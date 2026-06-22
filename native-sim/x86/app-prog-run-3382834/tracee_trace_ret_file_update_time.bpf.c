extern char args_map;
extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char file_modification_map;
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

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_0(
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
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 39ULL: goto x86_l_27;
	case 42ULL: goto x86_l_2a;
	case 50ULL: goto x86_l_32;
	case 57ULL: goto x86_l_39;
	case 65ULL: goto x86_l_41;
	case 70ULL: goto x86_l_46;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 81ULL: goto x86_l_51;
	case 84ULL: goto x86_l_54;
	case 89ULL: goto x86_l_59;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 100ULL: goto x86_l_64;
	case 102ULL: goto x86_l_66;
	case 105ULL: goto x86_l_69;
	case 113ULL: goto x86_l_71;
	case 120ULL: goto x86_l_78;
	case 128ULL: goto x86_l_80;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 140ULL: goto x86_l_8c;
	case 142ULL: goto x86_l_8e;
	case 145ULL: goto x86_l_91;
	case 150ULL: goto x86_l_96;
	case 152ULL: goto x86_l_98;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 167ULL: goto x86_l_a7;
	case 172ULL: goto x86_l_ac;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 184ULL: goto x86_l_b8;
	case 195ULL: goto x86_l_c3;
	case 200ULL: goto x86_l_c8;
	case 202ULL: goto x86_l_ca;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 217ULL: goto x86_l_d9;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 224ULL: goto x86_l_e0;
	case 227ULL: goto x86_l_e3;
	case 229ULL: goto x86_l_e5;
	case 233ULL: goto x86_l_e9;
	case 241ULL: goto x86_l_f1;
	case 246ULL: goto x86_l_f6;
	case 251ULL: goto x86_l_fb;
	case 256ULL: goto x86_l_100;
	case 259ULL: goto x86_l_103;
	case 261ULL: goto x86_l_105;
	case 269ULL: goto x86_l_10d;
	case 271ULL: goto x86_l_10f;
	case 275ULL: goto x86_l_113;
	case 277ULL: goto x86_l_115;
	case 284ULL: goto x86_l_11c;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 296ULL: goto x86_l_128;
	case 299ULL: goto x86_l_12b;
	case 301ULL: goto x86_l_12d;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 318ULL: goto x86_l_13e;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 340ULL: goto x86_l_154;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 356ULL: goto x86_l_164;
	case 361ULL: goto x86_l_169;
	case 366ULL: goto x86_l_16e;
	case 368ULL: goto x86_l_170;
	case 371ULL: goto x86_l_173;
	case 377ULL: goto x86_l_179;
	case 380ULL: goto x86_l_17c;
	case 390ULL: goto x86_l_186;
	case 398ULL: goto x86_l_18e;
	case 409ULL: goto x86_l_199;
	case 420ULL: goto x86_l_1a4;
	case 431ULL: goto x86_l_1af;
	case 442ULL: goto x86_l_1ba;
	case 453ULL: goto x86_l_1c5;
	case 464ULL: goto x86_l_1d0;
	case 475ULL: goto x86_l_1db;
	case 486ULL: goto x86_l_1e6;
	case 493ULL: goto x86_l_1ed;
	case 501ULL: goto x86_l_1f5;
	case 509ULL: goto x86_l_1fd;
	case 517ULL: goto x86_l_205;
	case 525ULL: goto x86_l_20d;
	case 533ULL: goto x86_l_215;
	case 541ULL: goto x86_l_21d;
	case 549ULL: goto x86_l_225;
	case 557ULL: goto x86_l_22d;
	case 565ULL: goto x86_l_235;
	case 573ULL: goto x86_l_23d;
	case 581ULL: goto x86_l_245;
	case 589ULL: goto x86_l_24d;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 650ULL: goto x86_l_28a;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 674ULL: goto x86_l_2a2;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 684ULL: goto x86_l_2ac;
	case 692ULL: goto x86_l_2b4;
	case 696ULL: goto x86_l_2b8;
	case 703ULL: goto x86_l_2bf;
	case 710ULL: goto x86_l_2c6;
	case 718ULL: goto x86_l_2ce;
	case 723ULL: goto x86_l_2d3;
	case 725ULL: goto x86_l_2d5;
	case 728ULL: goto x86_l_2d8;
	case 731ULL: goto x86_l_2db;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 763ULL: goto x86_l_2fb;
	case 768ULL: goto x86_l_300;
	case 771ULL: goto x86_l_303;
	case 775ULL: goto x86_l_307;
	case 783ULL: goto x86_l_30f;
	case 790ULL: goto x86_l_316;
	case 795ULL: goto x86_l_31b;
	case 800ULL: goto x86_l_320;
	case 802ULL: goto x86_l_322;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 814ULL: goto x86_l_32e;
	case 818ULL: goto x86_l_332;
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
	case 1023ULL: goto x86_l_3ff;
	case 1034ULL: goto x86_l_40a;
	case 1045ULL: goto x86_l_415;
	case 1056ULL: goto x86_l_420;
	case 1067ULL: goto x86_l_42b;
	case 1078ULL: goto x86_l_436;
	case 1089ULL: goto x86_l_441;
	case 1100ULL: goto x86_l_44c;
	case 1111ULL: goto x86_l_457;
	case 1122ULL: goto x86_l_462;
	case 1133ULL: goto x86_l_46d;
	case 1144ULL: goto x86_l_478;
	case 1155ULL: goto x86_l_483;
	case 1163ULL: goto x86_l_48b;
	case 1171ULL: goto x86_l_493;
	case 1179ULL: goto x86_l_49b;
	case 1187ULL: goto x86_l_4a3;
	case 1195ULL: goto x86_l_4ab;
	case 1203ULL: goto x86_l_4b3;
	case 1211ULL: goto x86_l_4bb;
	case 1219ULL: goto x86_l_4c3;
	case 1227ULL: goto x86_l_4cb;
	case 1235ULL: goto x86_l_4d3;
	case 1243ULL: goto x86_l_4db;
	case 1251ULL: goto x86_l_4e3;
	case 1259ULL: goto x86_l_4eb;
	case 1267ULL: goto x86_l_4f3;
	case 1275ULL: goto x86_l_4fb;
	case 1282ULL: goto x86_l_502;
	case 1289ULL: goto x86_l_509;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1307ULL: goto x86_l_51b;
	case 1310ULL: goto x86_l_51e;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1325ULL: goto x86_l_52d;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1353ULL: goto x86_l_549;
	case 1357ULL: goto x86_l_54d;
	case 1365ULL: goto x86_l_555;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1393ULL: goto x86_l_571;
	case 1399ULL: goto x86_l_577;
	case 1402ULL: goto x86_l_57a;
	case 1406ULL: goto x86_l_57e;
	case 1413ULL: goto x86_l_585;
	case 1424ULL: goto x86_l_590;
	case 1435ULL: goto x86_l_59b;
	case 1446ULL: goto x86_l_5a6;
	case 1457ULL: goto x86_l_5b1;
	case 1468ULL: goto x86_l_5bc;
	case 1479ULL: goto x86_l_5c7;
	case 1490ULL: goto x86_l_5d2;
	case 1501ULL: goto x86_l_5dd;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1528ULL: goto x86_l_5f8;
	case 1536ULL: goto x86_l_600;
	case 1544ULL: goto x86_l_608;
	case 1552ULL: goto x86_l_610;
	case 1560ULL: goto x86_l_618;
	case 1568ULL: goto x86_l_620;
	case 1576ULL: goto x86_l_628;
	case 1584ULL: goto x86_l_630;
	case 1592ULL: goto x86_l_638;
	case 1600ULL: goto x86_l_640;
	case 1608ULL: goto x86_l_648;
	case 1616ULL: goto x86_l_650;
	case 1624ULL: goto x86_l_658;
	case 1632ULL: goto x86_l_660;
	case 1639ULL: goto x86_l_667;
	case 1646ULL: goto x86_l_66e;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1687ULL: goto x86_l_697;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1703ULL: goto x86_l_6a7;
	case 1707ULL: goto x86_l_6ab;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1725ULL: goto x86_l_6bd;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1735ULL: goto x86_l_6c7;
	case 1743ULL: goto x86_l_6cf;
	case 1751ULL: goto x86_l_6d7;
	case 1755ULL: goto x86_l_6db;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1780ULL: goto x86_l_6f4;
	case 1788ULL: goto x86_l_6fc;
	case 1792ULL: goto x86_l_700;
	case 1800ULL: goto x86_l_708;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1817ULL: goto x86_l_719;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1834ULL: goto x86_l_72a;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1859ULL: goto x86_l_743;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1879ULL: goto x86_l_757;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1905ULL: goto x86_l_771;
	case 1907ULL: goto x86_l_773;
	case 1915ULL: goto x86_l_77b;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1943ULL: goto x86_l_797;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1958ULL: goto x86_l_7a6;
	case 1962ULL: goto x86_l_7aa;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1987ULL: goto x86_l_7c3;
	case 1994ULL: goto x86_l_7ca;
	case 1998ULL: goto x86_l_7ce;
	case 2006ULL: goto x86_l_7d6;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2034ULL: goto x86_l_7f2;
	case 2038ULL: goto x86_l_7f6;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2063ULL: goto x86_l_80f;
	case 2071ULL: goto x86_l_817;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2106ULL: goto x86_l_83a;
	case 2110ULL: goto x86_l_83e;
	case 2114ULL: goto x86_l_842;
	case 2118ULL: goto x86_l_846;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2180ULL: goto x86_l_884;
	case 2182ULL: goto x86_l_886;
	case 2190ULL: goto x86_l_88e;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2225ULL: goto x86_l_8b1;
	case 2229ULL: goto x86_l_8b5;
	case 2233ULL: goto x86_l_8b9;
	case 2237ULL: goto x86_l_8bd;
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
	/* 0xa: sub    rsp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 296ULL);
x86_l_11:
	/* 0x11: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: movabs rbx,0x30800000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3332894621696ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27:
	/* 0x27: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a:
	/* 0x2a: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_32:
	/* 0x32: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_39:
	/* 0x39: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_41:
	/* 0x41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46:
	/* 0x46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48:
	/* 0x48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_51:
	/* 0x51: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59:
	/* 0x59: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d:
	/* 0x5d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_62:
	/* 0x62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64:
	/* 0x64: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_66:
	/* 0x66: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_71:
	/* 0x71: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_78:
	/* 0x78: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_80:
	/* 0x80: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_85:
	/* 0x85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87:
	/* 0x87: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_8c:
	/* 0x8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e:
	/* 0x8e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_91:
	/* 0x91: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_96:
	/* 0x96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98:
	/* 0x98: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9f:
	/* 0x9f: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a7:
	/* 0xa7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ac:
	/* 0xac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1:
	/* 0xb1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b6:
	/* 0xb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8:
	/* 0xb8: test   DWORD PTR [rsp+0x90],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618477387776ULL);
x86_l_c3:
	/* 0xc3: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_c8:
	/* 0xc8: jne    136 <trace_ret_file_update_time+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_136;
	}
x86_l_ca:
	/* 0xca: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_cf:
	/* 0xcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1:
	/* 0xd1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d4:
	/* 0xd4: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_d9:
	/* 0xd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db:
	/* 0xdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de:
	/* 0xde: je     e5 <trace_ret_file_update_time+0xe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5;
	}
x86_l_e0:
	/* 0xe0: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e3:
	/* 0xe3: jmp    e5 <trace_ret_file_update_time+0xe5> */
	goto x86_l_e5;
x86_l_e5:
	/* 0xe5: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e9:
	/* 0xe9: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f1:
	/* 0xf1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f6:
	/* 0xf6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fb:
	/* 0xfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_100:
	/* 0x100: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_103:
	/* 0x103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105:
	/* 0x105: test   BYTE PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_10d:
	/* 0x10d: jne    115 <trace_ret_file_update_time+0x115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_115;
	}
x86_l_10f:
	/* 0x10f: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_113:
	/* 0x113: jmp    136 <trace_ret_file_update_time+0x136> */
	goto x86_l_136;
x86_l_115:
	/* 0x115: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_11c:
	/* 0x11c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_121:
	/* 0x121: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_126:
	/* 0x126: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128:
	/* 0x128: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: je     131 <trace_ret_file_update_time+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131;
	}
x86_l_12d:
	/* 0x12d: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f:
	/* 0x12f: jmp    136 <trace_ret_file_update_time+0x136> */
	goto x86_l_136;
x86_l_131:
	/* 0x131: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_136:
	/* 0x136: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_13e:
	/* 0x13e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_145:
	/* 0x145: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14a:
	/* 0x14a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f:
	/* 0x14f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151:
	/* 0x151: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154:
	/* 0x154: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_15a:
	/* 0x15a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_164:
	/* 0x164: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_169:
	/* 0x169: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173:
	/* 0x173: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_179:
	/* 0x179: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_17c:
	/* 0x17c: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_186:
	/* 0x186: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_1a4:
	/* 0x1a4: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1af:
	/* 0x1af: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1c5:
	/* 0x1c5: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1d0:
	/* 0x1d0: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1db:
	/* 0x1db: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1e6:
	/* 0x1e6: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1ed:
	/* 0x1ed: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f5:
	/* 0x1f5: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fd:
	/* 0x1fd: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_205:
	/* 0x205: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_20d:
	/* 0x20d: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_215:
	/* 0x215: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_21d:
	/* 0x21d: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_225:
	/* 0x225: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_22d:
	/* 0x22d: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_235:
	/* 0x235: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_23d:
	/* 0x23d: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_245:
	/* 0x245: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_24d:
	/* 0x24d: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_255:
	/* 0x255: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_25a:
	/* 0x25a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c:
	/* 0x25c: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_260:
	/* 0x260: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_264:
	/* 0x264: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_268:
	/* 0x268: mov    DWORD PTR [r14+0x70],0x308 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337928ULL);
x86_l_270:
	/* 0x270: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27a:
	/* 0x27a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_27f:
	/* 0x27f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281:
	/* 0x281: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_286:
	/* 0x286: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_28a:
	/* 0x28a: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_291:
	/* 0x291: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_298:
	/* 0x298: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0:
	/* 0x2a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2:
	/* 0x2a2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a7:
	/* 0x2a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aa:
	/* 0x2aa: je     300 <trace_ret_file_update_time+0x300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_300;
	}
x86_l_2ac:
	/* 0x2ac: mov    QWORD PTR [rsp+0x120],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2b4:
	/* 0x2b4: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b8:
	/* 0x2b8: mov    DWORD PTR [rsp+0x100],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2bf:
	/* 0x2bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2c6:
	/* 0x2c6: lea    rsi,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2ce:
	/* 0x2ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d3:
	/* 0x2d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5:
	/* 0x2d5: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d8:
	/* 0x2d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: mov    QWORD PTR [rsp+0x110],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2e3:
	/* 0x2e3: je     542 <trace_ret_file_update_time+0x542> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_542;
	}
x86_l_2e9:
	/* 0x2e9: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2ee:
	/* 0x2ee: jne    c0d <trace_ret_file_update_time+0xc0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3085ULL;
	}
x86_l_2f4:
	/* 0x2f4: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2f9:
	/* 0x2f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb:
	/* 0x2fb: jmp    cc9 <trace_ret_file_update_time+0xcc9> */
	return 3273ULL;
x86_l_300:
	/* 0x300: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303:
	/* 0x303: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_307:
	/* 0x307: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_30f:
	/* 0x30f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_316:
	/* 0x316: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31b:
	/* 0x31b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_320:
	/* 0x320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322:
	/* 0x322: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_32b:
	/* 0x32b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32e:
	/* 0x32e: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_332:
	/* 0x332: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_339:
	/* 0x339: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_34f:
	/* 0x34f: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_35a:
	/* 0x35a: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_365:
	/* 0x365: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_370:
	/* 0x370: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_37b:
	/* 0x37b: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_386:
	/* 0x386: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_391:
	/* 0x391: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_39c:
	/* 0x39c: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_3a7:
	/* 0x3a7: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_3b2:
	/* 0x3b2: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3c8:
	/* 0x3c8: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3d3:
	/* 0x3d3: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3de:
	/* 0x3de: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3e9:
	/* 0x3e9: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3f4:
	/* 0x3f4: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3ff:
	/* 0x3ff: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_40a:
	/* 0x40a: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_415:
	/* 0x415: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_420:
	/* 0x420: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_441:
	/* 0x441: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_44c:
	/* 0x44c: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_457:
	/* 0x457: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_462:
	/* 0x462: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_46d:
	/* 0x46d: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_49b:
	/* 0x49b: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4a3:
	/* 0x4a3: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_4ab:
	/* 0x4ab: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4b3:
	/* 0x4b3: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4bb:
	/* 0x4bb: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4c3:
	/* 0x4c3: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4cb:
	/* 0x4cb: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4d3:
	/* 0x4d3: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4db:
	/* 0x4db: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4eb:
	/* 0x4eb: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f3:
	/* 0x4f3: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4fb:
	/* 0x4fb: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_502:
	/* 0x502: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_509:
	/* 0x509: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_511:
	/* 0x511: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_516:
	/* 0x516: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_51b:
	/* 0x51b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_51e:
	/* 0x51e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_520:
	/* 0x520: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_525:
	/* 0x525: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_52a:
	/* 0x52a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_52d:
	/* 0x52d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f:
	/* 0x52f: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_534:
	/* 0x534: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: jne    2ac <trace_ret_file_update_time+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ac;
	}
x86_l_53d:
	/* 0x53d: jmp    2391 <trace_ret_file_update_time+0x2391> */
	return 9105ULL;
x86_l_542:
	/* 0x542: mov    eax,DWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_549:
	/* 0x549: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_54d:
	/* 0x54d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_555:
	/* 0x555: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_55c:
	/* 0x55c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_561:
	/* 0x561: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_566:
	/* 0x566: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_56c:
	/* 0x56c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e:
	/* 0x56e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_571:
	/* 0x571: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_577:
	/* 0x577: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_57a:
	/* 0x57a: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_57e:
	/* 0x57e: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_585:
	/* 0x585: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_59b:
	/* 0x59b: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5a6:
	/* 0x5a6: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_5b1:
	/* 0x5b1: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5bc:
	/* 0x5bc: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5c7:
	/* 0x5c7: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5dd:
	/* 0x5dd: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5f8:
	/* 0x5f8: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_600:
	/* 0x600: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_608:
	/* 0x608: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_610:
	/* 0x610: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_618:
	/* 0x618: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_620:
	/* 0x620: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_628:
	/* 0x628: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_630:
	/* 0x630: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_638:
	/* 0x638: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_640:
	/* 0x640: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_648:
	/* 0x648: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_650:
	/* 0x650: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_658:
	/* 0x658: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_660:
	/* 0x660: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_667:
	/* 0x667: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_66e:
	/* 0x66e: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_676:
	/* 0x676: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67b:
	/* 0x67b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_680:
	/* 0x680: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_683:
	/* 0x683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_685:
	/* 0x685: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_68a:
	/* 0x68a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_68f:
	/* 0x68f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_692:
	/* 0x692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694:
	/* 0x694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_697:
	/* 0x697: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_69d:
	/* 0x69d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6a0:
	/* 0x6a0: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_6a7:
	/* 0x6a7: lea    rbp,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ab:
	/* 0x6ab: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6b3:
	/* 0x6b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6b8:
	/* 0x6b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6bd:
	/* 0x6bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c2:
	/* 0x6c2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c7:
	/* 0x6c7: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6cf:
	/* 0x6cf: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6d7:
	/* 0x6d7: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6db:
	/* 0x6db: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6e3:
	/* 0x6e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6e8:
	/* 0x6e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ed:
	/* 0x6ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f2:
	/* 0x6f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f4:
	/* 0x6f4: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6fc:
	/* 0x6fc: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_700:
	/* 0x700: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_708:
	/* 0x708: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_70d:
	/* 0x70d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_712:
	/* 0x712: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_717:
	/* 0x717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_719:
	/* 0x719: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_721:
	/* 0x721: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_726:
	/* 0x726: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_72a:
	/* 0x72a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_732:
	/* 0x732: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_737:
	/* 0x737: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73c:
	/* 0x73c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_741:
	/* 0x741: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_743:
	/* 0x743: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_74a:
	/* 0x74a: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_74e:
	/* 0x74e: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_753:
	/* 0x753: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_757:
	/* 0x757: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_75f:
	/* 0x75f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_764:
	/* 0x764: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_769:
	/* 0x769: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76e:
	/* 0x76e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_771:
	/* 0x771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_773:
	/* 0x773: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_77b:
	/* 0x77b: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_783:
	/* 0x783: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_788:
	/* 0x788: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78d:
	/* 0x78d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_792:
	/* 0x792: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_795:
	/* 0x795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_797:
	/* 0x797: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_79e:
	/* 0x79e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7a2:
	/* 0x7a2: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7a6:
	/* 0x7a6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_7aa:
	/* 0x7aa: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7b2:
	/* 0x7b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7b7:
	/* 0x7b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7bc:
	/* 0x7bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c1:
	/* 0x7c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c3:
	/* 0x7c3: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7ca:
	/* 0x7ca: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7ce:
	/* 0x7ce: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7d6:
	/* 0x7d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7db:
	/* 0x7db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e0:
	/* 0x7e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7e5:
	/* 0x7e5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7e8:
	/* 0x7e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ea:
	/* 0x7ea: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7f2:
	/* 0x7f2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7f6:
	/* 0x7f6: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7fe:
	/* 0x7fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_803:
	/* 0x803: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_808:
	/* 0x808: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_80d:
	/* 0x80d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80f:
	/* 0x80f: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_817:
	/* 0x817: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
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
	/* 0x833: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_83a:
	/* 0x83a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_83e:
	/* 0x83e: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_842:
	/* 0x842: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_846:
	/* 0x846: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_84e:
	/* 0x84e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_853:
	/* 0x853: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_858:
	/* 0x858: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_85d:
	/* 0x85d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85f:
	/* 0x85f: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_866:
	/* 0x866: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_86a:
	/* 0x86a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_872:
	/* 0x872: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_877:
	/* 0x877: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87c:
	/* 0x87c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_881:
	/* 0x881: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_884:
	/* 0x884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_886:
	/* 0x886: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_88e:
	/* 0x88e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_896:
	/* 0x896: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_89b:
	/* 0x89b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a0:
	/* 0x8a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8a5:
	/* 0x8a5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8a8:
	/* 0x8a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8aa:
	/* 0x8aa: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b1:
	/* 0x8b1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8b5:
	/* 0x8b5: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8b9:
	/* 0x8b9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8bd:
	/* 0x8bd: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
	return 2245ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2262ULL: goto x86_l_8d6;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2282ULL: goto x86_l_8ea;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2299ULL: goto x86_l_8fb;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2343ULL: goto x86_l_927;
	case 2351ULL: goto x86_l_92f;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2377ULL: goto x86_l_949;
	case 2379ULL: goto x86_l_94b;
	case 2386ULL: goto x86_l_952;
	case 2390ULL: goto x86_l_956;
	case 2394ULL: goto x86_l_95a;
	case 2398ULL: goto x86_l_95e;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2431ULL: goto x86_l_97f;
	case 2435ULL: goto x86_l_983;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2460ULL: goto x86_l_99c;
	case 2467ULL: goto x86_l_9a3;
	case 2469ULL: goto x86_l_9a5;
	case 2477ULL: goto x86_l_9ad;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2505ULL: goto x86_l_9c9;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2540ULL: goto x86_l_9ec;
	case 2544ULL: goto x86_l_9f0;
	case 2548ULL: goto x86_l_9f4;
	case 2552ULL: goto x86_l_9f8;
	case 2560ULL: goto x86_l_a00;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2584ULL: goto x86_l_a18;
	case 2588ULL: goto x86_l_a1c;
	case 2592ULL: goto x86_l_a20;
	case 2597ULL: goto x86_l_a25;
	case 2604ULL: goto x86_l_a2c;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2640ULL: goto x86_l_a50;
	case 2644ULL: goto x86_l_a54;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2669ULL: goto x86_l_a6d;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2707ULL: goto x86_l_a93;
	case 2711ULL: goto x86_l_a97;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2763ULL: goto x86_l_acb;
	case 2767ULL: goto x86_l_acf;
	case 2775ULL: goto x86_l_ad7;
	case 2779ULL: goto x86_l_adb;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2812ULL: goto x86_l_afc;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2825ULL: goto x86_l_b09;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2858ULL: goto x86_l_b2a;
	case 2862ULL: goto x86_l_b2e;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2913ULL: goto x86_l_b61;
	case 2917ULL: goto x86_l_b65;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2942ULL: goto x86_l_b7e;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2968ULL: goto x86_l_b98;
	case 2970ULL: goto x86_l_b9a;
	case 2978ULL: goto x86_l_ba2;
	case 2986ULL: goto x86_l_baa;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3003ULL: goto x86_l_bbb;
	case 3011ULL: goto x86_l_bc3;
	case 3019ULL: goto x86_l_bcb;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3039ULL: goto x86_l_bdf;
	case 3042ULL: goto x86_l_be2;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3064ULL: goto x86_l_bf8;
	case 3066ULL: goto x86_l_bfa;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3085ULL: goto x86_l_c0d;
	case 3090ULL: goto x86_l_c12;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3117ULL: goto x86_l_c2d;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3151ULL: goto x86_l_c4f;
	case 3156ULL: goto x86_l_c54;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3194ULL: goto x86_l_c7a;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3217ULL: goto x86_l_c91;
	case 3219ULL: goto x86_l_c93;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3232ULL: goto x86_l_ca0;
	case 3236ULL: goto x86_l_ca4;
	case 3244ULL: goto x86_l_cac;
	case 3249ULL: goto x86_l_cb1;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3261ULL: goto x86_l_cbd;
	case 3269ULL: goto x86_l_cc5;
	case 3271ULL: goto x86_l_cc7;
	case 3273ULL: goto x86_l_cc9;
	case 3277ULL: goto x86_l_ccd;
	case 3281ULL: goto x86_l_cd1;
	case 3285ULL: goto x86_l_cd5;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3319ULL: goto x86_l_cf7;
	case 3322ULL: goto x86_l_cfa;
	case 3325ULL: goto x86_l_cfd;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3348ULL: goto x86_l_d14;
	case 3359ULL: goto x86_l_d1f;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3422ULL: goto x86_l_d5e;
	case 3426ULL: goto x86_l_d62;
	case 3433ULL: goto x86_l_d69;
	case 3436ULL: goto x86_l_d6c;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3451ULL: goto x86_l_d7b;
	case 3458ULL: goto x86_l_d82;
	case 3465ULL: goto x86_l_d89;
	case 3469ULL: goto x86_l_d8d;
	case 3476ULL: goto x86_l_d94;
	case 3480ULL: goto x86_l_d98;
	case 3487ULL: goto x86_l_d9f;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3502ULL: goto x86_l_dae;
	case 3509ULL: goto x86_l_db5;
	case 3516ULL: goto x86_l_dbc;
	case 3523ULL: goto x86_l_dc3;
	case 3526ULL: goto x86_l_dc6;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3543ULL: goto x86_l_dd7;
	case 3545ULL: goto x86_l_dd9;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3558ULL: goto x86_l_de6;
	case 3564ULL: goto x86_l_dec;
	case 3569ULL: goto x86_l_df1;
	case 3576ULL: goto x86_l_df8;
	case 3579ULL: goto x86_l_dfb;
	case 3585ULL: goto x86_l_e01;
	case 3593ULL: goto x86_l_e09;
	case 3596ULL: goto x86_l_e0c;
	case 3599ULL: goto x86_l_e0f;
	case 3602ULL: goto x86_l_e12;
	case 3606ULL: goto x86_l_e16;
	case 3609ULL: goto x86_l_e19;
	case 3612ULL: goto x86_l_e1c;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3634ULL: goto x86_l_e32;
	case 3636ULL: goto x86_l_e34;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3650ULL: goto x86_l_e42;
	case 3653ULL: goto x86_l_e45;
	case 3660ULL: goto x86_l_e4c;
	case 3663ULL: goto x86_l_e4f;
	case 3666ULL: goto x86_l_e52;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3678ULL: goto x86_l_e5e;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3711ULL: goto x86_l_e7f;
	case 3714ULL: goto x86_l_e82;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3770ULL: goto x86_l_eba;
	case 3777ULL: goto x86_l_ec1;
	case 3785ULL: goto x86_l_ec9;
	case 3792ULL: goto x86_l_ed0;
	case 3800ULL: goto x86_l_ed8;
	case 3807ULL: goto x86_l_edf;
	case 3815ULL: goto x86_l_ee7;
	case 3823ULL: goto x86_l_eef;
	case 3830ULL: goto x86_l_ef6;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3845ULL: goto x86_l_f05;
	case 3848ULL: goto x86_l_f08;
	case 3852ULL: goto x86_l_f0c;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3872ULL: goto x86_l_f20;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3905ULL: goto x86_l_f41;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3917ULL: goto x86_l_f4d;
	case 3925ULL: goto x86_l_f55;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3939ULL: goto x86_l_f63;
	case 3941ULL: goto x86_l_f65;
	case 3945ULL: goto x86_l_f69;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3967ULL: goto x86_l_f7f;
	case 3975ULL: goto x86_l_f87;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3987ULL: goto x86_l_f93;
	case 3995ULL: goto x86_l_f9b;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4011ULL: goto x86_l_fab;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4037ULL: goto x86_l_fc5;
	case 4044ULL: goto x86_l_fcc;
	case 4047ULL: goto x86_l_fcf;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4071ULL: goto x86_l_fe7;
	case 4074ULL: goto x86_l_fea;
	case 4076ULL: goto x86_l_fec;
	case 4078ULL: goto x86_l_fee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_8c5:
	/* 0x8c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8ca:
	/* 0x8ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cf:
	/* 0x8cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d4:
	/* 0x8d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d6:
	/* 0x8d6: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8de:
	/* 0x8de: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_8e2:
	/* 0x8e2: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8ea:
	/* 0x8ea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f4:
	/* 0x8f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8f9:
	/* 0x8f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fb:
	/* 0x8fb: mov    ebp,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_902:
	/* 0x902: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_907:
	/* 0x907: lea    r15,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_90b:
	/* 0x90b: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_913:
	/* 0x913: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_918:
	/* 0x918: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91d:
	/* 0x91d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_922:
	/* 0x922: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_925:
	/* 0x925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_927:
	/* 0x927: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_92f:
	/* 0x92f: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_937:
	/* 0x937: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_941:
	/* 0x941: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_946:
	/* 0x946: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_949:
	/* 0x949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94b:
	/* 0x94b: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_952:
	/* 0x952: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_956:
	/* 0x956: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_95a:
	/* 0x95a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_95e:
	/* 0x95e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_966:
	/* 0x966: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_96b:
	/* 0x96b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_970:
	/* 0x970: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_975:
	/* 0x975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_977:
	/* 0x977: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_97f:
	/* 0x97f: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_983:
	/* 0x983: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_98b:
	/* 0x98b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_990:
	/* 0x990: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_995:
	/* 0x995: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_99a:
	/* 0x99a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99c:
	/* 0x99c: cmp    ebp,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 144ULL);
x86_l_9a3:
	/* 0x9a3: jne    a1c <trace_ret_file_update_time+0xa1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a1c;
	}
x86_l_9a5:
	/* 0x9a5: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9ad:
	/* 0x9ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9b2:
	/* 0x9b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b7:
	/* 0x9b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bc:
	/* 0x9bc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c1:
	/* 0x9c1: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9c9:
	/* 0x9c9: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9d1:
	/* 0x9d1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9d6:
	/* 0x9d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9db:
	/* 0x9db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9e0:
	/* 0x9e0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9e3:
	/* 0x9e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e5:
	/* 0x9e5: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9ec:
	/* 0x9ec: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_9f0:
	/* 0x9f0: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9f4:
	/* 0x9f4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9f8:
	/* 0x9f8: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a00:
	/* 0xa00: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a05:
	/* 0xa05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a0a:
	/* 0xa0a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a18:
	/* 0xa18: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a1c:
	/* 0xa1c: mov    DWORD PTR [r13+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a20:
	/* 0xa20: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a25:
	/* 0xa25: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a2c:
	/* 0xa2c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a34:
	/* 0xa34: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3e:
	/* 0xa3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a43:
	/* 0xa43: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a48:
	/* 0xa48: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a50:
	/* 0xa50: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_a54:
	/* 0xa54: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a5c:
	/* 0xa5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a61:
	/* 0xa61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a66:
	/* 0xa66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a6b:
	/* 0xa6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6d:
	/* 0xa6d: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a75:
	/* 0xa75: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a7a:
	/* 0xa7a: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a7f:
	/* 0xa7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a84:
	/* 0xa84: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a8c:
	/* 0xa8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a91:
	/* 0xa91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a93:
	/* 0xa93: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a97:
	/* 0xa97: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a9b:
	/* 0xa9b: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_aa0:
	/* 0xaa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa2:
	/* 0xaa2: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa6:
	/* 0xaa6: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aaa:
	/* 0xaaa: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ab2:
	/* 0xab2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ab7:
	/* 0xab7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_abc:
	/* 0xabc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ac1:
	/* 0xac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac3:
	/* 0xac3: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_acb:
	/* 0xacb: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_acf:
	/* 0xacf: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_ad7:
	/* 0xad7: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_adb:
	/* 0xadb: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ae3:
	/* 0xae3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae8:
	/* 0xae8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aed:
	/* 0xaed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af2:
	/* 0xaf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af4:
	/* 0xaf4: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_afc:
	/* 0xafc: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b00:
	/* 0xb00: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b05:
	/* 0xb05: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_b09:
	/* 0xb09: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b11:
	/* 0xb11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b16:
	/* 0xb16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1b:
	/* 0xb1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b20:
	/* 0xb20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b22:
	/* 0xb22: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b2a:
	/* 0xb2a: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b2e:
	/* 0xb2e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b36:
	/* 0xb36: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b3b:
	/* 0xb3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b40:
	/* 0xb40: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b45:
	/* 0xb45: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b48:
	/* 0xb48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4a:
	/* 0xb4a: test   BYTE PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_b52:
	/* 0xb52: je     b59 <trace_ret_file_update_time+0xb59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b59;
	}
x86_l_b54:
	/* 0xb54: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_b59:
	/* 0xb59: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_b61:
	/* 0xb61: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b65:
	/* 0xb65: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_b6d:
	/* 0xb6d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b72:
	/* 0xb72: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_b77:
	/* 0xb77: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b7c:
	/* 0xb7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7e:
	/* 0xb7e: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b86:
	/* 0xb86: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b8b:
	/* 0xb8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b90:
	/* 0xb90: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b95:
	/* 0xb95: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b98:
	/* 0xb98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9a:
	/* 0xb9a: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ba2:
	/* 0xba2: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_baa:
	/* 0xbaa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_baf:
	/* 0xbaf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bb4:
	/* 0xbb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb9:
	/* 0xbb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbb:
	/* 0xbbb: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bc3:
	/* 0xbc3: lea    rbx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bcb:
	/* 0xbcb: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_bd0:
	/* 0xbd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bd5:
	/* 0xbd5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bd8:
	/* 0xbd8: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_bdd:
	/* 0xbdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bdf:
	/* 0xbdf: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_be6:
	/* 0xbe6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_beb:
	/* 0xbeb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_bf0:
	/* 0xbf0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_bf5:
	/* 0xbf5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_bf8:
	/* 0xbf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfa:
	/* 0xbfa: mov    r15,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_c02:
	/* 0xc02: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_c07:
	/* 0xc07: je     2f4 <trace_ret_file_update_time+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 756ULL;
	}
x86_l_c0d:
	/* 0xc0d: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_c12:
	/* 0xc12: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_c19:
	/* 0xc19: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c1e:
	/* 0xc1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c23:
	/* 0xc23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c28:
	/* 0xc28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c2d:
	/* 0xc2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2f:
	/* 0xc2f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c34:
	/* 0xc34: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c39:
	/* 0xc39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c3e:
	/* 0xc3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c43:
	/* 0xc43: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c48:
	/* 0xc48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4d:
	/* 0xc4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4f:
	/* 0xc4f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c54:
	/* 0xc54: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c5c:
	/* 0xc5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c61:
	/* 0xc61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c66:
	/* 0xc66: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c6b:
	/* 0xc6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c70:
	/* 0xc70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c72:
	/* 0xc72: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c7a:
	/* 0xc7a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c82:
	/* 0xc82: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c87:
	/* 0xc87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c8c:
	/* 0xc8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c91:
	/* 0xc91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c93:
	/* 0xc93: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c9b:
	/* 0xc9b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_c9e:
	/* 0xc9e: je     cc7 <trace_ret_file_update_time+0xcc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc7;
	}
x86_l_ca0:
	/* 0xca0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ca4:
	/* 0xca4: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cac:
	/* 0xcac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cb1:
	/* 0xcb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cb6:
	/* 0xcb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cbb:
	/* 0xcbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbd:
	/* 0xcbd: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cc5:
	/* 0xcc5: jmp    cc9 <trace_ret_file_update_time+0xcc9> */
	goto x86_l_cc9;
x86_l_cc7:
	/* 0xcc7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc9:
	/* 0xcc9: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccd:
	/* 0xccd: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd1:
	/* 0xcd1: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cd5:
	/* 0xcd5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_cdc:
	/* 0xcdc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce6:
	/* 0xce6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce8:
	/* 0xce8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ceb:
	/* 0xceb: je     d04 <trace_ret_file_update_time+0xd04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d04;
	}
x86_l_ced:
	/* 0xced: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_cf0:
	/* 0xcf0: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_cf7:
	/* 0xcf7: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_cfa:
	/* 0xcfa: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_cfd:
	/* 0xcfd: jne    d04 <trace_ret_file_update_time+0xd04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d04;
	}
x86_l_cff:
	/* 0xcff: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_d04:
	/* 0xd04: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_d09:
	/* 0xd09: cmp    ax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_d0e:
	/* 0xd0e: jne    27cb <trace_ret_file_update_time+0x27cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10187ULL;
	}
x86_l_d14:
	/* 0xd14: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_d1f:
	/* 0xd1f: mov    DWORD PTR [rsp+0x90],0x308 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475291400ULL);
x86_l_d2a:
	/* 0xd2a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d2f:
	/* 0xd2f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_d36:
	/* 0xd36: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d3b:
	/* 0xd3b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d40:
	/* 0xd40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d42:
	/* 0xd42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d45:
	/* 0xd45: je     db5 <trace_ret_file_update_time+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db5;
	}
x86_l_d47:
	/* 0xd47: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d4a:
	/* 0xd4a: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d52:
	/* 0xd52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d57:
	/* 0xd57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d59:
	/* 0xd59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5c:
	/* 0xd5c: je     db5 <trace_ret_file_update_time+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db5;
	}
x86_l_d5e:
	/* 0xd5e: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d62:
	/* 0xd62: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_d69:
	/* 0xd69: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6c:
	/* 0xd6c: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_d73:
	/* 0xd73: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d77:
	/* 0xd77: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d7b:
	/* 0xd7b: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_d82:
	/* 0xd82: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_d89:
	/* 0xd89: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8d:
	/* 0xd8d: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_d94:
	/* 0xd94: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d98:
	/* 0xd98: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_d9f:
	/* 0xd9f: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da3:
	/* 0xda3: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_daa:
	/* 0xdaa: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dae:
	/* 0xdae: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_db5:
	/* 0xdb5: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_dbc:
	/* 0xdbc: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dc3:
	/* 0xdc3: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc6:
	/* 0xdc6: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_dca:
	/* 0xdca: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dcf:
	/* 0xdcf: mov    QWORD PTR [rsp+0x118],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_dd7:
	/* 0xdd7: jne    df1 <trace_ret_file_update_time+0xdf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_df1;
	}
x86_l_dd9:
	/* 0xdd9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ddc:
	/* 0xddc: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_ddf:
	/* 0xddf: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_de6:
	/* 0xde6: jne    1651 <trace_ret_file_update_time+0x1651> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5713ULL;
	}
x86_l_dec:
	/* 0xdec: jmp    2391 <trace_ret_file_update_time+0x2391> */
	return 9105ULL;
x86_l_df1:
	/* 0xdf1: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_df8:
	/* 0xdf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dfb:
	/* 0xdfb: je     fbe <trace_ret_file_update_time+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fbe;
	}
x86_l_e01:
	/* 0xe01: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_e09:
	/* 0xe09: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_e0c:
	/* 0xe0c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0f:
	/* 0xe0f: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_e12:
	/* 0xe12: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e16:
	/* 0xe16: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e19:
	/* 0xe19: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e1c:
	/* 0xe1c: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_e23:
	/* 0xe23: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e26:
	/* 0xe26: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e2d:
	/* 0xe2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e30:
	/* 0xe30: je     e52 <trace_ret_file_update_time+0xe52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e52;
	}
x86_l_e32:
	/* 0xe32: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e34:
	/* 0xe34: cmp    BYTE PTR [r13+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_e3c:
	/* 0xe3c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_e3f:
	/* 0xe3f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e42:
	/* 0xe42: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e45:
	/* 0xe45: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_e4c:
	/* 0xe4c: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e4f:
	/* 0xe4f: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e52:
	/* 0xe52: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_e59:
	/* 0xe59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e5c:
	/* 0xe5c: je     e78 <trace_ret_file_update_time+0xe78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e78;
	}
x86_l_e5e:
	/* 0xe5e: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_e62:
	/* 0xe62: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e65:
	/* 0xe65: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_e68:
	/* 0xe68: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e6b:
	/* 0xe6b: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_e72:
	/* 0xe72: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e75:
	/* 0xe75: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e78:
	/* 0xe78: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_e7f:
	/* 0xe7f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e82:
	/* 0xe82: je     ea0 <trace_ret_file_update_time+0xea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ea0;
	}
x86_l_e84:
	/* 0xe84: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e87:
	/* 0xe87: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e8c:
	/* 0xe8c: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e90:
	/* 0xe90: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e93:
	/* 0xe93: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_e9a:
	/* 0xe9a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e9d:
	/* 0xe9d: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ea0:
	/* 0xea0: movzx  ebp,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ea5:
	/* 0xea5: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_eac:
	/* 0xeac: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb4:
	/* 0xeb4: je     1034 <trace_ret_file_update_time+0x1034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4148ULL;
	}
x86_l_eba:
	/* 0xeba: mov    rax,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_ec1:
	/* 0xec1: mov    QWORD PTR [rsp+0x108],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_ec9:
	/* 0xec9: mov    rax,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_ed0:
	/* 0xed0: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_ed8:
	/* 0xed8: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_edf:
	/* 0xedf: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_ee7:
	/* 0xee7: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_eef:
	/* 0xeef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_ef6:
	/* 0xef6: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_efe:
	/* 0xefe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f03:
	/* 0xf03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f05:
	/* 0xf05: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f08:
	/* 0xf08: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f0c:
	/* 0xf0c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f14:
	/* 0xf14: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f1b:
	/* 0xf1b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_f1e:
	/* 0xf1e: je     f43 <trace_ret_file_update_time+0xf43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f43;
	}
x86_l_f20:
	/* 0xf20: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f28:
	/* 0xf28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2d:
	/* 0xf2d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f30:
	/* 0xf30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f32:
	/* 0xf32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f35:
	/* 0xf35: je     f43 <trace_ret_file_update_time+0xf43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f43;
	}
x86_l_f37:
	/* 0xf37: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3a:
	/* 0xf3a: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3e:
	/* 0xf3e: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f41:
	/* 0xf41: jmp    f45 <trace_ret_file_update_time+0xf45> */
	goto x86_l_f45;
x86_l_f43:
	/* 0xf43: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f45:
	/* 0xf45: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_f4d:
	/* 0xf4d: mov    rsi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_f55:
	/* 0xf55: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f5d:
	/* 0xf5d: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f60:
	/* 0xf60: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f63:
	/* 0xf63: jb     f7b <trace_ret_file_update_time+0xf7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f7b;
	}
x86_l_f65:
	/* 0xf65: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f69:
	/* 0xf69: je     f70 <trace_ret_file_update_time+0xf70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f70;
	}
x86_l_f6b:
	/* 0xf6b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f6e:
	/* 0xf6e: jbe    f7b <trace_ret_file_update_time+0xf7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f7b;
	}
x86_l_f70:
	/* 0xf70: and    r13,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 264ULL);
x86_l_f78:
	/* 0xf78: or     rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_f7b:
	/* 0xf7b: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f7f:
	/* 0xf7f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f87:
	/* 0xf87: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f8e:
	/* 0xf8e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_f91:
	/* 0xf91: je     fda <trace_ret_file_update_time+0xfda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fda;
	}
x86_l_f93:
	/* 0xf93: mov    QWORD PTR [rsp+0xf0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_f9b:
	/* 0xf9b: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fa3:
	/* 0xfa3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fa8:
	/* 0xfa8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fab:
	/* 0xfab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fad:
	/* 0xfad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: je     fee <trace_ret_file_update_time+0xfee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fee;
	}
x86_l_fb2:
	/* 0xfb2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb5:
	/* 0xfb5: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb9:
	/* 0xfb9: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fbc:
	/* 0xfbc: jmp    ff0 <trace_ret_file_update_time+0xff0> */
	return 4080ULL;
x86_l_fbe:
	/* 0xfbe: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fc5:
	/* 0xfc5: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_fcc:
	/* 0xfcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fcf:
	/* 0xfcf: jne    e32 <trace_ret_file_update_time+0xe32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e32;
	}
x86_l_fd5:
	/* 0xfd5: jmp    e52 <trace_ret_file_update_time+0xe52> */
	goto x86_l_e52;
x86_l_fda:
	/* 0xfda: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fdc:
	/* 0xfdc: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fdf:
	/* 0xfdf: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe7:
	/* 0xfe7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_fea:
	/* 0xfea: jae    1010 <trace_ret_file_update_time+0x1010> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4112ULL;
	}
x86_l_fec:
	/* 0xfec: jmp    1026 <trace_ret_file_update_time+0x1026> */
	return 4134ULL;
x86_l_fee:
	/* 0xfee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
	return 4080ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4080ULL: goto x86_l_ff0;
	case 4088ULL: goto x86_l_ff8;
	case 4096ULL: goto x86_l_1000;
	case 4099ULL: goto x86_l_1003;
	case 4107ULL: goto x86_l_100b;
	case 4110ULL: goto x86_l_100e;
	case 4112ULL: goto x86_l_1010;
	case 4116ULL: goto x86_l_1014;
	case 4118ULL: goto x86_l_1016;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4156ULL: goto x86_l_103c;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4173ULL: goto x86_l_104d;
	case 4180ULL: goto x86_l_1054;
	case 4187ULL: goto x86_l_105b;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4204ULL: goto x86_l_106c;
	case 4211ULL: goto x86_l_1073;
	case 4219ULL: goto x86_l_107b;
	case 4226ULL: goto x86_l_1082;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4244ULL: goto x86_l_1094;
	case 4248ULL: goto x86_l_1098;
	case 4256ULL: goto x86_l_10a0;
	case 4263ULL: goto x86_l_10a7;
	case 4266ULL: goto x86_l_10aa;
	case 4268ULL: goto x86_l_10ac;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4286ULL: goto x86_l_10be;
	case 4288ULL: goto x86_l_10c0;
	case 4291ULL: goto x86_l_10c3;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4321ULL: goto x86_l_10e1;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4369ULL: goto x86_l_1111;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4387ULL: goto x86_l_1123;
	case 4395ULL: goto x86_l_112b;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4412ULL: goto x86_l_113c;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4432ULL: goto x86_l_1150;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4449ULL: goto x86_l_1161;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4491ULL: goto x86_l_118b;
	case 4495ULL: goto x86_l_118f;
	case 4502ULL: goto x86_l_1196;
	case 4509ULL: goto x86_l_119d;
	case 4517ULL: goto x86_l_11a5;
	case 4524ULL: goto x86_l_11ac;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4542ULL: goto x86_l_11be;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4554ULL: goto x86_l_11ca;
	case 4557ULL: goto x86_l_11cd;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4568ULL: goto x86_l_11d8;
	case 4571ULL: goto x86_l_11db;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4585ULL: goto x86_l_11e9;
	case 4587ULL: goto x86_l_11eb;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4620ULL: goto x86_l_120c;
	case 4624ULL: goto x86_l_1210;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4657ULL: goto x86_l_1231;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4692ULL: goto x86_l_1254;
	case 4696ULL: goto x86_l_1258;
	case 4700ULL: goto x86_l_125c;
	case 4704ULL: goto x86_l_1260;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4729ULL: goto x86_l_1279;
	case 4737ULL: goto x86_l_1281;
	case 4741ULL: goto x86_l_1285;
	case 4749ULL: goto x86_l_128d;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4766ULL: goto x86_l_129e;
	case 4773ULL: goto x86_l_12a5;
	case 4777ULL: goto x86_l_12a9;
	case 4784ULL: goto x86_l_12b0;
	case 4791ULL: goto x86_l_12b7;
	case 4799ULL: goto x86_l_12bf;
	case 4806ULL: goto x86_l_12c6;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4850ULL: goto x86_l_12f2;
	case 4853ULL: goto x86_l_12f5;
	case 4855ULL: goto x86_l_12f7;
	case 4858ULL: goto x86_l_12fa;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4889ULL: goto x86_l_1319;
	case 4895ULL: goto x86_l_131f;
	case 4900ULL: goto x86_l_1324;
	case 4907ULL: goto x86_l_132b;
	case 4915ULL: goto x86_l_1333;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4932ULL: goto x86_l_1344;
	case 4940ULL: goto x86_l_134c;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4965ULL: goto x86_l_1365;
	case 4973ULL: goto x86_l_136d;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5026ULL: goto x86_l_13a2;
	case 5028ULL: goto x86_l_13a4;
	case 5035ULL: goto x86_l_13ab;
	case 5042ULL: goto x86_l_13b2;
	case 5050ULL: goto x86_l_13ba;
	case 5057ULL: goto x86_l_13c1;
	case 5065ULL: goto x86_l_13c9;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5087ULL: goto x86_l_13df;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5108ULL: goto x86_l_13f4;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5117ULL: goto x86_l_13fd;
	case 5119ULL: goto x86_l_13ff;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5174ULL: goto x86_l_1436;
	case 5181ULL: goto x86_l_143d;
	case 5188ULL: goto x86_l_1444;
	case 5196ULL: goto x86_l_144c;
	case 5203ULL: goto x86_l_1453;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5221ULL: goto x86_l_1465;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5246ULL: goto x86_l_147e;
	case 5249ULL: goto x86_l_1481;
	case 5251ULL: goto x86_l_1483;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5268ULL: goto x86_l_1494;
	case 5271ULL: goto x86_l_1497;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5282ULL: goto x86_l_14a2;
	case 5289ULL: goto x86_l_14a9;
	case 5292ULL: goto x86_l_14ac;
	case 5294ULL: goto x86_l_14ae;
	case 5298ULL: goto x86_l_14b2;
	case 5305ULL: goto x86_l_14b9;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5337ULL: goto x86_l_14d9;
	case 5339ULL: goto x86_l_14db;
	case 5346ULL: goto x86_l_14e2;
	case 5349ULL: goto x86_l_14e5;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5369ULL: goto x86_l_14f9;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5377ULL: goto x86_l_1501;
	case 5381ULL: goto x86_l_1505;
	case 5384ULL: goto x86_l_1508;
	case 5386ULL: goto x86_l_150a;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5412ULL: goto x86_l_1524;
	case 5419ULL: goto x86_l_152b;
	case 5427ULL: goto x86_l_1533;
	case 5434ULL: goto x86_l_153a;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5459ULL: goto x86_l_1553;
	case 5462ULL: goto x86_l_1556;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5495ULL: goto x86_l_1577;
	case 5497ULL: goto x86_l_1579;
	case 5500ULL: goto x86_l_157c;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5532ULL: goto x86_l_159c;
	case 5540ULL: goto x86_l_15a4;
	case 5547ULL: goto x86_l_15ab;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5565ULL: goto x86_l_15bd;
	case 5572ULL: goto x86_l_15c4;
	case 5575ULL: goto x86_l_15c7;
	case 5577ULL: goto x86_l_15c9;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5589ULL: goto x86_l_15d5;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5599ULL: goto x86_l_15df;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5635ULL: goto x86_l_1603;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5642ULL: goto x86_l_160a;
	case 5645ULL: goto x86_l_160d;
	case 5648ULL: goto x86_l_1610;
	case 5651ULL: goto x86_l_1613;
	case 5654ULL: goto x86_l_1616;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5669ULL: goto x86_l_1625;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5680ULL: goto x86_l_1630;
	case 5683ULL: goto x86_l_1633;
	case 5690ULL: goto x86_l_163a;
	case 5697ULL: goto x86_l_1641;
	case 5700ULL: goto x86_l_1644;
	case 5707ULL: goto x86_l_164b;
	case 5713ULL: goto x86_l_1651;
	case 5721ULL: goto x86_l_1659;
	case 5729ULL: goto x86_l_1661;
	case 5741ULL: goto x86_l_166d;
	case 5753ULL: goto x86_l_1679;
	case 5765ULL: goto x86_l_1685;
	case 5777ULL: goto x86_l_1691;
	case 5789ULL: goto x86_l_169d;
	case 5801ULL: goto x86_l_16a9;
	case 5813ULL: goto x86_l_16b5;
	case 5825ULL: goto x86_l_16c1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ff0:
	/* 0xff0: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_ff8:
	/* 0xff8: mov    rsi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1000:
	/* 0x1000: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1003:
	/* 0x1003: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_100b:
	/* 0x100b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_100e:
	/* 0x100e: jb     1026 <trace_ret_file_update_time+0x1026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1026;
	}
x86_l_1010:
	/* 0x1010: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1014:
	/* 0x1014: je     101b <trace_ret_file_update_time+0x101b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101b;
	}
x86_l_1016:
	/* 0x1016: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1019:
	/* 0x1019: jbe    1026 <trace_ret_file_update_time+0x1026> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1026;
	}
x86_l_101b:
	/* 0x101b: and    r13,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 264ULL);
x86_l_1023:
	/* 0x1023: or     rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_1026:
	/* 0x1026: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1029:
	/* 0x1029: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_102c:
	/* 0x102c: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_102f:
	/* 0x102f: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1034:
	/* 0x1034: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_103c:
	/* 0x103c: je     1109 <trace_ret_file_update_time+0x1109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1109;
	}
x86_l_1042:
	/* 0x1042: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_104d:
	/* 0x104d: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1054:
	/* 0x1054: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_105b:
	/* 0x105b: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1063:
	/* 0x1063: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1065:
	/* 0x1065: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_106c:
	/* 0x106c: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_1073:
	/* 0x1073: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_107b:
	/* 0x107b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_1082:
	/* 0x1082: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_108a:
	/* 0x108a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_108f:
	/* 0x108f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1091:
	/* 0x1091: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1094:
	/* 0x1094: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1098:
	/* 0x1098: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10a0:
	/* 0x10a0: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10a7:
	/* 0x10a7: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: je     10cc <trace_ret_file_update_time+0x10cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10cc;
	}
x86_l_10ac:
	/* 0x10ac: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10b4:
	/* 0x10b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b9:
	/* 0x10b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bb:
	/* 0x10bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10be:
	/* 0x10be: je     10cc <trace_ret_file_update_time+0x10cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10cc;
	}
x86_l_10c0:
	/* 0x10c0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c3:
	/* 0x10c3: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c7:
	/* 0x10c7: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10ca:
	/* 0x10ca: jmp    10ce <trace_ret_file_update_time+0x10ce> */
	goto x86_l_10ce;
x86_l_10cc:
	/* 0x10cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ce:
	/* 0x10ce: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10d1:
	/* 0x10d1: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10d9:
	/* 0x10d9: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_10dc:
	/* 0x10dc: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_10df:
	/* 0x10df: jae    10e8 <trace_ret_file_update_time+0x10e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_10e8;
	}
x86_l_10e1:
	/* 0x10e1: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_10e6:
	/* 0x10e6: jmp    1103 <trace_ret_file_update_time+0x1103> */
	goto x86_l_1103;
x86_l_10e8:
	/* 0x10e8: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10ec:
	/* 0x10ec: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_10f1:
	/* 0x10f1: je     10f8 <trace_ret_file_update_time+0x10f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10f8;
	}
x86_l_10f3:
	/* 0x10f3: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: jbe    1103 <trace_ret_file_update_time+0x1103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1103;
	}
x86_l_10f8:
	/* 0x10f8: and    r15,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 240ULL);
x86_l_1100:
	/* 0x1100: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1103:
	/* 0x1103: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1106:
	/* 0x1106: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1109:
	/* 0x1109: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1111:
	/* 0x1111: je     11f7 <trace_ret_file_update_time+0x11f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f7;
	}
x86_l_1117:
	/* 0x1117: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_111c:
	/* 0x111c: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1123:
	/* 0x1123: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_112b:
	/* 0x112b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1130:
	/* 0x1130: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1135:
	/* 0x1135: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_113a:
	/* 0x113a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_113c:
	/* 0x113c: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1144:
	/* 0x1144: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1148:
	/* 0x1148: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1150:
	/* 0x1150: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1155:
	/* 0x1155: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_115a:
	/* 0x115a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_115f:
	/* 0x115f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1161:
	/* 0x1161: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1169:
	/* 0x1169: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_116e:
	/* 0x116e: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1173:
	/* 0x1173: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1178:
	/* 0x1178: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1180:
	/* 0x1180: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1185:
	/* 0x1185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1187:
	/* 0x1187: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_118b:
	/* 0x118b: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_118f:
	/* 0x118f: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1196:
	/* 0x1196: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_119d:
	/* 0x119d: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11a5:
	/* 0x11a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_11ac:
	/* 0x11ac: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11b4:
	/* 0x11b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b9:
	/* 0x11b9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11bc:
	/* 0x11bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11be:
	/* 0x11be: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11c5:
	/* 0x11c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c8:
	/* 0x11c8: je     11e9 <trace_ret_file_update_time+0x11e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e9;
	}
x86_l_11ca:
	/* 0x11ca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11cd:
	/* 0x11cd: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11d1:
	/* 0x11d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11d6:
	/* 0x11d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d8:
	/* 0x11d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11db:
	/* 0x11db: je     11e9 <trace_ret_file_update_time+0x11e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e9;
	}
x86_l_11dd:
	/* 0x11dd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e0:
	/* 0x11e0: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11e4:
	/* 0x11e4: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e7:
	/* 0x11e7: jmp    11eb <trace_ret_file_update_time+0x11eb> */
	goto x86_l_11eb;
x86_l_11e9:
	/* 0x11e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11eb:
	/* 0x11eb: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ee:
	/* 0x11ee: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_11f1:
	/* 0x11f1: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11f4:
	/* 0x11f4: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11f7:
	/* 0x11f7: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_11ff:
	/* 0x11ff: je     1311 <trace_ret_file_update_time+0x1311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1311;
	}
x86_l_1205:
	/* 0x1205: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_120c:
	/* 0x120c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1210:
	/* 0x1210: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1218:
	/* 0x1218: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_121d:
	/* 0x121d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1222:
	/* 0x1222: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1227:
	/* 0x1227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1229:
	/* 0x1229: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1231:
	/* 0x1231: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1239:
	/* 0x1239: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_123e:
	/* 0x123e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1243:
	/* 0x1243: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1248:
	/* 0x1248: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_124b:
	/* 0x124b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124d:
	/* 0x124d: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1254:
	/* 0x1254: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1258:
	/* 0x1258: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_125c:
	/* 0x125c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1260:
	/* 0x1260: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1268:
	/* 0x1268: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_126d:
	/* 0x126d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1272:
	/* 0x1272: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1277:
	/* 0x1277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1279:
	/* 0x1279: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1281:
	/* 0x1281: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1285:
	/* 0x1285: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_128d:
	/* 0x128d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1292:
	/* 0x1292: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1297:
	/* 0x1297: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_129c:
	/* 0x129c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129e:
	/* 0x129e: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12a5:
	/* 0x12a5: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12a9:
	/* 0x12a9: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_12b0:
	/* 0x12b0: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_12b7:
	/* 0x12b7: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12bf:
	/* 0x12bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_12c6:
	/* 0x12c6: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12ce:
	/* 0x12ce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d3:
	/* 0x12d3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12d6:
	/* 0x12d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d8:
	/* 0x12d8: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12df:
	/* 0x12df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e2:
	/* 0x12e2: je     1303 <trace_ret_file_update_time+0x1303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1303;
	}
x86_l_12e4:
	/* 0x12e4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12eb:
	/* 0x12eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f0:
	/* 0x12f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f2:
	/* 0x12f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f5:
	/* 0x12f5: je     1303 <trace_ret_file_update_time+0x1303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1303;
	}
x86_l_12f7:
	/* 0x12f7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fa:
	/* 0x12fa: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12fe:
	/* 0x12fe: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1301:
	/* 0x1301: jmp    1305 <trace_ret_file_update_time+0x1305> */
	goto x86_l_1305;
x86_l_1303:
	/* 0x1303: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1305:
	/* 0x1305: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1308:
	/* 0x1308: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_130b:
	/* 0x130b: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_130e:
	/* 0x130e: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1311:
	/* 0x1311: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1319:
	/* 0x1319: je     1410 <trace_ret_file_update_time+0x1410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1410;
	}
x86_l_131f:
	/* 0x131f: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1324:
	/* 0x1324: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_132b:
	/* 0x132b: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1333:
	/* 0x1333: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1338:
	/* 0x1338: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_133d:
	/* 0x133d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1342:
	/* 0x1342: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1344:
	/* 0x1344: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_134c:
	/* 0x134c: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1354:
	/* 0x1354: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1359:
	/* 0x1359: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_135e:
	/* 0x135e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1363:
	/* 0x1363: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1365:
	/* 0x1365: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_136d:
	/* 0x136d: lea    r15,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1375:
	/* 0x1375: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_137a:
	/* 0x137a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_137f:
	/* 0x137f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1382:
	/* 0x1382: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_138d:
	/* 0x138d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1392:
	/* 0x1392: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1397:
	/* 0x1397: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_139a:
	/* 0x139a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_139f:
	/* 0x139f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13a2:
	/* 0x13a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a4:
	/* 0x13a4: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_13ab:
	/* 0x13ab: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_13b2:
	/* 0x13b2: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_13ba:
	/* 0x13ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_13c1:
	/* 0x13c1: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_13c9:
	/* 0x13c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ce:
	/* 0x13ce: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d1:
	/* 0x13d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d3:
	/* 0x13d3: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13da:
	/* 0x13da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13dd:
	/* 0x13dd: je     13fd <trace_ret_file_update_time+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13fd;
	}
x86_l_13df:
	/* 0x13df: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13e2:
	/* 0x13e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e7:
	/* 0x13e7: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ec:
	/* 0x13ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ef:
	/* 0x13ef: je     13fd <trace_ret_file_update_time+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13fd;
	}
x86_l_13f1:
	/* 0x13f1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f4:
	/* 0x13f4: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f8:
	/* 0x13f8: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13fb:
	/* 0x13fb: jmp    13ff <trace_ret_file_update_time+0x13ff> */
	goto x86_l_13ff;
x86_l_13fd:
	/* 0x13fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ff:
	/* 0x13ff: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1402:
	/* 0x1402: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1405:
	/* 0x1405: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1408:
	/* 0x1408: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_140b:
	/* 0x140b: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1410:
	/* 0x1410: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1418:
	/* 0x1418: je     14a2 <trace_ret_file_update_time+0x14a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a2;
	}
x86_l_141e:
	/* 0x141e: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1422:
	/* 0x1422: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1427:
	/* 0x1427: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_142c:
	/* 0x142c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_142f:
	/* 0x142f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1434:
	/* 0x1434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1436:
	/* 0x1436: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_143d:
	/* 0x143d: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1444:
	/* 0x1444: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_144c:
	/* 0x144c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1453:
	/* 0x1453: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_145b:
	/* 0x145b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1460:
	/* 0x1460: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1463:
	/* 0x1463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1465:
	/* 0x1465: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_146c:
	/* 0x146c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146f:
	/* 0x146f: je     148f <trace_ret_file_update_time+0x148f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148f;
	}
x86_l_1471:
	/* 0x1471: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1474:
	/* 0x1474: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1479:
	/* 0x1479: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_147c:
	/* 0x147c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_147e:
	/* 0x147e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1481:
	/* 0x1481: je     148f <trace_ret_file_update_time+0x148f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148f;
	}
x86_l_1483:
	/* 0x1483: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1486:
	/* 0x1486: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_148a:
	/* 0x148a: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_148d:
	/* 0x148d: jmp    1491 <trace_ret_file_update_time+0x1491> */
	goto x86_l_1491;
x86_l_148f:
	/* 0x148f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1491:
	/* 0x1491: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1494:
	/* 0x1494: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1497:
	/* 0x1497: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_149a:
	/* 0x149a: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_149d:
	/* 0x149d: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_14a2:
	/* 0x14a2: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_14a9:
	/* 0x14a9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_14ac:
	/* 0x14ac: je     1518 <trace_ret_file_update_time+0x1518> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1518;
	}
x86_l_14ae:
	/* 0x14ae: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b2:
	/* 0x14b2: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14b9:
	/* 0x14b9: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_14c0:
	/* 0x14c0: mov    WORD PTR [rsp+0x40],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14c5:
	/* 0x14c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_14cc:
	/* 0x14cc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14d1:
	/* 0x14d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d6:
	/* 0x14d6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14d9:
	/* 0x14d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14db:
	/* 0x14db: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14e2:
	/* 0x14e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e5:
	/* 0x14e5: je     150a <trace_ret_file_update_time+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150a;
	}
x86_l_14e7:
	/* 0x14e7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14ea:
	/* 0x14ea: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14f2:
	/* 0x14f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f7:
	/* 0x14f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f9:
	/* 0x14f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14fc:
	/* 0x14fc: je     150a <trace_ret_file_update_time+0x150a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150a;
	}
x86_l_14fe:
	/* 0x14fe: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1501:
	/* 0x1501: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1505:
	/* 0x1505: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1508:
	/* 0x1508: jmp    150c <trace_ret_file_update_time+0x150c> */
	goto x86_l_150c;
x86_l_150a:
	/* 0x150a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150c:
	/* 0x150c: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_150f:
	/* 0x150f: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1512:
	/* 0x1512: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1515:
	/* 0x1515: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1518:
	/* 0x1518: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_151f:
	/* 0x151f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: je     1585 <trace_ret_file_update_time+0x1585> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1585;
	}
x86_l_1524:
	/* 0x1524: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_152b:
	/* 0x152b: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1533:
	/* 0x1533: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_153a:
	/* 0x153a: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1542:
	/* 0x1542: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1547:
	/* 0x1547: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_154a:
	/* 0x154a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154c:
	/* 0x154c: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1553:
	/* 0x1553: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1556:
	/* 0x1556: je     1577 <trace_ret_file_update_time+0x1577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1577;
	}
x86_l_1558:
	/* 0x1558: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_155b:
	/* 0x155b: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_155f:
	/* 0x155f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1564:
	/* 0x1564: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1566:
	/* 0x1566: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1569:
	/* 0x1569: je     1577 <trace_ret_file_update_time+0x1577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1577;
	}
x86_l_156b:
	/* 0x156b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156e:
	/* 0x156e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1572:
	/* 0x1572: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1575:
	/* 0x1575: jmp    1579 <trace_ret_file_update_time+0x1579> */
	goto x86_l_1579;
x86_l_1577:
	/* 0x1577: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1579:
	/* 0x1579: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_157c:
	/* 0x157c: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_157f:
	/* 0x157f: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1582:
	/* 0x1582: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1585:
	/* 0x1585: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_158c:
	/* 0x158c: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_158f:
	/* 0x158f: je     1616 <trace_ret_file_update_time+0x1616> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1616;
	}
x86_l_1595:
	/* 0x1595: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_159c:
	/* 0x159c: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15a4:
	/* 0x15a4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_15ab:
	/* 0x15ab: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15b3:
	/* 0x15b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b8:
	/* 0x15b8: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15bb:
	/* 0x15bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bd:
	/* 0x15bd: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15c4:
	/* 0x15c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15c7:
	/* 0x15c7: je     1608 <trace_ret_file_update_time+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1608;
	}
x86_l_15c9:
	/* 0x15c9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15cc:
	/* 0x15cc: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15d1:
	/* 0x15d1: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15d5:
	/* 0x15d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15da:
	/* 0x15da: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15dd:
	/* 0x15dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15df:
	/* 0x15df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e2:
	/* 0x15e2: jne    15fc <trace_ret_file_update_time+0x15fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15fc;
	}
x86_l_15e4:
	/* 0x15e4: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e9:
	/* 0x15e9: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ed:
	/* 0x15ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15f2:
	/* 0x15f2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15f5:
	/* 0x15f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f7:
	/* 0x15f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15fa:
	/* 0x15fa: je     1608 <trace_ret_file_update_time+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1608;
	}
x86_l_15fc:
	/* 0x15fc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ff:
	/* 0x15ff: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1603:
	/* 0x1603: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1606:
	/* 0x1606: jmp    160a <trace_ret_file_update_time+0x160a> */
	goto x86_l_160a;
x86_l_1608:
	/* 0x1608: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_160a:
	/* 0x160a: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_160d:
	/* 0x160d: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1610:
	/* 0x1610: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1613:
	/* 0x1613: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1616:
	/* 0x1616: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_161d:
	/* 0x161d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1620:
	/* 0x1620: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1625:
	/* 0x1625: je     1633 <trace_ret_file_update_time+0x1633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1633;
	}
x86_l_1627:
	/* 0x1627: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_162c:
	/* 0x162c: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1630:
	/* 0x1630: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1633:
	/* 0x1633: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_163a:
	/* 0x163a: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1641:
	/* 0x1641: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1644:
	/* 0x1644: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_164b:
	/* 0x164b: je     2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9105ULL;
	}
x86_l_1651:
	/* 0x1651: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1659:
	/* 0x1659: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1661:
	/* 0x1661: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_166d:
	/* 0x166d: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_1679:
	/* 0x1679: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1685:
	/* 0x1685: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_1691:
	/* 0x1691: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_169d:
	/* 0x169d: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_16a9:
	/* 0x16a9: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_16b5:
	/* 0x16b5: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_16c1:
	/* 0x16c1: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
	return 5837ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5837ULL: goto x86_l_16cd;
	case 5849ULL: goto x86_l_16d9;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5869ULL: goto x86_l_16ed;
	case 5875ULL: goto x86_l_16f3;
	case 5883ULL: goto x86_l_16fb;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5911ULL: goto x86_l_1717;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6030ULL: goto x86_l_178e;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6080ULL: goto x86_l_17c0;
	case 6083ULL: goto x86_l_17c3;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6132ULL: goto x86_l_17f4;
	case 6138ULL: goto x86_l_17fa;
	case 6143ULL: goto x86_l_17ff;
	case 6146ULL: goto x86_l_1802;
	case 6152ULL: goto x86_l_1808;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6178ULL: goto x86_l_1822;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6195ULL: goto x86_l_1833;
	case 6197ULL: goto x86_l_1835;
	case 6199ULL: goto x86_l_1837;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6215ULL: goto x86_l_1847;
	case 6217ULL: goto x86_l_1849;
	case 6220ULL: goto x86_l_184c;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6263ULL: goto x86_l_1877;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6277ULL: goto x86_l_1885;
	case 6282ULL: goto x86_l_188a;
	case 6289ULL: goto x86_l_1891;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6307ULL: goto x86_l_18a3;
	case 6313ULL: goto x86_l_18a9;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6328ULL: goto x86_l_18b8;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6351ULL: goto x86_l_18cf;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6366ULL: goto x86_l_18de;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6390ULL: goto x86_l_18f6;
	case 6394ULL: goto x86_l_18fa;
	case 6399ULL: goto x86_l_18ff;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6424ULL: goto x86_l_1918;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6507ULL: goto x86_l_196b;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6521ULL: goto x86_l_1979;
	case 6527ULL: goto x86_l_197f;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6559ULL: goto x86_l_199f;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6586ULL: goto x86_l_19ba;
	case 6591ULL: goto x86_l_19bf;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6661ULL: goto x86_l_1a05;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6684ULL: goto x86_l_1a1c;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6772ULL: goto x86_l_1a74;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6806ULL: goto x86_l_1a96;
	case 6815ULL: goto x86_l_1a9f;
	case 6824ULL: goto x86_l_1aa8;
	case 6828ULL: goto x86_l_1aac;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6962ULL: goto x86_l_1b32;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6976ULL: goto x86_l_1b40;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7103ULL: goto x86_l_1bbf;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7158ULL: goto x86_l_1bf6;
	case 7169ULL: goto x86_l_1c01;
	case 7177ULL: goto x86_l_1c09;
	case 7185ULL: goto x86_l_1c11;
	case 7189ULL: goto x86_l_1c15;
	case 7193ULL: goto x86_l_1c19;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7227ULL: goto x86_l_1c3b;
	case 7230ULL: goto x86_l_1c3e;
	case 7236ULL: goto x86_l_1c44;
	case 7244ULL: goto x86_l_1c4c;
	case 7251ULL: goto x86_l_1c53;
	case 7253ULL: goto x86_l_1c55;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7270ULL: goto x86_l_1c66;
	case 7272ULL: goto x86_l_1c68;
	case 7280ULL: goto x86_l_1c70;
	case 7286ULL: goto x86_l_1c76;
	case 7292ULL: goto x86_l_1c7c;
	case 7301ULL: goto x86_l_1c85;
	case 7309ULL: goto x86_l_1c8d;
	case 7317ULL: goto x86_l_1c95;
	case 7323ULL: goto x86_l_1c9b;
	case 7325ULL: goto x86_l_1c9d;
	case 7329ULL: goto x86_l_1ca1;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7354ULL: goto x86_l_1cba;
	case 7358ULL: goto x86_l_1cbe;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7373ULL: goto x86_l_1ccd;
	case 7375ULL: goto x86_l_1ccf;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7387ULL: goto x86_l_1cdb;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7404ULL: goto x86_l_1cec;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7423ULL: goto x86_l_1cff;
	case 7430ULL: goto x86_l_1d06;
	case 7438ULL: goto x86_l_1d0e;
	case 7445ULL: goto x86_l_1d15;
	case 7447ULL: goto x86_l_1d17;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7472ULL: goto x86_l_1d30;
	case 7476ULL: goto x86_l_1d34;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7500ULL: goto x86_l_1d4c;
	case 7503ULL: goto x86_l_1d4f;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7516ULL: goto x86_l_1d5c;
	case 7523ULL: goto x86_l_1d63;
	case 7531ULL: goto x86_l_1d6b;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7549ULL: goto x86_l_1d7d;
	case 7555ULL: goto x86_l_1d83;
	case 7557ULL: goto x86_l_1d85;
	case 7565ULL: goto x86_l_1d8d;
	case 7569ULL: goto x86_l_1d91;
	case 7576ULL: goto x86_l_1d98;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7591ULL: goto x86_l_1da7;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7601ULL: goto x86_l_1db1;
	case 7609ULL: goto x86_l_1db9;
	case 7616ULL: goto x86_l_1dc0;
	case 7624ULL: goto x86_l_1dc8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_16cd:
	/* 0x16cd: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_16d9:
	/* 0x16d9: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_16e5:
	/* 0x16e5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ea:
	/* 0x16ea: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_16ed:
	/* 0x16ed: je     1877 <trace_ret_file_update_time+0x1877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1877;
	}
x86_l_16f3:
	/* 0x16f3: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_16fb:
	/* 0x16fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_1702:
	/* 0x1702: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1707:
	/* 0x1707: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170c:
	/* 0x170c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170e:
	/* 0x170e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1711:
	/* 0x1711: je     1883 <trace_ret_file_update_time+0x1883> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1883;
	}
x86_l_1717:
	/* 0x1717: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_171a:
	/* 0x171a: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171f:
	/* 0x171f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1724:
	/* 0x1724: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1729:
	/* 0x1729: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_172e:
	/* 0x172e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1733:
	/* 0x1733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1735:
	/* 0x1735: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_173a:
	/* 0x173a: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173f:
	/* 0x173f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1744:
	/* 0x1744: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1749:
	/* 0x1749: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_174e:
	/* 0x174e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1753:
	/* 0x1753: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1758:
	/* 0x1758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175a:
	/* 0x175a: test   BYTE PTR [rsp+0x40],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906976ULL);
x86_l_175f:
	/* 0x175f: jne    188a <trace_ret_file_update_time+0x188a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_188a;
	}
x86_l_1765:
	/* 0x1765: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_176a:
	/* 0x176a: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176f:
	/* 0x176f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1774:
	/* 0x1774: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1779:
	/* 0x1779: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_177e:
	/* 0x177e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1783:
	/* 0x1783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1785:
	/* 0x1785: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_178a:
	/* 0x178a: lea    rcx,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_178e:
	/* 0x178e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1792:
	/* 0x1792: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1797:
	/* 0x1797: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_179c:
	/* 0x179c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17a1:
	/* 0x17a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a5:
	/* 0x17a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17aa:
	/* 0x17aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ac:
	/* 0x17ac: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17b1:
	/* 0x17b1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17b6:
	/* 0x17b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17bb:
	/* 0x17bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17c0:
	/* 0x17c0: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_17c3:
	/* 0x17c3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_17c6:
	/* 0x17c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c8:
	/* 0x17c8: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17cd:
	/* 0x17cd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17d2:
	/* 0x17d2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17d6:
	/* 0x17d6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17db:
	/* 0x17db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17e0:
	/* 0x17e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17e5:
	/* 0x17e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17ea:
	/* 0x17ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ec:
	/* 0x17ec: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f1:
	/* 0x17f1: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_17f4:
	/* 0x17f4: je     18a0 <trace_ret_file_update_time+0x18a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a0;
	}
x86_l_17fa:
	/* 0x17fa: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17ff:
	/* 0x17ff: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1802:
	/* 0x1802: je     18a0 <trace_ret_file_update_time+0x18a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a0;
	}
x86_l_1808:
	/* 0x1808: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_180c:
	/* 0x180c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1811:
	/* 0x1811: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1816:
	/* 0x1816: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_181b:
	/* 0x181b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1820:
	/* 0x1820: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1822:
	/* 0x1822: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1826:
	/* 0x1826: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_182b:
	/* 0x182b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_182d:
	/* 0x182d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1833:
	/* 0x1833: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1835:
	/* 0x1835: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1837:
	/* 0x1837: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_183d:
	/* 0x183d: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1842:
	/* 0x1842: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1847:
	/* 0x1847: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1849:
	/* 0x1849: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_184c:
	/* 0x184c: jl     1a22 <trace_ret_file_update_time+0x1a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1a22;
	}
x86_l_1852:
	/* 0x1852: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1857:
	/* 0x1857: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_185e:
	/* 0x185e: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_1863:
	/* 0x1863: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1865:
	/* 0x1865: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186a:
	/* 0x186a: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_186f:
	/* 0x186f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1872:
	/* 0x1872: jmp    1926 <trace_ret_file_update_time+0x1926> */
	goto x86_l_1926;
x86_l_1877:
	/* 0x1877: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1879:
	/* 0x1879: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187b:
	/* 0x187b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187e:
	/* 0x187e: jmp    1c11 <trace_ret_file_update_time+0x1c11> */
	goto x86_l_1c11;
x86_l_1883:
	/* 0x1883: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1885:
	/* 0x1885: jmp    1a6c <trace_ret_file_update_time+0x1a6c> */
	goto x86_l_1a6c;
x86_l_188a:
	/* 0x188a: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1891:
	/* 0x1891: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1896:
	/* 0x1896: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_189b:
	/* 0x189b: jmp    1a55 <trace_ret_file_update_time+0x1a55> */
	goto x86_l_1a55;
x86_l_18a0:
	/* 0x18a0: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_18a3:
	/* 0x18a3: jne    1a22 <trace_ret_file_update_time+0x1a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a22;
	}
x86_l_18a9:
	/* 0x18a9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ad:
	/* 0x18ad: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_18b2:
	/* 0x18b2: je     1a22 <trace_ret_file_update_time+0x1a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a22;
	}
x86_l_18b8:
	/* 0x18b8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18bc:
	/* 0x18bc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c1:
	/* 0x18c1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18c6:
	/* 0x18c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18cb:
	/* 0x18cb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cf:
	/* 0x18cf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18d3:
	/* 0x18d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18d8:
	/* 0x18d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18da:
	/* 0x18da: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18de:
	/* 0x18de: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_18e1:
	/* 0x18e1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18e6:
	/* 0x18e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18eb:
	/* 0x18eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ef:
	/* 0x18ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18f4:
	/* 0x18f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f6:
	/* 0x18f6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18fa:
	/* 0x18fa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18ff:
	/* 0x18ff: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1904:
	/* 0x1904: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1909:
	/* 0x1909: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190d:
	/* 0x190d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1912:
	/* 0x1912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1914:
	/* 0x1914: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1918:
	/* 0x1918: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_191c:
	/* 0x191c: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1921:
	/* 0x1921: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1926:
	/* 0x1926: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_192b:
	/* 0x192b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1930:
	/* 0x1930: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1935:
	/* 0x1935: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_193a:
	/* 0x193a: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_193d:
	/* 0x193d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193f:
	/* 0x193f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1944:
	/* 0x1944: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1949:
	/* 0x1949: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_194d:
	/* 0x194d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1952:
	/* 0x1952: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1957:
	/* 0x1957: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_195c:
	/* 0x195c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1961:
	/* 0x1961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1963:
	/* 0x1963: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1968:
	/* 0x1968: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_196b:
	/* 0x196b: je     1a02 <trace_ret_file_update_time+0x1a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a02;
	}
x86_l_1971:
	/* 0x1971: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1976:
	/* 0x1976: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1979:
	/* 0x1979: je     1a02 <trace_ret_file_update_time+0x1a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a02;
	}
x86_l_197f:
	/* 0x197f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1983:
	/* 0x1983: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1988:
	/* 0x1988: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_198d:
	/* 0x198d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1992:
	/* 0x1992: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1997:
	/* 0x1997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1999:
	/* 0x1999: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_199d:
	/* 0x199d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_199f:
	/* 0x199f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19a5:
	/* 0x19a5: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19aa:
	/* 0x19aa: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_19ad:
	/* 0x19ad: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19af:
	/* 0x19af: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b4:
	/* 0x19b4: jb     24b2 <trace_ret_file_update_time+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9394ULL;
	}
x86_l_19ba:
	/* 0x19ba: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19bf:
	/* 0x19bf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19c5:
	/* 0x19c5: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19ca:
	/* 0x19ca: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19cd:
	/* 0x19cd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_19cf:
	/* 0x19cf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19d9:
	/* 0x19d9: jl     1a10 <trace_ret_file_update_time+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1a10;
	}
x86_l_19db:
	/* 0x19db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e0:
	/* 0x19e0: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_19e3:
	/* 0x19e3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_19e9:
	/* 0x19e9: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_19ee:
	/* 0x19ee: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19f0:
	/* 0x19f0: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f5:
	/* 0x19f5: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19fa:
	/* 0x19fa: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_19fd:
	/* 0x19fd: jmp    2426 <trace_ret_file_update_time+0x2426> */
	return 9254ULL;
x86_l_1a02:
	/* 0x1a02: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a05:
	/* 0x1a05: je     23a9 <trace_ret_file_update_time+0x23a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9129ULL;
	}
x86_l_1a0b:
	/* 0x1a0b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a10:
	/* 0x1a10: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a15:
	/* 0x1a15: cmp    r8d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 16384ULL);
x86_l_1a1c:
	/* 0x1a1c: jne    24b2 <trace_ret_file_update_time+0x24b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9394ULL;
	}
x86_l_1a22:
	/* 0x1a22: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a27:
	/* 0x1a27: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a2b:
	/* 0x1a2b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a30:
	/* 0x1a30: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1a35:
	/* 0x1a35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a3f:
	/* 0x1a3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a41:
	/* 0x1a41: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a46:
	/* 0x1a46: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1a50:
	/* 0x1a50: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a55:
	/* 0x1a55: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1a58:
	/* 0x1a58: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a5d:
	/* 0x1a5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5f:
	/* 0x1a5f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a62:
	/* 0x1a62: and    r8d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1a69:
	/* 0x1a69: add    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a6c:
	/* 0x1a6c: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a74:
	/* 0x1a74: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1a78:
	/* 0x1a78: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a82:
	/* 0x1a82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a87:
	/* 0x1a87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a8f:
	/* 0x1a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a91:
	/* 0x1a91: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a96:
	/* 0x1a96: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1aa8:
	/* 0x1aa8: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aac:
	/* 0x1aac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ab6:
	/* 0x1ab6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1abb:
	/* 0x1abb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac0:
	/* 0x1ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac2:
	/* 0x1ac2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1acc:
	/* 0x1acc: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1ad0:
	/* 0x1ad0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ada:
	/* 0x1ada: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1adf:
	/* 0x1adf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ae7:
	/* 0x1ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae9:
	/* 0x1ae9: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aed:
	/* 0x1aed: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1af2:
	/* 0x1af2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1af7:
	/* 0x1af7: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1afc:
	/* 0x1afc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b01:
	/* 0x1b01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b06:
	/* 0x1b06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b0b:
	/* 0x1b0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0d:
	/* 0x1b0d: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b12:
	/* 0x1b12: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1b15:
	/* 0x1b15: js     1b40 <trace_ret_file_update_time+0x1b40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b40;
	}
x86_l_1b17:
	/* 0x1b17: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b1c:
	/* 0x1b1c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b21:
	/* 0x1b21: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b26:
	/* 0x1b26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b2b:
	/* 0x1b2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b30:
	/* 0x1b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b32:
	/* 0x1b32: imul   rbx,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RBX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1b39:
	/* 0x1b39: add    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1b3e:
	/* 0x1b3e: jmp    1b42 <trace_ret_file_update_time+0x1b42> */
	goto x86_l_1b42;
x86_l_1b40:
	/* 0x1b40: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b42:
	/* 0x1b42: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b47:
	/* 0x1b47: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b51:
	/* 0x1b51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b56:
	/* 0x1b56: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b59:
	/* 0x1b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5b:
	/* 0x1b5b: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b60:
	/* 0x1b60: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b64:
	/* 0x1b64: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b69:
	/* 0x1b69: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b6e:
	/* 0x1b6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b73:
	/* 0x1b73: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b78:
	/* 0x1b78: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b81:
	/* 0x1b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b83:
	/* 0x1b83: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b88:
	/* 0x1b88: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1b92:
	/* 0x1b92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b97:
	/* 0x1b97: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba1:
	/* 0x1ba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba3:
	/* 0x1ba3: mov    r15d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba8:
	/* 0x1ba8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bad:
	/* 0x1bad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bbf:
	/* 0x1bbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc1:
	/* 0x1bc1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc6:
	/* 0x1bc6: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1bca:
	/* 0x1bca: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bde:
	/* 0x1bde: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1be2:
	/* 0x1be2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be7:
	/* 0x1be7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be9:
	/* 0x1be9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bee:
	/* 0x1bee: mov    DWORD PTR [rsp+0xd0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    DWORD PTR [rsp+0xd4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1c01:
	/* 0x1c01: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1c09:
	/* 0x1c09: mov    QWORD PTR [rsp+0xe0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1c11:
	/* 0x1c11: mov    ecx,DWORD PTR [r13+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1c15:
	/* 0x1c15: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c19:
	/* 0x1c19: mov    DWORD PTR [rsp+0x24],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c23:
	/* 0x1c23: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_modification_map)));
x86_l_1c2a:
	/* 0x1c2a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c34:
	/* 0x1c34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c36:
	/* 0x1c36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c39:
	/* 0x1c39: je     1c44 <trace_ret_file_update_time+0x1c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c44;
	}
x86_l_1c3b:
	/* 0x1c3b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3e:
	/* 0x1c3e: jne    2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9105ULL;
	}
x86_l_1c44:
	/* 0x1c44: mov    DWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_modification_map)));
x86_l_1c53:
	/* 0x1c53: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c55:
	/* 0x1c55: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c5a:
	/* 0x1c5a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c64:
	/* 0x1c64: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c66:
	/* 0x1c66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c68:
	/* 0x1c68: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c70:
	/* 0x1c70: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1c76:
	/* 0x1c76: ja     1d06 <trace_ret_file_update_time+0x1d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d06;
	}
x86_l_1c7c:
	/* 0x1c7c: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1c85:
	/* 0x1c85: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c8d:
	/* 0x1c8d: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1c95:
	/* 0x1c95: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1c9b:
	/* 0x1c9b: ja     1d06 <trace_ret_file_update_time+0x1d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d06;
	}
x86_l_1c9d:
	/* 0x1c9d: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ca1:
	/* 0x1ca1: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1ca8:
	/* 0x1ca8: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1cad:
	/* 0x1cad: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1cb2:
	/* 0x1cb2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cba:
	/* 0x1cba: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1cbe:
	/* 0x1cbe: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1cca:
	/* 0x1cca: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ccd:
	/* 0x1ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccf:
	/* 0x1ccf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cd1:
	/* 0x1cd1: jle    1d06 <trace_ret_file_update_time+0x1d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1d06;
	}
x86_l_1cd3:
	/* 0x1cd3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cdb:
	/* 0x1cdb: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1ce2:
	/* 0x1ce2: ja     1d06 <trace_ret_file_update_time+0x1d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d06;
	}
x86_l_1ce4:
	/* 0x1ce4: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1cec:
	/* 0x1cec: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1cf4:
	/* 0x1cf4: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1cf7:
	/* 0x1cf7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cff:
	/* 0x1cff: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d06:
	/* 0x1d06: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d0e:
	/* 0x1d0e: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1d15:
	/* 0x1d15: ja     1d63 <trace_ret_file_update_time+0x1d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d63;
	}
x86_l_1d17:
	/* 0x1d17: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1d20:
	/* 0x1d20: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1d26:
	/* 0x1d26: ja     1d63 <trace_ret_file_update_time+0x1d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d63;
	}
x86_l_1d28:
	/* 0x1d28: lea    rdx,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d30:
	/* 0x1d30: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d34:
	/* 0x1d34: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d40:
	/* 0x1d40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d45:
	/* 0x1d45: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d4a:
	/* 0x1d4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4c:
	/* 0x1d4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4f:
	/* 0x1d4f: js     1d63 <trace_ret_file_update_time+0x1d63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d63;
	}
x86_l_1d51:
	/* 0x1d51: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1d54:
	/* 0x1d54: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d5c:
	/* 0x1d5c: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d63:
	/* 0x1d63: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d6b:
	/* 0x1d6b: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1d72:
	/* 0x1d72: ja     1dc0 <trace_ret_file_update_time+0x1dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dc0;
	}
x86_l_1d74:
	/* 0x1d74: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1d7d:
	/* 0x1d7d: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1d83:
	/* 0x1d83: ja     1dc0 <trace_ret_file_update_time+0x1dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dc0;
	}
x86_l_1d85:
	/* 0x1d85: lea    rdx,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1d8d:
	/* 0x1d8d: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d91:
	/* 0x1d91: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1d98:
	/* 0x1d98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d9d:
	/* 0x1d9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da2:
	/* 0x1da2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da7:
	/* 0x1da7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da9:
	/* 0x1da9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dac:
	/* 0x1dac: js     1dc0 <trace_ret_file_update_time+0x1dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dc0;
	}
x86_l_1dae:
	/* 0x1dae: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1db1:
	/* 0x1db1: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1db9:
	/* 0x1db9: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1dc0:
	/* 0x1dc0: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1dc8:
	/* 0x1dc8: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
	return 7631ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7631ULL: goto x86_l_1dcf;
	case 7633ULL: goto x86_l_1dd1;
	case 7642ULL: goto x86_l_1dda;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7654ULL: goto x86_l_1de6;
	case 7661ULL: goto x86_l_1ded;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7702ULL: goto x86_l_1e16;
	case 7709ULL: goto x86_l_1e1d;
	case 7717ULL: goto x86_l_1e25;
	case 7724ULL: goto x86_l_1e2c;
	case 7726ULL: goto x86_l_1e2e;
	case 7735ULL: goto x86_l_1e37;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7782ULL: goto x86_l_1e66;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7795ULL: goto x86_l_1e73;
	case 7802ULL: goto x86_l_1e7a;
	case 7809ULL: goto x86_l_1e81;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7833ULL: goto x86_l_1e99;
	case 7836ULL: goto x86_l_1e9c;
	case 7838ULL: goto x86_l_1e9e;
	case 7843ULL: goto x86_l_1ea3;
	case 7848ULL: goto x86_l_1ea8;
	case 7852ULL: goto x86_l_1eac;
	case 7857ULL: goto x86_l_1eb1;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7872ULL: goto x86_l_1ec0;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7893ULL: goto x86_l_1ed5;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7940ULL: goto x86_l_1f04;
	case 7944ULL: goto x86_l_1f08;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8007ULL: goto x86_l_1f47;
	case 8011ULL: goto x86_l_1f4b;
	case 8015ULL: goto x86_l_1f4f;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8041ULL: goto x86_l_1f69;
	case 8045ULL: goto x86_l_1f6d;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8173ULL: goto x86_l_1fed;
	case 8177ULL: goto x86_l_1ff1;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8226ULL: goto x86_l_2022;
	case 8231ULL: goto x86_l_2027;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8244ULL: goto x86_l_2034;
	case 8248ULL: goto x86_l_2038;
	case 8252ULL: goto x86_l_203c;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8279ULL: goto x86_l_2057;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8309ULL: goto x86_l_2075;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8333ULL: goto x86_l_208d;
	case 8336ULL: goto x86_l_2090;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8376ULL: goto x86_l_20b8;
	case 8380ULL: goto x86_l_20bc;
	case 8384ULL: goto x86_l_20c0;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8441ULL: goto x86_l_20f9;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8466ULL: goto x86_l_2112;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8493ULL: goto x86_l_212d;
	case 8496ULL: goto x86_l_2130;
	case 8498ULL: goto x86_l_2132;
	case 8502ULL: goto x86_l_2136;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8524ULL: goto x86_l_214c;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8544ULL: goto x86_l_2160;
	case 8548ULL: goto x86_l_2164;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8574ULL: goto x86_l_217e;
	case 8579ULL: goto x86_l_2183;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8589ULL: goto x86_l_218d;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8697ULL: goto x86_l_21f9;
	case 8701ULL: goto x86_l_21fd;
	case 8706ULL: goto x86_l_2202;
	case 8710ULL: goto x86_l_2206;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8799ULL: goto x86_l_225f;
	case 8802ULL: goto x86_l_2262;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8811ULL: goto x86_l_226b;
	case 8816ULL: goto x86_l_2270;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8938ULL: goto x86_l_22ea;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8985ULL: goto x86_l_2319;
	case 8987ULL: goto x86_l_231b;
	case 8995ULL: goto x86_l_2323;
	case 8999ULL: goto x86_l_2327;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9040ULL: goto x86_l_2350;
	case 9044ULL: goto x86_l_2354;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9075ULL: goto x86_l_2373;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9107ULL: goto x86_l_2393;
	case 9114ULL: goto x86_l_239a;
	case 9115ULL: goto x86_l_239b;
	case 9117ULL: goto x86_l_239d;
	case 9119ULL: goto x86_l_239f;
	case 9121ULL: goto x86_l_23a1;
	case 9123ULL: goto x86_l_23a3;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9172ULL: goto x86_l_23d4;
	case 9176ULL: goto x86_l_23d8;
	case 9181ULL: goto x86_l_23dd;
	case 9183ULL: goto x86_l_23df;
	case 9187ULL: goto x86_l_23e3;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9211ULL: goto x86_l_23fb;
	case 9215ULL: goto x86_l_23ff;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9241ULL: goto x86_l_2419;
	case 9245ULL: goto x86_l_241d;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9293ULL: goto x86_l_244d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1dcf:
	/* 0x1dcf: ja     1e1d <trace_ret_file_update_time+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e1d;
	}
x86_l_1dd1:
	/* 0x1dd1: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1dda:
	/* 0x1dda: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1de0:
	/* 0x1de0: ja     1e1d <trace_ret_file_update_time+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e1d;
	}
x86_l_1de2:
	/* 0x1de2: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1de6:
	/* 0x1de6: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ded:
	/* 0x1ded: lea    rdx,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1df5:
	/* 0x1df5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dff:
	/* 0x1dff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e04:
	/* 0x1e04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e06:
	/* 0x1e06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e09:
	/* 0x1e09: js     1e1d <trace_ret_file_update_time+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e1d;
	}
x86_l_1e0b:
	/* 0x1e0b: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e16:
	/* 0x1e16: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e1d:
	/* 0x1e1d: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e25:
	/* 0x1e25: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1e2c:
	/* 0x1e2c: ja     1e7a <trace_ret_file_update_time+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e7a;
	}
x86_l_1e2e:
	/* 0x1e2e: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1e37:
	/* 0x1e37: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1e3d:
	/* 0x1e3d: ja     1e7a <trace_ret_file_update_time+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e7a;
	}
x86_l_1e3f:
	/* 0x1e3f: lea    rdx,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1e47:
	/* 0x1e47: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e4b:
	/* 0x1e4b: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1e52:
	/* 0x1e52: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e57:
	/* 0x1e57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e61:
	/* 0x1e61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e63:
	/* 0x1e63: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e66:
	/* 0x1e66: js     1e7a <trace_ret_file_update_time+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e7a;
	}
x86_l_1e68:
	/* 0x1e68: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e73:
	/* 0x1e73: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    r13,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1e81:
	/* 0x1e81: lea    r15,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e85:
	/* 0x1e85: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e8a:
	/* 0x1e8a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e94:
	/* 0x1e94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e99:
	/* 0x1e99: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e9c:
	/* 0x1e9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9e:
	/* 0x1e9e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ea3:
	/* 0x1ea3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ea8:
	/* 0x1ea8: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eac:
	/* 0x1eac: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eb1:
	/* 0x1eb1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1eb6:
	/* 0x1eb6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ebb:
	/* 0x1ebb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec0:
	/* 0x1ec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec2:
	/* 0x1ec2: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ec7:
	/* 0x1ec7: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1ecb:
	/* 0x1ecb: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ed5:
	/* 0x1ed5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eda:
	/* 0x1eda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1edf:
	/* 0x1edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee1:
	/* 0x1ee1: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ee6:
	/* 0x1ee6: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1eea:
	/* 0x1eea: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eef:
	/* 0x1eef: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ef4:
	/* 0x1ef4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1efe:
	/* 0x1efe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f00:
	/* 0x1f00: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f04:
	/* 0x1f04: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1f08:
	/* 0x1f08: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0c:
	/* 0x1f0c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f11:
	/* 0x1f11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f16:
	/* 0x1f16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f20:
	/* 0x1f20: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f23:
	/* 0x1f23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f25:
	/* 0x1f25: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f2a:
	/* 0x1f2a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f34:
	/* 0x1f34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f39:
	/* 0x1f39: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f3e:
	/* 0x1f3e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f41:
	/* 0x1f41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f43:
	/* 0x1f43: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f47:
	/* 0x1f47: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1f4b:
	/* 0x1f4b: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1f4f:
	/* 0x1f4f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f53:
	/* 0x1f53: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f58:
	/* 0x1f58: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f62:
	/* 0x1f62: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f67:
	/* 0x1f67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f69:
	/* 0x1f69: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f71:
	/* 0x1f71: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f76:
	/* 0x1f76: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f80:
	/* 0x1f80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f85:
	/* 0x1f85: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f88:
	/* 0x1f88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8a:
	/* 0x1f8a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f8f:
	/* 0x1f8f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f93:
	/* 0x1f93: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f98:
	/* 0x1f98: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa2:
	/* 0x1fa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa7:
	/* 0x1fa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa9:
	/* 0x1fa9: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fae:
	/* 0x1fae: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fb8:
	/* 0x1fb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fc5:
	/* 0x1fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc7:
	/* 0x1fc7: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fcb:
	/* 0x1fcb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1fcf:
	/* 0x1fcf: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fd3:
	/* 0x1fd3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fd7:
	/* 0x1fd7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1feb:
	/* 0x1feb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fed:
	/* 0x1fed: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ff5:
	/* 0x1ff5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fff:
	/* 0x1fff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2004:
	/* 0x2004: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2009:
	/* 0x2009: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_200c:
	/* 0x200c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200e:
	/* 0x200e: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2013:
	/* 0x2013: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2018:
	/* 0x2018: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_201d:
	/* 0x201d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2022:
	/* 0x2022: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2027:
	/* 0x2027: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_202a:
	/* 0x202a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202c:
	/* 0x202c: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2030:
	/* 0x2030: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2034:
	/* 0x2034: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2038:
	/* 0x2038: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_203c:
	/* 0x203c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2041:
	/* 0x2041: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2046:
	/* 0x2046: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_204b:
	/* 0x204b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2050:
	/* 0x2050: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2052:
	/* 0x2052: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2057:
	/* 0x2057: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_205b:
	/* 0x205b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2060:
	/* 0x2060: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2065:
	/* 0x2065: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_206a:
	/* 0x206a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_206f:
	/* 0x206f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2071:
	/* 0x2071: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2075:
	/* 0x2075: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2079:
	/* 0x2079: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_207e:
	/* 0x207e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2083:
	/* 0x2083: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2088:
	/* 0x2088: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_208d:
	/* 0x208d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2090:
	/* 0x2090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2092:
	/* 0x2092: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2097:
	/* 0x2097: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_209c:
	/* 0x209c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20a1:
	/* 0x20a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a6:
	/* 0x20a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ab:
	/* 0x20ab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20ae:
	/* 0x20ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b0:
	/* 0x20b0: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20b4:
	/* 0x20b4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_20b8:
	/* 0x20b8: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20bc:
	/* 0x20bc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20c0:
	/* 0x20c0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20c5:
	/* 0x20c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20ca:
	/* 0x20ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20cf:
	/* 0x20cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20d4:
	/* 0x20d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d6:
	/* 0x20d6: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20db:
	/* 0x20db: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_20df:
	/* 0x20df: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20e4:
	/* 0x20e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_20e9:
	/* 0x20e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20ee:
	/* 0x20ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20f3:
	/* 0x20f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f5:
	/* 0x20f5: cmp    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 64ULL);
x86_l_20f9:
	/* 0x20f9: jne    2160 <trace_ret_file_update_time+0x2160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2160;
	}
x86_l_20fb:
	/* 0x20fb: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2100:
	/* 0x2100: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2105:
	/* 0x2105: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_210a:
	/* 0x210a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210f:
	/* 0x210f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2112:
	/* 0x2112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2114:
	/* 0x2114: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2119:
	/* 0x2119: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_211e:
	/* 0x211e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2123:
	/* 0x2123: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2128:
	/* 0x2128: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_212d:
	/* 0x212d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2130:
	/* 0x2130: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2132:
	/* 0x2132: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2136:
	/* 0x2136: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_213a:
	/* 0x213a: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_213e:
	/* 0x213e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2142:
	/* 0x2142: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2147:
	/* 0x2147: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_214c:
	/* 0x214c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2151:
	/* 0x2151: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2156:
	/* 0x2156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2158:
	/* 0x2158: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_215c:
	/* 0x215c: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2160:
	/* 0x2160: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2164:
	/* 0x2164: lea    r12,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_216b:
	/* 0x216b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2170:
	/* 0x2170: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2175:
	/* 0x2175: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_217a:
	/* 0x217a: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_217e:
	/* 0x217e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2183:
	/* 0x2183: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2186:
	/* 0x2186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2188:
	/* 0x2188: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_218d:
	/* 0x218d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2191:
	/* 0x2191: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2196:
	/* 0x2196: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_219b:
	/* 0x219b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21a0:
	/* 0x21a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a5:
	/* 0x21a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a7:
	/* 0x21a7: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21ac:
	/* 0x21ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21b1:
	/* 0x21b1: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_21b6:
	/* 0x21b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21bb:
	/* 0x21bb: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21c0:
	/* 0x21c0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21c5:
	/* 0x21c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c7:
	/* 0x21c7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21cb:
	/* 0x21cb: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_21cf:
	/* 0x21cf: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_21d4:
	/* 0x21d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d6:
	/* 0x21d6: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21da:
	/* 0x21da: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_21de:
	/* 0x21de: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21e3:
	/* 0x21e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21e8:
	/* 0x21e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21ed:
	/* 0x21ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f2:
	/* 0x21f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f4:
	/* 0x21f4: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21f9:
	/* 0x21f9: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fd:
	/* 0x21fd: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2202:
	/* 0x2202: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2206:
	/* 0x2206: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_220b:
	/* 0x220b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2210:
	/* 0x2210: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2215:
	/* 0x2215: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_221a:
	/* 0x221a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221c:
	/* 0x221c: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2221:
	/* 0x2221: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2225:
	/* 0x2225: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2229:
	/* 0x2229: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_222e:
	/* 0x222e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2233:
	/* 0x2233: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2238:
	/* 0x2238: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_223d:
	/* 0x223d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2240:
	/* 0x2240: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2242:
	/* 0x2242: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2247:
	/* 0x2247: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_224b:
	/* 0x224b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2250:
	/* 0x2250: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2255:
	/* 0x2255: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_225a:
	/* 0x225a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_225f:
	/* 0x225f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2262:
	/* 0x2262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2264:
	/* 0x2264: test   BYTE PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_2269:
	/* 0x2269: je     2270 <trace_ret_file_update_time+0x2270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2270;
	}
x86_l_226b:
	/* 0x226b: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2270:
	/* 0x2270: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2278:
	/* 0x2278: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_227c:
	/* 0x227c: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2284:
	/* 0x2284: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2289:
	/* 0x2289: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_228e:
	/* 0x228e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2293:
	/* 0x2293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2295:
	/* 0x2295: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_229a:
	/* 0x229a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_229f:
	/* 0x229f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22a4:
	/* 0x22a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a9:
	/* 0x22a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_22ac:
	/* 0x22ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ae:
	/* 0x22ae: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22b3:
	/* 0x22b3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22b8:
	/* 0x22b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22bd:
	/* 0x22bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c2:
	/* 0x22c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c7:
	/* 0x22c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c9:
	/* 0x22c9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22ce:
	/* 0x22ce: lea    rbx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22d3:
	/* 0x22d3: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_22d8:
	/* 0x22d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22dd:
	/* 0x22dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22e0:
	/* 0x22e0: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_22e5:
	/* 0x22e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e7:
	/* 0x22e7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_22ea:
	/* 0x22ea: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_22ee:
	/* 0x22ee: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_22f3:
	/* 0x22f3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_22f8:
	/* 0x22f8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22fd:
	/* 0x22fd: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2300:
	/* 0x2300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2302:
	/* 0x2302: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_2307:
	/* 0x2307: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_230c:
	/* 0x230c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2311:
	/* 0x2311: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2316:
	/* 0x2316: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2319:
	/* 0x2319: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231b:
	/* 0x231b: mov    rax,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2323:
	/* 0x2323: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2327:
	/* 0x2327: mov    rbx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_232f:
	/* 0x232f: je     2354 <trace_ret_file_update_time+0x2354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2354;
	}
x86_l_2331:
	/* 0x2331: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2338:
	/* 0x2338: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_233d:
	/* 0x233d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2342:
	/* 0x2342: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2347:
	/* 0x2347: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_234a:
	/* 0x234a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234c:
	/* 0x234c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_234e:
	/* 0x234e: js     2354 <trace_ret_file_update_time+0x2354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2354;
	}
x86_l_2350:
	/* 0x2350: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2354:
	/* 0x2354: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_235c:
	/* 0x235c: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2361:
	/* 0x2361: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2366:
	/* 0x2366: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2369:
	/* 0x2369: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_236f:
	/* 0x236f: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2373:
	/* 0x2373: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_237a:
	/* 0x237a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_237f:
	/* 0x237f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2384:
	/* 0x2384: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2389:
	/* 0x2389: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_238c:
	/* 0x238c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_238f:
	/* 0x238f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2391:
	/* 0x2391: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2393:
	/* 0x2393: add    rsp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_239a:
	/* 0x239a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_239b:
	/* 0x239b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_239d:
	/* 0x239d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_239f:
	/* 0x239f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_23a1:
	/* 0x23a1: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_23a3:
	/* 0x23a3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_23a4:
	/* 0x23a4: jmp    3c0c <trace_ret_file_update_time+0x3c0c> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23a9:
	/* 0x23a9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ad:
	/* 0x23ad: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_23b2:
	/* 0x23b2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b7:
	/* 0x23b7: je     1a10 <trace_ret_file_update_time+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6672ULL;
	}
x86_l_23bd:
	/* 0x23bd: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23c1:
	/* 0x23c1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23c6:
	/* 0x23c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23cb:
	/* 0x23cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23d0:
	/* 0x23d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d4:
	/* 0x23d4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23d8:
	/* 0x23d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23dd:
	/* 0x23dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23df:
	/* 0x23df: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e3:
	/* 0x23e3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23e6:
	/* 0x23e6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23eb:
	/* 0x23eb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f0:
	/* 0x23f0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f4:
	/* 0x23f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f9:
	/* 0x23f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fb:
	/* 0x23fb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ff:
	/* 0x23ff: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2404:
	/* 0x2404: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2409:
	/* 0x2409: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_240e:
	/* 0x240e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2412:
	/* 0x2412: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2417:
	/* 0x2417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2419:
	/* 0x2419: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241d:
	/* 0x241d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2421:
	/* 0x2421: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2426:
	/* 0x2426: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_242b:
	/* 0x242b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2430:
	/* 0x2430: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2435:
	/* 0x2435: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_243a:
	/* 0x243a: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243f:
	/* 0x243f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2444:
	/* 0x2444: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2449:
	/* 0x2449: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_244d:
	/* 0x244d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
	return 9298ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9335ULL: goto x86_l_2477;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9361ULL: goto x86_l_2491;
	case 9365ULL: goto x86_l_2495;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9430ULL: goto x86_l_24d6;
	case 9436ULL: goto x86_l_24dc;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9475ULL: goto x86_l_2503;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9488ULL: goto x86_l_2510;
	case 9490ULL: goto x86_l_2512;
	case 9494ULL: goto x86_l_2516;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9511ULL: goto x86_l_2527;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9537ULL: goto x86_l_2541;
	case 9541ULL: goto x86_l_2545;
	case 9546ULL: goto x86_l_254a;
	case 9548ULL: goto x86_l_254c;
	case 9552ULL: goto x86_l_2550;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9569ULL: goto x86_l_2561;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9581ULL: goto x86_l_256d;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9603ULL: goto x86_l_2583;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9621ULL: goto x86_l_2595;
	case 9626ULL: goto x86_l_259a;
	case 9629ULL: goto x86_l_259d;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9698ULL: goto x86_l_25e2;
	case 9704ULL: goto x86_l_25e8;
	case 9709ULL: goto x86_l_25ed;
	case 9712ULL: goto x86_l_25f0;
	case 9718ULL: goto x86_l_25f6;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9766ULL: goto x86_l_2626;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9783ULL: goto x86_l_2637;
	case 9786ULL: goto x86_l_263a;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9795ULL: goto x86_l_2643;
	case 9798ULL: goto x86_l_2646;
	case 9803ULL: goto x86_l_264b;
	case 9809ULL: goto x86_l_2651;
	case 9814ULL: goto x86_l_2656;
	case 9817ULL: goto x86_l_2659;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9830ULL: goto x86_l_2666;
	case 9835ULL: goto x86_l_266b;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9845ULL: goto x86_l_2675;
	case 9848ULL: goto x86_l_2678;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9869ULL: goto x86_l_268d;
	case 9873ULL: goto x86_l_2691;
	case 9878ULL: goto x86_l_2696;
	case 9883ULL: goto x86_l_269b;
	case 9888ULL: goto x86_l_26a0;
	case 9892ULL: goto x86_l_26a4;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9903ULL: goto x86_l_26af;
	case 9907ULL: goto x86_l_26b3;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9924ULL: goto x86_l_26c4;
	case 9929ULL: goto x86_l_26c9;
	case 9931ULL: goto x86_l_26cb;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9961ULL: goto x86_l_26e9;
	case 9965ULL: goto x86_l_26ed;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9994ULL: goto x86_l_270a;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10008ULL: goto x86_l_2718;
	case 10013ULL: goto x86_l_271d;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10044ULL: goto x86_l_273c;
	case 10049ULL: goto x86_l_2741;
	case 10052ULL: goto x86_l_2744;
	case 10058ULL: goto x86_l_274a;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10082ULL: goto x86_l_2762;
	case 10084ULL: goto x86_l_2764;
	case 10088ULL: goto x86_l_2768;
	case 10090ULL: goto x86_l_276a;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10104ULL: goto x86_l_2778;
	case 10106ULL: goto x86_l_277a;
	case 10112ULL: goto x86_l_2780;
	case 10117ULL: goto x86_l_2785;
	case 10123ULL: goto x86_l_278b;
	case 10126ULL: goto x86_l_278e;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10144ULL: goto x86_l_27a0;
	case 10149ULL: goto x86_l_27a5;
	case 10152ULL: goto x86_l_27a8;
	case 10158ULL: goto x86_l_27ae;
	case 10163ULL: goto x86_l_27b3;
	case 10167ULL: goto x86_l_27b7;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10182ULL: goto x86_l_27c6;
	case 10187ULL: goto x86_l_27cb;
	case 10194ULL: goto x86_l_27d2;
	case 10197ULL: goto x86_l_27d5;
	case 10201ULL: goto x86_l_27d9;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10266ULL: goto x86_l_281a;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10289ULL: goto x86_l_2831;
	case 10293ULL: goto x86_l_2835;
	case 10298ULL: goto x86_l_283a;
	case 10300ULL: goto x86_l_283c;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	case 10342ULL: goto x86_l_2866;
	case 10347ULL: goto x86_l_286b;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10362ULL: goto x86_l_287a;
	case 10366ULL: goto x86_l_287e;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10389ULL: goto x86_l_2895;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10447ULL: goto x86_l_28cf;
	case 10451ULL: goto x86_l_28d3;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10479ULL: goto x86_l_28ef;
	case 10485ULL: goto x86_l_28f5;
	case 10490ULL: goto x86_l_28fa;
	case 10492ULL: goto x86_l_28fc;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10527ULL: goto x86_l_291f;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10542ULL: goto x86_l_292e;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10561ULL: goto x86_l_2941;
	case 10565ULL: goto x86_l_2945;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10576ULL: goto x86_l_2950;
	case 10580ULL: goto x86_l_2954;
	case 10583ULL: goto x86_l_2957;
	case 10588ULL: goto x86_l_295c;
	case 10593ULL: goto x86_l_2961;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10604ULL: goto x86_l_296c;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10634ULL: goto x86_l_298a;
	case 10638ULL: goto x86_l_298e;
	case 10642ULL: goto x86_l_2992;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10655ULL: goto x86_l_299f;
	case 10660ULL: goto x86_l_29a4;
	case 10662ULL: goto x86_l_29a6;
	case 10667ULL: goto x86_l_29ab;
	case 10669ULL: goto x86_l_29ad;
	case 10672ULL: goto x86_l_29b0;
	case 10678ULL: goto x86_l_29b6;
	case 10683ULL: goto x86_l_29bb;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10701ULL: goto x86_l_29cd;
	case 10703ULL: goto x86_l_29cf;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10723ULL: goto x86_l_29e3;
	case 10728ULL: goto x86_l_29e8;
	case 10731ULL: goto x86_l_29eb;
	case 10736ULL: goto x86_l_29f0;
	case 10738ULL: goto x86_l_29f2;
	case 10743ULL: goto x86_l_29f7;
	case 10748ULL: goto x86_l_29fc;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10772ULL: goto x86_l_2a14;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10798ULL: goto x86_l_2a2e;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10822ULL: goto x86_l_2a46;
	case 10824ULL: goto x86_l_2a48;
	case 10828ULL: goto x86_l_2a4c;
	case 10830ULL: goto x86_l_2a4e;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10843ULL: goto x86_l_2a5b;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10867ULL: goto x86_l_2a73;
	case 10872ULL: goto x86_l_2a78;
	case 10874ULL: goto x86_l_2a7a;
	case 10877ULL: goto x86_l_2a7d;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10887ULL: goto x86_l_2a87;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10922ULL: goto x86_l_2aaa;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2452:
	/* 0x2452: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2457:
	/* 0x2457: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_245c:
	/* 0x245c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2461:
	/* 0x2461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2463:
	/* 0x2463: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2468:
	/* 0x2468: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_246b:
	/* 0x246b: je     24d3 <trace_ret_file_update_time+0x24d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d3;
	}
x86_l_246d:
	/* 0x246d: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2472:
	/* 0x2472: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2475:
	/* 0x2475: je     24d3 <trace_ret_file_update_time+0x24d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d3;
	}
x86_l_2477:
	/* 0x2477: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_247b:
	/* 0x247b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2480:
	/* 0x2480: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_248a:
	/* 0x248a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_248f:
	/* 0x248f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2491:
	/* 0x2491: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2495:
	/* 0x2495: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2497:
	/* 0x2497: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_249d:
	/* 0x249d: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a2:
	/* 0x24a2: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_24a5:
	/* 0x24a5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24a7:
	/* 0x24a7: jae    2556 <trace_ret_file_update_time+0x2556> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2556;
	}
x86_l_24ad:
	/* 0x24ad: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b2:
	/* 0x24b2: dec    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_24b5:
	/* 0x24b5: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_24b8:
	/* 0x24b8: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_24bd:
	/* 0x24bd: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24c2:
	/* 0x24c2: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_24c7:
	/* 0x24c7: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_24ce:
	/* 0x24ce: jmp    1a62 <trace_ret_file_update_time+0x1a62> */
	return 6754ULL;
x86_l_24d3:
	/* 0x24d3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24d6:
	/* 0x24d6: jne    1a0b <trace_ret_file_update_time+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6667ULL;
	}
x86_l_24dc:
	/* 0x24dc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e0:
	/* 0x24e0: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_24e5:
	/* 0x24e5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ea:
	/* 0x24ea: je     1a10 <trace_ret_file_update_time+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6672ULL;
	}
x86_l_24f0:
	/* 0x24f0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24f4:
	/* 0x24f4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24f9:
	/* 0x24f9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24fe:
	/* 0x24fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2503:
	/* 0x2503: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2507:
	/* 0x2507: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_250b:
	/* 0x250b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2510:
	/* 0x2510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2512:
	/* 0x2512: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2516:
	/* 0x2516: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2519:
	/* 0x2519: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_251e:
	/* 0x251e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2523:
	/* 0x2523: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2527:
	/* 0x2527: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_252c:
	/* 0x252c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_252e:
	/* 0x252e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2532:
	/* 0x2532: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2537:
	/* 0x2537: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_253c:
	/* 0x253c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2541:
	/* 0x2541: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2545:
	/* 0x2545: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_254a:
	/* 0x254a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254c:
	/* 0x254c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2550:
	/* 0x2550: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2554:
	/* 0x2554: jmp    259d <trace_ret_file_update_time+0x259d> */
	goto x86_l_259d;
x86_l_2556:
	/* 0x2556: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_255b:
	/* 0x255b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2561:
	/* 0x2561: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2564:
	/* 0x2564: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2566:
	/* 0x2566: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_256b:
	/* 0x256b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256d:
	/* 0x256d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2570:
	/* 0x2570: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2575:
	/* 0x2575: jl     1a10 <trace_ret_file_update_time+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6672ULL;
	}
x86_l_257b:
	/* 0x257b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2580:
	/* 0x2580: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2583:
	/* 0x2583: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2589:
	/* 0x2589: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_258e:
	/* 0x258e: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2590:
	/* 0x2590: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2595:
	/* 0x2595: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_259a:
	/* 0x259a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_259d:
	/* 0x259d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25a2:
	/* 0x25a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25a7:
	/* 0x25a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25ac:
	/* 0x25ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25b1:
	/* 0x25b1: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_25b4:
	/* 0x25b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b6:
	/* 0x25b6: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25bb:
	/* 0x25bb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c0:
	/* 0x25c0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25c4:
	/* 0x25c4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25c9:
	/* 0x25c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25ce:
	/* 0x25ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25d3:
	/* 0x25d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d8:
	/* 0x25d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25da:
	/* 0x25da: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25df:
	/* 0x25df: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25e2:
	/* 0x25e2: je     2675 <trace_ret_file_update_time+0x2675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2675;
	}
x86_l_25e8:
	/* 0x25e8: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25ed:
	/* 0x25ed: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25f0:
	/* 0x25f0: je     2675 <trace_ret_file_update_time+0x2675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2675;
	}
x86_l_25f6:
	/* 0x25f6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25fa:
	/* 0x25fa: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25ff:
	/* 0x25ff: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2604:
	/* 0x2604: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2609:
	/* 0x2609: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_260e:
	/* 0x260e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2610:
	/* 0x2610: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2614:
	/* 0x2614: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2616:
	/* 0x2616: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_261c:
	/* 0x261c: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2621:
	/* 0x2621: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_2624:
	/* 0x2624: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2626:
	/* 0x2626: jb     24ad <trace_ret_file_update_time+0x24ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24ad;
	}
x86_l_262c:
	/* 0x262c: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2631:
	/* 0x2631: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2637:
	/* 0x2637: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_263a:
	/* 0x263a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_263c:
	/* 0x263c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2641:
	/* 0x2641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2643:
	/* 0x2643: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2646:
	/* 0x2646: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_264b:
	/* 0x264b: jl     1a10 <trace_ret_file_update_time+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6672ULL;
	}
x86_l_2651:
	/* 0x2651: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2656:
	/* 0x2656: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2659:
	/* 0x2659: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_265f:
	/* 0x265f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2664:
	/* 0x2664: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2666:
	/* 0x2666: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266b:
	/* 0x266b: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2670:
	/* 0x2670: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2673:
	/* 0x2673: jmp    26f1 <trace_ret_file_update_time+0x26f1> */
	goto x86_l_26f1;
x86_l_2675:
	/* 0x2675: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2678:
	/* 0x2678: jne    1a0b <trace_ret_file_update_time+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6667ULL;
	}
x86_l_267e:
	/* 0x267e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2682:
	/* 0x2682: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2687:
	/* 0x2687: je     1a0b <trace_ret_file_update_time+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6667ULL;
	}
x86_l_268d:
	/* 0x268d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2691:
	/* 0x2691: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2696:
	/* 0x2696: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_269b:
	/* 0x269b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26a0:
	/* 0x26a0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a4:
	/* 0x26a4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26a8:
	/* 0x26a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ad:
	/* 0x26ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26af:
	/* 0x26af: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b3:
	/* 0x26b3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26b6:
	/* 0x26b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26bb:
	/* 0x26bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26c0:
	/* 0x26c0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c4:
	/* 0x26c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c9:
	/* 0x26c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cb:
	/* 0x26cb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26cf:
	/* 0x26cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d4:
	/* 0x26d4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26d9:
	/* 0x26d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26de:
	/* 0x26de: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e2:
	/* 0x26e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e7:
	/* 0x26e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e9:
	/* 0x26e9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ed:
	/* 0x26ed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26f1:
	/* 0x26f1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26f6:
	/* 0x26f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26fb:
	/* 0x26fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2700:
	/* 0x2700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2705:
	/* 0x2705: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_2708:
	/* 0x2708: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270a:
	/* 0x270a: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_270f:
	/* 0x270f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2714:
	/* 0x2714: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2718:
	/* 0x2718: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_271d:
	/* 0x271d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2722:
	/* 0x2722: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2727:
	/* 0x2727: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_272c:
	/* 0x272c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272e:
	/* 0x272e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2733:
	/* 0x2733: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2736:
	/* 0x2736: je     2802 <trace_ret_file_update_time+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2802;
	}
x86_l_273c:
	/* 0x273c: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2741:
	/* 0x2741: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2744:
	/* 0x2744: je     2802 <trace_ret_file_update_time+0x2802> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2802;
	}
x86_l_274a:
	/* 0x274a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_274e:
	/* 0x274e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2753:
	/* 0x2753: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2758:
	/* 0x2758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_275d:
	/* 0x275d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2762:
	/* 0x2762: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2764:
	/* 0x2764: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2768:
	/* 0x2768: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_276a:
	/* 0x276a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2770:
	/* 0x2770: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2775:
	/* 0x2775: mov    edi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R8, X86_WIDTH_32);
x86_l_2778:
	/* 0x2778: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_277a:
	/* 0x277a: jb     24ad <trace_ret_file_update_time+0x24ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24ad;
	}
x86_l_2780:
	/* 0x2780: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2785:
	/* 0x2785: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_278b:
	/* 0x278b: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_278e:
	/* 0x278e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2790:
	/* 0x2790: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2795:
	/* 0x2795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2797:
	/* 0x2797: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_279a:
	/* 0x279a: jl     1a0b <trace_ret_file_update_time+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6667ULL;
	}
x86_l_27a0:
	/* 0x27a0: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a5:
	/* 0x27a5: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_27a8:
	/* 0x27a8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_27ae:
	/* 0x27ae: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27b3:
	/* 0x27b3: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_27b7:
	/* 0x27b7: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27b9:
	/* 0x27b9: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27be:
	/* 0x27be: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27c3:
	/* 0x27c3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_27c6:
	/* 0x27c6: jmp    287e <trace_ret_file_update_time+0x287e> */
	goto x86_l_287e;
x86_l_27cb:
	/* 0x27cb: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_27d2:
	/* 0x27d2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_27d5:
	/* 0x27d5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27d9:
	/* 0x27d9: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_27de:
	/* 0x27de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e3:
	/* 0x27e3: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_27e8:
	/* 0x27e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ea:
	/* 0x27ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27ed:
	/* 0x27ed: jne    2391 <trace_ret_file_update_time+0x2391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9105ULL;
	}
x86_l_27f3:
	/* 0x27f3: movzx  eax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_27f8:
	/* 0x27f8: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_27fd:
	/* 0x27fd: jmp    d14 <trace_ret_file_update_time+0xd14> */
	return 3348ULL;
x86_l_2802:
	/* 0x2802: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2805:
	/* 0x2805: jne    1a0b <trace_ret_file_update_time+0x1a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6667ULL;
	}
x86_l_280b:
	/* 0x280b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280f:
	/* 0x280f: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2814:
	/* 0x2814: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_281a:
	/* 0x281a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_281e:
	/* 0x281e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2823:
	/* 0x2823: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2828:
	/* 0x2828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_282d:
	/* 0x282d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2831:
	/* 0x2831: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2835:
	/* 0x2835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_283a:
	/* 0x283a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283c:
	/* 0x283c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2840:
	/* 0x2840: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2843:
	/* 0x2843: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2848:
	/* 0x2848: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_284d:
	/* 0x284d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2851:
	/* 0x2851: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2856:
	/* 0x2856: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2858:
	/* 0x2858: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_285c:
	/* 0x285c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2861:
	/* 0x2861: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2866:
	/* 0x2866: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_286b:
	/* 0x286b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286f:
	/* 0x286f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2874:
	/* 0x2874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2876:
	/* 0x2876: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_287a:
	/* 0x287a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_287e:
	/* 0x287e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2883:
	/* 0x2883: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2888:
	/* 0x2888: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_288d:
	/* 0x288d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2892:
	/* 0x2892: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2895:
	/* 0x2895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2897:
	/* 0x2897: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_289c:
	/* 0x289c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28a1:
	/* 0x28a1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28a5:
	/* 0x28a5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28aa:
	/* 0x28aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28af:
	/* 0x28af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28b4:
	/* 0x28b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b9:
	/* 0x28b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bb:
	/* 0x28bb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c0:
	/* 0x28c0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28c3:
	/* 0x28c3: je     2916 <trace_ret_file_update_time+0x2916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2916;
	}
x86_l_28c5:
	/* 0x28c5: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28ca:
	/* 0x28ca: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28cd:
	/* 0x28cd: je     2916 <trace_ret_file_update_time+0x2916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2916;
	}
x86_l_28cf:
	/* 0x28cf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28d3:
	/* 0x28d3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28d8:
	/* 0x28d8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28dd:
	/* 0x28dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28e2:
	/* 0x28e2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28e7:
	/* 0x28e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28e9:
	/* 0x28e9: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_28ed:
	/* 0x28ed: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_28ef:
	/* 0x28ef: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28f5:
	/* 0x28f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fa:
	/* 0x28fa: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28fc:
	/* 0x28fc: jae    2994 <trace_ret_file_update_time+0x2994> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2994;
	}
x86_l_2902:
	/* 0x2902: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2907:
	/* 0x2907: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290c:
	/* 0x290c: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2911:
	/* 0x2911: jmp    24b2 <trace_ret_file_update_time+0x24b2> */
	goto x86_l_24b2;
x86_l_2916:
	/* 0x2916: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2919:
	/* 0x2919: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_291f:
	/* 0x291f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2923:
	/* 0x2923: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2928:
	/* 0x2928: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_292e:
	/* 0x292e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2932:
	/* 0x2932: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2937:
	/* 0x2937: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_293c:
	/* 0x293c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2941:
	/* 0x2941: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2945:
	/* 0x2945: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2949:
	/* 0x2949: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_294e:
	/* 0x294e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2950:
	/* 0x2950: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2954:
	/* 0x2954: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2957:
	/* 0x2957: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_295c:
	/* 0x295c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2961:
	/* 0x2961: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2965:
	/* 0x2965: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_296a:
	/* 0x296a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296c:
	/* 0x296c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2970:
	/* 0x2970: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2975:
	/* 0x2975: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_297a:
	/* 0x297a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_297f:
	/* 0x297f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2983:
	/* 0x2983: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2988:
	/* 0x2988: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_298a:
	/* 0x298a: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298e:
	/* 0x298e: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2992:
	/* 0x2992: jmp    29d9 <trace_ret_file_update_time+0x29d9> */
	goto x86_l_29d9;
x86_l_2994:
	/* 0x2994: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2999:
	/* 0x2999: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_299f:
	/* 0x299f: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_29a4:
	/* 0x29a4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_29a6:
	/* 0x29a6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_29ab:
	/* 0x29ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ad:
	/* 0x29ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29b0:
	/* 0x29b0: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_29b6:
	/* 0x29b6: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29bb:
	/* 0x29bb: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_29be:
	/* 0x29be: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_29c4:
	/* 0x29c4: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29c9:
	/* 0x29c9: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_29cd:
	/* 0x29cd: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29cf:
	/* 0x29cf: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d4:
	/* 0x29d4: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29d9:
	/* 0x29d9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29de:
	/* 0x29de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29e3:
	/* 0x29e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e8:
	/* 0x29e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_29eb:
	/* 0x29eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f0:
	/* 0x29f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f2:
	/* 0x29f2: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29f7:
	/* 0x29f7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29fc:
	/* 0x29fc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a00:
	/* 0x2a00: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a05:
	/* 0x2a05: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a0a:
	/* 0x2a0a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a14:
	/* 0x2a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a16:
	/* 0x2a16: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a1b:
	/* 0x2a1b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a1e:
	/* 0x2a1e: je     2aa7 <trace_ret_file_update_time+0x2aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa7;
	}
x86_l_2a24:
	/* 0x2a24: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a29:
	/* 0x2a29: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a2c:
	/* 0x2a2c: je     2aa7 <trace_ret_file_update_time+0x2aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa7;
	}
x86_l_2a2e:
	/* 0x2a2e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a32:
	/* 0x2a32: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a37:
	/* 0x2a37: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a3c:
	/* 0x2a3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a41:
	/* 0x2a41: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a46:
	/* 0x2a46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a48:
	/* 0x2a48: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2a4c:
	/* 0x2a4c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a4e:
	/* 0x2a4e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a54:
	/* 0x2a54: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a59:
	/* 0x2a59: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a5b:
	/* 0x2a5b: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2902;
	}
x86_l_2a61:
	/* 0x2a61: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a66:
	/* 0x2a66: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a6c:
	/* 0x2a6c: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2a71:
	/* 0x2a71: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2a73:
	/* 0x2a73: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a78:
	/* 0x2a78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7a:
	/* 0x2a7a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a7d:
	/* 0x2a7d: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_2a7f:
	/* 0x2a7f: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a84:
	/* 0x2a84: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a87:
	/* 0x2a87: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a92:
	/* 0x2a92: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a96:
	/* 0x2a96: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a98:
	/* 0x2a98: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aa2:
	/* 0x2aa2: jmp    2b25 <trace_ret_file_update_time+0x2b25> */
	return 11045ULL;
x86_l_2aa7:
	/* 0x2aa7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2aaa:
	/* 0x2aaa: je     2ab6 <trace_ret_file_update_time+0x2ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10934ULL;
	}
	return 10924ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10938ULL: goto x86_l_2aba;
	case 10943ULL: goto x86_l_2abf;
	case 10945ULL: goto x86_l_2ac1;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10968ULL: goto x86_l_2ad8;
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10979ULL: goto x86_l_2ae3;
	case 10983ULL: goto x86_l_2ae7;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10996ULL: goto x86_l_2af4;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11007ULL: goto x86_l_2aff;
	case 11011ULL: goto x86_l_2b03;
	case 11016ULL: goto x86_l_2b08;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11030ULL: goto x86_l_2b16;
	case 11035ULL: goto x86_l_2b1b;
	case 11037ULL: goto x86_l_2b1d;
	case 11041ULL: goto x86_l_2b21;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11055ULL: goto x86_l_2b2f;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11120ULL: goto x86_l_2b70;
	case 11125ULL: goto x86_l_2b75;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11156ULL: goto x86_l_2b94;
	case 11160ULL: goto x86_l_2b98;
	case 11162ULL: goto x86_l_2b9a;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11186ULL: goto x86_l_2bb2;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11223ULL: goto x86_l_2bd7;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11250ULL: goto x86_l_2bf2;
	case 11252ULL: goto x86_l_2bf4;
	case 11255ULL: goto x86_l_2bf7;
	case 11261ULL: goto x86_l_2bfd;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11276ULL: goto x86_l_2c0c;
	case 11280ULL: goto x86_l_2c10;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11299ULL: goto x86_l_2c23;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11338ULL: goto x86_l_2c4a;
	case 11342ULL: goto x86_l_2c4e;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11361ULL: goto x86_l_2c61;
	case 11366ULL: goto x86_l_2c66;
	case 11368ULL: goto x86_l_2c68;
	case 11372ULL: goto x86_l_2c6c;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11401ULL: goto x86_l_2c89;
	case 11406ULL: goto x86_l_2c8e;
	case 11411ULL: goto x86_l_2c93;
	case 11415ULL: goto x86_l_2c97;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11506ULL: goto x86_l_2cf2;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11537ULL: goto x86_l_2d11;
	case 11540ULL: goto x86_l_2d14;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11554ULL: goto x86_l_2d22;
	case 11560ULL: goto x86_l_2d28;
	case 11565ULL: goto x86_l_2d2d;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11583ULL: goto x86_l_2d3f;
	case 11586ULL: goto x86_l_2d42;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11607ULL: goto x86_l_2d57;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11630ULL: goto x86_l_2d6e;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11641ULL: goto x86_l_2d79;
	case 11645ULL: goto x86_l_2d7d;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11662ULL: goto x86_l_2d8e;
	case 11667ULL: goto x86_l_2d93;
	case 11669ULL: goto x86_l_2d95;
	case 11673ULL: goto x86_l_2d99;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11703ULL: goto x86_l_2db7;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11722ULL: goto x86_l_2dca;
	case 11725ULL: goto x86_l_2dcd;
	case 11730ULL: goto x86_l_2dd2;
	case 11732ULL: goto x86_l_2dd4;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11776ULL: goto x86_l_2e00;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11790ULL: goto x86_l_2e0e;
	case 11792ULL: goto x86_l_2e10;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11822ULL: goto x86_l_2e2e;
	case 11824ULL: goto x86_l_2e30;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11837ULL: goto x86_l_2e3d;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11854ULL: goto x86_l_2e4e;
	case 11859ULL: goto x86_l_2e53;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11868ULL: goto x86_l_2e5c;
	case 11871ULL: goto x86_l_2e5f;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11885ULL: goto x86_l_2e6d;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11923ULL: goto x86_l_2e93;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11938ULL: goto x86_l_2ea2;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11961ULL: goto x86_l_2eb9;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11972ULL: goto x86_l_2ec4;
	case 11976ULL: goto x86_l_2ec8;
	case 11979ULL: goto x86_l_2ecb;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11993ULL: goto x86_l_2ed9;
	case 11998ULL: goto x86_l_2ede;
	case 12000ULL: goto x86_l_2ee0;
	case 12004ULL: goto x86_l_2ee4;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12023ULL: goto x86_l_2ef7;
	case 12028ULL: goto x86_l_2efc;
	case 12030ULL: goto x86_l_2efe;
	case 12034ULL: goto x86_l_2f02;
	case 12038ULL: goto x86_l_2f06;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12056ULL: goto x86_l_2f18;
	case 12061ULL: goto x86_l_2f1d;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12077ULL: goto x86_l_2f2d;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12092ULL: goto x86_l_2f3c;
	case 12097ULL: goto x86_l_2f41;
	case 12099ULL: goto x86_l_2f43;
	case 12104ULL: goto x86_l_2f48;
	case 12107ULL: goto x86_l_2f4b;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12121ULL: goto x86_l_2f59;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12153ULL: goto x86_l_2f79;
	case 12155ULL: goto x86_l_2f7b;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12168ULL: goto x86_l_2f88;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12202ULL: goto x86_l_2faa;
	case 12208ULL: goto x86_l_2fb0;
	case 12213ULL: goto x86_l_2fb5;
	case 12216ULL: goto x86_l_2fb8;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12231ULL: goto x86_l_2fc7;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12245ULL: goto x86_l_2fd5;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12269ULL: goto x86_l_2fed;
	case 12273ULL: goto x86_l_2ff1;
	case 12278ULL: goto x86_l_2ff6;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12292ULL: goto x86_l_3004;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12303ULL: goto x86_l_300f;
	case 12307ULL: goto x86_l_3013;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12324ULL: goto x86_l_3024;
	case 12329ULL: goto x86_l_3029;
	case 12331ULL: goto x86_l_302b;
	case 12335ULL: goto x86_l_302f;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12361ULL: goto x86_l_3049;
	case 12365ULL: goto x86_l_304d;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12384ULL: goto x86_l_3060;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12399ULL: goto x86_l_306f;
	case 12404ULL: goto x86_l_3074;
	case 12408ULL: goto x86_l_3078;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12438ULL: goto x86_l_3096;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12452ULL: goto x86_l_30a4;
	case 12454ULL: goto x86_l_30a6;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12484ULL: goto x86_l_30c4;
	case 12486ULL: goto x86_l_30c6;
	case 12492ULL: goto x86_l_30cc;
	case 12497ULL: goto x86_l_30d1;
	case 12499ULL: goto x86_l_30d3;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12533ULL: goto x86_l_30f5;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12547ULL: goto x86_l_3103;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2aac:
	/* 0x2aac: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab1:
	/* 0x2ab1: jmp    1a0b <trace_ret_file_update_time+0x1a0b> */
	return 6667ULL;
x86_l_2ab6:
	/* 0x2ab6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aba:
	/* 0x2aba: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2abf:
	/* 0x2abf: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aac;
	}
x86_l_2ac1:
	/* 0x2ac1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ac5:
	/* 0x2ac5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aca:
	/* 0x2aca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2acf:
	/* 0x2acf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ad4:
	/* 0x2ad4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad8:
	/* 0x2ad8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2adc:
	/* 0x2adc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae1:
	/* 0x2ae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae3:
	/* 0x2ae3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aea:
	/* 0x2aea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2aef:
	/* 0x2aef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af4:
	/* 0x2af4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af8:
	/* 0x2af8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afd:
	/* 0x2afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aff:
	/* 0x2aff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b03:
	/* 0x2b03: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b08:
	/* 0x2b08: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b0d:
	/* 0x2b0d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b12:
	/* 0x2b12: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b16:
	/* 0x2b16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b1b:
	/* 0x2b1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1d:
	/* 0x2b1d: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b21:
	/* 0x2b21: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b25:
	/* 0x2b25: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b2a:
	/* 0x2b2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b2f:
	/* 0x2b2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b34:
	/* 0x2b34: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2b37:
	/* 0x2b37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b3c:
	/* 0x2b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3e:
	/* 0x2b3e: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b43:
	/* 0x2b43: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b48:
	/* 0x2b48: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b4c:
	/* 0x2b4c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b51:
	/* 0x2b51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b56:
	/* 0x2b56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b5b:
	/* 0x2b5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b60:
	/* 0x2b60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b62:
	/* 0x2b62: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b67:
	/* 0x2b67: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b6a:
	/* 0x2b6a: je     2bf4 <trace_ret_file_update_time+0x2bf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf4;
	}
x86_l_2b70:
	/* 0x2b70: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b75:
	/* 0x2b75: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b78:
	/* 0x2b78: je     2bf4 <trace_ret_file_update_time+0x2bf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf4;
	}
x86_l_2b7a:
	/* 0x2b7a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b7e:
	/* 0x2b7e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b83:
	/* 0x2b83: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b88:
	/* 0x2b88: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b8d:
	/* 0x2b8d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b92:
	/* 0x2b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b94:
	/* 0x2b94: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2b98:
	/* 0x2b98: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b9a:
	/* 0x2b9a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba5:
	/* 0x2ba5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ba7:
	/* 0x2ba7: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_2bad:
	/* 0x2bad: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bb2:
	/* 0x2bb2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bb8:
	/* 0x2bb8: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2bbf:
	/* 0x2bbf: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2bc4:
	/* 0x2bc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc6:
	/* 0x2bc6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bc9:
	/* 0x2bc9: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2aac;
	}
x86_l_2bcf:
	/* 0x2bcf: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd4:
	/* 0x2bd4: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2bd7:
	/* 0x2bd7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2bdd:
	/* 0x2bdd: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2be2:
	/* 0x2be2: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2be6:
	/* 0x2be6: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2be8:
	/* 0x2be8: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bed:
	/* 0x2bed: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bf2:
	/* 0x2bf2: jmp    2c70 <trace_ret_file_update_time+0x2c70> */
	goto x86_l_2c70;
x86_l_2bf4:
	/* 0x2bf4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2bf7:
	/* 0x2bf7: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aac;
	}
x86_l_2bfd:
	/* 0x2bfd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c01:
	/* 0x2c01: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2c06:
	/* 0x2c06: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aac;
	}
x86_l_2c0c:
	/* 0x2c0c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c10:
	/* 0x2c10: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c15:
	/* 0x2c15: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c23:
	/* 0x2c23: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c27:
	/* 0x2c27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c2c:
	/* 0x2c2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2e:
	/* 0x2c2e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c32:
	/* 0x2c32: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c35:
	/* 0x2c35: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c43:
	/* 0x2c43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c48:
	/* 0x2c48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4a:
	/* 0x2c4a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c4e:
	/* 0x2c4e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c53:
	/* 0x2c53: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c58:
	/* 0x2c58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c61:
	/* 0x2c61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c66:
	/* 0x2c66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c68:
	/* 0x2c68: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6c:
	/* 0x2c6c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c70:
	/* 0x2c70: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c75:
	/* 0x2c75: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c7f:
	/* 0x2c7f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c82:
	/* 0x2c82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c87:
	/* 0x2c87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c89:
	/* 0x2c89: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c8e:
	/* 0x2c8e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c93:
	/* 0x2c93: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c97:
	/* 0x2c97: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ca1:
	/* 0x2ca1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ca6:
	/* 0x2ca6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cab:
	/* 0x2cab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cad:
	/* 0x2cad: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cb2:
	/* 0x2cb2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cb5:
	/* 0x2cb5: je     2d3f <trace_ret_file_update_time+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d3f;
	}
x86_l_2cbb:
	/* 0x2cbb: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cc0:
	/* 0x2cc0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cc3:
	/* 0x2cc3: je     2d3f <trace_ret_file_update_time+0x2d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d3f;
	}
x86_l_2cc5:
	/* 0x2cc5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cc9:
	/* 0x2cc9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cce:
	/* 0x2cce: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2cdd:
	/* 0x2cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdf:
	/* 0x2cdf: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2ce3:
	/* 0x2ce3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ce5:
	/* 0x2ce5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ceb:
	/* 0x2ceb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf0:
	/* 0x2cf0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cf2:
	/* 0x2cf2: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_2cf8:
	/* 0x2cf8: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cfd:
	/* 0x2cfd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d03:
	/* 0x2d03: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2d08:
	/* 0x2d08: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2d0a:
	/* 0x2d0a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d0f:
	/* 0x2d0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d11:
	/* 0x2d11: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d14:
	/* 0x2d14: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2aac;
	}
x86_l_2d1a:
	/* 0x2d1a: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1f:
	/* 0x2d1f: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d22:
	/* 0x2d22: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d28:
	/* 0x2d28: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d31:
	/* 0x2d31: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d33:
	/* 0x2d33: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d38:
	/* 0x2d38: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d3d:
	/* 0x2d3d: jmp    2dbb <trace_ret_file_update_time+0x2dbb> */
	goto x86_l_2dbb;
x86_l_2d3f:
	/* 0x2d3f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d42:
	/* 0x2d42: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aac;
	}
x86_l_2d48:
	/* 0x2d48: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d4c:
	/* 0x2d4c: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2d51:
	/* 0x2d51: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aac;
	}
x86_l_2d57:
	/* 0x2d57: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d5b:
	/* 0x2d5b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d60:
	/* 0x2d60: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d65:
	/* 0x2d65: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d6a:
	/* 0x2d6a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6e:
	/* 0x2d6e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d72:
	/* 0x2d72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d77:
	/* 0x2d77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d79:
	/* 0x2d79: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d7d:
	/* 0x2d7d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d80:
	/* 0x2d80: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d85:
	/* 0x2d85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8e:
	/* 0x2d8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d93:
	/* 0x2d93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d95:
	/* 0x2d95: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d99:
	/* 0x2d99: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2da3:
	/* 0x2da3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2da8:
	/* 0x2da8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dac:
	/* 0x2dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db1:
	/* 0x2db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db3:
	/* 0x2db3: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2db7:
	/* 0x2db7: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dbb:
	/* 0x2dbb: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dca:
	/* 0x2dca: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2dcd:
	/* 0x2dcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd2:
	/* 0x2dd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd4:
	/* 0x2dd4: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dde:
	/* 0x2dde: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2de2:
	/* 0x2de2: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2de7:
	/* 0x2de7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dec:
	/* 0x2dec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2df1:
	/* 0x2df1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df6:
	/* 0x2df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df8:
	/* 0x2df8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dfd:
	/* 0x2dfd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e00:
	/* 0x2e00: je     2e8a <trace_ret_file_update_time+0x2e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8a;
	}
x86_l_2e06:
	/* 0x2e06: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e0b:
	/* 0x2e0b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e0e:
	/* 0x2e0e: je     2e8a <trace_ret_file_update_time+0x2e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8a;
	}
x86_l_2e10:
	/* 0x2e10: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e14:
	/* 0x2e14: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e19:
	/* 0x2e19: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2e1e:
	/* 0x2e1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e23:
	/* 0x2e23: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e28:
	/* 0x2e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2a:
	/* 0x2e2a: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2e2e:
	/* 0x2e2e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e30:
	/* 0x2e30: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e36:
	/* 0x2e36: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3b:
	/* 0x2e3b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e3d:
	/* 0x2e3d: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_2e43:
	/* 0x2e43: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e48:
	/* 0x2e48: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e4e:
	/* 0x2e4e: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2e53:
	/* 0x2e53: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2e55:
	/* 0x2e55: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2e5a:
	/* 0x2e5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5c:
	/* 0x2e5c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e5f:
	/* 0x2e5f: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2aac;
	}
x86_l_2e65:
	/* 0x2e65: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6a:
	/* 0x2e6a: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e6d:
	/* 0x2e6d: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e73:
	/* 0x2e73: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e78:
	/* 0x2e78: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e7c:
	/* 0x2e7c: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e7e:
	/* 0x2e7e: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e83:
	/* 0x2e83: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e88:
	/* 0x2e88: jmp    2f06 <trace_ret_file_update_time+0x2f06> */
	goto x86_l_2f06;
x86_l_2e8a:
	/* 0x2e8a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e8d:
	/* 0x2e8d: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aac;
	}
x86_l_2e93:
	/* 0x2e93: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e97:
	/* 0x2e97: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2e9c:
	/* 0x2e9c: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aac;
	}
x86_l_2ea2:
	/* 0x2ea2: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ea6:
	/* 0x2ea6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eab:
	/* 0x2eab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb5:
	/* 0x2eb5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eb9:
	/* 0x2eb9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec2:
	/* 0x2ec2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec4:
	/* 0x2ec4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ecb:
	/* 0x2ecb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed9:
	/* 0x2ed9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ede:
	/* 0x2ede: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee0:
	/* 0x2ee0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee4:
	/* 0x2ee4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eee:
	/* 0x2eee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ef3:
	/* 0x2ef3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef7:
	/* 0x2ef7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2efc:
	/* 0x2efc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2efe:
	/* 0x2efe: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f02:
	/* 0x2f02: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f06:
	/* 0x2f06: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f10:
	/* 0x2f10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f15:
	/* 0x2f15: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f18:
	/* 0x2f18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1d:
	/* 0x2f1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1f:
	/* 0x2f1f: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f24:
	/* 0x2f24: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f29:
	/* 0x2f29: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f2d:
	/* 0x2f2d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f32:
	/* 0x2f32: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f37:
	/* 0x2f37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f3c:
	/* 0x2f3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f41:
	/* 0x2f41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f43:
	/* 0x2f43: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f48:
	/* 0x2f48: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f4b:
	/* 0x2f4b: je     2fd5 <trace_ret_file_update_time+0x2fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd5;
	}
x86_l_2f51:
	/* 0x2f51: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f56:
	/* 0x2f56: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f59:
	/* 0x2f59: je     2fd5 <trace_ret_file_update_time+0x2fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd5;
	}
x86_l_2f5b:
	/* 0x2f5b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f5f:
	/* 0x2f5f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f64:
	/* 0x2f64: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2f69:
	/* 0x2f69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f73:
	/* 0x2f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f75:
	/* 0x2f75: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_2f79:
	/* 0x2f79: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f7b:
	/* 0x2f7b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f81:
	/* 0x2f81: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f86:
	/* 0x2f86: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f88:
	/* 0x2f88: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_2f8e:
	/* 0x2f8e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f93:
	/* 0x2f93: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f99:
	/* 0x2f99: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2f9e:
	/* 0x2f9e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2fa0:
	/* 0x2fa0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2fa5:
	/* 0x2fa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa7:
	/* 0x2fa7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2faa:
	/* 0x2faa: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2aac;
	}
x86_l_2fb0:
	/* 0x2fb0: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb5:
	/* 0x2fb5: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2fb8:
	/* 0x2fb8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2fbe:
	/* 0x2fbe: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fc3:
	/* 0x2fc3: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2fc7:
	/* 0x2fc7: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fc9:
	/* 0x2fc9: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fce:
	/* 0x2fce: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fd3:
	/* 0x2fd3: jmp    3051 <trace_ret_file_update_time+0x3051> */
	goto x86_l_3051;
x86_l_2fd5:
	/* 0x2fd5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2fd8:
	/* 0x2fd8: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2aac;
	}
x86_l_2fde:
	/* 0x2fde: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe2:
	/* 0x2fe2: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2fe7:
	/* 0x2fe7: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aac;
	}
x86_l_2fed:
	/* 0x2fed: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ff1:
	/* 0x2ff1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff6:
	/* 0x2ff6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ffb:
	/* 0x2ffb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3000:
	/* 0x3000: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3004:
	/* 0x3004: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3008:
	/* 0x3008: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_300d:
	/* 0x300d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300f:
	/* 0x300f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3013:
	/* 0x3013: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3016:
	/* 0x3016: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_301b:
	/* 0x301b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3020:
	/* 0x3020: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3024:
	/* 0x3024: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3029:
	/* 0x3029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302b:
	/* 0x302b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_302f:
	/* 0x302f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3034:
	/* 0x3034: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3039:
	/* 0x3039: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_303e:
	/* 0x303e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3042:
	/* 0x3042: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3047:
	/* 0x3047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3049:
	/* 0x3049: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304d:
	/* 0x304d: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3051:
	/* 0x3051: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3056:
	/* 0x3056: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_305b:
	/* 0x305b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3060:
	/* 0x3060: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3063:
	/* 0x3063: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3068:
	/* 0x3068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306a:
	/* 0x306a: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_306f:
	/* 0x306f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3074:
	/* 0x3074: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3078:
	/* 0x3078: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_307d:
	/* 0x307d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3082:
	/* 0x3082: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3087:
	/* 0x3087: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_308c:
	/* 0x308c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_308e:
	/* 0x308e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3093:
	/* 0x3093: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3096:
	/* 0x3096: je     3120 <trace_ret_file_update_time+0x3120> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12576ULL;
	}
x86_l_309c:
	/* 0x309c: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30a1:
	/* 0x30a1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30a4:
	/* 0x30a4: je     3120 <trace_ret_file_update_time+0x3120> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12576ULL;
	}
x86_l_30a6:
	/* 0x30a6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30aa:
	/* 0x30aa: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_30af:
	/* 0x30af: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_30b4:
	/* 0x30b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30b9:
	/* 0x30b9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30be:
	/* 0x30be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c0:
	/* 0x30c0: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_30c4:
	/* 0x30c4: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30c6:
	/* 0x30c6: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30cc:
	/* 0x30cc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30d1:
	/* 0x30d1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30d3:
	/* 0x30d3: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_30d9:
	/* 0x30d9: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_30de:
	/* 0x30de: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_30e4:
	/* 0x30e4: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_30e9:
	/* 0x30e9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_30eb:
	/* 0x30eb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_30f0:
	/* 0x30f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f2:
	/* 0x30f2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30f5:
	/* 0x30f5: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2aac;
	}
x86_l_30fb:
	/* 0x30fb: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3100:
	/* 0x3100: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3103:
	/* 0x3103: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
	return 12553ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12553ULL: goto x86_l_3109;
	case 12558ULL: goto x86_l_310e;
	case 12562ULL: goto x86_l_3112;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12574ULL: goto x86_l_311e;
	case 12576ULL: goto x86_l_3120;
	case 12579ULL: goto x86_l_3123;
	case 12585ULL: goto x86_l_3129;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12600ULL: goto x86_l_3138;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12623ULL: goto x86_l_314f;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12651ULL: goto x86_l_316b;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12662ULL: goto x86_l_3176;
	case 12666ULL: goto x86_l_317a;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12692ULL: goto x86_l_3194;
	case 12696ULL: goto x86_l_3198;
	case 12700ULL: goto x86_l_319c;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12718ULL: goto x86_l_31ae;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12761ULL: goto x86_l_31d9;
	case 12766ULL: goto x86_l_31de;
	case 12769ULL: goto x86_l_31e1;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12783ULL: goto x86_l_31ef;
	case 12785ULL: goto x86_l_31f1;
	case 12789ULL: goto x86_l_31f5;
	case 12794ULL: goto x86_l_31fa;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12815ULL: goto x86_l_320f;
	case 12817ULL: goto x86_l_3211;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12830ULL: goto x86_l_321e;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12854ULL: goto x86_l_3236;
	case 12859ULL: goto x86_l_323b;
	case 12861ULL: goto x86_l_323d;
	case 12864ULL: goto x86_l_3240;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12884ULL: goto x86_l_3254;
	case 12889ULL: goto x86_l_3259;
	case 12893ULL: goto x86_l_325d;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12905ULL: goto x86_l_3269;
	case 12907ULL: goto x86_l_326b;
	case 12910ULL: goto x86_l_326e;
	case 12916ULL: goto x86_l_3274;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12931ULL: goto x86_l_3283;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12954ULL: goto x86_l_329a;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12965ULL: goto x86_l_32a5;
	case 12969ULL: goto x86_l_32a9;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12982ULL: goto x86_l_32b6;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12993ULL: goto x86_l_32c1;
	case 12997ULL: goto x86_l_32c5;
	case 13002ULL: goto x86_l_32ca;
	case 13007ULL: goto x86_l_32cf;
	case 13012ULL: goto x86_l_32d4;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13023ULL: goto x86_l_32df;
	case 13027ULL: goto x86_l_32e3;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13066ULL: goto x86_l_330a;
	case 13070ULL: goto x86_l_330e;
	case 13075ULL: goto x86_l_3313;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13090ULL: goto x86_l_3322;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13100ULL: goto x86_l_332c;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13114ULL: goto x86_l_333a;
	case 13116ULL: goto x86_l_333c;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13140ULL: goto x86_l_3354;
	case 13142ULL: goto x86_l_3356;
	case 13146ULL: goto x86_l_335a;
	case 13148ULL: goto x86_l_335c;
	case 13154ULL: goto x86_l_3362;
	case 13159ULL: goto x86_l_3367;
	case 13161ULL: goto x86_l_3369;
	case 13167ULL: goto x86_l_336f;
	case 13172ULL: goto x86_l_3374;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13190ULL: goto x86_l_3386;
	case 13192ULL: goto x86_l_3388;
	case 13195ULL: goto x86_l_338b;
	case 13201ULL: goto x86_l_3391;
	case 13206ULL: goto x86_l_3396;
	case 13209ULL: goto x86_l_3399;
	case 13215ULL: goto x86_l_339f;
	case 13220ULL: goto x86_l_33a4;
	case 13224ULL: goto x86_l_33a8;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13238ULL: goto x86_l_33b6;
	case 13241ULL: goto x86_l_33b9;
	case 13247ULL: goto x86_l_33bf;
	case 13251ULL: goto x86_l_33c3;
	case 13256ULL: goto x86_l_33c8;
	case 13262ULL: goto x86_l_33ce;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13276ULL: goto x86_l_33dc;
	case 13281ULL: goto x86_l_33e1;
	case 13285ULL: goto x86_l_33e5;
	case 13289ULL: goto x86_l_33e9;
	case 13294ULL: goto x86_l_33ee;
	case 13296ULL: goto x86_l_33f0;
	case 13300ULL: goto x86_l_33f4;
	case 13303ULL: goto x86_l_33f7;
	case 13308ULL: goto x86_l_33fc;
	case 13313ULL: goto x86_l_3401;
	case 13317ULL: goto x86_l_3405;
	case 13322ULL: goto x86_l_340a;
	case 13324ULL: goto x86_l_340c;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13354ULL: goto x86_l_342a;
	case 13358ULL: goto x86_l_342e;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13380ULL: goto x86_l_3444;
	case 13385ULL: goto x86_l_3449;
	case 13387ULL: goto x86_l_344b;
	case 13392ULL: goto x86_l_3450;
	case 13397ULL: goto x86_l_3455;
	case 13401ULL: goto x86_l_3459;
	case 13406ULL: goto x86_l_345e;
	case 13411ULL: goto x86_l_3463;
	case 13416ULL: goto x86_l_3468;
	case 13421ULL: goto x86_l_346d;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13431ULL: goto x86_l_3477;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13445ULL: goto x86_l_3485;
	case 13447ULL: goto x86_l_3487;
	case 13451ULL: goto x86_l_348b;
	case 13456ULL: goto x86_l_3490;
	case 13461ULL: goto x86_l_3495;
	case 13466ULL: goto x86_l_349a;
	case 13471ULL: goto x86_l_349f;
	case 13473ULL: goto x86_l_34a1;
	case 13477ULL: goto x86_l_34a5;
	case 13479ULL: goto x86_l_34a7;
	case 13485ULL: goto x86_l_34ad;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13498ULL: goto x86_l_34ba;
	case 13503ULL: goto x86_l_34bf;
	case 13509ULL: goto x86_l_34c5;
	case 13514ULL: goto x86_l_34ca;
	case 13516ULL: goto x86_l_34cc;
	case 13521ULL: goto x86_l_34d1;
	case 13523ULL: goto x86_l_34d3;
	case 13526ULL: goto x86_l_34d6;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13540ULL: goto x86_l_34e4;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13555ULL: goto x86_l_34f3;
	case 13557ULL: goto x86_l_34f5;
	case 13562ULL: goto x86_l_34fa;
	case 13567ULL: goto x86_l_34ff;
	case 13569ULL: goto x86_l_3501;
	case 13572ULL: goto x86_l_3504;
	case 13578ULL: goto x86_l_350a;
	case 13582ULL: goto x86_l_350e;
	case 13587ULL: goto x86_l_3513;
	case 13593ULL: goto x86_l_3519;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13612ULL: goto x86_l_352c;
	case 13616ULL: goto x86_l_3530;
	case 13620ULL: goto x86_l_3534;
	case 13625ULL: goto x86_l_3539;
	case 13627ULL: goto x86_l_353b;
	case 13631ULL: goto x86_l_353f;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13655ULL: goto x86_l_3557;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13689ULL: goto x86_l_3579;
	case 13693ULL: goto x86_l_357d;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13711ULL: goto x86_l_358f;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13728ULL: goto x86_l_35a0;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13762ULL: goto x86_l_35c2;
	case 13768ULL: goto x86_l_35c8;
	case 13773ULL: goto x86_l_35cd;
	case 13776ULL: goto x86_l_35d0;
	case 13778ULL: goto x86_l_35d2;
	case 13782ULL: goto x86_l_35d6;
	case 13787ULL: goto x86_l_35db;
	case 13792ULL: goto x86_l_35e0;
	case 13797ULL: goto x86_l_35e5;
	case 13802ULL: goto x86_l_35ea;
	case 13804ULL: goto x86_l_35ec;
	case 13808ULL: goto x86_l_35f0;
	case 13810ULL: goto x86_l_35f2;
	case 13816ULL: goto x86_l_35f8;
	case 13821ULL: goto x86_l_35fd;
	case 13823ULL: goto x86_l_35ff;
	case 13829ULL: goto x86_l_3605;
	case 13834ULL: goto x86_l_360a;
	case 13840ULL: goto x86_l_3610;
	case 13845ULL: goto x86_l_3615;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13857ULL: goto x86_l_3621;
	case 13863ULL: goto x86_l_3627;
	case 13868ULL: goto x86_l_362c;
	case 13871ULL: goto x86_l_362f;
	case 13877ULL: goto x86_l_3635;
	case 13882ULL: goto x86_l_363a;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13900ULL: goto x86_l_364c;
	case 13903ULL: goto x86_l_364f;
	case 13909ULL: goto x86_l_3655;
	case 13913ULL: goto x86_l_3659;
	case 13918ULL: goto x86_l_365e;
	case 13924ULL: goto x86_l_3664;
	case 13928ULL: goto x86_l_3668;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13943ULL: goto x86_l_3677;
	case 13947ULL: goto x86_l_367b;
	case 13951ULL: goto x86_l_367f;
	case 13956ULL: goto x86_l_3684;
	case 13958ULL: goto x86_l_3686;
	case 13962ULL: goto x86_l_368a;
	case 13965ULL: goto x86_l_368d;
	case 13970ULL: goto x86_l_3692;
	case 13975ULL: goto x86_l_3697;
	case 13979ULL: goto x86_l_369b;
	case 13984ULL: goto x86_l_36a0;
	case 13986ULL: goto x86_l_36a2;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14009ULL: goto x86_l_36b9;
	case 14014ULL: goto x86_l_36be;
	case 14016ULL: goto x86_l_36c0;
	case 14020ULL: goto x86_l_36c4;
	case 14024ULL: goto x86_l_36c8;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14042ULL: goto x86_l_36da;
	case 14047ULL: goto x86_l_36df;
	case 14049ULL: goto x86_l_36e1;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14063ULL: goto x86_l_36ef;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14093ULL: goto x86_l_370d;
	case 14099ULL: goto x86_l_3713;
	case 14104ULL: goto x86_l_3718;
	case 14107ULL: goto x86_l_371b;
	case 14109ULL: goto x86_l_371d;
	case 14113ULL: goto x86_l_3721;
	case 14118ULL: goto x86_l_3726;
	case 14123ULL: goto x86_l_372b;
	case 14128ULL: goto x86_l_3730;
	case 14133ULL: goto x86_l_3735;
	case 14135ULL: goto x86_l_3737;
	case 14139ULL: goto x86_l_373b;
	case 14141ULL: goto x86_l_373d;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14160ULL: goto x86_l_3750;
	case 14165ULL: goto x86_l_3755;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14178ULL: goto x86_l_3762;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3109:
	/* 0x3109: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_310e:
	/* 0x310e: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3112:
	/* 0x3112: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3114:
	/* 0x3114: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3119:
	/* 0x3119: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_311e:
	/* 0x311e: jmp    319c <trace_ret_file_update_time+0x319c> */
	goto x86_l_319c;
x86_l_3120:
	/* 0x3120: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3123:
	/* 0x3123: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_3129:
	/* 0x3129: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_312d:
	/* 0x312d: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3132:
	/* 0x3132: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3138:
	/* 0x3138: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_313c:
	/* 0x313c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3141:
	/* 0x3141: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3146:
	/* 0x3146: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_314b:
	/* 0x314b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_314f:
	/* 0x314f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3153:
	/* 0x3153: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3158:
	/* 0x3158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_315a:
	/* 0x315a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_315e:
	/* 0x315e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3161:
	/* 0x3161: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3166:
	/* 0x3166: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_316b:
	/* 0x316b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_316f:
	/* 0x316f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3174:
	/* 0x3174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3176:
	/* 0x3176: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317a:
	/* 0x317a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_317f:
	/* 0x317f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3184:
	/* 0x3184: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3189:
	/* 0x3189: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318d:
	/* 0x318d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3192:
	/* 0x3192: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3194:
	/* 0x3194: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3198:
	/* 0x3198: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_319c:
	/* 0x319c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31a1:
	/* 0x31a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a6:
	/* 0x31a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31ab:
	/* 0x31ab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31ae:
	/* 0x31ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b3:
	/* 0x31b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b5:
	/* 0x31b5: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31ba:
	/* 0x31ba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31bf:
	/* 0x31bf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31c3:
	/* 0x31c3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31c8:
	/* 0x31c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31cd:
	/* 0x31cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31d2:
	/* 0x31d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d7:
	/* 0x31d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d9:
	/* 0x31d9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31de:
	/* 0x31de: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31e1:
	/* 0x31e1: je     326b <trace_ret_file_update_time+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326b;
	}
x86_l_31e7:
	/* 0x31e7: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31ec:
	/* 0x31ec: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31ef:
	/* 0x31ef: je     326b <trace_ret_file_update_time+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326b;
	}
x86_l_31f1:
	/* 0x31f1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31f5:
	/* 0x31f5: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_31fa:
	/* 0x31fa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31ff:
	/* 0x31ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3204:
	/* 0x3204: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3209:
	/* 0x3209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320b:
	/* 0x320b: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_320f:
	/* 0x320f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3211:
	/* 0x3211: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3217:
	/* 0x3217: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_321c:
	/* 0x321c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_321e:
	/* 0x321e: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_3224:
	/* 0x3224: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3229:
	/* 0x3229: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_322f:
	/* 0x322f: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3234:
	/* 0x3234: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3236:
	/* 0x3236: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_323b:
	/* 0x323b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323d:
	/* 0x323d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3240:
	/* 0x3240: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3246:
	/* 0x3246: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_324b:
	/* 0x324b: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_324e:
	/* 0x324e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3254:
	/* 0x3254: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3259:
	/* 0x3259: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_325d:
	/* 0x325d: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_325f:
	/* 0x325f: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3264:
	/* 0x3264: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3269:
	/* 0x3269: jmp    32e7 <trace_ret_file_update_time+0x32e7> */
	goto x86_l_32e7;
x86_l_326b:
	/* 0x326b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_326e:
	/* 0x326e: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_3274:
	/* 0x3274: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3278:
	/* 0x3278: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_327d:
	/* 0x327d: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3283:
	/* 0x3283: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3287:
	/* 0x3287: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_328c:
	/* 0x328c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3291:
	/* 0x3291: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3296:
	/* 0x3296: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329a:
	/* 0x329a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_329e:
	/* 0x329e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a3:
	/* 0x32a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a5:
	/* 0x32a5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32a9:
	/* 0x32a9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_32ac:
	/* 0x32ac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32b1:
	/* 0x32b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32b6:
	/* 0x32b6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ba:
	/* 0x32ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32bf:
	/* 0x32bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c1:
	/* 0x32c1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c5:
	/* 0x32c5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ca:
	/* 0x32ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32cf:
	/* 0x32cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d4:
	/* 0x32d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d8:
	/* 0x32d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32dd:
	/* 0x32dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32df:
	/* 0x32df: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e3:
	/* 0x32e3: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32e7:
	/* 0x32e7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32ec:
	/* 0x32ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32f1:
	/* 0x32f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32f6:
	/* 0x32f6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32f9:
	/* 0x32f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fe:
	/* 0x32fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3300:
	/* 0x3300: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3305:
	/* 0x3305: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_330a:
	/* 0x330a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_330e:
	/* 0x330e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3313:
	/* 0x3313: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3318:
	/* 0x3318: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_331d:
	/* 0x331d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3322:
	/* 0x3322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3324:
	/* 0x3324: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3329:
	/* 0x3329: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_332c:
	/* 0x332c: je     33b6 <trace_ret_file_update_time+0x33b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b6;
	}
x86_l_3332:
	/* 0x3332: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3337:
	/* 0x3337: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_333a:
	/* 0x333a: je     33b6 <trace_ret_file_update_time+0x33b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b6;
	}
x86_l_333c:
	/* 0x333c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3340:
	/* 0x3340: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3345:
	/* 0x3345: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_334a:
	/* 0x334a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_334f:
	/* 0x334f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3354:
	/* 0x3354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3356:
	/* 0x3356: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_335a:
	/* 0x335a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_335c:
	/* 0x335c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3362:
	/* 0x3362: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3367:
	/* 0x3367: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3369:
	/* 0x3369: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_336f:
	/* 0x336f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3374:
	/* 0x3374: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_337a:
	/* 0x337a: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_337f:
	/* 0x337f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3381:
	/* 0x3381: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3386:
	/* 0x3386: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3388:
	/* 0x3388: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_338b:
	/* 0x338b: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3391:
	/* 0x3391: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3396:
	/* 0x3396: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3399:
	/* 0x3399: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_339f:
	/* 0x339f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_33a4:
	/* 0x33a4: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_33a8:
	/* 0x33a8: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33aa:
	/* 0x33aa: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33af:
	/* 0x33af: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33b4:
	/* 0x33b4: jmp    3432 <trace_ret_file_update_time+0x3432> */
	goto x86_l_3432;
x86_l_33b6:
	/* 0x33b6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33b9:
	/* 0x33b9: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_33bf:
	/* 0x33bf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c3:
	/* 0x33c3: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_33c8:
	/* 0x33c8: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_33ce:
	/* 0x33ce: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33d2:
	/* 0x33d2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33d7:
	/* 0x33d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33dc:
	/* 0x33dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33e1:
	/* 0x33e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33e5:
	/* 0x33e5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33e9:
	/* 0x33e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33ee:
	/* 0x33ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f0:
	/* 0x33f0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f4:
	/* 0x33f4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_33f7:
	/* 0x33f7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_33fc:
	/* 0x33fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3401:
	/* 0x3401: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3405:
	/* 0x3405: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_340a:
	/* 0x340a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340c:
	/* 0x340c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3410:
	/* 0x3410: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3415:
	/* 0x3415: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_341a:
	/* 0x341a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_341f:
	/* 0x341f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3423:
	/* 0x3423: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3428:
	/* 0x3428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_342a:
	/* 0x342a: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_342e:
	/* 0x342e: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3432:
	/* 0x3432: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3437:
	/* 0x3437: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_343c:
	/* 0x343c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3441:
	/* 0x3441: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3444:
	/* 0x3444: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3449:
	/* 0x3449: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344b:
	/* 0x344b: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3450:
	/* 0x3450: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3455:
	/* 0x3455: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3459:
	/* 0x3459: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_345e:
	/* 0x345e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3463:
	/* 0x3463: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3468:
	/* 0x3468: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_346d:
	/* 0x346d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_346f:
	/* 0x346f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3474:
	/* 0x3474: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3477:
	/* 0x3477: je     3501 <trace_ret_file_update_time+0x3501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3501;
	}
x86_l_347d:
	/* 0x347d: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3482:
	/* 0x3482: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3485:
	/* 0x3485: je     3501 <trace_ret_file_update_time+0x3501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3501;
	}
x86_l_3487:
	/* 0x3487: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_348b:
	/* 0x348b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3490:
	/* 0x3490: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3495:
	/* 0x3495: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_349a:
	/* 0x349a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_349f:
	/* 0x349f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a1:
	/* 0x34a1: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_34a5:
	/* 0x34a5: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_34a7:
	/* 0x34a7: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_34ad:
	/* 0x34ad: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34b2:
	/* 0x34b2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34b4:
	/* 0x34b4: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_34ba:
	/* 0x34ba: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_34bf:
	/* 0x34bf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_34c5:
	/* 0x34c5: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_34ca:
	/* 0x34ca: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_34cc:
	/* 0x34cc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_34d1:
	/* 0x34d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d3:
	/* 0x34d3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34d6:
	/* 0x34d6: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_34dc:
	/* 0x34dc: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34e1:
	/* 0x34e1: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_34e4:
	/* 0x34e4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34ea:
	/* 0x34ea: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34ef:
	/* 0x34ef: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34f3:
	/* 0x34f3: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34f5:
	/* 0x34f5: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34fa:
	/* 0x34fa: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34ff:
	/* 0x34ff: jmp    357d <trace_ret_file_update_time+0x357d> */
	goto x86_l_357d;
x86_l_3501:
	/* 0x3501: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3504:
	/* 0x3504: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_350a:
	/* 0x350a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350e:
	/* 0x350e: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3513:
	/* 0x3513: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3519:
	/* 0x3519: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_351d:
	/* 0x351d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3522:
	/* 0x3522: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3527:
	/* 0x3527: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_352c:
	/* 0x352c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3530:
	/* 0x3530: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3534:
	/* 0x3534: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3539:
	/* 0x3539: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353b:
	/* 0x353b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_353f:
	/* 0x353f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3542:
	/* 0x3542: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3547:
	/* 0x3547: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_354c:
	/* 0x354c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3550:
	/* 0x3550: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3555:
	/* 0x3555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3557:
	/* 0x3557: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_355b:
	/* 0x355b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3560:
	/* 0x3560: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3565:
	/* 0x3565: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_356a:
	/* 0x356a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_356e:
	/* 0x356e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3573:
	/* 0x3573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3575:
	/* 0x3575: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3579:
	/* 0x3579: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_357d:
	/* 0x357d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3582:
	/* 0x3582: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3587:
	/* 0x3587: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_358c:
	/* 0x358c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_358f:
	/* 0x358f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3594:
	/* 0x3594: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3596:
	/* 0x3596: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_359b:
	/* 0x359b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35a0:
	/* 0x35a0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35a4:
	/* 0x35a4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35a9:
	/* 0x35a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35ae:
	/* 0x35ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35b3:
	/* 0x35b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35b8:
	/* 0x35b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ba:
	/* 0x35ba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35bf:
	/* 0x35bf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_35c2:
	/* 0x35c2: je     364c <trace_ret_file_update_time+0x364c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364c;
	}
x86_l_35c8:
	/* 0x35c8: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35cd:
	/* 0x35cd: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_35d0:
	/* 0x35d0: je     364c <trace_ret_file_update_time+0x364c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364c;
	}
x86_l_35d2:
	/* 0x35d2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35d6:
	/* 0x35d6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_35db:
	/* 0x35db: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_35e0:
	/* 0x35e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35e5:
	/* 0x35e5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_35ea:
	/* 0x35ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ec:
	/* 0x35ec: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_35f0:
	/* 0x35f0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35f2:
	/* 0x35f2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35f8:
	/* 0x35f8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35fd:
	/* 0x35fd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35ff:
	/* 0x35ff: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_3605:
	/* 0x3605: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_360a:
	/* 0x360a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3610:
	/* 0x3610: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3615:
	/* 0x3615: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3617:
	/* 0x3617: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_361c:
	/* 0x361c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361e:
	/* 0x361e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3621:
	/* 0x3621: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3627:
	/* 0x3627: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_362c:
	/* 0x362c: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_362f:
	/* 0x362f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3635:
	/* 0x3635: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_363a:
	/* 0x363a: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_363e:
	/* 0x363e: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3640:
	/* 0x3640: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3645:
	/* 0x3645: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_364a:
	/* 0x364a: jmp    36c8 <trace_ret_file_update_time+0x36c8> */
	goto x86_l_36c8;
x86_l_364c:
	/* 0x364c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_364f:
	/* 0x364f: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_3655:
	/* 0x3655: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3659:
	/* 0x3659: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_365e:
	/* 0x365e: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3664:
	/* 0x3664: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3668:
	/* 0x3668: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_366d:
	/* 0x366d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3672:
	/* 0x3672: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3677:
	/* 0x3677: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_367b:
	/* 0x367b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_367f:
	/* 0x367f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3684:
	/* 0x3684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3686:
	/* 0x3686: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368a:
	/* 0x368a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_368d:
	/* 0x368d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3692:
	/* 0x3692: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3697:
	/* 0x3697: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_369b:
	/* 0x369b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36a0:
	/* 0x36a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a2:
	/* 0x36a2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36a6:
	/* 0x36a6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36ab:
	/* 0x36ab: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36b0:
	/* 0x36b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36b5:
	/* 0x36b5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36b9:
	/* 0x36b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36be:
	/* 0x36be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c0:
	/* 0x36c0: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c4:
	/* 0x36c4: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36c8:
	/* 0x36c8: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36cd:
	/* 0x36cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36d2:
	/* 0x36d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36d7:
	/* 0x36d7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_36da:
	/* 0x36da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36df:
	/* 0x36df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36e1:
	/* 0x36e1: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36e6:
	/* 0x36e6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36eb:
	/* 0x36eb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_36ef:
	/* 0x36ef: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_36f4:
	/* 0x36f4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36f9:
	/* 0x36f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36fe:
	/* 0x36fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3703:
	/* 0x3703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3705:
	/* 0x3705: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_370a:
	/* 0x370a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_370d:
	/* 0x370d: je     3797 <trace_ret_file_update_time+0x3797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14231ULL;
	}
x86_l_3713:
	/* 0x3713: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3718:
	/* 0x3718: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_371b:
	/* 0x371b: je     3797 <trace_ret_file_update_time+0x3797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14231ULL;
	}
x86_l_371d:
	/* 0x371d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3721:
	/* 0x3721: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3726:
	/* 0x3726: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_372b:
	/* 0x372b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3730:
	/* 0x3730: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3735:
	/* 0x3735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3737:
	/* 0x3737: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_373b:
	/* 0x373b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_373d:
	/* 0x373d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3743:
	/* 0x3743: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3748:
	/* 0x3748: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_374a:
	/* 0x374a: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_3750:
	/* 0x3750: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3755:
	/* 0x3755: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_375b:
	/* 0x375b: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3760:
	/* 0x3760: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3762:
	/* 0x3762: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
	return 14183ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14183ULL: goto x86_l_3767;
	case 14185ULL: goto x86_l_3769;
	case 14188ULL: goto x86_l_376c;
	case 14194ULL: goto x86_l_3772;
	case 14199ULL: goto x86_l_3777;
	case 14202ULL: goto x86_l_377a;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14217ULL: goto x86_l_3789;
	case 14219ULL: goto x86_l_378b;
	case 14224ULL: goto x86_l_3790;
	case 14229ULL: goto x86_l_3795;
	case 14231ULL: goto x86_l_3797;
	case 14234ULL: goto x86_l_379a;
	case 14240ULL: goto x86_l_37a0;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14255ULL: goto x86_l_37af;
	case 14259ULL: goto x86_l_37b3;
	case 14264ULL: goto x86_l_37b8;
	case 14269ULL: goto x86_l_37bd;
	case 14274ULL: goto x86_l_37c2;
	case 14278ULL: goto x86_l_37c6;
	case 14282ULL: goto x86_l_37ca;
	case 14287ULL: goto x86_l_37cf;
	case 14289ULL: goto x86_l_37d1;
	case 14293ULL: goto x86_l_37d5;
	case 14296ULL: goto x86_l_37d8;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14310ULL: goto x86_l_37e6;
	case 14315ULL: goto x86_l_37eb;
	case 14317ULL: goto x86_l_37ed;
	case 14321ULL: goto x86_l_37f1;
	case 14326ULL: goto x86_l_37f6;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14347ULL: goto x86_l_380b;
	case 14351ULL: goto x86_l_380f;
	case 14355ULL: goto x86_l_3813;
	case 14360ULL: goto x86_l_3818;
	case 14365ULL: goto x86_l_381d;
	case 14370ULL: goto x86_l_3822;
	case 14373ULL: goto x86_l_3825;
	case 14378ULL: goto x86_l_382a;
	case 14380ULL: goto x86_l_382c;
	case 14385ULL: goto x86_l_3831;
	case 14390ULL: goto x86_l_3836;
	case 14394ULL: goto x86_l_383a;
	case 14399ULL: goto x86_l_383f;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14416ULL: goto x86_l_3850;
	case 14421ULL: goto x86_l_3855;
	case 14424ULL: goto x86_l_3858;
	case 14430ULL: goto x86_l_385e;
	case 14435ULL: goto x86_l_3863;
	case 14438ULL: goto x86_l_3866;
	case 14440ULL: goto x86_l_3868;
	case 14444ULL: goto x86_l_386c;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14464ULL: goto x86_l_3880;
	case 14466ULL: goto x86_l_3882;
	case 14470ULL: goto x86_l_3886;
	case 14472ULL: goto x86_l_3888;
	case 14478ULL: goto x86_l_388e;
	case 14483ULL: goto x86_l_3893;
	case 14485ULL: goto x86_l_3895;
	case 14491ULL: goto x86_l_389b;
	case 14496ULL: goto x86_l_38a0;
	case 14502ULL: goto x86_l_38a6;
	case 14507ULL: goto x86_l_38ab;
	case 14509ULL: goto x86_l_38ad;
	case 14514ULL: goto x86_l_38b2;
	case 14516ULL: goto x86_l_38b4;
	case 14519ULL: goto x86_l_38b7;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14533ULL: goto x86_l_38c5;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14548ULL: goto x86_l_38d4;
	case 14550ULL: goto x86_l_38d6;
	case 14555ULL: goto x86_l_38db;
	case 14560ULL: goto x86_l_38e0;
	case 14562ULL: goto x86_l_38e2;
	case 14565ULL: goto x86_l_38e5;
	case 14571ULL: goto x86_l_38eb;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14586ULL: goto x86_l_38fa;
	case 14590ULL: goto x86_l_38fe;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14609ULL: goto x86_l_3911;
	case 14613ULL: goto x86_l_3915;
	case 14618ULL: goto x86_l_391a;
	case 14620ULL: goto x86_l_391c;
	case 14624ULL: goto x86_l_3920;
	case 14627ULL: goto x86_l_3923;
	case 14632ULL: goto x86_l_3928;
	case 14637ULL: goto x86_l_392d;
	case 14641ULL: goto x86_l_3931;
	case 14646ULL: goto x86_l_3936;
	case 14648ULL: goto x86_l_3938;
	case 14652ULL: goto x86_l_393c;
	case 14657ULL: goto x86_l_3941;
	case 14662ULL: goto x86_l_3946;
	case 14667ULL: goto x86_l_394b;
	case 14671ULL: goto x86_l_394f;
	case 14676ULL: goto x86_l_3954;
	case 14678ULL: goto x86_l_3956;
	case 14682ULL: goto x86_l_395a;
	case 14686ULL: goto x86_l_395e;
	case 14691ULL: goto x86_l_3963;
	case 14696ULL: goto x86_l_3968;
	case 14701ULL: goto x86_l_396d;
	case 14704ULL: goto x86_l_3970;
	case 14709ULL: goto x86_l_3975;
	case 14711ULL: goto x86_l_3977;
	case 14716ULL: goto x86_l_397c;
	case 14721ULL: goto x86_l_3981;
	case 14725ULL: goto x86_l_3985;
	case 14730ULL: goto x86_l_398a;
	case 14735ULL: goto x86_l_398f;
	case 14740ULL: goto x86_l_3994;
	case 14745ULL: goto x86_l_3999;
	case 14747ULL: goto x86_l_399b;
	case 14752ULL: goto x86_l_39a0;
	case 14755ULL: goto x86_l_39a3;
	case 14761ULL: goto x86_l_39a9;
	case 14766ULL: goto x86_l_39ae;
	case 14769ULL: goto x86_l_39b1;
	case 14771ULL: goto x86_l_39b3;
	case 14775ULL: goto x86_l_39b7;
	case 14780ULL: goto x86_l_39bc;
	case 14785ULL: goto x86_l_39c1;
	case 14790ULL: goto x86_l_39c6;
	case 14795ULL: goto x86_l_39cb;
	case 14797ULL: goto x86_l_39cd;
	case 14801ULL: goto x86_l_39d1;
	case 14803ULL: goto x86_l_39d3;
	case 14809ULL: goto x86_l_39d9;
	case 14814ULL: goto x86_l_39de;
	case 14816ULL: goto x86_l_39e0;
	case 14822ULL: goto x86_l_39e6;
	case 14827ULL: goto x86_l_39eb;
	case 14833ULL: goto x86_l_39f1;
	case 14838ULL: goto x86_l_39f6;
	case 14840ULL: goto x86_l_39f8;
	case 14845ULL: goto x86_l_39fd;
	case 14847ULL: goto x86_l_39ff;
	case 14850ULL: goto x86_l_3a02;
	case 14856ULL: goto x86_l_3a08;
	case 14861ULL: goto x86_l_3a0d;
	case 14864ULL: goto x86_l_3a10;
	case 14870ULL: goto x86_l_3a16;
	case 14875ULL: goto x86_l_3a1b;
	case 14879ULL: goto x86_l_3a1f;
	case 14881ULL: goto x86_l_3a21;
	case 14886ULL: goto x86_l_3a26;
	case 14891ULL: goto x86_l_3a2b;
	case 14893ULL: goto x86_l_3a2d;
	case 14896ULL: goto x86_l_3a30;
	case 14902ULL: goto x86_l_3a36;
	case 14906ULL: goto x86_l_3a3a;
	case 14911ULL: goto x86_l_3a3f;
	case 14917ULL: goto x86_l_3a45;
	case 14921ULL: goto x86_l_3a49;
	case 14926ULL: goto x86_l_3a4e;
	case 14931ULL: goto x86_l_3a53;
	case 14936ULL: goto x86_l_3a58;
	case 14940ULL: goto x86_l_3a5c;
	case 14944ULL: goto x86_l_3a60;
	case 14949ULL: goto x86_l_3a65;
	case 14951ULL: goto x86_l_3a67;
	case 14955ULL: goto x86_l_3a6b;
	case 14958ULL: goto x86_l_3a6e;
	case 14963ULL: goto x86_l_3a73;
	case 14968ULL: goto x86_l_3a78;
	case 14972ULL: goto x86_l_3a7c;
	case 14977ULL: goto x86_l_3a81;
	case 14979ULL: goto x86_l_3a83;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14998ULL: goto x86_l_3a96;
	case 15002ULL: goto x86_l_3a9a;
	case 15007ULL: goto x86_l_3a9f;
	case 15009ULL: goto x86_l_3aa1;
	case 15013ULL: goto x86_l_3aa5;
	case 15017ULL: goto x86_l_3aa9;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15032ULL: goto x86_l_3ab8;
	case 15035ULL: goto x86_l_3abb;
	case 15040ULL: goto x86_l_3ac0;
	case 15042ULL: goto x86_l_3ac2;
	case 15047ULL: goto x86_l_3ac7;
	case 15052ULL: goto x86_l_3acc;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15066ULL: goto x86_l_3ada;
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15078ULL: goto x86_l_3ae6;
	case 15083ULL: goto x86_l_3aeb;
	case 15086ULL: goto x86_l_3aee;
	case 15092ULL: goto x86_l_3af4;
	case 15097ULL: goto x86_l_3af9;
	case 15100ULL: goto x86_l_3afc;
	case 15106ULL: goto x86_l_3b02;
	case 15110ULL: goto x86_l_3b06;
	case 15115ULL: goto x86_l_3b0b;
	case 15120ULL: goto x86_l_3b10;
	case 15125ULL: goto x86_l_3b15;
	case 15130ULL: goto x86_l_3b1a;
	case 15132ULL: goto x86_l_3b1c;
	case 15136ULL: goto x86_l_3b20;
	case 15138ULL: goto x86_l_3b22;
	case 15144ULL: goto x86_l_3b28;
	case 15149ULL: goto x86_l_3b2d;
	case 15151ULL: goto x86_l_3b2f;
	case 15157ULL: goto x86_l_3b35;
	case 15162ULL: goto x86_l_3b3a;
	case 15168ULL: goto x86_l_3b40;
	case 15173ULL: goto x86_l_3b45;
	case 15175ULL: goto x86_l_3b47;
	case 15180ULL: goto x86_l_3b4c;
	case 15182ULL: goto x86_l_3b4e;
	case 15185ULL: goto x86_l_3b51;
	case 15191ULL: goto x86_l_3b57;
	case 15196ULL: goto x86_l_3b5c;
	case 15200ULL: goto x86_l_3b60;
	case 15206ULL: goto x86_l_3b66;
	case 15211ULL: goto x86_l_3b6b;
	case 15215ULL: goto x86_l_3b6f;
	case 15218ULL: goto x86_l_3b72;
	case 15223ULL: goto x86_l_3b77;
	case 15228ULL: goto x86_l_3b7c;
	case 15233ULL: goto x86_l_3b81;
	case 15240ULL: goto x86_l_3b88;
	case 15246ULL: goto x86_l_3b8e;
	case 15251ULL: goto x86_l_3b93;
	case 15254ULL: goto x86_l_3b96;
	case 15260ULL: goto x86_l_3b9c;
	case 15264ULL: goto x86_l_3ba0;
	case 15269ULL: goto x86_l_3ba5;
	case 15275ULL: goto x86_l_3bab;
	case 15279ULL: goto x86_l_3baf;
	case 15284ULL: goto x86_l_3bb4;
	case 15289ULL: goto x86_l_3bb9;
	case 15294ULL: goto x86_l_3bbe;
	case 15298ULL: goto x86_l_3bc2;
	case 15302ULL: goto x86_l_3bc6;
	case 15307ULL: goto x86_l_3bcb;
	case 15309ULL: goto x86_l_3bcd;
	case 15313ULL: goto x86_l_3bd1;
	case 15316ULL: goto x86_l_3bd4;
	case 15321ULL: goto x86_l_3bd9;
	case 15326ULL: goto x86_l_3bde;
	case 15330ULL: goto x86_l_3be2;
	case 15335ULL: goto x86_l_3be7;
	case 15337ULL: goto x86_l_3be9;
	case 15341ULL: goto x86_l_3bed;
	case 15346ULL: goto x86_l_3bf2;
	case 15351ULL: goto x86_l_3bf7;
	case 15356ULL: goto x86_l_3bfc;
	case 15360ULL: goto x86_l_3c00;
	case 15365ULL: goto x86_l_3c05;
	case 15367ULL: goto x86_l_3c07;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3767:
	/* 0x3767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3769:
	/* 0x3769: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_376c:
	/* 0x376c: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3772:
	/* 0x3772: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3777:
	/* 0x3777: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_377a:
	/* 0x377a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3780:
	/* 0x3780: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3785:
	/* 0x3785: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3789:
	/* 0x3789: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_378b:
	/* 0x378b: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3790:
	/* 0x3790: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3795:
	/* 0x3795: jmp    3813 <trace_ret_file_update_time+0x3813> */
	goto x86_l_3813;
x86_l_3797:
	/* 0x3797: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_379a:
	/* 0x379a: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_37a0:
	/* 0x37a0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a4:
	/* 0x37a4: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_37a9:
	/* 0x37a9: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_37af:
	/* 0x37af: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37b3:
	/* 0x37b3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37b8:
	/* 0x37b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37bd:
	/* 0x37bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37c2:
	/* 0x37c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c6:
	/* 0x37c6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_37ca:
	/* 0x37ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37cf:
	/* 0x37cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d1:
	/* 0x37d1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d5:
	/* 0x37d5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_37d8:
	/* 0x37d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37dd:
	/* 0x37dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37e2:
	/* 0x37e2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37e6:
	/* 0x37e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37eb:
	/* 0x37eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37ed:
	/* 0x37ed: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37f1:
	/* 0x37f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_37f6:
	/* 0x37f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_37fb:
	/* 0x37fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3800:
	/* 0x3800: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3804:
	/* 0x3804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3809:
	/* 0x3809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380b:
	/* 0x380b: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_380f:
	/* 0x380f: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3813:
	/* 0x3813: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3818:
	/* 0x3818: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_381d:
	/* 0x381d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3822:
	/* 0x3822: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3825:
	/* 0x3825: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_382a:
	/* 0x382a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_382c:
	/* 0x382c: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3831:
	/* 0x3831: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3836:
	/* 0x3836: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_383a:
	/* 0x383a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_383f:
	/* 0x383f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3844:
	/* 0x3844: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3849:
	/* 0x3849: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_384e:
	/* 0x384e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3850:
	/* 0x3850: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3855:
	/* 0x3855: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3858:
	/* 0x3858: je     38e2 <trace_ret_file_update_time+0x38e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e2;
	}
x86_l_385e:
	/* 0x385e: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3863:
	/* 0x3863: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3866:
	/* 0x3866: je     38e2 <trace_ret_file_update_time+0x38e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38e2;
	}
x86_l_3868:
	/* 0x3868: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_386c:
	/* 0x386c: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3871:
	/* 0x3871: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3876:
	/* 0x3876: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_387b:
	/* 0x387b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3880:
	/* 0x3880: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3882:
	/* 0x3882: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_3886:
	/* 0x3886: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3888:
	/* 0x3888: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_388e:
	/* 0x388e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3893:
	/* 0x3893: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3895:
	/* 0x3895: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_389b:
	/* 0x389b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_38a0:
	/* 0x38a0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_38a6:
	/* 0x38a6: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_38ab:
	/* 0x38ab: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_38ad:
	/* 0x38ad: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_38b2:
	/* 0x38b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b4:
	/* 0x38b4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38b7:
	/* 0x38b7: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_38bd:
	/* 0x38bd: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38c2:
	/* 0x38c2: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_38c5:
	/* 0x38c5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_38cb:
	/* 0x38cb: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_38d0:
	/* 0x38d0: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_38d4:
	/* 0x38d4: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_38d6:
	/* 0x38d6: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38db:
	/* 0x38db: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38e0:
	/* 0x38e0: jmp    395e <trace_ret_file_update_time+0x395e> */
	goto x86_l_395e;
x86_l_38e2:
	/* 0x38e2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_38e5:
	/* 0x38e5: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_38eb:
	/* 0x38eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38ef:
	/* 0x38ef: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_38f4:
	/* 0x38f4: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_38fa:
	/* 0x38fa: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38fe:
	/* 0x38fe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3903:
	/* 0x3903: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3908:
	/* 0x3908: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_390d:
	/* 0x390d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3911:
	/* 0x3911: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3915:
	/* 0x3915: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_391a:
	/* 0x391a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_391c:
	/* 0x391c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3920:
	/* 0x3920: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3923:
	/* 0x3923: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3928:
	/* 0x3928: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_392d:
	/* 0x392d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3931:
	/* 0x3931: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3936:
	/* 0x3936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3938:
	/* 0x3938: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_393c:
	/* 0x393c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3941:
	/* 0x3941: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3946:
	/* 0x3946: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_394b:
	/* 0x394b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_394f:
	/* 0x394f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3954:
	/* 0x3954: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3956:
	/* 0x3956: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_395a:
	/* 0x395a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_395e:
	/* 0x395e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3963:
	/* 0x3963: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3968:
	/* 0x3968: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_396d:
	/* 0x396d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3970:
	/* 0x3970: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3975:
	/* 0x3975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3977:
	/* 0x3977: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_397c:
	/* 0x397c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3981:
	/* 0x3981: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3985:
	/* 0x3985: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_398a:
	/* 0x398a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_398f:
	/* 0x398f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3994:
	/* 0x3994: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3999:
	/* 0x3999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_399b:
	/* 0x399b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39a0:
	/* 0x39a0: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_39a3:
	/* 0x39a3: je     3a2d <trace_ret_file_update_time+0x3a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a2d;
	}
x86_l_39a9:
	/* 0x39a9: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_39ae:
	/* 0x39ae: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_39b1:
	/* 0x39b1: je     3a2d <trace_ret_file_update_time+0x3a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a2d;
	}
x86_l_39b3:
	/* 0x39b3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_39b7:
	/* 0x39b7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_39bc:
	/* 0x39bc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_39c1:
	/* 0x39c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_39c6:
	/* 0x39c6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_39cb:
	/* 0x39cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39cd:
	/* 0x39cd: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_39d1:
	/* 0x39d1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_39d3:
	/* 0x39d3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_39d9:
	/* 0x39d9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39de:
	/* 0x39de: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39e0:
	/* 0x39e0: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_39e6:
	/* 0x39e6: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_39eb:
	/* 0x39eb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_39f1:
	/* 0x39f1: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_39f6:
	/* 0x39f6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_39f8:
	/* 0x39f8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_39fd:
	/* 0x39fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ff:
	/* 0x39ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a02:
	/* 0x3a02: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3a08:
	/* 0x3a08: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a0d:
	/* 0x3a0d: lea    ecx,[rsi-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3a10:
	/* 0x3a10: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3a16:
	/* 0x3a16: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a1b:
	/* 0x3a1b: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3a1f:
	/* 0x3a1f: sub    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3a21:
	/* 0x3a21: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a26:
	/* 0x3a26: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a2b:
	/* 0x3a2b: jmp    3aa9 <trace_ret_file_update_time+0x3aa9> */
	goto x86_l_3aa9;
x86_l_3a2d:
	/* 0x3a2d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3a30:
	/* 0x3a30: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_3a36:
	/* 0x3a36: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3a:
	/* 0x3a3a: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3a3f:
	/* 0x3a3f: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3a45:
	/* 0x3a45: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a49:
	/* 0x3a49: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a4e:
	/* 0x3a4e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a53:
	/* 0x3a53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a58:
	/* 0x3a58: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a5c:
	/* 0x3a5c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3a60:
	/* 0x3a60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a65:
	/* 0x3a65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a67:
	/* 0x3a67: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a6b:
	/* 0x3a6b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3a6e:
	/* 0x3a6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a73:
	/* 0x3a73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a78:
	/* 0x3a78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a7c:
	/* 0x3a7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a81:
	/* 0x3a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a83:
	/* 0x3a83: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a87:
	/* 0x3a87: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3a91:
	/* 0x3a91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3a96:
	/* 0x3a96: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a9a:
	/* 0x3a9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a9f:
	/* 0x3a9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa1:
	/* 0x3aa1: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa5:
	/* 0x3aa5: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3aa9:
	/* 0x3aa9: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3aae:
	/* 0x3aae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ab3:
	/* 0x3ab3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ab8:
	/* 0x3ab8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3abb:
	/* 0x3abb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ac0:
	/* 0x3ac0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac2:
	/* 0x3ac2: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ac7:
	/* 0x3ac7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3acc:
	/* 0x3acc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ad0:
	/* 0x3ad0: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ada:
	/* 0x3ada: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3adf:
	/* 0x3adf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ae4:
	/* 0x3ae4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ae6:
	/* 0x3ae6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3aeb:
	/* 0x3aeb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3aee:
	/* 0x3aee: je     3b93 <trace_ret_file_update_time+0x3b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b93;
	}
x86_l_3af4:
	/* 0x3af4: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3af9:
	/* 0x3af9: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3afc:
	/* 0x3afc: je     3b93 <trace_ret_file_update_time+0x3b93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b93;
	}
x86_l_3b02:
	/* 0x3b02: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3b06:
	/* 0x3b06: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b0b:
	/* 0x3b0b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3b10:
	/* 0x3b10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b15:
	/* 0x3b15: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3b1a:
	/* 0x3b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b1c:
	/* 0x3b1c: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_3b20:
	/* 0x3b20: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3b22:
	/* 0x3b22: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3b28:
	/* 0x3b28: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b2d:
	/* 0x3b2d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3b2f:
	/* 0x3b2f: jb     2902 <trace_ret_file_update_time+0x2902> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10498ULL;
	}
x86_l_3b35:
	/* 0x3b35: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3b3a:
	/* 0x3b3a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3b40:
	/* 0x3b40: add    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_3b45:
	/* 0x3b45: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3b47:
	/* 0x3b47: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3b4c:
	/* 0x3b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b4e:
	/* 0x3b4e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3b51:
	/* 0x3b51: jl     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 10924ULL;
	}
x86_l_3b57:
	/* 0x3b57: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b5c:
	/* 0x3b5c: lea    ecx,[r8-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3b60:
	/* 0x3b60: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3b66:
	/* 0x3b66: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3b6b:
	/* 0x3b6b: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3b6f:
	/* 0x3b6f: sub    r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3b72:
	/* 0x3b72: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b77:
	/* 0x3b77: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b7c:
	/* 0x3b7c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b81:
	/* 0x3b81: cmp    r8d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 16384ULL);
x86_l_3b88:
	/* 0x3b88: je     1a22 <trace_ret_file_update_time+0x1a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6690ULL;
	}
x86_l_3b8e:
	/* 0x3b8e: jmp    24b2 <trace_ret_file_update_time+0x24b2> */
	return 9394ULL;
x86_l_3b93:
	/* 0x3b93: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3b96:
	/* 0x3b96: jne    2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10924ULL;
	}
x86_l_3b9c:
	/* 0x3b9c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ba0:
	/* 0x3ba0: cmp    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_3ba5:
	/* 0x3ba5: je     2aac <trace_ret_file_update_time+0x2aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10924ULL;
	}
x86_l_3bab:
	/* 0x3bab: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3baf:
	/* 0x3baf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3bb4:
	/* 0x3bb4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bb9:
	/* 0x3bb9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bbe:
	/* 0x3bbe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bc2:
	/* 0x3bc2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3bc6:
	/* 0x3bc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bcb:
	/* 0x3bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bcd:
	/* 0x3bcd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bd1:
	/* 0x3bd1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3bd4:
	/* 0x3bd4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bd9:
	/* 0x3bd9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bde:
	/* 0x3bde: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3be2:
	/* 0x3be2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be7:
	/* 0x3be7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be9:
	/* 0x3be9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bed:
	/* 0x3bed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bf2:
	/* 0x3bf2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3bf7:
	/* 0x3bf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3bfc:
	/* 0x3bfc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c00:
	/* 0x3c00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c05:
	/* 0x3c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c07:
	/* 0x3c07: jmp    2aac <trace_ret_file_update_time+0x2aac> */
	return 10924ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_file_update_time_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13396U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2237ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2245ULL && __x86_pc <= 4078ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 4080ULL && __x86_pc <= 5825ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5837ULL && __x86_pc <= 7624ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7631ULL && __x86_pc <= 9293ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9298ULL && __x86_pc <= 10922ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10924ULL && __x86_pc <= 12547ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12553ULL && __x86_pc <= 14178ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14183ULL && __x86_pc <= 15367ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

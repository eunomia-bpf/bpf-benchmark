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
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 30ULL: goto x86_l_1e;
	case 32ULL: goto x86_l_20;
	case 35ULL: goto x86_l_23;
	case 43ULL: goto x86_l_2b;
	case 48ULL: goto x86_l_30;
	case 55ULL: goto x86_l_37;
	case 63ULL: goto x86_l_3f;
	case 65ULL: goto x86_l_41;
	case 68ULL: goto x86_l_44;
	case 74ULL: goto x86_l_4a;
	case 77ULL: goto x86_l_4d;
	case 81ULL: goto x86_l_51;
	case 89ULL: goto x86_l_59;
	case 94ULL: goto x86_l_5e;
	case 96ULL: goto x86_l_60;
	case 98ULL: goto x86_l_62;
	case 101ULL: goto x86_l_65;
	case 109ULL: goto x86_l_6d;
	case 114ULL: goto x86_l_72;
	case 121ULL: goto x86_l_79;
	case 129ULL: goto x86_l_81;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 141ULL: goto x86_l_8d;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 151ULL: goto x86_l_97;
	case 155ULL: goto x86_l_9b;
	case 160ULL: goto x86_l_a0;
	case 168ULL: goto x86_l_a8;
	case 173ULL: goto x86_l_ad;
	case 175ULL: goto x86_l_af;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 200ULL: goto x86_l_c8;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 220ULL: goto x86_l_dc;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 237ULL: goto x86_l_ed;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 247ULL: goto x86_l_f7;
	case 255ULL: goto x86_l_ff;
	case 257ULL: goto x86_l_101;
	case 261ULL: goto x86_l_105;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 304ULL: goto x86_l_130;
	case 312ULL: goto x86_l_138;
	case 317ULL: goto x86_l_13d;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 331ULL: goto x86_l_14b;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 343ULL: goto x86_l_157;
	case 348ULL: goto x86_l_15c;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 362ULL: goto x86_l_16a;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 384ULL: goto x86_l_180;
	case 392ULL: goto x86_l_188;
	case 403ULL: goto x86_l_193;
	case 414ULL: goto x86_l_19e;
	case 425ULL: goto x86_l_1a9;
	case 436ULL: goto x86_l_1b4;
	case 447ULL: goto x86_l_1bf;
	case 458ULL: goto x86_l_1ca;
	case 469ULL: goto x86_l_1d5;
	case 480ULL: goto x86_l_1e0;
	case 487ULL: goto x86_l_1e7;
	case 495ULL: goto x86_l_1ef;
	case 503ULL: goto x86_l_1f7;
	case 511ULL: goto x86_l_1ff;
	case 519ULL: goto x86_l_207;
	case 527ULL: goto x86_l_20f;
	case 535ULL: goto x86_l_217;
	case 543ULL: goto x86_l_21f;
	case 551ULL: goto x86_l_227;
	case 559ULL: goto x86_l_22f;
	case 567ULL: goto x86_l_237;
	case 575ULL: goto x86_l_23f;
	case 583ULL: goto x86_l_247;
	case 591ULL: goto x86_l_24f;
	case 596ULL: goto x86_l_254;
	case 598ULL: goto x86_l_256;
	case 602ULL: goto x86_l_25a;
	case 606ULL: goto x86_l_25e;
	case 610ULL: goto x86_l_262;
	case 618ULL: goto x86_l_26a;
	case 623ULL: goto x86_l_26f;
	case 625ULL: goto x86_l_271;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 679ULL: goto x86_l_2a7;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
	case 692ULL: goto x86_l_2b4;
	case 697ULL: goto x86_l_2b9;
	case 704ULL: goto x86_l_2c0;
	case 712ULL: goto x86_l_2c8;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 720ULL: goto x86_l_2d0;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 765ULL: goto x86_l_2fd;
	case 770ULL: goto x86_l_302;
	case 777ULL: goto x86_l_309;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 793ULL: goto x86_l_319;
	case 797ULL: goto x86_l_31d;
	case 804ULL: goto x86_l_324;
	case 815ULL: goto x86_l_32f;
	case 826ULL: goto x86_l_33a;
	case 837ULL: goto x86_l_345;
	case 848ULL: goto x86_l_350;
	case 859ULL: goto x86_l_35b;
	case 870ULL: goto x86_l_366;
	case 881ULL: goto x86_l_371;
	case 892ULL: goto x86_l_37c;
	case 903ULL: goto x86_l_387;
	case 914ULL: goto x86_l_392;
	case 925ULL: goto x86_l_39d;
	case 936ULL: goto x86_l_3a8;
	case 947ULL: goto x86_l_3b3;
	case 958ULL: goto x86_l_3be;
	case 969ULL: goto x86_l_3c9;
	case 980ULL: goto x86_l_3d4;
	case 991ULL: goto x86_l_3df;
	case 1002ULL: goto x86_l_3ea;
	case 1013ULL: goto x86_l_3f5;
	case 1024ULL: goto x86_l_400;
	case 1035ULL: goto x86_l_40b;
	case 1046ULL: goto x86_l_416;
	case 1057ULL: goto x86_l_421;
	case 1068ULL: goto x86_l_42c;
	case 1079ULL: goto x86_l_437;
	case 1090ULL: goto x86_l_442;
	case 1101ULL: goto x86_l_44d;
	case 1112ULL: goto x86_l_458;
	case 1123ULL: goto x86_l_463;
	case 1134ULL: goto x86_l_46e;
	case 1142ULL: goto x86_l_476;
	case 1150ULL: goto x86_l_47e;
	case 1158ULL: goto x86_l_486;
	case 1166ULL: goto x86_l_48e;
	case 1174ULL: goto x86_l_496;
	case 1182ULL: goto x86_l_49e;
	case 1190ULL: goto x86_l_4a6;
	case 1198ULL: goto x86_l_4ae;
	case 1206ULL: goto x86_l_4b6;
	case 1214ULL: goto x86_l_4be;
	case 1222ULL: goto x86_l_4c6;
	case 1230ULL: goto x86_l_4ce;
	case 1238ULL: goto x86_l_4d6;
	case 1246ULL: goto x86_l_4de;
	case 1254ULL: goto x86_l_4e6;
	case 1261ULL: goto x86_l_4ed;
	case 1267ULL: goto x86_l_4f3;
	case 1274ULL: goto x86_l_4fa;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1293ULL: goto x86_l_50d;
	case 1296ULL: goto x86_l_510;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1309ULL: goto x86_l_51d;
	case 1311ULL: goto x86_l_51f;
	case 1316ULL: goto x86_l_524;
	case 1319ULL: goto x86_l_527;
	case 1325ULL: goto x86_l_52d;
	case 1330ULL: goto x86_l_532;
	case 1337ULL: goto x86_l_539;
	case 1341ULL: goto x86_l_53d;
	case 1349ULL: goto x86_l_545;
	case 1354ULL: goto x86_l_54a;
	case 1361ULL: goto x86_l_551;
	case 1366ULL: goto x86_l_556;
	case 1368ULL: goto x86_l_558;
	case 1371ULL: goto x86_l_55b;
	case 1377ULL: goto x86_l_561;
	case 1381ULL: goto x86_l_565;
	case 1388ULL: goto x86_l_56c;
	case 1399ULL: goto x86_l_577;
	case 1410ULL: goto x86_l_582;
	case 1421ULL: goto x86_l_58d;
	case 1432ULL: goto x86_l_598;
	case 1443ULL: goto x86_l_5a3;
	case 1454ULL: goto x86_l_5ae;
	case 1465ULL: goto x86_l_5b9;
	case 1476ULL: goto x86_l_5c4;
	case 1487ULL: goto x86_l_5cf;
	case 1495ULL: goto x86_l_5d7;
	case 1503ULL: goto x86_l_5df;
	case 1511ULL: goto x86_l_5e7;
	case 1519ULL: goto x86_l_5ef;
	case 1527ULL: goto x86_l_5f7;
	case 1535ULL: goto x86_l_5ff;
	case 1543ULL: goto x86_l_607;
	case 1551ULL: goto x86_l_60f;
	case 1559ULL: goto x86_l_617;
	case 1567ULL: goto x86_l_61f;
	case 1575ULL: goto x86_l_627;
	case 1583ULL: goto x86_l_62f;
	case 1591ULL: goto x86_l_637;
	case 1599ULL: goto x86_l_63f;
	case 1607ULL: goto x86_l_647;
	case 1614ULL: goto x86_l_64e;
	case 1620ULL: goto x86_l_654;
	case 1627ULL: goto x86_l_65b;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1643ULL: goto x86_l_66b;
	case 1646ULL: goto x86_l_66e;
	case 1649ULL: goto x86_l_671;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1662ULL: goto x86_l_67e;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1673ULL: goto x86_l_689;
	case 1676ULL: goto x86_l_68c;
	case 1683ULL: goto x86_l_693;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1700ULL: goto x86_l_6a4;
	case 1705ULL: goto x86_l_6a9;
	case 1708ULL: goto x86_l_6ac;
	case 1710ULL: goto x86_l_6ae;
	case 1718ULL: goto x86_l_6b6;
	case 1726ULL: goto x86_l_6be;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1750ULL: goto x86_l_6d6;
	case 1758ULL: goto x86_l_6de;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1775ULL: goto x86_l_6ef;
	case 1780ULL: goto x86_l_6f4;
	case 1782ULL: goto x86_l_6f6;
	case 1790ULL: goto x86_l_6fe;
	case 1798ULL: goto x86_l_706;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1822ULL: goto x86_l_71e;
	case 1829ULL: goto x86_l_725;
	case 1833ULL: goto x86_l_729;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1853ULL: goto x86_l_73d;
	case 1858ULL: goto x86_l_742;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1873ULL: goto x86_l_751;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1902ULL: goto x86_l_76e;
	case 1904ULL: goto x86_l_770;
	case 1911ULL: goto x86_l_777;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1936ULL: goto x86_l_790;
	case 1941ULL: goto x86_l_795;
	case 1943ULL: goto x86_l_797;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1985ULL: goto x86_l_7c1;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2009ULL: goto x86_l_7d9;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2047ULL: goto x86_l_7ff;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2059ULL: goto x86_l_80b;
	case 2064ULL: goto x86_l_810;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2086ULL: goto x86_l_826;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2116ULL: goto x86_l_844;
	case 2118ULL: goto x86_l_846;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2149ULL: goto x86_l_865;
	case 2156ULL: goto x86_l_86c;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2188ULL: goto x86_l_88c;
	case 2196ULL: goto x86_l_894;
	case 2200ULL: goto x86_l_898;
	case 2205ULL: goto x86_l_89d;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2220ULL: goto x86_l_8ac;
	case 2227ULL: goto x86_l_8b3;
	case 2234ULL: goto x86_l_8ba;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2259ULL: goto x86_l_8d3;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2269ULL: goto x86_l_8dd;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 296ULL);
x86_l_a:
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: movabs rbx,0x30800000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 3332894621696ULL);
x86_l_17:
	/* 0x17: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1c:
	/* 0x1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e:
	/* 0x1e: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20:
	/* 0x20: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_23:
	/* 0x23: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b:
	/* 0x2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30:
	/* 0x30: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_37:
	/* 0x37: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3f:
	/* 0x3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41:
	/* 0x41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_44:
	/* 0x44: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_4a:
	/* 0x4a: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d:
	/* 0x4d: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51:
	/* 0x51: mov    QWORD PTR [rsp+0x120],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_59:
	/* 0x59: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62:
	/* 0x62: or     rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_65:
	/* 0x65: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6d:
	/* 0x6d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_72:
	/* 0x72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&args_map)));
x86_l_79:
	/* 0x79: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_81:
	/* 0x81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83:
	/* 0x83: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_88:
	/* 0x88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a:
	/* 0x8a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9b:
	/* 0x9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a0:
	/* 0xa0: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a8:
	/* 0xa8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ad:
	/* 0xad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af:
	/* 0xaf: test   DWORD PTR [rsp+0x80],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549757911040ULL);
x86_l_ba:
	/* 0xba: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_bf:
	/* 0xbf: jne    128 <trace_ret_file_update_time+0x128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_128;
	}
x86_l_c1:
	/* 0xc1: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_c6:
	/* 0xc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8:
	/* 0xc8: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_cd:
	/* 0xcd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d0:
	/* 0xd0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     dc <trace_ret_file_update_time+0xdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc;
	}
x86_l_d7:
	/* 0xd7: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_da:
	/* 0xda: jmp    dc <trace_ret_file_update_time+0xdc> */
	goto x86_l_dc;
x86_l_dc:
	/* 0xdc: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0:
	/* 0xe0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e5:
	/* 0xe5: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ed:
	/* 0xed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2:
	/* 0xf2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7:
	/* 0xf7: test   BYTE PTR [rsp+0x80],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 549755813890ULL);
x86_l_ff:
	/* 0xff: jne    107 <trace_ret_file_update_time+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_107;
	}
x86_l_101:
	/* 0x101: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_105:
	/* 0x105: jmp    128 <trace_ret_file_update_time+0x128> */
	goto x86_l_128;
x86_l_107:
	/* 0x107: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c:
	/* 0x10c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_113:
	/* 0x113: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_118:
	/* 0x118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a:
	/* 0x11a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: je     123 <trace_ret_file_update_time+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123;
	}
x86_l_11f:
	/* 0x11f: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121:
	/* 0x121: jmp    128 <trace_ret_file_update_time+0x128> */
	goto x86_l_128;
x86_l_123:
	/* 0x123: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0x108],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_130:
	/* 0x130: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_138:
	/* 0x138: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d:
	/* 0x13d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_144:
	/* 0x144: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_149:
	/* 0x149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b:
	/* 0x14b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_154:
	/* 0x154: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_157:
	/* 0x157: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15c:
	/* 0x15c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_163:
	/* 0x163: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_168:
	/* 0x168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a:
	/* 0x16a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16d:
	/* 0x16d: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_173:
	/* 0x173: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_180:
	/* 0x180: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_193:
	/* 0x193: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1e7:
	/* 0x1e7: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ef:
	/* 0x1ef: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f7:
	/* 0x1f7: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ff:
	/* 0x1ff: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_207:
	/* 0x207: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20f:
	/* 0x20f: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_217:
	/* 0x217: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_21f:
	/* 0x21f: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_227:
	/* 0x227: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_22f:
	/* 0x22f: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_237:
	/* 0x237: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_23f:
	/* 0x23f: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_247:
	/* 0x247: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_24f:
	/* 0x24f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_254:
	/* 0x254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256:
	/* 0x256: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25a:
	/* 0x25a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_25e:
	/* 0x25e: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_262:
	/* 0x262: mov    DWORD PTR [r14+0x70],0x308 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337928ULL);
x86_l_26a:
	/* 0x26a: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_26f:
	/* 0x26f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271:
	/* 0x271: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_274:
	/* 0x274: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_279:
	/* 0x279: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b:
	/* 0x27b: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_280:
	/* 0x280: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_284:
	/* 0x284: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_288:
	/* 0x288: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c:
	/* 0x28c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_291:
	/* 0x291: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_298:
	/* 0x298: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d:
	/* 0x29d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f:
	/* 0x29f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a4:
	/* 0x2a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: je     2ed <trace_ret_file_update_time+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed;
	}
x86_l_2a9:
	/* 0x2a9: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rsp+0xf8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2b4:
	/* 0x2b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b9:
	/* 0x2b9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_2c0:
	/* 0x2c0: lea    rsi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2c8:
	/* 0x2c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca:
	/* 0x2ca: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d0:
	/* 0x2d0: je     532 <trace_ret_file_update_time+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_532;
	}
x86_l_2d6:
	/* 0x2d6: test   BYTE PTR [r13+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_2db:
	/* 0x2db: jne    b6c <trace_ret_file_update_time+0xb6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2924ULL;
	}
x86_l_2e1:
	/* 0x2e1: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2e6:
	/* 0x2e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8:
	/* 0x2e8: jmp    c05 <trace_ret_file_update_time+0xc05> */
	return 3077ULL;
x86_l_2ed:
	/* 0x2ed: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f1:
	/* 0x2f1: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_302:
	/* 0x302: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_309:
	/* 0x309: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_319:
	/* 0x319: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31d:
	/* 0x31d: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_324:
	/* 0x324: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_32f:
	/* 0x32f: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_33a:
	/* 0x33a: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_345:
	/* 0x345: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_35b:
	/* 0x35b: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_366:
	/* 0x366: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_371:
	/* 0x371: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_37c:
	/* 0x37c: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_392:
	/* 0x392: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_3a8:
	/* 0x3a8: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3be:
	/* 0x3be: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_3ea:
	/* 0x3ea: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_400:
	/* 0x400: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_416:
	/* 0x416: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_421:
	/* 0x421: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_42c:
	/* 0x42c: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_437:
	/* 0x437: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_458:
	/* 0x458: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_486:
	/* 0x486: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_48e:
	/* 0x48e: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_496:
	/* 0x496: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_49e:
	/* 0x49e: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4a6:
	/* 0x4a6: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4b6:
	/* 0x4b6: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4be:
	/* 0x4be: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4d6:
	/* 0x4d6: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4de:
	/* 0x4de: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4e6:
	/* 0x4e6: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ed:
	/* 0x4ed: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4f3:
	/* 0x4f3: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4fa:
	/* 0x4fa: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_502:
	/* 0x502: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_507:
	/* 0x507: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_50d:
	/* 0x50d: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_510:
	/* 0x510: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_515:
	/* 0x515: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_51a:
	/* 0x51a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_51d:
	/* 0x51d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51f:
	/* 0x51f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_524:
	/* 0x524: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_527:
	/* 0x527: jne    2a9 <trace_ret_file_update_time+0x2a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a9;
	}
x86_l_52d:
	/* 0x52d: jmp    21db <trace_ret_file_update_time+0x21db> */
	return 8667ULL;
x86_l_532:
	/* 0x532: mov    eax,DWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_539:
	/* 0x539: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53d:
	/* 0x53d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_545:
	/* 0x545: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54a:
	/* 0x54a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_551:
	/* 0x551: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_556:
	/* 0x556: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_558:
	/* 0x558: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55b:
	/* 0x55b: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_561:
	/* 0x561: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_565:
	/* 0x565: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_577:
	/* 0x577: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_582:
	/* 0x582: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5a3:
	/* 0x5a3: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5ae:
	/* 0x5ae: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_5c4:
	/* 0x5c4: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5d7:
	/* 0x5d7: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5ef:
	/* 0x5ef: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5f7:
	/* 0x5f7: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5ff:
	/* 0x5ff: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_607:
	/* 0x607: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_60f:
	/* 0x60f: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_617:
	/* 0x617: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_61f:
	/* 0x61f: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_627:
	/* 0x627: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_62f:
	/* 0x62f: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_637:
	/* 0x637: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_63f:
	/* 0x63f: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_647:
	/* 0x647: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64e:
	/* 0x64e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_654:
	/* 0x654: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_65b:
	/* 0x65b: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_663:
	/* 0x663: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_668:
	/* 0x668: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_66b:
	/* 0x66b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_66e:
	/* 0x66e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_671:
	/* 0x671: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_676:
	/* 0x676: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_67b:
	/* 0x67b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_67e:
	/* 0x67e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_680:
	/* 0x680: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_683:
	/* 0x683: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_689:
	/* 0x689: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_68c:
	/* 0x68c: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_693:
	/* 0x693: lea    rbp,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_697:
	/* 0x697: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69c:
	/* 0x69c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6a4:
	/* 0x6a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a9:
	/* 0x6a9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ac:
	/* 0x6ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ae:
	/* 0x6ae: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6b6:
	/* 0x6b6: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_6be:
	/* 0x6be: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c2:
	/* 0x6c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c7:
	/* 0x6c7: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6cf:
	/* 0x6cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d4:
	/* 0x6d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d6:
	/* 0x6d6: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6de:
	/* 0x6de: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6e2:
	/* 0x6e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e7:
	/* 0x6e7: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6ef:
	/* 0x6ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f4:
	/* 0x6f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f6:
	/* 0x6f6: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6fe:
	/* 0x6fe: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_706:
	/* 0x706: lea    rdx,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_70a:
	/* 0x70a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70f:
	/* 0x70f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_717:
	/* 0x717: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_71c:
	/* 0x71c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71e:
	/* 0x71e: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_725:
	/* 0x725: mov    DWORD PTR [r15+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_729:
	/* 0x729: mov    QWORD PTR [rsp+0xd8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_731:
	/* 0x731: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_735:
	/* 0x735: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_73d:
	/* 0x73d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_742:
	/* 0x742: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_74a:
	/* 0x74a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74f:
	/* 0x74f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_751:
	/* 0x751: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_759:
	/* 0x759: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75e:
	/* 0x75e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_766:
	/* 0x766: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_76b:
	/* 0x76b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_76e:
	/* 0x76e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_770:
	/* 0x770: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_777:
	/* 0x777: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_77b:
	/* 0x77b: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_77f:
	/* 0x77f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_783:
	/* 0x783: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_788:
	/* 0x788: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_790:
	/* 0x790: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_795:
	/* 0x795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_797:
	/* 0x797: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_79e:
	/* 0x79e: mov    DWORD PTR [r15+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7a2:
	/* 0x7a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a7:
	/* 0x7a7: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7af:
	/* 0x7af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b4:
	/* 0x7b4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7b7:
	/* 0x7b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b9:
	/* 0x7b9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7c1:
	/* 0x7c1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7c5:
	/* 0x7c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ca:
	/* 0x7ca: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7d2:
	/* 0x7d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d7:
	/* 0x7d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d9:
	/* 0x7d9: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7e1:
	/* 0x7e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e6:
	/* 0x7e6: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7ee:
	/* 0x7ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f3:
	/* 0x7f3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7f6:
	/* 0x7f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f8:
	/* 0x7f8: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7ff:
	/* 0x7ff: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_803:
	/* 0x803: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_807:
	/* 0x807: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_80b:
	/* 0x80b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_810:
	/* 0x810: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_818:
	/* 0x818: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_81d:
	/* 0x81d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81f:
	/* 0x81f: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_826:
	/* 0x826: mov    DWORD PTR [r15+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_82a:
	/* 0x82a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_82f:
	/* 0x82f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_837:
	/* 0x837: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_83c:
	/* 0x83c: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_844:
	/* 0x844: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_846:
	/* 0x846: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_84e:
	/* 0x84e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_853:
	/* 0x853: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_85b:
	/* 0x85b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_860:
	/* 0x860: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_863:
	/* 0x863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_865:
	/* 0x865: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_86c:
	/* 0x86c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_870:
	/* 0x870: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_874:
	/* 0x874: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_878:
	/* 0x878: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87d:
	/* 0x87d: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_885:
	/* 0x885: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88a:
	/* 0x88a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88c:
	/* 0x88c: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_894:
	/* 0x894: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_898:
	/* 0x898: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89d:
	/* 0x89d: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a5:
	/* 0x8a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8aa:
	/* 0x8aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ac:
	/* 0x8ac: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8b3:
	/* 0x8b3: mov    DWORD PTR [rsp+0xe0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_8ba:
	/* 0x8ba: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_8c2:
	/* 0x8c2: lea    rbp,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c6:
	/* 0x8c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cb:
	/* 0x8cb: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8d3:
	/* 0x8d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d8:
	/* 0x8d8: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8dd:
	/* 0x8dd: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8e5:
	/* 0x8e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ea:
	/* 0x8ea: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
	return 2290ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2378ULL: goto x86_l_94a;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2408ULL: goto x86_l_968;
	case 2410ULL: goto x86_l_96a;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2439ULL: goto x86_l_987;
	case 2441ULL: goto x86_l_989;
	case 2448ULL: goto x86_l_990;
	case 2452ULL: goto x86_l_994;
	case 2456ULL: goto x86_l_998;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2480ULL: goto x86_l_9b0;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2498ULL: goto x86_l_9c2;
	case 2502ULL: goto x86_l_9c6;
	case 2510ULL: goto x86_l_9ce;
	case 2517ULL: goto x86_l_9d5;
	case 2522ULL: goto x86_l_9da;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2538ULL: goto x86_l_9ea;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2597ULL: goto x86_l_a25;
	case 2601ULL: goto x86_l_a29;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2640ULL: goto x86_l_a50;
	case 2648ULL: goto x86_l_a58;
	case 2651ULL: goto x86_l_a5b;
	case 2659ULL: goto x86_l_a63;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2683ULL: goto x86_l_a7b;
	case 2691ULL: goto x86_l_a83;
	case 2695ULL: goto x86_l_a87;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2712ULL: goto x86_l_a98;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2727ULL: goto x86_l_aa7;
	case 2735ULL: goto x86_l_aaf;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2760ULL: goto x86_l_ac8;
	case 2762ULL: goto x86_l_aca;
	case 2770ULL: goto x86_l_ad2;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2789ULL: goto x86_l_ae5;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2860ULL: goto x86_l_b2c;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2881ULL: goto x86_l_b41;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2911ULL: goto x86_l_b5f;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2953ULL: goto x86_l_b89;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3008ULL: goto x86_l_bc0;
	case 3013ULL: goto x86_l_bc5;
	case 3021ULL: goto x86_l_bcd;
	case 3026ULL: goto x86_l_bd2;
	case 3028ULL: goto x86_l_bd4;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3041ULL: goto x86_l_be1;
	case 3045ULL: goto x86_l_be5;
	case 3050ULL: goto x86_l_bea;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3073ULL: goto x86_l_c01;
	case 3075ULL: goto x86_l_c03;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3108ULL: goto x86_l_c24;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3129ULL: goto x86_l_c39;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3152ULL: goto x86_l_c50;
	case 3163ULL: goto x86_l_c5b;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3191ULL: goto x86_l_c77;
	case 3196ULL: goto x86_l_c7c;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3226ULL: goto x86_l_c9a;
	case 3230ULL: goto x86_l_c9e;
	case 3237ULL: goto x86_l_ca5;
	case 3240ULL: goto x86_l_ca8;
	case 3247ULL: goto x86_l_caf;
	case 3251ULL: goto x86_l_cb3;
	case 3255ULL: goto x86_l_cb7;
	case 3262ULL: goto x86_l_cbe;
	case 3269ULL: goto x86_l_cc5;
	case 3273ULL: goto x86_l_cc9;
	case 3280ULL: goto x86_l_cd0;
	case 3284ULL: goto x86_l_cd4;
	case 3291ULL: goto x86_l_cdb;
	case 3295ULL: goto x86_l_cdf;
	case 3302ULL: goto x86_l_ce6;
	case 3306ULL: goto x86_l_cea;
	case 3313ULL: goto x86_l_cf1;
	case 3320ULL: goto x86_l_cf8;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3343ULL: goto x86_l_d0f;
	case 3351ULL: goto x86_l_d17;
	case 3359ULL: goto x86_l_d1f;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3374ULL: goto x86_l_d2e;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3409ULL: goto x86_l_d51;
	case 3412ULL: goto x86_l_d54;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3428ULL: goto x86_l_d64;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3445ULL: goto x86_l_d75;
	case 3448ULL: goto x86_l_d78;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3460ULL: goto x86_l_d84;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3476ULL: goto x86_l_d94;
	case 3479ULL: goto x86_l_d97;
	case 3482ULL: goto x86_l_d9a;
	case 3489ULL: goto x86_l_da1;
	case 3492ULL: goto x86_l_da4;
	case 3494ULL: goto x86_l_da6;
	case 3498ULL: goto x86_l_daa;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3527ULL: goto x86_l_dc7;
	case 3530ULL: goto x86_l_dca;
	case 3532ULL: goto x86_l_dcc;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3583ULL: goto x86_l_dff;
	case 3589ULL: goto x86_l_e05;
	case 3596ULL: goto x86_l_e0c;
	case 3604ULL: goto x86_l_e14;
	case 3611ULL: goto x86_l_e1b;
	case 3619ULL: goto x86_l_e23;
	case 3626ULL: goto x86_l_e2a;
	case 3634ULL: goto x86_l_e32;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3654ULL: goto x86_l_e46;
	case 3662ULL: goto x86_l_e4e;
	case 3664ULL: goto x86_l_e50;
	case 3667ULL: goto x86_l_e53;
	case 3671ULL: goto x86_l_e57;
	case 3679ULL: goto x86_l_e5f;
	case 3686ULL: goto x86_l_e66;
	case 3689ULL: goto x86_l_e69;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3714ULL: goto x86_l_e82;
	case 3717ULL: goto x86_l_e85;
	case 3721ULL: goto x86_l_e89;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3728ULL: goto x86_l_e90;
	case 3736ULL: goto x86_l_e98;
	case 3744ULL: goto x86_l_ea0;
	case 3752ULL: goto x86_l_ea8;
	case 3755ULL: goto x86_l_eab;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3769ULL: goto x86_l_eb9;
	case 3771ULL: goto x86_l_ebb;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3786ULL: goto x86_l_eca;
	case 3794ULL: goto x86_l_ed2;
	case 3801ULL: goto x86_l_ed9;
	case 3804ULL: goto x86_l_edc;
	case 3806ULL: goto x86_l_ede;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3827ULL: goto x86_l_ef3;
	case 3830ULL: goto x86_l_ef6;
	case 3832ULL: goto x86_l_ef8;
	case 3835ULL: goto x86_l_efb;
	case 3837ULL: goto x86_l_efd;
	case 3840ULL: goto x86_l_f00;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3849ULL: goto x86_l_f09;
	case 3856ULL: goto x86_l_f10;
	case 3863ULL: goto x86_l_f17;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3879ULL: goto x86_l_f27;
	case 3882ULL: goto x86_l_f2a;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3897ULL: goto x86_l_f39;
	case 3899ULL: goto x86_l_f3b;
	case 3907ULL: goto x86_l_f43;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3926ULL: goto x86_l_f56;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3940ULL: goto x86_l_f64;
	case 3942ULL: goto x86_l_f66;
	case 3950ULL: goto x86_l_f6e;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3970ULL: goto x86_l_f82;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 4002ULL: goto x86_l_fa2;
	case 4009ULL: goto x86_l_fa9;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4026ULL: goto x86_l_fba;
	case 4033ULL: goto x86_l_fc1;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4053ULL: goto x86_l_fd5;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4067ULL: goto x86_l_fe3;
	case 4075ULL: goto x86_l_feb;
	case 4082ULL: goto x86_l_ff2;
	case 4085ULL: goto x86_l_ff5;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4105ULL: goto x86_l_1009;
	case 4108ULL: goto x86_l_100c;
	case 4110ULL: goto x86_l_100e;
	case 4113ULL: goto x86_l_1011;
	case 4117ULL: goto x86_l_1015;
	case 4120ULL: goto x86_l_1018;
	default: return 0xffffffffffffffffULL;
	}
x86_l_8f2:
	/* 0x8f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8f7:
	/* 0x8f7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8fa:
	/* 0x8fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8fc:
	/* 0x8fc: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_903:
	/* 0x903: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_907:
	/* 0x907: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_90b:
	/* 0x90b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_90f:
	/* 0x90f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_914:
	/* 0x914: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_91c:
	/* 0x91c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_921:
	/* 0x921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_923:
	/* 0x923: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_92b:
	/* 0x92b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_92f:
	/* 0x92f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_934:
	/* 0x934: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_93c:
	/* 0x93c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_941:
	/* 0x941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_943:
	/* 0x943: mov    eax,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_94a:
	/* 0x94a: cmp    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 128ULL);
x86_l_951:
	/* 0x951: jne    9c2 <trace_ret_file_update_time+0x9c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9c2;
	}
x86_l_953:
	/* 0x953: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_958:
	/* 0x958: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_960:
	/* 0x960: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_965:
	/* 0x965: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_968:
	/* 0x968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96a:
	/* 0x96a: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_972:
	/* 0x972: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_977:
	/* 0x977: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_97f:
	/* 0x97f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_984:
	/* 0x984: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_987:
	/* 0x987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_989:
	/* 0x989: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_990:
	/* 0x990: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_994:
	/* 0x994: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_998:
	/* 0x998: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_99c:
	/* 0x99c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a1:
	/* 0x9a1: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9a9:
	/* 0x9a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9ae:
	/* 0x9ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b0:
	/* 0x9b0: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9b7:
	/* 0x9b7: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9bb:
	/* 0x9bb: mov    eax,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_9c2:
	/* 0x9c2: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c6:
	/* 0x9c6: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_9ce:
	/* 0x9ce: lea    rbx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9d5:
	/* 0x9d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9da:
	/* 0x9da: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9e2:
	/* 0x9e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e7:
	/* 0x9e7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9ea:
	/* 0x9ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ec:
	/* 0x9ec: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9f4:
	/* 0x9f4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9f8:
	/* 0x9f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9fd:
	/* 0x9fd: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a05:
	/* 0xa05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0a:
	/* 0xa0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0c:
	/* 0xa0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a11:
	/* 0xa11: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a19:
	/* 0xa19: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a1e:
	/* 0xa1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a23:
	/* 0xa23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a25:
	/* 0xa25: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a29:
	/* 0xa29: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a2d:
	/* 0xa2d: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_a32:
	/* 0xa32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a34:
	/* 0xa34: mov    DWORD PTR [r15+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a38:
	/* 0xa38: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a3c:
	/* 0xa3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a41:
	/* 0xa41: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a49:
	/* 0xa49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4e:
	/* 0xa4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a50:
	/* 0xa50: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a58:
	/* 0xa58: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5b:
	/* 0xa5b: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_a63:
	/* 0xa63: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a67:
	/* 0xa67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a6c:
	/* 0xa6c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a74:
	/* 0xa74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a79:
	/* 0xa79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7b:
	/* 0xa7b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a83:
	/* 0xa83: mov    QWORD PTR [r15+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a87:
	/* 0xa87: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_a8f:
	/* 0xa8f: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_a93:
	/* 0xa93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a98:
	/* 0xa98: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_aa0:
	/* 0xaa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aa5:
	/* 0xaa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa7:
	/* 0xaa7: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_aaf:
	/* 0xaaf: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ab3:
	/* 0xab3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ab8:
	/* 0xab8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ac0:
	/* 0xac0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ac5:
	/* 0xac5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ac8:
	/* 0xac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aca:
	/* 0xaca: test   BYTE PTR [rsp+0x80],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 549755813890ULL);
x86_l_ad2:
	/* 0xad2: je     ad9 <trace_ret_file_update_time+0xad9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ad9;
	}
x86_l_ad4:
	/* 0xad4: or     BYTE PTR [r15+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_ad9:
	/* 0xad9: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_ae5:
	/* 0xae5: mov    QWORD PTR [r15+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_aed:
	/* 0xaed: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_af2:
	/* 0xaf2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_af7:
	/* 0xaf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af9:
	/* 0xaf9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_afe:
	/* 0xafe: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b06:
	/* 0xb06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b0b:
	/* 0xb0b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b0e:
	/* 0xb0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b10:
	/* 0xb10: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b18:
	/* 0xb18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b1d:
	/* 0xb1d: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b25:
	/* 0xb25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b2a:
	/* 0xb2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2c:
	/* 0xb2c: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b34:
	/* 0xb34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b39:
	/* 0xb39: lea    rbx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b41:
	/* 0xb41: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b44:
	/* 0xb44: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_b49:
	/* 0xb49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4b:
	/* 0xb4b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_b52:
	/* 0xb52: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_b57:
	/* 0xb57: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b5c:
	/* 0xb5c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_b5f:
	/* 0xb5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b61:
	/* 0xb61: test   BYTE PTR [r13+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_b66:
	/* 0xb66: je     2e1 <trace_ret_file_update_time+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 737ULL;
	}
x86_l_b6c:
	/* 0xb6c: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_b71:
	/* 0xb71: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_b78:
	/* 0xb78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b7d:
	/* 0xb7d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b82:
	/* 0xb82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b87:
	/* 0xb87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b89:
	/* 0xb89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b8e:
	/* 0xb8e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b93:
	/* 0xb93: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b98:
	/* 0xb98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b9d:
	/* 0xb9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9f:
	/* 0xb9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ba4:
	/* 0xba4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba9:
	/* 0xba9: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bb1:
	/* 0xbb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb6:
	/* 0xbb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb8:
	/* 0xbb8: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bc0:
	/* 0xbc0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bc5:
	/* 0xbc5: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bcd:
	/* 0xbcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bd2:
	/* 0xbd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd4:
	/* 0xbd4: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bdc:
	/* 0xbdc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: je     c03 <trace_ret_file_update_time+0xc03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c03;
	}
x86_l_be1:
	/* 0xbe1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_be5:
	/* 0xbe5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bea:
	/* 0xbea: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bf2:
	/* 0xbf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf7:
	/* 0xbf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf9:
	/* 0xbf9: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c01:
	/* 0xc01: jmp    c05 <trace_ret_file_update_time+0xc05> */
	goto x86_l_c05;
x86_l_c03:
	/* 0xc03: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c05:
	/* 0xc05: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c09:
	/* 0xc09: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0d:
	/* 0xc0d: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c11:
	/* 0xc11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c16:
	/* 0xc16: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_c1d:
	/* 0xc1d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c22:
	/* 0xc22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c24:
	/* 0xc24: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c27:
	/* 0xc27: je     c40 <trace_ret_file_update_time+0xc40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c40;
	}
x86_l_c29:
	/* 0xc29: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c2c:
	/* 0xc2c: mov    BYTE PTR [r15+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_c33:
	/* 0xc33: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c36:
	/* 0xc36: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_c39:
	/* 0xc39: jne    c40 <trace_ret_file_update_time+0xc40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c40;
	}
x86_l_c3b:
	/* 0xc3b: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_c40:
	/* 0xc40: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c45:
	/* 0xc45: cmp    ax,WORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_c4a:
	/* 0xc4a: jne    2453 <trace_ret_file_update_time+0x2453> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9299ULL;
	}
x86_l_c50:
	/* 0xc50: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_c5b:
	/* 0xc5b: mov    DWORD PTR [rsp+0x80],0x308 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755814664ULL);
x86_l_c66:
	/* 0xc66: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6b:
	/* 0xc6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c70:
	/* 0xc70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_c77:
	/* 0xc77: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7c:
	/* 0xc7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7e:
	/* 0xc7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c81:
	/* 0xc81: je     cf1 <trace_ret_file_update_time+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf1;
	}
x86_l_c83:
	/* 0xc83: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c88:
	/* 0xc88: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c90:
	/* 0xc90: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c93:
	/* 0xc93: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c95:
	/* 0xc95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c98:
	/* 0xc98: je     cf1 <trace_ret_file_update_time+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf1;
	}
x86_l_c9a:
	/* 0xc9a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c9e:
	/* 0xc9e: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_ca5:
	/* 0xca5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca8:
	/* 0xca8: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_caf:
	/* 0xcaf: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cb3:
	/* 0xcb3: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cb7:
	/* 0xcb7: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_cbe:
	/* 0xcbe: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_cc5:
	/* 0xcc5: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc9:
	/* 0xcc9: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_cd0:
	/* 0xcd0: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cd4:
	/* 0xcd4: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_cdb:
	/* 0xcdb: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cdf:
	/* 0xcdf: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_ce6:
	/* 0xce6: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cea:
	/* 0xcea: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_cf1:
	/* 0xcf1: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_cf8:
	/* 0xcf8: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cff:
	/* 0xcff: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d03:
	/* 0xd03: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_d07:
	/* 0xd07: mov    QWORD PTR [rsp+0x118],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_d0f:
	/* 0xd0f: mov    QWORD PTR [rsp+0x110],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_d17:
	/* 0xd17: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_d1f:
	/* 0xd1f: jne    d39 <trace_ret_file_update_time+0xd39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d39;
	}
x86_l_d21:
	/* 0xd21: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d24:
	/* 0xd24: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_d27:
	/* 0xd27: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d2e:
	/* 0xd2e: jne    1562 <trace_ret_file_update_time+0x1562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5474ULL;
	}
x86_l_d34:
	/* 0xd34: jmp    21db <trace_ret_file_update_time+0x21db> */
	return 8667ULL;
x86_l_d39:
	/* 0xd39: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_d40:
	/* 0xd40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: je     f09 <trace_ret_file_update_time+0xf09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f09;
	}
x86_l_d49:
	/* 0xd49: movzx  ecx,BYTE PTR [r15+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_d51:
	/* 0xd51: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_d54:
	/* 0xd54: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d57:
	/* 0xd57: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_d5a:
	/* 0xd5a: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_d5e:
	/* 0xd5e: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d61:
	/* 0xd61: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d64:
	/* 0xd64: xor    r13,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_d6b:
	/* 0xd6b: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d6e:
	/* 0xd6e: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d75:
	/* 0xd75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d78:
	/* 0xd78: je     d9a <trace_ret_file_update_time+0xd9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9a;
	}
x86_l_d7a:
	/* 0xd7a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7c:
	/* 0xd7c: cmp    BYTE PTR [r15+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_d84:
	/* 0xd84: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d87:
	/* 0xd87: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d8a:
	/* 0xd8a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d8d:
	/* 0xd8d: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d94:
	/* 0xd94: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d97:
	/* 0xd97: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d9a:
	/* 0xd9a: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_da1:
	/* 0xda1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da4:
	/* 0xda4: je     dc0 <trace_ret_file_update_time+0xdc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc0;
	}
x86_l_da6:
	/* 0xda6: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_daa:
	/* 0xdaa: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dad:
	/* 0xdad: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_db0:
	/* 0xdb0: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_db3:
	/* 0xdb3: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_dba:
	/* 0xdba: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dbd:
	/* 0xdbd: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_dc0:
	/* 0xdc0: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_dc7:
	/* 0xdc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dca:
	/* 0xdca: je     de8 <trace_ret_file_update_time+0xde8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de8;
	}
x86_l_dcc:
	/* 0xdcc: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dcf:
	/* 0xdcf: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dd4:
	/* 0xdd4: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dd8:
	/* 0xdd8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ddb:
	/* 0xddb: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_de2:
	/* 0xde2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_de5:
	/* 0xde5: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_de8:
	/* 0xde8: movzx  ebp,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ded:
	/* 0xded: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_df4:
	/* 0xdf4: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: mov    WORD PTR [rsp+0xe0],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_dff:
	/* 0xdff: je     f82 <trace_ret_file_update_time+0xf82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f82;
	}
x86_l_e05:
	/* 0xe05: mov    rax,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_e0c:
	/* 0xe0c: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_e14:
	/* 0xe14: mov    rax,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_e1b:
	/* 0xe1b: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_e23:
	/* 0xe23: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_e2a:
	/* 0xe2a: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_e32:
	/* 0xe32: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e3a:
	/* 0xe3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3f:
	/* 0xe3f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_e46:
	/* 0xe46: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e4e:
	/* 0xe4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e50:
	/* 0xe50: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e53:
	/* 0xe53: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e57:
	/* 0xe57: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e5f:
	/* 0xe5f: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e66:
	/* 0xe66: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e69:
	/* 0xe69: je     e8e <trace_ret_file_update_time+0xe8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8e;
	}
x86_l_e6b:
	/* 0xe6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e70:
	/* 0xe70: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e78:
	/* 0xe78: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e7b:
	/* 0xe7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7d:
	/* 0xe7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e80:
	/* 0xe80: je     e8e <trace_ret_file_update_time+0xe8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8e;
	}
x86_l_e82:
	/* 0xe82: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e85:
	/* 0xe85: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e89:
	/* 0xe89: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e8c:
	/* 0xe8c: jmp    e90 <trace_ret_file_update_time+0xe90> */
	goto x86_l_e90;
x86_l_e8e:
	/* 0xe8e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e90:
	/* 0xe90: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_e98:
	/* 0xe98: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ea0:
	/* 0xea0: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ea8:
	/* 0xea8: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_eab:
	/* 0xeab: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_eae:
	/* 0xeae: jb     ec6 <trace_ret_file_update_time+0xec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_ec6;
	}
x86_l_eb0:
	/* 0xeb0: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eb4:
	/* 0xeb4: je     ebb <trace_ret_file_update_time+0xebb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebb;
	}
x86_l_eb6:
	/* 0xeb6: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_eb9:
	/* 0xeb9: jbe    ec6 <trace_ret_file_update_time+0xec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ec6;
	}
x86_l_ebb:
	/* 0xebb: and    r12,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 256ULL);
x86_l_ec3:
	/* 0xec3: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec6:
	/* 0xec6: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eca:
	/* 0xeca: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ed2:
	/* 0xed2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ed9:
	/* 0xed9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_edc:
	/* 0xedc: je     f25 <trace_ret_file_update_time+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f25;
	}
x86_l_ede:
	/* 0xede: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ee6:
	/* 0xee6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eeb:
	/* 0xeeb: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ef3:
	/* 0xef3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ef6:
	/* 0xef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef8:
	/* 0xef8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_efb:
	/* 0xefb: je     f39 <trace_ret_file_update_time+0xf39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f39;
	}
x86_l_efd:
	/* 0xefd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f00:
	/* 0xf00: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f04:
	/* 0xf04: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f07:
	/* 0xf07: jmp    f3b <trace_ret_file_update_time+0xf3b> */
	goto x86_l_f3b;
x86_l_f09:
	/* 0xf09: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f10:
	/* 0xf10: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_f17:
	/* 0xf17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1a:
	/* 0xf1a: jne    d7a <trace_ret_file_update_time+0xd7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d7a;
	}
x86_l_f20:
	/* 0xf20: jmp    d9a <trace_ret_file_update_time+0xd9a> */
	goto x86_l_d9a;
x86_l_f25:
	/* 0xf25: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f27:
	/* 0xf27: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f2a:
	/* 0xf2a: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f32:
	/* 0xf32: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f35:
	/* 0xf35: jae    f5b <trace_ret_file_update_time+0xf5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f5b;
	}
x86_l_f37:
	/* 0xf37: jmp    f71 <trace_ret_file_update_time+0xf71> */
	goto x86_l_f71;
x86_l_f39:
	/* 0xf39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f3b:
	/* 0xf3b: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_f43:
	/* 0xf43: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_f4b:
	/* 0xf4b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f4e:
	/* 0xf4e: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f56:
	/* 0xf56: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_f59:
	/* 0xf59: jb     f71 <trace_ret_file_update_time+0xf71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f71;
	}
x86_l_f5b:
	/* 0xf5b: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f5f:
	/* 0xf5f: je     f66 <trace_ret_file_update_time+0xf66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f66;
	}
x86_l_f61:
	/* 0xf61: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_f64:
	/* 0xf64: jbe    f71 <trace_ret_file_update_time+0xf71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f71;
	}
x86_l_f66:
	/* 0xf66: and    r12,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 256ULL);
x86_l_f6e:
	/* 0xf6e: or     rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_f71:
	/* 0xf71: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_f74:
	/* 0xf74: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f77:
	/* 0xf77: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_f7a:
	/* 0xf7a: movzx  ebp,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_f82:
	/* 0xf82: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_f8a:
	/* 0xf8a: je     105d <trace_ret_file_update_time+0x105d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4189ULL;
	}
x86_l_f90:
	/* 0xf90: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_f95:
	/* 0xf95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f97:
	/* 0xf97: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f9b:
	/* 0xf9b: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_fa2:
	/* 0xfa2: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_fa9:
	/* 0xfa9: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_fb1:
	/* 0xfb1: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_fb3:
	/* 0xfb3: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_fba:
	/* 0xfba: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_fc1:
	/* 0xfc1: mov    WORD PTR [rsp+0x80],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fc9:
	/* 0xfc9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fce:
	/* 0xfce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_fd5:
	/* 0xfd5: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fdd:
	/* 0xfdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdf:
	/* 0xfdf: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fe3:
	/* 0xfe3: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_feb:
	/* 0xfeb: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ff2:
	/* 0xff2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff5:
	/* 0xff5: je     101a <trace_ret_file_update_time+0x101a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4122ULL;
	}
x86_l_ff7:
	/* 0xff7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ffc:
	/* 0xffc: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1004:
	/* 0x1004: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1007:
	/* 0x1007: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1009:
	/* 0x1009: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100c:
	/* 0x100c: je     101a <trace_ret_file_update_time+0x101a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4122ULL;
	}
x86_l_100e:
	/* 0x100e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1011:
	/* 0x1011: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1015:
	/* 0x1015: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1018:
	/* 0x1018: jmp    101c <trace_ret_file_update_time+0x101c> */
	return 4124ULL;
	return 4122ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4122ULL: goto x86_l_101a;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4135ULL: goto x86_l_1027;
	case 4138ULL: goto x86_l_102a;
	case 4141ULL: goto x86_l_102d;
	case 4143ULL: goto x86_l_102f;
	case 4151ULL: goto x86_l_1037;
	case 4153ULL: goto x86_l_1039;
	case 4157ULL: goto x86_l_103d;
	case 4165ULL: goto x86_l_1045;
	case 4167ULL: goto x86_l_1047;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4180ULL: goto x86_l_1054;
	case 4183ULL: goto x86_l_1057;
	case 4186ULL: goto x86_l_105a;
	case 4189ULL: goto x86_l_105d;
	case 4197ULL: goto x86_l_1065;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4235ULL: goto x86_l_108b;
	case 4243ULL: goto x86_l_1093;
	case 4247ULL: goto x86_l_1097;
	case 4252ULL: goto x86_l_109c;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4267ULL: goto x86_l_10ab;
	case 4272ULL: goto x86_l_10b0;
	case 4280ULL: goto x86_l_10b8;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4296ULL: goto x86_l_10c8;
	case 4300ULL: goto x86_l_10cc;
	case 4307ULL: goto x86_l_10d3;
	case 4314ULL: goto x86_l_10da;
	case 4317ULL: goto x86_l_10dd;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4337ULL: goto x86_l_10f1;
	case 4345ULL: goto x86_l_10f9;
	case 4347ULL: goto x86_l_10fb;
	case 4354ULL: goto x86_l_1102;
	case 4357ULL: goto x86_l_1105;
	case 4359ULL: goto x86_l_1107;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4376ULL: goto x86_l_1118;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4404ULL: goto x86_l_1134;
	case 4412ULL: goto x86_l_113c;
	case 4418ULL: goto x86_l_1142;
	case 4425ULL: goto x86_l_1149;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4449ULL: goto x86_l_1161;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4487ULL: goto x86_l_1187;
	case 4491ULL: goto x86_l_118b;
	case 4495ULL: goto x86_l_118f;
	case 4499ULL: goto x86_l_1193;
	case 4504ULL: goto x86_l_1198;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4519ULL: goto x86_l_11a7;
	case 4527ULL: goto x86_l_11af;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4569ULL: goto x86_l_11d9;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4587ULL: goto x86_l_11eb;
	case 4592ULL: goto x86_l_11f0;
	case 4599ULL: goto x86_l_11f7;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4616ULL: goto x86_l_1208;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4643ULL: goto x86_l_1223;
	case 4647ULL: goto x86_l_1227;
	case 4650ULL: goto x86_l_122a;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4663ULL: goto x86_l_1237;
	case 4666ULL: goto x86_l_123a;
	case 4674ULL: goto x86_l_1242;
	case 4680ULL: goto x86_l_1248;
	case 4685ULL: goto x86_l_124d;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4720ULL: goto x86_l_1270;
	case 4725ULL: goto x86_l_1275;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4740ULL: goto x86_l_1284;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4761ULL: goto x86_l_1299;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4771ULL: goto x86_l_12a3;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4791ULL: goto x86_l_12b7;
	case 4793ULL: goto x86_l_12b9;
	case 4800ULL: goto x86_l_12c0;
	case 4807ULL: goto x86_l_12c7;
	case 4810ULL: goto x86_l_12ca;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4830ULL: goto x86_l_12de;
	case 4838ULL: goto x86_l_12e6;
	case 4840ULL: goto x86_l_12e8;
	case 4847ULL: goto x86_l_12ef;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4860ULL: goto x86_l_12fc;
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
	case 4904ULL: goto x86_l_1328;
	case 4912ULL: goto x86_l_1330;
	case 4918ULL: goto x86_l_1336;
	case 4922ULL: goto x86_l_133a;
	case 4927ULL: goto x86_l_133f;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4937ULL: goto x86_l_1349;
	case 4944ULL: goto x86_l_1350;
	case 4951ULL: goto x86_l_1357;
	case 4954ULL: goto x86_l_135a;
	case 4962ULL: goto x86_l_1362;
	case 4967ULL: goto x86_l_1367;
	case 4974ULL: goto x86_l_136e;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5014ULL: goto x86_l_1396;
	case 5017ULL: goto x86_l_1399;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5048ULL: goto x86_l_13b8;
	case 5055ULL: goto x86_l_13bf;
	case 5058ULL: goto x86_l_13c2;
	case 5060ULL: goto x86_l_13c4;
	case 5064ULL: goto x86_l_13c8;
	case 5071ULL: goto x86_l_13cf;
	case 5078ULL: goto x86_l_13d6;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5091ULL: goto x86_l_13e3;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5166ULL: goto x86_l_142e;
	case 5173ULL: goto x86_l_1435;
	case 5176ULL: goto x86_l_1438;
	case 5178ULL: goto x86_l_143a;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5208ULL: goto x86_l_1458;
	case 5216ULL: goto x86_l_1460;
	case 5218ULL: goto x86_l_1462;
	case 5225ULL: goto x86_l_1469;
	case 5228ULL: goto x86_l_146c;
	case 5230ULL: goto x86_l_146e;
	case 5234ULL: goto x86_l_1472;
	case 5239ULL: goto x86_l_1477;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5249ULL: goto x86_l_1481;
	case 5252ULL: goto x86_l_1484;
	case 5256ULL: goto x86_l_1488;
	case 5259ULL: goto x86_l_148b;
	case 5261ULL: goto x86_l_148d;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5269ULL: goto x86_l_1495;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5291ULL: goto x86_l_14ab;
	case 5298ULL: goto x86_l_14b2;
	case 5301ULL: goto x86_l_14b5;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5321ULL: goto x86_l_14c9;
	case 5329ULL: goto x86_l_14d1;
	case 5331ULL: goto x86_l_14d3;
	case 5338ULL: goto x86_l_14da;
	case 5341ULL: goto x86_l_14dd;
	case 5343ULL: goto x86_l_14df;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5365ULL: goto x86_l_14f5;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5389ULL: goto x86_l_150d;
	case 5392ULL: goto x86_l_1510;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5411ULL: goto x86_l_1523;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5451ULL: goto x86_l_154b;
	case 5458ULL: goto x86_l_1552;
	case 5461ULL: goto x86_l_1555;
	case 5468ULL: goto x86_l_155c;
	case 5474ULL: goto x86_l_1562;
	case 5482ULL: goto x86_l_156a;
	case 5490ULL: goto x86_l_1572;
	case 5502ULL: goto x86_l_157e;
	case 5514ULL: goto x86_l_158a;
	case 5526ULL: goto x86_l_1596;
	case 5538ULL: goto x86_l_15a2;
	case 5550ULL: goto x86_l_15ae;
	case 5562ULL: goto x86_l_15ba;
	case 5574ULL: goto x86_l_15c6;
	case 5586ULL: goto x86_l_15d2;
	case 5598ULL: goto x86_l_15de;
	case 5610ULL: goto x86_l_15ea;
	case 5622ULL: goto x86_l_15f6;
	case 5630ULL: goto x86_l_15fe;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5666ULL: goto x86_l_1622;
	case 5669ULL: goto x86_l_1625;
	case 5675ULL: goto x86_l_162b;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5732ULL: goto x86_l_1664;
	case 5737ULL: goto x86_l_1669;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5807ULL: goto x86_l_16af;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5820ULL: goto x86_l_16bc;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5861ULL: goto x86_l_16e5;
	case 5867ULL: goto x86_l_16eb;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5881ULL: goto x86_l_16f9;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	default: return 0xffffffffffffffffULL;
	}
x86_l_101a:
	/* 0x101a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_101c:
	/* 0x101c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_101f:
	/* 0x101f: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1027:
	/* 0x1027: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_102a:
	/* 0x102a: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: jae    1039 <trace_ret_file_update_time+0x1039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1039;
	}
x86_l_102f:
	/* 0x102f: movzx  ebp,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_1037:
	/* 0x1037: jmp    1057 <trace_ret_file_update_time+0x1057> */
	goto x86_l_1057;
x86_l_1039:
	/* 0x1039: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_103d:
	/* 0x103d: movzx  ebp,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_1045:
	/* 0x1045: je     104c <trace_ret_file_update_time+0x104c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104c;
	}
x86_l_1047:
	/* 0x1047: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_104a:
	/* 0x104a: jbe    1057 <trace_ret_file_update_time+0x1057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1057;
	}
x86_l_104c:
	/* 0x104c: and    r15,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 216ULL);
x86_l_1054:
	/* 0x1054: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1057:
	/* 0x1057: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_105a:
	/* 0x105a: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_105d:
	/* 0x105d: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1065:
	/* 0x1065: je     1134 <trace_ret_file_update_time+0x1134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1134;
	}
x86_l_106b:
	/* 0x106b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1070:
	/* 0x1070: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1077:
	/* 0x1077: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107c:
	/* 0x107c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1084:
	/* 0x1084: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1089:
	/* 0x1089: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108b:
	/* 0x108b: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1093:
	/* 0x1093: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1097:
	/* 0x1097: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_109c:
	/* 0x109c: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10a4:
	/* 0x10a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10a9:
	/* 0x10a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ab:
	/* 0x10ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b0:
	/* 0x10b0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10b8:
	/* 0x10b8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10bd:
	/* 0x10bd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10c8:
	/* 0x10c8: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10cc:
	/* 0x10cc: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_10d3:
	/* 0x10d3: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_10da:
	/* 0x10da: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10dd:
	/* 0x10dd: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10e5:
	/* 0x10e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10ea:
	/* 0x10ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_10f1:
	/* 0x10f1: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10f9:
	/* 0x10f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fb:
	/* 0x10fb: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1102:
	/* 0x1102: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1105:
	/* 0x1105: je     1126 <trace_ret_file_update_time+0x1126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1126;
	}
x86_l_1107:
	/* 0x1107: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_110b:
	/* 0x110b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1110:
	/* 0x1110: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1115:
	/* 0x1115: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1118:
	/* 0x1118: je     1126 <trace_ret_file_update_time+0x1126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1126;
	}
x86_l_111a:
	/* 0x111a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111d:
	/* 0x111d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1121:
	/* 0x1121: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1124:
	/* 0x1124: jmp    1128 <trace_ret_file_update_time+0x1128> */
	goto x86_l_1128;
x86_l_1126:
	/* 0x1126: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1128:
	/* 0x1128: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_112b:
	/* 0x112b: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_112e:
	/* 0x112e: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1131:
	/* 0x1131: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1134:
	/* 0x1134: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_113c:
	/* 0x113c: je     123a <trace_ret_file_update_time+0x123a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_123a;
	}
x86_l_1142:
	/* 0x1142: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1149:
	/* 0x1149: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_114d:
	/* 0x114d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1152:
	/* 0x1152: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_115a:
	/* 0x115a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_115f:
	/* 0x115f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1161:
	/* 0x1161: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1169:
	/* 0x1169: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_116e:
	/* 0x116e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1176:
	/* 0x1176: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_117b:
	/* 0x117b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_117e:
	/* 0x117e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1180:
	/* 0x1180: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1187:
	/* 0x1187: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_118b:
	/* 0x118b: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_118f:
	/* 0x118f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1193:
	/* 0x1193: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1198:
	/* 0x1198: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11a0:
	/* 0x11a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a5:
	/* 0x11a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a7:
	/* 0x11a7: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11af:
	/* 0x11af: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_11b3:
	/* 0x11b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11b8:
	/* 0x11b8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11c0:
	/* 0x11c0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11c5:
	/* 0x11c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c7:
	/* 0x11c7: mov    eax,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11ce:
	/* 0x11ce: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11d2:
	/* 0x11d2: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_11d9:
	/* 0x11d9: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_11e0:
	/* 0x11e0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e3:
	/* 0x11e3: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11eb:
	/* 0x11eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11f0:
	/* 0x11f0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_11f7:
	/* 0x11f7: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11ff:
	/* 0x11ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1201:
	/* 0x1201: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1208:
	/* 0x1208: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120b:
	/* 0x120b: je     122c <trace_ret_file_update_time+0x122c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_122c;
	}
x86_l_120d:
	/* 0x120d: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1211:
	/* 0x1211: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1216:
	/* 0x1216: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1219:
	/* 0x1219: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_121b:
	/* 0x121b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: je     122c <trace_ret_file_update_time+0x122c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_122c;
	}
x86_l_1220:
	/* 0x1220: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1223:
	/* 0x1223: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1227:
	/* 0x1227: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_122a:
	/* 0x122a: jmp    122e <trace_ret_file_update_time+0x122e> */
	goto x86_l_122e;
x86_l_122c:
	/* 0x122c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_122e:
	/* 0x122e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1231:
	/* 0x1231: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1234:
	/* 0x1234: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1237:
	/* 0x1237: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_123a:
	/* 0x123a: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1242:
	/* 0x1242: je     1328 <trace_ret_file_update_time+0x1328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1328;
	}
x86_l_1248:
	/* 0x1248: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_124d:
	/* 0x124d: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1254:
	/* 0x1254: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1259:
	/* 0x1259: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1261:
	/* 0x1261: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1266:
	/* 0x1266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1268:
	/* 0x1268: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1270:
	/* 0x1270: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1275:
	/* 0x1275: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_127d:
	/* 0x127d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1282:
	/* 0x1282: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1284:
	/* 0x1284: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_128c:
	/* 0x128c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1291:
	/* 0x1291: lea    r15,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1299:
	/* 0x1299: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_129c:
	/* 0x129c: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_12a1:
	/* 0x12a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a3:
	/* 0x12a3: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_12a7:
	/* 0x12a7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_12ac:
	/* 0x12ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12af:
	/* 0x12af: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12b4:
	/* 0x12b4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12b7:
	/* 0x12b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b9:
	/* 0x12b9: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_12c0:
	/* 0x12c0: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_12c7:
	/* 0x12c7: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12ca:
	/* 0x12ca: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12d2:
	/* 0x12d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d7:
	/* 0x12d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_12de:
	/* 0x12de: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12e6:
	/* 0x12e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e8:
	/* 0x12e8: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12ef:
	/* 0x12ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12f2:
	/* 0x12f2: je     1312 <trace_ret_file_update_time+0x1312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1312;
	}
x86_l_12f4:
	/* 0x12f4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12f9:
	/* 0x12f9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12fc:
	/* 0x12fc: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_12ff:
	/* 0x12ff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1301:
	/* 0x1301: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: je     1312 <trace_ret_file_update_time+0x1312> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1312;
	}
x86_l_1306:
	/* 0x1306: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1309:
	/* 0x1309: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_130d:
	/* 0x130d: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1310:
	/* 0x1310: jmp    1314 <trace_ret_file_update_time+0x1314> */
	goto x86_l_1314;
x86_l_1312:
	/* 0x1312: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1314:
	/* 0x1314: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1317:
	/* 0x1317: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_131a:
	/* 0x131a: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_131d:
	/* 0x131d: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1320:
	/* 0x1320: movzx  ebp,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_1328:
	/* 0x1328: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1330:
	/* 0x1330: je     13b8 <trace_ret_file_update_time+0x13b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b8;
	}
x86_l_1336:
	/* 0x1336: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_133a:
	/* 0x133a: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_133f:
	/* 0x133f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1342:
	/* 0x1342: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1347:
	/* 0x1347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1349:
	/* 0x1349: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1350:
	/* 0x1350: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1357:
	/* 0x1357: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_135a:
	/* 0x135a: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1362:
	/* 0x1362: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1367:
	/* 0x1367: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_136e:
	/* 0x136e: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1376:
	/* 0x1376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1378:
	/* 0x1378: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_137f:
	/* 0x137f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1382:
	/* 0x1382: je     13a2 <trace_ret_file_update_time+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a2;
	}
x86_l_1384:
	/* 0x1384: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1389:
	/* 0x1389: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_138c:
	/* 0x138c: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_138f:
	/* 0x138f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1391:
	/* 0x1391: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1394:
	/* 0x1394: je     13a2 <trace_ret_file_update_time+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a2;
	}
x86_l_1396:
	/* 0x1396: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1399:
	/* 0x1399: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_139d:
	/* 0x139d: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13a0:
	/* 0x13a0: jmp    13a4 <trace_ret_file_update_time+0x13a4> */
	goto x86_l_13a4;
x86_l_13a2:
	/* 0x13a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a4:
	/* 0x13a4: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13a7:
	/* 0x13a7: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_13aa:
	/* 0x13aa: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ad:
	/* 0x13ad: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_13b0:
	/* 0x13b0: movzx  ebp,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_13b8:
	/* 0x13b8: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_13bf:
	/* 0x13bf: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_13c2:
	/* 0x13c2: je     142e <trace_ret_file_update_time+0x142e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_142e;
	}
x86_l_13c4:
	/* 0x13c4: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c8:
	/* 0x13c8: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13cf:
	/* 0x13cf: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_13d6:
	/* 0x13d6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d9:
	/* 0x13d9: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13de:
	/* 0x13de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e3:
	/* 0x13e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_13ea:
	/* 0x13ea: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ef:
	/* 0x13ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f1:
	/* 0x13f1: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13f8:
	/* 0x13f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: je     1420 <trace_ret_file_update_time+0x1420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1420;
	}
x86_l_13fd:
	/* 0x13fd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1402:
	/* 0x1402: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_140a:
	/* 0x140a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_140d:
	/* 0x140d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_140f:
	/* 0x140f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1412:
	/* 0x1412: je     1420 <trace_ret_file_update_time+0x1420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1420;
	}
x86_l_1414:
	/* 0x1414: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1417:
	/* 0x1417: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_141b:
	/* 0x141b: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_141e:
	/* 0x141e: jmp    1422 <trace_ret_file_update_time+0x1422> */
	goto x86_l_1422;
x86_l_1420:
	/* 0x1420: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1422:
	/* 0x1422: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1425:
	/* 0x1425: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1428:
	/* 0x1428: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_142b:
	/* 0x142b: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_142e:
	/* 0x142e: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1435:
	/* 0x1435: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1438:
	/* 0x1438: je     149b <trace_ret_file_update_time+0x149b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_149b;
	}
x86_l_143a:
	/* 0x143a: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1441:
	/* 0x1441: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1444:
	/* 0x1444: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_144c:
	/* 0x144c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1451:
	/* 0x1451: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1458:
	/* 0x1458: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1460:
	/* 0x1460: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1462:
	/* 0x1462: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1469:
	/* 0x1469: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146c:
	/* 0x146c: je     148d <trace_ret_file_update_time+0x148d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148d;
	}
x86_l_146e:
	/* 0x146e: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1472:
	/* 0x1472: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1477:
	/* 0x1477: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_147a:
	/* 0x147a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_147c:
	/* 0x147c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_147f:
	/* 0x147f: je     148d <trace_ret_file_update_time+0x148d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148d;
	}
x86_l_1481:
	/* 0x1481: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1484:
	/* 0x1484: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1488:
	/* 0x1488: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_148b:
	/* 0x148b: jmp    148f <trace_ret_file_update_time+0x148f> */
	goto x86_l_148f;
x86_l_148d:
	/* 0x148d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148f:
	/* 0x148f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1492:
	/* 0x1492: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1495:
	/* 0x1495: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1498:
	/* 0x1498: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_149b:
	/* 0x149b: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_14a2:
	/* 0x14a2: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_14a5:
	/* 0x14a5: je     152c <trace_ret_file_update_time+0x152c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152c;
	}
x86_l_14ab:
	/* 0x14ab: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_14b2:
	/* 0x14b2: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14b5:
	/* 0x14b5: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c2:
	/* 0x14c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_14c9:
	/* 0x14c9: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14d1:
	/* 0x14d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d3:
	/* 0x14d3: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14da:
	/* 0x14da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14dd:
	/* 0x14dd: je     151e <trace_ret_file_update_time+0x151e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_151e;
	}
x86_l_14df:
	/* 0x14df: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_14e2:
	/* 0x14e2: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14e7:
	/* 0x14e7: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14eb:
	/* 0x14eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f0:
	/* 0x14f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14f3:
	/* 0x14f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f5:
	/* 0x14f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f8:
	/* 0x14f8: jne    1512 <trace_ret_file_update_time+0x1512> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1512;
	}
x86_l_14fa:
	/* 0x14fa: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14ff:
	/* 0x14ff: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1503:
	/* 0x1503: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1508:
	/* 0x1508: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_150b:
	/* 0x150b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150d:
	/* 0x150d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1510:
	/* 0x1510: je     151e <trace_ret_file_update_time+0x151e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_151e;
	}
x86_l_1512:
	/* 0x1512: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1515:
	/* 0x1515: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1519:
	/* 0x1519: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_151c:
	/* 0x151c: jmp    1520 <trace_ret_file_update_time+0x1520> */
	goto x86_l_1520;
x86_l_151e:
	/* 0x151e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1520:
	/* 0x1520: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1523:
	/* 0x1523: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1526:
	/* 0x1526: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1529:
	/* 0x1529: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_152c:
	/* 0x152c: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1533:
	/* 0x1533: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: je     1544 <trace_ret_file_update_time+0x1544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1544;
	}
x86_l_1538:
	/* 0x1538: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_153d:
	/* 0x153d: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1541:
	/* 0x1541: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1544:
	/* 0x1544: and    r13,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_154b:
	/* 0x154b: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1552:
	/* 0x1552: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1555:
	/* 0x1555: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_155c:
	/* 0x155c: je     21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8667ULL;
	}
x86_l_1562:
	/* 0x1562: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_156a:
	/* 0x156a: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1572:
	/* 0x1572: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_157e:
	/* 0x157e: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_158a:
	/* 0x158a: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1596:
	/* 0x1596: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_15a2:
	/* 0x15a2: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_15ae:
	/* 0x15ae: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_15ba:
	/* 0x15ba: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_15c6:
	/* 0x15c6: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_15d2:
	/* 0x15d2: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_15de:
	/* 0x15de: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_15ea:
	/* 0x15ea: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_15f6:
	/* 0x15f6: mov    r12,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_15fe:
	/* 0x15fe: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1601:
	/* 0x1601: je     1754 <trace_ret_file_update_time+0x1754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5972ULL;
	}
x86_l_1607:
	/* 0x1607: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_160f:
	/* 0x160f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1614:
	/* 0x1614: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_161b:
	/* 0x161b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1620:
	/* 0x1620: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1622:
	/* 0x1622: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1625:
	/* 0x1625: je     1760 <trace_ret_file_update_time+0x1760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5984ULL;
	}
x86_l_162b:
	/* 0x162b: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_162e:
	/* 0x162e: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1633:
	/* 0x1633: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1638:
	/* 0x1638: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_163d:
	/* 0x163d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1642:
	/* 0x1642: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1644:
	/* 0x1644: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1649:
	/* 0x1649: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164e:
	/* 0x164e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1653:
	/* 0x1653: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1658:
	/* 0x1658: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165d:
	/* 0x165d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1662:
	/* 0x1662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1664:
	/* 0x1664: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_1669:
	/* 0x1669: jne    1767 <trace_ret_file_update_time+0x1767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5991ULL;
	}
x86_l_166f:
	/* 0x166f: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1674:
	/* 0x1674: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1679:
	/* 0x1679: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167e:
	/* 0x167e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1683:
	/* 0x1683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1685:
	/* 0x1685: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_168a:
	/* 0x168a: lea    rax,[r12-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_168f:
	/* 0x168f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1694:
	/* 0x1694: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1699:
	/* 0x1699: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169e:
	/* 0x169e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16a3:
	/* 0x16a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a8:
	/* 0x16a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16aa:
	/* 0x16aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16af:
	/* 0x16af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b4:
	/* 0x16b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b9:
	/* 0x16b9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16bc:
	/* 0x16bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16be:
	/* 0x16be: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16c3:
	/* 0x16c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16c8:
	/* 0x16c8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16cc:
	/* 0x16cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16d1:
	/* 0x16d1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16d6:
	/* 0x16d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16db:
	/* 0x16db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16dd:
	/* 0x16dd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e2:
	/* 0x16e2: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16e5:
	/* 0x16e5: je     1784 <trace_ret_file_update_time+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6020ULL;
	}
x86_l_16eb:
	/* 0x16eb: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f0:
	/* 0x16f0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16f3:
	/* 0x16f3: je     1784 <trace_ret_file_update_time+0x1784> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6020ULL;
	}
x86_l_16f9:
	/* 0x16f9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16fd:
	/* 0x16fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1702:
	/* 0x1702: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 5895ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5906ULL: goto x86_l_1712;
	case 5911ULL: goto x86_l_1717;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5929ULL: goto x86_l_1729;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5942ULL: goto x86_l_1736;
	case 5948ULL: goto x86_l_173c;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5974ULL: goto x86_l_1756;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6003ULL: goto x86_l_1773;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6023ULL: goto x86_l_1787;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6071ULL: goto x86_l_17b7;
	case 6076ULL: goto x86_l_17bc;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6113ULL: goto x86_l_17e1;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6147ULL: goto x86_l_1803;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6181ULL: goto x86_l_1825;
	case 6183ULL: goto x86_l_1827;
	case 6188ULL: goto x86_l_182c;
	case 6191ULL: goto x86_l_182f;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6203ULL: goto x86_l_183b;
	case 6207ULL: goto x86_l_183f;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6224ULL: goto x86_l_1850;
	case 6228ULL: goto x86_l_1854;
	case 6230ULL: goto x86_l_1856;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6246ULL: goto x86_l_1866;
	case 6251ULL: goto x86_l_186b;
	case 6257ULL: goto x86_l_1871;
	case 6260ULL: goto x86_l_1874;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6270ULL: goto x86_l_187e;
	case 6272ULL: goto x86_l_1880;
	case 6275ULL: goto x86_l_1883;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6304ULL: goto x86_l_18a0;
	case 6306ULL: goto x86_l_18a2;
	case 6312ULL: goto x86_l_18a8;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6364ULL: goto x86_l_18dc;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6393ULL: goto x86_l_18f9;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6431ULL: goto x86_l_191f;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6446ULL: goto x86_l_192e;
	case 6451ULL: goto x86_l_1933;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6506ULL: goto x86_l_196a;
	case 6511ULL: goto x86_l_196f;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6521ULL: goto x86_l_1979;
	case 6527ULL: goto x86_l_197f;
	case 6532ULL: goto x86_l_1984;
	case 6535ULL: goto x86_l_1987;
	case 6541ULL: goto x86_l_198d;
	case 6545ULL: goto x86_l_1991;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6562ULL: goto x86_l_19a2;
	case 6566ULL: goto x86_l_19a6;
	case 6568ULL: goto x86_l_19a8;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6605ULL: goto x86_l_19cd;
	case 6613ULL: goto x86_l_19d5;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6654ULL: goto x86_l_19fe;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6677ULL: goto x86_l_1a15;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6771ULL: goto x86_l_1a73;
	case 6773ULL: goto x86_l_1a75;
	case 6778ULL: goto x86_l_1a7a;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6811ULL: goto x86_l_1a9b;
	case 6816ULL: goto x86_l_1aa0;
	case 6821ULL: goto x86_l_1aa5;
	case 6826ULL: goto x86_l_1aaa;
	case 6829ULL: goto x86_l_1aad;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6845ULL: goto x86_l_1abd;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6894ULL: goto x86_l_1aee;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6943ULL: goto x86_l_1b1f;
	case 6954ULL: goto x86_l_1b2a;
	case 6962ULL: goto x86_l_1b32;
	case 6970ULL: goto x86_l_1b3a;
	case 6978ULL: goto x86_l_1b42;
	case 6981ULL: goto x86_l_1b45;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7028ULL: goto x86_l_1b74;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7070ULL: goto x86_l_1b9e;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7087ULL: goto x86_l_1baf;
	case 7095ULL: goto x86_l_1bb7;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7123ULL: goto x86_l_1bd3;
	case 7127ULL: goto x86_l_1bd7;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7144ULL: goto x86_l_1be8;
	case 7146ULL: goto x86_l_1bea;
	case 7148ULL: goto x86_l_1bec;
	case 7156ULL: goto x86_l_1bf4;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7173ULL: goto x86_l_1c05;
	case 7181ULL: goto x86_l_1c0d;
	case 7184ULL: goto x86_l_1c10;
	case 7192ULL: goto x86_l_1c18;
	case 7199ULL: goto x86_l_1c1f;
	case 7207ULL: goto x86_l_1c27;
	case 7214ULL: goto x86_l_1c2e;
	case 7216ULL: goto x86_l_1c30;
	case 7225ULL: goto x86_l_1c39;
	case 7231ULL: goto x86_l_1c3f;
	case 7233ULL: goto x86_l_1c41;
	case 7241ULL: goto x86_l_1c49;
	case 7245ULL: goto x86_l_1c4d;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7264ULL: goto x86_l_1c60;
	case 7267ULL: goto x86_l_1c63;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7280ULL: goto x86_l_1c70;
	case 7287ULL: goto x86_l_1c77;
	case 7295ULL: goto x86_l_1c7f;
	case 7302ULL: goto x86_l_1c86;
	case 7304ULL: goto x86_l_1c88;
	case 7313ULL: goto x86_l_1c91;
	case 7319ULL: goto x86_l_1c97;
	case 7321ULL: goto x86_l_1c99;
	case 7329ULL: goto x86_l_1ca1;
	case 7333ULL: goto x86_l_1ca5;
	case 7340ULL: goto x86_l_1cac;
	case 7345ULL: goto x86_l_1cb1;
	case 7350ULL: goto x86_l_1cb6;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7368ULL: goto x86_l_1cc8;
	case 7375ULL: goto x86_l_1ccf;
	case 7383ULL: goto x86_l_1cd7;
	case 7390ULL: goto x86_l_1cde;
	case 7392ULL: goto x86_l_1ce0;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7409ULL: goto x86_l_1cf1;
	case 7413ULL: goto x86_l_1cf5;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7445ULL: goto x86_l_1d15;
	case 7448ULL: goto x86_l_1d18;
	case 7456ULL: goto x86_l_1d20;
	case 7463ULL: goto x86_l_1d27;
	case 7471ULL: goto x86_l_1d2f;
	case 7478ULL: goto x86_l_1d36;
	case 7480ULL: goto x86_l_1d38;
	case 7489ULL: goto x86_l_1d41;
	case 7495ULL: goto x86_l_1d47;
	case 7497ULL: goto x86_l_1d49;
	case 7505ULL: goto x86_l_1d51;
	case 7509ULL: goto x86_l_1d55;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7536ULL: goto x86_l_1d70;
	case 7544ULL: goto x86_l_1d78;
	case 7551ULL: goto x86_l_1d7f;
	case 7558ULL: goto x86_l_1d86;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7596ULL: goto x86_l_1dac;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1707:
	/* 0x1707: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_170c:
	/* 0x170c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170e:
	/* 0x170e: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1712:
	/* 0x1712: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1717:
	/* 0x1717: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1719:
	/* 0x1719: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_171f:
	/* 0x171f: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1721:
	/* 0x1721: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1723:
	/* 0x1723: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1729:
	/* 0x1729: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_172c:
	/* 0x172c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1731:
	/* 0x1731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1733:
	/* 0x1733: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1736:
	/* 0x1736: jl     18ae <trace_ret_file_update_time+0x18ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18ae;
	}
x86_l_173c:
	/* 0x173c: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_1743:
	/* 0x1743: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_1748:
	/* 0x1748: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_174a:
	/* 0x174a: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174f:
	/* 0x174f: jmp    17f1 <trace_ret_file_update_time+0x17f1> */
	goto x86_l_17f1;
x86_l_1754:
	/* 0x1754: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1756:
	/* 0x1756: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1758:
	/* 0x1758: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175b:
	/* 0x175b: jmp    1b3a <trace_ret_file_update_time+0x1b3a> */
	goto x86_l_1b3a;
x86_l_1760:
	/* 0x1760: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1762:
	/* 0x1762: jmp    19de <trace_ret_file_update_time+0x19de> */
	goto x86_l_19de;
x86_l_1767:
	/* 0x1767: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_176c:
	/* 0x176c: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1773:
	/* 0x1773: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1776:
	/* 0x1776: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_177b:
	/* 0x177b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177d:
	/* 0x177d: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177f:
	/* 0x177f: jmp    19d5 <trace_ret_file_update_time+0x19d5> */
	goto x86_l_19d5;
x86_l_1784:
	/* 0x1784: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1787:
	/* 0x1787: jne    18ae <trace_ret_file_update_time+0x18ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18ae;
	}
x86_l_178d:
	/* 0x178d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1792:
	/* 0x1792: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1797:
	/* 0x1797: je     18ae <trace_ret_file_update_time+0x18ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ae;
	}
x86_l_179d:
	/* 0x179d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17a2:
	/* 0x17a2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a7:
	/* 0x17a7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_17ab:
	/* 0x17ab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b0:
	/* 0x17b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b5:
	/* 0x17b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b7:
	/* 0x17b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17bc:
	/* 0x17bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c1:
	/* 0x17c1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c6:
	/* 0x17c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17cb:
	/* 0x17cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17cd:
	/* 0x17cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17d2:
	/* 0x17d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d7:
	/* 0x17d7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17dc:
	/* 0x17dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17e1:
	/* 0x17e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e3:
	/* 0x17e3: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e8:
	/* 0x17e8: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_17ec:
	/* 0x17ec: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_17f1:
	/* 0x17f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17f6:
	/* 0x17f6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17fb:
	/* 0x17fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1800:
	/* 0x1800: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1803:
	/* 0x1803: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1806:
	/* 0x1806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1808:
	/* 0x1808: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_180d:
	/* 0x180d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1812:
	/* 0x1812: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1816:
	/* 0x1816: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_181b:
	/* 0x181b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1820:
	/* 0x1820: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1825:
	/* 0x1825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1827:
	/* 0x1827: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_182c:
	/* 0x182c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_182f:
	/* 0x182f: je     189d <trace_ret_file_update_time+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189d;
	}
x86_l_1831:
	/* 0x1831: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1836:
	/* 0x1836: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1839:
	/* 0x1839: je     189d <trace_ret_file_update_time+0x189d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189d;
	}
x86_l_183b:
	/* 0x183b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_183f:
	/* 0x183f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1844:
	/* 0x1844: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1849:
	/* 0x1849: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_184e:
	/* 0x184e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1850:
	/* 0x1850: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1854:
	/* 0x1854: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1856:
	/* 0x1856: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_185c:
	/* 0x185c: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_185e:
	/* 0x185e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1860:
	/* 0x1860: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_19b8;
	}
x86_l_1866:
	/* 0x1866: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_186b:
	/* 0x186b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1871:
	/* 0x1871: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1874:
	/* 0x1874: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1879:
	/* 0x1879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187b:
	/* 0x187b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_187e:
	/* 0x187e: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_18a2;
	}
x86_l_1880:
	/* 0x1880: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1883:
	/* 0x1883: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1889:
	/* 0x1889: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_188e:
	/* 0x188e: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1890:
	/* 0x1890: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1895:
	/* 0x1895: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1898:
	/* 0x1898: jmp    193e <trace_ret_file_update_time+0x193e> */
	goto x86_l_193e;
x86_l_189d:
	/* 0x189d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_18a0:
	/* 0x18a0: je     18e3 <trace_ret_file_update_time+0x18e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18e3;
	}
x86_l_18a2:
	/* 0x18a2: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_18a8:
	/* 0x18a8: jne    19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19b8;
	}
x86_l_18ae:
	/* 0x18ae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b3:
	/* 0x18b3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18b7:
	/* 0x18b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18bc:
	/* 0x18bc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18c1:
	/* 0x18c1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_18c6:
	/* 0x18c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c8:
	/* 0x18c8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cd:
	/* 0x18cd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_18d2:
	/* 0x18d2: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_18d5:
	/* 0x18d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18da:
	/* 0x18da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18dc:
	/* 0x18dc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18de:
	/* 0x18de: jmp    19cd <trace_ret_file_update_time+0x19cd> */
	goto x86_l_19cd;
x86_l_18e3:
	/* 0x18e3: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e8:
	/* 0x18e8: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_18ed:
	/* 0x18ed: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18a2;
	}
x86_l_18ef:
	/* 0x18ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18f4:
	/* 0x18f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18f9:
	/* 0x18f9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18fd:
	/* 0x18fd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1902:
	/* 0x1902: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1907:
	/* 0x1907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1909:
	/* 0x1909: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_190e:
	/* 0x190e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1913:
	/* 0x1913: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1918:
	/* 0x1918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_191d:
	/* 0x191d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191f:
	/* 0x191f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1924:
	/* 0x1924: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1929:
	/* 0x1929: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192e:
	/* 0x192e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1933:
	/* 0x1933: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1935:
	/* 0x1935: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193a:
	/* 0x193a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_193e:
	/* 0x193e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1943:
	/* 0x1943: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1948:
	/* 0x1948: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194d:
	/* 0x194d: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1950:
	/* 0x1950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1952:
	/* 0x1952: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1957:
	/* 0x1957: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_195c:
	/* 0x195c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1960:
	/* 0x1960: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1965:
	/* 0x1965: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_196a:
	/* 0x196a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_196f:
	/* 0x196f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1971:
	/* 0x1971: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1976:
	/* 0x1976: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1979:
	/* 0x1979: je     21ec <trace_ret_file_update_time+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8684ULL;
	}
x86_l_197f:
	/* 0x197f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1984:
	/* 0x1984: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1987:
	/* 0x1987: je     21ec <trace_ret_file_update_time+0x21ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8684ULL;
	}
x86_l_198d:
	/* 0x198d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1991:
	/* 0x1991: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1996:
	/* 0x1996: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_199b:
	/* 0x199b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_19a0:
	/* 0x19a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a2:
	/* 0x19a2: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_19a6:
	/* 0x19a6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_19a8:
	/* 0x19a8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19ae:
	/* 0x19ae: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_19b0:
	/* 0x19b0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19b2:
	/* 0x19b2: jae    2256 <trace_ret_file_update_time+0x2256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8790ULL;
	}
x86_l_19b8:
	/* 0x19b8: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_19ba:
	/* 0x19ba: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_19bc:
	/* 0x19bc: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_19c1:
	/* 0x19c1: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_19c6:
	/* 0x19c6: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_19cd:
	/* 0x19cd: mov    r12,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_19d5:
	/* 0x19d5: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19db:
	/* 0x19db: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19de:
	/* 0x19de: mov    QWORD PTR [rsp+0x80],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19e6:
	/* 0x19e6: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_19ea:
	/* 0x19ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19ef:
	/* 0x19ef: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19f4:
	/* 0x19f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19f9:
	/* 0x19f9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19fc:
	/* 0x19fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fe:
	/* 0x19fe: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a07:
	/* 0x1a07: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a15:
	/* 0x1a15: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a19:
	/* 0x1a19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a1e:
	/* 0x1a1e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a23:
	/* 0x1a23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a28:
	/* 0x1a28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2a:
	/* 0x1a2a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2f:
	/* 0x1a2f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a34:
	/* 0x1a34: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1a38:
	/* 0x1a38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a3d:
	/* 0x1a3d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a42:
	/* 0x1a42: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a47:
	/* 0x1a47: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a4a:
	/* 0x1a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4c:
	/* 0x1a4c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a50:
	/* 0x1a50: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a55:
	/* 0x1a55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a5a:
	/* 0x1a5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5f:
	/* 0x1a5f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a64:
	/* 0x1a64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a69:
	/* 0x1a69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6b:
	/* 0x1a6b: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a70:
	/* 0x1a70: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1a73:
	/* 0x1a73: js     1a99 <trace_ret_file_update_time+0x1a99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a99;
	}
x86_l_1a75:
	/* 0x1a75: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a7f:
	/* 0x1a7f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a84:
	/* 0x1a84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: imul   rbx,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RBX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1a92:
	/* 0x1a92: add    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1a97:
	/* 0x1a97: jmp    1a9b <trace_ret_file_update_time+0x1a9b> */
	goto x86_l_1a9b;
x86_l_1a99:
	/* 0x1a99: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9b:
	/* 0x1a9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa0:
	/* 0x1aa0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1aad:
	/* 0x1aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aaf:
	/* 0x1aaf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ab9:
	/* 0x1ab9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1abd:
	/* 0x1abd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac2:
	/* 0x1ac2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac7:
	/* 0x1ac7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac9:
	/* 0x1ac9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ace:
	/* 0x1ace: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad3:
	/* 0x1ad3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1add:
	/* 0x1add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adf:
	/* 0x1adf: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae9:
	/* 0x1ae9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aee:
	/* 0x1aee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af3:
	/* 0x1af3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1af6:
	/* 0x1af6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af8:
	/* 0x1af8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1afd:
	/* 0x1afd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b02:
	/* 0x1b02: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b06:
	/* 0x1b06: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0b:
	/* 0x1b0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b10:
	/* 0x1b10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b12:
	/* 0x1b12: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b17:
	/* 0x1b17: mov    DWORD PTR [rsp+0xc0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1b32:
	/* 0x1b32: mov    QWORD PTR [rsp+0xd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    rcx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1b42:
	/* 0x1b42: mov    ecx,DWORD PTR [rcx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b45:
	/* 0x1b45: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b49:
	/* 0x1b49: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b53:
	/* 0x1b53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b58:
	/* 0x1b58: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_modification_map)));
x86_l_1b5f:
	/* 0x1b5f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b64:
	/* 0x1b64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b66:
	/* 0x1b66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b69:
	/* 0x1b69: je     1b74 <trace_ret_file_update_time+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b74;
	}
x86_l_1b6b:
	/* 0x1b6b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: jne    21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8667ULL;
	}
x86_l_1b74:
	/* 0x1b74: mov    DWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b81:
	/* 0x1b81: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&file_modification_map)));
x86_l_1b88:
	/* 0x1b88: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b8d:
	/* 0x1b8d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b92:
	/* 0x1b92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b94:
	/* 0x1b94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b96:
	/* 0x1b96: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b9e:
	/* 0x1b9e: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1ba4:
	/* 0x1ba4: ja     1c1f <trace_ret_file_update_time+0x1c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c1f;
	}
x86_l_1ba6:
	/* 0x1ba6: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1baf:
	/* 0x1baf: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1bbf:
	/* 0x1bbf: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1bc4:
	/* 0x1bc4: ja     1c1f <trace_ret_file_update_time+0x1c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c1f;
	}
x86_l_1bc6:
	/* 0x1bc6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1bcb:
	/* 0x1bcb: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bd3:
	/* 0x1bd3: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1bd7:
	/* 0x1bd7: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1bde:
	/* 0x1bde: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1be3:
	/* 0x1be3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1be6:
	/* 0x1be6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be8:
	/* 0x1be8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bea:
	/* 0x1bea: jle    1c1f <trace_ret_file_update_time+0x1c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1c1f;
	}
x86_l_1bec:
	/* 0x1bec: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bf4:
	/* 0x1bf4: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1bfb:
	/* 0x1bfb: ja     1c1f <trace_ret_file_update_time+0x1c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c1f;
	}
x86_l_1bfd:
	/* 0x1bfd: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1c05:
	/* 0x1c05: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c0d:
	/* 0x1c0d: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1c10:
	/* 0x1c10: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c18:
	/* 0x1c18: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1c1f:
	/* 0x1c1f: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c27:
	/* 0x1c27: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1c2e:
	/* 0x1c2e: ja     1c77 <trace_ret_file_update_time+0x1c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c77;
	}
x86_l_1c30:
	/* 0x1c30: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1c39:
	/* 0x1c39: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1c3f:
	/* 0x1c3f: ja     1c77 <trace_ret_file_update_time+0x1c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c77;
	}
x86_l_1c41:
	/* 0x1c41: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c49:
	/* 0x1c49: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c4d:
	/* 0x1c4d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1c54:
	/* 0x1c54: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c59:
	/* 0x1c59: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c5e:
	/* 0x1c5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c60:
	/* 0x1c60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c63:
	/* 0x1c63: js     1c77 <trace_ret_file_update_time+0x1c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c77;
	}
x86_l_1c65:
	/* 0x1c65: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1c68:
	/* 0x1c68: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c70:
	/* 0x1c70: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1c77:
	/* 0x1c77: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c7f:
	/* 0x1c7f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1c86:
	/* 0x1c86: ja     1ccf <trace_ret_file_update_time+0x1ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ccf;
	}
x86_l_1c88:
	/* 0x1c88: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1c91:
	/* 0x1c91: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1c97:
	/* 0x1c97: ja     1ccf <trace_ret_file_update_time+0x1ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ccf;
	}
x86_l_1c99:
	/* 0x1c99: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ca1:
	/* 0x1ca1: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ca5:
	/* 0x1ca5: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1cac:
	/* 0x1cac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb1:
	/* 0x1cb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb6:
	/* 0x1cb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb8:
	/* 0x1cb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cbb:
	/* 0x1cbb: js     1ccf <trace_ret_file_update_time+0x1ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ccf;
	}
x86_l_1cbd:
	/* 0x1cbd: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cc8:
	/* 0x1cc8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ccf:
	/* 0x1ccf: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1cd7:
	/* 0x1cd7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1cde:
	/* 0x1cde: ja     1d27 <trace_ret_file_update_time+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d27;
	}
x86_l_1ce0:
	/* 0x1ce0: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1ce9:
	/* 0x1ce9: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1cef:
	/* 0x1cef: ja     1d27 <trace_ret_file_update_time+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d27;
	}
x86_l_1cf1:
	/* 0x1cf1: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1cf5:
	/* 0x1cf5: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1cfc:
	/* 0x1cfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d01:
	/* 0x1d01: lea    rdx,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1d09:
	/* 0x1d09: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d0e:
	/* 0x1d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d10:
	/* 0x1d10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d13:
	/* 0x1d13: js     1d27 <trace_ret_file_update_time+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d27;
	}
x86_l_1d15:
	/* 0x1d15: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1d18:
	/* 0x1d18: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d20:
	/* 0x1d20: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d27:
	/* 0x1d27: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d2f:
	/* 0x1d2f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1d36:
	/* 0x1d36: ja     1d7f <trace_ret_file_update_time+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d7f;
	}
x86_l_1d38:
	/* 0x1d38: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1d41:
	/* 0x1d41: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1d47:
	/* 0x1d47: ja     1d7f <trace_ret_file_update_time+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d7f;
	}
x86_l_1d49:
	/* 0x1d49: lea    rdx,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d51:
	/* 0x1d51: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1d55:
	/* 0x1d55: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d61:
	/* 0x1d61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d6b:
	/* 0x1d6b: js     1d7f <trace_ret_file_update_time+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d7f;
	}
x86_l_1d6d:
	/* 0x1d6d: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1d70:
	/* 0x1d70: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d78:
	/* 0x1d78: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    r13,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1d86:
	/* 0x1d86: lea    r12,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d8f:
	/* 0x1d8f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d94:
	/* 0x1d94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d99:
	/* 0x1d99: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d9c:
	/* 0x1d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9e:
	/* 0x1d9e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1da3:
	/* 0x1da3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1da8:
	/* 0x1da8: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dac:
	/* 0x1dac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1db1:
	/* 0x1db1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1db6:
	/* 0x1db6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dbb:
	/* 0x1dbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbd:
	/* 0x1dbd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dc2:
	/* 0x1dc2: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1dc6:
	/* 0x1dc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dcb:
	/* 0x1dcb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd5:
	/* 0x1dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd7:
	/* 0x1dd7: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 7644ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7644ULL: goto x86_l_1ddc;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7669ULL: goto x86_l_1df5;
	case 7673ULL: goto x86_l_1df9;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7692ULL: goto x86_l_1e0c;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7722ULL: goto x86_l_1e2a;
	case 7726ULL: goto x86_l_1e2e;
	case 7730ULL: goto x86_l_1e32;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7743ULL: goto x86_l_1e3f;
	case 7748ULL: goto x86_l_1e44;
	case 7753ULL: goto x86_l_1e49;
	case 7755ULL: goto x86_l_1e4b;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7778ULL: goto x86_l_1e62;
	case 7781ULL: goto x86_l_1e65;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7832ULL: goto x86_l_1e98;
	case 7834ULL: goto x86_l_1e9a;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7867ULL: goto x86_l_1ebb;
	case 7871ULL: goto x86_l_1ebf;
	case 7875ULL: goto x86_l_1ec3;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7920ULL: goto x86_l_1ef0;
	case 7924ULL: goto x86_l_1ef4;
	case 7928ULL: goto x86_l_1ef8;
	case 7932ULL: goto x86_l_1efc;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7951ULL: goto x86_l_1f0f;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7983ULL: goto x86_l_1f2f;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8007ULL: goto x86_l_1f47;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8027ULL: goto x86_l_1f5b;
	case 8030ULL: goto x86_l_1f5e;
	case 8032ULL: goto x86_l_1f60;
	case 8036ULL: goto x86_l_1f64;
	case 8040ULL: goto x86_l_1f68;
	case 8044ULL: goto x86_l_1f6c;
	case 8048ULL: goto x86_l_1f70;
	case 8053ULL: goto x86_l_1f75;
	case 8058ULL: goto x86_l_1f7a;
	case 8063ULL: goto x86_l_1f7f;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8091ULL: goto x86_l_1f9b;
	case 8095ULL: goto x86_l_1f9f;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8142ULL: goto x86_l_1fce;
	case 8146ULL: goto x86_l_1fd2;
	case 8150ULL: goto x86_l_1fd6;
	case 8154ULL: goto x86_l_1fda;
	case 8158ULL: goto x86_l_1fde;
	case 8163ULL: goto x86_l_1fe3;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8179ULL: goto x86_l_1ff3;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8270ULL: goto x86_l_204e;
	case 8274ULL: goto x86_l_2052;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8285ULL: goto x86_l_205d;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8304ULL: goto x86_l_2070;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8350ULL: goto x86_l_209e;
	case 8354ULL: goto x86_l_20a2;
	case 8359ULL: goto x86_l_20a7;
	case 8364ULL: goto x86_l_20ac;
	case 8369ULL: goto x86_l_20b1;
	case 8372ULL: goto x86_l_20b4;
	case 8374ULL: goto x86_l_20b6;
	case 8379ULL: goto x86_l_20bb;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8393ULL: goto x86_l_20c9;
	case 8398ULL: goto x86_l_20ce;
	case 8401ULL: goto x86_l_20d1;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8427ULL: goto x86_l_20eb;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8517ULL: goto x86_l_2145;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8567ULL: goto x86_l_2177;
	case 8571ULL: goto x86_l_217b;
	case 8579ULL: goto x86_l_2183;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8603ULL: goto x86_l_219b;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8629ULL: goto x86_l_21b5;
	case 8632ULL: goto x86_l_21b8;
	case 8638ULL: goto x86_l_21be;
	case 8642ULL: goto x86_l_21c2;
	case 8647ULL: goto x86_l_21c7;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8667ULL: goto x86_l_21db;
	case 8669ULL: goto x86_l_21dd;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8777ULL: goto x86_l_2249;
	case 8779ULL: goto x86_l_224b;
	case 8784ULL: goto x86_l_2250;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8801ULL: goto x86_l_2261;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8811ULL: goto x86_l_226b;
	case 8814ULL: goto x86_l_226e;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8862ULL: goto x86_l_229e;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8913ULL: goto x86_l_22d1;
	case 8915ULL: goto x86_l_22d3;
	case 8919ULL: goto x86_l_22d7;
	case 8924ULL: goto x86_l_22dc;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8958ULL: goto x86_l_22fe;
	case 8963ULL: goto x86_l_2303;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8979ULL: goto x86_l_2313;
	case 8982ULL: goto x86_l_2316;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9004ULL: goto x86_l_232c;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9017ULL: goto x86_l_2339;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9075ULL: goto x86_l_2373;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9114ULL: goto x86_l_239a;
	case 9118ULL: goto x86_l_239e;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9197ULL: goto x86_l_23ed;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9230ULL: goto x86_l_240e;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9251ULL: goto x86_l_2423;
	case 9254ULL: goto x86_l_2426;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ddc:
	/* 0x1ddc: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1de0:
	/* 0x1de0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1de5:
	/* 0x1de5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dea:
	/* 0x1dea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1def:
	/* 0x1def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df1:
	/* 0x1df1: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df5:
	/* 0x1df5: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1df9:
	/* 0x1df9: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e02:
	/* 0x1e02: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e07:
	/* 0x1e07: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e0c:
	/* 0x1e0c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e0f:
	/* 0x1e0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e11:
	/* 0x1e11: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e16:
	/* 0x1e16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e1b:
	/* 0x1e1b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e20:
	/* 0x1e20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e25:
	/* 0x1e25: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e28:
	/* 0x1e28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2a:
	/* 0x1e2a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e2e:
	/* 0x1e2e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e32:
	/* 0x1e32: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1e36:
	/* 0x1e36: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e3a:
	/* 0x1e3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e3f:
	/* 0x1e3f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e44:
	/* 0x1e44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e49:
	/* 0x1e49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4b:
	/* 0x1e4b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e53:
	/* 0x1e53: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e58:
	/* 0x1e58: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e5d:
	/* 0x1e5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e62:
	/* 0x1e62: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e65:
	/* 0x1e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e67:
	/* 0x1e67: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e6c:
	/* 0x1e6c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e70:
	/* 0x1e70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e75:
	/* 0x1e75: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e7f:
	/* 0x1e7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e81:
	/* 0x1e81: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e86:
	/* 0x1e86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e8b:
	/* 0x1e8b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e90:
	/* 0x1e90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e95:
	/* 0x1e95: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e98:
	/* 0x1e98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9a:
	/* 0x1e9a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9e:
	/* 0x1e9e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1ea2:
	/* 0x1ea2: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ea6:
	/* 0x1ea6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eaf:
	/* 0x1eaf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eb9:
	/* 0x1eb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ebb:
	/* 0x1ebb: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ec8:
	/* 0x1ec8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ed5:
	/* 0x1ed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed7:
	/* 0x1ed7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1edc:
	/* 0x1edc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ee1:
	/* 0x1ee1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee6:
	/* 0x1ee6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1eee:
	/* 0x1eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef0:
	/* 0x1ef0: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ef4:
	/* 0x1ef4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1ef8:
	/* 0x1ef8: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1efc:
	/* 0x1efc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f00:
	/* 0x1f00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f05:
	/* 0x1f05: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f0a:
	/* 0x1f0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f0f:
	/* 0x1f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f11:
	/* 0x1f11: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f16:
	/* 0x1f16: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f1f:
	/* 0x1f1f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f24:
	/* 0x1f24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f29:
	/* 0x1f29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2b:
	/* 0x1f2b: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f2f:
	/* 0x1f2f: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f33:
	/* 0x1f33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f38:
	/* 0x1f38: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f42:
	/* 0x1f42: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f45:
	/* 0x1f45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f47:
	/* 0x1f47: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f51:
	/* 0x1f51: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f56:
	/* 0x1f56: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f5e:
	/* 0x1f5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f60:
	/* 0x1f60: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f64:
	/* 0x1f64: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1f68:
	/* 0x1f68: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f6c:
	/* 0x1f6c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f70:
	/* 0x1f70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f75:
	/* 0x1f75: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f7a:
	/* 0x1f7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f7f:
	/* 0x1f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f81:
	/* 0x1f81: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f86:
	/* 0x1f86: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f8f:
	/* 0x1f8f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f94:
	/* 0x1f94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f99:
	/* 0x1f99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9b:
	/* 0x1f9b: cmp    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_1f9f:
	/* 0x1f9f: jne    1ff7 <trace_ret_file_update_time+0x1ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff7;
	}
x86_l_1fa1:
	/* 0x1fa1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fa6:
	/* 0x1fa6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fab:
	/* 0x1fab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fb3:
	/* 0x1fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb5:
	/* 0x1fb5: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fba:
	/* 0x1fba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fbf:
	/* 0x1fbf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fc9:
	/* 0x1fc9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fcc:
	/* 0x1fcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fce:
	/* 0x1fce: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fd2:
	/* 0x1fd2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1fd6:
	/* 0x1fd6: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1fda:
	/* 0x1fda: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fde:
	/* 0x1fde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fe3:
	/* 0x1fe3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fed:
	/* 0x1fed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fef:
	/* 0x1fef: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ff3:
	/* 0x1ff3: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ff7:
	/* 0x1ff7: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fff:
	/* 0x1fff: lea    r12,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2006:
	/* 0x2006: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_200b:
	/* 0x200b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2010:
	/* 0x2010: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2015:
	/* 0x2015: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2018:
	/* 0x2018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201a:
	/* 0x201a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_201f:
	/* 0x201f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2023:
	/* 0x2023: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2028:
	/* 0x2028: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_202d:
	/* 0x202d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2032:
	/* 0x2032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2034:
	/* 0x2034: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2039:
	/* 0x2039: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_203e:
	/* 0x203e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2043:
	/* 0x2043: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2048:
	/* 0x2048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204a:
	/* 0x204a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_204e:
	/* 0x204e: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2052:
	/* 0x2052: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2057:
	/* 0x2057: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2059:
	/* 0x2059: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_205d:
	/* 0x205d: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2061:
	/* 0x2061: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2066:
	/* 0x2066: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_206b:
	/* 0x206b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2070:
	/* 0x2070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2072:
	/* 0x2072: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2077:
	/* 0x2077: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_207b:
	/* 0x207b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2080:
	/* 0x2080: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2084:
	/* 0x2084: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2089:
	/* 0x2089: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_208e:
	/* 0x208e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2093:
	/* 0x2093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2095:
	/* 0x2095: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_209a:
	/* 0x209a: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_209e:
	/* 0x209e: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_20a2:
	/* 0x20a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a7:
	/* 0x20a7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20ac:
	/* 0x20ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b1:
	/* 0x20b1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_20b4:
	/* 0x20b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b6:
	/* 0x20b6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20bb:
	/* 0x20bb: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20bf:
	/* 0x20bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20c4:
	/* 0x20c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20c9:
	/* 0x20c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ce:
	/* 0x20ce: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_20d1:
	/* 0x20d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20d3:
	/* 0x20d3: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_20d8:
	/* 0x20d8: je     20df <trace_ret_file_update_time+0x20df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20df;
	}
x86_l_20da:
	/* 0x20da: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_20df:
	/* 0x20df: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_20e3:
	/* 0x20e3: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_20eb:
	/* 0x20eb: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_20f3:
	/* 0x20f3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_20f8:
	/* 0x20f8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20fd:
	/* 0x20fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ff:
	/* 0x20ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2104:
	/* 0x2104: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2109:
	/* 0x2109: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210e:
	/* 0x210e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2111:
	/* 0x2111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2113:
	/* 0x2113: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2118:
	/* 0x2118: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_211d:
	/* 0x211d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2122:
	/* 0x2122: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2127:
	/* 0x2127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2129:
	/* 0x2129: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_212e:
	/* 0x212e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2133:
	/* 0x2133: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2138:
	/* 0x2138: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_213b:
	/* 0x213b: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2140:
	/* 0x2140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2142:
	/* 0x2142: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2145:
	/* 0x2145: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_2149:
	/* 0x2149: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_214e:
	/* 0x214e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2153:
	/* 0x2153: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2156:
	/* 0x2156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2158:
	/* 0x2158: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215d:
	/* 0x215d: mov    rdi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2165:
	/* 0x2165: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_216a:
	/* 0x216a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_216d:
	/* 0x216d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216f:
	/* 0x216f: mov    rax,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2177:
	/* 0x2177: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_217b:
	/* 0x217b: mov    rbx,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2183:
	/* 0x2183: je     21a3 <trace_ret_file_update_time+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a3;
	}
x86_l_2185:
	/* 0x2185: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_218a:
	/* 0x218a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2191:
	/* 0x2191: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2196:
	/* 0x2196: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2199:
	/* 0x2199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219b:
	/* 0x219b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_219d:
	/* 0x219d: js     21a3 <trace_ret_file_update_time+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_21a3;
	}
x86_l_219f:
	/* 0x219f: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21a3:
	/* 0x21a3: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21ab:
	/* 0x21ab: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_21b0:
	/* 0x21b0: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_21b5:
	/* 0x21b5: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_21b8:
	/* 0x21b8: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_21be:
	/* 0x21be: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_21c2:
	/* 0x21c2: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_21c7:
	/* 0x21c7: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_21ce:
	/* 0x21ce: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_21d3:
	/* 0x21d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21d6:
	/* 0x21d6: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_21d9:
	/* 0x21d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21db:
	/* 0x21db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21dd:
	/* 0x21dd: add    rsp,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_21e4:
	/* 0x21e4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_21e6:
	/* 0x21e6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_21e7:
	/* 0x21e7: jmp    3531 <trace_ret_file_update_time+0x3531> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_21ec:
	/* 0x21ec: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21ef:
	/* 0x21ef: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_21f5:
	/* 0x21f5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fa:
	/* 0x21fa: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_21ff:
	/* 0x21ff: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2205:
	/* 0x2205: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_220a:
	/* 0x220a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220f:
	/* 0x220f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2213:
	/* 0x2213: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2218:
	/* 0x2218: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_221d:
	/* 0x221d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221f:
	/* 0x221f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2224:
	/* 0x2224: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2229:
	/* 0x2229: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222e:
	/* 0x222e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2233:
	/* 0x2233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2235:
	/* 0x2235: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_223a:
	/* 0x223a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223f:
	/* 0x223f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2244:
	/* 0x2244: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2249:
	/* 0x2249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224b:
	/* 0x224b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2250:
	/* 0x2250: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2254:
	/* 0x2254: jmp    228c <trace_ret_file_update_time+0x228c> */
	goto x86_l_228c;
x86_l_2256:
	/* 0x2256: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_225b:
	/* 0x225b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2261:
	/* 0x2261: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2264:
	/* 0x2264: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2269:
	/* 0x2269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226b:
	/* 0x226b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_226e:
	/* 0x226e: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2274:
	/* 0x2274: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2277:
	/* 0x2277: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_227d:
	/* 0x227d: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2282:
	/* 0x2282: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2284:
	/* 0x2284: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2289:
	/* 0x2289: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_228c:
	/* 0x228c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2291:
	/* 0x2291: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2296:
	/* 0x2296: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_229b:
	/* 0x229b: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_229e:
	/* 0x229e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a0:
	/* 0x22a0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a5:
	/* 0x22a5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22aa:
	/* 0x22aa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22ae:
	/* 0x22ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22b3:
	/* 0x22b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b8:
	/* 0x22b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22bd:
	/* 0x22bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bf:
	/* 0x22bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c4:
	/* 0x22c4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_22c7:
	/* 0x22c7: je     2336 <trace_ret_file_update_time+0x2336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2336;
	}
x86_l_22c9:
	/* 0x22c9: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22ce:
	/* 0x22ce: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22d1:
	/* 0x22d1: je     2336 <trace_ret_file_update_time+0x2336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2336;
	}
x86_l_22d3:
	/* 0x22d3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22d7:
	/* 0x22d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22dc:
	/* 0x22dc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22e1:
	/* 0x22e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22e6:
	/* 0x22e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e8:
	/* 0x22e8: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_22ec:
	/* 0x22ec: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22ee:
	/* 0x22ee: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_22f4:
	/* 0x22f4: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_22f6:
	/* 0x22f6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22f8:
	/* 0x22f8: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_22fe:
	/* 0x22fe: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2303:
	/* 0x2303: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2309:
	/* 0x2309: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_230c:
	/* 0x230c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2311:
	/* 0x2311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2313:
	/* 0x2313: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2316:
	/* 0x2316: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_231c:
	/* 0x231c: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_231f:
	/* 0x231f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2325:
	/* 0x2325: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_232a:
	/* 0x232a: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_232c:
	/* 0x232c: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2331:
	/* 0x2331: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2334:
	/* 0x2334: jmp    239e <trace_ret_file_update_time+0x239e> */
	goto x86_l_239e;
x86_l_2336:
	/* 0x2336: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2339:
	/* 0x2339: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_233f:
	/* 0x233f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2344:
	/* 0x2344: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2349:
	/* 0x2349: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_234f:
	/* 0x234f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2354:
	/* 0x2354: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2359:
	/* 0x2359: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_235d:
	/* 0x235d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2362:
	/* 0x2362: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2367:
	/* 0x2367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2369:
	/* 0x2369: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_236e:
	/* 0x236e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2373:
	/* 0x2373: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2378:
	/* 0x2378: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_237d:
	/* 0x237d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237f:
	/* 0x237f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2384:
	/* 0x2384: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2389:
	/* 0x2389: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_238e:
	/* 0x238e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2393:
	/* 0x2393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2395:
	/* 0x2395: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239a:
	/* 0x239a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_239e:
	/* 0x239e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23a3:
	/* 0x23a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23a8:
	/* 0x23a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ad:
	/* 0x23ad: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_23b0:
	/* 0x23b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b2:
	/* 0x23b2: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23b7:
	/* 0x23b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23bc:
	/* 0x23bc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_23c0:
	/* 0x23c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23c5:
	/* 0x23c5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23ca:
	/* 0x23ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23cf:
	/* 0x23cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d1:
	/* 0x23d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d6:
	/* 0x23d6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: je     2485 <trace_ret_file_update_time+0x2485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9349ULL;
	}
x86_l_23df:
	/* 0x23df: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23e4:
	/* 0x23e4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23e7:
	/* 0x23e7: je     2485 <trace_ret_file_update_time+0x2485> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9349ULL;
	}
x86_l_23ed:
	/* 0x23ed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_23f1:
	/* 0x23f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f6:
	/* 0x23f6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23fb:
	/* 0x23fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2400:
	/* 0x2400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2402:
	/* 0x2402: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2406:
	/* 0x2406: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2408:
	/* 0x2408: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_240e:
	/* 0x240e: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2410:
	/* 0x2410: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2412:
	/* 0x2412: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2418:
	/* 0x2418: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_241d:
	/* 0x241d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2423:
	/* 0x2423: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2426:
	/* 0x2426: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
	return 9259ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9273ULL: goto x86_l_2439;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9291ULL: goto x86_l_244b;
	case 9294ULL: goto x86_l_244e;
	case 9299ULL: goto x86_l_2453;
	case 9306ULL: goto x86_l_245a;
	case 9309ULL: goto x86_l_245d;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9328ULL: goto x86_l_2470;
	case 9334ULL: goto x86_l_2476;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9352ULL: goto x86_l_2488;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9384ULL: goto x86_l_24a8;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9468ULL: goto x86_l_24fc;
	case 9473ULL: goto x86_l_2501;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9521ULL: goto x86_l_2531;
	case 9524ULL: goto x86_l_2534;
	case 9526ULL: goto x86_l_2536;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9547ULL: goto x86_l_254b;
	case 9551ULL: goto x86_l_254f;
	case 9553ULL: goto x86_l_2551;
	case 9559ULL: goto x86_l_2557;
	case 9561ULL: goto x86_l_2559;
	case 9563ULL: goto x86_l_255b;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9792ULL: goto x86_l_2640;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9802ULL: goto x86_l_264a;
	case 9804ULL: goto x86_l_264c;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9831ULL: goto x86_l_2667;
	case 9837ULL: goto x86_l_266d;
	case 9839ULL: goto x86_l_266f;
	case 9841ULL: goto x86_l_2671;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9871ULL: goto x86_l_268f;
	case 9877ULL: goto x86_l_2695;
	case 9880ULL: goto x86_l_2698;
	case 9886ULL: goto x86_l_269e;
	case 9891ULL: goto x86_l_26a3;
	case 9893ULL: goto x86_l_26a5;
	case 9898ULL: goto x86_l_26aa;
	case 9900ULL: goto x86_l_26ac;
	case 9903ULL: goto x86_l_26af;
	case 9909ULL: goto x86_l_26b5;
	case 9914ULL: goto x86_l_26ba;
	case 9919ULL: goto x86_l_26bf;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9949ULL: goto x86_l_26dd;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10031ULL: goto x86_l_272f;
	case 10036ULL: goto x86_l_2734;
	case 10041ULL: goto x86_l_2739;
	case 10045ULL: goto x86_l_273d;
	case 10050ULL: goto x86_l_2742;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10070ULL: goto x86_l_2756;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10080ULL: goto x86_l_2760;
	case 10082ULL: goto x86_l_2762;
	case 10086ULL: goto x86_l_2766;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10101ULL: goto x86_l_2775;
	case 10103ULL: goto x86_l_2777;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10119ULL: goto x86_l_2787;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10136ULL: goto x86_l_2798;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10146ULL: goto x86_l_27a2;
	case 10149ULL: goto x86_l_27a5;
	case 10155ULL: goto x86_l_27ab;
	case 10158ULL: goto x86_l_27ae;
	case 10164ULL: goto x86_l_27b4;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10213ULL: goto x86_l_27e5;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10261ULL: goto x86_l_2815;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10292ULL: goto x86_l_2834;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10350ULL: goto x86_l_286e;
	case 10355ULL: goto x86_l_2873;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10364ULL: goto x86_l_287c;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10381ULL: goto x86_l_288d;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10393ULL: goto x86_l_2899;
	case 10395ULL: goto x86_l_289b;
	case 10397ULL: goto x86_l_289d;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10414ULL: goto x86_l_28ae;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10427ULL: goto x86_l_28bb;
	case 10433ULL: goto x86_l_28c1;
	case 10436ULL: goto x86_l_28c4;
	case 10442ULL: goto x86_l_28ca;
	case 10447ULL: goto x86_l_28cf;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10475ULL: goto x86_l_28eb;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10491ULL: goto x86_l_28fb;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10585ULL: goto x86_l_2959;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10636ULL: goto x86_l_298c;
	case 10638ULL: goto x86_l_298e;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10665ULL: goto x86_l_29a9;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10702ULL: goto x86_l_29ce;
	case 10705ULL: goto x86_l_29d1;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10734ULL: goto x86_l_29ee;
	case 10737ULL: goto x86_l_29f1;
	case 10743ULL: goto x86_l_29f7;
	case 10748ULL: goto x86_l_29fc;
	case 10753ULL: goto x86_l_2a01;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10773ULL: goto x86_l_2a15;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10838ULL: goto x86_l_2a56;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	default: return 0xffffffffffffffffULL;
	}
x86_l_242b:
	/* 0x242b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242d:
	/* 0x242d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2430:
	/* 0x2430: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2436:
	/* 0x2436: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2439:
	/* 0x2439: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_243f:
	/* 0x243f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2444:
	/* 0x2444: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2446:
	/* 0x2446: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_244b:
	/* 0x244b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_244e:
	/* 0x244e: jmp    24ed <trace_ret_file_update_time+0x24ed> */
	goto x86_l_24ed;
x86_l_2453:
	/* 0x2453: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_245a:
	/* 0x245a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_245d:
	/* 0x245d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2461:
	/* 0x2461: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2466:
	/* 0x2466: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_246b:
	/* 0x246b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246d:
	/* 0x246d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2470:
	/* 0x2470: jne    21db <trace_ret_file_update_time+0x21db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8667ULL;
	}
x86_l_2476:
	/* 0x2476: movzx  eax,WORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_247b:
	/* 0x247b: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2480:
	/* 0x2480: jmp    c50 <trace_ret_file_update_time+0xc50> */
	return 3152ULL;
x86_l_2485:
	/* 0x2485: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2488:
	/* 0x2488: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_248e:
	/* 0x248e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2493:
	/* 0x2493: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2498:
	/* 0x2498: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_249e:
	/* 0x249e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24a3:
	/* 0x24a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a8:
	/* 0x24a8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24ac:
	/* 0x24ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b1:
	/* 0x24b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24b6:
	/* 0x24b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b8:
	/* 0x24b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24bd:
	/* 0x24bd: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c2:
	/* 0x24c2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c7:
	/* 0x24c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24cc:
	/* 0x24cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ce:
	/* 0x24ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24d3:
	/* 0x24d3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d8:
	/* 0x24d8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24dd:
	/* 0x24dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e2:
	/* 0x24e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e4:
	/* 0x24e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e9:
	/* 0x24e9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24ed:
	/* 0x24ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24f2:
	/* 0x24f2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24f7:
	/* 0x24f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24fc:
	/* 0x24fc: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2501:
	/* 0x2501: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2503:
	/* 0x2503: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2508:
	/* 0x2508: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_250d:
	/* 0x250d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2511:
	/* 0x2511: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2516:
	/* 0x2516: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_251b:
	/* 0x251b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2520:
	/* 0x2520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2522:
	/* 0x2522: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2527:
	/* 0x2527: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_252a:
	/* 0x252a: je     2596 <trace_ret_file_update_time+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2596;
	}
x86_l_252c:
	/* 0x252c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2531:
	/* 0x2531: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2534:
	/* 0x2534: je     2596 <trace_ret_file_update_time+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2596;
	}
x86_l_2536:
	/* 0x2536: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_253a:
	/* 0x253a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_253f:
	/* 0x253f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2544:
	/* 0x2544: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2549:
	/* 0x2549: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254b:
	/* 0x254b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_254f:
	/* 0x254f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2551:
	/* 0x2551: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2557:
	/* 0x2557: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2559:
	/* 0x2559: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_255b:
	/* 0x255b: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2561:
	/* 0x2561: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2566:
	/* 0x2566: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_256c:
	/* 0x256c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_256f:
	/* 0x256f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2574:
	/* 0x2574: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2576:
	/* 0x2576: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2579:
	/* 0x2579: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_257f:
	/* 0x257f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2582:
	/* 0x2582: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2588:
	/* 0x2588: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_258d:
	/* 0x258d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_258f:
	/* 0x258f: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2594:
	/* 0x2594: jmp    2603 <trace_ret_file_update_time+0x2603> */
	goto x86_l_2603;
x86_l_2596:
	/* 0x2596: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2599:
	/* 0x2599: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_259f:
	/* 0x259f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25a4:
	/* 0x25a4: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_25a9:
	/* 0x25a9: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_25af:
	/* 0x25af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25b4:
	/* 0x25b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b9:
	/* 0x25b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25bd:
	/* 0x25bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c2:
	/* 0x25c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25c7:
	/* 0x25c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c9:
	/* 0x25c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25ce:
	/* 0x25ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25d3:
	/* 0x25d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25d8:
	/* 0x25d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25dd:
	/* 0x25dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25df:
	/* 0x25df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25e4:
	/* 0x25e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e9:
	/* 0x25e9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25ee:
	/* 0x25ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f3:
	/* 0x25f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f5:
	/* 0x25f5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25fa:
	/* 0x25fa: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25fe:
	/* 0x25fe: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2603:
	/* 0x2603: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2608:
	/* 0x2608: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_260d:
	/* 0x260d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2612:
	/* 0x2612: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2617:
	/* 0x2617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2619:
	/* 0x2619: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_261e:
	/* 0x261e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2623:
	/* 0x2623: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2627:
	/* 0x2627: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_262c:
	/* 0x262c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2631:
	/* 0x2631: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2636:
	/* 0x2636: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2638:
	/* 0x2638: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263d:
	/* 0x263d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2640:
	/* 0x2640: je     26ac <trace_ret_file_update_time+0x26ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ac;
	}
x86_l_2642:
	/* 0x2642: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2647:
	/* 0x2647: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_264a:
	/* 0x264a: je     26ac <trace_ret_file_update_time+0x26ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ac;
	}
x86_l_264c:
	/* 0x264c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2650:
	/* 0x2650: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2655:
	/* 0x2655: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_265a:
	/* 0x265a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_265f:
	/* 0x265f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2661:
	/* 0x2661: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2665:
	/* 0x2665: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2667:
	/* 0x2667: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_266d:
	/* 0x266d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_266f:
	/* 0x266f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2671:
	/* 0x2671: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2677:
	/* 0x2677: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_267c:
	/* 0x267c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2682:
	/* 0x2682: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2685:
	/* 0x2685: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_268a:
	/* 0x268a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268c:
	/* 0x268c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_268f:
	/* 0x268f: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2695:
	/* 0x2695: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2698:
	/* 0x2698: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_269e:
	/* 0x269e: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_26a3:
	/* 0x26a3: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26a5:
	/* 0x26a5: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26aa:
	/* 0x26aa: jmp    2719 <trace_ret_file_update_time+0x2719> */
	goto x86_l_2719;
x86_l_26ac:
	/* 0x26ac: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26af:
	/* 0x26af: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_26b5:
	/* 0x26b5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ba:
	/* 0x26ba: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_26bf:
	/* 0x26bf: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_26c5:
	/* 0x26c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26ca:
	/* 0x26ca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26cf:
	/* 0x26cf: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26d3:
	/* 0x26d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d8:
	/* 0x26d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26dd:
	/* 0x26dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26df:
	/* 0x26df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26e4:
	/* 0x26e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e9:
	/* 0x26e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ee:
	/* 0x26ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26f3:
	/* 0x26f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f5:
	/* 0x26f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26fa:
	/* 0x26fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ff:
	/* 0x26ff: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2704:
	/* 0x2704: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2709:
	/* 0x2709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270b:
	/* 0x270b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2710:
	/* 0x2710: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2714:
	/* 0x2714: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2719:
	/* 0x2719: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_271e:
	/* 0x271e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2723:
	/* 0x2723: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2728:
	/* 0x2728: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_272d:
	/* 0x272d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272f:
	/* 0x272f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2734:
	/* 0x2734: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2739:
	/* 0x2739: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_273d:
	/* 0x273d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2742:
	/* 0x2742: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2747:
	/* 0x2747: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_274c:
	/* 0x274c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274e:
	/* 0x274e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2753:
	/* 0x2753: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2756:
	/* 0x2756: je     27c2 <trace_ret_file_update_time+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27c2;
	}
x86_l_2758:
	/* 0x2758: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_275d:
	/* 0x275d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2760:
	/* 0x2760: je     27c2 <trace_ret_file_update_time+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27c2;
	}
x86_l_2762:
	/* 0x2762: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2766:
	/* 0x2766: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_276b:
	/* 0x276b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2770:
	/* 0x2770: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2775:
	/* 0x2775: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2777:
	/* 0x2777: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_277b:
	/* 0x277b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_277d:
	/* 0x277d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2783:
	/* 0x2783: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2785:
	/* 0x2785: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2787:
	/* 0x2787: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_278d:
	/* 0x278d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2792:
	/* 0x2792: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2798:
	/* 0x2798: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_279b:
	/* 0x279b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_27a0:
	/* 0x27a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a2:
	/* 0x27a2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27a5:
	/* 0x27a5: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_27ab:
	/* 0x27ab: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_27ae:
	/* 0x27ae: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_27b4:
	/* 0x27b4: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_27b9:
	/* 0x27b9: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27bb:
	/* 0x27bb: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c0:
	/* 0x27c0: jmp    282f <trace_ret_file_update_time+0x282f> */
	goto x86_l_282f;
x86_l_27c2:
	/* 0x27c2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_27c5:
	/* 0x27c5: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_27cb:
	/* 0x27cb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d0:
	/* 0x27d0: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_27d5:
	/* 0x27d5: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_27db:
	/* 0x27db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27e0:
	/* 0x27e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e5:
	/* 0x27e5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27e9:
	/* 0x27e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ee:
	/* 0x27ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27f3:
	/* 0x27f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f5:
	/* 0x27f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27fa:
	/* 0x27fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27ff:
	/* 0x27ff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2804:
	/* 0x2804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2809:
	/* 0x2809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_280b:
	/* 0x280b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2810:
	/* 0x2810: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2815:
	/* 0x2815: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_281a:
	/* 0x281a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_281f:
	/* 0x281f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2821:
	/* 0x2821: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2826:
	/* 0x2826: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_282a:
	/* 0x282a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_282f:
	/* 0x282f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2834:
	/* 0x2834: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2839:
	/* 0x2839: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_283e:
	/* 0x283e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2843:
	/* 0x2843: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2845:
	/* 0x2845: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_284a:
	/* 0x284a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_284f:
	/* 0x284f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2853:
	/* 0x2853: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2858:
	/* 0x2858: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_285d:
	/* 0x285d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2862:
	/* 0x2862: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2864:
	/* 0x2864: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2869:
	/* 0x2869: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_286c:
	/* 0x286c: je     28d8 <trace_ret_file_update_time+0x28d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d8;
	}
x86_l_286e:
	/* 0x286e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2873:
	/* 0x2873: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2876:
	/* 0x2876: je     28d8 <trace_ret_file_update_time+0x28d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d8;
	}
x86_l_2878:
	/* 0x2878: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_287c:
	/* 0x287c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2881:
	/* 0x2881: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2886:
	/* 0x2886: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_288b:
	/* 0x288b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288d:
	/* 0x288d: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2891:
	/* 0x2891: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2893:
	/* 0x2893: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2899:
	/* 0x2899: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_289b:
	/* 0x289b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_289d:
	/* 0x289d: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_28a3:
	/* 0x28a3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28a8:
	/* 0x28a8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28ae:
	/* 0x28ae: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28b1:
	/* 0x28b1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_28b6:
	/* 0x28b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28b8:
	/* 0x28b8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28bb:
	/* 0x28bb: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_28c1:
	/* 0x28c1: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_28c4:
	/* 0x28c4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_28ca:
	/* 0x28ca: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_28cf:
	/* 0x28cf: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28d1:
	/* 0x28d1: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28d6:
	/* 0x28d6: jmp    2945 <trace_ret_file_update_time+0x2945> */
	goto x86_l_2945;
x86_l_28d8:
	/* 0x28d8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28db:
	/* 0x28db: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_28e1:
	/* 0x28e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e6:
	/* 0x28e6: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_28eb:
	/* 0x28eb: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_28f1:
	/* 0x28f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28f6:
	/* 0x28f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fb:
	/* 0x28fb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28ff:
	/* 0x28ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2904:
	/* 0x2904: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2909:
	/* 0x2909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290b:
	/* 0x290b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2910:
	/* 0x2910: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2915:
	/* 0x2915: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291a:
	/* 0x291a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291f:
	/* 0x291f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2921:
	/* 0x2921: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2926:
	/* 0x2926: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292b:
	/* 0x292b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2930:
	/* 0x2930: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2935:
	/* 0x2935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2937:
	/* 0x2937: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293c:
	/* 0x293c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2940:
	/* 0x2940: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2945:
	/* 0x2945: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_294a:
	/* 0x294a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_294f:
	/* 0x294f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2954:
	/* 0x2954: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2959:
	/* 0x2959: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295b:
	/* 0x295b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2960:
	/* 0x2960: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2965:
	/* 0x2965: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2969:
	/* 0x2969: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_296e:
	/* 0x296e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2973:
	/* 0x2973: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2978:
	/* 0x2978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_297a:
	/* 0x297a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_297f:
	/* 0x297f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2982:
	/* 0x2982: je     29ee <trace_ret_file_update_time+0x29ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ee;
	}
x86_l_2984:
	/* 0x2984: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2989:
	/* 0x2989: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_298c:
	/* 0x298c: je     29ee <trace_ret_file_update_time+0x29ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ee;
	}
x86_l_298e:
	/* 0x298e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2992:
	/* 0x2992: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2997:
	/* 0x2997: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_299c:
	/* 0x299c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29a1:
	/* 0x29a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a3:
	/* 0x29a3: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_29a7:
	/* 0x29a7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29a9:
	/* 0x29a9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29af:
	/* 0x29af: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_29b1:
	/* 0x29b1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29b3:
	/* 0x29b3: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_29b9:
	/* 0x29b9: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29be:
	/* 0x29be: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29c4:
	/* 0x29c4: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c7:
	/* 0x29c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_29cc:
	/* 0x29cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ce:
	/* 0x29ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29d1:
	/* 0x29d1: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_29d7:
	/* 0x29d7: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_29da:
	/* 0x29da: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_29e0:
	/* 0x29e0: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_29e5:
	/* 0x29e5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29e7:
	/* 0x29e7: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ec:
	/* 0x29ec: jmp    2a5b <trace_ret_file_update_time+0x2a5b> */
	goto x86_l_2a5b;
x86_l_29ee:
	/* 0x29ee: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29f1:
	/* 0x29f1: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_29f7:
	/* 0x29f7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fc:
	/* 0x29fc: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2a01:
	/* 0x2a01: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2a07:
	/* 0x2a07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a11:
	/* 0x2a11: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a15:
	/* 0x2a15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a1f:
	/* 0x2a1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a21:
	/* 0x2a21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a26:
	/* 0x2a26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2b:
	/* 0x2a2b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a30:
	/* 0x2a30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a35:
	/* 0x2a35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a37:
	/* 0x2a37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a3c:
	/* 0x2a3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a41:
	/* 0x2a41: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a46:
	/* 0x2a46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a4b:
	/* 0x2a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4d:
	/* 0x2a4d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a52:
	/* 0x2a52: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a56:
	/* 0x2a56: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a5b:
	/* 0x2a5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a60:
	/* 0x2a60: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a65:
	/* 0x2a65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a6f:
	/* 0x2a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a71:
	/* 0x2a71: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a76:
	/* 0x2a76: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7b:
	/* 0x2a7b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a7f:
	/* 0x2a7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a84:
	/* 0x2a84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 10889ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10904ULL: goto x86_l_2a98;
	case 10906ULL: goto x86_l_2a9a;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10916ULL: goto x86_l_2aa4;
	case 10920ULL: goto x86_l_2aa8;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10937ULL: goto x86_l_2ab9;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10949ULL: goto x86_l_2ac5;
	case 10951ULL: goto x86_l_2ac7;
	case 10953ULL: goto x86_l_2ac9;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10978ULL: goto x86_l_2ae2;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10989ULL: goto x86_l_2aed;
	case 10992ULL: goto x86_l_2af0;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11143ULL: goto x86_l_2b87;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11184ULL: goto x86_l_2bb0;
	case 11189ULL: goto x86_l_2bb5;
	case 11192ULL: goto x86_l_2bb8;
	case 11194ULL: goto x86_l_2bba;
	case 11198ULL: goto x86_l_2bbe;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11215ULL: goto x86_l_2bcf;
	case 11219ULL: goto x86_l_2bd3;
	case 11221ULL: goto x86_l_2bd5;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11231ULL: goto x86_l_2bdf;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11248ULL: goto x86_l_2bf0;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11258ULL: goto x86_l_2bfa;
	case 11261ULL: goto x86_l_2bfd;
	case 11267ULL: goto x86_l_2c03;
	case 11270ULL: goto x86_l_2c06;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11283ULL: goto x86_l_2c13;
	case 11288ULL: goto x86_l_2c18;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11325ULL: goto x86_l_2c3d;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11394ULL: goto x86_l_2c82;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11460ULL: goto x86_l_2cc4;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11470ULL: goto x86_l_2cce;
	case 11472ULL: goto x86_l_2cd0;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11505ULL: goto x86_l_2cf1;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11526ULL: goto x86_l_2d06;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11536ULL: goto x86_l_2d10;
	case 11539ULL: goto x86_l_2d13;
	case 11545ULL: goto x86_l_2d19;
	case 11548ULL: goto x86_l_2d1c;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11568ULL: goto x86_l_2d30;
	case 11571ULL: goto x86_l_2d33;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11593ULL: goto x86_l_2d49;
	case 11598ULL: goto x86_l_2d4e;
	case 11603ULL: goto x86_l_2d53;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11641ULL: goto x86_l_2d79;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11663ULL: goto x86_l_2d8f;
	case 11668ULL: goto x86_l_2d94;
	case 11672ULL: goto x86_l_2d98;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11713ULL: goto x86_l_2dc1;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11748ULL: goto x86_l_2de4;
	case 11750ULL: goto x86_l_2de6;
	case 11754ULL: goto x86_l_2dea;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11775ULL: goto x86_l_2dff;
	case 11777ULL: goto x86_l_2e01;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11787ULL: goto x86_l_2e0b;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11817ULL: goto x86_l_2e29;
	case 11823ULL: goto x86_l_2e2f;
	case 11826ULL: goto x86_l_2e32;
	case 11832ULL: goto x86_l_2e38;
	case 11837ULL: goto x86_l_2e3d;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11865ULL: goto x86_l_2e59;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11982ULL: goto x86_l_2ece;
	case 11987ULL: goto x86_l_2ed3;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12008ULL: goto x86_l_2ee8;
	case 12013ULL: goto x86_l_2eed;
	case 12016ULL: goto x86_l_2ef0;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12026ULL: goto x86_l_2efa;
	case 12028ULL: goto x86_l_2efc;
	case 12032ULL: goto x86_l_2f00;
	case 12037ULL: goto x86_l_2f05;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12049ULL: goto x86_l_2f11;
	case 12053ULL: goto x86_l_2f15;
	case 12055ULL: goto x86_l_2f17;
	case 12061ULL: goto x86_l_2f1d;
	case 12063ULL: goto x86_l_2f1f;
	case 12065ULL: goto x86_l_2f21;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12082ULL: goto x86_l_2f32;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12092ULL: goto x86_l_2f3c;
	case 12095ULL: goto x86_l_2f3f;
	case 12101ULL: goto x86_l_2f45;
	case 12104ULL: goto x86_l_2f48;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12122ULL: goto x86_l_2f5a;
	case 12124ULL: goto x86_l_2f5c;
	case 12127ULL: goto x86_l_2f5f;
	case 12133ULL: goto x86_l_2f65;
	case 12138ULL: goto x86_l_2f6a;
	case 12143ULL: goto x86_l_2f6f;
	case 12149ULL: goto x86_l_2f75;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12175ULL: goto x86_l_2f8f;
	case 12180ULL: goto x86_l_2f94;
	case 12185ULL: goto x86_l_2f99;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12217ULL: goto x86_l_2fb9;
	case 12219ULL: goto x86_l_2fbb;
	case 12224ULL: goto x86_l_2fc0;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12253ULL: goto x86_l_2fdd;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12265ULL: goto x86_l_2fe9;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12284ULL: goto x86_l_2ffc;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12327ULL: goto x86_l_3027;
	case 12331ULL: goto x86_l_302b;
	case 12333ULL: goto x86_l_302d;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12343ULL: goto x86_l_3037;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12360ULL: goto x86_l_3048;
	case 12363ULL: goto x86_l_304b;
	case 12368ULL: goto x86_l_3050;
	case 12370ULL: goto x86_l_3052;
	case 12373ULL: goto x86_l_3055;
	case 12379ULL: goto x86_l_305b;
	case 12382ULL: goto x86_l_305e;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12427ULL: goto x86_l_308b;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12451ULL: goto x86_l_30a3;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12475ULL: goto x86_l_30bb;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12490ULL: goto x86_l_30ca;
	case 12495ULL: goto x86_l_30cf;
	case 12497ULL: goto x86_l_30d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a89:
	/* 0x2a89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8e:
	/* 0x2a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a90:
	/* 0x2a90: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a95:
	/* 0x2a95: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a98:
	/* 0x2a98: je     2b04 <trace_ret_file_update_time+0x2b04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b04;
	}
x86_l_2a9a:
	/* 0x2a9a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a9f:
	/* 0x2a9f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2aa2:
	/* 0x2aa2: je     2b04 <trace_ret_file_update_time+0x2b04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b04;
	}
x86_l_2aa4:
	/* 0x2aa4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2aa8:
	/* 0x2aa8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2aad:
	/* 0x2aad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ab7:
	/* 0x2ab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab9:
	/* 0x2ab9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2abd:
	/* 0x2abd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2abf:
	/* 0x2abf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2ac7:
	/* 0x2ac7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ac9:
	/* 0x2ac9: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2acf:
	/* 0x2acf: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ad4:
	/* 0x2ad4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2ada:
	/* 0x2ada: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2add:
	/* 0x2add: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ae2:
	/* 0x2ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae4:
	/* 0x2ae4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ae7:
	/* 0x2ae7: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2aed:
	/* 0x2aed: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2af0:
	/* 0x2af0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2af6:
	/* 0x2af6: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2afb:
	/* 0x2afb: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2afd:
	/* 0x2afd: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b02:
	/* 0x2b02: jmp    2b71 <trace_ret_file_update_time+0x2b71> */
	goto x86_l_2b71;
x86_l_2b04:
	/* 0x2b04: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b07:
	/* 0x2b07: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_2b0d:
	/* 0x2b0d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b12:
	/* 0x2b12: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2b17:
	/* 0x2b17: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2b1d:
	/* 0x2b1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b22:
	/* 0x2b22: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b27:
	/* 0x2b27: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b2b:
	/* 0x2b2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b30:
	/* 0x2b30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b35:
	/* 0x2b35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b37:
	/* 0x2b37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3c:
	/* 0x2b3c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b41:
	/* 0x2b41: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b46:
	/* 0x2b46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b4b:
	/* 0x2b4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4d:
	/* 0x2b4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b52:
	/* 0x2b52: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b57:
	/* 0x2b57: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b5c:
	/* 0x2b5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b61:
	/* 0x2b61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b63:
	/* 0x2b63: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b68:
	/* 0x2b68: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b6c:
	/* 0x2b6c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b71:
	/* 0x2b71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b76:
	/* 0x2b76: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b80:
	/* 0x2b80: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b85:
	/* 0x2b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b87:
	/* 0x2b87: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b8c:
	/* 0x2b8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b91:
	/* 0x2b91: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b95:
	/* 0x2b95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b9a:
	/* 0x2b9a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b9f:
	/* 0x2b9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba4:
	/* 0x2ba4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba6:
	/* 0x2ba6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bab:
	/* 0x2bab: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2bae:
	/* 0x2bae: je     2c1a <trace_ret_file_update_time+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1a;
	}
x86_l_2bb0:
	/* 0x2bb0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bb5:
	/* 0x2bb5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2bb8:
	/* 0x2bb8: je     2c1a <trace_ret_file_update_time+0x2c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1a;
	}
x86_l_2bba:
	/* 0x2bba: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2bbe:
	/* 0x2bbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bc3:
	/* 0x2bc3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bc8:
	/* 0x2bc8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bcd:
	/* 0x2bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcf:
	/* 0x2bcf: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2bd3:
	/* 0x2bd3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2bd5:
	/* 0x2bd5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2bdd:
	/* 0x2bdd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bdf:
	/* 0x2bdf: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2be5:
	/* 0x2be5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bea:
	/* 0x2bea: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bf0:
	/* 0x2bf0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bf3:
	/* 0x2bf3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2bf8:
	/* 0x2bf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfa:
	/* 0x2bfa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bfd:
	/* 0x2bfd: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2c03:
	/* 0x2c03: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c06:
	/* 0x2c06: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c11:
	/* 0x2c11: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c13:
	/* 0x2c13: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c18:
	/* 0x2c18: jmp    2c87 <trace_ret_file_update_time+0x2c87> */
	goto x86_l_2c87;
x86_l_2c1a:
	/* 0x2c1a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c1d:
	/* 0x2c1d: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_2c23:
	/* 0x2c23: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c28:
	/* 0x2c28: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2c2d:
	/* 0x2c2d: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2c33:
	/* 0x2c33: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c38:
	/* 0x2c38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3d:
	/* 0x2c3d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c41:
	/* 0x2c41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c46:
	/* 0x2c46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c4b:
	/* 0x2c4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4d:
	/* 0x2c4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c52:
	/* 0x2c52: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c57:
	/* 0x2c57: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c61:
	/* 0x2c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c63:
	/* 0x2c63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c68:
	/* 0x2c68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c72:
	/* 0x2c72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c77:
	/* 0x2c77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c79:
	/* 0x2c79: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c7e:
	/* 0x2c7e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c82:
	/* 0x2c82: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c87:
	/* 0x2c87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c8c:
	/* 0x2c8c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c91:
	/* 0x2c91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c96:
	/* 0x2c96: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c9b:
	/* 0x2c9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9d:
	/* 0x2c9d: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ca2:
	/* 0x2ca2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca7:
	/* 0x2ca7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cab:
	/* 0x2cab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb0:
	/* 0x2cb0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cba:
	/* 0x2cba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbc:
	/* 0x2cbc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc1:
	/* 0x2cc1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cc4:
	/* 0x2cc4: je     2d30 <trace_ret_file_update_time+0x2d30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d30;
	}
x86_l_2cc6:
	/* 0x2cc6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ccb:
	/* 0x2ccb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2cce:
	/* 0x2cce: je     2d30 <trace_ret_file_update_time+0x2d30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d30;
	}
x86_l_2cd0:
	/* 0x2cd0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cd4:
	/* 0x2cd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd9:
	/* 0x2cd9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cde:
	/* 0x2cde: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ce3:
	/* 0x2ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce5:
	/* 0x2ce5: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ce9:
	/* 0x2ce9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ceb:
	/* 0x2ceb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2cf3:
	/* 0x2cf3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cf5:
	/* 0x2cf5: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2cfb:
	/* 0x2cfb: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d00:
	/* 0x2d00: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d06:
	/* 0x2d06: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d09:
	/* 0x2d09: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d0e:
	/* 0x2d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d10:
	/* 0x2d10: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d13:
	/* 0x2d13: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2d19:
	/* 0x2d19: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d1c:
	/* 0x2d1c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d22:
	/* 0x2d22: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d27:
	/* 0x2d27: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d29:
	/* 0x2d29: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d2e:
	/* 0x2d2e: jmp    2d9d <trace_ret_file_update_time+0x2d9d> */
	goto x86_l_2d9d;
x86_l_2d30:
	/* 0x2d30: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d33:
	/* 0x2d33: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_2d39:
	/* 0x2d39: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d3e:
	/* 0x2d3e: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2d43:
	/* 0x2d43: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2d49:
	/* 0x2d49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d4e:
	/* 0x2d4e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d53:
	/* 0x2d53: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d57:
	/* 0x2d57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d61:
	/* 0x2d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d63:
	/* 0x2d63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d68:
	/* 0x2d68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6d:
	/* 0x2d6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d72:
	/* 0x2d72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d77:
	/* 0x2d77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d79:
	/* 0x2d79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d7e:
	/* 0x2d7e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d83:
	/* 0x2d83: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d88:
	/* 0x2d88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8d:
	/* 0x2d8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8f:
	/* 0x2d8f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d94:
	/* 0x2d94: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d98:
	/* 0x2d98: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d9d:
	/* 0x2d9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2da2:
	/* 0x2da2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2da7:
	/* 0x2da7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dac:
	/* 0x2dac: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2db1:
	/* 0x2db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db3:
	/* 0x2db3: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2db8:
	/* 0x2db8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dbd:
	/* 0x2dbd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2dc1:
	/* 0x2dc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dc6:
	/* 0x2dc6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dcb:
	/* 0x2dcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dd0:
	/* 0x2dd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd2:
	/* 0x2dd2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd7:
	/* 0x2dd7: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dda:
	/* 0x2dda: je     2e46 <trace_ret_file_update_time+0x2e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e46;
	}
x86_l_2ddc:
	/* 0x2ddc: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2de1:
	/* 0x2de1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2de4:
	/* 0x2de4: je     2e46 <trace_ret_file_update_time+0x2e46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e46;
	}
x86_l_2de6:
	/* 0x2de6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dea:
	/* 0x2dea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2def:
	/* 0x2def: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2df4:
	/* 0x2df4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2df9:
	/* 0x2df9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dfb:
	/* 0x2dfb: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2dff:
	/* 0x2dff: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e01:
	/* 0x2e01: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e07:
	/* 0x2e07: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2e09:
	/* 0x2e09: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e0b:
	/* 0x2e0b: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2e11:
	/* 0x2e11: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e16:
	/* 0x2e16: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e1c:
	/* 0x2e1c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e1f:
	/* 0x2e1f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2e24:
	/* 0x2e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e26:
	/* 0x2e26: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e29:
	/* 0x2e29: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2e2f:
	/* 0x2e2f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e32:
	/* 0x2e32: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e38:
	/* 0x2e38: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e3d:
	/* 0x2e3d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e3f:
	/* 0x2e3f: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e44:
	/* 0x2e44: jmp    2eb3 <trace_ret_file_update_time+0x2eb3> */
	goto x86_l_2eb3;
x86_l_2e46:
	/* 0x2e46: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e49:
	/* 0x2e49: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_2e4f:
	/* 0x2e4f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e54:
	/* 0x2e54: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2e59:
	/* 0x2e59: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2e5f:
	/* 0x2e5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e64:
	/* 0x2e64: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e69:
	/* 0x2e69: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e6d:
	/* 0x2e6d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e72:
	/* 0x2e72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e77:
	/* 0x2e77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e79:
	/* 0x2e79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e83:
	/* 0x2e83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e88:
	/* 0x2e88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8d:
	/* 0x2e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8f:
	/* 0x2e8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e94:
	/* 0x2e94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e99:
	/* 0x2e99: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea3:
	/* 0x2ea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea5:
	/* 0x2ea5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eaa:
	/* 0x2eaa: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2eae:
	/* 0x2eae: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eb3:
	/* 0x2eb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb8:
	/* 0x2eb8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ec7:
	/* 0x2ec7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec9:
	/* 0x2ec9: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ece:
	/* 0x2ece: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed3:
	/* 0x2ed3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2edc:
	/* 0x2edc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ee1:
	/* 0x2ee1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ee6:
	/* 0x2ee6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee8:
	/* 0x2ee8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eed:
	/* 0x2eed: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ef0:
	/* 0x2ef0: je     2f5c <trace_ret_file_update_time+0x2f5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5c;
	}
x86_l_2ef2:
	/* 0x2ef2: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ef7:
	/* 0x2ef7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2efa:
	/* 0x2efa: je     2f5c <trace_ret_file_update_time+0x2f5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f5c;
	}
x86_l_2efc:
	/* 0x2efc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f00:
	/* 0x2f00: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f05:
	/* 0x2f05: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f0a:
	/* 0x2f0a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f0f:
	/* 0x2f0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f11:
	/* 0x2f11: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2f15:
	/* 0x2f15: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f17:
	/* 0x2f17: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f1d:
	/* 0x2f1d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2f1f:
	/* 0x2f1f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f21:
	/* 0x2f21: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_2f27:
	/* 0x2f27: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f2c:
	/* 0x2f2c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f32:
	/* 0x2f32: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f35:
	/* 0x2f35: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f3a:
	/* 0x2f3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3c:
	/* 0x2f3c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f3f:
	/* 0x2f3f: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_2f45:
	/* 0x2f45: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f48:
	/* 0x2f48: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f53:
	/* 0x2f53: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f55:
	/* 0x2f55: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f5a:
	/* 0x2f5a: jmp    2fc9 <trace_ret_file_update_time+0x2fc9> */
	goto x86_l_2fc9;
x86_l_2f5c:
	/* 0x2f5c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f5f:
	/* 0x2f5f: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_2f65:
	/* 0x2f65: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6a:
	/* 0x2f6a: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2f6f:
	/* 0x2f6f: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_2f75:
	/* 0x2f75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f7a:
	/* 0x2f7a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7f:
	/* 0x2f7f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f83:
	/* 0x2f83: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f88:
	/* 0x2f88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f8d:
	/* 0x2f8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8f:
	/* 0x2f8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f94:
	/* 0x2f94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f99:
	/* 0x2f99: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f9e:
	/* 0x2f9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa3:
	/* 0x2fa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa5:
	/* 0x2fa5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2faa:
	/* 0x2faa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2faf:
	/* 0x2faf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb4:
	/* 0x2fb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb9:
	/* 0x2fb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbb:
	/* 0x2fbb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc0:
	/* 0x2fc0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fc4:
	/* 0x2fc4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fce:
	/* 0x2fce: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fd3:
	/* 0x2fd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fdd:
	/* 0x2fdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fdf:
	/* 0x2fdf: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe9:
	/* 0x2fe9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2fed:
	/* 0x2fed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ff2:
	/* 0x2ff2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ffc:
	/* 0x2ffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ffe:
	/* 0x2ffe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3003:
	/* 0x3003: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3006:
	/* 0x3006: je     3072 <trace_ret_file_update_time+0x3072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3072;
	}
x86_l_3008:
	/* 0x3008: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_300d:
	/* 0x300d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3010:
	/* 0x3010: je     3072 <trace_ret_file_update_time+0x3072> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3072;
	}
x86_l_3012:
	/* 0x3012: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3016:
	/* 0x3016: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_301b:
	/* 0x301b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3020:
	/* 0x3020: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3025:
	/* 0x3025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3027:
	/* 0x3027: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_302b:
	/* 0x302b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_302d:
	/* 0x302d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3033:
	/* 0x3033: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3035:
	/* 0x3035: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3037:
	/* 0x3037: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_303d:
	/* 0x303d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3042:
	/* 0x3042: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3048:
	/* 0x3048: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_304b:
	/* 0x304b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3050:
	/* 0x3050: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3052:
	/* 0x3052: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3055:
	/* 0x3055: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_305b:
	/* 0x305b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_305e:
	/* 0x305e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3064:
	/* 0x3064: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3069:
	/* 0x3069: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_306b:
	/* 0x306b: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3070:
	/* 0x3070: jmp    30df <trace_ret_file_update_time+0x30df> */
	return 12511ULL;
x86_l_3072:
	/* 0x3072: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3075:
	/* 0x3075: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_307b:
	/* 0x307b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3080:
	/* 0x3080: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3085:
	/* 0x3085: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_308b:
	/* 0x308b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3090:
	/* 0x3090: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3095:
	/* 0x3095: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3099:
	/* 0x3099: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_309e:
	/* 0x309e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30a3:
	/* 0x30a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a5:
	/* 0x30a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30aa:
	/* 0x30aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30af:
	/* 0x30af: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30b4:
	/* 0x30b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b9:
	/* 0x30b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30bb:
	/* 0x30bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c0:
	/* 0x30c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30c5:
	/* 0x30c5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30ca:
	/* 0x30ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30cf:
	/* 0x30cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d1:
	/* 0x30d1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 12502ULL;
}

static __noinline __u64 tracee_trace_ret_file_update_time_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12502ULL: goto x86_l_30d6;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12572ULL: goto x86_l_311c;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12582ULL: goto x86_l_3126;
	case 12584ULL: goto x86_l_3128;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12598ULL: goto x86_l_3136;
	case 12603ULL: goto x86_l_313b;
	case 12605ULL: goto x86_l_313d;
	case 12609ULL: goto x86_l_3141;
	case 12611ULL: goto x86_l_3143;
	case 12617ULL: goto x86_l_3149;
	case 12619ULL: goto x86_l_314b;
	case 12621ULL: goto x86_l_314d;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12648ULL: goto x86_l_3168;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12660ULL: goto x86_l_3174;
	case 12666ULL: goto x86_l_317a;
	case 12671ULL: goto x86_l_317f;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12680ULL: goto x86_l_3188;
	case 12683ULL: goto x86_l_318b;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12699ULL: goto x86_l_319b;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12768ULL: goto x86_l_31e0;
	case 12773ULL: goto x86_l_31e5;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12784ULL: goto x86_l_31f0;
	case 12789ULL: goto x86_l_31f5;
	case 12794ULL: goto x86_l_31fa;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12811ULL: goto x86_l_320b;
	case 12816ULL: goto x86_l_3210;
	case 12821ULL: goto x86_l_3215;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12840ULL: goto x86_l_3228;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12850ULL: goto x86_l_3232;
	case 12852ULL: goto x86_l_3234;
	case 12857ULL: goto x86_l_3239;
	case 12860ULL: goto x86_l_323c;
	case 12862ULL: goto x86_l_323e;
	case 12866ULL: goto x86_l_3242;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12881ULL: goto x86_l_3251;
	case 12883ULL: goto x86_l_3253;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12895ULL: goto x86_l_325f;
	case 12897ULL: goto x86_l_3261;
	case 12899ULL: goto x86_l_3263;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12916ULL: goto x86_l_3274;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12926ULL: goto x86_l_327e;
	case 12929ULL: goto x86_l_3281;
	case 12935ULL: goto x86_l_3287;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12949ULL: goto x86_l_3295;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12958ULL: goto x86_l_329e;
	case 12961ULL: goto x86_l_32a1;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12997ULL: goto x86_l_32c5;
	case 13002ULL: goto x86_l_32ca;
	case 13007ULL: goto x86_l_32cf;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13029ULL: goto x86_l_32e5;
	case 13031ULL: goto x86_l_32e7;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13058ULL: goto x86_l_3302;
	case 13062ULL: goto x86_l_3306;
	case 13067ULL: goto x86_l_330b;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13089ULL: goto x86_l_3321;
	case 13094ULL: goto x86_l_3326;
	case 13099ULL: goto x86_l_332b;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13128ULL: goto x86_l_3348;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13138ULL: goto x86_l_3352;
	case 13140ULL: goto x86_l_3354;
	case 13144ULL: goto x86_l_3358;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13159ULL: goto x86_l_3367;
	case 13161ULL: goto x86_l_3369;
	case 13165ULL: goto x86_l_336d;
	case 13167ULL: goto x86_l_336f;
	case 13173ULL: goto x86_l_3375;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13183ULL: goto x86_l_337f;
	case 13188ULL: goto x86_l_3384;
	case 13194ULL: goto x86_l_338a;
	case 13197ULL: goto x86_l_338d;
	case 13202ULL: goto x86_l_3392;
	case 13204ULL: goto x86_l_3394;
	case 13207ULL: goto x86_l_3397;
	case 13213ULL: goto x86_l_339d;
	case 13216ULL: goto x86_l_33a0;
	case 13222ULL: goto x86_l_33a6;
	case 13227ULL: goto x86_l_33ab;
	case 13229ULL: goto x86_l_33ad;
	case 13234ULL: goto x86_l_33b2;
	case 13236ULL: goto x86_l_33b4;
	case 13239ULL: goto x86_l_33b7;
	case 13245ULL: goto x86_l_33bd;
	case 13250ULL: goto x86_l_33c2;
	case 13255ULL: goto x86_l_33c7;
	case 13261ULL: goto x86_l_33cd;
	case 13266ULL: goto x86_l_33d2;
	case 13271ULL: goto x86_l_33d7;
	case 13275ULL: goto x86_l_33db;
	case 13280ULL: goto x86_l_33e0;
	case 13285ULL: goto x86_l_33e5;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13297ULL: goto x86_l_33f1;
	case 13302ULL: goto x86_l_33f6;
	case 13307ULL: goto x86_l_33fb;
	case 13309ULL: goto x86_l_33fd;
	case 13314ULL: goto x86_l_3402;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13329ULL: goto x86_l_3411;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13355ULL: goto x86_l_342b;
	case 13360ULL: goto x86_l_3430;
	case 13365ULL: goto x86_l_3435;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13381ULL: goto x86_l_3445;
	case 13386ULL: goto x86_l_344a;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13398ULL: goto x86_l_3456;
	case 13403ULL: goto x86_l_345b;
	case 13406ULL: goto x86_l_345e;
	case 13408ULL: goto x86_l_3460;
	case 13413ULL: goto x86_l_3465;
	case 13416ULL: goto x86_l_3468;
	case 13418ULL: goto x86_l_346a;
	case 13422ULL: goto x86_l_346e;
	case 13427ULL: goto x86_l_3473;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13439ULL: goto x86_l_347f;
	case 13443ULL: goto x86_l_3483;
	case 13445ULL: goto x86_l_3485;
	case 13451ULL: goto x86_l_348b;
	case 13453ULL: goto x86_l_348d;
	case 13455ULL: goto x86_l_348f;
	case 13461ULL: goto x86_l_3495;
	case 13466ULL: goto x86_l_349a;
	case 13472ULL: goto x86_l_34a0;
	case 13475ULL: goto x86_l_34a3;
	case 13480ULL: goto x86_l_34a8;
	case 13482ULL: goto x86_l_34aa;
	case 13485ULL: goto x86_l_34ad;
	case 13491ULL: goto x86_l_34b3;
	case 13494ULL: goto x86_l_34b6;
	case 13500ULL: goto x86_l_34bc;
	case 13505ULL: goto x86_l_34c1;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13517ULL: goto x86_l_34cd;
	case 13520ULL: goto x86_l_34d0;
	case 13526ULL: goto x86_l_34d6;
	case 13531ULL: goto x86_l_34db;
	case 13536ULL: goto x86_l_34e0;
	case 13542ULL: goto x86_l_34e6;
	case 13547ULL: goto x86_l_34eb;
	case 13552ULL: goto x86_l_34f0;
	case 13556ULL: goto x86_l_34f4;
	case 13561ULL: goto x86_l_34f9;
	case 13566ULL: goto x86_l_34fe;
	case 13568ULL: goto x86_l_3500;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13583ULL: goto x86_l_350f;
	case 13588ULL: goto x86_l_3514;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13612ULL: goto x86_l_352c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30d6:
	/* 0x30d6: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30da:
	/* 0x30da: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30df:
	/* 0x30df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30e4:
	/* 0x30e4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30e9:
	/* 0x30e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30ee:
	/* 0x30ee: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30f3:
	/* 0x30f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f5:
	/* 0x30f5: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30fa:
	/* 0x30fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ff:
	/* 0x30ff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3103:
	/* 0x3103: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3108:
	/* 0x3108: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_310d:
	/* 0x310d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3112:
	/* 0x3112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3114:
	/* 0x3114: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3119:
	/* 0x3119: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_311c:
	/* 0x311c: je     3188 <trace_ret_file_update_time+0x3188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3188;
	}
x86_l_311e:
	/* 0x311e: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3123:
	/* 0x3123: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3126:
	/* 0x3126: je     3188 <trace_ret_file_update_time+0x3188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3188;
	}
x86_l_3128:
	/* 0x3128: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_312c:
	/* 0x312c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3131:
	/* 0x3131: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3136:
	/* 0x3136: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_313b:
	/* 0x313b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313d:
	/* 0x313d: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3141:
	/* 0x3141: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3143:
	/* 0x3143: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3149:
	/* 0x3149: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_314b:
	/* 0x314b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_314d:
	/* 0x314d: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_3153:
	/* 0x3153: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3158:
	/* 0x3158: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_315e:
	/* 0x315e: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3161:
	/* 0x3161: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3166:
	/* 0x3166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3168:
	/* 0x3168: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_316b:
	/* 0x316b: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_3171:
	/* 0x3171: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3174:
	/* 0x3174: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_317a:
	/* 0x317a: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_317f:
	/* 0x317f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3181:
	/* 0x3181: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3186:
	/* 0x3186: jmp    31f5 <trace_ret_file_update_time+0x31f5> */
	goto x86_l_31f5;
x86_l_3188:
	/* 0x3188: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_318b:
	/* 0x318b: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_3191:
	/* 0x3191: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3196:
	/* 0x3196: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_319b:
	/* 0x319b: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_31a1:
	/* 0x31a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31a6:
	/* 0x31a6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ab:
	/* 0x31ab: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31af:
	/* 0x31af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31b4:
	/* 0x31b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b9:
	/* 0x31b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bb:
	/* 0x31bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31c0:
	/* 0x31c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c5:
	/* 0x31c5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ca:
	/* 0x31ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31cf:
	/* 0x31cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d1:
	/* 0x31d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31d6:
	/* 0x31d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31db:
	/* 0x31db: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31e0:
	/* 0x31e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31e5:
	/* 0x31e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e7:
	/* 0x31e7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ec:
	/* 0x31ec: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31f0:
	/* 0x31f0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31f5:
	/* 0x31f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31fa:
	/* 0x31fa: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31ff:
	/* 0x31ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3204:
	/* 0x3204: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3209:
	/* 0x3209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320b:
	/* 0x320b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3210:
	/* 0x3210: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3215:
	/* 0x3215: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3219:
	/* 0x3219: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_321e:
	/* 0x321e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3223:
	/* 0x3223: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3228:
	/* 0x3228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322a:
	/* 0x322a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_322f:
	/* 0x322f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3232:
	/* 0x3232: je     329e <trace_ret_file_update_time+0x329e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_329e;
	}
x86_l_3234:
	/* 0x3234: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3239:
	/* 0x3239: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_323c:
	/* 0x323c: je     329e <trace_ret_file_update_time+0x329e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_329e;
	}
x86_l_323e:
	/* 0x323e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3242:
	/* 0x3242: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3247:
	/* 0x3247: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_324c:
	/* 0x324c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3251:
	/* 0x3251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3253:
	/* 0x3253: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3257:
	/* 0x3257: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3259:
	/* 0x3259: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_325f:
	/* 0x325f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3261:
	/* 0x3261: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3263:
	/* 0x3263: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_3269:
	/* 0x3269: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_326e:
	/* 0x326e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3274:
	/* 0x3274: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3277:
	/* 0x3277: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_327c:
	/* 0x327c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_327e:
	/* 0x327e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3281:
	/* 0x3281: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_3287:
	/* 0x3287: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_328a:
	/* 0x328a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3290:
	/* 0x3290: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3295:
	/* 0x3295: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3297:
	/* 0x3297: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329c:
	/* 0x329c: jmp    330b <trace_ret_file_update_time+0x330b> */
	goto x86_l_330b;
x86_l_329e:
	/* 0x329e: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32a1:
	/* 0x32a1: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_32a7:
	/* 0x32a7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ac:
	/* 0x32ac: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_32b1:
	/* 0x32b1: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_32b7:
	/* 0x32b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32bc:
	/* 0x32bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32c1:
	/* 0x32c1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32c5:
	/* 0x32c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ca:
	/* 0x32ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32cf:
	/* 0x32cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d1:
	/* 0x32d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d6:
	/* 0x32d6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32db:
	/* 0x32db: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32e0:
	/* 0x32e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e5:
	/* 0x32e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e7:
	/* 0x32e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32ec:
	/* 0x32ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f1:
	/* 0x32f1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32f6:
	/* 0x32f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fb:
	/* 0x32fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fd:
	/* 0x32fd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3302:
	/* 0x3302: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3306:
	/* 0x3306: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_330b:
	/* 0x330b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3310:
	/* 0x3310: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3315:
	/* 0x3315: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_331a:
	/* 0x331a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_331f:
	/* 0x331f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3321:
	/* 0x3321: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3326:
	/* 0x3326: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332b:
	/* 0x332b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_332f:
	/* 0x332f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3334:
	/* 0x3334: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3339:
	/* 0x3339: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_333e:
	/* 0x333e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3340:
	/* 0x3340: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3345:
	/* 0x3345: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3348:
	/* 0x3348: je     33b4 <trace_ret_file_update_time+0x33b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b4;
	}
x86_l_334a:
	/* 0x334a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_334f:
	/* 0x334f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3352:
	/* 0x3352: je     33b4 <trace_ret_file_update_time+0x33b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33b4;
	}
x86_l_3354:
	/* 0x3354: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3358:
	/* 0x3358: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_335d:
	/* 0x335d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3362:
	/* 0x3362: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3367:
	/* 0x3367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3369:
	/* 0x3369: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_336d:
	/* 0x336d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_336f:
	/* 0x336f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3375:
	/* 0x3375: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3377:
	/* 0x3377: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3379:
	/* 0x3379: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_337f:
	/* 0x337f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3384:
	/* 0x3384: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_338a:
	/* 0x338a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_338d:
	/* 0x338d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3392:
	/* 0x3392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3394:
	/* 0x3394: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3397:
	/* 0x3397: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_339d:
	/* 0x339d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_33a0:
	/* 0x33a0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_33a6:
	/* 0x33a6: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_33ab:
	/* 0x33ab: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_33ad:
	/* 0x33ad: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b2:
	/* 0x33b2: jmp    3421 <trace_ret_file_update_time+0x3421> */
	goto x86_l_3421;
x86_l_33b4:
	/* 0x33b4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_33b7:
	/* 0x33b7: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_33bd:
	/* 0x33bd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c2:
	/* 0x33c2: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_33c7:
	/* 0x33c7: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_33cd:
	/* 0x33cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33d2:
	/* 0x33d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33d7:
	/* 0x33d7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33db:
	/* 0x33db: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e0:
	/* 0x33e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33e5:
	/* 0x33e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e7:
	/* 0x33e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33ec:
	/* 0x33ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f1:
	/* 0x33f1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f6:
	/* 0x33f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33fb:
	/* 0x33fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fd:
	/* 0x33fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3402:
	/* 0x3402: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3407:
	/* 0x3407: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_340c:
	/* 0x340c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3411:
	/* 0x3411: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3413:
	/* 0x3413: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3418:
	/* 0x3418: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_341c:
	/* 0x341c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3421:
	/* 0x3421: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3426:
	/* 0x3426: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_342b:
	/* 0x342b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3430:
	/* 0x3430: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3435:
	/* 0x3435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3437:
	/* 0x3437: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_343c:
	/* 0x343c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3441:
	/* 0x3441: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3445:
	/* 0x3445: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_344a:
	/* 0x344a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_344f:
	/* 0x344f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3454:
	/* 0x3454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3456:
	/* 0x3456: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_345b:
	/* 0x345b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_345e:
	/* 0x345e: je     34cd <trace_ret_file_update_time+0x34cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34cd;
	}
x86_l_3460:
	/* 0x3460: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3465:
	/* 0x3465: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3468:
	/* 0x3468: je     34cd <trace_ret_file_update_time+0x34cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34cd;
	}
x86_l_346a:
	/* 0x346a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_346e:
	/* 0x346e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3473:
	/* 0x3473: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3478:
	/* 0x3478: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_347d:
	/* 0x347d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347f:
	/* 0x347f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3483:
	/* 0x3483: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3485:
	/* 0x3485: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_348b:
	/* 0x348b: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_348d:
	/* 0x348d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_348f:
	/* 0x348f: jb     19b8 <trace_ret_file_update_time+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6584ULL;
	}
x86_l_3495:
	/* 0x3495: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_349a:
	/* 0x349a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_34a0:
	/* 0x34a0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34a3:
	/* 0x34a3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_34a8:
	/* 0x34a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34aa:
	/* 0x34aa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_34ad:
	/* 0x34ad: jl     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6306ULL;
	}
x86_l_34b3:
	/* 0x34b3: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_34b6:
	/* 0x34b6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_34bc:
	/* 0x34bc: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34c1:
	/* 0x34c1: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34c3:
	/* 0x34c3: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34c8:
	/* 0x34c8: jmp    18a2 <trace_ret_file_update_time+0x18a2> */
	return 6306ULL;
x86_l_34cd:
	/* 0x34cd: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_34d0:
	/* 0x34d0: jne    18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6306ULL;
	}
x86_l_34d6:
	/* 0x34d6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34db:
	/* 0x34db: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_34e0:
	/* 0x34e0: je     18a2 <trace_ret_file_update_time+0x18a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6306ULL;
	}
x86_l_34e6:
	/* 0x34e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34eb:
	/* 0x34eb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34f0:
	/* 0x34f0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34f4:
	/* 0x34f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34f9:
	/* 0x34f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34fe:
	/* 0x34fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3500:
	/* 0x3500: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3505:
	/* 0x3505: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350a:
	/* 0x350a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350f:
	/* 0x350f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3514:
	/* 0x3514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3516:
	/* 0x3516: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_351b:
	/* 0x351b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3520:
	/* 0x3520: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3525:
	/* 0x3525: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_352a:
	/* 0x352a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_352c:
	/* 0x352c: jmp    18a2 <trace_ret_file_update_time+0x18a2> */
	return 6306ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 11808U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2282ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2290ULL && __x86_pc <= 4120ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 4122ULL && __x86_pc <= 5890ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5895ULL && __x86_pc <= 7639ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7644ULL && __x86_pc <= 9254ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9259ULL && __x86_pc <= 10884ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10889ULL && __x86_pc <= 12497ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12502ULL && __x86_pc <= 13612ULL)
			__x86_pc = tracee_trace_ret_file_update_time_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char fexit_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char socktrack_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 26ULL: goto x86_l_1a;
	case 28ULL: goto x86_l_1c;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 55ULL: goto x86_l_37;
	case 62ULL: goto x86_l_3e;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 77ULL: goto x86_l_4d;
	case 80ULL: goto x86_l_50;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 110ULL: goto x86_l_6e;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 124ULL: goto x86_l_7c;
	case 127ULL: goto x86_l_7f;
	case 133ULL: goto x86_l_85;
	case 136ULL: goto x86_l_88;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 147ULL: goto x86_l_93;
	case 149ULL: goto x86_l_95;
	case 153ULL: goto x86_l_99;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 168ULL: goto x86_l_a8;
	case 170ULL: goto x86_l_aa;
	case 173ULL: goto x86_l_ad;
	case 177ULL: goto x86_l_b1;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 198ULL: goto x86_l_c6;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 226ULL: goto x86_l_e2;
	case 234ULL: goto x86_l_ea;
	case 238ULL: goto x86_l_ee;
	case 246ULL: goto x86_l_f6;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 263ULL: goto x86_l_107;
	case 265ULL: goto x86_l_109;
	case 272ULL: goto x86_l_110;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 291ULL: goto x86_l_123;
	case 301ULL: goto x86_l_12d;
	case 309ULL: goto x86_l_135;
	case 320ULL: goto x86_l_140;
	case 327ULL: goto x86_l_147;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 351ULL: goto x86_l_15f;
	case 357ULL: goto x86_l_165;
	case 363ULL: goto x86_l_16b;
	case 374ULL: goto x86_l_176;
	case 376ULL: goto x86_l_178;
	case 382ULL: goto x86_l_17e;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 399ULL: goto x86_l_18f;
	case 406ULL: goto x86_l_196;
	case 409ULL: goto x86_l_199;
	case 415ULL: goto x86_l_19f;
	case 423ULL: goto x86_l_1a7;
	case 426ULL: goto x86_l_1aa;
	case 430ULL: goto x86_l_1ae;
	case 439ULL: goto x86_l_1b7;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 514ULL: goto x86_l_202;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 528ULL: goto x86_l_210;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 538ULL: goto x86_l_21a;
	case 541ULL: goto x86_l_21d;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 557ULL: goto x86_l_22d;
	case 563ULL: goto x86_l_233;
	case 567ULL: goto x86_l_237;
	case 572ULL: goto x86_l_23c;
	case 576ULL: goto x86_l_240;
	case 581ULL: goto x86_l_245;
	case 586ULL: goto x86_l_24a;
	case 591ULL: goto x86_l_24f;
	case 594ULL: goto x86_l_252;
	case 596ULL: goto x86_l_254;
	case 601ULL: goto x86_l_259;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 612ULL: goto x86_l_264;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 648ULL: goto x86_l_288;
	case 652ULL: goto x86_l_28c;
	case 656ULL: goto x86_l_290;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 709ULL: goto x86_l_2c5;
	case 711ULL: goto x86_l_2c7;
	case 719ULL: goto x86_l_2cf;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 731ULL: goto x86_l_2db;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 759ULL: goto x86_l_2f7;
	case 763ULL: goto x86_l_2fb;
	case 768ULL: goto x86_l_300;
	case 776ULL: goto x86_l_308;
	case 781ULL: goto x86_l_30d;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 789ULL: goto x86_l_315;
	case 793ULL: goto x86_l_319;
	case 799ULL: goto x86_l_31f;
	case 803ULL: goto x86_l_323;
	case 809ULL: goto x86_l_329;
	case 821ULL: goto x86_l_335;
	case 829ULL: goto x86_l_33d;
	case 837ULL: goto x86_l_345;
	case 842ULL: goto x86_l_34a;
	case 845ULL: goto x86_l_34d;
	case 849ULL: goto x86_l_351;
	case 854ULL: goto x86_l_356;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 866ULL: goto x86_l_362;
	case 870ULL: goto x86_l_366;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 886ULL: goto x86_l_376;
	case 891ULL: goto x86_l_37b;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 921ULL: goto x86_l_399;
	case 923ULL: goto x86_l_39b;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 959ULL: goto x86_l_3bf;
	case 964ULL: goto x86_l_3c4;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 979ULL: goto x86_l_3d3;
	case 984ULL: goto x86_l_3d8;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 1000ULL: goto x86_l_3e8;
	case 1011ULL: goto x86_l_3f3;
	case 1018ULL: goto x86_l_3fa;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1033ULL: goto x86_l_409;
	case 1036ULL: goto x86_l_40c;
	case 1042ULL: goto x86_l_412;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1056ULL: goto x86_l_420;
	case 1061ULL: goto x86_l_425;
	case 1063ULL: goto x86_l_427;
	case 1070ULL: goto x86_l_42e;
	case 1078ULL: goto x86_l_436;
	case 1083ULL: goto x86_l_43b;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1103ULL: goto x86_l_44f;
	case 1111ULL: goto x86_l_457;
	case 1116ULL: goto x86_l_45c;
	case 1124ULL: goto x86_l_464;
	case 1129ULL: goto x86_l_469;
	case 1134ULL: goto x86_l_46e;
	case 1138ULL: goto x86_l_472;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1159ULL: goto x86_l_487;
	case 1161ULL: goto x86_l_489;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1202ULL: goto x86_l_4b2;
	case 1208ULL: goto x86_l_4b8;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1257ULL: goto x86_l_4e9;
	case 1262ULL: goto x86_l_4ee;
	case 1267ULL: goto x86_l_4f3;
	case 1269ULL: goto x86_l_4f5;
	case 1272ULL: goto x86_l_4f8;
	case 1279ULL: goto x86_l_4ff;
	case 1289ULL: goto x86_l_509;
	case 1296ULL: goto x86_l_510;
	case 1306ULL: goto x86_l_51a;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1326ULL: goto x86_l_52e;
	case 1335ULL: goto x86_l_537;
	case 1340ULL: goto x86_l_53c;
	case 1349ULL: goto x86_l_545;
	case 1358ULL: goto x86_l_54e;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1387ULL: goto x86_l_56b;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1401ULL: goto x86_l_579;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1429ULL: goto x86_l_595;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1441ULL: goto x86_l_5a1;
	case 1449ULL: goto x86_l_5a9;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1469ULL: goto x86_l_5bd;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1487ULL: goto x86_l_5cf;
	case 1492ULL: goto x86_l_5d4;
	case 1497ULL: goto x86_l_5d9;
	case 1505ULL: goto x86_l_5e1;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1515ULL: goto x86_l_5eb;
	case 1520ULL: goto x86_l_5f0;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1536ULL: goto x86_l_600;
	case 1539ULL: goto x86_l_603;
	case 1544ULL: goto x86_l_608;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1561ULL: goto x86_l_619;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1614ULL: goto x86_l_64e;
	case 1622ULL: goto x86_l_656;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1651ULL: goto x86_l_673;
	case 1653ULL: goto x86_l_675;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1685ULL: goto x86_l_695;
	case 1687ULL: goto x86_l_697;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1701ULL: goto x86_l_6a5;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1739ULL: goto x86_l_6cb;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1753ULL: goto x86_l_6d9;
	case 1761ULL: goto x86_l_6e1;
	case 1763ULL: goto x86_l_6e3;
	case 1766ULL: goto x86_l_6e6;
	case 1770ULL: goto x86_l_6ea;
	case 1773ULL: goto x86_l_6ed;
	case 1777ULL: goto x86_l_6f1;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1784ULL: goto x86_l_6f8;
	case 1788ULL: goto x86_l_6fc;
	case 1791ULL: goto x86_l_6ff;
	case 1797ULL: goto x86_l_705;
	case 1803ULL: goto x86_l_70b;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
	case 1814ULL: goto x86_l_716;
	case 1819ULL: goto x86_l_71b;
	case 1821ULL: goto x86_l_71d;
	case 1824ULL: goto x86_l_720;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1844ULL: goto x86_l_734;
	case 1849ULL: goto x86_l_739;
	case 1852ULL: goto x86_l_73c;
	case 1858ULL: goto x86_l_742;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: lea    rsi,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_15:
	/* 0x15: mov    eax,0xb8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 184ULL);
x86_l_1a:
	/* 0x1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c:
	/* 0x1c: mov    rax,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24:
	/* 0x24: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2c:
	/* 0x2c: mov    DWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_37:
	/* 0x37: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_3e:
	/* 0x3e: lea    rsi,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_46:
	/* 0x46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: je     3002 <generic_fexit_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12290ULL;
	}
x86_l_56:
	/* 0x56: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_63:
	/* 0x63: mov    DWORD PTR [r15+0x5ef8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104419244900352ULL);
x86_l_6e:
	/* 0x6e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_75:
	/* 0x75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a:
	/* 0x7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c:
	/* 0x7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: je     3002 <generic_fexit_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12290ULL;
	}
x86_l_85:
	/* 0x85: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_88:
	/* 0x88: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8e:
	/* 0x8e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_93:
	/* 0x93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95:
	/* 0x95: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_99:
	/* 0x99: jne    9f <generic_fexit_event+0x9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9f;
	}
x86_l_9b:
	/* 0x9b: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f:
	/* 0x9f: mov    QWORD PTR [rbx+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a3:
	/* 0xa3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a8:
	/* 0xa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa:
	/* 0xaa: mov    DWORD PTR [rbx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_ad:
	/* 0xad: mov    rax,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b1:
	/* 0xb1: mov    rcx,QWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba:
	/* 0xba: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bf:
	/* 0xbf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
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
	/* 0xd5: je     3002 <generic_fexit_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12290ULL;
	}
x86_l_db:
	/* 0xdb: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de:
	/* 0xde: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ea:
	/* 0xea: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee:
	/* 0xee: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f6:
	/* 0xf6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_fd:
	/* 0xfd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_102:
	/* 0x102: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_107:
	/* 0x107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rbx+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_110:
	/* 0x110: mov    ebp,DWORD PTR [r12+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_115:
	/* 0x115: mov    r14d,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_11a:
	/* 0x11a: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: je     189 <generic_fexit_event+0x189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189;
	}
x86_l_11f:
	/* 0x11f: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_123:
	/* 0x123: mov    DWORD PTR [rbx+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_12d:
	/* 0x12d: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_135:
	/* 0x135: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_140:
	/* 0x140: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_147:
	/* 0x147: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_14f:
	/* 0x14f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_154:
	/* 0x154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156:
	/* 0x156: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: je     285 <generic_fexit_event+0x285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285;
	}
x86_l_15f:
	/* 0x15f: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16b:
	/* 0x16b: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_176:
	/* 0x176: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_178:
	/* 0x178: je     2e2 <generic_fexit_event+0x2e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e2;
	}
x86_l_17e:
	/* 0x17e: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_184:
	/* 0x184: jmp    288 <generic_fexit_event+0x288> */
	goto x86_l_288;
x86_l_189:
	/* 0x189: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_18f:
	/* 0x18f: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_196:
	/* 0x196: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_199:
	/* 0x199: jne    2cd7 <generic_fexit_event+0x2cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11479ULL;
	}
x86_l_19f:
	/* 0x19f: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a7:
	/* 0x1a7: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1aa:
	/* 0x1aa: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1ae:
	/* 0x1ae: cmp    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rsp+0xc0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c4:
	/* 0x1c4: je     34a <generic_fexit_event+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34a;
	}
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cf:
	/* 0x1cf: mov    r14,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1d7:
	/* 0x1d7: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1dc:
	/* 0x1dc: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1e2:
	/* 0x1e2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1e7:
	/* 0x1e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec:
	/* 0x1ec: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f4:
	/* 0x1f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f9:
	/* 0x1f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb:
	/* 0x1fb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_200:
	/* 0x200: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_202:
	/* 0x202: js     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6310ULL;
	}
x86_l_208:
	/* 0x208: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20d:
	/* 0x20d: cmp    rsi,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_210:
	/* 0x210: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_213:
	/* 0x213: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_216:
	/* 0x216: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_21a:
	/* 0x21a: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_221:
	/* 0x221: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_226:
	/* 0x226: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_22d:
	/* 0x22d: ja     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6310ULL;
	}
x86_l_233:
	/* 0x233: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_237:
	/* 0x237: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c:
	/* 0x23c: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_240:
	/* 0x240: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_245:
	/* 0x245: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24a:
	/* 0x24a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24f:
	/* 0x24f: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_252:
	/* 0x252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254:
	/* 0x254: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_259:
	/* 0x259: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b:
	/* 0x25b: js     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6310ULL;
	}
x86_l_261:
	/* 0x261: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_264:
	/* 0x264: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_267:
	/* 0x267: je     a87 <generic_fexit_event+0xa87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2695ULL;
	}
x86_l_26d:
	/* 0x26d: sub    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_270:
	/* 0x270: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_275:
	/* 0x275: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27a:
	/* 0x27a: jne    a93 <generic_fexit_event+0xa93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2707ULL;
	}
x86_l_280:
	/* 0x280: jmp    34d <generic_fexit_event+0x34d> */
	goto x86_l_34d;
x86_l_285:
	/* 0x285: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_288:
	/* 0x288: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28c:
	/* 0x28c: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_290:
	/* 0x290: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_295:
	/* 0x295: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_298:
	/* 0x298: je     2caa <generic_fexit_event+0x2caa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11434ULL;
	}
x86_l_29e:
	/* 0x29e: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2a1:
	/* 0x2a1: jne    2cc0 <generic_fexit_event+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11456ULL;
	}
x86_l_2a7:
	/* 0x2a7: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa:
	/* 0x2aa: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ae:
	/* 0x2ae: mov    eax,DWORD PTR [rbx+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2b1:
	/* 0x2b1: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2b5:
	/* 0x2b5: mov    rax,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b9:
	/* 0x2b9: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2be:
	/* 0x2be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2c5:
	/* 0x2c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c7:
	/* 0x2c7: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2cf:
	/* 0x2cf: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d4:
	/* 0x2d4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d9:
	/* 0x2d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2db:
	/* 0x2db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd:
	/* 0x2dd: jmp    2cc0 <generic_fexit_event+0x2cc0> */
	return 11456ULL;
x86_l_2e2:
	/* 0x2e2: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2e9:
	/* 0x2e9: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ee:
	/* 0x2ee: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2f7:
	/* 0x2f7: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300:
	/* 0x300: mov    QWORD PTR [rsp+0xc0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_308:
	/* 0x308: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30d:
	/* 0x30d: jle    362 <generic_fexit_event+0x362> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_362;
	}
x86_l_30f:
	/* 0x30f: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_313:
	/* 0x313: je     37d <generic_fexit_event+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37d;
	}
x86_l_315:
	/* 0x315: cmp    r14d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 37ULL);
x86_l_319:
	/* 0x319: je     3bb <generic_fexit_event+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_31f:
	/* 0x31f: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_323:
	/* 0x323: jne    8bb <generic_fexit_event+0x8bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2235ULL;
	}
x86_l_329:
	/* 0x329: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_335:
	/* 0x335: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_33d:
	/* 0x33d: lea    r12,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_345:
	/* 0x345: jmp    3e8 <generic_fexit_event+0x3e8> */
	goto x86_l_3e8;
x86_l_34a:
	/* 0x34a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34d:
	/* 0x34d: mov    DWORD PTR [r15+r14*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_351:
	/* 0x351: mov    DWORD PTR [r15+r14*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 4ULL);
x86_l_356:
	/* 0x356: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35a:
	/* 0x35a: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: jmp    18af <generic_fexit_event+0x18af> */
	return 6319ULL;
x86_l_362:
	/* 0x362: cmp    r14d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 15ULL);
x86_l_366:
	/* 0x366: je     7fa <generic_fexit_event+0x7fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2042ULL;
	}
x86_l_36c:
	/* 0x36c: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_370:
	/* 0x370: jne    8bb <generic_fexit_event+0x8bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2235ULL;
	}
x86_l_376:
	/* 0x376: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37b:
	/* 0x37b: jmp    3a5 <generic_fexit_event+0x3a5> */
	goto x86_l_3a5;
x86_l_37d:
	/* 0x37d: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_382:
	/* 0x382: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_387:
	/* 0x387: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38c:
	/* 0x38c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_391:
	/* 0x391: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_394:
	/* 0x394: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_399:
	/* 0x399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b:
	/* 0x39b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a5:
	/* 0x3a5: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3aa:
	/* 0x3aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3af:
	/* 0x3af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b4:
	/* 0x3b4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b9:
	/* 0x3b9: jmp    3d8 <generic_fexit_event+0x3d8> */
	goto x86_l_3d8;
x86_l_3bb:
	/* 0x3bb: add    rbp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3bf:
	/* 0x3bf: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3c4:
	/* 0x3c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c9:
	/* 0x3c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ce:
	/* 0x3ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d3:
	/* 0x3d3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3d8:
	/* 0x3d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dd:
	/* 0x3dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3df:
	/* 0x3df: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e4:
	/* 0x3e4: add    r12,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3e8:
	/* 0x3e8: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_3f3:
	/* 0x3f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_3fa:
	/* 0x3fa: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_402:
	/* 0x402: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_407:
	/* 0x407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409:
	/* 0x409: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40c:
	/* 0x40c: je     4c1 <generic_fexit_event+0x4c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1;
	}
x86_l_412:
	/* 0x412: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_415:
	/* 0x415: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_420:
	/* 0x420: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_425:
	/* 0x425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_427:
	/* 0x427: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_42e:
	/* 0x42e: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_436:
	/* 0x436: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43b:
	/* 0x43b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_440:
	/* 0x440: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_445:
	/* 0x445: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_447:
	/* 0x447: mov    rbp,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_44f:
	/* 0x44f: mov    QWORD PTR [rsp+0xf8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_457:
	/* 0x457: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45c:
	/* 0x45c: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_464:
	/* 0x464: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_469:
	/* 0x469: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46e:
	/* 0x46e: lea    rcx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_472:
	/* 0x472: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_47a:
	/* 0x47a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_487:
	/* 0x487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489:
	/* 0x489: mov    r12,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_491:
	/* 0x491: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_496:
	/* 0x496: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_49b:
	/* 0x49b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a0:
	/* 0x4a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a5:
	/* 0x4a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aa:
	/* 0x4aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac:
	/* 0x4ac: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4b2:
	/* 0x4b2: mov    r14d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4096ULL);
x86_l_4b8:
	/* 0x4b8: je     4ce <generic_fexit_event+0x4ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ce;
	}
x86_l_4ba:
	/* 0x4ba: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bf:
	/* 0x4bf: jmp    520 <generic_fexit_event+0x520> */
	goto x86_l_520;
x86_l_4c1:
	/* 0x4c1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c4:
	/* 0x4c4: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4c9:
	/* 0x4c9: jmp    a7e <generic_fexit_event+0xa7e> */
	return 2686ULL;
x86_l_4ce:
	/* 0x4ce: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d3:
	/* 0x4d3: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d8:
	/* 0x4d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4dd:
	/* 0x4dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e2:
	/* 0x4e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e7:
	/* 0x4e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e9:
	/* 0x4e9: cmp    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4ee:
	/* 0x4ee: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f3:
	/* 0x4f3: je     520 <generic_fexit_event+0x520> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_520;
	}
x86_l_4f5:
	/* 0x4f5: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_4ff:
	/* 0x4ff: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_509:
	/* 0x509: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_510:
	/* 0x510: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_51a:
	/* 0x51a: mov    r14d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4086ULL);
x86_l_520:
	/* 0x520: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_52e:
	/* 0x52e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_537:
	/* 0x537: mov    QWORD PTR [rsp+0x48],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_545:
	/* 0x545: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_54e:
	/* 0x54e: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_557:
	/* 0x557: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_561:
	/* 0x561: mov    DWORD PTR [rsp+0x70],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_566:
	/* 0x566: mov    BYTE PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_56b:
	/* 0x56b: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_56f:
	/* 0x56f: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_574:
	/* 0x574: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_579:
	/* 0x579: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57e:
	/* 0x57e: lea    r14,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_583:
	/* 0x583: lea    r15,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_588:
	/* 0x588: lea    r13,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_58d:
	/* 0x58d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_592:
	/* 0x592: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_595:
	/* 0x595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597:
	/* 0x597: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_59c:
	/* 0x59c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5a1:
	/* 0x5a1: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_5a9:
	/* 0x5a9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5ac:
	/* 0x5ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b1:
	/* 0x5b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b3:
	/* 0x5b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b8:
	/* 0x5b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5bd:
	/* 0x5bd: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_5c5:
	/* 0x5c5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5c8:
	/* 0x5c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cd:
	/* 0x5cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf:
	/* 0x5cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5d4:
	/* 0x5d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d9:
	/* 0x5d9: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5e1:
	/* 0x5e1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_5e4:
	/* 0x5e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e9:
	/* 0x5e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5eb:
	/* 0x5eb: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5f0:
	/* 0x5f0: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_5f4:
	/* 0x5f4: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5f9:
	/* 0x5f9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_600:
	/* 0x600: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_603:
	/* 0x603: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_608:
	/* 0x608: je     7d4 <generic_fexit_event+0x7d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2004ULL;
	}
x86_l_60e:
	/* 0x60e: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_613:
	/* 0x613: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_619:
	/* 0x619: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_61e:
	/* 0x61e: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_623:
	/* 0x623: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_628:
	/* 0x628: cmp    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_62d:
	/* 0x62d: jne    63a <generic_fexit_event+0x63a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_63a;
	}
x86_l_62f:
	/* 0x62f: cmp    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_634:
	/* 0x634: je     967 <generic_fexit_event+0x967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2407ULL;
	}
x86_l_63a:
	/* 0x63a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_63f:
	/* 0x63f: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_647:
	/* 0x647: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c:
	/* 0x64c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e:
	/* 0x64e: cmp    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 184ULL);
x86_l_656:
	/* 0x656: je     767 <generic_fexit_event+0x767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1895ULL;
	}
x86_l_65c:
	/* 0x65c: lea    r14,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_661:
	/* 0x661: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_666:
	/* 0x666: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66b:
	/* 0x66b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_670:
	/* 0x670: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_673:
	/* 0x673: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_675:
	/* 0x675: cmp    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67a:
	/* 0x67a: je     767 <generic_fexit_event+0x767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1895ULL;
	}
x86_l_680:
	/* 0x680: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_685:
	/* 0x685: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_68d:
	/* 0x68d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_692:
	/* 0x692: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_695:
	/* 0x695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_697:
	/* 0x697: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_69b:
	/* 0x69b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6a0:
	/* 0x6a0: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a5:
	/* 0x6a5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6aa:
	/* 0x6aa: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6af:
	/* 0x6af: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b4:
	/* 0x6b4: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6b9:
	/* 0x6b9: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6be:
	/* 0x6be: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_6c3:
	/* 0x6c3: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6c6:
	/* 0x6c6: mov    r13d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6cb:
	/* 0x6cb: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_6ce:
	/* 0x6ce: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6d1:
	/* 0x6d1: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_6d6:
	/* 0x6d6: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_6d9:
	/* 0x6d9: add    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_6e1:
	/* 0x6e1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e3:
	/* 0x6e3: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_6ea:
	/* 0x6ea: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6ed:
	/* 0x6ed: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_6f1:
	/* 0x6f1: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6f3:
	/* 0x6f3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_6f6:
	/* 0x6f6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6f8:
	/* 0x6f8: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6fc:
	/* 0x6fc: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6ff:
	/* 0x6ff: jb     96c <generic_fexit_event+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2412ULL;
	}
x86_l_705:
	/* 0x705: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_70b:
	/* 0x70b: ja     96c <generic_fexit_event+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2412ULL;
	}
x86_l_711:
	/* 0x711: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_714:
	/* 0x714: jbe    71b <generic_fexit_event+0x71b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_71b;
	}
x86_l_716:
	/* 0x716: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_71b:
	/* 0x71b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71d:
	/* 0x71d: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_720:
	/* 0x720: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_724:
	/* 0x724: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_727:
	/* 0x727: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_72a:
	/* 0x72a: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_72d:
	/* 0x72d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_732:
	/* 0x732: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_734:
	/* 0x734: mov    QWORD PTR [rsp+0x68],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_739:
	/* 0x739: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_73c:
	/* 0x73c: jbe    96c <generic_fexit_event+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2412ULL;
	}
x86_l_742:
	/* 0x742: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
	return 1866ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1943ULL: goto x86_l_797;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1965ULL: goto x86_l_7ad;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1993ULL: goto x86_l_7c9;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2011ULL: goto x86_l_7db;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2088ULL: goto x86_l_828;
	case 2099ULL: goto x86_l_833;
	case 2106ULL: goto x86_l_83a;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2127ULL: goto x86_l_84f;
	case 2133ULL: goto x86_l_855;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2162ULL: goto x86_l_872;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2178ULL: goto x86_l_882;
	case 2182ULL: goto x86_l_886;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2208ULL: goto x86_l_8a0;
	case 2218ULL: goto x86_l_8aa;
	case 2224ULL: goto x86_l_8b0;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2244ULL: goto x86_l_8c4;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2263ULL: goto x86_l_8d7;
	case 2267ULL: goto x86_l_8db;
	case 2273ULL: goto x86_l_8e1;
	case 2278ULL: goto x86_l_8e6;
	case 2289ULL: goto x86_l_8f1;
	case 2296ULL: goto x86_l_8f8;
	case 2304ULL: goto x86_l_900;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2314ULL: goto x86_l_90a;
	case 2317ULL: goto x86_l_90d;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2333ULL: goto x86_l_91d;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2363ULL: goto x86_l_93b;
	case 2367ULL: goto x86_l_93f;
	case 2370ULL: goto x86_l_942;
	case 2376ULL: goto x86_l_948;
	case 2381ULL: goto x86_l_94d;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2452ULL: goto x86_l_994;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2467ULL: goto x86_l_9a3;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2486ULL: goto x86_l_9b6;
	case 2489ULL: goto x86_l_9b9;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2516ULL: goto x86_l_9d4;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2545ULL: goto x86_l_9f1;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2568ULL: goto x86_l_a08;
	case 2573ULL: goto x86_l_a0d;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2604ULL: goto x86_l_a2c;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2630ULL: goto x86_l_a46;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2674ULL: goto x86_l_a72;
	case 2678ULL: goto x86_l_a76;
	case 2683ULL: goto x86_l_a7b;
	case 2686ULL: goto x86_l_a7e;
	case 2690ULL: goto x86_l_a82;
	case 2695ULL: goto x86_l_a87;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2734ULL: goto x86_l_aae;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2773ULL: goto x86_l_ad5;
	case 2779ULL: goto x86_l_adb;
	case 2784ULL: goto x86_l_ae0;
	case 2789ULL: goto x86_l_ae5;
	case 2792ULL: goto x86_l_ae8;
	case 2795ULL: goto x86_l_aeb;
	case 2799ULL: goto x86_l_aef;
	case 2802ULL: goto x86_l_af2;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2818ULL: goto x86_l_b02;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2864ULL: goto x86_l_b30;
	case 2872ULL: goto x86_l_b38;
	case 2874ULL: goto x86_l_b3a;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2889ULL: goto x86_l_b49;
	case 2895ULL: goto x86_l_b4f;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2906ULL: goto x86_l_b5a;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2961ULL: goto x86_l_b91;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2976ULL: goto x86_l_ba0;
	case 2980ULL: goto x86_l_ba4;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2996ULL: goto x86_l_bb4;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3021ULL: goto x86_l_bcd;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3053ULL: goto x86_l_bed;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3082ULL: goto x86_l_c0a;
	case 3089ULL: goto x86_l_c11;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3153ULL: goto x86_l_c51;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3178ULL: goto x86_l_c6a;
	case 3185ULL: goto x86_l_c71;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3215ULL: goto x86_l_c8f;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3237ULL: goto x86_l_ca5;
	case 3245ULL: goto x86_l_cad;
	case 3253ULL: goto x86_l_cb5;
	case 3261ULL: goto x86_l_cbd;
	case 3264ULL: goto x86_l_cc0;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3337ULL: goto x86_l_d09;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3351ULL: goto x86_l_d17;
	case 3357ULL: goto x86_l_d1d;
	case 3361ULL: goto x86_l_d21;
	case 3366ULL: goto x86_l_d26;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3395ULL: goto x86_l_d43;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3408ULL: goto x86_l_d50;
	case 3412ULL: goto x86_l_d54;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3476ULL: goto x86_l_d94;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3533ULL: goto x86_l_dcd;
	case 3537ULL: goto x86_l_dd1;
	case 3540ULL: goto x86_l_dd4;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3576ULL: goto x86_l_df8;
	case 3582ULL: goto x86_l_dfe;
	case 3586ULL: goto x86_l_e02;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3601ULL: goto x86_l_e11;
	case 3607ULL: goto x86_l_e17;
	case 3610ULL: goto x86_l_e1a;
	case 3615ULL: goto x86_l_e1f;
	case 3620ULL: goto x86_l_e24;
	case 3628ULL: goto x86_l_e2c;
	case 3636ULL: goto x86_l_e34;
	case 3644ULL: goto x86_l_e3c;
	case 3652ULL: goto x86_l_e44;
	case 3660ULL: goto x86_l_e4c;
	case 3668ULL: goto x86_l_e54;
	case 3676ULL: goto x86_l_e5c;
	case 3684ULL: goto x86_l_e64;
	case 3692ULL: goto x86_l_e6c;
	case 3700ULL: goto x86_l_e74;
	case 3708ULL: goto x86_l_e7c;
	case 3716ULL: goto x86_l_e84;
	case 3724ULL: goto x86_l_e8c;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_74a:
	/* 0x74a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_74f:
	/* 0x74f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_754:
	/* 0x754: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_75a:
	/* 0x75a: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_75c:
	/* 0x75c: jne    619 <generic_fexit_event+0x619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1561ULL;
	}
x86_l_762:
	/* 0x762: jmp    977 <generic_fexit_event+0x977> */
	goto x86_l_977;
x86_l_767:
	/* 0x767: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76b:
	/* 0x76b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_770:
	/* 0x770: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_775:
	/* 0x775: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77a:
	/* 0x77a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77c:
	/* 0x77c: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_781:
	/* 0x781: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_786:
	/* 0x786: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_78c:
	/* 0x78c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_791:
	/* 0x791: je     b6e <generic_fexit_event+0xb6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6e;
	}
x86_l_797:
	/* 0x797: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_79b:
	/* 0x79b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7a0:
	/* 0x7a0: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a5:
	/* 0x7a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7aa:
	/* 0x7aa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7ad:
	/* 0x7ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7af:
	/* 0x7af: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b4:
	/* 0x7b4: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7b9:
	/* 0x7b9: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7bd:
	/* 0x7bd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7c2:
	/* 0x7c2: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c7:
	/* 0x7c7: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_7c9:
	/* 0x7c9: jne    619 <generic_fexit_event+0x619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1561ULL;
	}
x86_l_7cf:
	/* 0x7cf: jmp    977 <generic_fexit_event+0x977> */
	goto x86_l_977;
x86_l_7d4:
	/* 0x7d4: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_7db:
	/* 0x7db: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7dd:
	/* 0x7dd: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7e2:
	/* 0x7e2: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_7e7:
	/* 0x7e7: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_7ec:
	/* 0x7ec: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_7f1:
	/* 0x7f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f3:
	/* 0x7f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f5:
	/* 0x7f5: jmp    971 <generic_fexit_event+0x971> */
	goto x86_l_971;
x86_l_7fa:
	/* 0x7fa: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ff:
	/* 0x7ff: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_804:
	/* 0x804: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_809:
	/* 0x809: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_80e:
	/* 0x80e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_813:
	/* 0x813: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_818:
	/* 0x818: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81a:
	/* 0x81a: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_81f:
	/* 0x81f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_822:
	/* 0x822: jne    3e8 <generic_fexit_event+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1000ULL;
	}
x86_l_828:
	/* 0x828: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_833:
	/* 0x833: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_83a:
	/* 0x83a: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_842:
	/* 0x842: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_847:
	/* 0x847: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_849:
	/* 0x849: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84c:
	/* 0x84c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84f:
	/* 0x84f: je     2c53 <generic_fexit_event+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11347ULL;
	}
x86_l_855:
	/* 0x855: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_859:
	/* 0x859: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_85e:
	/* 0x85e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_863:
	/* 0x863: jg     dbe <generic_fexit_event+0xdbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dbe;
	}
x86_l_869:
	/* 0x869: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_86d:
	/* 0x86d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_872:
	/* 0x872: jle    f1b <generic_fexit_event+0xf1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3867ULL;
	}
x86_l_878:
	/* 0x878: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_87c:
	/* 0x87c: jle    122a <generic_fexit_event+0x122a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4650ULL;
	}
x86_l_882:
	/* 0x882: cmp    r14d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 21ULL);
x86_l_886:
	/* 0x886: je     1c7a <generic_fexit_event+0x1c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7290ULL;
	}
x86_l_88c:
	/* 0x88c: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_890:
	/* 0x890: je     1be3 <generic_fexit_event+0x1be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7139ULL;
	}
x86_l_896:
	/* 0x896: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_89a:
	/* 0x89a: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_8a0:
	/* 0x8a0: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_8aa:
	/* 0x8aa: mov    DWORD PTR [rcx+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_8b0:
	/* 0x8b0: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_8b6:
	/* 0x8b6: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_8bb:
	/* 0x8bb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c0:
	/* 0x8c0: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_8c4:
	/* 0x8c4: ja     828 <generic_fexit_event+0x828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_828;
	}
x86_l_8ca:
	/* 0x8ca: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_8cd:
	/* 0x8cd: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_8d7:
	/* 0x8d7: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: jae    828 <generic_fexit_event+0x828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_828;
	}
x86_l_8e1:
	/* 0x8e1: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8e6:
	/* 0x8e6: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_8f8:
	/* 0x8f8: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_900:
	/* 0x900: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_905:
	/* 0x905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_907:
	/* 0x907: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90a:
	/* 0x90a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90d:
	/* 0x90d: je     2c53 <generic_fexit_event+0x2c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11347ULL;
	}
x86_l_913:
	/* 0x913: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_917:
	/* 0x917: jle    b7d <generic_fexit_event+0xb7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b7d;
	}
x86_l_91d:
	/* 0x91d: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_921:
	/* 0x921: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_926:
	/* 0x926: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92b:
	/* 0x92b: jle    cff <generic_fexit_event+0xcff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cff;
	}
x86_l_931:
	/* 0x931: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_935:
	/* 0x935: jg     df4 <generic_fexit_event+0xdf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_df4;
	}
x86_l_93b:
	/* 0x93b: lea    eax,[r14-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_93f:
	/* 0x93f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_942:
	/* 0x942: jae    1313 <generic_fexit_event+0x1313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4883ULL;
	}
x86_l_948:
	/* 0x948: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94d:
	/* 0x94d: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_953:
	/* 0x953: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_958:
	/* 0x958: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_95d:
	/* 0x95d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_962:
	/* 0x962: jmp    121e <generic_fexit_event+0x121e> */
	return 4638ULL;
x86_l_967:
	/* 0x967: mov    BYTE PTR [rsp+0x74],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206337ULL);
x86_l_96c:
	/* 0x96c: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_971:
	/* 0x971: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_977:
	/* 0x977: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_97c:
	/* 0x97c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_981:
	/* 0x981: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_983:
	/* 0x983: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_986:
	/* 0x986: je     9c0 <generic_fexit_event+0x9c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c0;
	}
x86_l_988:
	/* 0x988: cmp    BYTE PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_98d:
	/* 0x98d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_990:
	/* 0x990: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_994:
	/* 0x994: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_99a:
	/* 0x99a: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_99d:
	/* 0x99d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_99f:
	/* 0x99f: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_9a3:
	/* 0x9a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a6:
	/* 0x9a6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ab:
	/* 0x9ab: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b0:
	/* 0x9b0: je     a7b <generic_fexit_event+0xa7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7b;
	}
x86_l_9b6:
	/* 0x9b6: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_9b9:
	/* 0x9b9: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9bb:
	/* 0x9bb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: jmp    9cd <generic_fexit_event+0x9cd> */
	goto x86_l_9cd;
x86_l_9c0:
	/* 0x9c0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c3:
	/* 0x9c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c8:
	/* 0x9c8: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9cd:
	/* 0x9cd: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_9d4:
	/* 0x9d4: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9db:
	/* 0x9db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9e0:
	/* 0x9e0: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_9e3:
	/* 0x9e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e5:
	/* 0x9e5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ea:
	/* 0x9ea: mov    DWORD PTR [rax+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_9f1:
	/* 0x9f1: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9f6:
	/* 0x9f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9fb:
	/* 0x9fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a00:
	/* 0xa00: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a08:
	/* 0xa08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a0d:
	/* 0xa0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0f:
	/* 0xa0f: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a14:
	/* 0xa14: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a18:
	/* 0xa18: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a1d:
	/* 0xa1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a22:
	/* 0xa22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a27:
	/* 0xa27: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a2c:
	/* 0xa2c: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a30:
	/* 0xa30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a35:
	/* 0xa35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a37:
	/* 0xa37: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a3c:
	/* 0xa3c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a41:
	/* 0xa41: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_a46:
	/* 0xa46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a4b:
	/* 0xa4b: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a50:
	/* 0xa50: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a55:
	/* 0xa55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a57:
	/* 0xa57: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5c:
	/* 0xa5c: mov    DWORD PTR [rcx+r13*1+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 160ULL);
x86_l_a64:
	/* 0xa64: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_a69:
	/* 0xa69: mov    WORD PTR [rcx+r13*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 164ULL);
x86_l_a72:
	/* 0xa72: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_a76:
	/* 0xa76: jmp    2c63 <generic_fexit_event+0x2c63> */
	return 11363ULL;
x86_l_a7b:
	/* 0xa7b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7e:
	/* 0xa7e: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a82:
	/* 0xa82: jmp    2c6c <generic_fexit_event+0x2c6c> */
	return 11372ULL;
x86_l_a87:
	/* 0xa87: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a89:
	/* 0xa89: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8e:
	/* 0xa8e: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a93:
	/* 0xa93: cmp    QWORD PTR [rsp+0x90],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290625ULL);
x86_l_a9c:
	/* 0xa9c: jne    aa6 <generic_fexit_event+0xaa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aa6;
	}
x86_l_a9e:
	/* 0xa9e: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: jmp    34d <generic_fexit_event+0x34d> */
	return 845ULL;
x86_l_aa6:
	/* 0xaa6: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_aae:
	/* 0xaae: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab2:
	/* 0xab2: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ab7:
	/* 0xab7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_abd:
	/* 0xabd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_ac2:
	/* 0xac2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ac7:
	/* 0xac7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_acc:
	/* 0xacc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ace:
	/* 0xace: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_ad3:
	/* 0xad3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ad5:
	/* 0xad5: js     18ab <generic_fexit_event+0x18ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6315ULL;
	}
x86_l_adb:
	/* 0xadb: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ae0:
	/* 0xae0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae5:
	/* 0xae5: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ae8:
	/* 0xae8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_aeb:
	/* 0xaeb: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_aef:
	/* 0xaef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af2:
	/* 0xaf2: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_af6:
	/* 0xaf6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_afb:
	/* 0xafb: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_b02:
	/* 0xb02: ja     18ab <generic_fexit_event+0x18ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6315ULL;
	}
x86_l_b08:
	/* 0xb08: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0d:
	/* 0xb0d: add    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b10:
	/* 0xb10: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b15:
	/* 0xb15: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b19:
	/* 0xb19: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b1e:
	/* 0xb1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b23:
	/* 0xb23: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b28:
	/* 0xb28: mov    QWORD PTR [rsp+0x88],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b30:
	/* 0xb30: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b38:
	/* 0xb38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3a:
	/* 0xb3a: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b42:
	/* 0xb42: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_b47:
	/* 0xb47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b49:
	/* 0xb49: js     18ab <generic_fexit_event+0x18ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6315ULL;
	}
x86_l_b4f:
	/* 0xb4f: add    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b52:
	/* 0xb52: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b57:
	/* 0xb57: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_b5a:
	/* 0xb5a: je     17ce <generic_fexit_event+0x17ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6094ULL;
	}
x86_l_b60:
	/* 0xb60: sub    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b63:
	/* 0xb63: jne    17d1 <generic_fexit_event+0x17d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6097ULL;
	}
x86_l_b69:
	/* 0xb69: jmp    18c7 <generic_fexit_event+0x18c7> */
	return 6343ULL;
x86_l_b6e:
	/* 0xb6e: mov    BYTE PTR [rsp+0x74],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206337ULL);
x86_l_b73:
	/* 0xb73: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b78:
	/* 0xb78: jmp    977 <generic_fexit_event+0x977> */
	goto x86_l_977;
x86_l_b7d:
	/* 0xb7d: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_b81:
	/* 0xb81: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b86:
	/* 0xb86: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b8b:
	/* 0xb8b: jg     d31 <generic_fexit_event+0xd31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d31;
	}
x86_l_b91:
	/* 0xb91: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_b95:
	/* 0xb95: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9a:
	/* 0xb9a: jle    f6e <generic_fexit_event+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3950ULL;
	}
x86_l_ba0:
	/* 0xba0: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_ba4:
	/* 0xba4: je     151d <generic_fexit_event+0x151d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5405ULL;
	}
x86_l_baa:
	/* 0xbaa: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_bae:
	/* 0xbae: je     d9b <generic_fexit_event+0xd9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d9b;
	}
x86_l_bb4:
	/* 0xbb4: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_bb8:
	/* 0xbb8: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_bbe:
	/* 0xbbe: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_bc1:
	/* 0xbc1: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bc6:
	/* 0xbc6: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_bcd:
	/* 0xbcd: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_bd4:
	/* 0xbd4: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bd9:
	/* 0xbd9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bde:
	/* 0xbde: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_be1:
	/* 0xbe1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_be6:
	/* 0xbe6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_beb:
	/* 0xbeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bed:
	/* 0xbed: lea    rdi,[r14+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_bf4:
	/* 0xbf4: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_bf9:
	/* 0xbf9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bfe:
	/* 0xbfe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c03:
	/* 0xc03: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_c08:
	/* 0xc08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c0a:
	/* 0xc0a: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_c11:
	/* 0xc11: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c19:
	/* 0xc19: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
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
	/* 0xc2a: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c31:
	/* 0xc31: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c39:
	/* 0xc39: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c3e:
	/* 0xc3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c43:
	/* 0xc43: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c48:
	/* 0xc48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4a:
	/* 0xc4a: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_c51:
	/* 0xc51: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c59:
	/* 0xc59: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c5e:
	/* 0xc5e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c63:
	/* 0xc63: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c68:
	/* 0xc68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6a:
	/* 0xc6a: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c71:
	/* 0xc71: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c79:
	/* 0xc79: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c7e:
	/* 0xc7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c83:
	/* 0xc83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c88:
	/* 0xc88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8a:
	/* 0xc8a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8f:
	/* 0xc8f: lea    r13,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_c96:
	/* 0xc96: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9d:
	/* 0xc9d: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ca5:
	/* 0xca5: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_cad:
	/* 0xcad: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cb5:
	/* 0xcb5: movzx  eax,WORD PTR [r14+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_cbd:
	/* 0xcbd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_cc0:
	/* 0xcc0: je     1ff9 <generic_fexit_event+0x1ff9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8185ULL;
	}
x86_l_cc6:
	/* 0xcc6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cc9:
	/* 0xcc9: jne    2028 <generic_fexit_event+0x2028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8232ULL;
	}
x86_l_ccf:
	/* 0xccf: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cd4:
	/* 0xcd4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cd9:
	/* 0xcd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cde:
	/* 0xcde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ce3:
	/* 0xce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce5:
	/* 0xce5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cea:
	/* 0xcea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cef:
	/* 0xcef: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_cf2:
	/* 0xcf2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cf7:
	/* 0xcf7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_cfa:
	/* 0xcfa: jmp    2026 <generic_fexit_event+0x2026> */
	return 8230ULL;
x86_l_cff:
	/* 0xcff: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_d03:
	/* 0xd03: jg     f4f <generic_fexit_event+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3919ULL;
	}
x86_l_d09:
	/* 0xd09: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_d0d:
	/* 0xd0d: je     1351 <generic_fexit_event+0x1351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4945ULL;
	}
x86_l_d13:
	/* 0xd13: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_d17:
	/* 0xd17: je     1424 <generic_fexit_event+0x1424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5156ULL;
	}
x86_l_d1d:
	/* 0xd1d: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_d21:
	/* 0xd21: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d26:
	/* 0xd26: je     f7e <generic_fexit_event+0xf7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3966ULL;
	}
x86_l_d2c:
	/* 0xd2c: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_d31:
	/* 0xd31: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d35:
	/* 0xd35: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d38:
	/* 0xd38: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d3d:
	/* 0xd3d: jb     f7e <generic_fexit_event+0xf7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3966ULL;
	}
x86_l_d43:
	/* 0xd43: lea    eax,[r14-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d47:
	/* 0xd47: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d4a:
	/* 0xd4a: jb     f9d <generic_fexit_event+0xf9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3997ULL;
	}
x86_l_d50:
	/* 0xd50: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_d54:
	/* 0xd54: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_d5a:
	/* 0xd5a: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d5f:
	/* 0xd5f: lea    r14,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d64:
	/* 0xd64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d69:
	/* 0xd69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d6e:
	/* 0xd6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d73:
	/* 0xd73: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_d76:
	/* 0xd76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d78:
	/* 0xd78: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d7d:
	/* 0xd7d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d82:
	/* 0xd82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d87:
	/* 0xd87: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d8c:
	/* 0xd8c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_d8f:
	/* 0xd8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d94:
	/* 0xd94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d96:
	/* 0xd96: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9b:
	/* 0xd9b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da0:
	/* 0xda0: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_da3:
	/* 0xda3: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_daa:
	/* 0xdaa: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_daf:
	/* 0xdaf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_db4:
	/* 0xdb4: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_db9:
	/* 0xdb9: jmp    170a <generic_fexit_event+0x170a> */
	return 5898ULL;
x86_l_dbe:
	/* 0xdbe: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_dc2:
	/* 0xdc2: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc7:
	/* 0xdc7: jle    113d <generic_fexit_event+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4413ULL;
	}
x86_l_dcd:
	/* 0xdcd: lea    edx,[r14-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_dd1:
	/* 0xdd1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_dd4:
	/* 0xdd4: jae    fbc <generic_fexit_event+0xfbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4028ULL;
	}
x86_l_dda:
	/* 0xdda: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_de0:
	/* 0xde0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_de5:
	/* 0xde5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dea:
	/* 0xdea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_def:
	/* 0xdef: jmp    121b <generic_fexit_event+0x121b> */
	return 4635ULL;
x86_l_df4:
	/* 0xdf4: cmp    r14d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 39ULL);
x86_l_df8:
	/* 0xdf8: je     16e5 <generic_fexit_event+0x16e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5861ULL;
	}
x86_l_dfe:
	/* 0xdfe: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_e02:
	/* 0xe02: je     172c <generic_fexit_event+0x172c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5932ULL;
	}
x86_l_e08:
	/* 0xe08: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_e0c:
	/* 0xe0c: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e11:
	/* 0xe11: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_e17:
	/* 0xe17: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_e1a:
	/* 0xe1a: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e1f:
	/* 0xe1f: mov    BYTE PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e24:
	/* 0xe24: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e2c:
	/* 0xe2c: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e34:
	/* 0xe34: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e3c:
	/* 0xe3c: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e44:
	/* 0xe44: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e4c:
	/* 0xe4c: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e54:
	/* 0xe54: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e5c:
	/* 0xe5c: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e6c:
	/* 0xe6c: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e74:
	/* 0xe74: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e7c:
	/* 0xe7c: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e84:
	/* 0xe84: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e8c:
	/* 0xe8c: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e93:
	/* 0xe93: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e98:
	/* 0xe98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e9d:
	/* 0xe9d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ea2:
	/* 0xea2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ea5:
	/* 0xea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea7:
	/* 0xea7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eaa:
	/* 0xeaa: js     2250 <generic_fexit_event+0x2250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8784ULL;
	}
x86_l_eb0:
	/* 0xeb0: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
	return 3765ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3788ULL: goto x86_l_ecc;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3807ULL: goto x86_l_edf;
	case 3814ULL: goto x86_l_ee6;
	case 3819ULL: goto x86_l_eeb;
	case 3826ULL: goto x86_l_ef2;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3852ULL: goto x86_l_f0c;
	case 3854ULL: goto x86_l_f0e;
	case 3860ULL: goto x86_l_f14;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3877ULL: goto x86_l_f25;
	case 3881ULL: goto x86_l_f29;
	case 3887ULL: goto x86_l_f2f;
	case 3891ULL: goto x86_l_f33;
	case 3897ULL: goto x86_l_f39;
	case 3908ULL: goto x86_l_f44;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3954ULL: goto x86_l_f72;
	case 3956ULL: goto x86_l_f74;
	case 3960ULL: goto x86_l_f78;
	case 3966ULL: goto x86_l_f7e;
	case 3972ULL: goto x86_l_f84;
	case 3977ULL: goto x86_l_f89;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3992ULL: goto x86_l_f98;
	case 3997ULL: goto x86_l_f9d;
	case 4002ULL: goto x86_l_fa2;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4038ULL: goto x86_l_fc6;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4059ULL: goto x86_l_fdb;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4120ULL: goto x86_l_1018;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4137ULL: goto x86_l_1029;
	case 4142ULL: goto x86_l_102e;
	case 4147ULL: goto x86_l_1033;
	case 4149ULL: goto x86_l_1035;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4178ULL: goto x86_l_1052;
	case 4185ULL: goto x86_l_1059;
	case 4193ULL: goto x86_l_1061;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4210ULL: goto x86_l_1072;
	case 4217ULL: goto x86_l_1079;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4249ULL: goto x86_l_1099;
	case 4257ULL: goto x86_l_10a1;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4269ULL: goto x86_l_10ad;
	case 4276ULL: goto x86_l_10b4;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4296ULL: goto x86_l_10c8;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4313ULL: goto x86_l_10d9;
	case 4321ULL: goto x86_l_10e1;
	case 4329ULL: goto x86_l_10e9;
	case 4337ULL: goto x86_l_10f1;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4372ULL: goto x86_l_1114;
	case 4377ULL: goto x86_l_1119;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4387ULL: goto x86_l_1123;
	case 4392ULL: goto x86_l_1128;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4408ULL: goto x86_l_1138;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4423ULL: goto x86_l_1147;
	case 4427ULL: goto x86_l_114b;
	case 4433ULL: goto x86_l_1151;
	case 4441ULL: goto x86_l_1159;
	case 4449ULL: goto x86_l_1161;
	case 4457ULL: goto x86_l_1169;
	case 4465ULL: goto x86_l_1171;
	case 4473ULL: goto x86_l_1179;
	case 4481ULL: goto x86_l_1181;
	case 4489ULL: goto x86_l_1189;
	case 4497ULL: goto x86_l_1191;
	case 4505ULL: goto x86_l_1199;
	case 4512ULL: goto x86_l_11a0;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4540ULL: goto x86_l_11bc;
	case 4543ULL: goto x86_l_11bf;
	case 4549ULL: goto x86_l_11c5;
	case 4554ULL: goto x86_l_11ca;
	case 4557ULL: goto x86_l_11cd;
	case 4564ULL: goto x86_l_11d4;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4591ULL: goto x86_l_11ef;
	case 4594ULL: goto x86_l_11f2;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4609ULL: goto x86_l_1201;
	case 4615ULL: goto x86_l_1207;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4654ULL: goto x86_l_122e;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4670ULL: goto x86_l_123e;
	case 4679ULL: goto x86_l_1247;
	case 4686ULL: goto x86_l_124e;
	case 4689ULL: goto x86_l_1251;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4710ULL: goto x86_l_1266;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4724ULL: goto x86_l_1274;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4744ULL: goto x86_l_1288;
	case 4747ULL: goto x86_l_128b;
	case 4752ULL: goto x86_l_1290;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4787ULL: goto x86_l_12b3;
	case 4790ULL: goto x86_l_12b6;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4804ULL: goto x86_l_12c4;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4828ULL: goto x86_l_12dc;
	case 4833ULL: goto x86_l_12e1;
	case 4840ULL: goto x86_l_12e8;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4914ULL: goto x86_l_1332;
	case 4917ULL: goto x86_l_1335;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4953ULL: goto x86_l_1359;
	case 4962ULL: goto x86_l_1362;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5014ULL: goto x86_l_1396;
	case 5018ULL: goto x86_l_139a;
	case 5022ULL: goto x86_l_139e;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5041ULL: goto x86_l_13b1;
	case 5044ULL: goto x86_l_13b4;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5086ULL: goto x86_l_13de;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5105ULL: goto x86_l_13f1;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5119ULL: goto x86_l_13ff;
	case 5123ULL: goto x86_l_1403;
	case 5127ULL: goto x86_l_1407;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5147ULL: goto x86_l_141b;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5195ULL: goto x86_l_144b;
	case 5198ULL: goto x86_l_144e;
	case 5200ULL: goto x86_l_1450;
	case 5208ULL: goto x86_l_1458;
	case 5210ULL: goto x86_l_145a;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5225ULL: goto x86_l_1469;
	case 5229ULL: goto x86_l_146d;
	case 5234ULL: goto x86_l_1472;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5250ULL: goto x86_l_1482;
	case 5255ULL: goto x86_l_1487;
	case 5258ULL: goto x86_l_148a;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5296ULL: goto x86_l_14b0;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5334ULL: goto x86_l_14d6;
	case 5341ULL: goto x86_l_14dd;
	case 5347ULL: goto x86_l_14e3;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5379ULL: goto x86_l_1503;
	case 5386ULL: goto x86_l_150a;
	case 5393ULL: goto x86_l_1511;
	case 5397ULL: goto x86_l_1515;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5417ULL: goto x86_l_1529;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5444ULL: goto x86_l_1544;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5479ULL: goto x86_l_1567;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5503ULL: goto x86_l_157f;
	case 5510ULL: goto x86_l_1586;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5534ULL: goto x86_l_159e;
	case 5543ULL: goto x86_l_15a7;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5565ULL: goto x86_l_15bd;
	case 5570ULL: goto x86_l_15c2;
	case 5572ULL: goto x86_l_15c4;
	case 5579ULL: goto x86_l_15cb;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5613ULL: goto x86_l_15ed;
	case 5618ULL: goto x86_l_15f2;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_eb5:
	/* 0xeb5: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eba:
	/* 0xeba: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ebf:
	/* 0xebf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_ec9:
	/* 0xec9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ecc:
	/* 0xecc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ece:
	/* 0xece: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed1:
	/* 0xed1: js     2250 <generic_fexit_event+0x2250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8784ULL;
	}
x86_l_ed7:
	/* 0xed7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edc:
	/* 0xedc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_ee6:
	/* 0xee6: cmp    BYTE PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_eeb:
	/* 0xeeb: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_ef2:
	/* 0xef2: je     2224 <generic_fexit_event+0x2224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8740ULL;
	}
x86_l_ef8:
	/* 0xef8: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_efd:
	/* 0xefd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_f02:
	/* 0xf02: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_f07:
	/* 0xf07: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_f0a:
	/* 0xf0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f0c:
	/* 0xf0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f0e:
	/* 0xf0e: js     2250 <generic_fexit_event+0x2250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8784ULL;
	}
x86_l_f14:
	/* 0xf14: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_f16:
	/* 0xf16: jmp    2245 <generic_fexit_event+0x2245> */
	return 8773ULL;
x86_l_f1b:
	/* 0xf1b: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_f1f:
	/* 0xf1f: jg     11fd <generic_fexit_event+0x11fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11fd;
	}
x86_l_f25:
	/* 0xf25: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_f29:
	/* 0xf29: je     18d4 <generic_fexit_event+0x18d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6356ULL;
	}
x86_l_f2f:
	/* 0xf2f: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_f33:
	/* 0xf33: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_f39:
	/* 0xf39: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_f44:
	/* 0xf44: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_f4a:
	/* 0xf4a: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_f4f:
	/* 0xf4f: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f54:
	/* 0xf54: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f5a:
	/* 0xf5a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f5f:
	/* 0xf5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f64:
	/* 0xf64: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f69:
	/* 0xf69: jmp    121e <generic_fexit_event+0x121e> */
	goto x86_l_121e;
x86_l_f6e:
	/* 0xf6e: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_f72:
	/* 0xf72: je     f9d <generic_fexit_event+0xf9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9d;
	}
x86_l_f74:
	/* 0xf74: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_f78:
	/* 0xf78: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_f7e:
	/* 0xf7e: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_f84:
	/* 0xf84: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f89:
	/* 0xf89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f8e:
	/* 0xf8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f93:
	/* 0xf93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f98:
	/* 0xf98: jmp    121e <generic_fexit_event+0x121e> */
	goto x86_l_121e;
x86_l_f9d:
	/* 0xf9d: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fa2:
	/* 0xfa2: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_fa8:
	/* 0xfa8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fad:
	/* 0xfad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb2:
	/* 0xfb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fb7:
	/* 0xfb7: jmp    121e <generic_fexit_event+0x121e> */
	goto x86_l_121e;
x86_l_fbc:
	/* 0xfbc: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_fc0:
	/* 0xfc0: je     1d82 <generic_fexit_event+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7554ULL;
	}
x86_l_fc6:
	/* 0xfc6: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_fca:
	/* 0xfca: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_fd0:
	/* 0xfd0: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_fd3:
	/* 0xfd3: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fdb:
	/* 0xfdb: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_fdf:
	/* 0xfdf: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fe4:
	/* 0xfe4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_fea:
	/* 0xfea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fef:
	/* 0xfef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff4:
	/* 0xff4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff9:
	/* 0xff9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1003:
	/* 0x1003: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1006:
	/* 0x1006: je     22ee <generic_fexit_event+0x22ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8942ULL;
	}
x86_l_100c:
	/* 0x100c: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1011:
	/* 0x1011: mov    QWORD PTR [rbp+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1018:
	/* 0x1018: lea    rdi,[rbp+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_101f:
	/* 0x101f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1024:
	/* 0x1024: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1029:
	/* 0x1029: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_102e:
	/* 0x102e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1033:
	/* 0x1033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1035:
	/* 0x1035: lea    rdi,[rbp+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_103c:
	/* 0x103c: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1041:
	/* 0x1041: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1046:
	/* 0x1046: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_104b:
	/* 0x104b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1050:
	/* 0x1050: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1052:
	/* 0x1052: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1059:
	/* 0x1059: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1061:
	/* 0x1061: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1066:
	/* 0x1066: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_106b:
	/* 0x106b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1070:
	/* 0x1070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1072:
	/* 0x1072: lea    rdi,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1079:
	/* 0x1079: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1081:
	/* 0x1081: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1086:
	/* 0x1086: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_108b:
	/* 0x108b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1090:
	/* 0x1090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1092:
	/* 0x1092: lea    rdi,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1099:
	/* 0x1099: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_10a1:
	/* 0x10a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a6:
	/* 0x10a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10ab:
	/* 0x10ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ad:
	/* 0x10ad: lea    rdi,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_10b4:
	/* 0x10b4: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_10bc:
	/* 0x10bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10c1:
	/* 0x10c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10c6:
	/* 0x10c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c8:
	/* 0x10c8: lea    r13,[rbp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_10cf:
	/* 0x10cf: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: mov    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d9:
	/* 0x10d9: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10e1:
	/* 0x10e1: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10e9:
	/* 0x10e9: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10f1:
	/* 0x10f1: movzx  eax,WORD PTR [rbp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_10f8:
	/* 0x10f8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10fb:
	/* 0x10fb: je     2263 <generic_fexit_event+0x2263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8803ULL;
	}
x86_l_1101:
	/* 0x1101: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1104:
	/* 0x1104: jne    2295 <generic_fexit_event+0x2295> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8853ULL;
	}
x86_l_110a:
	/* 0x110a: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_110f:
	/* 0x110f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1114:
	/* 0x1114: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1119:
	/* 0x1119: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_111c:
	/* 0x111c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1121:
	/* 0x1121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1123:
	/* 0x1123: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1128:
	/* 0x1128: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_112d:
	/* 0x112d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1130:
	/* 0x1130: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1135:
	/* 0x1135: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1138:
	/* 0x1138: jmp    2293 <generic_fexit_event+0x2293> */
	return 8851ULL;
x86_l_113d:
	/* 0x113d: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_1141:
	/* 0x1141: je     1e30 <generic_fexit_event+0x1e30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7728ULL;
	}
x86_l_1147:
	/* 0x1147: cmp    r14d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 27ULL);
x86_l_114b:
	/* 0x114b: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_1151:
	/* 0x1151: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1159:
	/* 0x1159: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1161:
	/* 0x1161: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1169:
	/* 0x1169: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1171:
	/* 0x1171: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1179:
	/* 0x1179: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1181:
	/* 0x1181: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1189:
	/* 0x1189: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1191:
	/* 0x1191: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1199:
	/* 0x1199: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a0:
	/* 0x11a0: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_11a7:
	/* 0x11a7: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ab:
	/* 0x11ab: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_11b0:
	/* 0x11b0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_11b5:
	/* 0x11b5: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_11ba:
	/* 0x11ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bc:
	/* 0x11bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11bf:
	/* 0x11bf: js     1ea4 <generic_fexit_event+0x1ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7844ULL;
	}
x86_l_11c5:
	/* 0x11c5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ca:
	/* 0x11ca: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_11cd:
	/* 0x11cd: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_11d4:
	/* 0x11d4: add    rbp,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_11db:
	/* 0x11db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11e0:
	/* 0x11e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11e5:
	/* 0x11e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11ea:
	/* 0x11ea: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11ed:
	/* 0x11ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ef:
	/* 0x11ef: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_11f2:
	/* 0x11f2: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_11f8:
	/* 0x11f8: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_11fd:
	/* 0x11fd: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1201:
	/* 0x1201: je     198a <generic_fexit_event+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6538ULL;
	}
x86_l_1207:
	/* 0x1207: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_120b:
	/* 0x120b: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_1211:
	/* 0x1211: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1214:
	/* 0x1214: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1219:
	/* 0x1219: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121b:
	/* 0x121b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1225:
	/* 0x1225: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_122a:
	/* 0x122a: cmp    r14d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 19ULL);
x86_l_122e:
	/* 0x122e: je     1d26 <generic_fexit_event+0x1d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7462ULL;
	}
x86_l_1234:
	/* 0x1234: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_1238:
	/* 0x1238: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_123e:
	/* 0x123e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1247:
	/* 0x1247: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_124e:
	/* 0x124e: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_1251:
	/* 0x1251: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1256:
	/* 0x1256: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_125b:
	/* 0x125b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1260:
	/* 0x1260: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_1263:
	/* 0x1263: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1266:
	/* 0x1266: lea    r12,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_126d:
	/* 0x126d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1272:
	/* 0x1272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1274:
	/* 0x1274: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1279:
	/* 0x1279: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_127e:
	/* 0x127e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1283:
	/* 0x1283: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1288:
	/* 0x1288: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_128b:
	/* 0x128b: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1290:
	/* 0x1290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1292:
	/* 0x1292: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1297:
	/* 0x1297: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_129e:
	/* 0x129e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12a3:
	/* 0x12a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a8:
	/* 0x12a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12ad:
	/* 0x12ad: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_12b3:
	/* 0x12b3: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_12b6:
	/* 0x12b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b8:
	/* 0x12b8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12bd:
	/* 0x12bd: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_12c4:
	/* 0x12c4: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_12cb:
	/* 0x12cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d0:
	/* 0x12d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d5:
	/* 0x12d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12da:
	/* 0x12da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12dc:
	/* 0x12dc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e1:
	/* 0x12e1: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_12e8:
	/* 0x12e8: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_12ef:
	/* 0x12ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12f4:
	/* 0x12f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f9:
	/* 0x12f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12fe:
	/* 0x12fe: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1301:
	/* 0x1301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1303:
	/* 0x1303: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1308:
	/* 0x1308: mov    r13d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 152ULL);
x86_l_130e:
	/* 0x130e: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_1313:
	/* 0x1313: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_1317:
	/* 0x1317: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131c:
	/* 0x131c: jne    2c5d <generic_fexit_event+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11357ULL;
	}
x86_l_1322:
	/* 0x1322: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1327:
	/* 0x1327: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_132a:
	/* 0x132a: add    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 192ULL);
x86_l_1332:
	/* 0x1332: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1335:
	/* 0x1335: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_133b:
	/* 0x133b: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_133e:
	/* 0x133e: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1345:
	/* 0x1345: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1347:
	/* 0x1347: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_134c:
	/* 0x134c: jmp    170a <generic_fexit_event+0x170a> */
	return 5898ULL;
x86_l_1351:
	/* 0x1351: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1356:
	/* 0x1356: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1359:
	/* 0x1359: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1362:
	/* 0x1362: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_136b:
	/* 0x136b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1370:
	/* 0x1370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1372:
	/* 0x1372: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1376:
	/* 0x1376: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_137b:
	/* 0x137b: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1380:
	/* 0x1380: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1385:
	/* 0x1385: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_138a:
	/* 0x138a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_138f:
	/* 0x138f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1394:
	/* 0x1394: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1396:
	/* 0x1396: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_139a:
	/* 0x139a: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_139e:
	/* 0x139e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_13a5:
	/* 0x13a5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13aa:
	/* 0x13aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13af:
	/* 0x13af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b1:
	/* 0x13b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b4:
	/* 0x13b4: je     1eac <generic_fexit_event+0x1eac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7852ULL;
	}
x86_l_13ba:
	/* 0x13ba: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bd:
	/* 0x13bd: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13c2:
	/* 0x13c2: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13c5:
	/* 0x13c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ca:
	/* 0x13ca: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cf:
	/* 0x13cf: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_13d4:
	/* 0x13d4: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13dc:
	/* 0x13dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13de:
	/* 0x13de: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13e5:
	/* 0x13e5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ea:
	/* 0x13ea: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_13f1:
	/* 0x13f1: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13f5:
	/* 0x13f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13fa:
	/* 0x13fa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13fd:
	/* 0x13fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ff:
	/* 0x13ff: lea    rdi,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1403:
	/* 0x1403: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1407:
	/* 0x1407: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_140b:
	/* 0x140b: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_140f:
	/* 0x140f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1414:
	/* 0x1414: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1419:
	/* 0x1419: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141b:
	/* 0x141b: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_141f:
	/* 0x141f: jmp    2212 <generic_fexit_event+0x2212> */
	return 8722ULL;
x86_l_1424:
	/* 0x1424: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1429:
	/* 0x1429: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_142c:
	/* 0x142c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_142f:
	/* 0x142f: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1434:
	/* 0x1434: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_143c:
	/* 0x143c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1441:
	/* 0x1441: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1446:
	/* 0x1446: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_144b:
	/* 0x144b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_144e:
	/* 0x144e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1450:
	/* 0x1450: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_1458:
	/* 0x1458: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_145a:
	/* 0x145a: je     1eb8 <generic_fexit_event+0x1eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7864ULL;
	}
x86_l_1460:
	/* 0x1460: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1463:
	/* 0x1463: jne    20bf <generic_fexit_event+0x20bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8383ULL;
	}
x86_l_1469:
	/* 0x1469: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_146d:
	/* 0x146d: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1472:
	/* 0x1472: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1478:
	/* 0x1478: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_147d:
	/* 0x147d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1482:
	/* 0x1482: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1487:
	/* 0x1487: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_148a:
	/* 0x148a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148c:
	/* 0x148c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1491:
	/* 0x1491: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1496:
	/* 0x1496: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_149b:
	/* 0x149b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a0:
	/* 0x14a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14a5:
	/* 0x14a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a7:
	/* 0x14a7: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14ac:
	/* 0x14ac: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14b0:
	/* 0x14b0: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14b8:
	/* 0x14b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c2:
	/* 0x14c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c7:
	/* 0x14c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c9:
	/* 0x14c9: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14ce:
	/* 0x14ce: mov    rbp,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14d6:
	/* 0x14d6: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_14dd:
	/* 0x14dd: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_14e3:
	/* 0x14e3: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_14e7:
	/* 0x14e7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_14ea:
	/* 0x14ea: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_14f1:
	/* 0x14f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14f6:
	/* 0x14f6: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_14f9:
	/* 0x14f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fb:
	/* 0x14fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14fd:
	/* 0x14fd: js     21f4 <generic_fexit_event+0x21f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8692ULL;
	}
x86_l_1503:
	/* 0x1503: mov    DWORD PTR [r14+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_150a:
	/* 0x150a: mov    DWORD PTR [r14+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1511:
	/* 0x1511: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1515:
	/* 0x1515: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1518:
	/* 0x1518: jmp    2212 <generic_fexit_event+0x2212> */
	return 8722ULL;
x86_l_151d:
	/* 0x151d: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1522:
	/* 0x1522: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1529:
	/* 0x1529: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1530:
	/* 0x1530: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1535:
	/* 0x1535: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1538:
	/* 0x1538: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_153d:
	/* 0x153d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1542:
	/* 0x1542: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1544:
	/* 0x1544: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_154b:
	/* 0x154b: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_154f:
	/* 0x154f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1554:
	/* 0x1554: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1559:
	/* 0x1559: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_155e:
	/* 0x155e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1560:
	/* 0x1560: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1567:
	/* 0x1567: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_156e:
	/* 0x156e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1573:
	/* 0x1573: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1578:
	/* 0x1578: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_157d:
	/* 0x157d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157f:
	/* 0x157f: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1586:
	/* 0x1586: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_158d:
	/* 0x158d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1592:
	/* 0x1592: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1597:
	/* 0x1597: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_159c:
	/* 0x159c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159e:
	/* 0x159e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_15a7:
	/* 0x15a7: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_15ae:
	/* 0x15ae: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b3:
	/* 0x15b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15b8:
	/* 0x15b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15bd:
	/* 0x15bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c2:
	/* 0x15c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c4:
	/* 0x15c4: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15cb:
	/* 0x15cb: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15d3:
	/* 0x15d3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15d8:
	/* 0x15d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15dd:
	/* 0x15dd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15e2:
	/* 0x15e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e4:
	/* 0x15e4: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_15ed:
	/* 0x15ed: add    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_15f2:
	/* 0x15f2: lea    rdi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_15fa:
	/* 0x15fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15ff:
	/* 0x15ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1604:
	/* 0x1604: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1609:
	/* 0x1609: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5646ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5646ULL: goto x86_l_160e;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5660ULL: goto x86_l_161c;
	case 5666ULL: goto x86_l_1622;
	case 5669ULL: goto x86_l_1625;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5705ULL: goto x86_l_1649;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5725ULL: goto x86_l_165d;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5744ULL: goto x86_l_1670;
	case 5751ULL: goto x86_l_1677;
	case 5759ULL: goto x86_l_167f;
	case 5767ULL: goto x86_l_1687;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5803ULL: goto x86_l_16ab;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5826ULL: goto x86_l_16c2;
	case 5833ULL: goto x86_l_16c9;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5883ULL: goto x86_l_16fb;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5900ULL: goto x86_l_170c;
	case 5903ULL: goto x86_l_170f;
	case 5906ULL: goto x86_l_1712;
	case 5912ULL: goto x86_l_1718;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5935ULL: goto x86_l_172f;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5951ULL: goto x86_l_173f;
	case 5959ULL: goto x86_l_1747;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5979ULL: goto x86_l_175b;
	case 5984ULL: goto x86_l_1760;
	case 5987ULL: goto x86_l_1763;
	case 5989ULL: goto x86_l_1765;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6003ULL: goto x86_l_1773;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6052ULL: goto x86_l_17a4;
	case 6056ULL: goto x86_l_17a8;
	case 6061ULL: goto x86_l_17ad;
	case 6068ULL: goto x86_l_17b4;
	case 6075ULL: goto x86_l_17bb;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6106ULL: goto x86_l_17da;
	case 6112ULL: goto x86_l_17e0;
	case 6120ULL: goto x86_l_17e8;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6176ULL: goto x86_l_1820;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6188ULL: goto x86_l_182c;
	case 6191ULL: goto x86_l_182f;
	case 6194ULL: goto x86_l_1832;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6220ULL: goto x86_l_184c;
	case 6225ULL: goto x86_l_1851;
	case 6233ULL: goto x86_l_1859;
	case 6239ULL: goto x86_l_185f;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6260ULL: goto x86_l_1874;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6279ULL: goto x86_l_1887;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6319ULL: goto x86_l_18af;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6361ULL: goto x86_l_18d9;
	case 6370ULL: goto x86_l_18e2;
	case 6379ULL: goto x86_l_18eb;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6394ULL: goto x86_l_18fa;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6426ULL: goto x86_l_191a;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6447ULL: goto x86_l_192f;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6477ULL: goto x86_l_194d;
	case 6479ULL: goto x86_l_194f;
	case 6487ULL: goto x86_l_1957;
	case 6494ULL: goto x86_l_195e;
	case 6498ULL: goto x86_l_1962;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6512ULL: goto x86_l_1970;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6545ULL: goto x86_l_1991;
	case 6548ULL: goto x86_l_1994;
	case 6555ULL: goto x86_l_199b;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6581ULL: goto x86_l_19b5;
	case 6588ULL: goto x86_l_19bc;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6621ULL: goto x86_l_19dd;
	case 6625ULL: goto x86_l_19e1;
	case 6630ULL: goto x86_l_19e6;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6654ULL: goto x86_l_19fe;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6687ULL: goto x86_l_1a1f;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6720ULL: goto x86_l_1a40;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6786ULL: goto x86_l_1a82;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6867ULL: goto x86_l_1ad3;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6888ULL: goto x86_l_1ae8;
	case 6893ULL: goto x86_l_1aed;
	case 6900ULL: goto x86_l_1af4;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6921ULL: goto x86_l_1b09;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6935ULL: goto x86_l_1b17;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6972ULL: goto x86_l_1b3c;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7024ULL: goto x86_l_1b70;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7060ULL: goto x86_l_1b94;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7082ULL: goto x86_l_1baa;
	case 7084ULL: goto x86_l_1bac;
	case 7089ULL: goto x86_l_1bb1;
	case 7096ULL: goto x86_l_1bb8;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7175ULL: goto x86_l_1c07;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7211ULL: goto x86_l_1c2b;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7247ULL: goto x86_l_1c4f;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7309ULL: goto x86_l_1c8d;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7323ULL: goto x86_l_1c9b;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7356ULL: goto x86_l_1cbc;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7389ULL: goto x86_l_1cdd;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7410ULL: goto x86_l_1cf2;
	case 7415ULL: goto x86_l_1cf7;
	case 7422ULL: goto x86_l_1cfe;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_160e:
	/* 0x160e: movzx  eax,BYTE PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 180ULL);
x86_l_1616:
	/* 0x1616: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1619:
	/* 0x1619: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_161c:
	/* 0x161c: je     1f44 <generic_fexit_event+0x1f44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8004ULL;
	}
x86_l_1622:
	/* 0x1622: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1625:
	/* 0x1625: jne    2c4d <generic_fexit_event+0x2c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11341ULL;
	}
x86_l_162b:
	/* 0x162b: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1630:
	/* 0x1630: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1638:
	/* 0x1638: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_163d:
	/* 0x163d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1642:
	/* 0x1642: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1647:
	/* 0x1647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1649:
	/* 0x1649: movzx  eax,BYTE PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 208ULL);
x86_l_1651:
	/* 0x1651: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1656:
	/* 0x1656: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_165d:
	/* 0x165d: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_1666:
	/* 0x1666: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_166b:
	/* 0x166b: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1670:
	/* 0x1670: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1677:
	/* 0x1677: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_167f:
	/* 0x167f: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1687:
	/* 0x1687: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_168f:
	/* 0x168f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1694:
	/* 0x1694: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1699:
	/* 0x1699: lea    r14,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_16a0:
	/* 0x16a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a5:
	/* 0x16a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a7:
	/* 0x16a7: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16ab:
	/* 0x16ab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16b0:
	/* 0x16b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b5:
	/* 0x16b5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_16b8:
	/* 0x16b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16bd:
	/* 0x16bd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c2:
	/* 0x16c2: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_16c9:
	/* 0x16c9: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_16d1:
	/* 0x16d1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_16d6:
	/* 0x16d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16db:
	/* 0x16db: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_16e0:
	/* 0x16e0: jmp    2ac9 <generic_fexit_event+0x2ac9> */
	return 10953ULL;
x86_l_16e5:
	/* 0x16e5: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_16ea:
	/* 0x16ea: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_16ef:
	/* 0x16ef: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f4:
	/* 0x16f4: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_16fb:
	/* 0x16fb: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1700:
	/* 0x1700: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1705:
	/* 0x1705: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_170a:
	/* 0x170a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170c:
	/* 0x170c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_170f:
	/* 0x170f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1712:
	/* 0x1712: js     1220 <generic_fexit_event+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4640ULL;
	}
x86_l_1718:
	/* 0x1718: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_171c:
	/* 0x171c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1721:
	/* 0x1721: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1723:
	/* 0x1723: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1727:
	/* 0x1727: jmp    1220 <generic_fexit_event+0x1220> */
	return 4640ULL;
x86_l_172c:
	/* 0x172c: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_172f:
	/* 0x172f: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1732:
	/* 0x1732: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1737:
	/* 0x1737: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_173f:
	/* 0x173f: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1747:
	/* 0x1747: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174e:
	/* 0x174e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1753:
	/* 0x1753: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1758:
	/* 0x1758: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_175b:
	/* 0x175b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1760:
	/* 0x1760: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1763:
	/* 0x1763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1765:
	/* 0x1765: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1768:
	/* 0x1768: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_176d:
	/* 0x176d: js     212c <generic_fexit_event+0x212c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8492ULL;
	}
x86_l_1773:
	/* 0x1773: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1777:
	/* 0x1777: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_177a:
	/* 0x177a: je     20d5 <generic_fexit_event+0x20d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8405ULL;
	}
x86_l_1780:
	/* 0x1780: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1783:
	/* 0x1783: jne    2117 <generic_fexit_event+0x2117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8471ULL;
	}
x86_l_1789:
	/* 0x1789: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_178e:
	/* 0x178e: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1793:
	/* 0x1793: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1798:
	/* 0x1798: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_179d:
	/* 0x179d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17a2:
	/* 0x17a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a4:
	/* 0x17a4: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17a8:
	/* 0x17a8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ad:
	/* 0x17ad: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_17b4:
	/* 0x17b4: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_17bb:
	/* 0x17bb: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_17bf:
	/* 0x17bf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17c4:
	/* 0x17c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c9:
	/* 0x17c9: jmp    210d <generic_fexit_event+0x210d> */
	return 8461ULL;
x86_l_17ce:
	/* 0x17ce: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d1:
	/* 0x17d1: cmp    QWORD PTR [rsp+0x90],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290627ULL);
x86_l_17da:
	/* 0x17da: jb     18c7 <generic_fexit_event+0x18c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18c7;
	}
x86_l_17e0:
	/* 0x17e0: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17e8:
	/* 0x17e8: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ec:
	/* 0x17ec: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17f1:
	/* 0x17f1: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_17f7:
	/* 0x17f7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_17fc:
	/* 0x17fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1801:
	/* 0x1801: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1806:
	/* 0x1806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1808:
	/* 0x1808: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_180d:
	/* 0x180d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_180f:
	/* 0x180f: js     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18a6;
	}
x86_l_1815:
	/* 0x1815: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_181a:
	/* 0x181a: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_181d:
	/* 0x181d: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1820:
	/* 0x1820: cmovb  rcx,rax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_1824:
	/* 0x1824: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1829:
	/* 0x1829: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_182c:
	/* 0x182c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_182f:
	/* 0x182f: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1832:
	/* 0x1832: cmovne r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_1836:
	/* 0x1836: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_183b:
	/* 0x183b: cmp    r14,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4094ULL);
x86_l_1842:
	/* 0x1842: ja     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18a6;
	}
x86_l_1844:
	/* 0x1844: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_184c:
	/* 0x184c: add    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1851:
	/* 0x1851: mov    QWORD PTR [rsp+0x88],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1859:
	/* 0x1859: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_185f:
	/* 0x185f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1862:
	/* 0x1862: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1867:
	/* 0x1867: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_186c:
	/* 0x186c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1871:
	/* 0x1871: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1874:
	/* 0x1874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1876:
	/* 0x1876: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_187b:
	/* 0x187b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187d:
	/* 0x187d: js     18a6 <generic_fexit_event+0x18a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18a6;
	}
x86_l_187f:
	/* 0x187f: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1884:
	/* 0x1884: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1887:
	/* 0x1887: add    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_188a:
	/* 0x188a: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1890:
	/* 0x1890: je     2375 <generic_fexit_event+0x2375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9077ULL;
	}
x86_l_1896:
	/* 0x1896: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_189b:
	/* 0x189b: jne    237c <generic_fexit_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_18a1:
	/* 0x18a1: jmp    2387 <generic_fexit_event+0x2387> */
	return 9095ULL;
x86_l_18a6:
	/* 0x18a6: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18ab:
	/* 0x18ab: mov    DWORD PTR [r15+r14*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18af:
	/* 0x18af: add    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18b2:
	/* 0x18b2: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_18b5:
	/* 0x18b5: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_18bd:
	/* 0x18bd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18c2:
	/* 0x18c2: jmp    2d68 <generic_fexit_event+0x2d68> */
	return 11624ULL;
x86_l_18c7:
	/* 0x18c7: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_18ca:
	/* 0x18ca: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18cf:
	/* 0x18cf: jmp    34d <generic_fexit_event+0x34d> */
	return 845ULL;
x86_l_18d4:
	/* 0x18d4: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18d9:
	/* 0x18d9: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_18e2:
	/* 0x18e2: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_18eb:
	/* 0x18eb: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18f0:
	/* 0x18f0: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18f5:
	/* 0x18f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18fa:
	/* 0x18fa: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_18fd:
	/* 0x18fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1902:
	/* 0x1902: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1908:
	/* 0x1908: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_190d:
	/* 0x190d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190f:
	/* 0x190f: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1914:
	/* 0x1914: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_191a:
	/* 0x191a: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1920:
	/* 0x1920: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1923:
	/* 0x1923: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_1927:
	/* 0x1927: mov    QWORD PTR [rsp+0x88],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_192f:
	/* 0x192f: add    r14,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1936:
	/* 0x1936: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193b:
	/* 0x193b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_193e:
	/* 0x193e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1941:
	/* 0x1941: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1944:
	/* 0x1944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1946:
	/* 0x1946: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_194b:
	/* 0x194b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_194d:
	/* 0x194d: js     1968 <generic_fexit_event+0x1968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1968;
	}
x86_l_194f:
	/* 0x194f: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1957:
	/* 0x1957: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_195e:
	/* 0x195e: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1962:
	/* 0x1962: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1965:
	/* 0x1965: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1968:
	/* 0x1968: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1970:
	/* 0x1970: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1976:
	/* 0x1976: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197b:
	/* 0x197b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1980:
	/* 0x1980: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1985:
	/* 0x1985: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_198a:
	/* 0x198a: lea    r13,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1991:
	/* 0x1991: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1994:
	/* 0x1994: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_199b:
	/* 0x199b: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199f:
	/* 0x199f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19a4:
	/* 0x19a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a9:
	/* 0x19a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ae:
	/* 0x19ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b0:
	/* 0x19b0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b5:
	/* 0x19b5: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19bc:
	/* 0x19bc: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19c0:
	/* 0x19c0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19ca:
	/* 0x19ca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19cf:
	/* 0x19cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d1:
	/* 0x19d1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d6:
	/* 0x19d6: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_19dd:
	/* 0x19dd: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19e1:
	/* 0x19e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19e6:
	/* 0x19e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19eb:
	/* 0x19eb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19f0:
	/* 0x19f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f2:
	/* 0x19f2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f7:
	/* 0x19f7: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_19fe:
	/* 0x19fe: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a02:
	/* 0x1a02: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a07:
	/* 0x1a07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a11:
	/* 0x1a11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a13:
	/* 0x1a13: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a18:
	/* 0x1a18: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a1f:
	/* 0x1a1f: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a23:
	/* 0x1a23: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a28:
	/* 0x1a28: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a32:
	/* 0x1a32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a34:
	/* 0x1a34: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a39:
	/* 0x1a39: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a40:
	/* 0x1a40: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a44:
	/* 0x1a44: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a49:
	/* 0x1a49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a4e:
	/* 0x1a4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a53:
	/* 0x1a53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a55:
	/* 0x1a55: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a5a:
	/* 0x1a5a: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1a61:
	/* 0x1a61: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a65:
	/* 0x1a65: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a74:
	/* 0x1a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a76:
	/* 0x1a76: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7b:
	/* 0x1a7b: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1a82:
	/* 0x1a82: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a86:
	/* 0x1a86: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a90:
	/* 0x1a90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a95:
	/* 0x1a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a97:
	/* 0x1a97: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aab:
	/* 0x1aab: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1ab2:
	/* 0x1ab2: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ab6:
	/* 0x1ab6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1abb:
	/* 0x1abb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ac5:
	/* 0x1ac5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac7:
	/* 0x1ac7: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1acc:
	/* 0x1acc: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1ad3:
	/* 0x1ad3: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1adc:
	/* 0x1adc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae6:
	/* 0x1ae6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae8:
	/* 0x1ae8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aed:
	/* 0x1aed: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1af4:
	/* 0x1af4: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1af8:
	/* 0x1af8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1afd:
	/* 0x1afd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b02:
	/* 0x1b02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b07:
	/* 0x1b07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b09:
	/* 0x1b09: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b12:
	/* 0x1b12: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b17:
	/* 0x1b17: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b1a:
	/* 0x1b1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b1f:
	/* 0x1b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b21:
	/* 0x1b21: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1b28:
	/* 0x1b28: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b32:
	/* 0x1b32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b37:
	/* 0x1b37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b3c:
	/* 0x1b3c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b3f:
	/* 0x1b3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b41:
	/* 0x1b41: mov    r13,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b46:
	/* 0x1b46: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b52:
	/* 0x1b52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b57:
	/* 0x1b57: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1b5a:
	/* 0x1b5a: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_1b5d:
	/* 0x1b5d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b62:
	/* 0x1b62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b64:
	/* 0x1b64: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b69:
	/* 0x1b69: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1b70:
	/* 0x1b70: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1b77:
	/* 0x1b77: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b81:
	/* 0x1b81: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b86:
	/* 0x1b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b88:
	/* 0x1b88: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8d:
	/* 0x1b8d: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1b94:
	/* 0x1b94: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1baa:
	/* 0x1baa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bac:
	/* 0x1bac: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb1:
	/* 0x1bb1: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1bb8:
	/* 0x1bb8: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bce:
	/* 0x1bce: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1bd1:
	/* 0x1bd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd3:
	/* 0x1bd3: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd8:
	/* 0x1bd8: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_1bde:
	/* 0x1bde: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_1be3:
	/* 0x1be3: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1bea:
	/* 0x1bea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bef:
	/* 0x1bef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bf9:
	/* 0x1bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfb:
	/* 0x1bfb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c00:
	/* 0x1c00: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c07:
	/* 0x1c07: lea    rdx,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1c0e:
	/* 0x1c0e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c13:
	/* 0x1c13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c18:
	/* 0x1c18: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c1d:
	/* 0x1c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1f:
	/* 0x1c1f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c24:
	/* 0x1c24: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1c2b:
	/* 0x1c2b: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c32:
	/* 0x1c32: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c37:
	/* 0x1c37: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c41:
	/* 0x1c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c43:
	/* 0x1c43: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c48:
	/* 0x1c48: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1c4f:
	/* 0x1c4f: add    rbp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c56:
	/* 0x1c56: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c60:
	/* 0x1c60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c65:
	/* 0x1c65: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1c68:
	/* 0x1c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6a:
	/* 0x1c6a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1c75:
	/* 0x1c75: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_1c7a:
	/* 0x1c7a: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c83:
	/* 0x1c83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c88:
	/* 0x1c88: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c8d:
	/* 0x1c8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8f:
	/* 0x1c8f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c94:
	/* 0x1c94: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c9b:
	/* 0x1c9b: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cae:
	/* 0x1cae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb0:
	/* 0x1cb0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb5:
	/* 0x1cb5: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1cbc:
	/* 0x1cbc: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cca:
	/* 0x1cca: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ccf:
	/* 0x1ccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd1:
	/* 0x1cd1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd6:
	/* 0x1cd6: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1cdd:
	/* 0x1cdd: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cf0:
	/* 0x1cf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf2:
	/* 0x1cf2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf7:
	/* 0x1cf7: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1cfe:
	/* 0x1cfe: add    rbp,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1d02:
	/* 0x1d02: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d07:
	/* 0x1d07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d0c:
	/* 0x1d0c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d11:
	/* 0x1d11: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1d14:
	/* 0x1d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d16:
	/* 0x1d16: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d1b:
	/* 0x1d1b: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1d21:
	/* 0x1d21: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_1d26:
	/* 0x1d26: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d30:
	/* 0x1d30: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d35:
	/* 0x1d35: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1d38:
	/* 0x1d38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3a:
	/* 0x1d3a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3f:
	/* 0x1d3f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
	return 7494ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7494ULL: goto x86_l_1d46;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7599ULL: goto x86_l_1daf;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7619ULL: goto x86_l_1dc3;
	case 7621ULL: goto x86_l_1dc5;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7636ULL: goto x86_l_1dd4;
	case 7640ULL: goto x86_l_1dd8;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7670ULL: goto x86_l_1df6;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7700ULL: goto x86_l_1e14;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7736ULL: goto x86_l_1e38;
	case 7744ULL: goto x86_l_1e40;
	case 7752ULL: goto x86_l_1e48;
	case 7760ULL: goto x86_l_1e50;
	case 7768ULL: goto x86_l_1e58;
	case 7776ULL: goto x86_l_1e60;
	case 7784ULL: goto x86_l_1e68;
	case 7792ULL: goto x86_l_1e70;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7852ULL: goto x86_l_1eac;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7895ULL: goto x86_l_1ed7;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7921ULL: goto x86_l_1ef1;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7936ULL: goto x86_l_1f00;
	case 7943ULL: goto x86_l_1f07;
	case 7949ULL: goto x86_l_1f0d;
	case 7953ULL: goto x86_l_1f11;
	case 7956ULL: goto x86_l_1f14;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7981ULL: goto x86_l_1f2d;
	case 7988ULL: goto x86_l_1f34;
	case 7995ULL: goto x86_l_1f3b;
	case 7999ULL: goto x86_l_1f3f;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8017ULL: goto x86_l_1f51;
	case 8026ULL: goto x86_l_1f5a;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8043ULL: goto x86_l_1f6b;
	case 8047ULL: goto x86_l_1f6f;
	case 8055ULL: goto x86_l_1f77;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8073ULL: goto x86_l_1f89;
	case 8077ULL: goto x86_l_1f8d;
	case 8081ULL: goto x86_l_1f91;
	case 8084ULL: goto x86_l_1f94;
	case 8088ULL: goto x86_l_1f98;
	case 8096ULL: goto x86_l_1fa0;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8137ULL: goto x86_l_1fc9;
	case 8143ULL: goto x86_l_1fcf;
	case 8145ULL: goto x86_l_1fd1;
	case 8151ULL: goto x86_l_1fd7;
	case 8154ULL: goto x86_l_1fda;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8169ULL: goto x86_l_1fe9;
	case 8176ULL: goto x86_l_1ff0;
	case 8180ULL: goto x86_l_1ff4;
	case 8185ULL: goto x86_l_1ff9;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8244ULL: goto x86_l_2034;
	case 8249ULL: goto x86_l_2039;
	case 8253ULL: goto x86_l_203d;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8276ULL: goto x86_l_2054;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8311ULL: goto x86_l_2077;
	case 8321ULL: goto x86_l_2081;
	case 8326ULL: goto x86_l_2086;
	case 8331ULL: goto x86_l_208b;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8353ULL: goto x86_l_20a1;
	case 8359ULL: goto x86_l_20a7;
	case 8361ULL: goto x86_l_20a9;
	case 8364ULL: goto x86_l_20ac;
	case 8368ULL: goto x86_l_20b0;
	case 8372ULL: goto x86_l_20b4;
	case 8375ULL: goto x86_l_20b7;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8447ULL: goto x86_l_20ff;
	case 8451ULL: goto x86_l_2103;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8466ULL: goto x86_l_2112;
	case 8469ULL: goto x86_l_2115;
	case 8471ULL: goto x86_l_2117;
	case 8476ULL: goto x86_l_211c;
	case 8483ULL: goto x86_l_2123;
	case 8492ULL: goto x86_l_212c;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8551ULL: goto x86_l_2167;
	case 8557ULL: goto x86_l_216d;
	case 8561ULL: goto x86_l_2171;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8657ULL: goto x86_l_21d1;
	case 8659ULL: goto x86_l_21d3;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8703ULL: goto x86_l_21ff;
	case 8705ULL: goto x86_l_2201;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8762ULL: goto x86_l_223a;
	case 8764ULL: goto x86_l_223c;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8784ULL: goto x86_l_2250;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8843ULL: goto x86_l_228b;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8919ULL: goto x86_l_22d7;
	case 8922ULL: goto x86_l_22da;
	case 8924ULL: goto x86_l_22dc;
	case 8932ULL: goto x86_l_22e4;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8987ULL: goto x86_l_231b;
	case 8989ULL: goto x86_l_231d;
	case 8997ULL: goto x86_l_2325;
	case 9000ULL: goto x86_l_2328;
	case 9004ULL: goto x86_l_232c;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9022ULL: goto x86_l_233e;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9033ULL: goto x86_l_2349;
	case 9038ULL: goto x86_l_234e;
	case 9044ULL: goto x86_l_2354;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9093ULL: goto x86_l_2385;
	case 9095ULL: goto x86_l_2387;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9116ULL: goto x86_l_239c;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9155ULL: goto x86_l_23c3;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9181ULL: goto x86_l_23dd;
	case 9184ULL: goto x86_l_23e0;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9200ULL: goto x86_l_23f0;
	case 9206ULL: goto x86_l_23f6;
	case 9209ULL: goto x86_l_23f9;
	case 9212ULL: goto x86_l_23fc;
	case 9220ULL: goto x86_l_2404;
	case 9223ULL: goto x86_l_2407;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9252ULL: goto x86_l_2424;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1d46:
	/* 0x1d46: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d54:
	/* 0x1d54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d59:
	/* 0x1d59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5b:
	/* 0x1d5b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d60:
	/* 0x1d60: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1d67:
	/* 0x1d67: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d70:
	/* 0x1d70: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1d7d:
	/* 0x1d7d: jmp    1e1e <generic_fexit_event+0x1e1e> */
	goto x86_l_1e1e;
x86_l_1d82:
	/* 0x1d82: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d86:
	/* 0x1d86: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d90:
	/* 0x1d90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d95:
	/* 0x1d95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d9a:
	/* 0x1d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9c:
	/* 0x1d9c: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1da0:
	/* 0x1da0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da5:
	/* 0x1da5: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1dab:
	/* 0x1dab: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1daf:
	/* 0x1daf: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1db4:
	/* 0x1db4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1db9:
	/* 0x1db9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc3:
	/* 0x1dc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc5:
	/* 0x1dc5: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dce:
	/* 0x1dce: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1dd4:
	/* 0x1dd4: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1dd8:
	/* 0x1dd8: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1de2:
	/* 0x1de2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1de7:
	/* 0x1de7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dec:
	/* 0x1dec: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1def:
	/* 0x1def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df1:
	/* 0x1df1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df6:
	/* 0x1df6: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1e02:
	/* 0x1e02: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e07:
	/* 0x1e07: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e0a:
	/* 0x1e0a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e0f:
	/* 0x1e0f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e14:
	/* 0x1e14: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1e19:
	/* 0x1e19: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e1e:
	/* 0x1e1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e20:
	/* 0x1e20: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e25:
	/* 0x1e25: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1e2b:
	/* 0x1e2b: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_1e30:
	/* 0x1e30: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e38:
	/* 0x1e38: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1e40:
	/* 0x1e40: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1e48:
	/* 0x1e48: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1e50:
	/* 0x1e50: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e58:
	/* 0x1e58: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e60:
	/* 0x1e60: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1e68:
	/* 0x1e68: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e70:
	/* 0x1e70: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e78:
	/* 0x1e78: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1e7b:
	/* 0x1e7b: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e82:
	/* 0x1e82: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e87:
	/* 0x1e87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e91:
	/* 0x1e91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e96:
	/* 0x1e96: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e99:
	/* 0x1e99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9b:
	/* 0x1e9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e9e:
	/* 0x1e9e: je     213d <generic_fexit_event+0x213d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_213d;
	}
x86_l_1ea4:
	/* 0x1ea4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ea7:
	/* 0x1ea7: jmp    1220 <generic_fexit_event+0x1220> */
	return 4640ULL;
x86_l_1eac:
	/* 0x1eac: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1eb3:
	/* 0x1eb3: jmp    2212 <generic_fexit_event+0x2212> */
	goto x86_l_2212;
x86_l_1eb8:
	/* 0x1eb8: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ebd:
	/* 0x1ebd: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec7:
	/* 0x1ec7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ed1:
	/* 0x1ed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed3:
	/* 0x1ed3: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1ed7:
	/* 0x1ed7: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1edf:
	/* 0x1edf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ee4:
	/* 0x1ee4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eee:
	/* 0x1eee: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ef1:
	/* 0x1ef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef3:
	/* 0x1ef3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f00:
	/* 0x1f00: cmp    r12,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4095ULL);
x86_l_1f07:
	/* 0x1f07: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_1f0d:
	/* 0x1f0d: cmovb  r13,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_64, X86_CC_B);
x86_l_1f11:
	/* 0x1f11: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1f14:
	/* 0x1f14: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f20:
	/* 0x1f20: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1f23:
	/* 0x1f23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f25:
	/* 0x1f25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f27:
	/* 0x1f27: js     2201 <generic_fexit_event+0x2201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2201;
	}
x86_l_1f2d:
	/* 0x1f2d: mov    DWORD PTR [r14+0x9c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1f34:
	/* 0x1f34: mov    DWORD PTR [r14+0xa0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1f3b:
	/* 0x1f3b: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f3f:
	/* 0x1f3f: jmp    2212 <generic_fexit_event+0x2212> */
	goto x86_l_2212;
x86_l_1f44:
	/* 0x1f44: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f49:
	/* 0x1f49: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1f51:
	/* 0x1f51: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1f61:
	/* 0x1f61: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f66:
	/* 0x1f66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f6b:
	/* 0x1f6b: lea    rcx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1f77:
	/* 0x1f77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f79:
	/* 0x1f79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: je     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10854ULL;
	}
x86_l_1f82:
	/* 0x1f82: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1f85:
	/* 0x1f85: mov    WORD PTR [rax],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f89:
	/* 0x1f89: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1f8d:
	/* 0x1f8d: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1f91:
	/* 0x1f91: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f94:
	/* 0x1f94: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1f98:
	/* 0x1f98: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1fa0:
	/* 0x1fa0: lea    rdx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fae:
	/* 0x1fae: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_1fb1:
	/* 0x1fb1: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1fb6:
	/* 0x1fb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb8:
	/* 0x1fb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10854ULL;
	}
x86_l_1fc1:
	/* 0x1fc1: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1fc6:
	/* 0x1fc6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1fc9:
	/* 0x1fc9: jg     233b <generic_fexit_event+0x233b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_233b;
	}
x86_l_1fcf:
	/* 0x1fcf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd1:
	/* 0x1fd1: je     2364 <generic_fexit_event+0x2364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2364;
	}
x86_l_1fd7:
	/* 0x1fd7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1fda:
	/* 0x1fda: je     2364 <generic_fexit_event+0x2364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2364;
	}
x86_l_1fe0:
	/* 0x1fe0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1fe3:
	/* 0x1fe3: jne    2515 <generic_fexit_event+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9493ULL;
	}
x86_l_1fe9:
	/* 0x1fe9: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1ff0:
	/* 0x1ff0: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1ff4:
	/* 0x1ff4: jmp    2463 <generic_fexit_event+0x2463> */
	return 9315ULL;
x86_l_1ff9:
	/* 0x1ff9: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2003:
	/* 0x2003: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2008:
	/* 0x2008: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_200d:
	/* 0x200d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200f:
	/* 0x200f: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2014:
	/* 0x2014: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2019:
	/* 0x2019: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201e:
	/* 0x201e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2021:
	/* 0x2021: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2026:
	/* 0x2026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2028:
	/* 0x2028: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_202d:
	/* 0x202d: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2034:
	/* 0x2034: lea    r14,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2039:
	/* 0x2039: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_203d:
	/* 0x203d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2042:
	/* 0x2042: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2047:
	/* 0x2047: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_204c:
	/* 0x204c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_204f:
	/* 0x204f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2051:
	/* 0x2051: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2054:
	/* 0x2054: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_205b:
	/* 0x205b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2060:
	/* 0x2060: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2065:
	/* 0x2065: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_206a:
	/* 0x206a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_206d:
	/* 0x206d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206f:
	/* 0x206f: movzx  eax,WORD PTR [r13+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2077:
	/* 0x2077: movbe  WORD PTR [r13+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2081:
	/* 0x2081: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2086:
	/* 0x2086: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_208b:
	/* 0x208b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2092:
	/* 0x2092: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2097:
	/* 0x2097: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_209c:
	/* 0x209c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209e:
	/* 0x209e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20a1:
	/* 0x20a1: je     2c4d <generic_fexit_event+0x2c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11341ULL;
	}
x86_l_20a7:
	/* 0x20a7: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a9:
	/* 0x20a9: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ac:
	/* 0x20ac: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b0:
	/* 0x20b0: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b4:
	/* 0x20b4: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20b7:
	/* 0x20b7: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20ba:
	/* 0x20ba: jmp    2c4d <generic_fexit_event+0x2c4d> */
	return 11341ULL;
x86_l_20bf:
	/* 0x20bf: mov    QWORD PTR [r14+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_20ca:
	/* 0x20ca: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_20d0:
	/* 0x20d0: jmp    2212 <generic_fexit_event+0x2212> */
	goto x86_l_2212;
x86_l_20d5:
	/* 0x20d5: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_20dc:
	/* 0x20dc: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e1:
	/* 0x20e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20e6:
	/* 0x20e6: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_20e9:
	/* 0x20e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20ee:
	/* 0x20ee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20f3:
	/* 0x20f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f5:
	/* 0x20f5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_20f8:
	/* 0x20f8: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_20ff:
	/* 0x20ff: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2103:
	/* 0x2103: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2108:
	/* 0x2108: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_210d:
	/* 0x210d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2112:
	/* 0x2112: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2115:
	/* 0x2115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2117:
	/* 0x2117: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_211c:
	/* 0x211c: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_2123:
	/* 0x2123: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_212c:
	/* 0x212c: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_2132:
	/* 0x2132: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2135:
	/* 0x2135: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_2138:
	/* 0x2138: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_213d:
	/* 0x213d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2142:
	/* 0x2142: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2149:
	/* 0x2149: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_214e:
	/* 0x214e: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_2153:
	/* 0x2153: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2158:
	/* 0x2158: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_215d:
	/* 0x215d: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_2162:
	/* 0x2162: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2164:
	/* 0x2164: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2167:
	/* 0x2167: js     1ea4 <generic_fexit_event+0x1ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ea4;
	}
x86_l_216d:
	/* 0x216d: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2171:
	/* 0x2171: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2176:
	/* 0x2176: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_217b:
	/* 0x217b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2180:
	/* 0x2180: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2185:
	/* 0x2185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2187:
	/* 0x2187: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_218c:
	/* 0x218c: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_2193:
	/* 0x2193: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_2198:
	/* 0x2198: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_219d:
	/* 0x219d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21a0:
	/* 0x21a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a5:
	/* 0x21a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21aa:
	/* 0x21aa: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_21af:
	/* 0x21af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21b4:
	/* 0x21b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b6:
	/* 0x21b6: add    rbp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_21ba:
	/* 0x21ba: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21bf:
	/* 0x21bf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_21c4:
	/* 0x21c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21c9:
	/* 0x21c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21ce:
	/* 0x21ce: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_21d1:
	/* 0x21d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d3:
	/* 0x21d3: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_21d9:
	/* 0x21d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21dc:
	/* 0x21dc: jne    1220 <generic_fexit_event+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4640ULL;
	}
x86_l_21e2:
	/* 0x21e2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e4:
	/* 0x21e4: cmp    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_21e9:
	/* 0x21e9: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_21ec:
	/* 0x21ec: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21ef:
	/* 0x21ef: jmp    1220 <generic_fexit_event+0x1220> */
	return 4640ULL;
x86_l_21f4:
	/* 0x21f4: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_21ff:
	/* 0x21ff: jmp    2212 <generic_fexit_event+0x2212> */
	goto x86_l_2212;
x86_l_2201:
	/* 0x2201: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_220c:
	/* 0x220c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2212:
	/* 0x2212: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2217:
	/* 0x2217: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_221a:
	/* 0x221a: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_221f:
	/* 0x221f: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_2224:
	/* 0x2224: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_2228:
	/* 0x2228: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_222d:
	/* 0x222d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2232:
	/* 0x2232: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_2237:
	/* 0x2237: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_223a:
	/* 0x223a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223c:
	/* 0x223c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_223f:
	/* 0x223f: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2241:
	/* 0x2241: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2243:
	/* 0x2243: js     2250 <generic_fexit_event+0x2250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2250;
	}
x86_l_2245:
	/* 0x2245: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224a:
	/* 0x224a: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_2250:
	/* 0x2250: mov    r13d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 112ULL);
x86_l_2256:
	/* 0x2256: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_225b:
	/* 0x225b: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_225e:
	/* 0x225e: jmp    2c5d <generic_fexit_event+0x2c5d> */
	return 11357ULL;
x86_l_2263:
	/* 0x2263: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2268:
	/* 0x2268: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_226d:
	/* 0x226d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2272:
	/* 0x2272: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2275:
	/* 0x2275: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_227a:
	/* 0x227a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227c:
	/* 0x227c: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2281:
	/* 0x2281: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2286:
	/* 0x2286: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_228b:
	/* 0x228b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_228e:
	/* 0x228e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2293:
	/* 0x2293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2295:
	/* 0x2295: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229a:
	/* 0x229a: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_22a1:
	/* 0x22a1: lea    r14,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22a6:
	/* 0x22a6: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_22aa:
	/* 0x22aa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22af:
	/* 0x22af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b4:
	/* 0x22b4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22b9:
	/* 0x22b9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22be:
	/* 0x22be: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_22c1:
	/* 0x22c1: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_22c8:
	/* 0x22c8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22cd:
	/* 0x22cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22d2:
	/* 0x22d2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22d7:
	/* 0x22d7: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_22da:
	/* 0x22da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22dc:
	/* 0x22dc: movzx  eax,WORD PTR [r13+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_22e4:
	/* 0x22e4: movbe  WORD PTR [r13+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_22ee:
	/* 0x22ee: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f3:
	/* 0x22f3: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_22fa:
	/* 0x22fa: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22ff:
	/* 0x22ff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2306:
	/* 0x2306: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_230b:
	/* 0x230b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2310:
	/* 0x2310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2312:
	/* 0x2312: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2315:
	/* 0x2315: je     2c4d <generic_fexit_event+0x2c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11341ULL;
	}
x86_l_231b:
	/* 0x231b: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231d:
	/* 0x231d: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2325:
	/* 0x2325: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2328:
	/* 0x2328: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232c:
	/* 0x232c: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2330:
	/* 0x2330: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2333:
	/* 0x2333: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2336:
	/* 0x2336: jmp    2c4d <generic_fexit_event+0x2c4d> */
	return 11341ULL;
x86_l_233b:
	/* 0x233b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_233e:
	/* 0x233e: je     2452 <generic_fexit_event+0x2452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2344:
	/* 0x2344: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2347:
	/* 0x2347: je     2364 <generic_fexit_event+0x2364> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2364;
	}
x86_l_2349:
	/* 0x2349: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_234e:
	/* 0x234e: jne    2515 <generic_fexit_event+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9493ULL;
	}
x86_l_2354:
	/* 0x2354: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_235b:
	/* 0x235b: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_235f:
	/* 0x235f: jmp    2463 <generic_fexit_event+0x2463> */
	return 9315ULL;
x86_l_2364:
	/* 0x2364: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2369:
	/* 0x2369: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2370:
	/* 0x2370: jmp    245e <generic_fexit_event+0x245e> */
	return 9310ULL;
x86_l_2375:
	/* 0x2375: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2377:
	/* 0x2377: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_237c:
	/* 0x237c: cmp    QWORD PTR [rsp+0x90],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290627ULL);
x86_l_2385:
	/* 0x2385: jne    2394 <generic_fexit_event+0x2394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2394;
	}
x86_l_2387:
	/* 0x2387: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_238a:
	/* 0x238a: mov    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_238f:
	/* 0x238f: jmp    18ca <generic_fexit_event+0x18ca> */
	return 6346ULL;
x86_l_2394:
	/* 0x2394: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_239c:
	/* 0x239c: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23a0:
	/* 0x23a0: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23a5:
	/* 0x23a5: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_23ab:
	/* 0x23ab: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23b0:
	/* 0x23b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b5:
	/* 0x23b5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23ba:
	/* 0x23ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bc:
	/* 0x23bc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23c1:
	/* 0x23c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c3:
	/* 0x23c3: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12685ULL;
	}
x86_l_23c9:
	/* 0x23c9: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23ce:
	/* 0x23ce: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d3:
	/* 0x23d3: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_23d6:
	/* 0x23d6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_23dd:
	/* 0x23dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23e0:
	/* 0x23e0: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_23e4:
	/* 0x23e4: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_23e9:
	/* 0x23e9: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_23f0:
	/* 0x23f0: ja     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12685ULL;
	}
x86_l_23f6:
	/* 0x23f6: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_23f9:
	/* 0x23f9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_23fc:
	/* 0x23fc: add    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_2404:
	/* 0x2404: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_2407:
	/* 0x2407: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_240d:
	/* 0x240d: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2412:
	/* 0x2412: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2417:
	/* 0x2417: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_241c:
	/* 0x241c: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_241f:
	/* 0x241f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2424:
	/* 0x2424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2426:
	/* 0x2426: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_242b:
	/* 0x242b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242d:
	/* 0x242d: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12685ULL;
	}
x86_l_2433:
	/* 0x2433: add    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2436:
	/* 0x2436: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_243c:
	/* 0x243c: je     2792 <generic_fexit_event+0x2792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10130ULL;
	}
x86_l_2442:
	/* 0x2442: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_2447:
	/* 0x2447: jne    2799 <generic_fexit_event+0x2799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10137ULL;
	}
x86_l_244d:
	/* 0x244d: jmp    2387 <generic_fexit_event+0x2387> */
	goto x86_l_2387;
x86_l_2452:
	/* 0x2452: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2457:
	/* 0x2457: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
	return 9310ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9334ULL: goto x86_l_2476;
	case 9340ULL: goto x86_l_247c;
	case 9350ULL: goto x86_l_2486;
	case 9354ULL: goto x86_l_248a;
	case 9360ULL: goto x86_l_2490;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9398ULL: goto x86_l_24b6;
	case 9401ULL: goto x86_l_24b9;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9424ULL: goto x86_l_24d0;
	case 9426ULL: goto x86_l_24d2;
	case 9429ULL: goto x86_l_24d5;
	case 9431ULL: goto x86_l_24d7;
	case 9438ULL: goto x86_l_24de;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9461ULL: goto x86_l_24f5;
	case 9468ULL: goto x86_l_24fc;
	case 9472ULL: goto x86_l_2500;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9486ULL: goto x86_l_250e;
	case 9491ULL: goto x86_l_2513;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9508ULL: goto x86_l_2524;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9532ULL: goto x86_l_253c;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9552ULL: goto x86_l_2550;
	case 9562ULL: goto x86_l_255a;
	case 9566ULL: goto x86_l_255e;
	case 9572ULL: goto x86_l_2564;
	case 9576ULL: goto x86_l_2568;
	case 9579ULL: goto x86_l_256b;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9631ULL: goto x86_l_259f;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9641ULL: goto x86_l_25a9;
	case 9643ULL: goto x86_l_25ab;
	case 9650ULL: goto x86_l_25b2;
	case 9654ULL: goto x86_l_25b6;
	case 9656ULL: goto x86_l_25b8;
	case 9659ULL: goto x86_l_25bb;
	case 9661ULL: goto x86_l_25bd;
	case 9664ULL: goto x86_l_25c0;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9680ULL: goto x86_l_25d0;
	case 9684ULL: goto x86_l_25d4;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9748ULL: goto x86_l_2614;
	case 9754ULL: goto x86_l_261a;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9774ULL: goto x86_l_262e;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9829ULL: goto x86_l_2665;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9835ULL: goto x86_l_266b;
	case 9838ULL: goto x86_l_266e;
	case 9840ULL: goto x86_l_2670;
	case 9843ULL: goto x86_l_2673;
	case 9845ULL: goto x86_l_2675;
	case 9852ULL: goto x86_l_267c;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9882ULL: goto x86_l_269a;
	case 9886ULL: goto x86_l_269e;
	case 9888ULL: goto x86_l_26a0;
	case 9893ULL: goto x86_l_26a5;
	case 9900ULL: goto x86_l_26ac;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9912ULL: goto x86_l_26b8;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9926ULL: goto x86_l_26c6;
	case 9931ULL: goto x86_l_26cb;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9950ULL: goto x86_l_26de;
	case 9956ULL: goto x86_l_26e4;
	case 9966ULL: goto x86_l_26ee;
	case 9970ULL: goto x86_l_26f2;
	case 9976ULL: goto x86_l_26f8;
	case 9980ULL: goto x86_l_26fc;
	case 9983ULL: goto x86_l_26ff;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10007ULL: goto x86_l_2717;
	case 10012ULL: goto x86_l_271c;
	case 10014ULL: goto x86_l_271e;
	case 10017ULL: goto x86_l_2721;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10035ULL: goto x86_l_2733;
	case 10037ULL: goto x86_l_2735;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10045ULL: goto x86_l_273d;
	case 10051ULL: goto x86_l_2743;
	case 10058ULL: goto x86_l_274a;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10070ULL: goto x86_l_2756;
	case 10076ULL: goto x86_l_275c;
	case 10079ULL: goto x86_l_275f;
	case 10081ULL: goto x86_l_2761;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10099ULL: goto x86_l_2773;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10113ULL: goto x86_l_2781;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10137ULL: goto x86_l_2799;
	case 10146ULL: goto x86_l_27a2;
	case 10152ULL: goto x86_l_27a8;
	case 10160ULL: goto x86_l_27b0;
	case 10164ULL: goto x86_l_27b4;
	case 10169ULL: goto x86_l_27b9;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10199ULL: goto x86_l_27d7;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10225ULL: goto x86_l_27f1;
	case 10228ULL: goto x86_l_27f4;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10249ULL: goto x86_l_2809;
	case 10255ULL: goto x86_l_280f;
	case 10258ULL: goto x86_l_2812;
	case 10261ULL: goto x86_l_2815;
	case 10264ULL: goto x86_l_2818;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10304ULL: goto x86_l_2840;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10321ULL: goto x86_l_2851;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10348ULL: goto x86_l_286c;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10386ULL: goto x86_l_2892;
	case 10392ULL: goto x86_l_2898;
	case 10402ULL: goto x86_l_28a2;
	case 10406ULL: goto x86_l_28a6;
	case 10412ULL: goto x86_l_28ac;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10450ULL: goto x86_l_28d2;
	case 10453ULL: goto x86_l_28d5;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10467ULL: goto x86_l_28e3;
	case 10469ULL: goto x86_l_28e5;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10478ULL: goto x86_l_28ee;
	case 10481ULL: goto x86_l_28f1;
	case 10483ULL: goto x86_l_28f3;
	case 10490ULL: goto x86_l_28fa;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10499ULL: goto x86_l_2903;
	case 10501ULL: goto x86_l_2905;
	case 10504ULL: goto x86_l_2908;
	case 10506ULL: goto x86_l_290a;
	case 10511ULL: goto x86_l_290f;
	case 10513ULL: goto x86_l_2911;
	case 10520ULL: goto x86_l_2918;
	case 10524ULL: goto x86_l_291c;
	case 10526ULL: goto x86_l_291e;
	case 10531ULL: goto x86_l_2923;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10545ULL: goto x86_l_2931;
	case 10550ULL: goto x86_l_2936;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10604ULL: goto x86_l_296c;
	case 10608ULL: goto x86_l_2970;
	case 10614ULL: goto x86_l_2976;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10637ULL: goto x86_l_298d;
	case 10642ULL: goto x86_l_2992;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10652ULL: goto x86_l_299c;
	case 10655ULL: goto x86_l_299f;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10669ULL: goto x86_l_29ad;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10678ULL: goto x86_l_29b6;
	case 10680ULL: goto x86_l_29b8;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10692ULL: goto x86_l_29c4;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10701ULL: goto x86_l_29cd;
	case 10703ULL: goto x86_l_29cf;
	case 10706ULL: goto x86_l_29d2;
	case 10708ULL: goto x86_l_29d4;
	case 10713ULL: goto x86_l_29d9;
	case 10715ULL: goto x86_l_29db;
	case 10722ULL: goto x86_l_29e2;
	case 10726ULL: goto x86_l_29e6;
	case 10728ULL: goto x86_l_29e8;
	case 10733ULL: goto x86_l_29ed;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10747ULL: goto x86_l_29fb;
	case 10752ULL: goto x86_l_2a00;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10781ULL: goto x86_l_2a1d;
	case 10786ULL: goto x86_l_2a22;
	case 10790ULL: goto x86_l_2a26;
	case 10796ULL: goto x86_l_2a2c;
	case 10806ULL: goto x86_l_2a36;
	case 10810ULL: goto x86_l_2a3a;
	case 10816ULL: goto x86_l_2a40;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10844ULL: goto x86_l_2a5c;
	case 10847ULL: goto x86_l_2a5f;
	case 10852ULL: goto x86_l_2a64;
	case 10854ULL: goto x86_l_2a66;
	case 10856ULL: goto x86_l_2a68;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10879ULL: goto x86_l_2a7f;
	case 10889ULL: goto x86_l_2a89;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10931ULL: goto x86_l_2ab3;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_245e:
	/* 0x245e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2463:
	/* 0x2463: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2468:
	/* 0x2468: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246d:
	/* 0x246d: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2472:
	/* 0x2472: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2476:
	/* 0x2476: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_247c:
	/* 0x247c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2486:
	/* 0x2486: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_248a:
	/* 0x248a: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_2490:
	/* 0x2490: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2494:
	/* 0x2494: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2497:
	/* 0x2497: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_249a:
	/* 0x249a: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_249f:
	/* 0x249f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24a4:
	/* 0x24a4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_24a7:
	/* 0x24a7: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24ac:
	/* 0x24ac: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24af:
	/* 0x24af: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24b4:
	/* 0x24b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b6:
	/* 0x24b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24b9:
	/* 0x24b9: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_24bf:
	/* 0x24bf: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_24c4:
	/* 0x24c4: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_24c7:
	/* 0x24c7: jg     24e4 <generic_fexit_event+0x24e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_24e4;
	}
x86_l_24c9:
	/* 0x24c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24cb:
	/* 0x24cb: je     2502 <generic_fexit_event+0x2502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2502;
	}
x86_l_24cd:
	/* 0x24cd: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_24d0:
	/* 0x24d0: je     2502 <generic_fexit_event+0x2502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2502;
	}
x86_l_24d2:
	/* 0x24d2: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_24d5:
	/* 0x24d5: jne    2532 <generic_fexit_event+0x2532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2532;
	}
x86_l_24d7:
	/* 0x24d7: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_24de:
	/* 0x24de: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_24e2:
	/* 0x24e2: jmp    2537 <generic_fexit_event+0x2537> */
	goto x86_l_2537;
x86_l_24e4:
	/* 0x24e4: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_24e7:
	/* 0x24e7: je     251f <generic_fexit_event+0x251f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251f;
	}
x86_l_24e9:
	/* 0x24e9: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_24ec:
	/* 0x24ec: je     2502 <generic_fexit_event+0x2502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2502;
	}
x86_l_24ee:
	/* 0x24ee: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_24f3:
	/* 0x24f3: jne    2532 <generic_fexit_event+0x2532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2532;
	}
x86_l_24f5:
	/* 0x24f5: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_24fc:
	/* 0x24fc: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2500:
	/* 0x2500: jmp    2537 <generic_fexit_event+0x2537> */
	goto x86_l_2537;
x86_l_2502:
	/* 0x2502: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2507:
	/* 0x2507: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_250e:
	/* 0x250e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2513:
	/* 0x2513: jmp    2537 <generic_fexit_event+0x2537> */
	goto x86_l_2537;
x86_l_2515:
	/* 0x2515: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_251a:
	/* 0x251a: jmp    2463 <generic_fexit_event+0x2463> */
	goto x86_l_2463;
x86_l_251f:
	/* 0x251f: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2524:
	/* 0x2524: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_252b:
	/* 0x252b: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2530:
	/* 0x2530: jmp    2537 <generic_fexit_event+0x2537> */
	goto x86_l_2537;
x86_l_2532:
	/* 0x2532: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2537:
	/* 0x2537: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_253c:
	/* 0x253c: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2541:
	/* 0x2541: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2546:
	/* 0x2546: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_254a:
	/* 0x254a: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_2550:
	/* 0x2550: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_255a:
	/* 0x255a: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_255e:
	/* 0x255e: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_2564:
	/* 0x2564: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2568:
	/* 0x2568: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_256b:
	/* 0x256b: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_256e:
	/* 0x256e: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2573:
	/* 0x2573: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2578:
	/* 0x2578: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_257b:
	/* 0x257b: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2580:
	/* 0x2580: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2583:
	/* 0x2583: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2588:
	/* 0x2588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258a:
	/* 0x258a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_258d:
	/* 0x258d: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_2593:
	/* 0x2593: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2598:
	/* 0x2598: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_259b:
	/* 0x259b: jg     25b8 <generic_fexit_event+0x25b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_25b8;
	}
x86_l_259d:
	/* 0x259d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_259f:
	/* 0x259f: je     25d6 <generic_fexit_event+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d6;
	}
x86_l_25a1:
	/* 0x25a1: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_25a4:
	/* 0x25a4: je     25d6 <generic_fexit_event+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d6;
	}
x86_l_25a6:
	/* 0x25a6: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_25a9:
	/* 0x25a9: jne    25fc <generic_fexit_event+0x25fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25fc;
	}
x86_l_25ab:
	/* 0x25ab: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_25b2:
	/* 0x25b2: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_25b6:
	/* 0x25b6: jmp    2601 <generic_fexit_event+0x2601> */
	goto x86_l_2601;
x86_l_25b8:
	/* 0x25b8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_25bb:
	/* 0x25bb: je     25e9 <generic_fexit_event+0x25e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e9;
	}
x86_l_25bd:
	/* 0x25bd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_25c0:
	/* 0x25c0: je     25d6 <generic_fexit_event+0x25d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25d6;
	}
x86_l_25c2:
	/* 0x25c2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_25c7:
	/* 0x25c7: jne    25fc <generic_fexit_event+0x25fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25fc;
	}
x86_l_25c9:
	/* 0x25c9: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_25d0:
	/* 0x25d0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_25d4:
	/* 0x25d4: jmp    2601 <generic_fexit_event+0x2601> */
	goto x86_l_2601;
x86_l_25d6:
	/* 0x25d6: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25db:
	/* 0x25db: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_25e2:
	/* 0x25e2: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25e7:
	/* 0x25e7: jmp    2601 <generic_fexit_event+0x2601> */
	goto x86_l_2601;
x86_l_25e9:
	/* 0x25e9: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25ee:
	/* 0x25ee: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25f5:
	/* 0x25f5: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25fa:
	/* 0x25fa: jmp    2601 <generic_fexit_event+0x2601> */
	goto x86_l_2601;
x86_l_25fc:
	/* 0x25fc: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2601:
	/* 0x2601: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2606:
	/* 0x2606: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_260b:
	/* 0x260b: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2610:
	/* 0x2610: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2614:
	/* 0x2614: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_261a:
	/* 0x261a: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2624:
	/* 0x2624: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2628:
	/* 0x2628: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_262e:
	/* 0x262e: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2632:
	/* 0x2632: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2635:
	/* 0x2635: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2638:
	/* 0x2638: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_263d:
	/* 0x263d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2642:
	/* 0x2642: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2645:
	/* 0x2645: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_264a:
	/* 0x264a: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_264d:
	/* 0x264d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2652:
	/* 0x2652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2654:
	/* 0x2654: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2657:
	/* 0x2657: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_265d:
	/* 0x265d: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2662:
	/* 0x2662: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2665:
	/* 0x2665: jg     2682 <generic_fexit_event+0x2682> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2682;
	}
x86_l_2667:
	/* 0x2667: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2669:
	/* 0x2669: je     26a0 <generic_fexit_event+0x26a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a0;
	}
x86_l_266b:
	/* 0x266b: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_266e:
	/* 0x266e: je     26a0 <generic_fexit_event+0x26a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a0;
	}
x86_l_2670:
	/* 0x2670: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2673:
	/* 0x2673: jne    26c6 <generic_fexit_event+0x26c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c6;
	}
x86_l_2675:
	/* 0x2675: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_267c:
	/* 0x267c: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2680:
	/* 0x2680: jmp    26cb <generic_fexit_event+0x26cb> */
	goto x86_l_26cb;
x86_l_2682:
	/* 0x2682: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2685:
	/* 0x2685: je     26b3 <generic_fexit_event+0x26b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b3;
	}
x86_l_2687:
	/* 0x2687: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_268a:
	/* 0x268a: je     26a0 <generic_fexit_event+0x26a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a0;
	}
x86_l_268c:
	/* 0x268c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2691:
	/* 0x2691: jne    26c6 <generic_fexit_event+0x26c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26c6;
	}
x86_l_2693:
	/* 0x2693: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_269a:
	/* 0x269a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_269e:
	/* 0x269e: jmp    26cb <generic_fexit_event+0x26cb> */
	goto x86_l_26cb;
x86_l_26a0:
	/* 0x26a0: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26a5:
	/* 0x26a5: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_26ac:
	/* 0x26ac: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26b1:
	/* 0x26b1: jmp    26cb <generic_fexit_event+0x26cb> */
	goto x86_l_26cb;
x86_l_26b3:
	/* 0x26b3: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_26b8:
	/* 0x26b8: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_26bf:
	/* 0x26bf: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_26c4:
	/* 0x26c4: jmp    26cb <generic_fexit_event+0x26cb> */
	goto x86_l_26cb;
x86_l_26c6:
	/* 0x26c6: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26cb:
	/* 0x26cb: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26d0:
	/* 0x26d0: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d5:
	/* 0x26d5: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_26da:
	/* 0x26da: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_26de:
	/* 0x26de: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_26e4:
	/* 0x26e4: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_26ee:
	/* 0x26ee: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_26f2:
	/* 0x26f2: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_26f8:
	/* 0x26f8: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26fc:
	/* 0x26fc: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26ff:
	/* 0x26ff: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2702:
	/* 0x2702: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2707:
	/* 0x2707: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_270c:
	/* 0x270c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_270f:
	/* 0x270f: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2714:
	/* 0x2714: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2717:
	/* 0x2717: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_271c:
	/* 0x271c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271e:
	/* 0x271e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2721:
	/* 0x2721: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_2727:
	/* 0x2727: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_272c:
	/* 0x272c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_272f:
	/* 0x272f: jg     2753 <generic_fexit_event+0x2753> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2753;
	}
x86_l_2731:
	/* 0x2731: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2733:
	/* 0x2733: je     277c <generic_fexit_event+0x277c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277c;
	}
x86_l_2735:
	/* 0x2735: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2738:
	/* 0x2738: je     277c <generic_fexit_event+0x277c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277c;
	}
x86_l_273a:
	/* 0x273a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_273d:
	/* 0x273d: jne    287a <generic_fexit_event+0x287a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_287a;
	}
x86_l_2743:
	/* 0x2743: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_274a:
	/* 0x274a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_274e:
	/* 0x274e: jmp    287f <generic_fexit_event+0x287f> */
	goto x86_l_287f;
x86_l_2753:
	/* 0x2753: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2756:
	/* 0x2756: je     2867 <generic_fexit_event+0x2867> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2867;
	}
x86_l_275c:
	/* 0x275c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_275f:
	/* 0x275f: je     277c <generic_fexit_event+0x277c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_277c;
	}
x86_l_2761:
	/* 0x2761: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2766:
	/* 0x2766: jne    287a <generic_fexit_event+0x287a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_287a;
	}
x86_l_276c:
	/* 0x276c: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2773:
	/* 0x2773: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2777:
	/* 0x2777: jmp    287f <generic_fexit_event+0x287f> */
	goto x86_l_287f;
x86_l_277c:
	/* 0x277c: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2781:
	/* 0x2781: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2788:
	/* 0x2788: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_278d:
	/* 0x278d: jmp    287f <generic_fexit_event+0x287f> */
	goto x86_l_287f;
x86_l_2792:
	/* 0x2792: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2794:
	/* 0x2794: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2799:
	/* 0x2799: cmp    QWORD PTR [rsp+0x90],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290629ULL);
x86_l_27a2:
	/* 0x27a2: jb     2387 <generic_fexit_event+0x2387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9095ULL;
	}
x86_l_27a8:
	/* 0x27a8: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_27b0:
	/* 0x27b0: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27b4:
	/* 0x27b4: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27b9:
	/* 0x27b9: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_27bf:
	/* 0x27bf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27c4:
	/* 0x27c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c9:
	/* 0x27c9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27ce:
	/* 0x27ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d0:
	/* 0x27d0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27d5:
	/* 0x27d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27d7:
	/* 0x27d7: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12685ULL;
	}
x86_l_27dd:
	/* 0x27dd: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27e2:
	/* 0x27e2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e7:
	/* 0x27e7: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_27ea:
	/* 0x27ea: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_27ed:
	/* 0x27ed: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_27f1:
	/* 0x27f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27f4:
	/* 0x27f4: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_27f8:
	/* 0x27f8: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27fd:
	/* 0x27fd: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2802:
	/* 0x2802: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_2809:
	/* 0x2809: ja     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12685ULL;
	}
x86_l_280f:
	/* 0x280f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2812:
	/* 0x2812: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2815:
	/* 0x2815: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2818:
	/* 0x2818: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_281e:
	/* 0x281e: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2823:
	/* 0x2823: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2828:
	/* 0x2828: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_282d:
	/* 0x282d: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2832:
	/* 0x2832: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2837:
	/* 0x2837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2839:
	/* 0x2839: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_283e:
	/* 0x283e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2840:
	/* 0x2840: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12685ULL;
	}
x86_l_2846:
	/* 0x2846: add    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_284b:
	/* 0x284b: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2851:
	/* 0x2851: je     3020 <generic_fexit_event+0x3020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12320ULL;
	}
x86_l_2857:
	/* 0x2857: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_285c:
	/* 0x285c: jne    3027 <generic_fexit_event+0x3027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12327ULL;
	}
x86_l_2862:
	/* 0x2862: jmp    2387 <generic_fexit_event+0x2387> */
	return 9095ULL;
x86_l_2867:
	/* 0x2867: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_286c:
	/* 0x286c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2873:
	/* 0x2873: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2878:
	/* 0x2878: jmp    287f <generic_fexit_event+0x287f> */
	goto x86_l_287f;
x86_l_287a:
	/* 0x287a: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_287f:
	/* 0x287f: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2884:
	/* 0x2884: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2889:
	/* 0x2889: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_288e:
	/* 0x288e: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2892:
	/* 0x2892: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_2898:
	/* 0x2898: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_28a2:
	/* 0x28a2: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_28a6:
	/* 0x28a6: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_28ac:
	/* 0x28ac: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_28b0:
	/* 0x28b0: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_28b3:
	/* 0x28b3: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28b6:
	/* 0x28b6: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_28bb:
	/* 0x28bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28c0:
	/* 0x28c0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_28c3:
	/* 0x28c3: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28c8:
	/* 0x28c8: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28cb:
	/* 0x28cb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_28d0:
	/* 0x28d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d2:
	/* 0x28d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28d5:
	/* 0x28d5: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_28db:
	/* 0x28db: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_28e0:
	/* 0x28e0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_28e3:
	/* 0x28e3: jg     2900 <generic_fexit_event+0x2900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2900;
	}
x86_l_28e5:
	/* 0x28e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28e7:
	/* 0x28e7: je     291e <generic_fexit_event+0x291e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291e;
	}
x86_l_28e9:
	/* 0x28e9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_28ec:
	/* 0x28ec: je     291e <generic_fexit_event+0x291e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291e;
	}
x86_l_28ee:
	/* 0x28ee: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_28f1:
	/* 0x28f1: jne    2944 <generic_fexit_event+0x2944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2944;
	}
x86_l_28f3:
	/* 0x28f3: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_28fa:
	/* 0x28fa: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_28fe:
	/* 0x28fe: jmp    2949 <generic_fexit_event+0x2949> */
	goto x86_l_2949;
x86_l_2900:
	/* 0x2900: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2903:
	/* 0x2903: je     2931 <generic_fexit_event+0x2931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2931;
	}
x86_l_2905:
	/* 0x2905: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2908:
	/* 0x2908: je     291e <generic_fexit_event+0x291e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291e;
	}
x86_l_290a:
	/* 0x290a: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_290f:
	/* 0x290f: jne    2944 <generic_fexit_event+0x2944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2944;
	}
x86_l_2911:
	/* 0x2911: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2918:
	/* 0x2918: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_291c:
	/* 0x291c: jmp    2949 <generic_fexit_event+0x2949> */
	goto x86_l_2949;
x86_l_291e:
	/* 0x291e: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2923:
	/* 0x2923: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_292a:
	/* 0x292a: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_292f:
	/* 0x292f: jmp    2949 <generic_fexit_event+0x2949> */
	goto x86_l_2949;
x86_l_2931:
	/* 0x2931: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2936:
	/* 0x2936: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_293d:
	/* 0x293d: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2942:
	/* 0x2942: jmp    2949 <generic_fexit_event+0x2949> */
	goto x86_l_2949;
x86_l_2944:
	/* 0x2944: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2949:
	/* 0x2949: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_294e:
	/* 0x294e: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2953:
	/* 0x2953: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2958:
	/* 0x2958: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_295c:
	/* 0x295c: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_2962:
	/* 0x2962: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_296c:
	/* 0x296c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2970:
	/* 0x2970: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_2976:
	/* 0x2976: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_297a:
	/* 0x297a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_297d:
	/* 0x297d: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2980:
	/* 0x2980: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2985:
	/* 0x2985: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_298a:
	/* 0x298a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_298d:
	/* 0x298d: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2992:
	/* 0x2992: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2995:
	/* 0x2995: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_299a:
	/* 0x299a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299c:
	/* 0x299c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299f:
	/* 0x299f: js     2a66 <generic_fexit_event+0x2a66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a66;
	}
x86_l_29a5:
	/* 0x29a5: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_29aa:
	/* 0x29aa: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_29ad:
	/* 0x29ad: jg     29ca <generic_fexit_event+0x29ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_29ca;
	}
x86_l_29af:
	/* 0x29af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29b1:
	/* 0x29b1: je     29e8 <generic_fexit_event+0x29e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e8;
	}
x86_l_29b3:
	/* 0x29b3: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_29b6:
	/* 0x29b6: je     29e8 <generic_fexit_event+0x29e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e8;
	}
x86_l_29b8:
	/* 0x29b8: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_29bb:
	/* 0x29bb: jne    2a0e <generic_fexit_event+0x2a0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a0e;
	}
x86_l_29bd:
	/* 0x29bd: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_29c4:
	/* 0x29c4: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_29c8:
	/* 0x29c8: jmp    2a13 <generic_fexit_event+0x2a13> */
	goto x86_l_2a13;
x86_l_29ca:
	/* 0x29ca: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_29cd:
	/* 0x29cd: je     29fb <generic_fexit_event+0x29fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29fb;
	}
x86_l_29cf:
	/* 0x29cf: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_29d2:
	/* 0x29d2: je     29e8 <generic_fexit_event+0x29e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e8;
	}
x86_l_29d4:
	/* 0x29d4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_29d9:
	/* 0x29d9: jne    2a0e <generic_fexit_event+0x2a0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a0e;
	}
x86_l_29db:
	/* 0x29db: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_29e2:
	/* 0x29e2: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_29e6:
	/* 0x29e6: jmp    2a13 <generic_fexit_event+0x2a13> */
	goto x86_l_2a13;
x86_l_29e8:
	/* 0x29e8: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_29ed:
	/* 0x29ed: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_29f4:
	/* 0x29f4: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29f9:
	/* 0x29f9: jmp    2a13 <generic_fexit_event+0x2a13> */
	goto x86_l_2a13;
x86_l_29fb:
	/* 0x29fb: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2a00:
	/* 0x2a00: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2a07:
	/* 0x2a07: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2a0c:
	/* 0x2a0c: jmp    2a13 <generic_fexit_event+0x2a13> */
	goto x86_l_2a13;
x86_l_2a0e:
	/* 0x2a0e: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2a13:
	/* 0x2a13: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a18:
	/* 0x2a18: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1d:
	/* 0x2a1d: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2a22:
	/* 0x2a22: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2a26:
	/* 0x2a26: ja     3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12307ULL;
	}
x86_l_2a2c:
	/* 0x2a2c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2a36:
	/* 0x2a36: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2a3a:
	/* 0x2a3a: jae    3013 <generic_fexit_event+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12307ULL;
	}
x86_l_2a40:
	/* 0x2a40: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2a44:
	/* 0x2a44: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a47:
	/* 0x2a47: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a4a:
	/* 0x2a4a: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2a4f:
	/* 0x2a4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a54:
	/* 0x2a54: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a59:
	/* 0x2a59: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a5c:
	/* 0x2a5c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2a5f:
	/* 0x2a5f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a64:
	/* 0x2a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a66:
	/* 0x2a66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a68:
	/* 0x2a68: mov    BYTE PTR [rsp+0xd0],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2a6f:
	/* 0x2a6f: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a72:
	/* 0x2a72: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a77:
	/* 0x2a77: mov    WORD PTR [r14+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2a7f:
	/* 0x2a7f: mov    WORD PTR [r14+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_2a89:
	/* 0x2a89: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2a91:
	/* 0x2a91: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a96:
	/* 0x2a96: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aa0:
	/* 0x2aa0: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2aaa:
	/* 0x2aaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aac:
	/* 0x2aac: lea    rdi,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2ab3:
	/* 0x2ab3: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2abc:
	/* 0x2abc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ac1:
	/* 0x2ac1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
	return 10950ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10950ULL: goto x86_l_2ac6;
	case 10953ULL: goto x86_l_2ac9;
	case 10955ULL: goto x86_l_2acb;
	case 10963ULL: goto x86_l_2ad3;
	case 10966ULL: goto x86_l_2ad6;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10991ULL: goto x86_l_2aef;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11031ULL: goto x86_l_2b17;
	case 11035ULL: goto x86_l_2b1b;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11065ULL: goto x86_l_2b39;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11091ULL: goto x86_l_2b53;
	case 11096ULL: goto x86_l_2b58;
	case 11098ULL: goto x86_l_2b5a;
	case 11105ULL: goto x86_l_2b61;
	case 11109ULL: goto x86_l_2b65;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11137ULL: goto x86_l_2b81;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11159ULL: goto x86_l_2b97;
	case 11166ULL: goto x86_l_2b9e;
	case 11175ULL: goto x86_l_2ba7;
	case 11184ULL: goto x86_l_2bb0;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11220ULL: goto x86_l_2bd4;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11230ULL: goto x86_l_2bde;
	case 11232ULL: goto x86_l_2be0;
	case 11236ULL: goto x86_l_2be4;
	case 11244ULL: goto x86_l_2bec;
	case 11249ULL: goto x86_l_2bf1;
	case 11254ULL: goto x86_l_2bf6;
	case 11259ULL: goto x86_l_2bfb;
	case 11263ULL: goto x86_l_2bff;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11283ULL: goto x86_l_2c13;
	case 11287ULL: goto x86_l_2c17;
	case 11292ULL: goto x86_l_2c1c;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11311ULL: goto x86_l_2c2f;
	case 11314ULL: goto x86_l_2c32;
	case 11321ULL: goto x86_l_2c39;
	case 11325ULL: goto x86_l_2c3d;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11339ULL: goto x86_l_2c4b;
	case 11341ULL: goto x86_l_2c4d;
	case 11347ULL: goto x86_l_2c53;
	case 11352ULL: goto x86_l_2c58;
	case 11357ULL: goto x86_l_2c5d;
	case 11363ULL: goto x86_l_2c63;
	case 11366ULL: goto x86_l_2c66;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11379ULL: goto x86_l_2c73;
	case 11383ULL: goto x86_l_2c77;
	case 11386ULL: goto x86_l_2c7a;
	case 11388ULL: goto x86_l_2c7c;
	case 11398ULL: goto x86_l_2c86;
	case 11408ULL: goto x86_l_2c90;
	case 11416ULL: goto x86_l_2c98;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11434ULL: goto x86_l_2caa;
	case 11441ULL: goto x86_l_2cb1;
	case 11449ULL: goto x86_l_2cb9;
	case 11454ULL: goto x86_l_2cbe;
	case 11456ULL: goto x86_l_2cc0;
	case 11463ULL: goto x86_l_2cc7;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11479ULL: goto x86_l_2cd7;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11504ULL: goto x86_l_2cf0;
	case 11512ULL: goto x86_l_2cf8;
	case 11520ULL: goto x86_l_2d00;
	case 11527ULL: goto x86_l_2d07;
	case 11533ULL: goto x86_l_2d0d;
	case 11537ULL: goto x86_l_2d11;
	case 11541ULL: goto x86_l_2d15;
	case 11545ULL: goto x86_l_2d19;
	case 11550ULL: goto x86_l_2d1e;
	case 11558ULL: goto x86_l_2d26;
	case 11562ULL: goto x86_l_2d2a;
	case 11565ULL: goto x86_l_2d2d;
	case 11569ULL: goto x86_l_2d31;
	case 11575ULL: goto x86_l_2d37;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11587ULL: goto x86_l_2d43;
	case 11589ULL: goto x86_l_2d45;
	case 11593ULL: goto x86_l_2d49;
	case 11597ULL: goto x86_l_2d4d;
	case 11599ULL: goto x86_l_2d4f;
	case 11602ULL: goto x86_l_2d52;
	case 11605ULL: goto x86_l_2d55;
	case 11608ULL: goto x86_l_2d58;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11631ULL: goto x86_l_2d6f;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11646ULL: goto x86_l_2d7e;
	case 11654ULL: goto x86_l_2d86;
	case 11659ULL: goto x86_l_2d8b;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11681ULL: goto x86_l_2da1;
	case 11688ULL: goto x86_l_2da8;
	case 11692ULL: goto x86_l_2dac;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11711ULL: goto x86_l_2dbf;
	case 11714ULL: goto x86_l_2dc2;
	case 11716ULL: goto x86_l_2dc4;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11768ULL: goto x86_l_2df8;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11778ULL: goto x86_l_2e02;
	case 11784ULL: goto x86_l_2e08;
	case 11791ULL: goto x86_l_2e0f;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11824ULL: goto x86_l_2e30;
	case 11826ULL: goto x86_l_2e32;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11875ULL: goto x86_l_2e63;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11903ULL: goto x86_l_2e7f;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11929ULL: goto x86_l_2e99;
	case 11936ULL: goto x86_l_2ea0;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11978ULL: goto x86_l_2eca;
	case 11982ULL: goto x86_l_2ece;
	case 11989ULL: goto x86_l_2ed5;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12058ULL: goto x86_l_2f1a;
	case 12060ULL: goto x86_l_2f1c;
	case 12065ULL: goto x86_l_2f21;
	case 12068ULL: goto x86_l_2f24;
	case 12074ULL: goto x86_l_2f2a;
	case 12081ULL: goto x86_l_2f31;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12116ULL: goto x86_l_2f54;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12134ULL: goto x86_l_2f66;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12146ULL: goto x86_l_2f72;
	case 12149ULL: goto x86_l_2f75;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12159ULL: goto x86_l_2f7f;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12201ULL: goto x86_l_2fa9;
	case 12204ULL: goto x86_l_2fac;
	case 12210ULL: goto x86_l_2fb2;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12221ULL: goto x86_l_2fbd;
	case 12225ULL: goto x86_l_2fc1;
	case 12228ULL: goto x86_l_2fc4;
	case 12230ULL: goto x86_l_2fc6;
	case 12233ULL: goto x86_l_2fc9;
	case 12236ULL: goto x86_l_2fcc;
	case 12240ULL: goto x86_l_2fd0;
	case 12244ULL: goto x86_l_2fd4;
	case 12251ULL: goto x86_l_2fdb;
	case 12255ULL: goto x86_l_2fdf;
	case 12259ULL: goto x86_l_2fe3;
	case 12263ULL: goto x86_l_2fe7;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12283ULL: goto x86_l_2ffb;
	case 12288ULL: goto x86_l_3000;
	case 12290ULL: goto x86_l_3002;
	case 12292ULL: goto x86_l_3004;
	case 12299ULL: goto x86_l_300b;
	case 12301ULL: goto x86_l_300d;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12322ULL: goto x86_l_3022;
	case 12327ULL: goto x86_l_3027;
	case 12336ULL: goto x86_l_3030;
	case 12342ULL: goto x86_l_3036;
	case 12350ULL: goto x86_l_303e;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12389ULL: goto x86_l_3065;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12405ULL: goto x86_l_3075;
	case 12408ULL: goto x86_l_3078;
	case 12411ULL: goto x86_l_307b;
	case 12415ULL: goto x86_l_307f;
	case 12418ULL: goto x86_l_3082;
	case 12422ULL: goto x86_l_3086;
	case 12427ULL: goto x86_l_308b;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12451ULL: goto x86_l_30a3;
	case 12457ULL: goto x86_l_30a9;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12480ULL: goto x86_l_30c0;
	case 12482ULL: goto x86_l_30c2;
	case 12487ULL: goto x86_l_30c7;
	case 12489ULL: goto x86_l_30c9;
	case 12495ULL: goto x86_l_30cf;
	case 12498ULL: goto x86_l_30d2;
	case 12504ULL: goto x86_l_30d8;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12513ULL: goto x86_l_30e1;
	case 12518ULL: goto x86_l_30e6;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12534ULL: goto x86_l_30f6;
	case 12540ULL: goto x86_l_30fc;
	case 12548ULL: goto x86_l_3104;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12587ULL: goto x86_l_312b;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12602ULL: goto x86_l_313a;
	case 12605ULL: goto x86_l_313d;
	case 12609ULL: goto x86_l_3141;
	case 12612ULL: goto x86_l_3144;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12633ULL: goto x86_l_3159;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12663ULL: goto x86_l_3177;
	case 12666ULL: goto x86_l_317a;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12675ULL: goto x86_l_3183;
	case 12677ULL: goto x86_l_3185;
	case 12680ULL: goto x86_l_3188;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12699ULL: goto x86_l_319b;
	case 12704ULL: goto x86_l_31a0;
	case 12705ULL: goto x86_l_31a1;
	case 12707ULL: goto x86_l_31a3;
	case 12709ULL: goto x86_l_31a5;
	case 12711ULL: goto x86_l_31a7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2ac6:
	/* 0x2ac6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ac9:
	/* 0x2ac9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2acb:
	/* 0x2acb: movzx  eax,BYTE PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 208ULL);
x86_l_2ad3:
	/* 0x2ad3: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2ad6:
	/* 0x2ad6: je     2b2b <generic_fexit_event+0x2b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b2b;
	}
x86_l_2ad8:
	/* 0x2ad8: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2adb:
	/* 0x2adb: jne    2b7c <generic_fexit_event+0x2b7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b7c;
	}
x86_l_2ae1:
	/* 0x2ae1: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ae6:
	/* 0x2ae6: movzx  r12d,WORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 216ULL);
x86_l_2aef:
	/* 0x2aef: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2af3:
	/* 0x2af3: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2af8:
	/* 0x2af8: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2aff:
	/* 0x2aff: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b04:
	/* 0x2b04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b09:
	/* 0x2b09: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b0e:
	/* 0x2b0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b10:
	/* 0x2b10: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2b17:
	/* 0x2b17: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2b1b:
	/* 0x2b1b: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b24:
	/* 0x2b24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b29:
	/* 0x2b29: jmp    2b73 <generic_fexit_event+0x2b73> */
	goto x86_l_2b73;
x86_l_2b2b:
	/* 0x2b2b: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b30:
	/* 0x2b30: movzx  r12d,WORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 216ULL);
x86_l_2b39:
	/* 0x2b39: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b42:
	/* 0x2b42: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2b49:
	/* 0x2b49: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b53:
	/* 0x2b53: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b58:
	/* 0x2b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5a:
	/* 0x2b5a: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2b61:
	/* 0x2b61: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2b65:
	/* 0x2b65: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2b69:
	/* 0x2b69: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b73:
	/* 0x2b73: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b78:
	/* 0x2b78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7a:
	/* 0x2b7a: jmp    2b8b <generic_fexit_event+0x2b8b> */
	goto x86_l_2b8b;
x86_l_2b7c:
	/* 0x2b7c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b81:
	/* 0x2b81: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b90:
	/* 0x2b90: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2b97:
	/* 0x2b97: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2b9e:
	/* 0x2b9e: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2ba7:
	/* 0x2ba7: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2bb0:
	/* 0x2bb0: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2bb7:
	/* 0x2bb7: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bbc:
	/* 0x2bbc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2bd4:
	/* 0x2bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd6:
	/* 0x2bd6: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bdb:
	/* 0x2bdb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2bde:
	/* 0x2bde: je     2c4d <generic_fexit_event+0x2c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c4d;
	}
x86_l_2be0:
	/* 0x2be0: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2be4:
	/* 0x2be4: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2bec:
	/* 0x2bec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bf1:
	/* 0x2bf1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bf6:
	/* 0x2bf6: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bfb:
	/* 0x2bfb: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2bff:
	/* 0x2bff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c04:
	/* 0x2c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c06:
	/* 0x2c06: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c0b:
	/* 0x2c0b: mov    r13,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2c13:
	/* 0x2c13: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2c17:
	/* 0x2c17: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1c:
	/* 0x2c1c: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2c23:
	/* 0x2c23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c28:
	/* 0x2c28: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c2d:
	/* 0x2c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2f:
	/* 0x2c2f: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2c32:
	/* 0x2c32: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2c39:
	/* 0x2c39: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2c3d:
	/* 0x2c3d: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2c41:
	/* 0x2c41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c46:
	/* 0x2c46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c4b:
	/* 0x2c4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4d:
	/* 0x2c4d: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2c53:
	/* 0x2c53: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c58:
	/* 0x2c58: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2c63:
	/* 0x2c63: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_2c66:
	/* 0x2c66: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c6a:
	/* 0x2c6a: js     2c7c <generic_fexit_event+0x2c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c7c;
	}
x86_l_2c6c:
	/* 0x2c6c: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2c73:
	/* 0x2c73: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2c77:
	/* 0x2c77: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2c7a:
	/* 0x2c7a: jmp    2c90 <generic_fexit_event+0x2c90> */
	goto x86_l_2c90;
x86_l_2c7c:
	/* 0x2c7c: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_2c86:
	/* 0x2c86: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_2c90:
	/* 0x2c90: mov    r13,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2c98:
	/* 0x2c98: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c9c:
	/* 0x2c9c: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ca1:
	/* 0x2ca1: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2ca4:
	/* 0x2ca4: jne    29e <generic_fexit_event+0x29e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 670ULL;
	}
x86_l_2caa:
	/* 0x2caa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2cb1:
	/* 0x2cb1: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2cbe:
	/* 0x2cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc0:
	/* 0x2cc0: and    r14d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_2cc7:
	/* 0x2cc7: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2cce:
	/* 0x2cce: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2cd1:
	/* 0x2cd1: je     19f <generic_fexit_event+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 415ULL;
	}
x86_l_2cd7:
	/* 0x2cd7: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2cda:
	/* 0x2cda: jne    2d68 <generic_fexit_event+0x2d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d68;
	}
x86_l_2ce0:
	/* 0x2ce0: mov    QWORD PTR [rsp+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ced:
	/* 0x2ced: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2cf0:
	/* 0x2cf0: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    rbx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2d00:
	/* 0x2d00: cmp    rbx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4095ULL);
x86_l_2d07:
	/* 0x2d07: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2d0d:
	/* 0x2d0d: cmovb  r12,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_2d11:
	/* 0x2d11: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2d15:
	/* 0x2d15: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2d19:
	/* 0x2d19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d1e:
	/* 0x2d1e: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2d26:
	/* 0x2d26: lea    r13,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d2a:
	/* 0x2d2a: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d2d:
	/* 0x2d2d: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2d31:
	/* 0x2d31: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2d37:
	/* 0x2d37: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2d3a:
	/* 0x2d3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3c:
	/* 0x2d3c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2d41:
	/* 0x2d41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d43:
	/* 0x2d43: js     2d52 <generic_fexit_event+0x2d52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2d52;
	}
x86_l_2d45:
	/* 0x2d45: mov    DWORD PTR [r15+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d49:
	/* 0x2d49: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_2d4f:
	/* 0x2d4f: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_2d52:
	/* 0x2d52: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d55:
	/* 0x2d55: mov    DWORD PTR [r15],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d58:
	/* 0x2d58: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_2d5b:
	/* 0x2d5b: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d60:
	/* 0x2d60: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2d68:
	/* 0x2d68: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2d6d:
	/* 0x2d6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6f:
	/* 0x2d6f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2d72:
	/* 0x2d72: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d77:
	/* 0x2d77: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2d7e:
	/* 0x2d7e: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2d86:
	/* 0x2d86: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2d8b:
	/* 0x2d8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d90:
	/* 0x2d90: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2d95:
	/* 0x2d95: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d9f:
	/* 0x2d9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da1:
	/* 0x2da1: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2da8:
	/* 0x2da8: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2dac:
	/* 0x2dac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2db3:
	/* 0x2db3: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2db8:
	/* 0x2db8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2dbd:
	/* 0x2dbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dbf:
	/* 0x2dbf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2dc2:
	/* 0x2dc2: je     2dd2 <generic_fexit_event+0x2dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dd2;
	}
x86_l_2dc4:
	/* 0x2dc4: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2dc7:
	/* 0x2dc7: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2dcc:
	/* 0x2dcc: jne    2fac <generic_fexit_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fac;
	}
x86_l_2dd2:
	/* 0x2dd2: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2dd7:
	/* 0x2dd7: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ddc:
	/* 0x2ddc: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ddf:
	/* 0x2ddf: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2de4:
	/* 0x2de4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2de9:
	/* 0x2de9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dee:
	/* 0x2dee: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2df3:
	/* 0x2df3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df8:
	/* 0x2df8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dfa:
	/* 0x2dfa: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2dff:
	/* 0x2dff: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2e02:
	/* 0x2e02: je     2fa9 <generic_fexit_event+0x2fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fa9;
	}
x86_l_2e08:
	/* 0x2e08: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2e0f:
	/* 0x2e0f: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2e17:
	/* 0x2e17: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e21:
	/* 0x2e21: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2e26:
	/* 0x2e26: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e30:
	/* 0x2e30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e32:
	/* 0x2e32: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2e39:
	/* 0x2e39: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e3d:
	/* 0x2e3d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2e44:
	/* 0x2e44: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e49:
	/* 0x2e49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e4e:
	/* 0x2e4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e50:
	/* 0x2e50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e53:
	/* 0x2e53: je     2e63 <generic_fexit_event+0x2e63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e63;
	}
x86_l_2e55:
	/* 0x2e55: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2e58:
	/* 0x2e58: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e5d:
	/* 0x2e5d: jne    2fac <generic_fexit_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fac;
	}
x86_l_2e63:
	/* 0x2e63: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2e68:
	/* 0x2e68: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e6d:
	/* 0x2e6d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e70:
	/* 0x2e70: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e75:
	/* 0x2e75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e7a:
	/* 0x2e7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e7f:
	/* 0x2e7f: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2e84:
	/* 0x2e84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e89:
	/* 0x2e89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8b:
	/* 0x2e8b: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e90:
	/* 0x2e90: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2e93:
	/* 0x2e93: je     2fa9 <generic_fexit_event+0x2fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fa9;
	}
x86_l_2e99:
	/* 0x2e99: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2ea0:
	/* 0x2ea0: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2ead:
	/* 0x2ead: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2eb7:
	/* 0x2eb7: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2ebc:
	/* 0x2ebc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ec1:
	/* 0x2ec1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec3:
	/* 0x2ec3: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2eca:
	/* 0x2eca: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ece:
	/* 0x2ece: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2ed5:
	/* 0x2ed5: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2eda:
	/* 0x2eda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2edf:
	/* 0x2edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee1:
	/* 0x2ee1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ee4:
	/* 0x2ee4: je     2ef4 <generic_fexit_event+0x2ef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ef4;
	}
x86_l_2ee6:
	/* 0x2ee6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ee9:
	/* 0x2ee9: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2eee:
	/* 0x2eee: jne    2fac <generic_fexit_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fac;
	}
x86_l_2ef4:
	/* 0x2ef4: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2efe:
	/* 0x2efe: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f01:
	/* 0x2f01: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f06:
	/* 0x2f06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f10:
	/* 0x2f10: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2f15:
	/* 0x2f15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1a:
	/* 0x2f1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1c:
	/* 0x2f1c: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f21:
	/* 0x2f21: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2f24:
	/* 0x2f24: je     2fa9 <generic_fexit_event+0x2fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fa9;
	}
x86_l_2f2a:
	/* 0x2f2a: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2f31:
	/* 0x2f31: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2f39:
	/* 0x2f39: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f43:
	/* 0x2f43: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2f48:
	/* 0x2f48: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2f4d:
	/* 0x2f4d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f52:
	/* 0x2f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f54:
	/* 0x2f54: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2f5b:
	/* 0x2f5b: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2f66:
	/* 0x2f66: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2f6b:
	/* 0x2f6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f70:
	/* 0x2f70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f72:
	/* 0x2f72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f75:
	/* 0x2f75: je     2f81 <generic_fexit_event+0x2f81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f81;
	}
x86_l_2f77:
	/* 0x2f77: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2f7a:
	/* 0x2f7a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f7f:
	/* 0x2f7f: jne    2fac <generic_fexit_event+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fac;
	}
x86_l_2f81:
	/* 0x2f81: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2f86:
	/* 0x2f86: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f8b:
	/* 0x2f8b: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f8e:
	/* 0x2f8e: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f93:
	/* 0x2f93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f98:
	/* 0x2f98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f9d:
	/* 0x2f9d: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa7:
	/* 0x2fa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa9:
	/* 0x2fa9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fac:
	/* 0x2fac: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fb6:
	/* 0x2fb6: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2fbb:
	/* 0x2fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fbd:
	/* 0x2fbd: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc1:
	/* 0x2fc1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2fc4:
	/* 0x2fc4: je     2fd4 <generic_fexit_event+0x2fd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd4;
	}
x86_l_2fc6:
	/* 0x2fc6: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc9:
	/* 0x2fc9: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd0:
	/* 0x2fd0: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2fdb:
	/* 0x2fdb: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fdf:
	/* 0x2fdf: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2fe3:
	/* 0x2fe3: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fe7:
	/* 0x2fe7: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&fexit_calls)));
x86_l_2fee:
	/* 0x2fee: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2ff3:
	/* 0x2ff3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ff8:
	/* 0x2ff8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2ffb:
	/* 0x2ffb: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3000:
	/* 0x3000: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3002:
	/* 0x3002: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3004:
	/* 0x3004: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_300b:
	/* 0x300b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_300d:
	/* 0x300d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_300e:
	/* 0x300e: jmp    334f <cwd_read_v61+0x1af> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3013:
	/* 0x3013: mov    WORD PTR [rsp+0xd8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_301b:
	/* 0x301b: jmp    2a68 <generic_fexit_event+0x2a68> */
	return 10856ULL;
x86_l_3020:
	/* 0x3020: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3022:
	/* 0x3022: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3027:
	/* 0x3027: cmp    QWORD PTR [rsp+0x90],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290629ULL);
x86_l_3030:
	/* 0x3030: je     2387 <generic_fexit_event+0x2387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9095ULL;
	}
x86_l_3036:
	/* 0x3036: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_303e:
	/* 0x303e: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3042:
	/* 0x3042: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3047:
	/* 0x3047: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_304d:
	/* 0x304d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3052:
	/* 0x3052: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3057:
	/* 0x3057: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_305c:
	/* 0x305c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_305e:
	/* 0x305e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3063:
	/* 0x3063: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3065:
	/* 0x3065: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_318d;
	}
x86_l_306b:
	/* 0x306b: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3070:
	/* 0x3070: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3075:
	/* 0x3075: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3078:
	/* 0x3078: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_307b:
	/* 0x307b: cmovb  r12,r15 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R15, X86_WIDTH_64, X86_CC_B);
x86_l_307f:
	/* 0x307f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3082:
	/* 0x3082: cmovne r15,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_3086:
	/* 0x3086: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_308b:
	/* 0x308b: cmp    r15,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4094ULL);
x86_l_3092:
	/* 0x3092: ja     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_318d;
	}
x86_l_3098:
	/* 0x3098: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309d:
	/* 0x309d: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30a0:
	/* 0x30a0: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_30a3:
	/* 0x30a3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_30a9:
	/* 0x30a9: add    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_30ae:
	/* 0x30ae: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30b3:
	/* 0x30b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30b8:
	/* 0x30b8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30bd:
	/* 0x30bd: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_30c0:
	/* 0x30c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c2:
	/* 0x30c2: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_30c7:
	/* 0x30c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30c9:
	/* 0x30c9: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_318d;
	}
x86_l_30cf:
	/* 0x30cf: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30d2:
	/* 0x30d2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30d8:
	/* 0x30d8: je     30e6 <generic_fexit_event+0x30e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30e6;
	}
x86_l_30da:
	/* 0x30da: sub    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 16ULL);
x86_l_30df:
	/* 0x30df: jne    30ed <generic_fexit_event+0x30ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_30ed;
	}
x86_l_30e1:
	/* 0x30e1: jmp    2387 <generic_fexit_event+0x2387> */
	return 9095ULL;
x86_l_30e6:
	/* 0x30e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30e8:
	/* 0x30e8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ed:
	/* 0x30ed: cmp    QWORD PTR [rsp+0x90],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290631ULL);
x86_l_30f6:
	/* 0x30f6: jb     2387 <generic_fexit_event+0x2387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9095ULL;
	}
x86_l_30fc:
	/* 0x30fc: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3104:
	/* 0x3104: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_3108:
	/* 0x3108: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_310d:
	/* 0x310d: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3113:
	/* 0x3113: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3118:
	/* 0x3118: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_311d:
	/* 0x311d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3122:
	/* 0x3122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3124:
	/* 0x3124: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3129:
	/* 0x3129: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_312b:
	/* 0x312b: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_318d;
	}
x86_l_312d:
	/* 0x312d: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3132:
	/* 0x3132: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3137:
	/* 0x3137: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_313a:
	/* 0x313a: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_313d:
	/* 0x313d: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_3141:
	/* 0x3141: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_3144:
	/* 0x3144: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_3148:
	/* 0x3148: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_314d:
	/* 0x314d: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_3154:
	/* 0x3154: ja     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_318d;
	}
x86_l_3156:
	/* 0x3156: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3159:
	/* 0x3159: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3160:
	/* 0x3160: add    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3165:
	/* 0x3165: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_316a:
	/* 0x316a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_316f:
	/* 0x316f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3174:
	/* 0x3174: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_3177:
	/* 0x3177: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_317a:
	/* 0x317a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317c:
	/* 0x317c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3181:
	/* 0x3181: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3183:
	/* 0x3183: js     318d <generic_fexit_event+0x318d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_318d;
	}
x86_l_3185:
	/* 0x3185: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3188:
	/* 0x3188: jmp    238a <generic_fexit_event+0x238a> */
	return 9098ULL;
x86_l_318d:
	/* 0x318d: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3192:
	/* 0x3192: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3197:
	/* 0x3197: mov    DWORD PTR [rax+r14*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_319b:
	/* 0x319b: jmp    18af <generic_fexit_event+0x18af> */
	return 6319ULL;
x86_l_31a0:
	/* 0x31a0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_31a1:
	/* 0x31a1: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_31a3:
	/* 0x31a3: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_31a5:
	/* 0x31a5: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_31a7:
	/* 0x31a7: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
	return 12713ULL;
}

static __noinline __u64 tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12713ULL: goto x86_l_31a9;
	case 12714ULL: goto x86_l_31aa;
	case 12718ULL: goto x86_l_31ae;
	case 12721ULL: goto x86_l_31b1;
	case 12725ULL: goto x86_l_31b5;
	case 12729ULL: goto x86_l_31b9;
	case 12733ULL: goto x86_l_31bd;
	case 12736ULL: goto x86_l_31c0;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12748ULL: goto x86_l_31cc;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12826ULL: goto x86_l_321a;
	case 12831ULL: goto x86_l_321f;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12846ULL: goto x86_l_322e;
	case 12849ULL: goto x86_l_3231;
	case 12851ULL: goto x86_l_3233;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12865ULL: goto x86_l_3241;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12880ULL: goto x86_l_3250;
	case 12884ULL: goto x86_l_3254;
	case 12888ULL: goto x86_l_3258;
	case 12892ULL: goto x86_l_325c;
	case 12895ULL: goto x86_l_325f;
	case 12899ULL: goto x86_l_3263;
	case 12901ULL: goto x86_l_3265;
	case 12903ULL: goto x86_l_3267;
	case 12906ULL: goto x86_l_326a;
	case 12909ULL: goto x86_l_326d;
	case 12914ULL: goto x86_l_3272;
	case 12916ULL: goto x86_l_3274;
	case 12919ULL: goto x86_l_3277;
	case 12923ULL: goto x86_l_327b;
	case 12925ULL: goto x86_l_327d;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12934ULL: goto x86_l_3286;
	case 12936ULL: goto x86_l_3288;
	case 12939ULL: goto x86_l_328b;
	case 12944ULL: goto x86_l_3290;
	case 12947ULL: goto x86_l_3293;
	case 12953ULL: goto x86_l_3299;
	case 12960ULL: goto x86_l_32a0;
	case 12966ULL: goto x86_l_32a6;
	case 12969ULL: goto x86_l_32a9;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12985ULL: goto x86_l_32b9;
	case 12989ULL: goto x86_l_32bd;
	case 12992ULL: goto x86_l_32c0;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13006ULL: goto x86_l_32ce;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13021ULL: goto x86_l_32dd;
	case 13024ULL: goto x86_l_32e0;
	case 13026ULL: goto x86_l_32e2;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13052ULL: goto x86_l_32fc;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13063ULL: goto x86_l_3307;
	case 13067ULL: goto x86_l_330b;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13088ULL: goto x86_l_3320;
	case 13090ULL: goto x86_l_3322;
	case 13095ULL: goto x86_l_3327;
	case 13099ULL: goto x86_l_332b;
	case 13103ULL: goto x86_l_332f;
	case 13107ULL: goto x86_l_3333;
	case 13109ULL: goto x86_l_3335;
	case 13111ULL: goto x86_l_3337;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13124ULL: goto x86_l_3344;
	case 13125ULL: goto x86_l_3345;
	case 13127ULL: goto x86_l_3347;
	case 13129ULL: goto x86_l_3349;
	case 13131ULL: goto x86_l_334b;
	case 13133ULL: goto x86_l_334d;
	case 13134ULL: goto x86_l_334e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31a9:
	/* 0x31a9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_31aa:
	/* 0x31aa: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_31ae:
	/* 0x31ae: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_31b1:
	/* 0x31b1: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31b5:
	/* 0x31b5: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31b9:
	/* 0x31b9: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31bd:
	/* 0x31bd: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_31c0:
	/* 0x31c0: jne    31cc <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31cc;
	}
x86_l_31c2:
	/* 0x31c2: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_31c6:
	/* 0x31c6: je     3337 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3337;
	}
x86_l_31cc:
	/* 0x31cc: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31d0:
	/* 0x31d0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31d5:
	/* 0x31d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31da:
	/* 0x31da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31df:
	/* 0x31df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31e4:
	/* 0x31e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e6:
	/* 0x31e6: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_31eb:
	/* 0x31eb: je     32e2 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e2;
	}
x86_l_31f1:
	/* 0x31f1: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31f6:
	/* 0x31f6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fb:
	/* 0x31fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3200:
	/* 0x3200: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3205:
	/* 0x3205: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_320a:
	/* 0x320a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_320f:
	/* 0x320f: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3214:
	/* 0x3214: je     32e2 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e2;
	}
x86_l_321a:
	/* 0x321a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_321f:
	/* 0x321f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3224:
	/* 0x3224: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3229:
	/* 0x3229: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_322e:
	/* 0x322e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3231:
	/* 0x3231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3233:
	/* 0x3233: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3237:
	/* 0x3237: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_323c:
	/* 0x323c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3241:
	/* 0x3241: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3246:
	/* 0x3246: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_324b:
	/* 0x324b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_324e:
	/* 0x324e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3250:
	/* 0x3250: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3254:
	/* 0x3254: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3258:
	/* 0x3258: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_325c:
	/* 0x325c: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_325f:
	/* 0x325f: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3263:
	/* 0x3263: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3265:
	/* 0x3265: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3267:
	/* 0x3267: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_326a:
	/* 0x326a: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_326d:
	/* 0x326d: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3272:
	/* 0x3272: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3274:
	/* 0x3274: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3277:
	/* 0x3277: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_327b:
	/* 0x327b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_327d:
	/* 0x327d: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3281:
	/* 0x3281: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3283:
	/* 0x3283: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3286:
	/* 0x3286: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3288:
	/* 0x3288: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_328b:
	/* 0x328b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3290:
	/* 0x3290: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3293:
	/* 0x3293: jb     3340 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3340;
	}
x86_l_3299:
	/* 0x3299: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_32a0:
	/* 0x32a0: ja     3340 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3340;
	}
x86_l_32a6:
	/* 0x32a6: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_32a9:
	/* 0x32a9: jbe    32b0 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32b0;
	}
x86_l_32ab:
	/* 0x32ab: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_32b0:
	/* 0x32b0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32b2:
	/* 0x32b2: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_32b5:
	/* 0x32b5: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_32b9:
	/* 0x32b9: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32bd:
	/* 0x32bd: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32c0:
	/* 0x32c0: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32c3:
	/* 0x32c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32c8:
	/* 0x32c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ca:
	/* 0x32ca: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ce:
	/* 0x32ce: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_32d1:
	/* 0x32d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32d6:
	/* 0x32d6: jbe    3340 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3340;
	}
x86_l_32d8:
	/* 0x32d8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32dd:
	/* 0x32dd: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e0:
	/* 0x32e0: jmp    3333 <cwd_read_v61+0x193> */
	goto x86_l_3333;
x86_l_32e2:
	/* 0x32e2: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32e6:
	/* 0x32e6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32eb:
	/* 0x32eb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32f0:
	/* 0x32f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32f5:
	/* 0x32f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32fa:
	/* 0x32fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fc:
	/* 0x32fc: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3300:
	/* 0x3300: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3305:
	/* 0x3305: je     3337 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3337;
	}
x86_l_3307:
	/* 0x3307: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_330b:
	/* 0x330b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3310:
	/* 0x3310: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3315:
	/* 0x3315: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3318:
	/* 0x3318: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_331d:
	/* 0x331d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3320:
	/* 0x3320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3322:
	/* 0x3322: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3327:
	/* 0x3327: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_332b:
	/* 0x332b: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_332f:
	/* 0x332f: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3333:
	/* 0x3333: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3335:
	/* 0x3335: jmp    3340 <cwd_read_v61+0x1a0> */
	goto x86_l_3340;
x86_l_3337:
	/* 0x3337: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_333b:
	/* 0x333b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3340:
	/* 0x3340: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3344:
	/* 0x3344: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3345:
	/* 0x3345: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3347:
	/* 0x3347: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3349:
	/* 0x3349: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_334b:
	/* 0x334b: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_334d:
	/* 0x334d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_334e:
	/* 0x334e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11208U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1858ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1866ULL && __x86_pc <= 3760ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3765ULL && __x86_pc <= 5644ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5646ULL && __x86_pc <= 7487ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7494ULL && __x86_pc <= 9303ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9310ULL && __x86_pc <= 10945ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10950ULL && __x86_pc <= 12711ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12713ULL && __x86_pc <= 13134ULL)
			__x86_pc = tetragon_bpf_generic_fexit_v61_generic_fexit_event_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

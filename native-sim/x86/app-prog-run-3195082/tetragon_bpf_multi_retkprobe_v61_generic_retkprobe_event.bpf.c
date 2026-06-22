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
	case 43ULL: goto x86_l_2b;
	case 51ULL: goto x86_l_33;
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
	case 106ULL: goto x86_l_6a;
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
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 187ULL: goto x86_l_bb;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 215ULL: goto x86_l_d7;
	case 223ULL: goto x86_l_df;
	case 227ULL: goto x86_l_e3;
	case 235ULL: goto x86_l_eb;
	case 242ULL: goto x86_l_f2;
	case 247ULL: goto x86_l_f7;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 274ULL: goto x86_l_112;
	case 276ULL: goto x86_l_114;
	case 280ULL: goto x86_l_118;
	case 290ULL: goto x86_l_122;
	case 298ULL: goto x86_l_12a;
	case 309ULL: goto x86_l_135;
	case 316ULL: goto x86_l_13c;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 331ULL: goto x86_l_14b;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 363ULL: goto x86_l_16b;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 388ULL: goto x86_l_184;
	case 395ULL: goto x86_l_18b;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 412ULL: goto x86_l_19c;
	case 415ULL: goto x86_l_19f;
	case 419ULL: goto x86_l_1a3;
	case 428ULL: goto x86_l_1ac;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 460ULL: goto x86_l_1cc;
	case 465ULL: goto x86_l_1d1;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 489ULL: goto x86_l_1e9;
	case 494ULL: goto x86_l_1ee;
	case 496ULL: goto x86_l_1f0;
	case 501ULL: goto x86_l_1f5;
	case 503ULL: goto x86_l_1f7;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 520ULL: goto x86_l_208;
	case 523ULL: goto x86_l_20b;
	case 527ULL: goto x86_l_20f;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 546ULL: goto x86_l_222;
	case 552ULL: goto x86_l_228;
	case 556ULL: goto x86_l_22c;
	case 560ULL: goto x86_l_230;
	case 564ULL: goto x86_l_234;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 579ULL: goto x86_l_243;
	case 582ULL: goto x86_l_246;
	case 584ULL: goto x86_l_248;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 622ULL: goto x86_l_26e;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 636ULL: goto x86_l_27c;
	case 640ULL: goto x86_l_280;
	case 644ULL: goto x86_l_284;
	case 649ULL: goto x86_l_289;
	case 652ULL: goto x86_l_28c;
	case 658ULL: goto x86_l_292;
	case 661ULL: goto x86_l_295;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 747ULL: goto x86_l_2eb;
	case 751ULL: goto x86_l_2ef;
	case 755ULL: goto x86_l_2f3;
	case 763ULL: goto x86_l_2fb;
	case 768ULL: goto x86_l_300;
	case 770ULL: goto x86_l_302;
	case 774ULL: goto x86_l_306;
	case 776ULL: goto x86_l_308;
	case 780ULL: goto x86_l_30c;
	case 786ULL: goto x86_l_312;
	case 790ULL: goto x86_l_316;
	case 796ULL: goto x86_l_31c;
	case 808ULL: goto x86_l_328;
	case 816ULL: goto x86_l_330;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 832ULL: goto x86_l_340;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 857ULL: goto x86_l_359;
	case 863ULL: goto x86_l_35f;
	case 867ULL: goto x86_l_363;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 880ULL: goto x86_l_370;
	case 885ULL: goto x86_l_375;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 935ULL: goto x86_l_3a7;
	case 940ULL: goto x86_l_3ac;
	case 942ULL: goto x86_l_3ae;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 961ULL: goto x86_l_3c1;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 987ULL: goto x86_l_3db;
	case 998ULL: goto x86_l_3e6;
	case 1005ULL: goto x86_l_3ed;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1023ULL: goto x86_l_3ff;
	case 1029ULL: goto x86_l_405;
	case 1032ULL: goto x86_l_408;
	case 1038ULL: goto x86_l_40e;
	case 1043ULL: goto x86_l_413;
	case 1048ULL: goto x86_l_418;
	case 1050ULL: goto x86_l_41a;
	case 1057ULL: goto x86_l_421;
	case 1065ULL: goto x86_l_429;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1080ULL: goto x86_l_438;
	case 1082ULL: goto x86_l_43a;
	case 1090ULL: goto x86_l_442;
	case 1098ULL: goto x86_l_44a;
	case 1103ULL: goto x86_l_44f;
	case 1111ULL: goto x86_l_457;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1125ULL: goto x86_l_465;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1146ULL: goto x86_l_47a;
	case 1148ULL: goto x86_l_47c;
	case 1156ULL: goto x86_l_484;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1183ULL: goto x86_l_49f;
	case 1189ULL: goto x86_l_4a5;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1232ULL: goto x86_l_4d0;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1266ULL: goto x86_l_4f2;
	case 1276ULL: goto x86_l_4fc;
	case 1283ULL: goto x86_l_503;
	case 1293ULL: goto x86_l_50d;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1313ULL: goto x86_l_521;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1336ULL: goto x86_l_538;
	case 1345ULL: goto x86_l_541;
	case 1354ULL: goto x86_l_54a;
	case 1359ULL: goto x86_l_54f;
	case 1364ULL: goto x86_l_554;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1393ULL: goto x86_l_571;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1408ULL: goto x86_l_580;
	case 1413ULL: goto x86_l_585;
	case 1416ULL: goto x86_l_588;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1436ULL: goto x86_l_59c;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1446ULL: goto x86_l_5a6;
	case 1451ULL: goto x86_l_5ab;
	case 1456ULL: goto x86_l_5b0;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1472ULL: goto x86_l_5c0;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1523ULL: goto x86_l_5f3;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1542ULL: goto x86_l_606;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
	case 1635ULL: goto x86_l_663;
	case 1638ULL: goto x86_l_666;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1672ULL: goto x86_l_688;
	case 1674ULL: goto x86_l_68a;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1701ULL: goto x86_l_6a5;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1729ULL: goto x86_l_6c1;
	case 1732ULL: goto x86_l_6c4;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
	case 1750ULL: goto x86_l_6d6;
	case 1754ULL: goto x86_l_6da;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1763ULL: goto x86_l_6e3;
	case 1766ULL: goto x86_l_6e6;
	case 1768ULL: goto x86_l_6e8;
	case 1772ULL: goto x86_l_6ec;
	case 1775ULL: goto x86_l_6ef;
	case 1781ULL: goto x86_l_6f5;
	case 1787ULL: goto x86_l_6fb;
	case 1793ULL: goto x86_l_701;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1808ULL: goto x86_l_710;
	case 1812ULL: goto x86_l_714;
	case 1815ULL: goto x86_l_717;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
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
	/* 0x11: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_19:
	/* 0x19: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_24:
	/* 0x24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2b:
	/* 0x2b: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_33:
	/* 0x33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
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
	/* 0x3f: je     2faa <generic_retkprobe_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12202ULL;
	}
x86_l_45:
	/* 0x45: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_50:
	/* 0x50: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
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
	/* 0x63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_6a:
	/* 0x6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f:
	/* 0x6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71:
	/* 0x71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: je     2faa <generic_retkprobe_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12202ULL;
	}
x86_l_7a:
	/* 0x7a: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x90: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94:
	/* 0x94: mov    QWORD PTR [rbx+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_98:
	/* 0x98: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9d:
	/* 0x9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f:
	/* 0x9f: mov    DWORD PTR [rbx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_a2:
	/* 0xa2: mov    rax,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a6:
	/* 0xa6: mov    rcx,QWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b4:
	/* 0xb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_bb:
	/* 0xbb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c0:
	/* 0xc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c5:
	/* 0xc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7:
	/* 0xc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: je     2faa <generic_retkprobe_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12202ULL;
	}
x86_l_d0:
	/* 0xd0: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3:
	/* 0xd3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7:
	/* 0xd7: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_df:
	/* 0xdf: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e3:
	/* 0xe3: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_eb:
	/* 0xeb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_f2:
	/* 0xf2: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f7:
	/* 0xf7: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_fc:
	/* 0xfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rbx+0x90],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_105:
	/* 0x105: mov    ebp,DWORD PTR [r12+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10a:
	/* 0x10a: mov    r14d,DWORD PTR [r12+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_10f:
	/* 0x10f: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_112:
	/* 0x112: je     17e <generic_retkprobe_event+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17e;
	}
x86_l_114:
	/* 0x114: mov    DWORD PTR [rsp+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118:
	/* 0x118: mov    DWORD PTR [rbx+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_122:
	/* 0x122: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_12a:
	/* 0x12a: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_135:
	/* 0x135: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_13c:
	/* 0x13c: lea    rsi,[rsp+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_144:
	/* 0x144: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_149:
	/* 0x149: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b:
	/* 0x14b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: je     279 <generic_retkprobe_event+0x279> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279;
	}
x86_l_154:
	/* 0x154: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_15a:
	/* 0x15a: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_160:
	/* 0x160: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_16b:
	/* 0x16b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_16d:
	/* 0x16d: je     2d6 <generic_retkprobe_event+0x2d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d6;
	}
x86_l_173:
	/* 0x173: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_179:
	/* 0x179: jmp    27c <generic_retkprobe_event+0x27c> */
	goto x86_l_27c;
x86_l_17e:
	/* 0x17e: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_184:
	/* 0x184: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18b:
	/* 0x18b: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_18e:
	/* 0x18e: jne    2c7a <generic_retkprobe_event+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11386ULL;
	}
x86_l_194:
	/* 0x194: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19c:
	/* 0x19c: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_19f:
	/* 0x19f: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a3:
	/* 0x1a3: cmp    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [rsp+0xb8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b9:
	/* 0x1b9: je     33d <generic_retkprobe_event+0x33d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d;
	}
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c4:
	/* 0x1c4: mov    r14,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1cc:
	/* 0x1cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d1:
	/* 0x1d1: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1d7:
	/* 0x1d7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1dc:
	/* 0x1dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1:
	/* 0x1e1: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1e9:
	/* 0x1e9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ee:
	/* 0x1ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0:
	/* 0x1f0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1f5:
	/* 0x1f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f7:
	/* 0x1f7: js     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6267ULL;
	}
x86_l_1fd:
	/* 0x1fd: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_202:
	/* 0x202: cmp    rsi,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_205:
	/* 0x205: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_208:
	/* 0x208: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_20b:
	/* 0x20b: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_20f:
	/* 0x20f: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_212:
	/* 0x212: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_216:
	/* 0x216: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_21b:
	/* 0x21b: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_222:
	/* 0x222: ja     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6267ULL;
	}
x86_l_228:
	/* 0x228: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_22c:
	/* 0x22c: mov    QWORD PTR [rsp],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230:
	/* 0x230: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_234:
	/* 0x234: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_239:
	/* 0x239: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23e:
	/* 0x23e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_243:
	/* 0x243: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_246:
	/* 0x246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248:
	/* 0x248: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24d:
	/* 0x24d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f:
	/* 0x24f: js     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6267ULL;
	}
x86_l_255:
	/* 0x255: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_258:
	/* 0x258: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: je     a72 <generic_retkprobe_event+0xa72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2674ULL;
	}
x86_l_261:
	/* 0x261: sub    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_264:
	/* 0x264: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_269:
	/* 0x269: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e:
	/* 0x26e: jne    a7e <generic_retkprobe_event+0xa7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2686ULL;
	}
x86_l_274:
	/* 0x274: jmp    340 <generic_retkprobe_event+0x340> */
	goto x86_l_340;
x86_l_279:
	/* 0x279: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c:
	/* 0x27c: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280:
	/* 0x280: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_284:
	/* 0x284: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_289:
	/* 0x289: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_28c:
	/* 0x28c: je     2c4d <generic_retkprobe_event+0x2c4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11341ULL;
	}
x86_l_292:
	/* 0x292: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_295:
	/* 0x295: jne    2c63 <generic_retkprobe_event+0x2c63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11363ULL;
	}
x86_l_29b:
	/* 0x29b: mov    eax,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29e:
	/* 0x29e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,DWORD PTR [rbx+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2a5:
	/* 0x2a5: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2a9:
	/* 0x2a9: mov    rax,QWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ad:
	/* 0x2ad: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b2:
	/* 0x2b2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2b9:
	/* 0x2b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb:
	/* 0x2bb: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2c3:
	/* 0x2c3: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c8:
	/* 0x2c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cd:
	/* 0x2cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf:
	/* 0x2cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1:
	/* 0x2d1: jmp    2c63 <generic_retkprobe_event+0x2c63> */
	return 11363ULL;
x86_l_2d6:
	/* 0x2d6: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e2:
	/* 0x2e2: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2eb:
	/* 0x2eb: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_2ef:
	/* 0x2ef: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rsp+0xb8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_300:
	/* 0x300: jle    355 <generic_retkprobe_event+0x355> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_355;
	}
x86_l_302:
	/* 0x302: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_306:
	/* 0x306: je     370 <generic_retkprobe_event+0x370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_370;
	}
x86_l_308:
	/* 0x308: cmp    r14d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 37ULL);
x86_l_30c:
	/* 0x30c: je     3ae <generic_retkprobe_event+0x3ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ae;
	}
x86_l_312:
	/* 0x312: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_316:
	/* 0x316: jne    8aa <generic_retkprobe_event+0x8aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2218ULL;
	}
x86_l_31c:
	/* 0x31c: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_328:
	/* 0x328: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_330:
	/* 0x330: lea    r12,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_338:
	/* 0x338: jmp    3db <generic_retkprobe_event+0x3db> */
	goto x86_l_3db;
x86_l_33d:
	/* 0x33d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340:
	/* 0x340: mov    DWORD PTR [r15+r14*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_344:
	/* 0x344: mov    DWORD PTR [r15+r14*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 4ULL);
x86_l_349:
	/* 0x349: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34d:
	/* 0x34d: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_350:
	/* 0x350: jmp    1884 <generic_retkprobe_event+0x1884> */
	return 6276ULL;
x86_l_355:
	/* 0x355: cmp    r14d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 15ULL);
x86_l_359:
	/* 0x359: je     7ea <generic_retkprobe_event+0x7ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2026ULL;
	}
x86_l_35f:
	/* 0x35f: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_363:
	/* 0x363: jne    8aa <generic_retkprobe_event+0x8aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2218ULL;
	}
x86_l_369:
	/* 0x369: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36e:
	/* 0x36e: jmp    398 <generic_retkprobe_event+0x398> */
	goto x86_l_398;
x86_l_370:
	/* 0x370: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_375:
	/* 0x375: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37a:
	/* 0x37a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37f:
	/* 0x37f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_384:
	/* 0x384: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_387:
	/* 0x387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38c:
	/* 0x38c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e:
	/* 0x38e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_398:
	/* 0x398: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39d:
	/* 0x39d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a2:
	/* 0x3a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a7:
	/* 0x3a7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ac:
	/* 0x3ac: jmp    3cb <generic_retkprobe_event+0x3cb> */
	goto x86_l_3cb;
x86_l_3ae:
	/* 0x3ae: add    rbp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3b2:
	/* 0x3b2: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b7:
	/* 0x3b7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bc:
	/* 0x3bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c1:
	/* 0x3c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c6:
	/* 0x3c6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3cb:
	/* 0x3cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d0:
	/* 0x3d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2:
	/* 0x3d2: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d7:
	/* 0x3d7: add    r12,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3db:
	/* 0x3db: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_3e6:
	/* 0x3e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_3ed:
	/* 0x3ed: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_3f5:
	/* 0x3f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fa:
	/* 0x3fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc:
	/* 0x3fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ff:
	/* 0x3ff: je     4b4 <generic_retkprobe_event+0x4b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b4;
	}
x86_l_405:
	/* 0x405: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_408:
	/* 0x408: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_40e:
	/* 0x40e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_413:
	/* 0x413: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_418:
	/* 0x418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a:
	/* 0x41a: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_421:
	/* 0x421: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_429:
	/* 0x429: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_42e:
	/* 0x42e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_433:
	/* 0x433: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_438:
	/* 0x438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43a:
	/* 0x43a: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rsp+0xf0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_44a:
	/* 0x44a: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44f:
	/* 0x44f: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_457:
	/* 0x457: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45c:
	/* 0x45c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_461:
	/* 0x461: lea    rcx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_465:
	/* 0x465: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_46d:
	/* 0x46d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_472:
	/* 0x472: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_47a:
	/* 0x47a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c:
	/* 0x47c: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_484:
	/* 0x484: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_489:
	/* 0x489: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48e:
	/* 0x48e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_493:
	/* 0x493: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_498:
	/* 0x498: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d:
	/* 0x49d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f:
	/* 0x49f: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4a5:
	/* 0x4a5: mov    r14d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4096ULL);
x86_l_4ab:
	/* 0x4ab: je     4c1 <generic_retkprobe_event+0x4c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1;
	}
x86_l_4ad:
	/* 0x4ad: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b2:
	/* 0x4b2: jmp    513 <generic_retkprobe_event+0x513> */
	goto x86_l_513;
x86_l_4b4:
	/* 0x4b4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b7:
	/* 0x4b7: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4bc:
	/* 0x4bc: jmp    a69 <generic_retkprobe_event+0xa69> */
	return 2665ULL;
x86_l_4c1:
	/* 0x4c1: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c6:
	/* 0x4c6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cb:
	/* 0x4cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d0:
	/* 0x4d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d5:
	/* 0x4d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4da:
	/* 0x4da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc:
	/* 0x4dc: cmp    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4e1:
	/* 0x4e1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e6:
	/* 0x4e6: je     513 <generic_retkprobe_event+0x513> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_513;
	}
x86_l_4e8:
	/* 0x4e8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_4f2:
	/* 0x4f2: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_4fc:
	/* 0x4fc: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_503:
	/* 0x503: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_50d:
	/* 0x50d: mov    r14d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4086ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_518:
	/* 0x518: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_521:
	/* 0x521: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_52f:
	/* 0x52f: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_538:
	/* 0x538: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_541:
	/* 0x541: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_54a:
	/* 0x54a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f:
	/* 0x54f: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_554:
	/* 0x554: mov    DWORD PTR [rsp+0x68],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_559:
	/* 0x559: mov    BYTE PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_55e:
	/* 0x55e: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_562:
	/* 0x562: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_567:
	/* 0x567: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_56c:
	/* 0x56c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_571:
	/* 0x571: lea    r14,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_576:
	/* 0x576: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_57b:
	/* 0x57b: lea    r13,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_580:
	/* 0x580: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_585:
	/* 0x585: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_588:
	/* 0x588: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58a:
	/* 0x58a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_58f:
	/* 0x58f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_594:
	/* 0x594: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_59c:
	/* 0x59c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_59f:
	/* 0x59f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a4:
	/* 0x5a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a6:
	/* 0x5a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ab:
	/* 0x5ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b0:
	/* 0x5b0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b8:
	/* 0x5b8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c0:
	/* 0x5c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2:
	/* 0x5c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c7:
	/* 0x5c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5cc:
	/* 0x5cc: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_5d4:
	/* 0x5d4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dc:
	/* 0x5dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de:
	/* 0x5de: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e3:
	/* 0x5e3: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ec:
	/* 0x5ec: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5f3:
	/* 0x5f3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f6:
	/* 0x5f6: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5fb:
	/* 0x5fb: je     7c4 <generic_retkprobe_event+0x7c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1988ULL;
	}
x86_l_601:
	/* 0x601: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_606:
	/* 0x606: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_60c:
	/* 0x60c: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_611:
	/* 0x611: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_616:
	/* 0x616: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_61b:
	/* 0x61b: cmp    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_620:
	/* 0x620: jne    62d <generic_retkprobe_event+0x62d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_62d;
	}
x86_l_622:
	/* 0x622: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_627:
	/* 0x627: je     956 <generic_retkprobe_event+0x956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2390ULL;
	}
x86_l_62d:
	/* 0x62d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_632:
	/* 0x632: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_63a:
	/* 0x63a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63f:
	/* 0x63f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_641:
	/* 0x641: cmp    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 176ULL);
x86_l_649:
	/* 0x649: je     757 <generic_retkprobe_event+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1879ULL;
	}
x86_l_64f:
	/* 0x64f: lea    r14,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_654:
	/* 0x654: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_659:
	/* 0x659: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65e:
	/* 0x65e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_663:
	/* 0x663: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_666:
	/* 0x666: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_668:
	/* 0x668: cmp    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66d:
	/* 0x66d: je     757 <generic_retkprobe_event+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1879ULL;
	}
x86_l_673:
	/* 0x673: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_678:
	/* 0x678: lea    rdi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_680:
	/* 0x680: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_685:
	/* 0x685: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_68e:
	/* 0x68e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_693:
	/* 0x693: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_698:
	/* 0x698: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_69d:
	/* 0x69d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6a2:
	/* 0x6a2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6a5:
	/* 0x6a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a7:
	/* 0x6a7: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6ac:
	/* 0x6ac: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b1:
	/* 0x6b1: mov    r12d,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_6b6:
	/* 0x6b6: sub    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6b9:
	/* 0x6b9: mov    r13d,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6be:
	/* 0x6be: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_6c1:
	/* 0x6c1: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6c4:
	/* 0x6c4: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_6c9:
	/* 0x6c9: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_6cc:
	/* 0x6cc: add    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_6d1:
	/* 0x6d1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d3:
	/* 0x6d3: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_6d6:
	/* 0x6d6: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_6da:
	/* 0x6da: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6dd:
	/* 0x6dd: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_6e1:
	/* 0x6e1: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6e3:
	/* 0x6e3: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6e8:
	/* 0x6e8: mov    DWORD PTR [rsp+0x68],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6ec:
	/* 0x6ec: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6ef:
	/* 0x6ef: jb     95b <generic_retkprobe_event+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2395ULL;
	}
x86_l_6f5:
	/* 0x6f5: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_6fb:
	/* 0x6fb: ja     95b <generic_retkprobe_event+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2395ULL;
	}
x86_l_701:
	/* 0x701: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_704:
	/* 0x704: jbe    70b <generic_retkprobe_event+0x70b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_70b;
	}
x86_l_706:
	/* 0x706: mov    BYTE PTR [r14+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_70b:
	/* 0x70b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70d:
	/* 0x70d: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_710:
	/* 0x710: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_714:
	/* 0x714: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_717:
	/* 0x717: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_71a:
	/* 0x71a: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_71d:
	/* 0x71d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_722:
	/* 0x722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_724:
	/* 0x724: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_729:
	/* 0x729: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_72c:
	/* 0x72c: jbe    95b <generic_retkprobe_event+0x95b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2395ULL;
	}
	return 1842ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1842ULL: goto x86_l_732;
	case 1850ULL: goto x86_l_73a;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1866ULL: goto x86_l_74a;
	case 1868ULL: goto x86_l_74c;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1949ULL: goto x86_l_79d;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1983ULL: goto x86_l_7bf;
	case 1988ULL: goto x86_l_7c4;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2051ULL: goto x86_l_803;
	case 2056ULL: goto x86_l_808;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2066ULL: goto x86_l_812;
	case 2072ULL: goto x86_l_818;
	case 2083ULL: goto x86_l_823;
	case 2090ULL: goto x86_l_82a;
	case 2098ULL: goto x86_l_832;
	case 2103ULL: goto x86_l_837;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2117ULL: goto x86_l_845;
	case 2121ULL: goto x86_l_849;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2136ULL: goto x86_l_858;
	case 2140ULL: goto x86_l_85c;
	case 2145ULL: goto x86_l_861;
	case 2151ULL: goto x86_l_867;
	case 2155ULL: goto x86_l_86b;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2171ULL: goto x86_l_87b;
	case 2175ULL: goto x86_l_87f;
	case 2181ULL: goto x86_l_885;
	case 2185ULL: goto x86_l_889;
	case 2191ULL: goto x86_l_88f;
	case 2201ULL: goto x86_l_899;
	case 2207ULL: goto x86_l_89f;
	case 2213ULL: goto x86_l_8a5;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2233ULL: goto x86_l_8b9;
	case 2236ULL: goto x86_l_8bc;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2272ULL: goto x86_l_8e0;
	case 2279ULL: goto x86_l_8e7;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2300ULL: goto x86_l_8fc;
	case 2306ULL: goto x86_l_902;
	case 2310ULL: goto x86_l_906;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2346ULL: goto x86_l_92a;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2359ULL: goto x86_l_937;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2380ULL: goto x86_l_94c;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2435ULL: goto x86_l_983;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2446ULL: goto x86_l_98e;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2476ULL: goto x86_l_9ac;
	case 2478ULL: goto x86_l_9ae;
	case 2481ULL: goto x86_l_9b1;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2497ULL: goto x86_l_9c1;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2625ULL: goto x86_l_a41;
	case 2627ULL: goto x86_l_a43;
	case 2631ULL: goto x86_l_a47;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2653ULL: goto x86_l_a5d;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2665ULL: goto x86_l_a69;
	case 2669ULL: goto x86_l_a6d;
	case 2674ULL: goto x86_l_a72;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2695ULL: goto x86_l_a87;
	case 2697ULL: goto x86_l_a89;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2745ULL: goto x86_l_ab9;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2758ULL: goto x86_l_ac6;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2771ULL: goto x86_l_ad3;
	case 2774ULL: goto x86_l_ad6;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2797ULL: goto x86_l_aed;
	case 2803ULL: goto x86_l_af3;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2841ULL: goto x86_l_b19;
	case 2849ULL: goto x86_l_b21;
	case 2851ULL: goto x86_l_b23;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2866ULL: goto x86_l_b32;
	case 2872ULL: goto x86_l_b38;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2883ULL: goto x86_l_b43;
	case 2889ULL: goto x86_l_b49;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2946ULL: goto x86_l_b82;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2962ULL: goto x86_l_b92;
	case 2966ULL: goto x86_l_b96;
	case 2972ULL: goto x86_l_b9c;
	case 2976ULL: goto x86_l_ba0;
	case 2982ULL: goto x86_l_ba6;
	case 2985ULL: goto x86_l_ba9;
	case 2990ULL: goto x86_l_bae;
	case 2997ULL: goto x86_l_bb5;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3029ULL: goto x86_l_bd5;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3065ULL: goto x86_l_bf9;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3090ULL: goto x86_l_c12;
	case 3097ULL: goto x86_l_c19;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3122ULL: goto x86_l_c32;
	case 3129ULL: goto x86_l_c39;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3161ULL: goto x86_l_c59;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3198ULL: goto x86_l_c7e;
	case 3205ULL: goto x86_l_c85;
	case 3213ULL: goto x86_l_c8d;
	case 3221ULL: goto x86_l_c95;
	case 3229ULL: goto x86_l_c9d;
	case 3237ULL: goto x86_l_ca5;
	case 3240ULL: goto x86_l_ca8;
	case 3246ULL: goto x86_l_cae;
	case 3249ULL: goto x86_l_cb1;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3295ULL: goto x86_l_cdf;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3307ULL: goto x86_l_ceb;
	case 3313ULL: goto x86_l_cf1;
	case 3317ULL: goto x86_l_cf5;
	case 3323ULL: goto x86_l_cfb;
	case 3327ULL: goto x86_l_cff;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3341ULL: goto x86_l_d0d;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3369ULL: goto x86_l_d29;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3382ULL: goto x86_l_d36;
	case 3386ULL: goto x86_l_d3a;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3471ULL: goto x86_l_d8f;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3506ULL: goto x86_l_db2;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3519ULL: goto x86_l_dbf;
	case 3525ULL: goto x86_l_dc5;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3545ULL: goto x86_l_dd9;
	case 3549ULL: goto x86_l_ddd;
	case 3555ULL: goto x86_l_de3;
	case 3559ULL: goto x86_l_de7;
	case 3565ULL: goto x86_l_ded;
	case 3569ULL: goto x86_l_df1;
	case 3573ULL: goto x86_l_df5;
	case 3579ULL: goto x86_l_dfb;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3600ULL: goto x86_l_e10;
	case 3608ULL: goto x86_l_e18;
	case 3616ULL: goto x86_l_e20;
	case 3624ULL: goto x86_l_e28;
	case 3632ULL: goto x86_l_e30;
	case 3640ULL: goto x86_l_e38;
	case 3648ULL: goto x86_l_e40;
	case 3656ULL: goto x86_l_e48;
	case 3664ULL: goto x86_l_e50;
	case 3672ULL: goto x86_l_e58;
	case 3680ULL: goto x86_l_e60;
	case 3688ULL: goto x86_l_e68;
	case 3696ULL: goto x86_l_e70;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_732:
	/* 0x732: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_73a:
	/* 0x73a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_73f:
	/* 0x73f: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_744:
	/* 0x744: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_74a:
	/* 0x74a: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_74c:
	/* 0x74c: jne    60c <generic_retkprobe_event+0x60c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1548ULL;
	}
x86_l_752:
	/* 0x752: jmp    966 <generic_retkprobe_event+0x966> */
	goto x86_l_966;
x86_l_757:
	/* 0x757: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75b:
	/* 0x75b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_760:
	/* 0x760: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_765:
	/* 0x765: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_771:
	/* 0x771: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_776:
	/* 0x776: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_77c:
	/* 0x77c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_781:
	/* 0x781: je     b57 <generic_retkprobe_event+0xb57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b57;
	}
x86_l_787:
	/* 0x787: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_78b:
	/* 0x78b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_790:
	/* 0x790: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_795:
	/* 0x795: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_79a:
	/* 0x79a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_79d:
	/* 0x79d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79f:
	/* 0x79f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a4:
	/* 0x7a4: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7a9:
	/* 0x7a9: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7ad:
	/* 0x7ad: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b2:
	/* 0x7b2: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7b7:
	/* 0x7b7: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_7b9:
	/* 0x7b9: jne    60c <generic_retkprobe_event+0x60c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1548ULL;
	}
x86_l_7bf:
	/* 0x7bf: jmp    966 <generic_retkprobe_event+0x966> */
	goto x86_l_966;
x86_l_7c4:
	/* 0x7c4: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_7cb:
	/* 0x7cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7cd:
	/* 0x7cd: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d2:
	/* 0x7d2: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_7d7:
	/* 0x7d7: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_7dc:
	/* 0x7dc: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_7e1:
	/* 0x7e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e3:
	/* 0x7e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e5:
	/* 0x7e5: jmp    960 <generic_retkprobe_event+0x960> */
	goto x86_l_960;
x86_l_7ea:
	/* 0x7ea: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ef:
	/* 0x7ef: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7f4:
	/* 0x7f4: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f9:
	/* 0x7f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7fe:
	/* 0x7fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_803:
	/* 0x803: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_808:
	/* 0x808: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80a:
	/* 0x80a: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_80f:
	/* 0x80f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_812:
	/* 0x812: jne    3db <generic_retkprobe_event+0x3db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 987ULL;
	}
x86_l_818:
	/* 0x818: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_823:
	/* 0x823: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_82a:
	/* 0x82a: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_832:
	/* 0x832: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_837:
	/* 0x837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_839:
	/* 0x839: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_83c:
	/* 0x83c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: je     2bf7 <generic_retkprobe_event+0x2bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11255ULL;
	}
x86_l_845:
	/* 0x845: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_849:
	/* 0x849: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84d:
	/* 0x84d: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_852:
	/* 0x852: jg     da3 <generic_retkprobe_event+0xda3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_da3;
	}
x86_l_858:
	/* 0x858: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_85c:
	/* 0x85c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_861:
	/* 0x861: jle    efe <generic_retkprobe_event+0xefe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3838ULL;
	}
x86_l_867:
	/* 0x867: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_86b:
	/* 0x86b: jle    120a <generic_retkprobe_event+0x120a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4618ULL;
	}
x86_l_871:
	/* 0x871: cmp    r14d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 21ULL);
x86_l_875:
	/* 0x875: je     1c3b <generic_retkprobe_event+0x1c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7227ULL;
	}
x86_l_87b:
	/* 0x87b: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_87f:
	/* 0x87f: je     1ba8 <generic_retkprobe_event+0x1ba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7080ULL;
	}
x86_l_885:
	/* 0x885: cmp    r14d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 23ULL);
x86_l_889:
	/* 0x889: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_88f:
	/* 0x88f: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_899:
	/* 0x899: mov    DWORD PTR [rcx+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_89f:
	/* 0x89f: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_8a5:
	/* 0x8a5: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_8aa:
	/* 0x8aa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8af:
	/* 0x8af: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_8b3:
	/* 0x8b3: ja     818 <generic_retkprobe_event+0x818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_818;
	}
x86_l_8b9:
	/* 0x8b9: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_8bc:
	/* 0x8bc: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_8c6:
	/* 0x8c6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8ca:
	/* 0x8ca: jae    818 <generic_retkprobe_event+0x818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_818;
	}
x86_l_8d0:
	/* 0x8d0: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8d5:
	/* 0x8d5: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_8e7:
	/* 0x8e7: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_8ef:
	/* 0x8ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f4:
	/* 0x8f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f6:
	/* 0x8f6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f9:
	/* 0x8f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8fc:
	/* 0x8fc: je     2bf7 <generic_retkprobe_event+0x2bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11255ULL;
	}
x86_l_902:
	/* 0x902: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_906:
	/* 0x906: jle    b66 <generic_retkprobe_event+0xb66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b66;
	}
x86_l_90c:
	/* 0x90c: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_910:
	/* 0x910: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_915:
	/* 0x915: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_91a:
	/* 0x91a: jle    ce7 <generic_retkprobe_event+0xce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ce7;
	}
x86_l_920:
	/* 0x920: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_924:
	/* 0x924: jg     dd9 <generic_retkprobe_event+0xdd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dd9;
	}
x86_l_92a:
	/* 0x92a: lea    eax,[r14-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_92e:
	/* 0x92e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_931:
	/* 0x931: jae    12ef <generic_retkprobe_event+0x12ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4847ULL;
	}
x86_l_937:
	/* 0x937: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_93c:
	/* 0x93c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_942:
	/* 0x942: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_947:
	/* 0x947: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_94c:
	/* 0x94c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_951:
	/* 0x951: jmp    11ff <generic_retkprobe_event+0x11ff> */
	return 4607ULL;
x86_l_956:
	/* 0x956: mov    BYTE PTR [rsp+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_95b:
	/* 0x95b: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_960:
	/* 0x960: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_966:
	/* 0x966: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_96b:
	/* 0x96b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_970:
	/* 0x970: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_972:
	/* 0x972: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_975:
	/* 0x975: je     9ae <generic_retkprobe_event+0x9ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ae;
	}
x86_l_977:
	/* 0x977: cmp    BYTE PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_97c:
	/* 0x97c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_97f:
	/* 0x97f: mov    edx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_983:
	/* 0x983: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_989:
	/* 0x989: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_98c:
	/* 0x98c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_98e:
	/* 0x98e: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_992:
	/* 0x992: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_999:
	/* 0x999: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_99e:
	/* 0x99e: je     a66 <generic_retkprobe_event+0xa66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a66;
	}
x86_l_9a4:
	/* 0x9a4: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_9a7:
	/* 0x9a7: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9a9:
	/* 0x9a9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9ac:
	/* 0x9ac: jmp    9ba <generic_retkprobe_event+0x9ba> */
	goto x86_l_9ba;
x86_l_9ae:
	/* 0x9ae: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b1:
	/* 0x9b1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b5:
	/* 0x9b5: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ba:
	/* 0x9ba: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_9c1:
	/* 0x9c1: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_9c8:
	/* 0x9c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9cd:
	/* 0x9cd: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_9d0:
	/* 0x9d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d2:
	/* 0x9d2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d6:
	/* 0x9d6: mov    DWORD PTR [rax+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_9dd:
	/* 0x9dd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e2:
	/* 0x9e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e7:
	/* 0x9e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9f4:
	/* 0x9f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f9:
	/* 0x9f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fb:
	/* 0x9fb: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a00:
	/* 0xa00: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a04:
	/* 0xa04: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a09:
	/* 0xa09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_a0e:
	/* 0xa0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a13:
	/* 0xa13: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a18:
	/* 0xa18: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_a1c:
	/* 0xa1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a21:
	/* 0xa21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a23:
	/* 0xa23: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a28:
	/* 0xa28: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a2d:
	/* 0xa2d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_a32:
	/* 0xa32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a37:
	/* 0xa37: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a3c:
	/* 0xa3c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_a41:
	/* 0xa41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a43:
	/* 0xa43: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a47:
	/* 0xa47: mov    DWORD PTR [rcx+r13*1+0xa0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 160ULL);
x86_l_a4f:
	/* 0xa4f: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_a54:
	/* 0xa54: mov    WORD PTR [rcx+r13*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 164ULL);
x86_l_a5d:
	/* 0xa5d: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_a61:
	/* 0xa61: jmp    2c06 <generic_retkprobe_event+0x2c06> */
	return 11270ULL;
x86_l_a66:
	/* 0xa66: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a69:
	/* 0xa69: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6d:
	/* 0xa6d: jmp    2c0f <generic_retkprobe_event+0x2c0f> */
	return 11279ULL;
x86_l_a72:
	/* 0xa72: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a74:
	/* 0xa74: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a79:
	/* 0xa79: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7e:
	/* 0xa7e: cmp    QWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_a87:
	/* 0xa87: jne    a91 <generic_retkprobe_event+0xa91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a91;
	}
x86_l_a89:
	/* 0xa89: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_a8c:
	/* 0xa8c: jmp    340 <generic_retkprobe_event+0x340> */
	return 832ULL;
x86_l_a91:
	/* 0xa91: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a99:
	/* 0xa99: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9d:
	/* 0xa9d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa2:
	/* 0xaa2: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_aa8:
	/* 0xaa8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aad:
	/* 0xaad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ab2:
	/* 0xab2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ab7:
	/* 0xab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab9:
	/* 0xab9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_abe:
	/* 0xabe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ac0:
	/* 0xac0: js     1880 <generic_retkprobe_event+0x1880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6272ULL;
	}
x86_l_ac6:
	/* 0xac6: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_acb:
	/* 0xacb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad0:
	/* 0xad0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ad3:
	/* 0xad3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ad6:
	/* 0xad6: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_ada:
	/* 0xada: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_ae1:
	/* 0xae1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_ae6:
	/* 0xae6: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_aed:
	/* 0xaed: ja     1880 <generic_retkprobe_event+0x1880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6272ULL;
	}
x86_l_af3:
	/* 0xaf3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af7:
	/* 0xaf7: add    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_afa:
	/* 0xafa: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afe:
	/* 0xafe: lea    rdi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b02:
	/* 0xb02: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b07:
	/* 0xb07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b0c:
	/* 0xb0c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b11:
	/* 0xb11: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b19:
	/* 0xb19: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b21:
	/* 0xb21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b23:
	/* 0xb23: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b2b:
	/* 0xb2b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_b30:
	/* 0xb30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b32:
	/* 0xb32: js     1880 <generic_retkprobe_event+0x1880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6272ULL;
	}
x86_l_b38:
	/* 0xb38: add    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b3b:
	/* 0xb3b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b40:
	/* 0xb40: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: je     17a4 <generic_retkprobe_event+0x17a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6052ULL;
	}
x86_l_b49:
	/* 0xb49: sub    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b4c:
	/* 0xb4c: jne    17a7 <generic_retkprobe_event+0x17a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6055ULL;
	}
x86_l_b52:
	/* 0xb52: jmp    189c <generic_retkprobe_event+0x189c> */
	return 6300ULL;
x86_l_b57:
	/* 0xb57: mov    BYTE PTR [rsp+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_b5c:
	/* 0xb5c: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b61:
	/* 0xb61: jmp    966 <generic_retkprobe_event+0x966> */
	goto x86_l_966;
x86_l_b66:
	/* 0xb66: cmp    r14d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 9ULL);
x86_l_b6a:
	/* 0xb6a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b74:
	/* 0xb74: jg     d18 <generic_retkprobe_event+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d18;
	}
x86_l_b7a:
	/* 0xb7a: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_b7e:
	/* 0xb7e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b82:
	/* 0xb82: jle    f51 <generic_retkprobe_event+0xf51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3921ULL;
	}
x86_l_b88:
	/* 0xb88: cmp    r14d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 5ULL);
x86_l_b8c:
	/* 0xb8c: je     14f7 <generic_retkprobe_event+0x14f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5367ULL;
	}
x86_l_b92:
	/* 0xb92: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_b96:
	/* 0xb96: je     d80 <generic_retkprobe_event+0xd80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d80;
	}
x86_l_b9c:
	/* 0xb9c: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_ba0:
	/* 0xba0: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_ba6:
	/* 0xba6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ba9:
	/* 0xba9: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bae:
	/* 0xbae: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_bb5:
	/* 0xbb5: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_bbc:
	/* 0xbbc: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bc1:
	/* 0xbc1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bc6:
	/* 0xbc6: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_bc9:
	/* 0xbc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bce:
	/* 0xbce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_bd3:
	/* 0xbd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd5:
	/* 0xbd5: lea    rdi,[r14+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_bdc:
	/* 0xbdc: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_be1:
	/* 0xbe1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_be6:
	/* 0xbe6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_beb:
	/* 0xbeb: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_bf9:
	/* 0xbf9: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c01:
	/* 0xc01: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c06:
	/* 0xc06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c0b:
	/* 0xc0b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c10:
	/* 0xc10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c12:
	/* 0xc12: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c19:
	/* 0xc19: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c21:
	/* 0xc21: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c26:
	/* 0xc26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c2b:
	/* 0xc2b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c30:
	/* 0xc30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c32:
	/* 0xc32: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_c39:
	/* 0xc39: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c41:
	/* 0xc41: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c46:
	/* 0xc46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c4b:
	/* 0xc4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c50:
	/* 0xc50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c52:
	/* 0xc52: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c59:
	/* 0xc59: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c61:
	/* 0xc61: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c66:
	/* 0xc66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c6b:
	/* 0xc6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c70:
	/* 0xc70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c72:
	/* 0xc72: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c77:
	/* 0xc77: lea    r13,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_c7e:
	/* 0xc7e: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c85:
	/* 0xc85: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c8d:
	/* 0xc8d: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c95:
	/* 0xc95: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c9d:
	/* 0xc9d: movzx  eax,WORD PTR [r14+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_ca5:
	/* 0xca5: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_ca8:
	/* 0xca8: je     1faf <generic_retkprobe_event+0x1faf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8111ULL;
	}
x86_l_cae:
	/* 0xcae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cb1:
	/* 0xcb1: jne    1fde <generic_retkprobe_event+0x1fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8158ULL;
	}
x86_l_cb7:
	/* 0xcb7: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cbc:
	/* 0xcbc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cc1:
	/* 0xcc1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cc6:
	/* 0xcc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ccb:
	/* 0xccb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ccd:
	/* 0xccd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cd2:
	/* 0xcd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd7:
	/* 0xcd7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_cda:
	/* 0xcda: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cdf:
	/* 0xcdf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ce2:
	/* 0xce2: jmp    1fdc <generic_retkprobe_event+0x1fdc> */
	return 8156ULL;
x86_l_ce7:
	/* 0xce7: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_ceb:
	/* 0xceb: jg     f32 <generic_retkprobe_event+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3890ULL;
	}
x86_l_cf1:
	/* 0xcf1: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_cf5:
	/* 0xcf5: je     132c <generic_retkprobe_event+0x132c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4908ULL;
	}
x86_l_cfb:
	/* 0xcfb: cmp    r14d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 25ULL);
x86_l_cff:
	/* 0xcff: je     13fe <generic_retkprobe_event+0x13fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5118ULL;
	}
x86_l_d05:
	/* 0xd05: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_d09:
	/* 0xd09: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0d:
	/* 0xd0d: je     f61 <generic_retkprobe_event+0xf61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3937ULL;
	}
x86_l_d13:
	/* 0xd13: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_d18:
	/* 0xd18: lea    eax,[r14-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_d1c:
	/* 0xd1c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d1f:
	/* 0xd1f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d23:
	/* 0xd23: jb     f61 <generic_retkprobe_event+0xf61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3937ULL;
	}
x86_l_d29:
	/* 0xd29: lea    eax,[r14-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_d2d:
	/* 0xd2d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d30:
	/* 0xd30: jb     f80 <generic_retkprobe_event+0xf80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3968ULL;
	}
x86_l_d36:
	/* 0xd36: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_d3a:
	/* 0xd3a: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_d40:
	/* 0xd40: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d45:
	/* 0xd45: lea    r14,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d4a:
	/* 0xd4a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d4f:
	/* 0xd4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d54:
	/* 0xd54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d59:
	/* 0xd59: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_d5c:
	/* 0xd5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5e:
	/* 0xd5e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d63:
	/* 0xd63: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d68:
	/* 0xd68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d6d:
	/* 0xd6d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d72:
	/* 0xd72: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_d75:
	/* 0xd75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7a:
	/* 0xd7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7c:
	/* 0xd7c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d80:
	/* 0xd80: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d85:
	/* 0xd85: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_d8f:
	/* 0xd8f: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_d94:
	/* 0xd94: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_d99:
	/* 0xd99: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_d9e:
	/* 0xd9e: jmp    16e2 <generic_retkprobe_event+0x16e2> */
	return 5858ULL;
x86_l_da3:
	/* 0xda3: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_da7:
	/* 0xda7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dac:
	/* 0xdac: jle    111f <generic_retkprobe_event+0x111f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4383ULL;
	}
x86_l_db2:
	/* 0xdb2: lea    edx,[r14-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_db6:
	/* 0xdb6: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_db9:
	/* 0xdb9: jae    f9f <generic_retkprobe_event+0xf9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3999ULL;
	}
x86_l_dbf:
	/* 0xdbf: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_dc5:
	/* 0xdc5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dca:
	/* 0xdca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dcf:
	/* 0xdcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dd4:
	/* 0xdd4: jmp    11fc <generic_retkprobe_event+0x11fc> */
	return 4604ULL;
x86_l_dd9:
	/* 0xdd9: cmp    r14d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 39ULL);
x86_l_ddd:
	/* 0xddd: je     16be <generic_retkprobe_event+0x16be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5822ULL;
	}
x86_l_de3:
	/* 0xde3: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_de7:
	/* 0xde7: je     1704 <generic_retkprobe_event+0x1704> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5892ULL;
	}
x86_l_ded:
	/* 0xded: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_df1:
	/* 0xdf1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df5:
	/* 0xdf5: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_dfb:
	/* 0xdfb: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_dfe:
	/* 0xdfe: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e03:
	/* 0xe03: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e08:
	/* 0xe08: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e10:
	/* 0xe10: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e18:
	/* 0xe18: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e28:
	/* 0xe28: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e30:
	/* 0xe30: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_e38:
	/* 0xe38: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_e40:
	/* 0xe40: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e50:
	/* 0xe50: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e58:
	/* 0xe58: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_e60:
	/* 0xe60: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e68:
	/* 0xe68: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e70:
	/* 0xe70: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e77:
	/* 0xe77: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e7c:
	/* 0xe7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e81:
	/* 0xe81: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e86:
	/* 0xe86: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e89:
	/* 0xe89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8b:
	/* 0xe8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: js     2200 <generic_retkprobe_event+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8704ULL;
	}
	return 3732ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3760ULL: goto x86_l_eb0;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3778ULL: goto x86_l_ec2;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3797ULL: goto x86_l_ed5;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3821ULL: goto x86_l_eed;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3848ULL: goto x86_l_f08;
	case 3852ULL: goto x86_l_f0c;
	case 3858ULL: goto x86_l_f12;
	case 3862ULL: goto x86_l_f16;
	case 3868ULL: goto x86_l_f1c;
	case 3879ULL: goto x86_l_f27;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3906ULL: goto x86_l_f42;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3925ULL: goto x86_l_f55;
	case 3927ULL: goto x86_l_f57;
	case 3931ULL: goto x86_l_f5b;
	case 3937ULL: goto x86_l_f61;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4003ULL: goto x86_l_fa3;
	case 4009ULL: goto x86_l_fa9;
	case 4013ULL: goto x86_l_fad;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4030ULL: goto x86_l_fbe;
	case 4034ULL: goto x86_l_fc2;
	case 4039ULL: goto x86_l_fc7;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4073ULL: goto x86_l_fe9;
	case 4079ULL: goto x86_l_fef;
	case 4083ULL: goto x86_l_ff3;
	case 4090ULL: goto x86_l_ffa;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4107ULL: goto x86_l_100b;
	case 4112ULL: goto x86_l_1010;
	case 4117ULL: goto x86_l_1015;
	case 4119ULL: goto x86_l_1017;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4155ULL: goto x86_l_103b;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4180ULL: goto x86_l_1054;
	case 4187ULL: goto x86_l_105b;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4212ULL: goto x86_l_1074;
	case 4219ULL: goto x86_l_107b;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4239ULL: goto x86_l_108f;
	case 4246ULL: goto x86_l_1096;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4266ULL: goto x86_l_10aa;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4283ULL: goto x86_l_10bb;
	case 4291ULL: goto x86_l_10c3;
	case 4299ULL: goto x86_l_10cb;
	case 4307ULL: goto x86_l_10d3;
	case 4314ULL: goto x86_l_10da;
	case 4317ULL: goto x86_l_10dd;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4350ULL: goto x86_l_10fe;
	case 4355ULL: goto x86_l_1103;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4383ULL: goto x86_l_111f;
	case 4387ULL: goto x86_l_1123;
	case 4393ULL: goto x86_l_1129;
	case 4397ULL: goto x86_l_112d;
	case 4403ULL: goto x86_l_1133;
	case 4411ULL: goto x86_l_113b;
	case 4419ULL: goto x86_l_1143;
	case 4427ULL: goto x86_l_114b;
	case 4435ULL: goto x86_l_1153;
	case 4443ULL: goto x86_l_115b;
	case 4451ULL: goto x86_l_1163;
	case 4459ULL: goto x86_l_116b;
	case 4467ULL: goto x86_l_1173;
	case 4475ULL: goto x86_l_117b;
	case 4482ULL: goto x86_l_1182;
	case 4489ULL: goto x86_l_1189;
	case 4493ULL: goto x86_l_118d;
	case 4498ULL: goto x86_l_1192;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4526ULL: goto x86_l_11ae;
	case 4533ULL: goto x86_l_11b5;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4578ULL: goto x86_l_11e2;
	case 4584ULL: goto x86_l_11e8;
	case 4588ULL: goto x86_l_11ec;
	case 4594ULL: goto x86_l_11f2;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4622ULL: goto x86_l_120e;
	case 4628ULL: goto x86_l_1214;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4647ULL: goto x86_l_1227;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4675ULL: goto x86_l_1243;
	case 4678ULL: goto x86_l_1246;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4697ULL: goto x86_l_1259;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4726ULL: goto x86_l_1276;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4751ULL: goto x86_l_128f;
	case 4754ULL: goto x86_l_1292;
	case 4757ULL: goto x86_l_1295;
	case 4759ULL: goto x86_l_1297;
	case 4763ULL: goto x86_l_129b;
	case 4770ULL: goto x86_l_12a2;
	case 4777ULL: goto x86_l_12a9;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4805ULL: goto x86_l_12c5;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4827ULL: goto x86_l_12db;
	case 4830ULL: goto x86_l_12de;
	case 4832ULL: goto x86_l_12e0;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4851ULL: goto x86_l_12f3;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4886ULL: goto x86_l_1316;
	case 4889ULL: goto x86_l_1319;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4916ULL: goto x86_l_1334;
	case 4925ULL: goto x86_l_133d;
	case 4934ULL: goto x86_l_1346;
	case 4939ULL: goto x86_l_134b;
	case 4941ULL: goto x86_l_134d;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4981ULL: goto x86_l_1375;
	case 4985ULL: goto x86_l_1379;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5013ULL: goto x86_l_1395;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5039ULL: goto x86_l_13af;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5049ULL: goto x86_l_13b9;
	case 5056ULL: goto x86_l_13c0;
	case 5060ULL: goto x86_l_13c4;
	case 5067ULL: goto x86_l_13cb;
	case 5071ULL: goto x86_l_13cf;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5081ULL: goto x86_l_13d9;
	case 5085ULL: goto x86_l_13dd;
	case 5089ULL: goto x86_l_13e1;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5109ULL: goto x86_l_13f5;
	case 5113ULL: goto x86_l_13f9;
	case 5118ULL: goto x86_l_13fe;
	case 5123ULL: goto x86_l_1403;
	case 5126ULL: goto x86_l_1406;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5162ULL: goto x86_l_142a;
	case 5170ULL: goto x86_l_1432;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5181ULL: goto x86_l_143d;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5309ULL: goto x86_l_14bd;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5335ULL: goto x86_l_14d7;
	case 5341ULL: goto x86_l_14dd;
	case 5348ULL: goto x86_l_14e4;
	case 5355ULL: goto x86_l_14eb;
	case 5359ULL: goto x86_l_14ef;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5379ULL: goto x86_l_1503;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5394ULL: goto x86_l_1512;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5413ULL: goto x86_l_1525;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5434ULL: goto x86_l_153a;
	case 5441ULL: goto x86_l_1541;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5465ULL: goto x86_l_1559;
	case 5472ULL: goto x86_l_1560;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5505ULL: goto x86_l_1581;
	case 5512ULL: goto x86_l_1588;
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5527ULL: goto x86_l_1597;
	case 5532ULL: goto x86_l_159c;
	case 5534ULL: goto x86_l_159e;
	case 5541ULL: goto x86_l_15a5;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5566ULL: goto x86_l_15be;
	case 5575ULL: goto x86_l_15c7;
	case 5580ULL: goto x86_l_15cc;
	case 5588ULL: goto x86_l_15d4;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5603ULL: goto x86_l_15e3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e94:
	/* 0xe94: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_e99:
	/* 0xe99: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e9e:
	/* 0xe9e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea3:
	/* 0xea3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea8:
	/* 0xea8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_ead:
	/* 0xead: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_eb0:
	/* 0xeb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb2:
	/* 0xeb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb5:
	/* 0xeb5: js     2200 <generic_retkprobe_event+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8704ULL;
	}
x86_l_ebb:
	/* 0xebb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebf:
	/* 0xebf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ec2:
	/* 0xec2: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_ec9:
	/* 0xec9: cmp    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ece:
	/* 0xece: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_ed5:
	/* 0xed5: je     21d5 <generic_retkprobe_event+0x21d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8661ULL;
	}
x86_l_edb:
	/* 0xedb: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_ee0:
	/* 0xee0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ee5:
	/* 0xee5: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_eea:
	/* 0xeea: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_eed:
	/* 0xeed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eef:
	/* 0xeef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef1:
	/* 0xef1: js     2200 <generic_retkprobe_event+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8704ULL;
	}
x86_l_ef7:
	/* 0xef7: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_ef9:
	/* 0xef9: jmp    21f6 <generic_retkprobe_event+0x21f6> */
	return 8694ULL;
x86_l_efe:
	/* 0xefe: cmp    r14d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 7ULL);
x86_l_f02:
	/* 0xf02: jg     11de <generic_retkprobe_event+0x11de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11de;
	}
x86_l_f08:
	/* 0xf08: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_f0c:
	/* 0xf0c: je     18a9 <generic_retkprobe_event+0x18a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6313ULL;
	}
x86_l_f12:
	/* 0xf12: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_f16:
	/* 0xf16: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_f1c:
	/* 0xf1c: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_f27:
	/* 0xf27: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_f2d:
	/* 0xf2d: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_f32:
	/* 0xf32: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f37:
	/* 0xf37: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f3d:
	/* 0xf3d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f42:
	/* 0xf42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f47:
	/* 0xf47: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f4c:
	/* 0xf4c: jmp    11ff <generic_retkprobe_event+0x11ff> */
	goto x86_l_11ff;
x86_l_f51:
	/* 0xf51: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_f55:
	/* 0xf55: je     f80 <generic_retkprobe_event+0xf80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f80;
	}
x86_l_f57:
	/* 0xf57: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_f5b:
	/* 0xf5b: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_f61:
	/* 0xf61: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_f67:
	/* 0xf67: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f6c:
	/* 0xf6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f71:
	/* 0xf71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f76:
	/* 0xf76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7b:
	/* 0xf7b: jmp    11ff <generic_retkprobe_event+0x11ff> */
	goto x86_l_11ff;
x86_l_f80:
	/* 0xf80: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f85:
	/* 0xf85: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_f8b:
	/* 0xf8b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f90:
	/* 0xf90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f95:
	/* 0xf95: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f9a:
	/* 0xf9a: jmp    11ff <generic_retkprobe_event+0x11ff> */
	goto x86_l_11ff;
x86_l_f9f:
	/* 0xf9f: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_fa3:
	/* 0xfa3: je     1d3c <generic_retkprobe_event+0x1d3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7484ULL;
	}
x86_l_fa9:
	/* 0xfa9: cmp    r14d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 41ULL);
x86_l_fad:
	/* 0xfad: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_fb3:
	/* 0xfb3: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_fb6:
	/* 0xfb6: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fbe:
	/* 0xfbe: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_fc2:
	/* 0xfc2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc7:
	/* 0xfc7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_fcd:
	/* 0xfcd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fd2:
	/* 0xfd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd7:
	/* 0xfd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fdc:
	/* 0xfdc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fdf:
	/* 0xfdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe1:
	/* 0xfe1: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fe6:
	/* 0xfe6: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_fe9:
	/* 0xfe9: je     229c <generic_retkprobe_event+0x229c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8860ULL;
	}
x86_l_fef:
	/* 0xfef: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff3:
	/* 0xff3: mov    QWORD PTR [rbp+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_ffa:
	/* 0xffa: lea    rdi,[rbp+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_1001:
	/* 0x1001: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1006:
	/* 0x1006: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_100b:
	/* 0x100b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1010:
	/* 0x1010: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1015:
	/* 0x1015: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1017:
	/* 0x1017: lea    rdi,[rbp+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_101e:
	/* 0x101e: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1023:
	/* 0x1023: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1028:
	/* 0x1028: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_102d:
	/* 0x102d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1032:
	/* 0x1032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1034:
	/* 0x1034: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_103b:
	/* 0x103b: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1043:
	/* 0x1043: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1048:
	/* 0x1048: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_104d:
	/* 0x104d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1052:
	/* 0x1052: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1054:
	/* 0x1054: lea    rdi,[rbp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_105b:
	/* 0x105b: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1063:
	/* 0x1063: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1068:
	/* 0x1068: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_106d:
	/* 0x106d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1072:
	/* 0x1072: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1074:
	/* 0x1074: lea    rdi,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_107b:
	/* 0x107b: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1083:
	/* 0x1083: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1088:
	/* 0x1088: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_108d:
	/* 0x108d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108f:
	/* 0x108f: lea    rdi,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1096:
	/* 0x1096: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_109e:
	/* 0x109e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10a3:
	/* 0x10a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10a8:
	/* 0x10a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10aa:
	/* 0x10aa: lea    r13,[rbp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_10b1:
	/* 0x10b1: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_10b4:
	/* 0x10b4: mov    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bb:
	/* 0x10bb: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10c3:
	/* 0x10c3: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10cb:
	/* 0x10cb: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10d3:
	/* 0x10d3: movzx  eax,WORD PTR [rbp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_10da:
	/* 0x10da: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10dd:
	/* 0x10dd: je     2212 <generic_retkprobe_event+0x2212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8722ULL;
	}
x86_l_10e3:
	/* 0x10e3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10e6:
	/* 0x10e6: jne    2244 <generic_retkprobe_event+0x2244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8772ULL;
	}
x86_l_10ec:
	/* 0x10ec: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10f1:
	/* 0x10f1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10f6:
	/* 0x10f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10fb:
	/* 0x10fb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_10fe:
	/* 0x10fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1103:
	/* 0x1103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1105:
	/* 0x1105: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_110a:
	/* 0x110a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_110f:
	/* 0x110f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1112:
	/* 0x1112: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1117:
	/* 0x1117: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: jmp    2242 <generic_retkprobe_event+0x2242> */
	return 8770ULL;
x86_l_111f:
	/* 0x111f: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_1123:
	/* 0x1123: je     1de6 <generic_retkprobe_event+0x1de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7654ULL;
	}
x86_l_1129:
	/* 0x1129: cmp    r14d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 27ULL);
x86_l_112d:
	/* 0x112d: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_1133:
	/* 0x1133: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_113b:
	/* 0x113b: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1143:
	/* 0x1143: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_114b:
	/* 0x114b: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1153:
	/* 0x1153: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_115b:
	/* 0x115b: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1163:
	/* 0x1163: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_116b:
	/* 0x116b: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1173:
	/* 0x1173: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_117b:
	/* 0x117b: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1182:
	/* 0x1182: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1189:
	/* 0x1189: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_118d:
	/* 0x118d: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_1192:
	/* 0x1192: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1197:
	/* 0x1197: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_119c:
	/* 0x119c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119e:
	/* 0x119e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a1:
	/* 0x11a1: js     1e5a <generic_retkprobe_event+0x1e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7770ULL;
	}
x86_l_11a7:
	/* 0x11a7: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ab:
	/* 0x11ab: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_11ae:
	/* 0x11ae: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_11b5:
	/* 0x11b5: add    rbp,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_11bc:
	/* 0x11bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11c1:
	/* 0x11c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11c6:
	/* 0x11c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11cb:
	/* 0x11cb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11ce:
	/* 0x11ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d0:
	/* 0x11d0: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_11d3:
	/* 0x11d3: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_11d9:
	/* 0x11d9: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_11de:
	/* 0x11de: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_11e2:
	/* 0x11e2: je     195e <generic_retkprobe_event+0x195e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6494ULL;
	}
x86_l_11e8:
	/* 0x11e8: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_11ec:
	/* 0x11ec: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_11f2:
	/* 0x11f2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f5:
	/* 0x11f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11fa:
	/* 0x11fa: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11fc:
	/* 0x11fc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1201:
	/* 0x1201: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1205:
	/* 0x1205: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_120a:
	/* 0x120a: cmp    r14d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 19ULL);
x86_l_120e:
	/* 0x120e: je     1ce2 <generic_retkprobe_event+0x1ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7394ULL;
	}
x86_l_1214:
	/* 0x1214: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_1218:
	/* 0x1218: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_121e:
	/* 0x121e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1227:
	/* 0x1227: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_122e:
	/* 0x122e: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_1231:
	/* 0x1231: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1236:
	/* 0x1236: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_123b:
	/* 0x123b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1240:
	/* 0x1240: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_1243:
	/* 0x1243: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_1246:
	/* 0x1246: lea    r12,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_124d:
	/* 0x124d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1252:
	/* 0x1252: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1254:
	/* 0x1254: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1259:
	/* 0x1259: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_125e:
	/* 0x125e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1263:
	/* 0x1263: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1268:
	/* 0x1268: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_126b:
	/* 0x126b: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1270:
	/* 0x1270: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1272:
	/* 0x1272: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1276:
	/* 0x1276: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_127d:
	/* 0x127d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1282:
	/* 0x1282: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1287:
	/* 0x1287: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_128c:
	/* 0x128c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_128f:
	/* 0x128f: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_1292:
	/* 0x1292: mov    rbx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_64);
x86_l_1295:
	/* 0x1295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1297:
	/* 0x1297: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129b:
	/* 0x129b: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_12a2:
	/* 0x12a2: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_12a9:
	/* 0x12a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12ae:
	/* 0x12ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b3:
	/* 0x12b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12b8:
	/* 0x12b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ba:
	/* 0x12ba: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12be:
	/* 0x12be: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_12c5:
	/* 0x12c5: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_12cc:
	/* 0x12cc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d1:
	/* 0x12d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12d6:
	/* 0x12d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12db:
	/* 0x12db: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_12de:
	/* 0x12de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e0:
	/* 0x12e0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e4:
	/* 0x12e4: mov    r13d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 152ULL);
x86_l_12ea:
	/* 0x12ea: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_12ef:
	/* 0x12ef: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_12f3:
	/* 0x12f3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f7:
	/* 0x12f7: jne    2c00 <generic_retkprobe_event+0x2c00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11264ULL;
	}
x86_l_12fd:
	/* 0x12fd: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1302:
	/* 0x1302: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1305:
	/* 0x1305: add    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 184ULL);
x86_l_130d:
	/* 0x130d: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1310:
	/* 0x1310: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1316:
	/* 0x1316: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1319:
	/* 0x1319: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1320:
	/* 0x1320: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1322:
	/* 0x1322: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1327:
	/* 0x1327: jmp    16e2 <generic_retkprobe_event+0x16e2> */
	return 5858ULL;
x86_l_132c:
	/* 0x132c: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1331:
	/* 0x1331: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1334:
	/* 0x1334: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_133d:
	/* 0x133d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1346:
	/* 0x1346: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_134b:
	/* 0x134b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134d:
	/* 0x134d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1351:
	/* 0x1351: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1356:
	/* 0x1356: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_135b:
	/* 0x135b: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1360:
	/* 0x1360: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1365:
	/* 0x1365: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_136a:
	/* 0x136a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_136f:
	/* 0x136f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1371:
	/* 0x1371: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1375:
	/* 0x1375: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1379:
	/* 0x1379: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1380:
	/* 0x1380: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1385:
	/* 0x1385: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138a:
	/* 0x138a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138c:
	/* 0x138c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138f:
	/* 0x138f: je     1e62 <generic_retkprobe_event+0x1e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7778ULL;
	}
x86_l_1395:
	/* 0x1395: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1398:
	/* 0x1398: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_139d:
	/* 0x139d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13a0:
	/* 0x13a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13a5:
	/* 0x13a5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13aa:
	/* 0x13aa: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_13af:
	/* 0x13af: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_13b2:
	/* 0x13b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b9:
	/* 0x13b9: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_13c0:
	/* 0x13c0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c4:
	/* 0x13c4: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_13cb:
	/* 0x13cb: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13cf:
	/* 0x13cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13d4:
	/* 0x13d4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d9:
	/* 0x13d9: lea    rdi,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_13dd:
	/* 0x13dd: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_13e1:
	/* 0x13e1: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_13e5:
	/* 0x13e5: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_13e9:
	/* 0x13e9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ee:
	/* 0x13ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13f3:
	/* 0x13f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f5:
	/* 0x13f5: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_13f9:
	/* 0x13f9: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	return 8644ULL;
x86_l_13fe:
	/* 0x13fe: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1403:
	/* 0x1403: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1406:
	/* 0x1406: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_140e:
	/* 0x140e: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1416:
	/* 0x1416: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_141b:
	/* 0x141b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1420:
	/* 0x1420: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1425:
	/* 0x1425: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1428:
	/* 0x1428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142a:
	/* 0x142a: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_1432:
	/* 0x1432: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1434:
	/* 0x1434: je     1e6e <generic_retkprobe_event+0x1e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7790ULL;
	}
x86_l_143a:
	/* 0x143a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143d:
	/* 0x143d: jne    2074 <generic_retkprobe_event+0x2074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8308ULL;
	}
x86_l_1443:
	/* 0x1443: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1447:
	/* 0x1447: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_144c:
	/* 0x144c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1452:
	/* 0x1452: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1457:
	/* 0x1457: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_145c:
	/* 0x145c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1461:
	/* 0x1461: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146b:
	/* 0x146b: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1470:
	/* 0x1470: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1475:
	/* 0x1475: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_147a:
	/* 0x147a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_147f:
	/* 0x147f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1481:
	/* 0x1481: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1486:
	/* 0x1486: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_148a:
	/* 0x148a: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1492:
	/* 0x1492: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1497:
	/* 0x1497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_149c:
	/* 0x149c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14a1:
	/* 0x14a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a3:
	/* 0x14a3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14a8:
	/* 0x14a8: mov    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14b0:
	/* 0x14b0: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_14b7:
	/* 0x14b7: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_14bd:
	/* 0x14bd: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_14c1:
	/* 0x14c1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_14c4:
	/* 0x14c4: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_14cb:
	/* 0x14cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14d0:
	/* 0x14d0: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_14d3:
	/* 0x14d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d5:
	/* 0x14d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d7:
	/* 0x14d7: js     21a6 <generic_retkprobe_event+0x21a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8614ULL;
	}
x86_l_14dd:
	/* 0x14dd: mov    DWORD PTR [r14+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_14e4:
	/* 0x14e4: mov    DWORD PTR [r14+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14eb:
	/* 0x14eb: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14ef:
	/* 0x14ef: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_14f2:
	/* 0x14f2: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	return 8644ULL;
x86_l_14f7:
	/* 0x14f7: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14fc:
	/* 0x14fc: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1503:
	/* 0x1503: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_150a:
	/* 0x150a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_150f:
	/* 0x150f: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1517:
	/* 0x1517: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_151c:
	/* 0x151c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151e:
	/* 0x151e: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1525:
	/* 0x1525: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1529:
	/* 0x1529: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1533:
	/* 0x1533: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1538:
	/* 0x1538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153a:
	/* 0x153a: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1541:
	/* 0x1541: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1548:
	/* 0x1548: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_154d:
	/* 0x154d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1552:
	/* 0x1552: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1557:
	/* 0x1557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1559:
	/* 0x1559: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1560:
	/* 0x1560: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1567:
	/* 0x1567: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_156c:
	/* 0x156c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1571:
	/* 0x1571: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1581:
	/* 0x1581: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1588:
	/* 0x1588: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_158d:
	/* 0x158d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1592:
	/* 0x1592: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1597:
	/* 0x1597: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_159c:
	/* 0x159c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159e:
	/* 0x159e: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15a5:
	/* 0x15a5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15ad:
	/* 0x15ad: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15b2:
	/* 0x15b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15b7:
	/* 0x15b7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15bc:
	/* 0x15bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15be:
	/* 0x15be: movzx  r12d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_15c7:
	/* 0x15c7: add    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_15cc:
	/* 0x15cc: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_15d4:
	/* 0x15d4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15d9:
	/* 0x15d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15de:
	/* 0x15de: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_15e3:
	/* 0x15e3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
	return 5606ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5606ULL: goto x86_l_15e6;
	case 5608ULL: goto x86_l_15e8;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5622ULL: goto x86_l_15f6;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5675ULL: goto x86_l_162b;
	case 5679ULL: goto x86_l_162f;
	case 5686ULL: goto x86_l_1636;
	case 5695ULL: goto x86_l_163f;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5712ULL: goto x86_l_1650;
	case 5720ULL: goto x86_l_1658;
	case 5728ULL: goto x86_l_1660;
	case 5736ULL: goto x86_l_1668;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5777ULL: goto x86_l_1691;
	case 5782ULL: goto x86_l_1696;
	case 5785ULL: goto x86_l_1699;
	case 5787ULL: goto x86_l_169b;
	case 5794ULL: goto x86_l_16a2;
	case 5802ULL: goto x86_l_16aa;
	case 5807ULL: goto x86_l_16af;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5863ULL: goto x86_l_16e7;
	case 5866ULL: goto x86_l_16ea;
	case 5872ULL: goto x86_l_16f0;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5911ULL: goto x86_l_1717;
	case 5919ULL: goto x86_l_171f;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5947ULL: goto x86_l_173b;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5956ULL: goto x86_l_1744;
	case 5962ULL: goto x86_l_174a;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5975ULL: goto x86_l_1757;
	case 5978ULL: goto x86_l_175a;
	case 5984ULL: goto x86_l_1760;
	case 5989ULL: goto x86_l_1765;
	case 5994ULL: goto x86_l_176a;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6009ULL: goto x86_l_1779;
	case 6011ULL: goto x86_l_177b;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6037ULL: goto x86_l_1795;
	case 6042ULL: goto x86_l_179a;
	case 6047ULL: goto x86_l_179f;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6064ULL: goto x86_l_17b0;
	case 6070ULL: goto x86_l_17b6;
	case 6078ULL: goto x86_l_17be;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6128ULL: goto x86_l_17f0;
	case 6131ULL: goto x86_l_17f3;
	case 6134ULL: goto x86_l_17f6;
	case 6138ULL: goto x86_l_17fa;
	case 6143ULL: goto x86_l_17ff;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6156ULL: goto x86_l_180c;
	case 6161ULL: goto x86_l_1811;
	case 6168ULL: goto x86_l_1818;
	case 6170ULL: goto x86_l_181a;
	case 6178ULL: goto x86_l_1822;
	case 6182ULL: goto x86_l_1826;
	case 6190ULL: goto x86_l_182e;
	case 6196ULL: goto x86_l_1834;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6236ULL: goto x86_l_185c;
	case 6239ULL: goto x86_l_185f;
	case 6245ULL: goto x86_l_1865;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6276ULL: goto x86_l_1884;
	case 6279ULL: goto x86_l_1887;
	case 6282ULL: goto x86_l_188a;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6327ULL: goto x86_l_18b7;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6396ULL: goto x86_l_18fc;
	case 6404ULL: goto x86_l_1904;
	case 6411ULL: goto x86_l_190b;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6425ULL: goto x86_l_1919;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6444ULL: goto x86_l_192c;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6469ULL: goto x86_l_1945;
	case 6475ULL: goto x86_l_194b;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6511ULL: goto x86_l_196f;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6532ULL: goto x86_l_1984;
	case 6536ULL: goto x86_l_1988;
	case 6543ULL: goto x86_l_198f;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6564ULL: goto x86_l_19a4;
	case 6568ULL: goto x86_l_19a8;
	case 6575ULL: goto x86_l_19af;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6596ULL: goto x86_l_19c4;
	case 6600ULL: goto x86_l_19c8;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6628ULL: goto x86_l_19e4;
	case 6632ULL: goto x86_l_19e8;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6671ULL: goto x86_l_1a0f;
	case 6675ULL: goto x86_l_1a13;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6703ULL: goto x86_l_1a2f;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6724ULL: goto x86_l_1a44;
	case 6728ULL: goto x86_l_1a48;
	case 6735ULL: goto x86_l_1a4f;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6754ULL: goto x86_l_1a62;
	case 6756ULL: goto x86_l_1a64;
	case 6760ULL: goto x86_l_1a68;
	case 6770ULL: goto x86_l_1a72;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6802ULL: goto x86_l_1a92;
	case 6806ULL: goto x86_l_1a96;
	case 6813ULL: goto x86_l_1a9d;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6845ULL: goto x86_l_1abd;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6866ULL: goto x86_l_1ad2;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6890ULL: goto x86_l_1aea;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6920ULL: goto x86_l_1b08;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6957ULL: goto x86_l_1b2d;
	case 6961ULL: goto x86_l_1b31;
	case 6968ULL: goto x86_l_1b38;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6996ULL: goto x86_l_1b54;
	case 7003ULL: goto x86_l_1b5b;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7038ULL: goto x86_l_1b7e;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7069ULL: goto x86_l_1b9d;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7087ULL: goto x86_l_1baf;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7108ULL: goto x86_l_1bc4;
	case 7115ULL: goto x86_l_1bcb;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7139ULL: goto x86_l_1be3;
	case 7143ULL: goto x86_l_1be7;
	case 7150ULL: goto x86_l_1bee;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7174ULL: goto x86_l_1c06;
	case 7178ULL: goto x86_l_1c0a;
	case 7185ULL: goto x86_l_1c11;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7210ULL: goto x86_l_1c2a;
	case 7212ULL: goto x86_l_1c2c;
	case 7216ULL: goto x86_l_1c30;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	case 7248ULL: goto x86_l_1c50;
	case 7252ULL: goto x86_l_1c54;
	case 7259ULL: goto x86_l_1c5b;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7280ULL: goto x86_l_1c70;
	case 7284ULL: goto x86_l_1c74;
	case 7291ULL: goto x86_l_1c7b;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7312ULL: goto x86_l_1c90;
	case 7316ULL: goto x86_l_1c94;
	case 7323ULL: goto x86_l_1c9b;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7355ULL: goto x86_l_1cbb;
	case 7359ULL: goto x86_l_1cbf;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7414ULL: goto x86_l_1cf6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15e6:
	/* 0x15e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e8:
	/* 0x15e8: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_15f0:
	/* 0x15f0: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_15f3:
	/* 0x15f3: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_15f6:
	/* 0x15f6: je     1efa <generic_retkprobe_event+0x1efa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7930ULL;
	}
x86_l_15fc:
	/* 0x15fc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15ff:
	/* 0x15ff: jne    2bf1 <generic_retkprobe_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11249ULL;
	}
x86_l_1605:
	/* 0x1605: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_160a:
	/* 0x160a: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1612:
	/* 0x1612: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1617:
	/* 0x1617: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_161c:
	/* 0x161c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_162b:
	/* 0x162b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_162f:
	/* 0x162f: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1636:
	/* 0x1636: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_163f:
	/* 0x163f: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1644:
	/* 0x1644: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1649:
	/* 0x1649: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1650:
	/* 0x1650: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1658:
	/* 0x1658: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1660:
	/* 0x1660: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1668:
	/* 0x1668: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_166d:
	/* 0x166d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1672:
	/* 0x1672: lea    r14,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1679:
	/* 0x1679: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_167e:
	/* 0x167e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1680:
	/* 0x1680: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1684:
	/* 0x1684: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1689:
	/* 0x1689: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_168e:
	/* 0x168e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1691:
	/* 0x1691: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1696:
	/* 0x1696: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1699:
	/* 0x1699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169b:
	/* 0x169b: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_16a2:
	/* 0x16a2: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16aa:
	/* 0x16aa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_16af:
	/* 0x16af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b4:
	/* 0x16b4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_16b9:
	/* 0x16b9: jmp    2a72 <generic_retkprobe_event+0x2a72> */
	return 10866ULL;
x86_l_16be:
	/* 0x16be: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_16c3:
	/* 0x16c3: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_16c8:
	/* 0x16c8: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16cc:
	/* 0x16cc: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_16d3:
	/* 0x16d3: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_16d8:
	/* 0x16d8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16dd:
	/* 0x16dd: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_16e2:
	/* 0x16e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e4:
	/* 0x16e4: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_16e7:
	/* 0x16e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16ea:
	/* 0x16ea: js     1201 <generic_retkprobe_event+0x1201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4609ULL;
	}
x86_l_16f0:
	/* 0x16f0: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_16f4:
	/* 0x16f4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f9:
	/* 0x16f9: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fb:
	/* 0x16fb: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_16ff:
	/* 0x16ff: jmp    1201 <generic_retkprobe_event+0x1201> */
	return 4609ULL;
x86_l_1704:
	/* 0x1704: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_1707:
	/* 0x1707: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_170a:
	/* 0x170a: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_170f:
	/* 0x170f: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1717:
	/* 0x1717: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_171f:
	/* 0x171f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1726:
	/* 0x1726: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_172b:
	/* 0x172b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1730:
	/* 0x1730: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1733:
	/* 0x1733: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1738:
	/* 0x1738: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_173b:
	/* 0x173b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173d:
	/* 0x173d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1740:
	/* 0x1740: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1744:
	/* 0x1744: js     20e0 <generic_retkprobe_event+0x20e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8416ULL;
	}
x86_l_174a:
	/* 0x174a: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_174e:
	/* 0x174e: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1751:
	/* 0x1751: je     208a <generic_retkprobe_event+0x208a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8330ULL;
	}
x86_l_1757:
	/* 0x1757: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_175a:
	/* 0x175a: jne    20cc <generic_retkprobe_event+0x20cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8396ULL;
	}
x86_l_1760:
	/* 0x1760: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1765:
	/* 0x1765: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_176a:
	/* 0x176a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_176f:
	/* 0x176f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1774:
	/* 0x1774: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1779:
	/* 0x1779: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177b:
	/* 0x177b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_177f:
	/* 0x177f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1783:
	/* 0x1783: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_178a:
	/* 0x178a: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1791:
	/* 0x1791: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1795:
	/* 0x1795: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_179a:
	/* 0x179a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_179f:
	/* 0x179f: jmp    20c2 <generic_retkprobe_event+0x20c2> */
	return 8386ULL;
x86_l_17a4:
	/* 0x17a4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a7:
	/* 0x17a7: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_17b0:
	/* 0x17b0: jb     189c <generic_retkprobe_event+0x189c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_189c;
	}
x86_l_17b6:
	/* 0x17b6: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17be:
	/* 0x17be: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17c2:
	/* 0x17c2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17c7:
	/* 0x17c7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_17cd:
	/* 0x17cd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_17d2:
	/* 0x17d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17d7:
	/* 0x17d7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17dc:
	/* 0x17dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17de:
	/* 0x17de: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_17e3:
	/* 0x17e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e5:
	/* 0x17e5: js     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_187b;
	}
x86_l_17eb:
	/* 0x17eb: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17f0:
	/* 0x17f0: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_17f3:
	/* 0x17f3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_17f6:
	/* 0x17f6: cmovb  rcx,rax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_17fa:
	/* 0x17fa: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ff:
	/* 0x17ff: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1802:
	/* 0x1802: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1805:
	/* 0x1805: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1808:
	/* 0x1808: cmovne r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_180c:
	/* 0x180c: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1811:
	/* 0x1811: cmp    r14,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 4094ULL);
x86_l_1818:
	/* 0x1818: ja     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_187b;
	}
x86_l_181a:
	/* 0x181a: mov    rdi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1822:
	/* 0x1822: add    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1826:
	/* 0x1826: mov    QWORD PTR [rsp+0x80],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_182e:
	/* 0x182e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1834:
	/* 0x1834: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1837:
	/* 0x1837: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_183c:
	/* 0x183c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1841:
	/* 0x1841: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1846:
	/* 0x1846: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1849:
	/* 0x1849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184b:
	/* 0x184b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1850:
	/* 0x1850: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1852:
	/* 0x1852: js     187b <generic_retkprobe_event+0x187b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_187b;
	}
x86_l_1854:
	/* 0x1854: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1859:
	/* 0x1859: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_185c:
	/* 0x185c: add    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_185f:
	/* 0x185f: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1865:
	/* 0x1865: je     2322 <generic_retkprobe_event+0x2322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8994ULL;
	}
x86_l_186b:
	/* 0x186b: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_1870:
	/* 0x1870: jne    2329 <generic_retkprobe_event+0x2329> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9001ULL;
	}
x86_l_1876:
	/* 0x1876: jmp    2334 <generic_retkprobe_event+0x2334> */
	return 9012ULL;
x86_l_187b:
	/* 0x187b: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1880:
	/* 0x1880: mov    DWORD PTR [r15+r14*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1884:
	/* 0x1884: add    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1887:
	/* 0x1887: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_188a:
	/* 0x188a: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1892:
	/* 0x1892: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1897:
	/* 0x1897: jmp    2d0b <generic_retkprobe_event+0x2d0b> */
	return 11531ULL;
x86_l_189c:
	/* 0x189c: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_189f:
	/* 0x189f: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18a4:
	/* 0x18a4: jmp    340 <generic_retkprobe_event+0x340> */
	return 832ULL;
x86_l_18a9:
	/* 0x18a9: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ae:
	/* 0x18ae: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_18b7:
	/* 0x18b7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_18c0:
	/* 0x18c0: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18c5:
	/* 0x18c5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18ca:
	/* 0x18ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18cf:
	/* 0x18cf: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_18d2:
	/* 0x18d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18d7:
	/* 0x18d7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_18dd:
	/* 0x18dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18e2:
	/* 0x18e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e4:
	/* 0x18e4: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e9:
	/* 0x18e9: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_18ef:
	/* 0x18ef: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_18f5:
	/* 0x18f5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_18f8:
	/* 0x18f8: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_18fc:
	/* 0x18fc: mov    QWORD PTR [rsp+0x80],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1904:
	/* 0x1904: add    r14,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_190b:
	/* 0x190b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1910:
	/* 0x1910: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1913:
	/* 0x1913: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1916:
	/* 0x1916: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1919:
	/* 0x1919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191b:
	/* 0x191b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1920:
	/* 0x1920: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1922:
	/* 0x1922: js     193d <generic_retkprobe_event+0x193d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_193d;
	}
x86_l_1924:
	/* 0x1924: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_192c:
	/* 0x192c: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1933:
	/* 0x1933: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1937:
	/* 0x1937: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_193a:
	/* 0x193a: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_193d:
	/* 0x193d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1945:
	/* 0x1945: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_194b:
	/* 0x194b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194f:
	/* 0x194f: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1954:
	/* 0x1954: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1959:
	/* 0x1959: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_195e:
	/* 0x195e: lea    r13,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1965:
	/* 0x1965: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1968:
	/* 0x1968: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_196f:
	/* 0x196f: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1973:
	/* 0x1973: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1978:
	/* 0x1978: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_197d:
	/* 0x197d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1982:
	/* 0x1982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1984:
	/* 0x1984: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1988:
	/* 0x1988: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_198f:
	/* 0x198f: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1993:
	/* 0x1993: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1998:
	/* 0x1998: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_199d:
	/* 0x199d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a2:
	/* 0x19a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a4:
	/* 0x19a4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a8:
	/* 0x19a8: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_19af:
	/* 0x19af: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19b3:
	/* 0x19b3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19b8:
	/* 0x19b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19bd:
	/* 0x19bd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c2:
	/* 0x19c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c4:
	/* 0x19c4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c8:
	/* 0x19c8: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_19cf:
	/* 0x19cf: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19d3:
	/* 0x19d3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19d8:
	/* 0x19d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19dd:
	/* 0x19dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e2:
	/* 0x19e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e4:
	/* 0x19e4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e8:
	/* 0x19e8: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19ef:
	/* 0x19ef: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f3:
	/* 0x19f3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19f8:
	/* 0x19f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19fd:
	/* 0x19fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a02:
	/* 0x1a02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a04:
	/* 0x1a04: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a08:
	/* 0x1a08: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a0f:
	/* 0x1a0f: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a13:
	/* 0x1a13: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a18:
	/* 0x1a18: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a22:
	/* 0x1a22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a24:
	/* 0x1a24: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a28:
	/* 0x1a28: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1a2f:
	/* 0x1a2f: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a33:
	/* 0x1a33: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a38:
	/* 0x1a38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a3d:
	/* 0x1a3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a42:
	/* 0x1a42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a44:
	/* 0x1a44: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a48:
	/* 0x1a48: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1a4f:
	/* 0x1a4f: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a53:
	/* 0x1a53: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a58:
	/* 0x1a58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a5d:
	/* 0x1a5d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a62:
	/* 0x1a62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a64:
	/* 0x1a64: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a68:
	/* 0x1a68: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1a72:
	/* 0x1a72: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a76:
	/* 0x1a76: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1a7d:
	/* 0x1a7d: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a81:
	/* 0x1a81: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a86:
	/* 0x1a86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a90:
	/* 0x1a90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a92:
	/* 0x1a92: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a96:
	/* 0x1a96: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1a9d:
	/* 0x1a9d: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aab:
	/* 0x1aab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ab0:
	/* 0x1ab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab2:
	/* 0x1ab2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1abd:
	/* 0x1abd: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1acb:
	/* 0x1acb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad0:
	/* 0x1ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad2:
	/* 0x1ad2: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ad6:
	/* 0x1ad6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1adb:
	/* 0x1adb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1ae3:
	/* 0x1ae3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ae8:
	/* 0x1ae8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aea:
	/* 0x1aea: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1af1:
	/* 0x1af1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1af6:
	/* 0x1af6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1afb:
	/* 0x1afb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b00:
	/* 0x1b00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b05:
	/* 0x1b05: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b08:
	/* 0x1b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0a:
	/* 0x1b0a: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0f:
	/* 0x1b0f: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1b16:
	/* 0x1b16: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b20:
	/* 0x1b20: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1b23:
	/* 0x1b23: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b2b:
	/* 0x1b2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2d:
	/* 0x1b2d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b31:
	/* 0x1b31: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1b38:
	/* 0x1b38: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b44:
	/* 0x1b44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b49:
	/* 0x1b49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b4e:
	/* 0x1b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b50:
	/* 0x1b50: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b54:
	/* 0x1b54: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1b5b:
	/* 0x1b5b: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1b62:
	/* 0x1b62: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b67:
	/* 0x1b67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b6c:
	/* 0x1b6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b71:
	/* 0x1b71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b73:
	/* 0x1b73: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b77:
	/* 0x1b77: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1b7e:
	/* 0x1b7e: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1b85:
	/* 0x1b85: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b94:
	/* 0x1b94: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b97:
	/* 0x1b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b99:
	/* 0x1b99: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9d:
	/* 0x1b9d: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_1ba3:
	/* 0x1ba3: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_1ba8:
	/* 0x1ba8: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1baf:
	/* 0x1baf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bbe:
	/* 0x1bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc0:
	/* 0x1bc0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc4:
	/* 0x1bc4: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1bcb:
	/* 0x1bcb: lea    rdx,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bd7:
	/* 0x1bd7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1be1:
	/* 0x1be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be3:
	/* 0x1be3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be7:
	/* 0x1be7: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1bee:
	/* 0x1bee: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bff:
	/* 0x1bff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c04:
	/* 0x1c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c06:
	/* 0x1c06: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c0a:
	/* 0x1c0a: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1c11:
	/* 0x1c11: add    rbp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c18:
	/* 0x1c18: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c22:
	/* 0x1c22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c27:
	/* 0x1c27: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1c2a:
	/* 0x1c2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2c:
	/* 0x1c2c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c30:
	/* 0x1c30: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1c36:
	/* 0x1c36: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_1c3b:
	/* 0x1c3b: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c3f:
	/* 0x1c3f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c44:
	/* 0x1c44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c49:
	/* 0x1c49: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c4e:
	/* 0x1c4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c50:
	/* 0x1c50: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c54:
	/* 0x1c54: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c5b:
	/* 0x1c5b: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c64:
	/* 0x1c64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c69:
	/* 0x1c69: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c6e:
	/* 0x1c6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c70:
	/* 0x1c70: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c74:
	/* 0x1c74: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1c7b:
	/* 0x1c7b: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c84:
	/* 0x1c84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c89:
	/* 0x1c89: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c8e:
	/* 0x1c8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c90:
	/* 0x1c90: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c94:
	/* 0x1c94: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c9b:
	/* 0x1c9b: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
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
	/* 0x1cb0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1cbb:
	/* 0x1cbb: add    rbp,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1cce:
	/* 0x1cce: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1cd1:
	/* 0x1cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd3:
	/* 0x1cd3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1cdd:
	/* 0x1cdd: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_1ce2:
	/* 0x1ce2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cec:
	/* 0x1cec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cf1:
	/* 0x1cf1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1cf4:
	/* 0x1cf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf6:
	/* 0x1cf6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 7418ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7418ULL: goto x86_l_1cfa;
	case 7425ULL: goto x86_l_1d01;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7450ULL: goto x86_l_1d1a;
	case 7457ULL: goto x86_l_1d21;
	case 7461ULL: goto x86_l_1d25;
	case 7466ULL: goto x86_l_1d2a;
	case 7471ULL: goto x86_l_1d2f;
	case 7476ULL: goto x86_l_1d34;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7524ULL: goto x86_l_1d64;
	case 7528ULL: goto x86_l_1d68;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7564ULL: goto x86_l_1d8c;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7591ULL: goto x86_l_1da7;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7639ULL: goto x86_l_1dd7;
	case 7643ULL: goto x86_l_1ddb;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7662ULL: goto x86_l_1dee;
	case 7670ULL: goto x86_l_1df6;
	case 7678ULL: goto x86_l_1dfe;
	case 7686ULL: goto x86_l_1e06;
	case 7694ULL: goto x86_l_1e0e;
	case 7702ULL: goto x86_l_1e16;
	case 7710ULL: goto x86_l_1e1e;
	case 7718ULL: goto x86_l_1e26;
	case 7726ULL: goto x86_l_1e2e;
	case 7729ULL: goto x86_l_1e31;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7761ULL: goto x86_l_1e51;
	case 7764ULL: goto x86_l_1e54;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7778ULL: goto x86_l_1e62;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7800ULL: goto x86_l_1e78;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7817ULL: goto x86_l_1e89;
	case 7821ULL: goto x86_l_1e8d;
	case 7829ULL: goto x86_l_1e95;
	case 7834ULL: goto x86_l_1e9a;
	case 7839ULL: goto x86_l_1e9f;
	case 7844ULL: goto x86_l_1ea4;
	case 7847ULL: goto x86_l_1ea7;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7862ULL: goto x86_l_1eb6;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7879ULL: goto x86_l_1ec7;
	case 7882ULL: goto x86_l_1eca;
	case 7889ULL: goto x86_l_1ed1;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7901ULL: goto x86_l_1edd;
	case 7907ULL: goto x86_l_1ee3;
	case 7914ULL: goto x86_l_1eea;
	case 7921ULL: goto x86_l_1ef1;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7943ULL: goto x86_l_1f07;
	case 7952ULL: goto x86_l_1f10;
	case 7959ULL: goto x86_l_1f17;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7973ULL: goto x86_l_1f25;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7986ULL: goto x86_l_1f32;
	case 7992ULL: goto x86_l_1f38;
	case 7995ULL: goto x86_l_1f3b;
	case 7999ULL: goto x86_l_1f3f;
	case 8003ULL: goto x86_l_1f43;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8014ULL: goto x86_l_1f4e;
	case 8022ULL: goto x86_l_1f56;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8071ULL: goto x86_l_1f87;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8095ULL: goto x86_l_1f9f;
	case 8102ULL: goto x86_l_1fa6;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8148ULL: goto x86_l_1fd4;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8158ULL: goto x86_l_1fde;
	case 8162ULL: goto x86_l_1fe2;
	case 8169ULL: goto x86_l_1fe9;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8196ULL: goto x86_l_2004;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8236ULL: goto x86_l_202c;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8289ULL: goto x86_l_2061;
	case 8293ULL: goto x86_l_2065;
	case 8297ULL: goto x86_l_2069;
	case 8300ULL: goto x86_l_206c;
	case 8303ULL: goto x86_l_206f;
	case 8308ULL: goto x86_l_2074;
	case 8319ULL: goto x86_l_207f;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8347ULL: goto x86_l_209b;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8372ULL: goto x86_l_20b4;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8400ULL: goto x86_l_20d0;
	case 8407ULL: goto x86_l_20d7;
	case 8416ULL: goto x86_l_20e0;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8437ULL: goto x86_l_20f5;
	case 8444ULL: goto x86_l_20fc;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8469ULL: goto x86_l_2115;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8480ULL: goto x86_l_2120;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8506ULL: goto x86_l_213a;
	case 8510ULL: goto x86_l_213e;
	case 8517ULL: goto x86_l_2145;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8552ULL: goto x86_l_2168;
	case 8556ULL: goto x86_l_216c;
	case 8561ULL: goto x86_l_2171;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8579ULL: goto x86_l_2183;
	case 8581ULL: goto x86_l_2185;
	case 8587ULL: goto x86_l_218b;
	case 8590ULL: goto x86_l_218e;
	case 8596ULL: goto x86_l_2194;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8625ULL: goto x86_l_21b1;
	case 8627ULL: goto x86_l_21b3;
	case 8638ULL: goto x86_l_21be;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8683ULL: goto x86_l_21eb;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8694ULL: goto x86_l_21f6;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8710ULL: goto x86_l_2206;
	case 8714ULL: goto x86_l_220a;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8772ULL: goto x86_l_2244;
	case 8776ULL: goto x86_l_2248;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8850ULL: goto x86_l_2292;
	case 8860ULL: goto x86_l_229c;
	case 8864ULL: goto x86_l_22a0;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8893ULL: goto x86_l_22bd;
	case 8895ULL: goto x86_l_22bf;
	case 8898ULL: goto x86_l_22c2;
	case 8904ULL: goto x86_l_22c8;
	case 8906ULL: goto x86_l_22ca;
	case 8914ULL: goto x86_l_22d2;
	case 8917ULL: goto x86_l_22d5;
	case 8921ULL: goto x86_l_22d9;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8961ULL: goto x86_l_2301;
	case 8968ULL: goto x86_l_2308;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9010ULL: goto x86_l_2332;
	case 9012ULL: goto x86_l_2334;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9033ULL: goto x86_l_2349;
	case 9037ULL: goto x86_l_234d;
	case 9042ULL: goto x86_l_2352;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9078ULL: goto x86_l_2376;
	case 9083ULL: goto x86_l_237b;
	case 9088ULL: goto x86_l_2380;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9117ULL: goto x86_l_239d;
	case 9123ULL: goto x86_l_23a3;
	case 9126ULL: goto x86_l_23a6;
	case 9129ULL: goto x86_l_23a9;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9178ULL: goto x86_l_23da;
	case 9184ULL: goto x86_l_23e0;
	case 9187ULL: goto x86_l_23e3;
	case 9193ULL: goto x86_l_23e9;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cfa:
	/* 0x1cfa: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d01:
	/* 0x1d01: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d05:
	/* 0x1d05: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d14:
	/* 0x1d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d16:
	/* 0x1d16: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1a:
	/* 0x1d1a: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1d21:
	/* 0x1d21: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1d25:
	/* 0x1d25: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2f:
	/* 0x1d2f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d34:
	/* 0x1d34: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1d37:
	/* 0x1d37: jmp    1dd5 <generic_retkprobe_event+0x1dd5> */
	goto x86_l_1dd5;
x86_l_1d3c:
	/* 0x1d3c: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d40:
	/* 0x1d40: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d45:
	/* 0x1d45: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d54:
	/* 0x1d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d56:
	/* 0x1d56: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1d64:
	/* 0x1d64: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d68:
	/* 0x1d68: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6d:
	/* 0x1d6d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d72:
	/* 0x1d72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d77:
	/* 0x1d77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d7c:
	/* 0x1d7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7e:
	/* 0x1d7e: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d82:
	/* 0x1d82: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d86:
	/* 0x1d86: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d8c:
	/* 0x1d8c: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1d90:
	/* 0x1d90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d95:
	/* 0x1d95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da4:
	/* 0x1da4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1da7:
	/* 0x1da7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da9:
	/* 0x1da9: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dad:
	/* 0x1dad: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1db4:
	/* 0x1db4: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1db9:
	/* 0x1db9: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dbe:
	/* 0x1dbe: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dc1:
	/* 0x1dc1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dc6:
	/* 0x1dc6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1dcb:
	/* 0x1dcb: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dd5:
	/* 0x1dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd7:
	/* 0x1dd7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1de1:
	/* 0x1de1: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_1de6:
	/* 0x1de6: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1dee:
	/* 0x1dee: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1df6:
	/* 0x1df6: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1e06:
	/* 0x1e06: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e16:
	/* 0x1e16: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e26:
	/* 0x1e26: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1e2e:
	/* 0x1e2e: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_1e31:
	/* 0x1e31: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e38:
	/* 0x1e38: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e42:
	/* 0x1e42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e47:
	/* 0x1e47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e4f:
	/* 0x1e4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e51:
	/* 0x1e51: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e54:
	/* 0x1e54: je     20f1 <generic_retkprobe_event+0x20f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f1;
	}
x86_l_1e5a:
	/* 0x1e5a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e5d:
	/* 0x1e5d: jmp    1201 <generic_retkprobe_event+0x1201> */
	return 4609ULL;
x86_l_1e62:
	/* 0x1e62: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1e69:
	/* 0x1e69: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	goto x86_l_21c4;
x86_l_1e6e:
	/* 0x1e6e: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e73:
	/* 0x1e73: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e78:
	/* 0x1e78: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e7d:
	/* 0x1e7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e82:
	/* 0x1e82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e87:
	/* 0x1e87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e89:
	/* 0x1e89: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1e8d:
	/* 0x1e8d: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e95:
	/* 0x1e95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e9f:
	/* 0x1e9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ea7:
	/* 0x1ea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea9:
	/* 0x1ea9: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1eae:
	/* 0x1eae: mov    r12,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1eb6:
	/* 0x1eb6: cmp    r12,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4095ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_1ec3:
	/* 0x1ec3: cmovb  r13,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_64, X86_CC_B);
x86_l_1ec7:
	/* 0x1ec7: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1eca:
	/* 0x1eca: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1ed9:
	/* 0x1ed9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1edb:
	/* 0x1edb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1edd:
	/* 0x1edd: js     21b3 <generic_retkprobe_event+0x21b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_21b3;
	}
x86_l_1ee3:
	/* 0x1ee3: mov    DWORD PTR [r14+0x9c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1eea:
	/* 0x1eea: mov    DWORD PTR [r14+0xa0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ef1:
	/* 0x1ef1: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ef5:
	/* 0x1ef5: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	goto x86_l_21c4;
x86_l_1efa:
	/* 0x1efa: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eff:
	/* 0x1eff: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1f07:
	/* 0x1f07: movzx  r12d,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1f10:
	/* 0x1f10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1f17:
	/* 0x1f17: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f1c:
	/* 0x1f1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f21:
	/* 0x1f21: lea    rcx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1f25:
	/* 0x1f25: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f2d:
	/* 0x1f2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2f:
	/* 0x1f2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f32:
	/* 0x1f32: je     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10768ULL;
	}
x86_l_1f38:
	/* 0x1f38: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1f3b:
	/* 0x1f3b: mov    WORD PTR [rax],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f3f:
	/* 0x1f3f: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1f43:
	/* 0x1f43: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1f47:
	/* 0x1f47: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f4a:
	/* 0x1f4a: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f56:
	/* 0x1f56: lea    rdx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f5f:
	/* 0x1f5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f64:
	/* 0x1f64: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_1f67:
	/* 0x1f67: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1f6c:
	/* 0x1f6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6e:
	/* 0x1f6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f71:
	/* 0x1f71: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10768ULL;
	}
x86_l_1f77:
	/* 0x1f77: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1f7c:
	/* 0x1f7c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1f7f:
	/* 0x1f7f: jg     22e8 <generic_retkprobe_event+0x22e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22e8;
	}
x86_l_1f85:
	/* 0x1f85: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f87:
	/* 0x1f87: je     2311 <generic_retkprobe_event+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2311;
	}
x86_l_1f8d:
	/* 0x1f8d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1f90:
	/* 0x1f90: je     2311 <generic_retkprobe_event+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2311;
	}
x86_l_1f96:
	/* 0x1f96: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1f99:
	/* 0x1f99: jne    24c2 <generic_retkprobe_event+0x24c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9410ULL;
	}
x86_l_1f9f:
	/* 0x1f9f: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1faa:
	/* 0x1faa: jmp    2410 <generic_retkprobe_event+0x2410> */
	return 9232ULL;
x86_l_1faf:
	/* 0x1faf: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fb4:
	/* 0x1fb4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fc3:
	/* 0x1fc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc5:
	/* 0x1fc5: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fca:
	/* 0x1fca: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fd4:
	/* 0x1fd4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1fd7:
	/* 0x1fd7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fdc:
	/* 0x1fdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fde:
	/* 0x1fde: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe2:
	/* 0x1fe2: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1fe9:
	/* 0x1fe9: lea    r14,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fee:
	/* 0x1fee: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ffc:
	/* 0x1ffc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2001:
	/* 0x2001: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2004:
	/* 0x2004: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2006:
	/* 0x2006: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2009:
	/* 0x2009: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_2010:
	/* 0x2010: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2015:
	/* 0x2015: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_201a:
	/* 0x201a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_201f:
	/* 0x201f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2022:
	/* 0x2022: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2024:
	/* 0x2024: movzx  eax,WORD PTR [r13+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_202c:
	/* 0x202c: movbe  WORD PTR [r13+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2036:
	/* 0x2036: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_203b:
	/* 0x203b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2040:
	/* 0x2040: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2047:
	/* 0x2047: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_204c:
	/* 0x204c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2051:
	/* 0x2051: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2053:
	/* 0x2053: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2056:
	/* 0x2056: je     2bf1 <generic_retkprobe_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11249ULL;
	}
x86_l_205c:
	/* 0x205c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_205e:
	/* 0x205e: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2061:
	/* 0x2061: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2065:
	/* 0x2065: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2069:
	/* 0x2069: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_206c:
	/* 0x206c: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_206f:
	/* 0x206f: jmp    2bf1 <generic_retkprobe_event+0x2bf1> */
	return 11249ULL;
x86_l_2074:
	/* 0x2074: mov    QWORD PTR [r14+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_207f:
	/* 0x207f: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_2085:
	/* 0x2085: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	goto x86_l_21c4;
x86_l_208a:
	/* 0x208a: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2091:
	/* 0x2091: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2096:
	/* 0x2096: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_209b:
	/* 0x209b: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_209e:
	/* 0x209e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20a3:
	/* 0x20a3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20a8:
	/* 0x20a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20aa:
	/* 0x20aa: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_20ad:
	/* 0x20ad: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_20b4:
	/* 0x20b4: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_20b8:
	/* 0x20b8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20bd:
	/* 0x20bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20c2:
	/* 0x20c2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20c7:
	/* 0x20c7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20ca:
	/* 0x20ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20cc:
	/* 0x20cc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d0:
	/* 0x20d0: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_20d7:
	/* 0x20d7: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_20e0:
	/* 0x20e0: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_20e6:
	/* 0x20e6: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_20e9:
	/* 0x20e9: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_20ec:
	/* 0x20ec: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_20f1:
	/* 0x20f1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f5:
	/* 0x20f5: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_20fc:
	/* 0x20fc: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2101:
	/* 0x2101: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_2106:
	/* 0x2106: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_210b:
	/* 0x210b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2110:
	/* 0x2110: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_2115:
	/* 0x2115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2117:
	/* 0x2117: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211a:
	/* 0x211a: js     1e5a <generic_retkprobe_event+0x1e5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e5a;
	}
x86_l_2120:
	/* 0x2120: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2124:
	/* 0x2124: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2129:
	/* 0x2129: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_212e:
	/* 0x212e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2133:
	/* 0x2133: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2138:
	/* 0x2138: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213a:
	/* 0x213a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_213e:
	/* 0x213e: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_2145:
	/* 0x2145: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_214a:
	/* 0x214a: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_214f:
	/* 0x214f: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2152:
	/* 0x2152: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2157:
	/* 0x2157: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_215c:
	/* 0x215c: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2161:
	/* 0x2161: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2166:
	/* 0x2166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2168:
	/* 0x2168: add    rbp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_216c:
	/* 0x216c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2171:
	/* 0x2171: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2176:
	/* 0x2176: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_217b:
	/* 0x217b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2180:
	/* 0x2180: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2183:
	/* 0x2183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2185:
	/* 0x2185: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_218b:
	/* 0x218b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_218e:
	/* 0x218e: jne    1201 <generic_retkprobe_event+0x1201> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4609ULL;
	}
x86_l_2194:
	/* 0x2194: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2196:
	/* 0x2196: cmp    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_219b:
	/* 0x219b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_219e:
	/* 0x219e: mov    DWORD PTR [r14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a1:
	/* 0x21a1: jmp    1201 <generic_retkprobe_event+0x1201> */
	return 4609ULL;
x86_l_21a6:
	/* 0x21a6: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_21b1:
	/* 0x21b1: jmp    21c4 <generic_retkprobe_event+0x21c4> */
	goto x86_l_21c4;
x86_l_21b3:
	/* 0x21b3: mov    DWORD PTR [r14+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_21be:
	/* 0x21be: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_21c4:
	/* 0x21c4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c8:
	/* 0x21c8: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_21cb:
	/* 0x21cb: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d0:
	/* 0x21d0: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_21d5:
	/* 0x21d5: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_21d9:
	/* 0x21d9: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_21de:
	/* 0x21de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21e3:
	/* 0x21e3: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_21e8:
	/* 0x21e8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21eb:
	/* 0x21eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ed:
	/* 0x21ed: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_21f0:
	/* 0x21f0: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_21f2:
	/* 0x21f2: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_21f4:
	/* 0x21f4: js     2200 <generic_retkprobe_event+0x2200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2200;
	}
x86_l_21f6:
	/* 0x21f6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21fa:
	/* 0x21fa: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_2200:
	/* 0x2200: mov    r13d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 112ULL);
x86_l_2206:
	/* 0x2206: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220a:
	/* 0x220a: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_220d:
	/* 0x220d: jmp    2c00 <generic_retkprobe_event+0x2c00> */
	return 11264ULL;
x86_l_2212:
	/* 0x2212: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2217:
	/* 0x2217: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_221c:
	/* 0x221c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2221:
	/* 0x2221: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2224:
	/* 0x2224: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2229:
	/* 0x2229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222b:
	/* 0x222b: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2230:
	/* 0x2230: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2235:
	/* 0x2235: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_223a:
	/* 0x223a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_223d:
	/* 0x223d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2242:
	/* 0x2242: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2244:
	/* 0x2244: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2248:
	/* 0x2248: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_224f:
	/* 0x224f: lea    r14,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2254:
	/* 0x2254: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2258:
	/* 0x2258: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_225d:
	/* 0x225d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2262:
	/* 0x2262: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2267:
	/* 0x2267: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_226a:
	/* 0x226a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226c:
	/* 0x226c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_2276:
	/* 0x2276: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_227b:
	/* 0x227b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2280:
	/* 0x2280: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2285:
	/* 0x2285: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2288:
	/* 0x2288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228a:
	/* 0x228a: movzx  eax,WORD PTR [r13+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2292:
	/* 0x2292: movbe  WORD PTR [r13+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_229c:
	/* 0x229c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a0:
	/* 0x22a0: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_22a7:
	/* 0x22a7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22ac:
	/* 0x22ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_22b3:
	/* 0x22b3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22b8:
	/* 0x22b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22bd:
	/* 0x22bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bf:
	/* 0x22bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c2:
	/* 0x22c2: je     2bf1 <generic_retkprobe_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11249ULL;
	}
x86_l_22c8:
	/* 0x22c8: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ca:
	/* 0x22ca: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_22d2:
	/* 0x22d2: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d5:
	/* 0x22d5: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d9:
	/* 0x22d9: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22dd:
	/* 0x22dd: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22e0:
	/* 0x22e0: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_22e3:
	/* 0x22e3: jmp    2bf1 <generic_retkprobe_event+0x2bf1> */
	return 11249ULL;
x86_l_22e8:
	/* 0x22e8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_22eb:
	/* 0x22eb: je     23ff <generic_retkprobe_event+0x23ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ff;
	}
x86_l_22f1:
	/* 0x22f1: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22f4:
	/* 0x22f4: je     2311 <generic_retkprobe_event+0x2311> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2311;
	}
x86_l_22f6:
	/* 0x22f6: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_22fb:
	/* 0x22fb: jne    24c2 <generic_retkprobe_event+0x24c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9410ULL;
	}
x86_l_2301:
	/* 0x2301: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2308:
	/* 0x2308: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_230c:
	/* 0x230c: jmp    2410 <generic_retkprobe_event+0x2410> */
	return 9232ULL;
x86_l_2311:
	/* 0x2311: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2316:
	/* 0x2316: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_231d:
	/* 0x231d: jmp    240b <generic_retkprobe_event+0x240b> */
	return 9227ULL;
x86_l_2322:
	/* 0x2322: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2324:
	/* 0x2324: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2329:
	/* 0x2329: cmp    QWORD PTR [rsp+0x88],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552259ULL);
x86_l_2332:
	/* 0x2332: jne    2341 <generic_retkprobe_event+0x2341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2341;
	}
x86_l_2334:
	/* 0x2334: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_2337:
	/* 0x2337: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_233c:
	/* 0x233c: jmp    189f <generic_retkprobe_event+0x189f> */
	return 6303ULL;
x86_l_2341:
	/* 0x2341: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2349:
	/* 0x2349: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_234d:
	/* 0x234d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2352:
	/* 0x2352: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2358:
	/* 0x2358: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_235d:
	/* 0x235d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2362:
	/* 0x2362: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2367:
	/* 0x2367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2369:
	/* 0x2369: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_236e:
	/* 0x236e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2370:
	/* 0x2370: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12596ULL;
	}
x86_l_2376:
	/* 0x2376: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_237b:
	/* 0x237b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2380:
	/* 0x2380: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2383:
	/* 0x2383: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2386:
	/* 0x2386: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_238a:
	/* 0x238a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_238d:
	/* 0x238d: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_2391:
	/* 0x2391: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2396:
	/* 0x2396: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_239d:
	/* 0x239d: ja     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12596ULL;
	}
x86_l_23a3:
	/* 0x23a3: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_23a6:
	/* 0x23a6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_23a9:
	/* 0x23a9: add    rdi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_23b1:
	/* 0x23b1: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_23b4:
	/* 0x23b4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23ba:
	/* 0x23ba: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_23bf:
	/* 0x23bf: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23c4:
	/* 0x23c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c9:
	/* 0x23c9: mov    rsi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23d1:
	/* 0x23d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d3:
	/* 0x23d3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_23d8:
	/* 0x23d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23da:
	/* 0x23da: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12596ULL;
	}
x86_l_23e0:
	/* 0x23e0: add    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23e3:
	/* 0x23e3: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_23e9:
	/* 0x23e9: je     273f <generic_retkprobe_event+0x273f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10047ULL;
	}
x86_l_23ef:
	/* 0x23ef: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_23f4:
	/* 0x23f4: jne    2746 <generic_retkprobe_event+0x2746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10054ULL;
	}
x86_l_23fa:
	/* 0x23fa: jmp    2334 <generic_retkprobe_event+0x2334> */
	goto x86_l_2334;
x86_l_23ff:
	/* 0x23ff: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
	return 9220ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9220ULL: goto x86_l_2404;
	case 9227ULL: goto x86_l_240b;
	case 9232ULL: goto x86_l_2410;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9247ULL: goto x86_l_241f;
	case 9251ULL: goto x86_l_2423;
	case 9257ULL: goto x86_l_2429;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9277ULL: goto x86_l_243d;
	case 9281ULL: goto x86_l_2441;
	case 9284ULL: goto x86_l_2444;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9318ULL: goto x86_l_2466;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9334ULL: goto x86_l_2476;
	case 9336ULL: goto x86_l_2478;
	case 9338ULL: goto x86_l_247a;
	case 9341ULL: goto x86_l_247d;
	case 9343ULL: goto x86_l_247f;
	case 9346ULL: goto x86_l_2482;
	case 9348ULL: goto x86_l_2484;
	case 9355ULL: goto x86_l_248b;
	case 9359ULL: goto x86_l_248f;
	case 9361ULL: goto x86_l_2491;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9385ULL: goto x86_l_24a9;
	case 9389ULL: goto x86_l_24ad;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9463ULL: goto x86_l_24f7;
	case 9469ULL: goto x86_l_24fd;
	case 9479ULL: goto x86_l_2507;
	case 9483ULL: goto x86_l_250b;
	case 9489ULL: goto x86_l_2511;
	case 9493ULL: goto x86_l_2515;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9530ULL: goto x86_l_253a;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9548ULL: goto x86_l_254c;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9558ULL: goto x86_l_2556;
	case 9560ULL: goto x86_l_2558;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9576ULL: goto x86_l_2568;
	case 9578ULL: goto x86_l_256a;
	case 9581ULL: goto x86_l_256d;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9665ULL: goto x86_l_25c1;
	case 9671ULL: goto x86_l_25c7;
	case 9681ULL: goto x86_l_25d1;
	case 9685ULL: goto x86_l_25d5;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9729ULL: goto x86_l_2601;
	case 9732ULL: goto x86_l_2604;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9750ULL: goto x86_l_2616;
	case 9752ULL: goto x86_l_2618;
	case 9755ULL: goto x86_l_261b;
	case 9757ULL: goto x86_l_261d;
	case 9760ULL: goto x86_l_2620;
	case 9762ULL: goto x86_l_2622;
	case 9769ULL: goto x86_l_2629;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9778ULL: goto x86_l_2632;
	case 9780ULL: goto x86_l_2634;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9792ULL: goto x86_l_2640;
	case 9799ULL: goto x86_l_2647;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9867ULL: goto x86_l_268b;
	case 9873ULL: goto x86_l_2691;
	case 9883ULL: goto x86_l_269b;
	case 9887ULL: goto x86_l_269f;
	case 9893ULL: goto x86_l_26a5;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9924ULL: goto x86_l_26c4;
	case 9929ULL: goto x86_l_26c9;
	case 9931ULL: goto x86_l_26cb;
	case 9934ULL: goto x86_l_26ce;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9948ULL: goto x86_l_26dc;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9957ULL: goto x86_l_26e5;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9968ULL: goto x86_l_26f0;
	case 9975ULL: goto x86_l_26f7;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9987ULL: goto x86_l_2703;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10009ULL: goto x86_l_2719;
	case 10016ULL: goto x86_l_2720;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10077ULL: goto x86_l_275d;
	case 10081ULL: goto x86_l_2761;
	case 10086ULL: goto x86_l_2766;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10116ULL: goto x86_l_2784;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10142ULL: goto x86_l_279e;
	case 10145ULL: goto x86_l_27a1;
	case 10149ULL: goto x86_l_27a5;
	case 10154ULL: goto x86_l_27aa;
	case 10158ULL: goto x86_l_27ae;
	case 10165ULL: goto x86_l_27b5;
	case 10171ULL: goto x86_l_27bb;
	case 10174ULL: goto x86_l_27be;
	case 10177ULL: goto x86_l_27c1;
	case 10180ULL: goto x86_l_27c4;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10201ULL: goto x86_l_27d9;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10246ULL: goto x86_l_2806;
	case 10252ULL: goto x86_l_280c;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10296ULL: goto x86_l_2838;
	case 10300ULL: goto x86_l_283c;
	case 10306ULL: goto x86_l_2842;
	case 10316ULL: goto x86_l_284c;
	case 10320ULL: goto x86_l_2850;
	case 10326ULL: goto x86_l_2856;
	case 10330ULL: goto x86_l_285a;
	case 10333ULL: goto x86_l_285d;
	case 10336ULL: goto x86_l_2860;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10364ULL: goto x86_l_287c;
	case 10367ULL: goto x86_l_287f;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10381ULL: goto x86_l_288d;
	case 10383ULL: goto x86_l_288f;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10392ULL: goto x86_l_2898;
	case 10395ULL: goto x86_l_289b;
	case 10397ULL: goto x86_l_289d;
	case 10404ULL: goto x86_l_28a4;
	case 10408ULL: goto x86_l_28a8;
	case 10410ULL: goto x86_l_28aa;
	case 10413ULL: goto x86_l_28ad;
	case 10415ULL: goto x86_l_28af;
	case 10418ULL: goto x86_l_28b2;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10427ULL: goto x86_l_28bb;
	case 10434ULL: goto x86_l_28c2;
	case 10438ULL: goto x86_l_28c6;
	case 10440ULL: goto x86_l_28c8;
	case 10445ULL: goto x86_l_28cd;
	case 10452ULL: goto x86_l_28d4;
	case 10457ULL: goto x86_l_28d9;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10471ULL: goto x86_l_28e7;
	case 10476ULL: goto x86_l_28ec;
	case 10478ULL: goto x86_l_28ee;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10502ULL: goto x86_l_2906;
	case 10508ULL: goto x86_l_290c;
	case 10518ULL: goto x86_l_2916;
	case 10522ULL: goto x86_l_291a;
	case 10528ULL: goto x86_l_2920;
	case 10532ULL: goto x86_l_2924;
	case 10535ULL: goto x86_l_2927;
	case 10538ULL: goto x86_l_292a;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10583ULL: goto x86_l_2957;
	case 10585ULL: goto x86_l_2959;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10597ULL: goto x86_l_2965;
	case 10599ULL: goto x86_l_2967;
	case 10606ULL: goto x86_l_296e;
	case 10610ULL: goto x86_l_2972;
	case 10612ULL: goto x86_l_2974;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10620ULL: goto x86_l_297c;
	case 10622ULL: goto x86_l_297e;
	case 10627ULL: goto x86_l_2983;
	case 10629ULL: goto x86_l_2985;
	case 10636ULL: goto x86_l_298c;
	case 10640ULL: goto x86_l_2990;
	case 10642ULL: goto x86_l_2992;
	case 10647ULL: goto x86_l_2997;
	case 10654ULL: goto x86_l_299e;
	case 10659ULL: goto x86_l_29a3;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10673ULL: goto x86_l_29b1;
	case 10678ULL: goto x86_l_29b6;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10704ULL: goto x86_l_29d0;
	case 10710ULL: goto x86_l_29d6;
	case 10720ULL: goto x86_l_29e0;
	case 10724ULL: goto x86_l_29e4;
	case 10730ULL: goto x86_l_29ea;
	case 10734ULL: goto x86_l_29ee;
	case 10737ULL: goto x86_l_29f1;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10755ULL: goto x86_l_2a03;
	case 10758ULL: goto x86_l_2a06;
	case 10761ULL: goto x86_l_2a09;
	case 10766ULL: goto x86_l_2a0e;
	case 10768ULL: goto x86_l_2a10;
	case 10770ULL: goto x86_l_2a12;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10784ULL: goto x86_l_2a20;
	case 10792ULL: goto x86_l_2a28;
	case 10802ULL: goto x86_l_2a32;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10820ULL: goto x86_l_2a44;
	case 10825ULL: goto x86_l_2a49;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10837ULL: goto x86_l_2a55;
	case 10844ULL: goto x86_l_2a5c;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2404:
	/* 0x2404: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_240b:
	/* 0x240b: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2410:
	/* 0x2410: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2415:
	/* 0x2415: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241a:
	/* 0x241a: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_241f:
	/* 0x241f: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2423:
	/* 0x2423: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_2429:
	/* 0x2429: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2433:
	/* 0x2433: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2437:
	/* 0x2437: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_243d:
	/* 0x243d: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2441:
	/* 0x2441: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2444:
	/* 0x2444: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2447:
	/* 0x2447: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_244c:
	/* 0x244c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2451:
	/* 0x2451: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2454:
	/* 0x2454: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2459:
	/* 0x2459: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_245c:
	/* 0x245c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2461:
	/* 0x2461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2463:
	/* 0x2463: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2466:
	/* 0x2466: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_246c:
	/* 0x246c: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2471:
	/* 0x2471: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2474:
	/* 0x2474: jg     2491 <generic_retkprobe_event+0x2491> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2491;
	}
x86_l_2476:
	/* 0x2476: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2478:
	/* 0x2478: je     24af <generic_retkprobe_event+0x24af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24af;
	}
x86_l_247a:
	/* 0x247a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_247d:
	/* 0x247d: je     24af <generic_retkprobe_event+0x24af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24af;
	}
x86_l_247f:
	/* 0x247f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2482:
	/* 0x2482: jne    24df <generic_retkprobe_event+0x24df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24df;
	}
x86_l_2484:
	/* 0x2484: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_248b:
	/* 0x248b: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_248f:
	/* 0x248f: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	goto x86_l_24e4;
x86_l_2491:
	/* 0x2491: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2494:
	/* 0x2494: je     24cc <generic_retkprobe_event+0x24cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cc;
	}
x86_l_2496:
	/* 0x2496: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2499:
	/* 0x2499: je     24af <generic_retkprobe_event+0x24af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24af;
	}
x86_l_249b:
	/* 0x249b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_24a0:
	/* 0x24a0: jne    24df <generic_retkprobe_event+0x24df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24df;
	}
x86_l_24a2:
	/* 0x24a2: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_24a9:
	/* 0x24a9: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_24ad:
	/* 0x24ad: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	goto x86_l_24e4;
x86_l_24af:
	/* 0x24af: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24b4:
	/* 0x24b4: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_24bb:
	/* 0x24bb: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24c0:
	/* 0x24c0: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	goto x86_l_24e4;
x86_l_24c2:
	/* 0x24c2: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24c7:
	/* 0x24c7: jmp    2410 <generic_retkprobe_event+0x2410> */
	goto x86_l_2410;
x86_l_24cc:
	/* 0x24cc: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24d1:
	/* 0x24d1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24d8:
	/* 0x24d8: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24dd:
	/* 0x24dd: jmp    24e4 <generic_retkprobe_event+0x24e4> */
	goto x86_l_24e4;
x86_l_24df:
	/* 0x24df: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24e4:
	/* 0x24e4: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24e9:
	/* 0x24e9: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ee:
	/* 0x24ee: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_24f3:
	/* 0x24f3: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_24f7:
	/* 0x24f7: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_24fd:
	/* 0x24fd: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2507:
	/* 0x2507: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_250b:
	/* 0x250b: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_2511:
	/* 0x2511: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2515:
	/* 0x2515: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2518:
	/* 0x2518: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_251b:
	/* 0x251b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2520:
	/* 0x2520: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2525:
	/* 0x2525: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2528:
	/* 0x2528: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_252d:
	/* 0x252d: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2530:
	/* 0x2530: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2535:
	/* 0x2535: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2537:
	/* 0x2537: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_253a:
	/* 0x253a: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_2540:
	/* 0x2540: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2545:
	/* 0x2545: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2548:
	/* 0x2548: jg     2565 <generic_retkprobe_event+0x2565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2565;
	}
x86_l_254a:
	/* 0x254a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_254c:
	/* 0x254c: je     2583 <generic_retkprobe_event+0x2583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2583;
	}
x86_l_254e:
	/* 0x254e: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2551:
	/* 0x2551: je     2583 <generic_retkprobe_event+0x2583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2583;
	}
x86_l_2553:
	/* 0x2553: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2556:
	/* 0x2556: jne    25a9 <generic_retkprobe_event+0x25a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25a9;
	}
x86_l_2558:
	/* 0x2558: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_255f:
	/* 0x255f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2563:
	/* 0x2563: jmp    25ae <generic_retkprobe_event+0x25ae> */
	goto x86_l_25ae;
x86_l_2565:
	/* 0x2565: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2568:
	/* 0x2568: je     2596 <generic_retkprobe_event+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2596;
	}
x86_l_256a:
	/* 0x256a: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_256d:
	/* 0x256d: je     2583 <generic_retkprobe_event+0x2583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2583;
	}
x86_l_256f:
	/* 0x256f: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2574:
	/* 0x2574: jne    25a9 <generic_retkprobe_event+0x25a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25a9;
	}
x86_l_2576:
	/* 0x2576: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_257d:
	/* 0x257d: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2581:
	/* 0x2581: jmp    25ae <generic_retkprobe_event+0x25ae> */
	goto x86_l_25ae;
x86_l_2583:
	/* 0x2583: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2588:
	/* 0x2588: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_258f:
	/* 0x258f: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2594:
	/* 0x2594: jmp    25ae <generic_retkprobe_event+0x25ae> */
	goto x86_l_25ae;
x86_l_2596:
	/* 0x2596: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_259b:
	/* 0x259b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25a2:
	/* 0x25a2: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25a7:
	/* 0x25a7: jmp    25ae <generic_retkprobe_event+0x25ae> */
	goto x86_l_25ae;
x86_l_25a9:
	/* 0x25a9: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_25ae:
	/* 0x25ae: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25b3:
	/* 0x25b3: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b8:
	/* 0x25b8: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_25bd:
	/* 0x25bd: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_25c1:
	/* 0x25c1: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_25c7:
	/* 0x25c7: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25d1:
	/* 0x25d1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25d5:
	/* 0x25d5: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_25db:
	/* 0x25db: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_25df:
	/* 0x25df: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_25e2:
	/* 0x25e2: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25e5:
	/* 0x25e5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_25ea:
	/* 0x25ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ef:
	/* 0x25ef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_25f2:
	/* 0x25f2: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25f7:
	/* 0x25f7: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25fa:
	/* 0x25fa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_25ff:
	/* 0x25ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2601:
	/* 0x2601: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2604:
	/* 0x2604: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_260a:
	/* 0x260a: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_260f:
	/* 0x260f: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2612:
	/* 0x2612: jg     262f <generic_retkprobe_event+0x262f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_262f;
	}
x86_l_2614:
	/* 0x2614: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2616:
	/* 0x2616: je     264d <generic_retkprobe_event+0x264d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264d;
	}
x86_l_2618:
	/* 0x2618: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_261b:
	/* 0x261b: je     264d <generic_retkprobe_event+0x264d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264d;
	}
x86_l_261d:
	/* 0x261d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2620:
	/* 0x2620: jne    2673 <generic_retkprobe_event+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2673;
	}
x86_l_2622:
	/* 0x2622: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2629:
	/* 0x2629: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_262d:
	/* 0x262d: jmp    2678 <generic_retkprobe_event+0x2678> */
	goto x86_l_2678;
x86_l_262f:
	/* 0x262f: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2632:
	/* 0x2632: je     2660 <generic_retkprobe_event+0x2660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2660;
	}
x86_l_2634:
	/* 0x2634: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2637:
	/* 0x2637: je     264d <generic_retkprobe_event+0x264d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264d;
	}
x86_l_2639:
	/* 0x2639: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_263e:
	/* 0x263e: jne    2673 <generic_retkprobe_event+0x2673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2673;
	}
x86_l_2640:
	/* 0x2640: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2647:
	/* 0x2647: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_264b:
	/* 0x264b: jmp    2678 <generic_retkprobe_event+0x2678> */
	goto x86_l_2678;
x86_l_264d:
	/* 0x264d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2652:
	/* 0x2652: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2659:
	/* 0x2659: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_265e:
	/* 0x265e: jmp    2678 <generic_retkprobe_event+0x2678> */
	goto x86_l_2678;
x86_l_2660:
	/* 0x2660: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2665:
	/* 0x2665: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_266c:
	/* 0x266c: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2671:
	/* 0x2671: jmp    2678 <generic_retkprobe_event+0x2678> */
	goto x86_l_2678;
x86_l_2673:
	/* 0x2673: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2678:
	/* 0x2678: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_267d:
	/* 0x267d: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2682:
	/* 0x2682: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2687:
	/* 0x2687: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_268b:
	/* 0x268b: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_2691:
	/* 0x2691: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_269b:
	/* 0x269b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_269f:
	/* 0x269f: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_26a5:
	/* 0x26a5: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26a9:
	/* 0x26a9: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26ac:
	/* 0x26ac: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26af:
	/* 0x26af: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_26b4:
	/* 0x26b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26b9:
	/* 0x26b9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_26bc:
	/* 0x26bc: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26c1:
	/* 0x26c1: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26c4:
	/* 0x26c4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_26c9:
	/* 0x26c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cb:
	/* 0x26cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26ce:
	/* 0x26ce: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_26d4:
	/* 0x26d4: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_26d9:
	/* 0x26d9: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_26dc:
	/* 0x26dc: jg     2700 <generic_retkprobe_event+0x2700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2700;
	}
x86_l_26de:
	/* 0x26de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26e0:
	/* 0x26e0: je     2729 <generic_retkprobe_event+0x2729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2729;
	}
x86_l_26e2:
	/* 0x26e2: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_26e5:
	/* 0x26e5: je     2729 <generic_retkprobe_event+0x2729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2729;
	}
x86_l_26e7:
	/* 0x26e7: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_26ea:
	/* 0x26ea: jne    2824 <generic_retkprobe_event+0x2824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2824;
	}
x86_l_26f0:
	/* 0x26f0: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_26f7:
	/* 0x26f7: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_26fb:
	/* 0x26fb: jmp    2829 <generic_retkprobe_event+0x2829> */
	goto x86_l_2829;
x86_l_2700:
	/* 0x2700: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2703:
	/* 0x2703: je     2811 <generic_retkprobe_event+0x2811> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2811;
	}
x86_l_2709:
	/* 0x2709: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_270c:
	/* 0x270c: je     2729 <generic_retkprobe_event+0x2729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2729;
	}
x86_l_270e:
	/* 0x270e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2713:
	/* 0x2713: jne    2824 <generic_retkprobe_event+0x2824> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2824;
	}
x86_l_2719:
	/* 0x2719: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2720:
	/* 0x2720: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2724:
	/* 0x2724: jmp    2829 <generic_retkprobe_event+0x2829> */
	goto x86_l_2829;
x86_l_2729:
	/* 0x2729: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_272e:
	/* 0x272e: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2735:
	/* 0x2735: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_273a:
	/* 0x273a: jmp    2829 <generic_retkprobe_event+0x2829> */
	goto x86_l_2829;
x86_l_273f:
	/* 0x273f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2741:
	/* 0x2741: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2746:
	/* 0x2746: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_274f:
	/* 0x274f: jb     2334 <generic_retkprobe_event+0x2334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9012ULL;
	}
x86_l_2755:
	/* 0x2755: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_275d:
	/* 0x275d: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2761:
	/* 0x2761: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2766:
	/* 0x2766: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_276c:
	/* 0x276c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2771:
	/* 0x2771: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2776:
	/* 0x2776: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_277b:
	/* 0x277b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277d:
	/* 0x277d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2782:
	/* 0x2782: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2784:
	/* 0x2784: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12596ULL;
	}
x86_l_278a:
	/* 0x278a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_278f:
	/* 0x278f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2794:
	/* 0x2794: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2797:
	/* 0x2797: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_279a:
	/* 0x279a: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_279e:
	/* 0x279e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a1:
	/* 0x27a1: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_27a5:
	/* 0x27a5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27aa:
	/* 0x27aa: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ae:
	/* 0x27ae: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_27b5:
	/* 0x27b5: ja     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12596ULL;
	}
x86_l_27bb:
	/* 0x27bb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_27be:
	/* 0x27be: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27c1:
	/* 0x27c1: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_27c4:
	/* 0x27c4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27ca:
	/* 0x27ca: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27cf:
	/* 0x27cf: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d4:
	/* 0x27d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27d9:
	/* 0x27d9: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27dd:
	/* 0x27dd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27e2:
	/* 0x27e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e4:
	/* 0x27e4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27e9:
	/* 0x27e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27eb:
	/* 0x27eb: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12596ULL;
	}
x86_l_27f1:
	/* 0x27f1: add    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27f5:
	/* 0x27f5: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_27fb:
	/* 0x27fb: je     2fc8 <generic_retkprobe_event+0x2fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12232ULL;
	}
x86_l_2801:
	/* 0x2801: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_2806:
	/* 0x2806: jne    2fcf <generic_retkprobe_event+0x2fcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12239ULL;
	}
x86_l_280c:
	/* 0x280c: jmp    2334 <generic_retkprobe_event+0x2334> */
	return 9012ULL;
x86_l_2811:
	/* 0x2811: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2816:
	/* 0x2816: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_281d:
	/* 0x281d: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2822:
	/* 0x2822: jmp    2829 <generic_retkprobe_event+0x2829> */
	goto x86_l_2829;
x86_l_2824:
	/* 0x2824: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2829:
	/* 0x2829: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_282e:
	/* 0x282e: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2833:
	/* 0x2833: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2838:
	/* 0x2838: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_283c:
	/* 0x283c: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_2842:
	/* 0x2842: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_284c:
	/* 0x284c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2850:
	/* 0x2850: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_2856:
	/* 0x2856: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_285a:
	/* 0x285a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_285d:
	/* 0x285d: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2860:
	/* 0x2860: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2865:
	/* 0x2865: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_286a:
	/* 0x286a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_286d:
	/* 0x286d: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2872:
	/* 0x2872: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2875:
	/* 0x2875: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_287a:
	/* 0x287a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287c:
	/* 0x287c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_287f:
	/* 0x287f: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_2885:
	/* 0x2885: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_288a:
	/* 0x288a: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_288d:
	/* 0x288d: jg     28aa <generic_retkprobe_event+0x28aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_28aa;
	}
x86_l_288f:
	/* 0x288f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2891:
	/* 0x2891: je     28c8 <generic_retkprobe_event+0x28c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c8;
	}
x86_l_2893:
	/* 0x2893: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2896:
	/* 0x2896: je     28c8 <generic_retkprobe_event+0x28c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c8;
	}
x86_l_2898:
	/* 0x2898: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_289b:
	/* 0x289b: jne    28ee <generic_retkprobe_event+0x28ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ee;
	}
x86_l_289d:
	/* 0x289d: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_28a4:
	/* 0x28a4: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_28a8:
	/* 0x28a8: jmp    28f3 <generic_retkprobe_event+0x28f3> */
	goto x86_l_28f3;
x86_l_28aa:
	/* 0x28aa: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_28ad:
	/* 0x28ad: je     28db <generic_retkprobe_event+0x28db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28db;
	}
x86_l_28af:
	/* 0x28af: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_28b2:
	/* 0x28b2: je     28c8 <generic_retkprobe_event+0x28c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c8;
	}
x86_l_28b4:
	/* 0x28b4: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_28b9:
	/* 0x28b9: jne    28ee <generic_retkprobe_event+0x28ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ee;
	}
x86_l_28bb:
	/* 0x28bb: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_28c2:
	/* 0x28c2: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_28c6:
	/* 0x28c6: jmp    28f3 <generic_retkprobe_event+0x28f3> */
	goto x86_l_28f3;
x86_l_28c8:
	/* 0x28c8: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_28cd:
	/* 0x28cd: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_28d4:
	/* 0x28d4: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28d9:
	/* 0x28d9: jmp    28f3 <generic_retkprobe_event+0x28f3> */
	goto x86_l_28f3;
x86_l_28db:
	/* 0x28db: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_28e0:
	/* 0x28e0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_28e7:
	/* 0x28e7: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28ec:
	/* 0x28ec: jmp    28f3 <generic_retkprobe_event+0x28f3> */
	goto x86_l_28f3;
x86_l_28ee:
	/* 0x28ee: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_28f3:
	/* 0x28f3: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28f8:
	/* 0x28f8: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28fd:
	/* 0x28fd: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2902:
	/* 0x2902: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2906:
	/* 0x2906: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_290c:
	/* 0x290c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2916:
	/* 0x2916: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_291a:
	/* 0x291a: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_2920:
	/* 0x2920: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2924:
	/* 0x2924: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2927:
	/* 0x2927: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_292a:
	/* 0x292a: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_292f:
	/* 0x292f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2934:
	/* 0x2934: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2937:
	/* 0x2937: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_293c:
	/* 0x293c: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_293f:
	/* 0x293f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2944:
	/* 0x2944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2946:
	/* 0x2946: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2949:
	/* 0x2949: js     2a10 <generic_retkprobe_event+0x2a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a10;
	}
x86_l_294f:
	/* 0x294f: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2954:
	/* 0x2954: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2957:
	/* 0x2957: jg     2974 <generic_retkprobe_event+0x2974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2974;
	}
x86_l_2959:
	/* 0x2959: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_295b:
	/* 0x295b: je     2992 <generic_retkprobe_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_295d:
	/* 0x295d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2960:
	/* 0x2960: je     2992 <generic_retkprobe_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_2962:
	/* 0x2962: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2965:
	/* 0x2965: jne    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b8;
	}
x86_l_2967:
	/* 0x2967: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_296e:
	/* 0x296e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2972:
	/* 0x2972: jmp    29bd <generic_retkprobe_event+0x29bd> */
	goto x86_l_29bd;
x86_l_2974:
	/* 0x2974: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2977:
	/* 0x2977: je     29a5 <generic_retkprobe_event+0x29a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29a5;
	}
x86_l_2979:
	/* 0x2979: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_297c:
	/* 0x297c: je     2992 <generic_retkprobe_event+0x2992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2992;
	}
x86_l_297e:
	/* 0x297e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2983:
	/* 0x2983: jne    29b8 <generic_retkprobe_event+0x29b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29b8;
	}
x86_l_2985:
	/* 0x2985: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_298c:
	/* 0x298c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2990:
	/* 0x2990: jmp    29bd <generic_retkprobe_event+0x29bd> */
	goto x86_l_29bd;
x86_l_2992:
	/* 0x2992: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2997:
	/* 0x2997: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_299e:
	/* 0x299e: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29a3:
	/* 0x29a3: jmp    29bd <generic_retkprobe_event+0x29bd> */
	goto x86_l_29bd;
x86_l_29a5:
	/* 0x29a5: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_29aa:
	/* 0x29aa: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_29b1:
	/* 0x29b1: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_29b6:
	/* 0x29b6: jmp    29bd <generic_retkprobe_event+0x29bd> */
	goto x86_l_29bd;
x86_l_29b8:
	/* 0x29b8: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_29bd:
	/* 0x29bd: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29c2:
	/* 0x29c2: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c7:
	/* 0x29c7: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_29cc:
	/* 0x29cc: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_29d0:
	/* 0x29d0: ja     2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 12219ULL;
	}
x86_l_29d6:
	/* 0x29d6: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_29e0:
	/* 0x29e0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_29e4:
	/* 0x29e4: jae    2fbb <generic_retkprobe_event+0x2fbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12219ULL;
	}
x86_l_29ea:
	/* 0x29ea: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_29ee:
	/* 0x29ee: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29f1:
	/* 0x29f1: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29f4:
	/* 0x29f4: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_29f9:
	/* 0x29f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29fe:
	/* 0x29fe: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a03:
	/* 0x2a03: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a06:
	/* 0x2a06: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2a09:
	/* 0x2a09: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2a0e:
	/* 0x2a0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a10:
	/* 0x2a10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a12:
	/* 0x2a12: mov    BYTE PTR [rsp+0xc8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2a19:
	/* 0x2a19: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2a1c:
	/* 0x2a1c: mov    r14,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a20:
	/* 0x2a20: mov    WORD PTR [r14+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2a28:
	/* 0x2a28: mov    WORD PTR [r14+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_2a32:
	/* 0x2a32: mov    r12,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a3a:
	/* 0x2a3a: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a44:
	/* 0x2a44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a49:
	/* 0x2a49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a53:
	/* 0x2a53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a55:
	/* 0x2a55: lea    rdi,[r14+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2a5c:
	/* 0x2a5c: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2a60:
	/* 0x2a60: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2a65:
	/* 0x2a65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 10858ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10868ULL: goto x86_l_2a74;
	case 10876ULL: goto x86_l_2a7c;
	case 10879ULL: goto x86_l_2a7f;
	case 10881ULL: goto x86_l_2a81;
	case 10884ULL: goto x86_l_2a84;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10912ULL: goto x86_l_2aa0;
	case 10919ULL: goto x86_l_2aa7;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10936ULL: goto x86_l_2ab8;
	case 10943ULL: goto x86_l_2abf;
	case 10947ULL: goto x86_l_2ac3;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10963ULL: goto x86_l_2ad3;
	case 10968ULL: goto x86_l_2ad8;
	case 10977ULL: goto x86_l_2ae1;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11009ULL: goto x86_l_2b01;
	case 11016ULL: goto x86_l_2b08;
	case 11020ULL: goto x86_l_2b0c;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11041ULL: goto x86_l_2b21;
	case 11043ULL: goto x86_l_2b23;
	case 11047ULL: goto x86_l_2b27;
	case 11057ULL: goto x86_l_2b31;
	case 11061ULL: goto x86_l_2b35;
	case 11068ULL: goto x86_l_2b3c;
	case 11075ULL: goto x86_l_2b43;
	case 11084ULL: goto x86_l_2b4c;
	case 11093ULL: goto x86_l_2b55;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11129ULL: goto x86_l_2b79;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11145ULL: goto x86_l_2b89;
	case 11153ULL: goto x86_l_2b91;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11192ULL: goto x86_l_2bb8;
	case 11196ULL: goto x86_l_2bbc;
	case 11200ULL: goto x86_l_2bc0;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11219ULL: goto x86_l_2bd3;
	case 11222ULL: goto x86_l_2bd6;
	case 11229ULL: goto x86_l_2bdd;
	case 11233ULL: goto x86_l_2be1;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11249ULL: goto x86_l_2bf1;
	case 11255ULL: goto x86_l_2bf7;
	case 11259ULL: goto x86_l_2bfb;
	case 11264ULL: goto x86_l_2c00;
	case 11270ULL: goto x86_l_2c06;
	case 11273ULL: goto x86_l_2c09;
	case 11277ULL: goto x86_l_2c0d;
	case 11279ULL: goto x86_l_2c0f;
	case 11286ULL: goto x86_l_2c16;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11305ULL: goto x86_l_2c29;
	case 11315ULL: goto x86_l_2c33;
	case 11323ULL: goto x86_l_2c3b;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11335ULL: goto x86_l_2c47;
	case 11341ULL: goto x86_l_2c4d;
	case 11348ULL: goto x86_l_2c54;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11363ULL: goto x86_l_2c63;
	case 11370ULL: goto x86_l_2c6a;
	case 11377ULL: goto x86_l_2c71;
	case 11380ULL: goto x86_l_2c74;
	case 11386ULL: goto x86_l_2c7a;
	case 11389ULL: goto x86_l_2c7d;
	case 11395ULL: goto x86_l_2c83;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11411ULL: goto x86_l_2c93;
	case 11419ULL: goto x86_l_2c9b;
	case 11427ULL: goto x86_l_2ca3;
	case 11434ULL: goto x86_l_2caa;
	case 11440ULL: goto x86_l_2cb0;
	case 11444ULL: goto x86_l_2cb4;
	case 11448ULL: goto x86_l_2cb8;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11472ULL: goto x86_l_2cd0;
	case 11476ULL: goto x86_l_2cd4;
	case 11482ULL: goto x86_l_2cda;
	case 11485ULL: goto x86_l_2cdd;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11500ULL: goto x86_l_2cec;
	case 11504ULL: goto x86_l_2cf0;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11515ULL: goto x86_l_2cfb;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11553ULL: goto x86_l_2d21;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11588ULL: goto x86_l_2d44;
	case 11595ULL: goto x86_l_2d4b;
	case 11599ULL: goto x86_l_2d4f;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11618ULL: goto x86_l_2d62;
	case 11621ULL: goto x86_l_2d65;
	case 11623ULL: goto x86_l_2d67;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11660ULL: goto x86_l_2d8c;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11677ULL: goto x86_l_2d9d;
	case 11682ULL: goto x86_l_2da2;
	case 11685ULL: goto x86_l_2da5;
	case 11691ULL: goto x86_l_2dab;
	case 11698ULL: goto x86_l_2db2;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11733ULL: goto x86_l_2dd5;
	case 11740ULL: goto x86_l_2ddc;
	case 11744ULL: goto x86_l_2de0;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11792ULL: goto x86_l_2e10;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11805ULL: goto x86_l_2e1d;
	case 11810ULL: goto x86_l_2e22;
	case 11815ULL: goto x86_l_2e27;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11827ULL: goto x86_l_2e33;
	case 11830ULL: goto x86_l_2e36;
	case 11836ULL: goto x86_l_2e3c;
	case 11843ULL: goto x86_l_2e43;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11878ULL: goto x86_l_2e66;
	case 11885ULL: goto x86_l_2e6d;
	case 11889ULL: goto x86_l_2e71;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11908ULL: goto x86_l_2e84;
	case 11911ULL: goto x86_l_2e87;
	case 11913ULL: goto x86_l_2e89;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11945ULL: goto x86_l_2ea9;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11967ULL: goto x86_l_2ebf;
	case 11972ULL: goto x86_l_2ec4;
	case 11975ULL: goto x86_l_2ec7;
	case 11981ULL: goto x86_l_2ecd;
	case 11988ULL: goto x86_l_2ed4;
	case 11996ULL: goto x86_l_2edc;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12011ULL: goto x86_l_2eeb;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12023ULL: goto x86_l_2ef7;
	case 12030ULL: goto x86_l_2efe;
	case 12034ULL: goto x86_l_2f02;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12056ULL: goto x86_l_2f18;
	case 12058ULL: goto x86_l_2f1a;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12091ULL: goto x86_l_2f3b;
	case 12096ULL: goto x86_l_2f40;
	case 12101ULL: goto x86_l_2f45;
	case 12106ULL: goto x86_l_2f4a;
	case 12108ULL: goto x86_l_2f4c;
	case 12111ULL: goto x86_l_2f4f;
	case 12117ULL: goto x86_l_2f55;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12128ULL: goto x86_l_2f60;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12140ULL: goto x86_l_2f6c;
	case 12143ULL: goto x86_l_2f6f;
	case 12147ULL: goto x86_l_2f73;
	case 12151ULL: goto x86_l_2f77;
	case 12158ULL: goto x86_l_2f7e;
	case 12162ULL: goto x86_l_2f82;
	case 12166ULL: goto x86_l_2f86;
	case 12170ULL: goto x86_l_2f8a;
	case 12177ULL: goto x86_l_2f91;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12190ULL: goto x86_l_2f9e;
	case 12195ULL: goto x86_l_2fa3;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12211ULL: goto x86_l_2fb3;
	case 12213ULL: goto x86_l_2fb5;
	case 12214ULL: goto x86_l_2fb6;
	case 12219ULL: goto x86_l_2fbb;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12262ULL: goto x86_l_2fe6;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12292ULL: goto x86_l_3004;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12301ULL: goto x86_l_300d;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12320ULL: goto x86_l_3020;
	case 12323ULL: goto x86_l_3023;
	case 12327ULL: goto x86_l_3027;
	case 12330ULL: goto x86_l_302a;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12346ULL: goto x86_l_303a;
	case 12352ULL: goto x86_l_3040;
	case 12356ULL: goto x86_l_3044;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12368ULL: goto x86_l_3050;
	case 12373ULL: goto x86_l_3055;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12391ULL: goto x86_l_3067;
	case 12393ULL: goto x86_l_3069;
	case 12398ULL: goto x86_l_306e;
	case 12400ULL: goto x86_l_3070;
	case 12406ULL: goto x86_l_3076;
	case 12409ULL: goto x86_l_3079;
	case 12415ULL: goto x86_l_307f;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12424ULL: goto x86_l_3088;
	case 12429ULL: goto x86_l_308d;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12445ULL: goto x86_l_309d;
	case 12451ULL: goto x86_l_30a3;
	case 12459ULL: goto x86_l_30ab;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12484ULL: goto x86_l_30c4;
	case 12489ULL: goto x86_l_30c9;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12498ULL: goto x86_l_30d2;
	case 12500ULL: goto x86_l_30d4;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12513ULL: goto x86_l_30e1;
	case 12516ULL: goto x86_l_30e4;
	case 12520ULL: goto x86_l_30e8;
	case 12523ULL: goto x86_l_30eb;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12539ULL: goto x86_l_30fb;
	case 12541ULL: goto x86_l_30fd;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12566ULL: goto x86_l_3116;
	case 12571ULL: goto x86_l_311b;
	case 12574ULL: goto x86_l_311e;
	case 12577ULL: goto x86_l_3121;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12586ULL: goto x86_l_312a;
	case 12588ULL: goto x86_l_312c;
	case 12591ULL: goto x86_l_312f;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12606ULL: goto x86_l_313e;
	case 12610ULL: goto x86_l_3142;
	case 12615ULL: goto x86_l_3147;
	case 12616ULL: goto x86_l_3148;
	case 12618ULL: goto x86_l_314a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a6a:
	/* 0x2a6a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a6f:
	/* 0x2a6f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a72:
	/* 0x2a72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a74:
	/* 0x2a74: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_2a7c:
	/* 0x2a7c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2a7f:
	/* 0x2a7f: je     2ad3 <generic_retkprobe_event+0x2ad3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad3;
	}
x86_l_2a81:
	/* 0x2a81: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2a84:
	/* 0x2a84: jne    2b23 <generic_retkprobe_event+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b23;
	}
x86_l_2a8a:
	/* 0x2a8a: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a8f:
	/* 0x2a8f: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2a98:
	/* 0x2a98: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa0:
	/* 0x2aa0: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2aa7:
	/* 0x2aa7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2aac:
	/* 0x2aac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ab1:
	/* 0x2ab1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2ab6:
	/* 0x2ab6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ab8:
	/* 0x2ab8: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2abf:
	/* 0x2abf: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ac3:
	/* 0x2ac3: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2acc:
	/* 0x2acc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ad1:
	/* 0x2ad1: jmp    2b1a <generic_retkprobe_event+0x2b1a> */
	goto x86_l_2b1a;
x86_l_2ad3:
	/* 0x2ad3: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ad8:
	/* 0x2ad8: movzx  r12d,WORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 208ULL);
x86_l_2ae1:
	/* 0x2ae1: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2ae5:
	/* 0x2ae5: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae9:
	/* 0x2ae9: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2af0:
	/* 0x2af0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2af5:
	/* 0x2af5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2afa:
	/* 0x2afa: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2aff:
	/* 0x2aff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b01:
	/* 0x2b01: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2b08:
	/* 0x2b08: lea    rdx,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2b0c:
	/* 0x2b0c: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2b10:
	/* 0x2b10: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2b15:
	/* 0x2b15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2b1f:
	/* 0x2b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b21:
	/* 0x2b21: jmp    2b31 <generic_retkprobe_event+0x2b31> */
	goto x86_l_2b31;
x86_l_2b23:
	/* 0x2b23: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b27:
	/* 0x2b27: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2b31:
	/* 0x2b31: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b35:
	/* 0x2b35: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2b3c:
	/* 0x2b3c: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2b43:
	/* 0x2b43: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_2b4c:
	/* 0x2b4c: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_2b55:
	/* 0x2b55: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2b5c:
	/* 0x2b5c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b61:
	/* 0x2b61: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b66:
	/* 0x2b66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2b71:
	/* 0x2b71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b76:
	/* 0x2b76: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2b79:
	/* 0x2b79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7b:
	/* 0x2b7b: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b80:
	/* 0x2b80: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2b83:
	/* 0x2b83: je     2bf1 <generic_retkprobe_event+0x2bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf1;
	}
x86_l_2b85:
	/* 0x2b85: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2b89:
	/* 0x2b89: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b91:
	/* 0x2b91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b96:
	/* 0x2b96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ba0:
	/* 0x2ba0: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ba9:
	/* 0x2ba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bab:
	/* 0x2bab: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2bb8:
	/* 0x2bb8: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2bbc:
	/* 0x2bbc: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc0:
	/* 0x2bc0: lea    rdi,[rbp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_2bc7:
	/* 0x2bc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bd1:
	/* 0x2bd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd3:
	/* 0x2bd3: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2bd6:
	/* 0x2bd6: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2bdd:
	/* 0x2bdd: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2be1:
	/* 0x2be1: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2be5:
	/* 0x2be5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bea:
	/* 0x2bea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2bef:
	/* 0x2bef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf1:
	/* 0x2bf1: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bfb:
	/* 0x2bfb: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c00:
	/* 0x2c00: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2c06:
	/* 0x2c06: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_2c09:
	/* 0x2c09: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c0d:
	/* 0x2c0d: js     2c1f <generic_retkprobe_event+0x2c1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c1f;
	}
x86_l_2c0f:
	/* 0x2c0f: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2c16:
	/* 0x2c16: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2c1d:
	/* 0x2c1d: jmp    2c33 <generic_retkprobe_event+0x2c33> */
	goto x86_l_2c33;
x86_l_2c1f:
	/* 0x2c1f: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_2c29:
	/* 0x2c29: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_2c33:
	/* 0x2c33: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2c3b:
	/* 0x2c3b: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    eax,DWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c44:
	/* 0x2c44: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2c47:
	/* 0x2c47: jne    292 <generic_retkprobe_event+0x292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 658ULL;
	}
x86_l_2c4d:
	/* 0x2c4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_2c54:
	/* 0x2c54: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c61:
	/* 0x2c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c63:
	/* 0x2c63: and    r14d,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_2c6a:
	/* 0x2c6a: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2c71:
	/* 0x2c71: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2c74:
	/* 0x2c74: je     194 <generic_retkprobe_event+0x194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 404ULL;
	}
x86_l_2c7a:
	/* 0x2c7a: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2c7d:
	/* 0x2c7d: jne    2d0b <generic_retkprobe_event+0x2d0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d0b;
	}
x86_l_2c83:
	/* 0x2c83: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c90:
	/* 0x2c90: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2c93:
	/* 0x2c93: mov    DWORD PTR [r15+r14*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2c9b:
	/* 0x2c9b: mov    rbx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2ca3:
	/* 0x2ca3: cmp    rbx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4095ULL);
x86_l_2caa:
	/* 0x2caa: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2cb0:
	/* 0x2cb0: cmovb  r12,rbx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBX, X86_WIDTH_64, X86_CC_B);
x86_l_2cb4:
	/* 0x2cb4: lea    rdi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2cb8:
	/* 0x2cb8: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2cbc:
	/* 0x2cbc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cc1:
	/* 0x2cc1: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2cc9:
	/* 0x2cc9: lea    r13,[r14+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ccd:
	/* 0x2ccd: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cd0:
	/* 0x2cd0: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2cd4:
	/* 0x2cd4: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_2cda:
	/* 0x2cda: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2cdd:
	/* 0x2cdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdf:
	/* 0x2cdf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2ce4:
	/* 0x2ce4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ce6:
	/* 0x2ce6: js     2cf5 <generic_retkprobe_event+0x2cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2cf5;
	}
x86_l_2ce8:
	/* 0x2ce8: mov    DWORD PTR [r15+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cec:
	/* 0x2cec: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_2cf2:
	/* 0x2cf2: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_2cf5:
	/* 0x2cf5: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cf8:
	/* 0x2cf8: mov    DWORD PTR [r15],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_2cfe:
	/* 0x2cfe: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d03:
	/* 0x2d03: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2d10:
	/* 0x2d10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d12:
	/* 0x2d12: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2d15:
	/* 0x2d15: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d1a:
	/* 0x2d1a: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2d21:
	/* 0x2d21: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2d29:
	/* 0x2d29: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d33:
	/* 0x2d33: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2d38:
	/* 0x2d38: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d42:
	/* 0x2d42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d44:
	/* 0x2d44: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d4f:
	/* 0x2d4f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2d56:
	/* 0x2d56: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d60:
	/* 0x2d60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d62:
	/* 0x2d62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d65:
	/* 0x2d65: je     2d75 <generic_retkprobe_event+0x2d75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d75;
	}
x86_l_2d67:
	/* 0x2d67: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2d6a:
	/* 0x2d6a: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2d6f:
	/* 0x2d6f: jne    2f4f <generic_retkprobe_event+0x2f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f4f;
	}
x86_l_2d75:
	/* 0x2d75: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d7f:
	/* 0x2d7f: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d82:
	/* 0x2d82: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d87:
	/* 0x2d87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d91:
	/* 0x2d91: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2d96:
	/* 0x2d96: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d9b:
	/* 0x2d9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d9d:
	/* 0x2d9d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2da2:
	/* 0x2da2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2da5:
	/* 0x2da5: je     2f4c <generic_retkprobe_event+0x2f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4c;
	}
x86_l_2dab:
	/* 0x2dab: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2db2:
	/* 0x2db2: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2dba:
	/* 0x2dba: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dc4:
	/* 0x2dc4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2dc9:
	/* 0x2dc9: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2dce:
	/* 0x2dce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2dd3:
	/* 0x2dd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd5:
	/* 0x2dd5: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2ddc:
	/* 0x2ddc: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2de0:
	/* 0x2de0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2de7:
	/* 0x2de7: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2dec:
	/* 0x2dec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2df1:
	/* 0x2df1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df3:
	/* 0x2df3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2df6:
	/* 0x2df6: je     2e06 <generic_retkprobe_event+0x2e06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e06;
	}
x86_l_2df8:
	/* 0x2df8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2dfb:
	/* 0x2dfb: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e00:
	/* 0x2e00: jne    2f4f <generic_retkprobe_event+0x2f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f4f;
	}
x86_l_2e06:
	/* 0x2e06: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e10:
	/* 0x2e10: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e13:
	/* 0x2e13: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e18:
	/* 0x2e18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e1d:
	/* 0x2e1d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e22:
	/* 0x2e22: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2e27:
	/* 0x2e27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e2c:
	/* 0x2e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2e:
	/* 0x2e2e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e33:
	/* 0x2e33: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2e36:
	/* 0x2e36: je     2f4c <generic_retkprobe_event+0x2f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4c;
	}
x86_l_2e3c:
	/* 0x2e3c: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2e43:
	/* 0x2e43: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2e50:
	/* 0x2e50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e55:
	/* 0x2e55: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2e5a:
	/* 0x2e5a: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e64:
	/* 0x2e64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e66:
	/* 0x2e66: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2e6d:
	/* 0x2e6d: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e71:
	/* 0x2e71: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2e78:
	/* 0x2e78: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e82:
	/* 0x2e82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e84:
	/* 0x2e84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e87:
	/* 0x2e87: je     2e97 <generic_retkprobe_event+0x2e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e97;
	}
x86_l_2e89:
	/* 0x2e89: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2e8c:
	/* 0x2e8c: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e91:
	/* 0x2e91: jne    2f4f <generic_retkprobe_event+0x2f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f4f;
	}
x86_l_2e97:
	/* 0x2e97: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ea1:
	/* 0x2ea1: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ea4:
	/* 0x2ea4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eae:
	/* 0x2eae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb3:
	/* 0x2eb3: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebd:
	/* 0x2ebd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ebf:
	/* 0x2ebf: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ec4:
	/* 0x2ec4: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2ec7:
	/* 0x2ec7: je     2f4c <generic_retkprobe_event+0x2f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4c;
	}
x86_l_2ecd:
	/* 0x2ecd: add    rcx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_2ed4:
	/* 0x2ed4: lea    rdi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2edc:
	/* 0x2edc: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2ee1:
	/* 0x2ee1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ee6:
	/* 0x2ee6: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2eeb:
	/* 0x2eeb: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2ef0:
	/* 0x2ef0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ef5:
	/* 0x2ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef7:
	/* 0x2ef7: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2efe:
	/* 0x2efe: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f02:
	/* 0x2f02: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2f09:
	/* 0x2f09: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f0e:
	/* 0x2f0e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f13:
	/* 0x2f13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f15:
	/* 0x2f15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f18:
	/* 0x2f18: je     2f24 <generic_retkprobe_event+0x2f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f24;
	}
x86_l_2f1a:
	/* 0x2f1a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2f1d:
	/* 0x2f1d: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f22:
	/* 0x2f22: jne    2f4f <generic_retkprobe_event+0x2f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f4f;
	}
x86_l_2f24:
	/* 0x2f24: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2f29:
	/* 0x2f29: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f2e:
	/* 0x2f2e: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f31:
	/* 0x2f31: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f36:
	/* 0x2f36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f3b:
	/* 0x2f3b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f40:
	/* 0x2f40: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_2f45:
	/* 0x2f45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4a:
	/* 0x2f4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f4c:
	/* 0x2f4c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f4f:
	/* 0x2f4f: mov    DWORD PTR [rbx],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2f55:
	/* 0x2f55: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f59:
	/* 0x2f59: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2f5e:
	/* 0x2f5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f60:
	/* 0x2f60: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f64:
	/* 0x2f64: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2f67:
	/* 0x2f67: je     2f77 <generic_retkprobe_event+0x2f77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f77;
	}
x86_l_2f69:
	/* 0x2f69: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6f:
	/* 0x2f6f: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f73:
	/* 0x2f73: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f77:
	/* 0x2f77: mov    DWORD PTR [rbx+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2f7e:
	/* 0x2f7e: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f82:
	/* 0x2f82: mov    QWORD PTR [rbx+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f86:
	/* 0x2f86: mov    DWORD PTR [rbx+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f8a:
	/* 0x2f8a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_2f91:
	/* 0x2f91: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2f96:
	/* 0x2f96: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2f9b:
	/* 0x2f9b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2f9e:
	/* 0x2f9e: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2fa3:
	/* 0x2fa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa5:
	/* 0x2fa5: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2faa:
	/* 0x2faa: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2fac:
	/* 0x2fac: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2fb3:
	/* 0x2fb3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2fb5:
	/* 0x2fb5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2fb6:
	/* 0x2fb6: jmp    32f6 <cwd_read_v61+0x1af> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2fbb:
	/* 0x2fbb: mov    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2fc3:
	/* 0x2fc3: jmp    2a12 <generic_retkprobe_event+0x2a12> */
	return 10770ULL;
x86_l_2fc8:
	/* 0x2fc8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fca:
	/* 0x2fca: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fcf:
	/* 0x2fcf: cmp    QWORD PTR [rsp+0x88],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552261ULL);
x86_l_2fd8:
	/* 0x2fd8: je     2334 <generic_retkprobe_event+0x2334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9012ULL;
	}
x86_l_2fde:
	/* 0x2fde: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2fe6:
	/* 0x2fe6: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fea:
	/* 0x2fea: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fef:
	/* 0x2fef: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2ff5:
	/* 0x2ff5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2ffa:
	/* 0x2ffa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fff:
	/* 0x2fff: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3004:
	/* 0x3004: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3006:
	/* 0x3006: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_300b:
	/* 0x300b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_300d:
	/* 0x300d: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3134;
	}
x86_l_3013:
	/* 0x3013: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3018:
	/* 0x3018: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301d:
	/* 0x301d: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_3020:
	/* 0x3020: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3023:
	/* 0x3023: cmovb  r12,r15 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R15, X86_WIDTH_64, X86_CC_B);
x86_l_3027:
	/* 0x3027: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_302a:
	/* 0x302a: cmovne r15,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_302e:
	/* 0x302e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_3033:
	/* 0x3033: cmp    r15,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4094ULL);
x86_l_303a:
	/* 0x303a: ja     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3134;
	}
x86_l_3040:
	/* 0x3040: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3044:
	/* 0x3044: add    rdi,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3047:
	/* 0x3047: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_304a:
	/* 0x304a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3050:
	/* 0x3050: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3055:
	/* 0x3055: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_305a:
	/* 0x305a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_305f:
	/* 0x305f: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3064:
	/* 0x3064: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3067:
	/* 0x3067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3069:
	/* 0x3069: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_306e:
	/* 0x306e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3070:
	/* 0x3070: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3134;
	}
x86_l_3076:
	/* 0x3076: add    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3079:
	/* 0x3079: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_307f:
	/* 0x307f: je     308d <generic_retkprobe_event+0x308d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_308d;
	}
x86_l_3081:
	/* 0x3081: sub    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 8ULL);
x86_l_3086:
	/* 0x3086: jne    3094 <generic_retkprobe_event+0x3094> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3094;
	}
x86_l_3088:
	/* 0x3088: jmp    2334 <generic_retkprobe_event+0x2334> */
	return 9012ULL;
x86_l_308d:
	/* 0x308d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_308f:
	/* 0x308f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3094:
	/* 0x3094: cmp    QWORD PTR [rsp+0x88],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552263ULL);
x86_l_309d:
	/* 0x309d: jb     2334 <generic_retkprobe_event+0x2334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9012ULL;
	}
x86_l_30a3:
	/* 0x30a3: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_30ab:
	/* 0x30ab: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_30af:
	/* 0x30af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30b4:
	/* 0x30b4: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_30ba:
	/* 0x30ba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_30bf:
	/* 0x30bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30c4:
	/* 0x30c4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30c9:
	/* 0x30c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30cb:
	/* 0x30cb: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_30d0:
	/* 0x30d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30d2:
	/* 0x30d2: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3134;
	}
x86_l_30d4:
	/* 0x30d4: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30d9:
	/* 0x30d9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30de:
	/* 0x30de: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_30e1:
	/* 0x30e1: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_30e4:
	/* 0x30e4: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_30e8:
	/* 0x30e8: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_30eb:
	/* 0x30eb: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_30ef:
	/* 0x30ef: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_30f4:
	/* 0x30f4: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_30fb:
	/* 0x30fb: ja     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3134;
	}
x86_l_30fd:
	/* 0x30fd: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3100:
	/* 0x3100: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3107:
	/* 0x3107: add    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_310c:
	/* 0x310c: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3111:
	/* 0x3111: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3116:
	/* 0x3116: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_311b:
	/* 0x311b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_311e:
	/* 0x311e: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_3121:
	/* 0x3121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3123:
	/* 0x3123: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_3128:
	/* 0x3128: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_312a:
	/* 0x312a: js     3134 <generic_retkprobe_event+0x3134> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3134;
	}
x86_l_312c:
	/* 0x312c: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_312f:
	/* 0x312f: jmp    2337 <generic_retkprobe_event+0x2337> */
	return 9015ULL;
x86_l_3134:
	/* 0x3134: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3139:
	/* 0x3139: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_313e:
	/* 0x313e: mov    DWORD PTR [rax+r14*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_3142:
	/* 0x3142: jmp    1884 <generic_retkprobe_event+0x1884> */
	return 6276ULL;
x86_l_3147:
	/* 0x3147: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3148:
	/* 0x3148: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_314a:
	/* 0x314a: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
	return 12620ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12624ULL: goto x86_l_3150;
	case 12625ULL: goto x86_l_3151;
	case 12629ULL: goto x86_l_3155;
	case 12632ULL: goto x86_l_3158;
	case 12636ULL: goto x86_l_315c;
	case 12640ULL: goto x86_l_3160;
	case 12644ULL: goto x86_l_3164;
	case 12647ULL: goto x86_l_3167;
	case 12649ULL: goto x86_l_3169;
	case 12653ULL: goto x86_l_316d;
	case 12659ULL: goto x86_l_3173;
	case 12663ULL: goto x86_l_3177;
	case 12668ULL: goto x86_l_317c;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12724ULL: goto x86_l_31b4;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12760ULL: goto x86_l_31d8;
	case 12762ULL: goto x86_l_31da;
	case 12766ULL: goto x86_l_31de;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12789ULL: goto x86_l_31f5;
	case 12791ULL: goto x86_l_31f7;
	case 12795ULL: goto x86_l_31fb;
	case 12799ULL: goto x86_l_31ff;
	case 12803ULL: goto x86_l_3203;
	case 12806ULL: goto x86_l_3206;
	case 12810ULL: goto x86_l_320a;
	case 12812ULL: goto x86_l_320c;
	case 12814ULL: goto x86_l_320e;
	case 12817ULL: goto x86_l_3211;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12834ULL: goto x86_l_3222;
	case 12836ULL: goto x86_l_3224;
	case 12840ULL: goto x86_l_3228;
	case 12842ULL: goto x86_l_322a;
	case 12845ULL: goto x86_l_322d;
	case 12847ULL: goto x86_l_322f;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12858ULL: goto x86_l_323a;
	case 12864ULL: goto x86_l_3240;
	case 12871ULL: goto x86_l_3247;
	case 12877ULL: goto x86_l_324d;
	case 12880ULL: goto x86_l_3250;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12892ULL: goto x86_l_325c;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12903ULL: goto x86_l_3267;
	case 12906ULL: goto x86_l_326a;
	case 12911ULL: goto x86_l_326f;
	case 12913ULL: goto x86_l_3271;
	case 12917ULL: goto x86_l_3275;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12927ULL: goto x86_l_327f;
	case 12932ULL: goto x86_l_3284;
	case 12935ULL: goto x86_l_3287;
	case 12937ULL: goto x86_l_3289;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12956ULL: goto x86_l_329c;
	case 12961ULL: goto x86_l_32a1;
	case 12963ULL: goto x86_l_32a3;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12974ULL: goto x86_l_32ae;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12988ULL: goto x86_l_32bc;
	case 12991ULL: goto x86_l_32bf;
	case 12996ULL: goto x86_l_32c4;
	case 12999ULL: goto x86_l_32c7;
	case 13001ULL: goto x86_l_32c9;
	case 13006ULL: goto x86_l_32ce;
	case 13010ULL: goto x86_l_32d2;
	case 13014ULL: goto x86_l_32d6;
	case 13018ULL: goto x86_l_32da;
	case 13020ULL: goto x86_l_32dc;
	case 13022ULL: goto x86_l_32de;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13035ULL: goto x86_l_32eb;
	case 13036ULL: goto x86_l_32ec;
	case 13038ULL: goto x86_l_32ee;
	case 13040ULL: goto x86_l_32f0;
	case 13042ULL: goto x86_l_32f2;
	case 13044ULL: goto x86_l_32f4;
	case 13045ULL: goto x86_l_32f5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_314c:
	/* 0x314c: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_314e:
	/* 0x314e: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3150:
	/* 0x3150: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3151:
	/* 0x3151: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_3155:
	/* 0x3155: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_3158:
	/* 0x3158: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_315c:
	/* 0x315c: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3160:
	/* 0x3160: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3164:
	/* 0x3164: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_3167:
	/* 0x3167: jne    3173 <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3173;
	}
x86_l_3169:
	/* 0x3169: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_316d:
	/* 0x316d: je     32de <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32de;
	}
x86_l_3173:
	/* 0x3173: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3177:
	/* 0x3177: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_317c:
	/* 0x317c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3181:
	/* 0x3181: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3186:
	/* 0x3186: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_318b:
	/* 0x318b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_318d:
	/* 0x318d: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3192:
	/* 0x3192: je     3289 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3289;
	}
x86_l_3198:
	/* 0x3198: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_319d:
	/* 0x319d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31a2:
	/* 0x31a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a7:
	/* 0x31a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ac:
	/* 0x31ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b1:
	/* 0x31b1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31b4:
	/* 0x31b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b6:
	/* 0x31b6: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31bb:
	/* 0x31bb: je     3289 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3289;
	}
x86_l_31c1:
	/* 0x31c1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c6:
	/* 0x31c6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31cb:
	/* 0x31cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31d0:
	/* 0x31d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31d5:
	/* 0x31d5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31d8:
	/* 0x31d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31da:
	/* 0x31da: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_31de:
	/* 0x31de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e3:
	/* 0x31e3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31e8:
	/* 0x31e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ed:
	/* 0x31ed: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31f2:
	/* 0x31f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31f5:
	/* 0x31f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f7:
	/* 0x31f7: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31fb:
	/* 0x31fb: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31ff:
	/* 0x31ff: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3203:
	/* 0x3203: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3206:
	/* 0x3206: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_320a:
	/* 0x320a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_320c:
	/* 0x320c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_320e:
	/* 0x320e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3211:
	/* 0x3211: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_3214:
	/* 0x3214: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3219:
	/* 0x3219: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_321b:
	/* 0x321b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_321e:
	/* 0x321e: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3222:
	/* 0x3222: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_3224:
	/* 0x3224: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_3228:
	/* 0x3228: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_322a:
	/* 0x322a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_322d:
	/* 0x322d: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_322f:
	/* 0x322f: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3232:
	/* 0x3232: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3237:
	/* 0x3237: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_323a:
	/* 0x323a: jb     32e7 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_32e7;
	}
x86_l_3240:
	/* 0x3240: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_3247:
	/* 0x3247: ja     32e7 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32e7;
	}
x86_l_324d:
	/* 0x324d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3250:
	/* 0x3250: jbe    3257 <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3257;
	}
x86_l_3252:
	/* 0x3252: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3257:
	/* 0x3257: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3259:
	/* 0x3259: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_325c:
	/* 0x325c: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_3260:
	/* 0x3260: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3264:
	/* 0x3264: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3267:
	/* 0x3267: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_326a:
	/* 0x326a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_326f:
	/* 0x326f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3271:
	/* 0x3271: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3275:
	/* 0x3275: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_3278:
	/* 0x3278: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_327d:
	/* 0x327d: jbe    32e7 <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32e7;
	}
x86_l_327f:
	/* 0x327f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3284:
	/* 0x3284: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3287:
	/* 0x3287: jmp    32da <cwd_read_v61+0x193> */
	goto x86_l_32da;
x86_l_3289:
	/* 0x3289: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328d:
	/* 0x328d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3292:
	/* 0x3292: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3297:
	/* 0x3297: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_329c:
	/* 0x329c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a1:
	/* 0x32a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a3:
	/* 0x32a3: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32a7:
	/* 0x32a7: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_32ac:
	/* 0x32ac: je     32de <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32de;
	}
x86_l_32ae:
	/* 0x32ae: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_32b2:
	/* 0x32b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32b7:
	/* 0x32b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32bc:
	/* 0x32bc: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_32bf:
	/* 0x32bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c4:
	/* 0x32c4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32c7:
	/* 0x32c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32c9:
	/* 0x32c9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ce:
	/* 0x32ce: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32d2:
	/* 0x32d2: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_32d6:
	/* 0x32d6: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32da:
	/* 0x32da: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32dc:
	/* 0x32dc: jmp    32e7 <cwd_read_v61+0x1a0> */
	goto x86_l_32e7;
x86_l_32de:
	/* 0x32de: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32e7:
	/* 0x32e7: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_32eb:
	/* 0x32eb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32ec:
	/* 0x32ec: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_32ee:
	/* 0x32ee: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_32f0:
	/* 0x32f0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_32f2:
	/* 0x32f2: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_32f4:
	/* 0x32f4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_32f5:
	/* 0x32f5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
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
	for (__u32 __x86_iter = 0; __x86_iter < 11216U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1836ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1842ULL && __x86_pc <= 3726ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3732ULL && __x86_pc <= 5603ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5606ULL && __x86_pc <= 7414ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7418ULL && __x86_pc <= 9215ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9220ULL && __x86_pc <= 10853ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10858ULL && __x86_pc <= 12618ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12620ULL && __x86_pc <= 13045ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

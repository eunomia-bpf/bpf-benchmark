extern char CONFIG_ITER_NUM;
extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 15ULL: goto x86_l_f;
	case 26ULL: goto x86_l_1a;
	case 31ULL: goto x86_l_1f;
	case 38ULL: goto x86_l_26;
	case 46ULL: goto x86_l_2e;
	case 48ULL: goto x86_l_30;
	case 51ULL: goto x86_l_33;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 100ULL: goto x86_l_64;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 121ULL: goto x86_l_79;
	case 129ULL: goto x86_l_81;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 150ULL: goto x86_l_96;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 171ULL: goto x86_l_ab;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 184ULL: goto x86_l_b8;
	case 192ULL: goto x86_l_c0;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 205ULL: goto x86_l_cd;
	case 213ULL: goto x86_l_d5;
	case 217ULL: goto x86_l_d9;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 249ULL: goto x86_l_f9;
	case 257ULL: goto x86_l_101;
	case 261ULL: goto x86_l_105;
	case 264ULL: goto x86_l_108;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 313ULL: goto x86_l_139;
	case 320ULL: goto x86_l_140;
	case 326ULL: goto x86_l_146;
	case 330ULL: goto x86_l_14a;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 339ULL: goto x86_l_153;
	case 341ULL: goto x86_l_155;
	case 345ULL: goto x86_l_159;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 357ULL: goto x86_l_165;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 371ULL: goto x86_l_173;
	case 377ULL: goto x86_l_179;
	case 380ULL: goto x86_l_17c;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 413ULL: goto x86_l_19d;
	case 419ULL: goto x86_l_1a3;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 434ULL: goto x86_l_1b2;
	case 442ULL: goto x86_l_1ba;
	case 448ULL: goto x86_l_1c0;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 460ULL: goto x86_l_1cc;
	case 466ULL: goto x86_l_1d2;
	case 469ULL: goto x86_l_1d5;
	case 475ULL: goto x86_l_1db;
	case 483ULL: goto x86_l_1e3;
	case 486ULL: goto x86_l_1e6;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 500ULL: goto x86_l_1f4;
	case 506ULL: goto x86_l_1fa;
	case 511ULL: goto x86_l_1ff;
	case 514ULL: goto x86_l_202;
	case 520ULL: goto x86_l_208;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 533ULL: goto x86_l_215;
	case 539ULL: goto x86_l_21b;
	case 544ULL: goto x86_l_220;
	case 547ULL: goto x86_l_223;
	case 553ULL: goto x86_l_229;
	case 556ULL: goto x86_l_22c;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 602ULL: goto x86_l_25a;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 624ULL: goto x86_l_270;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 645ULL: goto x86_l_285;
	case 649ULL: goto x86_l_289;
	case 654ULL: goto x86_l_28e;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 689ULL: goto x86_l_2b1;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 705ULL: goto x86_l_2c1;
	case 711ULL: goto x86_l_2c7;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 733ULL: goto x86_l_2dd;
	case 736ULL: goto x86_l_2e0;
	case 742ULL: goto x86_l_2e6;
	case 747ULL: goto x86_l_2eb;
	case 752ULL: goto x86_l_2f0;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 769ULL: goto x86_l_301;
	case 775ULL: goto x86_l_307;
	case 783ULL: goto x86_l_30f;
	case 786ULL: goto x86_l_312;
	case 792ULL: goto x86_l_318;
	case 797ULL: goto x86_l_31d;
	case 802ULL: goto x86_l_322;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 816ULL: goto x86_l_330;
	case 820ULL: goto x86_l_334;
	case 825ULL: goto x86_l_339;
	case 829ULL: goto x86_l_33d;
	case 836ULL: goto x86_l_344;
	case 840ULL: goto x86_l_348;
	case 845ULL: goto x86_l_34d;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 875ULL: goto x86_l_36b;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 885ULL: goto x86_l_375;
	case 887ULL: goto x86_l_377;
	case 893ULL: goto x86_l_37d;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 911ULL: goto x86_l_38f;
	case 918ULL: goto x86_l_396;
	case 924ULL: goto x86_l_39c;
	case 931ULL: goto x86_l_3a3;
	case 934ULL: goto x86_l_3a6;
	case 939ULL: goto x86_l_3ab;
	case 942ULL: goto x86_l_3ae;
	case 947ULL: goto x86_l_3b3;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 964ULL: goto x86_l_3c4;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 981ULL: goto x86_l_3d5;
	case 986ULL: goto x86_l_3da;
	case 988ULL: goto x86_l_3dc;
	case 993ULL: goto x86_l_3e1;
	case 995ULL: goto x86_l_3e3;
	case 1001ULL: goto x86_l_3e9;
	case 1008ULL: goto x86_l_3f0;
	case 1014ULL: goto x86_l_3f6;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1031ULL: goto x86_l_407;
	case 1033ULL: goto x86_l_409;
	case 1038ULL: goto x86_l_40e;
	case 1043ULL: goto x86_l_413;
	case 1048ULL: goto x86_l_418;
	case 1053ULL: goto x86_l_41d;
	case 1055ULL: goto x86_l_41f;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1068ULL: goto x86_l_42c;
	case 1075ULL: goto x86_l_433;
	case 1081ULL: goto x86_l_439;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1098ULL: goto x86_l_44a;
	case 1100ULL: goto x86_l_44c;
	case 1105ULL: goto x86_l_451;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1135ULL: goto x86_l_46f;
	case 1142ULL: goto x86_l_476;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1165ULL: goto x86_l_48d;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1177ULL: goto x86_l_499;
	case 1182ULL: goto x86_l_49e;
	case 1187ULL: goto x86_l_4a3;
	case 1189ULL: goto x86_l_4a5;
	case 1194ULL: goto x86_l_4aa;
	case 1196ULL: goto x86_l_4ac;
	case 1202ULL: goto x86_l_4b2;
	case 1209ULL: goto x86_l_4b9;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1232ULL: goto x86_l_4d0;
	case 1234ULL: goto x86_l_4d2;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1256ULL: goto x86_l_4e8;
	case 1261ULL: goto x86_l_4ed;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1276ULL: goto x86_l_4fc;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1299ULL: goto x86_l_513;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1330ULL: goto x86_l_532;
	case 1336ULL: goto x86_l_538;
	case 1343ULL: goto x86_l_53f;
	case 1349ULL: goto x86_l_545;
	case 1354ULL: goto x86_l_54a;
	case 1359ULL: goto x86_l_54f;
	case 1366ULL: goto x86_l_556;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1397ULL: goto x86_l_575;
	case 1403ULL: goto x86_l_57b;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1421ULL: goto x86_l_58d;
	case 1426ULL: goto x86_l_592;
	case 1433ULL: goto x86_l_599;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1445ULL: goto x86_l_5a5;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1477ULL: goto x86_l_5c5;
	case 1483ULL: goto x86_l_5cb;
	case 1488ULL: goto x86_l_5d0;
	case 1493ULL: goto x86_l_5d5;
	case 1500ULL: goto x86_l_5dc;
	case 1502ULL: goto x86_l_5de;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1522ULL: goto x86_l_5f2;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1582ULL: goto x86_l_62e;
	case 1585ULL: goto x86_l_631;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1616ULL: goto x86_l_650;
	case 1622ULL: goto x86_l_656;
	case 1629ULL: goto x86_l_65d;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1683ULL: goto x86_l_693;
	case 1689ULL: goto x86_l_699;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1712ULL: goto x86_l_6b0;
	case 1719ULL: goto x86_l_6b7;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1750ULL: goto x86_l_6d6;
	case 1756ULL: goto x86_l_6dc;
	case 1763ULL: goto x86_l_6e3;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1786ULL: goto x86_l_6fa;
	case 1788ULL: goto x86_l_6fc;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x28],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1a:
	/* 0x1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2e:
	/* 0x2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30:
	/* 0x30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: je     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20152ULL;
	}
x86_l_39:
	/* 0x39: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_43:
	/* 0x43: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_48:
	/* 0x48: lea    rcx,[r15+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_54:
	/* 0x54: lea    rcx,[r15+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_60:
	/* 0x60: lea    rcx,[r15+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6c:
	/* 0x6c: lea    rcx,[r15+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_75:
	/* 0x75: lea    rcx,[r15+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_81:
	/* 0x81: lea    rcx,[r15+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_85:
	/* 0x85: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8a:
	/* 0x8a: lea    rcx,[r15+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8e:
	/* 0x8e: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_96:
	/* 0x96: lea    rcx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9f:
	/* 0x9f: lea    rcx,[r15+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ab:
	/* 0xab: lea    rcx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b4:
	/* 0xb4: lea    rcx,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b8:
	/* 0xb8: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c0:
	/* 0xc0: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4:
	/* 0xc4: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c9:
	/* 0xc9: lea    rcx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd:
	/* 0xcd: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d5:
	/* 0xd5: lea    rcx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_de:
	/* 0xde: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1:
	/* 0xe1: lea    rax,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5:
	/* 0xe5: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ea:
	/* 0xea: lea    r12,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee:
	/* 0xee: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f3:
	/* 0xf3: je     1107 <generic_sleepable_preload+0x1107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4359ULL;
	}
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rsp+0xc0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_101:
	/* 0x101: lea    r14,[rdi+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_105:
	/* 0x105: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_108:
	/* 0x108: add    rbx,0x213 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 531ULL);
x86_l_10f:
	/* 0x10f: mov    r12d,0xbe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 190ULL);
x86_l_115:
	/* 0x115: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11a:
	/* 0x11a: jmp    146 <generic_sleepable_preload+0x146> */
	goto x86_l_146;
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e:
	/* 0x11e: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_123:
	/* 0x123: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128:
	/* 0x128: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12d:
	/* 0x12d: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_131:
	/* 0x131: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_135:
	/* 0x135: add    r12,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_139:
	/* 0x139: cmp    r12,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 590ULL);
x86_l_140:
	/* 0x140: je     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20152ULL;
	}
x86_l_146:
	/* 0x146: mov    eax,DWORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_14a:
	/* 0x14a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_14f:
	/* 0x14f: je     12d <generic_sleepable_preload+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d;
	}
x86_l_151:
	/* 0x151: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_153:
	/* 0x153: js     1aa <generic_sleepable_preload+0x1aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1aa;
	}
x86_l_155:
	/* 0x155: movzx  ecx,BYTE PTR [rbx-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_159:
	/* 0x159: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15c:
	/* 0x15c: jg     212 <generic_sleepable_preload+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_212;
	}
x86_l_162:
	/* 0x162: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: je     330 <generic_sleepable_preload+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_330;
	}
x86_l_16b:
	/* 0x16b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_170:
	/* 0x170: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_173:
	/* 0x173: jne    384 <generic_sleepable_preload+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_384;
	}
x86_l_179:
	/* 0x179: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_17c:
	/* 0x17c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_182:
	/* 0x182: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_187:
	/* 0x187: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18f:
	/* 0x18f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194:
	/* 0x194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196:
	/* 0x196: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: je     339 <generic_sleepable_preload+0x339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_339;
	}
x86_l_1a3:
	/* 0x1a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a5:
	/* 0x1a5: jmp    384 <generic_sleepable_preload+0x384> */
	goto x86_l_384;
x86_l_1aa:
	/* 0x1aa: movzx  eax,BYTE PTR [r14+0x2be] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 702ULL);
x86_l_1b2:
	/* 0x1b2: movzx  ecx,WORD PTR [r14+0x2bc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 700ULL);
x86_l_1ba:
	/* 0x1ba: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1c0:
	/* 0x1c0: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1c3:
	/* 0x1c3: jle    296 <generic_sleepable_preload+0x296> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_296;
	}
x86_l_1c9:
	/* 0x1c9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1cc:
	/* 0x1cc: jle    2cc <generic_sleepable_preload+0x2cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2cc;
	}
x86_l_1d2:
	/* 0x1d2: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1d5:
	/* 0x1d5: jle    91c <generic_sleepable_preload+0x91c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2332ULL;
	}
x86_l_1db:
	/* 0x1db: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e3:
	/* 0x1e3: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e6:
	/* 0x1e6: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_1ec:
	/* 0x1ec: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f1:
	/* 0x1f1: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f4:
	/* 0x1f4: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_1fa:
	/* 0x1fa: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1ff:
	/* 0x1ff: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_202:
	/* 0x202: jne    94b <generic_sleepable_preload+0x94b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2379ULL;
	}
x86_l_208:
	/* 0x208: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20d:
	/* 0x20d: jmp    938 <generic_sleepable_preload+0x938> */
	return 2360ULL;
x86_l_212:
	/* 0x212: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_215:
	/* 0x215: je     358 <generic_sleepable_preload+0x358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_358;
	}
x86_l_21b:
	/* 0x21b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_220:
	/* 0x220: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_223:
	/* 0x223: jne    384 <generic_sleepable_preload+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_384;
	}
x86_l_229:
	/* 0x229: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_22c:
	/* 0x22c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_232:
	/* 0x232: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_237:
	/* 0x237: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a:
	/* 0x23a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23f:
	/* 0x23f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_242:
	/* 0x242: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b:
	/* 0x24b: jne    37d <generic_sleepable_preload+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37d;
	}
x86_l_251:
	/* 0x251: mov    edx,DWORD PTR [rbx-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551609ULL);
x86_l_254:
	/* 0x254: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25a:
	/* 0x25a: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25d:
	/* 0x25d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_262:
	/* 0x262: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267:
	/* 0x267: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c:
	/* 0x26c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e:
	/* 0x26e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_270:
	/* 0x270: jne    37d <generic_sleepable_preload+0x37d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37d;
	}
x86_l_276:
	/* 0x276: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27b:
	/* 0x27b: movzx  ecx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27e:
	/* 0x27e: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_285:
	/* 0x285: mov    rdx,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_289:
	/* 0x289: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_28e:
	/* 0x28e: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_291:
	/* 0x291: jmp    ebb <generic_sleepable_preload+0xebb> */
	return 3771ULL;
x86_l_296:
	/* 0x296: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_299:
	/* 0x299: jg     2fe <generic_sleepable_preload+0x2fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fe;
	}
x86_l_29b:
	/* 0x29b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_29e:
	/* 0x29e: jg     8e3 <generic_sleepable_preload+0x8e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2275ULL;
	}
x86_l_2a4:
	/* 0x2a4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a9:
	/* 0x2a9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2ab:
	/* 0x2ab: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_2b1:
	/* 0x2b1: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2b9:
	/* 0x2b9: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2be:
	/* 0x2be: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c1:
	/* 0x2c1: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_2c7:
	/* 0x2c7: jmp    94b <generic_sleepable_preload+0x94b> */
	return 2379ULL;
x86_l_2cc:
	/* 0x2cc: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2cf:
	/* 0x2cf: jg     8c5 <generic_sleepable_preload+0x8c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2245ULL;
	}
x86_l_2d5:
	/* 0x2d5: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2dd:
	/* 0x2dd: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e0:
	/* 0x2e0: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_2e6:
	/* 0x2e6: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2eb:
	/* 0x2eb: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_2f0:
	/* 0x2f0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_2f3:
	/* 0x2f3: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_2f9:
	/* 0x2f9: jmp    94b <generic_sleepable_preload+0x94b> */
	return 2379ULL;
x86_l_2fe:
	/* 0x2fe: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_301:
	/* 0x301: jg     8fe <generic_sleepable_preload+0x8fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2302ULL;
	}
x86_l_307:
	/* 0x307: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30f:
	/* 0x30f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_312:
	/* 0x312: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_318:
	/* 0x318: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_31d:
	/* 0x31d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_322:
	/* 0x322: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_325:
	/* 0x325: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2360ULL;
	}
x86_l_32b:
	/* 0x32b: jmp    94b <generic_sleepable_preload+0x94b> */
	return 2379ULL;
x86_l_330:
	/* 0x330: mov    rax,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551597ULL);
x86_l_334:
	/* 0x334: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_339:
	/* 0x339: movzx  eax,BYTE PTR [rbx-0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551613ULL);
x86_l_33d:
	/* 0x33d: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_344:
	/* 0x344: cmp    BYTE PTR [rbx-0x1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744069414584320ULL);
x86_l_348:
	/* 0x348: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_34d:
	/* 0x34d: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_352:
	/* 0x352: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_356:
	/* 0x356: jmp    384 <generic_sleepable_preload+0x384> */
	goto x86_l_384;
x86_l_358:
	/* 0x358: mov    edx,DWORD PTR [rbx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551605ULL);
x86_l_35b:
	/* 0x35b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_361:
	/* 0x361: add    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_366:
	/* 0x366: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36b:
	/* 0x36b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_36e:
	/* 0x36e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_373:
	/* 0x373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375:
	/* 0x375: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_377:
	/* 0x377: je     ead <generic_sleepable_preload+0xead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3757ULL;
	}
x86_l_37d:
	/* 0x37d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_37f:
	/* 0x37f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_384:
	/* 0x384: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_389:
	/* 0x389: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38c:
	/* 0x38c: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_38f:
	/* 0x38f: cmp    WORD PTR [rdi+r12*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743764471906304ULL);
x86_l_396:
	/* 0x396: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_39c:
	/* 0x39c: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_3a3:
	/* 0x3a3: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3a6:
	/* 0x3a6: mov    edx,DWORD PTR [rdi+r12*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551538ULL);
x86_l_3ab:
	/* 0x3ab: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ae:
	/* 0x3ae: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b3:
	/* 0x3b3: movzx  eax,WORD PTR [rdi+r12*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R12, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_3b9:
	/* 0x3b9: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3bb:
	/* 0x3bb: je     62e <generic_sleepable_preload+0x62e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62e;
	}
x86_l_3c1:
	/* 0x3c1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3c4:
	/* 0x3c4: je     3e9 <generic_sleepable_preload+0x3e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e9;
	}
x86_l_3c6:
	/* 0x3c6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cb:
	/* 0x3cb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0:
	/* 0x3d0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d5:
	/* 0x3d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3da:
	/* 0x3da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc:
	/* 0x3dc: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e1:
	/* 0x3e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e3:
	/* 0x3e3: js     8ba <generic_sleepable_preload+0x8ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2234ULL;
	}
x86_l_3e9:
	/* 0x3e9: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_3f0:
	/* 0x3f0: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_3f6:
	/* 0x3f6: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_3fb:
	/* 0x3fb: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_400:
	/* 0x400: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_407:
	/* 0x407: je     42c <generic_sleepable_preload+0x42c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42c;
	}
x86_l_409:
	/* 0x409: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_40e:
	/* 0x40e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_413:
	/* 0x413: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_418:
	/* 0x418: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41d:
	/* 0x41d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f:
	/* 0x41f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_424:
	/* 0x424: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_426:
	/* 0x426: js     e97 <generic_sleepable_preload+0xe97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3735ULL;
	}
x86_l_42c:
	/* 0x42c: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_433:
	/* 0x433: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_439:
	/* 0x439: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_43e:
	/* 0x43e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_443:
	/* 0x443: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_44a:
	/* 0x44a: je     46f <generic_sleepable_preload+0x46f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46f;
	}
x86_l_44c:
	/* 0x44c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_451:
	/* 0x451: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_456:
	/* 0x456: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b:
	/* 0x45b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_460:
	/* 0x460: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_462:
	/* 0x462: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_467:
	/* 0x467: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_469:
	/* 0x469: js     ed9 <generic_sleepable_preload+0xed9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3801ULL;
	}
x86_l_46f:
	/* 0x46f: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_476:
	/* 0x476: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_47c:
	/* 0x47c: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_481:
	/* 0x481: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_486:
	/* 0x486: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_48d:
	/* 0x48d: je     4b2 <generic_sleepable_preload+0x4b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b2;
	}
x86_l_48f:
	/* 0x48f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_494:
	/* 0x494: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_499:
	/* 0x499: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e:
	/* 0x49e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a3:
	/* 0x4a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a5:
	/* 0x4a5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4aa:
	/* 0x4aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ac:
	/* 0x4ac: js     eec <generic_sleepable_preload+0xeec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3820ULL;
	}
x86_l_4b2:
	/* 0x4b2: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_4b9:
	/* 0x4b9: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_4bf:
	/* 0x4bf: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_4c4:
	/* 0x4c4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c9:
	/* 0x4c9: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_4d0:
	/* 0x4d0: je     4f5 <generic_sleepable_preload+0x4f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f5;
	}
x86_l_4d2:
	/* 0x4d2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dc:
	/* 0x4dc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e1:
	/* 0x4e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e6:
	/* 0x4e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8:
	/* 0x4e8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ed:
	/* 0x4ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ef:
	/* 0x4ef: js     eff <generic_sleepable_preload+0xeff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3839ULL;
	}
x86_l_4f5:
	/* 0x4f5: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_4fc:
	/* 0x4fc: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_502:
	/* 0x502: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_507:
	/* 0x507: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50c:
	/* 0x50c: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_513:
	/* 0x513: je     538 <generic_sleepable_preload+0x538> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_538;
	}
x86_l_515:
	/* 0x515: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51a:
	/* 0x51a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51f:
	/* 0x51f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_524:
	/* 0x524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_530:
	/* 0x530: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_532:
	/* 0x532: js     f12 <generic_sleepable_preload+0xf12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3858ULL;
	}
x86_l_538:
	/* 0x538: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_53f:
	/* 0x53f: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_545:
	/* 0x545: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_54a:
	/* 0x54a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_54f:
	/* 0x54f: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_556:
	/* 0x556: je     57b <generic_sleepable_preload+0x57b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57b;
	}
x86_l_558:
	/* 0x558: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55d:
	/* 0x55d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_562:
	/* 0x562: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_567:
	/* 0x567: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56c:
	/* 0x56c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e:
	/* 0x56e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_573:
	/* 0x573: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_575:
	/* 0x575: js     f25 <generic_sleepable_preload+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3877ULL;
	}
x86_l_57b:
	/* 0x57b: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_582:
	/* 0x582: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_588:
	/* 0x588: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_58d:
	/* 0x58d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_592:
	/* 0x592: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_599:
	/* 0x599: je     5be <generic_sleepable_preload+0x5be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5be;
	}
x86_l_59b:
	/* 0x59b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a0:
	/* 0x5a0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a5:
	/* 0x5a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aa:
	/* 0x5aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5af:
	/* 0x5af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b1:
	/* 0x5b1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b6:
	/* 0x5b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b8:
	/* 0x5b8: js     10c7 <generic_sleepable_preload+0x10c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4295ULL;
	}
x86_l_5be:
	/* 0x5be: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_5c5:
	/* 0x5c5: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_5cb:
	/* 0x5cb: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_5d0:
	/* 0x5d0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5d5:
	/* 0x5d5: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_5dc:
	/* 0x5dc: je     601 <generic_sleepable_preload+0x601> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_601;
	}
x86_l_5de:
	/* 0x5de: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e3:
	/* 0x5e3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e8:
	/* 0x5e8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ed:
	/* 0x5ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f2:
	/* 0x5f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f4:
	/* 0x5f4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f9:
	/* 0x5f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fb:
	/* 0x5fb: js     10f1 <generic_sleepable_preload+0x10f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4337ULL;
	}
x86_l_601:
	/* 0x601: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_607:
	/* 0x607: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_60d:
	/* 0x60d: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_612:
	/* 0x612: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_617:
	/* 0x617: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_61e:
	/* 0x61e: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_624:
	/* 0x624: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_629:
	/* 0x629: jmp    896 <generic_sleepable_preload+0x896> */
	return 2198ULL;
x86_l_62e:
	/* 0x62e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_631:
	/* 0x631: je     656 <generic_sleepable_preload+0x656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_656;
	}
x86_l_633:
	/* 0x633: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_638:
	/* 0x638: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63d:
	/* 0x63d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_642:
	/* 0x642: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_647:
	/* 0x647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_649:
	/* 0x649: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64e:
	/* 0x64e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_650:
	/* 0x650: js     8ba <generic_sleepable_preload+0x8ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2234ULL;
	}
x86_l_656:
	/* 0x656: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_65d:
	/* 0x65d: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_663:
	/* 0x663: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_668:
	/* 0x668: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_66d:
	/* 0x66d: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_674:
	/* 0x674: je     699 <generic_sleepable_preload+0x699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_699;
	}
x86_l_676:
	/* 0x676: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_67b:
	/* 0x67b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_680:
	/* 0x680: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_685:
	/* 0x685: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68a:
	/* 0x68a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68c:
	/* 0x68c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_691:
	/* 0x691: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_693:
	/* 0x693: js     e97 <generic_sleepable_preload+0xe97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3735ULL;
	}
x86_l_699:
	/* 0x699: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_6a0:
	/* 0x6a0: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_6a6:
	/* 0x6a6: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_6ab:
	/* 0x6ab: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6b0:
	/* 0x6b0: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_6b7:
	/* 0x6b7: je     6dc <generic_sleepable_preload+0x6dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6dc;
	}
x86_l_6b9:
	/* 0x6b9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6be:
	/* 0x6be: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c3:
	/* 0x6c3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c8:
	/* 0x6c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6cd:
	/* 0x6cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cf:
	/* 0x6cf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d4:
	/* 0x6d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6d6:
	/* 0x6d6: js     ed9 <generic_sleepable_preload+0xed9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3801ULL;
	}
x86_l_6dc:
	/* 0x6dc: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_6e3:
	/* 0x6e3: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_6e9:
	/* 0x6e9: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_6ee:
	/* 0x6ee: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6f3:
	/* 0x6f3: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_6fa:
	/* 0x6fa: je     71f <generic_sleepable_preload+0x71f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1823ULL;
	}
x86_l_6fc:
	/* 0x6fc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_701:
	/* 0x701: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_706:
	/* 0x706: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70b:
	/* 0x70b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_710:
	/* 0x710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1810ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1817ULL: goto x86_l_719;
	case 1823ULL: goto x86_l_71f;
	case 1830ULL: goto x86_l_726;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1877ULL: goto x86_l_755;
	case 1882ULL: goto x86_l_75a;
	case 1884ULL: goto x86_l_75c;
	case 1890ULL: goto x86_l_762;
	case 1897ULL: goto x86_l_769;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1920ULL: goto x86_l_780;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1951ULL: goto x86_l_79f;
	case 1957ULL: goto x86_l_7a5;
	case 1964ULL: goto x86_l_7ac;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1987ULL: goto x86_l_7c3;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2016ULL: goto x86_l_7e0;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2031ULL: goto x86_l_7ef;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2047ULL: goto x86_l_7ff;
	case 2054ULL: goto x86_l_806;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2085ULL: goto x86_l_825;
	case 2091ULL: goto x86_l_82b;
	case 2098ULL: goto x86_l_832;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2121ULL: goto x86_l_849;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2152ULL: goto x86_l_868;
	case 2158ULL: goto x86_l_86e;
	case 2164ULL: goto x86_l_874;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2180ULL: goto x86_l_884;
	case 2187ULL: goto x86_l_88b;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2213ULL: goto x86_l_8a5;
	case 2215ULL: goto x86_l_8a7;
	case 2217ULL: goto x86_l_8a9;
	case 2223ULL: goto x86_l_8af;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2302ULL: goto x86_l_8fe;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2328ULL: goto x86_l_918;
	case 2330ULL: goto x86_l_91a;
	case 2332ULL: goto x86_l_91c;
	case 2340ULL: goto x86_l_924;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2355ULL: goto x86_l_933;
	case 2358ULL: goto x86_l_936;
	case 2360ULL: goto x86_l_938;
	case 2363ULL: goto x86_l_93b;
	case 2365ULL: goto x86_l_93d;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2390ULL: goto x86_l_956;
	case 2392ULL: goto x86_l_958;
	case 2396ULL: goto x86_l_95c;
	case 2403ULL: goto x86_l_963;
	case 2409ULL: goto x86_l_969;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2424ULL: goto x86_l_978;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2478ULL: goto x86_l_9ae;
	case 2480ULL: goto x86_l_9b0;
	case 2486ULL: goto x86_l_9b6;
	case 2493ULL: goto x86_l_9bd;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2509ULL: goto x86_l_9cd;
	case 2516ULL: goto x86_l_9d4;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2540ULL: goto x86_l_9ec;
	case 2545ULL: goto x86_l_9f1;
	case 2547ULL: goto x86_l_9f3;
	case 2553ULL: goto x86_l_9f9;
	case 2560ULL: goto x86_l_a00;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2576ULL: goto x86_l_a10;
	case 2583ULL: goto x86_l_a17;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2614ULL: goto x86_l_a36;
	case 2620ULL: goto x86_l_a3c;
	case 2627ULL: goto x86_l_a43;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2650ULL: goto x86_l_a5a;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2687ULL: goto x86_l_a7f;
	case 2694ULL: goto x86_l_a86;
	case 2700ULL: goto x86_l_a8c;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2717ULL: goto x86_l_a9d;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2754ULL: goto x86_l_ac2;
	case 2761ULL: goto x86_l_ac9;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2784ULL: goto x86_l_ae0;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2815ULL: goto x86_l_aff;
	case 2821ULL: goto x86_l_b05;
	case 2828ULL: goto x86_l_b0c;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2882ULL: goto x86_l_b42;
	case 2888ULL: goto x86_l_b48;
	case 2895ULL: goto x86_l_b4f;
	case 2901ULL: goto x86_l_b55;
	case 2906ULL: goto x86_l_b5a;
	case 2911ULL: goto x86_l_b5f;
	case 2918ULL: goto x86_l_b66;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2942ULL: goto x86_l_b7e;
	case 2947ULL: goto x86_l_b83;
	case 2949ULL: goto x86_l_b85;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2978ULL: goto x86_l_ba2;
	case 2985ULL: goto x86_l_ba9;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3016ULL: goto x86_l_bc8;
	case 3022ULL: goto x86_l_bce;
	case 3028ULL: goto x86_l_bd4;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3051ULL: goto x86_l_beb;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3099ULL: goto x86_l_c1b;
	case 3101ULL: goto x86_l_c1d;
	case 3107ULL: goto x86_l_c23;
	case 3114ULL: goto x86_l_c2a;
	case 3120ULL: goto x86_l_c30;
	case 3125ULL: goto x86_l_c35;
	case 3130ULL: goto x86_l_c3a;
	case 3137ULL: goto x86_l_c41;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3159ULL: goto x86_l_c57;
	case 3161ULL: goto x86_l_c59;
	case 3166ULL: goto x86_l_c5e;
	case 3168ULL: goto x86_l_c60;
	case 3174ULL: goto x86_l_c66;
	case 3181ULL: goto x86_l_c6d;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3204ULL: goto x86_l_c84;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3235ULL: goto x86_l_ca3;
	case 3241ULL: goto x86_l_ca9;
	case 3248ULL: goto x86_l_cb0;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3264ULL: goto x86_l_cc0;
	case 3271ULL: goto x86_l_cc7;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3295ULL: goto x86_l_cdf;
	case 3300ULL: goto x86_l_ce4;
	case 3302ULL: goto x86_l_ce6;
	case 3308ULL: goto x86_l_cec;
	case 3315ULL: goto x86_l_cf3;
	case 3321ULL: goto x86_l_cf9;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3350ULL: goto x86_l_d16;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3369ULL: goto x86_l_d29;
	case 3375ULL: goto x86_l_d2f;
	case 3382ULL: goto x86_l_d36;
	case 3388ULL: goto x86_l_d3c;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3405ULL: goto x86_l_d4d;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3434ULL: goto x86_l_d6a;
	case 3436ULL: goto x86_l_d6c;
	case 3442ULL: goto x86_l_d72;
	case 3449ULL: goto x86_l_d79;
	case 3455ULL: goto x86_l_d7f;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3484ULL: goto x86_l_d9c;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3516ULL: goto x86_l_dbc;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3532ULL: goto x86_l_dcc;
	case 3539ULL: goto x86_l_dd3;
	case 3541ULL: goto x86_l_dd5;
	case 3546ULL: goto x86_l_dda;
	case 3551ULL: goto x86_l_ddf;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3570ULL: goto x86_l_df2;
	case 3576ULL: goto x86_l_df8;
	case 3583ULL: goto x86_l_dff;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_712:
	/* 0x712: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_717:
	/* 0x717: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_719:
	/* 0x719: js     eec <generic_sleepable_preload+0xeec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3820ULL;
	}
x86_l_71f:
	/* 0x71f: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_726:
	/* 0x726: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_72c:
	/* 0x72c: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_731:
	/* 0x731: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_736:
	/* 0x736: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_73d:
	/* 0x73d: je     762 <generic_sleepable_preload+0x762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_762;
	}
x86_l_73f:
	/* 0x73f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_744:
	/* 0x744: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_749:
	/* 0x749: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74e:
	/* 0x74e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_753:
	/* 0x753: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_755:
	/* 0x755: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_75a:
	/* 0x75a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_75c:
	/* 0x75c: js     eff <generic_sleepable_preload+0xeff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3839ULL;
	}
x86_l_762:
	/* 0x762: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_769:
	/* 0x769: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_76f:
	/* 0x76f: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_774:
	/* 0x774: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_779:
	/* 0x779: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_780:
	/* 0x780: je     7a5 <generic_sleepable_preload+0x7a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7a5;
	}
x86_l_782:
	/* 0x782: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_787:
	/* 0x787: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_78c:
	/* 0x78c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_791:
	/* 0x791: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_796:
	/* 0x796: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_798:
	/* 0x798: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_79d:
	/* 0x79d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_79f:
	/* 0x79f: js     f12 <generic_sleepable_preload+0xf12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3858ULL;
	}
x86_l_7a5:
	/* 0x7a5: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_7ac:
	/* 0x7ac: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_7b2:
	/* 0x7b2: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_7b7:
	/* 0x7b7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7bc:
	/* 0x7bc: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_7c3:
	/* 0x7c3: je     7e8 <generic_sleepable_preload+0x7e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e8;
	}
x86_l_7c5:
	/* 0x7c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_7ca:
	/* 0x7ca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7cf:
	/* 0x7cf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d4:
	/* 0x7d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d9:
	/* 0x7d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7db:
	/* 0x7db: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7e0:
	/* 0x7e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e2:
	/* 0x7e2: js     f25 <generic_sleepable_preload+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3877ULL;
	}
x86_l_7e8:
	/* 0x7e8: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_7ef:
	/* 0x7ef: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_7f5:
	/* 0x7f5: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_7fa:
	/* 0x7fa: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7ff:
	/* 0x7ff: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_806:
	/* 0x806: je     82b <generic_sleepable_preload+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_82b;
	}
x86_l_808:
	/* 0x808: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_80d:
	/* 0x80d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_812:
	/* 0x812: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_817:
	/* 0x817: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_81c:
	/* 0x81c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81e:
	/* 0x81e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_823:
	/* 0x823: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_825:
	/* 0x825: js     10c7 <generic_sleepable_preload+0x10c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4295ULL;
	}
x86_l_82b:
	/* 0x82b: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_832:
	/* 0x832: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_838:
	/* 0x838: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_83d:
	/* 0x83d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_842:
	/* 0x842: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_849:
	/* 0x849: je     86e <generic_sleepable_preload+0x86e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_86e;
	}
x86_l_84b:
	/* 0x84b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_850:
	/* 0x850: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_855:
	/* 0x855: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_85a:
	/* 0x85a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_85f:
	/* 0x85f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_861:
	/* 0x861: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_866:
	/* 0x866: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_868:
	/* 0x868: js     10f1 <generic_sleepable_preload+0x10f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4337ULL;
	}
x86_l_86e:
	/* 0x86e: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_874:
	/* 0x874: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_87a:
	/* 0x87a: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_87f:
	/* 0x87f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_884:
	/* 0x884: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_88b:
	/* 0x88b: je     f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3886ULL;
	}
x86_l_891:
	/* 0x891: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_896:
	/* 0x896: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89b:
	/* 0x89b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a0:
	/* 0x8a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a5:
	/* 0x8a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a7:
	/* 0x8a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a9:
	/* 0x8a9: jns    f2e <generic_sleepable_preload+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3886ULL;
	}
x86_l_8af:
	/* 0x8af: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_8b5:
	/* 0x8b5: jmp    f2b <generic_sleepable_preload+0xf2b> */
	return 3883ULL;
x86_l_8ba:
	/* 0x8ba: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_8c0:
	/* 0x8c0: jmp    f2b <generic_sleepable_preload+0xf2b> */
	return 3883ULL;
x86_l_8c5:
	/* 0x8c5: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8cd:
	/* 0x8cd: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_8d0:
	/* 0x8d0: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_8d2:
	/* 0x8d2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8d7:
	/* 0x8d7: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_8dc:
	/* 0x8dc: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_8df:
	/* 0x8df: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_8e1:
	/* 0x8e1: jmp    94b <generic_sleepable_preload+0x94b> */
	goto x86_l_94b;
x86_l_8e3:
	/* 0x8e3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8e8:
	/* 0x8e8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8eb:
	/* 0x8eb: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_8ed:
	/* 0x8ed: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8f2:
	/* 0x8f2: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_8f7:
	/* 0x8f7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8fa:
	/* 0x8fa: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_8fc:
	/* 0x8fc: jmp    94b <generic_sleepable_preload+0x94b> */
	goto x86_l_94b;
x86_l_8fe:
	/* 0x8fe: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_906:
	/* 0x906: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_909:
	/* 0x909: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_90b:
	/* 0x90b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_910:
	/* 0x910: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_915:
	/* 0x915: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_918:
	/* 0x918: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_91a:
	/* 0x91a: jmp    94b <generic_sleepable_preload+0x94b> */
	goto x86_l_94b;
x86_l_91c:
	/* 0x91c: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_924:
	/* 0x924: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_927:
	/* 0x927: je     938 <generic_sleepable_preload+0x938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_938;
	}
x86_l_929:
	/* 0x929: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92e:
	/* 0x92e: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_933:
	/* 0x933: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_936:
	/* 0x936: jne    94b <generic_sleepable_preload+0x94b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94b;
	}
x86_l_938:
	/* 0x938: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_93b:
	/* 0x93b: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_93d:
	/* 0x93d: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_93f:
	/* 0x93f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_944:
	/* 0x944: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_946:
	/* 0x946: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_94b:
	/* 0x94b: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_950:
	/* 0x950: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_953:
	/* 0x953: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_956:
	/* 0x956: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_958:
	/* 0x958: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95c:
	/* 0x95c: cmp    WORD PTR [rdi+r12*1-0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743764471906304ULL);
x86_l_963:
	/* 0x963: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_969:
	/* 0x969: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_970:
	/* 0x970: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_973:
	/* 0x973: mov    eax,DWORD PTR [rdi+r12*1-0x4e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551538ULL);
x86_l_978:
	/* 0x978: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_97b:
	/* 0x97b: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_980:
	/* 0x980: movzx  eax,WORD PTR [rdi+r12*1-0x4a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R12, 0, X86_WIDTH_16), 18446744073709551542ULL);
x86_l_986:
	/* 0x986: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_988:
	/* 0x988: je     bfb <generic_sleepable_preload+0xbfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bfb;
	}
x86_l_98e:
	/* 0x98e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_991:
	/* 0x991: je     9b6 <generic_sleepable_preload+0x9b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b6;
	}
x86_l_993:
	/* 0x993: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_998:
	/* 0x998: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_99d:
	/* 0x99d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a2:
	/* 0x9a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a7:
	/* 0x9a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9ae:
	/* 0x9ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b0:
	/* 0x9b0: js     e8c <generic_sleepable_preload+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3724ULL;
	}
x86_l_9b6:
	/* 0x9b6: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_9bd:
	/* 0x9bd: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_9c3:
	/* 0x9c3: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_9c8:
	/* 0x9c8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9cd:
	/* 0x9cd: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_9d4:
	/* 0x9d4: je     9f9 <generic_sleepable_preload+0x9f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f9;
	}
x86_l_9d6:
	/* 0x9d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_9db:
	/* 0x9db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e0:
	/* 0x9e0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e5:
	/* 0x9e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ea:
	/* 0x9ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ec:
	/* 0x9ec: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9f1:
	/* 0x9f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9f3:
	/* 0x9f3: js     ea2 <generic_sleepable_preload+0xea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3746ULL;
	}
x86_l_9f9:
	/* 0x9f9: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_a00:
	/* 0xa00: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_a06:
	/* 0xa06: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_a0b:
	/* 0xa0b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a10:
	/* 0xa10: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_a17:
	/* 0xa17: je     a3c <generic_sleepable_preload+0xa3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a3c;
	}
x86_l_a19:
	/* 0xa19: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a1e:
	/* 0xa1e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a23:
	/* 0xa23: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a28:
	/* 0xa28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2d:
	/* 0xa2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2f:
	/* 0xa2f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a34:
	/* 0xa34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a36:
	/* 0xa36: js     ee1 <generic_sleepable_preload+0xee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3809ULL;
	}
x86_l_a3c:
	/* 0xa3c: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_a43:
	/* 0xa43: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_a49:
	/* 0xa49: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_a4e:
	/* 0xa4e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a53:
	/* 0xa53: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_a5a:
	/* 0xa5a: je     a7f <generic_sleepable_preload+0xa7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a7f;
	}
x86_l_a5c:
	/* 0xa5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a61:
	/* 0xa61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a66:
	/* 0xa66: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6b:
	/* 0xa6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a70:
	/* 0xa70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a72:
	/* 0xa72: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a77:
	/* 0xa77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a79:
	/* 0xa79: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3828ULL;
	}
x86_l_a7f:
	/* 0xa7f: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_a86:
	/* 0xa86: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_a8c:
	/* 0xa8c: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_a91:
	/* 0xa91: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a96:
	/* 0xa96: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_a9d:
	/* 0xa9d: je     ac2 <generic_sleepable_preload+0xac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac2;
	}
x86_l_a9f:
	/* 0xa9f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_aa4:
	/* 0xaa4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa9:
	/* 0xaa9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aae:
	/* 0xaae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ab3:
	/* 0xab3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab5:
	/* 0xab5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aba:
	/* 0xaba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abc:
	/* 0xabc: js     f07 <generic_sleepable_preload+0xf07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3847ULL;
	}
x86_l_ac2:
	/* 0xac2: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_ac9:
	/* 0xac9: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_acf:
	/* 0xacf: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_ad4:
	/* 0xad4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ad9:
	/* 0xad9: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_ae0:
	/* 0xae0: je     b05 <generic_sleepable_preload+0xb05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b05;
	}
x86_l_ae2:
	/* 0xae2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ae7:
	/* 0xae7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aec:
	/* 0xaec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af1:
	/* 0xaf1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af6:
	/* 0xaf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af8:
	/* 0xaf8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_afd:
	/* 0xafd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aff:
	/* 0xaff: js     f1a <generic_sleepable_preload+0xf1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3866ULL;
	}
x86_l_b05:
	/* 0xb05: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_b0c:
	/* 0xb0c: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_b12:
	/* 0xb12: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_b17:
	/* 0xb17: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b1c:
	/* 0xb1c: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_b23:
	/* 0xb23: je     b48 <generic_sleepable_preload+0xb48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b48;
	}
x86_l_b25:
	/* 0xb25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2f:
	/* 0xb2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b34:
	/* 0xb34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b39:
	/* 0xb39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3b:
	/* 0xb3b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b40:
	/* 0xb40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b42:
	/* 0xb42: js     1006 <generic_sleepable_preload+0x1006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4102ULL;
	}
x86_l_b48:
	/* 0xb48: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_b4f:
	/* 0xb4f: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_b55:
	/* 0xb55: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_b5a:
	/* 0xb5a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b5f:
	/* 0xb5f: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_b66:
	/* 0xb66: je     b8b <generic_sleepable_preload+0xb8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8b;
	}
x86_l_b68:
	/* 0xb68: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b6d:
	/* 0xb6d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b72:
	/* 0xb72: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b77:
	/* 0xb77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b7c:
	/* 0xb7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7e:
	/* 0xb7e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b83:
	/* 0xb83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b85:
	/* 0xb85: js     10d5 <generic_sleepable_preload+0x10d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4309ULL;
	}
x86_l_b8b:
	/* 0xb8b: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_b92:
	/* 0xb92: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_b98:
	/* 0xb98: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_b9d:
	/* 0xb9d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ba2:
	/* 0xba2: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_ba9:
	/* 0xba9: je     bce <generic_sleepable_preload+0xbce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bce;
	}
x86_l_bab:
	/* 0xbab: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bb0:
	/* 0xbb0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb5:
	/* 0xbb5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bba:
	/* 0xbba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bbf:
	/* 0xbbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc1:
	/* 0xbc1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bc6:
	/* 0xbc6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc8:
	/* 0xbc8: js     10fc <generic_sleepable_preload+0x10fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4348ULL;
	}
x86_l_bce:
	/* 0xbce: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_bd4:
	/* 0xbd4: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_bda:
	/* 0xbda: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_bdf:
	/* 0xbdf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_be4:
	/* 0xbe4: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_beb:
	/* 0xbeb: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_bf1:
	/* 0xbf1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bf6:
	/* 0xbf6: jmp    e63 <generic_sleepable_preload+0xe63> */
	return 3683ULL;
x86_l_bfb:
	/* 0xbfb: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_bfe:
	/* 0xbfe: je     c23 <generic_sleepable_preload+0xc23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c23;
	}
x86_l_c00:
	/* 0xc00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c05:
	/* 0xc05: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0a:
	/* 0xc0a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0f:
	/* 0xc0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c14:
	/* 0xc14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c16:
	/* 0xc16: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c1b:
	/* 0xc1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c1d:
	/* 0xc1d: js     e8c <generic_sleepable_preload+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3724ULL;
	}
x86_l_c23:
	/* 0xc23: cmp    WORD PTR [rdi+r12*1-0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743798831644672ULL);
x86_l_c2a:
	/* 0xc2a: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_c30:
	/* 0xc30: mov    eax,DWORD PTR [rdi+r12*1-0x46] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551546ULL);
x86_l_c35:
	/* 0xc35: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c3a:
	/* 0xc3a: cmp    WORD PTR [rdi+r12*1-0x42],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743790241710080ULL);
x86_l_c41:
	/* 0xc41: je     c66 <generic_sleepable_preload+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c66;
	}
x86_l_c43:
	/* 0xc43: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c48:
	/* 0xc48: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c4d:
	/* 0xc4d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c52:
	/* 0xc52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c57:
	/* 0xc57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c59:
	/* 0xc59: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c5e:
	/* 0xc5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c60:
	/* 0xc60: js     ea2 <generic_sleepable_preload+0xea2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3746ULL;
	}
x86_l_c66:
	/* 0xc66: cmp    WORD PTR [rdi+r12*1-0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743833191383040ULL);
x86_l_c6d:
	/* 0xc6d: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_c73:
	/* 0xc73: mov    eax,DWORD PTR [rdi+r12*1-0x3e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551554ULL);
x86_l_c78:
	/* 0xc78: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c7d:
	/* 0xc7d: cmp    WORD PTR [rdi+r12*1-0x3a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743824601448448ULL);
x86_l_c84:
	/* 0xc84: je     ca9 <generic_sleepable_preload+0xca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ca9;
	}
x86_l_c86:
	/* 0xc86: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c8b:
	/* 0xc8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c90:
	/* 0xc90: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c95:
	/* 0xc95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c9a:
	/* 0xc9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9c:
	/* 0xc9c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca1:
	/* 0xca1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca3:
	/* 0xca3: js     ee1 <generic_sleepable_preload+0xee1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3809ULL;
	}
x86_l_ca9:
	/* 0xca9: cmp    WORD PTR [rdi+r12*1-0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743867551121408ULL);
x86_l_cb0:
	/* 0xcb0: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_cb6:
	/* 0xcb6: mov    eax,DWORD PTR [rdi+r12*1-0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551562ULL);
x86_l_cbb:
	/* 0xcbb: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cc0:
	/* 0xcc0: cmp    WORD PTR [rdi+r12*1-0x32],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743858961186816ULL);
x86_l_cc7:
	/* 0xcc7: je     cec <generic_sleepable_preload+0xcec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cec;
	}
x86_l_cc9:
	/* 0xcc9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cce:
	/* 0xcce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd3:
	/* 0xcd3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd8:
	/* 0xcd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cdd:
	/* 0xcdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdf:
	/* 0xcdf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce4:
	/* 0xce4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ce6:
	/* 0xce6: js     ef4 <generic_sleepable_preload+0xef4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3828ULL;
	}
x86_l_cec:
	/* 0xcec: cmp    WORD PTR [rdi+r12*1-0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743901910859776ULL);
x86_l_cf3:
	/* 0xcf3: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_cf9:
	/* 0xcf9: mov    eax,DWORD PTR [rdi+r12*1-0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551570ULL);
x86_l_cfe:
	/* 0xcfe: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d03:
	/* 0xd03: cmp    WORD PTR [rdi+r12*1-0x2a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743893320925184ULL);
x86_l_d0a:
	/* 0xd0a: je     d2f <generic_sleepable_preload+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2f;
	}
x86_l_d0c:
	/* 0xd0c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d11:
	/* 0xd11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d16:
	/* 0xd16: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1b:
	/* 0xd1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d20:
	/* 0xd20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d22:
	/* 0xd22: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d27:
	/* 0xd27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d29:
	/* 0xd29: js     f07 <generic_sleepable_preload+0xf07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3847ULL;
	}
x86_l_d2f:
	/* 0xd2f: cmp    WORD PTR [rdi+r12*1-0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743936270598144ULL);
x86_l_d36:
	/* 0xd36: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_d3c:
	/* 0xd3c: mov    eax,DWORD PTR [rdi+r12*1-0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551578ULL);
x86_l_d41:
	/* 0xd41: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d46:
	/* 0xd46: cmp    WORD PTR [rdi+r12*1-0x22],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743927680663552ULL);
x86_l_d4d:
	/* 0xd4d: je     d72 <generic_sleepable_preload+0xd72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d72;
	}
x86_l_d4f:
	/* 0xd4f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d54:
	/* 0xd54: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d59:
	/* 0xd59: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5e:
	/* 0xd5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d63:
	/* 0xd63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d65:
	/* 0xd65: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d6a:
	/* 0xd6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d6c:
	/* 0xd6c: js     f1a <generic_sleepable_preload+0xf1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3866ULL;
	}
x86_l_d72:
	/* 0xd72: cmp    WORD PTR [rdi+r12*1-0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743970630336512ULL);
x86_l_d79:
	/* 0xd79: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_d7f:
	/* 0xd7f: mov    eax,DWORD PTR [rdi+r12*1-0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551586ULL);
x86_l_d84:
	/* 0xd84: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d89:
	/* 0xd89: cmp    WORD PTR [rdi+r12*1-0x1a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743962040401920ULL);
x86_l_d90:
	/* 0xd90: je     db5 <generic_sleepable_preload+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db5;
	}
x86_l_d92:
	/* 0xd92: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d97:
	/* 0xd97: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9c:
	/* 0xd9c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da1:
	/* 0xda1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_da6:
	/* 0xda6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da8:
	/* 0xda8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dad:
	/* 0xdad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: js     1006 <generic_sleepable_preload+0x1006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4102ULL;
	}
x86_l_db5:
	/* 0xdb5: cmp    WORD PTR [rdi+r12*1-0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744004990074880ULL);
x86_l_dbc:
	/* 0xdbc: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_dc2:
	/* 0xdc2: mov    eax,DWORD PTR [rdi+r12*1-0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551594ULL);
x86_l_dc7:
	/* 0xdc7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dcc:
	/* 0xdcc: cmp    WORD PTR [rdi+r12*1-0x12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446743996400140288ULL);
x86_l_dd3:
	/* 0xdd3: je     df8 <generic_sleepable_preload+0xdf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df8;
	}
x86_l_dd5:
	/* 0xdd5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dda:
	/* 0xdda: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddf:
	/* 0xddf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de4:
	/* 0xde4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de9:
	/* 0xde9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_deb:
	/* 0xdeb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df0:
	/* 0xdf0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df2:
	/* 0xdf2: js     10d5 <generic_sleepable_preload+0x10d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4309ULL;
	}
x86_l_df8:
	/* 0xdf8: cmp    WORD PTR [rdi+r12*1-0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744039349813248ULL);
x86_l_dff:
	/* 0xdff: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4116ULL;
	}
x86_l_e05:
	/* 0xe05: mov    eax,DWORD PTR [rdi+r12*1-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551602ULL);
x86_l_e0a:
	/* 0xe0a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
	return 3599ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3599ULL: goto x86_l_e0f;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3628ULL: goto x86_l_e2c;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3637ULL: goto x86_l_e35;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3655ULL: goto x86_l_e47;
	case 3660ULL: goto x86_l_e4c;
	case 3665ULL: goto x86_l_e51;
	case 3672ULL: goto x86_l_e58;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	case 3713ULL: goto x86_l_e81;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3781ULL: goto x86_l_ec5;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3794ULL: goto x86_l_ed2;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3807ULL: goto x86_l_edf;
	case 3809ULL: goto x86_l_ee1;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3826ULL: goto x86_l_ef2;
	case 3828ULL: goto x86_l_ef4;
	case 3834ULL: goto x86_l_efa;
	case 3839ULL: goto x86_l_eff;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3864ULL: goto x86_l_f18;
	case 3866ULL: goto x86_l_f1a;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3883ULL: goto x86_l_f2b;
	case 3886ULL: goto x86_l_f2e;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3943ULL: goto x86_l_f67;
	case 3948ULL: goto x86_l_f6c;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3984ULL: goto x86_l_f90;
	case 3990ULL: goto x86_l_f96;
	case 3993ULL: goto x86_l_f99;
	case 4000ULL: goto x86_l_fa0;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4038ULL: goto x86_l_fc6;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4052ULL: goto x86_l_fd4;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4069ULL: goto x86_l_fe5;
	case 4071ULL: goto x86_l_fe7;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4081ULL: goto x86_l_ff1;
	case 4084ULL: goto x86_l_ff4;
	case 4086ULL: goto x86_l_ff6;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4116ULL: goto x86_l_1014;
	case 4119ULL: goto x86_l_1017;
	case 4125ULL: goto x86_l_101d;
	case 4130ULL: goto x86_l_1022;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4186ULL: goto x86_l_105a;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4210ULL: goto x86_l_1072;
	case 4213ULL: goto x86_l_1075;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4229ULL: goto x86_l_1085;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4253ULL: goto x86_l_109d;
	case 4257ULL: goto x86_l_10a1;
	case 4262ULL: goto x86_l_10a6;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4279ULL: goto x86_l_10b7;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4298ULL: goto x86_l_10ca;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4323ULL: goto x86_l_10e3;
	case 4326ULL: goto x86_l_10e6;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4362ULL: goto x86_l_110a;
	case 4367ULL: goto x86_l_110f;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4377ULL: goto x86_l_1119;
	case 4384ULL: goto x86_l_1120;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4398ULL: goto x86_l_112e;
	case 4404ULL: goto x86_l_1134;
	case 4407ULL: goto x86_l_1137;
	case 4413ULL: goto x86_l_113d;
	case 4419ULL: goto x86_l_1143;
	case 4425ULL: goto x86_l_1149;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4443ULL: goto x86_l_115b;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4452ULL: goto x86_l_1164;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4465ULL: goto x86_l_1171;
	case 4472ULL: goto x86_l_1178;
	case 4479ULL: goto x86_l_117f;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4490ULL: goto x86_l_118a;
	case 4496ULL: goto x86_l_1190;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4514ULL: goto x86_l_11a2;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4582ULL: goto x86_l_11e6;
	case 4588ULL: goto x86_l_11ec;
	case 4594ULL: goto x86_l_11f2;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4625ULL: goto x86_l_1211;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4677ULL: goto x86_l_1245;
	case 4684ULL: goto x86_l_124c;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4729ULL: goto x86_l_1279;
	case 4732ULL: goto x86_l_127c;
	case 4735ULL: goto x86_l_127f;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4763ULL: goto x86_l_129b;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4800ULL: goto x86_l_12c0;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4825ULL: goto x86_l_12d9;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4855ULL: goto x86_l_12f7;
	case 4862ULL: goto x86_l_12fe;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4883ULL: goto x86_l_1313;
	case 4885ULL: goto x86_l_1315;
	case 4891ULL: goto x86_l_131b;
	case 4897ULL: goto x86_l_1321;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4918ULL: goto x86_l_1336;
	case 4920ULL: goto x86_l_1338;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4979ULL: goto x86_l_1373;
	case 4981ULL: goto x86_l_1375;
	case 4987ULL: goto x86_l_137b;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5014ULL: goto x86_l_1396;
	case 5019ULL: goto x86_l_139b;
	case 5021ULL: goto x86_l_139d;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5058ULL: goto x86_l_13c2;
	case 5063ULL: goto x86_l_13c7;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5082ULL: goto x86_l_13da;
	case 5088ULL: goto x86_l_13e0;
	case 5096ULL: goto x86_l_13e8;
	case 5102ULL: goto x86_l_13ee;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5121ULL: goto x86_l_1401;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5138ULL: goto x86_l_1412;
	case 5143ULL: goto x86_l_1417;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5158ULL: goto x86_l_1426;
	case 5166ULL: goto x86_l_142e;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5228ULL: goto x86_l_146c;
	case 5236ULL: goto x86_l_1474;
	case 5242ULL: goto x86_l_147a;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5261ULL: goto x86_l_148d;
	case 5263ULL: goto x86_l_148f;
	case 5268ULL: goto x86_l_1494;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5292ULL: goto x86_l_14ac;
	case 5298ULL: goto x86_l_14b2;
	case 5306ULL: goto x86_l_14ba;
	case 5312ULL: goto x86_l_14c0;
	case 5318ULL: goto x86_l_14c6;
	case 5323ULL: goto x86_l_14cb;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5343ULL: goto x86_l_14df;
	case 5348ULL: goto x86_l_14e4;
	case 5353ULL: goto x86_l_14e9;
	case 5355ULL: goto x86_l_14eb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e0f:
	/* 0xe0f: cmp    WORD PTR [rdi+r12*1-0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744030759878656ULL);
x86_l_e16:
	/* 0xe16: je     e3b <generic_sleepable_preload+0xe3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e3b;
	}
x86_l_e18:
	/* 0xe18: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e1d:
	/* 0xe1d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e22:
	/* 0xe22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e27:
	/* 0xe27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e2c:
	/* 0xe2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2e:
	/* 0xe2e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e33:
	/* 0xe33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e35:
	/* 0xe35: js     10fc <generic_sleepable_preload+0x10fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10fc;
	}
x86_l_e3b:
	/* 0xe3b: cmp    WORD PTR [rdi+r12*1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_e41:
	/* 0xe41: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1014;
	}
x86_l_e47:
	/* 0xe47: mov    eax,DWORD PTR [rdi+r12*1-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 18446744073709551610ULL);
x86_l_e4c:
	/* 0xe4c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e51:
	/* 0xe51: cmp    WORD PTR [rdi+r12*1-0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R12, 0), 18446744065119617024ULL);
x86_l_e58:
	/* 0xe58: je     1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1014;
	}
x86_l_e5e:
	/* 0xe5e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e63:
	/* 0xe63: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e68:
	/* 0xe68: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6d:
	/* 0xe6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e72:
	/* 0xe72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e74:
	/* 0xe74: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e79:
	/* 0xe79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e7b:
	/* 0xe7b: jns    1014 <generic_sleepable_preload+0x1014> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1014;
	}
x86_l_e81:
	/* 0xe81: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_e87:
	/* 0xe87: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_e8c:
	/* 0xe8c: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_e92:
	/* 0xe92: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_e97:
	/* 0xe97: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_e9d:
	/* 0xe9d: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_ea2:
	/* 0xea2: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_ea8:
	/* 0xea8: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_ead:
	/* 0xead: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_eb2:
	/* 0xeb2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_eb7:
	/* 0xeb7: add    rdx,QWORD PTR [rbx-0x13] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 18446744073709551597ULL);
x86_l_ebb:
	/* 0xebb: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ec3:
	/* 0xec3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec5:
	/* 0xec5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ec7:
	/* 0xec7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ecc:
	/* 0xecc: je     339 <generic_sleepable_preload+0x339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 825ULL;
	}
x86_l_ed2:
	/* 0xed2: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_ed4:
	/* 0xed4: jmp    384 <generic_sleepable_preload+0x384> */
	return 900ULL;
x86_l_ed9:
	/* 0xed9: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_edf:
	/* 0xedf: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_ee1:
	/* 0xee1: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_ee7:
	/* 0xee7: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_eec:
	/* 0xeec: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ef2:
	/* 0xef2: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_ef4:
	/* 0xef4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_efa:
	/* 0xefa: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_eff:
	/* 0xeff: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_f05:
	/* 0xf05: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_f07:
	/* 0xf07: mov    r15d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 5ULL);
x86_l_f0d:
	/* 0xf0d: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_f12:
	/* 0xf12: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_f18:
	/* 0xf18: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_f1a:
	/* 0xf1a: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_f20:
	/* 0xf20: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_f25:
	/* 0xf25: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_f2b:
	/* 0xf2b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2e:
	/* 0xf2e: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f31:
	/* 0xf31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f36:
	/* 0xf36: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3b:
	/* 0xf3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f40:
	/* 0xf40: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_f43:
	/* 0xf43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f45:
	/* 0xf45: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_f48:
	/* 0xf48: jne    123 <generic_sleepable_preload+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 291ULL;
	}
x86_l_f4e:
	/* 0xf4e: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f53:
	/* 0xf53: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f58:
	/* 0xf58: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f60:
	/* 0xf60: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f65:
	/* 0xf65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f67:
	/* 0xf67: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6c:
	/* 0xf6c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f74:
	/* 0xf74: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f79:
	/* 0xf79: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f80:
	/* 0xf80: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f85:
	/* 0xf85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f87:
	/* 0xf87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 286ULL;
	}
x86_l_f90:
	/* 0xf90: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_f96:
	/* 0xf96: mov    ebx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_32);
x86_l_f99:
	/* 0xf99: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_fa0:
	/* 0xfa0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fa3:
	/* 0xfa3: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_fa6:
	/* 0xfa6: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fab:
	/* 0xfab: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fb1:
	/* 0xfb1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fb3:
	/* 0xfb3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_fb6:
	/* 0xfb6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fbb:
	/* 0xfbb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fc1:
	/* 0xfc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc3:
	/* 0xfc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc6:
	/* 0xfc6: je     11e <generic_sleepable_preload+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 286ULL;
	}
x86_l_fcc:
	/* 0xfcc: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_fce:
	/* 0xfce: je     11c <generic_sleepable_preload+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 284ULL;
	}
x86_l_fd4:
	/* 0xfd4: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fd8:
	/* 0xfd8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_fdd:
	/* 0xfdd: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_fe5:
	/* 0xfe5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fe7:
	/* 0xfe7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fea:
	/* 0xfea: call   fef <generic_sleepable_preload+0xfef> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_fef:
	/* 0xfef: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ff1:
	/* 0xff1: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_ff4:
	/* 0xff4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_ff6:
	/* 0xff6: jns    11c <generic_sleepable_preload+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 284ULL;
	}
x86_l_ffc:
	/* 0xffc: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_1001:
	/* 0x1001: jmp    11c <generic_sleepable_preload+0x11c> */
	return 284ULL;
x86_l_1006:
	/* 0x1006: mov    r15d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 7ULL);
x86_l_100c:
	/* 0x100c: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1014:
	/* 0x1014: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1017:
	/* 0x1017: jne    12d <generic_sleepable_preload+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 301ULL;
	}
x86_l_101d:
	/* 0x101d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1022:
	/* 0x1022: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_102a:
	/* 0x102a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_102f:
	/* 0x102f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1031:
	/* 0x1031: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1036:
	/* 0x1036: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_103e:
	/* 0x103e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1043:
	/* 0x1043: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_104a:
	/* 0x104a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104f:
	/* 0x104f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1051:
	/* 0x1051: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1054:
	/* 0x1054: je     123 <generic_sleepable_preload+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 291ULL;
	}
x86_l_105a:
	/* 0x105a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1060:
	/* 0x1060: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_1063:
	/* 0x1063: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_106a:
	/* 0x106a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_106d:
	/* 0x106d: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1072:
	/* 0x1072: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1075:
	/* 0x1075: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1078:
	/* 0x1078: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107a:
	/* 0x107a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_107d:
	/* 0x107d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1082:
	/* 0x1082: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1085:
	/* 0x1085: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1088:
	/* 0x1088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108a:
	/* 0x108a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_108d:
	/* 0x108d: je     123 <generic_sleepable_preload+0x123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 291ULL;
	}
x86_l_1093:
	/* 0x1093: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1096:
	/* 0x1096: cmp    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_109b:
	/* 0x109b: je     10be <generic_sleepable_preload+0x10be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10be;
	}
x86_l_109d:
	/* 0x109d: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10a1:
	/* 0x10a1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_10a6:
	/* 0x10a6: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10ae:
	/* 0x10ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b0:
	/* 0x10b0: call   10b5 <generic_sleepable_preload+0x10b5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_10b5:
	/* 0x10b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b7:
	/* 0x10b7: jns    10be <generic_sleepable_preload+0x10be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_10be;
	}
x86_l_10b9:
	/* 0x10b9: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_10be:
	/* 0x10be: mov    DWORD PTR [r13+0x0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c2:
	/* 0x10c2: jmp    123 <generic_sleepable_preload+0x123> */
	return 291ULL;
x86_l_10c7:
	/* 0x10c7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ca:
	/* 0x10ca: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_10d0:
	/* 0x10d0: jmp    f2e <generic_sleepable_preload+0xf2e> */
	goto x86_l_f2e;
x86_l_10d5:
	/* 0x10d5: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10dd:
	/* 0x10dd: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_10e3:
	/* 0x10e3: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_10e6:
	/* 0x10e6: jne    12d <generic_sleepable_preload+0x12d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 301ULL;
	}
x86_l_10ec:
	/* 0x10ec: jmp    101d <generic_sleepable_preload+0x101d> */
	goto x86_l_101d;
x86_l_10f1:
	/* 0x10f1: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_10f7:
	/* 0x10f7: jmp    f2b <generic_sleepable_preload+0xf2b> */
	goto x86_l_f2b;
x86_l_10fc:
	/* 0x10fc: mov    r15d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9ULL);
x86_l_1102:
	/* 0x1102: jmp    100c <generic_sleepable_preload+0x100c> */
	goto x86_l_100c;
x86_l_1107:
	/* 0x1107: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_110a:
	/* 0x110a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_110f:
	/* 0x110f: je     205c <generic_sleepable_preload+0x205c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8284ULL;
	}
x86_l_1115:
	/* 0x1115: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1117:
	/* 0x1117: js     1171 <generic_sleepable_preload+0x1171> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1171;
	}
x86_l_1119:
	/* 0x1119: movzx  ecx,BYTE PTR [rdi+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_1120:
	/* 0x1120: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1122:
	/* 0x1122: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1125:
	/* 0x1125: jg     11d4 <generic_sleepable_preload+0x11d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11d4;
	}
x86_l_112b:
	/* 0x112b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_112e:
	/* 0x112e: je     12e4 <generic_sleepable_preload+0x12e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e4;
	}
x86_l_1134:
	/* 0x1134: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1137:
	/* 0x1137: jne    1345 <generic_sleepable_preload+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1345;
	}
x86_l_113d:
	/* 0x113d: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1143:
	/* 0x1143: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1149:
	/* 0x1149: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_114c:
	/* 0x114c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1151:
	/* 0x1151: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1156:
	/* 0x1156: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_115b:
	/* 0x115b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115d:
	/* 0x115d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1162:
	/* 0x1162: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1164:
	/* 0x1164: je     12f0 <generic_sleepable_preload+0x12f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f0;
	}
x86_l_116a:
	/* 0x116a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_116c:
	/* 0x116c: jmp    1345 <generic_sleepable_preload+0x1345> */
	goto x86_l_1345;
x86_l_1171:
	/* 0x1171: movzx  ecx,BYTE PTR [rdi+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_1178:
	/* 0x1178: movzx  eax,WORD PTR [rdi+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_117f:
	/* 0x117f: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_1185:
	/* 0x1185: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1187:
	/* 0x1187: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_118a:
	/* 0x118a: jle    1260 <generic_sleepable_preload+0x1260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1260;
	}
x86_l_1190:
	/* 0x1190: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1193:
	/* 0x1193: jle    128a <generic_sleepable_preload+0x128a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_128a;
	}
x86_l_1199:
	/* 0x1199: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_119c:
	/* 0x119c: jle    1908 <generic_sleepable_preload+0x1908> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6408ULL;
	}
x86_l_11a2:
	/* 0x11a2: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_11aa:
	/* 0x11aa: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_11ad:
	/* 0x11ad: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_11b3:
	/* 0x11b3: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11b8:
	/* 0x11b8: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_11bb:
	/* 0x11bb: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_11c1:
	/* 0x11c1: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_11c4:
	/* 0x11c4: jne    1932 <generic_sleepable_preload+0x1932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6450ULL;
	}
x86_l_11ca:
	/* 0x11ca: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11cf:
	/* 0x11cf: jmp    191f <generic_sleepable_preload+0x191f> */
	return 6431ULL;
x86_l_11d4:
	/* 0x11d4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11d7:
	/* 0x11d7: je     1315 <generic_sleepable_preload+0x1315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1315;
	}
x86_l_11dd:
	/* 0x11dd: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11e0:
	/* 0x11e0: jne    1345 <generic_sleepable_preload+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1345;
	}
x86_l_11e6:
	/* 0x11e6: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_11ec:
	/* 0x11ec: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_11f2:
	/* 0x11f2: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11f5:
	/* 0x11f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11fa:
	/* 0x11fa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11fd:
	/* 0x11fd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1202:
	/* 0x1202: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1207:
	/* 0x1207: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1209:
	/* 0x1209: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120b:
	/* 0x120b: jne    1340 <generic_sleepable_preload+0x1340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1340;
	}
x86_l_1211:
	/* 0x1211: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1217:
	/* 0x1217: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_121d:
	/* 0x121d: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1220:
	/* 0x1220: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1225:
	/* 0x1225: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122a:
	/* 0x122a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_122f:
	/* 0x122f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1231:
	/* 0x1231: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1233:
	/* 0x1233: jne    1340 <generic_sleepable_preload+0x1340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1340;
	}
x86_l_1239:
	/* 0x1239: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_123e:
	/* 0x123e: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_1245:
	/* 0x1245: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_124c:
	/* 0x124c: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_1253:
	/* 0x1253: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1258:
	/* 0x1258: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_125b:
	/* 0x125b: jmp    1ed2 <generic_sleepable_preload+0x1ed2> */
	return 7890ULL;
x86_l_1260:
	/* 0x1260: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1263:
	/* 0x1263: jg     12b7 <generic_sleepable_preload+0x12b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12b7;
	}
x86_l_1265:
	/* 0x1265: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1268:
	/* 0x1268: jg     18d9 <generic_sleepable_preload+0x18d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6361ULL;
	}
x86_l_126e:
	/* 0x126e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1271:
	/* 0x1271: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1273:
	/* 0x1273: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_1279:
	/* 0x1279: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_127c:
	/* 0x127c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_127f:
	/* 0x127f: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_1285:
	/* 0x1285: jmp    1932 <generic_sleepable_preload+0x1932> */
	return 6450ULL;
x86_l_128a:
	/* 0x128a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_128d:
	/* 0x128d: jg     18c0 <generic_sleepable_preload+0x18c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6336ULL;
	}
x86_l_1293:
	/* 0x1293: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_129b:
	/* 0x129b: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_129e:
	/* 0x129e: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_12a4:
	/* 0x12a4: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_12a9:
	/* 0x12a9: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_12ac:
	/* 0x12ac: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_12b2:
	/* 0x12b2: jmp    1932 <generic_sleepable_preload+0x1932> */
	return 6450ULL;
x86_l_12b7:
	/* 0x12b7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12ba:
	/* 0x12ba: jg     18ef <generic_sleepable_preload+0x18ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 6383ULL;
	}
x86_l_12c0:
	/* 0x12c0: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12c8:
	/* 0x12c8: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_12cb:
	/* 0x12cb: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_12d1:
	/* 0x12d1: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12d6:
	/* 0x12d6: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12d9:
	/* 0x12d9: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6431ULL;
	}
x86_l_12df:
	/* 0x12df: jmp    1932 <generic_sleepable_preload+0x1932> */
	return 6450ULL;
x86_l_12e4:
	/* 0x12e4: mov    rax,QWORD PTR [rdi+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_12eb:
	/* 0x12eb: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f0:
	/* 0x12f0: movzx  eax,BYTE PTR [rdi+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_12f7:
	/* 0x12f7: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_12fe:
	/* 0x12fe: cmp    BYTE PTR [rdi+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_1305:
	/* 0x1305: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_130a:
	/* 0x130a: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_130f:
	/* 0x130f: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1313:
	/* 0x1313: jmp    1345 <generic_sleepable_preload+0x1345> */
	goto x86_l_1345;
x86_l_1315:
	/* 0x1315: mov    edx,DWORD PTR [rdi+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_131b:
	/* 0x131b: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1321:
	/* 0x1321: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1324:
	/* 0x1324: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1329:
	/* 0x1329: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_132c:
	/* 0x132c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1331:
	/* 0x1331: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1336:
	/* 0x1336: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1338:
	/* 0x1338: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_133a:
	/* 0x133a: je     1ec1 <generic_sleepable_preload+0x1ec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7873ULL;
	}
x86_l_1340:
	/* 0x1340: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1342:
	/* 0x1342: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1345:
	/* 0x1345: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134a:
	/* 0x134a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134c:
	/* 0x134c: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_134f:
	/* 0x134f: cmp    WORD PTR [rdi+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1354:
	/* 0x1354: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_135a:
	/* 0x135a: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1361:
	/* 0x1361: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1364:
	/* 0x1364: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1367:
	/* 0x1367: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_136a:
	/* 0x136a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136f:
	/* 0x136f: movzx  eax,WORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1373:
	/* 0x1373: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1375:
	/* 0x1375: je     1600 <generic_sleepable_preload+0x1600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5632ULL;
	}
x86_l_137b:
	/* 0x137b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_137e:
	/* 0x137e: je     13a3 <generic_sleepable_preload+0x13a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a3;
	}
x86_l_1380:
	/* 0x1380: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1385:
	/* 0x1385: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138a:
	/* 0x138a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138f:
	/* 0x138f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1394:
	/* 0x1394: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1396:
	/* 0x1396: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139b:
	/* 0x139b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_139d:
	/* 0x139d: js     18b6 <generic_sleepable_preload+0x18b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6326ULL;
	}
x86_l_13a3:
	/* 0x13a3: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_13a8:
	/* 0x13a8: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_13ae:
	/* 0x13ae: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13b1:
	/* 0x13b1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_13b6:
	/* 0x13b6: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_13bb:
	/* 0x13bb: je     13e0 <generic_sleepable_preload+0x13e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e0;
	}
x86_l_13bd:
	/* 0x13bd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13c2:
	/* 0x13c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c7:
	/* 0x13c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cc:
	/* 0x13cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13d1:
	/* 0x13d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d3:
	/* 0x13d3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d8:
	/* 0x13d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13da:
	/* 0x13da: js     1eb0 <generic_sleepable_preload+0x1eb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7856ULL;
	}
x86_l_13e0:
	/* 0x13e0: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_13e8:
	/* 0x13e8: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_13ee:
	/* 0x13ee: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13f4:
	/* 0x13f4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_13f9:
	/* 0x13f9: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1401:
	/* 0x1401: je     1426 <generic_sleepable_preload+0x1426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1426;
	}
x86_l_1403:
	/* 0x1403: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1408:
	/* 0x1408: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_140d:
	/* 0x140d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1412:
	/* 0x1412: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1417:
	/* 0x1417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1419:
	/* 0x1419: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_141e:
	/* 0x141e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1420:
	/* 0x1420: js     1ef0 <generic_sleepable_preload+0x1ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7920ULL;
	}
x86_l_1426:
	/* 0x1426: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_142e:
	/* 0x142e: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1434:
	/* 0x1434: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_143a:
	/* 0x143a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_143f:
	/* 0x143f: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1447:
	/* 0x1447: je     146c <generic_sleepable_preload+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146c;
	}
x86_l_1449:
	/* 0x1449: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_144e:
	/* 0x144e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1453:
	/* 0x1453: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1458:
	/* 0x1458: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_145d:
	/* 0x145d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145f:
	/* 0x145f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1464:
	/* 0x1464: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1466:
	/* 0x1466: js     1f01 <generic_sleepable_preload+0x1f01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7937ULL;
	}
x86_l_146c:
	/* 0x146c: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1474:
	/* 0x1474: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_147a:
	/* 0x147a: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1480:
	/* 0x1480: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1485:
	/* 0x1485: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_148d:
	/* 0x148d: je     14b2 <generic_sleepable_preload+0x14b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b2;
	}
x86_l_148f:
	/* 0x148f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1494:
	/* 0x1494: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1499:
	/* 0x1499: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_149e:
	/* 0x149e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14a3:
	/* 0x14a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a5:
	/* 0x14a5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14aa:
	/* 0x14aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14ac:
	/* 0x14ac: js     1f12 <generic_sleepable_preload+0x1f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7954ULL;
	}
x86_l_14b2:
	/* 0x14b2: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_14ba:
	/* 0x14ba: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_14c0:
	/* 0x14c0: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14c6:
	/* 0x14c6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_14cb:
	/* 0x14cb: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_14d3:
	/* 0x14d3: je     14f8 <generic_sleepable_preload+0x14f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5368ULL;
	}
x86_l_14d5:
	/* 0x14d5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14da:
	/* 0x14da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14df:
	/* 0x14df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e4:
	/* 0x14e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14e9:
	/* 0x14e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14eb:
	/* 0x14eb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 5360ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5360ULL: goto x86_l_14f0;
	case 5362ULL: goto x86_l_14f2;
	case 5368ULL: goto x86_l_14f8;
	case 5376ULL: goto x86_l_1500;
	case 5382ULL: goto x86_l_1506;
	case 5388ULL: goto x86_l_150c;
	case 5393ULL: goto x86_l_1511;
	case 5401ULL: goto x86_l_1519;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5425ULL: goto x86_l_1531;
	case 5427ULL: goto x86_l_1533;
	case 5433ULL: goto x86_l_1539;
	case 5438ULL: goto x86_l_153e;
	case 5446ULL: goto x86_l_1546;
	case 5452ULL: goto x86_l_154c;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5471ULL: goto x86_l_155f;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5495ULL: goto x86_l_1577;
	case 5497ULL: goto x86_l_1579;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5516ULL: goto x86_l_158c;
	case 5522ULL: goto x86_l_1592;
	case 5528ULL: goto x86_l_1598;
	case 5533ULL: goto x86_l_159d;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5565ULL: goto x86_l_15bd;
	case 5567ULL: goto x86_l_15bf;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5608ULL: goto x86_l_15e8;
	case 5616ULL: goto x86_l_15f0;
	case 5622ULL: goto x86_l_15f6;
	case 5627ULL: goto x86_l_15fb;
	case 5632ULL: goto x86_l_1600;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5666ULL: goto x86_l_1622;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5683ULL: goto x86_l_1633;
	case 5686ULL: goto x86_l_1636;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5718ULL: goto x86_l_1656;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5741ULL: goto x86_l_166d;
	case 5747ULL: goto x86_l_1673;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5773ULL: goto x86_l_168d;
	case 5778ULL: goto x86_l_1692;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5797ULL: goto x86_l_16a5;
	case 5803ULL: goto x86_l_16ab;
	case 5811ULL: goto x86_l_16b3;
	case 5817ULL: goto x86_l_16b9;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5836ULL: goto x86_l_16cc;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5867ULL: goto x86_l_16eb;
	case 5873ULL: goto x86_l_16f1;
	case 5881ULL: goto x86_l_16f9;
	case 5887ULL: goto x86_l_16ff;
	case 5893ULL: goto x86_l_1705;
	case 5898ULL: goto x86_l_170a;
	case 5906ULL: goto x86_l_1712;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5918ULL: goto x86_l_171e;
	case 5923ULL: goto x86_l_1723;
	case 5928ULL: goto x86_l_1728;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5937ULL: goto x86_l_1731;
	case 5943ULL: goto x86_l_1737;
	case 5951ULL: goto x86_l_173f;
	case 5957ULL: goto x86_l_1745;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6000ULL: goto x86_l_1770;
	case 6005ULL: goto x86_l_1775;
	case 6007ULL: goto x86_l_1777;
	case 6013ULL: goto x86_l_177d;
	case 6021ULL: goto x86_l_1785;
	case 6027ULL: goto x86_l_178b;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6046ULL: goto x86_l_179e;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6091ULL: goto x86_l_17cb;
	case 6097ULL: goto x86_l_17d1;
	case 6100ULL: goto x86_l_17d4;
	case 6106ULL: goto x86_l_17da;
	case 6111ULL: goto x86_l_17df;
	case 6119ULL: goto x86_l_17e7;
	case 6121ULL: goto x86_l_17e9;
	case 6126ULL: goto x86_l_17ee;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6143ULL: goto x86_l_17ff;
	case 6145ULL: goto x86_l_1801;
	case 6151ULL: goto x86_l_1807;
	case 6156ULL: goto x86_l_180c;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6172ULL: goto x86_l_181c;
	case 6178ULL: goto x86_l_1822;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6197ULL: goto x86_l_1835;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6214ULL: goto x86_l_1846;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6223ULL: goto x86_l_184f;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6250ULL: goto x86_l_186a;
	case 6256ULL: goto x86_l_1870;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6275ULL: goto x86_l_1883;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6291ULL: goto x86_l_1893;
	case 6296ULL: goto x86_l_1898;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6310ULL: goto x86_l_18a6;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6344ULL: goto x86_l_18c8;
	case 6347ULL: goto x86_l_18cb;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6357ULL: goto x86_l_18d5;
	case 6359ULL: goto x86_l_18d7;
	case 6361ULL: goto x86_l_18d9;
	case 6366ULL: goto x86_l_18de;
	case 6369ULL: goto x86_l_18e1;
	case 6371ULL: goto x86_l_18e3;
	case 6376ULL: goto x86_l_18e8;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6391ULL: goto x86_l_18f7;
	case 6394ULL: goto x86_l_18fa;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6431ULL: goto x86_l_191f;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6438ULL: goto x86_l_1926;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6460ULL: goto x86_l_193c;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6474ULL: goto x86_l_194a;
	case 6481ULL: goto x86_l_1951;
	case 6484ULL: goto x86_l_1954;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6499ULL: goto x86_l_1963;
	case 6501ULL: goto x86_l_1965;
	case 6507ULL: goto x86_l_196b;
	case 6510ULL: goto x86_l_196e;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6532ULL: goto x86_l_1984;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6541ULL: goto x86_l_198d;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6602ULL: goto x86_l_19ca;
	case 6608ULL: goto x86_l_19d0;
	case 6616ULL: goto x86_l_19d8;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6663ULL: goto x86_l_1a07;
	case 6665ULL: goto x86_l_1a09;
	case 6670ULL: goto x86_l_1a0e;
	case 6672ULL: goto x86_l_1a10;
	case 6678ULL: goto x86_l_1a16;
	case 6686ULL: goto x86_l_1a1e;
	case 6692ULL: goto x86_l_1a24;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6742ULL: goto x86_l_1a56;
	case 6748ULL: goto x86_l_1a5c;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6781ULL: goto x86_l_1a7d;
	case 6783ULL: goto x86_l_1a7f;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6818ULL: goto x86_l_1aa2;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6882ULL: goto x86_l_1ae2;
	case 6888ULL: goto x86_l_1ae8;
	case 6896ULL: goto x86_l_1af0;
	case 6902ULL: goto x86_l_1af6;
	case 6908ULL: goto x86_l_1afc;
	case 6913ULL: goto x86_l_1b01;
	case 6921ULL: goto x86_l_1b09;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6966ULL: goto x86_l_1b36;
	case 6972ULL: goto x86_l_1b3c;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7036ULL: goto x86_l_1b7c;
	case 7042ULL: goto x86_l_1b82;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7061ULL: goto x86_l_1b95;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7093ULL: goto x86_l_1bb5;
	case 7098ULL: goto x86_l_1bba;
	case 7106ULL: goto x86_l_1bc2;
	case 7111ULL: goto x86_l_1bc7;
	case 7117ULL: goto x86_l_1bcd;
	case 7123ULL: goto x86_l_1bd3;
	case 7128ULL: goto x86_l_1bd8;
	case 7136ULL: goto x86_l_1be0;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7155ULL: goto x86_l_1bf3;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7177ULL: goto x86_l_1c09;
	case 7179ULL: goto x86_l_1c0b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14f0:
	/* 0x14f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14f2:
	/* 0x14f2: js     1f23 <generic_sleepable_preload+0x1f23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7971ULL;
	}
x86_l_14f8:
	/* 0x14f8: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1500:
	/* 0x1500: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1506:
	/* 0x1506: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_150c:
	/* 0x150c: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1511:
	/* 0x1511: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1519:
	/* 0x1519: je     1539 <generic_sleepable_preload+0x1539> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1539;
	}
x86_l_151b:
	/* 0x151b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1520:
	/* 0x1520: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1525:
	/* 0x1525: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152a:
	/* 0x152a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_152f:
	/* 0x152f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1531:
	/* 0x1531: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1533:
	/* 0x1533: js     5d79 <generic_sleepable_preload+0x5d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23929ULL;
	}
x86_l_1539:
	/* 0x1539: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_153e:
	/* 0x153e: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1546:
	/* 0x1546: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_154c:
	/* 0x154c: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1552:
	/* 0x1552: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1557:
	/* 0x1557: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_155f:
	/* 0x155f: je     157f <generic_sleepable_preload+0x157f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157f;
	}
x86_l_1561:
	/* 0x1561: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1566:
	/* 0x1566: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_156b:
	/* 0x156b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1570:
	/* 0x1570: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1575:
	/* 0x1575: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1577:
	/* 0x1577: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1579:
	/* 0x1579: js     5ef3 <generic_sleepable_preload+0x5ef3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24307ULL;
	}
x86_l_157f:
	/* 0x157f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1584:
	/* 0x1584: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_158c:
	/* 0x158c: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1592:
	/* 0x1592: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1598:
	/* 0x1598: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_159d:
	/* 0x159d: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_15a5:
	/* 0x15a5: je     15c5 <generic_sleepable_preload+0x15c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15c5;
	}
x86_l_15a7:
	/* 0x15a7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ac:
	/* 0x15ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b1:
	/* 0x15b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b6:
	/* 0x15b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15bb:
	/* 0x15bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15bd:
	/* 0x15bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15bf:
	/* 0x15bf: js     5fff <generic_sleepable_preload+0x5fff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24575ULL;
	}
x86_l_15c5:
	/* 0x15c5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15ca:
	/* 0x15ca: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_15d2:
	/* 0x15d2: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15d7:
	/* 0x15d7: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_15dd:
	/* 0x15dd: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_15e3:
	/* 0x15e3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_15e8:
	/* 0x15e8: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_15f0:
	/* 0x15f0: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_15f6:
	/* 0x15f6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15fb:
	/* 0x15fb: jmp    188e <generic_sleepable_preload+0x188e> */
	goto x86_l_188e;
x86_l_1600:
	/* 0x1600: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1603:
	/* 0x1603: je     1628 <generic_sleepable_preload+0x1628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1628;
	}
x86_l_1605:
	/* 0x1605: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_160a:
	/* 0x160a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160f:
	/* 0x160f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1614:
	/* 0x1614: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1619:
	/* 0x1619: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161b:
	/* 0x161b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1620:
	/* 0x1620: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1622:
	/* 0x1622: js     18b6 <generic_sleepable_preload+0x18b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18b6;
	}
x86_l_1628:
	/* 0x1628: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_162d:
	/* 0x162d: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1633:
	/* 0x1633: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1636:
	/* 0x1636: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_163b:
	/* 0x163b: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1640:
	/* 0x1640: je     1665 <generic_sleepable_preload+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1665;
	}
x86_l_1642:
	/* 0x1642: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1647:
	/* 0x1647: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_164c:
	/* 0x164c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1651:
	/* 0x1651: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1656:
	/* 0x1656: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1658:
	/* 0x1658: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_165d:
	/* 0x165d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_165f:
	/* 0x165f: js     1eb0 <generic_sleepable_preload+0x1eb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7856ULL;
	}
x86_l_1665:
	/* 0x1665: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_166d:
	/* 0x166d: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1673:
	/* 0x1673: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1679:
	/* 0x1679: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_167e:
	/* 0x167e: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1686:
	/* 0x1686: je     16ab <generic_sleepable_preload+0x16ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ab;
	}
x86_l_1688:
	/* 0x1688: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_168d:
	/* 0x168d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1692:
	/* 0x1692: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1697:
	/* 0x1697: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_169c:
	/* 0x169c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169e:
	/* 0x169e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a3:
	/* 0x16a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16a5:
	/* 0x16a5: js     1ef0 <generic_sleepable_preload+0x1ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7920ULL;
	}
x86_l_16ab:
	/* 0x16ab: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_16b3:
	/* 0x16b3: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_16b9:
	/* 0x16b9: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16bf:
	/* 0x16bf: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_16c4:
	/* 0x16c4: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_16cc:
	/* 0x16cc: je     16f1 <generic_sleepable_preload+0x16f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16f1;
	}
x86_l_16ce:
	/* 0x16ce: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_16d3:
	/* 0x16d3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d8:
	/* 0x16d8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16dd:
	/* 0x16dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16e2:
	/* 0x16e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e4:
	/* 0x16e4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e9:
	/* 0x16e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16eb:
	/* 0x16eb: js     1f01 <generic_sleepable_preload+0x1f01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7937ULL;
	}
x86_l_16f1:
	/* 0x16f1: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_16f9:
	/* 0x16f9: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_16ff:
	/* 0x16ff: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1705:
	/* 0x1705: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_170a:
	/* 0x170a: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1712:
	/* 0x1712: je     1737 <generic_sleepable_preload+0x1737> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1737;
	}
x86_l_1714:
	/* 0x1714: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1719:
	/* 0x1719: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171e:
	/* 0x171e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1723:
	/* 0x1723: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1728:
	/* 0x1728: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172a:
	/* 0x172a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_172f:
	/* 0x172f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1731:
	/* 0x1731: js     1f12 <generic_sleepable_preload+0x1f12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7954ULL;
	}
x86_l_1737:
	/* 0x1737: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_173f:
	/* 0x173f: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1745:
	/* 0x1745: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_174b:
	/* 0x174b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1750:
	/* 0x1750: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1758:
	/* 0x1758: je     177d <generic_sleepable_preload+0x177d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177d;
	}
x86_l_175a:
	/* 0x175a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_175f:
	/* 0x175f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1764:
	/* 0x1764: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1769:
	/* 0x1769: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_176e:
	/* 0x176e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1770:
	/* 0x1770: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1775:
	/* 0x1775: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1777:
	/* 0x1777: js     1f23 <generic_sleepable_preload+0x1f23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7971ULL;
	}
x86_l_177d:
	/* 0x177d: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1785:
	/* 0x1785: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_178b:
	/* 0x178b: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1791:
	/* 0x1791: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1796:
	/* 0x1796: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_179e:
	/* 0x179e: je     17be <generic_sleepable_preload+0x17be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17be;
	}
x86_l_17a0:
	/* 0x17a0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17a5:
	/* 0x17a5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17aa:
	/* 0x17aa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17af:
	/* 0x17af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17b4:
	/* 0x17b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b6:
	/* 0x17b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17b8:
	/* 0x17b8: js     5d79 <generic_sleepable_preload+0x5d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23929ULL;
	}
x86_l_17be:
	/* 0x17be: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17c3:
	/* 0x17c3: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_17cb:
	/* 0x17cb: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_17d1:
	/* 0x17d1: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_17d4:
	/* 0x17d4: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17da:
	/* 0x17da: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_17df:
	/* 0x17df: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_17e7:
	/* 0x17e7: je     1807 <generic_sleepable_preload+0x1807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1807;
	}
x86_l_17e9:
	/* 0x17e9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17ee:
	/* 0x17ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f3:
	/* 0x17f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f8:
	/* 0x17f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17fd:
	/* 0x17fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ff:
	/* 0x17ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1801:
	/* 0x1801: js     5f97 <generic_sleepable_preload+0x5f97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24471ULL;
	}
x86_l_1807:
	/* 0x1807: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180c:
	/* 0x180c: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1814:
	/* 0x1814: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1819:
	/* 0x1819: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_181c:
	/* 0x181c: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1822:
	/* 0x1822: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1828:
	/* 0x1828: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_182d:
	/* 0x182d: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1835:
	/* 0x1835: je     1855 <generic_sleepable_preload+0x1855> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1855;
	}
x86_l_1837:
	/* 0x1837: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_183c:
	/* 0x183c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1841:
	/* 0x1841: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1846:
	/* 0x1846: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_184b:
	/* 0x184b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184d:
	/* 0x184d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_184f:
	/* 0x184f: js     6069 <generic_sleepable_preload+0x6069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24681ULL;
	}
x86_l_1855:
	/* 0x1855: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_185a:
	/* 0x185a: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1862:
	/* 0x1862: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1867:
	/* 0x1867: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_186a:
	/* 0x186a: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1870:
	/* 0x1870: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1876:
	/* 0x1876: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_187b:
	/* 0x187b: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1883:
	/* 0x1883: je     1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7979ULL;
	}
x86_l_1889:
	/* 0x1889: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_188e:
	/* 0x188e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1893:
	/* 0x1893: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1898:
	/* 0x1898: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189d:
	/* 0x189d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189f:
	/* 0x189f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18a4:
	/* 0x18a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18a6:
	/* 0x18a6: jns    1f2b <generic_sleepable_preload+0x1f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7979ULL;
	}
x86_l_18ac:
	/* 0x18ac: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_18b1:
	/* 0x18b1: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	return 7976ULL;
x86_l_18b6:
	/* 0x18b6: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_18bb:
	/* 0x18bb: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	return 7976ULL;
x86_l_18c0:
	/* 0x18c0: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18c8:
	/* 0x18c8: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_18cb:
	/* 0x18cb: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_18cd:
	/* 0x18cd: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18d2:
	/* 0x18d2: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_18d5:
	/* 0x18d5: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_18d7:
	/* 0x18d7: jmp    1932 <generic_sleepable_preload+0x1932> */
	goto x86_l_1932;
x86_l_18d9:
	/* 0x18d9: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18de:
	/* 0x18de: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_18e1:
	/* 0x18e1: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_18e3:
	/* 0x18e3: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e8:
	/* 0x18e8: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_18eb:
	/* 0x18eb: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_18ed:
	/* 0x18ed: jmp    1932 <generic_sleepable_preload+0x1932> */
	goto x86_l_1932;
x86_l_18ef:
	/* 0x18ef: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18f7:
	/* 0x18f7: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_18fa:
	/* 0x18fa: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_18fc:
	/* 0x18fc: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1901:
	/* 0x1901: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1904:
	/* 0x1904: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_1906:
	/* 0x1906: jmp    1932 <generic_sleepable_preload+0x1932> */
	goto x86_l_1932;
x86_l_1908:
	/* 0x1908: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1910:
	/* 0x1910: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1913:
	/* 0x1913: je     191f <generic_sleepable_preload+0x191f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_191f;
	}
x86_l_1915:
	/* 0x1915: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_191a:
	/* 0x191a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_191d:
	/* 0x191d: jne    1932 <generic_sleepable_preload+0x1932> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1932;
	}
x86_l_191f:
	/* 0x191f: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1922:
	/* 0x1922: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_1924:
	/* 0x1924: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1926:
	/* 0x1926: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_192b:
	/* 0x192b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_192d:
	/* 0x192d: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_1932:
	/* 0x1932: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1937:
	/* 0x1937: mov    ebx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_193a:
	/* 0x193a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193c:
	/* 0x193c: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_193f:
	/* 0x193f: cmp    WORD PTR [rdi+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1944:
	/* 0x1944: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_194a:
	/* 0x194a: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1951:
	/* 0x1951: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1954:
	/* 0x1954: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1957:
	/* 0x1957: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_195a:
	/* 0x195a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195f:
	/* 0x195f: movzx  eax,WORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_1963:
	/* 0x1963: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1965:
	/* 0x1965: je     1bf0 <generic_sleepable_preload+0x1bf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bf0;
	}
x86_l_196b:
	/* 0x196b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_196e:
	/* 0x196e: je     1993 <generic_sleepable_preload+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1993;
	}
x86_l_1970:
	/* 0x1970: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1975:
	/* 0x1975: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197a:
	/* 0x197a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197f:
	/* 0x197f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1984:
	/* 0x1984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1986:
	/* 0x1986: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_198b:
	/* 0x198b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_198d:
	/* 0x198d: js     1ea6 <generic_sleepable_preload+0x1ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7846ULL;
	}
x86_l_1993:
	/* 0x1993: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1998:
	/* 0x1998: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_199e:
	/* 0x199e: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19a1:
	/* 0x19a1: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19a6:
	/* 0x19a6: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_19ab:
	/* 0x19ab: je     19d0 <generic_sleepable_preload+0x19d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19d0;
	}
x86_l_19ad:
	/* 0x19ad: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19b2:
	/* 0x19b2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b7:
	/* 0x19b7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19bc:
	/* 0x19bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19c1:
	/* 0x19c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c3:
	/* 0x19c3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c8:
	/* 0x19c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19ca:
	/* 0x19ca: js     1eb7 <generic_sleepable_preload+0x1eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7863ULL;
	}
x86_l_19d0:
	/* 0x19d0: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_19d8:
	/* 0x19d8: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_19de:
	/* 0x19de: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19e4:
	/* 0x19e4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19e9:
	/* 0x19e9: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_19f1:
	/* 0x19f1: je     1a16 <generic_sleepable_preload+0x1a16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a16;
	}
x86_l_19f3:
	/* 0x19f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19f8:
	/* 0x19f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fd:
	/* 0x19fd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a02:
	/* 0x1a02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a07:
	/* 0x1a07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a09:
	/* 0x1a09: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a0e:
	/* 0x1a0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a10:
	/* 0x1a10: js     1ef7 <generic_sleepable_preload+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7927ULL;
	}
x86_l_1a16:
	/* 0x1a16: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1a1e:
	/* 0x1a1e: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1a24:
	/* 0x1a24: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1a2a:
	/* 0x1a2a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a2f:
	/* 0x1a2f: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a37:
	/* 0x1a37: je     1a5c <generic_sleepable_preload+0x1a5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5c;
	}
x86_l_1a39:
	/* 0x1a39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a43:
	/* 0x1a43: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a48:
	/* 0x1a48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a4d:
	/* 0x1a4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4f:
	/* 0x1a4f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a54:
	/* 0x1a54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a56:
	/* 0x1a56: js     1f08 <generic_sleepable_preload+0x1f08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7944ULL;
	}
x86_l_1a5c:
	/* 0x1a5c: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1a64:
	/* 0x1a64: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1a6a:
	/* 0x1a6a: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a70:
	/* 0x1a70: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a75:
	/* 0x1a75: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1a7d:
	/* 0x1a7d: je     1aa2 <generic_sleepable_preload+0x1aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1aa2;
	}
x86_l_1a7f:
	/* 0x1a7f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a84:
	/* 0x1a84: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a89:
	/* 0x1a89: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8e:
	/* 0x1a8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a93:
	/* 0x1a93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a95:
	/* 0x1a95: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a9a:
	/* 0x1a9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a9c:
	/* 0x1a9c: js     1f19 <generic_sleepable_preload+0x1f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7961ULL;
	}
x86_l_1aa2:
	/* 0x1aa2: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1aaa:
	/* 0x1aaa: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1ab0:
	/* 0x1ab0: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1ab6:
	/* 0x1ab6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1abb:
	/* 0x1abb: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1ac3:
	/* 0x1ac3: je     1ae8 <generic_sleepable_preload+0x1ae8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae8;
	}
x86_l_1ac5:
	/* 0x1ac5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1aca:
	/* 0x1aca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1acf:
	/* 0x1acf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ad9:
	/* 0x1ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adb:
	/* 0x1adb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae0:
	/* 0x1ae0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ae2:
	/* 0x1ae2: js     1faa <generic_sleepable_preload+0x1faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8106ULL;
	}
x86_l_1ae8:
	/* 0x1ae8: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1af0:
	/* 0x1af0: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1af6:
	/* 0x1af6: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1afc:
	/* 0x1afc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b01:
	/* 0x1b01: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1b09:
	/* 0x1b09: je     1b29 <generic_sleepable_preload+0x1b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b29;
	}
x86_l_1b0b:
	/* 0x1b0b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b10:
	/* 0x1b10: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b15:
	/* 0x1b15: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b1f:
	/* 0x1b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b21:
	/* 0x1b21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b23:
	/* 0x1b23: js     5d8b <generic_sleepable_preload+0x5d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23947ULL;
	}
x86_l_1b29:
	/* 0x1b29: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b2e:
	/* 0x1b2e: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1b36:
	/* 0x1b36: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1b3c:
	/* 0x1b3c: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b42:
	/* 0x1b42: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b47:
	/* 0x1b47: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1b4f:
	/* 0x1b4f: je     1b6f <generic_sleepable_preload+0x1b6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6f;
	}
x86_l_1b51:
	/* 0x1b51: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b56:
	/* 0x1b56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b5b:
	/* 0x1b5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b60:
	/* 0x1b60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b65:
	/* 0x1b65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b67:
	/* 0x1b67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b69:
	/* 0x1b69: js     5f05 <generic_sleepable_preload+0x5f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24325ULL;
	}
x86_l_1b6f:
	/* 0x1b6f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b74:
	/* 0x1b74: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1b7c:
	/* 0x1b7c: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1b82:
	/* 0x1b82: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b88:
	/* 0x1b88: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b8d:
	/* 0x1b8d: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1b95:
	/* 0x1b95: je     1bb5 <generic_sleepable_preload+0x1bb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb5;
	}
x86_l_1b97:
	/* 0x1b97: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba1:
	/* 0x1ba1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bab:
	/* 0x1bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bad:
	/* 0x1bad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1baf:
	/* 0x1baf: js     6016 <generic_sleepable_preload+0x6016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24598ULL;
	}
x86_l_1bb5:
	/* 0x1bb5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bba:
	/* 0x1bba: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1bc2:
	/* 0x1bc2: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bc7:
	/* 0x1bc7: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1bcd:
	/* 0x1bcd: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bd3:
	/* 0x1bd3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bd8:
	/* 0x1bd8: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1be0:
	/* 0x1be0: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8114ULL;
	}
x86_l_1be6:
	/* 0x1be6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1beb:
	/* 0x1beb: jmp    1e7e <generic_sleepable_preload+0x1e7e> */
	return 7806ULL;
x86_l_1bf0:
	/* 0x1bf0: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1bf3:
	/* 0x1bf3: je     1c18 <generic_sleepable_preload+0x1c18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7192ULL;
	}
x86_l_1bf5:
	/* 0x1bf5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bff:
	/* 0x1bff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c04:
	/* 0x1c04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c09:
	/* 0x1c09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0b:
	/* 0x1c0b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 7184ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7203ULL: goto x86_l_1c23;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7240ULL: goto x86_l_1c48;
	case 7245ULL: goto x86_l_1c4d;
	case 7247ULL: goto x86_l_1c4f;
	case 7253ULL: goto x86_l_1c55;
	case 7261ULL: goto x86_l_1c5d;
	case 7267ULL: goto x86_l_1c63;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7286ULL: goto x86_l_1c76;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7323ULL: goto x86_l_1c9b;
	case 7331ULL: goto x86_l_1ca3;
	case 7337ULL: goto x86_l_1ca9;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7356ULL: goto x86_l_1cbc;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7378ULL: goto x86_l_1cd2;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7387ULL: goto x86_l_1cdb;
	case 7393ULL: goto x86_l_1ce1;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7426ULL: goto x86_l_1d02;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7463ULL: goto x86_l_1d27;
	case 7471ULL: goto x86_l_1d2f;
	case 7477ULL: goto x86_l_1d35;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7496ULL: goto x86_l_1d48;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7508ULL: goto x86_l_1d54;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7533ULL: goto x86_l_1d6d;
	case 7541ULL: goto x86_l_1d75;
	case 7547ULL: goto x86_l_1d7b;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7598ULL: goto x86_l_1dae;
	case 7603ULL: goto x86_l_1db3;
	case 7611ULL: goto x86_l_1dbb;
	case 7617ULL: goto x86_l_1dc1;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7661ULL: goto x86_l_1ded;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7692ULL: goto x86_l_1e0c;
	case 7698ULL: goto x86_l_1e12;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7749ULL: goto x86_l_1e45;
	case 7754ULL: goto x86_l_1e4a;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7770ULL: goto x86_l_1e5a;
	case 7776ULL: goto x86_l_1e60;
	case 7782ULL: goto x86_l_1e66;
	case 7787ULL: goto x86_l_1e6b;
	case 7795ULL: goto x86_l_1e73;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7823ULL: goto x86_l_1e8f;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7904ULL: goto x86_l_1ee0;
	case 7907ULL: goto x86_l_1ee3;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7954ULL: goto x86_l_1f12;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7976ULL: goto x86_l_1f28;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7997ULL: goto x86_l_1f3d;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8048ULL: goto x86_l_1f70;
	case 8053ULL: goto x86_l_1f75;
	case 8055ULL: goto x86_l_1f77;
	case 8058ULL: goto x86_l_1f7a;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8148ULL: goto x86_l_1fd4;
	case 8153ULL: goto x86_l_1fd9;
	case 8160ULL: goto x86_l_1fe0;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8172ULL: goto x86_l_1fec;
	case 8178ULL: goto x86_l_1ff2;
	case 8181ULL: goto x86_l_1ff5;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8196ULL: goto x86_l_2004;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8215ULL: goto x86_l_2017;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8231ULL: goto x86_l_2027;
	case 8233ULL: goto x86_l_2029;
	case 8236ULL: goto x86_l_202c;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8253ULL: goto x86_l_203d;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8263ULL: goto x86_l_2047;
	case 8265ULL: goto x86_l_2049;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8279ULL: goto x86_l_2057;
	case 8284ULL: goto x86_l_205c;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8298ULL: goto x86_l_206a;
	case 8300ULL: goto x86_l_206c;
	case 8302ULL: goto x86_l_206e;
	case 8309ULL: goto x86_l_2075;
	case 8311ULL: goto x86_l_2077;
	case 8314ULL: goto x86_l_207a;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8344ULL: goto x86_l_2098;
	case 8350ULL: goto x86_l_209e;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8377ULL: goto x86_l_20b9;
	case 8383ULL: goto x86_l_20bf;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8397ULL: goto x86_l_20cd;
	case 8404ULL: goto x86_l_20d4;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8415ULL: goto x86_l_20df;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8456ULL: goto x86_l_2108;
	case 8461ULL: goto x86_l_210d;
	case 8464ULL: goto x86_l_2110;
	case 8470ULL: goto x86_l_2116;
	case 8475ULL: goto x86_l_211b;
	case 8478ULL: goto x86_l_211e;
	case 8484ULL: goto x86_l_2124;
	case 8489ULL: goto x86_l_2129;
	case 8492ULL: goto x86_l_212c;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8507ULL: goto x86_l_213b;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8522ULL: goto x86_l_214a;
	case 8527ULL: goto x86_l_214f;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8542ULL: goto x86_l_215e;
	case 8544ULL: goto x86_l_2160;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8560ULL: goto x86_l_2170;
	case 8567ULL: goto x86_l_2177;
	case 8572ULL: goto x86_l_217c;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8588ULL: goto x86_l_218c;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8600ULL: goto x86_l_2198;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8614ULL: goto x86_l_21a6;
	case 8620ULL: goto x86_l_21ac;
	case 8628ULL: goto x86_l_21b4;
	case 8631ULL: goto x86_l_21b7;
	case 8637ULL: goto x86_l_21bd;
	case 8642ULL: goto x86_l_21c2;
	case 8645ULL: goto x86_l_21c5;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8659ULL: goto x86_l_21d3;
	case 8665ULL: goto x86_l_21d9;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8690ULL: goto x86_l_21f2;
	case 8696ULL: goto x86_l_21f8;
	case 8701ULL: goto x86_l_21fd;
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8720ULL: goto x86_l_2210;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8761ULL: goto x86_l_2239;
	case 8767ULL: goto x86_l_223f;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8800ULL: goto x86_l_2260;
	case 8806ULL: goto x86_l_2266;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8834ULL: goto x86_l_2282;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8844ULL: goto x86_l_228c;
	case 8846ULL: goto x86_l_228e;
	case 8849ULL: goto x86_l_2291;
	case 8857ULL: goto x86_l_2299;
	case 8863ULL: goto x86_l_229f;
	case 8870ULL: goto x86_l_22a6;
	case 8873ULL: goto x86_l_22a9;
	case 8879ULL: goto x86_l_22af;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8894ULL: goto x86_l_22be;
	case 8896ULL: goto x86_l_22c0;
	case 8902ULL: goto x86_l_22c6;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c10:
	/* 0x1c10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c12:
	/* 0x1c12: js     1ea6 <generic_sleepable_preload+0x1ea6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ea6;
	}
x86_l_1c18:
	/* 0x1c18: cmp    WORD PTR [rdi+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1c1d:
	/* 0x1c1d: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1c23:
	/* 0x1c23: mov    eax,DWORD PTR [rdi+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c26:
	/* 0x1c26: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c2b:
	/* 0x1c2b: cmp    WORD PTR [rdi+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1c30:
	/* 0x1c30: je     1c55 <generic_sleepable_preload+0x1c55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c55;
	}
x86_l_1c32:
	/* 0x1c32: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c37:
	/* 0x1c37: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c3c:
	/* 0x1c3c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c41:
	/* 0x1c41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c46:
	/* 0x1c46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c48:
	/* 0x1c48: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c4d:
	/* 0x1c4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c4f:
	/* 0x1c4f: js     1eb7 <generic_sleepable_preload+0x1eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1eb7;
	}
x86_l_1c55:
	/* 0x1c55: cmp    WORD PTR [rdi+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1c5d:
	/* 0x1c5d: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1c63:
	/* 0x1c63: mov    eax,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c69:
	/* 0x1c69: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c6e:
	/* 0x1c6e: cmp    WORD PTR [rdi+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1c76:
	/* 0x1c76: je     1c9b <generic_sleepable_preload+0x1c9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c9b;
	}
x86_l_1c78:
	/* 0x1c78: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c82:
	/* 0x1c82: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c87:
	/* 0x1c87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c8c:
	/* 0x1c8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8e:
	/* 0x1c8e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c93:
	/* 0x1c93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c95:
	/* 0x1c95: js     1ef7 <generic_sleepable_preload+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ef7;
	}
x86_l_1c9b:
	/* 0x1c9b: cmp    WORD PTR [rdi+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1ca3:
	/* 0x1ca3: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1ca9:
	/* 0x1ca9: mov    eax,DWORD PTR [rdi+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1caf:
	/* 0x1caf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1cb4:
	/* 0x1cb4: cmp    WORD PTR [rdi+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1cbc:
	/* 0x1cbc: je     1ce1 <generic_sleepable_preload+0x1ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ce1;
	}
x86_l_1cbe:
	/* 0x1cbe: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc8:
	/* 0x1cc8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ccd:
	/* 0x1ccd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd2:
	/* 0x1cd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd4:
	/* 0x1cd4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cd9:
	/* 0x1cd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cdb:
	/* 0x1cdb: js     1f08 <generic_sleepable_preload+0x1f08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f08;
	}
x86_l_1ce1:
	/* 0x1ce1: cmp    WORD PTR [rdi+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_1ce9:
	/* 0x1ce9: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1cef:
	/* 0x1cef: mov    eax,DWORD PTR [rdi+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1cf5:
	/* 0x1cf5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1cfa:
	/* 0x1cfa: cmp    WORD PTR [rdi+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1d02:
	/* 0x1d02: je     1d27 <generic_sleepable_preload+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d27;
	}
x86_l_1d04:
	/* 0x1d04: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d09:
	/* 0x1d09: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0e:
	/* 0x1d0e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d13:
	/* 0x1d13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d18:
	/* 0x1d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1a:
	/* 0x1d1a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d1f:
	/* 0x1d1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d21:
	/* 0x1d21: js     1f19 <generic_sleepable_preload+0x1f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f19;
	}
x86_l_1d27:
	/* 0x1d27: cmp    WORD PTR [rdi+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_1d2f:
	/* 0x1d2f: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1d35:
	/* 0x1d35: mov    eax,DWORD PTR [rdi+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d3b:
	/* 0x1d3b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d40:
	/* 0x1d40: cmp    WORD PTR [rdi+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1d48:
	/* 0x1d48: je     1d6d <generic_sleepable_preload+0x1d6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d6d;
	}
x86_l_1d4a:
	/* 0x1d4a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d54:
	/* 0x1d54: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d59:
	/* 0x1d59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d5e:
	/* 0x1d5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d60:
	/* 0x1d60: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d65:
	/* 0x1d65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d67:
	/* 0x1d67: js     1faa <generic_sleepable_preload+0x1faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1faa;
	}
x86_l_1d6d:
	/* 0x1d6d: cmp    WORD PTR [rdi+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_1d75:
	/* 0x1d75: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1d7b:
	/* 0x1d7b: mov    eax,DWORD PTR [rdi+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d81:
	/* 0x1d81: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d86:
	/* 0x1d86: cmp    WORD PTR [rdi+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1d8e:
	/* 0x1d8e: je     1dae <generic_sleepable_preload+0x1dae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dae;
	}
x86_l_1d90:
	/* 0x1d90: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d95:
	/* 0x1d95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9a:
	/* 0x1d9a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da4:
	/* 0x1da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da6:
	/* 0x1da6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1da8:
	/* 0x1da8: js     5d8b <generic_sleepable_preload+0x5d8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23947ULL;
	}
x86_l_1dae:
	/* 0x1dae: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db3:
	/* 0x1db3: cmp    WORD PTR [rdi+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_1dbb:
	/* 0x1dbb: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1dc1:
	/* 0x1dc1: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1dc4:
	/* 0x1dc4: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dca:
	/* 0x1dca: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1dcf:
	/* 0x1dcf: cmp    WORD PTR [rdi+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1dd7:
	/* 0x1dd7: je     1df7 <generic_sleepable_preload+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df7;
	}
x86_l_1dd9:
	/* 0x1dd9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1dde:
	/* 0x1dde: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de3:
	/* 0x1de3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de8:
	/* 0x1de8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ded:
	/* 0x1ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1def:
	/* 0x1def: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1df1:
	/* 0x1df1: js     5fa4 <generic_sleepable_preload+0x5fa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24484ULL;
	}
x86_l_1df7:
	/* 0x1df7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dfc:
	/* 0x1dfc: cmp    WORD PTR [rdi+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_1e04:
	/* 0x1e04: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e09:
	/* 0x1e09: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_1e0c:
	/* 0x1e0c: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1e12:
	/* 0x1e12: mov    eax,DWORD PTR [rdi+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e18:
	/* 0x1e18: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e1d:
	/* 0x1e1d: cmp    WORD PTR [rdi+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_1e25:
	/* 0x1e25: je     1e45 <generic_sleepable_preload+0x1e45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e45;
	}
x86_l_1e27:
	/* 0x1e27: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e31:
	/* 0x1e31: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e36:
	/* 0x1e36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e3b:
	/* 0x1e3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3d:
	/* 0x1e3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e3f:
	/* 0x1e3f: js     6083 <generic_sleepable_preload+0x6083> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24707ULL;
	}
x86_l_1e45:
	/* 0x1e45: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e4a:
	/* 0x1e4a: cmp    WORD PTR [rdi+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_1e52:
	/* 0x1e52: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e57:
	/* 0x1e57: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_1e5a:
	/* 0x1e5a: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1e60:
	/* 0x1e60: mov    eax,DWORD PTR [rdi+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e66:
	/* 0x1e66: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e6b:
	/* 0x1e6b: cmp    WORD PTR [rdi+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_1e73:
	/* 0x1e73: je     1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1e79:
	/* 0x1e79: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e83:
	/* 0x1e83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e88:
	/* 0x1e88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e8d:
	/* 0x1e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8f:
	/* 0x1e8f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e94:
	/* 0x1e94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e96:
	/* 0x1e96: jns    1fb2 <generic_sleepable_preload+0x1fb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1fb2;
	}
x86_l_1e9c:
	/* 0x1e9c: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1ea1:
	/* 0x1ea1: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1ea6:
	/* 0x1ea6: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1eab:
	/* 0x1eab: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1eb0:
	/* 0x1eb0: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1eb5:
	/* 0x1eb5: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	goto x86_l_1f28;
x86_l_1eb7:
	/* 0x1eb7: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ebc:
	/* 0x1ebc: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1ec1:
	/* 0x1ec1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1ec6:
	/* 0x1ec6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ecb:
	/* 0x1ecb: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_1ed2:
	/* 0x1ed2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed7:
	/* 0x1ed7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1edc:
	/* 0x1edc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ede:
	/* 0x1ede: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ee0:
	/* 0x1ee0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ee3:
	/* 0x1ee3: je     12f0 <generic_sleepable_preload+0x12f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4848ULL;
	}
x86_l_1ee9:
	/* 0x1ee9: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1eeb:
	/* 0x1eeb: jmp    1345 <generic_sleepable_preload+0x1345> */
	return 4933ULL;
x86_l_1ef0:
	/* 0x1ef0: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1ef5:
	/* 0x1ef5: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	goto x86_l_1f28;
x86_l_1ef7:
	/* 0x1ef7: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1efc:
	/* 0x1efc: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1f01:
	/* 0x1f01: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1f06:
	/* 0x1f06: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	goto x86_l_1f28;
x86_l_1f08:
	/* 0x1f08: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1f0d:
	/* 0x1f0d: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1f12:
	/* 0x1f12: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1f17:
	/* 0x1f17: jmp    1f28 <generic_sleepable_preload+0x1f28> */
	goto x86_l_1f28;
x86_l_1f19:
	/* 0x1f19: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1f1e:
	/* 0x1f1e: jmp    1faf <generic_sleepable_preload+0x1faf> */
	goto x86_l_1faf;
x86_l_1f23:
	/* 0x1f23: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1f28:
	/* 0x1f28: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2b:
	/* 0x1f2b: mov    ebx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f33:
	/* 0x1f33: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f38:
	/* 0x1f38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f3d:
	/* 0x1f3d: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_1f40:
	/* 0x1f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f42:
	/* 0x1f42: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1f45:
	/* 0x1f45: jne    2057 <generic_sleepable_preload+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2057;
	}
x86_l_1f4b:
	/* 0x1f4b: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f50:
	/* 0x1f50: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f55:
	/* 0x1f55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f57:
	/* 0x1f57: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1f64:
	/* 0x1f64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f69:
	/* 0x1f69: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1f70:
	/* 0x1f70: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f75:
	/* 0x1f75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f77:
	/* 0x1f77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7a:
	/* 0x1f7a: je     2057 <generic_sleepable_preload+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2057;
	}
x86_l_1f80:
	/* 0x1f80: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1f86:
	/* 0x1f86: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1f89:
	/* 0x1f89: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1f90:
	/* 0x1f90: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f95:
	/* 0x1f95: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1f98:
	/* 0x1f98: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1f9b:
	/* 0x1f9b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1f9e:
	/* 0x1f9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa0:
	/* 0x1fa0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1fa3:
	/* 0x1fa3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa8:
	/* 0x1fa8: jmp    2014 <generic_sleepable_preload+0x2014> */
	goto x86_l_2014;
x86_l_1faa:
	/* 0x1faa: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1faf:
	/* 0x1faf: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb2:
	/* 0x1fb2: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1fb5:
	/* 0x1fb5: jne    205c <generic_sleepable_preload+0x205c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_205c;
	}
x86_l_1fbb:
	/* 0x1fbb: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc0:
	/* 0x1fc0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1fc5:
	/* 0x1fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc7:
	/* 0x1fc7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1fd4:
	/* 0x1fd4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1fe0:
	/* 0x1fe0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe5:
	/* 0x1fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe7:
	/* 0x1fe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fea:
	/* 0x1fea: je     2057 <generic_sleepable_preload+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2057;
	}
x86_l_1fec:
	/* 0x1fec: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1ff5:
	/* 0x1ff5: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1ffc:
	/* 0x1ffc: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2001:
	/* 0x2001: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2004:
	/* 0x2004: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2007:
	/* 0x2007: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_200a:
	/* 0x200a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_200c:
	/* 0x200c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_200f:
	/* 0x200f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2014:
	/* 0x2014: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2017:
	/* 0x2017: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_201a:
	/* 0x201a: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_201f:
	/* 0x201f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2022:
	/* 0x2022: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2024:
	/* 0x2024: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2027:
	/* 0x2027: je     2057 <generic_sleepable_preload+0x2057> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2057;
	}
x86_l_2029:
	/* 0x2029: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_202c:
	/* 0x202c: je     2055 <generic_sleepable_preload+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2055;
	}
x86_l_202e:
	/* 0x202e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2031:
	/* 0x2031: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2035:
	/* 0x2035: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_203a:
	/* 0x203a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_203d:
	/* 0x203d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_203f:
	/* 0x203f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2042:
	/* 0x2042: call   2047 <generic_sleepable_preload+0x2047> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2047:
	/* 0x2047: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2049:
	/* 0x2049: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_204c:
	/* 0x204c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_204e:
	/* 0x204e: jns    2055 <generic_sleepable_preload+0x2055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2055;
	}
x86_l_2050:
	/* 0x2050: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_2055:
	/* 0x2055: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2057:
	/* 0x2057: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205c:
	/* 0x205c: mov    eax,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_205f:
	/* 0x205f: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2064:
	/* 0x2064: je     2fcb <generic_sleepable_preload+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12235ULL;
	}
x86_l_206a:
	/* 0x206a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_206c:
	/* 0x206c: js     20c6 <generic_sleepable_preload+0x20c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20c6;
	}
x86_l_206e:
	/* 0x206e: movzx  ecx,BYTE PTR [rdi+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_2075:
	/* 0x2075: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2077:
	/* 0x2077: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_207a:
	/* 0x207a: jg     2129 <generic_sleepable_preload+0x2129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2129;
	}
x86_l_2080:
	/* 0x2080: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2083:
	/* 0x2083: je     21fd <generic_sleepable_preload+0x21fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21fd;
	}
x86_l_2089:
	/* 0x2089: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_208c:
	/* 0x208c: jne    2287 <generic_sleepable_preload+0x2287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2287;
	}
x86_l_2092:
	/* 0x2092: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_2098:
	/* 0x2098: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_209e:
	/* 0x209e: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20a1:
	/* 0x20a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20a6:
	/* 0x20a6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ab:
	/* 0x20ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b0:
	/* 0x20b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b2:
	/* 0x20b2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b7:
	/* 0x20b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b9:
	/* 0x20b9: je     2209 <generic_sleepable_preload+0x2209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2209;
	}
x86_l_20bf:
	/* 0x20bf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20c1:
	/* 0x20c1: jmp    2287 <generic_sleepable_preload+0x2287> */
	goto x86_l_2287;
x86_l_20c6:
	/* 0x20c6: movzx  ecx,BYTE PTR [rdi+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_20cd:
	/* 0x20cd: movzx  eax,WORD PTR [rdi+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_20d4:
	/* 0x20d4: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_20da:
	/* 0x20da: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20dc:
	/* 0x20dc: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_20df:
	/* 0x20df: jle    217c <generic_sleepable_preload+0x217c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_217c;
	}
x86_l_20e5:
	/* 0x20e5: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_20e8:
	/* 0x20e8: jle    21a3 <generic_sleepable_preload+0x21a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_21a3;
	}
x86_l_20ee:
	/* 0x20ee: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_20f1:
	/* 0x20f1: jle    2856 <generic_sleepable_preload+0x2856> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 10326ULL;
	}
x86_l_20f7:
	/* 0x20f7: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_20ff:
	/* 0x20ff: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2102:
	/* 0x2102: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_2108:
	/* 0x2108: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_210d:
	/* 0x210d: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2110:
	/* 0x2110: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_2116:
	/* 0x2116: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_211b:
	/* 0x211b: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_211e:
	/* 0x211e: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_2124:
	/* 0x2124: jmp    288f <generic_sleepable_preload+0x288f> */
	return 10383ULL;
x86_l_2129:
	/* 0x2129: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_212c:
	/* 0x212c: je     2233 <generic_sleepable_preload+0x2233> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2233;
	}
x86_l_2132:
	/* 0x2132: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2135:
	/* 0x2135: jne    2287 <generic_sleepable_preload+0x2287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2287;
	}
x86_l_213b:
	/* 0x213b: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_2141:
	/* 0x2141: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2147:
	/* 0x2147: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_214a:
	/* 0x214a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_214f:
	/* 0x214f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_2152:
	/* 0x2152: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2157:
	/* 0x2157: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_215c:
	/* 0x215c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215e:
	/* 0x215e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2160:
	/* 0x2160: jne    2282 <generic_sleepable_preload+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2282;
	}
x86_l_2166:
	/* 0x2166: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_216b:
	/* 0x216b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2170:
	/* 0x2170: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_2177:
	/* 0x2177: jmp    2e56 <generic_sleepable_preload+0x2e56> */
	return 11862ULL;
x86_l_217c:
	/* 0x217c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_217f:
	/* 0x217f: jg     21d0 <generic_sleepable_preload+0x21d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21d0;
	}
x86_l_2181:
	/* 0x2181: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2184:
	/* 0x2184: jg     2827 <generic_sleepable_preload+0x2827> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10279ULL;
	}
x86_l_218a:
	/* 0x218a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_218c:
	/* 0x218c: je     2879 <generic_sleepable_preload+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10361ULL;
	}
x86_l_2192:
	/* 0x2192: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2195:
	/* 0x2195: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2198:
	/* 0x2198: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_219e:
	/* 0x219e: jmp    288f <generic_sleepable_preload+0x288f> */
	return 10383ULL;
x86_l_21a3:
	/* 0x21a3: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_21a6:
	/* 0x21a6: jg     280e <generic_sleepable_preload+0x280e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10254ULL;
	}
x86_l_21ac:
	/* 0x21ac: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_21b4:
	/* 0x21b4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21b7:
	/* 0x21b7: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_21bd:
	/* 0x21bd: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21c2:
	/* 0x21c2: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_21c5:
	/* 0x21c5: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_21cb:
	/* 0x21cb: jmp    288f <generic_sleepable_preload+0x288f> */
	return 10383ULL;
x86_l_21d0:
	/* 0x21d0: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_21d3:
	/* 0x21d3: jg     283d <generic_sleepable_preload+0x283d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10301ULL;
	}
x86_l_21d9:
	/* 0x21d9: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_21e1:
	/* 0x21e1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_21e4:
	/* 0x21e4: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_21ea:
	/* 0x21ea: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21ef:
	/* 0x21ef: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_21f2:
	/* 0x21f2: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10364ULL;
	}
x86_l_21f8:
	/* 0x21f8: jmp    288f <generic_sleepable_preload+0x288f> */
	return 10383ULL;
x86_l_21fd:
	/* 0x21fd: mov    rax,QWORD PTR [rdi+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2204:
	/* 0x2204: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2209:
	/* 0x2209: movzx  eax,BYTE PTR [rdi+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_2210:
	/* 0x2210: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_2217:
	/* 0x2217: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_221c:
	/* 0x221c: cmp    BYTE PTR [rdi+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_2223:
	/* 0x2223: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_2228:
	/* 0x2228: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_222d:
	/* 0x222d: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_2231:
	/* 0x2231: jmp    2287 <generic_sleepable_preload+0x2287> */
	goto x86_l_2287;
x86_l_2233:
	/* 0x2233: mov    edx,DWORD PTR [rdi+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_2239:
	/* 0x2239: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_223f:
	/* 0x223f: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2242:
	/* 0x2242: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2247:
	/* 0x2247: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_224a:
	/* 0x224a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_224f:
	/* 0x224f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2254:
	/* 0x2254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2256:
	/* 0x2256: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2258:
	/* 0x2258: jne    2282 <generic_sleepable_preload+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2282;
	}
x86_l_225a:
	/* 0x225a: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_2260:
	/* 0x2260: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2266:
	/* 0x2266: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2269:
	/* 0x2269: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_226e:
	/* 0x226e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2273:
	/* 0x2273: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2278:
	/* 0x2278: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227a:
	/* 0x227a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_227c:
	/* 0x227c: je     2e34 <generic_sleepable_preload+0x2e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11828ULL;
	}
x86_l_2282:
	/* 0x2282: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2284:
	/* 0x2284: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2287:
	/* 0x2287: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_228c:
	/* 0x228c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228e:
	/* 0x228e: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_2291:
	/* 0x2291: cmp    WORD PTR [rdi+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_2299:
	/* 0x2299: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_229f:
	/* 0x229f: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_22a6:
	/* 0x22a6: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22a9:
	/* 0x22a9: mov    edx,DWORD PTR [rdi+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_22af:
	/* 0x22af: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22b2:
	/* 0x22b2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b7:
	/* 0x22b7: movzx  eax,WORD PTR [rdi+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_22be:
	/* 0x22be: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_22c0:
	/* 0x22c0: je     254f <generic_sleepable_preload+0x254f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9551ULL;
	}
x86_l_22c6:
	/* 0x22c6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_22c9:
	/* 0x22c9: je     22ee <generic_sleepable_preload+0x22ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8942ULL;
	}
x86_l_22cb:
	/* 0x22cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_22d0:
	/* 0x22d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d5:
	/* 0x22d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 8922ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8950ULL: goto x86_l_22f6;
	case 8956ULL: goto x86_l_22fc;
	case 8962ULL: goto x86_l_2302;
	case 8967ULL: goto x86_l_2307;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8992ULL: goto x86_l_2320;
	case 8997ULL: goto x86_l_2325;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9006ULL: goto x86_l_232e;
	case 9012ULL: goto x86_l_2334;
	case 9020ULL: goto x86_l_233c;
	case 9026ULL: goto x86_l_2342;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9045ULL: goto x86_l_2355;
	case 9047ULL: goto x86_l_2357;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9082ULL: goto x86_l_237a;
	case 9090ULL: goto x86_l_2382;
	case 9096ULL: goto x86_l_2388;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9115ULL: goto x86_l_239b;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9146ULL: goto x86_l_23ba;
	case 9152ULL: goto x86_l_23c0;
	case 9160ULL: goto x86_l_23c8;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9222ULL: goto x86_l_2406;
	case 9230ULL: goto x86_l_240e;
	case 9236ULL: goto x86_l_2414;
	case 9242ULL: goto x86_l_241a;
	case 9247ULL: goto x86_l_241f;
	case 9255ULL: goto x86_l_2427;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9284ULL: goto x86_l_2444;
	case 9286ULL: goto x86_l_2446;
	case 9292ULL: goto x86_l_244c;
	case 9300ULL: goto x86_l_2454;
	case 9306ULL: goto x86_l_245a;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9351ULL: goto x86_l_2487;
	case 9357ULL: goto x86_l_248d;
	case 9362ULL: goto x86_l_2492;
	case 9370ULL: goto x86_l_249a;
	case 9376ULL: goto x86_l_24a0;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9427ULL: goto x86_l_24d3;
	case 9432ULL: goto x86_l_24d8;
	case 9440ULL: goto x86_l_24e0;
	case 9446ULL: goto x86_l_24e6;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9491ULL: goto x86_l_2513;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9510ULL: goto x86_l_2526;
	case 9516ULL: goto x86_l_252c;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9561ULL: goto x86_l_2559;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9585ULL: goto x86_l_2571;
	case 9591ULL: goto x86_l_2577;
	case 9599ULL: goto x86_l_257f;
	case 9605ULL: goto x86_l_2585;
	case 9611ULL: goto x86_l_258b;
	case 9616ULL: goto x86_l_2590;
	case 9624ULL: goto x86_l_2598;
	case 9626ULL: goto x86_l_259a;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9648ULL: goto x86_l_25b0;
	case 9653ULL: goto x86_l_25b5;
	case 9655ULL: goto x86_l_25b7;
	case 9661ULL: goto x86_l_25bd;
	case 9669ULL: goto x86_l_25c5;
	case 9675ULL: goto x86_l_25cb;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9694ULL: goto x86_l_25de;
	case 9696ULL: goto x86_l_25e0;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9725ULL: goto x86_l_25fd;
	case 9731ULL: goto x86_l_2603;
	case 9739ULL: goto x86_l_260b;
	case 9745ULL: goto x86_l_2611;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9764ULL: goto x86_l_2624;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9795ULL: goto x86_l_2643;
	case 9801ULL: goto x86_l_2649;
	case 9809ULL: goto x86_l_2651;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9834ULL: goto x86_l_266a;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9846ULL: goto x86_l_2676;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9865ULL: goto x86_l_2689;
	case 9871ULL: goto x86_l_268f;
	case 9879ULL: goto x86_l_2697;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9926ULL: goto x86_l_26c6;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9935ULL: goto x86_l_26cf;
	case 9941ULL: goto x86_l_26d5;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9974ULL: goto x86_l_26f6;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10000ULL: goto x86_l_2710;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10019ULL: goto x86_l_2723;
	case 10025ULL: goto x86_l_2729;
	case 10028ULL: goto x86_l_272c;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10047ULL: goto x86_l_273f;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10059ULL: goto x86_l_274b;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10071ULL: goto x86_l_2757;
	case 10073ULL: goto x86_l_2759;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10101ULL: goto x86_l_2775;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10120ULL: goto x86_l_2788;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10144ULL: goto x86_l_27a0;
	case 10146ULL: goto x86_l_27a2;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10165ULL: goto x86_l_27b5;
	case 10168ULL: goto x86_l_27b8;
	case 10174ULL: goto x86_l_27be;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10193ULL: goto x86_l_27d1;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10221ULL: goto x86_l_27ed;
	case 10226ULL: goto x86_l_27f2;
	case 10228ULL: goto x86_l_27f4;
	case 10234ULL: goto x86_l_27fa;
	case 10239ULL: goto x86_l_27ff;
	case 10244ULL: goto x86_l_2804;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10262ULL: goto x86_l_2816;
	case 10265ULL: goto x86_l_2819;
	case 10267ULL: goto x86_l_281b;
	case 10272ULL: goto x86_l_2820;
	case 10275ULL: goto x86_l_2823;
	case 10277ULL: goto x86_l_2825;
	case 10279ULL: goto x86_l_2827;
	case 10284ULL: goto x86_l_282c;
	case 10287ULL: goto x86_l_282f;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10297ULL: goto x86_l_2839;
	case 10299ULL: goto x86_l_283b;
	case 10301ULL: goto x86_l_283d;
	case 10309ULL: goto x86_l_2845;
	case 10312ULL: goto x86_l_2848;
	case 10314ULL: goto x86_l_284a;
	case 10319ULL: goto x86_l_284f;
	case 10322ULL: goto x86_l_2852;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10334ULL: goto x86_l_285e;
	case 10337ULL: goto x86_l_2861;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10347ULL: goto x86_l_286b;
	case 10349ULL: goto x86_l_286d;
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10364ULL: goto x86_l_287c;
	case 10367ULL: goto x86_l_287f;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10378ULL: goto x86_l_288a;
	case 10383ULL: goto x86_l_288f;
	case 10388ULL: goto x86_l_2894;
	case 10391ULL: goto x86_l_2897;
	case 10393ULL: goto x86_l_2899;
	case 10396ULL: goto x86_l_289c;
	case 10404ULL: goto x86_l_28a4;
	case 10410ULL: goto x86_l_28aa;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10426ULL: goto x86_l_28ba;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10441ULL: goto x86_l_28c9;
	case 10443ULL: goto x86_l_28cb;
	case 10449ULL: goto x86_l_28d1;
	case 10452ULL: goto x86_l_28d4;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10474ULL: goto x86_l_28ea;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10483ULL: goto x86_l_28f3;
	case 10489ULL: goto x86_l_28f9;
	case 10497ULL: goto x86_l_2901;
	case 10503ULL: goto x86_l_2907;
	case 10509ULL: goto x86_l_290d;
	case 10514ULL: goto x86_l_2912;
	case 10522ULL: goto x86_l_291a;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10544ULL: goto x86_l_2930;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10553ULL: goto x86_l_2939;
	case 10559ULL: goto x86_l_293f;
	case 10567ULL: goto x86_l_2947;
	case 10573ULL: goto x86_l_294d;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10592ULL: goto x86_l_2960;
	case 10594ULL: goto x86_l_2962;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10614ULL: goto x86_l_2976;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10623ULL: goto x86_l_297f;
	case 10629ULL: goto x86_l_2985;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10662ULL: goto x86_l_29a6;
	case 10664ULL: goto x86_l_29a8;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10707ULL: goto x86_l_29d3;
	case 10713ULL: goto x86_l_29d9;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10732ULL: goto x86_l_29ec;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10761ULL: goto x86_l_2a09;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22da:
	/* 0x22da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22df:
	/* 0x22df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e1:
	/* 0x22e1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22e6:
	/* 0x22e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e8:
	/* 0x22e8: js     2804 <generic_sleepable_preload+0x2804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2804;
	}
x86_l_22ee:
	/* 0x22ee: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_22f6:
	/* 0x22f6: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_22fc:
	/* 0x22fc: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2302:
	/* 0x2302: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2307:
	/* 0x2307: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_230f:
	/* 0x230f: je     2334 <generic_sleepable_preload+0x2334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2334;
	}
x86_l_2311:
	/* 0x2311: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2316:
	/* 0x2316: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231b:
	/* 0x231b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2320:
	/* 0x2320: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2325:
	/* 0x2325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2327:
	/* 0x2327: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_232c:
	/* 0x232c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232e:
	/* 0x232e: js     286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_286f;
	}
x86_l_2334:
	/* 0x2334: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_233c:
	/* 0x233c: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2342:
	/* 0x2342: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2348:
	/* 0x2348: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_234d:
	/* 0x234d: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2355:
	/* 0x2355: je     237a <generic_sleepable_preload+0x237a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237a;
	}
x86_l_2357:
	/* 0x2357: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_235c:
	/* 0x235c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2361:
	/* 0x2361: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2366:
	/* 0x2366: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_236b:
	/* 0x236b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236d:
	/* 0x236d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2372:
	/* 0x2372: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2374:
	/* 0x2374: js     2e23 <generic_sleepable_preload+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11811ULL;
	}
x86_l_237a:
	/* 0x237a: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2382:
	/* 0x2382: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2388:
	/* 0x2388: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_238e:
	/* 0x238e: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2393:
	/* 0x2393: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_239b:
	/* 0x239b: je     23c0 <generic_sleepable_preload+0x23c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23c0;
	}
x86_l_239d:
	/* 0x239d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23a2:
	/* 0x23a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a7:
	/* 0x23a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ac:
	/* 0x23ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b1:
	/* 0x23b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b3:
	/* 0x23b3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23b8:
	/* 0x23b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23ba:
	/* 0x23ba: js     2e74 <generic_sleepable_preload+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11892ULL;
	}
x86_l_23c0:
	/* 0x23c0: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_23c8:
	/* 0x23c8: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_23ce:
	/* 0x23ce: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_23d4:
	/* 0x23d4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_23d9:
	/* 0x23d9: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_23e1:
	/* 0x23e1: je     2406 <generic_sleepable_preload+0x2406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2406;
	}
x86_l_23e3:
	/* 0x23e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23e8:
	/* 0x23e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ed:
	/* 0x23ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f2:
	/* 0x23f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f7:
	/* 0x23f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f9:
	/* 0x23f9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23fe:
	/* 0x23fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2400:
	/* 0x2400: js     2e85 <generic_sleepable_preload+0x2e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11909ULL;
	}
x86_l_2406:
	/* 0x2406: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_240e:
	/* 0x240e: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2414:
	/* 0x2414: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_241a:
	/* 0x241a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_241f:
	/* 0x241f: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2427:
	/* 0x2427: je     244c <generic_sleepable_preload+0x244c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244c;
	}
x86_l_2429:
	/* 0x2429: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_242e:
	/* 0x242e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2433:
	/* 0x2433: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2438:
	/* 0x2438: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_243d:
	/* 0x243d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243f:
	/* 0x243f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2444:
	/* 0x2444: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2446:
	/* 0x2446: js     2e96 <generic_sleepable_preload+0x2e96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11926ULL;
	}
x86_l_244c:
	/* 0x244c: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2454:
	/* 0x2454: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_245a:
	/* 0x245a: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2460:
	/* 0x2460: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2465:
	/* 0x2465: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_246d:
	/* 0x246d: je     248d <generic_sleepable_preload+0x248d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248d;
	}
x86_l_246f:
	/* 0x246f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2474:
	/* 0x2474: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2479:
	/* 0x2479: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_247e:
	/* 0x247e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2483:
	/* 0x2483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2485:
	/* 0x2485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2487:
	/* 0x2487: js     5d9d <generic_sleepable_preload+0x5d9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23965ULL;
	}
x86_l_248d:
	/* 0x248d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2492:
	/* 0x2492: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_249a:
	/* 0x249a: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_24a0:
	/* 0x24a0: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_24a6:
	/* 0x24a6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24ab:
	/* 0x24ab: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_24b3:
	/* 0x24b3: je     24d3 <generic_sleepable_preload+0x24d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d3;
	}
x86_l_24b5:
	/* 0x24b5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24ba:
	/* 0x24ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24bf:
	/* 0x24bf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c4:
	/* 0x24c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c9:
	/* 0x24c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24cb:
	/* 0x24cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24cd:
	/* 0x24cd: js     5f17 <generic_sleepable_preload+0x5f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24343ULL;
	}
x86_l_24d3:
	/* 0x24d3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24d8:
	/* 0x24d8: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_24e0:
	/* 0x24e0: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_24e6:
	/* 0x24e6: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_24ec:
	/* 0x24ec: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_24f1:
	/* 0x24f1: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_24f9:
	/* 0x24f9: je     2519 <generic_sleepable_preload+0x2519> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2519;
	}
x86_l_24fb:
	/* 0x24fb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2500:
	/* 0x2500: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2505:
	/* 0x2505: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_250a:
	/* 0x250a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_250f:
	/* 0x250f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2511:
	/* 0x2511: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2513:
	/* 0x2513: js     602d <generic_sleepable_preload+0x602d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24621ULL;
	}
x86_l_2519:
	/* 0x2519: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_251e:
	/* 0x251e: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2526:
	/* 0x2526: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_252c:
	/* 0x252c: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2532:
	/* 0x2532: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2537:
	/* 0x2537: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_253f:
	/* 0x253f: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2545:
	/* 0x2545: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_254a:
	/* 0x254a: jmp    27dc <generic_sleepable_preload+0x27dc> */
	goto x86_l_27dc;
x86_l_254f:
	/* 0x254f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2552:
	/* 0x2552: je     2577 <generic_sleepable_preload+0x2577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2577;
	}
x86_l_2554:
	/* 0x2554: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2559:
	/* 0x2559: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_255e:
	/* 0x255e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2563:
	/* 0x2563: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2568:
	/* 0x2568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256a:
	/* 0x256a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_256f:
	/* 0x256f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2571:
	/* 0x2571: js     2804 <generic_sleepable_preload+0x2804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2804;
	}
x86_l_2577:
	/* 0x2577: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_257f:
	/* 0x257f: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2585:
	/* 0x2585: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_258b:
	/* 0x258b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2590:
	/* 0x2590: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2598:
	/* 0x2598: je     25bd <generic_sleepable_preload+0x25bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25bd;
	}
x86_l_259a:
	/* 0x259a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_259f:
	/* 0x259f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a4:
	/* 0x25a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a9:
	/* 0x25a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ae:
	/* 0x25ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b0:
	/* 0x25b0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25b5:
	/* 0x25b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b7:
	/* 0x25b7: js     286f <generic_sleepable_preload+0x286f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_286f;
	}
x86_l_25bd:
	/* 0x25bd: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_25c5:
	/* 0x25c5: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_25cb:
	/* 0x25cb: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_25d1:
	/* 0x25d1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_25d6:
	/* 0x25d6: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_25de:
	/* 0x25de: je     2603 <generic_sleepable_preload+0x2603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2603;
	}
x86_l_25e0:
	/* 0x25e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25e5:
	/* 0x25e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ea:
	/* 0x25ea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ef:
	/* 0x25ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25f4:
	/* 0x25f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25f6:
	/* 0x25f6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25fb:
	/* 0x25fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25fd:
	/* 0x25fd: js     2e23 <generic_sleepable_preload+0x2e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11811ULL;
	}
x86_l_2603:
	/* 0x2603: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_260b:
	/* 0x260b: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2611:
	/* 0x2611: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2617:
	/* 0x2617: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_261c:
	/* 0x261c: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2624:
	/* 0x2624: je     2649 <generic_sleepable_preload+0x2649> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2649;
	}
x86_l_2626:
	/* 0x2626: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_262b:
	/* 0x262b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2630:
	/* 0x2630: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2635:
	/* 0x2635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_263a:
	/* 0x263a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263c:
	/* 0x263c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2641:
	/* 0x2641: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2643:
	/* 0x2643: js     2e74 <generic_sleepable_preload+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11892ULL;
	}
x86_l_2649:
	/* 0x2649: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2651:
	/* 0x2651: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2657:
	/* 0x2657: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_265d:
	/* 0x265d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2662:
	/* 0x2662: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_266a:
	/* 0x266a: je     268f <generic_sleepable_preload+0x268f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268f;
	}
x86_l_266c:
	/* 0x266c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2671:
	/* 0x2671: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2676:
	/* 0x2676: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_267b:
	/* 0x267b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2680:
	/* 0x2680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2682:
	/* 0x2682: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2687:
	/* 0x2687: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2689:
	/* 0x2689: js     2e85 <generic_sleepable_preload+0x2e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11909ULL;
	}
x86_l_268f:
	/* 0x268f: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2697:
	/* 0x2697: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_269d:
	/* 0x269d: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_26a3:
	/* 0x26a3: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26a8:
	/* 0x26a8: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_26b0:
	/* 0x26b0: je     26d5 <generic_sleepable_preload+0x26d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d5;
	}
x86_l_26b2:
	/* 0x26b2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26b7:
	/* 0x26b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26bc:
	/* 0x26bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c1:
	/* 0x26c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c6:
	/* 0x26c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c8:
	/* 0x26c8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26cd:
	/* 0x26cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26cf:
	/* 0x26cf: js     2e96 <generic_sleepable_preload+0x2e96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11926ULL;
	}
x86_l_26d5:
	/* 0x26d5: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_26dd:
	/* 0x26dd: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_26e3:
	/* 0x26e3: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_26e9:
	/* 0x26e9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_26ee:
	/* 0x26ee: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_26f6:
	/* 0x26f6: je     2716 <generic_sleepable_preload+0x2716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2716;
	}
x86_l_26f8:
	/* 0x26f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26fd:
	/* 0x26fd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2702:
	/* 0x2702: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2707:
	/* 0x2707: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_270c:
	/* 0x270c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270e:
	/* 0x270e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2710:
	/* 0x2710: js     5d9d <generic_sleepable_preload+0x5d9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23965ULL;
	}
x86_l_2716:
	/* 0x2716: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_271b:
	/* 0x271b: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2723:
	/* 0x2723: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2729:
	/* 0x2729: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_272c:
	/* 0x272c: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2732:
	/* 0x2732: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2737:
	/* 0x2737: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_273f:
	/* 0x273f: je     275f <generic_sleepable_preload+0x275f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_275f;
	}
x86_l_2741:
	/* 0x2741: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2746:
	/* 0x2746: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274b:
	/* 0x274b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2750:
	/* 0x2750: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2755:
	/* 0x2755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2757:
	/* 0x2757: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2759:
	/* 0x2759: js     5fb1 <generic_sleepable_preload+0x5fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24497ULL;
	}
x86_l_275f:
	/* 0x275f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2764:
	/* 0x2764: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_276c:
	/* 0x276c: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_276f:
	/* 0x276f: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_2775:
	/* 0x2775: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_277b:
	/* 0x277b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2780:
	/* 0x2780: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2788:
	/* 0x2788: je     27a8 <generic_sleepable_preload+0x27a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a8;
	}
x86_l_278a:
	/* 0x278a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_278f:
	/* 0x278f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2794:
	/* 0x2794: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2799:
	/* 0x2799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_279e:
	/* 0x279e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a0:
	/* 0x27a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27a2:
	/* 0x27a2: js     609d <generic_sleepable_preload+0x609d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24733ULL;
	}
x86_l_27a8:
	/* 0x27a8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ad:
	/* 0x27ad: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_27b5:
	/* 0x27b5: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_27b8:
	/* 0x27b8: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_27be:
	/* 0x27be: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_27c4:
	/* 0x27c4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_27c9:
	/* 0x27c9: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_27d1:
	/* 0x27d1: je     2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11934ULL;
	}
x86_l_27d7:
	/* 0x27d7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27dc:
	/* 0x27dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e1:
	/* 0x27e1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e6:
	/* 0x27e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27eb:
	/* 0x27eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ed:
	/* 0x27ed: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27f2:
	/* 0x27f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27f4:
	/* 0x27f4: jns    2e9e <generic_sleepable_preload+0x2e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11934ULL;
	}
x86_l_27fa:
	/* 0x27fa: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_27ff:
	/* 0x27ff: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	return 11931ULL;
x86_l_2804:
	/* 0x2804: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2809:
	/* 0x2809: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	return 11931ULL;
x86_l_280e:
	/* 0x280e: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2816:
	/* 0x2816: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2819:
	/* 0x2819: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_281b:
	/* 0x281b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2820:
	/* 0x2820: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2823:
	/* 0x2823: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_2825:
	/* 0x2825: jmp    288f <generic_sleepable_preload+0x288f> */
	goto x86_l_288f;
x86_l_2827:
	/* 0x2827: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_282c:
	/* 0x282c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_282f:
	/* 0x282f: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_2831:
	/* 0x2831: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2836:
	/* 0x2836: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2839:
	/* 0x2839: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_283b:
	/* 0x283b: jmp    288f <generic_sleepable_preload+0x288f> */
	goto x86_l_288f;
x86_l_283d:
	/* 0x283d: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2845:
	/* 0x2845: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_2848:
	/* 0x2848: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_284a:
	/* 0x284a: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_284f:
	/* 0x284f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2852:
	/* 0x2852: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_2854:
	/* 0x2854: jmp    288f <generic_sleepable_preload+0x288f> */
	goto x86_l_288f;
x86_l_2856:
	/* 0x2856: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_285e:
	/* 0x285e: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2861:
	/* 0x2861: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_2863:
	/* 0x2863: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2868:
	/* 0x2868: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_286b:
	/* 0x286b: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_286d:
	/* 0x286d: jmp    288f <generic_sleepable_preload+0x288f> */
	goto x86_l_288f;
x86_l_286f:
	/* 0x286f: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2874:
	/* 0x2874: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	return 11931ULL;
x86_l_2879:
	/* 0x2879: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_287c:
	/* 0x287c: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_287f:
	/* 0x287f: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_2881:
	/* 0x2881: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2883:
	/* 0x2883: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_2888:
	/* 0x2888: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_288a:
	/* 0x288a: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_288f:
	/* 0x288f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2894:
	/* 0x2894: mov    ebx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2897:
	/* 0x2897: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2899:
	/* 0x2899: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_289c:
	/* 0x289c: cmp    WORD PTR [rdi+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_28a4:
	/* 0x28a4: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12069ULL;
	}
x86_l_28aa:
	/* 0x28aa: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_28b1:
	/* 0x28b1: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_28b4:
	/* 0x28b4: mov    edx,DWORD PTR [rdi+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_28ba:
	/* 0x28ba: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28bd:
	/* 0x28bd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c2:
	/* 0x28c2: movzx  eax,WORD PTR [rdi+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_28c9:
	/* 0x28c9: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_28cb:
	/* 0x28cb: je     2b5a <generic_sleepable_preload+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11098ULL;
	}
x86_l_28d1:
	/* 0x28d1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_28d4:
	/* 0x28d4: je     28f9 <generic_sleepable_preload+0x28f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28f9;
	}
x86_l_28d6:
	/* 0x28d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28db:
	/* 0x28db: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e0:
	/* 0x28e0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e5:
	/* 0x28e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28ea:
	/* 0x28ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ec:
	/* 0x28ec: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28f1:
	/* 0x28f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28f3:
	/* 0x28f3: js     2e0f <generic_sleepable_preload+0x2e0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11791ULL;
	}
x86_l_28f9:
	/* 0x28f9: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2901:
	/* 0x2901: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12069ULL;
	}
x86_l_2907:
	/* 0x2907: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_290d:
	/* 0x290d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2912:
	/* 0x2912: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_291a:
	/* 0x291a: je     293f <generic_sleepable_preload+0x293f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_293f;
	}
x86_l_291c:
	/* 0x291c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2921:
	/* 0x2921: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2926:
	/* 0x2926: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292b:
	/* 0x292b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2930:
	/* 0x2930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2932:
	/* 0x2932: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2937:
	/* 0x2937: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2939:
	/* 0x2939: js     2e19 <generic_sleepable_preload+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11801ULL;
	}
x86_l_293f:
	/* 0x293f: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2947:
	/* 0x2947: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12069ULL;
	}
x86_l_294d:
	/* 0x294d: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2953:
	/* 0x2953: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2958:
	/* 0x2958: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2960:
	/* 0x2960: je     2985 <generic_sleepable_preload+0x2985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2985;
	}
x86_l_2962:
	/* 0x2962: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2967:
	/* 0x2967: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_296c:
	/* 0x296c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2971:
	/* 0x2971: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2976:
	/* 0x2976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2978:
	/* 0x2978: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_297d:
	/* 0x297d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_297f:
	/* 0x297f: js     2e2a <generic_sleepable_preload+0x2e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11818ULL;
	}
x86_l_2985:
	/* 0x2985: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_298d:
	/* 0x298d: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12069ULL;
	}
x86_l_2993:
	/* 0x2993: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2999:
	/* 0x2999: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_299e:
	/* 0x299e: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_29a6:
	/* 0x29a6: je     29cb <generic_sleepable_preload+0x29cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cb;
	}
x86_l_29a8:
	/* 0x29a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29ad:
	/* 0x29ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b2:
	/* 0x29b2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b7:
	/* 0x29b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29bc:
	/* 0x29bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29be:
	/* 0x29be: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29c3:
	/* 0x29c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29c5:
	/* 0x29c5: js     2e7b <generic_sleepable_preload+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11899ULL;
	}
x86_l_29cb:
	/* 0x29cb: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_29d3:
	/* 0x29d3: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12069ULL;
	}
x86_l_29d9:
	/* 0x29d9: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_29df:
	/* 0x29df: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29e4:
	/* 0x29e4: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_29ec:
	/* 0x29ec: je     2a11 <generic_sleepable_preload+0x2a11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10769ULL;
	}
x86_l_29ee:
	/* 0x29ee: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29f3:
	/* 0x29f3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29f8:
	/* 0x29f8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fd:
	/* 0x29fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a02:
	/* 0x2a02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a04:
	/* 0x2a04: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a09:
	/* 0x2a09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 10763ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10763ULL: goto x86_l_2a0b;
	case 10769ULL: goto x86_l_2a11;
	case 10777ULL: goto x86_l_2a19;
	case 10783ULL: goto x86_l_2a1f;
	case 10789ULL: goto x86_l_2a25;
	case 10794ULL: goto x86_l_2a2a;
	case 10802ULL: goto x86_l_2a32;
	case 10804ULL: goto x86_l_2a34;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10819ULL: goto x86_l_2a43;
	case 10824ULL: goto x86_l_2a48;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10833ULL: goto x86_l_2a51;
	case 10839ULL: goto x86_l_2a57;
	case 10847ULL: goto x86_l_2a5f;
	case 10853ULL: goto x86_l_2a65;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10872ULL: goto x86_l_2a78;
	case 10874ULL: goto x86_l_2a7a;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10898ULL: goto x86_l_2a92;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10917ULL: goto x86_l_2aa5;
	case 10923ULL: goto x86_l_2aab;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10942ULL: goto x86_l_2abe;
	case 10944ULL: goto x86_l_2ac0;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10964ULL: goto x86_l_2ad4;
	case 10966ULL: goto x86_l_2ad6;
	case 10968ULL: goto x86_l_2ad8;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10987ULL: goto x86_l_2aeb;
	case 10993ULL: goto x86_l_2af1;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11012ULL: goto x86_l_2b04;
	case 11014ULL: goto x86_l_2b06;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11036ULL: goto x86_l_2b1c;
	case 11038ULL: goto x86_l_2b1e;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11057ULL: goto x86_l_2b31;
	case 11063ULL: goto x86_l_2b37;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11082ULL: goto x86_l_2b4a;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11101ULL: goto x86_l_2b5d;
	case 11103ULL: goto x86_l_2b5f;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11125ULL: goto x86_l_2b75;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11138ULL: goto x86_l_2b82;
	case 11146ULL: goto x86_l_2b8a;
	case 11152ULL: goto x86_l_2b90;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11171ULL: goto x86_l_2ba3;
	case 11173ULL: goto x86_l_2ba5;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11188ULL: goto x86_l_2bb4;
	case 11193ULL: goto x86_l_2bb9;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11202ULL: goto x86_l_2bc2;
	case 11208ULL: goto x86_l_2bc8;
	case 11216ULL: goto x86_l_2bd0;
	case 11222ULL: goto x86_l_2bd6;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11241ULL: goto x86_l_2be9;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11278ULL: goto x86_l_2c0e;
	case 11286ULL: goto x86_l_2c16;
	case 11292ULL: goto x86_l_2c1c;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11348ULL: goto x86_l_2c54;
	case 11356ULL: goto x86_l_2c5c;
	case 11362ULL: goto x86_l_2c62;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11381ULL: goto x86_l_2c75;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11403ULL: goto x86_l_2c8b;
	case 11405ULL: goto x86_l_2c8d;
	case 11410ULL: goto x86_l_2c92;
	case 11412ULL: goto x86_l_2c94;
	case 11418ULL: goto x86_l_2c9a;
	case 11426ULL: goto x86_l_2ca2;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11451ULL: goto x86_l_2cbb;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11473ULL: goto x86_l_2cd1;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11496ULL: goto x86_l_2ce8;
	case 11502ULL: goto x86_l_2cee;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11521ULL: goto x86_l_2d01;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11543ULL: goto x86_l_2d17;
	case 11545ULL: goto x86_l_2d19;
	case 11547ULL: goto x86_l_2d1b;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11566ULL: goto x86_l_2d2e;
	case 11572ULL: goto x86_l_2d34;
	case 11575ULL: goto x86_l_2d37;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11616ULL: goto x86_l_2d60;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11631ULL: goto x86_l_2d6f;
	case 11639ULL: goto x86_l_2d77;
	case 11642ULL: goto x86_l_2d7a;
	case 11648ULL: goto x86_l_2d80;
	case 11654ULL: goto x86_l_2d86;
	case 11659ULL: goto x86_l_2d8b;
	case 11667ULL: goto x86_l_2d93;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11689ULL: goto x86_l_2da9;
	case 11691ULL: goto x86_l_2dab;
	case 11693ULL: goto x86_l_2dad;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11712ULL: goto x86_l_2dc0;
	case 11715ULL: goto x86_l_2dc3;
	case 11721ULL: goto x86_l_2dc9;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11740ULL: goto x86_l_2ddc;
	case 11746ULL: goto x86_l_2de2;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11768ULL: goto x86_l_2df8;
	case 11773ULL: goto x86_l_2dfd;
	case 11775ULL: goto x86_l_2dff;
	case 11781ULL: goto x86_l_2e05;
	case 11786ULL: goto x86_l_2e0a;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11801ULL: goto x86_l_2e19;
	case 11806ULL: goto x86_l_2e1e;
	case 11811ULL: goto x86_l_2e23;
	case 11816ULL: goto x86_l_2e28;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11840ULL: goto x86_l_2e40;
	case 11847ULL: goto x86_l_2e47;
	case 11854ULL: goto x86_l_2e4e;
	case 11859ULL: goto x86_l_2e53;
	case 11862ULL: goto x86_l_2e56;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11879ULL: goto x86_l_2e67;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11899ULL: goto x86_l_2e7b;
	case 11904ULL: goto x86_l_2e80;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11934ULL: goto x86_l_2e9e;
	case 11937ULL: goto x86_l_2ea1;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12010ULL: goto x86_l_2eea;
	case 12013ULL: goto x86_l_2eed;
	case 12019ULL: goto x86_l_2ef3;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12035ULL: goto x86_l_2f03;
	case 12040ULL: goto x86_l_2f08;
	case 12043ULL: goto x86_l_2f0b;
	case 12046ULL: goto x86_l_2f0e;
	case 12049ULL: goto x86_l_2f11;
	case 12051ULL: goto x86_l_2f13;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12072ULL: goto x86_l_2f28;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12122ULL: goto x86_l_2f5a;
	case 12125ULL: goto x86_l_2f5d;
	case 12127ULL: goto x86_l_2f5f;
	case 12133ULL: goto x86_l_2f65;
	case 12136ULL: goto x86_l_2f68;
	case 12143ULL: goto x86_l_2f6f;
	case 12148ULL: goto x86_l_2f74;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12157ULL: goto x86_l_2f7d;
	case 12159ULL: goto x86_l_2f7f;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12170ULL: goto x86_l_2f8a;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12178ULL: goto x86_l_2f92;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12186ULL: goto x86_l_2f9a;
	case 12188ULL: goto x86_l_2f9c;
	case 12191ULL: goto x86_l_2f9f;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12203ULL: goto x86_l_2fab;
	case 12205ULL: goto x86_l_2fad;
	case 12208ULL: goto x86_l_2fb0;
	case 12213ULL: goto x86_l_2fb5;
	case 12215ULL: goto x86_l_2fb7;
	case 12218ULL: goto x86_l_2fba;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12228ULL: goto x86_l_2fc4;
	case 12230ULL: goto x86_l_2fc6;
	case 12235ULL: goto x86_l_2fcb;
	case 12238ULL: goto x86_l_2fce;
	case 12243ULL: goto x86_l_2fd3;
	case 12249ULL: goto x86_l_2fd9;
	case 12251ULL: goto x86_l_2fdb;
	case 12253ULL: goto x86_l_2fdd;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	case 12265ULL: goto x86_l_2fe9;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12279ULL: goto x86_l_2ff7;
	case 12285ULL: goto x86_l_2ffd;
	case 12288ULL: goto x86_l_3000;
	case 12294ULL: goto x86_l_3006;
	case 12300ULL: goto x86_l_300c;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12324ULL: goto x86_l_3024;
	case 12326ULL: goto x86_l_3026;
	case 12331ULL: goto x86_l_302b;
	case 12333ULL: goto x86_l_302d;
	case 12339ULL: goto x86_l_3033;
	case 12341ULL: goto x86_l_3035;
	case 12346ULL: goto x86_l_303a;
	case 12353ULL: goto x86_l_3041;
	case 12360ULL: goto x86_l_3048;
	case 12366ULL: goto x86_l_304e;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12377ULL: goto x86_l_3059;
	case 12380ULL: goto x86_l_305c;
	case 12386ULL: goto x86_l_3062;
	case 12389ULL: goto x86_l_3065;
	case 12395ULL: goto x86_l_306b;
	case 12403ULL: goto x86_l_3073;
	case 12406ULL: goto x86_l_3076;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12434ULL: goto x86_l_3092;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12459ULL: goto x86_l_30ab;
	case 12462ULL: goto x86_l_30ae;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12480ULL: goto x86_l_30c0;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12501ULL: goto x86_l_30d5;
	case 12503ULL: goto x86_l_30d7;
	case 12505ULL: goto x86_l_30d9;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12528ULL: goto x86_l_30f0;
	case 12533ULL: goto x86_l_30f5;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12543ULL: goto x86_l_30ff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a0b:
	/* 0x2a0b: js     2e8c <generic_sleepable_preload+0x2e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e8c;
	}
x86_l_2a11:
	/* 0x2a11: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2a19:
	/* 0x2a19: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2a1f:
	/* 0x2a1f: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2a25:
	/* 0x2a25: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a2a:
	/* 0x2a2a: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2a32:
	/* 0x2a32: je     2a57 <generic_sleepable_preload+0x2a57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a57;
	}
x86_l_2a34:
	/* 0x2a34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a39:
	/* 0x2a39: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a3e:
	/* 0x2a3e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a43:
	/* 0x2a43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a48:
	/* 0x2a48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4a:
	/* 0x2a4a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a4f:
	/* 0x2a4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a51:
	/* 0x2a51: js     2f1d <generic_sleepable_preload+0x2f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f1d;
	}
x86_l_2a57:
	/* 0x2a57: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2a5f:
	/* 0x2a5f: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2a65:
	/* 0x2a65: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2a6b:
	/* 0x2a6b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2a70:
	/* 0x2a70: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2a78:
	/* 0x2a78: je     2a98 <generic_sleepable_preload+0x2a98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a98;
	}
x86_l_2a7a:
	/* 0x2a7a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a7f:
	/* 0x2a7f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a84:
	/* 0x2a84: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a89:
	/* 0x2a89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8e:
	/* 0x2a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a90:
	/* 0x2a90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a92:
	/* 0x2a92: js     5daf <generic_sleepable_preload+0x5daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23983ULL;
	}
x86_l_2a98:
	/* 0x2a98: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a9d:
	/* 0x2a9d: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2aa5:
	/* 0x2aa5: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2aab:
	/* 0x2aab: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2ab1:
	/* 0x2ab1: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ab6:
	/* 0x2ab6: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2abe:
	/* 0x2abe: je     2ade <generic_sleepable_preload+0x2ade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ade;
	}
x86_l_2ac0:
	/* 0x2ac0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ac5:
	/* 0x2ac5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aca:
	/* 0x2aca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2acf:
	/* 0x2acf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ad4:
	/* 0x2ad4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad6:
	/* 0x2ad6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ad8:
	/* 0x2ad8: js     5f29 <generic_sleepable_preload+0x5f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24361ULL;
	}
x86_l_2ade:
	/* 0x2ade: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ae3:
	/* 0x2ae3: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2aeb:
	/* 0x2aeb: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2af1:
	/* 0x2af1: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2af7:
	/* 0x2af7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2afc:
	/* 0x2afc: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2b04:
	/* 0x2b04: je     2b24 <generic_sleepable_preload+0x2b24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b24;
	}
x86_l_2b06:
	/* 0x2b06: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b0b:
	/* 0x2b0b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b10:
	/* 0x2b10: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b15:
	/* 0x2b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b1a:
	/* 0x2b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1c:
	/* 0x2b1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b1e:
	/* 0x2b1e: js     6037 <generic_sleepable_preload+0x6037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24631ULL;
	}
x86_l_2b24:
	/* 0x2b24: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b29:
	/* 0x2b29: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2b31:
	/* 0x2b31: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2b37:
	/* 0x2b37: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2b3d:
	/* 0x2b3d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b42:
	/* 0x2b42: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2b4a:
	/* 0x2b4a: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2b50:
	/* 0x2b50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b55:
	/* 0x2b55: jmp    2de7 <generic_sleepable_preload+0x2de7> */
	goto x86_l_2de7;
x86_l_2b5a:
	/* 0x2b5a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2b5d:
	/* 0x2b5d: je     2b82 <generic_sleepable_preload+0x2b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b82;
	}
x86_l_2b5f:
	/* 0x2b5f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b64:
	/* 0x2b64: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b69:
	/* 0x2b69: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b6e:
	/* 0x2b6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b73:
	/* 0x2b73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b75:
	/* 0x2b75: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b7a:
	/* 0x2b7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b7c:
	/* 0x2b7c: js     2e0f <generic_sleepable_preload+0x2e0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e0f;
	}
x86_l_2b82:
	/* 0x2b82: cmp    WORD PTR [rdi+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_2b8a:
	/* 0x2b8a: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2b90:
	/* 0x2b90: mov    eax,DWORD PTR [rdi+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2b96:
	/* 0x2b96: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2b9b:
	/* 0x2b9b: cmp    WORD PTR [rdi+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_2ba3:
	/* 0x2ba3: je     2bc8 <generic_sleepable_preload+0x2bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc8;
	}
x86_l_2ba5:
	/* 0x2ba5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2baa:
	/* 0x2baa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2baf:
	/* 0x2baf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bb4:
	/* 0x2bb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bb9:
	/* 0x2bb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bbb:
	/* 0x2bbb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bc0:
	/* 0x2bc0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bc2:
	/* 0x2bc2: js     2e19 <generic_sleepable_preload+0x2e19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e19;
	}
x86_l_2bc8:
	/* 0x2bc8: cmp    WORD PTR [rdi+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2bd0:
	/* 0x2bd0: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2bd6:
	/* 0x2bd6: mov    eax,DWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2bdc:
	/* 0x2bdc: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2be1:
	/* 0x2be1: cmp    WORD PTR [rdi+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2be9:
	/* 0x2be9: je     2c0e <generic_sleepable_preload+0x2c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c0e;
	}
x86_l_2beb:
	/* 0x2beb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf5:
	/* 0x2bf5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bff:
	/* 0x2bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c01:
	/* 0x2c01: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c06:
	/* 0x2c06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c08:
	/* 0x2c08: js     2e2a <generic_sleepable_preload+0x2e2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e2a;
	}
x86_l_2c0e:
	/* 0x2c0e: cmp    WORD PTR [rdi+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_2c16:
	/* 0x2c16: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2c1c:
	/* 0x2c1c: mov    eax,DWORD PTR [rdi+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2c22:
	/* 0x2c22: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c27:
	/* 0x2c27: cmp    WORD PTR [rdi+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2c2f:
	/* 0x2c2f: je     2c54 <generic_sleepable_preload+0x2c54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c54;
	}
x86_l_2c31:
	/* 0x2c31: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c36:
	/* 0x2c36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3b:
	/* 0x2c3b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c40:
	/* 0x2c40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c45:
	/* 0x2c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c47:
	/* 0x2c47: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c4c:
	/* 0x2c4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c4e:
	/* 0x2c4e: js     2e7b <generic_sleepable_preload+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e7b;
	}
x86_l_2c54:
	/* 0x2c54: cmp    WORD PTR [rdi+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_2c5c:
	/* 0x2c5c: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2c62:
	/* 0x2c62: mov    eax,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2c68:
	/* 0x2c68: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: cmp    WORD PTR [rdi+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2c75:
	/* 0x2c75: je     2c9a <generic_sleepable_preload+0x2c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c9a;
	}
x86_l_2c77:
	/* 0x2c77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c7c:
	/* 0x2c7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c81:
	/* 0x2c81: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c86:
	/* 0x2c86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c8b:
	/* 0x2c8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8d:
	/* 0x2c8d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c92:
	/* 0x2c92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c94:
	/* 0x2c94: js     2e8c <generic_sleepable_preload+0x2e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2e8c;
	}
x86_l_2c9a:
	/* 0x2c9a: cmp    WORD PTR [rdi+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_2ca2:
	/* 0x2ca2: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2ca8:
	/* 0x2ca8: mov    eax,DWORD PTR [rdi+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2cae:
	/* 0x2cae: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2cb3:
	/* 0x2cb3: cmp    WORD PTR [rdi+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2cbb:
	/* 0x2cbb: je     2ce0 <generic_sleepable_preload+0x2ce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce0;
	}
x86_l_2cbd:
	/* 0x2cbd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cc7:
	/* 0x2cc7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ccc:
	/* 0x2ccc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cd1:
	/* 0x2cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd3:
	/* 0x2cd3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cd8:
	/* 0x2cd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cda:
	/* 0x2cda: js     2f1d <generic_sleepable_preload+0x2f1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f1d;
	}
x86_l_2ce0:
	/* 0x2ce0: cmp    WORD PTR [rdi+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_2ce8:
	/* 0x2ce8: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2cee:
	/* 0x2cee: mov    eax,DWORD PTR [rdi+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2cf4:
	/* 0x2cf4: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2cf9:
	/* 0x2cf9: cmp    WORD PTR [rdi+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_2d01:
	/* 0x2d01: je     2d21 <generic_sleepable_preload+0x2d21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d21;
	}
x86_l_2d03:
	/* 0x2d03: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d08:
	/* 0x2d08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d0d:
	/* 0x2d0d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d12:
	/* 0x2d12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d17:
	/* 0x2d17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d19:
	/* 0x2d19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d1b:
	/* 0x2d1b: js     5daf <generic_sleepable_preload+0x5daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23983ULL;
	}
x86_l_2d21:
	/* 0x2d21: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d26:
	/* 0x2d26: cmp    WORD PTR [rdi+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2d2e:
	/* 0x2d2e: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2d34:
	/* 0x2d34: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2d37:
	/* 0x2d37: mov    eax,DWORD PTR [rdi+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2d3d:
	/* 0x2d3d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d42:
	/* 0x2d42: cmp    WORD PTR [rdi+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_2d4a:
	/* 0x2d4a: je     2d6a <generic_sleepable_preload+0x2d6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d6a;
	}
x86_l_2d4c:
	/* 0x2d4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d51:
	/* 0x2d51: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d56:
	/* 0x2d56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d60:
	/* 0x2d60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d62:
	/* 0x2d62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d64:
	/* 0x2d64: js     5fbe <generic_sleepable_preload+0x5fbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24510ULL;
	}
x86_l_2d6a:
	/* 0x2d6a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d6f:
	/* 0x2d6f: cmp    WORD PTR [rdi+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_2d77:
	/* 0x2d77: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2d7a:
	/* 0x2d7a: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2d80:
	/* 0x2d80: mov    eax,DWORD PTR [rdi+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2d86:
	/* 0x2d86: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d8b:
	/* 0x2d8b: cmp    WORD PTR [rdi+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_2d93:
	/* 0x2d93: je     2db3 <generic_sleepable_preload+0x2db3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db3;
	}
x86_l_2d95:
	/* 0x2d95: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9f:
	/* 0x2d9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da4:
	/* 0x2da4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da9:
	/* 0x2da9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dab:
	/* 0x2dab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dad:
	/* 0x2dad: js     60b2 <generic_sleepable_preload+0x60b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24754ULL;
	}
x86_l_2db3:
	/* 0x2db3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2db8:
	/* 0x2db8: cmp    WORD PTR [rdi+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2dc0:
	/* 0x2dc0: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2dc3:
	/* 0x2dc3: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2dc9:
	/* 0x2dc9: mov    eax,DWORD PTR [rdi+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2dcf:
	/* 0x2dcf: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2dd4:
	/* 0x2dd4: cmp    WORD PTR [rdi+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_2ddc:
	/* 0x2ddc: je     2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f25;
	}
x86_l_2de2:
	/* 0x2de2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2de7:
	/* 0x2de7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dec:
	/* 0x2dec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df1:
	/* 0x2df1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df6:
	/* 0x2df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df8:
	/* 0x2df8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dfd:
	/* 0x2dfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dff:
	/* 0x2dff: jns    2f25 <generic_sleepable_preload+0x2f25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2f25;
	}
x86_l_2e05:
	/* 0x2e05: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2e0a:
	/* 0x2e0a: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e0f:
	/* 0x2e0f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2e14:
	/* 0x2e14: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e19:
	/* 0x2e19: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2e1e:
	/* 0x2e1e: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e23:
	/* 0x2e23: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2e28:
	/* 0x2e28: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	goto x86_l_2e9b;
x86_l_2e2a:
	/* 0x2e2a: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2e2f:
	/* 0x2e2f: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e34:
	/* 0x2e34: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e39:
	/* 0x2e39: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_2e40:
	/* 0x2e40: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_2e47:
	/* 0x2e47: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_2e4e:
	/* 0x2e4e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2e53:
	/* 0x2e53: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e56:
	/* 0x2e56: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e5b:
	/* 0x2e5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e60:
	/* 0x2e60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e62:
	/* 0x2e62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e64:
	/* 0x2e64: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e67:
	/* 0x2e67: je     2209 <generic_sleepable_preload+0x2209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8713ULL;
	}
x86_l_2e6d:
	/* 0x2e6d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2e6f:
	/* 0x2e6f: jmp    2287 <generic_sleepable_preload+0x2287> */
	return 8839ULL;
x86_l_2e74:
	/* 0x2e74: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2e79:
	/* 0x2e79: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	goto x86_l_2e9b;
x86_l_2e7b:
	/* 0x2e7b: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2e80:
	/* 0x2e80: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e85:
	/* 0x2e85: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2e8a:
	/* 0x2e8a: jmp    2e9b <generic_sleepable_preload+0x2e9b> */
	goto x86_l_2e9b;
x86_l_2e8c:
	/* 0x2e8c: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_2e91:
	/* 0x2e91: jmp    2f22 <generic_sleepable_preload+0x2f22> */
	goto x86_l_2f22;
x86_l_2e96:
	/* 0x2e96: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2e9b:
	/* 0x2e9b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e9e:
	/* 0x2e9e: mov    ebx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea1:
	/* 0x2ea1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea6:
	/* 0x2ea6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eab:
	/* 0x2eab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_2eb3:
	/* 0x2eb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb5:
	/* 0x2eb5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2eb8:
	/* 0x2eb8: jne    2fc6 <generic_sleepable_preload+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fc6;
	}
x86_l_2ebe:
	/* 0x2ebe: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec3:
	/* 0x2ec3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2ec8:
	/* 0x2ec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eca:
	/* 0x2eca: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ecf:
	/* 0x2ecf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2edc:
	/* 0x2edc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2ee3:
	/* 0x2ee3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee8:
	/* 0x2ee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eea:
	/* 0x2eea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eed:
	/* 0x2eed: je     2fc6 <generic_sleepable_preload+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc6;
	}
x86_l_2ef3:
	/* 0x2ef3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2efc:
	/* 0x2efc: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f03:
	/* 0x2f03: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f08:
	/* 0x2f08: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f0b:
	/* 0x2f0b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f0e:
	/* 0x2f0e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f11:
	/* 0x2f11: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f13:
	/* 0x2f13: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2f16:
	/* 0x2f16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f1b:
	/* 0x2f1b: jmp    2f87 <generic_sleepable_preload+0x2f87> */
	goto x86_l_2f87;
x86_l_2f1d:
	/* 0x2f1d: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_2f22:
	/* 0x2f22: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f25:
	/* 0x2f25: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_2f28:
	/* 0x2f28: jne    2fcb <generic_sleepable_preload+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fcb;
	}
x86_l_2f2e:
	/* 0x2f2e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f33:
	/* 0x2f33: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f38:
	/* 0x2f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f3a:
	/* 0x2f3a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f47:
	/* 0x2f47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_2f53:
	/* 0x2f53: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f58:
	/* 0x2f58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5a:
	/* 0x2f5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f5d:
	/* 0x2f5d: je     2fc6 <generic_sleepable_preload+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc6;
	}
x86_l_2f5f:
	/* 0x2f5f: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2f65:
	/* 0x2f65: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_2f68:
	/* 0x2f68: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_2f6f:
	/* 0x2f6f: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f74:
	/* 0x2f74: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f77:
	/* 0x2f77: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f7a:
	/* 0x2f7a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f7d:
	/* 0x2f7d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f7f:
	/* 0x2f7f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2f82:
	/* 0x2f82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f87:
	/* 0x2f87: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2f8a:
	/* 0x2f8a: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2f8d:
	/* 0x2f8d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_2f90:
	/* 0x2f90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f92:
	/* 0x2f92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f95:
	/* 0x2f95: je     2fc6 <generic_sleepable_preload+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc6;
	}
x86_l_2f97:
	/* 0x2f97: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2f9a:
	/* 0x2f9a: je     2fc4 <generic_sleepable_preload+0x2fc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fc4;
	}
x86_l_2f9c:
	/* 0x2f9c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2f9f:
	/* 0x2f9f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2fa3:
	/* 0x2fa3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2fab:
	/* 0x2fab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fad:
	/* 0x2fad: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2fb0:
	/* 0x2fb0: call   2fb5 <generic_sleepable_preload+0x2fb5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_2fb5:
	/* 0x2fb5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2fb7:
	/* 0x2fb7: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_2fba:
	/* 0x2fba: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2fbc:
	/* 0x2fbc: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_2fc1:
	/* 0x2fc1: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_2fc4:
	/* 0x2fc4: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc6:
	/* 0x2fc6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fcb:
	/* 0x2fcb: mov    eax,DWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fce:
	/* 0x2fce: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_2fd3:
	/* 0x2fd3: je     3f3f <generic_sleepable_preload+0x3f3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16191ULL;
	}
x86_l_2fd9:
	/* 0x2fd9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2fdb:
	/* 0x2fdb: js     303a <generic_sleepable_preload+0x303a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_303a;
	}
x86_l_2fdd:
	/* 0x2fdd: movzx  ecx,BYTE PTR [rdi+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_2fe4:
	/* 0x2fe4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fe6:
	/* 0x2fe6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2fe9:
	/* 0x2fe9: jg     309d <generic_sleepable_preload+0x309d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_309d;
	}
x86_l_2fef:
	/* 0x2fef: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ff2:
	/* 0x2ff2: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ff7:
	/* 0x2ff7: je     317b <generic_sleepable_preload+0x317b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12667ULL;
	}
x86_l_2ffd:
	/* 0x2ffd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3000:
	/* 0x3000: jne    3200 <generic_sleepable_preload+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12800ULL;
	}
x86_l_3006:
	/* 0x3006: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_300c:
	/* 0x300c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3012:
	/* 0x3012: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3015:
	/* 0x3015: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_301a:
	/* 0x301a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_301f:
	/* 0x301f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3024:
	/* 0x3024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3026:
	/* 0x3026: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_302b:
	/* 0x302b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_302d:
	/* 0x302d: je     3187 <generic_sleepable_preload+0x3187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12679ULL;
	}
x86_l_3033:
	/* 0x3033: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3035:
	/* 0x3035: jmp    3200 <generic_sleepable_preload+0x3200> */
	return 12800ULL;
x86_l_303a:
	/* 0x303a: movzx  ecx,BYTE PTR [rdi+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_3041:
	/* 0x3041: movzx  eax,WORD PTR [rdi+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3048:
	/* 0x3048: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_304e:
	/* 0x304e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3050:
	/* 0x3050: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3053:
	/* 0x3053: jle    30f5 <generic_sleepable_preload+0x30f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30f5;
	}
x86_l_3059:
	/* 0x3059: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_305c:
	/* 0x305c: jle    3121 <generic_sleepable_preload+0x3121> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 12577ULL;
	}
x86_l_3062:
	/* 0x3062: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3065:
	/* 0x3065: jle    37cf <generic_sleepable_preload+0x37cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 14287ULL;
	}
x86_l_306b:
	/* 0x306b: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3073:
	/* 0x3073: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3076:
	/* 0x3076: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14310ULL;
	}
x86_l_307c:
	/* 0x307c: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3081:
	/* 0x3081: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3084:
	/* 0x3084: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14310ULL;
	}
x86_l_308a:
	/* 0x308a: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_308f:
	/* 0x308f: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3092:
	/* 0x3092: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14310ULL;
	}
x86_l_3098:
	/* 0x3098: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	return 14329ULL;
x86_l_309d:
	/* 0x309d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30a0:
	/* 0x30a0: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30a5:
	/* 0x30a5: je     31ac <generic_sleepable_preload+0x31ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12716ULL;
	}
x86_l_30ab:
	/* 0x30ab: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_30ae:
	/* 0x30ae: jne    3200 <generic_sleepable_preload+0x3200> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12800ULL;
	}
x86_l_30b4:
	/* 0x30b4: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_30ba:
	/* 0x30ba: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30c0:
	/* 0x30c0: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30c3:
	/* 0x30c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30c8:
	/* 0x30c8: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_30cb:
	/* 0x30cb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30d0:
	/* 0x30d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d5:
	/* 0x30d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d7:
	/* 0x30d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30d9:
	/* 0x30d9: jne    31fb <generic_sleepable_preload+0x31fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12795ULL;
	}
x86_l_30df:
	/* 0x30df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_30e4:
	/* 0x30e4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30e9:
	/* 0x30e9: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_30f0:
	/* 0x30f0: jmp    3dca <generic_sleepable_preload+0x3dca> */
	return 15818ULL;
x86_l_30f5:
	/* 0x30f5: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_30f8:
	/* 0x30f8: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30fd:
	/* 0x30fd: jg     314e <generic_sleepable_preload+0x314e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 12622ULL;
	}
x86_l_30ff:
	/* 0x30ff: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
	return 12546ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12546ULL: goto x86_l_3102;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12560ULL: goto x86_l_3110;
	case 12563ULL: goto x86_l_3113;
	case 12566ULL: goto x86_l_3116;
	case 12572ULL: goto x86_l_311c;
	case 12577ULL: goto x86_l_3121;
	case 12580ULL: goto x86_l_3124;
	case 12586ULL: goto x86_l_312a;
	case 12594ULL: goto x86_l_3132;
	case 12597ULL: goto x86_l_3135;
	case 12603ULL: goto x86_l_313b;
	case 12608ULL: goto x86_l_3140;
	case 12611ULL: goto x86_l_3143;
	case 12617ULL: goto x86_l_3149;
	case 12622ULL: goto x86_l_314e;
	case 12625ULL: goto x86_l_3151;
	case 12631ULL: goto x86_l_3157;
	case 12639ULL: goto x86_l_315f;
	case 12642ULL: goto x86_l_3162;
	case 12648ULL: goto x86_l_3168;
	case 12653ULL: goto x86_l_316d;
	case 12656ULL: goto x86_l_3170;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12674ULL: goto x86_l_3182;
	case 12679ULL: goto x86_l_3187;
	case 12686ULL: goto x86_l_318e;
	case 12693ULL: goto x86_l_3195;
	case 12700ULL: goto x86_l_319c;
	case 12705ULL: goto x86_l_31a1;
	case 12710ULL: goto x86_l_31a6;
	case 12714ULL: goto x86_l_31aa;
	case 12716ULL: goto x86_l_31ac;
	case 12722ULL: goto x86_l_31b2;
	case 12728ULL: goto x86_l_31b8;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12749ULL: goto x86_l_31cd;
	case 12751ULL: goto x86_l_31cf;
	case 12753ULL: goto x86_l_31d1;
	case 12755ULL: goto x86_l_31d3;
	case 12761ULL: goto x86_l_31d9;
	case 12767ULL: goto x86_l_31df;
	case 12770ULL: goto x86_l_31e2;
	case 12775ULL: goto x86_l_31e7;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12787ULL: goto x86_l_31f3;
	case 12789ULL: goto x86_l_31f5;
	case 12795ULL: goto x86_l_31fb;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12807ULL: goto x86_l_3207;
	case 12810ULL: goto x86_l_320a;
	case 12818ULL: goto x86_l_3212;
	case 12824ULL: goto x86_l_3218;
	case 12831ULL: goto x86_l_321f;
	case 12834ULL: goto x86_l_3222;
	case 12840ULL: goto x86_l_3228;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12855ULL: goto x86_l_3237;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12890ULL: goto x86_l_325a;
	case 12895ULL: goto x86_l_325f;
	case 12897ULL: goto x86_l_3261;
	case 12903ULL: goto x86_l_3267;
	case 12911ULL: goto x86_l_326f;
	case 12917ULL: goto x86_l_3275;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12936ULL: goto x86_l_3288;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12960ULL: goto x86_l_32a0;
	case 12965ULL: goto x86_l_32a5;
	case 12967ULL: goto x86_l_32a7;
	case 12973ULL: goto x86_l_32ad;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13006ULL: goto x86_l_32ce;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13037ULL: goto x86_l_32ed;
	case 13043ULL: goto x86_l_32f3;
	case 13051ULL: goto x86_l_32fb;
	case 13057ULL: goto x86_l_3301;
	case 13063ULL: goto x86_l_3307;
	case 13068ULL: goto x86_l_330c;
	case 13076ULL: goto x86_l_3314;
	case 13078ULL: goto x86_l_3316;
	case 13083ULL: goto x86_l_331b;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13098ULL: goto x86_l_332a;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13113ULL: goto x86_l_3339;
	case 13121ULL: goto x86_l_3341;
	case 13127ULL: goto x86_l_3347;
	case 13133ULL: goto x86_l_334d;
	case 13138ULL: goto x86_l_3352;
	case 13146ULL: goto x86_l_335a;
	case 13148ULL: goto x86_l_335c;
	case 13153ULL: goto x86_l_3361;
	case 13158ULL: goto x86_l_3366;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13177ULL: goto x86_l_3379;
	case 13183ULL: goto x86_l_337f;
	case 13191ULL: goto x86_l_3387;
	case 13197ULL: goto x86_l_338d;
	case 13203ULL: goto x86_l_3393;
	case 13208ULL: goto x86_l_3398;
	case 13216ULL: goto x86_l_33a0;
	case 13218ULL: goto x86_l_33a2;
	case 13223ULL: goto x86_l_33a7;
	case 13228ULL: goto x86_l_33ac;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13240ULL: goto x86_l_33b8;
	case 13245ULL: goto x86_l_33bd;
	case 13247ULL: goto x86_l_33bf;
	case 13253ULL: goto x86_l_33c5;
	case 13261ULL: goto x86_l_33cd;
	case 13267ULL: goto x86_l_33d3;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13286ULL: goto x86_l_33e6;
	case 13288ULL: goto x86_l_33e8;
	case 13293ULL: goto x86_l_33ed;
	case 13298ULL: goto x86_l_33f2;
	case 13303ULL: goto x86_l_33f7;
	case 13308ULL: goto x86_l_33fc;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13331ULL: goto x86_l_3413;
	case 13337ULL: goto x86_l_3419;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13356ULL: goto x86_l_342c;
	case 13358ULL: goto x86_l_342e;
	case 13363ULL: goto x86_l_3433;
	case 13368ULL: goto x86_l_3438;
	case 13373ULL: goto x86_l_343d;
	case 13378ULL: goto x86_l_3442;
	case 13380ULL: goto x86_l_3444;
	case 13382ULL: goto x86_l_3446;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13401ULL: goto x86_l_3459;
	case 13407ULL: goto x86_l_345f;
	case 13413ULL: goto x86_l_3465;
	case 13418ULL: goto x86_l_346a;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13443ULL: goto x86_l_3483;
	case 13448ULL: goto x86_l_3488;
	case 13450ULL: goto x86_l_348a;
	case 13452ULL: goto x86_l_348c;
	case 13458ULL: goto x86_l_3492;
	case 13463ULL: goto x86_l_3497;
	case 13471ULL: goto x86_l_349f;
	case 13477ULL: goto x86_l_34a5;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13496ULL: goto x86_l_34b8;
	case 13502ULL: goto x86_l_34be;
	case 13507ULL: goto x86_l_34c3;
	case 13512ULL: goto x86_l_34c8;
	case 13515ULL: goto x86_l_34cb;
	case 13517ULL: goto x86_l_34cd;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13532ULL: goto x86_l_34dc;
	case 13537ULL: goto x86_l_34e1;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13546ULL: goto x86_l_34ea;
	case 13552ULL: goto x86_l_34f0;
	case 13560ULL: goto x86_l_34f8;
	case 13566ULL: goto x86_l_34fe;
	case 13572ULL: goto x86_l_3504;
	case 13577ULL: goto x86_l_3509;
	case 13585ULL: goto x86_l_3511;
	case 13587ULL: goto x86_l_3513;
	case 13592ULL: goto x86_l_3518;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13616ULL: goto x86_l_3530;
	case 13622ULL: goto x86_l_3536;
	case 13630ULL: goto x86_l_353e;
	case 13636ULL: goto x86_l_3544;
	case 13642ULL: goto x86_l_354a;
	case 13647ULL: goto x86_l_354f;
	case 13655ULL: goto x86_l_3557;
	case 13657ULL: goto x86_l_3559;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13679ULL: goto x86_l_356f;
	case 13684ULL: goto x86_l_3574;
	case 13686ULL: goto x86_l_3576;
	case 13692ULL: goto x86_l_357c;
	case 13700ULL: goto x86_l_3584;
	case 13706ULL: goto x86_l_358a;
	case 13712ULL: goto x86_l_3590;
	case 13717ULL: goto x86_l_3595;
	case 13725ULL: goto x86_l_359d;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13737ULL: goto x86_l_35a9;
	case 13742ULL: goto x86_l_35ae;
	case 13747ULL: goto x86_l_35b3;
	case 13749ULL: goto x86_l_35b5;
	case 13754ULL: goto x86_l_35ba;
	case 13756ULL: goto x86_l_35bc;
	case 13762ULL: goto x86_l_35c2;
	case 13770ULL: goto x86_l_35ca;
	case 13776ULL: goto x86_l_35d0;
	case 13782ULL: goto x86_l_35d6;
	case 13787ULL: goto x86_l_35db;
	case 13795ULL: goto x86_l_35e3;
	case 13797ULL: goto x86_l_35e5;
	case 13802ULL: goto x86_l_35ea;
	case 13807ULL: goto x86_l_35ef;
	case 13812ULL: goto x86_l_35f4;
	case 13817ULL: goto x86_l_35f9;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13826ULL: goto x86_l_3602;
	case 13832ULL: goto x86_l_3608;
	case 13840ULL: goto x86_l_3610;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13865ULL: goto x86_l_3629;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13877ULL: goto x86_l_3635;
	case 13882ULL: goto x86_l_363a;
	case 13887ULL: goto x86_l_363f;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13896ULL: goto x86_l_3648;
	case 13902ULL: goto x86_l_364e;
	case 13910ULL: goto x86_l_3656;
	case 13916ULL: goto x86_l_365c;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13935ULL: goto x86_l_366f;
	case 13937ULL: goto x86_l_3671;
	case 13942ULL: goto x86_l_3676;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13957ULL: goto x86_l_3685;
	case 13959ULL: goto x86_l_3687;
	case 13961ULL: goto x86_l_3689;
	case 13967ULL: goto x86_l_368f;
	case 13972ULL: goto x86_l_3694;
	case 13980ULL: goto x86_l_369c;
	case 13986ULL: goto x86_l_36a2;
	case 13989ULL: goto x86_l_36a5;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14008ULL: goto x86_l_36b8;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14032ULL: goto x86_l_36d0;
	case 14034ULL: goto x86_l_36d2;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14053ULL: goto x86_l_36e5;
	case 14056ULL: goto x86_l_36e8;
	case 14062ULL: goto x86_l_36ee;
	case 14068ULL: goto x86_l_36f4;
	case 14073ULL: goto x86_l_36f9;
	case 14081ULL: goto x86_l_3701;
	case 14083ULL: goto x86_l_3703;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14098ULL: goto x86_l_3712;
	case 14103ULL: goto x86_l_3717;
	case 14105ULL: goto x86_l_3719;
	case 14107ULL: goto x86_l_371b;
	case 14113ULL: goto x86_l_3721;
	case 14118ULL: goto x86_l_3726;
	case 14126ULL: goto x86_l_372e;
	case 14129ULL: goto x86_l_3731;
	case 14135ULL: goto x86_l_3737;
	case 14141ULL: goto x86_l_373d;
	case 14146ULL: goto x86_l_3742;
	case 14154ULL: goto x86_l_374a;
	case 14160ULL: goto x86_l_3750;
	case 14165ULL: goto x86_l_3755;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14180ULL: goto x86_l_3764;
	case 14182ULL: goto x86_l_3766;
	case 14187ULL: goto x86_l_376b;
	case 14189ULL: goto x86_l_376d;
	case 14195ULL: goto x86_l_3773;
	case 14200ULL: goto x86_l_3778;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14223ULL: goto x86_l_378f;
	case 14226ULL: goto x86_l_3792;
	case 14228ULL: goto x86_l_3794;
	case 14233ULL: goto x86_l_3799;
	case 14236ULL: goto x86_l_379c;
	case 14238ULL: goto x86_l_379e;
	case 14240ULL: goto x86_l_37a0;
	case 14245ULL: goto x86_l_37a5;
	case 14248ULL: goto x86_l_37a8;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14258ULL: goto x86_l_37b2;
	case 14260ULL: goto x86_l_37b4;
	case 14262ULL: goto x86_l_37b6;
	case 14270ULL: goto x86_l_37be;
	case 14273ULL: goto x86_l_37c1;
	case 14275ULL: goto x86_l_37c3;
	case 14280ULL: goto x86_l_37c8;
	case 14283ULL: goto x86_l_37cb;
	case 14285ULL: goto x86_l_37cd;
	case 14287ULL: goto x86_l_37cf;
	case 14295ULL: goto x86_l_37d7;
	case 14298ULL: goto x86_l_37da;
	case 14300ULL: goto x86_l_37dc;
	case 14305ULL: goto x86_l_37e1;
	case 14308ULL: goto x86_l_37e4;
	case 14310ULL: goto x86_l_37e6;
	case 14313ULL: goto x86_l_37e9;
	case 14315ULL: goto x86_l_37eb;
	case 14317ULL: goto x86_l_37ed;
	case 14322ULL: goto x86_l_37f2;
	case 14324ULL: goto x86_l_37f4;
	case 14329ULL: goto x86_l_37f9;
	case 14334ULL: goto x86_l_37fe;
	case 14337ULL: goto x86_l_3801;
	case 14339ULL: goto x86_l_3803;
	case 14342ULL: goto x86_l_3806;
	case 14350ULL: goto x86_l_380e;
	case 14356ULL: goto x86_l_3814;
	case 14363ULL: goto x86_l_381b;
	case 14366ULL: goto x86_l_381e;
	case 14372ULL: goto x86_l_3824;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3102:
	/* 0x3102: jg     37a0 <generic_sleepable_preload+0x37a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_37a0;
	}
x86_l_3108:
	/* 0x3108: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_310a:
	/* 0x310a: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_3110:
	/* 0x3110: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3113:
	/* 0x3113: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3116:
	/* 0x3116: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_311c:
	/* 0x311c: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_3121:
	/* 0x3121: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3124:
	/* 0x3124: jg     3787 <generic_sleepable_preload+0x3787> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3787;
	}
x86_l_312a:
	/* 0x312a: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3132:
	/* 0x3132: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3135:
	/* 0x3135: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_313b:
	/* 0x313b: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3140:
	/* 0x3140: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3143:
	/* 0x3143: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_3149:
	/* 0x3149: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_314e:
	/* 0x314e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3151:
	/* 0x3151: jg     37b6 <generic_sleepable_preload+0x37b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_37b6;
	}
x86_l_3157:
	/* 0x3157: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_315f:
	/* 0x315f: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3162:
	/* 0x3162: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_3168:
	/* 0x3168: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_316d:
	/* 0x316d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3170:
	/* 0x3170: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_3176:
	/* 0x3176: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_317b:
	/* 0x317b: mov    rax,QWORD PTR [rdi+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_3182:
	/* 0x3182: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3187:
	/* 0x3187: movzx  eax,BYTE PTR [rdi+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_318e:
	/* 0x318e: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_3195:
	/* 0x3195: cmp    BYTE PTR [rdi+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_319c:
	/* 0x319c: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_31a1:
	/* 0x31a1: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_31a6:
	/* 0x31a6: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_31aa:
	/* 0x31aa: jmp    3200 <generic_sleepable_preload+0x3200> */
	goto x86_l_3200;
x86_l_31ac:
	/* 0x31ac: mov    edx,DWORD PTR [rdi+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_31b2:
	/* 0x31b2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31b8:
	/* 0x31b8: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31bb:
	/* 0x31bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31c0:
	/* 0x31c0: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_31c3:
	/* 0x31c3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c8:
	/* 0x31c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31cd:
	/* 0x31cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cf:
	/* 0x31cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31d1:
	/* 0x31d1: jne    31fb <generic_sleepable_preload+0x31fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31fb;
	}
x86_l_31d3:
	/* 0x31d3: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_31d9:
	/* 0x31d9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31df:
	/* 0x31df: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_31e2:
	/* 0x31e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31e7:
	/* 0x31e7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ec:
	/* 0x31ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31f1:
	/* 0x31f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f3:
	/* 0x31f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31f5:
	/* 0x31f5: je     3da8 <generic_sleepable_preload+0x3da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15784ULL;
	}
x86_l_31fb:
	/* 0x31fb: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_31fd:
	/* 0x31fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3200:
	/* 0x3200: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3205:
	/* 0x3205: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3207:
	/* 0x3207: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_320a:
	/* 0x320a: cmp    WORD PTR [rdi+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_3212:
	/* 0x3212: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3218:
	/* 0x3218: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_321f:
	/* 0x321f: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3222:
	/* 0x3222: mov    edx,DWORD PTR [rdi+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3228:
	/* 0x3228: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_322b:
	/* 0x322b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3230:
	/* 0x3230: movzx  eax,WORD PTR [rdi+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_3237:
	/* 0x3237: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3239:
	/* 0x3239: je     34c8 <generic_sleepable_preload+0x34c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34c8;
	}
x86_l_323f:
	/* 0x323f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3242:
	/* 0x3242: je     3267 <generic_sleepable_preload+0x3267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3267;
	}
x86_l_3244:
	/* 0x3244: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3249:
	/* 0x3249: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_324e:
	/* 0x324e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3253:
	/* 0x3253: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3258:
	/* 0x3258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325a:
	/* 0x325a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_325f:
	/* 0x325f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3261:
	/* 0x3261: js     377d <generic_sleepable_preload+0x377d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_377d;
	}
x86_l_3267:
	/* 0x3267: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_326f:
	/* 0x326f: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3275:
	/* 0x3275: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_327b:
	/* 0x327b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3280:
	/* 0x3280: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3288:
	/* 0x3288: je     32ad <generic_sleepable_preload+0x32ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32ad;
	}
x86_l_328a:
	/* 0x328a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_328f:
	/* 0x328f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3294:
	/* 0x3294: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3299:
	/* 0x3299: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_329e:
	/* 0x329e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a0:
	/* 0x32a0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32a5:
	/* 0x32a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32a7:
	/* 0x32a7: js     3d83 <generic_sleepable_preload+0x3d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15747ULL;
	}
x86_l_32ad:
	/* 0x32ad: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_32b5:
	/* 0x32b5: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_32bb:
	/* 0x32bb: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_32c1:
	/* 0x32c1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_32c6:
	/* 0x32c6: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_32ce:
	/* 0x32ce: je     32f3 <generic_sleepable_preload+0x32f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32f3;
	}
x86_l_32d0:
	/* 0x32d0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_32d5:
	/* 0x32d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32da:
	/* 0x32da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32df:
	/* 0x32df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e4:
	/* 0x32e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e6:
	/* 0x32e6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32eb:
	/* 0x32eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32ed:
	/* 0x32ed: js     3d97 <generic_sleepable_preload+0x3d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15767ULL;
	}
x86_l_32f3:
	/* 0x32f3: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_32fb:
	/* 0x32fb: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3301:
	/* 0x3301: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3307:
	/* 0x3307: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_330c:
	/* 0x330c: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3314:
	/* 0x3314: je     3339 <generic_sleepable_preload+0x3339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3339;
	}
x86_l_3316:
	/* 0x3316: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_331b:
	/* 0x331b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3320:
	/* 0x3320: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3325:
	/* 0x3325: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_332a:
	/* 0x332a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332c:
	/* 0x332c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3331:
	/* 0x3331: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3333:
	/* 0x3333: js     3de8 <generic_sleepable_preload+0x3de8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15848ULL;
	}
x86_l_3339:
	/* 0x3339: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3341:
	/* 0x3341: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3347:
	/* 0x3347: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_334d:
	/* 0x334d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3352:
	/* 0x3352: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_335a:
	/* 0x335a: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_337f;
	}
x86_l_335c:
	/* 0x335c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3361:
	/* 0x3361: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3366:
	/* 0x3366: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_336b:
	/* 0x336b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3370:
	/* 0x3370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3372:
	/* 0x3372: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3377:
	/* 0x3377: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3379:
	/* 0x3379: js     3df9 <generic_sleepable_preload+0x3df9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15865ULL;
	}
x86_l_337f:
	/* 0x337f: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3387:
	/* 0x3387: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_338d:
	/* 0x338d: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3393:
	/* 0x3393: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3398:
	/* 0x3398: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_33a0:
	/* 0x33a0: je     33c5 <generic_sleepable_preload+0x33c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33c5;
	}
x86_l_33a2:
	/* 0x33a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33a7:
	/* 0x33a7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33ac:
	/* 0x33ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b1:
	/* 0x33b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33b6:
	/* 0x33b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b8:
	/* 0x33b8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33bd:
	/* 0x33bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33bf:
	/* 0x33bf: js     3e0a <generic_sleepable_preload+0x3e0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15882ULL;
	}
x86_l_33c5:
	/* 0x33c5: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_33cd:
	/* 0x33cd: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_33d3:
	/* 0x33d3: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_33d9:
	/* 0x33d9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_33de:
	/* 0x33de: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_33e6:
	/* 0x33e6: je     3406 <generic_sleepable_preload+0x3406> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3406;
	}
x86_l_33e8:
	/* 0x33e8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33ed:
	/* 0x33ed: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33f2:
	/* 0x33f2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33f7:
	/* 0x33f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33fc:
	/* 0x33fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33fe:
	/* 0x33fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3400:
	/* 0x3400: js     5dc1 <generic_sleepable_preload+0x5dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24001ULL;
	}
x86_l_3406:
	/* 0x3406: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340b:
	/* 0x340b: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3413:
	/* 0x3413: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3419:
	/* 0x3419: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_341f:
	/* 0x341f: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3424:
	/* 0x3424: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_342c:
	/* 0x342c: je     344c <generic_sleepable_preload+0x344c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_344c;
	}
x86_l_342e:
	/* 0x342e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3433:
	/* 0x3433: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3438:
	/* 0x3438: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_343d:
	/* 0x343d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3442:
	/* 0x3442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3444:
	/* 0x3444: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3446:
	/* 0x3446: js     5f3b <generic_sleepable_preload+0x5f3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24379ULL;
	}
x86_l_344c:
	/* 0x344c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3451:
	/* 0x3451: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3459:
	/* 0x3459: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_345f:
	/* 0x345f: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3465:
	/* 0x3465: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_346a:
	/* 0x346a: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3472:
	/* 0x3472: je     3492 <generic_sleepable_preload+0x3492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3492;
	}
x86_l_3474:
	/* 0x3474: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3479:
	/* 0x3479: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_347e:
	/* 0x347e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3483:
	/* 0x3483: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3488:
	/* 0x3488: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_348a:
	/* 0x348a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_348c:
	/* 0x348c: js     6041 <generic_sleepable_preload+0x6041> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24641ULL;
	}
x86_l_3492:
	/* 0x3492: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3497:
	/* 0x3497: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_349f:
	/* 0x349f: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_34a5:
	/* 0x34a5: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_34ab:
	/* 0x34ab: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34b0:
	/* 0x34b0: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_34b8:
	/* 0x34b8: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_34be:
	/* 0x34be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34c3:
	/* 0x34c3: jmp    3755 <generic_sleepable_preload+0x3755> */
	goto x86_l_3755;
x86_l_34c8:
	/* 0x34c8: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_34cb:
	/* 0x34cb: je     34f0 <generic_sleepable_preload+0x34f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34f0;
	}
x86_l_34cd:
	/* 0x34cd: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_34d2:
	/* 0x34d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d7:
	/* 0x34d7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34dc:
	/* 0x34dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34e1:
	/* 0x34e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e3:
	/* 0x34e3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34e8:
	/* 0x34e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34ea:
	/* 0x34ea: js     377d <generic_sleepable_preload+0x377d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_377d;
	}
x86_l_34f0:
	/* 0x34f0: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_34f8:
	/* 0x34f8: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_34fe:
	/* 0x34fe: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3504:
	/* 0x3504: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3509:
	/* 0x3509: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3511:
	/* 0x3511: je     3536 <generic_sleepable_preload+0x3536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3536;
	}
x86_l_3513:
	/* 0x3513: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3518:
	/* 0x3518: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_351d:
	/* 0x351d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3522:
	/* 0x3522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3527:
	/* 0x3527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3529:
	/* 0x3529: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_352e:
	/* 0x352e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3530:
	/* 0x3530: js     3d83 <generic_sleepable_preload+0x3d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15747ULL;
	}
x86_l_3536:
	/* 0x3536: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_353e:
	/* 0x353e: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3544:
	/* 0x3544: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_354a:
	/* 0x354a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_354f:
	/* 0x354f: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3557:
	/* 0x3557: je     357c <generic_sleepable_preload+0x357c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_357c;
	}
x86_l_3559:
	/* 0x3559: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_355e:
	/* 0x355e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3563:
	/* 0x3563: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3568:
	/* 0x3568: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_356d:
	/* 0x356d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_356f:
	/* 0x356f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3574:
	/* 0x3574: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3576:
	/* 0x3576: js     3d97 <generic_sleepable_preload+0x3d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15767ULL;
	}
x86_l_357c:
	/* 0x357c: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3584:
	/* 0x3584: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_358a:
	/* 0x358a: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3590:
	/* 0x3590: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3595:
	/* 0x3595: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_359d:
	/* 0x359d: je     35c2 <generic_sleepable_preload+0x35c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c2;
	}
x86_l_359f:
	/* 0x359f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35a4:
	/* 0x35a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35a9:
	/* 0x35a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ae:
	/* 0x35ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35b3:
	/* 0x35b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b5:
	/* 0x35b5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35ba:
	/* 0x35ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35bc:
	/* 0x35bc: js     3de8 <generic_sleepable_preload+0x3de8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15848ULL;
	}
x86_l_35c2:
	/* 0x35c2: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_35ca:
	/* 0x35ca: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_35d0:
	/* 0x35d0: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_35d6:
	/* 0x35d6: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_35db:
	/* 0x35db: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_35e3:
	/* 0x35e3: je     3608 <generic_sleepable_preload+0x3608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3608;
	}
x86_l_35e5:
	/* 0x35e5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_35ea:
	/* 0x35ea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ef:
	/* 0x35ef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f4:
	/* 0x35f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35f9:
	/* 0x35f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35fb:
	/* 0x35fb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3600:
	/* 0x3600: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3602:
	/* 0x3602: js     3df9 <generic_sleepable_preload+0x3df9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15865ULL;
	}
x86_l_3608:
	/* 0x3608: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3610:
	/* 0x3610: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3616:
	/* 0x3616: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_361c:
	/* 0x361c: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3621:
	/* 0x3621: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3629:
	/* 0x3629: je     364e <generic_sleepable_preload+0x364e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_364e;
	}
x86_l_362b:
	/* 0x362b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3630:
	/* 0x3630: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3635:
	/* 0x3635: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_363a:
	/* 0x363a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_363f:
	/* 0x363f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3641:
	/* 0x3641: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3646:
	/* 0x3646: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3648:
	/* 0x3648: js     3e0a <generic_sleepable_preload+0x3e0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 15882ULL;
	}
x86_l_364e:
	/* 0x364e: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3656:
	/* 0x3656: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_365c:
	/* 0x365c: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3662:
	/* 0x3662: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3667:
	/* 0x3667: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_366f:
	/* 0x366f: je     368f <generic_sleepable_preload+0x368f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_368f;
	}
x86_l_3671:
	/* 0x3671: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3676:
	/* 0x3676: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_367b:
	/* 0x367b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3680:
	/* 0x3680: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3685:
	/* 0x3685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3687:
	/* 0x3687: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3689:
	/* 0x3689: js     5dc1 <generic_sleepable_preload+0x5dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24001ULL;
	}
x86_l_368f:
	/* 0x368f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3694:
	/* 0x3694: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_369c:
	/* 0x369c: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_36a2:
	/* 0x36a2: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_36a5:
	/* 0x36a5: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_36ab:
	/* 0x36ab: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36b0:
	/* 0x36b0: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_36b8:
	/* 0x36b8: je     36d8 <generic_sleepable_preload+0x36d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36d8;
	}
x86_l_36ba:
	/* 0x36ba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_36bf:
	/* 0x36bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c4:
	/* 0x36c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36c9:
	/* 0x36c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36ce:
	/* 0x36ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d0:
	/* 0x36d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d2:
	/* 0x36d2: js     5fcb <generic_sleepable_preload+0x5fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24523ULL;
	}
x86_l_36d8:
	/* 0x36d8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36dd:
	/* 0x36dd: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_36e5:
	/* 0x36e5: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_36e8:
	/* 0x36e8: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_36ee:
	/* 0x36ee: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_36f4:
	/* 0x36f4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_36f9:
	/* 0x36f9: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3701:
	/* 0x3701: je     3721 <generic_sleepable_preload+0x3721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3721;
	}
x86_l_3703:
	/* 0x3703: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3708:
	/* 0x3708: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_370d:
	/* 0x370d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3712:
	/* 0x3712: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3717:
	/* 0x3717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3719:
	/* 0x3719: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_371b:
	/* 0x371b: js     60c7 <generic_sleepable_preload+0x60c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24775ULL;
	}
x86_l_3721:
	/* 0x3721: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3726:
	/* 0x3726: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_372e:
	/* 0x372e: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_3731:
	/* 0x3731: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3737:
	/* 0x3737: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_373d:
	/* 0x373d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_3742:
	/* 0x3742: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_374a:
	/* 0x374a: je     3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15890ULL;
	}
x86_l_3750:
	/* 0x3750: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3755:
	/* 0x3755: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375a:
	/* 0x375a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375f:
	/* 0x375f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3764:
	/* 0x3764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3766:
	/* 0x3766: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_376b:
	/* 0x376b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_376d:
	/* 0x376d: jns    3e12 <generic_sleepable_preload+0x3e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 15890ULL;
	}
x86_l_3773:
	/* 0x3773: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3778:
	/* 0x3778: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	return 15887ULL;
x86_l_377d:
	/* 0x377d: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3782:
	/* 0x3782: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	return 15887ULL;
x86_l_3787:
	/* 0x3787: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_378f:
	/* 0x378f: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_3792:
	/* 0x3792: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_3794:
	/* 0x3794: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3799:
	/* 0x3799: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_379c:
	/* 0x379c: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_379e:
	/* 0x379e: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_37a0:
	/* 0x37a0: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_37a5:
	/* 0x37a5: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_37a8:
	/* 0x37a8: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_37aa:
	/* 0x37aa: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_37af:
	/* 0x37af: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_37b2:
	/* 0x37b2: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_37b4:
	/* 0x37b4: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_37b6:
	/* 0x37b6: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_37be:
	/* 0x37be: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_37c1:
	/* 0x37c1: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_37c3:
	/* 0x37c3: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_37c8:
	/* 0x37c8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_37cb:
	/* 0x37cb: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_37cd:
	/* 0x37cd: jmp    37f9 <generic_sleepable_preload+0x37f9> */
	goto x86_l_37f9;
x86_l_37cf:
	/* 0x37cf: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_37d7:
	/* 0x37d7: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_37da:
	/* 0x37da: je     37e6 <generic_sleepable_preload+0x37e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e6;
	}
x86_l_37dc:
	/* 0x37dc: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_37e1:
	/* 0x37e1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_37e4:
	/* 0x37e4: jne    37f9 <generic_sleepable_preload+0x37f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37f9;
	}
x86_l_37e6:
	/* 0x37e6: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_37e9:
	/* 0x37e9: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_37eb:
	/* 0x37eb: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_37ed:
	/* 0x37ed: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_37f2:
	/* 0x37f2: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_37f4:
	/* 0x37f4: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_37f9:
	/* 0x37f9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37fe:
	/* 0x37fe: mov    ebx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3801:
	/* 0x3801: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3803:
	/* 0x3803: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_3806:
	/* 0x3806: cmp    WORD PTR [rdi+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_380e:
	/* 0x380e: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16025ULL;
	}
x86_l_3814:
	/* 0x3814: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_381b:
	/* 0x381b: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_381e:
	/* 0x381e: mov    edx,DWORD PTR [rdi+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3824:
	/* 0x3824: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
	return 14375ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14375ULL: goto x86_l_3827;
	case 14380ULL: goto x86_l_382c;
	case 14387ULL: goto x86_l_3833;
	case 14389ULL: goto x86_l_3835;
	case 14395ULL: goto x86_l_383b;
	case 14398ULL: goto x86_l_383e;
	case 14400ULL: goto x86_l_3840;
	case 14405ULL: goto x86_l_3845;
	case 14410ULL: goto x86_l_384a;
	case 14415ULL: goto x86_l_384f;
	case 14420ULL: goto x86_l_3854;
	case 14422ULL: goto x86_l_3856;
	case 14427ULL: goto x86_l_385b;
	case 14429ULL: goto x86_l_385d;
	case 14435ULL: goto x86_l_3863;
	case 14443ULL: goto x86_l_386b;
	case 14449ULL: goto x86_l_3871;
	case 14455ULL: goto x86_l_3877;
	case 14460ULL: goto x86_l_387c;
	case 14468ULL: goto x86_l_3884;
	case 14470ULL: goto x86_l_3886;
	case 14475ULL: goto x86_l_388b;
	case 14480ULL: goto x86_l_3890;
	case 14485ULL: goto x86_l_3895;
	case 14490ULL: goto x86_l_389a;
	case 14492ULL: goto x86_l_389c;
	case 14497ULL: goto x86_l_38a1;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14513ULL: goto x86_l_38b1;
	case 14519ULL: goto x86_l_38b7;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14538ULL: goto x86_l_38ca;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14550ULL: goto x86_l_38d6;
	case 14555ULL: goto x86_l_38db;
	case 14560ULL: goto x86_l_38e0;
	case 14562ULL: goto x86_l_38e2;
	case 14567ULL: goto x86_l_38e7;
	case 14569ULL: goto x86_l_38e9;
	case 14575ULL: goto x86_l_38ef;
	case 14583ULL: goto x86_l_38f7;
	case 14589ULL: goto x86_l_38fd;
	case 14595ULL: goto x86_l_3903;
	case 14600ULL: goto x86_l_3908;
	case 14608ULL: goto x86_l_3910;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14620ULL: goto x86_l_391c;
	case 14625ULL: goto x86_l_3921;
	case 14630ULL: goto x86_l_3926;
	case 14632ULL: goto x86_l_3928;
	case 14637ULL: goto x86_l_392d;
	case 14639ULL: goto x86_l_392f;
	case 14645ULL: goto x86_l_3935;
	case 14653ULL: goto x86_l_393d;
	case 14659ULL: goto x86_l_3943;
	case 14665ULL: goto x86_l_3949;
	case 14670ULL: goto x86_l_394e;
	case 14678ULL: goto x86_l_3956;
	case 14680ULL: goto x86_l_3958;
	case 14685ULL: goto x86_l_395d;
	case 14690ULL: goto x86_l_3962;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14702ULL: goto x86_l_396e;
	case 14707ULL: goto x86_l_3973;
	case 14709ULL: goto x86_l_3975;
	case 14715ULL: goto x86_l_397b;
	case 14723ULL: goto x86_l_3983;
	case 14729ULL: goto x86_l_3989;
	case 14735ULL: goto x86_l_398f;
	case 14740ULL: goto x86_l_3994;
	case 14748ULL: goto x86_l_399c;
	case 14750ULL: goto x86_l_399e;
	case 14755ULL: goto x86_l_39a3;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14770ULL: goto x86_l_39b2;
	case 14772ULL: goto x86_l_39b4;
	case 14777ULL: goto x86_l_39b9;
	case 14779ULL: goto x86_l_39bb;
	case 14785ULL: goto x86_l_39c1;
	case 14793ULL: goto x86_l_39c9;
	case 14799ULL: goto x86_l_39cf;
	case 14805ULL: goto x86_l_39d5;
	case 14810ULL: goto x86_l_39da;
	case 14818ULL: goto x86_l_39e2;
	case 14820ULL: goto x86_l_39e4;
	case 14825ULL: goto x86_l_39e9;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14840ULL: goto x86_l_39f8;
	case 14842ULL: goto x86_l_39fa;
	case 14844ULL: goto x86_l_39fc;
	case 14850ULL: goto x86_l_3a02;
	case 14855ULL: goto x86_l_3a07;
	case 14863ULL: goto x86_l_3a0f;
	case 14869ULL: goto x86_l_3a15;
	case 14875ULL: goto x86_l_3a1b;
	case 14880ULL: goto x86_l_3a20;
	case 14888ULL: goto x86_l_3a28;
	case 14890ULL: goto x86_l_3a2a;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14905ULL: goto x86_l_3a39;
	case 14910ULL: goto x86_l_3a3e;
	case 14912ULL: goto x86_l_3a40;
	case 14914ULL: goto x86_l_3a42;
	case 14920ULL: goto x86_l_3a48;
	case 14925ULL: goto x86_l_3a4d;
	case 14933ULL: goto x86_l_3a55;
	case 14939ULL: goto x86_l_3a5b;
	case 14945ULL: goto x86_l_3a61;
	case 14950ULL: goto x86_l_3a66;
	case 14958ULL: goto x86_l_3a6e;
	case 14960ULL: goto x86_l_3a70;
	case 14965ULL: goto x86_l_3a75;
	case 14970ULL: goto x86_l_3a7a;
	case 14975ULL: goto x86_l_3a7f;
	case 14980ULL: goto x86_l_3a84;
	case 14982ULL: goto x86_l_3a86;
	case 14984ULL: goto x86_l_3a88;
	case 14990ULL: goto x86_l_3a8e;
	case 14995ULL: goto x86_l_3a93;
	case 15003ULL: goto x86_l_3a9b;
	case 15009ULL: goto x86_l_3aa1;
	case 15015ULL: goto x86_l_3aa7;
	case 15020ULL: goto x86_l_3aac;
	case 15028ULL: goto x86_l_3ab4;
	case 15034ULL: goto x86_l_3aba;
	case 15039ULL: goto x86_l_3abf;
	case 15044ULL: goto x86_l_3ac4;
	case 15047ULL: goto x86_l_3ac7;
	case 15049ULL: goto x86_l_3ac9;
	case 15054ULL: goto x86_l_3ace;
	case 15059ULL: goto x86_l_3ad3;
	case 15064ULL: goto x86_l_3ad8;
	case 15069ULL: goto x86_l_3add;
	case 15071ULL: goto x86_l_3adf;
	case 15076ULL: goto x86_l_3ae4;
	case 15078ULL: goto x86_l_3ae6;
	case 15084ULL: goto x86_l_3aec;
	case 15092ULL: goto x86_l_3af4;
	case 15098ULL: goto x86_l_3afa;
	case 15104ULL: goto x86_l_3b00;
	case 15109ULL: goto x86_l_3b05;
	case 15117ULL: goto x86_l_3b0d;
	case 15119ULL: goto x86_l_3b0f;
	case 15124ULL: goto x86_l_3b14;
	case 15129ULL: goto x86_l_3b19;
	case 15134ULL: goto x86_l_3b1e;
	case 15139ULL: goto x86_l_3b23;
	case 15141ULL: goto x86_l_3b25;
	case 15146ULL: goto x86_l_3b2a;
	case 15148ULL: goto x86_l_3b2c;
	case 15154ULL: goto x86_l_3b32;
	case 15162ULL: goto x86_l_3b3a;
	case 15168ULL: goto x86_l_3b40;
	case 15174ULL: goto x86_l_3b46;
	case 15179ULL: goto x86_l_3b4b;
	case 15187ULL: goto x86_l_3b53;
	case 15189ULL: goto x86_l_3b55;
	case 15194ULL: goto x86_l_3b5a;
	case 15199ULL: goto x86_l_3b5f;
	case 15204ULL: goto x86_l_3b64;
	case 15209ULL: goto x86_l_3b69;
	case 15211ULL: goto x86_l_3b6b;
	case 15216ULL: goto x86_l_3b70;
	case 15218ULL: goto x86_l_3b72;
	case 15224ULL: goto x86_l_3b78;
	case 15232ULL: goto x86_l_3b80;
	case 15238ULL: goto x86_l_3b86;
	case 15244ULL: goto x86_l_3b8c;
	case 15249ULL: goto x86_l_3b91;
	case 15257ULL: goto x86_l_3b99;
	case 15259ULL: goto x86_l_3b9b;
	case 15264ULL: goto x86_l_3ba0;
	case 15269ULL: goto x86_l_3ba5;
	case 15274ULL: goto x86_l_3baa;
	case 15279ULL: goto x86_l_3baf;
	case 15281ULL: goto x86_l_3bb1;
	case 15286ULL: goto x86_l_3bb6;
	case 15288ULL: goto x86_l_3bb8;
	case 15294ULL: goto x86_l_3bbe;
	case 15302ULL: goto x86_l_3bc6;
	case 15308ULL: goto x86_l_3bcc;
	case 15314ULL: goto x86_l_3bd2;
	case 15319ULL: goto x86_l_3bd7;
	case 15327ULL: goto x86_l_3bdf;
	case 15329ULL: goto x86_l_3be1;
	case 15334ULL: goto x86_l_3be6;
	case 15339ULL: goto x86_l_3beb;
	case 15344ULL: goto x86_l_3bf0;
	case 15349ULL: goto x86_l_3bf5;
	case 15351ULL: goto x86_l_3bf7;
	case 15356ULL: goto x86_l_3bfc;
	case 15358ULL: goto x86_l_3bfe;
	case 15364ULL: goto x86_l_3c04;
	case 15372ULL: goto x86_l_3c0c;
	case 15378ULL: goto x86_l_3c12;
	case 15384ULL: goto x86_l_3c18;
	case 15389ULL: goto x86_l_3c1d;
	case 15397ULL: goto x86_l_3c25;
	case 15399ULL: goto x86_l_3c27;
	case 15404ULL: goto x86_l_3c2c;
	case 15409ULL: goto x86_l_3c31;
	case 15414ULL: goto x86_l_3c36;
	case 15419ULL: goto x86_l_3c3b;
	case 15421ULL: goto x86_l_3c3d;
	case 15426ULL: goto x86_l_3c42;
	case 15428ULL: goto x86_l_3c44;
	case 15434ULL: goto x86_l_3c4a;
	case 15442ULL: goto x86_l_3c52;
	case 15448ULL: goto x86_l_3c58;
	case 15454ULL: goto x86_l_3c5e;
	case 15459ULL: goto x86_l_3c63;
	case 15467ULL: goto x86_l_3c6b;
	case 15469ULL: goto x86_l_3c6d;
	case 15474ULL: goto x86_l_3c72;
	case 15479ULL: goto x86_l_3c77;
	case 15484ULL: goto x86_l_3c7c;
	case 15489ULL: goto x86_l_3c81;
	case 15491ULL: goto x86_l_3c83;
	case 15493ULL: goto x86_l_3c85;
	case 15499ULL: goto x86_l_3c8b;
	case 15504ULL: goto x86_l_3c90;
	case 15512ULL: goto x86_l_3c98;
	case 15518ULL: goto x86_l_3c9e;
	case 15521ULL: goto x86_l_3ca1;
	case 15527ULL: goto x86_l_3ca7;
	case 15532ULL: goto x86_l_3cac;
	case 15540ULL: goto x86_l_3cb4;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15552ULL: goto x86_l_3cc0;
	case 15557ULL: goto x86_l_3cc5;
	case 15562ULL: goto x86_l_3cca;
	case 15564ULL: goto x86_l_3ccc;
	case 15566ULL: goto x86_l_3cce;
	case 15572ULL: goto x86_l_3cd4;
	case 15577ULL: goto x86_l_3cd9;
	case 15585ULL: goto x86_l_3ce1;
	case 15588ULL: goto x86_l_3ce4;
	case 15594ULL: goto x86_l_3cea;
	case 15600ULL: goto x86_l_3cf0;
	case 15605ULL: goto x86_l_3cf5;
	case 15613ULL: goto x86_l_3cfd;
	case 15615ULL: goto x86_l_3cff;
	case 15620ULL: goto x86_l_3d04;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15635ULL: goto x86_l_3d13;
	case 15637ULL: goto x86_l_3d15;
	case 15639ULL: goto x86_l_3d17;
	case 15645ULL: goto x86_l_3d1d;
	case 15650ULL: goto x86_l_3d22;
	case 15658ULL: goto x86_l_3d2a;
	case 15661ULL: goto x86_l_3d2d;
	case 15667ULL: goto x86_l_3d33;
	case 15673ULL: goto x86_l_3d39;
	case 15678ULL: goto x86_l_3d3e;
	case 15686ULL: goto x86_l_3d46;
	case 15692ULL: goto x86_l_3d4c;
	case 15697ULL: goto x86_l_3d51;
	case 15702ULL: goto x86_l_3d56;
	case 15707ULL: goto x86_l_3d5b;
	case 15712ULL: goto x86_l_3d60;
	case 15714ULL: goto x86_l_3d62;
	case 15719ULL: goto x86_l_3d67;
	case 15721ULL: goto x86_l_3d69;
	case 15727ULL: goto x86_l_3d6f;
	case 15732ULL: goto x86_l_3d74;
	case 15737ULL: goto x86_l_3d79;
	case 15742ULL: goto x86_l_3d7e;
	case 15747ULL: goto x86_l_3d83;
	case 15752ULL: goto x86_l_3d88;
	case 15757ULL: goto x86_l_3d8d;
	case 15762ULL: goto x86_l_3d92;
	case 15767ULL: goto x86_l_3d97;
	case 15772ULL: goto x86_l_3d9c;
	case 15774ULL: goto x86_l_3d9e;
	case 15779ULL: goto x86_l_3da3;
	case 15784ULL: goto x86_l_3da8;
	case 15789ULL: goto x86_l_3dad;
	case 15796ULL: goto x86_l_3db4;
	case 15803ULL: goto x86_l_3dbb;
	case 15810ULL: goto x86_l_3dc2;
	case 15815ULL: goto x86_l_3dc7;
	case 15818ULL: goto x86_l_3dca;
	case 15823ULL: goto x86_l_3dcf;
	case 15828ULL: goto x86_l_3dd4;
	case 15830ULL: goto x86_l_3dd6;
	case 15832ULL: goto x86_l_3dd8;
	case 15835ULL: goto x86_l_3ddb;
	case 15841ULL: goto x86_l_3de1;
	case 15843ULL: goto x86_l_3de3;
	case 15848ULL: goto x86_l_3de8;
	case 15853ULL: goto x86_l_3ded;
	case 15855ULL: goto x86_l_3def;
	case 15860ULL: goto x86_l_3df4;
	case 15865ULL: goto x86_l_3df9;
	case 15870ULL: goto x86_l_3dfe;
	case 15872ULL: goto x86_l_3e00;
	case 15877ULL: goto x86_l_3e05;
	case 15882ULL: goto x86_l_3e0a;
	case 15887ULL: goto x86_l_3e0f;
	case 15890ULL: goto x86_l_3e12;
	case 15893ULL: goto x86_l_3e15;
	case 15898ULL: goto x86_l_3e1a;
	case 15903ULL: goto x86_l_3e1f;
	case 15908ULL: goto x86_l_3e24;
	case 15911ULL: goto x86_l_3e27;
	case 15913ULL: goto x86_l_3e29;
	case 15916ULL: goto x86_l_3e2c;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15947ULL: goto x86_l_3e4b;
	case 15952ULL: goto x86_l_3e50;
	case 15959ULL: goto x86_l_3e57;
	case 15964ULL: goto x86_l_3e5c;
	case 15966ULL: goto x86_l_3e5e;
	case 15969ULL: goto x86_l_3e61;
	case 15975ULL: goto x86_l_3e67;
	case 15981ULL: goto x86_l_3e6d;
	case 15984ULL: goto x86_l_3e70;
	case 15991ULL: goto x86_l_3e77;
	case 15996ULL: goto x86_l_3e7c;
	case 15999ULL: goto x86_l_3e7f;
	case 16002ULL: goto x86_l_3e82;
	case 16005ULL: goto x86_l_3e85;
	case 16007ULL: goto x86_l_3e87;
	case 16010ULL: goto x86_l_3e8a;
	case 16015ULL: goto x86_l_3e8f;
	case 16017ULL: goto x86_l_3e91;
	case 16022ULL: goto x86_l_3e96;
	case 16025ULL: goto x86_l_3e99;
	case 16028ULL: goto x86_l_3e9c;
	case 16034ULL: goto x86_l_3ea2;
	case 16039ULL: goto x86_l_3ea7;
	case 16044ULL: goto x86_l_3eac;
	case 16046ULL: goto x86_l_3eae;
	case 16051ULL: goto x86_l_3eb3;
	case 16059ULL: goto x86_l_3ebb;
	case 16064ULL: goto x86_l_3ec0;
	case 16071ULL: goto x86_l_3ec7;
	case 16076ULL: goto x86_l_3ecc;
	case 16078ULL: goto x86_l_3ece;
	case 16081ULL: goto x86_l_3ed1;
	case 16083ULL: goto x86_l_3ed3;
	case 16089ULL: goto x86_l_3ed9;
	case 16092ULL: goto x86_l_3edc;
	case 16099ULL: goto x86_l_3ee3;
	case 16104ULL: goto x86_l_3ee8;
	case 16107ULL: goto x86_l_3eeb;
	case 16110ULL: goto x86_l_3eee;
	case 16113ULL: goto x86_l_3ef1;
	case 16115ULL: goto x86_l_3ef3;
	case 16118ULL: goto x86_l_3ef6;
	case 16123ULL: goto x86_l_3efb;
	case 16126ULL: goto x86_l_3efe;
	case 16129ULL: goto x86_l_3f01;
	case 16132ULL: goto x86_l_3f04;
	case 16134ULL: goto x86_l_3f06;
	case 16137ULL: goto x86_l_3f09;
	case 16139ULL: goto x86_l_3f0b;
	case 16142ULL: goto x86_l_3f0e;
	case 16144ULL: goto x86_l_3f10;
	case 16147ULL: goto x86_l_3f13;
	case 16151ULL: goto x86_l_3f17;
	case 16156ULL: goto x86_l_3f1c;
	case 16159ULL: goto x86_l_3f1f;
	case 16161ULL: goto x86_l_3f21;
	case 16164ULL: goto x86_l_3f24;
	case 16169ULL: goto x86_l_3f29;
	case 16171ULL: goto x86_l_3f2b;
	case 16174ULL: goto x86_l_3f2e;
	case 16176ULL: goto x86_l_3f30;
	case 16181ULL: goto x86_l_3f35;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3827:
	/* 0x3827: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_382c:
	/* 0x382c: movzx  eax,WORD PTR [rdi+0x114] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 276ULL);
x86_l_3833:
	/* 0x3833: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3835:
	/* 0x3835: je     3ac4 <generic_sleepable_preload+0x3ac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac4;
	}
x86_l_383b:
	/* 0x383b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_383e:
	/* 0x383e: je     3863 <generic_sleepable_preload+0x3863> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3863;
	}
x86_l_3840:
	/* 0x3840: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3845:
	/* 0x3845: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_384a:
	/* 0x384a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_384f:
	/* 0x384f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3854:
	/* 0x3854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3856:
	/* 0x3856: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_385b:
	/* 0x385b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_385d:
	/* 0x385d: js     3d79 <generic_sleepable_preload+0x3d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d79;
	}
x86_l_3863:
	/* 0x3863: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_386b:
	/* 0x386b: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3871:
	/* 0x3871: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3877:
	/* 0x3877: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_387c:
	/* 0x387c: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3884:
	/* 0x3884: je     38a9 <generic_sleepable_preload+0x38a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a9;
	}
x86_l_3886:
	/* 0x3886: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_388b:
	/* 0x388b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3890:
	/* 0x3890: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3895:
	/* 0x3895: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_389a:
	/* 0x389a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389c:
	/* 0x389c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38a1:
	/* 0x38a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a3:
	/* 0x38a3: js     3d8d <generic_sleepable_preload+0x3d8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d8d;
	}
x86_l_38a9:
	/* 0x38a9: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_38b1:
	/* 0x38b1: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_38b7:
	/* 0x38b7: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_38bd:
	/* 0x38bd: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_38c2:
	/* 0x38c2: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_38ca:
	/* 0x38ca: je     38ef <generic_sleepable_preload+0x38ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ef;
	}
x86_l_38cc:
	/* 0x38cc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_38d1:
	/* 0x38d1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38d6:
	/* 0x38d6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38db:
	/* 0x38db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38e0:
	/* 0x38e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e2:
	/* 0x38e2: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38e7:
	/* 0x38e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e9:
	/* 0x38e9: js     3d9e <generic_sleepable_preload+0x3d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d9e;
	}
x86_l_38ef:
	/* 0x38ef: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_38f7:
	/* 0x38f7: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_38fd:
	/* 0x38fd: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3903:
	/* 0x3903: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3908:
	/* 0x3908: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3910:
	/* 0x3910: je     3935 <generic_sleepable_preload+0x3935> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3935;
	}
x86_l_3912:
	/* 0x3912: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3917:
	/* 0x3917: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_391c:
	/* 0x391c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3921:
	/* 0x3921: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3926:
	/* 0x3926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3928:
	/* 0x3928: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_392d:
	/* 0x392d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_392f:
	/* 0x392f: js     3def <generic_sleepable_preload+0x3def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3def;
	}
x86_l_3935:
	/* 0x3935: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_393d:
	/* 0x393d: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3943:
	/* 0x3943: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3949:
	/* 0x3949: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_394e:
	/* 0x394e: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3956:
	/* 0x3956: je     397b <generic_sleepable_preload+0x397b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_397b;
	}
x86_l_3958:
	/* 0x3958: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_395d:
	/* 0x395d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3962:
	/* 0x3962: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3967:
	/* 0x3967: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_396c:
	/* 0x396c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396e:
	/* 0x396e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3973:
	/* 0x3973: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3975:
	/* 0x3975: js     3e00 <generic_sleepable_preload+0x3e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e00;
	}
x86_l_397b:
	/* 0x397b: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3983:
	/* 0x3983: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3989:
	/* 0x3989: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_398f:
	/* 0x398f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3994:
	/* 0x3994: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_399c:
	/* 0x399c: je     39c1 <generic_sleepable_preload+0x39c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c1;
	}
x86_l_399e:
	/* 0x399e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39a3:
	/* 0x39a3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39a8:
	/* 0x39a8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39ad:
	/* 0x39ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39b2:
	/* 0x39b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b4:
	/* 0x39b4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39b9:
	/* 0x39b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39bb:
	/* 0x39bb: js     3e91 <generic_sleepable_preload+0x3e91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e91;
	}
x86_l_39c1:
	/* 0x39c1: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_39c9:
	/* 0x39c9: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_39cf:
	/* 0x39cf: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_39d5:
	/* 0x39d5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_39da:
	/* 0x39da: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_39e2:
	/* 0x39e2: je     3a02 <generic_sleepable_preload+0x3a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a02;
	}
x86_l_39e4:
	/* 0x39e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_39e9:
	/* 0x39e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39ee:
	/* 0x39ee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39f3:
	/* 0x39f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39f8:
	/* 0x39f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39fa:
	/* 0x39fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39fc:
	/* 0x39fc: js     5dd3 <generic_sleepable_preload+0x5dd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24019ULL;
	}
x86_l_3a02:
	/* 0x3a02: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a07:
	/* 0x3a07: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3a0f:
	/* 0x3a0f: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3a15:
	/* 0x3a15: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3a1b:
	/* 0x3a1b: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a20:
	/* 0x3a20: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3a28:
	/* 0x3a28: je     3a48 <generic_sleepable_preload+0x3a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a48;
	}
x86_l_3a2a:
	/* 0x3a2a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a2f:
	/* 0x3a2f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a34:
	/* 0x3a34: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a39:
	/* 0x3a39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a3e:
	/* 0x3a3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a40:
	/* 0x3a40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a42:
	/* 0x3a42: js     5f4d <generic_sleepable_preload+0x5f4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24397ULL;
	}
x86_l_3a48:
	/* 0x3a48: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a4d:
	/* 0x3a4d: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3a55:
	/* 0x3a55: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3a5b:
	/* 0x3a5b: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3a61:
	/* 0x3a61: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a66:
	/* 0x3a66: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3a6e:
	/* 0x3a6e: je     3a8e <generic_sleepable_preload+0x3a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a8e;
	}
x86_l_3a70:
	/* 0x3a70: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3a75:
	/* 0x3a75: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a7a:
	/* 0x3a7a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a7f:
	/* 0x3a7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a84:
	/* 0x3a84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a86:
	/* 0x3a86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a88:
	/* 0x3a88: js     604b <generic_sleepable_preload+0x604b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24651ULL;
	}
x86_l_3a8e:
	/* 0x3a8e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a93:
	/* 0x3a93: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3a9b:
	/* 0x3a9b: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3aa1:
	/* 0x3aa1: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3aa7:
	/* 0x3aa7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3aac:
	/* 0x3aac: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3ab4:
	/* 0x3ab4: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3aba:
	/* 0x3aba: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3abf:
	/* 0x3abf: jmp    3d51 <generic_sleepable_preload+0x3d51> */
	goto x86_l_3d51;
x86_l_3ac4:
	/* 0x3ac4: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3ac7:
	/* 0x3ac7: je     3aec <generic_sleepable_preload+0x3aec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aec;
	}
x86_l_3ac9:
	/* 0x3ac9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ace:
	/* 0x3ace: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ad3:
	/* 0x3ad3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ad8:
	/* 0x3ad8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3add:
	/* 0x3add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3adf:
	/* 0x3adf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ae4:
	/* 0x3ae4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ae6:
	/* 0x3ae6: js     3d79 <generic_sleepable_preload+0x3d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d79;
	}
x86_l_3aec:
	/* 0x3aec: cmp    WORD PTR [rdi+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_3af4:
	/* 0x3af4: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3afa:
	/* 0x3afa: mov    eax,DWORD PTR [rdi+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_3b00:
	/* 0x3b00: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b05:
	/* 0x3b05: cmp    WORD PTR [rdi+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_3b0d:
	/* 0x3b0d: je     3b32 <generic_sleepable_preload+0x3b32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b32;
	}
x86_l_3b0f:
	/* 0x3b0f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b14:
	/* 0x3b14: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b19:
	/* 0x3b19: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b1e:
	/* 0x3b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b23:
	/* 0x3b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b25:
	/* 0x3b25: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b2a:
	/* 0x3b2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b2c:
	/* 0x3b2c: js     3d8d <generic_sleepable_preload+0x3d8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d8d;
	}
x86_l_3b32:
	/* 0x3b32: cmp    WORD PTR [rdi+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_3b3a:
	/* 0x3b3a: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3b40:
	/* 0x3b40: mov    eax,DWORD PTR [rdi+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3b46:
	/* 0x3b46: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b4b:
	/* 0x3b4b: cmp    WORD PTR [rdi+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_3b53:
	/* 0x3b53: je     3b78 <generic_sleepable_preload+0x3b78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b78;
	}
x86_l_3b55:
	/* 0x3b55: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3b5a:
	/* 0x3b5a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b5f:
	/* 0x3b5f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b64:
	/* 0x3b64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b69:
	/* 0x3b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6b:
	/* 0x3b6b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b70:
	/* 0x3b70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b72:
	/* 0x3b72: js     3d9e <generic_sleepable_preload+0x3d9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3d9e;
	}
x86_l_3b78:
	/* 0x3b78: cmp    WORD PTR [rdi+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_3b80:
	/* 0x3b80: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3b86:
	/* 0x3b86: mov    eax,DWORD PTR [rdi+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_3b8c:
	/* 0x3b8c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3b91:
	/* 0x3b91: cmp    WORD PTR [rdi+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_3b99:
	/* 0x3b99: je     3bbe <generic_sleepable_preload+0x3bbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bbe;
	}
x86_l_3b9b:
	/* 0x3b9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3ba0:
	/* 0x3ba0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ba5:
	/* 0x3ba5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3baa:
	/* 0x3baa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3baf:
	/* 0x3baf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bb1:
	/* 0x3bb1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bb6:
	/* 0x3bb6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bb8:
	/* 0x3bb8: js     3def <generic_sleepable_preload+0x3def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3def;
	}
x86_l_3bbe:
	/* 0x3bbe: cmp    WORD PTR [rdi+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_3bc6:
	/* 0x3bc6: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3bcc:
	/* 0x3bcc: mov    eax,DWORD PTR [rdi+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_3bd2:
	/* 0x3bd2: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3bd7:
	/* 0x3bd7: cmp    WORD PTR [rdi+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_3bdf:
	/* 0x3bdf: je     3c04 <generic_sleepable_preload+0x3c04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c04;
	}
x86_l_3be1:
	/* 0x3be1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3be6:
	/* 0x3be6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3beb:
	/* 0x3beb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bf0:
	/* 0x3bf0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3bf5:
	/* 0x3bf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bf7:
	/* 0x3bf7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bfc:
	/* 0x3bfc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bfe:
	/* 0x3bfe: js     3e00 <generic_sleepable_preload+0x3e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e00;
	}
x86_l_3c04:
	/* 0x3c04: cmp    WORD PTR [rdi+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_3c0c:
	/* 0x3c0c: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3c12:
	/* 0x3c12: mov    eax,DWORD PTR [rdi+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_3c18:
	/* 0x3c18: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c1d:
	/* 0x3c1d: cmp    WORD PTR [rdi+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_3c25:
	/* 0x3c25: je     3c4a <generic_sleepable_preload+0x3c4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c4a;
	}
x86_l_3c27:
	/* 0x3c27: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c2c:
	/* 0x3c2c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c31:
	/* 0x3c31: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c36:
	/* 0x3c36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c3b:
	/* 0x3c3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3d:
	/* 0x3c3d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c42:
	/* 0x3c42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c44:
	/* 0x3c44: js     3e91 <generic_sleepable_preload+0x3e91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e91;
	}
x86_l_3c4a:
	/* 0x3c4a: cmp    WORD PTR [rdi+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_3c52:
	/* 0x3c52: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3c58:
	/* 0x3c58: mov    eax,DWORD PTR [rdi+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3c5e:
	/* 0x3c5e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3c63:
	/* 0x3c63: cmp    WORD PTR [rdi+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_3c6b:
	/* 0x3c6b: je     3c8b <generic_sleepable_preload+0x3c8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c8b;
	}
x86_l_3c6d:
	/* 0x3c6d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3c72:
	/* 0x3c72: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c77:
	/* 0x3c77: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c7c:
	/* 0x3c7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c81:
	/* 0x3c81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c83:
	/* 0x3c83: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c85:
	/* 0x3c85: js     5dd3 <generic_sleepable_preload+0x5dd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24019ULL;
	}
x86_l_3c8b:
	/* 0x3c8b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c90:
	/* 0x3c90: cmp    WORD PTR [rdi+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_3c98:
	/* 0x3c98: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3c9e:
	/* 0x3c9e: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3ca1:
	/* 0x3ca1: mov    eax,DWORD PTR [rdi+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_3ca7:
	/* 0x3ca7: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3cac:
	/* 0x3cac: cmp    WORD PTR [rdi+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_3cb4:
	/* 0x3cb4: je     3cd4 <generic_sleepable_preload+0x3cd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cd4;
	}
x86_l_3cb6:
	/* 0x3cb6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3cbb:
	/* 0x3cbb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cc0:
	/* 0x3cc0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cc5:
	/* 0x3cc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cca:
	/* 0x3cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ccc:
	/* 0x3ccc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cce:
	/* 0x3cce: js     5fd8 <generic_sleepable_preload+0x5fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24536ULL;
	}
x86_l_3cd4:
	/* 0x3cd4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3cd9:
	/* 0x3cd9: cmp    WORD PTR [rdi+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_3ce1:
	/* 0x3ce1: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3ce4:
	/* 0x3ce4: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3cea:
	/* 0x3cea: mov    eax,DWORD PTR [rdi+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3cf0:
	/* 0x3cf0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3cf5:
	/* 0x3cf5: cmp    WORD PTR [rdi+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_3cfd:
	/* 0x3cfd: je     3d1d <generic_sleepable_preload+0x3d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d1d;
	}
x86_l_3cff:
	/* 0x3cff: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d04:
	/* 0x3d04: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d09:
	/* 0x3d09: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d0e:
	/* 0x3d0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d13:
	/* 0x3d13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d15:
	/* 0x3d15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d17:
	/* 0x3d17: js     60dc <generic_sleepable_preload+0x60dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24796ULL;
	}
x86_l_3d1d:
	/* 0x3d1d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d22:
	/* 0x3d22: cmp    WORD PTR [rdi+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_3d2a:
	/* 0x3d2a: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3d2d:
	/* 0x3d2d: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3d33:
	/* 0x3d33: mov    eax,DWORD PTR [rdi+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_3d39:
	/* 0x3d39: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d3e:
	/* 0x3d3e: cmp    WORD PTR [rdi+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_3d46:
	/* 0x3d46: je     3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e99;
	}
x86_l_3d4c:
	/* 0x3d4c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3d51:
	/* 0x3d51: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d56:
	/* 0x3d56: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d5b:
	/* 0x3d5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d60:
	/* 0x3d60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d62:
	/* 0x3d62: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d67:
	/* 0x3d67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d69:
	/* 0x3d69: jns    3e99 <generic_sleepable_preload+0x3e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3e99;
	}
x86_l_3d6f:
	/* 0x3d6f: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3d74:
	/* 0x3d74: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3d79:
	/* 0x3d79: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_3d7e:
	/* 0x3d7e: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3d83:
	/* 0x3d83: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3d88:
	/* 0x3d88: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	goto x86_l_3e0f;
x86_l_3d8d:
	/* 0x3d8d: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3d92:
	/* 0x3d92: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3d97:
	/* 0x3d97: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3d9c:
	/* 0x3d9c: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	goto x86_l_3e0f;
x86_l_3d9e:
	/* 0x3d9e: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_3da3:
	/* 0x3da3: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3da8:
	/* 0x3da8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_3dad:
	/* 0x3dad: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_3db4:
	/* 0x3db4: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_3dbb:
	/* 0x3dbb: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_3dc2:
	/* 0x3dc2: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_3dc7:
	/* 0x3dc7: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dca:
	/* 0x3dca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3dcf:
	/* 0x3dcf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3dd4:
	/* 0x3dd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dd6:
	/* 0x3dd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dd8:
	/* 0x3dd8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3ddb:
	/* 0x3ddb: je     3187 <generic_sleepable_preload+0x3187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12679ULL;
	}
x86_l_3de1:
	/* 0x3de1: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3de3:
	/* 0x3de3: jmp    3200 <generic_sleepable_preload+0x3200> */
	return 12800ULL;
x86_l_3de8:
	/* 0x3de8: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3ded:
	/* 0x3ded: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	goto x86_l_3e0f;
x86_l_3def:
	/* 0x3def: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3df4:
	/* 0x3df4: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3df9:
	/* 0x3df9: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3dfe:
	/* 0x3dfe: jmp    3e0f <generic_sleepable_preload+0x3e0f> */
	goto x86_l_3e0f;
x86_l_3e00:
	/* 0x3e00: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3e05:
	/* 0x3e05: jmp    3e96 <generic_sleepable_preload+0x3e96> */
	goto x86_l_3e96;
x86_l_3e0a:
	/* 0x3e0a: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3e0f:
	/* 0x3e0f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e12:
	/* 0x3e12: mov    ebx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e15:
	/* 0x3e15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e1a:
	/* 0x3e1a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e1f:
	/* 0x3e1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e24:
	/* 0x3e24: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3e27:
	/* 0x3e27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e29:
	/* 0x3e29: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3e2c:
	/* 0x3e2c: jne    3f3a <generic_sleepable_preload+0x3f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16186ULL;
	}
x86_l_3e32:
	/* 0x3e32: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e37:
	/* 0x3e37: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3e3c:
	/* 0x3e3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e3e:
	/* 0x3e3e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e43:
	/* 0x3e43: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3e4b:
	/* 0x3e4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e50:
	/* 0x3e50: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3e57:
	/* 0x3e57: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e5c:
	/* 0x3e5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e5e:
	/* 0x3e5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e61:
	/* 0x3e61: je     3f3a <generic_sleepable_preload+0x3f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16186ULL;
	}
x86_l_3e67:
	/* 0x3e67: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3e6d:
	/* 0x3e6d: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3e70:
	/* 0x3e70: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3e77:
	/* 0x3e77: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e7c:
	/* 0x3e7c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3e7f:
	/* 0x3e7f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3e82:
	/* 0x3e82: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3e85:
	/* 0x3e85: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e87:
	/* 0x3e87: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3e8a:
	/* 0x3e8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e8f:
	/* 0x3e8f: jmp    3efb <generic_sleepable_preload+0x3efb> */
	goto x86_l_3efb;
x86_l_3e91:
	/* 0x3e91: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3e96:
	/* 0x3e96: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e99:
	/* 0x3e99: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_3e9c:
	/* 0x3e9c: jne    3f3f <generic_sleepable_preload+0x3f3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 16191ULL;
	}
x86_l_3ea2:
	/* 0x3ea2: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea7:
	/* 0x3ea7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3eac:
	/* 0x3eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eae:
	/* 0x3eae: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3eb3:
	/* 0x3eb3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ebb:
	/* 0x3ebb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ec0:
	/* 0x3ec0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3ec7:
	/* 0x3ec7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ecc:
	/* 0x3ecc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ece:
	/* 0x3ece: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ed1:
	/* 0x3ed1: je     3f3a <generic_sleepable_preload+0x3f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16186ULL;
	}
x86_l_3ed3:
	/* 0x3ed3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_3ed9:
	/* 0x3ed9: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_3edc:
	/* 0x3edc: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3ee3:
	/* 0x3ee3: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ee8:
	/* 0x3ee8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3eeb:
	/* 0x3eeb: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3eee:
	/* 0x3eee: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3ef1:
	/* 0x3ef1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ef3:
	/* 0x3ef3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3ef6:
	/* 0x3ef6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3efb:
	/* 0x3efb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3efe:
	/* 0x3efe: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_3f01:
	/* 0x3f01: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3f04:
	/* 0x3f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f06:
	/* 0x3f06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f09:
	/* 0x3f09: je     3f3a <generic_sleepable_preload+0x3f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16186ULL;
	}
x86_l_3f0b:
	/* 0x3f0b: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_3f0e:
	/* 0x3f0e: je     3f38 <generic_sleepable_preload+0x3f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16184ULL;
	}
x86_l_3f10:
	/* 0x3f10: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3f13:
	/* 0x3f13: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3f17:
	/* 0x3f17: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f1c:
	/* 0x3f1c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3f1f:
	/* 0x3f1f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f21:
	/* 0x3f21: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3f24:
	/* 0x3f24: call   3f29 <generic_sleepable_preload+0x3f29> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3f29:
	/* 0x3f29: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3f2b:
	/* 0x3f2b: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3f2e:
	/* 0x3f2e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3f30:
	/* 0x3f30: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3f35:
	/* 0x3f35: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
	return 16184ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16184ULL: goto x86_l_3f38;
	case 16186ULL: goto x86_l_3f3a;
	case 16191ULL: goto x86_l_3f3f;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16205ULL: goto x86_l_3f4d;
	case 16207ULL: goto x86_l_3f4f;
	case 16209ULL: goto x86_l_3f51;
	case 16216ULL: goto x86_l_3f58;
	case 16218ULL: goto x86_l_3f5a;
	case 16221ULL: goto x86_l_3f5d;
	case 16226ULL: goto x86_l_3f62;
	case 16232ULL: goto x86_l_3f68;
	case 16235ULL: goto x86_l_3f6b;
	case 16241ULL: goto x86_l_3f71;
	case 16244ULL: goto x86_l_3f74;
	case 16250ULL: goto x86_l_3f7a;
	case 16256ULL: goto x86_l_3f80;
	case 16262ULL: goto x86_l_3f86;
	case 16265ULL: goto x86_l_3f89;
	case 16270ULL: goto x86_l_3f8e;
	case 16275ULL: goto x86_l_3f93;
	case 16280ULL: goto x86_l_3f98;
	case 16282ULL: goto x86_l_3f9a;
	case 16287ULL: goto x86_l_3f9f;
	case 16289ULL: goto x86_l_3fa1;
	case 16295ULL: goto x86_l_3fa7;
	case 16297ULL: goto x86_l_3fa9;
	case 16302ULL: goto x86_l_3fae;
	case 16309ULL: goto x86_l_3fb5;
	case 16316ULL: goto x86_l_3fbc;
	case 16322ULL: goto x86_l_3fc2;
	case 16324ULL: goto x86_l_3fc4;
	case 16327ULL: goto x86_l_3fc7;
	case 16333ULL: goto x86_l_3fcd;
	case 16336ULL: goto x86_l_3fd0;
	case 16342ULL: goto x86_l_3fd6;
	case 16345ULL: goto x86_l_3fd9;
	case 16351ULL: goto x86_l_3fdf;
	case 16359ULL: goto x86_l_3fe7;
	case 16362ULL: goto x86_l_3fea;
	case 16368ULL: goto x86_l_3ff0;
	case 16373ULL: goto x86_l_3ff5;
	case 16376ULL: goto x86_l_3ff8;
	case 16382ULL: goto x86_l_3ffe;
	case 16387ULL: goto x86_l_4003;
	case 16390ULL: goto x86_l_4006;
	case 16396ULL: goto x86_l_400c;
	case 16401ULL: goto x86_l_4011;
	case 16404ULL: goto x86_l_4014;
	case 16410ULL: goto x86_l_401a;
	case 16413ULL: goto x86_l_401d;
	case 16419ULL: goto x86_l_4023;
	case 16425ULL: goto x86_l_4029;
	case 16431ULL: goto x86_l_402f;
	case 16434ULL: goto x86_l_4032;
	case 16439ULL: goto x86_l_4037;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16452ULL: goto x86_l_4044;
	case 16454ULL: goto x86_l_4046;
	case 16456ULL: goto x86_l_4048;
	case 16462ULL: goto x86_l_404e;
	case 16467ULL: goto x86_l_4053;
	case 16472ULL: goto x86_l_4058;
	case 16479ULL: goto x86_l_405f;
	case 16484ULL: goto x86_l_4064;
	case 16487ULL: goto x86_l_4067;
	case 16492ULL: goto x86_l_406c;
	case 16494ULL: goto x86_l_406e;
	case 16497ULL: goto x86_l_4071;
	case 16503ULL: goto x86_l_4077;
	case 16505ULL: goto x86_l_4079;
	case 16511ULL: goto x86_l_407f;
	case 16514ULL: goto x86_l_4082;
	case 16517ULL: goto x86_l_4085;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16531ULL: goto x86_l_4093;
	case 16537ULL: goto x86_l_4099;
	case 16545ULL: goto x86_l_40a1;
	case 16548ULL: goto x86_l_40a4;
	case 16554ULL: goto x86_l_40aa;
	case 16559ULL: goto x86_l_40af;
	case 16562ULL: goto x86_l_40b2;
	case 16568ULL: goto x86_l_40b8;
	case 16573ULL: goto x86_l_40bd;
	case 16576ULL: goto x86_l_40c0;
	case 16582ULL: goto x86_l_40c6;
	case 16590ULL: goto x86_l_40ce;
	case 16593ULL: goto x86_l_40d1;
	case 16599ULL: goto x86_l_40d7;
	case 16604ULL: goto x86_l_40dc;
	case 16607ULL: goto x86_l_40df;
	case 16613ULL: goto x86_l_40e5;
	case 16618ULL: goto x86_l_40ea;
	case 16625ULL: goto x86_l_40f1;
	case 16630ULL: goto x86_l_40f6;
	case 16637ULL: goto x86_l_40fd;
	case 16644ULL: goto x86_l_4104;
	case 16651ULL: goto x86_l_410b;
	case 16656ULL: goto x86_l_4110;
	case 16661ULL: goto x86_l_4115;
	case 16665ULL: goto x86_l_4119;
	case 16667ULL: goto x86_l_411b;
	case 16673ULL: goto x86_l_4121;
	case 16679ULL: goto x86_l_4127;
	case 16682ULL: goto x86_l_412a;
	case 16687ULL: goto x86_l_412f;
	case 16690ULL: goto x86_l_4132;
	case 16695ULL: goto x86_l_4137;
	case 16700ULL: goto x86_l_413c;
	case 16702ULL: goto x86_l_413e;
	case 16704ULL: goto x86_l_4140;
	case 16706ULL: goto x86_l_4142;
	case 16712ULL: goto x86_l_4148;
	case 16718ULL: goto x86_l_414e;
	case 16721ULL: goto x86_l_4151;
	case 16726ULL: goto x86_l_4156;
	case 16731ULL: goto x86_l_415b;
	case 16736ULL: goto x86_l_4160;
	case 16738ULL: goto x86_l_4162;
	case 16740ULL: goto x86_l_4164;
	case 16746ULL: goto x86_l_416a;
	case 16748ULL: goto x86_l_416c;
	case 16751ULL: goto x86_l_416f;
	case 16756ULL: goto x86_l_4174;
	case 16758ULL: goto x86_l_4176;
	case 16761ULL: goto x86_l_4179;
	case 16769ULL: goto x86_l_4181;
	case 16775ULL: goto x86_l_4187;
	case 16782ULL: goto x86_l_418e;
	case 16785ULL: goto x86_l_4191;
	case 16791ULL: goto x86_l_4197;
	case 16794ULL: goto x86_l_419a;
	case 16799ULL: goto x86_l_419f;
	case 16806ULL: goto x86_l_41a6;
	case 16808ULL: goto x86_l_41a8;
	case 16814ULL: goto x86_l_41ae;
	case 16817ULL: goto x86_l_41b1;
	case 16819ULL: goto x86_l_41b3;
	case 16824ULL: goto x86_l_41b8;
	case 16829ULL: goto x86_l_41bd;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16841ULL: goto x86_l_41c9;
	case 16846ULL: goto x86_l_41ce;
	case 16848ULL: goto x86_l_41d0;
	case 16854ULL: goto x86_l_41d6;
	case 16862ULL: goto x86_l_41de;
	case 16868ULL: goto x86_l_41e4;
	case 16874ULL: goto x86_l_41ea;
	case 16879ULL: goto x86_l_41ef;
	case 16887ULL: goto x86_l_41f7;
	case 16889ULL: goto x86_l_41f9;
	case 16894ULL: goto x86_l_41fe;
	case 16899ULL: goto x86_l_4203;
	case 16904ULL: goto x86_l_4208;
	case 16909ULL: goto x86_l_420d;
	case 16911ULL: goto x86_l_420f;
	case 16916ULL: goto x86_l_4214;
	case 16918ULL: goto x86_l_4216;
	case 16924ULL: goto x86_l_421c;
	case 16932ULL: goto x86_l_4224;
	case 16938ULL: goto x86_l_422a;
	case 16944ULL: goto x86_l_4230;
	case 16949ULL: goto x86_l_4235;
	case 16957ULL: goto x86_l_423d;
	case 16959ULL: goto x86_l_423f;
	case 16964ULL: goto x86_l_4244;
	case 16969ULL: goto x86_l_4249;
	case 16974ULL: goto x86_l_424e;
	case 16979ULL: goto x86_l_4253;
	case 16981ULL: goto x86_l_4255;
	case 16986ULL: goto x86_l_425a;
	case 16988ULL: goto x86_l_425c;
	case 16994ULL: goto x86_l_4262;
	case 17002ULL: goto x86_l_426a;
	case 17008ULL: goto x86_l_4270;
	case 17014ULL: goto x86_l_4276;
	case 17019ULL: goto x86_l_427b;
	case 17027ULL: goto x86_l_4283;
	case 17029ULL: goto x86_l_4285;
	case 17034ULL: goto x86_l_428a;
	case 17039ULL: goto x86_l_428f;
	case 17044ULL: goto x86_l_4294;
	case 17049ULL: goto x86_l_4299;
	case 17051ULL: goto x86_l_429b;
	case 17056ULL: goto x86_l_42a0;
	case 17058ULL: goto x86_l_42a2;
	case 17064ULL: goto x86_l_42a8;
	case 17072ULL: goto x86_l_42b0;
	case 17078ULL: goto x86_l_42b6;
	case 17084ULL: goto x86_l_42bc;
	case 17089ULL: goto x86_l_42c1;
	case 17097ULL: goto x86_l_42c9;
	case 17099ULL: goto x86_l_42cb;
	case 17104ULL: goto x86_l_42d0;
	case 17109ULL: goto x86_l_42d5;
	case 17114ULL: goto x86_l_42da;
	case 17119ULL: goto x86_l_42df;
	case 17121ULL: goto x86_l_42e1;
	case 17126ULL: goto x86_l_42e6;
	case 17128ULL: goto x86_l_42e8;
	case 17134ULL: goto x86_l_42ee;
	case 17142ULL: goto x86_l_42f6;
	case 17148ULL: goto x86_l_42fc;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17167ULL: goto x86_l_430f;
	case 17169ULL: goto x86_l_4311;
	case 17174ULL: goto x86_l_4316;
	case 17179ULL: goto x86_l_431b;
	case 17184ULL: goto x86_l_4320;
	case 17189ULL: goto x86_l_4325;
	case 17191ULL: goto x86_l_4327;
	case 17196ULL: goto x86_l_432c;
	case 17198ULL: goto x86_l_432e;
	case 17204ULL: goto x86_l_4334;
	case 17212ULL: goto x86_l_433c;
	case 17218ULL: goto x86_l_4342;
	case 17224ULL: goto x86_l_4348;
	case 17229ULL: goto x86_l_434d;
	case 17237ULL: goto x86_l_4355;
	case 17239ULL: goto x86_l_4357;
	case 17244ULL: goto x86_l_435c;
	case 17249ULL: goto x86_l_4361;
	case 17254ULL: goto x86_l_4366;
	case 17259ULL: goto x86_l_436b;
	case 17261ULL: goto x86_l_436d;
	case 17263ULL: goto x86_l_436f;
	case 17269ULL: goto x86_l_4375;
	case 17274ULL: goto x86_l_437a;
	case 17282ULL: goto x86_l_4382;
	case 17288ULL: goto x86_l_4388;
	case 17294ULL: goto x86_l_438e;
	case 17299ULL: goto x86_l_4393;
	case 17307ULL: goto x86_l_439b;
	case 17309ULL: goto x86_l_439d;
	case 17314ULL: goto x86_l_43a2;
	case 17319ULL: goto x86_l_43a7;
	case 17324ULL: goto x86_l_43ac;
	case 17329ULL: goto x86_l_43b1;
	case 17331ULL: goto x86_l_43b3;
	case 17333ULL: goto x86_l_43b5;
	case 17339ULL: goto x86_l_43bb;
	case 17344ULL: goto x86_l_43c0;
	case 17352ULL: goto x86_l_43c8;
	case 17358ULL: goto x86_l_43ce;
	case 17364ULL: goto x86_l_43d4;
	case 17369ULL: goto x86_l_43d9;
	case 17377ULL: goto x86_l_43e1;
	case 17379ULL: goto x86_l_43e3;
	case 17384ULL: goto x86_l_43e8;
	case 17389ULL: goto x86_l_43ed;
	case 17394ULL: goto x86_l_43f2;
	case 17399ULL: goto x86_l_43f7;
	case 17401ULL: goto x86_l_43f9;
	case 17403ULL: goto x86_l_43fb;
	case 17409ULL: goto x86_l_4401;
	case 17414ULL: goto x86_l_4406;
	case 17422ULL: goto x86_l_440e;
	case 17428ULL: goto x86_l_4414;
	case 17434ULL: goto x86_l_441a;
	case 17439ULL: goto x86_l_441f;
	case 17447ULL: goto x86_l_4427;
	case 17453ULL: goto x86_l_442d;
	case 17458ULL: goto x86_l_4432;
	case 17463ULL: goto x86_l_4437;
	case 17466ULL: goto x86_l_443a;
	case 17468ULL: goto x86_l_443c;
	case 17473ULL: goto x86_l_4441;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17490ULL: goto x86_l_4452;
	case 17495ULL: goto x86_l_4457;
	case 17497ULL: goto x86_l_4459;
	case 17503ULL: goto x86_l_445f;
	case 17511ULL: goto x86_l_4467;
	case 17517ULL: goto x86_l_446d;
	case 17523ULL: goto x86_l_4473;
	case 17528ULL: goto x86_l_4478;
	case 17536ULL: goto x86_l_4480;
	case 17538ULL: goto x86_l_4482;
	case 17543ULL: goto x86_l_4487;
	case 17548ULL: goto x86_l_448c;
	case 17553ULL: goto x86_l_4491;
	case 17558ULL: goto x86_l_4496;
	case 17560ULL: goto x86_l_4498;
	case 17565ULL: goto x86_l_449d;
	case 17567ULL: goto x86_l_449f;
	case 17573ULL: goto x86_l_44a5;
	case 17581ULL: goto x86_l_44ad;
	case 17587ULL: goto x86_l_44b3;
	case 17593ULL: goto x86_l_44b9;
	case 17598ULL: goto x86_l_44be;
	case 17606ULL: goto x86_l_44c6;
	case 17608ULL: goto x86_l_44c8;
	case 17613ULL: goto x86_l_44cd;
	case 17618ULL: goto x86_l_44d2;
	case 17623ULL: goto x86_l_44d7;
	case 17628ULL: goto x86_l_44dc;
	case 17630ULL: goto x86_l_44de;
	case 17635ULL: goto x86_l_44e3;
	case 17637ULL: goto x86_l_44e5;
	case 17643ULL: goto x86_l_44eb;
	case 17651ULL: goto x86_l_44f3;
	case 17657ULL: goto x86_l_44f9;
	case 17663ULL: goto x86_l_44ff;
	case 17668ULL: goto x86_l_4504;
	case 17676ULL: goto x86_l_450c;
	case 17678ULL: goto x86_l_450e;
	case 17683ULL: goto x86_l_4513;
	case 17688ULL: goto x86_l_4518;
	case 17693ULL: goto x86_l_451d;
	case 17698ULL: goto x86_l_4522;
	case 17700ULL: goto x86_l_4524;
	case 17705ULL: goto x86_l_4529;
	case 17707ULL: goto x86_l_452b;
	case 17713ULL: goto x86_l_4531;
	case 17721ULL: goto x86_l_4539;
	case 17727ULL: goto x86_l_453f;
	case 17733ULL: goto x86_l_4545;
	case 17738ULL: goto x86_l_454a;
	case 17746ULL: goto x86_l_4552;
	case 17748ULL: goto x86_l_4554;
	case 17753ULL: goto x86_l_4559;
	case 17758ULL: goto x86_l_455e;
	case 17763ULL: goto x86_l_4563;
	case 17768ULL: goto x86_l_4568;
	case 17770ULL: goto x86_l_456a;
	case 17775ULL: goto x86_l_456f;
	case 17777ULL: goto x86_l_4571;
	case 17783ULL: goto x86_l_4577;
	case 17791ULL: goto x86_l_457f;
	case 17797ULL: goto x86_l_4585;
	case 17803ULL: goto x86_l_458b;
	case 17808ULL: goto x86_l_4590;
	case 17816ULL: goto x86_l_4598;
	case 17818ULL: goto x86_l_459a;
	case 17823ULL: goto x86_l_459f;
	case 17828ULL: goto x86_l_45a4;
	case 17833ULL: goto x86_l_45a9;
	case 17838ULL: goto x86_l_45ae;
	case 17840ULL: goto x86_l_45b0;
	case 17845ULL: goto x86_l_45b5;
	case 17847ULL: goto x86_l_45b7;
	case 17853ULL: goto x86_l_45bd;
	case 17861ULL: goto x86_l_45c5;
	case 17867ULL: goto x86_l_45cb;
	case 17873ULL: goto x86_l_45d1;
	case 17878ULL: goto x86_l_45d6;
	case 17886ULL: goto x86_l_45de;
	case 17888ULL: goto x86_l_45e0;
	case 17893ULL: goto x86_l_45e5;
	case 17898ULL: goto x86_l_45ea;
	case 17903ULL: goto x86_l_45ef;
	case 17908ULL: goto x86_l_45f4;
	case 17910ULL: goto x86_l_45f6;
	case 17912ULL: goto x86_l_45f8;
	case 17918ULL: goto x86_l_45fe;
	case 17923ULL: goto x86_l_4603;
	case 17931ULL: goto x86_l_460b;
	case 17937ULL: goto x86_l_4611;
	case 17940ULL: goto x86_l_4614;
	case 17946ULL: goto x86_l_461a;
	case 17951ULL: goto x86_l_461f;
	case 17959ULL: goto x86_l_4627;
	case 17961ULL: goto x86_l_4629;
	case 17966ULL: goto x86_l_462e;
	case 17971ULL: goto x86_l_4633;
	case 17976ULL: goto x86_l_4638;
	case 17981ULL: goto x86_l_463d;
	case 17983ULL: goto x86_l_463f;
	case 17985ULL: goto x86_l_4641;
	case 17991ULL: goto x86_l_4647;
	case 17996ULL: goto x86_l_464c;
	case 18004ULL: goto x86_l_4654;
	case 18007ULL: goto x86_l_4657;
	case 18013ULL: goto x86_l_465d;
	case 18019ULL: goto x86_l_4663;
	case 18024ULL: goto x86_l_4668;
	case 18032ULL: goto x86_l_4670;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3f38:
	/* 0x3f38: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f3a:
	/* 0x3f3a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f3f:
	/* 0x3f3f: mov    eax,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3f42:
	/* 0x3f42: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_3f47:
	/* 0x3f47: je     4eae <generic_sleepable_preload+0x4eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20142ULL;
	}
x86_l_3f4d:
	/* 0x3f4d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3f4f:
	/* 0x3f4f: js     3fae <generic_sleepable_preload+0x3fae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3fae;
	}
x86_l_3f51:
	/* 0x3f51: movzx  ecx,BYTE PTR [rdi+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_3f58:
	/* 0x3f58: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f5a:
	/* 0x3f5a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3f5d:
	/* 0x3f5d: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f62:
	/* 0x3f62: jg     4011 <generic_sleepable_preload+0x4011> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4011;
	}
x86_l_3f68:
	/* 0x3f68: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3f6b:
	/* 0x3f6b: je     40ea <generic_sleepable_preload+0x40ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40ea;
	}
x86_l_3f71:
	/* 0x3f71: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3f74:
	/* 0x3f74: jne    416f <generic_sleepable_preload+0x416f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_416f;
	}
x86_l_3f7a:
	/* 0x3f7a: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_3f80:
	/* 0x3f80: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f86:
	/* 0x3f86: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f89:
	/* 0x3f89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f8e:
	/* 0x3f8e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f93:
	/* 0x3f93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f98:
	/* 0x3f98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f9a:
	/* 0x3f9a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f9f:
	/* 0x3f9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fa1:
	/* 0x3fa1: je     40f6 <generic_sleepable_preload+0x40f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40f6;
	}
x86_l_3fa7:
	/* 0x3fa7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fa9:
	/* 0x3fa9: jmp    416f <generic_sleepable_preload+0x416f> */
	goto x86_l_416f;
x86_l_3fae:
	/* 0x3fae: movzx  ecx,BYTE PTR [rdi+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_3fb5:
	/* 0x3fb5: movzx  eax,WORD PTR [rdi+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_3fbc:
	/* 0x3fbc: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_3fc2:
	/* 0x3fc2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc4:
	/* 0x3fc4: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3fc7:
	/* 0x3fc7: jle    4064 <generic_sleepable_preload+0x4064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4064;
	}
x86_l_3fcd:
	/* 0x3fcd: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3fd0:
	/* 0x3fd0: jle    4090 <generic_sleepable_preload+0x4090> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4090;
	}
x86_l_3fd6:
	/* 0x3fd6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3fd9:
	/* 0x3fd9: jle    473e <generic_sleepable_preload+0x473e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 18238ULL;
	}
x86_l_3fdf:
	/* 0x3fdf: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3fe7:
	/* 0x3fe7: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3fea:
	/* 0x3fea: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_3ff0:
	/* 0x3ff0: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ff5:
	/* 0x3ff5: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3ff8:
	/* 0x3ff8: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_3ffe:
	/* 0x3ffe: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4003:
	/* 0x4003: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4006:
	/* 0x4006: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_400c:
	/* 0x400c: jmp    4768 <generic_sleepable_preload+0x4768> */
	return 18280ULL;
x86_l_4011:
	/* 0x4011: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4014:
	/* 0x4014: je     411b <generic_sleepable_preload+0x411b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_411b;
	}
x86_l_401a:
	/* 0x401a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_401d:
	/* 0x401d: jne    416f <generic_sleepable_preload+0x416f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_416f;
	}
x86_l_4023:
	/* 0x4023: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_4029:
	/* 0x4029: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_402f:
	/* 0x402f: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4032:
	/* 0x4032: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4037:
	/* 0x4037: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_403a:
	/* 0x403a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_403f:
	/* 0x403f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4044:
	/* 0x4044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4046:
	/* 0x4046: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4048:
	/* 0x4048: jne    416a <generic_sleepable_preload+0x416a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_416a;
	}
x86_l_404e:
	/* 0x404e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4053:
	/* 0x4053: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4058:
	/* 0x4058: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_405f:
	/* 0x405f: jmp    4d39 <generic_sleepable_preload+0x4d39> */
	return 19769ULL;
x86_l_4064:
	/* 0x4064: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4067:
	/* 0x4067: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_406c:
	/* 0x406c: jg     40bd <generic_sleepable_preload+0x40bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_40bd;
	}
x86_l_406e:
	/* 0x406e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4071:
	/* 0x4071: jg     470f <generic_sleepable_preload+0x470f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18191ULL;
	}
x86_l_4077:
	/* 0x4077: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4079:
	/* 0x4079: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_407f:
	/* 0x407f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4082:
	/* 0x4082: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4085:
	/* 0x4085: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_408b:
	/* 0x408b: jmp    4768 <generic_sleepable_preload+0x4768> */
	return 18280ULL;
x86_l_4090:
	/* 0x4090: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_4093:
	/* 0x4093: jg     46f6 <generic_sleepable_preload+0x46f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18166ULL;
	}
x86_l_4099:
	/* 0x4099: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_40a1:
	/* 0x40a1: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40a4:
	/* 0x40a4: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_40aa:
	/* 0x40aa: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40af:
	/* 0x40af: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_40b2:
	/* 0x40b2: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_40b8:
	/* 0x40b8: jmp    4768 <generic_sleepable_preload+0x4768> */
	return 18280ULL;
x86_l_40bd:
	/* 0x40bd: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_40c0:
	/* 0x40c0: jg     4725 <generic_sleepable_preload+0x4725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 18213ULL;
	}
x86_l_40c6:
	/* 0x40c6: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_40ce:
	/* 0x40ce: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_40d1:
	/* 0x40d1: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_40d7:
	/* 0x40d7: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_40dc:
	/* 0x40dc: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_40df:
	/* 0x40df: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18261ULL;
	}
x86_l_40e5:
	/* 0x40e5: jmp    4768 <generic_sleepable_preload+0x4768> */
	return 18280ULL;
x86_l_40ea:
	/* 0x40ea: mov    rax,QWORD PTR [rdi+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_40f1:
	/* 0x40f1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40f6:
	/* 0x40f6: movzx  eax,BYTE PTR [rdi+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_40fd:
	/* 0x40fd: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_4104:
	/* 0x4104: cmp    BYTE PTR [rdi+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_410b:
	/* 0x410b: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_4110:
	/* 0x4110: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_4115:
	/* 0x4115: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_4119:
	/* 0x4119: jmp    416f <generic_sleepable_preload+0x416f> */
	goto x86_l_416f;
x86_l_411b:
	/* 0x411b: mov    edx,DWORD PTR [rdi+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_4121:
	/* 0x4121: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4127:
	/* 0x4127: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_412a:
	/* 0x412a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_412f:
	/* 0x412f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4132:
	/* 0x4132: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4137:
	/* 0x4137: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_413c:
	/* 0x413c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_413e:
	/* 0x413e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4140:
	/* 0x4140: jne    416a <generic_sleepable_preload+0x416a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_416a;
	}
x86_l_4142:
	/* 0x4142: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_4148:
	/* 0x4148: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_414e:
	/* 0x414e: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4151:
	/* 0x4151: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4156:
	/* 0x4156: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_415b:
	/* 0x415b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4160:
	/* 0x4160: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4162:
	/* 0x4162: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4164:
	/* 0x4164: je     4d17 <generic_sleepable_preload+0x4d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19735ULL;
	}
x86_l_416a:
	/* 0x416a: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_416c:
	/* 0x416c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_416f:
	/* 0x416f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4174:
	/* 0x4174: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4176:
	/* 0x4176: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4179:
	/* 0x4179: cmp    WORD PTR [rdi+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_4181:
	/* 0x4181: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4187:
	/* 0x4187: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_418e:
	/* 0x418e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4191:
	/* 0x4191: mov    edx,DWORD PTR [rdi+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4197:
	/* 0x4197: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_419a:
	/* 0x419a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_419f:
	/* 0x419f: movzx  eax,WORD PTR [rdi+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_41a6:
	/* 0x41a6: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_41a8:
	/* 0x41a8: je     4437 <generic_sleepable_preload+0x4437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4437;
	}
x86_l_41ae:
	/* 0x41ae: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_41b1:
	/* 0x41b1: je     41d6 <generic_sleepable_preload+0x41d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41d6;
	}
x86_l_41b3:
	/* 0x41b3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41b8:
	/* 0x41b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41bd:
	/* 0x41bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41c2:
	/* 0x41c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_41c7:
	/* 0x41c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c9:
	/* 0x41c9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_41ce:
	/* 0x41ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41d0:
	/* 0x41d0: js     46ec <generic_sleepable_preload+0x46ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18156ULL;
	}
x86_l_41d6:
	/* 0x41d6: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_41de:
	/* 0x41de: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_41e4:
	/* 0x41e4: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_41ea:
	/* 0x41ea: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_41ef:
	/* 0x41ef: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_41f7:
	/* 0x41f7: je     421c <generic_sleepable_preload+0x421c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421c;
	}
x86_l_41f9:
	/* 0x41f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_41fe:
	/* 0x41fe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4203:
	/* 0x4203: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4208:
	/* 0x4208: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_420d:
	/* 0x420d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_420f:
	/* 0x420f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4214:
	/* 0x4214: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4216:
	/* 0x4216: js     4cf2 <generic_sleepable_preload+0x4cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19698ULL;
	}
x86_l_421c:
	/* 0x421c: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4224:
	/* 0x4224: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_422a:
	/* 0x422a: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4230:
	/* 0x4230: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4235:
	/* 0x4235: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_423d:
	/* 0x423d: je     4262 <generic_sleepable_preload+0x4262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4262;
	}
x86_l_423f:
	/* 0x423f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4244:
	/* 0x4244: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4249:
	/* 0x4249: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_424e:
	/* 0x424e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4253:
	/* 0x4253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4255:
	/* 0x4255: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_425a:
	/* 0x425a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_425c:
	/* 0x425c: js     4d06 <generic_sleepable_preload+0x4d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19718ULL;
	}
x86_l_4262:
	/* 0x4262: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_426a:
	/* 0x426a: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4270:
	/* 0x4270: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4276:
	/* 0x4276: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_427b:
	/* 0x427b: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4283:
	/* 0x4283: je     42a8 <generic_sleepable_preload+0x42a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a8;
	}
x86_l_4285:
	/* 0x4285: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_428a:
	/* 0x428a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_428f:
	/* 0x428f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4294:
	/* 0x4294: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4299:
	/* 0x4299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_429b:
	/* 0x429b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42a0:
	/* 0x42a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a2:
	/* 0x42a2: js     4d57 <generic_sleepable_preload+0x4d57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19799ULL;
	}
x86_l_42a8:
	/* 0x42a8: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_42b0:
	/* 0x42b0: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_42b6:
	/* 0x42b6: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_42bc:
	/* 0x42bc: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_42c1:
	/* 0x42c1: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_42c9:
	/* 0x42c9: je     42ee <generic_sleepable_preload+0x42ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42ee;
	}
x86_l_42cb:
	/* 0x42cb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_42d0:
	/* 0x42d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42d5:
	/* 0x42d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42da:
	/* 0x42da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42df:
	/* 0x42df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e1:
	/* 0x42e1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42e6:
	/* 0x42e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42e8:
	/* 0x42e8: js     4d68 <generic_sleepable_preload+0x4d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19816ULL;
	}
x86_l_42ee:
	/* 0x42ee: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_42f6:
	/* 0x42f6: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_42fc:
	/* 0x42fc: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4302:
	/* 0x4302: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4307:
	/* 0x4307: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_430f:
	/* 0x430f: je     4334 <generic_sleepable_preload+0x4334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4334;
	}
x86_l_4311:
	/* 0x4311: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4316:
	/* 0x4316: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_431b:
	/* 0x431b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4320:
	/* 0x4320: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4325:
	/* 0x4325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4327:
	/* 0x4327: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_432c:
	/* 0x432c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_432e:
	/* 0x432e: js     4d79 <generic_sleepable_preload+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19833ULL;
	}
x86_l_4334:
	/* 0x4334: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_433c:
	/* 0x433c: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4342:
	/* 0x4342: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4348:
	/* 0x4348: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_434d:
	/* 0x434d: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4355:
	/* 0x4355: je     4375 <generic_sleepable_preload+0x4375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4375;
	}
x86_l_4357:
	/* 0x4357: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_435c:
	/* 0x435c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4361:
	/* 0x4361: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4366:
	/* 0x4366: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_436b:
	/* 0x436b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_436d:
	/* 0x436d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_436f:
	/* 0x436f: js     5de5 <generic_sleepable_preload+0x5de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24037ULL;
	}
x86_l_4375:
	/* 0x4375: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_437a:
	/* 0x437a: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4382:
	/* 0x4382: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4388:
	/* 0x4388: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_438e:
	/* 0x438e: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4393:
	/* 0x4393: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_439b:
	/* 0x439b: je     43bb <generic_sleepable_preload+0x43bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43bb;
	}
x86_l_439d:
	/* 0x439d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43a2:
	/* 0x43a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43a7:
	/* 0x43a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43ac:
	/* 0x43ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43b1:
	/* 0x43b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b3:
	/* 0x43b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43b5:
	/* 0x43b5: js     5f5f <generic_sleepable_preload+0x5f5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24415ULL;
	}
x86_l_43bb:
	/* 0x43bb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_43c0:
	/* 0x43c0: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_43c8:
	/* 0x43c8: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_43ce:
	/* 0x43ce: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_43d4:
	/* 0x43d4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_43d9:
	/* 0x43d9: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_43e1:
	/* 0x43e1: je     4401 <generic_sleepable_preload+0x4401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4401;
	}
x86_l_43e3:
	/* 0x43e3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_43e8:
	/* 0x43e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43ed:
	/* 0x43ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43f2:
	/* 0x43f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43f7:
	/* 0x43f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43f9:
	/* 0x43f9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43fb:
	/* 0x43fb: js     6055 <generic_sleepable_preload+0x6055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24661ULL;
	}
x86_l_4401:
	/* 0x4401: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4406:
	/* 0x4406: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_440e:
	/* 0x440e: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4414:
	/* 0x4414: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_441a:
	/* 0x441a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_441f:
	/* 0x441f: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4427:
	/* 0x4427: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_442d:
	/* 0x442d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4432:
	/* 0x4432: jmp    46c4 <generic_sleepable_preload+0x46c4> */
	return 18116ULL;
x86_l_4437:
	/* 0x4437: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_443a:
	/* 0x443a: je     445f <generic_sleepable_preload+0x445f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_445f;
	}
x86_l_443c:
	/* 0x443c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4441:
	/* 0x4441: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4446:
	/* 0x4446: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_444b:
	/* 0x444b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4450:
	/* 0x4450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4452:
	/* 0x4452: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4457:
	/* 0x4457: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4459:
	/* 0x4459: js     46ec <generic_sleepable_preload+0x46ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18156ULL;
	}
x86_l_445f:
	/* 0x445f: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4467:
	/* 0x4467: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_446d:
	/* 0x446d: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4473:
	/* 0x4473: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4478:
	/* 0x4478: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4480:
	/* 0x4480: je     44a5 <generic_sleepable_preload+0x44a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44a5;
	}
x86_l_4482:
	/* 0x4482: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4487:
	/* 0x4487: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_448c:
	/* 0x448c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4491:
	/* 0x4491: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4496:
	/* 0x4496: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4498:
	/* 0x4498: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_449d:
	/* 0x449d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_449f:
	/* 0x449f: js     4cf2 <generic_sleepable_preload+0x4cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19698ULL;
	}
x86_l_44a5:
	/* 0x44a5: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_44ad:
	/* 0x44ad: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_44b3:
	/* 0x44b3: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_44b9:
	/* 0x44b9: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_44be:
	/* 0x44be: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_44c6:
	/* 0x44c6: je     44eb <generic_sleepable_preload+0x44eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44eb;
	}
x86_l_44c8:
	/* 0x44c8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_44cd:
	/* 0x44cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d2:
	/* 0x44d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d7:
	/* 0x44d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44dc:
	/* 0x44dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44de:
	/* 0x44de: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44e3:
	/* 0x44e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44e5:
	/* 0x44e5: js     4d06 <generic_sleepable_preload+0x4d06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19718ULL;
	}
x86_l_44eb:
	/* 0x44eb: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_44f3:
	/* 0x44f3: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_44f9:
	/* 0x44f9: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_44ff:
	/* 0x44ff: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4504:
	/* 0x4504: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_450c:
	/* 0x450c: je     4531 <generic_sleepable_preload+0x4531> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4531;
	}
x86_l_450e:
	/* 0x450e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4513:
	/* 0x4513: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4518:
	/* 0x4518: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_451d:
	/* 0x451d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4522:
	/* 0x4522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4524:
	/* 0x4524: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4529:
	/* 0x4529: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_452b:
	/* 0x452b: js     4d57 <generic_sleepable_preload+0x4d57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19799ULL;
	}
x86_l_4531:
	/* 0x4531: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4539:
	/* 0x4539: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_453f:
	/* 0x453f: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4545:
	/* 0x4545: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_454a:
	/* 0x454a: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4552:
	/* 0x4552: je     4577 <generic_sleepable_preload+0x4577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4577;
	}
x86_l_4554:
	/* 0x4554: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4559:
	/* 0x4559: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_455e:
	/* 0x455e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4563:
	/* 0x4563: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4568:
	/* 0x4568: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456a:
	/* 0x456a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_456f:
	/* 0x456f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4571:
	/* 0x4571: js     4d68 <generic_sleepable_preload+0x4d68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19816ULL;
	}
x86_l_4577:
	/* 0x4577: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_457f:
	/* 0x457f: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4585:
	/* 0x4585: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_458b:
	/* 0x458b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4590:
	/* 0x4590: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4598:
	/* 0x4598: je     45bd <generic_sleepable_preload+0x45bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45bd;
	}
x86_l_459a:
	/* 0x459a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_459f:
	/* 0x459f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45a4:
	/* 0x45a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45a9:
	/* 0x45a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45ae:
	/* 0x45ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45b0:
	/* 0x45b0: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_45b5:
	/* 0x45b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45b7:
	/* 0x45b7: js     4d79 <generic_sleepable_preload+0x4d79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19833ULL;
	}
x86_l_45bd:
	/* 0x45bd: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_45c5:
	/* 0x45c5: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_45cb:
	/* 0x45cb: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_45d1:
	/* 0x45d1: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_45d6:
	/* 0x45d6: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_45de:
	/* 0x45de: je     45fe <generic_sleepable_preload+0x45fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45fe;
	}
x86_l_45e0:
	/* 0x45e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_45e5:
	/* 0x45e5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45ea:
	/* 0x45ea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45ef:
	/* 0x45ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45f4:
	/* 0x45f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45f6:
	/* 0x45f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45f8:
	/* 0x45f8: js     5de5 <generic_sleepable_preload+0x5de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24037ULL;
	}
x86_l_45fe:
	/* 0x45fe: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4603:
	/* 0x4603: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_460b:
	/* 0x460b: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_4611:
	/* 0x4611: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_4614:
	/* 0x4614: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_461a:
	/* 0x461a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_461f:
	/* 0x461f: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4627:
	/* 0x4627: je     4647 <generic_sleepable_preload+0x4647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4647;
	}
x86_l_4629:
	/* 0x4629: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_462e:
	/* 0x462e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4633:
	/* 0x4633: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4638:
	/* 0x4638: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_463d:
	/* 0x463d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_463f:
	/* 0x463f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4641:
	/* 0x4641: js     5fe5 <generic_sleepable_preload+0x5fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24549ULL;
	}
x86_l_4647:
	/* 0x4647: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_464c:
	/* 0x464c: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4654:
	/* 0x4654: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_4657:
	/* 0x4657: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19841ULL;
	}
x86_l_465d:
	/* 0x465d: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4663:
	/* 0x4663: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_4668:
	/* 0x4668: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4670:
	/* 0x4670: je     4690 <generic_sleepable_preload+0x4690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18064ULL;
	}
	return 18034ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18034ULL: goto x86_l_4672;
	case 18039ULL: goto x86_l_4677;
	case 18044ULL: goto x86_l_467c;
	case 18049ULL: goto x86_l_4681;
	case 18054ULL: goto x86_l_4686;
	case 18056ULL: goto x86_l_4688;
	case 18058ULL: goto x86_l_468a;
	case 18064ULL: goto x86_l_4690;
	case 18069ULL: goto x86_l_4695;
	case 18077ULL: goto x86_l_469d;
	case 18080ULL: goto x86_l_46a0;
	case 18086ULL: goto x86_l_46a6;
	case 18092ULL: goto x86_l_46ac;
	case 18097ULL: goto x86_l_46b1;
	case 18105ULL: goto x86_l_46b9;
	case 18111ULL: goto x86_l_46bf;
	case 18116ULL: goto x86_l_46c4;
	case 18121ULL: goto x86_l_46c9;
	case 18126ULL: goto x86_l_46ce;
	case 18131ULL: goto x86_l_46d3;
	case 18133ULL: goto x86_l_46d5;
	case 18138ULL: goto x86_l_46da;
	case 18140ULL: goto x86_l_46dc;
	case 18146ULL: goto x86_l_46e2;
	case 18151ULL: goto x86_l_46e7;
	case 18156ULL: goto x86_l_46ec;
	case 18161ULL: goto x86_l_46f1;
	case 18166ULL: goto x86_l_46f6;
	case 18174ULL: goto x86_l_46fe;
	case 18177ULL: goto x86_l_4701;
	case 18179ULL: goto x86_l_4703;
	case 18184ULL: goto x86_l_4708;
	case 18187ULL: goto x86_l_470b;
	case 18189ULL: goto x86_l_470d;
	case 18191ULL: goto x86_l_470f;
	case 18196ULL: goto x86_l_4714;
	case 18199ULL: goto x86_l_4717;
	case 18201ULL: goto x86_l_4719;
	case 18206ULL: goto x86_l_471e;
	case 18209ULL: goto x86_l_4721;
	case 18211ULL: goto x86_l_4723;
	case 18213ULL: goto x86_l_4725;
	case 18221ULL: goto x86_l_472d;
	case 18224ULL: goto x86_l_4730;
	case 18226ULL: goto x86_l_4732;
	case 18231ULL: goto x86_l_4737;
	case 18234ULL: goto x86_l_473a;
	case 18236ULL: goto x86_l_473c;
	case 18238ULL: goto x86_l_473e;
	case 18246ULL: goto x86_l_4746;
	case 18249ULL: goto x86_l_4749;
	case 18251ULL: goto x86_l_474b;
	case 18256ULL: goto x86_l_4750;
	case 18259ULL: goto x86_l_4753;
	case 18261ULL: goto x86_l_4755;
	case 18264ULL: goto x86_l_4758;
	case 18266ULL: goto x86_l_475a;
	case 18268ULL: goto x86_l_475c;
	case 18273ULL: goto x86_l_4761;
	case 18275ULL: goto x86_l_4763;
	case 18280ULL: goto x86_l_4768;
	case 18285ULL: goto x86_l_476d;
	case 18288ULL: goto x86_l_4770;
	case 18290ULL: goto x86_l_4772;
	case 18293ULL: goto x86_l_4775;
	case 18301ULL: goto x86_l_477d;
	case 18307ULL: goto x86_l_4783;
	case 18314ULL: goto x86_l_478a;
	case 18317ULL: goto x86_l_478d;
	case 18323ULL: goto x86_l_4793;
	case 18326ULL: goto x86_l_4796;
	case 18331ULL: goto x86_l_479b;
	case 18338ULL: goto x86_l_47a2;
	case 18340ULL: goto x86_l_47a4;
	case 18346ULL: goto x86_l_47aa;
	case 18349ULL: goto x86_l_47ad;
	case 18351ULL: goto x86_l_47af;
	case 18356ULL: goto x86_l_47b4;
	case 18361ULL: goto x86_l_47b9;
	case 18366ULL: goto x86_l_47be;
	case 18371ULL: goto x86_l_47c3;
	case 18373ULL: goto x86_l_47c5;
	case 18378ULL: goto x86_l_47ca;
	case 18380ULL: goto x86_l_47cc;
	case 18386ULL: goto x86_l_47d2;
	case 18394ULL: goto x86_l_47da;
	case 18400ULL: goto x86_l_47e0;
	case 18406ULL: goto x86_l_47e6;
	case 18411ULL: goto x86_l_47eb;
	case 18419ULL: goto x86_l_47f3;
	case 18421ULL: goto x86_l_47f5;
	case 18426ULL: goto x86_l_47fa;
	case 18431ULL: goto x86_l_47ff;
	case 18436ULL: goto x86_l_4804;
	case 18441ULL: goto x86_l_4809;
	case 18443ULL: goto x86_l_480b;
	case 18448ULL: goto x86_l_4810;
	case 18450ULL: goto x86_l_4812;
	case 18456ULL: goto x86_l_4818;
	case 18464ULL: goto x86_l_4820;
	case 18470ULL: goto x86_l_4826;
	case 18476ULL: goto x86_l_482c;
	case 18481ULL: goto x86_l_4831;
	case 18489ULL: goto x86_l_4839;
	case 18491ULL: goto x86_l_483b;
	case 18496ULL: goto x86_l_4840;
	case 18501ULL: goto x86_l_4845;
	case 18506ULL: goto x86_l_484a;
	case 18511ULL: goto x86_l_484f;
	case 18513ULL: goto x86_l_4851;
	case 18518ULL: goto x86_l_4856;
	case 18520ULL: goto x86_l_4858;
	case 18526ULL: goto x86_l_485e;
	case 18534ULL: goto x86_l_4866;
	case 18540ULL: goto x86_l_486c;
	case 18546ULL: goto x86_l_4872;
	case 18551ULL: goto x86_l_4877;
	case 18559ULL: goto x86_l_487f;
	case 18561ULL: goto x86_l_4881;
	case 18566ULL: goto x86_l_4886;
	case 18571ULL: goto x86_l_488b;
	case 18576ULL: goto x86_l_4890;
	case 18581ULL: goto x86_l_4895;
	case 18583ULL: goto x86_l_4897;
	case 18588ULL: goto x86_l_489c;
	case 18590ULL: goto x86_l_489e;
	case 18596ULL: goto x86_l_48a4;
	case 18604ULL: goto x86_l_48ac;
	case 18610ULL: goto x86_l_48b2;
	case 18616ULL: goto x86_l_48b8;
	case 18621ULL: goto x86_l_48bd;
	case 18629ULL: goto x86_l_48c5;
	case 18631ULL: goto x86_l_48c7;
	case 18636ULL: goto x86_l_48cc;
	case 18641ULL: goto x86_l_48d1;
	case 18646ULL: goto x86_l_48d6;
	case 18651ULL: goto x86_l_48db;
	case 18653ULL: goto x86_l_48dd;
	case 18658ULL: goto x86_l_48e2;
	case 18660ULL: goto x86_l_48e4;
	case 18666ULL: goto x86_l_48ea;
	case 18674ULL: goto x86_l_48f2;
	case 18680ULL: goto x86_l_48f8;
	case 18686ULL: goto x86_l_48fe;
	case 18691ULL: goto x86_l_4903;
	case 18699ULL: goto x86_l_490b;
	case 18701ULL: goto x86_l_490d;
	case 18706ULL: goto x86_l_4912;
	case 18711ULL: goto x86_l_4917;
	case 18716ULL: goto x86_l_491c;
	case 18721ULL: goto x86_l_4921;
	case 18723ULL: goto x86_l_4923;
	case 18728ULL: goto x86_l_4928;
	case 18730ULL: goto x86_l_492a;
	case 18736ULL: goto x86_l_4930;
	case 18744ULL: goto x86_l_4938;
	case 18750ULL: goto x86_l_493e;
	case 18756ULL: goto x86_l_4944;
	case 18761ULL: goto x86_l_4949;
	case 18769ULL: goto x86_l_4951;
	case 18771ULL: goto x86_l_4953;
	case 18776ULL: goto x86_l_4958;
	case 18781ULL: goto x86_l_495d;
	case 18786ULL: goto x86_l_4962;
	case 18791ULL: goto x86_l_4967;
	case 18793ULL: goto x86_l_4969;
	case 18795ULL: goto x86_l_496b;
	case 18801ULL: goto x86_l_4971;
	case 18806ULL: goto x86_l_4976;
	case 18814ULL: goto x86_l_497e;
	case 18820ULL: goto x86_l_4984;
	case 18826ULL: goto x86_l_498a;
	case 18831ULL: goto x86_l_498f;
	case 18839ULL: goto x86_l_4997;
	case 18841ULL: goto x86_l_4999;
	case 18846ULL: goto x86_l_499e;
	case 18851ULL: goto x86_l_49a3;
	case 18856ULL: goto x86_l_49a8;
	case 18861ULL: goto x86_l_49ad;
	case 18863ULL: goto x86_l_49af;
	case 18865ULL: goto x86_l_49b1;
	case 18871ULL: goto x86_l_49b7;
	case 18876ULL: goto x86_l_49bc;
	case 18884ULL: goto x86_l_49c4;
	case 18890ULL: goto x86_l_49ca;
	case 18896ULL: goto x86_l_49d0;
	case 18901ULL: goto x86_l_49d5;
	case 18909ULL: goto x86_l_49dd;
	case 18911ULL: goto x86_l_49df;
	case 18916ULL: goto x86_l_49e4;
	case 18921ULL: goto x86_l_49e9;
	case 18926ULL: goto x86_l_49ee;
	case 18931ULL: goto x86_l_49f3;
	case 18933ULL: goto x86_l_49f5;
	case 18935ULL: goto x86_l_49f7;
	case 18941ULL: goto x86_l_49fd;
	case 18946ULL: goto x86_l_4a02;
	case 18954ULL: goto x86_l_4a0a;
	case 18960ULL: goto x86_l_4a10;
	case 18966ULL: goto x86_l_4a16;
	case 18971ULL: goto x86_l_4a1b;
	case 18979ULL: goto x86_l_4a23;
	case 18985ULL: goto x86_l_4a29;
	case 18990ULL: goto x86_l_4a2e;
	case 18995ULL: goto x86_l_4a33;
	case 18998ULL: goto x86_l_4a36;
	case 19000ULL: goto x86_l_4a38;
	case 19005ULL: goto x86_l_4a3d;
	case 19010ULL: goto x86_l_4a42;
	case 19015ULL: goto x86_l_4a47;
	case 19020ULL: goto x86_l_4a4c;
	case 19022ULL: goto x86_l_4a4e;
	case 19027ULL: goto x86_l_4a53;
	case 19029ULL: goto x86_l_4a55;
	case 19035ULL: goto x86_l_4a5b;
	case 19043ULL: goto x86_l_4a63;
	case 19049ULL: goto x86_l_4a69;
	case 19055ULL: goto x86_l_4a6f;
	case 19060ULL: goto x86_l_4a74;
	case 19068ULL: goto x86_l_4a7c;
	case 19070ULL: goto x86_l_4a7e;
	case 19075ULL: goto x86_l_4a83;
	case 19080ULL: goto x86_l_4a88;
	case 19085ULL: goto x86_l_4a8d;
	case 19090ULL: goto x86_l_4a92;
	case 19092ULL: goto x86_l_4a94;
	case 19097ULL: goto x86_l_4a99;
	case 19099ULL: goto x86_l_4a9b;
	case 19105ULL: goto x86_l_4aa1;
	case 19113ULL: goto x86_l_4aa9;
	case 19119ULL: goto x86_l_4aaf;
	case 19125ULL: goto x86_l_4ab5;
	case 19130ULL: goto x86_l_4aba;
	case 19138ULL: goto x86_l_4ac2;
	case 19140ULL: goto x86_l_4ac4;
	case 19145ULL: goto x86_l_4ac9;
	case 19150ULL: goto x86_l_4ace;
	case 19155ULL: goto x86_l_4ad3;
	case 19160ULL: goto x86_l_4ad8;
	case 19162ULL: goto x86_l_4ada;
	case 19167ULL: goto x86_l_4adf;
	case 19169ULL: goto x86_l_4ae1;
	case 19175ULL: goto x86_l_4ae7;
	case 19183ULL: goto x86_l_4aef;
	case 19189ULL: goto x86_l_4af5;
	case 19195ULL: goto x86_l_4afb;
	case 19200ULL: goto x86_l_4b00;
	case 19208ULL: goto x86_l_4b08;
	case 19210ULL: goto x86_l_4b0a;
	case 19215ULL: goto x86_l_4b0f;
	case 19220ULL: goto x86_l_4b14;
	case 19225ULL: goto x86_l_4b19;
	case 19230ULL: goto x86_l_4b1e;
	case 19232ULL: goto x86_l_4b20;
	case 19237ULL: goto x86_l_4b25;
	case 19239ULL: goto x86_l_4b27;
	case 19245ULL: goto x86_l_4b2d;
	case 19253ULL: goto x86_l_4b35;
	case 19259ULL: goto x86_l_4b3b;
	case 19265ULL: goto x86_l_4b41;
	case 19270ULL: goto x86_l_4b46;
	case 19278ULL: goto x86_l_4b4e;
	case 19280ULL: goto x86_l_4b50;
	case 19285ULL: goto x86_l_4b55;
	case 19290ULL: goto x86_l_4b5a;
	case 19295ULL: goto x86_l_4b5f;
	case 19300ULL: goto x86_l_4b64;
	case 19302ULL: goto x86_l_4b66;
	case 19307ULL: goto x86_l_4b6b;
	case 19309ULL: goto x86_l_4b6d;
	case 19315ULL: goto x86_l_4b73;
	case 19323ULL: goto x86_l_4b7b;
	case 19329ULL: goto x86_l_4b81;
	case 19335ULL: goto x86_l_4b87;
	case 19340ULL: goto x86_l_4b8c;
	case 19348ULL: goto x86_l_4b94;
	case 19350ULL: goto x86_l_4b96;
	case 19355ULL: goto x86_l_4b9b;
	case 19360ULL: goto x86_l_4ba0;
	case 19365ULL: goto x86_l_4ba5;
	case 19370ULL: goto x86_l_4baa;
	case 19372ULL: goto x86_l_4bac;
	case 19377ULL: goto x86_l_4bb1;
	case 19379ULL: goto x86_l_4bb3;
	case 19385ULL: goto x86_l_4bb9;
	case 19393ULL: goto x86_l_4bc1;
	case 19399ULL: goto x86_l_4bc7;
	case 19405ULL: goto x86_l_4bcd;
	case 19410ULL: goto x86_l_4bd2;
	case 19418ULL: goto x86_l_4bda;
	case 19420ULL: goto x86_l_4bdc;
	case 19425ULL: goto x86_l_4be1;
	case 19430ULL: goto x86_l_4be6;
	case 19435ULL: goto x86_l_4beb;
	case 19440ULL: goto x86_l_4bf0;
	case 19442ULL: goto x86_l_4bf2;
	case 19444ULL: goto x86_l_4bf4;
	case 19450ULL: goto x86_l_4bfa;
	case 19455ULL: goto x86_l_4bff;
	case 19463ULL: goto x86_l_4c07;
	case 19469ULL: goto x86_l_4c0d;
	case 19472ULL: goto x86_l_4c10;
	case 19478ULL: goto x86_l_4c16;
	case 19483ULL: goto x86_l_4c1b;
	case 19491ULL: goto x86_l_4c23;
	case 19493ULL: goto x86_l_4c25;
	case 19498ULL: goto x86_l_4c2a;
	case 19503ULL: goto x86_l_4c2f;
	case 19508ULL: goto x86_l_4c34;
	case 19513ULL: goto x86_l_4c39;
	case 19515ULL: goto x86_l_4c3b;
	case 19517ULL: goto x86_l_4c3d;
	case 19523ULL: goto x86_l_4c43;
	case 19528ULL: goto x86_l_4c48;
	case 19536ULL: goto x86_l_4c50;
	case 19539ULL: goto x86_l_4c53;
	case 19545ULL: goto x86_l_4c59;
	case 19551ULL: goto x86_l_4c5f;
	case 19556ULL: goto x86_l_4c64;
	case 19564ULL: goto x86_l_4c6c;
	case 19566ULL: goto x86_l_4c6e;
	case 19571ULL: goto x86_l_4c73;
	case 19576ULL: goto x86_l_4c78;
	case 19581ULL: goto x86_l_4c7d;
	case 19586ULL: goto x86_l_4c82;
	case 19588ULL: goto x86_l_4c84;
	case 19590ULL: goto x86_l_4c86;
	case 19596ULL: goto x86_l_4c8c;
	case 19601ULL: goto x86_l_4c91;
	case 19609ULL: goto x86_l_4c99;
	case 19612ULL: goto x86_l_4c9c;
	case 19618ULL: goto x86_l_4ca2;
	case 19624ULL: goto x86_l_4ca8;
	case 19629ULL: goto x86_l_4cad;
	case 19637ULL: goto x86_l_4cb5;
	case 19643ULL: goto x86_l_4cbb;
	case 19648ULL: goto x86_l_4cc0;
	case 19653ULL: goto x86_l_4cc5;
	case 19658ULL: goto x86_l_4cca;
	case 19663ULL: goto x86_l_4ccf;
	case 19665ULL: goto x86_l_4cd1;
	case 19670ULL: goto x86_l_4cd6;
	case 19672ULL: goto x86_l_4cd8;
	case 19678ULL: goto x86_l_4cde;
	case 19683ULL: goto x86_l_4ce3;
	case 19688ULL: goto x86_l_4ce8;
	case 19693ULL: goto x86_l_4ced;
	case 19698ULL: goto x86_l_4cf2;
	case 19703ULL: goto x86_l_4cf7;
	case 19708ULL: goto x86_l_4cfc;
	case 19713ULL: goto x86_l_4d01;
	case 19718ULL: goto x86_l_4d06;
	case 19723ULL: goto x86_l_4d0b;
	case 19725ULL: goto x86_l_4d0d;
	case 19730ULL: goto x86_l_4d12;
	case 19735ULL: goto x86_l_4d17;
	case 19740ULL: goto x86_l_4d1c;
	case 19747ULL: goto x86_l_4d23;
	case 19754ULL: goto x86_l_4d2a;
	case 19761ULL: goto x86_l_4d31;
	case 19766ULL: goto x86_l_4d36;
	case 19769ULL: goto x86_l_4d39;
	case 19774ULL: goto x86_l_4d3e;
	case 19779ULL: goto x86_l_4d43;
	case 19781ULL: goto x86_l_4d45;
	case 19783ULL: goto x86_l_4d47;
	case 19786ULL: goto x86_l_4d4a;
	case 19792ULL: goto x86_l_4d50;
	case 19794ULL: goto x86_l_4d52;
	case 19799ULL: goto x86_l_4d57;
	case 19804ULL: goto x86_l_4d5c;
	case 19806ULL: goto x86_l_4d5e;
	case 19811ULL: goto x86_l_4d63;
	case 19816ULL: goto x86_l_4d68;
	case 19821ULL: goto x86_l_4d6d;
	case 19823ULL: goto x86_l_4d6f;
	case 19828ULL: goto x86_l_4d74;
	case 19833ULL: goto x86_l_4d79;
	case 19838ULL: goto x86_l_4d7e;
	case 19841ULL: goto x86_l_4d81;
	case 19844ULL: goto x86_l_4d84;
	case 19849ULL: goto x86_l_4d89;
	case 19854ULL: goto x86_l_4d8e;
	case 19859ULL: goto x86_l_4d93;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4672:
	/* 0x4672: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4677:
	/* 0x4677: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_467c:
	/* 0x467c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4681:
	/* 0x4681: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4686:
	/* 0x4686: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4688:
	/* 0x4688: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_468a:
	/* 0x468a: js     60f1 <generic_sleepable_preload+0x60f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24817ULL;
	}
x86_l_4690:
	/* 0x4690: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4695:
	/* 0x4695: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_469d:
	/* 0x469d: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_46a0:
	/* 0x46a0: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d81;
	}
x86_l_46a6:
	/* 0x46a6: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_46ac:
	/* 0x46ac: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_46b1:
	/* 0x46b1: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_46b9:
	/* 0x46b9: je     4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d81;
	}
x86_l_46bf:
	/* 0x46bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_46c4:
	/* 0x46c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46c9:
	/* 0x46c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ce:
	/* 0x46ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46d3:
	/* 0x46d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d5:
	/* 0x46d5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_46da:
	/* 0x46da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46dc:
	/* 0x46dc: jns    4d81 <generic_sleepable_preload+0x4d81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4d81;
	}
x86_l_46e2:
	/* 0x46e2: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_46e7:
	/* 0x46e7: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_46ec:
	/* 0x46ec: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_46f1:
	/* 0x46f1: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_46f6:
	/* 0x46f6: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_46fe:
	/* 0x46fe: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4701:
	/* 0x4701: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_4703:
	/* 0x4703: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4708:
	/* 0x4708: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_470b:
	/* 0x470b: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_470d:
	/* 0x470d: jmp    4768 <generic_sleepable_preload+0x4768> */
	goto x86_l_4768;
x86_l_470f:
	/* 0x470f: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4714:
	/* 0x4714: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4717:
	/* 0x4717: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_4719:
	/* 0x4719: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_471e:
	/* 0x471e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4721:
	/* 0x4721: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_4723:
	/* 0x4723: jmp    4768 <generic_sleepable_preload+0x4768> */
	goto x86_l_4768;
x86_l_4725:
	/* 0x4725: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_472d:
	/* 0x472d: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_4730:
	/* 0x4730: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_4732:
	/* 0x4732: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4737:
	/* 0x4737: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_473a:
	/* 0x473a: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_473c:
	/* 0x473c: jmp    4768 <generic_sleepable_preload+0x4768> */
	goto x86_l_4768;
x86_l_473e:
	/* 0x473e: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4746:
	/* 0x4746: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4749:
	/* 0x4749: je     4755 <generic_sleepable_preload+0x4755> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4755;
	}
x86_l_474b:
	/* 0x474b: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4750:
	/* 0x4750: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4753:
	/* 0x4753: jne    4768 <generic_sleepable_preload+0x4768> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4768;
	}
x86_l_4755:
	/* 0x4755: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_4758:
	/* 0x4758: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_475a:
	/* 0x475a: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_475c:
	/* 0x475c: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_4761:
	/* 0x4761: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4763:
	/* 0x4763: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_4768:
	/* 0x4768: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_476d:
	/* 0x476d: mov    ebx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4770:
	/* 0x4770: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4772:
	/* 0x4772: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_4775:
	/* 0x4775: cmp    WORD PTR [rdi+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_477d:
	/* 0x477d: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4783:
	/* 0x4783: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_478a:
	/* 0x478a: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_478d:
	/* 0x478d: mov    edx,DWORD PTR [rdi+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_4793:
	/* 0x4793: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4796:
	/* 0x4796: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_479b:
	/* 0x479b: movzx  eax,WORD PTR [rdi+0x164] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 356ULL);
x86_l_47a2:
	/* 0x47a2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_47a4:
	/* 0x47a4: je     4a33 <generic_sleepable_preload+0x4a33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a33;
	}
x86_l_47aa:
	/* 0x47aa: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_47ad:
	/* 0x47ad: je     47d2 <generic_sleepable_preload+0x47d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47d2;
	}
x86_l_47af:
	/* 0x47af: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47b4:
	/* 0x47b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47b9:
	/* 0x47b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47be:
	/* 0x47be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47c3:
	/* 0x47c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47c5:
	/* 0x47c5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47ca:
	/* 0x47ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_47cc:
	/* 0x47cc: js     4ce8 <generic_sleepable_preload+0x4ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ce8;
	}
x86_l_47d2:
	/* 0x47d2: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_47da:
	/* 0x47da: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_47e0:
	/* 0x47e0: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_47e6:
	/* 0x47e6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_47eb:
	/* 0x47eb: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_47f3:
	/* 0x47f3: je     4818 <generic_sleepable_preload+0x4818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4818;
	}
x86_l_47f5:
	/* 0x47f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_47fa:
	/* 0x47fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47ff:
	/* 0x47ff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4804:
	/* 0x4804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4809:
	/* 0x4809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_480b:
	/* 0x480b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4810:
	/* 0x4810: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4812:
	/* 0x4812: js     4cfc <generic_sleepable_preload+0x4cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cfc;
	}
x86_l_4818:
	/* 0x4818: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4820:
	/* 0x4820: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4826:
	/* 0x4826: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_482c:
	/* 0x482c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4831:
	/* 0x4831: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4839:
	/* 0x4839: je     485e <generic_sleepable_preload+0x485e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485e;
	}
x86_l_483b:
	/* 0x483b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4840:
	/* 0x4840: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4845:
	/* 0x4845: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484a:
	/* 0x484a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_484f:
	/* 0x484f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4851:
	/* 0x4851: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4856:
	/* 0x4856: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4858:
	/* 0x4858: js     4d0d <generic_sleepable_preload+0x4d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d0d;
	}
x86_l_485e:
	/* 0x485e: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4866:
	/* 0x4866: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_486c:
	/* 0x486c: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4872:
	/* 0x4872: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4877:
	/* 0x4877: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_487f:
	/* 0x487f: je     48a4 <generic_sleepable_preload+0x48a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48a4;
	}
x86_l_4881:
	/* 0x4881: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4886:
	/* 0x4886: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488b:
	/* 0x488b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4890:
	/* 0x4890: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4895:
	/* 0x4895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4897:
	/* 0x4897: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_489c:
	/* 0x489c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_489e:
	/* 0x489e: js     4d5e <generic_sleepable_preload+0x4d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d5e;
	}
x86_l_48a4:
	/* 0x48a4: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_48ac:
	/* 0x48ac: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_48b2:
	/* 0x48b2: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_48b8:
	/* 0x48b8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_48bd:
	/* 0x48bd: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_48c5:
	/* 0x48c5: je     48ea <generic_sleepable_preload+0x48ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48ea;
	}
x86_l_48c7:
	/* 0x48c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_48cc:
	/* 0x48cc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48d1:
	/* 0x48d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48d6:
	/* 0x48d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48db:
	/* 0x48db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48dd:
	/* 0x48dd: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48e2:
	/* 0x48e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48e4:
	/* 0x48e4: js     4d6f <generic_sleepable_preload+0x4d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d6f;
	}
x86_l_48ea:
	/* 0x48ea: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_48f2:
	/* 0x48f2: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_48f8:
	/* 0x48f8: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_48fe:
	/* 0x48fe: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4903:
	/* 0x4903: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_490b:
	/* 0x490b: je     4930 <generic_sleepable_preload+0x4930> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4930;
	}
x86_l_490d:
	/* 0x490d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4912:
	/* 0x4912: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4917:
	/* 0x4917: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491c:
	/* 0x491c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4921:
	/* 0x4921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4923:
	/* 0x4923: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4928:
	/* 0x4928: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_492a:
	/* 0x492a: js     4e00 <generic_sleepable_preload+0x4e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19968ULL;
	}
x86_l_4930:
	/* 0x4930: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4938:
	/* 0x4938: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_493e:
	/* 0x493e: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4944:
	/* 0x4944: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4949:
	/* 0x4949: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4951:
	/* 0x4951: je     4971 <generic_sleepable_preload+0x4971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4971;
	}
x86_l_4953:
	/* 0x4953: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4958:
	/* 0x4958: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_495d:
	/* 0x495d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4962:
	/* 0x4962: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4967:
	/* 0x4967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4969:
	/* 0x4969: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_496b:
	/* 0x496b: js     5df7 <generic_sleepable_preload+0x5df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24055ULL;
	}
x86_l_4971:
	/* 0x4971: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4976:
	/* 0x4976: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_497e:
	/* 0x497e: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4984:
	/* 0x4984: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_498a:
	/* 0x498a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_498f:
	/* 0x498f: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4997:
	/* 0x4997: je     49b7 <generic_sleepable_preload+0x49b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49b7;
	}
x86_l_4999:
	/* 0x4999: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_499e:
	/* 0x499e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a3:
	/* 0x49a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49a8:
	/* 0x49a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49ad:
	/* 0x49ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49af:
	/* 0x49af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49b1:
	/* 0x49b1: js     5f71 <generic_sleepable_preload+0x5f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24433ULL;
	}
x86_l_49b7:
	/* 0x49b7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_49bc:
	/* 0x49bc: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_49c4:
	/* 0x49c4: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_49ca:
	/* 0x49ca: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_49d0:
	/* 0x49d0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49d5:
	/* 0x49d5: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_49dd:
	/* 0x49dd: je     49fd <generic_sleepable_preload+0x49fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49fd;
	}
x86_l_49df:
	/* 0x49df: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_49e4:
	/* 0x49e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e9:
	/* 0x49e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49ee:
	/* 0x49ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49f3:
	/* 0x49f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f5:
	/* 0x49f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49f7:
	/* 0x49f7: js     605f <generic_sleepable_preload+0x605f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24671ULL;
	}
x86_l_49fd:
	/* 0x49fd: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a02:
	/* 0x4a02: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4a0a:
	/* 0x4a0a: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4a10:
	/* 0x4a10: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4a16:
	/* 0x4a16: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a1b:
	/* 0x4a1b: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4a23:
	/* 0x4a23: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4a29:
	/* 0x4a29: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a2e:
	/* 0x4a2e: jmp    4cc0 <generic_sleepable_preload+0x4cc0> */
	goto x86_l_4cc0;
x86_l_4a33:
	/* 0x4a33: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4a36:
	/* 0x4a36: je     4a5b <generic_sleepable_preload+0x4a5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a5b;
	}
x86_l_4a38:
	/* 0x4a38: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a3d:
	/* 0x4a3d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a42:
	/* 0x4a42: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a47:
	/* 0x4a47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a4c:
	/* 0x4a4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a4e:
	/* 0x4a4e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a53:
	/* 0x4a53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a55:
	/* 0x4a55: js     4ce8 <generic_sleepable_preload+0x4ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ce8;
	}
x86_l_4a5b:
	/* 0x4a5b: cmp    WORD PTR [rdi+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_4a63:
	/* 0x4a63: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4a69:
	/* 0x4a69: mov    eax,DWORD PTR [rdi+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_4a6f:
	/* 0x4a6f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4a74:
	/* 0x4a74: cmp    WORD PTR [rdi+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_4a7c:
	/* 0x4a7c: je     4aa1 <generic_sleepable_preload+0x4aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4aa1;
	}
x86_l_4a7e:
	/* 0x4a7e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4a83:
	/* 0x4a83: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a88:
	/* 0x4a88: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a8d:
	/* 0x4a8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a92:
	/* 0x4a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a94:
	/* 0x4a94: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a99:
	/* 0x4a99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a9b:
	/* 0x4a9b: js     4cfc <generic_sleepable_preload+0x4cfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4cfc;
	}
x86_l_4aa1:
	/* 0x4aa1: cmp    WORD PTR [rdi+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_4aa9:
	/* 0x4aa9: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4aaf:
	/* 0x4aaf: mov    eax,DWORD PTR [rdi+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_4ab5:
	/* 0x4ab5: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4aba:
	/* 0x4aba: cmp    WORD PTR [rdi+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_4ac2:
	/* 0x4ac2: je     4ae7 <generic_sleepable_preload+0x4ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ae7;
	}
x86_l_4ac4:
	/* 0x4ac4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4ac9:
	/* 0x4ac9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ace:
	/* 0x4ace: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad3:
	/* 0x4ad3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ad8:
	/* 0x4ad8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ada:
	/* 0x4ada: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4adf:
	/* 0x4adf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ae1:
	/* 0x4ae1: js     4d0d <generic_sleepable_preload+0x4d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d0d;
	}
x86_l_4ae7:
	/* 0x4ae7: cmp    WORD PTR [rdi+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_4aef:
	/* 0x4aef: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4af5:
	/* 0x4af5: mov    eax,DWORD PTR [rdi+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_4afb:
	/* 0x4afb: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b00:
	/* 0x4b00: cmp    WORD PTR [rdi+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_4b08:
	/* 0x4b08: je     4b2d <generic_sleepable_preload+0x4b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b2d;
	}
x86_l_4b0a:
	/* 0x4b0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b0f:
	/* 0x4b0f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b14:
	/* 0x4b14: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b19:
	/* 0x4b19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b1e:
	/* 0x4b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b20:
	/* 0x4b20: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b25:
	/* 0x4b25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b27:
	/* 0x4b27: js     4d5e <generic_sleepable_preload+0x4d5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d5e;
	}
x86_l_4b2d:
	/* 0x4b2d: cmp    WORD PTR [rdi+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_4b35:
	/* 0x4b35: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4b3b:
	/* 0x4b3b: mov    eax,DWORD PTR [rdi+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_4b41:
	/* 0x4b41: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b46:
	/* 0x4b46: cmp    WORD PTR [rdi+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_4b4e:
	/* 0x4b4e: je     4b73 <generic_sleepable_preload+0x4b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b73;
	}
x86_l_4b50:
	/* 0x4b50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b55:
	/* 0x4b55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b5a:
	/* 0x4b5a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b5f:
	/* 0x4b5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b64:
	/* 0x4b64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b66:
	/* 0x4b66: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b6b:
	/* 0x4b6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b6d:
	/* 0x4b6d: js     4d6f <generic_sleepable_preload+0x4d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4d6f;
	}
x86_l_4b73:
	/* 0x4b73: cmp    WORD PTR [rdi+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_4b7b:
	/* 0x4b7b: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4b81:
	/* 0x4b81: mov    eax,DWORD PTR [rdi+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_4b87:
	/* 0x4b87: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4b8c:
	/* 0x4b8c: cmp    WORD PTR [rdi+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_4b94:
	/* 0x4b94: je     4bb9 <generic_sleepable_preload+0x4bb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bb9;
	}
x86_l_4b96:
	/* 0x4b96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ba0:
	/* 0x4ba0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ba5:
	/* 0x4ba5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4baa:
	/* 0x4baa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bac:
	/* 0x4bac: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bb1:
	/* 0x4bb1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bb3:
	/* 0x4bb3: js     4e00 <generic_sleepable_preload+0x4e00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 19968ULL;
	}
x86_l_4bb9:
	/* 0x4bb9: cmp    WORD PTR [rdi+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_4bc1:
	/* 0x4bc1: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4bc7:
	/* 0x4bc7: mov    eax,DWORD PTR [rdi+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4bcd:
	/* 0x4bcd: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4bd2:
	/* 0x4bd2: cmp    WORD PTR [rdi+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_4bda:
	/* 0x4bda: je     4bfa <generic_sleepable_preload+0x4bfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bfa;
	}
x86_l_4bdc:
	/* 0x4bdc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4be1:
	/* 0x4be1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4be6:
	/* 0x4be6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4beb:
	/* 0x4beb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4bf0:
	/* 0x4bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf2:
	/* 0x4bf2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bf4:
	/* 0x4bf4: js     5df7 <generic_sleepable_preload+0x5df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24055ULL;
	}
x86_l_4bfa:
	/* 0x4bfa: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4bff:
	/* 0x4bff: cmp    WORD PTR [rdi+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_4c07:
	/* 0x4c07: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4c0d:
	/* 0x4c0d: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4c10:
	/* 0x4c10: mov    eax,DWORD PTR [rdi+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4c16:
	/* 0x4c16: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c1b:
	/* 0x4c1b: cmp    WORD PTR [rdi+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_4c23:
	/* 0x4c23: je     4c43 <generic_sleepable_preload+0x4c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c43;
	}
x86_l_4c25:
	/* 0x4c25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c2a:
	/* 0x4c2a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c2f:
	/* 0x4c2f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c34:
	/* 0x4c34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c39:
	/* 0x4c39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c3b:
	/* 0x4c3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c3d:
	/* 0x4c3d: js     5ff2 <generic_sleepable_preload+0x5ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24562ULL;
	}
x86_l_4c43:
	/* 0x4c43: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c48:
	/* 0x4c48: cmp    WORD PTR [rdi+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_4c50:
	/* 0x4c50: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4c53:
	/* 0x4c53: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4c59:
	/* 0x4c59: mov    eax,DWORD PTR [rdi+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_4c5f:
	/* 0x4c5f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4c64:
	/* 0x4c64: cmp    WORD PTR [rdi+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_4c6c:
	/* 0x4c6c: je     4c8c <generic_sleepable_preload+0x4c8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c8c;
	}
x86_l_4c6e:
	/* 0x4c6e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4c73:
	/* 0x4c73: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c78:
	/* 0x4c78: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c7d:
	/* 0x4c7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c82:
	/* 0x4c82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c84:
	/* 0x4c84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c86:
	/* 0x4c86: js     6106 <generic_sleepable_preload+0x6106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24838ULL;
	}
x86_l_4c8c:
	/* 0x4c8c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c91:
	/* 0x4c91: cmp    WORD PTR [rdi+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_4c99:
	/* 0x4c99: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4c9c:
	/* 0x4c9c: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4ca2:
	/* 0x4ca2: mov    eax,DWORD PTR [rdi+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_4ca8:
	/* 0x4ca8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4cad:
	/* 0x4cad: cmp    WORD PTR [rdi+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_4cb5:
	/* 0x4cb5: je     4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19976ULL;
	}
x86_l_4cbb:
	/* 0x4cbb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4cc0:
	/* 0x4cc0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cc5:
	/* 0x4cc5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cca:
	/* 0x4cca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ccf:
	/* 0x4ccf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd1:
	/* 0x4cd1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4cd6:
	/* 0x4cd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cd8:
	/* 0x4cd8: jns    4e08 <generic_sleepable_preload+0x4e08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 19976ULL;
	}
x86_l_4cde:
	/* 0x4cde: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4ce3:
	/* 0x4ce3: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4ce8:
	/* 0x4ce8: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4ced:
	/* 0x4ced: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4cf2:
	/* 0x4cf2: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4cf7:
	/* 0x4cf7: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_4cfc:
	/* 0x4cfc: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4d01:
	/* 0x4d01: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4d06:
	/* 0x4d06: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4d0b:
	/* 0x4d0b: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_4d0d:
	/* 0x4d0d: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_4d12:
	/* 0x4d12: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4d17:
	/* 0x4d17: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4d1c:
	/* 0x4d1c: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_4d23:
	/* 0x4d23: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_4d2a:
	/* 0x4d2a: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_4d31:
	/* 0x4d31: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_4d36:
	/* 0x4d36: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d39:
	/* 0x4d39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d3e:
	/* 0x4d3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d43:
	/* 0x4d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d45:
	/* 0x4d45: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d47:
	/* 0x4d47: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d4a:
	/* 0x4d4a: je     40f6 <generic_sleepable_preload+0x40f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16630ULL;
	}
x86_l_4d50:
	/* 0x4d50: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4d52:
	/* 0x4d52: jmp    416f <generic_sleepable_preload+0x416f> */
	return 16751ULL;
x86_l_4d57:
	/* 0x4d57: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4d5c:
	/* 0x4d5c: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_4d5e:
	/* 0x4d5e: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4d63:
	/* 0x4d63: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4d68:
	/* 0x4d68: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4d6d:
	/* 0x4d6d: jmp    4d7e <generic_sleepable_preload+0x4d7e> */
	goto x86_l_4d7e;
x86_l_4d6f:
	/* 0x4d6f: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_4d74:
	/* 0x4d74: jmp    4e05 <generic_sleepable_preload+0x4e05> */
	return 19973ULL;
x86_l_4d79:
	/* 0x4d79: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4d7e:
	/* 0x4d7e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d81:
	/* 0x4d81: mov    ebx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d84:
	/* 0x4d84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d89:
	/* 0x4d89: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d8e:
	/* 0x4d8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d93:
	/* 0x4d93: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
	return 19862ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19862ULL: goto x86_l_4d96;
	case 19864ULL: goto x86_l_4d98;
	case 19867ULL: goto x86_l_4d9b;
	case 19873ULL: goto x86_l_4da1;
	case 19878ULL: goto x86_l_4da6;
	case 19883ULL: goto x86_l_4dab;
	case 19885ULL: goto x86_l_4dad;
	case 19890ULL: goto x86_l_4db2;
	case 19898ULL: goto x86_l_4dba;
	case 19903ULL: goto x86_l_4dbf;
	case 19910ULL: goto x86_l_4dc6;
	case 19915ULL: goto x86_l_4dcb;
	case 19917ULL: goto x86_l_4dcd;
	case 19920ULL: goto x86_l_4dd0;
	case 19926ULL: goto x86_l_4dd6;
	case 19932ULL: goto x86_l_4ddc;
	case 19935ULL: goto x86_l_4ddf;
	case 19942ULL: goto x86_l_4de6;
	case 19947ULL: goto x86_l_4deb;
	case 19950ULL: goto x86_l_4dee;
	case 19953ULL: goto x86_l_4df1;
	case 19956ULL: goto x86_l_4df4;
	case 19958ULL: goto x86_l_4df6;
	case 19961ULL: goto x86_l_4df9;
	case 19966ULL: goto x86_l_4dfe;
	case 19968ULL: goto x86_l_4e00;
	case 19973ULL: goto x86_l_4e05;
	case 19976ULL: goto x86_l_4e08;
	case 19979ULL: goto x86_l_4e0b;
	case 19985ULL: goto x86_l_4e11;
	case 19990ULL: goto x86_l_4e16;
	case 19995ULL: goto x86_l_4e1b;
	case 19997ULL: goto x86_l_4e1d;
	case 20002ULL: goto x86_l_4e22;
	case 20010ULL: goto x86_l_4e2a;
	case 20015ULL: goto x86_l_4e2f;
	case 20022ULL: goto x86_l_4e36;
	case 20027ULL: goto x86_l_4e3b;
	case 20029ULL: goto x86_l_4e3d;
	case 20032ULL: goto x86_l_4e40;
	case 20034ULL: goto x86_l_4e42;
	case 20040ULL: goto x86_l_4e48;
	case 20043ULL: goto x86_l_4e4b;
	case 20050ULL: goto x86_l_4e52;
	case 20055ULL: goto x86_l_4e57;
	case 20058ULL: goto x86_l_4e5a;
	case 20061ULL: goto x86_l_4e5d;
	case 20064ULL: goto x86_l_4e60;
	case 20066ULL: goto x86_l_4e62;
	case 20069ULL: goto x86_l_4e65;
	case 20074ULL: goto x86_l_4e6a;
	case 20077ULL: goto x86_l_4e6d;
	case 20080ULL: goto x86_l_4e70;
	case 20083ULL: goto x86_l_4e73;
	case 20085ULL: goto x86_l_4e75;
	case 20088ULL: goto x86_l_4e78;
	case 20090ULL: goto x86_l_4e7a;
	case 20093ULL: goto x86_l_4e7d;
	case 20095ULL: goto x86_l_4e7f;
	case 20098ULL: goto x86_l_4e82;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20110ULL: goto x86_l_4e8e;
	case 20112ULL: goto x86_l_4e90;
	case 20115ULL: goto x86_l_4e93;
	case 20120ULL: goto x86_l_4e98;
	case 20122ULL: goto x86_l_4e9a;
	case 20125ULL: goto x86_l_4e9d;
	case 20127ULL: goto x86_l_4e9f;
	case 20132ULL: goto x86_l_4ea4;
	case 20135ULL: goto x86_l_4ea7;
	case 20137ULL: goto x86_l_4ea9;
	case 20142ULL: goto x86_l_4eae;
	case 20145ULL: goto x86_l_4eb1;
	case 20150ULL: goto x86_l_4eb6;
	case 20152ULL: goto x86_l_4eb8;
	case 20154ULL: goto x86_l_4eba;
	case 20161ULL: goto x86_l_4ec1;
	case 20163ULL: goto x86_l_4ec3;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20171ULL: goto x86_l_4ecb;
	case 20173ULL: goto x86_l_4ecd;
	case 20180ULL: goto x86_l_4ed4;
	case 20182ULL: goto x86_l_4ed6;
	case 20185ULL: goto x86_l_4ed9;
	case 20191ULL: goto x86_l_4edf;
	case 20194ULL: goto x86_l_4ee2;
	case 20199ULL: goto x86_l_4ee7;
	case 20205ULL: goto x86_l_4eed;
	case 20208ULL: goto x86_l_4ef0;
	case 20214ULL: goto x86_l_4ef6;
	case 20220ULL: goto x86_l_4efc;
	case 20225ULL: goto x86_l_4f01;
	case 20228ULL: goto x86_l_4f04;
	case 20233ULL: goto x86_l_4f09;
	case 20238ULL: goto x86_l_4f0e;
	case 20243ULL: goto x86_l_4f13;
	case 20245ULL: goto x86_l_4f15;
	case 20250ULL: goto x86_l_4f1a;
	case 20252ULL: goto x86_l_4f1c;
	case 20258ULL: goto x86_l_4f22;
	case 20260ULL: goto x86_l_4f24;
	case 20265ULL: goto x86_l_4f29;
	case 20272ULL: goto x86_l_4f30;
	case 20279ULL: goto x86_l_4f37;
	case 20285ULL: goto x86_l_4f3d;
	case 20287ULL: goto x86_l_4f3f;
	case 20290ULL: goto x86_l_4f42;
	case 20296ULL: goto x86_l_4f48;
	case 20299ULL: goto x86_l_4f4b;
	case 20305ULL: goto x86_l_4f51;
	case 20308ULL: goto x86_l_4f54;
	case 20314ULL: goto x86_l_4f5a;
	case 20322ULL: goto x86_l_4f62;
	case 20325ULL: goto x86_l_4f65;
	case 20331ULL: goto x86_l_4f6b;
	case 20336ULL: goto x86_l_4f70;
	case 20339ULL: goto x86_l_4f73;
	case 20345ULL: goto x86_l_4f79;
	case 20350ULL: goto x86_l_4f7e;
	case 20353ULL: goto x86_l_4f81;
	case 20359ULL: goto x86_l_4f87;
	case 20364ULL: goto x86_l_4f8c;
	case 20367ULL: goto x86_l_4f8f;
	case 20372ULL: goto x86_l_4f94;
	case 20378ULL: goto x86_l_4f9a;
	case 20381ULL: goto x86_l_4f9d;
	case 20387ULL: goto x86_l_4fa3;
	case 20393ULL: goto x86_l_4fa9;
	case 20398ULL: goto x86_l_4fae;
	case 20401ULL: goto x86_l_4fb1;
	case 20406ULL: goto x86_l_4fb6;
	case 20409ULL: goto x86_l_4fb9;
	case 20414ULL: goto x86_l_4fbe;
	case 20419ULL: goto x86_l_4fc3;
	case 20422ULL: goto x86_l_4fc6;
	case 20424ULL: goto x86_l_4fc8;
	case 20426ULL: goto x86_l_4fca;
	case 20432ULL: goto x86_l_4fd0;
	case 20437ULL: goto x86_l_4fd5;
	case 20442ULL: goto x86_l_4fda;
	case 20449ULL: goto x86_l_4fe1;
	case 20454ULL: goto x86_l_4fe6;
	case 20457ULL: goto x86_l_4fe9;
	case 20459ULL: goto x86_l_4feb;
	case 20462ULL: goto x86_l_4fee;
	case 20468ULL: goto x86_l_4ff4;
	case 20470ULL: goto x86_l_4ff6;
	case 20476ULL: goto x86_l_4ffc;
	case 20479ULL: goto x86_l_4fff;
	case 20482ULL: goto x86_l_5002;
	case 20488ULL: goto x86_l_5008;
	case 20493ULL: goto x86_l_500d;
	case 20496ULL: goto x86_l_5010;
	case 20502ULL: goto x86_l_5016;
	case 20510ULL: goto x86_l_501e;
	case 20513ULL: goto x86_l_5021;
	case 20519ULL: goto x86_l_5027;
	case 20524ULL: goto x86_l_502c;
	case 20527ULL: goto x86_l_502f;
	case 20533ULL: goto x86_l_5035;
	case 20538ULL: goto x86_l_503a;
	case 20541ULL: goto x86_l_503d;
	case 20547ULL: goto x86_l_5043;
	case 20555ULL: goto x86_l_504b;
	case 20558ULL: goto x86_l_504e;
	case 20564ULL: goto x86_l_5054;
	case 20569ULL: goto x86_l_5059;
	case 20572ULL: goto x86_l_505c;
	case 20578ULL: goto x86_l_5062;
	case 20583ULL: goto x86_l_5067;
	case 20590ULL: goto x86_l_506e;
	case 20595ULL: goto x86_l_5073;
	case 20602ULL: goto x86_l_507a;
	case 20609ULL: goto x86_l_5081;
	case 20616ULL: goto x86_l_5088;
	case 20621ULL: goto x86_l_508d;
	case 20626ULL: goto x86_l_5092;
	case 20630ULL: goto x86_l_5096;
	case 20632ULL: goto x86_l_5098;
	case 20638ULL: goto x86_l_509e;
	case 20644ULL: goto x86_l_50a4;
	case 20647ULL: goto x86_l_50a7;
	case 20652ULL: goto x86_l_50ac;
	case 20655ULL: goto x86_l_50af;
	case 20660ULL: goto x86_l_50b4;
	case 20665ULL: goto x86_l_50b9;
	case 20667ULL: goto x86_l_50bb;
	case 20669ULL: goto x86_l_50bd;
	case 20671ULL: goto x86_l_50bf;
	case 20677ULL: goto x86_l_50c5;
	case 20682ULL: goto x86_l_50ca;
	case 20685ULL: goto x86_l_50cd;
	case 20690ULL: goto x86_l_50d2;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20703ULL: goto x86_l_50df;
	case 20705ULL: goto x86_l_50e1;
	case 20707ULL: goto x86_l_50e3;
	case 20713ULL: goto x86_l_50e9;
	case 20715ULL: goto x86_l_50eb;
	case 20718ULL: goto x86_l_50ee;
	case 20723ULL: goto x86_l_50f3;
	case 20725ULL: goto x86_l_50f5;
	case 20728ULL: goto x86_l_50f8;
	case 20736ULL: goto x86_l_5100;
	case 20742ULL: goto x86_l_5106;
	case 20749ULL: goto x86_l_510d;
	case 20752ULL: goto x86_l_5110;
	case 20758ULL: goto x86_l_5116;
	case 20761ULL: goto x86_l_5119;
	case 20766ULL: goto x86_l_511e;
	case 20773ULL: goto x86_l_5125;
	case 20775ULL: goto x86_l_5127;
	case 20781ULL: goto x86_l_512d;
	case 20784ULL: goto x86_l_5130;
	case 20786ULL: goto x86_l_5132;
	case 20791ULL: goto x86_l_5137;
	case 20796ULL: goto x86_l_513c;
	case 20801ULL: goto x86_l_5141;
	case 20806ULL: goto x86_l_5146;
	case 20808ULL: goto x86_l_5148;
	case 20813ULL: goto x86_l_514d;
	case 20815ULL: goto x86_l_514f;
	case 20821ULL: goto x86_l_5155;
	case 20829ULL: goto x86_l_515d;
	case 20835ULL: goto x86_l_5163;
	case 20841ULL: goto x86_l_5169;
	case 20846ULL: goto x86_l_516e;
	case 20854ULL: goto x86_l_5176;
	case 20856ULL: goto x86_l_5178;
	case 20861ULL: goto x86_l_517d;
	case 20866ULL: goto x86_l_5182;
	case 20871ULL: goto x86_l_5187;
	case 20876ULL: goto x86_l_518c;
	case 20878ULL: goto x86_l_518e;
	case 20883ULL: goto x86_l_5193;
	case 20885ULL: goto x86_l_5195;
	case 20891ULL: goto x86_l_519b;
	case 20899ULL: goto x86_l_51a3;
	case 20905ULL: goto x86_l_51a9;
	case 20911ULL: goto x86_l_51af;
	case 20916ULL: goto x86_l_51b4;
	case 20924ULL: goto x86_l_51bc;
	case 20926ULL: goto x86_l_51be;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20941ULL: goto x86_l_51cd;
	case 20946ULL: goto x86_l_51d2;
	case 20948ULL: goto x86_l_51d4;
	case 20953ULL: goto x86_l_51d9;
	case 20955ULL: goto x86_l_51db;
	case 20961ULL: goto x86_l_51e1;
	case 20969ULL: goto x86_l_51e9;
	case 20975ULL: goto x86_l_51ef;
	case 20981ULL: goto x86_l_51f5;
	case 20986ULL: goto x86_l_51fa;
	case 20994ULL: goto x86_l_5202;
	case 20996ULL: goto x86_l_5204;
	case 21001ULL: goto x86_l_5209;
	case 21006ULL: goto x86_l_520e;
	case 21011ULL: goto x86_l_5213;
	case 21016ULL: goto x86_l_5218;
	case 21018ULL: goto x86_l_521a;
	case 21023ULL: goto x86_l_521f;
	case 21025ULL: goto x86_l_5221;
	case 21031ULL: goto x86_l_5227;
	case 21039ULL: goto x86_l_522f;
	case 21045ULL: goto x86_l_5235;
	case 21051ULL: goto x86_l_523b;
	case 21056ULL: goto x86_l_5240;
	case 21064ULL: goto x86_l_5248;
	case 21066ULL: goto x86_l_524a;
	case 21071ULL: goto x86_l_524f;
	case 21076ULL: goto x86_l_5254;
	case 21081ULL: goto x86_l_5259;
	case 21086ULL: goto x86_l_525e;
	case 21088ULL: goto x86_l_5260;
	case 21093ULL: goto x86_l_5265;
	case 21095ULL: goto x86_l_5267;
	case 21101ULL: goto x86_l_526d;
	case 21109ULL: goto x86_l_5275;
	case 21115ULL: goto x86_l_527b;
	case 21121ULL: goto x86_l_5281;
	case 21126ULL: goto x86_l_5286;
	case 21134ULL: goto x86_l_528e;
	case 21136ULL: goto x86_l_5290;
	case 21141ULL: goto x86_l_5295;
	case 21146ULL: goto x86_l_529a;
	case 21151ULL: goto x86_l_529f;
	case 21156ULL: goto x86_l_52a4;
	case 21158ULL: goto x86_l_52a6;
	case 21163ULL: goto x86_l_52ab;
	case 21165ULL: goto x86_l_52ad;
	case 21171ULL: goto x86_l_52b3;
	case 21179ULL: goto x86_l_52bb;
	case 21185ULL: goto x86_l_52c1;
	case 21191ULL: goto x86_l_52c7;
	case 21196ULL: goto x86_l_52cc;
	case 21204ULL: goto x86_l_52d4;
	case 21206ULL: goto x86_l_52d6;
	case 21211ULL: goto x86_l_52db;
	case 21216ULL: goto x86_l_52e0;
	case 21221ULL: goto x86_l_52e5;
	case 21226ULL: goto x86_l_52ea;
	case 21228ULL: goto x86_l_52ec;
	case 21230ULL: goto x86_l_52ee;
	case 21236ULL: goto x86_l_52f4;
	case 21241ULL: goto x86_l_52f9;
	case 21249ULL: goto x86_l_5301;
	case 21255ULL: goto x86_l_5307;
	case 21261ULL: goto x86_l_530d;
	case 21266ULL: goto x86_l_5312;
	case 21274ULL: goto x86_l_531a;
	case 21276ULL: goto x86_l_531c;
	case 21281ULL: goto x86_l_5321;
	case 21286ULL: goto x86_l_5326;
	case 21291ULL: goto x86_l_532b;
	case 21296ULL: goto x86_l_5330;
	case 21298ULL: goto x86_l_5332;
	case 21300ULL: goto x86_l_5334;
	case 21306ULL: goto x86_l_533a;
	case 21311ULL: goto x86_l_533f;
	case 21319ULL: goto x86_l_5347;
	case 21325ULL: goto x86_l_534d;
	case 21331ULL: goto x86_l_5353;
	case 21336ULL: goto x86_l_5358;
	case 21344ULL: goto x86_l_5360;
	case 21346ULL: goto x86_l_5362;
	case 21351ULL: goto x86_l_5367;
	case 21356ULL: goto x86_l_536c;
	case 21361ULL: goto x86_l_5371;
	case 21366ULL: goto x86_l_5376;
	case 21368ULL: goto x86_l_5378;
	case 21370ULL: goto x86_l_537a;
	case 21376ULL: goto x86_l_5380;
	case 21381ULL: goto x86_l_5385;
	case 21389ULL: goto x86_l_538d;
	case 21395ULL: goto x86_l_5393;
	case 21401ULL: goto x86_l_5399;
	case 21406ULL: goto x86_l_539e;
	case 21414ULL: goto x86_l_53a6;
	case 21420ULL: goto x86_l_53ac;
	case 21425ULL: goto x86_l_53b1;
	case 21430ULL: goto x86_l_53b6;
	case 21433ULL: goto x86_l_53b9;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21445ULL: goto x86_l_53c5;
	case 21450ULL: goto x86_l_53ca;
	case 21455ULL: goto x86_l_53cf;
	case 21457ULL: goto x86_l_53d1;
	case 21462ULL: goto x86_l_53d6;
	case 21464ULL: goto x86_l_53d8;
	case 21470ULL: goto x86_l_53de;
	case 21478ULL: goto x86_l_53e6;
	case 21484ULL: goto x86_l_53ec;
	case 21490ULL: goto x86_l_53f2;
	case 21495ULL: goto x86_l_53f7;
	case 21503ULL: goto x86_l_53ff;
	case 21505ULL: goto x86_l_5401;
	case 21510ULL: goto x86_l_5406;
	case 21515ULL: goto x86_l_540b;
	case 21520ULL: goto x86_l_5410;
	case 21525ULL: goto x86_l_5415;
	case 21527ULL: goto x86_l_5417;
	case 21532ULL: goto x86_l_541c;
	case 21534ULL: goto x86_l_541e;
	case 21540ULL: goto x86_l_5424;
	case 21548ULL: goto x86_l_542c;
	case 21554ULL: goto x86_l_5432;
	case 21560ULL: goto x86_l_5438;
	case 21565ULL: goto x86_l_543d;
	case 21573ULL: goto x86_l_5445;
	case 21575ULL: goto x86_l_5447;
	case 21580ULL: goto x86_l_544c;
	case 21585ULL: goto x86_l_5451;
	case 21590ULL: goto x86_l_5456;
	case 21595ULL: goto x86_l_545b;
	case 21597ULL: goto x86_l_545d;
	case 21602ULL: goto x86_l_5462;
	case 21604ULL: goto x86_l_5464;
	case 21610ULL: goto x86_l_546a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4d96:
	/* 0x4d96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d98:
	/* 0x4d98: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4d9b:
	/* 0x4d9b: jne    4ea9 <generic_sleepable_preload+0x4ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ea9;
	}
x86_l_4da1:
	/* 0x4da1: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4da6:
	/* 0x4da6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4dab:
	/* 0x4dab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dad:
	/* 0x4dad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4db2:
	/* 0x4db2: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4dba:
	/* 0x4dba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4dbf:
	/* 0x4dbf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4dc6:
	/* 0x4dc6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dcb:
	/* 0x4dcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dcd:
	/* 0x4dcd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4dd0:
	/* 0x4dd0: je     4ea9 <generic_sleepable_preload+0x4ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea9;
	}
x86_l_4dd6:
	/* 0x4dd6: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4ddc:
	/* 0x4ddc: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4ddf:
	/* 0x4ddf: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4de6:
	/* 0x4de6: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4deb:
	/* 0x4deb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4dee:
	/* 0x4dee: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4df1:
	/* 0x4df1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4df4:
	/* 0x4df4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4df6:
	/* 0x4df6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4df9:
	/* 0x4df9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4dfe:
	/* 0x4dfe: jmp    4e6a <generic_sleepable_preload+0x4e6a> */
	goto x86_l_4e6a;
x86_l_4e00:
	/* 0x4e00: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_4e05:
	/* 0x4e05: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e08:
	/* 0x4e08: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_4e0b:
	/* 0x4e0b: jne    4eae <generic_sleepable_preload+0x4eae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4eae;
	}
x86_l_4e11:
	/* 0x4e11: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e16:
	/* 0x4e16: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4e1b:
	/* 0x4e1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e1d:
	/* 0x4e1d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e22:
	/* 0x4e22: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e2a:
	/* 0x4e2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e2f:
	/* 0x4e2f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_4e36:
	/* 0x4e36: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e3b:
	/* 0x4e3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e3d:
	/* 0x4e3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e40:
	/* 0x4e40: je     4ea9 <generic_sleepable_preload+0x4ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea9;
	}
x86_l_4e42:
	/* 0x4e42: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_4e48:
	/* 0x4e48: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_4e4b:
	/* 0x4e4b: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_4e52:
	/* 0x4e52: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e57:
	/* 0x4e57: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4e5a:
	/* 0x4e5a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4e5d:
	/* 0x4e5d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4e60:
	/* 0x4e60: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e62:
	/* 0x4e62: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4e65:
	/* 0x4e65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e6a:
	/* 0x4e6a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4e6d:
	/* 0x4e6d: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_4e70:
	/* 0x4e70: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4e73:
	/* 0x4e73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e75:
	/* 0x4e75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e78:
	/* 0x4e78: je     4ea9 <generic_sleepable_preload+0x4ea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea9;
	}
x86_l_4e7a:
	/* 0x4e7a: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_4e7d:
	/* 0x4e7d: je     4ea7 <generic_sleepable_preload+0x4ea7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ea7;
	}
x86_l_4e7f:
	/* 0x4e7f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4e82:
	/* 0x4e82: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e86:
	/* 0x4e86: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e8b:
	/* 0x4e8b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_4e8e:
	/* 0x4e8e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e90:
	/* 0x4e90: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4e93:
	/* 0x4e93: call   4e98 <generic_sleepable_preload+0x4e98> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_4e98:
	/* 0x4e98: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4e9a:
	/* 0x4e9a: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_4e9d:
	/* 0x4e9d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4e9f:
	/* 0x4e9f: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_4ea4:
	/* 0x4ea4: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_4ea7:
	/* 0x4ea7: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ea9:
	/* 0x4ea9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4eae:
	/* 0x4eae: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4eb1:
	/* 0x4eb1: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_4eb6:
	/* 0x4eb6: jne    4ec9 <generic_sleepable_preload+0x4ec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ec9;
	}
x86_l_4eb8:
	/* 0x4eb8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4eba:
	/* 0x4eba: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_4ec1:
	/* 0x4ec1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_4ec3:
	/* 0x4ec3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_4ec4:
	/* 0x4ec4: jmp    611b <generic_sleepable_preload+0x611b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4ec9:
	/* 0x4ec9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4ecb:
	/* 0x4ecb: js     4f29 <generic_sleepable_preload+0x4f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4f29;
	}
x86_l_4ecd:
	/* 0x4ecd: movzx  ecx,BYTE PTR [rdi+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_4ed4:
	/* 0x4ed4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ed6:
	/* 0x4ed6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4ed9:
	/* 0x4ed9: jg     4f8c <generic_sleepable_preload+0x4f8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4f8c;
	}
x86_l_4edf:
	/* 0x4edf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ee2:
	/* 0x4ee2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ee7:
	/* 0x4ee7: je     5067 <generic_sleepable_preload+0x5067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5067;
	}
x86_l_4eed:
	/* 0x4eed: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4ef0:
	/* 0x4ef0: jne    50ee <generic_sleepable_preload+0x50ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50ee;
	}
x86_l_4ef6:
	/* 0x4ef6: mov    eax,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_4efc:
	/* 0x4efc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f01:
	/* 0x4f01: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f04:
	/* 0x4f04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f09:
	/* 0x4f09: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f0e:
	/* 0x4f0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f13:
	/* 0x4f13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f15:
	/* 0x4f15: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f1a:
	/* 0x4f1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f1c:
	/* 0x4f1c: je     5073 <generic_sleepable_preload+0x5073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5073;
	}
x86_l_4f22:
	/* 0x4f22: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f24:
	/* 0x4f24: jmp    50ee <generic_sleepable_preload+0x50ee> */
	goto x86_l_50ee;
x86_l_4f29:
	/* 0x4f29: movzx  ecx,BYTE PTR [rdi+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4f30:
	/* 0x4f30: movzx  eax,WORD PTR [rdi+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4f37:
	/* 0x4f37: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_4f3d:
	/* 0x4f3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f3f:
	/* 0x4f3f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4f42:
	/* 0x4f42: jle    4fe6 <generic_sleepable_preload+0x4fe6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4fe6;
	}
x86_l_4f48:
	/* 0x4f48: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4f4b:
	/* 0x4f4b: jle    500d <generic_sleepable_preload+0x500d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_500d;
	}
x86_l_4f51:
	/* 0x4f51: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4f54:
	/* 0x4f54: jle    56b4 <generic_sleepable_preload+0x56b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 22196ULL;
	}
x86_l_4f5a:
	/* 0x4f5a: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4f62:
	/* 0x4f62: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4f65:
	/* 0x4f65: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_4f6b:
	/* 0x4f6b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4f70:
	/* 0x4f70: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4f73:
	/* 0x4f73: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_4f79:
	/* 0x4f79: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4f7e:
	/* 0x4f7e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4f81:
	/* 0x4f81: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_4f87:
	/* 0x4f87: jmp    56ef <generic_sleepable_preload+0x56ef> */
	return 22255ULL;
x86_l_4f8c:
	/* 0x4f8c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4f8f:
	/* 0x4f8f: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f94:
	/* 0x4f94: je     5098 <generic_sleepable_preload+0x5098> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5098;
	}
x86_l_4f9a:
	/* 0x4f9a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4f9d:
	/* 0x4f9d: jne    50ee <generic_sleepable_preload+0x50ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50ee;
	}
x86_l_4fa3:
	/* 0x4fa3: mov    eax,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_4fa9:
	/* 0x4fa9: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4fae:
	/* 0x4fae: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fb1:
	/* 0x4fb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fb6:
	/* 0x4fb6: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4fb9:
	/* 0x4fb9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fbe:
	/* 0x4fbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fc3:
	/* 0x4fc3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4fc6:
	/* 0x4fc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fc8:
	/* 0x4fc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fca:
	/* 0x4fca: jne    50e9 <generic_sleepable_preload+0x50e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50e9;
	}
x86_l_4fd0:
	/* 0x4fd0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_4fd5:
	/* 0x4fd5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fda:
	/* 0x4fda: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_4fe1:
	/* 0x4fe1: jmp    5ca8 <generic_sleepable_preload+0x5ca8> */
	return 23720ULL;
x86_l_4fe6:
	/* 0x4fe6: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4fe9:
	/* 0x4fe9: jg     503a <generic_sleepable_preload+0x503a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_503a;
	}
x86_l_4feb:
	/* 0x4feb: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4fee:
	/* 0x4fee: jg     5685 <generic_sleepable_preload+0x5685> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22149ULL;
	}
x86_l_4ff4:
	/* 0x4ff4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4ff6:
	/* 0x4ff6: je     56d7 <generic_sleepable_preload+0x56d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22231ULL;
	}
x86_l_4ffc:
	/* 0x4ffc: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4fff:
	/* 0x4fff: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_5002:
	/* 0x5002: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_5008:
	/* 0x5008: jmp    56ef <generic_sleepable_preload+0x56ef> */
	return 22255ULL;
x86_l_500d:
	/* 0x500d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_5010:
	/* 0x5010: jg     566c <generic_sleepable_preload+0x566c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22124ULL;
	}
x86_l_5016:
	/* 0x5016: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_501e:
	/* 0x501e: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5021:
	/* 0x5021: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_5027:
	/* 0x5027: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_502c:
	/* 0x502c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_502f:
	/* 0x502f: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_5035:
	/* 0x5035: jmp    56ef <generic_sleepable_preload+0x56ef> */
	return 22255ULL;
x86_l_503a:
	/* 0x503a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_503d:
	/* 0x503d: jg     569b <generic_sleepable_preload+0x569b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 22171ULL;
	}
x86_l_5043:
	/* 0x5043: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_504b:
	/* 0x504b: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_504e:
	/* 0x504e: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_5054:
	/* 0x5054: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5059:
	/* 0x5059: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_505c:
	/* 0x505c: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22236ULL;
	}
x86_l_5062:
	/* 0x5062: jmp    56ef <generic_sleepable_preload+0x56ef> */
	return 22255ULL;
x86_l_5067:
	/* 0x5067: mov    rax,QWORD PTR [rdi+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_506e:
	/* 0x506e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5073:
	/* 0x5073: movzx  eax,BYTE PTR [rdi+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_507a:
	/* 0x507a: shlx   rcx,QWORD PTR [rsp+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((32ULL << 32) | X86_ALU_SHL));
x86_l_5081:
	/* 0x5081: cmp    BYTE PTR [rdi+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_5088:
	/* 0x5088: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_508d:
	/* 0x508d: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_5092:
	/* 0x5092: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_5096:
	/* 0x5096: jmp    50ee <generic_sleepable_preload+0x50ee> */
	goto x86_l_50ee;
x86_l_5098:
	/* 0x5098: mov    edx,DWORD PTR [rdi+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_509e:
	/* 0x509e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50a4:
	/* 0x50a4: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50a7:
	/* 0x50a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50ac:
	/* 0x50ac: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_50af:
	/* 0x50af: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50b4:
	/* 0x50b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50b9:
	/* 0x50b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50bb:
	/* 0x50bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50bd:
	/* 0x50bd: jne    50e9 <generic_sleepable_preload+0x50e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50e9;
	}
x86_l_50bf:
	/* 0x50bf: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_50c5:
	/* 0x50c5: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50ca:
	/* 0x50ca: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50cd:
	/* 0x50cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50d2:
	/* 0x50d2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50d7:
	/* 0x50d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50dc:
	/* 0x50dc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_50df:
	/* 0x50df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e1:
	/* 0x50e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50e3:
	/* 0x50e3: je     5c86 <generic_sleepable_preload+0x5c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23686ULL;
	}
x86_l_50e9:
	/* 0x50e9: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_50eb:
	/* 0x50eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_50ee:
	/* 0x50ee: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50f3:
	/* 0x50f3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50f5:
	/* 0x50f5: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_50f8:
	/* 0x50f8: cmp    WORD PTR [rdi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5100:
	/* 0x5100: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5106:
	/* 0x5106: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_510d:
	/* 0x510d: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5110:
	/* 0x5110: mov    edx,DWORD PTR [rdi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_5116:
	/* 0x5116: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5119:
	/* 0x5119: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_511e:
	/* 0x511e: movzx  eax,WORD PTR [rdi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5125:
	/* 0x5125: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_5127:
	/* 0x5127: je     53b6 <generic_sleepable_preload+0x53b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53b6;
	}
x86_l_512d:
	/* 0x512d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5130:
	/* 0x5130: je     5155 <generic_sleepable_preload+0x5155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5155;
	}
x86_l_5132:
	/* 0x5132: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5137:
	/* 0x5137: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_513c:
	/* 0x513c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5141:
	/* 0x5141: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5146:
	/* 0x5146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5148:
	/* 0x5148: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_514d:
	/* 0x514d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_514f:
	/* 0x514f: js     5662 <generic_sleepable_preload+0x5662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22114ULL;
	}
x86_l_5155:
	/* 0x5155: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_515d:
	/* 0x515d: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5163:
	/* 0x5163: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_5169:
	/* 0x5169: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_516e:
	/* 0x516e: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5176:
	/* 0x5176: je     519b <generic_sleepable_preload+0x519b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_519b;
	}
x86_l_5178:
	/* 0x5178: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_517d:
	/* 0x517d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5182:
	/* 0x5182: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5187:
	/* 0x5187: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_518c:
	/* 0x518c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518e:
	/* 0x518e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5193:
	/* 0x5193: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5195:
	/* 0x5195: js     56cd <generic_sleepable_preload+0x56cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22221ULL;
	}
x86_l_519b:
	/* 0x519b: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_51a3:
	/* 0x51a3: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_51a9:
	/* 0x51a9: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_51af:
	/* 0x51af: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_51b4:
	/* 0x51b4: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_51bc:
	/* 0x51bc: je     51e1 <generic_sleepable_preload+0x51e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_51e1;
	}
x86_l_51be:
	/* 0x51be: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_51c3:
	/* 0x51c3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51c8:
	/* 0x51c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51cd:
	/* 0x51cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51d2:
	/* 0x51d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d4:
	/* 0x51d4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51d9:
	/* 0x51d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_51db:
	/* 0x51db: js     5c75 <generic_sleepable_preload+0x5c75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23669ULL;
	}
x86_l_51e1:
	/* 0x51e1: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_51e9:
	/* 0x51e9: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_51ef:
	/* 0x51ef: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_51f5:
	/* 0x51f5: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_51fa:
	/* 0x51fa: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5202:
	/* 0x5202: je     5227 <generic_sleepable_preload+0x5227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5227;
	}
x86_l_5204:
	/* 0x5204: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5209:
	/* 0x5209: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_520e:
	/* 0x520e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5213:
	/* 0x5213: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5218:
	/* 0x5218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_521a:
	/* 0x521a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_521f:
	/* 0x521f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5221:
	/* 0x5221: js     5cc6 <generic_sleepable_preload+0x5cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23750ULL;
	}
x86_l_5227:
	/* 0x5227: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_522f:
	/* 0x522f: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5235:
	/* 0x5235: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_523b:
	/* 0x523b: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5240:
	/* 0x5240: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5248:
	/* 0x5248: je     526d <generic_sleepable_preload+0x526d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_526d;
	}
x86_l_524a:
	/* 0x524a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_524f:
	/* 0x524f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5254:
	/* 0x5254: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5259:
	/* 0x5259: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_525e:
	/* 0x525e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5260:
	/* 0x5260: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5265:
	/* 0x5265: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5267:
	/* 0x5267: js     5cd7 <generic_sleepable_preload+0x5cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23767ULL;
	}
x86_l_526d:
	/* 0x526d: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5275:
	/* 0x5275: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_527b:
	/* 0x527b: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5281:
	/* 0x5281: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5286:
	/* 0x5286: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_528e:
	/* 0x528e: je     52b3 <generic_sleepable_preload+0x52b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52b3;
	}
x86_l_5290:
	/* 0x5290: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5295:
	/* 0x5295: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_529a:
	/* 0x529a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_529f:
	/* 0x529f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52a4:
	/* 0x52a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52a6:
	/* 0x52a6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52ab:
	/* 0x52ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ad:
	/* 0x52ad: js     5ce8 <generic_sleepable_preload+0x5ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23784ULL;
	}
x86_l_52b3:
	/* 0x52b3: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_52bb:
	/* 0x52bb: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_52c1:
	/* 0x52c1: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_52c7:
	/* 0x52c7: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_52cc:
	/* 0x52cc: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_52d4:
	/* 0x52d4: je     52f4 <generic_sleepable_preload+0x52f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_52f4;
	}
x86_l_52d6:
	/* 0x52d6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_52db:
	/* 0x52db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52e0:
	/* 0x52e0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52e5:
	/* 0x52e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52ea:
	/* 0x52ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ec:
	/* 0x52ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52ee:
	/* 0x52ee: js     5e09 <generic_sleepable_preload+0x5e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24073ULL;
	}
x86_l_52f4:
	/* 0x52f4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52f9:
	/* 0x52f9: cmp    WORD PTR [rdi+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5301:
	/* 0x5301: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5307:
	/* 0x5307: mov    eax,DWORD PTR [rdi+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_530d:
	/* 0x530d: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5312:
	/* 0x5312: cmp    WORD PTR [rdi+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_531a:
	/* 0x531a: je     533a <generic_sleepable_preload+0x533a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_533a;
	}
x86_l_531c:
	/* 0x531c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5321:
	/* 0x5321: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5326:
	/* 0x5326: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_532b:
	/* 0x532b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5330:
	/* 0x5330: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5332:
	/* 0x5332: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5334:
	/* 0x5334: js     5ecb <generic_sleepable_preload+0x5ecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24267ULL;
	}
x86_l_533a:
	/* 0x533a: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_533f:
	/* 0x533f: cmp    WORD PTR [rdi+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5347:
	/* 0x5347: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_534d:
	/* 0x534d: mov    eax,DWORD PTR [rdi+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5353:
	/* 0x5353: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5358:
	/* 0x5358: cmp    WORD PTR [rdi+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5360:
	/* 0x5360: je     5380 <generic_sleepable_preload+0x5380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5380;
	}
x86_l_5362:
	/* 0x5362: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5367:
	/* 0x5367: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_536c:
	/* 0x536c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5371:
	/* 0x5371: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5376:
	/* 0x5376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5378:
	/* 0x5378: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_537a:
	/* 0x537a: js     5f83 <generic_sleepable_preload+0x5f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24451ULL;
	}
x86_l_5380:
	/* 0x5380: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5385:
	/* 0x5385: cmp    WORD PTR [rdi+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_538d:
	/* 0x538d: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5393:
	/* 0x5393: mov    eax,DWORD PTR [rdi+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5399:
	/* 0x5399: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_539e:
	/* 0x539e: cmp    WORD PTR [rdi+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_53a6:
	/* 0x53a6: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_53ac:
	/* 0x53ac: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53b1:
	/* 0x53b1: jmp    563a <generic_sleepable_preload+0x563a> */
	return 22074ULL;
x86_l_53b6:
	/* 0x53b6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_53b9:
	/* 0x53b9: je     53de <generic_sleepable_preload+0x53de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53de;
	}
x86_l_53bb:
	/* 0x53bb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53c0:
	/* 0x53c0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53c5:
	/* 0x53c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53ca:
	/* 0x53ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53cf:
	/* 0x53cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d1:
	/* 0x53d1: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53d6:
	/* 0x53d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53d8:
	/* 0x53d8: js     5662 <generic_sleepable_preload+0x5662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22114ULL;
	}
x86_l_53de:
	/* 0x53de: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_53e6:
	/* 0x53e6: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_53ec:
	/* 0x53ec: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_53f2:
	/* 0x53f2: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_53f7:
	/* 0x53f7: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_53ff:
	/* 0x53ff: je     5424 <generic_sleepable_preload+0x5424> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5424;
	}
x86_l_5401:
	/* 0x5401: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5406:
	/* 0x5406: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_540b:
	/* 0x540b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5410:
	/* 0x5410: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5415:
	/* 0x5415: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5417:
	/* 0x5417: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_541c:
	/* 0x541c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_541e:
	/* 0x541e: js     56cd <generic_sleepable_preload+0x56cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 22221ULL;
	}
x86_l_5424:
	/* 0x5424: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_542c:
	/* 0x542c: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5432:
	/* 0x5432: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5438:
	/* 0x5438: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_543d:
	/* 0x543d: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5445:
	/* 0x5445: je     546a <generic_sleepable_preload+0x546a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_546a;
	}
x86_l_5447:
	/* 0x5447: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_544c:
	/* 0x544c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5451:
	/* 0x5451: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5456:
	/* 0x5456: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_545b:
	/* 0x545b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_545d:
	/* 0x545d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5462:
	/* 0x5462: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5464:
	/* 0x5464: js     5c75 <generic_sleepable_preload+0x5c75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23669ULL;
	}
x86_l_546a:
	/* 0x546a: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
	return 21618ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21618ULL: goto x86_l_5472;
	case 21624ULL: goto x86_l_5478;
	case 21630ULL: goto x86_l_547e;
	case 21635ULL: goto x86_l_5483;
	case 21643ULL: goto x86_l_548b;
	case 21645ULL: goto x86_l_548d;
	case 21650ULL: goto x86_l_5492;
	case 21655ULL: goto x86_l_5497;
	case 21660ULL: goto x86_l_549c;
	case 21665ULL: goto x86_l_54a1;
	case 21667ULL: goto x86_l_54a3;
	case 21672ULL: goto x86_l_54a8;
	case 21674ULL: goto x86_l_54aa;
	case 21680ULL: goto x86_l_54b0;
	case 21688ULL: goto x86_l_54b8;
	case 21694ULL: goto x86_l_54be;
	case 21700ULL: goto x86_l_54c4;
	case 21705ULL: goto x86_l_54c9;
	case 21713ULL: goto x86_l_54d1;
	case 21715ULL: goto x86_l_54d3;
	case 21720ULL: goto x86_l_54d8;
	case 21725ULL: goto x86_l_54dd;
	case 21730ULL: goto x86_l_54e2;
	case 21735ULL: goto x86_l_54e7;
	case 21737ULL: goto x86_l_54e9;
	case 21742ULL: goto x86_l_54ee;
	case 21744ULL: goto x86_l_54f0;
	case 21750ULL: goto x86_l_54f6;
	case 21758ULL: goto x86_l_54fe;
	case 21764ULL: goto x86_l_5504;
	case 21770ULL: goto x86_l_550a;
	case 21775ULL: goto x86_l_550f;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21790ULL: goto x86_l_551e;
	case 21795ULL: goto x86_l_5523;
	case 21800ULL: goto x86_l_5528;
	case 21805ULL: goto x86_l_552d;
	case 21807ULL: goto x86_l_552f;
	case 21812ULL: goto x86_l_5534;
	case 21814ULL: goto x86_l_5536;
	case 21820ULL: goto x86_l_553c;
	case 21828ULL: goto x86_l_5544;
	case 21834ULL: goto x86_l_554a;
	case 21840ULL: goto x86_l_5550;
	case 21845ULL: goto x86_l_5555;
	case 21853ULL: goto x86_l_555d;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21865ULL: goto x86_l_5569;
	case 21870ULL: goto x86_l_556e;
	case 21875ULL: goto x86_l_5573;
	case 21877ULL: goto x86_l_5575;
	case 21879ULL: goto x86_l_5577;
	case 21885ULL: goto x86_l_557d;
	case 21890ULL: goto x86_l_5582;
	case 21898ULL: goto x86_l_558a;
	case 21904ULL: goto x86_l_5590;
	case 21910ULL: goto x86_l_5596;
	case 21915ULL: goto x86_l_559b;
	case 21923ULL: goto x86_l_55a3;
	case 21925ULL: goto x86_l_55a5;
	case 21930ULL: goto x86_l_55aa;
	case 21935ULL: goto x86_l_55af;
	case 21940ULL: goto x86_l_55b4;
	case 21945ULL: goto x86_l_55b9;
	case 21947ULL: goto x86_l_55bb;
	case 21949ULL: goto x86_l_55bd;
	case 21955ULL: goto x86_l_55c3;
	case 21960ULL: goto x86_l_55c8;
	case 21968ULL: goto x86_l_55d0;
	case 21974ULL: goto x86_l_55d6;
	case 21980ULL: goto x86_l_55dc;
	case 21985ULL: goto x86_l_55e1;
	case 21993ULL: goto x86_l_55e9;
	case 21995ULL: goto x86_l_55eb;
	case 22000ULL: goto x86_l_55f0;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22015ULL: goto x86_l_55ff;
	case 22017ULL: goto x86_l_5601;
	case 22019ULL: goto x86_l_5603;
	case 22025ULL: goto x86_l_5609;
	case 22030ULL: goto x86_l_560e;
	case 22038ULL: goto x86_l_5616;
	case 22044ULL: goto x86_l_561c;
	case 22050ULL: goto x86_l_5622;
	case 22055ULL: goto x86_l_5627;
	case 22063ULL: goto x86_l_562f;
	case 22069ULL: goto x86_l_5635;
	case 22074ULL: goto x86_l_563a;
	case 22079ULL: goto x86_l_563f;
	case 22084ULL: goto x86_l_5644;
	case 22089ULL: goto x86_l_5649;
	case 22091ULL: goto x86_l_564b;
	case 22096ULL: goto x86_l_5650;
	case 22098ULL: goto x86_l_5652;
	case 22104ULL: goto x86_l_5658;
	case 22109ULL: goto x86_l_565d;
	case 22114ULL: goto x86_l_5662;
	case 22119ULL: goto x86_l_5667;
	case 22124ULL: goto x86_l_566c;
	case 22132ULL: goto x86_l_5674;
	case 22135ULL: goto x86_l_5677;
	case 22137ULL: goto x86_l_5679;
	case 22142ULL: goto x86_l_567e;
	case 22145ULL: goto x86_l_5681;
	case 22147ULL: goto x86_l_5683;
	case 22149ULL: goto x86_l_5685;
	case 22154ULL: goto x86_l_568a;
	case 22157ULL: goto x86_l_568d;
	case 22159ULL: goto x86_l_568f;
	case 22164ULL: goto x86_l_5694;
	case 22167ULL: goto x86_l_5697;
	case 22169ULL: goto x86_l_5699;
	case 22171ULL: goto x86_l_569b;
	case 22179ULL: goto x86_l_56a3;
	case 22182ULL: goto x86_l_56a6;
	case 22184ULL: goto x86_l_56a8;
	case 22189ULL: goto x86_l_56ad;
	case 22192ULL: goto x86_l_56b0;
	case 22194ULL: goto x86_l_56b2;
	case 22196ULL: goto x86_l_56b4;
	case 22204ULL: goto x86_l_56bc;
	case 22207ULL: goto x86_l_56bf;
	case 22209ULL: goto x86_l_56c1;
	case 22214ULL: goto x86_l_56c6;
	case 22217ULL: goto x86_l_56c9;
	case 22219ULL: goto x86_l_56cb;
	case 22221ULL: goto x86_l_56cd;
	case 22226ULL: goto x86_l_56d2;
	case 22231ULL: goto x86_l_56d7;
	case 22236ULL: goto x86_l_56dc;
	case 22239ULL: goto x86_l_56df;
	case 22241ULL: goto x86_l_56e1;
	case 22243ULL: goto x86_l_56e3;
	case 22248ULL: goto x86_l_56e8;
	case 22250ULL: goto x86_l_56ea;
	case 22255ULL: goto x86_l_56ef;
	case 22260ULL: goto x86_l_56f4;
	case 22263ULL: goto x86_l_56f7;
	case 22265ULL: goto x86_l_56f9;
	case 22268ULL: goto x86_l_56fc;
	case 22276ULL: goto x86_l_5704;
	case 22282ULL: goto x86_l_570a;
	case 22289ULL: goto x86_l_5711;
	case 22292ULL: goto x86_l_5714;
	case 22298ULL: goto x86_l_571a;
	case 22301ULL: goto x86_l_571d;
	case 22306ULL: goto x86_l_5722;
	case 22313ULL: goto x86_l_5729;
	case 22315ULL: goto x86_l_572b;
	case 22321ULL: goto x86_l_5731;
	case 22324ULL: goto x86_l_5734;
	case 22326ULL: goto x86_l_5736;
	case 22331ULL: goto x86_l_573b;
	case 22336ULL: goto x86_l_5740;
	case 22341ULL: goto x86_l_5745;
	case 22346ULL: goto x86_l_574a;
	case 22348ULL: goto x86_l_574c;
	case 22353ULL: goto x86_l_5751;
	case 22355ULL: goto x86_l_5753;
	case 22361ULL: goto x86_l_5759;
	case 22369ULL: goto x86_l_5761;
	case 22375ULL: goto x86_l_5767;
	case 22381ULL: goto x86_l_576d;
	case 22386ULL: goto x86_l_5772;
	case 22394ULL: goto x86_l_577a;
	case 22396ULL: goto x86_l_577c;
	case 22401ULL: goto x86_l_5781;
	case 22406ULL: goto x86_l_5786;
	case 22411ULL: goto x86_l_578b;
	case 22416ULL: goto x86_l_5790;
	case 22418ULL: goto x86_l_5792;
	case 22423ULL: goto x86_l_5797;
	case 22425ULL: goto x86_l_5799;
	case 22431ULL: goto x86_l_579f;
	case 22439ULL: goto x86_l_57a7;
	case 22445ULL: goto x86_l_57ad;
	case 22451ULL: goto x86_l_57b3;
	case 22456ULL: goto x86_l_57b8;
	case 22464ULL: goto x86_l_57c0;
	case 22466ULL: goto x86_l_57c2;
	case 22471ULL: goto x86_l_57c7;
	case 22476ULL: goto x86_l_57cc;
	case 22481ULL: goto x86_l_57d1;
	case 22486ULL: goto x86_l_57d6;
	case 22488ULL: goto x86_l_57d8;
	case 22493ULL: goto x86_l_57dd;
	case 22495ULL: goto x86_l_57df;
	case 22501ULL: goto x86_l_57e5;
	case 22509ULL: goto x86_l_57ed;
	case 22515ULL: goto x86_l_57f3;
	case 22521ULL: goto x86_l_57f9;
	case 22526ULL: goto x86_l_57fe;
	case 22534ULL: goto x86_l_5806;
	case 22536ULL: goto x86_l_5808;
	case 22541ULL: goto x86_l_580d;
	case 22546ULL: goto x86_l_5812;
	case 22551ULL: goto x86_l_5817;
	case 22556ULL: goto x86_l_581c;
	case 22558ULL: goto x86_l_581e;
	case 22563ULL: goto x86_l_5823;
	case 22565ULL: goto x86_l_5825;
	case 22571ULL: goto x86_l_582b;
	case 22579ULL: goto x86_l_5833;
	case 22585ULL: goto x86_l_5839;
	case 22591ULL: goto x86_l_583f;
	case 22596ULL: goto x86_l_5844;
	case 22604ULL: goto x86_l_584c;
	case 22606ULL: goto x86_l_584e;
	case 22611ULL: goto x86_l_5853;
	case 22616ULL: goto x86_l_5858;
	case 22621ULL: goto x86_l_585d;
	case 22626ULL: goto x86_l_5862;
	case 22628ULL: goto x86_l_5864;
	case 22633ULL: goto x86_l_5869;
	case 22635ULL: goto x86_l_586b;
	case 22641ULL: goto x86_l_5871;
	case 22649ULL: goto x86_l_5879;
	case 22655ULL: goto x86_l_587f;
	case 22661ULL: goto x86_l_5885;
	case 22666ULL: goto x86_l_588a;
	case 22674ULL: goto x86_l_5892;
	case 22676ULL: goto x86_l_5894;
	case 22681ULL: goto x86_l_5899;
	case 22686ULL: goto x86_l_589e;
	case 22691ULL: goto x86_l_58a3;
	case 22696ULL: goto x86_l_58a8;
	case 22698ULL: goto x86_l_58aa;
	case 22703ULL: goto x86_l_58af;
	case 22705ULL: goto x86_l_58b1;
	case 22711ULL: goto x86_l_58b7;
	case 22719ULL: goto x86_l_58bf;
	case 22725ULL: goto x86_l_58c5;
	case 22731ULL: goto x86_l_58cb;
	case 22736ULL: goto x86_l_58d0;
	case 22744ULL: goto x86_l_58d8;
	case 22746ULL: goto x86_l_58da;
	case 22751ULL: goto x86_l_58df;
	case 22756ULL: goto x86_l_58e4;
	case 22761ULL: goto x86_l_58e9;
	case 22766ULL: goto x86_l_58ee;
	case 22768ULL: goto x86_l_58f0;
	case 22770ULL: goto x86_l_58f2;
	case 22776ULL: goto x86_l_58f8;
	case 22781ULL: goto x86_l_58fd;
	case 22789ULL: goto x86_l_5905;
	case 22795ULL: goto x86_l_590b;
	case 22801ULL: goto x86_l_5911;
	case 22806ULL: goto x86_l_5916;
	case 22814ULL: goto x86_l_591e;
	case 22816ULL: goto x86_l_5920;
	case 22821ULL: goto x86_l_5925;
	case 22826ULL: goto x86_l_592a;
	case 22831ULL: goto x86_l_592f;
	case 22836ULL: goto x86_l_5934;
	case 22838ULL: goto x86_l_5936;
	case 22840ULL: goto x86_l_5938;
	case 22846ULL: goto x86_l_593e;
	case 22851ULL: goto x86_l_5943;
	case 22859ULL: goto x86_l_594b;
	case 22865ULL: goto x86_l_5951;
	case 22871ULL: goto x86_l_5957;
	case 22876ULL: goto x86_l_595c;
	case 22884ULL: goto x86_l_5964;
	case 22886ULL: goto x86_l_5966;
	case 22891ULL: goto x86_l_596b;
	case 22896ULL: goto x86_l_5970;
	case 22901ULL: goto x86_l_5975;
	case 22906ULL: goto x86_l_597a;
	case 22908ULL: goto x86_l_597c;
	case 22910ULL: goto x86_l_597e;
	case 22916ULL: goto x86_l_5984;
	case 22921ULL: goto x86_l_5989;
	case 22929ULL: goto x86_l_5991;
	case 22935ULL: goto x86_l_5997;
	case 22941ULL: goto x86_l_599d;
	case 22946ULL: goto x86_l_59a2;
	case 22954ULL: goto x86_l_59aa;
	case 22960ULL: goto x86_l_59b0;
	case 22965ULL: goto x86_l_59b5;
	case 22970ULL: goto x86_l_59ba;
	case 22973ULL: goto x86_l_59bd;
	case 22975ULL: goto x86_l_59bf;
	case 22980ULL: goto x86_l_59c4;
	case 22985ULL: goto x86_l_59c9;
	case 22990ULL: goto x86_l_59ce;
	case 22995ULL: goto x86_l_59d3;
	case 22997ULL: goto x86_l_59d5;
	case 23002ULL: goto x86_l_59da;
	case 23004ULL: goto x86_l_59dc;
	case 23010ULL: goto x86_l_59e2;
	case 23018ULL: goto x86_l_59ea;
	case 23024ULL: goto x86_l_59f0;
	case 23030ULL: goto x86_l_59f6;
	case 23035ULL: goto x86_l_59fb;
	case 23043ULL: goto x86_l_5a03;
	case 23045ULL: goto x86_l_5a05;
	case 23050ULL: goto x86_l_5a0a;
	case 23055ULL: goto x86_l_5a0f;
	case 23060ULL: goto x86_l_5a14;
	case 23065ULL: goto x86_l_5a19;
	case 23067ULL: goto x86_l_5a1b;
	case 23072ULL: goto x86_l_5a20;
	case 23074ULL: goto x86_l_5a22;
	case 23080ULL: goto x86_l_5a28;
	case 23088ULL: goto x86_l_5a30;
	case 23094ULL: goto x86_l_5a36;
	case 23100ULL: goto x86_l_5a3c;
	case 23105ULL: goto x86_l_5a41;
	case 23113ULL: goto x86_l_5a49;
	case 23115ULL: goto x86_l_5a4b;
	case 23120ULL: goto x86_l_5a50;
	case 23125ULL: goto x86_l_5a55;
	case 23130ULL: goto x86_l_5a5a;
	case 23135ULL: goto x86_l_5a5f;
	case 23137ULL: goto x86_l_5a61;
	case 23142ULL: goto x86_l_5a66;
	case 23144ULL: goto x86_l_5a68;
	case 23150ULL: goto x86_l_5a6e;
	case 23158ULL: goto x86_l_5a76;
	case 23164ULL: goto x86_l_5a7c;
	case 23170ULL: goto x86_l_5a82;
	case 23175ULL: goto x86_l_5a87;
	case 23183ULL: goto x86_l_5a8f;
	case 23185ULL: goto x86_l_5a91;
	case 23190ULL: goto x86_l_5a96;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23205ULL: goto x86_l_5aa5;
	case 23207ULL: goto x86_l_5aa7;
	case 23212ULL: goto x86_l_5aac;
	case 23214ULL: goto x86_l_5aae;
	case 23220ULL: goto x86_l_5ab4;
	case 23228ULL: goto x86_l_5abc;
	case 23234ULL: goto x86_l_5ac2;
	case 23240ULL: goto x86_l_5ac8;
	case 23245ULL: goto x86_l_5acd;
	case 23253ULL: goto x86_l_5ad5;
	case 23255ULL: goto x86_l_5ad7;
	case 23260ULL: goto x86_l_5adc;
	case 23265ULL: goto x86_l_5ae1;
	case 23270ULL: goto x86_l_5ae6;
	case 23275ULL: goto x86_l_5aeb;
	case 23277ULL: goto x86_l_5aed;
	case 23282ULL: goto x86_l_5af2;
	case 23284ULL: goto x86_l_5af4;
	case 23290ULL: goto x86_l_5afa;
	case 23298ULL: goto x86_l_5b02;
	case 23304ULL: goto x86_l_5b08;
	case 23310ULL: goto x86_l_5b0e;
	case 23315ULL: goto x86_l_5b13;
	case 23323ULL: goto x86_l_5b1b;
	case 23325ULL: goto x86_l_5b1d;
	case 23330ULL: goto x86_l_5b22;
	case 23335ULL: goto x86_l_5b27;
	case 23340ULL: goto x86_l_5b2c;
	case 23345ULL: goto x86_l_5b31;
	case 23347ULL: goto x86_l_5b33;
	case 23349ULL: goto x86_l_5b35;
	case 23355ULL: goto x86_l_5b3b;
	case 23360ULL: goto x86_l_5b40;
	case 23368ULL: goto x86_l_5b48;
	case 23374ULL: goto x86_l_5b4e;
	case 23380ULL: goto x86_l_5b54;
	case 23385ULL: goto x86_l_5b59;
	case 23393ULL: goto x86_l_5b61;
	case 23395ULL: goto x86_l_5b63;
	case 23400ULL: goto x86_l_5b68;
	case 23405ULL: goto x86_l_5b6d;
	case 23410ULL: goto x86_l_5b72;
	case 23415ULL: goto x86_l_5b77;
	case 23417ULL: goto x86_l_5b79;
	case 23419ULL: goto x86_l_5b7b;
	case 23425ULL: goto x86_l_5b81;
	case 23430ULL: goto x86_l_5b86;
	case 23438ULL: goto x86_l_5b8e;
	case 23444ULL: goto x86_l_5b94;
	case 23450ULL: goto x86_l_5b9a;
	case 23455ULL: goto x86_l_5b9f;
	case 23463ULL: goto x86_l_5ba7;
	case 23465ULL: goto x86_l_5ba9;
	case 23470ULL: goto x86_l_5bae;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5472:
	/* 0x5472: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5478:
	/* 0x5478: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_547e:
	/* 0x547e: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5483:
	/* 0x5483: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_548b:
	/* 0x548b: je     54b0 <generic_sleepable_preload+0x54b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54b0;
	}
x86_l_548d:
	/* 0x548d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5492:
	/* 0x5492: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5497:
	/* 0x5497: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_549c:
	/* 0x549c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54a1:
	/* 0x54a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54a3:
	/* 0x54a3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54a8:
	/* 0x54a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54aa:
	/* 0x54aa: js     5cc6 <generic_sleepable_preload+0x5cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23750ULL;
	}
x86_l_54b0:
	/* 0x54b0: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_54b8:
	/* 0x54b8: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_54be:
	/* 0x54be: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_54c4:
	/* 0x54c4: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_54c9:
	/* 0x54c9: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_54d1:
	/* 0x54d1: je     54f6 <generic_sleepable_preload+0x54f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54f6;
	}
x86_l_54d3:
	/* 0x54d3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_54d8:
	/* 0x54d8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54dd:
	/* 0x54dd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54e2:
	/* 0x54e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54e7:
	/* 0x54e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54e9:
	/* 0x54e9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54ee:
	/* 0x54ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54f0:
	/* 0x54f0: js     5cd7 <generic_sleepable_preload+0x5cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23767ULL;
	}
x86_l_54f6:
	/* 0x54f6: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_54fe:
	/* 0x54fe: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5504:
	/* 0x5504: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_550a:
	/* 0x550a: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_550f:
	/* 0x550f: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5517:
	/* 0x5517: je     553c <generic_sleepable_preload+0x553c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_553c;
	}
x86_l_5519:
	/* 0x5519: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_551e:
	/* 0x551e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5523:
	/* 0x5523: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5528:
	/* 0x5528: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_552d:
	/* 0x552d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552f:
	/* 0x552f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5534:
	/* 0x5534: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5536:
	/* 0x5536: js     5ce8 <generic_sleepable_preload+0x5ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23784ULL;
	}
x86_l_553c:
	/* 0x553c: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5544:
	/* 0x5544: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_554a:
	/* 0x554a: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5550:
	/* 0x5550: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5555:
	/* 0x5555: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_555d:
	/* 0x555d: je     557d <generic_sleepable_preload+0x557d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557d;
	}
x86_l_555f:
	/* 0x555f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5564:
	/* 0x5564: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5569:
	/* 0x5569: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_556e:
	/* 0x556e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5573:
	/* 0x5573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5575:
	/* 0x5575: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5577:
	/* 0x5577: js     5e09 <generic_sleepable_preload+0x5e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24073ULL;
	}
x86_l_557d:
	/* 0x557d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5582:
	/* 0x5582: cmp    WORD PTR [rdi+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_558a:
	/* 0x558a: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5590:
	/* 0x5590: mov    eax,DWORD PTR [rdi+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5596:
	/* 0x5596: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_559b:
	/* 0x559b: cmp    WORD PTR [rdi+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_55a3:
	/* 0x55a3: je     55c3 <generic_sleepable_preload+0x55c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_55c3;
	}
x86_l_55a5:
	/* 0x55a5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55aa:
	/* 0x55aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55af:
	/* 0x55af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55b4:
	/* 0x55b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55b9:
	/* 0x55b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55bb:
	/* 0x55bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55bd:
	/* 0x55bd: js     5ecb <generic_sleepable_preload+0x5ecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24267ULL;
	}
x86_l_55c3:
	/* 0x55c3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_55c8:
	/* 0x55c8: cmp    WORD PTR [rdi+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_55d0:
	/* 0x55d0: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_55d6:
	/* 0x55d6: mov    eax,DWORD PTR [rdi+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_55dc:
	/* 0x55dc: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_55e1:
	/* 0x55e1: cmp    WORD PTR [rdi+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_55e9:
	/* 0x55e9: je     5609 <generic_sleepable_preload+0x5609> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5609;
	}
x86_l_55eb:
	/* 0x55eb: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_55f0:
	/* 0x55f0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55f5:
	/* 0x55f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55fa:
	/* 0x55fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55ff:
	/* 0x55ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5601:
	/* 0x5601: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5603:
	/* 0x5603: js     5f83 <generic_sleepable_preload+0x5f83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24451ULL;
	}
x86_l_5609:
	/* 0x5609: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_560e:
	/* 0x560e: cmp    WORD PTR [rdi+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5616:
	/* 0x5616: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_561c:
	/* 0x561c: mov    eax,DWORD PTR [rdi+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5622:
	/* 0x5622: add    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5627:
	/* 0x5627: cmp    WORD PTR [rdi+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_562f:
	/* 0x562f: je     5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23792ULL;
	}
x86_l_5635:
	/* 0x5635: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_563a:
	/* 0x563a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_563f:
	/* 0x563f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5644:
	/* 0x5644: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5649:
	/* 0x5649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564b:
	/* 0x564b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5650:
	/* 0x5650: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5652:
	/* 0x5652: jns    5cf0 <generic_sleepable_preload+0x5cf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 23792ULL;
	}
x86_l_5658:
	/* 0x5658: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_565d:
	/* 0x565d: jmp    5ced <generic_sleepable_preload+0x5ced> */
	return 23789ULL;
x86_l_5662:
	/* 0x5662: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_5667:
	/* 0x5667: jmp    5ced <generic_sleepable_preload+0x5ced> */
	return 23789ULL;
x86_l_566c:
	/* 0x566c: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5674:
	/* 0x5674: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5677:
	/* 0x5677: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_5679:
	/* 0x5679: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_567e:
	/* 0x567e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_5681:
	/* 0x5681: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_5683:
	/* 0x5683: jmp    56ef <generic_sleepable_preload+0x56ef> */
	goto x86_l_56ef;
x86_l_5685:
	/* 0x5685: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_568a:
	/* 0x568a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_568d:
	/* 0x568d: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_568f:
	/* 0x568f: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5694:
	/* 0x5694: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_5697:
	/* 0x5697: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_5699:
	/* 0x5699: jmp    56ef <generic_sleepable_preload+0x56ef> */
	goto x86_l_56ef;
x86_l_569b:
	/* 0x569b: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_56a3:
	/* 0x56a3: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_56a6:
	/* 0x56a6: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_56a8:
	/* 0x56a8: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_56ad:
	/* 0x56ad: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_56b0:
	/* 0x56b0: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_56b2:
	/* 0x56b2: jmp    56ef <generic_sleepable_preload+0x56ef> */
	goto x86_l_56ef;
x86_l_56b4:
	/* 0x56b4: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_56bc:
	/* 0x56bc: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_56bf:
	/* 0x56bf: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_56c1:
	/* 0x56c1: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_56c6:
	/* 0x56c6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_56c9:
	/* 0x56c9: je     56dc <generic_sleepable_preload+0x56dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56dc;
	}
x86_l_56cb:
	/* 0x56cb: jmp    56ef <generic_sleepable_preload+0x56ef> */
	goto x86_l_56ef;
x86_l_56cd:
	/* 0x56cd: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_56d2:
	/* 0x56d2: jmp    5ced <generic_sleepable_preload+0x5ced> */
	return 23789ULL;
x86_l_56d7:
	/* 0x56d7: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56dc:
	/* 0x56dc: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_56df:
	/* 0x56df: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_56e1:
	/* 0x56e1: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_56e3:
	/* 0x56e3: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_56e8:
	/* 0x56e8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_56ea:
	/* 0x56ea: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_56ef:
	/* 0x56ef: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56f4:
	/* 0x56f4: mov    ebx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_56f7:
	/* 0x56f7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56f9:
	/* 0x56f9: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_56fc:
	/* 0x56fc: cmp    WORD PTR [rdi+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_5704:
	/* 0x5704: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_570a:
	/* 0x570a: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5711:
	/* 0x5711: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5714:
	/* 0x5714: mov    edx,DWORD PTR [rdi+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_571a:
	/* 0x571a: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_571d:
	/* 0x571d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5722:
	/* 0x5722: movzx  eax,WORD PTR [rdi+0x1b4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 436ULL);
x86_l_5729:
	/* 0x5729: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_572b:
	/* 0x572b: je     59ba <generic_sleepable_preload+0x59ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59ba;
	}
x86_l_5731:
	/* 0x5731: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5734:
	/* 0x5734: je     5759 <generic_sleepable_preload+0x5759> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5759;
	}
x86_l_5736:
	/* 0x5736: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_573b:
	/* 0x573b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5740:
	/* 0x5740: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5745:
	/* 0x5745: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_574a:
	/* 0x574a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_574c:
	/* 0x574c: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5751:
	/* 0x5751: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5753:
	/* 0x5753: js     5c61 <generic_sleepable_preload+0x5c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23649ULL;
	}
x86_l_5759:
	/* 0x5759: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_5761:
	/* 0x5761: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5767:
	/* 0x5767: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_576d:
	/* 0x576d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5772:
	/* 0x5772: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_577a:
	/* 0x577a: je     579f <generic_sleepable_preload+0x579f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_579f;
	}
x86_l_577c:
	/* 0x577c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5781:
	/* 0x5781: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5786:
	/* 0x5786: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_578b:
	/* 0x578b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5790:
	/* 0x5790: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5792:
	/* 0x5792: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5797:
	/* 0x5797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5799:
	/* 0x5799: js     5c6b <generic_sleepable_preload+0x5c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23659ULL;
	}
x86_l_579f:
	/* 0x579f: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_57a7:
	/* 0x57a7: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_57ad:
	/* 0x57ad: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_57b3:
	/* 0x57b3: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57b8:
	/* 0x57b8: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_57c0:
	/* 0x57c0: je     57e5 <generic_sleepable_preload+0x57e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57e5;
	}
x86_l_57c2:
	/* 0x57c2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_57c7:
	/* 0x57c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57cc:
	/* 0x57cc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57d1:
	/* 0x57d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57d6:
	/* 0x57d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d8:
	/* 0x57d8: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57dd:
	/* 0x57dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57df:
	/* 0x57df: js     5c7c <generic_sleepable_preload+0x5c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23676ULL;
	}
x86_l_57e5:
	/* 0x57e5: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_57ed:
	/* 0x57ed: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_57f3:
	/* 0x57f3: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_57f9:
	/* 0x57f9: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57fe:
	/* 0x57fe: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5806:
	/* 0x5806: je     582b <generic_sleepable_preload+0x582b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_582b;
	}
x86_l_5808:
	/* 0x5808: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_580d:
	/* 0x580d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5812:
	/* 0x5812: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5817:
	/* 0x5817: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_581c:
	/* 0x581c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_581e:
	/* 0x581e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5823:
	/* 0x5823: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5825:
	/* 0x5825: js     5ccd <generic_sleepable_preload+0x5ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23757ULL;
	}
x86_l_582b:
	/* 0x582b: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5833:
	/* 0x5833: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5839:
	/* 0x5839: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_583f:
	/* 0x583f: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5844:
	/* 0x5844: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_584c:
	/* 0x584c: je     5871 <generic_sleepable_preload+0x5871> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5871;
	}
x86_l_584e:
	/* 0x584e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5853:
	/* 0x5853: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5858:
	/* 0x5858: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_585d:
	/* 0x585d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5862:
	/* 0x5862: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5864:
	/* 0x5864: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5869:
	/* 0x5869: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_586b:
	/* 0x586b: js     5cde <generic_sleepable_preload+0x5cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23774ULL;
	}
x86_l_5871:
	/* 0x5871: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5879:
	/* 0x5879: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_587f:
	/* 0x587f: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5885:
	/* 0x5885: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_588a:
	/* 0x588a: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5892:
	/* 0x5892: je     58b7 <generic_sleepable_preload+0x58b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58b7;
	}
x86_l_5894:
	/* 0x5894: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5899:
	/* 0x5899: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_589e:
	/* 0x589e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58a3:
	/* 0x58a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58a8:
	/* 0x58a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58aa:
	/* 0x58aa: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58af:
	/* 0x58af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58b1:
	/* 0x58b1: js     5d6f <generic_sleepable_preload+0x5d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23919ULL;
	}
x86_l_58b7:
	/* 0x58b7: cmp    WORD PTR [rdi+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_58bf:
	/* 0x58bf: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_58c5:
	/* 0x58c5: mov    eax,DWORD PTR [rdi+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_58cb:
	/* 0x58cb: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58d0:
	/* 0x58d0: cmp    WORD PTR [rdi+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_58d8:
	/* 0x58d8: je     58f8 <generic_sleepable_preload+0x58f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58f8;
	}
x86_l_58da:
	/* 0x58da: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_58df:
	/* 0x58df: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58e4:
	/* 0x58e4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58e9:
	/* 0x58e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58ee:
	/* 0x58ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f0:
	/* 0x58f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58f2:
	/* 0x58f2: js     5e1b <generic_sleepable_preload+0x5e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24091ULL;
	}
x86_l_58f8:
	/* 0x58f8: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58fd:
	/* 0x58fd: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5905:
	/* 0x5905: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_590b:
	/* 0x590b: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5911:
	/* 0x5911: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5916:
	/* 0x5916: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_591e:
	/* 0x591e: je     593e <generic_sleepable_preload+0x593e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_593e;
	}
x86_l_5920:
	/* 0x5920: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5925:
	/* 0x5925: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_592a:
	/* 0x592a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_592f:
	/* 0x592f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5934:
	/* 0x5934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5936:
	/* 0x5936: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5938:
	/* 0x5938: js     5edd <generic_sleepable_preload+0x5edd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24285ULL;
	}
x86_l_593e:
	/* 0x593e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5943:
	/* 0x5943: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_594b:
	/* 0x594b: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5951:
	/* 0x5951: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5957:
	/* 0x5957: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_595c:
	/* 0x595c: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5964:
	/* 0x5964: je     5984 <generic_sleepable_preload+0x5984> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5984;
	}
x86_l_5966:
	/* 0x5966: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_596b:
	/* 0x596b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5970:
	/* 0x5970: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5975:
	/* 0x5975: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_597a:
	/* 0x597a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597c:
	/* 0x597c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_597e:
	/* 0x597e: js     5f8d <generic_sleepable_preload+0x5f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24461ULL;
	}
x86_l_5984:
	/* 0x5984: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5989:
	/* 0x5989: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5991:
	/* 0x5991: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5997:
	/* 0x5997: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_599d:
	/* 0x599d: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59a2:
	/* 0x59a2: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_59aa:
	/* 0x59aa: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_59b0:
	/* 0x59b0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59b5:
	/* 0x59b5: jmp    5c3e <generic_sleepable_preload+0x5c3e> */
	return 23614ULL;
x86_l_59ba:
	/* 0x59ba: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_59bd:
	/* 0x59bd: je     59e2 <generic_sleepable_preload+0x59e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59e2;
	}
x86_l_59bf:
	/* 0x59bf: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59c4:
	/* 0x59c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c9:
	/* 0x59c9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59ce:
	/* 0x59ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59d3:
	/* 0x59d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59d5:
	/* 0x59d5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59da:
	/* 0x59da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_59dc:
	/* 0x59dc: js     5c61 <generic_sleepable_preload+0x5c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23649ULL;
	}
x86_l_59e2:
	/* 0x59e2: cmp    WORD PTR [rdi+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_59ea:
	/* 0x59ea: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_59f0:
	/* 0x59f0: mov    eax,DWORD PTR [rdi+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_59f6:
	/* 0x59f6: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_59fb:
	/* 0x59fb: cmp    WORD PTR [rdi+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_5a03:
	/* 0x5a03: je     5a28 <generic_sleepable_preload+0x5a28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a28;
	}
x86_l_5a05:
	/* 0x5a05: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a0a:
	/* 0x5a0a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a0f:
	/* 0x5a0f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a14:
	/* 0x5a14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a19:
	/* 0x5a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a1b:
	/* 0x5a1b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a20:
	/* 0x5a20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a22:
	/* 0x5a22: js     5c6b <generic_sleepable_preload+0x5c6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23659ULL;
	}
x86_l_5a28:
	/* 0x5a28: cmp    WORD PTR [rdi+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_5a30:
	/* 0x5a30: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5a36:
	/* 0x5a36: mov    eax,DWORD PTR [rdi+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_5a3c:
	/* 0x5a3c: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a41:
	/* 0x5a41: cmp    WORD PTR [rdi+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_5a49:
	/* 0x5a49: je     5a6e <generic_sleepable_preload+0x5a6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a6e;
	}
x86_l_5a4b:
	/* 0x5a4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a50:
	/* 0x5a50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a55:
	/* 0x5a55: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a5a:
	/* 0x5a5a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a5f:
	/* 0x5a5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a61:
	/* 0x5a61: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a66:
	/* 0x5a66: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a68:
	/* 0x5a68: js     5c7c <generic_sleepable_preload+0x5c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23676ULL;
	}
x86_l_5a6e:
	/* 0x5a6e: cmp    WORD PTR [rdi+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_5a76:
	/* 0x5a76: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5a7c:
	/* 0x5a7c: mov    eax,DWORD PTR [rdi+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_5a82:
	/* 0x5a82: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5a87:
	/* 0x5a87: cmp    WORD PTR [rdi+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_5a8f:
	/* 0x5a8f: je     5ab4 <generic_sleepable_preload+0x5ab4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ab4;
	}
x86_l_5a91:
	/* 0x5a91: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a96:
	/* 0x5a96: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a9b:
	/* 0x5a9b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aa0:
	/* 0x5aa0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5aa5:
	/* 0x5aa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa7:
	/* 0x5aa7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aac:
	/* 0x5aac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5aae:
	/* 0x5aae: js     5ccd <generic_sleepable_preload+0x5ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23757ULL;
	}
x86_l_5ab4:
	/* 0x5ab4: cmp    WORD PTR [rdi+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_5abc:
	/* 0x5abc: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5ac2:
	/* 0x5ac2: mov    eax,DWORD PTR [rdi+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_5ac8:
	/* 0x5ac8: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5acd:
	/* 0x5acd: cmp    WORD PTR [rdi+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_5ad5:
	/* 0x5ad5: je     5afa <generic_sleepable_preload+0x5afa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5afa;
	}
x86_l_5ad7:
	/* 0x5ad7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5adc:
	/* 0x5adc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae1:
	/* 0x5ae1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae6:
	/* 0x5ae6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5aeb:
	/* 0x5aeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aed:
	/* 0x5aed: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5af2:
	/* 0x5af2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5af4:
	/* 0x5af4: js     5cde <generic_sleepable_preload+0x5cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23774ULL;
	}
x86_l_5afa:
	/* 0x5afa: cmp    WORD PTR [rdi+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_5b02:
	/* 0x5b02: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5b08:
	/* 0x5b08: mov    eax,DWORD PTR [rdi+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_5b0e:
	/* 0x5b0e: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b13:
	/* 0x5b13: cmp    WORD PTR [rdi+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_5b1b:
	/* 0x5b1b: je     5b3b <generic_sleepable_preload+0x5b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b3b;
	}
x86_l_5b1d:
	/* 0x5b1d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b22:
	/* 0x5b22: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b27:
	/* 0x5b27: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b2c:
	/* 0x5b2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b31:
	/* 0x5b31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b33:
	/* 0x5b33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b35:
	/* 0x5b35: js     5d6f <generic_sleepable_preload+0x5d6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 23919ULL;
	}
x86_l_5b3b:
	/* 0x5b3b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b40:
	/* 0x5b40: cmp    WORD PTR [rcx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_5b48:
	/* 0x5b48: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5b4e:
	/* 0x5b4e: mov    eax,DWORD PTR [rcx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_5b54:
	/* 0x5b54: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b59:
	/* 0x5b59: cmp    WORD PTR [rcx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_5b61:
	/* 0x5b61: je     5b81 <generic_sleepable_preload+0x5b81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b81;
	}
x86_l_5b63:
	/* 0x5b63: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5b68:
	/* 0x5b68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b6d:
	/* 0x5b6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b72:
	/* 0x5b72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b77:
	/* 0x5b77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b79:
	/* 0x5b79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b7b:
	/* 0x5b7b: js     5e1b <generic_sleepable_preload+0x5e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 24091ULL;
	}
x86_l_5b81:
	/* 0x5b81: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b86:
	/* 0x5b86: cmp    WORD PTR [rcx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_5b8e:
	/* 0x5b8e: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24099ULL;
	}
x86_l_5b94:
	/* 0x5b94: mov    eax,DWORD PTR [rcx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_5b9a:
	/* 0x5b9a: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b9f:
	/* 0x5b9f: cmp    WORD PTR [rcx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_5ba7:
	/* 0x5ba7: je     5bc7 <generic_sleepable_preload+0x5bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23495ULL;
	}
x86_l_5ba9:
	/* 0x5ba9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bae:
	/* 0x5bae: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 23475ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23475ULL: goto x86_l_5bb3;
	case 23480ULL: goto x86_l_5bb8;
	case 23485ULL: goto x86_l_5bbd;
	case 23487ULL: goto x86_l_5bbf;
	case 23489ULL: goto x86_l_5bc1;
	case 23495ULL: goto x86_l_5bc7;
	case 23500ULL: goto x86_l_5bcc;
	case 23508ULL: goto x86_l_5bd4;
	case 23514ULL: goto x86_l_5bda;
	case 23520ULL: goto x86_l_5be0;
	case 23525ULL: goto x86_l_5be5;
	case 23533ULL: goto x86_l_5bed;
	case 23535ULL: goto x86_l_5bef;
	case 23540ULL: goto x86_l_5bf4;
	case 23545ULL: goto x86_l_5bf9;
	case 23550ULL: goto x86_l_5bfe;
	case 23555ULL: goto x86_l_5c03;
	case 23557ULL: goto x86_l_5c05;
	case 23559ULL: goto x86_l_5c07;
	case 23565ULL: goto x86_l_5c0d;
	case 23570ULL: goto x86_l_5c12;
	case 23578ULL: goto x86_l_5c1a;
	case 23584ULL: goto x86_l_5c20;
	case 23590ULL: goto x86_l_5c26;
	case 23595ULL: goto x86_l_5c2b;
	case 23603ULL: goto x86_l_5c33;
	case 23609ULL: goto x86_l_5c39;
	case 23614ULL: goto x86_l_5c3e;
	case 23619ULL: goto x86_l_5c43;
	case 23624ULL: goto x86_l_5c48;
	case 23629ULL: goto x86_l_5c4d;
	case 23631ULL: goto x86_l_5c4f;
	case 23633ULL: goto x86_l_5c51;
	case 23639ULL: goto x86_l_5c57;
	case 23644ULL: goto x86_l_5c5c;
	case 23649ULL: goto x86_l_5c61;
	case 23654ULL: goto x86_l_5c66;
	case 23659ULL: goto x86_l_5c6b;
	case 23664ULL: goto x86_l_5c70;
	case 23669ULL: goto x86_l_5c75;
	case 23674ULL: goto x86_l_5c7a;
	case 23676ULL: goto x86_l_5c7c;
	case 23681ULL: goto x86_l_5c81;
	case 23686ULL: goto x86_l_5c86;
	case 23691ULL: goto x86_l_5c8b;
	case 23698ULL: goto x86_l_5c92;
	case 23705ULL: goto x86_l_5c99;
	case 23712ULL: goto x86_l_5ca0;
	case 23717ULL: goto x86_l_5ca5;
	case 23720ULL: goto x86_l_5ca8;
	case 23725ULL: goto x86_l_5cad;
	case 23730ULL: goto x86_l_5cb2;
	case 23732ULL: goto x86_l_5cb4;
	case 23734ULL: goto x86_l_5cb6;
	case 23737ULL: goto x86_l_5cb9;
	case 23743ULL: goto x86_l_5cbf;
	case 23745ULL: goto x86_l_5cc1;
	case 23750ULL: goto x86_l_5cc6;
	case 23755ULL: goto x86_l_5ccb;
	case 23757ULL: goto x86_l_5ccd;
	case 23762ULL: goto x86_l_5cd2;
	case 23767ULL: goto x86_l_5cd7;
	case 23772ULL: goto x86_l_5cdc;
	case 23774ULL: goto x86_l_5cde;
	case 23779ULL: goto x86_l_5ce3;
	case 23784ULL: goto x86_l_5ce8;
	case 23789ULL: goto x86_l_5ced;
	case 23792ULL: goto x86_l_5cf0;
	case 23795ULL: goto x86_l_5cf3;
	case 23800ULL: goto x86_l_5cf8;
	case 23805ULL: goto x86_l_5cfd;
	case 23810ULL: goto x86_l_5d02;
	case 23813ULL: goto x86_l_5d05;
	case 23815ULL: goto x86_l_5d07;
	case 23818ULL: goto x86_l_5d0a;
	case 23824ULL: goto x86_l_5d10;
	case 23829ULL: goto x86_l_5d15;
	case 23834ULL: goto x86_l_5d1a;
	case 23836ULL: goto x86_l_5d1c;
	case 23841ULL: goto x86_l_5d21;
	case 23849ULL: goto x86_l_5d29;
	case 23854ULL: goto x86_l_5d2e;
	case 23861ULL: goto x86_l_5d35;
	case 23866ULL: goto x86_l_5d3a;
	case 23868ULL: goto x86_l_5d3c;
	case 23871ULL: goto x86_l_5d3f;
	case 23877ULL: goto x86_l_5d45;
	case 23883ULL: goto x86_l_5d4b;
	case 23890ULL: goto x86_l_5d52;
	case 23895ULL: goto x86_l_5d57;
	case 23898ULL: goto x86_l_5d5a;
	case 23901ULL: goto x86_l_5d5d;
	case 23904ULL: goto x86_l_5d60;
	case 23906ULL: goto x86_l_5d62;
	case 23909ULL: goto x86_l_5d65;
	case 23914ULL: goto x86_l_5d6a;
	case 23919ULL: goto x86_l_5d6f;
	case 23924ULL: goto x86_l_5d74;
	case 23929ULL: goto x86_l_5d79;
	case 23934ULL: goto x86_l_5d7e;
	case 23937ULL: goto x86_l_5d81;
	case 23942ULL: goto x86_l_5d86;
	case 23947ULL: goto x86_l_5d8b;
	case 23952ULL: goto x86_l_5d90;
	case 23955ULL: goto x86_l_5d93;
	case 23960ULL: goto x86_l_5d98;
	case 23965ULL: goto x86_l_5d9d;
	case 23970ULL: goto x86_l_5da2;
	case 23973ULL: goto x86_l_5da5;
	case 23978ULL: goto x86_l_5daa;
	case 23983ULL: goto x86_l_5daf;
	case 23988ULL: goto x86_l_5db4;
	case 23991ULL: goto x86_l_5db7;
	case 23996ULL: goto x86_l_5dbc;
	case 24001ULL: goto x86_l_5dc1;
	case 24006ULL: goto x86_l_5dc6;
	case 24009ULL: goto x86_l_5dc9;
	case 24014ULL: goto x86_l_5dce;
	case 24019ULL: goto x86_l_5dd3;
	case 24024ULL: goto x86_l_5dd8;
	case 24027ULL: goto x86_l_5ddb;
	case 24032ULL: goto x86_l_5de0;
	case 24037ULL: goto x86_l_5de5;
	case 24042ULL: goto x86_l_5dea;
	case 24045ULL: goto x86_l_5ded;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24060ULL: goto x86_l_5dfc;
	case 24063ULL: goto x86_l_5dff;
	case 24068ULL: goto x86_l_5e04;
	case 24073ULL: goto x86_l_5e09;
	case 24078ULL: goto x86_l_5e0e;
	case 24081ULL: goto x86_l_5e11;
	case 24086ULL: goto x86_l_5e16;
	case 24091ULL: goto x86_l_5e1b;
	case 24096ULL: goto x86_l_5e20;
	case 24099ULL: goto x86_l_5e23;
	case 24102ULL: goto x86_l_5e26;
	case 24108ULL: goto x86_l_5e2c;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24120ULL: goto x86_l_5e38;
	case 24125ULL: goto x86_l_5e3d;
	case 24133ULL: goto x86_l_5e45;
	case 24138ULL: goto x86_l_5e4a;
	case 24145ULL: goto x86_l_5e51;
	case 24150ULL: goto x86_l_5e56;
	case 24152ULL: goto x86_l_5e58;
	case 24155ULL: goto x86_l_5e5b;
	case 24161ULL: goto x86_l_5e61;
	case 24167ULL: goto x86_l_5e67;
	case 24174ULL: goto x86_l_5e6e;
	case 24179ULL: goto x86_l_5e73;
	case 24182ULL: goto x86_l_5e76;
	case 24185ULL: goto x86_l_5e79;
	case 24188ULL: goto x86_l_5e7c;
	case 24190ULL: goto x86_l_5e7e;
	case 24193ULL: goto x86_l_5e81;
	case 24198ULL: goto x86_l_5e86;
	case 24201ULL: goto x86_l_5e89;
	case 24204ULL: goto x86_l_5e8c;
	case 24206ULL: goto x86_l_5e8e;
	case 24209ULL: goto x86_l_5e91;
	case 24215ULL: goto x86_l_5e97;
	case 24218ULL: goto x86_l_5e9a;
	case 24220ULL: goto x86_l_5e9c;
	case 24223ULL: goto x86_l_5e9f;
	case 24227ULL: goto x86_l_5ea3;
	case 24232ULL: goto x86_l_5ea8;
	case 24235ULL: goto x86_l_5eab;
	case 24237ULL: goto x86_l_5ead;
	case 24240ULL: goto x86_l_5eb0;
	case 24245ULL: goto x86_l_5eb5;
	case 24247ULL: goto x86_l_5eb7;
	case 24250ULL: goto x86_l_5eba;
	case 24252ULL: goto x86_l_5ebc;
	case 24257ULL: goto x86_l_5ec1;
	case 24260ULL: goto x86_l_5ec4;
	case 24262ULL: goto x86_l_5ec6;
	case 24267ULL: goto x86_l_5ecb;
	case 24270ULL: goto x86_l_5ece;
	case 24275ULL: goto x86_l_5ed3;
	case 24280ULL: goto x86_l_5ed8;
	case 24285ULL: goto x86_l_5edd;
	case 24288ULL: goto x86_l_5ee0;
	case 24293ULL: goto x86_l_5ee5;
	case 24296ULL: goto x86_l_5ee8;
	case 24302ULL: goto x86_l_5eee;
	case 24307ULL: goto x86_l_5ef3;
	case 24310ULL: goto x86_l_5ef6;
	case 24315ULL: goto x86_l_5efb;
	case 24320ULL: goto x86_l_5f00;
	case 24325ULL: goto x86_l_5f05;
	case 24328ULL: goto x86_l_5f08;
	case 24333ULL: goto x86_l_5f0d;
	case 24338ULL: goto x86_l_5f12;
	case 24343ULL: goto x86_l_5f17;
	case 24346ULL: goto x86_l_5f1a;
	case 24351ULL: goto x86_l_5f1f;
	case 24356ULL: goto x86_l_5f24;
	case 24361ULL: goto x86_l_5f29;
	case 24364ULL: goto x86_l_5f2c;
	case 24369ULL: goto x86_l_5f31;
	case 24374ULL: goto x86_l_5f36;
	case 24379ULL: goto x86_l_5f3b;
	case 24382ULL: goto x86_l_5f3e;
	case 24387ULL: goto x86_l_5f43;
	case 24392ULL: goto x86_l_5f48;
	case 24397ULL: goto x86_l_5f4d;
	case 24400ULL: goto x86_l_5f50;
	case 24405ULL: goto x86_l_5f55;
	case 24410ULL: goto x86_l_5f5a;
	case 24415ULL: goto x86_l_5f5f;
	case 24418ULL: goto x86_l_5f62;
	case 24423ULL: goto x86_l_5f67;
	case 24428ULL: goto x86_l_5f6c;
	case 24433ULL: goto x86_l_5f71;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24446ULL: goto x86_l_5f7e;
	case 24451ULL: goto x86_l_5f83;
	case 24456ULL: goto x86_l_5f88;
	case 24461ULL: goto x86_l_5f8d;
	case 24466ULL: goto x86_l_5f92;
	case 24471ULL: goto x86_l_5f97;
	case 24474ULL: goto x86_l_5f9a;
	case 24479ULL: goto x86_l_5f9f;
	case 24484ULL: goto x86_l_5fa4;
	case 24487ULL: goto x86_l_5fa7;
	case 24492ULL: goto x86_l_5fac;
	case 24497ULL: goto x86_l_5fb1;
	case 24500ULL: goto x86_l_5fb4;
	case 24505ULL: goto x86_l_5fb9;
	case 24510ULL: goto x86_l_5fbe;
	case 24513ULL: goto x86_l_5fc1;
	case 24518ULL: goto x86_l_5fc6;
	case 24523ULL: goto x86_l_5fcb;
	case 24526ULL: goto x86_l_5fce;
	case 24531ULL: goto x86_l_5fd3;
	case 24536ULL: goto x86_l_5fd8;
	case 24539ULL: goto x86_l_5fdb;
	case 24544ULL: goto x86_l_5fe0;
	case 24549ULL: goto x86_l_5fe5;
	case 24552ULL: goto x86_l_5fe8;
	case 24557ULL: goto x86_l_5fed;
	case 24562ULL: goto x86_l_5ff2;
	case 24565ULL: goto x86_l_5ff5;
	case 24570ULL: goto x86_l_5ffa;
	case 24575ULL: goto x86_l_5fff;
	case 24580ULL: goto x86_l_6004;
	case 24583ULL: goto x86_l_6007;
	case 24588ULL: goto x86_l_600c;
	case 24593ULL: goto x86_l_6011;
	case 24598ULL: goto x86_l_6016;
	case 24603ULL: goto x86_l_601b;
	case 24606ULL: goto x86_l_601e;
	case 24611ULL: goto x86_l_6023;
	case 24616ULL: goto x86_l_6028;
	case 24621ULL: goto x86_l_602d;
	case 24626ULL: goto x86_l_6032;
	case 24631ULL: goto x86_l_6037;
	case 24636ULL: goto x86_l_603c;
	case 24641ULL: goto x86_l_6041;
	case 24646ULL: goto x86_l_6046;
	case 24651ULL: goto x86_l_604b;
	case 24656ULL: goto x86_l_6050;
	case 24661ULL: goto x86_l_6055;
	case 24666ULL: goto x86_l_605a;
	case 24671ULL: goto x86_l_605f;
	case 24676ULL: goto x86_l_6064;
	case 24681ULL: goto x86_l_6069;
	case 24686ULL: goto x86_l_606e;
	case 24689ULL: goto x86_l_6071;
	case 24694ULL: goto x86_l_6076;
	case 24699ULL: goto x86_l_607b;
	case 24702ULL: goto x86_l_607e;
	case 24707ULL: goto x86_l_6083;
	case 24712ULL: goto x86_l_6088;
	case 24715ULL: goto x86_l_608b;
	case 24720ULL: goto x86_l_6090;
	case 24725ULL: goto x86_l_6095;
	case 24728ULL: goto x86_l_6098;
	case 24733ULL: goto x86_l_609d;
	case 24738ULL: goto x86_l_60a2;
	case 24741ULL: goto x86_l_60a5;
	case 24746ULL: goto x86_l_60aa;
	case 24749ULL: goto x86_l_60ad;
	case 24754ULL: goto x86_l_60b2;
	case 24759ULL: goto x86_l_60b7;
	case 24762ULL: goto x86_l_60ba;
	case 24767ULL: goto x86_l_60bf;
	case 24770ULL: goto x86_l_60c2;
	case 24775ULL: goto x86_l_60c7;
	case 24780ULL: goto x86_l_60cc;
	case 24783ULL: goto x86_l_60cf;
	case 24788ULL: goto x86_l_60d4;
	case 24791ULL: goto x86_l_60d7;
	case 24796ULL: goto x86_l_60dc;
	case 24801ULL: goto x86_l_60e1;
	case 24804ULL: goto x86_l_60e4;
	case 24809ULL: goto x86_l_60e9;
	case 24812ULL: goto x86_l_60ec;
	case 24817ULL: goto x86_l_60f1;
	case 24822ULL: goto x86_l_60f6;
	case 24825ULL: goto x86_l_60f9;
	case 24830ULL: goto x86_l_60fe;
	case 24833ULL: goto x86_l_6101;
	case 24838ULL: goto x86_l_6106;
	case 24843ULL: goto x86_l_610b;
	case 24846ULL: goto x86_l_610e;
	case 24851ULL: goto x86_l_6113;
	case 24854ULL: goto x86_l_6116;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5bb3:
	/* 0x5bb3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bb8:
	/* 0x5bb8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bbd:
	/* 0x5bbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bbf:
	/* 0x5bbf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bc1:
	/* 0x5bc1: js     5edd <generic_sleepable_preload+0x5edd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5edd;
	}
x86_l_5bc7:
	/* 0x5bc7: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bcc:
	/* 0x5bcc: cmp    WORD PTR [rcx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_5bd4:
	/* 0x5bd4: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e23;
	}
x86_l_5bda:
	/* 0x5bda: mov    eax,DWORD PTR [rcx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_5be0:
	/* 0x5be0: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5be5:
	/* 0x5be5: cmp    WORD PTR [rcx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_5bed:
	/* 0x5bed: je     5c0d <generic_sleepable_preload+0x5c0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c0d;
	}
x86_l_5bef:
	/* 0x5bef: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5bf4:
	/* 0x5bf4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bf9:
	/* 0x5bf9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bfe:
	/* 0x5bfe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c03:
	/* 0x5c03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c05:
	/* 0x5c05: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c07:
	/* 0x5c07: js     5f8d <generic_sleepable_preload+0x5f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_5f8d;
	}
x86_l_5c0d:
	/* 0x5c0d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c12:
	/* 0x5c12: cmp    WORD PTR [rcx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_5c1a:
	/* 0x5c1a: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e23;
	}
x86_l_5c20:
	/* 0x5c20: mov    eax,DWORD PTR [rcx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_5c26:
	/* 0x5c26: add    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c2b:
	/* 0x5c2b: cmp    WORD PTR [rcx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_5c33:
	/* 0x5c33: je     5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e23;
	}
x86_l_5c39:
	/* 0x5c39: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c3e:
	/* 0x5c3e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c43:
	/* 0x5c43: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c48:
	/* 0x5c48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c4d:
	/* 0x5c4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c4f:
	/* 0x5c4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5c51:
	/* 0x5c51: jns    5e23 <generic_sleepable_preload+0x5e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5e23;
	}
x86_l_5c57:
	/* 0x5c57: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_5c5c:
	/* 0x5c5c: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5c61:
	/* 0x5c61: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_5c66:
	/* 0x5c66: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5c6b:
	/* 0x5c6b: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_5c70:
	/* 0x5c70: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5c75:
	/* 0x5c75: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_5c7a:
	/* 0x5c7a: jmp    5ced <generic_sleepable_preload+0x5ced> */
	goto x86_l_5ced;
x86_l_5c7c:
	/* 0x5c7c: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_5c81:
	/* 0x5c81: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5c86:
	/* 0x5c86: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5c8b:
	/* 0x5c8b: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_5c92:
	/* 0x5c92: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_5c99:
	/* 0x5c99: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_5ca0:
	/* 0x5ca0: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_5ca5:
	/* 0x5ca5: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ca8:
	/* 0x5ca8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cad:
	/* 0x5cad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cb2:
	/* 0x5cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb4:
	/* 0x5cb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cb6:
	/* 0x5cb6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5cb9:
	/* 0x5cb9: je     5073 <generic_sleepable_preload+0x5073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20595ULL;
	}
x86_l_5cbf:
	/* 0x5cbf: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_5cc1:
	/* 0x5cc1: jmp    50ee <generic_sleepable_preload+0x50ee> */
	return 20718ULL;
x86_l_5cc6:
	/* 0x5cc6: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_5ccb:
	/* 0x5ccb: jmp    5ced <generic_sleepable_preload+0x5ced> */
	goto x86_l_5ced;
x86_l_5ccd:
	/* 0x5ccd: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_5cd2:
	/* 0x5cd2: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5cd7:
	/* 0x5cd7: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_5cdc:
	/* 0x5cdc: jmp    5ced <generic_sleepable_preload+0x5ced> */
	goto x86_l_5ced;
x86_l_5cde:
	/* 0x5cde: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_5ce3:
	/* 0x5ce3: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5ce8:
	/* 0x5ce8: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_5ced:
	/* 0x5ced: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5cf0:
	/* 0x5cf0: mov    ebx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5cf3:
	/* 0x5cf3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5cf8:
	/* 0x5cf8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cfd:
	/* 0x5cfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d02:
	/* 0x5d02: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_5d05:
	/* 0x5d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d07:
	/* 0x5d07: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5d0a:
	/* 0x5d0a: jne    4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 20152ULL;
	}
x86_l_5d10:
	/* 0x5d10: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d15:
	/* 0x5d15: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5d1a:
	/* 0x5d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1c:
	/* 0x5d1c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d21:
	/* 0x5d21: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d29:
	/* 0x5d29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d2e:
	/* 0x5d2e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5d35:
	/* 0x5d35: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d3a:
	/* 0x5d3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3c:
	/* 0x5d3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d3f:
	/* 0x5d3f: je     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20152ULL;
	}
x86_l_5d45:
	/* 0x5d45: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5d4b:
	/* 0x5d4b: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5d52:
	/* 0x5d52: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d57:
	/* 0x5d57: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5d5a:
	/* 0x5d5a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5d5d:
	/* 0x5d5d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5d60:
	/* 0x5d60: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d62:
	/* 0x5d62: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5d65:
	/* 0x5d65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d6a:
	/* 0x5d6a: jmp    5e86 <generic_sleepable_preload+0x5e86> */
	goto x86_l_5e86;
x86_l_5d6f:
	/* 0x5d6f: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_5d74:
	/* 0x5d74: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5d79:
	/* 0x5d79: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5d7e:
	/* 0x5d7e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d81:
	/* 0x5d81: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d86:
	/* 0x5d86: jmp    1f2b <generic_sleepable_preload+0x1f2b> */
	return 7979ULL;
x86_l_5d8b:
	/* 0x5d8b: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5d90:
	/* 0x5d90: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d93:
	/* 0x5d93: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d98:
	/* 0x5d98: jmp    1fb2 <generic_sleepable_preload+0x1fb2> */
	return 8114ULL;
x86_l_5d9d:
	/* 0x5d9d: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5da2:
	/* 0x5da2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5da5:
	/* 0x5da5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5daa:
	/* 0x5daa: jmp    2e9e <generic_sleepable_preload+0x2e9e> */
	return 11934ULL;
x86_l_5daf:
	/* 0x5daf: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5db4:
	/* 0x5db4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5db7:
	/* 0x5db7: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dbc:
	/* 0x5dbc: jmp    2f25 <generic_sleepable_preload+0x2f25> */
	return 12069ULL;
x86_l_5dc1:
	/* 0x5dc1: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dc6:
	/* 0x5dc6: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dc9:
	/* 0x5dc9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dce:
	/* 0x5dce: jmp    3e12 <generic_sleepable_preload+0x3e12> */
	return 15890ULL;
x86_l_5dd3:
	/* 0x5dd3: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dd8:
	/* 0x5dd8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ddb:
	/* 0x5ddb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5de0:
	/* 0x5de0: jmp    3e99 <generic_sleepable_preload+0x3e99> */
	return 16025ULL;
x86_l_5de5:
	/* 0x5de5: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dea:
	/* 0x5dea: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ded:
	/* 0x5ded: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5df2:
	/* 0x5df2: jmp    4d81 <generic_sleepable_preload+0x4d81> */
	return 19841ULL;
x86_l_5df7:
	/* 0x5df7: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5dfc:
	/* 0x5dfc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dff:
	/* 0x5dff: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e04:
	/* 0x5e04: jmp    4e08 <generic_sleepable_preload+0x4e08> */
	return 19976ULL;
x86_l_5e09:
	/* 0x5e09: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5e0e:
	/* 0x5e0e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e11:
	/* 0x5e11: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e16:
	/* 0x5e16: jmp    5cf0 <generic_sleepable_preload+0x5cf0> */
	goto x86_l_5cf0;
x86_l_5e1b:
	/* 0x5e1b: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_5e20:
	/* 0x5e20: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e23:
	/* 0x5e23: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5e26:
	/* 0x5e26: jne    4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 20152ULL;
	}
x86_l_5e2c:
	/* 0x5e2c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e31:
	/* 0x5e31: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_5e36:
	/* 0x5e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e38:
	/* 0x5e38: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e3d:
	/* 0x5e3d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e45:
	/* 0x5e45: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e4a:
	/* 0x5e4a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_5e51:
	/* 0x5e51: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e56:
	/* 0x5e56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e58:
	/* 0x5e58: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e5b:
	/* 0x5e5b: je     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20152ULL;
	}
x86_l_5e61:
	/* 0x5e61: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5e67:
	/* 0x5e67: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_5e6e:
	/* 0x5e6e: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e73:
	/* 0x5e73: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5e76:
	/* 0x5e76: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5e79:
	/* 0x5e79: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5e7c:
	/* 0x5e7c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e7e:
	/* 0x5e7e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5e81:
	/* 0x5e81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e86:
	/* 0x5e86: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_5e89:
	/* 0x5e89: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_5e8c:
	/* 0x5e8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e8e:
	/* 0x5e8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e91:
	/* 0x5e91: je     4eb8 <generic_sleepable_preload+0x4eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20152ULL;
	}
x86_l_5e97:
	/* 0x5e97: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_5e9a:
	/* 0x5e9a: je     5ec4 <generic_sleepable_preload+0x5ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ec4;
	}
x86_l_5e9c:
	/* 0x5e9c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5e9f:
	/* 0x5e9f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_5ea3:
	/* 0x5ea3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5ea8:
	/* 0x5ea8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_5eab:
	/* 0x5eab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ead:
	/* 0x5ead: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5eb0:
	/* 0x5eb0: call   5eb5 <generic_sleepable_preload+0x5eb5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_5eb5:
	/* 0x5eb5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5eb7:
	/* 0x5eb7: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5eba:
	/* 0x5eba: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_5ebc:
	/* 0x5ebc: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_5ec1:
	/* 0x5ec1: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5ec4:
	/* 0x5ec4: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ec6:
	/* 0x5ec6: jmp    4eb8 <generic_sleepable_preload+0x4eb8> */
	return 20152ULL;
x86_l_5ecb:
	/* 0x5ecb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ece:
	/* 0x5ece: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ed3:
	/* 0x5ed3: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ed8:
	/* 0x5ed8: jmp    5cf0 <generic_sleepable_preload+0x5cf0> */
	goto x86_l_5cf0;
x86_l_5edd:
	/* 0x5edd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ee0:
	/* 0x5ee0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ee5:
	/* 0x5ee5: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_5ee8:
	/* 0x5ee8: je     5e2c <generic_sleepable_preload+0x5e2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e2c;
	}
x86_l_5eee:
	/* 0x5eee: jmp    4eb8 <generic_sleepable_preload+0x4eb8> */
	return 20152ULL;
x86_l_5ef3:
	/* 0x5ef3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ef6:
	/* 0x5ef6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5efb:
	/* 0x5efb: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f00:
	/* 0x5f00: jmp    1f2b <generic_sleepable_preload+0x1f2b> */
	return 7979ULL;
x86_l_5f05:
	/* 0x5f05: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f08:
	/* 0x5f08: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f0d:
	/* 0x5f0d: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f12:
	/* 0x5f12: jmp    1fb2 <generic_sleepable_preload+0x1fb2> */
	return 8114ULL;
x86_l_5f17:
	/* 0x5f17: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f1a:
	/* 0x5f1a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f1f:
	/* 0x5f1f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f24:
	/* 0x5f24: jmp    2e9e <generic_sleepable_preload+0x2e9e> */
	return 11934ULL;
x86_l_5f29:
	/* 0x5f29: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f2c:
	/* 0x5f2c: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f31:
	/* 0x5f31: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f36:
	/* 0x5f36: jmp    2f25 <generic_sleepable_preload+0x2f25> */
	return 12069ULL;
x86_l_5f3b:
	/* 0x5f3b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f3e:
	/* 0x5f3e: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f43:
	/* 0x5f43: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f48:
	/* 0x5f48: jmp    3e12 <generic_sleepable_preload+0x3e12> */
	return 15890ULL;
x86_l_5f4d:
	/* 0x5f4d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f50:
	/* 0x5f50: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f55:
	/* 0x5f55: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f5a:
	/* 0x5f5a: jmp    3e99 <generic_sleepable_preload+0x3e99> */
	return 16025ULL;
x86_l_5f5f:
	/* 0x5f5f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f62:
	/* 0x5f62: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f67:
	/* 0x5f67: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f6c:
	/* 0x5f6c: jmp    4d81 <generic_sleepable_preload+0x4d81> */
	return 19841ULL;
x86_l_5f71:
	/* 0x5f71: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f74:
	/* 0x5f74: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f79:
	/* 0x5f79: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f7e:
	/* 0x5f7e: jmp    4e08 <generic_sleepable_preload+0x4e08> */
	return 19976ULL;
x86_l_5f83:
	/* 0x5f83: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5f88:
	/* 0x5f88: jmp    5e0e <generic_sleepable_preload+0x5e0e> */
	goto x86_l_5e0e;
x86_l_5f8d:
	/* 0x5f8d: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_5f92:
	/* 0x5f92: jmp    5e20 <generic_sleepable_preload+0x5e20> */
	goto x86_l_5e20;
x86_l_5f97:
	/* 0x5f97: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f9a:
	/* 0x5f9a: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5f9f:
	/* 0x5f9f: jmp    6071 <generic_sleepable_preload+0x6071> */
	goto x86_l_6071;
x86_l_5fa4:
	/* 0x5fa4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fa7:
	/* 0x5fa7: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fac:
	/* 0x5fac: jmp    608b <generic_sleepable_preload+0x608b> */
	goto x86_l_608b;
x86_l_5fb1:
	/* 0x5fb1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fb4:
	/* 0x5fb4: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fb9:
	/* 0x5fb9: jmp    60a5 <generic_sleepable_preload+0x60a5> */
	goto x86_l_60a5;
x86_l_5fbe:
	/* 0x5fbe: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fc1:
	/* 0x5fc1: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fc6:
	/* 0x5fc6: jmp    60ba <generic_sleepable_preload+0x60ba> */
	goto x86_l_60ba;
x86_l_5fcb:
	/* 0x5fcb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fce:
	/* 0x5fce: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fd3:
	/* 0x5fd3: jmp    60cf <generic_sleepable_preload+0x60cf> */
	goto x86_l_60cf;
x86_l_5fd8:
	/* 0x5fd8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fdb:
	/* 0x5fdb: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fe0:
	/* 0x5fe0: jmp    60e4 <generic_sleepable_preload+0x60e4> */
	goto x86_l_60e4;
x86_l_5fe5:
	/* 0x5fe5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fe8:
	/* 0x5fe8: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5fed:
	/* 0x5fed: jmp    60f9 <generic_sleepable_preload+0x60f9> */
	goto x86_l_60f9;
x86_l_5ff2:
	/* 0x5ff2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ff5:
	/* 0x5ff5: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_5ffa:
	/* 0x5ffa: jmp    610e <generic_sleepable_preload+0x610e> */
	goto x86_l_610e;
x86_l_5fff:
	/* 0x5fff: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6004:
	/* 0x6004: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6007:
	/* 0x6007: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_600c:
	/* 0x600c: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6011:
	/* 0x6011: jmp    1f2b <generic_sleepable_preload+0x1f2b> */
	return 7979ULL;
x86_l_6016:
	/* 0x6016: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_601b:
	/* 0x601b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_601e:
	/* 0x601e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6023:
	/* 0x6023: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6028:
	/* 0x6028: jmp    1fb2 <generic_sleepable_preload+0x1fb2> */
	return 8114ULL;
x86_l_602d:
	/* 0x602d: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6032:
	/* 0x6032: jmp    5da2 <generic_sleepable_preload+0x5da2> */
	goto x86_l_5da2;
x86_l_6037:
	/* 0x6037: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_603c:
	/* 0x603c: jmp    5db4 <generic_sleepable_preload+0x5db4> */
	goto x86_l_5db4;
x86_l_6041:
	/* 0x6041: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6046:
	/* 0x6046: jmp    5dc6 <generic_sleepable_preload+0x5dc6> */
	goto x86_l_5dc6;
x86_l_604b:
	/* 0x604b: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6050:
	/* 0x6050: jmp    5dd8 <generic_sleepable_preload+0x5dd8> */
	goto x86_l_5dd8;
x86_l_6055:
	/* 0x6055: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_605a:
	/* 0x605a: jmp    5dea <generic_sleepable_preload+0x5dea> */
	goto x86_l_5dea;
x86_l_605f:
	/* 0x605f: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6064:
	/* 0x6064: jmp    5dfc <generic_sleepable_preload+0x5dfc> */
	goto x86_l_5dfc;
x86_l_6069:
	/* 0x6069: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_606e:
	/* 0x606e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6071:
	/* 0x6071: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6076:
	/* 0x6076: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_607b:
	/* 0x607b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_607e:
	/* 0x607e: jmp    1f2b <generic_sleepable_preload+0x1f2b> */
	return 7979ULL;
x86_l_6083:
	/* 0x6083: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6088:
	/* 0x6088: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_608b:
	/* 0x608b: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6090:
	/* 0x6090: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6095:
	/* 0x6095: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_6098:
	/* 0x6098: jmp    1fb2 <generic_sleepable_preload+0x1fb2> */
	return 8114ULL;
x86_l_609d:
	/* 0x609d: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60a2:
	/* 0x60a2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60a5:
	/* 0x60a5: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60aa:
	/* 0x60aa: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_60ad:
	/* 0x60ad: jmp    2e9e <generic_sleepable_preload+0x2e9e> */
	return 11934ULL;
x86_l_60b2:
	/* 0x60b2: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60b7:
	/* 0x60b7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60ba:
	/* 0x60ba: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60bf:
	/* 0x60bf: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_60c2:
	/* 0x60c2: jmp    2f25 <generic_sleepable_preload+0x2f25> */
	return 12069ULL;
x86_l_60c7:
	/* 0x60c7: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60cc:
	/* 0x60cc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60cf:
	/* 0x60cf: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60d4:
	/* 0x60d4: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_60d7:
	/* 0x60d7: jmp    3e12 <generic_sleepable_preload+0x3e12> */
	return 15890ULL;
x86_l_60dc:
	/* 0x60dc: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60e1:
	/* 0x60e1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60e4:
	/* 0x60e4: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60e9:
	/* 0x60e9: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_60ec:
	/* 0x60ec: jmp    3e99 <generic_sleepable_preload+0x3e99> */
	return 16025ULL;
x86_l_60f1:
	/* 0x60f1: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_60f6:
	/* 0x60f6: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60f9:
	/* 0x60f9: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60fe:
	/* 0x60fe: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_6101:
	/* 0x6101: jmp    4d81 <generic_sleepable_preload+0x4d81> */
	return 19841ULL;
x86_l_6106:
	/* 0x6106: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_610b:
	/* 0x610b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_610e:
	/* 0x610e: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6113:
	/* 0x6113: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_6116:
	/* 0x6116: jmp    4e08 <generic_sleepable_preload+0x4e08> */
	return 19976ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 21216U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1808ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1810ULL && __x86_pc <= 3594ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3599ULL && __x86_pc <= 5355ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5360ULL && __x86_pc <= 7179ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7184ULL && __x86_pc <= 8917ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8922ULL && __x86_pc <= 10761ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10763ULL && __x86_pc <= 12543ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12546ULL && __x86_pc <= 14372ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14375ULL && __x86_pc <= 16181ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16184ULL && __x86_pc <= 18032ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18034ULL && __x86_pc <= 19859ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 19862ULL && __x86_pc <= 21610ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21618ULL && __x86_pc <= 23470ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 23475ULL && __x86_pc <= 24854ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v511_generic_sleepable_preload_x86_chunk_13(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

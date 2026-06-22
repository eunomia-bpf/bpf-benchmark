extern char buffer_heap_map;
extern char data_heap;
extern char execve_calls;
extern char execve_heap;
extern char execve_map;
extern char execve_msg_heap_map;
extern char tcpmon_map;
extern char tg_cgtracker_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_execve_joined_info_map;
extern char tg_execve_joined_info_map_stats;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 18ULL: goto x86_l_12;
	case 20ULL: goto x86_l_14;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 39ULL: goto x86_l_27;
	case 44ULL: goto x86_l_2c;
	case 51ULL: goto x86_l_33;
	case 59ULL: goto x86_l_3b;
	case 61ULL: goto x86_l_3d;
	case 64ULL: goto x86_l_40;
	case 70ULL: goto x86_l_46;
	case 73ULL: goto x86_l_49;
	case 78ULL: goto x86_l_4e;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 88ULL: goto x86_l_58;
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 128ULL: goto x86_l_80;
	case 134ULL: goto x86_l_86;
	case 139ULL: goto x86_l_8b;
	case 144ULL: goto x86_l_90;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 159ULL: goto x86_l_9f;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 188ULL: goto x86_l_bc;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 198ULL: goto x86_l_c6;
	case 204ULL: goto x86_l_cc;
	case 209ULL: goto x86_l_d1;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 270ULL: goto x86_l_10e;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 290ULL: goto x86_l_122;
	case 295ULL: goto x86_l_127;
	case 297ULL: goto x86_l_129;
	case 300ULL: goto x86_l_12c;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 318ULL: goto x86_l_13e;
	case 323ULL: goto x86_l_143;
	case 328ULL: goto x86_l_148;
	case 333ULL: goto x86_l_14d;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 362ULL: goto x86_l_16a;
	case 367ULL: goto x86_l_16f;
	case 372ULL: goto x86_l_174;
	case 377ULL: goto x86_l_179;
	case 379ULL: goto x86_l_17b;
	case 383ULL: goto x86_l_17f;
	case 387ULL: goto x86_l_183;
	case 392ULL: goto x86_l_188;
	case 399ULL: goto x86_l_18f;
	case 404ULL: goto x86_l_194;
	case 406ULL: goto x86_l_196;
	case 409ULL: goto x86_l_199;
	case 411ULL: goto x86_l_19b;
	case 416ULL: goto x86_l_1a0;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 428ULL: goto x86_l_1ac;
	case 433ULL: goto x86_l_1b1;
	case 438ULL: goto x86_l_1b6;
	case 443ULL: goto x86_l_1bb;
	case 445ULL: goto x86_l_1bd;
	case 451ULL: goto x86_l_1c3;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 484ULL: goto x86_l_1e4;
	case 488ULL: goto x86_l_1e8;
	case 493ULL: goto x86_l_1ed;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 519ULL: goto x86_l_207;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 533ULL: goto x86_l_215;
	case 540ULL: goto x86_l_21c;
	case 542ULL: goto x86_l_21e;
	case 544ULL: goto x86_l_220;
	case 551ULL: goto x86_l_227;
	case 556ULL: goto x86_l_22c;
	case 561ULL: goto x86_l_231;
	case 566ULL: goto x86_l_236;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 585ULL: goto x86_l_249;
	case 590ULL: goto x86_l_24e;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 602ULL: goto x86_l_25a;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 610ULL: goto x86_l_262;
	case 617ULL: goto x86_l_269;
	case 628ULL: goto x86_l_274;
	case 633ULL: goto x86_l_279;
	case 640ULL: goto x86_l_280;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 658ULL: goto x86_l_292;
	case 669ULL: goto x86_l_29d;
	case 676ULL: goto x86_l_2a4;
	case 683ULL: goto x86_l_2ab;
	case 688ULL: goto x86_l_2b0;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 709ULL: goto x86_l_2c5;
	case 711ULL: goto x86_l_2c7;
	case 713ULL: goto x86_l_2c9;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 735ULL: goto x86_l_2df;
	case 740ULL: goto x86_l_2e4;
	case 745ULL: goto x86_l_2e9;
	case 747ULL: goto x86_l_2eb;
	case 752ULL: goto x86_l_2f0;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 768ULL: goto x86_l_300;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 781ULL: goto x86_l_30d;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 793ULL: goto x86_l_319;
	case 797ULL: goto x86_l_31d;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 811ULL: goto x86_l_32b;
	case 818ULL: goto x86_l_332;
	case 829ULL: goto x86_l_33d;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 845ULL: goto x86_l_34d;
	case 848ULL: goto x86_l_350;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 859ULL: goto x86_l_35b;
	case 864ULL: goto x86_l_360;
	case 869ULL: goto x86_l_365;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 881ULL: goto x86_l_371;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 910ULL: goto x86_l_38e;
	case 915ULL: goto x86_l_393;
	case 917ULL: goto x86_l_395;
	case 920ULL: goto x86_l_398;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 931ULL: goto x86_l_3a3;
	case 935ULL: goto x86_l_3a7;
	case 942ULL: goto x86_l_3ae;
	case 945ULL: goto x86_l_3b1;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 962ULL: goto x86_l_3c2;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 976ULL: goto x86_l_3d0;
	case 978ULL: goto x86_l_3d2;
	case 980ULL: goto x86_l_3d4;
	case 988ULL: goto x86_l_3dc;
	case 993ULL: goto x86_l_3e1;
	case 1000ULL: goto x86_l_3e8;
	case 1005ULL: goto x86_l_3ed;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1028ULL: goto x86_l_404;
	case 1039ULL: goto x86_l_40f;
	case 1050ULL: goto x86_l_41a;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1065ULL: goto x86_l_429;
	case 1072ULL: goto x86_l_430;
	case 1077ULL: goto x86_l_435;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1094ULL: goto x86_l_446;
	case 1099ULL: goto x86_l_44b;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1109ULL: goto x86_l_455;
	case 1111ULL: goto x86_l_457;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1131ULL: goto x86_l_46b;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1169ULL: goto x86_l_491;
	case 1172ULL: goto x86_l_494;
	case 1178ULL: goto x86_l_49a;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1191ULL: goto x86_l_4a7;
	case 1196ULL: goto x86_l_4ac;
	case 1198ULL: goto x86_l_4ae;
	case 1202ULL: goto x86_l_4b2;
	case 1206ULL: goto x86_l_4b6;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1216ULL: goto x86_l_4c0;
	case 1219ULL: goto x86_l_4c3;
	case 1224ULL: goto x86_l_4c8;
	case 1226ULL: goto x86_l_4ca;
	case 1230ULL: goto x86_l_4ce;
	case 1233ULL: goto x86_l_4d1;
	case 1237ULL: goto x86_l_4d5;
	case 1244ULL: goto x86_l_4dc;
	case 1251ULL: goto x86_l_4e3;
	case 1255ULL: goto x86_l_4e7;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1273ULL: goto x86_l_4f9;
	case 1276ULL: goto x86_l_4fc;
	case 1279ULL: goto x86_l_4ff;
	case 1285ULL: goto x86_l_505;
	case 1291ULL: goto x86_l_50b;
	case 1295ULL: goto x86_l_50f;
	case 1302ULL: goto x86_l_516;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1318ULL: goto x86_l_526;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1336ULL: goto x86_l_538;
	case 1339ULL: goto x86_l_53b;
	case 1345ULL: goto x86_l_541;
	case 1348ULL: goto x86_l_544;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1384ULL: goto x86_l_568;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1402ULL: goto x86_l_57a;
	case 1406ULL: goto x86_l_57e;
	case 1408ULL: goto x86_l_580;
	case 1414ULL: goto x86_l_586;
	case 1416ULL: goto x86_l_588;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1430ULL: goto x86_l_596;
	case 1435ULL: goto x86_l_59b;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1448ULL: goto x86_l_5a8;
	case 1450ULL: goto x86_l_5aa;
	case 1455ULL: goto x86_l_5af;
	case 1459ULL: goto x86_l_5b3;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1467ULL: goto x86_l_5bb;
	case 1471ULL: goto x86_l_5bf;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1497ULL: goto x86_l_5d9;
	case 1503ULL: goto x86_l_5df;
	case 1505ULL: goto x86_l_5e1;
	case 1511ULL: goto x86_l_5e7;
	case 1513ULL: goto x86_l_5e9;
	case 1519ULL: goto x86_l_5ef;
	case 1523ULL: goto x86_l_5f3;
	case 1527ULL: goto x86_l_5f7;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1556ULL: goto x86_l_614;
	case 1559ULL: goto x86_l_617;
	case 1561ULL: goto x86_l_619;
	case 1564ULL: goto x86_l_61c;
	case 1567ULL: goto x86_l_61f;
	case 1573ULL: goto x86_l_625;
	case 1579ULL: goto x86_l_62b;
	case 1582ULL: goto x86_l_62e;
	case 1585ULL: goto x86_l_631;
	case 1589ULL: goto x86_l_635;
	case 1596ULL: goto x86_l_63c;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1627ULL: goto x86_l_65b;
	case 1630ULL: goto x86_l_65e;
	case 1636ULL: goto x86_l_664;
	case 1639ULL: goto x86_l_667;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1671ULL: goto x86_l_687;
	case 1675ULL: goto x86_l_68b;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
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
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_12:
	/* 0x12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14:
	/* 0x14: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17:
	/* 0x17: movzx  r12d,WORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1c:
	/* 0x1c: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_msg_heap_map)));
x86_l_33:
	/* 0x33: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3b:
	/* 0x3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d:
	/* 0x3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: je     26a4 <event_execve+0x26a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9892ULL;
	}
x86_l_46:
	/* 0x46: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_49:
	/* 0x49: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_58:
	/* 0x58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64:
	/* 0x64: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_69:
	/* 0x69: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_6e:
	/* 0x6e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_73:
	/* 0x73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_78:
	/* 0x78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a:
	/* 0x7a: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_80:
	/* 0x80: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_86:
	/* 0x86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b:
	/* 0x8b: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_90:
	/* 0x90: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_95:
	/* 0x95: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a:
	/* 0x9a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_9f:
	/* 0x9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1:
	/* 0xa1: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a5:
	/* 0xa5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9:
	/* 0xa9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ae:
	/* 0xae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_b5:
	/* 0xb5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba:
	/* 0xba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc:
	/* 0xbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: je     cc <event_execve+0xcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc;
	}
x86_l_c1:
	/* 0xc1: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c6:
	/* 0xc6: jne    207 <event_execve+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_207;
	}
x86_l_cc:
	/* 0xcc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d1:
	/* 0xd1: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_d6:
	/* 0xd6: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_db:
	/* 0xdb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0:
	/* 0xe0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e5:
	/* 0xe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7:
	/* 0xe7: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ed:
	/* 0xed: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_f3:
	/* 0xf3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f8:
	/* 0xf8: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_fd:
	/* 0xfd: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_102:
	/* 0x102: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107:
	/* 0x107: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10c:
	/* 0x10c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e:
	/* 0x10e: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112:
	/* 0x112: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_116:
	/* 0x116: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11b:
	/* 0x11b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_122:
	/* 0x122: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_127:
	/* 0x127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129:
	/* 0x129: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: je     139 <event_execve+0x139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_139;
	}
x86_l_12e:
	/* 0x12e: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_133:
	/* 0x133: jne    207 <event_execve+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_207;
	}
x86_l_139:
	/* 0x139: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e:
	/* 0x13e: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_143:
	/* 0x143: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_148:
	/* 0x148: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14d:
	/* 0x14d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_152:
	/* 0x152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154:
	/* 0x154: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_15a:
	/* 0x15a: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_160:
	/* 0x160: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_165:
	/* 0x165: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_16a:
	/* 0x16a: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_16f:
	/* 0x16f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_174:
	/* 0x174: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179:
	/* 0x179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b:
	/* 0x17b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f:
	/* 0x17f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_183:
	/* 0x183: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_188:
	/* 0x188: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_18f:
	/* 0x18f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_194:
	/* 0x194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196:
	/* 0x196: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_199:
	/* 0x199: je     1a2 <event_execve+0x1a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a2;
	}
x86_l_19b:
	/* 0x19b: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1a0:
	/* 0x1a0: jne    207 <event_execve+0x207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_207;
	}
x86_l_1a2:
	/* 0x1a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a7:
	/* 0x1a7: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_1ac:
	/* 0x1ac: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1b1:
	/* 0x1b1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6:
	/* 0x1b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb:
	/* 0x1bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd:
	/* 0x1bd: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c3:
	/* 0x1c3: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_1c5:
	/* 0x1c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ca:
	/* 0x1ca: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_1cf:
	/* 0x1cf: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1d4:
	/* 0x1d4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d9:
	/* 0x1d9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de:
	/* 0x1de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0:
	/* 0x1e0: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4:
	/* 0x1e4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e8:
	/* 0x1e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ed:
	/* 0x1ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1f4:
	/* 0x1f4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f9:
	/* 0x1f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb:
	/* 0x1fb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_200:
	/* 0x200: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_205:
	/* 0x205: je     220 <event_execve+0x220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220;
	}
x86_l_207:
	/* 0x207: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a:
	/* 0x20a: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [r14+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_215:
	/* 0x215: mov    QWORD PTR [r14+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21c:
	/* 0x21c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e:
	/* 0x21e: jmp    279 <event_execve+0x279> */
	goto x86_l_279;
x86_l_220:
	/* 0x220: lea    rdx,[rbp+0xae0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2784ULL);
x86_l_227:
	/* 0x227: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c:
	/* 0x22c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_231:
	/* 0x231: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_236:
	/* 0x236: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238:
	/* 0x238: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23d:
	/* 0x23d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: je     260 <event_execve+0x260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_260;
	}
x86_l_242:
	/* 0x242: add    rdx,0xad4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2772ULL);
x86_l_249:
	/* 0x249: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24e:
	/* 0x24e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_253:
	/* 0x253: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_258:
	/* 0x258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a:
	/* 0x25a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25e:
	/* 0x25e: jmp    262 <event_execve+0x262> */
	goto x86_l_262;
x86_l_260:
	/* 0x260: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262:
	/* 0x262: mov    DWORD PTR [r14+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_269:
	/* 0x269: mov    QWORD PTR [r14+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_274:
	/* 0x274: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_279:
	/* 0x279: mov    QWORD PTR [r14+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_280:
	/* 0x280: mov    DWORD PTR [r14+0x15c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619009ULL);
x86_l_28b:
	/* 0x28b: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_292:
	/* 0x292: mov    QWORD PTR [r14+0x178],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1614907703296ULL);
x86_l_29d:
	/* 0x29d: mov    DWORD PTR [r14+0x144],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_2a4:
	/* 0x2a4: mov    DWORD PTR [r14+0x148],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2ab:
	/* 0x2ab: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2b0:
	/* 0x2b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2:
	/* 0x2b2: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b6:
	/* 0x2b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb:
	/* 0x2bb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c0:
	/* 0x2c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c5:
	/* 0x2c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7:
	/* 0x2c7: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c9:
	/* 0x2c9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2cf:
	/* 0x2cf: je     31d <event_execve+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d;
	}
x86_l_2d1:
	/* 0x2d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d6:
	/* 0x2d6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db:
	/* 0x2db: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2df:
	/* 0x2df: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4:
	/* 0x2e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e9:
	/* 0x2e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb:
	/* 0x2eb: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f0:
	/* 0x2f0: je     31d <event_execve+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31d;
	}
x86_l_2f2:
	/* 0x2f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f7:
	/* 0x2f7: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc:
	/* 0x2fc: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300:
	/* 0x300: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_303:
	/* 0x303: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_306:
	/* 0x306: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_30d:
	/* 0x30d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_312:
	/* 0x312: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_317:
	/* 0x317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319:
	/* 0x319: mov    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31d:
	/* 0x31d: mov    DWORD PTR [r14+0x14c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_324:
	/* 0x324: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_329:
	/* 0x329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b:
	/* 0x32b: mov    QWORD PTR [r14+0x170],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_332:
	/* 0x332: mov    DWORD PTR [r14+0x140],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534784ULL);
x86_l_33d:
	/* 0x33d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_342:
	/* 0x342: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344:
	/* 0x344: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_34d:
	/* 0x34d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_350:
	/* 0x350: je     371 <event_execve+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_371;
	}
x86_l_352:
	/* 0x352: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_356:
	/* 0x356: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_35b:
	/* 0x35b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_360:
	/* 0x360: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_365:
	/* 0x365: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_368:
	/* 0x368: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36a:
	/* 0x36a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36f:
	/* 0x36f: jmp    373 <event_execve+0x373> */
	goto x86_l_373;
x86_l_371:
	/* 0x371: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_373:
	/* 0x373: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_376:
	/* 0x376: mov    DWORD PTR [r14+0x158],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_37d:
	/* 0x37d: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_382:
	/* 0x382: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_387:
	/* 0x387: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_38e:
	/* 0x38e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_393:
	/* 0x393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_395:
	/* 0x395: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_398:
	/* 0x398: je     3f9 <event_execve+0x3f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f9;
	}
x86_l_39a:
	/* 0x39a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c:
	/* 0x39c: mov    DWORD PTR [r14+0x150],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3a3:
	/* 0x3a3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a7:
	/* 0x3a7: mov    QWORD PTR [r14+0x168],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_3ae:
	/* 0x3ae: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b1:
	/* 0x3b1: mov    DWORD PTR [r14+0x160],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3b8:
	/* 0x3b8: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bd:
	/* 0x3bd: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3c2:
	/* 0x3c2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map)));
x86_l_3c9:
	/* 0x3c9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ce:
	/* 0x3ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d0:
	/* 0x3d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d2:
	/* 0x3d2: je     41c <event_execve+0x41c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c;
	}
x86_l_3d4:
	/* 0x3d4: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_3dc:
	/* 0x3dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e1:
	/* 0x3e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_3e8:
	/* 0x3e8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ed:
	/* 0x3ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef:
	/* 0x3ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f2:
	/* 0x3f2: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_3f4:
	/* 0x3f4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f7:
	/* 0x3f7: jmp    43f <event_execve+0x43f> */
	goto x86_l_43f;
x86_l_3f9:
	/* 0x3f9: mov    DWORD PTR [r14+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_404:
	/* 0x404: mov    QWORD PTR [r14+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_40f:
	/* 0x40f: mov    DWORD PTR [r14+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_41a:
	/* 0x41a: jmp    43f <event_execve+0x43f> */
	goto x86_l_43f;
x86_l_41c:
	/* 0x41c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_424:
	/* 0x424: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_429:
	/* 0x429: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_execve_joined_info_map_stats)));
x86_l_430:
	/* 0x430: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_435:
	/* 0x435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_437:
	/* 0x437: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43a:
	/* 0x43a: je     43f <event_execve+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_43c:
	/* 0x43c: dec    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_DEC)), 0ULL);
x86_l_43f:
	/* 0x43f: lea    rdi,[r14+0x180] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_446:
	/* 0x446: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_44b:
	/* 0x44b: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_450:
	/* 0x450: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_453:
	/* 0x453: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_455:
	/* 0x455: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_457:
	/* 0x457: mov    QWORD PTR [rsp+0xb0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_45f:
	/* 0x45f: js     588 <event_execve+0x588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_588;
	}
x86_l_465:
	/* 0x465: je     594 <event_execve+0x594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_594;
	}
x86_l_46b:
	/* 0x46b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_470:
	/* 0x470: jne    59b <event_execve+0x59b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_59b;
	}
x86_l_476:
	/* 0x476: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47e:
	/* 0x47e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_483:
	/* 0x483: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_48a:
	/* 0x48a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f:
	/* 0x48f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491:
	/* 0x491: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: je     588 <event_execve+0x588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_588;
	}
x86_l_49a:
	/* 0x49a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_49d:
	/* 0x49d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4a0:
	/* 0x4a0: mov    DWORD PTR [rbp+0x0],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a7:
	/* 0x4a7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_4ac:
	/* 0x4ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae:
	/* 0x4ae: lea    rbx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b2:
	/* 0x4b2: mov    QWORD PTR [rbp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b6:
	/* 0x4b6: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_4ba:
	/* 0x4ba: jne    4c3 <event_execve+0x4c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c3;
	}
x86_l_4bc:
	/* 0x4bc: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c0:
	/* 0x4c0: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c3:
	/* 0x4c3: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_4c8:
	/* 0x4c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ce:
	/* 0x4ce: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d1:
	/* 0x4d1: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d5:
	/* 0x4d5: mov    QWORD PTR [r14+0x190],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [r14+0x198],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_4e3:
	/* 0x4e3: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_4e7:
	/* 0x4e7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ec:
	/* 0x4ec: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_4f4:
	/* 0x4f4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f9:
	/* 0x4f9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4fc:
	/* 0x4fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ff:
	/* 0x4ff: js     6fb <event_execve+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1787ULL;
	}
x86_l_505:
	/* 0x505: je     5a6 <event_execve+0x5a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a6;
	}
x86_l_50b:
	/* 0x50b: lea    r8d,[rbx+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_50f:
	/* 0x50f: and    r8d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_516:
	/* 0x516: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_51a:
	/* 0x51a: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_51f:
	/* 0x51f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_526:
	/* 0x526: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_52b:
	/* 0x52b: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_530:
	/* 0x530: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_533:
	/* 0x533: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_536:
	/* 0x536: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_538:
	/* 0x538: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53b:
	/* 0x53b: jns    5f3 <event_execve+0x5f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5f3;
	}
x86_l_541:
	/* 0x541: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_544:
	/* 0x544: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_54c:
	/* 0x54c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_551:
	/* 0x551: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_558:
	/* 0x558: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_55d:
	/* 0x55d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f:
	/* 0x55f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_562:
	/* 0x562: je     5f3 <event_execve+0x5f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f3;
	}
x86_l_568:
	/* 0x568: cmp    r15,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_56c:
	/* 0x56c: jg     5af <event_execve+0x5af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5af;
	}
x86_l_56e:
	/* 0x56e: cmp    r15,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_572:
	/* 0x572: je     5c9 <event_execve+0x5c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c9;
	}
x86_l_574:
	/* 0x574: cmp    r15,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_578:
	/* 0x578: je     5e1 <event_execve+0x5e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e1;
	}
x86_l_57a:
	/* 0x57a: cmp    r15,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_57e:
	/* 0x57e: jne    5d9 <event_execve+0x5d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5d9;
	}
x86_l_580:
	/* 0x580: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_586:
	/* 0x586: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_588:
	/* 0x588: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58a:
	/* 0x58a: mov    eax,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_58f:
	/* 0x58f: jmp    72c <event_execve+0x72c> */
	return 1836ULL;
x86_l_594:
	/* 0x594: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_596:
	/* 0x596: jmp    72c <event_execve+0x72c> */
	return 1836ULL;
x86_l_59b:
	/* 0x59b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_59d:
	/* 0x59d: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_59f:
	/* 0x59f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a1:
	/* 0x5a1: jmp    72c <event_execve+0x72c> */
	return 1836ULL;
x86_l_5a6:
	/* 0x5a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a8:
	/* 0x5a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5aa:
	/* 0x5aa: jmp    709 <event_execve+0x709> */
	return 1801ULL;
x86_l_5af:
	/* 0x5af: cmp    r15,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_5b3:
	/* 0x5b3: je     5d1 <event_execve+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1;
	}
x86_l_5b5:
	/* 0x5b5: cmp    r15,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_5b9:
	/* 0x5b9: je     5e9 <event_execve+0x5e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e9;
	}
x86_l_5bb:
	/* 0x5bb: cmp    r15,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_5bf:
	/* 0x5bf: jne    5d9 <event_execve+0x5d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5d9;
	}
x86_l_5c1:
	/* 0x5c1: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_5c7:
	/* 0x5c7: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_5c9:
	/* 0x5c9: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_5cf:
	/* 0x5cf: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_5d1:
	/* 0x5d1: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_5d7:
	/* 0x5d7: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_5d9:
	/* 0x5d9: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_5df:
	/* 0x5df: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_5e1:
	/* 0x5e1: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_5e7:
	/* 0x5e7: jmp    5ef <event_execve+0x5ef> */
	goto x86_l_5ef;
x86_l_5e9:
	/* 0x5e9: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_5ef:
	/* 0x5ef: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5f3:
	/* 0x5f3: lea    r15,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5f7:
	/* 0x5f7: cmp    rbx,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 32735ULL);
x86_l_5fe:
	/* 0x5fe: jne    6a7 <event_execve+0x6a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1703ULL;
	}
x86_l_604:
	/* 0x604: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_607:
	/* 0x607: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_60c:
	/* 0x60c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_60f:
	/* 0x60f: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_614:
	/* 0x614: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_617:
	/* 0x617: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_619:
	/* 0x619: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_61c:
	/* 0x61c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61f:
	/* 0x61f: js     6f6 <event_execve+0x6f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1782ULL;
	}
x86_l_625:
	/* 0x625: je     6a7 <event_execve+0x6a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1703ULL;
	}
x86_l_62b:
	/* 0x62b: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_631:
	/* 0x631: lea    r8d,[rbx+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_635:
	/* 0x635: and    r8d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_63c:
	/* 0x63c: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_640:
	/* 0x640: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_645:
	/* 0x645: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_64c:
	/* 0x64c: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_651:
	/* 0x651: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_656:
	/* 0x656: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_659:
	/* 0x659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65b:
	/* 0x65b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65e:
	/* 0x65e: jns    6f0 <event_execve+0x6f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1776ULL;
	}
x86_l_664:
	/* 0x664: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_667:
	/* 0x667: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_66f:
	/* 0x66f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_674:
	/* 0x674: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_67b:
	/* 0x67b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_680:
	/* 0x680: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_682:
	/* 0x682: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_685:
	/* 0x685: je     6f0 <event_execve+0x6f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1776ULL;
	}
x86_l_687:
	/* 0x687: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_68b:
	/* 0x68b: jg     6ac <event_execve+0x6ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1708ULL;
	}
x86_l_68d:
	/* 0x68d: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_691:
	/* 0x691: je     6c6 <event_execve+0x6c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1734ULL;
	}
	return 1683ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1683ULL: goto x86_l_693;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1695ULL: goto x86_l_69f;
	case 1701ULL: goto x86_l_6a5;
	case 1703ULL: goto x86_l_6a7;
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1712ULL: goto x86_l_6b0;
	case 1714ULL: goto x86_l_6b2;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
	case 1732ULL: goto x86_l_6c4;
	case 1734ULL: goto x86_l_6c6;
	case 1740ULL: goto x86_l_6cc;
	case 1742ULL: goto x86_l_6ce;
	case 1748ULL: goto x86_l_6d4;
	case 1750ULL: goto x86_l_6d6;
	case 1756ULL: goto x86_l_6dc;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1766ULL: goto x86_l_6e6;
	case 1772ULL: goto x86_l_6ec;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1789ULL: goto x86_l_6fd;
	case 1792ULL: goto x86_l_700;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1801ULL: goto x86_l_709;
	case 1808ULL: goto x86_l_710;
	case 1819ULL: goto x86_l_71b;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1844ULL: goto x86_l_734;
	case 1851ULL: goto x86_l_73b;
	case 1858ULL: goto x86_l_742;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1876ULL: goto x86_l_754;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1908ULL: goto x86_l_774;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1922ULL: goto x86_l_782;
	case 1932ULL: goto x86_l_78c;
	case 1937ULL: goto x86_l_791;
	case 1942ULL: goto x86_l_796;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1956ULL: goto x86_l_7a4;
	case 1959ULL: goto x86_l_7a7;
	case 1961ULL: goto x86_l_7a9;
	case 1963ULL: goto x86_l_7ab;
	case 1965ULL: goto x86_l_7ad;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1997ULL: goto x86_l_7cd;
	case 1999ULL: goto x86_l_7cf;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2017ULL: goto x86_l_7e1;
	case 2023ULL: goto x86_l_7e7;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2057ULL: goto x86_l_809;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2064ULL: goto x86_l_810;
	case 2066ULL: goto x86_l_812;
	case 2071ULL: goto x86_l_817;
	case 2078ULL: goto x86_l_81e;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2098ULL: goto x86_l_832;
	case 2105ULL: goto x86_l_839;
	case 2110ULL: goto x86_l_83e;
	case 2112ULL: goto x86_l_840;
	case 2115ULL: goto x86_l_843;
	case 2117ULL: goto x86_l_845;
	case 2119ULL: goto x86_l_847;
	case 2121ULL: goto x86_l_849;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2141ULL: goto x86_l_85d;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2153ULL: goto x86_l_869;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2188ULL: goto x86_l_88c;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2204ULL: goto x86_l_89c;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2224ULL: goto x86_l_8b0;
	case 2231ULL: goto x86_l_8b7;
	case 2236ULL: goto x86_l_8bc;
	case 2238ULL: goto x86_l_8be;
	case 2241ULL: goto x86_l_8c1;
	case 2247ULL: goto x86_l_8c7;
	case 2249ULL: goto x86_l_8c9;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2267ULL: goto x86_l_8db;
	case 2273ULL: goto x86_l_8e1;
	case 2279ULL: goto x86_l_8e7;
	case 2285ULL: goto x86_l_8ed;
	case 2290ULL: goto x86_l_8f2;
	case 2297ULL: goto x86_l_8f9;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2313ULL: goto x86_l_909;
	case 2316ULL: goto x86_l_90c;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2342ULL: goto x86_l_926;
	case 2348ULL: goto x86_l_92c;
	case 2351ULL: goto x86_l_92f;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2384ULL: goto x86_l_950;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2399ULL: goto x86_l_95f;
	case 2402ULL: goto x86_l_962;
	case 2409ULL: goto x86_l_969;
	case 2415ULL: goto x86_l_96f;
	case 2419ULL: goto x86_l_973;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2434ULL: goto x86_l_982;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2460ULL: goto x86_l_99c;
	case 2463ULL: goto x86_l_99f;
	case 2466ULL: goto x86_l_9a2;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2488ULL: goto x86_l_9b8;
	case 2494ULL: goto x86_l_9be;
	case 2497ULL: goto x86_l_9c1;
	case 2499ULL: goto x86_l_9c3;
	case 2504ULL: goto x86_l_9c8;
	case 2511ULL: goto x86_l_9cf;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2545ULL: goto x86_l_9f1;
	case 2548ULL: goto x86_l_9f4;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2582ULL: goto x86_l_a16;
	case 2587ULL: goto x86_l_a1b;
	case 2594ULL: goto x86_l_a22;
	case 2599ULL: goto x86_l_a27;
	case 2607ULL: goto x86_l_a2f;
	case 2609ULL: goto x86_l_a31;
	case 2611ULL: goto x86_l_a33;
	case 2617ULL: goto x86_l_a39;
	case 2623ULL: goto x86_l_a3f;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2642ULL: goto x86_l_a52;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2665ULL: goto x86_l_a69;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2678ULL: goto x86_l_a76;
	case 2684ULL: goto x86_l_a7c;
	case 2687ULL: goto x86_l_a7f;
	case 2690ULL: goto x86_l_a82;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2711ULL: goto x86_l_a97;
	case 2715ULL: goto x86_l_a9b;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2736ULL: goto x86_l_ab0;
	case 2740ULL: goto x86_l_ab4;
	case 2743ULL: goto x86_l_ab7;
	case 2747ULL: goto x86_l_abb;
	case 2754ULL: goto x86_l_ac2;
	case 2761ULL: goto x86_l_ac9;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2779ULL: goto x86_l_adb;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2795ULL: goto x86_l_aeb;
	case 2801ULL: goto x86_l_af1;
	case 2804ULL: goto x86_l_af4;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2837ULL: goto x86_l_b15;
	case 2841ULL: goto x86_l_b19;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2867ULL: goto x86_l_b33;
	case 2870ULL: goto x86_l_b36;
	case 2872ULL: goto x86_l_b38;
	case 2874ULL: goto x86_l_b3a;
	case 2876ULL: goto x86_l_b3c;
	case 2879ULL: goto x86_l_b3f;
	case 2881ULL: goto x86_l_b41;
	case 2889ULL: goto x86_l_b49;
	case 2895ULL: goto x86_l_b4f;
	case 2898ULL: goto x86_l_b52;
	case 2901ULL: goto x86_l_b55;
	case 2904ULL: goto x86_l_b58;
	case 2910ULL: goto x86_l_b5e;
	case 2916ULL: goto x86_l_b64;
	case 2919ULL: goto x86_l_b67;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2935ULL: goto x86_l_b77;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2954ULL: goto x86_l_b8a;
	case 2959ULL: goto x86_l_b8f;
	case 2961ULL: goto x86_l_b91;
	case 2963ULL: goto x86_l_b93;
	case 2965ULL: goto x86_l_b95;
	case 2970ULL: goto x86_l_b9a;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2983ULL: goto x86_l_ba7;
	case 2990ULL: goto x86_l_bae;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3003ULL: goto x86_l_bbb;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3019ULL: goto x86_l_bcb;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3042ULL: goto x86_l_be2;
	case 3045ULL: goto x86_l_be5;
	case 3051ULL: goto x86_l_beb;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3092ULL: goto x86_l_c14;
	case 3100ULL: goto x86_l_c1c;
	case 3102ULL: goto x86_l_c1e;
	case 3104ULL: goto x86_l_c20;
	case 3106ULL: goto x86_l_c22;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3143ULL: goto x86_l_c47;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3160ULL: goto x86_l_c58;
	case 3165ULL: goto x86_l_c5d;
	case 3171ULL: goto x86_l_c63;
	case 3174ULL: goto x86_l_c66;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3183ULL: goto x86_l_c6f;
	case 3189ULL: goto x86_l_c75;
	case 3195ULL: goto x86_l_c7b;
	case 3199ULL: goto x86_l_c7f;
	case 3206ULL: goto x86_l_c86;
	case 3211ULL: goto x86_l_c8b;
	case 3215ULL: goto x86_l_c8f;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3254ULL: goto x86_l_cb6;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3306ULL: goto x86_l_cea;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3338ULL: goto x86_l_d0a;
	case 3344ULL: goto x86_l_d10;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3360ULL: goto x86_l_d20;
	case 3367ULL: goto x86_l_d27;
	case 3372ULL: goto x86_l_d2c;
	case 3376ULL: goto x86_l_d30;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3403ULL: goto x86_l_d4b;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3416ULL: goto x86_l_d58;
	default: return 0xffffffffffffffffULL;
	}
x86_l_693:
	/* 0x693: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_697:
	/* 0x697: je     6de <event_execve+0x6de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6de;
	}
x86_l_699:
	/* 0x699: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_69d:
	/* 0x69d: jne    6d6 <event_execve+0x6d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6d6;
	}
x86_l_69f:
	/* 0x69f: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_6a5:
	/* 0x6a5: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6a7:
	/* 0x6a7: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_6aa:
	/* 0x6aa: jmp    6f6 <event_execve+0x6f6> */
	goto x86_l_6f6;
x86_l_6ac:
	/* 0x6ac: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_6b0:
	/* 0x6b0: je     6ce <event_execve+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ce;
	}
x86_l_6b2:
	/* 0x6b2: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_6b6:
	/* 0x6b6: je     6e6 <event_execve+0x6e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e6;
	}
x86_l_6b8:
	/* 0x6b8: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_6bc:
	/* 0x6bc: jne    6d6 <event_execve+0x6d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6d6;
	}
x86_l_6be:
	/* 0x6be: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_6c4:
	/* 0x6c4: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6c6:
	/* 0x6c6: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_6cc:
	/* 0x6cc: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6ce:
	/* 0x6ce: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_6d4:
	/* 0x6d4: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6d6:
	/* 0x6d6: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_6dc:
	/* 0x6dc: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6de:
	/* 0x6de: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_6e4:
	/* 0x6e4: jmp    6ec <event_execve+0x6ec> */
	goto x86_l_6ec;
x86_l_6e6:
	/* 0x6e6: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_6ec:
	/* 0x6ec: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6f0:
	/* 0x6f0: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6f3:
	/* 0x6f3: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_6f6:
	/* 0x6f6: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fb:
	/* 0x6fb: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_6fd:
	/* 0x6fd: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_700:
	/* 0x700: and    eax,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_32, X86_ALU_AND);
x86_l_702:
	/* 0x702: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_704:
	/* 0x704: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_706:
	/* 0x706: cmovg  ecx,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_32, X86_CC_G);
x86_l_709:
	/* 0x709: mov    DWORD PTR [r14+0x180],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_710:
	/* 0x710: mov    QWORD PTR [r14+0x184],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_71b:
	/* 0x71b: mov    DWORD PTR [r14+0x18c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 396ULL);
x86_l_722:
	/* 0x722: mov    ecx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_727:
	/* 0x727: mov    eax,0x800000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8388608ULL);
x86_l_72c:
	/* 0x72c: mov    WORD PTR [r14+0x178],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_734:
	/* 0x734: or     DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_73b:
	/* 0x73b: add    DWORD PTR [r14+0x140],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_742:
	/* 0x742: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_747:
	/* 0x747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_749:
	/* 0x749: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_754:
	/* 0x754: lea    rdx,[rax+0xa50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_75b:
	/* 0x75b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_760:
	/* 0x760: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_768:
	/* 0x768: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76d:
	/* 0x76d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76f:
	/* 0x76f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_772:
	/* 0x772: je     7cf <event_execve+0x7cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7cf;
	}
x86_l_774:
	/* 0x774: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_776:
	/* 0x776: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77b:
	/* 0x77b: mov    WORD PTR [rsp+0x32],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364809ULL);
x86_l_782:
	/* 0x782: movabs rax,0x400000042 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869250ULL);
x86_l_78c:
	/* 0x78c: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_791:
	/* 0x791: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_796:
	/* 0x796: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_79d:
	/* 0x79d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a2:
	/* 0x7a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a4:
	/* 0x7a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a7:
	/* 0x7a7: je     7ad <event_execve+0x7ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7ad;
	}
x86_l_7a9:
	/* 0x7a9: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7ab:
	/* 0x7ab: jmp    7cf <event_execve+0x7cf> */
	goto x86_l_7cf;
x86_l_7ad:
	/* 0x7ad: mov    DWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_7b5:
	/* 0x7b5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7ba:
	/* 0x7ba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_7c1:
	/* 0x7c1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c6:
	/* 0x7c6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7cb:
	/* 0x7cb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7cd:
	/* 0x7cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cf:
	/* 0x7cf: lea    r12,[r14+0x140] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_7d6:
	/* 0x7d6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d8:
	/* 0x7d8: cmp    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_7e1:
	/* 0x7e1: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_7e7:
	/* 0x7e7: je     119b <event_execve+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4507ULL;
	}
x86_l_7ed:
	/* 0x7ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7f2:
	/* 0x7f2: mov    edx,0x188 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 392ULL);
x86_l_7f7:
	/* 0x7f7: add    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_7ff:
	/* 0x7ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_804:
	/* 0x804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_809:
	/* 0x809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80b:
	/* 0x80b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80e:
	/* 0x80e: je     86b <event_execve+0x86b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_86b;
	}
x86_l_810:
	/* 0x810: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_812:
	/* 0x812: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_817:
	/* 0x817: mov    WORD PTR [rsp+0x32],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364809ULL);
x86_l_81e:
	/* 0x81e: movabs rax,0x400000047 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869255ULL);
x86_l_828:
	/* 0x828: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_82d:
	/* 0x82d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_832:
	/* 0x832: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_839:
	/* 0x839: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83e:
	/* 0x83e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_840:
	/* 0x840: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_843:
	/* 0x843: je     849 <event_execve+0x849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_849;
	}
x86_l_845:
	/* 0x845: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_847:
	/* 0x847: jmp    86b <event_execve+0x86b> */
	goto x86_l_86b;
x86_l_849:
	/* 0x849: mov    DWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_851:
	/* 0x851: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_856:
	/* 0x856: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_85d:
	/* 0x85d: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_862:
	/* 0x862: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_867:
	/* 0x867: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_869:
	/* 0x869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86b:
	/* 0x86b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_870:
	/* 0x870: mov    edx,0x190 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 400ULL);
x86_l_875:
	/* 0x875: add    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_87d:
	/* 0x87d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_882:
	/* 0x882: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_887:
	/* 0x887: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_889:
	/* 0x889: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_88c:
	/* 0x88c: je     8c9 <event_execve+0x8c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c9;
	}
x86_l_88e:
	/* 0x88e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_890:
	/* 0x890: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_895:
	/* 0x895: mov    WORD PTR [rsp+0x32],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364809ULL);
x86_l_89c:
	/* 0x89c: movabs rax,0x400000048 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869256ULL);
x86_l_8a6:
	/* 0x8a6: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8ab:
	/* 0x8ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b0:
	/* 0x8b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_8b7:
	/* 0x8b7: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8bc:
	/* 0x8bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8be:
	/* 0x8be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c1:
	/* 0x8c1: je     a0b <event_execve+0xa0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a0b;
	}
x86_l_8c7:
	/* 0x8c7: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8c9:
	/* 0x8c9: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8cf:
	/* 0x8cf: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_8d5:
	/* 0x8d5: je     119b <event_execve+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4507ULL;
	}
x86_l_8db:
	/* 0x8db: cmp    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8e1:
	/* 0x8e1: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_8e7:
	/* 0x8e7: je     119b <event_execve+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4507ULL;
	}
x86_l_8ed:
	/* 0x8ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f2:
	/* 0x8f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_heap)));
x86_l_8f9:
	/* 0x8f9: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_901:
	/* 0x901: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_903:
	/* 0x903: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_909:
	/* 0x909: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90c:
	/* 0x90c: je     119b <event_execve+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4507ULL;
	}
x86_l_912:
	/* 0x912: mov    ecx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 45ULL);
x86_l_917:
	/* 0x917: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91c:
	/* 0x91c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_924:
	/* 0x924: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_926:
	/* 0x926: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_92c:
	/* 0x92c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_92f:
	/* 0x92f: js     119b <event_execve+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4507ULL;
	}
x86_l_935:
	/* 0x935: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93a:
	/* 0x93a: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93f:
	/* 0x93f: add    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_944:
	/* 0x944: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_949:
	/* 0x949: mov    r15d,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_950:
	/* 0x950: and    r15d,0x1ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 511ULL);
x86_l_957:
	/* 0x957: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95c:
	/* 0x95c: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_95f:
	/* 0x95f: sub    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_962:
	/* 0x962: cmp    r12,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1023ULL);
x86_l_969:
	/* 0x969: ja     a4a <event_execve+0xa4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a4a;
	}
x86_l_96f:
	/* 0x96f: lea    rdi,[r14+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_973:
	/* 0x973: add    rdi,0x140 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 320ULL);
x86_l_97a:
	/* 0x97a: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_97f:
	/* 0x97f: sub    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_982:
	/* 0x982: add    rdx,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 1024ULL);
x86_l_989:
	/* 0x989: cmp    r12,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: jae    a4a <event_execve+0xa4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a4a;
	}
x86_l_992:
	/* 0x992: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_995:
	/* 0x995: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_99c:
	/* 0x99c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99f:
	/* 0x99f: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9a2:
	/* 0x9a2: cmovne r13d,r12d */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_32, X86_CC_NE);
x86_l_9a6:
	/* 0x9a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9ab:
	/* 0x9ab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b0:
	/* 0x9b0: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_9b3:
	/* 0x9b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b5:
	/* 0x9b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b8:
	/* 0x9b8: je     1189 <event_execve+0x1189> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4489ULL;
	}
x86_l_9be:
	/* 0x9be: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_9c1:
	/* 0x9c1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_9c3:
	/* 0x9c3: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c8:
	/* 0x9c8: mov    WORD PTR [rsp+0x32],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364809ULL);
x86_l_9cf:
	/* 0x9cf: movabs rax,0x40000006c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17179869292ULL);
x86_l_9d9:
	/* 0x9d9: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9de:
	/* 0x9de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e3:
	/* 0x9e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_9ea:
	/* 0x9ea: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ef:
	/* 0x9ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f1:
	/* 0x9f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9f4:
	/* 0x9f4: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f9:
	/* 0x9f9: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9fe:
	/* 0x9fe: je     106c <event_execve+0x106c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4204ULL;
	}
x86_l_a04:
	/* 0xa04: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a06:
	/* 0xa06: jmp    1094 <event_execve+0x1094> */
	return 4244ULL;
x86_l_a0b:
	/* 0xa0b: mov    DWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_a16:
	/* 0xa16: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a1b:
	/* 0xa1b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_a22:
	/* 0xa22: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a27:
	/* 0xa27: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a2f:
	/* 0xa2f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a31:
	/* 0xa31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a33:
	/* 0xa33: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a39:
	/* 0xa39: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_a3f:
	/* 0xa3f: jne    8db <event_execve+0x8db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8db;
	}
x86_l_a45:
	/* 0xa45: jmp    119b <event_execve+0x119b> */
	return 4507ULL;
x86_l_a4a:
	/* 0xa4a: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a52:
	/* 0xa52: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_a5d:
	/* 0xa5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a62:
	/* 0xa62: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_a69:
	/* 0xa69: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a71:
	/* 0xa71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a73:
	/* 0xa73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a76:
	/* 0xa76: je     1059 <event_execve+0x1059> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4185ULL;
	}
x86_l_a7c:
	/* 0xa7c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_a7f:
	/* 0xa7f: add    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a82:
	/* 0xa82: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a88:
	/* 0xa88: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a8d:
	/* 0xa8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8f:
	/* 0xa8f: lea    rbx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a93:
	/* 0xa93: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a97:
	/* 0xa97: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_a9b:
	/* 0xa9b: jne    aa9 <event_execve+0xaa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aa9;
	}
x86_l_a9d:
	/* 0xa9d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa2:
	/* 0xaa2: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa6:
	/* 0xaa6: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa9:
	/* 0xaa9: mov    eax,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_aae:
	/* 0xaae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab0:
	/* 0xab0: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ab4:
	/* 0xab4: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab7:
	/* 0xab7: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_abb:
	/* 0xabb: mov    QWORD PTR [r15+0x150],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_ac2:
	/* 0xac2: mov    QWORD PTR [r15+0x158],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_ac9:
	/* 0xac9: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: js     1061 <event_execve+0x1061> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4193ULL;
	}
x86_l_ad2:
	/* 0xad2: mov    QWORD PTR [rsp+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_adb:
	/* 0xadb: cmp    r12,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 32736ULL);
x86_l_ae2:
	/* 0xae2: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_ae7:
	/* 0xae7: cmovb  rbx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_R12, X86_WIDTH_64, X86_CC_B);
x86_l_aeb:
	/* 0xaeb: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_af1:
	/* 0xaf1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_af4:
	/* 0xaf4: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_af8:
	/* 0xaf8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_afd:
	/* 0xafd: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b05:
	/* 0xb05: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_b07:
	/* 0xb07: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b0f:
	/* 0xb0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b11:
	/* 0xb11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b13:
	/* 0xb13: js     b3c <event_execve+0xb3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b3c;
	}
x86_l_b15:
	/* 0xb15: lea    r8d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b19:
	/* 0xb19: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b1d:
	/* 0xb1d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_b22:
	/* 0xb22: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_b29:
	/* 0xb29: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_b2e:
	/* 0xb2e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b33:
	/* 0xb33: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_b36:
	/* 0xb36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b38:
	/* 0xb38: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3a:
	/* 0xb3a: jns    b3f <event_execve+0xb3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_b3f;
	}
x86_l_b3c:
	/* 0xb3c: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_b3f:
	/* 0xb3f: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_b41:
	/* 0xb41: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b49:
	/* 0xb49: js     10ac <event_execve+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4268ULL;
	}
x86_l_b4f:
	/* 0xb4f: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_b52:
	/* 0xb52: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_b55:
	/* 0xb55: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b58:
	/* 0xb58: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4413ULL;
	}
x86_l_b5e:
	/* 0xb5e: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4273ULL;
	}
x86_l_b64:
	/* 0xb64: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b67:
	/* 0xb67: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_b6e:
	/* 0xb6e: mov    esi,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32736ULL);
x86_l_b73:
	/* 0xb73: cmovb  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_b77:
	/* 0xb77: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_b7d:
	/* 0xb7d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b82:
	/* 0xb82: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b8a:
	/* 0xb8a: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b8f:
	/* 0xb8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b91:
	/* 0xb91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b93:
	/* 0xb93: js     bc6 <event_execve+0xbc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_bc6;
	}
x86_l_b95:
	/* 0xb95: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b9a:
	/* 0xb9a: lea    r8d,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b9e:
	/* 0xb9e: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ba2:
	/* 0xba2: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_ba7:
	/* 0xba7: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_bae:
	/* 0xbae: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_bb3:
	/* 0xbb3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb8:
	/* 0xbb8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_bbb:
	/* 0xbbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbd:
	/* 0xbbd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbf:
	/* 0xbbf: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bc4:
	/* 0xbc4: jns    bc9 <event_execve+0xbc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_bc9;
	}
x86_l_bc6:
	/* 0xbc6: movsxd rdx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_bc9:
	/* 0xbc9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_bcb:
	/* 0xbcb: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bd3:
	/* 0xbd3: js     24d9 <event_execve+0x24d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9433ULL;
	}
x86_l_bd9:
	/* 0xbd9: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bdc:
	/* 0xbdc: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_bdf:
	/* 0xbdf: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: sub    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_be5:
	/* 0xbe5: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4413ULL;
	}
x86_l_beb:
	/* 0xbeb: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4273ULL;
	}
x86_l_bf1:
	/* 0xbf1: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bf6:
	/* 0xbf6: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bf9:
	/* 0xbf9: cmp    rsi,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 32736ULL);
x86_l_c00:
	/* 0xc00: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_c05:
	/* 0xc05: cmovb  rbx,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_c09:
	/* 0xc09: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_c0f:
	/* 0xc0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c14:
	/* 0xc14: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c1c:
	/* 0xc1c: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_c1e:
	/* 0xc1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c20:
	/* 0xc20: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c22:
	/* 0xc22: js     c4b <event_execve+0xc4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_c4b;
	}
x86_l_c24:
	/* 0xc24: lea    r8d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c28:
	/* 0xc28: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c2c:
	/* 0xc2c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_c31:
	/* 0xc31: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_c38:
	/* 0xc38: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_c3d:
	/* 0xc3d: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c42:
	/* 0xc42: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_c45:
	/* 0xc45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c47:
	/* 0xc47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c49:
	/* 0xc49: jns    c4e <event_execve+0xc4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_c4e;
	}
x86_l_c4b:
	/* 0xc4b: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_c4e:
	/* 0xc4e: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_c50:
	/* 0xc50: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c58:
	/* 0xc58: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c5d:
	/* 0xc5d: js     10ac <event_execve+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4268ULL;
	}
x86_l_c63:
	/* 0xc63: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c66:
	/* 0xc66: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c69:
	/* 0xc69: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_c6c:
	/* 0xc6c: sub    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c6f:
	/* 0xc6f: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4413ULL;
	}
x86_l_c75:
	/* 0xc75: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4273ULL;
	}
x86_l_c7b:
	/* 0xc7b: lea    rdx,[rbx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c7f:
	/* 0xc7f: cmp    rdi,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 32736ULL);
x86_l_c86:
	/* 0xc86: mov    esi,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32736ULL);
x86_l_c8b:
	/* 0xc8b: cmovb  rsi,rdi */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDI, X86_WIDTH_64, X86_CC_B);
x86_l_c8f:
	/* 0xc8f: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_c95:
	/* 0xc95: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c9a:
	/* 0xc9a: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ca7:
	/* 0xca7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca9:
	/* 0xca9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cab:
	/* 0xcab: js     cd9 <event_execve+0xcd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_cd9;
	}
x86_l_cad:
	/* 0xcad: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cb2:
	/* 0xcb2: lea    r8d,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb6:
	/* 0xcb6: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cba:
	/* 0xcba: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_cbf:
	/* 0xcbf: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_cc6:
	/* 0xcc6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_ccb:
	/* 0xccb: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd0:
	/* 0xcd0: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_cd3:
	/* 0xcd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd5:
	/* 0xcd5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cd7:
	/* 0xcd7: jns    ce0 <event_execve+0xce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_ce0;
	}
x86_l_cd9:
	/* 0xcd9: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ce0:
	/* 0xce0: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ce5:
	/* 0xce5: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_ce8:
	/* 0xce8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_cea:
	/* 0xcea: js     2838 <event_execve+0x2838> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10296ULL;
	}
x86_l_cf0:
	/* 0xcf0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_cf3:
	/* 0xcf3: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cf6:
	/* 0xcf6: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_cf9:
	/* 0xcf9: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_cfc:
	/* 0xcfc: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d01:
	/* 0xd01: sub    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d04:
	/* 0xd04: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4413ULL;
	}
x86_l_d0a:
	/* 0xd0a: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4273ULL;
	}
x86_l_d10:
	/* 0xd10: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d18:
	/* 0xd18: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d1d:
	/* 0xd1d: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d20:
	/* 0xd20: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_d27:
	/* 0xd27: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_d2c:
	/* 0xd2c: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_d30:
	/* 0xd30: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_d36:
	/* 0xd36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d3b:
	/* 0xd3b: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d43:
	/* 0xd43: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_d45:
	/* 0xd45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d47:
	/* 0xd47: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d49:
	/* 0xd49: js     d72 <event_execve+0xd72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3442ULL;
	}
x86_l_d4b:
	/* 0xd4b: lea    r8d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d4f:
	/* 0xd4f: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d53:
	/* 0xd53: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_d58:
	/* 0xd58: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
	return 3423ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3436ULL: goto x86_l_d6c;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3447ULL: goto x86_l_d77;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3479ULL: goto x86_l_d97;
	case 3487ULL: goto x86_l_d9f;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3507ULL: goto x86_l_db3;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3533ULL: goto x86_l_dcd;
	case 3535ULL: goto x86_l_dcf;
	case 3537ULL: goto x86_l_dd1;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3577ULL: goto x86_l_df9;
	case 3579ULL: goto x86_l_dfb;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3593ULL: goto x86_l_e09;
	case 3599ULL: goto x86_l_e0f;
	case 3604ULL: goto x86_l_e14;
	case 3607ULL: goto x86_l_e17;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3621ULL: goto x86_l_e25;
	case 3627ULL: goto x86_l_e2b;
	case 3633ULL: goto x86_l_e31;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3649ULL: goto x86_l_e41;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3665ULL: goto x86_l_e51;
	case 3671ULL: goto x86_l_e57;
	case 3676ULL: goto x86_l_e5c;
	case 3684ULL: goto x86_l_e64;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3692ULL: goto x86_l_e6c;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3762ULL: goto x86_l_eb2;
	case 3768ULL: goto x86_l_eb8;
	case 3776ULL: goto x86_l_ec0;
	case 3780ULL: goto x86_l_ec4;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3807ULL: goto x86_l_edf;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3822ULL: goto x86_l_eee;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3835ULL: goto x86_l_efb;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3866ULL: goto x86_l_f1a;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3888ULL: goto x86_l_f30;
	case 3893ULL: goto x86_l_f35;
	case 3896ULL: goto x86_l_f38;
	case 3899ULL: goto x86_l_f3b;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3910ULL: goto x86_l_f46;
	case 3916ULL: goto x86_l_f4c;
	case 3922ULL: goto x86_l_f52;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3954ULL: goto x86_l_f72;
	case 3960ULL: goto x86_l_f78;
	case 3965ULL: goto x86_l_f7d;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3981ULL: goto x86_l_f8d;
	case 3985ULL: goto x86_l_f91;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4016ULL: goto x86_l_fb0;
	case 4018ULL: goto x86_l_fb2;
	case 4020ULL: goto x86_l_fb4;
	case 4023ULL: goto x86_l_fb7;
	case 4025ULL: goto x86_l_fb9;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4051ULL: goto x86_l_fd3;
	case 4057ULL: goto x86_l_fd9;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4084ULL: goto x86_l_ff4;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4110ULL: goto x86_l_100e;
	case 4112ULL: goto x86_l_1010;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4132ULL: goto x86_l_1024;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4149ULL: goto x86_l_1035;
	case 4152ULL: goto x86_l_1038;
	case 4154ULL: goto x86_l_103a;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4188ULL: goto x86_l_105c;
	case 4193ULL: goto x86_l_1061;
	case 4202ULL: goto x86_l_106a;
	case 4204ULL: goto x86_l_106c;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4240ULL: goto x86_l_1090;
	case 4242ULL: goto x86_l_1092;
	case 4244ULL: goto x86_l_1094;
	case 4246ULL: goto x86_l_1096;
	case 4252ULL: goto x86_l_109c;
	case 4260ULL: goto x86_l_10a4;
	case 4263ULL: goto x86_l_10a7;
	case 4268ULL: goto x86_l_10ac;
	case 4273ULL: goto x86_l_10b1;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4310ULL: goto x86_l_10d6;
	case 4314ULL: goto x86_l_10da;
	case 4316ULL: goto x86_l_10dc;
	case 4320ULL: goto x86_l_10e0;
	case 4322ULL: goto x86_l_10e2;
	case 4326ULL: goto x86_l_10e6;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4334ULL: goto x86_l_10ee;
	case 4340ULL: goto x86_l_10f4;
	case 4342ULL: goto x86_l_10f6;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4352ULL: goto x86_l_1100;
	case 4354ULL: goto x86_l_1102;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4366ULL: goto x86_l_110e;
	case 4368ULL: goto x86_l_1110;
	case 4374ULL: goto x86_l_1116;
	case 4376ULL: goto x86_l_1118;
	case 4382ULL: goto x86_l_111e;
	case 4384ULL: goto x86_l_1120;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4398ULL: goto x86_l_112e;
	case 4400ULL: goto x86_l_1130;
	case 4406ULL: goto x86_l_1136;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4416ULL: goto x86_l_1140;
	case 4418ULL: goto x86_l_1142;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4440ULL: goto x86_l_1158;
	case 4443ULL: goto x86_l_115b;
	case 4450ULL: goto x86_l_1162;
	case 4461ULL: goto x86_l_116d;
	case 4468ULL: goto x86_l_1174;
	case 4475ULL: goto x86_l_117b;
	case 4483ULL: goto x86_l_1183;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4507ULL: goto x86_l_119b;
	case 4514ULL: goto x86_l_11a2;
	case 4521ULL: goto x86_l_11a9;
	case 4529ULL: goto x86_l_11b1;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4547ULL: goto x86_l_11c3;
	case 4552ULL: goto x86_l_11c8;
	case 4554ULL: goto x86_l_11ca;
	case 4562ULL: goto x86_l_11d2;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4603ULL: goto x86_l_11fb;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4648ULL: goto x86_l_1228;
	case 4654ULL: goto x86_l_122e;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4678ULL: goto x86_l_1246;
	case 4682ULL: goto x86_l_124a;
	case 4688ULL: goto x86_l_1250;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4729ULL: goto x86_l_1279;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4751ULL: goto x86_l_128f;
	case 4753ULL: goto x86_l_1291;
	case 4757ULL: goto x86_l_1295;
	case 4763ULL: goto x86_l_129b;
	case 4770ULL: goto x86_l_12a2;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4804ULL: goto x86_l_12c4;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4828ULL: goto x86_l_12dc;
	case 4832ULL: goto x86_l_12e0;
	case 4838ULL: goto x86_l_12e6;
	case 4845ULL: goto x86_l_12ed;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4860ULL: goto x86_l_12fc;
	case 4863ULL: goto x86_l_12ff;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4879ULL: goto x86_l_130f;
	case 4886ULL: goto x86_l_1316;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4903ULL: goto x86_l_1327;
	case 4907ULL: goto x86_l_132b;
	case 4913ULL: goto x86_l_1331;
	case 4920ULL: goto x86_l_1338;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4935ULL: goto x86_l_1347;
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4948ULL: goto x86_l_1354;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4982ULL: goto x86_l_1376;
	case 4988ULL: goto x86_l_137c;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5023ULL: goto x86_l_139f;
	case 5029ULL: goto x86_l_13a5;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5057ULL: goto x86_l_13c1;
	case 5063ULL: goto x86_l_13c7;
	case 5070ULL: goto x86_l_13ce;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5104ULL: goto x86_l_13f0;
	case 5111ULL: goto x86_l_13f7;
	case 5116ULL: goto x86_l_13fc;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5132ULL: goto x86_l_140c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d5f:
	/* 0xd5f: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_d64:
	/* 0xd64: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d69:
	/* 0xd69: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_d6c:
	/* 0xd6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6e:
	/* 0xd6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d70:
	/* 0xd70: jns    d75 <event_execve+0xd75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_d75;
	}
x86_l_d72:
	/* 0xd72: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_d75:
	/* 0xd75: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_d77:
	/* 0xd77: js     10ac <event_execve+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10ac;
	}
x86_l_d7d:
	/* 0xd7d: add    rbx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_d82:
	/* 0xd82: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_d85:
	/* 0xd85: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d8b:
	/* 0xd8b: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_d91:
	/* 0xd91: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_d97:
	/* 0xd97: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d9f:
	/* 0xd9f: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_da3:
	/* 0xda3: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_daa:
	/* 0xdaa: mov    esi,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32736ULL);
x86_l_daf:
	/* 0xdaf: cmovb  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_db3:
	/* 0xdb3: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_db9:
	/* 0xdb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dbe:
	/* 0xdbe: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_dc6:
	/* 0xdc6: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_dcb:
	/* 0xdcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dcd:
	/* 0xdcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dcf:
	/* 0xdcf: js     dfd <event_execve+0xdfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_dfd;
	}
x86_l_dd1:
	/* 0xdd1: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_dd6:
	/* 0xdd6: lea    r8d,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dda:
	/* 0xdda: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dde:
	/* 0xdde: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_de3:
	/* 0xde3: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_dea:
	/* 0xdea: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_def:
	/* 0xdef: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_df4:
	/* 0xdf4: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df9:
	/* 0xdf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dfb:
	/* 0xdfb: jns    e04 <event_execve+0xe04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e04;
	}
x86_l_dfd:
	/* 0xdfd: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_dff:
	/* 0xdff: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e04:
	/* 0xe04: cmp    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_e09:
	/* 0xe09: js     2cda <event_execve+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11482ULL;
	}
x86_l_e0f:
	/* 0xe0f: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e14:
	/* 0xe14: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e17:
	/* 0xe17: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_e1a:
	/* 0xe1a: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_e1d:
	/* 0xe1d: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e22:
	/* 0xe22: sub    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_e25:
	/* 0xe25: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_e2b:
	/* 0xe2b: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_e31:
	/* 0xe31: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e39:
	/* 0xe39: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e3e:
	/* 0xe3e: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e41:
	/* 0xe41: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_e48:
	/* 0xe48: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_e4d:
	/* 0xe4d: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_e51:
	/* 0xe51: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_e57:
	/* 0xe57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e5c:
	/* 0xe5c: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e64:
	/* 0xe64: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_e66:
	/* 0xe66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e68:
	/* 0xe68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e6a:
	/* 0xe6a: js     e93 <event_execve+0xe93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_e93;
	}
x86_l_e6c:
	/* 0xe6c: lea    r8d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e70:
	/* 0xe70: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e74:
	/* 0xe74: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e79:
	/* 0xe79: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_e80:
	/* 0xe80: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_e85:
	/* 0xe85: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e8a:
	/* 0xe8a: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_e8d:
	/* 0xe8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8f:
	/* 0xe8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e91:
	/* 0xe91: jns    e96 <event_execve+0xe96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_e96;
	}
x86_l_e93:
	/* 0xe93: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_e96:
	/* 0xe96: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_e98:
	/* 0xe98: js     10ac <event_execve+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10ac;
	}
x86_l_e9e:
	/* 0xe9e: add    rbx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_ea3:
	/* 0xea3: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_ea6:
	/* 0xea6: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_ea9:
	/* 0xea9: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_eac:
	/* 0xeac: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_eb2:
	/* 0xeb2: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_eb8:
	/* 0xeb8: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ec0:
	/* 0xec0: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ec4:
	/* 0xec4: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_ecb:
	/* 0xecb: mov    esi,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32736ULL);
x86_l_ed0:
	/* 0xed0: cmovb  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_ed4:
	/* 0xed4: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_eda:
	/* 0xeda: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_edf:
	/* 0xedf: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ee7:
	/* 0xee7: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_eec:
	/* 0xeec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eee:
	/* 0xeee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef0:
	/* 0xef0: js     f1e <event_execve+0xf1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f1e;
	}
x86_l_ef2:
	/* 0xef2: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ef7:
	/* 0xef7: lea    r8d,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_efb:
	/* 0xefb: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eff:
	/* 0xeff: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f04:
	/* 0xf04: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_f0b:
	/* 0xf0b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_f10:
	/* 0xf10: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f15:
	/* 0xf15: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_f18:
	/* 0xf18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1a:
	/* 0xf1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f1c:
	/* 0xf1c: jns    f25 <event_execve+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_f25;
	}
x86_l_f1e:
	/* 0xf1e: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_f20:
	/* 0xf20: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f25:
	/* 0xf25: cmp    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_f2a:
	/* 0xf2a: js     2cda <event_execve+0x2cda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11482ULL;
	}
x86_l_f30:
	/* 0xf30: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f35:
	/* 0xf35: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f38:
	/* 0xf38: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_f3b:
	/* 0xf3b: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f43:
	/* 0xf43: sub    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_f46:
	/* 0xf46: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_f4c:
	/* 0xf4c: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_f52:
	/* 0xf52: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f5a:
	/* 0xf5a: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f5f:
	/* 0xf5f: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f62:
	/* 0xf62: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_f69:
	/* 0xf69: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_f6e:
	/* 0xf6e: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_f72:
	/* 0xf72: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_f78:
	/* 0xf78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f85:
	/* 0xf85: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_f87:
	/* 0xf87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f89:
	/* 0xf89: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f8b:
	/* 0xf8b: js     fb4 <event_execve+0xfb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fb4;
	}
x86_l_f8d:
	/* 0xf8d: lea    r8d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f91:
	/* 0xf91: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f95:
	/* 0xf95: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f9a:
	/* 0xf9a: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_fa1:
	/* 0xfa1: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_fa6:
	/* 0xfa6: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fab:
	/* 0xfab: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb0:
	/* 0xfb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fb2:
	/* 0xfb2: jns    fb7 <event_execve+0xfb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_fb7;
	}
x86_l_fb4:
	/* 0xfb4: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_fb7:
	/* 0xfb7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_fb9:
	/* 0xfb9: js     10ac <event_execve+0x10ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10ac;
	}
x86_l_fbf:
	/* 0xfbf: add    rbx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_fc4:
	/* 0xfc4: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_fc7:
	/* 0xfc7: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_fca:
	/* 0xfca: sub    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_fcd:
	/* 0xfcd: je     113d <event_execve+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_fd3:
	/* 0xfd3: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_fd9:
	/* 0xfd9: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fe1:
	/* 0xfe1: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_fe4:
	/* 0xfe4: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_feb:
	/* 0xfeb: mov    esi,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32736ULL);
x86_l_ff0:
	/* 0xff0: cmovb  rsi,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_ff4:
	/* 0xff4: and    esi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_ffa:
	/* 0xffa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fff:
	/* 0xfff: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1007:
	/* 0x1007: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_100c:
	/* 0x100c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_100e:
	/* 0x100e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1010:
	/* 0x1010: js     103e <event_execve+0x103e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_103e;
	}
x86_l_1012:
	/* 0x1012: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1017:
	/* 0x1017: lea    r8d,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101b:
	/* 0x101b: mov    DWORD PTR [r13+0x4],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_101f:
	/* 0x101f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1024:
	/* 0x1024: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_102b:
	/* 0x102b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1030:
	/* 0x1030: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1035:
	/* 0x1035: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1038:
	/* 0x1038: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103a:
	/* 0x103a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_103c:
	/* 0x103c: jns    1045 <event_execve+0x1045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1045;
	}
x86_l_103e:
	/* 0x103e: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1040:
	/* 0x1040: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1045:
	/* 0x1045: cmp    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_104a:
	/* 0x104a: js     10b1 <event_execve+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10b1;
	}
x86_l_104c:
	/* 0x104c: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1051:
	/* 0x1051: add    rax,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1054:
	/* 0x1054: jmp    113d <event_execve+0x113d> */
	goto x86_l_113d;
x86_l_1059:
	/* 0x1059: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_105c:
	/* 0x105c: jmp    1189 <event_execve+0x1189> */
	goto x86_l_1189;
x86_l_1061:
	/* 0x1061: mov    QWORD PTR [rsp+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_106a:
	/* 0x106a: jmp    10b1 <event_execve+0x10b1> */
	goto x86_l_10b1;
x86_l_106c:
	/* 0x106c: mov    DWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_1077:
	/* 0x1077: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_107c:
	/* 0x107c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1083:
	/* 0x1083: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1088:
	/* 0x1088: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1090:
	/* 0x1090: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1092:
	/* 0x1092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1094:
	/* 0x1094: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1096:
	/* 0x1096: jns    1193 <event_execve+0x1193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1193;
	}
x86_l_109c:
	/* 0x109c: or     BYTE PTR [r14+0x15d],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1498943586306ULL);
x86_l_10a4:
	/* 0x10a4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a7:
	/* 0x10a7: jmp    1193 <event_execve+0x1193> */
	goto x86_l_1193;
x86_l_10ac:
	/* 0x10ac: mov    QWORD PTR [rsp+0x28],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10b1:
	/* 0x10b1: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_10b9:
	/* 0x10b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10be:
	/* 0x10be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_10c5:
	/* 0x10c5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ca:
	/* 0x10ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cc:
	/* 0x10cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10cf:
	/* 0x10cf: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10d4:
	/* 0x10d4: je     113a <event_execve+0x113a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113a;
	}
x86_l_10d6:
	/* 0x10d6: cmp    rcx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_10da:
	/* 0x10da: jg     10f6 <event_execve+0x10f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_10f6;
	}
x86_l_10dc:
	/* 0x10dc: cmp    rcx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_10e0:
	/* 0x10e0: je     1110 <event_execve+0x1110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1110;
	}
x86_l_10e2:
	/* 0x10e2: cmp    rcx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_10e6:
	/* 0x10e6: je     1128 <event_execve+0x1128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1128;
	}
x86_l_10e8:
	/* 0x10e8: cmp    rcx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_10ec:
	/* 0x10ec: jne    1120 <event_execve+0x1120> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1120;
	}
x86_l_10ee:
	/* 0x10ee: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_10f4:
	/* 0x10f4: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_10f6:
	/* 0x10f6: cmp    rcx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_10fa:
	/* 0x10fa: je     1118 <event_execve+0x1118> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1118;
	}
x86_l_10fc:
	/* 0x10fc: cmp    rcx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_1100:
	/* 0x1100: je     1130 <event_execve+0x1130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1130;
	}
x86_l_1102:
	/* 0x1102: cmp    rcx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1106:
	/* 0x1106: jne    1120 <event_execve+0x1120> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1120;
	}
x86_l_1108:
	/* 0x1108: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_110e:
	/* 0x110e: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_1110:
	/* 0x1110: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_1116:
	/* 0x1116: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_1118:
	/* 0x1118: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_111e:
	/* 0x111e: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_1120:
	/* 0x1120: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_1126:
	/* 0x1126: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_1128:
	/* 0x1128: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_112e:
	/* 0x112e: jmp    1136 <event_execve+0x1136> */
	goto x86_l_1136;
x86_l_1130:
	/* 0x1130: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_1136:
	/* 0x1136: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_113a:
	/* 0x113a: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1140:
	/* 0x1140: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1142:
	/* 0x1142: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1144:
	/* 0x1144: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1148:
	/* 0x1148: cmove  ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_E);
x86_l_114b:
	/* 0x114b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_114d:
	/* 0x114d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_1152:
	/* 0x1152: cmovs  esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_1155:
	/* 0x1155: cmovs  ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_S);
x86_l_1158:
	/* 0x1158: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_115b:
	/* 0x115b: mov    DWORD PTR [r15+0x140],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1162:
	/* 0x1162: mov    DWORD PTR [r15+0x144],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_116d:
	/* 0x116d: mov    DWORD PTR [r15+0x148],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_1174:
	/* 0x1174: mov    DWORD PTR [r15+0x14c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_117b:
	/* 0x117b: or     BYTE PTR [r14+0x15f],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1507533520897ULL);
x86_l_1183:
	/* 0x1183: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1189:
	/* 0x1189: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118e:
	/* 0x118e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1193:
	/* 0x1193: mov    WORD PTR [r14+0x17a],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 378ULL);
x86_l_119b:
	/* 0x119b: add    r13d,DWORD PTR [r14+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 320ULL);
x86_l_11a2:
	/* 0x11a2: mov    DWORD PTR [r14+0x140],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_11a9:
	/* 0x11a9: test   BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1498943586336ULL);
x86_l_11b1:
	/* 0x11b1: jne    1d41 <event_execve+0x1d41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7489ULL;
	}
x86_l_11b7:
	/* 0x11b7: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11bc:
	/* 0x11bc: mov    ebx,DWORD PTR [r14+0x144] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_11c3:
	/* 0x11c3: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_11c8:
	/* 0x11c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ca:
	/* 0x11ca: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11d2:
	/* 0x11d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d5:
	/* 0x11d5: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11da:
	/* 0x11da: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_11e0:
	/* 0x11e0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_11e3:
	/* 0x11e3: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_11ea:
	/* 0x11ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ef:
	/* 0x11ef: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f4:
	/* 0x11f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11f9:
	/* 0x11f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fb:
	/* 0x11fb: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ff:
	/* 0x11ff: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_1205:
	/* 0x1205: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_120c:
	/* 0x120c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1211:
	/* 0x1211: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1216:
	/* 0x1216: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_121b:
	/* 0x121b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1225:
	/* 0x1225: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1228:
	/* 0x1228: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_122e:
	/* 0x122e: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1235:
	/* 0x1235: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_123a:
	/* 0x123a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_123f:
	/* 0x123f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1244:
	/* 0x1244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1246:
	/* 0x1246: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_124a:
	/* 0x124a: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_1250:
	/* 0x1250: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1257:
	/* 0x1257: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_125c:
	/* 0x125c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1261:
	/* 0x1261: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1266:
	/* 0x1266: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1269:
	/* 0x1269: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126b:
	/* 0x126b: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1270:
	/* 0x1270: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1273:
	/* 0x1273: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_1279:
	/* 0x1279: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1280:
	/* 0x1280: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1285:
	/* 0x1285: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_128a:
	/* 0x128a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_128f:
	/* 0x128f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1291:
	/* 0x1291: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1295:
	/* 0x1295: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_129b:
	/* 0x129b: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_12a2:
	/* 0x12a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12a7:
	/* 0x12a7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ac:
	/* 0x12ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12b1:
	/* 0x12b1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12b4:
	/* 0x12b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b6:
	/* 0x12b6: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12bb:
	/* 0x12bb: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_12be:
	/* 0x12be: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_12c4:
	/* 0x12c4: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_12cb:
	/* 0x12cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12d0:
	/* 0x12d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d5:
	/* 0x12d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12da:
	/* 0x12da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12dc:
	/* 0x12dc: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e0:
	/* 0x12e0: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_12e6:
	/* 0x12e6: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_12ed:
	/* 0x12ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12f2:
	/* 0x12f2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12f7:
	/* 0x12f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12fc:
	/* 0x12fc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12ff:
	/* 0x12ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1301:
	/* 0x1301: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1306:
	/* 0x1306: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1309:
	/* 0x1309: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_130f:
	/* 0x130f: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1316:
	/* 0x1316: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_131b:
	/* 0x131b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1320:
	/* 0x1320: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1325:
	/* 0x1325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1327:
	/* 0x1327: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132b:
	/* 0x132b: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_1331:
	/* 0x1331: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1338:
	/* 0x1338: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_133d:
	/* 0x133d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1342:
	/* 0x1342: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1347:
	/* 0x1347: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_134a:
	/* 0x134a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134c:
	/* 0x134c: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1351:
	/* 0x1351: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1354:
	/* 0x1354: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_135a:
	/* 0x135a: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1361:
	/* 0x1361: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1366:
	/* 0x1366: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136b:
	/* 0x136b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1370:
	/* 0x1370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1372:
	/* 0x1372: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1376:
	/* 0x1376: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_137c:
	/* 0x137c: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1383:
	/* 0x1383: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1388:
	/* 0x1388: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_138d:
	/* 0x138d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1392:
	/* 0x1392: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1395:
	/* 0x1395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1397:
	/* 0x1397: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_139c:
	/* 0x139c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_139f:
	/* 0x139f: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_13a5:
	/* 0x13a5: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_13ac:
	/* 0x13ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13b1:
	/* 0x13b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b6:
	/* 0x13b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13bb:
	/* 0x13bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bd:
	/* 0x13bd: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c1:
	/* 0x13c1: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
x86_l_13c7:
	/* 0x13c7: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_13ce:
	/* 0x13ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13d3:
	/* 0x13d3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d8:
	/* 0x13d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13dd:
	/* 0x13dd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_13e0:
	/* 0x13e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e2:
	/* 0x13e2: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13e7:
	/* 0x13e7: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6060ULL;
	}
x86_l_13f0:
	/* 0x13f0: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_13f7:
	/* 0x13f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13fc:
	/* 0x13fc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1401:
	/* 0x1401: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1406:
	/* 0x1406: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1408:
	/* 0x1408: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_140c:
	/* 0x140c: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6063ULL;
	}
	return 5138ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5138ULL: goto x86_l_1412;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5163ULL: goto x86_l_142b;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5173ULL: goto x86_l_1435;
	case 5179ULL: goto x86_l_143b;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5213ULL: goto x86_l_145d;
	case 5220ULL: goto x86_l_1464;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5248ULL: goto x86_l_1480;
	case 5254ULL: goto x86_l_1486;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5282ULL: goto x86_l_14a2;
	case 5288ULL: goto x86_l_14a8;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5313ULL: goto x86_l_14c1;
	case 5315ULL: goto x86_l_14c3;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5329ULL: goto x86_l_14d1;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5370ULL: goto x86_l_14fa;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5398ULL: goto x86_l_1516;
	case 5404ULL: goto x86_l_151c;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5421ULL: goto x86_l_152d;
	case 5426ULL: goto x86_l_1532;
	case 5428ULL: goto x86_l_1534;
	case 5432ULL: goto x86_l_1538;
	case 5438ULL: goto x86_l_153e;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5473ULL: goto x86_l_1561;
	case 5479ULL: goto x86_l_1567;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5503ULL: goto x86_l_157f;
	case 5507ULL: goto x86_l_1583;
	case 5513ULL: goto x86_l_1589;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5538ULL: goto x86_l_15a2;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5548ULL: goto x86_l_15ac;
	case 5554ULL: goto x86_l_15b2;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5582ULL: goto x86_l_15ce;
	case 5588ULL: goto x86_l_15d4;
	case 5595ULL: goto x86_l_15db;
	case 5600ULL: goto x86_l_15e0;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5636ULL: goto x86_l_1604;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5651ULL: goto x86_l_1613;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5688ULL: goto x86_l_1638;
	case 5690ULL: goto x86_l_163a;
	case 5695ULL: goto x86_l_163f;
	case 5698ULL: goto x86_l_1642;
	case 5704ULL: goto x86_l_1648;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5732ULL: goto x86_l_1664;
	case 5738ULL: goto x86_l_166a;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5763ULL: goto x86_l_1683;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5773ULL: goto x86_l_168d;
	case 5779ULL: goto x86_l_1693;
	case 5786ULL: goto x86_l_169a;
	case 5791ULL: goto x86_l_169f;
	case 5796ULL: goto x86_l_16a4;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5807ULL: goto x86_l_16af;
	case 5813ULL: goto x86_l_16b5;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5854ULL: goto x86_l_16de;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5878ULL: goto x86_l_16f6;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5905ULL: goto x86_l_1711;
	case 5910ULL: goto x86_l_1716;
	case 5913ULL: goto x86_l_1719;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5923ULL: goto x86_l_1723;
	case 5929ULL: goto x86_l_1729;
	case 5936ULL: goto x86_l_1730;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5957ULL: goto x86_l_1745;
	case 5959ULL: goto x86_l_1747;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5994ULL: goto x86_l_176a;
	case 5996ULL: goto x86_l_176c;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6020ULL: goto x86_l_1784;
	case 6024ULL: goto x86_l_1788;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6063ULL: goto x86_l_17af;
	case 6065ULL: goto x86_l_17b1;
	case 6069ULL: goto x86_l_17b5;
	case 6073ULL: goto x86_l_17b9;
	case 6080ULL: goto x86_l_17c0;
	case 6085ULL: goto x86_l_17c5;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6120ULL: goto x86_l_17e8;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6143ULL: goto x86_l_17ff;
	case 6151ULL: goto x86_l_1807;
	case 6153ULL: goto x86_l_1809;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6174ULL: goto x86_l_181e;
	case 6182ULL: goto x86_l_1826;
	case 6189ULL: goto x86_l_182d;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6204ULL: goto x86_l_183c;
	case 6211ULL: goto x86_l_1843;
	case 6216ULL: goto x86_l_1848;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6231ULL: goto x86_l_1857;
	case 6239ULL: goto x86_l_185f;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6265ULL: goto x86_l_1879;
	case 6270ULL: goto x86_l_187e;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6305ULL: goto x86_l_18a1;
	case 6311ULL: goto x86_l_18a7;
	case 6317ULL: goto x86_l_18ad;
	case 6319ULL: goto x86_l_18af;
	case 6327ULL: goto x86_l_18b7;
	case 6329ULL: goto x86_l_18b9;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6347ULL: goto x86_l_18cb;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6364ULL: goto x86_l_18dc;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6394ULL: goto x86_l_18fa;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6406ULL: goto x86_l_1906;
	case 6416ULL: goto x86_l_1910;
	case 6423ULL: goto x86_l_1917;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6448ULL: goto x86_l_1930;
	case 6457ULL: goto x86_l_1939;
	case 6462ULL: goto x86_l_193e;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6481ULL: goto x86_l_1951;
	case 6490ULL: goto x86_l_195a;
	case 6499ULL: goto x86_l_1963;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6531ULL: goto x86_l_1983;
	case 6536ULL: goto x86_l_1988;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6549ULL: goto x86_l_1995;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6594ULL: goto x86_l_19c2;
	case 6597ULL: goto x86_l_19c5;
	case 6602ULL: goto x86_l_19ca;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6681ULL: goto x86_l_1a19;
	case 6687ULL: goto x86_l_1a1f;
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6708ULL: goto x86_l_1a34;
	case 6710ULL: goto x86_l_1a36;
	case 6713ULL: goto x86_l_1a39;
	case 6716ULL: goto x86_l_1a3c;
	case 6722ULL: goto x86_l_1a42;
	case 6724ULL: goto x86_l_1a44;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6747ULL: goto x86_l_1a5b;
	case 6752ULL: goto x86_l_1a60;
	case 6755ULL: goto x86_l_1a63;
	case 6757ULL: goto x86_l_1a65;
	case 6765ULL: goto x86_l_1a6d;
	case 6771ULL: goto x86_l_1a73;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6827ULL: goto x86_l_1aab;
	case 6829ULL: goto x86_l_1aad;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6874ULL: goto x86_l_1ada;
	case 6876ULL: goto x86_l_1adc;
	case 6878ULL: goto x86_l_1ade;
	case 6880ULL: goto x86_l_1ae0;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6919ULL: goto x86_l_1b07;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1412:
	/* 0x1412: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1419:
	/* 0x1419: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_141e:
	/* 0x141e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1423:
	/* 0x1423: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1428:
	/* 0x1428: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_142b:
	/* 0x142b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142d:
	/* 0x142d: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1432:
	/* 0x1432: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1435:
	/* 0x1435: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_143b:
	/* 0x143b: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1442:
	/* 0x1442: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1447:
	/* 0x1447: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_144c:
	/* 0x144c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1451:
	/* 0x1451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1453:
	/* 0x1453: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1457:
	/* 0x1457: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_145d:
	/* 0x145d: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1464:
	/* 0x1464: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1469:
	/* 0x1469: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146e:
	/* 0x146e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1473:
	/* 0x1473: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1478:
	/* 0x1478: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147d:
	/* 0x147d: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1480:
	/* 0x1480: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_1486:
	/* 0x1486: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_148d:
	/* 0x148d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1492:
	/* 0x1492: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1497:
	/* 0x1497: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_149c:
	/* 0x149c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149e:
	/* 0x149e: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14a2:
	/* 0x14a2: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_14a8:
	/* 0x14a8: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_14af:
	/* 0x14af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14b4:
	/* 0x14b4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14b9:
	/* 0x14b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14be:
	/* 0x14be: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14c1:
	/* 0x14c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c3:
	/* 0x14c3: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14c8:
	/* 0x14c8: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_14d1:
	/* 0x14d1: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_14d8:
	/* 0x14d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14dd:
	/* 0x14dd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e2:
	/* 0x14e2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14e7:
	/* 0x14e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e9:
	/* 0x14e9: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ed:
	/* 0x14ed: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_14f3:
	/* 0x14f3: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_14fa:
	/* 0x14fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14ff:
	/* 0x14ff: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1504:
	/* 0x1504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1509:
	/* 0x1509: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150e:
	/* 0x150e: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1513:
	/* 0x1513: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1516:
	/* 0x1516: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_151c:
	/* 0x151c: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1523:
	/* 0x1523: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1528:
	/* 0x1528: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152d:
	/* 0x152d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1532:
	/* 0x1532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1534:
	/* 0x1534: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1538:
	/* 0x1538: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_153e:
	/* 0x153e: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1545:
	/* 0x1545: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_154a:
	/* 0x154a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_154f:
	/* 0x154f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1554:
	/* 0x1554: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1557:
	/* 0x1557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1559:
	/* 0x1559: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_155e:
	/* 0x155e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1561:
	/* 0x1561: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_1567:
	/* 0x1567: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_156e:
	/* 0x156e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1573:
	/* 0x1573: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1578:
	/* 0x1578: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_157d:
	/* 0x157d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157f:
	/* 0x157f: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1583:
	/* 0x1583: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_1589:
	/* 0x1589: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1590:
	/* 0x1590: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1595:
	/* 0x1595: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_159a:
	/* 0x159a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_159f:
	/* 0x159f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15a2:
	/* 0x15a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a4:
	/* 0x15a4: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15a9:
	/* 0x15a9: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_15ac:
	/* 0x15ac: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_15b2:
	/* 0x15b2: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_15b9:
	/* 0x15b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15be:
	/* 0x15be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15c3:
	/* 0x15c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15c8:
	/* 0x15c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ca:
	/* 0x15ca: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ce:
	/* 0x15ce: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_15d4:
	/* 0x15d4: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_15db:
	/* 0x15db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15e0:
	/* 0x15e0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15e5:
	/* 0x15e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ea:
	/* 0x15ea: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15ed:
	/* 0x15ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ef:
	/* 0x15ef: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15f4:
	/* 0x15f4: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_15f7:
	/* 0x15f7: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_15fd:
	/* 0x15fd: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1604:
	/* 0x1604: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1609:
	/* 0x1609: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160e:
	/* 0x160e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1613:
	/* 0x1613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1615:
	/* 0x1615: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1619:
	/* 0x1619: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_161f:
	/* 0x161f: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1626:
	/* 0x1626: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_162b:
	/* 0x162b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1630:
	/* 0x1630: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1635:
	/* 0x1635: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1638:
	/* 0x1638: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163a:
	/* 0x163a: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_163f:
	/* 0x163f: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1642:
	/* 0x1642: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_1648:
	/* 0x1648: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_164f:
	/* 0x164f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1654:
	/* 0x1654: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1659:
	/* 0x1659: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_165e:
	/* 0x165e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1660:
	/* 0x1660: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1664:
	/* 0x1664: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_166a:
	/* 0x166a: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1671:
	/* 0x1671: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1676:
	/* 0x1676: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167b:
	/* 0x167b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1680:
	/* 0x1680: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1683:
	/* 0x1683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1685:
	/* 0x1685: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_168a:
	/* 0x168a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_168d:
	/* 0x168d: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_1693:
	/* 0x1693: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_169a:
	/* 0x169a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_169f:
	/* 0x169f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16a4:
	/* 0x16a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16a9:
	/* 0x16a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ab:
	/* 0x16ab: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16af:
	/* 0x16af: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_16b5:
	/* 0x16b5: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_16bc:
	/* 0x16bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16c1:
	/* 0x16c1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16c6:
	/* 0x16c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16cb:
	/* 0x16cb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_16ce:
	/* 0x16ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d0:
	/* 0x16d0: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16d5:
	/* 0x16d5: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_16d8:
	/* 0x16d8: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_16de:
	/* 0x16de: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_16e5:
	/* 0x16e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16ea:
	/* 0x16ea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ef:
	/* 0x16ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16f4:
	/* 0x16f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f6:
	/* 0x16f6: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16fa:
	/* 0x16fa: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_1700:
	/* 0x1700: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1707:
	/* 0x1707: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_170c:
	/* 0x170c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1711:
	/* 0x1711: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1716:
	/* 0x1716: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1719:
	/* 0x1719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171b:
	/* 0x171b: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1720:
	/* 0x1720: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_1729:
	/* 0x1729: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1730:
	/* 0x1730: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1735:
	/* 0x1735: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_173a:
	/* 0x173a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_173f:
	/* 0x173f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1741:
	/* 0x1741: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1745:
	/* 0x1745: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_1747:
	/* 0x1747: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_174e:
	/* 0x174e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1753:
	/* 0x1753: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1758:
	/* 0x1758: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175d:
	/* 0x175d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1760:
	/* 0x1760: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1762:
	/* 0x1762: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1767:
	/* 0x1767: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_176a:
	/* 0x176a: je     17ac <event_execve+0x17ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17ac;
	}
x86_l_176c:
	/* 0x176c: lea    rdx,[r13+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_1773:
	/* 0x1773: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1778:
	/* 0x1778: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_177d:
	/* 0x177d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1782:
	/* 0x1782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1784:
	/* 0x1784: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1788:
	/* 0x1788: je     17af <event_execve+0x17af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17af;
	}
x86_l_178a:
	/* 0x178a: add    r13,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_1791:
	/* 0x1791: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1796:
	/* 0x1796: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_179b:
	/* 0x179b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17a0:
	/* 0x17a0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_17a3:
	/* 0x17a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a5:
	/* 0x17a5: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17aa:
	/* 0x17aa: jmp    17af <event_execve+0x17af> */
	goto x86_l_17af;
x86_l_17ac:
	/* 0x17ac: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17af:
	/* 0x17af: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b1:
	/* 0x17b1: cmp    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17b5:
	/* 0x17b5: cmovne r13,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_64, X86_CC_NE);
x86_l_17b9:
	/* 0x17b9: add    r13,0xd30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3376ULL);
x86_l_17c0:
	/* 0x17c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c5:
	/* 0x17c5: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17cd:
	/* 0x17cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17d2:
	/* 0x17d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_17d5:
	/* 0x17d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d7:
	/* 0x17d7: mov    rbx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17df:
	/* 0x17df: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_17e2:
	/* 0x17e2: je     18b9 <event_execve+0x18b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b9;
	}
x86_l_17e8:
	/* 0x17e8: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_17f3:
	/* 0x17f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17f8:
	/* 0x17f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_17ff:
	/* 0x17ff: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1807:
	/* 0x1807: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1809:
	/* 0x1809: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180c:
	/* 0x180c: je     18cb <event_execve+0x18cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18cb;
	}
x86_l_1812:
	/* 0x1812: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1815:
	/* 0x1815: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_181a:
	/* 0x181a: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_181e:
	/* 0x181e: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1826:
	/* 0x1826: lea    rax,[r15+0x1000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4096ULL);
x86_l_182d:
	/* 0x182d: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1835:
	/* 0x1835: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_183a:
	/* 0x183a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183c:
	/* 0x183c: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_1843:
	/* 0x1843: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1848:
	/* 0x1848: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1850:
	/* 0x1850: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1855:
	/* 0x1855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1857:
	/* 0x1857: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_185f:
	/* 0x185f: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1863:
	/* 0x1863: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1868:
	/* 0x1868: add    rbx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_186c:
	/* 0x186c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1871:
	/* 0x1871: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1879:
	/* 0x1879: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_187e:
	/* 0x187e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1881:
	/* 0x1881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1883:
	/* 0x1883: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_188b:
	/* 0x188b: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1890:
	/* 0x1890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1895:
	/* 0x1895: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_189a:
	/* 0x189a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189f:
	/* 0x189f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a1:
	/* 0x18a1: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_18a7:
	/* 0x18a7: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_18ad:
	/* 0x18ad: je     18d7 <event_execve+0x18d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d7;
	}
x86_l_18af:
	/* 0x18af: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18b7:
	/* 0x18b7: jmp    1927 <event_execve+0x1927> */
	goto x86_l_1927;
x86_l_18b9:
	/* 0x18b9: or     BYTE PTR [r14+0x15d],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 1498943586336ULL);
x86_l_18c1:
	/* 0x18c1: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c6:
	/* 0x18c6: jmp    1d3d <event_execve+0x1d3d> */
	return 7485ULL;
x86_l_18cb:
	/* 0x18cb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18cd:
	/* 0x18cd: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18d2:
	/* 0x18d2: jmp    1d3d <event_execve+0x1d3d> */
	return 7485ULL;
x86_l_18d7:
	/* 0x18d7: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18dc:
	/* 0x18dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e1:
	/* 0x18e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18e6:
	/* 0x18e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18eb:
	/* 0x18eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ed:
	/* 0x18ed: cmp    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18f2:
	/* 0x18f2: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18fa:
	/* 0x18fa: je     1927 <event_execve+0x1927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1927;
	}
x86_l_18fc:
	/* 0x18fc: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_18ff:
	/* 0x18ff: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_1906:
	/* 0x1906: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_1910:
	/* 0x1910: mov    QWORD PTR [r15+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_1917:
	/* 0x1917: mov    WORD PTR [r15+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_1921:
	/* 0x1921: mov    r13d,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4086ULL);
x86_l_1927:
	/* 0x1927: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1930:
	/* 0x1930: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1939:
	/* 0x1939: mov    QWORD PTR [rsp+0x40],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_193e:
	/* 0x193e: lea    r12,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1943:
	/* 0x1943: lea    r15,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1948:
	/* 0x1948: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1951:
	/* 0x1951: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_195a:
	/* 0x195a: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1963:
	/* 0x1963: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_196b:
	/* 0x196b: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1970:
	/* 0x1970: mov    DWORD PTR [rsp+0x68],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1975:
	/* 0x1975: lea    r13,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_197a:
	/* 0x197a: mov    BYTE PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_197f:
	/* 0x197f: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1983:
	/* 0x1983: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1988:
	/* 0x1988: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_198d:
	/* 0x198d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1992:
	/* 0x1992: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1995:
	/* 0x1995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1997:
	/* 0x1997: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_199c:
	/* 0x199c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19a4:
	/* 0x19a4: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19a9:
	/* 0x19a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ab:
	/* 0x19ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b0:
	/* 0x19b0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_19b3:
	/* 0x19b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19b8:
	/* 0x19b8: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_19bb:
	/* 0x19bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bd:
	/* 0x19bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19c2:
	/* 0x19c2: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_19c5:
	/* 0x19c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19d2:
	/* 0x19d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d4:
	/* 0x19d4: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19d9:
	/* 0x19d9: lea    rax,[rbx-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_19dd:
	/* 0x19dd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19e2:
	/* 0x19e2: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19e7:
	/* 0x19e7: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_19ec:
	/* 0x19ec: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19f1:
	/* 0x19f1: jne    1a4e <event_execve+0x1a4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4e;
	}
x86_l_19f3:
	/* 0x19f3: cmp    rbx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_19f8:
	/* 0x19f8: jne    1a4e <event_execve+0x1a4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4e;
	}
x86_l_19fa:
	/* 0x19fa: mov    BYTE PTR [rsp+0x6c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467969ULL);
x86_l_19ff:
	/* 0x19ff: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a04:
	/* 0x1a04: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a09:
	/* 0x1a09: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a11:
	/* 0x1a11: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a16:
	/* 0x1a16: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1a19:
	/* 0x1a19: je     1b66 <event_execve+0x1b66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7014ULL;
	}
x86_l_1a1f:
	/* 0x1a1f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a21:
	/* 0x1a21: cmp    BYTE PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_1a26:
	/* 0x1a26: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1a29:
	/* 0x1a29: mov    edx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_1a32:
	/* 0x1a32: sub    ebp,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1a34:
	/* 0x1a34: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1a36:
	/* 0x1a36: cmovle ebp,edx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_1a39:
	/* 0x1a39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3c:
	/* 0x1a3c: je     1d3b <event_execve+0x1d3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7483ULL;
	}
x86_l_1a42:
	/* 0x1a42: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_1a44:
	/* 0x1a44: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a46:
	/* 0x1a46: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a49:
	/* 0x1a49: jmp    1b6a <event_execve+0x1b6a> */
	return 7018ULL;
x86_l_1a4e:
	/* 0x1a4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a53:
	/* 0x1a53: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a60:
	/* 0x1a60: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a63:
	/* 0x1a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a65:
	/* 0x1a65: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_1a6d:
	/* 0x1a6d: je     1bbf <event_execve+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7103ULL;
	}
x86_l_1a73:
	/* 0x1a73: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a77:
	/* 0x1a77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a7c:
	/* 0x1a7c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a81:
	/* 0x1a81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a86:
	/* 0x1a86: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a90:
	/* 0x1a90: je     1bbf <event_execve+0x1bbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7103ULL;
	}
x86_l_1a96:
	/* 0x1a96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9b:
	/* 0x1a9b: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1aab:
	/* 0x1aab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aad:
	/* 0x1aad: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1ab1:
	/* 0x1ab1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1abb:
	/* 0x1abb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ac3:
	/* 0x1ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac5:
	/* 0x1ac5: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aca:
	/* 0x1aca: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1acf:
	/* 0x1acf: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ad3:
	/* 0x1ad3: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ad6:
	/* 0x1ad6: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ada:
	/* 0x1ada: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1adc:
	/* 0x1adc: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1ade:
	/* 0x1ade: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ae0:
	/* 0x1ae0: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1ae3:
	/* 0x1ae3: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1ae8:
	/* 0x1ae8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aeb:
	/* 0x1aeb: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1aed:
	/* 0x1aed: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1af1:
	/* 0x1af1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1af3:
	/* 0x1af3: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1af6:
	/* 0x1af6: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1af9:
	/* 0x1af9: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1afc:
	/* 0x1afc: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1aff:
	/* 0x1aff: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b04:
	/* 0x1b04: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b07:
	/* 0x1b07: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 6924ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6935ULL: goto x86_l_1b17;
	case 6942ULL: goto x86_l_1b1e;
	case 6948ULL: goto x86_l_1b24;
	case 6950ULL: goto x86_l_1b26;
	case 6956ULL: goto x86_l_1b2c;
	case 6960ULL: goto x86_l_1b30;
	case 6964ULL: goto x86_l_1b34;
	case 6967ULL: goto x86_l_1b37;
	case 6971ULL: goto x86_l_1b3b;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7025ULL: goto x86_l_1b71;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7042ULL: goto x86_l_1b82;
	case 7044ULL: goto x86_l_1b84;
	case 7046ULL: goto x86_l_1b86;
	case 7053ULL: goto x86_l_1b8d;
	case 7055ULL: goto x86_l_1b8f;
	case 7061ULL: goto x86_l_1b95;
	case 7063ULL: goto x86_l_1b97;
	case 7066ULL: goto x86_l_1b9a;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7075ULL: goto x86_l_1ba3;
	case 7078ULL: goto x86_l_1ba6;
	case 7083ULL: goto x86_l_1bab;
	case 7090ULL: goto x86_l_1bb2;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7140ULL: goto x86_l_1be4;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7162ULL: goto x86_l_1bfa;
	case 7164ULL: goto x86_l_1bfc;
	case 7169ULL: goto x86_l_1c01;
	case 7174ULL: goto x86_l_1c06;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7193ULL: goto x86_l_1c19;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7219ULL: goto x86_l_1c33;
	case 7224ULL: goto x86_l_1c38;
	case 7226ULL: goto x86_l_1c3a;
	case 7234ULL: goto x86_l_1c42;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7336ULL: goto x86_l_1ca8;
	case 7339ULL: goto x86_l_1cab;
	case 7343ULL: goto x86_l_1caf;
	case 7345ULL: goto x86_l_1cb1;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7352ULL: goto x86_l_1cb8;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7374ULL: goto x86_l_1cce;
	case 7377ULL: goto x86_l_1cd1;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7404ULL: goto x86_l_1cec;
	case 7411ULL: goto x86_l_1cf3;
	case 7417ULL: goto x86_l_1cf9;
	case 7419ULL: goto x86_l_1cfb;
	case 7425ULL: goto x86_l_1d01;
	case 7429ULL: goto x86_l_1d05;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7440ULL: goto x86_l_1d10;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7537ULL: goto x86_l_1d71;
	case 7545ULL: goto x86_l_1d79;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7563ULL: goto x86_l_1d8b;
	case 7568ULL: goto x86_l_1d90;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7584ULL: goto x86_l_1da0;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7594ULL: goto x86_l_1daa;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7611ULL: goto x86_l_1dbb;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7629ULL: goto x86_l_1dcd;
	case 7634ULL: goto x86_l_1dd2;
	case 7639ULL: goto x86_l_1dd7;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7657ULL: goto x86_l_1de9;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7678ULL: goto x86_l_1dfe;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7695ULL: goto x86_l_1e0f;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7706ULL: goto x86_l_1e1a;
	case 7713ULL: goto x86_l_1e21;
	case 7718ULL: goto x86_l_1e26;
	case 7723ULL: goto x86_l_1e2b;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7779ULL: goto x86_l_1e63;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7790ULL: goto x86_l_1e6e;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7827ULL: goto x86_l_1e93;
	case 7834ULL: goto x86_l_1e9a;
	case 7838ULL: goto x86_l_1e9e;
	case 7845ULL: goto x86_l_1ea5;
	case 7849ULL: goto x86_l_1ea9;
	case 7856ULL: goto x86_l_1eb0;
	case 7863ULL: goto x86_l_1eb7;
	case 7870ULL: goto x86_l_1ebe;
	case 7878ULL: goto x86_l_1ec6;
	case 7881ULL: goto x86_l_1ec9;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7895ULL: goto x86_l_1ed7;
	case 7899ULL: goto x86_l_1edb;
	case 7903ULL: goto x86_l_1edf;
	case 7907ULL: goto x86_l_1ee3;
	case 7911ULL: goto x86_l_1ee7;
	case 7915ULL: goto x86_l_1eeb;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7933ULL: goto x86_l_1efd;
	case 7940ULL: goto x86_l_1f04;
	case 7947ULL: goto x86_l_1f0b;
	case 7951ULL: goto x86_l_1f0f;
	case 7958ULL: goto x86_l_1f16;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7979ULL: goto x86_l_1f2b;
	case 7987ULL: goto x86_l_1f33;
	case 7994ULL: goto x86_l_1f3a;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8006ULL: goto x86_l_1f46;
	case 8012ULL: goto x86_l_1f4c;
	case 8019ULL: goto x86_l_1f53;
	case 8025ULL: goto x86_l_1f59;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8052ULL: goto x86_l_1f74;
	case 8055ULL: goto x86_l_1f77;
	case 8062ULL: goto x86_l_1f7e;
	case 8070ULL: goto x86_l_1f86;
	case 8073ULL: goto x86_l_1f89;
	case 8075ULL: goto x86_l_1f8b;
	case 8082ULL: goto x86_l_1f92;
	case 8085ULL: goto x86_l_1f95;
	case 8087ULL: goto x86_l_1f97;
	case 8093ULL: goto x86_l_1f9d;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8113ULL: goto x86_l_1fb1;
	case 8117ULL: goto x86_l_1fb5;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8138ULL: goto x86_l_1fca;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8157ULL: goto x86_l_1fdd;
	case 8165ULL: goto x86_l_1fe5;
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8200ULL: goto x86_l_2008;
	case 8208ULL: goto x86_l_2010;
	case 8215ULL: goto x86_l_2017;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8247ULL: goto x86_l_2037;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8274ULL: goto x86_l_2052;
	case 8276ULL: goto x86_l_2054;
	case 8281ULL: goto x86_l_2059;
	case 8284ULL: goto x86_l_205c;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8297ULL: goto x86_l_2069;
	case 8299ULL: goto x86_l_206b;
	case 8303ULL: goto x86_l_206f;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8336ULL: goto x86_l_2090;
	case 8339ULL: goto x86_l_2093;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8360ULL: goto x86_l_20a8;
	case 8366ULL: goto x86_l_20ae;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8394ULL: goto x86_l_20ca;
	case 8400ULL: goto x86_l_20d0;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8421ULL: goto x86_l_20e5;
	case 8426ULL: goto x86_l_20ea;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8444ULL: goto x86_l_20fc;
	case 8453ULL: goto x86_l_2105;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8470ULL: goto x86_l_2116;
	case 8475ULL: goto x86_l_211b;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8500ULL: goto x86_l_2134;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8530ULL: goto x86_l_2152;
	case 8533ULL: goto x86_l_2155;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8547ULL: goto x86_l_2163;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8590ULL: goto x86_l_218e;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8614ULL: goto x86_l_21a6;
	case 8616ULL: goto x86_l_21a8;
	case 8621ULL: goto x86_l_21ad;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8645ULL: goto x86_l_21c5;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8663ULL: goto x86_l_21d7;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b0c:
	/* 0x1b0c: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b11:
	/* 0x1b11: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_1b17:
	/* 0x1b17: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1b1e:
	/* 0x1b1e: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_1b24:
	/* 0x1b24: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1b26:
	/* 0x1b26: jbe    2e7f <event_execve+0x2e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11903ULL;
	}
x86_l_1b2c:
	/* 0x1b2c: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1b30:
	/* 0x1b30: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_1b34:
	/* 0x1b34: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b37:
	/* 0x1b37: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1b3b:
	/* 0x1b3b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1b3e:
	/* 0x1b3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b43:
	/* 0x1b43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b45:
	/* 0x1b45: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b52:
	/* 0x1b52: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b57:
	/* 0x1b57: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b61:
	/* 0x1b61: jmp    1c14 <event_execve+0x1c14> */
	goto x86_l_1c14;
x86_l_1b66:
	/* 0x1b66: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b68:
	/* 0x1b68: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6a:
	/* 0x1b6a: and    r13d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_1b71:
	/* 0x1b71: and    ebp,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b77:
	/* 0x1b77: add    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b7a:
	/* 0x1b7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1b82:
	/* 0x1b82: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1b84:
	/* 0x1b84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b86:
	/* 0x1b86: mov    eax,DWORD PTR [r14+0x15c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1b8f:
	/* 0x1b8f: or     ecx,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 4096ULL);
x86_l_1b95:
	/* 0x1b95: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1b97:
	/* 0x1b97: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1b9a:
	/* 0x1b9a: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1b9c:
	/* 0x1b9c: or     eax,0x400000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 4194304ULL);
x86_l_1ba1:
	/* 0x1ba1: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1ba3:
	/* 0x1ba3: cmove  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_1ba6:
	/* 0x1ba6: and    eax,0xffffdbff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294958079ULL);
x86_l_1bab:
	/* 0x1bab: mov    DWORD PTR [r14+0x15c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    WORD PTR [r14+0x17c],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 380ULL);
x86_l_1bba:
	/* 0x1bba: jmp    1d3d <event_execve+0x1d3d> */
	goto x86_l_1d3d;
x86_l_1bbf:
	/* 0x1bbf: lea    rdx,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc8:
	/* 0x1bc8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcd:
	/* 0x1bcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd2:
	/* 0x1bd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd4:
	/* 0x1bd4: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bd9:
	/* 0x1bd9: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1bde:
	/* 0x1bde: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_1be4:
	/* 0x1be4: add    rbx,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_1be8:
	/* 0x1be8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bed:
	/* 0x1bed: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1bfa:
	/* 0x1bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfc:
	/* 0x1bfc: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c01:
	/* 0x1c01: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c06:
	/* 0x1c06: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c0a:
	/* 0x1c0a: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c14:
	/* 0x1c14: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1c19:
	/* 0x1c19: jne    1c26 <event_execve+0x1c26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c26;
	}
x86_l_1c1b:
	/* 0x1c1b: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_1c20:
	/* 0x1c20: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_1c26:
	/* 0x1c26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c2b:
	/* 0x1c2b: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c33:
	/* 0x1c33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c38:
	/* 0x1c38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3a:
	/* 0x1c3a: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_1c42:
	/* 0x1c42: je     21e2 <event_execve+0x21e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e2;
	}
x86_l_1c48:
	/* 0x1c48: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c4c:
	/* 0x1c4c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c51:
	/* 0x1c51: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c56:
	/* 0x1c56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c5e:
	/* 0x1c5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c60:
	/* 0x1c60: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c65:
	/* 0x1c65: je     21e2 <event_execve+0x21e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21e2;
	}
x86_l_1c6b:
	/* 0x1c6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c70:
	/* 0x1c70: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c78:
	/* 0x1c78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c80:
	/* 0x1c80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c82:
	/* 0x1c82: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1c86:
	/* 0x1c86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c8b:
	/* 0x1c8b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c90:
	/* 0x1c90: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c95:
	/* 0x1c95: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ca8:
	/* 0x1ca8: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1cab:
	/* 0x1cab: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1caf:
	/* 0x1caf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb1:
	/* 0x1cb1: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1cb3:
	/* 0x1cb3: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cb5:
	/* 0x1cb5: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1cb8:
	/* 0x1cb8: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1cbd:
	/* 0x1cbd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc0:
	/* 0x1cc0: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1cc2:
	/* 0x1cc2: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1cc6:
	/* 0x1cc6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1cc8:
	/* 0x1cc8: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1ccb:
	/* 0x1ccb: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cce:
	/* 0x1cce: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1cd1:
	/* 0x1cd1: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cd4:
	/* 0x1cd4: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1cd9:
	/* 0x1cd9: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1cdc:
	/* 0x1cdc: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ce6:
	/* 0x1ce6: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_1cec:
	/* 0x1cec: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1cf3:
	/* 0x1cf3: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_1cf9:
	/* 0x1cf9: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1cfb:
	/* 0x1cfb: jbe    2e7f <event_execve+0x2e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11903ULL;
	}
x86_l_1d01:
	/* 0x1d01: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1d05:
	/* 0x1d05: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_1d09:
	/* 0x1d09: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d0c:
	/* 0x1d0c: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1d10:
	/* 0x1d10: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1d13:
	/* 0x1d13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d18:
	/* 0x1d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1a:
	/* 0x1d1a: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1d27:
	/* 0x1d27: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d31:
	/* 0x1d31: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d36:
	/* 0x1d36: jmp    2237 <event_execve+0x2237> */
	return 8759ULL;
x86_l_1d3b:
	/* 0x1d3b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d3d:
	/* 0x1d3d: mov    r13d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d41:
	/* 0x1d41: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1d46:
	/* 0x1d46: mov    DWORD PTR [r14+0x140],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    WORD PTR [r14],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1d53:
	/* 0x1d53: mov    rax,QWORD PTR [r14+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5e:
	/* 0x1d5e: lea    eax,[r13+rbp*1+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 320ULL);
x86_l_1d66:
	/* 0x1d66: mov    DWORD PTR [r14+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d6a:
	/* 0x1d6a: lea    rbx,[r14+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1d71:
	/* 0x1d71: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d79:
	/* 0x1d79: lea    rdx,[r12+0xce0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_1d81:
	/* 0x1d81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d86:
	/* 0x1d86: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d8b:
	/* 0x1d8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d90:
	/* 0x1d90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d92:
	/* 0x1d92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d97:
	/* 0x1d97: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d9c:
	/* 0x1d9c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1da0:
	/* 0x1da0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1da3:
	/* 0x1da3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1da8:
	/* 0x1da8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1daa:
	/* 0x1daa: lea    rdi,[r14+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1db1:
	/* 0x1db1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db6:
	/* 0x1db6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dbb:
	/* 0x1dbb: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc4:
	/* 0x1dc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc6:
	/* 0x1dc6: lea    rdi,[r14+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1dcd:
	/* 0x1dcd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd2:
	/* 0x1dd2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1dd7:
	/* 0x1dd7: add    rdx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1de0:
	/* 0x1de0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de2:
	/* 0x1de2: lea    rdi,[r14+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1de9:
	/* 0x1de9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dee:
	/* 0x1dee: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1df3:
	/* 0x1df3: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_1df7:
	/* 0x1df7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dfc:
	/* 0x1dfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfe:
	/* 0x1dfe: lea    rdi,[r14+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e05:
	/* 0x1e05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e0a:
	/* 0x1e0a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e0f:
	/* 0x1e0f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e13:
	/* 0x1e13: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e18:
	/* 0x1e18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1a:
	/* 0x1e1a: lea    rdi,[r14+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1e21:
	/* 0x1e21: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e26:
	/* 0x1e26: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e2b:
	/* 0x1e2b: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e34:
	/* 0x1e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e36:
	/* 0x1e36: lea    rdi,[r14+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e42:
	/* 0x1e42: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e47:
	/* 0x1e47: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e50:
	/* 0x1e50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e52:
	/* 0x1e52: lea    rdi,[r14+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1e59:
	/* 0x1e59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e5e:
	/* 0x1e5e: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e63:
	/* 0x1e63: add    rdx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 36ULL);
x86_l_1e67:
	/* 0x1e67: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e6c:
	/* 0x1e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6e:
	/* 0x1e6e: lea    rdi,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1e75:
	/* 0x1e75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e7f:
	/* 0x1e7f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1e83:
	/* 0x1e83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e88:
	/* 0x1e88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8a:
	/* 0x1e8a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    rcx,QWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e93:
	/* 0x1e93: mov    QWORD PTR [r14+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9e:
	/* 0x1e9e: mov    QWORD PTR [r14+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ea9:
	/* 0x1ea9: mov    QWORD PTR [r14+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    eax,DWORD PTR [r14+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    DWORD PTR [r14+0x154],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 340ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    rax,QWORD PTR [r12+0xd48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_1ec6:
	/* 0x1ec6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ec9:
	/* 0x1ec9: je     1fb1 <event_execve+0x1fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb1;
	}
x86_l_1ecf:
	/* 0x1ecf: mov    r8,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    r9,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed7:
	/* 0x1ed7: mov    r10,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1edb:
	/* 0x1edb: mov    rdi,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1edf:
	/* 0x1edf: mov    rsi,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    rcx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    rax,QWORD PTR [rax+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eef:
	/* 0x1eef: mov    r8d,DWORD PTR [r8+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    DWORD PTR [r14+0x108],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1efd:
	/* 0x1efd: mov    r8d,DWORD PTR [r9+0x470] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_1f04:
	/* 0x1f04: mov    DWORD PTR [r14+0x10c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    r8d,DWORD PTR [r10+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0f:
	/* 0x1f0f: mov    DWORD PTR [r14+0x110],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1f16:
	/* 0x1f16: mov    r8,QWORD PTR [r12+0xb38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_1f1e:
	/* 0x1f1e: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: je     1f3c <event_execve+0x1f3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3c;
	}
x86_l_1f23:
	/* 0x1f23: movsxd r9,DWORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_R8, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_1f27:
	/* 0x1f27: shl    r9,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    r8,QWORD PTR [r8+r9*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 144ULL);
x86_l_1f33:
	/* 0x1f33: mov    r8d,DWORD PTR [r8+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f3a:
	/* 0x1f3a: jmp    1f3f <event_execve+0x1f3f> */
	goto x86_l_1f3f;
x86_l_1f3c:
	/* 0x1f3c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3f:
	/* 0x1f3f: mov    DWORD PTR [r14+0x114],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 276ULL);
x86_l_1f46:
	/* 0x1f46: mov    edi,DWORD PTR [rdi+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    DWORD PTR [r14+0x118],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1f53:
	/* 0x1f53: mov    esi,DWORD PTR [rsi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1f59:
	/* 0x1f59: mov    DWORD PTR [r14+0x11c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1f60:
	/* 0x1f60: mov    edx,DWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f63:
	/* 0x1f63: mov    DWORD PTR [r14+0x120],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    ecx,DWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6d:
	/* 0x1f6d: mov    DWORD PTR [r14+0x124],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292ULL);
x86_l_1f74:
	/* 0x1f74: mov    eax,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f77:
	/* 0x1f77: mov    DWORD PTR [r14+0x128],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    rax,QWORD PTR [r12+0xa50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_1f86:
	/* 0x1f86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f89:
	/* 0x1f89: je     1fa6 <event_execve+0x1fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fa6;
	}
x86_l_1f8b:
	/* 0x1f8b: mov    rax,QWORD PTR [rax+0x4a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1184ULL);
x86_l_1f92:
	/* 0x1f92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f95:
	/* 0x1f95: je     1fa6 <event_execve+0x1fa6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fa6;
	}
x86_l_1f97:
	/* 0x1f97: mov    eax,DWORD PTR [rax+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1f9d:
	/* 0x1f9d: mov    DWORD PTR [r14+0x12c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1fa4:
	/* 0x1fa4: jmp    1fb1 <event_execve+0x1fb1> */
	goto x86_l_1fb1;
x86_l_1fa6:
	/* 0x1fa6: mov    DWORD PTR [r14+0x12c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_1fb1:
	/* 0x1fb1: lea    r12,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1fc0:
	/* 0x1fc0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc2:
	/* 0x1fc2: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1fc7:
	/* 0x1fc7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1fca:
	/* 0x1fca: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fcc:
	/* 0x1fcc: call   1fd1 <event_execve+0x1fd1> */
	X86_SIM_L_EXEC_CALL_MEMSET(144ULL);
x86_l_1fd1:
	/* 0x1fd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fd6:
	/* 0x1fd6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_1fdd:
	/* 0x1fdd: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1fe5:
	/* 0x1fe5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe7:
	/* 0x1fe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fea:
	/* 0x1fea: je     1ffd <event_execve+0x1ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ffd;
	}
x86_l_1fec:
	/* 0x1fec: mov    ebx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fef:
	/* 0x1fef: cmp    QWORD PTR [rax+0x20],0x63677270 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 139106677360ULL);
x86_l_1ff7:
	/* 0x1ff7: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1ffb:
	/* 0x1ffb: jmp    1fff <event_execve+0x1fff> */
	goto x86_l_1fff;
x86_l_1ffd:
	/* 0x1ffd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fff:
	/* 0x1fff: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2008:
	/* 0x2008: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2010:
	/* 0x2010: add    rdx,0xf60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 3936ULL);
x86_l_2017:
	/* 0x2017: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_201c:
	/* 0x201c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2021:
	/* 0x2021: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2026:
	/* 0x2026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2028:
	/* 0x2028: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_202e:
	/* 0x202e: je     2672 <event_execve+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_2034:
	/* 0x2034: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_2037:
	/* 0x2037: je     20a5 <event_execve+0x20a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20a5;
	}
x86_l_2039:
	/* 0x2039: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_203e:
	/* 0x203e: mov    edx,0x88 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 136ULL);
x86_l_2043:
	/* 0x2043: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2048:
	/* 0x2048: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_204d:
	/* 0x204d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2052:
	/* 0x2052: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2054:
	/* 0x2054: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2059:
	/* 0x2059: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_205c:
	/* 0x205c: je     2672 <event_execve+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_2062:
	/* 0x2062: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_2067:
	/* 0x2067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2069:
	/* 0x2069: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_206b:
	/* 0x206b: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_206f:
	/* 0x206f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2072:
	/* 0x2072: je     215b <event_execve+0x215b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215b;
	}
x86_l_2078:
	/* 0x2078: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_207d:
	/* 0x207d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2082:
	/* 0x2082: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgtracker_map)));
x86_l_2089:
	/* 0x2089: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_208e:
	/* 0x208e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2090:
	/* 0x2090: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2093:
	/* 0x2093: je     2163 <event_execve+0x2163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2163;
	}
x86_l_2099:
	/* 0x2099: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209c:
	/* 0x209c: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20a0:
	/* 0x20a0: jmp    2169 <event_execve+0x2169> */
	goto x86_l_2169;
x86_l_20a5:
	/* 0x20a5: cmp    ebx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 11ULL);
x86_l_20a8:
	/* 0x20a8: ja     2672 <event_execve+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9842ULL;
	}
x86_l_20ae:
	/* 0x20ae: mov    edx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_20b0:
	/* 0x20b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20b5:
	/* 0x20b5: shl    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 3ULL);
x86_l_20b9:
	/* 0x20b9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20be:
	/* 0x20be: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20c3:
	/* 0x20c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20c8:
	/* 0x20c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ca:
	/* 0x20ca: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20d0:
	/* 0x20d0: je     265f <event_execve+0x265f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9823ULL;
	}
x86_l_20d6:
	/* 0x20d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20db:
	/* 0x20db: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20e0:
	/* 0x20e0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20e5:
	/* 0x20e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ea:
	/* 0x20ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ec:
	/* 0x20ec: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f1:
	/* 0x20f1: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_20f4:
	/* 0x20f4: je     2672 <event_execve+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_20fa:
	/* 0x20fa: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20fc:
	/* 0x20fc: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2105:
	/* 0x2105: lea    rdx,[rbx+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_210c:
	/* 0x210c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2111:
	/* 0x2111: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2116:
	/* 0x2116: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_211b:
	/* 0x211b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211d:
	/* 0x211d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2122:
	/* 0x2122: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_212b:
	/* 0x212b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_212e:
	/* 0x212e: je     21ce <event_execve+0x21ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ce;
	}
x86_l_2134:
	/* 0x2134: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2138:
	/* 0x2138: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_213d:
	/* 0x213d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2142:
	/* 0x2142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_214e:
	/* 0x214e: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2152:
	/* 0x2152: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2155:
	/* 0x2155: jne    2078 <event_execve+0x2078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2078;
	}
x86_l_215b:
	/* 0x215b: or     ebp,0x200000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 2097152ULL);
x86_l_2161:
	/* 0x2161: jmp    2169 <event_execve+0x2169> */
	goto x86_l_2169;
x86_l_2163:
	/* 0x2163: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2165:
	/* 0x2165: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2169:
	/* 0x2169: add    rbx,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_2170:
	/* 0x2170: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2175:
	/* 0x2175: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_217a:
	/* 0x217a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_217f:
	/* 0x217f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2182:
	/* 0x2182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2184:
	/* 0x2184: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2189:
	/* 0x2189: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218e:
	/* 0x218e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2192:
	/* 0x2192: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2197:
	/* 0x2197: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219c:
	/* 0x219c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219e:
	/* 0x219e: mov    ecx,0x10000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65536ULL);
x86_l_21a3:
	/* 0x21a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21a6:
	/* 0x21a6: jne    21c7 <event_execve+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21c7;
	}
x86_l_21a8:
	/* 0x21a8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ad:
	/* 0x21ad: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_21b0:
	/* 0x21b0: je     21c7 <event_execve+0x21c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c7;
	}
x86_l_21b2:
	/* 0x21b2: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_21b5:
	/* 0x21b5: add    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_21b9:
	/* 0x21b9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_21be:
	/* 0x21be: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_21c3:
	/* 0x21c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c5:
	/* 0x21c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c7:
	/* 0x21c7: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_21c9:
	/* 0x21c9: jmp    2674 <event_execve+0x2674> */
	return 9844ULL;
x86_l_21ce:
	/* 0x21ce: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21d0:
	/* 0x21d0: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d4:
	/* 0x21d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d7:
	/* 0x21d7: jne    2078 <event_execve+0x2078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2078;
	}
x86_l_21dd:
	/* 0x21dd: jmp    215b <event_execve+0x215b> */
	goto x86_l_215b;
x86_l_21e2:
	/* 0x21e2: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 8678ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8678ULL: goto x86_l_21e6;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8711ULL: goto x86_l_2207;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8777ULL: goto x86_l_2249;
	case 8782ULL: goto x86_l_224e;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8805ULL: goto x86_l_2265;
	case 8811ULL: goto x86_l_226b;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8867ULL: goto x86_l_22a3;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8907ULL: goto x86_l_22cb;
	case 8910ULL: goto x86_l_22ce;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8918ULL: goto x86_l_22d6;
	case 8920ULL: goto x86_l_22d8;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8933ULL: goto x86_l_22e5;
	case 8937ULL: goto x86_l_22e9;
	case 8939ULL: goto x86_l_22eb;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8964ULL: goto x86_l_2304;
	case 8969ULL: goto x86_l_2309;
	case 8975ULL: goto x86_l_230f;
	case 8982ULL: goto x86_l_2316;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8996ULL: goto x86_l_2324;
	case 9000ULL: goto x86_l_2328;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9011ULL: goto x86_l_2333;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9082ULL: goto x86_l_237a;
	case 9088ULL: goto x86_l_2380;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9110ULL: goto x86_l_2396;
	case 9112ULL: goto x86_l_2398;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9182ULL: goto x86_l_23de;
	case 9188ULL: goto x86_l_23e4;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9207ULL: goto x86_l_23f7;
	case 9210ULL: goto x86_l_23fa;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9236ULL: goto x86_l_2414;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9268ULL: goto x86_l_2434;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9284ULL: goto x86_l_2444;
	case 9287ULL: goto x86_l_2447;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9297ULL: goto x86_l_2451;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9308ULL: goto x86_l_245c;
	case 9310ULL: goto x86_l_245e;
	case 9314ULL: goto x86_l_2462;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9346ULL: goto x86_l_2482;
	case 9352ULL: goto x86_l_2488;
	case 9359ULL: goto x86_l_248f;
	case 9365ULL: goto x86_l_2495;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9377ULL: goto x86_l_24a1;
	case 9381ULL: goto x86_l_24a5;
	case 9384ULL: goto x86_l_24a8;
	case 9388ULL: goto x86_l_24ac;
	case 9391ULL: goto x86_l_24af;
	case 9396ULL: goto x86_l_24b4;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9411ULL: goto x86_l_24c3;
	case 9416ULL: goto x86_l_24c8;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9480ULL: goto x86_l_2508;
	case 9484ULL: goto x86_l_250c;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9609ULL: goto x86_l_2589;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9676ULL: goto x86_l_25cc;
	case 9679ULL: goto x86_l_25cf;
	case 9683ULL: goto x86_l_25d3;
	case 9685ULL: goto x86_l_25d5;
	case 9687ULL: goto x86_l_25d7;
	case 9689ULL: goto x86_l_25d9;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9728ULL: goto x86_l_2600;
	case 9733ULL: goto x86_l_2605;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9759ULL: goto x86_l_261f;
	case 9765ULL: goto x86_l_2625;
	case 9769ULL: goto x86_l_2629;
	case 9773ULL: goto x86_l_262d;
	case 9776ULL: goto x86_l_2630;
	case 9780ULL: goto x86_l_2634;
	case 9783ULL: goto x86_l_2637;
	case 9788ULL: goto x86_l_263c;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9836ULL: goto x86_l_266c;
	case 9842ULL: goto x86_l_2672;
	case 9844ULL: goto x86_l_2674;
	case 9851ULL: goto x86_l_267b;
	case 9862ULL: goto x86_l_2686;
	case 9873ULL: goto x86_l_2691;
	case 9878ULL: goto x86_l_2696;
	case 9885ULL: goto x86_l_269d;
	case 9888ULL: goto x86_l_26a0;
	case 9890ULL: goto x86_l_26a2;
	case 9892ULL: goto x86_l_26a4;
	case 9894ULL: goto x86_l_26a6;
	case 9901ULL: goto x86_l_26ad;
	case 9903ULL: goto x86_l_26af;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9928ULL: goto x86_l_26c8;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9946ULL: goto x86_l_26da;
	case 9950ULL: goto x86_l_26de;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9968ULL: goto x86_l_26f0;
	case 9970ULL: goto x86_l_26f2;
	case 9975ULL: goto x86_l_26f7;
	case 9980ULL: goto x86_l_26fc;
	case 9984ULL: goto x86_l_2700;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10006ULL: goto x86_l_2716;
	case 10011ULL: goto x86_l_271b;
	case 10017ULL: goto x86_l_2721;
	case 10022ULL: goto x86_l_2726;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10037ULL: goto x86_l_2735;
	case 10045ULL: goto x86_l_273d;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10065ULL: goto x86_l_2751;
	case 10070ULL: goto x86_l_2756;
	case 10073ULL: goto x86_l_2759;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10086ULL: goto x86_l_2766;
	case 10091ULL: goto x86_l_276b;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10113ULL: goto x86_l_2781;
	case 10118ULL: goto x86_l_2786;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10131ULL: goto x86_l_2793;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10143ULL: goto x86_l_279f;
	case 10147ULL: goto x86_l_27a3;
	case 10150ULL: goto x86_l_27a6;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10158ULL: goto x86_l_27ae;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10168ULL: goto x86_l_27b8;
	case 10171ULL: goto x86_l_27bb;
	case 10173ULL: goto x86_l_27bd;
	case 10177ULL: goto x86_l_27c1;
	case 10179ULL: goto x86_l_27c3;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10199ULL: goto x86_l_27d7;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10220ULL: goto x86_l_27ec;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10252ULL: goto x86_l_280c;
	case 10256ULL: goto x86_l_2810;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10266ULL: goto x86_l_281a;
	case 10271ULL: goto x86_l_281f;
	case 10279ULL: goto x86_l_2827;
	case 10284ULL: goto x86_l_282c;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10296ULL: goto x86_l_2838;
	case 10301ULL: goto x86_l_283d;
	case 10306ULL: goto x86_l_2842;
	case 10310ULL: goto x86_l_2846;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10325ULL: goto x86_l_2855;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10337ULL: goto x86_l_2861;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21e6:
	/* 0x21e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21eb:
	/* 0x21eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f0:
	/* 0x21f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f5:
	/* 0x21f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f7:
	/* 0x21f7: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21fc:
	/* 0x21fc: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2201:
	/* 0x2201: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2207:
	/* 0x2207: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_220b:
	/* 0x220b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2210:
	/* 0x2210: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2215:
	/* 0x2215: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_221a:
	/* 0x221a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_221d:
	/* 0x221d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221f:
	/* 0x221f: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2224:
	/* 0x2224: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2229:
	/* 0x2229: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222d:
	/* 0x222d: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2232:
	/* 0x2232: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2237:
	/* 0x2237: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_223c:
	/* 0x223c: jne    2249 <event_execve+0x2249> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2249;
	}
x86_l_223e:
	/* 0x223e: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2243:
	/* 0x2243: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2249:
	/* 0x2249: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_224e:
	/* 0x224e: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2256:
	/* 0x2256: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_225b:
	/* 0x225b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225d:
	/* 0x225d: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2265:
	/* 0x2265: je     235b <event_execve+0x235b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235b;
	}
x86_l_226b:
	/* 0x226b: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_226f:
	/* 0x226f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2274:
	/* 0x2274: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2279:
	/* 0x2279: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_227e:
	/* 0x227e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2281:
	/* 0x2281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2283:
	/* 0x2283: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2288:
	/* 0x2288: je     235b <event_execve+0x235b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235b;
	}
x86_l_228e:
	/* 0x228e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2293:
	/* 0x2293: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_229b:
	/* 0x229b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a0:
	/* 0x22a0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_22a3:
	/* 0x22a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a5:
	/* 0x22a5: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_22a9:
	/* 0x22a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ae:
	/* 0x22ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b3:
	/* 0x22b3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_22b8:
	/* 0x22b8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22bb:
	/* 0x22bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bd:
	/* 0x22bd: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22c2:
	/* 0x22c2: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22c7:
	/* 0x22c7: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22cb:
	/* 0x22cb: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_22ce:
	/* 0x22ce: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22d2:
	/* 0x22d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22d4:
	/* 0x22d4: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_22d6:
	/* 0x22d6: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22d8:
	/* 0x22d8: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_22db:
	/* 0x22db: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_22e0:
	/* 0x22e0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22e3:
	/* 0x22e3: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_22e5:
	/* 0x22e5: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_22e9:
	/* 0x22e9: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_22eb:
	/* 0x22eb: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_22ee:
	/* 0x22ee: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22f1:
	/* 0x22f1: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_22f4:
	/* 0x22f4: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22f7:
	/* 0x22f7: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_22fc:
	/* 0x22fc: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_22ff:
	/* 0x22ff: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2304:
	/* 0x2304: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2309:
	/* 0x2309: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_230f:
	/* 0x230f: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2316:
	/* 0x2316: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_231c:
	/* 0x231c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_231e:
	/* 0x231e: jbe    2e7f <event_execve+0x2e7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11903ULL;
	}
x86_l_2324:
	/* 0x2324: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2328:
	/* 0x2328: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_232c:
	/* 0x232c: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_232f:
	/* 0x232f: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2333:
	/* 0x2333: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2336:
	/* 0x2336: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_233b:
	/* 0x233b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233d:
	/* 0x233d: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2342:
	/* 0x2342: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_234a:
	/* 0x234a: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_234f:
	/* 0x234f: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2354:
	/* 0x2354: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2359:
	/* 0x2359: jmp    23b0 <event_execve+0x23b0> */
	goto x86_l_23b0;
x86_l_235b:
	/* 0x235b: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235f:
	/* 0x235f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2364:
	/* 0x2364: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2369:
	/* 0x2369: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_236e:
	/* 0x236e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2370:
	/* 0x2370: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2375:
	/* 0x2375: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_237a:
	/* 0x237a: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2380:
	/* 0x2380: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2384:
	/* 0x2384: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2389:
	/* 0x2389: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_238e:
	/* 0x238e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2393:
	/* 0x2393: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2396:
	/* 0x2396: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2398:
	/* 0x2398: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239d:
	/* 0x239d: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23a2:
	/* 0x23a2: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23a6:
	/* 0x23a6: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23ab:
	/* 0x23ab: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23b0:
	/* 0x23b0: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_23b5:
	/* 0x23b5: jne    23c2 <event_execve+0x23c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23c2;
	}
x86_l_23b7:
	/* 0x23b7: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_23bc:
	/* 0x23bc: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_23c2:
	/* 0x23c2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23c7:
	/* 0x23c7: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_23cf:
	/* 0x23cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d4:
	/* 0x23d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d6:
	/* 0x23d6: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_23de:
	/* 0x23de: je     24e3 <event_execve+0x24e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e3;
	}
x86_l_23e4:
	/* 0x23e4: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23e8:
	/* 0x23e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23ed:
	/* 0x23ed: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f2:
	/* 0x23f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23f7:
	/* 0x23f7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23fa:
	/* 0x23fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fc:
	/* 0x23fc: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2401:
	/* 0x2401: je     24e3 <event_execve+0x24e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e3;
	}
x86_l_2407:
	/* 0x2407: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_240c:
	/* 0x240c: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2414:
	/* 0x2414: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2419:
	/* 0x2419: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_241c:
	/* 0x241c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241e:
	/* 0x241e: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2422:
	/* 0x2422: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2427:
	/* 0x2427: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_242c:
	/* 0x242c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2431:
	/* 0x2431: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2434:
	/* 0x2434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2436:
	/* 0x2436: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_243b:
	/* 0x243b: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2440:
	/* 0x2440: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2444:
	/* 0x2444: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2447:
	/* 0x2447: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_244b:
	/* 0x244b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_244d:
	/* 0x244d: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_244f:
	/* 0x244f: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2451:
	/* 0x2451: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2454:
	/* 0x2454: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2459:
	/* 0x2459: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_245c:
	/* 0x245c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_245e:
	/* 0x245e: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2462:
	/* 0x2462: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2464:
	/* 0x2464: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2467:
	/* 0x2467: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_246a:
	/* 0x246a: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_246d:
	/* 0x246d: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2470:
	/* 0x2470: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2475:
	/* 0x2475: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2478:
	/* 0x2478: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_247d:
	/* 0x247d: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2482:
	/* 0x2482: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2488:
	/* 0x2488: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_248f:
	/* 0x248f: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_2495:
	/* 0x2495: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2497:
	/* 0x2497: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11888ULL;
	}
x86_l_249d:
	/* 0x249d: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24a1:
	/* 0x24a1: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_24a5:
	/* 0x24a5: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_24a8:
	/* 0x24a8: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_24ac:
	/* 0x24ac: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_24af:
	/* 0x24af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b4:
	/* 0x24b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b6:
	/* 0x24b6: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24bb:
	/* 0x24bb: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24c3:
	/* 0x24c3: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24c8:
	/* 0x24c8: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_24cd:
	/* 0x24cd: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24d2:
	/* 0x24d2: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24d7:
	/* 0x24d7: jmp    2538 <event_execve+0x2538> */
	goto x86_l_2538;
x86_l_24d9:
	/* 0x24d9: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24de:
	/* 0x24de: jmp    10b1 <event_execve+0x10b1> */
	return 4273ULL;
x86_l_24e3:
	/* 0x24e3: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e7:
	/* 0x24e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ec:
	/* 0x24ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24f1:
	/* 0x24f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f6:
	/* 0x24f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f8:
	/* 0x24f8: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24fd:
	/* 0x24fd: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2502:
	/* 0x2502: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2508:
	/* 0x2508: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_250c:
	/* 0x250c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2511:
	/* 0x2511: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2516:
	/* 0x2516: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251b:
	/* 0x251b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_251e:
	/* 0x251e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2520:
	/* 0x2520: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2525:
	/* 0x2525: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_252a:
	/* 0x252a: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_252e:
	/* 0x252e: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2533:
	/* 0x2533: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2538:
	/* 0x2538: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_253d:
	/* 0x253d: jne    254a <event_execve+0x254a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_254a;
	}
x86_l_253f:
	/* 0x253f: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2544:
	/* 0x2544: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_254a:
	/* 0x254a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_254f:
	/* 0x254f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2557:
	/* 0x2557: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255c:
	/* 0x255c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255e:
	/* 0x255e: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2566:
	/* 0x2566: je     26b5 <event_execve+0x26b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b5;
	}
x86_l_256c:
	/* 0x256c: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2570:
	/* 0x2570: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2575:
	/* 0x2575: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_257a:
	/* 0x257a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_257f:
	/* 0x257f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2582:
	/* 0x2582: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2584:
	/* 0x2584: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2589:
	/* 0x2589: je     26b5 <event_execve+0x26b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b5;
	}
x86_l_258f:
	/* 0x258f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2594:
	/* 0x2594: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_259c:
	/* 0x259c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25a1:
	/* 0x25a1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25a4:
	/* 0x25a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a6:
	/* 0x25a6: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_25aa:
	/* 0x25aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25af:
	/* 0x25af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b4:
	/* 0x25b4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25b9:
	/* 0x25b9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25bc:
	/* 0x25bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25be:
	/* 0x25be: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25c3:
	/* 0x25c3: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25c8:
	/* 0x25c8: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_25cc:
	/* 0x25cc: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_25cf:
	/* 0x25cf: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25d3:
	/* 0x25d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d5:
	/* 0x25d5: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_25d7:
	/* 0x25d7: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25d9:
	/* 0x25d9: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_25dc:
	/* 0x25dc: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_25e1:
	/* 0x25e1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25e4:
	/* 0x25e4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_25e6:
	/* 0x25e6: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_25ea:
	/* 0x25ea: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_25ec:
	/* 0x25ec: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_25ef:
	/* 0x25ef: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25f2:
	/* 0x25f2: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_25f5:
	/* 0x25f5: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25f8:
	/* 0x25f8: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25fd:
	/* 0x25fd: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2600:
	/* 0x2600: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2605:
	/* 0x2605: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_260a:
	/* 0x260a: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2610:
	/* 0x2610: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2617:
	/* 0x2617: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_261d:
	/* 0x261d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_261f:
	/* 0x261f: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11888ULL;
	}
x86_l_2625:
	/* 0x2625: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2629:
	/* 0x2629: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_262d:
	/* 0x262d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2630:
	/* 0x2630: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2634:
	/* 0x2634: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2637:
	/* 0x2637: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_263c:
	/* 0x263c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263e:
	/* 0x263e: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2643:
	/* 0x2643: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_264b:
	/* 0x264b: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2650:
	/* 0x2650: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2655:
	/* 0x2655: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_265a:
	/* 0x265a: jmp    270a <event_execve+0x270a> */
	goto x86_l_270a;
x86_l_265f:
	/* 0x265f: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2664:
	/* 0x2664: mov    ebp,0x80000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 524288ULL);
x86_l_2669:
	/* 0x2669: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_266c:
	/* 0x266c: jne    20fc <event_execve+0x20fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8444ULL;
	}
x86_l_2672:
	/* 0x2672: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2674:
	/* 0x2674: or     DWORD PTR [r14+0x15c],ecx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 348ULL);
x86_l_267b:
	/* 0x267b: mov    QWORD PTR [r14+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_2686:
	/* 0x2686: mov    QWORD PTR [r14+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2691:
	/* 0x2691: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2696:
	/* 0x2696: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&execve_calls)));
x86_l_269d:
	/* 0x269d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26a0:
	/* 0x26a0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26a2:
	/* 0x26a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26a4:
	/* 0x26a4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26a6:
	/* 0x26a6: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_26ad:
	/* 0x26ad: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_26af:
	/* 0x26af: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_26b0:
	/* 0x26b0: jmp    3066 <event_execve+0x3066> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_26b5:
	/* 0x26b5: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b9:
	/* 0x26b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26be:
	/* 0x26be: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26c3:
	/* 0x26c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c8:
	/* 0x26c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ca:
	/* 0x26ca: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26cf:
	/* 0x26cf: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_26d4:
	/* 0x26d4: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_26da:
	/* 0x26da: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_26de:
	/* 0x26de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e3:
	/* 0x26e3: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26e8:
	/* 0x26e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ed:
	/* 0x26ed: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_26f0:
	/* 0x26f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f2:
	/* 0x26f2: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f7:
	/* 0x26f7: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26fc:
	/* 0x26fc: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2700:
	/* 0x2700: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2705:
	/* 0x2705: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_270a:
	/* 0x270a: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_270f:
	/* 0x270f: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2714:
	/* 0x2714: jne    2721 <event_execve+0x2721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2721;
	}
x86_l_2716:
	/* 0x2716: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_271b:
	/* 0x271b: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2721:
	/* 0x2721: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2726:
	/* 0x2726: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_272e:
	/* 0x272e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2733:
	/* 0x2733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2735:
	/* 0x2735: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_273d:
	/* 0x273d: je     2842 <event_execve+0x2842> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2842;
	}
x86_l_2743:
	/* 0x2743: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2747:
	/* 0x2747: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_274c:
	/* 0x274c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2751:
	/* 0x2751: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2756:
	/* 0x2756: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2759:
	/* 0x2759: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275b:
	/* 0x275b: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2760:
	/* 0x2760: je     2842 <event_execve+0x2842> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2842;
	}
x86_l_2766:
	/* 0x2766: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_276b:
	/* 0x276b: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2773:
	/* 0x2773: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2778:
	/* 0x2778: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_277b:
	/* 0x277b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277d:
	/* 0x277d: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2781:
	/* 0x2781: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2786:
	/* 0x2786: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278b:
	/* 0x278b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2790:
	/* 0x2790: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2793:
	/* 0x2793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2795:
	/* 0x2795: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_279a:
	/* 0x279a: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_279f:
	/* 0x279f: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_27a3:
	/* 0x27a3: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_27a6:
	/* 0x27a6: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27aa:
	/* 0x27aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ac:
	/* 0x27ac: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_27ae:
	/* 0x27ae: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27b0:
	/* 0x27b0: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_27b3:
	/* 0x27b3: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_27b8:
	/* 0x27b8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27bb:
	/* 0x27bb: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_27bd:
	/* 0x27bd: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_27c1:
	/* 0x27c1: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_27c3:
	/* 0x27c3: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_27c6:
	/* 0x27c6: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27c9:
	/* 0x27c9: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_27cc:
	/* 0x27cc: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27cf:
	/* 0x27cf: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_27d4:
	/* 0x27d4: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_27d7:
	/* 0x27d7: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27dc:
	/* 0x27dc: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27e1:
	/* 0x27e1: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27e6:
	/* 0x27e6: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_27ec:
	/* 0x27ec: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_27f3:
	/* 0x27f3: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_27f9:
	/* 0x27f9: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_27fb:
	/* 0x27fb: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11888ULL;
	}
x86_l_2801:
	/* 0x2801: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2805:
	/* 0x2805: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2809:
	/* 0x2809: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_280c:
	/* 0x280c: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2810:
	/* 0x2810: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2813:
	/* 0x2813: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2818:
	/* 0x2818: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281a:
	/* 0x281a: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_281f:
	/* 0x281f: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2827:
	/* 0x2827: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_282c:
	/* 0x282c: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2831:
	/* 0x2831: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2836:
	/* 0x2836: jmp    289c <event_execve+0x289c> */
	return 10396ULL;
x86_l_2838:
	/* 0x2838: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_283d:
	/* 0x283d: jmp    10b1 <event_execve+0x10b1> */
	return 4273ULL;
x86_l_2842:
	/* 0x2842: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2846:
	/* 0x2846: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_284b:
	/* 0x284b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2850:
	/* 0x2850: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2855:
	/* 0x2855: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2857:
	/* 0x2857: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_285c:
	/* 0x285c: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2861:
	/* 0x2861: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 10342ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10342ULL: goto x86_l_2866;
	case 10348ULL: goto x86_l_286c;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10396ULL: goto x86_l_289c;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10439ULL: goto x86_l_28c7;
	case 10447ULL: goto x86_l_28cf;
	case 10453ULL: goto x86_l_28d5;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10475ULL: goto x86_l_28eb;
	case 10477ULL: goto x86_l_28ed;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10509ULL: goto x86_l_290d;
	case 10511ULL: goto x86_l_290f;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10549ULL: goto x86_l_2935;
	case 10552ULL: goto x86_l_2938;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10573ULL: goto x86_l_294d;
	case 10575ULL: goto x86_l_294f;
	case 10579ULL: goto x86_l_2953;
	case 10581ULL: goto x86_l_2955;
	case 10584ULL: goto x86_l_2958;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10622ULL: goto x86_l_297e;
	case 10629ULL: goto x86_l_2985;
	case 10635ULL: goto x86_l_298b;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10647ULL: goto x86_l_2997;
	case 10651ULL: goto x86_l_299b;
	case 10654ULL: goto x86_l_299e;
	case 10658ULL: goto x86_l_29a2;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10681ULL: goto x86_l_29b9;
	case 10686ULL: goto x86_l_29be;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10729ULL: goto x86_l_29e9;
	case 10734ULL: goto x86_l_29ee;
	case 10740ULL: goto x86_l_29f4;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10762ULL: goto x86_l_2a0a;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10831ULL: goto x86_l_2a4f;
	case 10839ULL: goto x86_l_2a57;
	case 10845ULL: goto x86_l_2a5d;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10893ULL: goto x86_l_2a8d;
	case 10898ULL: goto x86_l_2a92;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10907ULL: goto x86_l_2a9b;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10925ULL: goto x86_l_2aad;
	case 10927ULL: goto x86_l_2aaf;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10941ULL: goto x86_l_2abd;
	case 10944ULL: goto x86_l_2ac0;
	case 10948ULL: goto x86_l_2ac4;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10965ULL: goto x86_l_2ad5;
	case 10967ULL: goto x86_l_2ad7;
	case 10971ULL: goto x86_l_2adb;
	case 10973ULL: goto x86_l_2add;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10982ULL: goto x86_l_2ae6;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11014ULL: goto x86_l_2b06;
	case 11021ULL: goto x86_l_2b0d;
	case 11027ULL: goto x86_l_2b13;
	case 11029ULL: goto x86_l_2b15;
	case 11035ULL: goto x86_l_2b1b;
	case 11039ULL: goto x86_l_2b1f;
	case 11043ULL: goto x86_l_2b23;
	case 11046ULL: goto x86_l_2b26;
	case 11050ULL: goto x86_l_2b2a;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11065ULL: goto x86_l_2b39;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11094ULL: goto x86_l_2b56;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11111ULL: goto x86_l_2b67;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11132ULL: goto x86_l_2b7c;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11146ULL: goto x86_l_2b8a;
	case 11151ULL: goto x86_l_2b8f;
	case 11154ULL: goto x86_l_2b92;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11192ULL: goto x86_l_2bb8;
	case 11197ULL: goto x86_l_2bbd;
	case 11203ULL: goto x86_l_2bc3;
	case 11208ULL: goto x86_l_2bc8;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11223ULL: goto x86_l_2bd7;
	case 11231ULL: goto x86_l_2bdf;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11259ULL: goto x86_l_2bfb;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11272ULL: goto x86_l_2c08;
	case 11277ULL: goto x86_l_2c0d;
	case 11285ULL: goto x86_l_2c15;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11317ULL: goto x86_l_2c35;
	case 11319ULL: goto x86_l_2c37;
	case 11324ULL: goto x86_l_2c3c;
	case 11329ULL: goto x86_l_2c41;
	case 11333ULL: goto x86_l_2c45;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11344ULL: goto x86_l_2c50;
	case 11346ULL: goto x86_l_2c52;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11357ULL: goto x86_l_2c5d;
	case 11359ULL: goto x86_l_2c5f;
	case 11363ULL: goto x86_l_2c63;
	case 11365ULL: goto x86_l_2c65;
	case 11368ULL: goto x86_l_2c68;
	case 11371ULL: goto x86_l_2c6b;
	case 11374ULL: goto x86_l_2c6e;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11385ULL: goto x86_l_2c79;
	case 11390ULL: goto x86_l_2c7e;
	case 11395ULL: goto x86_l_2c83;
	case 11400ULL: goto x86_l_2c88;
	case 11406ULL: goto x86_l_2c8e;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11427ULL: goto x86_l_2ca3;
	case 11431ULL: goto x86_l_2ca7;
	case 11435ULL: goto x86_l_2cab;
	case 11438ULL: goto x86_l_2cae;
	case 11442ULL: goto x86_l_2cb2;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11511ULL: goto x86_l_2cf7;
	case 11516ULL: goto x86_l_2cfc;
	case 11518ULL: goto x86_l_2cfe;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11533ULL: goto x86_l_2d0d;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11577ULL: goto x86_l_2d39;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11597ULL: goto x86_l_2d4d;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11630ULL: goto x86_l_2d6e;
	case 11638ULL: goto x86_l_2d76;
	case 11644ULL: goto x86_l_2d7c;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11668ULL: goto x86_l_2d94;
	case 11673ULL: goto x86_l_2d99;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11736ULL: goto x86_l_2dd8;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11747ULL: goto x86_l_2de3;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11761ULL: goto x86_l_2df1;
	case 11764ULL: goto x86_l_2df4;
	case 11766ULL: goto x86_l_2df6;
	case 11770ULL: goto x86_l_2dfa;
	case 11772ULL: goto x86_l_2dfc;
	case 11775ULL: goto x86_l_2dff;
	case 11778ULL: goto x86_l_2e02;
	case 11781ULL: goto x86_l_2e05;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11792ULL: goto x86_l_2e10;
	case 11797ULL: goto x86_l_2e15;
	case 11802ULL: goto x86_l_2e1a;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11820ULL: goto x86_l_2e2c;
	case 11826ULL: goto x86_l_2e32;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11834ULL: goto x86_l_2e3a;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11860ULL: goto x86_l_2e54;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11903ULL: goto x86_l_2e7f;
	case 11906ULL: goto x86_l_2e82;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11948ULL: goto x86_l_2eac;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11971ULL: goto x86_l_2ec3;
	case 11975ULL: goto x86_l_2ec7;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11993ULL: goto x86_l_2ed9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2866:
	/* 0x2866: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_286c:
	/* 0x286c: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2870:
	/* 0x2870: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2875:
	/* 0x2875: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_287a:
	/* 0x287a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287f:
	/* 0x287f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2882:
	/* 0x2882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2884:
	/* 0x2884: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2889:
	/* 0x2889: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_288e:
	/* 0x288e: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2892:
	/* 0x2892: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2897:
	/* 0x2897: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_289c:
	/* 0x289c: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_28a1:
	/* 0x28a1: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_28a6:
	/* 0x28a6: jne    28b3 <event_execve+0x28b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28b3;
	}
x86_l_28a8:
	/* 0x28a8: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_28ad:
	/* 0x28ad: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_28b3:
	/* 0x28b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b8:
	/* 0x28b8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_28c0:
	/* 0x28c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c5:
	/* 0x28c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c7:
	/* 0x28c7: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_28cf:
	/* 0x28cf: je     29ca <event_execve+0x29ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ca;
	}
x86_l_28d5:
	/* 0x28d5: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28d9:
	/* 0x28d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28de:
	/* 0x28de: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e3:
	/* 0x28e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28e8:
	/* 0x28e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28eb:
	/* 0x28eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ed:
	/* 0x28ed: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f2:
	/* 0x28f2: je     29ca <event_execve+0x29ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29ca;
	}
x86_l_28f8:
	/* 0x28f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28fd:
	/* 0x28fd: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2905:
	/* 0x2905: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_290a:
	/* 0x290a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_290d:
	/* 0x290d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290f:
	/* 0x290f: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2913:
	/* 0x2913: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2918:
	/* 0x2918: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_291d:
	/* 0x291d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2922:
	/* 0x2922: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2925:
	/* 0x2925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2927:
	/* 0x2927: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_292c:
	/* 0x292c: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2931:
	/* 0x2931: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2935:
	/* 0x2935: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2938:
	/* 0x2938: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_293c:
	/* 0x293c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_293e:
	/* 0x293e: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2940:
	/* 0x2940: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2942:
	/* 0x2942: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2945:
	/* 0x2945: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_294a:
	/* 0x294a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_294d:
	/* 0x294d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_294f:
	/* 0x294f: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2953:
	/* 0x2953: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2955:
	/* 0x2955: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2958:
	/* 0x2958: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_295b:
	/* 0x295b: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_295e:
	/* 0x295e: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2961:
	/* 0x2961: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2966:
	/* 0x2966: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2969:
	/* 0x2969: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296e:
	/* 0x296e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2973:
	/* 0x2973: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2978:
	/* 0x2978: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_297e:
	/* 0x297e: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2985:
	/* 0x2985: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_298b:
	/* 0x298b: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_298d:
	/* 0x298d: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e70;
	}
x86_l_2993:
	/* 0x2993: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2997:
	/* 0x2997: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_299b:
	/* 0x299b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_299e:
	/* 0x299e: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_29a2:
	/* 0x29a2: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_29a5:
	/* 0x29a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29aa:
	/* 0x29aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ac:
	/* 0x29ac: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_29b1:
	/* 0x29b1: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_29b9:
	/* 0x29b9: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29be:
	/* 0x29be: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29c3:
	/* 0x29c3: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_29c8:
	/* 0x29c8: jmp    2a24 <event_execve+0x2a24> */
	goto x86_l_2a24;
x86_l_29ca:
	/* 0x29ca: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ce:
	/* 0x29ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29d3:
	/* 0x29d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d8:
	/* 0x29d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29dd:
	/* 0x29dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29df:
	/* 0x29df: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_29e4:
	/* 0x29e4: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_29e9:
	/* 0x29e9: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_29ee:
	/* 0x29ee: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_29f4:
	/* 0x29f4: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_29f8:
	/* 0x29f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29fd:
	/* 0x29fd: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a02:
	/* 0x2a02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a07:
	/* 0x2a07: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2a0a:
	/* 0x2a0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0c:
	/* 0x2a0c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a11:
	/* 0x2a11: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a16:
	/* 0x2a16: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a24:
	/* 0x2a24: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2a29:
	/* 0x2a29: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a2e:
	/* 0x2a2e: jne    2a3b <event_execve+0x2a3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a3b;
	}
x86_l_2a30:
	/* 0x2a30: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2a35:
	/* 0x2a35: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2a3b:
	/* 0x2a3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a40:
	/* 0x2a40: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a48:
	/* 0x2a48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a4d:
	/* 0x2a4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4f:
	/* 0x2a4f: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2a57:
	/* 0x2a57: je     2b52 <event_execve+0x2b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b52;
	}
x86_l_2a5d:
	/* 0x2a5d: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a61:
	/* 0x2a61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a66:
	/* 0x2a66: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a70:
	/* 0x2a70: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a73:
	/* 0x2a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a75:
	/* 0x2a75: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7a:
	/* 0x2a7a: je     2b52 <event_execve+0x2b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b52;
	}
x86_l_2a80:
	/* 0x2a80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a85:
	/* 0x2a85: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a92:
	/* 0x2a92: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a95:
	/* 0x2a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a97:
	/* 0x2a97: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aa0:
	/* 0x2aa0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2aaa:
	/* 0x2aaa: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2aad:
	/* 0x2aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aaf:
	/* 0x2aaf: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ab4:
	/* 0x2ab4: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2abd:
	/* 0x2abd: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ac0:
	/* 0x2ac0: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ac4:
	/* 0x2ac4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ac6:
	/* 0x2ac6: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2ac8:
	/* 0x2ac8: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2aca:
	/* 0x2aca: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2acd:
	/* 0x2acd: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2ad2:
	/* 0x2ad2: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad5:
	/* 0x2ad5: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2ad7:
	/* 0x2ad7: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2adb:
	/* 0x2adb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2add:
	/* 0x2add: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2ae0:
	/* 0x2ae0: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ae3:
	/* 0x2ae3: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2ae6:
	/* 0x2ae6: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ae9:
	/* 0x2ae9: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2aee:
	/* 0x2aee: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2af1:
	/* 0x2af1: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2af6:
	/* 0x2af6: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2afb:
	/* 0x2afb: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b00:
	/* 0x2b00: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2b06:
	/* 0x2b06: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2b0d:
	/* 0x2b0d: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_2b13:
	/* 0x2b13: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2b15:
	/* 0x2b15: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e70;
	}
x86_l_2b1b:
	/* 0x2b1b: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b1f:
	/* 0x2b1f: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2b23:
	/* 0x2b23: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2b26:
	/* 0x2b26: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2b2a:
	/* 0x2b2a: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2b2d:
	/* 0x2b2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b32:
	/* 0x2b32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b34:
	/* 0x2b34: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b39:
	/* 0x2b39: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b41:
	/* 0x2b41: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b46:
	/* 0x2b46: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b4b:
	/* 0x2b4b: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b50:
	/* 0x2b50: jmp    2bac <event_execve+0x2bac> */
	goto x86_l_2bac;
x86_l_2b52:
	/* 0x2b52: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b56:
	/* 0x2b56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b5b:
	/* 0x2b5b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b60:
	/* 0x2b60: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b65:
	/* 0x2b65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b67:
	/* 0x2b67: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b6c:
	/* 0x2b6c: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2b71:
	/* 0x2b71: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b76:
	/* 0x2b76: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2b7c:
	/* 0x2b7c: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2b80:
	/* 0x2b80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b85:
	/* 0x2b85: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b8a:
	/* 0x2b8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b8f:
	/* 0x2b8f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b92:
	/* 0x2b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b94:
	/* 0x2b94: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b99:
	/* 0x2b99: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2b9e:
	/* 0x2b9e: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ba2:
	/* 0x2ba2: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ba7:
	/* 0x2ba7: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bac:
	/* 0x2bac: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bb6:
	/* 0x2bb6: jne    2bc3 <event_execve+0x2bc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bc3;
	}
x86_l_2bb8:
	/* 0x2bb8: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2bbd:
	/* 0x2bbd: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2bc3:
	/* 0x2bc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bc8:
	/* 0x2bc8: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bd5:
	/* 0x2bd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd7:
	/* 0x2bd7: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2bdf:
	/* 0x2bdf: je     2ce9 <event_execve+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2be5:
	/* 0x2be5: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2be9:
	/* 0x2be9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bee:
	/* 0x2bee: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf3:
	/* 0x2bf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bf8:
	/* 0x2bf8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2bfb:
	/* 0x2bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bfd:
	/* 0x2bfd: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c02:
	/* 0x2c02: je     2ce9 <event_execve+0x2ce9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce9;
	}
x86_l_2c08:
	/* 0x2c08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c0d:
	/* 0x2c0d: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c15:
	/* 0x2c15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1a:
	/* 0x2c1a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c1d:
	/* 0x2c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1f:
	/* 0x2c1f: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2c23:
	/* 0x2c23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c28:
	/* 0x2c28: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c32:
	/* 0x2c32: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c35:
	/* 0x2c35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c37:
	/* 0x2c37: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c3c:
	/* 0x2c3c: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c41:
	/* 0x2c41: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2c45:
	/* 0x2c45: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c48:
	/* 0x2c48: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2c4c:
	/* 0x2c4c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c4e:
	/* 0x2c4e: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2c50:
	/* 0x2c50: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c52:
	/* 0x2c52: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2c55:
	/* 0x2c55: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2c5a:
	/* 0x2c5a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c5d:
	/* 0x2c5d: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2c5f:
	/* 0x2c5f: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2c63:
	/* 0x2c63: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2c65:
	/* 0x2c65: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2c68:
	/* 0x2c68: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c6b:
	/* 0x2c6b: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2c6e:
	/* 0x2c6e: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c71:
	/* 0x2c71: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2c76:
	/* 0x2c76: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c79:
	/* 0x2c79: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c7e:
	/* 0x2c7e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c83:
	/* 0x2c83: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c88:
	/* 0x2c88: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2c8e:
	/* 0x2c8e: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2c95:
	/* 0x2c95: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_2c9b:
	/* 0x2c9b: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2c9d:
	/* 0x2c9d: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e70;
	}
x86_l_2ca3:
	/* 0x2ca3: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2cab:
	/* 0x2cab: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2cae:
	/* 0x2cae: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2cb2:
	/* 0x2cb2: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2cb5:
	/* 0x2cb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cba:
	/* 0x2cba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbc:
	/* 0x2cbc: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2cc1:
	/* 0x2cc1: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2cc9:
	/* 0x2cc9: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cce:
	/* 0x2cce: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2cd8:
	/* 0x2cd8: jmp    2d43 <event_execve+0x2d43> */
	goto x86_l_2d43;
x86_l_2cda:
	/* 0x2cda: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2cdf:
	/* 0x2cdf: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ce4:
	/* 0x2ce4: jmp    10b1 <event_execve+0x10b1> */
	return 4273ULL;
x86_l_2ce9:
	/* 0x2ce9: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ced:
	/* 0x2ced: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cf2:
	/* 0x2cf2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf7:
	/* 0x2cf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cfc:
	/* 0x2cfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cfe:
	/* 0x2cfe: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d03:
	/* 0x2d03: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d08:
	/* 0x2d08: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d0d:
	/* 0x2d0d: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2d13:
	/* 0x2d13: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2d17:
	/* 0x2d17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d1c:
	/* 0x2d1c: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d21:
	/* 0x2d21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d26:
	/* 0x2d26: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2d29:
	/* 0x2d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2b:
	/* 0x2d2b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d30:
	/* 0x2d30: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d35:
	/* 0x2d35: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d39:
	/* 0x2d39: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d43:
	/* 0x2d43: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2d48:
	/* 0x2d48: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d4d:
	/* 0x2d4d: jne    2d5a <event_execve+0x2d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d5a;
	}
x86_l_2d4f:
	/* 0x2d4f: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2d54:
	/* 0x2d54: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2d5a:
	/* 0x2d5a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d5f:
	/* 0x2d5f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2d67:
	/* 0x2d67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d6c:
	/* 0x2d6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6e:
	/* 0x2d6e: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2d76:
	/* 0x2d76: je     2e99 <event_execve+0x2e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e99;
	}
x86_l_2d7c:
	/* 0x2d7c: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d80:
	/* 0x2d80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d85:
	/* 0x2d85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d8f:
	/* 0x2d8f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d92:
	/* 0x2d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d94:
	/* 0x2d94: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d99:
	/* 0x2d99: je     2e99 <event_execve+0x2e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e99;
	}
x86_l_2d9f:
	/* 0x2d9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da4:
	/* 0x2da4: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2dac:
	/* 0x2dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db1:
	/* 0x2db1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2db4:
	/* 0x2db4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db6:
	/* 0x2db6: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2dba:
	/* 0x2dba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dbf:
	/* 0x2dbf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc4:
	/* 0x2dc4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2dc9:
	/* 0x2dc9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dcc:
	/* 0x2dcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dce:
	/* 0x2dce: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2dd3:
	/* 0x2dd3: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2dd8:
	/* 0x2dd8: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2ddc:
	/* 0x2ddc: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ddf:
	/* 0x2ddf: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2de3:
	/* 0x2de3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de5:
	/* 0x2de5: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2de7:
	/* 0x2de7: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2de9:
	/* 0x2de9: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2dec:
	/* 0x2dec: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2df1:
	/* 0x2df1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df4:
	/* 0x2df4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2df6:
	/* 0x2df6: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2dfa:
	/* 0x2dfa: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2dfc:
	/* 0x2dfc: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2dff:
	/* 0x2dff: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e02:
	/* 0x2e02: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2e05:
	/* 0x2e05: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e08:
	/* 0x2e08: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e0d:
	/* 0x2e0d: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e10:
	/* 0x2e10: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e15:
	/* 0x2e15: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e1a:
	/* 0x2e1a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e1f:
	/* 0x2e1f: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2e25:
	/* 0x2e25: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2e2c:
	/* 0x2e2c: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_2e32:
	/* 0x2e32: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e34:
	/* 0x2e34: jbe    2e70 <event_execve+0x2e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e70;
	}
x86_l_2e36:
	/* 0x2e36: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2e3e:
	/* 0x2e3e: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e41:
	/* 0x2e41: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2e45:
	/* 0x2e45: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e48:
	/* 0x2e48: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e4d:
	/* 0x2e4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4f:
	/* 0x2e4f: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e54:
	/* 0x2e54: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2e5c:
	/* 0x2e5c: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e61:
	/* 0x2e61: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e66:
	/* 0x2e66: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e6b:
	/* 0x2e6b: jmp    2ef3 <event_execve+0x2ef3> */
	return 12019ULL;
x86_l_2e70:
	/* 0x2e70: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e75:
	/* 0x2e75: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e7a:
	/* 0x2e7a: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e7f:
	/* 0x2e7f: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e82:
	/* 0x2e82: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e85:
	/* 0x2e85: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2e8d:
	/* 0x2e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8f:
	/* 0x2e8f: mov    QWORD PTR [rsp+0x60],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2e94:
	/* 0x2e94: jmp    1a09 <event_execve+0x1a09> */
	return 6665ULL;
x86_l_2e99:
	/* 0x2e99: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea2:
	/* 0x2ea2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ea7:
	/* 0x2ea7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eac:
	/* 0x2eac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eae:
	/* 0x2eae: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2eb3:
	/* 0x2eb3: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2eb8:
	/* 0x2eb8: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ebd:
	/* 0x2ebd: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2ec3:
	/* 0x2ec3: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2ec7:
	/* 0x2ec7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ecc:
	/* 0x2ecc: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ed1:
	/* 0x2ed1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2ed9:
	/* 0x2ed9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 11995ULL;
}

static __noinline __u64 tetragon_bpf_execve_event_event_execve_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12042ULL: goto x86_l_2f0a;
	case 12047ULL: goto x86_l_2f0f;
	case 12055ULL: goto x86_l_2f17;
	case 12060ULL: goto x86_l_2f1c;
	case 12062ULL: goto x86_l_2f1e;
	case 12070ULL: goto x86_l_2f26;
	case 12076ULL: goto x86_l_2f2c;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12095ULL: goto x86_l_2f3f;
	case 12098ULL: goto x86_l_2f42;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12111ULL: goto x86_l_2f4f;
	case 12116ULL: goto x86_l_2f54;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12138ULL: goto x86_l_2f6a;
	case 12143ULL: goto x86_l_2f6f;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12156ULL: goto x86_l_2f7c;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12172ULL: goto x86_l_2f8c;
	case 12175ULL: goto x86_l_2f8f;
	case 12179ULL: goto x86_l_2f93;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12185ULL: goto x86_l_2f99;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12196ULL: goto x86_l_2fa4;
	case 12198ULL: goto x86_l_2fa6;
	case 12202ULL: goto x86_l_2faa;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12210ULL: goto x86_l_2fb2;
	case 12213ULL: goto x86_l_2fb5;
	case 12216ULL: goto x86_l_2fb8;
	case 12221ULL: goto x86_l_2fbd;
	case 12224ULL: goto x86_l_2fc0;
	case 12229ULL: goto x86_l_2fc5;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12245ULL: goto x86_l_2fd5;
	case 12252ULL: goto x86_l_2fdc;
	case 12258ULL: goto x86_l_2fe2;
	case 12260ULL: goto x86_l_2fe4;
	case 12266ULL: goto x86_l_2fea;
	case 12270ULL: goto x86_l_2fee;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12281ULL: goto x86_l_2ff9;
	case 12284ULL: goto x86_l_2ffc;
	case 12289ULL: goto x86_l_3001;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12304ULL: goto x86_l_3010;
	case 12309ULL: goto x86_l_3015;
	case 12314ULL: goto x86_l_301a;
	case 12319ULL: goto x86_l_301f;
	case 12323ULL: goto x86_l_3023;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12338ULL: goto x86_l_3032;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12355ULL: goto x86_l_3043;
	case 12361ULL: goto x86_l_3049;
	case 12365ULL: goto x86_l_304d;
	case 12370ULL: goto x86_l_3052;
	case 12375ULL: goto x86_l_3057;
	case 12380ULL: goto x86_l_305c;
	case 12383ULL: goto x86_l_305f;
	case 12385ULL: goto x86_l_3061;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2edb:
	/* 0x2edb: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee0:
	/* 0x2ee0: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ee5:
	/* 0x2ee5: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee9:
	/* 0x2ee9: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2eee:
	/* 0x2eee: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ef3:
	/* 0x2ef3: cmp    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2efd:
	/* 0x2efd: jne    2f0a <event_execve+0x2f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f0a;
	}
x86_l_2eff:
	/* 0x2eff: cmp    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_2f04:
	/* 0x2f04: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_2f0a:
	/* 0x2f0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f0f:
	/* 0x2f0f: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2f17:
	/* 0x2f17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1c:
	/* 0x2f1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1e:
	/* 0x2f1e: cmp    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 128ULL);
x86_l_2f26:
	/* 0x2f26: je     301f <event_execve+0x301f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_301f;
	}
x86_l_2f2c:
	/* 0x2f2c: lea    r13,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f30:
	/* 0x2f30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f35:
	/* 0x2f35: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f3a:
	/* 0x2f3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f42:
	/* 0x2f42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f44:
	/* 0x2f44: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f49:
	/* 0x2f49: je     301f <event_execve+0x301f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_301f;
	}
x86_l_2f4f:
	/* 0x2f4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f54:
	/* 0x2f54: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f5c:
	/* 0x2f5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f61:
	/* 0x2f61: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f64:
	/* 0x2f64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f66:
	/* 0x2f66: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2f6a:
	/* 0x2f6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f6f:
	/* 0x2f6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f74:
	/* 0x2f74: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f79:
	/* 0x2f79: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f7c:
	/* 0x2f7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7e:
	/* 0x2f7e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2f83:
	/* 0x2f83: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f88:
	/* 0x2f88: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2f8c:
	/* 0x2f8c: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f8f:
	/* 0x2f8f: mov    edi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f93:
	/* 0x2f93: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f95:
	/* 0x2f95: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2f97:
	/* 0x2f97: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f99:
	/* 0x2f99: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2f9c:
	/* 0x2f9c: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2fa1:
	/* 0x2fa1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fa4:
	/* 0x2fa4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2fa6:
	/* 0x2fa6: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2faa:
	/* 0x2faa: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2fac:
	/* 0x2fac: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2faf:
	/* 0x2faf: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2fb2:
	/* 0x2fb2: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2fb5:
	/* 0x2fb5: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fb8:
	/* 0x2fb8: mov    DWORD PTR [rsp+0x68],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2fbd:
	/* 0x2fbd: sub    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2fc0:
	/* 0x2fc0: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc5:
	/* 0x2fc5: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2fca:
	/* 0x2fca: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fcf:
	/* 0x2fcf: jb     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6665ULL;
	}
x86_l_2fd5:
	/* 0x2fd5: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2fdc:
	/* 0x2fdc: ja     1a09 <event_execve+0x1a09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6665ULL;
	}
x86_l_2fe2:
	/* 0x2fe2: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2fe4:
	/* 0x2fe4: jbe    2e75 <event_execve+0x2e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11893ULL;
	}
x86_l_2fea:
	/* 0x2fea: lea    rbx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2fee:
	/* 0x2fee: mov    BYTE PTR [rax+rbp*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBP, 0), 47ULL);
x86_l_2ff2:
	/* 0x2ff2: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ff5:
	/* 0x2ff5: lea    rdi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2ff9:
	/* 0x2ff9: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2ffc:
	/* 0x2ffc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3001:
	/* 0x3001: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3003:
	/* 0x3003: mov    QWORD PTR [rsp+0x60],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3008:
	/* 0x3008: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3010:
	/* 0x3010: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3015:
	/* 0x3015: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_301a:
	/* 0x301a: jmp    1a04 <event_execve+0x1a04> */
	return 6660ULL;
x86_l_301f:
	/* 0x301f: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3023:
	/* 0x3023: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3028:
	/* 0x3028: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_302d:
	/* 0x302d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3032:
	/* 0x3032: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3034:
	/* 0x3034: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3039:
	/* 0x3039: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_303e:
	/* 0x303e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3043:
	/* 0x3043: je     19fa <event_execve+0x19fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6650ULL;
	}
x86_l_3049:
	/* 0x3049: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_304d:
	/* 0x304d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3052:
	/* 0x3052: lea    rdi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3057:
	/* 0x3057: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_305c:
	/* 0x305c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_305f:
	/* 0x305f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3061:
	/* 0x3061: jmp    19ff <event_execve+0x19ff> */
	return 6655ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_execve_event_event_execve_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11116U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1681ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1683ULL && __x86_pc <= 3416ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3423ULL && __x86_pc <= 5132ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5138ULL && __x86_pc <= 6919ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6924ULL && __x86_pc <= 8674ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8678ULL && __x86_pc <= 10337ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10342ULL && __x86_pc <= 11993ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11995ULL && __x86_pc <= 12385ULL)
			__x86_pc = tetragon_bpf_execve_event_event_execve_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

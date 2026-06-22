extern char __config_endpoint_id;
extern char __config_security_label;
extern char cilium_calls;
extern char cilium_metrics;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 19ULL: goto x86_l_13;
	case 23ULL: goto x86_l_17;
	case 26ULL: goto x86_l_1a;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 39ULL: goto x86_l_27;
	case 42ULL: goto x86_l_2a;
	case 50ULL: goto x86_l_32;
	case 57ULL: goto x86_l_39;
	case 62ULL: goto x86_l_3e;
	case 68ULL: goto x86_l_44;
	case 71ULL: goto x86_l_47;
	case 74ULL: goto x86_l_4a;
	case 77ULL: goto x86_l_4d;
	case 79ULL: goto x86_l_4f;
	case 88ULL: goto x86_l_58;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 113ULL: goto x86_l_71;
	case 115ULL: goto x86_l_73;
	case 117ULL: goto x86_l_75;
	case 119ULL: goto x86_l_77;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
	case 140ULL: goto x86_l_8c;
	case 143ULL: goto x86_l_8f;
	case 145ULL: goto x86_l_91;
	case 148ULL: goto x86_l_94;
	case 151ULL: goto x86_l_97;
	case 154ULL: goto x86_l_9a;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 174ULL: goto x86_l_ae;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 200ULL: goto x86_l_c8;
	case 204ULL: goto x86_l_cc;
	case 208ULL: goto x86_l_d0;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 226ULL: goto x86_l_e2;
	case 233ULL: goto x86_l_e9;
	case 235ULL: goto x86_l_eb;
	case 238ULL: goto x86_l_ee;
	case 241ULL: goto x86_l_f1;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 253ULL: goto x86_l_fd;
	case 262ULL: goto x86_l_106;
	case 269ULL: goto x86_l_10d;
	case 274ULL: goto x86_l_112;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 286ULL: goto x86_l_11e;
	case 288ULL: goto x86_l_120;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 297ULL: goto x86_l_129;
	case 301ULL: goto x86_l_12d;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 320ULL: goto x86_l_140;
	case 329ULL: goto x86_l_149;
	case 338ULL: goto x86_l_152;
	case 342ULL: goto x86_l_156;
	case 345ULL: goto x86_l_159;
	case 349ULL: goto x86_l_15d;
	case 352ULL: goto x86_l_160;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 369ULL: goto x86_l_171;
	case 372ULL: goto x86_l_174;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 385ULL: goto x86_l_181;
	case 387ULL: goto x86_l_183;
	case 393ULL: goto x86_l_189;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 403ULL: goto x86_l_193;
	case 408ULL: goto x86_l_198;
	case 411ULL: goto x86_l_19b;
	case 413ULL: goto x86_l_19d;
	case 419ULL: goto x86_l_1a3;
	case 423ULL: goto x86_l_1a7;
	case 428ULL: goto x86_l_1ac;
	case 432ULL: goto x86_l_1b0;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 446ULL: goto x86_l_1be;
	case 450ULL: goto x86_l_1c2;
	case 453ULL: goto x86_l_1c5;
	case 460ULL: goto x86_l_1cc;
	case 466ULL: goto x86_l_1d2;
	case 470ULL: goto x86_l_1d6;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 487ULL: goto x86_l_1e7;
	case 489ULL: goto x86_l_1e9;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 508ULL: goto x86_l_1fc;
	case 511ULL: goto x86_l_1ff;
	case 513ULL: goto x86_l_201;
	case 518ULL: goto x86_l_206;
	case 520ULL: goto x86_l_208;
	case 523ULL: goto x86_l_20b;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 536ULL: goto x86_l_218;
	case 540ULL: goto x86_l_21c;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 549ULL: goto x86_l_225;
	case 552ULL: goto x86_l_228;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 565ULL: goto x86_l_235;
	case 568ULL: goto x86_l_238;
	case 572ULL: goto x86_l_23c;
	case 578ULL: goto x86_l_242;
	case 581ULL: goto x86_l_245;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 594ULL: goto x86_l_252;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 603ULL: goto x86_l_25b;
	case 605ULL: goto x86_l_25d;
	case 607ULL: goto x86_l_25f;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 617ULL: goto x86_l_269;
	case 620ULL: goto x86_l_26c;
	case 626ULL: goto x86_l_272;
	case 633ULL: goto x86_l_279;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 645ULL: goto x86_l_285;
	case 648ULL: goto x86_l_288;
	case 658ULL: goto x86_l_292;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 675ULL: goto x86_l_2a3;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 708ULL: goto x86_l_2c4;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 715ULL: goto x86_l_2cb;
	case 718ULL: goto x86_l_2ce;
	case 722ULL: goto x86_l_2d2;
	case 724ULL: goto x86_l_2d4;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 760ULL: goto x86_l_2f8;
	case 762ULL: goto x86_l_2fa;
	case 764ULL: goto x86_l_2fc;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 779ULL: goto x86_l_30b;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 797ULL: goto x86_l_31d;
	case 798ULL: goto x86_l_31e;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 818ULL: goto x86_l_332;
	case 823ULL: goto x86_l_337;
	case 827ULL: goto x86_l_33b;
	case 831ULL: goto x86_l_33f;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 847ULL: goto x86_l_34f;
	case 851ULL: goto x86_l_353;
	case 858ULL: goto x86_l_35a;
	case 864ULL: goto x86_l_360;
	case 869ULL: goto x86_l_365;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 882ULL: goto x86_l_372;
	case 887ULL: goto x86_l_377;
	case 891ULL: goto x86_l_37b;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 915ULL: goto x86_l_393;
	case 918ULL: goto x86_l_396;
	case 921ULL: goto x86_l_399;
	case 924ULL: goto x86_l_39c;
	case 927ULL: goto x86_l_39f;
	case 930ULL: goto x86_l_3a2;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 947ULL: goto x86_l_3b3;
	case 950ULL: goto x86_l_3b6;
	case 952ULL: goto x86_l_3b8;
	case 955ULL: goto x86_l_3bb;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 964ULL: goto x86_l_3c4;
	case 967ULL: goto x86_l_3c7;
	case 969ULL: goto x86_l_3c9;
	case 973ULL: goto x86_l_3cd;
	case 975ULL: goto x86_l_3cf;
	case 978ULL: goto x86_l_3d2;
	case 982ULL: goto x86_l_3d6;
	case 985ULL: goto x86_l_3d9;
	case 988ULL: goto x86_l_3dc;
	case 990ULL: goto x86_l_3de;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1000ULL: goto x86_l_3e8;
	case 1002ULL: goto x86_l_3ea;
	case 1006ULL: goto x86_l_3ee;
	case 1009ULL: goto x86_l_3f1;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1022ULL: goto x86_l_3fe;
	case 1025ULL: goto x86_l_401;
	case 1029ULL: goto x86_l_405;
	case 1032ULL: goto x86_l_408;
	case 1034ULL: goto x86_l_40a;
	case 1038ULL: goto x86_l_40e;
	case 1040ULL: goto x86_l_410;
	case 1042ULL: goto x86_l_412;
	case 1046ULL: goto x86_l_416;
	case 1050ULL: goto x86_l_41a;
	case 1056ULL: goto x86_l_420;
	case 1059ULL: goto x86_l_423;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1066ULL: goto x86_l_42a;
	case 1069ULL: goto x86_l_42d;
	case 1071ULL: goto x86_l_42f;
	case 1073ULL: goto x86_l_431;
	case 1077ULL: goto x86_l_435;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1099ULL: goto x86_l_44b;
	case 1104ULL: goto x86_l_450;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1119ULL: goto x86_l_45f;
	case 1125ULL: goto x86_l_465;
	case 1128ULL: goto x86_l_468;
	case 1130ULL: goto x86_l_46a;
	case 1140ULL: goto x86_l_474;
	case 1145ULL: goto x86_l_479;
	case 1150ULL: goto x86_l_47e;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1169ULL: goto x86_l_491;
	case 1172ULL: goto x86_l_494;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1198ULL: goto x86_l_4ae;
	case 1203ULL: goto x86_l_4b3;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1229ULL: goto x86_l_4cd;
	case 1232ULL: goto x86_l_4d0;
	case 1237ULL: goto x86_l_4d5;
	case 1241ULL: goto x86_l_4d9;
	case 1244ULL: goto x86_l_4dc;
	case 1246ULL: goto x86_l_4de;
	case 1250ULL: goto x86_l_4e2;
	case 1253ULL: goto x86_l_4e5;
	case 1255ULL: goto x86_l_4e7;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1266ULL: goto x86_l_4f2;
	case 1268ULL: goto x86_l_4f4;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1287ULL: goto x86_l_507;
	case 1291ULL: goto x86_l_50b;
	case 1294ULL: goto x86_l_50e;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1301ULL: goto x86_l_515;
	case 1304ULL: goto x86_l_518;
	case 1306ULL: goto x86_l_51a;
	case 1310ULL: goto x86_l_51e;
	case 1316ULL: goto x86_l_524;
	case 1320ULL: goto x86_l_528;
	case 1323ULL: goto x86_l_52b;
	case 1325ULL: goto x86_l_52d;
	case 1329ULL: goto x86_l_531;
	case 1332ULL: goto x86_l_534;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1340ULL: goto x86_l_53c;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1357ULL: goto x86_l_54d;
	case 1363ULL: goto x86_l_553;
	case 1367ULL: goto x86_l_557;
	case 1370ULL: goto x86_l_55a;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1379ULL: goto x86_l_563;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1386ULL: goto x86_l_56a;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1402ULL: goto x86_l_57a;
	case 1405ULL: goto x86_l_57d;
	case 1407ULL: goto x86_l_57f;
	case 1411ULL: goto x86_l_583;
	case 1414ULL: goto x86_l_586;
	case 1420ULL: goto x86_l_58c;
	case 1422ULL: goto x86_l_58e;
	case 1425ULL: goto x86_l_591;
	case 1427ULL: goto x86_l_593;
	case 1431ULL: goto x86_l_597;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1446ULL: goto x86_l_5a6;
	case 1450ULL: goto x86_l_5aa;
	case 1453ULL: goto x86_l_5ad;
	case 1459ULL: goto x86_l_5b3;
	case 1464ULL: goto x86_l_5b8;
	case 1467ULL: goto x86_l_5bb;
	case 1469ULL: goto x86_l_5bd;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1483ULL: goto x86_l_5cb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_13:
	/* 0x13: movzx  ebp,BYTE PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 48ULL);
x86_l_17:
	/* 0x17: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a:
	/* 0x1a: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1e:
	/* 0x1e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_23:
	/* 0x23: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25:
	/* 0x25: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_27:
	/* 0x27: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a:
	/* 0x2a: mov    DWORD PTR [rsp+0x24],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_32:
	/* 0x32: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_39:
	/* 0x39: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e:
	/* 0x3e: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_44:
	/* 0x44: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_47:
	/* 0x47: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: jne    7d <tail_policy_denied_ipv6+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7d;
	}
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_58:
	/* 0x58: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_5f:
	/* 0x5f: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_64:
	/* 0x64: lea    r14,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69:
	/* 0x69: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6e:
	/* 0x6e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_71:
	/* 0x71: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73:
	/* 0x73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75:
	/* 0x75: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_77:
	/* 0x77: js     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272;
	}
x86_l_7d:
	/* 0x7d: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_84:
	/* 0x84: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_89:
	/* 0x89: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_8c:
	/* 0x8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: je     f8 <tail_policy_denied_ipv6+0xf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f8;
	}
x86_l_91:
	/* 0x91: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94:
	/* 0x94: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_97:
	/* 0x97: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9a:
	/* 0x9a: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_a1:
	/* 0xa1: jbe    129 <tail_policy_denied_ipv6+0x129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_129;
	}
x86_l_a7:
	/* 0xa7: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_ae:
	/* 0xae: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_b8:
	/* 0xb8: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c1:
	/* 0xc1: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_c8:
	/* 0xc8: imul   rcx,rcx,0x64 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RCX, X86_WIDTH_64, 100ULL);
x86_l_cc:
	/* 0xcc: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4:
	/* 0xd4: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d7:
	/* 0xd7: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_da:
	/* 0xda: mov    QWORD PTR [rax],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd:
	/* 0xdd: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_e2:
	/* 0xe2: cmp    rcx,0x3e8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 1000ULL);
x86_l_e9:
	/* 0xe9: ja     139 <tail_policy_denied_ipv6+0x139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_139;
	}
x86_l_eb:
	/* 0xeb: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ee:
	/* 0xee: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: jne    139 <tail_policy_denied_ipv6+0x139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_139;
	}
x86_l_f3:
	/* 0xf3: jmp    208 <tail_policy_denied_ipv6+0x208> */
	goto x86_l_208;
x86_l_f8:
	/* 0xf8: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd:
	/* 0xfd: mov    QWORD PTR [rsp+0x18],0x63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215203ULL);
x86_l_106:
	/* 0x106: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_10d:
	/* 0x10d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_112:
	/* 0x112: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_117:
	/* 0x117: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c:
	/* 0x11c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e:
	/* 0x11e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120:
	/* 0x120: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_122:
	/* 0x122: jns    140 <tail_policy_denied_ipv6+0x140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_140;
	}
x86_l_124:
	/* 0x124: jmp    208 <tail_policy_denied_ipv6+0x208> */
	goto x86_l_208;
x86_l_129:
	/* 0x129: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d:
	/* 0x12d: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_130:
	/* 0x130: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_133:
	/* 0x133: je     208 <tail_policy_denied_ipv6+0x208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208;
	}
x86_l_139:
	/* 0x139: dec    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_13c:
	/* 0x13c: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140:
	/* 0x140: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_149:
	/* 0x149: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_152:
	/* 0x152: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_156:
	/* 0x156: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_159:
	/* 0x159: lea    rcx,[r14+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_15d:
	/* 0x15d: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_160:
	/* 0x160: ja     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_272;
	}
x86_l_166:
	/* 0x166: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b:
	/* 0x16b: mov    r15d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 26ULL);
x86_l_171:
	/* 0x171: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_174:
	/* 0x174: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_179:
	/* 0x179: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_17e:
	/* 0x17e: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_181:
	/* 0x181: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_183:
	/* 0x183: js     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272;
	}
x86_l_189:
	/* 0x189: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e:
	/* 0x18e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_191:
	/* 0x191: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193:
	/* 0x193: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_198:
	/* 0x198: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: js     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272;
	}
x86_l_1a3:
	/* 0x1a3: mov    rax,QWORD PTR [r14+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac:
	/* 0x1ac: mov    rax,QWORD PTR [r14+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b5:
	/* 0x1b5: mov    rax,QWORD PTR [r14+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1be:
	/* 0x1be: mov    r13,QWORD PTR [r14+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1c2:
	/* 0x1c2: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c5:
	/* 0x1c5: cmp    r14d,0x4d0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1232ULL);
x86_l_1cc:
	/* 0x1cc: mov    r15d,0x4d0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1232ULL);
x86_l_1d2:
	/* 0x1d2: cmovb  r15d,r14d */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R14, X86_WIDTH_32, X86_CC_B);
x86_l_1d6:
	/* 0x1d6: lea    esi,[r15+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1da:
	/* 0x1da: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd:
	/* 0x1dd: mov    eax,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 38ULL);
x86_l_1e2:
	/* 0x1e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e7:
	/* 0x1e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9:
	/* 0x1e9: mov    ecx,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1ec:
	/* 0x1ec: mov    edx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ef:
	/* 0x1ef: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f3:
	/* 0x1f3: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: jbe    20d <tail_policy_denied_ipv6+0x20d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20d;
	}
x86_l_1f8:
	/* 0x1f8: lea    rax,[rcx+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1fc:
	/* 0x1fc: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: ja     245 <tail_policy_denied_ipv6+0x245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_245;
	}
x86_l_201:
	/* 0x201: movzx  r12d,BYTE PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_206:
	/* 0x206: jmp    245 <tail_policy_denied_ipv6+0x245> */
	goto x86_l_245;
x86_l_208:
	/* 0x208: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20b:
	/* 0x20b: jmp    272 <tail_policy_denied_ipv6+0x272> */
	goto x86_l_272;
x86_l_20d:
	/* 0x20d: movzx  r12d,WORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_212:
	/* 0x212: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_216:
	/* 0x216: jb     245 <tail_policy_denied_ipv6+0x245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_245;
	}
x86_l_218:
	/* 0x218: lea    rsi,[rcx+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_21c:
	/* 0x21c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: jbe    232 <tail_policy_denied_ipv6+0x232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_232;
	}
x86_l_221:
	/* 0x221: add    rcx,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 17ULL);
x86_l_225:
	/* 0x225: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_228:
	/* 0x228: ja     245 <tail_policy_denied_ipv6+0x245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_245;
	}
x86_l_22a:
	/* 0x22a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22d:
	/* 0x22d: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_230:
	/* 0x230: jmp    245 <tail_policy_denied_ipv6+0x245> */
	goto x86_l_245;
x86_l_232:
	/* 0x232: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_235:
	/* 0x235: add    eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_238:
	/* 0x238: cmp    r14d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 4ULL);
x86_l_23c:
	/* 0x23c: jae    4d5 <tail_policy_denied_ipv6+0x4d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4d5;
	}
x86_l_242:
	/* 0x242: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_245:
	/* 0x245: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_24a:
	/* 0x24a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_252:
	/* 0x252: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_257:
	/* 0x257: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_259:
	/* 0x259: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b:
	/* 0x25b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25d:
	/* 0x25d: js     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272;
	}
x86_l_25f:
	/* 0x25f: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_262:
	/* 0x262: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_265:
	/* 0x265: lea    rdx,[rax+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_269:
	/* 0x269: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_26c:
	/* 0x26c: jbe    323 <tail_policy_denied_ipv6+0x323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_323;
	}
x86_l_272:
	/* 0x272: mov    rax,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_279:
	/* 0x279: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27e:
	/* 0x27e: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_285:
	/* 0x285: mov    DWORD PTR [rbx+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_288:
	/* 0x288: movabs rax,0xac0020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 774621343520915456ULL);
x86_l_292:
	/* 0x292: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_296:
	/* 0x296: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299:
	/* 0x299: movabs rax,0x20aba0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8769896960ULL);
x86_l_2a3:
	/* 0x2a3: add    rax,0x60000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 393216ULL);
x86_l_2a9:
	/* 0x2a9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae:
	/* 0x2ae: mov    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3:
	/* 0x2b3: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2ba:
	/* 0x2ba: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bf:
	/* 0x2bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c4:
	/* 0x2c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6:
	/* 0x2c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c9:
	/* 0x2c9: je     2d4 <tail_policy_denied_ipv6+0x2d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d4;
	}
x86_l_2cb:
	/* 0x2cb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2ce:
	/* 0x2ce: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2d2:
	/* 0x2d2: jmp    2fc <tail_policy_denied_ipv6+0x2fc> */
	goto x86_l_2fc;
x86_l_2d4:
	/* 0x2d4: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e2:
	/* 0x2e2: mov    rdi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2e9:
	/* 0x2e9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ee:
	/* 0x2ee: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f3:
	/* 0x2f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f8:
	/* 0x2f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fa:
	/* 0x2fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc:
	/* 0x2fc: mov    rsi,QWORD PTR [rip+0x28ae7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_303:
	/* 0x303: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_308:
	/* 0x308: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_30b:
	/* 0x30b: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_310:
	/* 0x310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312:
	/* 0x312: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_317:
	/* 0x317: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_31b:
	/* 0x31b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_31d:
	/* 0x31d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_31e:
	/* 0x31e: jmp    4233 <tail_policy_denied_ipv6+0x4233> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_323:
	/* 0x323: movzx  ecx,WORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_328:
	/* 0x328: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32c:
	/* 0x32c: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330:
	/* 0x330: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_332:
	/* 0x332: movzx  ecx,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_337:
	/* 0x337: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_33b:
	/* 0x33b: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33f:
	/* 0x33f: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_342:
	/* 0x342: mov    WORD PTR [rax+0xc],0xdd86 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539664262ULL);
x86_l_348:
	/* 0x348: mov    DWORD PTR [rax+0xe],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60129542240ULL);
x86_l_34f:
	/* 0x34f: add    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_353:
	/* 0x353: movbe  WORD PTR [rax+0x12],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_35a:
	/* 0x35a: mov    WORD PTR [rax+0x14],0x403a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899362362ULL);
x86_l_360:
	/* 0x360: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_365:
	/* 0x365: mov    QWORD PTR [rax+0x2e],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_369:
	/* 0x369: mov    r8,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36e:
	/* 0x36e: mov    QWORD PTR [rax+0x26],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_372:
	/* 0x372: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_377:
	/* 0x377: mov    QWORD PTR [rax+0x1e],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_37b:
	/* 0x37b: mov    QWORD PTR [rax+0x16],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_37f:
	/* 0x37f: mov    WORD PTR [rax+0x36],0x101 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928234241ULL);
x86_l_385:
	/* 0x385: mov    DWORD PTR [rax+0x3a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 249108103168ULL);
x86_l_38c:
	/* 0x38c: movzx  ecx,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_390:
	/* 0x390: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_393:
	/* 0x393: bswap  r15d */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_R15, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_396:
	/* 0x396: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_399:
	/* 0x399: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_39c:
	/* 0x39c: add    ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_39f:
	/* 0x39f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3a6:
	/* 0x3a6: movzx  edx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3a9:
	/* 0x3a9: shr    r13,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_3ad:
	/* 0x3ad: add    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b0:
	/* 0x3b0: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b3:
	/* 0x3b3: movzx  ecx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3b6:
	/* 0x3b6: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_3b8:
	/* 0x3b8: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3bb:
	/* 0x3bb: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3bd:
	/* 0x3bd: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_3c0:
	/* 0x3c0: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3c4:
	/* 0x3c4: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3c7:
	/* 0x3c7: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c9:
	/* 0x3c9: shr    rsi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_3cd:
	/* 0x3cd: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3cf:
	/* 0x3cf: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d2:
	/* 0x3d2: movzx  ecx,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3d6:
	/* 0x3d6: mov    edx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_3d9:
	/* 0x3d9: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3dc:
	/* 0x3dc: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3de:
	/* 0x3de: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_3e1:
	/* 0x3e1: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_3e5:
	/* 0x3e5: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3e8:
	/* 0x3e8: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ea:
	/* 0x3ea: shr    r8,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_3ee:
	/* 0x3ee: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f1:
	/* 0x3f1: movzx  ecx,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3f4:
	/* 0x3f4: add    ecx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f7:
	/* 0x3f7: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f9:
	/* 0x3f9: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_3fb:
	/* 0x3fb: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3fe:
	/* 0x3fe: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_401:
	/* 0x401: shr    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_405:
	/* 0x405: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_408:
	/* 0x408: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40a:
	/* 0x40a: shr    rdi,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_40e:
	/* 0x40e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_410:
	/* 0x410: add    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_412:
	/* 0x412: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_416:
	/* 0x416: lea    ecx,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_41a:
	/* 0x41a: add    ecx,0x3b01 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 15105ULL);
x86_l_420:
	/* 0x420: movzx  edx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_423:
	/* 0x423: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_426:
	/* 0x426: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_428:
	/* 0x428: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_42a:
	/* 0x42a: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_42d:
	/* 0x42d: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_42f:
	/* 0x42f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_431:
	/* 0x431: mov    WORD PTR [rax+0x38],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_435:
	/* 0x435: mov    rax,QWORD PTR [rip+0x28aea] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_43c:
	/* 0x43c: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43f:
	/* 0x43f: mov    rax,QWORD PTR [rip+0x28aea] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_446:
	/* 0x446: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448:
	/* 0x448: mov    edi,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_44b:
	/* 0x44b: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_450:
	/* 0x450: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_452:
	/* 0x452: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454:
	/* 0x454: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_456:
	/* 0x456: js     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_272;
	}
x86_l_45c:
	/* 0x45c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_45f:
	/* 0x45f: je     272 <tail_policy_denied_ipv6+0x272> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272;
	}
x86_l_465:
	/* 0x465: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_468:
	/* 0x468: mov    ebx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a:
	/* 0x46a: movabs rax,0x20aba0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8769896960ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_479:
	/* 0x479: mov    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47e:
	/* 0x47e: mov    rdi,QWORD PTR [rip+0x28aea] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_485:
	/* 0x485: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48a:
	/* 0x48a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48f:
	/* 0x48f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491:
	/* 0x491: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: je     4a5 <tail_policy_denied_ipv6+0x4a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a5;
	}
x86_l_496:
	/* 0x496: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_499:
	/* 0x499: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_49d:
	/* 0x49d: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_4a0:
	/* 0x4a0: jmp    317 <tail_policy_denied_ipv6+0x317> */
	goto x86_l_317;
x86_l_4a5:
	/* 0x4a5: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_4ae:
	/* 0x4ae: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b3:
	/* 0x4b3: mov    rdi,QWORD PTR [rip+0x28aea] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4ba:
	/* 0x4ba: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bf:
	/* 0x4bf: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c4:
	/* 0x4c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4c9:
	/* 0x4c9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cb:
	/* 0x4cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd:
	/* 0x4cd: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_4d0:
	/* 0x4d0: jmp    317 <tail_policy_denied_ipv6+0x317> */
	goto x86_l_317;
x86_l_4d5:
	/* 0x4d5: lea    rdi,[rcx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4d9:
	/* 0x4d9: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4dc:
	/* 0x4dc: jbe    4ef <tail_policy_denied_ipv6+0x4ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4ef;
	}
x86_l_4de:
	/* 0x4de: add    rcx,0x13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 19ULL);
x86_l_4e2:
	/* 0x4e2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4e5:
	/* 0x4e5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_536;
	}
x86_l_4e7:
	/* 0x4e7: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_4ea:
	/* 0x4ea: jmp    245 <tail_policy_denied_ipv6+0x245> */
	goto x86_l_245;
x86_l_4ef:
	/* 0x4ef: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f2:
	/* 0x4f2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4f4:
	/* 0x4f4: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_4f8:
	/* 0x4f8: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_4fe:
	/* 0x4fe: lea    rsi,[rcx+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_502:
	/* 0x502: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_505:
	/* 0x505: jbe    515 <tail_policy_denied_ipv6+0x515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_515;
	}
x86_l_507:
	/* 0x507: add    rcx,0x15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 21ULL);
x86_l_50b:
	/* 0x50b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_50e:
	/* 0x50e: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e7;
	}
x86_l_510:
	/* 0x510: movzx  ecx,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_513:
	/* 0x513: jmp    539 <tail_policy_denied_ipv6+0x539> */
	goto x86_l_539;
x86_l_515:
	/* 0x515: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_518:
	/* 0x518: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_51a:
	/* 0x51a: cmp    r14d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 8ULL);
x86_l_51e:
	/* 0x51e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_524:
	/* 0x524: lea    rdi,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_528:
	/* 0x528: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_52b:
	/* 0x52b: jbe    544 <tail_policy_denied_ipv6+0x544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_544;
	}
x86_l_52d:
	/* 0x52d: add    rcx,0x17 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 23ULL);
x86_l_531:
	/* 0x531: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_534:
	/* 0x534: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e7;
	}
x86_l_536:
	/* 0x536: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_539:
	/* 0x539: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_53c:
	/* 0x53c: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_53f:
	/* 0x53f: jmp    245 <tail_policy_denied_ipv6+0x245> */
	goto x86_l_245;
x86_l_544:
	/* 0x544: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_547:
	/* 0x547: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_549:
	/* 0x549: cmp    r14d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 10ULL);
x86_l_54d:
	/* 0x54d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_553:
	/* 0x553: lea    rsi,[rcx+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_557:
	/* 0x557: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_55a:
	/* 0x55a: jbe    567 <tail_policy_denied_ipv6+0x567> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_567;
	}
x86_l_55c:
	/* 0x55c: add    rcx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 25ULL);
x86_l_560:
	/* 0x560: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_563:
	/* 0x563: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e7;
	}
x86_l_565:
	/* 0x565: jmp    510 <tail_policy_denied_ipv6+0x510> */
	goto x86_l_510;
x86_l_567:
	/* 0x567: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56a:
	/* 0x56a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_56c:
	/* 0x56c: cmp    r14d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 12ULL);
x86_l_570:
	/* 0x570: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_576:
	/* 0x576: lea    rdi,[rcx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_57a:
	/* 0x57a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_57d:
	/* 0x57d: jbe    58e <tail_policy_denied_ipv6+0x58e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_58e;
	}
x86_l_57f:
	/* 0x57f: add    rcx,0x1b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 27ULL);
x86_l_583:
	/* 0x583: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_586:
	/* 0x586: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e7;
	}
x86_l_58c:
	/* 0x58c: jmp    536 <tail_policy_denied_ipv6+0x536> */
	goto x86_l_536;
x86_l_58e:
	/* 0x58e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_591:
	/* 0x591: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_593:
	/* 0x593: cmp    r14d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 14ULL);
x86_l_597:
	/* 0x597: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_59d:
	/* 0x59d: lea    rsi,[rcx+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_5a1:
	/* 0x5a1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_5a4:
	/* 0x5a4: jbe    5b8 <tail_policy_denied_ipv6+0x5b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5b8;
	}
x86_l_5a6:
	/* 0x5a6: add    rcx,0x1d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 29ULL);
x86_l_5aa:
	/* 0x5aa: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5ad:
	/* 0x5ad: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e7;
	}
x86_l_5b3:
	/* 0x5b3: jmp    510 <tail_policy_denied_ipv6+0x510> */
	goto x86_l_510;
x86_l_5b8:
	/* 0x5b8: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5bb:
	/* 0x5bb: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5bd:
	/* 0x5bd: cmp    r14d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 16ULL);
x86_l_5c1:
	/* 0x5c1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_242;
	}
x86_l_5c7:
	/* 0x5c7: lea    rdi,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cb:
	/* 0x5cb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
	return 1486ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1506ULL: goto x86_l_5e2;
	case 1509ULL: goto x86_l_5e5;
	case 1511ULL: goto x86_l_5e7;
	case 1515ULL: goto x86_l_5eb;
	case 1521ULL: goto x86_l_5f1;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1530ULL: goto x86_l_5fa;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1553ULL: goto x86_l_611;
	case 1557ULL: goto x86_l_615;
	case 1563ULL: goto x86_l_61b;
	case 1567ULL: goto x86_l_61f;
	case 1570ULL: goto x86_l_622;
	case 1572ULL: goto x86_l_624;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1585ULL: goto x86_l_631;
	case 1590ULL: goto x86_l_636;
	case 1593ULL: goto x86_l_639;
	case 1595ULL: goto x86_l_63b;
	case 1599ULL: goto x86_l_63f;
	case 1605ULL: goto x86_l_645;
	case 1609ULL: goto x86_l_649;
	case 1612ULL: goto x86_l_64c;
	case 1614ULL: goto x86_l_64e;
	case 1618ULL: goto x86_l_652;
	case 1621ULL: goto x86_l_655;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1635ULL: goto x86_l_663;
	case 1637ULL: goto x86_l_665;
	case 1641ULL: goto x86_l_669;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1654ULL: goto x86_l_676;
	case 1656ULL: goto x86_l_678;
	case 1660ULL: goto x86_l_67c;
	case 1663ULL: goto x86_l_67f;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1677ULL: goto x86_l_68d;
	case 1679ULL: goto x86_l_68f;
	case 1683ULL: goto x86_l_693;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1711ULL: goto x86_l_6af;
	case 1716ULL: goto x86_l_6b4;
	case 1719ULL: goto x86_l_6b7;
	case 1721ULL: goto x86_l_6b9;
	case 1725ULL: goto x86_l_6bd;
	case 1731ULL: goto x86_l_6c3;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1761ULL: goto x86_l_6e1;
	case 1763ULL: goto x86_l_6e3;
	case 1767ULL: goto x86_l_6e7;
	case 1773ULL: goto x86_l_6ed;
	case 1777ULL: goto x86_l_6f1;
	case 1780ULL: goto x86_l_6f4;
	case 1782ULL: goto x86_l_6f6;
	case 1786ULL: goto x86_l_6fa;
	case 1789ULL: goto x86_l_6fd;
	case 1795ULL: goto x86_l_703;
	case 1800ULL: goto x86_l_708;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1809ULL: goto x86_l_711;
	case 1815ULL: goto x86_l_717;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1824ULL: goto x86_l_720;
	case 1828ULL: goto x86_l_724;
	case 1831ULL: goto x86_l_727;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1857ULL: goto x86_l_741;
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1873ULL: goto x86_l_751;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1887ULL: goto x86_l_75f;
	case 1889ULL: goto x86_l_761;
	case 1893ULL: goto x86_l_765;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1908ULL: goto x86_l_774;
	case 1912ULL: goto x86_l_778;
	case 1915ULL: goto x86_l_77b;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1929ULL: goto x86_l_789;
	case 1931ULL: goto x86_l_78b;
	case 1935ULL: goto x86_l_78f;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1963ULL: goto x86_l_7ab;
	case 1968ULL: goto x86_l_7b0;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1977ULL: goto x86_l_7b9;
	case 1983ULL: goto x86_l_7bf;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 1999ULL: goto x86_l_7cf;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2013ULL: goto x86_l_7dd;
	case 2015ULL: goto x86_l_7df;
	case 2019ULL: goto x86_l_7e3;
	case 2025ULL: goto x86_l_7e9;
	case 2029ULL: goto x86_l_7ed;
	case 2032ULL: goto x86_l_7f0;
	case 2034ULL: goto x86_l_7f2;
	case 2038ULL: goto x86_l_7f6;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2057ULL: goto x86_l_809;
	case 2061ULL: goto x86_l_80d;
	case 2067ULL: goto x86_l_813;
	case 2071ULL: goto x86_l_817;
	case 2074ULL: goto x86_l_81a;
	case 2076ULL: goto x86_l_81c;
	case 2080ULL: goto x86_l_820;
	case 2083ULL: goto x86_l_823;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2103ULL: goto x86_l_837;
	case 2109ULL: goto x86_l_83d;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2118ULL: goto x86_l_846;
	case 2122ULL: goto x86_l_84a;
	case 2125ULL: goto x86_l_84d;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2139ULL: goto x86_l_85b;
	case 2141ULL: goto x86_l_85d;
	case 2145ULL: goto x86_l_861;
	case 2151ULL: goto x86_l_867;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2160ULL: goto x86_l_870;
	case 2164ULL: goto x86_l_874;
	case 2167ULL: goto x86_l_877;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2193ULL: goto x86_l_891;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2229ULL: goto x86_l_8b5;
	case 2235ULL: goto x86_l_8bb;
	case 2239ULL: goto x86_l_8bf;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2248ULL: goto x86_l_8c8;
	case 2251ULL: goto x86_l_8cb;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2265ULL: goto x86_l_8d9;
	case 2267ULL: goto x86_l_8db;
	case 2271ULL: goto x86_l_8df;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2284ULL: goto x86_l_8ec;
	case 2286ULL: goto x86_l_8ee;
	case 2290ULL: goto x86_l_8f2;
	case 2293ULL: goto x86_l_8f5;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2328ULL: goto x86_l_918;
	case 2332ULL: goto x86_l_91c;
	case 2335ULL: goto x86_l_91f;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2349ULL: goto x86_l_92d;
	case 2351ULL: goto x86_l_92f;
	case 2355ULL: goto x86_l_933;
	case 2361ULL: goto x86_l_939;
	case 2365ULL: goto x86_l_93d;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2374ULL: goto x86_l_946;
	case 2377ULL: goto x86_l_949;
	case 2383ULL: goto x86_l_94f;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2393ULL: goto x86_l_959;
	case 2397ULL: goto x86_l_95d;
	case 2403ULL: goto x86_l_963;
	case 2407ULL: goto x86_l_967;
	case 2410ULL: goto x86_l_96a;
	case 2412ULL: goto x86_l_96c;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2433ULL: goto x86_l_981;
	case 2435ULL: goto x86_l_983;
	case 2439ULL: goto x86_l_987;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2496ULL: goto x86_l_9c0;
	case 2500ULL: goto x86_l_9c4;
	case 2503ULL: goto x86_l_9c7;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2517ULL: goto x86_l_9d5;
	case 2519ULL: goto x86_l_9d7;
	case 2523ULL: goto x86_l_9db;
	case 2529ULL: goto x86_l_9e1;
	case 2533ULL: goto x86_l_9e5;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2545ULL: goto x86_l_9f1;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2559ULL: goto x86_l_9ff;
	case 2561ULL: goto x86_l_a01;
	case 2565ULL: goto x86_l_a05;
	case 2571ULL: goto x86_l_a0b;
	case 2575ULL: goto x86_l_a0f;
	case 2578ULL: goto x86_l_a12;
	case 2580ULL: goto x86_l_a14;
	case 2584ULL: goto x86_l_a18;
	case 2587ULL: goto x86_l_a1b;
	case 2593ULL: goto x86_l_a21;
	case 2598ULL: goto x86_l_a26;
	case 2601ULL: goto x86_l_a29;
	case 2603ULL: goto x86_l_a2b;
	case 2607ULL: goto x86_l_a2f;
	case 2613ULL: goto x86_l_a35;
	case 2617ULL: goto x86_l_a39;
	case 2620ULL: goto x86_l_a3c;
	case 2622ULL: goto x86_l_a3e;
	case 2626ULL: goto x86_l_a42;
	case 2629ULL: goto x86_l_a45;
	case 2635ULL: goto x86_l_a4b;
	case 2640ULL: goto x86_l_a50;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2649ULL: goto x86_l_a59;
	case 2655ULL: goto x86_l_a5f;
	case 2659ULL: goto x86_l_a63;
	case 2662ULL: goto x86_l_a66;
	case 2664ULL: goto x86_l_a68;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2685ULL: goto x86_l_a7d;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2697ULL: goto x86_l_a89;
	case 2701ULL: goto x86_l_a8d;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2729ULL: goto x86_l_aa9;
	case 2733ULL: goto x86_l_aad;
	case 2739ULL: goto x86_l_ab3;
	case 2743ULL: goto x86_l_ab7;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2771ULL: goto x86_l_ad3;
	case 2775ULL: goto x86_l_ad7;
	case 2781ULL: goto x86_l_add;
	case 2785ULL: goto x86_l_ae1;
	case 2788ULL: goto x86_l_ae4;
	case 2790ULL: goto x86_l_ae6;
	case 2794ULL: goto x86_l_aea;
	case 2797ULL: goto x86_l_aed;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2813ULL: goto x86_l_afd;
	case 2817ULL: goto x86_l_b01;
	case 2823ULL: goto x86_l_b07;
	case 2827ULL: goto x86_l_b0b;
	case 2830ULL: goto x86_l_b0e;
	case 2832ULL: goto x86_l_b10;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2859ULL: goto x86_l_b2b;
	case 2865ULL: goto x86_l_b31;
	case 2869ULL: goto x86_l_b35;
	case 2872ULL: goto x86_l_b38;
	case 2874ULL: goto x86_l_b3a;
	case 2878ULL: goto x86_l_b3e;
	case 2881ULL: goto x86_l_b41;
	case 2887ULL: goto x86_l_b47;
	case 2892ULL: goto x86_l_b4c;
	case 2895ULL: goto x86_l_b4f;
	case 2897ULL: goto x86_l_b51;
	case 2901ULL: goto x86_l_b55;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2920ULL: goto x86_l_b68;
	case 2923ULL: goto x86_l_b6b;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2937ULL: goto x86_l_b79;
	case 2939ULL: goto x86_l_b7b;
	case 2943ULL: goto x86_l_b7f;
	case 2949ULL: goto x86_l_b85;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5ce:
	/* 0x5ce: jbe    5e2 <tail_policy_denied_ipv6+0x5e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_5e2;
	}
x86_l_5d0:
	/* 0x5d0: add    rcx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 31ULL);
x86_l_5d4:
	/* 0x5d4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_5dd:
	/* 0x5dd: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_5e2:
	/* 0x5e2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5e5:
	/* 0x5e5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5e7:
	/* 0x5e7: cmp    r14d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 18ULL);
x86_l_5eb:
	/* 0x5eb: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_5f1:
	/* 0x5f1: lea    rsi,[rcx+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_5f5:
	/* 0x5f5: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_5f8:
	/* 0x5f8: jbe    60c <tail_policy_denied_ipv6+0x60c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_60c;
	}
x86_l_5fa:
	/* 0x5fa: add    rcx,0x21 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 33ULL);
x86_l_5fe:
	/* 0x5fe: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_601:
	/* 0x601: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_607:
	/* 0x607: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_60c:
	/* 0x60c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_60f:
	/* 0x60f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_611:
	/* 0x611: cmp    r14d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 20ULL);
x86_l_615:
	/* 0x615: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_61b:
	/* 0x61b: lea    rdi,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_61f:
	/* 0x61f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_622:
	/* 0x622: jbe    636 <tail_policy_denied_ipv6+0x636> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_636;
	}
x86_l_624:
	/* 0x624: add    rcx,0x23 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 35ULL);
x86_l_628:
	/* 0x628: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_631:
	/* 0x631: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_636:
	/* 0x636: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_639:
	/* 0x639: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_63b:
	/* 0x63b: cmp    r14d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 22ULL);
x86_l_63f:
	/* 0x63f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_645:
	/* 0x645: lea    rsi,[rcx+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_649:
	/* 0x649: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: jbe    660 <tail_policy_denied_ipv6+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_660;
	}
x86_l_64e:
	/* 0x64e: add    rcx,0x25 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 37ULL);
x86_l_652:
	/* 0x652: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_655:
	/* 0x655: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_65b:
	/* 0x65b: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_660:
	/* 0x660: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_663:
	/* 0x663: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_665:
	/* 0x665: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_669:
	/* 0x669: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_66f:
	/* 0x66f: lea    rdi,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_673:
	/* 0x673: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_676:
	/* 0x676: jbe    68a <tail_policy_denied_ipv6+0x68a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_68a;
	}
x86_l_678:
	/* 0x678: add    rcx,0x27 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_67c:
	/* 0x67c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_685:
	/* 0x685: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_68a:
	/* 0x68a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_68d:
	/* 0x68d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_68f:
	/* 0x68f: cmp    r14d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 26ULL);
x86_l_693:
	/* 0x693: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_699:
	/* 0x699: lea    rsi,[rcx+0x2a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_69d:
	/* 0x69d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_6a0:
	/* 0x6a0: jbe    6b4 <tail_policy_denied_ipv6+0x6b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6b4;
	}
x86_l_6a2:
	/* 0x6a2: add    rcx,0x29 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 41ULL);
x86_l_6a6:
	/* 0x6a6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_6a9:
	/* 0x6a9: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_6af:
	/* 0x6af: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_6b4:
	/* 0x6b4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6b7:
	/* 0x6b7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6b9:
	/* 0x6b9: cmp    r14d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 28ULL);
x86_l_6bd:
	/* 0x6bd: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_6c3:
	/* 0x6c3: lea    rdi,[rcx+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6c7:
	/* 0x6c7: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_6ca:
	/* 0x6ca: jbe    6de <tail_policy_denied_ipv6+0x6de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_6de;
	}
x86_l_6cc:
	/* 0x6cc: add    rcx,0x2b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 43ULL);
x86_l_6d0:
	/* 0x6d0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_6d3:
	/* 0x6d3: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_6d9:
	/* 0x6d9: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_6de:
	/* 0x6de: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6e1:
	/* 0x6e1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6e3:
	/* 0x6e3: cmp    r14d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 30ULL);
x86_l_6e7:
	/* 0x6e7: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_6ed:
	/* 0x6ed: lea    rsi,[rcx+0x2e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_6f1:
	/* 0x6f1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: jbe    708 <tail_policy_denied_ipv6+0x708> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_708;
	}
x86_l_6f6:
	/* 0x6f6: add    rcx,0x2d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 45ULL);
x86_l_6fa:
	/* 0x6fa: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_6fd:
	/* 0x6fd: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_703:
	/* 0x703: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_708:
	/* 0x708: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_70b:
	/* 0x70b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_70d:
	/* 0x70d: cmp    r14d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 32ULL);
x86_l_711:
	/* 0x711: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_717:
	/* 0x717: lea    rdi,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71b:
	/* 0x71b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: jbe    732 <tail_policy_denied_ipv6+0x732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_732;
	}
x86_l_720:
	/* 0x720: add    rcx,0x2f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 47ULL);
x86_l_724:
	/* 0x724: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_727:
	/* 0x727: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_72d:
	/* 0x72d: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_732:
	/* 0x732: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_735:
	/* 0x735: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_737:
	/* 0x737: cmp    r14d,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 34ULL);
x86_l_73b:
	/* 0x73b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_741:
	/* 0x741: lea    rsi,[rcx+0x32] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_745:
	/* 0x745: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_748:
	/* 0x748: jbe    75c <tail_policy_denied_ipv6+0x75c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_75c;
	}
x86_l_74a:
	/* 0x74a: add    rcx,0x31 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 49ULL);
x86_l_74e:
	/* 0x74e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_751:
	/* 0x751: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_757:
	/* 0x757: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_75c:
	/* 0x75c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_75f:
	/* 0x75f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_761:
	/* 0x761: cmp    r14d,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 36ULL);
x86_l_765:
	/* 0x765: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_76b:
	/* 0x76b: lea    rdi,[rcx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_76f:
	/* 0x76f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_772:
	/* 0x772: jbe    786 <tail_policy_denied_ipv6+0x786> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_786;
	}
x86_l_774:
	/* 0x774: add    rcx,0x33 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 51ULL);
x86_l_778:
	/* 0x778: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_781:
	/* 0x781: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_786:
	/* 0x786: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_789:
	/* 0x789: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_78b:
	/* 0x78b: cmp    r14d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 38ULL);
x86_l_78f:
	/* 0x78f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_795:
	/* 0x795: lea    rsi,[rcx+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_799:
	/* 0x799: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_79c:
	/* 0x79c: jbe    7b0 <tail_policy_denied_ipv6+0x7b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_7b0;
	}
x86_l_79e:
	/* 0x79e: add    rcx,0x35 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 53ULL);
x86_l_7a2:
	/* 0x7a2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_7a5:
	/* 0x7a5: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_7ab:
	/* 0x7ab: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_7b0:
	/* 0x7b0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_7b3:
	/* 0x7b3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7b5:
	/* 0x7b5: cmp    r14d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 40ULL);
x86_l_7b9:
	/* 0x7b9: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_7bf:
	/* 0x7bf: lea    rdi,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c3:
	/* 0x7c3: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: jbe    7da <tail_policy_denied_ipv6+0x7da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_7da;
	}
x86_l_7c8:
	/* 0x7c8: add    rcx,0x37 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 55ULL);
x86_l_7cc:
	/* 0x7cc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_7cf:
	/* 0x7cf: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_7d5:
	/* 0x7d5: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_7da:
	/* 0x7da: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_7dd:
	/* 0x7dd: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7df:
	/* 0x7df: cmp    r14d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 42ULL);
x86_l_7e3:
	/* 0x7e3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_7e9:
	/* 0x7e9: lea    rsi,[rcx+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_7ed:
	/* 0x7ed: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7f0:
	/* 0x7f0: jbe    804 <tail_policy_denied_ipv6+0x804> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_804;
	}
x86_l_7f2:
	/* 0x7f2: add    rcx,0x39 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 57ULL);
x86_l_7f6:
	/* 0x7f6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_7f9:
	/* 0x7f9: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_7ff:
	/* 0x7ff: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_804:
	/* 0x804: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_807:
	/* 0x807: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_809:
	/* 0x809: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_80d:
	/* 0x80d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_813:
	/* 0x813: lea    rdi,[rcx+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_817:
	/* 0x817: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_81a:
	/* 0x81a: jbe    82e <tail_policy_denied_ipv6+0x82e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_82e;
	}
x86_l_81c:
	/* 0x81c: add    rcx,0x3b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 59ULL);
x86_l_820:
	/* 0x820: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_823:
	/* 0x823: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_829:
	/* 0x829: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_82e:
	/* 0x82e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_831:
	/* 0x831: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_833:
	/* 0x833: cmp    r14d,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 46ULL);
x86_l_837:
	/* 0x837: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_83d:
	/* 0x83d: lea    rsi,[rcx+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_841:
	/* 0x841: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_844:
	/* 0x844: jbe    858 <tail_policy_denied_ipv6+0x858> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_858;
	}
x86_l_846:
	/* 0x846: add    rcx,0x3d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 61ULL);
x86_l_84a:
	/* 0x84a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_84d:
	/* 0x84d: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_853:
	/* 0x853: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_858:
	/* 0x858: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_85b:
	/* 0x85b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_85d:
	/* 0x85d: cmp    r14d,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 48ULL);
x86_l_861:
	/* 0x861: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_867:
	/* 0x867: lea    rdi,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_86b:
	/* 0x86b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: jbe    882 <tail_policy_denied_ipv6+0x882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_882;
	}
x86_l_870:
	/* 0x870: add    rcx,0x3f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 63ULL);
x86_l_874:
	/* 0x874: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_877:
	/* 0x877: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_87d:
	/* 0x87d: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_882:
	/* 0x882: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_885:
	/* 0x885: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_887:
	/* 0x887: cmp    r14d,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 50ULL);
x86_l_88b:
	/* 0x88b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_891:
	/* 0x891: lea    rsi,[rcx+0x42] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_895:
	/* 0x895: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_898:
	/* 0x898: jbe    8ac <tail_policy_denied_ipv6+0x8ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_8ac;
	}
x86_l_89a:
	/* 0x89a: add    rcx,0x41 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 65ULL);
x86_l_89e:
	/* 0x89e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_8a1:
	/* 0x8a1: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_8a7:
	/* 0x8a7: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_8ac:
	/* 0x8ac: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8af:
	/* 0x8af: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8b1:
	/* 0x8b1: cmp    r14d,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 52ULL);
x86_l_8b5:
	/* 0x8b5: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_8bb:
	/* 0x8bb: lea    rdi,[rcx+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_8bf:
	/* 0x8bf: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: jbe    8d6 <tail_policy_denied_ipv6+0x8d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_8d6;
	}
x86_l_8c4:
	/* 0x8c4: add    rcx,0x43 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 67ULL);
x86_l_8c8:
	/* 0x8c8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_8cb:
	/* 0x8cb: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_8d1:
	/* 0x8d1: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_8d6:
	/* 0x8d6: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8d9:
	/* 0x8d9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8db:
	/* 0x8db: cmp    r14d,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 54ULL);
x86_l_8df:
	/* 0x8df: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_8e5:
	/* 0x8e5: lea    rsi,[rcx+0x46] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_8e9:
	/* 0x8e9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_8ec:
	/* 0x8ec: jbe    900 <tail_policy_denied_ipv6+0x900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_900;
	}
x86_l_8ee:
	/* 0x8ee: add    rcx,0x45 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 69ULL);
x86_l_8f2:
	/* 0x8f2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_8f5:
	/* 0x8f5: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_8fb:
	/* 0x8fb: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_900:
	/* 0x900: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_903:
	/* 0x903: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_905:
	/* 0x905: cmp    r14d,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 56ULL);
x86_l_909:
	/* 0x909: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_90f:
	/* 0x90f: lea    rdi,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_913:
	/* 0x913: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_916:
	/* 0x916: jbe    92a <tail_policy_denied_ipv6+0x92a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_92a;
	}
x86_l_918:
	/* 0x918: add    rcx,0x47 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 71ULL);
x86_l_91c:
	/* 0x91c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_925:
	/* 0x925: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_92a:
	/* 0x92a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_92d:
	/* 0x92d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_92f:
	/* 0x92f: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_933:
	/* 0x933: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_939:
	/* 0x939: lea    rsi,[rcx+0x4a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_93d:
	/* 0x93d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_940:
	/* 0x940: jbe    954 <tail_policy_denied_ipv6+0x954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_954;
	}
x86_l_942:
	/* 0x942: add    rcx,0x49 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 73ULL);
x86_l_946:
	/* 0x946: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_949:
	/* 0x949: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_94f:
	/* 0x94f: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_954:
	/* 0x954: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_957:
	/* 0x957: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_959:
	/* 0x959: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_95d:
	/* 0x95d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_963:
	/* 0x963: lea    rdi,[rcx+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_967:
	/* 0x967: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_96a:
	/* 0x96a: jbe    97e <tail_policy_denied_ipv6+0x97e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_97e;
	}
x86_l_96c:
	/* 0x96c: add    rcx,0x4b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 75ULL);
x86_l_970:
	/* 0x970: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_973:
	/* 0x973: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_979:
	/* 0x979: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_97e:
	/* 0x97e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_981:
	/* 0x981: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_983:
	/* 0x983: cmp    r14d,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 62ULL);
x86_l_987:
	/* 0x987: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_98d:
	/* 0x98d: lea    rsi,[rcx+0x4e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_991:
	/* 0x991: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_994:
	/* 0x994: jbe    9a8 <tail_policy_denied_ipv6+0x9a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_9a8;
	}
x86_l_996:
	/* 0x996: add    rcx,0x4d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 77ULL);
x86_l_99a:
	/* 0x99a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_99d:
	/* 0x99d: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_9a3:
	/* 0x9a3: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_9a8:
	/* 0x9a8: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9ab:
	/* 0x9ab: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9ad:
	/* 0x9ad: cmp    r14d,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 64ULL);
x86_l_9b1:
	/* 0x9b1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_9b7:
	/* 0x9b7: lea    rdi,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9bb:
	/* 0x9bb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: jbe    9d2 <tail_policy_denied_ipv6+0x9d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_9d2;
	}
x86_l_9c0:
	/* 0x9c0: add    rcx,0x4f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 79ULL);
x86_l_9c4:
	/* 0x9c4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_9c7:
	/* 0x9c7: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_9cd:
	/* 0x9cd: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_9d2:
	/* 0x9d2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9d5:
	/* 0x9d5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9d7:
	/* 0x9d7: cmp    r14d,0x42 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 66ULL);
x86_l_9db:
	/* 0x9db: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_9e1:
	/* 0x9e1: lea    rsi,[rcx+0x52] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_9e5:
	/* 0x9e5: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_9e8:
	/* 0x9e8: jbe    9fc <tail_policy_denied_ipv6+0x9fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_9fc;
	}
x86_l_9ea:
	/* 0x9ea: add    rcx,0x51 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 81ULL);
x86_l_9ee:
	/* 0x9ee: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_9f1:
	/* 0x9f1: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_9f7:
	/* 0x9f7: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_9fc:
	/* 0x9fc: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9ff:
	/* 0x9ff: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a01:
	/* 0xa01: cmp    r14d,0x44 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 68ULL);
x86_l_a05:
	/* 0xa05: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_a0b:
	/* 0xa0b: lea    rdi,[rcx+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_a0f:
	/* 0xa0f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: jbe    a26 <tail_policy_denied_ipv6+0xa26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a26;
	}
x86_l_a14:
	/* 0xa14: add    rcx,0x53 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 83ULL);
x86_l_a18:
	/* 0xa18: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a1b:
	/* 0xa1b: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_a21:
	/* 0xa21: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_a26:
	/* 0xa26: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a29:
	/* 0xa29: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a2b:
	/* 0xa2b: cmp    r14d,0x46 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 70ULL);
x86_l_a2f:
	/* 0xa2f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_a35:
	/* 0xa35: lea    rsi,[rcx+0x56] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_a39:
	/* 0xa39: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a3c:
	/* 0xa3c: jbe    a50 <tail_policy_denied_ipv6+0xa50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a50;
	}
x86_l_a3e:
	/* 0xa3e: add    rcx,0x55 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 85ULL);
x86_l_a42:
	/* 0xa42: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a45:
	/* 0xa45: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_a4b:
	/* 0xa4b: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_a50:
	/* 0xa50: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a53:
	/* 0xa53: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a55:
	/* 0xa55: cmp    r14d,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 72ULL);
x86_l_a59:
	/* 0xa59: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_a5f:
	/* 0xa5f: lea    rdi,[rcx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a63:
	/* 0xa63: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_a66:
	/* 0xa66: jbe    a7a <tail_policy_denied_ipv6+0xa7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a7a;
	}
x86_l_a68:
	/* 0xa68: add    rcx,0x57 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 87ULL);
x86_l_a6c:
	/* 0xa6c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a6f:
	/* 0xa6f: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_a75:
	/* 0xa75: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_a7a:
	/* 0xa7a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a7d:
	/* 0xa7d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a7f:
	/* 0xa7f: cmp    r14d,0x4a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 74ULL);
x86_l_a83:
	/* 0xa83: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_a89:
	/* 0xa89: lea    rsi,[rcx+0x5a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_a8d:
	/* 0xa8d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a90:
	/* 0xa90: jbe    aa4 <tail_policy_denied_ipv6+0xaa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_aa4;
	}
x86_l_a92:
	/* 0xa92: add    rcx,0x59 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 89ULL);
x86_l_a96:
	/* 0xa96: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a99:
	/* 0xa99: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_a9f:
	/* 0xa9f: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_aa4:
	/* 0xaa4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_aa7:
	/* 0xaa7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_aa9:
	/* 0xaa9: cmp    r14d,0x4c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 76ULL);
x86_l_aad:
	/* 0xaad: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_ab3:
	/* 0xab3: lea    rdi,[rcx+0x5c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ab7:
	/* 0xab7: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_aba:
	/* 0xaba: jbe    ace <tail_policy_denied_ipv6+0xace> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ace;
	}
x86_l_abc:
	/* 0xabc: add    rcx,0x5b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 91ULL);
x86_l_ac0:
	/* 0xac0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_ac9:
	/* 0xac9: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_ace:
	/* 0xace: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ad1:
	/* 0xad1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ad3:
	/* 0xad3: cmp    r14d,0x4e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 78ULL);
x86_l_ad7:
	/* 0xad7: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_add:
	/* 0xadd: lea    rsi,[rcx+0x5e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_ae1:
	/* 0xae1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: jbe    af8 <tail_policy_denied_ipv6+0xaf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_af8;
	}
x86_l_ae6:
	/* 0xae6: add    rcx,0x5d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 93ULL);
x86_l_aea:
	/* 0xaea: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_aed:
	/* 0xaed: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_af3:
	/* 0xaf3: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_af8:
	/* 0xaf8: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_afb:
	/* 0xafb: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_afd:
	/* 0xafd: cmp    r14d,0x50 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 80ULL);
x86_l_b01:
	/* 0xb01: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_b07:
	/* 0xb07: lea    rdi,[rcx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b0b:
	/* 0xb0b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_b0e:
	/* 0xb0e: jbe    b22 <tail_policy_denied_ipv6+0xb22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b22;
	}
x86_l_b10:
	/* 0xb10: add    rcx,0x5f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 95ULL);
x86_l_b14:
	/* 0xb14: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_b17:
	/* 0xb17: ja     4e7 <tail_policy_denied_ipv6+0x4e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1255ULL;
	}
x86_l_b1d:
	/* 0xb1d: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_b22:
	/* 0xb22: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b25:
	/* 0xb25: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b27:
	/* 0xb27: cmp    r14d,0x52 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 82ULL);
x86_l_b2b:
	/* 0xb2b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_b31:
	/* 0xb31: lea    rsi,[rcx+0x62] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_b35:
	/* 0xb35: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b38:
	/* 0xb38: jbe    b4c <tail_policy_denied_ipv6+0xb4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b4c;
	}
x86_l_b3a:
	/* 0xb3a: add    rcx,0x61 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 97ULL);
x86_l_b3e:
	/* 0xb3e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_b41:
	/* 0xb41: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_b47:
	/* 0xb47: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_b4c:
	/* 0xb4c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b4f:
	/* 0xb4f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b51:
	/* 0xb51: cmp    r14d,0x54 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 84ULL);
x86_l_b55:
	/* 0xb55: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_b5b:
	/* 0xb5b: lea    rdi,[rcx+0x64] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_b5f:
	/* 0xb5f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_b62:
	/* 0xb62: jbe    b76 <tail_policy_denied_ipv6+0xb76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b76;
	}
x86_l_b64:
	/* 0xb64: add    rcx,0x63 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 99ULL);
x86_l_b68:
	/* 0xb68: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_b6b:
	/* 0xb6b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_b71:
	/* 0xb71: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_b76:
	/* 0xb76: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b79:
	/* 0xb79: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b7b:
	/* 0xb7b: cmp    r14d,0x56 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 86ULL);
x86_l_b7f:
	/* 0xb7f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_b85:
	/* 0xb85: lea    rsi,[rcx+0x66] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
	return 2953ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2965ULL: goto x86_l_b95;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2979ULL: goto x86_l_ba3;
	case 2981ULL: goto x86_l_ba5;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3004ULL: goto x86_l_bbc;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3018ULL: goto x86_l_bca;
	case 3021ULL: goto x86_l_bcd;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3042ULL: goto x86_l_be2;
	case 3046ULL: goto x86_l_be6;
	case 3049ULL: goto x86_l_be9;
	case 3055ULL: goto x86_l_bef;
	case 3060ULL: goto x86_l_bf4;
	case 3063ULL: goto x86_l_bf7;
	case 3065ULL: goto x86_l_bf9;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3079ULL: goto x86_l_c07;
	case 3082ULL: goto x86_l_c0a;
	case 3084ULL: goto x86_l_c0c;
	case 3088ULL: goto x86_l_c10;
	case 3091ULL: goto x86_l_c13;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3105ULL: goto x86_l_c21;
	case 3107ULL: goto x86_l_c23;
	case 3111ULL: goto x86_l_c27;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3126ULL: goto x86_l_c36;
	case 3130ULL: goto x86_l_c3a;
	case 3133ULL: goto x86_l_c3d;
	case 3139ULL: goto x86_l_c43;
	case 3144ULL: goto x86_l_c48;
	case 3147ULL: goto x86_l_c4b;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3159ULL: goto x86_l_c57;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3189ULL: goto x86_l_c75;
	case 3191ULL: goto x86_l_c77;
	case 3195ULL: goto x86_l_c7b;
	case 3201ULL: goto x86_l_c81;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3214ULL: goto x86_l_c8e;
	case 3217ULL: goto x86_l_c91;
	case 3223ULL: goto x86_l_c97;
	case 3228ULL: goto x86_l_c9c;
	case 3231ULL: goto x86_l_c9f;
	case 3233ULL: goto x86_l_ca1;
	case 3237ULL: goto x86_l_ca5;
	case 3243ULL: goto x86_l_cab;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3252ULL: goto x86_l_cb4;
	case 3256ULL: goto x86_l_cb8;
	case 3259ULL: goto x86_l_cbb;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3285ULL: goto x86_l_cd5;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3298ULL: goto x86_l_ce2;
	case 3301ULL: goto x86_l_ce5;
	case 3307ULL: goto x86_l_ceb;
	case 3312ULL: goto x86_l_cf0;
	case 3315ULL: goto x86_l_cf3;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3334ULL: goto x86_l_d06;
	case 3336ULL: goto x86_l_d08;
	case 3340ULL: goto x86_l_d0c;
	case 3343ULL: goto x86_l_d0f;
	case 3349ULL: goto x86_l_d15;
	case 3354ULL: goto x86_l_d1a;
	case 3357ULL: goto x86_l_d1d;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3369ULL: goto x86_l_d29;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3405ULL: goto x86_l_d4d;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3420ULL: goto x86_l_d5c;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3453ULL: goto x86_l_d7d;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3462ULL: goto x86_l_d86;
	case 3466ULL: goto x86_l_d8a;
	case 3469ULL: goto x86_l_d8d;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3485ULL: goto x86_l_d9d;
	case 3489ULL: goto x86_l_da1;
	case 3495ULL: goto x86_l_da7;
	case 3502ULL: goto x86_l_dae;
	case 3505ULL: goto x86_l_db1;
	case 3507ULL: goto x86_l_db3;
	case 3511ULL: goto x86_l_db7;
	case 3514ULL: goto x86_l_dba;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3530ULL: goto x86_l_dca;
	case 3534ULL: goto x86_l_dce;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3576ULL: goto x86_l_df8;
	case 3578ULL: goto x86_l_dfa;
	case 3582ULL: goto x86_l_dfe;
	case 3588ULL: goto x86_l_e04;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3600ULL: goto x86_l_e10;
	case 3607ULL: goto x86_l_e17;
	case 3610ULL: goto x86_l_e1a;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3636ULL: goto x86_l_e34;
	case 3643ULL: goto x86_l_e3b;
	case 3646ULL: goto x86_l_e3e;
	case 3648ULL: goto x86_l_e40;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3684ULL: goto x86_l_e64;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3703ULL: goto x86_l_e77;
	case 3706ULL: goto x86_l_e7a;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3722ULL: goto x86_l_e8a;
	case 3726ULL: goto x86_l_e8e;
	case 3732ULL: goto x86_l_e94;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3760ULL: goto x86_l_eb0;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3770ULL: goto x86_l_eba;
	case 3774ULL: goto x86_l_ebe;
	case 3780ULL: goto x86_l_ec4;
	case 3787ULL: goto x86_l_ecb;
	case 3790ULL: goto x86_l_ece;
	case 3792ULL: goto x86_l_ed0;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3818ULL: goto x86_l_eea;
	case 3822ULL: goto x86_l_eee;
	case 3828ULL: goto x86_l_ef4;
	case 3835ULL: goto x86_l_efb;
	case 3838ULL: goto x86_l_efe;
	case 3840ULL: goto x86_l_f00;
	case 3847ULL: goto x86_l_f07;
	case 3850ULL: goto x86_l_f0a;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3866ULL: goto x86_l_f1a;
	case 3873ULL: goto x86_l_f21;
	case 3879ULL: goto x86_l_f27;
	case 3886ULL: goto x86_l_f2e;
	case 3889ULL: goto x86_l_f31;
	case 3891ULL: goto x86_l_f33;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3907ULL: goto x86_l_f43;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3935ULL: goto x86_l_f5f;
	case 3941ULL: goto x86_l_f65;
	case 3948ULL: goto x86_l_f6c;
	case 3951ULL: goto x86_l_f6f;
	case 3953ULL: goto x86_l_f71;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3986ULL: goto x86_l_f92;
	case 3992ULL: goto x86_l_f98;
	case 3999ULL: goto x86_l_f9f;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4037ULL: goto x86_l_fc5;
	case 4043ULL: goto x86_l_fcb;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4055ULL: goto x86_l_fd7;
	case 4062ULL: goto x86_l_fde;
	case 4065ULL: goto x86_l_fe1;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4079ULL: goto x86_l_fef;
	case 4081ULL: goto x86_l_ff1;
	case 4088ULL: goto x86_l_ff8;
	case 4094ULL: goto x86_l_ffe;
	case 4101ULL: goto x86_l_1005;
	case 4104ULL: goto x86_l_1008;
	case 4106ULL: goto x86_l_100a;
	case 4113ULL: goto x86_l_1011;
	case 4116ULL: goto x86_l_1014;
	case 4122ULL: goto x86_l_101a;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4132ULL: goto x86_l_1024;
	case 4139ULL: goto x86_l_102b;
	case 4145ULL: goto x86_l_1031;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4157ULL: goto x86_l_103d;
	case 4164ULL: goto x86_l_1044;
	case 4167ULL: goto x86_l_1047;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4181ULL: goto x86_l_1055;
	case 4183ULL: goto x86_l_1057;
	case 4190ULL: goto x86_l_105e;
	case 4196ULL: goto x86_l_1064;
	case 4203ULL: goto x86_l_106b;
	case 4206ULL: goto x86_l_106e;
	case 4208ULL: goto x86_l_1070;
	case 4215ULL: goto x86_l_1077;
	case 4218ULL: goto x86_l_107a;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4241ULL: goto x86_l_1091;
	case 4247ULL: goto x86_l_1097;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4259ULL: goto x86_l_10a3;
	case 4266ULL: goto x86_l_10aa;
	case 4269ULL: goto x86_l_10ad;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4292ULL: goto x86_l_10c4;
	case 4298ULL: goto x86_l_10ca;
	case 4305ULL: goto x86_l_10d1;
	case 4308ULL: goto x86_l_10d4;
	case 4310ULL: goto x86_l_10d6;
	case 4317ULL: goto x86_l_10dd;
	case 4320ULL: goto x86_l_10e0;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4336ULL: goto x86_l_10f0;
	case 4343ULL: goto x86_l_10f7;
	case 4349ULL: goto x86_l_10fd;
	case 4356ULL: goto x86_l_1104;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4368ULL: goto x86_l_1110;
	case 4371ULL: goto x86_l_1113;
	case 4377ULL: goto x86_l_1119;
	case 4382ULL: goto x86_l_111e;
	case 4385ULL: goto x86_l_1121;
	case 4387ULL: goto x86_l_1123;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4412ULL: goto x86_l_113c;
	case 4419ULL: goto x86_l_1143;
	case 4422ULL: goto x86_l_1146;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4445ULL: goto x86_l_115d;
	case 4451ULL: goto x86_l_1163;
	case 4458ULL: goto x86_l_116a;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4470ULL: goto x86_l_1176;
	case 4473ULL: goto x86_l_1179;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4496ULL: goto x86_l_1190;
	case 4502ULL: goto x86_l_1196;
	case 4509ULL: goto x86_l_119d;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4540ULL: goto x86_l_11bc;
	case 4547ULL: goto x86_l_11c3;
	case 4553ULL: goto x86_l_11c9;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4572ULL: goto x86_l_11dc;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4591ULL: goto x86_l_11ef;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b89:
	/* 0xb89: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_b8c:
	/* 0xb8c: jbe    ba0 <tail_policy_denied_ipv6+0xba0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ba0;
	}
x86_l_b8e:
	/* 0xb8e: add    rcx,0x65 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 101ULL);
x86_l_b92:
	/* 0xb92: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_b95:
	/* 0xb95: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_b9b:
	/* 0xb9b: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_ba0:
	/* 0xba0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ba3:
	/* 0xba3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ba5:
	/* 0xba5: cmp    r14d,0x58 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 88ULL);
x86_l_ba9:
	/* 0xba9: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_baf:
	/* 0xbaf: lea    rdi,[rcx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bb3:
	/* 0xbb3: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_bb6:
	/* 0xbb6: jbe    bca <tail_policy_denied_ipv6+0xbca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_bca;
	}
x86_l_bb8:
	/* 0xbb8: add    rcx,0x67 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 103ULL);
x86_l_bbc:
	/* 0xbbc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_bbf:
	/* 0xbbf: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_bc5:
	/* 0xbc5: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_bca:
	/* 0xbca: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bcd:
	/* 0xbcd: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bcf:
	/* 0xbcf: cmp    r14d,0x5a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 90ULL);
x86_l_bd3:
	/* 0xbd3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_bd9:
	/* 0xbd9: lea    rsi,[rcx+0x6a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_bdd:
	/* 0xbdd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_be0:
	/* 0xbe0: jbe    bf4 <tail_policy_denied_ipv6+0xbf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_bf4;
	}
x86_l_be2:
	/* 0xbe2: add    rcx,0x69 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 105ULL);
x86_l_be6:
	/* 0xbe6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_be9:
	/* 0xbe9: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_bef:
	/* 0xbef: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_bf4:
	/* 0xbf4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bf7:
	/* 0xbf7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bf9:
	/* 0xbf9: cmp    r14d,0x5c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 92ULL);
x86_l_bfd:
	/* 0xbfd: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_c03:
	/* 0xc03: lea    rdi,[rcx+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_c07:
	/* 0xc07: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_c0a:
	/* 0xc0a: jbe    c1e <tail_policy_denied_ipv6+0xc1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c1e;
	}
x86_l_c0c:
	/* 0xc0c: add    rcx,0x6b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 107ULL);
x86_l_c10:
	/* 0xc10: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c13:
	/* 0xc13: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_c19:
	/* 0xc19: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_c1e:
	/* 0xc1e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c21:
	/* 0xc21: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c23:
	/* 0xc23: cmp    r14d,0x5e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 94ULL);
x86_l_c27:
	/* 0xc27: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_c2d:
	/* 0xc2d: lea    rsi,[rcx+0x6e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 110ULL);
x86_l_c31:
	/* 0xc31: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: jbe    c48 <tail_policy_denied_ipv6+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c48;
	}
x86_l_c36:
	/* 0xc36: add    rcx,0x6d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 109ULL);
x86_l_c3a:
	/* 0xc3a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c3d:
	/* 0xc3d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_c43:
	/* 0xc43: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_c48:
	/* 0xc48: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c4b:
	/* 0xc4b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c4d:
	/* 0xc4d: cmp    r14d,0x60 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 96ULL);
x86_l_c51:
	/* 0xc51: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_c57:
	/* 0xc57: lea    rdi,[rcx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c5b:
	/* 0xc5b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_c5e:
	/* 0xc5e: jbe    c72 <tail_policy_denied_ipv6+0xc72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c72;
	}
x86_l_c60:
	/* 0xc60: add    rcx,0x6f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 111ULL);
x86_l_c64:
	/* 0xc64: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c67:
	/* 0xc67: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_c6d:
	/* 0xc6d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_c72:
	/* 0xc72: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c75:
	/* 0xc75: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c77:
	/* 0xc77: cmp    r14d,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 98ULL);
x86_l_c7b:
	/* 0xc7b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_c81:
	/* 0xc81: lea    rsi,[rcx+0x72] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 114ULL);
x86_l_c85:
	/* 0xc85: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c88:
	/* 0xc88: jbe    c9c <tail_policy_denied_ipv6+0xc9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c9c;
	}
x86_l_c8a:
	/* 0xc8a: add    rcx,0x71 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 113ULL);
x86_l_c8e:
	/* 0xc8e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c91:
	/* 0xc91: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_c97:
	/* 0xc97: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_c9c:
	/* 0xc9c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c9f:
	/* 0xc9f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ca1:
	/* 0xca1: cmp    r14d,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 100ULL);
x86_l_ca5:
	/* 0xca5: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_cab:
	/* 0xcab: lea    rdi,[rcx+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_caf:
	/* 0xcaf: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_cb2:
	/* 0xcb2: jbe    cc6 <tail_policy_denied_ipv6+0xcc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_cc6;
	}
x86_l_cb4:
	/* 0xcb4: add    rcx,0x73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 115ULL);
x86_l_cb8:
	/* 0xcb8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_cbb:
	/* 0xcbb: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_cc1:
	/* 0xcc1: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_cc6:
	/* 0xcc6: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cc9:
	/* 0xcc9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ccb:
	/* 0xccb: cmp    r14d,0x66 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 102ULL);
x86_l_ccf:
	/* 0xccf: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_cd5:
	/* 0xcd5: lea    rsi,[rcx+0x76] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_cd9:
	/* 0xcd9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_cdc:
	/* 0xcdc: jbe    cf0 <tail_policy_denied_ipv6+0xcf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_cf0;
	}
x86_l_cde:
	/* 0xcde: add    rcx,0x75 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 117ULL);
x86_l_ce2:
	/* 0xce2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_ce5:
	/* 0xce5: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_ceb:
	/* 0xceb: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_cf0:
	/* 0xcf0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cf3:
	/* 0xcf3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cf5:
	/* 0xcf5: cmp    r14d,0x68 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 104ULL);
x86_l_cf9:
	/* 0xcf9: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_cff:
	/* 0xcff: lea    rdi,[rcx+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d03:
	/* 0xd03: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_d06:
	/* 0xd06: jbe    d1a <tail_policy_denied_ipv6+0xd1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d1a;
	}
x86_l_d08:
	/* 0xd08: add    rcx,0x77 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 119ULL);
x86_l_d0c:
	/* 0xd0c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d0f:
	/* 0xd0f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_d15:
	/* 0xd15: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_d1a:
	/* 0xd1a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d1d:
	/* 0xd1d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d1f:
	/* 0xd1f: cmp    r14d,0x6a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 106ULL);
x86_l_d23:
	/* 0xd23: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_d29:
	/* 0xd29: lea    rsi,[rcx+0x7a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_d2d:
	/* 0xd2d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_d30:
	/* 0xd30: jbe    d44 <tail_policy_denied_ipv6+0xd44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d44;
	}
x86_l_d32:
	/* 0xd32: add    rcx,0x79 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 121ULL);
x86_l_d36:
	/* 0xd36: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d39:
	/* 0xd39: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_d3f:
	/* 0xd3f: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_d44:
	/* 0xd44: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d47:
	/* 0xd47: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d49:
	/* 0xd49: cmp    r14d,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 108ULL);
x86_l_d4d:
	/* 0xd4d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_d53:
	/* 0xd53: lea    rdi,[rcx+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_d57:
	/* 0xd57: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_d5a:
	/* 0xd5a: jbe    d6e <tail_policy_denied_ipv6+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d6e;
	}
x86_l_d5c:
	/* 0xd5c: add    rcx,0x7b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 123ULL);
x86_l_d60:
	/* 0xd60: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d63:
	/* 0xd63: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_d69:
	/* 0xd69: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_d6e:
	/* 0xd6e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d71:
	/* 0xd71: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d73:
	/* 0xd73: cmp    r14d,0x6e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 110ULL);
x86_l_d77:
	/* 0xd77: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_d7d:
	/* 0xd7d: lea    rsi,[rcx+0x7e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_d81:
	/* 0xd81: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_d84:
	/* 0xd84: jbe    d98 <tail_policy_denied_ipv6+0xd98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d98;
	}
x86_l_d86:
	/* 0xd86: add    rcx,0x7d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 125ULL);
x86_l_d8a:
	/* 0xd8a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_d93:
	/* 0xd93: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_d98:
	/* 0xd98: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d9b:
	/* 0xd9b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d9d:
	/* 0xd9d: cmp    r14d,0x70 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 112ULL);
x86_l_da1:
	/* 0xda1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_da7:
	/* 0xda7: lea    rdi,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dae:
	/* 0xdae: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_db1:
	/* 0xdb1: jbe    dc5 <tail_policy_denied_ipv6+0xdc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_dc5;
	}
x86_l_db3:
	/* 0xdb3: add    rcx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 127ULL);
x86_l_db7:
	/* 0xdb7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_dba:
	/* 0xdba: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_dc0:
	/* 0xdc0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_dc5:
	/* 0xdc5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_dc8:
	/* 0xdc8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dca:
	/* 0xdca: cmp    r14d,0x72 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 114ULL);
x86_l_dce:
	/* 0xdce: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_dd4:
	/* 0xdd4: lea    rsi,[rcx+0x82] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 130ULL);
x86_l_ddb:
	/* 0xddb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: jbe    df5 <tail_policy_denied_ipv6+0xdf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_df5;
	}
x86_l_de0:
	/* 0xde0: add    rcx,0x81 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 129ULL);
x86_l_de7:
	/* 0xde7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_dea:
	/* 0xdea: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_df0:
	/* 0xdf0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_df5:
	/* 0xdf5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_df8:
	/* 0xdf8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dfa:
	/* 0xdfa: cmp    r14d,0x74 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 116ULL);
x86_l_dfe:
	/* 0xdfe: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_e04:
	/* 0xe04: lea    rdi,[rcx+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_e0b:
	/* 0xe0b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: jbe    e25 <tail_policy_denied_ipv6+0xe25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e25;
	}
x86_l_e10:
	/* 0xe10: add    rcx,0x83 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 131ULL);
x86_l_e17:
	/* 0xe17: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_e1a:
	/* 0xe1a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_e20:
	/* 0xe20: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_e25:
	/* 0xe25: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e28:
	/* 0xe28: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e2a:
	/* 0xe2a: cmp    r14d,0x76 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 118ULL);
x86_l_e2e:
	/* 0xe2e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_e34:
	/* 0xe34: lea    rsi,[rcx+0x86] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_e3b:
	/* 0xe3b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e3e:
	/* 0xe3e: jbe    e55 <tail_policy_denied_ipv6+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e55;
	}
x86_l_e40:
	/* 0xe40: add    rcx,0x85 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 133ULL);
x86_l_e47:
	/* 0xe47: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_e4a:
	/* 0xe4a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_e50:
	/* 0xe50: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_e55:
	/* 0xe55: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e58:
	/* 0xe58: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e5a:
	/* 0xe5a: cmp    r14d,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 120ULL);
x86_l_e5e:
	/* 0xe5e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_e64:
	/* 0xe64: lea    rdi,[rcx+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e6b:
	/* 0xe6b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_e6e:
	/* 0xe6e: jbe    e85 <tail_policy_denied_ipv6+0xe85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e85;
	}
x86_l_e70:
	/* 0xe70: add    rcx,0x87 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 135ULL);
x86_l_e77:
	/* 0xe77: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_e7a:
	/* 0xe7a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_e80:
	/* 0xe80: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_e85:
	/* 0xe85: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e88:
	/* 0xe88: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e8a:
	/* 0xe8a: cmp    r14d,0x7a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 122ULL);
x86_l_e8e:
	/* 0xe8e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_e94:
	/* 0xe94: lea    rsi,[rcx+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_e9b:
	/* 0xe9b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e9e:
	/* 0xe9e: jbe    eb5 <tail_policy_denied_ipv6+0xeb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_eb5;
	}
x86_l_ea0:
	/* 0xea0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_ea7:
	/* 0xea7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_eaa:
	/* 0xeaa: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_eb0:
	/* 0xeb0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_eb5:
	/* 0xeb5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_eb8:
	/* 0xeb8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eba:
	/* 0xeba: cmp    r14d,0x7c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 124ULL);
x86_l_ebe:
	/* 0xebe: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_ec4:
	/* 0xec4: lea    rdi,[rcx+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_ecb:
	/* 0xecb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: jbe    ee5 <tail_policy_denied_ipv6+0xee5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ee5;
	}
x86_l_ed0:
	/* 0xed0: add    rcx,0x8b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 139ULL);
x86_l_ed7:
	/* 0xed7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_eda:
	/* 0xeda: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_ee0:
	/* 0xee0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_ee5:
	/* 0xee5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ee8:
	/* 0xee8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eea:
	/* 0xeea: cmp    r14d,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 126ULL);
x86_l_eee:
	/* 0xeee: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_ef4:
	/* 0xef4: lea    rsi,[rcx+0x8e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 142ULL);
x86_l_efb:
	/* 0xefb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_efe:
	/* 0xefe: jbe    f15 <tail_policy_denied_ipv6+0xf15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f15;
	}
x86_l_f00:
	/* 0xf00: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_f07:
	/* 0xf07: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_f0a:
	/* 0xf0a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_f10:
	/* 0xf10: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_f15:
	/* 0xf15: movzx  esi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_f18:
	/* 0xf18: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f1a:
	/* 0xf1a: cmp    r14d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 256ULL);
x86_l_f21:
	/* 0xf21: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_f27:
	/* 0xf27: lea    rsi,[rcx+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_f2e:
	/* 0xf2e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_f31:
	/* 0xf31: jbe    f4f <tail_policy_denied_ipv6+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f4f;
	}
x86_l_f33:
	/* 0xf33: lea    rsi,[rcx+0x10f] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 271ULL);
x86_l_f3a:
	/* 0xf3a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_f3d:
	/* 0xf3d: ja     286d <tail_policy_denied_ipv6+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10349ULL;
	}
x86_l_f43:
	/* 0xf43: movzx  ecx,BYTE PTR [rcx+0x10e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 270ULL);
x86_l_f4a:
	/* 0xf4a: jmp    539 <tail_policy_denied_ipv6+0x539> */
	return 1337ULL;
x86_l_f4f:
	/* 0xf4f: movzx  edi,WORD PTR [rcx+0x10e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 270ULL);
x86_l_f56:
	/* 0xf56: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f58:
	/* 0xf58: cmp    r14d,0x102 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 258ULL);
x86_l_f5f:
	/* 0xf5f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_f65:
	/* 0xf65: lea    rdi,[rcx+0x112] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274ULL);
x86_l_f6c:
	/* 0xf6c: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_f6f:
	/* 0xf6f: jbe    f86 <tail_policy_denied_ipv6+0xf86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f86;
	}
x86_l_f71:
	/* 0xf71: add    rcx,0x111 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 273ULL);
x86_l_f78:
	/* 0xf78: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_f81:
	/* 0xf81: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_f86:
	/* 0xf86: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_f89:
	/* 0xf89: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f8b:
	/* 0xf8b: cmp    r14d,0x104 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 260ULL);
x86_l_f92:
	/* 0xf92: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_f98:
	/* 0xf98: lea    rsi,[rcx+0x114] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 276ULL);
x86_l_f9f:
	/* 0xf9f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_fa2:
	/* 0xfa2: jbe    fb9 <tail_policy_denied_ipv6+0xfb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fb9;
	}
x86_l_fa4:
	/* 0xfa4: add    rcx,0x113 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 275ULL);
x86_l_fab:
	/* 0xfab: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_fb4:
	/* 0xfb4: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_fb9:
	/* 0xfb9: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fbc:
	/* 0xfbc: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fbe:
	/* 0xfbe: cmp    r14d,0x106 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 262ULL);
x86_l_fc5:
	/* 0xfc5: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_fcb:
	/* 0xfcb: lea    rdi,[rcx+0x116] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 278ULL);
x86_l_fd2:
	/* 0xfd2: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: jbe    fec <tail_policy_denied_ipv6+0xfec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fec;
	}
x86_l_fd7:
	/* 0xfd7: add    rcx,0x115 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 277ULL);
x86_l_fde:
	/* 0xfde: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_fe1:
	/* 0xfe1: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_fe7:
	/* 0xfe7: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_fec:
	/* 0xfec: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fef:
	/* 0xfef: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ff1:
	/* 0xff1: cmp    r14d,0x108 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 264ULL);
x86_l_ff8:
	/* 0xff8: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_ffe:
	/* 0xffe: lea    rsi,[rcx+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1005:
	/* 0x1005: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1008:
	/* 0x1008: jbe    101f <tail_policy_denied_ipv6+0x101f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_101f;
	}
x86_l_100a:
	/* 0x100a: add    rcx,0x117 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 279ULL);
x86_l_1011:
	/* 0x1011: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1014:
	/* 0x1014: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_101a:
	/* 0x101a: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_101f:
	/* 0x101f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1022:
	/* 0x1022: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1024:
	/* 0x1024: cmp    r14d,0x10a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 266ULL);
x86_l_102b:
	/* 0x102b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1031:
	/* 0x1031: lea    rdi,[rcx+0x11a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 282ULL);
x86_l_1038:
	/* 0x1038: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_103b:
	/* 0x103b: jbe    1052 <tail_policy_denied_ipv6+0x1052> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1052;
	}
x86_l_103d:
	/* 0x103d: add    rcx,0x119 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 281ULL);
x86_l_1044:
	/* 0x1044: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1047:
	/* 0x1047: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_104d:
	/* 0x104d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1052:
	/* 0x1052: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1055:
	/* 0x1055: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1057:
	/* 0x1057: cmp    r14d,0x10c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 268ULL);
x86_l_105e:
	/* 0x105e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1064:
	/* 0x1064: lea    rsi,[rcx+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_106b:
	/* 0x106b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: jbe    1085 <tail_policy_denied_ipv6+0x1085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1085;
	}
x86_l_1070:
	/* 0x1070: add    rcx,0x11b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 283ULL);
x86_l_1077:
	/* 0x1077: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_107a:
	/* 0x107a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1080:
	/* 0x1080: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1085:
	/* 0x1085: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1088:
	/* 0x1088: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_108a:
	/* 0x108a: cmp    r14d,0x10e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 270ULL);
x86_l_1091:
	/* 0x1091: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1097:
	/* 0x1097: lea    rdi,[rcx+0x11e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 286ULL);
x86_l_109e:
	/* 0x109e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: jbe    10b8 <tail_policy_denied_ipv6+0x10b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_10b8;
	}
x86_l_10a3:
	/* 0x10a3: add    rcx,0x11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 285ULL);
x86_l_10aa:
	/* 0x10aa: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_10ad:
	/* 0x10ad: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_10b3:
	/* 0x10b3: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_10b8:
	/* 0x10b8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10bb:
	/* 0x10bb: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10bd:
	/* 0x10bd: cmp    r14d,0x110 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 272ULL);
x86_l_10c4:
	/* 0x10c4: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_10ca:
	/* 0x10ca: lea    rsi,[rcx+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_10d1:
	/* 0x10d1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_10d4:
	/* 0x10d4: jbe    10eb <tail_policy_denied_ipv6+0x10eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_10eb;
	}
x86_l_10d6:
	/* 0x10d6: add    rcx,0x11f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 287ULL);
x86_l_10dd:
	/* 0x10dd: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_10e0:
	/* 0x10e0: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_10e6:
	/* 0x10e6: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_10eb:
	/* 0x10eb: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10ee:
	/* 0x10ee: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10f0:
	/* 0x10f0: cmp    r14d,0x112 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 274ULL);
x86_l_10f7:
	/* 0x10f7: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_10fd:
	/* 0x10fd: lea    rdi,[rcx+0x122] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 290ULL);
x86_l_1104:
	/* 0x1104: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1107:
	/* 0x1107: jbe    111e <tail_policy_denied_ipv6+0x111e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_111e;
	}
x86_l_1109:
	/* 0x1109: add    rcx,0x121 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 289ULL);
x86_l_1110:
	/* 0x1110: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1119:
	/* 0x1119: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_111e:
	/* 0x111e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1121:
	/* 0x1121: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1123:
	/* 0x1123: cmp    r14d,0x114 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 276ULL);
x86_l_112a:
	/* 0x112a: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1130:
	/* 0x1130: lea    rsi,[rcx+0x124] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292ULL);
x86_l_1137:
	/* 0x1137: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_113a:
	/* 0x113a: jbe    1151 <tail_policy_denied_ipv6+0x1151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1151;
	}
x86_l_113c:
	/* 0x113c: add    rcx,0x123 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 291ULL);
x86_l_1143:
	/* 0x1143: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1146:
	/* 0x1146: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_114c:
	/* 0x114c: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1151:
	/* 0x1151: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1154:
	/* 0x1154: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1156:
	/* 0x1156: cmp    r14d,0x116 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 278ULL);
x86_l_115d:
	/* 0x115d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1163:
	/* 0x1163: lea    rdi,[rcx+0x126] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 294ULL);
x86_l_116a:
	/* 0x116a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_116d:
	/* 0x116d: jbe    1184 <tail_policy_denied_ipv6+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1184;
	}
x86_l_116f:
	/* 0x116f: add    rcx,0x125 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 293ULL);
x86_l_1176:
	/* 0x1176: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1179:
	/* 0x1179: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_117f:
	/* 0x117f: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1184:
	/* 0x1184: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1187:
	/* 0x1187: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1189:
	/* 0x1189: cmp    r14d,0x118 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 280ULL);
x86_l_1190:
	/* 0x1190: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1196:
	/* 0x1196: lea    rsi,[rcx+0x128] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_119d:
	/* 0x119d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: jbe    11b7 <tail_policy_denied_ipv6+0x11b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_11b7;
	}
x86_l_11a2:
	/* 0x11a2: add    rcx,0x127 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 295ULL);
x86_l_11a9:
	/* 0x11a9: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_11ac:
	/* 0x11ac: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_11b2:
	/* 0x11b2: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_11b7:
	/* 0x11b7: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11ba:
	/* 0x11ba: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11bc:
	/* 0x11bc: cmp    r14d,0x11a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 282ULL);
x86_l_11c3:
	/* 0x11c3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_11c9:
	/* 0x11c9: lea    rdi,[rcx+0x12a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 298ULL);
x86_l_11d0:
	/* 0x11d0: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_11d3:
	/* 0x11d3: jbe    11ea <tail_policy_denied_ipv6+0x11ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_11ea;
	}
x86_l_11d5:
	/* 0x11d5: add    rcx,0x129 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 297ULL);
x86_l_11dc:
	/* 0x11dc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_11df:
	/* 0x11df: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_11e5:
	/* 0x11e5: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_11ea:
	/* 0x11ea: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11ed:
	/* 0x11ed: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11ef:
	/* 0x11ef: cmp    r14d,0x11c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 284ULL);
	return 4598ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4598ULL: goto x86_l_11f6;
	case 4604ULL: goto x86_l_11fc;
	case 4611ULL: goto x86_l_1203;
	case 4614ULL: goto x86_l_1206;
	case 4616ULL: goto x86_l_1208;
	case 4623ULL: goto x86_l_120f;
	case 4626ULL: goto x86_l_1212;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4662ULL: goto x86_l_1236;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4693ULL: goto x86_l_1255;
	case 4700ULL: goto x86_l_125c;
	case 4706ULL: goto x86_l_1262;
	case 4713ULL: goto x86_l_1269;
	case 4716ULL: goto x86_l_126c;
	case 4718ULL: goto x86_l_126e;
	case 4725ULL: goto x86_l_1275;
	case 4728ULL: goto x86_l_1278;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4742ULL: goto x86_l_1286;
	case 4744ULL: goto x86_l_1288;
	case 4751ULL: goto x86_l_128f;
	case 4757ULL: goto x86_l_1295;
	case 4764ULL: goto x86_l_129c;
	case 4767ULL: goto x86_l_129f;
	case 4769ULL: goto x86_l_12a1;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4795ULL: goto x86_l_12bb;
	case 4802ULL: goto x86_l_12c2;
	case 4808ULL: goto x86_l_12c8;
	case 4815ULL: goto x86_l_12cf;
	case 4818ULL: goto x86_l_12d2;
	case 4820ULL: goto x86_l_12d4;
	case 4827ULL: goto x86_l_12db;
	case 4830ULL: goto x86_l_12de;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4844ULL: goto x86_l_12ec;
	case 4846ULL: goto x86_l_12ee;
	case 4853ULL: goto x86_l_12f5;
	case 4859ULL: goto x86_l_12fb;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4878ULL: goto x86_l_130e;
	case 4881ULL: goto x86_l_1311;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4904ULL: goto x86_l_1328;
	case 4910ULL: goto x86_l_132e;
	case 4917ULL: goto x86_l_1335;
	case 4920ULL: goto x86_l_1338;
	case 4922ULL: goto x86_l_133a;
	case 4929ULL: goto x86_l_1341;
	case 4932ULL: goto x86_l_1344;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4946ULL: goto x86_l_1352;
	case 4948ULL: goto x86_l_1354;
	case 4955ULL: goto x86_l_135b;
	case 4961ULL: goto x86_l_1361;
	case 4968ULL: goto x86_l_1368;
	case 4971ULL: goto x86_l_136b;
	case 4973ULL: goto x86_l_136d;
	case 4980ULL: goto x86_l_1374;
	case 4983ULL: goto x86_l_1377;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 4997ULL: goto x86_l_1385;
	case 4999ULL: goto x86_l_1387;
	case 5006ULL: goto x86_l_138e;
	case 5012ULL: goto x86_l_1394;
	case 5019ULL: goto x86_l_139b;
	case 5022ULL: goto x86_l_139e;
	case 5024ULL: goto x86_l_13a0;
	case 5031ULL: goto x86_l_13a7;
	case 5034ULL: goto x86_l_13aa;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5057ULL: goto x86_l_13c1;
	case 5063ULL: goto x86_l_13c7;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5091ULL: goto x86_l_13e3;
	case 5096ULL: goto x86_l_13e8;
	case 5099ULL: goto x86_l_13eb;
	case 5101ULL: goto x86_l_13ed;
	case 5108ULL: goto x86_l_13f4;
	case 5114ULL: goto x86_l_13fa;
	case 5121ULL: goto x86_l_1401;
	case 5124ULL: goto x86_l_1404;
	case 5126ULL: goto x86_l_1406;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5150ULL: goto x86_l_141e;
	case 5152ULL: goto x86_l_1420;
	case 5159ULL: goto x86_l_1427;
	case 5165ULL: goto x86_l_142d;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5177ULL: goto x86_l_1439;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5210ULL: goto x86_l_145a;
	case 5216ULL: goto x86_l_1460;
	case 5223ULL: goto x86_l_1467;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5279ULL: goto x86_l_149f;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5295ULL: goto x86_l_14af;
	case 5300ULL: goto x86_l_14b4;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5312ULL: goto x86_l_14c0;
	case 5318ULL: goto x86_l_14c6;
	case 5325ULL: goto x86_l_14cd;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5354ULL: goto x86_l_14ea;
	case 5356ULL: goto x86_l_14ec;
	case 5363ULL: goto x86_l_14f3;
	case 5369ULL: goto x86_l_14f9;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5381ULL: goto x86_l_1505;
	case 5388ULL: goto x86_l_150c;
	case 5391ULL: goto x86_l_150f;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5414ULL: goto x86_l_1526;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5432ULL: goto x86_l_1538;
	case 5439ULL: goto x86_l_153f;
	case 5442ULL: goto x86_l_1542;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5456ULL: goto x86_l_1550;
	case 5458ULL: goto x86_l_1552;
	case 5465ULL: goto x86_l_1559;
	case 5471ULL: goto x86_l_155f;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5490ULL: goto x86_l_1572;
	case 5493ULL: goto x86_l_1575;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5507ULL: goto x86_l_1583;
	case 5509ULL: goto x86_l_1585;
	case 5516ULL: goto x86_l_158c;
	case 5522ULL: goto x86_l_1592;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5534ULL: goto x86_l_159e;
	case 5541ULL: goto x86_l_15a5;
	case 5544ULL: goto x86_l_15a8;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5560ULL: goto x86_l_15b8;
	case 5567ULL: goto x86_l_15bf;
	case 5573ULL: goto x86_l_15c5;
	case 5580ULL: goto x86_l_15cc;
	case 5583ULL: goto x86_l_15cf;
	case 5585ULL: goto x86_l_15d1;
	case 5592ULL: goto x86_l_15d8;
	case 5595ULL: goto x86_l_15db;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5609ULL: goto x86_l_15e9;
	case 5611ULL: goto x86_l_15eb;
	case 5618ULL: goto x86_l_15f2;
	case 5624ULL: goto x86_l_15f8;
	case 5631ULL: goto x86_l_15ff;
	case 5634ULL: goto x86_l_1602;
	case 5636ULL: goto x86_l_1604;
	case 5643ULL: goto x86_l_160b;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5660ULL: goto x86_l_161c;
	case 5662ULL: goto x86_l_161e;
	case 5669ULL: goto x86_l_1625;
	case 5675ULL: goto x86_l_162b;
	case 5682ULL: goto x86_l_1632;
	case 5685ULL: goto x86_l_1635;
	case 5687ULL: goto x86_l_1637;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5713ULL: goto x86_l_1651;
	case 5720ULL: goto x86_l_1658;
	case 5726ULL: goto x86_l_165e;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5738ULL: goto x86_l_166a;
	case 5745ULL: goto x86_l_1671;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5764ULL: goto x86_l_1684;
	case 5771ULL: goto x86_l_168b;
	case 5777ULL: goto x86_l_1691;
	case 5784ULL: goto x86_l_1698;
	case 5787ULL: goto x86_l_169b;
	case 5789ULL: goto x86_l_169d;
	case 5796ULL: goto x86_l_16a4;
	case 5799ULL: goto x86_l_16a7;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5822ULL: goto x86_l_16be;
	case 5828ULL: goto x86_l_16c4;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5840ULL: goto x86_l_16d0;
	case 5847ULL: goto x86_l_16d7;
	case 5850ULL: goto x86_l_16da;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5864ULL: goto x86_l_16e8;
	case 5866ULL: goto x86_l_16ea;
	case 5873ULL: goto x86_l_16f1;
	case 5879ULL: goto x86_l_16f7;
	case 5886ULL: goto x86_l_16fe;
	case 5889ULL: goto x86_l_1701;
	case 5891ULL: goto x86_l_1703;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5915ULL: goto x86_l_171b;
	case 5917ULL: goto x86_l_171d;
	case 5924ULL: goto x86_l_1724;
	case 5930ULL: goto x86_l_172a;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5942ULL: goto x86_l_1736;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5968ULL: goto x86_l_1750;
	case 5975ULL: goto x86_l_1757;
	case 5981ULL: goto x86_l_175d;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 6000ULL: goto x86_l_1770;
	case 6003ULL: goto x86_l_1773;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6019ULL: goto x86_l_1783;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6051ULL: goto x86_l_17a3;
	case 6054ULL: goto x86_l_17a6;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6077ULL: goto x86_l_17bd;
	case 6083ULL: goto x86_l_17c3;
	case 6090ULL: goto x86_l_17ca;
	case 6093ULL: goto x86_l_17cd;
	case 6095ULL: goto x86_l_17cf;
	case 6102ULL: goto x86_l_17d6;
	case 6105ULL: goto x86_l_17d9;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6119ULL: goto x86_l_17e7;
	case 6121ULL: goto x86_l_17e9;
	case 6128ULL: goto x86_l_17f0;
	case 6134ULL: goto x86_l_17f6;
	case 6141ULL: goto x86_l_17fd;
	case 6144ULL: goto x86_l_1800;
	case 6146ULL: goto x86_l_1802;
	case 6153ULL: goto x86_l_1809;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6172ULL: goto x86_l_181c;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6192ULL: goto x86_l_1830;
	case 6195ULL: goto x86_l_1833;
	case 6197ULL: goto x86_l_1835;
	case 6204ULL: goto x86_l_183c;
	case 6207ULL: goto x86_l_183f;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6223ULL: goto x86_l_184f;
	case 6230ULL: goto x86_l_1856;
	case 6236ULL: goto x86_l_185c;
	case 6243ULL: goto x86_l_1863;
	case 6246ULL: goto x86_l_1866;
	case 6248ULL: goto x86_l_1868;
	case 6255ULL: goto x86_l_186f;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6272ULL: goto x86_l_1880;
	case 6274ULL: goto x86_l_1882;
	case 6281ULL: goto x86_l_1889;
	case 6287ULL: goto x86_l_188f;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6306ULL: goto x86_l_18a2;
	case 6309ULL: goto x86_l_18a5;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6323ULL: goto x86_l_18b3;
	case 6325ULL: goto x86_l_18b5;
	case 6332ULL: goto x86_l_18bc;
	case 6338ULL: goto x86_l_18c2;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6357ULL: goto x86_l_18d5;
	case 6360ULL: goto x86_l_18d8;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6374ULL: goto x86_l_18e6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_11f6:
	/* 0x11f6: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_11fc:
	/* 0x11fc: lea    rsi,[rcx+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1203:
	/* 0x1203: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1206:
	/* 0x1206: jbe    121d <tail_policy_denied_ipv6+0x121d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_121d;
	}
x86_l_1208:
	/* 0x1208: add    rcx,0x12b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 299ULL);
x86_l_120f:
	/* 0x120f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1212:
	/* 0x1212: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1218:
	/* 0x1218: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_121d:
	/* 0x121d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1220:
	/* 0x1220: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1222:
	/* 0x1222: cmp    r14d,0x11e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 286ULL);
x86_l_1229:
	/* 0x1229: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_122f:
	/* 0x122f: lea    rdi,[rcx+0x12e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 302ULL);
x86_l_1236:
	/* 0x1236: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1239:
	/* 0x1239: jbe    1250 <tail_policy_denied_ipv6+0x1250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1250;
	}
x86_l_123b:
	/* 0x123b: add    rcx,0x12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 301ULL);
x86_l_1242:
	/* 0x1242: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_124b:
	/* 0x124b: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1250:
	/* 0x1250: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1253:
	/* 0x1253: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1255:
	/* 0x1255: cmp    r14d,0x120 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 288ULL);
x86_l_125c:
	/* 0x125c: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1262:
	/* 0x1262: lea    rsi,[rcx+0x130] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_1269:
	/* 0x1269: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_126c:
	/* 0x126c: jbe    1283 <tail_policy_denied_ipv6+0x1283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1283;
	}
x86_l_126e:
	/* 0x126e: add    rcx,0x12f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 303ULL);
x86_l_1275:
	/* 0x1275: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_127e:
	/* 0x127e: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1283:
	/* 0x1283: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1286:
	/* 0x1286: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1288:
	/* 0x1288: cmp    r14d,0x122 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 290ULL);
x86_l_128f:
	/* 0x128f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1295:
	/* 0x1295: lea    rdi,[rcx+0x132] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 306ULL);
x86_l_129c:
	/* 0x129c: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_129f:
	/* 0x129f: jbe    12b6 <tail_policy_denied_ipv6+0x12b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_12b6;
	}
x86_l_12a1:
	/* 0x12a1: add    rcx,0x131 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 305ULL);
x86_l_12a8:
	/* 0x12a8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_12ab:
	/* 0x12ab: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_12b1:
	/* 0x12b1: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_12b6:
	/* 0x12b6: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12b9:
	/* 0x12b9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12bb:
	/* 0x12bb: cmp    r14d,0x124 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 292ULL);
x86_l_12c2:
	/* 0x12c2: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_12c8:
	/* 0x12c8: lea    rsi,[rcx+0x134] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 308ULL);
x86_l_12cf:
	/* 0x12cf: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_12d2:
	/* 0x12d2: jbe    12e9 <tail_policy_denied_ipv6+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_12e9;
	}
x86_l_12d4:
	/* 0x12d4: add    rcx,0x133 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 307ULL);
x86_l_12db:
	/* 0x12db: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_12de:
	/* 0x12de: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_12e4:
	/* 0x12e4: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_12e9:
	/* 0x12e9: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12ec:
	/* 0x12ec: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12ee:
	/* 0x12ee: cmp    r14d,0x126 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 294ULL);
x86_l_12f5:
	/* 0x12f5: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_12fb:
	/* 0x12fb: lea    rdi,[rcx+0x136] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 310ULL);
x86_l_1302:
	/* 0x1302: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1305:
	/* 0x1305: jbe    131c <tail_policy_denied_ipv6+0x131c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_131c;
	}
x86_l_1307:
	/* 0x1307: add    rcx,0x135 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 309ULL);
x86_l_130e:
	/* 0x130e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1311:
	/* 0x1311: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1317:
	/* 0x1317: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_131c:
	/* 0x131c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_131f:
	/* 0x131f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1321:
	/* 0x1321: cmp    r14d,0x128 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 296ULL);
x86_l_1328:
	/* 0x1328: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_132e:
	/* 0x132e: lea    rsi,[rcx+0x138] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_1335:
	/* 0x1335: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: jbe    134f <tail_policy_denied_ipv6+0x134f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_134f;
	}
x86_l_133a:
	/* 0x133a: add    rcx,0x137 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 311ULL);
x86_l_1341:
	/* 0x1341: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_134a:
	/* 0x134a: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_134f:
	/* 0x134f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1352:
	/* 0x1352: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1354:
	/* 0x1354: cmp    r14d,0x12a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 298ULL);
x86_l_135b:
	/* 0x135b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1361:
	/* 0x1361: lea    rdi,[rcx+0x13a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 314ULL);
x86_l_1368:
	/* 0x1368: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_136b:
	/* 0x136b: jbe    1382 <tail_policy_denied_ipv6+0x1382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1382;
	}
x86_l_136d:
	/* 0x136d: add    rcx,0x139 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 313ULL);
x86_l_1374:
	/* 0x1374: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1377:
	/* 0x1377: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_137d:
	/* 0x137d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1382:
	/* 0x1382: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1385:
	/* 0x1385: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1387:
	/* 0x1387: cmp    r14d,0x12c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 300ULL);
x86_l_138e:
	/* 0x138e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1394:
	/* 0x1394: lea    rsi,[rcx+0x13c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 316ULL);
x86_l_139b:
	/* 0x139b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_139e:
	/* 0x139e: jbe    13b5 <tail_policy_denied_ipv6+0x13b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_13b5;
	}
x86_l_13a0:
	/* 0x13a0: add    rcx,0x13b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 315ULL);
x86_l_13a7:
	/* 0x13a7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_13aa:
	/* 0x13aa: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_13b0:
	/* 0x13b0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_13b5:
	/* 0x13b5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13b8:
	/* 0x13b8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13ba:
	/* 0x13ba: cmp    r14d,0x12e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 302ULL);
x86_l_13c1:
	/* 0x13c1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_13c7:
	/* 0x13c7: lea    rdi,[rcx+0x13e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 318ULL);
x86_l_13ce:
	/* 0x13ce: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_13d1:
	/* 0x13d1: jbe    13e8 <tail_policy_denied_ipv6+0x13e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_13e8;
	}
x86_l_13d3:
	/* 0x13d3: add    rcx,0x13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 317ULL);
x86_l_13da:
	/* 0x13da: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_13dd:
	/* 0x13dd: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_13e3:
	/* 0x13e3: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_13e8:
	/* 0x13e8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13eb:
	/* 0x13eb: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13ed:
	/* 0x13ed: cmp    r14d,0x130 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 304ULL);
x86_l_13f4:
	/* 0x13f4: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_13fa:
	/* 0x13fa: lea    rsi,[rcx+0x140] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1401:
	/* 0x1401: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1404:
	/* 0x1404: jbe    141b <tail_policy_denied_ipv6+0x141b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_141b;
	}
x86_l_1406:
	/* 0x1406: add    rcx,0x13f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 319ULL);
x86_l_140d:
	/* 0x140d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1416:
	/* 0x1416: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_141b:
	/* 0x141b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_141e:
	/* 0x141e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1420:
	/* 0x1420: cmp    r14d,0x132 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 306ULL);
x86_l_1427:
	/* 0x1427: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_142d:
	/* 0x142d: lea    rdi,[rcx+0x142] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 322ULL);
x86_l_1434:
	/* 0x1434: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1437:
	/* 0x1437: jbe    144e <tail_policy_denied_ipv6+0x144e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_144e;
	}
x86_l_1439:
	/* 0x1439: add    rcx,0x141 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 321ULL);
x86_l_1440:
	/* 0x1440: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1443:
	/* 0x1443: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1449:
	/* 0x1449: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_144e:
	/* 0x144e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1451:
	/* 0x1451: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1453:
	/* 0x1453: cmp    r14d,0x134 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 308ULL);
x86_l_145a:
	/* 0x145a: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1460:
	/* 0x1460: lea    rsi,[rcx+0x144] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 324ULL);
x86_l_1467:
	/* 0x1467: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_146a:
	/* 0x146a: jbe    1481 <tail_policy_denied_ipv6+0x1481> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1481;
	}
x86_l_146c:
	/* 0x146c: add    rcx,0x143 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 323ULL);
x86_l_1473:
	/* 0x1473: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_147c:
	/* 0x147c: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1481:
	/* 0x1481: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1484:
	/* 0x1484: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1486:
	/* 0x1486: cmp    r14d,0x136 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 310ULL);
x86_l_148d:
	/* 0x148d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1493:
	/* 0x1493: lea    rdi,[rcx+0x146] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 326ULL);
x86_l_149a:
	/* 0x149a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: jbe    14b4 <tail_policy_denied_ipv6+0x14b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14b4;
	}
x86_l_149f:
	/* 0x149f: add    rcx,0x145 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 325ULL);
x86_l_14a6:
	/* 0x14a6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_14a9:
	/* 0x14a9: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_14af:
	/* 0x14af: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_14b4:
	/* 0x14b4: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14b7:
	/* 0x14b7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14b9:
	/* 0x14b9: cmp    r14d,0x138 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 312ULL);
x86_l_14c0:
	/* 0x14c0: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_14c6:
	/* 0x14c6: lea    rsi,[rcx+0x148] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_14cd:
	/* 0x14cd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_14d0:
	/* 0x14d0: jbe    14e7 <tail_policy_denied_ipv6+0x14e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14e7;
	}
x86_l_14d2:
	/* 0x14d2: add    rcx,0x147 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 327ULL);
x86_l_14d9:
	/* 0x14d9: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_14dc:
	/* 0x14dc: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_14e2:
	/* 0x14e2: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_14e7:
	/* 0x14e7: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14ea:
	/* 0x14ea: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14ec:
	/* 0x14ec: cmp    r14d,0x13a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 314ULL);
x86_l_14f3:
	/* 0x14f3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_14f9:
	/* 0x14f9: lea    rdi,[rcx+0x14a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 330ULL);
x86_l_1500:
	/* 0x1500: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1503:
	/* 0x1503: jbe    151a <tail_policy_denied_ipv6+0x151a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_151a;
	}
x86_l_1505:
	/* 0x1505: add    rcx,0x149 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 329ULL);
x86_l_150c:
	/* 0x150c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_150f:
	/* 0x150f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1515:
	/* 0x1515: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_151a:
	/* 0x151a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_151d:
	/* 0x151d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_151f:
	/* 0x151f: cmp    r14d,0x13c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 316ULL);
x86_l_1526:
	/* 0x1526: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_152c:
	/* 0x152c: lea    rsi,[rcx+0x14c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 332ULL);
x86_l_1533:
	/* 0x1533: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: jbe    154d <tail_policy_denied_ipv6+0x154d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_154d;
	}
x86_l_1538:
	/* 0x1538: add    rcx,0x14b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 331ULL);
x86_l_153f:
	/* 0x153f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1542:
	/* 0x1542: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1548:
	/* 0x1548: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_154d:
	/* 0x154d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1550:
	/* 0x1550: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1552:
	/* 0x1552: cmp    r14d,0x13e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 318ULL);
x86_l_1559:
	/* 0x1559: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_155f:
	/* 0x155f: lea    rdi,[rcx+0x14e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 334ULL);
x86_l_1566:
	/* 0x1566: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1569:
	/* 0x1569: jbe    1580 <tail_policy_denied_ipv6+0x1580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1580;
	}
x86_l_156b:
	/* 0x156b: add    rcx,0x14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 333ULL);
x86_l_1572:
	/* 0x1572: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1575:
	/* 0x1575: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_157b:
	/* 0x157b: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1580:
	/* 0x1580: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1583:
	/* 0x1583: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1585:
	/* 0x1585: cmp    r14d,0x140 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 320ULL);
x86_l_158c:
	/* 0x158c: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1592:
	/* 0x1592: lea    rsi,[rcx+0x150] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_1599:
	/* 0x1599: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_159c:
	/* 0x159c: jbe    15b3 <tail_policy_denied_ipv6+0x15b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_15b3;
	}
x86_l_159e:
	/* 0x159e: add    rcx,0x14f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 335ULL);
x86_l_15a5:
	/* 0x15a5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_15a8:
	/* 0x15a8: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_15ae:
	/* 0x15ae: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_15b3:
	/* 0x15b3: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15b6:
	/* 0x15b6: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15b8:
	/* 0x15b8: cmp    r14d,0x142 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 322ULL);
x86_l_15bf:
	/* 0x15bf: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_15c5:
	/* 0x15c5: lea    rdi,[rcx+0x152] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 338ULL);
x86_l_15cc:
	/* 0x15cc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_15cf:
	/* 0x15cf: jbe    15e6 <tail_policy_denied_ipv6+0x15e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_15e6;
	}
x86_l_15d1:
	/* 0x15d1: add    rcx,0x151 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 337ULL);
x86_l_15d8:
	/* 0x15d8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_15db:
	/* 0x15db: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_15e1:
	/* 0x15e1: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_15e6:
	/* 0x15e6: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15e9:
	/* 0x15e9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15eb:
	/* 0x15eb: cmp    r14d,0x144 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 324ULL);
x86_l_15f2:
	/* 0x15f2: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_15f8:
	/* 0x15f8: lea    rsi,[rcx+0x154] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 340ULL);
x86_l_15ff:
	/* 0x15ff: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1602:
	/* 0x1602: jbe    1619 <tail_policy_denied_ipv6+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1619;
	}
x86_l_1604:
	/* 0x1604: add    rcx,0x153 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 339ULL);
x86_l_160b:
	/* 0x160b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_160e:
	/* 0x160e: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1614:
	/* 0x1614: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1619:
	/* 0x1619: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_161c:
	/* 0x161c: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_161e:
	/* 0x161e: cmp    r14d,0x146 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 326ULL);
x86_l_1625:
	/* 0x1625: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_162b:
	/* 0x162b: lea    rdi,[rcx+0x156] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 342ULL);
x86_l_1632:
	/* 0x1632: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1635:
	/* 0x1635: jbe    164c <tail_policy_denied_ipv6+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_164c;
	}
x86_l_1637:
	/* 0x1637: add    rcx,0x155 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 341ULL);
x86_l_163e:
	/* 0x163e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1641:
	/* 0x1641: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1647:
	/* 0x1647: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_164c:
	/* 0x164c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_164f:
	/* 0x164f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1651:
	/* 0x1651: cmp    r14d,0x148 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 328ULL);
x86_l_1658:
	/* 0x1658: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_165e:
	/* 0x165e: lea    rsi,[rcx+0x158] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_1665:
	/* 0x1665: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1668:
	/* 0x1668: jbe    167f <tail_policy_denied_ipv6+0x167f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_167f;
	}
x86_l_166a:
	/* 0x166a: add    rcx,0x157 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 343ULL);
x86_l_1671:
	/* 0x1671: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1674:
	/* 0x1674: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_167a:
	/* 0x167a: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_167f:
	/* 0x167f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1682:
	/* 0x1682: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1684:
	/* 0x1684: cmp    r14d,0x14a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 330ULL);
x86_l_168b:
	/* 0x168b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1691:
	/* 0x1691: lea    rdi,[rcx+0x15a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 346ULL);
x86_l_1698:
	/* 0x1698: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_169b:
	/* 0x169b: jbe    16b2 <tail_policy_denied_ipv6+0x16b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_16b2;
	}
x86_l_169d:
	/* 0x169d: add    rcx,0x159 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 345ULL);
x86_l_16a4:
	/* 0x16a4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_16a7:
	/* 0x16a7: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_16ad:
	/* 0x16ad: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_16b2:
	/* 0x16b2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16b5:
	/* 0x16b5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16b7:
	/* 0x16b7: cmp    r14d,0x14c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 332ULL);
x86_l_16be:
	/* 0x16be: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_16c4:
	/* 0x16c4: lea    rsi,[rcx+0x15c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 348ULL);
x86_l_16cb:
	/* 0x16cb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_16ce:
	/* 0x16ce: jbe    16e5 <tail_policy_denied_ipv6+0x16e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_16e5;
	}
x86_l_16d0:
	/* 0x16d0: add    rcx,0x15b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 347ULL);
x86_l_16d7:
	/* 0x16d7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_16da:
	/* 0x16da: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_16e0:
	/* 0x16e0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_16e5:
	/* 0x16e5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16e8:
	/* 0x16e8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16ea:
	/* 0x16ea: cmp    r14d,0x14e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 334ULL);
x86_l_16f1:
	/* 0x16f1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_16f7:
	/* 0x16f7: lea    rdi,[rcx+0x15e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 350ULL);
x86_l_16fe:
	/* 0x16fe: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1701:
	/* 0x1701: jbe    1718 <tail_policy_denied_ipv6+0x1718> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1718;
	}
x86_l_1703:
	/* 0x1703: add    rcx,0x15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 349ULL);
x86_l_170a:
	/* 0x170a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_170d:
	/* 0x170d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1713:
	/* 0x1713: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1718:
	/* 0x1718: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_171b:
	/* 0x171b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_171d:
	/* 0x171d: cmp    r14d,0x150 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 336ULL);
x86_l_1724:
	/* 0x1724: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_172a:
	/* 0x172a: lea    rsi,[rcx+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_1731:
	/* 0x1731: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1734:
	/* 0x1734: jbe    174b <tail_policy_denied_ipv6+0x174b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_174b;
	}
x86_l_1736:
	/* 0x1736: add    rcx,0x15f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 351ULL);
x86_l_173d:
	/* 0x173d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1740:
	/* 0x1740: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1746:
	/* 0x1746: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_174b:
	/* 0x174b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_174e:
	/* 0x174e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1750:
	/* 0x1750: cmp    r14d,0x152 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 338ULL);
x86_l_1757:
	/* 0x1757: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_175d:
	/* 0x175d: lea    rdi,[rcx+0x162] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 354ULL);
x86_l_1764:
	/* 0x1764: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1767:
	/* 0x1767: jbe    177e <tail_policy_denied_ipv6+0x177e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_177e;
	}
x86_l_1769:
	/* 0x1769: add    rcx,0x161 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 353ULL);
x86_l_1770:
	/* 0x1770: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1773:
	/* 0x1773: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1779:
	/* 0x1779: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_177e:
	/* 0x177e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1781:
	/* 0x1781: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1783:
	/* 0x1783: cmp    r14d,0x154 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 340ULL);
x86_l_178a:
	/* 0x178a: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1790:
	/* 0x1790: lea    rsi,[rcx+0x164] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 356ULL);
x86_l_1797:
	/* 0x1797: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_179a:
	/* 0x179a: jbe    17b1 <tail_policy_denied_ipv6+0x17b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17b1;
	}
x86_l_179c:
	/* 0x179c: add    rcx,0x163 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 355ULL);
x86_l_17a3:
	/* 0x17a3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_17a6:
	/* 0x17a6: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_17ac:
	/* 0x17ac: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_17b1:
	/* 0x17b1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17b4:
	/* 0x17b4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17b6:
	/* 0x17b6: cmp    r14d,0x156 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 342ULL);
x86_l_17bd:
	/* 0x17bd: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_17c3:
	/* 0x17c3: lea    rdi,[rcx+0x166] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 358ULL);
x86_l_17ca:
	/* 0x17ca: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_17cd:
	/* 0x17cd: jbe    17e4 <tail_policy_denied_ipv6+0x17e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17e4;
	}
x86_l_17cf:
	/* 0x17cf: add    rcx,0x165 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 357ULL);
x86_l_17d6:
	/* 0x17d6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_17d9:
	/* 0x17d9: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_17df:
	/* 0x17df: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_17e4:
	/* 0x17e4: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e7:
	/* 0x17e7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17e9:
	/* 0x17e9: cmp    r14d,0x158 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 344ULL);
x86_l_17f0:
	/* 0x17f0: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_17f6:
	/* 0x17f6: lea    rsi,[rcx+0x168] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_17fd:
	/* 0x17fd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1800:
	/* 0x1800: jbe    1817 <tail_policy_denied_ipv6+0x1817> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1817;
	}
x86_l_1802:
	/* 0x1802: add    rcx,0x167 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 359ULL);
x86_l_1809:
	/* 0x1809: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_180c:
	/* 0x180c: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1812:
	/* 0x1812: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1817:
	/* 0x1817: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_181a:
	/* 0x181a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_181c:
	/* 0x181c: cmp    r14d,0x15a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 346ULL);
x86_l_1823:
	/* 0x1823: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1829:
	/* 0x1829: lea    rdi,[rcx+0x16a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 362ULL);
x86_l_1830:
	/* 0x1830: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1833:
	/* 0x1833: jbe    184a <tail_policy_denied_ipv6+0x184a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_184a;
	}
x86_l_1835:
	/* 0x1835: add    rcx,0x169 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 361ULL);
x86_l_183c:
	/* 0x183c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_183f:
	/* 0x183f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1845:
	/* 0x1845: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_184a:
	/* 0x184a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_184d:
	/* 0x184d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_184f:
	/* 0x184f: cmp    r14d,0x15c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 348ULL);
x86_l_1856:
	/* 0x1856: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_185c:
	/* 0x185c: lea    rsi,[rcx+0x16c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 364ULL);
x86_l_1863:
	/* 0x1863: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1866:
	/* 0x1866: jbe    187d <tail_policy_denied_ipv6+0x187d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_187d;
	}
x86_l_1868:
	/* 0x1868: add    rcx,0x16b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 363ULL);
x86_l_186f:
	/* 0x186f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1872:
	/* 0x1872: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1878:
	/* 0x1878: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_187d:
	/* 0x187d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1880:
	/* 0x1880: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1882:
	/* 0x1882: cmp    r14d,0x15e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 350ULL);
x86_l_1889:
	/* 0x1889: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_188f:
	/* 0x188f: lea    rdi,[rcx+0x16e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 366ULL);
x86_l_1896:
	/* 0x1896: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1899:
	/* 0x1899: jbe    18b0 <tail_policy_denied_ipv6+0x18b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_18b0;
	}
x86_l_189b:
	/* 0x189b: add    rcx,0x16d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 365ULL);
x86_l_18a2:
	/* 0x18a2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_18a5:
	/* 0x18a5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_18ab:
	/* 0x18ab: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_18b0:
	/* 0x18b0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18b3:
	/* 0x18b3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18b5:
	/* 0x18b5: cmp    r14d,0x160 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 352ULL);
x86_l_18bc:
	/* 0x18bc: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_18c2:
	/* 0x18c2: lea    rsi,[rcx+0x170] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_18c9:
	/* 0x18c9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_18cc:
	/* 0x18cc: jbe    18e3 <tail_policy_denied_ipv6+0x18e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_18e3;
	}
x86_l_18ce:
	/* 0x18ce: add    rcx,0x16f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 367ULL);
x86_l_18d5:
	/* 0x18d5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_18d8:
	/* 0x18d8: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_18de:
	/* 0x18de: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_18e3:
	/* 0x18e3: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18e6:
	/* 0x18e6: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
	return 6376ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6376ULL: goto x86_l_18e8;
	case 6383ULL: goto x86_l_18ef;
	case 6389ULL: goto x86_l_18f5;
	case 6396ULL: goto x86_l_18fc;
	case 6399ULL: goto x86_l_18ff;
	case 6401ULL: goto x86_l_1901;
	case 6408ULL: goto x86_l_1908;
	case 6411ULL: goto x86_l_190b;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6425ULL: goto x86_l_1919;
	case 6427ULL: goto x86_l_191b;
	case 6434ULL: goto x86_l_1922;
	case 6440ULL: goto x86_l_1928;
	case 6447ULL: goto x86_l_192f;
	case 6450ULL: goto x86_l_1932;
	case 6452ULL: goto x86_l_1934;
	case 6459ULL: goto x86_l_193b;
	case 6462ULL: goto x86_l_193e;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6478ULL: goto x86_l_194e;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6498ULL: goto x86_l_1962;
	case 6501ULL: goto x86_l_1965;
	case 6503ULL: goto x86_l_1967;
	case 6510ULL: goto x86_l_196e;
	case 6513ULL: goto x86_l_1971;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6536ULL: goto x86_l_1988;
	case 6542ULL: goto x86_l_198e;
	case 6549ULL: goto x86_l_1995;
	case 6552ULL: goto x86_l_1998;
	case 6554ULL: goto x86_l_199a;
	case 6561ULL: goto x86_l_19a1;
	case 6564ULL: goto x86_l_19a4;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6578ULL: goto x86_l_19b2;
	case 6580ULL: goto x86_l_19b4;
	case 6587ULL: goto x86_l_19bb;
	case 6593ULL: goto x86_l_19c1;
	case 6600ULL: goto x86_l_19c8;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6612ULL: goto x86_l_19d4;
	case 6615ULL: goto x86_l_19d7;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6638ULL: goto x86_l_19ee;
	case 6644ULL: goto x86_l_19f4;
	case 6651ULL: goto x86_l_19fb;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6680ULL: goto x86_l_1a18;
	case 6682ULL: goto x86_l_1a1a;
	case 6689ULL: goto x86_l_1a21;
	case 6695ULL: goto x86_l_1a27;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6707ULL: goto x86_l_1a33;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6733ULL: goto x86_l_1a4d;
	case 6740ULL: goto x86_l_1a54;
	case 6746ULL: goto x86_l_1a5a;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6782ULL: goto x86_l_1a7e;
	case 6784ULL: goto x86_l_1a80;
	case 6791ULL: goto x86_l_1a87;
	case 6797ULL: goto x86_l_1a8d;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6825ULL: goto x86_l_1aa9;
	case 6830ULL: goto x86_l_1aae;
	case 6833ULL: goto x86_l_1ab1;
	case 6835ULL: goto x86_l_1ab3;
	case 6842ULL: goto x86_l_1aba;
	case 6848ULL: goto x86_l_1ac0;
	case 6855ULL: goto x86_l_1ac7;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6867ULL: goto x86_l_1ad3;
	case 6870ULL: goto x86_l_1ad6;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6893ULL: goto x86_l_1aed;
	case 6899ULL: goto x86_l_1af3;
	case 6906ULL: goto x86_l_1afa;
	case 6909ULL: goto x86_l_1afd;
	case 6911ULL: goto x86_l_1aff;
	case 6918ULL: goto x86_l_1b06;
	case 6921ULL: goto x86_l_1b09;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6935ULL: goto x86_l_1b17;
	case 6937ULL: goto x86_l_1b19;
	case 6944ULL: goto x86_l_1b20;
	case 6950ULL: goto x86_l_1b26;
	case 6957ULL: goto x86_l_1b2d;
	case 6960ULL: goto x86_l_1b30;
	case 6962ULL: goto x86_l_1b32;
	case 6969ULL: goto x86_l_1b39;
	case 6972ULL: goto x86_l_1b3c;
	case 6978ULL: goto x86_l_1b42;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6995ULL: goto x86_l_1b53;
	case 7001ULL: goto x86_l_1b59;
	case 7008ULL: goto x86_l_1b60;
	case 7011ULL: goto x86_l_1b63;
	case 7013ULL: goto x86_l_1b65;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7039ULL: goto x86_l_1b7f;
	case 7046ULL: goto x86_l_1b86;
	case 7052ULL: goto x86_l_1b8c;
	case 7059ULL: goto x86_l_1b93;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7090ULL: goto x86_l_1bb2;
	case 7097ULL: goto x86_l_1bb9;
	case 7103ULL: goto x86_l_1bbf;
	case 7110ULL: goto x86_l_1bc6;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7122ULL: goto x86_l_1bd2;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7148ULL: goto x86_l_1bec;
	case 7154ULL: goto x86_l_1bf2;
	case 7161ULL: goto x86_l_1bf9;
	case 7164ULL: goto x86_l_1bfc;
	case 7166ULL: goto x86_l_1bfe;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7182ULL: goto x86_l_1c0e;
	case 7189ULL: goto x86_l_1c15;
	case 7194ULL: goto x86_l_1c1a;
	case 7201ULL: goto x86_l_1c21;
	case 7203ULL: goto x86_l_1c23;
	case 7210ULL: goto x86_l_1c2a;
	case 7216ULL: goto x86_l_1c30;
	case 7223ULL: goto x86_l_1c37;
	case 7226ULL: goto x86_l_1c3a;
	case 7228ULL: goto x86_l_1c3c;
	case 7235ULL: goto x86_l_1c43;
	case 7238ULL: goto x86_l_1c46;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7252ULL: goto x86_l_1c54;
	case 7254ULL: goto x86_l_1c56;
	case 7261ULL: goto x86_l_1c5d;
	case 7267ULL: goto x86_l_1c63;
	case 7274ULL: goto x86_l_1c6a;
	case 7277ULL: goto x86_l_1c6d;
	case 7279ULL: goto x86_l_1c6f;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7305ULL: goto x86_l_1c89;
	case 7312ULL: goto x86_l_1c90;
	case 7318ULL: goto x86_l_1c96;
	case 7325ULL: goto x86_l_1c9d;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7354ULL: goto x86_l_1cba;
	case 7356ULL: goto x86_l_1cbc;
	case 7363ULL: goto x86_l_1cc3;
	case 7369ULL: goto x86_l_1cc9;
	case 7376ULL: goto x86_l_1cd0;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7388ULL: goto x86_l_1cdc;
	case 7391ULL: goto x86_l_1cdf;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7405ULL: goto x86_l_1ced;
	case 7407ULL: goto x86_l_1cef;
	case 7414ULL: goto x86_l_1cf6;
	case 7420ULL: goto x86_l_1cfc;
	case 7427ULL: goto x86_l_1d03;
	case 7430ULL: goto x86_l_1d06;
	case 7432ULL: goto x86_l_1d08;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7465ULL: goto x86_l_1d29;
	case 7471ULL: goto x86_l_1d2f;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7483ULL: goto x86_l_1d3b;
	case 7490ULL: goto x86_l_1d42;
	case 7493ULL: goto x86_l_1d45;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7507ULL: goto x86_l_1d53;
	case 7509ULL: goto x86_l_1d55;
	case 7516ULL: goto x86_l_1d5c;
	case 7522ULL: goto x86_l_1d62;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7534ULL: goto x86_l_1d6e;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7558ULL: goto x86_l_1d86;
	case 7560ULL: goto x86_l_1d88;
	case 7567ULL: goto x86_l_1d8f;
	case 7573ULL: goto x86_l_1d95;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7601ULL: goto x86_l_1db1;
	case 7606ULL: goto x86_l_1db6;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7618ULL: goto x86_l_1dc2;
	case 7624ULL: goto x86_l_1dc8;
	case 7631ULL: goto x86_l_1dcf;
	case 7634ULL: goto x86_l_1dd2;
	case 7636ULL: goto x86_l_1dd4;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7652ULL: goto x86_l_1de4;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7662ULL: goto x86_l_1dee;
	case 7669ULL: goto x86_l_1df5;
	case 7675ULL: goto x86_l_1dfb;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7687ULL: goto x86_l_1e07;
	case 7694ULL: goto x86_l_1e0e;
	case 7697ULL: goto x86_l_1e11;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7711ULL: goto x86_l_1e1f;
	case 7713ULL: goto x86_l_1e21;
	case 7720ULL: goto x86_l_1e28;
	case 7726ULL: goto x86_l_1e2e;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7738ULL: goto x86_l_1e3a;
	case 7745ULL: goto x86_l_1e41;
	case 7748ULL: goto x86_l_1e44;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7762ULL: goto x86_l_1e52;
	case 7764ULL: goto x86_l_1e54;
	case 7771ULL: goto x86_l_1e5b;
	case 7777ULL: goto x86_l_1e61;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7789ULL: goto x86_l_1e6d;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7815ULL: goto x86_l_1e87;
	case 7822ULL: goto x86_l_1e8e;
	case 7828ULL: goto x86_l_1e94;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7847ULL: goto x86_l_1ea7;
	case 7850ULL: goto x86_l_1eaa;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7864ULL: goto x86_l_1eb8;
	case 7866ULL: goto x86_l_1eba;
	case 7873ULL: goto x86_l_1ec1;
	case 7879ULL: goto x86_l_1ec7;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7898ULL: goto x86_l_1eda;
	case 7901ULL: goto x86_l_1edd;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7924ULL: goto x86_l_1ef4;
	case 7930ULL: goto x86_l_1efa;
	case 7937ULL: goto x86_l_1f01;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7949ULL: goto x86_l_1f0d;
	case 7952ULL: goto x86_l_1f10;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7968ULL: goto x86_l_1f20;
	case 7975ULL: goto x86_l_1f27;
	case 7981ULL: goto x86_l_1f2d;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 8000ULL: goto x86_l_1f40;
	case 8003ULL: goto x86_l_1f43;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8026ULL: goto x86_l_1f5a;
	case 8032ULL: goto x86_l_1f60;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8044ULL: goto x86_l_1f6c;
	case 8051ULL: goto x86_l_1f73;
	case 8054ULL: goto x86_l_1f76;
	case 8060ULL: goto x86_l_1f7c;
	case 8065ULL: goto x86_l_1f81;
	case 8068ULL: goto x86_l_1f84;
	case 8070ULL: goto x86_l_1f86;
	case 8077ULL: goto x86_l_1f8d;
	case 8083ULL: goto x86_l_1f93;
	case 8090ULL: goto x86_l_1f9a;
	case 8093ULL: goto x86_l_1f9d;
	case 8095ULL: goto x86_l_1f9f;
	case 8102ULL: goto x86_l_1fa6;
	case 8105ULL: goto x86_l_1fa9;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8128ULL: goto x86_l_1fc0;
	case 8134ULL: goto x86_l_1fc6;
	case 8141ULL: goto x86_l_1fcd;
	case 8144ULL: goto x86_l_1fd0;
	case 8146ULL: goto x86_l_1fd2;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_18e8:
	/* 0x18e8: cmp    r14d,0x162 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 354ULL);
x86_l_18ef:
	/* 0x18ef: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_18f5:
	/* 0x18f5: lea    rdi,[rcx+0x172] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 370ULL);
x86_l_18fc:
	/* 0x18fc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_18ff:
	/* 0x18ff: jbe    1916 <tail_policy_denied_ipv6+0x1916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1916;
	}
x86_l_1901:
	/* 0x1901: add    rcx,0x171 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 369ULL);
x86_l_1908:
	/* 0x1908: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_190b:
	/* 0x190b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1911:
	/* 0x1911: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1916:
	/* 0x1916: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1919:
	/* 0x1919: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_191b:
	/* 0x191b: cmp    r14d,0x164 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 356ULL);
x86_l_1922:
	/* 0x1922: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1928:
	/* 0x1928: lea    rsi,[rcx+0x174] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 372ULL);
x86_l_192f:
	/* 0x192f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1932:
	/* 0x1932: jbe    1949 <tail_policy_denied_ipv6+0x1949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1949;
	}
x86_l_1934:
	/* 0x1934: add    rcx,0x173 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 371ULL);
x86_l_193b:
	/* 0x193b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_193e:
	/* 0x193e: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1944:
	/* 0x1944: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1949:
	/* 0x1949: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_194c:
	/* 0x194c: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_194e:
	/* 0x194e: cmp    r14d,0x166 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 358ULL);
x86_l_1955:
	/* 0x1955: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_195b:
	/* 0x195b: lea    rdi,[rcx+0x176] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 374ULL);
x86_l_1962:
	/* 0x1962: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1965:
	/* 0x1965: jbe    197c <tail_policy_denied_ipv6+0x197c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_197c;
	}
x86_l_1967:
	/* 0x1967: add    rcx,0x175 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 373ULL);
x86_l_196e:
	/* 0x196e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1971:
	/* 0x1971: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1977:
	/* 0x1977: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_197c:
	/* 0x197c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_197f:
	/* 0x197f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1981:
	/* 0x1981: cmp    r14d,0x168 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 360ULL);
x86_l_1988:
	/* 0x1988: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_198e:
	/* 0x198e: lea    rsi,[rcx+0x178] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_1995:
	/* 0x1995: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1998:
	/* 0x1998: jbe    19af <tail_policy_denied_ipv6+0x19af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19af;
	}
x86_l_199a:
	/* 0x199a: add    rcx,0x177 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 375ULL);
x86_l_19a1:
	/* 0x19a1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_19a4:
	/* 0x19a4: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_19aa:
	/* 0x19aa: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_19af:
	/* 0x19af: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19b2:
	/* 0x19b2: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19b4:
	/* 0x19b4: cmp    r14d,0x16a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 362ULL);
x86_l_19bb:
	/* 0x19bb: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_19c1:
	/* 0x19c1: lea    rdi,[rcx+0x17a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 378ULL);
x86_l_19c8:
	/* 0x19c8: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_19cb:
	/* 0x19cb: jbe    19e2 <tail_policy_denied_ipv6+0x19e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_19e2;
	}
x86_l_19cd:
	/* 0x19cd: add    rcx,0x179 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 377ULL);
x86_l_19d4:
	/* 0x19d4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_19d7:
	/* 0x19d7: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_19dd:
	/* 0x19dd: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_19e2:
	/* 0x19e2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19e5:
	/* 0x19e5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19e7:
	/* 0x19e7: cmp    r14d,0x16c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 364ULL);
x86_l_19ee:
	/* 0x19ee: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_19f4:
	/* 0x19f4: lea    rsi,[rcx+0x17c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 380ULL);
x86_l_19fb:
	/* 0x19fb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_19fe:
	/* 0x19fe: jbe    1a15 <tail_policy_denied_ipv6+0x1a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a15;
	}
x86_l_1a00:
	/* 0x1a00: add    rcx,0x17b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 379ULL);
x86_l_1a07:
	/* 0x1a07: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a0a:
	/* 0x1a0a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1a10:
	/* 0x1a10: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1a15:
	/* 0x1a15: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a18:
	/* 0x1a18: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a1a:
	/* 0x1a1a: cmp    r14d,0x16e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 366ULL);
x86_l_1a21:
	/* 0x1a21: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1a27:
	/* 0x1a27: lea    rdi,[rcx+0x17e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 382ULL);
x86_l_1a2e:
	/* 0x1a2e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1a31:
	/* 0x1a31: jbe    1a48 <tail_policy_denied_ipv6+0x1a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a48;
	}
x86_l_1a33:
	/* 0x1a33: add    rcx,0x17d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 381ULL);
x86_l_1a3a:
	/* 0x1a3a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a3d:
	/* 0x1a3d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1a43:
	/* 0x1a43: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1a48:
	/* 0x1a48: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a4d:
	/* 0x1a4d: cmp    r14d,0x170 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 368ULL);
x86_l_1a54:
	/* 0x1a54: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1a5a:
	/* 0x1a5a: lea    rsi,[rcx+0x180] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_1a61:
	/* 0x1a61: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1a64:
	/* 0x1a64: jbe    1a7b <tail_policy_denied_ipv6+0x1a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a7b;
	}
x86_l_1a66:
	/* 0x1a66: add    rcx,0x17f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 383ULL);
x86_l_1a6d:
	/* 0x1a6d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a70:
	/* 0x1a70: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1a76:
	/* 0x1a76: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1a7b:
	/* 0x1a7b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a7e:
	/* 0x1a7e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a80:
	/* 0x1a80: cmp    r14d,0x172 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 370ULL);
x86_l_1a87:
	/* 0x1a87: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1a8d:
	/* 0x1a8d: lea    rdi,[rcx+0x182] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 386ULL);
x86_l_1a94:
	/* 0x1a94: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1a97:
	/* 0x1a97: jbe    1aae <tail_policy_denied_ipv6+0x1aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1aae;
	}
x86_l_1a99:
	/* 0x1a99: add    rcx,0x181 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 385ULL);
x86_l_1aa0:
	/* 0x1aa0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1aa3:
	/* 0x1aa3: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1aa9:
	/* 0x1aa9: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1aae:
	/* 0x1aae: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ab1:
	/* 0x1ab1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ab3:
	/* 0x1ab3: cmp    r14d,0x174 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 372ULL);
x86_l_1aba:
	/* 0x1aba: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1ac0:
	/* 0x1ac0: lea    rsi,[rcx+0x184] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 388ULL);
x86_l_1ac7:
	/* 0x1ac7: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1aca:
	/* 0x1aca: jbe    1ae1 <tail_policy_denied_ipv6+0x1ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ae1;
	}
x86_l_1acc:
	/* 0x1acc: add    rcx,0x183 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 387ULL);
x86_l_1ad3:
	/* 0x1ad3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1ad6:
	/* 0x1ad6: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1adc:
	/* 0x1adc: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1ae1:
	/* 0x1ae1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae4:
	/* 0x1ae4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ae6:
	/* 0x1ae6: cmp    r14d,0x176 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 374ULL);
x86_l_1aed:
	/* 0x1aed: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1af3:
	/* 0x1af3: lea    rdi,[rcx+0x186] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 390ULL);
x86_l_1afa:
	/* 0x1afa: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1afd:
	/* 0x1afd: jbe    1b14 <tail_policy_denied_ipv6+0x1b14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b14;
	}
x86_l_1aff:
	/* 0x1aff: add    rcx,0x185 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 389ULL);
x86_l_1b06:
	/* 0x1b06: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b09:
	/* 0x1b09: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1b0f:
	/* 0x1b0f: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1b14:
	/* 0x1b14: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b17:
	/* 0x1b17: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b19:
	/* 0x1b19: cmp    r14d,0x178 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 376ULL);
x86_l_1b20:
	/* 0x1b20: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1b26:
	/* 0x1b26: lea    rsi,[rcx+0x188] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_1b2d:
	/* 0x1b2d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1b30:
	/* 0x1b30: jbe    1b47 <tail_policy_denied_ipv6+0x1b47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b47;
	}
x86_l_1b32:
	/* 0x1b32: add    rcx,0x187 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 391ULL);
x86_l_1b39:
	/* 0x1b39: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b3c:
	/* 0x1b3c: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1b42:
	/* 0x1b42: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1b47:
	/* 0x1b47: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b4a:
	/* 0x1b4a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b4c:
	/* 0x1b4c: cmp    r14d,0x17a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 378ULL);
x86_l_1b53:
	/* 0x1b53: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1b59:
	/* 0x1b59: lea    rdi,[rcx+0x18a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 394ULL);
x86_l_1b60:
	/* 0x1b60: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1b63:
	/* 0x1b63: jbe    1b7a <tail_policy_denied_ipv6+0x1b7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b7a;
	}
x86_l_1b65:
	/* 0x1b65: add    rcx,0x189 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 393ULL);
x86_l_1b6c:
	/* 0x1b6c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b6f:
	/* 0x1b6f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1b75:
	/* 0x1b75: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1b7a:
	/* 0x1b7a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b7d:
	/* 0x1b7d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b7f:
	/* 0x1b7f: cmp    r14d,0x17c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 380ULL);
x86_l_1b86:
	/* 0x1b86: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1b8c:
	/* 0x1b8c: lea    rsi,[rcx+0x18c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 396ULL);
x86_l_1b93:
	/* 0x1b93: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1b96:
	/* 0x1b96: jbe    1bad <tail_policy_denied_ipv6+0x1bad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1bad;
	}
x86_l_1b98:
	/* 0x1b98: add    rcx,0x18b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 395ULL);
x86_l_1b9f:
	/* 0x1b9f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1ba8:
	/* 0x1ba8: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1bad:
	/* 0x1bad: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bb0:
	/* 0x1bb0: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bb2:
	/* 0x1bb2: cmp    r14d,0x17e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 382ULL);
x86_l_1bb9:
	/* 0x1bb9: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1bbf:
	/* 0x1bbf: lea    rdi,[rcx+0x18e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 398ULL);
x86_l_1bc6:
	/* 0x1bc6: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1bc9:
	/* 0x1bc9: jbe    1be0 <tail_policy_denied_ipv6+0x1be0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1be0;
	}
x86_l_1bcb:
	/* 0x1bcb: add    rcx,0x18d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 397ULL);
x86_l_1bd2:
	/* 0x1bd2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1bd5:
	/* 0x1bd5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1bdb:
	/* 0x1bdb: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1be0:
	/* 0x1be0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1be3:
	/* 0x1be3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1be5:
	/* 0x1be5: cmp    r14d,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 512ULL);
x86_l_1bec:
	/* 0x1bec: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1bf2:
	/* 0x1bf2: lea    rsi,[rcx+0x210] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 528ULL);
x86_l_1bf9:
	/* 0x1bf9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1bfc:
	/* 0x1bfc: jbe    1c1a <tail_policy_denied_ipv6+0x1c1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c1a;
	}
x86_l_1bfe:
	/* 0x1bfe: lea    rsi,[rcx+0x20f] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 527ULL);
x86_l_1c05:
	/* 0x1c05: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1c08:
	/* 0x1c08: ja     286d <tail_policy_denied_ipv6+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10349ULL;
	}
x86_l_1c0e:
	/* 0x1c0e: movzx  ecx,BYTE PTR [rcx+0x20e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 526ULL);
x86_l_1c15:
	/* 0x1c15: jmp    539 <tail_policy_denied_ipv6+0x539> */
	return 1337ULL;
x86_l_1c1a:
	/* 0x1c1a: movzx  edi,WORD PTR [rcx+0x20e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 526ULL);
x86_l_1c21:
	/* 0x1c21: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c23:
	/* 0x1c23: cmp    r14d,0x202 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 514ULL);
x86_l_1c2a:
	/* 0x1c2a: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1c30:
	/* 0x1c30: lea    rdi,[rcx+0x212] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 530ULL);
x86_l_1c37:
	/* 0x1c37: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1c3a:
	/* 0x1c3a: jbe    1c51 <tail_policy_denied_ipv6+0x1c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c51;
	}
x86_l_1c3c:
	/* 0x1c3c: add    rcx,0x211 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 529ULL);
x86_l_1c43:
	/* 0x1c43: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1c46:
	/* 0x1c46: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1c4c:
	/* 0x1c4c: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1c51:
	/* 0x1c51: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c54:
	/* 0x1c54: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c56:
	/* 0x1c56: cmp    r14d,0x204 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 516ULL);
x86_l_1c5d:
	/* 0x1c5d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1c63:
	/* 0x1c63: lea    rsi,[rcx+0x214] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 532ULL);
x86_l_1c6a:
	/* 0x1c6a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1c6d:
	/* 0x1c6d: jbe    1c84 <tail_policy_denied_ipv6+0x1c84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c84;
	}
x86_l_1c6f:
	/* 0x1c6f: add    rcx,0x213 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 531ULL);
x86_l_1c76:
	/* 0x1c76: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1c79:
	/* 0x1c79: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1c7f:
	/* 0x1c7f: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1c84:
	/* 0x1c84: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c87:
	/* 0x1c87: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c89:
	/* 0x1c89: cmp    r14d,0x206 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 518ULL);
x86_l_1c90:
	/* 0x1c90: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1c96:
	/* 0x1c96: lea    rdi,[rcx+0x216] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 534ULL);
x86_l_1c9d:
	/* 0x1c9d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1ca0:
	/* 0x1ca0: jbe    1cb7 <tail_policy_denied_ipv6+0x1cb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cb7;
	}
x86_l_1ca2:
	/* 0x1ca2: add    rcx,0x215 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 533ULL);
x86_l_1ca9:
	/* 0x1ca9: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1cac:
	/* 0x1cac: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1cb2:
	/* 0x1cb2: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1cb7:
	/* 0x1cb7: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cba:
	/* 0x1cba: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cbc:
	/* 0x1cbc: cmp    r14d,0x208 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 520ULL);
x86_l_1cc3:
	/* 0x1cc3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1cc9:
	/* 0x1cc9: lea    rsi,[rcx+0x218] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_1cd0:
	/* 0x1cd0: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1cd3:
	/* 0x1cd3: jbe    1cea <tail_policy_denied_ipv6+0x1cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1cea;
	}
x86_l_1cd5:
	/* 0x1cd5: add    rcx,0x217 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 535ULL);
x86_l_1cdc:
	/* 0x1cdc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1cdf:
	/* 0x1cdf: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1ce5:
	/* 0x1ce5: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1cea:
	/* 0x1cea: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ced:
	/* 0x1ced: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cef:
	/* 0x1cef: cmp    r14d,0x20a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 522ULL);
x86_l_1cf6:
	/* 0x1cf6: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1cfc:
	/* 0x1cfc: lea    rdi,[rcx+0x21a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 538ULL);
x86_l_1d03:
	/* 0x1d03: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1d06:
	/* 0x1d06: jbe    1d1d <tail_policy_denied_ipv6+0x1d1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1d1d;
	}
x86_l_1d08:
	/* 0x1d08: add    rcx,0x219 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 537ULL);
x86_l_1d0f:
	/* 0x1d0f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1d12:
	/* 0x1d12: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1d18:
	/* 0x1d18: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1d1d:
	/* 0x1d1d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d20:
	/* 0x1d20: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d22:
	/* 0x1d22: cmp    r14d,0x20c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 524ULL);
x86_l_1d29:
	/* 0x1d29: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1d2f:
	/* 0x1d2f: lea    rsi,[rcx+0x21c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 540ULL);
x86_l_1d36:
	/* 0x1d36: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1d39:
	/* 0x1d39: jbe    1d50 <tail_policy_denied_ipv6+0x1d50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1d50;
	}
x86_l_1d3b:
	/* 0x1d3b: add    rcx,0x21b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 539ULL);
x86_l_1d42:
	/* 0x1d42: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1d45:
	/* 0x1d45: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1d4b:
	/* 0x1d4b: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1d50:
	/* 0x1d50: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d53:
	/* 0x1d53: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d55:
	/* 0x1d55: cmp    r14d,0x20e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 526ULL);
x86_l_1d5c:
	/* 0x1d5c: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1d62:
	/* 0x1d62: lea    rdi,[rcx+0x21e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 542ULL);
x86_l_1d69:
	/* 0x1d69: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1d6c:
	/* 0x1d6c: jbe    1d83 <tail_policy_denied_ipv6+0x1d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1d83;
	}
x86_l_1d6e:
	/* 0x1d6e: add    rcx,0x21d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 541ULL);
x86_l_1d75:
	/* 0x1d75: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1d78:
	/* 0x1d78: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1d7e:
	/* 0x1d7e: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1d83:
	/* 0x1d83: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d86:
	/* 0x1d86: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d88:
	/* 0x1d88: cmp    r14d,0x210 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 528ULL);
x86_l_1d8f:
	/* 0x1d8f: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1d95:
	/* 0x1d95: lea    rsi,[rcx+0x220] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1d9c:
	/* 0x1d9c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1d9f:
	/* 0x1d9f: jbe    1db6 <tail_policy_denied_ipv6+0x1db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1db6;
	}
x86_l_1da1:
	/* 0x1da1: add    rcx,0x21f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 543ULL);
x86_l_1da8:
	/* 0x1da8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1db1:
	/* 0x1db1: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1db6:
	/* 0x1db6: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1db9:
	/* 0x1db9: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dbb:
	/* 0x1dbb: cmp    r14d,0x212 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 530ULL);
x86_l_1dc2:
	/* 0x1dc2: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1dc8:
	/* 0x1dc8: lea    rdi,[rcx+0x222] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 546ULL);
x86_l_1dcf:
	/* 0x1dcf: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1dd2:
	/* 0x1dd2: jbe    1de9 <tail_policy_denied_ipv6+0x1de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1de9;
	}
x86_l_1dd4:
	/* 0x1dd4: add    rcx,0x221 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 545ULL);
x86_l_1ddb:
	/* 0x1ddb: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1de4:
	/* 0x1de4: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1de9:
	/* 0x1de9: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1dec:
	/* 0x1dec: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dee:
	/* 0x1dee: cmp    r14d,0x214 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 532ULL);
x86_l_1df5:
	/* 0x1df5: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1dfb:
	/* 0x1dfb: lea    rsi,[rcx+0x224] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_1e02:
	/* 0x1e02: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1e05:
	/* 0x1e05: jbe    1e1c <tail_policy_denied_ipv6+0x1e1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e1c;
	}
x86_l_1e07:
	/* 0x1e07: add    rcx,0x223 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 547ULL);
x86_l_1e0e:
	/* 0x1e0e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1e11:
	/* 0x1e11: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1e17:
	/* 0x1e17: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1e1c:
	/* 0x1e1c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e1f:
	/* 0x1e1f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e21:
	/* 0x1e21: cmp    r14d,0x216 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 534ULL);
x86_l_1e28:
	/* 0x1e28: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1e2e:
	/* 0x1e2e: lea    rdi,[rcx+0x226] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 550ULL);
x86_l_1e35:
	/* 0x1e35: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1e38:
	/* 0x1e38: jbe    1e4f <tail_policy_denied_ipv6+0x1e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e4f;
	}
x86_l_1e3a:
	/* 0x1e3a: add    rcx,0x225 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 549ULL);
x86_l_1e41:
	/* 0x1e41: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1e44:
	/* 0x1e44: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1e4a:
	/* 0x1e4a: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1e4f:
	/* 0x1e4f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e52:
	/* 0x1e52: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e54:
	/* 0x1e54: cmp    r14d,0x218 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 536ULL);
x86_l_1e5b:
	/* 0x1e5b: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1e61:
	/* 0x1e61: lea    rsi,[rcx+0x228] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 552ULL);
x86_l_1e68:
	/* 0x1e68: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1e6b:
	/* 0x1e6b: jbe    1e82 <tail_policy_denied_ipv6+0x1e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e82;
	}
x86_l_1e6d:
	/* 0x1e6d: add    rcx,0x227 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 551ULL);
x86_l_1e74:
	/* 0x1e74: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1e77:
	/* 0x1e77: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1e7d:
	/* 0x1e7d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1e82:
	/* 0x1e82: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e85:
	/* 0x1e85: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e87:
	/* 0x1e87: cmp    r14d,0x21a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 538ULL);
x86_l_1e8e:
	/* 0x1e8e: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1e94:
	/* 0x1e94: lea    rdi,[rcx+0x22a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 554ULL);
x86_l_1e9b:
	/* 0x1e9b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1e9e:
	/* 0x1e9e: jbe    1eb5 <tail_policy_denied_ipv6+0x1eb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1eb5;
	}
x86_l_1ea0:
	/* 0x1ea0: add    rcx,0x229 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 553ULL);
x86_l_1ea7:
	/* 0x1ea7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1eaa:
	/* 0x1eaa: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1eb0:
	/* 0x1eb0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1eb5:
	/* 0x1eb5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eb8:
	/* 0x1eb8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1eba:
	/* 0x1eba: cmp    r14d,0x21c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 540ULL);
x86_l_1ec1:
	/* 0x1ec1: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1ec7:
	/* 0x1ec7: lea    rsi,[rcx+0x22c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 556ULL);
x86_l_1ece:
	/* 0x1ece: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1ed1:
	/* 0x1ed1: jbe    1ee8 <tail_policy_denied_ipv6+0x1ee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ee8;
	}
x86_l_1ed3:
	/* 0x1ed3: add    rcx,0x22b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 555ULL);
x86_l_1eda:
	/* 0x1eda: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1edd:
	/* 0x1edd: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1ee3:
	/* 0x1ee3: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1ee8:
	/* 0x1ee8: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1eeb:
	/* 0x1eeb: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1eed:
	/* 0x1eed: cmp    r14d,0x21e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 542ULL);
x86_l_1ef4:
	/* 0x1ef4: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1efa:
	/* 0x1efa: lea    rdi,[rcx+0x22e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 558ULL);
x86_l_1f01:
	/* 0x1f01: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1f04:
	/* 0x1f04: jbe    1f1b <tail_policy_denied_ipv6+0x1f1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f1b;
	}
x86_l_1f06:
	/* 0x1f06: add    rcx,0x22d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 557ULL);
x86_l_1f0d:
	/* 0x1f0d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1f10:
	/* 0x1f10: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1f16:
	/* 0x1f16: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1f1b:
	/* 0x1f1b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f1e:
	/* 0x1f1e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f20:
	/* 0x1f20: cmp    r14d,0x220 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 544ULL);
x86_l_1f27:
	/* 0x1f27: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1f2d:
	/* 0x1f2d: lea    rsi,[rcx+0x230] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_1f34:
	/* 0x1f34: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1f37:
	/* 0x1f37: jbe    1f4e <tail_policy_denied_ipv6+0x1f4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f4e;
	}
x86_l_1f39:
	/* 0x1f39: add    rcx,0x22f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 559ULL);
x86_l_1f40:
	/* 0x1f40: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1f43:
	/* 0x1f43: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1f49:
	/* 0x1f49: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1f4e:
	/* 0x1f4e: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f51:
	/* 0x1f51: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f53:
	/* 0x1f53: cmp    r14d,0x222 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 546ULL);
x86_l_1f5a:
	/* 0x1f5a: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1f60:
	/* 0x1f60: lea    rdi,[rcx+0x232] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 562ULL);
x86_l_1f67:
	/* 0x1f67: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1f6a:
	/* 0x1f6a: jbe    1f81 <tail_policy_denied_ipv6+0x1f81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1f81;
	}
x86_l_1f6c:
	/* 0x1f6c: add    rcx,0x231 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 561ULL);
x86_l_1f73:
	/* 0x1f73: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1f76:
	/* 0x1f76: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1f7c:
	/* 0x1f7c: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1f81:
	/* 0x1f81: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f84:
	/* 0x1f84: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f86:
	/* 0x1f86: cmp    r14d,0x224 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 548ULL);
x86_l_1f8d:
	/* 0x1f8d: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1f93:
	/* 0x1f93: lea    rsi,[rcx+0x234] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 564ULL);
x86_l_1f9a:
	/* 0x1f9a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1f9d:
	/* 0x1f9d: jbe    1fb4 <tail_policy_denied_ipv6+0x1fb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1fb4;
	}
x86_l_1f9f:
	/* 0x1f9f: add    rcx,0x233 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 563ULL);
x86_l_1fa6:
	/* 0x1fa6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1fa9:
	/* 0x1fa9: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_1faf:
	/* 0x1faf: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_1fb4:
	/* 0x1fb4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fb7:
	/* 0x1fb7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fb9:
	/* 0x1fb9: cmp    r14d,0x226 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 550ULL);
x86_l_1fc0:
	/* 0x1fc0: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1fc6:
	/* 0x1fc6: lea    rdi,[rcx+0x236] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 566ULL);
x86_l_1fcd:
	/* 0x1fcd: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_1fd0:
	/* 0x1fd0: jbe    1fe7 <tail_policy_denied_ipv6+0x1fe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 8167ULL;
	}
x86_l_1fd2:
	/* 0x1fd2: add    rcx,0x235 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 565ULL);
x86_l_1fd9:
	/* 0x1fd9: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1fdc:
	/* 0x1fdc: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_1fe2:
	/* 0x1fe2: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
	return 8167ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8167ULL: goto x86_l_1fe7;
	case 8170ULL: goto x86_l_1fea;
	case 8172ULL: goto x86_l_1fec;
	case 8179ULL: goto x86_l_1ff3;
	case 8185ULL: goto x86_l_1ff9;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8221ULL: goto x86_l_201d;
	case 8223ULL: goto x86_l_201f;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8243ULL: goto x86_l_2033;
	case 8246ULL: goto x86_l_2036;
	case 8248ULL: goto x86_l_2038;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8281ULL: goto x86_l_2059;
	case 8287ULL: goto x86_l_205f;
	case 8294ULL: goto x86_l_2066;
	case 8297ULL: goto x86_l_2069;
	case 8299ULL: goto x86_l_206b;
	case 8306ULL: goto x86_l_2072;
	case 8309ULL: goto x86_l_2075;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8345ULL: goto x86_l_2099;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8357ULL: goto x86_l_20a5;
	case 8360ULL: goto x86_l_20a8;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8383ULL: goto x86_l_20bf;
	case 8389ULL: goto x86_l_20c5;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8401ULL: goto x86_l_20d1;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8427ULL: goto x86_l_20eb;
	case 8434ULL: goto x86_l_20f2;
	case 8440ULL: goto x86_l_20f8;
	case 8447ULL: goto x86_l_20ff;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8468ULL: goto x86_l_2114;
	case 8473ULL: goto x86_l_2119;
	case 8476ULL: goto x86_l_211c;
	case 8478ULL: goto x86_l_211e;
	case 8485ULL: goto x86_l_2125;
	case 8491ULL: goto x86_l_212b;
	case 8498ULL: goto x86_l_2132;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8524ULL: goto x86_l_214c;
	case 8527ULL: goto x86_l_214f;
	case 8529ULL: goto x86_l_2151;
	case 8536ULL: goto x86_l_2158;
	case 8542ULL: goto x86_l_215e;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8561ULL: goto x86_l_2171;
	case 8564ULL: goto x86_l_2174;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8580ULL: goto x86_l_2184;
	case 8587ULL: goto x86_l_218b;
	case 8593ULL: goto x86_l_2191;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8605ULL: goto x86_l_219d;
	case 8612ULL: goto x86_l_21a4;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8626ULL: goto x86_l_21b2;
	case 8629ULL: goto x86_l_21b5;
	case 8631ULL: goto x86_l_21b7;
	case 8638ULL: goto x86_l_21be;
	case 8644ULL: goto x86_l_21c4;
	case 8651ULL: goto x86_l_21cb;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8663ULL: goto x86_l_21d7;
	case 8666ULL: goto x86_l_21da;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8689ULL: goto x86_l_21f1;
	case 8695ULL: goto x86_l_21f7;
	case 8702ULL: goto x86_l_21fe;
	case 8705ULL: goto x86_l_2201;
	case 8707ULL: goto x86_l_2203;
	case 8714ULL: goto x86_l_220a;
	case 8717ULL: goto x86_l_220d;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8731ULL: goto x86_l_221b;
	case 8733ULL: goto x86_l_221d;
	case 8740ULL: goto x86_l_2224;
	case 8746ULL: goto x86_l_222a;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8758ULL: goto x86_l_2236;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8774ULL: goto x86_l_2246;
	case 8779ULL: goto x86_l_224b;
	case 8782ULL: goto x86_l_224e;
	case 8784ULL: goto x86_l_2250;
	case 8791ULL: goto x86_l_2257;
	case 8797ULL: goto x86_l_225d;
	case 8804ULL: goto x86_l_2264;
	case 8807ULL: goto x86_l_2267;
	case 8809ULL: goto x86_l_2269;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8842ULL: goto x86_l_228a;
	case 8848ULL: goto x86_l_2290;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8867ULL: goto x86_l_22a3;
	case 8870ULL: goto x86_l_22a6;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8884ULL: goto x86_l_22b4;
	case 8886ULL: goto x86_l_22b6;
	case 8893ULL: goto x86_l_22bd;
	case 8899ULL: goto x86_l_22c3;
	case 8906ULL: goto x86_l_22ca;
	case 8909ULL: goto x86_l_22cd;
	case 8911ULL: goto x86_l_22cf;
	case 8918ULL: goto x86_l_22d6;
	case 8921ULL: goto x86_l_22d9;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8944ULL: goto x86_l_22f0;
	case 8950ULL: goto x86_l_22f6;
	case 8957ULL: goto x86_l_22fd;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8978ULL: goto x86_l_2312;
	case 8983ULL: goto x86_l_2317;
	case 8986ULL: goto x86_l_231a;
	case 8988ULL: goto x86_l_231c;
	case 8995ULL: goto x86_l_2323;
	case 9001ULL: goto x86_l_2329;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9013ULL: goto x86_l_2335;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9046ULL: goto x86_l_2356;
	case 9052ULL: goto x86_l_235c;
	case 9059ULL: goto x86_l_2363;
	case 9062ULL: goto x86_l_2366;
	case 9064ULL: goto x86_l_2368;
	case 9071ULL: goto x86_l_236f;
	case 9074ULL: goto x86_l_2372;
	case 9080ULL: goto x86_l_2378;
	case 9085ULL: goto x86_l_237d;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9097ULL: goto x86_l_2389;
	case 9103ULL: goto x86_l_238f;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9115ULL: goto x86_l_239b;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9148ULL: goto x86_l_23bc;
	case 9154ULL: goto x86_l_23c2;
	case 9161ULL: goto x86_l_23c9;
	case 9164ULL: goto x86_l_23cc;
	case 9166ULL: goto x86_l_23ce;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9190ULL: goto x86_l_23e6;
	case 9192ULL: goto x86_l_23e8;
	case 9199ULL: goto x86_l_23ef;
	case 9205ULL: goto x86_l_23f5;
	case 9212ULL: goto x86_l_23fc;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9224ULL: goto x86_l_2408;
	case 9227ULL: goto x86_l_240b;
	case 9233ULL: goto x86_l_2411;
	case 9238ULL: goto x86_l_2416;
	case 9241ULL: goto x86_l_2419;
	case 9243ULL: goto x86_l_241b;
	case 9250ULL: goto x86_l_2422;
	case 9256ULL: goto x86_l_2428;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9268ULL: goto x86_l_2434;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9294ULL: goto x86_l_244e;
	case 9301ULL: goto x86_l_2455;
	case 9307ULL: goto x86_l_245b;
	case 9314ULL: goto x86_l_2462;
	case 9317ULL: goto x86_l_2465;
	case 9319ULL: goto x86_l_2467;
	case 9326ULL: goto x86_l_246e;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9343ULL: goto x86_l_247f;
	case 9345ULL: goto x86_l_2481;
	case 9352ULL: goto x86_l_2488;
	case 9358ULL: goto x86_l_248e;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9370ULL: goto x86_l_249a;
	case 9377ULL: goto x86_l_24a1;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9396ULL: goto x86_l_24b4;
	case 9403ULL: goto x86_l_24bb;
	case 9409ULL: goto x86_l_24c1;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9472ULL: goto x86_l_2500;
	case 9479ULL: goto x86_l_2507;
	case 9482ULL: goto x86_l_250a;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9496ULL: goto x86_l_2518;
	case 9498ULL: goto x86_l_251a;
	case 9505ULL: goto x86_l_2521;
	case 9511ULL: goto x86_l_2527;
	case 9518ULL: goto x86_l_252e;
	case 9521ULL: goto x86_l_2531;
	case 9523ULL: goto x86_l_2533;
	case 9530ULL: goto x86_l_253a;
	case 9533ULL: goto x86_l_253d;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9556ULL: goto x86_l_2554;
	case 9562ULL: goto x86_l_255a;
	case 9569ULL: goto x86_l_2561;
	case 9572ULL: goto x86_l_2564;
	case 9574ULL: goto x86_l_2566;
	case 9581ULL: goto x86_l_256d;
	case 9584ULL: goto x86_l_2570;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9598ULL: goto x86_l_257e;
	case 9600ULL: goto x86_l_2580;
	case 9607ULL: goto x86_l_2587;
	case 9613ULL: goto x86_l_258d;
	case 9620ULL: goto x86_l_2594;
	case 9623ULL: goto x86_l_2597;
	case 9625ULL: goto x86_l_2599;
	case 9632ULL: goto x86_l_25a0;
	case 9635ULL: goto x86_l_25a3;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9649ULL: goto x86_l_25b1;
	case 9651ULL: goto x86_l_25b3;
	case 9658ULL: goto x86_l_25ba;
	case 9664ULL: goto x86_l_25c0;
	case 9671ULL: goto x86_l_25c7;
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9683ULL: goto x86_l_25d3;
	case 9686ULL: goto x86_l_25d6;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9709ULL: goto x86_l_25ed;
	case 9715ULL: goto x86_l_25f3;
	case 9722ULL: goto x86_l_25fa;
	case 9725ULL: goto x86_l_25fd;
	case 9727ULL: goto x86_l_25ff;
	case 9734ULL: goto x86_l_2606;
	case 9737ULL: goto x86_l_2609;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9760ULL: goto x86_l_2620;
	case 9766ULL: goto x86_l_2626;
	case 9773ULL: goto x86_l_262d;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9785ULL: goto x86_l_2639;
	case 9788ULL: goto x86_l_263c;
	case 9794ULL: goto x86_l_2642;
	case 9799ULL: goto x86_l_2647;
	case 9802ULL: goto x86_l_264a;
	case 9804ULL: goto x86_l_264c;
	case 9811ULL: goto x86_l_2653;
	case 9817ULL: goto x86_l_2659;
	case 9824ULL: goto x86_l_2660;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9836ULL: goto x86_l_266c;
	case 9839ULL: goto x86_l_266f;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9853ULL: goto x86_l_267d;
	case 9855ULL: goto x86_l_267f;
	case 9862ULL: goto x86_l_2686;
	case 9868ULL: goto x86_l_268c;
	case 9875ULL: goto x86_l_2693;
	case 9878ULL: goto x86_l_2696;
	case 9880ULL: goto x86_l_2698;
	case 9887ULL: goto x86_l_269f;
	case 9890ULL: goto x86_l_26a2;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9913ULL: goto x86_l_26b9;
	case 9919ULL: goto x86_l_26bf;
	case 9926ULL: goto x86_l_26c6;
	case 9929ULL: goto x86_l_26c9;
	case 9931ULL: goto x86_l_26cb;
	case 9938ULL: goto x86_l_26d2;
	case 9941ULL: goto x86_l_26d5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1fe7:
	/* 0x1fe7: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fea:
	/* 0x1fea: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fec:
	/* 0x1fec: cmp    r14d,0x228 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 552ULL);
x86_l_1ff3:
	/* 0x1ff3: jb     242 <tail_policy_denied_ipv6+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 578ULL;
	}
x86_l_1ff9:
	/* 0x1ff9: lea    rsi,[rcx+0x238] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_2000:
	/* 0x2000: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2003:
	/* 0x2003: jbe    201a <tail_policy_denied_ipv6+0x201a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_201a;
	}
x86_l_2005:
	/* 0x2005: add    rcx,0x237 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 567ULL);
x86_l_200c:
	/* 0x200c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_200f:
	/* 0x200f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2015:
	/* 0x2015: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_201a:
	/* 0x201a: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_201d:
	/* 0x201d: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_201f:
	/* 0x201f: cmp    r14d,0x22a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 554ULL);
x86_l_2026:
	/* 0x2026: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_202c:
	/* 0x202c: lea    rdi,[rcx+0x23a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 570ULL);
x86_l_2033:
	/* 0x2033: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2036:
	/* 0x2036: jbe    204d <tail_policy_denied_ipv6+0x204d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_204d;
	}
x86_l_2038:
	/* 0x2038: add    rcx,0x239 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 569ULL);
x86_l_203f:
	/* 0x203f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2042:
	/* 0x2042: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2048:
	/* 0x2048: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_204d:
	/* 0x204d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2050:
	/* 0x2050: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2052:
	/* 0x2052: cmp    r14d,0x22c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 556ULL);
x86_l_2059:
	/* 0x2059: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_205f:
	/* 0x205f: lea    rsi,[rcx+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_2066:
	/* 0x2066: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2069:
	/* 0x2069: jbe    2080 <tail_policy_denied_ipv6+0x2080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2080;
	}
x86_l_206b:
	/* 0x206b: add    rcx,0x23b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 571ULL);
x86_l_2072:
	/* 0x2072: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2075:
	/* 0x2075: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_207b:
	/* 0x207b: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2080:
	/* 0x2080: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2083:
	/* 0x2083: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2085:
	/* 0x2085: cmp    r14d,0x22e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 558ULL);
x86_l_208c:
	/* 0x208c: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2092:
	/* 0x2092: lea    rdi,[rcx+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_2099:
	/* 0x2099: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_209c:
	/* 0x209c: jbe    20b3 <tail_policy_denied_ipv6+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20b3;
	}
x86_l_209e:
	/* 0x209e: add    rcx,0x23d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 573ULL);
x86_l_20a5:
	/* 0x20a5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_20a8:
	/* 0x20a8: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_20ae:
	/* 0x20ae: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_20b3:
	/* 0x20b3: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20b6:
	/* 0x20b6: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20b8:
	/* 0x20b8: cmp    r14d,0x230 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 560ULL);
x86_l_20bf:
	/* 0x20bf: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_20c5:
	/* 0x20c5: lea    rsi,[rcx+0x240] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 576ULL);
x86_l_20cc:
	/* 0x20cc: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_20cf:
	/* 0x20cf: jbe    20e6 <tail_policy_denied_ipv6+0x20e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20e6;
	}
x86_l_20d1:
	/* 0x20d1: add    rcx,0x23f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 575ULL);
x86_l_20d8:
	/* 0x20d8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_20db:
	/* 0x20db: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_20e1:
	/* 0x20e1: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_20e6:
	/* 0x20e6: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20e9:
	/* 0x20e9: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20eb:
	/* 0x20eb: cmp    r14d,0x232 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 562ULL);
x86_l_20f2:
	/* 0x20f2: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_20f8:
	/* 0x20f8: lea    rdi,[rcx+0x242] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 578ULL);
x86_l_20ff:
	/* 0x20ff: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2102:
	/* 0x2102: jbe    2119 <tail_policy_denied_ipv6+0x2119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2119;
	}
x86_l_2104:
	/* 0x2104: add    rcx,0x241 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 577ULL);
x86_l_210b:
	/* 0x210b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_210e:
	/* 0x210e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2114:
	/* 0x2114: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2119:
	/* 0x2119: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_211c:
	/* 0x211c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_211e:
	/* 0x211e: cmp    r14d,0x234 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 564ULL);
x86_l_2125:
	/* 0x2125: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_212b:
	/* 0x212b: lea    rsi,[rcx+0x244] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 580ULL);
x86_l_2132:
	/* 0x2132: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2135:
	/* 0x2135: jbe    214c <tail_policy_denied_ipv6+0x214c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_214c;
	}
x86_l_2137:
	/* 0x2137: add    rcx,0x243 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 579ULL);
x86_l_213e:
	/* 0x213e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2141:
	/* 0x2141: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2147:
	/* 0x2147: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_214c:
	/* 0x214c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_214f:
	/* 0x214f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2151:
	/* 0x2151: cmp    r14d,0x236 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 566ULL);
x86_l_2158:
	/* 0x2158: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_215e:
	/* 0x215e: lea    rdi,[rcx+0x246] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 582ULL);
x86_l_2165:
	/* 0x2165: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2168:
	/* 0x2168: jbe    217f <tail_policy_denied_ipv6+0x217f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_217f;
	}
x86_l_216a:
	/* 0x216a: add    rcx,0x245 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 581ULL);
x86_l_2171:
	/* 0x2171: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2174:
	/* 0x2174: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_217a:
	/* 0x217a: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_217f:
	/* 0x217f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2182:
	/* 0x2182: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2184:
	/* 0x2184: cmp    r14d,0x238 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 568ULL);
x86_l_218b:
	/* 0x218b: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2191:
	/* 0x2191: lea    rsi,[rcx+0x248] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_2198:
	/* 0x2198: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_219b:
	/* 0x219b: jbe    21b2 <tail_policy_denied_ipv6+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_21b2;
	}
x86_l_219d:
	/* 0x219d: add    rcx,0x247 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 583ULL);
x86_l_21a4:
	/* 0x21a4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_21a7:
	/* 0x21a7: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_21ad:
	/* 0x21ad: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_21b2:
	/* 0x21b2: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21b5:
	/* 0x21b5: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21b7:
	/* 0x21b7: cmp    r14d,0x23a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 570ULL);
x86_l_21be:
	/* 0x21be: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_21c4:
	/* 0x21c4: lea    rdi,[rcx+0x24a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 586ULL);
x86_l_21cb:
	/* 0x21cb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_21ce:
	/* 0x21ce: jbe    21e5 <tail_policy_denied_ipv6+0x21e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_21e5;
	}
x86_l_21d0:
	/* 0x21d0: add    rcx,0x249 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 585ULL);
x86_l_21d7:
	/* 0x21d7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_21da:
	/* 0x21da: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_21e0:
	/* 0x21e0: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_21e5:
	/* 0x21e5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21e8:
	/* 0x21e8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21ea:
	/* 0x21ea: cmp    r14d,0x23c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 572ULL);
x86_l_21f1:
	/* 0x21f1: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_21f7:
	/* 0x21f7: lea    rsi,[rcx+0x24c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 588ULL);
x86_l_21fe:
	/* 0x21fe: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2201:
	/* 0x2201: jbe    2218 <tail_policy_denied_ipv6+0x2218> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2218;
	}
x86_l_2203:
	/* 0x2203: add    rcx,0x24b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 587ULL);
x86_l_220a:
	/* 0x220a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_220d:
	/* 0x220d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2213:
	/* 0x2213: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2218:
	/* 0x2218: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_221b:
	/* 0x221b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_221d:
	/* 0x221d: cmp    r14d,0x23e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 574ULL);
x86_l_2224:
	/* 0x2224: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_222a:
	/* 0x222a: lea    rdi,[rcx+0x24e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 590ULL);
x86_l_2231:
	/* 0x2231: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2234:
	/* 0x2234: jbe    224b <tail_policy_denied_ipv6+0x224b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_224b;
	}
x86_l_2236:
	/* 0x2236: add    rcx,0x24d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 589ULL);
x86_l_223d:
	/* 0x223d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2240:
	/* 0x2240: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2246:
	/* 0x2246: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_224b:
	/* 0x224b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_224e:
	/* 0x224e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2250:
	/* 0x2250: cmp    r14d,0x240 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 576ULL);
x86_l_2257:
	/* 0x2257: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_225d:
	/* 0x225d: lea    rsi,[rcx+0x250] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_2264:
	/* 0x2264: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2267:
	/* 0x2267: jbe    227e <tail_policy_denied_ipv6+0x227e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_227e;
	}
x86_l_2269:
	/* 0x2269: add    rcx,0x24f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 591ULL);
x86_l_2270:
	/* 0x2270: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2273:
	/* 0x2273: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2279:
	/* 0x2279: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_227e:
	/* 0x227e: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2281:
	/* 0x2281: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2283:
	/* 0x2283: cmp    r14d,0x242 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 578ULL);
x86_l_228a:
	/* 0x228a: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2290:
	/* 0x2290: lea    rdi,[rcx+0x252] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 594ULL);
x86_l_2297:
	/* 0x2297: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_229a:
	/* 0x229a: jbe    22b1 <tail_policy_denied_ipv6+0x22b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_22b1;
	}
x86_l_229c:
	/* 0x229c: add    rcx,0x251 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 593ULL);
x86_l_22a3:
	/* 0x22a3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_22a6:
	/* 0x22a6: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_22ac:
	/* 0x22ac: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_22b1:
	/* 0x22b1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22b4:
	/* 0x22b4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22b6:
	/* 0x22b6: cmp    r14d,0x244 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 580ULL);
x86_l_22bd:
	/* 0x22bd: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_22c3:
	/* 0x22c3: lea    rsi,[rcx+0x254] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_22ca:
	/* 0x22ca: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_22cd:
	/* 0x22cd: jbe    22e4 <tail_policy_denied_ipv6+0x22e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_22e4;
	}
x86_l_22cf:
	/* 0x22cf: add    rcx,0x253 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 595ULL);
x86_l_22d6:
	/* 0x22d6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_22d9:
	/* 0x22d9: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_22df:
	/* 0x22df: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_22e4:
	/* 0x22e4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22e7:
	/* 0x22e7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22e9:
	/* 0x22e9: cmp    r14d,0x246 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 582ULL);
x86_l_22f0:
	/* 0x22f0: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_22f6:
	/* 0x22f6: lea    rdi,[rcx+0x256] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 598ULL);
x86_l_22fd:
	/* 0x22fd: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2300:
	/* 0x2300: jbe    2317 <tail_policy_denied_ipv6+0x2317> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2317;
	}
x86_l_2302:
	/* 0x2302: add    rcx,0x255 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 597ULL);
x86_l_2309:
	/* 0x2309: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_230c:
	/* 0x230c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2312:
	/* 0x2312: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2317:
	/* 0x2317: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_231a:
	/* 0x231a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_231c:
	/* 0x231c: cmp    r14d,0x248 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 584ULL);
x86_l_2323:
	/* 0x2323: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2329:
	/* 0x2329: lea    rsi,[rcx+0x258] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 600ULL);
x86_l_2330:
	/* 0x2330: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2333:
	/* 0x2333: jbe    234a <tail_policy_denied_ipv6+0x234a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_234a;
	}
x86_l_2335:
	/* 0x2335: add    rcx,0x257 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 599ULL);
x86_l_233c:
	/* 0x233c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2345:
	/* 0x2345: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_234a:
	/* 0x234a: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_234d:
	/* 0x234d: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_234f:
	/* 0x234f: cmp    r14d,0x24a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 586ULL);
x86_l_2356:
	/* 0x2356: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_235c:
	/* 0x235c: lea    rdi,[rcx+0x25a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 602ULL);
x86_l_2363:
	/* 0x2363: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2366:
	/* 0x2366: jbe    237d <tail_policy_denied_ipv6+0x237d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_237d;
	}
x86_l_2368:
	/* 0x2368: add    rcx,0x259 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 601ULL);
x86_l_236f:
	/* 0x236f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2372:
	/* 0x2372: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2378:
	/* 0x2378: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_237d:
	/* 0x237d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2380:
	/* 0x2380: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2382:
	/* 0x2382: cmp    r14d,0x24c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 588ULL);
x86_l_2389:
	/* 0x2389: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_238f:
	/* 0x238f: lea    rsi,[rcx+0x25c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 604ULL);
x86_l_2396:
	/* 0x2396: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2399:
	/* 0x2399: jbe    23b0 <tail_policy_denied_ipv6+0x23b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23b0;
	}
x86_l_239b:
	/* 0x239b: add    rcx,0x25b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 603ULL);
x86_l_23a2:
	/* 0x23a2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_23a5:
	/* 0x23a5: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_23ab:
	/* 0x23ab: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_23b0:
	/* 0x23b0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23b3:
	/* 0x23b3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23b5:
	/* 0x23b5: cmp    r14d,0x24e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 590ULL);
x86_l_23bc:
	/* 0x23bc: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_23c2:
	/* 0x23c2: lea    rdi,[rcx+0x25e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 606ULL);
x86_l_23c9:
	/* 0x23c9: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_23cc:
	/* 0x23cc: jbe    23e3 <tail_policy_denied_ipv6+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23e3;
	}
x86_l_23ce:
	/* 0x23ce: add    rcx,0x25d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 605ULL);
x86_l_23d5:
	/* 0x23d5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_23d8:
	/* 0x23d8: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_23de:
	/* 0x23de: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_23e3:
	/* 0x23e3: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23e6:
	/* 0x23e6: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23e8:
	/* 0x23e8: cmp    r14d,0x250 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 592ULL);
x86_l_23ef:
	/* 0x23ef: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_23f5:
	/* 0x23f5: lea    rsi,[rcx+0x260] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_23fc:
	/* 0x23fc: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_23ff:
	/* 0x23ff: jbe    2416 <tail_policy_denied_ipv6+0x2416> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2416;
	}
x86_l_2401:
	/* 0x2401: add    rcx,0x25f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 607ULL);
x86_l_2408:
	/* 0x2408: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_240b:
	/* 0x240b: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2411:
	/* 0x2411: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2416:
	/* 0x2416: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2419:
	/* 0x2419: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_241b:
	/* 0x241b: cmp    r14d,0x252 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 594ULL);
x86_l_2422:
	/* 0x2422: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2428:
	/* 0x2428: lea    rdi,[rcx+0x262] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 610ULL);
x86_l_242f:
	/* 0x242f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2432:
	/* 0x2432: jbe    2449 <tail_policy_denied_ipv6+0x2449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2449;
	}
x86_l_2434:
	/* 0x2434: add    rcx,0x261 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 609ULL);
x86_l_243b:
	/* 0x243b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_243e:
	/* 0x243e: ja     286d <tail_policy_denied_ipv6+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10349ULL;
	}
x86_l_2444:
	/* 0x2444: jmp    536 <tail_policy_denied_ipv6+0x536> */
	return 1334ULL;
x86_l_2449:
	/* 0x2449: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_244c:
	/* 0x244c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_244e:
	/* 0x244e: cmp    r14d,0x254 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 596ULL);
x86_l_2455:
	/* 0x2455: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_245b:
	/* 0x245b: lea    rsi,[rcx+0x264] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 612ULL);
x86_l_2462:
	/* 0x2462: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2465:
	/* 0x2465: jbe    247c <tail_policy_denied_ipv6+0x247c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_247c;
	}
x86_l_2467:
	/* 0x2467: add    rcx,0x263 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 611ULL);
x86_l_246e:
	/* 0x246e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2471:
	/* 0x2471: ja     286d <tail_policy_denied_ipv6+0x286d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10349ULL;
	}
x86_l_2477:
	/* 0x2477: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_247c:
	/* 0x247c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_247f:
	/* 0x247f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2481:
	/* 0x2481: cmp    r14d,0x256 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 598ULL);
x86_l_2488:
	/* 0x2488: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_248e:
	/* 0x248e: lea    rdi,[rcx+0x266] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 614ULL);
x86_l_2495:
	/* 0x2495: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2498:
	/* 0x2498: jbe    24af <tail_policy_denied_ipv6+0x24af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24af;
	}
x86_l_249a:
	/* 0x249a: add    rcx,0x265 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 613ULL);
x86_l_24a1:
	/* 0x24a1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_24a4:
	/* 0x24a4: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_24aa:
	/* 0x24aa: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_24af:
	/* 0x24af: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24b2:
	/* 0x24b2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24b4:
	/* 0x24b4: cmp    r14d,0x258 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 600ULL);
x86_l_24bb:
	/* 0x24bb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_24c1:
	/* 0x24c1: lea    rsi,[rcx+0x268] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_24c8:
	/* 0x24c8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_24cb:
	/* 0x24cb: jbe    24e2 <tail_policy_denied_ipv6+0x24e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24e2;
	}
x86_l_24cd:
	/* 0x24cd: add    rcx,0x267 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 615ULL);
x86_l_24d4:
	/* 0x24d4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_24d7:
	/* 0x24d7: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_24dd:
	/* 0x24dd: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_24e2:
	/* 0x24e2: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24e5:
	/* 0x24e5: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24e7:
	/* 0x24e7: cmp    r14d,0x25a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 602ULL);
x86_l_24ee:
	/* 0x24ee: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_24f4:
	/* 0x24f4: lea    rdi,[rcx+0x26a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618ULL);
x86_l_24fb:
	/* 0x24fb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_24fe:
	/* 0x24fe: jbe    2515 <tail_policy_denied_ipv6+0x2515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2515;
	}
x86_l_2500:
	/* 0x2500: add    rcx,0x269 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 617ULL);
x86_l_2507:
	/* 0x2507: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_250a:
	/* 0x250a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2510:
	/* 0x2510: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2515:
	/* 0x2515: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2518:
	/* 0x2518: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_251a:
	/* 0x251a: cmp    r14d,0x25c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 604ULL);
x86_l_2521:
	/* 0x2521: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2527:
	/* 0x2527: lea    rsi,[rcx+0x26c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_252e:
	/* 0x252e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2531:
	/* 0x2531: jbe    2548 <tail_policy_denied_ipv6+0x2548> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2548;
	}
x86_l_2533:
	/* 0x2533: add    rcx,0x26b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 619ULL);
x86_l_253a:
	/* 0x253a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_253d:
	/* 0x253d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2543:
	/* 0x2543: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2548:
	/* 0x2548: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_254b:
	/* 0x254b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_254d:
	/* 0x254d: cmp    r14d,0x25e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 606ULL);
x86_l_2554:
	/* 0x2554: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_255a:
	/* 0x255a: lea    rdi,[rcx+0x26e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 622ULL);
x86_l_2561:
	/* 0x2561: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2564:
	/* 0x2564: jbe    257b <tail_policy_denied_ipv6+0x257b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_257b;
	}
x86_l_2566:
	/* 0x2566: add    rcx,0x26d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 621ULL);
x86_l_256d:
	/* 0x256d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2570:
	/* 0x2570: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2576:
	/* 0x2576: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_257b:
	/* 0x257b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_257e:
	/* 0x257e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2580:
	/* 0x2580: cmp    r14d,0x260 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 608ULL);
x86_l_2587:
	/* 0x2587: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_258d:
	/* 0x258d: lea    rsi,[rcx+0x270] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 624ULL);
x86_l_2594:
	/* 0x2594: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2597:
	/* 0x2597: jbe    25ae <tail_policy_denied_ipv6+0x25ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_25ae;
	}
x86_l_2599:
	/* 0x2599: add    rcx,0x26f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 623ULL);
x86_l_25a0:
	/* 0x25a0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_25a3:
	/* 0x25a3: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_25a9:
	/* 0x25a9: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_25ae:
	/* 0x25ae: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25b1:
	/* 0x25b1: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25b3:
	/* 0x25b3: cmp    r14d,0x262 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 610ULL);
x86_l_25ba:
	/* 0x25ba: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_25c0:
	/* 0x25c0: lea    rdi,[rcx+0x272] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 626ULL);
x86_l_25c7:
	/* 0x25c7: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_25ca:
	/* 0x25ca: jbe    25e1 <tail_policy_denied_ipv6+0x25e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_25e1;
	}
x86_l_25cc:
	/* 0x25cc: add    rcx,0x271 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 625ULL);
x86_l_25d3:
	/* 0x25d3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_25d6:
	/* 0x25d6: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_25dc:
	/* 0x25dc: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_25e1:
	/* 0x25e1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25e4:
	/* 0x25e4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25e6:
	/* 0x25e6: cmp    r14d,0x264 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 612ULL);
x86_l_25ed:
	/* 0x25ed: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_25f3:
	/* 0x25f3: lea    rsi,[rcx+0x274] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 628ULL);
x86_l_25fa:
	/* 0x25fa: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_25fd:
	/* 0x25fd: jbe    2614 <tail_policy_denied_ipv6+0x2614> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2614;
	}
x86_l_25ff:
	/* 0x25ff: add    rcx,0x273 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 627ULL);
x86_l_2606:
	/* 0x2606: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2609:
	/* 0x2609: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_260f:
	/* 0x260f: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2614:
	/* 0x2614: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2617:
	/* 0x2617: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2619:
	/* 0x2619: cmp    r14d,0x266 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 614ULL);
x86_l_2620:
	/* 0x2620: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2626:
	/* 0x2626: lea    rdi,[rcx+0x276] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 630ULL);
x86_l_262d:
	/* 0x262d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2630:
	/* 0x2630: jbe    2647 <tail_policy_denied_ipv6+0x2647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2647;
	}
x86_l_2632:
	/* 0x2632: add    rcx,0x275 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 629ULL);
x86_l_2639:
	/* 0x2639: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_263c:
	/* 0x263c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2642:
	/* 0x2642: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_2647:
	/* 0x2647: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_264a:
	/* 0x264a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_264c:
	/* 0x264c: cmp    r14d,0x268 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 616ULL);
x86_l_2653:
	/* 0x2653: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2659:
	/* 0x2659: lea    rsi,[rcx+0x278] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 632ULL);
x86_l_2660:
	/* 0x2660: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2663:
	/* 0x2663: jbe    267a <tail_policy_denied_ipv6+0x267a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_267a;
	}
x86_l_2665:
	/* 0x2665: add    rcx,0x277 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 631ULL);
x86_l_266c:
	/* 0x266c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_266f:
	/* 0x266f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2675:
	/* 0x2675: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_267a:
	/* 0x267a: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_267d:
	/* 0x267d: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_267f:
	/* 0x267f: cmp    r14d,0x26a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 618ULL);
x86_l_2686:
	/* 0x2686: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_268c:
	/* 0x268c: lea    rdi,[rcx+0x27a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 634ULL);
x86_l_2693:
	/* 0x2693: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2696:
	/* 0x2696: jbe    26ad <tail_policy_denied_ipv6+0x26ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26ad;
	}
x86_l_2698:
	/* 0x2698: add    rcx,0x279 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 633ULL);
x86_l_269f:
	/* 0x269f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_26a2:
	/* 0x26a2: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_26a8:
	/* 0x26a8: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	return 10349ULL;
x86_l_26ad:
	/* 0x26ad: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26b0:
	/* 0x26b0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26b2:
	/* 0x26b2: cmp    r14d,0x26c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 620ULL);
x86_l_26b9:
	/* 0x26b9: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_26bf:
	/* 0x26bf: lea    rsi,[rcx+0x27c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 636ULL);
x86_l_26c6:
	/* 0x26c6: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_26c9:
	/* 0x26c9: jbe    26e0 <tail_policy_denied_ipv6+0x26e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9952ULL;
	}
x86_l_26cb:
	/* 0x26cb: add    rcx,0x27b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 635ULL);
x86_l_26d2:
	/* 0x26d2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_26d5:
	/* 0x26d5: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
	return 9947ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9957ULL: goto x86_l_26e5;
	case 9964ULL: goto x86_l_26ec;
	case 9970ULL: goto x86_l_26f2;
	case 9977ULL: goto x86_l_26f9;
	case 9980ULL: goto x86_l_26fc;
	case 9982ULL: goto x86_l_26fe;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10015ULL: goto x86_l_271f;
	case 10021ULL: goto x86_l_2725;
	case 10028ULL: goto x86_l_272c;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10040ULL: goto x86_l_2738;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10054ULL: goto x86_l_2746;
	case 10057ULL: goto x86_l_2749;
	case 10059ULL: goto x86_l_274b;
	case 10066ULL: goto x86_l_2752;
	case 10072ULL: goto x86_l_2758;
	case 10079ULL: goto x86_l_275f;
	case 10082ULL: goto x86_l_2762;
	case 10084ULL: goto x86_l_2764;
	case 10091ULL: goto x86_l_276b;
	case 10094ULL: goto x86_l_276e;
	case 10100ULL: goto x86_l_2774;
	case 10105ULL: goto x86_l_2779;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10117ULL: goto x86_l_2785;
	case 10123ULL: goto x86_l_278b;
	case 10130ULL: goto x86_l_2792;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10142ULL: goto x86_l_279e;
	case 10145ULL: goto x86_l_27a1;
	case 10151ULL: goto x86_l_27a7;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10168ULL: goto x86_l_27b8;
	case 10174ULL: goto x86_l_27be;
	case 10181ULL: goto x86_l_27c5;
	case 10184ULL: goto x86_l_27c8;
	case 10186ULL: goto x86_l_27ca;
	case 10193ULL: goto x86_l_27d1;
	case 10196ULL: goto x86_l_27d4;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10219ULL: goto x86_l_27eb;
	case 10225ULL: goto x86_l_27f1;
	case 10232ULL: goto x86_l_27f8;
	case 10235ULL: goto x86_l_27fb;
	case 10237ULL: goto x86_l_27fd;
	case 10244ULL: goto x86_l_2804;
	case 10247ULL: goto x86_l_2807;
	case 10253ULL: goto x86_l_280d;
	case 10255ULL: goto x86_l_280f;
	case 10258ULL: goto x86_l_2812;
	case 10260ULL: goto x86_l_2814;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10280ULL: goto x86_l_2828;
	case 10283ULL: goto x86_l_282b;
	case 10285ULL: goto x86_l_282d;
	case 10292ULL: goto x86_l_2834;
	case 10295ULL: goto x86_l_2837;
	case 10301ULL: goto x86_l_283d;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10308ULL: goto x86_l_2844;
	case 10315ULL: goto x86_l_284b;
	case 10321ULL: goto x86_l_2851;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10340ULL: goto x86_l_2864;
	case 10343ULL: goto x86_l_2867;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10357ULL: goto x86_l_2875;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10369ULL: goto x86_l_2881;
	case 10375ULL: goto x86_l_2887;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10394ULL: goto x86_l_289a;
	case 10397ULL: goto x86_l_289d;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10411ULL: goto x86_l_28ab;
	case 10413ULL: goto x86_l_28ad;
	case 10420ULL: goto x86_l_28b4;
	case 10426ULL: goto x86_l_28ba;
	case 10433ULL: goto x86_l_28c1;
	case 10436ULL: goto x86_l_28c4;
	case 10438ULL: goto x86_l_28c6;
	case 10445ULL: goto x86_l_28cd;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10473ULL: goto x86_l_28e9;
	case 10475ULL: goto x86_l_28eb;
	case 10482ULL: goto x86_l_28f2;
	case 10488ULL: goto x86_l_28f8;
	case 10495ULL: goto x86_l_28ff;
	case 10498ULL: goto x86_l_2902;
	case 10500ULL: goto x86_l_2904;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10524ULL: goto x86_l_291c;
	case 10526ULL: goto x86_l_291e;
	case 10533ULL: goto x86_l_2925;
	case 10539ULL: goto x86_l_292b;
	case 10546ULL: goto x86_l_2932;
	case 10549ULL: goto x86_l_2935;
	case 10551ULL: goto x86_l_2937;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10575ULL: goto x86_l_294f;
	case 10577ULL: goto x86_l_2951;
	case 10584ULL: goto x86_l_2958;
	case 10590ULL: goto x86_l_295e;
	case 10597ULL: goto x86_l_2965;
	case 10600ULL: goto x86_l_2968;
	case 10602ULL: goto x86_l_296a;
	case 10609ULL: goto x86_l_2971;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10628ULL: goto x86_l_2984;
	case 10635ULL: goto x86_l_298b;
	case 10641ULL: goto x86_l_2991;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10653ULL: goto x86_l_299d;
	case 10660ULL: goto x86_l_29a4;
	case 10663ULL: goto x86_l_29a7;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10677ULL: goto x86_l_29b5;
	case 10679ULL: goto x86_l_29b7;
	case 10686ULL: goto x86_l_29be;
	case 10692ULL: goto x86_l_29c4;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10704ULL: goto x86_l_29d0;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10728ULL: goto x86_l_29e8;
	case 10730ULL: goto x86_l_29ea;
	case 10737ULL: goto x86_l_29f1;
	case 10743ULL: goto x86_l_29f7;
	case 10750ULL: goto x86_l_29fe;
	case 10753ULL: goto x86_l_2a01;
	case 10755ULL: goto x86_l_2a03;
	case 10762ULL: goto x86_l_2a0a;
	case 10765ULL: goto x86_l_2a0d;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10779ULL: goto x86_l_2a1b;
	case 10781ULL: goto x86_l_2a1d;
	case 10788ULL: goto x86_l_2a24;
	case 10794ULL: goto x86_l_2a2a;
	case 10801ULL: goto x86_l_2a31;
	case 10804ULL: goto x86_l_2a34;
	case 10806ULL: goto x86_l_2a36;
	case 10813ULL: goto x86_l_2a3d;
	case 10816ULL: goto x86_l_2a40;
	case 10822ULL: goto x86_l_2a46;
	case 10827ULL: goto x86_l_2a4b;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10839ULL: goto x86_l_2a57;
	case 10845ULL: goto x86_l_2a5d;
	case 10852ULL: goto x86_l_2a64;
	case 10855ULL: goto x86_l_2a67;
	case 10857ULL: goto x86_l_2a69;
	case 10864ULL: goto x86_l_2a70;
	case 10867ULL: goto x86_l_2a73;
	case 10873ULL: goto x86_l_2a79;
	case 10878ULL: goto x86_l_2a7e;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10890ULL: goto x86_l_2a8a;
	case 10896ULL: goto x86_l_2a90;
	case 10903ULL: goto x86_l_2a97;
	case 10906ULL: goto x86_l_2a9a;
	case 10908ULL: goto x86_l_2a9c;
	case 10915ULL: goto x86_l_2aa3;
	case 10918ULL: goto x86_l_2aa6;
	case 10924ULL: goto x86_l_2aac;
	case 10929ULL: goto x86_l_2ab1;
	case 10932ULL: goto x86_l_2ab4;
	case 10934ULL: goto x86_l_2ab6;
	case 10941ULL: goto x86_l_2abd;
	case 10947ULL: goto x86_l_2ac3;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10998ULL: goto x86_l_2af6;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11017ULL: goto x86_l_2b09;
	case 11020ULL: goto x86_l_2b0c;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11034ULL: goto x86_l_2b1a;
	case 11036ULL: goto x86_l_2b1c;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11061ULL: goto x86_l_2b35;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11085ULL: goto x86_l_2b4d;
	case 11087ULL: goto x86_l_2b4f;
	case 11094ULL: goto x86_l_2b56;
	case 11100ULL: goto x86_l_2b5c;
	case 11107ULL: goto x86_l_2b63;
	case 11110ULL: goto x86_l_2b66;
	case 11112ULL: goto x86_l_2b68;
	case 11119ULL: goto x86_l_2b6f;
	case 11122ULL: goto x86_l_2b72;
	case 11128ULL: goto x86_l_2b78;
	case 11133ULL: goto x86_l_2b7d;
	case 11136ULL: goto x86_l_2b80;
	case 11138ULL: goto x86_l_2b82;
	case 11145ULL: goto x86_l_2b89;
	case 11151ULL: goto x86_l_2b8f;
	case 11158ULL: goto x86_l_2b96;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11170ULL: goto x86_l_2ba2;
	case 11173ULL: goto x86_l_2ba5;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11196ULL: goto x86_l_2bbc;
	case 11202ULL: goto x86_l_2bc2;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11214ULL: goto x86_l_2bce;
	case 11221ULL: goto x86_l_2bd5;
	case 11224ULL: goto x86_l_2bd8;
	case 11230ULL: goto x86_l_2bde;
	case 11235ULL: goto x86_l_2be3;
	case 11238ULL: goto x86_l_2be6;
	case 11240ULL: goto x86_l_2be8;
	case 11247ULL: goto x86_l_2bef;
	case 11253ULL: goto x86_l_2bf5;
	case 11260ULL: goto x86_l_2bfc;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11272ULL: goto x86_l_2c08;
	case 11275ULL: goto x86_l_2c0b;
	case 11281ULL: goto x86_l_2c11;
	case 11286ULL: goto x86_l_2c16;
	case 11289ULL: goto x86_l_2c19;
	case 11291ULL: goto x86_l_2c1b;
	case 11298ULL: goto x86_l_2c22;
	case 11304ULL: goto x86_l_2c28;
	case 11311ULL: goto x86_l_2c2f;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11332ULL: goto x86_l_2c44;
	case 11337ULL: goto x86_l_2c49;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11349ULL: goto x86_l_2c55;
	case 11355ULL: goto x86_l_2c5b;
	case 11362ULL: goto x86_l_2c62;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11374ULL: goto x86_l_2c6e;
	case 11377ULL: goto x86_l_2c71;
	case 11383ULL: goto x86_l_2c77;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11400ULL: goto x86_l_2c88;
	case 11406ULL: goto x86_l_2c8e;
	case 11413ULL: goto x86_l_2c95;
	case 11416ULL: goto x86_l_2c98;
	case 11418ULL: goto x86_l_2c9a;
	case 11425ULL: goto x86_l_2ca1;
	case 11428ULL: goto x86_l_2ca4;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11442ULL: goto x86_l_2cb2;
	case 11444ULL: goto x86_l_2cb4;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11464ULL: goto x86_l_2cc8;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11476ULL: goto x86_l_2cd4;
	case 11479ULL: goto x86_l_2cd7;
	case 11485ULL: goto x86_l_2cdd;
	case 11490ULL: goto x86_l_2ce2;
	case 11493ULL: goto x86_l_2ce5;
	case 11495ULL: goto x86_l_2ce7;
	case 11502ULL: goto x86_l_2cee;
	case 11508ULL: goto x86_l_2cf4;
	case 11515ULL: goto x86_l_2cfb;
	case 11518ULL: goto x86_l_2cfe;
	case 11520ULL: goto x86_l_2d00;
	case 11527ULL: goto x86_l_2d07;
	case 11530ULL: goto x86_l_2d0a;
	case 11536ULL: goto x86_l_2d10;
	case 11541ULL: goto x86_l_2d15;
	case 11544ULL: goto x86_l_2d18;
	case 11546ULL: goto x86_l_2d1a;
	case 11553ULL: goto x86_l_2d21;
	case 11559ULL: goto x86_l_2d27;
	case 11566ULL: goto x86_l_2d2e;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11578ULL: goto x86_l_2d3a;
	case 11581ULL: goto x86_l_2d3d;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11595ULL: goto x86_l_2d4b;
	case 11597ULL: goto x86_l_2d4d;
	case 11604ULL: goto x86_l_2d54;
	case 11610ULL: goto x86_l_2d5a;
	case 11617ULL: goto x86_l_2d61;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11629ULL: goto x86_l_2d6d;
	case 11632ULL: goto x86_l_2d70;
	case 11638ULL: goto x86_l_2d76;
	case 11643ULL: goto x86_l_2d7b;
	case 11646ULL: goto x86_l_2d7e;
	case 11648ULL: goto x86_l_2d80;
	case 11655ULL: goto x86_l_2d87;
	case 11661ULL: goto x86_l_2d8d;
	case 11668ULL: goto x86_l_2d94;
	case 11671ULL: goto x86_l_2d97;
	case 11673ULL: goto x86_l_2d99;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11719ULL: goto x86_l_2dc7;
	case 11722ULL: goto x86_l_2dca;
	default: return 0xffffffffffffffffULL;
	}
x86_l_26db:
	/* 0x26db: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_26e0:
	/* 0x26e0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26e3:
	/* 0x26e3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26e5:
	/* 0x26e5: cmp    r14d,0x26e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 622ULL);
x86_l_26ec:
	/* 0x26ec: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_26f2:
	/* 0x26f2: lea    rdi,[rcx+0x27e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 638ULL);
x86_l_26f9:
	/* 0x26f9: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_26fc:
	/* 0x26fc: jbe    2713 <tail_policy_denied_ipv6+0x2713> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2713;
	}
x86_l_26fe:
	/* 0x26fe: add    rcx,0x27d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 637ULL);
x86_l_2705:
	/* 0x2705: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2708:
	/* 0x2708: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_270e:
	/* 0x270e: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_2713:
	/* 0x2713: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2716:
	/* 0x2716: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2718:
	/* 0x2718: cmp    r14d,0x270 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 624ULL);
x86_l_271f:
	/* 0x271f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2725:
	/* 0x2725: lea    rsi,[rcx+0x280] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 640ULL);
x86_l_272c:
	/* 0x272c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_272f:
	/* 0x272f: jbe    2746 <tail_policy_denied_ipv6+0x2746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2746;
	}
x86_l_2731:
	/* 0x2731: add    rcx,0x27f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 639ULL);
x86_l_2738:
	/* 0x2738: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_273b:
	/* 0x273b: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2741:
	/* 0x2741: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_2746:
	/* 0x2746: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2749:
	/* 0x2749: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_274b:
	/* 0x274b: cmp    r14d,0x272 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 626ULL);
x86_l_2752:
	/* 0x2752: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2758:
	/* 0x2758: lea    rdi,[rcx+0x282] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 642ULL);
x86_l_275f:
	/* 0x275f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2762:
	/* 0x2762: jbe    2779 <tail_policy_denied_ipv6+0x2779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2779;
	}
x86_l_2764:
	/* 0x2764: add    rcx,0x281 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 641ULL);
x86_l_276b:
	/* 0x276b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_276e:
	/* 0x276e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2774:
	/* 0x2774: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_2779:
	/* 0x2779: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_277c:
	/* 0x277c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_277e:
	/* 0x277e: cmp    r14d,0x274 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 628ULL);
x86_l_2785:
	/* 0x2785: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_278b:
	/* 0x278b: lea    rsi,[rcx+0x284] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 644ULL);
x86_l_2792:
	/* 0x2792: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2795:
	/* 0x2795: jbe    27ac <tail_policy_denied_ipv6+0x27ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_27ac;
	}
x86_l_2797:
	/* 0x2797: add    rcx,0x283 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 643ULL);
x86_l_279e:
	/* 0x279e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_27a1:
	/* 0x27a1: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_27a7:
	/* 0x27a7: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_27ac:
	/* 0x27ac: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27af:
	/* 0x27af: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27b1:
	/* 0x27b1: cmp    r14d,0x276 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 630ULL);
x86_l_27b8:
	/* 0x27b8: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_27be:
	/* 0x27be: lea    rdi,[rcx+0x286] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 646ULL);
x86_l_27c5:
	/* 0x27c5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_27c8:
	/* 0x27c8: jbe    27df <tail_policy_denied_ipv6+0x27df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_27df;
	}
x86_l_27ca:
	/* 0x27ca: add    rcx,0x285 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 645ULL);
x86_l_27d1:
	/* 0x27d1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_27d4:
	/* 0x27d4: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_27da:
	/* 0x27da: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_27df:
	/* 0x27df: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27e2:
	/* 0x27e2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27e4:
	/* 0x27e4: cmp    r14d,0x278 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 632ULL);
x86_l_27eb:
	/* 0x27eb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_27f1:
	/* 0x27f1: lea    rsi,[rcx+0x288] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 648ULL);
x86_l_27f8:
	/* 0x27f8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_27fb:
	/* 0x27fb: jbe    280f <tail_policy_denied_ipv6+0x280f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_280f;
	}
x86_l_27fd:
	/* 0x27fd: add    rcx,0x287 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 647ULL);
x86_l_2804:
	/* 0x2804: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2807:
	/* 0x2807: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_280d:
	/* 0x280d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_280f:
	/* 0x280f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2812:
	/* 0x2812: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2814:
	/* 0x2814: cmp    r14d,0x27a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 634ULL);
x86_l_281b:
	/* 0x281b: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2821:
	/* 0x2821: lea    rdi,[rcx+0x28a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 650ULL);
x86_l_2828:
	/* 0x2828: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_282b:
	/* 0x282b: jbe    283f <tail_policy_denied_ipv6+0x283f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_283f;
	}
x86_l_282d:
	/* 0x282d: add    rcx,0x289 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 649ULL);
x86_l_2834:
	/* 0x2834: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2837:
	/* 0x2837: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_283d:
	/* 0x283d: jmp    286d <tail_policy_denied_ipv6+0x286d> */
	goto x86_l_286d;
x86_l_283f:
	/* 0x283f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2842:
	/* 0x2842: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2844:
	/* 0x2844: cmp    r14d,0x27c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 636ULL);
x86_l_284b:
	/* 0x284b: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2851:
	/* 0x2851: lea    rsi,[rcx+0x28c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652ULL);
x86_l_2858:
	/* 0x2858: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_285b:
	/* 0x285b: jbe    2875 <tail_policy_denied_ipv6+0x2875> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2875;
	}
x86_l_285d:
	/* 0x285d: add    rcx,0x28b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 651ULL);
x86_l_2864:
	/* 0x2864: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2867:
	/* 0x2867: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_286d:
	/* 0x286d: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_2870:
	/* 0x2870: jmp    245 <tail_policy_denied_ipv6+0x245> */
	return 581ULL;
x86_l_2875:
	/* 0x2875: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2878:
	/* 0x2878: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_287a:
	/* 0x287a: cmp    r14d,0x27e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 638ULL);
x86_l_2881:
	/* 0x2881: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2887:
	/* 0x2887: lea    rdi,[rcx+0x28e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 654ULL);
x86_l_288e:
	/* 0x288e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2891:
	/* 0x2891: jbe    28a8 <tail_policy_denied_ipv6+0x28a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_28a8;
	}
x86_l_2893:
	/* 0x2893: add    rcx,0x28d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 653ULL);
x86_l_289a:
	/* 0x289a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_289d:
	/* 0x289d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_28a3:
	/* 0x28a3: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_28a8:
	/* 0x28a8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28ab:
	/* 0x28ab: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28ad:
	/* 0x28ad: cmp    r14d,0x300 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 768ULL);
x86_l_28b4:
	/* 0x28b4: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_28ba:
	/* 0x28ba: lea    rsi,[rcx+0x310] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 784ULL);
x86_l_28c1:
	/* 0x28c1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_28c4:
	/* 0x28c4: jbe    28e2 <tail_policy_denied_ipv6+0x28e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_28e2;
	}
x86_l_28c6:
	/* 0x28c6: lea    rsi,[rcx+0x30f] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 783ULL);
x86_l_28cd:
	/* 0x28cd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_28d0:
	/* 0x28d0: ja     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 16931ULL;
	}
x86_l_28d6:
	/* 0x28d6: movzx  ecx,BYTE PTR [rcx+0x30e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 782ULL);
x86_l_28dd:
	/* 0x28dd: jmp    539 <tail_policy_denied_ipv6+0x539> */
	return 1337ULL;
x86_l_28e2:
	/* 0x28e2: movzx  edi,WORD PTR [rcx+0x30e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 782ULL);
x86_l_28e9:
	/* 0x28e9: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28eb:
	/* 0x28eb: cmp    r14d,0x302 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 770ULL);
x86_l_28f2:
	/* 0x28f2: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_28f8:
	/* 0x28f8: lea    rdi,[rcx+0x312] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 786ULL);
x86_l_28ff:
	/* 0x28ff: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2902:
	/* 0x2902: jbe    2919 <tail_policy_denied_ipv6+0x2919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2919;
	}
x86_l_2904:
	/* 0x2904: add    rcx,0x311 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 785ULL);
x86_l_290b:
	/* 0x290b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_290e:
	/* 0x290e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2914:
	/* 0x2914: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2919:
	/* 0x2919: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_291c:
	/* 0x291c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_291e:
	/* 0x291e: cmp    r14d,0x304 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 772ULL);
x86_l_2925:
	/* 0x2925: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_292b:
	/* 0x292b: lea    rsi,[rcx+0x314] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 788ULL);
x86_l_2932:
	/* 0x2932: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2935:
	/* 0x2935: jbe    294c <tail_policy_denied_ipv6+0x294c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_294c;
	}
x86_l_2937:
	/* 0x2937: add    rcx,0x313 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 787ULL);
x86_l_293e:
	/* 0x293e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2941:
	/* 0x2941: ja     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 16931ULL;
	}
x86_l_2947:
	/* 0x2947: jmp    510 <tail_policy_denied_ipv6+0x510> */
	return 1296ULL;
x86_l_294c:
	/* 0x294c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_294f:
	/* 0x294f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2951:
	/* 0x2951: cmp    r14d,0x306 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 774ULL);
x86_l_2958:
	/* 0x2958: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_295e:
	/* 0x295e: lea    rdi,[rcx+0x316] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790ULL);
x86_l_2965:
	/* 0x2965: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2968:
	/* 0x2968: jbe    297f <tail_policy_denied_ipv6+0x297f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_297f;
	}
x86_l_296a:
	/* 0x296a: add    rcx,0x315 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 789ULL);
x86_l_2971:
	/* 0x2971: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2974:
	/* 0x2974: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_297a:
	/* 0x297a: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_297f:
	/* 0x297f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2982:
	/* 0x2982: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2984:
	/* 0x2984: cmp    r14d,0x308 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 776ULL);
x86_l_298b:
	/* 0x298b: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2991:
	/* 0x2991: lea    rsi,[rcx+0x318] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 792ULL);
x86_l_2998:
	/* 0x2998: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_299b:
	/* 0x299b: jbe    29b2 <tail_policy_denied_ipv6+0x29b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29b2;
	}
x86_l_299d:
	/* 0x299d: add    rcx,0x317 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 791ULL);
x86_l_29a4:
	/* 0x29a4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_29a7:
	/* 0x29a7: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_29ad:
	/* 0x29ad: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_29b2:
	/* 0x29b2: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29b5:
	/* 0x29b5: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_29b7:
	/* 0x29b7: cmp    r14d,0x30a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 778ULL);
x86_l_29be:
	/* 0x29be: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_29c4:
	/* 0x29c4: lea    rdi,[rcx+0x31a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 794ULL);
x86_l_29cb:
	/* 0x29cb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_29ce:
	/* 0x29ce: jbe    29e5 <tail_policy_denied_ipv6+0x29e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29e5;
	}
x86_l_29d0:
	/* 0x29d0: add    rcx,0x319 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 793ULL);
x86_l_29d7:
	/* 0x29d7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_29da:
	/* 0x29da: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_29e0:
	/* 0x29e0: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_29e5:
	/* 0x29e5: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29e8:
	/* 0x29e8: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_29ea:
	/* 0x29ea: cmp    r14d,0x30c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 780ULL);
x86_l_29f1:
	/* 0x29f1: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_29f7:
	/* 0x29f7: lea    rsi,[rcx+0x31c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 796ULL);
x86_l_29fe:
	/* 0x29fe: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2a01:
	/* 0x2a01: jbe    2a18 <tail_policy_denied_ipv6+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a18;
	}
x86_l_2a03:
	/* 0x2a03: add    rcx,0x31b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 795ULL);
x86_l_2a0a:
	/* 0x2a0a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2a0d:
	/* 0x2a0d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2a13:
	/* 0x2a13: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2a18:
	/* 0x2a18: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a1b:
	/* 0x2a1b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a1d:
	/* 0x2a1d: cmp    r14d,0x30e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 782ULL);
x86_l_2a24:
	/* 0x2a24: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2a2a:
	/* 0x2a2a: lea    rdi,[rcx+0x31e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 798ULL);
x86_l_2a31:
	/* 0x2a31: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2a34:
	/* 0x2a34: jbe    2a4b <tail_policy_denied_ipv6+0x2a4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a4b;
	}
x86_l_2a36:
	/* 0x2a36: add    rcx,0x31d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 797ULL);
x86_l_2a3d:
	/* 0x2a3d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2a40:
	/* 0x2a40: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2a46:
	/* 0x2a46: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2a4b:
	/* 0x2a4b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a4e:
	/* 0x2a4e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a50:
	/* 0x2a50: cmp    r14d,0x310 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 784ULL);
x86_l_2a57:
	/* 0x2a57: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2a5d:
	/* 0x2a5d: lea    rsi,[rcx+0x320] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 800ULL);
x86_l_2a64:
	/* 0x2a64: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2a67:
	/* 0x2a67: jbe    2a7e <tail_policy_denied_ipv6+0x2a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a7e;
	}
x86_l_2a69:
	/* 0x2a69: add    rcx,0x31f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 799ULL);
x86_l_2a70:
	/* 0x2a70: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2a73:
	/* 0x2a73: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2a79:
	/* 0x2a79: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2a7e:
	/* 0x2a7e: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a81:
	/* 0x2a81: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a83:
	/* 0x2a83: cmp    r14d,0x312 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 786ULL);
x86_l_2a8a:
	/* 0x2a8a: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2a90:
	/* 0x2a90: lea    rdi,[rcx+0x322] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 802ULL);
x86_l_2a97:
	/* 0x2a97: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2a9a:
	/* 0x2a9a: jbe    2ab1 <tail_policy_denied_ipv6+0x2ab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ab1;
	}
x86_l_2a9c:
	/* 0x2a9c: add    rcx,0x321 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 801ULL);
x86_l_2aa3:
	/* 0x2aa3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2aa6:
	/* 0x2aa6: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2aac:
	/* 0x2aac: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2ab1:
	/* 0x2ab1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ab4:
	/* 0x2ab4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ab6:
	/* 0x2ab6: cmp    r14d,0x314 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 788ULL);
x86_l_2abd:
	/* 0x2abd: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2ac3:
	/* 0x2ac3: lea    rsi,[rcx+0x324] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 804ULL);
x86_l_2aca:
	/* 0x2aca: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2acd:
	/* 0x2acd: jbe    2ae4 <tail_policy_denied_ipv6+0x2ae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ae4;
	}
x86_l_2acf:
	/* 0x2acf: add    rcx,0x323 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 803ULL);
x86_l_2ad6:
	/* 0x2ad6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ad9:
	/* 0x2ad9: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2adf:
	/* 0x2adf: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2ae4:
	/* 0x2ae4: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ae7:
	/* 0x2ae7: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ae9:
	/* 0x2ae9: cmp    r14d,0x316 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 790ULL);
x86_l_2af0:
	/* 0x2af0: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2af6:
	/* 0x2af6: lea    rdi,[rcx+0x326] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 806ULL);
x86_l_2afd:
	/* 0x2afd: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2b00:
	/* 0x2b00: jbe    2b17 <tail_policy_denied_ipv6+0x2b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b17;
	}
x86_l_2b02:
	/* 0x2b02: add    rcx,0x325 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 805ULL);
x86_l_2b09:
	/* 0x2b09: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2b0c:
	/* 0x2b0c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2b12:
	/* 0x2b12: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2b17:
	/* 0x2b17: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b1a:
	/* 0x2b1a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b1c:
	/* 0x2b1c: cmp    r14d,0x318 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 792ULL);
x86_l_2b23:
	/* 0x2b23: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2b29:
	/* 0x2b29: lea    rsi,[rcx+0x328] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 808ULL);
x86_l_2b30:
	/* 0x2b30: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2b33:
	/* 0x2b33: jbe    2b4a <tail_policy_denied_ipv6+0x2b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b4a;
	}
x86_l_2b35:
	/* 0x2b35: add    rcx,0x327 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 807ULL);
x86_l_2b3c:
	/* 0x2b3c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2b3f:
	/* 0x2b3f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2b45:
	/* 0x2b45: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2b4a:
	/* 0x2b4a: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b4d:
	/* 0x2b4d: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b4f:
	/* 0x2b4f: cmp    r14d,0x31a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 794ULL);
x86_l_2b56:
	/* 0x2b56: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2b5c:
	/* 0x2b5c: lea    rdi,[rcx+0x32a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 810ULL);
x86_l_2b63:
	/* 0x2b63: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2b66:
	/* 0x2b66: jbe    2b7d <tail_policy_denied_ipv6+0x2b7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2b7d;
	}
x86_l_2b68:
	/* 0x2b68: add    rcx,0x329 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 809ULL);
x86_l_2b6f:
	/* 0x2b6f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2b72:
	/* 0x2b72: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2b78:
	/* 0x2b78: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2b7d:
	/* 0x2b7d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b80:
	/* 0x2b80: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b82:
	/* 0x2b82: cmp    r14d,0x31c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 796ULL);
x86_l_2b89:
	/* 0x2b89: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2b8f:
	/* 0x2b8f: lea    rsi,[rcx+0x32c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 812ULL);
x86_l_2b96:
	/* 0x2b96: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2b99:
	/* 0x2b99: jbe    2bb0 <tail_policy_denied_ipv6+0x2bb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2bb0;
	}
x86_l_2b9b:
	/* 0x2b9b: add    rcx,0x32b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 811ULL);
x86_l_2ba2:
	/* 0x2ba2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ba5:
	/* 0x2ba5: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2bab:
	/* 0x2bab: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2bb0:
	/* 0x2bb0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bb3:
	/* 0x2bb3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2bb5:
	/* 0x2bb5: cmp    r14d,0x31e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 798ULL);
x86_l_2bbc:
	/* 0x2bbc: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2bc2:
	/* 0x2bc2: lea    rdi,[rcx+0x32e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 814ULL);
x86_l_2bc9:
	/* 0x2bc9: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2bcc:
	/* 0x2bcc: jbe    2be3 <tail_policy_denied_ipv6+0x2be3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2be3;
	}
x86_l_2bce:
	/* 0x2bce: add    rcx,0x32d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 813ULL);
x86_l_2bd5:
	/* 0x2bd5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2bd8:
	/* 0x2bd8: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2bde:
	/* 0x2bde: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2be3:
	/* 0x2be3: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2be6:
	/* 0x2be6: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2be8:
	/* 0x2be8: cmp    r14d,0x320 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 800ULL);
x86_l_2bef:
	/* 0x2bef: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2bf5:
	/* 0x2bf5: lea    rsi,[rcx+0x330] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 816ULL);
x86_l_2bfc:
	/* 0x2bfc: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2bff:
	/* 0x2bff: jbe    2c16 <tail_policy_denied_ipv6+0x2c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c16;
	}
x86_l_2c01:
	/* 0x2c01: add    rcx,0x32f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 815ULL);
x86_l_2c08:
	/* 0x2c08: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2c0b:
	/* 0x2c0b: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2c11:
	/* 0x2c11: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2c16:
	/* 0x2c16: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c19:
	/* 0x2c19: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c1b:
	/* 0x2c1b: cmp    r14d,0x322 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 802ULL);
x86_l_2c22:
	/* 0x2c22: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2c28:
	/* 0x2c28: lea    rdi,[rcx+0x332] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 818ULL);
x86_l_2c2f:
	/* 0x2c2f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2c32:
	/* 0x2c32: jbe    2c49 <tail_policy_denied_ipv6+0x2c49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c49;
	}
x86_l_2c34:
	/* 0x2c34: add    rcx,0x331 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 817ULL);
x86_l_2c3b:
	/* 0x2c3b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2c3e:
	/* 0x2c3e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2c44:
	/* 0x2c44: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2c49:
	/* 0x2c49: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c4c:
	/* 0x2c4c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c4e:
	/* 0x2c4e: cmp    r14d,0x324 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 804ULL);
x86_l_2c55:
	/* 0x2c55: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2c5b:
	/* 0x2c5b: lea    rsi,[rcx+0x334] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 820ULL);
x86_l_2c62:
	/* 0x2c62: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2c65:
	/* 0x2c65: jbe    2c7c <tail_policy_denied_ipv6+0x2c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c7c;
	}
x86_l_2c67:
	/* 0x2c67: add    rcx,0x333 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 819ULL);
x86_l_2c6e:
	/* 0x2c6e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2c71:
	/* 0x2c71: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2c77:
	/* 0x2c77: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2c7c:
	/* 0x2c7c: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c7f:
	/* 0x2c7f: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c81:
	/* 0x2c81: cmp    r14d,0x326 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 806ULL);
x86_l_2c88:
	/* 0x2c88: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2c8e:
	/* 0x2c8e: lea    rdi,[rcx+0x336] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 822ULL);
x86_l_2c95:
	/* 0x2c95: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2c98:
	/* 0x2c98: jbe    2caf <tail_policy_denied_ipv6+0x2caf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2caf;
	}
x86_l_2c9a:
	/* 0x2c9a: add    rcx,0x335 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 821ULL);
x86_l_2ca1:
	/* 0x2ca1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ca4:
	/* 0x2ca4: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2caa:
	/* 0x2caa: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2caf:
	/* 0x2caf: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cb2:
	/* 0x2cb2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2cb4:
	/* 0x2cb4: cmp    r14d,0x328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 808ULL);
x86_l_2cbb:
	/* 0x2cbb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2cc1:
	/* 0x2cc1: lea    rsi,[rcx+0x338] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824ULL);
x86_l_2cc8:
	/* 0x2cc8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2ccb:
	/* 0x2ccb: jbe    2ce2 <tail_policy_denied_ipv6+0x2ce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ce2;
	}
x86_l_2ccd:
	/* 0x2ccd: add    rcx,0x337 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 823ULL);
x86_l_2cd4:
	/* 0x2cd4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2cd7:
	/* 0x2cd7: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2cdd:
	/* 0x2cdd: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2ce2:
	/* 0x2ce2: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ce5:
	/* 0x2ce5: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ce7:
	/* 0x2ce7: cmp    r14d,0x32a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 810ULL);
x86_l_2cee:
	/* 0x2cee: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2cf4:
	/* 0x2cf4: lea    rdi,[rcx+0x33a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 826ULL);
x86_l_2cfb:
	/* 0x2cfb: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2cfe:
	/* 0x2cfe: jbe    2d15 <tail_policy_denied_ipv6+0x2d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d15;
	}
x86_l_2d00:
	/* 0x2d00: add    rcx,0x339 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 825ULL);
x86_l_2d07:
	/* 0x2d07: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2d0a:
	/* 0x2d0a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2d10:
	/* 0x2d10: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2d15:
	/* 0x2d15: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d18:
	/* 0x2d18: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d1a:
	/* 0x2d1a: cmp    r14d,0x32c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 812ULL);
x86_l_2d21:
	/* 0x2d21: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2d27:
	/* 0x2d27: lea    rsi,[rcx+0x33c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 828ULL);
x86_l_2d2e:
	/* 0x2d2e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2d31:
	/* 0x2d31: jbe    2d48 <tail_policy_denied_ipv6+0x2d48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d48;
	}
x86_l_2d33:
	/* 0x2d33: add    rcx,0x33b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 827ULL);
x86_l_2d3a:
	/* 0x2d3a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2d3d:
	/* 0x2d3d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2d43:
	/* 0x2d43: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2d48:
	/* 0x2d48: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d4b:
	/* 0x2d4b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d4d:
	/* 0x2d4d: cmp    r14d,0x32e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 814ULL);
x86_l_2d54:
	/* 0x2d54: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2d5a:
	/* 0x2d5a: lea    rdi,[rcx+0x33e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 830ULL);
x86_l_2d61:
	/* 0x2d61: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2d64:
	/* 0x2d64: jbe    2d7b <tail_policy_denied_ipv6+0x2d7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d7b;
	}
x86_l_2d66:
	/* 0x2d66: add    rcx,0x33d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 829ULL);
x86_l_2d6d:
	/* 0x2d6d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2d70:
	/* 0x2d70: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2d76:
	/* 0x2d76: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2d7b:
	/* 0x2d7b: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d7e:
	/* 0x2d7e: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d80:
	/* 0x2d80: cmp    r14d,0x330 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 816ULL);
x86_l_2d87:
	/* 0x2d87: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2d8d:
	/* 0x2d8d: lea    rsi,[rcx+0x340] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 832ULL);
x86_l_2d94:
	/* 0x2d94: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2d97:
	/* 0x2d97: jbe    2dae <tail_policy_denied_ipv6+0x2dae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dae;
	}
x86_l_2d99:
	/* 0x2d99: add    rcx,0x33f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 831ULL);
x86_l_2da0:
	/* 0x2da0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2da3:
	/* 0x2da3: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2da9:
	/* 0x2da9: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2dae:
	/* 0x2dae: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2db1:
	/* 0x2db1: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2db3:
	/* 0x2db3: cmp    r14d,0x332 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 818ULL);
x86_l_2dba:
	/* 0x2dba: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2dc0:
	/* 0x2dc0: lea    rdi,[rcx+0x342] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 834ULL);
x86_l_2dc7:
	/* 0x2dc7: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2dca:
	/* 0x2dca: jbe    2de1 <tail_policy_denied_ipv6+0x2de1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 11745ULL;
	}
	return 11724ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11724ULL: goto x86_l_2dcc;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11748ULL: goto x86_l_2de4;
	case 11750ULL: goto x86_l_2de6;
	case 11757ULL: goto x86_l_2ded;
	case 11763ULL: goto x86_l_2df3;
	case 11770ULL: goto x86_l_2dfa;
	case 11773ULL: goto x86_l_2dfd;
	case 11775ULL: goto x86_l_2dff;
	case 11782ULL: goto x86_l_2e06;
	case 11785ULL: goto x86_l_2e09;
	case 11791ULL: goto x86_l_2e0f;
	case 11796ULL: goto x86_l_2e14;
	case 11799ULL: goto x86_l_2e17;
	case 11801ULL: goto x86_l_2e19;
	case 11808ULL: goto x86_l_2e20;
	case 11814ULL: goto x86_l_2e26;
	case 11821ULL: goto x86_l_2e2d;
	case 11824ULL: goto x86_l_2e30;
	case 11826ULL: goto x86_l_2e32;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11852ULL: goto x86_l_2e4c;
	case 11859ULL: goto x86_l_2e53;
	case 11865ULL: goto x86_l_2e59;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11877ULL: goto x86_l_2e65;
	case 11884ULL: goto x86_l_2e6c;
	case 11887ULL: goto x86_l_2e6f;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11901ULL: goto x86_l_2e7d;
	case 11903ULL: goto x86_l_2e7f;
	case 11910ULL: goto x86_l_2e86;
	case 11916ULL: goto x86_l_2e8c;
	case 11923ULL: goto x86_l_2e93;
	case 11926ULL: goto x86_l_2e96;
	case 11928ULL: goto x86_l_2e98;
	case 11935ULL: goto x86_l_2e9f;
	case 11938ULL: goto x86_l_2ea2;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11952ULL: goto x86_l_2eb0;
	case 11954ULL: goto x86_l_2eb2;
	case 11961ULL: goto x86_l_2eb9;
	case 11967ULL: goto x86_l_2ebf;
	case 11974ULL: goto x86_l_2ec6;
	case 11977ULL: goto x86_l_2ec9;
	case 11979ULL: goto x86_l_2ecb;
	case 11986ULL: goto x86_l_2ed2;
	case 11989ULL: goto x86_l_2ed5;
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12003ULL: goto x86_l_2ee3;
	case 12005ULL: goto x86_l_2ee5;
	case 12012ULL: goto x86_l_2eec;
	case 12018ULL: goto x86_l_2ef2;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12030ULL: goto x86_l_2efe;
	case 12037ULL: goto x86_l_2f05;
	case 12040ULL: goto x86_l_2f08;
	case 12046ULL: goto x86_l_2f0e;
	case 12051ULL: goto x86_l_2f13;
	case 12054ULL: goto x86_l_2f16;
	case 12056ULL: goto x86_l_2f18;
	case 12063ULL: goto x86_l_2f1f;
	case 12069ULL: goto x86_l_2f25;
	case 12076ULL: goto x86_l_2f2c;
	case 12079ULL: goto x86_l_2f2f;
	case 12081ULL: goto x86_l_2f31;
	case 12088ULL: goto x86_l_2f38;
	case 12091ULL: goto x86_l_2f3b;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12105ULL: goto x86_l_2f49;
	case 12107ULL: goto x86_l_2f4b;
	case 12114ULL: goto x86_l_2f52;
	case 12120ULL: goto x86_l_2f58;
	case 12127ULL: goto x86_l_2f5f;
	case 12130ULL: goto x86_l_2f62;
	case 12132ULL: goto x86_l_2f64;
	case 12139ULL: goto x86_l_2f6b;
	case 12142ULL: goto x86_l_2f6e;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12156ULL: goto x86_l_2f7c;
	case 12158ULL: goto x86_l_2f7e;
	case 12165ULL: goto x86_l_2f85;
	case 12171ULL: goto x86_l_2f8b;
	case 12178ULL: goto x86_l_2f92;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12190ULL: goto x86_l_2f9e;
	case 12193ULL: goto x86_l_2fa1;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12209ULL: goto x86_l_2fb1;
	case 12216ULL: goto x86_l_2fb8;
	case 12222ULL: goto x86_l_2fbe;
	case 12229ULL: goto x86_l_2fc5;
	case 12232ULL: goto x86_l_2fc8;
	case 12234ULL: goto x86_l_2fca;
	case 12241ULL: goto x86_l_2fd1;
	case 12244ULL: goto x86_l_2fd4;
	case 12250ULL: goto x86_l_2fda;
	case 12255ULL: goto x86_l_2fdf;
	case 12258ULL: goto x86_l_2fe2;
	case 12260ULL: goto x86_l_2fe4;
	case 12267ULL: goto x86_l_2feb;
	case 12273ULL: goto x86_l_2ff1;
	case 12280ULL: goto x86_l_2ff8;
	case 12283ULL: goto x86_l_2ffb;
	case 12285ULL: goto x86_l_2ffd;
	case 12292ULL: goto x86_l_3004;
	case 12295ULL: goto x86_l_3007;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12311ULL: goto x86_l_3017;
	case 12318ULL: goto x86_l_301e;
	case 12324ULL: goto x86_l_3024;
	case 12331ULL: goto x86_l_302b;
	case 12334ULL: goto x86_l_302e;
	case 12336ULL: goto x86_l_3030;
	case 12343ULL: goto x86_l_3037;
	case 12346ULL: goto x86_l_303a;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12360ULL: goto x86_l_3048;
	case 12362ULL: goto x86_l_304a;
	case 12369ULL: goto x86_l_3051;
	case 12375ULL: goto x86_l_3057;
	case 12382ULL: goto x86_l_305e;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12408ULL: goto x86_l_3078;
	case 12411ULL: goto x86_l_307b;
	case 12413ULL: goto x86_l_307d;
	case 12420ULL: goto x86_l_3084;
	case 12426ULL: goto x86_l_308a;
	case 12433ULL: goto x86_l_3091;
	case 12436ULL: goto x86_l_3094;
	case 12438ULL: goto x86_l_3096;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12462ULL: goto x86_l_30ae;
	case 12464ULL: goto x86_l_30b0;
	case 12471ULL: goto x86_l_30b7;
	case 12477ULL: goto x86_l_30bd;
	case 12484ULL: goto x86_l_30c4;
	case 12487ULL: goto x86_l_30c7;
	case 12489ULL: goto x86_l_30c9;
	case 12496ULL: goto x86_l_30d0;
	case 12499ULL: goto x86_l_30d3;
	case 12505ULL: goto x86_l_30d9;
	case 12510ULL: goto x86_l_30de;
	case 12513ULL: goto x86_l_30e1;
	case 12515ULL: goto x86_l_30e3;
	case 12522ULL: goto x86_l_30ea;
	case 12528ULL: goto x86_l_30f0;
	case 12535ULL: goto x86_l_30f7;
	case 12538ULL: goto x86_l_30fa;
	case 12540ULL: goto x86_l_30fc;
	case 12547ULL: goto x86_l_3103;
	case 12550ULL: goto x86_l_3106;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12566ULL: goto x86_l_3116;
	case 12573ULL: goto x86_l_311d;
	case 12579ULL: goto x86_l_3123;
	case 12586ULL: goto x86_l_312a;
	case 12589ULL: goto x86_l_312d;
	case 12591ULL: goto x86_l_312f;
	case 12598ULL: goto x86_l_3136;
	case 12601ULL: goto x86_l_3139;
	case 12607ULL: goto x86_l_313f;
	case 12612ULL: goto x86_l_3144;
	case 12615ULL: goto x86_l_3147;
	case 12617ULL: goto x86_l_3149;
	case 12624ULL: goto x86_l_3150;
	case 12630ULL: goto x86_l_3156;
	case 12637ULL: goto x86_l_315d;
	case 12640ULL: goto x86_l_3160;
	case 12642ULL: goto x86_l_3162;
	case 12649ULL: goto x86_l_3169;
	case 12652ULL: goto x86_l_316c;
	case 12658ULL: goto x86_l_3172;
	case 12663ULL: goto x86_l_3177;
	case 12666ULL: goto x86_l_317a;
	case 12668ULL: goto x86_l_317c;
	case 12675ULL: goto x86_l_3183;
	case 12681ULL: goto x86_l_3189;
	case 12688ULL: goto x86_l_3190;
	case 12691ULL: goto x86_l_3193;
	case 12693ULL: goto x86_l_3195;
	case 12700ULL: goto x86_l_319c;
	case 12703ULL: goto x86_l_319f;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12726ULL: goto x86_l_31b6;
	case 12732ULL: goto x86_l_31bc;
	case 12739ULL: goto x86_l_31c3;
	case 12742ULL: goto x86_l_31c6;
	case 12744ULL: goto x86_l_31c8;
	case 12751ULL: goto x86_l_31cf;
	case 12754ULL: goto x86_l_31d2;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12768ULL: goto x86_l_31e0;
	case 12770ULL: goto x86_l_31e2;
	case 12777ULL: goto x86_l_31e9;
	case 12783ULL: goto x86_l_31ef;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12795ULL: goto x86_l_31fb;
	case 12802ULL: goto x86_l_3202;
	case 12805ULL: goto x86_l_3205;
	case 12811ULL: goto x86_l_320b;
	case 12816ULL: goto x86_l_3210;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12841ULL: goto x86_l_3229;
	case 12844ULL: goto x86_l_322c;
	case 12846ULL: goto x86_l_322e;
	case 12853ULL: goto x86_l_3235;
	case 12856ULL: goto x86_l_3238;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12870ULL: goto x86_l_3246;
	case 12872ULL: goto x86_l_3248;
	case 12879ULL: goto x86_l_324f;
	case 12885ULL: goto x86_l_3255;
	case 12892ULL: goto x86_l_325c;
	case 12895ULL: goto x86_l_325f;
	case 12897ULL: goto x86_l_3261;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12921ULL: goto x86_l_3279;
	case 12923ULL: goto x86_l_327b;
	case 12930ULL: goto x86_l_3282;
	case 12936ULL: goto x86_l_3288;
	case 12943ULL: goto x86_l_328f;
	case 12946ULL: goto x86_l_3292;
	case 12948ULL: goto x86_l_3294;
	case 12955ULL: goto x86_l_329b;
	case 12958ULL: goto x86_l_329e;
	case 12964ULL: goto x86_l_32a4;
	case 12969ULL: goto x86_l_32a9;
	case 12972ULL: goto x86_l_32ac;
	case 12974ULL: goto x86_l_32ae;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12994ULL: goto x86_l_32c2;
	case 12997ULL: goto x86_l_32c5;
	case 12999ULL: goto x86_l_32c7;
	case 13006ULL: goto x86_l_32ce;
	case 13009ULL: goto x86_l_32d1;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13025ULL: goto x86_l_32e1;
	case 13032ULL: goto x86_l_32e8;
	case 13038ULL: goto x86_l_32ee;
	case 13045ULL: goto x86_l_32f5;
	case 13048ULL: goto x86_l_32f8;
	case 13050ULL: goto x86_l_32fa;
	case 13057ULL: goto x86_l_3301;
	case 13060ULL: goto x86_l_3304;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13074ULL: goto x86_l_3312;
	case 13076ULL: goto x86_l_3314;
	case 13083ULL: goto x86_l_331b;
	case 13089ULL: goto x86_l_3321;
	case 13096ULL: goto x86_l_3328;
	case 13099ULL: goto x86_l_332b;
	case 13101ULL: goto x86_l_332d;
	case 13108ULL: goto x86_l_3334;
	case 13111ULL: goto x86_l_3337;
	case 13117ULL: goto x86_l_333d;
	case 13122ULL: goto x86_l_3342;
	case 13125ULL: goto x86_l_3345;
	case 13127ULL: goto x86_l_3347;
	case 13134ULL: goto x86_l_334e;
	case 13140ULL: goto x86_l_3354;
	case 13147ULL: goto x86_l_335b;
	case 13150ULL: goto x86_l_335e;
	case 13152ULL: goto x86_l_3360;
	case 13159ULL: goto x86_l_3367;
	case 13162ULL: goto x86_l_336a;
	case 13168ULL: goto x86_l_3370;
	case 13173ULL: goto x86_l_3375;
	case 13176ULL: goto x86_l_3378;
	case 13178ULL: goto x86_l_337a;
	case 13185ULL: goto x86_l_3381;
	case 13191ULL: goto x86_l_3387;
	case 13198ULL: goto x86_l_338e;
	case 13201ULL: goto x86_l_3391;
	case 13203ULL: goto x86_l_3393;
	case 13210ULL: goto x86_l_339a;
	case 13213ULL: goto x86_l_339d;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13227ULL: goto x86_l_33ab;
	case 13229ULL: goto x86_l_33ad;
	case 13236ULL: goto x86_l_33b4;
	case 13242ULL: goto x86_l_33ba;
	case 13249ULL: goto x86_l_33c1;
	case 13252ULL: goto x86_l_33c4;
	case 13254ULL: goto x86_l_33c6;
	case 13261ULL: goto x86_l_33cd;
	case 13264ULL: goto x86_l_33d0;
	case 13270ULL: goto x86_l_33d6;
	case 13275ULL: goto x86_l_33db;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13287ULL: goto x86_l_33e7;
	case 13293ULL: goto x86_l_33ed;
	case 13300ULL: goto x86_l_33f4;
	case 13303ULL: goto x86_l_33f7;
	case 13305ULL: goto x86_l_33f9;
	case 13312ULL: goto x86_l_3400;
	case 13315ULL: goto x86_l_3403;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13329ULL: goto x86_l_3411;
	case 13331ULL: goto x86_l_3413;
	case 13338ULL: goto x86_l_341a;
	case 13344ULL: goto x86_l_3420;
	case 13351ULL: goto x86_l_3427;
	case 13354ULL: goto x86_l_342a;
	case 13356ULL: goto x86_l_342c;
	case 13363ULL: goto x86_l_3433;
	case 13366ULL: goto x86_l_3436;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13380ULL: goto x86_l_3444;
	case 13382ULL: goto x86_l_3446;
	case 13389ULL: goto x86_l_344d;
	case 13395ULL: goto x86_l_3453;
	case 13402ULL: goto x86_l_345a;
	case 13405ULL: goto x86_l_345d;
	case 13407ULL: goto x86_l_345f;
	case 13414ULL: goto x86_l_3466;
	case 13417ULL: goto x86_l_3469;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13431ULL: goto x86_l_3477;
	case 13433ULL: goto x86_l_3479;
	case 13440ULL: goto x86_l_3480;
	case 13446ULL: goto x86_l_3486;
	case 13453ULL: goto x86_l_348d;
	case 13456ULL: goto x86_l_3490;
	case 13458ULL: goto x86_l_3492;
	case 13465ULL: goto x86_l_3499;
	case 13468ULL: goto x86_l_349c;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13491ULL: goto x86_l_34b3;
	case 13497ULL: goto x86_l_34b9;
	case 13504ULL: goto x86_l_34c0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2dcc:
	/* 0x2dcc: add    rcx,0x341 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 833ULL);
x86_l_2dd3:
	/* 0x2dd3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2dd6:
	/* 0x2dd6: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2ddc:
	/* 0x2ddc: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2de1:
	/* 0x2de1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2de4:
	/* 0x2de4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2de6:
	/* 0x2de6: cmp    r14d,0x334 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 820ULL);
x86_l_2ded:
	/* 0x2ded: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2df3:
	/* 0x2df3: lea    rsi,[rcx+0x344] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 836ULL);
x86_l_2dfa:
	/* 0x2dfa: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2dfd:
	/* 0x2dfd: jbe    2e14 <tail_policy_denied_ipv6+0x2e14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e14;
	}
x86_l_2dff:
	/* 0x2dff: add    rcx,0x343 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 835ULL);
x86_l_2e06:
	/* 0x2e06: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2e09:
	/* 0x2e09: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2e0f:
	/* 0x2e0f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2e14:
	/* 0x2e14: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e17:
	/* 0x2e17: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e19:
	/* 0x2e19: cmp    r14d,0x336 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 822ULL);
x86_l_2e20:
	/* 0x2e20: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2e26:
	/* 0x2e26: lea    rdi,[rcx+0x346] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 838ULL);
x86_l_2e2d:
	/* 0x2e2d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2e30:
	/* 0x2e30: jbe    2e47 <tail_policy_denied_ipv6+0x2e47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e47;
	}
x86_l_2e32:
	/* 0x2e32: add    rcx,0x345 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 837ULL);
x86_l_2e39:
	/* 0x2e39: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2e3c:
	/* 0x2e3c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2e42:
	/* 0x2e42: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2e47:
	/* 0x2e47: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e4a:
	/* 0x2e4a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e4c:
	/* 0x2e4c: cmp    r14d,0x338 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 824ULL);
x86_l_2e53:
	/* 0x2e53: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2e59:
	/* 0x2e59: lea    rsi,[rcx+0x348] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 840ULL);
x86_l_2e60:
	/* 0x2e60: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2e63:
	/* 0x2e63: jbe    2e7a <tail_policy_denied_ipv6+0x2e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2e7a;
	}
x86_l_2e65:
	/* 0x2e65: add    rcx,0x347 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 839ULL);
x86_l_2e6c:
	/* 0x2e6c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2e6f:
	/* 0x2e6f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2e75:
	/* 0x2e75: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2e7a:
	/* 0x2e7a: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e7d:
	/* 0x2e7d: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e7f:
	/* 0x2e7f: cmp    r14d,0x33a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 826ULL);
x86_l_2e86:
	/* 0x2e86: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2e8c:
	/* 0x2e8c: lea    rdi,[rcx+0x34a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 842ULL);
x86_l_2e93:
	/* 0x2e93: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2e96:
	/* 0x2e96: jbe    2ead <tail_policy_denied_ipv6+0x2ead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ead;
	}
x86_l_2e98:
	/* 0x2e98: add    rcx,0x349 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 841ULL);
x86_l_2e9f:
	/* 0x2e9f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ea2:
	/* 0x2ea2: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2ea8:
	/* 0x2ea8: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2ead:
	/* 0x2ead: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2eb0:
	/* 0x2eb0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2eb2:
	/* 0x2eb2: cmp    r14d,0x33c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 828ULL);
x86_l_2eb9:
	/* 0x2eb9: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2ebf:
	/* 0x2ebf: lea    rsi,[rcx+0x34c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 844ULL);
x86_l_2ec6:
	/* 0x2ec6: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2ec9:
	/* 0x2ec9: jbe    2ee0 <tail_policy_denied_ipv6+0x2ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2ee0;
	}
x86_l_2ecb:
	/* 0x2ecb: add    rcx,0x34b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 843ULL);
x86_l_2ed2:
	/* 0x2ed2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2ed5:
	/* 0x2ed5: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2edb:
	/* 0x2edb: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2ee0:
	/* 0x2ee0: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ee3:
	/* 0x2ee3: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ee5:
	/* 0x2ee5: cmp    r14d,0x33e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 830ULL);
x86_l_2eec:
	/* 0x2eec: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2ef2:
	/* 0x2ef2: lea    rdi,[rcx+0x34e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 846ULL);
x86_l_2ef9:
	/* 0x2ef9: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2efc:
	/* 0x2efc: jbe    2f13 <tail_policy_denied_ipv6+0x2f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f13;
	}
x86_l_2efe:
	/* 0x2efe: add    rcx,0x34d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 845ULL);
x86_l_2f05:
	/* 0x2f05: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f08:
	/* 0x2f08: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2f0e:
	/* 0x2f0e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2f13:
	/* 0x2f13: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f16:
	/* 0x2f16: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f18:
	/* 0x2f18: cmp    r14d,0x340 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 832ULL);
x86_l_2f1f:
	/* 0x2f1f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2f25:
	/* 0x2f25: lea    rsi,[rcx+0x350] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 848ULL);
x86_l_2f2c:
	/* 0x2f2c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2f2f:
	/* 0x2f2f: jbe    2f46 <tail_policy_denied_ipv6+0x2f46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f46;
	}
x86_l_2f31:
	/* 0x2f31: add    rcx,0x34f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 847ULL);
x86_l_2f38:
	/* 0x2f38: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f3b:
	/* 0x2f3b: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2f41:
	/* 0x2f41: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2f46:
	/* 0x2f46: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f49:
	/* 0x2f49: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f4b:
	/* 0x2f4b: cmp    r14d,0x342 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 834ULL);
x86_l_2f52:
	/* 0x2f52: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2f58:
	/* 0x2f58: lea    rdi,[rcx+0x352] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 850ULL);
x86_l_2f5f:
	/* 0x2f5f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2f62:
	/* 0x2f62: jbe    2f79 <tail_policy_denied_ipv6+0x2f79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f79;
	}
x86_l_2f64:
	/* 0x2f64: add    rcx,0x351 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 849ULL);
x86_l_2f6b:
	/* 0x2f6b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f6e:
	/* 0x2f6e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2f74:
	/* 0x2f74: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2f79:
	/* 0x2f79: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f7c:
	/* 0x2f7c: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f7e:
	/* 0x2f7e: cmp    r14d,0x344 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 836ULL);
x86_l_2f85:
	/* 0x2f85: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2f8b:
	/* 0x2f8b: lea    rsi,[rcx+0x354] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 852ULL);
x86_l_2f92:
	/* 0x2f92: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2f95:
	/* 0x2f95: jbe    2fac <tail_policy_denied_ipv6+0x2fac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2fac;
	}
x86_l_2f97:
	/* 0x2f97: add    rcx,0x353 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 851ULL);
x86_l_2f9e:
	/* 0x2f9e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2fa1:
	/* 0x2fa1: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_2fa7:
	/* 0x2fa7: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2fac:
	/* 0x2fac: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2faf:
	/* 0x2faf: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2fb1:
	/* 0x2fb1: cmp    r14d,0x346 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 838ULL);
x86_l_2fb8:
	/* 0x2fb8: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2fbe:
	/* 0x2fbe: lea    rdi,[rcx+0x356] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 854ULL);
x86_l_2fc5:
	/* 0x2fc5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2fc8:
	/* 0x2fc8: jbe    2fdf <tail_policy_denied_ipv6+0x2fdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2fdf;
	}
x86_l_2fca:
	/* 0x2fca: add    rcx,0x355 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 853ULL);
x86_l_2fd1:
	/* 0x2fd1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2fd4:
	/* 0x2fd4: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_2fda:
	/* 0x2fda: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_2fdf:
	/* 0x2fdf: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fe2:
	/* 0x2fe2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2fe4:
	/* 0x2fe4: cmp    r14d,0x348 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 840ULL);
x86_l_2feb:
	/* 0x2feb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_2ff1:
	/* 0x2ff1: lea    rsi,[rcx+0x358] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 856ULL);
x86_l_2ff8:
	/* 0x2ff8: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2ffb:
	/* 0x2ffb: jbe    3012 <tail_policy_denied_ipv6+0x3012> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3012;
	}
x86_l_2ffd:
	/* 0x2ffd: add    rcx,0x357 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 855ULL);
x86_l_3004:
	/* 0x3004: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3007:
	/* 0x3007: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_300d:
	/* 0x300d: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3012:
	/* 0x3012: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3015:
	/* 0x3015: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3017:
	/* 0x3017: cmp    r14d,0x34a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 842ULL);
x86_l_301e:
	/* 0x301e: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3024:
	/* 0x3024: lea    rdi,[rcx+0x35a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858ULL);
x86_l_302b:
	/* 0x302b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_302e:
	/* 0x302e: jbe    3045 <tail_policy_denied_ipv6+0x3045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3045;
	}
x86_l_3030:
	/* 0x3030: add    rcx,0x359 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 857ULL);
x86_l_3037:
	/* 0x3037: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_303a:
	/* 0x303a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3040:
	/* 0x3040: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3045:
	/* 0x3045: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3048:
	/* 0x3048: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_304a:
	/* 0x304a: cmp    r14d,0x34c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 844ULL);
x86_l_3051:
	/* 0x3051: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3057:
	/* 0x3057: lea    rsi,[rcx+0x35c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 860ULL);
x86_l_305e:
	/* 0x305e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3061:
	/* 0x3061: jbe    3078 <tail_policy_denied_ipv6+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3078;
	}
x86_l_3063:
	/* 0x3063: add    rcx,0x35b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 859ULL);
x86_l_306a:
	/* 0x306a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_306d:
	/* 0x306d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3073:
	/* 0x3073: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3078:
	/* 0x3078: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_307b:
	/* 0x307b: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_307d:
	/* 0x307d: cmp    r14d,0x34e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 846ULL);
x86_l_3084:
	/* 0x3084: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_308a:
	/* 0x308a: lea    rdi,[rcx+0x35e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 862ULL);
x86_l_3091:
	/* 0x3091: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3094:
	/* 0x3094: jbe    30ab <tail_policy_denied_ipv6+0x30ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_30ab;
	}
x86_l_3096:
	/* 0x3096: add    rcx,0x35d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 861ULL);
x86_l_309d:
	/* 0x309d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_30a0:
	/* 0x30a0: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_30a6:
	/* 0x30a6: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_30ab:
	/* 0x30ab: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30ae:
	/* 0x30ae: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_30b0:
	/* 0x30b0: cmp    r14d,0x350 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 848ULL);
x86_l_30b7:
	/* 0x30b7: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_30bd:
	/* 0x30bd: lea    rsi,[rcx+0x360] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 864ULL);
x86_l_30c4:
	/* 0x30c4: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_30c7:
	/* 0x30c7: jbe    30de <tail_policy_denied_ipv6+0x30de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_30de;
	}
x86_l_30c9:
	/* 0x30c9: add    rcx,0x35f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 863ULL);
x86_l_30d0:
	/* 0x30d0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_30d3:
	/* 0x30d3: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_30d9:
	/* 0x30d9: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_30de:
	/* 0x30de: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30e1:
	/* 0x30e1: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_30e3:
	/* 0x30e3: cmp    r14d,0x352 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 850ULL);
x86_l_30ea:
	/* 0x30ea: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_30f0:
	/* 0x30f0: lea    rdi,[rcx+0x362] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 866ULL);
x86_l_30f7:
	/* 0x30f7: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_30fa:
	/* 0x30fa: jbe    3111 <tail_policy_denied_ipv6+0x3111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3111;
	}
x86_l_30fc:
	/* 0x30fc: add    rcx,0x361 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 865ULL);
x86_l_3103:
	/* 0x3103: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3106:
	/* 0x3106: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_310c:
	/* 0x310c: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3111:
	/* 0x3111: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3114:
	/* 0x3114: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3116:
	/* 0x3116: cmp    r14d,0x354 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 852ULL);
x86_l_311d:
	/* 0x311d: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3123:
	/* 0x3123: lea    rsi,[rcx+0x364] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 868ULL);
x86_l_312a:
	/* 0x312a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_312d:
	/* 0x312d: jbe    3144 <tail_policy_denied_ipv6+0x3144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3144;
	}
x86_l_312f:
	/* 0x312f: add    rcx,0x363 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 867ULL);
x86_l_3136:
	/* 0x3136: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3139:
	/* 0x3139: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_313f:
	/* 0x313f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3144:
	/* 0x3144: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3147:
	/* 0x3147: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3149:
	/* 0x3149: cmp    r14d,0x356 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 854ULL);
x86_l_3150:
	/* 0x3150: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3156:
	/* 0x3156: lea    rdi,[rcx+0x366] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 870ULL);
x86_l_315d:
	/* 0x315d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3160:
	/* 0x3160: jbe    3177 <tail_policy_denied_ipv6+0x3177> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3177;
	}
x86_l_3162:
	/* 0x3162: add    rcx,0x365 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 869ULL);
x86_l_3169:
	/* 0x3169: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_316c:
	/* 0x316c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3172:
	/* 0x3172: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3177:
	/* 0x3177: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_317a:
	/* 0x317a: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_317c:
	/* 0x317c: cmp    r14d,0x358 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 856ULL);
x86_l_3183:
	/* 0x3183: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3189:
	/* 0x3189: lea    rsi,[rcx+0x368] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 872ULL);
x86_l_3190:
	/* 0x3190: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3193:
	/* 0x3193: jbe    31aa <tail_policy_denied_ipv6+0x31aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_31aa;
	}
x86_l_3195:
	/* 0x3195: add    rcx,0x367 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 871ULL);
x86_l_319c:
	/* 0x319c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_319f:
	/* 0x319f: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_31a5:
	/* 0x31a5: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_31aa:
	/* 0x31aa: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31ad:
	/* 0x31ad: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_31af:
	/* 0x31af: cmp    r14d,0x35a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 858ULL);
x86_l_31b6:
	/* 0x31b6: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_31bc:
	/* 0x31bc: lea    rdi,[rcx+0x36a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 874ULL);
x86_l_31c3:
	/* 0x31c3: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_31c6:
	/* 0x31c6: jbe    31dd <tail_policy_denied_ipv6+0x31dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_31dd;
	}
x86_l_31c8:
	/* 0x31c8: add    rcx,0x369 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 873ULL);
x86_l_31cf:
	/* 0x31cf: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_31d2:
	/* 0x31d2: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_31d8:
	/* 0x31d8: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_31dd:
	/* 0x31dd: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31e0:
	/* 0x31e0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_31e2:
	/* 0x31e2: cmp    r14d,0x35c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 860ULL);
x86_l_31e9:
	/* 0x31e9: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_31ef:
	/* 0x31ef: lea    rsi,[rcx+0x36c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 876ULL);
x86_l_31f6:
	/* 0x31f6: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: jbe    3210 <tail_policy_denied_ipv6+0x3210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3210;
	}
x86_l_31fb:
	/* 0x31fb: add    rcx,0x36b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 875ULL);
x86_l_3202:
	/* 0x3202: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3205:
	/* 0x3205: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_320b:
	/* 0x320b: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3210:
	/* 0x3210: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3213:
	/* 0x3213: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3215:
	/* 0x3215: cmp    r14d,0x35e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 862ULL);
x86_l_321c:
	/* 0x321c: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3222:
	/* 0x3222: lea    rdi,[rcx+0x36e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 878ULL);
x86_l_3229:
	/* 0x3229: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_322c:
	/* 0x322c: jbe    3243 <tail_policy_denied_ipv6+0x3243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3243;
	}
x86_l_322e:
	/* 0x322e: add    rcx,0x36d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 877ULL);
x86_l_3235:
	/* 0x3235: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3238:
	/* 0x3238: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_323e:
	/* 0x323e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3243:
	/* 0x3243: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3246:
	/* 0x3246: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3248:
	/* 0x3248: cmp    r14d,0x360 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 864ULL);
x86_l_324f:
	/* 0x324f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3255:
	/* 0x3255: lea    rsi,[rcx+0x370] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 880ULL);
x86_l_325c:
	/* 0x325c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_325f:
	/* 0x325f: jbe    3276 <tail_policy_denied_ipv6+0x3276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3276;
	}
x86_l_3261:
	/* 0x3261: add    rcx,0x36f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 879ULL);
x86_l_3268:
	/* 0x3268: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_326b:
	/* 0x326b: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3271:
	/* 0x3271: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3276:
	/* 0x3276: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3279:
	/* 0x3279: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_327b:
	/* 0x327b: cmp    r14d,0x362 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 866ULL);
x86_l_3282:
	/* 0x3282: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3288:
	/* 0x3288: lea    rdi,[rcx+0x372] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 882ULL);
x86_l_328f:
	/* 0x328f: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3292:
	/* 0x3292: jbe    32a9 <tail_policy_denied_ipv6+0x32a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32a9;
	}
x86_l_3294:
	/* 0x3294: add    rcx,0x371 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 881ULL);
x86_l_329b:
	/* 0x329b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_329e:
	/* 0x329e: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_32a4:
	/* 0x32a4: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_32a9:
	/* 0x32a9: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32ac:
	/* 0x32ac: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_32ae:
	/* 0x32ae: cmp    r14d,0x364 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 868ULL);
x86_l_32b5:
	/* 0x32b5: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_32bb:
	/* 0x32bb: lea    rsi,[rcx+0x374] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 884ULL);
x86_l_32c2:
	/* 0x32c2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_32c5:
	/* 0x32c5: jbe    32dc <tail_policy_denied_ipv6+0x32dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_32dc;
	}
x86_l_32c7:
	/* 0x32c7: add    rcx,0x373 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 883ULL);
x86_l_32ce:
	/* 0x32ce: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_32d1:
	/* 0x32d1: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_32d7:
	/* 0x32d7: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_32dc:
	/* 0x32dc: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32df:
	/* 0x32df: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_32e1:
	/* 0x32e1: cmp    r14d,0x366 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 870ULL);
x86_l_32e8:
	/* 0x32e8: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_32ee:
	/* 0x32ee: lea    rdi,[rcx+0x376] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 886ULL);
x86_l_32f5:
	/* 0x32f5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_32f8:
	/* 0x32f8: jbe    330f <tail_policy_denied_ipv6+0x330f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_330f;
	}
x86_l_32fa:
	/* 0x32fa: add    rcx,0x375 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 885ULL);
x86_l_3301:
	/* 0x3301: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3304:
	/* 0x3304: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_330a:
	/* 0x330a: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_330f:
	/* 0x330f: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3312:
	/* 0x3312: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3314:
	/* 0x3314: cmp    r14d,0x368 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 872ULL);
x86_l_331b:
	/* 0x331b: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3321:
	/* 0x3321: lea    rsi,[rcx+0x378] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 888ULL);
x86_l_3328:
	/* 0x3328: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_332b:
	/* 0x332b: jbe    3342 <tail_policy_denied_ipv6+0x3342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3342;
	}
x86_l_332d:
	/* 0x332d: add    rcx,0x377 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 887ULL);
x86_l_3334:
	/* 0x3334: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3337:
	/* 0x3337: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_333d:
	/* 0x333d: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3342:
	/* 0x3342: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3345:
	/* 0x3345: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3347:
	/* 0x3347: cmp    r14d,0x36a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 874ULL);
x86_l_334e:
	/* 0x334e: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3354:
	/* 0x3354: lea    rdi,[rcx+0x37a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 890ULL);
x86_l_335b:
	/* 0x335b: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_335e:
	/* 0x335e: jbe    3375 <tail_policy_denied_ipv6+0x3375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3375;
	}
x86_l_3360:
	/* 0x3360: add    rcx,0x379 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 889ULL);
x86_l_3367:
	/* 0x3367: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_336a:
	/* 0x336a: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3370:
	/* 0x3370: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3375:
	/* 0x3375: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3378:
	/* 0x3378: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_337a:
	/* 0x337a: cmp    r14d,0x36c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 876ULL);
x86_l_3381:
	/* 0x3381: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3387:
	/* 0x3387: lea    rsi,[rcx+0x37c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 892ULL);
x86_l_338e:
	/* 0x338e: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3391:
	/* 0x3391: jbe    33a8 <tail_policy_denied_ipv6+0x33a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_33a8;
	}
x86_l_3393:
	/* 0x3393: add    rcx,0x37b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 891ULL);
x86_l_339a:
	/* 0x339a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_339d:
	/* 0x339d: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_33a3:
	/* 0x33a3: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_33a8:
	/* 0x33a8: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33ab:
	/* 0x33ab: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_33ad:
	/* 0x33ad: cmp    r14d,0x36e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 878ULL);
x86_l_33b4:
	/* 0x33b4: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_33ba:
	/* 0x33ba: lea    rdi,[rcx+0x37e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 894ULL);
x86_l_33c1:
	/* 0x33c1: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_33c4:
	/* 0x33c4: jbe    33db <tail_policy_denied_ipv6+0x33db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_33db;
	}
x86_l_33c6:
	/* 0x33c6: add    rcx,0x37d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 893ULL);
x86_l_33cd:
	/* 0x33cd: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_33d0:
	/* 0x33d0: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_33d6:
	/* 0x33d6: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_33db:
	/* 0x33db: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33de:
	/* 0x33de: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_33e0:
	/* 0x33e0: cmp    r14d,0x370 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 880ULL);
x86_l_33e7:
	/* 0x33e7: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_33ed:
	/* 0x33ed: lea    rsi,[rcx+0x380] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 896ULL);
x86_l_33f4:
	/* 0x33f4: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_33f7:
	/* 0x33f7: jbe    340e <tail_policy_denied_ipv6+0x340e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_340e;
	}
x86_l_33f9:
	/* 0x33f9: add    rcx,0x37f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 895ULL);
x86_l_3400:
	/* 0x3400: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3403:
	/* 0x3403: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3409:
	/* 0x3409: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_340e:
	/* 0x340e: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3411:
	/* 0x3411: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3413:
	/* 0x3413: cmp    r14d,0x372 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 882ULL);
x86_l_341a:
	/* 0x341a: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3420:
	/* 0x3420: lea    rdi,[rcx+0x382] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 898ULL);
x86_l_3427:
	/* 0x3427: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_342a:
	/* 0x342a: jbe    3441 <tail_policy_denied_ipv6+0x3441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3441;
	}
x86_l_342c:
	/* 0x342c: add    rcx,0x381 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 897ULL);
x86_l_3433:
	/* 0x3433: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3436:
	/* 0x3436: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_343c:
	/* 0x343c: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3441:
	/* 0x3441: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3444:
	/* 0x3444: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3446:
	/* 0x3446: cmp    r14d,0x374 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 884ULL);
x86_l_344d:
	/* 0x344d: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3453:
	/* 0x3453: lea    rsi,[rcx+0x384] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 900ULL);
x86_l_345a:
	/* 0x345a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_345d:
	/* 0x345d: jbe    3474 <tail_policy_denied_ipv6+0x3474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3474;
	}
x86_l_345f:
	/* 0x345f: add    rcx,0x383 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 899ULL);
x86_l_3466:
	/* 0x3466: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3469:
	/* 0x3469: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_346f:
	/* 0x346f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3474:
	/* 0x3474: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3477:
	/* 0x3477: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3479:
	/* 0x3479: cmp    r14d,0x376 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 886ULL);
x86_l_3480:
	/* 0x3480: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3486:
	/* 0x3486: lea    rdi,[rcx+0x386] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 902ULL);
x86_l_348d:
	/* 0x348d: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3490:
	/* 0x3490: jbe    34a7 <tail_policy_denied_ipv6+0x34a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34a7;
	}
x86_l_3492:
	/* 0x3492: add    rcx,0x385 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 901ULL);
x86_l_3499:
	/* 0x3499: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_349c:
	/* 0x349c: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_34a2:
	/* 0x34a2: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_34a7:
	/* 0x34a7: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34aa:
	/* 0x34aa: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34ac:
	/* 0x34ac: cmp    r14d,0x378 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 888ULL);
x86_l_34b3:
	/* 0x34b3: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_34b9:
	/* 0x34b9: lea    rsi,[rcx+0x388] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 904ULL);
x86_l_34c0:
	/* 0x34c0: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
	return 13507ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13507ULL: goto x86_l_34c3;
	case 13509ULL: goto x86_l_34c5;
	case 13516ULL: goto x86_l_34cc;
	case 13519ULL: goto x86_l_34cf;
	case 13525ULL: goto x86_l_34d5;
	case 13530ULL: goto x86_l_34da;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13542ULL: goto x86_l_34e6;
	case 13548ULL: goto x86_l_34ec;
	case 13555ULL: goto x86_l_34f3;
	case 13558ULL: goto x86_l_34f6;
	case 13560ULL: goto x86_l_34f8;
	case 13567ULL: goto x86_l_34ff;
	case 13570ULL: goto x86_l_3502;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13593ULL: goto x86_l_3519;
	case 13599ULL: goto x86_l_351f;
	case 13606ULL: goto x86_l_3526;
	case 13609ULL: goto x86_l_3529;
	case 13611ULL: goto x86_l_352b;
	case 13618ULL: goto x86_l_3532;
	case 13621ULL: goto x86_l_3535;
	case 13627ULL: goto x86_l_353b;
	case 13632ULL: goto x86_l_3540;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13644ULL: goto x86_l_354c;
	case 13650ULL: goto x86_l_3552;
	case 13657ULL: goto x86_l_3559;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13669ULL: goto x86_l_3565;
	case 13672ULL: goto x86_l_3568;
	case 13678ULL: goto x86_l_356e;
	case 13683ULL: goto x86_l_3573;
	case 13686ULL: goto x86_l_3576;
	case 13688ULL: goto x86_l_3578;
	case 13695ULL: goto x86_l_357f;
	case 13701ULL: goto x86_l_3585;
	case 13708ULL: goto x86_l_358c;
	case 13711ULL: goto x86_l_358f;
	case 13713ULL: goto x86_l_3591;
	case 13720ULL: goto x86_l_3598;
	case 13723ULL: goto x86_l_359b;
	case 13729ULL: goto x86_l_35a1;
	case 13736ULL: goto x86_l_35a8;
	case 13741ULL: goto x86_l_35ad;
	case 13748ULL: goto x86_l_35b4;
	case 13750ULL: goto x86_l_35b6;
	case 13757ULL: goto x86_l_35bd;
	case 13763ULL: goto x86_l_35c3;
	case 13770ULL: goto x86_l_35ca;
	case 13773ULL: goto x86_l_35cd;
	case 13775ULL: goto x86_l_35cf;
	case 13782ULL: goto x86_l_35d6;
	case 13785ULL: goto x86_l_35d9;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13799ULL: goto x86_l_35e7;
	case 13801ULL: goto x86_l_35e9;
	case 13808ULL: goto x86_l_35f0;
	case 13814ULL: goto x86_l_35f6;
	case 13821ULL: goto x86_l_35fd;
	case 13824ULL: goto x86_l_3600;
	case 13826ULL: goto x86_l_3602;
	case 13833ULL: goto x86_l_3609;
	case 13836ULL: goto x86_l_360c;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13859ULL: goto x86_l_3623;
	case 13865ULL: goto x86_l_3629;
	case 13872ULL: goto x86_l_3630;
	case 13875ULL: goto x86_l_3633;
	case 13877ULL: goto x86_l_3635;
	case 13884ULL: goto x86_l_363c;
	case 13887ULL: goto x86_l_363f;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13901ULL: goto x86_l_364d;
	case 13903ULL: goto x86_l_364f;
	case 13910ULL: goto x86_l_3656;
	case 13916ULL: goto x86_l_365c;
	case 13923ULL: goto x86_l_3663;
	case 13926ULL: goto x86_l_3666;
	case 13928ULL: goto x86_l_3668;
	case 13935ULL: goto x86_l_366f;
	case 13938ULL: goto x86_l_3672;
	case 13944ULL: goto x86_l_3678;
	case 13949ULL: goto x86_l_367d;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13961ULL: goto x86_l_3689;
	case 13967ULL: goto x86_l_368f;
	case 13974ULL: goto x86_l_3696;
	case 13977ULL: goto x86_l_3699;
	case 13979ULL: goto x86_l_369b;
	case 13986ULL: goto x86_l_36a2;
	case 13989ULL: goto x86_l_36a5;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14003ULL: goto x86_l_36b3;
	case 14005ULL: goto x86_l_36b5;
	case 14012ULL: goto x86_l_36bc;
	case 14018ULL: goto x86_l_36c2;
	case 14025ULL: goto x86_l_36c9;
	case 14028ULL: goto x86_l_36cc;
	case 14030ULL: goto x86_l_36ce;
	case 14037ULL: goto x86_l_36d5;
	case 14040ULL: goto x86_l_36d8;
	case 14046ULL: goto x86_l_36de;
	case 14051ULL: goto x86_l_36e3;
	case 14054ULL: goto x86_l_36e6;
	case 14056ULL: goto x86_l_36e8;
	case 14063ULL: goto x86_l_36ef;
	case 14069ULL: goto x86_l_36f5;
	case 14076ULL: goto x86_l_36fc;
	case 14079ULL: goto x86_l_36ff;
	case 14081ULL: goto x86_l_3701;
	case 14088ULL: goto x86_l_3708;
	case 14091ULL: goto x86_l_370b;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14105ULL: goto x86_l_3719;
	case 14107ULL: goto x86_l_371b;
	case 14114ULL: goto x86_l_3722;
	case 14120ULL: goto x86_l_3728;
	case 14127ULL: goto x86_l_372f;
	case 14130ULL: goto x86_l_3732;
	case 14132ULL: goto x86_l_3734;
	case 14139ULL: goto x86_l_373b;
	case 14142ULL: goto x86_l_373e;
	case 14148ULL: goto x86_l_3744;
	case 14153ULL: goto x86_l_3749;
	case 14156ULL: goto x86_l_374c;
	case 14158ULL: goto x86_l_374e;
	case 14165ULL: goto x86_l_3755;
	case 14171ULL: goto x86_l_375b;
	case 14178ULL: goto x86_l_3762;
	case 14181ULL: goto x86_l_3765;
	case 14183ULL: goto x86_l_3767;
	case 14190ULL: goto x86_l_376e;
	case 14193ULL: goto x86_l_3771;
	case 14199ULL: goto x86_l_3777;
	case 14204ULL: goto x86_l_377c;
	case 14207ULL: goto x86_l_377f;
	case 14209ULL: goto x86_l_3781;
	case 14216ULL: goto x86_l_3788;
	case 14222ULL: goto x86_l_378e;
	case 14229ULL: goto x86_l_3795;
	case 14232ULL: goto x86_l_3798;
	case 14234ULL: goto x86_l_379a;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14250ULL: goto x86_l_37aa;
	case 14255ULL: goto x86_l_37af;
	case 14258ULL: goto x86_l_37b2;
	case 14260ULL: goto x86_l_37b4;
	case 14267ULL: goto x86_l_37bb;
	case 14273ULL: goto x86_l_37c1;
	case 14280ULL: goto x86_l_37c8;
	case 14283ULL: goto x86_l_37cb;
	case 14285ULL: goto x86_l_37cd;
	case 14292ULL: goto x86_l_37d4;
	case 14295ULL: goto x86_l_37d7;
	case 14301ULL: goto x86_l_37dd;
	case 14306ULL: goto x86_l_37e2;
	case 14309ULL: goto x86_l_37e5;
	case 14311ULL: goto x86_l_37e7;
	case 14318ULL: goto x86_l_37ee;
	case 14324ULL: goto x86_l_37f4;
	case 14331ULL: goto x86_l_37fb;
	case 14334ULL: goto x86_l_37fe;
	case 14336ULL: goto x86_l_3800;
	case 14343ULL: goto x86_l_3807;
	case 14346ULL: goto x86_l_380a;
	case 14352ULL: goto x86_l_3810;
	case 14357ULL: goto x86_l_3815;
	case 14360ULL: goto x86_l_3818;
	case 14362ULL: goto x86_l_381a;
	case 14369ULL: goto x86_l_3821;
	case 14375ULL: goto x86_l_3827;
	case 14382ULL: goto x86_l_382e;
	case 14385ULL: goto x86_l_3831;
	case 14387ULL: goto x86_l_3833;
	case 14394ULL: goto x86_l_383a;
	case 14397ULL: goto x86_l_383d;
	case 14403ULL: goto x86_l_3843;
	case 14408ULL: goto x86_l_3848;
	case 14411ULL: goto x86_l_384b;
	case 14413ULL: goto x86_l_384d;
	case 14420ULL: goto x86_l_3854;
	case 14426ULL: goto x86_l_385a;
	case 14433ULL: goto x86_l_3861;
	case 14436ULL: goto x86_l_3864;
	case 14438ULL: goto x86_l_3866;
	case 14445ULL: goto x86_l_386d;
	case 14448ULL: goto x86_l_3870;
	case 14454ULL: goto x86_l_3876;
	case 14459ULL: goto x86_l_387b;
	case 14462ULL: goto x86_l_387e;
	case 14464ULL: goto x86_l_3880;
	case 14471ULL: goto x86_l_3887;
	case 14477ULL: goto x86_l_388d;
	case 14484ULL: goto x86_l_3894;
	case 14487ULL: goto x86_l_3897;
	case 14489ULL: goto x86_l_3899;
	case 14496ULL: goto x86_l_38a0;
	case 14499ULL: goto x86_l_38a3;
	case 14505ULL: goto x86_l_38a9;
	case 14510ULL: goto x86_l_38ae;
	case 14513ULL: goto x86_l_38b1;
	case 14515ULL: goto x86_l_38b3;
	case 14522ULL: goto x86_l_38ba;
	case 14528ULL: goto x86_l_38c0;
	case 14535ULL: goto x86_l_38c7;
	case 14538ULL: goto x86_l_38ca;
	case 14540ULL: goto x86_l_38cc;
	case 14547ULL: goto x86_l_38d3;
	case 14550ULL: goto x86_l_38d6;
	case 14556ULL: goto x86_l_38dc;
	case 14561ULL: goto x86_l_38e1;
	case 14564ULL: goto x86_l_38e4;
	case 14566ULL: goto x86_l_38e6;
	case 14573ULL: goto x86_l_38ed;
	case 14579ULL: goto x86_l_38f3;
	case 14586ULL: goto x86_l_38fa;
	case 14589ULL: goto x86_l_38fd;
	case 14591ULL: goto x86_l_38ff;
	case 14598ULL: goto x86_l_3906;
	case 14601ULL: goto x86_l_3909;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14615ULL: goto x86_l_3917;
	case 14617ULL: goto x86_l_3919;
	case 14624ULL: goto x86_l_3920;
	case 14630ULL: goto x86_l_3926;
	case 14637ULL: goto x86_l_392d;
	case 14640ULL: goto x86_l_3930;
	case 14642ULL: goto x86_l_3932;
	case 14649ULL: goto x86_l_3939;
	case 14652ULL: goto x86_l_393c;
	case 14658ULL: goto x86_l_3942;
	case 14663ULL: goto x86_l_3947;
	case 14666ULL: goto x86_l_394a;
	case 14668ULL: goto x86_l_394c;
	case 14675ULL: goto x86_l_3953;
	case 14681ULL: goto x86_l_3959;
	case 14688ULL: goto x86_l_3960;
	case 14691ULL: goto x86_l_3963;
	case 14693ULL: goto x86_l_3965;
	case 14700ULL: goto x86_l_396c;
	case 14703ULL: goto x86_l_396f;
	case 14709ULL: goto x86_l_3975;
	case 14714ULL: goto x86_l_397a;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14726ULL: goto x86_l_3986;
	case 14732ULL: goto x86_l_398c;
	case 14739ULL: goto x86_l_3993;
	case 14742ULL: goto x86_l_3996;
	case 14744ULL: goto x86_l_3998;
	case 14751ULL: goto x86_l_399f;
	case 14754ULL: goto x86_l_39a2;
	case 14760ULL: goto x86_l_39a8;
	case 14765ULL: goto x86_l_39ad;
	case 14768ULL: goto x86_l_39b0;
	case 14770ULL: goto x86_l_39b2;
	case 14777ULL: goto x86_l_39b9;
	case 14783ULL: goto x86_l_39bf;
	case 14790ULL: goto x86_l_39c6;
	case 14793ULL: goto x86_l_39c9;
	case 14795ULL: goto x86_l_39cb;
	case 14802ULL: goto x86_l_39d2;
	case 14805ULL: goto x86_l_39d5;
	case 14811ULL: goto x86_l_39db;
	case 14816ULL: goto x86_l_39e0;
	case 14819ULL: goto x86_l_39e3;
	case 14821ULL: goto x86_l_39e5;
	case 14828ULL: goto x86_l_39ec;
	case 14834ULL: goto x86_l_39f2;
	case 14841ULL: goto x86_l_39f9;
	case 14844ULL: goto x86_l_39fc;
	case 14846ULL: goto x86_l_39fe;
	case 14853ULL: goto x86_l_3a05;
	case 14856ULL: goto x86_l_3a08;
	case 14862ULL: goto x86_l_3a0e;
	case 14867ULL: goto x86_l_3a13;
	case 14870ULL: goto x86_l_3a16;
	case 14872ULL: goto x86_l_3a18;
	case 14879ULL: goto x86_l_3a1f;
	case 14885ULL: goto x86_l_3a25;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14897ULL: goto x86_l_3a31;
	case 14904ULL: goto x86_l_3a38;
	case 14907ULL: goto x86_l_3a3b;
	case 14913ULL: goto x86_l_3a41;
	case 14918ULL: goto x86_l_3a46;
	case 14921ULL: goto x86_l_3a49;
	case 14923ULL: goto x86_l_3a4b;
	case 14930ULL: goto x86_l_3a52;
	case 14936ULL: goto x86_l_3a58;
	case 14943ULL: goto x86_l_3a5f;
	case 14946ULL: goto x86_l_3a62;
	case 14948ULL: goto x86_l_3a64;
	case 14955ULL: goto x86_l_3a6b;
	case 14958ULL: goto x86_l_3a6e;
	case 14964ULL: goto x86_l_3a74;
	case 14969ULL: goto x86_l_3a79;
	case 14972ULL: goto x86_l_3a7c;
	case 14974ULL: goto x86_l_3a7e;
	case 14981ULL: goto x86_l_3a85;
	case 14987ULL: goto x86_l_3a8b;
	case 14994ULL: goto x86_l_3a92;
	case 14997ULL: goto x86_l_3a95;
	case 14999ULL: goto x86_l_3a97;
	case 15006ULL: goto x86_l_3a9e;
	case 15009ULL: goto x86_l_3aa1;
	case 15015ULL: goto x86_l_3aa7;
	case 15020ULL: goto x86_l_3aac;
	case 15023ULL: goto x86_l_3aaf;
	case 15025ULL: goto x86_l_3ab1;
	case 15032ULL: goto x86_l_3ab8;
	case 15038ULL: goto x86_l_3abe;
	case 15045ULL: goto x86_l_3ac5;
	case 15048ULL: goto x86_l_3ac8;
	case 15050ULL: goto x86_l_3aca;
	case 15057ULL: goto x86_l_3ad1;
	case 15060ULL: goto x86_l_3ad4;
	case 15066ULL: goto x86_l_3ada;
	case 15071ULL: goto x86_l_3adf;
	case 15074ULL: goto x86_l_3ae2;
	case 15076ULL: goto x86_l_3ae4;
	case 15083ULL: goto x86_l_3aeb;
	case 15089ULL: goto x86_l_3af1;
	case 15096ULL: goto x86_l_3af8;
	case 15099ULL: goto x86_l_3afb;
	case 15101ULL: goto x86_l_3afd;
	case 15108ULL: goto x86_l_3b04;
	case 15111ULL: goto x86_l_3b07;
	case 15117ULL: goto x86_l_3b0d;
	case 15122ULL: goto x86_l_3b12;
	case 15125ULL: goto x86_l_3b15;
	case 15127ULL: goto x86_l_3b17;
	case 15134ULL: goto x86_l_3b1e;
	case 15140ULL: goto x86_l_3b24;
	case 15147ULL: goto x86_l_3b2b;
	case 15150ULL: goto x86_l_3b2e;
	case 15152ULL: goto x86_l_3b30;
	case 15159ULL: goto x86_l_3b37;
	case 15162ULL: goto x86_l_3b3a;
	case 15168ULL: goto x86_l_3b40;
	case 15173ULL: goto x86_l_3b45;
	case 15176ULL: goto x86_l_3b48;
	case 15178ULL: goto x86_l_3b4a;
	case 15185ULL: goto x86_l_3b51;
	case 15191ULL: goto x86_l_3b57;
	case 15198ULL: goto x86_l_3b5e;
	case 15201ULL: goto x86_l_3b61;
	case 15203ULL: goto x86_l_3b63;
	case 15210ULL: goto x86_l_3b6a;
	case 15213ULL: goto x86_l_3b6d;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15227ULL: goto x86_l_3b7b;
	case 15229ULL: goto x86_l_3b7d;
	case 15236ULL: goto x86_l_3b84;
	case 15242ULL: goto x86_l_3b8a;
	case 15249ULL: goto x86_l_3b91;
	case 15252ULL: goto x86_l_3b94;
	case 15254ULL: goto x86_l_3b96;
	case 15261ULL: goto x86_l_3b9d;
	case 15264ULL: goto x86_l_3ba0;
	case 15270ULL: goto x86_l_3ba6;
	case 15275ULL: goto x86_l_3bab;
	case 15278ULL: goto x86_l_3bae;
	case 15280ULL: goto x86_l_3bb0;
	case 15287ULL: goto x86_l_3bb7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_34c3:
	/* 0x34c3: jbe    34da <tail_policy_denied_ipv6+0x34da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34da;
	}
x86_l_34c5:
	/* 0x34c5: add    rcx,0x387 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 903ULL);
x86_l_34cc:
	/* 0x34cc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_34cf:
	/* 0x34cf: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_34d5:
	/* 0x34d5: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_34da:
	/* 0x34da: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34dd:
	/* 0x34dd: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34df:
	/* 0x34df: cmp    r14d,0x37a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 890ULL);
x86_l_34e6:
	/* 0x34e6: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_34ec:
	/* 0x34ec: lea    rdi,[rcx+0x38a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 906ULL);
x86_l_34f3:
	/* 0x34f3: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_34f6:
	/* 0x34f6: jbe    350d <tail_policy_denied_ipv6+0x350d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_350d;
	}
x86_l_34f8:
	/* 0x34f8: add    rcx,0x389 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 905ULL);
x86_l_34ff:
	/* 0x34ff: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3502:
	/* 0x3502: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3508:
	/* 0x3508: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_350d:
	/* 0x350d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3510:
	/* 0x3510: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3512:
	/* 0x3512: cmp    r14d,0x37c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 892ULL);
x86_l_3519:
	/* 0x3519: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_351f:
	/* 0x351f: lea    rsi,[rcx+0x38c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 908ULL);
x86_l_3526:
	/* 0x3526: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3529:
	/* 0x3529: jbe    3540 <tail_policy_denied_ipv6+0x3540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3540;
	}
x86_l_352b:
	/* 0x352b: add    rcx,0x38b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 907ULL);
x86_l_3532:
	/* 0x3532: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3535:
	/* 0x3535: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_353b:
	/* 0x353b: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3540:
	/* 0x3540: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3543:
	/* 0x3543: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3545:
	/* 0x3545: cmp    r14d,0x37e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 894ULL);
x86_l_354c:
	/* 0x354c: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3552:
	/* 0x3552: lea    rdi,[rcx+0x38e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 910ULL);
x86_l_3559:
	/* 0x3559: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_355c:
	/* 0x355c: jbe    3573 <tail_policy_denied_ipv6+0x3573> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3573;
	}
x86_l_355e:
	/* 0x355e: add    rcx,0x38d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 909ULL);
x86_l_3565:
	/* 0x3565: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3568:
	/* 0x3568: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_356e:
	/* 0x356e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3573:
	/* 0x3573: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3576:
	/* 0x3576: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3578:
	/* 0x3578: cmp    r14d,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_357f:
	/* 0x357f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3585:
	/* 0x3585: lea    rsi,[rcx+0x410] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_358c:
	/* 0x358c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_358f:
	/* 0x358f: jbe    35ad <tail_policy_denied_ipv6+0x35ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_35ad;
	}
x86_l_3591:
	/* 0x3591: lea    rsi,[rcx+0x40f] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1039ULL);
x86_l_3598:
	/* 0x3598: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_359b:
	/* 0x359b: ja     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 16931ULL;
	}
x86_l_35a1:
	/* 0x35a1: movzx  ecx,BYTE PTR [rcx+0x40e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1038ULL);
x86_l_35a8:
	/* 0x35a8: jmp    539 <tail_policy_denied_ipv6+0x539> */
	return 1337ULL;
x86_l_35ad:
	/* 0x35ad: movzx  edi,WORD PTR [rcx+0x40e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 1038ULL);
x86_l_35b4:
	/* 0x35b4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_35b6:
	/* 0x35b6: cmp    r14d,0x402 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1026ULL);
x86_l_35bd:
	/* 0x35bd: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_35c3:
	/* 0x35c3: lea    rdi,[rcx+0x412] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1042ULL);
x86_l_35ca:
	/* 0x35ca: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_35cd:
	/* 0x35cd: jbe    35e4 <tail_policy_denied_ipv6+0x35e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_35e4;
	}
x86_l_35cf:
	/* 0x35cf: add    rcx,0x411 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1041ULL);
x86_l_35d6:
	/* 0x35d6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_35d9:
	/* 0x35d9: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_35df:
	/* 0x35df: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_35e4:
	/* 0x35e4: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35e7:
	/* 0x35e7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_35e9:
	/* 0x35e9: cmp    r14d,0x404 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1028ULL);
x86_l_35f0:
	/* 0x35f0: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_35f6:
	/* 0x35f6: lea    rsi,[rcx+0x414] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1044ULL);
x86_l_35fd:
	/* 0x35fd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3600:
	/* 0x3600: jbe    3617 <tail_policy_denied_ipv6+0x3617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3617;
	}
x86_l_3602:
	/* 0x3602: add    rcx,0x413 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1043ULL);
x86_l_3609:
	/* 0x3609: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_360c:
	/* 0x360c: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3612:
	/* 0x3612: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3617:
	/* 0x3617: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_361a:
	/* 0x361a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_361c:
	/* 0x361c: cmp    r14d,0x406 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1030ULL);
x86_l_3623:
	/* 0x3623: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3629:
	/* 0x3629: lea    rdi,[rcx+0x416] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1046ULL);
x86_l_3630:
	/* 0x3630: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3633:
	/* 0x3633: jbe    364a <tail_policy_denied_ipv6+0x364a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_364a;
	}
x86_l_3635:
	/* 0x3635: add    rcx,0x415 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1045ULL);
x86_l_363c:
	/* 0x363c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_363f:
	/* 0x363f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3645:
	/* 0x3645: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_364a:
	/* 0x364a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_364d:
	/* 0x364d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_364f:
	/* 0x364f: cmp    r14d,0x408 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1032ULL);
x86_l_3656:
	/* 0x3656: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_365c:
	/* 0x365c: lea    rsi,[rcx+0x418] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1048ULL);
x86_l_3663:
	/* 0x3663: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3666:
	/* 0x3666: jbe    367d <tail_policy_denied_ipv6+0x367d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_367d;
	}
x86_l_3668:
	/* 0x3668: add    rcx,0x417 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1047ULL);
x86_l_366f:
	/* 0x366f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3672:
	/* 0x3672: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3678:
	/* 0x3678: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_367d:
	/* 0x367d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3680:
	/* 0x3680: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3682:
	/* 0x3682: cmp    r14d,0x40a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1034ULL);
x86_l_3689:
	/* 0x3689: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_368f:
	/* 0x368f: lea    rdi,[rcx+0x41a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1050ULL);
x86_l_3696:
	/* 0x3696: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3699:
	/* 0x3699: jbe    36b0 <tail_policy_denied_ipv6+0x36b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_36b0;
	}
x86_l_369b:
	/* 0x369b: add    rcx,0x419 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1049ULL);
x86_l_36a2:
	/* 0x36a2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_36a5:
	/* 0x36a5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_36ab:
	/* 0x36ab: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_36b0:
	/* 0x36b0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36b3:
	/* 0x36b3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36b5:
	/* 0x36b5: cmp    r14d,0x40c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1036ULL);
x86_l_36bc:
	/* 0x36bc: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_36c2:
	/* 0x36c2: lea    rsi,[rcx+0x41c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1052ULL);
x86_l_36c9:
	/* 0x36c9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_36cc:
	/* 0x36cc: jbe    36e3 <tail_policy_denied_ipv6+0x36e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_36e3;
	}
x86_l_36ce:
	/* 0x36ce: add    rcx,0x41b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1051ULL);
x86_l_36d5:
	/* 0x36d5: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_36d8:
	/* 0x36d8: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_36de:
	/* 0x36de: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_36e3:
	/* 0x36e3: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36e6:
	/* 0x36e6: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36e8:
	/* 0x36e8: cmp    r14d,0x40e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1038ULL);
x86_l_36ef:
	/* 0x36ef: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_36f5:
	/* 0x36f5: lea    rdi,[rcx+0x41e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1054ULL);
x86_l_36fc:
	/* 0x36fc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_36ff:
	/* 0x36ff: jbe    3716 <tail_policy_denied_ipv6+0x3716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3716;
	}
x86_l_3701:
	/* 0x3701: add    rcx,0x41d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1053ULL);
x86_l_3708:
	/* 0x3708: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_370b:
	/* 0x370b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3711:
	/* 0x3711: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3716:
	/* 0x3716: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3719:
	/* 0x3719: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_371b:
	/* 0x371b: cmp    r14d,0x410 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1040ULL);
x86_l_3722:
	/* 0x3722: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3728:
	/* 0x3728: lea    rsi,[rcx+0x420] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1056ULL);
x86_l_372f:
	/* 0x372f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3732:
	/* 0x3732: jbe    3749 <tail_policy_denied_ipv6+0x3749> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3749;
	}
x86_l_3734:
	/* 0x3734: add    rcx,0x41f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1055ULL);
x86_l_373b:
	/* 0x373b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_373e:
	/* 0x373e: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3744:
	/* 0x3744: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3749:
	/* 0x3749: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_374c:
	/* 0x374c: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_374e:
	/* 0x374e: cmp    r14d,0x412 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1042ULL);
x86_l_3755:
	/* 0x3755: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_375b:
	/* 0x375b: lea    rdi,[rcx+0x422] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1058ULL);
x86_l_3762:
	/* 0x3762: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3765:
	/* 0x3765: jbe    377c <tail_policy_denied_ipv6+0x377c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_377c;
	}
x86_l_3767:
	/* 0x3767: add    rcx,0x421 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1057ULL);
x86_l_376e:
	/* 0x376e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3771:
	/* 0x3771: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3777:
	/* 0x3777: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_377c:
	/* 0x377c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_377f:
	/* 0x377f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3781:
	/* 0x3781: cmp    r14d,0x414 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1044ULL);
x86_l_3788:
	/* 0x3788: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_378e:
	/* 0x378e: lea    rsi,[rcx+0x424] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1060ULL);
x86_l_3795:
	/* 0x3795: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3798:
	/* 0x3798: jbe    37af <tail_policy_denied_ipv6+0x37af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_37af;
	}
x86_l_379a:
	/* 0x379a: add    rcx,0x423 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1059ULL);
x86_l_37a1:
	/* 0x37a1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_37a4:
	/* 0x37a4: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_37aa:
	/* 0x37aa: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_37af:
	/* 0x37af: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37b2:
	/* 0x37b2: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_37b4:
	/* 0x37b4: cmp    r14d,0x416 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1046ULL);
x86_l_37bb:
	/* 0x37bb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_37c1:
	/* 0x37c1: lea    rdi,[rcx+0x426] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1062ULL);
x86_l_37c8:
	/* 0x37c8: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_37cb:
	/* 0x37cb: jbe    37e2 <tail_policy_denied_ipv6+0x37e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_37e2;
	}
x86_l_37cd:
	/* 0x37cd: add    rcx,0x425 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1061ULL);
x86_l_37d4:
	/* 0x37d4: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_37d7:
	/* 0x37d7: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_37dd:
	/* 0x37dd: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_37e2:
	/* 0x37e2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37e5:
	/* 0x37e5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_37e7:
	/* 0x37e7: cmp    r14d,0x418 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1048ULL);
x86_l_37ee:
	/* 0x37ee: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_37f4:
	/* 0x37f4: lea    rsi,[rcx+0x428] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1064ULL);
x86_l_37fb:
	/* 0x37fb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_37fe:
	/* 0x37fe: jbe    3815 <tail_policy_denied_ipv6+0x3815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3815;
	}
x86_l_3800:
	/* 0x3800: add    rcx,0x427 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1063ULL);
x86_l_3807:
	/* 0x3807: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_380a:
	/* 0x380a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3810:
	/* 0x3810: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3815:
	/* 0x3815: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3818:
	/* 0x3818: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_381a:
	/* 0x381a: cmp    r14d,0x41a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1050ULL);
x86_l_3821:
	/* 0x3821: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3827:
	/* 0x3827: lea    rdi,[rcx+0x42a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1066ULL);
x86_l_382e:
	/* 0x382e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3831:
	/* 0x3831: jbe    3848 <tail_policy_denied_ipv6+0x3848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3848;
	}
x86_l_3833:
	/* 0x3833: add    rcx,0x429 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1065ULL);
x86_l_383a:
	/* 0x383a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_383d:
	/* 0x383d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3843:
	/* 0x3843: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3848:
	/* 0x3848: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_384b:
	/* 0x384b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_384d:
	/* 0x384d: cmp    r14d,0x41c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1052ULL);
x86_l_3854:
	/* 0x3854: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_385a:
	/* 0x385a: lea    rsi,[rcx+0x42c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1068ULL);
x86_l_3861:
	/* 0x3861: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3864:
	/* 0x3864: jbe    387b <tail_policy_denied_ipv6+0x387b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_387b;
	}
x86_l_3866:
	/* 0x3866: add    rcx,0x42b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1067ULL);
x86_l_386d:
	/* 0x386d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3870:
	/* 0x3870: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3876:
	/* 0x3876: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_387b:
	/* 0x387b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_387e:
	/* 0x387e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3880:
	/* 0x3880: cmp    r14d,0x41e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1054ULL);
x86_l_3887:
	/* 0x3887: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_388d:
	/* 0x388d: lea    rdi,[rcx+0x42e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1070ULL);
x86_l_3894:
	/* 0x3894: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3897:
	/* 0x3897: jbe    38ae <tail_policy_denied_ipv6+0x38ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_38ae;
	}
x86_l_3899:
	/* 0x3899: add    rcx,0x42d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1069ULL);
x86_l_38a0:
	/* 0x38a0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_38a3:
	/* 0x38a3: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_38a9:
	/* 0x38a9: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_38ae:
	/* 0x38ae: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38b1:
	/* 0x38b1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38b3:
	/* 0x38b3: cmp    r14d,0x420 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1056ULL);
x86_l_38ba:
	/* 0x38ba: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_38c0:
	/* 0x38c0: lea    rsi,[rcx+0x430] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1072ULL);
x86_l_38c7:
	/* 0x38c7: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_38ca:
	/* 0x38ca: jbe    38e1 <tail_policy_denied_ipv6+0x38e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_38e1;
	}
x86_l_38cc:
	/* 0x38cc: add    rcx,0x42f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1071ULL);
x86_l_38d3:
	/* 0x38d3: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_38d6:
	/* 0x38d6: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_38dc:
	/* 0x38dc: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_38e1:
	/* 0x38e1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38e4:
	/* 0x38e4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38e6:
	/* 0x38e6: cmp    r14d,0x422 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1058ULL);
x86_l_38ed:
	/* 0x38ed: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_38f3:
	/* 0x38f3: lea    rdi,[rcx+0x432] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1074ULL);
x86_l_38fa:
	/* 0x38fa: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_38fd:
	/* 0x38fd: jbe    3914 <tail_policy_denied_ipv6+0x3914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3914;
	}
x86_l_38ff:
	/* 0x38ff: add    rcx,0x431 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1073ULL);
x86_l_3906:
	/* 0x3906: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3909:
	/* 0x3909: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_390f:
	/* 0x390f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3914:
	/* 0x3914: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3917:
	/* 0x3917: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3919:
	/* 0x3919: cmp    r14d,0x424 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1060ULL);
x86_l_3920:
	/* 0x3920: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3926:
	/* 0x3926: lea    rsi,[rcx+0x434] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1076ULL);
x86_l_392d:
	/* 0x392d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3930:
	/* 0x3930: jbe    3947 <tail_policy_denied_ipv6+0x3947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3947;
	}
x86_l_3932:
	/* 0x3932: add    rcx,0x433 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1075ULL);
x86_l_3939:
	/* 0x3939: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_393c:
	/* 0x393c: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3942:
	/* 0x3942: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3947:
	/* 0x3947: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_394a:
	/* 0x394a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_394c:
	/* 0x394c: cmp    r14d,0x426 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1062ULL);
x86_l_3953:
	/* 0x3953: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3959:
	/* 0x3959: lea    rdi,[rcx+0x436] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1078ULL);
x86_l_3960:
	/* 0x3960: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3963:
	/* 0x3963: jbe    397a <tail_policy_denied_ipv6+0x397a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_397a;
	}
x86_l_3965:
	/* 0x3965: add    rcx,0x435 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1077ULL);
x86_l_396c:
	/* 0x396c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_396f:
	/* 0x396f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3975:
	/* 0x3975: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_397a:
	/* 0x397a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_397d:
	/* 0x397d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_397f:
	/* 0x397f: cmp    r14d,0x428 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1064ULL);
x86_l_3986:
	/* 0x3986: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_398c:
	/* 0x398c: lea    rsi,[rcx+0x438] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1080ULL);
x86_l_3993:
	/* 0x3993: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3996:
	/* 0x3996: jbe    39ad <tail_policy_denied_ipv6+0x39ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_39ad;
	}
x86_l_3998:
	/* 0x3998: add    rcx,0x437 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1079ULL);
x86_l_399f:
	/* 0x399f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_39a2:
	/* 0x39a2: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_39a8:
	/* 0x39a8: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_39ad:
	/* 0x39ad: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39b0:
	/* 0x39b0: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_39b2:
	/* 0x39b2: cmp    r14d,0x42a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1066ULL);
x86_l_39b9:
	/* 0x39b9: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_39bf:
	/* 0x39bf: lea    rdi,[rcx+0x43a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1082ULL);
x86_l_39c6:
	/* 0x39c6: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_39c9:
	/* 0x39c9: jbe    39e0 <tail_policy_denied_ipv6+0x39e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_39e0;
	}
x86_l_39cb:
	/* 0x39cb: add    rcx,0x439 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1081ULL);
x86_l_39d2:
	/* 0x39d2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_39d5:
	/* 0x39d5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_39db:
	/* 0x39db: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_39e0:
	/* 0x39e0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39e3:
	/* 0x39e3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_39e5:
	/* 0x39e5: cmp    r14d,0x42c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1068ULL);
x86_l_39ec:
	/* 0x39ec: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_39f2:
	/* 0x39f2: lea    rsi,[rcx+0x43c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1084ULL);
x86_l_39f9:
	/* 0x39f9: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_39fc:
	/* 0x39fc: jbe    3a13 <tail_policy_denied_ipv6+0x3a13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3a13;
	}
x86_l_39fe:
	/* 0x39fe: add    rcx,0x43b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1083ULL);
x86_l_3a05:
	/* 0x3a05: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3a08:
	/* 0x3a08: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3a0e:
	/* 0x3a0e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3a13:
	/* 0x3a13: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a16:
	/* 0x3a16: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3a18:
	/* 0x3a18: cmp    r14d,0x42e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1070ULL);
x86_l_3a1f:
	/* 0x3a1f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3a25:
	/* 0x3a25: lea    rdi,[rcx+0x43e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1086ULL);
x86_l_3a2c:
	/* 0x3a2c: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3a2f:
	/* 0x3a2f: jbe    3a46 <tail_policy_denied_ipv6+0x3a46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3a46;
	}
x86_l_3a31:
	/* 0x3a31: add    rcx,0x43d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1085ULL);
x86_l_3a38:
	/* 0x3a38: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3a3b:
	/* 0x3a3b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3a41:
	/* 0x3a41: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3a46:
	/* 0x3a46: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a49:
	/* 0x3a49: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3a4b:
	/* 0x3a4b: cmp    r14d,0x430 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1072ULL);
x86_l_3a52:
	/* 0x3a52: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3a58:
	/* 0x3a58: lea    rsi,[rcx+0x440] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1088ULL);
x86_l_3a5f:
	/* 0x3a5f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3a62:
	/* 0x3a62: jbe    3a79 <tail_policy_denied_ipv6+0x3a79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3a79;
	}
x86_l_3a64:
	/* 0x3a64: add    rcx,0x43f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1087ULL);
x86_l_3a6b:
	/* 0x3a6b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3a6e:
	/* 0x3a6e: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3a74:
	/* 0x3a74: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3a79:
	/* 0x3a79: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a7c:
	/* 0x3a7c: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3a7e:
	/* 0x3a7e: cmp    r14d,0x432 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1074ULL);
x86_l_3a85:
	/* 0x3a85: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3a8b:
	/* 0x3a8b: lea    rdi,[rcx+0x442] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1090ULL);
x86_l_3a92:
	/* 0x3a92: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3a95:
	/* 0x3a95: jbe    3aac <tail_policy_denied_ipv6+0x3aac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3aac;
	}
x86_l_3a97:
	/* 0x3a97: add    rcx,0x441 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1089ULL);
x86_l_3a9e:
	/* 0x3a9e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3aa1:
	/* 0x3aa1: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3aa7:
	/* 0x3aa7: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3aac:
	/* 0x3aac: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3aaf:
	/* 0x3aaf: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ab1:
	/* 0x3ab1: cmp    r14d,0x434 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1076ULL);
x86_l_3ab8:
	/* 0x3ab8: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3abe:
	/* 0x3abe: lea    rsi,[rcx+0x444] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1092ULL);
x86_l_3ac5:
	/* 0x3ac5: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3ac8:
	/* 0x3ac8: jbe    3adf <tail_policy_denied_ipv6+0x3adf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3adf;
	}
x86_l_3aca:
	/* 0x3aca: add    rcx,0x443 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1091ULL);
x86_l_3ad1:
	/* 0x3ad1: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3ad4:
	/* 0x3ad4: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3ada:
	/* 0x3ada: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3adf:
	/* 0x3adf: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ae2:
	/* 0x3ae2: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ae4:
	/* 0x3ae4: cmp    r14d,0x436 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1078ULL);
x86_l_3aeb:
	/* 0x3aeb: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3af1:
	/* 0x3af1: lea    rdi,[rcx+0x446] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1094ULL);
x86_l_3af8:
	/* 0x3af8: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3afb:
	/* 0x3afb: jbe    3b12 <tail_policy_denied_ipv6+0x3b12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b12;
	}
x86_l_3afd:
	/* 0x3afd: add    rcx,0x445 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1093ULL);
x86_l_3b04:
	/* 0x3b04: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3b07:
	/* 0x3b07: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3b0d:
	/* 0x3b0d: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3b12:
	/* 0x3b12: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b15:
	/* 0x3b15: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b17:
	/* 0x3b17: cmp    r14d,0x438 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1080ULL);
x86_l_3b1e:
	/* 0x3b1e: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3b24:
	/* 0x3b24: lea    rsi,[rcx+0x448] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1096ULL);
x86_l_3b2b:
	/* 0x3b2b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3b2e:
	/* 0x3b2e: jbe    3b45 <tail_policy_denied_ipv6+0x3b45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b45;
	}
x86_l_3b30:
	/* 0x3b30: add    rcx,0x447 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1095ULL);
x86_l_3b37:
	/* 0x3b37: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3b3a:
	/* 0x3b3a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3b40:
	/* 0x3b40: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3b45:
	/* 0x3b45: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b48:
	/* 0x3b48: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b4a:
	/* 0x3b4a: cmp    r14d,0x43a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1082ULL);
x86_l_3b51:
	/* 0x3b51: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3b57:
	/* 0x3b57: lea    rdi,[rcx+0x44a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1098ULL);
x86_l_3b5e:
	/* 0x3b5e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3b61:
	/* 0x3b61: jbe    3b78 <tail_policy_denied_ipv6+0x3b78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b78;
	}
x86_l_3b63:
	/* 0x3b63: add    rcx,0x449 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1097ULL);
x86_l_3b6a:
	/* 0x3b6a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3b6d:
	/* 0x3b6d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3b73:
	/* 0x3b73: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3b78:
	/* 0x3b78: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b7b:
	/* 0x3b7b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3b7d:
	/* 0x3b7d: cmp    r14d,0x43c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1084ULL);
x86_l_3b84:
	/* 0x3b84: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
x86_l_3b8a:
	/* 0x3b8a: lea    rsi,[rcx+0x44c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1100ULL);
x86_l_3b91:
	/* 0x3b91: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3b94:
	/* 0x3b94: jbe    3bab <tail_policy_denied_ipv6+0x3bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3bab;
	}
x86_l_3b96:
	/* 0x3b96: add    rcx,0x44b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1099ULL);
x86_l_3b9d:
	/* 0x3b9d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3ba0:
	/* 0x3ba0: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3ba6:
	/* 0x3ba6: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	return 16931ULL;
x86_l_3bab:
	/* 0x3bab: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bae:
	/* 0x3bae: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3bb0:
	/* 0x3bb0: cmp    r14d,0x43e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1086ULL);
x86_l_3bb7:
	/* 0x3bb7: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 15842ULL;
	}
	return 15293ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15293ULL: goto x86_l_3bbd;
	case 15300ULL: goto x86_l_3bc4;
	case 15303ULL: goto x86_l_3bc7;
	case 15305ULL: goto x86_l_3bc9;
	case 15312ULL: goto x86_l_3bd0;
	case 15315ULL: goto x86_l_3bd3;
	case 15321ULL: goto x86_l_3bd9;
	case 15326ULL: goto x86_l_3bde;
	case 15329ULL: goto x86_l_3be1;
	case 15331ULL: goto x86_l_3be3;
	case 15338ULL: goto x86_l_3bea;
	case 15344ULL: goto x86_l_3bf0;
	case 15351ULL: goto x86_l_3bf7;
	case 15354ULL: goto x86_l_3bfa;
	case 15356ULL: goto x86_l_3bfc;
	case 15363ULL: goto x86_l_3c03;
	case 15366ULL: goto x86_l_3c06;
	case 15372ULL: goto x86_l_3c0c;
	case 15377ULL: goto x86_l_3c11;
	case 15380ULL: goto x86_l_3c14;
	case 15382ULL: goto x86_l_3c16;
	case 15389ULL: goto x86_l_3c1d;
	case 15395ULL: goto x86_l_3c23;
	case 15402ULL: goto x86_l_3c2a;
	case 15405ULL: goto x86_l_3c2d;
	case 15407ULL: goto x86_l_3c2f;
	case 15414ULL: goto x86_l_3c36;
	case 15417ULL: goto x86_l_3c39;
	case 15423ULL: goto x86_l_3c3f;
	case 15428ULL: goto x86_l_3c44;
	case 15431ULL: goto x86_l_3c47;
	case 15433ULL: goto x86_l_3c49;
	case 15440ULL: goto x86_l_3c50;
	case 15446ULL: goto x86_l_3c56;
	case 15453ULL: goto x86_l_3c5d;
	case 15456ULL: goto x86_l_3c60;
	case 15458ULL: goto x86_l_3c62;
	case 15465ULL: goto x86_l_3c69;
	case 15468ULL: goto x86_l_3c6c;
	case 15474ULL: goto x86_l_3c72;
	case 15479ULL: goto x86_l_3c77;
	case 15482ULL: goto x86_l_3c7a;
	case 15484ULL: goto x86_l_3c7c;
	case 15491ULL: goto x86_l_3c83;
	case 15497ULL: goto x86_l_3c89;
	case 15504ULL: goto x86_l_3c90;
	case 15507ULL: goto x86_l_3c93;
	case 15509ULL: goto x86_l_3c95;
	case 15516ULL: goto x86_l_3c9c;
	case 15519ULL: goto x86_l_3c9f;
	case 15525ULL: goto x86_l_3ca5;
	case 15530ULL: goto x86_l_3caa;
	case 15533ULL: goto x86_l_3cad;
	case 15535ULL: goto x86_l_3caf;
	case 15542ULL: goto x86_l_3cb6;
	case 15548ULL: goto x86_l_3cbc;
	case 15555ULL: goto x86_l_3cc3;
	case 15558ULL: goto x86_l_3cc6;
	case 15560ULL: goto x86_l_3cc8;
	case 15567ULL: goto x86_l_3ccf;
	case 15570ULL: goto x86_l_3cd2;
	case 15576ULL: goto x86_l_3cd8;
	case 15581ULL: goto x86_l_3cdd;
	case 15584ULL: goto x86_l_3ce0;
	case 15586ULL: goto x86_l_3ce2;
	case 15593ULL: goto x86_l_3ce9;
	case 15599ULL: goto x86_l_3cef;
	case 15606ULL: goto x86_l_3cf6;
	case 15609ULL: goto x86_l_3cf9;
	case 15611ULL: goto x86_l_3cfb;
	case 15618ULL: goto x86_l_3d02;
	case 15621ULL: goto x86_l_3d05;
	case 15627ULL: goto x86_l_3d0b;
	case 15632ULL: goto x86_l_3d10;
	case 15635ULL: goto x86_l_3d13;
	case 15637ULL: goto x86_l_3d15;
	case 15644ULL: goto x86_l_3d1c;
	case 15650ULL: goto x86_l_3d22;
	case 15657ULL: goto x86_l_3d29;
	case 15660ULL: goto x86_l_3d2c;
	case 15662ULL: goto x86_l_3d2e;
	case 15669ULL: goto x86_l_3d35;
	case 15672ULL: goto x86_l_3d38;
	case 15678ULL: goto x86_l_3d3e;
	case 15683ULL: goto x86_l_3d43;
	case 15686ULL: goto x86_l_3d46;
	case 15688ULL: goto x86_l_3d48;
	case 15695ULL: goto x86_l_3d4f;
	case 15701ULL: goto x86_l_3d55;
	case 15708ULL: goto x86_l_3d5c;
	case 15711ULL: goto x86_l_3d5f;
	case 15713ULL: goto x86_l_3d61;
	case 15720ULL: goto x86_l_3d68;
	case 15723ULL: goto x86_l_3d6b;
	case 15729ULL: goto x86_l_3d71;
	case 15734ULL: goto x86_l_3d76;
	case 15737ULL: goto x86_l_3d79;
	case 15739ULL: goto x86_l_3d7b;
	case 15746ULL: goto x86_l_3d82;
	case 15748ULL: goto x86_l_3d84;
	case 15755ULL: goto x86_l_3d8b;
	case 15758ULL: goto x86_l_3d8e;
	case 15760ULL: goto x86_l_3d90;
	case 15767ULL: goto x86_l_3d97;
	case 15770ULL: goto x86_l_3d9a;
	case 15776ULL: goto x86_l_3da0;
	case 15781ULL: goto x86_l_3da5;
	case 15784ULL: goto x86_l_3da8;
	case 15786ULL: goto x86_l_3daa;
	case 15793ULL: goto x86_l_3db1;
	case 15795ULL: goto x86_l_3db3;
	case 15802ULL: goto x86_l_3dba;
	case 15805ULL: goto x86_l_3dbd;
	case 15807ULL: goto x86_l_3dbf;
	case 15814ULL: goto x86_l_3dc6;
	case 15817ULL: goto x86_l_3dc9;
	case 15823ULL: goto x86_l_3dcf;
	case 15828ULL: goto x86_l_3dd4;
	case 15831ULL: goto x86_l_3dd7;
	case 15833ULL: goto x86_l_3dd9;
	case 15840ULL: goto x86_l_3de0;
	case 15842ULL: goto x86_l_3de2;
	case 15845ULL: goto x86_l_3de5;
	case 15850ULL: goto x86_l_3dea;
	case 15857ULL: goto x86_l_3df1;
	case 15860ULL: goto x86_l_3df4;
	case 15862ULL: goto x86_l_3df6;
	case 15869ULL: goto x86_l_3dfd;
	case 15872ULL: goto x86_l_3e00;
	case 15878ULL: goto x86_l_3e06;
	case 15883ULL: goto x86_l_3e0b;
	case 15886ULL: goto x86_l_3e0e;
	case 15888ULL: goto x86_l_3e10;
	case 15895ULL: goto x86_l_3e17;
	case 15901ULL: goto x86_l_3e1d;
	case 15908ULL: goto x86_l_3e24;
	case 15911ULL: goto x86_l_3e27;
	case 15913ULL: goto x86_l_3e29;
	case 15920ULL: goto x86_l_3e30;
	case 15923ULL: goto x86_l_3e33;
	case 15929ULL: goto x86_l_3e39;
	case 15934ULL: goto x86_l_3e3e;
	case 15937ULL: goto x86_l_3e41;
	case 15939ULL: goto x86_l_3e43;
	case 15946ULL: goto x86_l_3e4a;
	case 15952ULL: goto x86_l_3e50;
	case 15959ULL: goto x86_l_3e57;
	case 15962ULL: goto x86_l_3e5a;
	case 15964ULL: goto x86_l_3e5c;
	case 15971ULL: goto x86_l_3e63;
	case 15974ULL: goto x86_l_3e66;
	case 15980ULL: goto x86_l_3e6c;
	case 15985ULL: goto x86_l_3e71;
	case 15988ULL: goto x86_l_3e74;
	case 15990ULL: goto x86_l_3e76;
	case 15997ULL: goto x86_l_3e7d;
	case 16003ULL: goto x86_l_3e83;
	case 16010ULL: goto x86_l_3e8a;
	case 16013ULL: goto x86_l_3e8d;
	case 16015ULL: goto x86_l_3e8f;
	case 16022ULL: goto x86_l_3e96;
	case 16025ULL: goto x86_l_3e99;
	case 16031ULL: goto x86_l_3e9f;
	case 16036ULL: goto x86_l_3ea4;
	case 16039ULL: goto x86_l_3ea7;
	case 16041ULL: goto x86_l_3ea9;
	case 16048ULL: goto x86_l_3eb0;
	case 16054ULL: goto x86_l_3eb6;
	case 16061ULL: goto x86_l_3ebd;
	case 16064ULL: goto x86_l_3ec0;
	case 16066ULL: goto x86_l_3ec2;
	case 16073ULL: goto x86_l_3ec9;
	case 16076ULL: goto x86_l_3ecc;
	case 16082ULL: goto x86_l_3ed2;
	case 16087ULL: goto x86_l_3ed7;
	case 16090ULL: goto x86_l_3eda;
	case 16092ULL: goto x86_l_3edc;
	case 16099ULL: goto x86_l_3ee3;
	case 16105ULL: goto x86_l_3ee9;
	case 16112ULL: goto x86_l_3ef0;
	case 16115ULL: goto x86_l_3ef3;
	case 16117ULL: goto x86_l_3ef5;
	case 16124ULL: goto x86_l_3efc;
	case 16127ULL: goto x86_l_3eff;
	case 16133ULL: goto x86_l_3f05;
	case 16138ULL: goto x86_l_3f0a;
	case 16141ULL: goto x86_l_3f0d;
	case 16143ULL: goto x86_l_3f0f;
	case 16150ULL: goto x86_l_3f16;
	case 16156ULL: goto x86_l_3f1c;
	case 16163ULL: goto x86_l_3f23;
	case 16166ULL: goto x86_l_3f26;
	case 16168ULL: goto x86_l_3f28;
	case 16175ULL: goto x86_l_3f2f;
	case 16178ULL: goto x86_l_3f32;
	case 16184ULL: goto x86_l_3f38;
	case 16189ULL: goto x86_l_3f3d;
	case 16192ULL: goto x86_l_3f40;
	case 16194ULL: goto x86_l_3f42;
	case 16201ULL: goto x86_l_3f49;
	case 16207ULL: goto x86_l_3f4f;
	case 16214ULL: goto x86_l_3f56;
	case 16217ULL: goto x86_l_3f59;
	case 16219ULL: goto x86_l_3f5b;
	case 16226ULL: goto x86_l_3f62;
	case 16229ULL: goto x86_l_3f65;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16243ULL: goto x86_l_3f73;
	case 16245ULL: goto x86_l_3f75;
	case 16252ULL: goto x86_l_3f7c;
	case 16258ULL: goto x86_l_3f82;
	case 16265ULL: goto x86_l_3f89;
	case 16268ULL: goto x86_l_3f8c;
	case 16270ULL: goto x86_l_3f8e;
	case 16277ULL: goto x86_l_3f95;
	case 16280ULL: goto x86_l_3f98;
	case 16286ULL: goto x86_l_3f9e;
	case 16291ULL: goto x86_l_3fa3;
	case 16294ULL: goto x86_l_3fa6;
	case 16296ULL: goto x86_l_3fa8;
	case 16303ULL: goto x86_l_3faf;
	case 16309ULL: goto x86_l_3fb5;
	case 16316ULL: goto x86_l_3fbc;
	case 16319ULL: goto x86_l_3fbf;
	case 16321ULL: goto x86_l_3fc1;
	case 16328ULL: goto x86_l_3fc8;
	case 16331ULL: goto x86_l_3fcb;
	case 16337ULL: goto x86_l_3fd1;
	case 16342ULL: goto x86_l_3fd6;
	case 16345ULL: goto x86_l_3fd9;
	case 16347ULL: goto x86_l_3fdb;
	case 16354ULL: goto x86_l_3fe2;
	case 16360ULL: goto x86_l_3fe8;
	case 16367ULL: goto x86_l_3fef;
	case 16370ULL: goto x86_l_3ff2;
	case 16372ULL: goto x86_l_3ff4;
	case 16379ULL: goto x86_l_3ffb;
	case 16382ULL: goto x86_l_3ffe;
	case 16388ULL: goto x86_l_4004;
	case 16393ULL: goto x86_l_4009;
	case 16396ULL: goto x86_l_400c;
	case 16398ULL: goto x86_l_400e;
	case 16405ULL: goto x86_l_4015;
	case 16411ULL: goto x86_l_401b;
	case 16418ULL: goto x86_l_4022;
	case 16421ULL: goto x86_l_4025;
	case 16423ULL: goto x86_l_4027;
	case 16430ULL: goto x86_l_402e;
	case 16433ULL: goto x86_l_4031;
	case 16439ULL: goto x86_l_4037;
	case 16444ULL: goto x86_l_403c;
	case 16447ULL: goto x86_l_403f;
	case 16449ULL: goto x86_l_4041;
	case 16456ULL: goto x86_l_4048;
	case 16462ULL: goto x86_l_404e;
	case 16469ULL: goto x86_l_4055;
	case 16472ULL: goto x86_l_4058;
	case 16474ULL: goto x86_l_405a;
	case 16481ULL: goto x86_l_4061;
	case 16484ULL: goto x86_l_4064;
	case 16490ULL: goto x86_l_406a;
	case 16495ULL: goto x86_l_406f;
	case 16498ULL: goto x86_l_4072;
	case 16500ULL: goto x86_l_4074;
	case 16507ULL: goto x86_l_407b;
	case 16513ULL: goto x86_l_4081;
	case 16520ULL: goto x86_l_4088;
	case 16523ULL: goto x86_l_408b;
	case 16525ULL: goto x86_l_408d;
	case 16532ULL: goto x86_l_4094;
	case 16535ULL: goto x86_l_4097;
	case 16541ULL: goto x86_l_409d;
	case 16546ULL: goto x86_l_40a2;
	case 16549ULL: goto x86_l_40a5;
	case 16551ULL: goto x86_l_40a7;
	case 16558ULL: goto x86_l_40ae;
	case 16564ULL: goto x86_l_40b4;
	case 16571ULL: goto x86_l_40bb;
	case 16574ULL: goto x86_l_40be;
	case 16576ULL: goto x86_l_40c0;
	case 16583ULL: goto x86_l_40c7;
	case 16586ULL: goto x86_l_40ca;
	case 16592ULL: goto x86_l_40d0;
	case 16597ULL: goto x86_l_40d5;
	case 16600ULL: goto x86_l_40d8;
	case 16602ULL: goto x86_l_40da;
	case 16609ULL: goto x86_l_40e1;
	case 16615ULL: goto x86_l_40e7;
	case 16622ULL: goto x86_l_40ee;
	case 16625ULL: goto x86_l_40f1;
	case 16627ULL: goto x86_l_40f3;
	case 16634ULL: goto x86_l_40fa;
	case 16637ULL: goto x86_l_40fd;
	case 16643ULL: goto x86_l_4103;
	case 16648ULL: goto x86_l_4108;
	case 16651ULL: goto x86_l_410b;
	case 16653ULL: goto x86_l_410d;
	case 16660ULL: goto x86_l_4114;
	case 16666ULL: goto x86_l_411a;
	case 16673ULL: goto x86_l_4121;
	case 16676ULL: goto x86_l_4124;
	case 16678ULL: goto x86_l_4126;
	case 16685ULL: goto x86_l_412d;
	case 16688ULL: goto x86_l_4130;
	case 16694ULL: goto x86_l_4136;
	case 16699ULL: goto x86_l_413b;
	case 16702ULL: goto x86_l_413e;
	case 16704ULL: goto x86_l_4140;
	case 16711ULL: goto x86_l_4147;
	case 16717ULL: goto x86_l_414d;
	case 16724ULL: goto x86_l_4154;
	case 16727ULL: goto x86_l_4157;
	case 16729ULL: goto x86_l_4159;
	case 16736ULL: goto x86_l_4160;
	case 16739ULL: goto x86_l_4163;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16753ULL: goto x86_l_4171;
	case 16755ULL: goto x86_l_4173;
	case 16762ULL: goto x86_l_417a;
	case 16768ULL: goto x86_l_4180;
	case 16775ULL: goto x86_l_4187;
	case 16778ULL: goto x86_l_418a;
	case 16780ULL: goto x86_l_418c;
	case 16787ULL: goto x86_l_4193;
	case 16790ULL: goto x86_l_4196;
	case 16796ULL: goto x86_l_419c;
	case 16801ULL: goto x86_l_41a1;
	case 16804ULL: goto x86_l_41a4;
	case 16806ULL: goto x86_l_41a6;
	case 16813ULL: goto x86_l_41ad;
	case 16815ULL: goto x86_l_41af;
	case 16822ULL: goto x86_l_41b6;
	case 16825ULL: goto x86_l_41b9;
	case 16827ULL: goto x86_l_41bb;
	case 16834ULL: goto x86_l_41c2;
	case 16837ULL: goto x86_l_41c5;
	case 16843ULL: goto x86_l_41cb;
	case 16845ULL: goto x86_l_41cd;
	case 16848ULL: goto x86_l_41d0;
	case 16850ULL: goto x86_l_41d2;
	case 16857ULL: goto x86_l_41d9;
	case 16859ULL: goto x86_l_41db;
	case 16866ULL: goto x86_l_41e2;
	case 16869ULL: goto x86_l_41e5;
	case 16871ULL: goto x86_l_41e7;
	case 16878ULL: goto x86_l_41ee;
	case 16881ULL: goto x86_l_41f1;
	case 16887ULL: goto x86_l_41f7;
	case 16889ULL: goto x86_l_41f9;
	case 16892ULL: goto x86_l_41fc;
	case 16894ULL: goto x86_l_41fe;
	case 16901ULL: goto x86_l_4205;
	case 16903ULL: goto x86_l_4207;
	case 16910ULL: goto x86_l_420e;
	case 16913ULL: goto x86_l_4211;
	case 16915ULL: goto x86_l_4213;
	case 16922ULL: goto x86_l_421a;
	case 16925ULL: goto x86_l_421d;
	case 16931ULL: goto x86_l_4223;
	case 16934ULL: goto x86_l_4226;
	case 16939ULL: goto x86_l_422b;
	case 16942ULL: goto x86_l_422e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3bbd:
	/* 0x3bbd: lea    rdi,[rcx+0x44e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1102ULL);
x86_l_3bc4:
	/* 0x3bc4: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3bc7:
	/* 0x3bc7: jbe    3bde <tail_policy_denied_ipv6+0x3bde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3bde;
	}
x86_l_3bc9:
	/* 0x3bc9: add    rcx,0x44d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1101ULL);
x86_l_3bd0:
	/* 0x3bd0: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3bd3:
	/* 0x3bd3: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3bd9:
	/* 0x3bd9: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3bde:
	/* 0x3bde: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3be1:
	/* 0x3be1: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3be3:
	/* 0x3be3: cmp    r14d,0x440 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1088ULL);
x86_l_3bea:
	/* 0x3bea: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3bf0:
	/* 0x3bf0: lea    rsi,[rcx+0x450] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1104ULL);
x86_l_3bf7:
	/* 0x3bf7: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3bfa:
	/* 0x3bfa: jbe    3c11 <tail_policy_denied_ipv6+0x3c11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3c11;
	}
x86_l_3bfc:
	/* 0x3bfc: add    rcx,0x44f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1103ULL);
x86_l_3c03:
	/* 0x3c03: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3c06:
	/* 0x3c06: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3c0c:
	/* 0x3c0c: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3c11:
	/* 0x3c11: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c14:
	/* 0x3c14: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c16:
	/* 0x3c16: cmp    r14d,0x442 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1090ULL);
x86_l_3c1d:
	/* 0x3c1d: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3c23:
	/* 0x3c23: lea    rdi,[rcx+0x452] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1106ULL);
x86_l_3c2a:
	/* 0x3c2a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3c2d:
	/* 0x3c2d: jbe    3c44 <tail_policy_denied_ipv6+0x3c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3c44;
	}
x86_l_3c2f:
	/* 0x3c2f: add    rcx,0x451 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1105ULL);
x86_l_3c36:
	/* 0x3c36: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3c39:
	/* 0x3c39: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3c3f:
	/* 0x3c3f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3c44:
	/* 0x3c44: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c47:
	/* 0x3c47: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c49:
	/* 0x3c49: cmp    r14d,0x444 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1092ULL);
x86_l_3c50:
	/* 0x3c50: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3c56:
	/* 0x3c56: lea    rsi,[rcx+0x454] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1108ULL);
x86_l_3c5d:
	/* 0x3c5d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3c60:
	/* 0x3c60: jbe    3c77 <tail_policy_denied_ipv6+0x3c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3c77;
	}
x86_l_3c62:
	/* 0x3c62: add    rcx,0x453 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1107ULL);
x86_l_3c69:
	/* 0x3c69: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3c6c:
	/* 0x3c6c: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3c72:
	/* 0x3c72: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3c77:
	/* 0x3c77: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c7a:
	/* 0x3c7a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c7c:
	/* 0x3c7c: cmp    r14d,0x446 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1094ULL);
x86_l_3c83:
	/* 0x3c83: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3c89:
	/* 0x3c89: lea    rdi,[rcx+0x456] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1110ULL);
x86_l_3c90:
	/* 0x3c90: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3c93:
	/* 0x3c93: jbe    3caa <tail_policy_denied_ipv6+0x3caa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3caa;
	}
x86_l_3c95:
	/* 0x3c95: add    rcx,0x455 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1109ULL);
x86_l_3c9c:
	/* 0x3c9c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3c9f:
	/* 0x3c9f: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3ca5:
	/* 0x3ca5: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3caa:
	/* 0x3caa: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cad:
	/* 0x3cad: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3caf:
	/* 0x3caf: cmp    r14d,0x448 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1096ULL);
x86_l_3cb6:
	/* 0x3cb6: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3cbc:
	/* 0x3cbc: lea    rsi,[rcx+0x458] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1112ULL);
x86_l_3cc3:
	/* 0x3cc3: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3cc6:
	/* 0x3cc6: jbe    3cdd <tail_policy_denied_ipv6+0x3cdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3cdd;
	}
x86_l_3cc8:
	/* 0x3cc8: add    rcx,0x457 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1111ULL);
x86_l_3ccf:
	/* 0x3ccf: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3cd2:
	/* 0x3cd2: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3cd8:
	/* 0x3cd8: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3cdd:
	/* 0x3cdd: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ce0:
	/* 0x3ce0: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ce2:
	/* 0x3ce2: cmp    r14d,0x44a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1098ULL);
x86_l_3ce9:
	/* 0x3ce9: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3cef:
	/* 0x3cef: lea    rdi,[rcx+0x45a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1114ULL);
x86_l_3cf6:
	/* 0x3cf6: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3cf9:
	/* 0x3cf9: jbe    3d10 <tail_policy_denied_ipv6+0x3d10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3d10;
	}
x86_l_3cfb:
	/* 0x3cfb: add    rcx,0x459 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1113ULL);
x86_l_3d02:
	/* 0x3d02: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3d05:
	/* 0x3d05: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3d0b:
	/* 0x3d0b: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3d10:
	/* 0x3d10: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d13:
	/* 0x3d13: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d15:
	/* 0x3d15: cmp    r14d,0x44c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1100ULL);
x86_l_3d1c:
	/* 0x3d1c: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3d22:
	/* 0x3d22: lea    rsi,[rcx+0x45c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1116ULL);
x86_l_3d29:
	/* 0x3d29: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3d2c:
	/* 0x3d2c: jbe    3d43 <tail_policy_denied_ipv6+0x3d43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3d43;
	}
x86_l_3d2e:
	/* 0x3d2e: add    rcx,0x45b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1115ULL);
x86_l_3d35:
	/* 0x3d35: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3d38:
	/* 0x3d38: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3d3e:
	/* 0x3d3e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3d43:
	/* 0x3d43: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d46:
	/* 0x3d46: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d48:
	/* 0x3d48: cmp    r14d,0x44e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1102ULL);
x86_l_3d4f:
	/* 0x3d4f: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3d55:
	/* 0x3d55: lea    rdi,[rcx+0x45e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1118ULL);
x86_l_3d5c:
	/* 0x3d5c: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3d5f:
	/* 0x3d5f: jbe    3d76 <tail_policy_denied_ipv6+0x3d76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3d76;
	}
x86_l_3d61:
	/* 0x3d61: add    rcx,0x45d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1117ULL);
x86_l_3d68:
	/* 0x3d68: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3d6b:
	/* 0x3d6b: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3d71:
	/* 0x3d71: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3d76:
	/* 0x3d76: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d79:
	/* 0x3d79: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d7b:
	/* 0x3d7b: cmp    r14d,0x450 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1104ULL);
x86_l_3d82:
	/* 0x3d82: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3d84:
	/* 0x3d84: lea    rsi,[rcx+0x460] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1120ULL);
x86_l_3d8b:
	/* 0x3d8b: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3d8e:
	/* 0x3d8e: jbe    3da5 <tail_policy_denied_ipv6+0x3da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3da5;
	}
x86_l_3d90:
	/* 0x3d90: add    rcx,0x45f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1119ULL);
x86_l_3d97:
	/* 0x3d97: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3d9a:
	/* 0x3d9a: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3da0:
	/* 0x3da0: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3da5:
	/* 0x3da5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3da8:
	/* 0x3da8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3daa:
	/* 0x3daa: cmp    r14d,0x452 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1106ULL);
x86_l_3db1:
	/* 0x3db1: jb     3de2 <tail_policy_denied_ipv6+0x3de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3de2;
	}
x86_l_3db3:
	/* 0x3db3: lea    rdi,[rcx+0x462] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1122ULL);
x86_l_3dba:
	/* 0x3dba: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3dbd:
	/* 0x3dbd: jbe    3dd4 <tail_policy_denied_ipv6+0x3dd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3dd4;
	}
x86_l_3dbf:
	/* 0x3dbf: add    rcx,0x461 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1121ULL);
x86_l_3dc6:
	/* 0x3dc6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3dc9:
	/* 0x3dc9: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3dcf:
	/* 0x3dcf: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3dd4:
	/* 0x3dd4: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3dd7:
	/* 0x3dd7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3dd9:
	/* 0x3dd9: cmp    r14d,0x454 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1108ULL);
x86_l_3de0:
	/* 0x3de0: jae    3dea <tail_policy_denied_ipv6+0x3dea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3dea;
	}
x86_l_3de2:
	/* 0x3de2: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_3de5:
	/* 0x3de5: jmp    245 <tail_policy_denied_ipv6+0x245> */
	return 581ULL;
x86_l_3dea:
	/* 0x3dea: lea    rsi,[rcx+0x464] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1124ULL);
x86_l_3df1:
	/* 0x3df1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3df4:
	/* 0x3df4: jbe    3e0b <tail_policy_denied_ipv6+0x3e0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3e0b;
	}
x86_l_3df6:
	/* 0x3df6: add    rcx,0x463 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1123ULL);
x86_l_3dfd:
	/* 0x3dfd: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3e00:
	/* 0x3e00: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3e06:
	/* 0x3e06: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3e0b:
	/* 0x3e0b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e0e:
	/* 0x3e0e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e10:
	/* 0x3e10: cmp    r14d,0x456 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1110ULL);
x86_l_3e17:
	/* 0x3e17: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3e1d:
	/* 0x3e1d: lea    rdi,[rcx+0x466] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1126ULL);
x86_l_3e24:
	/* 0x3e24: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3e27:
	/* 0x3e27: jbe    3e3e <tail_policy_denied_ipv6+0x3e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3e3e;
	}
x86_l_3e29:
	/* 0x3e29: add    rcx,0x465 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1125ULL);
x86_l_3e30:
	/* 0x3e30: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3e33:
	/* 0x3e33: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3e39:
	/* 0x3e39: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3e3e:
	/* 0x3e3e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e41:
	/* 0x3e41: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e43:
	/* 0x3e43: cmp    r14d,0x458 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1112ULL);
x86_l_3e4a:
	/* 0x3e4a: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3e50:
	/* 0x3e50: lea    rsi,[rcx+0x468] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1128ULL);
x86_l_3e57:
	/* 0x3e57: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3e5a:
	/* 0x3e5a: jbe    3e71 <tail_policy_denied_ipv6+0x3e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3e71;
	}
x86_l_3e5c:
	/* 0x3e5c: add    rcx,0x467 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1127ULL);
x86_l_3e63:
	/* 0x3e63: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3e66:
	/* 0x3e66: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3e6c:
	/* 0x3e6c: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3e71:
	/* 0x3e71: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e74:
	/* 0x3e74: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e76:
	/* 0x3e76: cmp    r14d,0x45a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1114ULL);
x86_l_3e7d:
	/* 0x3e7d: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3e83:
	/* 0x3e83: lea    rdi,[rcx+0x46a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1130ULL);
x86_l_3e8a:
	/* 0x3e8a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3e8d:
	/* 0x3e8d: jbe    3ea4 <tail_policy_denied_ipv6+0x3ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3ea4;
	}
x86_l_3e8f:
	/* 0x3e8f: add    rcx,0x469 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1129ULL);
x86_l_3e96:
	/* 0x3e96: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3e99:
	/* 0x3e99: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3e9f:
	/* 0x3e9f: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3ea4:
	/* 0x3ea4: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ea7:
	/* 0x3ea7: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ea9:
	/* 0x3ea9: cmp    r14d,0x45c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1116ULL);
x86_l_3eb0:
	/* 0x3eb0: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3eb6:
	/* 0x3eb6: lea    rsi,[rcx+0x46c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1132ULL);
x86_l_3ebd:
	/* 0x3ebd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3ec0:
	/* 0x3ec0: jbe    3ed7 <tail_policy_denied_ipv6+0x3ed7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3ed7;
	}
x86_l_3ec2:
	/* 0x3ec2: add    rcx,0x46b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1131ULL);
x86_l_3ec9:
	/* 0x3ec9: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3ecc:
	/* 0x3ecc: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3ed2:
	/* 0x3ed2: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3ed7:
	/* 0x3ed7: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3eda:
	/* 0x3eda: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3edc:
	/* 0x3edc: cmp    r14d,0x45e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1118ULL);
x86_l_3ee3:
	/* 0x3ee3: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3ee9:
	/* 0x3ee9: lea    rdi,[rcx+0x46e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1134ULL);
x86_l_3ef0:
	/* 0x3ef0: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3ef3:
	/* 0x3ef3: jbe    3f0a <tail_policy_denied_ipv6+0x3f0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3f0a;
	}
x86_l_3ef5:
	/* 0x3ef5: add    rcx,0x46d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1133ULL);
x86_l_3efc:
	/* 0x3efc: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3eff:
	/* 0x3eff: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3f05:
	/* 0x3f05: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3f0a:
	/* 0x3f0a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f0d:
	/* 0x3f0d: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f0f:
	/* 0x3f0f: cmp    r14d,0x460 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1120ULL);
x86_l_3f16:
	/* 0x3f16: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3f1c:
	/* 0x3f1c: lea    rsi,[rcx+0x470] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_3f23:
	/* 0x3f23: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3f26:
	/* 0x3f26: jbe    3f3d <tail_policy_denied_ipv6+0x3f3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3f3d;
	}
x86_l_3f28:
	/* 0x3f28: add    rcx,0x46f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1135ULL);
x86_l_3f2f:
	/* 0x3f2f: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3f32:
	/* 0x3f32: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3f38:
	/* 0x3f38: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3f3d:
	/* 0x3f3d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f40:
	/* 0x3f40: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f42:
	/* 0x3f42: cmp    r14d,0x462 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1122ULL);
x86_l_3f49:
	/* 0x3f49: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3f4f:
	/* 0x3f4f: lea    rdi,[rcx+0x472] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1138ULL);
x86_l_3f56:
	/* 0x3f56: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3f59:
	/* 0x3f59: jbe    3f70 <tail_policy_denied_ipv6+0x3f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3f70;
	}
x86_l_3f5b:
	/* 0x3f5b: add    rcx,0x471 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1137ULL);
x86_l_3f62:
	/* 0x3f62: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3f65:
	/* 0x3f65: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3f6b:
	/* 0x3f6b: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3f70:
	/* 0x3f70: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f73:
	/* 0x3f73: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f75:
	/* 0x3f75: cmp    r14d,0x464 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1124ULL);
x86_l_3f7c:
	/* 0x3f7c: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3f82:
	/* 0x3f82: lea    rsi,[rcx+0x474] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1140ULL);
x86_l_3f89:
	/* 0x3f89: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3f8c:
	/* 0x3f8c: jbe    3fa3 <tail_policy_denied_ipv6+0x3fa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3fa3;
	}
x86_l_3f8e:
	/* 0x3f8e: add    rcx,0x473 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1139ULL);
x86_l_3f95:
	/* 0x3f95: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3f98:
	/* 0x3f98: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_3f9e:
	/* 0x3f9e: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3fa3:
	/* 0x3fa3: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fa6:
	/* 0x3fa6: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3fa8:
	/* 0x3fa8: cmp    r14d,0x466 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1126ULL);
x86_l_3faf:
	/* 0x3faf: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3fb5:
	/* 0x3fb5: lea    rdi,[rcx+0x476] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1142ULL);
x86_l_3fbc:
	/* 0x3fbc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3fbf:
	/* 0x3fbf: jbe    3fd6 <tail_policy_denied_ipv6+0x3fd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3fd6;
	}
x86_l_3fc1:
	/* 0x3fc1: add    rcx,0x475 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1141ULL);
x86_l_3fc8:
	/* 0x3fc8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3fcb:
	/* 0x3fcb: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_3fd1:
	/* 0x3fd1: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_3fd6:
	/* 0x3fd6: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fd9:
	/* 0x3fd9: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3fdb:
	/* 0x3fdb: cmp    r14d,0x468 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1128ULL);
x86_l_3fe2:
	/* 0x3fe2: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_3fe8:
	/* 0x3fe8: lea    rsi,[rcx+0x478] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1144ULL);
x86_l_3fef:
	/* 0x3fef: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3ff2:
	/* 0x3ff2: jbe    4009 <tail_policy_denied_ipv6+0x4009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4009;
	}
x86_l_3ff4:
	/* 0x3ff4: add    rcx,0x477 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1143ULL);
x86_l_3ffb:
	/* 0x3ffb: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3ffe:
	/* 0x3ffe: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_4004:
	/* 0x4004: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_4009:
	/* 0x4009: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_400c:
	/* 0x400c: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_400e:
	/* 0x400e: cmp    r14d,0x46a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1130ULL);
x86_l_4015:
	/* 0x4015: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_401b:
	/* 0x401b: lea    rdi,[rcx+0x47a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1146ULL);
x86_l_4022:
	/* 0x4022: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4025:
	/* 0x4025: jbe    403c <tail_policy_denied_ipv6+0x403c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_403c;
	}
x86_l_4027:
	/* 0x4027: add    rcx,0x479 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1145ULL);
x86_l_402e:
	/* 0x402e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4031:
	/* 0x4031: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_4037:
	/* 0x4037: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_403c:
	/* 0x403c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_403f:
	/* 0x403f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4041:
	/* 0x4041: cmp    r14d,0x46c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1132ULL);
x86_l_4048:
	/* 0x4048: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_404e:
	/* 0x404e: lea    rsi,[rcx+0x47c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1148ULL);
x86_l_4055:
	/* 0x4055: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4058:
	/* 0x4058: jbe    406f <tail_policy_denied_ipv6+0x406f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_406f;
	}
x86_l_405a:
	/* 0x405a: add    rcx,0x47b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1147ULL);
x86_l_4061:
	/* 0x4061: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4064:
	/* 0x4064: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_406a:
	/* 0x406a: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_406f:
	/* 0x406f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4072:
	/* 0x4072: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4074:
	/* 0x4074: cmp    r14d,0x46e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1134ULL);
x86_l_407b:
	/* 0x407b: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_4081:
	/* 0x4081: lea    rdi,[rcx+0x47e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1150ULL);
x86_l_4088:
	/* 0x4088: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_408b:
	/* 0x408b: jbe    40a2 <tail_policy_denied_ipv6+0x40a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_40a2;
	}
x86_l_408d:
	/* 0x408d: add    rcx,0x47d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1149ULL);
x86_l_4094:
	/* 0x4094: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4097:
	/* 0x4097: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_409d:
	/* 0x409d: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_40a2:
	/* 0x40a2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40a5:
	/* 0x40a5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40a7:
	/* 0x40a7: cmp    r14d,0x470 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1136ULL);
x86_l_40ae:
	/* 0x40ae: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_40b4:
	/* 0x40b4: lea    rsi,[rcx+0x480] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1152ULL);
x86_l_40bb:
	/* 0x40bb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_40be:
	/* 0x40be: jbe    40d5 <tail_policy_denied_ipv6+0x40d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_40d5;
	}
x86_l_40c0:
	/* 0x40c0: add    rcx,0x47f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1151ULL);
x86_l_40c7:
	/* 0x40c7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_40ca:
	/* 0x40ca: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_40d0:
	/* 0x40d0: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_40d5:
	/* 0x40d5: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40d8:
	/* 0x40d8: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40da:
	/* 0x40da: cmp    r14d,0x472 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1138ULL);
x86_l_40e1:
	/* 0x40e1: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_40e7:
	/* 0x40e7: lea    rdi,[rcx+0x482] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1154ULL);
x86_l_40ee:
	/* 0x40ee: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_40f1:
	/* 0x40f1: jbe    4108 <tail_policy_denied_ipv6+0x4108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4108;
	}
x86_l_40f3:
	/* 0x40f3: add    rcx,0x481 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1153ULL);
x86_l_40fa:
	/* 0x40fa: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_40fd:
	/* 0x40fd: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_4103:
	/* 0x4103: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_4108:
	/* 0x4108: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_410b:
	/* 0x410b: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_410d:
	/* 0x410d: cmp    r14d,0x474 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1140ULL);
x86_l_4114:
	/* 0x4114: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_411a:
	/* 0x411a: lea    rsi,[rcx+0x484] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1156ULL);
x86_l_4121:
	/* 0x4121: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4124:
	/* 0x4124: jbe    413b <tail_policy_denied_ipv6+0x413b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_413b;
	}
x86_l_4126:
	/* 0x4126: add    rcx,0x483 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1155ULL);
x86_l_412d:
	/* 0x412d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4130:
	/* 0x4130: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_4136:
	/* 0x4136: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_413b:
	/* 0x413b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_413e:
	/* 0x413e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4140:
	/* 0x4140: cmp    r14d,0x476 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1142ULL);
x86_l_4147:
	/* 0x4147: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_414d:
	/* 0x414d: lea    rdi,[rcx+0x486] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1158ULL);
x86_l_4154:
	/* 0x4154: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4157:
	/* 0x4157: jbe    416e <tail_policy_denied_ipv6+0x416e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_416e;
	}
x86_l_4159:
	/* 0x4159: add    rcx,0x485 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1157ULL);
x86_l_4160:
	/* 0x4160: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4163:
	/* 0x4163: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_4169:
	/* 0x4169: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_416e:
	/* 0x416e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4171:
	/* 0x4171: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4173:
	/* 0x4173: cmp    r14d,0x478 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1144ULL);
x86_l_417a:
	/* 0x417a: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_4180:
	/* 0x4180: lea    rsi,[rcx+0x488] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1160ULL);
x86_l_4187:
	/* 0x4187: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_418a:
	/* 0x418a: jbe    41a1 <tail_policy_denied_ipv6+0x41a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_41a1;
	}
x86_l_418c:
	/* 0x418c: add    rcx,0x487 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1159ULL);
x86_l_4193:
	/* 0x4193: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_4196:
	/* 0x4196: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_419c:
	/* 0x419c: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_41a1:
	/* 0x41a1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41a4:
	/* 0x41a4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_41a6:
	/* 0x41a6: cmp    r14d,0x47a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1146ULL);
x86_l_41ad:
	/* 0x41ad: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_41af:
	/* 0x41af: lea    rdi,[rcx+0x48a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1162ULL);
x86_l_41b6:
	/* 0x41b6: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_41b9:
	/* 0x41b9: jbe    41cd <tail_policy_denied_ipv6+0x41cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_41cd;
	}
x86_l_41bb:
	/* 0x41bb: add    rcx,0x489 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1161ULL);
x86_l_41c2:
	/* 0x41c2: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_41c5:
	/* 0x41c5: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_41cb:
	/* 0x41cb: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_41cd:
	/* 0x41cd: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41d0:
	/* 0x41d0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_41d2:
	/* 0x41d2: cmp    r14d,0x47c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1148ULL);
x86_l_41d9:
	/* 0x41d9: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_41db:
	/* 0x41db: lea    rsi,[rcx+0x48c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1164ULL);
x86_l_41e2:
	/* 0x41e2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_41e5:
	/* 0x41e5: jbe    41f9 <tail_policy_denied_ipv6+0x41f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_41f9;
	}
x86_l_41e7:
	/* 0x41e7: add    rcx,0x48b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1163ULL);
x86_l_41ee:
	/* 0x41ee: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_41f1:
	/* 0x41f1: jbe    510 <tail_policy_denied_ipv6+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1296ULL;
	}
x86_l_41f7:
	/* 0x41f7: jmp    4223 <tail_policy_denied_ipv6+0x4223> */
	goto x86_l_4223;
x86_l_41f9:
	/* 0x41f9: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41fc:
	/* 0x41fc: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_41fe:
	/* 0x41fe: cmp    r14d,0x47e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1150ULL);
x86_l_4205:
	/* 0x4205: jb     4223 <tail_policy_denied_ipv6+0x4223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4223;
	}
x86_l_4207:
	/* 0x4207: lea    rdi,[rcx+0x48e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1166ULL);
x86_l_420e:
	/* 0x420e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4211:
	/* 0x4211: jbe    422b <tail_policy_denied_ipv6+0x422b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_422b;
	}
x86_l_4213:
	/* 0x4213: add    rcx,0x48d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1165ULL);
x86_l_421a:
	/* 0x421a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_421d:
	/* 0x421d: jbe    536 <tail_policy_denied_ipv6+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1334ULL;
	}
x86_l_4223:
	/* 0x4223: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_4226:
	/* 0x4226: jmp    245 <tail_policy_denied_ipv6+0x245> */
	return 581ULL;
x86_l_422b:
	/* 0x422b: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_422e:
	/* 0x422e: jmp    539 <tail_policy_denied_ipv6+0x539> */
	return 1337ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_lxc_tail_policy_denied_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 15280U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1483ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1486ULL && __x86_pc <= 2949ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2953ULL && __x86_pc <= 4591ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4598ULL && __x86_pc <= 6374ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6376ULL && __x86_pc <= 8162ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8167ULL && __x86_pc <= 9941ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9947ULL && __x86_pc <= 11722ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11724ULL && __x86_pc <= 13504ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13507ULL && __x86_pc <= 15287ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15293ULL && __x86_pc <= 16942ULL)
			__x86_pc = cilium_bpf_lxc_tail_policy_denied_ipv6_x86_chunk_9(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 20ULL: goto x86_l_14;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 33ULL: goto x86_l_21;
	case 37ULL: goto x86_l_25;
	case 46ULL: goto x86_l_2e;
	case 55ULL: goto x86_l_37;
	case 64ULL: goto x86_l_40;
	case 73ULL: goto x86_l_49;
	case 82ULL: goto x86_l_52;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 93ULL: goto x86_l_5d;
	case 98ULL: goto x86_l_62;
	case 101ULL: goto x86_l_65;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 115ULL: goto x86_l_73;
	case 123ULL: goto x86_l_7b;
	case 128ULL: goto x86_l_80;
	case 132ULL: goto x86_l_84;
	case 138ULL: goto x86_l_8a;
	case 143ULL: goto x86_l_8f;
	case 153ULL: goto x86_l_99;
	case 157ULL: goto x86_l_9d;
	case 163ULL: goto x86_l_a3;
	case 171ULL: goto x86_l_ab;
	case 176ULL: goto x86_l_b0;
	case 179ULL: goto x86_l_b3;
	case 184ULL: goto x86_l_b8;
	case 189ULL: goto x86_l_bd;
	case 191ULL: goto x86_l_bf;
	case 193ULL: goto x86_l_c1;
	case 199ULL: goto x86_l_c7;
	case 204ULL: goto x86_l_cc;
	case 213ULL: goto x86_l_d5;
	case 216ULL: goto x86_l_d8;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 226ULL: goto x86_l_e2;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 237ULL: goto x86_l_ed;
	case 245ULL: goto x86_l_f5;
	case 252ULL: goto x86_l_fc;
	case 254ULL: goto x86_l_fe;
	case 262ULL: goto x86_l_106;
	case 269ULL: goto x86_l_10d;
	case 273ULL: goto x86_l_111;
	case 275ULL: goto x86_l_113;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 290ULL: goto x86_l_122;
	case 293ULL: goto x86_l_125;
	case 297ULL: goto x86_l_129;
	case 303ULL: goto x86_l_12f;
	case 306ULL: goto x86_l_132;
	case 316ULL: goto x86_l_13c;
	case 320ULL: goto x86_l_140;
	case 326ULL: goto x86_l_146;
	case 334ULL: goto x86_l_14e;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 347ULL: goto x86_l_15b;
	case 352ULL: goto x86_l_160;
	case 354ULL: goto x86_l_162;
	case 356ULL: goto x86_l_164;
	case 362ULL: goto x86_l_16a;
	case 370ULL: goto x86_l_172;
	case 374ULL: goto x86_l_176;
	case 380ULL: goto x86_l_17c;
	case 384ULL: goto x86_l_180;
	case 389ULL: goto x86_l_185;
	case 395ULL: goto x86_l_18b;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 413ULL: goto x86_l_19d;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 459ULL: goto x86_l_1cb;
	case 467ULL: goto x86_l_1d3;
	case 472ULL: goto x86_l_1d8;
	case 475ULL: goto x86_l_1db;
	case 480ULL: goto x86_l_1e0;
	case 485ULL: goto x86_l_1e5;
	case 487ULL: goto x86_l_1e7;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 502ULL: goto x86_l_1f6;
	case 510ULL: goto x86_l_1fe;
	case 514ULL: goto x86_l_202;
	case 517ULL: goto x86_l_205;
	case 525ULL: goto x86_l_20d;
	case 535ULL: goto x86_l_217;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 547ULL: goto x86_l_223;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 565ULL: goto x86_l_235;
	case 569ULL: goto x86_l_239;
	case 572ULL: goto x86_l_23c;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 583ULL: goto x86_l_247;
	case 589ULL: goto x86_l_24d;
	case 592ULL: goto x86_l_250;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 618ULL: goto x86_l_26a;
	case 626ULL: goto x86_l_272;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 643ULL: goto x86_l_283;
	case 655ULL: goto x86_l_28f;
	case 663ULL: goto x86_l_297;
	case 668ULL: goto x86_l_29c;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 678ULL: goto x86_l_2a6;
	case 680ULL: goto x86_l_2a8;
	case 686ULL: goto x86_l_2ae;
	case 693ULL: goto x86_l_2b5;
	case 701ULL: goto x86_l_2bd;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 716ULL: goto x86_l_2cc;
	case 726ULL: goto x86_l_2d6;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 738ULL: goto x86_l_2e2;
	case 748ULL: goto x86_l_2ec;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 760ULL: goto x86_l_2f8;
	case 765ULL: goto x86_l_2fd;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 776ULL: goto x86_l_308;
	case 782ULL: goto x86_l_30e;
	case 785ULL: goto x86_l_311;
	case 795ULL: goto x86_l_31b;
	case 799ULL: goto x86_l_31f;
	case 801ULL: goto x86_l_321;
	case 809ULL: goto x86_l_329;
	case 814ULL: goto x86_l_32e;
	case 817ULL: goto x86_l_331;
	case 820ULL: goto x86_l_334;
	case 825ULL: goto x86_l_339;
	case 827ULL: goto x86_l_33b;
	case 829ULL: goto x86_l_33d;
	case 835ULL: goto x86_l_343;
	case 843ULL: goto x86_l_34b;
	case 847ULL: goto x86_l_34f;
	case 849ULL: goto x86_l_351;
	case 853ULL: goto x86_l_355;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 863ULL: goto x86_l_35f;
	case 867ULL: goto x86_l_363;
	case 869ULL: goto x86_l_365;
	case 877ULL: goto x86_l_36d;
	case 885ULL: goto x86_l_375;
	case 890ULL: goto x86_l_37a;
	case 894ULL: goto x86_l_37e;
	case 899ULL: goto x86_l_383;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 915ULL: goto x86_l_393;
	case 920ULL: goto x86_l_398;
	case 925ULL: goto x86_l_39d;
	case 928ULL: goto x86_l_3a0;
	case 936ULL: goto x86_l_3a8;
	case 944ULL: goto x86_l_3b0;
	case 948ULL: goto x86_l_3b4;
	case 950ULL: goto x86_l_3b6;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 975ULL: goto x86_l_3cf;
	case 983ULL: goto x86_l_3d7;
	case 988ULL: goto x86_l_3dc;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 998ULL: goto x86_l_3e6;
	case 1000ULL: goto x86_l_3e8;
	case 1006ULL: goto x86_l_3ee;
	case 1013ULL: goto x86_l_3f5;
	case 1021ULL: goto x86_l_3fd;
	case 1025ULL: goto x86_l_401;
	case 1028ULL: goto x86_l_404;
	case 1036ULL: goto x86_l_40c;
	case 1046ULL: goto x86_l_416;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1058ULL: goto x86_l_422;
	case 1068ULL: goto x86_l_42c;
	case 1071ULL: goto x86_l_42f;
	case 1076ULL: goto x86_l_434;
	case 1080ULL: goto x86_l_438;
	case 1085ULL: goto x86_l_43d;
	case 1088ULL: goto x86_l_440;
	case 1090ULL: goto x86_l_442;
	case 1094ULL: goto x86_l_446;
	case 1097ULL: goto x86_l_449;
	case 1100ULL: goto x86_l_44c;
	case 1106ULL: goto x86_l_452;
	case 1108ULL: goto x86_l_454;
	case 1118ULL: goto x86_l_45e;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1132ULL: goto x86_l_46c;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1167ULL: goto x86_l_48f;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1176ULL: goto x86_l_498;
	case 1182ULL: goto x86_l_49e;
	case 1185ULL: goto x86_l_4a1;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1216ULL: goto x86_l_4c0;
	case 1222ULL: goto x86_l_4c6;
	case 1234ULL: goto x86_l_4d2;
	case 1242ULL: goto x86_l_4da;
	case 1247ULL: goto x86_l_4df;
	case 1250ULL: goto x86_l_4e2;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1262ULL: goto x86_l_4ee;
	case 1268ULL: goto x86_l_4f4;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1280ULL: goto x86_l_500;
	case 1284ULL: goto x86_l_504;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1294ULL: goto x86_l_50e;
	case 1299ULL: goto x86_l_513;
	case 1304ULL: goto x86_l_518;
	case 1312ULL: goto x86_l_520;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1325ULL: goto x86_l_52d;
	case 1330ULL: goto x86_l_532;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1356ULL: goto x86_l_54c;
	case 1361ULL: goto x86_l_551;
	case 1365ULL: goto x86_l_555;
	case 1367ULL: goto x86_l_557;
	case 1371ULL: goto x86_l_55b;
	case 1374ULL: goto x86_l_55e;
	case 1380ULL: goto x86_l_564;
	case 1383ULL: goto x86_l_567;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1404ULL: goto x86_l_57c;
	case 1412ULL: goto x86_l_584;
	case 1419ULL: goto x86_l_58b;
	case 1422ULL: goto x86_l_58e;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1436ULL: goto x86_l_59c;
	case 1443ULL: goto x86_l_5a3;
	case 1446ULL: goto x86_l_5a6;
	case 1449ULL: goto x86_l_5a9;
	case 1453ULL: goto x86_l_5ad;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1466ULL: goto x86_l_5ba;
	case 1471ULL: goto x86_l_5bf;
	case 1474ULL: goto x86_l_5c2;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1509ULL: goto x86_l_5e5;
	case 1514ULL: goto x86_l_5ea;
	case 1519ULL: goto x86_l_5ef;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1563ULL: goto x86_l_61b;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1572ULL: goto x86_l_624;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1589ULL: goto x86_l_635;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1603ULL: goto x86_l_643;
	case 1609ULL: goto x86_l_649;
	case 1614ULL: goto x86_l_64e;
	case 1623ULL: goto x86_l_657;
	case 1632ULL: goto x86_l_660;
	case 1641ULL: goto x86_l_669;
	case 1650ULL: goto x86_l_672;
	case 1659ULL: goto x86_l_67b;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1680ULL: goto x86_l_690;
	case 1683ULL: goto x86_l_693;
	case 1688ULL: goto x86_l_698;
	case 1690ULL: goto x86_l_69a;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1699ULL: goto x86_l_6a3;
	case 1705ULL: goto x86_l_6a9;
	case 1713ULL: goto x86_l_6b1;
	case 1721ULL: goto x86_l_6b9;
	case 1725ULL: goto x86_l_6bd;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1759ULL: goto x86_l_6df;
	case 1764ULL: goto x86_l_6e4;
	case 1772ULL: goto x86_l_6ec;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1793ULL: goto x86_l_701;
	case 1797ULL: goto x86_l_705;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1853ULL: goto x86_l_73d;
	case 1855ULL: goto x86_l_73f;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1875ULL: goto x86_l_753;
	case 1879ULL: goto x86_l_757;
	case 1881ULL: goto x86_l_759;
	case 1885ULL: goto x86_l_75d;
	case 1891ULL: goto x86_l_763;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_14:
	/* 0x14: movzx  r12d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18:
	/* 0x18: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f:
	/* 0x1f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21:
	/* 0x21: mov    r14d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25:
	/* 0x25: mov    QWORD PTR [rsp+0x7e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_2e:
	/* 0x2e: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_37:
	/* 0x37: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_40:
	/* 0x40: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_49:
	/* 0x49: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_52:
	/* 0x52: mov    r15d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_56:
	/* 0x56: mov    ecx,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_59:
	/* 0x59: lea    rdx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d:
	/* 0x5d: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_62:
	/* 0x62: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_65:
	/* 0x65: ja     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4318ULL;
	}
x86_l_6b:
	/* 0x6b: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_70:
	/* 0x70: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73:
	/* 0x73: mov    BYTE PTR [rsp+0x84],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_7b:
	/* 0x7b: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_80:
	/* 0x80: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_84:
	/* 0x84: ja     518 <tail_nodeport_nat_ingress_ipv6+0x518> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_518;
	}
x86_l_8a:
	/* 0x8a: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_8f:
	/* 0x8f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_99:
	/* 0x99: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: jae    1aa <tail_nodeport_nat_ingress_ipv6+0x1aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1aa;
	}
x86_l_a3:
	/* 0xa3: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ab:
	/* 0xab: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b0:
	/* 0xb0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_b8:
	/* 0xb8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bd:
	/* 0xbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf:
	/* 0xbf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c1:
	/* 0xc1: js     10d9 <tail_nodeport_nat_ingress_ipv6+0x10d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4313ULL;
	}
x86_l_c7:
	/* 0xc7: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cc:
	/* 0xcc: movzx  r14d,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_d5:
	/* 0xd5: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_d8:
	/* 0xd8: mov    DWORD PTR [rsp+0x40],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dd:
	/* 0xdd: jle    fe <tail_nodeport_nat_ingress_ipv6+0xfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_fe;
	}
x86_l_df:
	/* 0xdf: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_e2:
	/* 0xe2: je     fe <tail_nodeport_nat_ingress_ipv6+0xfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe;
	}
x86_l_e4:
	/* 0xe4: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_e7:
	/* 0xe7: jne    1b9 <tail_nodeport_nat_ingress_ipv6+0x1b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b9;
	}
x86_l_ed:
	/* 0xed: movzx  eax,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_f5:
	/* 0xf5: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_fc:
	/* 0xfc: jmp    11b <tail_nodeport_nat_ingress_ipv6+0x11b> */
	goto x86_l_11b;
x86_l_fe:
	/* 0xfe: movzx  eax,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_106:
	/* 0x106: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_10d:
	/* 0x10d: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_111:
	/* 0x111: jne    11b <tail_nodeport_nat_ingress_ipv6+0x11b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11b;
	}
x86_l_113:
	/* 0x113: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_116:
	/* 0x116: jmp    1bf <tail_nodeport_nat_ingress_ipv6+0x1bf> */
	goto x86_l_1bf;
x86_l_11b:
	/* 0x11b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e:
	/* 0x11e: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_122:
	/* 0x122: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_125:
	/* 0x125: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_129:
	/* 0x129: ja     24d <tail_nodeport_nat_ingress_ipv6+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24d;
	}
x86_l_12f:
	/* 0x12f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_132:
	/* 0x132: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_13c:
	/* 0x13c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_140:
	/* 0x140: jae    255 <tail_nodeport_nat_ingress_ipv6+0x255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_255;
	}
x86_l_146:
	/* 0x146: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14e:
	/* 0x14e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_153:
	/* 0x153: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_156:
	/* 0x156: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15b:
	/* 0x15b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_160:
	/* 0x160: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162:
	/* 0x162: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_164:
	/* 0x164: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_16a:
	/* 0x16a: movzx  ebp,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_172:
	/* 0x172: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_176:
	/* 0x176: jle    25d <tail_nodeport_nat_ingress_ipv6+0x25d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_25d;
	}
x86_l_17c:
	/* 0x17c: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_180:
	/* 0x180: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_185:
	/* 0x185: je     27d <tail_nodeport_nat_ingress_ipv6+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d;
	}
x86_l_18b:
	/* 0x18b: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_18f:
	/* 0x18f: jne    262 <tail_nodeport_nat_ingress_ipv6+0x262> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_262;
	}
x86_l_195:
	/* 0x195: movzx  eax,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_19d:
	/* 0x19d: lea    r12d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1a5:
	/* 0x1a5: jmp    2fd <tail_nodeport_nat_ingress_ipv6+0x2fd> */
	goto x86_l_2fd;
x86_l_1aa:
	/* 0x1aa: cmp    rbp,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 59ULL);
x86_l_1ae:
	/* 0x1ae: je     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4318ULL;
	}
x86_l_1b4:
	/* 0x1b4: jmp    518 <tail_nodeport_nat_ingress_ipv6+0x518> */
	goto x86_l_518;
x86_l_1b9:
	/* 0x1b9: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1cb:
	/* 0x1cb: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d3:
	/* 0x1d3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1d8:
	/* 0x1d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1db:
	/* 0x1db: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_1e0:
	/* 0x1e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e5:
	/* 0x1e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7:
	/* 0x1e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e9:
	/* 0x1e9: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_1ef:
	/* 0x1ef: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1f6:
	/* 0x1f6: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_1fe:
	/* 0x1fe: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_202:
	/* 0x202: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_205:
	/* 0x205: movzx  eax,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_20d:
	/* 0x20d: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_217:
	/* 0x217: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_21a:
	/* 0x21a: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_21f:
	/* 0x21f: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_223:
	/* 0x223: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_22d:
	/* 0x22d: or     r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_230:
	/* 0x230: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_235:
	/* 0x235: cmove  r13,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_239:
	/* 0x239: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_23c:
	/* 0x23c: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_240:
	/* 0x240: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_243:
	/* 0x243: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_247:
	/* 0x247: jbe    12f <tail_nodeport_nat_ingress_ipv6+0x12f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_12f;
	}
x86_l_24d:
	/* 0x24d: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_250:
	/* 0x250: jmp    50e <tail_nodeport_nat_ingress_ipv6+0x50e> */
	goto x86_l_50e;
x86_l_255:
	/* 0x255: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_258:
	/* 0x258: jmp    37a <tail_nodeport_nat_ingress_ipv6+0x37a> */
	goto x86_l_37a;
x86_l_25d:
	/* 0x25d: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_262:
	/* 0x262: movzx  eax,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_26a:
	/* 0x26a: lea    r12d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_272:
	/* 0x272: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_276:
	/* 0x276: je     283 <tail_nodeport_nat_ingress_ipv6+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283;
	}
x86_l_278:
	/* 0x278: jmp    2fd <tail_nodeport_nat_ingress_ipv6+0x2fd> */
	goto x86_l_2fd;
x86_l_27d:
	/* 0x27d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_283:
	/* 0x283: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_28f:
	/* 0x28f: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_297:
	/* 0x297: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_29c:
	/* 0x29c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29f:
	/* 0x29f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a4:
	/* 0x2a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6:
	/* 0x2a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a8:
	/* 0x2a8: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_2ae:
	/* 0x2ae: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2b5:
	/* 0x2b5: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_2bd:
	/* 0x2bd: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2c1:
	/* 0x2c1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2c4:
	/* 0x2c4: movzx  eax,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_2cc:
	/* 0x2cc: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_2d6:
	/* 0x2d6: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2d9:
	/* 0x2d9: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_2de:
	/* 0x2de: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_2e2:
	/* 0x2e2: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_2ec:
	/* 0x2ec: or     r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ef:
	/* 0x2ef: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_2f4:
	/* 0x2f4: cmove  r13,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_2f8:
	/* 0x2f8: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fd:
	/* 0x2fd: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_301:
	/* 0x301: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_304:
	/* 0x304: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_308:
	/* 0x308: ja     50e <tail_nodeport_nat_ingress_ipv6+0x50e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_50e;
	}
x86_l_30e:
	/* 0x30e: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_311:
	/* 0x311: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_31b:
	/* 0x31b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_31f:
	/* 0x31f: jae    37a <tail_nodeport_nat_ingress_ipv6+0x37a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_37a;
	}
x86_l_321:
	/* 0x321: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_329:
	/* 0x329: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_32e:
	/* 0x32e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_331:
	/* 0x331: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_334:
	/* 0x334: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_339:
	/* 0x339: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b:
	/* 0x33b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33d:
	/* 0x33d: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_343:
	/* 0x343: movzx  edi,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_34b:
	/* 0x34b: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_34f:
	/* 0x34f: jle    398 <tail_nodeport_nat_ingress_ipv6+0x398> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_398;
	}
x86_l_351:
	/* 0x351: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_355:
	/* 0x355: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_35a:
	/* 0x35a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: je     3bb <tail_nodeport_nat_ingress_ipv6+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_35f:
	/* 0x35f: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_363:
	/* 0x363: jne    3a0 <tail_nodeport_nat_ingress_ipv6+0x3a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a0;
	}
x86_l_365:
	/* 0x365: movzx  ecx,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_36d:
	/* 0x36d: lea    r14d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_375:
	/* 0x375: jmp    442 <tail_nodeport_nat_ingress_ipv6+0x442> */
	goto x86_l_442;
x86_l_37a:
	/* 0x37a: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_37e:
	/* 0x37e: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_383:
	/* 0x383: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_388:
	/* 0x388: mov    r12d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_38d:
	/* 0x38d: je     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4318ULL;
	}
x86_l_393:
	/* 0x393: jmp    518 <tail_nodeport_nat_ingress_ipv6+0x518> */
	goto x86_l_518;
x86_l_398:
	/* 0x398: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_39d:
	/* 0x39d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: movzx  ecx,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_3a8:
	/* 0x3a8: lea    r14d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_3b0:
	/* 0x3b0: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_3b4:
	/* 0x3b4: je     3c1 <tail_nodeport_nat_ingress_ipv6+0x3c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c1;
	}
x86_l_3b6:
	/* 0x3b6: jmp    442 <tail_nodeport_nat_ingress_ipv6+0x442> */
	goto x86_l_442;
x86_l_3bb:
	/* 0x3bb: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_3c1:
	/* 0x3c1: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_3c3:
	/* 0x3c3: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3cf:
	/* 0x3cf: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3d7:
	/* 0x3d7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3dc:
	/* 0x3dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e4:
	/* 0x3e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e6:
	/* 0x3e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e8:
	/* 0x3e8: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_3ee:
	/* 0x3ee: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3f5:
	/* 0x3f5: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_3fd:
	/* 0x3fd: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_401:
	/* 0x401: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_404:
	/* 0x404: movzx  eax,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_40c:
	/* 0x40c: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_416:
	/* 0x416: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_419:
	/* 0x419: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_41e:
	/* 0x41e: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_422:
	/* 0x422: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_42c:
	/* 0x42c: or     r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_42f:
	/* 0x42f: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_434:
	/* 0x434: cmove  r13,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_438:
	/* 0x438: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_43d:
	/* 0x43d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_440:
	/* 0x440: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_442:
	/* 0x442: movzx  ebp,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_446:
	/* 0x446: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_449:
	/* 0x449: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_44c:
	/* 0x44c: ja     50c <tail_nodeport_nat_ingress_ipv6+0x50c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_50c;
	}
x86_l_452:
	/* 0x452: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_454:
	/* 0x454: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_45e:
	/* 0x45e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_462:
	/* 0x462: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_467:
	/* 0x467: mov    r12d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_46c:
	/* 0x46c: jae    4fe <tail_nodeport_nat_ingress_ipv6+0x4fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4fe;
	}
x86_l_472:
	/* 0x472: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_475:
	/* 0x475: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_47d:
	/* 0x47d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_482:
	/* 0x482: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_485:
	/* 0x485: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_488:
	/* 0x488: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_48d:
	/* 0x48d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f:
	/* 0x48f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_491:
	/* 0x491: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_496:
	/* 0x496: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_498:
	/* 0x498: js     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4318ULL;
	}
x86_l_49e:
	/* 0x49e: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_4a1:
	/* 0x4a1: jle    4b7 <tail_nodeport_nat_ingress_ipv6+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4b7;
	}
x86_l_4a3:
	/* 0x4a3: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_4a6:
	/* 0x4a6: je     4c6 <tail_nodeport_nat_ingress_ipv6+0x4c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c6;
	}
x86_l_4a8:
	/* 0x4a8: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_4ab:
	/* 0x4ab: jne    4b7 <tail_nodeport_nat_ingress_ipv6+0x4b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4b7;
	}
x86_l_4ad:
	/* 0x4ad: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_4b2:
	/* 0x4b2: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	return 4318ULL;
x86_l_4b7:
	/* 0x4b7: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_4bc:
	/* 0x4bc: cmp    r12b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 44ULL);
x86_l_4c0:
	/* 0x4c0: jne    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4318ULL;
	}
x86_l_4c6:
	/* 0x4c6: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_4d2:
	/* 0x4d2: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4da:
	/* 0x4da: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4df:
	/* 0x4df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4e2:
	/* 0x4e2: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_4e5:
	/* 0x4e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ea:
	/* 0x4ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec:
	/* 0x4ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ee:
	/* 0x4ee: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3890ULL;
	}
x86_l_4f4:
	/* 0x4f4: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_4f9:
	/* 0x4f9: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	return 3895ULL;
x86_l_4fe:
	/* 0x4fe: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_500:
	/* 0x500: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_504:
	/* 0x504: je     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4318ULL;
	}
x86_l_50a:
	/* 0x50a: jmp    518 <tail_nodeport_nat_ingress_ipv6+0x518> */
	goto x86_l_518;
x86_l_50c:
	/* 0x50c: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_50e:
	/* 0x50e: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_513:
	/* 0x513: mov    r12d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_518:
	/* 0x518: mov    BYTE PTR [rsp+0x84],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_520:
	/* 0x520: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_524:
	/* 0x524: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_529:
	/* 0x529: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52d:
	/* 0x52d: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_532:
	/* 0x532: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_536:
	/* 0x536: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53b:
	/* 0x53b: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_544:
	/* 0x544: mov    BYTE PTR [rsp+0x85],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650369ULL);
x86_l_54c:
	/* 0x54c: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_551:
	/* 0x551: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_555:
	/* 0x555: je     56d <tail_nodeport_nat_ingress_ipv6+0x56d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56d;
	}
x86_l_557:
	/* 0x557: movzx  ecx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_55b:
	/* 0x55b: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_55e:
	/* 0x55e: je     5f4 <tail_nodeport_nat_ingress_ipv6+0x5f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f4;
	}
x86_l_564:
	/* 0x564: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_567:
	/* 0x567: jne    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4318ULL;
	}
x86_l_56d:
	/* 0x56d: mov    DWORD PTR [rsp+0x40],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_572:
	/* 0x572: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_57c:
	/* 0x57c: lea    r12,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_584:
	/* 0x584: mov    rcx,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_58b:
	/* 0x58b: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58e:
	/* 0x58e: je     77e <tail_nodeport_nat_ingress_ipv6+0x77e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1918ULL;
	}
x86_l_594:
	/* 0x594: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_599:
	/* 0x599: mov    r14,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a3:
	/* 0x5a3: mov    DWORD PTR [r15],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a6:
	/* 0x5a6: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_5a9:
	/* 0x5a9: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5ad:
	/* 0x5ad: mov    BYTE PTR [r15+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5b1:
	/* 0x5b1: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5b4:
	/* 0x5b4: jne    1276 <tail_nodeport_nat_ingress_ipv6+0x1276> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4726ULL;
	}
x86_l_5ba:
	/* 0x5ba: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5bf:
	/* 0x5bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5c2:
	/* 0x5c2: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_5c5:
	/* 0x5c5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5c8:
	/* 0x5c8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5cd:
	/* 0x5cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf:
	/* 0x5cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d1:
	/* 0x5d1: js     93c <tail_nodeport_nat_ingress_ipv6+0x93c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2364ULL;
	}
x86_l_5d7:
	/* 0x5d7: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_5dc:
	/* 0x5dc: jb     13e4 <tail_nodeport_nat_ingress_ipv6+0x13e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5092ULL;
	}
x86_l_5e2:
	/* 0x5e2: mov    QWORD PTR [r15],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e5:
	/* 0x5e5: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_5ea:
	/* 0x5ea: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5ef:
	/* 0x5ef: jmp    7a9 <tail_nodeport_nat_ingress_ipv6+0x7a9> */
	return 1961ULL;
x86_l_5f4:
	/* 0x5f4: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_5f9:
	/* 0x5f9: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_5fe:
	/* 0x5fe: jb     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4318ULL;
	}
x86_l_604:
	/* 0x604: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_609:
	/* 0x609: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_60e:
	/* 0x60e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_611:
	/* 0x611: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_614:
	/* 0x614: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_619:
	/* 0x619: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61b:
	/* 0x61b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_61d:
	/* 0x61d: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_622:
	/* 0x622: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_624:
	/* 0x624: js     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4318ULL;
	}
x86_l_62a:
	/* 0x62a: movzx  ecx,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_62f:
	/* 0x62f: cmp    ecx,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 129ULL);
x86_l_635:
	/* 0x635: je     949 <tail_nodeport_nat_ingress_ipv6+0x949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2377ULL;
	}
x86_l_63b:
	/* 0x63b: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_640:
	/* 0x640: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_643:
	/* 0x643: jne    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4318ULL;
	}
x86_l_649:
	/* 0x649: lea    r15d,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64e:
	/* 0x64e: mov    QWORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_657:
	/* 0x657: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_660:
	/* 0x660: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_669:
	/* 0x669: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_672:
	/* 0x672: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_67b:
	/* 0x67b: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_683:
	/* 0x683: mov    ebp,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_688:
	/* 0x688: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_68d:
	/* 0x68d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_690:
	/* 0x690: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_693:
	/* 0x693: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_698:
	/* 0x698: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69a:
	/* 0x69a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_69c:
	/* 0x69c: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_6a1:
	/* 0x6a1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6a3:
	/* 0x6a3: js     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4318ULL;
	}
x86_l_6a9:
	/* 0x6a9: mov    QWORD PTR [rsp+0xe0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_6b1:
	/* 0x6b1: movzx  eax,BYTE PTR [rsp+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 158ULL);
x86_l_6b9:
	/* 0x6b9: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6bd:
	/* 0x6bd: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_6c5:
	/* 0x6c5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ca:
	/* 0x6ca: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6d2:
	/* 0x6d2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d7:
	/* 0x6d7: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6df:
	/* 0x6df: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e4:
	/* 0x6e4: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6ec:
	/* 0x6ec: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f1:
	/* 0x6f1: mov    BYTE PTR [rsp+0x35],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266689ULL);
x86_l_6f6:
	/* 0x6f6: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fb:
	/* 0x6fb: movzx  r13d,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_701:
	/* 0x701: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_705:
	/* 0x705: ja     fc1 <tail_nodeport_nat_ingress_ipv6+0xfc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4033ULL;
	}
x86_l_70b:
	/* 0x70b: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_710:
	/* 0x710: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_71a:
	/* 0x71a: bt     rax,r13 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: jae    d6c <tail_nodeport_nat_ingress_ipv6+0xd6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3436ULL;
	}
x86_l_724:
	/* 0x724: lea    esi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_729:
	/* 0x729: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72e:
	/* 0x72e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_733:
	/* 0x733: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_736:
	/* 0x736: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_73b:
	/* 0x73b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73d:
	/* 0x73d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_73f:
	/* 0x73f: js     10d9 <tail_nodeport_nat_ingress_ipv6+0x10d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4313ULL;
	}
x86_l_745:
	/* 0x745: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_74a:
	/* 0x74a: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_74f:
	/* 0x74f: movzx  r14d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_753:
	/* 0x753: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_757:
	/* 0x757: jle    76d <tail_nodeport_nat_ingress_ipv6+0x76d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1901ULL;
	}
x86_l_759:
	/* 0x759: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_75d:
	/* 0x75d: je     e2b <tail_nodeport_nat_ingress_ipv6+0xe2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3627ULL;
	}
x86_l_763:
	/* 0x763: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
	return 1895ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1895ULL: goto x86_l_767;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1946ULL: goto x86_l_79a;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1967ULL: goto x86_l_7af;
	case 1975ULL: goto x86_l_7b7;
	case 1983ULL: goto x86_l_7bf;
	case 1991ULL: goto x86_l_7c7;
	case 1999ULL: goto x86_l_7cf;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2011ULL: goto x86_l_7db;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2063ULL: goto x86_l_80f;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2083ULL: goto x86_l_823;
	case 2092ULL: goto x86_l_82c;
	case 2101ULL: goto x86_l_835;
	case 2110ULL: goto x86_l_83e;
	case 2119ULL: goto x86_l_847;
	case 2123ULL: goto x86_l_84b;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2164ULL: goto x86_l_874;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2185ULL: goto x86_l_889;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2223ULL: goto x86_l_8af;
	case 2235ULL: goto x86_l_8bb;
	case 2247ULL: goto x86_l_8c7;
	case 2259ULL: goto x86_l_8d3;
	case 2271ULL: goto x86_l_8df;
	case 2283ULL: goto x86_l_8eb;
	case 2288ULL: goto x86_l_8f0;
	case 2293ULL: goto x86_l_8f5;
	case 2301ULL: goto x86_l_8fd;
	case 2309ULL: goto x86_l_905;
	case 2317ULL: goto x86_l_90d;
	case 2325ULL: goto x86_l_915;
	case 2329ULL: goto x86_l_919;
	case 2337ULL: goto x86_l_921;
	case 2344ULL: goto x86_l_928;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2390ULL: goto x86_l_956;
	case 2400ULL: goto x86_l_960;
	case 2405ULL: goto x86_l_965;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2422ULL: goto x86_l_976;
	case 2426ULL: goto x86_l_97a;
	case 2436ULL: goto x86_l_984;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2448ULL: goto x86_l_990;
	case 2456ULL: goto x86_l_998;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2483ULL: goto x86_l_9b3;
	case 2485ULL: goto x86_l_9b5;
	case 2487ULL: goto x86_l_9b7;
	case 2493ULL: goto x86_l_9bd;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2509ULL: goto x86_l_9cd;
	case 2517ULL: goto x86_l_9d5;
	case 2525ULL: goto x86_l_9dd;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2559ULL: goto x86_l_9ff;
	case 2563ULL: goto x86_l_a03;
	case 2571ULL: goto x86_l_a0b;
	case 2575ULL: goto x86_l_a0f;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2596ULL: goto x86_l_a24;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2611ULL: goto x86_l_a33;
	case 2613ULL: goto x86_l_a35;
	case 2620ULL: goto x86_l_a3c;
	case 2622ULL: goto x86_l_a3e;
	case 2629ULL: goto x86_l_a45;
	case 2637ULL: goto x86_l_a4d;
	case 2645ULL: goto x86_l_a55;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2661ULL: goto x86_l_a65;
	case 2671ULL: goto x86_l_a6f;
	case 2674ULL: goto x86_l_a72;
	case 2680ULL: goto x86_l_a78;
	case 2683ULL: goto x86_l_a7b;
	case 2692ULL: goto x86_l_a84;
	case 2701ULL: goto x86_l_a8d;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2723ULL: goto x86_l_aa3;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2735ULL: goto x86_l_aaf;
	case 2738ULL: goto x86_l_ab2;
	case 2740ULL: goto x86_l_ab4;
	case 2743ULL: goto x86_l_ab7;
	case 2747ULL: goto x86_l_abb;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2759ULL: goto x86_l_ac7;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2813ULL: goto x86_l_afd;
	case 2815ULL: goto x86_l_aff;
	case 2825ULL: goto x86_l_b09;
	case 2828ULL: goto x86_l_b0c;
	case 2830ULL: goto x86_l_b0e;
	case 2833ULL: goto x86_l_b11;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2857ULL: goto x86_l_b29;
	case 2864ULL: goto x86_l_b30;
	case 2868ULL: goto x86_l_b34;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2877ULL: goto x86_l_b3d;
	case 2882ULL: goto x86_l_b42;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2894ULL: goto x86_l_b4e;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2928ULL: goto x86_l_b70;
	case 2931ULL: goto x86_l_b73;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2947ULL: goto x86_l_b83;
	case 2949ULL: goto x86_l_b85;
	case 2952ULL: goto x86_l_b88;
	case 2958ULL: goto x86_l_b8e;
	case 2961ULL: goto x86_l_b91;
	case 2964ULL: goto x86_l_b94;
	case 2966ULL: goto x86_l_b96;
	case 2968ULL: goto x86_l_b98;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2985ULL: goto x86_l_ba9;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 2997ULL: goto x86_l_bb5;
	case 3004ULL: goto x86_l_bbc;
	case 3008ULL: goto x86_l_bc0;
	case 3012ULL: goto x86_l_bc4;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3034ULL: goto x86_l_bda;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3042ULL: goto x86_l_be2;
	case 3044ULL: goto x86_l_be4;
	case 3050ULL: goto x86_l_bea;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3063ULL: goto x86_l_bf7;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3072ULL: goto x86_l_c00;
	case 3079ULL: goto x86_l_c07;
	case 3083ULL: goto x86_l_c0b;
	case 3087ULL: goto x86_l_c0f;
	case 3091ULL: goto x86_l_c13;
	case 3095ULL: goto x86_l_c17;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3107ULL: goto x86_l_c23;
	case 3109ULL: goto x86_l_c25;
	case 3113ULL: goto x86_l_c29;
	case 3115ULL: goto x86_l_c2b;
	case 3120ULL: goto x86_l_c30;
	case 3122ULL: goto x86_l_c32;
	case 3124ULL: goto x86_l_c34;
	case 3128ULL: goto x86_l_c38;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3150ULL: goto x86_l_c4e;
	case 3153ULL: goto x86_l_c51;
	case 3158ULL: goto x86_l_c56;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3173ULL: goto x86_l_c65;
	case 3180ULL: goto x86_l_c6c;
	case 3183ULL: goto x86_l_c6f;
	case 3185ULL: goto x86_l_c71;
	case 3192ULL: goto x86_l_c78;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3200ULL: goto x86_l_c80;
	case 3202ULL: goto x86_l_c82;
	case 3207ULL: goto x86_l_c87;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3246ULL: goto x86_l_cae;
	case 3248ULL: goto x86_l_cb0;
	case 3255ULL: goto x86_l_cb7;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3265ULL: goto x86_l_cc1;
	case 3271ULL: goto x86_l_cc7;
	case 3273ULL: goto x86_l_cc9;
	case 3279ULL: goto x86_l_ccf;
	case 3282ULL: goto x86_l_cd2;
	case 3284ULL: goto x86_l_cd4;
	case 3287ULL: goto x86_l_cd7;
	case 3293ULL: goto x86_l_cdd;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3307ULL: goto x86_l_ceb;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3326ULL: goto x86_l_cfe;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3343ULL: goto x86_l_d0f;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3361ULL: goto x86_l_d21;
	case 3364ULL: goto x86_l_d24;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3387ULL: goto x86_l_d3b;
	case 3394ULL: goto x86_l_d42;
	case 3396ULL: goto x86_l_d44;
	case 3398ULL: goto x86_l_d46;
	case 3404ULL: goto x86_l_d4c;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3417ULL: goto x86_l_d59;
	case 3424ULL: goto x86_l_d60;
	case 3426ULL: goto x86_l_d62;
	case 3428ULL: goto x86_l_d64;
	case 3431ULL: goto x86_l_d67;
	case 3434ULL: goto x86_l_d6a;
	case 3436ULL: goto x86_l_d6c;
	case 3440ULL: goto x86_l_d70;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3460ULL: goto x86_l_d84;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3473ULL: goto x86_l_d91;
	case 3475ULL: goto x86_l_d93;
	case 3479ULL: goto x86_l_d97;
	case 3481ULL: goto x86_l_d99;
	case 3486ULL: goto x86_l_d9e;
	case 3488ULL: goto x86_l_da0;
	case 3490ULL: goto x86_l_da2;
	case 3494ULL: goto x86_l_da6;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3516ULL: goto x86_l_dbc;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3537ULL: goto x86_l_dd1;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3548ULL: goto x86_l_ddc;
	case 3550ULL: goto x86_l_dde;
	case 3557ULL: goto x86_l_de5;
	case 3559ULL: goto x86_l_de7;
	case 3562ULL: goto x86_l_dea;
	case 3565ULL: goto x86_l_ded;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3577ULL: goto x86_l_df9;
	case 3579ULL: goto x86_l_dfb;
	case 3582ULL: goto x86_l_dfe;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3591ULL: goto x86_l_e07;
	case 3594ULL: goto x86_l_e0a;
	case 3600ULL: goto x86_l_e10;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3620ULL: goto x86_l_e24;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3646ULL: goto x86_l_e3e;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3672ULL: goto x86_l_e58;
	case 3676ULL: goto x86_l_e5c;
	case 3678ULL: goto x86_l_e5e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_767:
	/* 0x767: jne    e32 <tail_nodeport_nat_ingress_ipv6+0xe32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e32;
	}
x86_l_76d:
	/* 0x76d: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_772:
	/* 0x772: lea    ebp,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_779:
	/* 0x779: jmp    e3e <tail_nodeport_nat_ingress_ipv6+0xe3e> */
	goto x86_l_e3e;
x86_l_77e:
	/* 0x77e: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_781:
	/* 0x781: jne    1450 <tail_nodeport_nat_ingress_ipv6+0x1450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5200ULL;
	}
x86_l_787:
	/* 0x787: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_78c:
	/* 0x78c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_78f:
	/* 0x78f: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_792:
	/* 0x792: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_795:
	/* 0x795: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_79a:
	/* 0x79a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79c:
	/* 0x79c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_79e:
	/* 0x79e: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_7a3:
	/* 0x7a3: js     b59 <tail_nodeport_nat_ingress_ipv6+0xb59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b59;
	}
x86_l_7a9:
	/* 0x7a9: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7ad:
	/* 0x7ad: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_7af:
	/* 0x7af: movzx  ecx,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_7b7:
	/* 0x7b7: movzx  edx,WORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 130ULL);
x86_l_7bf:
	/* 0x7bf: mov    WORD PTR [rsp+0x82],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 130ULL);
x86_l_7c7:
	/* 0x7c7: mov    WORD PTR [rsp+0x80],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7cf:
	/* 0x7cf: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_7d3:
	/* 0x7d3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7d8:
	/* 0x7d8: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_7db:
	/* 0x7db: jb     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 4318ULL;
	}
x86_l_7e1:
	/* 0x7e1: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7e5:
	/* 0x7e5: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7ea:
	/* 0x7ea: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7ef:
	/* 0x7ef: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_7f6:
	/* 0x7f6: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7fb:
	/* 0x7fb: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_801:
	/* 0x801: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_804:
	/* 0x804: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_807:
	/* 0x807: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_80c:
	/* 0x80c: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_80f:
	/* 0x80f: je     f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3895ULL;
	}
x86_l_815:
	/* 0x815: lea    rax,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_81a:
	/* 0x81a: mov    QWORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_823:
	/* 0x823: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_82c:
	/* 0x82c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_835:
	/* 0x835: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_83e:
	/* 0x83e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_847:
	/* 0x847: mov    rcx,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_84b:
	/* 0x84b: mov    rdx,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_84f:
	/* 0x84f: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_854:
	/* 0x854: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_859:
	/* 0x859: movzx  ecx,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_85e:
	/* 0x85e: mov    WORD PTR [rsp+0x32],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_863:
	/* 0x863: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_866:
	/* 0x866: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_86f:
	/* 0x86f: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_874:
	/* 0x874: movzx  eax,WORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 130ULL);
x86_l_87c:
	/* 0x87c: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_881:
	/* 0x881: movzx  eax,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_889:
	/* 0x889: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_88d:
	/* 0x88d: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_892:
	/* 0x892: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_899:
	/* 0x899: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89e:
	/* 0x89e: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_8a1:
	/* 0x8a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a4:
	/* 0x8a4: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8a9:
	/* 0x8a9: jne    9bd <tail_nodeport_nat_ingress_ipv6+0x9bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9bd;
	}
x86_l_8af:
	/* 0x8af: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_8bb:
	/* 0x8bb: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_8c7:
	/* 0x8c7: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_8d3:
	/* 0x8d3: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_8df:
	/* 0x8df: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_8eb:
	/* 0x8eb: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f0:
	/* 0x8f0: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8f5:
	/* 0x8f5: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_8fd:
	/* 0x8fd: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_905:
	/* 0x905: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_90d:
	/* 0x90d: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_915:
	/* 0x915: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_919:
	/* 0x919: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_921:
	/* 0x921: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_928:
	/* 0x928: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92b:
	/* 0x92b: je     96d <tail_nodeport_nat_ingress_ipv6+0x96d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_96d;
	}
x86_l_92d:
	/* 0x92d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_932:
	/* 0x932: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_934:
	/* 0x934: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_936:
	/* 0x936: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_93a:
	/* 0x93a: jmp    990 <tail_nodeport_nat_ingress_ipv6+0x990> */
	goto x86_l_990;
x86_l_93c:
	/* 0x93c: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_941:
	/* 0x941: mov    QWORD PTR [r15],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_944:
	/* 0x944: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	return 3895ULL;
x86_l_949:
	/* 0x949: movzx  eax,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_94e:
	/* 0x94e: mov    WORD PTR [rsp+0x80],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_956:
	/* 0x956: mov    WORD PTR [rsp+0x82],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 558345748480ULL);
x86_l_960:
	/* 0x960: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_965:
	/* 0x965: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_968:
	/* 0x968: jmp    7e1 <tail_nodeport_nat_ingress_ipv6+0x7e1> */
	goto x86_l_7e1;
x86_l_96d:
	/* 0x96d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_972:
	/* 0x972: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_974:
	/* 0x974: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_976:
	/* 0x976: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_97a:
	/* 0x97a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_984:
	/* 0x984: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_987:
	/* 0x987: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_990:
	/* 0x990: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_998:
	/* 0x998: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_99f:
	/* 0x99f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a4:
	/* 0x9a4: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9ac:
	/* 0x9ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9b1:
	/* 0x9b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b3:
	/* 0x9b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b5:
	/* 0x9b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9b7:
	/* 0x9b7: js     abd <tail_nodeport_nat_ingress_ipv6+0xabd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_abd;
	}
x86_l_9bd:
	/* 0x9bd: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_9c2:
	/* 0x9c2: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9c7:
	/* 0x9c7: je     1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5528ULL;
	}
x86_l_9cd:
	/* 0x9cd: movzx  eax,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_9d5:
	/* 0x9d5: mov    WORD PTR [rsp+0xbc],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_9dd:
	/* 0x9dd: movzx  ecx,WORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 130ULL);
x86_l_9e5:
	/* 0x9e5: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9ea:
	/* 0x9ea: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9f2:
	/* 0x9f2: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f7:
	/* 0x9f7: mov    QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9ff:
	/* 0x9ff: mov    rdx,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a03:
	/* 0xa03: mov    QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a0b:
	/* 0xa0b: mov    rdx,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a0f:
	/* 0xa0f: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a17:
	/* 0xa17: movzx  edx,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_a1c:
	/* 0xa1c: mov    WORD PTR [rsp+0xba],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 186ULL);
x86_l_a24:
	/* 0xa24: mov    WORD PTR [rsp+0xb8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a2c:
	/* 0xa2c: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a2f:
	/* 0xa2f: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_a33:
	/* 0xa33: jne    a3e <tail_nodeport_nat_ingress_ipv6+0xa3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a3e;
	}
x86_l_a35:
	/* 0xa35: mov    r12,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_a3c:
	/* 0xa3c: jmp    a45 <tail_nodeport_nat_ingress_ipv6+0xa45> */
	goto x86_l_a45;
x86_l_a3e:
	/* 0xa3e: mov    r12,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_a45:
	/* 0xa45: mov    BYTE PTR [rsp+0xbd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 811748818944ULL);
x86_l_a4d:
	/* 0xa4d: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a55:
	/* 0xa55: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_a5c:
	/* 0xa5c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5f:
	/* 0xa5f: je     af9 <tail_nodeport_nat_ingress_ipv6+0xaf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af9;
	}
x86_l_a65:
	/* 0xa65: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_a6f:
	/* 0xa6f: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_a72:
	/* 0xa72: je     af9 <tail_nodeport_nat_ingress_ipv6+0xaf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af9;
	}
x86_l_a78:
	/* 0xa78: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7b:
	/* 0xa7b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a84:
	/* 0xa84: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_a8d:
	/* 0xa8d: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_a97:
	/* 0xa97: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a9c:
	/* 0xa9c: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_aa3:
	/* 0xaa3: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aa8:
	/* 0xaa8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aad:
	/* 0xaad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aaf:
	/* 0xaaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab2:
	/* 0xab2: je     ac7 <tail_nodeport_nat_ingress_ipv6+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac7;
	}
x86_l_ab4:
	/* 0xab4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ab7:
	/* 0xab7: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_abb:
	/* 0xabb: jmp    aef <tail_nodeport_nat_ingress_ipv6+0xaef> */
	goto x86_l_aef;
x86_l_abd:
	/* 0xabd: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_ac2:
	/* 0xac2: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	return 4318ULL;
x86_l_ac7:
	/* 0xac7: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_ad0:
	/* 0xad0: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad5:
	/* 0xad5: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_adc:
	/* 0xadc: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ae1:
	/* 0xae1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae6:
	/* 0xae6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_aeb:
	/* 0xaeb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aed:
	/* 0xaed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aef:
	/* 0xaef: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_af4:
	/* 0xaf4: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_af9:
	/* 0xaf9: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_afd:
	/* 0xafd: jne    b63 <tail_nodeport_nat_ingress_ipv6+0xb63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b63;
	}
x86_l_aff:
	/* 0xaff: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_b09:
	/* 0xb09: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_b0c:
	/* 0xb0c: jne    b63 <tail_nodeport_nat_ingress_ipv6+0xb63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b63;
	}
x86_l_b0e:
	/* 0xb0e: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_b11:
	/* 0xb11: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b16:
	/* 0xb16: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b1b:
	/* 0xb1b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b23:
	/* 0xb23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b25:
	/* 0xb25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b27:
	/* 0xb27: js     b59 <tail_nodeport_nat_ingress_ipv6+0xb59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b59;
	}
x86_l_b29:
	/* 0xb29: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b30:
	/* 0xb30: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b34:
	/* 0xb34: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_b36:
	/* 0xb36: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_b3b:
	/* 0xb3b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3d:
	/* 0xb3d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_b42:
	/* 0xb42: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b45:
	/* 0xb45: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b48:
	/* 0xb48: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_b4e:
	/* 0xb4e: jne    14a7 <tail_nodeport_nat_ingress_ipv6+0x14a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5287ULL;
	}
x86_l_b54:
	/* 0xb54: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_b57:
	/* 0xb57: jmp    b73 <tail_nodeport_nat_ingress_ipv6+0xb73> */
	goto x86_l_b73;
x86_l_b59:
	/* 0xb59: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_b5e:
	/* 0xb5e: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	return 4318ULL;
x86_l_b63:
	/* 0xb63: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b6a:
	/* 0xb6a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b6c:
	/* 0xb6c: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b70:
	/* 0xb70: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b73:
	/* 0xb73: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b7b:
	/* 0xb7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b80:
	/* 0xb80: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b83:
	/* 0xb83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b85:
	/* 0xb85: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b88:
	/* 0xb88: je     158a <tail_nodeport_nat_ingress_ipv6+0x158a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5514ULL;
	}
x86_l_b8e:
	/* 0xb8e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_b91:
	/* 0xb91: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b94:
	/* 0xb94: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b96:
	/* 0xb96: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b98:
	/* 0xb98: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b9b:
	/* 0xb9b: je     cb0 <tail_nodeport_nat_ingress_ipv6+0xcb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb0;
	}
x86_l_ba1:
	/* 0xba1: mov    QWORD PTR [rsp+0xe0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_ba9:
	/* 0xba9: mov    rdx,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bb0:
	/* 0xbb0: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb3:
	/* 0xbb3: je     bc6 <tail_nodeport_nat_ingress_ipv6+0xbc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc6;
	}
x86_l_bb5:
	/* 0xbb5: mov    rcx,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bbc:
	/* 0xbbc: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_bc0:
	/* 0xbc0: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bc4:
	/* 0xbc4: jmp    bcc <tail_nodeport_nat_ingress_ipv6+0xbcc> */
	goto x86_l_bcc;
x86_l_bc6:
	/* 0xbc6: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_bcc:
	/* 0xbcc: cmp    WORD PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_bd5:
	/* 0xbd5: jne    c0f <tail_nodeport_nat_ingress_ipv6+0xc0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c0f;
	}
x86_l_bd7:
	/* 0xbd7: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bda:
	/* 0xbda: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bdc:
	/* 0xbdc: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_bdf:
	/* 0xbdf: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_be2:
	/* 0xbe2: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_be4:
	/* 0xbe4: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bea:
	/* 0xbea: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_bec:
	/* 0xbec: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_bf1:
	/* 0xbf1: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_bf7:
	/* 0xbf7: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_bfb:
	/* 0xbfb: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bfe:
	/* 0xbfe: je     c0f <tail_nodeport_nat_ingress_ipv6+0xc0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0f;
	}
x86_l_c00:
	/* 0xc00: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c07:
	/* 0xc07: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_c0b:
	/* 0xc0b: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c0f:
	/* 0xc0f: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c13:
	/* 0xc13: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c17:
	/* 0xc17: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1a:
	/* 0xc1a: je     c2b <tail_nodeport_nat_ingress_ipv6+0xc2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2b;
	}
x86_l_c1c:
	/* 0xc1c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_c21:
	/* 0xc21: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c23:
	/* 0xc23: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c25:
	/* 0xc25: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c29:
	/* 0xc29: jmp    c4e <tail_nodeport_nat_ingress_ipv6+0xc4e> */
	goto x86_l_c4e;
x86_l_c2b:
	/* 0xc2b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c30:
	/* 0xc30: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c32:
	/* 0xc32: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c34:
	/* 0xc34: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c38:
	/* 0xc38: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c42:
	/* 0xc42: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c45:
	/* 0xc45: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c4a:
	/* 0xc4a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c4e:
	/* 0xc4e: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c51:
	/* 0xc51: mov    DWORD PTR [r12+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c56:
	/* 0xc56: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c5c:
	/* 0xc5c: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c61:
	/* 0xc61: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c65:
	/* 0xc65: mov    rsi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c6c:
	/* 0xc6c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6f:
	/* 0xc6f: je     c82 <tail_nodeport_nat_ingress_ipv6+0xc82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c82;
	}
x86_l_c71:
	/* 0xc71: mov    rsi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c78:
	/* 0xc78: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7a:
	/* 0xc7a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c7d:
	/* 0xc7d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c80:
	/* 0xc80: jmp    c87 <tail_nodeport_nat_ingress_ipv6+0xc87> */
	goto x86_l_c87;
x86_l_c82:
	/* 0xc82: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c87:
	/* 0xc87: mov    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_c8f:
	/* 0xc8f: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c91:
	/* 0xc91: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c94:
	/* 0xc94: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c96:
	/* 0xc96: jb     c9d <tail_nodeport_nat_ingress_ipv6+0xc9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c9d;
	}
x86_l_c98:
	/* 0xc98: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_c9b:
	/* 0xc9b: je     cb0 <tail_nodeport_nat_ingress_ipv6+0xcb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb0;
	}
x86_l_c9d:
	/* 0xc9d: mov    BYTE PTR [r12+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_ca2:
	/* 0xca2: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ca7:
	/* 0xca7: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_cae:
	/* 0xcae: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb0:
	/* 0xcb0: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_cb7:
	/* 0xcb7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cba:
	/* 0xcba: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cbf:
	/* 0xcbf: je     ccf <tail_nodeport_nat_ingress_ipv6+0xccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ccf;
	}
x86_l_cc1:
	/* 0xcc1: inc QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_cc7:
	/* 0xcc7: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc9:
	/* 0xcc9: add QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R12, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_ccf:
	/* 0xccf: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cd2:
	/* 0xcd2: je     d21 <tail_nodeport_nat_ingress_ipv6+0xd21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d21;
	}
x86_l_cd4:
	/* 0xcd4: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_cd7:
	/* 0xcd7: jne    1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5528ULL;
	}
x86_l_cdd:
	/* 0xcdd: movzx  eax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ce3:
	/* 0xce3: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_ce5:
	/* 0xce5: je     1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5528ULL;
	}
x86_l_ceb:
	/* 0xceb: mov    WORD PTR [r12+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_cf3:
	/* 0xcf3: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_cf8:
	/* 0xcf8: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cfe:
	/* 0xcfe: mov    r14,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d05:
	/* 0xd05: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d09:
	/* 0xd09: je     14b1 <tail_nodeport_nat_ingress_ipv6+0x14b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5297ULL;
	}
x86_l_d0f:
	/* 0xd0f: mov    rcx,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d16:
	/* 0xd16: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_d19:
	/* 0xd19: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d1c:
	/* 0xd1c: jmp    14b6 <tail_nodeport_nat_ingress_ipv6+0x14b6> */
	return 5302ULL;
x86_l_d21:
	/* 0xd21: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d24:
	/* 0xd24: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_d27:
	/* 0xd27: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_d2a:
	/* 0xd2a: or     ax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_d30:
	/* 0xd30: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_d32:
	/* 0xd32: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_d35:
	/* 0xd35: mov    WORD PTR [r12+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d3b:
	/* 0xd3b: mov    rcx,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d42:
	/* 0xd42: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d44:
	/* 0xd44: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_d46:
	/* 0xd46: je     1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5528ULL;
	}
x86_l_d4c:
	/* 0xd4c: mov    r14,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d53:
	/* 0xd53: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d57:
	/* 0xd57: je     d7b <tail_nodeport_nat_ingress_ipv6+0xd7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7b;
	}
x86_l_d59:
	/* 0xd59: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d60:
	/* 0xd60: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d62:
	/* 0xd62: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d64:
	/* 0xd64: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_d67:
	/* 0xd67: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d6a:
	/* 0xd6a: jmp    d80 <tail_nodeport_nat_ingress_ipv6+0xd80> */
	goto x86_l_d80;
x86_l_d6c:
	/* 0xd6c: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_d70:
	/* 0xd70: je     fba <tail_nodeport_nat_ingress_ipv6+0xfba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4026ULL;
	}
x86_l_d76:
	/* 0xd76: jmp    fc1 <tail_nodeport_nat_ingress_ipv6+0xfc1> */
	return 4033ULL;
x86_l_d7b:
	/* 0xd7b: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_d80:
	/* 0xd80: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_d84:
	/* 0xd84: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d88:
	/* 0xd88: je     d99 <tail_nodeport_nat_ingress_ipv6+0xd99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d99;
	}
x86_l_d8a:
	/* 0xd8a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d8f:
	/* 0xd8f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d91:
	/* 0xd91: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d93:
	/* 0xd93: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d97:
	/* 0xd97: jmp    dbc <tail_nodeport_nat_ingress_ipv6+0xdbc> */
	goto x86_l_dbc;
x86_l_d99:
	/* 0xd99: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d9e:
	/* 0xd9e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da0:
	/* 0xda0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_da2:
	/* 0xda2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_da6:
	/* 0xda6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_db0:
	/* 0xdb0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_db3:
	/* 0xdb3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_dbc:
	/* 0xdbc: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dbe:
	/* 0xdbe: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dc3:
	/* 0xdc3: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_dc9:
	/* 0xdc9: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_dce:
	/* 0xdce: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd1:
	/* 0xdd1: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_dd5:
	/* 0xdd5: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd8:
	/* 0xdd8: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ddc:
	/* 0xddc: je     def <tail_nodeport_nat_ingress_ipv6+0xdef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_def;
	}
x86_l_dde:
	/* 0xdde: mov    rsi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_de5:
	/* 0xde5: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de7:
	/* 0xde7: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_dea:
	/* 0xdea: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ded:
	/* 0xded: jmp    df4 <tail_nodeport_nat_ingress_ipv6+0xdf4> */
	goto x86_l_df4;
x86_l_def:
	/* 0xdef: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_df4:
	/* 0xdf4: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_df6:
	/* 0xdf6: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df9:
	/* 0xdf9: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_dfb:
	/* 0xdfb: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dfe:
	/* 0xdfe: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_e00:
	/* 0xe00: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e05:
	/* 0xe05: jb     e10 <tail_nodeport_nat_ingress_ipv6+0xe10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e10;
	}
x86_l_e07:
	/* 0xe07: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e0a:
	/* 0xe0a: je     1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5528ULL;
	}
x86_l_e10:
	/* 0xe10: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e13:
	/* 0xe13: mov    BYTE PTR [r12+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_e18:
	/* 0xe18: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e1d:
	/* 0xe1d: mov    rax,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e24:
	/* 0xe24: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e26:
	/* 0xe26: jmp    1598 <tail_nodeport_nat_ingress_ipv6+0x1598> */
	return 5528ULL;
x86_l_e2b:
	/* 0xe2b: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_e30:
	/* 0xe30: jmp    e3e <tail_nodeport_nat_ingress_ipv6+0xe3e> */
	goto x86_l_e3e;
x86_l_e32:
	/* 0xe32: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_e37:
	/* 0xe37: lea    ebp,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_e3e:
	/* 0xe3e: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_e41:
	/* 0xe41: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_e45:
	/* 0xe45: ja     f5a <tail_nodeport_nat_ingress_ipv6+0xf5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3930ULL;
	}
x86_l_e4b:
	/* 0xe4b: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_e4e:
	/* 0xe4e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_e58:
	/* 0xe58: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_e5c:
	/* 0xe5c: jae    eb6 <tail_nodeport_nat_ingress_ipv6+0xeb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3766ULL;
	}
x86_l_e5e:
	/* 0xe5e: lea    esi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
	return 3682ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3682ULL: goto x86_l_e62;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3710ULL: goto x86_l_e7e;
	case 3716ULL: goto x86_l_e84;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3750ULL: goto x86_l_ea6;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3769ULL: goto x86_l_eb9;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3799ULL: goto x86_l_ed7;
	case 3802ULL: goto x86_l_eda;
	case 3804ULL: goto x86_l_edc;
	case 3814ULL: goto x86_l_ee6;
	case 3818ULL: goto x86_l_eea;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3844ULL: goto x86_l_f04;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3854ULL: goto x86_l_f0e;
	case 3858ULL: goto x86_l_f12;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3874ULL: goto x86_l_f22;
	case 3876ULL: goto x86_l_f24;
	case 3881ULL: goto x86_l_f29;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3923ULL: goto x86_l_f53;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3955ULL: goto x86_l_f73;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3969ULL: goto x86_l_f81;
	case 3973ULL: goto x86_l_f85;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4015ULL: goto x86_l_faf;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4028ULL: goto x86_l_fbc;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4041ULL: goto x86_l_fc9;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4069ULL: goto x86_l_fe5;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4082ULL: goto x86_l_ff2;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4091ULL: goto x86_l_ffb;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4106ULL: goto x86_l_100a;
	case 4108ULL: goto x86_l_100c;
	case 4114ULL: goto x86_l_1012;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4180ULL: goto x86_l_1054;
	case 4187ULL: goto x86_l_105b;
	case 4195ULL: goto x86_l_1063;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4208ULL: goto x86_l_1070;
	case 4214ULL: goto x86_l_1076;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4256ULL: goto x86_l_10a0;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4267ULL: goto x86_l_10ab;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4283ULL: goto x86_l_10bb;
	case 4288ULL: goto x86_l_10c0;
	case 4290ULL: goto x86_l_10c2;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4311ULL: goto x86_l_10d7;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4325ULL: goto x86_l_10e5;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4339ULL: goto x86_l_10f3;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4361ULL: goto x86_l_1109;
	case 4366ULL: goto x86_l_110e;
	case 4372ULL: goto x86_l_1114;
	case 4374ULL: goto x86_l_1116;
	case 4376ULL: goto x86_l_1118;
	case 4379ULL: goto x86_l_111b;
	case 4382ULL: goto x86_l_111e;
	case 4386ULL: goto x86_l_1122;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4416ULL: goto x86_l_1140;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4435ULL: goto x86_l_1153;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4452ULL: goto x86_l_1164;
	case 4454ULL: goto x86_l_1166;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4480ULL: goto x86_l_1180;
	case 4488ULL: goto x86_l_1188;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4517ULL: goto x86_l_11a5;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4532ULL: goto x86_l_11b4;
	case 4537ULL: goto x86_l_11b9;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4551ULL: goto x86_l_11c7;
	case 4553ULL: goto x86_l_11c9;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4572ULL: goto x86_l_11dc;
	case 4576ULL: goto x86_l_11e0;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4662ULL: goto x86_l_1236;
	case 4666ULL: goto x86_l_123a;
	case 4672ULL: goto x86_l_1240;
	case 4676ULL: goto x86_l_1244;
	case 4678ULL: goto x86_l_1246;
	case 4680ULL: goto x86_l_1248;
	case 4687ULL: goto x86_l_124f;
	case 4698ULL: goto x86_l_125a;
	case 4702ULL: goto x86_l_125e;
	case 4708ULL: goto x86_l_1264;
	case 4719ULL: goto x86_l_126f;
	case 4724ULL: goto x86_l_1274;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4746ULL: goto x86_l_128a;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4757ULL: goto x86_l_1295;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4793ULL: goto x86_l_12b9;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4817ULL: goto x86_l_12d1;
	case 4822ULL: goto x86_l_12d6;
	case 4830ULL: goto x86_l_12de;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4851ULL: goto x86_l_12f3;
	case 4855ULL: goto x86_l_12f7;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4874ULL: goto x86_l_130a;
	case 4878ULL: goto x86_l_130e;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4902ULL: goto x86_l_1326;
	case 4907ULL: goto x86_l_132b;
	case 4911ULL: goto x86_l_132f;
	case 4913ULL: goto x86_l_1331;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4934ULL: goto x86_l_1346;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4957ULL: goto x86_l_135d;
	case 4960ULL: goto x86_l_1360;
	case 4968ULL: goto x86_l_1368;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4987ULL: goto x86_l_137b;
	case 4989ULL: goto x86_l_137d;
	case 4991ULL: goto x86_l_137f;
	case 4997ULL: goto x86_l_1385;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5015ULL: goto x86_l_1397;
	case 5017ULL: goto x86_l_1399;
	case 5025ULL: goto x86_l_13a1;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5037ULL: goto x86_l_13ad;
	case 5039ULL: goto x86_l_13af;
	case 5046ULL: goto x86_l_13b6;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5056ULL: goto x86_l_13c0;
	case 5058ULL: goto x86_l_13c2;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5099ULL: goto x86_l_13eb;
	case 5104ULL: goto x86_l_13f0;
	case 5107ULL: goto x86_l_13f3;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5114ULL: goto x86_l_13fa;
	case 5116ULL: goto x86_l_13fc;
	case 5122ULL: goto x86_l_1402;
	case 5125ULL: goto x86_l_1405;
	case 5137ULL: goto x86_l_1411;
	case 5149ULL: goto x86_l_141d;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5171ULL: goto x86_l_1433;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5245ULL: goto x86_l_147d;
	case 5253ULL: goto x86_l_1485;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5318ULL: goto x86_l_14c6;
	case 5321ULL: goto x86_l_14c9;
	case 5324ULL: goto x86_l_14cc;
	case 5326ULL: goto x86_l_14ce;
	case 5332ULL: goto x86_l_14d4;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5347ULL: goto x86_l_14e3;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5376ULL: goto x86_l_1500;
	case 5381ULL: goto x86_l_1505;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e62:
	/* 0xe62: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e67:
	/* 0xe67: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e6c:
	/* 0xe6c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e74:
	/* 0xe74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e76:
	/* 0xe76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e78:
	/* 0xe78: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f32;
	}
x86_l_e7e:
	/* 0xe7e: movzx  r13d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_e84:
	/* 0xe84: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e88:
	/* 0xe88: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_e8c:
	/* 0xe8c: jle    ea8 <tail_nodeport_nat_ingress_ipv6+0xea8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ea8;
	}
x86_l_e8e:
	/* 0xe8e: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_e92:
	/* 0xe92: je     ec7 <tail_nodeport_nat_ingress_ipv6+0xec7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec7;
	}
x86_l_e94:
	/* 0xe94: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_e98:
	/* 0xe98: jne    ea8 <tail_nodeport_nat_ingress_ipv6+0xea8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ea8;
	}
x86_l_e9a:
	/* 0xe9a: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_e9f:
	/* 0xe9f: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_ea6:
	/* 0xea6: jmp    ecc <tail_nodeport_nat_ingress_ipv6+0xecc> */
	goto x86_l_ecc;
x86_l_ea8:
	/* 0xea8: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_ead:
	/* 0xead: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_eb4:
	/* 0xeb4: jmp    ecc <tail_nodeport_nat_ingress_ipv6+0xecc> */
	goto x86_l_ecc;
x86_l_eb6:
	/* 0xeb6: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_eb9:
	/* 0xeb9: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_ebd:
	/* 0xebd: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ec2:
	/* 0xec2: jmp    fb3 <tail_nodeport_nat_ingress_ipv6+0xfb3> */
	goto x86_l_fb3;
x86_l_ec7:
	/* 0xec7: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_ecc:
	/* 0xecc: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ece:
	/* 0xece: cmp    ecx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_ed1:
	/* 0xed1: ja     f5d <tail_nodeport_nat_ingress_ipv6+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f5d;
	}
x86_l_ed7:
	/* 0xed7: mov    r14d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_32);
x86_l_eda:
	/* 0xeda: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_edc:
	/* 0xedc: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_ee6:
	/* 0xee6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_eea:
	/* 0xeea: jae    f4f <tail_nodeport_nat_ingress_ipv6+0xf4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f4f;
	}
x86_l_eec:
	/* 0xeec: lea    esi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ef0:
	/* 0xef0: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef5:
	/* 0xef5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_efa:
	/* 0xefa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_efd:
	/* 0xefd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f02:
	/* 0xf02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f04:
	/* 0xf04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f06:
	/* 0xf06: js     f32 <tail_nodeport_nat_ingress_ipv6+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f32;
	}
x86_l_f08:
	/* 0xf08: movzx  r13d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_f0e:
	/* 0xf0e: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f12:
	/* 0xf12: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_f16:
	/* 0xf16: jle    f41 <tail_nodeport_nat_ingress_ipv6+0xf41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_f41;
	}
x86_l_f18:
	/* 0xf18: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_f1c:
	/* 0xf1c: je     f64 <tail_nodeport_nat_ingress_ipv6+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f64;
	}
x86_l_f1e:
	/* 0xf1e: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_f22:
	/* 0xf22: jne    f41 <tail_nodeport_nat_ingress_ipv6+0xf41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f41;
	}
x86_l_f24:
	/* 0xf24: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_f29:
	/* 0xf29: lea    ecx,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_f30:
	/* 0xf30: jmp    f69 <tail_nodeport_nat_ingress_ipv6+0xf69> */
	goto x86_l_f69;
x86_l_f32:
	/* 0xf32: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_f37:
	/* 0xf37: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f3c:
	/* 0xf3c: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	goto x86_l_10de;
x86_l_f41:
	/* 0xf41: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_f46:
	/* 0xf46: lea    ecx,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_f4d:
	/* 0xf4d: jmp    f69 <tail_nodeport_nat_ingress_ipv6+0xf69> */
	goto x86_l_f69;
x86_l_f4f:
	/* 0xf4f: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_f53:
	/* 0xf53: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f58:
	/* 0xf58: jmp    fb3 <tail_nodeport_nat_ingress_ipv6+0xfb3> */
	goto x86_l_fb3;
x86_l_f5a:
	/* 0xf5a: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_f5d:
	/* 0xf5d: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f62:
	/* 0xf62: jmp    fc1 <tail_nodeport_nat_ingress_ipv6+0xfc1> */
	goto x86_l_fc1;
x86_l_f64:
	/* 0xf64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f69:
	/* 0xf69: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f6e:
	/* 0xf6e: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f70:
	/* 0xf70: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_f73:
	/* 0xf73: ja     fc1 <tail_nodeport_nat_ingress_ipv6+0xfc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_fc1;
	}
x86_l_f75:
	/* 0xf75: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f77:
	/* 0xf77: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_f81:
	/* 0xf81: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f85:
	/* 0xf85: jae    faf <tail_nodeport_nat_ingress_ipv6+0xfaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_faf;
	}
x86_l_f87:
	/* 0xf87: add    ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f8a:
	/* 0xf8a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f8f:
	/* 0xf8f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f94:
	/* 0xf94: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f97:
	/* 0xf97: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f99:
	/* 0xf99: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f9e:
	/* 0xf9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa0:
	/* 0xfa0: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_fa5:
	/* 0xfa5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa7:
	/* 0xfa7: jns    4ad <tail_nodeport_nat_ingress_ipv6+0x4ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1197ULL;
	}
x86_l_fad:
	/* 0xfad: jmp    fba <tail_nodeport_nat_ingress_ipv6+0xfba> */
	goto x86_l_fba;
x86_l_faf:
	/* 0xfaf: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_fb3:
	/* 0xfb3: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_fb8:
	/* 0xfb8: jne    fc1 <tail_nodeport_nat_ingress_ipv6+0xfc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fc1;
	}
x86_l_fba:
	/* 0xfba: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_fbc:
	/* 0xfbc: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	goto x86_l_10de;
x86_l_fc1:
	/* 0xfc1: mov    BYTE PTR [rsp+0x34],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fc6:
	/* 0xfc6: add    ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fc9:
	/* 0xfc9: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_fcd:
	/* 0xfcd: je     fe5 <tail_nodeport_nat_ingress_ipv6+0xfe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe5;
	}
x86_l_fcf:
	/* 0xfcf: movzx  eax,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fd3:
	/* 0xfd3: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_fd6:
	/* 0xfd6: je     108a <tail_nodeport_nat_ingress_ipv6+0x108a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_108a;
	}
x86_l_fdc:
	/* 0xfdc: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_fdf:
	/* 0xfdf: jne    11cf <tail_nodeport_nat_ingress_ipv6+0x11cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11cf;
	}
x86_l_fe5:
	/* 0xfe5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fea:
	/* 0xfea: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_fef:
	/* 0xfef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ff2:
	/* 0xff2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_ff4:
	/* 0xff4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ff9:
	/* 0xff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffb:
	/* 0xffb: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ffd:
	/* 0xffd: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1002:
	/* 0x1002: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_100a:
	/* 0x100a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_100c:
	/* 0x100c: js     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10de;
	}
x86_l_1012:
	/* 0x1012: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1019:
	/* 0x1019: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101e:
	/* 0x101e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1023:
	/* 0x1023: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1025:
	/* 0x1025: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_102d:
	/* 0x102d: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1030:
	/* 0x1030: je     10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10de;
	}
x86_l_1036:
	/* 0x1036: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_103b:
	/* 0x103b: movzx  r14d,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_1041:
	/* 0x1041: movzx  ecx,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1046:
	/* 0x1046: movzx  edx,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_104b:
	/* 0x104b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1050:
	/* 0x1050: cmp    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1054:
	/* 0x1054: mov    DWORD PTR [rsp+0xf4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_105b:
	/* 0x105b: mov    WORD PTR [rsp+0xee],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 238ULL);
x86_l_1063:
	/* 0x1063: jne    11d9 <tail_nodeport_nat_ingress_ipv6+0x11d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11d9;
	}
x86_l_1069:
	/* 0x1069: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_106c:
	/* 0x106c: sete   BYTE PTR [rsp] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 0ULL);
x86_l_1070:
	/* 0x1070: jne    11e0 <tail_nodeport_nat_ingress_ipv6+0x11e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11e0;
	}
x86_l_1076:
	/* 0x1076: mov    rax,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_107a:
	/* 0x107a: cmp    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_107f:
	/* 0x107f: je     13c0 <tail_nodeport_nat_ingress_ipv6+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13c0;
	}
x86_l_1085:
	/* 0x1085: jmp    11e0 <tail_nodeport_nat_ingress_ipv6+0x11e0> */
	goto x86_l_11e0;
x86_l_108a:
	/* 0x108a: lea    rdx,[rsp+0x5f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 95ULL);
x86_l_108f:
	/* 0x108f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1094:
	/* 0x1094: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1097:
	/* 0x1097: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1099:
	/* 0x1099: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_109e:
	/* 0x109e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a0:
	/* 0x10a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a2:
	/* 0x10a2: js     10d9 <tail_nodeport_nat_ingress_ipv6+0x10d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_10d9;
	}
x86_l_10a4:
	/* 0x10a4: cmp    BYTE PTR [rsp+0x5f],0x80 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 408021893248ULL);
x86_l_10a9:
	/* 0x10a9: jne    10d9 <tail_nodeport_nat_ingress_ipv6+0x10d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10d9;
	}
x86_l_10ab:
	/* 0x10ab: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10ae:
	/* 0x10ae: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10b3:
	/* 0x10b3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_10b8:
	/* 0x10b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10bb:
	/* 0x10bb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10c0:
	/* 0x10c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c2:
	/* 0x10c2: mov    DWORD PTR [rsp+0x40],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906948ULL);
x86_l_10ca:
	/* 0x10ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10cc:
	/* 0x10cc: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_10d1:
	/* 0x10d1: jns    1012 <tail_nodeport_nat_ingress_ipv6+0x1012> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1012;
	}
x86_l_10d7:
	/* 0x10d7: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	goto x86_l_10de;
x86_l_10d9:
	/* 0x10d9: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_10de:
	/* 0x10de: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_10e3:
	/* 0x10e3: je     10ef <tail_nodeport_nat_ingress_ipv6+0x10ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10ef;
	}
x86_l_10e5:
	/* 0x10e5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e8:
	/* 0x10e8: cmp    eax,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_10ed:
	/* 0x10ed: jne    1114 <tail_nodeport_nat_ingress_ipv6+0x1114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1114;
	}
x86_l_10ef:
	/* 0x10ef: or     BYTE PTR [rbx+0x2c],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 188978561028ULL);
x86_l_10f3:
	/* 0x10f3: mov    rsi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_10fa:
	/* 0x10fa: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10ff:
	/* 0x10ff: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1102:
	/* 0x1102: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1107:
	/* 0x1107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1109:
	/* 0x1109: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_110e:
	/* 0x110e: mov    r15d,0xa00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2560ULL);
x86_l_1114:
	/* 0x1114: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1116:
	/* 0x1116: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1118:
	/* 0x1118: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_111b:
	/* 0x111b: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_111e:
	/* 0x111e: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1122:
	/* 0x1122: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_1129:
	/* 0x1129: or     eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_OR);
x86_l_112c:
	/* 0x112c: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_112f:
	/* 0x112f: movabs rcx,0x4b2680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 338447279805431808ULL);
x86_l_1139:
	/* 0x1139: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_113d:
	/* 0x113d: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1140:
	/* 0x1140: movabs rcx,0x6804b20100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446755373312ULL);
x86_l_114a:
	/* 0x114a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114f:
	/* 0x114f: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1153:
	/* 0x1153: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_115a:
	/* 0x115a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115f:
	/* 0x115f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1164:
	/* 0x1164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1166:
	/* 0x1166: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1169:
	/* 0x1169: je     1174 <tail_nodeport_nat_ingress_ipv6+0x1174> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1174;
	}
x86_l_116b:
	/* 0x116b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_116e:
	/* 0x116e: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1172:
	/* 0x1172: jmp    11a5 <tail_nodeport_nat_ingress_ipv6+0x11a5> */
	goto x86_l_11a5;
x86_l_1174:
	/* 0x1174: mov    QWORD PTR [rsp+0x98],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028993ULL);
x86_l_1180:
	/* 0x1180: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1188:
	/* 0x1188: mov    rdi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_118f:
	/* 0x118f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1194:
	/* 0x1194: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_119c:
	/* 0x119c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11a1:
	/* 0x11a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a3:
	/* 0x11a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a5:
	/* 0x11a5: mov    rsi,QWORD PTR [rip+0x38f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_11ac:
	/* 0x11ac: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_11b1:
	/* 0x11b1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11b4:
	/* 0x11b4: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_11b9:
	/* 0x11b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bb:
	/* 0x11bb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c0:
	/* 0x11c0: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_11c7:
	/* 0x11c7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11c9:
	/* 0x11c9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11ca:
	/* 0x11ca: jmp    293e <tail_nodeport_nat_ingress_ipv6+0x293e> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_11cf:
	/* 0x11cf: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_11d4:
	/* 0x11d4: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	goto x86_l_10de;
x86_l_11d9:
	/* 0x11d9: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_11dc:
	/* 0x11dc: sete   BYTE PTR [rsp] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 0ULL);
x86_l_11e0:
	/* 0x11e0: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_11e3:
	/* 0x11e3: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_11e7:
	/* 0x11e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ec:
	/* 0x11ec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ee:
	/* 0x11ee: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_11f6:
	/* 0x11f6: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_11fb:
	/* 0x11fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1200:
	/* 0x1200: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1208:
	/* 0x1208: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_120b:
	/* 0x120b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120d:
	/* 0x120d: mov    DWORD PTR [rsp+0xf0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1214:
	/* 0x1214: lea    esi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1219:
	/* 0x1219: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_121e:
	/* 0x121e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1221:
	/* 0x1221: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1224:
	/* 0x1224: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1229:
	/* 0x1229: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_122c:
	/* 0x122c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122e:
	/* 0x122e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1230:
	/* 0x1230: js     13da <tail_nodeport_nat_ingress_ipv6+0x13da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13da;
	}
x86_l_1236:
	/* 0x1236: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_123a:
	/* 0x123a: je     12c6 <tail_nodeport_nat_ingress_ipv6+0x12c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c6;
	}
x86_l_1240:
	/* 0x1240: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_1244:
	/* 0x1244: je     12a1 <tail_nodeport_nat_ingress_ipv6+0x12a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a1;
	}
x86_l_1246:
	/* 0x1246: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1248:
	/* 0x1248: mov    DWORD PTR [rsp+0xdc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_124f:
	/* 0x124f: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_125a:
	/* 0x125a: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_125e:
	/* 0x125e: jne    12e9 <tail_nodeport_nat_ingress_ipv6+0x12e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12e9;
	}
x86_l_1264:
	/* 0x1264: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_126f:
	/* 0x126f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1274:
	/* 0x1274: jmp    12d6 <tail_nodeport_nat_ingress_ipv6+0x12d6> */
	goto x86_l_12d6;
x86_l_1276:
	/* 0x1276: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_1279:
	/* 0x1279: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1280:
	/* 0x1280: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1285:
	/* 0x1285: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1288:
	/* 0x1288: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128a:
	/* 0x128a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_128d:
	/* 0x128d: je     145a <tail_nodeport_nat_ingress_ipv6+0x145a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145a;
	}
x86_l_1293:
	/* 0x1293: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1295:
	/* 0x1295: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_129c:
	/* 0x129c: jmp    5e2 <tail_nodeport_nat_ingress_ipv6+0x5e2> */
	return 1506ULL;
x86_l_12a1:
	/* 0x12a1: mov    DWORD PTR [rsp+0x94],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159840ULL);
x86_l_12ac:
	/* 0x12ac: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_12b1:
	/* 0x12b1: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_12b9:
	/* 0x12b9: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_12c4:
	/* 0x12c4: jmp    12e9 <tail_nodeport_nat_ingress_ipv6+0x12e9> */
	goto x86_l_12e9;
x86_l_12c6:
	/* 0x12c6: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_12d1:
	/* 0x12d1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12d6:
	/* 0x12d6: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_12de:
	/* 0x12de: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_12e9:
	/* 0x12e9: cmp    BYTE PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ed:
	/* 0x12ed: jne    1385 <tail_nodeport_nat_ingress_ipv6+0x1385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1385;
	}
x86_l_12f3:
	/* 0x12f3: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_12f7:
	/* 0x12f7: ja     1467 <tail_nodeport_nat_ingress_ipv6+0x1467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1467;
	}
x86_l_12fd:
	/* 0x12fd: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1300:
	/* 0x1300: movabs rcx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_130a:
	/* 0x130a: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_130e:
	/* 0x130e: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_1313:
	/* 0x1313: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1318:
	/* 0x1318: jae    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_10de;
	}
x86_l_131e:
	/* 0x131e: movzx  eax,WORD PTR [rsp+0xee] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 238ULL);
x86_l_1326:
	/* 0x1326: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_132b:
	/* 0x132b: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_132f:
	/* 0x132f: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1331:
	/* 0x1331: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1336:
	/* 0x1336: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_133b:
	/* 0x133b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_133e:
	/* 0x133e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1343:
	/* 0x1343: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1346:
	/* 0x1346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1348:
	/* 0x1348: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_134a:
	/* 0x134a: js     13da <tail_nodeport_nat_ingress_ipv6+0x13da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_13da;
	}
x86_l_1350:
	/* 0x1350: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1355:
	/* 0x1355: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_135d:
	/* 0x135d: lea    esi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1360:
	/* 0x1360: mov    r8d,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1368:
	/* 0x1368: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_136c:
	/* 0x136c: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1371:
	/* 0x1371: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: mov    edx,DWORD PTR [rsp+0xf4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_137b:
	/* 0x137b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137d:
	/* 0x137d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_137f:
	/* 0x137f: js     18fc <tail_nodeport_nat_ingress_ipv6+0x18fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6396ULL;
	}
x86_l_1385:
	/* 0x1385: cmp    BYTE PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_138d:
	/* 0x138d: jne    13c0 <tail_nodeport_nat_ingress_ipv6+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c0;
	}
x86_l_138f:
	/* 0x138f: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1397:
	/* 0x1397: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1399:
	/* 0x1399: mov    r8d,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_13a1:
	/* 0x13a1: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_13a5:
	/* 0x13a5: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_13aa:
	/* 0x13aa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13ad:
	/* 0x13ad: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13af:
	/* 0x13af: mov    ecx,DWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_13b6:
	/* 0x13b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b8:
	/* 0x13b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ba:
	/* 0x13ba: js     18fc <tail_nodeport_nat_ingress_ipv6+0x18fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6396ULL;
	}
x86_l_13c0:
	/* 0x13c0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c2:
	/* 0x13c2: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13ca:
	/* 0x13ca: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_13cd:
	/* 0x13cd: mov    r13,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_13d5:
	/* 0x13d5: jmp    159d <tail_nodeport_nat_ingress_ipv6+0x159d> */
	return 5533ULL;
x86_l_13da:
	/* 0x13da: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_13df:
	/* 0x13df: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	goto x86_l_f37;
x86_l_13e4:
	/* 0x13e4: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_13eb:
	/* 0x13eb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13f0:
	/* 0x13f0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13f6:
	/* 0x13f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f8:
	/* 0x13f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fa:
	/* 0x13fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13fc:
	/* 0x13fc: je     5e2 <tail_nodeport_nat_ingress_ipv6+0x5e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1506ULL;
	}
x86_l_1402:
	/* 0x1402: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1405:
	/* 0x1405: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1411:
	/* 0x1411: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_141d:
	/* 0x141d: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_1427:
	/* 0x1427: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_142c:
	/* 0x142c: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1433:
	/* 0x1433: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1438:
	/* 0x1438: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143d:
	/* 0x143d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143f:
	/* 0x143f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1442:
	/* 0x1442: je     1471 <tail_nodeport_nat_ingress_ipv6+0x1471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1471;
	}
x86_l_1444:
	/* 0x1444: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1447:
	/* 0x1447: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_144b:
	/* 0x144b: jmp    5e2 <tail_nodeport_nat_ingress_ipv6+0x5e2> */
	return 1506ULL;
x86_l_1450:
	/* 0x1450: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_1455:
	/* 0x1455: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	goto x86_l_10de;
x86_l_145a:
	/* 0x145a: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_145f:
	/* 0x145f: mov    QWORD PTR [r15],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1462:
	/* 0x1462: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	goto x86_l_f37;
x86_l_1467:
	/* 0x1467: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_146c:
	/* 0x146c: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	goto x86_l_f37;
x86_l_1471:
	/* 0x1471: mov    QWORD PTR [rsp+0x98],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028993ULL);
x86_l_147d:
	/* 0x147d: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1485:
	/* 0x1485: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_148c:
	/* 0x148c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1491:
	/* 0x1491: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1499:
	/* 0x1499: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_149e:
	/* 0x149e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a0:
	/* 0x14a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a2:
	/* 0x14a2: jmp    5e2 <tail_nodeport_nat_ingress_ipv6+0x5e2> */
	return 1506ULL;
x86_l_14a7:
	/* 0x14a7: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_14ac:
	/* 0x14ac: jmp    b73 <tail_nodeport_nat_ingress_ipv6+0xb73> */
	return 2931ULL;
x86_l_14b1:
	/* 0x14b1: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_14b6:
	/* 0x14b6: cmp    WORD PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_14bf:
	/* 0x14bf: jne    14f6 <tail_nodeport_nat_ingress_ipv6+0x14f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14f6;
	}
x86_l_14c1:
	/* 0x14c1: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c4:
	/* 0x14c4: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14c6:
	/* 0x14c6: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_14c9:
	/* 0x14c9: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_14cc:
	/* 0x14cc: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_14ce:
	/* 0x14ce: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14d4:
	/* 0x14d4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14d6:
	/* 0x14d6: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_14db:
	/* 0x14db: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_14e0:
	/* 0x14e0: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_14e3:
	/* 0x14e3: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e7:
	/* 0x14e7: je     14f6 <tail_nodeport_nat_ingress_ipv6+0x14f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f6;
	}
x86_l_14e9:
	/* 0x14e9: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_14f0:
	/* 0x14f0: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_14f3:
	/* 0x14f3: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14f6:
	/* 0x14f6: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_14fa:
	/* 0x14fa: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fe:
	/* 0x14fe: je     150f <tail_nodeport_nat_ingress_ipv6+0x150f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5391ULL;
	}
x86_l_1500:
	/* 0x1500: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1505:
	/* 0x1505: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1507:
	/* 0x1507: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1509:
	/* 0x1509: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
	return 5389ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5389ULL: goto x86_l_150d;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5400ULL: goto x86_l_1518;
	case 5404ULL: goto x86_l_151c;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5426ULL: goto x86_l_1532;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5439ULL: goto x86_l_153f;
	case 5444ULL: goto x86_l_1544;
	case 5447ULL: goto x86_l_1547;
	case 5451ULL: goto x86_l_154b;
	case 5454ULL: goto x86_l_154e;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5467ULL: goto x86_l_155b;
	case 5469ULL: goto x86_l_155d;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5489ULL: goto x86_l_1571;
	case 5492ULL: goto x86_l_1574;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5499ULL: goto x86_l_157b;
	case 5501ULL: goto x86_l_157d;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5514ULL: goto x86_l_158a;
	case 5521ULL: goto x86_l_1591;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5533ULL: goto x86_l_159d;
	case 5542ULL: goto x86_l_15a6;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5564ULL: goto x86_l_15bc;
	case 5568ULL: goto x86_l_15c0;
	case 5570ULL: goto x86_l_15c2;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5590ULL: goto x86_l_15d6;
	case 5594ULL: goto x86_l_15da;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5610ULL: goto x86_l_15ea;
	case 5615ULL: goto x86_l_15ef;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5677ULL: goto x86_l_162d;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5684ULL: goto x86_l_1634;
	case 5686ULL: goto x86_l_1636;
	case 5690ULL: goto x86_l_163a;
	case 5692ULL: goto x86_l_163c;
	case 5696ULL: goto x86_l_1640;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5707ULL: goto x86_l_164b;
	case 5709ULL: goto x86_l_164d;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5720ULL: goto x86_l_1658;
	case 5722ULL: goto x86_l_165a;
	case 5724ULL: goto x86_l_165c;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5749ULL: goto x86_l_1675;
	case 5755ULL: goto x86_l_167b;
	case 5757ULL: goto x86_l_167d;
	case 5759ULL: goto x86_l_167f;
	case 5765ULL: goto x86_l_1685;
	case 5768ULL: goto x86_l_1688;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5777ULL: goto x86_l_1691;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5786ULL: goto x86_l_169a;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5804ULL: goto x86_l_16ac;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5823ULL: goto x86_l_16bf;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5853ULL: goto x86_l_16dd;
	case 5861ULL: goto x86_l_16e5;
	case 5864ULL: goto x86_l_16e8;
	case 5872ULL: goto x86_l_16f0;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5890ULL: goto x86_l_1702;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5906ULL: goto x86_l_1712;
	case 5910ULL: goto x86_l_1716;
	case 5918ULL: goto x86_l_171e;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5930ULL: goto x86_l_172a;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5980ULL: goto x86_l_175c;
	case 5983ULL: goto x86_l_175f;
	case 5986ULL: goto x86_l_1762;
	case 5988ULL: goto x86_l_1764;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6024ULL: goto x86_l_1788;
	case 6028ULL: goto x86_l_178c;
	case 6040ULL: goto x86_l_1798;
	case 6051ULL: goto x86_l_17a3;
	case 6063ULL: goto x86_l_17af;
	case 6075ULL: goto x86_l_17bb;
	case 6087ULL: goto x86_l_17c7;
	case 6099ULL: goto x86_l_17d3;
	case 6111ULL: goto x86_l_17df;
	case 6123ULL: goto x86_l_17eb;
	case 6135ULL: goto x86_l_17f7;
	case 6143ULL: goto x86_l_17ff;
	case 6146ULL: goto x86_l_1802;
	case 6153ULL: goto x86_l_1809;
	case 6162ULL: goto x86_l_1812;
	case 6171ULL: goto x86_l_181b;
	case 6180ULL: goto x86_l_1824;
	case 6189ULL: goto x86_l_182d;
	case 6198ULL: goto x86_l_1836;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6209ULL: goto x86_l_1841;
	case 6212ULL: goto x86_l_1844;
	case 6218ULL: goto x86_l_184a;
	case 6223ULL: goto x86_l_184f;
	case 6226ULL: goto x86_l_1852;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6243ULL: goto x86_l_1863;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6264ULL: goto x86_l_1878;
	case 6268ULL: goto x86_l_187c;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6295ULL: goto x86_l_1897;
	case 6297ULL: goto x86_l_1899;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6312ULL: goto x86_l_18a8;
	case 6314ULL: goto x86_l_18aa;
	case 6318ULL: goto x86_l_18ae;
	case 6320ULL: goto x86_l_18b0;
	case 6324ULL: goto x86_l_18b4;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6338ULL: goto x86_l_18c2;
	case 6340ULL: goto x86_l_18c4;
	case 6345ULL: goto x86_l_18c9;
	case 6352ULL: goto x86_l_18d0;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6366ULL: goto x86_l_18de;
	case 6371ULL: goto x86_l_18e3;
	case 6375ULL: goto x86_l_18e7;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6421ULL: goto x86_l_1915;
	case 6426ULL: goto x86_l_191a;
	case 6431ULL: goto x86_l_191f;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6454ULL: goto x86_l_1936;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6467ULL: goto x86_l_1943;
	case 6470ULL: goto x86_l_1946;
	case 6475ULL: goto x86_l_194b;
	case 6485ULL: goto x86_l_1955;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6497ULL: goto x86_l_1961;
	case 6500ULL: goto x86_l_1964;
	case 6510ULL: goto x86_l_196e;
	case 6513ULL: goto x86_l_1971;
	case 6518ULL: goto x86_l_1976;
	case 6522ULL: goto x86_l_197a;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6532ULL: goto x86_l_1984;
	case 6536ULL: goto x86_l_1988;
	case 6542ULL: goto x86_l_198e;
	case 6545ULL: goto x86_l_1991;
	case 6555ULL: goto x86_l_199b;
	case 6559ULL: goto x86_l_199f;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6591ULL: goto x86_l_19bf;
	case 6597ULL: goto x86_l_19c5;
	case 6603ULL: goto x86_l_19cb;
	case 6607ULL: goto x86_l_19cf;
	case 6609ULL: goto x86_l_19d1;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6618ULL: goto x86_l_19da;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6652ULL: goto x86_l_19fc;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6685ULL: goto x86_l_1a1d;
	case 6689ULL: goto x86_l_1a21;
	case 6691ULL: goto x86_l_1a23;
	case 6693ULL: goto x86_l_1a25;
	case 6699ULL: goto x86_l_1a2b;
	case 6708ULL: goto x86_l_1a34;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6736ULL: goto x86_l_1a50;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6767ULL: goto x86_l_1a6f;
	case 6770ULL: goto x86_l_1a72;
	case 6775ULL: goto x86_l_1a77;
	case 6779ULL: goto x86_l_1a7b;
	case 6782ULL: goto x86_l_1a7e;
	case 6792ULL: goto x86_l_1a88;
	case 6795ULL: goto x86_l_1a8b;
	case 6800ULL: goto x86_l_1a90;
	case 6804ULL: goto x86_l_1a94;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6828ULL: goto x86_l_1aac;
	case 6830ULL: goto x86_l_1aae;
	case 6840ULL: goto x86_l_1ab8;
	case 6844ULL: goto x86_l_1abc;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6873ULL: goto x86_l_1ad9;
	case 6875ULL: goto x86_l_1adb;
	case 6881ULL: goto x86_l_1ae1;
	case 6887ULL: goto x86_l_1ae7;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6900ULL: goto x86_l_1af4;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6934ULL: goto x86_l_1b16;
	case 6938ULL: goto x86_l_1b1a;
	case 6940ULL: goto x86_l_1b1c;
	case 6945ULL: goto x86_l_1b21;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6998ULL: goto x86_l_1b56;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7029ULL: goto x86_l_1b75;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7041ULL: goto x86_l_1b81;
	case 7044ULL: goto x86_l_1b84;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7066ULL: goto x86_l_1b9a;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7078ULL: goto x86_l_1ba6;
	case 7080ULL: goto x86_l_1ba8;
	case 7084ULL: goto x86_l_1bac;
	case 7090ULL: goto x86_l_1bb2;
	case 7093ULL: goto x86_l_1bb5;
	case 7103ULL: goto x86_l_1bbf;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_150d:
	/* 0x150d: jmp    1532 <tail_nodeport_nat_ingress_ipv6+0x1532> */
	goto x86_l_1532;
x86_l_150f:
	/* 0x150f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1514:
	/* 0x1514: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1516:
	/* 0x1516: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1518:
	/* 0x1518: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_151c:
	/* 0x151c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1526:
	/* 0x1526: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_152e:
	/* 0x152e: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1532:
	/* 0x1532: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1534:
	/* 0x1534: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1539:
	/* 0x1539: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_153f:
	/* 0x153f: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1544:
	/* 0x1544: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1547:
	/* 0x1547: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_154b:
	/* 0x154b: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154e:
	/* 0x154e: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1552:
	/* 0x1552: je     1565 <tail_nodeport_nat_ingress_ipv6+0x1565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1565;
	}
x86_l_1554:
	/* 0x1554: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_155b:
	/* 0x155b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_155d:
	/* 0x155d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1560:
	/* 0x1560: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1563:
	/* 0x1563: jmp    156a <tail_nodeport_nat_ingress_ipv6+0x156a> */
	goto x86_l_156a;
x86_l_1565:
	/* 0x1565: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_156a:
	/* 0x156a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_156c:
	/* 0x156c: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156f:
	/* 0x156f: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1571:
	/* 0x1571: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1574:
	/* 0x1574: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1576:
	/* 0x1576: jb     157d <tail_nodeport_nat_ingress_ipv6+0x157d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_157d;
	}
x86_l_1578:
	/* 0x1578: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_157b:
	/* 0x157b: je     1593 <tail_nodeport_nat_ingress_ipv6+0x1593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1593;
	}
x86_l_157d:
	/* 0x157d: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1580:
	/* 0x1580: mov    BYTE PTR [r12+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1585:
	/* 0x1585: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_158a:
	/* 0x158a: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1591:
	/* 0x1591: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1593:
	/* 0x1593: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1598:
	/* 0x1598: movzx  ebp,WORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_159d:
	/* 0x159d: movzx  r14d,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_15a6:
	/* 0x15a6: movzx  ecx,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_15ae:
	/* 0x15ae: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15b3:
	/* 0x15b3: cmp    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_15b7:
	/* 0x15b7: jne    15d3 <tail_nodeport_nat_ingress_ipv6+0x15d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15d3;
	}
x86_l_15b9:
	/* 0x15b9: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_15bc:
	/* 0x15bc: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_15c0:
	/* 0x15c0: jne    15da <tail_nodeport_nat_ingress_ipv6+0x15da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15da;
	}
x86_l_15c2:
	/* 0x15c2: mov    rax,QWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15c6:
	/* 0x15c6: cmp    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15cb:
	/* 0x15cb: je     1771 <tail_nodeport_nat_ingress_ipv6+0x1771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1771;
	}
x86_l_15d1:
	/* 0x15d1: jmp    15da <tail_nodeport_nat_ingress_ipv6+0x15da> */
	goto x86_l_15da;
x86_l_15d3:
	/* 0x15d3: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_15d6:
	/* 0x15d6: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_15da:
	/* 0x15da: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_15e1:
	/* 0x15e1: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15e6:
	/* 0x15e6: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_15ea:
	/* 0x15ea: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15ef:
	/* 0x15ef: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_15f4:
	/* 0x15f4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_15f9:
	/* 0x15f9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15fc:
	/* 0x15fc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1601:
	/* 0x1601: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1604:
	/* 0x1604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1606:
	/* 0x1606: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1609:
	/* 0x1609: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_160e:
	/* 0x160e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1611:
	/* 0x1611: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1616:
	/* 0x1616: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1619:
	/* 0x1619: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_161e:
	/* 0x161e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_162d:
	/* 0x162d: test   r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1630:
	/* 0x1630: jne    165a <tail_nodeport_nat_ingress_ipv6+0x165a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_165a;
	}
x86_l_1632:
	/* 0x1632: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1634:
	/* 0x1634: js     165a <tail_nodeport_nat_ingress_ipv6+0x165a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_165a;
	}
x86_l_1636:
	/* 0x1636: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_163a:
	/* 0x163a: je     167f <tail_nodeport_nat_ingress_ipv6+0x167f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_167f;
	}
x86_l_163c:
	/* 0x163c: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_1640:
	/* 0x1640: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1645:
	/* 0x1645: je     166f <tail_nodeport_nat_ingress_ipv6+0x166f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_1647:
	/* 0x1647: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_164b:
	/* 0x164b: jne    1691 <tail_nodeport_nat_ingress_ipv6+0x1691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1691;
	}
x86_l_164d:
	/* 0x164d: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1653:
	/* 0x1653: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1656:
	/* 0x1656: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1658:
	/* 0x1658: jmp    169a <tail_nodeport_nat_ingress_ipv6+0x169a> */
	goto x86_l_169a;
x86_l_165a:
	/* 0x165a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_165c:
	/* 0x165c: jns    1771 <tail_nodeport_nat_ingress_ipv6+0x1771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1771;
	}
x86_l_1662:
	/* 0x1662: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1665:
	/* 0x1665: and    eax,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_166a:
	/* 0x166a: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	return 3895ULL;
x86_l_166f:
	/* 0x166f: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_1675:
	/* 0x1675: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_167b:
	/* 0x167b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_167d:
	/* 0x167d: jmp    169a <tail_nodeport_nat_ingress_ipv6+0x169a> */
	goto x86_l_169a;
x86_l_167f:
	/* 0x167f: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1685:
	/* 0x1685: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1688:
	/* 0x1688: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168a:
	/* 0x168a: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_168f:
	/* 0x168f: jmp    169a <tail_nodeport_nat_ingress_ipv6+0x169a> */
	goto x86_l_169a;
x86_l_1691:
	/* 0x1691: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_1694:
	/* 0x1694: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1697:
	/* 0x1697: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_169a:
	/* 0x169a: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_169d:
	/* 0x169d: jne    174b <tail_nodeport_nat_ingress_ipv6+0x174b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174b;
	}
x86_l_16a3:
	/* 0x16a3: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_16a8:
	/* 0x16a8: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_16ac:
	/* 0x16ac: ja     f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3895ULL;
	}
x86_l_16b2:
	/* 0x16b2: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_16b5:
	/* 0x16b5: movabs rdx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_16bf:
	/* 0x16bf: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_16c3:
	/* 0x16c3: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16c8:
	/* 0x16c8: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16cc:
	/* 0x16cc: jae    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4318ULL;
	}
x86_l_16d2:
	/* 0x16d2: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_16d5:
	/* 0x16d5: mov    DWORD PTR [rsp+0xe0],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_16dd:
	/* 0x16dd: mov    WORD PTR [rsp+0x98],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16e5:
	/* 0x16e5: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16e8:
	/* 0x16e8: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16f0:
	/* 0x16f0: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_16f5:
	/* 0x16f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16f8:
	/* 0x16f8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_16fd:
	/* 0x16fd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1700:
	/* 0x1700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1702:
	/* 0x1702: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1704:
	/* 0x1704: js     18f2 <tail_nodeport_nat_ingress_ipv6+0x18f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18f2;
	}
x86_l_170a:
	/* 0x170a: movzx  ecx,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1712:
	/* 0x1712: lea    esi,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1716:
	/* 0x1716: mov    r8d,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_171e:
	/* 0x171e: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1722:
	/* 0x1722: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1727:
	/* 0x1727: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_172a:
	/* 0x172a: mov    edx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1731:
	/* 0x1731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1733:
	/* 0x1733: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1735:
	/* 0x1735: js     19f2 <tail_nodeport_nat_ingress_ipv6+0x19f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19f2;
	}
x86_l_173b:
	/* 0x173b: mov    r13,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1740:
	/* 0x1740: mov    r8d,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1748:
	/* 0x1748: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_174e:
	/* 0x174e: jne    1771 <tail_nodeport_nat_ingress_ipv6+0x1771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1771;
	}
x86_l_1750:
	/* 0x1750: add    r15d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1753:
	/* 0x1753: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1757:
	/* 0x1757: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_175c:
	/* 0x175c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_175f:
	/* 0x175f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1762:
	/* 0x1762: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1764:
	/* 0x1764: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1767:
	/* 0x1767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1769:
	/* 0x1769: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_176b:
	/* 0x176b: js     18fc <tail_nodeport_nat_ingress_ipv6+0x18fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18fc;
	}
x86_l_1771:
	/* 0x1771: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_1776:
	/* 0x1776: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1779:
	/* 0x1779: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_177e:
	/* 0x177e: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1781:
	/* 0x1781: mov    rbp,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1788:
	/* 0x1788: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_178c:
	/* 0x178c: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1798:
	/* 0x1798: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_17a3:
	/* 0x17a3: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_17af:
	/* 0x17af: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_17c7:
	/* 0x17c7: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_17d3:
	/* 0x17d3: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_17df:
	/* 0x17df: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_17eb:
	/* 0x17eb: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_17f7:
	/* 0x17f7: mov    BYTE PTR [rsp+0x98],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 652835029002ULL);
x86_l_17ff:
	/* 0x17ff: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1802:
	/* 0x1802: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1809:
	/* 0x1809: mov    QWORD PTR [rsp+0x7e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1812:
	/* 0x1812: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_181b:
	/* 0x181b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1824:
	/* 0x1824: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_182d:
	/* 0x182d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1836:
	/* 0x1836: mov    r15d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_183a:
	/* 0x183a: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_183d:
	/* 0x183d: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1841:
	/* 0x1841: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1844:
	/* 0x1844: ja     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8557ULL;
	}
x86_l_184a:
	/* 0x184a: movzx  r14d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_184f:
	/* 0x184f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1852:
	/* 0x1852: mov    BYTE PTR [rsp+0x84],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_185a:
	/* 0x185a: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_185f:
	/* 0x185f: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_1863:
	/* 0x1863: ja     1c64 <tail_nodeport_nat_ingress_ipv6+0x1c64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7268ULL;
	}
x86_l_1869:
	/* 0x1869: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_186e:
	/* 0x186e: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1878:
	/* 0x1878: bt     rcx,r14 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_187c:
	/* 0x187c: jae    18e3 <tail_nodeport_nat_ingress_ipv6+0x18e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18e3;
	}
x86_l_187e:
	/* 0x187e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1883:
	/* 0x1883: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1888:
	/* 0x1888: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_188b:
	/* 0x188b: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_1890:
	/* 0x1890: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1895:
	/* 0x1895: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1897:
	/* 0x1897: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1899:
	/* 0x1899: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_189f:
	/* 0x189f: movzx  ebp,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_18a4:
	/* 0x18a4: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_18a8:
	/* 0x18a8: jle    18c4 <tail_nodeport_nat_ingress_ipv6+0x18c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_18c4;
	}
x86_l_18aa:
	/* 0x18aa: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_18ae:
	/* 0x18ae: je     18c4 <tail_nodeport_nat_ingress_ipv6+0x18c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c4;
	}
x86_l_18b0:
	/* 0x18b0: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_18b4:
	/* 0x18b4: jne    1906 <tail_nodeport_nat_ingress_ipv6+0x1906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1906;
	}
x86_l_18b6:
	/* 0x18b6: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_18bb:
	/* 0x18bb: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_18c2:
	/* 0x18c2: jmp    18db <tail_nodeport_nat_ingress_ipv6+0x18db> */
	goto x86_l_18db;
x86_l_18c4:
	/* 0x18c4: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_18c9:
	/* 0x18c9: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_18d0:
	/* 0x18d0: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_18d4:
	/* 0x18d4: jne    18db <tail_nodeport_nat_ingress_ipv6+0x18db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18db;
	}
x86_l_18d6:
	/* 0x18d6: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_18d9:
	/* 0x18d9: jmp    190c <tail_nodeport_nat_ingress_ipv6+0x190c> */
	goto x86_l_190c;
x86_l_18db:
	/* 0x18db: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18de:
	/* 0x18de: jmp    197d <tail_nodeport_nat_ingress_ipv6+0x197d> */
	goto x86_l_197d;
x86_l_18e3:
	/* 0x18e3: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_18e7:
	/* 0x18e7: je     2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8562ULL;
	}
x86_l_18ed:
	/* 0x18ed: jmp    1c64 <tail_nodeport_nat_ingress_ipv6+0x1c64> */
	return 7268ULL;
x86_l_18f2:
	/* 0x18f2: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_18f7:
	/* 0x18f7: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	return 4318ULL;
x86_l_18fc:
	/* 0x18fc: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_1901:
	/* 0x1901: jmp    f37 <tail_nodeport_nat_ingress_ipv6+0xf37> */
	return 3895ULL;
x86_l_1906:
	/* 0x1906: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_190c:
	/* 0x190c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1915:
	/* 0x1915: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_191a:
	/* 0x191a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_191f:
	/* 0x191f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1922:
	/* 0x1922: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_1927:
	/* 0x1927: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_192c:
	/* 0x192c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192e:
	/* 0x192e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1930:
	/* 0x1930: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_1936:
	/* 0x1936: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_193a:
	/* 0x193a: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_193f:
	/* 0x193f: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1943:
	/* 0x1943: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1946:
	/* 0x1946: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_194b:
	/* 0x194b: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1955:
	/* 0x1955: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1958:
	/* 0x1958: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_195d:
	/* 0x195d: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1961:
	/* 0x1961: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_1964:
	/* 0x1964: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_196e:
	/* 0x196e: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1971:
	/* 0x1971: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_1976:
	/* 0x1976: cmove  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_197a:
	/* 0x197a: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_197d:
	/* 0x197d: movzx  r13d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1981:
	/* 0x1981: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1984:
	/* 0x1984: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1988:
	/* 0x1988: ja     1b21 <tail_nodeport_nat_ingress_ipv6+0x1b21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b21;
	}
x86_l_198e:
	/* 0x198e: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1991:
	/* 0x1991: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_199b:
	/* 0x199b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: jae    19fc <tail_nodeport_nat_ingress_ipv6+0x19fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19fc;
	}
x86_l_19a1:
	/* 0x19a1: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19a6:
	/* 0x19a6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ab:
	/* 0x19ab: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_19b0:
	/* 0x19b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19b3:
	/* 0x19b3: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_19b6:
	/* 0x19b6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19bb:
	/* 0x19bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bd:
	/* 0x19bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19bf:
	/* 0x19bf: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_19c5:
	/* 0x19c5: movzx  r14d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_19cb:
	/* 0x19cb: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_19cf:
	/* 0x19cf: jle    1a0d <tail_nodeport_nat_ingress_ipv6+0x1a0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a0d;
	}
x86_l_19d1:
	/* 0x19d1: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_19d5:
	/* 0x19d5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_19d8:
	/* 0x19d8: je     1a25 <tail_nodeport_nat_ingress_ipv6+0x1a25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a25;
	}
x86_l_19da:
	/* 0x19da: cmp    r13d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 51ULL);
x86_l_19de:
	/* 0x19de: jne    1a10 <tail_nodeport_nat_ingress_ipv6+0x1a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a10;
	}
x86_l_19e0:
	/* 0x19e0: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_19e5:
	/* 0x19e5: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_19ed:
	/* 0x19ed: jmp    1a9c <tail_nodeport_nat_ingress_ipv6+0x1a9c> */
	goto x86_l_1a9c;
x86_l_19f2:
	/* 0x19f2: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_19f7:
	/* 0x19f7: jmp    10de <tail_nodeport_nat_ingress_ipv6+0x10de> */
	return 4318ULL;
x86_l_19fc:
	/* 0x19fc: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_19ff:
	/* 0x19ff: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1a03:
	/* 0x1a03: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1a08:
	/* 0x1a08: jmp    1c46 <tail_nodeport_nat_ingress_ipv6+0x1c46> */
	return 7238ULL;
x86_l_1a0d:
	/* 0x1a0d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_1a15:
	/* 0x1a15: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1a1d:
	/* 0x1a1d: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_1a21:
	/* 0x1a21: je     1a2b <tail_nodeport_nat_ingress_ipv6+0x1a2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a2b;
	}
x86_l_1a23:
	/* 0x1a23: jmp    1a9c <tail_nodeport_nat_ingress_ipv6+0x1a9c> */
	goto x86_l_1a9c;
x86_l_1a25:
	/* 0x1a25: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a34:
	/* 0x1a34: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a39:
	/* 0x1a39: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a41:
	/* 0x1a41: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a46:
	/* 0x1a46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a48:
	/* 0x1a48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a4a:
	/* 0x1a4a: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_1a50:
	/* 0x1a50: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a54:
	/* 0x1a54: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1a59:
	/* 0x1a59: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1a5d:
	/* 0x1a5d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a60:
	/* 0x1a60: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1a65:
	/* 0x1a65: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1a6f:
	/* 0x1a6f: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a72:
	/* 0x1a72: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_1a77:
	/* 0x1a77: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1a7b:
	/* 0x1a7b: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a7e:
	/* 0x1a7e: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_1a88:
	/* 0x1a88: or     rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a8b:
	/* 0x1a8b: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_1a90:
	/* 0x1a90: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1a94:
	/* 0x1a94: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a99:
	/* 0x1a99: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1a9c:
	/* 0x1a9c: movzx  ebp,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1aa0:
	/* 0x1aa0: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1aa3:
	/* 0x1aa3: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1aa6:
	/* 0x1aa6: ja     1c58 <tail_nodeport_nat_ingress_ipv6+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7256ULL;
	}
x86_l_1aac:
	/* 0x1aac: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1aae:
	/* 0x1aae: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1ab8:
	/* 0x1ab8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1abc:
	/* 0x1abc: jae    1c38 <tail_nodeport_nat_ingress_ipv6+0x1c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7224ULL;
	}
x86_l_1ac2:
	/* 0x1ac2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1acc:
	/* 0x1acc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1acf:
	/* 0x1acf: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_1ad2:
	/* 0x1ad2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ad7:
	/* 0x1ad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad9:
	/* 0x1ad9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1adb:
	/* 0x1adb: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_1ae1:
	/* 0x1ae1: movzx  r12d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1ae7:
	/* 0x1ae7: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1aea:
	/* 0x1aea: jle    1b07 <tail_nodeport_nat_ingress_ipv6+0x1b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b07;
	}
x86_l_1aec:
	/* 0x1aec: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1aef:
	/* 0x1aef: je     1b29 <tail_nodeport_nat_ingress_ipv6+0x1b29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b29;
	}
x86_l_1af1:
	/* 0x1af1: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1af4:
	/* 0x1af4: jne    1b07 <tail_nodeport_nat_ingress_ipv6+0x1b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b07;
	}
x86_l_1af6:
	/* 0x1af6: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_1afb:
	/* 0x1afb: lea    ebp,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1b02:
	/* 0x1b02: jmp    1b9f <tail_nodeport_nat_ingress_ipv6+0x1b9f> */
	goto x86_l_1b9f;
x86_l_1b07:
	/* 0x1b07: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1b0a:
	/* 0x1b0a: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_1b0f:
	/* 0x1b0f: lea    ebp,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1b16:
	/* 0x1b16: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_1b1a:
	/* 0x1b1a: je     1b31 <tail_nodeport_nat_ingress_ipv6+0x1b31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b31;
	}
x86_l_1b1c:
	/* 0x1b1c: jmp    1ba2 <tail_nodeport_nat_ingress_ipv6+0x1ba2> */
	goto x86_l_1ba2;
x86_l_1b21:
	/* 0x1b21: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_1b24:
	/* 0x1b24: jmp    1c5d <tail_nodeport_nat_ingress_ipv6+0x1c5d> */
	return 7261ULL;
x86_l_1b29:
	/* 0x1b29: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1b31:
	/* 0x1b31: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b3a:
	/* 0x1b3a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3f:
	/* 0x1b3f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1b44:
	/* 0x1b44: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b47:
	/* 0x1b47: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b4c:
	/* 0x1b4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4e:
	/* 0x1b4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b50:
	/* 0x1b50: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8557ULL;
	}
x86_l_1b56:
	/* 0x1b56: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b5a:
	/* 0x1b5a: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1b5f:
	/* 0x1b5f: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1b63:
	/* 0x1b63: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b66:
	/* 0x1b66: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1b6b:
	/* 0x1b6b: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1b75:
	/* 0x1b75: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b78:
	/* 0x1b78: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_1b7d:
	/* 0x1b7d: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1b81:
	/* 0x1b81: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b84:
	/* 0x1b84: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b8e:
	/* 0x1b8e: or     rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b91:
	/* 0x1b91: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_1b96:
	/* 0x1b96: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1b9a:
	/* 0x1b9a: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: movzx  r14d,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ba6:
	/* 0x1ba6: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ba8:
	/* 0x1ba8: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1bac:
	/* 0x1bac: ja     1c55 <tail_nodeport_nat_ingress_ipv6+0x1c55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7253ULL;
	}
x86_l_1bb2:
	/* 0x1bb2: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1bb5:
	/* 0x1bb5: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1bbf:
	/* 0x1bbf: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1bc3:
	/* 0x1bc3: jae    1c35 <tail_nodeport_nat_ingress_ipv6+0x1c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7221ULL;
	}
x86_l_1bc5:
	/* 0x1bc5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bca:
	/* 0x1bca: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1bcf:
	/* 0x1bcf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
	return 7122ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7122ULL: goto x86_l_1bd2;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7132ULL: goto x86_l_1bdc;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7147ULL: goto x86_l_1beb;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7157ULL: goto x86_l_1bf5;
	case 7159ULL: goto x86_l_1bf7;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7169ULL: goto x86_l_1c01;
	case 7171ULL: goto x86_l_1c03;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7203ULL: goto x86_l_1c23;
	case 7205ULL: goto x86_l_1c25;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7224ULL: goto x86_l_1c38;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7245ULL: goto x86_l_1c4d;
	case 7251ULL: goto x86_l_1c53;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7268ULL: goto x86_l_1c64;
	case 7276ULL: goto x86_l_1c6c;
	case 7280ULL: goto x86_l_1c70;
	case 7285ULL: goto x86_l_1c75;
	case 7289ULL: goto x86_l_1c79;
	case 7294ULL: goto x86_l_1c7e;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7316ULL: goto x86_l_1c94;
	case 7318ULL: goto x86_l_1c96;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7331ULL: goto x86_l_1ca3;
	case 7341ULL: goto x86_l_1cad;
	case 7349ULL: goto x86_l_1cb5;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7363ULL: goto x86_l_1cc3;
	case 7366ULL: goto x86_l_1cc6;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7387ULL: goto x86_l_1cdb;
	case 7397ULL: goto x86_l_1ce5;
	case 7400ULL: goto x86_l_1ce8;
	case 7406ULL: goto x86_l_1cee;
	case 7411ULL: goto x86_l_1cf3;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7423ULL: goto x86_l_1cff;
	case 7429ULL: goto x86_l_1d05;
	case 7432ULL: goto x86_l_1d08;
	case 7438ULL: goto x86_l_1d0e;
	case 7441ULL: goto x86_l_1d11;
	case 7443ULL: goto x86_l_1d13;
	case 7446ULL: goto x86_l_1d16;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7480ULL: goto x86_l_1d38;
	case 7482ULL: goto x86_l_1d3a;
	case 7488ULL: goto x86_l_1d40;
	case 7497ULL: goto x86_l_1d49;
	case 7501ULL: goto x86_l_1d4d;
	case 7503ULL: goto x86_l_1d4f;
	case 7510ULL: goto x86_l_1d56;
	case 7512ULL: goto x86_l_1d58;
	case 7519ULL: goto x86_l_1d5f;
	case 7524ULL: goto x86_l_1d64;
	case 7532ULL: goto x86_l_1d6c;
	case 7540ULL: goto x86_l_1d74;
	case 7544ULL: goto x86_l_1d78;
	case 7550ULL: goto x86_l_1d7e;
	case 7553ULL: goto x86_l_1d81;
	case 7559ULL: goto x86_l_1d87;
	case 7562ULL: goto x86_l_1d8a;
	case 7571ULL: goto x86_l_1d93;
	case 7580ULL: goto x86_l_1d9c;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7602ULL: goto x86_l_1db2;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7617ULL: goto x86_l_1dc1;
	case 7619ULL: goto x86_l_1dc3;
	case 7622ULL: goto x86_l_1dc6;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7636ULL: goto x86_l_1dd4;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7651ULL: goto x86_l_1de3;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7696ULL: goto x86_l_1e10;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7718ULL: goto x86_l_1e26;
	case 7720ULL: goto x86_l_1e28;
	case 7723ULL: goto x86_l_1e2b;
	case 7728ULL: goto x86_l_1e30;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7745ULL: goto x86_l_1e41;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7757ULL: goto x86_l_1e4d;
	case 7762ULL: goto x86_l_1e52;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7782ULL: goto x86_l_1e66;
	case 7788ULL: goto x86_l_1e6c;
	case 7791ULL: goto x86_l_1e6f;
	case 7793ULL: goto x86_l_1e71;
	case 7796ULL: goto x86_l_1e74;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7813ULL: goto x86_l_1e85;
	case 7816ULL: goto x86_l_1e88;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7827ULL: goto x86_l_1e93;
	case 7830ULL: goto x86_l_1e96;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7842ULL: goto x86_l_1ea2;
	case 7848ULL: goto x86_l_1ea8;
	case 7854ULL: goto x86_l_1eae;
	case 7859ULL: goto x86_l_1eb3;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7866ULL: goto x86_l_1eba;
	case 7872ULL: goto x86_l_1ec0;
	case 7879ULL: goto x86_l_1ec7;
	case 7882ULL: goto x86_l_1eca;
	case 7884ULL: goto x86_l_1ecc;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7908ULL: goto x86_l_1ee4;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7921ULL: goto x86_l_1ef1;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7940ULL: goto x86_l_1f04;
	case 7943ULL: goto x86_l_1f07;
	case 7950ULL: goto x86_l_1f0e;
	case 7953ULL: goto x86_l_1f11;
	case 7955ULL: goto x86_l_1f13;
	case 7962ULL: goto x86_l_1f1a;
	case 7965ULL: goto x86_l_1f1d;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7976ULL: goto x86_l_1f28;
	case 7983ULL: goto x86_l_1f2f;
	case 7986ULL: goto x86_l_1f32;
	case 7988ULL: goto x86_l_1f34;
	case 7993ULL: goto x86_l_1f39;
	case 7995ULL: goto x86_l_1f3b;
	case 7997ULL: goto x86_l_1f3d;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8016ULL: goto x86_l_1f50;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8034ULL: goto x86_l_1f62;
	case 8038ULL: goto x86_l_1f66;
	case 8040ULL: goto x86_l_1f68;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8053ULL: goto x86_l_1f75;
	case 8057ULL: goto x86_l_1f79;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8076ULL: goto x86_l_1f8c;
	case 8078ULL: goto x86_l_1f8e;
	case 8081ULL: goto x86_l_1f91;
	case 8084ULL: goto x86_l_1f94;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8093ULL: goto x86_l_1f9d;
	case 8096ULL: goto x86_l_1fa0;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8109ULL: goto x86_l_1fad;
	case 8113ULL: goto x86_l_1fb1;
	case 8120ULL: goto x86_l_1fb8;
	case 8122ULL: goto x86_l_1fba;
	case 8129ULL: goto x86_l_1fc1;
	case 8132ULL: goto x86_l_1fc4;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8175ULL: goto x86_l_1fef;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8209ULL: goto x86_l_2011;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8233ULL: goto x86_l_2029;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8243ULL: goto x86_l_2033;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8275ULL: goto x86_l_2053;
	case 8279ULL: goto x86_l_2057;
	case 8281ULL: goto x86_l_2059;
	case 8288ULL: goto x86_l_2060;
	case 8290ULL: goto x86_l_2062;
	case 8292ULL: goto x86_l_2064;
	case 8295ULL: goto x86_l_2067;
	case 8298ULL: goto x86_l_206a;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8309ULL: goto x86_l_2075;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8353ULL: goto x86_l_20a1;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8371ULL: goto x86_l_20b3;
	case 8376ULL: goto x86_l_20b8;
	case 8380ULL: goto x86_l_20bc;
	case 8383ULL: goto x86_l_20bf;
	case 8387ULL: goto x86_l_20c3;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8403ULL: goto x86_l_20d3;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8413ULL: goto x86_l_20dd;
	case 8418ULL: goto x86_l_20e2;
	case 8420ULL: goto x86_l_20e4;
	case 8423ULL: goto x86_l_20e7;
	case 8425ULL: goto x86_l_20e9;
	case 8428ULL: goto x86_l_20ec;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8444ULL: goto x86_l_20fc;
	case 8448ULL: goto x86_l_2100;
	case 8455ULL: goto x86_l_2107;
	case 8457ULL: goto x86_l_2109;
	case 8465ULL: goto x86_l_2111;
	case 8471ULL: goto x86_l_2117;
	case 8476ULL: goto x86_l_211c;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8591ULL: goto x86_l_218f;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8610ULL: goto x86_l_21a2;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8632ULL: goto x86_l_21b8;
	case 8636ULL: goto x86_l_21bc;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8655ULL: goto x86_l_21cf;
	case 8658ULL: goto x86_l_21d2;
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8676ULL: goto x86_l_21e4;
	case 8681ULL: goto x86_l_21e9;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8703ULL: goto x86_l_21ff;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1bd2:
	/* 0x1bd2: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1bd5:
	/* 0x1bd5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bda:
	/* 0x1bda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bdc:
	/* 0x1bdc: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1bde:
	/* 0x1bde: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1be3:
	/* 0x1be3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1be5:
	/* 0x1be5: js     2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2172;
	}
x86_l_1beb:
	/* 0x1beb: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_1bef:
	/* 0x1bef: jle    1bfd <tail_nodeport_nat_ingress_ipv6+0x1bfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bfd;
	}
x86_l_1bf1:
	/* 0x1bf1: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_1bf5:
	/* 0x1bf5: je     1c03 <tail_nodeport_nat_ingress_ipv6+0x1c03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c03;
	}
x86_l_1bf7:
	/* 0x1bf7: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_1bfb:
	/* 0x1bfb: je     1c2b <tail_nodeport_nat_ingress_ipv6+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c2b;
	}
x86_l_1bfd:
	/* 0x1bfd: cmp    r12b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 44ULL);
x86_l_1c01:
	/* 0x1c01: jne    1c2b <tail_nodeport_nat_ingress_ipv6+0x1c2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c2b;
	}
x86_l_1c03:
	/* 0x1c03: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c0c:
	/* 0x1c0c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c11:
	/* 0x1c11: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1c16:
	/* 0x1c16: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c19:
	/* 0x1c19: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1c1c:
	/* 0x1c1c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c21:
	/* 0x1c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c23:
	/* 0x1c23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c25:
	/* 0x1c25: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_216d;
	}
x86_l_1c2b:
	/* 0x1c2b: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1c30:
	/* 0x1c30: jmp    2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	goto x86_l_2172;
x86_l_1c35:
	/* 0x1c35: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_1c38:
	/* 0x1c38: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1c41:
	/* 0x1c41: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c46:
	/* 0x1c46: mov    rbp,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1c4d:
	/* 0x1c4d: je     2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2172;
	}
x86_l_1c53:
	/* 0x1c53: jmp    1c64 <tail_nodeport_nat_ingress_ipv6+0x1c64> */
	goto x86_l_1c64;
x86_l_1c55:
	/* 0x1c55: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_1c58:
	/* 0x1c58: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    rbp,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1c64:
	/* 0x1c64: mov    BYTE PTR [rsp+0x84],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c70:
	/* 0x1c70: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1c75:
	/* 0x1c75: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c79:
	/* 0x1c79: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c82:
	/* 0x1c82: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c87:
	/* 0x1c87: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c90:
	/* 0x1c90: cmp    r14b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 17ULL);
x86_l_1c94:
	/* 0x1c94: je     1ca3 <tail_nodeport_nat_ingress_ipv6+0x1ca3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca3;
	}
x86_l_1c96:
	/* 0x1c96: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c9a:
	/* 0x1c9a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1c9d:
	/* 0x1c9d: jne    2915 <tail_nodeport_nat_ingress_ipv6+0x2915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10517ULL;
	}
x86_l_1ca3:
	/* 0x1ca3: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_1cad:
	/* 0x1cad: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cb5:
	/* 0x1cb5: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_1cbc:
	/* 0x1cbc: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1cc1:
	/* 0x1cc1: je     1d13 <tail_nodeport_nat_ingress_ipv6+0x1d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d13;
	}
x86_l_1cc3:
	/* 0x1cc3: mov    r13,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccd:
	/* 0x1ccd: mov    DWORD PTR [r15],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd0:
	/* 0x1cd0: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1cd3:
	/* 0x1cd3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    BYTE PTR [r15+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cdb:
	/* 0x1cdb: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1ce5:
	/* 0x1ce5: test   r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1ce8:
	/* 0x1ce8: jne    25fe <tail_nodeport_nat_ingress_ipv6+0x25fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9726ULL;
	}
x86_l_1cee:
	/* 0x1cee: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1cf6:
	/* 0x1cf6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cfb:
	/* 0x1cfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfd:
	/* 0x1cfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cff:
	/* 0x1cff: js     1dcc <tail_nodeport_nat_ingress_ipv6+0x1dcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dcc;
	}
x86_l_1d05:
	/* 0x1d05: test   r12,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R14, X86_WIDTH_64);
x86_l_1d08:
	/* 0x1d08: jne    2632 <tail_nodeport_nat_ingress_ipv6+0x2632> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9778ULL;
	}
x86_l_1d0e:
	/* 0x1d0e: mov    QWORD PTR [r15],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d11:
	/* 0x1d11: jmp    1d40 <tail_nodeport_nat_ingress_ipv6+0x1d40> */
	goto x86_l_1d40;
x86_l_1d13:
	/* 0x1d13: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d16:
	/* 0x1d16: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1d20:
	/* 0x1d20: test   r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: jne    26ad <tail_nodeport_nat_ingress_ipv6+0x26ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9901ULL;
	}
x86_l_1d29:
	/* 0x1d29: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d31:
	/* 0x1d31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d36:
	/* 0x1d36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d38:
	/* 0x1d38: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d3a:
	/* 0x1d3a: js     1dd9 <tail_nodeport_nat_ingress_ipv6+0x1dd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dd9;
	}
x86_l_1d40:
	/* 0x1d40: movzx  r13d,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_1d49:
	/* 0x1d49: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1d4d:
	/* 0x1d4d: jne    1d58 <tail_nodeport_nat_ingress_ipv6+0x1d58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d58;
	}
x86_l_1d4f:
	/* 0x1d4f: mov    r15,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1d56:
	/* 0x1d56: jmp    1d5f <tail_nodeport_nat_ingress_ipv6+0x1d5f> */
	goto x86_l_1d5f;
x86_l_1d58:
	/* 0x1d58: mov    r15,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1d5f:
	/* 0x1d5f: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d64:
	/* 0x1d64: mov    BYTE PTR [rsp+0x85],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650368ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d74:
	/* 0x1d74: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d78:
	/* 0x1d78: je     1e10 <tail_nodeport_nat_ingress_ipv6+0x1e10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e10;
	}
x86_l_1d7e:
	/* 0x1d7e: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d81:
	/* 0x1d81: je     1e10 <tail_nodeport_nat_ingress_ipv6+0x1e10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e10;
	}
x86_l_1d87:
	/* 0x1d87: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1d93:
	/* 0x1d93: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d9c:
	/* 0x1d9c: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_1da6:
	/* 0x1da6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1dab:
	/* 0x1dab: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1db2:
	/* 0x1db2: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1db7:
	/* 0x1db7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dbc:
	/* 0x1dbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbe:
	/* 0x1dbe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc1:
	/* 0x1dc1: je     1de3 <tail_nodeport_nat_ingress_ipv6+0x1de3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de3;
	}
x86_l_1dc3:
	/* 0x1dc3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1dc6:
	/* 0x1dc6: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1dca:
	/* 0x1dca: jmp    1e0b <tail_nodeport_nat_ingress_ipv6+0x1e0b> */
	goto x86_l_1e0b;
x86_l_1dcc:
	/* 0x1dcc: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_1dd1:
	/* 0x1dd1: mov    QWORD PTR [r15],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd4:
	/* 0x1dd4: jmp    2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	goto x86_l_2172;
x86_l_1dd9:
	/* 0x1dd9: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_1dde:
	/* 0x1dde: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	goto x86_l_2175;
x86_l_1de3:
	/* 0x1de3: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1dec:
	/* 0x1dec: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df1:
	/* 0x1df1: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1df8:
	/* 0x1df8: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1dfd:
	/* 0x1dfd: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e02:
	/* 0x1e02: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e07:
	/* 0x1e07: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e09:
	/* 0x1e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0b:
	/* 0x1e0b: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e10:
	/* 0x1e10: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1e1a:
	/* 0x1e1a: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e1d:
	/* 0x1e1d: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1e21:
	/* 0x1e21: jne    1e71 <tail_nodeport_nat_ingress_ipv6+0x1e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e71;
	}
x86_l_1e23:
	/* 0x1e23: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1e26:
	/* 0x1e26: jne    1e71 <tail_nodeport_nat_ingress_ipv6+0x1e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e71;
	}
x86_l_1e28:
	/* 0x1e28: lea    esi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e2b:
	/* 0x1e2b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e30:
	/* 0x1e30: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1e35:
	/* 0x1e35: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e38:
	/* 0x1e38: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e3d:
	/* 0x1e3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3f:
	/* 0x1e3f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e41:
	/* 0x1e41: js     2915 <tail_nodeport_nat_ingress_ipv6+0x2915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10517ULL;
	}
x86_l_1e47:
	/* 0x1e47: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4b:
	/* 0x1e4b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1e4d:
	/* 0x1e4d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1e52:
	/* 0x1e52: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e55:
	/* 0x1e55: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1e5a:
	/* 0x1e5a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1e5d:
	/* 0x1e5d: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e60:
	/* 0x1e60: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_1e66:
	/* 0x1e66: jne    27f3 <tail_nodeport_nat_ingress_ipv6+0x27f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10227ULL;
	}
x86_l_1e6c:
	/* 0x1e6c: mov    r14b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_8);
x86_l_1e6f:
	/* 0x1e6f: jmp    1e7b <tail_nodeport_nat_ingress_ipv6+0x1e7b> */
	goto x86_l_1e7b;
x86_l_1e71:
	/* 0x1e71: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e74:
	/* 0x1e74: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e78:
	/* 0x1e78: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e7b:
	/* 0x1e7b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e80:
	/* 0x1e80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e85:
	/* 0x1e85: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1e88:
	/* 0x1e88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8a:
	/* 0x1e8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e8d:
	/* 0x1e8d: je     290c <tail_nodeport_nat_ingress_ipv6+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10508ULL;
	}
x86_l_1e93:
	/* 0x1e93: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1e96:
	/* 0x1e96: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1e9a:
	/* 0x1e9a: test   al,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 32ULL);
x86_l_1e9c:
	/* 0x1e9c: je     290c <tail_nodeport_nat_ingress_ipv6+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10508ULL;
	}
x86_l_1ea2:
	/* 0x1ea2: cmp    WORD PTR [r15+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1ea8:
	/* 0x1ea8: je     290c <tail_nodeport_nat_ingress_ipv6+0x290c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10508ULL;
	}
x86_l_1eae:
	/* 0x1eae: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1eb3:
	/* 0x1eb3: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1eb5:
	/* 0x1eb5: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1eb7:
	/* 0x1eb7: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1eba:
	/* 0x1eba: je     1fba <tail_nodeport_nat_ingress_ipv6+0x1fba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fba;
	}
x86_l_1ec0:
	/* 0x1ec0: mov    rcx,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1ec7:
	/* 0x1ec7: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eca:
	/* 0x1eca: je     1edb <tail_nodeport_nat_ingress_ipv6+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1edb;
	}
x86_l_1ecc:
	/* 0x1ecc: mov    rcx,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1ed3:
	/* 0x1ed3: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1ed6:
	/* 0x1ed6: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ed9:
	/* 0x1ed9: jmp    1ee0 <tail_nodeport_nat_ingress_ipv6+0x1ee0> */
	goto x86_l_1ee0;
x86_l_1edb:
	/* 0x1edb: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1ee0:
	/* 0x1ee0: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1ee4:
	/* 0x1ee4: jne    1f20 <tail_nodeport_nat_ingress_ipv6+0x1f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f20;
	}
x86_l_1ee6:
	/* 0x1ee6: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee9:
	/* 0x1ee9: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1eeb:
	/* 0x1eeb: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1eee:
	/* 0x1eee: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1ef1:
	/* 0x1ef1: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ef3:
	/* 0x1ef3: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ef8:
	/* 0x1ef8: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_1efa:
	/* 0x1efa: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1eff:
	/* 0x1eff: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1f04:
	/* 0x1f04: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1f07:
	/* 0x1f07: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1f0e:
	/* 0x1f0e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f11:
	/* 0x1f11: je     1f20 <tail_nodeport_nat_ingress_ipv6+0x1f20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f20;
	}
x86_l_1f13:
	/* 0x1f13: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f1a:
	/* 0x1f1a: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1f1d:
	/* 0x1f1d: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f20:
	/* 0x1f20: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f24:
	/* 0x1f24: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f28:
	/* 0x1f28: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1f2f:
	/* 0x1f2f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f32:
	/* 0x1f32: je     1f43 <tail_nodeport_nat_ingress_ipv6+0x1f43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f43;
	}
x86_l_1f34:
	/* 0x1f34: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1f39:
	/* 0x1f39: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3b:
	/* 0x1f3b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f3d:
	/* 0x1f3d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1f41:
	/* 0x1f41: jmp    1f66 <tail_nodeport_nat_ingress_ipv6+0x1f66> */
	goto x86_l_1f66;
x86_l_1f43:
	/* 0x1f43: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1f48:
	/* 0x1f48: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f4a:
	/* 0x1f4a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f4c:
	/* 0x1f4c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1f50:
	/* 0x1f50: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1f5d:
	/* 0x1f5d: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1f62:
	/* 0x1f62: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1f66:
	/* 0x1f66: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f68:
	/* 0x1f68: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6c:
	/* 0x1f6c: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1f71:
	/* 0x1f71: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1f75:
	/* 0x1f75: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1f79:
	/* 0x1f79: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1f80:
	/* 0x1f80: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f83:
	/* 0x1f83: je     1f96 <tail_nodeport_nat_ingress_ipv6+0x1f96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f96;
	}
x86_l_1f85:
	/* 0x1f85: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f8c:
	/* 0x1f8c: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f8e:
	/* 0x1f8e: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1f91:
	/* 0x1f91: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f94:
	/* 0x1f94: jmp    1f9b <tail_nodeport_nat_ingress_ipv6+0x1f9b> */
	goto x86_l_1f9b;
x86_l_1f96:
	/* 0x1f96: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1f9b:
	/* 0x1f9b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f9d:
	/* 0x1f9d: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1fa0:
	/* 0x1fa0: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1fa2:
	/* 0x1fa2: jb     1fa9 <tail_nodeport_nat_ingress_ipv6+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1fa9;
	}
x86_l_1fa4:
	/* 0x1fa4: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_1fa7:
	/* 0x1fa7: je     1fba <tail_nodeport_nat_ingress_ipv6+0x1fba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fba;
	}
x86_l_1fa9:
	/* 0x1fa9: mov    BYTE PTR [r15+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1fad:
	/* 0x1fad: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1fb8:
	/* 0x1fb8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fba:
	/* 0x1fba: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1fc1:
	/* 0x1fc1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc4:
	/* 0x1fc4: je     1fd2 <tail_nodeport_nat_ingress_ipv6+0x1fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd2;
	}
x86_l_1fc6:
	/* 0x1fc6: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fcd:
	/* 0x1fcd: add QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1fd2:
	/* 0x1fd2: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1fd6:
	/* 0x1fd6: je     2023 <tail_nodeport_nat_ingress_ipv6+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2023;
	}
x86_l_1fd8:
	/* 0x1fd8: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1fdc:
	/* 0x1fdc: jne    2109 <tail_nodeport_nat_ingress_ipv6+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2109;
	}
x86_l_1fe2:
	/* 0x1fe2: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1fe7:
	/* 0x1fe7: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1fe9:
	/* 0x1fe9: je     2109 <tail_nodeport_nat_ingress_ipv6+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2109;
	}
x86_l_1fef:
	/* 0x1fef: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1ff6:
	/* 0x1ff6: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1ffb:
	/* 0x1ffb: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2000:
	/* 0x2000: mov    r14,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2007:
	/* 0x2007: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_200b:
	/* 0x200b: je     283e <tail_nodeport_nat_ingress_ipv6+0x283e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10302ULL;
	}
x86_l_2011:
	/* 0x2011: mov    rcx,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2018:
	/* 0x2018: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_201b:
	/* 0x201b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_201e:
	/* 0x201e: jmp    2843 <tail_nodeport_nat_ingress_ipv6+0x2843> */
	return 10307ULL;
x86_l_2023:
	/* 0x2023: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2026:
	/* 0x2026: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_2029:
	/* 0x2029: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_202c:
	/* 0x202c: or     ax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_2031:
	/* 0x2031: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2033:
	/* 0x2033: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_2036:
	/* 0x2036: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_203b:
	/* 0x203b: mov    rcx,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2042:
	/* 0x2042: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2044:
	/* 0x2044: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2046:
	/* 0x2046: je     2109 <tail_nodeport_nat_ingress_ipv6+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2109;
	}
x86_l_204c:
	/* 0x204c: mov    r14,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2053:
	/* 0x2053: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2057:
	/* 0x2057: je     206c <tail_nodeport_nat_ingress_ipv6+0x206c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206c;
	}
x86_l_2059:
	/* 0x2059: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2060:
	/* 0x2060: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2062:
	/* 0x2062: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2064:
	/* 0x2064: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2067:
	/* 0x2067: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_206a:
	/* 0x206a: jmp    2071 <tail_nodeport_nat_ingress_ipv6+0x2071> */
	goto x86_l_2071;
x86_l_206c:
	/* 0x206c: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2071:
	/* 0x2071: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_2075:
	/* 0x2075: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2079:
	/* 0x2079: je     208a <tail_nodeport_nat_ingress_ipv6+0x208a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208a;
	}
x86_l_207b:
	/* 0x207b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2080:
	/* 0x2080: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2082:
	/* 0x2082: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2084:
	/* 0x2084: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2088:
	/* 0x2088: jmp    20ad <tail_nodeport_nat_ingress_ipv6+0x20ad> */
	goto x86_l_20ad;
x86_l_208a:
	/* 0x208a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_208f:
	/* 0x208f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2091:
	/* 0x2091: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2093:
	/* 0x2093: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2097:
	/* 0x2097: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_20a1:
	/* 0x20a1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_20a4:
	/* 0x20a4: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_20a9:
	/* 0x20a9: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_20ad:
	/* 0x20ad: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20af:
	/* 0x20af: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20b3:
	/* 0x20b3: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_20b8:
	/* 0x20b8: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_20bc:
	/* 0x20bc: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20bf:
	/* 0x20bf: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_20c3:
	/* 0x20c3: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c6:
	/* 0x20c6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ca:
	/* 0x20ca: je     20dd <tail_nodeport_nat_ingress_ipv6+0x20dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20dd;
	}
x86_l_20cc:
	/* 0x20cc: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_20d3:
	/* 0x20d3: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d5:
	/* 0x20d5: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_20d8:
	/* 0x20d8: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_20db:
	/* 0x20db: jmp    20e2 <tail_nodeport_nat_ingress_ipv6+0x20e2> */
	goto x86_l_20e2;
x86_l_20dd:
	/* 0x20dd: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_20e2:
	/* 0x20e2: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20e4:
	/* 0x20e4: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e7:
	/* 0x20e7: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_20e9:
	/* 0x20e9: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ec:
	/* 0x20ec: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_20ee:
	/* 0x20ee: jb     20f5 <tail_nodeport_nat_ingress_ipv6+0x20f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20f5;
	}
x86_l_20f0:
	/* 0x20f0: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20f3:
	/* 0x20f3: je     2109 <tail_nodeport_nat_ingress_ipv6+0x2109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2109;
	}
x86_l_20f5:
	/* 0x20f5: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f8:
	/* 0x20f8: mov    BYTE PTR [r15+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_20fc:
	/* 0x20fc: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2100:
	/* 0x2100: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2107:
	/* 0x2107: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2109:
	/* 0x2109: test   BYTE PTR [rsp+0x85],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650370ULL);
x86_l_2111:
	/* 0x2111: jne    2915 <tail_nodeport_nat_ingress_ipv6+0x2915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10517ULL;
	}
x86_l_2117:
	/* 0x2117: movzx  ebp,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_211c:
	/* 0x211c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2121:
	/* 0x2121: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2126:
	/* 0x2126: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2129:
	/* 0x2129: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_212e:
	/* 0x212e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2133:
	/* 0x2133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2135:
	/* 0x2135: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2137:
	/* 0x2137: js     216d <tail_nodeport_nat_ingress_ipv6+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_216d;
	}
x86_l_2139:
	/* 0x2139: movzx  eax,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_213e:
	/* 0x213e: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2140:
	/* 0x2140: jae    217f <tail_nodeport_nat_ingress_ipv6+0x217f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_217f;
	}
x86_l_2142:
	/* 0x2142: movabs rax,0x200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934592ULL);
x86_l_214c:
	/* 0x214c: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2150:
	/* 0x2150: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2157:
	/* 0x2157: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_215c:
	/* 0x215c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2164:
	/* 0x2164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2166:
	/* 0x2166: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_216b:
	/* 0x216b: jmp    2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	goto x86_l_2172;
x86_l_216d:
	/* 0x216d: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_2172:
	/* 0x2172: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2175:
	/* 0x2175: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_217a:
	/* 0x217a: jmp    1114 <tail_nodeport_nat_ingress_ipv6+0x1114> */
	return 4372ULL;
x86_l_217f:
	/* 0x217f: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_2181:
	/* 0x2181: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2185:
	/* 0x2185: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218a:
	/* 0x218a: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_218f:
	/* 0x218f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2192:
	/* 0x2192: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_2197:
	/* 0x2197: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_219c:
	/* 0x219c: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_21a2:
	/* 0x21a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a4:
	/* 0x21a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a6:
	/* 0x21a6: js     2257 <tail_nodeport_nat_ingress_ipv6+0x2257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8791ULL;
	}
x86_l_21ac:
	/* 0x21ac: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21b1:
	/* 0x21b1: mov    r14,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_21b8:
	/* 0x21b8: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21bc:
	/* 0x21bc: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_21c3:
	/* 0x21c3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c8:
	/* 0x21c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21cd:
	/* 0x21cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cf:
	/* 0x21cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d2:
	/* 0x21d2: je     2395 <tail_nodeport_nat_ingress_ipv6+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9109ULL;
	}
x86_l_21d8:
	/* 0x21d8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_21db:
	/* 0x21db: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21df:
	/* 0x21df: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21e4:
	/* 0x21e4: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21e9:
	/* 0x21e9: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ee:
	/* 0x21ee: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21f3:
	/* 0x21f3: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f7:
	/* 0x21f7: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21fc:
	/* 0x21fc: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21ff:
	/* 0x21ff: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 8708ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8749ULL: goto x86_l_222d;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8773ULL: goto x86_l_2245;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8809ULL: goto x86_l_2269;
	case 8811ULL: goto x86_l_226b;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8830ULL: goto x86_l_227e;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8850ULL: goto x86_l_2292;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8875ULL: goto x86_l_22ab;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8896ULL: goto x86_l_22c0;
	case 8898ULL: goto x86_l_22c2;
	case 8901ULL: goto x86_l_22c5;
	case 8903ULL: goto x86_l_22c7;
	case 8908ULL: goto x86_l_22cc;
	case 8911ULL: goto x86_l_22cf;
	case 8913ULL: goto x86_l_22d1;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8962ULL: goto x86_l_2302;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8982ULL: goto x86_l_2316;
	case 8985ULL: goto x86_l_2319;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8997ULL: goto x86_l_2325;
	case 8999ULL: goto x86_l_2327;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9040ULL: goto x86_l_2350;
	case 9042ULL: goto x86_l_2352;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9053ULL: goto x86_l_235d;
	case 9060ULL: goto x86_l_2364;
	case 9066ULL: goto x86_l_236a;
	case 9069ULL: goto x86_l_236d;
	case 9072ULL: goto x86_l_2370;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9082ULL: goto x86_l_237a;
	case 9084ULL: goto x86_l_237c;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9092ULL: goto x86_l_2384;
	case 9095ULL: goto x86_l_2387;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9103ULL: goto x86_l_238f;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9124ULL: goto x86_l_23a4;
	case 9127ULL: goto x86_l_23a7;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9155ULL: goto x86_l_23c3;
	case 9162ULL: goto x86_l_23ca;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9180ULL: goto x86_l_23dc;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9219ULL: goto x86_l_2403;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9242ULL: goto x86_l_241a;
	case 9245ULL: goto x86_l_241d;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9256ULL: goto x86_l_2428;
	case 9261ULL: goto x86_l_242d;
	case 9263ULL: goto x86_l_242f;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9306ULL: goto x86_l_245a;
	case 9309ULL: goto x86_l_245d;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9322ULL: goto x86_l_246a;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9356ULL: goto x86_l_248c;
	case 9359ULL: goto x86_l_248f;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9372ULL: goto x86_l_249c;
	case 9377ULL: goto x86_l_24a1;
	case 9382ULL: goto x86_l_24a6;
	case 9385ULL: goto x86_l_24a9;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9401ULL: goto x86_l_24b9;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9420ULL: goto x86_l_24cc;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9441ULL: goto x86_l_24e1;
	case 9446ULL: goto x86_l_24e6;
	case 9454ULL: goto x86_l_24ee;
	case 9461ULL: goto x86_l_24f5;
	case 9464ULL: goto x86_l_24f8;
	case 9467ULL: goto x86_l_24fb;
	case 9475ULL: goto x86_l_2503;
	case 9480ULL: goto x86_l_2508;
	case 9483ULL: goto x86_l_250b;
	case 9488ULL: goto x86_l_2510;
	case 9490ULL: goto x86_l_2512;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9497ULL: goto x86_l_2519;
	case 9503ULL: goto x86_l_251f;
	case 9510ULL: goto x86_l_2526;
	case 9514ULL: goto x86_l_252a;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9533ULL: goto x86_l_253d;
	case 9536ULL: goto x86_l_2540;
	case 9538ULL: goto x86_l_2542;
	case 9542ULL: goto x86_l_2546;
	case 9548ULL: goto x86_l_254c;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9576ULL: goto x86_l_2568;
	case 9582ULL: goto x86_l_256e;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9611ULL: goto x86_l_258b;
	case 9614ULL: goto x86_l_258e;
	case 9616ULL: goto x86_l_2590;
	case 9618ULL: goto x86_l_2592;
	case 9624ULL: goto x86_l_2598;
	case 9632ULL: goto x86_l_25a0;
	case 9640ULL: goto x86_l_25a8;
	case 9644ULL: goto x86_l_25ac;
	case 9647ULL: goto x86_l_25af;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9694ULL: goto x86_l_25de;
	case 9697ULL: goto x86_l_25e1;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9733ULL: goto x86_l_2605;
	case 9738ULL: goto x86_l_260a;
	case 9741ULL: goto x86_l_260d;
	case 9743ULL: goto x86_l_260f;
	case 9746ULL: goto x86_l_2612;
	case 9752ULL: goto x86_l_2618;
	case 9754ULL: goto x86_l_261a;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9793ULL: goto x86_l_2641;
	case 9801ULL: goto x86_l_2649;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9807ULL: goto x86_l_264f;
	case 9813ULL: goto x86_l_2655;
	case 9815ULL: goto x86_l_2657;
	case 9824ULL: goto x86_l_2660;
	case 9833ULL: goto x86_l_2669;
	case 9843ULL: goto x86_l_2673;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9861ULL: goto x86_l_2685;
	case 9866ULL: goto x86_l_268a;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9876ULL: goto x86_l_2694;
	case 9882ULL: goto x86_l_269a;
	case 9885ULL: goto x86_l_269d;
	case 9889ULL: goto x86_l_26a1;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9958ULL: goto x86_l_26e6;
	case 9962ULL: goto x86_l_26ea;
	case 9971ULL: goto x86_l_26f3;
	case 9979ULL: goto x86_l_26fb;
	case 9988ULL: goto x86_l_2704;
	case 9997ULL: goto x86_l_270d;
	case 10006ULL: goto x86_l_2716;
	case 10014ULL: goto x86_l_271e;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10050ULL: goto x86_l_2742;
	case 10059ULL: goto x86_l_274b;
	case 10068ULL: goto x86_l_2754;
	case 10077ULL: goto x86_l_275d;
	case 10085ULL: goto x86_l_2765;
	case 10089ULL: goto x86_l_2769;
	case 10093ULL: goto x86_l_276d;
	case 10097ULL: goto x86_l_2771;
	case 10101ULL: goto x86_l_2775;
	case 10105ULL: goto x86_l_2779;
	case 10109ULL: goto x86_l_277d;
	case 10113ULL: goto x86_l_2781;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10127ULL: goto x86_l_278f;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10149ULL: goto x86_l_27a5;
	case 10155ULL: goto x86_l_27ab;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10167ULL: goto x86_l_27b7;
	case 10169ULL: goto x86_l_27b9;
	case 10172ULL: goto x86_l_27bc;
	case 10174ULL: goto x86_l_27be;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10189ULL: goto x86_l_27cd;
	case 10191ULL: goto x86_l_27cf;
	case 10196ULL: goto x86_l_27d4;
	case 10202ULL: goto x86_l_27da;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10243ULL: goto x86_l_2803;
	case 10248ULL: goto x86_l_2808;
	case 10250ULL: goto x86_l_280a;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10307ULL: goto x86_l_2843;
	case 10311ULL: goto x86_l_2847;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10346ULL: goto x86_l_286a;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2204:
	/* 0x2204: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2209:
	/* 0x2209: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_220c:
	/* 0x220c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2211:
	/* 0x2211: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2214:
	/* 0x2214: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2219:
	/* 0x2219: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_221c:
	/* 0x221c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221e:
	/* 0x221e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2220:
	/* 0x2220: sets   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_S);
x86_l_2223:
	/* 0x2223: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2226:
	/* 0x2226: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2229:
	/* 0x2229: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_222b:
	/* 0x222b: jne    2261 <tail_nodeport_nat_ingress_ipv6+0x2261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2261;
	}
x86_l_222d:
	/* 0x222d: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2233:
	/* 0x2233: jne    2261 <tail_nodeport_nat_ingress_ipv6+0x2261> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2261;
	}
x86_l_2235:
	/* 0x2235: movzx  eax,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_223d:
	/* 0x223d: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_2240:
	/* 0x2240: je     2289 <tail_nodeport_nat_ingress_ipv6+0x2289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2289;
	}
x86_l_2242:
	/* 0x2242: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2245:
	/* 0x2245: je     2278 <tail_nodeport_nat_ingress_ipv6+0x2278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2278;
	}
x86_l_2247:
	/* 0x2247: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_224a:
	/* 0x224a: jne    2294 <tail_nodeport_nat_ingress_ipv6+0x2294> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2294;
	}
x86_l_224c:
	/* 0x224c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_224f:
	/* 0x224f: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_2255:
	/* 0x2255: jmp    229a <tail_nodeport_nat_ingress_ipv6+0x229a> */
	goto x86_l_229a;
x86_l_2257:
	/* 0x2257: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_225c:
	/* 0x225c: jmp    2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	return 8562ULL;
x86_l_2261:
	/* 0x2261: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2263:
	/* 0x2263: jne    291f <tail_nodeport_nat_ingress_ipv6+0x291f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10527ULL;
	}
x86_l_2269:
	/* 0x2269: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_226b:
	/* 0x226b: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_226d:
	/* 0x226d: je     2395 <tail_nodeport_nat_ingress_ipv6+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2395;
	}
x86_l_2273:
	/* 0x2273: jmp    27b9 <tail_nodeport_nat_ingress_ipv6+0x27b9> */
	goto x86_l_27b9;
x86_l_2278:
	/* 0x2278: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_227e:
	/* 0x227e: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2284:
	/* 0x2284: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2287:
	/* 0x2287: jmp    229d <tail_nodeport_nat_ingress_ipv6+0x229d> */
	goto x86_l_229d;
x86_l_2289:
	/* 0x2289: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228c:
	/* 0x228c: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2292:
	/* 0x2292: jmp    229a <tail_nodeport_nat_ingress_ipv6+0x229a> */
	goto x86_l_229a;
x86_l_2294:
	/* 0x2294: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2297:
	/* 0x2297: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_229a:
	/* 0x229a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_229d:
	/* 0x229d: movzx  edx,WORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_22a2:
	/* 0x22a2: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_22a5:
	/* 0x22a5: je     2331 <tail_nodeport_nat_ingress_ipv6+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_22ab:
	/* 0x22ab: movzx  ebp,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_22b3:
	/* 0x22b3: mov    ecx,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967154ULL);
x86_l_22b8:
	/* 0x22b8: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_22bb:
	/* 0x22bb: jg     22cc <tail_nodeport_nat_ingress_ipv6+0x22cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22cc;
	}
x86_l_22bd:
	/* 0x22bd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22c0:
	/* 0x22c0: je     2331 <tail_nodeport_nat_ingress_ipv6+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_22c2:
	/* 0x22c2: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_22c5:
	/* 0x22c5: je     22da <tail_nodeport_nat_ingress_ipv6+0x22da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22da;
	}
x86_l_22c7:
	/* 0x22c7: jmp    25f4 <tail_nodeport_nat_ingress_ipv6+0x25f4> */
	goto x86_l_25f4;
x86_l_22cc:
	/* 0x22cc: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_22cf:
	/* 0x22cf: je     2331 <tail_nodeport_nat_ingress_ipv6+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_22d1:
	/* 0x22d1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_22d4:
	/* 0x22d4: jne    25f4 <tail_nodeport_nat_ingress_ipv6+0x25f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25f4;
	}
x86_l_22da:
	/* 0x22da: cmp    dx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_16);
x86_l_22dd:
	/* 0x22dd: je     2331 <tail_nodeport_nat_ingress_ipv6+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_22df:
	/* 0x22df: mov    WORD PTR [rsp+0x50],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22e4:
	/* 0x22e4: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22e9:
	/* 0x22e9: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_22ee:
	/* 0x22ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22f1:
	/* 0x22f1: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22f6:
	/* 0x22f6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22fb:
	/* 0x22fb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22fe:
	/* 0x22fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2300:
	/* 0x2300: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2302:
	/* 0x2302: js     25ef <tail_nodeport_nat_ingress_ipv6+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25ef;
	}
x86_l_2308:
	/* 0x2308: movzx  ecx,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_230d:
	/* 0x230d: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2312:
	/* 0x2312: lea    esi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2316:
	/* 0x2316: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_2319:
	/* 0x2319: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_231d:
	/* 0x231d: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2322:
	/* 0x2322: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2325:
	/* 0x2325: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2327:
	/* 0x2327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2329:
	/* 0x2329: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232b:
	/* 0x232b: js     25d7 <tail_nodeport_nat_ingress_ipv6+0x25d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d7;
	}
x86_l_2331:
	/* 0x2331: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2334:
	/* 0x2334: jne    2395 <tail_nodeport_nat_ingress_ipv6+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2395;
	}
x86_l_2336:
	/* 0x2336: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_233b:
	/* 0x233b: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2340:
	/* 0x2340: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2345:
	/* 0x2345: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2348:
	/* 0x2348: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_234d:
	/* 0x234d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2350:
	/* 0x2350: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2352:
	/* 0x2352: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_2355:
	/* 0x2355: add    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 72ULL);
x86_l_235a:
	/* 0x235a: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_235d:
	/* 0x235d: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_2364:
	/* 0x2364: mov    r14d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 11ULL);
x86_l_236a:
	/* 0x236a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_236d:
	/* 0x236d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2370:
	/* 0x2370: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2372:
	/* 0x2372: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2374:
	/* 0x2374: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2377:
	/* 0x2377: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_237a:
	/* 0x237a: jne    238d <tail_nodeport_nat_ingress_ipv6+0x238d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_238d;
	}
x86_l_237c:
	/* 0x237c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_237f:
	/* 0x237f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2382:
	/* 0x2382: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2384:
	/* 0x2384: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2387:
	/* 0x2387: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_238a:
	/* 0x238a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_238d:
	/* 0x238d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_238f:
	/* 0x238f: js     25d7 <tail_nodeport_nat_ingress_ipv6+0x25d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d7;
	}
x86_l_2395:
	/* 0x2395: mov    r12d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2399:
	/* 0x2399: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_239c:
	/* 0x239c: lea    rcx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23a1:
	/* 0x23a1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a4:
	/* 0x23a4: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_23a7:
	/* 0x23a7: jbe    23b3 <tail_nodeport_nat_ingress_ipv6+0x23b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23b3;
	}
x86_l_23a9:
	/* 0x23a9: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_23ae:
	/* 0x23ae: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	return 8565ULL;
x86_l_23b3:
	/* 0x23b3: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_23b8:
	/* 0x23b8: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_23bb:
	/* 0x23bb: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_23c0:
	/* 0x23c0: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c3:
	/* 0x23c3: mov    WORD PTR [rsp+0x16],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489281024ULL);
x86_l_23ca:
	/* 0x23ca: mov    DWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476896ULL);
x86_l_23d2:
	/* 0x23d2: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23d7:
	/* 0x23d7: mov    rcx,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23dc:
	/* 0x23dc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23e1:
	/* 0x23e1: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23e6:
	/* 0x23e6: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_23ed:
	/* 0x23ed: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_23f4:
	/* 0x23f4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f9:
	/* 0x23f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23fe:
	/* 0x23fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2400:
	/* 0x2400: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2403:
	/* 0x2403: je     24a1 <tail_nodeport_nat_ingress_ipv6+0x24a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a1;
	}
x86_l_2409:
	/* 0x2409: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_240c:
	/* 0x240c: movzx  eax,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_2410:
	/* 0x2410: and    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_2412:
	/* 0x2412: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2414:
	/* 0x2414: jne    24a1 <tail_nodeport_nat_ingress_ipv6+0x24a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24a1;
	}
x86_l_241a:
	/* 0x241a: mov    ebp,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_241d:
	/* 0x241d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2420:
	/* 0x2420: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2425:
	/* 0x2425: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2428:
	/* 0x2428: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_242d:
	/* 0x242d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_242f:
	/* 0x242f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2431:
	/* 0x2431: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2433:
	/* 0x2433: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_2438:
	/* 0x2438: jne    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8565ULL;
	}
x86_l_243e:
	/* 0x243e: mov    WORD PTR [rsp+0x10],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2443:
	/* 0x2443: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2448:
	/* 0x2448: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_244d:
	/* 0x244d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2450:
	/* 0x2450: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2455:
	/* 0x2455: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_245a:
	/* 0x245a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_245d:
	/* 0x245d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245f:
	/* 0x245f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2461:
	/* 0x2461: js     25ef <tail_nodeport_nat_ingress_ipv6+0x25ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25ef;
	}
x86_l_2467:
	/* 0x2467: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246a:
	/* 0x246a: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_2474:
	/* 0x2474: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2479:
	/* 0x2479: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2480:
	/* 0x2480: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_248a:
	/* 0x248a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_248c:
	/* 0x248c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_248f:
	/* 0x248f: je     26b7 <tail_nodeport_nat_ingress_ipv6+0x26b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b7;
	}
x86_l_2495:
	/* 0x2495: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2498:
	/* 0x2498: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_249c:
	/* 0x249c: jmp    26df <tail_nodeport_nat_ingress_ipv6+0x26df> */
	goto x86_l_26df;
x86_l_24a1:
	/* 0x24a1: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a6:
	/* 0x24a6: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_24a9:
	/* 0x24a9: jne    24bf <tail_nodeport_nat_ingress_ipv6+0x24bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24bf;
	}
x86_l_24ab:
	/* 0x24ab: mov    eax,0xffffff5f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967135ULL);
x86_l_24b0:
	/* 0x24b0: cmp    DWORD PTR [r12+0x10],0xffff0000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014378496ULL);
x86_l_24b9:
	/* 0x24b9: je     2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8565ULL;
	}
x86_l_24bf:
	/* 0x24bf: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c4:
	/* 0x24c4: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_24cc:
	/* 0x24cc: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_24d4:
	/* 0x24d4: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d9:
	/* 0x24d9: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_24e1:
	/* 0x24e1: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24e6:
	/* 0x24e6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24ee:
	/* 0x24ee: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_24f5:
	/* 0x24f5: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_24f8:
	/* 0x24f8: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_24fb:
	/* 0x24fb: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2503:
	/* 0x2503: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_2508:
	/* 0x2508: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_250b:
	/* 0x250b: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_2510:
	/* 0x2510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2512:
	/* 0x2512: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2514:
	/* 0x2514: je     251f <tail_nodeport_nat_ingress_ipv6+0x251f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251f;
	}
x86_l_2516:
	/* 0x2516: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2519:
	/* 0x2519: jne    25de <tail_nodeport_nat_ingress_ipv6+0x25de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25de;
	}
x86_l_251f:
	/* 0x251f: mov    ebp,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2526:
	/* 0x2526: mov    DWORD PTR [rsp+0x10],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252a:
	/* 0x252a: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_2531:
	/* 0x2531: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2536:
	/* 0x2536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_253b:
	/* 0x253b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253d:
	/* 0x253d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2540:
	/* 0x2540: je     254c <tail_nodeport_nat_ingress_ipv6+0x254c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254c;
	}
x86_l_2542:
	/* 0x2542: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2546:
	/* 0x2546: jne    2626 <tail_nodeport_nat_ingress_ipv6+0x2626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2626;
	}
x86_l_254c:
	/* 0x254c: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2550:
	/* 0x2550: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2555:
	/* 0x2555: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2558:
	/* 0x2558: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_255d:
	/* 0x255d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_255f:
	/* 0x255f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2561:
	/* 0x2561: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_2566:
	/* 0x2566: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2568:
	/* 0x2568: jne    25f4 <tail_nodeport_nat_ingress_ipv6+0x25f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25f4;
	}
x86_l_256e:
	/* 0x256e: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2574:
	/* 0x2574: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2579:
	/* 0x2579: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_257e:
	/* 0x257e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2581:
	/* 0x2581: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2586:
	/* 0x2586: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_258b:
	/* 0x258b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258e:
	/* 0x258e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2590:
	/* 0x2590: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2592:
	/* 0x2592: js     27fe <tail_nodeport_nat_ingress_ipv6+0x27fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_27fe;
	}
x86_l_2598:
	/* 0x2598: lea    rax,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_25a0:
	/* 0x25a0: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_25a8:
	/* 0x25a8: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ac:
	/* 0x25ac: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25af:
	/* 0x25af: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b3:
	/* 0x25b3: mov    QWORD PTR [rsp+0x14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_25b8:
	/* 0x25b8: mov    QWORD PTR [rsp+0x1c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_25bd:
	/* 0x25bd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c2:
	/* 0x25c2: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_25c7:
	/* 0x25c7: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_25c9:
	/* 0x25c9: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_25ce:
	/* 0x25ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d0:
	/* 0x25d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d2:
	/* 0x25d2: jmp    27b9 <tail_nodeport_nat_ingress_ipv6+0x27b9> */
	goto x86_l_27b9;
x86_l_25d7:
	/* 0x25d7: mov    ecx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967142ULL);
x86_l_25dc:
	/* 0x25dc: jmp    25f4 <tail_nodeport_nat_ingress_ipv6+0x25f4> */
	goto x86_l_25f4;
x86_l_25de:
	/* 0x25de: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_25e1:
	/* 0x25e1: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_25e5:
	/* 0x25e5: mov    eax,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967127ULL);
x86_l_25ea:
	/* 0x25ea: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	return 8565ULL;
x86_l_25ef:
	/* 0x25ef: mov    ecx,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967155ULL);
x86_l_25f4:
	/* 0x25f4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25f7:
	/* 0x25f7: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_25f9:
	/* 0x25f9: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	return 8565ULL;
x86_l_25fe:
	/* 0x25fe: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_2605:
	/* 0x2605: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_260a:
	/* 0x260a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_260d:
	/* 0x260d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260f:
	/* 0x260f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2612:
	/* 0x2612: je     27e6 <tail_nodeport_nat_ingress_ipv6+0x27e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27e6;
	}
x86_l_2618:
	/* 0x2618: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261a:
	/* 0x261a: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2621:
	/* 0x2621: jmp    1d0e <tail_nodeport_nat_ingress_ipv6+0x1d0e> */
	return 7438ULL;
x86_l_2626:
	/* 0x2626: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_262b:
	/* 0x262b: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_262d:
	/* 0x262d: jmp    27b5 <tail_nodeport_nat_ingress_ipv6+0x27b5> */
	goto x86_l_27b5;
x86_l_2632:
	/* 0x2632: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_2639:
	/* 0x2639: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_263e:
	/* 0x263e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2641:
	/* 0x2641: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2649:
	/* 0x2649: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_264b:
	/* 0x264b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264d:
	/* 0x264d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_264f:
	/* 0x264f: je     1d0e <tail_nodeport_nat_ingress_ipv6+0x1d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7438ULL;
	}
x86_l_2655:
	/* 0x2655: mov    ebp,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2657:
	/* 0x2657: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2660:
	/* 0x2660: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2669:
	/* 0x2669: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_2673:
	/* 0x2673: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_2679:
	/* 0x2679: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_267e:
	/* 0x267e: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2685:
	/* 0x2685: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_268a:
	/* 0x268a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_268f:
	/* 0x268f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2691:
	/* 0x2691: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2694:
	/* 0x2694: je     280a <tail_nodeport_nat_ingress_ipv6+0x280a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_280a;
	}
x86_l_269a:
	/* 0x269a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_269d:
	/* 0x269d: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26a1:
	/* 0x26a1: mov    rbp,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_26a8:
	/* 0x26a8: jmp    1d0e <tail_nodeport_nat_ingress_ipv6+0x1d0e> */
	return 7438ULL;
x86_l_26ad:
	/* 0x26ad: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_26b2:
	/* 0x26b2: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	return 8565ULL;
x86_l_26b7:
	/* 0x26b7: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_26c0:
	/* 0x26c0: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26c5:
	/* 0x26c5: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_26cc:
	/* 0x26cc: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26d1:
	/* 0x26d1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26d6:
	/* 0x26d6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26db:
	/* 0x26db: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26dd:
	/* 0x26dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26df:
	/* 0x26df: test   BYTE PTR [r14+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_26e4:
	/* 0x26e4: jne    2742 <tail_nodeport_nat_ingress_ipv6+0x2742> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2742;
	}
x86_l_26e6:
	/* 0x26e6: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26ea:
	/* 0x26ea: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26f3:
	/* 0x26f3: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_26fb:
	/* 0x26fb: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2704:
	/* 0x2704: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_270d:
	/* 0x270d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2716:
	/* 0x2716: mov    DWORD PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_271e:
	/* 0x271e: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_2724:
	/* 0x2724: mov    BYTE PTR [rsp+0x25],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913790016ULL);
x86_l_2729:
	/* 0x2729: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_272e:
	/* 0x272e: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2733:
	/* 0x2733: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2736:
	/* 0x2736: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_273b:
	/* 0x273b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2740:
	/* 0x2740: jmp    27a1 <tail_nodeport_nat_ingress_ipv6+0x27a1> */
	goto x86_l_27a1;
x86_l_2742:
	/* 0x2742: mov    QWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_274b:
	/* 0x274b: mov    QWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_2754:
	/* 0x2754: mov    QWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_275d:
	/* 0x275d: mov    DWORD PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_2765:
	/* 0x2765: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2769:
	/* 0x2769: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_276d:
	/* 0x276d: mov    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2771:
	/* 0x2771: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2775:
	/* 0x2775: mov    eax,DWORD PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2779:
	/* 0x2779: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_277d:
	/* 0x277d: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2781:
	/* 0x2781: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2785:
	/* 0x2785: mov    BYTE PTR [rsp+0x25],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913790016ULL);
x86_l_278a:
	/* 0x278a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_278f:
	/* 0x278f: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2794:
	/* 0x2794: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2797:
	/* 0x2797: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_279c:
	/* 0x279c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_27a1:
	/* 0x27a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a3:
	/* 0x27a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27a5:
	/* 0x27a5: js     2931 <tail_nodeport_nat_ingress_ipv6+0x2931> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10545ULL;
	}
x86_l_27ab:
	/* 0x27ab: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_27b0:
	/* 0x27b0: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_27b5:
	/* 0x27b5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b7:
	/* 0x27b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b9:
	/* 0x27b9: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27bc:
	/* 0x27bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27be:
	/* 0x27be: js     2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8565ULL;
	}
x86_l_27c4:
	/* 0x27c4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27c7:
	/* 0x27c7: je     2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8565ULL;
	}
x86_l_27cd:
	/* 0x27cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27cf:
	/* 0x27cf: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27d4:
	/* 0x27d4: je     10ef <tail_nodeport_nat_ingress_ipv6+0x10ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4335ULL;
	}
x86_l_27da:
	/* 0x27da: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_27e1:
	/* 0x27e1: jmp    11c0 <tail_nodeport_nat_ingress_ipv6+0x11c0> */
	return 4544ULL;
x86_l_27e6:
	/* 0x27e6: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_27eb:
	/* 0x27eb: mov    QWORD PTR [r15],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ee:
	/* 0x27ee: jmp    2172 <tail_nodeport_nat_ingress_ipv6+0x2172> */
	return 8562ULL;
x86_l_27f3:
	/* 0x27f3: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_27f9:
	/* 0x27f9: jmp    1e7b <tail_nodeport_nat_ingress_ipv6+0x1e7b> */
	return 7803ULL;
x86_l_27fe:
	/* 0x27fe: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2800:
	/* 0x2800: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_2803:
	/* 0x2803: and    eax,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_2808:
	/* 0x2808: jmp    27b9 <tail_nodeport_nat_ingress_ipv6+0x27b9> */
	goto x86_l_27b9;
x86_l_280a:
	/* 0x280a: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2813:
	/* 0x2813: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2818:
	/* 0x2818: mov    rdi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_281f:
	/* 0x281f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2824:
	/* 0x2824: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2829:
	/* 0x2829: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_282e:
	/* 0x282e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2830:
	/* 0x2830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2832:
	/* 0x2832: mov    rbp,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_2839:
	/* 0x2839: jmp    1d0e <tail_nodeport_nat_ingress_ipv6+0x1d0e> */
	return 7438ULL;
x86_l_283e:
	/* 0x283e: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_2843:
	/* 0x2843: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_2847:
	/* 0x2847: jne    287d <tail_nodeport_nat_ingress_ipv6+0x287d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10365ULL;
	}
x86_l_2849:
	/* 0x2849: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_284c:
	/* 0x284c: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_284e:
	/* 0x284e: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2851:
	/* 0x2851: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2854:
	/* 0x2854: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2856:
	/* 0x2856: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_285b:
	/* 0x285b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_285d:
	/* 0x285d: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2862:
	/* 0x2862: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_2867:
	/* 0x2867: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_286a:
	/* 0x286a: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286e:
	/* 0x286e: je     287d <tail_nodeport_nat_ingress_ipv6+0x287d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10365ULL;
	}
x86_l_2870:
	/* 0x2870: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
	return 10359ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10359ULL: goto x86_l_2877;
	case 10362ULL: goto x86_l_287a;
	case 10365ULL: goto x86_l_287d;
	case 10369ULL: goto x86_l_2881;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10382ULL: goto x86_l_288e;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10413ULL: goto x86_l_28ad;
	case 10416ULL: goto x86_l_28b0;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10427ULL: goto x86_l_28bb;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10447ULL: goto x86_l_28cf;
	case 10450ULL: goto x86_l_28d2;
	case 10454ULL: goto x86_l_28d6;
	case 10456ULL: goto x86_l_28d8;
	case 10463ULL: goto x86_l_28df;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10473ULL: goto x86_l_28e9;
	case 10478ULL: goto x86_l_28ee;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10485ULL: goto x86_l_28f5;
	case 10488ULL: goto x86_l_28f8;
	case 10490ULL: goto x86_l_28fa;
	case 10492ULL: goto x86_l_28fc;
	case 10495ULL: goto x86_l_28ff;
	case 10497ULL: goto x86_l_2901;
	case 10500ULL: goto x86_l_2904;
	case 10504ULL: goto x86_l_2908;
	case 10508ULL: goto x86_l_290c;
	case 10515ULL: goto x86_l_2913;
	case 10517ULL: goto x86_l_2915;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10534ULL: goto x86_l_2926;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2877:
	/* 0x2877: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_287a:
	/* 0x287a: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_287d:
	/* 0x287d: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_2881:
	/* 0x2881: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2885:
	/* 0x2885: je     2896 <tail_nodeport_nat_ingress_ipv6+0x2896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2896;
	}
x86_l_2887:
	/* 0x2887: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_288c:
	/* 0x288c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_288e:
	/* 0x288e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2890:
	/* 0x2890: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2894:
	/* 0x2894: jmp    28b9 <tail_nodeport_nat_ingress_ipv6+0x28b9> */
	goto x86_l_28b9;
x86_l_2896:
	/* 0x2896: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_289b:
	/* 0x289b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_289d:
	/* 0x289d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_289f:
	/* 0x289f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_28a3:
	/* 0x28a3: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_28ad:
	/* 0x28ad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28b0:
	/* 0x28b0: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_28b5:
	/* 0x28b5: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_28b9:
	/* 0x28b9: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28bb:
	/* 0x28bb: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28bf:
	/* 0x28bf: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_28c4:
	/* 0x28c4: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_28c8:
	/* 0x28c8: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28cb:
	/* 0x28cb: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_28cf:
	/* 0x28cf: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d2:
	/* 0x28d2: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d6:
	/* 0x28d6: je     28e9 <tail_nodeport_nat_ingress_ipv6+0x28e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28e9;
	}
x86_l_28d8:
	/* 0x28d8: mov    rsi,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_28df:
	/* 0x28df: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e1:
	/* 0x28e1: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_28e4:
	/* 0x28e4: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_28e7:
	/* 0x28e7: jmp    28ee <tail_nodeport_nat_ingress_ipv6+0x28ee> */
	goto x86_l_28ee;
x86_l_28e9:
	/* 0x28e9: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_28ee:
	/* 0x28ee: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28f0:
	/* 0x28f0: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f3:
	/* 0x28f3: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_28f5:
	/* 0x28f5: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f8:
	/* 0x28f8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_28fa:
	/* 0x28fa: jb     2901 <tail_nodeport_nat_ingress_ipv6+0x2901> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2901;
	}
x86_l_28fc:
	/* 0x28fc: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_28ff:
	/* 0x28ff: je     2915 <tail_nodeport_nat_ingress_ipv6+0x2915> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2915;
	}
x86_l_2901:
	/* 0x2901: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2904:
	/* 0x2904: mov    BYTE PTR [r15+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_2908:
	/* 0x2908: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_290c:
	/* 0x290c: mov    rax,QWORD PTR [rip+0x38fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2913:
	/* 0x2913: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2915:
	/* 0x2915: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_291a:
	/* 0x291a: jmp    10ef <tail_nodeport_nat_ingress_ipv6+0x10ef> */
	return 4335ULL;
x86_l_291f:
	/* 0x291f: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_2924:
	/* 0x2924: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_2926:
	/* 0x2926: je     2395 <tail_nodeport_nat_ingress_ipv6+0x2395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9109ULL;
	}
x86_l_292c:
	/* 0x292c: jmp    27b9 <tail_nodeport_nat_ingress_ipv6+0x27b9> */
	return 10169ULL;
x86_l_2931:
	/* 0x2931: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2934:
	/* 0x2934: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_2939:
	/* 0x2939: jmp    2175 <tail_nodeport_nat_ingress_ipv6+0x2175> */
	return 8565ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9436U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1891ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1895ULL && __x86_pc <= 3678ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3682ULL && __x86_pc <= 5385ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5389ULL && __x86_pc <= 7119ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7122ULL && __x86_pc <= 8703ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8708ULL && __x86_pc <= 10352ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10359ULL && __x86_pc <= 10553ULL)
			__x86_pc = cilium_bpf_wireguard_tail_nodeport_nat_ingress_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

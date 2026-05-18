#define X86_VM_ENABLE_STACK 1
#define X86_VM_ENABLE_STACK_SLOT7 1
#define X86_VM_ENABLE_STACK_DEEP 1
#define X86_VM_ENABLE_STACK_EXT 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int tracee_syscall_name_table_lookup_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> */
	X86_VM_X86_JCC(X86_CC_BE, 0x110c, 0x110f, x86_l_110f);
x86_l_110e:
	/* 0x110e: ret */
	X86_VM_X86_RET();
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_A, 0x1116, 0x110e, x86_l_110e);
x86_l_1118:
	/* 0x1118: lea    rdi,[rdx+0x10c] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_111f:
	/* 0x111f: cmp    rdi,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_A, 0x1122, 0x110e, x86_l_110e);
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rsi],0x40 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1127:
	/* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1127, 0x110e, x86_l_110e);
x86_l_1129:
	/* 0x1129: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_112a:
	/* 0x112a: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_112d:
	/* 0x112d: push   r15 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_112f:
	/* 0x112f: push   r14 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_1131:
	/* 0x1131: push   r13 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_1133:
	/* 0x1133: push   r12 */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_1135:
	/* 0x1135: push   rbx */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1136:
	/* 0x1136: movabs r10,0x6a09e667f3bcc909 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_64, 0, 7640891576956012809ULL);
x86_l_1140:
	/* 0x1140: movabs rsi,0x65736f6c63 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, 0, 435728378979ULL);
x86_l_114a:
	/* 0x114a: xor    r8d,r8d */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114d:
	/* 0x114d: lea    r9,[rsi+0xfa0614] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_R9, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16385556ULL);
x86_l_1154:
	/* 0x1154: movabs rbx,0x74616e65706f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 127961812791407ULL);
x86_l_115e:
	/* 0x115e: movabs r14,0x74616b6e696c6e75 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 8386102103099862645ULL);
x86_l_1168:
	/* 0x1168: movabs r12,0x74613274617473 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 32757966627239027ULL);
x86_l_1172:
	/* 0x1172: movabs r13,0x647466656e676973 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 7238523086921230707ULL);
x86_l_117c:
	/* 0x117c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1180:
	/* 0x1180: movzx  edi,BYTE PTR [rdx+r8*4+0xc] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_8), 12ULL);
x86_l_1186:
	/* 0x1186: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_8), 13ULL);
x86_l_118c:
	/* 0x118c: shl    ecx,0x8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_118f:
	/* 0x118f: or     ecx,edi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_1191:
	/* 0x1191: movzx  eax,WORD PTR [rdx+r8*4+0xe] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R8, 2, X86_WIDTH_16), 14ULL);
x86_l_1197:
	/* 0x1197: shl    eax,0x10 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_119a:
	/* 0x119a: or     eax,ecx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR, 0);
x86_l_119c:
	/* 0x119c: cmp    eax,0x4f */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 79ULL);
x86_l_119f:
	/* 0x119f: jg     11e0 <tracee_syscall_name_table_lookup_xdp+0xe0> */
	X86_VM_X86_JCC(X86_CC_G, 0x119f, 0x11e0, x86_l_11e0);
x86_l_11a1:
	/* 0x11a1: cmp    eax,0x26 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 38ULL);
x86_l_11a4:
	/* 0x11a4: jg     1220 <tracee_syscall_name_table_lookup_xdp+0x120> */
	X86_VM_X86_JCC(X86_CC_G, 0x11a4, 0x1220, x86_l_1220);
x86_l_11a6:
	/* 0x11a6: cmp    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11a9:
	/* 0x11a9: jg     1284 <tracee_syscall_name_table_lookup_xdp+0x184> */
	X86_VM_X86_JCC(X86_CC_G, 0x11a9, 0x1284, x86_l_1284);
x86_l_11af:
	/* 0x11af: test   eax,eax */
	X86_VM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_11b1:
	/* 0x11b1: je     136f <tracee_syscall_name_table_lookup_xdp+0x26f> */
	X86_VM_X86_JCC(X86_CC_E, 0x11b1, 0x136f, x86_l_136f);
x86_l_11b7:
	/* 0x11b7: cmp    eax,0x1 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 1ULL);
x86_l_11ba:
	/* 0x11ba: je     1329 <tracee_syscall_name_table_lookup_xdp+0x229> */
	X86_VM_X86_JCC(X86_CC_E, 0x11ba, 0x1329, x86_l_1329);
x86_l_11c0:
	/* 0x11c0: cmp    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11c3:
	/* 0x11c3: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x11c3, 0x13ef, x86_l_13ef);
x86_l_11c9:
	/* 0x11c9: mov    ecx,0x6e65706f */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1852141679ULL);
x86_l_11ce:
	/* 0x11ce: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x11ce, 0x13b0, x86_l_13b0);
x86_l_11d3:
	/* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11e0:
	/* 0x11e0: cmp    eax,0x100 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 256ULL);
x86_l_11e5:
	/* 0x11e5: jg     1250 <tracee_syscall_name_table_lookup_xdp+0x150> */
	X86_VM_X86_JCC(X86_CC_G, 0x11e5, 0x1250, x86_l_1250);
x86_l_11e7:
	/* 0x11e7: cmp    eax,0x9d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 157ULL);
x86_l_11ec:
	/* 0x11ec: jg     12ac <tracee_syscall_name_table_lookup_xdp+0x1ac> */
	X86_VM_X86_JCC(X86_CC_G, 0x11ec, 0x12ac, x86_l_12ac);
x86_l_11f2:
	/* 0x11f2: cmp    eax,0x50 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 80ULL);
x86_l_11f5:
	/* 0x11f5: je     1376 <tracee_syscall_name_table_lookup_xdp+0x276> */
	X86_VM_X86_JCC(X86_CC_E, 0x11f5, 0x1376, x86_l_1376);
x86_l_11fb:
	/* 0x11fb: cmp    eax,0x57 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 87ULL);
x86_l_11fe:
	/* 0x11fe: je     1331 <tracee_syscall_name_table_lookup_xdp+0x231> */
	X86_VM_X86_JCC(X86_CC_E, 0x11fe, 0x1331, x86_l_1331);
x86_l_1204:
	/* 0x1204: cmp    eax,0x59 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 89ULL);
x86_l_1207:
	/* 0x1207: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1207, 0x13ef, x86_l_13ef);
x86_l_120d:
	/* 0x120d: movabs rcx,0x6b6e696c55 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 461413903445ULL);
x86_l_1217:
	/* 0x1217: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1217, 0x13b0, x86_l_13b0);
x86_l_121c:
	/* 0x121c: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1220:
	/* 0x1220: cmp    eax,0x3a */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 58ULL);
x86_l_1223:
	/* 0x1223: jg     12dc <tracee_syscall_name_table_lookup_xdp+0x1dc> */
	X86_VM_X86_JCC(X86_CC_G, 0x1223, 0x12dc, x86_l_12dc);
x86_l_1229:
	/* 0x1229: cmp    eax,0x27 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 39ULL);
x86_l_122c:
	/* 0x122c: je     137d <tracee_syscall_name_table_lookup_xdp+0x27d> */
	X86_VM_X86_JCC(X86_CC_E, 0x122c, 0x137d, x86_l_137d);
x86_l_1232:
	/* 0x1232: cmp    eax,0x38 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 56ULL);
x86_l_1235:
	/* 0x1235: je     133d <tracee_syscall_name_table_lookup_xdp+0x23d> */
	X86_VM_X86_JCC(X86_CC_E, 0x1235, 0x133d, x86_l_133d);
x86_l_123b:
	/* 0x123b: cmp    eax,0x39 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 57ULL);
x86_l_123e:
	/* 0x123e: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x123e, 0x13ef, x86_l_13ef);
x86_l_1244:
	/* 0x1244: mov    ecx,0x6b726f66 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802661734ULL);
x86_l_1249:
	/* 0x1249: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1249, 0x13b0, x86_l_13b0);
x86_l_124e:
	/* 0x124e: xchg   ax,ax */
	X86_VM_RUN_OP(X86_OP_XCHG, X86_RAX, X86_RAX, X86_WIDTH_16, 0, 0);
x86_l_1250:
	/* 0x1250: cmp    eax,0x122 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 290ULL);
x86_l_1255:
	/* 0x1255: jg     1302 <tracee_syscall_name_table_lookup_xdp+0x202> */
	X86_VM_X86_JCC(X86_CC_G, 0x1255, 0x1302, x86_l_1302);
x86_l_125b:
	/* 0x125b: cmp    eax,0x101 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 257ULL);
x86_l_1260:
	/* 0x1260: je     1389 <tracee_syscall_name_table_lookup_xdp+0x289> */
	X86_VM_X86_JCC(X86_CC_E, 0x1260, 0x1389, x86_l_1389);
x86_l_1266:
	/* 0x1266: cmp    eax,0x107 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 263ULL);
x86_l_126b:
	/* 0x126b: je     1349 <tracee_syscall_name_table_lookup_xdp+0x249> */
	X86_VM_X86_JCC(X86_CC_E, 0x126b, 0x1349, x86_l_1349);
x86_l_1271:
	/* 0x1271: cmp    eax,0x119 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 281ULL);
x86_l_1276:
	/* 0x1276: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1276, 0x13ef, x86_l_13ef);
x86_l_127c:
	/* 0x127c: mov    rcx,r12 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R12, X86_WIDTH_64, 0, 0);
x86_l_127f:
	/* 0x127f: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x127f, 0x13b0, x86_l_13b0);
x86_l_1284:
	/* 0x1284: mov    rcx,rsi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_64, 0, 0);
x86_l_1287:
	/* 0x1287: cmp    eax,0x3 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 3ULL);
x86_l_128a:
	/* 0x128a: je     13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JCC(X86_CC_E, 0x128a, 0x13b0, x86_l_13b0);
x86_l_1290:
	/* 0x1290: cmp    eax,0x9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 9ULL);
x86_l_1293:
	/* 0x1293: je     134e <tracee_syscall_name_table_lookup_xdp+0x24e> */
	X86_VM_X86_JCC(X86_CC_E, 0x1293, 0x134e, x86_l_134e);
x86_l_1299:
	/* 0x1299: cmp    eax,0xc */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 12ULL);
x86_l_129c:
	/* 0x129c: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x129c, 0x13ef, x86_l_13ef);
x86_l_12a2:
	/* 0x12a2: mov    ecx,0x6b72626b */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1802658411ULL);
x86_l_12a7:
	/* 0x12a7: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x12a7, 0x13b0, x86_l_13b0);
x86_l_12ac:
	/* 0x12ac: cmp    eax,0x9e */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 158ULL);
x86_l_12b1:
	/* 0x12b1: je     138e <tracee_syscall_name_table_lookup_xdp+0x28e> */
	X86_VM_X86_JCC(X86_CC_E, 0x12b1, 0x138e, x86_l_138e);
x86_l_12b7:
	/* 0x12b7: cmp    eax,0xca */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 202ULL);
x86_l_12bc:
	/* 0x12bc: je     1355 <tracee_syscall_name_table_lookup_xdp+0x255> */
	X86_VM_X86_JCC(X86_CC_E, 0x12bc, 0x1355, x86_l_1355);
x86_l_12c2:
	/* 0x12c2: cmp    eax,0xd9 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 217ULL);
x86_l_12c7:
	/* 0x12c7: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12c7, 0x13ef, x86_l_13ef);
x86_l_12cd:
	/* 0x12cd: movabs rcx,0x646461746567 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 110382294525287ULL);
x86_l_12d7:
	/* 0x12d7: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x12d7, 0x13b0, x86_l_13b0);
x86_l_12dc:
	/* 0x12dc: cmp    eax,0x3b */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 59ULL);
x86_l_12df:
	/* 0x12df: je     139a <tracee_syscall_name_table_lookup_xdp+0x29a> */
	X86_VM_X86_JCC(X86_CC_E, 0x12df, 0x139a, x86_l_139a);
x86_l_12e5:
	/* 0x12e5: cmp    eax,0x3c */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 60ULL);
x86_l_12e8:
	/* 0x12e8: je     1361 <tracee_syscall_name_table_lookup_xdp+0x261> */
	X86_VM_X86_JCC(X86_CC_E, 0x12e8, 0x1361, x86_l_1361);
x86_l_12ea:
	/* 0x12ea: cmp    eax,0x3d */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 61ULL);
x86_l_12ed:
	/* 0x12ed: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x12ed, 0x13ef, x86_l_13ef);
x86_l_12f3:
	/* 0x12f3: movabs rcx,0x347469617755 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 57674588845909ULL);
x86_l_12fd:
	/* 0x12fd: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x12fd, 0x13b0, x86_l_13b0);
x86_l_1302:
	/* 0x1302: cmp    eax,0x123 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 291ULL);
x86_l_1307:
	/* 0x1307: je     13a6 <tracee_syscall_name_table_lookup_xdp+0x2a6> */
	X86_VM_X86_JCC(X86_CC_E, 0x1307, 0x13a6, x86_l_13a6);
x86_l_130d:
	/* 0x130d: cmp    eax,0x141 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 321ULL);
x86_l_1312:
	/* 0x1312: je     1368 <tracee_syscall_name_table_lookup_xdp+0x268> */
	X86_VM_X86_JCC(X86_CC_E, 0x1312, 0x1368, x86_l_1368);
x86_l_1314:
	/* 0x1314: cmp    eax,0x14c */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 332ULL);
x86_l_1319:
	/* 0x1319: jne    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> */
	X86_VM_X86_JCC(X86_CC_NE, 0x1319, 0x13ef, x86_l_13ef);
x86_l_131f:
	/* 0x131f: mov    ecx,0x78746173 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 2020893043ULL);
x86_l_1324:
	/* 0x1324: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1324, 0x13b0, x86_l_13b0);
x86_l_1329:
	/* 0x1329: mov    rcx,r9 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R9, X86_WIDTH_64, 0, 0);
x86_l_132c:
	/* 0x132c: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x132c, 0x13b0, x86_l_13b0);
x86_l_1331:
	/* 0x1331: movabs rcx,0x6b6e696c6e75 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 118121959288437ULL);
x86_l_133b:
	/* 0x133b: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x133b, 0x13b0, x86_l_13b0);
x86_l_133d:
	/* 0x133d: movabs rcx,0x656e6f6c6355 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111524990182229ULL);
x86_l_1347:
	/* 0x1347: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1347, 0x13b0, x86_l_13b0);
x86_l_1349:
	/* 0x1349: mov    rcx,r14 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_134c:
	/* 0x134c: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x134c, 0x13b0, x86_l_13b0);
x86_l_134e:
	/* 0x134e: mov    ecx,0x70616d6d */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1885433197ULL);
x86_l_1353:
	/* 0x1353: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1353, 0x13b0, x86_l_13b0);
x86_l_1355:
	/* 0x1355: movabs rcx,0x786574756655 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 132377140880981ULL);
x86_l_135f:
	/* 0x135f: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x135f, 0x13b0, x86_l_13b0);
x86_l_1361:
	/* 0x1361: mov    ecx,0x74697865 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1953069157ULL);
x86_l_1366:
	/* 0x1366: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1366, 0x13b0, x86_l_13b0);
x86_l_1368:
	/* 0x1368: mov    ecx,0x706662 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 7366242ULL);
x86_l_136d:
	/* 0x136d: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x136d, 0x13b0, x86_l_13b0);
x86_l_136f:
	/* 0x136f: mov    ecx,0x72656164 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1919246692ULL);
x86_l_1374:
	/* 0x1374: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1374, 0x13b0, x86_l_13b0);
x86_l_1376:
	/* 0x1376: mov    ecx,0x69646863 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 1768188003ULL);
x86_l_137b:
	/* 0x137b: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x137b, 0x13b0, x86_l_13b0);
x86_l_137d:
	/* 0x137d: movabs rcx,0x6469707467 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 431265707111ULL);
x86_l_1387:
	/* 0x1387: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1387, 0x13b0, x86_l_13b0);
x86_l_1389:
	/* 0x1389: mov    rcx,rbx */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_138c:
	/* 0x138c: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x138c, 0x13b0, x86_l_13b0);
x86_l_138e:
	/* 0x138e: movabs rcx,0x6c74635f68637261 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 7814980514819043937ULL);
x86_l_1398:
	/* 0x1398: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x1398, 0x13b0, x86_l_13b0);
x86_l_139a:
	/* 0x139a: movabs rcx,0x657663657865 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 111559148140645ULL);
x86_l_13a4:
	/* 0x13a4: jmp    13b0 <tracee_syscall_name_table_lookup_xdp+0x2b0> */
	X86_VM_X86_JMP(0x13a4, 0x13b0, x86_l_13b0);
x86_l_13a6:
	/* 0x13a6: mov    rcx,r13 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_R13, X86_WIDTH_64, 0, 0);
x86_l_13a9:
	/* 0x13a9: nop    DWORD PTR [rax+0x0] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_13b0:
	/* 0x13b0: mov    r15d,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R15, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13b3:
	/* 0x13b3: xor    r15,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13b6:
	/* 0x13b6: mov    eax,r8d */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_13b9:
	/* 0x13b9: and    eax,0x7 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_13bc:
	/* 0x13bc: lea    ecx,[rax+0x1] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_13bf:
	/* 0x13bf: mov    r11,r15 */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R11, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_13c2:
	/* 0x13c2: shl    r11,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R11, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_13c5:
	/* 0x13c5: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13c7:
	/* 0x13c7: not    cl */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_13c9:
	/* 0x13c9: shr    r15,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 0);
x86_l_13cc:
	/* 0x13cc: shl    eax,0x3 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_13cf:
	/* 0x13cf: mov    ecx,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13d1:
	/* 0x13d1: shl    rdi,cl */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_13d4:
	/* 0x13d4: or     r15,r11 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R11, X86_WIDTH_64, X86_ALU_OR, 0);
x86_l_13d7:
	/* 0x13d7: add    r15,r10 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R15, X86_R10, X86_WIDTH_64, X86_ALU_ADD, 0);
x86_l_13da:
	/* 0x13da: xor    rdi,r15 */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_13dd:
	/* 0x13dd: mov    r10,rdi */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_R10, X86_RDI, X86_WIDTH_64, 0, 0);
x86_l_13e0:
	/* 0x13e0: inc    r8 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_13e3:
	/* 0x13e3: cmp    r8,0x40 */
	X86_VM_RUN_OP(X86_OP_CMP_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, 0, 64ULL);
x86_l_13e7:
	/* 0x13e7: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> */
	X86_VM_X86_JCC(X86_CC_NE, 0x13e7, 0x1180, x86_l_1180);
x86_l_13ed:
	/* 0x13ed: jmp    1404 <tracee_syscall_name_table_lookup_xdp+0x304> */
	X86_VM_X86_JMP(0x13ed, 0x1404, x86_l_1404);
x86_l_13ef:
	/* 0x13ef: mov    eax,eax */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_13f1:
	/* 0x13f1: movabs rcx,0x9e3779b185ebca87 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 11400714785074694791ULL);
x86_l_13fb:
	/* 0x13fb: imul   rax,rcx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_IMUL, 0);
x86_l_13ff:
	/* 0x13ff: xor    r10,rax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_R10, X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1402:
	/* 0x1402: jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0> */
	X86_VM_X86_JMP(0x1402, 0x13e0, x86_l_13e0);
x86_l_1404:
	/* 0x1404: mov    QWORD PTR [rdx],r10 */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1407:
	/* 0x1407: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_140c:
	/* 0x140c: pop    rbx */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_140d:
	/* 0x140d: pop    r12 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R12, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_140f:
	/* 0x140f: pop    r13 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R13, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1411:
	/* 0x1411: pop    r14 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R14, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1413:
	/* 0x1413: pop    r15 */
	X86_VM_RUN_OP(X86_OP_POP, X86_R15, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1415:
	/* 0x1415: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1416:
	/* 0x1416: ret */
	X86_VM_X86_RET();
	return XDP_ABORTED;
}

X86_VM_LICENSE();

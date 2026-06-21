#define X86_SIM_ENABLE_STACK 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_policy_guard_tree_filter_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rsi,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c:
	/* 0xc: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: jbe    16 <cilium_policy_guard_tree_filter_xdp+0x16> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf, 0x16, x86_l_16);
x86_l_11:
	/* 0x11: jmp    17a <cilium_policy_guard_tree_filter_xdp+0x17a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_16:
	/* 0x16: lea    rdi,[rdx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a:
	/* 0x1a: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: ja     11 <cilium_policy_guard_tree_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1d, 0x11, x86_l_11);
x86_l_1f:
	/* 0x1f: lea    r8,[rdx+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_26:
	/* 0x26: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_29:
	/* 0x29: ja     11 <cilium_policy_guard_tree_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_A, 0x29, 0x11, x86_l_11);
x86_l_2b:
	/* 0x2b: cmp    DWORD PTR [rdi],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e:
	/* 0x2e: jne    11 <cilium_policy_guard_tree_filter_xdp+0x11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e, 0x11, x86_l_11);
x86_l_30:
	/* 0x30: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_31:
	/* 0x31: add    rdx,0x1b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 27ULL);
x86_l_35:
	/* 0x35: movabs rdi,0xe7037ed1a0b428db */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 16646288086500911323ULL);
x86_l_3f:
	/* 0x3f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41:
	/* 0x41: jmp    78 <cilium_policy_guard_tree_filter_xdp+0x78> */
	X86_SIM_X86_JMP(0x41, 0x78, x86_l_78);
x86_l_43:
	/* 0x43: shl    r8,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 48ULL);
x86_l_47:
	/* 0x47: xor    rsi,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_XOR);
x86_l_4a:
	/* 0x4a: add    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d:
	/* 0x4d: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_4f:
	/* 0x4f: and    dil,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_AND, 7ULL);
x86_l_53:
	/* 0x53: lea    r8d,[rdi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_57:
	/* 0x57: shlx   rbx,rsi,r8 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RBX, X86_RSI, X86_WIDTH_64, X86_R8, X86_ALU_SHL);
x86_l_5c:
	/* 0x5c: not    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NOT, 0);
x86_l_5f:
	/* 0x5f: shrx   rdi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHR);
x86_l_64:
	/* 0x64: or     rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_67:
	/* 0x67: inc    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6a:
	/* 0x6a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6e:
	/* 0x6e: cmp    rax,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32ULL);
x86_l_72:
	/* 0x72: je     134 <cilium_policy_guard_tree_filter_xdp+0x134> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72, 0x134, x86_l_134);
x86_l_78:
	/* 0x78: movzx  r8d,BYTE PTR [rdx-0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551601ULL);
x86_l_7d:
	/* 0x7d: mov    rsi,QWORD PTR [rdx-0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551609ULL);
x86_l_81:
	/* 0x81: cmp    r8,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 33ULL);
x86_l_85:
	/* 0x85: jb     47 <cilium_policy_guard_tree_filter_xdp+0x47> */
	X86_SIM_X86_JCC(X86_CC_B, 0x85, 0x47, x86_l_47);
x86_l_87:
	/* 0x87: movzx  r9d,BYTE PTR [rdx-0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551602ULL);
x86_l_8c:
	/* 0x8c: test   r9b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R9, X86_WIDTH_8, 1ULL);
x86_l_90:
	/* 0x90: je     f8 <cilium_policy_guard_tree_filter_xdp+0xf8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90, 0xf8, x86_l_f8);
x86_l_92:
	/* 0x92: movzx  r9d,BYTE PTR [rdx-0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551603ULL);
x86_l_97:
	/* 0x97: test   r9b,r9b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_8);
x86_l_9a:
	/* 0x9a: js     ee <cilium_policy_guard_tree_filter_xdp+0xee> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9a, 0xee, x86_l_ee);
x86_l_9c:
	/* 0x9c: movzx  r9d,BYTE PTR [rdx-0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551604ULL);
x86_l_a1:
	/* 0xa1: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_a4:
	/* 0xa4: xor    r10d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7:
	/* 0xa7: cmp    r10b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_8, 17ULL);
x86_l_ab:
	/* 0xab: jb     f4 <cilium_policy_guard_tree_filter_xdp+0xf4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xab, 0xf4, x86_l_f4);
x86_l_ad:
	/* 0xad: movzx  r9d,BYTE PTR [rdx-0xb] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551605ULL);
x86_l_b2:
	/* 0xb2: add    r8b,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_8, X86_ALU_ADD);
x86_l_b5:
	/* 0xb5: cmp    r8b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 191ULL);
x86_l_b9:
	/* 0xb9: ja     103 <cilium_policy_guard_tree_filter_xdp+0x103> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb9, 0x103, x86_l_103);
x86_l_bb:
	/* 0xbb: movzx  r8d,BYTE PTR [rdx-0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551606ULL);
x86_l_c0:
	/* 0xc0: mov    r9d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_32);
x86_l_c3:
	/* 0xc3: and    r9b,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_8, X86_ALU_AND, 24ULL);
x86_l_c7:
	/* 0xc7: cmp    r9b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_8, 16ULL);
x86_l_cb:
	/* 0xcb: jne    10f <cilium_policy_guard_tree_filter_xdp+0x10f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb, 0x10f, x86_l_10f);
x86_l_cd:
	/* 0xcd: movzx  r9d,BYTE PTR [rdx-0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551607ULL);
x86_l_d2:
	/* 0xd2: cmp    r9d,0xaa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 170ULL);
x86_l_d9:
	/* 0xd9: jne    118 <cilium_policy_guard_tree_filter_xdp+0x118> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd9, 0x118, x86_l_118);
x86_l_db:
	/* 0xdb: xor    r8,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_de:
	/* 0xde: shld   r8,rsi,0x7 */
	X86_SIM_RUN_OP(X86_OP_SHLD_IMM, X86_R8, X86_RSI, X86_WIDTH_64, 0, 7ULL);
x86_l_e3:
	/* 0xe3: add    r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e6:
	/* 0xe6: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_e9:
	/* 0xe9: jmp    4d <cilium_policy_guard_tree_filter_xdp+0x4d> */
	X86_SIM_X86_JMP(0xe9, 0x4d, x86_l_4d);
x86_l_ee:
	/* 0xee: shl    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_f2:
	/* 0xf2: jmp    107 <cilium_policy_guard_tree_filter_xdp+0x107> */
	X86_SIM_X86_JMP(0xf2, 0x107, x86_l_107);
x86_l_f4:
	/* 0xf4: shl    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_f8:
	/* 0xf8: add    rsi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_fb:
	/* 0xfb: xor    rsi,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR);
x86_l_fe:
	/* 0xfe: jmp    4d <cilium_policy_guard_tree_filter_xdp+0x4d> */
	X86_SIM_X86_JMP(0xfe, 0x4d, x86_l_4d);
x86_l_103:
	/* 0x103: shl    r9d,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_107:
	/* 0x107: xor    rsi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_64, X86_ALU_XOR);
x86_l_10a:
	/* 0x10a: jmp    4a <cilium_policy_guard_tree_filter_xdp+0x4a> */
	X86_SIM_X86_JMP(0x10a, 0x4a, x86_l_4a);
x86_l_10f:
	/* 0x10f: shl    r8,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_113:
	/* 0x113: add    rsi,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_116:
	/* 0x116: jmp    fb <cilium_policy_guard_tree_filter_xdp+0xfb> */
	X86_SIM_X86_JMP(0x116, 0xfb, x86_l_fb);
x86_l_118:
	/* 0x118: movzx  r8d,BYTE PTR [rdx-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_11d:
	/* 0x11d: mov    r10d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R8, X86_WIDTH_32);
x86_l_120:
	/* 0x120: and    r10b,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_124:
	/* 0x124: cmp    r10b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_8, 1ULL);
x86_l_128:
	/* 0x128: je     43 <cilium_policy_guard_tree_filter_xdp+0x43> */
	X86_SIM_X86_JCC(X86_CC_E, 0x128, 0x43, x86_l_43);
x86_l_12e:
	/* 0x12e: shl    r9,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 40ULL);
x86_l_132:
	/* 0x132: jmp    f8 <cilium_policy_guard_tree_filter_xdp+0xf8> */
	X86_SIM_X86_JMP(0x132, 0xf8, x86_l_f8);
x86_l_134:
	/* 0x134: mov    BYTE PTR [rcx],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137:
	/* 0x137: mov    BYTE PTR [rcx+0x1],bh */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_13a:
	/* 0x13a: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_13c:
	/* 0x13c: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13f:
	/* 0x13f: mov    BYTE PTR [rcx+0x2],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_142:
	/* 0x142: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_144:
	/* 0x144: shr    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_147:
	/* 0x147: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_14a:
	/* 0x14a: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_14d:
	/* 0x14d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_151:
	/* 0x151: mov    BYTE PTR [rcx+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_154:
	/* 0x154: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_157:
	/* 0x157: shr    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_15b:
	/* 0x15b: mov    BYTE PTR [rcx+0x5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_15e:
	/* 0x15e: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_161:
	/* 0x161: shr    rax,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 48ULL);
x86_l_165:
	/* 0x165: mov    BYTE PTR [rcx+0x6],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_168:
	/* 0x168: shr    rbx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_16c:
	/* 0x16c: mov    BYTE PTR [rcx+0x7],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_16f:
	/* 0x16f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_174:
	/* 0x174: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_175:
	/* 0x175: jmp    17a <cilium_policy_guard_tree_filter_xdp+0x17a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_17a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

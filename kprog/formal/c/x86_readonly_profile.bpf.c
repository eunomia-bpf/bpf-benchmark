#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 8U
#define X86_SIM_STACK_VALUE_WORDS(M) M(0)
#include "../../x86/x86_sim_local_bpf.h"

static const __u8 __x86_rodata_0[16] SEC(".rodata.native.0") __attribute__((aligned(16))) = {0x12, 0x83, 0xfe, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x20, 0x31, 0x42, 0x53, 0x64, 0x75, 0x96};
static const char __x86_rodata_metadata[] SEC(".native_lab.rodata") = "{\"version\":1,\"objects\":[{\"proof_section\":\".rodata.native.0\",\"proof_symbol\":\"__x86_rodata_0\",\"native_symbol\":\"section:SectionIndex(4):.rodata:table_0\",\"size\":16}]}";

static __always_inline __u64 __x86_rodata_0_value(__u64 offset, __u8 width)
{
	switch (width) {
	case 1: switch (offset) {
	case 0: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 0, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 1: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 1, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 2: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 2, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 3: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 3, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 4: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 4, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 5: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 5, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 6: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 6, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 7: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 7, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 8: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 8, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 9: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 9, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 10: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 10, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 11: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 11, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 12: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 12, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 13: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 13, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 14: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 14, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 15: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 15, 1);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	} break;
	case 2: switch (offset) {
	case 0: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 0, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 1: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 1, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 2: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 2, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 3: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 3, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 4: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 4, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 5: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 5, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 6: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 6, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 7: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 7, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 8: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 8, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 9: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 9, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 10: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 10, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 11: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 11, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 12: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 12, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 13: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 13, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 14: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 14, 2);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	} break;
	case 4: switch (offset) {
	case 0: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 0, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 1: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 1, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 2: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 2, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 3: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 3, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 4: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 4, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 5: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 5, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 6: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 6, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 7: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 7, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 8: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 8, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 9: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 9, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 10: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 10, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 11: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 11, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 12: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 12, 4);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	} break;
	case 8: switch (offset) {
	case 0: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 0, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 1: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 1, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 2: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 2, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 3: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 3, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 4: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 4, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 5: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 5, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 6: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 6, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 7: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 7, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	case 8: {
		__u64 value = 0;
		KPROG_C_COPY_BYTES(&value, __x86_rodata_0 + 8, 8);
		KPROG_C_VALUE_BARRIER_VAR(value);
		return value;
	}
	} break;
	}
	return KPROG_X86_MEM_LOAD((const __u8 *)__x86_rodata_0 + offset, width);
}

#define X86_SIM_L_NATIVE_DATA_LOAD_DECL(RESULT, BASE, OFF, WIDTH) \
   const void *__x86_ro_base = (BASE); __u64 __x86_ro_off = (OFF); \
   __u8 __x86_ro_width = (WIDTH); __u64 RESULT; \
   if (__builtin_constant_p((__u64)(long)__x86_ro_base - (__u64)(long)__x86_rodata_0)) \
       RESULT = __x86_rodata_0_value((__u64)(long)__x86_ro_base - (__u64)(long)__x86_rodata_0 + __x86_ro_off, __x86_ro_width); else \
       RESULT = KPROG_X86_MEM_LOAD(KPROG_PTR_ADD64_BITS(__x86_ro_base, __x86_ro_off), __x86_ro_width);
#define X86_SIM_L_NATIVE_DATA_LOAD_INTO(OUTPUT, BASE, OFF, WIDTH) \
   do { X86_SIM_L_NATIVE_DATA_LOAD_DECL(__x86_ro_into, BASE, OFF, WIDTH) \
        (OUTPUT) = __x86_ro_into; } while (0)
#undef X86_SIM_L_NATIVE_DATA_LOAD
#define X86_SIM_L_NATIVE_DATA_LOAD(BASE, OFF, WIDTH) \
   ({ X86_SIM_L_NATIVE_DATA_LOAD_DECL(__x86_ro_value, BASE, OFF, WIDTH) \
      __x86_ro_value; })

#include "/workspaces/repository/kprog/x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_REG, X86_OP_ALU_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LEA, X86_OP_LEA)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_POP, X86_OP_POP)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_PUSH, X86_OP_PUSH)

SEC("socket")
int x86_readonly_profile_x86_sim_xdp(void *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	X86_SIM_BIND_INLINE();
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: lea    rax,[rip+0x0] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, ((__u64)(long)((__u8 *)(__x86_rodata_0) + (0))));
x86_l_8:
	/* 0x8: xor    esi,esi */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_a:
	/* 0xa: mov    rcx,QWORD PTR [rax+rsi*1] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_e:
	/* 0xe: movzx  edx,WORD PTR [rax+rsi*1+0x7] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_16), 7ULL);
x86_l_13:
	/* 0x13: xor    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_16:
	/* 0x16: movzx  edx,BYTE PTR [rax+rsi*1+0xf] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 15ULL);
x86_l_1b:
	/* 0x1b: xor    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_1e:
	/* 0x1e: mov    edx,DWORD PTR [rax+rsi*1+0x3] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 3ULL);
x86_l_22:
	/* 0x22: xor    rcx,rdx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_25:
	/* 0x25: mov    rax,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_28:
	/* 0x28: shr    rcx,0x20 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_2c:
	/* 0x2c: xor    eax,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_2e:
	/* 0x2e: pop    rbx */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBX, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_2f:
	/* 0x2f: jmp    34 <x86_readonly_profile+0x34> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_34:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

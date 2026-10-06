// SPDX-License-Identifier: GPL-2.0

#include <errno.h>
#include <linux/bpf.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef int16_t s16;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;

#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

struct bpf_prog_aux {
	bool priv_stack_ptr;
};

struct bpf_prog {
	const struct bpf_prog_aux *aux;
};

#define INSN(CODE, DST, SRC, OFF, IMM) \
	((struct bpf_insn){ .code = (CODE), .dst_reg = (DST), \
		.src_reg = (SRC), .off = (OFF), .imm = (IMM) })
#define BPF_LDX_MEM(SIZE, DST, SRC, OFF) \
	INSN(BPF_LDX | BPF_MEM | (SIZE), DST, SRC, OFF, 0)
#define BPF_STX_MEM(SIZE, DST, SRC, OFF) \
	INSN(BPF_STX | BPF_MEM | (SIZE), DST, SRC, OFF, 0)
#define BPF_MOV64_REG(DST, SRC) INSN(BPF_ALU64 | BPF_MOV | BPF_X, DST, SRC, 0, 0)
#define BPF_MOV32_REG(DST, SRC) INSN(BPF_ALU | BPF_MOV | BPF_X, DST, SRC, 0, 0)
#define BPF_ALU64_IMM(OP, DST, IMM) INSN(BPF_ALU64 | (OP), DST, 0, 0, IMM)
#define BPF_ALU32_IMM(OP, DST, IMM) INSN(BPF_ALU | (OP), DST, 0, 0, IMM)
#define BPF_ALU64_REG(OP, DST, SRC) INSN(BPF_ALU64 | (OP) | BPF_X, DST, SRC, 0, 0)
#define BPF_ALU32_REG(OP, DST, SRC) INSN(BPF_ALU | (OP) | BPF_X, DST, SRC, 0, 0)
#define BPF_JMP_IMM(OP, DST, IMM, OFF) INSN(BPF_JMP | (OP), DST, 0, OFF, IMM)
#define BPF_JMP32_IMM(OP, DST, IMM, OFF) INSN(BPF_JMP32 | (OP), DST, 0, OFF, IMM)
#define BPF_JMP_A(OFF) INSN(BPF_JMP | BPF_JA, 0, 0, OFF, 0)

#define KOP_X86_REG_R9 11
#define KOP_X86_REG_R10 12
#define KOP_X86_REG_R11 13
#define KOP_X86_REG_R12 14
#define KOP_X86_REG_RSP 15

static __always_inline bool kop_payload_wire_escaped(u64 payload)
{
	u8 marker = payload & 0xf;
	u8 original_low = (payload >> 4) & 0xf;

	return marker == BPF_REG_10 && original_low >= 11 && original_low <= 15;
}

static __always_inline u64 kop_payload_decode(u64 payload)
{
	if (!kop_payload_wire_escaped(payload))
		return payload;
	return ((payload >> 8) << 4) | ((payload >> 4) & 0xf);
}

static __always_inline u8 kop_x86_reg_code(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_0:
	case BPF_REG_5:
		return 0;
	case BPF_REG_4:
		return 1;
	case BPF_REG_3:
		return 2;
	case BPF_REG_6:
		return 3;
	case BPF_REG_7:
	case BPF_REG_10:
		return 5;
	case BPF_REG_2:
	case BPF_REG_8:
		return 6;
	case BPF_REG_1:
	case BPF_REG_9:
		return 7;
	case KOP_X86_REG_R9:
		return 1;
	case KOP_X86_REG_R10:
		return 2;
	case KOP_X86_REG_R11:
		return 3;
	case KOP_X86_REG_R12:
	case KOP_X86_REG_RSP:
		return 4;
	default:
		return 0xff;
	}
}

static __always_inline bool kop_x86_reg_ext(u8 bpf_reg)
{
	switch (bpf_reg) {
	case BPF_REG_5:
	case BPF_REG_7:
	case BPF_REG_8:
	case BPF_REG_9:
	case KOP_X86_REG_R9:
	case KOP_X86_REG_R10:
	case KOP_X86_REG_R11:
	case KOP_X86_REG_R12:
		return true;
	default:
		return false;
	}
}

static __always_inline bool kop_x86_reg_valid(u8 bpf_reg)
{
	return kop_x86_reg_code(bpf_reg) != 0xff;
}

#define _KOP_COMMON_H
#define __bpf_kfunc_start_defs()
#define __bpf_kfunc
#define __bpf_kfunc_end_defs()
#define BTF_KFUNCS_START(NAME)
#define BTF_ID_FLAGS(KIND, NAME)
#define BTF_KFUNCS_END(NAME)
#define THIS_MODULE NULL
#define DEFINE_KOP_V2_MODULE(PREFIX, DESC, KFUNC_IDS, KOP_DESC_ARRAY)

struct bpf_kop {
	void *owner;
	int max_insn_cnt;
	int max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload,
			const struct bpf_prog *prog, const u8 *final_ip);
};

#include "../../../kinsn/module/x86/bpf_x86_rotate.c"

static u64 rotate_imm_payload(u8 form, u8 dst_reg, u8 src_reg, u8 shift)
{
	return (u64)form | ((u64)dst_reg << 4) | ((u64)src_reg << 8) |
	       ((u64)shift << 12);
}

static u64 rotate_rr_payload(u8 form, u8 dst_reg, u8 cnt_reg)
{
	return (u64)form | ((u64)dst_reg << 4) | ((u64)cnt_reg << 8);
}

static void require_true(bool condition, const char *message)
{
	if (!condition) {
		fprintf(stderr, "%s\n", message);
		exit(1);
	}
}

static void require_int(const char *name, int actual, int expected)
{
	if (actual != expected) {
		fprintf(stderr, "%s: got %d expected %d\n", name, actual,
			expected);
		exit(1);
	}
}

static void require_bytes(const char *name, const u8 *actual,
			  const u8 *expected, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++) {
		if (actual[i] == expected[i])
			continue;
		fprintf(stderr, "%s[%zu]: got 0x%02x expected 0x%02x\n",
			name, i, actual[i], expected[i]);
		exit(1);
	}
}

static void test_emit_rol_imm_widths(void)
{
	const u8 expected_rolq[] = { 0x48, 0xc1, 0xc0, 13 };
	const u8 expected_roll[] = { 0xc1, 0xc0, 13 };
	u8 image[8] = {};
	u32 off = 0;
	int len;

	len = emit_rolq_x86(image, &off, true,
			    rotate_imm_payload(X86_ROTATE_FORM_IMM,
					       BPF_REG_0, BPF_REG_0, 13),
			    NULL, NULL);
	require_int("rolq imm len", len, sizeof(expected_rolq));
	require_int("rolq imm off", off, sizeof(expected_rolq));
	require_bytes("rolq imm bytes", image, expected_rolq,
		      sizeof(expected_rolq));

	memset(image, 0, sizeof(image));
	off = 0;
	len = emit_roll_x86(image, &off, true,
			    rotate_imm_payload(X86_ROTATE_FORM_IMM,
					       BPF_REG_0, BPF_REG_0, 13),
			    NULL, NULL);
	require_int("roll imm len", len, sizeof(expected_roll));
	require_int("roll imm off", off, sizeof(expected_roll));
	require_bytes("roll imm bytes", image, expected_roll,
		      sizeof(expected_roll));

	off = 0;
	len = emit_rolq_x86(NULL, &off, false,
			    rotate_imm_payload(X86_ROTATE_FORM_IMM,
					       BPF_REG_0, BPF_REG_0, 13),
			    NULL, NULL);
	require_int("rolq sizing len", len, sizeof(expected_rolq));
	require_int("rolq sizing off", off, sizeof(expected_rolq));
}

static void test_emit_rol_cl_widths(void)
{
	const u8 expected_rolq[] = { 0x48, 0xd3, 0xc0 };
	const u8 expected_roll[] = { 0xd3, 0xc0 };
	u8 image[8] = {};
	u32 off = 0;
	int len;

	len = emit_rolq_x86(image, &off, true,
			    rotate_rr_payload(X86_ROTATE_FORM_RR,
					      BPF_REG_0, BPF_REG_4),
			    NULL, NULL);
	require_int("rolq cl len", len, sizeof(expected_rolq));
	require_int("rolq cl off", off, sizeof(expected_rolq));
	require_bytes("rolq cl bytes", image, expected_rolq,
		      sizeof(expected_rolq));

	memset(image, 0, sizeof(image));
	off = 0;
	len = emit_roll_x86(image, &off, true,
			    rotate_rr_payload(X86_ROTATE_FORM_RR,
					      BPF_REG_0, BPF_REG_4),
			    NULL, NULL);
	require_int("roll cl len", len, sizeof(expected_roll));
	require_int("roll cl off", off, sizeof(expected_roll));
	require_bytes("roll cl bytes", image, expected_roll,
		      sizeof(expected_roll));
}

static void test_emit_rorxl_keeps_distinct_src(void)
{
	const u8 expected[] = { 0xc4, 0xe3, 0x7b, 0xf0, 0xc7, 24 };
	u8 image[8] = {};
	u32 off = 0;
	int len;

	len = emit_rotate32_x86(image, &off, true,
				rotate_imm_payload(X86_ROTATE_FORM_IMM,
						   BPF_REG_0, BPF_REG_1, 8),
				NULL, NULL);
	require_int("rorxl len", len, sizeof(expected));
	require_int("rorxl off", off, sizeof(expected));
	require_bytes("rorxl bytes", image, expected, sizeof(expected));
}

/* Execute the real instruction ABI against an independent rotate oracle.
 * This catches wrong signed-branch widths, missed wrap bits, CL aliasing, and
 * writes to other registers without depending on a scratch-register layout.
 */
static void execute_rotate(const struct bpf_insn *insns, int count, u64 regs[16])
{
	for (int pc = 0, steps = 0; pc < count; pc++, steps++) {
		const struct bpf_insn *insn = &insns[pc];
		u8 cls = BPF_CLASS(insn->code), op = BPF_OP(insn->code);
		u64 value = regs[insn->dst_reg];
		u64 rhs = BPF_SRC(insn->code) == BPF_X ?
			regs[insn->src_reg] : (u64)(int64_t)insn->imm;

		require_true(steps < count, "rotate expansion did not terminate");
		if (cls == BPF_ALU || cls == BPF_ALU64) {
			if (cls == BPF_ALU)
				value = (u32)value;
			switch (op) {
			case BPF_MOV: value = rhs; break;
			case BPF_LSH:
				require_true(rhs < (cls == BPF_ALU ? 32U : 64U),
					     "rotate expansion has an out-of-range shift");
				value <<= rhs;
				break;
			case BPF_OR: value |= rhs; break;
			default: require_true(false, "unsupported rotate ALU opcode");
			}
			regs[insn->dst_reg] = cls == BPF_ALU ? (u32)value : value;
		} else if (cls == BPF_JMP || cls == BPF_JMP32) {
			bool taken = false;

			switch (op) {
			case BPF_JA: taken = true; break;
			case BPF_JSET: taken = (value & rhs) != 0; break;
			case BPF_JSLT:
				taken = cls == BPF_JMP32 ? (s32)value < (s32)rhs :
					(int64_t)value < (int64_t)rhs;
				break;
			default: require_true(false, "unsupported rotate jump opcode");
			}
			if (taken) {
				require_true(insn->off >= 0 && pc + insn->off < count,
					     "rotate expansion jumps outside its bytecode");
				pc += insn->off;
			}
		} else {
			require_true(false, "unsupported rotate instruction class");
		}
	}
}

static void test_instantiate_rol_cl_widths(void)
{
	const u64 values[] = { 0, 1, 0x80000000ULL, 1ULL << 63,
			      UINT64_MAX, 0x0123456789abcdefULL };
	const u8 destinations[] = { BPF_REG_0, BPF_REG_4, BPF_REG_5 };
	const struct bpf_kop *descs[] = { &bpf_x86_roll_desc, &bpf_x86_rolq_desc };

	for (size_t w = 0; w < 2; w++) {
		const struct bpf_kop *desc = descs[w];
		unsigned width = w ? 64 : 32;
		u64 mask = w ? UINT64_MAX : UINT32_MAX;
		struct bpf_insn *insns = calloc(desc->max_insn_cnt + 1, sizeof(*insns));

		require_true(insns != NULL, "cannot allocate rotate bytecode");
		for (size_t d = 0; d < sizeof(destinations); d++) {
			u8 dst = destinations[d];
			int count = desc->instantiate_insn(
				rotate_rr_payload(X86_ROTATE_FORM_RR, dst, BPF_REG_4), insns);

			require_true(count > 0, "rotate payload was rejected");
			require_true(count <= desc->max_insn_cnt,
				     "rotate expansion exceeds its registered capacity");
			require_true(insns[desc->max_insn_cnt].code == 0,
				     "rotate expansion overwrote its capacity guard");
			for (size_t v = 0; v < sizeof(values) / sizeof(values[0]); v++) {
				for (unsigned cl = 0; cl < 256; cl++) {
					u64 regs[16], before[16];
					unsigned shift = cl & (width - 1);
					u64 value, want;

					for (unsigned r = 0; r < 16; r++)
						regs[r] = 0xfedcba9876543200ULL + r;
					regs[dst] = values[v];
					regs[BPF_REG_4] = (regs[BPF_REG_4] & ~0xffULL) | cl;
					memcpy(before, regs, sizeof(regs));
					value = regs[dst] & mask;
					want = shift ? ((value << shift) |
						(value >> (width - shift))) & mask : value;
					execute_rotate(insns, count, regs);
					require_true(regs[dst] == want, "rotate result differs from oracle");
					for (unsigned r = 0; r < 16; r++)
						require_true(r == dst || regs[r] == before[r],
							     "rotate changed another register");
				}
			}
		}
		free(insns);
	}
}

int main(void)
{
	test_emit_rol_imm_widths();
	test_emit_rol_cl_widths();
	test_emit_rorxl_keeps_distinct_src();
	test_instantiate_rol_cl_widths();
	return 0;
}

// SPDX-License-Identifier: GPL-2.0

#include <errno.h>
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

#define BPF_REG_0 0
#define BPF_REG_1 1
#define BPF_REG_2 2
#define BPF_REG_3 3
#define BPF_REG_4 4
#define BPF_REG_5 5
#define BPF_REG_6 6
#define BPF_REG_7 7
#define BPF_REG_8 8
#define BPF_REG_9 9
#define BPF_REG_10 10

#define BPF_DW 8
#define BPF_AND 1
#define BPF_LSH 2
#define BPF_RSH 3
#define BPF_NEG 4
#define BPF_OR 5

enum test_bpf_code {
	TEST_BPF_LDX_MEM = 1,
	TEST_BPF_STX_MEM = 2,
	TEST_BPF_MOV64_REG = 3,
	TEST_BPF_MOV32_REG = 4,
	TEST_BPF_ALU64_IMM = 5,
	TEST_BPF_ALU32_IMM = 6,
	TEST_BPF_ALU64_REG = 7,
	TEST_BPF_ALU32_REG = 8,
};

struct bpf_insn {
	u8 code;
	u8 dst_reg;
	u8 src_reg;
	s16 off;
	s32 imm;
};

struct bpf_prog;

#define BPF_LDX_MEM(SIZE, DST, SRC, OFF) \
	((struct bpf_insn){ TEST_BPF_LDX_MEM, (DST), (SRC), (OFF), (SIZE) })
#define BPF_STX_MEM(SIZE, DST, SRC, OFF) \
	((struct bpf_insn){ TEST_BPF_STX_MEM, (DST), (SRC), (OFF), (SIZE) })
#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){ TEST_BPF_MOV64_REG, (DST), (SRC), 0, 0 })
#define BPF_MOV32_REG(DST, SRC) \
	((struct bpf_insn){ TEST_BPF_MOV32_REG, (DST), (SRC), 0, 0 })
#define BPF_ALU64_IMM(OP, DST, IMM) \
	((struct bpf_insn){ TEST_BPF_ALU64_IMM, (DST), (OP), 0, (IMM) })
#define BPF_ALU32_IMM(OP, DST, IMM) \
	((struct bpf_insn){ TEST_BPF_ALU32_IMM, (DST), (OP), 0, (IMM) })
#define BPF_ALU64_REG(OP, DST, SRC) \
	((struct bpf_insn){ TEST_BPF_ALU64_REG, (DST), (SRC), (OP), 0 })
#define BPF_ALU32_REG(OP, DST, SRC) \
	((struct bpf_insn){ TEST_BPF_ALU32_REG, (DST), (SRC), (OP), 0 })

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
			const struct bpf_prog *prog);
};

#include "../../../module/x86/bpf_x86_rotate.c"

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

static int count_alu_imm(const struct bpf_insn *insns, int count, u8 code,
			 u8 op, s32 imm)
{
	int matches = 0;
	int i;

	for (i = 0; i < count; i++) {
		if (insns[i].code == code && insns[i].src_reg == op &&
		    insns[i].imm == imm)
			matches++;
	}
	return matches;
}

static bool has_mov(const struct bpf_insn *insns, int count, u8 code,
		    u8 dst_reg, u8 src_reg)
{
	int i;

	for (i = 0; i < count; i++) {
		if (insns[i].code == code && insns[i].dst_reg == dst_reg &&
		    insns[i].src_reg == src_reg)
			return true;
	}
	return false;
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
			    NULL);
	require_int("rolq imm len", len, sizeof(expected_rolq));
	require_int("rolq imm off", off, sizeof(expected_rolq));
	require_bytes("rolq imm bytes", image, expected_rolq,
		      sizeof(expected_rolq));

	memset(image, 0, sizeof(image));
	off = 0;
	len = emit_roll_x86(image, &off, true,
			    rotate_imm_payload(X86_ROTATE_FORM_IMM,
					       BPF_REG_0, BPF_REG_0, 13),
			    NULL);
	require_int("roll imm len", len, sizeof(expected_roll));
	require_int("roll imm off", off, sizeof(expected_roll));
	require_bytes("roll imm bytes", image, expected_roll,
		      sizeof(expected_roll));

	off = 0;
	len = emit_rolq_x86(NULL, &off, false,
			    rotate_imm_payload(X86_ROTATE_FORM_IMM,
					       BPF_REG_0, BPF_REG_0, 13),
			    NULL);
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
			    NULL);
	require_int("rolq cl len", len, sizeof(expected_rolq));
	require_int("rolq cl off", off, sizeof(expected_rolq));
	require_bytes("rolq cl bytes", image, expected_rolq,
		      sizeof(expected_rolq));

	memset(image, 0, sizeof(image));
	off = 0;
	len = emit_roll_x86(image, &off, true,
			    rotate_rr_payload(X86_ROTATE_FORM_RR,
					      BPF_REG_0, BPF_REG_4),
			    NULL);
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
				NULL);
	require_int("rorxl len", len, sizeof(expected));
	require_int("rorxl off", off, sizeof(expected));
	require_bytes("rorxl bytes", image, expected, sizeof(expected));
}

static void test_instantiate_rol_cl_widths(void)
{
	struct bpf_insn insns[64];
	u64 payload = rotate_rr_payload(X86_ROTATE_FORM_RR, BPF_REG_0,
					BPF_REG_4);
	int count;

	memset(insns, 0, sizeof(insns));
	count = instantiate_rolq(payload, insns);
	require_true(count > 0, "instantiate rolq cl failed");
	require_int("rolq cl and-mask count",
		    count_alu_imm(insns, count, TEST_BPF_ALU64_IMM, BPF_AND,
				  63),
		    2);
	require_int("rolq cl wrong-width and-mask count",
		    count_alu_imm(insns, count, TEST_BPF_ALU32_IMM, BPF_AND,
				  31),
		    0);
	require_true(has_mov(insns, count, TEST_BPF_MOV64_REG,
			     KOP_X86_SCRATCH1, BPF_REG_4),
		     "rolq cl did not read count as 64-bit");

	memset(insns, 0, sizeof(insns));
	count = instantiate_roll(payload, insns);
	require_true(count > 0, "instantiate roll cl failed");
	require_int("roll cl and-mask count",
		    count_alu_imm(insns, count, TEST_BPF_ALU32_IMM, BPF_AND,
				  31),
		    2);
	require_int("roll cl wrong-width and-mask count",
		    count_alu_imm(insns, count, TEST_BPF_ALU64_IMM, BPF_AND,
				  63),
		    0);
	require_true(has_mov(insns, count, TEST_BPF_MOV32_REG,
			     KOP_X86_SCRATCH1, BPF_REG_4),
		     "roll cl did not read count as 32-bit");
}

int main(void)
{
	test_emit_rol_imm_widths();
	test_emit_rol_cl_widths();
	test_emit_rorxl_keeps_distinct_src();
	test_instantiate_rol_cl_widths();
	return 0;
}

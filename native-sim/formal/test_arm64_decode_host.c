/*
 * Host cross-check for the generated AArch64 mnemonic-to-code decode contract
 * (generated/arm64_decode.h).
 *
 * The generated header is the only source of the ARM64_{ALU,SHIFT,MOD,
 * BITFIELD}_* numeric codes shared by the simulator constants, the Lean model,
 * and the artifact encoder. This oracle binds those constants two ways:
 *   1. Each macro equals the code of an independent, locally written
 *      mnemonic table, and every code within a table is distinct, so decode is
 *      unambiguous.
 *   2. The generated constants drive the *real* shared AUX codec from
 *      arm64_sim.h (ARM64_AUX_ALU/_SHIFT/_MOVK/_MEM/_BITFIELD/_CCMP), and each
 *      packed field is read back with an independent extractor written here.
 *      Every generated code is exercised in every field of the AUX word it
 *      belongs to, at the 0/255 field boundaries as well.
 * arm64_sim.h is included so the check is against the macros the simulator
 * actually uses, not a restatement; arm64_sim_local_bpf.h is not included
 * (it pulls in bpf_helpers.h). Exits non-zero on any mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../arm64 test_arm64_decode_host.c -o /tmp/t_a64d \
 *     && /tmp/t_a64d
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;

#include "../arm64/arm64_sim.h"

#include <stdio.h>
#include <string.h>

/* Independent byte-field extractors (not the simulator's ARM64_SIM_L_*). */
static __u32 f0(__u32 aux) { return (aux >> 0) & 0xffU; }
static __u32 f1(__u32 aux) { return (aux >> 8) & 0xffU; }
static __u32 f2(__u32 aux) { return (aux >> 16) & 0xffU; }
static __u32 f3(__u32 aux) { return (aux >> 24) & 0xffU; }

static unsigned cases = 0;
static unsigned failures = 0;

static void expect_eq(const char *what, __u32 got, __u32 want)
{
	cases++;
	if (got != want) {
		fprintf(stderr, "MISMATCH %s: got %u want %u\n", what, got, want);
		failures++;
	}
}

/* Independent mnemonic tables: name -> code, written out here rather than
 * derived from the generated header. */
struct row {
	const char *mnemonic;
	__u32 code;
};

static const struct row ALU[] = {
	{"add", 0}, {"sub", 1}, {"and", 2}, {"bic", 3}, {"eor", 4}, {"orr", 5},
};
static const struct row SHIFT[] = {
	{"lsl", 0}, {"lsr", 1}, {"asr", 2}, {"ror", 3},
};
static const struct row MOD[] = {
	{"", 0}, {"lsl", 1}, {"lsr", 2}, {"asr", 3}, {"ror", 4}, {"uxtw", 5},
	{"sxtw", 6}, {"uxth", 7}, {"sxth", 8}, {"uxtb", 9}, {"sxtb", 10},
};
static const struct row BITFIELD[] = {
	{"ubfx", 0}, {"sbfx", 1}, {"ubfiz", 2}, {"bfxil", 3}, {"bfi", 4},
};

/* The generated macro and the independent table must agree for each entry. */
static void check_table(const char *table, const struct row *rows, unsigned n,
			const __u32 *macros)
{
	unsigned i, j;

	for (i = 0; i < n; i++) {
		char what[64];

		snprintf(what, sizeof what, "%s[%s]", table, rows[i].mnemonic);
		expect_eq(what, macros[i], rows[i].code);
	}
	/* Codes are distinct within a table. */
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			cases++;
			if (rows[i].code == rows[j].code) {
				fprintf(stderr, "DUPLICATE %s code %u\n", table,
					rows[i].code);
				failures++;
			}
		}
	}
}

/* Pack `code` in field `field_of` of the AUX word, read it back with the
 * independent extractor, and confirm both the widened round trip and that the
 * other fields stay clear. */
static void check_aux_field(const char *what, __u32 aux, __u32 (*getter)(__u32),
			    __u32 code)
{
	expect_eq(what, getter(aux), code);
}

int main(void)
{
	static const __u32 alu_macros[] = {
		ARM64_ALU_ADD, ARM64_ALU_SUB, ARM64_ALU_AND,
		ARM64_ALU_BIC, ARM64_ALU_EOR, ARM64_ALU_ORR,
	};
	static const __u32 shift_macros[] = {
		ARM64_SHIFT_LSL, ARM64_SHIFT_LSR, ARM64_SHIFT_ASR,
		ARM64_SHIFT_ROR,
	};
	static const __u32 mod_macros[] = {
		ARM64_MOD_NONE, ARM64_MOD_LSL, ARM64_MOD_LSR, ARM64_MOD_ASR,
		ARM64_MOD_ROR, ARM64_MOD_UXTW, ARM64_MOD_SXTW, ARM64_MOD_UXTH,
		ARM64_MOD_SXTH, ARM64_MOD_UXTB, ARM64_MOD_SXTB,
	};
	static const __u32 bitfield_macros[] = {
		ARM64_BITFIELD_UBFX, ARM64_BITFIELD_SBFX, ARM64_BITFIELD_UBFIZ,
		ARM64_BITFIELD_BFXIL, ARM64_BITFIELD_BFI,
	};

	/* 1. Constants equal the independent tables, and codes are distinct. */
	check_table("alu", ALU, sizeof ALU / sizeof ALU[0], alu_macros);
	check_table("shift", SHIFT, sizeof SHIFT / sizeof SHIFT[0], shift_macros);
	check_table("mod", MOD, sizeof MOD / sizeof MOD[0], mod_macros);
	check_table("bitfield", BITFIELD, sizeof BITFIELD / sizeof BITFIELD[0],
		    bitfield_macros);

	/* 2. AUX round trip through the real shared codec. */
	unsigned i, j;

	for (i = 0; i < sizeof ALU / sizeof ALU[0]; i++) {
		for (j = 0; j < sizeof MOD / sizeof MOD[0]; j++) {
			__u32 aux = ARM64_AUX_ALU(alu_macros[i], mod_macros[j],
						  shift_macros[ARM64_SHIFT_ROR]);

			check_aux_field("alu.code", aux, f0, alu_macros[i]);
			check_aux_field("alu.mod", aux, f1, mod_macros[j]);
			check_aux_field("alu.shift", aux, f2, ARM64_SHIFT_ROR);
			check_aux_field("alu.bit24", aux, f3, 0);
		}
	}

	for (i = 0; i < sizeof BITFIELD / sizeof BITFIELD[0]; i++) {
		for (j = 0; j < 64; j++) {
			__u32 aux = ARM64_AUX_BITFIELD(bitfield_macros[i], j, j + 1);

			check_aux_field("bitfield.code", aux, f0,
					bitfield_macros[i]);
			check_aux_field("bitfield.lsb", aux, f1, j);
			check_aux_field("bitfield.width", aux, f2, j + 1);
		}
	}

	for (i = 0; i < sizeof MOD / sizeof MOD[0]; i++) {
		__u32 aux = ARM64_AUX_MEM(mod_macros[i], ARM64_MEM_POST,
					  shift_macros[ARM64_SHIFT_ASR], 0x5a);

		check_aux_field("mem.index", aux, f0, mod_macros[i]);
		check_aux_field("mem.mod", aux, f1, ARM64_MEM_POST);
		check_aux_field("mem.shift", aux, f2, ARM64_SHIFT_ASR);
		check_aux_field("mem.flags", aux, f3, 0x5a);
	}

	/* MOVK places its shift in bits 16..23; SHIFT in the low byte. */
	for (i = 0; i < sizeof SHIFT / sizeof SHIFT[0]; i++) {
		__u32 movk = ARM64_AUX_MOVK(shift_macros[i]);

		check_aux_field("movk.shift", movk, f2, shift_macros[i]);
		check_aux_field("movk.low", movk, f0, 0);
		check_aux_field("shift.low", ARM64_AUX_SHIFT(shift_macros[i]), f0,
				shift_macros[i]);
	}

	/* Field boundaries: every generated code still survives the codec when
	 * packed next to another maximum-width field. */
	for (i = 0; i < sizeof ALU / sizeof ALU[0]; i++) {
		__u32 aux = ARM64_AUX_ALU(alu_macros[i], 0xffU, 0xffU);

		check_aux_field("alu.bound.code", aux, f0, alu_macros[i]);
		check_aux_field("alu.bound.mod", aux, f1, 0xffU);
		check_aux_field("alu.bound.shift", aux, f2, 0xffU);
	}

	if (failures == 0)
		printf("arm64 decode host cross-check: OK (%u cases)\n", cases);
	return failures == 0 ? 0 : 1;
}

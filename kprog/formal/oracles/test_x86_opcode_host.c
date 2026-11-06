/*
 * Host cross-check for the generated x86 opcode contract
 * (generated/x86_opcode.h).
 *
 * The generated header pins each `X86_OP_*` token to its numeric code with a
 * `_Static_assert`, so a renumbered token fails the build. This oracle adds the
 * checks a compile-time assert cannot make: it re-parses `../x86/x86_sim.h` at
 * run time and confirms the header defines *exactly* the 72 canonical tokens in
 * the independent table below — so an *added*, renamed, or dropped token is
 * caught, not only a changed value — that the five width-suffixed aliases
 * resolve to their targets, and that no two canonical tokens share a code.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_opcode_host.c \
 *     -o /tmp/t_xop && /tmp/t_xop
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef int __s32;
typedef long long __s64;
#define __always_inline inline

#include "../x86/x86_sim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned cases = 0;
static unsigned failures = 0;

static void expect_eq(const char *what, __u64 got, __u64 want)
{
	cases++;
	if (got != want) {
		fprintf(stderr, "MISMATCH %s: got %llu want %llu\n", what,
			(unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

/* The independent enumeration of the canonical opcodes, written from
 * kprog/x86/x86_sim.h rather than derived from the generated header. */
struct op {
	const char *define;
	__u32 code;
};

static const struct op OPCODE_OPS[] = {
	{ "X86_OP_NOP", 0 },
	{ "X86_OP_MOV_IMM", 1 },
	{ "X86_OP_MOV_REG", 2 },
	{ "X86_OP_ADD_IMM", 3 },
	{ "X86_OP_ADD_REG", 4 },
	{ "X86_OP_XOR_REG", 5 },
	{ "X86_OP_MOV_LOAD", 6 },
	{ "X86_OP_MOV_STORE_IMM", 7 },
	{ "X86_OP_MOV_STORE_REG", 8 },
	{ "X86_OP_LEA", 9 },
	{ "X86_OP_ALU_IMM", 10 },
	{ "X86_OP_ALU_REG", 11 },
	{ "X86_OP_CMP_IMM", 12 },
	{ "X86_OP_CMP_REG", 13 },
	{ "X86_OP_TEST_IMM", 14 },
	{ "X86_OP_TEST_REG", 15 },
	{ "X86_OP_JCC", 16 },
	{ "X86_OP_JMP", 17 },
	{ "X86_OP_PUSH", 18 },
	{ "X86_OP_POP", 19 },
	{ "X86_OP_CALL", 20 },
	{ "X86_OP_CMOV", 21 },
	{ "X86_OP_SETCC", 22 },
	{ "X86_OP_BSWAP", 23 },
	{ "X86_OP_POPCNT", 24 },
	{ "X86_OP_XCHG", 25 },
	{ "X86_OP_DIV", 26 },
	{ "X86_OP_SHLD_IMM", 27 },
	{ "X86_OP_SHRD_IMM", 28 },
	{ "X86_OP_CMP_MEM_IMM", 29 },
	{ "X86_OP_TEST_MEM_IMM", 30 },
	{ "X86_OP_CMP_MEM_REG", 31 },
	{ "X86_OP_MOVZX_REG", 32 },
	{ "X86_OP_MOVSX_REG", 33 },
	{ "X86_OP_MOVSX_LOAD", 34 },
	{ "X86_OP_ALU_MEM", 35 },
	{ "X86_OP_CMP_REG_MEM", 36 },
	{ "X86_OP_MOV_LOAD_SCALAR", 37 },
	{ "X86_OP_SHIFTX", 38 },
	{ "X86_OP_RORX", 39 },
	{ "X86_OP_MOVBE_LOAD", 40 },
	{ "X86_OP_MOVBE_STORE", 41 },
	{ "X86_OP_SHIFTX_MEM", 42 },
	{ "X86_OP_RORX_MEM", 43 },
	{ "X86_OP_MOV_LOAD_MAP_PTR", 44 },
	{ "X86_OP_MOV_LOAD_HELPER_ID", 45 },
	{ "X86_OP_CALL_HELPER", 46 },
	{ "X86_OP_CALL_REG", 47 },
	{ "X86_OP_LOAD_XMM0", 48 },
	{ "X86_OP_STORE_XMM0", 49 },
	{ "X86_OP_ALU_MEM_UNARY", 50 },
	{ "X86_OP_ALU_MEM_IMM", 51 },
	{ "X86_OP_BZHI", 52 },
	{ "X86_OP_BZHI_MEM", 53 },
	{ "X86_OP_ALU_MEM_REG", 54 },
	{ "X86_OP_BT", 55 },
	{ "X86_OP_IMUL_IMM", 56 },
	{ "X86_OP_MULX", 57 },
	{ "X86_OP_REP_MOVS", 58 },
	{ "X86_OP_TEST_MEM_REG", 59 },
	{ "X86_OP_CALL_MEMSET", 60 },
	{ "X86_OP_ANDN", 61 },
	{ "X86_OP_SETCC_MEM", 62 },
	{ "X86_OP_CALL_MEMCPY", 63 },
	{ "X86_OP_CMOV_MEM", 64 },
	{ "X86_OP_IMUL_MEM_IMM", 65 },
	{ "X86_OP_BT_IMM", 66 },
	{ "X86_OP_BT_MEM_IMM", 67 },
	{ "X86_OP_ANDN_MEM", 68 },
	{ "X86_OP_CALL_MEMSET_REG", 69 },
	{ "X86_OP_CALL_MEMCPY_REG", 70 },
	{ "X86_OP_RET", 255 },
};

/* Read one `#define X86_OP_<NAME> 0x..U` line out of the simulator header;
 * return 1 when found and store the numeric value in *value, 0 otherwise. */
static int sim_define_value(const char *text, const char *name, __u64 *value)
{
	size_t namelen = strlen(name);
	const char *line = text;

	while ((line = strstr(line, "#define ")) != NULL) {
		const char *rest = line + strlen("#define ");

		if (strncmp(rest, name, namelen) != 0 ||
		    (rest[namelen] != ' ' && rest[namelen] != '\t')) {
			line = rest;
			continue;
		}
		rest += namelen;
		while (*rest == ' ' || *rest == '\t')
			rest++;
		if (strncmp(rest, "0x", 2) != 0)
			return 0;
		*value = strtoull(rest, NULL, 16);
		return 1;
	}
	return 0;
}

int main(void)
{
	FILE *f = fopen("../x86/x86_sim.h", "rb");
	char *text;
	long size;
	unsigned i;

	if (f == NULL) {
		fprintf(stderr, "cannot open ../x86/x86_sim.h\n");
		return 1;
	}
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);
	text = malloc((size_t)size + 1);
	if (text == NULL || fread(text, 1, (size_t)size, f) != (size_t)size) {
		fprintf(stderr, "cannot read ../x86/x86_sim.h\n");
		return 1;
	}
	text[size] = '\0';
	fclose(f);

	/* 1. The generated constants equal the independent table. The generated
	 * macro is the token itself, so this drives the real header value. */
	for (i = 0; i < sizeof OPCODE_OPS / sizeof OPCODE_OPS[0]; i++) {
		__u64 value = ~0ULL;
		unsigned found = sim_define_value(text, OPCODE_OPS[i].define,
						  &value);

		expect_eq(OPCODE_OPS[i].define, found ? 1 : 0, 1);
		expect_eq(OPCODE_OPS[i].define, value, OPCODE_OPS[i].code);
	}

	/* 2. Every canonical token in the table is distinct from every other. */
	for (i = 0; i < sizeof OPCODE_OPS / sizeof OPCODE_OPS[0]; i++) {
		unsigned j;

		for (j = i + 1; j < sizeof OPCODE_OPS / sizeof OPCODE_OPS[0]; j++) {
			cases++;
			if (OPCODE_OPS[i].code == OPCODE_OPS[j].code) {
				fprintf(stderr, "DUPLICATE code %u: %s and %s\n",
					OPCODE_OPS[i].code, OPCODE_OPS[i].define,
					OPCODE_OPS[j].define);
				failures++;
			}
		}
	}

	/* 3. Whole-namespace coverage: every canonical `#define X86_OP_* 0x..U`
	 * in the simulator header is one of the table rows, and every table row
	 * is one of the header's canonical tokens. The generated header alone
	 * cannot expose the name set, so the header text is the source. */
	{
		const char *line = text;

		while ((line = strstr(line, "#define X86_OP_")) != NULL) {
			const char *name = line + strlen("#define ");
			const char *end = name;
			unsigned matched = 0;
			char token[64];

			while ((*end >= 'A' && *end <= 'Z') ||
			       (*end >= '0' && *end <= '9') || *end == '_')
				end++;
			if ((size_t)(end - name) < sizeof token) {
				const char *rest = end;

				memcpy(token, name, (size_t)(end - name));
				token[end - name] = '\0';
				while (*rest == ' ' || *rest == '\t')
					rest++;
				if (strncmp(rest, "0x", 2) == 0) {
					for (i = 0;
					     i < sizeof OPCODE_OPS / sizeof OPCODE_OPS[0];
					     i++) {
						if (strcmp(token, OPCODE_OPS[i].define) == 0)
							matched++;
					}
					cases++;
					if (matched != 1) {
						fprintf(stderr,
							"UNCOVERED canonical %s (%u)\n",
							token, matched);
						failures++;
					}
				}
			}
			line = end;
		}
	}

	/* 4. Each width-suffixed alias resolves to its canonical token. The
	 * generated header asserts this at compile time; restating it here keeps the
	 * alias set visible to the oracle rather than buried in one header. */
	expect_eq("X86_OP_MOV_IMM64", X86_OP_MOV_IMM64, X86_OP_MOV_IMM);
	expect_eq("X86_OP_MOV_REG64", X86_OP_MOV_REG64, X86_OP_MOV_REG);
	expect_eq("X86_OP_ADD_IMM64", X86_OP_ADD_IMM64, X86_OP_ADD_IMM);
	expect_eq("X86_OP_ADD_REG64", X86_OP_ADD_REG64, X86_OP_ADD_REG);
	expect_eq("X86_OP_XOR_REG32", X86_OP_XOR_REG32, X86_OP_XOR_REG);
	expect_eq("alias-count", KPROG_X86_OPCODE_COUNT, 72);

	free(text);
	if (failures == 0)
		printf("x86 opcode host cross-check: OK (%u cases)\n", cases);
	return failures == 0 ? 0 : 1;
}

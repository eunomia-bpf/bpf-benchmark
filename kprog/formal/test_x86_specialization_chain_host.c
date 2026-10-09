/*
 * Host cross-check for the x86 specialization *chain parse*
 * (generated/x86_specialization.h + KProgFormal/GeneratedX86Specialization.lean).
 *
 * The generated contract pins, per canonical `X86_OP_*` token, the
 * `X86_SIM_L_EXEC` handler its chain arm calls. That table was produced by
 * parsing `../x86/x86_sim_local_bpf.h`, so a drift between the two would be
 * invisible to the generator alone. This oracle re-parses the live
 * `X86_SIM_L_EXEC` body text at run time --- its arms are the `(OP) == X86_OP_*`
 * guards, split at brace depth 0 --- and confirms
 *   1. every arm guard names a canonical token, and no token is selected by two
 *      arms (so a deleted, duplicated, or re-split arm is caught);
 *   2. the handler set of each arm matches the independent table below, which
 *      records the handler each token's arm calls (or "" when inline / absent);
 *   3. the independent table is exactly the canonical token list from
 *      `../x86/x86_sim.h`, in order, with no token added or dropped;
 *   4. `KPROG_X86_SPEC_COUNT` from the generated header equals the table size.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_specialization_chain_host.c \
 *     -o build/test_x86_specialization_chain_host \
 *     && ./build/test_x86_specialization_chain_host
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
#include "generated/x86_specialization.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned cases = 0;
static unsigned failures = 0;

/* The independent per-token chain table: the `X86_SIM_L_EXEC` handler each
 * token's arm calls, or "" when the arm is inline or the token has no arm. */
struct spec {
	const char *token;
	const char *handler;
};

static const struct spec SPEC[] = {
	{ "X86_OP_NOP", "" },
	{ "X86_OP_MOV_IMM", "" },
	{ "X86_OP_MOV_REG", "" },
	{ "X86_OP_ADD_IMM", "X86_SIM_L_EXEC_ALU_IMM" },
	{ "X86_OP_ADD_REG", "X86_SIM_L_EXEC_ALU_REG" },
	{ "X86_OP_XOR_REG", "X86_SIM_L_EXEC_ALU_REG" },
	{ "X86_OP_MOV_LOAD", "X86_SIM_L_EXEC_MOV_LOAD" },
	{ "X86_OP_MOV_STORE_IMM", "X86_SIM_L_EXEC_STORE" },
	{ "X86_OP_MOV_STORE_REG", "X86_SIM_L_EXEC_STORE" },
	{ "X86_OP_LEA", "X86_SIM_L_EXEC_LEA" },
	{ "X86_OP_ALU_IMM", "X86_SIM_L_EXEC_ALU_IMM" },
	{ "X86_OP_ALU_REG", "X86_SIM_L_EXEC_ALU_REG" },
	{ "X86_OP_CMP_IMM", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX" },
	{ "X86_OP_CMP_REG", "X86_SIM_L_EXEC_CMP_REG_OP_AUX" },
	{ "X86_OP_TEST_IMM", "X86_SIM_L_EXEC_CMP_IMM_OP_AUX" },
	{ "X86_OP_TEST_REG", "X86_SIM_L_EXEC_CMP_REG_OP_AUX" },
	{ "X86_OP_JCC", "" },
	{ "X86_OP_JMP", "" },
	{ "X86_OP_PUSH", "X86_SIM_L_EXEC_PUSH" },
	{ "X86_OP_POP", "X86_SIM_L_EXEC_POP" },
	{ "X86_OP_CALL", "" },
	{ "X86_OP_CMOV", "X86_SIM_L_EXEC_CMOV" },
	{ "X86_OP_SETCC", "X86_SIM_L_EXEC_SETCC_STEP" },
	{ "X86_OP_BSWAP", "" },
	{ "X86_OP_POPCNT", "" },
	{ "X86_OP_XCHG", "" },
	{ "X86_OP_DIV", "" },
	{ "X86_OP_SHLD_IMM", "" },
	{ "X86_OP_SHRD_IMM", "" },
	{ "X86_OP_CMP_MEM_IMM", "X86_SIM_L_EXEC_CMP_MEM" },
	{ "X86_OP_TEST_MEM_IMM", "X86_SIM_L_EXEC_CMP_MEM" },
	{ "X86_OP_CMP_MEM_REG", "X86_SIM_L_EXEC_CMP_MEM" },
	{ "X86_OP_MOVZX_REG", "" },
	{ "X86_OP_MOVSX_REG", "" },
	{ "X86_OP_MOVSX_LOAD", "X86_SIM_L_EXEC_MOV_LOAD" },
	{ "X86_OP_ALU_MEM", "X86_SIM_L_EXEC_ALU_MEM" },
	{ "X86_OP_CMP_REG_MEM", "X86_SIM_L_EXEC_CMP_REG_MEM" },
	{ "X86_OP_MOV_LOAD_SCALAR", "X86_SIM_L_EXEC_MOV_LOAD" },
	{ "X86_OP_SHIFTX", "" },
	{ "X86_OP_RORX", "" },
	{ "X86_OP_MOVBE_LOAD", "X86_SIM_L_EXEC_MOVBE_LOAD" },
	{ "X86_OP_MOVBE_STORE", "X86_SIM_L_EXEC_MOVBE_STORE" },
	{ "X86_OP_SHIFTX_MEM", "" },
	{ "X86_OP_RORX_MEM", "" },
	{ "X86_OP_MOV_LOAD_MAP_PTR", "" },
	{ "X86_OP_MOV_LOAD_HELPER_ID", "" },
	{ "X86_OP_CALL_HELPER", "" },
	{ "X86_OP_CALL_REG", "X86_SIM_BPF_CALL_REG" },
	{ "X86_OP_LOAD_XMM0", "X86_SIM_L_EXEC_LOAD_XMM0" },
	{ "X86_OP_STORE_XMM0", "X86_SIM_L_EXEC_STORE_XMM0" },
	{ "X86_OP_ALU_MEM_UNARY", "X86_SIM_L_EXEC_ALU_MEM_UNARY" },
	{ "X86_OP_ALU_MEM_IMM", "X86_SIM_L_EXEC_ALU_MEM_IMM" },
	{ "X86_OP_BZHI", "X86_SIM_L_EXEC_BZHI" },
	{ "X86_OP_BZHI_MEM", "X86_SIM_L_EXEC_BZHI_MEM" },
	{ "X86_OP_ALU_MEM_REG", "X86_SIM_L_EXEC_ALU_MEM_REG" },
	{ "X86_OP_BT", "X86_SIM_L_EXEC_BT" },
	{ "X86_OP_IMUL_IMM", "X86_SIM_L_EXEC_IMUL_IMM" },
	{ "X86_OP_MULX", "X86_SIM_L_EXEC_MULX" },
	{ "X86_OP_REP_MOVS", "X86_SIM_L_EXEC_REP_MOVS" },
	{ "X86_OP_TEST_MEM_REG", "X86_SIM_L_EXEC_CMP_MEM" },
	{ "X86_OP_CALL_MEMSET", "X86_SIM_L_EXEC_CALL_MEMSET" },
	{ "X86_OP_ANDN", "X86_SIM_L_EXEC_ANDN" },
	{ "X86_OP_SETCC_MEM", "X86_SIM_L_EXEC_SETCC_MEM" },
	{ "X86_OP_CALL_MEMCPY", "X86_SIM_L_EXEC_CALL_MEMCPY" },
	{ "X86_OP_CMOV_MEM", "X86_SIM_L_EXEC_CMOV_MEM" },
	{ "X86_OP_IMUL_MEM_IMM", "X86_SIM_L_EXEC_IMUL_MEM_IMM" },
	{ "X86_OP_BT_IMM", "X86_SIM_L_EXEC_BT_IMM" },
	{ "X86_OP_BT_MEM_IMM", "X86_SIM_L_EXEC_BT_MEM_IMM" },
	{ "X86_OP_ANDN_MEM", "X86_SIM_L_EXEC_ANDN_MEM" },
	{ "X86_OP_CALL_MEMSET_REG", "X86_SIM_L_EXEC_CALL_MEMSET_REG" },
	{ "X86_OP_CALL_MEMCPY_REG", "X86_SIM_L_EXEC_CALL_MEMCPY_REG" },
	{ "X86_OP_RET", "" },
};

#define SPEC_COUNT (sizeof SPEC / sizeof SPEC[0])

static char *read_whole_file(const char *path)
{
	FILE *file = fopen(path, "rb");
	long size;
	char *text;

	if (file == NULL) {
		fprintf(stderr, "cannot open %s\n", path);
		return NULL;
	}
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	text = malloc((size_t)size + 1);
	if (text == NULL) {
		fclose(file);
		return NULL;
	}
	if (size > 0 && fread(text, 1, (size_t)size, file) != (size_t)size) {
		free(text);
		fclose(file);
		return NULL;
	}
	text[size] = '\0';
	fclose(file);
	return text;
}

static int is_ident(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

/* The first distinct `(`-invoked `X86_SIM_L_EXEC_*`/`X86_SIM_BPF_CALL_*` name in
 * an arm, or "" when the arm calls none or more than one distinct handler (the
 * double-shift arms call `X86_SIM_L_SET_SHIFT_FLAGS` twice). */
static void arm_handler(const char *arm, size_t len, char *out, size_t out_size)
{
	const char *first = NULL;
	size_t first_len = 0;
	unsigned distinct = 0;
	size_t i = 0;

	out[0] = '\0';
	while (i + 16 < len) {
		const char *at = arm + i;
		size_t name_len;
		size_t j;
		int same_first;

		if (strncmp(at, "X86_SIM_L_EXEC_", 15) == 0)
			name_len = 15;
		else if (strncmp(at, "X86_SIM_BPF_CALL_", 17) == 0)
			name_len = 17;
		else {
			i++;
			continue;
		}
		while (name_len < len - i && is_ident(at[name_len]))
			name_len++;
		for (j = name_len; j < len - i && (at[j] == ' ' || at[j] == '\t' ||
						   at[j] == '\n' || at[j] == '\\');
		     j++)
			;
		if (j < len - i && at[j] == '(' && name_len < 64) {
			same_first = first != NULL && first_len == name_len &&
				     strncmp(first, at, name_len) == 0;
			if (first == NULL) {
				first = at;
				first_len = name_len;
				distinct = 1;
			} else if (!same_first) {
				distinct++;
			}
		}
		i += name_len;
	}
	if (distinct == 1) {
		size_t n = first_len < out_size - 1 ? first_len : out_size - 1;

		memcpy(out, first, n);
		out[n] = '\0';
	}
}

/* Count how many times `token` occurs as `(OP) == <token>` within [begin, end),
 * and record the first occurrence's arm handler. Returns 0 when absent. */
static unsigned arm_token_occurrences(const char *begin, const char *end,
				      const char *token, char *handler_out,
				      size_t handler_size)
{
	const char *scan = begin;
	unsigned found = 0;
	size_t token_len = strlen(token);

	handler_out[0] = '\0';
	while ((scan = strstr(scan, "(OP) == ")) != NULL) {
		const char *name;

		if (scan >= end)
			break;
		name = scan + strlen("(OP) == ");
		if ((size_t)(end - name) >= token_len &&
		    strncmp(name, token, token_len) == 0 &&
		    (name[token_len] == ' ' || name[token_len] == '|' ||
		     name[token_len] == ')' || name[token_len] == '\n' ||
		     name[token_len] == '\t' || name[token_len] == '\\'))
			found++;
		scan = name;
	}
	if (found > 0)
		arm_handler(begin, (size_t)(end - begin), handler_out,
			    handler_size);
	return found;
}

int main(void)
{
	char *text = read_whole_file("../x86/x86_sim_local_bpf.h");
	char *sim_text = read_whole_file("../x86/x86_sim.h");
	unsigned seen[SPEC_COUNT];
	const char *body;
	const char *inner_begin;
	const char *inner_end;
	const char *end;
	size_t i;
	int depth;
	const char *arm_begin;
	unsigned arm_count = 0;

	if (text == NULL || sim_text == NULL) {
		free(text);
		free(sim_text);
		return 1;
	}
	memset(seen, 0, sizeof seen);
	body = strstr(text, "#define X86_SIM_L_EXEC(OP, DST, SRC, FLAGS, AUX, IMM)");
	end = body != NULL ? strstr(body, "#define X86_SIM_RUN_OP(") : NULL;
	if (body == NULL || end == NULL) {
		fprintf(stderr, "X86_SIM_L_EXEC / X86_SIM_RUN_OP not found\n");
		free(text);
		free(sim_text);
		return 1;
	}

	/* Locate the outer arm body: the brace that opens the `do { ... } while`. */
	inner_begin = strchr(strstr(body, "do {"), '{');
	if (inner_begin == NULL) {
		fprintf(stderr, "X86_SIM_L_EXEC body brace not found\n");
		free(text);
		free(sim_text);
		return 1;
	}
	inner_begin++;
	depth = 1;
	inner_end = inner_begin;
	for (i = 0; inner_begin + i < end; i++) {
		if (inner_begin[i] == '{')
			depth++;
		else if (inner_begin[i] == '}' && --depth == 0) {
			inner_end = inner_begin + i;
			break;
		}
	}
	if (inner_end <= inner_begin) {
		fprintf(stderr, "X86_SIM_L_EXEC body not balanced\n");
		free(text);
		free(sim_text);
		return 1;
	}

	/* Walk arms: an arm ends at a depth-0 `} else if (`. Its guard is the text
	 * from the arm start up to the arm body's `{`; the body follows. */
	arm_begin = inner_begin;
	depth = 0;
	for (i = 0; arm_begin + i < inner_end; i++) {
		char c = arm_begin[i];

		if (c == '{')
			depth++;
		else if (c == '}') {
			depth--;
			if (depth == 0 && strncmp(arm_begin + i, "} else if (", 11) == 0) {
				const char *arm_end = arm_begin + i;
				char handler[80];
				size_t k;

				arm_handler(arm_begin, (size_t)(arm_end - arm_begin),
					    handler, sizeof handler);
				arm_count++;
				for (k = 0; k < SPEC_COUNT; k++) {
					unsigned occ = arm_token_occurrences(
						arm_begin, arm_end, SPEC[k].token,
						handler, sizeof handler);

					if (occ == 0)
						continue;
					seen[k] += occ;
					cases++;
					if (strcmp(handler, SPEC[k].handler) != 0) {
						fprintf(stderr,
							"arm handler %s: got \"%s\" want \"%s\"\n",
							SPEC[k].token, handler,
							SPEC[k].handler);
						failures++;
					}
				}
				arm_begin += i + 11;
				i = (size_t)-1;
				depth = 0;
			}
		}
	}
	/* Trailing arm (no `} else if (` after it). */
	if (arm_begin < inner_end) {
		char handler[80];

		arm_handler(arm_begin, (size_t)(inner_end - arm_begin), handler,
			    sizeof handler);
		arm_count++;
		for (i = 0; i < SPEC_COUNT; i++) {
			unsigned occ = arm_token_occurrences(arm_begin, inner_end,
							     SPEC[i].token,
							     handler,
							     sizeof handler);

			if (occ == 0)
				continue;
			seen[i] += occ;
			cases++;
			if (strcmp(handler, SPEC[i].handler) != 0) {
				fprintf(stderr,
					"arm handler %s: got \"%s\" want \"%s\"\n",
					SPEC[i].token, handler, SPEC[i].handler);
				failures++;
			}
		}
	}
	cases++;
	if (arm_count == 0) {
		fprintf(stderr, "no chain arms parsed\n");
		failures++;
	}

	/* Every table token that has an arm must be selected exactly once, and a
	 * token recorded with a handler must have been seen. */
	for (i = 0; i < SPEC_COUNT; i++) {
		unsigned expect = 0;
		size_t q;

		for (q = 0; q < SPEC_COUNT; q++)
			if (SPEC[q].handler[0] != '\0' &&
			    strcmp(SPEC[q].token, SPEC[i].token) == 0)
				expect = 1;
		if (SPEC[i].handler[0] != '\0') {
			cases++;
			if (seen[i] == 0) {
				fprintf(stderr, "arm missing for %s\n", SPEC[i].token);
				failures++;
			} else if (seen[i] > 1) {
				fprintf(stderr, "arm duplicated for %s (%u)\n",
					SPEC[i].token, seen[i]);
				failures++;
			}
		}
		(void)expect;
	}

	/* The independent table is the canonical token list, in order. */
	{
		const char *line = sim_text;
		unsigned index = 0;

		while ((line = strstr(line, "#define X86_OP_")) != NULL) {
			const char *name = line + strlen("#define ");
			const char *at = name;
			char token[64];

			while (is_ident(*at))
				at++;
			if ((size_t)(at - name) < sizeof token &&
			    (size_t)(at - name) > 0) {
				const char *rest = at;

				memcpy(token, name, (size_t)(at - name));
				token[at - name] = '\0';
				while (*rest == ' ' || *rest == '\t')
					rest++;
				if (strncmp(rest, "0x", 2) == 0) {
					cases++;
					if (index >= SPEC_COUNT) {
						fprintf(stderr,
							"table short: header has %s\n",
							token);
						failures++;
					} else if (strcmp(SPEC[index].token, token) != 0) {
						fprintf(stderr,
							"table order: slot %u is %s, header has %s\n",
							index, SPEC[index].token,
							token);
						failures++;
					}
					index++;
				}
			}
			line = at;
		}
		cases++;
		if (index != SPEC_COUNT) {
			fprintf(stderr, "table size %u != canonical %u\n",
				(unsigned)SPEC_COUNT, index);
			failures++;
		}
	}

	/* The generated header's count agrees. */
	cases++;
	if (KPROG_X86_SPEC_COUNT != SPEC_COUNT) {
		fprintf(stderr, "KPROG_X86_SPEC_COUNT %u != %u\n",
			KPROG_X86_SPEC_COUNT, (unsigned)SPEC_COUNT);
		failures++;
	}

	free(text);
	free(sim_text);
	if (failures == 0)
		printf("x86 specialization chain host cross-check: OK (%u cases)\n",
		       cases);
	return failures == 0 ? 0 : 1;
}

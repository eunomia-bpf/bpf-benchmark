/*
 * Host cross-check for the x86-64 `MOVZX`/`MOVSX` register-source opcode-keyed
 * extension-shape selection contract (STEP 0118).
 *
 * The module under test is `generated/x86_movx_shape.h`. It fixes two things
 * the `X86_OP_MOVZX_REG || X86_OP_MOVSX_REG` arm of `X86_SIM_L_EXEC` (and the
 * shared `X86_SIM_L_EXEC_MOVX_REG` body) decides. First, the extension function
 * the body selects between on the opcode: the sign extension
 * (`x86_sign_extend`) at the `X86_OP_MOVSX_REG` opcode and the zero extension
 * (`x86_apply_width`) at every other opcode, written by hand as an
 * `(OP) == X86_OP_MOVSX_REG ?` select. Second, the *source width* the selected
 * function is applied at: the decoded `aux` field names it unless it is the
 * absent code, in which case the body falls back to its effective width — the
 * `(AUX) ? (AUX) : __x86_l_width` kernel.
 * This oracle drives the contract's `KPROG_X86_MOVX_SHAPE` / `.._COUNT`
 * / `.._SHAPE_*` and `KPROG_X86_MOVX_SRC_WIDTH` / `.._ABSENT_CODE` and restates
 * both selections from the raw opcodes and width codes. The two must agree; the
 * generated `_Static_assert`s additionally pin the hand-written
 * `X86_OP_MOVZX_REG` / `X86_OP_MOVSX_REG` decodes to the generated table at
 * compile time. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. test_x86_movx_shape_host.c -o /tmp/t_movx_shape
 *   /tmp/t_movx_shape
 */
typedef unsigned char __u8;

/* The hand-written decodes the generated drift checks bind to, and the width
 * decodes the source-width checks bind to. The former are pinned to the
 * generated table by the header's `_Static_assert`s. */
#define X86_OP_MOVZX_REG 0x20U
#define X86_OP_MOVSX_REG 0x21U
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U

#include "generated/x86_movx_shape.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The independent selection: the sign-extension body exactly at the
 * `X86_OP_MOVSX_REG` opcode and the zero-extension body at every other opcode,
 * so the selector is total. The arm codes are restated as literals so the model
 * is independent of the generated `.._SHAPE_*` values. */
static int model_arm(unsigned op)
{
	return op == X86_OP_MOVSX_REG ? 0 : 1;
}

/* The width codes the source-width resolution operates at, restated as
 * literals: the four `x86_width_spec.json` decode values. */
static const unsigned width_codes[] = {1U, 2U, 4U, 8U};
#define WIDTH_CODE_COUNT 4U

/* The independent source-width resolution: the decoded `aux` field names the
 * source width unless it is the absent code, in which case the body falls back
 * to the effective width passed in. The absent code is restated as a literal so
 * the model is independent of the generated `.._ABSENT_CODE`. */
static unsigned model_src_width(unsigned aux, unsigned effective)
{
	return aux == 0U ? effective : aux;
}

int main(void)
{
	unsigned op;

	cases++;
	if (KPROG_X86_MOVX_SHAPE_COUNT != 2U) {
		printf("MISMATCH count got=%u want=2\n",
		       (unsigned)KPROG_X86_MOVX_SHAPE_COUNT);
		failures++;
	}

	cases++;
	if (X86_OP_MOVZX_REG != 0x20U || X86_OP_MOVSX_REG != 0x21U) {
		printf("MISMATCH opcode got=%u/%u want=32/33\n",
		       (unsigned)X86_OP_MOVZX_REG, (unsigned)X86_OP_MOVSX_REG);
		failures++;
	}

	cases++;
	if (KPROG_X86_MOVX_SHAPE_SIGN_EXTEND ==
	    KPROG_X86_MOVX_SHAPE_ZERO_EXTEND) {
		printf("MISMATCH shape codes not distinct\n");
		failures++;
	}

	/* The selector returns the extension function the independent model
	 * names, over the whole byte range the opcode can take. */
	for (op = 0; op <= 0xffU; op++) {
		unsigned got = KPROG_X86_MOVX_SHAPE((__u8)op);
		int want = model_arm(op);

		cases++;
		if (got != (unsigned)want) {
			printf("MISMATCH shape op=%u got=%u want=%d\n",
			       op, got, want);
			failures++;
		}
	}

	/* The source-width selector returns the width the independent model
	 * resolves, over the whole byte range `aux` can take and a mix of
	 * effective widths (including two real width codes). */
	{
		static const unsigned effectives[] = {1U, 2U, 4U, 8U};
		unsigned aux;
		unsigned e;

		for (aux = 0; aux <= 0xffU; aux++) {
			for (e = 0; e < 4U; e++) {
				unsigned got = KPROG_X86_MOVX_SRC_WIDTH(
					(__u8)aux, effectives[e]);
				unsigned want = model_src_width(aux,
								effectives[e]);

				cases++;
				if (got != want) {
					printf("MISMATCH src width aux=%u eff=%u"
					       " got=%u want=%u\n",
					       aux, effectives[e], got, want);
					failures++;
				}
			}
		}
	}

	/* The selector is the identity on every real source width: only the
	 * absent code is rewritten, so no encoded width is distorted. */
	{
		unsigned i;

		for (i = 0; i < WIDTH_CODE_COUNT; i++) {
			cases++;
			if (KPROG_X86_MOVX_SRC_WIDTH(width_codes[i],
						     X86_WIDTH_64) !=
			    width_codes[i]) {
				printf("MISMATCH src width code %u distorted\n",
				       width_codes[i]);
				failures++;
			}
		}
	}

	/* An absent `aux` field resolves to the effective width the body passes
	 * in, and the absent code collides with no real width code. */
	cases++;
	if (KPROG_X86_MOVX_SRC_WIDTH(KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE,
				     X86_WIDTH_64) != X86_WIDTH_64 ||
	    KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE == 0x1U ||
	    KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE == 0x2U ||
	    KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE == 0x4U ||
	    KPROG_X86_MOVX_SRC_WIDTH_ABSENT_CODE == 0x8U) {
		printf("MISMATCH src width absent field drift\n");
		failures++;
	}

	/* Each MOVX opcode reaches its own body, and a code that is neither
	 * (here the absent code 0) reaches the zero-extension default. */
	cases++;
	if (KPROG_X86_MOVX_SHAPE(X86_OP_MOVZX_REG) !=
		    KPROG_X86_MOVX_SHAPE_ZERO_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(X86_OP_MOVSX_REG) !=
		    KPROG_X86_MOVX_SHAPE_SIGN_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(0U) != KPROG_X86_MOVX_SHAPE_ZERO_EXTEND ||
	    KPROG_X86_MOVX_SHAPE(3U) != KPROG_X86_MOVX_SHAPE_ZERO_EXTEND) {
		printf("MISMATCH opcode shape drift\n");
		failures++;
	}

	if (failures != 0) {
		printf("x86 movx shape host cross-check: FAIL (%d)\n", failures);
		return 1;
	}
	printf("x86 movx shape host cross-check: OK (%lu cases)\n", cases);
	return 0;
}

/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause) */
/*
 * Tetragon's loader supplies these return-zero bodies for default CEL slots.
 * This BPF library supplies their linked source extents to manifest generation.
 * The native cel_expr fallback in process/cel_expr.h has the same result.
 */
#define CEL_DEFAULT(slot) \
    int cel_expr_##slot(long *argsoff, char *args) { return 0; }

CEL_DEFAULT(0)
CEL_DEFAULT(1)
CEL_DEFAULT(2)
CEL_DEFAULT(3)
CEL_DEFAULT(4)
CEL_DEFAULT(5)
CEL_DEFAULT(6)
CEL_DEFAULT(7)

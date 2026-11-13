// SPDX-License-Identifier: GPL-2.0
/*
 * Zeroing with stores instead of a memset call. Native objects only, switch-on path.
 *
 * A BPF program that zeroes a map value writes it with explicit stores: clang's BPF
 * backend expands `__builtin_memset(p, 0, 368)` into `*(u64 *)(r0 + N) = r8` stores
 * (Tracee sys_enter_init LBB4_3 is 30 of them). The same C compiled for x86-64 keeps
 * the call: X86's constant-store lowering only inlines up to 16 stores and otherwise
 * calls memset, which in this kernel is __memset -> `rep stos %al` one byte at a time
 * (2.c: `jmp memset_orig`; memset_orig stores 64 bytes per iteration in the bulk path
 * but the entry path taken here is the byte loop). So the native body does strictly
 * more work than the JIT one on every invocation -- measured on one Tracee run,
 * 13.9% of all guest CPU-time samples land inside the 32-byte memset body in the
 * native phase against 0.7% in the eBPF phase (kprog/perf/profile/).
 *
 * This header gives those calls the shape the JIT body has. It is only on the
 * include path of the switch-on build: native objects compiled without it are
 * byte-identical to the ones the image ships today.
 *
 * Scope of the rewrite:
 *   - only calls whose size and fill byte are compile-time constants are rewritten;
 *     a computed size keeps the call, since that is the one case where a rep-stos
 *     loop is what the kernel does best;
 *   - only sizes up to NATIVE_MEMSET_MAX_BYTES are unrolled, so a large zeroing
 *     does not trade one `rep stos` for a long store run in the instruction cache;
 *     the limit is where X86's own inline threshold stops being a win here.
 * The store loop body is what clang's loop-idiom pass would otherwise fold back
 * into a memset call, so the switch-on build also passes -fno-builtin-memset; the
 * calls this macro leaves alone are declared explicitly and stay real calls.
 */

#ifndef VENDOR_BPF_NATIVE_MEMSET_H
#define VENDOR_BPF_NATIVE_MEMSET_H

#ifdef MICRO_NATIVE

#define NATIVE_MEMSET_MAX_BYTES 512u

typedef unsigned long __native_memset_word;

static __attribute__((always_inline)) inline void
__native_memset_stores(void *dst, int fill, __native_memset_word bytes)
{
	unsigned char *byte = (unsigned char *)dst;
	unsigned char pattern = (unsigned char)fill;
	__native_memset_word word = 0x0101010101010101ULL * pattern;
	__native_memset_word *out = (__native_memset_word *)dst;
	__native_memset_word words = bytes / sizeof(word);
	__native_memset_word tail = bytes % sizeof(word);
	__native_memset_word i;

#pragma clang loop unroll(full)
	for (i = 0; i < words; i++)
		out[i] = word;
#pragma clang loop unroll(full)
	for (i = 0; i < tail; i++)
		byte[bytes - tail + i] = pattern;
}

/* The kernel's own prototype; the calls this macro leaves alone still go there. */
extern void *memset(void *dst, int fill, __native_memset_word bytes);

#define __builtin_memset(dst, fill, bytes)                                  \
	((__builtin_constant_p(bytes) && __builtin_constant_p(fill)          \
	  && (__native_memset_word)(bytes) <= NATIVE_MEMSET_MAX_BYTES)       \
	     ? (void)__native_memset_stores((dst), (fill),                    \
	                                    (__native_memset_word)(bytes))   \
	     : memset((dst), (fill), (__native_memset_word)(bytes)))

#endif /* MICRO_NATIVE */

#endif /* VENDOR_BPF_NATIVE_MEMSET_H */
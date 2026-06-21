// SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause)
/* Copyright Authors of Cilium */

#ifndef __BPF_COMPILER_H__
#define __BPF_COMPILER_H__

#ifdef __V61_BPF_PROG
#define FUNC_LOCAL  static __attribute__((noinline)) __attribute__((__unused__))
#define FUNC_INLINE static inline __attribute__((always_inline))
#else
/* Older kernels have all functions inlined.  */
#define FUNC_LOCAL  static inline __attribute__((always_inline))
#define FUNC_INLINE static inline __attribute__((always_inline))
#endif

#ifndef fallthrough
#define fallthrough __attribute__((fallthrough))
#endif

#define TETRAGON_STR(s)  #s
#define TETRAGON_XSTR(s) TETRAGON_STR(s)

#ifdef MICRO_NATIVE
#define tetragon_mask(value, mask) \
	do { \
		(value) &= (mask); \
	} while (0)
#define tetragon_clamp_max(value, max) \
	do { \
		if ((value) > (max)) \
			(value) = (max); \
	} while (0)
#define tetragon_clamp_nonnegative_max_or_goto(value, max, label) \
	do { \
		if ((long)(value) < 0) \
			goto label; \
		tetragon_clamp_max(value, max); \
	} while (0)
#define tetragon_set_if_not_errno_or_zero(value, replacement) \
	do { \
		if ((long)(value) > 0 || (long)(value) < -4095) \
			(value) = (replacement); \
	} while (0)
#else
#define tetragon_mask(value, mask) \
	asm volatile("%[__value] &= %1;\n" \
		     : [__value] "+r"(value) \
		     : "i"(mask))
#define tetragon_clamp_max(value, max) \
	asm volatile("if %[__value] < " TETRAGON_XSTR(max) " goto +1\n;" \
		     "%[__value] = " TETRAGON_XSTR(max) ";\n" \
		     : [__value] "+r"(value))
#define tetragon_clamp_nonnegative_max_or_goto(value, max, label) \
	asm volatile goto("if %[__value] < 0 goto %l[" TETRAGON_XSTR(label) "]\n;" \
			  "if %[__value] < " TETRAGON_XSTR(max) " goto +1\n;" \
			  "%[__value] = " TETRAGON_XSTR(max) ";\n" \
			  : \
			  : [__value] "+r"(value) \
			  : \
			  : label)
#define tetragon_set_if_not_errno_or_zero(value, replacement) \
	asm volatile("if %[__value] s< -4095 goto +1\n" \
		     "if %[__value] s<= 0 goto +1\n" \
		     "%[__value] = " TETRAGON_XSTR(replacement) "\n" \
		     : [__value] "+r"(value))
#endif

#endif /* __BPF_COMPILER_H__ */

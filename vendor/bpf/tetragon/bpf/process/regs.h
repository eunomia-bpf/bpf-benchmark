// SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause)
/* Copyright Authors of Cilium */

#ifndef __REGS_H__
#define __REGS_H__

#if defined(__TARGET_ARCH_x86)

FUNC_LOCAL __u64
read_reg(struct pt_regs *ctx, __u32 src, __u8 shift)
{
#ifdef MICRO_NATIVE
#define READ_REG(reg) ({                                             \
	__u64 val = *(__u64 *)((char *)ctx + offsetof(struct pt_regs, reg)); \
	val <<= shift;                                               \
	val >>= shift;                                               \
	val;                                                         \
})
#else
#define READ_REG(reg) ({                                        \
	__u64 val;                                              \
	asm volatile("%[val] = *(u64 *)(%[ctx] + %[off])\n"     \
		     : [ctx] "+r"(ctx), [val] "+r"(val)         \
		     : [off] "i"(offsetof(struct pt_regs, reg)) \
		     :);                                        \
	val <<= shift;                                          \
	val >>= shift;                                          \
	val;                                                    \
})
#endif

	switch (src) {
	case offsetof(struct pt_regs, r15):
		return READ_REG(r15);
	case offsetof(struct pt_regs, r14):
		return READ_REG(r14);
	case offsetof(struct pt_regs, r13):
		return READ_REG(r13);
	case offsetof(struct pt_regs, r12):
		return READ_REG(r12);
	case offsetof(struct pt_regs, bp):
		return READ_REG(bp);
	case offsetof(struct pt_regs, bx):
		return READ_REG(bx);
	case offsetof(struct pt_regs, r11):
		return READ_REG(r11);
	case offsetof(struct pt_regs, r10):
		return READ_REG(r10);
	case offsetof(struct pt_regs, r9):
		return READ_REG(r9);
	case offsetof(struct pt_regs, r8):
		return READ_REG(r8);
	case offsetof(struct pt_regs, ax):
		return READ_REG(ax);
	case offsetof(struct pt_regs, cx):
		return READ_REG(cx);
	case offsetof(struct pt_regs, dx):
		return READ_REG(dx);
	case offsetof(struct pt_regs, si):
		return READ_REG(si);
	case offsetof(struct pt_regs, di):
		return READ_REG(di);
	case offsetof(struct pt_regs, ip):
		return READ_REG(ip);
	case offsetof(struct pt_regs, sp):
		return READ_REG(sp);
	}

#undef READ_REG
	return 0;
}

FUNC_LOCAL int
write_reg(struct pt_regs *ctx, __u32 dst, __u8 size, __u64 val)
{
#ifdef MICRO_NATIVE
#define WRITE_REG(reg) ({                                                  \
	void *__p = (char *)ctx + offsetof(struct pt_regs, reg);            \
	if (size == 8)                                                      \
		*(__u64 *)__p = val;                                        \
	else if (size == 4)                                                 \
		*(__u32 *)__p = (__u32)val;                                 \
	else if (size == 2)                                                 \
		*(__u16 *)__p = (__u16)val;                                 \
	else if (size == 1)                                                 \
		*(__u8 *)__p = (__u8)val;                                   \
	0;                                                                 \
})
#else
#define WRITE_REG(reg) ({                                                  \
	asm volatile("if %[size] != 8 goto +2\n"                           \
		     "*(u64 *)(%[ctx] + %[off]) = %[val]\n"                \
		     "goto +8\n"                                           \
		     "if %[size] != 4 goto +2\n"                           \
		     "*(u32 *)(%[ctx] + %[off]) = %[val]\n"                \
		     "goto +5\n"                                           \
		     "if %[size] != 2 goto +2\n"                           \
		     "*(u16 *)(%[ctx] + %[off]) = %[val]\n"                \
		     "goto +2\n"                                           \
		     "if %[size] != 1 goto +1\n"                           \
		     "*(u8 *)(%[ctx] + %[off]) = %[val]\n"                 \
		     : [ctx] "+r"(ctx), [val] "+r"(val), [size] "+r"(size) \
		     : [off] "i"(offsetof(struct pt_regs, reg))            \
		     :);                                                   \
	0;                                                                 \
})
#endif

	switch (dst) {
	case offsetof(struct pt_regs, r15):
		return WRITE_REG(r15);
	case offsetof(struct pt_regs, r14):
		return WRITE_REG(r14);
	case offsetof(struct pt_regs, r13):
		return WRITE_REG(r13);
	case offsetof(struct pt_regs, r12):
		return WRITE_REG(r12);
	case offsetof(struct pt_regs, bp):
		return WRITE_REG(bp);
	case offsetof(struct pt_regs, bx):
		return WRITE_REG(bx);
	case offsetof(struct pt_regs, r11):
		return WRITE_REG(r11);
	case offsetof(struct pt_regs, r10):
		return WRITE_REG(r10);
	case offsetof(struct pt_regs, r9):
		return WRITE_REG(r9);
	case offsetof(struct pt_regs, r8):
		return WRITE_REG(r8);
	case offsetof(struct pt_regs, ax):
		return WRITE_REG(ax);
	case offsetof(struct pt_regs, cx):
		return WRITE_REG(cx);
	case offsetof(struct pt_regs, dx):
		return WRITE_REG(dx);
	case offsetof(struct pt_regs, si):
		return WRITE_REG(si);
	case offsetof(struct pt_regs, di):
		return WRITE_REG(di);
	case offsetof(struct pt_regs, ip):
		return WRITE_REG(ip);
	case offsetof(struct pt_regs, sp):
		return WRITE_REG(sp);
	}

#undef WRITE_REG
	return 0;
}

#endif /* __TARGET_ARCH_x86 */

#if defined(__TARGET_ARCH_arm64)

FUNC_LOCAL __u64
read_reg(struct pt_regs *ctx, __u32 src, __u8 shift)
{
#ifdef MICRO_NATIVE
#define READ_SCALAR_REG(reg) ({                                        \
	__u64 val = *(__u64 *)((char *)ctx + offsetof(struct pt_regs, reg)); \
	val <<= shift;                                                  \
	val >>= shift;                                                  \
	val;                                                            \
})
#define READ_ARRAY_REG(offset) ({ \
	__u64 val = ctx->regs[(offset)]; \
	val <<= shift; \
	val >>= shift; \
	val; \
})
#else
#define READ_SCALAR_REG(reg) ({                                  \
	__u64 val;                                                \
	asm volatile("%[val] = *(u64 *)(%[ctx] + %[off])\n"       \
		     : [ctx] "+r"(ctx), [val] "+r"(val)           \
		     : [off] "i"(offsetof(struct pt_regs, reg))   \
		     :);                                          \
	val <<= shift;                                            \
	val >>= shift;                                            \
	val;                                                      \
})
#define READ_ARRAY_REG(offset) ({                                           \
	__u64 val;                                                          \
	asm volatile("%[val] = *(u64 *)(%[ctx] + %[off])\n"                 \
		     : [ctx] "+r"(ctx), [val] "+r"(val)                     \
		     : [off] "i"(offsetof(struct pt_regs, regs) + 8 * (offset)) \
		     :);                                                    \
	val <<= shift;                                                      \
	val >>= shift;                                                      \
	val;                                                                \
})
#endif

	switch (src) {
	case offsetof(struct pt_regs, sp):
		return READ_SCALAR_REG(sp);
	case offsetof(struct pt_regs, pc):
		return READ_SCALAR_REG(pc);
	case offsetof(struct pt_regs, regs) + 8 * 0:
		return READ_ARRAY_REG(0);
	case offsetof(struct pt_regs, regs) + 8 * 1:
		return READ_ARRAY_REG(1);
	case offsetof(struct pt_regs, regs) + 8 * 2:
		return READ_ARRAY_REG(2);
	case offsetof(struct pt_regs, regs) + 8 * 3:
		return READ_ARRAY_REG(3);
	case offsetof(struct pt_regs, regs) + 8 * 4:
		return READ_ARRAY_REG(4);
	case offsetof(struct pt_regs, regs) + 8 * 5:
		return READ_ARRAY_REG(5);
	case offsetof(struct pt_regs, regs) + 8 * 6:
		return READ_ARRAY_REG(6);
	case offsetof(struct pt_regs, regs) + 8 * 7:
		return READ_ARRAY_REG(7);
	case offsetof(struct pt_regs, regs) + 8 * 8:
		return READ_ARRAY_REG(8);
	case offsetof(struct pt_regs, regs) + 8 * 9:
		return READ_ARRAY_REG(9);
	case offsetof(struct pt_regs, regs) + 8 * 10:
		return READ_ARRAY_REG(10);
	case offsetof(struct pt_regs, regs) + 8 * 11:
		return READ_ARRAY_REG(11);
	case offsetof(struct pt_regs, regs) + 8 * 12:
		return READ_ARRAY_REG(12);
	case offsetof(struct pt_regs, regs) + 8 * 13:
		return READ_ARRAY_REG(13);
	case offsetof(struct pt_regs, regs) + 8 * 14:
		return READ_ARRAY_REG(14);
	case offsetof(struct pt_regs, regs) + 8 * 15:
		return READ_ARRAY_REG(15);
	case offsetof(struct pt_regs, regs) + 8 * 16:
		return READ_ARRAY_REG(16);
	case offsetof(struct pt_regs, regs) + 8 * 17:
		return READ_ARRAY_REG(17);
	case offsetof(struct pt_regs, regs) + 8 * 18:
		return READ_ARRAY_REG(18);
	case offsetof(struct pt_regs, regs) + 8 * 19:
		return READ_ARRAY_REG(19);
	case offsetof(struct pt_regs, regs) + 8 * 20:
		return READ_ARRAY_REG(20);
	case offsetof(struct pt_regs, regs) + 8 * 21:
		return READ_ARRAY_REG(21);
	case offsetof(struct pt_regs, regs) + 8 * 22:
		return READ_ARRAY_REG(22);
	case offsetof(struct pt_regs, regs) + 8 * 23:
		return READ_ARRAY_REG(23);
	case offsetof(struct pt_regs, regs) + 8 * 24:
		return READ_ARRAY_REG(24);
	case offsetof(struct pt_regs, regs) + 8 * 25:
		return READ_ARRAY_REG(25);
	case offsetof(struct pt_regs, regs) + 8 * 26:
		return READ_ARRAY_REG(26);
	case offsetof(struct pt_regs, regs) + 8 * 27:
		return READ_ARRAY_REG(27);
	case offsetof(struct pt_regs, regs) + 8 * 28:
		return READ_ARRAY_REG(28);
	case offsetof(struct pt_regs, regs) + 8 * 29:
		return READ_ARRAY_REG(29);
	case offsetof(struct pt_regs, regs) + 8 * 30:
		return READ_ARRAY_REG(30);
	}

#undef READ_SCALAR_REG
#undef READ_ARRAY_REG
	return 0;
}

FUNC_LOCAL int
write_reg(struct pt_regs *ctx, __u32 dst, __u8 size, __u64 val)
{
#ifdef MICRO_NATIVE
#define WRITE_SCALAR_REG(reg) ({                                           \
	void *__p = (char *)ctx + offsetof(struct pt_regs, reg);            \
	if (size == 8)                                                      \
		*(__u64 *)__p = val;                                        \
	else if (size == 4)                                                 \
		*(__u32 *)__p = (__u32)val;                                 \
	0;                                                                 \
})
#define WRITE_ARRAY_REG(offset) ({ \
	void *__p = &ctx->regs[(offset)]; \
	if (size == 8) \
		*(__u64 *)__p = val; \
	else if (size == 4) \
		*(__u32 *)__p = (__u32)val; \
	0; \
})
#else
#define WRITE_SCALAR_REG(reg) ({                                           \
	asm volatile("if %[size] != 8 goto +2\n"                           \
		     "*(u64 *)(%[ctx] + %[off]) = %[val]\n"                \
		     "goto +2\n"                                           \
		     "if %[size] != 4 goto +1\n"                           \
		     "*(u32 *)(%[ctx] + %[off]) = %[val]\n"                \
		     : [ctx] "+r"(ctx), [val] "+r"(val), [size] "+r"(size) \
		     : [off] "i"(offsetof(struct pt_regs, reg))            \
		     :);                                                   \
	0;                                                                 \
})
#define WRITE_ARRAY_REG(offset) ({                                          \
	asm volatile("if %[size] != 8 goto +2\n"                           \
		     "*(u64 *)(%[ctx] + %[off]) = %[val]\n"                \
		     "goto +2\n"                                           \
		     "if %[size] != 4 goto +1\n"                           \
		     "*(u32 *)(%[ctx] + %[off]) = %[val]\n"                \
		     : [ctx] "+r"(ctx), [val] "+r"(val), [size] "+r"(size) \
		     : [off] "i"(offsetof(struct pt_regs, regs) + 8 * (offset)) \
		     :);                                                   \
	0;                                                                 \
})
#endif

	switch (dst) {
	case offsetof(struct pt_regs, sp):
		return WRITE_SCALAR_REG(sp);
	case offsetof(struct pt_regs, pc):
		return WRITE_SCALAR_REG(pc);
	case offsetof(struct pt_regs, regs) + 8 * 0:
		return WRITE_ARRAY_REG(0);
	case offsetof(struct pt_regs, regs) + 8 * 1:
		return WRITE_ARRAY_REG(1);
	case offsetof(struct pt_regs, regs) + 8 * 2:
		return WRITE_ARRAY_REG(2);
	case offsetof(struct pt_regs, regs) + 8 * 3:
		return WRITE_ARRAY_REG(3);
	case offsetof(struct pt_regs, regs) + 8 * 4:
		return WRITE_ARRAY_REG(4);
	case offsetof(struct pt_regs, regs) + 8 * 5:
		return WRITE_ARRAY_REG(5);
	case offsetof(struct pt_regs, regs) + 8 * 6:
		return WRITE_ARRAY_REG(6);
	case offsetof(struct pt_regs, regs) + 8 * 7:
		return WRITE_ARRAY_REG(7);
	case offsetof(struct pt_regs, regs) + 8 * 8:
		return WRITE_ARRAY_REG(8);
	case offsetof(struct pt_regs, regs) + 8 * 9:
		return WRITE_ARRAY_REG(9);
	case offsetof(struct pt_regs, regs) + 8 * 10:
		return WRITE_ARRAY_REG(10);
	case offsetof(struct pt_regs, regs) + 8 * 11:
		return WRITE_ARRAY_REG(11);
	case offsetof(struct pt_regs, regs) + 8 * 12:
		return WRITE_ARRAY_REG(12);
	case offsetof(struct pt_regs, regs) + 8 * 13:
		return WRITE_ARRAY_REG(13);
	case offsetof(struct pt_regs, regs) + 8 * 14:
		return WRITE_ARRAY_REG(14);
	case offsetof(struct pt_regs, regs) + 8 * 15:
		return WRITE_ARRAY_REG(15);
	case offsetof(struct pt_regs, regs) + 8 * 16:
		return WRITE_ARRAY_REG(16);
	case offsetof(struct pt_regs, regs) + 8 * 17:
		return WRITE_ARRAY_REG(17);
	case offsetof(struct pt_regs, regs) + 8 * 18:
		return WRITE_ARRAY_REG(18);
	case offsetof(struct pt_regs, regs) + 8 * 19:
		return WRITE_ARRAY_REG(19);
	case offsetof(struct pt_regs, regs) + 8 * 20:
		return WRITE_ARRAY_REG(20);
	case offsetof(struct pt_regs, regs) + 8 * 21:
		return WRITE_ARRAY_REG(21);
	case offsetof(struct pt_regs, regs) + 8 * 22:
		return WRITE_ARRAY_REG(22);
	case offsetof(struct pt_regs, regs) + 8 * 23:
		return WRITE_ARRAY_REG(23);
	case offsetof(struct pt_regs, regs) + 8 * 24:
		return WRITE_ARRAY_REG(24);
	case offsetof(struct pt_regs, regs) + 8 * 25:
		return WRITE_ARRAY_REG(25);
	case offsetof(struct pt_regs, regs) + 8 * 26:
		return WRITE_ARRAY_REG(26);
	case offsetof(struct pt_regs, regs) + 8 * 27:
		return WRITE_ARRAY_REG(27);
	case offsetof(struct pt_regs, regs) + 8 * 28:
		return WRITE_ARRAY_REG(28);
	case offsetof(struct pt_regs, regs) + 8 * 29:
		return WRITE_ARRAY_REG(29);
	case offsetof(struct pt_regs, regs) + 8 * 30:
		return WRITE_ARRAY_REG(30);
	}

#undef WRITE_SCALAR_REG
#undef WRITE_ARRAY_REG
	return 0;
}

#endif /* __TARGET_ARCH_arm64 */

#endif /* __REGS_H__*/

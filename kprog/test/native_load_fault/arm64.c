/* ARM64 guest recovery forms share the live-file and NULL-file controls. */
#include "vmlinux.h"
#define ENTRY(NAME) __attribute__((section("lsm/file_open"),used,noinline)) unsigned long NAME(unsigned long *ctx)
#define ADDRESS const struct file *file=(const void *)ctx[0]; const void *base=&file->f_pos
#define SCALAR(NAME, INSN, OUT) ENTRY(NAME) { ADDRESS; unsigned long value; asm volatile(INSN " " OUT ",[%1]" : "=r"(value) : "r"(base) : "memory"); return -(value&1UL); }
SCALAR(entry_byte,"ldrb","%w0")
SCALAR(entry_half,"ldrh","%w0")
SCALAR(entry_word,"ldr","%w0")
SCALAR(entry_signed_byte,"ldrsb","%0")
SCALAR(entry_signed_half,"ldrsh","%0")
SCALAR(entry_signed_word,"ldrsw","%0")
ENTRY(entry_pair)
{
    ADDRESS; unsigned long first,second;
    asm volatile("ldp %0,%1,[%2]" : "=r"(first),"=r"(second) : "r"(base) : "memory");
    return -((first|second)&1UL);
}
ENTRY(entry_pre)
{
    ADDRESS; unsigned long value;
    base=(const char *)base-8;
    asm volatile("ldr %0,[%1,#8]!" : "=r"(value),"+r"(base) : : "memory");
    return -(value&1UL);
}
ENTRY(entry_post)
{
    ADDRESS; unsigned long value;
    asm volatile("ldr %0,[%1],#8" : "=r"(value),"+r"(base) : : "memory");
    return -(value&1UL);
}
#define VECTOR(NAME, REG) ENTRY(NAME) { ADDRESS; unsigned long value,initial=2; asm volatile("fmov d0,%2; ldr " REG ",[ %1 ]; fmov %0,d0" : "=r"(value) : "r"(base),"r"(initial) : "v0","memory");return -(value&1UL); }
VECTOR(entry_d0,"d0")
VECTOR(entry_q0,"q0")
ENTRY(entry_d0_post)
{
    ADDRESS; unsigned long value,initial=2;
    asm volatile("fmov d0,%2; ldr d0,[%1],#8; fmov %0,d0" : "=r"(value),"+r"(base) : "r"(initial) : "v0","memory");
    return -(value&1UL);
}
ENTRY(entry_q0_post)
{
    ADDRESS; unsigned long value,initial=2;
    asm volatile("fmov d0,%2; ldr q0,[%1],#16; fmov %0,d0" : "=r"(value),"+r"(base) : "r"(initial) : "v0","memory");
    return -(value&1UL);
}

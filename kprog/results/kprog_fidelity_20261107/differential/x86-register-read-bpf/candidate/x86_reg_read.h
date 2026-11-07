/* Private generic x86 register-read range representation. */
#ifndef KPROG_FORMAL_GENERATED_X86_REG_READ_H
#define KPROG_FORMAL_GENERATED_X86_REG_READ_H
#if defined(__BPF__) || defined(__bpf__)
#define KPROG_X86_READ_REG_AT(VALUE, WIDTH, BYTE_SHIFT) \
 ({ __u64 __kprog_x86_read = (VALUE) >> ((WIDTH) == X86_WIDTH_8 ? (BYTE_SHIFT) : 0U); \
    if ((WIDTH) == X86_WIDTH_8) \
      __asm__("%0 &= 255" : "+r"(__kprog_x86_read)); \
    else if ((WIDTH) == X86_WIDTH_16) \
      __asm__("%0 &= 65535" : "+r"(__kprog_x86_read)); \
    else if ((WIDTH) == X86_WIDTH_32) \
      __kprog_x86_read = (__u32)__kprog_x86_read; \
    __kprog_x86_read; })
#else
#define KPROG_X86_READ_REG_AT(VALUE, WIDTH, BYTE_SHIFT) \
 KPROG_X86_APPLY_WIDTH((VALUE) >> ((WIDTH) == X86_WIDTH_8 ? (BYTE_SHIFT) : 0U), (WIDTH))
#endif
#endif

/* Compiled with -include ahead of native_lab_input.h: every private input of
 * the simulator becomes a read of an ordinary, mutable array map. The verifier
 * marks each such load an unknown scalar, the same abstract value the private
 * instruction produced, so B needs no verifier extension. */
#ifndef NATIVE_LAB_INPUT_H
#define NATIVE_LAB_INPUT_H
#if defined(__TARGET_ARCH_x86)
#define KPROG_X86_ENTRY_SAVES_CALLEE 1
#endif
#define NATIVE_LAB_INPUT_ABI 2
#define NATIVE_LAB_INPUT_SRC 9
#define NATIVE_LAB_INPUT_SP 1
#define NATIVE_LAB_INPUT_CODE 2
#define NATIVE_LAB_INPUT_RETURN 3
#define NATIVE_LAB_INPUT_NUMERIC 4
#define NATIVE_LAB_INPUT_EXCLUSIVE_FAILURE 5
#define NATIVE_LAB_INPUT_UNSPECIFIED 6
#if defined(__bpf__)
extern unsigned long long kprog_unspecified_input[] __attribute__((section(".ksyms")));
#define KPROG_UNSPECIFIED_WORD() (*(volatile unsigned long long *)&kprog_unspecified_input[0])
#define NATIVE_LAB_ENTRY_INPUT(kind) ({ (void)(kind); (unsigned long)KPROG_UNSPECIFIED_WORD(); })
#define NATIVE_LAB_NUMERIC(value) ({ (void)(value); (unsigned long)KPROG_UNSPECIFIED_WORD(); })
#define NATIVE_LAB_EXCLUSIVE_FAILURE(site) ({ (void)(site); (unsigned long)(KPROG_UNSPECIFIED_WORD() & 1); })
#endif
#endif

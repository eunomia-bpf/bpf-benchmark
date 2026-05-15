#ifndef MICRO_HANDCRAFT_H
#define MICRO_HANDCRAFT_H

#include <linux/bpf.h>
#include <stddef.h>
#include <stdint.h>

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif

#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif

#define MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM 1
#define MICRO_HANDCRAFT_BPF_X86_POPCNTQ 2
#define MICRO_HANDCRAFT_BPF_X86_MOVBE32_SIB 3
#define MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM 4
#define MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32 5
#define MICRO_HANDCRAFT_BPF_X86_TESTQ_RR 6
#define MICRO_HANDCRAFT_BPF_X86_CMOVNEQ_RR 7

struct micro_handcraft_program {
    const struct bpf_insn *insns;
    size_t insn_count;
};

typedef int (*micro_handcraft_get_program_fn)(struct micro_handcraft_program *program);

#endif

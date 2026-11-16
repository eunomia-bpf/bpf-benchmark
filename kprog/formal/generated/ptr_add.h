/* Canonical simulator C; edit directly. Historical origin: generate_ptr_add_spec.py from ptr_add_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_PTR_ADD_H
#define KPROG_FORMAL_GENERATED_PTR_ADD_H

/* Address bits wrap at 64 bits, including zero/relative SP words. */
#define KPROG_PTR_ADD64_BITS(SRC_PTR, RHS) ((__u8 *)(unsigned long)((__u64)(unsigned long)(SRC_PTR) + (__u64)(RHS)))
/* BPF retains its original pointer operand form for verifier/codegen identity.
 * Host/Clight form address bits explicitly, including null/relative words. */
#if defined(__bpf__) || defined(__BPF__)
#define KPROG_PTR_ADD64_NATIVE(SRC_PTR, RHS) ((__u8 *)(SRC_PTR) + (RHS))
#else
#define KPROG_PTR_ADD64_NATIVE(SRC_PTR, RHS) KPROG_PTR_ADD64_BITS((SRC_PTR), (RHS))
#endif
#define KPROG_PTR_ADD64_TAG(SRC_TAG) (SRC_TAG)
#define KPROG_X86_LEA_STACK_REFERENCE(SRC_IS_RSP, DST_IS_RSP) \
    ((SRC_IS_RSP) && !(DST_IS_RSP))

#endif

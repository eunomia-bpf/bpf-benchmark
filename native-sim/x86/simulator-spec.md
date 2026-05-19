# ReverseSim x86 Simulator Spec

This document specifies the active x86 proof simulator used by
`native-sim/x86`. It is intentionally tied to the current implementation:

- `x86_sim_local_bpf.h`
- `x86_sim.h`
- `micro-prog/generate_micro_sim_proofs.py`

The old `struct x86_state` / `x86_exec_*` path and the JSON/template linker
experiment are removed.

## Correctness Contract

For an accepted artifact, the generated eBPF proof program must execute the same
architectural x86 state transition as the linked native x86 instruction stream.

Forbidden mechanisms:

- runtime trap, abort, fallback return, or unsupported branch;
- simulator-inserted packet/output/stack bounds checks;
- branch assertions over values not used by the hardware branch;
- fuel guards or fixed loop trip bounds;
- benchmark-specific generation logic;
- dead parallel simulator implementations.

Verifier rejection is a valid result. It must not be repaired by adding a
checked-simulator behavior that native x86 would not execute.

## State

Architectural state:

```text
GPRs:   RAX RCX RDX RBX RSP RBP RSI RDI R8..R15
Flags:  CF ZF SF OF
Memory: raw ctx/packet/stack/rodata/native-address memory as expressed by the
        generated instruction semantics
```

Implementation representation:

```c
__u64 __x86_rax, ..., __x86_r15;
__u8 __x86_cf, __x86_zf, __x86_sf, __x86_of;
union { __u8 b[N]; __u64 q[(N + 7) / 8]; } __x86_stack_mem;
```

The stack array is a byte model of the native stack region used by the proof
artifact. There is no runtime bounds check. If a generated proof expression
accesses outside the modeled extent, the compiler/verifier/load path should
fail rather than silently executing a different behavior.

## Ghost Pointer Metadata

Each register also has proof metadata:

```c
void *__x86_p_<reg>;
__u8  __x86_tag_<reg>;
__s32 __x86_off_<reg>;
```

This metadata is not architectural x86 state. It exists only to express the
same address value in a form the eBPF verifier can type-check. The invariant is:

```text
tag(reg) != NONE  =>  scalar(reg) == address_value(ptr(reg), off(reg), tag(reg))
```

Allowed uses:

- select a verifier-typed pointer expression for a load/store whose scalar x86
  address is the same value;
- propagate tags through 64-bit `mov`, `lea`, `add`, `sub`, and `xchg` when the
  scalar value is transformed identically.

Forbidden uses:

- change a scalar GPR value;
- change flags or branch conditions;
- prove a branch from metadata rather than x86 flags;
- insert a runtime check;
- manufacture a pointer relation not guaranteed by the ABI or previous exact
  instruction semantics.

This invariant is a proof obligation for direct-native safety.

## Entry ABI

For XDP and skb micro programs, ReverseSim starts with:

```text
RDI = ctx
tag(RDI) = CTX
RSP = 0
tag(RSP) = STACK
```

`ctx->data`, `ctx->data_end`, and skb data/length fields are modeled as ABI
loads. The resulting scalar value must equal the value a native ABI-compliant
program would observe.

## Instruction Expansion

Python emits one C macro per native x86 instruction:

```c
/* 0xADDR: original asm */
X86_SIM_RUN_OP(X86_OP_..., dst, src, width, aux, imm);
```

For branches and calls it emits x86 control macros:

```c
X86_SIM_X86_JCC(cc, current_pc, target_pc, target_label);
X86_SIM_X86_JMP(current_pc, target_pc, target_label);
X86_SIM_X86_CALL(target_label, return_pc);
X86_SIM_X86_RET();
X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);
```

Python is not allowed to select semantic helpers based on benchmark names,
expected values, verifier failures, or opcode-specific shortcuts. It may parse
native operands into numeric macro arguments.

## Branches

Conditional branches read only architectural flags:

```text
Jcc(target) = if eval_cc(CF,ZF,SF,OF,cc) then PC=target else PC=fallthrough
```

There is no `last_cmp_*`, `cmp_ptr_*`, verifier assertion, or range proof hook.
For example:

```asm
cmp rdx, 3
mov rdx, r9
ja target
```

The `ja` uses the flags produced by `cmp`; it must not assert anything about
the current value of `rdx`.

## Calls And Returns

`call target`:

```text
RSP = RSP - 8
MEM64[RSP] = fallthrough_pc
PC = target
```

`ret`:

```text
tmp = MEM64[RSP]
RSP = RSP + 8
PC = tmp
```

Current C code dispatches `PC = tmp` through generated labels. This covers the
normal linked micro call/return pattern where return addresses are not modified
as data. It is not yet a full hardware model for arbitrary computed return
targets or return-address mutation; such artifacts must not be treated as
direct-native safe until the dispatch model is extended.

## Memory

Loads and stores are raw native memory operations in the proof expression:

```text
LOAD(width, address)
STORE(width, address, value)
```

No simulator-side data-end check is inserted. If native x86 has an explicit
guard, that guard remains an x86 compare/branch over flags. If the verifier
cannot connect that guard to a later load/store, the artifact fails to load.

Fault-like cases are not converted into fallback behavior:

- invalid address;
- stack outside modeled extent;
- disallowed packet write for the program type;
- division fault;
- verifier-prohibited pointer arithmetic.

They surface as compile, verifier, or load failures.

## Result Rule

An accepted artifact may be used for direct-native safety only if:

1. The generated instruction sequence is the linked native x86 sequence.
2. Every emitted macro implements the corresponding x86 state transition.
3. Ghost metadata satisfies the invariant above and never affects architectural
   values except by selecting an equivalent typed address expression.
4. No forbidden mechanism appears in the accepted artifact.
5. The verifier accepts the generated eBPF proof program.

If any item is missing, the result is an experiment result, not a direct-native
safety proof.

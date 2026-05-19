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
void *__x86_rax, ..., *__x86_r15;
__u8 __x86_cf, __x86_zf, __x86_sf, __x86_of;
union { __u8 b[N]; __u64 q[(N + 7) / 8]; } __x86_stack_mem;
```

The C type `void *` is the storage representation for the architectural 64-bit
register bits. It is not per-register metadata. A register is read as a pointer
for pointer-shaped x86 operations such as `mov`, `lea`, stack-pointer updates,
and memory addressing. The same register is read as `(__u64)(long)reg` for x86
integer operations, flag computation, shifts, masks, compares, division, and
partial-width register semantics.

The stack array is a byte model of the native stack region used by the proof
artifact. There is no runtime bounds check. If a generated proof expression
accesses outside the modeled extent, the compiler/verifier/load path should
fail rather than silently executing a different behavior.

## No Ghost Pointer Metadata

GPR variables carry only architectural x86 values. The active simulator does
not maintain
per-register proof metadata such as:

```c
void *__x86_p_<reg>;
__u8  __x86_tag_<reg>;
__s32 __x86_off_<reg>;
```

The old `PACKET`, `PACKET_END`, `PACKET_LEN`, and `STACK` tags are removed.
In particular, the simulator must not prove:

```text
packet + skb_len == packet_end
```

from hidden metadata. If native code loads `skb->len`, that result is an
ordinary architectural register value.

## Entry ABI

For XDP and skb micro programs, ReverseSim starts with:

```text
RDI = &guest_abi
RSP = 0
```

The implementation entry macros are:

```c
X86_SIM_ENTRY_XDP(ctx);
X86_SIM_ENTRY_SKB(ctx);
```

They may only:

- create guest ABI memory containing the linked native ABI fields;
- declare simulator-local architectural variables and modeled stack storage;
- set ABI-defined entry state (`RDI = &guest_abi`, modeled `RSP = 0`).

The guest ABI memory object is architectural memory for the linked native entry
ABI. For XDP, offset 0 holds `ctx->data` and offset 8 holds `ctx->data_end`.
For skb, the object contains the linked native ABI fields currently referenced
by the generated x86, including `len` and `data` at the linked offsets.

Current micro skb proof mode initializes:

```text
guest_abi.data = ctx->data
guest_abi.len  = ctx->data_end - ctx->data
```

This is an ABI equality assumption for the current linear micro/test_run skb
inputs: the native `sk_buff->len` value read by the linked x86 must equal the
linear packet span represented by verifier `data_end - data`. It is not a
general TC/cgroup skb rule. Non-linear skbs, cloned fragments, or any attach
point where native `sk_buff->len` can differ from the verifier packet span are
outside this proof mode until the native ABI exposes a value that is exactly
equal to verifier `data_end`.

The entry macros must not change ctx/packet/output memory, create per-register
tags, insert bounds checks, trap, fallback, infer `packet + len == packet_end`,
or influence control flow.

Only ABI-defined entry state may be used as a semantic fact. Other GPRs and
flags are unspecified at native function entry. The C implementation may give
local variables initializer values so the eBPF program is well-formed, but an
accepted artifact must separately establish that no guest-visible data flow,
control flow, memory access, or return value depends on those initializer values.
Self-zeroing idioms such as `xor eax, eax` are acceptable only because the x86
instruction result is independent of the old register value.

## Representation Tricks

Verifier-facing typed expressions are allowed only as semantics-erased
representations of the same x86 value. Removing the typed expression and
replacing it with the corresponding raw x86 memory value must leave the same
architectural registers, flags, memory effects, and control flow.

Allowed examples:

```text
x86 entry:        RDI = &guest_abi
x86 instruction:  MOV reg, [RDI + data_offset]
proof expression: reg = LOAD64(&guest_abi + data_offset)

x86 instruction:  LEA reg, [packet_reg + const]
proof expression: reg = (void *)((u8 *)packet_reg + const)
```

These are allowed because both sides compute the same architectural x86 value.
The `void *` C type preserves verifier-visible pointer shape when the value is
already a pointer, but it does not attach a hidden tag to the register.

Forbidden uses:

- caching `ctx->data`, `ctx->data_end`, or skb `len` at entry as hidden proof
  facts outside the guest ABI memory object;
- propagating typed pointer metadata across x86 registers;
- using typed facts to affect flags, branches, return values, or memory writes;
- proving packet bounds from `packet + len`, `data_end`, or any relation that
  the native x86 instruction stream did not itself establish.

`ctx->data`, `ctx->data_end`, skb data, and skb length enter the proof through
guest ABI memory construction and ordinary x86 loads from that memory. They do
not create per-register pointer metadata.

The micro skb `len = data_end - data` initializer is not a packet-bound proof
hook. If native x86 later computes `data + len`, that value remains an ordinary
architectural result of the native instructions. The simulator must not replace
branches against `data + len` with branches against `data_end`, or assert that
the current register is packet-end, unless that exact value is produced by the
native instruction sequence.

Known verifier-expression boundary: exact x86 partial-register writes to a
register that currently has verifier pointer type may require integer bit
operations over pointer bits. Native x86 allows this, but the eBPF verifier may
reject the proof expression. The simulator must not repair that rejection by
zero-extending, dropping upper bits, or otherwise changing partial-register
hardware semantics.

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

Current C code dispatches `PC = tmp` through generated labels. This is not a
full hardware model for arbitrary computed return targets. The accepted subset
for the current experiment is compiler-generated normal direct calls:

```text
No reachable instruction may modify the active return-address slot before the
matching ret.
```

Examples outside this subset include stores to `[rsp]`, `[rbp+8]`, or any alias
of the return slot followed by `ret`. Such code is legal x86, but the current
label-dispatch simulator must not claim it is proven direct-native safe. Full
hardware coverage requires a PC-based simulator where `ret` sets a variable PC
from `MEM64[RSP]` and dispatches from that value.

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

For skb programs, the simulator must not manufacture packet `data_end` from
`skb->data + skb->len`. If the linked native x86 computes a bound that the
eBPF verifier cannot relate to packet memory, verifier rejection is the correct
experimental result. The current micro `len = data_end - data` ABI initializer
does not relax this rule: it may make the architectural `len` value match the
linear test packet, but it must not be used to synthesize hidden packet-end
metadata or branch assertions.

## Result Rule

An accepted artifact may be used for direct-native safety only if:

1. The generated instruction sequence is the linked native x86 sequence.
2. Every emitted macro implements the corresponding x86 state transition.
3. No hidden pointer metadata, packet-length proof, branch assertion, runtime
   guard, trap, or fallback appears in the accepted artifact.
4. The verifier accepts the generated eBPF proof program.

If any item is missing, the result is an experiment result, not a direct-native
safety proof.

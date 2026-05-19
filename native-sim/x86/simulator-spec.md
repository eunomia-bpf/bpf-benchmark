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
For skb, the guest object mirrors the kernel BPF runtime ABI used by the linked
native micro code:

```text
guest_abi + 0x30: BPF-visible __sk_buff.cb[0..] scratch
guest_abi + 0x50: BPF-visible __sk_buff.data_end
guest_abi + 0xd0: sk_buff->data
```

The concrete offsets are generated for native code from kernel BTF:

```text
K_SK_BUFF_BPF_CB_OFFSET =
    offsetof(struct sk_buff, cb) + offsetof(struct qdisc_skb_cb, data)

K_SK_BUFF_BPF_DATA_END_OFFSET =
    offsetof(struct sk_buff, cb) + offsetof(struct bpf_skb_data_end, data_end)
```

On the current x86 kernel these are `0x30` and `0x50`; `sk_buff->data` is
`0xd0`. The simulator constants must match the kernel used to generate the
linked native code.

The simulator must not model `skb->len` as packet end. eBPF source-level
`ctx->data_end` is not a load from `sk_buff->len`: the verifier/JIT rewrite
turns it into a load from `skb->cb + offsetof(struct bpf_skb_data_end,
data_end)`, and the kernel runtime fills that slot before running skb BPF
programs. Direct-native proof must align native x86 with that same runtime ABI.

For skb entries, `X86_SIM_X86_RET()` copies guest ABI `cb[0..1]` to the typed
test-run `struct __sk_buff` output context. This is the proof representation of
the same `bpf_skb_cb(skb)` scratch storage that native x86 writes. It must not
modify the architectural return value: `RAX` remains the program return. In
particular, `cgroup_skb` return values are only actions
(`CGROUP_SKB_OK`/`CGROUP_SKB_DROP`); the 64-bit benchmark result is not encoded
in the return value.

The entry and return ABI macros must not change packet data, create
per-register tags, insert bounds checks, trap, fallback, infer
`packet + len == packet_end`, or influence control flow. Conditional
compilation between native and eBPF builds is limited to the minimum ABI shim
needed to expose the same kernel fields; it must not create two benchmark
algorithms or two result semantics.

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

`ctx->data`, `ctx->data_end`, `bpf_skb_cb(skb)`, and `sk_buff->data` enter the
proof through guest ABI memory construction and ordinary x86 loads/stores from
that memory. They do not create per-register pointer metadata.

If native x86 explicitly loads `skb->len` in a future artifact, that value is
an ordinary architectural load and must not be treated as packet end unless the
linked ABI has separately made it exactly equal to the verifier-visible
`data_end` value.

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
`skb->data + skb->len`. The current native micro ABI reads the same
runtime-prepared BPF `data_end` slot that eBPF ctx access uses. If a future
linked native x86 sequence computes a different bound that the eBPF verifier
cannot relate to packet memory, verifier rejection is the correct experimental
result.

## Result Rule

An accepted artifact may be used for direct-native safety only if:

1. The generated instruction sequence is the linked native x86 sequence.
2. Every emitted macro implements the corresponding x86 state transition.
3. No hidden pointer metadata, packet-length proof, branch assertion, runtime
   guard, trap, or fallback appears in the accepted artifact.
4. The verifier accepts the generated eBPF proof program.

If any item is missing, the result is an experiment result, not a direct-native
safety proof.

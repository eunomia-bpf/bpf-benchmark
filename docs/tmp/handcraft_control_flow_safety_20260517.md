# Handcraft Control-Flow Safety Notes

Date: 2026-05-17

This note records the current design discussion for native x86 asm to handcraft
BPF/kinsn conversion.

## Safety Boundary

User space must not provide verifier proof facts or final native branch
displacements. It may provide only the architectural x86 instruction operands
and the program-level branch/call target that was present in the input asm.

Forbidden user-space-controlled branch payload fields:

- verifier proof kind;
- verifier proof branch delta after kinsn materialization;
- final x86 `rel8` / `rel32` displacement;
- verifier scratch-register allocation;
- hidden x86 flag interpretation that the kernel cannot validate.

The kernel must treat all handcraft input as untrusted. Bad payloads may be
rejected by the verifier or by kinsn descriptor validation, but they must not be
able to crash the kernel or make verifier proof differ from final native
execution.

## Branch Kinsn Boundary

The branch kinsn module may remain available as a machine-instruction selector,
but user space must not provide a separate verifier proof kind or proof-time
branch delta. That is the wrong trust boundary. A verifier branch target after
kinsn materialization depends on kernel proof expansion and later kernel BPF
patching. A final x86 displacement depends on JIT layout. Both are
kernel-owned facts, not user-space facts.

This was visible in handcraft micro failures such as a verifier rejection with a
branch target computed outside the expanded proof program. The immediate cause
was a stale or incorrect user-space model of kinsn proof lengths.

## Fixed-3 Bundle Candidate

One possible kernel-side design is to make every kinsn a fixed 3-insn bundle:

```text
0: sidecar payload
1: carrier jump
2: call BPF_PSEUDO_KINSN_CALL
```

The carrier can be a real BPF jump, for example:

```c
BPF_JMP32 | BPF_JA, imm = target_delta
```

Benefits:

- `bpf_adj_branches()` can relocate the target because the target lives in a
  real BPF branch field.
- the third instruction remains the kinsn call, so the existing kfunc/BTF
  descriptor lookup still finds the kinsn module descriptor;
- user space no longer needs to provide proof deltas or x86 displacements;
- fixed length means most verifier changes are mechanical `2 -> 3` bundle
  accounting rather than variable-region support.

The expected kernel work is small if all kinsns are fixed length:

- `struct bpf_kinsn_region.orig[2]` becomes `orig[3]`;
- lowering records `sidecar + carrier + call` as the atomic original region;
- restore patches back 3 original instructions;
- payload lookup for the call reads sidecar at `call - 2`;
- JIT treats the carrier as bundle metadata, not as a normal emitted BPF jump;
- branch kinsn JIT uses the normal JIT address table (`addrs[]` on x86,
  `ctx->offset[]` on arm64) to compute final native displacement.

The important part is that the kernel computes final displacement. User space
does not provide it.

## Short-Term Experiment

Before changing the kernel ABI, use a separate converter path that keeps
control flow as ordinary BPF:

```text
x86 call -> BPF_PSEUDO_CALL
x86 ret  -> BPF_EXIT
x86 jmp  -> BPF_JMP32 | BPF_JA
x86 jcc  -> ordinary BPF conditional branch where possible
```

The experiment is implemented in:

```text
analysis/native_asm_to_handcraft_bpf_cf.py
```

This script is intentionally separate from `native_asm_to_handcraft.py`.
It does not emit branch kinsn payloads and therefore does not emit
`HC_X86_BRANCH_PAYLOAD`, proof-kind fields, proof-time branch deltas, or final
x86 displacements for branch/call/exit.

For `jcc`, it first tries to translate the immediately preceding `cmp/test`
into a direct BPF branch. This preserves verifier-visible facts for common
packet bounds checks such as:

```text
cmp data_plus_k, data_end
ja abort
```

When direct translation is not possible, it falls back to ordinary BPF branches
over the shadow flag stack written by `cmp/test` kinsns. That fallback is for
bring-up only: it can run verifier-visible control flow, but it does not give
the packet verifier the same range proof as a direct BPF compare.

The script is fail-fast for missing semantics. If a direct call target is
outside the parsed asm text, an indirect jump uses a native-only shadow
register that ordinary BPF cannot name, or any non-padding x86 instruction has
no emitted representation, generation exits non-zero and does not write a
partial `.handcraft.c`. A generated handcraft source must not contain an
instruction comment whose code body was silently omitted.

Branch relocation in this path uses only the final emitted BPF instruction
layout. It does not model kinsn proof expansion length, because that is a
kernel-owned verifier detail and is exactly what this path is trying to remove
from user-space trust.

## Current Recommendation

Run the short-term BPF-control-flow converter first to make every micro either
generate a complete verifier-visible program or fail with an explicit missing
instruction/control-flow form. If this works for most programs, keep
branch/call as ordinary BPF in the experimental path and defer fixed-3 carrier
work until native branch parity is the bottleneck.

If native parity requires branch kinsns, use the fixed-3 carrier design rather
than putting proof deltas or x86 displacement back into user-space payloads.

## Native C ABI Knobs

The host-native benchmark and the converter input should avoid SysV frame
noise that eBPF/XDP does not have. Native micro programs now compile with:

```text
-fomit-frame-pointer -mno-red-zone -fno-stack-protector
-fno-asynchronous-unwind-tables -fno-unwind-tables -fno-jump-tables
```

This makes the function body closer to the x86 BPF JIT convention: first XDP
argument in `rdi`, return in `rax`, no mandatory `push rbp; mov rbp,rsp` frame,
and no compiler-created jump tables in `.rodata`.

This is not a complete XDP ABI match. Host native still needs a runnable
`struct xdp_md` representation with pointer-sized `data` and `data_end`, while
kernel XDP exposes verifier-mediated ctx fields. The converter must keep that
ctx mapping explicit; it must not hide it as an implicit proof fact.

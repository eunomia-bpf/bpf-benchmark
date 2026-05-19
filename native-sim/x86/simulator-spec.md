# x86 ReverseSim Simulator Specification

This document specifies the verifier-facing generated-C simulator path under
`native-sim/x86`. It is intended to match the current code closely enough that each
rule can be translated into a later mechanized proof obligation.

The trusted shape is:

```text
native x86 instruction stream
  -> generated fixed eBPF/C simulator schedule
  -> kernel eBPF verifier accepts the generated proof program
  -> native execution is justified only if the generated schedule is proved
     equivalent to the native x86 stream under this spec
```

The generator must not use benchmark names, expected return values, or observed
test failures to select semantics. Every non-local transformation below is a
named theorem obligation.

## 1. Scope

This spec covers the generated-C path:

- `native-sim/x86/micro-prog/generate_micro_sim_proofs.py`
- `native-sim/x86/x86_sim.h`
- `native-sim/x86/x86_sim_bpf.h`
- generated programs under `native-sim/x86/micro-prog/*.bpf.c`

The strict JSON-linker path is a separate experiment. Its final proof should use
the same instruction and lowering rules, but its bytecode-linking details are
not specified here.

## 2. Machine State

The abstract x86 state is:

```text
XState = {
  GPR64:
    rax rcx rdx rbx rsp rbp rsi rdi r8 r9 r10 r11 r12 r13 r14 r15,

  Flags:
    cf zf sf of,

  Ghost pointer capability for each GPR:
    p_<reg>   : verifier pointer value or null,
    tag_<reg> : NONE | CTX | PACKET | PACKET_END | RODATA | STACK |
                 PACKET_LEN,
    off_<reg> : hidden packet/data-end offset used only when tag is PACKET or
                PACKET_END,

  Modeled stack slots:
    stack0..stackN plus tag_stackN,
    p_stack0..p_stack8 verifier pointer payloads for low stack slots,

  Packet verifier inputs:
    data, data_end,

  Control:
    current native address or return/done/unsupported
}
```

Concrete x86 arithmetic uses only the `GPR64` and `Flags` fields. The `p_*`,
`tag_*`, and `off_*` fields are ghost verifier capabilities. They must not
affect the mathematical value of a scalar x86 register except by authorizing a
memory access that the native program would perform.

### Entry ABI

For XDP-style generated programs:

```text
rdi has ghost capability CTX(ctx)
ctx->data is modeled as PACKET(data)
ctx->data_end is modeled as PACKET_END(data_end)
rsp has ghost capability STACK when stack modeling is enabled
all other ghost capabilities start as NONE
```

The code implementation is `x86_init_state()` in `x86_sim.h`.

### Stack Pointer Payload Rule

Each modeled x86 stack slot stores its 64-bit value and a ghost tag. Low slots
`0..8` also carry real BPF verifier pointer payloads (`p_stack0..p_stack8`) so
native stack spills of packet/ctx/rodata capabilities can be restored without
inventing a new pointer fact. A stack slot tagged `NONE` or `STACK` does not
need a BPF pointer payload.

If a reachable native path spills a non-`NONE`/non-`STACK` pointer into a deeper
slot, the generated proof artifact must reject before native execution. This is
a support/coverage rejection, not a runtime safety check for accepted native
code. The current micro corpus needs low slots through slot 8, including the
`bpf_local_call_fanout_dispatch` packet-pointer spills at `[rbp-0x38]` and
`[rbp-0x40]`.

### Hidden Packet Offset Rule

For packet and packet-end capabilities, `off_<reg>` records the verifier-visible
offset from the entry packet `data` pointer. This field is hidden proof metadata:
the concrete x86 register value in `GPR64` is still the value produced by the
modeled x86 instruction. For current packet pointers, pointer-producing helpers
write a scalar register value of `0` and preserve the real packet verifier
payload plus the hidden offset in `p_<reg>/tag_<reg>/off_<reg>`.

Loads may use the hidden offset only to emit an equivalent verifier-visible
address:

```text
addr = data + off_<base> + displacement
```

The proof obligation is that this address denotes the same modeled packet byte
that the native x86 memory operand denotes under the entry ABI. The hidden offset
must not be read as an x86 scalar value and must be invalidated or recomputed
whenever the pointer capability is invalidated or moved.

### SKB Packet-Length Capability Rule

For native SKB-shaped micro objects, `ctx+0xd0` denotes the packet data pointer
and `ctx+0x70` denotes the packet length. A 32-bit load from `ctx+0x70` writes
the native scalar length into the destination register and attaches a
`PACKET_LEN` ghost capability whose verifier payload is `data_end`.

The only current pointer-producing use of `PACKET_LEN` is 64-bit addition with
a packet data pointer:

```text
PACKET_LEN(data_end, len) + PACKET(data + off)
  = PACKET_END(data_end + off)
PACKET(data + off) + PACKET_LEN(data_end, len)
  = PACKET_END(data_end + off)
```

For the accepted SKB micro path, `off == 0` at the ABI construction point, so
this expresses the kernel verifier relation `data + skb_len == data_end`.
This is not a runtime bounds check and does not assert a branch fact; it is an
ABI theorem that must be proved for the direct native execution environment.

### No Proof-Only Assertion Or Bounds-Check Rule

The final safety target is direct native x86 execution after verifier acceptance
of the generated eBPF proof program. Therefore the proof program must not become
a stricter checked simulator that rejects paths the native x86 would execute.
Verifier acceptance must come from semantics-preserving state layout, compiler
specialization, and facts already present in the native x86 control flow.

Hard rules for native-direct safety:

```text
No proof-only branch assertion.
No runtime packet/output bounds check in the proof path.
No proof-only stack/model bounds check that native x86 does not execute.
No runtime unsupported/fallback as an accepted safety mechanism.
No fuel guard or synthetic trip bound.
No fallback return value.
No benchmark-specific renderer or helper.
No metadata fact may justify a memory access unless it is proved equivalent to
the native x86 address and path condition.
```

In particular, this pattern must not assert a range over current `rdx` from the
old `cmp` flags:

```asm
cmp rdx, 3
mov rdx, r9
ja target
```

x86 keeps the flags from `cmp`, but current `rdx` after `mov` is no longer the
cmp operand. A verifier assertion over current `rdx` would prove a different
program and would be unsound for direct native execution.

The active code therefore deletes the previous `last_cmp_*` metadata and
`x86_sim_assert_*` branch helpers. Branches use only `x86_eval_cc()` over the
modeled x86 flags. This may make verifier acceptance harder, but verifier
success must come from semantics-preserving optimization, not from a range fact
or bounds check that native x86 does not guarantee.

`X86_SIM_UNSUPPORTED` is simulator behavior, not native x86 behavior. A final accepted
native artifact needs a proof that every `X86_SIM_UNSUPPORTED` path is unreachable, or
a translation/load-time rejection before native execution. It must not be used
as a runtime safety guard for direct native execution.

## 3. Instruction Step Relation

For every generated native instruction `I` at address `pc`, the generator emits
exactly one simulator helper step, except for branches, calls, returns, and
named lowering rules in this document.

The simulator step has the form:

```c
X86_SIM_RUN_OP(op, dst, src, width, aux, imm);
```

The generated tuple `(op, dst, src, width, aux, imm)` is the encoded form of the
native instruction. C-authored simulator macros may dispatch to typed helpers
or fast paths when compile-time constants prove the same x86 step, but Python
does not select those helpers. The C simulator step must implement the
following relation:

```text
step(I, XState_in, Mem_in) = XState_out, Mem_out, Continue | Done | Unsupported
```

The proof obligation for each C simulator step/helper is:

```text
For every supported native instruction I encoded as args,
helper(args, XState_in, Mem_in) implements the same state transition as
the x86 ISA rule for I, restricted to the modeled memory/capability domain.
```

Compiler optimization is not part of the semantic proof. Clang inlining and
constant propagation may specialize fixed `(op, dst, src, aux, imm)` records so
the kernel verifier can analyze the eBPF program, but the correctness statement
is over the C-authored simulator/helper relation above.

Compile-cost fixes must preserve this boundary. Python may continue to emit the
simple native instruction stream and label metadata, but it must not grow
program-shape logic to make a hard case easier for clang or the verifier. Any
compile-cost reduction belongs in the C-authored simulator/header/macro layer:
helper factoring, inline/noinline boundaries, macro shape, state layout, and
ISA-semantics factoring are valid places to change. Python-side helper
selection, loop recognition, control-flow reconstruction, state specialization,
or benchmark-specific workarounds are outside this spec.

### Arithmetic And Flags

Arithmetic helpers update destination register values using x86 width rules:

```text
8/16-bit write: preserve high bits outside written lane
32-bit write: zero-extend to 64 bits
64-bit write: full 64-bit write
```

Flag updates:

```text
ADD/INC: x86 add flags, except INC preserves old CF
SUB/SBB/CMP: x86 subtract flags
AND/OR/XOR/TEST/SHL/SHR/SAR/ROL: current helper-defined flag rule in
  x86_set_alu_flags() / x86_set_logic_flags()
NOT: no flag update
```

Any helper whose flags do not yet match full x86 for an opcode must be listed as
a semantic gap before that opcode can be considered verified.

Same-register `xchg` is a no-op for both concrete state and ghost metadata. In
particular, `xchg ax, ax` must not clear the packet capability of `rax`; native
x86 treats it as an alignment NOP and direct-native safety depends on preserving
that exact behavior.

### Memory

A native memory operand is encoded by:

```text
base register
optional index register
scale log2
signed displacement
access width
```

The verifier-facing memory domains are:

```text
PACKET:      access is the native effective address represented by the packet
             pointer capability plus displacement; no proof-only runtime
             data_end guard may be inserted by the simulator
PACKET_END:  comparable pointer only; not directly dereferenceable
CTX:         only modeled ABI reads/writes are accepted
STACK:       access is mapped to explicit modeled stack slots under a stack
             layout theorem; checked slot rejection is not a final safety guard
RODATA:      access is mapped to a generated read-only table model
NONE:        not an accepted dereference domain for direct native execution
```

Packet and stack accesses in helpers must be proved equivalent to native memory
accesses under the ABI assumption that the native program is only allowed to
observe the modeled packet/output/stack domains.

## 4. Branches And Returns

Conditional native branches are emitted as:

```c
X86_SIM_X86_JCC(cc, current_pc, target_pc, target_label);
```

The proof obligation is:

```text
x86_eval_cc(state, cc) equals the x86 condition-code predicate over
state.cf/state.zf/state.sf/state.of.
```

The branch macro must not emit verifier-only assertions or bounds checks. If the
verifier needs a range fact, that fact must come from the native x86 instruction
stream itself and from semantics-preserving compiler/state shaping. The active
code removed the previous `x86_sim_assert_branch()` path for this reason.

Unconditional native branches are emitted as:

```c
X86_SIM_X86_JMP(current_pc, target_pc, target_label);
```

These are x86 instruction-lowering macros, not a separate simulator instruction set.
The generated operation is still native `jcc`/`jmp`; the C-authored macro owns
the verifier lowering to `goto target_label`. Python does not infer loop bounds,
induction variables, exits, or callback state. It only supplies the native
current/target addresses and target label. A taken backward edge has the same
control-flow meaning as native x86: jump to the target label. Any verifier
rejection for an unprovable or too-expensive loop is a verifier result, not a simulator
semantic fallback.

Native `ret` is emitted as:

```c
X86_SIM_X86_RET();
```

This returns the low 32 bits of `rax` to the BPF test-run ABI. Program-type
success return values are external metadata (`expected_retval` in
`micro/config/micro_pure_jit.yaml`), not generator semantics.

## 5. Native Calls

Known direct native call targets are disassembled and emitted as generated
subfunctions:

```c
static X86_SIM_SUBFN_ATTR int x86_fn_<symbol>(
    struct x86_state *state, void *data, void *data_end);
```

The native call site is emitted as:

```c
X86_SIM_X86_CALL(x86_fn_<symbol>);
```

The generated subfunction body starts with:

```c
X86_SIM_SUB_BEGIN();
```

and every native callee `ret` is emitted as:

```c
X86_SIM_X86_SUB_RET();
```

`X86_SIM_X86_CALL()` is a C-authored protocol macro. It models the native call
stack effect by reserving one return-address slot on the modeled x86 stack
before entering the generated callee and releasing that slot after the callee
returns. The return-address value itself is currently modeled as scalar zero
because none of the generated micro callees inspect it.

`X86_SIM_SUB_BEGIN()` only declares the per-callee instruction record. Generated
callee prologue/epilogue instructions such as `push rbp`, `mov rbp, rsp`, and
`pop rbp` execute through normal x86 helper steps. Callee-saved register
preservation is therefore provided by those generated x86 instructions, not by a
separate hidden wrapper restore.

Subfunction branches use the subfunction branch macros:

```c
X86_SIM_X86_SUB_JCC(cc, current_pc, target_pc, target_label);
X86_SIM_X86_SUB_JMP(current_pc, target_pc, target_label);
```

which apply the same native branch lowering as entry-function branches inside
the generated callee body.

The subfunction proof obligation is:

```text
Executing x86_fn_symbol from state S is equivalent to executing the native
callee instruction stream from its entry until its native ret.
```

If a future callee reads the native return address, the call macro must model
the concrete return-address value or reject that program.

## 6. Loop Lowering

The active generator does not lower loops to `bpf_loop` and does not perform
loop-shape analysis. Native loops remain native labels plus branch macros. The
C-authored branch macros lower native x86 edges directly to C labels and `goto`.
There is no fuel guard or synthetic trip bound because those are not x86 ISA
semantics.

The generator must not choose loop treatment based on return value, benchmark
name, observed failure, or per-loop Python analysis. Future optimized loop
protocols must be C-authored or bytecode-template-authored and added back to
this spec before use.

Current verifier consequence: plain native backedges are semantically clean and
the current micro corpus passes 29/29. The hard cases were fixed through
C-authored state shape and exact ISA/ABI rules, not Python loop analysis:
`bpftrace_string_search_prefix_scan` remains under the verifier limit, and the
TC/SKB checksum loops use the `PACKET_LEN` ABI rule plus exact same-register
`xchg` semantics. Future loop fixes must remain C/template proof rules that
preserve native branch semantics, not Python benchmark renderers, branch
assertions, or fuel bounds.

### Non-Active Loop Experiments

The active implementation does not contain a loop `pc` field and does not emit
pc-dispatch basic-block callbacks. That experiment was removed from the active
generator because it moved CFG scheduling complexity into Python and did not fix
the historical verifier-cost blockers.

The previous Python-generated `bpf_loop(bound, callback, &loop_ctx, 0)` lowering
has also been removed from the active generator for the same reason. It is not
part of the current proof contract.

## 7. Indexed Packet Addressing

x86 permits equivalent effective-address forms such as:

```text
[packet_ptr + scalar + disp]
[scalar + packet_ptr + disp]
```

The C simulator treats a scale-1 index register tagged `PACKET` as the packet
base when the nominal base register is scalar. This is implemented by
`x86_promote_index_packet_base()` under `X86_SIM_ENABLE_INDEX_PACKET_PROMOTE`.

Top-level packet loads in `x86_sim_bpf.h` may use a verifier-proven raw-load
fastpath. If the base pointer has no hidden offset, the address is:

```text
addr = packet_base + effective_disp
value = *(width *)addr
```

If the base pointer carries a hidden packet offset, the verifier-facing address
is:

```text
addr = data + off_<base> + effective_disp
value = *(width *)addr
```

This is not an extra sandbox and not a semantic shortcut. It is valid only when
the normal eBPF verifier can prove that `addr..addr+width` is inside the packet.
If that proof is unavailable, the BPF load is rejected. Subfunction helper steps
use the checked typed simulator path so local-call proof state does not depend
on raw packet range being preserved across generated callees.

Packet-pointer arithmetic must preserve concrete x86 scalar semantics. For
example, if a pointer-capable register is adjusted by an immediate, the
implementation updates the hidden offset used by verifier proof while leaving
the concrete register value equal to the modeled x86 result under the active ABI.
This separation is required for formalization: `off_<reg>` is proof metadata,
not part of the guest ISA.

For TC/SKB-shaped native input, `ctx+0xd0` denotes packet `data` and `ctx+0x70`
denotes packet length. The active implementation does not record the last
`cmp [ctx+0x70], imm` and does not use the following branch as a verifier
assertion. Instead, a load from `ctx+0x70` produces the concrete length scalar
plus a `PACKET_LEN` ghost capability. The C simulator may then derive
`PACKET_END` only from the ABI theorem `data + len == data_end`.

The previous prototype used `cmp [ctx + 0x70], imm; ja target` to emit a
verifier-visible `data + imm + 1 <= data_end` check. That path has been removed
from the active code because it was a proof-only branch assertion. Future SKB
range visibility must come from native x86 guards plus the `PACKET_LEN` ABI
relation, not from a hidden assertion attached to a branch.

For XDP packet-end compares, the simulator records:

```text
cmp packet_ptr, data_end
```

The previous prototype recorded this as `PACKET_END_IMM` and emitted an edge
assertion. That metadata/assertion path has been removed. If packet-end compares
are used for verifier range proof later, the proof must be part of a specified
semantics-preserving lowering, not a hidden assertion.

## 8. Entry Context Capability Preservation

Some native programs write output through ABI-defined fields of the original
context pointer, represented as:

```text
mov [rdi + 16], reg
mov [rdi + 20], reg
```

The C-authored `X86_SIM_RUN_OP` macro calls `x86_sim_prepare_ctx_output()` before
executing each non-loop helper. For ABI output stores, that helper reasserts:

```c
state.p_rdi = (void *)ctx;
state.tag_rdi = X86_PTR_CTX;
```

immediately before the store helper executes. The generator does not contain a
benchmark-specific or store-specific renderer for this.

Proof obligation:

```text
For any accepted program path that reaches an ABI output store, rdi must still
denote the entry ctx capability at that point, or the store must be covered by an
explicit ABI-output theorem. Reasserting the ghost capability before executing
the store helper must be observationally a no-op for the concrete x86 state.
```

This rule is not tied to a specific benchmark or loop exit shape.

## 9. Generator Correctness Contract

For a generated program:

```text
G = generate(native_program)
```

the generator must satisfy:

```text
1. Every supported native instruction is represented exactly once by either:
   a. one helper step, or
   b. one explicit branch/call/return edge, or
   c. one named lowering theorem in this document.

2. Address labels in G preserve native control-flow targets.

3. Any omitted native instruction must be covered by an explicit theorem.

4. Any ghost restore must be justified by a C helper/frame theorem.

5. No rule may depend on:
   - benchmark name,
   - expected result,
   - expected return value,
   - verifier error text,
   - measured runtime behavior.
```

## 10. Current Open Proof Gaps

These are not acceptable final assumptions; they are work items.

| Gap | Required proof or implementation |
| --- | --- |
| Full x86 flag coverage | Audit every helper flag rule against the subset of x86 opcodes emitted by current micro programs. |
| RODATA model | Specify each generated read-only table and prove indexed reads match the native constants. |
| Stack model bounds | Prove every modeled stack access maps to the correct x86 stack slot and prove the low-slot pointer-payload coverage is sufficient for the accepted artifact or reject before native execution. Runtime slot rejection is not a final safety mechanism. |
| Runtime unsupported semantics | `X86_SIM_UNSUPPORTED` is simulator behavior, not native x86 behavior. Final acceptance requires load-time rejection or a proof that each unsupported is unreachable under the accepted native program. Direct native x86 will not execute `X86_SIM_UNSUPPORTED` or return `XDP_ABORTED`. |
| Packet/output helper bounds checks | Active packet/output helpers must not insert runtime `data_end` bounds checks. Verifier acceptance must come from equivalent pointer state and native guards/ABI preconditions, not an extra checked-simulator guard. |
| Branch proof metadata | Removed from active code. Keep it out unless there is a formal theorem that preserves exact native x86 branch semantics and does not introduce proof-only assertions. |
| Hidden packet-offset metadata | Prove that `off_<reg>` is observationally invisible to x86 scalar execution and that every proven packet load reads the same modeled packet byte as the native effective address. |
| SKB packet-length metadata | Prove that `ctx+0x70` native loads exactly the SKB length and that the accepted native ABI satisfies `data + len == data_end`; `PACKET_LEN` may only express that ABI relation, not invent a branch-bound fact. |
| No semantic verifier hacks | Prove that no verifier aid changes x86 behavior: no fuel guard, no fixed loop trip bound, no fallback return, no benchmark-specific renderer, and no assertion over facts not guaranteed by the native execution. |
| ABI special cases | Prove the modeled `ctx`, `skb`, packet, output, and rodata layouts match the native execution ABI exactly; otherwise direct native execution may read/write addresses not covered by the proof. |
| Native call return address | Current generated callees assume the return-address slot is not read. A callee that reads it must be rejected or modeled with the concrete native return address. |
| Multi-exit loop verifier cost | Current micro passes 29/29, including `bpftrace_string_search_prefix_scan`. Any future structural lowering must still be a C/template theorem and preserve native branch semantics without fuel. |
| Paused PC-dispatch experiment | If revived, implement it as a C/template proof rule rather than Python CFG scheduling. It is not active now. |
| ABI output-store theorem | `x86_sim_prepare_ctx_output()` is C-authored, but the final proof still must show accepted paths reach `[rdi+16/20]` stores only when `rdi` denotes entry ctx, or explicitly define that ABI store as a semantic rule. |
| JSON-linker equivalence | Reuse this spec after JSON bytecode linking stops going through clang. |

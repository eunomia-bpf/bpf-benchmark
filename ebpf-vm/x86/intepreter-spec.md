# x86 eBPF-VM Interpreter Specification

This document specifies the verifier-facing generated-C interpreter path under
`ebpf-vm/x86`. It is intended to match the current code closely enough that each
rule can be translated into a later mechanized proof obligation.

The trusted shape is:

```text
native x86 instruction stream
  -> generated fixed eBPF/C interpreter schedule
  -> kernel eBPF verifier accepts the generated proof program
  -> native execution is justified only if the generated schedule is proved
     equivalent to the native x86 stream under this spec
```

The generator must not use benchmark names, expected return values, or observed
test failures to select semantics. Every non-local transformation below is a
named theorem obligation.

## 1. Scope

This spec covers the generated-C path:

- `ebpf-vm/x86/micro-prog/generate_micro_proofs.py`
- `ebpf-vm/x86/x86_interp.h`
- `ebpf-vm/x86/x86_vm_bpf.h`
- generated programs under `ebpf-vm/x86/micro-prog/*.bpf.c`

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
    tag_<reg> : NONE | CTX | PACKET | PACKET_END | RODATA | STACK,

  Modeled stack slots:
    stack0..stackN plus tag_stackN,
    p_stack_a/p_stack_b sparse verifier pointer payloads keyed by slot number,

  Packet verifier inputs:
    data, data_end,

  Control:
    current native address or return/done/trap
}
```

Concrete x86 arithmetic uses only the `GPR64` and `Flags` fields. The `p_*` and
`tag_*` fields are ghost verifier capabilities. They must not affect the
mathematical value of a scalar x86 register except by authorizing a memory
access that the native program would perform.

### Entry ABI

For XDP-style generated programs:

```text
rdi has ghost capability CTX(ctx)
ctx->data is modeled as PACKET(data)
ctx->data_end is modeled as PACKET_END(data_end)
rsp has ghost capability STACK when stack modeling is enabled
all other ghost capabilities start as NONE
```

The code implementation is `x86_init_state()` in `x86_interp.h`.

### Stack Pointer Payload Rule

Each modeled x86 stack slot stores its 64-bit value and a ghost tag. Real BPF
verifier pointer payloads are sparse: the implementation keeps at most two live
non-`STACK` pointer payloads in `p_stack_a` and `p_stack_b`, each keyed by the
slot number. A stack slot tagged `STACK` reconstructs its meaning from the
stored x86 stack offset and does not need a BPF pointer payload.

If a third live non-`STACK` verifier pointer is spilled to the modeled x86 stack,
the interpreter traps. The current micro corpus needs at most two live packet
pointer spills. A final proof must either keep this as an explicit accepted
subset or replace it with an unbounded/sufficiently bounded pointer-payload
model.

## 3. Instruction Step Relation

For every generated native instruction `I` at address `pc`, the generator emits
exactly one interpreter helper step, except for branches, calls, returns, and
named lowering rules in this document.

The interpreter step has the form:

```c
X86_VM_RUN_OP(op, dst, src, width, aux, imm);
```

The generated tuple `(op, dst, src, width, aux, imm)` is the encoded form of the
native instruction. C-authored interpreter macros may dispatch to typed helpers
or fast paths when compile-time constants prove the same x86 step, but Python
does not select those helpers. The C interpreter step must implement the
following relation:

```text
step(I, XState_in, Mem_in) = XState_out, Mem_out, Continue | Done | Trap
```

The proof obligation for each C interpreter step/helper is:

```text
For every supported native instruction I encoded as args,
helper(args, XState_in, Mem_in) implements the same state transition as
the x86 ISA rule for I, restricted to the modeled memory/capability domain.
```

Compiler optimization is not part of the semantic proof. Clang inlining and
constant propagation may specialize fixed `(op, dst, src, aux, imm)` records so
the kernel verifier can analyze the eBPF program, but the correctness statement
is over the C-authored interpreter/helper relation above.

Compile-cost fixes must preserve this boundary. Python may continue to emit the
simple native instruction stream and label metadata, but it must not grow
program-shape logic to make a hard case easier for clang or the verifier. Any
compile-cost reduction belongs in the C-authored interpreter/header/macro layer:
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
PACKET:      access is allowed only if data <= addr and addr + width <= data_end
PACKET_END:  comparable pointer only; not directly dereferenceable
CTX:         only modeled ABI reads/writes are allowed
STACK:       access is mapped to explicit modeled stack slots
RODATA:      access is mapped to a generated read-only table model
NONE:        memory access traps
```

Packet and stack accesses in helpers must be proved equivalent to native memory
accesses under the ABI assumption that the native program is only allowed to
observe the modeled packet/output/stack domains.

## 4. Branches And Returns

Conditional native branches are emitted as:

```c
X86_VM_X86_JCC(cc, current_pc, target_pc, target_label);
```

The proof obligation is:

```text
x86_eval_cc(state, cc) equals the x86 condition-code predicate over
state.cf/state.zf/state.sf/state.of.
```

Unconditional native branches are emitted as:

```c
X86_VM_X86_JMP(current_pc, target_pc, target_label);
```

These are x86 instruction-lowering macros, not a separate VM instruction set.
The generated operation is still native `jcc`/`jmp`; the C-authored macro owns
the verifier lowering to `goto target_label`. Python does not infer loop bounds,
induction variables, exits, or callback state. It only supplies the native
current/target addresses and target label. A taken backward edge has the same
control-flow meaning as native x86: jump to the target label. Any verifier
rejection for an unprovable or too-expensive loop is a verifier result, not a VM
semantic fallback.

Native `ret` is emitted as:

```c
X86_VM_X86_RET();
```

This returns the low 32 bits of `rax` to the BPF test-run ABI. Program-type
success return values are external metadata (`expected_retval` in
`micro/config/micro_pure_jit.yaml`), not generator semantics.

## 5. Native Calls

Known direct native call targets are disassembled and emitted as generated
subfunctions:

```c
static X86_VM_SUBFN_ATTR int x86_fn_<symbol>(
    struct x86_state *state, void *data, void *data_end);
```

The native call site is emitted as:

```c
X86_VM_X86_CALL(x86_fn_<symbol>);
```

The generated subfunction body starts with:

```c
X86_VM_SUB_BEGIN();
```

and every native callee `ret` is emitted as:

```c
X86_VM_X86_SUB_RET();
```

`X86_VM_X86_CALL()` is a C-authored protocol macro. It models the native call
stack effect by reserving one return-address slot on the modeled x86 stack
before entering the generated callee and releasing that slot after the callee
returns. The return-address value itself is currently modeled as scalar zero
because none of the generated micro callees inspect it.

`X86_VM_SUB_BEGIN()` only declares the per-callee instruction record. Generated
callee prologue/epilogue instructions such as `push rbp`, `mov rbp, rsp`, and
`pop rbp` execute through normal x86 helper steps. Callee-saved register
preservation is therefore provided by those generated x86 instructions, not by a
separate hidden wrapper restore.

Subfunction branches use the subfunction branch macros:

```c
X86_VM_X86_SUB_JCC(cc, current_pc, target_pc, target_label);
X86_VM_X86_SUB_JMP(current_pc, target_pc, target_label);
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

Current verifier consequence: plain native backedges are semantically clean but
not verifier-friendly for all bounded loops. `packet_checksum_fold` and
`tc_packet_checksum_fold` hit the kernel verifier's `8193 jumps too complex`
limit, and `bpftrace_string_search_prefix_scan` hits the global
processed-instruction limit. Any fix must be a C/template proof rule, not a
Python benchmark renderer and not a fuel bound.

### Non-Active Loop Experiments

The active implementation does not contain a loop `pc` field and does not emit
pc-dispatch basic-block callbacks. That experiment was removed from the active
generator because it moved CFG scheduling complexity into Python and did not
fix the two remaining verifier `E2BIG` failures.

The previous Python-generated `bpf_loop(bound, callback, &loop_ctx, 0)` lowering
has also been removed from the active generator for the same reason. It is not
part of the current proof contract.

## 7. Indexed Packet Addressing

x86 permits equivalent effective-address forms such as:

```text
[packet_ptr + scalar + disp]
[scalar + packet_ptr + disp]
```

The C interpreter treats a scale-1 index register tagged `PACKET` as the packet
base when the nominal base register is scalar. This is implemented by
`x86_promote_index_packet_base()` under `X86_VM_ENABLE_INDEX_PACKET_PROMOTE`.
Packet fastpaths in `x86_vm_bpf.h` are restricted to no-index operands so they
cannot bypass this full addressing rule.

## 8. Entry Context Capability Preservation

Some native programs write output through ABI-defined fields of the original
context pointer, represented as:

```text
mov [rdi + 16], reg
mov [rdi + 20], reg
```

The C-authored `X86_VM_RUN_OP` macro calls `x86_vm_prepare_ctx_output()` before
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
| Stack model bounds | Prove every modeled stack access maps to the correct x86 stack slot and prove the sparse two-payload pointer-spill rule is sufficient or replace it. |
| Multi-exit loop state explosion | Add a theorem or structural lowering for priority among exits before using any non-`goto` loop proof protocol. |
| Paused PC-dispatch experiment | If revived, implement it as a C/template proof rule rather than Python CFG scheduling. It is not active now. |
| ABI output-store theorem | `x86_vm_prepare_ctx_output()` is C-authored, but the final proof still must show accepted paths reach `[rdi+16/20]` stores only when `rdi` denotes entry ctx, or explicitly define that ABI store as a semantic rule. |
| Native backedge verifier cost | Add a C/template loop proof protocol for bounded native loops that exceed verifier jump/processed-insn limits without introducing fuel semantics. |
| JSON-linker equivalence | Reuse this spec after JSON bytecode linking stops going through clang. |

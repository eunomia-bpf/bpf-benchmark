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
    stack0..stackN plus p_stackN/tag_stackN,

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

## 3. Instruction Step Relation

For every generated native instruction `I` at address `pc`, the generator emits
exactly one interpreter helper step, except for branches, calls, returns, and
named lowering rules in this document.

The helper call has the form:

```c
X86_VM_RUN_OP(helper, op, dst, src, width, aux, imm);
```

or inside a loop callback:

```c
X86_VM_LOOP_OP(helper, op, dst, src, width, aux, imm);
```

The generated tuple `(op, dst, src, width, aux, imm)` is the encoded form of the
native instruction. The helper must implement the following relation:

```text
step(I, XState_in, Mem_in) = XState_out, Mem_out, Continue | Done | Trap
```

The proof obligation for each helper is:

```text
For every supported native instruction I encoded as args,
helper(args, XState_in, Mem_in) implements the same state transition as
the x86 ISA rule for I, restricted to the modeled memory/capability domain.
```

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
if (x86_eval_cc(&state, cc))
    goto target;
```

or, inside a loop callback:

```c
if (x86_eval_cc(&state, cc)) {
    ...
}
```

The proof obligation is:

```text
x86_eval_cc(state, cc) equals the x86 condition-code predicate over
state.cf/state.zf/state.sf/state.of.
```

Native `ret` is emitted as:

```c
X86_VM_RET_RAX();
```

This returns the low 32 bits of `rax` to the BPF test-run ABI. Program-type
success return values are external metadata (`expected_retval` in
`micro/config/micro_pure_jit.yaml`), not generator semantics.

## 5. Native Calls

Known direct native call targets are disassembled and emitted as generated
subfunctions:

```c
static __noinline int x86_fn_<symbol>(
    struct x86_state *state, void *data, void *data_end);
```

The subfunction proof obligation is:

```text
Executing x86_fn_symbol from state S is equivalent to executing the native
callee instruction stream from its entry until its native ret.
```

Current generated subfunctions save and restore the SysV callee-saved register
set:

```text
rbx rbp r12 r13 r14 r15
```

If a callee relies on stack-frame traffic that the wrapper suppresses, the
wrapper rule must prove that the suppressed native push/pop/mov frame sequence
is observationally equivalent under the modeled stack ABI.

## 6. Loop Lowering

The generator may lower a native counted loop to:

```c
bpf_loop(bound, callback, &loop_ctx, 0)
```

This is allowed only when a static loop analysis has identified:

```text
region_start
region_end
entry
exit_addrs
induction register iv
init value
positive step
cmp limit
backedge condition
bound = ceil((limit - init) / step)
```

The lowering theorem is:

```text
If the native loop starts in a state satisfying the induction invariant,
and each callback execution implements exactly one native loop iteration,
then bpf_loop(bound, callback, ctx, 0) implements the native loop until
the first native exit.
```

### Exact-Trip Backedge Rule

For a single-exit loop with exact trip count:

```text
len(exit_addrs) == 1
bound == raw_bound
```

the callback may emit:

```c
if (__x86_loop_index + 1 >= bound) {
    loop->next = exit_addr;
    return 1;
}
if (native_backedge_condition)
    return 0;
```

This is not a benchmark-specific correction. It is justified by the theorem:

```text
At callback index bound - 1, after executing the native loop body and the
native compare instruction, the native backedge condition is false and control
falls through to exit_addr.
```

The generator must not choose this rule based on return value, benchmark name,
or observed failure.

### Multi-Exit Loops

For multi-exit loops, callback code must set:

```c
loop->next = native_exit_addr;
return 1;
```

for the specific native exit taken. No exact-trip fallback may be used unless a
separate theorem proves priority among exits.

### Non-Active PC-Dispatch Experiment

The active implementation does not contain a loop `pc` field and does not emit
pc-dispatch basic-block callbacks. That experiment was removed from the active
generator because it moved CFG scheduling complexity into Python and did not
fix the two remaining verifier `E2BIG` failures.

Any future pc-dispatch rule must be C-authored or bytecode-template-authored
and must be added back to this spec before use. It is not part of the current
proof contract.

## 7. Loop Frame Preservation

The loop callback may widen verifier knowledge of stack-carried ghost fields.
The active implementation handles the `rdi` case in the C loop protocol instead
of Python write-set insertion.

Current implemented frame rule:

```text
During a loop callback:
  X86_VM_LOOP_OP marks loop.rdi_written when an opcode writes X86_RDI.
  X86_VM_LOOP_CALL marks loop.rdi_written for native direct calls.

After bpf_loop returns:
  if loop.rdi_written == 0:
    state.rdi     = saved_rdi
    state.p_rdi   = saved_p_rdi
    state.tag_rdi = saved_tag_rdi
```

This is valid for paths where the C loop protocol records no RDI write. For
concrete x86 correctness, the restore is observationally a no-op on those paths.
For verifier correctness, it preserves the ghost capability needed by later
memory helpers.

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

3. Any omitted native instruction must be covered by an explicit theorem
   (for example synthetic frame traffic in generated call wrappers).

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
| Stack model bounds | Prove every modeled stack access maps to the correct x86 stack slot after synthetic frame rewrites. |
| Multi-exit loop state explosion | Add a theorem or structural lowering for priority among exits before using exact-trip fallback on multi-exit loops. |
| Paused PC-dispatch experiment | If revived, implement it as a C/template proof rule rather than Python CFG scheduling. It is not active now. |
| ABI output-store theorem | `x86_vm_prepare_ctx_output()` is C-authored, but the final proof still must show accepted paths reach `[rdi+16/20]` stores only when `rdi` denotes entry ctx, or explicitly define that ABI store as a semantic rule. |
| Native call loops | Prove or refactor loop callbacks that call large generated subfunctions without exceeding verifier complexity. |
| JSON-linker equivalence | Reuse this spec after JSON bytecode linking stops going through clang. |

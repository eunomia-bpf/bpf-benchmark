# ReverseJIT x86 eBPF-VM Link Spec

Status: experimental specification. This file defines the model used by the
`ebpf-vm/x86` JSON-link prototype. It is a formalization target, not a completed
proof.

## Goal

Every micro program should be accepted through this path:

```text
native x86 disassembly
  -> Python emits JSON schedule
  -> loader links JSON schedule with C-authored eBPF templates
  -> kernel verifier accepts linked eBPF
  -> BPF_PROG_TEST_RUN returns the micro expected result
```

Python may decode x86 and produce declarative records. Python must not emit
verifier-facing BPF semantics. C owns instruction helper semantics. The loader
owns bytecode linking, branch fixups, pseudo-call fixups, BPF load attributes,
and test-run plumbing.

## State

Let an x86 machine state be:

```text
X = (R, F, M)
R: x86 register -> 64-bit word
F: {cf, zf, sf, of}
M: memory object -> bytes
```

The verifier-facing linked state is:

```text
V = (R, T, F, P, S)
R: x86 register -> 64-bit word
T: x86 register -> capability tag
F: {cf, zf, sf, of}
P: packet memory capability = (data, data_end)
S: finite ghost stack slots
```

Tags are:

```text
NONE | CTX | PACKET | PACKET_END | RODATA | STACK
```

The linked-path ABI deliberately stores packet positions as scalar offsets, not
as raw kernel pointers:

```text
T[r] = PACKET      => R[r] is an offset from data
T[r] = PACKET_END  => R[r] is packet length
T[r] = CTX         => R[r] is not a CPU address; ctx fields are modeled
T[r] = NONE        => R[r] is an ordinary scalar
```

This differs from native x86 registers, which hold CPU addresses. The refinement
relation connects them:

```text
Ref(X, V) iff:
  if V.T[r] = PACKET then X.R[r] = addr(data) + V.R[r]
  if V.T[r] = PACKET_END then X.R[r] = addr(data_end)
  if V.T[r] = NONE then X.R[r] = V.R[r]
  flags match
  every modeled memory byte agrees
```

So the verifier program does not claim that `R[r]` is a raw pointer. It claims a
capability plus offset that refines the native pointer under the program ABI.

## Instruction Step Relation

Each JSON step has:

```text
(helper, op, dst, src, flags, aux, imm, flow, target)
```

The intended small-step judgment is:

```text
Exec(helper, args, V, P) -> (V', control)
```

where `control` is one of:

```text
continue | done | trap | branch_taken
```

For ordinary helper steps:

```text
control = continue  => next pc = pc + 1
control = done      => exit with V.R[rax]
control = trap      => XDP_ABORTED
```

For conditional branch steps:

```text
control = branch_taken => next pc = target
control = continue     => next pc = pc + 1
```

The loader is responsible only for materializing this fixed control-flow graph.
It is not allowed to implement x86 helper semantics.

## Memory Semantics

For packet load/store:

```text
base_tag = PACKET
off = R[base] + disp + index * scale
0 <= off
off + width <= packet_len
```

Then:

```text
load  reads bytes P.data[off .. off+width)
store writes bytes P.data[off .. off+width)
```

The verifier-facing implementation must perform scalar bounds checks before
constructing `data + off`, because the eBPF verifier rejects packet-pointer
arithmetic with unconstrained scalars.

For `CTX` in the micro XDP prototype:

```text
mov reg, [rdi + 0]  => reg := 0,          tag := PACKET
mov reg, [rdi + 8]  => reg := packet_len, tag := PACKET_END
```

This models the two fields of `struct xdp_md` used by the native micro entry:
`data` and `data_end`. The native refinement maps those offsets back to real CPU
addresses.

## Helper Granularity

Templates are instruction-class helpers, not whole-program blobs.

```text
x86_tmpl_alu_imm
x86_tmpl_alu_reg
x86_tmpl_mov_load
x86_tmpl_mov_store_imm
x86_tmpl_cmp_reg
...
```

ALU helpers share one helper per operand form and use `aux = X86_ALU_*` for the
operation. If a helper is too hard for the verifier, it may be split by
instruction subclass, but not by individual micro program.

## Loader Obligations

The loader must:

1. parse JSON schedule;
2. reject unsupported helper names or unsupported flow kinds;
3. load C-authored template bytecode from `x86_template_helpers.bpf.o`;
4. create a main BPF glue program with fixed CFG;
5. load `packed_args` and `imm` constants for each step into BPF argument
   registers;
6. inline the selected C-authored `x86_tmpl_arg_*` template body;
7. rewrite template-local `exit` instructions into fall-through jumps back to
   linker glue;
8. resolve all branch offsets;
9. call `BPF_PROG_LOAD` and `BPF_PROG_TEST_RUN`.

The loader must not:

```text
emit_x86_mov_load(...)
emit_x86_alu_reg(...)
evaluate x86 flags
specialize memory semantics per micro
silently skip unsupported micro programs
```

## Proof Obligations

Not proven here, but required by the final design:

1. JSON decode correctness: every JSON step matches the selected native x86
   instruction.
2. Template correctness: each C helper implements the small-step relation above.
3. Linker correctness: branch fixups, template inlining, and argument-load
   patching preserve the JSON CFG and helper parameter record.
4. ABI refinement: native x86 state refines verifier offset/capability state.
5. Safety transfer: if the linked BPF program passes the verifier and native
   execution refines the linked state, native execution respects the same memory
   policy.

## Current Implementation Notes

The first subprogram-call linker showed why raw packet pointers cannot be stored
inside VM state across helper calls: the verifier reloaded them as scalars in a
later subprogram. The linked ABI therefore uses packet offsets plus tags and
recomputes packet pointers inside memory helpers after bounds checks.

Current implementation detail: tags are stored in 64-bit scalar slots in the
linked state, not in byte-sized tag fields, because the verifier does not retain
enough precision for byte stack stores/loads across the linked helper sequence.
The byte tag fields remain part of the C struct for the older generated-C
prototype; the strict JSON-link path treats the 64-bit slots as the verifier
contract.

This is not arbitrary x86. It is x86 under the ReverseJIT ABI: pointer-valued
registers have capability meaning, and direct native execution must be proven to
refine the same capability/offset behavior.

Current validation status: the strict JSON-link path passes all 29 micro
programs with this pipeline:

```text
python native disassembly decoder
  -> JSON schedule with helper IDs and numeric arguments
  -> Rust loader inline-links C-authored `x86_tmpl_arg_*` bytecode
  -> BPF_PROG_LOAD
  -> BPF_PROG_TEST_RUN expected-result check
```

The key verifier engineering point is that the C-authored template body is
inlined into the main program after the loader loads constant `packed_args` and
`imm` values. That keeps the helper semantics in C while still letting the
kernel verifier prune unreachable width/op/address-mode branches.

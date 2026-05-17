# ReverseJIT Research Note

Status: research direction

## Core Idea

ReverseJIT treats eBPF as a verification ISA and native code as the execution
ISA.

The program submitted to the kernel is not an arbitrary native binary. It is a
dual-semantics instruction stream. Each instruction has two kernel-defined
meanings:

- verifier semantics: ordinary eBPF behavior that the existing eBPF verifier can
  check;
- execution semantics: native x86 or arm64 code emitted by the kernel JIT path.

The verifier checks the eBPF semantics. Runtime executes the bound native
semantics.

In one sentence:

```text
ReverseJIT keeps the eBPF safety model, but swaps the post-verification
execution representation from eBPF JIT output to a semantically coupled native
representation.
```

## What This Is Not

ReverseJIT is not traditional proof-carrying code.

In classic PCC, a user supplies native code plus a proof. The kernel checks the
proof and then runs the native code without runtime checks. ReverseJIT does not
require the user to submit a proof. The user submits only instructions from a
kernel-defined dual-semantics ISA. The verifier-visible semantics are already
eBPF, so the existing eBPF verifier remains the proof checker for safety.

ReverseJIT is also not "userspace says this native blob is equivalent, trust
me". It needs a kernel-trusted binding between verifier-visible semantics and
native execution semantics. That binding can be a kernel-defined instruction ABI,
a formally verified translator in the trusted computing base, or a certificate
checker. What it does not require is a human-written proof supplied by every
user program.

The critical distinction is:

```text
PCC:
  user native code + user proof -> proof checker -> native execution

ReverseJIT:
  kernel-defined dual-semantics program -> eBPF verifier -> native execution
```

## Relation To kinsn

Current kinsn is the mechanism. ReverseJIT is the architecture.

The current kinsn model is local:

```text
ordinary eBPF program
  selected patterns become kinsns
  verifier sees instantiate_insn()
  JIT executes emit_x86() / emit_arm64()
```

That is a good proof-of-concept, but it looks like a superinstruction or JIT
optimization if used only for a few peepholes.

ReverseJIT generalizes the same dual-semantics idea to the whole program:

```text
whole translated region is kinsn-like
  verifier semantics = eBPF
  execution semantics = native x86/arm64
```

This changes the framing:

- kinsn as a local optimization: accelerate selected BPF patterns;
- ReverseJIT as a system: define a native execution ABI whose safety contract is
  exactly the eBPF verifier contract.

The best implementation path is incremental:

1. keep current kinsn as the minimal kernel mechanism;
2. expand the instruction set from peephole kinsns to a fuller native-shadow ISA;
3. move from mixed BPF+kinsn programs toward all-kinsn translated regions;
4. when coverage is high enough, ordinary eBPF becomes mostly the verifier-facing
   semantics, while runtime follows the native semantics.

## Safety Model

The intended safety claim is:

```text
Any ReverseJIT program accepted by the existing eBPF verifier is safe under the
same memory, pointer, helper, and control-flow policy as ordinary eBPF, provided
all executable native behavior is produced only by kernel-defined instruction
semantics.
```

The kernel must not accept arbitrary x86 or arm64 blobs under this model. Native
execution is safe only because each executable operation is tied to an
eBPF-verifier-visible operation owned by the kernel ABI.

The user or compiler can produce ReverseJIT bytecode, but the producer is not
trusted for safety. The trusted parts are:

- the existing eBPF verifier;
- the kernel's dual-semantics instruction definitions;
- the architecture-specific native emitters;
- the ABI rules that prevent native code from observing or mutating state not
  represented in the verifier semantics.

## Safety Transfer Argument

The strongest safety argument is a refinement argument:

```text
native program P
  -> translate(P) = eBPF program B
  -> verifier accepts B
  -> trusted equivalence proof: P refines B under the ReverseJIT ABI
  -> execute P
```

If the verifier proves `B` safe, and the trusted equivalence proof says every
observable behavior of `P` is allowed by `B`, then `P` inherits the eBPF safety
property:

```text
safe(B) and P refines B => safe(P)
```

This is the precise reason direct native execution can be safe. The native code
does not become safe merely because some separate eBPF VM was verified. It
becomes safe because the kernel's trusted mechanism establishes that the native
program being executed is the same program, semantically, as the verifier-accepted
eBPF program.

There are several possible bindings:

- kernel-owned dual-semantics instructions: each payload has one
  `instantiate_insn()` and one native emitter, both owned by the kernel/module
  ABI;
- kernel-generated native code: the kernel JIT emits `P` from verified `B`, which
  is the ordinary BPF JIT model;
- trusted verified translator: a kernel-trusted component translates `P` to `B`
  or `B` to `P`, and its correctness proof is part of the TCB;
- certificate checking: userspace submits `P`, `B`, and an equivalence
  certificate that the kernel checks before executing `P`.

What is not a security boundary:

```text
userspace submits safe B
userspace also submits arbitrary unsafe P
kernel verifies B
kernel executes P without checking or owning the P == B binding
```

That construction is unsafe because the verified artifact and the executed
artifact are not connected inside the kernel trust boundary.

Native memory operations are safe only under this refinement relation. For
example, an executed native instruction such as:

```asm
mov rax, [rdi + 8]
```

is safe if the equivalence proof ties `rdi + 8` to a verifier-approved BPF
pointer access with the same bounds, object, and fault behavior. It is not safe
if verifier-visible `rdi` is only a scalar guest offset while native `rdi` is
used by the CPU as a raw kernel virtual address. In that case the native program
does not refine the verified eBPF program.

This means ReverseJIT does not inherently require extra SFI on the final native
path. SFI is only one way to make native memory operations match a sandboxed VM
semantics. If the original x86 program is already safe under an eBPF-like ABI,
and the verifier-facing translation faithfully represents the real x86 semantics
that will execute, then verifier acceptance of `B` plus equivalence `P == B` is
enough:

```text
original x86 already follows verifier-safe pointer/bounds rules
faithful x86-to-eBPF translation passes verifier
trusted equivalence says executed x86 is that same semantics
=> no extra SFI is needed
```

The important failure mode is an unfaithful translation. For example, translating
an x86 memory access into a sandboxed interpreter operation:

```text
guest_addr = rax
if guest_addr + 8 > guest_mem_size: trap
load guest_mem[guest_addr]
```

proves the safety of sandboxed x86 VM semantics, not the safety of directly
executing:

```asm
mov rbx, [rax]
```

against the real kernel address space. Direct execution is safe only when the
eBPF artifact checked by the verifier is a faithful model of the native code that
will actually run.

## State Model

ReverseJIT can represent a native machine state using verifier-visible eBPF
state.

Example for x86:

| Native State | Verifier-Visible State | Runtime State |
|---|---|---|
| `rax`, `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `rbx`, `r13`, `r14`, `r15` | mapped BPF registers | mapped physical registers |
| extra registers such as `r10`, `r11`, `r12` | fixed ghost stack slots or scalar shadow locations | hidden physical registers |
| flags / condition state | explicit scalar shadow state | native flags when locally valid, or hidden flag state |
| program memory accesses | verifier-checked BPF pointer operations | equivalent native loads/stores |

Ghost stack slots are verifier state, not necessarily real memory used by native
execution. The native side may keep the corresponding value in a hidden physical
register, as long as all operations that can observe or update that state are
represented by ReverseJIT instructions with matching verifier semantics.

## Boundary Rules

The hard part is not arithmetic instructions. The hard part is observation
boundaries.

These operations must have explicit ABI rules:

- helper calls;
- kfunc calls;
- tail calls;
- exits and return values;
- stack pointer escapes;
- map, packet, ctx, and dynptr accesses;
- branches and branch target relocation;
- native flags across instruction boundaries;
- callee-saved and caller-clobbered native registers;
- exception or fault behavior for native memory operations.

The safe rule is:

```text
Any operation that can observe verifier-visible state or expose native hidden
state must either be represented by a ReverseJIT instruction with verifier
semantics, or pass through a boundary adapter that materializes the verifier
state expected by ordinary eBPF.
```

For example, a hidden native register may stand for a verifier ghost stack slot
inside a closed ReverseJIT region. But before an ordinary helper is allowed to
read a pointer to that stack slot, the ABI must either materialize the value to
real stack memory or reject that program shape.

## Kernel Interface Shape

The natural kernel interface is close to kinsn:

```c
struct reversejit_insn {
        int (*instantiate_insn)(payload, struct bpf_insn *buf);
        int (*emit_x86)(payload, ...);
        int (*emit_arm64)(payload, ...);
};
```

`instantiate_insn()` is the verifier source of truth. Native emitters are the
execution refinements.

The verifier path lowers ReverseJIT instructions to ordinary BPF semantics and
checks the resulting program. The JIT path emits the native semantics instead.

For this to become a full-program substrate rather than a peephole mechanism,
the kernel interface likely needs:

- branch-aware kinsn proof lowering, not only local proof sequences;
- a way to encode or relocate program-level branch targets;
- region-level hidden-state layout;
- explicit boundary adapters for calls, tail calls, exits, and helper-visible
  stack state;
- per-architecture register allocation and save/restore rules for hidden native
  registers.

## Relation To An eBPF-Written x86 VM

An eBPF implementation of an x86 VM is useful as a semantic model, but it is not
the runtime path if the goal is native performance.

If the eBPF VM is actually executed, performance is interpreter performance. If
the eBPF VM is only verifier-facing and native x86 is executed instead, then the
VM is a semantic witness, not the security mechanism by itself. The security
mechanism is the trusted proof that the executed native program refines the
verified VM/eBPF semantics.

ReverseJIT makes that binding part of the kernel instruction ABI:

```text
eBPF VM / instantiate_insn: verifier-facing semantics
native emit: execution semantics
kernel ABI: binds the two
```

## Related Work Positioning

The closest ancestor is proof-carrying code for safe kernel extensions:

- George C. Necula and Peter Lee, "Safe Kernel Extensions Without Run-Time
  Checking", OSDI 1996.

That work checks a user-provided proof for native code. ReverseJIT instead uses
the existing eBPF verifier over verifier-visible semantics and does not require
the user to provide a proof.

Translation validation is related in two different ways. For the kernel-defined
dual-semantics instruction model, it can be an offline implementation validation
technique:

- validate that a native emitter implements the same semantics as
  `instantiate_insn()`;
- validate that a frontend lowering to ReverseJIT preserves source semantics.

For a more aggressive "submit native `P` plus verifier artifact `B`" model,
translation validation or certificate checking becomes the core binding
mechanism. The important distinction is that the checked fact is equivalence
`P == B`; the eBPF verifier still checks the safety of `B`.

Native Client, RockSalt, and native machine-code validators are related because
they safely execute native code. Their safety model validates or restricts native
machine code directly. ReverseJIT instead avoids arbitrary native validation by
restricting the executable representation to a kernel-defined dual-semantics
ISA.

Verified eBPF JIT work is also related but opposite in direction:

```text
verified eBPF JIT:
  eBPF source -> prove generated native code preserves eBPF semantics

ReverseJIT:
  dual-semantics source -> verifier checks eBPF semantics -> execute bound native
  semantics
```

## Paper Framing

A good paper framing is not "another eBPF JIT optimization". It is:

```text
eBPF as a verification-only ISA, native code as the execution ISA.
```

Possible title:

```text
ReverseJIT: eBPF as a Verification ISA for Native Kernel Extensions
```

The main systems claim should be:

```text
ReverseJIT preserves the eBPF verifier safety model while allowing programs to
execute through a native representation whose semantics are bound to the verified
eBPF representation by the kernel ABI.
```

For a strong systems paper, the evaluation needs to show:

- broad instruction coverage, not only a few peepholes;
- real eBPF workloads, not only microbenchmarks;
- performance close to native x86/arm64 and better than the existing eBPF JIT;
- small and understandable verifier changes;
- a clear accounting of the added trusted code base;
- failure cases where the verifier rejects invalid ReverseJIT programs naturally.

## Main Risks

The idea is viable, but the risks are sharp:

- If native code is arbitrary, this collapses back into PCC or native validation.
- If the kernel does not own or check the binding between verified eBPF and
  executed native code, the safety argument does not hold.
- If only a few instructions are covered, the work looks like superinstructions.
- If helper/call/stack boundaries are underspecified, the safety claim is weak.
- If native emitters are large and ad hoc, the TCB story becomes difficult.
- If verifier-visible state and hidden native state can diverge across branches,
  the model becomes unsound.

The strongest version is therefore conservative:

```text
ReverseJIT programs are not arbitrary native binaries. They are programs in a
kernel-defined dual-semantics ISA. The verifier checks the eBPF semantics, and
the JIT executes the native semantics bound to the same instruction definitions.
```

That is the key difference from both traditional proof-carrying code and the
current local kinsn optimization model.

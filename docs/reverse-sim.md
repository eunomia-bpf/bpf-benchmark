# ReverseSim Research Note

Status: research direction

## Project Context: Three Sister Ideas

This research project produces three distinct papers that share a single
evaluation setup (the `bpf-benchmark` corpus, micro suite, and measurement
infrastructure) but address different problems with different designs and
implementations.

| # | Idea | Problem | Design center | Kernel change |
|---|---|---|---|---|
| 1 | **Speculative eBPF optimization** | Already-loaded eBPF programs miss optimization opportunities that only become visible after the program is live (map contents stabilize, branch profile emerges, helper-call patterns). | Pure-userspace tool that observes live programs, applies BPF-to-BPF rewrite passes (`map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `branch_flip`, ...) and swaps in an optimized candidate using the stock kernel's atomic-or-near-atomic attachment update mechanisms. | Near zero. |
| 2 | **Kinsn** | The eBPF instruction set is too far from hardware to express several native-equivalent optimizations (rotate, conditional select, BMI bit-field extract, BLS instructions, prefetch). | A new OS abstraction: kernel-defined dual-semantics instructions, where the verifier sees `instantiate_insn()` lowering to ordinary eBPF and the JIT executes a per-architecture `emit_*()`. Likely also LLVM backend support and a userspace optimizer to recognize candidate patterns. | Verifier + JIT additions, one structure per kinsn, growing TCB but bounded. |
| 3 | **ReverseSim** (this doc) | Run arbitrary x86/arm64 native code safely inside the kernel without requiring the developer to write eBPF or to submit a separate proof. | An x86 or arm64 simulator (or a JIT that emits eBPF) written in eBPF C. Specialization to a specific target program collapses the simulator to straight-line eBPF, which the stock verifier checks. The kernel JIT then lowers it to native. | Near zero. |

The three are not incremental versions of one design. Each picks a different
problem and a different point in the trust / kernel-surface / coverage space.
This doc is about idea #3. Idea #1 lives in
`docs/optimization-architecture-vision.md`. Idea #2 lives in
`docs/kinsn-design.md` and `docs/kinsn-formal-semantics.md`.

A kernel-ABI variant of "ReverseSim" (dual-semantics ISA owned by the kernel)
was an earlier framing of idea #3. It overlaps heavily with idea #2 and is now
recorded only as an alternative path in section
[Alternative Path: Kernel-ABI Dual-Semantics ISA](#alternative-path-kernel-abi-dual-semantics-isa).

## Core Idea

ReverseSim writes a target-ISA simulator or JIT in C,
compiles it with clang to eBPF, and lets the existing eBPF verifier check the
result. The kernel does not learn a new ISA, does not gain a new syscall, and
does not host any new emit path.

```text
target native binary (x86 or arm64)
  -> compile-time specialization of a trusted simulator or JIT written in C
  -> eBPF program
  -> stock kernel verifier accepts (memory, pointers, calls, control flow)
  -> stock kernel JIT lowers to native
  -> native execution
```

In one sentence:

```text
ReverseSim brings native code into the eBPF safety model by
treating an eBPF-written simulator (or JIT) as the trusted lowering and the
stock eBPF verifier as the safety checker.
```

The user does not submit native code to the kernel. The user submits the
specialized eBPF representation of the native code. The native machine in
kernel still executes only what the stock JIT emits.

Two implementation strategies sit inside this idea:

- **ReverseSim**: a target-ISA simulator in C, specialized to one
  target program by clang constant propagation. Compile time is fast (per-program
  specialization, not per-load LLVM run). Detailed in [Mechanism](#mechanism).
- **ReverseSim-in-eBPF**: a native-to-eBPF JIT written in C, compiled to eBPF,
  invoked offline against the target program to emit the eBPF artifact. The
  produced eBPF is checked by the stock verifier. The JIT itself is verified
  once; per-program use is just running the JIT. Has the same trust profile as
  the simulator variant.

Both are eBPF-written. Both rely on the same safety transfer argument. They
differ in whether specialization is a clang job (simulator variant) or an
explicit emitter job (JIT variant).

## What This Is Not

This is not traditional proof-carrying code.

In classic PCC, a user supplies native code plus a proof. The kernel checks the
proof and runs the native code without runtime checks. ReverseSim does not
require the user to submit a proof. The user submits an eBPF program produced
by a trusted lowering, and the existing eBPF verifier is the proof checker.

```text
PCC:
  user native code + user proof
    -> proof checker
    -> native execution

ReverseSim:
  user native program
    -> trusted lowering (simulator or JIT, both written in eBPF)
    -> eBPF
    -> stock eBPF verifier
    -> stock JIT
    -> native execution
```

This is not "trust me, this native blob is equivalent to that eBPF". The native
code path that runs in kernel is the kernel-JIT-emitted lowering of an eBPF
program the verifier accepted, not a user-supplied native blob.

This is not arbitrary-native-binary execution. If the target program has
genuinely untranslatable behavior (computed indirect call to an unrecognized
kernel address, jump tables built from runtime data with unbounded target sets,
unsupported SIMD instructions), specialization fails and the program is
rejected before reaching the verifier.

## Relation To kinsn

Kinsn (idea #2) and ReverseSim (idea #3) attack the same
underlying question — how to make non-trivial native operations available
inside the eBPF safety model — from opposite ends:

- Kinsn extends the kernel-side instruction set with kernel-defined
  dual-semantics primitives. Each new primitive grows the kernel TCB by a small
  amount.
- ReverseSim extends the userspace-side lowering with a verified
  simulator or JIT. The kernel stays unchanged. The added TCB is a userspace
  artifact: one C file per target ISA, verifiable independently.

Kinsn covers "a handful of patterns that ordinary eBPF can't express well".
ReverseSim covers "anything the target ISA can express, subject to
verifier-tractable lowering". The two are not exclusive: a kinsn-aware kernel
combined with a ReverseSim that emits kinsns where helpful is a natural
ablation point, but neither requires the other.

## Mechanism

This section specifies the ReverseSim variant. The ReverseSim-in-eBPF
variant uses the same lowering rules but performs them in an explicit emitter
rather than relying on clang specialization; see
[ReverseSim-In-eBPF Variant](#reversesim-in-ebpf-variant).

### Per-Program Specialization

Write a target-ISA simulator in C. For each user program:

1. The target native binary is treated as data: an array of native instructions
   and an entry PC, both `static const` in the specialized source.
2. The simulator is specialized to that data at compile time. Because the
   instruction array is constant from the compiler's point of view, clang's
   constant propagation and switch-table lowering unroll the dispatch loop into
   a straight-line sequence of per-instruction handlers.
3. The kernel eBPF verifier sees a verifier-tractable BPF program: no unbounded
   loop, no indirect dispatch over runtime-variable opcodes, just a long
   sequence of small handler bodies.
4. The kernel eBPF JIT executes that program. Despite being called an
   "simulator", the actual runtime path is straight-line per-handler native
   code with no dispatch overhead, equivalent in shape to a direct translation
   of the target instructions to eBPF.

"Simulator on the source side, JIT on the runtime side" is the same code path
when specialization is performed at compile time rather than runtime. The
simulator is the semantic specification; the verifier-visible artifact is its
specialization to one program.

### Why The Verifier Accepts It

A generic eBPF-written simulator for a Turing-complete ISA cannot pass the
verifier: it has unbounded dispatch loops and indirect jumps over arbitrary
opcodes. Specialization removes both:

- The instruction sequence is constant. The outer dispatch loop is unrolled.
  There is no runtime-variable opcode read after specialization.
- Direct jumps inside the target program become eBPF jumps to known offsets
  inside the unrolled handler chain. Indirect jumps inside the target program
  must be lowered to a verifier-acceptable dispatch (PC-keyed switch over the
  bounded set of possible targets, computed at compile time).
- Memory accesses inside per-instruction handlers go through ordinary BPF
  pointer types. The verifier checks them with its existing rules.

Each handler is small. Each handler is reached by a constant-propagated control
path. Together they look to the verifier like a long but straight-line eBPF
program.

### Safety Argument

Safety transfers from the eBPF verifier to executed behavior by a refinement
argument:

```text
target native program P
  -> compile-time specialization of trusted simulator I to P
  -> result is eBPF program B_{I,P}
  -> verifier accepts B_{I,P}
  -> kernel JIT executes B_{I,P} as native code
```

What runs in kernel is `B_{I,P}` lowered by the existing eBPF JIT. Not the
original target binary `P`. The native machine still executes only kernel-JIT
output. The user does not submit native code at all; the user submits the
specialized eBPF representation.

Out-of-bounds and other unsafe behavior in `P` cannot hide behind the
simulator abstraction. If `P` reads past a packet end, the corresponding
specialized eBPF load also reads past the packet end with the same effective
address, and the verifier rejects it as a packet pointer violation. The
simulator does not perform any masking, bounds insertion, or sandbox
adjustment: it is a faithful 1:1 lowering of native semantics into eBPF
operations on the same pointer types the kernel already checks.

A subtle point: this argument depends on memory accesses translating one to
one. Indirect control flow needs an explicit verifier-friendly form (PC
dispatch). Other instructions that the verifier cannot model directly (for
example wide vector ops, special-purpose CPU instructions) must either be
expressed using helper/kfunc calls or rejected by the specialization step.

### Trust Model

This idea moves the trust dependency to:

- the C source of the simulator `I`;
- clang's compilation of `I` to eBPF.

The simulator `I` is small, fixed per target ISA, and amenable to formal
verification. Possible sources for the simulator semantics:

- a hand-written reference simulator, formally verified once;
- a generated simulator from a machine-checked ISA specification (for
  example Sail, `github.com/rems-project/sail`);
- ARM publishes an official C reference simulator that could serve as a
  starting point for the arm64 variant.

Clang's compilation correctness is the same trust dependency the existing eBPF
ecosystem already accepts for every BPF program. It is not a new TCB component.

### Why It Is Not An Actual Simulator At Runtime

Naive reading: this is just a software simulator and will be slow.

Refined reading: this is a compile-time partial evaluator. The user's program
is the static input; the residual is straight-line eBPF that the existing
kernel JIT lowers to straight-line native code. The runtime cost is the same as
if a verified native-to-eBPF translator had emitted that eBPF directly. The
"simulator" is the semantic anchor for the specialization, not the runtime
shape.

### Helper, Kfunc, And Boundary ABI

Native programs make calls. The simulator cannot emit those as opaque
absolute-address calls because the eBPF verifier requires every call to go
through its helper or kfunc tables.

Compile-time lowering handles this:

- Each call site in the target native program is recognized at specialization
  time by matching the target address against the kernel's exported helper and
  kfunc tables. A `bpftool prog dump jited` of an existing eBPF program on the
  same kernel gives the absolute addresses for every helper used by similar
  programs; those addresses anchor the recognition.
- A recognized call lowers to a `BPF_CALL` eBPF instruction with `imm` set to
  the helper or kfunc id. The verifier checks it like any other helper call.
- An unrecognized call address causes specialization to fail loudly. Arbitrary
  indirect kernel calls are not permitted under this model.

Tail calls, exits, and program-typed return value conventions are similarly
lowered at specialization time, using the existing eBPF idioms for each.

### Register File And Stack

The target machine has more architectural registers than eBPF (16 GPRs on x86,
31 on arm64 vs. 10 BPF registers). The specialized simulator places the
target register file in a fixed region of the BPF stack:

```text
BPF stack layout:
  [ caller frame ]
  [ target reg file: r0..rN as i64 slots ]
  [ shadow flags  ]
  [ per-handler scratch ]
```

Each target instruction handler reads source registers from this slot region,
performs the operation as ordinary eBPF arithmetic with appropriate type
tracking (SCALAR vs. PTR_TO_xxx depending on what the verifier knows about that
slot at that PC), and writes destination registers back.

The verifier already tracks types per stack slot. The risk is state explosion
when many handlers see the same slot with different types under different
control paths. Mitigation: pin all general-purpose target registers to the
SCALAR type at handler boundaries, materializing pointer arithmetic only inside
handlers that actually perform pointer-typed operations. Stronger mitigation:
split the target program into smaller verifier-tractable regions and emit
boundary materializations between them.

### Control Flow Lowering

The hard cases:

- Direct conditional and unconditional jumps lower to eBPF jumps with constant
  targets inside the unrolled handler chain. Trivial.
- Indirect jumps require the set of possible targets to be enumerated at
  specialization time. The lowered form is a PC-keyed switch:

  ```c
  switch (target_pc) {
    case PC_A: goto handler_A;
    case PC_B: goto handler_B;
    ...
    default:   fail();
  }
  ```

  The switch table is constant, and the verifier accepts it as a bounded
  dispatch. Targets outside the enumerated set cause runtime fail.
- Computed call targets are not allowed unless they fall into the recognized
  helper/kfunc table.
- Return semantics use the target ABI's return-value register mapped to eBPF's
  `r0`.

If the target program contains genuinely arbitrary indirect control flow (jump
tables built from runtime data, return addresses popped from data memory),
specialization fails. This is the same restriction the verifier already applies
to ordinary eBPF programs and is consistent with the safety model.

### Implementation Surface

Approximate size budget:

| Component | LOC | Notes |
|---|---|---|
| Per-arch simulator (x86) | 1.5k–3k C | dispatch + per-insn handlers |
| Per-arch simulator (arm64) | 1k–2k C | smaller ISA, simpler |
| Specialization driver | 500–1k Rust/C | reads target binary, emits specialized simulator source or eBPF directly |
| Helper/kfunc recognition table | 200–500 LOC | absolute addr -> helper id map per kernel build |
| Kernel-side changes | ~0 | uses stock verifier + JIT |

There is no required new kernel syscall, no new verifier hook, and no new JIT
path. The result is a userspace tool plus a regenerated table of helper
addresses for the running kernel.

### Open Questions

These items decide whether the variant scales beyond a small PoC:

- Does clang reliably collapse the dispatch when the instruction array is
  static const, or are there cases where it leaves runtime dispatch in place?
- Does the verifier accept the resulting unrolled program within its complexity
  budget at realistic target program sizes (1k, 10k, 100k native instructions)?
- How is the SCALAR/PTR state of stack-slotted target registers managed without
  state explosion?
- For pointer-bearing target registers (packet pointer in `rdi`, ctx pointer in
  `rsi`, ...), how is the type information communicated from the prog-type
  context into the specialized handlers?
- ARM and RISC-V are expected to be friendlier than x86 because register
  pressure is lower and CISC-specific quirks are absent. Quantify.

A minimal PoC that answers the first two questions is the next concrete step:
implement a 5-to-10-instruction subset (`mov reg/imm`, `add reg/reg`, `cmp`,
conditional and unconditional `jcc`, `ret`), compile a hand-written specialized
simulator for a 50-instruction program, and verify that (a) clang produces a
dispatch-free eBPF program, (b) the kernel verifier accepts it, (c) the kernel
JIT lowers it to instruction-count-comparable native code.

### ReverseSim-In-eBPF Variant

The alternative inside idea #3 is to write a native-to-eBPF JIT in C, compile
that JIT itself to eBPF, run it offline against the target binary, and submit
the emitted eBPF to the kernel. The trust profile is the same as the
simulator variant — the JIT replaces the simulator as the trusted lowering,
and the stock eBPF verifier still checks the produced artifact.

When to prefer the JIT variant:

- target binaries are large enough that whole-program clang specialization is
  too slow to be in the loop;
- the lowering needs explicit pattern matching that clang's constant
  propagation will not discover (for example pattern-driven fusion of native
  multi-instruction idioms);
- the JIT can also be the host for ablations (turning off specific lowerings,
  emitting kinsns where available, etc.).

When to prefer the simulator variant:

- the lowering rules are simple and uniform per native instruction;
- semantic verification is anchored on the simulator rather than the emitter
  (simulators are easier to formalize against an ISA specification than
  emitters);
- the implementation effort is dominated by handler bodies, not by a separate
  emitter framework.

The two variants share the same Safety Model, Safety Transfer Argument, State
Model, and Boundary Rules below.

## Safety Model

The intended safety claim is:

```text
Any ReverseSim program accepted by the existing eBPF
verifier is safe under the same memory, pointer, helper, and control-flow
policy as ordinary eBPF, provided the lowering from target native code to eBPF
is a faithful 1:1 translation of native semantics into operations on the same
pointer types the verifier already checks.
```

The kernel does not accept arbitrary x86 or arm64 blobs under this model.
Native execution is safe only because each executable operation is the eBPF JIT
lowering of an eBPF instruction that the verifier accepted.

The user or compiler can produce the eBPF artifact, but the producer is not
trusted for safety. The trusted parts are:

- the existing eBPF verifier;
- the existing eBPF JIT;
- the simulator or JIT written in C (one per target ISA);
- clang's compilation of that C source to eBPF.

## Safety Transfer Argument

The strongest safety argument is a refinement argument:

```text
native program P
  -> lower(P) via simulator or JIT I = eBPF program B
  -> verifier accepts B
  -> trusted equivalence: B faithfully models the native semantics of P
  -> kernel JIT executes B; native machine runs JIT output
```

If the verifier proves `B` safe, and the trusted equivalence says every
observable behavior of `B` (memory accesses, helper calls, control flow) is
the same as the corresponding behavior of `P`, then executing `B` exhibits
exactly the safe subset of `P`'s behavior:

```text
safe(B) and B models P faithfully => safe(execute(B)) and execute(B) ~ P
```

The native code does not become safe because some separate ReverseSim was
verified. It becomes safe because the kernel JIT runs the eBPF program that
the verifier accepted, and that eBPF program is, by construction, a faithful
model of the user's intended native program.

There are several possible bindings:

- specialized simulator (this doc's main case): the simulator is the
  trusted lowering;
- explicit JIT in eBPF: the JIT is the trusted lowering;
- trusted verified translator: a translator with a machine-checked
  correctness proof is the trusted lowering;
- certificate checking: userspace submits `P`, `B`, and an equivalence
  certificate that the kernel checks before executing `B`.

What is not a security boundary:

```text
userspace submits safe B
userspace also submits arbitrary unsafe P
kernel verifies B but executes P directly without the trusted lowering
```

That construction is unsafe because the verified artifact and the executed
artifact are not connected by a trusted lowering.

Native memory operations are safe under this refinement relation. For example,
an executed instruction sequence whose source-level intent is:

```asm
mov rax, [rdi + 8]
```

is safe if the lowered eBPF performs the same load through a verifier-checked
BPF pointer with the same bounds, object, and fault behavior. It is not safe
if a user simply submitted that x86 directly to the kernel without the trusted
lowering producing an eBPF artifact for the verifier to check.

The important failure mode is an unfaithful lowering. For example, lowering an
x86 memory access into a sandboxed VM operation:

```text
guest_addr = rax
if guest_addr + 8 > guest_mem_size: unsupported
load guest_mem[guest_addr]
```

proves the safety of sandboxed x86 simulator semantics, not the safety of treating
`rax` as a real kernel address. ReverseSim's lowering is faithful
exactly when target-program semantics on packet, ctx, map_value, and stack
pointers map one-to-one to eBPF pointer-typed operations that the verifier
already checks. Unfaithful lowering breaks the safety transfer.

## State Model

The lowering represents target machine state using verifier-visible eBPF state.

Example for x86:

| Native State | Verifier-Visible State | Runtime State |
|---|---|---|
| `rax`, `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `rbx`, `r13`, `r14`, `r15` | mapped BPF registers or stack-slot registers | mapped physical registers after kernel JIT |
| extra registers such as `r10`, `r11`, `r12` | fixed stack slots in the target register file region | physical registers chosen by the kernel JIT |
| flags / condition state | explicit scalar shadow state | native flags when locally valid, or kernel-JIT-managed |
| program memory accesses | verifier-checked BPF pointer operations | equivalent native loads/stores after kernel JIT |

Target register slots are verifier-visible state. The kernel JIT may keep the
corresponding value in a physical register, as long as all observable
operations on that state are represented by eBPF instructions in the
specialized artifact.

## Boundary Rules

The hard part is not arithmetic instructions. The hard part is observation
boundaries.

These operations need explicit lowering rules:

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
Any operation that can observe verifier-visible state or expose hidden runtime
state must be represented by an eBPF instruction in the specialized artifact,
or pass through a boundary adapter that materializes the verifier state
expected by ordinary eBPF.
```

For example, a register held only in a physical register by the kernel JIT may
back a target register slot inside a closed specialized region. But before an
ordinary helper is allowed to read a pointer to that target register slot's
backing memory, the lowering must materialize the value to real stack memory
or reject that program shape.

## Alternative Path: Kernel-ABI Dual-Semantics ISA

An earlier framing of idea #3 placed the dual semantics inside the kernel: each
ReverseSim instruction had both a verifier-visible `instantiate_insn()`
lowering and a per-architecture native emitter, both owned by the kernel ABI.
This framing has been demoted to an alternative path because it overlaps
significantly with idea #2 (Kinsn, whole-program generalization).

Recorded here for completeness:

```c
struct reversesim_insn {
        int (*instantiate_insn)(payload, struct bpf_insn *buf);
        int (*emit_x86)(payload, ...);
        int (*emit_arm64)(payload, ...);
};
```

`instantiate_insn()` is the verifier source of truth. Native emitters are the
execution refinements. The verifier path lowers ReverseSim instructions to
ordinary BPF semantics and checks the resulting program. The JIT path emits the
native semantics instead.

For this to become a full-program substrate rather than a peephole mechanism,
the kernel interface would need:

- branch-aware proof lowering, not only local proof sequences;
- a way to encode or relocate program-level branch targets across kinsn
  expansions;
- region-level hidden-state layout;
- explicit boundary adapters for calls, tail calls, exits, and helper-visible
  stack state;
- per-architecture register allocation and save/restore rules for hidden native
  registers.

This is essentially kinsn (idea #2) generalized from peepholes to whole-program
substrate. If the project later finds value in pursuing it, it belongs in the
kinsn paper line, not in this one. The simulator and JIT variants above keep
the kernel surface near zero and remain the core of idea #3.

## Related Work Positioning

The closest ancestor is proof-carrying code for safe kernel extensions:

- George C. Necula and Peter Lee, "Safe Kernel Extensions Without Run-Time
  Checking", OSDI 1996.

PCC checks a user-provided proof for native code. ReverseSim
instead uses the existing eBPF verifier over the lowered eBPF program and does
not require the user to provide a proof.

Translation validation is related: it can validate that the per-program
specialization preserves source semantics, or that a hand-written JIT
faithfully implements the target ISA.

Native Client, RockSalt, and native machine-code validators safely execute
native code by validating or restricting native machine code directly.
ReverseSim avoids arbitrary native validation by never running
user-supplied native bytes; only the stock kernel JIT output runs.

Verified eBPF JIT work (Jitterbug, Serval, K2) proves that an eBPF JIT
preserves eBPF semantics. ReverseSim is dual: it proves that a
native-to-eBPF lowering preserves native semantics, and reuses the existing
(possibly verified) eBPF JIT downstream.

Reusable trusted ISA specifications include Sail's machine-checked semantics
for arm64 and RISC-V, and ARM's official C reference simulator. These are
candidate sources for the trusted simulator `I`.

## Paper Framing

The systems claim:

```text
ReverseSim brings native code into the kernel under the
eBPF safety model without modifying the kernel, by writing the trusted
native-to-eBPF lowering in eBPF itself.
```

Possible title:

```text
ReverseSim: Bringing Native Code into the eBPF Safety Model
  (without changing the kernel)
```

For a strong systems paper, the evaluation needs to show:

- broad target-ISA coverage, not only a few instructions;
- real programs (existing eBPF apps re-expressed via the lowering, plus native
  routines that have no obvious eBPF expression);
- performance close to native x86/arm64 and comparable to or better than the
  existing eBPF JIT for the same source semantics;
- complexity of the trusted lowering (simulator or JIT in eBPF) and its
  amenability to formal verification;
- a clear accounting of the added trusted code base relative to PCC and to
  kinsn;
- failure cases where the verifier rejects unfaithfully lowered programs
  naturally.

## Main Risks

The idea is viable, but the risks are sharp:

- If clang does not reliably collapse the specialized dispatch, the
  verifier-visible artifact is a generic simulator and will not pass the
  verifier. This is the single biggest open question.
- If the verifier's complexity budget is exceeded by the unrolled artifact at
  realistic target program sizes, the practical coverage shrinks sharply.
- If indirect control flow inside the target program cannot be reduced to a
  bounded PC-keyed switch, the program is rejected; the fraction of real
  programs this excludes is unknown.
- If pointer-typed target registers cause SCALAR/PTR state explosion across
  many handlers, verifier acceptance becomes unstable.
- If the helper/kfunc recognition table goes out of sync with the running
  kernel, specialization mis-lowers calls; the recognition step must be
  regenerated against the running kernel and not cached across kernel
  versions.
- If the trusted simulator or JIT is large and ad hoc, the TCB story becomes
  difficult; formal verification against a machine-checked ISA specification
  is the mitigation.
- If only a small subset of the target ISA is covered, the result looks like
  another peephole mechanism rather than a path to running native programs.

The strongest version is therefore conservative:

```text
ReverseSim does not execute user-supplied native code. It
executes the stock eBPF JIT lowering of an eBPF program produced by a trusted
in-eBPF simulator or JIT, which makes a one-to-one faithful translation of
the target native program. The existing eBPF verifier is the safety checker.
```

That is the key difference from both traditional proof-carrying code and the
kernel-ABI variant (which overlaps with kinsn).

## 附录 A:原始讨论记录(2026-05-17)

以下是讨论该 specialized eBPF simulator variant 的原始对话记录,原文保留,
未做归纳或措辞调整。出于隐私考虑不标注具体发言者,按时间顺序呈现。

> 这里核心的问题是"simulator 对目标程序的解释执行"通过验证器的检查,并不能
> 说明目标程序真的安全,比如目标 native 程序里的一个 oob,可能不会导致
> simulator 的 oob,除非这个目标程序自己是 sanitized 的(插了安全检查)。

> 这个感觉很酷哈哈,但是可能不好实现

> 工程来说 这个 simulator 可能需要用到很多 bpf 的 hack,不过应该是 feasible

> 对,我们不仅仅要让 simulator 通过验证器的检查,实际上还要形式化验证这个
> simulator/JIT 是完全等价于 x86 指令的

> 目前看来....我今天试了试,确实不太好做

> 甚至可能 JIT 反而更好做一点

> 假如不能信任 clang 的编译(应该是不能?),那么我们要形式化验证 simulator/JIT
> 大概率要手写指令集转换的?

> 那写一个 x86 的 JIT,把 x86 指令 emit 成一段 bpf 指令序列反而还更方便一点...

> 也不容易因为状态爆炸导致过不去验证器

> 目前的 kinsn 基本上能表达大多数,但是跳转指令不好搞

> 因为跳转指令需要被 verifier 和 jit relocation

> register 可以,目前来说我们可以把栈的一部分当作 register

> 如果放宽一点,信任 clang 的编译的话会方便不少(我不确定这样可以被接受嘛,
> 你觉得呢 @sunhao

> 信任 clang 的话我基本上写出来 simulator 了

> 另外我在想干脆 rejit 不改 kernel 了

> map inline 还有一套确实有效果

> 至少 katran 比如说能 100ns -> 50ns

> 效果还是挺明显的

> 之前的问题在于 bpf runcnt 测量方法开销太大了,每次运行平均 30-50ns 开销,
> 导致不能用

> 这里是指信任 clang 编译的 simulator (in bpf bytecode)?我有点 confused

> 是的,信任 clang 编译的 ebpf simulator 的编译过程正确

> 这样我们形式化验证 c 写的 ebpf simulator 正确就好了?

> 然后我们再把 c 写的 ebpf simulator 加上对应的 x86 指令给 ebpf verifier,
> 等于我们让 ebpf verifier 去 verify "正确的 simulator 执行这几条 x86 指令的
> 过程"

> X86 simulator 到 ebpf bytecode 编译的等价性可以假设

> 只要 ebpf verifier 确认"正确的 simulator 执行这几条 x86 指令的过程"是
> 安全的那就安全了

> 那就简单啦 x

> 对 核心的问题就是我刚刚提到的那个

> 这里

> 如果目标程序不插检查它就通不过 ebpf verifier 了,因为这样的话会导致 simulator
> 解释的过程中出现越界访问?

> 说起来你会去 sosp 和 linux plumber 吗

> 我可能会去 sosp

> Plumber 不一定,不过下周末到西雅图

> 这两个在一起

> 一个城市,隔一两天好像

> 不过今天讨论的这个如果是 simulator 其实变成又和 kinsn 不一样的 idea 了(?

> 确实在一个地儿 我都没注意到

> X86 Simulator 视角没有 oob,所以我说目标程序的 oob 可能不会体现为
> simulator 的 oob

> verifier 不能只 verify simulator(图灵完备的不停机 simulator 也过不了
> 编译器),verify 的一定是"正确的 simulator 执行这几条 x86 指令的过程"

> 所以目标程序的 oob 一定会在执行的过程中体现为 simulator 的 oob

> 就是这个 simulator 在执行的时候的某一个步骤会去越界访问 packet 之类的,
> 因为它的执行会是和 native insn 完全一致的

> simulator 本身感知不到 oob 也不会去检查,它就是个单纯的翻译器

> 感觉是不一样的目标不一样的实现流程 x

> 解决的问题也会不一样,一个的出发点是怎么把 ebpf 变得更快,现在说的出发点变成,
> 如何直接跑 native insn 还能保证安全

> 其实经过 clang 的常量传播,实际上验证器验证的就等于 kinsn 展开的 bpf insn
> proof format

> 经过常量传播就等于把 x86 jit 成 ebpf 然后验证 ebpf

> 但是还是执行 x86

> 经常编译需要个几分钟

> I see,合理

> 加了 simulator 这一层以后,不知道会增加多少验证难度

> 不过感觉这个 idea 挺疯狂的哈哈,不错

> kinsn 实现太复杂了...主要是最后涉及 register 和 jmp,还得全局 relocate

> 也就是,如果我们想要做类似的事情,验证 kinsn 会更难(因为等于直接验证 jit
> compiler,不如直接验证 simulator)

> x86 simulator 也很复杂

> 确实 dan 提出来一个问题,我们怎么选择了 kinsn 的?是不是看看 native code
> 产物?然后我根据 native code 逐步加 kinsn,直到加了七八十个,然后我发现既然
> 大多数 insn 都有了那为啥不能直接跑 native code 得了

> simulator 可以想象成 native 指令对应的 eBPF 指令序列的 map

> 一个具体的程序可以想象成一系列 index

> Verifier 通过 lookup 找到 native 程序对应的语义,然后进行验证

> 但是 kinsn 跑 native code 我发现 jmp 很难解决,register 分配也很麻烦。。。

> 是这样的,目前就是这样做的

> 我实现了一个 poc 了

> 这个没法从零做,需要在 LLVM 加深度支持,从零 agent 一定会犯很多错

> '看看 Claude 写的 C compiler 有多少 bug 就能想象'

> 是的....今天折腾了一天发现 kinsn 完全覆盖 x86 走不通,太难了

> 而且还是改 kernel module

> Simulator 应该可以基于现有的改

> 我感觉让 agent 自己写可能也就几百行?而且可能更容易 hack 一下通过 ebpf
> verifier

> 另外 abi 要对齐

> 然后也可以用已有的 eBPF self tests 当作 oracle

> 让 agent 一直改

> 嗯

> 主要指令太多了

> 确实

> arm 可能好点

> 从零写 语义不一定对

> arm / riscv 估计也能不少加速,和 x86 不一样,估计加速主要在 reg 分配上面

> 最好基于 reference simulator,适配到能编到 eBPF

> ARM 应该有官方的 C simulator

> 有什么别人已经形式化验证过了的吗

> https://github.com/rems-project/sail

> 直接从 formal semantics 生成 simulator

> 不过可能太复杂了,作为 poc 也可以假设已有的是对的

> 感觉这样等于有三个 idea 各自解决一个不那么一样的问题了(

> 实现也不一样

> 虽然实验可能差不多

> 都可以拿 ebpf app 跑跑测试性能

> 今天讨论这个虽然可以说解决的不是 ebpf 的问题,但是实际上如果依赖 ebpf
> verifier 实现的话还是要遵守 ebpf 的 abi,验证也只会更严格

> abi(kfunc/helper/pseudo call) 确实是个问题,在 simulator 层面对应改 pc,
> 但在 eBPF 需要触发 verifier 对应的 call check

> 需要做对应的 abi 转换

> 让 kernel compile ebpf 之后 dump 出来 jitted code,我们就获得了所有 call
> 的地址

> 然后我们在用这些绝对地址 link 一下就好了

> 也几乎不用改内核

## 附录 B:三条思路在 project 内的定位

```text
1. Speculative optimization of eBPF
   定位: pure userspace tool for runtime optimization opportunities in eBPF
   关键技术: live discovery / atomic-or-near-atomic prog swap /
            map_inline + const_prop + dce 等纯 BPF-to-BPF rewrite
   内核改动: 接近零(取决于具体 attach 类型的 swap 能力)
   形式化对象: 每个 pass 的 BPF-to-BPF 重写正确性
   解决的问题: 已加载的 eBPF 程序在运行时上下文变化(map 内容、profile)后
              错失的优化机会

2. Kinsn
   定位: new OS abstraction for eBPF optimization,
        brings eBPF closer to hardware
   关键技术: 双语义 kernel-defined 指令(instantiate_insn + native emit) +
            可能的 LLVM backend / userspace optimizer 支持
   内核改动: 中等(verifier + JIT + 每条 kinsn 的 proof + relocation)
   形式化对象: 每条 kinsn 的 verifier 语义和 native emit 的等价性
   解决的问题: 让 eBPF 能表达更接近硬件的操作而不放弃 verifier 保证

3. ReverseSim (本 doc)
   定位: x86/arm simulator or JIT written in eBPF,
        enabling safely running native code in the kernel
        without additional proof from the user
   关键技术: 特化的 eBPF simulator(主线) 或 native-to-eBPF JIT in eBPF
   内核改动: 接近零
   形式化对象: 单个 C simulator / JIT 的正确性
   解决的问题: 直接在内核里运行 native 代码并保证安全;
              不再要求开发者写 eBPF

实验设置: 三条都使用同一套 ebpf app benchmark / micro 套件 / 测量基础设施
```

这三条不是 incremental 三个版本,而是三个独立的设计点,各自针对的"待解决问题"
不重合。Project 共享 corpus、measurement infra、kernel build,论文层面拆开。

# llvmbpf as a Kernel BPF Optimization Framework

## Executive Summary

The characterization results in `docs/paper.md` point to a specific conclusion: the current kernel-vs-llvmbpf gap is mostly a **backend lowering gap**, not a generic "BPF program quality" gap.

- llvmbpf/kernel exec-time geomean is `0.849x`, code-size ratio is `0.496x`.
- The measured gap is dominated by:
  - byte-load recomposition: `50.7%` of instruction surplus, `2.24x` isolated penalty
  - missing conditional-move lowering: `19.9%` of instruction surplus
  - fixed callee-saved overhead: `18.5%` of instruction surplus, already fixed in newer kernels
- Only `InstCombine` and `SimplifyCFG` materially affected BPF programs in the current pass-ablation study.

This has direct implications for the five approaches:

1. **Approach 2 (kernel hint system) is the strongest systems-paper direction.**
   It directly targets backend-only losses while preserving verifier semantics and keeping LLVM out of the kernel. It does require kernel/UAPI changes, but those changes are focused and defensible.
2. **Approach 4 is the strongest no-kernel-change direction, but it is weaker technically and narratively.**
   It can be implemented as a userspace pre-optimizer, but it will not recover most of the measured gap because the largest losses are not expressible purely at BPF bytecode level.
3. **Approach 1 is the research umbrella for Approach 4, but not yet a clean implementation path in current `llvmbpf`.**
4. **Approach 5 is useful only as a secondary extension once a real hint transport exists.**
5. **Approach 3 is too speculative for the current paper.**

If the goal is to turn the paper from "characterization only" into a strong OSDI/SOSP-style systems paper, the best path is:

- primary contribution: **userspace llvmbpf-generated JIT hints for the kernel**
- concrete prototype: **x86 + arm64 consumers**, with at least two hint classes
- safety story: **original bytecode still verified; hints are advisory and locally checked**
- fallback story: **invalid or unsupported hints are ignored**

## Ground Truth From This Repo

### What `llvmbpf` actually does today

`vendor/llvmbpf` already provides a useful optimization framework, but not in the form required by Approach 1/4 yet.

- The lift entry is `llvm_bpf_jit_context::generateModule()` in `vendor/llvmbpf/src/compiler.cpp:88`.
- It reads `vm.instructions`, splits the BPF CFG into LLVM basic blocks, allocates storage for BPF registers, allocates an emulated stack, and emits LLVM IR for each BPF instruction.
- It lowers helper calls into ordinary external LLVM calls and lowers local BPF calls into a manual call stack plus `indirectbr` return dispatch.
- AOT compilation in `vendor/llvmbpf/src/llvm_jit_context.cpp:413` emits a **host native object** using the host target triple, not BPF bytecode.
- The CLI `-emit-llvm` path prints IR before optimization, then still emits a native object.

Concretely:

- `vendor/llvmbpf/src/compiler.cpp:203-220` allocates `r0..r10` and a large emulated stack.
- `vendor/llvmbpf/src/compiler.cpp:260-352` uses `BlockAddress` and `indirectbr` for local BPF calls.
- `vendor/llvmbpf/src/compiler.cpp:783-1015` special-cases `LDDW`, including materializing host pointers or calling helper shims.
- `vendor/llvmbpf/src/llvm_jit_context.cpp:421-485` targets the host machine and emits a native object file.

This matters because the current LLVM IR is shaped for **native execution of an emulated BPF machine state**, not for re-emitting verifier-friendly BPF.

### Why current `llvmbpf` cannot round-trip back to BPF "for free"

Approach 1/4 sounds like "just retarget LLVM to the BPF backend." In the current codebase that is not enough.

Three concrete blockers:

1. **The lifted IR is not canonical BPF IR.**
   It models BPF registers as allocas, keeps a synthetic stack, and represents local calls with `indirectbr`. That is fine for native codegen; it is a poor starting point for clean BPF re-emission.
2. **Some BPF-specific semantics have already been erased or replaced.**
   Helper calls become external calls, and some `LDDW` forms become host addresses or helper wrappers.
3. **There is no BPF output path at all.**
   The repo supports host native JIT/AOT, PTX, and SPIR-V, but not `LLVM IR -> optimized BPF bytecode` or `LLVM IR -> .bpf.o`.

So Approach 4 is not a small patch. It needs either:

- a new verifier-aware lift that preserves BPF-level structure much more faithfully, or
- a new translation/repair stage that reconstructs valid BPF from the current lowered IR.

### What BPF metadata channels exist today

The existing `BPF_PROG_LOAD` metadata fields are:

- `prog_btf_fd`
- `func_info`
- `line_info`
- `attach_btf_*`
- `fd_array`

See `vendor/linux/include/uapi/linux/bpf.h:1603-1639`.

The problem is that `func_info` and `line_info` are structurally narrow:

- `struct bpf_func_info` is only `{ insn_off, type_id }`
- `struct bpf_line_info` is only `{ insn_off, file_name_off, line_off, line_col }`

See `vendor/linux/include/uapi/linux/bpf.h:7451-7464`.

The verifier does allow larger record sizes in principle, but only if the extra tail bytes are zero:

- `vendor/linux/kernel/bpf/verifier.c:19117-19131`
- `vendor/linux/kernel/bpf/verifier.c:19312-19323`

That means **existing kernels do not provide a usable nonzero side channel for custom hints via `func_info`/`line_info`**.

`BTF` declaration tags are more flexible, and the kernel already looks up named tags with prefixes such as `exception_callback:`:

- tag lookup helper: `vendor/linux/kernel/bpf/btf.c:3509-3552`
- one verifier use: `vendor/linux/kernel/bpf/verifier.c:3117-3151`

But decl tags are attached to **types/functions/arguments**, not to arbitrary instructions, basic blocks, or liveness ranges. They are too coarse for a clean long-term hint ABI.

That said, they are still the **least invasive prototype path**:

- they already ride through `prog_btf_fd`
- their payload is an arbitrary string
- the kernel already has the plumbing to search for prefixed tags

So for a first prototype, a function-level tag such as `hint:<serialized payload>` on the main BPF function is plausible. It is awkward for large or per-instruction hints, but it avoids immediate UAPI growth.

### Immediate consequence

For transport design, the repo/kernel state suggests a two-stage answer:

- **prototype path without new UAPI**: program BTF decl-tags, with `fd_array` as a fallback side-band object carrier
- **clean long-term path**: a dedicated hint blob or new BTF-ext-like subsection

In other words, any real long-term hint system needs at least one of:

- a new `BPF_PROG_LOAD` field such as `hint_fd` or `hint_blob`
- a new `.BTF.ext` subsection with dedicated kernel parsing
- a dedicated sidecar object referenced through `fd_array`

This is a kernel/UAPI extension, not something libbpf/llvmbpf can fake entirely in userspace.

## Evaluation Criteria

For each approach I evaluate:

1. technical feasibility in the current repo/kernel model
2. verifier compatibility
3. cross-architecture applicability
4. relation to K2, Merlin, EPSO, and KFuse
5. implementation complexity
6. likely performance impact relative to the current characterization
7. paper strength

## Approach 1: Userspace BPF Bytecode Optimization

### Core idea

Lift BPF bytecode to LLVM IR, optimize it, lower back to optimized BPF bytecode, then let the kernel verifier and kernel JIT handle the rest.

### Technical feasibility

**Feasible in principle, not directly supported by current `llvmbpf`.**

What exists:

- BPF bytecode -> LLVM IR lift exists.
- LLVM optimization pipeline exists.

What does not exist:

- LLVM IR -> BPF output path in this repo
- a BPF-faithful IR form suitable for round-tripping
- ELF/relocation regeneration for `.bpf.o`

Practical reading: this is a new compiler project built on top of `llvmbpf`, not a small extension.

### Verifier compatibility

**This is the main risk.**

An optimized BPF program can still fail the verifier even if the original passed, because the verifier reasons about more than functional equivalence:

- pointer provenance and pointer types
- stack-slot initialization
- helper argument types
- loop structure and boundedness
- subprogram boundaries
- packet/map/context access forms that the verifier can prove safe

The current lift erases too much verifier-relevant structure to guarantee that arbitrary LLVM transformations remain verifier-friendly.

The realistic safe subset is much smaller:

- scalar SSA simplification
- constant folding
- dead code elimination on scalar-only regions
- local CFG simplification that does not perturb verifier-visible memory/pointer structure

Anything involving memory access widening, stack layout changes, helper-call motion, pointer arithmetic rewrites, or loop reshaping is high-risk.

### Cross-architecture applicability

**Strong in principle.**

If the output is valid BPF bytecode, every architecture-specific kernel JIT can benefit.

But this is also the limitation: the optimization can only exploit what the BPF ISA can express. It cannot directly ask x86 for `cmov` or arm64 for `csel`.

### Comparison with prior work

This is directly in the same space as:

- **K2**: program-synthesis-based BPF bytecode optimization
- **Merlin**: multi-tier optimization over LLVM IR plus BPF bytecode
- **EPSO**: BPF bytecode rewriting/superoptimization

The biggest advantage of the llvmbpf angle is:

- reuse of the LLVM mid-end instead of hundreds of custom rewrite rules
- ability to start from **arbitrary BPF ELF** even without the original source IR

The biggest disadvantage is:

- current llvmbpf is not verifier-aware enough for safe round-tripping
- Merlin already occupies much of the "LLVM helps BPF optimization" story

### Implementation complexity

**High.**

Minimum real deliverable:

1. add an optimized-IR export path
2. add a BPF backend emission path
3. preserve enough BPF semantics through lifting
4. rebuild `.bpf.o` with relocations/BTF
5. add a verifier-oracle fallback path

### Expected performance improvement

**Probably modest relative to the current 15% kernel gap.**

This is the critical point.

Your characterization says the dominant losses are:

- byte-load recomposition in the kernel JIT backend
- missing `cmov`/select lowering in the kernel JIT backend

A bytecode optimizer does not automatically fix either.

It may still help:

- simplify CFG before JIT
- remove redundant scalar ALU ops
- reduce instruction count in verifier-visible code

But the likely steady-state gain is closer to **single-digit runtime improvement** than to the full llvmbpf-vs-kernel gap. It is more likely to resemble Merlin/EPSO-style bytecode-level gains than backend replacement gains.

### What is different or better

Best differentiator:

- "LLVM-based optimizer for arbitrary deployed BPF ELF, not just source-controlled C-to-BPF builds"

But to make this paper-strong, you would need to show:

- materially lower engineering effort than rule-heavy systems
- competitive or better gains than Merlin/EPSO
- broad verifier acceptance
- cross-arch wins on x86/arm64/riscv

### Bottom line

**Interesting, but not the best primary paper direction.**

It is implementable only with a substantial new compiler effort, and it does not align well with the specific backend losses your current paper already identified.

## Approach 2: Kernel Hint System

### Core idea

Keep the original BPF bytecode unchanged. Use llvmbpf in userspace to analyze or optimize the program, then emit **advisory JIT hints** that the kernel JIT can consume.

Examples:

- load-widening opportunities
- select/phi regions that should become `cmov` or `csel`
- basic-block order / fallthrough preferences
- register liveness or save-mask hints

### Technical feasibility

**Medium, and this is the most promising direction.**

What already exists:

- userspace llvmbpf can lift to LLVM IR and run optimization/analysis
- kernel has metadata plumbing for BTF and program load
- kernel JITs already do multi-pass emission and have places where such hints could be consumed

What needs to be built:

- a hint schema
- a transport mechanism
- a verifier/JIT-side validator for hints
- per-arch consumers

The transport is the biggest structural change. Existing `func_info`/`line_info` are too rigid. For transport there are really two viable options:

- **least invasive prototype**: encode coarse hints or a compact serialized blob in program BTF decl-tags on the main function
- **clean interface**: add a dedicated `hint_fd` or `hint_blob`, or add a new BTF-ext-like hint subsection

`fd_array` is the next-best stopgap because it already lets program load carry extra bound objects. It is workable, just less principled than a dedicated hint carrier.

So the cleanest long-term design is probably:

- a new `hint_fd` or `hint_blob` in `BPF_PROG_LOAD`, or
- a new BTF-ext-like subsection keyed by `insn_off`

### Verifier compatibility

**Excellent.**

This is the biggest advantage of Approach 2.

- The actual BPF bytecode remains unchanged.
- The verifier still verifies the same program.
- Hints are advisory. If a hint is missing, malformed, inconsistent, or unsupported, the kernel ignores it.

That gives a very clean safety story:

- verifier safety is preserved
- JIT correctness remains in-kernel
- userspace never injects executable native code into the kernel

### Cross-architecture applicability

**Strong if the hint semantics are generic.**

A good hint schema is not "emit x86 `cmov`." It is something like:

- this branch diamond is a side-effect-free select region
- this set of byte loads can be widened to a 32-bit or 64-bit load
- this basic-block order is preferred
- these callee-saved BPF registers are dead

Then each backend maps that to:

- x86: `cmov`, `mov`, block reordering
- arm64: `csel`, `ldr`, block reordering
- riscv: conditional-move equivalent if available, or fallback branch lowering

The analysis is shared; only the final exploitation is per-arch.

### Comparison with prior work

This is **not** direct competition with K2/Merlin/EPSO.

- K2/Merlin/EPSO optimize the verifier-visible program before JIT.
- Approach 2 optimizes the **backend decision layer** after the program form is already fixed.
- KFuse fuses multiple already-verified programs inside the kernel; it is orthogonal.

This is a much cleaner novelty claim:

> existing work optimizes BPF bytecode; we optimize how existing kernel JITs lower already-verified BPF, without embedding LLVM in the kernel.

### Implementation complexity

**Medium-high, but much better aligned with the current evidence.**

A reasonable staged implementation:

1. userspace analyzer emits only two hint classes:
   - `wide_load_ok`
   - `select_region`
2. x86 JIT consumes both
3. arm64 JIT consumes at least `wide_load_ok`, optionally `select_region`
4. all hints remain optional and validated locally

That is a tractable systems contribution.

### Expected performance improvement

**Highest among the five approaches.**

Why:

- it can directly target the measured root causes
- it does not depend on verifier-friendly re-expression of those optimizations in BPF bytecode

Conservative expectation from current data:

- suite-level improvement: likely **high single digits to low teens**
- biggest wins: memory-local and control-flow-heavy benchmarks
- smaller gains: dependency-chain benchmarks where code size is not the bottleneck

I would not claim "full closure of the llvmbpf gap." The current data explicitly show that code size and runtime are not tightly correlated. But this is the only approach that can plausibly recover a large fraction of the measured backend gap.

### What is different or better

This is the strongest differentiator available:

- uses userspace LLVM as an **advisor**, not as an in-kernel execution engine
- attacks a layer that prior work mostly does not address
- preserves kernel safety and verification structure
- can be applied across architectures through a shared hint schema

### Bottom line

**Best overall direction.**

This is the one most likely to turn the paper into a systems paper instead of a compiler-characterization paper.

## Approach 3: Hybrid Execution

### Core idea

For hot BPF programs, offload execution from the kernel JIT to llvmbpf-generated native code in userspace.

### Technical feasibility

**Very low for the current scope.**

You would need:

- hotness detection
- transparent handoff from kernel execution to userspace execution
- exact helper/map/context emulation
- synchronization and failure recovery
- security validation for userspace-generated native code

This is much larger than the rest of the paper and effectively becomes a new execution architecture.

### Verifier compatibility

**Weak.**

The verifier proves safety of BPF abstract-machine execution, not arbitrary userspace native code.

So you need one of:

- proof-carrying translation
- in-kernel validation of emitted native code
- a sandbox that mediates all memory accesses and helper calls

At that point the design is no longer a lightweight extension of the current system.

### Cross-architecture applicability

Nominally yes, but only after massive engineering work.

In practice every program type would need its own context and helper model:

- XDP and TC are especially hard because the fast path is latency-sensitive
- tracing and iterator programs are easier semantically but still nontrivial

### Comparison with prior work

This no longer competes primarily with K2/Merlin/EPSO. It becomes closer to:

- userspace BPF runtimes
- offload systems
- split-execution systems

That is a different paper.

### Implementation complexity

**Very high.**

### Expected performance improvement

**Poor for the current workloads.**

Even if llvmbpf native code is 15% faster than the kernel JIT, the overhead of kernel-userspace delegation will dominate many BPF hot paths.

This is especially true for:

- XDP
- TC
- kprobe/tracepoint-style short handlers

It could help only for very compute-heavy or batched workloads, which is not the center of your current characterization.

### What is different or better

Only if the paper becomes about safe offload/execution migration. That is not what the current evidence supports.

### Bottom line

**Do not lead with this.**

It is too speculative and too far from the current paper's demonstrated mechanisms.

## Approach 4: LLVM-Optimized BPF Bytecode + Kernel JIT

### Core idea

This is the concrete tool version of Approach 1:

1. take a BPF ELF
2. lift to LLVM IR
3. optimize
4. lower back to BPF
5. feed optimized BPF to the kernel verifier and JIT

### Technical feasibility

**Low-medium as a deliverable, high as an engineering effort.**

This is the most implementable no-kernel-change path, but only if scoped carefully.

A realistic first version is not "full llvmbpf round-trip." It is:

- scalar/CFG-only rewrites
- verifier-oracle fallback
- raw instruction output first
- ELF regeneration later

That is much more plausible than trying to round-trip all of `llvmbpf`'s current IR.

### Verifier compatibility

Same concerns as Approach 1.

The right deployment model is:

1. attempt optimization
2. load the rewritten program under the same attach context
3. if verifier rejects, fall back to the original program

That gives operational safety, though not proof-by-construction.

### Cross-architecture applicability

**Very good.**

This is the core strength of the approach. Once the optimized bytecode is valid, every existing kernel JIT benefits.

### Comparison with prior work

Still directly comparable to K2/Merlin/EPSO.

The most credible differentiation is:

- no dependence on original source LLVM IR
- works on arbitrary BPF ELF inputs
- leverages standard LLVM passes instead of a large custom rewrite inventory

But you must be explicit that the optimization space is likely narrower than general LLVM suggests, because verifier legality dominates.

### Implementation complexity

**High.**

### Expected performance improvement

**Moderate at best.**

I would expect:

- some code-size reduction
- some verifier-time increase unless paired with a good legality filter
- limited steady-state runtime improvement compared with Approach 2

This approach can help some control-flow and scalar patterns, but it does not naturally fix the main backend-only losses you already measured.

### What is different or better

The paper story is clean if you need a strict no-kernel-change contribution:

> a userspace LLVM-based pre-optimizer for existing BPF ELF objects that preserves kernel verification and benefits all architectures.

But that is still a more crowded novelty space than Approach 2.

### Bottom line

**Best fallback if kernel modification is politically impossible, but not the strongest overall paper.**

## Approach 5: Optimized BPF Bytecode with Verifier Annotations

### Core idea

Pair Approach 4 with extra metadata that helps the verifier or loader reason about the optimized program.

### Technical feasibility

**Low today unless you add a new metadata channel.**

The existing channels do not cleanly support this:

- `func_info` and `line_info` cannot carry nonzero custom payloads on current kernels
- decl tags are too coarse
- `fd_array` can carry extra objects, but the kernel has no defined semantics for "optimization hints" there

So this is really "Approach 4 plus a new kernel/UAPI extension."

### Verifier compatibility

Potentially very good, because the verifier could:

- consume summarized facts
- reject inconsistent metadata
- ignore metadata when unsupported

But that requires new kernel logic.

### Cross-architecture applicability

Strong, because verifier-side acceleration is architecture-neutral.

### Comparison with prior work

This is more orthogonal to K2/Merlin/EPSO than Approach 4 alone, but it is also a weaker primary claim because it focuses on load-time cost, not steady-state execution.

### Implementation complexity

**Medium as a kernel feature, weak as a standalone paper hook.**

### Expected performance improvement

Steady-state execution: **none directly**.

Potential benefits:

- lower verification time
- lower optimization rejection cost if paired with Approach 4
- better reload performance for systems such as Cilium

This is useful, but it should be a **secondary result**, not the paper's main contribution.

### What is different or better

Useful as part of a broader framework, especially if you want to show that optimization does not make load latency unacceptable.

### Bottom line

**Good companion feature, weak lead feature.**

## Side-by-Side Ranking

| Approach | Feasible now | Verifier risk | Cross-arch story | Likely runtime gain | Novelty strength | Overall |
|---|---|---:|---:|---:|---:|---:|
| 1. userspace bytecode optimization | Medium-low | High | High | Medium-low | Medium | 3/5 |
| 2. kernel hint system | Medium | Low | High | High | High | **5/5** |
| 3. hybrid execution | Low | Very high | Medium | Low/negative | Diffuse | 1/5 |
| 4. LLVM-optimized BPF + kernel JIT | Medium-low | High | High | Medium | Medium | 4/5 if no kernel changes are allowed |
| 5. bytecode + verifier annotations | Low alone | Low | High | Low for runtime | Medium-low | 2/5 alone, 4/5 as secondary support |

## Comparison With Existing Work

## K2

K2 is a bytecode-level optimizer based on program synthesis. It sits before JIT compilation and is verifier-constrained. It is closest to Approaches 1 and 4.

Implication:

- If you pursue Approach 1/4, you are in direct competition with K2.
- Your differentiator must be "LLVM-based and works on arbitrary BPF ELF," not "we optimize BPF before JIT," because K2 already does that.

## Merlin

Merlin is the strongest competing reference for Approach 1/4 because it already spans multiple optimization layers, including LLVM IR and BPF bytecode.

Implication:

- A plain "LLVM can optimize BPF" story is not new enough.
- Your advantage must be either:
  - arbitrary deployed BPF ELF without source IR, or
  - a backend-focused architecture-aware integration story, which pushes you back toward Approach 2

## EPSO

EPSO is also in the bytecode optimization space, but its method is rewrite-rule/superoptimization oriented.

Implication:

- It helps motivate the argument that custom rewrite inventories are expensive to maintain.
- That supports the "userspace llvmbpf as reusable optimization framework" angle.

## KFuse

KFuse fuses multiple BPF programs inside the kernel after verification. It is orthogonal.

Implication:

- KFuse is not a threat to the novelty of Approach 2.
- In fact, a hint system and KFuse could stack: first fuse programs, then lower the fused code with better JIT hints.

## What Makes the Strongest OSDI/SOSP Paper

The strongest paper is not "llvmbpf can also optimize bytecode." The strongest paper is:

> **llvmbpf as a userspace optimization advisor that safely improves existing kernel JITs across architectures without embedding LLVM in the kernel.**

That requires three ingredients:

### 1. A concrete system abstraction

Define a stable hint interface keyed by BPF instruction offsets and subprogram boundaries.

Minimal useful hints:

- `wide_load_ok(insn_off, width)`
- `select_region(head_off, true_off, false_off, merge_off, dst_reg)`
- `preferred_fallthrough(bb_id)`
- optional `callee_saved_mask(subprog_id)`

### 2. A clean safety contract

The safety contract should be:

- the original program is what the verifier approves
- hints are advisory only
- the kernel rechecks local structural preconditions before using any hint
- unsupported or invalid hints are ignored

This is much stronger than trusting userspace-generated native code.

### 3. A real cross-architecture evaluation

At minimum:

- x86 implementation
- arm64 implementation

Why not only x86:

- the paper claim is "applicable across architectures"
- arm64 naturally exercises different backend choices such as `csel` and `ldr`-family widening

RISC-V can be design-only if implementation time is limited, but x86-only is weaker.

## Recommended Research Plan

## Primary path: Approach 2

Build a prototype around two hint families:

1. **Safe wide-load hint**
   - Target the byte-recompose problem directly.
   - Userspace computes candidate widening regions.
   - Kernel JIT rechecks offset/width/alignment/type preconditions before emitting native wide loads.

2. **Select-region hint**
   - Target missing `cmov`/`csel`.
   - Userspace identifies branch diamonds with pure register assignment on both arms.
   - x86 lowers to `cmov`; arm64 lowers to `csel`; unsupported architectures ignore.

Secondary hint:

- basic-block order / fallthrough preference

Do not spend early effort on:

- verifier hints
- full register-allocation hints
- hybrid execution

## Fallback path: Approach 4-lite

If kernel work is blocked, build:

- a userspace pre-optimizer restricted to scalar and CFG simplifications
- a verifier-oracle fallback path
- evaluation on the current real-program corpus to measure acceptance rate

But present it honestly:

- it is a useful tool
- it is less able to attack the specific backend losses identified in the characterization

## Concrete prototype milestones

1. Export optimized LLVM IR from `llvmbpf` after `optimizeModule()`.
2. Build a userspace analysis pass that emits sidecar hints from optimized LLVM IR.
3. Add a kernel hint transport:
   - prototype: decl-tag payload on the main program function
   - better stopgap: side-band object through `fd_array`
   - best long-term ABI: new `hint_fd` or hint blob
   - acceptable alternative: new BTF-ext-like section with kernel parser
4. Implement x86 `wide_load_ok`.
5. Implement x86 `select_region`.
6. Implement arm64 `wide_load_ok`.
7. Evaluate on:
   - microbenchmarks already in the repo
   - the paired real-program corpus
   - reload/verification overhead

## Likely reviewer questions and good answers

### "Why not just put LLVM in the kernel?"

Because the contribution is exactly that you do not need to. Userspace llvmbpf does expensive analysis; the kernel only consumes a narrow advisory interface.

### "Why not use Merlin/K2/EPSO?"

Because they operate before or at bytecode level. Your measured gap is mostly in the backend lowering stage.

### "How do you preserve safety?"

Because the verified bytecode is unchanged, and the kernel validates or ignores hints locally.

### "Why is this cross-architecture?"

Because the hint producer is shared and the hint semantics are generic, while the per-arch JIT maps those hints to its own native instructions.

## Final Recommendation

If the objective is to maximize the probability of turning this work into a strong systems paper:

- **Lead with Approach 2.**
- Present Approach 4 as the strongest no-kernel-change alternative.
- Treat Approach 5 as a supporting extension, not the main idea.
- Drop Approach 3 from the critical path.

The main strategic lesson from your own characterization is:

> the biggest remaining opportunity is not "optimize BPF more"; it is "use userspace llvmbpf analysis to help the kernel JIT make better backend decisions safely."

That is the direction that best fits the evidence already collected, best distinguishes the work from K2/Merlin/EPSO/KFuse, and best supports an OSDI/SOSP contribution claim.

## References

- `docs/paper.md`, especially Sections 10 and 11
- `docs/kernel-jit-optimization-plan.md`
- `vendor/llvmbpf/src/compiler.cpp`
- `vendor/llvmbpf/src/llvm_jit_context.cpp`
- `vendor/linux/include/uapi/linux/bpf.h`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/kernel/bpf/btf.c`
- K2: https://arxiv.org/abs/2105.02178
- Merlin: https://dl.acm.org/doi/10.1145/3620665.3640369
- EPSO: https://arxiv.org/abs/2505.03776
- KFuse: https://www.cs.columbia.edu/~khli/papers/kfuse_eurosys22.pdf

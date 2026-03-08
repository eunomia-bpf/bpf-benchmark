# Kernel eBPF JIT Improvement Recommendations

This document distills the benchmark evidence from `docs/stage-log-2026-03-07.md`, `micro/results/performance_deep_analysis.md`, `micro/results/causal_isolation_analysis.md`, and `micro/results/paradox_analysis.md` into three concrete kernel x86-64 JIT improvement proposals. The emphasis is on mechanisms that are both measurable in the current data and plausibly actionable in `arch/x86/net/bpf_jit_comp.c`.

## 1. Executive Summary

Three improvement opportunities stand out from the comparative analysis:

1. **Byte-load recomposition optimization**. This is the largest single source of kernel instruction inflation: **50.7%** of measured extra instructions, and it has a directly isolated runtime cost of **0.447x** on `load_byte_recompose`, meaning the kernel is **2.24x slower** on that pattern alone.
2. **Conditional-move (`cmov`) support for select-like control flow**. Across the 22 JIT-dump benchmarks, LLVM emits **31 `cmov` instructions** while the kernel emits **0**; the most visible case is `switch_dispatch`, where LLVM uses **28 `cmov`** and the kernel stays branch-heavy.
3. **Per-function callee-saved register optimization**. Fixed prologue/epilogue overhead accounts for **18.5%** of measured extra instructions, and the benchmarked kernel always saves at least `rbp`, `rbx`, and `r13`, even in trivial programs.

Estimated combined potential:

- These three mechanisms account for about **89.1%** of the measured kernel instruction surplus (`50.7% + 19.9% + 18.5%`).
- As a static-code upper bound, if those surpluses were removed without overlap, the kernel's total native instruction volume would move from `1.00x` of current size to roughly **0.50x**, close to llvmbpf's observed **0.44x** instruction ratio and **0.496x** native-code-size ratio.
- Runtime upside will be smaller than the static upper bound and highly workload-dependent, but the mechanisms line up with the two categories where llvmbpf already wins most consistently: **control-flow = 0.627x** and **memory-local = 0.665x**.

## 2. Improvement 1: Byte-Load Recomposition Optimization

### Current behavior

The benchmarked kernel JIT expands byte-based BPF loads into byte-at-a-time reconstruction ladders. In the JIT dumps, logical wide loads become repeated `movzbq + shl + or` sequences. The benchmark suite exposes this as the dominant source of static code inflation.

Example from `memory_pair_sum`:

**Kernel JIT**:

```x86asm
; kernel loads 8 individual bytes, shifts, and ORs them together
movzbq  (%rdi), %rax        ; load byte 0
movzbq  1(%rdi), %rcx       ; load byte 1
shl     $8, %rcx
or      %rcx, %rax
movzbq  2(%rdi), %rcx       ; load byte 2
shl     $16, %rcx
or      %rcx, %rax
movzbq  3(%rdi), %rcx       ; load byte 3
shl     $24, %rcx
or      %rcx, %rax
; ... 4 more bytes for the full 64-bit value
```

**llvmbpf LLVM**:

```x86asm
; LLVM loads the full 64-bit word directly
mov     (%rdi), %rax
```

### Evidence

- Byte-load recomposition is the single largest measured source of extra kernel instructions: **50.7%** of total surplus.
- On the 22-benchmark JIT-dump subset, the kernel has **62 recompose sites** covering **320 byte-load instructions**; llvmbpf has **5 sites** covering **32 byte-load instructions**.
- The largest static inflation is `bounds_ladder`: **7** kernel recompose sequences and **40** byte-loads, versus **2** and **8** for llvmbpf, for a **+141 instruction** gap and **2.81x** kernel/llvmbpf instruction ratio.
- The causal-isolation benchmark `load_byte_recompose` directly quantifies the runtime cost: **0.447x** exec ratio (95% CI `[0.417, 0.481]`), meaning the kernel is **2.24x slower** on this pattern alone.
- The control benchmarks establish the baseline for non-recompose memory access: `load_word32 = 0.779x`, `load_native_u64 = 0.776x`, while the full recompose case falls to **0.447x**.
- This aligns with the broader suite: the `memory-local` category has an exec geomean of **0.665x**, and stride-based memory cases such as `stride_load_4` (**0.442x**) and `stride_load_16` (**0.423x**) strongly favor llvmbpf.

### Proposed fix

Add a JIT-side recognizer for verifier-safe byte-recompose idioms and collapse them into direct wide loads when all of the following are already known:

- the address is aligned for the target width;
- the verifier has already established bounds and type safety for the full scalar;
- the recompose ladder is simply materializing a little-endian 32-bit or 64-bit scalar, not mixing unrelated bytes.

In practice, the kernel JIT should recognize ladders generated from repeated `BPF_LDX_MEM_B` uses that feed a pure shift/OR tree and emit:

- `movzbl` / `movzwl` / `movl` / `movq` for direct scalar loads, or
- a smaller pair of loads when full-width loads are not legal but byte-by-byte synthesis is unnecessarily conservative.

### Expected impact

This is the highest-payoff improvement in the current data:

- it removes the biggest static tax (**50.7%** of surplus);
- it is already proven to matter dynamically (**2.24x** isolated penalty);
- it targets packet parsing and structured-header extraction, where BPF frequently reconstructs wider fields from packet or map-backed bytes.

One important caveat from the benchmark suite: not every packet-oriented program is dominated by this path. For example, `packet_parse` is near parity at **0.964x**. The recommendation therefore is not "all packet programs will speed up equally", but rather "packet programs that repeatedly reconstruct header fields are the most likely high-return targets."

## 3. Improvement 2: Conditional Move (`cmov`) Support

### Current behavior

In the measured benchmark set, the kernel JIT never lowers BPF control flow to `cmov`; it emits conditional branches directly instead. LLVM uses `cmov` opportunistically for select-like patterns and min/max-style clamping.

### Evidence

- Across the JIT-dump subset, LLVM emits **31 `cmov`** instructions and the kernel emits **0**.
- The most important case is `switch_dispatch`, where LLVM emits **28 `cmov`** and the kernel emits **0**.
- `switch_dispatch` also shows the shape difference clearly:
  - exec ratio: **0.789x**
  - total instructions: **279** (llvmbpf) vs **350** (kernel)
  - branches: **69** (llvmbpf) vs **136** (kernel)
- Additional `cmov` use appears in `bounds_ladder` (**2**) and `binary_search` (**1**), both benchmarks with strong llvmbpf wins: `bounds_ladder = 0.479x`, `binary_search = 0.481x`.
- More broadly, branch instructions account for **19.9%** of measured extra kernel instructions, and the `control-flow` category has the strongest benchmark-wide llvmbpf advantage at **0.627x**.

### Proposed fix

Add a late pattern-recognition pass in the x86 JIT for branch diamonds of the form:

```text
if (cond) goto L_true
dst = a
goto L_merge
L_true:
dst = b
L_merge:
```

When both arms only assign a register value and have no side effects, lower the construct to:

1. one compare;
2. one default move;
3. one `cmovcc`.

This is necessarily a JIT pattern-recognition feature rather than a direct ISA mapping, because the BPF ISA does not expose a native `cmov` instruction.

The best initial targets are:

- switch-like select chains (`switch_dispatch`);
- min/max and clamp idioms (`bounds_ladder`);
- compare-and-select patterns in search kernels (`binary_search`).

### Expected impact

`cmov` support will not matter for every control-heavy program, but it directly targets the cases where branch prediction is the bottleneck rather than arithmetic throughput. The likely payoff is:

- fewer unpredictable branch edges;
- less branch-predictor pressure in data-dependent dispatch code;
- tighter select-style lowering without extra merge blocks.

This recommendation is especially well aligned with `switch_dispatch`, where the current kernel path pays for **136** branches while LLVM replaces much of that structure with **28** `cmov`.

## 4. Improvement 3: Per-Function Callee-Saved Register Optimization

### Current behavior

The benchmarked kernel JIT pays a fixed prologue tax by saving at least `rbp`, `rbx`, and `r13` regardless of whether the function actually needs all of them. LLVM varies the save set by function.

From the prologue analysis:

- prologue/epilogue ratio: **0.40x** (llvmbpf/kernel);
- prologue/epilogue contributes **18.5%** of measured extra kernel instructions.

Representative examples from the JIT dumps:

| Benchmark | Kernel saves | LLVM saves | Prologue instructions (K vs L) |
| --- | --- | --- | ---: |
| `simple` | `rbp, rbx, r13` | `rbx` | `7 vs 2` |
| `memory_pair_sum` | `rbp, rbx, r13` | `rbx` | `7 vs 2` |
| `fibonacci_iter` | `rbp, rbx, r13` | `rbx` | `7 vs 4` |
| `binary_search` | `rbp, rbx, r13, r14, r15` | `r15, r14, rbx` | `11 vs 4` |
| `spill_pressure` | `rbp, rbx, r13, r14, r15` | `rbp, r15, r14, r13, r12, rbx` | `11 vs 14` |

The `spill_pressure` and `switch_dispatch` exceptions are useful: LLVM is not "always saving fewer registers". It is saving registers **adaptively**. In register-heavy kernels it may save more, but in trivial kernels it saves much less. That adaptive behavior is what the kernel JIT currently lacks in the benchmarked configuration.

### Proposed fix

Add per-function register-usage analysis before prologue emission and save only the callee-saved registers that are actually clobbered by the generated native code. The minimum version of this optimization is:

- compute the physical callee-saved set used by the function;
- emit pushes/pops only for that set;
- avoid fixed saves of `rbx` and `r13` when they are dead for the whole function.

If the x86 JIT can safely operate without a frame pointer for leaf-like programs, a second-stage refinement is to omit `rbp` setup as well when stack layout and unwinding constraints allow it.

### Expected impact

This is the smallest of the three improvements by dynamic upside, but it is also the cleanest fixed-overhead reduction:

- it directly attacks **18.5%** of measured extra instructions;
- it helps the short programs that are currently paying a fixed `7`-instruction prologue for almost no useful work;
- it should reduce call and return overhead in helper-light, small-function kernels.

The performance analysis suggests one limit: fixed prologue savings alone will not explain the suite's largest speedups, because the benchmark categories with the biggest llvmbpf wins are `control-flow` and `memory-local`, not `call-size`. This makes prologue optimization a good "easy win", but not the first place to expect dramatic runtime changes.

## 5. Additional Observations

### LLVM's instruction-scheduling and critical-path advantages

The paradox analysis shows why static compaction is not enough by itself: what matters is whether the critical path shrinks. In several kernels LLVM's advantage appears not just as "fewer instructions" but as a shorter dependency chain in the hot loop:

- `bitcount`: kernel loop chain **14** vs LLVM **6**
- `fixed_loop_large`: **11** vs **5**
- `code_clone_8`: **59** vs **45**

These are not pure scheduling measurements, but they are consistent with LLVM producing tighter dependency structure once byte-recompose ladders and extra control-flow edges are gone.

### Dead code elimination across basic blocks

The optimization ablation shows that for these BPF-scale programs, essentially all useful LLVM optimization arrives by `-O1`, and the stage log explicitly attributes that to **dead code elimination, constant propagation, and register allocation**. That fits the control-flow results:

- `control-flow` category exec geomean: **0.627x**
- branch ratio: **0.76x**
- LLVM merges or removes branches that the kernel JIT still lowers 1:1.

This is a useful observation, but it is not yet isolated enough to recommend a kernel-side global optimization pass ahead of the three targeted fixes above.

### Constant folding through phi-like merge structure

The current benchmark set does not isolate phi-driven constant folding as a standalone causal mechanism, so this remains an inference rather than a measured recommendation. Still, merge-heavy benchmarks such as `switch_dispatch`, `binary_search`, and `bounds_ladder` are exactly the kinds of kernels where SSA-based simplification can fold values before instruction selection. The practical implication is that some residual LLVM advantage will remain even after the three recommended kernel JIT improvements, because the kernel JIT does not operate over a rich SSA form.

## 6. Implementation Feasibility Assessment

`docs/references/linux-bench-framework-analysis.md` reports `arch/x86/net/bpf_jit_comp.c` at roughly **4,110 LOC**. All three recommendations are therefore localized changes relative to backend size; the main difference is not file scale but how much new analysis each feature requires.

### Difficulty ranking

1. **Easiest**: per-function callee-saved optimization
2. **Medium**: byte-load recompose optimization
3. **Hardest**: `cmov` support

### Estimated implementation effort

| Improvement | Difficulty | Estimated LOC in `arch/x86/net/bpf_jit_comp.c` | Why |
| --- | --- | ---: | --- |
| Per-function callee-saved optimization | Low to medium | **40-100 LOC** | Mostly prologue/epilogue bookkeeping plus register-usage tracking |
| Byte-load recompose optimization | Medium | **120-220 LOC** | Requires safe pattern recognition in load lowering and width/alignment legality checks |
| `cmov` support | Medium to high | **180-320 LOC** | Requires recognizing branch diamonds or select-like idioms before final x86 emission |

These are estimates, not measurements. They assume localized x86 JIT work rather than a new generic BPF IR pass.

### Mailing-list discussion status

Based on repository search plus a targeted search of accessible bpf-list mirrors:

- **Per-function callee-saved optimization**: **Yes, adjacent upstream discussion exists.** The x86 JIT's callee-saved-register tracking (`callee_regs_used`) appears in bpf-list-visible JIT work, which means this area already has upstream precedent and review vocabulary.
- **Byte-load recompose optimization**: **No directly matching bpf-list discussion found** in the materials reviewed for this document.
- **`cmov` support**: **No directly matching bpf-list discussion found** in the materials reviewed for this document.

So the practical reading is:

- prologue/register-save work is the most upstream-familiar topic;
- byte-recompose and `cmov` look like benchmark-driven proposals that would probably need fresh RFC discussion and benchmark-backed justification.

### Recommended implementation order

If the goal is "fastest path to a measurable kernel JIT win", the order should be:

1. **Byte-load recompose optimization first**: largest measured payoff and strongest causal evidence.
2. **Per-function callee-saved optimization second**: easiest patch and low risk.
3. **`cmov` support third**: worthwhile, but the most analysis-heavy change because the BPF ISA does not encode it directly.

That ordering balances expected speedup against implementation risk better than simply sorting by difficulty.

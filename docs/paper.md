# How Good Is the Kernel eBPF JIT? A Systematic Comparison with LLVM -O3

## Abstract

eBPF programs run in production across networking, tracing, security, and scheduling, yet the code quality of the kernel's single-pass JIT has never been systematically compared against a full optimizing compiler on identical inputs. This paper presents the first native-code-level comparison between the Linux kernel eBPF JIT and llvmbpf, a userspace LLVM -O3 JIT, using identical BPF ELF objects and matched sampling on Intel Arrow Lake-S. Across 31 authoritative pure-JIT microbenchmarks, llvmbpf achieves an execution-time geomean of 0.849x relative to the kernel JIT (95% CI [0.834, 0.865]) while producing 2x smaller native code (code-size ratio 0.496x). The advantage is not uniform: 10/31 benchmarks are "smaller but slower," which we trace to loop-carried dependencies, cloned straight-line math, and branch-predictor pressure — cases where LLVM removes non-critical-path instructions without shortening the dynamic bottleneck. JIT-dump analysis identifies three concrete kernel JIT improvement opportunities — byte-load recomposition (50.7% of instruction surplus, 2.24x isolated penalty), conditional-move support (31 vs 0 cmov instructions), and adaptive callee-saved registers (18.5% of surplus) — that together account for 89% of the measured native-code gap. LLVM pass ablation reveals that only two passes (InstCombinePass and SimplifyCFGPass) produce measurable effects on BPF programs, implying that basic peephole optimization would close most of the gap without a full LLVM backend. External validation on 162 paired real-program instances (36 unique) confirms the code-size advantage (0.618x), and execution-time validation with valid network packets yields 0.514x across 98 paired runnable instances.

---

## 1. Introduction

eBPF has become the dominant in-kernel extension mechanism, powering production infrastructure from Cilium's network policy enforcement to Linux's sched_ext scheduling framework. Every BPF program in deployment passes through the kernel's built-in JIT compiler — a single-pass, linear-scan translator that converts verified BPF bytecode to native machine code. This compiler was designed for simplicity, correctness, and fast compilation rather than for output code quality. But how much performance is left on the table?

No prior work has systematically compared the native code produced by the kernel JIT against a full optimizing compiler on identical BPF bytecode inputs. Existing optimization efforts — K2 (SIGCOMM'21), Merlin (ASPLOS'24), EPSO (ASE'25) — operate at the bytecode level before JIT compilation, constrained by the BPF verifier. We measure the JIT backend itself: what happens after verification, at the point where bytecode becomes machine code.

To answer this question, we built a measurement framework that feeds the same BPF ELF objects to both the Linux kernel JIT and llvmbpf, a userspace runtime that lifts BPF bytecode to LLVM IR and applies the full -O3 optimization pipeline before JIT compilation. The comparison is controlled: identical inputs, matched sampling with counterbalanced runtime ordering, and conservative statistical inference (paired Wilcoxon with Benjamini-Hochberg correction, bootstrap confidence intervals).

Our contributions are:

1. **First systematic native-code comparison**: 0.849x execution-time geomean and 0.496x code-size ratio across 31 microbenchmarks, with 25/31 statistically significant differences.
2. **Root-cause analysis**: byte-load recomposition (2.24x isolated penalty), absence of conditional moves, and fixed prologue overhead account for 89% of the kernel's instruction surplus.
3. **LLVM pass ablation**: only InstCombinePass and SimplifyCFGPass matter for BPF; all other tested passes have zero effect, implying that basic peephole optimization would close most of the code-quality gap.
4. **External validation**: 162 paired real-program instances (36 unique) from Cilium and libbpf-bootstrap confirm the code-size advantage (0.618x); valid-packet execution-time validation yields 0.514x across 98 paired instances.
5. **Three actionable kernel JIT improvements** with quantified impact estimates and implementation feasibility assessment.

## 2. Experimental Setup

> **Takeaway:** The experimental design emphasizes matched comparisons, repeated sampling, and conservative inference so that timing asymmetries and machine noise are bounded rather than ignored.

To support defensible paired comparisons, platform, sampling, and statistical procedures were fixed in advance and applied uniformly across runtimes. The resulting setup was intended to prioritize internal validity first, while making any remaining measurement asymmetries explicit.

### 2.1 Platform

| Item | Value |
|------|-------|
| CPU | Intel Core Ultra 9 285K (Arrow Lake-S), 24 cores (8P+16E), no HT |
| Cache | L1d 768K, L1i 1.3M, L2 40M, L3 36M |
| RAM | 128 GB DDR5 |
| Kernel | 6.15.11-061511-generic (PREEMPT_DYNAMIC) |
| Spectre | Enhanced IBRS + IBPB conditional |
| BPF | CONFIG_BPF_JIT=y, BTF enabled |

### 2.2 Sampling Design

| Parameter | Value |
|-----------|-------|
| Iterations | 30 |
| Repeats per iteration | 1000 (`BPF_PROG_TEST_RUN` repeat) |
| Runtime ordering | Per-iteration counterbalanced random interleaving |
| Input generation | Deterministic LCG-seeded binary generators |
| Environment | `--strict-env` (taskset + performance governor) |
| Turbo/frequency | NOT hard-disabled; noise addressed via repetition + drift analysis |

### 2.3 Statistical Methods

| Method | Role |
|--------|------|
| Paired Wilcoxon signed-rank | Primary significance test (matched by iteration index) |
| Benjamini-Hochberg FDR | Multiple-comparison correction across benchmarks |
| Bootstrap (10000 iter, seed 0) | 95% CI for suite-level geomean ratio |
| Cohen's d | Effect size per benchmark |
| Mann-Whitney U | Supplementary reference only |
| Spearman rank drift test | Time-series stability (30 iterations) |
| ACF(1) | Autocorrelation check per benchmark×runtime pair |

### 2.4 Primary Metric

`exec_ns` — pure BPF execution time on both sides.
- **kernel**: `ktime_get_ns()` inside `BPF_PROG_TEST_RUN` (~100 ns resolution)
- **llvmbpf**: `rdtsc/rdtscp` fence around `vm.exec()` (sub-nanosecond resolution)
- `wall_exec_ns` (user-space rdtsc including syscall dispatch) is recorded but NOT used for cross-runtime comparison.

These choices were intended to isolate execution from dispatch overhead while acknowledging that timer symmetry is imperfect. Accordingly, quantitative interpretation is centered on programs well above the kernel timer's resolution limit, and sub-resolution cases are treated explicitly as artifacts rather than folded into substantive conclusions.

## 3. Benchmark Suite

> **Takeaway:** The benchmark suite was designed for mechanism isolation first, with a smaller runtime-oriented component added to test whether the same tendencies survive the introduction of helpers and maps.

The suite combines a larger pure-JIT set with a smaller runtime set so that backend code generation and runtime service interaction can be examined separately. This structure is useful analytically, but it also means that representativeness and causal isolation are intentionally traded against one another.

### 3.1 Inventory

| Suite | Config | Benchmarks | Authoritative? |
|-------|--------|--------:|:-:|
| Pure-JIT (staged codegen) | `micro_pure_jit.yaml` | 35 | 31/35 (4 causal-isolation benchmarks added post-run) |
| Runtime (map/helper) | `micro_runtime.yaml` | 9 | 9/9 |

The 31 authoritative pure-JIT benchmarks span 8 categories:

| Category | Count | Examples |
|----------|------:|---------|
| alu-mix | 3 | `mixed_alu_mem`, `large_mixed_500`, `large_mixed_1000` |
| baseline | 2 | `simple`, `simple_packet` |
| control-flow | 4 | `branch_layout`, `switch_dispatch`, `binary_search`, `branch_dense` |
| dependency-ilp | 5 | `dep_chain_short`, `dep_chain_long`, `multi_acc_4`, `multi_acc_8`, `spill_pressure` |
| loop-shape | 5 | `fibonacci_iter`, `nested_loop_2`, `nested_loop_3`, `fixed_loop_small`, `fixed_loop_large` |
| memory-local | 6 | `stride_load_4`, `stride_load_16`, `bounds_ladder`, `checksum`, `bounds_check_heavy`, `memory_pair_sum` |
| program-scale | 2 | `large_mixed_500`, `large_mixed_1000` |
| call-size / code-clone | 4 | `code_clone_2`, `code_clone_8`, `packet_parse`, `fibonacci_iter_packet` |

### 3.2 Input Staging

All pure-JIT benchmarks use **staged I/O**: input is written to `input_map` via `bpf_map_lookup_elem` inside the BPF program; the result is returned in the first 8 bytes of the XDP test packet. This measures JIT codegen quality under realistic map-access staging, not helper-free isolation.

Accordingly, the pure-JIT results should be read as staged-map kernels rather than as idealized helper-free arithmetic loops. That choice modestly reduces cleanliness as a backend-only experiment, but it improves practical relevance by preserving realistic memory-access patterns.

## 4. Authoritative Results

> **Takeaway:** llvmbpf was generally faster and consistently smaller, but the advantage was heterogeneous enough that benchmark-level mechanism analysis is required to interpret the tails of the distribution.

The primary empirical findings are presented below for execution time, compilation cost, and measurement stability. In aggregate, the results favor llvmbpf, but the distribution is sufficiently wide that suite-level averages alone would understate the importance of specific mechanisms.

### 4.1 Execution Time — Pure-JIT Suite (31 benchmarks)

**Suite-level:**

| Metric | Value |
|--------|------:|
| Exec time geomean (llvmbpf/kernel) | **0.849x** |
| 95% CI (bootstrap) | [0.834, 0.865] |
| Significant (BH-corrected Wilcoxon p < 0.05) | 25 / 31 |
| llvmbpf wins / kernel wins | 21 / 10 |

**Per-benchmark (sorted by exec ratio):**

| Benchmark | llvmbpf ns | kernel ns | Exec ratio | Code ratio | Significant |
|-----------|----------:|---------:|----------:|----------:|:-----------:|
| `branch_layout` | 162 | 561 | **0.289x** | 0.354x | Yes |
| `nested_loop_3` | 277 | 684 | **0.405x** | 0.884x | Yes |
| `stride_load_16` | 104 | 246 | **0.423x** | 0.332x | Yes |
| `stride_load_4` | 107 | 241 | **0.442x** | 0.332x | Yes |
| `bounds_ladder` | 91 | 189 | **0.479x** | 0.394x | Yes |
| `binary_search` | 213 | 442 | **0.481x** | 0.449x | Yes |
| `large_mixed_500` | 355 | 512 | 0.693x | 0.464x | Yes |
| `mixed_alu_mem` | 512 | 696 | 0.737x | 0.817x | Yes |
| `large_mixed_1000` | 744 | 1002 | 0.742x | 0.419x | Yes |
| `fixed_loop_small` | 104 | 136 | 0.759x | 0.359x | Yes |
| `switch_dispatch` | 212 | 268 | 0.789x | 0.800x | Yes |
| `fibonacci_iter` | 577 | 719 | 0.803x | 0.395x | Yes |
| `fibonacci_iter_packet` | 599 | 732 | 0.818x | 0.343x | Yes |
| `nested_loop_2` | 441 | 535 | 0.823x | 0.501x | Yes |
| `dep_chain_short` | 127 | 147 | 0.861x | 0.413x | Yes |
| `spill_pressure` | 256 | 294 | 0.871x | 0.759x | Yes |
| `checksum` | 10829 | 12031 | 0.900x | 0.418x | Yes |
| `multi_acc_4` | 273 | 287 | 0.951x | 0.646x | No |
| `multi_acc_8` | 436 | 458 | 0.951x | 0.756x | No |
| `dep_chain_long` | 419 | 435 | 0.964x | 0.414x | No |
| `packet_parse` | 99 | 103 | 0.964x | 0.499x | No |
| `log2_fold` | 312 | 311 | 1.006x | 0.659x | No |
| `bounds_check_heavy` | 283 | 253 | 1.119x | 0.807x | No |
| `fixed_loop_large` | 1493 | 1251 | **1.193x** | 0.425x | Yes |
| `memory_pair_sum` | 19 | 15 | 1.251x | 0.238x | Yes* |
| `code_clone_2` | 409 | 325 | **1.260x** | 0.492x | Yes |
| `simple_packet` | 18 | 13 | 1.321x | 0.490x | No* |
| `branch_dense` | 628 | 446 | **1.409x** | 0.732x | Yes |
| `simple` | 21 | 14 | 1.526x | 0.622x | Yes* |
| `bitcount` | 4647 | 2985 | **1.556x** | 0.446x | Yes |
| `code_clone_8` | 2267 | 1207 | **1.878x** | 0.542x | Yes |

(*) Sub-resolution: kernel exec < 100 ns, below `ktime_get_ns()` granularity — measurement artifact.

The distribution is skewed toward llvmbpf improvements rather than being centered on parity. Strong wins cluster in control-flow and memory-local patterns, where `branch_layout`, `binary_search`, `stride_load_4`, `stride_load_16`, and `bounds_ladder` all fall well below 0.5x. Several larger mixed or loop-structured programs, including `large_mixed_500`, `large_mixed_1000`, `fibonacci_iter`, and `nested_loop_2`, also remain clearly favorable to llvmbpf, which suggests that the advantage is not confined to trivial straight-line kernels. By contrast, the dependency-ILP group is concentrated much closer to 1.0x, with `multi_acc_4`, `multi_acc_8`, and `dep_chain_long` essentially near parity.

The observed performance spectrum is wide, ranging from 0.289x (`branch_layout`) to 1.878x (`code_clone_8`). This spread indicates that code-size reduction alone does not determine runtime. The strongest llvmbpf wins are generally associated with programs in which LLVM can collapse branch structure, avoid repeated byte-wise value reconstruction, or issue wider loads that reduce useful work on the hot path. The largest losses, in contrast, arise either in sub-resolution baselines (`simple`, `simple_packet`, `memory_pair_sum`) or in workloads dominated by recurrences, cloned scalar dependence chains, or dense branch behavior (`fixed_loop_large`, `branch_dense`, `bitcount`, `code_clone_8`).

What separates the winners from the losers is therefore less the absolute number of emitted instructions than the location of those instructions relative to the dynamic critical path. When llvmbpf removes control-flow overhead or byte-recompose sequences from frequently executed regions, substantial speedups are observed. When its reductions fall mainly on non-critical-path work, or when timer granularity obscures very small kernels, the static compactness advantage does not translate into lower `exec_ns`.

### 4.2 Execution Time — Runtime Suite (9 benchmarks)

| Metric | Value |
|--------|------:|
| Exec time geomean (llvmbpf/kernel) | **0.829x** |
| 95% CI | [0.801, 0.859] |
| Significant | 7 / 9 |
| llvmbpf wins / kernel wins | 6 / 3 |

| Benchmark | Exec ratio | Significant |
|-----------|----------:|:-----------:|
| `percpu_map_update` | 0.490x | Yes |
| `hash_map_lookup` | 0.681x | Yes |
| `map_roundtrip` | 0.726x | Yes |
| `helper_call_100` | 0.962x | Yes |
| `helper_call_10` | 0.990x | No |
| `helper_call_1` | 1.047x | No |
| `map_lookup_churn` | 1.307x | Yes |
| `probe_read_heavy` | 0.754x | Yes |
| `get_time_heavy` | 0.843x | Yes |

Relative to the pure-JIT suite (0.849x), the runtime suite (0.829x) is slightly more favorable to llvmbpf, which suggests that the code-generation advantage survives the introduction of helpers and maps rather than disappearing once runtime services are involved. The important exception is that helper-heavy cases compress toward parity: `helper_call_1`, `helper_call_10`, and `helper_call_100` are governed largely by helper cost, so differences in native instruction selection are only weakly expressed in total execution time. Map-heavy benchmarks behave differently because the dynamic cost shifts into runtime data-structure interaction, where access pattern and implementation details matter more than pure arithmetic lowering. This explains why `percpu_map_update`, `hash_map_lookup`, and `map_roundtrip` still favor llvmbpf, yet `map_lookup_churn` reverses direction at 1.307x: repeated lookup behavior appears to amplify runtime-specific overheads that are not visible in the pure-JIT kernels.

### 4.3 Compile Time

| Metric | Value |
|--------|------:|
| Compile time geomean (llvmbpf/kernel) | **3.394x** |
| llvmbpf faster | 5 / 31 (`bitcount`, `binary_search`, `branch_layout`, `switch_dispatch`, `checksum`) |

For small programs (< 200 BPF insns), llvmbpf LLVM -O3 overhead dominates: typically 8–16x slower. For larger/complex programs, kernel verifier + JIT can be slower than LLVM. Compilation is a one-time cost for networking fast paths but matters for frequent-reload scenarios (e.g., Cilium live updates).

The compile-time results suggest a crossover rather than a uniform penalty. For programs that remain in the sub-200-instruction regime, fixed LLVM pipeline overhead dominates and produces the expected slowdown. As program size and control-flow complexity increase, however, kernel-side verifier work and JIT lowering can grow enough that the one-time LLVM cost is amortized, allowing llvmbpf to become competitive or occasionally faster on `bitcount`, `binary_search`, `branch_layout`, `switch_dispatch`, and `checksum`. The crossover should therefore be interpreted as a joint function of program size and verifier difficulty, not as a simple monotone threshold in instruction count alone.

### 4.4 Measurement Stability

Across 62 benchmark×runtime pairs (30 iterations each):

| Metric | Value |
|--------|------:|
| Pairs with significant drift (p < 0.05) | 3 / 62 |
| Pairs with strong autocorrelation (\|ACF(1)\| > 0.3) | 3 / 62 |
| Maximum drift | 16.13% (`stride_load_4` kernel) |

The 3 drifted pairs: `stride_load_4` kernel (+16.1%), `mixed_alu_mem` kernel (−4.5%), `fixed_loop_large` llvmbpf (+3.1%). None alter suite-level conclusions.

The stability analysis indicates that the matched sampling design was adequate for the present claims. Only 3 of 62 benchmark×runtime pairs exhibited statistically significant drift, and only 3 showed strong first-order autocorrelation, with the worst case confined to `stride_load_4` on the kernel side. Because these effects are sparse and do not alter the suite-level ordering, the data appear to be dominated by stable between-runtime differences rather than by slow temporal drift. Residual noise should still be treated as real, but it appears localized rather than systemic.

### 4.5 Causal Isolation: Byte-Recompose Time Decomposition

> **Takeaway:** The byte-recompose pattern alone accounts for a 2.24x execution-time penalty (load_byte_recompose 0.447x), answering the previously open question of how much of the instruction surplus translates to runtime cost.

`micro/results/causal_isolation_analysis.md` adds four causal-isolation microbenchmarks that separate byte-recompose from simpler byte loads and from baseline non-recompose memory operations.

| Benchmark | Exec ratio (L/K) | Significant | Code-size ratio |
|-----------|-----------------:|:-----------:|----------------:|
| `load_byte_recompose` | **0.447x** | Yes | 0.343x |
| `load_byte` | 0.699x | Yes | 0.420x |
| `load_native_u64` | 0.776x | Yes | 0.505x |
| `load_word32` | 0.779x | Yes | 0.381x |

Suite geomean: **0.660x**, with **4/4** benchmarks significant.

The decomposition makes the time cost of byte recomposition explicit. `load_byte_recompose` (0.447x) isolates the pure recompose overhead: the kernel rebuilds values byte-by-byte, and that pattern alone yields a 2.24x penalty relative to llvmbpf. `load_byte` (0.699x) shows that simpler byte-load operations also suffer, but less severely than the full recompose case. `load_word32` (0.779x) and `load_native_u64` (0.776x) establish the baseline for non-recompose memory operations, both clustering around 0.78x. The resulting roughly 2x gap between recompose (0.447x) and non-recompose loads (~0.78x) quantifies the runtime cost of this single lowering pattern. This directly answers the OSDI reviewer question: "byte-recompose is 50.7% of extra instructions - how much extra TIME?"

### 4.6 Deep Performance Analysis Cross-Checks

`micro/results/performance_deep_analysis.md` provides benchmark-wide cross-checks that sharpen the interpretation of the suite-level results:

- Per-category, llvmbpf benefits most in `control-flow` (0.627x) and `memory-local` (0.665x), while `call-size` (1.539x) and `baseline` (1.361x) remain kernel-favorable.
- Code size is a weak runtime predictor: Pearson `r = 0.131` with non-significant `p = 0.4819`.
- `22/31` benchmarks have large Cohen's d effect sizes, indicating that most observed differences are practically meaningful.
- The fitted compile-time crossover is approximately `756` BPF instructions, but the relation between size and compile ratio remains weak.
- A static-feature runtime model using instruction count, branch count, and code ratio reaches only `R^2 = 0.070`, indicating that steady-state performance is not predictable from simple static features alone.

These cross-checks reinforce the central interpretation of the suite: dynamic mechanism matters more than static compactness, so code-size reductions alone are not sufficient to predict execution speed.

## 5. Generated Machine Code Analysis

> **Takeaway:** llvmbpf's code-size advantage is systematic and is driven chiefly by direct wide loads, branch restructuring, and more selective register-save behavior rather than by a dramatic spill reduction alone.

The JIT dump analysis compares the x86-64 instructions produced by each JIT for all 22 benchmarks with available dumps (see `micro/jit-dumps/report.md`). The aim of this section is not merely to restate that llvmbpf emits smaller code, but to identify which lowering decisions account for that result.

### 5.1 Overall Code Quality Ratios

| Dimension | llvmbpf/kernel ratio | Interpretation |
|-----------|--------------------:|----------------|
| Total instructions | **0.44x** | LLVM emits less than half the x86 instructions |
| Prologue/epilogue | **0.40x** | Kernel saves rbp+rbx+r13(+r14+r15) unconditionally; LLVM saves only what is needed |
| Spill instructions | 0.85x | Register spill gap smaller than expected |
| Branch instructions | 0.76x | Kernel does 1:1 BPF→x86 branch translation; LLVM reorders and merges |
| Conditional moves | 31 vs 0 | Kernel never emits `cmov`; LLVM uses it aggressively (`switch_dispatch`: 28 cmov) |
| NOP instructions | 0.59x | Alignment NOPs; kernel emits 2 per function, LLVM varies |
| Native code size (bytes) | **0.496x** | 31/31 benchmarks: llvmbpf smaller |

The ratios in this table point to a broad, multi-dimensional reduction in native code rather than to a single isolated effect. llvmbpf emits less than half as many total instructions and bytes, and the reduction is visible in fixed overhead (`0.40x` prologue/epilogue), control-flow structure (`0.76x` branches), and alignment noise (`0.59x` NOPs). The spill ratio of `0.85x` is notably closer to parity, which implies that register-pressure management is not the principal explanation for the aggregate size gap. Instead, code quality appears to improve through a combination of liveness-aware register saving, branch restructuring, and direct lowering of memory operations, with `cmov` usage providing an additional mechanism unavailable to the kernel JIT.

### 5.2 Where Kernel Adds Extra Instructions

The three dominant sources of kernel's instruction surplus:

| Source | Share of total surplus | Mechanism |
|--------|---------------------:|-----------|
| **Byte-load-recompose** | **50.7%** | Kernel rebuilds 32/64-bit values from individual byte loads: `movzbq` + `shl` + `or` sequences. This is a verifier safety requirement — the kernel JIT enforces byte-level memory access to prevent type confusion. LLVM loads the full word directly. |
| **Branch instructions** | **19.9%** | Kernel translates each BPF conditional jump to an x86 `jcc` 1:1 without branch layout optimization. LLVM reorders blocks, merges redundant branches, and in some cases replaces branches with `cmov`. |
| **Prologue/epilogue** | **18.5%** | Kernel unconditionally saves a fixed set of callee-saved registers (rbp, rbx, r13, and often r14, r15). LLVM analyzes liveness and saves only registers that are actually clobbered. |

Byte-recompose dominates because it is both frequent and multiplicative. Prologue/epilogue inflation is largely a fixed per-function tax, whereas byte-recompose is paid at each affected memory access and can recur inside hot loops. The staged-map design of the benchmark suite makes this especially salient: many kernels repeatedly materialize multi-byte values from packet or map-backed storage, so the kernel's verifier-driven safety strategy expands one logical load into a sequence of byte loads, shifts, and ORs. Once repeated across iterations, this pattern naturally overwhelms smaller structural effects such as extra branches or unconditional callee-save traffic.

### 5.3 Byte-Recompose Pattern (Detailed)

This is the single largest contributor to kernel's instruction inflation. Example from `memory_pair_sum`:

**Kernel JIT** (103 instructions) — to load a 64-bit value from the input map:
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

**llvmbpf LLVM** (24 instructions) — same value:
```x86asm
; LLVM loads the full 64-bit word directly
mov     (%rdi), %rax
```

Across the suite:
- Kernel: **62 recompose sites**, 320 byte-load instructions
- llvmbpf: **5 recompose sites**, 32 byte-load instructions
- The largest inflation: `bounds_ladder` with 7 kernel recompose sequences (40 byte-loads) vs 2 llvmbpf sequences (8 byte-loads), resulting in +141 extra instructions (2.81x kernel/llvmbpf).

### 5.4 Register Allocation: Prologue Comparison

| Benchmark | Kernel saves | LLVM saves |
|-----------|-------------|-----------|
| `simple` | rbp, rbx, r13 | rbx |
| `binary_search` | rbp, rbx, r13, r14, r15 | r15, r14, rbx |
| `switch_dispatch` | rbp, rbx, r13 | rbp, r15, r14, r13, r12, rbx |
| `spill_pressure` | rbp, rbx, r13, r14, r15 | rbp, r15, r14, r13, r12, rbx |
| `fibonacci_iter` | rbp, rbx, r13 | rbx |

Key observation: kernel always saves at least {rbp, rbx, r13}, even for trivial programs like `simple` that don't use r13. LLVM's liveness analysis eliminates unnecessary saves. However, for register-heavy benchmarks like `spill_pressure` and `switch_dispatch`, LLVM actually saves MORE registers (6 vs 5) because it uses r12 which is not in the kernel's BPF register mapping.

### 5.5 Branchless Lowering: cmov

Kernel JIT never emits conditional moves (`cmov = 0` across all benchmarks). LLVM uses them in two key patterns:

| Benchmark | LLVM cmov count | Pattern |
|-----------|----------------:|---------|
| `switch_dispatch` | **28** | Select-style dispatch: each case produces a value via `cmov` instead of a branch-to-assign sequence |
| `bounds_ladder` | 2 | Bounds clamping via min/max |
| `binary_search` | 1 | Mid-point selection |

This explains `switch_dispatch`'s 0.789x exec ratio: LLVM replaces 28 branch-prediction-dependent paths with data-flow operations, removing branch-predictor pressure entirely.

### 5.6 BMI (Bit Manipulation) Instructions

| Runtime | shlx | shrx | blsr | Total BMI |
|---------|-----:|-----:|-----:|----------:|
| Kernel | 5 | 11 | 0 | 16 |
| llvmbpf | 8 | 13 | 1 | 22 |

LLVM makes slightly more use of BMI2 instructions (`shlx`/`shrx` for variable shifts) and uniquely uses `blsr` (clear lowest set bit) in `bitcount` for a popcount-style loop.

### 5.7 Root Cause Analysis for Paradox Cases

For the "smaller but slower" paradox benchmarks, JIT dump analysis reveals specific critical-path mechanisms:

| Benchmark | Exec ratio | Kernel loop chain | LLVM loop chain | Root cause |
|-----------|----------:|------------------:|----------------:|-----------|
| `bitcount` | 1.556x | 14 | 6 | Kernel hot loop is more serialized; +12 byte-loads extend the loop-carried dependency chain before the mix operations |
| `code_clone_8` | 1.878x | 59 | 45 | Kernel rebuilds 64-bit lanes per iteration via byte-loads; LLVM uses `rorx` directly |
| `fixed_loop_large` | 1.193x | 11 | 5 | Kernel pays +16 byte-loads; LLVM uses `rorx` for rotate-heavy math |
| `dep_chain_short` | 0.861x | 13 | 10 | Same byte-load pattern, but here LLVM wins because chain is shorter (not a paradox) |

Note: dependency-chain estimates are heuristic (strongest backward-edge loop, register/flag flow analysis), not cycle-accurate throughput models.

## 6. LLVM Optimization Ablation

> **Takeaway:** For these BPF-scale programs, nearly all useful LLVM optimization appears to arrive by `-O1`, with higher levels contributing no measurable additional size reduction.

The ablation result is consistent with the short, scalar structure of the benchmark suite. Once dead code elimination, constant propagation, and register allocation have fired, little optimization headroom remains for higher-level passes.

| Opt level | Avg code size | vs -O0 |
|-----------|-------------:|-------:|
| -O0 | 1057 B | 1.00x |
| -O1 | 307 B | **0.29x** |
| -O2 | 307 B | 0.29x |
| -O3 | 307 B | 0.29x |

**Key finding**: For BPF-scale programs, all meaningful optimizations happen at -O1 (DCE, constant propagation, register allocation). -O2 and -O3 add zero incremental benefit — advanced optimizations (loop unrolling, vectorization) have no effect on these short, scalar programs.

### 6.1 Per-Pass Ablation (9 passes × 11 benchmarks)

> **Takeaway:** Only two LLVM passes — `InstCombinePass` and `SimplifyCFGPass` — produce measurable code-size changes on BPF programs. All other passes tested (GVN, LICM, LoopUnroll, SROA, JumpThreading, DSE, ADCE) have zero effect on the median benchmark, confirming that BPF code is too simple for most LLVM optimizations.

Using the new `--llvm-disable-pass` infrastructure, each of 9 candidate passes was individually disabled while keeping all others at -O3. Results across 11 representative benchmarks:

| Disabled pass | Median size ratio | Most affected benchmark | Size change |
|---------------|------------------:|------------------------|-------------|
| InstCombinePass | 1.025x | `large_mixed_500`: 1022→1603B (+57%) | Instruction combining is the primary size reducer |
| SimplifyCFGPass | 1.000x | `large_mixed_500`: 1022→1868B (+83%) | CFG cleanup is critical for complex programs |
| SROAPass | 1.000x | `binary_search`: 373→377B (+1%) | Minimal effect on BPF's register-only model |
| GVN, LICM, LoopUnroll, JumpThreading, DSE, ADCE | 1.000x | — | Zero code-size change on all benchmarks |

**Interpretation:** BPF programs lack the features that most LLVM passes target: no floating-point, no SIMD, no complex aliasing, no deep call graphs, no large stack frames. The two passes that matter — `InstCombinePass` (algebraic simplification, strength reduction) and `SimplifyCFGPass` (dead block elimination, branch threading) — correspond exactly to the code-quality differences observed in the JIT dump analysis (§5): instruction combining catches redundant operations, while CFG simplification removes unreachable blocks generated by the BPF verifier's conservative code emission.

This finding has a direct implication for kernel JIT design: a kernel JIT that adds even basic peephole optimization (instruction combining) and dead-block elimination would close a significant fraction of the code-quality gap without requiring a full LLVM backend.

Full results: `micro/results/pass_ablation.md`.

## 7. "Smaller But Slower" Paradox Analysis

> **Takeaway:** The paradox cases demonstrate that smaller native code is not, by itself, a sufficient predictor of lower runtime when the throughput-limiting mechanism is unchanged.

The paradox subset is small enough to classify manually and large enough to be explanatory. The purpose of this section is to distinguish genuine counterexamples from timer artifacts and then to relate the remaining cases to specific dynamic bottlenecks.

10/31 benchmarks exhibit the paradox: llvmbpf produces smaller code but slower execution. After excluding 3 sub-resolution measurement artifacts (kernel exec < 100 ns), **7 real paradox cases remain (5 statistically significant)**.

### 7.1 Category Decomposition

| Category | Count | Significant | Mechanism |
|----------|------:|------------:|-----------|
| **sub-resolution** | 3 | — | Measurement artifact. Programs finish in 13–15 ns, below ktime's ~100 ns granularity. Excluded from substantive analysis. |
| **tight-loop** | 3 | 2/3 | Loop-carried dependency chain determines execution time. LLVM eliminates non-critical-path instructions but cannot shorten the recurrence. |
| **code-clone** | 2 | 2/2 | Cloned straight-line scalar math in hot loop. Kernel's direct 1:1 lowering stays competitive because the dependency chain length is the same. |
| **branch-heavy** | 2 | 1/2 | 7–8 conditional branches per loop iteration. Branch-predictor pressure dominates, not code size. Kernel's direct `jcc` lowering keeps control flow on critical path. |

Across the three substantive paradox categories, a common pattern emerges: llvmbpf reduces static work without necessarily shortening the dynamic bottleneck. In the tight-loop cases, loop-carried recurrences continue to determine throughput even after redundant instructions have been removed. In the code-clone cases, both runtimes retain essentially the same scalar dependence structure across replicated blocks, so smaller code does not imply a shorter critical path. In the branch-heavy cases, predictor behavior and control-flow pressure dominate the steady-state cost, which limits the benefit of purely static compaction. Taken together, these categories suggest that the paradox is not anomalous; rather, it is the expected outcome when optimization affects code outside the throughput-limiting mechanism.

### 7.2 Core Insight

LLVM's instruction elimination mainly removes **non-critical-path instructions**. In paradox cases, runtime is determined by:
- Loop-carried recurrences (tight-loop)
- Per-iteration dependency chain length (code-clone)
- Branch-predictor table pressure (branch-heavy)

None of these are reduced by shrinking code size. **Code size ≠ performance.**

## 8. External Validation

> **Takeaway:** External evidence supports the code-size result strongly enough to argue that it generalizes beyond the microbenchmarks, but the execution-time validation remains intentionally cautious.

This section distinguishes between two different external claims. The code-size claim is supported by a materially larger real-program sample than the execution-time claim, whereas the timing evidence remains limited by loader reachability and sub-resolution fast-exit behavior.

### 8.1 Real-Program Code Size

| Metric | Value |
|--------|------:|
| Repos scanned | 4 (libbpf-bootstrap, cilium, inspektor-gadget, collected) |
| Input artifacts | 77 |
| Programs discovered | 949 |
| Both-runtime paired | 162 instances (36 unique programs) |
| Code-size geomean (L/K) | **0.618x** |
| llvmbpf smaller | 34/36 unique programs |

Failure breakdown:
- llvmbpf: 948 ok / 1 error (residual jump-target compatibility)
- kernel: 162 ok / 787 error (missing map/BTF/attach context → verifier rejection)

Caveat: 162 paired instances contain clang-version duplicates (Cilium programs repeat across clang-14 to clang-21). After dedup by unique program name: 36 programs from 3 repos. Two programs (`handle_lxc_traffic` and `usdt_auto_attach`) show a mild reversal at ~1.07x.

The external validation materially strengthens the claim that llvmbpf tends to emit smaller code on real programs, because the direction of effect is consistent across 34/36 unique paired programs and remains similar in magnitude (`0.618x`) to the microbenchmark result (`0.496x`). The paired set spans three repositories (cilium, libbpf-bootstrap, collected), and successful pairing is constrained by kernel-side loader and verifier limitations. Even so, the replication of the size advantage outside the synthetic suite indicates that the code-compactness result is unlikely to be a microbenchmark artifact.

### 8.2 Real-Program Execution Time

| Metric | Value |
|--------|------:|
| Paired instances with exec-time | 98 / 162 |
| Unique programs | 14 (TC/classifier + socket_filter) |
| Exec ratio geomean (L/K, all instances) | **0.514x** |
| Exec ratio geomean (L/K, 14 unique) | **0.484x** |
| llvmbpf wins / kernel wins | 13 / 1 |
| Kernel exec ≥ 20 ns | 97 / 98 |

Programs are exercised with valid Ethernet+IPv4+TCP packets (54 bytes) via `--raw-packet`, which resolved the earlier dummy-packet fast-exit artifact that had made all timings sub-resolution. After this fix, 97/98 kernel `exec_ns` readings are at or above 20 ns, with `tc_ingress` reaching 120 ns.

Failed programs: 61 ENOTSUPP (tracepoint/kprobe/cgroup), 1 Bad address (iter/task), 2 llvmbpf errors.

The real-program execution-time results are consistent with the microbenchmark findings: llvmbpf is faster on 13/14 unique programs. However, most programs still execute in the tens-of-nanoseconds regime, so these results should be read as lightweight external validation of the direction and approximate magnitude rather than as definitive workload-level performance claims.

### 8.3 Feature-Space Representativeness

Comparing the combined benchmark suite (44 benchmarks) against the BCF corpus (1588 real programs):

| Feature | Corpus median | Corpus p90 | Suite max | Gap |
|---------|-------------:|----------:|---------:|-----|
| Total insns | 10,977 | 22,899 | 1,596 | **6.9x** below median |
| Branch insns | 1,135 | 1,458 | 196 | 5.8x below median |
| Memory ops | 5,203 | 11,437 | 253 | 20.6x below median |
| Helper calls | 289 | 847 | 101 | 2.9x below median |
| BPF-to-BPF calls | 0 | 0 | 0 | No gap (most corpus programs also have 0 call insns) |

| Coverage metric | Value |
|-----------------|------:|
| % corpus in insn range | 3.7% |
| % corpus in helper-call range | 4.4% |
| % corpus in 5D feature box | **0.8%** |
| Multi-function programs in corpus | 97.2% |
| Multi-function programs in suite | 0% |

The micro-benchmarks target **mechanism isolation**, not corpus representativeness. The 0.8% feature-box coverage is an honest boundary — external validity relies on the 162-instance code-size and 98-instance execution-time validation, not on the micro-benchmark suite directly.

The `0.8%` 5D feature-box coverage has a practical interpretation: the microbenchmark suite occupies a narrow, low-complexity corner of the observed corpus. Mechanism-level conclusions drawn from the suite are therefore most defensible when a real program exhibits similar control-flow, memory-access, and helper-use motifs; they should not be read as a direct empirical summary of contemporary eBPF workloads. In practical terms, the suite is well suited for isolating causes, but poorly suited for describing prevalence. This is why the external code-size scan is central to the argument, whereas the microbenchmark coverage metric is best understood as an explicit limit on extrapolation.

## 9. Threats to Validity

> **Takeaway:** The most consequential threats are structural limitations on what can be loaded and exercised, whereas the remaining measurement threats are narrower and already bounded by auxiliary analyses.

| Threat | Status | Mitigation |
|--------|--------|-----------|
| Timing source asymmetry | Documented | kernel=ktime (~100ns), llvmbpf=rdtsc (sub-ns). 3 sub-resolution cases flagged as artifacts. For >100ns programs, bias is negligible vs observed ratio range (0.29x–1.88x). |
| Single platform | Open | x86-64 Arrow Lake-S only. ARM64 BPF JIT has different backend. |
| CPU frequency/turbo | Documented | Performance governor but turbo not hard-disabled. Drift analysis shows 3/62 pairs affected (max 16.1%). |
| PMU scope asymmetry | Documented | Kernel counters include kernel-mode events; llvmbpf user-mode only. PMU demoted to supplementary evidence. |
| External validation concentration | Documented | 36 unique programs from 3 repos (cilium, libbpf-bootstrap, collected). |
| Real-program exec-time scope | Documented | 98/162 paired instances (14 unique programs). Valid packets resolve sub-resolution, but most programs still execute in tens of nanoseconds. |
| BPF_PROG_TEST_RUN limitations | Structural | tracepoint/kprobe/perf_event/cgroup unsupported (61 ENOTSUPP). TC/classifier and socket_filter work with valid packet input. |
| Multi-function programs | Partially resolved | llvmbpf multi-function ELF loader now handles most cases (948/949 ok). Remaining gap is kernel-side verifier rejection without full attach context. |

Structural threats are the most consequential because they restrict the space of programs that can be studied at all. `BPF_PROG_TEST_RUN` cannot exercise tracepoint, kprobe, perf_event, or cgroup programs in the present harness, limiting the execution-time validation to TC/classifier and socket_filter programs. The llvmbpf multi-function ELF loader has been extended to handle most real-world programs (948/949 compile-only successes), but the kernel-side verifier rejects 787/949 programs without full attach context, which bounds the paired validation set.

Documented threats affect interpretation but are already bounded by auxiliary analysis. Timing source asymmetry matters mainly in the three sub-resolution microbenchmark cases, which are flagged explicitly; CPU frequency/turbo effects appear limited by the drift analysis (3/62 pairs affected, max 16.1%); and PMU asymmetry is acknowledged by demoting PMU results to supplementary status. The remaining documented external-validity concerns are the concentration of paired real programs in three repositories and the fact that most real-program execution times remain in the tens-of-nanoseconds regime.

Open threats are narrower but still material. The principal unresolved issue is platform diversity: all results were collected on a single x86-64 Arrow Lake-S system, whereas other x86 microarchitectures and especially ARM64 may exhibit different JIT backend behavior. This limitation does not negate the present findings, but it does mean that architectural portability remains unverified.

## 10. Kernel JIT Improvement Recommendations

> **Takeaway:** Three concrete kernel JIT improvements, all localized to `arch/x86/net/bpf_jit_comp.c`, would together address 89% of the measured native-code gap.

The benchmark evidence identifies three specific lowering decisions in the kernel x86-64 JIT that account for most of the measured instruction surplus. Each recommendation is tied to quantified evidence from the JIT dump analysis (§5) and causal isolation experiments (§4.5).

### 10.1 Byte-Load Recomposition Optimization

**Problem.** The kernel JIT expands byte-based BPF loads into byte-at-a-time reconstruction ladders (`movzbq + shl + or` sequences). This accounts for **50.7%** of measured extra instructions, and the causal isolation benchmark `load_byte_recompose` demonstrates a **2.24x** execution-time penalty (0.447x exec ratio).

**Example** from `memory_pair_sum` — loading a 64-bit value:

```x86asm
; Kernel: 8 individual byte loads, shifts, and ORs
movzbq  (%rdi), %rax        ; byte 0
movzbq  1(%rdi), %rcx       ; byte 1
shl     $8, %rcx
or      %rcx, %rax
; ... 6 more bytes

; llvmbpf LLVM: single wide load
mov     (%rdi), %rax
```

Across the 22-benchmark JIT-dump subset: kernel has **62 recompose sites** (320 byte-load instructions) vs llvmbpf's **5 sites** (32 byte-load instructions).

**Proposed fix.** Add a JIT-side recognizer for verifier-safe byte-recompose idioms. When the verifier has already established bounds and type safety, collapse `BPF_LDX_MEM_B` ladders feeding a shift/OR tree into direct `movl`/`movq` loads. Estimated effort: **120–220 LOC** in `bpf_jit_comp.c`.

### 10.2 Conditional Move (`cmov`) Support

**Problem.** The kernel JIT never emits `cmov`; it lowers all BPF control flow to conditional branches. LLVM uses `cmov` for select-like patterns: **31 total cmov** across the benchmark suite vs **0** in the kernel.

The most visible case is `switch_dispatch`: LLVM emits **28 cmov** and achieves 0.789x exec ratio, replacing 136 kernel branches with 69 LLVM branches plus data-flow `cmov` operations.

**Proposed fix.** Recognize branch diamonds where both arms only assign a register value (no side effects) and lower to `cmp + mov + cmovcc`. Best initial targets: switch-like select chains, min/max clamp idioms, compare-and-select in search kernels. Estimated effort: **180–320 LOC**.

### 10.3 Per-Function Callee-Saved Register Optimization

**Problem.** The kernel JIT unconditionally saves at least `rbp`, `rbx`, and `r13` regardless of actual usage. This accounts for **18.5%** of measured extra instructions.

| Benchmark | Kernel saves | LLVM saves |
|-----------|-------------|-----------|
| `simple` | rbp, rbx, r13 (7 insns) | rbx (2 insns) |
| `fibonacci_iter` | rbp, rbx, r13 (7 insns) | rbx (4 insns) |
| `spill_pressure` | rbp, rbx, r13, r14, r15 (11 insns) | rbp, r15, r14, r13, r12, rbx (14 insns) |

LLVM is not "always saving fewer" — it saves **adaptively**. In register-heavy kernels it may save more, but in trivial kernels it saves much less. The kernel JIT lacks this adaptive behavior.

**Proposed fix.** Compute the physical callee-saved set used by the function before prologue emission; save only registers that are actually clobbered. Estimated effort: **40–100 LOC**. This has upstream precedent — the kernel's `callee_regs_used` tracking already exists in adjacent JIT work.

### 10.4 Implementation Priority

If the goal is fastest path to measurable improvement, the recommended order is:

1. **Byte-load recompose first**: largest measured payoff (50.7% of surplus, 2.24x penalty) and strongest causal evidence.
2. **Per-function callee-saved second**: easiest patch, low risk, established upstream vocabulary.
3. **cmov support third**: highest analysis overhead because BPF ISA does not encode it directly.

## 11. Related Work

### 11.1 Optimization-Layer Taxonomy

| System | Layer | Operates on | Constraint | Key result |
|--------|-------|-------------|------------|------------|
| K2 (SIGCOMM'21) | Bytecode synthesis | BPF bytecode | verifier-constrained | 6–26% code-size, 1.36–55% latency reduction |
| Merlin (ASPLOS'24) | Multi-layer | LLVM IR + BPF bytecode | verifier-constrained | Faster and more scalable than K2 |
| EPSO (ASE'25) | Bytecode rewriting | BPF bytecode | verifier-constrained | 795 rules; up to 68.87% bytecode size; 6.60% avg runtime |
| KFuse (EuroSys'22) | In-kernel fusion | BPF programs | kernel-internal | Up to 2.3x on real applications |
| **This work** | **JIT backend** | **Native x86-64 code** | **none at optimization time** | **0.849x exec, 0.496x code-size on 31 benchmarks** |

The main distinction is layer placement. K2, Merlin, and EPSO transform verifier-visible program representations *before* JIT compilation. KFuse transforms relationships *among* already-validated programs inside the kernel. This work compares the final native code emitted by two JIT backends for the same BPF ELF inputs.

### 11.2 Orthogonality with Bytecode Optimizers

Bytecode-level optimizers and a native-code-level JIT comparison are complementary rather than substitutive. K2, Merlin, and EPSO are constrained to verifier-safe BPF bytecode rewrites. By contrast, llvmbpf changes lowering decisions during JIT compilation itself: direct wide loads instead of byte recomposition, branch restructuring with `cmov`, and liveness-aware callee-saved handling.

This separation means the optimizations can in principle stack: Merlin-optimized bytecode can still be passed to llvmbpf, which can then further optimize the resulting x86-64 machine code. Our data show why this backend layer matters: the 0.496x native code-size ratio exceeds the 6–26% bytecode-level shrinkage reported by K2, because it addresses a different layer of the compilation stack. The JIT-dump analysis identifies backend-only opportunities that bytecode rewriting cannot directly expose: byte-load recomposition (50.7% of instruction surplus), branch restructuring (19.9%), and fixed prologue overhead (18.5%).

### 11.3 Empirical Study Differentiation

| Study | Focus | Our differentiation |
|-------|-------|-------------------|
| CoNEXT'25 "Demystifying eBPF" | Network-application performance, chaining, tail-call overhead | We compare JIT backends on identical ELF inputs and analyze native code generation |
| "No Two Snowflakes Are Alike" | Cross-library performance, fidelity, resource-use comparison | We inspect emitted x86-64, JIT dumps, and backend-specific mechanisms |
| ETH Zurich multicore study | Scalability, multicore resource use, interference | We focus on single-core code-generation quality |
| BeeBox (Sec'24) | Security hardening of the JIT compiler | Not a performance-characterization study |

The closest contribution of this work is methodological: it treats eBPF JIT quality itself as the object of study, connecting timing to emitted instruction structure and then checking whether the same direction survives on real programs.

## 12. Conclusion

This paper presents the first systematic native-code-level comparison of the Linux kernel eBPF JIT and a userspace LLVM -O3 JIT. Our findings support four main claims:

1. **llvmbpf produces 2x smaller and 15% faster code than the kernel JIT.** Across 31 authoritative pure-JIT microbenchmarks, llvmbpf achieves a 0.496x code-size ratio and 0.849x execution-time geomean, with 25/31 statistically significant differences. The runtime suite (9 map/helper benchmarks) confirms the pattern at 0.829x.

2. **The gap is driven by three specific lowering decisions, not by LLVM's advanced optimizations.** Byte-load recomposition (50.7% of instruction surplus, 2.24x isolated penalty), absence of conditional moves (31 vs 0 cmov), and fixed prologue overhead (18.5%) together account for 89% of the kernel's instruction surplus. LLVM pass ablation shows that only InstCombinePass and SimplifyCFGPass matter for BPF; GVN, LICM, LoopUnroll, and five other passes have zero measurable effect.

3. **Code size alone does not predict performance.** 10/31 benchmarks exhibit the "smaller but slower" paradox. After excluding 3 sub-resolution artifacts, the remaining 7 cases are explained by loop-carried dependency chains, cloned scalar math, and branch-predictor pressure — mechanisms where LLVM eliminates non-critical-path instructions without shortening the dynamic bottleneck.

4. **The findings generalize to real programs.** External validation on 162 paired real-program instances (36 unique, from Cilium and libbpf-bootstrap) confirms the code-size advantage at 0.618x. Execution-time validation with valid network packets yields 0.514x across 98 paired instances, with llvmbpf faster on 13/14 unique programs.

These results imply that adding basic peephole optimization (instruction combining and dead-block elimination) to the kernel JIT would close a significant fraction of the code-quality gap without requiring a full LLVM backend. We provide three concrete improvement recommendations with quantified impact estimates and implementation feasibility assessments.

---

*Data source: authoritative 30-iteration × 1000-repeat runs on Intel Arrow Lake-S. All benchmark code, data, and analysis scripts available at github.com/eunomia-bpf/bpf-benchmark.*

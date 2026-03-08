# Paper Outline: Kernel vs LLVM JIT for eBPF — A Systematic Native-Code Comparison

## Target venue: OSDI/SOSP (systems, emphasis on actionable insights)

---

## Title options
1. "How Good Is the Kernel eBPF JIT? A Systematic Comparison with LLVM -O3"
2. "What a Full Compiler Could Do for eBPF: Measuring the Code-Quality Gap"
3. "Beyond Single-Pass: Quantifying the eBPF JIT Performance Gap with LLVM"

## 1. Introduction (~1.5 pages)

**Hook**: eBPF's kernel JIT is a single-pass, linear-scan compiler. Every BPF program in production — firewalls, load balancers, observability — runs through this compiler. But how much performance is left on the table?

**Gap**: No prior work has compared kernel JIT output to a full LLVM backend on identical BPF bytecode at the native-code level. Existing work (K2, Merlin, EPSO) optimizes bytecode *before* JIT, operating under verifier constraints. We measure the JIT backend itself.

**Contributions**:
1. First systematic native-code comparison: 0.849x exec, 0.496x code-size across 31 benchmarks
2. Root-cause analysis: byte-recompose (2.24x penalty), cmov absence, fixed prologue — accounting for 89% of instruction surplus
3. Pass ablation: only InstCombinePass and SimplifyCFGPass matter for BPF; other LLVM passes have zero effect
4. External validation on 162 real-world Cilium programs (0.514x exec-time, 0.618x code-size)
5. Three actionable kernel JIT improvements with quantified impact estimates

**Data source**: stage-log §1, §2

## 2. Background (~1 page)

- eBPF architecture: bytecode ISA, verifier, JIT compilation
- Kernel JIT: single-pass, linear-scan register allocation, direct translation
- llvmbpf: lifts BPF bytecode to LLVM IR, runs full -O3 pipeline, JIT compiles
- Why comparison is fair: identical BPF ELF input, same ISA semantics

**Data source**: stage-log §1, CLAUDE.md

## 3. Methodology (~2 pages)

### 3.1 Experimental Setup
- Platform: Intel Arrow Lake-S, 128GB DDR5, kernel 6.15.11
- Sampling: 30 iterations × 1000 repeats, counterbalanced runtime ordering
- Environment: taskset + performance governor, strict-env enforcement
- Timing: exec_ns (ktime for kernel, rdtsc for llvmbpf), explicit asymmetry discussion

### 3.2 Benchmark Suite
- 31 pure-JIT staged-codegen benchmarks across 8 categories
- 9 runtime (map/helper) benchmarks
- 1 BPF-to-BPF local call benchmark
- Input staging: deterministic LCG generators, map-backed I/O

### 3.3 Statistical Methods
- Paired Wilcoxon + BH correction, bootstrap CIs, Cohen's d
- Drift analysis, ACF checks

### 3.4 External Validation Corpus
- 162 paired programs from 4 repos (Cilium, libbpf-bootstrap, inspektor-gadget, collected)
- Valid Ethernet+IPv4+TCP packet for realistic exec-time

**Data source**: stage-log §2, §3

## 4. Results (~3 pages)

### 4.1 Execution Time
- Suite geomean: 0.849x [0.834, 0.865], 25/31 significant
- Per-category: control-flow 0.627x, memory-local 0.665x, loop-shape 0.764x; call-size 1.539x, baseline 1.361x
- **Figure 1**: Exec ratio bar chart (micro/results/figures/exec_ratio_bars.pdf)
- **Figure 3**: Category breakdown (category_breakdown.pdf)

### 4.2 Code Size
- Suite geomean: 0.496x, all 31 llvmbpf smaller
- Code-size is a weak runtime predictor: Pearson r=0.131 (p=0.48)
- **Figure 2**: Code-size ratio bars
- **Figure 5**: Size-vs-exec scatter with regression

### 4.3 Compile Time
- Suite geomean L/K: 3.394x (llvmbpf slower)
- 5/31 benchmarks where llvmbpf compiles faster
- Crossover estimate: ~756 BPF instructions
- **Figure 4**: Compile ratio bars

### 4.4 Runtime Mechanism Benchmarks
- Map/helper suite geomean: 0.829x, 7/9 significant
- Helper overhead consistent with pure-JIT findings

**Data source**: stage-log §4, performance_deep_analysis.md

## 5. Analysis (~3 pages)

### 5.1 Root Cause: JIT Dump Analysis
- Byte-recompose: 50.7% of extra instructions; causal isolation shows 0.447x (2.24x penalty)
- cmov: 31 vs 0 instances; switch_dispatch most affected
- Prologue/epilogue: 18.5% of extra instructions; fixed 3-register save vs adaptive
- **Figure 6**: Causal isolation comparison

### 5.2 "Smaller But Slower" Paradox
- 10/31 benchmarks where llvmbpf produces smaller but slower code
- Categories: 3 sub-resolution artifacts, 2 tight-loop, 3 code-clone, 2 branch-heavy
- Key insight: code-size reduction alone doesn't predict performance when throughput bottleneck is unchanged

### 5.3 LLVM Pass Ablation
- 9 passes × 11 benchmarks: only InstCombinePass and SimplifyCFGPass matter
- BPF programs too simple for GVN, LICM, LoopUnroll, DSE, etc.
- Implication: kernel JIT needs only peephole optimization + dead-block elimination to close most of the gap

### 5.4 External Validation
- Code-size: 0.618x geomean, 162 paired instances, 36 unique programs
- Exec-time: 0.514x geomean, 98 paired instances, 14 unique programs
- Programs span Cilium's full TC pipeline: cil_from_netdev, handle_policy, etc.

**Data source**: stage-log §5, §6, §7; kernel-jit-improvements.md; pass_ablation.md

## 6. Kernel JIT Improvement Recommendations (~1.5 pages)

### 6.1 Byte-Load Recomposition
- Problem: movzbq + shl + or sequences for wide loads
- Evidence: 2.24x exec penalty (causal isolation)
- Fix: pattern recognition for aligned multi-byte loads → single wide load
- Estimated impact: 15-25% exec improvement on memory-heavy programs

### 6.2 Conditional Move Support
- Problem: kernel never emits cmov
- Evidence: 31 cmov in llvmbpf vs 0 in kernel
- Fix: BPF_ALU conditional → cmov lowering
- Estimated impact: measurable on branch-heavy programs (switch_dispatch 0.789x)

### 6.3 Adaptive Callee-Saved Registers
- Problem: always saves rbp, rbx, r13 regardless of usage
- Evidence: 18.5% of instruction surplus
- Fix: per-function register analysis
- Estimated impact: reduced overhead for small/medium programs

**Data source**: kernel-jit-improvements.md

## 7. Related Work (~1 page)

- K2/Merlin/EPSO: bytecode-level, verifier-constrained → orthogonal to JIT backend
- KFuse: in-kernel fusion → complementary
- CoNEXT'25: application-level eBPF perf → we go deeper on codegen
- "No Two Snowflakes": cross-library comparison → we add native-code analysis

**Data source**: related-work-positioning.md, ebpf-bench-research-plan.md

## 8. Discussion & Threats to Validity (~1 page)

- Timing asymmetry: ktime vs rdtsc (bounded by repetition)
- Single platform: x86-64 only (structural JIT differences are ISA-independent)
- Benchmark representativeness: 0.8% feature-box coverage (micro-benchmarks for mechanism isolation, not corpus coverage)
- BPF_PROG_TEST_RUN limitations: no tracepoint/kprobe/perf_event hooks
- Short exec-time programs: most real-world validation still <100ns per execution

## 9. Conclusion (~0.5 pages)

Key claims:
1. llvmbpf LLVM -O3 JIT produces 2x smaller and 15% faster code than the kernel JIT
2. The gap is driven by three specific lowering decisions, not by LLVM's advanced optimizations
3. Adding basic peephole optimization to the kernel JIT would close most of the code-quality gap
4. These findings are validated on 162 production Cilium programs

---

## Figure Index
1. exec_ratio_bars.pdf — Execution-time ratio (31 benchmarks)
2. code_size_ratio_bars.pdf — Code-size ratio (31 benchmarks)
3. category_breakdown.pdf — Per-category exec & code-size
4. compile_ratio_bars.pdf — Compile-time ratio
5. size_vs_exec_scatter.pdf — Code-size vs exec-time scatter
6. causal_isolation.pdf — Byte-recompose causal isolation

## Table Index
1. Platform & sampling parameters
2. Benchmark suite inventory (31+9)
3. Per-benchmark exec ratio + significance + effect size
4. Pass ablation: code-size impact per pass
5. External validation: 14 unique programs exec-time
6. Kernel JIT improvement summary

## Data Availability
- All benchmark code, data, and analysis scripts at: github.com/eunomia-bpf/bpf-benchmark
- Authoritative JSON datasets for full reproducibility

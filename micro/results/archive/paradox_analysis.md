# Smaller-But-Slower Paradox Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- Significance source: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative_analysis.md`
- Programs dir: `/home/yunwei37/workspace/bpf-benchmark/micro/programs`
- JIT dumps dir: `/home/yunwei37/workspace/bpf-benchmark/micro/jit-dumps`
- Paradox definition: code-size ratio `L/K < 1.0` and exec ratio `L/K > 1.0`.
- Paradox cases found: `10 / 31` benchmarks total: `7` real paradox cases plus `3` sub-resolution measurement artifacts.
- Statistically significant paradox cases: `7 / 10` overall by BH-adjusted paired Wilcoxon p < 0.05; excluding sub-resolution artifacts leaves `5 / 7` significant real paradox cases.
- Helper counts include explicit `bpf_*()` calls in the benchmark source plus wrapper-implied map helpers from the `DEFINE_*_XDP_BENCH` macro used by the source.
- Categories are hypotheses driven by source structure plus any available `.asm` JIT dump signals.

## Paradox Benchmarks

| Benchmark | Exec Ratio (L/K) | Code Ratio (L/K) | Significant | Kernel exec ns | BPF insns | Loop | Helpers | Baseline | JIT hint | Category | Why |
| --- | ---: | ---: | --- | ---: | ---: | --- | --- | --- | --- | --- | --- |
| simple | 1.526 | 0.622 | Yes | 13.7 | 29 | no | 1 (wrapper) | yes | insns K/L 49/25; branches K/L 5/4 | sub-resolution | measurement artifact: kernel mean exec is 13.7ns, well below this platform's ~100ns `ktime_get_ns()` granularity, so quantized timer values swamp any real code-shape effect |
| simple_packet | 1.321 | 0.490 | No | 13.4 | 21 | no | 0 | yes | n/a | sub-resolution | measurement artifact: kernel mean exec is 13.4ns, well below this platform's ~100ns `ktime_get_ns()` granularity, so quantized timer values swamp any real code-shape effect |
| memory_pair_sum | 1.251 | 0.238 | Yes | 15.3 | 83 | no | 1 (wrapper) | yes | insns K/L 103/24; branches K/L 5/4 | sub-resolution | measurement artifact: kernel mean exec is 15.3ns, well below this platform's ~100ns `ktime_get_ns()` granularity, so quantized timer values swamp any real code-shape effect |
| bitcount | 1.556 | 0.446 | Yes | 2985.3 | 134 | yes (2) | 1 (wrapper) | no | insns K/L 163/61; branches K/L 12/13 | tight-loop | loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.446x code-size reduction mostly removes non-critical-path instructions |
| fixed_loop_large | 1.193 | 0.425 | Yes | 1251.1 | 115 | yes (1) | 1 (wrapper) | no | insns K/L 135/54; branches K/L 7/6 | tight-loop | loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.425x code-size reduction mostly removes non-critical-path instructions |
| log2_fold | 1.006 | 0.659 | No | 310.5 | 133 | yes (1) | 1 (wrapper) | no | insns K/L 166/104; branches K/L 19/8 | tight-loop | near-parity; loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.659x code-size reduction mostly removes non-critical-path instructions |
| code_clone_8 | 1.878 | 0.542 | Yes | 1207.0 | 189 | yes (2) | 1 (wrapper) | no | insns K/L 214/103; branches K/L 8/5 | code-clone | steady-state loop is mostly cloned straight-line scalar math, so LLVM shrinks bytes without shortening the per-iteration dependency chain |
| code_clone_2 | 1.260 | 0.492 | Yes | 324.8 | 118 | yes (2) | 1 (wrapper) | no | insns K/L 139/62; branches K/L 8/6 | code-clone | steady-state loop is mostly cloned straight-line scalar math, so LLVM shrinks bytes without shortening the per-iteration dependency chain |
| branch_dense | 1.409 | 0.732 | Yes | 445.9 | 181 | yes (1) | 1 (wrapper) | no | source: 8 loop-body `if`s/elt; dense BPF jumps lower directly to x86 `jcc` | branch-heavy | each element goes through 8 explicit loop-body `if` statements, so the hot path is branch-prediction-limited rather than code-size-limited; the kernel JIT's direct `jcc` lowering keeps that dense control flow on the critical path |
| bounds_check_heavy | 1.119 | 0.807 | No | 253.1 | 333 | yes (1) | 1 (wrapper) | no | source: 7 always-on + up to 2 selector-gated `if`s/record; repeated guards lower to x86 `jcc` | branch-heavy | each record evaluates 7 always-on bounds/selector branches plus up to 2 extra guarded checks, so repeated control-flow decisions dominate the critical path and LLVM's smaller code does not remove the predictor bottleneck |

## Category Summary

| Category | Count | Interpretation | Benchmarks |
| --- | ---: | --- | --- |
| sub-resolution | 3 | measurement artifact; exclude from substantive paradox analysis | simple, simple_packet, memory_pair_sum |
| tight-loop | 3 | real paradox | bitcount, fixed_loop_large, log2_fold |
| code-clone | 2 | real paradox | code_clone_8, code_clone_2 |
| branch-heavy | 2 | real paradox | branch_dense, bounds_check_heavy |
| effective real paradox count | 7 | excludes the 3 sub-resolution artifacts; 5 significant | bitcount, fixed_loop_large, log2_fold, code_clone_8, code_clone_2, branch_dense, bounds_check_heavy |

## Key Insight

After excluding the 3 sub-resolution measurement artifacts, `7 of 7` remaining paradox cases are real smaller-but-slower behaviors rather than timer noise. `5` of those `7` real cases are statistically significant; the non-significant real cases are `log2_fold` (near-parity at 1.006x) and `bounds_check_heavy` (a modest 1.119x gap with high variance).
The excluded cases (`simple`, `simple_packet`, `memory_pair_sum`) all finish below this platform's ~100ns `ktime_get_ns()` granularity, so their apparent paradox ratios are quantized timer values, not substantive performance differences.
LLVM's instruction elimination mainly reduces non-critical-path instructions. In the remaining real cases the runtime is set by loop-carried recurrences, cloned straight-line math, or dense control flow, so smaller code does not automatically mean a shorter critical path.

## Reading Notes

- `sub-resolution` marks measurement artifacts: kernel mean `exec_ns` is below this platform's ~100ns `ktime_get_ns()` granularity, so quantized timer values cannot resolve real performance differences and these cases should be excluded from substantive paradox analysis.
- `tight-loop` means a loop dominates steady-state execution; byte savings mostly happen outside the loop-carried dependency chain.
- `code-clone` means a repeated straight-line body is cloned inside the hot loop, where kernel's direct lowering stays competitive.
- `branch-heavy` means the hot loop carries many source-level conditionals per iteration: `branch_dense` has 8 loop-body `if` statements per element, while `bounds_check_heavy` has 7 always-on plus up to 2 selector-gated `if` statements per record. On this x86 host the kernel JIT lowers BPF conditional jumps directly to `jcc`, so branch-predictor pressure, not code size, dominates the critical path.
- Report output: `/home/yunwei37/workspace/bpf-benchmark/micro/results/paradox_analysis.md`

# Smaller-But-Slower Paradox Analysis

- Input JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative.json`
- Significance source: `/home/yunwei37/workspace/bpf-benchmark/micro/results/pure_jit_authoritative_analysis.md`
- Programs dir: `/home/yunwei37/workspace/bpf-benchmark/micro/programs`
- JIT dumps dir: `/home/yunwei37/workspace/bpf-benchmark/micro/jit-dumps`
- Paradox definition: code-size ratio `L/K < 1.0` and exec ratio `L/K > 1.0`.
- Paradox cases found: `10 / 31` benchmarks.
- Statistically significant paradox cases: `7 / 10` benchmarks by BH-adjusted paired Wilcoxon p < 0.05.
- Helper counts include explicit `bpf_*()` calls in the benchmark source plus wrapper-implied map helpers from the `DEFINE_*_XDP_BENCH` macro used by the source.
- Categories are hypotheses driven by source structure plus any available `.asm` JIT dump signals.

## Paradox Benchmarks

| Benchmark | Exec Ratio (L/K) | Code Ratio (L/K) | Significant | Kernel exec ns | BPF insns | Loop | Helpers | Baseline | JIT hint | Category | Why |
| --- | ---: | ---: | --- | ---: | ---: | --- | --- | --- | --- | --- | --- |
| simple | 1.526 | 0.622 | Yes | 13.7 | 29 | no | 1 (wrapper) | yes | insns K/L 49/25; branches K/L 5/4 | sub-resolution | kernel mean exec is 13.7ns, below the 100ns ktime floor, so timer quantization dominates any code-shape effect |
| simple_packet | 1.321 | 0.490 | No | 13.4 | 21 | no | 0 | yes | n/a | sub-resolution | kernel mean exec is 13.4ns, below the 100ns ktime floor, so timer quantization dominates any code-shape effect |
| memory_pair_sum | 1.251 | 0.238 | Yes | 15.3 | 83 | no | 1 (wrapper) | yes | insns K/L 103/24; branches K/L 5/4 | sub-resolution | kernel mean exec is 15.3ns, below the 100ns ktime floor, so timer quantization dominates any code-shape effect |
| bitcount | 1.556 | 0.446 | Yes | 2985.3 | 134 | yes (2) | 1 (wrapper) | no | insns K/L 163/61; branches K/L 12/13 | tight-loop | loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.446x code-size reduction mostly removes non-critical-path instructions |
| fixed_loop_large | 1.193 | 0.425 | Yes | 1251.1 | 115 | yes (1) | 1 (wrapper) | no | insns K/L 135/54; branches K/L 7/6 | tight-loop | loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.425x code-size reduction mostly removes non-critical-path instructions |
| log2_fold | 1.006 | 0.659 | No | 310.5 | 133 | yes (1) | 1 (wrapper) | no | insns K/L 166/104; branches K/L 19/8 | tight-loop | near-parity; loop-dominated work keeps cost on the loop-carried recurrence, so LLVM's 0.659x code-size reduction mostly removes non-critical-path instructions |
| code_clone_8 | 1.878 | 0.542 | Yes | 1207.0 | 189 | yes (2) | 1 (wrapper) | no | insns K/L 214/103; branches K/L 8/5 | code-clone | steady-state loop is mostly cloned straight-line scalar math, so LLVM shrinks bytes without shortening the per-iteration dependency chain |
| code_clone_2 | 1.260 | 0.492 | Yes | 324.8 | 118 | yes (2) | 1 (wrapper) | no | insns K/L 139/62; branches K/L 8/6 | code-clone | steady-state loop is mostly cloned straight-line scalar math, so LLVM shrinks bytes without shortening the per-iteration dependency chain |
| branch_dense | 1.409 | 0.732 | Yes | 445.9 | 181 | yes (1) | 1 (wrapper) | no | n/a | branch-heavy | hot path is branch-dense (11 ifs), so the control-flow shape matters more than static byte count and kernel's direct branch lowering can win |
| bounds_check_heavy | 1.119 | 0.807 | No | 253.1 | 333 | yes (1) | 1 (wrapper) | no | n/a | branch-heavy | hot path is branch-dense (12 ifs), so the control-flow shape matters more than static byte count and kernel's direct branch lowering can win |

## Category Summary

| Category | Count | Benchmarks |
| --- | ---: | --- |
| sub-resolution | 3 | simple, simple_packet, memory_pair_sum |
| tight-loop | 3 | bitcount, fixed_loop_large, log2_fold |
| code-clone | 2 | code_clone_8, code_clone_2 |
| branch-heavy | 2 | branch_dense, bounds_check_heavy |

## Key Insight

7 of 10 paradox cases are statistically significant, strengthening the claim that "smaller but slower" is a real phenomenon rather than noise.
The non-significant paradox cases are weak edge cases: `simple_packet` is sub-resolution, `log2_fold` is near-parity (1.006x), and `bounds_check_heavy` is non-significant despite a modest 1.119x gap.
LLVM's instruction elimination mainly reduces non-critical-path instructions. In these cases the runtime is set by timer noise, loop-carried recurrences, cloned straight-line math, or dense control flow, so smaller code does not automatically mean a shorter critical path.

## Reading Notes

- `sub-resolution` means the kernel mean `exec_ns` is below `100ns`, so the ratio is dominated by `ktime` granularity.
- `tight-loop` means a loop dominates steady-state execution; byte savings mostly happen outside the loop-carried dependency chain.
- `code-clone` means a repeated straight-line body is cloned inside the hot loop, where kernel's direct lowering stays competitive.
- `branch-heavy` means control-flow density or verifier-style guards dominate behavior, so branch layout matters more than raw bytes.
- Report output: `/home/yunwei37/workspace/bpf-benchmark/micro/results/paradox_analysis.md`

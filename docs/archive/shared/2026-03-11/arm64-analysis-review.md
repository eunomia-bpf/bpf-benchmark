# ARM64 Cross-Architecture Analysis Review

Line numbers below refer to `docs/tmp/arm64-cross-arch-analysis.md` unless another file is named explicitly. I also checked `micro/results/runtime_with_map_lookup_repeat.json`, because the analysis itself names that x86 runtime file as an input at line 3.

## Executive Findings

- The arithmetic is sound. I recomputed all 61 rows from the raw JSON medians and found no transcription errors in the summary table, suite geomeans, or flip counts.
- Using `L/K = llvmbpf / kernel` is the right first normalization for cross-arch comparison of the pure-JIT suite, but several later sentences over-interpret that ratio as direct evidence of "kernel JIT quality."
- The main completeness problem is provenance. The ARM64 JSONs were generated from `git_sha=d8edc80...` on `Linux-6.14.0-1017-azure` (`micro/results/arm64_pure_jit.json:10-11`, `micro/results/arm64_runtime.json:10-11`), while the x86 JSONs were generated from `git_sha=5ae9684...` on `Linux-6.15.11-061511-generic` (`micro/results/pure_jit_with_cmov.json:10-11`, `micro/results/runtime_with_map_lookup_repeat.json:10-11`).
- The x86 provenance metadata is not just different, but internally inconsistent: the x86 pure-JIT JSON contains `cmov_select`, yet `git show 5ae9684f179a7192b58ee6e0326746991f777ab7:micro/programs/cmov_select.bpf.c` fails; the x86 runtime JSON contains `map_lookup_repeat`, but `git show 5ae9684f179a7192b58ee6e0326746991f777ab7:config/micro_runtime.yaml | rg -n 'map_lookup_repeat'` finds nothing. That must be resolved before publication.

## 1. Data Accuracy

The numerical content is accurate as written.

- The suite summaries at lines 13-15 and 29 reproduce from the raw medians: ARM64 pure-JIT geomean `0.655522 -> 0.656`, ARM64 runtime `1.076327 -> 1.076`, ARM64 overall `0.716840 -> 0.717`; x86 pure-JIT `0.797305 -> 0.797`, x86 runtime `0.874602 -> 0.875`, x86 overall `0.810721 -> 0.811`.
- The win/loss counts also reproduce: ARM64 pure-JIT `44/50`, ARM64 runtime `3/11`, ARM64 overall `47/61`.
- The direction-flip count at lines 21-23 is correct: `18` total, `15` pure-JIT and `3` runtime.
- The one-to-one benchmark matching claim at line 7 is also correct, once the x86 runtime file named at line 3 is included.

Spot-checks against the ARM64 raw JSON:

| Benchmark | Suite | ARM64 llvmbpf median (ns) | ARM64 kernel median (ns) | Computed `L/K` | Cited lines |
| --- | --- | ---: | ---: | ---: | --- |
| `simple` | pure-JIT | `40` | `12` | `3.333` | 25, 79 |
| `bitcount` | pure-JIT | `5012` | `9205` | `0.544` | 21, 82 |
| `switch_dispatch` | pure-JIT | `416` | `320` | `1.300` | 23, 88 |
| `cmov_select` | pure-JIT | `587` | `1703` | `0.345` | 47-53, 90 |
| `load_byte_recompose` | pure-JIT | `126` | `359` | `0.351` | 24, 66, 94 |
| `struct_field_cluster` | pure-JIT | `102` | `107` | `0.953` | 24, 42, 61, 71, 127 |
| `map_roundtrip` | runtime | `809` | `640` | `1.264` | 22, 43, 61, 130 |
| `helper_call_100` | runtime | `3482` | `3193` | `1.091` | 22, 43, 136 |
| `atomic_counter_xadd` | runtime | `268` | `260` | `1.031` | 22, 43, 61, 139 |

I did not find any arithmetic error that needs correction.

## 2. Cross-Arch Methodology

Line 5 is directionally right: comparing `L/K` instead of raw nanoseconds is the least-bad way to compare architectures when the hosts are not matched. For the pure-JIT suite, it is a reasonable first-order summary.

The pitfalls are:

- The comparison is not "architecture only." The datasets differ by repo SHA, kernel version, host environment, and run protocol: ARM64 uses `iterations=5`, `warmups=1`, `repeat=200` (`micro/results/arm64_pure_jit.json:32-39`, `micro/results/arm64_runtime.json:32-39`), while x86 uses `iterations=10`, `warmups=2`, `repeat=500` (`micro/results/pure_jit_with_cmov.json:32-39`, `micro/results/runtime_with_map_lookup_repeat.json:32-39`).
- `L/K` collapses two moving parts. A higher ARM64 ratio can mean a stronger ARM64 kernel JIT, a weaker ARM64 llvmbpf, or both. Line 75 overstates this when it defines positive `LK_diff` as "the ARM64 kernel JIT is relatively stronger." Mathematically, it only means `arm64_LK > x86_LK`.
- Runtime/helper cases are not clean backend-quality measurements. `micro_runtime` uses user-space helper shims for llvmbpf and kernel helper implementations for eBPF; for example llvmbpf helper ID `5` is wired to `std::chrono::steady_clock::now()` in [micro/runner/src/llvmbpf_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/llvmbpf_runner.cpp#L394), and kernel `exec_ns` comes from `test_opts.duration` in [micro/runner/src/kernel_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/kernel_runner.cpp#L453).
- Near-parity ratios should not carry strong architecture claims with only five ARM64 iterations. `struct_field_cluster = 0.953` (line 127), `atomic_counter_xadd = 1.031` (line 139), and `helper_call_10 = 1.008` (line 135) need uncertainty intervals.
- Floor-bound kernel timings still matter even though line 25 flags some tiny cases. The repo itself defines `KERNEL_EXEC_SUBRESOLUTION_NS = 100.0` in [micro/archive/scripts/analyze_statistics.py](/home/yunwei37/workspace/bpf-benchmark/micro/archive/scripts/analyze_statistics.py), so any benchmark with kernel median below `100ns` should be treated cautiously.

Recommendation: keep `L/K` as the main cross-arch summary for pure-JIT kernels, but do not use it by itself to claim causal backend superiority.

## 3. `cmov_select` Interpretation

The values at lines 49-53 are correct:

- ARM64: `llvmbpf = 587ns`, `kernel = 1703ns`, `L/K = 0.345`.
- x86: `llvmbpf = 147.5ns`, `kernel = 815ns`, `L/K = 0.181`.

The interpretation should be narrower than the document currently makes it.

- The safe claim is that `cmov_select` is a real LLVM win on both architectures, and the win is larger on x86 than on ARM64.
- The unsafe claim is that the smaller ARM64 ratio shows the ARM64 kernel is specifically "better at `csel`." The ratio alone cannot distinguish "better ARM64 kernel lowering" from "weaker ARM64 llvmbpf lowering."
- The pure-JIT baseline-adjusted ratio points the same way: `runtime_comparison.llvmbpf_over_kernel_adjusted_exec_ratio` is `0.323` on ARM64 and `0.149` on x86. So even after subtracting each runtime's own `simple` floor, x86 still shows the larger llvmbpf advantage.
- The absolute medians are still useful as diagnostics, but because line 5 already says cross-machine ns are not directly comparable, they do not support a causal statement by themselves.

My conclusion on lines 49-53: keep "cross-arch LLVM win with architecture-dependent magnitude," but remove any implication that this already identifies the ARM64 kernel JIT as better at `csel`. That needs emitted-code evidence.

## 4. Architecture-Specific Insights

What is supported:

- Lines 58-60 are source-backed. Both backends already perform conditional callee-saved preservation: x86 via [vendor/linux/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L355), [vendor/linux/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1504), and [vendor/linux/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1680); ARM64 via [vendor/linux/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L374), [vendor/linux/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L426), [vendor/linux/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L458), [vendor/linux/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L565), and [vendor/linux/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L1042).
- Pure-JIT observations such as `load_byte_recompose` staying a strong llvmbpf win and `load_native_u64` / `struct_field_cluster` moving closer to parity on ARM64 are supported by the medians cited at lines 24, 61, 66, and 71.
- Line 62 is directionally consistent with the local source tree: I found no `csel`/`csinc`/`csinv`/`csneg` lowering in the local ARM64 BPF JIT, while x86 has a specialized `cmove` site in [vendor/linux/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1782).

What is too strong:

- Lines 31-43 and 61 use runtime/helper flips as if they were backend-quality evidence. They are runtime-stack results, not pure JIT measurements.
- Line 61 should not say "ARM64's kernel JIT looks stronger than x86" on `map_roundtrip`, `atomic_counter_xadd`, or `helper_call_100`. The defensible phrasing is "ARM64's kernel runtime stack is relatively more favorable against llvmbpf on these workloads."
- Line 62 goes a step too far when it says the select pattern is "still largely unrecovered by the stock JITs." Absence of a generic lowering hook plus one microbenchmark is suggestive, but not enough without disassembly.
- Line 75 has the same overreach as line 61: `LK_diff` is a ratio-difference summary, not a direct measure of kernel-only quality.

## 5. Timing Source

Yes, the timing-source split affects comparability.

- On llvmbpf, x86 uses `rdtsc` when available and ARM64 falls back to `clock_gettime(CLOCK_MONOTONIC)` in [micro/runner/src/llvmbpf_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/llvmbpf_runner.cpp#L32), [micro/runner/src/llvmbpf_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/llvmbpf_runner.cpp#L63), and [micro/runner/src/llvmbpf_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/llvmbpf_runner.cpp#L697).
- On kernel eBPF, `exec_ns` is always `test_opts.duration` and is labeled `ktime` in [micro/runner/src/kernel_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/kernel_runner.cpp#L453).
- That means every `L/K` ratio is already a cross-runtime comparison between different timers, even before any cross-architecture interpretation.

On resolution:

- The artifacts do not record `clock_getres(CLOCK_MONOTONIC)`, and there is no `clock_getres` call under `micro/`, so the effective ARM64 monotonic-clock resolution is not recoverable from the supplied artifacts.
- The only explicit in-repo threshold is the project heuristic `KERNEL_EXEC_SUBRESOLUTION_NS = 100.0` in [micro/archive/scripts/analyze_statistics.py](/home/yunwei37/workspace/bpf-benchmark/micro/archive/scripts/analyze_statistics.py). That is a caution threshold, not a measured clock resolution for the ARM64 VM.
- Practically, this means mid-size kernels like `bitcount`, `cmov_select`, or `helper_call_100` are usable, while tiny kernels and sub-`100ns` kernel medians need explicit caveats.

## 6. JIT Advisor Implications

Some recommendations are well-founded:

- Line 66 on `wide_load` is supported. `load_byte_recompose` is a strong llvmbpf win on both architectures.
- The broader idea in line 67 that some source-shape families can be discovered at verifier level and deferred to backend policy is reasonable.
- Line 69 is directionally sensible: `cmov_select` looks more like an architecture-specific backend decision than a universal verifier rewrite.

Some recommendations are ahead of the evidence:

- Lines 67-68 lean too hard on packet/ctx examples whose evidence is mixed. The document itself admits this at line 68, but the takeaway should be more conservative.
- Runtime/helper cases should not be driving backend directives. They can motivate workload coverage, but not kernel-vs-LLVM codegen claims.
- Line 71's `ldp`/`stp` shaping idea is a reasonable hypothesis, but nothing in the current artifact set directly ties the observed ARM64 medians to pair-load/store formation.

My recommendation here is: keep the cross-arch advisor conclusions tied to the pure-JIT suite, and present the runtime suite as complementary workload evidence rather than backend-quality proof.

## 7. Missing Before Citing This in a Paper

The document needs the following before it is paper-ready:

1. Resolve provenance first. Re-run ARM64 and x86 from the same repo SHA and disclose the exact kernel trees used. The current ARM64/x86 metadata disagree, and the x86 metadata appear internally inconsistent with the benchmark contents.
2. Add uncertainty estimates. At minimum: bootstrap confidence intervals for each `L/K`, plus paired significance testing or a stability appendix for ARM64.
3. State an explicit sub-resolution policy. Do not just warn about `simple`, `simple_packet`, and `memory_pair_sum` at line 25; apply the same rule to every sub-`100ns` kernel median.
4. Record timer properties. Add `clock_getres(CLOCK_MONOTONIC)` for ARM64 and document the timer used for each runtime in the paper text.
5. Match run protocol and host controls. Right now the datasets differ in `iterations`, `warmups`, `repeat`, kernel version, and host power-state metadata.
6. Add emitted-code evidence for headline claims. `cmov_select`, `switch_dispatch`, `load_byte_recompose`, `load_native_u64`, and `struct_field_cluster` need disassembly or instruction-count support before you can claim anything stronger than "ratio pattern observed."
7. Separate pure-JIT and runtime claims more cleanly. Backend-quality claims should come from pure-JIT kernels; runtime/helper benchmarks should be labeled as end-to-end runtime-stack behavior.

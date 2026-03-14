# VM vs Host Detailed Analysis

## Inputs and Method

- VM file: `tmp/vm_authoritative.json`
- Host authoritative file: `micro/results/pure_jit_authoritative.json`
- VM run metadata: kernel `7.0.0-rc2-gc23719abc330`, runtime `kernel` only, generated `2026-03-08T06:12:04.735376+00:00`, `10` iterations x `500` repeat
- Host run metadata: kernel `6.15.11-061511-generic`, runtimes `llvmbpf` + `kernel`, generated `2026-03-07T03:30:21.761128+00:00`, `30` iterations x `1000` repeat
- Overlap: `31` benchmarks
- Metric used here: per-benchmark `exec_ns.median` from each JSON result
- Host `L/K` ratio = `host llvmbpf median / host kernel median`; values below `1.0x` mean llvmbpf is faster, above `1.0x` mean kernel is faster
- Estimated VM `L/K` ratio = `host llvmbpf median / VM kernel median`; this treats host llvmbpf as a proxy for VM llvmbpf
- Because llvmbpf is held constant in the estimate, `estimated VM L/K = host L/K * (host kernel / VM kernel)`; the ratio shift is exactly the kernel 6.15 -> 7.0 speedup factor

## Executive Summary

- Across all `31` overlaps, kernel median geomean speedup from host `6.15.11` to VM `7.0-rc2` is `1.135x`.
- Excluding the known sub-resolution baselines (`simple`, `simple_packet`, `memory_pair_sum`), the kernel geomean speedup is `1.105x`.
- `23/31` benchmarks improved on the VM kernel, `8/31` regressed, and `7/31` stayed within +/-5%.
- Host authoritative geomean `L/K` is `0.811x`; estimated VM geomean `L/K` is `0.920x`. Under the llvmbpf-proxy assumption, `7.0-rc2` shifts the suite `1.135x` toward kernel.
- Host kernel is faster than llvmbpf on `8/31` benchmarks; estimated VM kernel would be faster on `14/31`.
- The largest raw improvements are dominated by two timer-floor baselines (`simple_packet`, `memory_pair_sum`); the largest substantive improvements are `multi_acc_8`, `bounds_check_heavy`, `spill_pressure`, `stride_load_16`, and `fixed_loop_small`.

### Category-Level View

| Category | Count | Kernel 6.15 -> 7.0 speedup geomean | Host L/K geomean | Estimated VM L/K geomean |
| --- | ---: | ---: | ---: | ---: |
| `alu-mix` | 3 | 1.102x | 1.007x | 1.109x |
| `baseline` | 3 | 1.464x | 1.101x | 1.611x |
| `call-size` | 2 | 0.972x | 1.567x | 1.523x |
| `control-flow` | 4 | 0.999x | 0.618x | 0.617x |
| `dependency-ilp` | 5 | 1.144x | 0.911x | 1.042x |
| `loop-shape` | 6 | 1.175x | 0.737x | 0.866x |
| `memory-local` | 6 | 1.117x | 0.622x | 0.694x |
| `program-scale` | 2 | 1.137x | 0.725x | 0.825x |

## Full 31-Benchmark Table

| Benchmark | Category | Host kernel median (ns) | Host llvmbpf median (ns) | Host L/K | VM kernel median (ns) | Estimated VM L/K | Kernel 6.15 -> 7.0 speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `binary_search` | `control-flow` | 454.0 | 204.5 | 0.450x | 475.5 | 0.430x | 0.955x |
| `bitcount` | `alu-mix` | 3035.5 | 4621.5 | 1.522x | 2990.5 | 1.545x | 1.015x |
| `bounds_check_heavy` | `memory-local` | 258.0 | 249.5 | 0.967x | 190.0 | 1.313x | 1.358x |
| `bounds_ladder` | `memory-local` | 202.0 | 81.0 | 0.401x | 217.5 | 0.372x | 0.929x |
| `branch_dense` | `control-flow` | 427.5 | 620.0 | 1.450x | 433.5 | 1.430x | 0.986x |
| `branch_layout` | `control-flow` | 530.0 | 155.5 | 0.293x | 539.0 | 0.288x | 0.983x |
| `checksum` | `memory-local` | 12055.5 | 10820.0 | 0.898x | 11939.0 | 0.906x | 1.010x |
| `code_clone_2` | `call-size` | 303.5 | 390.5 | 1.287x | 369.0 | 1.058x | 0.822x |
| `code_clone_8` | `call-size` | 1184.5 | 2261.5 | 1.909x | 1032.0 | 2.191x | 1.148x |
| `dep_chain_long` | `dependency-ilp` | 412.0 | 411.0 | 0.998x | 366.5 | 1.121x | 1.124x |
| `dep_chain_short` | `dependency-ilp` | 149.0 | 116.5 | 0.782x | 152.5 | 0.764x | 0.977x |
| `fibonacci_iter` | `loop-shape` | 723.5 | 577.0 | 0.798x | 686.0 | 0.841x | 1.055x |
| `fibonacci_iter_packet` | `loop-shape` | 745.5 | 590.0 | 0.791x | 614.0 | 0.961x | 1.214x |
| `fixed_loop_large` | `loop-shape` | 1255.0 | 1503.5 | 1.198x | 1045.5 | 1.438x | 1.200x |
| `fixed_loop_small` | `loop-shape` | 142.0 | 94.0 | 0.662x | 111.5 | 0.843x | 1.274x |
| `large_mixed_1000` | `program-scale` | 987.5 | 737.0 | 0.746x | 839.5 | 0.878x | 1.176x |
| `large_mixed_500` | `program-scale` | 496.5 | 350.0 | 0.705x | 451.5 | 0.775x | 1.100x |
| `log2_fold` | `alu-mix` | 320.0 | 303.5 | 0.948x | 271.0 | 1.120x | 1.181x |
| `memory_pair_sum` | `baseline` | 17.5 | 17.0 | 0.971x | 13.0 | 1.308x | 1.346x |
| `mixed_alu_mem` | `alu-mix` | 676.5 | 478.0 | 0.707x | 606.5 | 0.788x | 1.115x |
| `multi_acc_4` | `dependency-ilp` | 260.0 | 263.5 | 1.013x | 287.5 | 0.917x | 0.904x |
| `multi_acc_8` | `dependency-ilp` | 470.5 | 426.0 | 0.905x | 307.5 | 1.385x | 1.530x |
| `nested_loop_2` | `loop-shape` | 515.0 | 420.5 | 0.817x | 439.5 | 0.957x | 1.172x |
| `nested_loop_3` | `loop-shape` | 669.0 | 262.5 | 0.392x | 584.5 | 0.449x | 1.145x |
| `packet_parse` | `memory-local` | 86.5 | 90.0 | 1.040x | 79.0 | 1.139x | 1.095x |
| `simple` | `baseline` | 12.0 | 17.5 | 1.458x | 12.5 | 1.400x | 0.960x |
| `simple_packet` | `baseline` | 17.0 | 16.0 | 0.941x | 7.0 | 2.286x | 2.429x |
| `spill_pressure` | `dependency-ilp` | 284.5 | 249.5 | 0.877x | 221.0 | 1.129x | 1.287x |
| `stride_load_16` | `memory-local` | 254.5 | 97.5 | 0.383x | 198.0 | 0.492x | 1.285x |
| `stride_load_4` | `memory-local` | 238.0 | 99.0 | 0.416x | 220.0 | 0.450x | 1.082x |
| `switch_dispatch` | `control-flow` | 271.5 | 206.5 | 0.761x | 252.5 | 0.818x | 1.075x |

## Largest Kernel Improvements

### Top 10 By Relative Speedup (includes timer-floor cases)

| Benchmark | Category | Host kernel (ns) | VM kernel (ns) | Speedup | Host L/K | Estimated VM L/K | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple_packet` | `baseline` | 17.0 | 7.0 | 2.429x | 0.941x | 2.286x | timer-floor artifact |
| `multi_acc_8` | `dependency-ilp` | 470.5 | 307.5 | 1.530x | 0.905x | 1.385x | substantive |
| `bounds_check_heavy` | `memory-local` | 258.0 | 190.0 | 1.358x | 0.967x | 1.313x | substantive |
| `memory_pair_sum` | `baseline` | 17.5 | 13.0 | 1.346x | 0.971x | 1.308x | timer-floor artifact |
| `spill_pressure` | `dependency-ilp` | 284.5 | 221.0 | 1.287x | 0.877x | 1.129x | substantive |
| `stride_load_16` | `memory-local` | 254.5 | 198.0 | 1.285x | 0.383x | 0.492x | substantive |
| `fixed_loop_small` | `loop-shape` | 142.0 | 111.5 | 1.274x | 0.662x | 0.843x | substantive |
| `fibonacci_iter_packet` | `loop-shape` | 745.5 | 614.0 | 1.214x | 0.791x | 0.961x | substantive |
| `fixed_loop_large` | `loop-shape` | 1255.0 | 1045.5 | 1.200x | 1.198x | 1.438x | substantive |
| `log2_fold` | `alu-mix` | 320.0 | 271.0 | 1.181x | 0.948x | 1.120x | substantive |

### Top 10 Substantive Improvements (excluding sub-resolution baselines)

| Benchmark | Category | Host kernel (ns) | VM kernel (ns) | Speedup | Host L/K | Estimated VM L/K |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| `multi_acc_8` | `dependency-ilp` | 470.5 | 307.5 | 1.530x | 0.905x | 1.385x |
| `bounds_check_heavy` | `memory-local` | 258.0 | 190.0 | 1.358x | 0.967x | 1.313x |
| `spill_pressure` | `dependency-ilp` | 284.5 | 221.0 | 1.287x | 0.877x | 1.129x |
| `stride_load_16` | `memory-local` | 254.5 | 198.0 | 1.285x | 0.383x | 0.492x |
| `fixed_loop_small` | `loop-shape` | 142.0 | 111.5 | 1.274x | 0.662x | 0.843x |
| `fibonacci_iter_packet` | `loop-shape` | 745.5 | 614.0 | 1.214x | 0.791x | 0.961x |
| `fixed_loop_large` | `loop-shape` | 1255.0 | 1045.5 | 1.200x | 1.198x | 1.438x |
| `log2_fold` | `alu-mix` | 320.0 | 271.0 | 1.181x | 0.948x | 1.120x |
| `large_mixed_1000` | `program-scale` | 987.5 | 839.5 | 1.176x | 0.746x | 0.878x |
| `nested_loop_2` | `loop-shape` | 515.0 | 439.5 | 1.172x | 0.817x | 0.957x |

## Correlation With Prior Optimization Analysis

### 1. Callee-saved-heavy candidates: `simple`, `fibonacci_iter`, `binary_search`

Prior analysis already identified fixed prologue / callee-saved traffic as a real kernel overhead source, and `docs/paper.md` section 5.4 lists these exact benchmarks in the prologue comparison (`simple`: kernel saves `rbp, rbx, r13` vs LLVM `rbx`; `binary_search`: kernel saves `rbp, rbx, r13, r14, r15` vs LLVM `r15, r14, rbx`; `fibonacci_iter`: kernel saves `rbp, rbx, r13` vs LLVM `rbx`). `docs/kernel-jit-optimization-plan.md` also states that per-function callee-saved optimization is already upstream in `7.0-rc2`.

| Benchmark | Host kernel (ns) | VM kernel (ns) | Kernel speedup | Host L/K | Estimated VM L/K | Interpretation |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | 12.0 | 12.5 | 0.960x | 1.458x | 1.400x | Slight regression, but still a timer-floor benchmark; not reliable evidence. |
| `fibonacci_iter` | 723.5 | 686.0 | 1.055x | 0.798x | 0.841x | Modest improvement only; recurrence-critical path still dominates. |
| `binary_search` | 454.0 | 475.5 | 0.955x | 0.450x | 0.430x | No improvement; branch-heavy search remains dominated by control-flow/layout effects. |

Group geomean speedup for these three is `0.989x`. That is not a strong systematic win. The data therefore do **not** support the claim that these three callee-saved-heavy exemplars improved the most from `6.15` to `7.0-rc2`. At most, the evidence is mixed: `fibonacci_iter` improves slightly, `binary_search` regresses slightly, and `simple` remains below timer resolution.

### 2. Byte-recompose-heavy / memory-local cases: `memory_pair_sum`, `stride_load_4`, `stride_load_16`

Prior analysis says byte-load recomposition remains the largest kernel gap: `50.7%` of instruction surplus in `docs/micro-bench-status.md`, with isolated runtime penalty quantified at `0.447x` for `load_byte_recompose` in `micro/results/causal_isolation_analysis.md`. The optimization plan explicitly says byte-recompose optimization is **not** yet implemented in `7.0-rc2`, so any VM-side improvement here should be treated as indirect rather than as evidence that the pattern disappeared.

| Benchmark | Host kernel (ns) | VM kernel (ns) | Kernel speedup | Host L/K | Estimated VM L/K | Interpretation |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `memory_pair_sum` | 17.5 | 13.0 | 1.346x | 0.971x | 1.308x | Apparent gain, but still below timer resolution; cannot treat as substantive byte-recompose evidence. |
| `stride_load_4` | 238.0 | 220.0 | 1.082x | 0.416x | 0.450x | Improves modestly, but llvmbpf proxy still remains clearly faster. |
| `stride_load_16` | 254.5 | 198.0 | 1.285x | 0.383x | 0.492x | Improves materially, but llvmbpf proxy still remains clearly faster. |

For all three together, the speedup geomean is `1.232x`, but that is inflated by the timer-floor `memory_pair_sum` case. Looking only at the two stride benchmarks, the speedup geomean is `1.179x`. So the byte-recompose-heavy cases do **not** simply stay flat; they improve somewhat, especially `stride_load_16`. However, they still do not close the original llvmbpf gap: host `L/K` is `0.416x` / `0.383x` on `stride_load_4` / `stride_load_16`, and the estimated VM `L/K` is still only `0.450x` / `0.492x`. In other words, `7.0-rc2` narrows the gap but still leaves llvmbpf roughly `2.0x`-`2.2x` faster on these memory-local kernels under the proxy assumption.

### 3. What Actually Improved Most

Excluding the timer-floor baselines, the strongest gains are not the user-specified callee-saved trio. They cluster more in dependency/register-pressure, loop-shape, and a few memory-local kernels:

- `multi_acc_8`: 470.5 -> 307.5 ns (`1.530x`), category `dependency-ilp`
- `bounds_check_heavy`: 258.0 -> 190.0 ns (`1.358x`), category `memory-local`
- `spill_pressure`: 284.5 -> 221.0 ns (`1.287x`), category `dependency-ilp`
- `stride_load_16`: 254.5 -> 198.0 ns (`1.285x`), category `memory-local`
- `fixed_loop_small`: 142.0 -> 111.5 ns (`1.274x`), category `loop-shape`
- `fibonacci_iter_packet`: 745.5 -> 614.0 ns (`1.214x`), category `loop-shape`
- `fixed_loop_large`: 1255.0 -> 1045.5 ns (`1.200x`), category `loop-shape`
- `log2_fold`: 320.0 -> 271.0 ns (`1.181x`), category `alu-mix`

That pattern is consistent with a kernel that got generally better in several places, but without a single clean signature that maps only to the old prologue/callee-saved hypothesis. Control-flow benchmarks as a group stay essentially flat (`0.999x` speedup geomean), which also matches the prior analysis that `cmov` / branch-layout improvements are still missing.

## Conclusions

1. `7.0-rc2` kernel medians are materially better than host `6.15.11` overall: `1.135x` geomean across all 31 overlaps, or `1.105x` once the known timer-floor baselines are excluded.
2. Using host llvmbpf medians as a proxy, the suite-level `L/K` geomean shifts from `0.811x` to `0.920x`, and the number of benchmarks where kernel is estimated to beat llvmbpf rises from `8` to `14`.
3. The data do **not** show a clean “callee-saved-heavy benchmarks improve the most” pattern for `simple`, `fibonacci_iter`, and `binary_search`; those three are mixed and collectively near parity (`0.989x` speedup geomean).
4. The data also do **not** support “byte-recompose-heavy benchmarks stay the same.” `stride_load_4` and especially `stride_load_16` improve, but they still remain clearly llvmbpf-favorable under the proxy estimate, which is consistent with byte-recompose still being an open kernel gap.
5. The best reading is: `7.0-rc2` narrows the kernel deficit substantially, likely helped by the upstreamed per-function callee-saved optimization, but it does not eliminate the previously identified branch-layout/cmov and byte-recompose disadvantages.

## References Used

- `micro/results/pure_jit_authoritative.json`
- `tmp/vm_authoritative.json`
- `docs/micro-bench-status.md`
- `docs/paper.md`
- `docs/kernel-jit-optimization-plan.md`
- `micro/results/causal_isolation_analysis.md`

# Corpus Performance Debug - 2026-04-28

- Input: `corpus/results/x86_kvm_corpus_20260428_004223_284452/details/result.json`
- Generated at: `2026-04-28T00:53:56.514516+00:00`
- Top-level status: `error`
- Active per-program rows: 178
- Reported summary: geomean 1.043857, wins 77, losses 101

Definitions used here:

- `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; values above 1.0 are slower after ReJIT.
- `min_run_cnt = min(baseline_run_cnt_delta, post_rejit_run_cnt_delta)`.
- `run_cnt_cv = abs(baseline_run_cnt_delta - post_rejit_run_cnt_delta) / (baseline_run_cnt_delta + post_rejit_run_cnt_delta)`, the population coefficient of variation for the two phase counts. The relative difference from the phase mean is `2 * run_cnt_cv`.
- `sub100ns` means either baseline or post-ReJIT average is below 100 ns/run.
- `app_changed` is the app-level `rejit_result.changed`. The artifact strips successful per-program ReJIT records, so exact per-program changed/unchanged attribution is not available from this result. `bytes_jited_delta` is included only as a size-change signal; same-size code can still be changed.

## Key Findings

1. Significant regressions are highly concentrated: tracee has 30/52, tetragon has 21/52, and bpftrace/vfsstat has 1/52. No other app has a significant regression.
2. Run-count mismatch is the strongest explanatory signal. Programs with `run_cnt_cv > 0.1` have geomean 1.173x, while programs with `run_cnt_cv <= 0.1` have geomean 1.006x. 32/52 significant regressions have `run_cnt_cv > 0.1`.
3. Low sample count alone is not a strong directional predictor. Pearson correlation of `log(ratio)` with `log10(min_run_cnt)` is -0.0066 and Spearman correlation of ratio with `min_run_cnt` is -0.0240. Low counts increase variance, but they do not explain the slowdown direction by themselves.
4. Tetragon is the clearest noise/workload-consistency problem: its app-level ReJIT result is `changed=false` and every active row has `bytes_jited_delta=0`, yet it has geomean 1.108x and 21 significant regressions. Many of those rows have post-ReJIT run counts around half of baseline (`run_cnt_cv` about 0.31-0.33).
5. Tracee has real ReJIT changes: app-level `changed=true`, 2,073 applied sites, 157/158 requested programs applied, and one EINVAL on program 665. It also contains the largest outlier, `trace_commit_cr` at 4.052x, but that row has a severe run-count mismatch: 787 baseline runs vs 100 post-ReJIT runs (`run_cnt_cv=0.775`).
6. Sub-100 ns programs are not the main source of the 1.044x geomean. They are 29/178 programs with geomean 1.002x and only 6/52 significant regressions. Some individual sub-100 ns regressions have tiny absolute deltas, so they should be treated as noisy despite high run counts.
7. Weighting by run count reduces the headline slowdown but does not eliminate it: unweighted geomean is 1.0439x; mean-run-count weighted geomean is 1.0334x; min-run-count weighted geomean is 1.0326x.

## Category Counts

| category | programs | geomean | median ratio | median min_run_cnt | min_run_cnt <100 | min_run_cnt <1000 | sub100ns | median run_cnt_cv | run_cnt_cv >0.1 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| significant regression (>1.1) | 52 | 1.295 | 1.222 | 190.5 | 21 | 41 | 6 | 0.155 | 32 |
| significant improvement (<0.9) | 19 | 0.762 | 0.823 | 33.0 | 12 | 16 | 3 | 0.055 | 5 |
| neutral (0.9-1.1) | 107 | 0.994 | 0.996 | 853.0 | 34 | 56 | 20 | 0.055 | 6 |
| all | 178 | 1.044 | 1.013 | 259.0 | 67 | 113 | 29 | 0.061 | 43 |

## Correlation Checks

| check | value | interpretation |
|---|---:|---|
| Pearson `log(ratio)` vs `log10(min_run_cnt)` | -0.0066 | no meaningful linear relationship |
| Spearman `ratio` vs `min_run_cnt` | -0.0240 | no meaningful monotonic relationship |
| Pearson `log(ratio)` vs `run_cnt_cv` | 0.4312 | moderate positive relationship |
| Spearman `ratio` vs `run_cnt_cv` | 0.4629 | moderate positive relationship |
| Pearson `log(ratio)` vs `log10(baseline_avg_ns)` | -0.0641 | no meaningful relationship to baseline runtime size |

## Weighted Geomeans

| weighting | geomean | note |
|---|---:|---|
| unweighted | 1.043857 | current summary metric |
| min run count | 1.032620 | downweights mismatched/low-activity rows |
| mean run count | 1.033406 | balanced across phases |
| baseline run count | 1.035920 | baseline-side weight |
| post-ReJIT run count | 1.030708 | post-side weight |

## Regression Patterns by App

| app | programs | geomean | regressions >1.1 | improvements <0.9 | neutral | losses >1.0 | app_changed | applied_sites | status |
|---|---:|---:|---:|---:|---:|---:|---|---:|---|
| tetragon/observer | 44 | 1.108 | 21 | 4 | 19 | 33 | False | 0 | ok |
| bpftrace/vfsstat | 2 | 1.063 | 1 | 0 | 1 | 1 | False | 0 | ok |
| tracee/monitor | 97 | 1.055 | 30 | 12 | 55 | 59 | True | 2073 | error |
| bcc/tcplife | 1 | 1.034 | 0 | 0 | 1 | 1 | False | 0 | ok |
| bpftrace/biosnoop | 2 | 1.019 | 0 | 0 | 2 | 1 | False | 0 | ok |
| bcc/execsnoop | 2 | 1.012 | 0 | 0 | 2 | 1 | False | 0 | ok |
| bpftrace/tcplife | 1 | 1.004 | 0 | 0 | 1 | 1 | False | 0 | ok |
| bcc/biosnoop | 3 | 0.997 | 0 | 0 | 3 | 1 | True | 3 | ok |
| bcc/opensnoop | 3 | 0.988 | 0 | 0 | 3 | 1 | False | 0 | ok |
| bpftrace/tcpretrans | 1 | 0.970 | 0 | 0 | 1 | 0 | False | 0 | ok |
| bcc/runqlat | 3 | 0.965 | 0 | 0 | 3 | 0 | True | 6 | ok |
| bcc/vfsstat | 3 | 0.961 | 0 | 0 | 3 | 0 | False | 0 | ok |
| bcc/bindsnoop | 3 | 0.948 | 0 | 0 | 3 | 1 | True | 4 | ok |
| bpftrace/runqlat | 3 | 0.944 | 0 | 0 | 3 | 0 | False | 0 | ok |
| katran | 1 | 0.938 | 0 | 0 | 1 | 0 | False | 0 | ok |
| bcc/syscount | 2 | 0.933 | 0 | 1 | 1 | 0 | False | 0 | ok |
| bcc/tcpconnect | 3 | 0.932 | 0 | 1 | 2 | 1 | False | 0 | ok |
| bcc/capable | 1 | 0.920 | 0 | 0 | 1 | 0 | True | 1 | ok |
| bpftrace/capable | 1 | 0.917 | 0 | 0 | 1 | 0 | False | 0 | ok |
| otelcol-ebpf-profiler/profiling | 2 | 0.592 | 0 | 1 | 1 | 0 | False | 0 | ok |

## Regression Patterns by Program Type

| type | programs | geomean | regressions >1.1 | improvements <0.9 | neutral | losses >1.0 | median min_run_cnt | sub100ns |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| lsm | 1 | 1.159 | 1 | 0 | 0 | 1 | 6239.0 | 0 |
| perf_event | 2 | 1.074 | 1 | 0 | 1 | 1 | 195.0 | 0 |
| kprobe | 131 | 1.066 | 44 | 14 | 73 | 81 | 201.0 | 22 |
| raw_tracepoint | 22 | 1.038 | 6 | 1 | 15 | 14 | 138.0 | 0 |
| tracing | 6 | 0.974 | 0 | 0 | 6 | 1 | 1029.5 | 3 |
| xdp | 1 | 0.938 | 0 | 0 | 1 | 0 | 1152.0 | 1 |
| tracepoint | 13 | 0.905 | 0 | 2 | 11 | 3 | 311296.0 | 3 |
| cgroup_skb | 2 | 0.844 | 0 | 2 | 0 | 0 | 158.5 | 0 |

## Run-Count Consistency

| subset | programs | geomean | regressions >1.1 | improvements <0.9 | losses >1.0 |
|---|---:|---:|---:|---:|---:|
| run_cnt_cv >0.1 | 43 | 1.173 | 32 | 5 | 36 |
| run_cnt_cv <=0.1 | 135 | 1.006 | 20 | 14 | 65 |
| run_cnt_cv >0.2 | 28 | 1.282 | 24 | 1 | 27 |
| run_cnt_cv >0.3 | 24 | 1.302 | 21 | 1 | 23 |
| min_run_cnt <100 | 67 | 1.026 | 21 | 12 | 39 |
| min_run_cnt >=100 | 111 | 1.055 | 31 | 7 | 62 |
| sub100ns | 29 | 1.002 | 6 | 3 | 12 |
| not sub100ns | 149 | 1.052 | 46 | 16 | 89 |

Highest run-count CV rows:

| app | id | program | type | ratio | base_cnt | post_cnt | run_cnt_cv | category |
|---|---:|---|---|---:|---:|---:|---:|---|
| tracee/monitor | 624 | trace_commit_cr | kprobe | 4.052 | 787 | 100 | 0.775 | regression |
| tetragon/observer | 276 | generic_kprobe_ | kprobe | 0.604 | 4 | 23 | 0.704 | improvement |
| tracee/monitor | 609 | trace_filldir64 | kprobe | 1.066 | 64140 | 19611 | 0.532 | neutral |
| tetragon/observer | 332 | generic_kprobe_ | kprobe | 1.232 | 1457 | 724 | 0.336 | regression |
| tetragon/observer | 305 | generic_kprobe_ | kprobe | 1.219 | 2931 | 1462 | 0.334 | regression |
| tetragon/observer | 492 | generic_kprobe_ | kprobe | 1.261 | 1200 | 600 | 0.333 | regression |
| tetragon/observer | 501 | generic_kprobe_ | kprobe | 1.433 | 360 | 180 | 0.333 | regression |
| tetragon/observer | 508 | generic_kprobe_ | kprobe | 1.463 | 120 | 60 | 0.333 | regression |
| tetragon/observer | 512 | generic_retkprobe_event | kprobe | 1.228 | 120 | 60 | 0.333 | regression |
| tetragon/observer | 518 | generic_kprobe_ | kprobe | 1.571 | 120 | 60 | 0.333 | regression |
| tetragon/observer | 525 | generic_kprobe_ | kprobe | 1.406 | 360 | 180 | 0.333 | regression |
| tetragon/observer | 531 | generic_kprobe_ | kprobe | 1.403 | 240 | 120 | 0.333 | regression |
| bpftrace/vfsstat | 747 | 1 | perf_event | 1.235 | 1 | 2 | 0.333 | regression |
| tetragon/observer | 327 | generic_kprobe_ | kprobe | 1.209 | 1473 | 738 | 0.332 | regression |
| tetragon/observer | 298 | generic_kprobe_ | kprobe | 1.295 | 617 | 317 | 0.321 | regression |
| tetragon/observer | 320 | generic_kprobe_ | kprobe | 1.276 | 617 | 317 | 0.321 | regression |
| tetragon/observer | 486 | generic_kprobe_ | kprobe | 1.284 | 617 | 317 | 0.321 | regression |
| tetragon/observer | 285 | generic_kprobe_ | kprobe | 1.269 | 497 | 259 | 0.315 | regression |
| tetragon/observer | 290 | generic_retkprobe_event | kprobe | 1.076 | 497 | 259 | 0.315 | neutral |
| tetragon/observer | 311 | generic_kprobe_ | kprobe | 1.186 | 497 | 259 | 0.315 | regression |
| tetragon/observer | 317 | generic_retkprobe_event | kprobe | 1.180 | 497 | 259 | 0.315 | regression |
| tetragon/observer | 473 | generic_kprobe_ | kprobe | 1.238 | 497 | 259 | 0.315 | regression |
| tetragon/observer | 477 | generic_retkprobe_event | kprobe | 1.294 | 497 | 259 | 0.315 | regression |
| tetragon/observer | 449 | generic_kprobe_ | kprobe | 1.473 | 129 | 69 | 0.303 | regression |
| tracee/monitor | 660 | trace_mmap_aler | kprobe | 1.226 | 1661 | 1002 | 0.247 | regression |
| tetragon/observer | 384 | generic_kprobe_ | kprobe | 1.201 | 5 | 8 | 0.231 | regression |
| tetragon/observer | 391 | generic_retkprobe_event | kprobe | 1.058 | 5 | 8 | 0.231 | neutral |
| tetragon/observer | 536 | generic_kprobe_ | kprobe | 1.209 | 5 | 8 | 0.231 | regression |
| tracee/monitor | 727 | lsm_file_open_t | lsm | 1.159 | 9100 | 6239 | 0.187 | regression |
| tracee/monitor | 621 | trace_security_file_open | kprobe | 1.203 | 9097 | 6239 | 0.186 | regression |

## ReJIT Optimization Status

The compacted artifact strips successful per-program ReJIT records and only preserves app-level `changed`, app-level site totals, aggregate `program_counts`, and error programs. Therefore this result cannot prove exactly which successful individual programs changed. The split below is app-level.

| app-level changed | apps | requested programs | applied programs | not applied | applied sites | active per_program rows | active geomean | min-count weighted geomean | regressions >1.1 | improvements <0.9 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| True | 5 | 168 | 167 | 1 | 2087 | 107 | 1.046 | 1.062 | 30 | 12 |
| False | 16 | 335 | 335 | 0 | 0 | 71 | 1.041 | 0.958 | 22 | 7 |
| None | 1 | 0 | 0 | 0 | 0 | 0 | n/a | n/a | 0 | 0 |

| bytes_jited_delta signal | programs | geomean | regressions >1.1 | improvements <0.9 | losses >1.0 |
|---|---:|---:|---:|---:|---:|
| nonzero bytes_jited_delta | 84 | 1.051 | 24 | 11 | 49 |
| zero bytes_jited_delta | 94 | 1.037 | 28 | 8 | 52 |

Per-app ReJIT result summary:

| app | status | changed | requested | applied | not_applied | applied_sites | error |
|---|---|---|---:|---:|---:|---:|---|
| bcc/capable | ok | True | 1 | 1 | 0 | 1 |  |
| bcc/execsnoop | ok | False | 2 | 2 | 0 | 0 |  |
| bcc/bindsnoop | ok | True | 3 | 3 | 0 | 4 |  |
| bcc/biosnoop | ok | True | 3 | 3 | 0 | 3 |  |
| bcc/vfsstat | ok | False | 5 | 5 | 0 | 0 |  |
| bcc/opensnoop | ok | False | 3 | 3 | 0 | 0 |  |
| bcc/syscount | ok | False | 2 | 2 | 0 | 0 |  |
| bcc/tcpconnect | ok | False | 3 | 3 | 0 | 0 |  |
| bcc/tcplife | ok | False | 1 | 1 | 0 | 0 |  |
| bcc/runqlat | ok | True | 3 | 3 | 0 | 6 |  |
| calico/felix | ok | False | 6 | 6 | 0 | 0 |  |
| otelcol-ebpf-profiler/profiling | ok | False | 13 | 13 | 0 | 0 |  |
| cilium/agent | error | None | 0 | 0 | 0 | 0 | failed to read BPF stats for requested program ids: 222, 226, 227, 228, 231, 232, 235 |
| tetragon/observer | ok | False | 287 | 287 | 0 | 0 |  |
| katran | ok | False | 3 | 3 | 0 | 0 |  |
| tracee/monitor | error | True | 158 | 157 | 1 | 2073 | prog 665: BPF_PROG_REJIT: Invalid argument (os error 22) |
| bpftrace/capable | ok | False | 1 | 1 | 0 | 0 |  |
| bpftrace/biosnoop | ok | False | 2 | 2 | 0 | 0 |  |
| bpftrace/vfsstat | ok | False | 2 | 2 | 0 | 0 |  |
| bpftrace/runqlat | ok | False | 3 | 3 | 0 | 0 |  |
| bpftrace/tcplife | ok | False | 1 | 1 | 0 | 0 |  |
| bpftrace/tcpretrans | ok | False | 1 | 1 | 0 | 0 |  |

## Significant Regressions (`ratio > 1.1`)

| app | id | program | type | ratio | baseline_avg_ns | post_rejit_avg_ns | baseline_run_cnt | post_rejit_run_cnt | run_cnt_cv | sub100ns | app_changed | bytes_jited_delta |
|---|---:|---|---|---:|---:|---:|---:|---:|---:|---|---|---:|
| tracee/monitor | 624 | trace_commit_cr | kprobe | 4.052 | 237.1 | 960.5 | 787 | 100 | 0.775 | False | True | -22 |
| tracee/monitor | 703 | trace_exec_binp | kprobe | 2.306 | 163.4 | 376.8 | 43 | 38 | 0.062 | False | True | -31 |
| tracee/monitor | 580 | trace_process_v | kprobe | 2.083 | 461.3 | 960.8 | 29 | 26 | 0.055 | False | True | 2 |
| tracee/monitor | 682 | trace_do_init_m | kprobe | 1.633 | 504.5 | 823.7 | 12 | 10 | 0.091 | False | True | 0 |
| tetragon/observer | 518 | generic_kprobe_ | kprobe | 1.571 | 2303.9 | 3619.8 | 120 | 60 | 0.333 | False | False | 0 |
| tetragon/observer | 449 | generic_kprobe_ | kprobe | 1.473 | 2060.3 | 3034.7 | 129 | 69 | 0.303 | False | False | 0 |
| tetragon/observer | 508 | generic_kprobe_ | kprobe | 1.463 | 1536.5 | 2248.0 | 120 | 60 | 0.333 | False | False | 0 |
| tetragon/observer | 501 | generic_kprobe_ | kprobe | 1.433 | 1163.6 | 1667.8 | 360 | 180 | 0.333 | False | False | 0 |
| tetragon/observer | 525 | generic_kprobe_ | kprobe | 1.406 | 1193.3 | 1677.7 | 360 | 180 | 0.333 | False | False | 0 |
| tetragon/observer | 531 | generic_kprobe_ | kprobe | 1.403 | 1816.9 | 2548.9 | 240 | 120 | 0.333 | False | False | 0 |
| tracee/monitor | 662 | trace_ret_do_mm | kprobe | 1.392 | 91.7 | 127.6 | 1001 | 883 | 0.063 | True | True | -156 |
| tracee/monitor | 701 | trace_ret_inoti | kprobe | 1.313 | 417.6 | 548.3 | 29 | 26 | 0.055 | False | True | -36 |
| tetragon/observer | 298 | generic_kprobe_ | kprobe | 1.295 | 875.2 | 1133.3 | 617 | 317 | 0.321 | False | False | 0 |
| tracee/monitor | 641 | trace_ret_vfs_w | kprobe | 1.294 | 38.1 | 49.3 | 47481 | 36973 | 0.124 | True | True | -31 |
| tetragon/observer | 477 | generic_retkprobe_event | kprobe | 1.294 | 847.8 | 1096.9 | 497 | 259 | 0.315 | False | False | 0 |
| tracee/monitor | 642 | vfs_write_magic | kprobe | 1.292 | 37.8 | 48.9 | 47501 | 36992 | 0.124 | True | True | -47 |
| tetragon/observer | 486 | generic_kprobe_ | kprobe | 1.284 | 987.8 | 1268.4 | 617 | 317 | 0.321 | False | False | 0 |
| tetragon/observer | 320 | generic_kprobe_ | kprobe | 1.276 | 919.9 | 1174.0 | 617 | 317 | 0.321 | False | False | 0 |
| tetragon/observer | 285 | generic_kprobe_ | kprobe | 1.269 | 1127.2 | 1430.2 | 497 | 259 | 0.315 | False | False | 0 |
| tracee/monitor | 717 | trace_security_ | kprobe | 1.267 | 109.3 | 138.4 | 239 | 201 | 0.086 | False | True | -212 |
| tetragon/observer | 492 | generic_kprobe_ | kprobe | 1.261 | 614.7 | 775.0 | 1200 | 600 | 0.333 | False | False | 0 |
| tetragon/observer | 473 | generic_kprobe_ | kprobe | 1.238 | 1257.0 | 1555.6 | 497 | 259 | 0.315 | False | False | 0 |
| bpftrace/vfsstat | 747 | 1 | perf_event | 1.235 | 939.0 | 1160.0 | 1 | 2 | 0.333 | False | False | 0 |
| tetragon/observer | 332 | generic_kprobe_ | kprobe | 1.232 | 721.7 | 889.1 | 1457 | 724 | 0.336 | False | False | 0 |
| tetragon/observer | 512 | generic_retkprobe_event | kprobe | 1.228 | 1049.9 | 1289.8 | 120 | 60 | 0.333 | False | False | 0 |
| tracee/monitor | 660 | trace_mmap_aler | kprobe | 1.226 | 171.2 | 209.9 | 1661 | 1002 | 0.247 | False | True | -27 |
| tetragon/observer | 305 | generic_kprobe_ | kprobe | 1.219 | 684.7 | 834.5 | 2931 | 1462 | 0.334 | False | False | 0 |
| tracee/monitor | 578 | trace_ptrace | kprobe | 1.218 | 683.1 | 831.9 | 58 | 52 | 0.055 | False | True | 2 |
| tetragon/observer | 327 | generic_kprobe_ | kprobe | 1.209 | 749.6 | 906.0 | 1473 | 738 | 0.332 | False | False | 0 |
| tetragon/observer | 536 | generic_kprobe_ | kprobe | 1.209 | 4863.6 | 5877.8 | 5 | 8 | 0.231 | False | False | 0 |
| tracee/monitor | 621 | trace_security_file_open | kprobe | 1.203 | 670.0 | 806.1 | 9097 | 6239 | 0.186 | False | True | 0 |
| tetragon/observer | 384 | generic_kprobe_ | kprobe | 1.201 | 6527.0 | 7836.5 | 5 | 8 | 0.231 | False | False | 0 |
| tetragon/observer | 311 | generic_kprobe_ | kprobe | 1.186 | 1163.9 | 1381.0 | 497 | 259 | 0.315 | False | False | 0 |
| tracee/monitor | 618 | tracepoint__cgr | raw_tracepoint | 1.184 | 1655.0 | 1959.0 | 1 | 1 | 0.000 | False | True | -23 |
| tracee/monitor | 640 | vfs_write_magic | kprobe | 1.181 | 41.0 | 48.4 | 47466 | 36968 | 0.124 | True | True | 0 |
| tetragon/observer | 317 | generic_retkprobe_event | kprobe | 1.180 | 900.3 | 1062.3 | 497 | 259 | 0.315 | False | False | 0 |
| tracee/monitor | 711 | trace_security_task_prctl | kprobe | 1.178 | 1268.5 | 1493.7 | 14 | 14 | 0.000 | False | True | 0 |
| tracee/monitor | 680 | tracepoint__mod | raw_tracepoint | 1.171 | 5945.3 | 6961.1 | 12 | 10 | 0.091 | False | True | -16 |
| tracee/monitor | 686 | tracepoint__tas | raw_tracepoint | 1.169 | 1951.8 | 2282.1 | 45 | 40 | 0.059 | False | True | -38 |
| tracee/monitor | 647 | vfs_writev_magi | kprobe | 1.167 | 37.1 | 43.3 | 3838 | 4206 | 0.046 | True | True | -754 |
| tracee/monitor | 694 | trace_fd_instal | kprobe | 1.166 | 265.0 | 309.0 | 15428 | 12232 | 0.116 | False | True | -297 |
| tracee/monitor | 727 | lsm_file_open_t | lsm | 1.159 | 335.3 | 388.6 | 9100 | 6239 | 0.187 | False | True | -38 |
| tracee/monitor | 582 | trace_arch_prct | kprobe | 1.132 | 1346.9 | 1525.1 | 43 | 38 | 0.062 | False | True | 2 |
| tracee/monitor | 586 | trace_dup2 | kprobe | 1.129 | 1103.4 | 1246.1 | 57 | 50 | 0.065 | False | True | 2 |
| tracee/monitor | 639 | trace_vfs_write | kprobe | 1.116 | 60.8 | 67.9 | 47467 | 36961 | 0.124 | True | True | 0 |
| tracee/monitor | 726 | tracepoint__exe | raw_tracepoint | 1.116 | 1052.6 | 1174.8 | 43 | 38 | 0.062 | False | True | -33 |
| tracee/monitor | 715 | trace_ret_sock_ | kprobe | 1.115 | 1203.3 | 1341.5 | 220 | 203 | 0.040 | False | True | -209 |
| tracee/monitor | 707 | trace_set_fs_pw | kprobe | 1.113 | 2580.9 | 2873.5 | 13 | 11 | 0.083 | False | True | -73 |
| tracee/monitor | 690 | trace_do_sigact | kprobe | 1.113 | 512.9 | 570.8 | 983 | 823 | 0.089 | False | True | 39 |
| tracee/monitor | 606 | tracepoint__sch | raw_tracepoint | 1.112 | 1536.9 | 1708.5 | 156 | 138 | 0.061 | False | True | 0 |
| tracee/monitor | 608 | tracepoint__sch | raw_tracepoint | 1.110 | 258.2 | 286.5 | 339061 | 270666 | 0.112 | False | True | -20 |
| tracee/monitor | 675 | trace_security_ | kprobe | 1.108 | 2858.3 | 3165.8 | 12 | 10 | 0.091 | False | True | -38 |

## Significant Improvements (`ratio < 0.9`)

| app | id | program | type | ratio | baseline_avg_ns | post_rejit_avg_ns | baseline_run_cnt | post_rejit_run_cnt | run_cnt_cv | sub100ns | app_changed | bytes_jited_delta |
|---|---:|---|---|---:|---:|---:|---:|---:|---:|---|---|---:|
| otelcol-ebpf-profiler/profiling | 131 | tracepoint__sch | tracepoint | 0.375 | 2436.5 | 913.2 | 8 | 6 | 0.143 | False | False | 0 |
| tracee/monitor | 683 | trace_ret_do_in | kprobe | 0.598 | 539.7 | 322.5 | 12 | 10 | 0.091 | False | True | -45 |
| tetragon/observer | 276 | generic_kprobe_ | kprobe | 0.604 | 2190.2 | 1322.4 | 4 | 23 | 0.704 | False | False | 0 |
| tracee/monitor | 725 | empty_kprobe | kprobe | 0.654 | 58.1 | 38.0 | 43 | 38 | 0.062 | True | True | 0 |
| tetragon/observer | 413 | generic_retkprobe_event | kprobe | 0.714 | 2568.0 | 1832.5 | 2 | 2 | 0.000 | False | False | 0 |
| tetragon/observer | 417 | generic_kprobe_ | kprobe | 0.735 | 3972.5 | 2920.0 | 2 | 2 | 0.000 | False | False | 0 |
| tracee/monitor | 708 | trace_security_ | kprobe | 0.770 | 1160.1 | 893.3 | 12 | 16 | 0.143 | False | True | -14 |
| tracee/monitor | 617 | tracepoint__cgr | raw_tracepoint | 0.814 | 2733.0 | 2224.0 | 1 | 1 | 0.000 | False | True | -29 |
| tracee/monitor | 721 | cgroup_skb_ingr | cgroup_skb | 0.823 | 1382.9 | 1137.5 | 176 | 158 | 0.054 | False | True | -3516 |
| tracee/monitor | 655 | trace_ret_vfs_r | kprobe | 0.823 | 268.5 | 221.0 | 2621 | 3279 | 0.112 | False | True | -31 |
| bcc/tcpconnect | 40 | trace_connect_v | kprobe | 0.824 | 5229.8 | 4311.1 | 33 | 36 | 0.043 | False | False | 0 |
| tracee/monitor | 718 | trace_security_ | kprobe | 0.835 | 418.2 | 349.3 | 99 | 84 | 0.082 | False | True | -212 |
| tracee/monitor | 722 | cgroup_skb_egre | cgroup_skb | 0.865 | 1941.6 | 1680.1 | 176 | 159 | 0.051 | False | True | -3516 |
| bcc/syscount | 36 | raw_syscalls__s | tracepoint | 0.879 | 63.3 | 55.7 | 915033 | 1043172 | 0.065 | True | False | 0 |
| tracee/monitor | 632 | trace_security_ | kprobe | 0.881 | 1915.1 | 1686.3 | 29 | 26 | 0.055 | False | True | -57 |
| tetragon/observer | 404 | generic_kprobe_ | kprobe | 0.884 | 7336.5 | 6488.0 | 2 | 2 | 0.000 | False | False | 0 |
| tracee/monitor | 627 | trace_security_ | kprobe | 0.887 | 1043.4 | 925.4 | 118 | 106 | 0.054 | False | True | -7 |
| tracee/monitor | 685 | trace_security_ | kprobe | 0.890 | 40.7 | 36.2 | 90161 | 70953 | 0.119 | True | True | -38 |
| tracee/monitor | 714 | trace_sock_allo | kprobe | 0.900 | 415.7 | 374.1 | 220 | 203 | 0.040 | False | True | -2 |

## Neutral Programs (`0.9 <= ratio <= 1.1`)

| app | id | program | type | ratio | baseline_avg_ns | post_rejit_avg_ns | baseline_run_cnt | post_rejit_run_cnt | run_cnt_cv | sub100ns | app_changed | bytes_jited_delta |
|---|---:|---|---|---:|---:|---:|---:|---:|---:|---|---|---:|
| bcc/bindsnoop | 13 | bindsnoop_entry | kprobe | 1.033 | 53.0 | 54.8 | 32245 | 30342 | 0.030 | True | True | 0 |
| bcc/bindsnoop | 15 | bindsnoop_v6_re | kprobe | 0.911 | 771.1 | 702.2 | 16122 | 15171 | 0.030 | False | True | -2 |
| bcc/bindsnoop | 14 | bindsnoop_v4_re | kprobe | 0.907 | 778.0 | 705.4 | 16123 | 15171 | 0.030 | False | True | -2 |
| bcc/biosnoop | 19 | trace_req_start | kprobe | 0.986 | 180.7 | 178.1 | 311296 | 344072 | 0.050 | False | True | 0 |
| bcc/biosnoop | 20 | trace_req_compl | tracepoint | 1.030 | 376.3 | 387.6 | 311296 | 344073 | 0.050 | False | True | -2 |
| bcc/biosnoop | 18 | trace_pid_start | tracepoint | 0.977 | 159.4 | 155.7 | 311296 | 344070 | 0.050 | False | True | 0 |
| bcc/capable | 6 | cap_capable | kprobe | 0.920 | 82.8 | 76.2 | 147283 | 150578 | 0.011 | True | True | 3 |
| bcc/execsnoop | 9 | syscall__execve | kprobe | 1.067 | 1778.4 | 1898.4 | 1243 | 1145 | 0.041 | False | False | 0 |
| bcc/execsnoop | 10 | do_ret_sys_exec | kprobe | 0.960 | 1409.4 | 1353.3 | 1157 | 1065 | 0.041 | False | False | 0 |
| bcc/opensnoop | 30 | __x64_sys_open | tracing | 1.014 | 1249.6 | 1266.8 | 453 | 552 | 0.099 | False | False | 0 |
| bcc/opensnoop | 32 | __x64_sys_opena | tracing | 0.999 | 1310.5 | 1309.3 | 453 | 552 | 0.099 | False | False | 0 |
| bcc/opensnoop | 31 | __x64_sys_opena | tracing | 0.952 | 1337.0 | 1272.2 | 1451 | 1626 | 0.057 | False | False | 0 |
| bcc/runqlat | 49 | sched_wakeup_ne | raw_tracepoint | 0.995 | 246.8 | 245.4 | 3856 | 3599 | 0.034 | False | True | 0 |
| bcc/runqlat | 48 | sched_wakeup | raw_tracepoint | 0.957 | 122.3 | 117.0 | 63359 | 58234 | 0.042 | False | True | 0 |
| bcc/runqlat | 47 | sched_switch | raw_tracepoint | 0.944 | 185.9 | 175.4 | 92490 | 84972 | 0.042 | False | True | -17 |
| bcc/syscount | 35 | raw_syscalls__s | tracepoint | 0.990 | 63.6 | 63.0 | 915200 | 1043420 | 0.065 | True | False | 0 |
| bcc/tcpconnect | 39 | trace_connect_e | kprobe | 1.070 | 718.0 | 768.4 | 66 | 72 | 0.043 | False | False | 0 |
| bcc/tcpconnect | 41 | trace_connect_v | kprobe | 0.919 | 4821.2 | 4430.7 | 33 | 36 | 0.043 | False | False | 0 |
| bcc/tcplife | 44 | sock__inet_sock | tracepoint | 1.034 | 714.5 | 738.7 | 812 | 770 | 0.027 | False | False | 0 |
| bcc/vfsstat | 26 | vfs_read | tracing | 0.985 | 29.7 | 29.3 | 9058 | 6859 | 0.138 | True | False | 0 |
| bcc/vfsstat | 27 | vfs_write | tracing | 0.974 | 28.6 | 27.8 | 13221 | 11955 | 0.050 | True | False | 0 |
| bcc/vfsstat | 25 | vfs_open | tracing | 0.925 | 55.2 | 51.1 | 624 | 608 | 0.013 | True | False | 0 |
| bpftrace/biosnoop | 741 | block_io_done | tracepoint | 1.069 | 311.0 | 332.4 | 335872 | 327680 | 0.012 | False | False | 0 |
| bpftrace/biosnoop | 740 | block_io_start | tracepoint | 0.971 | 200.7 | 194.8 | 335872 | 327680 | 0.012 | False | False | 0 |
| bpftrace/capable | 734 | cap_capable | kprobe | 0.917 | 127.7 | 117.0 | 146806 | 139199 | 0.027 | False | False | 0 |
| bpftrace/runqlat | 755 | sched_wakeup_ne | tracepoint | 0.999 | 223.0 | 222.9 | 3856 | 3085 | 0.111 | False | False | 0 |
| bpftrace/runqlat | 756 | sched_switch | tracepoint | 0.918 | 168.4 | 154.5 | 90772 | 101782 | 0.057 | False | False | 0 |
| bpftrace/runqlat | 754 | sched_wakeup | tracepoint | 0.918 | 106.3 | 97.5 | 56096 | 63926 | 0.065 | True | False | 0 |
| bpftrace/tcplife | 763 | tcp_set_state | kprobe | 1.004 | 938.5 | 942.6 | 714 | 704 | 0.007 | False | False | 0 |
| bpftrace/tcpretrans | 769 | tcp_retransmit_ | kprobe | 0.970 | 5607.9 | 5437.9 | 17 | 18 | 0.029 | False | False | 0 |
| bpftrace/vfsstat | 748 | vfs_create | kprobe | 0.915 | 53.7 | 49.2 | 20624 | 17452 | 0.083 | True | False | 0 |
| katran | 553 | balancer_ingress | xdp | 0.938 | 55.8 | 52.3 | 1152 | 1152 | 0.000 | True | False | 0 |
| otelcol-ebpf-profiler/profiling | 132 | native_tracer_e | perf_event | 0.934 | 19940.2 | 18617.6 | 398 | 389 | 0.011 | False | False | 0 |
| tetragon/observer | 273 | generic_kprobe_ | kprobe | 1.091 | 3632.0 | 3962.0 | 1 | 1 | 0.000 | False | False | 0 |
| tetragon/observer | 253 | event_wake_up_n | kprobe | 1.088 | 751.5 | 817.3 | 1733 | 1901 | 0.046 | False | False | 0 |
| tetragon/observer | 426 | generic_kprobe_ | kprobe | 1.080 | 5124.5 | 5535.0 | 2 | 2 | 0.000 | False | False | 0 |
| tetragon/observer | 290 | generic_retkprobe_event | kprobe | 1.076 | 838.7 | 902.6 | 497 | 259 | 0.315 | False | False | 0 |
| tetragon/observer | 257 | tg_kp_bprm_comm | kprobe | 1.070 | 296.8 | 317.6 | 853 | 1004 | 0.081 | False | False | 0 |
| tetragon/observer | 391 | generic_retkprobe_event | kprobe | 1.058 | 2214.2 | 2342.8 | 5 | 8 | 0.231 | False | False | 0 |
| tetragon/observer | 469 | generic_kprobe_ | kprobe | 1.032 | 5777.0 | 5963.0 | 1 | 1 | 0.000 | False | False | 0 |
| tetragon/observer | 365 | generic_kprobe_ | kprobe | 1.018 | 467.6 | 476.1 | 167825 | 169794 | 0.006 | False | False | 0 |
| tetragon/observer | 370 | generic_retkprobe_event | kprobe | 1.015 | 40.9 | 41.4 | 167687 | 169047 | 0.004 | True | False | 0 |
| tetragon/observer | 359 | generic_kprobe_ | kprobe | 1.013 | 270.4 | 273.9 | 40907 | 44365 | 0.041 | False | False | 0 |
| tetragon/observer | 462 | generic_kprobe_ | kprobe | 1.002 | 2695.7 | 2702.0 | 44738 | 51863 | 0.074 | False | False | 0 |
| tetragon/observer | 374 | generic_kprobe_ | kprobe | 0.996 | 999.6 | 995.7 | 109083 | 127346 | 0.077 | False | False | 0 |
| tetragon/observer | 378 | generic_retkprobe_event | kprobe | 0.996 | 48.5 | 48.3 | 109083 | 127346 | 0.077 | True | False | 0 |
| tetragon/observer | 432 | generic_kprobe_ | kprobe | 0.970 | 1727.7 | 1676.0 | 853 | 1004 | 0.081 | False | False | 0 |
| tetragon/observer | 251 | event_exit_acct | kprobe | 0.929 | 615.2 | 571.5 | 1087 | 1241 | 0.066 | False | False | 0 |
| tetragon/observer | 266 | generic_kprobe_ | kprobe | 0.917 | 2710.5 | 2484.8 | 4 | 4 | 0.000 | False | False | 0 |
| tetragon/observer | 444 | generic_rawtp_e | raw_tracepoint | 1.076 | 1620.6 | 1743.6 | 853 | 1004 | 0.081 | False | False | 0 |
| tetragon/observer | 256 | event_execve | tracepoint | 0.976 | 3077.5 | 3003.5 | 853 | 1004 | 0.081 | False | False | 0 |
| tetragon/observer | 441 | generic_tracepo | tracepoint | 0.948 | 485.8 | 460.5 | 1408658 | 1377863 | 0.011 | False | False | 0 |
| tracee/monitor | 633 | trace_security_ | kprobe | 1.082 | 1624.8 | 1757.8 | 29 | 26 | 0.055 | False | True | -18 |
| tracee/monitor | 691 | trace_vfs_utime | kprobe | 1.079 | 2708.4 | 2922.4 | 47 | 41 | 0.068 | False | True | -17 |
| tracee/monitor | 626 | trace_cap_capab | kprobe | 1.075 | 192.0 | 206.4 | 27391 | 21842 | 0.113 | False | True | -25 |
| tracee/monitor | 697 | trace_ret_file_ | kprobe | 1.067 | 36.9 | 39.4 | 5844 | 6389 | 0.045 | True | True | 9 |
| tracee/monitor | 583 | trace_ret_arch_ | kprobe | 1.067 | 1775.5 | 1893.9 | 43 | 38 | 0.062 | False | True | -36 |
| tracee/monitor | 609 | trace_filldir64 | kprobe | 1.066 | 17.8 | 18.9 | 64140 | 19611 | 0.532 | True | True | -38 |
| tracee/monitor | 705 | trace_execute_f | kprobe | 1.064 | 3518.6 | 3742.7 | 72 | 64 | 0.059 | False | True | -26 |
| tracee/monitor | 666 | trace_security_ | kprobe | 1.057 | 344.2 | 363.8 | 21635 | 19626 | 0.049 | False | True | -35 |
| tracee/monitor | 670 | trace_security_ | kprobe | 1.055 | 1113.3 | 1174.2 | 506 | 506 | 0.000 | False | True | -20 |
| tracee/monitor | 587 | trace_ret_dup2 | kprobe | 1.045 | 2135.2 | 2232.3 | 57 | 50 | 0.065 | False | True | -36 |
| tracee/monitor | 695 | trace_filp_clos | kprobe | 1.042 | 944.0 | 984.1 | 4907 | 4374 | 0.057 | False | True | -297 |
| tracee/monitor | 719 | cgroup_bpf_run_ | kprobe | 1.040 | 1221.4 | 1270.8 | 444 | 389 | 0.066 | False | True | -386 |
| tracee/monitor | 636 | trace_security_ | kprobe | 1.032 | 1729.9 | 1785.2 | 35 | 32 | 0.045 | False | True | -47 |
| tracee/monitor | 654 | trace_vfs_read | kprobe | 1.032 | 85.7 | 88.4 | 22043 | 18070 | 0.099 | True | True | 0 |
| tracee/monitor | 716 | trace_security_ | kprobe | 1.021 | 1710.1 | 1745.7 | 29 | 26 | 0.055 | False | True | 0 |
| tracee/monitor | 635 | trace_security_ | kprobe | 1.012 | 1678.6 | 1699.2 | 31 | 28 | 0.051 | False | True | -17 |
| tracee/monitor | 657 | trace_vfs_readv | kprobe | 1.012 | 81.2 | 82.1 | 3838 | 4206 | 0.046 | True | True | 0 |
| tracee/monitor | 579 | trace_ret_ptrac | kprobe | 1.011 | 1394.1 | 1409.0 | 58 | 52 | 0.055 | False | True | -36 |
| tracee/monitor | 634 | trace_security_ | kprobe | 1.011 | 2497.8 | 2524.4 | 103 | 98 | 0.025 | False | True | -60 |
| tracee/monitor | 669 | trace_security_ | kprobe | 1.005 | 310.8 | 312.2 | 6288 | 6152 | 0.011 | False | True | -29 |
| tracee/monitor | 581 | trace_ret_proce | kprobe | 1.001 | 1986.5 | 1988.7 | 29 | 26 | 0.055 | False | True | -36 |
| tracee/monitor | 615 | trace_security_ | kprobe | 1.001 | 779.4 | 780.0 | 188 | 168 | 0.056 | False | True | -6 |
| tracee/monitor | 704 | trace_security_ | kprobe | 1.000 | 4867.5 | 4866.3 | 43 | 38 | 0.062 | False | True | -12 |
| tracee/monitor | 625 | trace_switch_ta | kprobe | 0.999 | 1189.8 | 1188.8 | 156 | 138 | 0.061 | False | True | 11 |
| tracee/monitor | 658 | trace_ret_vfs_r | kprobe | 0.989 | 56.8 | 56.2 | 3838 | 4206 | 0.046 | True | True | -31 |
| tracee/monitor | 611 | trace_do_exit | kprobe | 0.988 | 1423.1 | 1406.6 | 156 | 138 | 0.061 | False | True | -38 |
| tracee/monitor | 687 | trace_security_ | kprobe | 0.983 | 2810.0 | 2762.4 | 29 | 26 | 0.055 | False | True | -45 |
| tracee/monitor | 700 | trace_inotify_f | kprobe | 0.983 | 538.9 | 529.7 | 29 | 26 | 0.055 | False | True | 0 |
| tracee/monitor | 620 | trace_security_ | kprobe | 0.982 | 3554.3 | 3488.6 | 43 | 38 | 0.062 | False | True | -26 |
| tracee/monitor | 710 | trace_chmod_com | kprobe | 0.977 | 2895.1 | 2828.2 | 29 | 26 | 0.055 | False | True | -35 |
| tracee/monitor | 664 | trace_security_file_mprotect | kprobe | 0.973 | 1459.0 | 1419.2 | 175 | 152 | 0.070 | False | True | 0 |
| tracee/monitor | 706 | trace_security_ | kprobe | 0.962 | 3410.3 | 3279.4 | 29 | 26 | 0.055 | False | True | -17 |
| tracee/monitor | 645 | vfs_writev_magi | kprobe | 0.951 | 50.7 | 48.2 | 3838 | 4206 | 0.046 | True | True | 0 |
| tracee/monitor | 661 | trace_do_mmap | kprobe | 0.950 | 147.2 | 139.9 | 1001 | 883 | 0.063 | False | True | 0 |
| tracee/monitor | 684 | trace_load_elf_ | kprobe | 0.944 | 1668.0 | 1575.0 | 86 | 76 | 0.062 | False | True | -11 |
| tracee/monitor | 663 | trace_security_mmap_file | kprobe | 0.944 | 941.3 | 888.7 | 1001 | 883 | 0.063 | False | True | 0 |
| tracee/monitor | 644 | trace_vfs_write | kprobe | 0.923 | 54.9 | 50.6 | 3838 | 4206 | 0.046 | True | True | 0 |
| tracee/monitor | 674 | trace_security_ | kprobe | 0.922 | 2939.8 | 2711.1 | 12 | 10 | 0.091 | False | True | -9 |
| tracee/monitor | 696 | trace_file_upda | kprobe | 0.921 | 91.6 | 84.4 | 5844 | 6389 | 0.045 | True | True | -10 |
| tracee/monitor | 623 | trace_security_ | kprobe | 0.912 | 1958.0 | 1786.3 | 136 | 121 | 0.058 | False | True | -13 |
| tracee/monitor | 693 | trace_do_trunca | kprobe | 0.908 | 806.3 | 732.3 | 1948 | 2129 | 0.044 | False | True | -20 |
| tracee/monitor | 628 | trace_security_ | kprobe | 0.908 | 3038.4 | 2757.6 | 29 | 26 | 0.055 | False | True | -73 |
| tracee/monitor | 646 | trace_ret_vfs_w | kprobe | 0.904 | 47.1 | 42.6 | 3838 | 4206 | 0.046 | True | True | -31 |
| tracee/monitor | 676 | trace_security_ | kprobe | 0.903 | 2560.7 | 2313.0 | 29 | 26 | 0.055 | False | True | -26 |
| tracee/monitor | 576 | trace_sys_enter | raw_tracepoint | 1.099 | 310.8 | 341.6 | 3166180 | 2779264 | 0.065 | False | True | -25 |
| tracee/monitor | 573 | tracepoint__raw | raw_tracepoint | 1.088 | 330.1 | 359.1 | 3166194 | 2784785 | 0.064 | False | True | 0 |
| tracee/monitor | 577 | trace_sys_exit | raw_tracepoint | 1.083 | 308.5 | 334.1 | 3166110 | 2779337 | 0.065 | False | True | -25 |
| tracee/monitor | 603 | tracepoint__sch | raw_tracepoint | 1.057 | 5082.0 | 5372.6 | 43 | 38 | 0.062 | False | True | -31 |
| tracee/monitor | 681 | tracepoint__mod | raw_tracepoint | 1.046 | 6540.7 | 6838.8 | 12 | 10 | 0.091 | False | True | -45 |
| tracee/monitor | 570 | tracepoint__raw | raw_tracepoint | 1.011 | 157.3 | 159.1 | 3167330 | 2784217 | 0.064 | False | True | 0 |
| tracee/monitor | 595 | tracepoint__sch | raw_tracepoint | 1.003 | 5055.9 | 5072.1 | 156 | 138 | 0.061 | False | True | 125 |
| tracee/monitor | 619 | tracepoint__cgr | raw_tracepoint | 0.991 | 1604.0 | 1590.0 | 1 | 1 | 0.000 | False | True | -23 |
| tracee/monitor | 723 | cgroup_mkdir_si | raw_tracepoint | 0.978 | 2673.0 | 2615.0 | 1 | 1 | 0.000 | False | True | -12 |
| tracee/monitor | 605 | tracepoint__sch | raw_tracepoint | 0.966 | 1939.9 | 1873.3 | 156 | 138 | 0.061 | False | True | -20 |
| tracee/monitor | 724 | cgroup_rmdir_si | raw_tracepoint | 0.954 | 1888.0 | 1801.0 | 1 | 1 | 0.000 | False | True | -12 |

## Conclusion

The 1.044x corpus geomean is not clean evidence that ReJIT generally made programs slower. A large part of the regression comes from rows where the baseline and post-ReJIT workloads did not exercise the same number of BPF invocations, especially unchanged tetragon programs. After filtering by consistency conceptually, the stable-count subset is nearly neutral at 1.006x geomean. The remaining real concern is tracee: it is the one large changed app with many applied optimization sites and still has stable-count regressions in addition to workload-mismatch outliers. The next measurement run should prioritize repeated samples and workload-count stability before attributing small per-program ratios to ReJIT code quality.

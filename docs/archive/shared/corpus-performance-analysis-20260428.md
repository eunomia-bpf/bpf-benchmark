# Corpus Performance Analysis - 2026-04-28

Source result:
`corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`

Definitions:

- `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; lower than `1.0` is faster after ReJIT.
- `bytes_jited_delta = post_rejit.bytes_jited - baseline.bytes_jited`.
- `applied` below means `bytes_jited_delta != 0` for that program. This is stricter than app-level `rejit_result.changed`.
- Comparable programs are only rows with `run_cnt_delta > 0` in both phases, matching the framework's mathematical requirement.
- Workload stability uses app workload `ops_total`: `abs(post_ops - baseline_ops) / baseline_ops > 10%` is unstable.

## Executive Summary

The latest run is effectively flat by the headline metric: `1.0038275637087666` across `146` comparable programs, with `81` wins and `65` losses. App status is `21/22 ok`; the only app error is the known `tracee/monitor` ReJIT `EINVAL` on program `665`.

The root cause is not app-level workload instability in this run. Every app has workload `ops_total` within 10% between baseline and post-ReJIT. The current problem is coverage and attribution:

- Only `63/146` comparable programs have `bytes_jited_delta != 0`.
- Those applied rows are concentrated in `tracee/monitor`: `59/63` comparable applied rows are tracee.
- `16/21` app cases with comparable rows have zero applied programs; `17/22` result app cases have zero applied programs even when counting all loaded BPF programs.
- Applied comparable rows regress: geomean `1.032346`.
- Non-applied comparable rows improve: geomean `0.982708`. Since these programs have no JIT byte-size change, that deviation is measurement/runtime noise, BPF event mix movement, or same-size/native-equivalent effects not visible from bytes.

So the overall near-neutral result is a cancellation: applied rows are about `3.2%` slower by unweighted per-program geomean, while non-applied rows are about `1.7%` faster. This means the headline does not show a real improvement; it also does not show a broad app workload failure.

One caveat: run-count-weighted diagnostics tell a less negative story. Weighted by minimum per-program run count, all rows are `0.9957`, applied rows are `0.9945`, and non-applied rows are `0.9962`. The official metric is unweighted per-program geomean, but this shows the small applied regression is driven by equal weighting of many lower-activity tracee programs rather than a high-volume runtime slowdown.

## Per-App Breakdown

| app | status | comparable programs | geomean | wins/losses | comparable applied | all loaded applied | run_cnt >10% | workload ops diff |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| `bcc/capable` | `ok` | 1 | 0.748 | 1/0 | 1/1 | 1/1 | 1 | +7.0% |
| `bcc/execsnoop` | `ok` | 2 | 0.682 | 2/0 | 0/2 | 0/2 | 2 | +0.0% |
| `bcc/bindsnoop` | `ok` | 2 | 0.939 | 2/0 | 1/2 | 2/3 | 0 | -0.3% |
| `bcc/biosnoop` | `ok` | 3 | 0.943 | 3/0 | 1/3 | 1/3 | 0 | +0.0% |
| `bcc/vfsstat` | `ok` | 5 | 1.002 | 1/4 | 0/5 | 0/5 | 0 | -0.1% |
| `bcc/opensnoop` | `ok` | 3 | 0.990 | 3/0 | 0/3 | 0/3 | 2 | -0.1% |
| `bcc/syscount` | `ok` | 2 | 0.983 | 2/0 | 0/2 | 0/2 | 0 | -0.9% |
| `bcc/tcpconnect` | `ok` | 2 | 1.015 | 1/1 | 0/2 | 0/3 | 2 | +0.6% |
| `bcc/tcplife` | `ok` | 1 | 0.902 | 1/0 | 0/1 | 0/1 | 0 | +0.0% |
| `bcc/runqlat` | `ok` | 3 | 0.973 | 3/0 | 1/3 | 1/3 | 0 | +0.0% |
| `calico/felix` | `ok` | 1 | 0.849 | 1/0 | 0/1 | 0/6 | 1 | +0.8% |
| `otelcol-ebpf-profiler/profiling` | `ok` | 2 | 0.922 | 2/0 | 0/2 | 0/13 | 0 | +0.0% |
| `cilium/agent` | `ok` | 1 | 0.969 | 1/0 | 0/1 | 0/16 | 0 | +1.2% |
| `tetragon/observer` | `ok` | 36 | 1.006 | 17/19 | 0/36 | 0/287 | 6 | -0.2% |
| `katran` | `ok` | 1 | 1.024 | 0/1 | 0/1 | 0/3 | 0 | -0.6% |
| `tracee/monitor` | `error` | 72 | 1.034 | 35/37 | 59/72 | 121/158 | 8 | +0.0% |
| `bpftrace/capable` | `ok` | 1 | 0.897 | 1/0 | 0/1 | 0/1 | 1 | +1.4% |
| `bpftrace/biosnoop` | `ok` | 2 | 0.989 | 2/0 | 0/2 | 0/2 | 0 | +0.0% |
| `bpftrace/vfsstat` | `ok` | 2 | 0.997 | 1/1 | 0/2 | 0/2 | 0 | +0.0% |
| `bpftrace/runqlat` | `ok` | 3 | 0.973 | 2/1 | 0/3 | 0/3 | 1 | +0.0% |
| `bpftrace/tcplife` | `ok` | 1 | 1.076 | 0/1 | 0/1 | 0/1 | 0 | -0.2% |
| `bpftrace/tcpretrans` | `ok` | 0 | n/a | 0/0 | 0/0 | 0/1 | 0 | -0.4% |

Runner-family view:

| runner | programs | geomean | wins/losses | comparable applied |
|---|---:|---:|---:|---:|
| `bcc` | 24 | 0.936691 | 19/5 | 4 |
| `bpftrace` | 9 | 0.983871 | 6/3 | 0 |
| `calico` | 1 | 0.849080 | 1/0 | 0 |
| `cilium` | 1 | 0.968531 | 1/0 | 0 |
| `katran` | 1 | 1.023955 | 0/1 | 0 |
| `otelcol-ebpf-profiler` | 2 | 0.922175 | 2/0 | 0 |
| `tetragon` | 36 | 1.006081 | 17/19 | 0 |
| `tracee` | 72 | 1.033744 | 35/37 | 59 |

## Applied Coverage

| scope | total programs | bytes-applied | non-applied | applied share |
|---|---:|---:|---:|---:|
| Comparable per-program rows | 146 | 63 | 83 | 43.2% |
| All loaded BPF programs present in both phase snapshots | 519 | 126 | 393 | 24.3% |
| Comparable app cases | 21 | 5 with any applied | 16 with zero applied | 23.8% apps covered |
| All result app cases | 22 | 5 with any applied | 17 with zero applied | 22.7% apps covered |

This is the main coverage problem. The corpus now has broad app coverage, but the actual changed-code coverage is narrow. The applied rows are almost entirely tracee:

| app group | comparable programs | bytes-applied | applied geomean | non-applied geomean |
|---|---:|---:|---:|---:|
| all apps | 146 | 63 | 1.032346 | 0.982708 |
| tracee only | 72 | 59 | 1.0448 | 0.9852 |
| non-tracee | 74 | 4 | 0.8654 | 0.9822 |

The non-tracee applied set is too small to interpret as a corpus-wide optimization signal.

## Workload Stability

All app workload `ops_total` deltas are within the 10% stability threshold. The largest is `bcc/capable` at `+7.0%`; every other app is within about `1.4%`.

| app | baseline ops | post-ReJIT ops | diff | stable |
|---|---:|---:|---:|---|
| `bcc/capable` | 164024 | 175498 | +7.0% | yes |
| `bcc/execsnoop` | 345030 | 345030 | +0.0% | yes |
| `bcc/bindsnoop` | 157592 | 157170 | -0.3% | yes |
| `bcc/biosnoop` | 1966160 | 1967117 | +0.0% | yes |
| `bcc/vfsstat` | 247903 | 247749 | -0.1% | yes |
| `bcc/opensnoop` | 247902 | 247699 | -0.1% | yes |
| `bcc/syscount` | 174425 | 172845 | -0.9% | yes |
| `bcc/tcpconnect` | 156743 | 157619 | +0.6% | yes |
| `bcc/tcplife` | 157710 | 157737 | +0.0% | yes |
| `bcc/runqlat` | 345030 | 345030 | +0.0% | yes |
| `calico/felix` | 21458 | 21622 | +0.8% | yes |
| `otelcol-ebpf-profiler/profiling` | 60150 | 60150 | +0.0% | yes |
| `cilium/agent` | 22221 | 22488 | +1.2% | yes |
| `tetragon/observer` | 354832 | 354293 | -0.2% | yes |
| `katran` | 43904 | 43648 | -0.6% | yes |
| `tracee/monitor` | 186720 | 186720 | +0.0% | yes |
| `bpftrace/capable` | 172730 | 175178 | +1.4% | yes |
| `bpftrace/biosnoop` | 1966200 | 1966200 | +0.0% | yes |
| `bpftrace/vfsstat` | 247858 | 247877 | +0.0% | yes |
| `bpftrace/runqlat` | 345030 | 345030 | +0.0% | yes |
| `bpftrace/tcplife` | 157595 | 157256 | -0.2% | yes |
| `bpftrace/tcpretrans` | 158014 | 157428 | -0.4% | yes |

Per-program run counts are still not perfectly stable: `24/146` comparable programs have run-count deltas above 10%. However, the direction is not enough to explain the whole result:

| subset | programs | geomean | wins/losses |
|---|---:|---:|---:|
| run-count delta <=10% | 122 | 1.008245 | 66/56 |
| run-count delta >10% | 24 | 0.981668 | 15/9 |
| applied and run-count delta <=10% | 54 | 1.027597 | 27/27 |
| non-applied and run-count delta <=10% | 68 | 0.993138 | 39/29 |

This means app workload total is stable, but per-program activity mix still moves enough to add noise. Applied rows remain slower even in the run-count-stable subset.

## Regression Analysis

Only one app case has app geomean above `1.05`:

| app | geomean | programs | applied | workload diff | diagnosis |
|---|---:|---:|---:|---:|---|
| `bpftrace/tcplife` | 1.075643 | 1 | 0 | -0.2% | Not a ReJIT-code regression: `bytes_jited_delta=0`, app `changed=false`, run count stable (`352 -> 339`). It is a single non-applied program (`tcp_set_state`) moving from `1189.6 ns` to `1279.6 ns`; treat as measurement/runtime noise unless it repeats. |

No bytes-applied app crosses `1.05` at the app level. The important applied-code concern is tracee, even though its app geomean is only `1.033744`:

| tracee subset | programs | geomean | wins/losses |
|---|---:|---:|---:|
| all tracee comparable | 72 | 1.0337 | 35/37 |
| tracee applied | 59 | 1.0448 | 27/32 |
| tracee non-applied | 13 | 0.9852 | 8/5 |
| tracee applied, run-count delta <=10% | 51 | 1.0351 | 24/27 |
| tracee applied, run-count delta >10% | 8 | 1.1088 | 3/5 |

Tracee byte-delta buckets:

| tracee byte-delta bucket | programs | geomean | wins/losses |
|---|---:|---:|---:|
| positive delta | 7 | 1.0826 | 3/4 |
| small negative delta `-1..-40` | 38 | 1.0155 | 19/19 |
| medium negative delta `-41..-300` | 11 | 1.0981 | 4/7 |
| large negative delta `<-300` | 3 | 1.1487 | 1/2 |
| zero delta | 13 | 0.9852 | 8/5 |

From this artifact, the pass-level cause cannot be proven because successful per-program ReJIT diagnostics are not retained in `rejit_result`; the compact result keeps app-level status and final BPF stats. The observable root cause is that tracee's changed-code rows, especially medium and large native-size reductions, are not profitable under the unweighted per-program metric.

Top regressions:

| app | prog id | program | ratio | baseline/post ns | run cnt base/post | run cnt diff | bytes delta |
|---|---:|---|---:|---:|---:|---:|---:|
| `tracee/monitor` | 699 | `trace_ret_file_` | 2.166 | 131.6/285.0 | 24/24 | +0.0% | -40 |
| `tracee/monitor` | 703 | `trace_exec_binp` | 1.847 | 156.0/288.1 | 203/191 | +5.9% | -31 |
| `tracee/monitor` | 718 | `trace_security_` | 1.566 | 484.7/759.2 | 340/209 | +38.5% | -212 |
| `tracee/monitor` | 717 | `trace_security_` | 1.423 | 301.2/428.6 | 601/374 | +37.8% | -212 |
| `tracee/monitor` | 635 | `trace_security_` | 1.366 | 637.9/871.3 | 50/24 | +52.0% | -17 |
| `tracee/monitor` | 719 | `cgroup_bpf_run_` | 1.362 | 586.1/798.3 | 818/576 | +29.6% | -386 |
| `tetragon/observer` | 278 | `generic_kprobe_` | 1.348 | 1140.8/1537.3 | 228/440 | +93.0% | 0 |
| `tracee/monitor` | 697 | `trace_ret_file_` | 1.278 | 42.7/54.6 | 8697/8695 | +0.0% | +9 |
| `tracee/monitor` | 588 | `trace_dup3` | 1.220 | 279.1/340.6 | 66/30 | +54.5% | +2 |
| `tracee/monitor` | 595 | `tracepoint__sch` | 1.167 | 2253.9/2629.9 | 30413/30401 | +0.0% | +125 |

The top regression table is mixed. Some rows are stable and applied (`699`, `703`, `697`, `595`), which is a real signal. Others have large run-count movement (`718`, `717`, `635`, `719`, `278`, `588`), so their effect size is not reliable.

## Noise vs Real Difference

| subset | programs | geomean | wins/losses | interpretation |
|---|---:|---:|---:|---|
| all comparable | 146 | 1.003828 | 81/65 | Flat headline. |
| bytes-applied | 63 | 1.032346 | 31/32 | Changed-code rows are slower by unweighted per-program geomean. |
| non-applied | 83 | 0.982708 | 50/33 | No-byte-change rows are faster, proving the run has residual noise or phase effects. |
| bytes-applied, run-count stable | 54 | 1.027597 | 27/27 | Applied regression remains after removing large run-count deltas. |
| non-applied, run-count stable | 68 | 0.993138 | 39/29 | Non-applied rows move closer to neutral, but still not exactly `1.0`. |
| min run count <30 | 9 | 1.055817 | 5/4 | Low-count rows are noisy and skew worse. |
| min run count >=30 | 137 | 1.000503 | 76/61 | Most of the corpus is truly near-neutral. |

The non-applied geomean being `0.982708` is too far from `1.0` to treat the headline as purely optimization signal. But the applied subset is worse than the non-applied subset, including in the run-count-stable slice, so the result is not just noise either. The best current explanation is:

1. Broad workload execution is stable.
2. Most app cases have no changed code and contribute noise around neutral.
3. Tracee contributes most changed-code rows and those rows are mildly regressed by the official unweighted per-program metric.
4. The applied regression is not visible as a high-volume slowdown when weighting by run count; it is a per-program fairness metric issue plus tracee-specific changed-code profitability.

## Historical Comparison

The current `docs/kernel-jit-optimization-plan.md` does not contain a `1.054x overall` corpus line. It currently lists:

- v2 authoritative `#644`: applied-only/all-comparable geomean `1.033x`, applied sample `61`.
- Wave 1 x86 KVM `#663`: all-comparable geomean `1.010x`, applied sample `12`.

Those doc values appear to be speedup-style values where higher is better, while this result JSON uses `post/baseline` where lower is better. Converted to speedup, the latest run is `1 / 1.0038275637087666 = 0.9962x`.

| reference | metric as speedup | equivalent post/base | latest comparison |
|---|---:|---:|---|
| User-stated authoritative `1.054x overall` | 1.054 | 0.9488 | latest speedup `0.9962x`, about `5.5%` below that target |
| Current plan v2 `#644` | 1.033 | 0.9681 | latest speedup is about `3.6%` below |
| Current plan Wave 1 x86 `#663` | 1.010 | 0.9901 | latest speedup is about `1.4%` below |
| Latest JSON | 0.9962 | 1.0038 | essentially flat, slightly slower |

Same-schema artifact comparison:

| artifact | generated | samples | app ok/total | programs | geomean post/base | wins/losses | comparable applied | applied gm | non-applied gm | note |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---|
| Earliest `1.125` | `2026-04-28T02:26:47Z` | 1 | 20/22 | 157 | 1.125382 | 47/110 | 74 | 1.1562 | 1.0986 | Bad run: both applied and non-applied regressed; previous analysis showed major workload/run-count instability. |
| Previous `0.9714` | `2026-04-28T06:19:19Z` | 30 | 8/22 | 78 | 0.971421 | 20/58 | 55 | 0.9838 | 0.9425 | Not directly comparable: many app cases failed or produced no comparable rows; only 78 programs. |
| Latest `1.0038` | `2026-04-28T09:00:19Z` | 30 | 21/22 | 146 | 1.003828 | 81/65 | 63 | 1.0323 | 0.9827 | Much cleaner app coverage and stable workload ops, but changed-code subset regresses. |

Interpretation:

- Versus `1.125`: the latest run is much better (`-10.77%` in post/base geomean) and the severe non-applied regression disappeared.
- Versus `0.9714`: the latest run is worse by `+3.34%` in post/base geomean, but the previous run had only `8/22` app cases ok and only `78` programs. It should not be used as the primary baseline for a full-corpus conclusion.
- Versus authoritative speedup lines: latest is below target because it is not an improvement at all (`0.9962x` speedup).

## bpftrace Discovery Check

Latest bpftrace BPF programs discovered in the phase snapshots:

| app | loaded programs | comparable programs | bytes-applied |
|---|---:|---:|---:|
| `bpftrace/capable` | 1 | 1 | 0 |
| `bpftrace/biosnoop` | 2 | 2 | 0 |
| `bpftrace/vfsstat` | 2 | 2 | 0 |
| `bpftrace/runqlat` | 3 | 3 | 0 |
| `bpftrace/tcplife` | 1 | 1 | 0 |
| `bpftrace/tcpretrans` | 1 | 0 | 0 |
| total | 10 | 9 | 0 |

Answer: yes, if "discovered" means BPF programs found in baseline/post snapshots, bpftrace discovered `10` programs, which is one more than the previous `9`. However, comparable measured bpftrace rows remain `9` because `bpftrace/tcpretrans` had baseline `run_cnt_delta=0` and post `run_cnt_delta=1`, so it is excluded from `per_program` by the required `run_cnt_delta > 0` rule.

This validates that removing the name-hint filter improved discovery coverage, but it did not increase bpftrace comparable performance coverage in this latest geomean.

## Root-Cause Conclusion

The latest corpus result is not limited by workload `ops_total` instability; the workload layer is stable in this artifact. The performance issue is a combination of:

1. Low applied coverage across apps: most app cases have no changed program bytes, so their rows mostly measure noise.
2. Tracee concentration: almost all comparable applied rows come from `tracee/monitor`.
3. Tracee changed-code profitability: tracee applied rows regress by `1.0448` unweighted geomean, and stable applied tracee rows still regress by `1.0351`.
4. Residual measurement noise: non-applied rows are `0.9827`, proving no-byte-change rows can move by around 1-2%.
5. Missing pass attribution in the compact result: without successful per-program pass records, the artifact can identify which programs changed and how much, but not which pass caused each changed program's regression.

For the next debugging run, preserve per-program ReJIT pass diagnostics for successful programs and focus on tracee rows with medium/large negative `bytes_jited_delta` (`trace_security_*`, `cgroup_bpf_run_*`, and `trace_ret_file_*`). The current data says the broad corpus harness is now stable enough to investigate optimization profitability, but the optimization coverage and tracee pass attribution are the blockers.

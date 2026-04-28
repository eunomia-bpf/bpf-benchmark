# Per-Program Corpus Performance Analysis - 2026-04-27

Source result:
`corpus/results/x86_kvm_corpus_20260428_021257_300217/details/result.json`

The result was generated at `2026-04-28T02:26:47Z`, which is 2026-04-27 in the local Vancouver timezone. This is the newest corpus `result.json` found by mtime under `corpus/results`.

Notes:

- The top-level result status is `error`, but it contains a complete `per_program` payload with 157 measured programs. The error comes from app-level failures such as `cilium/agent` BPF stats read failure and one `tracee/monitor` ReJIT `EINVAL`; these are not filtered out of the result.
- `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`. Values below 1.0 are faster after ReJIT.
- `applied` below means `bytes_jited_delta != 0` for the measured program or the app-level `rejit_result.changed == true`. This follows the requested classification. I also show `bytes-delta n` because app-level `changed=true` is coarser than per-program byte diffs.
- `run_cnt >10%` means `abs(post_rejit_run_cnt_delta - baseline_run_cnt_delta) / baseline_run_cnt_delta > 0.10`.

## Headline

| group | programs | geomean | wins | losses | interpretation |
|---|---:|---:|---:|---:|---|
| all measured programs | 157 | 1.125 | 47 | 110 | 12.5% slower overall |
| applied, app-changed or byte-delta | 95 | 1.172 | 22 | 73 | 17.2% slower |
| direct `bytes_jited_delta != 0` only | 74 | 1.156 | 18 | 56 | 15.6% slower |
| unchanged | 62 | 1.058 | 25 | 37 | 5.8% slower |
| applied with run_cnt within 10% | 67 | 1.157 | 17 | 50 | still slower with stable run counts |
| unchanged with run_cnt within 10% | 18 | 1.065 | 5 | 13 | baseline noise also trends slower |

Answer to the core performance question: this run does not show a ReJIT performance improvement. The applied group has geomean `1.172`, so it is slower, not faster. Because unchanged programs also regress (`1.058`), part of the movement is measurement/workload noise, but applied programs regress more than unchanged programs even when run counts are within 10%.

## Per-App Summary

| app | n | geomean | wins/losses | applied n | applied geomean | unchanged n | unchanged geomean | bytes-delta n | run_cnt >10% |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc/bindsnoop | 2 | 0.970 | 1/1 | 2 | 0.970 | 0 |  | 1 | 0 |
| bcc/biosnoop | 3 | 2.029 | 0/3 | 3 | 2.029 | 0 |  | 1 | 3 |
| bcc/capable | 1 | 0.860 | 1/0 | 1 | 0.860 | 0 |  | 1 | 1 |
| bcc/execsnoop | 2 | 1.888 | 0/2 | 0 |  | 2 | 1.888 | 0 | 0 |
| bcc/opensnoop | 3 | 1.150 | 0/3 | 0 |  | 3 | 1.150 | 0 | 2 |
| bcc/runqlat | 3 | 0.935 | 3/0 | 3 | 0.935 | 0 |  | 1 | 2 |
| bcc/syscount | 2 | 0.985 | 2/0 | 0 |  | 2 | 0.985 | 0 | 2 |
| bcc/tcpconnect | 2 | 1.386 | 0/2 | 0 |  | 2 | 1.386 | 0 | 2 |
| bcc/tcplife | 1 | 1.040 | 0/1 | 0 |  | 1 | 1.040 | 0 | 1 |
| bcc/vfsstat | 3 | 1.072 | 0/3 | 0 |  | 3 | 1.072 | 0 | 3 |
| bpftrace/biosnoop | 2 | 0.945 | 1/1 | 0 |  | 2 | 0.945 | 0 | 2 |
| bpftrace/capable | 1 | 0.665 | 1/0 | 0 |  | 1 | 0.665 | 0 | 1 |
| bpftrace/runqlat | 3 | 1.025 | 0/3 | 0 |  | 3 | 1.025 | 0 | 0 |
| bpftrace/tcplife | 1 | 0.855 | 1/0 | 0 |  | 1 | 0.855 | 0 | 1 |
| bpftrace/vfsstat | 2 | 0.967 | 1/1 | 0 |  | 2 | 0.967 | 0 | 2 |
| katran | 1 | 0.927 | 1/0 | 0 |  | 1 | 0.927 | 0 | 1 |
| otelcol-ebpf-profiler/profiling | 2 | 0.580 | 2/0 | 0 |  | 2 | 0.580 | 0 | 2 |
| tetragon/observer | 37 | 1.077 | 16/21 | 0 |  | 37 | 1.077 | 0 | 25 |
| tracee/monitor | 86 | 1.168 | 17/69 | 86 | 1.168 | 0 |  | 70 | 22 |

Main contributors:

- `tracee/monitor` dominates the row count: 86/157 measured programs, geomean `1.168`, and 69 losses.
- `tetragon/observer` has no code byte deltas in the measured programs but still has geomean `1.077`; this is evidence of workload or measurement movement independent of ReJIT code changes.
- The worst app-level geomean is `bcc/biosnoop` at `2.029`, but all three rows have unstable run counts and very small BPF run counts, so the magnitude is not reliable.

## Top 10 Regressions

| app | prog id | program | ratio | run_cnt base/post | avg ns base/post | run_cnt diff | applied | bytes_jited_delta |
|---|---:|---|---:|---:|---:|---:|---|---:|
| tracee/monitor | 645 | `vfs_writev_magi` | 5.332 | 6/6 | 36.2/192.8 | +0.0% | yes | 0 |
| bcc/biosnoop | 20 | `trace_req_compl` | 4.933 | 29/7 | 298.1/1470.9 | -75.9% | yes | -2 |
| tetragon/observer | 480 | `generic_retkprobe_event` | 2.952 | 5898/9053 | 50.4/148.7 | +53.5% | no | 0 |
| bcc/execsnoop | 10 | `do_ret_sys_exec` | 2.819 | 2/2 | 91.0/256.5 | +0.0% | no | 0 |
| tetragon/observer | 317 | `generic_retkprobe_event` | 2.798 | 5898/9053 | 53.1/148.5 | +53.5% | no | 0 |
| tetragon/observer | 289 | `generic_retkprobe_event` | 2.564 | 5898/9053 | 48.6/124.5 | +53.5% | no | 0 |
| tracee/monitor | 647 | `vfs_writev_magi` | 2.415 | 6/6 | 229.3/553.8 | +0.0% | yes | -754 |
| tracee/monitor | 703 | `trace_exec_binp` | 2.139 | 4/4 | 148.8/318.2 | +0.0% | yes | -31 |
| tracee/monitor | 717 | `trace_security_` | 2.115 | 13/21 | 186.8/395.2 | +61.5% | yes | -212 |
| tracee/monitor | 644 | `trace_vfs_write` | 2.045 | 6/6 | 269.2/550.5 | +0.0% | yes | 0 |

The top regressions are mixed. Six are in applied apps, four are unchanged. Seven of the ten have very low minimum run counts below 30, and five of the ten have run count deltas above 10%. The individual extreme ratios should not be treated as precise effect sizes.

## Top 10 Improvements

| app | prog id | program | ratio | run_cnt base/post | avg ns base/post | run_cnt diff | applied | bytes_jited_delta |
|---|---:|---|---:|---:|---:|---:|---|---:|
| otelcol-ebpf-profiler/profiling | 131 | `tracepoint__sch` | 0.341 | 2/1 | 4533.5/1544.0 | -50.0% | no | 0 |
| bpftrace/capable | 734 | `cap_capable` | 0.665 | 66107/72812 | 206.5/137.3 | +10.1% | no | 0 |
| tracee/monitor | 719 | `cgroup_bpf_run_` | 0.680 | 5/21 | 1171.6/796.9 | +320.0% | yes | -386 |
| tetragon/observer | 455 | `generic_kprobe_` | 0.729 | 363/1059 | 1626.8/1186.4 | +191.7% | no | 0 |
| tracee/monitor | 658 | `trace_ret_vfs_r` | 0.733 | 6/6 | 2033.7/1491.0 | +0.0% | yes | -31 |
| tetragon/observer | 495 | `generic_kprobe_` | 0.733 | 4/4 | 3405.2/2497.5 | +0.0% | no | 0 |
| tetragon/observer | 525 | `generic_kprobe_` | 0.748 | 4/4 | 3777.2/2825.5 | +0.0% | no | 0 |
| tetragon/observer | 494 | `generic_kprobe_` | 0.791 | 11/15 | 2102.0/1662.0 | +36.4% | no | 0 |
| bpftrace/vfsstat | 748 | `vfs_create` | 0.802 | 135694/157414 | 62.2/49.9 | +16.0% | no | 0 |
| bpftrace/biosnoop | 740 | `block_io_start` | 0.825 | 57/954 | 851.2/702.5 | +1573.7% | no | 0 |

The top improvements are even more noise-heavy: only two are applied by the requested definition, seven have run count deltas above 10%, and six have minimum run counts below 30.

## Run Count Consistency

| run count group | programs | geomean | wins | losses | median ratio |
|---|---:|---:|---:|---:|---:|
| `run_cnt` delta >10% | 72 | 1.112 | 25 | 47 | 1.066 |
| `run_cnt` delta <=10% | 85 | 1.137 | 22 | 63 | 1.030 |

Ratio distribution for the 72 programs with run count delta >10%:

| ratio bucket | programs |
|---|---:|
| `<0.50` | 1 |
| `0.50-0.80` | 4 |
| `0.80-0.95` | 13 |
| `0.95-1.05` | 14 |
| `1.05-1.20` | 23 |
| `1.20-2.00` | 12 |
| `>=2.00` | 5 |

The run count instability is large: 72/157 programs, or 45.9%, differ by more than 10%. However, stable-run-count programs are not cleanly improved either; their geomean is worse (`1.137`) than the unstable group (`1.112`). This means run count skew explains many extreme rows, but not the whole regression signal.

Low-count programs are a separate problem. Programs with `min(baseline_run_cnt_delta, post_rejit_run_cnt_delta) < 30` have geomean `1.210` across 65 rows, while the remaining 92 rows have geomean `1.069`. Most of the largest apparent effects come from low-count rows.

## Stress-ng Workload Consistency

| app | workload | ops base/post | ops diff | duration s base/post |
|---|---|---:|---:|---:|
| bcc/capable | stress_ng_os | 35639/53479 | +50.1% | 8.08/6.05 |
| bcc/execsnoop | stress_ng_process | 240549/313827 | +30.5% | 1.05/1.05 |
| bcc/bindsnoop | stress_ng_network | 7662464/13198956 | +72.3% | 1.13/1.13 |
| bcc/vfsstat | stress_ng_filesystem | 43439/35823 | -17.5% | 2.98/3.04 |
| bcc/opensnoop | stress_ng_filesystem | 47911/35938 | -25.0% | 2.95/2.91 |
| bcc/syscount | stress_ng_os | 48195/45347 | -5.9% | 5.09/4.08 |
| bcc/tcpconnect | stress_ng_network | 9643553/11878094 | +23.2% | 1.11/1.14 |
| bcc/tcplife | stress_ng_network | 11556544/8237339 | -28.7% | 1.22/1.08 |
| bcc/runqlat | stress_ng_scheduler | 319421/251602 | -21.2% | 1.05/1.03 |
| otelcol-ebpf-profiler/profiling | stress_ng_cpu | 2005/2005 | +0.0% | 0.80/0.72 |
| tetragon/observer | stress_ng_os_io_network | 3053376/10620637 | +247.8% | 7.33/13.17 |
| tracee/monitor | stress_ng_os | 246908/251408 | +1.8% | 10.05/10.27 |
| bpftrace/capable | stress_ng_os | 56484/49990 | -11.5% | 9.20/11.10 |
| bpftrace/vfsstat | stress_ng_filesystem | 37245/46423 | +24.6% | 3.07/3.26 |
| bpftrace/runqlat | stress_ng_scheduler | 298453/250131 | -16.2% | 1.05/1.04 |
| bpftrace/tcplife | stress_ng_network | 17255192/18298872 | +6.0% | 1.08/1.16 |
| bpftrace/tcpretrans | stress_ng_network | 50109672/62071524 | +23.9% | 5.13/5.12 |

Stress-ng is not stable in this run. Among 17 stress-ng workload entries, 13 differ by more than 10% in total ops between baseline and post-ReJIT. Median absolute ops delta is 23.2%. The largest delta is `tetragon/observer` at +247.8%, and that app has no measured code byte deltas, which strongly points to workload/runtime variation.

`tracee/monitor` is the important exception: its stress-ng ops are close (+1.8%) and duration is close (10.05s vs 10.27s). Tracee still regresses (`1.168` geomean, 69/86 losses), so tracee is the strongest candidate for a real ReJIT-related regression. The exact per-program extremes inside tracee are still shaky because many of the worst rows have very small run counts.

## Interpretation

ReJIT does not show a performance win in this latest corpus run. The applied group is slower by geomean, and the direct byte-delta subset is also slower.

The regression is not all one thing:

- Real ReJIT signal: applied/direct-byte-delta programs regress more than unchanged programs, and applied programs remain slower even when `run_cnt` is within 10%.
- Measurement noise: unchanged programs also regress, the top improvements/regressions include many unchanged programs, and nearly half the programs have `run_cnt` deltas above 10%.
- Low sample counts: 65/157 programs have fewer than 30 runs in either baseline or post-ReJIT, and those rows dominate the most extreme ratios.
- Workload instability: stress-ng total ops are not stable for most apps, so app-to-app conclusions from a single run should be treated cautiously.

Most actionable follow-up: rerun with stronger workload normalization or repeated trials, then compare the applied direct-byte-delta subset, especially `tracee/monitor`, against the unchanged subset from the same run. A single-run top-10 table is useful for triage, but not sufficient to claim precise per-program speedups or slowdowns.

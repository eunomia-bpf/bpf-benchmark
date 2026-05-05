# Performance analysis: kinsn, wide_mem, map_inline (2026-05-05)

Inputs were the three on-disk result directories named in the task. I did not run benchmarks or modify framework code. The two SAMPLES=30 inputs are analyzed as historical runs; the current SAMPLES cap is 3, and SAMPLES=1 remains paper-grade legitimate when the per-program `min_runs >= 100` filter passes.

Method: for each program with both baseline and post-ReJIT counters, `baseline_avg = baseline.run_time_ns_delta / baseline.run_cnt_delta`, `post_avg = post_rejit.run_time_ns_delta / post_rejit.run_cnt_delta`, and `ratio = post_avg / baseline_avg`; lower is better. Programs with either run count at zero are non-comparable. The paper-grade retained set applies the mandatory `min(baseline_runs, post_rejit_runs) >= 100` filter from `CLAUDE.md`.

Applied counts below mean successful per-program ReJIT/pass records with `sites_applied > 0`; failed ReJIT attempts are counted as failed, not applied. Run #2 uses the legacy equivalent `passes[].sites_applied`, while run #3 uses `passes[].bpfopt_summary.sites_applied`.

## kinsn-only authoritative

- Source: `corpus/results/x86_kvm_corpus_20260505_011150_328270/metadata.json`, `corpus/results/x86_kvm_corpus_20260505_011150_328270/details/result.json`, `corpus/results/x86_kvm_corpus_20260505_011150_328270/details/apps/*.json`
- Suite/status: `corpus` / `error` (result status `error`)
- Pass set + samples: `['kinsn']`; samples `30`; workload_seconds `1.0`
- Programs: 0 comparable / 0 retained after min_runs >= 100 (0 raw baseline/post program ids)
- Programs applied / failed: 0 successful applied programs (0 sites) / 0 failed programs; app failures: 1
- App failure(s): `calico/felix`

| Population | Programs | Method B geomean ratio | Geomean speedup | Method C aggregate ratio | Aggregate speedup | wins/losses/ties |
|---|---:|---:|---:|---:|---:|---:|
| applied + retained | 0 | N/A | N/A | N/A | N/A | 0/0/0 |
| all retained | 0 | N/A | N/A | N/A | N/A | 0/0/0 |

This kinsn run is not numerically usable as a kinsn-only authoritative result: the directory contains only `details/apps/calico__felix.json`, that app failed before baseline/post counters were collected, and `details/result.json` has an empty top-level `per_program` list. All Method B/Method C values are therefore `N/A` rather than zero-speedup results.

Per-app breakdown:

| app | progs | comparable | retained | applied | applied_sites | failed | geomean_applied | geomean_all_retained |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| calico/felix | 0 | 0 | 0 | 0 | 0 | 0 | N/A | N/A |

## wide_mem-only authoritative

- Source: `corpus/results/x86_kvm_corpus_20260505_012029_594221/metadata.json`, `corpus/results/x86_kvm_corpus_20260505_012029_594221/details/result.json`, `corpus/results/x86_kvm_corpus_20260505_012029_594221/details/apps/*.json`
- Suite/status: `corpus` / `completed` (result status `ok`)
- Pass set + samples: `['wide_mem']`; samples `30`; workload_seconds `1.0`
- Programs: 157 comparable / 127 retained after min_runs >= 100 (535 raw baseline/post program ids)
- Programs applied / failed: 204 successful applied programs (1211 sites) / 45 failed programs; app failures: 0

| Population | Programs | Method B geomean ratio | Geomean speedup | Method C aggregate ratio | Aggregate speedup | wins/losses/ties |
|---|---:|---:|---:|---:|---:|---:|
| applied + retained | 33 | 1.079309 | 0.927x | 1.015124 | 0.985x | 8/20/5 |
| all retained | 127 | 1.249066 | 0.801x | 1.243788 | 0.804x | 24/91/12 |

Per-app breakdown:

| app | progs | comparable | retained | applied | applied_sites | failed | geomean_applied | geomean_all_retained |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc/bindsnoop | 3 | 2 | 0 | 0 | 0 | 0 | N/A | N/A |
| bcc/biosnoop | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 1.052051 |
| bcc/capable | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 0.998190 |
| bcc/execsnoop | 2 | 2 | 0 | 0 | 0 | 0 | N/A | N/A |
| bcc/opensnoop | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 1.034639 |
| bcc/runqlat | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 0.997039 |
| bcc/syscount | 2 | 2 | 2 | 0 | 0 | 0 | N/A | 0.988372 |
| bcc/tcpconnect | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 0.945875 |
| bcc/tcplife | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 1.026860 |
| bcc/vfsstat | 5 | 5 | 5 | 0 | 0 | 0 | N/A | 0.897031 |
| bpftrace/biosnoop | 2 | 2 | 2 | 1 | 4 | 0 | 1.002944 | 1.003180 |
| bpftrace/capable | 1 | 1 | 1 | 1 | 6 | 0 | 1.011529 | 1.011529 |
| bpftrace/runqlat | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 0.995192 |
| bpftrace/tcplife | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 0.983791 |
| bpftrace/tcpretrans | 1 | 1 | 0 | 1 | 3 | 0 | N/A | N/A |
| bpftrace/vfsstat | 2 | 2 | 1 | 0 | 0 | 0 | N/A | 1.056650 |
| cilium/agent | 38 | 4 | 1 | 0 | 0 | 1 | N/A | 1.093048 |
| katran | 3 | 2 | 1 | 1 | 4 | 0 | N/A | 1.001869 |
| otelcol-ebpf-profiler/profiling | 13 | 2 | 1 | 1 | 132 | 0 | N/A | 1.075738 |
| tetragon/observer | 287 | 34 | 27 | 192 | 883 | 44 | 0.997837 | 0.993433 |
| tracee/monitor | 158 | 80 | 68 | 7 | 179 | 0 | 1.531716 | 1.524644 |

## noop+map_inline today

- Source: `corpus/results/x86_kvm_corpus_20260505_173741_854355/metadata.json`, `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/result.json`, `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/apps/*.json`
- Suite/status: `corpus` / `completed` (result status `ok`)
- Pass set + samples: `['noop', 'map_inline']`; samples `1`; workload_seconds `3.0`
- Programs: 151 comparable / 127 retained after min_runs >= 100 (516 raw baseline/post program ids)
- Programs applied / failed: 36 successful applied programs (1598 sites) / 81 failed programs; app failures: 0

| Population | Programs | Method B geomean ratio | Geomean speedup | Method C aggregate ratio | Aggregate speedup | wins/losses/ties |
|---|---:|---:|---:|---:|---:|---:|
| applied + retained | 3 | 0.980383 | 1.020x | 1.016700 | 0.984x | 1/1/1 |
| all retained | 127 | 0.993047 | 1.007x | 0.983589 | 1.017x | 56/54/17 |

Map-inline retained/applied programs used for the headline applied-only Method B number:

| app | prog_id | program | applied_sites | baseline_runs | post_runs | min_runs | ratio |
|---|---:|---|---:|---:|---:|---:|---:|
| cilium/agent | 158 | `cil_from_netdev` | 26 | 1164 | 1366 | 1164 | 0.909120 |
| otelcol-ebpf-profiler/profiling | 55 | `native_tracer_entry` | 30 | 7952 | 7943 | 7943 | 0.997743 |
| tracee/monitor | 518 | `tracepoint__sched__sched_process_fork` | 1 | 7752 | 7486 | 7486 | 1.038839 |

Note: the run has 36 successful map_inline-applied programs and 1598 successful sites overall (otelcol 1192/13, cilium 275/18, tracee 131/5), but only 3 of those programs satisfy `min_runs >= 100`. The other successful applied programs are mostly zero-run under this workload, so they cannot enter the paper-grade ratio population.

Per-app breakdown:

| app | progs | comparable | retained | applied | applied_sites | failed | geomean_applied | geomean_all_retained |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc/biosnoop | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 1.003104 |
| bcc/capable | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 0.979292 |
| bcc/opensnoop | 3 | 3 | 3 | 0 | 0 | 0 | N/A | 0.910179 |
| bcc/runqlat | 3 | 3 | 2 | 0 | 0 | 0 | N/A | 0.968835 |
| bcc/syscount | 2 | 2 | 2 | 0 | 0 | 0 | N/A | 1.071635 |
| bcc/tcpconnect | 3 | 2 | 2 | 0 | 0 | 0 | N/A | 0.967079 |
| bcc/tcplife | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 0.999428 |
| bcc/vfsstat | 5 | 5 | 5 | 0 | 0 | 0 | N/A | 0.854741 |
| bpftrace/biosnoop | 2 | 2 | 2 | 0 | 0 | 0 | N/A | 1.000737 |
| bpftrace/capable | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 1.074783 |
| bpftrace/runqlat | 3 | 3 | 2 | 0 | 0 | 0 | N/A | 1.159785 |
| bpftrace/tcplife | 1 | 1 | 1 | 0 | 0 | 0 | N/A | 0.801353 |
| bpftrace/vfsstat | 2 | 2 | 1 | 0 | 0 | 0 | N/A | 1.026630 |
| cilium/agent | 25 | 4 | 1 | 18 | 275 | 3 | 0.909120 | 0.909120 |
| katran | 3 | 1 | 1 | 0 | 0 | 0 | N/A | 0.957113 |
| otelcol-ebpf-profiler/profiling | 13 | 2 | 1 | 13 | 1192 | 0 | 0.997743 | 0.997743 |
| tetragon/observer | 287 | 34 | 28 | 0 | 0 | 44 | N/A | 0.966407 |
| tracee/monitor | 158 | 81 | 70 | 5 | 131 | 34 | 1.038839 | 1.015960 |

## Final synthesis

### Cross-pass comparison

| Run | Pass set | Samples | Status | Retained/applied programs | Method B geomean ratio | Method C aggregate ratio | All-retained Method B |
|---|---|---:|---|---:|---:|---:|---:|
| kinsn-only authoritative | `['kinsn']` | 30 | error | 0 | N/A | N/A | N/A |
| wide_mem-only authoritative | `['wide_mem']` | 30 | completed | 33 | 1.079309 | 1.015124 | 1.249066 |
| noop+map_inline today | `['noop', 'map_inline']` | 1 | completed | 3 | 0.980383 | 1.016700 | 0.993047 |

### Top contributors

None. No retained-and-applied program in these specified runs has `ratio < 0.7`.

### Top regressions

| run | app | prog_id | program | sites | min_runs | ratio |
|---|---|---:|---|---:|---:|---:|
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 654 | `cgroup_skb_egress` | 82 | 33839829 | 1.660881 |
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 574 | `vfs_write_magic_return` | 3 | 15537601 | 1.596579 |
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 653 | `cgroup_skb_ingress` | 82 | 6830227 | 1.575902 |
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 553 | `trace_security_file_open` | 3 | 11522222 | 1.467520 |
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 595 | `trace_security_mmap_file` | 3 | 218932 | 1.458354 |
| x86_kvm_corpus_20260505_012029_594221 | tracee/monitor | 579 | `vfs_writev_magic_return` | 3 | 784 | 1.443993 |

### Answers

- Map_inline applied-program question: after the mandatory min_runs filter, run #3 has 3 retained-and-applied programs, not 36. Their Method B geomean ratio is 0.980383 (1.020x geomean speedup), while Method C over the same population is 1.016700 (0.984x). The signal is mixed: Method B says about 2.0% faster per retained applied program, Method C says about 1.7% slower in run-weighted BPF time, and all-retained Method B is 0.993047 (1.007x). This run alone does not justify map_inline as a strong paper headline pass.
- Kinsn vs map_inline: the specified kinsn-only directory has no comparable program measurements, so the kinsn-vs-map_inline geomean comparison is not computable from the requested on-disk data. Among the analyzable runs here, map_inline is better than wide_mem on the retained/applied Method B metric: map_inline `0.980383` vs wide_mem `1.079309`.

### Recommendation

No pass deserves a strong paper headline number from these three directories alone. Map_inline is the best candidate among the analyzable data because it is the only pass set with an applied-only Method B ratio below 1.0, but the retained applied population is only 3 programs and Method C disagrees. Wide_mem alone regresses on both applied-only and all-retained Method B, and the named kinsn-only run failed before measurements.

### Open questions / data gaps

- Need a valid kinsn-only corpus run on the current supported app set; the specified kinsn run stopped at removed/unsupported `calico/felix`.
- Need a 12-pass cumulative run to measure pass interaction instead of isolated wide_mem/map_inline behavior.
- Need ARM64 data for map_inline/kinsn comparison.
- Need workload coverage that drives map_inline-applied programs: run #3 applies 1598 successful sites, but only 3 successful applied programs survive the `min_runs >= 100` filter.
- Need to account for per-program failures before headline use: run #3 has 81 failed programs, including 44 Tetragon noop ReJIT failures and Tracee map snapshot failures; run #2 has 45 failed programs.

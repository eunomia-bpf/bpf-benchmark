# Full Authoritative Rerun (2026-03-20)

## Scope

Task `#256`: full post-cleanup authoritative rerun from clean state.

Commands executed:

- `source /home/yunwei37/workspace/.venv/bin/activate`
- `make clean`
- `make all`
- `make kernel`
- `make check`
- `make vm-selftest`
- `make vm-micro ITERATIONS=10 WARMUPS=5 REPEAT=1000`
- `make vm-corpus REPEAT=500`
- `make vm-e2e`
- `cp micro/results/dev/vm_micro.json micro/results/vm_micro_authoritative_20260320.json`
- `cp corpus/results/dev/vm_corpus.json corpus/results/corpus_authoritative_20260320.json`
- `python3 micro/summarize_rq.py --results micro/results/dev/vm_micro.json`

Build and validation status:

- `make all`: pass
- `make kernel`: pass
- `make check`: pass
- `make vm-selftest`: `27/27` pass

Guest kernel throughout the VM runs: `7.0.0-rc2-g4c74965a2e97`

## Micro Rerun

Artifact:

- `micro/results/dev/vm_micro.json`
- authoritative copy: `micro/results/vm_micro_authoritative_20260320.json`
- generated at: `2026-03-20T17:11:49.026733+00:00`
- policy hash: `667ed0873980368f`

### Pure-JIT Characterization (`llvmbpf/kernel`)

`python3 micro/summarize_rq.py --results micro/results/dev/vm_micro.json` reports:

| Metric | Value |
| --- | ---: |
| Raw geomean | `0.580743x` |
| Baseline-adjusted geomean | `0.651534x` |
| Baseline-adjusted 95% CI | `[0.584473x, 0.723402x]` |
| Raw wins (`llvmbpf/kernel/tie`) | `57 / 3 / 2` |
| Adjusted wins (`llvmbpf/kernel/tie`) | `46 / 5 / 4` |
| Adjusted-ratio benchmark count | `55` |

### BpfReJIT Summary (`kernel/kernel-recompile`)

Ratio direction below is `kernel median exec_ns / kernel-recompile median exec_ns`.

| Metric | Value |
| --- | ---: |
| Benchmarks | `62` |
| Overall geomean | `1.057197x` |
| Applied-only geomean | `1.192666x` |
| Non-applied geomean | `1.041098x` |
| Applied benchmarks | `7` |
| Result mismatches | `0` |
| Applied regressions | `2` |

Applied benchmark breakdown:

| Benchmark | Sites | Kernel ns | Recompile ns | Ratio | Status |
| --- | ---: | ---: | ---: | ---: | --- |
| `cmov_dense` | `26` | `49.5` | `52.5` | `0.942857x` | regression |
| `bounds_ladder` | `4` | `139.0` | `131.0` | `1.061069x` | win |
| `large_mixed_500` | `7` | `429.0` | `400.0` | `1.072500x` | win |
| `large_mixed_1000` | `7` | `801.0` | `767.5` | `1.043648x` | win |
| `bpf_call_chain` | `2` | `308.5` | `311.5` | `0.990369x` | regression |
| `rotate64_hash` | `116` | `78.0` | `34.0` | `2.294118x` | win |
| `rotate_dense` | `256` | `170.0` | `126.0` | `1.349206x` | win |

Observations:

- No output mismatches were observed in any runtime sample.
- The applied set is still `7` benchmarks, but this rerun has `2` applied regressions (`cmov_dense`, `bpf_call_chain`).
- This fresh run materially differs from `docs/tmp/micro_authoritative_post_simplification_20260319.md` despite the same policy hash. Previous note: overall `1.003942x`, applied-only `1.151824x`, applied regressions `0`. Fresh authoritative rerun: overall `1.057197x`, applied-only `1.192666x`, applied regressions `2`.

## Corpus Rerun

Artifact:

- `corpus/results/dev/vm_corpus.json`
- `corpus/results/dev/vm_corpus.md`
- authoritative copy: `corpus/results/corpus_authoritative_20260320.json`
- generated at: `2026-03-20T18:02:02.071942+00:00`

### Suite Summary

Ratio direction below is `stock / recompile`.

| Metric | Value |
| --- | ---: |
| Targets attempted | `152` |
| Compile pairs | `150` |
| Measured pairs | `93` |
| Applied programs | `26` |
| Overall exec geomean | `0.982603x` |
| Applied-only exec geomean | `0.946786x` |
| Non-applied exec geomean | `0.996864x` |
| Exec ratio median | `0.977975x` |
| Exec ratio min | `0.363636x` |
| Exec ratio max | `6.177966x` |
| Improvements | `24` |
| Regressions | `54` |
| Code-size geomean | `1.001995x` |
| Total sites | `1856` |
| CMOV sites | `426` |
| WIDE sites | `330` |
| EXTRACT sites | `54` |
| ENDIAN sites | `825` |
| BRANCH-FLIP sites | `221` |

### Per-Source Breakdown

| Source | Measured | Applied | Overall gmean | Applied-only gmean |
| --- | ---: | ---: | ---: | ---: |
| `calico` | `53` | `12` | `1.017423x` | `0.925731x` |
| `katran` | `2` | `0` | `0.894427x` | `n/a` |
| `libbpf-bootstrap` | `1` | `1` | `0.893939x` | `0.893939x` |
| `linux-selftests` | `23` | `5` | `0.918463x` | `0.958185x` |
| `real_world_code_size` | `1` | `1` | `0.887097x` | `0.887097x` |
| `suricata` | `1` | `0` | `1.000000x` | `n/a` |
| `tracee` | `2` | `2` | `0.960769x` | `0.960769x` |
| `xdp-tools` | `3` | `2` | `1.327724x` | `1.683251x` |
| `xdp-tutorial` | `7` | `3` | `0.878507x` | `0.713766x` |

### Same-Image Measurement Status

`stock_exec_ns` was only partially populated:

| Metric | Value |
| --- | ---: |
| Successful `v5_run` rows | `150` |
| Rows with `stock_exec_ns` present | `93` |
| Rows missing `stock_exec_ns` | `57` |

Conclusion: same-image measurement is working for the `93` measured pairs, but it is not complete across all successful `v5_run` rows.

### Failure Reasons

| Reason | Count |
| --- | ---: |
| `paired stock_exec_ns missing from run-kernel output` | `57` |
| `Segmentation fault (exit=139)` | `1` |
| `TypeError: sequence item 0: expected str instance, bytes found (exit=1)` | `1` |

### Notable Corpus Extremes

Top speedups:

| Program | Source | Ratio |
| --- | --- | ---: |
| `calico_tc_skb_new_flow_entrypoint` | `calico` | `6.177966x` |
| `calico_xdp_main` | `calico` | `2.833333x` |
| `xdp_fwd_fib_direct` | `xdp-tools` | `2.833333x` |

Worst regressions:

| Program | Source | Ratio |
| --- | --- | ---: |
| `xdp_redirect_func` | `xdp-tutorial` | `0.363636x` |
| `change_tail` | `linux-selftests` | `0.600000x` |
| `__encap_ip6gre_eth` | `linux-selftests` | `0.600000x` |

## E2E Rerun

### Execution Note

`make vm-e2e` did not finish cleanly:

- `tracee` ran successfully
- target then failed at `tetragon` with `make: *** [Makefile:437: vm-e2e] Error 255`

To finish the authoritative rerun, I reran the requested E2E cases directly inside `vng` with `--memory 4G --cpus 2` against the rebuilt `bzImage`:

- `tetragon`
- `bpftrace`
- `scx`

The root `vm-e2e` target currently also includes `katran`, but the task request scoped Step 4 to `tracee + tetragon + bpftrace + scx`, so the authoritative report below covers those four requested cases.

### Tracee

Artifact:

- `e2e/results/dev/tracee.json`
- `e2e/results/dev/tracee.md`
- generated at: `2026-03-20T18:09:45.664900+00:00`
- mode: `manual_fallback`

ReJIT coverage:

- applied programs: `4 / 4`
- applied sites: `24`

Workload results:

| Workload | Baseline app | Post app | App delta | Baseline BPF ns | Post BPF ns | BPF delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `exec_storm` | `219.920176` | `237.811466` | `+8.135356%` | `366.361810` | `352.290007` | `-3.840958%` |
| `file_io` | `1644897.942225` | `1642996.971005` | `-0.115568%` | `154.847276` | `221.326172` | `+42.931912%` |
| `network` | `6497.885621` | `6575.928075` | `+1.201044%` | `381.691028` | `382.426424` | `+0.192668%` |

Limitations:

- Tracee daemon was unavailable, so this run used manual BPF program loading from `corpus/build/tracee/tracee.bpf.o`.
- Agent event counts and drop counters are unavailable in fallback mode.
- Agent CPU is unavailable in fallback mode.

### Tetragon

Artifact:

- `e2e/results/dev/tetragon.json`
- `e2e/results/dev/tetragon.md`
- generated at: `2026-03-20T18:23:39.075153+00:00`
- mode: `tetragon_daemon`

ReJIT coverage:

- applied programs: `2 / 7`
- applied sites: `9`

Workload results:

| Workload | Baseline app | Post app | App delta | Baseline BPF ns | Post BPF ns | BPF delta |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `connect_storm` | `861.378012` | `1138.805086` | `+32.207355%` | `3058.285714` | `3013.142857` | `-1.476084%` |
| `file_io` | `1546873.650053` | `1562724.799471` | `+1.024722%` | `3223.461538` | `3411.000000` | `+5.817921%` |
| `open_storm` | `330833.570942` | `332082.690484` | `+0.377567%` | `2436.000000` | `2396.000000` | `-1.642036%` |
| `stress_exec` | `214.316811` | `257.906086` | `+20.338710%` | `2136.484342` | `2157.040539` | `+0.962151%` |

Recompile errors:

- `execve_rate` had a partial recompile failure: `BPF_PROG_JIT_RECOMPILE: Invalid argument`

### bpftrace

Artifact:

- `e2e/results/dev/bpftrace.json`
- `e2e/results/dev/bpftrace.md`
- generated at: `2026-03-20T18:26:43.825871+00:00`

Summary:

- baseline successes: `5`
- ReJIT successes: `0`
- scripts with sites: `3`
- total sites: `13` (`cmov=12`, `wide=0`, `rotate=0`, `lea=0`)
- speedup geomean: `n/a`
- applied scripts: `0`

Per-script outcomes:

| Script | Sites | Baseline ops/s | Baseline BPF ns | Applied | Outcome |
| --- | ---: | ---: | ---: | ---: | --- |
| `open_latency` | `6` | `145197.680558` | `144.337853` | `0` | `policy filtered all live sites` |
| `exec_trace` | `0` | `195.414785` | `229.576057` | `0` | `no eligible directive sites` |
| `scheduler_latency` | `6` | `53.026344` | `104.975198` | `0` | `policy filtered all live sites` |
| `vfs_read_count` | `0` | `642050.613781` | `34.223165` | `0` | `no eligible directive sites` |
| `tcp_connect` | `1` | `26.726816` | `193.779302` | `0` | `BPF_PROG_JIT_RECOMPILE did not apply` |

There are no app-throughput or BPF-runtime deltas to report because no script produced a successful post-ReJIT measurement.

### scx

Artifact:

- `e2e/results/dev/scx.json`
- `e2e/results/dev/scx.md`
- generated at: `2026-03-20T18:28:29.452524+00:00`
- mode: `scx_rusty_loader`

ReJIT coverage:

- applied programs: `0 / 13`
- site-bearing programs: `11`
- total sites: `213`
- site totals: `cmov=67`, `lea=1`, `rotate=0`, `wide=0`

Comparison status:

- comparable: `False`
- reason: `post-ReJIT measurements are unavailable`

Baseline-only workload snapshot:

| Workload | Throughput | Lat p50 ms | Lat p95 ms | Context switches/s | Agent CPU % | System CPU busy % |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `hackbench` | `2.282874` | `423.000000` | `435.000000` | `109814.117825` | `0.033333` | `97.365789` |
| `stress-ng-cpu` | `6047.680000` | `n/a` | `n/a` | `1231.580297` | `0.066665` | `99.450183` |
| `sysbench-cpu` | `9286.740000` | `0.430000` | `2.220000` | `1217.258543` | `0.033333` | `99.566667` |

Limitations:

- `bpftool struct_ops register` returned success but did not leave `sched_ext` enabled, so the standalone bpftool path is not usable here.
- bpftool did not expose per-program `run_cnt` / `run_time_ns` for these struct_ops programs on this kernel.
- `BPF_PROG_JIT_RECOMPILE` did not apply to any loaded `scx_rusty` struct_ops program on this kernel.

## Final Artifact Set

- `micro/results/dev/vm_micro.json`
- `micro/results/vm_micro_authoritative_20260320.json`
- `corpus/results/dev/vm_corpus.json`
- `corpus/results/corpus_authoritative_20260320.json`
- `e2e/results/dev/tracee.json`
- `e2e/results/dev/tetragon.json`
- `e2e/results/dev/bpftrace.json`
- `e2e/results/dev/scx.json`

## Bottom Line

- Build, check, and VM selftests all passed.
- Micro authoritative rerun is positive overall at `1.057197x`, with a stronger applied-only geomean of `1.192666x`, but `2` applied regressions remain.
- Corpus authoritative rerun is net negative overall at `0.982603x`; applied-only is more negative at `0.946786x`.
- Same-image corpus measurement is only partially working: `93/150` successful `v5_run` rows emitted `stock_exec_ns`.
- E2E results are mixed:
  - `tracee`: mostly positive app impact except `file_io`
  - `tetragon`: positive app throughput in all four workloads, mixed BPF runtime changes
  - `bpftrace`: no successful ReJIT application
  - `scx`: no successful ReJIT application

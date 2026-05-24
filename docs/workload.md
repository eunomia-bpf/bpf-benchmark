# Workload Tuning Log

Last updated: 2026-05-23.

This document records how the corpus workloads were changed, what was tried,
what was rejected, and which raw artifacts back each decision. The benchmark
framework must keep writing raw measurements only. Slowdown numbers in this
file are offline analysis results computed from saved workload stdout/stderr,
not framework-side summaries.

Slowdown convention:

```text
slowdown = 1 - mean(ebpf_no_state_workload_metric) / mean(no_ebpf_workload_metric)
```

For stress-ng workloads the offline metric is the sum of stress-ng
`bogo ops/s (real time)` rows. For pktgen workloads it is summed `pps`. For
OTEL it is summed interpreter loop `ops=` plus stress-ng bogo ops. Higher
slowdown means the eBPF application consumes a larger fraction of the workload
budget. The target for workload selection was at least 60% slowdown when
possible, because small eBPF overhead makes optimization speedups hard to
observe at the app-workload level.

## Current Workload Mapping

The current corpus has one selected workload per supported app. There is no
runtime workload-selection matrix in the framework.

| App | Current workload | Current status |
| --- | --- | --- |
| `bcc/set` | `stress_ng_bcc_hook_hot` | Runs and is close but still below 60% in the latest 60s x3 stats-off pair. |
| `tracee/monitor` | `stress_ng_tracee_syscall_hot` | Runs and reaches 60% in 60s x1 pairs; needs 60s x3 confirmation. |
| `tetragon/observer` | `stress_ng_tetragon_policy_hot` | Runs and reaches 60% in one 60s x1 pair, but earlier same-workload pair was much lower; needs 60s x3 confirmation. |
| `otelcol-ebpf-profiler/profiling` | `otel_mixed_workload` | Runs and reaches 60% in 60s x3 stats-off. |
| `katran` | `xdp_pktgen` | Runs and reaches 60% in the stable 4-thread pktgen candidate. |
| `cilium/agent` | `cilium_endpoint_pktgen` | Runs, but current stats-off slowdown is still below 60%. This remains the main workload gap. |

Current code locations:

- App mapping: `runner/libs/benchmark_catalog.py`
- Generic and app-specific workloads: `runner/libs/workload.py`
- Katran pktgen runner path: `runner/libs/app_runners/katran.py`
- OTEL profiler runner setup: `runner/libs/app_runners/otel_profiler.py`

## Git History Of Workload Changes

| Date | Commit | Change | Reason / result |
| --- | --- | --- | --- |
| 2026-04-27 | `986ec3eb` | Switched many old handwritten synthetic loops to standard tools: stress-ng, fio, and real network workloads. | Improve paper credibility and avoid custom benchmark generators where standard tools exist. |
| 2026-04-27 | `5edf29e4` | Expanded stress-ng workload coverage. | Raised BPF program triggering coverage before app-specific tuning. |
| 2026-05-04 | `56148a3d` | Ran stress-ng stressors concurrently instead of sequentially; moved Tracee from `stress_ng_os` to broader `stress_ng_os_io_network`; moved TCP tools to real `tcp_connect`. | Concurrent stressors made duration semantics sane and improved trigger density. |
| 2026-05-06 | `8d679044` | Replaced OTEL runner-internal language idlers and `noop` measurement with bounded `otel_mixed_workload`. Initial workload used SHA-256 loops in Python/Ruby/Node/Perl/PHP plus `stress-ng --cpu 1`. | Made OTEL workload a raw workload payload instead of hidden runner state. |
| 2026-05-07 | `db1564b4` | Removed per-app workload duration defaults; kept one global `WORKLOAD_DURATION`. | Avoided per-app duration tuning in the framework. |
| 2026-05-14 | `7e4a3838` | Added Katran `xdp_pktgen` support. | `wrk`/HTTP `xdp_traffic` was not BPF-dominant enough for Katran. |
| 2026-05-14 | `59b8e144` | Switched the main Katran app from `xdp_traffic` to `xdp_pktgen`. | Made pktgen the primary Katran workload instead of an extra variant. |
| 2026-05-22 | `50bf5e00` | Added app-specific hot stress-ng groups for BCC, Tetragon, and Tracee; switched those apps off generic `stress_ng_os_io_network`. | Generic coverage workload mixed too much non-BPF user/storage work into performance measurement. |
| 2026-05-22 | `9f9d57e4` | Narrowed BCC hot workload to `syscall`, `cap`, `set`, and `sockfd`. | Removed low-ratio file/block/scheduler stressors after measuring that they diluted BPF overhead. |
| 2026-05-22 | `361e40c9` | Switched Cilium from `network_lossy_multi` to `cilium_endpoint_pktgen`; added plain endpoint topology and kernel pktgen. | `network_lossy_multi` was dominated by HTTP, wrk, and netem latency, not Cilium datapath cost. |
| 2026-05-23 | `f04689b4` | Changed Cilium endpoint pktgen toward bidirectional traffic and varying UDP destination ports; kept `clone_skb=0`. | Tried to increase Cilium policy/CT/datapath work per packet. Reproducible slowdown remains below target. |
| 2026-05-23 | `d340a708` | Made composite workload parent records raw-only by removing derived parent `duration_s`, `returncode`, stdout, and stderr. | Result-format cleanup, not a workload-tuning change. Leaf component raw stdout/stderr remains available for offline analysis. |

## Experiment Artifacts And Results

All commands were run through `make corpus`; manifests below are only indexes
to raw `result.json` and app payloads.

### BCC

Goal: drive BCC probes with syscall/capability/set/socket-fd paths while
avoiding slow file/block/scheduler stressors that hide eBPF overhead.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| `workload_tune_stressapps_20260522_211432` | `stress_ng_bcc_hook_hot` early hot set | no-eBPF `x86_kvm_corpus_20260522_211742_883689`; eBPF no-state `x86_kvm_corpus_20260522_212048_090465` | 34.28% | First 60s x1 BCC hot test. |
| `workload_tune_60s_stressapps_20260522_212234` | `stress_ng_bcc_hook_hot` broad hot set | no-eBPF `x86_kvm_corpus_20260522_213601_930201`; eBPF no-state `x86_kvm_corpus_20260522_213958_976252` | 45.27% | Still included too much low-ratio work. |
| `workload_tune_60s_refined_20260522_215403` | refined BCC hot set | no-eBPF `x86_kvm_corpus_20260522_215705_145573`; eBPF no-state `x86_kvm_corpus_20260522_220057_857310` | 43.94% | Single-run result did not improve. |
| `workload_perf_coverage_60s_20260522_155307` | `stress_ng_bcc_hook_hot` | no-eBPF `x86_kvm_corpus_20260522_225556_087664`; eBPF no-state `x86_kvm_corpus_20260522_230217_359197` | 44.49% | 60s x3; eBPF CV 6.87%. |
| `workload_perf_bcc_hot4_60s_20260522_161113` | hot4 variant | no-eBPF `x86_kvm_corpus_20260522_231402_001368`; eBPF no-state `x86_kvm_corpus_20260522_231959_336238` | 44.71% | 60s x3; stable but below target. |
| `workload_perf_bcc_syscall_hot_60s_20260522_162712` | final narrow set: `syscall,cap,set,sockfd` | no-eBPF `x86_kvm_corpus_20260522_233010_504479`; eBPF no-state `x86_kvm_corpus_20260522_233558_916058` | 54.35% | Best current 60s x3; still below 60%. |

Coverage diagnostics:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260522_222339_442883` | `stress_ng_bcc_hook_hot` | 25 | 22 | 20 |
| `x86_kvm_corpus_20260522_234642_346506` | `stress_ng_bcc_hook_hot` | 25 | 17 | 16 |

Decision: keep `stress_ng_bcc_hook_hot` because it is the best current
BPF-heavy BCC workload, but mark BCC as not yet meeting the 60% workload target.

### Tracee

Goal: maximize all-events syscall/raw-tracepoint/LSM dispatch with cheap
syscall generators.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| `workload_tune_tracee_20260522_210536` | `stress_ng_tracee_syscall_hot` | no-eBPF `x86_kvm_corpus_20260522_210921_806671`; eBPF no-state `x86_kvm_corpus_20260522_211234_202742` | 86.14% | First 10s x1 smoke pair reached target. |
| `workload_tune_60s_stressapps_20260522_212234` | `stress_ng_tracee_syscall_hot` | no-eBPF `x86_kvm_corpus_20260522_212550_405856`; eBPF no-state `x86_kvm_corpus_20260522_212946_730185` | 85.88% | 60s x1 reached target. |

Coverage diagnostic:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260522_224455_947112` | `stress_ng_tracee_syscall_hot` | 167 | 63 | 41 |

Decision: keep `stress_ng_tracee_syscall_hot`. Remaining work is a 60s x3
confirmation pair.

### Tetragon

Goal: drive the bundled policy hooks with socket/datagram/eventfd/mmap paths.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| `workload_tune_60s_stressapps_20260522_212234` | `stress_ng_tetragon_policy_hot` | no-eBPF `x86_kvm_corpus_20260522_214505_834979`; eBPF no-state `x86_kvm_corpus_20260522_214926_162024` | 34.16% | First 60s x1 pair was below target. |
| `workload_tune_60s_refined_20260522_215403` | same policy-hot workload | no-eBPF `x86_kvm_corpus_20260522_220606_309552`; eBPF no-state `x86_kvm_corpus_20260522_221005_946299` | 64.59% | Later 60s x1 pair reached target, but the gap between the two x1 pairs means this needs x3 confirmation. |

Coverage diagnostic:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260522_223420_827419` | `stress_ng_tetragon_policy_hot` | 173 | 25 | 16 |

Decision: keep `stress_ng_tetragon_policy_hot`, but do not treat the 64.59%
number as final until a 60s x3 pair reproduces it.

### OTEL eBPF Profiler

Goal: make profiler overhead visible in workload throughput and ensure samples
hit both native and interpreter unwind paths.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| git before `8d679044` | runner-internal language idlers plus `noop` | no current pair used | n/a | Rejected because measurement work was hidden in app runner state rather than in raw workload payload. |
| `workload_perf_otel_10khz_60s_20260522_192516` | early profiler-frequency/intloop candidate | manifest only | n/a | Used while tuning profiler sampling pressure. |
| `workload_perf_otel_intloop_10khz_60s_20260522_193322` | `otel_mixed_workload`, low-frequency/intloop candidate | no-eBPF `x86_kvm_corpus_20260523_023621_211760`; eBPF no-state `x86_kvm_corpus_20260523_024233_560597` | 20.34% | Too little profiler pressure. |
| `workload_perf_otel_intloop_100khz_60s_20260522_195146` | `otel_mixed_workload`, higher sampling/intloop candidate | no-eBPF `x86_kvm_corpus_20260523_025542_000315`; eBPF no-state `x86_kvm_corpus_20260523_030252_187353` | 58.80% | Close but just below target. |
| final 60s x3 pair | current `otel_mixed_workload` with 2 workers per language | no-eBPF `x86_kvm_corpus_20260523_081204_776028`; eBPF no-state `x86_kvm_corpus_20260523_082356_404370` | 61.36% | Meets target. no-eBPF CV 1.46%, eBPF CV 2.89%. |

Coverage diagnostic:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260523_002121_691273` | `otel_mixed_workload` | 13 | 2 | 1 |

Coverage note: OTEL interpreter unwind programs are tail-call targets, so their
own `run_cnt_delta` stays zero even when they execute. Their cost is measured
through the attached caller `native_tracer_entry`.

Decision: keep `otel_mixed_workload`.

### Cilium

Goal: make the workload packet/datapath dominated. The original workload was
too much userspace HTTP and netem delay.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| `workload_stats_remaining_60s_20260522_171746` | old `network_lossy_multi` | stats artifact `x86_kvm_corpus_20260523_003100_940391` | n/a | Coverage-only run. This old workload was dominated by wrk/HTTP/netem. |
| `workload_perf_network_pktgen_60s_20260522_202935` | `network_pktgen_udp` shared network variant | manifest exists | n/a | Early high-pps candidate before endpoint-specific traffic. |
| `workload_perf_cilium_endpoint_pktgen_noclone_60s_20260522_210958` | endpoint pktgen, `clone_skb=0` | no-eBPF `x86_kvm_corpus_20260523_041339_638255`; eBPF no-state `x86_kvm_corpus_20260523_042014_476148` | 34.31% | Stable but below target. |
| `workload_perf_cilium_endpoint_pktgen_bidir_60s_20260522_212749` | bidirectional endpoint pktgen | no-eBPF `x86_kvm_corpus_20260523_043053_421385`; eBPF no-state `x86_kvm_corpus_20260523_043702_423340` | 46.77% | Better but still below target. |
| `workload_perf_cilium_endpoint_pktgen_bidir_threads_60s_20260522_214411` | bidirectional, separate pktgen threads | no-eBPF `x86_kvm_corpus_20260523_044714_736491`; eBPF no-state `x86_kvm_corpus_20260523_045322_149815` | 63.79% | Rejected as unstable: eBPF CV was 17.84% and later runs did not reproduce this level. |
| final stats-off reference | current `cilium_endpoint_pktgen` | no-eBPF `x86_kvm_corpus_20260523_102334_880171`; eBPF no-state `x86_kvm_corpus_20260523_104422_931622` | 32.28% | Stable 60s x3, but far below target. |
| latest stats-on no-rejit | current `cilium_endpoint_pktgen` | no-eBPF `x86_kvm_corpus_20260523_102334_880171`; stats-on app artifact `x86_kvm_corpus_20260523_205640_203233` | 42.13% baseline, 36.66% post | Stats-on includes BPF stats accounting overhead, so this is diagnostic only, not pure workload overhead. |

Coverage diagnostic:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260523_003100_940391` | old `network_lossy_multi` | 60 | 8 | 6 |
| `x86_kvm_corpus_20260523_203848_846964` | `cilium_endpoint_pktgen` stats-on | 26 | 8 | 2 |
| `x86_kvm_corpus_20260523_205640_203233` | `cilium_endpoint_pktgen` stats-on | 26 | 8 | 2 |

Decision: current Cilium workload is the best integrated endpoint pktgen path,
but it is not good enough for the 60% target. The issue is workload design, not
loadtime apply: the no-eBPF/eBPF-no-state gap is too small under stable runs.
The next tuning direction should reduce non-BPF pktgen/veth/netns overhead or
make Cilium do heavier per-packet datapath work without relying on BPF stats
accounting to inflate slowdown.

### Katran

Goal: avoid HTTP/wrk userspace bottlenecks and make XDP balancer cost visible.

| Experiment | Workload | Artifacts | Slowdown | Notes |
| --- | --- | --- | ---: | --- |
| old mapping | `xdp_traffic` / wrk HTTP | older corpus artifacts | about 11.7% in tuning notes | Rejected because pktgen or wrk client work dominated and XDP program was too light. |
| `workload_perf_katran_clone_flags_60s_20260522_220024` | pktgen clone/flag candidate | manifest only, workload-only failed | n/a | Rejected during pktgen setup. |
| `workload_perf_katran_heavy_flags_60s_20260522_220936` and retry manifests | `xdp_pktgen` heavy flags, single pktgen thread | no-eBPF `x86_kvm_corpus_20260523_051235_885139`; eBPF no-state attempts mostly status 2 until runtime module issues were fixed | n/a | Several eBPF no-state attempts failed before the runtime image/module setup was corrected. |
| `workload_perf_katran_heavy_flags_ebpf_image_60s_20260522_223651` | same candidate after runtime-image fix | no-eBPF `x86_kvm_corpus_20260523_051235_885139`; eBPF no-state `x86_kvm_corpus_20260523_054010_203688` | -2.53% | Rejected: eBPF baseline CV was 16.44%, noisy and not BPF-dominant. |
| `workload_perf_katran_heavy_flags_4pktgen_60s_20260522_224855` plus later successful eBPF run | 4 pktgen threads | no-eBPF `x86_kvm_corpus_20260523_055252_246684`; eBPF no-state `x86_kvm_corpus_20260523_061505_495947` | 63.74% | Accepted. no-eBPF CV 2.00%, eBPF CV 0.41%. |

Coverage diagnostic:

| Artifact | Workload | Loaded | Active | `run_cnt >= 100` |
| --- | --- | ---: | ---: | ---: |
| `x86_kvm_corpus_20260523_004124_511756` | `xdp_pktgen` | 1 | 1 | 1 |

Decision: keep `xdp_pktgen` with the 4-thread pktgen path.

## Raw Manifest Index

This index lists every `corpus/results/workload_*` tuning manifest found in the
tree at the time this note was written. Some entries were interrupted, failed,
or only contain one side of a no-eBPF/eBPF pair; those are intentionally kept
here so the failed tuning path is visible. `Setup status` is the manifest's
recorded command status; rows marked `app error` exited the outer command but
the per-app JSON recorded an application failure.

| Manifest | App(s) | Setup status | Result artifacts |
| --- | --- | --- | --- |
| `workload_perf_bcc_hot4_60s_20260522_161113` | `bcc/set` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260522_231402_001368`, `x86_kvm_corpus_20260522_231959_336238` |
| `workload_perf_bcc_syscall_hot_60s_20260522_162712` | `bcc/set` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260522_233010_504479`, `x86_kvm_corpus_20260522_233558_916058` |
| `workload_perf_cilium_endpoint_pktgen_60s_20260522_210155` | `cilium/agent` | `workload_only:0` app error | `x86_kvm_corpus_20260523_040513_850094` |
| `workload_perf_cilium_endpoint_pktgen_bidir_60s_20260522_212749` | `cilium/agent` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260523_043053_421385`, `x86_kvm_corpus_20260523_043702_423340` |
| `workload_perf_cilium_endpoint_pktgen_bidir_threads_60s_20260522_214411` | `cilium/agent` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260523_044714_736491`, `x86_kvm_corpus_20260523_045322_149815` |
| `workload_perf_cilium_endpoint_pktgen_noclone_60s_20260522_210851` | `cilium/agent` | `workload_only:2` app error | `x86_kvm_corpus_20260523_040513_850094` |
| `workload_perf_cilium_endpoint_pktgen_noclone_60s_20260522_210958` | `cilium/agent` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260523_041339_638255`, `x86_kvm_corpus_20260523_042014_476148` |
| `workload_perf_coverage_60s_20260522_155307` | `bcc/set` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260522_225556_087664`, `x86_kvm_corpus_20260522_230217_359197` |
| `workload_perf_katran_clone_flags_60s_20260522_220024` | `katran` | `workload_only:0` app error | `x86_kvm_corpus_20260523_050519_591710` |
| `workload_perf_katran_heavy_flags_4pktgen_60s_20260522_224855` | `katran` | `workload_only:0`, `ebpf_no_state:0` app error | `x86_kvm_corpus_20260523_055252_246684`, `x86_kvm_corpus_20260523_055952_009234` |
| `workload_perf_katran_heavy_flags_60s_20260522_220936` | `katran` | `workload_only:0`, `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139`, `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_katran_heavy_flags_ebpf_after_btf2_60s_20260522_223108` | `katran` | `ebpf_no_state:0` app error | `x86_kvm_corpus_20260523_053517_445489` |
| `workload_perf_katran_heavy_flags_ebpf_after_btf_60s_20260522_223013` | `katran` | `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_katran_heavy_flags_ebpf_clean_60s_20260522_221954` | `katran` | `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_katran_heavy_flags_ebpf_image_60s_20260522_223651` | `katran` | `ebpf_no_state:0` | `x86_kvm_corpus_20260523_054010_203688` |
| `workload_perf_katran_heavy_flags_ebpf_jobs1_60s_20260522_222837` | `katran` | `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_katran_heavy_flags_ebpf_rerun_60s_20260522_222444` | `katran` | `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_katran_heavy_flags_ebpf_retry_60s_20260522_221805` | `katran` | `ebpf_no_state:2` | `x86_kvm_corpus_20260523_051235_885139` |
| `workload_perf_network_pktgen_60s_20260522_202935` | `cilium/agent,katran` | `workload_only:0`, `ebpf_no_state:2` | `x86_kvm_corpus_20260523_033326_529957`, `x86_kvm_corpus_20260523_033326_529957` |
| `workload_perf_network_pktgen_ebpf_retry_60s_20260522_204045` | `cilium/agent,katran` | `ebpf_no_state:0` | `x86_kvm_corpus_20260523_034445_173649` |
| `workload_perf_otel_10khz_60s_20260522_192516` | `otelcol-ebpf-profiler/profiling` | interrupted, empty manifest rows | log only |
| `workload_perf_otel_intloop_100khz_60s_20260522_195146` | `otelcol-ebpf-profiler/profiling` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260523_025542_000315`, `x86_kvm_corpus_20260523_030252_187353` |
| `workload_perf_otel_intloop_10khz_60s_20260522_193322` | `otelcol-ebpf-profiler/profiling` | `workload_only:0`, `ebpf_no_state:0` | `x86_kvm_corpus_20260523_023621_211760`, `x86_kvm_corpus_20260523_024233_560597` |
| `workload_stats_bcc_syscall_hot_60s_20260522_164348` | `bcc/set` | `stats_on_norejit:0` | `x86_kvm_corpus_20260522_234642_346506` |
| `workload_stats_coverage_60s_20260522_152042` | `bcc/set,tetragon/observer,tracee/monitor` | all `stats_on_norejit:0` | `x86_kvm_corpus_20260522_222339_442883`, `x86_kvm_corpus_20260522_223420_827419`, `x86_kvm_corpus_20260522_224455_947112` |
| `workload_stats_remaining_60s_20260522_171746` | `otelcol-ebpf-profiler/profiling,cilium/agent,katran` | all `stats_on_norejit:0` | `x86_kvm_corpus_20260523_002121_691273`, `x86_kvm_corpus_20260523_003100_940391`, `x86_kvm_corpus_20260523_004124_511756` |
| `workload_tune_60s_refined_20260522_215403` | `bcc/set,tetragon/observer` | all ok | `x86_kvm_corpus_20260522_215705_145573`, `x86_kvm_corpus_20260522_220057_857310`, `x86_kvm_corpus_20260522_220606_309552`, `x86_kvm_corpus_20260522_221005_946299` |
| `workload_tune_60s_stressapps_20260522_212234` | `tracee/monitor,bcc/set,tetragon/observer` | all ok | `x86_kvm_corpus_20260522_212550_405856`, `x86_kvm_corpus_20260522_212946_730185`, `x86_kvm_corpus_20260522_213601_930201`, `x86_kvm_corpus_20260522_213958_976252`, `x86_kvm_corpus_20260522_214505_834979`, `x86_kvm_corpus_20260522_214926_162024` |
| `workload_tune_stressapps_20260522_211432` | `bcc/set` | all ok | `x86_kvm_corpus_20260522_211742_883689`, `x86_kvm_corpus_20260522_212048_090465` |
| `workload_tune_tracee_20260522_210536` | `tracee/monitor` | all ok | `x86_kvm_corpus_20260522_210921_806671`, `x86_kvm_corpus_20260522_211234_202742` |

## Current Open Items

1. Cilium still needs a better workload. Current stable stats-off slowdown is
   32.28%, and stats-on diagnostic slowdown is not a valid substitute.
2. BCC needs either another workload refinement or acceptance as a below-target
   workload. Current best 60s x3 stats-off slowdown is 54.35%.
3. Tracee needs a 60s x3 no-eBPF vs eBPF-no-state confirmation pair.
4. Tetragon needs a 60s x3 confirmation pair because existing 60s x1 pairs
   disagree widely, 34.16% vs 64.59%.
5. `docs/evaluation.md` is stale for workload names; it still describes older
   workloads such as `stress_ng_os_io_network`, `network_lossy_multi`, and
   `xdp_traffic` for apps whose current workload has changed. This file should
   be used as the current workload-tuning record until that evaluation document
   is updated.

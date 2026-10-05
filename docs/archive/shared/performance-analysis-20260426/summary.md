# Performance Analysis - 2026-04-26

## Scope

- Artifact analyzed: `corpus/results/x86_kvm_corpus_20260426_085216_409418/details/result.json`
- Run type: KVM x86 corpus, `SAMPLES=30`, workload duration `1.0s`
- Suite status: `error`
- Blocking error: `tracee/monitor` failed on `prog 665: BPF_PROG_REJIT: Invalid argument (os error 22)`, but all other focal apps emitted baseline/post data.

## Important Correction

The ratios listed in the task prompt do not match this artifact's 30-sample phase means.

- `tetragon/observer` in this artifact is `1307.1 -> 1252.3 ops/s (0.958x)`, not `1538 -> 562 (0.365x)`.
- `calico/felix`, `cilium/agent`, `otelcol-ebpf-profiler/profiling` are `1.002x`, `1.057x`, `1.056x`, not slight regressions.
- `bcc/capable` is `0.999x`; `bpftrace/capable` is `1.046x`.
- `bcc/syscount` is `1.511x`; `bcc/opensnoop` is `1.740x`.

For `tetragon`, the cited `1538` and `562` are individual sample values present in the artifact, not the 30-sample means. I therefore treat this report as an analysis of the authoritative artifact itself, not of the ratios quoted in the prompt.

## Global Findings

### 1. Most apps did not actually change code

Only 5 of 22 apps have `rejit_result.changed=true`:

- `bcc/capable`
- `bcc/bindsnoop`
- `bcc/biosnoop`
- `bcc/runqlat`
- `tracee/monitor`

The other 17 apps, including `tetragon/observer`, `calico/felix`, `cilium/agent`, `otelcol-ebpf-profiler/profiling`, `bcc/syscount`, `bcc/opensnoop`, and `bpftrace/capable`, have `rejit_result.changed=false`.

This matters because the daemon explicitly skips the final `BPF_PROG_REJIT` syscall when `program_changed=false`; see `daemon/src/commands.rs:692-715`. So for unchanged apps there is no final kernel re-JIT, and no post-phase slowdown attributable to a final re-JIT I-cache flush.

### 2. The benchmark is always ordered baseline -> apply_rejit -> post_rejit

The harness measures baseline first, then calls `apply_rejit`, then measures post-reJIT; see `runner/libs/case_common.py:242-289`. There is no phase randomization or A/B/A/B interleaving in this flow.

That means large wins or losses on unchanged apps are very likely to be phase-order effects, workload warmup, or VM noise unless the BPF stats also show a convincing code-related shift.

### 3. The authoritative artifact is compacted and strips per-program reJIT detail

`result.json` preserves:

- `program_counts`
- app-level `changed`
- app-level `applied_site_totals` when non-zero

It strips:

- `per_program`
- raw daemon `output`
- debug payloads

So the exact per-program pass-by-pass reJIT decisions for this run are not recoverable from the authoritative artifact alone. This is a hard limitation for the `tetragon` request.

## Actual Throughput Summary

| app | mean baseline ops/s | mean post ops/s | ratio | changed | p-value (Welch) |
| --- | ---: | ---: | ---: | --- | ---: |
| `tetragon/observer` | 1307.1 | 1252.3 | 0.958x | `false` | 0.6848 |
| `calico/felix` | 938.3 | 940.0 | 1.002x | `false` | 0.9214 |
| `cilium/agent` | 867.6 | 917.2 | 1.057x | `false` | 0.0124 |
| `otelcol-ebpf-profiler/profiling` | 902.7 | 952.8 | 1.056x | `false` | 0.0100 |
| `bcc/capable` | 898.8 | 897.7 | 0.999x | `true` | 0.9548 |
| `bpftrace/capable` | 882.3 | 923.2 | 1.046x | `false` | 0.0701 |
| `bcc/syscount` | 758.3 | 1146.1 | 1.511x | `false` | 1.36e-14 |
| `bcc/opensnoop` | 495.8 | 862.8 | 1.740x | `false` | 8.39e-21 |

## 1. `tetragon/observer`

### What the artifact says

- `program_counts`: `287 requested / 287 applied / 0 not_applied`
- app-level `changed=false`
- no `applied_site_totals`
- 30-sample mean ratio: `0.958x`
- baseline CV: `36.9%`
- post CV: `44.5%`
- p-value: `0.6848`

This is not a statistically credible 63.5% regression. It is a noisy `-4.2%` shift with overlapping 95% CIs:

- baseline CI: `1127.1 .. 1487.2 ops/s`
- post CI: `1044.4 .. 1460.1 ops/s`

### ReJIT interpretation

The combination of:

- `changed=false`
- missing `applied_site_totals`
- daemon semantics that skip final REJIT on unchanged programs

means this run provides no evidence that any of the 287 tetragon programs ended up with changed final bytecode or incurred a final `BPF_PROG_REJIT` syscall. At artifact level, this looks like 287 successful `no_change` outcomes, not 287 effective optimizations.

### BPF stats

- hot programs: only `34 / 287` had non-zero `run_cnt_delta` in either phase
- total BPF `run_cnt_delta`: `39,974,019 -> 42,758,927` (`+7.0%`)
- total BPF `run_time_ns_delta`: `24.29s -> 27.19s` (`+11.9%`)
- weighted `avg_ns_per_run`: `607.7ns -> 635.9ns` (`+4.7%`)
- total workload ops: `71,431 -> 68,012` (`-4.8%`)
- normalized BPF cost per workload op: `340.1us/op -> 399.8us/op` (`+17.6%`)
- normalized BPF runs per workload op: `559.6 -> 628.7` (`+12.4%`)

Top hot programs by runtime are all generic Tetragon dispatcher programs:

- `438 generic_tracepoint_event`: `23.57M -> 26.11M` runs, `517.0ns -> 542.2ns`
- `456 generic_kprobe_event`: `1.11M -> 1.16M` runs, `3516.6ns -> 3632.5ns`
- `374 generic_kprobe_event`: `2.79M -> 2.91M` runs, `1292.8ns -> 1320.4ns`
- `364 generic_kprobe_event`: `3.22M -> 3.29M` runs, `645.3ns -> 659.6ns`

### Root cause assessment

The slowdown signal here is not “optimized code got worse”. The artifact instead shows:

- no final code change
- no evidence of any non-zero applied sites
- BPF work per workload op increased because the mixed workload exercised more traced activity per measured op

The workload definition explains why this can drift: `tetragon_exec_connect_mix` is a merged `60% exec_storm + 40% connect_storm` workload (`runner/libs/workload.py:748-762`). Because the benchmark aggregates two different time-bounded phases, the event mix per reported op can vary substantially between samples.

The “I-cache flush” hypothesis is not supported:

- unchanged programs skip final REJIT
- low post samples are scattered across the entire phase, not concentrated only at the beginning
- first 10 post samples and last 10 post samples have nearly identical means: `1272.1 vs 1273.2 ops/s`

Conclusion: in this artifact, `tetragon/observer` does not show a trustworthy optimizer-induced regression. The observed movement is dominated by workload-mix drift and very high VM/sample variance.

## 2. `calico/felix`, `cilium/agent`, `otelcol-ebpf-profiler/profiling`

### `calico/felix`

- actual ratio: `1.002x`
- `changed=false`
- hot programs: `1 / 6`
- total BPF runs: `4 -> 4`
- only hot program: `conntrack_cleanup`
- normalized BPF cost: `29.6ns/op -> 33.0ns/op`

`exec_storm` does not meaningfully exercise the Calico datapath BPF programs in this setup. The tc datapath programs never ran; only a background cleanup hook fired four times across the whole 30-sample phase. Any throughput difference here is not a dataplane BPF effect.

### `cilium/agent`

- actual ratio: `1.057x`
- `changed=false`
- hot programs: `0 / 16`
- total BPF runs: `0 -> 0`

This is the clearest “workload did not touch the BPF programs at all” case. `exec_storm` is not a valid workload for evaluating Cilium datapath performance in this artifact. Any throughput movement is pure non-BPF noise/order effect.

### `otelcol-ebpf-profiler/profiling`

- actual ratio: `1.056x`
- `changed=false`
- hot programs: `2 / 13`
- total BPF runs: `41,851 -> 43,029`
- normalized BPF cost: `1789.4ns/op -> 1658.7ns/op`
- hot programs:
  - `tracepoint__sched_process_free`: `39,727 -> 40,988` runs, `544.7ns -> 511.3ns`
  - `native_tracer_entry`: `2,124 -> 2,041` runs, `14.74us -> 14.72us`

Unlike Calico/Cilium, `exec_storm` does exercise the profiler's process-lifecycle hooks. But the measured direction is slightly positive, not negative, and the BPF cost per op also improves slightly.

### Conclusion for the new apps

- `calico/felix`: workload is almost entirely non-representative
- `cilium/agent`: workload is completely non-representative
- `otelcol-ebpf-profiler/profiling`: workload is representative enough to touch the intended hooks

So the prompt's “new apps all slightly slower” conclusion is not supported by this artifact.

## 3. `bcc/capable` and `bpftrace/capable`

### `bcc/capable`

- actual ratio: `0.999x`
- `changed=true`
- `applied_site_totals.total_sites=1`
- only contributing pass: `extract_sites=1`
- hot program: `cap_capable`
- BPF runs: `3,416,920 -> 3,373,377`
- `avg_ns_per_run`: `57.6ns -> 57.9ns`
- normalized BPF cost per workload op: `6691.7ns/op -> 6717.1ns/op`

This is effectively flat. The single extract-site rewrite does not introduce a measurable regression.

### `bpftrace/capable`

- actual ratio: `1.046x`
- `changed=false`
- no `applied_site_totals`
- hot program: `cap_capable`
- BPF runs: `3,357,562 -> 3,486,479`
- `avg_ns_per_run`: `145.0ns -> 152.4ns`
- normalized BPF cost per workload op: `16.80us/op -> 17.70us/op`

The bpftrace version is inherently much more expensive than the BCC version, but the post-phase delta is small and this app did not actually change code. There is no evidence here for a recompile-induced regression either.

### Conclusion for `capable`

The prompt's “both got slower because capable kprobe recompilation added overhead” is not supported:

- BCC: effectively no throughput change
- bpftrace: slight positive mean shift, no code change

## 4. Why `syscount` and `opensnoop` look good

### `bcc/syscount`

- actual ratio: `1.511x`
- `changed=false`
- no `applied_site_totals`
- hot programs:
  - `tracepoint__raw_syscalls__sys_enter`
  - `tracepoint__raw_syscalls__sys_exit`
- weighted `avg_ns_per_run`: `74.5ns -> 74.5ns`
- total BPF runtime: `3.48s -> 3.45s`
- workload ops: `22,781 -> 34,416`
- baseline CV: `21.7%`
- post CV: `6.5%`

This cannot be an optimization win, because the BPF program did not change and its per-run cost is identical. The only thing that changed is the benchmark throughput itself.

The workload is `file_open_storm`, which is just repeated open() on pre-created temp files (`runner/libs/workload.py:606-618`, `712-713`). The phase pattern is consistent with order/caching effects:

- baseline first 10 samples mean: `717.2 ops/s`
- baseline last 10 samples mean: `779.8 ops/s`
- post first 10 samples mean: `1149.0 ops/s`
- post last 10 samples mean: `1126.2 ops/s`

The baseline phase is visibly colder and noisier than the post phase.

### `bcc/opensnoop`

- actual ratio: `1.740x`
- `changed=false`
- no `applied_site_totals`
- BPF runs: `45,780 -> 78,378`
- weighted `avg_ns_per_run`: `1893.5ns -> 1821.4ns`
- normalized BPF cost per workload op: `5814.3ns/op -> 5509.5ns/op`
- baseline CV: `21.1%`
- post CV: `6.1%`

Again, there is no pass contribution to attribute. The improvement is dominated by the benchmark phase itself becoming much faster, not by the tracer becoming much cheaper.

The workload is `open_family_storm`, a tight loop over `open`, `openat`, and `openat2` on a temp file (`runner/libs/workload.py:995-1015`). It also shows a clear phase step:

- baseline first 10 samples mean: `483.3 ops/s`
- post first 10 samples mean: `869.5 ops/s`

### Pass contribution answer

For both `syscount` and `opensnoop`, the largest pass contribution is: none.

- `rejit_result.changed=false`
- no non-zero `applied_site_totals`
- no final REJIT

These “good results” are benchmark-order artifacts, not optimizer wins.

## 5. Overall Reliability

### VM noise and phase-order effects

This artifact is usable, but only with care:

- `tetragon/observer` is too noisy to support a small regression claim.
- `syscount` and `opensnoop` show huge gains on unchanged code, which is strong evidence of phase-order/warmup effects.
- `cilium/agent` shows throughput movement with zero BPF activity, which proves that some app-level throughput shifts are entirely outside BPF execution.

### Is `SAMPLES=30` enough?

It depends on the workload:

- For low-noise workloads with CV around `3% .. 10%` (`calico`, `cilium`, `otel`, `capable`, `tracee`, `katran`), 30 samples is enough to detect moderate effects.
- For high-noise workloads like `tetragon` with CV `37% .. 45%`, 30 samples is not enough to call a `4% .. 5%` shift meaningful.

### Which regressions look real vs measurement error?

- `tetragon/observer`: measurement noise / workload-mix drift; not a credible optimizer regression in this artifact
- `calico/felix`: no regression; workload barely touches BPF
- `cilium/agent`: no regression; workload does not touch BPF at all
- `otelcol-ebpf-profiler/profiling`: no regression; workload does touch BPF, but measured direction is positive
- `bcc/capable`: no regression
- `bpftrace/capable`: no regression
- `bcc/syscount` / `bcc/opensnoop`: apparent wins are not trustworthy optimizer wins

One genuinely strong unexplained effect in this artifact is `katran`:

- `1.00 run/op` both phases
- `52.6ns -> 53.1ns` per run, essentially flat BPF cost
- throughput drops to `0.760x`
- low baseline noise, clearly depressed post phase

That looks more like a workload or harness-level effect than a BPF optimization effect, but unlike `tetragon`, the signal is statistically strong. It is the clearest non-BPF regression worth separate follow-up.

## Bottom Line

The authoritative artifact does not support the narrative that several apps regressed because ReJIT made their BPF programs slower.

The dominant pattern is the opposite:

- many apps never changed code at all
- unchanged apps still show large throughput shifts
- those shifts correlate better with workload representativeness, phase ordering, cache warmup, and VM variance than with optimizer behavior

For this artifact specifically:

- `tetragon/observer` is noisy and unchanged; no evidence of a real ReJIT regression
- `calico/felix` and `cilium/agent` are not meaningfully exercised by `exec_storm`
- `otelcol-ebpf-profiler/profiling` is exercised and slightly improves
- `capable` does not regress
- `syscount` and `opensnoop` do not demonstrate optimizer wins; they demonstrate harness bias on unchanged code

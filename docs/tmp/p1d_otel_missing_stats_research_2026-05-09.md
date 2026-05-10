# OTEL `BPF stats missing requested program IDs` research

Date: 2026-05-09

Scope: code reading, local corpus artifact grep, and host `bpftool` feasibility checks only. I did not modify runner code, benchmark config, or `CLAUDE.md`.

## Summary

The immediate failure is not that tail-called OTEL programs are invisible to `bpftool prog show -j`. They are visible: successful OTEL corpus results contain `perf_unwind_*` programs in the raw BPF stats payload with `run_cnt_delta = 0` and `run_time_ns_delta = 0`.

The failing condition is that the runner samples a stale set of BPF program IDs. The wanted ID list is discovered earlier, then `sample_bpf_stats()` later requires every old ID to still be present in the current `bpftool prog show -j` output. If the app unloads/reloads programs, or exits and closes the program/map/link FDs, `sample_bpf_stats()` raises and the phase result is lost.

Hypothesis status:

- (a) "tail-call programs are not in `bpftool prog show`": rejected.
- (b) "OTEL dynamically reloads `perf_unwind_<lang>` during runtime": not proven; current OTEL source points against per-unwinder runtime reload. The observed all-13-IDs-missing OTEL failures are more consistent with the whole OTEL BPF collection being unloaded, either by process exit/shutdown or full reload, after the runner captured IDs.
- cilium's intermittent same error is the same stale-ID class, but there is stronger local evidence for Cilium datapath reload/churn: the runner has explicit comments and mitigations for Cilium reload invalidating captured program IDs.

## Observed Symptoms

Target OTEL failure:

```text
corpus/results/x86_kvm_corpus_20260510_042227_502084/details/apps/otelcol-ebpf-profiler__profiling.json:255
"error": "BPF stats missing requested program IDs: 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55"
```

In that file, `baseline.bpf` exists and contains all 13 OTEL programs, while `post_rejit` is `null`:

```text
lines 1-35: baseline.bpf starts with IDs 43..46
line 255: missing all 13 requested IDs
line 256: "post_rejit": null
line 257: "rejit_result": { ... }
```

So this specific failure happened after a successful baseline measurement and after ReJIT was attempted, before a post-ReJIT measurement could be recorded.

Local corpus count, over the available `otelcol-ebpf-profiler__profiling.json` files:

```text
      5 missing_stats
     87 ok
      3 other_error
```

This local workspace does not support the statement that every historical OTEL run has this exact failure. The available OTEL app result files begin at `2026-05-03`; older April corpus directories in this workspace do not contain OTEL app JSONs.

Cilium has the same error class intermittently:

```text
      9 missing_stats
     76 ok
     14 other_error
```

Example:

```text
corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/cilium__agent.json:570
"error": "BPF stats missing requested program IDs: 171, 174, 176, 177, 183, 185, 186"
```

## Runner ID Path

The wanted IDs are produced from `bpftool prog show -j` records after app startup.

Key path:

- `runner/libs/app_runners/process_support.py:202-210` records BPF IDs that existed before the app process starts.
- `runner/libs/app_runners/process_support.py:247-253` waits for the post-start program set to stabilize.
- `runner/libs/app_runners/process_support.py:350-355` stores that stable program list and returns its IDs from `NativeProcessRunner.start()`.
- `runner/libs/app_runners/otel_profiler.py:135-143` delegates OTEL startup to `NativeProcessRunner.start()`; it does not implement OTEL-specific BPF enumeration.

The measurement path then reuses that list:

- `corpus/driver.py:175-196` calls `sample_bpf_stats(logical_prog_ids)` before and after workload execution.
- `runner/libs/bpf_stats.py:25-26` gets a fresh current `bpftool prog show -j` payload.
- `runner/libs/bpf_stats.py:68-73` raises if any wanted ID is absent from the fresh payload.

There is a refresh boundary, but it is not at every stats sample:

- `corpus/driver.py:303-328` refreshes active session programs before named lifecycle phases.
- `corpus/driver.py:557-559` refreshes before baseline.
- `corpus/driver.py:605-607` refreshes before ReJIT.
- `corpus/driver.py:670-686` measures post-ReJIT using `result.state.prog_ids` without another refresh immediately before the `sample_bpf_stats()` call inside `_measure_runner_phase()`.

Therefore, any program unload/reload after `rejit_refresh` and before the post-ReJIT stats sample becomes exactly this error.

## Evidence Against Hypothesis (a)

`bpftool prog show` is the source for the stats records:

- `runner/libs/agent.py:64-65` runs `bpftool -j prog show`.
- `runner/libs/bpf_stats.py:37-49` converts those records into the framework's BPF stats fields.

Successful OTEL result showing tail-call targets in stats:

```text
corpus/results/x86_kvm_corpus_20260510_034728_154696/details/apps/otelcol-ebpf-profiler__profiling.json:50-57
id=48 name=perf_unwind_python type=perf_event run_cnt_delta=0 run_time_ns_delta=0

same file:113-120
id=55 name=native_tracer_entry type=perf_event run_cnt_delta=15952 run_time_ns_delta=33886823
```

Compact grep/jq output from the same file:

```text
43 perf_unwind_stop      perf_event 0     0        6232
44 perf_unwind_native    perf_event 0     0        37232
45 perf_unwind_hotspot   perf_event 0     0        28048
46 perf_unwind_perl      perf_event 0     0        29144
47 perf_unwind_php       perf_event 0     0        25032
48 perf_unwind_python    perf_event 0     0        33264
49 perf_unwind_ruby      perf_event 0     0        28000
50 perf_unwind_v8        perf_event 0     0        33712
51 perf_unwind_dotnet    perf_event 0     0        34248
52 perf_go_labels        perf_event 0     0        2496
53 perf_unwind_beam      perf_event 0     0        1088
54 tracepoint__sched_process_free tracepoint 20 84418 1320
55 native_tracer_entry   perf_event 15952 33886823 5496
```

This matches `CLAUDE.md:60-62`: tail-called programs are listed, but the stats counters stay zero because tail calls skip the prologue that increments `bpf_prog->stats`.

Conclusion: `bpftool prog show -j` does include OTEL tail-call targets when they are live.

## Evidence Around Hypothesis (b)

OTEL runner configuration enables all tracers:

- `runner/libs/app_runners/otel_profiler.py:33-62` defines the minimal collector config.
- `runner/libs/app_runners/otel_profiler.py:36-42` sets `tracers: all`.
- `runner/libs/app_runners/otel_profiler.py:43-49` sets `monitor_interval: 1s`.

OTEL upstream source loads BPF programs once during tracer startup:

- `runner/repos/opentelemetry-ebpf-profiler/internal/controller/controller.go:93-117` calls `tracer.NewTracer()` and logs that the eBPF tracer loaded.
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:233-246` calls `initializeMapsAndPrograms()`.
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:391-455` builds the tail-call program list and calls `loadPerfUnwinders()`.
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:700-743` loads enabled `perf_*` unwinders.
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:822-847` creates each BPF program with `NewProgramWithOptions()` and updates the tail-call map with the program FD.
- `runner/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:1208-1248` attaches only `native_tracer_entry` to perf events.

Source grep found the program-load API only in startup/loading paths:

```text
tracer/tracer.go:333 support.LoadCollectionSpec()
tracer/tracer.go:824 cebpf.NewProgramWithOptions(progSpec, programOptions)
```

Runtime interpreter attach/detach code updates maps and process state, not BPF program objects. For example, `processmanager/processinfo.go` calls interpreter `Attach`/`Detach`, while `processmanager/ebpf/ebpf.go` has map update/remove helpers.

The BPF side confirms the dispatch is via tail-call map:

- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:539-564` wraps `bpf_tail_call(ctx, &perf_progs, next)`.
- `runner/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h:772-784` has `native_tracer_entry` pick an unwinder and tail-call it.

So I do not see evidence for per-language `perf_unwind_<lang>` dynamic load/unload during normal OTEL runtime. The failing artifacts also miss all 13 OTEL IDs at once, not a subset of language unwinders:

```text
2026-05-06 21:21:17: missing 6..18
2026-05-08 04:52:24: missing 6..18
2026-05-09 19:34:52: missing 43..55
2026-05-09 19:59:59: missing 43..55
2026-05-10 04:22:27: missing 43..55
```

That is more consistent with the whole OTEL BPF collection being unloaded or replaced after the runner's refresh point. The local artifacts do not preserve a failure-time raw `bpftool prog show -j` snapshot, so I cannot prove whether replacement programs with the same names existed at that exact instant.

## Cilium Comparison

Cilium's runner already documents the same class of problem:

- `runner/libs/app_runners/cilium.py:293-307` disables drift/dynamic config/lifecycle and endpoint regen timers because they reload BPF programs mid-measurement and invalidate captured program IDs.
- `runner/libs/app_runners/cilium.py:550-555` freezes `cilium-agent` after endpoint setup so controllers cannot call `ReloadDatapath()` during baseline/post measurement and invalidate IDs.

The missing Cilium IDs are not just tail-call targets. Example from `x86_kvm_corpus_20260507_023000_475311`:

```text
missing ID 171 -> cil_to_netdev
missing ID 174 -> cil_from_host
missing ID 176 -> cil_host_policy
missing ID 177 -> cil_from_netdev
missing ID 183 -> cil_to_host
missing ID 185 -> cil_from_host
missing ID 186 -> cil_host_policy
```

Those names appear in `baseline.bpf`, then are missing before `post_rejit`:

- `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/cilium__agent.json:113-117` includes ID 171 as `cil_to_netdev`.
- `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/cilium__agent.json:158-174` includes IDs 176/177 as `cil_host_policy` and `cil_from_netdev`.
- `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/cilium__agent.json:570-571` records the missing-ID error and `post_rejit: null`.

Conclusion: Cilium's intermittent error is also stale program IDs, not tail-call invisibility.

## Host Experiments

Host `bpftool` is installed:

```text
/usr/local/sbin/bpftool
bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons
```

But this host user cannot enumerate or load BPF programs:

```text
$ bpftool -j prog show
[{"error":"can't get next program: Operation not permitted"}]
```

Because of that, I did not run a host tail-call load experiment and did not start the OTEL daemon on the host. The corpus artifacts are the stronger evidence here because they are from the benchmark VM environment with BPF privileges.

## Root Cause Conclusion

Root cause is a stale-ID sampling contract:

1. The runner captures OTEL BPF program IDs from `bpftool prog show -j` after startup and lifecycle refresh.
2. `sample_bpf_stats()` later requires those exact integer IDs to still exist.
3. In failing OTEL runs, the whole captured ID set is absent by post-ReJIT stats sampling.
4. Tail-call accounting explains zero counters, not missing records.
5. OTEL source does not show normal runtime per-unwinder reload; the failure looks like full collection unload/replacement or process exit between refresh and sample.
6. Cilium failures follow the same stale-ID class, with explicit runner comments confirming reload can invalidate IDs.

## Fix Options

### 1. Do not error when requested IDs are missing

Mechanism: change `sample_bpf_stats()` to return stats for found IDs and silently omit missing IDs.

Pros:

- Keeps successful subsets instead of dropping an entire app result.
- Simple implementation.

Cons:

- Violates `CLAUDE.md` fail-fast / no-silenced-errors rules.
- Hides app unload/reload and changes the measured program population without making the failure visible.
- Can bias post-hoc analysis because the retained population differs by phase.
- Conflicts with the benchmark rule that failures should surface naturally instead of being converted into informational gaps.

Compatibility: not compatible.

### 2. Re-discover programs at stats-sample time

Mechanism: immediately before a phase stats sample, re-run the same identity-based rediscovery already used by `_refresh_active_session_programs()`. If the old IDs disappeared but live programs with the same identity exist, update the phase-local ID list and sample those. If replacements are absent or ambiguous, fail with a clear error.

Important constraint: do not compute a delta across two different ID sets inside one phase. The initial and final stats snapshots for a phase must use the same live IDs, or the phase must fail/retry before recording a delta.

Pros:

- Addresses the actual stale-ID boundary.
- Preserves raw per-program measurements when an app legitimately reloads programs before the sample.
- Still fails fast if no same-identity replacement exists.
- Does not add metadata-only result fields.
- Does not filter ReJIT candidates.

Cons:

- More code than option 1.
- Needs careful identity matching for duplicate program names and attach targets.
- If a program reload happens during the workload window, the framework still cannot produce a valid single delta without restarting or failing that phase.

Compatibility: compatible if implemented as strict identity-preserving rediscovery with hard failure on mismatch.

### 3. Change `CLAUDE.md` to allow metadata fields for missing IDs

Mechanism: permit fields such as `missing_program_ids`, `workload_miss`, or limitations annotations in result payloads.

Pros:

- Improves debugging visibility after the fact.
- Could preserve partial raw stats while making missing IDs visible.

Cons:

- Directly conflicts with `CLAUDE.md:67-68` "No Redundant Informational Fields".
- Does not fix the stale-ID measurement contract.
- Risks normalizing partial/ambiguous benchmark data instead of surfacing a failure.

Compatibility: not compatible under current rules; would require an explicit rule change.

## Recommendation

Use option 2: strict sample-time rediscovery, not silent omission and not new metadata-only fields.

Recommended policy:

- Keep `sample_bpf_stats()` fail-fast for exact ID sampling.
- Add a caller-side phase sampler that checks liveness immediately before sampling, rediscovering by full program identity when old IDs disappeared.
- Require the initial and final snapshots of a phase to use the same rediscovered ID set.
- If no same-identity replacement exists, fail with a clearer error such as "tracked BPF programs disappeared before post_rejit sample; no same-identity replacements found".

This fits the existing benchmark design: raw counters only, no hidden filtering, and no informational result fields. It also separates two cases that are currently collapsed into one error string: legitimate ID churn with equivalent live replacements, versus actual program unload/process exit with no replacement.

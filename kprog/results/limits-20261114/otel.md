# OTel eBPF profiler performance limits, 2026-11-15

Both arms of one run, same guest, same workload, `kprog/perf/profile/phase-profile.py
run --app otelcol-ebpf-profiler/profiling --seconds 60 --cpus 0-7`. Capture
`/workspaces/kprog-raw/C/20261115T013715Z-phase-profile-otelcol-ebpf-profiler_profiling`;
corpus run `x86_kvm_corpus_20261115_013848_695617` (`status: ok`).

## `cpu-clock` sampling cannot see this app's BPF time at all

The capture's own `summary.txt` reports **0.00% BPF** in both arms, and that is not a
"BPF is negligible" finding: it is the sampling method failing on this program type.

The app's entire measurable BPF cost sits in one program:

| arm | program | type | invocations | BPF time | ns/invocation | jited bytes |
|---|---|---|---:|---:|---:|---:|
| eBPF | `native_tracer_e` | `perf_event` | 22 381 403 | 54.66 s | **2 442.2** | 3 815 |
| native | `native_tracer_e` | `perf_event` | 22 290 666 | 3.06 s | **137.5** | 7 510 |

`native_tracer_e` is a `perf_event` program driven by the profiler's own sampling timer.
`cpu-clock` at 999 Hz produced 471 388 samples in the eBPF phase and **one** of them landed
inside a JIT'd program range; the native phase produced 456 405 and **zero**. A
perf_event program runs for microseconds per invocation between its own timer ticks, so the
odds of an independent 999 Hz software-clock sample landing in its text are vanishing, and
perf's callchain sampling attributes the cost to the timer path instead. Every other
unwinder program (`perf_unwind_*`) ran fewer than 100 times per phase and contributed
nothing measurable.

So for OTel, the kernel's counters are the whole story and the perf share is not.

## What the counters say

Per-invocation BPF time **2 442.2 → 137.5 ns, 17.8x less**, at essentially the same
invocation count (22 381 403 against 22 290 666, 0.4% apart) over the same 60 s window.
Both arms ran exactly two programs: `native_tracer_e` (the cost) and one
`tracepoint__sched_*` program with ~90 invocations and negligible time.

This is the largest per-invocation native win measured on any app in this project, and it
comes with the one caveat that matters for a whole-app ratio: OTel's BPF time is a
**sampling workload** — 22.4 M invocations in 60 s is the profiler sampling the machine,
not the guest workload calling into a hook. The guest's whole CPU is dominated by the
workload and by the OTel agent's user-space processing, and the profile shows the BPF part
nearly disappearing (54.66 s → 3.06 s of a 60 s window) without a corresponding workload
throughput change, because the profiler and the workload are not in a caller/callee
relationship.

The jited byte count doubles (3 815 → 7 510) because the native object carries the unwind
machinery the eBPF arm calls out to; that is a size cost, not a per-invocation one, since
the measured per-invocation time falls 17.8x.

## What this bounds

The eBPF arm charged 54.66 s of a 60.04 s window to BPF. If that time were serialized on
the measured CPU set the app could not have run at all, so much of it is spread across
sampling contexts that overlap with workload and agent time. Treat 54.66 s as the
per-invocation sum, not as a serial wall-clock budget.

Two consequences for planning:

- **Codegen has almost nothing left to win on OTel** in the native arm: the remaining
  3.06 s is the whole BPF budget, and a perfect body still leaves the agent's user-space
  work and the workload untouched.
- **The interesting question for OTel is the eBPF arm's 54.66 s**, i.e. what the JIT'd
  `native_tracer_e` does for 2.4 µs per sample. That is where the native arm's 17.8x comes
  from, and it is consistent with the native body replacing a chain of helper calls with
  inlined work.

## Note on the profile's own workload

One sample of the app's normal workload per phase, so its throughput numbers are not
timing results. Use it for the per-invocation counters only; the perf share is unusable
here for the reason above.

Raw capture:
`/workspaces/kprog-raw/C/20261115T013715Z-phase-profile-otelcol-ebpf-profiler_profiling`
(`baseline.data`, `post_rejit.data`, per-phase `kallsyms` and `jit-lines.json`).
Regenerate with
`python3 kprog/results/limits-20261114/bpf-attribution.py <capture dir>`, and note that
its BPF share will read 0.00% for both arms — that is the method's limit, not the app's
cost. The per-invocation table comes from
`corpus/results/x86_kvm_corpus_20261115_013848_695617/details/apps/otelcol-ebpf-profiler__profiling.json`.
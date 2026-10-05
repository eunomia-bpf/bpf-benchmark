# otelcol-ebpf-profiler/profiling source-opt attempt: defer-kernel-stackid-unmapped-pid

- Time: 2026-06-25 12:00:59
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-correctness
- Source files: `support/ebpf/tracemgmt.h`
- Hypothesis: unknown PID samples only notify userspace and do not send a trace, so they can skip `bpf_get_stackid()` while preserving all sent-trace content.
- Expected hot path: `native_tracer_entry()` -> `collect_trace()` during first samples from newly spawned interpreter workers.
- Correctness argument: pid 0 traces, usermode-reg error traces, and known PID traces still collect kernel stack IDs; unmapped PID path still calls `report_pid()` and returns without sending a trace as before.
- Build command: through `make corpus` only; no explicit eBPF artifact rebuild was run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_190706_743922`
- Primary metric: language_ops_total mean=19631015807; samples `19482699802, 19832870505, 19577477114`; vs clean baseline -0.07%.
- Rejection reason: provenance failed. The otel vendor `otel-x86` path rebuilds the collector binary from the embedded BPF artifact, but this attempt did not explicitly regenerate `support/ebpf/tracer.ebpf.amd64` after editing `support/ebpf/tracemgmt.h`. The run is valid as a workload sanity check, but not as proof that the patched eBPF source was loaded.
- Follow-up: redo this hypothesis only after rebuilding the eBPF artifact before `make corpus`.

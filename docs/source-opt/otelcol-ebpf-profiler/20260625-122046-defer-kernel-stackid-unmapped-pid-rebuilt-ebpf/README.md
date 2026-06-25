# otelcol-ebpf-profiler/profiling source-opt attempt: defer-kernel-stackid-unmapped-pid-rebuilt-ebpf

- Time: 2026-06-25 12:20:46
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `support/ebpf/tracemgmt.h`
- Hypothesis: unknown PID samples only notify userspace and do not send a trace, so they can skip `bpf_get_stackid()` while preserving all sent-trace content.
- Expected hot path: `native_tracer_entry()` -> `collect_trace()` during first samples from newly spawned interpreter workers.
- Correctness argument: pid 0 traces, usermode-reg error traces, and known PID traces still collect kernel stack IDs; unmapped PID path still calls `report_pid()` and returns without sending a trace as before.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_192715_058308`
- Primary metric: language_ops_total mean=19644068683; samples `19898566747, 19709048452, 19324590849`; vs clean baseline -0.00%.
- Final verdict: correctness passed, but the throughput signal is effectively flat, so this attempt is not a good base for stacked otel optimizations.
- Follow-up: use the clean source baseline as the next attempt base.

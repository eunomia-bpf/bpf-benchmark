# otelcol-ebpf-profiler/profiling source-opt attempt: trace-send-size-direct

- Time: 2026-06-25 13:04:17
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `support/ebpf/tracemgmt.h`
- Hypothesis: `send_trace()` can compute the perf-event payload length directly from the fixed prefix size plus `stack_len` frames instead of subtracting empty frames from the maximum trace size.
- Expected hot path: `unwind_stop()` -> `send_trace()` for every emitted profiler trace.
- Correctness argument: `Trace.frames` remains the last field, the emitted byte range is identical for every valid `stack_len`, and the existing oversized-payload guard remains in place.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_201102_658698`.
- Performance: `language_ops_total` mean=19634728466; samples `19889012769, 19180704492, 19834468137`; vs clean baseline `-0.05%`.
- Follow-up: do not stack later otel optimizations on this patch; correctness passed, but the direct size formula only reduced a few instructions and did not improve throughput.

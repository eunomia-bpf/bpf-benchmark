# otelcol-ebpf-profiler/profiling source-opt attempt: tail-call-use-existing-record

- Time: 2026-06-25 12:41:47
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `support/ebpf/tracemgmt.h`, `support/ebpf/*_tracer.ebpf.c`, `support/ebpf/interpreter_dispatcher.ebpf.c`, `support/ebpf/native_stack_trace.ebpf.c`
- Hypothesis: most unwinder tail-call sites already have a checked `PerCPURecord *`; passing it into the tail-call wrapper removes one repeated per-CPU map lookup per tail call.
- Expected hot path: `native_tracer_entry()` -> native/interpreter unwinder chain -> `tail_call_record()`.
- Correctness argument: tail-call target, tail-call count, max-tail-call abort behavior, and unwind error state are unchanged; only the source of the already-current per-CPU record pointer changes.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_194845_959410`.
- Performance: `language_ops_total` mean=19358366012; samples `19402588695, 19278089079, 19394420261`; vs clean baseline `-1.46%`.
- Follow-up: do not stack later otel optimizations on this patch; correctness passed, but removing the repeated per-CPU lookup did not improve this workload.

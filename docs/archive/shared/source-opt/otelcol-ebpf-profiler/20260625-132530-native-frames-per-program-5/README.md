# otelcol-ebpf-profiler/profiling source-opt attempt: native-frames-per-program-5

- Time: 2026-06-25 13:25:30
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `support/ebpf/native_stack_trace.ebpf.c`
- Hypothesis: increasing `NATIVE_FRAMES_PER_PROGRAM` from 4 to 5 lets each native unwinder tail-call process one more native frame, reducing tail-call overhead for native-heavy stacks.
- Expected hot path: `native_tracer_entry()` -> `unwind_native()` chains in the mixed language workload.
- Correctness argument: frame encoding, `Trace` layout, max frame limit, tail-call target keys, and unwinder selection after each frame are unchanged; the program only batches more native frames per already-existing unwinder invocation.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_203203_222972`.
- Performance: `language_ops_total` mean=19611239252; samples `19226116826, 20279757143, 19327843786`; vs clean baseline `-0.17%`.
- Follow-up: do not stack later otel optimizations on this patch; correctness passed, but the larger native unwinder did not improve this workload.

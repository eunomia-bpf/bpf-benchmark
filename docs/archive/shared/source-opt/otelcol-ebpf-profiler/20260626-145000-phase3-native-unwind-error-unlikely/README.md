# otelcol-ebpf-profiler/profiling source-opt attempt: phase3-native-unwind-error-unlikely

- Time: 2026-06-26 14:50
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files:
  - `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/bpfdefs.h`
  - `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c`
  - `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h`
- Hypothesis: mark native-unwind error branches as cold so clang lays out the successful unwind path more tightly.
- Expected hot path: `native_tracer_entry` tail-calls native unwinder programs; the successful stack-delta lookup and frame-unwind path should dominate over error exits in a healthy profiling workload.
- Correctness argument: no map layout, event payload, tail-call key, attach point, or filtering semantics changed; only branch expectation metadata changed.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_215832_429743`
- Follow-up: do not stack this patch. The branch-layout-only approach regressed workload throughput by 1.42%; the next OTEL attempt should use a different structural target from clean source.

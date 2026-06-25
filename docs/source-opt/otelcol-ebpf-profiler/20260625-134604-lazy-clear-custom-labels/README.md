# otelcol-ebpf-profiler/profiling source-opt attempt: lazy-clear-custom-labels

- Time: 2026-06-25 13:46:04
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `support/ebpf/tracemgmt.h`
- Hypothesis: most traces do not carry Go custom labels, so `get_pristine_per_cpu_record()` can skip clearing the custom-label backing array unless the previous trace either emitted labels or attempted Go-label extraction.
- Expected hot path: `native_tracer_entry()` -> `collect_trace()` -> `get_pristine_per_cpu_record()` for every profiler sample.
- Correctness argument: `custom_labels.len` is still reset every trace; the backing array is cleared after any previous custom-label use or attempted extraction, preserving zeroed unused label payloads when labels may have been written.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_205249_386525`.
- Performance: `language_ops_total` samples `19345351817, 19739934685, 19355726380`, mean `19480337627`, `-0.84%` vs clean-source baseline.
- Follow-up: correctness passed, but throughput regressed; do not stack this patch.

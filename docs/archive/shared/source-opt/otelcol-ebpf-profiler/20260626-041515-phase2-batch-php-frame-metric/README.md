# otelcol-ebpf-profiler source-opt attempt: phase2-batch-php-frame-metric

- Time: 2026-06-26 04:15
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/php_tracer.ebpf.c`
- Hypothesis: PHP contributed the largest share of the mixed-language workload in the previous run, so batching successful PHP frame metric increments within one `walk_php_stack()` call might reduce per-frame map lookup/helper overhead on a weighted hot path.
- Expected hot path: `kprobe/unwind_php` and `perf_event/unwind_php`.
- Correctness argument: map layout, event payloads, tail-call keys, attach points, frame walking, and error metrics are unchanged. Successful PHP frame metrics are accumulated locally and written once at function exit; error metrics still increment immediately.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_112227_995529`
- Follow-up: Do not stack. The BPF body shrank substantially, but workload throughput regressed within the OTEL noise envelope.

## Performance

Primary metric: `language_ops_total`.

| Sample | Value |
| --- | ---: |
| 1 | 19462147885 |
| 2 | 19814623616 |
| 3 | 19247455513 |

- Mean: 19508075671
- Clean baseline mean: 19644780415
- vs baseline: -0.70%


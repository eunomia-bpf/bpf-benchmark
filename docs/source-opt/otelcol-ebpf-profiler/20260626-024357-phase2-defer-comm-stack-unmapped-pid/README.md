# otelcol-ebpf-profiler/profiling source-opt attempt: phase2-defer-comm-stack-unmapped-pid

- Time: 2026-06-26 02:43:57
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h`
- Hypothesis: for the unmapped-PID path in `collect_trace()`, avoid `bpf_get_current_comm()` and `bpf_get_stackid()` because that path reports PID metadata and returns before sending a trace.
- Expected hot path: `perf_event/native_tracer_entry` before tail-calling the native unwinder.
- Correctness argument: no map layout, event payload layout, tail-call key, or attach point changed; sent trace paths still populate `comm`, `kernel_stack_id`, and `unwind_error`; only the existing metadata-only unmapped-PID return skips helper work.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_095211_287090`
- Follow-up: do not stack this patch; move to a different OTEL strategy focused on hotter map/helper or unwinder paths.

## Result

Primary docs-side metric: `language_ops_total`.

Samples: `19676128056, 19509969254, 19258003069`

Mean: `19481366793`

Versus clean-source baseline mean `19644780415`: `-0.83%`


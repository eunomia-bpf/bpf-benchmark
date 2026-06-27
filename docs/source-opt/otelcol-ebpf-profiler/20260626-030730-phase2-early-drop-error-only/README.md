# otelcol-ebpf-profiler/profiling source-opt attempt: phase2-early-drop-error-only

- Time: 2026-06-26 03:07:30
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/interpreter_dispatcher.ebpf.c`
- Hypothesis: when `filter_error_frames` is enabled, an empty-stack error-only trace is dropped; return before `push_error()`, APM lookup, Go-label lookup, and `send_trace()` for that drop path.
- Expected hot path: `kprobe/perf_event unwind_stop` after native or interpreter unwinding terminates.
- Correctness argument: normal sent traces still push error frames when needed, still run APM/Go-label enrichment, and still call `send_trace()`; the early return only applies to traces that the existing filter would drop.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_101543_422474`
- Follow-up: do not stack this patch; error-only drop work is not the measured bottleneck for this workload.

## Result

Primary docs-side metric: `language_ops_total`.

Samples: `19879363031, 19331939856, 19534723746`

Mean: `19582008878`

Versus clean-source baseline mean `19644780415`: `-0.32%`


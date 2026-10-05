# otelcol-ebpf-profiler source-opt attempt: phase2-single-delta-reuse

- Time: 2026-06-26 03:53 local
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c`
- Hypothesis: when a stack-delta page has exactly one delta and the PC falls after it, `get_stack_delta()` can reuse the first lookup instead of fetching the same delta again.
- Expected hot path: `get_stack_delta()` inside `kprobe/unwind_native` and `perf_event/unwind_native`.
- Correctness argument: the patch only reuses an already validated `StackDelta *` for the single-delta-page case; map layout, event ABI, tail-call keys, and error paths are unchanged.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_110000_678727`
- Follow-up: do not stack. The patch passed correctness but did not improve workload throughput.

## Result

Docs-side primary metric:

- Clean baseline `language_ops_total` mean: `19644780415`
- Attempt samples: `19658284979, 19486494323, 19580559194`
- Attempt mean: `19575112832`
- Delta vs clean baseline: `-0.35%`


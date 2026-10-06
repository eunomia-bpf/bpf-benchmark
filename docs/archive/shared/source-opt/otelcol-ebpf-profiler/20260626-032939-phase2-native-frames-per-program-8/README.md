# otelcol-ebpf-profiler source-opt attempt: phase2-native-frames-per-program-8

- Time: 2026-06-26 03:29 local
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/native_stack_trace.ebpf.c`
- Hypothesis: increasing `NATIVE_FRAMES_PER_PROGRAM` from 4 to 8 may reduce tail-call recursion and map round trips during native unwind.
- Expected hot path: `kprobe/unwind_native` and `perf_event/unwind_native`.
- Correctness argument: the patch only changes per-program unwind loop unroll count; stack/event/map ABI and tail-call keys remain unchanged.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_103605_569628`
- Follow-up: do not stack. The larger body increased verifier/JIT program size substantially and did not improve workload throughput.

## Result

Docs-side primary metric:

- Clean baseline `language_ops_total` mean: `19644780415`
- Attempt samples: `19705666680, 19244754469, 19630399634`
- Attempt mean: `19526940261`
- Delta vs clean baseline: `-0.60%`


# otelcol-ebpf-profiler/profiling source-opt attempt: phase3-defer-pid-exists-lpm-lookup

- Time: 2026-06-26 15:15
- App: `otelcol-ebpf-profiler/profiling`
- Status: rejected-no-signal
- Source files:
  - `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracemgmt.h`
- Hypothesis: normal samples for already-known PIDs should not need both the dummy PID LPM lookup and the current-PC mapping LPM lookup.
- Expected hot path: `collect_trace()` runs for perf-event, uprobe, custom, and off-CPU samples; deferring `pid_information_exists(pid)` until mapping failure should remove one LPM lookup from successful known-PID samples.
- Correctness argument: new PID discovery is preserved because mapping failure still checks the dummy PID entry and calls `report_pid()` before returning; no map layout, event payload, tail-call key, attach point, or unwinder dispatch ABI changed.
- Build command: `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_222221_639047`
- Follow-up: do not stack this patch. Static diagnostics improved, but workload throughput regressed by 0.83%.

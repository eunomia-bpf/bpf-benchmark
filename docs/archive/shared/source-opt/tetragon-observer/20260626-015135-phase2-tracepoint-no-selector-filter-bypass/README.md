# tetragon/observer source-opt attempt: phase2-tracepoint-no-selector-filter-bypass

- Time: 2026-06-26 01:51:35
- App: `tetragon/observer`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: phase2 attempt 1 still sends no-selector raw-syscalls events through `TAIL_CALL_FILTER`. This attempt keeps the phase2 attempt 1 base and adds a tracepoint-entry fast path that detects `filter_map[0] == 0`, prepares the same process context, marks the selector as passed, and tail-calls directly to `TAIL_CALL_PROCESS`.
- Expected hot path: `generic_tracepoint_event()` for the raw-syscalls policy before the filter tail call.
- Correctness argument: the fast path only fires when the event has no configured selectors. When it cannot prove the no-selector process context, it falls back to the old `TAIL_CALL_FILTER` path. Selector-enabled events still use the old filter path.
- Build command: included in `build.log`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_085918_851913`
- Performance: stress_ng_sum_bogo_ops_s samples `390527, 390759, 385637`; mean `388975`; baseline mean `358681`; `+8.45%` vs baseline; `-0.56%` vs phase2 attempt 1.
- Follow-up: do not stack this patch. The direct bypass saved a tail call in principle, but it expanded the entry program substantially. Next attempt should use a narrower fast path, avoiding fallback lookup logic in the entry program.

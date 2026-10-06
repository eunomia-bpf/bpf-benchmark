# tetragon/observer source-opt attempt: phase2-filter-args-no-selector-fastpath

- Time: 2026-06-26 01:29:46
- App: `tetragon/observer`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: phase2 attempt 1 improved entry setup, but no-selector events still enter the args phase. This attempt keeps the phase2 attempt 1 base and moves the `!sel.active[SELECTORS_ACTIVE]` accept check before the `filter_map` lookup in `filter_args()`, so no-selector events avoid one map lookup in the args stage.
- Expected hot path: `generic_tracepoint_arg()` after `generic_process_event()` for the raw-syscalls policy.
- Correctness argument: the old code returned `1` immediately when `SELECTORS_ACTIVE` was false. The new code performs the same return before looking up `filter_map`; events with active selectors still follow the old `filter_map` and arg-filter path.
- Build command: included in `build.log`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_083643_226335`
- Performance: stress_ng_sum_bogo_ops_s samples `397404, 388898, 384775`; mean `390359`; baseline mean `358681`; `+8.83%` vs baseline; `-0.20%` vs phase2 attempt 1.
- Follow-up: do not stack this patch. The result suggests the remaining gap is not primarily the args-phase `filter_map` lookup, or the savings is below run-to-run noise for this workload.

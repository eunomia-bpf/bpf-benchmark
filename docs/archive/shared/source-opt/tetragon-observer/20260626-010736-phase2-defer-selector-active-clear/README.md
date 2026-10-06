# tetragon/observer source-opt attempt: phase2-defer-selector-active-clear

- Time: 2026-06-26 01:07:36
- App: `tetragon/observer`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: after phase2 attempt 1, the remaining hot no-selector path may still pay to clear per-selector active bits at entry. This attempt keeps the phase2 attempt 1 base and defers clearing selector-specific active bits until `generic_process_filter()` sees a selector set.
- Expected hot path: `generic_tracepoint_event()` for `raw_syscalls/sys_enter`, plus `generic_start_process_filter()` and `generic_process_filter()` for events that do use selectors.
- Correctness argument: `SELECTORS_ACTIVE` is still reset at every entry. Selector-specific active bits are cleared before the first selector pass when `selectors > 0` and `sel->curr == 0`; later tail-call selector iterations keep the active state they intentionally accumulated. The no-selector path sets `sel->pass = true` and does not consult selector-specific active bits.
- Build command: included in `build.log`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_081407_505208`
- Performance: stress_ng_sum_bogo_ops_s samples `391940, 385567, 395369`; mean `390959`; baseline mean `358681`; `+9.00%` vs baseline; `-0.05%` vs phase2 attempt 1.
- Follow-up: object sizes decreased slightly, but workload throughput did not beat phase2 attempt 1. Do not stack this patch; continue phase2 attempts 3-5 from `20260626-004351-phase2-tracepoint-nop-arg-fastpath`.

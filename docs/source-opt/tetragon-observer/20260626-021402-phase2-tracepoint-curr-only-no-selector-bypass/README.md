# tetragon/observer source-opt attempt: phase2-tracepoint-curr-only-no-selector-bypass

- Time: 2026-06-26 02:14:02
- App: `tetragon/observer`
- Status: accepted-for-analysis; selected as current tetragon phase2 best
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: attempt 4 showed that fully inlining no-selector fallback process lookup into `generic_tracepoint_event()` was too large. This attempt keeps the phase2 attempt 1 base and adds only a narrow fast path: when `filter_map[0] == 0` and `event_find_curr()` succeeds, fill `msg->current`, set `sel.pass`, and tail-call directly to `TAIL_CALL_PROCESS`. Misses fall back to the original `TAIL_CALL_FILTER` path.
- Expected hot path: `generic_tracepoint_event()` for raw-syscalls policy events whose current process is already present in `execve_map`.
- Correctness argument: the fast path is equivalent to the no-selector accept branch in `generic_process_filter()` when `event_find_curr()` succeeds. Cases with selectors, missing filter entries, or missing current process state still use the original filter program and fallback lookup logic.
- Build command: included in `build.log`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_092152_089522`
- Performance: stress_ng_sum_bogo_ops_s samples `393846, 395075, 386967`; mean `391962`; baseline mean `358681`; `+9.28%` vs baseline; `+0.21%` vs phase2 attempt 1; `+0.62%` vs first-round best.
- Follow-up: keep this as the best Tetragon source-opt patch so far, but it still does not reach the 10% target. Further Tetragon gains likely need a different mechanism than active-bit or no-selector filter micro-tuning.

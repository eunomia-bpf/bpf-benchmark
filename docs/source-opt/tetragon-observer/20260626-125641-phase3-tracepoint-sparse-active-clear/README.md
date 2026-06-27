# tetragon/observer source-opt attempt: phase3-tracepoint-sparse-active-clear

- Time: 2026-06-26 12:56:41
- App: `tetragon/observer`
- Status: accepted-for-analysis; selected as current tetragon phase3 base
- Source files:
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Base: phase2 best `20260626-021402-phase2-tracepoint-curr-only-no-selector-bypass`.
- Hypothesis: the phase2 best already bypasses `TAIL_CALL_FILTER` for no-selector tracepoint events when `event_find_curr()` succeeds. This attempt keeps that behavior and moves the full `sel.active[]` clear into the fallback path. The fast path only clears `SELECTORS_ACTIVE`, which is the gate checked by the later args stage, avoiding a full selector-active store ladder on the no-selector path.
- Expected hot path: `generic_tracepoint_event()` for the raw-syscalls policy in `stress_ng_tetragon_policy_hot`.
- Correctness argument: if the no-selector fast path succeeds, no selector-specific active bits are consumed because `SELECTORS_ACTIVE` is cleared and `sel.pass` is set. If the fast path misses, the code clears the full `sel.active[]` array before tail-calling the original filter path, preserving selector/fallback behavior.
- Build command: `make -C vendor tetragon-x86`
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_200430_726187`
- Performance: stress_ng_sum_bogo_ops_s samples `394428, 393844, 390877`; mean `393050`; baseline mean `358681`; `+9.58%` vs baseline; `+0.28%` vs phase2 best.
- Follow-up: stack the next Tetragon attempt on this base. It improves phase2 best but still misses the 10% target.

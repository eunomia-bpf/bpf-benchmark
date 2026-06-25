# tetragon/observer source-opt attempt: lazy-ns-cap-skip-empty-namespace-loop

- Time: 2026-06-25 11:16:13
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: attempt 3's lazy namespace/capability state was the best tetragon result so far. This attempt keeps that optimization and adds one local control-flow reduction: if the matchNamespace section length is zero, skip the existing unrolled namespace loop entirely instead of entering it and checking `len > 0` on every unrolled slot.
- Expected hot path: `generic_start_process_filter()` / `generic_tracepoint_event()` -> `generic_process_filter()` -> `selector_process_filter()`.
- Correctness argument: the namespace loop body was already guarded by `if (len > 0)`. Wrapping the loop with the same condition preserves behavior for empty and non-empty namespace sections. Namespace and capability snapshots are still materialized before the same selector consumers as attempt 3.
- Build command: included in `run-command.sh`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_182312_224669`
- Performance: stress_ng_sum_bogo_ops_s samples `391278, 386987, 390431`; mean `389565`; baseline mean `358681`; `+8.61%` vs baseline; `+0.43%` vs attempt 3.
- Follow-up: this is the best tetragon result so far and should be the new base for any further stacked source optimizations, but it is still below the 10% target.

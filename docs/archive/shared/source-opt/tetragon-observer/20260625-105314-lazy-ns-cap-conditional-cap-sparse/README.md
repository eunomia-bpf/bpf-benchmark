# tetragon/observer source-opt attempt: lazy-ns-cap-conditional-cap-sparse

- Time: 2026-06-25 10:53:14
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: generic process-filter entry does not need namespace and capability snapshots unless the selected policy section consumes namespace, capability, namespace-change, or capability-change selectors. Moving those reads into selector processing removes unconditional helper/probe work from hot events, and cap selectors with `ns == 0` do not need namespace state at all.
- Expected hot path: `generic_start_process_filter()` / `generic_tracepoint_event()` -> `generic_process_filter()` -> `selector_process_filter()`.
- Correctness argument: selector parsing, policy semantics, event payload layout, map layout, tail-call keys, and app attach points are unchanged. Namespace and capability fields are populated immediately before their original consumers. Capability filters only skip namespace collection when `caps->ns == 0`, matching the existing `process_filter_capabilities()` and `process_filter_capability_change()` logic that only reads namespace state when `ns != 0`.
- Build command: included in `run-command.sh`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_175958_060141`
- Performance: stress_ng_sum_bogo_ops_s samples `391844, 381971, 384998`; mean `386271`; baseline mean `358681`; `+7.69%` vs baseline.
- Follow-up: performance is positive but below the 10% target and below attempt 3's `+8.15%`; try a larger but still source-only selector hot-path optimization next.

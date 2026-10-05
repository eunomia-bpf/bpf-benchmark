# tetragon/observer source-opt attempt: filter-args-active-fastpath

- Time: 2026-06-25 10:06:49 America/Vancouver
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
- Hypothesis: checking `SELECTORS_ACTIVE` before `filter_map` lookup avoids one map lookup on generic events whose process prefilter accepted by default with no active selectors.
- Expected hot path: generic argument filter tail-call path after `generic_process_filter()`.
- Correctness argument: when `e->sel.active[SELECTORS_ACTIVE]` is false, the old code returns `1` after an unused successful `filter_map` lookup; moving the check earlier preserves the same accept-by-default result and does not alter selector, map, payload, or tail-call ABI.
- Build command: `make corpus`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260625_171339_967034`
- Performance: stress_ng_sum_bogo_ops_s samples `358593, 353455, 355383`, mean=355810, -0.80% vs clean-source baseline mean=358681.
- Follow-up: correctness passed, but this isolated branch/map-lookup reorder did not improve workload throughput; later attempts should combine larger generic event bookkeeping reductions.

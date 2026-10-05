# tetragon/observer source-opt attempt: sparse-selector-active-clear

- Time: 2026-06-25 09:45:57 America/Vancouver
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
- Hypothesis: clearing only the selector active slots that can be read on the hot path removes per-event stores without changing selector state.
- Expected hot path: generic kprobe/tracepoint event entry before process filtering.
- Correctness argument: selector reads use indices `0..MAX_SELECTORS` and sentinel `SELECTORS_ACTIVE`; indices `6..30` and `32` are not read by `generic_filter_arg()` or `next_selidx()`.
- Build command: `make corpus`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260625_165241_915913`
- Performance: stress_ng_sum_bogo_ops_s samples `362792, 351299, 355765`, mean=356619, -0.57% vs clean-source baseline mean=358681.
- Follow-up: correctness passed, but this isolated store reduction did not improve workload throughput; later attempts should target larger generic filtering/map-lookup costs.

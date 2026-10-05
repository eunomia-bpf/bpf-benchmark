# tetragon/observer source-opt attempt: lazy-ns-cap-selector-state

- Time: 2026-06-25 10:28:00 America/Vancouver
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: namespace and capability state is only needed by namespace/capability selectors, so moving those reads from generic event entry to the selector sections that consume them removes fixed per-event helper/probe-read cost on ordinary selectors.
- Expected hot path: generic kprobe/tracepoint process-filter path for the policy-hot stress-ng workload.
- Correctness argument: namespace/capability selector sections still initialize the same `msg->ns` and `msg->caps` fields before use; event payload, maps, selector layout, and tail-call dispatch are unchanged.
- Build command: `make corpus`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260625_173550_665242`
- Performance: stress_ng_sum_bogo_ops_s samples `392895, 386207, 384593`, mean=387898, +8.15% vs clean-source baseline mean=358681.
- Follow-up: correctness passed and performance improved materially, but it is below the 10% target; use this as the base direction for larger follow-up attempts.

# katran source-opt phase2 attempt: udp-flow-migration-require-dst

- Time: 2026-06-25 16:49:17 PDT
- App: `katran`
- Status: accepted-for-analysis
- Phase: 2
- Source files: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Stacked base: clean upstream source; no first-round katran patch had positive signal, so none is stacked.
- Hypothesis: `check_udp_flow_migration()` should only check down-real maps after a destination real has already been selected. The current `dst` test is effectively always true because callers pass `&dst`, so UDP LRU-miss/new-flow paths can pay unnecessary `is_under_flood()` and down-real map lookup cost.
- Expected hot path: `balancer_ingress()` -> `process_packet()` -> UDP VIP lookup -> LRU/CH routing -> `check_udp_flow_migration()`.
- Correctness argument: UDP flow migration only removes an existing selected destination when that real is marked down. If no destination exists yet, there is nothing to migrate; consistent hashing still selects a destination afterward.
- Build command: `make -C vendor katran-x86`, then formal `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_235638_664542`.
- Performance: `pktgen_total_pps` samples `3299495, 3294334, 3321729`, mean `3305186`, `+7.97%` vs clean-source baseline.
- Follow-up: positive signal; stack future katran phase2 attempts on this patch.

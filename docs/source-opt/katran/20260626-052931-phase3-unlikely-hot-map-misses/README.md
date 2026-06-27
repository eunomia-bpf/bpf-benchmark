# katran source-opt attempt: phase3-unlikely-hot-map-misses

- Time: 2026-06-26 05:29
- App: `katran`
- Status: accepted-for-analysis
- Source file: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Base: phase2 best `20260625-182615-phase2-cache-vip-metadata`
- Hypothesis: the normal pktgen path should hit VIP/stats/LRU/control maps.
  Marking hot-path map-miss checks as unlikely may improve branch layout in the
  generated BPF/JIT path without changing functionality.
- Expected hot path: IPv4/UDP pktgen traffic with successful VIP lookup, valid
  per-CPU LRU map, available stats maps, available QUIC stats map, available
  control value, and available per-VIP/per-real stats entries.
- Correctness argument: this patch only wraps existing boolean checks in
  `__builtin_expect(<condition>, 0)`. It does not remove any fallback, change any
  map key/value layout, change packet parsing, change action selection, or change
  stats semantics.
- Build command: `make -C vendor katran-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_123820_861697`
- Performance: pktgen total pps mean `3349874` from samples
  `3379459, 3355767, 3314396`; `+9.43%` vs clean baseline and `+0.03%` vs
  phase2 best.
- Decision: stack as the new katran best base. The win over phase2 best is small
  but positive under the formal 3-sample run, and correctness passed.
- Follow-up: continue katran phase3 attempts from this base, but look for a
  larger semantic-preserving reduction in repeated stats/LRU work to push past
  the 10% target.

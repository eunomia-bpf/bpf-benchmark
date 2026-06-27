# katran source-opt attempt: phase3-thoff-parser-reuse

- Time: 2026-06-26 04:39
- App: `katran`
- Status: completed-not-stacked
- Source files:
  - `vendor/repos/katran/katran/lib/bpf/balancer.c`
  - `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Base: phase2 best `20260625-182615-phase2-cache-vip-metadata`
- Hypothesis: `parse_l3_headers()` already returns the transport header offset. Reusing that offset in UDP, QUIC, and stable-routing parsing should remove repeated `calc_offset()` work on the hot path while keeping packet bounds checks intact.
- Expected hot path: IPv4/UDP pktgen traffic with VIP flags `F_QUIC_VIP | F_GLOBAL_LRU | F_HASH_SRC_DST_PORT | F_UDP_STABLE_ROUTING_VIP | F_UDP_FLOW_MIGRATION`.
- Correctness argument: the patch only threads the already-computed transport offset into parser helpers. It does not change map layout, packet ABI, tail-call keys, VIP flags, destination selection, or action semantics.
- Build command: `make -C vendor katran-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_114838_879478`
- Performance: pktgen total pps mean `3338745` from samples `3337569, 3357814, 3320853`; `+9.07%` vs clean baseline and `-0.30%` vs phase2 best.
- Decision: do not stack. Static code size improved, but formal workload throughput did not beat the current katran best.
- Follow-up: switch katran phase3 attempt 2 to a larger hot-path diagnosis instead of parser-offset micro-optimization. Start from phase2 best again and look for map/helper/stat-update or branch-layout work that can exceed the current `+9.40%` ceiling without removing functionality.

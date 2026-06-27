# katran source-opt attempt: phase3-quic-v0-cid-fast-reject

- Time: 2026-06-26 05:04
- App: `katran`
- Status: completed-not-stacked
- Source files:
  - `vendor/repos/katran/katran/lib/bpf/balancer.c`
  - `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Base: phase2 best `20260625-182615-phase2-cache-vip-metadata`
- Hypothesis: pktgen sends ordinary UDP payload while the benchmark VIP enables `F_QUIC_VIP`. `parse_quic()` can return immediately when the connection-id version bits are `0`, because the existing code does not route CID version 0 and falls back to CH.
- Expected hot path: IPv4/UDP pktgen traffic whose UDP payload is not a valid Katran-routable QUIC CID.
- Correctness argument: for `connIdVersion == 0`, the pre-existing code already left `server_id=FURTHER_PROCESSING` and `is_initial=false`, which makes the caller increment `ch_routed` and continue with CH/LRU routing. The patch returns that same parse result earlier. CID versions 1, 2, and 3 are unchanged.
- Build command: `make -C vendor katran-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_121345_246104`
- Performance: pktgen total pps mean `3320793` from samples `3276898, 3371790, 3313690`; `+8.48%` vs clean baseline and `-0.84%` vs phase2 best.
- Decision: do not stack. The v0 CID shortcut did not improve the current best and likely added branch pressure despite shortening the invalid-CID path.
- Follow-up: stop spending katran phase3 attempts on parser micro-paths. The next attempt should diagnose heavier per-packet costs: `is_under_flood()` / conn-rate stats, LRU miss stats, and repeated stats map updates.

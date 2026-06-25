# katran source-opt attempt: stable-rt-header-early-return

- Time: 20260625-025627
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Hypothesis: make `parse_udp_stable_rt_hdr()` return immediately when the UDP
  payload is not a stable routing header, avoiding the later null-connId branch.
- Expected hot path: UDP packets that do not carry the stable routing header.
- Correctness argument: the old non-stable path left `connId` null and returned
  at the later check. The stable path still performs the same bounds check,
  reads the same `connection_id`, and sets `is_stable_rt_pkt`.
- Build command: `make corpus` via the recorded run command.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_100305_598103`
- Follow-up: completed; katran source restored with
  `patch -p1 -R < docs/source-opt/katran/20260625-025627-stable-rt-header-early-return/source.diff`.

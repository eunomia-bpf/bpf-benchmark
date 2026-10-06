# katran source-opt attempt: icmp-protocol-refresh

- Time: 20260625-015559
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Hypothesis: avoid reloading `pckt.flow.proto` on the non-ICMP hot path after
  `handle_if_icmp()`. Only ICMP error packets rewrite `pckt.flow.proto` to the
  inner packet protocol.
- Expected hot path: IPv4 UDP `xdp_pktgen` packet where `F_ICMP` is unset.
- Correctness argument: non-ICMP packets keep the `protocol` value already
  returned by `parse_l3_headers()`. ICMP error packets still refresh
  `protocol` from `pckt.flow.proto`; ICMP echo/pass/drop returns before this
  point.
- Build command: `make corpus` via the recorded run command.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_090323_284447`
- Follow-up: restore katran source with
  `patch -p1 -R < docs/source-opt/katran/20260625-015559-icmp-protocol-refresh/source.diff`
  after recording the result. Completed; katran nested repo has no remaining
  source diff.

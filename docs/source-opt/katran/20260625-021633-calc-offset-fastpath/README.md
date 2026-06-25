# katran source-opt attempt: calc-offset-fastpath

- Time: 20260625-021633
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Hypothesis: make non-ICMP packet offset calculation return immediately,
  matching the UDP/TCP hot path, while keeping ICMP inner-header offsets
  equivalent through existing constants.
- Expected hot path: IPv4 UDP `xdp_pktgen` packet calling `parse_udp()` with
  `F_ICMP` unset.
- Correctness argument: non-ICMP offsets remain
  `sizeof(ethhdr)+sizeof(ip/ip6)`. ICMP offsets remain
  `sizeof(ethhdr)+IPV4_PLUS_ICMP_HDR` or
  `sizeof(ethhdr)+IPV6_PLUS_ICMP_HDR`, which are the same sums as before.
- Build command: `make corpus` via the recorded run command.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_092311_749645`
- Follow-up: completed; katran source restored with
  `patch -p1 -R < docs/source-opt/katran/20260625-021633-calc-offset-fastpath/source.diff`.

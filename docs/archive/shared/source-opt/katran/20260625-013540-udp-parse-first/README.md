# katran source-opt attempt: udp-parse-first

- Time: 20260625-013540
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/balancer.c`
- Hypothesis: put the UDP protocol branch before TCP in `process_packet()`,
  matching the `xdp_pktgen` workload's UDP hot path while keeping TCP and
  fallback behavior unchanged.
- Expected hot path: IPv4 UDP packet parse, VIP lookup, QUIC/stable-routing
  fallback, LRU/CH selection, IPIP/GUE encapsulation.
- Correctness argument: no map layout, event payload, tail-call key, attach
  point, statistics counter, or workload changes. TCP parsing is still executed
  for TCP packets; UDP parsing and GUE handling are unchanged.
- Build command: `make corpus` via the recorded run command.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_084248_406394`
- Follow-up: restore katran source with
  `patch -p1 -R < docs/source-opt/katran/20260625-013540-udp-parse-first/source.diff`
  after recording the result. Completed; katran nested repo has no remaining
  source diff.

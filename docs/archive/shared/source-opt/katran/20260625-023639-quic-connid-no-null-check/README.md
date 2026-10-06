# katran source-opt attempt: quic-connid-no-null-check

- Time: 20260625-023639
- App: `katran`
- Status: accepted-for-analysis
- Source files: `vendor/repos/katran/katran/lib/bpf/pckt_parsing.h`
- Hypothesis: remove an unreachable `connId` null check from `parse_quic()`
  after the long-header and short-header branches, reducing one branch in the
  QUIC parsing path.
- Expected hot path: UDP VIPs with QUIC parsing enabled.
- Correctness argument: both feasible branches assign `connId` after bounds
  checks; paths that cannot assign already return `result` before reaching the
  removed block.
- Build command: `make corpus` via the recorded run command.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_094328_513110`
- Follow-up: completed; katran source restored with
  `patch -p1 -R < docs/source-opt/katran/20260625-023639-quic-connid-no-null-check/source.diff`.

# cilium/agent source-opt attempt: tail-ipv4-to-endpoint-revalidate-unlikely

- Time: 2026-06-25 09:04:37 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: `tail_ipv4_to_endpoint()` usually sees valid packet data after
  tail calls and after proxy redirect preparation. Marking failed
  `revalidate_data()` checks `unlikely()` can improve branch layout without
  changing error handling.
- Expected hot path: IPv4 endpoint ingress path for `cilium_endpoint_pktgen`.
- Correctness argument: `unlikely()` is Cilium's existing compiler hint macro
  and preserves the call to `revalidate_data()` plus all pointer outputs. The
  patch does not change identity lookup, policy decisions, proxy redirect,
  metadata layout, map access, tail-call indexes, return codes, or drop
  notifications.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_161125_111575`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 717G 152G 83% /`.
- Performance: pktgen total pps samples `1668711, 1666812, 1680849`;
  mean `1672124`; docs-side change vs Cilium clean-source baseline `+12.37%`.
- Follow-up: if accepted, compare raw pktgen payload externally against the
  clean-source baseline.

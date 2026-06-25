# cilium/agent source-opt attempt: from-container-error-unlikely

- Time: 2026-06-25 08:05:10 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: `cil_from_container()` handles ordinary IPv4 endpoint traffic in
  the hot path, while invalid ethertype and failed L3 pull are error paths.
  Marking those branches `unlikely()` can improve generated branch layout
  without changing behavior.
- Expected hot path: endpoint egress entry program `cil_from_container()` for
  `cilium_endpoint_pktgen`.
- Correctness argument: `unlikely()` is Cilium's existing compiler hint macro
  and preserves the boolean value of the condition. The patch does not change
  trace emission, metadata clearing, queue mapping reset, tail-call indexes,
  packet parsing, maps, policy checks, or return codes.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_151130_130358`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 714G 155G 83% /`.
- Follow-up: if accepted, compare raw pktgen payload externally against the
  clean-source baseline.

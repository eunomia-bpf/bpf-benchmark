# cilium/agent source-opt attempt: cil-lxc-policy-error-unlikely

- Time: 2026-06-25 08:25:28 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: `cil_lxc_policy()` is an ingress policy entry point where valid
  Ethernet type and successful L3 header pull are the common packet path.
  Marking the unsupported-L2 and failed-pull paths `unlikely()` can improve
  branch layout without changing behavior.
- Expected hot path: local endpoint ingress policy path reached by
  `cilium_endpoint_pktgen`.
- Correctness argument: `unlikely()` is Cilium's existing compiler hint macro
  and preserves the value and side effects of both conditions. The patch does
  not change metadata, map access, tail-call indexes, policy decisions, packet
  parsing, return codes, or notification payloads.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_153206_021422`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 715G 154G 83% /`.
- Follow-up: if accepted, compare raw pktgen payload externally against the
  clean-source baseline.

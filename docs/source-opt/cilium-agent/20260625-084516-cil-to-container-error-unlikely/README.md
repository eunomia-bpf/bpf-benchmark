# cilium/agent source-opt attempt: cil-to-container-error-unlikely

- Time: 2026-06-25 08:45:16 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: `cil_to_container()` handles the endpoint ingress path for
  ordinary packets, while unsupported L2 and failed L3 header pull are error
  paths. Marking those branches `unlikely()` can improve branch layout without
  changing behavior.
- Expected hot path: reverse direction of `cilium_endpoint_pktgen` traffic that
  reaches the endpoint through `cil_to_container()`.
- Correctness argument: `unlikely()` is Cilium's existing compiler hint macro
  and preserves the value and side effects of both conditions. The patch does
  not change identity inheritance, proxy mark handling, host firewall branches,
  metadata layout, tail-call indexes, packet parsing, return codes, or drop
  notifications.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_155126_330125`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 716G 153G 83% /`.
- Follow-up: if accepted, compare raw pktgen payload externally against the
  clean-source baseline.

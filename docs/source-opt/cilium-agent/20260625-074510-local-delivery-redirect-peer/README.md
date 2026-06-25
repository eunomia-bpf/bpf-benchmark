# cilium/agent source-opt attempt: local-delivery-redirect-peer

- Time: 2026-06-25 07:45:10 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis
- Source files: `vendor/repos/cilium/bpf/lib/local_delivery.h`
- Hypothesis: `local_delivery()` can avoid materializing
  `should_redirect_peer(from_host)` for the policy-at-source branch by using
  the equivalent condition `(!ENABLE_HOST_ROUTING || from_host) &&
  !enable_netkit`.
- Expected hot path: endpoint-to-endpoint IPv4 local delivery from
  `bpf_lxc.c` through `ipv4_local_delivery()` into `local_delivery()`.
- Correctness argument: `should_redirect_peer(from_host)` is exactly
  `ENABLE_HOST_ROUTING && !from_host && !enable_netkit`. Therefore
  `!should_redirect_peer(from_host) && !enable_netkit` is equivalent to
  `(!ENABLE_HOST_ROUTING || from_host) && !enable_netkit`. In the branch,
  `use_redirect_peer` is necessarily false, so passing `false` to
  `redirect_ep()` preserves redirect behavior. The patch does not change map
  definitions, tail-call keys, endpoint metadata, policy decisions, packet
  rewrites, or attach points.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_145141_817976`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 713G 157G 83% /`.
- Follow-up: if accepted, compare raw pktgen payload externally against the
  clean-source baseline.

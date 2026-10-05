# cilium/agent source-opt attempt: phase2-best-plus-local-delivery

- Time: 2026-06-26 00:13 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/cilium/bpf/bpf_lxc.c`
  - `vendor/repos/cilium/bpf/lib/local_delivery.h`
- Hypothesis: keep the first-round best `tail_ipv4_to_endpoint()`
  failed-`revalidate_data()` hints, then stack only the first-round positive
  `local_delivery()` peer-redirect condition simplification. Unlike the earlier
  all-first-round stack, this tests one additional local-delivery handoff
  optimization without adding unrelated cold-branch hints.
- Expected hot path: endpoint-to-endpoint IPv4 UDP pktgen egress forwarding into
  local endpoint delivery, destination ingress policy, then redirect to the
  destination endpoint.
- Correctness argument: the `local_delivery()` rewrite preserves the old
  `!should_redirect_peer(from_host)` condition because
  `should_redirect_peer(from_host)` is
  `ENABLE_HOST_ROUTING && !from_host && !CONFIG(enable_netkit)`, and the branch
  still separately checks `!CONFIG(enable_netkit)`. In that branch,
  `use_redirect_peer` is therefore known false, so passing `false` to
  `redirect_ep()` preserves redirect behavior. No policy, CT, NAT, map layout,
  metadata key, packet rewrite, attach point, or tail-call target changes.
- Build command: `make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o`
  for local diagnostics; formal run uses `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_072138_036296`
- Performance: pktgen total pps samples `1534942, 1516759, 1532465`,
  mean `1528055.33`; `+2.68%` vs clean baseline mean `1488103`, `-8.62%`
  vs first-round best mean `1672124`.
- Follow-up: do not select as the Cilium phase2 base. Keep the first-round
  focused `tail_ipv4_to_endpoint()` revalidate patch as the Cilium best result.

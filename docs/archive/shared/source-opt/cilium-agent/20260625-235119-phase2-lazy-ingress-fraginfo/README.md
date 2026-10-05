# cilium/agent source-opt attempt: phase2-lazy-ingress-fraginfo

- Time: 2026-06-25 23:51 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; rejected-no-signal; not selected as next base
- Source files:
  - `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: keep the first-round best `tail_ipv4_to_endpoint()`
  failed-`revalidate_data()` hints, then reduce fixed work in the ingress
  policy path by computing IPv4 `fraginfo` only when fragment tracking is
  disabled or reply/rev-NAT handling needs `ipfrag_has_l4_header()`.
- Expected hot path: bidirectional endpoint-to-endpoint IPv4 UDP pktgen:
  egress CT/policy, local delivery, ingress policy, and final redirect to the
  destination endpoint.
- Correctness argument: the patch preserves fragment handling semantics:
  `is_untracked_fragment` remains false when IPv4 fragment tracking is enabled,
  and reply/rev-NAT still computes `fraginfo` before checking whether the packet
  has an L4 header. It does not change policy inputs, CT map selection, CT
  creation, NAT behavior, metadata, tail-call keys, packet rewrite, or return
  values.
- Build command: `make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o`
  for local diagnostics; formal run uses `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_065929_399049`
- Performance: pktgen total pps samples `1460702, 1462853, 1446400`,
  mean `1456651.67`; `-2.11%` vs clean baseline mean `1488103`, `-12.89%`
  vs first-round best mean `1672124`.
- Follow-up: do not keep this as a Cilium phase2 base. The config-branching
  fraginfo rewrite passed correctness but regressed below clean source, so the
  next attempt should avoid adding rodata config branches to `ipv4_policy()`.

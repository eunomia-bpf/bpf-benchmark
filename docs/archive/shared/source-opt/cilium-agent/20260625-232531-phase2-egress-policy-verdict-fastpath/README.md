# cilium/agent source-opt attempt: phase2-egress-policy-verdict-fastpath

- Time: 2026-06-25 23:25 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; rejected-no-signal; not selected as next base
- Source files:
  - `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: keep the first-round best `tail_ipv4_to_endpoint()`
  `revalidate_data()` hints, then mark rare IPv4 egress policy error paths in
  `handle_ipv4_from_lxc()` as cold. The endpoint-to-endpoint pktgen workload
  varies destination ports, so CT_NEW is not assumed cold; only auth-required,
  non-OK verdict, and proxy-redirect reply branches are marked `unlikely()`.
- Expected hot path: IPv4 endpoint egress through `tail_handle_ipv4_cont()`,
  ingress local delivery, and `tail_ipv4_to_endpoint()`.
- Correctness argument: the patch does not change policy lookup inputs, verdict
  notification conditions, CT state handling, proxy redirect behavior, metadata,
  maps, tail-call keys, packet rewrite, or return values.
- Build command: `make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o`
  for local diagnostics; formal run uses `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_063507_838342`
- Performance: pktgen_total_pps mean `1476514.33`; samples `1473623,
  1488389, 1467531`; `-0.78%` vs clean baseline and `-11.70%` vs
  first-round best mean `1672124`.
- Follow-up: do not use this caller-side verdict/proxy hint patch as a Cilium
  phase2 base. It passed correctness but regressed below clean source, so the
  next attempt should change strategy instead of adding more branch hints to
  this path.

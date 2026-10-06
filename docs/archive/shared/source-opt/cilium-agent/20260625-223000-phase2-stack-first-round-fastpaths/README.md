# cilium/agent source-opt attempt: phase2-stack-first-round-fastpaths

- Time: 2026-06-25 22:30 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/cilium/bpf/bpf_lxc.c`
  - `vendor/repos/cilium/bpf/lib/local_delivery.h`
- Hypothesis: the first-round Cilium patches all passed correctness and each
  had a positive pktgen signal. Stacking them should improve the same IPv4
  endpoint-to-endpoint path more than the best single patch by improving branch
  layout across `cil_from_container()`, `local_delivery()`,
  `tail_ipv4_to_endpoint()`, `cil_lxc_policy()`, and `cil_to_container()`.
- Expected hot path: bidirectional `cilium_endpoint_pktgen` traffic through
  endpoint egress, local delivery, ingress policy tail calls, and endpoint
  ingress.
- Correctness argument: the patch only uses Cilium's existing `unlikely()`
  macro on error paths and preserves the existing redirect-peer condition by
  expanding `!should_redirect_peer(from_host)` into its equivalent expression
  before passing the known `false` value into `redirect_ep()`.
- Build command: `make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o`
  for local diagnostics; formal run uses `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_054657_483125`
- Performance: pktgen total pps samples `1595444, 1626858, 1630134`,
  mean `1617478.67`; `+8.69%` vs clean baseline, `-3.27%` vs the
  first-round best (`1672124`).
- Follow-up: do not use this all-first-round stacked patch as the next Cilium
  base. It preserved correctness and stayed positive against clean source, but
  stacking every small branch-layout hint lost performance relative to the
  focused `tail_ipv4_to_endpoint()` patch.

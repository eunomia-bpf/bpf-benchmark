# cilium/agent source-opt attempt: phase2-tail-ipv4-policy-ok-fastpath

- Time: 2026-06-25 23:02 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; not selected as next base
- Source files:
  - `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: keep the first-round best `tail_ipv4_to_endpoint()`
  `revalidate_data()` hints, then make the common ingress-policy result
  (`CTX_ACT_OK`) an explicit `likely()` fast path. The benchmark disables L7
  proxy and runs allowed endpoint-to-endpoint IPv4 traffic, so proxy redirect
  and drop handling should be cold while preserving semantics.
- Expected hot path: local endpoint-to-endpoint IPv4 traffic through
  `tail_ipv4_to_endpoint()` after ingress CT/policy tail calls.
- Correctness argument: the patch does not change policy lookup inputs, proxy
  redirect handling, drop notification, metadata, maps, tail-call keys, packet
  rewrite, or return values. It only replaces an equivalent `switch (ret)` with
  an explicit `likely(ret == CTX_ACT_OK)` branch and keeps the same proxy/error
  fall-through behavior.
- Build command: `make -C vendor/repos/cilium/bpf CLANG=clang-18 bpf_lxc.o`
  for local diagnostics; formal run uses `make corpus`.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_061027_069307`
- Performance: pktgen total pps samples `1635252, 1608005, 1585824`,
  mean `1609693.67`; `+8.17%` vs clean baseline, `-3.73%` vs the
  first-round best (`1672124`).
- Follow-up: do not use this fast-path rewrite as the next Cilium base. It
  passed correctness but was slower than the focused first-round best and also
  slightly slower than the phase2 all-first-round stack.

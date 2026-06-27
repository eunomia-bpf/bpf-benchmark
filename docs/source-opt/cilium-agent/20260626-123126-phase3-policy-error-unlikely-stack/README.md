# cilium/agent source-opt attempt: phase3-policy-error-unlikely-stack

- Time: 2026-06-26 12:31 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; selected as current Cilium phase3 best
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: after attempt 4 showed that small first-round datapath error-path hints compose with the `tail_ipv4_to_endpoint()` base, another independently positive Cilium datapath hint in `cil_lxc_policy()` may further improve branch layout without touching policy/event semantics.
- Expected hot path: endpoint-to-endpoint IPv4 pktgen traffic through `tail_ipv4_to_endpoint()`, `cil_lxc_policy()`, and `cil_to_container()` loaded by the real `cilium-agent`.
- Correctness argument: the patch only wraps existing invalid-ethertype and failed-L3-header-pull checks in Cilium's existing `unlikely()` macro. It keeps map layout, event ABI, tail-call keys, policy checks, attach points, helper calls, and return actions unchanged.
- Build command: `make -C vendor cilium-x86`
- Run command: `SKIP_REJIT=all BPFREJIT_CORPUS_APPS='cilium/agent' BPFREJIT_CORPUS_BPF_STATS=0 SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Result path: `corpus/results/x86_kvm_corpus_20260626_193753_200824`
- Performance: pktgen_total_pps samples `1713045, 1718508, 1710806`; mean `1714120`; `+15.19%` vs clean baseline and `+1.66%` vs prior Cilium phase3 base.
- Follow-up: Cilium phase3 is complete; this is the current Cilium source-opt best. Continue phase3 with `tetragon/observer`.

# cilium/agent source-opt attempt: phase3-cil-to-container-error-unlikely-stack

- Time: 2026-06-26 12:09 PDT
- App: `cilium/agent`
- Status: accepted-for-analysis; selected as current Cilium phase3 base
- Source files: `vendor/repos/cilium/bpf/bpf_lxc.c`
- Hypothesis: the first-round `cil_to_container()` error-path branch hints may compose with the phase3 `tail_ipv4_to_endpoint()` reserved-identity cold-path base, unlike the larger policy/event rewrites that regressed attempts 2-3.
- Expected hot path: endpoint-to-endpoint IPv4 pktgen traffic through Cilium datapath, with `tail_ipv4_to_endpoint()` and `cil_to_container()` both loaded by the real `cilium-agent`.
- Correctness argument: the patch only marks existing error branches with Cilium's existing `unlikely()` macro and keeps map layout, event ABI, tail-call keys, policy checks, attach points, and return actions unchanged.
- Build command: `make -C vendor cilium-x86`
- Run command: `SKIP_REJIT=all BPFREJIT_CORPUS_APPS='cilium/agent' BPFREJIT_CORPUS_BPF_STATS=0 SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus`
- Result path: `corpus/results/x86_kvm_corpus_20260626_191637_695574`
- Performance: pktgen_total_pps samples `1688102, 1686224, 1684311`; mean `1686212`; `+13.31%` vs clean baseline and `+0.81%` vs prior Cilium phase3 base.
- Follow-up: use this stacked patch as the Cilium phase3 base for attempt 5; prefer composable datapath hot-path changes over policy verdict/event preparation.

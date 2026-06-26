# cilium/agent source-opt summary

App: `cilium/agent`

Status: phase2-complete

Start state:

- Started: 2026-06-25 07:24:20 PDT
- Initial worktree status: existing source-opt docs and corpus result files
  present; `vendor/repos/cilium` was clean.
- Initial disk: `/dev/nvme0n1p2 915G 711G 158G 82% /`
- Benchmark contract: single-app `make corpus`, `SKIP_REJIT=all`,
  `SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1`,
  `BPFREJIT_CORPUS_BPF_STATS=0`
- Runner: real `cilium-agent` with workload `cilium_endpoint_pktgen`
- BPF source root: `vendor/repos/cilium/bpf`

Baseline:

- Status: accepted
- Result path: `corpus/results/x86_kvm_corpus_20260625_143038_806522`
- App result: `corpus/results/x86_kvm_corpus_20260625_143038_806522/details/apps/cilium__agent.json`
- Gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples each had forward/reverse pktgen component returncodes `[0, 0]`;
  `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; disk after run:
  `/dev/nvme0n1p2 915G 712G 158G 82% /`.

Attempts:

| Attempt | Status | Result path | Notes |
| --- | --- | --- | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_145141_817976` | `local_delivery()` expands the `!should_redirect_peer(from_host) && !enable_netkit` condition into an equivalent direct expression and passes `false` in that branch. |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_151130_130358` | `cil_from_container()` marks invalid ethertype and failed L3 header pull branches with Cilium's existing `unlikely()` macro. |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_153206_021422` | `cil_lxc_policy()` marks unsupported-L2 and failed L3 header pull branches with Cilium's existing `unlikely()` macro. |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_155126_330125` | `cil_to_container()` marks unsupported-L2 and failed L3 header pull branches with Cilium's existing `unlikely()` macro. |
| 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_161125_111575` | `tail_ipv4_to_endpoint()` marks both failed `revalidate_data()` checks with Cilium's existing `unlikely()` macro. |

Phase2 attempts:

| Attempt | Status | Result path | Performance | Notes |
| --- | --- | --- | --- | --- |
| 1 | accepted-for-analysis; not selected as next base | `corpus/results/x86_kvm_corpus_20260626_054657_483125` | pktgen_total_pps mean `1617478.67`; samples `1595444, 1626858, 1630134`; `+8.69%` vs clean baseline, `-3.27%` vs first-round best | Stacked all five first-round positive patches. Correctness passed, but broad stacking regressed relative to the focused `tail_ipv4_to_endpoint()` best patch. |
| 2 | accepted-for-analysis; not selected as next base | `corpus/results/x86_kvm_corpus_20260626_061027_069307` | pktgen_total_pps mean `1609693.67`; samples `1635252, 1608005, 1585824`; `+8.17%` vs clean baseline, `-3.73%` vs first-round best | Started from the first-round best revalidate patch, then rewrote `tail_ipv4_to_endpoint()` policy result handling as an explicit `likely(ret == CTX_ACT_OK)` fast path. Correctness passed but did not beat current best. |
| 3 | accepted-for-analysis; rejected-no-signal; not selected as next base | `corpus/results/x86_kvm_corpus_20260626_063507_838342` | pktgen_total_pps mean `1476514.33`; samples `1473623, 1488389, 1467531`; `-0.78%` vs clean baseline, `-11.70%` vs first-round best | Started from the first-round best revalidate patch, then marked IPv4 egress auth-required, non-OK verdict, and proxy-redirect branches as cold in `handle_ipv4_from_lxc()`. Correctness passed but performance regressed below clean source. |
| 4 | accepted-for-analysis; rejected-no-signal; not selected as next base | `corpus/results/x86_kvm_corpus_20260626_065929_399049` | pktgen_total_pps mean `1456651.67`; samples `1460702, 1462853, 1446400`; `-2.11%` vs clean baseline, `-12.89%` vs first-round best | Started from the first-round best revalidate patch, then made ingress `ipv4_policy()` compute `fraginfo` lazily around fragment-tracking and reply/rev-NAT handling. Correctness passed, but larger config-dependent codegen regressed below clean source. |
| 5 | accepted-for-analysis; not selected as next base | `corpus/results/x86_kvm_corpus_20260626_072138_036296` | pktgen_total_pps mean `1528055.33`; samples `1534942, 1516759, 1532465`; `+2.68%` vs clean baseline, `-8.62%` vs first-round best | Stacked only the first-round best revalidate patch with the first-round positive `local_delivery()` peer-redirect condition simplification. Correctness passed and stayed above clean, but did not compose with the best patch. |

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded. 5 / 5 accepted.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] cilium source tree returned to attempt-start state after each attempt.

Phase2 gate:

- [x] Phase2 attempts 1-5 / 5 recorded.
- [x] Attempts 1-5 source tree restored after run.
- [x] No phase2 Cilium base improved over first-round best; keep
  `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely` as Cilium best
  (`+12.37%` vs clean baseline).

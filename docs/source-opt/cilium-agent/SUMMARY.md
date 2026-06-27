# cilium/agent source-opt summary

App: `cilium/agent`

Status: phase3-in-progress

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

Phase3 attempts:

| Attempt | Status | Result path | Performance | Notes |
| --- | --- | --- | --- | --- |
| 1 | accepted-for-analysis; selected as current Cilium phase3 base | `corpus/results/x86_kvm_corpus_20260626_180150_613607` | pktgen_total_pps mean `1672664`; samples `1683410, 1662935, 1671646`; `+12.40%` vs clean baseline, `+0.03%` vs previous Cilium best | Started from the first-round best revalidate patch, then marked the IPv4 `identity_is_reserved(src_sec_identity)` branch in `tail_ipv4_to_endpoint()` as cold. Correctness passed; the result is positive but tiny, so attempts 2-5 should move to larger hot-path work reduction instead of more branch hints. |
| 2 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_182603_784560` | pktgen_total_pps mean `1572938`; samples `1554963, 1566899, 1596952`; `+5.70%` vs clean baseline, `-5.96%` vs current Cilium phase3 base | Started from the phase3 attempt 1 base, then deferred policy verdict payload length and rate-limit setup until after the event filter in `send_policy_verdict_notify()`. Correctness passed and offline `tc/tail` section size shrank by `0x50`, but workload throughput regressed, so do not stack it. |
| 3 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_185324_568478` | pktgen_total_pps mean `1569838`; samples `1579206, 1566724, 1563584`; `+5.49%` vs clean baseline, `-6.15%` vs current Cilium phase3 base | Started from the phase3 attempt 1 base, then made established+allow policy traffic the explicit fast path around IPv4 ingress/egress policy verdict notification. Correctness passed, but the full-port-range pktgen workload likely keeps CT_NEW/policy verdict work hot enough that this branch reshaping regressed throughput; do not stack it. |
| 4 | accepted-for-analysis; selected as current Cilium phase3 base | `corpus/results/x86_kvm_corpus_20260626_191637_695574` | pktgen_total_pps mean `1686212`; samples `1688102, 1686224, 1684311`; `+13.31%` vs clean baseline, `+0.81%` vs prior Cilium phase3 base | Started from the phase3 attempt 1 base, then stacked the first-round positive `cil_to_container()` invalid-ethertype and failed-L3-pull `unlikely()` hints. Correctness passed and this composition improves over both the clean baseline and prior Cilium best, so attempt 5 should start from this base. |
| 5 | accepted-for-analysis; selected as Cilium phase3 best | `corpus/results/x86_kvm_corpus_20260626_193753_200824` | pktgen_total_pps mean `1714120`; samples `1713045, 1718508, 1710806`; `+15.19%` vs clean baseline, `+1.66%` vs prior Cilium phase3 base | Started from the phase3 attempt 4 base, then stacked the first-round positive `cil_lxc_policy()` invalid-ethertype and failed-L3-pull `unlikely()` hints. Correctness passed and this becomes the best Cilium source-opt result so far. |

Phase3 gate:

- [x] Phase3 attempts 1-5 / 5 recorded.
- [x] Attempts 1-5 source tree restored after run.
- [x] Cilium phase3 complete.
- [x] Current Cilium phase3 base is
  `20260626-123126-phase3-policy-error-unlikely-stack` with mean `1714120`
  (`+15.19%` vs clean baseline, `+1.66%` vs prior Cilium phase3 base).

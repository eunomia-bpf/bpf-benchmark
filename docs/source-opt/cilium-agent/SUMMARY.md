# cilium/agent source-opt summary

App: `cilium/agent`

Status: complete

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

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded. 5 / 5 accepted.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] cilium source tree returned to attempt-start state after each attempt.

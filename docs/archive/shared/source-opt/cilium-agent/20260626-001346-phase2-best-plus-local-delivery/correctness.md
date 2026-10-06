# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Local Cilium BPF diagnostic compile exited 0; see `diag-patched-build.log` | pass |
| Load | Formal `make corpus` run completed with app `status=ok`, `error=""` | pass |
| Workload | 3 baseline workload samples completed; component return codes `[0, 0, 0, 0, 0, 0]`; pktgen errors `0` | pass |
| Result schema | `baseline.workloads[]` has 3 samples, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | No map layout, event payload, metadata key, tail-call index, endpoint metadata, packet rewrite, policy decision, CT state, NAT state, fragment decision, or return code changes | pass |
| Coverage | Does not disable Cilium programs, maps, policy, CT, local delivery, redirect, NAT, or drop handling | pass |
| Provenance | `source.diff`, diagnostics, and run command recorded before formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 765G 104G 89% /`; Docker images
`84.59GB`, containers `29.73GB`, build cache `91.05GB`; no Docker cleanup
needed before this attempt.

Formal result: `corpus/results/x86_kvm_corpus_20260626_072138_036296`

Disk after run: `/dev/nvme0n1p2 915G 766G 103G 89% /`; Docker images
`85.18GB`, containers `29.73GB`, build cache `92.21GB`. No Docker cleanup was
needed after this attempt.

Source restoration: reversed `source.diff` with `patch -R`, removed local
Cilium diagnostic objects, and confirmed `vendor/repos/cilium` had no remaining
source diff.

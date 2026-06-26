# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Local Cilium BPF diagnostic compile exited 0; see `diag-patched-build.log` | pass |
| Load | Formal run `corpus/results/x86_kvm_corpus_20260626_063507_838342`; app `status=ok`, `error=""` | pass |
| Workload | 3 baseline workload samples; forward/reverse pktgen component returncodes `[0, 0, 0, 0, 0, 0]`; parsed pktgen errors `0` | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workloads length `3` | pass |
| ABI | No map layout, event payload, tail-call index, endpoint metadata, packet rewrite, policy decision, CT state, or return code changes | pass |
| Coverage | Does not disable Cilium programs, maps, policy, CT, local delivery, redirect, or drop handling | pass |
| Provenance | `source.diff`, diagnostics, and run command recorded before formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 763G 106G 88% /`; Docker images
`83.41GB`, containers `29.73GB`, build cache `88.71GB`; no Docker cleanup
needed before this attempt.

Disk after run: `/dev/nvme0n1p2 915G 764G 105G 88% /`; Docker images `84GB`,
containers `29.73GB`, build cache `89.88GB`; no Docker cleanup needed after
this attempt. `source.diff` was reverse-applied with `patch -R`, local Cilium
BPF diagnostic build outputs were removed, and `vendor/repos/cilium` status had
no remaining output.

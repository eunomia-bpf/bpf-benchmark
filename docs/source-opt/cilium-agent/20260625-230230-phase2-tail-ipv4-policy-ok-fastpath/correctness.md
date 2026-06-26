# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Local Cilium BPF diagnostic compile exited 0; see `diag-patched-build.log` | pass |
| Load | `corpus/results/x86_kvm_corpus_20260626_061027_069307/details/apps/cilium__agent.json`: app `status="ok"`, `error=""` | pass |
| Workload | 3 baseline samples; six pktgen component returncodes all `0`; parsed pktgen errors total `0` | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, `baseline.workloads` length `3` | pass |
| ABI | No map layout, event payload, tail-call index, endpoint metadata, packet rewrite, policy decision, or return code changes | pass |
| Coverage | Does not disable Cilium programs, maps, policy, CT, local delivery, redirect, or drop handling | pass |
| Provenance | `source.diff`, diagnostics, run command, result path, and performance extraction recorded | pass |

Disk before run: `/dev/nvme0n1p2 915G 762G 107G 88% /`; Docker images
`82.82GB`, containers `29.73GB`, build cache `87.55GB`; no Docker cleanup
needed before this attempt.

Disk after run: `/dev/nvme0n1p2 915G 763G 106G 88% /`; Docker images
`83.41GB`, containers `29.73GB`, build cache `88.71GB`; no Docker cleanup was
performed because there was still `106G` free.

Restoration:

- Formal result was parsed before source restoration.
- `patch -d vendor/repos/cilium -p1 -R < source.diff` returned Cilium source to
  the attempt-start state.
- Diagnostic `bpf_lxc.o`, `.bpf_lxc.o.cmd`, `bpf_lxc.ll`, and `bpf_lxc.s`
  files were removed from `vendor/repos/cilium/bpf/`.
- `git -C vendor/repos/cilium status --short` was empty after restoration.

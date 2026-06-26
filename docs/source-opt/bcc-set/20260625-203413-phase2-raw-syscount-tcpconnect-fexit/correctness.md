# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` exited 0; build log saved in `build.log` | pass |
| Load | Formal `make corpus` result `corpus/results/x86_kvm_corpus_20260626_034309_094312`; app `status="ok"`, `error=""` | pass |
| Workload | 3 baseline workload samples, return codes `0, 0, 0` | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, baseline workload payloads present | pass |
| ABI | `capable`, `syscount`, and `tcpconnect` event/map payload schemas are unchanged; `tcpconnect` removes only its private temporary `sockets` map | pass |
| Coverage | `tcpconnect` still has IPv4 and IPv6 handlers; `syscount -L` still attaches enter and exit hooks; `capable` still reports capability checks | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, and run command recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 749G 120G 87% /`; Docker images
`75.04GB`, build cache `73.77GB`; no Docker cleanup needed before this attempt.

Disk after restore: `/dev/nvme0n1p2 915G 751G 119G 87% /`; Docker images
`75.87GB`, build cache `75.18GB`; no Docker cleanup needed after this attempt.

Source restoration: `patch -R < source.diff` succeeded and
`make -C vendor bcc-x86` exited 0; `vendor/repos/bcc` status was clean after
the restore build.

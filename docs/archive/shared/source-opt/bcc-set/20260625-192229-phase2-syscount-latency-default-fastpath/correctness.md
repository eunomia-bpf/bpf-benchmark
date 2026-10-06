# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` exited 0 after fixing the stale cleanup jump; build log saved in `build.log` | pass |
| Load | `bcc/set` app lifecycle reached `app_done` with `status=ok`, `error=""` | pass |
| Workload | 3 baseline workload samples returned 0; stress-ng sums were `716964`, `718507`, `717694` real-time bogo ops/s | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, 3 baseline workloads present | pass |
| ABI | `tcpconnect` event, count key/value, `capable`, and `syscount` payload/map layouts are unchanged; `tcpconnect` removes only its private temporary handoff map | pass |
| Coverage | `tcpconnect` still handles IPv4 and IPv6 connects, pid/uid/port filters, count mode, and event mode; failed connects still do not emit events | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, and run command recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 744G 125G 86% /`; no Docker cleanup needed before this attempt.

Formal result: `corpus/results/x86_kvm_corpus_20260626_023049_621850/details/apps/bcc__set.json`.

Source restoration: `patch -d vendor/repos/bcc -p1 -R < source.diff` followed
by `make -C vendor bcc-x86` exited 0; `vendor/repos/bcc` status was clean
after restoration.

Disk after restoration: `/dev/nvme0n1p2 915G 746G 124G 86% /`; Docker images
`73.04GB`, build cache `70.3GB`; no cleanup needed.

# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` exited 0; build log saved in `build.log` | pass |
| Load | `bcc/set` app lifecycle reached `app_done` with `status=ok`, `error=""`; `baseline_start` completed after real `syscount` loaded raw tracepoints | pass |
| Workload | 3 baseline workload samples returned 0; stress-ng sums were `727466`, `720947`, `725471` real-time bogo ops/s | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, 3 baseline workloads present | pass |
| ABI | `capable` event/map layouts unchanged; `syscount` `start` and `data` map key/value layouts unchanged; syscount user output contract unchanged | pass |
| Coverage | `syscount` still attaches enter and exit hooks in latency mode and still counts all syscall ids; `capable` behavior is the phase2 attempt 1 accepted base | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, and run command recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 746G 124G 86% /`; Docker images
`73.04GB`, build cache `70.3GB`; no Docker cleanup needed before this attempt.

Formal result: `corpus/results/x86_kvm_corpus_20260626_025631_917158/details/apps/bcc__set.json`.

Source restoration: `patch -d vendor/repos/bcc -p1 -R < source.diff` followed
by `make -C vendor bcc-x86` exited 0; `vendor/repos/bcc` status was clean
after restoration.

Disk after restoration: `/dev/nvme0n1p2 915G 748G 122G 87% /`; Docker images
`74.2GB`, build cache `72.36GB`; no cleanup needed.

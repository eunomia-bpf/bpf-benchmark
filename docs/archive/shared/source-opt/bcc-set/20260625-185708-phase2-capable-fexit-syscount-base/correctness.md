# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` exited 0; build log saved in `build.log` | pass |
| Load | `bcc/set` app lifecycle reached `app_done` with `status=ok` | pass |
| Workload | Three baseline workload samples returned 0 | pass |
| Result schema | suite returned `status=ok`; app `status=ok`; `error=""`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `cap_event`, `unique_key`, `info`, `seen`, `events`, `stackmap`, and cgroup map layouts are unchanged; `syscount` counter structs and maps are unchanged | pass |
| Coverage | `capable` keeps cgroup, self-pid, target-pid, unique, stack, and perf-event paths; `syscount` only moves the existing interrupt-id return earlier | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, `run-command.sh`, `run.log`, result path, and restore build log recorded | pass |

Disk before run: `/dev/nvme0n1p2 915G 743G 126G 86% /`; no Docker cleanup needed before this attempt.
Disk after restore: `/dev/nvme0n1p2 915G 744G 125G 86% /`; Docker images `72.21GB`, build cache `68.89GB`; no cleanup needed.

Source restore:

- Reversed `source.diff` with `patch -d vendor/repos/bcc -p1 -R`.
- Rebuilt BCC artifacts with `make -C vendor bcc-x86`; log saved as `restore-build.log`.
- `vendor/repos/bcc` was clean after restore.

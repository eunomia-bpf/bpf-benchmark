# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | Formal `make corpus` run exited 0; app result `status="ok"` and `error=""` | pass |
| Workload | 3 baseline workload samples all returned 0 | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; app JSON saved under result path | pass |
| ABI | Listed syscall IDs keep all argument slots used by their Tracee event definitions; unlisted syscalls keep the original six-argument path | pass |
| Coverage | Does not disable events, maps, tail calls, scope filters, or perf submit | pass |
| Provenance | `source.diff`, run command, result path, correctness notes, and performance notes recorded | pass |

Disk before run: `/dev/nvme0n1p2 915G 758G 112G 88% /`; Docker images
`80.51GB`, containers `29.73GB`, build cache `83.42GB`; no Docker cleanup
needed before this attempt.

Restoration:

- Reversed `source.diff` with `patch -d vendor/repos/tracee -p1 -R`.
- Rebuilt clean Tracee artifact with `make -C vendor tracee-x86`; log saved
  in `restore-build.log`.
- `git -C vendor/repos/tracee status --short` produced no output.

Disk after run: `/dev/nvme0n1p2 915G 760G 110G 88% /`; Docker images
`81.66GB`, containers `29.73GB`, build cache `85.48GB`; no Docker cleanup
performed.

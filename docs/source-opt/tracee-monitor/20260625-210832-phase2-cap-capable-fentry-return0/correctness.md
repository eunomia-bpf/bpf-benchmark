# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | Tracee baseline start completed with `phase_done baseline_start status=ok` | pass |
| Workload | 3 retained workload samples all returned 0 | pass |
| Result schema | App result has `status="ok"`, `error=""`, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, and 3 baseline workloads | pass |
| ABI | Event id, argument payload, scope filtering, and perf submit path are unchanged | pass |
| Coverage | `trace_cap_capable` still hooks `cap_capable()` and still drops `CAP_OPT_NOAUDIT` checks | pass |
| Provenance | `source.diff`, run command, and attempt rationale recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 753G 117G 87% /`; Docker images
`77.03GB`, containers `29.73GB`, build cache `77.24GB`; no Docker cleanup
needed before this attempt.

Restoration: `patch -d vendor/repos/tracee -p1 -R < source.diff` followed by
`make -C vendor tracee-x86` exited 0; `vendor/repos/tracee` status returned
empty after restoration.

Disk after run: `/dev/nvme0n1p2 915G 755G 115G 87% /`; Docker images
`78.19GB`, containers `29.73GB`, build cache `79.3GB`; no Docker cleanup
needed after this attempt.

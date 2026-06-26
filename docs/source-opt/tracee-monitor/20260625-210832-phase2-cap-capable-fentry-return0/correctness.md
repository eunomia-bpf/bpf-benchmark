# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | TBD after formal `make corpus` run | pending |
| Workload | TBD after formal `make corpus` run | pending |
| Result schema | TBD after formal `make corpus` run | pending |
| ABI | Event id, argument payload, scope filtering, and perf submit path are unchanged | pass |
| Coverage | `trace_cap_capable` still hooks `cap_capable()` and still drops `CAP_OPT_NOAUDIT` checks | pass |
| Provenance | `source.diff`, run command, and attempt rationale recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 753G 117G 87% /`; Docker images
`77.03GB`, containers `29.73GB`, build cache `77.24GB`; no Docker cleanup
needed before this attempt.

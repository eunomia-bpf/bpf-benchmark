# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` exited 0; build log saved in `build.log` | pass |
| Load | `corpus/results/x86_kvm_corpus_20260626_040613_380312/details/apps/tracee__monitor.json` has `status="error"`; Tracee exited during BPF load with `libbpf: prog 'trace_cap_capable': failed to load: -22` | fail |
| Workload | No workload samples ran because app startup failed before baseline measurement | fail |
| Result schema | `post_rejit=null`, but `baseline.workloads` is empty and `rejit_result.mode` is absent because the app never reached baseline measurement | fail |
| ABI | Event id, argument payload, scope filtering, and perf submit path are unchanged | pass |
| Coverage | `trace_cap_capable` still hooks `cap_capable()` and still drops `CAP_OPT_NOAUDIT` checks | pass |
| Provenance | `source.diff`, `build.log`, diagnostics, and run command recorded before the formal run | pass |

Disk before run: `/dev/nvme0n1p2 915G 751G 119G 87% /`; Docker images
`75.87GB`, build cache `75.18GB`; no Docker cleanup needed before this attempt.

Restoration: `patch -d vendor/repos/tracee -p1 -R < source.diff` followed by
`make -C vendor tracee-x86` exited 0; `vendor/repos/tracee` status returned
empty after restoration.

Disk after run: `/dev/nvme0n1p2 915G 753G 117G 87% /`; Docker images
`77.03GB`, containers `29.73GB`, build cache `77.24GB`; no Docker cleanup
needed after this attempt.

# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tetragon-x86` completed successfully before the formal run. | pass |
| Load | Formal corpus run reported app `status="ok"` and `error=""` for `tetragon/observer`. | pass |
| Workload | Three baseline workload samples were recorded; app result contains three `baseline.workloads[]` entries. | pass |
| Result schema | App result has `post_rejit=null`; suite result has `skip_rejit=true` and `rejit_result=null`. | pass |
| ABI | No map key/value layout, event payload, tail-call key, attach point, or app-visible config format changed beyond attempt 2's already validated `event_config.flags` use. | pass |
| Coverage | No BPF program, policy check, selector path, or event path is disabled. The process-stage tail-call chain still advances through the same configured argument indexes. | pass |
| Provenance | `source.diff`, `run-command.sh`, `result-paths.txt`, `diagnostics.md`, and this correctness note are recorded under this attempt directory. | pass |

Source restoration: `patch -R -p1 < source.diff` was applied after the run, and `git -C vendor/repos/tetragon status --short` reported no local diff.

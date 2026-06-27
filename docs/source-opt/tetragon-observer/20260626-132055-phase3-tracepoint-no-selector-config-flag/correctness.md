# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tetragon-x86` completed successfully before the formal run. | pass |
| Load | Formal corpus run reported app `status="ok"` and `error=""` for `tetragon/observer`. | pass |
| Workload | Three baseline workload samples were recorded; app result contains three `baseline.workloads[]` entries. | pass |
| Result schema | App result has `post_rejit=null`; suite result has `skip_rejit=true` and `rejit_result=null`. | pass |
| ABI | `event_config.flags` already exists in the map value layout; this attempt only defines and sets bit 0. Event payloads, map keys, tail-call indexes, and attach points are unchanged. | pass |
| Coverage | Nonzero-selector policies still use the original filter path. No BPF program, policy check, or event path is disabled. | pass |
| Provenance | `source.diff`, `run-command.sh`, `result-paths.txt`, `diagnostics.md`, and this correctness note are recorded under this attempt directory. | pass |

Source restoration: `patch -R -p1 < source.diff` was applied after the run, and `git -C vendor/repos/tetragon status --short` reported no local diff.

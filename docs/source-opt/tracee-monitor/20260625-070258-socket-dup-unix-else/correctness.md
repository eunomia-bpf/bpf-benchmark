# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` rebuilt tracee and exited 0 | pass |
| Load | app result `status=ok`, `error=""` | pass |
| Workload | 3 baseline workload samples, returncodes `[0, 0, 0]` | pass |
| Result schema | suite `status=ok`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, event structs, field order, attach points, or headers | pass |
| Coverage | `source.diff` preserves socket dup event submission and only removes a redundant final family comparison after the existing family guard | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

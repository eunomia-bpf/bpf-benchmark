# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` rebuilt runtime image and exited 0 | pass |
| Load | app result `status=ok`, `error=""` | pass |
| Workload | 3 workload samples, each with forward/reverse pktgen component returncodes `[0, 0]` | pass |
| Result schema | suite `status=ok`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, endpoint structs, metadata slots, tail-call indexes, attach points, or headers exported to user space | pass |
| Coverage | `source.diff` preserves local delivery policy/redirect decisions by algebraic equivalence | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

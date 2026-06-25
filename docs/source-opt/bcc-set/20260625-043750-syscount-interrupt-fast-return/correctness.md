# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` rebuilt the BCC tool layer and exited 0 | pass |
| Load | `bcc/set` app lifecycle reached `app_done` with `status=ok` | pass |
| Workload | Three baseline workload samples returned 0 | pass |
| Result schema | suite `status=ok`; app `status=ok`; `error=""`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, counter structs, attach points, or headers | pass |
| Coverage | `source.diff` preserves all filters and only moves an existing early return | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

Disk after run: `/dev/nvme0n1p2 915G 700G 169G 81% /`; no Docker image cleanup needed.

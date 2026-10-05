# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` rebuilt Tetragon artifacts and completed with exit code 0. | pass |
| Load | app JSON has `status="ok"`, `error=""`, runner `tetragon`, workload `stress_ng_tetragon_policy_hot`. | pass |
| Workload | 3 baseline workload samples returned `0, 0, 0`. | pass |
| Result schema | suite `status=ok`; `baseline.workloads[]` length is 3; `post_rejit=null`; `rejit_result.mode=skip_rejit_all`. | pass |
| ABI | No map layout, event payload, attach point, or tail-call key changes in source diff. | pass |
| Coverage | Empty namespace sections skip only loop iterations whose body was already disabled by `len > 0`; non-empty sections still run the same filters. | pass |
| Provenance | `source.diff`, command, result path, performance notes, and restore status recorded. | pass |

Source restore: `patch -d vendor/repos/tetragon -p1 -R < source.diff` succeeded; tetragon source diff was empty after restore.

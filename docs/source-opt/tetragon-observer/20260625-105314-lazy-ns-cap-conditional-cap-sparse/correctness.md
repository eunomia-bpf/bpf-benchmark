# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` completed for `tetragon/observer`; BPF object build passed. | pass |
| Load | `status=ok`, `error=""` in `details/apps/tetragon__observer.json`. | pass |
| Workload | 3 baseline workload samples returned `0, 0, 0`. | pass |
| Result schema | `baseline.workloads[]` length is 3; `post_rejit=null`; `rejit_result.mode=skip_rejit_all`. | pass |
| ABI | No map layout, event payload, attach point, or tail-call key changes in source diff. | pass |
| Coverage | No policy selector, action, or output path is disabled; state is delayed until original consumer sections. | pass |
| Provenance | `source.diff`, command, result path, performance notes, and restore status recorded. | pass |

Source restore: `patch -d vendor/repos/tetragon -p1 -R < source.diff` succeeded; tetragon source diff was empty after restore.

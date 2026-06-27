# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor tracee-x86` completed and rebuilt `tracee.bpf.o` plus the real `tracee` binary. | pass |
| Load | `tracee/monitor` app `status=ok`, `error=""`. | pass |
| Workload | 3 baseline workload samples returned code 0. | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, 3 baseline workloads present. | pass |
| ABI | Does not change event payloads, map layouts, event IDs, or tail-call keys. The fast path only short-circuits scope-filter matching when all real scope/follow filter-enabled bitmaps are zero. | pass |
| Coverage | Does not disable events or filters; any enabled scope/follow filter falls back to the original `match_scope_filters()` path. | pass |
| Provenance | `source.diff`, `phase3-only.diff`, `build.log`, `base-build.log`, object summaries, `run.log`, `run-command.sh`, `result-paths.txt`, and this correctness note are present. | pass |

Machine-readable check:

```json
{
  "status": "ok",
  "error": "",
  "post_rejit_is_null": true,
  "rejit_mode": "skip_rejit_all",
  "baseline_workloads": 3,
  "workload_returncodes": [0],
  "workload_durations": [
    180.03387484799998,
    180.02503084199998,
    180.02313871599995
  ]
}
```

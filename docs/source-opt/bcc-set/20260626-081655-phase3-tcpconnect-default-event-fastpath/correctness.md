# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` completed before the formal run. | pass |
| Load | `bcc/set` app `status=ok`, `error=""`. | pass |
| Workload | 3 baseline workload samples returned code 0. | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, 3 baseline workloads present. | pass |
| ABI | Keeps `tcpconnect` event payload, maps used by user-visible count/event output, and app CLI behavior unchanged; the fast path is only for the no-filter/no-count/no-source-port event mode and emits the same event fields as the generic path. | pass |
| Coverage | Does not disable a BPF program or skip pid/uid/port/count/source-port modes; those still use the generic path. | pass |
| Provenance | `source.diff`, `build.log`, `run.log`, `run-command.sh`, `result-paths.txt`, and this correctness note are present. | pass |

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
    180.01583083399998,
    181.01533622099998,
    180.01607190700008
  ]
}
```

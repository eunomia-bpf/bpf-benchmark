# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` succeeded before the formal run. | pass |
| Load | App result has `status="ok"` and `error=""`. | pass |
| Workload | Three baseline workload samples completed; component returncodes were `[0]`. | pass |
| Result schema | `post_rejit == null`, `rejit_result.mode == "skip_rejit_all"`, and `baseline.workloads` length is 3. | pass |
| ABI | No map key/value layout, event payload, tail-call key, or attach-point changes. | pass |
| Coverage | No BPF program, language worker, frame walk, or error path was disabled. | pass |
| Provenance | `source.diff`, build logs, run command, run log, result paths, and restore build log are preserved in this attempt directory. | pass |

Checked JSON:

```json
{
  "status": "ok",
  "error": "",
  "post_rejit_is_null": true,
  "rejit_mode": "skip_rejit_all",
  "baseline_workloads": 3,
  "component_returncodes": [
    0
  ]
}
```


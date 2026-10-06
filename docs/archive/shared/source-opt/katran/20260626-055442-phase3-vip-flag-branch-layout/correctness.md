# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor katran-x86` completed; candidate object recorded in `candidate-object.txt` and `candidate-object.sha256`. | pass |
| Load | Katran runner reached `baseline_start` and `baseline` measurement with app status `ok`. | pass |
| Workload | Three `xdp_pktgen` workload samples completed; component returncodes were `[0]`. | pass |
| Result schema | `status="ok"`, `error=""`, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, and 3 baseline workload payloads. | pass |
| ABI | Patch only reuses existing VIP metadata fields and adds branch prediction hints around existing conditions; no map key/value, tail-call, packet metadata, or action ABI changed. | pass |
| Coverage | No BPF program, policy check, map lookup, stats update, or error path was removed. Cold paths remain reachable. | pass |
| Provenance | `source.diff`, build logs, run command, result paths, correctness notes, and object diagnostics are present in this attempt directory. | pass |

Correctness query:

```json
{
  "status": "ok",
  "error": "",
  "post_rejit_is_null": true,
  "rejit_mode": "skip_rejit_all",
  "baseline_workloads": 3,
  "component_returncodes": [0]
}
```

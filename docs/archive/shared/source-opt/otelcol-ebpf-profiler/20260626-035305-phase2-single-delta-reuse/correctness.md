# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | OTEL eBPF build completed and regenerated `tracer.ebpf.amd64`; patched build logged `Total instructions: 123863`. | pass |
| Load | Real `otelcol-ebpf-profiler/profiling` app completed with `status=ok`. | pass |
| Workload | Baseline phase recorded 3 workload samples; all component return codes were 0. | pass |
| Result schema | App JSON has `error=""`, `post_rejit=null`, and `rejit_result.mode="skip_rejit_all"`. | pass |
| ABI | Patch only changes local control flow in `get_stack_delta()`; no map/event struct layout, tail-call key, or attach point changed. | pass |
| Coverage | No program, language worker, profiler feature, or error-reporting path was disabled. | pass |
| Provenance | `source.diff`, `run-command.sh`, build logs, result path, and docs-side metric are recorded in this directory. | pass |

Validation snapshot:

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

After the run, the patch was reversed with `patch -R` and the clean eBPF artifact was rebuilt. The restored build returned to `Total instructions: 123833`, with `kprobe/unwind_native=6972`, `perf_event/unwind_native=6972`, and `perf_event/native_tracer_entry=1322`.


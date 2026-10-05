# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` completed, but this attempt did not explicitly rebuild `support/ebpf/tracer.ebpf.amd64` from the edited eBPF source before the collector build. | fail |
| Load | App lifecycle completed with `status=ok` and `error=""`; true patched-BPF load is not proven because build provenance failed. | fail |
| Workload | Three baseline samples completed; all 33 composite workload components returned 0. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workloads present. | pass |
| ABI | `source.diff` changes only control flow in `collect_trace()`; no map, event, frame, or tail-call ABI changes. | pass |
| Coverage | Unknown PID reporting is preserved; known PID and error trace paths still collect kernel stack IDs in the patch. | pass |
| Provenance | `source.diff`, command, build log, result path, and metric notes are present, but artifact rebuild provenance is missing. | fail |

Final verdict: `rejected-correctness`. Do not count this as one of the five valid otel source optimization attempts.

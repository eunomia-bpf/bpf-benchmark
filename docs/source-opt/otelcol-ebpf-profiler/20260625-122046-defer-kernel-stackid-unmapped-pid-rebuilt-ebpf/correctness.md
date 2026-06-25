# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` rebuilt `tracer.ebpf.amd64`; the subsequent `make corpus` OCB build recompiled and installed the collector binary. | pass |
| Load | App lifecycle completed with `status=ok` and `error=""`; real collector startup loaded through the normal runner path. | pass |
| Workload | Three baseline samples completed; all 33 composite workload components returned 0. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workloads present. | pass |
| ABI | `source.diff` changes only control flow in `collect_trace()`; no map, event, frame, or tail-call ABI changes. | pass |
| Coverage | Unknown PID reporting is preserved; known PID and error trace paths still collect kernel stack IDs. | pass |
| Provenance | `source.diff`, `ebpf-build.log`, `build.log`, command, result path, and metric notes are in this directory. | pass |

Final verdict: `rejected-no-signal`. This counts as a valid source optimization attempt, but it is not a useful base for cumulative otel tuning.

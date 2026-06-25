# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` succeeded before the formal run; `tracer.ebpf.amd64` changed and entered the runtime image build. | pass |
| Load | Real `otelcol-ebpf-profiler` startup completed; app `status=ok`, `error=""`. | pass |
| Workload | Three baseline workload samples completed; no component returned nonzero. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode=skip_rejit_all`; `baseline.workloads[]` has 3 samples. | pass |
| ABI | `Trace` layout, custom-label layout, map layout, and emitted payload layout stay unchanged. | pass |
| Coverage | No custom-label extraction, APM handling, unwinder, metric, or error path is removed; the patch only avoids clearing when no previous label state existed. | pass |
| Provenance | `source.diff`, eBPF build log, command, result path, run log, and notes are in this directory. | pass |

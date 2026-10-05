# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` completed before the formal run; rebuilt `tracer.ebpf.amd64` with total instruction count 123136. | pass |
| Load | Formal `make corpus` run completed with app `status=ok` and `error=""`. | pass |
| Workload | All 3 composite workload samples completed; all 33 component return codes were 0. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workload payloads present. | pass |
| ABI | `source.diff` only changes internal helper plumbing for existing tail calls; no map, event, frame, or tail-call key ABI changes. | pass |
| Coverage | All existing unwinder exits still call the same tail-call target and preserve `record->tailCalls` accounting. | pass |
| Provenance | `source.diff`, eBPF build log, command, result path, and notes are in this directory. | pass |

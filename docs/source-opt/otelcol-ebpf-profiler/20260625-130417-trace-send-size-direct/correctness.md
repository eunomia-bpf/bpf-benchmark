# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` completed before the formal run; rebuilt `tracer.ebpf.amd64` with total instruction count 123809. | pass |
| Load | Formal `make corpus` run completed with app `status=ok` and `error=""`. | pass |
| Workload | All 3 composite workload samples completed; all 33 component return codes were 0. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workload payloads present. | pass |
| ABI | `source.diff` preserves `Trace` layout and still sends exactly the prefix plus `stack_len` frames because `frames` is the final field. | pass |
| Coverage | No program, unwinder, metric, error path, or filter condition is removed. | pass |
| Provenance | `source.diff`, eBPF build log, command, result path, and notes are in this directory. | pass |

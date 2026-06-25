# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` completed before the formal run; rebuilt `tracer.ebpf.amd64` with total instruction count 127011. | pass |
| Load | Formal `make corpus` run completed with app `status=ok` and `error=""`. | pass |
| Workload | All 3 composite workload samples completed; all 33 component return codes were 0. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; baseline workload payloads present. | pass |
| ABI | `source.diff` only changes the number of native frames handled per `unwind_native()` invocation; map, event, frame, and tail-call ABI stay unchanged. | pass |
| Coverage | No unwinder, frame push, stop condition, or error path is removed; deep native stacks can only consume fewer tail calls for the same frame budget. | pass |
| Provenance | `source.diff`, eBPF build log, command, result path, and notes are in this directory. | pass |

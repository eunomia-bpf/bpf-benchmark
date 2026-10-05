# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` completed; see `ebpf-build.log`. | pass |
| Load | formal run app JSON has `status="ok"` and `error=""`. | pass |
| Workload | three baseline workload samples completed; component return codes were all `0`. | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, and `baseline.workloads` has 3 samples. | pass |
| ABI | only control flow inside `collect_trace()` changed; map layouts, event payload structs, tail-call keys, attach points, and sent trace fields are unchanged. | pass |
| Coverage | the existing unmapped-PID metadata path still calls `report_pid()` and returns; sent trace paths still compute `comm`, `kernel_stack_id`, and unwinder state. | pass |
| Provenance | `source.diff`, `run-command.sh`, `run.log`, `result-paths.txt`, `README.md`, `correctness.md`, and diagnostic objdump/build logs are present. | pass |

Correctness passed, but performance did not improve; classify as `rejected-no-signal`.


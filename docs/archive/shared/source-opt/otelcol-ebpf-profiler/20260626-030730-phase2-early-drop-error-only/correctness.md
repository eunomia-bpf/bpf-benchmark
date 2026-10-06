# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` completed; see `ebpf-build.log`. | pass |
| Load | formal run app JSON has `status="ok"` and `error=""`. | pass |
| Workload | three baseline workload samples completed; component return codes were all `0`. | pass |
| Result schema | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`, and `baseline.workloads` has 3 samples. | pass |
| ABI | no map layout, event payload struct, tail-call key, attach point, or sent trace format changed. | pass |
| Coverage | only existing `filter_error_frames` drop behavior was moved earlier for empty-stack error-only traces; normal trace enrichment and send paths are unchanged. | pass |
| Provenance | `source.diff`, `run-command.sh`, `run.log`, `result-paths.txt`, `README.md`, `correctness.md`, and build/restore logs are present. | pass |

Correctness passed, but performance did not improve; classify as `rejected-no-signal`.


# Correctness

## Gates

| Gate | Result | Evidence |
| --- | --- | --- |
| Build | pass | Candidate eBPF artifact rebuilt with `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`; see `build.log`. |
| Load | pass | App result `status=ok`, `error=""`. |
| Workload | pass | Three workload samples completed; all component returncodes were 0. |
| Result schema | pass | App `post_rejit=null`; suite `skip_rejit=true`, `rejit_result=null`. |
| ABI | pass | Patch only reorders an existing PID-information lookup relative to current-PC mapping resolution; map/event/tail-call/attach-point layouts are unchanged. |
| Coverage | pass | No BPF program, profiler path, language unwinder, process reporting path, or error handling path was disabled. |
| Provenance | pass | `source.diff`, build logs, run command, run log, result path, and performance record are present. |

## Performance

- Primary metric: `language_ops_total`
- Samples: `19585524873, 19436580480, 19422803783`
- Mean: `19481636379`
- Clean baseline mean: `19644780415`
- vs baseline: `-0.83%`

## Restore

The source patch was reversed with non-git `patch -R`, then the clean eBPF artifact was rebuilt. `git -C vendor/repos/opentelemetry-ebpf-profiler status --short` was empty after restore.

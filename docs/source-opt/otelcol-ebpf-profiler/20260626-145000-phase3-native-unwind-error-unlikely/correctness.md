# Correctness

## Gates

| Gate | Result | Evidence |
| --- | --- | --- |
| Build | pass | Candidate eBPF artifact rebuilt with `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64`; see `build.log`. |
| Load | pass | App result `status=ok`, `error=""`. |
| Workload | pass | Three workload samples completed; all component returncodes were 0. |
| Result schema | pass | App `post_rejit=null`; suite `skip_rejit=true`, `rejit_result=null`. |
| ABI | pass | Patch only added `OPTI_UNLIKELY()` branch hints; no map/event/tail-call/attach-point layout changed. |
| Coverage | pass | No BPF program, profiler path, language unwinder, or error handling path was disabled. |
| Provenance | pass | `source.diff`, build logs, run command, result path, and performance record are present. |

## Performance

- Primary metric: `language_ops_total`
- Samples: `19583174016, 19234194165, 19279128490`
- Mean: `19365498890`
- Clean baseline mean: `19644780415`
- vs baseline: `-1.42%`

## Restore

The source patch was reversed with non-git `patch -R`, then the clean eBPF artifact was rebuilt. `git -C vendor/repos/opentelemetry-ebpf-profiler status --short` was empty after restore.

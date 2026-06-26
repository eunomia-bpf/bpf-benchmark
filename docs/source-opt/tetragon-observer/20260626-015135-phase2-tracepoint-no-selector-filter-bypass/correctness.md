# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Local Tetragon BPF build completed with clang-18; formal `make corpus` completed. | pass |
| Load | App result status is `ok`; `error` is empty. | pass |
| Workload | Three baseline workload samples returned `0`. | pass |
| Result schema | `post_rejit` is `null`; `rejit_result.mode` is `skip_rejit_all`; baseline workload payloads are present. | pass |
| ABI | No map layout, event payload, tail-call key value, attach point, or userspace loader interface changed. | pass |
| Coverage | The bypass only applies to no-selector tracepoint policy entries. If the no-selector context is not available, or selectors are configured, execution falls back to the original filter tail-call path. | pass |
| Provenance | `source.diff`, `build.log`, `run-command.sh`, `run.log`, result path, diagnostics, and this correctness note are recorded. | pass |

Restore check: after the run, `source.diff` was reverse-applied with `patch -R`, and `git -C vendor/repos/tetragon status --short` printed no local changes.

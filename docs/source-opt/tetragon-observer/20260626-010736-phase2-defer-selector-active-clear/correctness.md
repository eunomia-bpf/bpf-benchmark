# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Local Tetragon BPF build completed with clang-18; formal `make corpus` completed. | pass |
| Load | App result status is `ok`; `error` is empty. | pass |
| Workload | Three baseline workload samples returned `0`. | pass |
| Result schema | `post_rejit` is `null`; `rejit_result.mode` is `skip_rejit_all`; baseline workload payloads are present. | pass |
| ABI | No map layout, event payload, tail-call key, attach point, or userspace loader interface changed. | pass |
| Coverage | No BPF program or selector/policy check was removed. Selector-specific active bits are still cleared before selector evaluation. | pass |
| Provenance | `source.diff`, `build.log`, `run-command.sh`, `run.log`, result path, diagnostics, and this correctness note are recorded. | pass |

Restore check: after the run, `source.diff` was reverse-applied with `patch -R`, and `git -C vendor/repos/tetragon status --short` printed no local changes.

# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | TBD after `make -C vendor tracee-x86` | pending |
| Load | TBD after formal `make corpus` run | pending |
| Workload | TBD after formal `make corpus` run | pending |
| Result schema | TBD after formal `make corpus` run | pending |
| ABI | Listed syscall IDs keep all argument slots used by their Tracee event definitions; unlisted syscalls keep the original six-argument path | pass |
| Coverage | Does not disable events, maps, tail calls, scope filters, or perf submit | pass |
| Provenance | `source.diff`, run command, and attempt rationale recorded before formal run | pass |

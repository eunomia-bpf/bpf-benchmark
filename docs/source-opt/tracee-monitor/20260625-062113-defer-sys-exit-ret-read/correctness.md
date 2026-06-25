# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` exited 0 and rebuilt `tracee.bpf.c` into the real tracee artifact path | pass |
| Load | app result `status=ok`, `error=""` | pass |
| Workload | 3 baseline workload samples returned `[0, 0, 0]` | pass |
| Result schema | suite `status=ok`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, event structs, field order, attach points, or headers | pass |
| Coverage | syscall exit initialization is preserved; the patch only defers the return-value read | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

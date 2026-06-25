# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | formal `make corpus` rebuilt `opensnoop.bpf.o`, regenerated `opensnoop.skel.h`, rebuilt `opensnoop`, and copied updated BCC binaries into the runtime image | pass |
| Load | app `status=ok`, `error=""`; real `bcc_set` runner started the libbpf-tools binaries | pass |
| Workload | 3 baseline workload samples, returncodes `[0, 0, 0]` | pass |
| Result schema | suite `status=ok`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, event struct, attach points, or headers | pass |
| Coverage | `source.diff` does not remove filters, output, stack collection, or programs | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

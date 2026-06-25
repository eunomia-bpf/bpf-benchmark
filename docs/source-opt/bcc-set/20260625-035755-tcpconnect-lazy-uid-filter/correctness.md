# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | formal `make corpus` rebuilt `tcpconnect.bpf.o`, regenerated `tcpconnect.skel.h`, rebuilt `tcpconnect`, and copied updated BCC binaries into the runtime image | pass |
| Load | app `status=ok`, `error=""`; real `bcc_set` runner started the libbpf-tools binaries | pass |
| Workload | 3 baseline workload samples, returncodes `[0, 0, 0]` | pass |
| Result schema | suite `status=ok`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, event structs, attach points, or headers | pass |
| Coverage | `source.diff` does not remove filters, output, count mode, or programs | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

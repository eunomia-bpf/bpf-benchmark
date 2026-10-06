# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor cilium-x86` passed before the run; `restore-build.log` also passed after reversing `source.diff`. | pass |
| Load | App result has `status="ok"` and `error=""`; lifecycle reached `baseline_start`, measurement, and `baseline_stop`. | pass |
| Workload | Three baseline workload samples ran; six pktgen components returned `0`. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; `baseline.workloads[]` contains three samples. | pass |
| ABI | Patch only changes branch prediction annotations in `bpf/bpf_lxc.c`; no map key/value, event payload, tail-call key, attach point, or helper interface changed. | pass |
| Coverage | No program, policy check, bounds check, event path, or error handling was removed. | pass |
| Provenance | `source.diff`, `candidate-only.diff`, `run-command.sh`, `run.log`, `build.log`, `restore-build.log`, and `result-paths.txt` are present. | pass |

Parsed workload details:

- Sample 1: forward `879741pps`, reverse `833304pps`, total `1713045`, errors `0`.
- Sample 2: forward `883473pps`, reverse `835035pps`, total `1718508`, errors `0`.
- Sample 3: forward `876658pps`, reverse `834148pps`, total `1710806`, errors `0`.
- Component durations: `180.040976747`, `180.051038695`, `180.09064916099993`, `180.06264135099997`, `180.11235415399995`, `180.11280312600002`.

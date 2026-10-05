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

- Sample 1: forward `869748pps`, reverse `818354pps`, total `1688102`, errors `0`.
- Sample 2: forward `870006pps`, reverse `816218pps`, total `1686224`, errors `0`.
- Sample 3: forward `865611pps`, reverse `818700pps`, total `1684311`, errors `0`.
- Component durations: `180.02568869799995`, `180.015451945`, `180.02206095000003`, `180.00837304099997`, `180.09231403`, `180.06231911500004`.

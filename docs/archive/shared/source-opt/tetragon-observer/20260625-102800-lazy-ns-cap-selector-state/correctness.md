# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` rebuilt Tetragon artifacts and completed with exit code 0. | pass |
| Load | app JSON has `status="ok"`, `error=""`, runner `tetragon`, workload `stress_ng_tetragon_policy_hot`. | pass |
| Workload | `baseline.workloads` has 3 samples, returncodes `0,0,0`. | pass |
| Result schema | suite `status="ok"`, `skip_rejit=true`, `bpf_stats=false`; app `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`. | pass |
| ABI | `source.diff` only changes when existing selector state is populated; map/event/tail-call layouts unchanged. | pass |
| Coverage | No BPF program, policy, selector, action, attach point, or helper path is removed. | pass |
| Provenance | `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` are present under this attempt directory. | pass |

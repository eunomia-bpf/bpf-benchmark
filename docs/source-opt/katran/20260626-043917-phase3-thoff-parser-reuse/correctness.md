# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor katran-x86` succeeded before the formal run; see `build.log`. | pass |
| Load | App result `status="ok"` and `error=""` in `corpus/results/x86_kvm_corpus_20260626_114838_879478/details/apps/katran.json`. | pass |
| Workload | Three baseline workload samples completed; all component return codes were `0`. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; `baseline.workloads` length is `3`. | pass |
| ABI | Patch only passes the existing transport offset to parser helpers. No map key/value, event payload, tail-call key, attach point, VIP flag, or action ABI changes. | pass |
| Coverage | No program, VIP mode, forwarding decision, flow-migration path, QUIC path, stable-routing path, stats path, or error path was disabled. | pass |
| Provenance | `source.diff`, `run-command.sh`, `run.log`, `result-paths.txt`, `diagnostics.md`, and `restore-build.log` are present. | pass |

Restoration:

- `patch -d vendor/repos/katran -p1 -R < source.diff` succeeded.
- `make -C vendor katran-x86` succeeded after restoration.
- `git -C vendor/repos/katran status --short` and targeted `git diff` were empty after restoration.
- Restored `balancer.bpf.o` xdp section size: `0x4870`.

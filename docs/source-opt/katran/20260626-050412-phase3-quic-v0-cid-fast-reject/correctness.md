# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | Base and candidate `make -C vendor katran-x86` builds succeeded; see `base-build.log` and `build.log`. | pass |
| Load | App result `status="ok"` and `error=""` in `corpus/results/x86_kvm_corpus_20260626_121345_246104/details/apps/katran.json`. | pass |
| Workload | Three baseline workload samples completed; all component return codes were `0`. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; `baseline.workloads` length is `3`. | pass |
| ABI | No map key/value, event payload, tail-call key, attach point, VIP flag, or action ABI change. | pass |
| Coverage | CID versions 1, 2, and 3 keep the same parser and routing behavior. CID version 0 already fell back to CH; it now returns the same parse result earlier. | pass |
| Provenance | `source.diff`, `run-command.sh`, `run.log`, `result-paths.txt`, `diagnostics.md`, and `restore-build.log` are present. | pass |

Restoration:

- `patch -d vendor/repos/katran -p1 -R < source.diff` succeeded.
- `make -C vendor katran-x86` succeeded after restoration.
- `git -C vendor/repos/katran status --short` and targeted `git diff` were empty after restoration.
- Restored `balancer.bpf.o` xdp section size: `0x4870`.

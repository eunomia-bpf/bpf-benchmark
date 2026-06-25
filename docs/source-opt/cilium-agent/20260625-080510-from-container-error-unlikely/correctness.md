# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make corpus` completed and runtime image copied `vendor/repos/cilium/bpf/` into `/var/lib/cilium/bpf/` | pass |
| Load | real `cilium-agent` runner reached `baseline_start` and `baseline_stop` with `status=ok` | pass |
| Workload | 3 `cilium_endpoint_pktgen` samples; each forward/reverse pktgen component returned `[0, 0]` | pass |
| Result schema | suite `status=ok`; app `status=ok`; `error=""`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"` | pass |
| ABI | `source.diff` does not change maps, endpoint structs, metadata slots, tail-call indexes, attach points, or payload layouts | pass |
| Coverage | `source.diff` preserves both error branches and only adds Cilium's existing branch hint macro | pass |
| Provenance | `README.md`, `source.diff`, `run-command.sh`, `build.log`, and `result-paths.txt` recorded | pass |

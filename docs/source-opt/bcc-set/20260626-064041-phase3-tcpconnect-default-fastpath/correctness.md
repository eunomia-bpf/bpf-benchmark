# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` completed; `build.log` captured. Candidate object changed only `tcpconnect.bpf.o` relative to the phase2 base. | pass |
| Load | `bcc/set` real libbpf-tools started through `make corpus`; app result `status="ok"`, `error=""`. | pass |
| Workload | 3 `stress_ng_bcc_hook_hot` workload samples; workload returncodes unique set `[0]`. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; 3 baseline workloads present. | pass |
| ABI | Only branch prediction hints around existing `tcpconnect` filter/count branches; no map layout, event payload, attach point, or filter semantics changed. | pass |
| Coverage | No BPF program disabled; pid/uid/port/source-port/count/event paths remain present. | pass |
| Provenance | `source.diff`, build diagnostics, run command, run log, and result path are stored in this attempt directory. | pass |

# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` completed; `build.log` captured. | pass |
| Load | `bcc/set` real libbpf-tools started through `make corpus`; app result `status="ok"`, `error=""`. | pass |
| Workload | 3 `stress_ng_bcc_hook_hot` workload samples; workload returncodes unique set `[0]`. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`; 3 baseline workloads present. | pass |
| ABI | `syscount` map key/value layouts, attach sections, data records, and user-visible output contract are unchanged. | pass |
| Coverage | Enter/exit hooks remain attached in `-L`; cgroup, pid, failure, errno, latency, and process-grouping paths remain present. | pass |
| Provenance | `source.diff`, object diagnostics, run command, run log, and result path are stored in this attempt directory. | pass |

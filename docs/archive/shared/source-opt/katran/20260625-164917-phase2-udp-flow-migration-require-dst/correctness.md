# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | `make -C vendor katran-x86` rebuilt `vendor/build/x86/katran/bpf/balancer.bpf.o`; formal `make corpus` copied `vendor/build/x86/katran/bpf/*.bpf.o` into the runtime image. | pass |
| Load | Real `katran_server_grpc` startup completed; app `status=ok`, `error=""`. | pass |
| Workload | Three `xdp_pktgen` samples completed; no workload component returned nonzero. | pass |
| Result schema | `post_rejit=null`; `rejit_result.mode=skip_rejit_all`; `baseline.workloads[]` has 3 samples. | pass |
| ABI | Map layouts, event payloads, attach point, tail-call dispatch, and packet encap format are unchanged. | pass |
| Coverage | No VIP, LRU, CH, QUIC, stable routing, or flow-migration feature is removed; the patch only skips flow-migration checks when no destination real exists yet. | pass |
| Provenance | `source.diff`, diagnostics, build log, run log, command, result path, and notes are in this directory. | pass |

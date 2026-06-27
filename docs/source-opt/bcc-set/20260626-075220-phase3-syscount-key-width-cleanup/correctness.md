# Correctness

| Gate | Evidence | Result |
| --- | --- | --- |
| Build | `make -C vendor bcc-x86` completed and regenerated `syscount.bpf.o`, `syscount.skel.h`, and `syscount`; `build.log` captured. | pass |
| Load | `bcc/set` real libbpf-tools started through `make corpus`; app result `status="ok"`, `error=""`. | pass |
| Workload | 3 baseline workload samples returned 0; stress-ng sums were `794399`, `794426`, `794353` real-time bogo ops/s. | pass |
| ReJIT disabled | `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`. | pass |
| ABI | `syscount` keeps the same user-visible `data` map, output records, filters, syscall keys, and latency/count semantics. Only the private BPF-side `start` timestamp scratch map changes from tid hash to task local storage. | pass |
| Scope | Patch only modifies BCC libbpf-tools eBPF source files already used by the real BCC binaries. | pass |

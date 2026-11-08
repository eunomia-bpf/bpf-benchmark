# Observed ARM first-pass application coverage

All six first-pass application runs are closed. Load attempts retain probes, transients, retries and failures. Resident rows and service requests have separate denominators.

| App | Baseline loads / IDs / resident | Native loads | Requests | Compiled | Bound | Specialization error | Verifier error | Other loader error | Application |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc | 74 / 74 / 23 | 69 | 19 | 19 | 16 | 0 | 3 | 0 | error |
| otelcol-ebpf-profiler | 16 / 15 / 12 | 3 | 1 | 1 | 0 | 0 | 0 | 1 | error |
| cilium | 8 / 5 / 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| tetragon | 205 / 201 / 152 | 19 | 0 | 0 | 0 | 0 | 0 | 0 | error |
| katran | 6 / 6 / 1 | 6 | 1 | 1 | 1 | 0 | 0 | 0 | ok |
| tracee | 162 / 162 / 151 | 9 | 1 | 1 | 0 | 0 | 0 | 1 | error |

Katran completes guest/application execution with one bound request. [Its work record](katran-two-start-work.json) retains matching packet/BPF/VIP/TX/receiver counts for both phases. Tracee records one generated and compiled request, followed by a native-link tail-map-plan rejection before verifier submission. The recorded ARM loader build predates the shared PROG_ARRAY identity repair at 3d0e584b5; the next source epoch consumes an updated ARM build. Original host status and shared-source drift flags remain in each raw result. Whole-application repairs and universal safety theorem work continue.

| Application | Recorded failure class | Count |
| --- | --- | ---: |
| BCC | Verifier infinite-loop rejection | 3 |
| OTel | Readonly-byte binding | 1 |
| Cilium | Guest library readonly filesystem | 1 |
| Tetragon | Feature-probe map descriptor identity | 1 |
| Tracee | Native-link tail-map plan | 1 |

Cilium and Tetragon failures occur during application startup; their request counts stay zero. Each application row in coverage-table.json links the complete runtime coverage and original archive hash.

## Closed startup successors

The original six first-pass rows retain their cohort identities. The generic
[application batch reader](../../../kprog/results/kprog_fidelity_20261107/application-batches/README.md)
now also reconciles the following closed ARM runtime epochs with their complete
archives, published identity audits and raw workload measurements.

| ARM application / epoch | Baseline resident / BPF calls | Requests | Generated / compiled / bound | Recorded boundary |
| --- | ---: | ---: | ---: | --- |
| Cilium225318 | 0 / 0 | 0 | 0 / 0 / 0 | gops HOME filesystem |
| Cilium230103 | 0 / 0 | 0 | 0 / 0 / 0 | endpoint-generation330-second deadline |
| Tetragon231024 | 157 / 25,136 | 1 | 1 / 1 / 0 | verifier exclusive-retry loop |

[The increment](../../../kprog/results/kprog_fidelity_20261107/application-batches/arm-startup-successor-increment.json)
retains the prior26-cohort/104-request collection and joins12 additional published
artifacts. Cilium's zero-request identity flags remain false. Tetragon's one
request has matching kernel/worker/receipt native bytes and six artifact hashes;
its six baseline stressors return0. OTel and Tracee runtime queues continue,
followed by the Cilium virtual-clock and guarded-module Katran queues.

## Closed resource and instruction-clock cohorts

The existing generic application archive reader joins each published coverage field, phase measurement, request artifact and native byte identity in closed-runtime-increment.json. Original cohort rows retain their source/boot epochs.

| Application / publication | Baseline resident / BPF calls | Requests | Generated / compiled / bound | Recorded class |
| --- | ---: | ---: | ---: | --- |
| otel / bfaeaf240 | 12 / 163,901 | 2 | 2 / 1 / 1 | guest_oom_clang |
| tracee / 7e35f5cb6 | 151 / 161,369 | 2 | 2 / 2 / 1 | scalar_pointer_verifier_refusal |
| cilium / 4aa04fec4 | 62 / 124,884 | 1 | 0 / 0 / 0 | helper_identity_domain |

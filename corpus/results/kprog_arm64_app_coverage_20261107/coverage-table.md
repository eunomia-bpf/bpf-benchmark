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

## Guarded-module Katran successor

| Application / publication | Baseline resident / BPF calls | Native resident / BPF calls | Requests | Generated / compiled / bound | Application |
| --- | ---: | ---: | ---: | ---: | --- |
| Katran / f869a5ff8 | 1 / 24,000 | 1 / 25,473 | 1 | 1 / 1 / 1 | ok |

[Guarded same-work counters](helper-guard-runtime/replay/trusted-arm64-katran-result/same-work.json) match pktgen/BPF/total/VIP/TX/LRU/receiver packets within each phase. Both phases record one LRU miss and0 packet/interface error/drop counters. The common kernel-owned path generates, verifies, binds and runs the one application request with matching native identities. OTel8GiB closes in1d63beebe with two compiled requests, one accepted request and one unaligned-stack verifier refusal. The live skb projection adopts in aed0d2b57; the matched-module Cilium/Tracee sequence retains its captured source epoch.

Current successor 2026-11-08T05:16:12.507163+00:00: stack byte-arm safety94c23b60f closes34cases with4positive native executions,16verifier/13specializer/1loader refusals and unsafe accepted/executed0/0. H324219/launch1fda0417d runs Cilium8-11 then Tracee. BCC/Tetragon331567 follows the Tracee CPU release; complete OTel387692/launchc606610ad follows H. C shared five-step publication supplies the ARM module/specializer migration interface.

Captured complete-application cohorts from the retained pre-migration runtime follow. Baseline resident counts are the final JIT workload snapshots; service source IDs count actual received native requests. Generated and compiled B counts come from each cohort's recorded source/object presence. Each application links its coverage JSON and adjacent complete raw runtime archive. Startup errors retain the exact frontier reached by that whole-application attempt.

| Application | Baseline resident | Service source IDs | B generated / compiled | Verifier accepted | Specialization failures | Verifier refusals | Observed cause | Whole app |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- | --- |
| [BCC](bcc-full-start-coverage.json) | 23 | 19 | 19 / 19 | 16 | 0 | 3 | 3 exclusive retry loops | error |
| [OTel](otel-memory-replay/replay/trusted-arm64-otelcol-ebpf-profiler-result/coverage.json) | 12 | 2 | 2 / 2 | 1 | 0 | 1 | 1 unaligned stack load | error |
| [Cilium](cilium-clock-replay/replay/trusted-arm64-cilium-result/coverage.json) | 62 | 1 | 0 / 0 | 0 | 1 | 0 | 1 helper189 finite-target generation | error |
| [Tetragon](tetragon-startup-replay/replay/trusted-arm64-tetragon-result/coverage.json) | 157 | 1 | 1 / 1 | 0 | 0 | 1 | 1 exclusive retry loop | error |
| [Katran](helper-guard-runtime/replay/trusted-arm64-katran-result/coverage.json) | 1 | 1 | 1 / 1 | 1 | 0 | 0 | 0 | ok |
| [Tracee](entry-resource-scope/tracee-replay/trusted-arm64-tracee-result/coverage.json) | 151 | 2 | 2 / 2 | 1 | 0 | 1 | 1 scalar context memory access | error |

Katran completes both workload arms; its [same-work record](helper-guard-runtime/replay/trusted-arm64-katran-result/same-work.json) retains24,000baseline and25,473native packets with phase-local packet/BPF/receiver counter agreement. Current Cilium has one fresh accepted request in its active whole-app cohort; its terminal coverage will join the completed-cohort table. The generic XDP buffer helper, Tracee CORE helper and stack byte-arm fixes have captured component results and pending whole-app consumption. C shared five-step publication precedes the new ARM BCC/Katran/34-case migration replays. QEMU measurements describe functional behavior.

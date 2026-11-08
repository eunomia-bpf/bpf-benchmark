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

| Application | Baseline resident | Service source IDs | B generated / compiled | Verifier accepted | Specialization failures | Verifier refusals | Kernel request failures | Observed cause | Whole app |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- | --- |
| [BCC](bcc-full-start-coverage.json) | 23 | 19 | 19 / 19 | 16 | 0 | 3 | 0 | 3 exclusive retry loops | error |
| [OTel](otel-memory-replay/replay/trusted-arm64-otelcol-ebpf-profiler-result/coverage.json) | 12 | 2 | 2 / 2 | 1 | 0 | 1 | 0 | 1 unaligned stack load | error |
| [Cilium](xdp-byte-helpers/applications/cilium/trusted-arm64-cilium-result/coverage.json) | 62 | 3 | 2 / 2 | 1 | 0 | 1 | 1 | 1 context alignment; 1 kernel request ESTALE | error |
| [Tetragon](tetragon-startup-replay/replay/trusted-arm64-tetragon-result/coverage.json) | 157 | 1 | 1 / 1 | 0 | 0 | 1 | 0 | 1 exclusive retry loop | error |
| [Katran](helper-guard-runtime/replay/trusted-arm64-katran-result/coverage.json) | 1 | 1 | 1 / 1 | 1 | 0 | 0 | 0 | 0 | ok |
| [Tracee](entry-resource-scope/tracee-replay/trusted-arm64-tracee-result/coverage.json) | 151 | 2 | 2 / 2 | 1 | 0 | 1 | 0 | 1 scalar context memory access | error |

Katran completes both workload arms; its [same-work record](helper-guard-runtime/replay/trusted-arm64-katran-result/same-work.json) retains24,000baseline and25,473native packets with phase-local packet/BPF/receiver counter agreement. Cilium closes d81268950 with one accepted request, one stock verifier context-alignment refusal and one kernel-facts ESTALE before generation. Tracee is the active whole-app successor at8-11. The generic XDP buffer helper, Tracee CORE helper and stack byte-arm fixes have captured component results and pending whole-app consumption. C shared five-step publication precedes the new ARM BCC/Katran/34-case migration replays. QEMU measurements describe functional behavior.

## Closed five-step and helper cohorts, 2026-11-08T07:33:34.111936+00:00

Each row retains its source/runtime epoch. Baseline resident programs count the workload snapshot; service source IDs count requests reached during native startup. The adjacent coverage JSON and complete raw archive carry every observed request and workload counter.

| Application | Baseline resident | Service source IDs | Generated C / compiled B | Verifier accepted and installed | Specialization errors | Verifier errors | Request or loader errors | Cause | Whole app |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- | --- |
| [BCC](../kprog_arm64_app_coverage_20261108/bcc-execution/trusted-arm64-bcc-result/coverage.json) | 23 | 23 | 23 / 23 | 23 | 0 | 0 | 0 | 20positive /3zero execution counters in each arm | ok |
| [OTel](../kprog_arm64_app_coverage_20261108/design-only-remaining/trusted-arm64-otelcol-ebpf-profiler-result/coverage.json) | 12 | 3 | 3 / 3 | 2 | 0 | 1 | 0 | 1 bpf_stack_extent (-576) | error |
| [Cilium](xdp-byte-helpers/applications/cilium/trusted-arm64-cilium-result/coverage.json) | 62 | 3 | 2 / 2 | 1 | 0 | 1 | 1 | 1 context_access_alignment, 1 kernel_facts_estale | error |
| [Tetragon](../kprog_arm64_app_coverage_20261108/design-only-remaining/trusted-arm64-tetragon-result/coverage.json) | 163 | 1 | 1 / 1 | 0 | 0 | 1 | 0 | 1 exclusive_retry_loop | error |
| [Katran](../kprog_arm64_app_coverage_20261108/design-only-x30/trusted-arm64-katran-result/coverage.json) | 1 | 1 | 1 / 1 | 1 | 0 | 0 | 0 |  | ok |
| [Tracee](xdp-byte-helpers/applications/tracee/trusted-arm64-tracee-result/coverage.json) | 151 | 3 | 3 / 3 | 2 | 0 | 1 | 0 | 1 bpf_stack_extent | error |

Five-step Katran84907b44c completes with host/QEMU/guest/application success and one fresh native request. JIT/native work records13,605/20,865BPF calls with matching phase-local total/VIP/TX/LRU packet counts. Each phase has0LRU misses; receiver and interface deltas accompany the JSON. QEMU durations describe functional execution. BCC retains15installed requests,3exclusive-retry verifier errors and1kernel chunk ENOENT error. Tracee retains2installed requests and its third request reaches the stock BPF stack extent at-520; this refines the earlier generic loader classification. OTel retains1installed request and its stack alignment error. The active five-step Tetragon/OTel/Cilium/Tracee queue has immutable launch385d5095c.

Tetragon493965393 closes its first complete five-step replay with163baseline resident programs and29897BPF invocations. Its first native request generates and compiles B, then reaches the stock exclusive-retry-loop error. The serial queue continues with OTel/Cilium/Tracee on captured source385d5095c. Canonical source adoptionf434f46a2 and the complete34-case replay retain separate cohorts.

OTel d7eab41ef closes the captured five-step replay with3fresh source/B objects and2installed programs. perf_unwind_native reaches stock-verifier stackoffset-576; the raw arena/tag/payload layout is496/64/8bytes. The serial queue continues with captured Cilium and Tracee. The complete BCC LSE successor has23successful service receipts while its application workload closes.

BCC b9378e020 completes the full five-step LSE two-start recipe at host/QEMU/guest/compiler exits0, with23fresh generated/compiled/accepted/installed requests. JIT/native counters record116354/72897BPF calls;13programs in each arm have positive counters and10retain zero counts for block/TCP/fsync trigger classes. [Exact phase and stressor counters](../kprog_arm64_app_coverage_20261108/lse-app/trusted-arm64-bcc-result/work-counters.json) retain syscall507/507 and each remaining duration-driven count.

Cilium's [latest whole-startup attempt](../kprog_arm64_app_coverage_20261108/design-only-remaining/trusted-arm64-cilium-result/coverage.json),142681d1f, closes during JIT-baseline endpoint creation with the synchronous API generation deadline and0native service requests. Its baseline counter snapshot remains pending; the Cilium native-stage row above retains its earlier captured cohort. Runner5f640f610 requests asynchronous creation and reuses the existing ready waiter; its complete successor is queued.

BCC real-event successor584ae11ac retains all23 generated/compiled/verifier-accepted/installed programs and app success in both arms. Fixed IPv4/IPv6 connections and16MiB direct I/O raise positive execution rows to20/23 per phase. JIT/native record183822/192059BPF calls; each TCP entry/return probe records8calls and each syscall stressor records507bogo operations. [The full counter record](../kprog_arm64_app_coverage_20261108/bcc-execution/trusted-arm64-bcc-result/work-counters.json) retains actual per-program/workload denominators. AIO fsync and queue-pressure inputs are the active successor for the three remaining cold hooks.

## Latest Tracee five-step terminal receipt, 2026-11-08T10:59:11.844506+00:00

[Tracee 280edd626](../kprog_arm64_app_coverage_20261108/design-only-remaining/trusted-arm64-tracee-result/coverage.json) records151baseline resident rows,3fresh generated/compiled requests,2installed programs and1kernel native-chunk ENOENT loader error. Request3 spans guest seconds6944.609 to7368.327; the application reports its7200-second lifecycle deadline. Capsule abandonment is a candidate cause alongside the map-lookup path. The complete kernel/service/application logs retain that distinction. The earlier stack-offset receipt above keeps its captured source/runtime epoch.

[BCC queued-input startup](../kprog_arm64_app_coverage_20261108/bcc-execution-queued/startup-libaio/summary.json) retains the first AIO library-resolution failure and full raw archive. The corrected successor uses the guest-installed libaio.so.1t64 and writes to its own result directory. The23accepted /20positive-program BCC cohort above remains the last completed two-start work comparison while this successor runs.

## Current BCC and Tetragon terminal cohorts, 2026-11-08T11:24:47.275730+00:00

| Application | Baseline resident | Requests | Generated / compiled | Installed | Verifier errors | Work |
| --- | ---: | ---: | ---: | ---: | --- | --- |
| [BCC](../kprog_arm64_app_coverage_20261108/bcc-execution-queued/trusted-arm64-bcc-result/README.md) | 23 | 23 | 23 / 23 | 23 | 0 | JIT/native441319/443267calls;21/23positive rows per phase |
| [Tetragon](../kprog_arm64_app_coverage_20261108/lse-tetragon/trusted-arm64-tetragon-result/coverage.json) | 161 | 3 | 3 / 3 | 2 | third body stackoffset-792 | baseline23944calls; native startup records the stack error |

BCC block_rq_insert uses the upstream optional -Q attachment path; its current command uses default arguments. The remaining merge hook keeps its zero observation. Tetragon LSE replaces the earlier exclusive-retry frontier with the current private-storage frontier. Each cohort retains its complete raw archive and source epoch.

Cilium async-endpoint successor closes with62JIT-baseline rows and17540BPF calls. Native configuration compilation exits with signal:killed before service submission; the latest-terminal-attempt JSON retains0requests and its exact raw archive alongside the earlier native-stage row. Signal/OOM/context-cancellation attribution continues from the captured compiler and kernel logs.

Cilium wrapper follow-up: captured native ELF complete, six text functions; host configuration compile0 with allocated sections byte-identical, all six proof-link commands0. The terminal QEMU epoch contains0service requests. Detailed source/context observations and the frozen-runner operator case are in ../kprog_arm64_app_coverage_20261108/cilium-native-compile/.

Tetragon precise-copy application terminal c9a653161: baseline154 resident rows,5proofs generated/compiled,4installed, execve_send reaches the stock8193jump-sequence frontier after667530instructions/6806states. event_wake_up_new_task crosses its former compiled-stack frontier and installs. Canonical successor2766f65c retains its own source/work receipts.

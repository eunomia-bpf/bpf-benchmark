# x86 application coverage, November8 UTC

The table records the latest closed complete-application attempt. Baseline resident census and observed terminal service requests retain distinct domains. Every attempt starts the original upstream application and preserves its native inputs, work counters and terminal logs. BCC and Katran complete the generation-bound arm and have R timing ownership. The remaining four applications continue through the frontiers below.

| Application | Baseline census | Generated | Compiled | Bound | Submission/specialization/loader errors | Verifier rejections | Raw evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/native-only-runtime/standard-bcc-8g.json) |
| OTel | 13 resident | 5 | 5 | 4 | 1: 900-second lifecycle timeout, then worker activation refusal | 0 | [035354](otel-host-compile/README.md) |
| Cilium | 72 resident | 2 | 2 | 1 | 0 | 1: TC data_len pointer arithmetic | [033637](cilium-dead-helper/README.md) |
| Tetragon | 287 resident | 4 | 4 | 3 | 0 | 1: execve_send jump complexity | [035351](tetragon-c-mask/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/katran-tagged-storage/README.md) |
| Tracee | 151 resident | 6 | 6 | 5 | 0 | 1: readonly table index range | [034222](tracee-c-mask/README.md) |

Current detached work runs the complete original Cilium application with the native skb data_len scalar read through the matching kernel context. Whole Tracee follows with [destination-width MOVZX/MOVSX value identity](movx-value-identity/typed32/README.md), then the [OTel continuation](otel-host-compile-continuation-plan.json) uses fresh host compilation and the existing corpus lifecycle interfaces set to0. Each application owns one 12 GiB/eight-vCPU guest on CPUs20-23 and one registered service. The completed 38-case pruned-helper suite retains 9 positive executions and 29 unsafe refusals. Actual terminal receipts determine coverage and acceptance. The [Cilium input record](cilium-skb-data-len-plan.json) captures its BTF field identity and launch source.

Recorded frontiers retain their separate entries and candidate epochs:

| Application / entry | Recorded frontier | Complete batch |
| --- | --- | --- |
| OTel / perf_unwind_native | R10-520 proof-stack write | [012120](otel-fixed-stack/README.md) |
| Tetragon / event_execve | R10-888 proof-stack write | [014223](tetragon-fixed-stack-retry/README.md) |
| Tetragon / execve_send |8193-jump sequence | [005356](tetragon-typed-read/README.md) |
| Tracee / sys_exit_submit | probe_read length range | [013224](tracee-fixed-stack/README.md) |
| Cilium / tail_handle_ipv4_from_host | kernel native-region kfunc identity | [010928](cilium-original-btf/README.md) |
| Cilium / tail_drop_notify | native relocation identity for pruned internal hash lookup;809instructions/14states | [021801](cilium-matched-runtime/README.md) |

The [Cilium matched-module cohort](cilium-matched-runtime/README.md) completes its original baseline and reaches resource binding after symbolic verification. The [generic callback correction](dead-map-helper-binding/README.md) passes614400source-extracted ASan/UBSan controls and the matching x86 module build. Whole-application replay supplies its next acceptance receipt.

The [registered-kfunc native-only suite](kfunc-native-only-safety/README.md) executes9positive controls and refuses29unsafe submissions:22verifier,6specializer,1loader. All38native archive hashes reconcile. Unsafe fixtures use load-only producer commands; positives execute bound TEST_RUN with matching outputs.

The [kernel and matching module records](kernel-kfunc-binding/README.md) preserve the registered-kfunc verifier profile, complete build,842module identities and exact runtime-section/BTF/relocation comparisons after standard strip/sign. Runtime image/config/module links remain available after the duplicate private guard build was retired; the shared incremental kernel cache retains its ownership.

Earlier complete attempts preserve the progression through [OTel aligned stack](otel-stack-aligned/README.md), [typed reads](otel-typed-read/README.md), [explicit RSP offsets](stack-fixed-offsets/README.md), [Tracee aligned stack](tracee-stack-aligned/README.md), [Tracee typed reads](tracee-typed-read/README.md), [Cilium original BTF](proof-kfunc-original-btf/README.md), [paired kfunc transport](proof-kfunc-transport/README.md) and the current table's raw cohorts. Universal ISA/token/link laws supply safety; captured component measurements and whole-application outcomes each retain their own evidence domain.

The [whole OTel typed-stack cohort](otel-typed-stack/README.md) freshly binds perf_unwind_native and advances to perf_unwind_hotspot compilation. Its12GiB guest records a Clang OOM kill at9.63GiB anonymous RSS; fresh trusted host compilation is the next resource correction. The [generic typed-stack measurements](typed-private-stack/README.md) preserve exact compiler inputs and completed fidelity controls.

The [whole Tracee typed-stack cohort](tracee-typed-stack/README.md) retains6fresh generation/compilation and5bound loads. Its readonly80-byte table frontier exposes a redundant mask on a comparison copy; a generic C-cast width representation is being checked against BPF-JIT/host/byte observations before the complete-app successor. Prior fixed-RSP helper-length logs preserve their own source epoch.

The [whole Tetragon typed-stack cohort](tetragon-typed-stack/README.md) closes4fresh generation/compilation and3bound loads, reaching execve_send8193jumps after63411instructions/707states. Its current complexity frontier and event_execve frame measurements retain their separate entry domains.

The latest complete batches retain [Cilium TC scalar projection](cilium-dead-helper/README.md), [Tracee readonly indexing](tracee-c-mask/README.md) and [Tetragon native control-flow complexity](tetragon-c-mask/README.md). All12terminal native hashes reconcile. The existing pruned-helper38-case safety suite retains9positive executions and29unsafe refusals. OTel fresh host compilation continues with its captured native and source inputs.

The [fresh host-compiled OTel cohort](otel-host-compile/README.md) binds perf_unwind_native and perf_unwind_hotspot, reaching 4 bound entries across 5 successful compilations. Its explicit 900-second lifecycle timeout precedes the fifth worker activation refusal. The public simulator header evolves during the run; the actual private compiler inputs retain their captured hashes. The continuation keeps native input and workload identity while allowing startup to follow compiler/load completion.

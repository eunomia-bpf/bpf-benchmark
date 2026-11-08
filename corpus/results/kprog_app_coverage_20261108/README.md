# x86 application coverage, November8 UTC

The table records the latest closed whole-application attempt, including setup and compiler-transport outcomes. Baseline resident census and observed terminal service requests retain distinct domains. Every attempt starts the original upstream application and preserves its native inputs, work counters and terminal logs. BCC and Katran complete the five-step native arm and have R timing ownership. The remaining four applications continue through the frontiers below.

| Application | Baseline census | Generated | Compiled | Installed | Submission/specialization/loader errors | Verifier rejections | Raw evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [final five-step cohort](bcc-katran-five-step/README.md) |
| OTel | 13 resident | 3 | 3 | 2 | 0 | 1: perf_unwind_native verifier exploration1000001instructions | [whole five-step cohort](whole-five-step-0700/README.md) |
| Cilium | 62 resident | 1 | 0 | 0 | 1: missing C body for helper189, bpf_xdp_load_bytes | 0 | [matched-module cohort](xdp-load-helper/README.md) |
| Tetragon | 287 resident | 5 | 5 | 4 | 0 | 1: event_execve stack write R10-944/8 after482instructions | [whole five-step cohort](whole-five-step-0700/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [final five-step cohort](bcc-katran-five-step/README.md) |
| Tracee | 151 resident | 2 | 2 | 1 | 0 | 1: R2 scalar memory access after242instructions | [matched-module cohort](xdp-load-helper/README.md) |

Current detached work runs complete Cilium and Tracee with the final-vmlinux module package, captured sources and a writable shared compiler directory; complete Tetragon and OTel follow with their own compiler lifecycle. Each application owns one 12 GiB/eight-vCPU guest on CPUs20-23 and one registered service. The [final-source38-case safety replay](five-step-x86-replay/README.md) executes9 positive controls and records27 stock-verifier refusals plus2 generation coverage failures. Historical whole-app coverage frontiers and their source epochs remain below.

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

The [whole Tracee destination-width cohort](tracee-movx-identity/README.md) carries the checked byte through readonly indexing and reaches probe_read length range at 2,776 instructions and107states. The [Cilium include audit](cilium-skb-data-len/README.md) attributes its measured object to the historical skb header; the selected-header successor preserves that diagnostic epoch and changes the actual compiler include graph. Its collection repair also preserves the prior published driver and archive bytes. The [generic numeric-iterator control](numeric-iterator-call/README.md) completes native/BPF compilation and native proof linking, then identifies typed kernel-call ABI modelling as the next Tetragon mechanism.

The [complete Cilium selected-skb cohort](cilium-owned-skb-053636/README.md) installs `cil_xdp_entry` and reaches `tail_nodeport_nat_ingress_ipv4` packet access offset18/size2 after373instructions. All2terminal native hashes reconcile. Captured inputs retain the pre-five-step module and actual compiler includes; three live source paths advance during the cohort. The successor consumes the published five-step kernel/module/service.

The [five-step x86 replay](five-step-x86-replay/README.md) retains the completed38-case safety outcomes, all four original whole-application setup attempts, captured compiler inputs and842matching standard modules. All38 safety and3 application native hashes match their terminal records. The kernel image/vmlinux hashes stay equal across the incremental module refresh. Historical whole-application receipts retain OTel5generated/4installed, Cilium2generated/1installed, Tetragon4generated/3installed and Tracee6generated/5installed on their captured earlier source epochs. Corrected five-step cohorts supply the ensuing coverage and work receipts.

The [XDP byte-load helper extension](xdp-load-helper/README.md) adds Linux189 to the existing68-row C/JSON/Lean dispatcher. Existing4100ID/18946typed-ABI observations, both helper Lean modules and29+1micro compile controls pass. Complete matched-module Cilium reaches that missing-body frontier; Tracee installs its first program and reaches the later R2 scalar read. The successor runs the entire original Cilium application with the extended snapshot.

The [final BCC/Katran five-step cohort](bcc-katran-five-step/README.md) completes26/26 actual native loads and both original workloads. BCC syscall work is514in each arm. Katran processes2523084JIT/2455449native packets with matching per-arm BPF/VIP/LRU/TX counts and0LRU misses; native delivery accounts for2452337received+2550TX-interface+562RX-interface packets. All26native request-object hashes match the prior five-step cohort. R retains the existing timing snapshots and native-source decision.

The [whole Tetragon/OTel five-step cohorts](whole-five-step-0700/README.md) retain11terminal native hash joins. Restoring the current237-row Tetragon asset inventory advances its entire startup to5generated/4installed and the event_execve stack-write frontier. OTel reaches3generated/2installed and the perf_unwind_native exploration frontier. Original startup errors, native objects and work counters retain their full logs.

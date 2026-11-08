# x86 application coverage, November8 UTC

The table records the latest closed whole-application attempt, including setup and compiler-transport outcomes. Baseline resident census and observed terminal service requests retain distinct domains. Every attempt starts the original upstream application and preserves its native inputs, work counters and terminal logs. BCC and Katran complete the five-step native arm and have R timing ownership. The remaining four applications continue through the frontiers below.

The current four-application cohort is [4e9a9c7b1](undefined-flags/four-apps-retry/README.md), captured on the canonical c1f6 PF/AF model and original native inputs. Fourteen terminal service requests generate14 and compile13, with10 installed,3 verifier rejections and1 compiler SIGKILL. Each application's original baseline completes and its native startup reaches the recorded frontier. Baseline resident counts come from this exact cohort; Cilium has60 resident programs in this startup. Whole Cilium with approved generic native-division lowering is running as its successor.

| Application | Baseline census | Generated | Compiled | Installed | Submission/specialization/compiler errors | Verifier rejections | Raw evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [current canonical PF/AF and paired-runtime replay](undefined-flags/bcc-katran/README.md) |
| OTel | 13 resident | 3 | 2 | 2 | 1: perf_unwind_native compiler SIGKILL | 0 | [canonical PF/AF whole cohort](undefined-flags/four-apps-retry/README.md) |
| Cilium | 60 resident | 4 | 4 | 3 | 0 | 1: tail_handle_ipv4_from_host packet offset30/size4; length-derived end comparison | [canonical PF/AF whole cohort](undefined-flags/four-apps-retry/README.md) |
| Tetragon | 287 resident | 4 | 4 | 3 | 0 | 1: execve_send sequence of8193jumps | [canonical PF/AF whole cohort](undefined-flags/four-apps-retry/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [current canonical PF/AF and packet accounting](undefined-flags/bcc-katran/README.md) |
| Tracee | 151 resident | 3 | 3 | 2 | 0 | 1: sys_enter_submit invalid read from stack off-288+0/size8 | [canonical PF/AF whole cohort](undefined-flags/four-apps-retry/README.md) |

The [approved return-default38-case replay](native-division-ret/safety/README.md), b844cf955, executes all9 positive controls and records27 stock-verifier rejections plus2 generation coverage failures. Every original unsafe native input uses load-only submission; actual unsafe native executions0. The original DIV cases exercise exact architectural #DE semantics. The [native compiler lowering component](native-division-ret/README.md) records2030051 independent scalar, optnone, live-condition and fixed-vector results for total native-input division.

The [complete-resource x86 kernel-C successor](kernel-selftests-whole-resources/README.md), 448d7ff35, captures all239 earlier native entries with original annotations,39 complete original BPF resource source units/38 successful resource compilations, upstream bpf_testmod and the current helper194 loader/linker. Its sole12GiB guest follows actual Cilium completion. The earlier [direct native table](kernel-selftests-direct/README.md) retains its239 native outcomes, and the [resource type observation](kernel-selftests-direct/README.md) carries the original FWD/STRUCT investigation where available. Historical application frontiers retain their own source epochs below.

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

The [Tracee current CORE-input cohort](tracee-current-core/README.md) consumes the existing published native build7479850e and installs five entries across six generated/compiled requests. The sixth reaches native chunk creation ENOENT after the historical300second image runner closes its client. The current-runner image successor keeps the same native input and waits for compile/load completion. The current header/native-source identity and original151-program baseline are preserved.

The [XDP metadata projection](xdp-metadata/README.md) maps the actual native xdp_buff64-bit field16 to the typed data_meta context field. Existing29+1micro compile controls complete. The full Cilium startup advances to3generated/compiled and2installed, reaching a stack-alignment refusal in tail_handle_ipv4 after352instructions.

The [whole Tracee current-runner cohort](tracee-current-runner/README.md) reaches the stock verifier on all6generated/compiled requests and installs5. Its current source reaches readonly80-byte table indexing atoffset1036/4 after3042instructions and92states; the current-runner image waits for compile/load completion. The prior300second client-exit receipt retains its own source epoch.

The [private-stack register-alias store representation](private-stack-bytes/README.md) reuses the existing byte ladder for scalar MOV stores while preserving pointer-wide and public memory operations. Existing4104678UBSan state observations and29+1micro compile controls pass, as does the captured wholeCilium source compile. The complete original Cilium successor closes5generated/compiled and4installed, reaching the proof-stack writeoff-544/8 after389instructions.

The [current MOVZX/MOVSX destination-lane representation](movx-current/README.md) adopts the existing generic profile in the canonical model and preserves142564UBSan complete-state observations. Current Tracee source compilation and29+1micro controls complete; the entire original Tracee startup follows with its frozen current snapshot and native7479850e.

The [whole Tracee current MOVX cohort](movx-current/README.md) closes6generated/compiled and5installed, passing the readonly table frontier and reaching probe-read helper length range after4310instructions/140states. All six terminal native hashes match; the original application error and work counters retain their raw records.

The [private flag-storage compiler measurements](flag-storage/README.md) retain7347785UBSan observations and paired current-header frames: Cilium616?768bytes, Tetragon1280?1280bytes. The canonical scalar flags remain selected. Source inspection directs the following x86 context work to real skb112/116fields and the216-byte proxy allocation; the private live-context component measures416direct frame bytes. Whole-application receipts follow its frozen source.

The [live kernel skb representation](skb-live-context/README.md) replaces padded context accesses with actual kernel fields and live packet/cb projections. Existing144640UBSan field observations,18946/4100helper cases,29+1micro compile controls and both universal context Lean modules pass. The shared exact-base helper relation removes its runtime context-null conjunct. Earlier live-context cohorts preserve their helper25CTX and setup-alias errors; the entire Cilium and original BCC/Katran successors run with one frozen source owner. Historical padded-context cohorts retain their measured loads and native work counters; current field modelling supplies their faithfulness correction.

The [complete live-context replay](skb-live-context/README.md) closes26/26BCC/Katran loads and both original workloads, preserving all26native input hashes. Katran native2454567BPF/VIP/LRU/TX equals2454279received+288RX-interface drops, with0LRUmisses. Current Cilium passes helper25context typing and reaches tc_index134byteAND at528instructions/7states.

The [live scalar-field representation](skb-scalar-fields/README.md) retains217600UBSan full-state observations, actual29+1micro compilation and captured wholeCilium compilation. The initial four-field whole cohort closes2generated/1installed at packetoff18/2 after415instructions. The canonical three-field profile retains queue_mapping actual kernel access, following its distinct setter behavior. Earlier private micro up-to-date receipts are preserved as command outcomes; the current phony target supplies actual compile records.

The [corrected canonical scalar replay](skb-scalar-fields/README.md) closes26/26BCC/Katran loads and both original workloads, with all26native hashes equal the prior scalar cohort. Cilium closes2generated/compiled and1installed, reaching packetoff30/4 after208instructions. Original closed-broker attempts remain alongside their corrected whole cohorts.

The [prepared native packet-end ABI](cilium-prepared-end/README.md) reads kernel cb.data_end at80 and closes5generated/compiled with4installed. This new native P epoch passes the earlier packet boundary frontier and reaches a numeric stack-pointer spill passed to helper9. All5terminal native hashes reconcile; full application work/timing follows complete startup.

The [whole Tracee immutable-byte cohort](readonly-values/whole-tracee/README.md) retains all terminal generation, compiler and installation outcomes together with actual work and error records. Its finite immutable-value representation keeps the original native data bytes and the existing application/native-source epoch.

The [generic C-copy whole Tracee cohort](readonly-c-loads/whole-tracee/README.md) retains every terminal request, the actual native inputs and raw phase work counters. Its generator emits the immutable-object C representation directly.

The [generic C-copy whole Tracee cohort](readonly-c-loads/whole-tracee-retry/README.md) retains every terminal request, the actual native inputs and raw phase work counters. Its generator emits the immutable-object C representation directly.

The [generic PLT32 tail-jump repair](plt32-tail-jumps/README.md) restores the complete reachable function closure for6 kernel C entries. Its239-entry paired link scan,90Rust cases and29+1micro compilations retain full raw records. Fresh original global_func4 now reaches stock verification with8functions/70native bytes and exposes its __sk_buff/kernel-skb context-layout frontier; global_func8 installs through the same registered service.

## Shared x86 native extent and kernel C helper continuation

The [exact native extent source and fresh shared runtime controls](native-extent/adoption/README.md) use callback-sized emission storage and execute the original small and264-byte native inputs with retval2. Shared kernel/module incremental builds and patch regressions pass. The [original BCC/native-safety replay](native-extent/functional/README.md) closes25/25BCC installations with statusok,9positive native executions,27stock-verifier refusals and2generation coverage outcomes.

The [original kernel C MTU cohort](kernel-helper-context-x86/README.md) submits tcx5,tcx6 andtc_uninit_mtu through source_prog_id0; all3generate,compile andstock-verify. Each probe requests loading, with native executions0. The fresh x86 worker/static/shared build and9existing service cases pass. LaneA retains the common contextual163 identity source ownership.

The [Katran shared-image attempt](native-extent/shared-katran/README.md) records ip_tunnel BTF errno22 during baseline startup. A fresh shared-kernel guest loads the exact current ip_tunnel module successfully. The existing application image refreshes its kernel/module payload from that same shared build, and the original Katran replay continues with its established image content, native inputs and workload. Each terminal record carries its own application status, native-stage counts and work counters.

The current canonical ANDN/BZHI flag cohort [7f95b6c2c](undefined-flags/bcc-katran/README.md) completes BCC25/25 and Katran1/1 with the shared exact-extent Image and paireda507runtime. Actual current work includes BCC syscall514/514 and Katran2465260/2486410input packets, per-phase matched BPF/TX/VIP/LRU/real-map counts, LRU misses0/0 and native receiver2486126plus284drops. Baseline interface sampling carries one extra packet. Historical [BCC stack-spill](stack-spill-values/bcc-katran/README.md) and [Katran paired-module](native-extent/packaged-katran/README.md) cohorts retain their original source epochs. Current [RSP compiler-mechanism observations](tetragon-precise-stack/rsp-displacement/replays/README.md) explain the six private-candidate findings and the universal compiled-B preservation interface. The [direct native kernel C launch](kernel-selftests-direct/README.md) applies the current common producer to239compiled entries from the657C-body/1917total catalog; additional source compilation coverage and actual runtime outcomes retain separate stages.

# Application service batch observations

One generic archive reader reconciles20 closed service batches across all six
application names. All89 terminal requests preserve byte equality between the
kernel-owned native object, the worker's received copy and the service receipt's
SHA256. Kernel source IDs match the service records. The batches contain85
generated sources,84 compiled objects and73 successful bound replies.

Every bound reply's request ID, program ID and status exactly match load.stdout.
All available published counts match the archive-derived counts, including the
latest nested failure classifications. Each request archive is consumed once,
and each service's terminal requests and archive set agree.

| Application / batch | Requests | Generated | Compiled | Bound | Other outcomes |
| --- | ---: | ---: | ---: | ---: | --- |
| bcc / functional_153239 | 25 | 25 | 25 | 25 | 0 |
| otel / functional_192310 | 3 | 3 | 3 | 2 | 1 verifier_rejected |
| cilium / functional_201146 | 1 | 1 | 0 | 0 | 1 compiler_rejected |
| tetragon / functional_201956 | 3 | 2 | 2 | 2 | 1 specialization_rejected |
| katran / functional_201524 | 1 | 1 | 1 | 0 | 1 verifier_rejected |
| tracee / functional_203243 | 3 | 2 | 2 | 2 | 1 specialization_rejected |
| tetragon / functional_205401 | 3 | 2 | 2 | 2 | 1 specialization_rejected |
| tetragon / timing_204105 | 3 | 2 | 2 | 2 | 1 specialization_rejected |
| tetragon / functional_210552 | 3 | 3 | 3 | 2 | 1 native_stub_load_error |
| tracee / functional_211016 | 6 | 6 | 6 | 5 | 1 verifier_rejected |
| katran / functional_213447 | 1 | 1 | 1 | 1 | 0 |
| tracee / arm64_functional_202335 | 1 | 1 | 1 | 0 | 1 loader_rejected |
| bcc / arm64_functional_172354 | 19 | 19 | 19 | 16 | 3 verifier_rejected |
| otel / arm64_functional_182921 | 1 | 1 | 1 | 0 | 1 loader_rejected |
| cilium / arm64_functional_183612 | 0 | 0 | 0 | 0 | startup frontier |
| tetragon / arm64_functional_183759 | 0 | 0 | 0 | 0 | startup frontier |
| katran / arm64_functional_185947 | 1 | 1 | 1 | 1 | 0 |
| tracee / functional_214037 | 6 | 6 | 6 | 5 | 1 verifier_rejected |
| tetragon / functional_221545 | 4 | 4 | 4 | 4 | next manifest selector frontier |
| tetragon / functional_223215 | 5 | 5 | 5 | 4 | 1 verifier_rejected |

The20 rows retain distinct source, image and boot epochs. Counts describe observed
load instances; repeated native objects and repeated program IDs across boots stay
in their original batches. Whole application completion and duration-driven
workload measurements follow the recorded startup frontiers.

## Tetragon complete-source manifest progression

The later223215 cohort receives execve_send through the corrected generic
source-function manifest. All five requests receive fresh generation and
compilation; four bind and match their actual application replacement rows.
Each timing row retains bound_required=1 and prebuilt_proof=0. The fifth
request, execve_send, reaches this actual kernel verifier diagnostic:

~~~text
trusted-native-loader: BPF_PROG_LOAD native_lab stub: Argument list too long
The sequence of 8193 jumps is too complex.
processed 188982 insns (limit 1000000) max_states_per_insn 4 total_states 1926 peak_states 1926 mark_read 0
~~~

The existing shared reader classifies this E2BIG/log boundary as
verifier_rejected and checks all parsed statistics against C's published
observations. The complete15MB diagnostic stream and request commands remain
in failures.jsonl.gz. manifest-increment.json records its exact byte length
and SHA256, alongside the retained earlier observation identities.

The raw baseline app JSON matches the coverage metadata:287 resident counters,
682,697 BPF runs, and an existing stress workload returning0 after2.073563403
seconds. The post_rejit measurement remains null and app status remains error.
Source drift records the trusted_service.py diagnostic-wording update; each
request's literal source identity vector retains its own execution epoch.

This progression adds five requests and four bound replies to the preceding
19 cohorts. The earlier84 terminal rows, complete failure-byte prefix,43 input
pins and every prior batch/work/source-vector object retain their values.
The20-cohort totals are89 requests,85 generated sources,84 compiled objects
and73 bound replies. C owns the common CMP/compiler representation trial and
complete application replay; V/T continue universal simulator/compiler/link
and binding laws.

## Tetragon memcpy binding and the next startup frontier

The221545 cohort receives4 requests and freshly generates, compiles and binds
all4. Every kernel-owned native object equals its worker copy and service SHA256.
The raw application shim agrees with the service's request/source/bound IDs:

| Request | Source ID | Bound ID |
| ---: | ---: | ---: |
| 1 | 333 | 334 |
| 2 | 335 | 336 |
| 3 | 337 | 338 |
| 4 | 339 | 340 |

Every replacement timing row records bound_required=1 and prebuilt_proof=0.
The link-plan rows also match their actual trusted_request IDs. The reader
opens the immutable result archive, checks the complete raw application phase
objects, hashes the executed shim log and joins each successful service reply
to its corresponding application replacement.

event_wake_up_new_task retains the exact native ELF SHA256 across five cohorts:
474212d9dc1c0972c12b8adf84af75d84b69759f3d32c4c2dbb87393adbcf5d4.
The201956,205401 and timing204105 epochs report specialization rejection;
210552 reaches the native-stub load boundary;221545 binds source337 to338 on
the captured T697bea memcpy module epoch. memcpy-increment.json preserves
these five distinct runtime/source epochs around the same native bytes.

The JIT phase contains287 resident counters and545,253 aggregate BPF runs.
Its existing stress workload exits0 after2.176152895 seconds. C's published
observations separately count311 baseline startup attempts, including probes.
The later native startup reaches execve_send's manifest selector before its
service request. C records10368 entry bytes plus928 callback bytes from
cwd_read_v61, giving11296 actual source bytes. The post_rejit raw measurement
remains null and application status remains error. The four terminal service
requests all bind; the next upstream startup frontier retains its own stage.

The shared reader compares C's full raw phase values directly, including null,
while the ARM schema retains its documented empty-object projection.
memcpy-initial-collection.tar.gz preserves the initial schema diagnostic.
The final reader completes with exit0. All prior18 batch objects,80 request
rows, the entire failure archive,39 input pins and earlier workload/source
vectors retain their exact values.

At the221545 checkpoint the totals are19 cohorts,84 terminal requests,80 generated sources,
79 compiled objects and69 bound replies. The15 earlier terminal failure records
remain intact. C owns the generic source-manifest callback closure repair and
the next complete application replay. The universal simulator, compiler, token
and binding laws continue through V/T.

## Dual-ISA first-pass reconciliation

The added five ARM cohorts complete the six ARM application names beside the
earlier Tracee cohort. One shared reader processes every archived request and
whole raw application phase. The six ARM cohorts contain22 generated/compiled
requests and17 bound replies: BCC16/19, Katran1/1, OTel0/1 and Tracee0/1.
Cilium and Tetragon preserve their startup outcomes with zero terminal service
requests. These counts describe actual service observations.

| ARM application | Baseline resident counters | Baseline BPF runs | Bound replies | Recorded app status |
| --- | ---: | ---: | ---: | --- |
| BCC | 23 | 178611 | 16 | error |
| OTel | 12 | 183227 | 0 | error |
| Cilium | 0 | 0 | 0 | error |
| Tetragon | 152 | 30593 | 0 | error |
| Katran | 1 | 26197 | 1 | ok |
| Tracee | 151 | 97751 | 0 | error |

Every available published phase object and resident-counter row equals its raw
application JSON. Empty phase objects retain their startup-frontier meaning.
The older BCC schema supplies full raw phases and an error first line; these
are checked directly. OTel's mixed workload retains its11 component outcomes.
The remaining schemas retain their full error fields and individual counter
lists. Source/host status, QEMU/guest exit and actual application status remain
separate observations.

ARM Katran's source ID31 binds to32; the executed post_rejit counter ID is32.
Its workload records26,197 JIT inputs and23,208 native inputs, with exactly those
BPF invocation counts. Both phase workloads complete. Their duration-driven
totals remain in the captured QEMU functional epoch.

The BCC failures carry explicit verifier loop diagnostics. The generic reader
classifies these before the outer native-stub EINVAL wrapper:

~~~text
fentry_vfs_read: infinite loop detected at insn 2
processed 29 insns (limit 1000000) max_states_per_insn 0 total_states 2 peak_states 2 mark_read 0
sys_exit: infinite loop detected at insn 203
processed 166 insns (limit 1000000) max_states_per_insn 0 total_states 12 peak_states 12 mark_read 0
sched_switch: infinite loop detected at insn 346
processed 350 insns (limit 1000000) max_states_per_insn 0 total_states 22 peak_states 22 mark_read 0
~~~

Every published decisive BCC diagnostic matches its raw stream. The historical
x86 Tetragon native-stub classification retains its original value. OTel's
actual loader boundary is preserved exactly:

~~~text
libbpf: elf: skipping unrecognized data section(6) .native_lab.rodata
trusted-native-loader: readonly proof data does not match native bytes
~~~

A's coherent loader/linker publication advances the next application epochs;
these six first-pass records retain their original execution sources.

The additional x86 Tracee214037 batch has6 fresh generated/compiled requests
and5 bound replies. sys_exit_submit retains the exact readonly rejection:

~~~text
invalid access to map value, value_size=80 off=1036 size=4
R0 max value is outside of the allowed memory range
processed 2154 insns (limit 1000000) max_states_per_insn 1 total_states 91 peak_states 91 mark_read 0
~~~

Its captured candidate include has SHA256
d585cf1e5e2d7ae63ceb6ee5e877ca42ff2eb7c6cfae977337c5ff0867a13621,
matching F's published13,434,880 register-read observations. The captured Clang18
wrapper supplies that include through -include. The root ea2f header identity
and private include identity keep their separate provenance.
dual-isa-increment.json pins that auxiliary launch archive, include and wrapper.
C's subsequent generic CMP/read representation trial follows this frontier.

The increment retains all prior12 batch objects,53 terminal rows, the entire
failure-byte prefix,22 input pins and earlier workload/source-vector values.
It adds6 cohorts,27 requests and22 bound replies. The total stages are65 bound,
7 verifier rejections,4 specialization rejections,1 compiler rejection,
1 native-stub load error and2 loader rejections. All80 kernel-owned native
objects equal their worker copies and service SHA256 receipts. Four initial
collector schema/classification diagnostics remain in
dual-initial-collections.tar.gz; the final reader handles raw-only phases,
first-line errors, component workloads and explicit verifier-loop diagnostics,
and completes with exit0.

## ARM Tracee startup frontier

The added ARM QEMU cohort uses A's immutable
5d0d953946ffe83e2a958b8d6c6990850bb86531 archive. The generic reader consumes its
complete service batch, matches the kernel-owned native ELF to the worker copy
and service SHA256, and reconciles every published request field, raw loader
diagnostic and archive identity. Source ID174 and request1 reach fresh C
generation and BPF compilation. The kernel native-link stage requires the
sys_enter_init_tail map in tail_call_maps; its captured link plan contains
13 map names and0 tail-call-map entries:

~~~text
Error: arm64 bpf_tail_call in tracepoint__raw_syscalls__sys_enter at byte offset 0x80 uses map "sys_enter_init_tail", which is not a link-plan tail_call_maps entry
~~~

The exact linker plan SHA256 is
fbb495444404b9577c9626e50d7333e717d109beeed421a3f199e4823318f880.
The request remains loader_rejected, with0 bound replies in this cohort.
A owns the common tail-call plan/metadata repair.

The raw application JSON matches the published coverage phase objects and
151 baseline resident counter records exactly. That baseline records97,751 BPF
runs and14,263,753,616ns of aggregate BPF runtime. Its existing seven-stressor
workload exits0 after5.819921264 seconds. The post_rejit phase remains at its
startup frontier; its raw measurement is null and coverage uses an empty object.
The reader explicitly reconciles those representations. Tracee's later startup
reports detector TRC-1013/TRC-107 environment-enrichment requirements, preserved
verbatim in summary.json. Application status error, guest exit1, QEMU exit0 and
the host's hashes_unchanged=false observation retain their distinct meanings.
The source summary captures192 initial file identities. Per-request reported
identity vectors and directly checked native bytes retain separate provenance.

arm-increment.json confirms exact retention of the prior11 batches,52 request
rows, complete failure-byte prefix,19 published input pins and packet-work
observations. The collector's first source-vector lookup expected a before/after
schema; this ARM summary provides hashes_before and hashes_unchanged.
arm-initial-collection.tar.gz preserves that attempt. The final reader records
the actual available fields and exits0.

## Whole Katran execution and packet work

The later Katran213447 batch completes startup and the existing two-second pktgen
workload with app status ok: one source program, one fresh generation/compile/
binding and one native replacement. The service's bound ID35 exactly matches
the executed post_rejit counter ID35; the baseline counter ID is20.
The reader opens C's published raw result archive and reconciles its app JSON
against the coverage metadata, parses sent counts directly from pktgen stdout,
and recomputes the selected before/after counter and interface differences.

| Arm | Sent / BPF runs / XDP TX / LRU path / VIP packets | LRU miss | Receiver packets | Load-balancer TX drops | Receiver drops | XDP drops |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| JIT | 2318117 | 0 | 2318117 | 0 | 0 | 0 |
| Bound native | 2386430 | 0 | 2377743 | 5158 | 3529 | 0 |

Native receiver accounting is2386430 -2377743 =8687 =5158 +3529. Baseline receiver
accounting has zero gap. Both arms execute one BPF invocation and one XDP TX
per sent workload packet, using the LRU hit path with miss0. Their workload
configurations match exactly. Achieved packet totals differ during their
duration-driven workloads; R's existing recipe provides the performance run.
All network drops remain explicit in the observation.

The work_observations field in summary.json contains the raw-source app hash,
executed IDs, packet/action/cache counters, receiver/drop reconciliation and
duration/return values. katran-increment.json confirms retention of all prior
10 batches,51 terminal rows, the complete failure archive and16 source input pins.

## Slot-join continuation

The later Tetragon210552 batch reaches3 generated/compiled requests and2 bound
replies. Its event_wake_up_new_task request carries the same kernel/worker native
SHA256 as the earlier205401 helper-origin failure:
474212d9dc1c0972c12b8adf84af75d84b69759f3d32c4c2dbb87393adbcf5d4.
The new failure boundary is the native stub load:

~~~text
trusted-native-loader: BPF_PROG_LOAD native_lab stub: Invalid argument
processed 34919 insns (limit 1000000) max_states_per_insn 4 total_states 526 peak_states 286 mark_read 0
~~~

Its context records4,618 native bytes,37 chunks and proof_bound=1. The full
verifier stream starts with those statistics and continues with instruction
trace. The generic reader records native_stub_load_error for that explicit EINVAL
boundary. Final group/materialization diagnosis remains with C/T.

The later Tracee211016 batch reaches6 generated/compiled requests and5 bound
replies, including sys_enter_submit. sys_exit_submit reaches this explicit
verifier diagnostic at BPF instruction5674:

~~~text
invalid access to map value, value_size=80 off=1036 size=4
R0 max value is outside of the allowed memory range
processed 2147 insns (limit 1000000) max_states_per_insn 1 total_states 91 peak_states 91 mark_read 0
~~~

The raw stream shows a scalar index masked to1020, plus a16-byte displacement,
followed by a four-byte read from the80-byte readonly object. All diagnostics and
commands are retained in failures.jsonl.gz. C owns generic index/range
preservation repair. These are batch runtime observations; universal simulator,
token and native-link laws remain with V/T.

## Earlier batch diagnostics

OTel192310 reaches its exploration limit:

~~~text
BPF program is too large. Processed 1000001 insn
processed 1000001 insns (limit 1000000) max_states_per_insn 31 total_states 64869 peak_states 2495 mark_read 0
~~~

Katran201524 retains the exact pointer diagnostic:

~~~text
R9 pointer arithmetic on map_value_or_null prohibited, null-check it first
processed 3013 insns (limit 1000000) max_states_per_insn 2 total_states 111 peak_states 111 mark_read 0
~~~

Cilium201146 generates C and its compiler reports the undeclared
cilium_percpu_trace_id identifier. The earlier Tetragon/Tracee helper-origin
diagnostics remain in the same archive with their full commands and source IDs.

The R Tetragon204105 timing attempt has metadata/result status error,3 requested
samples and180-second workloads. Its selected entry extent is1362 BPF instructions
or10,896 bytes. The actual selected request reaches the original helper-origin
diagnostic at0x9ab. The timing context and raw shim/metadata/result captures remain
separate from the later functional slot-join cohorts.

## Source identity and reproduction

The first six published cohorts use immutable Git blobs at
afc178f46e725fe96f85694d76fcf4c45c842914. The new Tetragon/Tracee slot-join
metadata and service archives use21cf7278605fc3b4b6468b3bec639badec9ab0fb.
The later Katran metadata, service and raw result archive use
3993aa884362093ba6821db4e97cdded89504d99. The ARM coverage, raw run and source
summary use5d0d953946ffe83e2a958b8d6c6990850bb86531. The five additional ARM metadata/raw/summary sets use
57db4da4387f19e86f79eae6dfa95bfaf024ee3d; the BCC raw archive retains its original
5d6d067cfd55a627d7f367054decc72e09bb7e51 identity. The later x86 Tracee metadata
and service archive usef41ccb6b773d0b24273b8145d758680f9b3f8793.
The Tetragon221545 metadata, service, raw result and published observations
use4adeb4807bb26eddd57324799eb79d9dc0118d56. The later Tetragon223215 metadata, service, raw result and observations use
071476a17f6526ef706404743ca19049201ed5e1. Forty-seven published metadata/archive
inputs have individual Git/hash/size pins in summary.json. Two additional captured Tetragon service epochs and the R timing
inputs retain their exact five-file captured-inputs.tar.gz and manifest.

recorded-source-identities.json groups literal service-reported file identities.
Those vectors record reported file hashes; loaded Python module identity remains
a separate execution-provenance boundary. Kernel/worker/receipt byte identity is
checked directly from every archived request.

join-increment.json confirms that the prior8 batches,42 terminal rows,7 failure
records,12 published input pins and earlier identity vectors retain their values.
The new increment adds9 requests and7 bound replies. The initial join collection
classified Tetragon's native-stub EINVAL under the broad BPF verifier bucket; its
raw collection output is retained. The final reader distinguishes that actual
load boundary and reconciles every available published count.

Run the generic reader from /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/application-batches/collect.py
~~~

The reader opens immutable published blobs and its captured input archive, then
writes batch tables and diagnostic streams in this directory. Service archives
support service/, corpus/ and run/ roots plus nested single-archive wrappers.
Original application requests, workloads, source trees and runtime outcomes stay
in their recorded epochs. Final collection exits0.

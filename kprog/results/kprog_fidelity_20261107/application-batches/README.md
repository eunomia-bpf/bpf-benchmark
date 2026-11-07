# Application service batch observations

One generic archive reader reconciles11 closed service batches across all six
application names. All52 terminal requests preserve byte equality between the
kernel-owned native object, the worker's received copy and the service receipt's
SHA256. Kernel source IDs match the service records. The batches contain48
generated sources,47 compiled objects and43 successful bound replies.

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

The11 rows retain distinct source, image and boot epochs. Counts describe observed
load instances; repeated native objects and repeated program IDs across boots stay
in their original batches. Whole application completion and duration-driven
workload measurements follow the recorded startup frontiers.

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
3993aa884362093ba6821db4e97cdded89504d99. Nineteen published metadata/archive
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
support both service/ and corpus/ roots plus nested single-archive wrappers.
Original application requests, workloads, source trees and runtime outcomes stay
in their recorded epochs. Final collection exits0.

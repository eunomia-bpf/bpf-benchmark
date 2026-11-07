# Native resource and inline-memory batch observations

One offline collector reconciles T's published generic memory-binding regression
at 697bea0ea4326472119c137b306d298621a9a218. It reads all three retained service
batches, including the two earlier producer failures. All eight terminal requests
have equal kernel-owned native bytes, worker copy bytes and receipt SHA256.
Kernel source IDs and every successful load reply agree with their service
records. Archive membership and terminal records match exactly in each batch.

| Service batch suffix | Requests | Bound | Producer refusal | Verifier refusal |
| --- | ---: | ---: | ---: | ---: |
| 1794086879500039835 | 2 | 1 | 1 | 0 |
| 1794086994366839654 | 2 | 1 | 1 | 0 |
| 1794087098395487377 | 4 | 3 | 0 | 1 |

The three batches retain distinct execution epochs and their original native
inputs. Counts describe requests and preserve repeated IDs across those epochs.
terminal-outcomes.tsv records each request, byte identity, stage and generated
copy/fill count. failures.jsonl.gz preserves the complete producer/verifier
diagnostics and commands from all three failed requests.

## Final memory and transport outcomes

The final batch's three native executions use fresh generation and binding.
Their client IDs, service IDs, native object hashes, generated macro counts and
published terminal receipts agree. Each returned 2 with prebuilt_proof=false.

| Copy/fill bytes | Source ID | Native ID | Observed return |
| ---: | ---: | ---: | ---: |
| 8 | 6 | 11 | 2 |
| 32 | 14 | 19 | 2 |
| 96 | 22 | 27 | 2 |

The final unsafe-address control generates a verifier refusal before native
execution. The exact diagnostic is:

~~~text
46: (73) *(u8 *)(r2 +0) = r9
R2 invalid mem access 'scalar'
processed 47 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
~~~

The final batch therefore has three successful native executions, one unsafe
verifier refusal and zero unsafe accepts. The transport command has 18 individually labeled outcomes: 16 expected
refusals and two PASS lines. Its final suite summary contributes one further
PASS line. The source metadata records all 19 outcome lines together; summary.json
keeps that reported count alongside the 18 individual outcomes and one summary.
The collector confirms the closing puts statement in the pinned C source.
Exact labels, errno values and record kinds are in transport-outcomes.tsv.

## Kernel-owned native map capabilities

The same offline reader now reconciles T's separate c94fbff015cfcf2a6b253a26122e9991036c558b
x86 KVM2vCPU/2GiB transport cohort. Its34 output lines contain33 named outcomes and one closing
suite summary. The complete old19-line cohort appears in the new cohort with
the same labels, outcomes, errno values and ordering. Fifteen additional named
outcomes cover native-resource submission, descriptor mutation, pinned object
identity, reference lifetime and rollback.

| Observed operation | Count |
| --- | ---: |
| Protocol refusals | 28 |
| Map-ID lifetime lookups returning -ENOENT | 2 |
| Positive protocol observations | 3 |
| Closing suite summary | 1 |

The source metadata's30 REJECTED lines include the28 protocol refusals and
the two lifetime lookups. resource-transport-outcomes.tsv keeps every original
label/outcome/errno and records operation_kind alongside record_kind.
Both lifetime lookups return libbpf_result=-2 and errno=2: one after rollback
of partial submission, duplicate-identity and copyback cases; one after request
completion and submitting-file close. The test completes that request with
status-EINVAL. Its separate object-ID query and map-shape assertions execute
before the corresponding PASS lines.

The positive resource observation checks a PERCPU_ARRAY with key size4,
value size8 and max_entries3 after the application mutates the submitted FD
array and closes its descriptors. Querying an omitted valid object receives
ENOENT, while the pinned object's ID remains resolvable. The source outer map
and inner template retain their actual shape checks. These are transport
submission/query/completion and reference-lifetime observations. The earlier
memory cohort above supplies its three actual native copy/fill executions.

The captured wire source defines SUBMIT_RESOURCES at ioctl group N,
number0x77. Compile-time source assertions retain the64-byte base request
and80-byte resource submission. The raw transport log equals the decompressed
published log exactly, and its recorded outer command exits0.

The resource result has its own18 immutable input pins: metadata, raw/log
archives and15 published source files. All15 archived source identities agree
with their recorded input manifest; the common group header retains its
documented two extra blank lines and exact observed/published hashes.
The archived module, test executable and compiler-command file match their
three published artifact digests:

- Module:57e6f868da0768526965fdd0a789c4d7080358efe4439edb1f0e32c5136ceb9f.
- Test executable:27c1c0f97f1b4918322b92b637cc01d182941e4e9c786237e930505f20d73dfd.
- Compiler command:b941864e215b29ecc77d09469481aecb032cd55fce0621382a503e1a88c020a5.

Four further kernel/configuration/libbpf identities remain explicit metadata
pins. summary.json separates these recorded identities from the artifact bytes
available in the archive. Its resource_transport_batch holds the new cohort;
the original memory/source/input fields retain their complete values.
resource-increment.json confirms exact retention of the three earlier service
batches,17 old input pins, terminal/transport tables and full failure archive.
C/A own coherent caller/service/module adoption and actual application runs;
V/T continue the universal resource, compiler and binding laws.

## AArch64 resource and fresh-service observations

The same reader consumes A's immutable publication
340a4ea5e07c38d415031c51aca057b57f62d955. Its portable transport cohort runs
under full-system AArch64 QEMU with two vCPUs, 2 GiB and host CPUs16-19.
All34 labels, outcomes, errno values and ordering equal the x86 resource
cohort above. arm-resource-transport-outcomes.tsv keeps the original fields
and ISA label. The28 protocol refusals, two map-ID lifetime lookups, three
positive protocol observations and one closing summary retain their distinct
operation kinds. Both lifetime lookups return libbpf_result=-2 and errno=2.
The archived transport result and guest status exit0.

A separate registered-service control in the same publication runs with two
vCPUs, 2 GiB and host CPUs8-11. Its source program3 binds as native program9
after fresh generation and BPF compilation; the client returns2 with
prebuilt_proof=false. Kernel-owned native bytes, worker-copy bytes, service
receipt and the actual service input native SHA agree:

~~~text
29c718c0dd9c592fb66ebdfe5a4f59b29bdf1bd53818f53771c13795f95bba4e
~~~

The raw client JSON equals its corresponding guest fields. Request membership,
entry, kernel source ID, successful loader reply and every artifact hash from
A's identity audit agree with the nested raw archive. The two actual generation
commands return0. Source and bound IDs equal3 and9 throughout. Kernel facts
record an empty maps vector for this scalar control. Native-only map-capability
and reference-lifetime observations come from the portable transport cohort;
the separate scalar control supplies an actual execution through the adopted
module, caller and registered service. C/A continue whole-application replay.

The archive supplies41 captured source files and six AArch64 ELF artifacts.
All41 source hashes equal the frozen build manifest. Forty corresponding Git
sources are available;39 match byte for byte, and the common group header
retains its documented two additional empty lines with equal remaining lines.
The kernel Module.symvers bytes are retained in the source archive. Four further
request-generation sources are checked against their published Git bytes.
The49 immutable input pins include these source and result identities.

The module digest is
0fd8117fb76b2301ecdde335a0731c549a977f492eb88914f458212a2649bec0,
the caller DSO digest is
25a55681c481afcd85b6098b67b6608b35de0700dc75fca1a41dc038a8e57994,
and the transport executable digest is
53a409e4ff7bbed3c9b8da206cd0ed00df8677a45baf1051120f2078a9b76ae8.
All six archived ELF machine fields identify AArch64. The packaged baseline
fixture retains digest de7821296054060c79cf4ff821a0939b63e8b01b8efb75e8c5b68deb987dfe2c;
the actual service mount selects the29c718 control above. Both identities
remain explicit. The module and caller hashes join the actual service input
vector, whose157 paths remain recorded metadata; eight overlapping paths agree
with the request's nine-field source/binary vector, and archived caller-source
bytes cover its remaining field.

arm-resource-increment.json records exact retention of every prior summary
field, all four existing outcome/failure files and the prior collection log.
The collector uses immutable published input blobs and exits0. Its first
schema pass reached a caller-source field carried in the source archive;
the completed join compares overlapping service fields and the full archived
source vector. Original source and diagnostic are retained in F's
arm-resource-review-initial.tar.gz. Runtime source, guest inputs, workload
bytes and universal V/T theorem interfaces retain their captured epochs.

## Source and binary identities

The collector verifies 13 production source SHA values against their published
Git blobs, plus the metadata, raw archive, raw log and existing shared service
archive parser: 17 pinned inputs in summary.json. It reuses the parser from the
published application-batch reader at 919dd020.

Ten tested artifacts retain their raw archive hashes. The captured common
group header includes the two documented extra blank lines; its remaining
lines match the publication. The exact observed and published hashes remain
in source_observations. The captured module SHA is
c3842be1caa33ad9f2b9516f33bb6742dc96f3662dda5f1ce106bc68fa6e56a8.

Each final request's nine-field source/binary vector equals the published
runtime-source record, and all four final vectors agree. These are literal
service-reported file identities. Kernel/worker native byte identity and the
client/load reply identities are checked directly from the original artifacts.

This finite generic mechanism regression supports the shared memcpy/memset
target-binding correction. V/T develop universal memory, compiler, token and
binding laws; C owns complete Tetragon application replay. Earlier negative
suite epochs retain their own source pins and counts.

## Reproduction

Run from /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/negative/inline-memory-batches/collect.py
~~~

The collector reads immutable published blobs and writes these batch observations.
It preserves original application/runtime inputs and launches zero guests.
The initial collector reached its control-count assertion after also reading
the enclosing memory-suite PASS summary. collection-attempt.tar.gz retains that
source and diagnostic. The final collector reads the exact transport-command
segment and exits 0. Original runtime and diagnostic bytes retain their values.

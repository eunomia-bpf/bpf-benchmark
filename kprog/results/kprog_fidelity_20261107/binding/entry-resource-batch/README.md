# Shared native entry-resource query batch

The unchanged published native-link resources mechanism executes609 host
metadata queries with609 complete outputs matching C/A's archived records.
Four queries use x86-64 native ELF inputs;605 use AArch64 native ELF inputs
from all six packaged application manifests. The host binary is the original
48e054b1 build. The batch command exits0, with zero query errors. This cohort
records resource-name discovery and paired component/source identities.

| ARM application | Packaged selectors | Unique entry queries | Matching outputs | Resource symbol range |
| --- | ---: | ---: | ---: | ---: |
| bcc | 32 | 32 | 32 | 0–19 |
| otelcol-ebpf-profiler | 36 | 38 | 38 | 0–25 |
| cilium | 98 | 89 | 89 | 0–42 |
| tetragon | 247 | 250 | 250 | 0–63 |
| katran | 12 | 12 | 12 | 0–14 |
| tracee | 123 | 184 | 184 | 0–27 |

The six manifests contain548 selectors. Prefix-expanded native function names
produce605 unique object-path/entry pairs. The collector independently
enumerates defined ELF functions and checks each manifest's complete entry set
against the published query batch. Identical native bytes used by distinct
paths keep their original path/entry identities. These counts describe
packaged input selectors and metadata queries. Application startup, generated
verifier programs, accepted loads and running workload counters retain their
separate application-batch records.

| x86 input | Exact selected entry | Matching resource symbols |
| --- | --- | ---: |
| Tracee | tracepoint__raw_syscalls__sys_enter | 2 |
| Cilium | cil_xdp_entry | 6 |
| Tetragon | event_exit_disassociate_ctty | 8 |
| OTel | read_task_struct | 2 |

queries.tsv contains every selected entry, native SHA, output symbols,
exit status and stdout/stderr digests. query.log.gz retains every actual
command, complete stdout/stderr and published expected symbol list. A separate
reconciliation checks all609 log/table pairs. The x86 Tracee output contains
sys_32_to_64_map and sys_enter_init_tail; the Cilium output includes the
previously missing cilium_percpu_trace_id resource. Complete names remain in
the table and summary.

## Frozen inputs and component identities

native-inputs.tar.gz contains138 native input paths represented by89 unique
ELF byte strings, plus the six original manifests. The native bytes total
110,114,208; the complete compressed bundle is33,753,909 bytes, SHA256
d62c16f73c51fa7b9c3395e3c7ce3d11ac0e2faaa7e9a855c307a27b69a60e7b.
Native objects share content-addressed archive members while retaining all
original path mappings. Every captured native and manifest hash matches the
published source batch. Subsequent replay reads this fixed bundle.

The reader consumes C's c664565ccb449e88d3580ebda1e3c079b71d8c53 and A's
bca4d587e9ca84a2d55043e2c30a95c02438e9cd publications through immutable Git
blobs. The original47 input pins retain their commit/path/hash/length identities;
the registered-service extension below adds11.
All21 frozen source files in A's build archive match both publications.
C's archived main.candidate.rs and native_loader.candidate.cpp equal the
corresponding frozen A sources. The shared mechanism follows selected-entry
reachable functions, code/data relocations and pointer-table references.

The actual archived host binary digest is
48e054b1b0a0099b1348bb6240af909ff4188ccb0faaf1734231443970286864,
with ELF machine x86-64. Five archived ARM artifacts match their published
digests and AArch64 ELF machine fields: caller DSO, trusted loader, service
client, native fixture and native linker. The actual ARM linker digest is
e183a7ea880f06e9584b27f41ff2ed51bd9d606e6cdc9f740a9f80da6f7758f9.
The original x86 caller DSO/loader digests remain published metadata in
summary.json. C's retained89 native-link tests and12 service tests, plus
A's three successful build/query stages, retain their original archived
logs and exit statuses. This replay executes the609 metadata queries.

## Archived ARM execution with the paired scoped-resource components

The reader also reconciles A's741f96936b4e1840457bd6f40afa04979950eebf
registered-service control. Its original QEMU run uses two vCPUs,2 GiB and
host CPUs8-11. The guest and QEMU exit0, the host report is true, and the native
client returns2 with prebuilt_proof=false. Source program3 binds as native8
after fresh generation and BPF compilation. The captured execution uses the
paired entry-resource loader/linker from the build/query cohort above.

Kernel-owned native bytes, the worker copy, service receipt, actual selected
fixture and the paired build's native ELF agree on SHA256
de7821296054060c79cf4ff821a0939b63e8b01b8efb75e8c5b68deb987dfe2c.
The client JSON equals the corresponding guest fields. The raw guest receipt,
service event, kernel source ID, successful load reply, selected entry and
published coverage record agree. Six published generated-artifact digests
match the actual nested archive bytes. Both original generation/compilation
commands return0.

The actual runtime identities join the archived paired build:

- Trusted worker loader:9b328444f14d4e4db613a47938903d239b4d7378260df3e69e5054435b247aab.
- Application service client:ac4e84709efbe5f93b868af4e7ec5696ee4f488d22fdd8248a81989e72f63d50.
- Native linker:e183a7ea880f06e9584b27f41ff2ed51bd9d606e6cdc9f740a9f80da6f7758f9.
- Resource module:0fd8117fb76b2301ecdde335a0731c549a977f492eb88914f458212a2649bec0.

The module's actual AArch64 ELF bytes are checked against A's earlier
340a4ea5e07c38d415031c51aca057b57f62d955 resource-build archive. The paired
caller DSO retains its archived build identityb4dfe444. The run's157 watched
path hashes agree before/after. Its nine-field request source/binary vector
has eight matching watched paths; the remaining caller C++ source matches the
frozen build archive. All seven source entries are checked against archived or
published bytes. summary.json preserves these fields and the original runtime
command under registered_service_control.

Kernel facts and generated metadata record maps=[] for this scalar fixture.
Its retained native execution count is one. The existing transport cohort
supplies map-object, query and reference-lifetime observations; the609 host
queries above supply resource-name closure observations. Each domain retains
its original inputs and counts. C/A own complete application execution; V/T
continue universal simulator, token, compiler, ABI, native-link and binding laws.

The combined collector exits0. All609 table rows and the33,753,909-byte native
bundle retain their exact published bytes. Every prior query-log record has
equal inputs, flags, output and status after normalization of its temporary
directory paths. The47 earlier input pins and original query counts, source/binary identities,
input bundle and application distributions retain their values. The refreshed
query-log digest records this replay\x27s actual command paths. Eleven further
input pins bring the total to58.
collection-status.json records these retention checks and keeps the host
query count separate from the archived ARM native execution count.

## Relation to kernel authorization and application execution

The backend is x86-64 host resource-name discovery over both ISA ELF formats.
Resource symbol lists can include helper and data identities. The caller
intersects discovered names with authenticated source-map identities, obtains
live FDs and deduplicates actual map objects before kernel submission. Kernel
resource counts and object authorization retain their generic checks. Symbol
counts in this table describe named relocation closure.

The earlier portable transport cohort in
../../negative/inline-memory-batches/ records actual capsule/resource-query
and reference-lifetime controls. C/A own coherent whole-application execution
with the paired caller/linker. The application ledger records fresh generation,
compilation, binding and workload observations. V/T own universal simulator,
token, compiler, ABI, native-link and binding laws. These batch observations
support the component behavior and input-identity part of that argument.

## Reproduction

From /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/binding/entry-resource-batch/Makefile replay
~~~

The Make target reads the existing fixed native bundle and immutable published
source/binary archives, selects the captured host executable and runs the same
resource-query interface for every entry. Each CLI call writes its JSON result
to the captured stdout pipe. A temporary native input file and host executable
live in F's Workspace lane for the duration of replay. Existing shared kernels,
modules, runtime images, applications and workloads retain their source epochs.

Initial setup resolved C's abbreviated syscall-entry label to the full ELF
tracepoint symbol recorded above. The distinct sys_enter_init entry produced
its own six-resource output during that setup. Original source, diagnostics
and that raw output remain in F/entry-resource-batch-initial.tar.gz.
collection-status.json records the final Make exit0 and the complete batch
identities. run.log.gz preserves the final command output.

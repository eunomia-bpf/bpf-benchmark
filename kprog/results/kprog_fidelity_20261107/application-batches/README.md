# Captured application-service batch outcomes

One generic archive reader checks eight closed batches spanning BCC, OTel,
Cilium, Tetragon, Katran and Tracee. All 42 terminal request archives have equal
kernel-owned native bytes, worker input bytes and service native SHA receipts.
Each source program ID agrees with its kernel facts. All 35 successful load
replies agree with their request ID, assigned native program ID and service
status. Request IDs and terminal archives reconcile within every batch.

| Application | Captured batch | Requests | Generated | Compiled | Bound | Specializer rejection | Compiler rejection | Verifier rejection |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | functional_153239 | 25 | 25 | 25 | 25 | 0 | 0 | 0 |
| otel | functional_192310 | 3 | 3 | 3 | 2 | 0 | 0 | 1 |
| cilium | functional_201146 | 1 | 1 | 0 | 0 | 0 | 1 | 0 |
| tetragon | functional_201956 | 3 | 2 | 2 | 2 | 1 | 0 | 0 |
| katran | functional_201524 | 1 | 1 | 1 | 0 | 0 | 0 | 1 |
| tracee | functional_203243 | 3 | 2 | 2 | 2 | 1 | 0 | 0 |
| tetragon | functional_205401 | 3 | 2 | 2 | 2 | 1 | 0 | 0 |
| tetragon | timing_204105 | 3 | 2 | 2 | 2 | 1 | 0 | 0 |

The total is 35 bound requests, four specializer rejections, one compiler
rejection and two verifier rejections. These counts cover eight separate
runtime epochs, including repeated Tetragon startup requests. Their input
identities and batch boundaries stay explicit in terminal-requests.tsv.
All reported generation/compilation/binding counts available in the published
batch metadata agree with archive contents.

## Observed failure stages

- OTel native unwinder: the kernel log reports
  ~~~text
  BPF program is too large. Processed 1000001 insn
  processed 1000001 insns (limit 1000000) max_states_per_insn 31 total_states 64869 peak_states 2495 mark_read 0
  ~~~
- Katran: the kernel log reports
  ~~~text
  R9 pointer arithmetic on map_value_or_null prohibited, null-check it first
  processed 3013 insns (limit 1000000) max_states_per_insn 2 total_states 111 peak_states 111 mark_read 0
  ~~~
- Cilium compilation reports
  ~~~text
  error: use of undeclared identifier 'cilium_percpu_trace_id'
  ~~~
- Tetragon and Tracee specializer failures retain their exact helper
  stack-origin diagnostics and full command/error records in failures.jsonl.gz.

These are recorded application/service outcomes. Universal simulator,
specialization, native-link and binding laws carry the safety argument.
Application completion and matching-work timing continue through the observed
failure classes with their runtime owners.

## Tetragon timing-stage diagnosis

R's 204105 timing batch captures three service requests: two bound replies and
a third request reaching the generator's helper stack-origin analysis. Its
shim records 1,362 BPF instructions, giving an actual 10,896-byte extent.
The kernel-owned native input for source program 337 and its worker copy match
SHA 474212d9dc1c0972c12b8adf84af75d84b69759f3d32c4c2dbb87393adbcf5d4.
The terminal entry and exact diagnostic are:

~~~text
event_wake_up_new_task
native helper source stack relation unresolved at 0x9ab: call   rax
~~~

The 205401 functional batch reaches the same entry and helper-origin
diagnostic. The timing batch retains metadata/result status error, three
requested samples and a 180-second workload setting. This pins the observed
binding frontier and the next generic source-analysis repair. C/V/T/R received
the exact archive, kernel/worker identities and failure stage in coordination.

## Inputs and reproduction

The six published functional rows use twelve metadata/service artifacts from
Git afc178f46e725fe96f85694d76fcf4c45c842914. Their exact hashes and original
paths appear in summary.json. captured-inputs.tar.gz preserves the two later
closed service archives plus R's metadata, result and shim log. Its manifest
records original paths, byte counts, hashes and capture time.

The reader accepts both service/ and corpus/ archive roots and single-archive
wrappers. It reconciles every terminal log row with exactly one request archive,
checks the kernel/worker input identity and loader reply, records generated
source/object presence and classifies the observed terminal stage from command
returns and verifier diagnostics. failures.jsonl.gz preserves the full original
diagnostics, command records and verifier statistics. recorded-source-identities.json
retains the service's reported source identity vectors.

~~~sh
cd /workspaces/repository
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/application-batches/collect.py
~~~

collection-status.json and collection.log.gz record the successful offline
collection. The reader operates on captured batches and writes these outcome
tables. Original application source, native objects, workload runs, active
guests and the separate LEA fidelity build retain their existing state.

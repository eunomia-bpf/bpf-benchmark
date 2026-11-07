# Standard-service micro batch outcomes

The shared reader in kprog/fidelity/audit_micro_batch.py reads complete
micro result and registered-service archives. The same routine processes all
benchmarks, samples and requests in each supplied cohort.

| Published cohort | Benchmarks | Exact result/return samples | Bound requests | Recorded compiler errors | Recorded loader rejects |
| --- | ---: | ---: | ---: | ---: | ---: |
| Earlier pure, 5004364f | 29 | 55 | 26 | 1 | 2 |
| Narrow-load pure, d32075a38 | 29 | 58 | 29 | 0 | 0 |
| Helper/map stage2, aaf7b9dc4 | 13 | 39 | 26 | 0 | 0 |
| Adopted producer pure, 9b1a92f5a | 29 | 58 | 29 | 0 | 0 |

The d320 narrow-load pure cohort has 29 JIT samples and 29 bound-native samples. Every observed
64-bit result and return value agrees with the configured expectation. Its
29 terminal receipts have distinct source IDs and distinct bound IDs,
successful BPF compiler commands, generated objects and matching loader
receipts. All 29 kernel-owned native inputs match both the worker's native
copy and the original baseline native bytes.

The source identities in every d320 request retain simulator header
47fb5565. The raw launch manifest and captured generated-memory header both
match 3ba4bc78 from c0b8e9cfa. This connects the completed batch to the
published RORX and narrow-load mechanisms. The kernel/module and executable
identities remain recorded in each cohort's launch hashes. Each cohort has
one recorded request-source identity set.

The helper/map batch has 13 samples for each of kernel, native_kernel and
native_proof. Both native labels use the registered generation-bound service.
Its 26 requests preserve kernel-to-worker native identity. The earlier pure
batch preserves all 29 terminal outcomes, including its compiler signal
and two exact loader errors. The batch tables retain these four cohorts'
separate source epochs and workload denominators.

This is an offline reanalysis of existing execution records. Functional
observations come from one sample and one repeat per runtime. Timing follows
R's existing requests. Universal safety evidence follows the generic
per-operation, per-token, binding and native-link theorems developed by V/T.
The common runtime mechanism continues to generate and verify each submitted
native input through the kernel-owned request path.

## Adopted producer epoch

The completed215009_047184 batch uses C's adopted wrapping-RSP and tagged-write
producer. The unchanged shared reader independently confirms29 fresh generated/
compiled/bound requests,29 distinct source IDs and29 distinct bound IDs.
Every kernel native input equals its worker copy, service SHA256 and retained
baseline native bytes. All58 actual sample objects and29 terminal service rows
also equal the published9b1a92f5a runtime metadata, with request/source/bound IDs
reconciled against the archive-derived receipts.

The29 JIT and29 native_proof samples match their configured full64-bit result
and return action. Twenty-three native results exceed0xffffffff, and configured
native actions include0,1 and2. The report preserves each benchmark's exact
integer result/action. This adds58 samples and29 requests to the retained
three-cohort observation set:210 matching samples and113 terminal requests
across four distinct epochs, with110 bound replies and the earlier three
recorded errors preserved.

The captured simulator header is6b3f31731d9d127a36183e3e35cd6b39335d8b5865649a8282fc503a7be0dc11;
the captured generated register-write header is
cf27e323c885cdf8258974a8800907af2f6ee56093d7721822b9e75360e72994.
All155 captured source snapshots match their corresponding launch hashes.
The159-entry launch vector additionally records the kernel image, module,
native-link executable and trusted loader identities. The image identity is
sha256:a13312372b9b1d7c8b86929da098ddbb177aef120941ec70b7fafa2468110219.
The batch records completed metadata, driver exit0 and source_drift=[].

pure-wrapping.json contains all58 values/actions,29 receipts, launch/source pins
and literal service-reported identity vectors. wrapping-increment.json records
the metadata hash, exact raw-to-published joins, baseline-input correspondence,
and the retained byte identities of all three earlier reports. Source file
vectors retain their literal provenance; direct native byte equality is checked
from each archived request. The registered service's ready record carries arch1
and the x86 kernel endpoint; its application command exits0 and teardown records
service_returncode=-15.

This is offline analysis of C's completed common-service execution. Existing
workloads, runtime sources, shared reader and warm build artifacts retain their
bytes. Universal simulator, token, compiler and binding laws continue through V/T;
R's existing timing recipe remains the performance path.

## Recompute

The commands in commands.json invoke the same reader with each cohort's raw
archive, service archive, suite and publication. From the repository root,
the adopted producer batch command is:

~~~sh
taskset -c 16-19 python3 kprog/fidelity/audit_micro_batch.py \
  --raw corpus/results/kprog_app_coverage_20261107/micro-wrapping-epoch/runtime-raw.tar.gz \
  --service corpus/results/kprog_app_coverage_20261107/micro-wrapping-epoch/runtime-service.tar.gz \
  --suite micro/config/micro_pure_jit.yaml \
  --publication 9b1a92f5a3b76993c19d844152a7e6bb89a295ab \
  --original-native-archive corpus/results/kprog_app_coverage_20261107/micro-shared-elf/validation-raw.tar.gz \
  --out /tmp/wrapping-micro-batch.json
~~~

The reader verifies the supplied raw archives and suite against the named
publication, reads every nested terminal request, checks exact sample values,
native hashes and compiler/load receipts, and retains launch hashes plus
captured source snapshot identities. It reads archives in memory and writes
one cohort report at the requested output path. The original native archive
is an optional baseline identity source; its committed 5004364f bytes were
also checked in this review.

pure-current.json and stage2.json contain the corresponding cohort reports.
pure-earlier.json.gz preserves the earlier report, including the complete
recorded loader stderr, in compact form. analysis.log records all four
completed invocations. Original raw archives remain at the source-publication
paths in the reports; the existing warm execution artifacts remain available.

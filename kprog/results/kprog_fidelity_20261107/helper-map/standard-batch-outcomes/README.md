# Standard-service micro batch outcomes

The shared reader in kprog/fidelity/audit_micro_batch.py reads complete
micro result and registered-service archives. The same routine processes all
benchmarks, samples and requests in each supplied cohort.

| Published cohort | Benchmarks | Exact result/return samples | Bound requests | Recorded compiler errors | Recorded loader rejects |
| --- | ---: | ---: | ---: | ---: | ---: |
| Earlier pure, 5004364f | 29 | 55 | 26 | 1 | 2 |
| Current pure, d32075a38 | 29 | 58 | 29 | 0 | 0 |
| Helper/map stage2, aaf7b9dc4 | 13 | 39 | 26 | 0 | 0 |

Current pure has 29 JIT samples and 29 bound-native samples. Every observed
64-bit result and return value agrees with the configured expectation. Its
29 terminal receipts have distinct source IDs and distinct bound IDs,
successful BPF compiler commands, generated objects and matching loader
receipts. All 29 kernel-owned native inputs match both the worker's native
copy and the original baseline native bytes.

The source identities in every current request retain simulator header
47fb5565. The raw launch manifest and captured generated-memory header both
match 3ba4bc78 from c0b8e9cfa. This connects the completed batch to the
published RORX and narrow-load mechanisms. The kernel/module and executable
identities remain recorded in each cohort's launch hashes. Each cohort has
one recorded request-source identity set.

The helper/map batch has 13 samples for each of kernel, native_kernel and
native_proof. Both native labels use the registered generation-bound service.
Its 26 requests preserve kernel-to-worker native identity. The earlier pure
batch preserves all 29 terminal outcomes, including its compiler signal
and two exact loader errors. The batch tables retain these three cohorts'
separate source epochs and workload denominators.

This is an offline reanalysis of existing execution records. Functional
observations come from one sample and one repeat per runtime. Timing follows
R's existing requests. Universal safety evidence follows the generic
per-operation, per-token, binding and native-link theorems developed by V/T.
The common runtime mechanism continues to generate and verify each submitted
native input through the kernel-owned request path.

## Recompute

The commands in commands.json invoke the same reader with each cohort's raw
archive, service archive, suite and publication. From the repository root,
the current batch command is:

~~~sh
python3 kprog/fidelity/audit_micro_batch.py \
  --raw corpus/results/kprog_app_coverage_20261107/micro-load-width/runtime-raw.tar.gz \
  --service corpus/results/kprog_app_coverage_20261107/micro-load-width/runtime-service.tar.gz \
  --suite micro/config/micro_pure_jit.yaml \
  --publication d32075a3824c56eb7e39bd7108fa0de5f2084172 \
  --original-native-archive corpus/results/kprog_app_coverage_20261107/micro-shared-elf/validation-raw.tar.gz \
  --out /tmp/current-micro-batch.json
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
recorded loader stderr, in compact form. analysis.log records all three
completed invocations. Original raw archives remain at the source-publication
paths in the reports; the existing warm execution artifacts remain available.

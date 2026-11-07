# Independent safety replay of the published ARM canonical worker

Same34 fixture native objects and unchanged producer:4 valid controls and30
LOADONLY negatives. The current canonical header/ABI/generator from b89015df9
and current native-link are used by the registered common service. The legacy
producer linker path and canonical service linker have identical ELF SHA256
f9086a5d08126aabfcaa824a6bf93aad9bc47c2b665d3f44b8757ceaaa3f3456.
No fixtures, producer, kernel, module, image or workload are rebuilt/changed.
The existing readonly-root transport is imported; F changes only its own
output directory and local subprocess binding to CPUs20-23 (2vCPU/2GiB).
A's transport source, guest and previous F archives remain untouched.
The run completed; native negatives never reached TEST_RUN.


## Completed canonical-worker replay

The detached driver, QEMU and guest each returned **0**. All **34** cases
completed: **4** controls ran successfully through both kernel and fresh
bound-native paths (result 0, return value 2); **30** negative cases were
rejected before native execution: **16** by the verifier, **13** during
specialization and **1** by the loader. Unsafe accepted: **0**; unsafe native
executions: **0**. results.tsv records the rejection stage and exact message
for every case; outcomes.json.gz retains the complete observations.

All 34 original fixture/native hashes match the bytes retained by the kernel
and the generated request objects. Every request has the same captured
service-source identity set. The raw unique request archive SHA256 is
7268e25f495a3b9e0a2cfe73e7685cd00adce4e6eb3168d5f56c80cdf82fcb71.
input-sources.tar.gz retains the exact original 154-file input snapshot,
including the imported ARM transport and this lane's replay wrapper.

Actual transport input hashes remained unchanged. The additional broad
host-source comparison reports A's later change to
corpus/results/kprog_arm64_app_coverage_20261106/trusted_service_arm64.py.
A announced this BCC-only error-propagation/timeout change while this job was
running. F had already imported the module, redirected its __file__ to the
F replay wrapper, and supplied its own guest dispatch. The captured original
transport source and the nonempty extra-source drift list are both retained;
this report does not claim every surrounding source file stayed unchanged.

Command used (2 guest CPUs, 2 GiB, host CPUs 20-23):

~~~sh
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile qemu RUN_OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/canonical-worker
~~~

This checks the published canonical ARM worker/header/ABI/generator with the
unchanged existing kernel. It does **not** test the private exclusive-loop
convergence kernel candidate or prove bounded termination of marker-bearing
retry cycles. The old return-linker failure/prefix records remain historical
evidence; they are not substituted for these fresh 34 request receipts.

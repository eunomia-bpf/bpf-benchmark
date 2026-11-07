# Actual BCC runtime v12 (QEMU functional run)

Application status: **error**. Baseline has23 resident program counter rows;
the native workload never starts. Six startup loads are replaced with
prebuilt generation-bound proofs; four failures are logged before the runner
aborts when opensnoop exits. Eight startup requests remain unfinished; they
are preserved, not classified as accepted or excluded.

Concrete rejection classes: vfsstat exclusive retry loop is not verifier
bounded; capable accesses modified context pointer at offset16; tcplife and
opensnoop proof stack writes exceed512 bytes (-520 and -808). The earlier
missing exclusive-marker error is absent from this startup prefix; sys_exit
was not reached, so this run does not establish its admission.

The complete raw run is in arm64_qemu_corpus_19700101_000008_108242.tar.gz.
all-startup-loads.jsonl preserves feature probes and application attempts;
native-replacements.jsonl preserves exact identities. resident-counters.csv
contains raw baseline program work/time counters. The gzip logs preserve
private kernel pinning, image/root build, QEMU output and Spark packaging.
Make command exit0 is distinct from the recorded application error.

Fresh artifacts: ../bcc-exclusive-v12. The private runtime is
kprog/arm64/build/app-runtime-v12, image
bpf-benchmark/runner-runtime:arm64-a-context-v12. The matching image/kernel
Spark command sequence has been built under that runtime's spark directory;
performance on hardware remains pending. The unchanged corpus workload uses
SAMPLES=1 WORKLOAD_DURATION=2, CPUs8-11 and4GiB full-system QEMU. QEMU timing
is functional evidence only.

# Strict all-probe BCC runtime retry

Run arm64_qemu_corpus_19700101_000008_377973 used the existing two-start
workload, one sample/two seconds, BPF stats on, eight vCPUs/4GiB. The baseline
completed with23 raw program counter rows. The strict published0bff849bf shim
replaced22 startup programs before additional probes failed: anonymous tracing
zero with expected_attach23, and seven runtime-FD map-value probes. All104
startup attempts remain (96loaded, eight unfinished); no program is excluded.
No native workload measurement completed. Exact app errors/counters/shim logs
are retained in the run archive and raw JSON/CSV/JSONL files.

Kernel/stock modules/11kinsn use immutable6836f7d44, loader context-v2-func-ip,
and current ARM linker01e636c94. All23 BCC source/native-proof/simulator triples
were regenerated/compiled. Five common startup triples were installed before
building the image. The exact packaged BCC payload and its manifest are
archived; later staging changes do not alter that evidence. The new global-map
consumer and additional startup selectors are the next integration, with
source-map SO and module changed together.

The first run command was issued before root export completed and failed with
missing qemu-run.sh directory. That raw failure remains; the sequential retry
ran after the build completed. build.log/run.log contain exact Make commands.
The root/image at kprog/arm64/build/app-runtime-v5 are the current runtime;
olderv4 was removed only after this image was built and all old raw evidence
committed. QEMU measurements are functional.

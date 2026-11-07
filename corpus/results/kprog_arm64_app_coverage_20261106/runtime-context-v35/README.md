# Actual ARM opensnoop admission with local native memset

The unchanged BCC workload was retried with all 32 selectors preserved, all 23
fresh proof candidates compiled, and the standard matched published kernel and
native_lab module. The diagnostic module is not used.

Opensnoop sys_exit_openat now loads with a prebuilt generation-bound simulator
proof. Its exact original/native ID replacement is retained in diagnosis.json
and native-replacements.jsonl. This closes the external-memset binding mismatch:
the native ELF and generated simulator contain an ordinary local byte-loop body.

The complete startup logs contain 13 bound replacements and four
native-load failures. The baseline has 23 resident program counter rows; the
application remains error (syscount rc97) and has no native workload counters.
Three exclusive retry loops and tcplife's stack use still fail. Application
completion, matching workload and performance are not claimed.

All startup attempts, phase counters/stdout/stderr/errors and the complete raw
runner directory remain. The multiline error CSV is gzip-preserved. All 32
native/proof payloads and the immutable image/kernel identity are retained.

The portable Spark launcher is built and its bound-path environment has been
round-tripped with three samples,180seconds and BPF stats enabled. No Spark
hardware run occurred. The image tar remains at
/workspaces/repository/kprog/arm64/build/app-runtime-v35/image.tar; transfer it
alongside the packaged spark directory, following ../DGX-SPARK.md.

~~~sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile qemu-context-v2-app RUNTIME_BASE=/workspaces/repository/kprog/arm64/build/app-runtime-v35 RUNTIME_IMAGE=bpf-benchmark/runner-runtime:arm64-a-context-v35 APP=bcc/set
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile app-replay-build RUNTIME_BASE=/workspaces/repository/kprog/arm64/build/app-runtime-v35 RUNTIME_IMAGE=bpf-benchmark/runner-runtime:arm64-a-context-v35
~~~

The previously lane-local app-replay Make targets are published with this result;
they expose the existing packaged launcher without changing the app runner.

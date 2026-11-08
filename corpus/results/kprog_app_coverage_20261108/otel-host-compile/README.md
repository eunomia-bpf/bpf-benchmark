# Whole OTel fresh host compilation

The unchanged upstream application generates and compiles 5 programs, then binds 4: read_task_struct, perf_unwind_stop, perf_unwind_native and perf_unwind_hotspot. All 5 terminal native hashes and 5 compiler source/object receipts reconcile. Fresh host compilation completes every requested Clang job; the largest observed RSS is 11,756,356 KiB. The broker and guest both exit 0.

The corpus driver records `loadtime rejit timed out after 900.0s`. Entry perf_unwind_perl starts compilation at 04:09:02 UTC and completes at 04:14:26 UTC, when its worker activation receives a refusal. The relationship between lifecycle cancellation and that later refusal is an inference from the explicit driver error, request chronology and kernel activation contract. The recorded frontier is lifecycle completion; the verifier-rejection count is 0.

The public simulator header evolves during this cohort under V ownership. The actual private compiler header, narrow-read header and wrapper retain their captured launch hashes. `coverage.json` records that one public-source drift explicitly, while `host-compiler.tar.gz` and service archives preserve the actual compiled source and object identities.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/host-compile-otel/run.sh
```

The complete original app, baseline census, work counters, request archives, generated C/BPF, service/kernel logs and source/image/binary pins are retained in service/result/launch/driver archives. The next cohort uses the existing corpus lifecycle timeout interfaces with 0 so its native-only startup follows actual generation and loading. Native bytes, worker capability checks, binding and workload retain their contracts.

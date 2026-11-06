# Lane A: AArch64 application artifact coverage, 2026-11-06

Baseline generation: **1,090/1,136 staged native proof objects generated C**,
covering all six application directories. The remaining 46 Tetragon objects fail on unresolved indirect `blr` targets;
all failures and call-register details are retained.
The [baseline table](baseline/table.md), [per-artifact CSV](baseline/coverage.csv),
[command log](baseline/commands.jsonl), and [outcome log](baseline/programs.jsonl)
retain every case. The generator/header snapshot and generated-source/native-input
archive are in `baseline/`. These are artifact counts, not a current inventory
of programs loaded during application startup.

| Application | Staged proof objects | Manifest program entries |
| --- | ---: | ---: |
| BCC | 34 | 29 |
| Cilium | 82 | 89 |
| Katran | 6 | 3 |
| OTel | 30 | 26 |
| Tetragon | 809 | 236 |
| Tracee | 175 | 114 |

Inputs: `vendor/build/native-bpf/arm64/stage/`, dated September 30 in this
checkout. Original manifests are copied into [inventory/](inventory/).
Objects include subroutines and configuration variants; manifests have
truncated-name entries and are not a complete current startup inventory.
No program, helper object, or failing artifact was excluded.

The initial pilot failed to compile: compact generation calls the removed
`arm64_apply_width` function. Its full console output is retained in
[baseline/pilot-compile.log](baseline/pilot-compile.log). The compact generator
also adds a fuel limit and a zero-return exit. Both renderer forms invent
one-entry array map definitions for unresolved app symbols; the app harness
uses XDP entry ABI for every program. Several helper macros return zero
instead of calling the helper. Baseline generation success is therefore **not
verified native safety or generation-bound application execution**. Verifier
checks and application executions remain unmeasured at this checkpoint.

Exact initial command, from the repository root:

```sh
taskset -c 16-19 make -C kprog/arm64 app-proofs-build APP_SIM_PROOF_ARGS='--generate-only --report-dir /workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/baseline --output-dir /workspaces/repository/kprog/arm64/app-coverage-baseline'
```

Generation ran on `master`, starting from `075c64b6e`; other lanes committed
`5d3757d35` and `8d4d57957` during enumeration. Neither touched the AArch64
generator/header snapshot. Unrelated dirty work was preserved. QEMU timings
will be functional diagnostics only; lane R owns performance measurement.

The app binding dependency was reported in the shared lane coordination file:
`native_loader_load_from_fd_with_manifest_path_btf_and_attach` does not populate
`FdLoadOptions.proof_insns`. The existing app entrypoint therefore uploads
unbound native code. A native-link `.proof.o` is native ELF input, not the
simulator BPF proof required by the generation-bound path. Lane T owns that
binding API; acceptance of separate XDP artifacts cannot close that gap.

## Compact-path removal and first QEMU load

The compact interpreter has been deleted, including its step table, fuel
limit, unknown-PC exit, and zero-return completion. App generation now uses
the same instruction-by-instruction label renderer as micro generation. The
first BCC artifact (`biosnoop.blk_account_io_merge_bio`) now compiles and loads
in full-system AArch64 QEMU. Its [raw loader output](label-pilot/verify/bcc_biosnoop_blk_account_io_merge_bio.stdout)
and [table](label-pilot/table.md) record **1/1 diagnostic XDP acceptance**.
The map/ABI/helper caveats above still apply; no app workload ran in this check.

Reproduce the isolated diagnostic using the result-local Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=label-pilot
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=label-pilot
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile summarize PHASE=label-pilot
```

The load harness packages an existing AArch64 BusyBox/libc initramfs, the
AArch64 reversesim loader, and compiled artifacts into image layers, exposing
only the result directory to the guest. It uses two vCPUs, 2 GiB RAM, host CPUs
16-19, the framework AArch64 `Image`, and QEMU TCG (`-cpu max`). It does not
rebuild a shared kernel, module, or runtime image. `BASE_INITRAMFS` and `KERNEL`
can be supplied to the Makefile. The default base is a local supervisor
artifact named explicitly in that Makefile, not an application runtime image.
Each completed compiler/loader attempt has its own raw record; rerunning
compilation reuses completed outcomes. The compiler deadline is 120 seconds
per case and loader deadline is 60 seconds. Failures stay in the table.

Validation: Python syntax checks, the BCC generation/compile regression, and
the QEMU load all passed. The concurrent shared formal check currently fails
in lane V's layout migration at `KProgFormal.CrossIsaRev`: duplicate
`GeneratedArm64Width.Width.enumToBitVec` imports. No formal file was changed
by this compact-removal increment; lane V is resolving the migration.

## Uninitialized-stack diagnostic

Lane F's negative suite accepts `ldur x0, [sp, #-8]; ret` with the production
simulator, whose backing stack is zero-initialized. A snapshot-only experiment
removed that initialization and made the backing union volatile. The resulting
BPF is exactly an uninitialized `r10 - 8` read followed by `exit`; QEMU still
accepted it. [Compiled instructions](uninitialized-stack-fix/compiled-bpf.asm)
and [verifier log](uninitialized-stack-fix/verify/uninitialized_stack.verifier.log)
retain the evidence. This experiment does **not** close the negative failure.
No production stack change was made by lane A.

The framework kernel's `include/linux/bpf.h:bpf_allow_uninit_stack` permits
uninitialized stack reads for `CAP_PERFMON` callers, and `verifier.c` assigns
that premise to `env->allow_uninit_stack`. The root guest uses that privileged
verifier contract. Removing simulator initialization alone cannot establish
the stricter negative-suite property. F owns the production stack correction;
this additional verifier premise was reported to F/T in coordination.

## Subsequent checkpoints

The label-rendered census also completed all 1,136 inputs: 1,090 generated and
46 Tetragon helper-identification failures. Extending the shared helper table
with IDs 36, 58, 109, 130 and 181 makes **all 46 failures generate**, as recorded
in [helper-ids/](helper-ids/). Together the two label-rendered checkpoints cover
all 1,136 staged inputs at generation. This closes the observed missing-helper
identification failures, not callback semantics, map/ABI fidelity, verification,
or application execution. The new macros call the actual helpers; their ABI
oracle checks distinct argument lanes, pointer order, u32 narrowing and negative
return values.

The [label-all table](label-all/table.md) and [per-artifact CSV](label-all/coverage.csv)
record compile/load outcomes including pending work. The first 29 completed
BCC load checks yielded 9 acceptances, 15 verifier rejections and 5 load
preparation failures. Cilium also has a diagnostic acceptance. Most large
compiles have reached the 120-second diagnostic deadline under concurrent
lane work; they remain timeout errors, not claims of unsupported instructions.
The initial compile invocation enumerated only 326 generated inputs while
generation was still running; rerun `compile PHASE=label-all` after it exits to
cover the rest. Compiler and verifier outcomes checkpoint independently.

[Manifest pairing](inventory/pairing.csv) covers all 497 manifest entries:
466 pair uniquely and 31 have ambiguous truncated names; no entry lacks a
candidate after applying both native-loader filename conventions. These
remain manifest entries, not a measured startup inventory. Do not resolve an
ambiguous program by choosing an arbitrary candidate.

The portable diagnostic kernel/initramfs is built and its standalone Makefile
has passed QEMU TCG locally. [DGX-SPARK.md](DGX-SPARK.md) gives the concrete
transfer and hardware replay commands and distinguishes them from the still
unavailable six-app generation-bound workload command.

Helper validation: `helper-contract-check` passed the affected Lean theorem,
generated-file freshness, the vendored libbpf ID check, 74 identity-table cases
and 84 helper-call/ABI cases. The full `make -C kprog/formal check` retry
stopped at a concurrently changed x86 CMOV route oracle (96,848 failures),
before the Arm helper tests; its complete log is retained under `helper-ids/`.
The first requested Arm negative + 29-case build completed nine positive
compiles before A interrupted it to avoid a second lane writing the shared
output directory. A restarted with isolated output paths and `--no-generate`;
that build is still running. The retained progress log is a checkpoint, not a
completed pass. Both invocations and the collision are recorded in coordination. No new helper macro is substituted with a zero return.

The missing-helper retry compile/load batch has now completed: **46 generated,
11 compiled, 35 compiler timeouts; all 11 compiled artifacts were rejected by
the diagnostic XDP verifier**. Their helper calls are now visible instead of
being unidentified during generation. Full raw compiler and verifier logs and
the [updated table](helper-ids/table.md) are retained. They require the actual
application program types/contexts and map bindings for an app-path result.

To resume the existing census without replacing completed records:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=label-all
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile verify PHASE=label-all
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile summarize PHASE=label-all
```

The result-local compiler also accepts disjoint index slices through
`COMPILE_ARGS='start stop'` over successfully generated records. Active slices
116:152 cover Katran/OTel and 915:1090 cover Tracee, while the initial 326-case
queue advances through the earlier records. This changes scheduling only;
the full table includes every object and all unfinished cases. Completed
verifier records are reused with their original raw logs and failure status.

The next QEMU checkpoint adds diagnostic load outcomes from Katran, OTel and
Tracee as well as BCC/Cilium. Across `label-all` and `helper-ids`, each of the
six applications now has generated-artifact verifier outcomes; these still
are not startup/application coverage or bound execution. Rejection classes in
the CSVs are derived from the complete verifier logs, including unavailable
helpers for the XDP type, packet-end arithmetic, packet offsets, synthetic-map
member accesses, map-value bounds, register fills and 32-bit pointer arithmetic.

Scheduling checkpoint: the original compile queues were stopped with their
completed records retained, then restarted using per-artifact file locks.
This prevents two overlapping resume invocations from writing the same object
or JSON record simultaneously. The complete default queue and the Tracee tail
queue now share those locks; they retain and reuse every completed success or
failure. The earlier progress logs remain alongside the current logs.

Binding update, 07:54 UTC: T has now implemented optional simulator-object
lookup through the manifest C entrypoint (`simulator_object`,
`simulator_program`) and passed a helper-proof fixture. The original-map
fixture still mismatches (`0xCCCCCCCC` observed, `2` expected). The earlier
entrypoint description records the baseline; A app ABI/map generation, real
startup inventory, complete verifier closure, bound QEMU workloads and their
same-work counters remain unfinished. The portable archive is a diagnostic
artifact replay, not a six-app performance bundle.

Micro-build failure checkpoint, 07:58 UTC: the isolated rebuild reports
`bcc_runqlat_log2_histogram_bucket` compile failure, clang exit 135, after
1449.848 seconds. The existing driver emits a compact compiler error and
continues the remaining cases; see `helper-ids/micro-build-isolated-progress.log`.
The production stack header changed during that compile, so its cause has not
been isolated. No architecture-wide build success is claimed. This is separate
from the passing helper identity/ABI checks and the retained app artifact scan.

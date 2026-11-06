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
| Tetragon | 809 | 235 |
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

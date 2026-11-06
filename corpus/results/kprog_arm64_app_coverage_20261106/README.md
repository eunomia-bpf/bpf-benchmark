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

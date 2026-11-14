# Named and numeric helper calls converge in the selected runtime linker

The exact linker binary selected for the current combined OTel configuration
produces identical runtime images, relocation tables, map patches and ABI
records for named PLT32 and numeric-register helper calls in three shapes:
adjacent, separated by an instruction that does not overwrite the helper
register, and a helper ID hoisted in RBX across two calls. All existing LTO
options are enabled together. Six actual emitted native executions return
the independent callback result101/102 and invoke it exactly once/twice.
`result.json` includes the assembly for every case; `commands.json` retains
the actual proof and kernel-mode commands and outcomes.

The current source scans until control transfer/register overwrite; strict
immediate/call adjacency is not required. Named and numeric references meet
in `helper_call_name` before the same runtime dispatch. Proof mode intentionally
preserves symbolic calls before runtime LTO. A different proof relocation
count therefore does not establish a runtime helper inlining defect. C was
sent these facts to update the older Tracee convergence explanation and
provide a real divergent entry/plan if one remains.

The test initially omitted `--abi-load-sites true` for the probe-read LTO
option and exited before kernel-mode output; that raw failure remains.
590bf4eba adds the existing required metadata selection. Final test source
3f4b9f0e6/590bf4eba, Make `helper-shapes` in scalar-spill-precision.mk. Each
product is overwritten at one scratch location; no linker binary is rebuilt
or copied. Raw: `/workspaces/kprog-raw/perf/20261114-helper-shapes`.

This establishes the focused call-shape behavior in the selected binary.
It does not certify all Tracee entries, explain its failed-read samples,
resolve CO-RE differences, or provide a performance gain. Those actual
program/data questions remain with P1-Tracee-read and C's producer work.

# Kernel-Fixed Baselines Implementation Summary

**Date:** 2026-03-10

**Branch:** `vendor/linux` -> `jit-fixed-baselines`

## Modified Files

- `vendor/linux/kernel/bpf/Kconfig`
- `vendor/linux/include/linux/bpf_jit_directives.h`
- `vendor/linux/kernel/bpf/jit_directives.c`
- `vendor/linux/arch/x86/net/bpf_jit_comp.c`
- `docs/tmp/kernel-fixed-baselines-implementation.md`

## LOC Added

Kernel changes only (`git diff --stat/--numstat` across the 4 kernel files):

- 310 insertions
- 26 deletions
- net: +284 lines

Per file:

- `arch/x86/net/bpf_jit_comp.c`: +185 / -26
- `include/linux/bpf_jit_directives.h`: +7 / -0
- `kernel/bpf/Kconfig`: +34 / -0
- `kernel/bpf/jit_directives.c`: +84 / -0

## CONFIG Options

- `CONFIG_BPF_JIT_FIXED_ROTATE` (default `y`): fixed rotate idiom baseline, emits `ROR` or `RORX` depending on BMI2.
- `CONFIG_BPF_JIT_FIXED_WIDE_MEM` (default `y`): fixed wide-load baseline for byte-recomposition ladders.
- `CONFIG_BPF_JIT_FIXED_LEA` (default `y`): fixed `LEA` baseline for `mov + shl + add` address-calculation patterns.
- `CONFIG_BPF_JIT_FIXED_CMOV` (default `n`): fixed `CMOV` baseline for compact/diamond conditional-select patterns.

## What Was Implemented

- Added four independent Kconfig toggles for the fixed baselines.
- Added public probe wrappers in `jit_directives.c`:
  - `bpf_jit_probe_rotate()`
  - `bpf_jit_probe_wide_mem()`
  - `bpf_jit_probe_addr_calc()`
  - `bpf_jit_probe_cond_select()`
- Reused existing v4 validators through synthetic `struct bpf_jit_rule` construction, so the fixed baselines share the same structural checks and emitters without requiring a v4 policy blob.
- Added a fixed-heuristic block in `arch/x86/net/bpf_jit_comp.c` before the main BPF->x86 switch, reusing `bpf_jit_try_emit_rule()` and the same multi-insn `addrs[]` bookkeeping pattern as the v4 path.

## Issues Encountered

- v4 precedence needed one extra guard: if an active v4 rule starts at the current site, fixed heuristics must not fire even when that rule requests stock emission (`consumed == 0`). This is handled with a `v4_rule_matched` check in `do_jit()`.
- Fixed `CMOV` can overlap the older load-time `BPF_JIT_DIRECTIVE_CMOV_SELECT` path, so the fixed baseline explicitly skips sites already covered by a legacy CMOV directive.
- Ran `make olddefconfig` before the final build so the new Kconfig symbols were materialized in `.config` with their default values.

## Build Verification

- `make olddefconfig`
- `make -j$(nproc) arch/x86/net/bpf_jit_comp.o kernel/bpf/jit_directives.o`
- `make -j$(nproc) bzImage`

All of the above completed successfully on this branch.

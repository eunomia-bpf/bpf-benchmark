# Kernel Low-Risk Simplification Report (2026-03-20)

## Summary

- Scope: only kernel code under `vendor/linux-framework` was changed.
- Result: all 6 requested simplifications were implemented.
- Behavior: intended as pure refactor only; no semantic changes were introduced.
- Net line reduction: `-137 LOC` (`183 insertions`, `320 deletions`) from `git -C vendor/linux-framework diff --shortstat`.

## Implemented Changes

| Item | Result | Notes |
|------|--------|-------|
| 1. ARM64 `a64_invert_cond` | Done | Replaced the explicit condition-pair switch with `cond ^ 1`, while still rejecting `cond >= AARCH64_INSN_COND_AL`. |
| 2. `alu32_linearizable` / `alu64_linearizable` merge | Done | Folded both helpers into `bpf_jit_alu_insn_linearizable(insn, is_32bit)`. |
| 3. Shared small helpers in common header | Done | Moved `bpf_jit_binding_value_is_noop()`, `bpf_jit_pick_wide_chunk()`, and `bpf_jit_bitfield_mask_width()` to `include/linux/bpf_jit_directives.h` as `static inline`. |
| 4. `image_prog` lookup dedup in `jit_directives.c` | Done | Added `bpf_jit_recompile_image_prog()` and `bpf_jit_recompile_ksym_prog()` and replaced repeated ternaries. |
| 5. x86 opcode mapping switch -> lookup table | Done | Replaced the three jump-op mapping switches with sparse lookup tables plus `bpf_jmp_opcode_lookup()`. |
| 6. `is_cmov_cond_jump` / `cond_op_valid` merge | Done | `bpf_jit_is_cmov_cond_jump()` now reuses `bpf_jit_cond_op_valid()`. |

No requested item was skipped.

## Incremental Compile Validation

Each simplification was followed by an object-level compile check:

- `make -C vendor/linux-framework kernel/bpf/jit_validators.o`
- `make -C vendor/linux-framework kernel/bpf/jit_directives.o`
- `make -C vendor/linux-framework arch/x86/net/bpf_jit_comp.o`
- ARM64 object check via a clean temporary hardlinked source tree plus out-of-tree build:
  - `make -C /tmp/linux-framework-arm64-src-137420 O=/tmp/linux-framework-arm64-build-137420 ARCH=arm64 LLVM=1 arch/arm64/net/bpf_jit_comp.o`

The temporary ARM64 tree was necessary because the main `vendor/linux-framework` tree is already being used for an in-tree x86 build and cannot be safely reused for a clean out-of-tree ARM64 Kbuild run.

## Full Validation

- `make -C vendor/linux-framework -j$(nproc) bzImage`
  - Success: `arch/x86/boot/bzImage is ready (#82)`
- `make vm-selftest`
  - Success: `PASS all 35 test(s)`
- `make vm-micro-smoke`
  - Success: smoke run completed and wrote `micro/results/dev/vm_micro_smoke.json`

## Line Count

`git -C vendor/linux-framework diff --numstat`:

| File | + | - | Net |
|------|---:|---:|---:|
| `arch/arm64/net/bpf_jit_comp.c` | 10 | 65 | -55 |
| `arch/x86/net/bpf_jit_comp.c` | 69 | 141 | -72 |
| `include/linux/bpf_jit_directives.h` | 28 | 0 | +28 |
| `kernel/bpf/jit_directives.c` | 44 | 40 | +4 |
| `kernel/bpf/jit_validators.c` | 32 | 74 | -42 |
| **Total** | **183** | **320** | **-137** |

Notes:

- Item 4 improved duplication/readability but `kernel/bpf/jit_directives.c` itself ended up `+4` lines because the helper definitions offset most of the repeated ternary removal.
- The overall target was still met: total kernel delta is `-137 LOC`, slightly better than the requested `~130 LOC`.

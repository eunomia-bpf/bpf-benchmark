# ARM64 BpfReJIT Emitter Implementation Report

Date: 2026-03-19

## Scope

Implemented the ARM64 BpfReJIT first wave for these canonical forms:

- `COND_SELECT` via `CMP`/`TST` + `CSEL`-family
- `ROTATE` via `EXTR`
- `WIDE_MEM` wide-load fusion via exact-width `LDR*` + endian fixups
- `BITFIELD_EXTRACT` via `UBFX`

Also implemented ARM64 staged recompile plumbing so policy-driven recompile can stage, commit, and abort safely.

## Kernel Changes

### ARM64 JIT helpers and emitters

Updated `vendor/linux-framework/arch/arm64/net/bpf_jit.h` to add:

- `A64_EXTR`
- `A64_ROR_I`
- `A64_UBFX`
- `A64_SBFX`
- `A64_RORV`

Updated `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c` to add:

- ARM64 binding helpers and compare/select helpers
- `emit_a64_cond_select()`
- `emit_canonical_rotate_arm64()`
- `emit_canonical_wide_load_arm64()`
- `emit_canonical_bitfield_extract_arm64()`
- `emit_canonical_select_arm64()`
- rule lookup and application in `build_body()`
- ARM64 `bpf_jit_arch_form_supported()`
- ARM64 staged recompile support:
  - `bpf_jit_recompile_commit()`
  - `bpf_jit_recompile_abort()`
  - `bpf_jit_supports_recompile()`

### Shared kernel changes

Updated `vendor/linux-framework/include/linux/bpf_jit_directives.h` to widen the staged-image helper guard from x86-only to x86 or ARM64.

Updated `vendor/linux-framework/kernel/bpf/jit_policy.c` to accept ARM64 policy blobs instead of rejecting all non-x86 architectures as unsupported.

## Selftest / Harness Adjustments

Updated `tests/kernel/test_recompile.c` so the test binary:

- emits the correct policy `arch_id` for the build target
- uses the opposite architecture for the wrong-arch negative test
- treats ARM64 later-wave forms (`addr_calc`, `zero_ext_elide`, `endian_fusion`, `branch_flip`) as expected unsupported cases for this first-wave port
- skips the x86-specific wide native-byte diff assertion on ARM64

These changes keep x86 behavior unchanged while making the ARM64 selftest reflect the intended first-wave support set.

## Verification

### Important note

`make kernel-arm64` in the repo uses a separate ARM64 source worktree, not the modified `vendor/linux-framework` checkout. To validate the actual implementation here, ARM64 builds were run directly in `vendor/linux-framework`, and ARM64 VM tests were run with:

`ARM64_IMAGE=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/arm64/boot/Image`

### Results

1. ARM64 direct build in modified tree:
   - `make -C vendor/linux-framework ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- KCONFIG_CONFIG=.config.arm64 -j$(nproc) Image`
   - Passed

2. x86 direct build in modified tree:
   - `make -C vendor/linux-framework -j$(nproc) bzImage`
   - Passed

3. x86 VM selftest:
   - `make vm-selftest`
   - Passed: 24/24 tests

4. x86 VM micro smoke:
   - `make vm-micro-smoke`
   - Passed

5. ARM64 QEMU smoke against modified ARM64 image:
   - `make vm-arm64-smoke ARM64_IMAGE=.../vendor/linux-framework/arch/arm64/boot/Image`
   - Passed

6. ARM64 QEMU selftest against modified ARM64 image:
   - `make vm-arm64-selftest ARM64_IMAGE=.../vendor/linux-framework/arch/arm64/boot/Image`
   - Passed: 24/24 tests

## ARM64 First-Wave Outcome

Verified working on ARM64:

- wide-load recompile
- cond-select recompile
- rotate recompile
- bitfield-extract recompile
- repeated recompile
- concurrent recompile `EBUSY` handling
- recompile while attached

Verified fail-closed on ARM64 for later-wave forms not implemented here:

- `addr_calc`
- `zero_ext_elide`
- `endian_fusion`
- `branch_flip`

## Notes

- The ARM64 selftest pass depends on the test harness being architecture-aware; before that fix it was hard-coded for x86 policy blobs.
- The implementation follows the design doc closely, with one extra shared kernel fix in `kernel/bpf/jit_policy.c` discovered during ARM64 validation.

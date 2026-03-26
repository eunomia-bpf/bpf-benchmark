# ARM64 BpfReJIT Test Results - 2026-03-25

## Environment

- **Kernel**: 7.0.0-rc2-g1268862b9d36 (rejit-v2 branch)
- **QEMU**: qemu-system-aarch64 8.2.2, `-M virt -cpu cortex-a72 -smp 4 -m 4G`
- **Cross-compiler**: aarch64-linux-gnu-gcc 13.3.0
- **Host**: x86_64, no KVM (pure emulation)

## Build Summary

### Kernel Image
- Pre-built at `vendor/linux-framework/build-arm64/arch/arm64/boot/Image`

### Kinsn Modules (5/5 compiled)
- `bpf_rotate.ko` - EXTR-based 64-bit rotate
- `bpf_select.ko` - conditional select (CSEL)
- `bpf_extract.ko` - bitfield extraction (UBFX)
- `bpf_endian.ko` - endian load (REV)
- `bpf_barrier.ko` - speculation barrier (SB/DSB+ISB)

Build command:
```bash
make -C .worktrees/linux-framework-arm64-src \
  O=vendor/linux-framework/build-arm64 \
  M=/tmp/arm64-module-build \
  ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
```

Note: The kernel build system overwrites `module/arm64/Makefile` with a redirect
when using `M=module/arm64` directly. Workaround: copy sources to a temp directory
and use a `Kbuild` file instead of `Makefile`.

### Test Binaries (7/7 compiled, static)
All simple tests (no libbpf dependency) cross-compiled with:
```bash
aarch64-linux-gnu-gcc -O2 -g -Wall -Wno-cpp -static \
  -I vendor/linux-framework/include/uapi -lpthread
```

## Test Results

### Module Loading: 5/5 OK

All kinsn modules loaded successfully into the ARM64 kernel.

### Test Suite Results

| Test | Result | Details |
|------|--------|---------|
| **rejit_poc** | **6/6 PASS** | same-length, different-length, fd_array, test_run correctness, info consistency, concurrent REJIT |
| **rejit_kinsn** | **13 pass, 0 fail, 1 skip** | Discovery: 7 kfuncs found across 5 modules. Skip: `rotate_jit_emits_rol` (x86_64-only). All ARM64-relevant kinsn tests pass including rotate, select, endian, extract, barrier. |
| **rejit_safety_tests** | **20/20 PASS** | All 15 negative tests + 5 correctness tests pass |
| **rejit_rollback_tests** | **0 pass, 0 fail, 1 skip** | T1 skipped: debugfs test hook unavailable (expected) |
| **rejit_regression** | **5/5 PASS** | concurrent_rejit, latency (487us), rapid_kallsyms, xdp_test_run, concurrent_rejit_and_run |
| **rejit_tail_call** | **2/2 PASS** | Kernel WARNING at `bpf_arch_poke_desc_update` (stub not implemented for ARM64), but test passes |
| **rejit_spectre** | **7/7 PASS** | All Spectre mitigation tests pass |

### Overall: 53 pass, 0 fail, 2 skip

## Known Issues

1. **`bpf_arch_poke_desc_update` WARNING**: The ARM64 JIT does not implement
   `bpf_arch_poke_desc_update` (returns `WARN_ON_ONCE` at `arraymap.c:1104`).
   This is a pre-existing kernel stub issue for tail call poke descriptors on ARM64.
   The tail call tests still pass functionally.

2. **Module Makefile overwrite**: The kernel build system's `O=` redirect mechanism
   overwrites the `Makefile` in the `M=` directory with an auto-generated redirect.
   This breaks subsequent builds. Workaround: use a separate build directory or
   use `Kbuild` instead of `Makefile` for the module.

## Conclusion

BpfReJIT's core functionality is fully operational on ARM64:
- REJIT syscall: same-length and different-length rewriting works
- Kinsn inline kfuncs: all 5 modules load and their kfuncs are discovered
- Verifier integration: kinsn instantiation and validation works
- Safety: all negative tests reject invalid programs as expected
- Concurrency: multi-threaded REJIT is safe
- Regression fixes: all b4bd737ef-era fixes verified on ARM64

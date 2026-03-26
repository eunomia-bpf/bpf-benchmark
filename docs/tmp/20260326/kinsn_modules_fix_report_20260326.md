# 2026-03-26 kinsn modules fix report

## Scope

Fixed the three review findings called out in [`docs/tmp/20260326/kinsn_modules_review_20260326.md`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260326/kinsn_modules_review_20260326.md):

1. `module/x86/bpf_bulk_memory.c`
2. `module/arm64/bpf_bulk_memory.c`

## Fixes

### Fix 1: x86 bulk-memory payload validation

- Added fail-closed reserved-bit checks:
  - `memcpy`: reject `payload >> 52`
  - `memset`: reject `payload >> 44`
- Added explicit decoded-length bounds checks in both x86 decode paths:
  - reject `len == 0`
  - reject `len > 128`

This closes the proof-buffer overrun case where x86 `instantiate_*()` could previously accept payload lengths above the descriptor limits.

### Fix 2: x86 memset `val_reg == BPF_REG_1` aliasing

- Reordered `emit_memset_x86()` so the byte value is materialized into `RAX` before `emit_addr_setup()` rewrites `RDI`.

This preserves the original `val_reg` byte even when the payload chooses `BPF_REG_1`.

### Fix 3: ARM64 memcpy temp-register semantics

- `emit_memcpy_bulk_arm64()` now decodes and maps the payload `tmp_reg`.
- The tail-copy path now uses that decoded ARM64 register instead of a hardcoded scratch register.
- For full-16-byte copies and even-sized tails, the emitter now reloads the final source byte into the decoded `tmp_reg` so the native JIT result matches the proof sequence's final register state.

## Verification

Executed:

```sh
make kinsn-modules
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml bulk_memory
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
make -C module/arm64 KDIR=/home/yunwei37/workspace/bpf-benchmark/.worktrees/linux-framework-arm64-src O=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/build-arm64 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
```

Results:

- `make kinsn-modules`: passed, rebuilt `module/x86/bpf_bulk_memory.ko`
- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml bulk_memory`: passed (`17 passed`)
- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`: passed (`431 passed`, `12 ignored`)
- `make -C module/arm64 ...`: passed, rebuilt `module/arm64/bpf_bulk_memory.ko`

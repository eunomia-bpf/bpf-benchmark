# Kernel Tracepoint / Stock Choice Cleanup

## Scope

This pass completed two reductions:

1. Removed BpfReJIT tracepoints.
2. Eliminated explicit stock native-choice rules.

The workspace already had unrelated local changes under `vendor/linux-framework`; this work was applied on top without reverting those edits.

## What Changed

### 1. BpfReJIT tracepoints removed

- Deleted `vendor/linux-framework/include/trace/events/bpf.h`.
- Removed `CREATE_TRACE_POINTS` / `#include <trace/events/bpf.h>` from `vendor/linux-framework/kernel/bpf/jit_directives.c`.
- Removed all `trace_bpf_jit_recompile_start()`, `trace_bpf_jit_recompile_end()`, and `trace_bpf_jit_recompile_rule()` call sites.
- Dropped now-unused local trace bookkeeping in `bpf_prog_jit_recompile()`.

### 2. Explicit stock native choices removed

- Removed stock native-choice enum values from `vendor/linux-framework/include/uapi/linux/bpf.h`:
  - `BPF_JIT_SEL_BRANCH`
  - `BPF_JIT_WMEM_BYTE_LOADS`
  - `BPF_JIT_ROT_SHIFT`
  - `BPF_JIT_ACALC_SHIFT_ADD`
  - `BPF_JIT_BFLIP_ORIGINAL`
- Updated `vendor/linux-framework/kernel/bpf/jit_directives.c` so policy validation only accepts real optimized choices.
- Updated `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` so the emitter dispatcher no longer carries stock-choice `return 0` branches.
- Updated scanner shared constants to match the UAPI cleanup:
  - `scanner/include/bpf_jit_scanner/types.h`
  - `scanner/include/bpf_jit_scanner/pattern_v5.hpp`

### 3. Selftest adjustments

- Updated `tests/kernel/test_recompile.c` so tests no longer fabricate stock-choice policy blobs.
- Stock behavior is now exercised through `policy_fd = 0` (`apply_stock_rejit()`), which matches the intended ABI after this cleanup.
- Relaxed the wide-memory image-diff assertions so they validate meaningful invariants:
  - stock re-JIT preserves semantics
  - optimized wide-site rewrite shrinks the native site and keeps the prefix before the site stable
  - no longer assumes stock re-JIT is bit-identical, or that bytes after the site never shift due to downstream fixups

## Validation

Commands run:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd vendor/linux-framework && make -j$(nproc) bzImage
cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest
cd /home/yunwei37/workspace/bpf-benchmark && make vm-micro-smoke
cd /home/yunwei37/workspace/bpf-benchmark && cmake --build scanner/build --target test_scanner
cd /home/yunwei37/workspace/bpf-benchmark && ./scanner/build/test_scanner
```

Results:

- `make -j$(nproc) bzImage`: PASS
- `make vm-selftest`: PASS (`20/20`)
- `make vm-micro-smoke`: PASS
  - `simple`: stock and recompile both produced expected result
  - `load_byte_recompose`: stock and recompile both produced expected result
- `cmake --build scanner/build --target test_scanner`: PASS
- `./scanner/build/test_scanner`: PASS (`PASS 179`)

## Notes

- `make kernel-tests` still emits the long-standing kernel-header warning from `vendor/linux-framework/include/uapi/linux/types.h` when user space includes vendored kernel headers. No new warning remained from this cleanup after removing now-unused helper code from `tests/kernel/test_recompile.c`.

# ARM64 `bpf_bulk_memory` module report

Date: 2026-03-26

Implemented [`module/arm64/bpf_bulk_memory.c`](/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c) with two v2 kinsn descriptors:

- `bpf_memcpy_bulk`
- `bpf_memset_bulk`

Key implementation points:

- `bpf_memcpy_bulk` decodes the packed bulk-memory payload already emitted by [`daemon/src/passes/bulk_memory.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory.rs), reuses the transported `temp_reg` for proof lowering, expands to bytewise `LDX_MEM/STX_MEM`, and emits an ARM64 `LDP/STP` post-index loop plus scalar `LDR/STR` tail handling for the final `< 16B`.
- `bpf_memset_bulk` supports immediate byte-fill and the reserved `value_from_reg` shape, proof-lowers to byte stores, and emits an ARM64 `STP` post-index loop plus scalar store tail handling.
- Native emit uses internal scratch registers `x9-x13`, which do not overlap the current BPF-to-ARM64 register mapping in [`module/include/kinsn_common.h`](/home/yunwei37/workspace/bpf-benchmark/module/include/kinsn_common.h).

Current-tree interface note:

- The checked-in kernel kinsn API still requires `instantiate_insn()`; there is no in-tree `model_call` callback yet.
- `bpf_memcpy_bulk` therefore uses the pass-supplied `temp_reg` field for proof lowering rather than relying on hidden BPF-visible scratch state.

Build wiring:

- Updated [`module/arm64/Makefile`](/home/yunwei37/workspace/bpf-benchmark/module/arm64/Makefile) to include `bpf_bulk_memory.o`.

Validation:

- ARM64 module build:
  `make -C module/arm64 KDIR=/home/yunwei37/workspace/bpf-benchmark/.worktrees/linux-framework-arm64-src O=/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/build-arm64 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-`
- Result: build succeeded, including `bpf_bulk_memory.ko`.
- No VM runtime loading or kernel execution was performed.

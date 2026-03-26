# ARM64 `bpf_ldp` module report

Date: 2026-03-26

Implemented [`module/arm64/bpf_ldp.c`](/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c) with two v2 kinsn descriptors:

- `bpf_ldp128`: proof-lowers to two ordered `BPF_LDX_MEM(BPF_DW, ...)` loads and emits one ARM64 signed-offset `LDP`.
- `bpf_stp128`: proof-lowers to two ordered `BPF_STX_MEM(BPF_DW, ...)` stores and emits one ARM64 signed-offset `STP`.

Payload decode follows the design ABI:

- bits `[3:0]`: lane0 reg
- bits `[7:4]`: lane1 reg
- bits `[11:8]`: base reg
- bits `[27:12]`: signed 16-bit low offset
- bits `[31:28]`: Phase 1 flags, required to be zero

Implemented constraints:

- pair offset must be 8-byte aligned and in `[-512, 504]`
- `bpf_ldp128` rejects `dst_lo == dst_hi`, either destination as `BPF_REG_10`, or `base == dst_lo/dst_hi`
- `bpf_stp128` allows duplicate source registers and does not forbid `base == src`

Updated [`module/arm64/Makefile`](/home/yunwei37/workspace/bpf-benchmark/module/arm64/Makefile) to build `bpf_ldp.o`.

Validation:

- direct `make -C module/arm64` against the default `vendor/linux-framework` tree fails before reaching the new file because that tree is not configured for ARM64 module compilation and existing ARM64 modules already depend on `CONFIG_ARM64` helpers.
- successful compile validation used a temporary module staging directory plus the existing ARM64 build tree:

```bash
make -C .worktrees/linux-framework-arm64-src \
  O=vendor/linux-framework/build-arm64 \
  M=/tmp/arm64-module-build-bo7Za5 \
  ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- modules
```

- result: `bpf_ldp.ko` built successfully
- runtime or kernel-side loading was not performed

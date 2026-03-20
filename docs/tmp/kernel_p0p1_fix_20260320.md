# Kernel P0/P1 Fix Report

Date: 2026-03-20

Scope completed:
- Fix P0 `BRANCH_FLIP` temp-buffer overflow risk
- Fix P1 `COND_SELECT` alias miscompile
- Fix P1 `ADDR_CALC` self-referential alias
- Remove the dead code called out in the audit

Scope intentionally not included:
- P2 trampoline-regeneration leak from the audit was not changed in this task

## Code changes

### 1. P0: `BRANCH_FLIP` validator tightened

File:
- `vendor/linux-framework/kernel/bpf/jit_validators.c`

Change:
- Added a validator-side x86 native-byte bound for `BRANCH_FLIP`.
- The validator now computes a conservative max-native-byte estimate for:
  - the compare/test emitted for the condition
  - both linearized branch bodies
  - the flipped conditional jump and join jump
- Rules are rejected if the estimated rewritten region exceeds the x86 scratch-buffer capacity (`128 + 64 = 192` bytes).

Effect:
- Prevents the x86 emitter from ever attempting to replay a branch body large enough to overflow its fixed temporary buffer.
- Keeps the safety boundary in the validator instead of relying on emitter-side after-the-fact size checks.

### 2. P1: `COND_SELECT` alias reject

File:
- `vendor/linux-framework/kernel/bpf/jit_validators.c`

Change:
- Added a validator reject for alias cases where `dst_reg` is also used as a condition operand:
  - `dst_reg == cond_a`
  - `dst_reg == cond_b` when `cond_b` is a register

Effect:
- Rejects the source shapes that x86 and arm64 lower with different sequencing, removing the shared-contract ambiguity.

### 3. P1: `ADDR_CALC` self-alias reject

File:
- `vendor/linux-framework/kernel/bpf/jit_validators.c`

Change:
- Added a validator reject when `base_reg == dst_reg` in the `mov dst, idx; lsh dst, scale; add dst, base` shape.

Effect:
- Prevents acceptance of self-referential forms that cannot be represented by the single-`LEA` lowering.

## Dead code removal

Files:
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_policy.c`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

Removed / cleaned up:
- Deleted `struct bpf_jit_policy::blob`
- Stopped retaining/freeing the policy blob in `jit_policy.c`
- Deleted `BPF_JIT_BFX_PARAM_ORDER`
- Deleted `BPF_JIT_BFX_ORDER_MASK_SHIFT`
- Stopped writing the unused bitfield-extract order param
- Deleted the unused `rollback` parameter from `bpf_jit_recompile_prog_images()`
- Deleted the unused `native_choice` parameter from `emit_canonical_rotate_arm64()`
- Made `insn_cnt` live in `bpf_jit_validate_rotate_rule()` by validating the site range instead of discarding it

## Verification

### 1. Kernel build

Command:
```bash
make -C vendor/linux-framework -j$(nproc) bzImage
```

Result:
- Success
- Produced `vendor/linux-framework/arch/x86/boot/bzImage`

### 2. VM selftests

Command:
```bash
make vm-selftest
```

Result:
- Success
- `PASS all 36 test(s)`

### 3. VM micro smoke

Command:
```bash
make vm-micro-smoke
```

Result:
- Success
- Benches passed:
  - `simple`
  - `load_byte_recompose`
  - `cmov_dense`
- Stock and recompiled runs produced matching benchmark results

## Touched files

- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_policy.c`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

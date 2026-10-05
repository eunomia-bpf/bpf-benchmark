# Kernel Review Fixes 2026-03-19

## Scope

Fixed the deep-review P0/P1/P2 findings in the kernel recompile path without changing the on-wire UAPI blob format or removing any canonical form.

## Changes

### P0: trampoline-attached program recompile guard

Files:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/include/linux/bpf.h`

What changed:
- Added `bpf_prog_has_active_trampoline()` to detect active trampoline consumers of a target BPF program by scanning the trampoline table for entries keyed by that program id.
- Broadened the recompile syscall guard to reject programs that:
  - have active trampoline consumers,
  - still carry `aux->dst_trampoline`,
  - are trampoline-attached by type (`bpf_prog_has_trampoline()`),
  - are `BPF_PROG_TYPE_EXT`,
  - or are attached `struct_ops` programs.
- The syscall now returns `-EOPNOTSUPP` with a generic trampoline-regeneration-required log message for all of those cases.

Reason:
- This prevents re-JIT from leaving stale trampoline code pointing at old JIT text until trampoline regeneration is implemented.

### P1: ZERO_EXT_ELIDE emitter reads original insns

Files:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

What changed:
- The validator now stores the validated ALU32 instruction fields in canonical params:
  - `code`
  - `dst_reg`
  - `src_reg`
  - `off`
  - `imm`
- The x86 emitter no longer dereferences the original instruction array.
- Instead it reconstructs a local synthetic `struct bpf_insn` from params and feeds that to `emit_bpf_alu32_insn()`.

### P1: BRANCH_FLIP emitter reads original insns

Files:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

What changed:
- The validator now stores normalized branch-compare fields in params:
  - full conditional branch `code`
  - compare lhs register
  - compare rhs value as reg-or-imm binding
- The validator also copies validated body A/body B instruction sequences into kernel-owned buffers and stores those pointers plus lengths in params.
- The emitter no longer reads the original program instruction array.
- It reconstructs the compare insn from params and emits the flipped bodies from the copied validated buffers.

### P1: policy header reserved flags fail-open

File:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`

What changed:
- Parsing now rejects any non-zero unknown bits in `struct bpf_jit_policy_hdr.flags` with `-EINVAL`.

Reason:
- Reserved header flags are now fail-closed for forward compatibility.

### P2: overlapping active rules not rejected

File:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`

What changed:
- After sorting rules by `site_start`, policy parsing now validates that each rule starts at or after the previous rule end.
- Any overlap causes whole-policy rejection with `-EINVAL`.

### P2: BRANCH_FLIP dead normalized fields

Files:
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`

What changed:
- Removed the dead branch-flip normalized fields from canonical params:
  - `BODY_A_START`
  - `BODY_B_START`
  - `JOIN_TARGET`
  - `SITE_PTR`
- Replaced them with params the emitter actually consumes:
  - normalized branch compare fields
  - copied body pointers
  - copied body lengths

### Supporting cleanup

Files:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`

What changed:
- Switched policy allocation to `kvzalloc()` so per-rule cleanup is safe on early parse failure.
- Added policy cleanup for branch-flip copied body buffers in `bpf_jit_free_policy()`.

## Verification

### 1. Kernel build

Command:
```bash
cd vendor/linux-framework && make -j$(nproc) bzImage
```

Result:
- PASS
- Built `arch/x86/boot/bzImage`

### 2. VM selftests

Command:
```bash
cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest
```

Result:
- PASS
- `PASS all 19 test(s)`

### 3. VM micro smoke

Command:
```bash
cd /home/yunwei37/workspace/bpf-benchmark && make vm-micro-smoke
```

Result:
- PASS
- Required smoke cases passed for both `kernel` and `kernel-recompile`
- `simple`: preserved result, `kernel-recompile` ran successfully
- `cmov_dense`: preserved result, `kernel-recompile` ran successfully

### 4. Scanner tests

Command:
```bash
cd /home/yunwei37/workspace/bpf-benchmark && \
cmake --build scanner/build --target test_scanner && \
./scanner/build/test_scanner
```

Result:
- PASS
- `PASS 180`

# COND_SELECT v5 Migration Report

Date: 2026-03-11

## Summary

The `vendor/linux-framework` tree at commit `2a6783cc7` already contains the
`COND_SELECT` migration to the v5 declarative path. No additional kernel or
scanner source changes were required in this workspace.

The migration is present in the three expected layers:

1. Userspace scanner descriptor generation
   - `scanner/src/pattern_v5.cpp`
   - `build_v5_cond_select_descriptors()`
   - `add_v5_cond_select_descs_for_jump()`
2. Kernel matcher + canonical binding extraction
   - `vendor/linux-framework/kernel/bpf/jit_directives.c`
   - `bpf_jit_validate_pattern_rule()`
   - `bpf_jit_validate_canonical_params()` with `BPF_JIT_CF_COND_SELECT`
3. x86 parameterized emitter
   - `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
   - `emit_canonical_select()`
   - `bpf_jit_try_emit_rule()` dispatch via `BPF_JIT_CF_COND_SELECT`

## Code Status

### 1. Scanner v5 descriptor

`scanner/src/pattern_v5.cpp` already defines declarative `COND_SELECT`
descriptors for both supported shapes:

- diamond: `jcc +2`, `mov`, `ja +1`, `mov`
- compact: `mov`, `jcc +1`, `mov`

The descriptors bind the canonical parameters expected by the emitter:

- `dst`
- `cond_op`
- `cond_a`
- `cond_b`
- `true_val`
- `false_val`
- `width`

### 2. Kernel canonical form and binding extraction

`vendor/linux-framework/kernel/bpf/jit_directives.c` already supports
`BPF_JIT_CF_COND_SELECT` in the generic v5 path:

- canonical form recognition via `bpf_jit_rule_form()`
- binding descriptor validation via `bpf_jit_binding_param_valid()`
- canonical param validation via `bpf_jit_validate_canonical_params()`
- generic match + binding extraction via `bpf_jit_validate_pattern_rule()`

This keeps the kernel on the intended v5 contract: userspace owns the pattern
description; the kernel owns generic matching, constraint checking, canonical
binding extraction, and lowering validation.

### 3. x86 parameterized emitter

`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` already lowers
`BPF_JIT_CF_COND_SELECT` from canonical bindings through
`emit_canonical_select()`.

The emitter consumes canonical parameters instead of re-parsing a fixed raw BPF
window when `rule_kind == BPF_JIT_RK_PATTERN`.

Legacy v4 emitters remain available for non-v5 rules, so the migration is
additive rather than disruptive.

## Validation

### Build / unit checks

- `./scanner/build/test_scanner`
  - result: `OK: 47 passed, 0 failed`
- `make -s -C vendor/linux-framework -j4 arch/x86/net/bpf_jit_comp.o kernel/bpf/jit_directives.o`
  - result: success

### Scanner `--scan-all` on `cmov_select`

Because the host has `kernel.unprivileged_bpf_disabled = 2`, live xlated dumping
had to be performed inside `vng`.

Command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "sudo bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && \
   ./micro/build/runner/micro_exec run-kernel \
     --program ./micro/programs/cmov_select.bpf.o \
     --input ./micro/generated-inputs/cmov_select.mem \
     --input-size 1024 --io-mode staged --repeat 1 \
     --dump-xlated /tmp/cmov_select.xlated --compile-only >/tmp/cmov_compile.json && \
   ./scanner/build/bpf-jit-scanner scan --xlated /tmp/cmov_select.xlated --v5 --all'"
```

Observed scanner result:

```text
Accepted 8 v5 site(s)
  cmov:   1
  wide:   3
  rotate: 4
  lea:    0
```

This confirms `scanner --scan-all` finds the `cmov_select` site through the v5
path.

### Recompile correctness in VM

Baseline:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "cd /home/yunwei37/workspace/bpf-benchmark && \
   sudo ./micro/build/runner/micro_exec run-kernel \
     --program ./micro/programs/cmov_select.bpf.o \
     --input ./micro/generated-inputs/cmov_select.mem \
     --input-size 1024 --io-mode staged --repeat 1"
```

Result:

- `result = 11332120082118096118`
- `jited_prog_len = 4168`
- `xlated_prog_len = 7480`

v5 recompile:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "cd /home/yunwei37/workspace/bpf-benchmark && \
   sudo ./micro/build/runner/micro_exec run-kernel \
     --program ./micro/programs/cmov_select.bpf.o \
     --input ./micro/generated-inputs/cmov_select.mem \
     --input-size 1024 --io-mode staged --repeat 1 \
     --recompile-v5 --recompile-cmov"
```

Result:

- `recompile-cmov: found 1 cmov sites in xlated program (935 insns)`
- `result = 11332120082118096118`
- `directive_scan.cmov_sites = 1`
- `jited_prog_len = 4167`
- `xlated_prog_len = 7480`
- `recompile.applied = true`

## Conclusion

`COND_SELECT` is already migrated to the v5 declarative framework in this tree.
The requested end-to-end properties all hold:

- userspace v5 descriptor exists
- kernel generic matcher extracts canonical bindings
- x86 lowering uses a parameterized canonical emitter
- `scanner --scan-all` finds the `cmov_select` site
- VM recompile preserves correctness and keeps `xlated_prog_len` unchanged

# Kernel Safety Fixes

Date: 2026-03-12

## Scope

Patched the live BpfReJIT recompile path and the masked 32-bit ROTATE validators in:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/helpers.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`

## Fixes

### Issue 1: live recompile vs runtime execution

- Recompile now stages replacement x86 JIT images in `aux->jit_data` and `jit_recompile_*` aux fields instead of mutating live `bpf_func`, extable state, or frame-pointer metadata during compilation.
- `kernel/bpf/jit_directives.c` now publishes the committed image with `smp_store_release()` only after the staged image is complete.
- `main_aux->bpf_exception_cb` is no longer cleared to `NULL`; it is updated only after the replacement callback image is ready.
- Old images are retired only after `synchronize_rcu()`.

### Issue 2: `bpf_int_jit_compile()` success detection

- Recompile no longer treats pointer equality as success.
- The recompile path now requires all staged predicates to hold:
  - the live `prog->bpf_func` stayed unchanged during staging
  - the program remained JITed
  - a staged replacement image exists
  - staged extable metadata is present when needed

### Issue 3: old JIT image leak and kallsyms/extable refresh

- The pre-recompile binary-pack header is captured before publication and freed after the RCU grace period.
- `search_bpf_extables()` now consults extable metadata carried by the matched BPF ksym entry, so old and new images can both resolve faults during the handoff window.
- Recompile adds a temporary shadow ksym for the new image, then after the grace period:
  - deletes the old canonical ksym
  - re-adds the canonical ksym for the new image
  - drops the shadow ksym

### Issue 4: rollback and staged artifact cleanup

- Rollback snapshots now include:
  - `jit_data`
  - a copy of each program's mutable `insnsi`
  - live pointer / extable / JIT state
- Failed recompiles now abort staged x86 JIT state, free staged binary-pack allocations, free staged private stacks when newly allocated, and restore the saved instruction stream and live program state.
- The restore path now runs for failed recompiles even when userspace did not request policy rollback, so the live image is not left partially mutated.

### Issue 5: masked 32-bit ROTATE validator

- Masked 32-bit rotate validation now rejects `AND_X` forms entirely.
- For `AND_K`, the validator now requires the immediate mask to exactly match the expected low-bits mask `(1U << (32 - N)) - 1` or its complementary upper-bits mask.
- Arbitrary non-zero masks no longer validate as ROTATE.

## Extra safety cleanup

- `bpf_throw()` now reads `bpf_exception_cb` through `READ_ONCE()` and warns if it is unexpectedly missing.
- `recompile_count` was saturated to avoid silent `u32` wraparound while touching the same path.

## Validation

Build:

```sh
make -C vendor/linux-framework -j$(nproc) bzImage
```

Result:

- Success
- Built image: `vendor/linux-framework/arch/x86/boot/bzImage`

VM smoke:

```sh
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "uname -r && cat /proc/version"
```

Result:

- `7.0.0-rc2-g05a1845490ed-dirty`
- `Linux version 7.0.0-rc2-g05a1845490ed-dirty ... #33 SMP PREEMPT_DYNAMIC Thu Mar 12 19:57:34 PDT 2026`

Notes:

- `vng` printed a warning that `modules.order` was not present because kernel modules are disabled in this build, but the guest booted and executed the smoke command successfully.

# Trampoline Regeneration + ROTATE Fix + Cleanup

Date: 2026-03-19

## Scope

Task #263 combined three kernel-side items:

1. Trampoline regeneration after `BPF_PROG_JIT_RECOMPILE`
2. P1 masked `ROTATE` tightening
3. P2 trampoline dead-code cleanup

## Implementation

### 1. Trampoline regeneration

Files:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/include/linux/bpf.h`

Key changes:

- Kept the refresh in the commit path before old-image retirement, so the existing `synchronize_rcu()` still protects old text from being freed while a trampoline could still reach it.
- Recompile now calls `bpf_prog_regenerate_trampolines(prog, old_prog_func)` after the new JIT image is committed.
- Refresh covers:
  - attached tracing programs (`fentry`/`fexit`/`LSM`) by rebuilding the trampoline image
  - target-side trampoline retargeting when the recompiled program is the trampoline target
  - freplace target repoke via `bpf_arch_text_poke()`
  - attached freplace program retargeting via `JUMP -> JUMP` repoke
- The target-side regular-trampoline case needed an extra fix discovered during VM validation:
  - simply changing `tr->func.addr` and calling `bpf_trampoline_update()` was wrong
  - the new target entry still has `NOP`, not the old trampoline call
  - fixed by treating the new target entry as a fresh registration site while retiring the old trampoline image separately

Failure semantics:

- Trampoline refresh failure no longer aborts the recompile.
- The kernel logs a warning and keeps the old JIT text resident instead of freeing potentially still-reachable old images.
- This preserves safety at the cost of a leak on the warning path.

### 2. Masked ROTATE validator

Files:

- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `tests/kernel/progs/test_rotate_masked_low.bpf.c`
- `tests/kernel/test_recompile.c`

Status:

- The kernel-side matcher in the current vendor worktree is now high-mask-only (`mask == high_mask`).
- I added a dedicated negative selftest so the low-mask non-rotate sequence is locked out by test coverage.

New selftest:

- `Rotate Low-Mask Rejected`
- Program shape:
  - `mov64 tmp, src`
  - `and64 tmp, low_mask`
  - `rsh64 tmp, 32-N`
  - `lsh64 src, N`
  - `or64 src, tmp`
- Expected result: policy rejected with `-EINVAL`

### 3. P2 trampoline cleanup

Files:

- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/include/linux/bpf.h`

Cleanup:

- Removed dead `bpf_prog_has_active_trampoline()` declaration/implementation left over from the earlier trampoline guard.

## Selftests

Updated userspace selftest:

- Added `tests/kernel/progs/test_trampoline_fentry.bpf.c`
- Reworked `Recompile After Attach Works` into a real trampoline case:
  - attach a live `fentry` program to `test_simple`
  - recompile the attached `fentry` program
  - recompile the target XDP program
  - verify the `fentry` counter still fires after both recompiles

This exercises both:

- attached-program trampoline regeneration
- target-program trampoline retargeting

## Validation

### Build

- `make -C vendor/linux-framework -j$(nproc) bzImage`: PASS

### VM selftest

- `make vm-selftest`: PASS (`25/25`)

New/changed checks that passed:

- `Rotate Low-Mask Rejected`
- `Recompile After Attach Works` (now a live `fentry` attach/regenerate test)

### VM micro smoke

- `make vm-micro-smoke`: PASS

Observed smoke output:

- `simple`: PASS
- `load_byte_recompose`: PASS
- `cmov_dense`: PASS

## Runtime bug found during validation

First VM run failed the new `fentry` test after recompiling the target program:

- symptom: target program still ran, but `fentry` count dropped to `0`
- root cause: target-side regeneration tried to `modify` the new target entry as if it already contained the old trampoline call
- fix: add a target-retarget helper that registers the trampoline on the new target entry as a fresh site and retires the old trampoline image separately

Second VM run passed `25/25`.

## Residual follow-up

Not completed in this task:

- scanner masked-rotate acceptance is still broader than the kernel validator
- this remains the leftover part of task #247

Also still missing dedicated selftest coverage:

- freplace-specific regeneration path
- LSM-specific regeneration path

The common regular-trampoline path and target-side retarget path are now covered by the new `fentry` selftest.

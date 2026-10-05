# Trampoline Leak Fix

Date: 2026-03-20

## Summary

Fixed the `P2` leak in `vendor/linux-framework/kernel/bpf/jit_directives.c` on the post-commit trampoline regeneration warning path.

Before the fix:
- `keep_old_images = true` was set when `bpf_prog_regenerate_trampolines()` failed.
- The subsequent cleanup skipped `bpf_jit_binary_pack_free(old_headers[i], NULL)` and `free_percpu(old_priv_stacks[i])` behind `!keep_old_images`.
- Those saved old allocations were then lost permanently.

After the fix:
- The existing `synchronize_rcu()` still runs after commit.
- If `keep_old_images` is set, a second `synchronize_rcu()` runs before reclamation.
- Old JIT images and old private stacks are then freed unconditionally on the normal cleanup path.

## Rationale

The first grace period covers the normal post-commit image swap. The second grace period is only needed when trampoline regeneration failed and old trampoline text may still transiently reference the previous JIT image. After that extra wait, the captured old image headers and private stacks can be reclaimed safely.

## Verification

- `make -C vendor/linux-framework -j$(nproc) bzImage` : passed
- `make vm-selftest` : passed, `35/35` tests
- `make vm-micro-smoke` : passed

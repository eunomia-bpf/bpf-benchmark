# LivePatchPass Review Report

Date: 2026-03-26

## Scope

Reviewed:

- `daemon/src/passes/live_patch.rs`
- `daemon/src/passes/mod.rs`

Focused on:

- null guard insertion
- helper arg sanitization
- pointer refresh
- tail-call isolation
- branch fixup after insertion
- pass registration order

## Findings

### 1. Fixed: `live_patch` was not the last registered pass

`daemon/src/passes/mod.rs` still placed `dangerous_helper_firewall` after `live_patch`, which violated the design requirement that live patching run last so earlier optimization/security passes cannot invalidate its inserted hardening.

Fix:

- moved `live_patch` to the final `PASS_REGISTRY` slot
- updated the pipeline regression to assert `live_patch` is last

### 2. Fixed: pointer refresh could reuse a ctx-save register that had already been clobbered

The original backward scan accepted the first earlier `mov r6-9, r1` without checking whether that callee-saved register had been overwritten before the helper call.

That could produce an invalid rewrite like:

```text
r9 = r1
r9 = 0
call bpf_xdp_adjust_head
; patched reload incorrectly reads packet roots from r9
```

Fix:

- made the backward ctx-save search clobber-aware
- if the saved ctx register is no longer valid at the helper call, the pass now inserts a fresh ctx save before the call
- added regression test `test_pointer_refresh_reinserts_ctx_save_when_saved_ctx_was_clobbered`

### 3. Fixed: pointer refresh could match packet roots that were no longer live roots at the helper

The original packet-root scan searched backward for `ctx->data` / `ctx->data_end` loads but did not reject roots that had been overwritten before the helper call.

That allowed a misrewrite where a later non-packet scalar in the same register was treated as stale packet data and rewritten as if it were still recoverable from ctx.

Fix:

- made packet-root discovery clobber-aware
- allowed root loads sourced from either `r1` or a still-valid saved ctx register
- added regression test `test_pointer_refresh_skips_when_packet_root_was_clobbered_before_helper`

### 4. Fixed: null-guard matching missed non-stack store dereferences

Null guarding only recognized `LDX` dereferences. A store through a maybe-null helper return, such as `stx [r6+off], rX`, remained unguarded.

Fix:

- generalized dereference detection to cover non-stack `LDX`, `ST`, and `STX`
- added regression test `test_null_guard_insertion_for_store_deref`

## Edge Cases Checked

- Helper arg sanitization remains limited to the intended helper set and only inserts `mov rA, 0` immediately before the helper call.
- Tail-call isolation remains a one-instruction replacement (`r0 = 0`), so no branch-offset repair is needed there.
- Branch repair after inserted guards still works; the existing `test_branch_fixup_after_insertion` passed after the rewrite changes.
- The pointer-refresh rewrite still rebuilds the dominating bounds guard and exits through the shared safe-exit epilogue.

## Test Results

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml live_patch
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Observed:

- `cargo test ... live_patch`: passed, `14 passed, 0 failed`
- full `cargo test`: passed, `430 passed, 0 failed, 12 ignored`

## Notes

- No remaining correctness blocker was found in the reviewed Phase-1 scope.
- The current implementation still intentionally skips more complex packet-pointer recovery cases such as dynamic-offset derived roots; that matches the design document rather than this review uncovering a regression.

# LivePatchPass Implementation Report

Date: 2026-03-26

## Scope

Implemented `LivePatchPass::run()` in `daemon/src/passes/live_patch.rs` to satisfy the TDD contract for the phase-1 live patch pass.

The implementation applies four patch templates:

1. Null guard insertion
   - Tracks helper-returned `PTR_OR_NULL` values derived from `bpf_map_lookup_elem()`.
   - Detects first unguarded `LDX_MEM` dereference on the derived register.
   - Inserts `if reg == 0 goto shared_safe_exit`.

2. Helper argument sanitization
   - Matches a bounded set of dangerous helper IDs (`probe_read*`, `probe_write_user`, `copy_from_user`).
   - Inserts `mov64_imm(arg_reg, 0)` before the helper call when the argument is not already zeroed in the local linear window.

3. Pointer refresh
   - Matches `changes_pkt_data` helpers currently covered by v1 (`xdp_adjust_head`, `skb_store_bytes`).
   - Finds stale packet-pointer use shortly after the helper.
   - Reuses an existing saved ctx register when present, otherwise saves `r1` into a dead callee-saved register.
   - Reloads `data` / `data_end` and rebuilds a bounds guard before the stale access.

4. Tail-call isolation
   - Replaces `call bpf_tail_call` with `mov64_imm(r0, 0)` to force the edge to fail closed while preserving the fallthrough path.

## Rewrite Strategy

- Scanning is done against the original instruction stream.
- Rewrites are applied in one combined pass using:
  - pre-insertions
  - post-insertions
  - in-place replacements
- A shared safe-exit block is appended once when needed:
  - `r0 = 0`
  - `exit`
- Original branch offsets are repaired with `fixup_all_branches()`.
- Newly inserted fail-closed jumps are patched to the shared safe-exit block after layout is finalized.
- `PassResult.diagnostics` now reports each applied patch site.

## Validation

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml live_patch
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `live_patch` tests: 10 passed, 0 failed
- full daemon test suite: 427 passed, 0 failed, 12 ignored

## Current v1 Limits

- `PTR_OR_NULL` matching is intentionally narrow and currently keyed to `bpf_map_lookup_elem()`.
- Helper sanitization uses a fixed helper-ID table and zeroes argument register `r2` for the supported helpers.
- Pointer refresh is limited to local linear windows and currently only supports direct packet-root reload patterns with constant-width accesses.
- The pass skips branch-targeted pre-insertion sites instead of trying to retarget incoming edges to newly inserted guards.

# DangerousHelperFirewallPass Review Report

Date: 2026-03-26

## Scope

Reviewed:

- `daemon/src/passes/dangerous_helper_firewall.rs`
- `daemon/src/passes/mod.rs`

Focused on:

- deny correctness for helper IDs `58`, `109`, `117`
- coarseify correctness for helper ID `5 -> 160`
- audit-only behavior for helper ID `113`
- cleanup safety
- registry ordering

## Findings

### 1. Fixed: cleanup could delete still-live `r1` setup

The original cleanup walk used `branch_targets` but ignored `liveness`, even though the pass declared it as a required analysis.

That allowed this bad case:

```text
mov64 r1, 7
call bpf_send_signal
... later use r1 ...
```

If the call was rewritten to `mov64 r0, -1`, the old cleanup logic could still delete the `mov64 r1, 7` setup. That is not semantics-preserving once the helper call disappears.

Fix:

- gate cleanup on `liveness.live_out[call_pc]`
- if `r1` is still live after the call site, skip cleanup entirely for that arg
- added regression test `test_cleanup_does_not_remove_live_arg_setup`

### 2. Fixed: helper ID `191` was missing from the audit table

Corpus statistics and the helper inventory both include `copy_from_user_task` (`191`) as part of the dangerous helper surface, but the pass never matched it.

Fix:

- added `BPF_FUNC_COPY_FROM_USER_TASK`
- audit it as `copy_from_user_task`
- added regression test `test_copy_from_user_task_audit_only`

### 3. Fixed in working tree: firewall ordering was no longer last

With the current working-tree `live_patch` registry edits, `dangerous_helper_firewall` was no longer the final pass even though the design requires it to run last.

Fix in the working tree:

- reordered the registry so `dangerous_helper_firewall` comes after `live_patch`
- added regression test `test_default_pipeline_ends_with_dangerous_helper_firewall`

## Edge Cases Checked

- No arg setup before a denied helper call is already handled safely: the call is rewritten in place and cleanup deletes nothing.
- Audit-only helper sites do not mutate bytecode and are reported through `sites_skipped` plus `diagnostics`.
- `ktime_get_ns` coarseify keeps opcode/register/offset fields unchanged and rewrites only helper ID `5 -> 160`.
- The deny rewrite remains `mov64 r0, -1` for `override_return`, `send_signal`, and `send_signal_thread`.

## Test Results

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml dangerous_helper
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Observed:

- `cargo test ... dangerous_helper`: passed, `13 passed, 0 failed`
- full `cargo test`: failed in unrelated `passes::live_patch::*` tests already present in the current working tree

Additional isolation run:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml -- --skip passes::live_patch::
```

Result:

- passed, `417 passed, 0 failed, 12 ignored`

## Notes

- The current workspace contains unrelated `live_patch` changes, including untracked `daemon/src/passes/live_patch.rs`.
- Committing `daemon/src/passes/mod.rs` together with those unrelated `live_patch` registry edits would also require deciding whether that new pass belongs in the same commit.

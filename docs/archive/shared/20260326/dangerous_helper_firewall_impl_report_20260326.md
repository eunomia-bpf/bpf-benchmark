# DangerousHelperFirewallPass Implementation Report

Date: 2026-03-26

## Scope

Implemented `DangerousHelperFirewallPass::run()` in:

- `daemon/src/passes/dangerous_helper_firewall.rs`

The pass now performs the Phase-1 helper firewall actions described in the design:

- `deny`: replace dangerous regular helper calls with `mov64 r0, -1`
- `coarseify`: rewrite `ktime_get_ns` helper ID `5` to `ktime_get_coarse_ns` helper ID `160`
- `audit`: record dangerous read-style helpers in `sites_skipped` and `diagnostics` without modifying bytecode

## Implemented Behavior

### 1. Fail-closed deny rewrites

Regular helper calls (`BPF_CALL` with `src_reg == 0`) are denied for:

- `override_return` (`58`)
- `send_signal` (`109`)
- `send_signal_thread` (`117`)
- `set_retval` (`187`)

Each matching call is replaced with:

```rust
BpfInsn::mov64_imm(0, -1)
```

This preserves instruction width and provides a verifier-friendly scalar error return.

### 2. Coarseify rewrite

For:

- `ktime_get_ns` (`5`)

the pass rewrites the helper ID in-place to:

- `ktime_get_coarse_ns` (`160`)

No calling-convention change is introduced.

### 3. Audit-only handling

The pass audits, but does not rewrite, these helpers:

- `probe_read` (`4`)
- `probe_read_str` (`45`)
- `probe_read_user` (`112`)
- `probe_read_kernel` (`113`)
- `probe_read_user_str` (`114`)
- `probe_read_kernel_str` (`115`)
- `probe_write_user` (`36`)
- `skb_store_bytes` (`9`)
- `skb_change_tail` (`38`)
- `skb_adjust_room` (`50`)
- `xdp_adjust_head` (`44`)
- `xdp_adjust_tail` (`65`)
- `jiffies64` (`118`)
- `ktime_get_boot_ns` (`125`)
- `d_path` (`147`)
- `copy_from_user` (`148`)
- `copy_from_user_task` (`191`)
- `snprintf_btf` (`149`)
- `find_vma` (`180`)
- `xdp_store_bytes` (`190`)

Audit hits are emitted as:

- `PassResult.sites_skipped`
- `PassResult.diagnostics`

If a program only hits audit-only helpers, `changed == false`.

### 4. Conservative arg-setup cleanup

For denied signal helpers, the pass also performs a conservative backward cleanup of trivial arg-setup chains for `r1` when safe:

- only within the same basic block
- never across branch targets
- never across control-flow instructions
- never when liveness shows `r1` is still live after the rewritten call site
- only for simple setup/update forms:
  - `mov64_imm`
  - `mov64_reg`
  - `ldimm64`
  - `alu64 add/sub imm`

When cleanup removes instructions, the pass rebuilds the instruction stream and runs branch-offset fixup via `fixup_all_branches()`.

This is what makes the branch-fixup TDD case pass.

### 5. Pipeline ordering

In the current working tree, `dangerous_helper_firewall` is kept last in the pass registry and a regression test asserts that invariant.

## Verification

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml dangerous_helper
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- Focused firewall tests: `13 passed, 0 failed`
- Full daemon test suite on the current workspace: failed in unrelated `passes::live_patch::*` tests
- Full daemon test sweep excluding unrelated `live_patch` tests: `417 passed, 0 failed, 12 ignored`

## Notes

- The unrelated `live_patch` worktree changes were not part of the firewall review scope.

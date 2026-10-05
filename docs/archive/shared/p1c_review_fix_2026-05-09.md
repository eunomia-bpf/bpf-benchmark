# P1-C independent review + fix

Date: 2026-05-09

## Verdict

Pass after fix.

The prior P1-C merge satisfied the design split but violated the explicit LOC gate:

```text
before this review: 27 files changed, 1678 insertions(+), 1509 deletions(-)
net: +169
```

This review fixed the LOC regression without restoring `passes/utils.rs`, without adding compatibility wrappers, and without changing kop emit bytes.

Final required scoped LOC check:

```text
git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src
27 files changed, 1546 insertions(+), 1567 deletions(-)
net: -21
```

## Issues Fixed

1. **P1-C LOC gate failure**
   - Problem: current diff was net +169 LOC, violating the task requirement.
   - Fix: removed duplicated logic and repeated fixtures instead of reverting P1-C:
     - `bpfopt/crates/bpfopt/src/passes/dce.rs:268` now reuses `rewrite::fixup_all_branches`.
     - `bpfopt/crates/bpfopt/src/pass.rs:1291` inlines the one-call registry index helpers.
     - `bpfopt/crates/bpfopt/src/main.rs:1190` adds a compact kop-target test fixture helper.

2. **Duplicate branch fixup after `utils.rs` split**
   - Problem: `dce.rs` carried a local `fixup_surviving_branches` implementation duplicating the moved `rewrite::fixup_all_branches` logic.
   - Fix: removed the local duplicate and call `fixup_all_branches(&mut new_insns, insns, &addr_map)` at `bpfopt/crates/bpfopt/src/passes/dce.rs:268`.
   - Coverage: existing DCE tests still cover helper-call reserved fields, LD_IMM64 pair deletion, and cascading dead-def removal.

3. **Redundant `KopRegistry` helper wrappers**
   - Problem: the atomic call setter had three private one-call helpers, including a duplicated collision check.
   - Fix: `set_kop_call_for_descriptor` now performs final-key collision checking, old-key removal, and insertion directly at `bpfopt/crates/bpfopt/src/pass.rs:1311`.
   - Semantics preserved: duplicate detection is still on the final `(btf_id, call_off)` key.

4. **Repeated target JSON test fixtures**
   - Problem: the P1-B/P1-C regression tests repeated large `TargetJson` literals.
   - Fix: added `kop_target()` and `registered_call_name()` helpers at `bpfopt/crates/bpfopt/src/main.rs:1190` and rewrote the duplicate-BTF tests to use them.
   - Test count is unchanged.

## Design Checks

- `bpfopt/crates/bpfopt/src/passes/utils.rs` is deleted.
- No `bpfopt/crates/bpfopt/src/passes/utils/` directory exists.
- Removed wrappers remain absent: `resolve_kop_call_off_for_target`, `resolve_kop_call_off_for_pass`, `target_name_for_pass`.
- `KopRegistry::is_target_available` exists at `bpfopt/crates/bpfopt/src/pass.rs:1252` and callers use it for availability checks.
- `btf_id_for_target_name` returns `anyhow::Result<i32>` at `bpfopt/crates/bpfopt/src/pass.rs:1236`.
- KOperation proof dispatch still reads both `btf_id` and `call_off` from bytecode at `bpfopt/crates/bpfopt/src/pass.rs:410` and resolves through `lookup_by_kop_call` at `bpfopt/crates/bpfopt/src/pass.rs:442`.
- `remap_btf_metadata` / `remap_kop_btf_metadata` live in `pass.rs`; branch/map rewrite helpers live in `passes/rewrite.rs`; DCE helpers live in `passes/dce.rs`; instruction emit helpers live in `insn.rs`.

## Compliance Checks

Commands returned no matches:

```text
rg -n "resolve_kop_call_off_for_target|resolve_kop_call_off_for_pass|target_name_for_pass|kop_registered_for_target_name|lookup_by_btf_id|set_btf_id_for_target_name|set_call_off_for_target_name" bpfopt/crates/bpfopt/src daemon/src
rg -n "#\[allow\(dead_code\)\]|unwrap_or_default|\.ok\(\)|let _ = " bpfopt/crates/bpfopt/src daemon/src
find bpfopt/crates/bpfopt/src/passes -maxdepth 2 \( -name utils.rs -o -type d -name utils \) -print
```

No commit was created. I did not modify `vendor/linux-framework`, `runner`, `e2e`, `micro`, or `daemon/src`. The worktree already contains corpus result additions and a dirty `docs/paper` submodule outside this fix; I left them untouched.

`git log -10 --oneline` shows no new revert/restore commit from this work.

## Bytecode Identity

The emit path remains byte-identical by static inspection:

- `emit_packed_kop_call_with_off` still emits exactly `BpfInsn::kop_sidecar(payload)` followed by `BpfInsn::call_kop_with_off(kop_btf_id, kop_off)` at `bpfopt/crates/bpfopt/src/insn.rs:534`.
- `BpfInsn::kop_sidecar` and `BpfInsn::call_kop_with_off` were not changed by this review.
- The seven kop pass emit call sites were not changed by this review; they still obtain the same runtime BTF ID and call offset from `KopRegistry`.
- The registry cleanup only removed internal helper wrappers around the same final `(btf_id, call_off)` index update.
- The DCE cleanup reuses the same branch fixup implementation already used by `RewritePlan::commit`; it changes no instruction construction for kop lowering.
- `RewritePlan::commit` branch/addr-map logic remains in `bpfopt/crates/bpfopt/src/passes/rewrite.rs` and was not semantically changed by this review.

## Verification

Allowed commands run:

```text
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/bpfopt && cargo test --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked
```

Results:

```text
bpfopt cargo build: pass
bpfopt cargo test:  pass
  lib tests:        335 passed
  main tests:       16 passed
  cli tests:        12 passed
daemon cargo build: pass
daemon cargo test:  pass
  daemon tests:     25 passed
total:              388 passed
```

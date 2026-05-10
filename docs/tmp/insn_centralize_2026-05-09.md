# insn.rs Centralization Report (2026-05-09)

## Scope

Centralized single-instruction BPF construction, classification, and sidecar decode helpers under `bpfopt/crates/bpfopt/src/insn.rs` `impl BpfInsn`.

No runner, corpus, micro, e2e, daemon syscall, or rewrite-builder design files were changed.

## Round 1: Constructors / Decoders Moved

| Old location | New location | Caller rewrite | Callers |
|---|---|---:|---:|
| `test_helpers.rs::pseudo_call_to` | `BpfInsn::pseudo_call_to` | `pseudo_call_to(...)` -> `BpfInsn::pseudo_call_to(...)` | 4 |
| `test_helpers.rs::ld_imm64` | `BpfInsn::ld_imm64` | `ld_imm64(...)` -> `BpfInsn::ld_imm64(...)` | 66 |
| `test_helpers.rs::add64_imm` | `BpfInsn::add64_imm` | `add64_imm(...)` -> `BpfInsn::add64_imm(...)` | 104 |
| `test_helpers.rs::jeq_imm` | `BpfInsn::jeq_imm` | `jeq_imm(...)` -> `BpfInsn::jeq_imm(...)` | 53 |
| `test_helpers.rs::jne_imm` | `BpfInsn::jne_imm` | `jne_imm(...)` -> `BpfInsn::jne_imm(...)` | 34 |
| `test_helpers.rs::jgt_reg` | `BpfInsn::jgt_reg` | `jgt_reg(...)` -> `BpfInsn::jgt_reg(...)` | 4 |
| `test_helpers.rs::sidecar_payload` | `BpfInsn::sidecar_payload` | `sidecar_payload(&insn)` -> `insn.sidecar_payload()` | 11 |
| `skb_load_bytes_tests.rs::helper_call` | existing `BpfInsn::helper_call` | `helper_call(...)` -> `BpfInsn::helper_call(...)` | 11 |
| `map_inline_tests.rs::ja` | existing `BpfInsn::ja` | `ja(...)` -> `BpfInsn::ja(...)` | 8 |

Additional same-class thin wrappers removed:

| Old location | New location | Caller rewrite | Callers |
|---|---|---:|---:|
| `rotate_tests.rs::alu32_imm` | `BpfInsn::alu32_imm` | `alu32_imm(...)` -> `BpfInsn::alu32_imm(...)` | 10 |
| `rotate_tests.rs::alu32_reg` | `BpfInsn::alu32_reg` | `alu32_reg(...)` -> `BpfInsn::alu32_reg(...)` | 5 |
| `endian_tests.rs::endian_to_be` | `BpfInsn::endian_to_be` | `endian_to_be(...)` -> `BpfInsn::endian_to_be(...)` | 34 |
| `prefetch_tests.rs::map_lookup_call` | existing `BpfInsn::helper_call` | `map_lookup_call()` -> `BpfInsn::helper_call(HELPER_MAP_LOOKUP_ELEM)` | 2 |
| `bounds_check_merge_tests.rs::jge_reg` | existing `BpfInsn::jump_reg` | `jge_reg(...)` -> `BpfInsn::jump_reg(BPF_JGE, ...)` | 1 |

`test_helpers.rs` now keeps fixture/state setup helpers only.

## Round 2: Generic Predicate Cleanup

| Removed helper | Replacement | Callers |
|---|---|---:|
| `cond_select.rs::is_mov64` | `insn.is_mov64_reg() || insn.is_mov64_imm()` inside `is_select_mov` | 1 |
| `map_inline.rs::is_mov64_reg` | `insn.is_mov64_reg()` | 1 |
| `const_prop.rs::is_reg_to_reg_mov` | `insn.is_mov64_reg() || insn.is_mov32_reg()` | 2 |
| `map_inline.rs::is_pseudo_map_fd_src` | inline `src == BPF_PSEUDO_MAP_FD || src == BPF_PSEUDO_MAP_IDX` | 2 |
| `map_inline.rs::is_pseudo_map_value_src` | inline `src == BPF_PSEUDO_MAP_VALUE || src == BPF_PSEUDO_MAP_IDX_VALUE` | 1 |
| `map_inline/map_info.rs::is_map_reference_src` | inline `src == BPF_PSEUDO_MAP_FD || src == BPF_PSEUDO_MAP_IDX` | 1 |

Pass-specific predicates from the task boundary were left unchanged.

## LOC Delta

`git diff --shortstat HEAD -- bpfopt/crates/bpfopt/src daemon/src`:

`24 files changed, 453 insertions(+), 470 deletions(-)` => net `-17`.

| File | Before | After | Delta |
|---|---:|---:|---:|
| `bpfopt/crates/bpfopt/src/analysis/branch_target_tests.rs` | 60 | 60 | 0 |
| `bpfopt/crates/bpfopt/src/analysis/liveness_tests.rs` | 114 | 114 | 0 |
| `bpfopt/crates/bpfopt/src/insn.rs` | 491 | 538 | +47 |
| `bpfopt/crates/bpfopt/src/test_helpers.rs` | 148 | 108 | -40 |
| `bpfopt/crates/bpfopt/src/passes/cond_select.rs` | 611 | 607 | -4 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs` | 833 | 827 | -6 |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 5502 | 5494 | -8 |
| `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` | 584 | 583 | -1 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs` | 392 | 382 | -10 |
| `bpfopt/crates/bpfopt/src/passes/branch_flip_tests.rs` | 489 | 489 | 0 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 548 | 548 | 0 |
| `bpfopt/crates/bpfopt/src/passes/ccmp_tests.rs` | 216 | 215 | -1 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 482 | 496 | +14 |
| `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs` | 384 | 410 | +26 |
| `bpfopt/crates/bpfopt/src/passes/dce_tests.rs` | 50 | 50 | 0 |
| `bpfopt/crates/bpfopt/src/passes/endian_tests.rs` | 541 | 535 | -6 |
| `bpfopt/crates/bpfopt/src/passes/extract_tests.rs` | 511 | 511 | 0 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 3145 | 3141 | -4 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 294 | 294 | 0 |
| `bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs` | 173 | 163 | -10 |
| `bpfopt/crates/bpfopt/src/passes/rotate_tests.rs` | 444 | 436 | -8 |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs` | 358 | 353 | -5 |
| `bpfopt/crates/bpfopt/src/passes/utils.rs` | 1532 | 1531 | -1 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs` | 606 | 606 | 0 |
| touched total | 18508 | 18491 | -17 |

`daemon/src` had no file changes.

## Verification

Commands run:

```sh
cargo build --workspace --locked
cargo test --workspace --locked 2>&1 | tail -40
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo build --workspace --locked
cd /home/yunwei37/workspace/bpf-benchmark/daemon && cargo test --workspace --locked 2>&1 | tail -20
```

Results:

| Suite | Result | Test count |
|---|---|---:|
| `bpfopt` build | passed | n/a |
| `bpfopt` tests | passed | 356 |
| `daemon` build | passed | n/a |
| `daemon` tests | passed | 25 |
| total listed tests | passed | 381 |

The test counts came from `cargo test --workspace --locked -- --list | rg -c ': test$'` in each workspace.

## CLAUDE.md Compliance Self-Check

- No ReJIT filtering, benchmark policy, result aggregation, runner, corpus, micro, e2e, or daemon syscall behavior changed.
- Existing ABI-view const aliases and the existing 18 `BpfInsn` constructors were kept.
- No hardcoded BTF IDs, helper-number aliases, revert/restore commits, benchmark runs, or commits were introduced.
- `bpfopt/crates/bpfopt/src/passes/rewrite.rs` was not changed.
- Forbidden-pattern check did not increase: both HEAD and current tree have zero matches for `#[allow(dead_code)]`, `unwrap_or_default`, `let _ = `, or `.ok()` under `bpfopt/crates/bpfopt/src daemon/src`.

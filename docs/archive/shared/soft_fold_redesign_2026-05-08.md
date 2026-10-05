# Soft Fold Redesign 2026-05-08

## LOC

Code/config diff before this report:

- Deleted: 287 LOC
- Added: 127 LOC
- Breakdown: `map_inline.rs` -280/+105, `map_inline_tests.rs` -3/+18, `katran.yaml` -4/+4

## Core Change

Soft hints no longer emit a stack const blob or preserve a fallback
`bpf_map_lookup_elem` call. The rewrite now resolves the original direct
`if r0 == 0` null handler, emits a key PIC chain at the lookup call, folds
each hit into scalar constant loads, and sends all misses through `r0 = 0`
followed by a jump to the existing null handler.

```rust
let null_handler = find_soft_fold_null_handler(&program.insns, site.call_pc)
    .ok_or_else(|| site_level_inline_veto("soft fold not applicable: missing null handler"))?;

for hint in hints {
    let mismatch_jumps = emit_key_compare_to_hint(&hint.key, &mut replacement)?;
    for load in &uses.fixed_loads {
        let scalar = read_scalar_from_value(&hint.inline_value, load.offset, load.size)
            .ok_or_else(|| site_level_inline_veto(...))?;
        replacement.extend(emit_constant_load(load.dst_reg, scalar, load.size));
    }
    branch_patches.push(ReplacementBranchPatch {
        replacement_pc: site.call_pc,
        replacement_insn_idx: replacement.len(),
        target_old_pc: null_handler.non_null_pc,
    });
    replacement.push(BpfInsn::ja(0));
    ...
}

replacement.push(BpfInsn::mov64_imm(0, 0));
branch_patches.push(ReplacementBranchPatch {
    replacement_pc: site.call_pc,
    replacement_insn_idx: replacement.len(),
    target_old_pc: null_handler.null_handler_pc,
});
replacement.push(BpfInsn::ja(0));
```

The old soft-only helpers for stack blob allocation/materialization were
removed.

## Verification

Commands run from `bpfopt/`:

```text
cargo fmt --check -p bpfopt
```

Passed.

```text
cargo test -p bpfopt
```

Passed:

- lib tests: 319 passed
- bin tests: 9 passed
- cli tests: 11 passed
- doctests: 0 passed

The new focused unit test is
`map_inline_soft_map_name_hint_emits_key_check_scalar_fold_without_fallback`;
it verifies key check emission, scalar fold emission, miss-to-null jump shape,
and absence of fallback `bpf_map_lookup_elem`.

## Boundaries

- Missing direct `BPF_JEQ r0, 0` null check after lookup: skip with
  `soft fold not applicable: missing null handler`.
- Lookup result has pointer/non-scalar use: skip with
  `soft fold not applicable: lookup result has non-scalar use`.
- Removed lookup/null/load instructions crossing a branch target: skip the site
  rather than keeping a fallback lookup path.
- Soft hints for map-in-map outer lookups remain unsupported.
- Katran `vip_map` hint is now the requested soft form:
  `--inline-hint=vip_map:0a6401010000000000000000000000001f900600`.

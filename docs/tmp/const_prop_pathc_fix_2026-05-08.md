# const_prop Path C verifier post-state guard fix, 2026-05-08

## Changed files and LOC

Rust code/test diff before this note:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`: +274 / -45
- `bpfopt/crates/bpfopt/src/passes/dce.rs`: +39 / -0, test fixture only
- `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`: +56 / -25, test fixture only

Total Rust diff: +369 / -70.

Completion note:

- `docs/tmp/const_prop_pathc_fix_2026-05-08.md`: +95 / -0 before this line-count update

No `map_inline.rs` changes. No kernel changes. No corpus benchmark run.

## Key guard implementation

`VerifierExactConstOracle` now records verifier post-state scalar exact observations separately from the propagation facts. A replacement is allowed only when every retained verifier visit for the PC/frame/dst proves the same scalar exact value:

```rust
fn post_state_proves_scalar_exact(
    &self,
    pc: usize,
    frame: usize,
    dst: u8,
    value: i64,
    width: VerifierValueWidth,
) -> bool {
    self.scalar_post_states
        .get(&(pc, frame, dst))
        .is_some_and(|state| state.matches(value, width))
}
```

`fold_alu_instruction()` now routes both local abstract-state candidates and oracle-derived candidates through that guard before emitting `MOV K` / `LD_IMM64`:

```rust
if !oracle.post_state_proves_scalar_exact_in_context(
    pc,
    frame,
    insn.dst_reg(),
    result as i64,
    width,
) {
    return AluFoldDecision::Skip(SkipReason {
        pc,
        reason: VERIFIER_POST_STATE_NOT_SCALAR_EXACT.to_string(),
    });
}

AluFoldDecision::Replace(candidate)
```

Skip-only runs now return `sites_skipped` with reason `verifier post-state is not scalar-exact`, so the CLI summary's `skip_reasons` naturally includes it.

## Test coverage

- Negative regression: `const_prop_post_state_guard_rejects_packet_pointer_copy_materialization`
  - Local state wants to fold `r7 = r1` to `r7 = 62`.
  - Verifier post-state says `R7` is `pkt`.
  - Pass skips the site, records the guard reason, and leaves bytecode unchanged.
- Positive regression: `const_prop_post_state_guard_allows_scalar_exact_register_copy`
  - Local state wants the same register-copy materialization.
  - Verifier post-state says `R7` is scalar exact `62`.
  - Replacement succeeds.
- Existing const_prop oracle tests still cover multi-visit agreement, missing observation, full-state omission, and cross-frame disagreement.
- Cross-pass test fixtures were updated to model the v3 daemon boundary: run `map_inline`, then install synthetic const_prop verifier post-state, then run `const_prop` / `dce`.

## Test output

Command:

```bash
cargo test -p bpfopt
```

Result:

```text
test result: ok. 318 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
Doc-tests bpfopt: 0 passed; 0 failed
```

## Known boundary cases

- Missing PC/frame/dst in verifier states fails closed: the replacement is skipped with `verifier post-state is not scalar-exact`.
- Any observed non-scalar verifier type (`pkt`, `map_value`, `ctx`, `fp`) or scalar non-exact state fails closed.
- Multiple retained visits at the same PC/frame/dst must all observe the same scalar exact value and compatible width; disagreement fails closed.
- Context-insensitive simulation (`frame = None`) requires all frames observed for that PC to prove the same scalar exact post-state.
- `VerifierValueWidth::Unknown` is accepted only as a compatibility case for current JSON-normalized verifier states that preserve scalar exact value but not the raw `_w` suffix; known `Bits32` / `Bits64` states are matched strictly.

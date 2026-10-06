# const_prop Path C post-state guard simplification, 2026-05-08

## LOC and deleted paths

`bpfopt/crates/bpfopt/src/passes/const_prop.rs` went from 1323 lines to 1267 lines: net -56 LOC.

Current diff for that file:

```text
47 insertions(+), 103 deletions(-)
```

Deleted from the verifier post-state guard path:

- the all-state `scalar_post_states` table populated from every non-branch verifier state
- `OracleExactAccumulator::scalar_post_state` and `into_scalar_post_state()`
- the old `post_state_proves_scalar_exact*()` guard that could use `PcFullState` / `EdgeFullState`
- the #252 second guard table names `insn_scalar_post_states` / `insn_frames_by_pc`
- the external skip reason `verifier instruction post-state is not scalar-exact`
- the misleading `apply_post_state()` / `can_apply_oracle_post_state()` names for exact-fact propagation

The remaining guard table is populated only when `state.kind == VerifierInsnKind::InsnDeltaState`. Full/edge verifier states still participate in the existing exact-fact propagation path, but they no longer prove ALU materialization safety.

## Key guard snippet

`fold_alu_instruction()` now has one verifier post-state guard:

```rust
if !oracle.instruction_post_state_proves_scalar_exact_in_context(
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
```

The oracle backing that guard uses only instruction delta post-states:

```rust
if state.kind == VerifierInsnKind::InsnDeltaState {
    post_state_frames_by_pc
        .entry(state.pc)
        .or_default()
        .insert(state.frame);
    *post_state_visit_counts
        .entry((state.pc, state.frame))
        .or_default() += 1;
    for (&regno, reg_state) in &state.regs {
        let key = (state.pc, state.frame, regno);
        *post_state_observed_counts.entry(key).or_default() += 1;
        let acc = post_state_accumulators.entry(key).or_default();
        match scalar_exact_post_state(reg_state) {
            Some(post_state) => acc.observe(post_state),
            None => acc.invalidate(),
        }
    }
}
```

## Test output

Command:

```bash
(cd bpfopt && cargo test -p bpfopt)
```

Result:

```text
running 319 tests
test result: ok. 319 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

running 9 tests
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

running 11 tests
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

Doc-tests bpfopt
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

Note: `cargo test -p bpfopt` from the repository root fails because the root has no `Cargo.toml`; the Rust workspace is `bpfopt/`.

## Boundary cases

- Missing `InsnDeltaState` or missing destination register observation fails closed and records `verifier post-state is not scalar-exact`.
- Conflicting `InsnDeltaState` observations fail closed.
- Multiple visits and multiple frames must all agree before replacement.
- `VerifierValueWidth` matching is unchanged.
- `PcFullState` and `EdgeFullState` can no longer prove scalar-exact post-state for ALU replacement.

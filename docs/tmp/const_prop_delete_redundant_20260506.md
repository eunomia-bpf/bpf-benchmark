# const_prop redundant branch cleanup deletion

## Deleted code inventory

Line refs below are from the pre-edit `bpfopt/crates/bpfopt/src/passes/const_prop.rs`.

- `const_prop.rs:2`: removed pass description as "branch folding"; now ALU materialization only.
- `const_prop.rs:5`: removed `HashSet` import used only by folded-branch NOP bookkeeping.
- `const_prop.rs:164`: removed `JA/NOP` from the pass doc comment.
- `const_prop.rs:193`: removed `nop_pcs` allocation.
- `const_prop.rs:206-210`: removed scan that collected NOP replacements from folded false branches.
- `const_prop.rs:216-234`: removed `branch_folded_taken` / `branch_folded_not_taken` counter accounting.
- `const_prop.rs:263`: removed `fixup_folded_jumps(...)` call.
- `const_prop.rs:264-269`: removed post-fixup forced NOP rewrite loop.
- `const_prop.rs:273-283`: removed internal `CFGAnalysis.run(...)` + `eliminate_unreachable_blocks_with_cfg(...)` cleanup call and composed addr map.
- `const_prop.rs:296-298`: removed diagnostics `const_prop_branch_folded_taken`, `const_prop_branch_folded_not_taken`, `const_prop_cleanup_removed_insns`.
- `const_prop.rs:416-418`: removed conditional-jump dispatch to `fold_jump_instruction`.
- `const_prop.rs:449-464`: removed `fold_jump_instruction` branch-to-`JA`/`NOP` materializer.
- `const_prop.rs:491-520`: removed `evaluate_jump_condition`.
- `const_prop.rs:601-616`: removed unsigned/signed jump operand normalization helpers.
- `const_prop.rs:625-631`: removed `jump_imm_operand`.
- `const_prop.rs:721-755`: removed `fixup_folded_jumps`.
- `const_prop.rs:770-796`: removed branch-only test helpers `jeq_imm`, `jeq32_imm`, `jne_imm`.
- `const_prop.rs:1034-1077`: removed `const_prop_folds_constant_branches_to_ja_and_nop`.
- `const_prop.rs:1102-1148`: removed `const_prop_folds_branch_after_map_inline`.
- `const_prop.rs:1150-1170`: removed `const_prop_removes_dead_target_after_false_branch_fold`.
- `const_prop.rs:1172-1254`: removed folded-jump fixup / DCE folded-branch tests.

Related stale tests were updated, not production pass code:

- `bpfopt/crates/bpfopt/src/passes/dce.rs`: DCE cascade test now expects the conditional branch to remain.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs`: pseudo-map-value cascade test now expects the branch to remain and the overwritten false-path assignment to be removed.
- `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`: full pipeline cascade test now expects one const_prop ALU materialization site and leaves branch cleanup to the kernel.

## Preserved ALU materialization path

- `const_prop.rs:27-164`: `OracleExactAccumulator` and `VerifierExactConstOracle` are still present.
- `const_prop.rs:185-203`: CFG analysis and block simulation setup are still used by const propagation.
- `const_prop.rs:209-256`: `const_prop_alu_materialized` remains the only const_prop diagnostic counter.
- `const_prop.rs:308-326`: `simulate_block` still drives per-block state transfer and replacement collection.
- `const_prop.rs:328-379`: `analyze_instruction` still tracks LD/LDX/ALU/call state. `BPF_JMP` / `BPF_JMP32` now only clobber helper-call registers and emit no replacement.
- `const_prop.rs:382-400`: `fold_alu_instruction` still emits MOV32/MOV64/LD_IMM64 candidates using verifier exact constants first.
- `const_prop.rs:402-499`: `evaluate_alu_result` and ALU evaluators are intact.
- `const_prop.rs:572-582`: `emit_constant_load` still chooses MOV32, MOV64, or LD_IMM64.
- `const_prop.rs:691-743`: required ALU tests remain: `const_prop_folds_alu_chain_to_constant_mov`, `const_prop_folds_alu32_chain_to_mov32_imm`, `const_prop_tracks_ldimm64_constants`.
- `const_prop.rs:757-768`: verifier-oracle ALU coverage remains via `const_prop_uses_verifier_exact_constants_for_alu_after_helper_calls`.

Code search after deletion:

```text
rg fold_jump_instruction/evaluate_jump_condition/fixup_folded_jumps/nop_pcs/const_prop_branch_folded/const_prop_cleanup_removed in bpfopt source: no matches.
eliminate_unreachable_blocks_with_cfg remains only in utils.rs, as required for shared callers.
```

## Verification

Before cargo build, the active `vm-corpus` process had moved into `python3 -m runner.libs.run_target_suite ...`; no host `cargo` or `rustc` build process was active.

```text
$ source /home/yunwei37/workspace/.venv/bin/activate && CARGO_TERM_COLOR=never cargo build --manifest-path bpfopt/Cargo.toml -p bpfopt --release
   Compiling bpfopt v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt)
    Finished `release` profile [optimized] target(s) in 10.51s
```

```text
$ source /home/yunwei37/workspace/.venv/bin/activate && CARGO_TERM_COLOR=never cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt
running 352 tests
test result: ok. 352 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.66s

running 12 tests
test result: ok. 12 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

running 10 tests
test result: ok. 10 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s

Doc-tests bpfopt
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s
```

No dead-code or unused-code warnings appeared in the final build or test output.

## Diff stat

```text
bpfopt/crates/bpfopt/src/passes/const_prop.rs      -500 / +17
bpfopt/crates/bpfopt/src/passes/dce.rs               -2 /  +7
bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs -11 /  +9
bpfopt/crates/bpfopt/src/passes/mod_tests.rs         -3 / +10

total: -516 / +43
net: -473 lines
```

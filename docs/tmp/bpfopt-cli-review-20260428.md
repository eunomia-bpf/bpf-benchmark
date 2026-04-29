# bpfopt CLI review for b0da364e

Reviewed commit: `b0da364e` (`feat(bpfopt): implement v3 CLI (12 pass subcommands + optimize + analyze)`)

Scope:
- `git diff b0da364e^..b0da364e`
- `bpfopt/crates/bpfopt/src/main.rs`
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs`
- `bpfopt/crates/bpfopt/src/lib.rs`
- `bpfopt/crates/bpfopt/Cargo.toml`
- v3 design: `docs/tmp/bpfopt_design_v3.md` sections 2.1, 3, 4, and pass order in section 5

## Findings

### CRITICAL: default `optimize` bypasses required side-input validation

Location:
- `bpfopt/crates/bpfopt/src/main.rs:456`
- `bpfopt/crates/bpfopt/src/main.rs:547`
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:102`

Description:

`run_optimize()` only calls `validate_required_side_inputs()` in the `else` branch for explicit `--passes`. When `--passes` is omitted, it selects `DEFAULT_PASS_ORDER` and immediately runs all 12 passes without validating the side-inputs required by that default order.

That conflicts with v3's pipeline contract and the review requirement that missing required side-inputs exit 1 with a clear `--xxx required` stderr. The default order includes `map-inline`, `const-prop`, kinsn passes, and `branch-flip`, so a bare `bpfopt optimize` currently succeeds even though it has no `--map-values`, `--map-ids`, `--verifier-states`, `--target`/`--kinsns`, or `--profile`.

Reproduction:

```text
bpfopt optimize --report opt-report.json < minimal.bin
status=0
stdout_bytes=16
report_passes=12
stderr=
```

The new integration test `optimize_default_pipeline_writes_json_report_array` codifies this success path with no side inputs, so the test currently protects the wrong behavior under the stated v3 rules.

Fix suggestion:

Canonicalize the selected pass list first, then call `validate_required_side_inputs(common, &pass_names)` for both default and explicit `--passes` before reading bytecode or running any pass. Update the default optimize integration test to either provide all required side-input files or assert the expected missing-side-input error. If the intended product behavior is "default optimize only runs side-input-free passes when side inputs are absent", document that as a v3 change first; it is not what the current design says.

### CRITICAL: `--target`/`--kinsns` presence is accepted even when the selected kinsn is missing

Location:
- `bpfopt/crates/bpfopt/src/main.rs:547`
- `bpfopt/crates/bpfopt/src/main.rs:655`
- `bpfopt/crates/bpfopt/src/main.rs:731`

Description:

For kinsn-backed passes, validation checks only whether `--target` exists or `--kinsns` is non-empty. It does not verify that the selected pass's required kinsn is present in the resulting `KinsnRegistry`.

As a result, a malformed or incomplete `target.json` with an empty `kinsns` object is accepted. The pass then returns `PassResult::skipped(...)`, the CLI exits 0, and the original bytecode is passed through. The review requirement explicitly calls out: "kinsns missing -> kinsn-required pass reports error".

Reproduction:

```text
target.json = {"arch":"x86_64","features":["cmov"],"kinsns":{}}

bpfopt rotate --target target.json < minimal.bin
status=0
stdout_bytes=16
stderr=
```

The same issue exists for explicit optimize:

```text
bpfopt optimize --passes rotate --target target.json < minimal.bin
status=0
stdout_bytes=16
stderr=
```

Fix suggestion:

After `build_pass_context()` constructs the final registry from `--target` plus `--kinsns`, validate each selected pass against the actual required target names and BTF IDs. For example, `rotate` should require `bpf_rotate64`, `cond-select` should require `bpf_select64`, `extract` should require `bpf_extract64`, and `bulk-memory` should require the bulk-memory kinsns defined by the target schema. Return exit 1 with messages like `rotate requires --target kinsn bpf_rotate64` instead of silently reporting an unchanged pass.

### HIGH: `optimize --passes` is not strictly equivalent to chaining the listed pass commands

Location:
- `bpfopt/crates/bpfopt/src/main.rs:473`
- `bpfopt/crates/bpfopt/src/pass.rs:930`

Description:

v3 describes `optimize --passes A,B,C` as a convenience equivalent to serially chaining pass commands. The CLI builds a `PassManager` and calls `run_with_profiling()`. `PassManager::run()` contains special fixed-point handling for adjacent `const_prop` + `dce`, so a requested list containing `const-prop,dce` can execute those passes multiple times and emit multiple report entries.

This can diverge from:
- `bpfopt const-prop | bpfopt dce`
- the exact user-provided order/count in `--passes`
- the v3 default list, which names each pass once

The minimal no-op fixture does not expose this because neither pass changes the bytecode, but the code path is active for real programs.

Fix suggestion:

For CLI `optimize`, run the selected pass list exactly once in the requested order, or make fixed-point behavior an explicit opt-in flag/subcommand. Keep per-pass verify/fixed-point orchestration in scripts if that is the intended v3 model.

### MEDIUM: integration coverage misses the side-input success paths and custom-order contract

Location:
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:44`
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:102`
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:137`

Description:

The 6 integration tests cover:
- `list-passes`
- `wide-mem` stdin/stdout pass-through
- single-pass report JSON
- default optimize report shape
- non-8-byte bytecode error
- missing `--verifier-states` for direct `const-prop`

They do not cover:
- successful `--target` parsing from a v3 target JSON file
- successful `--verifier-states` file parsing by the CLI
- successful `--map-values` + `--map-ids` file parsing
- `optimize --passes A,B,C` preserving the requested order
- `--target` present but missing the pass-required kinsn
- default `optimize` missing required side-inputs

The tests use inline bytecode and do not depend on `tests/fixtures`; the existing `tests/fixtures` symlink points to `../../../../daemon/tests/fixtures` but is not used by this test file.

Fix suggestion:

Add focused CLI integration tests for at least one valid `target.json`, one valid `verifier-states.json`, and one custom `optimize --passes wide-mem,dce` order report. Add negative tests for `rotate --target` with no `bpf_rotate64` and for default `optimize` missing required side inputs once the intended semantics are fixed.

### LOW: panic conversion catches unwinds but does not suppress the default panic hook

Location:
- `bpfopt/crates/bpfopt/src/main.rs:340`
- `bpfopt/crates/bpfopt/src/main.rs:488`

Description:

`main()` and `run_pipeline_catching_panics()` use `catch_unwind`, so panics are converted to exit 1 instead of aborting. However, Rust's default panic hook still prints the panic message before `catch_unwind` returns. If the requirement is "no raw Rust panic output reaches stderr", this is only partially satisfied.

Fix suggestion:

Install a short-lived custom panic hook around CLI execution or around pass execution, then restore the previous hook. Keep the user-facing stderr as `error: internal bpfopt panic` or `error: internal pass panic`.

## Positive Checks

- The 12 top-level per-pass subcommand names match v3: `wide-mem`, `rotate`, `const-prop`, `cond-select`, `extract`, `endian`, `branch-flip`, `dce`, `map-inline`, `bulk-memory`, `bounds-check-merge`, `skb-load-bytes`.
- `DEFAULT_PASS_ORDER` matches v3 section 5 order when converted to CLI names.
- `stdin`/`stdout` for per-pass and optimize commands are raw `struct bpf_insn[]` bytes with no framing.
- Non-8-byte input exits 1 and includes `multiple of 8` in stderr.
- No-op `wide-mem` exits 0 and passes through bytecode unchanged.
- `--input`/`--output` are wired as global flags.
- `analyze` emits meaningful JSON for the minimal program.
- `list-passes` and `list-passes --json` both list 12 passes.
- Single-pass report JSON uses the v3 field names: `pass`, `changed`, `sites_applied`, `insn_count_before`, `insn_count_after`, `insn_delta`.
- Optimize report uses `{ "passes": [...] }`, which is one of the accepted shapes in the review brief.
- `--verifier-states` deserializes JSON directly into `VerifierInsn`-compatible state and does not parse raw verifier logs.
- `target.json` supports `arch`, `features`, and `kinsns` with v3 aliases such as `bpf_bulk_memcpy`.
- `lib.rs` and `bpfopt/crates/bpfopt/Cargo.toml` are unchanged in `b0da364e`; the commit does not widen the library module surface or add CLI crate cross-dependencies.
- `bpfopt` depends on `kernel-sys`, but this path is used for constants/data types in the CLI, not direct BPF syscalls.

## Verification

Commands run:

```text
cargo test -p bpfopt
cargo build -p bpfopt --release
target/release/bpfopt list-passes
target/release/bpfopt list-passes --json
target/release/bpfopt analyze < minimal.bin
target/release/bpfopt wide-mem < minimal.bin
target/release/bpfopt wide-mem --report report.json < minimal.bin
target/release/bpfopt optimize --report opt-report.json < minimal.bin
target/release/bpfopt optimize --passes wide-mem,dce --report custom-report.json < minimal.bin
target/release/bpfopt wide-mem < invalid-9-byte.bin
target/release/bpfopt const-prop < minimal.bin
target/release/bpfopt rotate --target target-with-empty-kinsns.json < minimal.bin
target/release/bpfopt optimize --passes rotate --target target-with-empty-kinsns.json < minimal.bin
target/release/bpfopt rotate --target malformed-target.json < minimal.bin
```

Results:

```text
cargo test -p bpfopt: passed
  lib tests: 399 passed
  main.rs tests: 5 passed
  CLI integration tests: 6 passed
  doc tests: 0

cargo build -p bpfopt --release: passed

list-passes: status 0, 12 lines
list-passes --json: status 0, 12 entries, first map-inline, last branch-flip
analyze: status 0, JSON included insn_count=2, subprog_count=1, branch_count=0
wide-mem: status 0, 16 stdout bytes, byte-identical to input
wide-mem --report: status 0, valid report JSON, changed=false
optimize --report: status 0, 16 stdout bytes, 12 report entries
optimize --passes wide-mem,dce: status 0, report order wide_mem,dce
invalid 9-byte input: status 1, stdout empty, stderr contains multiple of 8
const-prop without --verifier-states: status 1, stdout empty, stderr contains --verifier-states
rotate with malformed target JSON: status 1, stdout empty, friendly parse context
rotate with empty target kinsns: status 0, pass-through bytecode; this is a finding
optimize --passes rotate with empty target kinsns: status 0, pass-through bytecode; this is a finding
```

Release startup/per-pass timing on this machine:

```text
/usr/bin/time target/release/bpfopt list-passes: 0.00 s
100x list-passes loop: 68.101 ms total, 0.681 ms average
100x wide-mem on minimal program: 64.858 ms total, 0.649 ms average
```

Note: a full workspace `cargo test` was attempted after unrelated in-progress `bpfget`/`bpfrejit` workspace entries appeared in the working tree. It failed before reaching the reviewed crate because those crates currently have `Cargo.toml` files pointing to missing `src/main.rs`. This is not part of `b0da364e`; `cargo test -p bpfopt` is the relevant verification for this review.

## Conclusion

Not ready as the CLI baseline for #41 Phase 1 minimal pipeline validation. The raw bytecode protocol, command surface, reports, and basic error paths are mostly in place, but the two side-input/target validation failures are v3 conformance blockers.

#39 (`bpfget`) and #40 (`bpfrejit`) can proceed as parallel implementation work if needed, but #41 should not consume this CLI as the integration baseline until:
- default `optimize` validates required side-inputs or the v3 semantics are explicitly changed;
- kinsn-required passes error when the selected target does not provide the required kinsn;
- tests cover those negative paths and at least one positive side-input file path.

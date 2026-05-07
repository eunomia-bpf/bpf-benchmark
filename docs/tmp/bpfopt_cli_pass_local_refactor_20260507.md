# bpfopt CLI Pass-Local Args Refactor - 2026-05-07

## Audit conclusion

Detailed audit: `docs/tmp/bpfopt_cli_args_audit_20260507.md`.

Shared framework args remain in `bpfopt/src/main.rs`:

- `--pass`
- `--input`
- `--output`
- `--report`
- `--platform`
- `--prog-type`
- `--kinsns`
- `--target`
- `--verifier-states`
- `--func-info` / `--func-info-rec-size`
- `--line-info` / `--line-info-rec-size`

Pass-local args moved out of `main.rs`:

- `map_inline`: `--map-values`, `--map-ids`
- `branch_flip`: `--profile`
- `prefetch`: optional `--profile`

`main.rs` and `pass.rs` no longer contain these pass-local flag names or their parsing schemas.

## Deletion list

- Removed global `CommonArgs.profile`, `CommonArgs.map_values`, and `CommonArgs.map_ids`.
- Removed main-level profile JSON parsing, bpftool map snapshot parsing, and map-id CSV parsing.
- Removed dead `BpfProgram.transform_log`, `TransformEntry`, and `BpfProgram::log_transform`.
- Removed dead `ProfilingData.cache_miss_rate`.
- Removed dead `PassManager::run_with_profiling`.
- Removed stale transform-log writes from concrete passes.
- Removed the unit test that only exercised the deleted `run_with_profiling` wrapper.

## New / changed interfaces

- Added `Cli.pass_args: Vec<String>` with clap `last = true`, so pass-local args must follow `--`.
- Changed `PassRegistryEntry.make` from a zero-arg constructor to `fn(&[String]) -> Result<Box<dyn BpfPass>>`.
- Added minimal pass-local parsers in:
  - `passes/map_inline.rs`
  - `passes/branch_flip.rs`
  - `passes/prefetch.rs`
- Added wrapper pass implementations for CLI profile/snapshot loading before delegating to existing pass logic.
- Updated `runner/libs/rejit_plan.py` to emit shared args before `--` and map-inline local args after `--`.
- Added daemon substitution variable `${PASS_LOCAL_ARGS}` as an empty placeholder for future pass-local command-template args.

No new `Pass` trait method, `Box<dyn Any>` payload, or cross-CLI crate dependency was added.

## LOC delta

Tracked refactor paths only (`git diff --stat -- bpfopt daemon runner`):

```text
 bpfopt/crates/bpfopt/src/main.rs                   | 655 +--------------------
 bpfopt/crates/bpfopt/src/pass.rs                   |  40 --
 bpfopt/crates/bpfopt/src/pass_tests.rs             |  50 --
 .../crates/bpfopt/src/passes/bounds_check_merge.rs |   3 -
 bpfopt/crates/bpfopt/src/passes/branch_flip.rs     | 169 +++++-
 bpfopt/crates/bpfopt/src/passes/bulk_memory.rs     |   3 -
 bpfopt/crates/bpfopt/src/passes/ccmp.rs            |   3 -
 bpfopt/crates/bpfopt/src/passes/cond_select.rs     |   3 -
 bpfopt/crates/bpfopt/src/passes/const_prop.rs      |   3 -
 bpfopt/crates/bpfopt/src/passes/dce.rs             |   2 -
 bpfopt/crates/bpfopt/src/passes/endian.rs          |   3 -
 bpfopt/crates/bpfopt/src/passes/extract.rs         |   3 -
 bpfopt/crates/bpfopt/src/passes/map_inline.rs      | 441 +++++++++++++-
 .../crates/bpfopt/src/passes/map_inline_tests.rs   | 125 ++++
 bpfopt/crates/bpfopt/src/passes/mod.rs             |  56 +-
 bpfopt/crates/bpfopt/src/passes/prefetch.rs        | 119 +++-
 bpfopt/crates/bpfopt/src/passes/rotate.rs          |   3 -
 bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs  |   3 -
 bpfopt/crates/bpfopt/src/passes/wide_mem.rs        |   3 -
 bpfopt/crates/bpfopt/tests/cli_pipeline.rs         |   4 +-
 daemon/src/commands.rs                             |   3 +
 runner/libs/rejit_plan.py                          |   7 +-
 22 files changed, 910 insertions(+), 791 deletions(-)
```

Audit doc added separately: `docs/tmp/bpfopt_cli_args_audit_20260507.md` (74 lines).

## Build and test results

All required commands passed on the final tree:

```text
cargo build --manifest-path bpfopt/Cargo.toml --release 2>&1 | tail
Finished `release` profile [optimized] target(s) in 9.31s

cargo build --manifest-path daemon/Cargo.toml --release 2>&1 | tail
Finished `release` profile [optimized] target(s) in 0.01s

cargo test --manifest-path bpfopt/Cargo.toml 2>&1 | tail -50
test result: ok. Doc-tests bpfopt/kernel_sys also ok.

cargo test --manifest-path daemon/Cargo.toml 2>&1 | tail -50
test result: ok. 27 passed; 0 failed.

make lint 2>&1 | tail
python -m py_compile completed successfully.
```

Additional self-review:

- `cargo fmt --manifest-path bpfopt/Cargo.toml --all`
- `cargo fmt --manifest-path daemon/Cargo.toml --all`
- `git diff --check -- bpfopt daemon runner docs/tmp/bpfopt_cli_args_audit_20260507.md`
- residual search for deleted dead-code names: clean

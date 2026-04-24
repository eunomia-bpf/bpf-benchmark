# daemon `orig_insns` fix summary (2026-04-23)

## Scope

Fix `daemon/src/commands.rs` single-program `optimize` silently short-circuiting when `orig_insns.is_empty()`, and clean up the requested daemon-layer SHOULD/NICE follow-ups:

- SHOULD: move `elf_parser` back to test-only.
- SHOULD: remove the now-redundant `orig_insns.is_empty()` guard in `maybe_attach_original_verifier_states()`.
- NICE: inline the single-use command-layer wrappers called out by the audit.

No VM targets were run in this task, per the explicit `make vm-*` ban.

## Decision

Selected **Scheme A: loud-fail**.

Reason:

1. `daemon/src/bpf.rs` does not convert any `BPF_PROG_GET_ORIGINAL` errno into an empty instruction vector. It returns empty `orig_insns` only when the kernel reports `orig_prog_len == 0`.
2. Local kernel code confirms that `orig_prog_len == 0` is a capability/raw-dump visibility issue, not a normal pass-planning outcome:
   - `vendor/linux-framework/kernel/bpf/syscall.c:5911-5919` zeros `orig_prog_len` when `!bpf_capable()`.
   - `vendor/linux-framework/kernel/bpf/syscall.c:5944-5953` handles raw-dump gating separately.
3. There is no daemon-side evidence that some specific program types are expected to be “optimize ok but naturally have no original bytecode”.

Therefore, empty `orig_insns` is an explicit failure for single-program `optimize`, and it should match `optimize-all` instead of being collapsed into `status="ok"` with empty passes.

## Changes

### BLOCKER

- `daemon/src/commands.rs`
  - Changed `try_apply_one()` to `bail!("prog {} ({}) is missing original bytecode from BPF_PROG_GET_ORIGINAL", ...)` when `orig_insns.is_empty()`.
  - Removed the old `ok + empty passes + applied=false + changed=false` short-circuit.
  - Simplified `orig_insn_count` to `orig_insns.len()` after the invariant is enforced.

### SHOULD

- `daemon/src/commands.rs`
  - Removed the redundant `orig_insns.is_empty()` guard from `maybe_attach_original_verifier_states()`.
- `daemon/src/main.rs`
  - Changed `mod elf_parser;` to `#[cfg(test)] mod elf_parser;`.
- `daemon/src/elf_parser.rs`
  - Removed the non-test dead-code suppression; the module now only builds in tests.

### NICE

- `daemon/src/commands.rs`
  - Inlined `OptimizeMode::should_apply()`.
  - Inlined `build_pipeline()`.
  - Inlined `build_prog_load_fd_array()`.
  - Removed the `summarize_error()` wrapper.
- `daemon/src/server.rs`
  - Inlined the error-headline formatting at the only `summarize_error()` call site.
- `daemon/src/commands_tests.rs`
  - Updated tests to cover the remaining real helpers directly.

## Diff summary

Code delta across the 3 daemon commits:

```text
5 files changed, 89 insertions(+), 110 deletions(-)
```

Net code delta: **-21 LOC**.

## Verification

Commands run:

```bash
cargo build --release --manifest-path daemon/Cargo.toml -p bpfrejit-daemon
cargo test --manifest-path daemon/Cargo.toml
make check
```

Results:

- `cargo build --release ...`: PASS
- `cargo test ...`: PASS, `499 passed; 0 failed; 0 ignored`
- `make check`: PASS

Notes:

- `cargo test` still emits pre-existing `dead_code` warnings in test-only helper code (`elf_parser.rs`, `test_utils.rs`), but the test suite is green.
- `make vm-*` was intentionally not run.

## Git log

```text
a95c6466 daemon: inline single-use command wrappers
f0692904 daemon: keep elf parser test-only
358da2d5 daemon: fail optimize when original bytecode is missing
```

# P66 Consolidation: P64 + P65 Handoff

Date: 2026-04-29

## Handoff State

Initial audit from `/home/yunwei37/workspace/bpf-benchmark/bpfopt` showed a mixed worktree:

- Staged P64 subset: `bpfget/src/main.rs`, `bpfrejit/src/main.rs`, `bpfverify/src/main.rs`, `runner/containers/runner-runtime.Dockerfile`
- Unstaged P64/P65 subset: `.gitignore`, `bpfget`, `bpfrejit`, `kernel-sys`, `daemon`, deleted `elf_parser.rs`, deleted `test_utils.rs`, bpfopt cleanup files, and bpfverify CLI test update

Follow-up audit from the repo root showed `HEAD=f28b81b5` already ahead of `origin/main=1b85ad59` with the original P64 staged subset committed locally. I kept that unpushed commit as the base for consolidation, completed the remaining P64/P65 work, and amended into one final commit. An unrelated `.claude/scheduled_tasks.lock` worktree change was left unstaged.

## P64 Fixes

- `bpfget --info/--full` now validates required attach metadata before writing JSON: `bpfopt/crates/bpfget/src/main.rs:171`, `:174`, `:225`, `:257`, `:262`.
  - `prog_btf` required for kprobe/tracing/lsm/ext: `bpfopt/crates/bpfget/src/main.rs:288`.
  - `attach_btf_id` required for tracing/lsm/struct_ops/ext: `bpfopt/crates/bpfget/src/main.rs:298`.
  - `expected_attach_type` required for tracing/lsm: `bpfopt/crates/bpfget/src/main.rs:308`.
- `bpfrejit --dry-run` now opens `prog_btf_fd` with `kernel_sys::btf_get_fd_by_id` and keeps the `OwnedFd` alive through `prog_load_dryrun_report`: `bpfopt/crates/bpfrejit/src/main.rs:122`, `:126`, `:139`, `:142`.
- `bpfverify --report` now exits 1 on verifier rejection while still writing the report before returning failure: `bpfopt/crates/bpfverify/src/main.rs:225`, `:239`, `:244`.
- Daemon report handling now reads bpfverify reports even when the subprocess exits nonzero, then propagates verifier status with the report detail: `daemon/src/commands.rs:1590`, `:1596`, `:1600`, `:1623`, `:1669`.
- Removed unused public `kernel_sys::prog_load_dryrun_with_fd_array`; `prog_load_dryrun_report` is now the only dry-run API in that area: `bpfopt/crates/kernel-sys/src/lib.rs:181`.
- `expected_attach_type_for_prog` now errors when a tracing/LSM program is attached through an unsupported link type needed for required attach-type recovery: `bpfopt/crates/kernel-sys/src/lib.rs:380`, `:403`.
- Deleted the three shallow `panic_payload_message_*` daemon tests: removed from `daemon/src/server.rs` after `:940`.

## P65 Cleanup

- Deleted `bpfopt/crates/bpfopt/src/elf_parser.rs` entirely. This removes the in-crate ELF parser, its fixture tests, and the `goblin` dependency, keeping bpfopt aligned with v3 raw `struct bpf_insn[]` input.
- Deleted `bpfopt/crates/bpfopt/src/test_utils.rs` entirely because it depended on the ELF parser and mock map plumbing.
- Removed `elf_parser` and `test_utils` modules from `bpfopt/crates/bpfopt/src/lib.rs:8`.
- Removed ELF-backed test helpers from `bpfopt/crates/bpfopt/src/insn.rs` and all remaining callers.
- Removed `goblin` from `bpfopt/Cargo.toml`, `bpfopt/crates/bpfopt/Cargo.toml`, and `bpfopt/Cargo.lock`.
- Replaced optimize-mode skip/fallback reporting with fail-fast side-input and kinsn validation in `bpfopt/crates/bpfopt/src/main.rs:630`, `:743`, `:757`, `:782`.
- Updated CLI tests to assert fail-fast behavior and absence of `skipped`/`reason` report fields: `bpfopt/crates/bpfopt/tests/cli_pipeline.rs`.

## mock_maps Decision

`mock_maps.rs` is retained only for tests:

- `bpfopt/crates/bpfopt/src/lib.rs:9` gates the public `bpf` test compatibility module behind `#[cfg(test)]`.
- `bpfopt/crates/bpfopt/src/lib.rs:14` gates `mock_maps` itself behind `#[cfg(test)]`.
- `pass.rs` production no longer calls mock map helpers. The three handoff hotspots are:
  - `bpfopt/crates/bpfopt/src/pass.rs:212-224`: test-only metadata lookup from `mock_maps`.
  - `bpfopt/crates/bpfopt/src/pass.rs:226-229`: production missing metadata is an error.
  - `bpfopt/crates/bpfopt/src/pass.rs:252-260`: test-only mock value-size lookup; production falls through to real snapshot metadata.
  - `bpfopt/crates/bpfopt/src/pass.rs:288-290`: test-only mock lookup; production requires snapshot metadata/value and errors otherwise.

## Unit Test Audit

Deleted 17 low-value or fallback-style tests:

- `bpfopt/crates/bpfopt/src/insn.rs`: `test_bpf_insn_encoding`, `test_make_regs_roundtrip`, `test_dump_bytecode_formats_full_insn_dump`
- `daemon/src/server.rs`: `panic_payload_message_formats_strings`, `panic_payload_message_formats_static_str`, `panic_payload_message_handles_unknown_payloads`
- `bpfopt/crates/bpfopt/src/passes/rotate.rs`: `test_scan_rotate_real_bytecode`
- `bpfopt/crates/bpfopt/src/passes/branch_flip.rs`: `test_branch_flip_real_bytecode_with_mock_pgo`, `test_branch_flip_real_bytecode_high_miss_rate`
- `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs`: `test_scan_wide_mem_real_bytecode`
- `bpfopt/crates/bpfopt/src/passes/endian.rs`: `test_scan_endian_real_bytecode`
- `bpfopt/crates/bpfopt/src/passes/extract.rs`: `test_scan_extract_real_bytecode`
- `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs`: `test_scan_cond_select_real_bytecode`
- `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`: `test_full_pipeline_real_bytecode_load_byte_recompose`, `test_full_pipeline_real_bytecode_rotate_dense`, `test_full_pipeline_real_bytecode_bitfield_extract`, `test_full_pipeline_real_bytecode_endian_swap_dense`

The deleted real-bytecode tests were unit tests with silent `SKIP` behavior and an ELF fixture dependency. The remaining test set was checked against the feedback rule: retained tests cover pass behavior, control-flow rewrites, ABI/layout offsets, error paths, CLI contracts, serialization contracts, or regression-sensitive transformations.

## Cargo Verification

Repo root has no `Cargo.toml`, so the commands were run in both Rust workspaces that changed:

- `cd bpfopt && cargo build --all-targets` passed.
- `cd daemon && cargo build --all-targets` passed.
- `cd bpfopt && cargo clippy --all-targets -- -D warnings` passed.
- `cd daemon && cargo clippy --all-targets -- -D warnings` passed.
- `cd bpfopt && cargo test --all-targets` passed: 451 tests.
- `cd daemon && cargo test --all-targets` passed: 34 tests.

No KVM validation was run; that is reserved for P67.

## LOC Delta

| Path | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `bpfopt/crates/bpfopt/src/elf_parser.rs` | 1212 | 0 | -1212 |
| `bpfopt/crates/bpfopt/src/test_utils.rs` | 544 | 0 | -544 |
| `bpfopt/crates/bpfopt/src/insn.rs` | 729 | 553 | -176 |
| `bpfopt/crates/bpfopt/src/main.rs` | 1746 | 1589 | -157 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 1237 | 1240 | +3 |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` | 1154 | 1027 | -127 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 682 | 650 | -32 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs` | 1006 | 956 | -50 |
| `bpfopt/crates/bpfopt/src/passes/extract.rs` | 855 | 799 | -56 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 612 | 426 | -186 |
| `bpfopt/crates/bpfopt/src/passes/rotate.rs` | 809 | 735 | -74 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs` | 990 | 937 | -53 |
| `bpfopt/crates/bpfopt/tests/cli_pipeline.rs` | 741 | 658 | -83 |
| `daemon/src/server.rs` | 1082 | 1061 | -21 |

Total bpfopt/daemon cleanup from the audited files above: 13,399 LOC before, 10,631 LOC after, net -2,768 LOC.

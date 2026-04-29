# kernel-sys fix review: 588da364

Date: 2026-04-28

Scope:

- `git diff 588da364^..588da364 -- bpfopt/crates/kernel-sys/`
- `bpfopt/crates/kernel-sys/src/lib.rs`
- `bpfopt/crates/kernel-sys/tests/prog_get_original.rs`
- comparison references: `vendor/linux-framework/include/uapi/linux/bpf.h`, `vendor/linux-framework/tools/include/uapi/linux/bpf.h`, `vendor/linux-framework/kernel/bpf/syscall.c`, `daemon/src/bpf.rs`

Verification commands run:

- `cargo fmt --check`
- `cargo build`
- `cargo test -p kernel-sys`
- `cargo test`
- `cargo test -p kernel-sys --test prog_get_original -- --nocapture`
- `git diff --check 588da364^..588da364 -- bpfopt/crates/kernel-sys`

All cargo commands passed. The local `prog_get_original` integration test skipped at runtime because `BPF_PROG_GET_NEXT_ID` returned `EPERM`, which is an expected unsupported-environment path.

## Summary

Commit `588da364` fixes the CRITICAL `kernel-sys` issues from the prior review. The fake `BPF_PROG_GET_ORIGINAL = 40` command and `AttrGetOriginal` are gone from `kernel-sys`; original bytecode retrieval now uses the fork `bpf_prog_info.orig_prog_len/orig_prog_insns` fields through `libbpf_sys::bpf_obj_get_info_by_fd`, matching the daemon and current vendor kernel implementation.

The commit is ready for Phase 1.2.5 and Phase 1.3 from a `kernel-sys` syscall-boundary perspective. The only residual issue found is a low-severity two-pass snapshot caveat in `prog_get_original()` under concurrent ReJIT, which already exists in the daemon pattern and is not a blocker for the next phase.

## P1: `BPF_PROG_GET_ORIGINAL` fake constant and `AttrGetOriginal`

Status: FIXED ✓

Severity: CRITICAL resolved

Evidence:

- `rg` found no `BPF_PROG_GET_ORIGINAL =` or `AttrGetOriginal` in `bpfopt/crates/kernel-sys`.
- `bpfopt/crates/kernel-sys/src/lib.rs:230-249` implements program info reads via `bpf_obj_get_info_by_fd`.
- `bpfopt/crates/kernel-sys/src/lib.rs:339-383` implements `prog_get_original()` as a two-pass `BPF_OBJ_GET_INFO_BY_FD` read using `orig_prog_len` and `orig_prog_insns`.
- `vendor/linux-framework/include/uapi/linux/bpf.h:6681-6722` defines `struct bpf_prog_info` with `orig_prog_len` and `orig_prog_insns`.
- `vendor/linux-framework/kernel/bpf/syscall.c:5944-5955` copies original bytecode through those fields.
- `vendor/linux-framework/kernel/bpf/syscall.c:7200-7245` still has no `BPF_PROG_GET_ORIGINAL` dispatcher case.

Daemon comparison:

- `daemon/src/bpf.rs:565-617` uses the same two-pass `BPF_OBJ_GET_INFO_BY_FD` pattern.
- The daemon is correct for the checked-in fork kernel. Some daemon messages/comments still say `BPF_PROG_GET_ORIGINAL`, but the implementation path matches `kernel-sys` after this fix.

`BpfProgInfoFork` layout:

- `bpfopt/crates/kernel-sys/src/lib.rs:48-88` defines the fork-compatible struct.
- A C offset check against `vendor/linux-framework/tools/include/uapi/linux/bpf.h` produced `sizeof(struct bpf_prog_info) = 240`, `orig_prog_len = 228`, and `orig_prog_insns = 232`.
- The Rust field-offset test covers every field from `type` through `orig_prog_insns`, not only the fork extension.

## P2: `AttrRejit` layout test

Status: FIXED ✓

Severity: HIGH resolved

Evidence:

- The stale `fork_attr_layouts_are_128_bytes` test is gone.
- `bpfopt/crates/kernel-sys/src/lib.rs:392-407` checks all `union bpf_attr.rejit` field offsets:
  `prog_fd=0`, `insn_cnt=4`, `insns=8`, `log_level=16`, `log_size=20`, `log_buf=24`, `fd_array=32`, `fd_array_cnt=40`, `flags=44`.
- A C offset check against vendor UAPI matched these values and confirmed `sizeof(union bpf_attr) = 168`.
- The Rust test also asserts `size_of::<AttrRejit>() == 48`, which is acceptable because it verifies the minimal prefix passed to the kernel, not the full union size. The fork kernel zero-initializes the full union before copying the user prefix.

## P3: ReJIT verifier log capture

Status: FIXED ✓

Severity: HIGH resolved

Evidence:

- `bpfopt/crates/kernel-sys/src/lib.rs:296-301` changes `prog_rejit()` to accept `Option<&mut [u8]>`.
- `bpfopt/crates/kernel-sys/src/lib.rs:302-320` fills `AttrRejit.log_level`, `log_size`, and `log_buf` when a buffer is provided.
- `bpfopt/crates/kernel-sys/src/lib.rs:321-333` extracts the same buffer after syscall failure and includes a verifier log summary in the returned error when non-empty.

Notes:

- This API does not automatically retry a no-log ReJIT with logging. That is still acceptable for `kernel-sys`: callers such as `bpfrejit` can pass a log buffer when they need verifier diagnostics, or implement a daemon-style fast-path retry above this wrapper.
- I did not force a live verifier failure locally; the code review confirms the kernel ABI fields are set and the error path reads the supplied buffer.

## P4: Map wrappers

Status: FIXED ✓

Severity: MEDIUM resolved

Evidence:

- `bpfopt/crates/kernel-sys/src/lib.rs:253-264` adds `map_get_next_id()`.
- `bpfopt/crates/kernel-sys/src/lib.rs:267-273` adds `map_get_fd_by_id()`.
- `bpfopt/crates/kernel-sys/src/lib.rs:276-284` adds `map_obj_get_info_by_fd()`.
- These call `libbpf_sys` APIs (`bpf_map_get_next_id`, `bpf_map_get_fd_by_id`, `bpf_map_get_info_by_fd`), not direct `libc::syscall`.

## P5: `prog_get_original` integration test

Status: FIXED ✓

Severity: MEDIUM resolved

Evidence:

- `bpfopt/crates/kernel-sys/tests/prog_get_original.rs` was added.
- The test skips unsupported environments for `EPERM`, `EACCES`, `ENOSYS`, and `EINVAL`, which is reasonable for unprivileged hosts and kernels without the fork fields.
- In an environment with a live program exposing nonzero `orig_prog_len`, the test calls `kernel_sys::prog_get_original()` and asserts `insns.len() * sizeof(bpf_insn) == info.orig_prog_len`.

Local result:

- `cargo test -p kernel-sys --test prog_get_original -- --nocapture` skipped with `BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)`.

## New Checks

### Two-pass `prog_get_original()` snapshot caveat

Status: PARTIAL

Severity: LOW

`prog_get_original()` calls `BPF_OBJ_GET_INFO_BY_FD` twice: once to get `orig_prog_len`, then again to copy bytes into a user buffer. The implementation detects length growth, malformed byte lengths, and denied raw dump by checking `orig_prog_insns == 0`. It does not detect an equal-length concurrent ReJIT between the two reads.

The fork kernel swaps `prog->aux->orig_insns` and `orig_prog_len` during ReJIT, so a concurrent ReJIT can theoretically make the two reads non-snapshot. The daemon has the same two-pass limitation. Because there is no generation token or snapshot API in the current UAPI, this is a residual race rather than a regression introduced by the fix. It is not a blocker for Phase 1.2.5 or Phase 1.3.

### `BpfProgInfoFork` full layout coverage

Status: FIXED ✓

Severity: none

The new unit test covers all fields in the fork `struct bpf_prog_info`, including the upstream fields before the fork extension. A C offset check against vendor UAPI matched the Rust offsets and total size:

- `sizeof(struct bpf_prog_info) = 240`
- `attach_btf_id = 224`
- `orig_prog_len = 228`
- `orig_prog_insns = 232`

### `bpfopt` crate kernel dependency boundary

Status: FIXED ✓

Severity: none

`bpfopt/crates/bpfopt/Cargo.toml` has no `kernel-sys`, `libbpf-rs`, `libbpf-sys`, or `libc` package dependency. `rg` also found no `libc::syscall`, `SYS_bpf`, or direct BPF syscall path in `bpfopt/crates/bpfopt`.

The workspace root `bpfopt/Cargo.toml` still declares shared workspace dependency versions for `kernel-sys` to use. That does not make the `bpfopt` package depend on kernel APIs.

### Unit test quality

Status: FIXED ✓

Severity: none

The new tests satisfy the CLAUDE.md unit-test guidance:

- ABI tests verify field offsets and encoded C layout boundaries, not only `size_of`.
- The integration test checks a real external ABI contract when privileges and live fork programs are available.
- No new test is a getter/setter test, self-equality tautology, pure mock behavior, or size-only layout assertion.

## Phase Readiness

Ready for Phase 1.2.5: YES, with the explicit interpretation that `bpfopt` should only consume `kernel-sys` pure data/type APIs if that phase intentionally relaxes the current zero-kernel-dependency split. This commit itself does not add kernel dependencies to the `bpfopt` crate.

Ready for Phase 1.3: YES for the basic `bpfget`/`bpfrejit` CLI syscall substrate. `bpfrejit` should pass a log buffer to `prog_rejit()` when it needs verifier diagnostics, and `bpfget` should treat the two-pass original-bytecode read as non-snapshot under concurrent ReJIT.

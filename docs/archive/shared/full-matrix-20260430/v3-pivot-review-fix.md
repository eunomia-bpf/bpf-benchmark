# v3 Pivot Review Fix Report

Date: 2026-05-01

Scope: fixes for every P0/P1/P2/P3 item in `docs/tmp/full-matrix-20260430/v3-pivot-review.md`.

## Summary

- P0#1: added a daemon-side verifier watchdog for in-process final verification and verifier-state capture.
- P0#2: already fixed by `b8f4b21b`; this round did not rework that fix, but added one focused line_info offset regression fixture.
- P1#3: updated docs to describe the current final-verify-only policy.
- P1#4: changed `ProgramSnapshot` to own map fds opened at snapshot time and reuse them for relocation/verify/ReJIT.
- P2#5/P3: removed stale fd_array JSON reader and minor fail-fast cleanup.
- P2#6: updated stale daemon/design schemas.
- P2#7: added daemon-level verifier reject/success tests through `KernelOps`.
- P2#8: moved kinsn final-image copy before Rust artifacts and added `bpfprof` executable smoke check.

## Issue Fixes

### P0#1 In-process verifier watchdog

Changed `daemon/src/commands.rs`:

- `LiveKernelOps::verify_candidate()` now clones the snapshot/bytecode/fd_array into a named watchdog thread.
- `LiveKernelOps::verifier_states()` uses the same watchdog helper.
- final verification timeout is 60s; original verifier-state capture timeout is 5s, matching the pre-pivot timeout intent.
- timeout returns a daemon error and leaves the stuck verifier thread detached. This cannot cancel a stuck kernel syscall, but it bounds the socket handler wait and lets the daemon continue after timeout.
- final verify now calls `bpfverify::verify()` so verifier rejects return a `VerifyReport`; commands writes `verifier.log` before surfacing the failure.

Added tests:

- `verifier_watchdog_times_out_without_waiting_for_worker`
- `final_verifier_reject_preserves_log_and_prog_id_in_error`
- `final_verifier_success_reaches_rejit_and_returns_success`

### P0#2 BTF line_info offset validation

No duplicate implementation. `b8f4b21b` already fixed this path.

This round added one small regression fixture:

- `line_info_normalization_drops_out_of_range_offsets`

### P1#3 per-pass verify/rollback docs drift

Updated:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/bpfopt_design_v3.md`

Docs now state that daemon runs one `bpfopt optimize` subprocess over the requested pass list, then performs one final in-process dry-run verify. It does not implement per-pass rollback.

### P1#4 ProgramSnapshot map fd ownership

Changed `daemon/crates/bpfget/src/lib.rs`:

- added `ProgramMapFd { map_id, fd: Arc<OwnedFd> }`;
- added `ProgramSnapshot::map_fds`;
- `snapshot_program()` opens map fds once while collecting map info;
- production `relocate_for_load()` resolves map ids from snapshot-owned fds instead of reopening maps;
- `RelocatedProgram` holds cloned `ProgramMapFd`s so relocated fd immediates stay valid until the load/ReJIT call finishes.

Added fd lifecycle test:

- `snapshot_owned_map_fd_survives_relocation_and_closes_on_drop`

### P2#5 fd_array JSON reader dead code

Removed `FdArray::from_json_file()` from `bpfopt/crates/kernel-sys/src/lib.rs` and dropped the now-unused `std::fs` / `std::path::Path` imports.

### P2#6 stale schema docs

Updated:

- `daemon/README.md`: removed unsupported `dry_run` optimize example.
- `docs/tmp/bpfopt_design_v3.md`: updated `VerifyReport` fields to `status`, `verifier_log`, `verifier_states`, `errno`, `jited_size`, `log_true_size`, etc.
- `docs/tmp/bpfopt_design_v3.md`: target JSON examples now include required `btf_id`.
- `docs/tmp/bpfopt_design_v3.md`: daemon socket commands now list `optimize`, `profile-start`, `profile-stop`, and `status`; `discover` is explicitly not implemented.

### P2#7 verifier reject tests

Added daemon-level tests using the existing `KernelOps` abstraction:

- verifier reject returns an error containing `prog 42` and the verifier log summary, writes `verifier.log`, and does not call ReJIT;
- verifier success proceeds to ReJIT and returns an ok `OptimizeOneResult`.

The tests use a fake `bpfopt` executable only inside the test harness; production code has no mock path.

### P2#8 Docker layering

Updated `runner/containers/runner-runtime.Dockerfile`:

- copied `/artifacts/kinsn` before Rust daemon/bpfopt artifacts in the final image;
- added `test -x /usr/local/bin/bpfprof` next to the existing `bpfopt` smoke check.

`make check` rebuilt the image and the new smoke check passed.

### P3 cleanup

- Removed `let _ = prog_id;` by dropping the unused `normalize_failure_artifacts()` parameter.
- Removed stale `#[allow(unused_imports)]` annotations from analysis result reexports.

## Line Count

Measured with `git diff --numstat b8f4b21b..HEAD` for the touched source/doc/Docker files:

- Total touched files: `+513 -91`, net `+422`.
- Code files only: `+482 -61`, net `+421`.
- Docs/README/Docker: `+31 -30`, net `+1`.

This is not a net line reduction. The required watchdog and daemon-level regression tests account for most added lines; the cleanup/removal side is `-91` lines.

## Verification

Passed:

```text
cargo test --workspace --manifest-path daemon/Cargo.toml
cargo test --manifest-path bpfopt/Cargo.toml
make daemon-tests
make check
```

`make check` ran the allowed `vm-test` path and reported `27 passed, 0 failed`. I did not run `make vm-corpus`, `make vm-e2e`, or `make vm-micro`.

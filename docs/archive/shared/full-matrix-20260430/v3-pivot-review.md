# v3 Pivot Review: commit 9bbd56f8

Scope: read-only audit of pivot commit `9bbd56f8` against the v3 architecture rules in `CLAUDE.md`, the consolidated feedback note, `docs/tmp/full-matrix-20260430/v3-arch-pivot.md`, and the updated `docs/tmp/bpfopt_design_v3.md`.

Notes:
- The current worktree has unrelated/parallel dirty state, including `daemon/crates/bpfget/src/lib.rs`. Findings below are based on `git show 9bbd56f8:<path>` / `git grep 9bbd56f8`, not on the dirty file.
- Per instruction, I did not run `cargo test`, `make check`, `vm-*`, or build-heavy commands.
- `cargo machete` is not installed in this environment (`cargo machete --version` reports no such command), so dependency dead-code checks are based on static greps only.

## Risk-Ranked Issues

### P0: In-process verifier has no hang watchdog

Status: FAIL

The old subprocess verifier path could be killed on timeout. The pivot moves verifier dry-runs in-process, but no replacement watchdog exists. A verifier infinite loop or pathological CPU-bound verifier case can block the whole daemon.

Evidence:
- `daemon/crates/bpfverify/src/lib.rs:73` starts a synchronous retry loop around `kernel_sys::prog_load_dryrun_report`.
- `daemon/crates/bpfverify/src/lib.rs:80` calls `kernel_sys::prog_load_dryrun_report` directly; the only retry condition is log buffer growth on `ENOSPC`.
- `daemon/src/commands.rs:405` calls `bpfverify::verify_pass` in-process.
- `daemon/src/commands.rs:420` calls `bpfverify::verifier_states` in-process.
- `daemon/src/server.rs:249` handles client requests inline in the server loop.
- `daemon/src/server.rs:417` dispatches `optimize` synchronously through `process_request`.

Impact:
- A stuck verifier blocks the daemon process, including new socket requests, status requests, shutdown handling, and live program work.
- `daemon/src/commands.rs:1530` / `daemon/src/commands.rs:1575` still protect subprocess stages such as `bpfopt`, but that timeout does not cover `bpfverify`.

Fix direction:
- Add an explicit daemon-level policy for verifier hangs. Either accept and document the risk, or add a watchdog that can recover the daemon process if an in-process verifier syscall does not return.
- A normal thread timeout is insufficient if the thread is stuck in the kernel verifier; the recovery mechanism must be able to abort or restart the process boundary that owns the stuck syscall.

### P0: BTF line_info is forwarded without offset normalization/validation

Status: FAIL

The pivot forwards raw `func_info` / `line_info` bytes from live `prog_info` into later dry-run/ReJIT loads. That preserves bytes, but it does not validate that each line-info `insn_off` still points to a valid instruction boundary in the candidate bytecode. This matches the known bcc failures:

`Invalid insn code at line_info[35].insn_off`

Evidence:
- `daemon/crates/bpfget/src/lib.rs:239` snapshots original bytecode via `kernel_sys::prog_get_original`.
- `daemon/crates/bpfget/src/lib.rs:252` only validates BTF blobs as raw record arrays.
- `daemon/crates/bpfget/src/lib.rs:271` stores `func_info` / `line_info` raw bytes into `ProgramSnapshot`.
- `daemon/src/commands.rs:1093` writes `snapshot.btf.func_info` and `snapshot.btf.line_info` to bpfopt side files.
- `daemon/src/commands.rs:1127` reads bpfopt-mutated BTF side files back into the candidate snapshot.
- `daemon/src/commands.rs:447` forwards candidate `btf` into `bpfverify`.
- `daemon/crates/bpfverify/src/lib.rs:87` passes `func_info` / `line_info` to `kernel_sys::prog_load_dryrun_report`.
- `bpfopt/crates/kernel-sys/src/lib.rs:598` sets libbpf load opts for `func_info` / `line_info`.

Impact:
- The architecture goal of reusing `prog->aux` metadata is only partially achieved. The bytes are reused, but the critical invariant between bytecode instruction offsets and BTF records is not enforced.
- Any transform or original-bytecode reconstruction that changes instruction layout can create verifier rejects before ReJIT.

Fix direction:
- In the existing parallel line-info fix, validate every BTF record offset against the exact candidate bytecode passed to verifier/ReJIT.
- Preserve raw records only when offsets are already valid for that bytecode.
- Fail fast with a clear daemon error if a record cannot be mapped safely.

### P1: Docs still describe per-pass verify/rollback, but daemon runs one full bpfopt pipeline and one final verify

Status: FAIL

The v3 design forbids an in-daemon `PassManager`, but docs still imply a per-pass loop with verifier acceptance after each pass. The implementation calls `bpfopt optimize` once and then verifies the final candidate.

Evidence:
- `daemon/src/commands.rs:955` invokes `bpfopt optimize`.
- `daemon/src/commands.rs:1008` performs one final verification of the optimized candidate.
- `daemon/src/commands.rs:1019` proceeds to final ReJIT after that verification.
- `docs/kernel-jit-optimization-plan.md:373` describes a daemon-side pass loop.
- `docs/kernel-jit-optimization-plan.md:379` says each pass is verified and rolled back if rejected.
- `docs/tmp/bpfopt_design_v3.md:377` describes a per-pass loop at the bytecode boundary.

Impact:
- This is not necessarily a code bug if final-verify-only is intended, but the documentation no longer describes the shipped behavior.
- Benchmark interpretation can be wrong: a single rejected late pass rejects the whole optimized candidate, while per-pass rollback would salvage earlier accepted passes.

Fix direction:
- Decide the policy explicitly:
  - Document final-verify-only as the actual v3 behavior, or
  - Change orchestration so `bpfopt` can run one pass at a time and the daemon verifies each candidate between subprocess invocations.

### P1: ProgramSnapshot does not own/reuse map fds despite docs claiming it does

Status: FAIL

The implementation avoids old JSON fd passing and does not leak fds, but it does not implement the documented "daemon-owned ProgramSnapshot holds map fds" model. Map fds are reopened for each relocation/load operation.

Evidence:
- `daemon/crates/bpfget/src/lib.rs:92` defines `ProgramSnapshot` with `info`, `maps`, `insns`, and `btf`; it does not store `OwnedFd` map fds.
- `daemon/crates/bpfget/src/lib.rs:113` opens map fds during `relocate_for_load`.
- `daemon/crates/bpfget/src/lib.rs:128` stores those fds only in the returned `RelocatedProgram`.
- `daemon/crates/bpfget/src/lib.rs:429` opens map fds temporarily in `get_map_infos`.
- `docs/tmp/bpfopt_design_v3.md:15` says the snapshot holds map fds.
- `docs/tmp/bpfopt_design_v3.md:163` repeats that `ProgramSnapshot` owns map fds.
- `docs/kernel-jit-optimization-plan.md:210` says the live snapshot directly retains map fds.

Impact:
- No unbounded fd leak was found in the pivot code path.
- However, the implementation has a race/lifecycle gap relative to the design: the map id is captured during snapshot, but the fd used for verifier/ReJIT is opened later.

Fix direction:
- Either update the design docs to describe per-call map-fd reopening, or make `ProgramSnapshot` own the map fds captured during discovery and reuse those fds through map-value reads, dry-run verification, and ReJIT.

### P2: Old fd_array JSON reader remains as unused protocol residue

Status: FAIL

The active daemon no longer uses `fd_array.json`, but `kernel-sys` still exposes a JSON reader for the old fd-array protocol with no callers in active source.

Evidence:
- `bpfopt/crates/kernel-sys/src/lib.rs:247` defines `FdArray::from_json_file`.
- Static caller search in `9bbd56f8` finds no active caller outside that definition.

Impact:
- This violates the fail-fast "no dead code / no legacy wrappers" rule.
- It also leaves a misleading old protocol API in the shared syscall/data crate.

Fix direction:
- Remove the JSON reader if the protocol is gone.
- If a test fixture still needs it, move it under test-only code instead of keeping a production API.

### P2: v3 design docs have stale socket/schema examples

Status: FAIL

Several docs no longer match the daemon protocol or data structures.

Evidence:
- `daemon/README.md:25` documents an optimize request with `dry_run`; `daemon/src/server.rs:417` ignores that field and only dispatches `cmd`, `prog_id`, and optional `enabled_passes`.
- `docs/tmp/bpfopt_design_v3.md:109` documents `VerifyReport { ok, verifier_log, states }`, while `daemon/crates/bpfverify/src/lib.rs:42` defines `status`, `verifier_log`, `verifier_states`, `errno`, and metadata fields.
- `docs/tmp/bpfopt_design_v3.md:236` shows target JSON without `btf_id`; `daemon/src/commands.rs:1369` requires `btf_id` or `btf_obj_id` for BTF fd resolution.
- `docs/tmp/bpfopt_design_v3.md:487` says the daemon accepts `discover`; `daemon/src/server.rs:417` supports only `optimize`, `profile-start`, `profile-stop`, and `status`.

Impact:
- Future agents can implement against stale docs and reintroduce protocol drift.

Fix direction:
- Update the docs to match the exact shipped JSON protocol and structs.
- If `discover` or `dry_run` are intended future endpoints, mark them explicitly as not implemented.

### P2: Missing test coverage for in-process verifier reject handling

Status: FAIL

The pivot has tests for relocation and some command helpers, but I did not find a test that exercises the key new path: in-process `bpfverify` rejects a candidate and the daemon converts that into the expected result/error path.

Evidence:
- `daemon/crates/bpfget/src/lib.rs:1028` tests multi-map relocation.
- `daemon/crates/bpfget/src/lib.rs:1083` tests BTF multi-subprogram byte preservation.
- `daemon/src/commands.rs:1675` tests bytecode decoder and kinsn target helpers.
- `daemon/src/server.rs:631` tests state handling and request validation.
- No static hit for a daemon test that forces `bpfverify::verify_pass` to return verifier reject and validates daemon response/failure artifacts.

Impact:
- The known `line_info` verifier reject was not caught by daemon tests.
- A future regression in in-process verifier error handling can silently change result shape.

Fix direction:
- Add a focused daemon/unit test using the existing `KernelOps` abstraction to simulate a verifier reject and assert the JSON/result path.
- Add one BTF line-info fixture that fails when offsets are not valid instruction boundaries.

### P2: Docker final image layering is mostly improved but not strictly aligned with CLAUDE.md

Status: WARN

The pivot correctly stops installing old standalone `bpfget`, `bpfverify`, and `bpfrejit` binaries. The remaining layer order still places kernel/kinsn final-image content after Rust artifacts.

Evidence:
- `runner/mk/build.mk:38` now lists only `bpfopt` and `bpfprof` under `ACTIVE_BPFOPT_BINARIES`.
- `runner/mk/build.mk:345` builds the daemon plus only `bpfopt` and `bpfprof`.
- `runner/containers/runner-runtime.Dockerfile:441` installs only `bpfrejit-daemon` from the daemon build.
- `runner/containers/runner-runtime.Dockerfile:471` installs only `bpfopt` and `bpfprof`.
- `runner/containers/runner-runtime.Dockerfile:517` copies daemon and bpfopt artifacts into the final image.
- `runner/containers/runner-runtime.Dockerfile:520` copies kinsn artifacts after Rust artifacts.
- `CLAUDE.md:89` says kernel + kinsn modules should be below runner/Rust/Python layers.

Impact:
- This does not appear to make Python changes rebuild apps/kernel/daemon.
- It is still a strict mismatch against the documented layering contract.

Fix direction:
- Move kinsn/kernel final image copy before Rust daemon/bpfopt copies, or document why final-image copy order is not considered part of the cache-sensitive layering contract.
- Add an explicit `test -x /usr/local/bin/bpfprof` smoke check next to the existing `bpfopt` check at `runner/containers/runner-runtime.Dockerfile:528`.

### P3: Minor fail-fast cleanup items remain

Status: WARN

Evidence:
- `daemon/src/commands.rs:225` has `let _ = prog_id;` inside `normalize_failure_artifacts`.
- `bpfopt/crates/bpfopt/src/analysis/mod.rs:13` uses `#[allow(unused_imports)]`.

Impact:
- These are not core pivot regressions, but they conflict with the strict fail-fast/no-dead-code style.

Fix direction:
- Remove the unused parameter or make it part of the function behavior.
- Remove stale reexports or gate them only where tests actually need them.

## Scope-by-Scope Review

### 1. Cross-process protocol deletion

Status: OK with one dead-code failure

Findings:
- Active daemon code no longer forks `bpfget`, `bpfverify`, or `bpfrejit`.
- Active daemon subprocess usage is limited to `bpfprof` and `bpfopt`.
- Old protocol strings such as `map_fds.json`, `fd_array.json`, `btf-info`, `verifier-states-out`, and `replay_bpfverify_report` do not remain in active `daemon/src` or `daemon/crates` code.
- Historical result files still contain old protocol strings, but those are not active code.

Evidence:
- `daemon/src/commands.rs:721` starts `bpfprof --all --per-site`.
- `daemon/src/commands.rs:955` invokes `bpfopt optimize`.
- `daemon/src/commands.rs:397` implements `LiveKernelOps` through in-process `bpfget`, `bpfverify`, and `bpfrejit` libraries.
- `daemon/src/commands.rs:1530` is the remaining generic subprocess runner for CLI stages.
- `bpfopt/crates/kernel-sys/src/lib.rs:247` still contains unused `FdArray::from_json_file`; see P2 issue above.

### 2. Dead code / fail-fast

Status: FAIL

Findings:
- No active `#[allow(dead_code)]` was found in source.
- `FdArray::from_json_file` remains as unused old fd-array JSON reader.
- `cargo machete` could not be run because it is not installed.
- Some minor style violations remain (`let _ = prog_id`, unused import allows).

Evidence:
- `bpfopt/crates/kernel-sys/src/lib.rs:247`
- `daemon/src/commands.rs:225`
- `bpfopt/crates/bpfopt/src/analysis/mod.rs:13`

### 3. FD management / lifecycle

Status: OK with design mismatch

Findings:
- No unbounded fd leak was found in the pivot path.
- Map fds opened for dry-run/ReJIT relocation are stored in `RelocatedProgram._map_fds`, keeping them alive while the load syscall runs and closing them on drop.
- Program fds opened for snapshot are local and close when snapshot collection completes.
- Invalidation tracker keeps its own `OwnedFd` handles and prunes them when tracked programs/maps are removed.
- The implementation does not hold/reuse map fds in `ProgramSnapshot` as docs claim.

Evidence:
- `daemon/crates/bpfget/src/lib.rs:92` `ProgramSnapshot` has no fd fields.
- `daemon/crates/bpfget/src/lib.rs:100` `RelocatedProgram` owns `_map_fds`.
- `daemon/crates/bpfget/src/lib.rs:113` opens map fds for relocation.
- `daemon/crates/bpfget/src/lib.rs:429` opens map fds temporarily for map info.
- `daemon/src/invalidation.rs:54` stores long-lived invalidation map fds.
- `daemon/src/invalidation.rs:80` prunes retained invalidation fds.

### 4. Zero-copy reuse of prog->aux metadata

Status: FAIL

Findings:
- Map relocation no longer uses serialized fd JSON; the daemon opens real map fds and writes those fds directly into relocated instructions.
- `func_info` / `line_info` are forwarded as raw bytes, but they are still written through bpfopt side files and read back.
- No validation was found that BTF record instruction offsets remain valid after original-bytecode reconstruction and bpfopt transforms.

Evidence:
- `daemon/crates/bpfget/src/lib.rs:136` rewrites `BPF_PSEUDO_MAP_IDX` / `BPF_PSEUDO_MAP_FD` to map fd immediates.
- `daemon/src/commands.rs:1093` writes BTF side files for `bpfopt`.
- `daemon/src/commands.rs:1127` reads BTF side files back.
- `daemon/crates/bpfverify/src/lib.rs:87` forwards BTF bytes to kernel load opts.

### 5. Daemon hang risk

Status: FAIL

Findings:
- `bpfopt` subprocesses still have timeout/kill handling.
- In-process verifier calls do not have an equivalent timeout, watchdog, or process-level recovery path.
- The server loop handles requests synchronously, so a verifier hang blocks the whole daemon.

Evidence:
- `daemon/src/commands.rs:1575` waits for subprocess timeout and kills children.
- `daemon/crates/bpfverify/src/lib.rs:80` performs direct in-process verifier dry-run.
- `daemon/src/server.rs:249` handles clients inline.

### 6. CLAUDE.md / plan doc / bpfopt_design_v3.md consistency

Status: FAIL

Findings:
- `CLAUDE.md` mostly matches the intended pivot: daemon owns kernel calls, runner stays untouched, and only `bpfopt`/`bpfprof` are external CLIs.
- `CLAUDE.md` wording that calls `bpfrejit-daemon` a remaining "standalone CLI binary crate" is slightly confusing, but acceptable if interpreted as the daemon binary crate.
- `docs/tmp/bpfopt_design_v3.md` and `docs/kernel-jit-optimization-plan.md` have stale details around map fd ownership, per-pass verify/rollback, `discover`, `dry_run`, and verifier report fields.

Evidence:
- `docs/tmp/bpfopt_design_v3.md:15`
- `docs/tmp/bpfopt_design_v3.md:109`
- `docs/tmp/bpfopt_design_v3.md:236`
- `docs/tmp/bpfopt_design_v3.md:377`
- `docs/tmp/bpfopt_design_v3.md:487`
- `docs/kernel-jit-optimization-plan.md:210`
- `docs/kernel-jit-optimization-plan.md:373`
- `daemon/README.md:25`

### 7. Cargo workspace consistency

Status: OK

Findings:
- `daemon` workspace now owns daemon plus `bpfget`, `bpfverify`, and `bpfrejit` library crates.
- `bpfopt` workspace contains only `kernel-sys`, `bpfopt`, and `bpfprof`.
- No direct CLI crate dependency from daemon to `bpfopt` lib was found.
- No direct `libc::syscall(SYS_bpf, ...)` calls were found outside `kernel-sys`.

Evidence:
- `daemon/Cargo.toml:7` lists daemon workspace members.
- `daemon/Cargo.toml:19` points daemon workspace dependency `kernel-sys` to `../bpfopt/crates/kernel-sys`.
- `daemon/Cargo.toml:30` depends on `bpfget`, `bpfrejit`, and `bpfverify`.
- `bpfopt/Cargo.toml:1` lists only `kernel-sys`, `bpfopt`, and `bpfprof` workspace members.
- `bpfopt/crates/kernel-sys/src/lib.rs:554` is the syscall boundary for BPF commands.

### 8. Test coverage

Status: FAIL

Findings:
- I did not run tests per instruction.
- Existing visible tests cover relocation helpers, BTF byte preservation, server state validation, and command helper logic.
- I did not find coverage for in-process `bpfverify` rejection through daemon result handling.
- I did not find a line-info validity regression test that would catch the known bcc failure.

Evidence:
- `daemon/crates/bpfget/src/lib.rs:1028`
- `daemon/crates/bpfget/src/lib.rs:1083`
- `daemon/src/commands.rs:1675`
- `daemon/src/server.rs:631`

### 9. build.mk / Makefile / Dockerfile

Status: OK with layering warning

Findings:
- Build scripts no longer build/install old standalone `bpfget`, `bpfverify`, or `bpfrejit` binaries.
- `bpfopt` and `bpfprof` remain as expected external CLIs.
- Runtime Python/YAML/config files are separated from compile-source dependency lists in `runner/mk/build.mk`.
- Docker final-image kinsn copy order is not strictly aligned with the documented layer order.

Evidence:
- `runner/mk/build.mk:38`
- `runner/mk/build.mk:91`
- `runner/mk/build.mk:173`
- `runner/mk/build.mk:345`
- `runner/containers/runner-runtime.Dockerfile:441`
- `runner/containers/runner-runtime.Dockerfile:471`
- `runner/containers/runner-runtime.Dockerfile:517`
- `runner/containers/runner-runtime.Dockerfile:520`

### 10. Runner Python boundary

Status: OK

Findings:
- No runner/corpus/e2e/micro Python diff was found in commit `9bbd56f8`.
- Runner still sends the same daemon socket commands: `optimize`, `profile-start`, and `profile-stop`.
- Daemon server still accepts `optimize`, `profile-start`, `profile-stop`, and `status`.
- The daemon response payload is more minimal than old docs, but runner normalization tolerates missing pass verify/action fields.

Evidence:
- `runner/libs/rejit.py:754`
- `runner/libs/rejit.py:786`
- `daemon/src/server.rs:417`
- `runner/libs/rejit.py:221`
- `runner/libs/rejit.py:259`

## Bottom Line

The pivot substantially removed the old forked kernel-helper CLI architecture from active daemon code and kept the runner boundary stable. The main quality gaps are not in workspace wiring; they are in the consequences of moving verifier work in-process:

1. There is no verifier hang recovery path.
2. BTF line-info metadata is forwarded without enough validation against the exact candidate bytecode.
3. Docs still describe stronger semantics than the code provides, especially per-pass verify/rollback and map-fd ownership.
4. A small amount of old protocol dead code remains in `kernel-sys`.

Recommended fix order:
1. P0: finish the line-info normalization/validation work already in progress.
2. P0: decide and implement/document the verifier hang recovery policy.
3. P1: reconcile docs with actual final-verify-only behavior, or change orchestration to true per-pass verify.
4. P1: decide whether `ProgramSnapshot` should own map fds; then make docs and implementation agree.
5. P2: remove `FdArray::from_json_file` and stale README/design schema examples.
6. P2: add focused daemon tests for verifier reject handling and line-info offset validity.

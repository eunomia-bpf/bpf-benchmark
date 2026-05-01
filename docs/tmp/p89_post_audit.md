# P89 Post-Audit

Scope: read-only audit of daemon, bpfopt, runner libs/suites, and driver code against `CLAUDE.md`, `docs/kernel-jit-optimization-plan.md`, and `docs/tmp/bpfopt_design_v3.md`. I did not inspect or modify `vendor/linux-framework/` or `module/`.

Baseline observed during audit: `da8a9b0c chore: clean git state -- track docs/results, ignore claude lock + replay bin`. The user-requested `c61f0559` is no longer HEAD in this worktree.

Validation performed:
- `cargo check --workspace` in `bpfopt/`: pass.
- `cargo check` in `daemon/`: pass.
- `cargo +nightly udeps --workspace` in `bpfopt/`: not run, nightly toolchain is not installed.
- `cargo +nightly udeps` in `daemon/`: not run, nightly toolchain is not installed.

## Top Immediate Fixes

1. DELETE kernel syscall retry fallbacks that can convert verifier-log failures into success: `bpfopt/crates/kernel-sys/src/lib.rs:374` and `bpfopt/crates/kernel-sys/src/lib.rs:1410`.
2. DELETE partial-program result paths in corpus stats: `corpus/driver.py:381` and `runner/libs/bpf_stats.py:71`.
3. DELETE stale `BPFREJIT_DAEMON_FAILURE_LAYOUT` export: `runner/containers/runner-runtime.Dockerfile:589`.
4. DELETE or explicitly redesign `map_inline` heuristic fallback key extraction: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1178` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1232`.
5. Resolve daemon v3 ownership drift: `daemon/src/server.rs:449` profile socket commands and `daemon/src/commands.rs:1062` daemon-owned optimize pipeline.
6. DELETE unused bytecode dump API and stale low-value tests/comments: `bpfopt/crates/bpfopt/src/insn.rs:425`, `daemon/src/invalidation.rs:233`, `runner/src/kernel_runner.cpp:968`.

## Findings

### BLOCKER: verifier-log retry changes BPF load result

- Location: `bpfopt/crates/kernel-sys/src/lib.rs:370`, `bpfopt/crates/kernel-sys/src/lib.rs:374`, `bpfopt/crates/kernel-sys/src/lib.rs:393`
- Problem: `prog_load_dryrun_report()` retries `bpf_prog_load` without verifier logging after a failed load when errno is `ENOSPC` or the log appears to reach a safe exit. If the retry succeeds, it returns `accepted: true`.
- Violation: Fail-fast/no fallback. A failed verifier-log-capable load becomes an accepted dry-run, hiding the original failure and making log-buffer problems look like success.
- Recommendation: DELETE the retry-without-log branch. Return the original errno/log and require callers to size logs or fail. After removal, DELETE `verifier_log_reaches_safe_exit()` at `bpfopt/crates/kernel-sys/src/lib.rs:244` unless another real caller remains.

### BLOCKER: ReJIT retry can return Ok after first syscall failed

- Location: `bpfopt/crates/kernel-sys/src/lib.rs:1402`, `bpfopt/crates/kernel-sys/src/lib.rs:1410`, `bpfopt/crates/kernel-sys/src/lib.rs:1425`
- Problem: `prog_rejit()` retries `BPF_PROG_REJIT` without verifier logging after the first syscall fails, and returns `Ok(())` if the retry succeeds.
- Violation: Fail-fast/no fallback/no silenced errors. The first ReJIT failure is not naturally surfaced in the result.
- Recommendation: DELETE the retry path. Return the first syscall error and verifier log summary.

### HIGH: stale daemon failure layout env remains

- Location: `runner/containers/runner-runtime.Dockerfile:586`, `runner/containers/runner-runtime.Dockerfile:589`
- Problem: the runtime still exports `BPFREJIT_DAEMON_FAILURE_LAYOUT=active-run-details`. Current source only reads `BPFREJIT_DAEMON_FAILURE_ROOT` at `daemon/src/commands.rs:21`; the layout env has no reader in current code.
- Violation: dead env / deleted active-run-details guard residue.
- Recommendation: DELETE the `BPFREJIT_DAEMON_FAILURE_LAYOUT` export. KEEP `BPFREJIT_DAEMON_FAILURE_ROOT`.

### HIGH: corpus rediscovery accepts partial program sets

- Location: `corpus/driver.py:381`, `corpus/driver.py:388`, `corpus/driver.py:395`
- Problem: when rediscovery returns fewer BPF programs than expected, the runner emits `session_warning` with `accepting partial set` and continues with a smaller live program list.
- Violation: fail-fast/no partial results. It can silently drop programs from benchmark accounting.
- Recommendation: DELETE the partial-accept path. If `refreshed_count < expected_count`, raise with expected, missing, and refreshed IDs.

### HIGH: missing BPF stats are warning-and-continue

- Location: `runner/libs/bpf_stats.py:71`, `runner/libs/bpf_stats.py:73`, `runner/libs/bpf_stats.py:77`
- Problem: `sample_bpf_stats_from_records()` logs a warning when requested program IDs are missing, then returns partial stats.
- Violation: no silenced errors / no partial results. Missing tracked programs should be a hard measurement error, not a warning.
- Recommendation: DELETE warning-and-continue. Raise with the missing IDs, or require an explicit caller mode for best-effort diagnostics only.

### HIGH: map_inline still has heuristic fallback extraction

- Location: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1178`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1198`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1232`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1247`
- Problem: verifier-guided key extraction falls back to backward scanning and pseudo-map-value extraction. Non-verifier mode also uses both fallback paths.
- Violation: fail-fast/no fallback. Missing verifier capability becomes heuristic success instead of a visible defect.
- Recommendation: DELETE production heuristic fallback after verifier-guided miss. If backward scan is still desired, make it an explicit experimental mode, not an implicit fallback in the default pass.

### MEDIUM: v1 map_inline terminology remains in production API

- Location: `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:52`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:61`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:69`
- Problem: production methods are still named `is_inlineable_v1()`, `can_remove_lookup_pattern_v1()`, and `is_speculative_v1()`.
- Violation: v1 historical residue. These are real production helpers, not dead code, but the naming keeps old architecture semantics alive.
- Recommendation: KEEP behavior if still correct, but DELETE the v1 naming and comments. Rename around current semantics, for example direct-value support, removable lookup pattern, and speculative runtime invalidation.

### MEDIUM: daemon owns profile lifecycle

- Location: `daemon/src/server.rs:66`, `daemon/src/server.rs:192`, `daemon/src/server.rs:449`, `daemon/src/server.rs:465`, `daemon/src/commands.rs:412`, `daemon/src/commands.rs:808`
- Problem: daemon keeps profile state and exposes `profile-start` / `profile-stop` socket commands. It spawns external `bpfprof --all --per-site`, so this is not in-process profiling, but the daemon still owns the profiling lifecycle.
- Violation: `docs/tmp/bpfopt_design_v3.md` says daemon must not do profiling internally and should shrink to socket/watch/invalidation plus external commands. This is also in tension with the later Option B note in `CLAUDE.md`, which allows daemon delegation to CLI subprocesses.
- Recommendation: DELETE daemon profile state/socket commands if the v3 design doc remains authoritative. Otherwise KEEP the behavior and update the design doc to explicitly bless daemon-owned external profile lifecycle.

### MEDIUM: daemon constructs optimize/verify/rejit pipeline

- Location: `daemon/src/commands.rs:1046`, `daemon/src/commands.rs:1062`, `daemon/src/commands.rs:1077`, `daemon/src/commands.rs:1080`, `daemon/src/commands.rs:1092`
- Problem: daemon chooses profile side inputs, invokes `bpfopt optimize`, reads reports, scans candidate bytecode for kinsn calls, and then continues verify/rejit.
- Violation: no in-process transform was found, but the daemon still owns a multi-step pass pipeline. Strict v3 text says per-pass/optimize orchestration belongs in external scripts, while CLAUDE Option B says daemon may delegate optimize/rejit/profile/discover to CLI subprocesses.
- Recommendation: KEEP only if Option B is now policy. If `docs/tmp/bpfopt_design_v3.md` is still authoritative, DELETE daemon pipeline construction and move it behind a single external script/command boundary.

### MEDIUM: daemon response schema errors are converted to per-program failure

- Location: `runner/libs/rejit.py:612`, `runner/libs/rejit.py:648`, `runner/libs/rejit.py:649`, `runner/libs/rejit.py:653`
- Problem: `_apply_result_from_response()` catches response-shape `RuntimeError`, changes `exit_code` to 1, clears `passes`, and returns a normalized result.
- Violation: fail-fast/no silenced schema errors. A daemon/runner contract violation becomes a normal-looking failed ReJIT result.
- Recommendation: DELETE the catch-and-normalize path. Raise schema errors immediately so protocol drift is visible.

### MEDIUM: unused public bytecode dump API

- Location: `bpfopt/crates/bpfopt/src/insn.rs:425`, `bpfopt/crates/bpfopt/src/insn.rs:437`, `bpfopt/crates/bpfopt/src/insn.rs:449`
- Problem: `BpfInsnDump`, `BpfBytecodeDump`, and `dump_bytecode_compact()` have no callers in audited source. The comment says they are used in socket responses, but daemon no longer imports them.
- Violation: dead public API / stale comment.
- Recommendation: DELETE the structs/function, or move them behind `#[cfg(test)]` only if tests need them.

### LOW: invalid artifact timestamp is silently replaced

- Location: `runner/libs/run_artifacts.py:90`, `runner/libs/run_artifacts.py:95`, `runner/libs/run_artifacts.py:97`
- Problem: invalid `generated_at` is swallowed and replaced with the current time.
- Violation: fail-fast/no silenced parse errors for artifact identity.
- Recommendation: DELETE the silent fallback for non-empty invalid input. Raise `ValueError`; keep current-time generation only when `generated_at` is absent.

### LOW: optional process identity read is silently ignored

- Location: `runner/libs/run_artifacts.py:106`, `runner/libs/run_artifacts.py:109`, `runner/libs/run_artifacts.py:113`
- Problem: `/proc/<pid>/stat` read/parse failures are ignored while building metadata.
- Violation: weak fail-fast signal, but this is optional launcher metadata.
- Recommendation: KEEP if launcher identity is purely diagnostic. DELETE the field or make failures explicit if later code uses it for active-run ownership.

### LOW: trivial unit test covers record storage only

- Location: `daemon/src/invalidation.rs:233`, `daemon/src/invalidation.rs:239`, `daemon/src/invalidation.rs:240`
- Problem: `test_record_inline_site()` mostly verifies that a just-pushed struct is present in the internal vector. Behavior paths are already covered by invalidation/change/batch tests starting at `daemon/src/invalidation.rs:251`.
- Violation: unit test quality rule against trivial storage tests.
- Recommendation: DELETE this test unless it is upgraded to catch a real duplicate/update/invalidation bug.

### LOW: stale TODO comment

- Location: `runner/src/kernel_runner.cpp:968`
- Problem: `// TODO: moved to Python orchestrator (§5.6)` looks like historical migration residue.
- Violation: stale TODO residue.
- Recommendation: DELETE or replace with a concrete current bug/task reference.

## KEEP / No-Issue Results

- Active-run metadata guard: no current source hit for `expected exactly one active`, `found {n}, expected`, or metadata scanning for current/active run. Current metadata hits are writes only: `runner/libs/run_artifacts.py:67`, `corpus/driver.py:905`, `micro/driver.py:692`.
- BranchFlip PGO: KEEP. The pass requires program-level PMU at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:82`, per-site profile at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:122`, and validates branch counters/miss rate/direction counters at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:279`. `bpfprof` emits per-site `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken` at `bpfopt/crates/bpfprof/src/main.rs:893`.
- Corpus metrics: KEEP. Per-program comparison uses `avg_ns_per_run` and only includes programs with positive baseline and post-ReJIT run counts at `corpus/driver.py:143`; output includes `per_program` and `summary` at `corpus/driver.py:799`.
- CLI cross-dependencies: KEEP. The six CLI crates depend on `kernel-sys` only for shared syscall/data access, for example `bpfopt/crates/bpfopt/Cargo.toml:16`, `bpfopt/crates/bpfverify/Cargo.toml:16`, `bpfopt/crates/bpfprof/Cargo.toml:19`, `bpfopt/crates/bpfrejit/Cargo.toml:16`, and `bpfopt/crates/bpfget/Cargo.toml:16`. `daemon/Cargo.toml:14` depends on `kernel-sys`, not `bpfopt`.
- Direct BPF syscall boundary: KEEP with the retry exceptions above. `libc::syscall(SYS_bpf)` appears only behind `kernel-sys` at `bpfopt/crates/kernel-sys/src/lib.rs:274`. The other syscall hit at `bpfopt/crates/kernel-sys/src/lib.rs:975` is `perf_event_open`, not `SYS_bpf`.
- Daemon in-process pass code: KEEP. I found no in-daemon `PassManager`, no in-process bytecode transform, and no verifier-log parser. `daemon/src/commands.rs:1861` only truncates verifier logs for error summaries.
- Test-only APIs: KEEP. `PassManager::pass_names()` is `#[cfg(test)]` at `bpfopt/crates/bpfopt/src/pass.rs:962`; current uses in `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:214` and `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:227` validate pipeline selection/order.

## History Signals

`git log --since=2026-04-01 -- runner/libs runner/suites corpus/driver.py e2e/driver.py micro/driver.py` shows broad runner changes during the v3 period, not only bug fixes/stale-data updates. The concrete current-code DELETE findings above cover the risky remnants I found. The highest-risk history entries to review before further runner work:

- `9884d106 Fix rediscovery: accept partial program sets with warning` maps directly to the current fail-soft path at `corpus/driver.py:381`.
- `ba5c011b Refactor and optimize workload and executor code` touched `corpus/driver.py`, `runner/libs/rejit.py`, `runner/libs/workload.py`, executors, and app runners.
- `e5badc7e Refactor workload measurement annotations...` touched 13 runner files and removed/reshaped measurement annotations.
- `0c9dfdf3 Simplify case_common lifecycle...` touched `corpus/driver.py` and `runner/libs/case_common.py`.
- `5edf29e4 Expand workloads to trigger more BPF programs...` added about 1000 lines to `runner/libs/workload.py`.

Recommendation: KEEP history-only commits until a concrete behavior bug is identified, but freeze further runner refactors during v3 migration. Treat current fail-soft paths as DELETE.

## Path-Only Cleanup Signals

These are generated/build artifacts, not source file:line findings:

- `daemon/build`: 8 KiB.
- `tests/unittest/build`: 60 MiB.
- `tests/negative/build`: 220 KiB.
- `vendor/llvmbpf/build`: 560 MiB.
- Known existing large v1 residue remains `corpus/build` at 1.4 GiB and `runner/repos` at 768 MiB.

Recommendation: DELETE generated build directories from the worktree/cache policy if they are not required for reproducible local runs. Do not touch `vendor/linux-framework/` or `module/`.

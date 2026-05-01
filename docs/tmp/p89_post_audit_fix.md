# P89 Post-Audit Fix Report

Scope: targeted fixes for `docs/tmp/p89_post_audit.md` plus the KVM v4 blocker where `daemon serve` exited when `BPFREJIT_DAEMON_FAILURE_ROOT` was unset. This did not touch `vendor/linux-framework/` or `module/`.

## KVM v4 Blocker

Status: FIXED.

- `daemon/src/commands.rs`: `FailureExportConfig::from_env()` no longer requires `BPFREJIT_DAEMON_FAILURE_ROOT`.
- If the env var is set, the daemon uses it exactly.
- If the env var is unset, the daemon defaults to `<cwd>/bpfrejit-failures`.
- An explicitly empty env var remains an error.
- The existing write-probe path still creates the directory and verifies it is writable.

Reason: `daemon serve` is started by runner code without this env var, so a hard env requirement prevented the corpus run from reaching application-level ReJIT results.

## Audit Findings

### verifier-log retry changes BPF load result

Status: FIXED.

- Removed the `prog_load_dryrun_report()` retry-without-log path from `bpfopt/crates/kernel-sys/src/lib.rs`.
- Removed the now-dead `verifier_log_reaches_safe_exit()` helper and its unit test.
- Dry-run load failures now return the original errno and verifier log summary to the caller.

### ReJIT retry can return Ok after first syscall failed

Status: FIXED.

- Removed the `prog_rejit()` retry-without-log path from `bpfopt/crates/kernel-sys/src/lib.rs`.
- ReJIT now surfaces the first syscall failure and verifier log summary instead of attempting a second syscall without log capture.

### stale daemon failure layout env remains

Status: FIXED.

- Removed `BPFREJIT_DAEMON_FAILURE_LAYOUT=active-run-details` from `runner/containers/runner-runtime.Dockerfile`.
- Kept `BPFREJIT_DAEMON_FAILURE_ROOT`; it still provides a useful explicit export root in runtime images.

### corpus rediscovery accepts partial program sets

Status: FIXED.

- `corpus/driver.py` now raises when rediscovery returns fewer programs than expected.
- The error includes expected IDs, refreshed IDs, and missing IDs.
- Removed the "accepting partial set" warning-and-continue path.

### missing BPF stats are warning-and-continue

Status: FIXED.

- `runner/libs/bpf_stats.py` now raises when requested program IDs are missing from sampled stats.
- Partial stats are no longer returned for tracked program sets with missing IDs.

### map_inline still has heuristic fallback extraction

Status: FIXED.

- Removed production fallback key extraction after verifier-guided lookup key extraction misses.
- Removed pseudo-map-value lookup key extraction fallback.
- Removed non-verifier fallback extraction for post-rewrite rounds.
- Added real verifier-state offset plumbing through `bpfverify` JSON output and `bpfopt` JSON input so verifier-guided map lookup key recovery can use actual verifier register offsets.
- Updated tests to assert skip/error behavior when verifier-guided state is unavailable, including wide keys and pseudo-map-value lookup keys.

### v1 map_inline terminology remains in production API

Status: FIXED.

- Renamed `is_inlineable_v1()` to `supports_direct_value_inline()`.
- Renamed `can_remove_lookup_pattern_v1()` to `has_removable_lookup_pattern()`.
- Renamed `is_speculative_v1()` to `has_speculative_invalidation()`.
- Removed v1-specific comments while preserving behavior.

### daemon owns profile lifecycle

Status: KEPT.

Reason: current implementation owns only the external lifecycle and spawns `bpfprof`; it does not run an in-process profiler. `docs/tmp/bpfopt_design_v3.md` now explicitly documents daemon-owned external `profile-start` / `profile-stop` lifecycle as v3 Option B compliant.

### daemon constructs optimize/verify/rejit pipeline

Status: KEPT.

Reason: current implementation delegates bytecode transform, verification, ReJIT, profiling, and discovery to CLI subprocesses. It does not link `bpfopt`, run `PassManager`, parse verifier logs for transform decisions, or transform bytecode in-process. `docs/tmp/bpfopt_design_v3.md` now explicitly documents daemon sequencing of external CLI subprocesses as v3 Option B compliant.

### daemon response schema errors are converted to per-program failure

Status: FIXED.

- Removed the `_apply_result_from_response()` `RuntimeError` catch-and-normalize path in `runner/libs/rejit.py`.
- Response schema errors now raise immediately so protocol drift remains visible.

### unused public bytecode dump API

Status: FIXED.

- Removed `BpfInsnDump`, `BpfBytecodeDump`, and `dump_bytecode_compact()` from `bpfopt/crates/bpfopt/src/insn.rs`.
- Removed the stale socket-response comment and unused serde import.

### invalid artifact timestamp is silently replaced

Status: FIXED.

- `runner/libs/run_artifacts.py` now raises `ValueError` for non-empty invalid `generated_at`.
- It falls back to current time only when `generated_at` is absent.

### optional process identity read is silently ignored

Status: KEPT.

Reason: launcher process identity remains optional diagnostic metadata only. The audit recommended keeping it unless later code uses it for active-run ownership.

### trivial unit test covers record storage only

Status: FIXED.

- Removed `test_record_inline_site()` from `daemon/src/invalidation.rs`.

### stale TODO comment

Status: FIXED.

- Removed the stale migration TODO from `runner/src/kernel_runner.cpp`.

## Diff Summary

- Daemon failure export root is cwd-relative by default and still write-probed.
- Kernel syscall wrappers no longer retry without verifier logs.
- Runner fail-soft paths for corpus rediscovery, BPF stats, daemon schema errors, and invalid artifact timestamps now raise.
- `map_inline` no longer silently falls back to heuristic key extraction; verifier-state offsets are now carried through the `bpfverify` -> `bpfopt` JSON boundary.
- v1 naming and dead bytecode dump API were removed.
- v3 design docs now explicitly describe Option B daemon delegation boundaries.
- Dead Docker env and stale/trivial cleanup items were removed.

## Validation

Passed:

- `cd bpfopt && cargo check --workspace`
- `cd bpfopt && cargo test --workspace --release`
- `cd daemon && cargo build --release`
- `cd daemon && cargo test --release`

Blocked by missing test path:

- `python -m pytest tests/python/ -v` exits 4 because `tests/python/` does not exist in this checkout.

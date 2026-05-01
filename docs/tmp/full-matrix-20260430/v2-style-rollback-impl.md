# v2-Style Rollback Implementation Report

Date: 2026-05-01

## Summary

Implemented the v2-style rollback while keeping the v3 boundaries that worked: `bpfopt` and `bpfprof` stay as CLIs, `kernel-sys` remains the only syscall boundary, runner Python stays on the daemon socket protocol, and daemon bytecode transforms still happen out-of-process through `bpfopt`.

The daemon main path is now:

```text
runner socket optimize
  -> daemon bpfget snapshot
  -> optional map-values / target side inputs
  -> optional const_prop thin dry-run only when explicitly requested
  -> bpfopt CLI
  -> daemon-built in-memory fd_array
  -> kernel_sys::prog_rejit()
```

No main-path `BPF_PROG_LOAD` dry-run remains. `BPF_PROG_REJIT` failures surface as errors with preserved artifacts.

## Step Coverage

| Step | Status | Notes |
|---|---:|---|
| 1. Cut daemon main path | Done | `try_apply_one_with_map_access` now snapshots, runs `bpfopt`, builds `fd_array`, then calls direct ReJIT. |
| 2. Delete `bpfverify` lib | Done | Removed `daemon/crates/bpfverify`; verifier-state parser moved to `kernel-sys`. |
| 3. Compress `bpfget` | Done | Removed BTF func/line info snapshotting, normalization, relocation reconstruction, and replay protocol. |
| 4. Inline `bpfrejit` | Done | Removed `daemon/crates/bpfrejit`; daemon calls `kernel_sys::prog_rejit()` directly. |
| 5. Add thin dry-run | Done | `daemon/src/dry_run.rs`; 5s timeout; `func_info = None`, `line_info = None`. |
| 6. Integrate `const_prop` | Done | Explicit `const_prop` triggers verifier-state capture; default pipeline skips it. |
| 7. Delete residual protocol code | Done | No active daemon `map_fds.json`, `fd_array.json`, `btf-info`, or `verifier-states-out` protocol remains. |
| 8. Update docs | Done | Updated `CLAUDE.md`, `docs/tmp/bpfopt_design_v3.md`, `docs/kernel-jit-optimization-plan.md`, plan doc, and daemon README. |
| 9. Tests | Done | See test results below. |
| 10. Report + commit | Done in this change | Single commit covers code, docs, and this report. |

## Quantitative Result

Plan target: daemon kernel-facing Rust from 6,756 lines to <= 2,400 lines, net reduction >= 4,300.

Actual production kernel-facing count:

```text
daemon/src/commands.rs production before tests: 1643
daemon/src/dry_run.rs production before tests:   161
daemon/crates/bpfget/src/lib.rs:                 523
total:                                          2327
```

Result: 6,756 -> 2,327, net -4,429 lines. This meets both thresholds: <= 2,400 and >= 4,300 lines removed.

Module-level comparison:

| Area | Expected | Actual |
|---|---:|---:|
| `daemon/crates/bpfverify` | 1,369 -> 0 | deleted |
| `daemon/crates/bpfrejit` | 77 -> 0 | deleted |
| `daemon/crates/bpfget` | 250-450 lines | 523 lines |
| `daemon/src/commands.rs` | 700-1,000 lines | 1,643 production lines, 1,967 raw including tests |
| thin dry-run | 200-300 lines | 161 production lines, 192 raw |
| total daemon kernel-facing production | <= 2,400 | 2,327 |

`commands.rs` remains above the per-file estimate because it still owns socket command orchestration, profile lifecycle, failure artifact preservation, map invalidation integration, and focused regression tests. The acceptance metric is the total daemon kernel-facing production count, which is under target.

## Design Checks

- Zero reconstruction: `bpfget` keeps `prog_info`/`map_ids` as kernel-provided data; daemon does not reverse-map old pseudo-map immediates.
- No BTF func/line replay: `ProgramSnapshot` no longer stores BTF func_info/line_info bytes; thin dry-run passes `func_info = None`, `line_info = None`.
- `const_prop` default off: removed from default `bpfopt optimize` pass lists and `corpus/config/benchmark_config.yaml`.
- No ReJIT filtering added.
- No fallback path added for failed dry-run, missing verifier states, failed `bpfopt`, or failed `BPF_PROG_REJIT`.
- `kernel-sys` remains the only BPF syscall boundary.

## Test Results

All allowed tests passed:

- `cargo test --workspace --manifest-path daemon/Cargo.toml`: passed, 23 daemon tests.
- `cargo test --workspace --manifest-path bpfopt/Cargo.toml`: passed, including bpfopt lib/bin/CLI, bpfprof, kernel-sys, and integration tests.
- `make daemon-tests`: passed, 23 daemon tests.
- `make check`: passed. This ran `vm-test` only, with `RESULTS: 27 passed, 0 failed`, including fuzz `1000/1000` rounds.

Forbidden targets were not run:

- `make vm-corpus`: not run.
- `make vm-e2e`: not run.
- `make vm-micro`: not run.

## Claude vm-corpus Handoff

Next verification should be run by Claude:

```bash
make vm-corpus
```

Expected focus:

- The round 9 daemon/replay bug classes should disappear: multi-map relocation, BTF line_info offset, replay context, timeout ramp, verifier-states-out protocol, line_info invalid offset, and kernel pointer immediate.
- Workload bugs can still remain: HTTP/1.1, timerfd, and open stressor are not daemon architecture bugs.
- Corpus should target 8/8 apps reaching `rejit_done ok`, except app baseline workload defects should remain classified separately.

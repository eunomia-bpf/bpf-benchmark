# P84 Combined Self-Review

Date: 2026-04-30

Base: `27618d66` (`docs(review): P83 review P78+P82 + next-round candidates`)
Head: `de8438e1` (`refactor(bpfget,bpfprof): require --output file for metadata/profile (v3 §10 stdout = raw bpf_insn only)`)

Scope: P84 removed the remaining P83 warning surfaces around no-real-PGO `branch_flip`, bpfprof PMU placeholders, pass/daemon debug payloads, stale runner exclusion schema, map provider layering, map-info placement, and non-bytecode JSON stdout.

## Stage Summary

| Stage | Commit | Result |
| --- | --- | --- |
| 1 | `86f35fdd` | Deleted `branch_flip` pass, CLI subcommand, registry/default-pass entry, tests, and bpfprof nullable PMU/per-insn placeholders. Default optimize pipeline is now 11 passes. |
| 2 | `39b08b80` | Deleted PassManager debug traces plus daemon `dry_run`, `attempts`, `timings_ns`, and runner artifact/debug-result storage for that response surface. |
| 3 | `5e83021f` | Deleted stale runner `policy.rules[].disable` provenance, `final_disabled_passes` summaries, and unused benchmark-config `profiles` parsing. Pass selection behavior still comes from `policy.default.passes` or explicit env override. |
| 4 | `e525b840` | Collapsed `MapInfoProvider` and `MapValueProvider` into a single `MapProvider`; snapshot and mock providers now implement one interface. |
| 5 | `ce91f5a8` | Moved `map_info` under `passes/map_inline/`; `analysis/` no longer owns a map-inline-only analysis module. |
| 6 | `de8438e1` | Required side-output files for bpfget JSON metadata/list/target and bpfprof profile JSON. Raw bytecode remains the only bpfget stdout payload. |

## LOC Delta

| Stage | Insertions | Deletions | Net |
| --- | ---: | ---: | ---: |
| 1 | 39 | 1614 | -1575 |
| 2 | 70 | 432 | -362 |
| 3 | 4 | 90 | -86 |
| 4 | 43 | 43 | 0 |
| 5 | 26 | 29 | -3 |
| 6 | 150 | 58 | +92 |
| Total, commits | 332 | 2266 | -1934 |

`git diff --shortstat 27618d66..HEAD -- . ':(exclude).claude/scheduled_tasks.lock'` reports 35 files changed, 324 insertions, 2258 deletions, net `-1934`. The required net LOC target `<= -800` is satisfied.

## P83 Warning Items

| P83 item | Status | Notes |
| --- | --- | --- |
| Delete/quarantine `branch_flip` and bpfprof PMU placeholders | Done | No active `branch_flip` pass, CLI, registry entry, default pass, or bpfprof `branch_misses`/`branch_instructions`/`per_insn` placeholder remains. |
| Delete PassManager debug traces and daemon attempts/timings/dry-run | Done | Active daemon response no longer carries `attempts` or `timings_ns`; runner no longer stores a full debug copy. |
| Delete stale runner disabled-pass/profile schema | Done | `policy.rules[].disable`, `benchmark_policy_exclusions`, `final_disabled_passes`, and unused `profiles` config override support were removed from active runner code. |
| Collapse map provider/mock stack | Done | One `MapProvider` trait replaces separate metadata/value providers. |
| Move map_info closer to map-inline | Done | `map_info.rs` now lives at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`; shared `analysis/` keeps branch target, CFG, and liveness. |
| Enforce JSON side-output files | Done | bpfget JSON modes require `--output`; bpfprof requires `--output` or `--output-dir`; only raw bytecode uses stdout. |

## Verification

- Stage 1: `cargo build --workspace`, `cargo test --workspace`, `cargo clippy --workspace --all-targets -- -D warnings`, daemon build/test/clippy, and `git diff --check` passed.
- Stage 2: bpfopt build/test/clippy, daemon build/test/clippy, field grep, and `git diff --check` passed.
- Stage 3: `python -m compileall -q runner/libs/rejit.py runner/libs/run_artifacts.py`, targeted provenance smoke commands, active schema grep, and `git diff --check` passed.
- Stage 4: bpfopt build/test/clippy and stale provider grep passed.
- Stage 5: bpfopt build/test/clippy passed after moving map-info under map-inline.
- Stage 6: bpfopt build/test/clippy, daemon build/test/clippy, stdout JSON grep, and `git diff --check` passed.

No KVM, Docker, or AWS smoke was run, per task constraint. The unrelated local `.claude/scheduled_tasks.lock` modification was not staged.

## Final Checklist

- 12-pass to 11-pass: done.
- PMU placeholder fields deleted: done.
- Debug response surface deleted: done.
- Map provider traits collapsed: done.
- `map_info` inlined into map-inline ownership: done.
- bpfget/bpfprof metadata/profile stdout removed: done.
- No CLI cross-dependencies added: done.
- No syscall-boundary changes outside `kernel-sys`: done.
- Net LOC at least -800: done, net `-1934`.

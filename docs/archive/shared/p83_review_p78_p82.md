# P83 Strict Review: P78 + P82 Cumulative Changes

Date: 2026-04-30

Scope:

- P78: `6621d896..8e99747d` (8 commits, self-reported net -1514 LOC)
- P82: `1bb76903..69c9e1b5` (8 commits, self-reported net -833 LOC)
- Cumulative source/doc diff from `6ab0083a..69c9e1b5`: 38 files, 1273 insertions, 3620 deletions, net -2347 LOC.

Method: read-only source/doc audit, `rg`, `git diff`, `git blame`, and targeted line reads. I did not run cargo, KVM, Docker, or AWS, per task constraint. Current main was `69c9e1b5`.

## A. P74/P76 5 Criticals

| Item | Status | Evidence | Short review |
| --- | --- | --- | --- |
| 1. daemon bare `optimize` / `optimize-all` vs 12-pass default | ✅ | `daemon/src/server.rs:441`, `daemon/src/server.rs:443`, `daemon/src/server.rs:458`, `daemon/src/commands.rs:1118`, `daemon/src/commands.rs:1121` | `optimize-all` is gone from the server match; `optimize` rejects missing/empty `enabled_passes` before fork and the command layer has a second fail-fast guard. |
| 2. `ProgramWatcher` swallowed BPF errors | ✅ | `daemon/src/server.rs:161`, `daemon/src/server.rs:164`, `daemon/src/server.rs:170`, `daemon/src/server.rs:172`, `daemon/src/server.rs:198`, `daemon/src/server.rs:212` | `from_live()` / `tick()` now return `Result`; enumeration errors propagate to `cmd_serve()` instead of warning-and-continuing. |
| 3. `status` silenced `list-passes` failure | ⚠️ | `daemon/src/server.rs:520`, `daemon/src/server.rs:525`, `daemon/src/server.rs:527`; P82 self-report `docs/tmp/p82_combined_review.md:14` | The specific fallback is deleted because `status` no longer shells out to `bpfopt list-passes`. Current `status` is weaker: it always returns daemon health/version/profiling and no longer hard-errors when CLI tools are broken. |
| 4. `disabled_passes` full-chain deletion | ⚠️ | Active daemon only parses `enabled_passes`: `daemon/src/server.rs:436`; bpfopt policy has only `enabled_passes`: `bpfopt/crates/bpfopt/src/pass.rs:836`; residual runner schema/artifact code: `runner/libs/rejit.py:415`, `runner/libs/rejit.py:421`, `runner/libs/rejit.py:472`, `runner/libs/run_artifacts.py:180`, `runner/libs/run_artifacts.py:207` | Active ReJIT filtering is gone, but full-codebase grep is not clean. Runner still understands `policy.rules[].disable` as provenance and summarizes `final_disabled_passes`. It does not appear to filter the pass list, but the forbidden/stale surface remains. |
| 5. `branch_flip` heuristic fallback | ✅ | `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:30`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:86`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:147`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:150` | Heuristic fallback is gone. Missing program PMU skips the pass; missing per-site profile skips the site rather than flipping. |

Verdict: no active P74-level ❌ remains, but item 4 is not grep-clean and item 3 is now a deliberately weaker health command.

## B. P81 Priority List

| Item | Status | Evidence | Short review |
| --- | --- | --- | --- |
| 1. `disabled_passes` | ⚠️ | `bpfopt/crates/bpfopt/src/pass.rs:836`, `runner/libs/rejit.py:415`, `runner/libs/run_artifacts.py:180` | Daemon/bpfopt active path is fixed. Runner-side stale schema/artifact support should still be deleted or rejected to make the rule enforceable. |
| 2. `scan-map-keys` moved out of public `bpfopt` | ✅ | bpfopt command list has no `scan-map-keys`: `bpfopt/crates/bpfopt/src/main.rs:148`; daemon internal scanner: `daemon/src/commands.rs:969` | Public v3 `bpfopt` stdout is no longer JSON for map-key scans; live key scanning is daemon/kernel-facing code through `kernel-sys`. |
| 3. `branch_flip` + PMU profile surface | ⚠️ | `bpfopt/crates/bpfprof/src/main.rs:185`, `bpfopt/crates/bpfprof/src/main.rs:192`, `bpfopt/crates/bpfprof/src/main.rs:195`, `bpfopt/crates/bpfprof/src/main.rs:304`, `bpfopt/crates/bpfprof/src/main.rs:308`, `bpfopt/crates/bpfopt/src/main.rs:968` | P78 removed the heuristic transform, but `bpfprof` still emits nullable program branch fields and empty `per_insn`; PMU counts are read then discarded. This leaves `branch_flip` effectively unusable with the shipped profiler. |
| 4. daemon `optimize-all`, profile save/load, status help | ✅ | P82 stages: `docs/tmp/p82_combined_review.md:13`, `docs/tmp/p82_combined_review.md:14`; current status: `daemon/src/server.rs:520` | The bulk/debug socket commands are gone; `status.available_passes_help` is gone. |
| 5. PassManager fixed-point + debug API | ⚠️ | Linear run loop: `bpfopt/crates/bpfopt/src/pass.rs:1004`; debug traces remain: `bpfopt/crates/bpfopt/src/pass.rs:890`, `bpfopt/crates/bpfopt/src/pass.rs:908`, `bpfopt/crates/bpfopt/src/pass.rs:1069`, `bpfopt/crates/bpfopt/src/pass_tests.rs:428` | The `const_prop+dce` fixed-point special case is gone, but always-allocated debug trace machinery remains and is protected by tests. |

## C. Cargo Verification Self-Report

| Item | Status | Evidence | Short review |
| --- | --- | --- | --- |
| Build/clippy/test | ✅ | P78: `docs/tmp/p78_combined_fix_review.md:55`; P82: `docs/tmp/p82_combined_review.md:13`, `docs/tmp/p82_combined_review.md:18` | Self-reported build/clippy/test passed for touched Rust crates. I did not rerun. |
| `#[allow(dead_code)]` | ✅ | `rg "#\\[allow\\(dead_code\\)\\]" bpfopt/crates daemon/src` returned no hits | No current dead-code allow remains in bpfopt/daemon source. |
| Other allow/warnings | ⚠️ | `bpfopt/crates/bpfopt/src/analysis/mod.rs:15`, `:17`, `:19`, `:21` | `#[allow(unused_imports)]` remains for analysis result re-exports. Not `dead_code`, but still cleanup smell. No unused-warning verification was rerun locally. |

## D. New Violations / Silence Grep

| Check | Status | Evidence | Short review |
| --- | --- | --- | --- |
| `.ok()` / `unwrap_or_default` / `let _ =` / empty `if let Err` | ✅ | Test-only unwrap default: `daemon/src/invalidation.rs:165`, `daemon/src/invalidation.rs:209`; handled cleanup error: `bpfopt/crates/bpfget/src/main.rs:823`, `bpfopt/crates/bpfget/src/main.rs:837`; logged cleanup: `daemon/src/commands.rs:96` | I found no new production BPF syscall / IO parse error silently discarded by P78/P82. Remaining grep hits are test mocks, cleanup in `Drop`, or explicitly converted errors. |
| `#[cfg(test)]` in `src/` outside test modules | ✅ | Test-only modules/helpers: `bpfopt/crates/bpfopt/src/lib.rs:9`, `bpfopt/crates/bpfopt/src/lib.rs:14`, `bpfopt/crates/bpfopt/src/pass.rs:944`, `bpfopt/crates/bpfopt/src/pass.rs:955` | No production fallback appears hidden behind `cfg(test)`. The test-gated mock map provider is deliberate. |
| daemon `pub` surface | ✅ | `daemon/src/bpf.rs:13`, `daemon/src/invalidation.rs:12`, `daemon/src/invalidation.rs:21`, `daemon/src/invalidation.rs:30`, `daemon/src/invalidation.rs:54`; test-only public helpers: `daemon/src/invalidation.rs:69`, `daemon/src/invalidation.rs:74` | P82/P78 narrowed daemon API to `pub(crate)` except test-only methods on crate-private types. Good enough for a binary crate. |

## E. v3 §10 stdin/stdout Raw `bpf_insn[]`

| Surface | Status | Evidence | Short review |
| --- | --- | --- | --- |
| `bpfopt` transforms and `optimize` | ✅ | Single pass reads/writes bytecode: `bpfopt/crates/bpfopt/src/main.rs:402`, `bpfopt/crates/bpfopt/src/main.rs:413`; optimize writes bytecode: `bpfopt/crates/bpfopt/src/main.rs:428`, `bpfopt/crates/bpfopt/src/main.rs:447`; raw I/O: `bpfopt/crates/bpfopt/src/main.rs:631`, `bpfopt/crates/bpfopt/src/main.rs:661` | Transform stdout remains raw `struct bpf_insn[]`. `list-passes` is metadata, not a transform pipeline. |
| `bpfget` default / `--info` / `--full` / `--target` | ⚠️ | Default raw bytecode: `bpfopt/crates/bpfget/src/main.rs:191`, `bpfopt/crates/bpfget/src/main.rs:195`; `--info` JSON stdout: `bpfopt/crates/bpfget/src/main.rs:181`, `bpfopt/crates/bpfget/src/main.rs:185`; `--full` files: `bpfopt/crates/bpfget/src/main.rs:356`, `bpfopt/crates/bpfget/src/main.rs:400`; `--target` JSON stdout/file: `bpfopt/crates/bpfget/src/main.rs:445`, `bpfopt/crates/bpfget/src/main.rs:467` | Default mode is compliant. Metadata modes write JSON to stdout if no `--output`; that matches existing v3 examples but is still suspicious under the strictest "stdout raw" reading. |
| `bpfverify --pipe` behavior | ✅ | Verify pass-through: `bpfopt/crates/bpfverify/src/main.rs:282`, `bpfopt/crates/bpfverify/src/main.rs:283`; report/states side files: `bpfopt/crates/bpfverify/src/main.rs:268`, `bpfopt/crates/bpfverify/src/main.rs:272`; raw output writer: `bpfopt/crates/bpfverify/src/main.rs:343` | Accepted bytecode is passed through raw; JSON reports/states are files. |
| `bpfrejit` | ✅ | Raw input: `bpfopt/crates/bpfrejit/src/main.rs:97`; final syscall path: `bpfopt/crates/bpfrejit/src/main.rs:108`; summary stderr/file: `bpfopt/crates/bpfrejit/src/main.rs:437`, `bpfopt/crates/bpfrejit/src/main.rs:441` | It consumes raw bytecode and does not put JSON on stdout. |
| `bpfprof` JSON stdout | ⚠️ | Daemon uses output dir: `daemon/src/commands.rs:1003`, `daemon/src/commands.rs:1007`; CLI stdout fallback: `bpfopt/crates/bpfprof/src/main.rs:228`, `bpfopt/crates/bpfprof/src/main.rs:235` | Reasonable as a profile side-output CLI, but stricter v3 can require `--output`/`--output-dir` to avoid non-bytecode stdout. Placeholder profile fields are the larger issue. |

## F. CLI Cross-Dependency / Syscall Boundary

| Check | Status | Evidence | Short review |
| --- | --- | --- | --- |
| Six CLI crates do not path-depend on each other | ✅ | `bpfopt/crates/bpfopt/Cargo.toml:11`, `bpfopt/crates/bpfget/Cargo.toml:11`, `bpfopt/crates/bpfverify/Cargo.toml:11`, `bpfopt/crates/bpfprof/Cargo.toml:11`, `bpfopt/crates/bpfrejit/Cargo.toml:11` | Each CLI depends on workspace/common crates only; no CLI-to-CLI path-dep. |
| daemon depends on `kernel-sys`, not `bpfopt` | ✅ | `daemon/Cargo.toml:11`, `daemon/Cargo.toml:14` | `bpfrejit-daemon` has no `bpfopt` path dependency. Cargo description is stale, though: `daemon/Cargo.toml:5`. |
| `kernel-sys` syscall boundary | ✅ | Rule comment: `bpfopt/crates/kernel-sys/src/lib.rs:3`; direct syscall helper: `bpfopt/crates/kernel-sys/src/lib.rs:210`; upstream wrapper example: `bpfopt/crates/kernel-sys/src/lib.rs:328`; fork REJIT syscall: `bpfopt/crates/kernel-sys/src/lib.rs:780`; original bytecode via extended info: `bpfopt/crates/kernel-sys/src/lib.rs:798` | Direct `SYS_bpf` remains only in `kernel-sys`, and the only direct command path found is fork-only `BPF_PROG_REJIT`. Standard commands use libbpf-sys wrappers. |

## G. Benchmark Framework / Vendor Scope

| Check | Status | Evidence | Short review |
| --- | --- | --- | --- |
| `runner/libs/`, `e2e/cases/`, `micro/driver.py` untouched | ✅ | P82 self-report: `docs/tmp/p82_combined_review.md:69`; cumulative diff touched no files in those paths except `corpus/config/benchmark_config.yaml` | Runner Python boundary stayed stable. |
| `corpus/config/benchmark_config.yaml` change | ✅ | Current config: `corpus/config/benchmark_config.yaml:1`, `corpus/config/benchmark_config.yaml:3`, `corpus/config/benchmark_config.yaml:14` | P82 deleted duplicate `passes.performance` and unused `profiles`; default policy pass list remains. No app-loader or filtering behavior was added. |
| Runner stale config support | ⚠️ | Skeleton/profiles still supported: `runner/libs/rejit.py:136`, `runner/libs/rejit.py:166`; rules parser still supported: `runner/libs/rejit.py:415` | This was intentionally not touched, but it is a next-round deletion candidate. |
| `vendor/linux-framework` / `module/` unchanged | ✅ | P78 self-report: `docs/tmp/p78_combined_fix_review.md:56`; P82 self-report: `docs/tmp/p82_combined_review.md:69`; current submodule HEAD `a1b8bade169fae6e174ef022fa96fb1c626d96df` | No vendor/module source changes in the reviewed range. |

## H. Next-Round Deletion Audit

| Question | Status | Evidence | Candidate |
| --- | --- | --- | --- |
| v3 §10 suspicious surfaces | ⚠️ | `bpfopt/crates/bpfget/src/main.rs:181`, `bpfopt/crates/bpfget/src/main.rs:445`, `bpfopt/crates/bpfprof/src/main.rs:228` | Require metadata/profile tools to use `--output` for JSON side-output, or document these as non-pipeline metadata exceptions. |
| Trait abstraction overdone | ⚠️ | Analysis registry: `bpfopt/crates/bpfopt/src/pass.rs:852`, `bpfopt/crates/bpfopt/src/pass.rs:870`; map providers: `bpfopt/crates/bpfopt/src/pass.rs:201`, `bpfopt/crates/bpfopt/src/pass.rs:210` | No plugin system exists; a simpler fixed analysis set and one map snapshot provider would be enough. |
| Tests that mostly lock placeholders/mocks | ⚠️ | Nullable profile test: `bpfopt/crates/bpfprof/src/main.rs:382`; mock provider: `bpfopt/crates/bpfopt/src/mock_maps.rs:27`, `bpfopt/crates/bpfopt/src/mock_maps.rs:103` | Delete tests that defend nullable PMU placeholders; shrink map mock once tests use explicit snapshot data. |
| Schema fields daemon writes but runner barely reads | ⚠️ | daemon response: `daemon/src/commands.rs:571`, `daemon/src/commands.rs:577`, `daemon/src/commands.rs:653`, `daemon/src/commands.rs:671`; runner only validates core fields and stores full debug copy: `runner/libs/rejit.py:684`, `runner/libs/rejit.py:718`, `runner/libs/rejit.py:748` | `attempts`, `failure_pc`, `attributed_pass`, `timings_ns`, and full `debug_result` are mostly debug/legacy payload. |
| daemon `optimize` args/response redundancy | ⚠️ | `dry_run` request: `daemon/src/server.rs:387`, `daemon/src/server.rs:391`; runner apply path always false: `runner/libs/rejit.py:928`; dry-run attempt result: `daemon/src/commands.rs:1395` | Delete daemon `dry_run` unless a real caller needs it. It is a partial-result mode adjacent to deleted `bpfrejit --dry-run`. |
| 12 passes simplification | ⚠️ | Pass registry includes `branch_flip`: `bpfopt/crates/bpfopt/src/passes/mod.rs:112`; profiler cannot produce per-site profile: `bpfopt/crates/bpfprof/src/main.rs:195` | No obvious merge among the core bytecode/kfunc passes; `branch_flip` is the obvious quarantine/delete until true PGO exists. |
| `mock_maps.rs` can shrink | ⚠️ | `bpfopt/crates/bpfopt/src/mock_maps.rs:1`, `bpfopt/crates/bpfopt/src/mock_maps.rs:169`; callers: `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:5` | Current file is 169 LOC, not 125. Moving tests to explicit `program.map_metadata` / `map_values` can remove thread-local global state. |
| analysis modules multiple production users | ⚠️ | CFG used by const_prop/dce/utils: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:183`, `bpfopt/crates/bpfopt/src/passes/dce.rs:36`, `bpfopt/crates/bpfopt/src/passes/utils.rs:202`; liveness used by many passes: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:405`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:115`; map_info mainly map-inline: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:783` | CFG/liveness should stay shared. `map_info` is effectively map-inline-only in production and can move closer to that pass. |
| bpfprof PMU/per-insn placeholders | ⚠️ | `bpfopt/crates/bpfprof/src/main.rs:60`, `bpfopt/crates/bpfprof/src/main.rs:63`, `bpfopt/crates/bpfprof/src/main.rs:192`, `bpfopt/crates/bpfprof/src/main.rs:195` | Delete nullable PMU/per-insn fields or implement real per-site attribution. |
| daemon `optimize` informational fields | ⚠️ | `daemon/src/commands.rs:566`, `daemon/src/commands.rs:567`, `daemon/src/commands.rs:577`, `daemon/src/commands.rs:578` | `passes_applied`, `timings_ns`, and some `program` counts duplicate `passes`/`summary` or serve only debugging. |

## Must Fix

No immediate P74-level ❌ critical remains. Before claiming the tree is fully clean, fix these:

1. ⚠️ Delete or reject runner `policy.rules[].disable` and `final_disabled_passes` support. Active filtering is gone, but the forbidden schema/artifact surface remains in `runner/libs/rejit.py:415` and `runner/libs/run_artifacts.py:180`.
2. ⚠️ Resolve the `branch_flip` / `bpfprof` contract. Either implement real program PMU + per-site `per_insn` data, or delete/quarantine `branch_flip` and remove nullable PMU placeholder fields from `bpfprof`.
3. ⚠️ Delete debug/legacy daemon response surfaces after confirming runner artifacts do not need them: `attempts`, `failure_pc`, `attributed_pass`, `timings_ns`, and daemon `dry_run`.

## Top 5 Next Deletion Candidates

| Priority | Candidate | Evidence | Estimated LOC delta |
| --- | --- | --- | ---: |
| 1 | Delete/quarantine current `branch_flip` + prune `bpfprof` placeholder PMU/per-insn fields | `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:37`, `bpfopt/crates/bpfprof/src/main.rs:54` | Conservative -90 to -160; aggressive with pass/tests -700 to -1100 |
| 2 | Delete runner stale exclusion/profile schema and artifact disabled-pass summaries | `runner/libs/rejit.py:136`, `runner/libs/rejit.py:415`, `runner/libs/run_artifacts.py:180` | -80 to -160 |
| 3 | Delete PassManager debug traces + daemon attempts/timings/dry-run response surface | `bpfopt/crates/bpfopt/src/pass.rs:890`, `daemon/src/commands.rs:571`, `daemon/src/server.rs:387` | -140 to -280 |
| 4 | Collapse map provider/mock stack and move map_info closer to map-inline | `bpfopt/crates/bpfopt/src/pass.rs:201`, `bpfopt/crates/bpfopt/src/mock_maps.rs:1`, `bpfopt/crates/bpfopt/src/analysis/map_info.rs:101` | -120 to -240 |
| 5 | Enforce file-only JSON side-output for metadata/profile commands | `bpfopt/crates/bpfget/src/main.rs:181`, `bpfopt/crates/bpfget/src/main.rs:445`, `bpfopt/crates/bpfprof/src/main.rs:228` | -30 to -80 |

Conservative next round: about -450 to -900 LOC. Aggressive branch_flip deletion path: about -1100 to -1800 LOC.

## I. Overall

- Architecture cleanliness: **8/10**, up from P74's 7/10.
- Active criticals: **0 ❌**.
- Important residuals: **3 ⚠️** (`disabled_passes` stale runner surface, `bpfprof`/`branch_flip` placeholder contract, debug/legacy daemon schema).
- LOC estimate: bpfopt-suite + daemon Rust/Cargo source is about **31.4K LOC** (`git ls-files` over `bpfopt/crates/*/src`, `daemon/src`, and Cargo manifests). Including bpfopt/daemon integration tests it is about **32.6K LOC**.


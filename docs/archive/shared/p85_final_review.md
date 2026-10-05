# P85 Final Review Before Three-Platform Smoke

Date: 2026-04-29

Base/head under review:
- Required `main`: `c5b4e905`
- Observed HEAD: `c5b4e9058bc1e7b673d5e3eff6b4bc849084a44e`
- Dirty local state before this review: unrelated `.claude/scheduled_tasks.lock`; left untouched.

Scope and constraints:
- Read-only review of source and docs, except this report.
- Did not run cargo build/test/clippy, KVM, Docker, or AWS. P84 self-report is trusted per task constraint.
- Primary references checked: `CLAUDE.md`, `docs/kernel-jit-optimization-plan.md`, `docs/tmp/bpfopt_design_v3.md`, P74/P76/P78/P81/P82/P83/P84 review docs, and the three memory feedback files.

## Executive Result

| Area | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| P84 Rust/daemon core cleanup | ✅ | `bpfopt/crates/bpfopt/src/passes/mod.rs:53`, `daemon/src/commands.rs:554` | Optimizer registry, default order, daemon optimize response, PMU placeholders, map provider collapse, and file-only bpfget/bpfprof JSON behavior are aligned with P84 intent. |
| Strict `branch_flip` whole-repo cleanup | ❌ | `runner/libs/rejit.py:24`, `runner/libs/rejit.py:764`, `micro/config/micro_pure_jit.yaml:746`, `tests/unittest/rejit_pass_correctness.c:278` | The optimizer pass is gone, but active runner/micro/unittest surfaces still contain `branch_flip`. This fails the P85 grep-clean requirement. |
| Smoke blocker status | ⚠️ | `corpus/config/benchmark_config.yaml:1`, `runner/libs/rejit.py:352` | I found no clear Docker/cargo/socket source blocker for smoke, but the `branch_flip` residue should be fixed before claiming final cleanup. |
| Architecture score | ⚠️ | `docs/tmp/p83_review_p78_p82.md:115`, `daemon/src/server.rs:431` | Improved from P83's 8/10 to 8.5/10. Not 9+ because stale profile socket commands and branch_flip runner hooks remain. |

## A. P84 改动 Sanity Check

| Check | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| A1. `branch_flip` / `BranchFlipPass` deleted cleanly | ❌ | `runner/libs/rejit.py:24`, `runner/libs/rejit.py:47`, `runner/libs/rejit.py:764`, `runner/libs/rejit.py:816`, `runner/libs/input_specs.yaml:214`, `micro/config/micro_pure_jit.yaml:746`, `tests/unittest/rejit_pass_correctness.c:278` | `BranchFlipPass` and optimizer registry/subcommand are gone, but whole-codebase active grep is not clean. Residual runner profiling hook can still call `profile-start` if stale pass config injects `branch_flip`. |
| A2. `PASS_REGISTRY` is 11 and default order synchronized | ✅ | `bpfopt/crates/bpfopt/src/passes/mod.rs:53`, `bpfopt/crates/bpfopt/src/passes/mod.rs:109`, `bpfopt/crates/bpfopt/src/main.rs:23`, `bpfopt/crates/bpfopt/src/main.rs:37`, `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:140` | Registry has 11 entries, `DEFAULT_OPTIMIZE_PASS_ORDER` aliases the same 11-name list, and CLI test asserts 11 names and no `branch-flip`. Plan doc says 11 pass CLI at `docs/kernel-jit-optimization-plan.md:416`; CLAUDE has no stale pass count list. |
| A3. bpfprof PMU placeholder removed | ✅ | `bpfopt/crates/bpfprof/src/main.rs:51`, `bpfopt/crates/bpfprof/src/main.rs:78`, `bpfopt/crates/bpfprof/src/main.rs:159` | `ProfileJson` has only `prog_id`, `duration_ms`, `run_cnt_delta`, and `run_time_ns_delta`; collection uses `BPF_STATS_RUN_TIME` only. No active `branch_misses`, `branch_instructions`, `per_insn`, or PMU placeholder fields found. |
| A4. PassManager debug traces removed | ✅ | `bpfopt/crates/bpfopt/src/pass.rs:893`, `bpfopt/crates/bpfopt/src/pass.rs:916` | `PassManager::run` now accumulates only pass results, sites, and changed flag. Active grep for `debug_trace`, `attempted_passes`, and `PassDebugTrace` had no hits. |
| A5. Daemon response no longer has debug/timing fields | ✅ | `daemon/src/commands.rs:554`, `daemon/src/commands.rs:594`, `daemon/src/server.rs:409` | `OptimizeOneResult` no longer carries `attempts`, `failure_pc`, `attributed_pass`, `timings_ns`, or `dry_run`. Active grep hits for `attempts`/`failure_pc` are unrelated AWS retry state or `bpfverify` verifier-log parsing, not daemon response fields. |
| A6. `policy.rules[].disable` deleted; parser consistency | ⚠️ | `corpus/config/benchmark_config.yaml:1`, `runner/libs/rejit.py:136`, `runner/libs/rejit.py:352`, `runner/libs/rejit.py:362` | Active config and parser use only `policy.default.passes` or legacy `passes.active_list`. Stale YAML containing `policy.rules[].disable` plus a valid default pass list is silently ignored rather than rejected; stale YAML with only rules.disable fails because no pass list exists. No filtering behavior remains, but this is not fully fail-fast against stale schema. |
| A7. `MapInfoProvider`/`MapValueProvider` collapsed into `MapProvider` | ✅ | `bpfopt/crates/bpfopt/src/pass.rs:169`, `bpfopt/crates/bpfopt/src/pass.rs:196`, `bpfopt/crates/bpfopt/src/pass.rs:306`, `bpfopt/crates/bpfopt/src/pass.rs:328` | Single `MapProvider` owns metadata, value-size, and lookup methods. Stale trait grep had no active hits; mock/snapshot providers use the unified path. |
| A8. `analysis/map_info.rs` moved under map-inline | ✅ | `bpfopt/crates/bpfopt/src/analysis/mod.rs:4`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:12`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:100`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:112` | Shared `analysis/` now has only branch target, CFG, and liveness. `MapInfoAnalysis` is map-inline-owned and calls `program.map_provider`. No `analysis::map_info` active references found. |
| A9. bpfget/bpfprof force side-output and daemon paths are correct | ✅ | `bpfopt/crates/bpfget/src/main.rs:173`, `bpfopt/crates/bpfget/src/main.rs:227`, `bpfopt/crates/bpfget/src/main.rs:230`, `bpfopt/crates/bpfprof/src/main.rs:103`, `daemon/src/commands.rs:921`, `daemon/src/commands.rs:1047`, `daemon/src/commands.rs:1079` | bpfget JSON metadata modes require `--output`, `--full` requires `--outdir`, bpfprof requires `--output`/`--output-dir`, and daemon uses those file paths. |

## B. Cargo / Clippy / Test Sanity

| Check | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| P84 cargo build/clippy/test self-report | ✅ | `docs/tmp/p84_combined_review.md:48`, `docs/tmp/p84_combined_review.md:53` | P84 reports workspace build/test/clippy and daemon build/test/clippy passed. Not rerun by P85 constraint. |
| `#[allow(dead_code)]` residue | ✅ | `CLAUDE.md:28` | Project-owned active grep for `#[allow(dead_code)]` had no hits; only docs/vendor/repo mirrors contain examples. |
| Other `#[allow(...)]` residue / unused warning risk | ⚠️ | `bpfopt/crates/bpfopt/src/analysis/mod.rs:13`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:15`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:17`, `bpfopt/crates/bpfverify/src/verifier_log.rs:19`, `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:73` | No dead-code allow, but `#[allow(unused_imports)]` remains on result reexports. P84 self-report says `-D warnings` passed; this is a cleanup smell, not a proven warning. |

## C. v3 §10 stdin/stdout raw `bpf_insn` Sanity

| Tool / mode | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| Design rule baseline | ✅ | `docs/tmp/bpfopt_design_v3.md:86`, `docs/tmp/bpfopt_design_v3.md:88`, `docs/tmp/bpfopt_design_v3.md:91` | v3 requires raw binary bytecode on stdin/stdout and side inputs/outputs via files. |
| `bpfopt` transform subcommands | ✅ | `bpfopt/crates/bpfopt/src/main.rs:378`, `bpfopt/crates/bpfopt/src/main.rs:388`, `bpfopt/crates/bpfopt/src/main.rs:403`, `bpfopt/crates/bpfopt/src/main.rs:421`, `bpfopt/crates/bpfopt/src/main.rs:424` | Single-pass and `optimize` paths read bytecode and write bytecode; JSON report is file-only via `--report`. |
| `bpfopt list-passes --json` | ⚠️ | `bpfopt/crates/bpfopt/src/main.rs:355`, `bpfopt/crates/bpfopt/src/main.rs:368`, `bpfopt/crates/bpfopt/src/main.rs:650` | Metadata command can still emit JSON to stdout when `--output` is omitted. This is not a bytecode transform pipeline violation, but it is a residual if “any stdout JSON” is interpreted literally. |
| `bpfverify` | ✅ | `bpfopt/crates/bpfverify/src/main.rs:282`, `bpfopt/crates/bpfverify/src/main.rs:299`, `bpfopt/crates/bpfverify/src/main.rs:343`, `bpfopt/crates/bpfverify/src/main.rs:357` | Reads raw bytecode from file/stdin, writes raw passthrough bytecode on success, and writes JSON reports/states only to requested files. |
| `bpfrejit` | ✅ | `bpfopt/crates/bpfrejit/src/main.rs:97`, `bpfopt/crates/bpfrejit/src/main.rs:108`, `bpfopt/crates/bpfrejit/src/main.rs:136`, `bpfopt/crates/bpfrejit/src/main.rs:437` | Reads raw bytecode, calls `kernel_sys::prog_rejit`, emits summary JSON to stderr and optional file, not stdout. |
| `bpfget --info/--target/--full` | ✅ | `bpfopt/crates/bpfget/src/main.rs:173`, `bpfopt/crates/bpfget/src/main.rs:193`, `bpfopt/crates/bpfget/src/main.rs:227`, `bpfopt/crates/bpfget/src/main.rs:230`, `bpfopt/crates/bpfget/src/main.rs:736` | Raw bytecode remains stdout-capable; JSON metadata is file-only; `--full` writes a directory. |
| `bpfprof` | ✅ | `bpfopt/crates/bpfprof/src/main.rs:90`, `bpfopt/crates/bpfprof/src/main.rs:103`, `bpfopt/crates/bpfprof/src/main.rs:187` | Profile JSON is file-only or directory-only. |
| Any stdout JSON residue | ⚠️ | `bpfopt/crates/bpfopt/src/main.rs:355`, `bpfopt/crates/bpfopt/src/main.rs:650` | Only known active residue is `bpfopt list-passes --json`. |

## D. CLI Cross-Dependency / Syscall Boundary

| Check | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| Workspace members | ✅ | `bpfopt/Cargo.toml:1`, `bpfopt/Cargo.toml:3`, `bpfopt/Cargo.toml:8` | bpfopt workspace contains `kernel-sys` plus 5 CLI crates: `bpfopt`, `bpfget`, `bpfrejit`, `bpfverify`, `bpfprof`. |
| CLI crates do not path-depend on each other | ✅ | `bpfopt/crates/bpfopt/Cargo.toml:11`, `bpfopt/crates/bpfget/Cargo.toml:11`, `bpfopt/crates/bpfverify/Cargo.toml:11`, `bpfopt/crates/bpfprof/Cargo.toml:11`, `bpfopt/crates/bpfrejit/Cargo.toml:11` | Each CLI crate depends on `kernel-sys`; no CLI-to-CLI path dependency found. |
| Daemon does not depend on `bpfopt` lib | ✅ | `daemon/Cargo.toml:11`, `daemon/Cargo.toml:14` | Daemon depends on `kernel-sys`, serde/json/clap/anyhow/libc; no `bpfopt` dependency. |
| `kernel-sys` syscall boundary | ✅ | `bpfopt/crates/kernel-sys/src/lib.rs:1`, `bpfopt/crates/kernel-sys/src/lib.rs:13`, `bpfopt/crates/kernel-sys/src/lib.rs:210`, `bpfopt/crates/kernel-sys/src/lib.rs:780` | Direct `SYS_bpf` call is isolated in `kernel-sys` and used for fork-only `BPF_PROG_REJIT`. Standard BPF helpers use libbpf/libbpf-sys. |
| `BPF_PROG_GET_ORIGINAL` handling | ✅ | `docs/kernel-jit-optimization-plan.md:414`, `bpfopt/crates/kernel-sys/src/lib.rs:798`, `bpfopt/crates/kernel-sys/src/lib.rs:821` | Current implementation reads fork `orig_prog_*` fields through `BPF_OBJ_GET_INFO_BY_FD`, not a separate direct syscall command. This matches the updated plan text. |
| Daemon direct BPF syscall grep | ✅ | `daemon/src/bpf.rs:4`, `daemon/src/bpf.rs:15`, `bpfopt/crates/kernel-sys/src/lib.rs:212` | Active grep for `libc::syscall`/`SYS_bpf` outside `kernel-sys` found no daemon or CLI direct BPF syscall. |
| Stale daemon description/docs | ⚠️ | `daemon/Cargo.toml:5`, `daemon/src/main.rs:4` | Comments still say daemon “optimizes” or applies bytecode rewrites; implementation is socket-to-CLI, but stale wording should be cleaned later. |

## E. Benchmark Framework Integrity

| Check | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| `runner/libs/rejit.py` still feeds corpus/e2e | ✅ | `runner/libs/rejit.py:352`, `runner/libs/rejit.py:752`, `corpus/driver.py:597`, `corpus/driver.py:667`, `e2e/driver.py:266`, `e2e/driver.py:291`, `runner/libs/case_common.py:181`, `runner/libs/case_common.py:255` | Corpus/e2e still start `DaemonSession` and pass `enabled_passes` from benchmark config into daemon optimize. |
| `corpus/`, `e2e/cases/`, `micro/driver.py` touched by P78+P82+P84 | ✅ | `corpus/config/benchmark_config.yaml:1`, `runner/libs/rejit.py:352`, `runner/libs/run_artifacts.py:19` | From P78 base through P84, diffs in benchmark runner surface were `corpus/config/benchmark_config.yaml`, `runner/libs/rejit.py`, and `runner/libs/run_artifacts.py`; `e2e/cases/` and `micro/driver.py` were not touched. |
| `vendor/linux-framework` / `module/` state | ✅ | `vendor/linux-framework` gitlink `a1b8bade169fae6e174ef022fa96fb1c626d96df`; `module` tree `f2c02ad5b3f49cbdfa0c372c0745f0c6cde6d79e` | `vendor/linux-framework` submodule HEAD is still `a1b8bade1`. `module/` is a tracked tree here, not a submodule; no diff in the reviewed range. |
| Benchmark config schema after simplification | ⚠️ | `corpus/config/benchmark_config.yaml:1`, `runner/libs/rejit.py:352`, `runner/libs/rejit.py:362` | Default config parses and provides all 11 passes. Stale `policy.rules[].disable` is not used, but unknown stale keys are not rejected. |

## F. 还能删什么：Last-Round Candidates

| Candidate | Status | Evidence | Recommendation |
| --- | --- | --- | --- |
| `bpfopt` CLI subcommands | ✅ | `bpfopt/crates/bpfopt/src/main.rs:143`, `bpfopt/crates/bpfopt/src/passes/mod.rs:53` | The 11 pass subcommands map to the active registry/default set; do not delete before smoke. `list-passes --json` could require `--output` later if strict stdout rule is extended to metadata. |
| Daemon socket protocol | ⚠️ | `daemon/src/server.rs:409`, `daemon/src/server.rs:431`, `daemon/src/server.rs:447`, `daemon/src/server.rs:472`, `runner/libs/rejit.py:764`, `runner/libs/rejit.py:816` | Runner’s real path uses `optimize`. `profile-start`/`profile-stop` are only tied to stale branch_flip preparation and are deletable with branch_flip cleanup. `status` is mostly health/test surface. |
| `daemon/src/commands.rs` size | ⚠️ | `daemon/src/commands.rs:921`, `daemon/src/commands.rs:950`, `daemon/src/commands.rs:1027`, `daemon/src/commands.rs:1155` | 2552 LOC. Biggest safe deletion after smoke is profile session plumbing once branch_flip residue is removed. Optimize orchestration is still real. |
| `pass.rs` / `PassManager` | ⚠️ | `bpfopt/crates/bpfopt/src/pass.rs:169`, `bpfopt/crates/bpfopt/src/pass.rs:893` | 1013 LOC. Can likely shrink by simplifying `AnalysisRegistry`/registration ceremony, but it is broad shared surface. Do not cut before smoke. |
| `mock_maps.rs` | ⚠️ | `bpfopt/crates/bpfopt/src/mock_maps.rs:1`, `bpfopt/crates/bpfopt/src/pass.rs:328` | 165 LOC. Could move tests to explicit per-program map snapshots/providers later, but current helper is not a smoke risk. |
| Merge 11 passes | ✅ | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:725`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:183`, `bpfopt/crates/bpfopt/src/passes/dce.rs:36` | Do not merge. `map_inline`, `const_prop`, and `dce` are sequentially synergistic but have distinct responsibilities and test surfaces. |
| Shared analyses | ✅ | `bpfopt/crates/bpfopt/src/passes/mod.rs:139`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:183`, `bpfopt/crates/bpfopt/src/passes/dce.rs:36`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:114`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:402` | CFG, liveness, and branch-target analyses are used by multiple passes and tests; keep. |
| CLI tests triviality | ✅ | `bpfopt/crates/bpfprof/tests/cli.rs:3`, `bpfopt/crates/bpfprof/tests/cli.rs:25`, `bpfopt/crates/bpfget/tests/cli.rs:47`, `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:140` | The sampled tests check error paths, side-output contracts, environment gating, and branch-flip regression. No obvious trivial must-delete before smoke. |

## G. Overall Assessment

| Question | Status | Evidence | Answer |
| --- | --- | --- | --- |
| Architecture cleanliness vs P83 8/10 | ⚠️ | `docs/tmp/p83_review_p78_p82.md:115`, `daemon/src/server.rs:431`, `runner/libs/rejit.py:764` | 8.5/10. P84 removed important stale surfaces, but branch_flip runner/micro residue and daemon profile protocol keep it below 9. |
| Any critical ❌? | ⚠️ | `runner/libs/rejit.py:816`, `micro/config/micro_pure_jit.yaml:746`, `tests/unittest/rejit_pass_correctness.c:278` | No clear three-platform smoke execution blocker found. There is one strict cleanup ❌: `branch_flip` active residues violate the P85 grep-clean requirement. |
| bpfopt-suite + daemon LOC | ✅ | `bpfopt/crates/bpfopt/src/main.rs:1303`, `daemon/src/commands.rs:2552` | Production Rust source excluding in-tree `*_tests.rs`/`pass_tests.rs`: 24,683 LOC. Source including in-tree test modules: 29,410 LOC. Source + CLI tests + manifests: 30,789 LOC. |
| Ready for three-platform smoke? | ⚠️ | `Makefile:103`, `Makefile:106`, `Makefile:118`, `Makefile:127`, `runner/libs/suite_commands.py:147` | Functionally close enough to run smoke if the goal is runtime validation, but not clean enough to call P84/P85 final cleanup complete until branch_flip residue and stale profile commands are removed or explicitly quarantined. |

## H. Final Sanity for Smoke Prep

| Check | Status | Evidence | Short finding |
| --- | --- | --- | --- |
| `main` HEAD is required commit | ✅ | `git rev-parse HEAD` = `c5b4e9058bc1e7b673d5e3eff6b4bc849084a44e` | Current branch is `main`, tracking `origin/main`. |
| Cargo workspace health | ✅ | `bpfopt/Cargo.toml:1`, `bpfopt/Cargo.toml:3`, `daemon/Cargo.toml:1`, `docs/tmp/p84_combined_review.md:48` | Cargo manifests are structurally consistent; P84 self-report says build/test/clippy passed. Not rerun by constraint. |
| Dockerfile/build graph not broken by P84 | ✅ | `runner/mk/build.mk:119`, `runner/mk/build.mk:125`, `runner/containers/runner-runtime.Dockerfile:483`, `runner/containers/runner-runtime.Dockerfile:510` | No P84 diff under `runner/containers`, `runner/mk`, or `Makefile`. Runtime image still copies daemon/CLI artifacts from image layers. |
| No host workspace bind mount in runtime command | ✅ | `runner/libs/suite_commands.py:139`, `runner/libs/suite_commands.py:147`, `runner/libs/suite_commands.py:149`, `runner/libs/suite_commands.py:150` | Runtime container mounts result dirs/tmp and system paths (`/sys`, `/sys/fs/bpf`, `/lib/modules`, `/boot`), not the whole host workspace. |
| Makefile smoke entries | ⚠️ | `Makefile:60`, `Makefile:103`, `Makefile:106`, `Makefile:115`, `Makefile:118`, `Makefile:124`, `Makefile:127`, `Makefile:133`, `Makefile:140` | `vm-corpus`, `vm-e2e`, `aws-x86-test`, `aws-arm64-test`, `aws-x86-benchmark`, `aws-arm64-benchmark`, generic `aws-corpus`, and generic `aws-e2e` exist. Literal aliases `aws-x86-corpus`, `aws-arm64-corpus`, `aws-x86-e2e`, `aws-arm64-e2e` do not exist; use `aws-*-benchmark AWS_*_BENCH_MODE=<corpus|e2e>` or `aws-corpus`/`aws-e2e` with `RUN_TARGET_ARCH`. |
| `benchmark_config.yaml` schema parses for corpus runner | ✅ | `corpus/config/benchmark_config.yaml:1`, `runner/libs/rejit.py:352`, `corpus/driver.py:597` | Default config provides 11 passes through `policy.default.passes`; corpus runner passes that list into daemon optimize. |

## 必修清单

1. ❌ Remove or quarantine all active `branch_flip` residues before declaring P84/P85 cleanup complete: `runner/libs/rejit.py:24`, `runner/libs/rejit.py:47`, `runner/libs/rejit.py:764`, `runner/libs/rejit.py:816`, `runner/libs/input_specs.yaml:214`, `runner/libs/input_generators.py:264`, `micro/config/micro_pure_jit.yaml:746`, `micro/programs/branch_flip_dense.bpf.c:9`, `tests/unittest/rejit_pass_correctness.c:278`, `tests/unittest/progs/test_branch_flip.bpf.c:17`.
2. ⚠️ Delete daemon `profile-start`/`profile-stop` protocol and `bpfprof` session plumbing if no replacement real PGO pass exists: `daemon/src/server.rs:431`, `daemon/src/server.rs:447`, `daemon/src/commands.rs:921`, `daemon/src/commands.rs:950`.
3. ⚠️ Make runner config schema fail-fast on stale `policy.rules[].disable` or document that unknown legacy keys are ignored intentionally: `runner/libs/rejit.py:352`.
4. ⚠️ Either add the literal AWS smoke aliases requested by the checklist or update smoke docs/scripts to use canonical current targets: `Makefile:118`, `Makefile:127`, `Makefile:133`, `Makefile:140`.

## 下一轮可删项

1. `bpfopt list-passes --json` stdout behavior can be tightened to require `--output` if the project wants zero JSON stdout, including metadata: `bpfopt/crates/bpfopt/src/main.rs:355`.
2. Daemon comments/descriptions should stop saying it directly optimizes/applies rewrites: `daemon/Cargo.toml:5`, `daemon/src/main.rs:4`.
3. `PassManager`/analysis registration ceremony can likely be simplified after smoke, but this is shared pass infrastructure and should not be cut in the smoke-prep window: `bpfopt/crates/bpfopt/src/pass.rs:893`.
4. `mock_maps.rs` could be replaced by explicit snapshot/provider tests later: `bpfopt/crates/bpfopt/src/mock_maps.rs:1`.
5. `#[allow(unused_imports)]` reexports in analysis module are a small cleanup target: `bpfopt/crates/bpfopt/src/analysis/mod.rs:13`.

## Final Verdict

P84 materially improved the v3 cleanup: pass count is now 11, PMU placeholders are gone, daemon optimize responses are smaller, map provider layering is simpler, `map_info` ownership is better, and `bpfget`/`bpfprof` no longer put JSON metadata/profile payloads on stdout.

Strict final review still finds one real ❌: `branch_flip` is not gone from the active codebase. It is deleted from optimizer Rust, but runner profile hooks, micro config/programs, and unittest assets still refer to it. That is not obviously a three-platform smoke execution blocker because default corpus config does not enable it, but it violates the exact P85 grep-clean requirement and keeps the architecture from being fully clean.

Smoke readiness: conditionally ready to run for runtime validation, but not clean enough to mark “final cleanup complete” until the required branch_flip/profile cleanup and AWS target-name ambiguity are resolved.

# BpfReJIT Repository Consistency Review

Date: 2026-03-28

Scope:
- Reviewed the current worktree for `daemon/`, `runner/`, `micro/`, `corpus/`, `e2e/`, and repo-owned tests.
- Excluded kernel code under `vendor/linux-framework/`.
- Did not modify source code. This report reflects the current checkout state, which already has user-side edits in the daemon tree.

Method:
- Scanned daemon Rust CLI/API and pass registry.
- Scanned runner Python/C++ interfaces and batch JSON flow.
- Compared `micro/`, `corpus/`, and `e2e/` driver contracts.
- Cross-checked Makefile target surfaces and parameter forwarding.
- Ran static dead-code / unused-import scans on repo-owned Python.
- Checked `benchmark_config.yaml`, `macro_corpus.yaml`, and generated-artifact hygiene.

## Executive Summary

No `CRITICAL` issue was found, but there are 3 `HIGH` findings that should be treated as release-blocking for consistency:

1. `benchmark_config.yaml` still names passes that do not exist in the current daemon pass registry.
2. The meaning of `enabled_passes=[]` is not preserved across daemon -> runner -> corpus batch paths.
3. `macro_corpus.yaml` currently references 8 object files that do not exist in `corpus/build/` and are not recorded in `corpus/build/build_report.json`.

The rest of the repo has a clear second tier of `MEDIUM` issues: E2E schema drift, terminology drift, duplicated pass/config parsing, an overgrown root `Makefile`, and stale default daemon paths in profiling utilities. There is also a smaller layer of `LOW` dead code and temp-artifact buildup.

## Findings

### 1. `HIGH` - `benchmark_config.yaml` points at passes that no longer exist in the daemon registry

What I found:
- `corpus/config/benchmark_config.yaml:13-17` defines a `security` pass group with:
  - `dangerous_helper_firewall`
  - `live_patch`
  - `speculation_barrier`
- The current daemon pass registry in `daemon/src/passes/mod.rs:52-118` only registers:
  - `map_inline`, `const_prop`, `dce`, `skb_load_bytes_spec`, `bounds_check_merge`, `wide_mem`, `bulk_memory`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `branch_flip`
- There are no corresponding registry entries for the 3 security passes above in the current tree.

Impact:
- Any profile or future config that selects the `security` group will drift from actual daemon behavior and can fail at runtime when passes are validated.
- The benchmark config is no longer a trustworthy source of truth for available passes.

Fix:
- Either restore those passes and re-register them, or remove them from `benchmark_config.yaml`.
- Add a repo-owned test that loads `benchmark_config.yaml` and asserts every configured pass name resolves in `daemon/src/passes/mod.rs`.

### 2. `HIGH` - Explicit zero-pass requests are preserved in one path and silently dropped in another

What I found:
- `runner/libs/rejit.py:493-509` always serializes `enabled_passes`, including `[]`.
- `tests/python/test_rejit.py:50-127` explicitly codifies that:
  - `BPFREJIT_BENCH_PASSES=""` means zero passes.
  - socket apply must send `"enabled_passes": []`.
- But the corpus batch path drops the same intent:
  - `corpus/modes.py:744-803` only writes `job["enabled_passes"]` when the list is truthy.
  - `runner/src/kernel_runner.cpp:1658-1675` only serializes `"enabled_passes"` when the vector is non-empty.

Impact:
- `None` and `[]` are distinct in `runner.libs.rejit`, but become indistinguishable in corpus/batch/C++ socket flow.
- The same conceptual request can mean:
  - "use daemon defaults" in one path
  - "run zero passes" in another
- This is a real dataflow inconsistency, not just naming drift.

Fix:
- Make pass selection tri-state everywhere:
  - `None` = default daemon behavior
  - `[]` = explicit zero passes
  - non-empty list = explicit pass set
- Update the batch JSON schema and C++ serializer to preserve empty arrays.
- Add end-to-end tests for zero-pass behavior in corpus and micro batch mode.

### 3. `HIGH` - `macro_corpus.yaml` references stale build outputs

What I found:
- `corpus/config/macro_corpus.yaml` currently names at least these missing object files:
  - `4354` `corpus/build/bpftrace/exec_trace.bpf.o`
  - `4374` `corpus/build/bpftrace/open_latency.bpf.o`
  - `4396` `corpus/build/bpftrace/scheduler_latency.bpf.o`
  - `4418` `corpus/build/bpftrace/tcp_connect.bpf.o`
  - `4439` `corpus/build/bpftrace/vfs_read_count.bpf.o`
  - `14823` `corpus/build/tracee/lsm_check.bpf.o`
  - `17929` `corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_fail3.bpf.o`
  - `18019` `corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.bpf.o`
- A scripted existence check found 8 missing objects out of 477 manifest entries.
- Those same 8 paths are also absent from `corpus/build/build_report.json`.
- Directory contents confirm the drift:
  - `corpus/build/bpftrace/` currently only contains `stdlib/`
  - `corpus/build/tracee/` contains `tracee.bpf.o` plus support dirs, but not `lsm_check.bpf.o`
  - `corpus/build/xdp-tutorial/experiment01-tailgrow/` contains `fail1`, `fail2`, `kern`, `kern2`, `kern4`, but not `fail3` or `kern3`

Impact:
- The corpus manifest overstates what the repo can actually build/run.
- This undermines corpus completeness claims and makes target selection/debugging harder.

Fix:
- Remove or update the stale entries in `macro_corpus.yaml`.
- Add a manifest validation step that checks every `source` either exists or is present in the build report with an explicit non-buildable reason.

### 4. `MEDIUM` - E2E result JSON is not a single schema

What I found:
- `tracee`, `tetragon`, `scx`, and `katran` expose top-level `baseline`, `post_rejit`, and `comparison` payloads:
  - `e2e/cases/tracee/case.py:937-959`
  - `e2e/cases/scx/case.py:720-743`
  - `e2e/cases/katran/case.py:2357-2363`
- `bcc` and `bpftrace` instead emit `records[]`, and each record uses `baseline` plus `rejit`:
  - `e2e/cases/bcc/case.py:808-816`, `841-858`
  - `e2e/cases/bpftrace/case.py:673-682`, `713-730`
- Per-case comparison keys also differ:
  - `tetragon` program rows use `stock_avg_ns`, `rejit_avg_ns`, `speedup`
  - `tracee` comparison uses `baseline_avg_ns_per_run`, `post_avg_ns_per_run`
  - `katran` uses `bpf_speedup_ratio`

Impact:
- Cross-case tooling has no stable contract.
- Any downstream comparison/reporting layer must special-case each E2E benchmark.

Fix:
- Define a shared E2E schema with:
  - one top-level phase model
  - one comparison field vocabulary
  - optional case-specific extension sections
- Keep adapters only at the presentation layer, not in the storage schema.

### 5. `MEDIUM` - The repo uses multiple names for the same concepts

What I found:
- Daemon CLI uses `Rewrite` and `Apply`:
  - `daemon/src/main.rs:49-64`
- Daemon socket protocol uses `optimize` and `optimize-all`:
  - `daemon/src/server.rs:208-220`
- Python helper is named `apply_daemon_rejit`:
  - `runner/libs/rejit.py:572-655`
- Runner C++ still emits `sample.phase = "recompile"`:
  - `runner/src/kernel_runner.cpp:3096-3100`
  - `runner/src/kernel_runner.cpp:4305-4309`
- Higher-level drivers use `baseline`, `post_rejit`, `rejit`, and sometimes `stock`.

Impact:
- The user-facing concept is "ReJIT", but the code alternates among `rewrite`, `apply`, `optimize`, `recompile`, `stock`, `baseline`, and `post_rejit`.
- This makes CLI design, logs, JSON fields, and docs harder to reason about.

Fix:
- Pick one canonical vocabulary and use aliases only at compatibility edges.
- Recommended canonical set:
  - action: `apply`
  - result state: `rejit`
  - control phase: `baseline`
  - post-change phase: `post_rejit`

### 6. `MEDIUM` - Benchmark pass/config parsing is duplicated in two different Python modules

What I found:
- `runner/libs/rejit.py:31-79` re-implements benchmark-config pass resolution.
- `corpus/modes.py:216-241` carries nearly the same logic again.
- Daemon lifecycle helpers are also duplicated:
  - `corpus/modes.py:599-612`
  - `runner/libs/rejit.py:441-490`

Impact:
- Config interpretation can drift without immediately failing tests.
- The same policy behavior is maintained in multiple places instead of one shared module.

Fix:
- Move pass-selection resolution and daemon server lifecycle into one shared helper module.
- Make `micro`, `corpus`, and `e2e` all import that one implementation.

### 7. `MEDIUM` - The root `Makefile` is not thin and duplicates `runner/Makefile` surface area

What I found:
- The repo instructions say the root `Makefile` should stay thin, but the current root file contains 57 targets and substantial ARM64/AWS/kernel orchestration.
- `Makefile:133-142` declares a very large `.PHONY` surface.
- `Makefile:163-203` duplicates many `corpus-build-*` forwarding targets.
- `Makefile:353-363` forwards `vm-corpus` and `vm-e2e` into `runner/Makefile`.
- `runner/Makefile` already carries the actual VM/test orchestration (`runner/Makefile:95-102`, `299-348`).

Impact:
- There are two public orchestration surfaces for the same workflows.
- Parameter forwarding is harder to audit, and changes must be synchronized twice.

Fix:
- Keep the root `Makefile` as a very small front door.
- Move directory-specific VM/build logic fully into `runner/Makefile` or dedicated per-directory Makefiles.
- Reduce root targets to thin delegators only.

### 8. `MEDIUM` - Profiling utilities still default to an outdated daemon path

What I found:
- Most of the repo consistently uses `daemon/target/release/bpfrejit-daemon`:
  - `Makefile:63`
  - `runner/Makefile:22`
  - `corpus/modes.py:70`
  - `e2e/run.py:145`
- But `runner/libs/profiler.py:16` still uses:
  - `daemon/build/bpfrejit-daemon`
- `runner/scripts/bpf_profiler.py:13-39` exposes that stale default directly to users.

Impact:
- Profiling scripts can point at a binary location that the rest of the repo no longer builds by default.
- This is a concrete config drift, not just naming style.

Fix:
- Change profiling defaults to `daemon/target/release/bpfrejit-daemon`.
- Add a smoke test that asserts all repo-owned daemon path defaults agree.

### 9. `LOW` - Old corpus v1 paths and dead helpers are still in tree

What I found:
- `corpus/modes.py:1143-1200` defines `run_targets_locally_batch()` but there is no remaining call site.
- `corpus/modes.py:2565-2672` defines old `build_summary()` / `build_markdown()`.
- Current entrypoints only use the v2 object/program record path:
  - `corpus/modes.py:2029-2116` `build_summary_v2`
  - `corpus/modes.py:2119-2160` `build_markdown_v2`
  - `corpus/modes.py:2893`, `2906`, `2963`, `2975` route through v2
- `runner/libs/run_artifacts.py:340-375` defines `extract_daemon_debug_details()` with no remaining caller.

Impact:
- These are not the biggest correctness risks, but they materially increase maintenance cost and code reading time.

Fix:
- Remove the dead v1 corpus path after confirming no external user depends on it.
- Delete dead helpers rather than keeping parallel implementations alive indefinitely.

### 10. `LOW` - There are small but real unused-import and compatibility leftovers in repo-owned Python

What I found from a repo-owned Python AST scan:
- `runner/libs/corpus.py:12` imports `build_runner_command` but does not use it.
- `runner/libs/results.py:8-18` imports a large block of statistics helpers that are unused in the current file.
- `e2e/cases/bcc/case.py:28-38`, `58-62` import `which` and `git_sha` but do not use them.
- `e2e/cases/tetragon/case.py:48-58` imports `git_sha` and `relpath` but does not use them.
- `runner/scripts/collect_e2e_profile.py:47-80` imports `DEFAULT_KATRAN_SCANNER` and `KATRAN_ROOT_DIR` but does not use them.

Impact:
- Mostly low-level hygiene debt, but it is a reliable signal that compatibility cleanup is lagging behind refactors.

Fix:
- Run a repo-owned unused-import check in CI for `runner/libs`, `corpus`, `micro`, `e2e`, `runner/scripts`, and `tests/python`.

### 11. `LOW` - `docs/tmp/` accumulation is significant and currently unmanaged

What I found:
- `docs/tmp/` currently contains 47 top-level `runner-batch-*` directories.
- Largest sampled directories:
  - `docs/tmp/runner-batch-r_twx6ky` about `311M`
  - `docs/tmp/runner-batch-y6pre4ep` about `198M`
  - dated review/result dirs such as `docs/tmp/20260326` about `147M` and `docs/tmp/20260327` about `134M`
- `.gitignore:121-140` correctly ignores most nested temp payloads, but there is no pruning policy.

Impact:
- This is disk and operator hygiene debt rather than correctness debt, but it will keep growing.

Fix:
- Add a cleanup target or retention script for `docs/tmp/runner-batch-*` and old dated scratch directories.

## Additional Notes

- `runner/libs/results.py:134-153` still carries `stock` -> `rejit` collapsing logic, but current C++ runner output only emits `phase = "recompile"` (`runner/src/kernel_runner.cpp:3096-3100`, `4305-4309`). That looks like stale compatibility code and supports the broader terminology-drift finding.
- `daemon/src/pass.rs:558-579` still exposes `PipelineProfile` / `MapInlineOnly`, while `daemon/src/passes/mod.rs:190-198` shows it is effectively an internal/testing-only concept now. This is low-level complexity debt, not a top-tier defect.

## Prioritized Action List

1. Reconcile daemon pass availability with `benchmark_config.yaml`, then add a test that every configured pass resolves in the daemon registry.
2. Make pass selection tri-state end-to-end (`default` vs `[]` vs explicit list) and add corpus/micro/E2E tests for the zero-pass case.
3. Remove or replace the 8 stale `macro_corpus.yaml` object entries and add automated manifest-vs-build-report validation.
4. Define one stable E2E result schema and migrate `bcc`/`bpftrace` onto the same phase vocabulary as the other cases.
5. Standardize naming around `apply`, `baseline`, `post_rejit`, and `rejit`; keep compatibility aliases only at leaf interfaces.
6. Consolidate benchmark pass parsing and daemon server lifecycle helpers into one shared Python module.
7. Slim the root `Makefile` so it becomes a thin delegator instead of a second orchestration layer.
8. Fix stale daemon default paths in profiling utilities and add a path-consistency test.
9. Delete dead corpus v1 helpers and other unused repo-owned helpers/imports.
10. Add a cleanup/retention rule for `docs/tmp/runner-batch-*` and other large scratch directories.

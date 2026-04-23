# Broader Deletion Review 2026-04-22

Scope: read-only review for Round 4 deletion candidates that are not the current A/B workstreams.

Excluded on purpose:
- A overlap: core daemon/runner schema cleanup, metadata cleanup, EINVAL handling, suite cleanup.
- B overlap: tracee parser, e2e override cleanup, tetragon duplicate setup, katran selection, `agent.find_bpf`, Makefile dead vars.
- Already-explicit prior items I did not re-report: `corpus_measurement_mode`, `program_fds`, `OptimizeOneResult` vs `ServeOptimizeResponse`, `target_prog_ids` vs `apply_prog_ids`.

Estimated additional net deletion available from the findings below: about **247 lines**.

## Findings

### 1. `CONSIDER` — Add one daemon helper for repeated unchanged/skip `PassResult` scaffolding
- Files: `daemon/src/passes/rotate.rs:31`, `daemon/src/passes/cond_select.rs:130`, `daemon/src/passes/endian.rs:232`, `daemon/src/passes/extract.rs:115`, `daemon/src/passes/bounds_check_merge.rs:97`, `daemon/src/passes/branch_flip.rs:95`, `daemon/src/passes/skb_load_bytes.rs:71`, plus similar sites in `bulk_memory.rs`, `const_prop.rs`, `dce.rs`, `map_inline.rs`, `wide_mem.rs`.
- Code block size estimate: about 28 repeated early-return blocks, about 280 gross lines, about **80 net deletable** after introducing one shared constructor/helper.
- Why it is dead/redundant:
  - `PassResult` already has one canonical shape in `daemon/src/pass.rs` for “unchanged, skipped, zero applied”.
  - Current passes open-code the same struct literal over and over: `changed: false`, `sites_applied: 0`, `diagnostics: vec![]`, one `SkipReason`, `..Default::default()`.
  - The repeated pattern appears in 12 pass files; the only real variable is the skip reason text, and in a few sites the diagnostics vector.
- Grep evidence:
  - `changed: false` appears in 12 pass files.
  - Representative examples: `rotate.rs:31-41`, `rotate.rs:45-55`, `cond_select.rs:130-140`, `cond_select.rs:174-184`.
- Deletion path:
  - Add one helper such as `PassResult::skipped(pass_name, reason)` and one variant with diagnostics.
  - Replace the repeated struct literals at each early-return site.

### 2. `DELETE_ME` — `corpus/driver.py::_run_app()` is now completely dead
- File: `corpus/driver.py:1066-1126`
- Code block size estimate: about **61 net deletable lines**.
- Why it is dead:
  - Whole-repo search shows only the definition; no caller remains.
  - The active corpus path is `run_suite()` and the per-session flow below it, not `_run_app()`.
- Grep evidence:
  - `rg -n "_run_app\\(" . -g '!docs/tmp/**' ...` returns only `corpus/driver.py:1066`.
- Deletion path:
  - Delete `_run_app()`.
  - No caller updates needed.

### 3. `CONSIDER` — Corpus apply metadata is write-only baggage now
- Files: `runner/libs/case_common.py:349-353`, `corpus/driver.py:926-943`
- Fields: `selection_source`, `scan_enabled_passes`, `benchmark_profile`
- Code block size estimate: about **16 net deletable lines**.
- Why it is dead:
  - These fields are produced in `_merge_group_rejit_results()` and then copied once in `_slice_rejit_result()`.
  - There are no downstream readers outside that producer/echo path.
- Grep evidence:
  - Whole-repo search outside `docs/tmp/`, results, build dirs, and vendored trees finds:
    - `selection_source` only in `case_common.py` producer and `corpus/driver.py` slicer.
    - `scan_enabled_passes` only in the same producer/slicer plus the actual scan call.
    - `benchmark_profile` only in `case_common.py` producer and `corpus/driver.py` slicer.
- Deletion path:
  - Keep the actual scan/apply decision logic.
  - Drop these three fields from the result payload and the slicer.

### 4. `CONSIDER` — Several runner result/artifact fields are pure write-through with no readers
- Files: `runner/libs/rejit.py:616-624`, `runner/libs/case_common.py:492-493`, `corpus/driver.py:784-786`, `corpus/driver.py:879-881`, `corpus/driver.py:1037`, `e2e/cases/bcc/case.py:173-175`, `e2e/cases/katran/case.py:173`
- Fields: `kernel_prog_name`, `command_used`, `runner_artifacts`
- Code block size estimate: about **18 net deletable lines**.
- Why it is dead:
  - `kernel_prog_name` is populated in runner apply results but is never read anywhere.
  - `command_used` and `runner_artifacts` are copied into payloads, but no corpus/e2e/reporting logic consumes them.
- Grep evidence:
  - Whole-repo search finds `kernel_prog_name` only at `runner/libs/rejit.py:622`.
  - `command_used` and `runner_artifacts` appear only in app runner state capture and payload assembly paths, with no decision/report reader.
- Deletion path:
  - Remove these fields from runner/app payload assembly.
  - Keep underlying runner state if local debugging still needs it, but stop serializing it into result JSON.

### 5. `CONSIDER` — `get_app_runner()` still carries unused alias and leaf-name fallback logic
- File: `runner/libs/app_runners/__init__.py:9-18`, `runner/libs/app_runners/__init__.py:21-39`, `runner/libs/app_runners/__init__.py:43-51`
- Code block size estimate: about **17 net deletable lines**.
- Why it is redundant:
  - The only shared app-suite manifest in-tree is `corpus/config/macro_apps.yaml`, and it already uses explicit `tool`, `script`, and `scheduler` keys.
  - No in-repo app-suite YAML uses `tool_name`, `script_name`, or nested `args`.
  - No current shared-app caller relies on deriving the runner identity from the app-name leaf.
- Grep evidence:
  - `corpus/config/macro_apps.yaml` explicitly sets `tool`/`script`/`scheduler` for all relevant entries.
  - Whole-repo search outside temp docs finds no app-suite YAML entry with `args:` and no manifest key usage for `tool_name:` or `script_name:`.
- Deletion path:
  - Require the current manifest shape explicitly.
  - Delete `_leaf_name()`, `_pop_string()`, and the alias/fallback branches in `_adapt_bcc()`, `_adapt_bpftrace()`, `_adapt_scx()`.

### 6. `CONSIDER` — `load_app_suite_from_yaml()` still supports an unused second manifest shape
- File: `runner/libs/app_suite_schema.py:83-94`, `runner/libs/app_suite_schema.py:110-115`, `runner/libs/app_suite_schema.py:157-158`
- Code block size estimate: about **14 net deletable lines**.
- Why it is redundant:
  - `_app_args()` still merges a nested `args:` mapping with top-level app keys, but no in-repo suite manifest uses `args:`.
  - `max_apps` is accepted by the loader, but no call site passes it.
- Grep evidence:
  - Whole-repo search outside temp docs finds no app-suite YAML with `args:`.
  - `load_app_suite_from_yaml(` has 4 call sites and none pass `max_apps=`.
- Deletion path:
  - Make the app-suite loader accept only the current flat app shape.
  - Delete `max_apps`.

### 7. `DELETE_ME` — Tetragon case still carries dead wrapper functions around shared workload helpers
- File: `e2e/cases/tetragon/case.py:126-146`
- Code block size estimate: about **17 net deletable lines**.
- Why it is dead:
  - `run_workload()` is only a thin wrapper over `run_workload_with_options()`.
  - `run_workload_with_options()` is not used anywhere else.
  - The local `run_exec_storm_in_cgroup()` wrapper only exists to forward to the shared runner helper and is only called from the dead wrapper path.
  - The active measurement path uses `runner.run_workload_spec(...)`, not these case-local wrappers.
- Grep evidence:
  - Whole-repo search shows `run_workload_with_options(` only in this file.
  - The local `run_workload(` wrapper is not called outside its own definition site.
- Deletion path:
  - Delete all three wrappers and keep the shared runner workload entrypoint.

### 8. `DELETE_ME` — `CaseLifecycleState.scan_kwargs` is a dead field
- File: `runner/libs/case_common.py:103-109`, `runner/libs/case_common.py:431-435`
- Code block size estimate: about **6 net deletable lines**.
- Why it is dead:
  - The field exists on the lifecycle dataclass and is read once in `run_case_lifecycle()`.
  - There is no writer anywhere in the current repo.
- Grep evidence:
  - Whole-repo search outside temp docs finds `scan_kwargs=` nowhere.
  - The only live uses are the dataclass field definition and the one read before `scan_programs(...)`.
- Deletion path:
  - Delete the field.
  - Pass `enabled_passes` directly into `scan_programs(...)`.

### 9. `DELETE_ME` — `LifecycleRunResult.setup_state` and `.metadata` are both unread
- File: `runner/libs/case_common.py:129-139`, `runner/libs/case_common.py:385-388`, `runner/libs/case_common.py:468-472`
- Code block size estimate: about **10 net deletable lines**.
- Why they are dead:
  - `setup_state` is written into `LifecycleRunResult` but never read.
  - `LifecycleRunResult.metadata` is also written at return sites, but no caller reads `lifecycle_result.metadata`.
  - Kinsn metadata still survives elsewhere through `PreparedDaemonSession.metadata`, so removing this field does not remove the actual data source.
- Grep evidence:
  - Whole-repo search finds `.setup_state` nowhere.
  - Whole-repo search finds no `lifecycle_result.metadata` reader.
- Deletion path:
  - Drop both fields from the dataclass and from the return builders.

### 10. `DELETE_ME` — `prepare_daemon_session(..., daemon_binary=...)` override is redundant
- Files: `runner/libs/case_common.py:142-154`, `runner/libs/rejit.py:816-837`, `e2e/driver.py:608`, `e2e/driver.py:635`, `corpus/driver.py:1140-1143`
- Code block size estimate: about **4 net deletable lines**.
- Why it is redundant:
  - `DaemonSession` already stores `daemon_binary`.
  - Every live call site passes the same value back into `prepare_daemon_session(...)`.
- Grep evidence:
  - All 3 non-definition call sites pass `daemon_binary=...`.
  - `DaemonSession.daemon_binary` is already present in the session object.
- Deletion path:
  - Remove the optional override parameter and use `daemon_session.daemon_binary` directly.

## Top 10 ROI

1. Daemon pass skip-result helper: about 80 net lines, low semantic risk, repeated in 12 files.
2. Delete dead `corpus/driver.py::_run_app()`: about 61 net lines, zero callers.
3. Remove write-only result/artifact baggage (`kernel_prog_name`, `command_used`, `runner_artifacts`): about 18 net lines.
4. Remove `get_app_runner()` alias/leaf fallback logic: about 17 net lines.
5. Delete dead tetragon workload wrappers: about 17 net lines.
6. Remove write-only corpus apply metadata (`selection_source`, `scan_enabled_passes`, `benchmark_profile`): about 16 net lines.
7. Remove unused app-suite legacy shape support (`args:` merge): about 14 net lines.
8. Remove unread `LifecycleRunResult.setup_state` and `.metadata`: about 10 net lines.
9. Remove dead `CaseLifecycleState.scan_kwargs`: about 6 net lines.
10. Remove redundant `prepare_daemon_session(..., daemon_binary=...)` override and unused `max_apps`: about 8 net lines combined.

## Notes

- The list above intentionally avoids the A/B streams and the already-documented `corpus_measurement_mode`, `program_fds`, and `OptimizeOneResult`/`ServeOptimizeResponse` cleanup.
- If Round 4 wants the safest order, start with: `_run_app()`, tetragon wrappers, lifecycle dead fields, `max_apps`, then the app-suite adapter cleanup, then the daemon pass helper.

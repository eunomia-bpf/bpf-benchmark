# Meta Review Recent Commits 2026-04-24

## Scope

- Primary range requested by command: `git log --oneline HEAD~25..HEAD`
- Supplementary named commits outside that exact range but explicitly listed by user:
  - `e252866d [e2e/tracee] delete require_program_activity activity gate`
  - `7c81db17 [e2e/tetragon] ship upstream tracing policies`
- I did **not** trust prior reports as conclusions. I read them for context, then re-ran `git show` / `git diff` / `git grep` / `rg`.
- Current worktree is dirty in `Makefile`, `e2e/driver.py`, and `runner/libs/app_runners/tracee.py`, plus untracked `e2e/results/*`. For M4 live-code checks I used `git grep HEAD -- ...` against committed blobs to avoid false positives from concurrent local edits.

## M1: Lazy Rename Check

- Command:
  - `git log -p HEAD~25..HEAD | grep -E '^[+-]def |^[+-]class |^[+-]fn |^[+-]pub fn |^[+-]impl '`
- Hits:
  - `_remote_result_dir_command(remote_workspace: str)` -> `_remote_result_dir_command(remote_workspace: str, suite_name: str)`
  - `collect_global_data_maps(...) -> Vec<...>` -> `collect_global_data_maps(...) -> Result<Vec<...>>`
  - `runtime_container_result_dirs(...)` deleted; `_container_result_dir(...)` added; `runtime_container_result_dirs(..., suite_name, die=...)` / `runtime_container_host_dirs(..., suite_name, die=...)` added
  - `finalize_process_output(process, collector=None)` -> `finalize_process_output(process, collector)`
  - `run_suite(args)` -> `run_suite(args, suite)`
  - `load_app_suite_from_yaml(...) -> tuple[...]` -> `load_app_suite_from_yaml(...) -> AppSuite`
  - `resolve_primary_output_json(args, spec)` -> `resolve_primary_output_json(args)`
  - deleted-only helpers: `smoke_output_path`, `summarize_program_activity`, `append_preflight_markdown`, `application_overhead_pct`, `attach_control_phase_metrics`, `merge_csv_and_repeated`
- Supplementary commands:
  - `git show e252866d -- | grep -E '^[+-]def |^[+-]class |^[+-]fn |^[+-]pub fn |^[+-]impl '`
  - `git show 7c81db17 -- | grep -E '^[+-]def |^[+-]class |^[+-]fn |^[+-]pub fn |^[+-]impl '`
- Supplementary hits:
  - `e252866d`: `verify_phase_measurement(record, *, require_tracee_activity)` -> `verify_phase_measurement(record)`
  - `7c81db17`: `0 hits`
- Judgment:
  - No true lazy rename found.
  - The symbol churn is signature tightening, helper deletion, or small helper extraction, not `A -> B` same-behavior renaming.
  - Only real new code-path symbols are `resolve_tetragon_policy_dir()` in `553e38b8` and `_container_result_dir()` in `ccd8debe`; neither hides a deleted predecessor.

## M2: Silent Regression Check

- Commands:
  - `git diff --name-status HEAD~26..HEAD -- 'tests/**' 'daemon/tests/**' 'daemon/src/**/*test*'`
  - `git diff HEAD~26..HEAD -- runner/suites/test.py daemon/src/elf_parser.rs daemon/src/profiler.rs | rg '^[+-]\\s*#\\[test\\]|^[+-]fn test_|^[+-]\\s*assert|^[+-]\\s*def test_'`
  - `git diff --name-status HEAD~26..HEAD | rg '(^[AMDR]\\t.*(tests?/|_test\\.|test_))'`
- Hits:
  - First command: `0 hits`
  - Second command: `0 hits`
  - Third command: `0 hits`
- Judgment:
  - No in-range test deletion or assert weakening found under `tests/**`, `daemon/tests/**`, or `daemon/src/**/*test*`.
  - The review range changed behavior without adding/updating tests, but I did not find a commit that relaxed an existing test into permissive behavior.
  - The only concrete regression I found is a CLI surface mismatch in `ccd8debe`; it is a real behavior break, but not a test-edit regression.

## M3: New Shim / Fallback Check

- Code-only pattern scans:
  - `git log -p HEAD~25..HEAD -- . ':(exclude)docs/**' | rg -n '^\\+.*(fallback|legacy|compat|deprecated|backward|shim|= None,|or default)'`
  - `git log -p HEAD~25..HEAD -- . ':(exclude)docs/**' | rg -n '^\\+.*Optional\\[|^\\+.*\\| None'`
  - `git log -p HEAD~25..HEAD -- . ':(exclude)docs/**' | rg -n '^\\+.*except.*:\\s*$|^\\+.*rescue|^\\+.*pass\\s*$|^\\+.*unwrap_or_default\\(|^\\+.*\\.ok\\(\\)|^\\+.*let _ = '`
- Hits:
  - All three commands returned `exit 1 / 0 hits`
- Targeted shim check:
  - `git grep -n '"--e2e-smoke"' HEAD -- runner/suites/e2e.py`
  - Hit: `HEAD:runner/suites/e2e.py:38`
  - `git grep -n '"--smoke"' HEAD -- e2e/driver.py`
  - Hit: `0 hits`
- Judgment:
  - No new `Optional[...]`, `except/pass`, or classic fallback idioms were added in code.
  - One real new shim/mode-switch was introduced anyway: `ccd8debe` added `--e2e-smoke` in `runner/suites/e2e.py`, forwarding `--smoke` into a committed `e2e/driver.py` that no longer parses that flag.

## M4: Verify Each Delete/Remove Commit Really Deleted What It Claimed

- `e252866d`
  - Command: `git grep -n -E 'require_program_activity|require_tracee_activity' HEAD -- e2e/cases/tracee/case.py e2e/cases/tracee/config.yaml runner/suites/e2e.py e2e/driver.py`
  - Hits: `0 hits`
  - Judgment: true delete.

- `34b0597a`
  - Command: `git grep -n -E 'vm-micro-smoke|smoke_output_path' HEAD -- Makefile runner/suites/e2e.py e2e/driver.py micro/driver.py runner/libs/__init__.py runner/libs/run_artifacts.py`
  - Hits: `0 hits`
  - Follow-up command: `git grep -n '\"--e2e-smoke\"' HEAD -- runner/suites/e2e.py`
  - Hits: `HEAD:runner/suites/e2e.py:38`
  - Judgment: the specific deleted entrypoints/helpers are gone, but the “delete smoke suite entrypoints” cleanup is **not durable cumulatively** because `ccd8debe` reintroduced a new smoke entrypoint later.

- `24294456` / `270689c4` / `ca4c88ef`
  - Command: `git grep -n -E 'summarize_program_activity|append_preflight_markdown|application_overhead_pct|attach_control_phase_metrics|preflight_duration_s|program_activity' HEAD -- e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/scx/case.py e2e/cases/tracee/config.yaml e2e/cases/tetragon/config.yaml`
  - Hits: `0 hits`
  - Judgment: true delete for the named activity/preflight helpers and payload fields.

- `f86d8b97`
  - Command: `git grep -n '\"suite_summary\"' HEAD -- corpus/driver.py runner/libs/app_suite_schema.py`
  - Hits: `0 hits`
  - Judgment: true delete.

- `0f0eadeb`
  - Command: `git grep -n -F '_resolve_script(' HEAD -- runner/libs/app_runners/bpftrace.py runner e2e/cases`
  - Hits: `0 hits`
  - Command: `rg -n --glob '!runner/build-*/toolchain/**' 'finalize_process_output\\(' runner/libs/app_runners/bpftrace.py runner e2e micro corpus tests daemon`
  - Hits: definition + one callsite only; callsite passes `self.collector`
  - Judgment: true delete of the fallback path; no stale no-collector caller remains.

- `be74a91b`
  - Command: `git grep -n 'tool_name=' HEAD -- e2e/cases/bcc/case.py runner/libs/app_runners/bcc.py runner e2e/cases`
  - Hits: `0 hits`
  - Command: `rg -n --glob '!runner/build-*/toolchain/**' 'BCCRunner\\(' runner e2e micro corpus tests daemon`
  - Hits: one real caller at `e2e/cases/bcc/case.py:126`
  - Judgment: true delete of dead constructor surfaces.

- `2d555d5f`
  - Command: `git grep -n '\"scheduler_output\"' HEAD -- e2e/cases/scx/case.py runner/libs/app_runners/scx.py runner/libs/case_common.py`
  - Hits: `0 hits`
  - Judgment: true delete.

- `d3988906`
  - Command: `git grep -n -E '\"suite_summary\"|\"scheduler_output\"|\"daemon_socket\"|\"tetragon_launch_command\"|\"agent_logs\"' HEAD -- corpus/driver.py e2e/cases/katran/case.py e2e/cases/scx/case.py e2e/cases/tetragon/case.py runner/libs/case_common.py`
  - Hits: `0 hits`
  - Judgment: true delete for the removed source-tree payload keys.

- `68d837a9`
  - Command: `git grep -n '\\-j\", \"-p\"' HEAD -- runner/libs/agent.py runner/libs/app_runners/katran.py runner/libs/app_runners e2e/cases micro corpus/driver.py`
  - Hits: `0 hits`
  - Judgment: true delete of machine-parsed pretty-json usage.

- `ccd8debe`
  - Commands:
    - `git grep -n -E 'object_basename|benchmark-default|merge_csv_and_repeated|collector=None' HEAD -- runner e2e/cases micro corpus/driver.py daemon/src tests/unittest`
    - `git grep -n -E '\"--native-repo\"|\"--scx-package\"' HEAD -- Makefile runner e2e/cases micro corpus/driver.py daemon/src tests/unittest`
  - Hits:
    - first command: only unrelated `prog_type_name` producer code outside the deleted Python consumers; no deleted Python alias/fallback readers remain
    - second command: `0 hits`
  - Judgment: true delete for the intended Python compat readers and singular CLI shims, **but** the same commit also introduces a new shim (`--e2e-smoke`), so the cleanup is not purely subtractive.

- `7862b308`
  - Command: `git grep -n 'getattr(program, \"prog_type_name\"\\|program.get(\"prog_type_name\")\\|record.get(\"prog_type_name\")' HEAD -- corpus/driver.py runner/libs/case_common.py runner/libs/rejit.py e2e/cases runner/libs/app_runners`
  - Hits: `0 hits`
  - Judgment: true delete of the final **source-tree consumer** of `prog_type_name`.

## M5: New Code Suspicion / Net-Positive Commits

- Primary code-only structural diff:
  - `git diff --stat HEAD~25..HEAD -- . ':(exclude)docs/**'`
  - Result: `34 files changed, 194 insertions(+), 823 deletions(-)`
- Per-commit shortstat scan:
  - `git show --shortstat` over the range shows only two net-positive code commits in the primary window:
    - `553e38b8`: `+15/-1`
    - `f8bd2575`: `+19/-6`
- Supplementary named commit outside the primary window:
  - `7c81db17`: `19 files changed, 767 insertions(+)`
- Judgment:
  - The batch is deletion-heavy overall.
  - The only large new feature surface is the Tetragon upstream policy pack (`7c81db17` + `553e38b8`); it is explicit and justified, not a stealth shim.
  - `f8bd2575` is net-positive because it replaces silent fallback with loud error plumbing; that is aligned with the stated rules.

## M6: Round 8 Principle Consistency

- Code-only pattern scans:
  - `git log -p HEAD~25..HEAD -- . ':(exclude)docs/**' | rg -n '^\\+.*(require_.*activity|activity_gate|expected_programs|min_programs|max_programs|whitelist|allowlist|allowed_|mode == |kind == |skip|skipped)'`
  - Hits: `0 hits`
- HEAD source checks:
  - `git grep -n '\"--e2e-smoke\"' HEAD -- runner/suites/e2e.py` -> `1 hit`
  - `git grep -n 'args\\.smoke\\|smoke_duration_s' HEAD -- e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/tracee/config.yaml e2e/cases/tetragon/config.yaml` -> multiple hits
- Judgment:
  - No new allowlist/filter or silent-skip pattern landed in code.
  - One new mode switch **did** land: `--e2e-smoke`.
  - Tracee/Tetragon smoke-mode branches/config are still present in HEAD source, so the range is not fully aligned with “no mode switch / no gate residue”.

## M7: Cross-Commit Cumulative Behavior Diff

- Command:
  - `git diff --stat HEAD~25..HEAD`
- Result:
  - deletion-heavy across e2e/corpus/runner code
  - docs-heavy on the side
- Cumulative behavior judgment:
  - The main cumulative inconsistency is the smoke path:
    1. `34b0597a` removed `--e2e-smoke` from `runner/suites/e2e.py`
    2. `4cd2c4c9` removed `--smoke` from `e2e/driver.py`
    3. `ccd8debe` re-added `--e2e-smoke` in `runner/suites/e2e.py`
    4. HEAD still contains `args.smoke` / `smoke_*` logic in Tracee/Tetragon source
  - Net effect: broken wrapper surface plus dead mode-specific residue.

## Findings

### 🔴 BLOCKER

- `ccd8debe` reintroduced a broken compat shim at `HEAD:runner/suites/e2e.py:38-40,72-75`.
  - Evidence:
    - `git show HEAD:runner/suites/e2e.py | nl -ba | sed -n '31,77p'`
    - `git show HEAD:e2e/driver.py | nl -ba | sed -n '156,167p'`
  - Concrete mismatch:
    - `runner/suites/e2e.py` adds `--e2e-smoke` and forwards `--smoke`
    - committed `e2e/driver.py` no longer parses `--smoke`
  - Why this matters:
    - This is a real behavior break for the newly introduced wrapper flag.
    - It is also a textbook “new shim / new mode switch” after `34b0597a` deleted smoke suite entrypoints.

### 🟡 SHOULD

- `4cd2c4c9` made the shared driver stop accepting smoke mode, but HEAD still retains smoke-only Tracee/Tetragon branches and config.
  - Paths:
    - `HEAD:e2e/cases/tracee/case.py:976-984`
    - `HEAD:e2e/cases/tracee/config.yaml:1-8`
    - `HEAD:e2e/cases/tetragon/case.py:618-620`
    - `HEAD:e2e/cases/tetragon/config.yaml:7-8`
  - Commit anchor:
    - `4cd2c4c9` removed `--smoke` from `e2e/driver.py:156-167`
  - Why this matters:
    - Even ignoring the broken shim above, the cleanup is incomplete.
    - The committed canonical entrypoint no longer exposes smoke mode, so these branches/configs are dead residue and keep the old split alive in source.

### 🟢 NICE

- No additional code-level lazy rename, silent-skip, or new fallback issue surfaced beyond the smoke-path inconsistency above.
  - I did not find a second independent behavior bug in the reviewed range.

## Reasonable Retentions / Legitimate Changes

- `7c81db17` + `553e38b8`
  - Real new functionality, but explicit and coherent: checked-in upstream Tetragon policy pack plus runner/image wiring.
  - Not a lazy rename, not a fallback shim.

- `f8bd2575`
  - `daemon/src/elf_parser.rs` converting `collect_global_data_maps` to `Result<Vec<_>>` is a fail-loud tightening, not a behavior-preserving rename.
  - `daemon/src/profiler.rs` uses `eprintln!` in `Drop`; that is the loudest viable path in Rust `Drop`, not a silent swallow.

- `0f0eadeb`
  - `finalize_process_output()` now requires `collector`, and the only live callsite passes one.
  - The deleted no-collector path is genuinely dead.

- `be74a91b`
  - `BCCRunner` constructor narrowing is legitimate because source-tree now has a single explicit caller.

- `7862b308`
  - Deleting the corpus consumer of `prog_type_name` is legitimate because live runner program records already carry `type` from `bpftool prog show`, and corpus still has section-based fallback via `_infer_prog_type_name()`.

## Sign-Off

- Verdict:
  - This batch is **mostly real cleanup**, deletion-heavy, and substantially purges dead surfaces.
  - It **does introduce one real new problem**: a broken `--e2e-smoke` shim in `ccd8debe`.
  - It also leaves behind smoke-mode residue in Tracee/Tetragon source after the shared entrypoint stopped supporting that mode.

- Most important fixes:
  - Remove `--e2e-smoke` from `runner/suites/e2e.py`, or restore a fully coherent end-to-end smoke path. Current state is broken.
  - Delete the remaining Tracee/Tetragon `args.smoke` / `smoke_*` branches and config if smoke mode is no longer supported.
  - Add a tiny non-VM CLI contract test for `runner/suites/e2e.py -> e2e/driver.py` arg wiring so this class of wrapper/driver mismatch cannot land again.

- Cleanliness score:
  - `3/5`
  - Rationale: deletion quality is generally high; no true lazy rename wave, no new silent-failure idioms, and no test weakening. The one blocker is concrete and avoidable, and the smoke cleanup is not fully closed.

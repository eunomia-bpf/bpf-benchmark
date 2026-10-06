# Complexity Review 2026-04-22

Scope: read-only repo scan, excluding `docs/tmp`, `corpus/results`, `e2e/results`, `runner/build-*`, and `vendor` except for the required background docs. No VM runs.

## CRITICAL

### 1. `changed` and `summary.program_changed` are duplicate truth sources for the same fact

Evidence:
- `runner/libs/rejit.py:629-640` validates both fields and fails if they disagree.
- `runner/libs/rejit.py:658-667` persists both into the normalized apply record.
- `runner/libs/case_common.py:97-117` reads both normalized copies and both raw `debug_result` copies.
- `corpus/driver.py:465-479` reads both again while deciding whether anything changed.

Why this is dead/redundant:
- This is one boolean fact expressed four times: daemon top-level `changed`, daemon `summary.program_changed`, normalized `changed`, and raw `debug_result.summary.program_changed`.
- Readers now need to consult multiple schemas for the same answer.
- Drift is correctness-impacting, not cosmetic: the runner hard-fails if the two daemon fields diverge.

Suggested deletion:
- Delete one representation end-to-end. Keep a single canonical "program changed" boolean in the daemon response and delete the other field plus all duplicate reader branches.

Caller / consumer grep:
```text
$ rg -n 'summary\\.program_changed|response.get\\("changed"\\)|debug_result.get\\("changed"\\)|debug_summary.get\\("program_changed"\\)' runner corpus
runner/libs/rejit.py:629:            program_changed = summary.get("program_changed")
runner/libs/rejit.py:634:            changed = response.get("changed")
runner/libs/rejit.py:639:                    "daemon response fields 'changed' and 'summary.program_changed' disagree"
runner/libs/case_common.py:102:            if isinstance(summary.get("program_changed"), bool) and bool(summary.get("program_changed")):
runner/libs/case_common.py:108:            if isinstance(debug_result.get("changed"), bool) and bool(debug_result.get("changed")):
runner/libs/case_common.py:112:                if isinstance(debug_summary.get("program_changed"), bool) and bool(
corpus/driver.py:467:        if bool(summary.get("program_changed")):
corpus/driver.py:473:        if bool(debug_result.get("changed")):
corpus/driver.py:477:            if bool(debug_summary.get("program_changed")):
```

## HIGH

### 2. `counts.total_sites` and `counts.applied_sites` are fabricated aliases of `summary.total_sites_applied`

Evidence:
- `runner/libs/rejit.py:641-667` reads `summary.total_sites_applied`, then writes:
  - `counts.total_sites = applied_sites`
  - `counts.applied_sites = applied_sites`
- `runner/libs/case_common.py:348-356` aggregates `counts.total_sites` and `counts.applied_sites`.
- `runner/libs/case_common.py:102-104,116` separately reads `summary.total_sites_applied`.
- `corpus/driver.py:463,469,479,930-933` reads both `counts.*` and `summary.total_sites_applied`.

Why this is dead/redundant:
- One integer is maintained in two schemas.
- `counts.total_sites` is especially misleading because it is not a real total; it is copied from `applied_sites`.
- Consumers are split between the synthetic `counts` wrapper and the original summary field, so the duplicate shape keeps propagating.

Suggested deletion:
- Delete the synthetic `counts` wrapper here and keep a single canonical site-count field. Do not carry both.

Caller / consumer grep:
```text
$ rg -n 'counts\\.get\\(|summary\\.get\\("total_sites_applied"\\)|debug_summary\\.get\\("total_sites_applied"\\)' corpus/driver.py runner/libs/case_common.py
corpus/driver.py:463:    if isinstance(counts, Mapping) and int(counts.get("applied_sites", 0) or 0) > 0:
corpus/driver.py:469:        if int(summary.get("total_sites_applied", 0) or 0) > 0:
corpus/driver.py:479:            if int(debug_summary.get("total_sites_applied", 0) or 0) > 0:
corpus/driver.py:932:            total_sites += int(counts.get("total_sites", 0) or 0)
corpus/driver.py:933:            applied_sites += int(counts.get("applied_sites", 0) or 0)
runner/libs/case_common.py:104:            if (_non_negative_int(summary.get("total_sites_applied")) or 0) > 0:
runner/libs/case_common.py:116:                if (_non_negative_int(debug_summary.get("total_sites_applied")) or 0) > 0:
runner/libs/case_common.py:355:            total_sites += int(counts.get("total_sites", 0) or 0)
runner/libs/case_common.py:356:            applied_sites += int(counts.get("applied_sites", 0) or 0)
```

### 3. Many `e2e` case-level override fields are dead compatibility residue with no parser or setter

Dead override fields confirmed:
- `smoke_duration`
- `attach_timeout`
- `load_timeout`
- `tracee_binary`
- `tetragon_binary`
- `tracee_extra_arg`
- `scheduler_binary`
- `scheduler_extra_arg`
- `tools_dir`

Evidence:
- `e2e/driver.py:184-198` is the only active CLI parser and does not define any of those names.
- `e2e/driver.py:376-377,390-401,409` only injects `config`, `tools`, `scripts`, `workloads`, `workload`, and `_suite_workload_overrides`.
- Readers still exist in cases:
  - `e2e/cases/bpftrace/case.py:430-433`
  - `e2e/cases/bcc/case.py:441-458`
  - `e2e/cases/tracee/case.py:1218-1221,1263,1301`
  - `e2e/cases/tetragon/case.py:817-825,862`
  - `e2e/cases/scx/case.py:581,600-601`
- `rg -n '__main__|build_parser\\(|parse_args\\(' e2e/cases` returns no hits, so the cases no longer have standalone CLIs that could set these fields.
- A setter search for those exact names returned no hits in `e2e/driver.py` or `e2e/cases`.

Why this is dead/redundant:
- These `getattr(args, ...)` branches only preserve an API that no current entrypoint actually supplies.
- They add indirection and false configurability, but every real execution path falls back to config/defaults.

Suggested deletion:
- Delete the unreachable override branches and keep only the inputs that `e2e/driver.py` or suite setup actually provide.

Caller / consumer grep:
```text
$ rg -n '__main__|build_parser\\(|parse_args\\(' e2e/cases
# no hits

$ rg -n 'add_argument\\(|setattr\\(args,|args\\.[A-Za-z_][A-Za-z0-9_]* =' e2e/driver.py e2e/cases | rg 'smoke_duration|attach_timeout|load_timeout|tracee_binary|tetragon_binary|tracee_extra_arg|scheduler_binary|scheduler_extra_arg|tools_dir'
# no hits
```

### 4. Daemon JSON still emits legacy `passes[].pass` alongside `passes[].pass_name`

Evidence:
- `daemon/src/commands.rs:123-149` defines both `pass` and `pass_name`, both populated from `pr.pass_name`.
- `runner/libs/rejit.py:465-470` still accepts either key.
- `daemon/src/commands_tests.rs:145-146` asserts that both keys exist.

Why this is dead/redundant:
- `pass` is a pure echo alias. It carries no extra meaning beyond `pass_name`.
- Within the active benchmark code, the only non-test reader is the compatibility fallback in `runner/libs/rejit.py`.

Suggested deletion:
- Delete `passes[].pass` from the daemon response, delete the runner fallback to `"pass"`, and update the test to assert only `pass_name`.

Caller / consumer grep:
```text
$ rg -n --glob '!runner/build-*/**' --glob '!vendor/**' --glob '!runner/repos/**' '\\.get\\("pass"\\)|\\["pass"\\]|"pass_name" if "pass_name" in item else "pass"' runner e2e corpus tests daemon/src
daemon/src/commands_tests.rs:145:    assert_eq!(parsed["passes"][0]["pass"], "wide_mem");
runner/libs/rejit.py:465:        pass_name_key = "pass_name" if "pass_name" in item else "pass"
```

### 5. Pending `kinsn` lifecycle overlay and its self-referential metadata fields are write-only artifact scaffolding

Evidence:
- Global pending overlay and attach path:
  - `runner/libs/case_common.py:25`
  - `runner/libs/case_common.py:32-49`
  - `runner/libs/case_common.py:82-85`
- Self-referential field writes:
  - `runner/libs/case_common.py:193-201`
  - `runner/libs/case_common.py:427`
  - `runner/libs/case_common.py:507-530`
- Top-level callers:
  - `e2e/driver.py:514,521,576,598`
  - `corpus/driver.py:1161,1393,1477,1487`

Write-only fields confirmed in source:
- `captured_at`
- `status`
- `lifecycle_index`
- `count`
- `lifecycle_runs`
- `daemon_kinsn_discovery`
- `abort_phase`

Why this is dead/redundant:
- The code maintains a global pending queue, injects lifecycle sequencing metadata, and writes status transitions like `ready`, `pending`, `completed`, `error`, and `aborted`.
- Source grep under `runner/`, `e2e/`, `corpus/`, and `tests/` finds constructors/writers, but no consumer that reads those fields back to drive behavior or reporting.
- This is extra global state plus artifact noise without an in-repo reader.

Suggested deletion:
- Delete `_PENDING_KINSN_METADATA`, `reset_pending_result_metadata()`, `attach_pending_result_metadata()`, `_append_pending_kinsn_metadata()`, and the unconsumed self-referential metadata fields above.

Caller / consumer grep:
```text
$ rg -n --glob '!docs/tmp/**' --glob '!corpus/results/**' --glob '!e2e/results/**' --glob '!runner/build-*/**' --glob '!vendor/**' 'captured_at|lifecycle_runs|daemon_kinsn_discovery|abort_phase|\\.get\\("kinsn_modules"\\)|\\["kinsn_modules"\\]' runner e2e corpus tests
runner/libs/case_common.py:40:    existing_kinsn = metadata_payload.get("kinsn_modules")
runner/libs/case_common.py:42:    existing_runs = kinsn_payload.get("lifecycle_runs")
runner/libs/case_common.py:45:    kinsn_payload["count"] = len(lifecycle_runs)
runner/libs/case_common.py:46:    kinsn_payload["lifecycle_runs"] = lifecycle_runs
runner/libs/case_common.py:193:    metadata.update(captured_at=datetime.now(timezone.utc).isoformat(), daemon_binary=relpath(binary),
runner/libs/case_common.py:194:                    daemon_kinsn_discovery=_capture_daemon_kinsn_discovery(...),
runner/libs/case_common.py:201:    metadata.update(captured_at=datetime.now(timezone.utc).isoformat(), status="pending")
runner/libs/case_common.py:427:            kinsn_metadata.update(status="aborted", reason=abort.reason, abort_phase=phase)
runner/libs/case_common.py:530:            artifacts["kinsn_modules"] = copy.deepcopy(kinsn_metadata)
```

## MEDIUM

### 6. Tetragon setup is inspected twice on the only call path

Evidence:
- `e2e/cases/tetragon/case.py:817-825` resolves or inspects setup before execution.
- `e2e/cases/tetragon/case.py:603-610` then instantiates `TetragonRunner` without passing the already-built `setup_result`.
- `runner/libs/app_runners/tetragon.py:250-257` re-runs `inspect_tetragon_setup()` whenever `self.setup_result is None`.
- `rg -n 'TetragonRunner\\(' runner e2e corpus tests` finds only `e2e/cases/tetragon/case.py:605`.

Why this is dead/redundant:
- The only caller already resolved the binary and assembled setup diagnostics for payload/error reporting.
- The runner then repeats setup inspection because that state is not threaded through.
- This is duplicate validation / duplicate setup ownership with no alternative caller to justify both paths.

Suggested deletion:
- Delete one setup path. Either keep case-owned setup and delete runner-side implicit inspection, or delete the pre-run inspection in the case and let the runner own setup. Do not keep both.

Caller / consumer grep:
```text
$ rg -n --glob '!runner/build-*/**' --glob '!vendor/**' --glob '!runner/repos/**' 'TetragonRunner\\(' runner e2e corpus tests
e2e/cases/tetragon/case.py:605:        runner = TetragonRunner(
runner/libs/app_runners/tetragon.py:230:class TetragonRunner(AppRunner):
```

## LOW

### 7. Top-level `Makefile` still carries unused variables

Evidence:
- Definitions:
  - `Makefile:7` `REPO_ROOT := $(ROOT_DIR)`
  - `Makefile:12` `KERNEL_TEST_DIR := $(ROOT_DIR)/tests/kernel`
  - `Makefile:45` `REPOS ?=`
  - `Makefile:75` `VENV_ACTIVATE := $(if $(VENV),source "$(VENV)/bin/activate" &&,)`
- Top-level expansion search returns no uses for any of the four variables.

Why this is dead/redundant:
- They are defined in the root `Makefile` but never expanded there.
- They add surface area without affecting any target.

Suggested deletion:
- Delete `REPO_ROOT`, `KERNEL_TEST_DIR`, `REPOS`, and `VENV_ACTIVATE` from the top-level `Makefile`.

Caller / consumer grep:
```text
$ for s in '$(REPO_ROOT)' '$(KERNEL_TEST_DIR)' '$(VENV_ACTIVATE)' '$(REPOS)'; do rg -n -F "$s" Makefile; done
# no hits for all four expansions
```

## Investigate Further

### A. `target_prog_ids` / `apply_prog_ids` still looks collapsible in most cases, but SCX still uses the split

Evidence:
- Generic lifecycle startup still seeds both identically: `runner/libs/case_common.py:546-548`.
- SCX remaps only `apply_prog_ids` to live scheduler IDs at baseline time: `e2e/cases/scx/case.py:365-392`.
- Corpus app sessions read only `state.apply_prog_ids`: `corpus/driver.py:1079-1080`.

Why this needs more context:
- Program selection semantics are gone, but SCX still uses `apply_prog_ids` as a live-ID remap container.
- The split may still be deletable, but only after deciding where that SCX live-ID map should live instead.

### B. `OptimizeOneResult` and `ServeOptimizeResponse` look like a near-duplicate daemon response layer

Evidence:
- `daemon/src/commands.rs:21-57` defines two almost-identical structs.
- `daemon/src/commands.rs:59-81` converts one to the other by copying fields and blanking `attempt.debug`.
- `daemon/src/server.rs:489` is the active response serialization site.

Why this needs more context:
- This smells like an unnecessary response abstraction layer, but it is not dead code yet.
- One more pass is needed to decide which struct to delete without smuggling in a new mutation layer elsewhere.

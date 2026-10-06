# Round 3+4 Semantic Verification

Reviewed inputs:
- Required Round 3/4 summaries under `docs/tmp/...`
- `git diff HEAD --stat -- . ':!docs/tmp'` and per-file `git diff HEAD -- <file>`
- Current file bodies with numbered context for all 38 changed files

Static cross-checks:
- `python3 -m pyflakes` on changed Python files: 2 findings, both dead imports
- `python3 -m py_compile` on changed Python files: passed
- `cargo check --manifest-path daemon/Cargo.toml --quiet`: passed

## Part 1 — 每个改动文件的 semantic inspection

### Build / Config
- `Makefile` — removed truly unused top-level vars (`REPO_ROOT`, `KERNEL_TEST_DIR`, `REPOS`, `VENV_ACTIVATE`) and nothing in the current make graph still references them. Residue: none. Score: `清洁`.
- `e2e/cases/bcc/config.yaml` — migrated tool workload metadata to `workload_spec` and kept only fields that current BCC loaders read. Residue: none. Score: `清洁`.
- `e2e/cases/tetragon/config_execve_rate.yaml` — config now matches the slimmer `WorkloadSpec`/runner path; deleted description-only metadata is not read anywhere. Residue: none. Score: `清洁`.

### Python Runtime / Glue
- `runner/libs/agent.py` — removed PID/fd ownership discovery helpers cleanly; no remaining callers or exports reference `find_bpf_programs`, `_resolve_pids`, or `_program_refs_from_pid`. Residue: none. Score: `清洁`.
- `runner/libs/app_suite_schema.py` — deleted nested-`args` compatibility and `max_apps`; all live callers use flat app keys and the new signature. Residue: none. Score: `清洁`.
- `runner/libs/workload.py` — `run_named_workload()` parameter rename is semantic no-op; current callers already pass the workload kind positionally/by the new name. Residue: none. Score: `清洁`.
- `runner/libs/case_common.py` — lifecycle simplification is coherent and no caller drift was introduced. Residue: duplicate scan-result shape support still survives at `runner/libs/case_common.py:213-218` and `runner/libs/case_common.py:599-601` (`sites` vs `counts`). Score: `残留`.
- `runner/libs/rejit.py` — daemon response cleanup is coherent and all changed readers now use `error_message`/`pass_name`. Residue: `_site_count_for_pass()` still accepts legacy bare pass-name keys at `runner/libs/rejit.py:225-239`, even though the current scan path synthesizes canonical `*_sites` counters only. Score: `残留`.
- `corpus/driver.py` — deleted corpus-side app-runner lifecycle wrapper cleanly; no functional caller/type drift remains. Residue: dead import `run_app_runner_lifecycle` remains in the import block at `corpus/driver.py:24-31`, and the dead `app_name=` plumbing is still passed at `corpus/driver.py:1082-1086`. Score: `残留`.
- `e2e/driver.py` — pending-result metadata removal and `prepare_daemon_session()` signature shrink are semantically complete; helper definitions were removed, not orphaned. Residue: none in changed hunks. Score: `清洁`.
- `runner/libs/app_runners/__init__.py` — runner adapter cleanup propagated cleanly to workload-shape changes. Residue: every adapter still accepts/discards `app_name`, and `get_app_runner()` still exposes it at `runner/libs/app_runners/__init__.py:9-10,21-22,33-34,46-47,55-56,64-65,82-94`. Score: `残留`.
- `runner/libs/app_runners/bcc.py` — `workload_spec` migration and timeout cleanup are semantically consistent with current callers. Residue: `BCCWorkloadSpec.name` at `runner/libs/app_runners/bcc.py:168-170` is written during config load (`runner/libs/app_runners/bcc.py:230-233`) but no longer read. Score: `残留`.
- `runner/libs/app_runners/bpftrace.py` — `description`/`workload_kind` removal is complete; script resolution and workload dispatch now use one shape. Residue: none. Score: `清洁`.
- `runner/libs/app_runners/katran.py` — old “guess the attached program by name” heuristic was fully removed; current callers use attach metadata and still get a valid prog_id. Residue: none. Score: `清洁`.
- `runner/libs/app_runners/tetragon.py` — `setup_result` is now explicit and the only live caller passes it; no fallback caller was left behind. Residue: none. Score: `清洁`.
- `runner/libs/app_runners/tracee.py` — strict parser / partial-line buffer removal is semantically complete; no orphan parse-error machinery remains. Residue: dead import `resolve_bpftool_binary` remains at `runner/libs/app_runners/tracee.py:20`. Score: `残留`.

### E2E Cases
- `e2e/cases/bcc/case.py` — workload-shape migration and artifact slimming are semantically complete; reports and summaries no longer read deleted fields. Residue: dead `setup_result` skeleton at `e2e/cases/bcc/case.py:431-436` is immediately overwritten by `inspect_bcc_setup()` at line 437. Score: `残留`.
- `e2e/cases/bpftrace/case.py` — `description`/`workload_kind` deletion propagated through selection, runner construction, payload shape, markdown, and report generation. Residue: none. Score: `清洁`.
- `e2e/cases/katran/case.py` — payload now consistently uses `workload_spec`; removed `runner_artifacts`/`workload_kind` reads are gone. Residue: none in changed path. Score: `清洁`.
- `e2e/cases/scx/case.py` — deleted CLI override accommodation cleanly; current entry path does not expose those knobs, and the remaining live/logical prog-id remap is still required for SCX. Residue: none in changed path. Score: `清洁`.
- `e2e/cases/tetragon/case.py` — helper removals and explicit `setup_result` propagation are coherent; `TetragonRunner` has exactly one live caller and it matches the new contract. Residue: dead `setup_result` skeleton at `e2e/cases/tetragon/case.py:784-790` is immediately overwritten at line 791. Score: `残留`.
- `e2e/cases/tracee/case.py` — strict collector error path removal is coherent and no caller still expects parse-error exceptions. Residue: dead `setup_result` skeleton at `e2e/cases/tracee/case.py:1209-1214` is immediately overwritten at line 1215. Score: `残留`.

### Rust Daemon Core
- `daemon/src/commands.rs` — removed duplicated serialized fields (`pass`, `program_changed`) without leaving stale readers; Python side now reads only `pass_name` and `error_message`. Residue: none. Score: `清洁`.
- `daemon/src/commands_tests.rs` — test fixtures/assertions were updated everywhere the deleted fields appeared; no stale schema expectations remain. Residue: none. Score: `清洁`.
- `daemon/src/pass.rs` — `PassResult::{unchanged, skipped, skipped_with_diagnostics}` is live and fully used by the changed pass files; no dead constructor or stale field handling remains. Residue: none. Score: `清洁`.
- `daemon/src/server.rs` — error payload key unification to `error_message` is consistent across request handlers, panic wrapper, JSON parse failures, and command dispatch. Residue: none. Score: `清洁`.

### Rust Passes
- `daemon/src/passes/bounds_check_merge.rs` — open-coded unchanged returns were collapsed to helpers; current skip branches still carry the correct `sites_skipped`. Residue: none. Score: `清洁`.
- `daemon/src/passes/branch_flip.rs` — helper migration is complete for PMU-missing, threshold-skip, and no-safe-site paths; diagnostics are still preserved where needed. Residue: none. Score: `清洁`.
- `daemon/src/passes/bulk_memory.rs` — unchanged helper migration is complete and left no manual dead scaffolding behind. Residue: none. Score: `清洁`.
- `daemon/src/passes/cond_select.rs` — helper migration is complete, including the diagnostic-only “kfunc unavailable but sites found” case. Residue: none. Score: `清洁`.
- `daemon/src/passes/const_prop.rs` — helper migration is complete and the `const_prop`/`dce` fixed-point loop in `pass.rs` still matches the current return shape. Residue: none. Score: `清洁`.
- `daemon/src/passes/dce.rs` — helper migration is complete; no stale manual unchanged record remains. Residue: none. Score: `清洁`.
- `daemon/src/passes/endian.rs` — helper migration is complete for kfunc-not-available, packed-ABI-not-available, and no-safe-site paths. Residue: none. Score: `清洁`.
- `daemon/src/passes/extract.rs` — helper migration is complete; skip reasons and unchanged paths still serialize correctly. Residue: none. Score: `清洁`.
- `daemon/src/passes/map_inline.rs` — helper migration is complete and map-inline metadata still survives the zero-apply path. Residue: none. Score: `清洁`.
- `daemon/src/passes/rotate.rs` — helper migration is complete; remaining pseudo-call and ABI guards are still semantically needed, not dead defense. Residue: none. Score: `清洁`.
- `daemon/src/passes/skb_load_bytes.rs` — helper migration is complete and the empty-program / layout-missing guards are still real guards. Residue: none. Score: `清洁`.
- `daemon/src/passes/wide_mem.rs` — helper migration is complete; remaining changed path still carries diagnostics and no deleted field is read. Residue: none. Score: `清洁`.

## Part 2 — 需要补删的清单（Round 5 候选）

No `HIGH` severity dead/broken residue found in the changed files. The remaining items are non-blocking cleanup.

- `MEDIUM`, estimated `18-24` LOC — dead `app_name` plumbing across `runner/libs/app_runners/__init__.py:9-10,21-22,33-34,46-47,55-56,64-65,82-94` and `corpus/driver.py:1082-1086`

```py
def _adapt_bcc(workload: str | None, app_name: str | None, kwargs: dict[str, object]) -> dict[str, object]:
    del app_name
    ...

runner = get_app_runner(
    app.runner,
    app_name=app.name,
    workload=app.workload_for("corpus"),
    **app.args,
)
```

Why dead: all adapters now ignore `app_name`; runner selection already comes from flat `tool` / `script` / `scheduler` keys or explicit workload config.

Delete path: remove `app_name` from `get_app_runner()`, drop it from all adapter signatures, delete the corpus caller kwarg.

- `MEDIUM`, estimated `10-14` LOC — duplicate scan-result shape (`sites` + `counts`) at `runner/libs/rejit.py:573` and `runner/libs/case_common.py:213-218,599-601`

```py
results[prog_id] = {
    "prog_id": int(prog_id),
    "sites": dict(counts),
    "counts": dict(counts),
    "error": "",
}

counts = record.get("sites") or record.get("counts") or {}
```

Why dead: `scan_programs()` is the only producer on the live path and it materializes both keys from the same dict; readers already treat them as interchangeable.

Delete path: keep one canonical field (`counts` is the clearer name), update `_scan_record_counts()` and `run_app_runner_phase_records()` to read only that field.

- `LOW`, estimated `4-6` LOC — legacy bare-pass-name fallback at `runner/libs/rejit.py:225-239`

```py
for key in (field_name, pass_name):
    if key not in site_counts:
        continue
```

Why dead: the current scan pipeline always builds canonical `*_sites` counters; no live producer returns `{ "rotate": 3 }`-style counts anymore.

Delete path: accept only the canonical `field_name`.

- `LOW`, estimated `12-15` LOC — three overwritten `setup_result` skeletons at `e2e/cases/bcc/case.py:431-437`, `e2e/cases/tracee/case.py:1209-1216`, and `e2e/cases/tetragon/case.py:784-791`

```py
setup_result = {
    "returncode": 0,
    ...
}
setup_result = inspect_..._setup()
```

Why dead: the literal dict is never read before being replaced.

Delete path: assign the `inspect_*_setup()` result directly.

- `LOW`, estimated `2` LOC — dead imports at `corpus/driver.py:24-31` and `runner/libs/app_runners/tracee.py:20`

```py
from runner.libs.case_common import ..., run_app_runner_lifecycle, ...
from .. import ROOT_DIR, resolve_bpftool_binary, run_command, tail_text, which
```

Why dead: neither imported name is referenced in the current body.

Delete path: remove the two imports.

- `LOW`, estimated `1-2` LOC — dead dataclass field `BCCWorkloadSpec.name` at `runner/libs/app_runners/bcc.py:168-170`

```py
@dataclass(frozen=True)
class BCCWorkloadSpec:
    name: str
    workload_spec: Mapping[str, object]
```

Why dead: the loaded spec is looked up by dict key; after construction the field is never read.

Delete path: remove the field and its constructor assignment.

## Part 3 — 发现的 bug（broken caller / type drift / 语义错）

None.

I did not find a live broken caller / return-shape drift in the changed files. In particular:
- `runner/libs/rejit.py` and `daemon/src/server.rs` now consistently use `error_message`.
- `daemon/src/commands.rs` field deletions (`pass`, `program_changed`) were reflected everywhere they were read or asserted.
- `runner/libs/app_suite_schema.py` signature changes (`max_apps`, nested `args`) have no live callers left.
- `runner/libs/app_runners/tetragon.py`’s new `setup_result` requirement matches its only live caller.

The suspicious-looking deleted per-case CLI override paths in `bcc` / `bpftrace` / `scx` / `tracee` / `tetragon` did not leave a broken caller: the current `e2e/driver.py` parser does not expose those knobs, and no live code constructs those args.

## Part 4 — 更广泛的持续删除候选

- Estimated `25-40` LOC — isolate the SCX-specific live-id remap, then collapse the generic `target_prog_ids` / `apply_prog_ids` dual-plumbing in `runner/libs/case_common.py:103-110`, `corpus/driver.py:1045-1046`, and `e2e/cases/scx/case.py:326-398`. This is still live today, so it is not Part 2 dead code, but it remains the biggest complexity hotspot after Round 4.
- Estimated `3-5` LOC — `e2e/driver.py:394-399` still injects `args.workload` for katran, while `e2e/cases/katran/case.py:110` hardcodes `{"kind": "network"}` and never reads that arg. Current suite data makes this non-buggy (`macro_apps.yaml` already supplies `e2e: network`), but the setter is dead plumbing on the current path.
- Estimated `4-6` LOC — inline `CorpusAppSession.prog_ids()` at `corpus/driver.py:1045-1046` into `session.state.prog_ids()`. It is a one-line wrapper over existing lifecycle-state logic.

## Part 5 — 判定

`Round 3+4 is semantically clean. VM sample 可以 safely proceed.`

Non-blocking Round 5 cleanup remains, but I did not find a must-fix semantic bug before a VM sample run.

# New Benchmark Architecture Review (2026-03-29)

## Scope

Reviewed:

- `corpus/orchestrator.py`
- `runner/libs/app_runners/bcc.py`
- `runner/libs/bpf_stats.py`
- `runner/Makefile`
- root `Makefile`
- `.gitignore`
- design alignment against plan doc §5.6

Validation used only host-safe checks:

- `pytest -q tests/python/test_corpus_orchestrator.py tests/python/test_bcc_case.py tests/python/test_bcc_runner.py tests/python/test_bpf_stats.py tests/python/test_case_common.py tests/python/test_corpus_manifest.py`
- `python3 -m py_compile corpus/orchestrator.py runner/libs/app_runners/bcc.py runner/libs/bpf_stats.py`

No host-kernel BPF loading or VM benchmark execution was performed in this review turn.

## Findings

### Fixed

1. `test_run` path violated same-image measurement and no-fallback policy.

- Before: `corpus/orchestrator.py` silently downgraded failed `bpftool prog run` measurements to a `micro_exec` reload fallback.
- Problem: that fallback does **not** measure the live REJIT-mutated kernel program, so it breaks the paired baseline/rejit model and violates the repo-level “no fallback behavior” rule.
- Fix: removed the fallback path. Each program now either produces a real `bpftool`-based same-image measurement or returns an explicit per-program error.

2. `test_run` object status could stay `ok` even when individual programs failed.

- Before: per-program failures were hidden inside `records[*].error`, while the object-level `status` and top-level summary could still report success.
- Fix: object status now aggregates record statuses fail-close, and the JSON now includes per-record `status` plus a `summary.statuses` block.

3. `BCCRunner` allowed partial attach success.

- Before: `start()` only failed when **zero** programs attached. If fewer-than-expected programs attached, or if only a subset of expected program names appeared, the run still continued.
- Problem: this is a classic silent degradation and violates zero-silent-failure.
- Fix: `BCCRunner.start()` now fails when attach count is short or any expected program name is missing, and it includes process tail output in the error.

4. `BCCRunner` did not inherit repo-shared default `tool_args`.

- Before: shared BCC config contributed `workload_kind`, `expected_programs`, and timeout, but not `tool_args`.
- Problem: corpus app-native execution could diverge from the E2E path for the same BCC tool.
- Fix: shared config now carries default `tool_args`, and `BCCRunner` uses them unless explicitly overridden.

5. `read_program_stats()` could silently drop unresolved program IDs.

- Before: if a requested program ID was missing from both `bpftool` and `libbpf` lookup, the function returned partial data instead of failing.
- Problem: app-native `exec_ns` aggregation could silently skip a program.
- Fix: unresolved requested IDs now raise a clear error. Existing FD close behavior remains intact and is covered by a test.

6. `vm-corpus` target was stale and effectively broken.

- Before: root `vm-corpus` still forwarded old architecture flags (`--profile`, `--batch-size`, `--warmups`, etc.) through `corpus/driver.py`, but `driver.py` now just forwards to the new orchestrator, which does not accept those flags.
- Fix: rewired `vm-corpus` to invoke the new orchestrator directly. `vm-corpus-new` remains as the validated subset target; `vm-corpus` is now the full new-architecture entry.

7. Plan doc §5.6 had drifted from the implemented corpus architecture.

- Before: §5.6 still described corpus `test_run` as a `micro_exec`-owned path.
- Fix: updated §5.6 to reflect the current corpus design: Python orchestrator + `bpftool` + `bpf_stats`, while `micro_exec` remains the isolated micro-benchmark tool.

8. `.gitignore` had date-specific scratch rules that did not generalize.

- Fix: generalized `docs/tmp/*/guest-scripts/`, `docs/tmp/*/vm-tmp/`, added `corpus/results/*/guest-inputs/`, and kept the requested `llvmbpf_roundtrip_poc/llvmbpf_build` ignore coverage.

### Remaining Gaps

1. App-native coverage is still incomplete.

- `runner/libs/app_runners/__init__.py` only wires `bcc` today.
- The default macro corpus manifest already contains many `app_native` objects from other repos.
- Current behavior is explicit `unsupported`, not silent, so this is not a correctness bug in this turn, but it is still a benchmark completeness gap.

2. Optional legacy selftests manifest still contains old `attach_trigger` / `compile_only` schema.

- The default production macro corpus is already on `measurement: app_native | test_run`, and tests enforce that.
- The optional linux-selftests manifest is still legacy-shaped. That is tolerable only because it is opt-in and outside the default path.

## Area-by-Area Verdict

### 1. `corpus/orchestrator.py`

- Code cleanliness: acceptable after removing the dead fallback path.
- Error handling: now aligned with zero-silent-failure for both app-native stats collection and `test_run` measurement.
- `app_native` path: structurally sound for implemented app runners.
- `test_run` path: now fail-close and same-image.
- `bpftool` handling: explicit JSON parsing plus propagated failure.
- daemon socket usage: relies on existing `runner.libs.rejit` socket helpers; no direct issue found here.
- result JSON: improved with per-record status aggregation.

### 2. `runner/libs/app_runners/bcc.py`

- Interface: clean `start` / `run_workload` / `stop`.
- Process lifecycle: no leak found in reviewed path; stop still cleans tempdir/log handles.
- Error handling: improved materially by fail-close attach validation and executable-path validation.

### 3. `runner/libs/bpf_stats.py`

- `enable_bpf_stats()`: correct FD lifetime handling.
- `read_program_stats()`: now fail-close for missing requested IDs.
- FD handling: no leak observed; explicit close is still in `finally`.

### 4. Overall architecture consistency

- Current code now matches the intended “Python orchestrator owns corpus coordination” direction.
- The biggest architecture inconsistency was the stale `vm-corpus` target and the stale §5.6 wording; both are fixed in this change set.
- Old architecture residues are no longer on the active default corpus path, but optional legacy manifests still exist.

## Bottom Line

The reviewed implementation is now substantially cleaner and more defensible. The major correctness hazards were not in the happy path; they were in silent degradation paths around fallback, partial attach acceptance, partial stats reads, and stale Makefile wiring. Those issues are fixed here.

What remains is mostly coverage and rollout work, not hidden correctness debt:

- implement more app runners,
- migrate optional legacy manifests when they are brought back into scope,
- run the updated `vm-corpus` path in VM once broader app-native coverage is ready.

# Final Cleanup Verification Report

Date: 2026-03-13

## Checklist Results

### 1. git status

Before fixes: untracked `config/ablation/`, `micro/policies/ablation/`, and one JSON file.
After fixes: **clean** — no untracked files.

### 2. Root directory

Root directory is clean: CLAUDE.md, config, corpus, docs, e2e, legacy, Makefile, micro, README.md, reference, docs/REVIEW.md, scanner, tests, tmp, vendor. No loose scripts or temp files.

`tmp/` directory exists but is now properly gitignored (56 previously-tracked scratch files removed from git).

### 3. CLAUDE.md accuracy

Two issues fixed:

- **user_bpf_benchmark reference**: was `user_bpf_benchmark/`, now correctly says `legacy/user_bpf_benchmark/`.
- **macro_corpus.yaml location**: was `config/`, now correctly says `corpus/config/macro_corpus.yaml`.
- **benchmark count**: updated from 56 to 62 (post per-form dense benchmarks).
- **config/ablation/ section**: added entry documenting the ablation YAML directory.

### 4. README.md accuracy

README is accurate and consistent with current layout. References to `micro/driver.py`, `e2e/run.py`, `corpus/build_expanded_corpus.py` all verified to exist and work.

### 5. Makefile targets

All three verified:
- `make help` — OK, shows all targets
- `make verify-build` — OK (`[verify-build] OK`)
- `make smoke` — OK (exec median ~60ns, result 12345678)

### 6. config/ directory

```
config/
  micro_pure_jit.yaml        # active suite
  ablation/                  # 7 per-family ablation YAMLs (now committed)
```

No unnecessary files.

### 7. micro/archive/scripts/

Contains legitimate analysis scripts:
- `analyze_*.py` (jit, paradox, performance, pmu, representativeness, stability, statistics)
- `build_policy_blob.py`, `demo_policy_iteration.py`
- `run_pass_ablation.py`, `run_rigorous.py`, `run_rigorous_framework_vm.py`

All are archived legacy scripts — appropriate location.

### 8. corpus/tmp/

Contains only `cross_domain_census.py` — a single live script, not scratch data. OK.

### 9. e2e/ structure

Python files exist and compile cleanly:
- `e2e/run.py` ✓
- `e2e/run_e2e_tracee.py` ✓
- `e2e/common/*.py` ✓
- `e2e/cases/*/case.py` ✓

### 10. .gitignore completeness

Issues fixed:
- Added `tmp/` (without leading slash) to properly ignore the root `tmp/` scratch directory
- Added `micro/policies/ablation/` to ignore generated ablation policy files
- Added `*.tmp.md` to ignore intermediate resume checkpoint files
- Added `docs/tmp/**/*.log` to ignore build/run log files

### 11. Python compile checks

All key files compile cleanly:
- `micro/run_micro.py` ✓
- `micro/compare_results.py` ✓
- `micro/benchmark_catalog.py` ✓
- `micro/input_generators.py` ✓
- `e2e/run_e2e_tracee.py` ✓
- `corpus/policy_utils.py` ✓
- All Python files in micro/, corpus/, e2e/ — zero compile errors

### 12. Scanner build

```
[ 60%] Built target bpf_jit_scanner
[100%] Built target bpf-jit-scanner
```
OK.

### 13. docs/tmp/ non-md files

One `.log` file found: `docs/tmp/tracee-e2e-build42-run.log` — removed from git tracking, now covered by new `docs/tmp/**/*.log` gitignore rule.

Two `.resume.tmp.md` files removed from tracking, now covered by new `*.tmp.md` gitignore rule.

### 14. Broken symlinks

None found.

## Changes Made

| File | Change |
|------|--------|
| `.gitignore` | Added `tmp/`, `micro/policies/ablation/`, `*.tmp.md`, `docs/tmp/**/*.log` |
| `CLAUDE.md` | Fixed legacy dir path, macro_corpus.yaml location, updated benchmark count to 62, added ablation/ section |
| `Makefile` | Enhanced `verify-build` target with stale-build detection |
| `config/ablation/*.yaml` | Added 7 ablation suite configs to git (previously untracked) |
| `micro/results/per_form_ablation_20260313/ablation_wide.json` | Added missing ablation result |
| `micro/results/smoke_authoritative_20260313.json` | Updated from latest smoke run |
| `tmp/` (56 files) | Removed from git tracking (now gitignored) |
| `docs/tmp/tracee-e2e-build42-run.log` | Removed from git tracking |
| `docs/tmp/*/kernel-recompile*.resume.tmp.md` (2 files) | Removed from git tracking |

## Status: CLEAN

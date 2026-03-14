# Benchmark Framework Review (Post-Cleanup)

Date: 2026-03-13
Reviewer: Claude (sonnet-4-6)
Scope: Deep review of Makefile, POLICY= support, compare, provenance, naming, corpus/e2e gaps.

---

## 1. Summary Table

| Area | Status | Severity |
|------|--------|----------|
| `make help` output | ✅ Clear and complete | — |
| `make verify-build` | ✅ Works correctly | — |
| `make smoke` provenance | ✅ Present in output | — |
| Symlink / `.latest.json` pattern | ✅ Works correctly | — |
| `POLICY=` for `vm-micro` | ✅ Works | — |
| `POLICY=` for `smoke` | ⚠️ Silently ignored (expected, but confusing) | Low |
| `POLICY=` for `vm-micro-smoke` | BUG: not passed | Medium |
| `make compare` basic function | ✅ Works when files share runtimes | — |
| `make compare` on llvmbpf-only files | BUG: `cannot infer runtime pair` | Medium |
| `compare_results.py` regression exit code | BUG: always returns 0 | High |
| `compare_results.py` provenance display | ⚠️ Shows `kernel=?` for old files | Low |
| `config/policies/` directory structure | ✅ Three policies exist (default/all-apply/baseline) | — |
| `micro/policies/` vs `config/policies/default/` | ⚠️ Duplicate dirs, backup files present | Low |
| Result file naming consistency | ⚠️ Mixed ad-hoc names in micro/results/ | Low |
| Provenance in corpus/e2e results | MISSING | Medium |
| CI workflow (`x86-benchmark.yml`) | BUG: references missing `config/micro_runtime.yaml` | High |
| CI regression detection | MISSING | High |
| `docs/tmp/` cleanliness | ✅ No JSON/sh/py files (only .md) | — |
| Authoritative one-click flow | ✅ Documented in CLAUDE.md via `make vm-micro` | — |

---

## 2. Verified Working: What's Good

### 2.1 `make help`
Output is clear, well-structured, lists all targets and tunable parameters. Includes the `POLICY=` options. No issues.

### 2.2 `make verify-build`
```
Kernel:     7de19ef03
Scanner:    8f0e4e7
micro_exec: Mar 13 12:25
bzImage:    18M Mar 13 14:42
POLICY:     default (dir: /home/.../config/policies/default)
[verify-build] OK
```
Correct. Shows kernel commit, scanner commit, micro_exec timestamp, bzImage size, and current POLICY setting.

### 2.3 `make smoke` provenance
Running `make smoke` writes to `micro/results/smoke.latest.json` (symlink → `smoke_authoritative_20260313.json`). The JSON contains:
```json
{
  "provenance": {
    "kernel_commit": "7de19ef03692e843fc62d7a5d764d2e5e0c7c093",
    "scanner_commit": "6a040a774c9a382c66ea7afba7353222a9348b61",
    "policy_files_hash": "b9a171513ec76bfc",
    "policy_dir": "/home/.../micro/policies",
    "params": {"iterations": 1, "warmups": 0, "repeat": 10},
    "cpu_model": "Intel(R) Core(TM) Ultra 9 285K",
    "environment": "bare-metal",
    "timestamp": "2026-03-13T22:40:31.236557+00:00"
  }
}
```
Provenance is present and correct for new runs.

### 2.4 Symlink / `.latest.json` Pattern
`results_layout.py` correctly implements:
- Write to `<suite>_authoritative_YYYYMMDD.json`
- Create/update `<suite>.latest.json` symlink
- If output path ends in `.latest.json`, derive authoritative name from prefix

### 2.5 `config/policies/` Structure
Three correctly differentiated policy sets:
- `default/`: optimized policies (empty sites for CMOV/dense regressions)
- `all-apply/`: all sites applied (no filtering)
- `baseline/`: empty policy files (no recompilation)

### 2.6 `make compare` (when files share runtimes)
Works for files with `kernel` + `kernel-recompile` runtimes. Example:
```
Comparing results: kernel-recompile / kernel
load_byte_recompose  0.6842  0.6842  +0.0000
simple               1.0000  1.0000  +0.0000
GEOMEAN              0.8272  0.8272  +0.0000
```

### 2.7 `docs/tmp/` Cleanliness
No `.json`, `.sh`, or `.py` files in `docs/tmp/`. Only `.md` files and empty `vm-tmp/` dir. The Makefile comment "docs/tmp is for analysis reports (.md) only" is being respected.

---

## 3. Bugs Found

### 3.1 [HIGH] `compare_results.py` Always Returns Exit Code 0

**File:** `micro/compare_results.py`, line 187

The `compare()` function always returns `0` regardless of whether regressions were found. This means:
- `make compare OLD=... NEW=...` always exits with success
- No CI regression gate is possible with the current tool
- Regressions are only reported as human-readable text, not actionable exit code

**Fix:** Change `return 0` at line 187 to:
```python
return 1 if regressions else 0
```

### 3.2 [HIGH] CI Workflow References Non-Existent Config

**File:** `.github/workflows/x86-benchmark.yml` and `arm64-benchmark.yml`

Both workflows run:
```bash
python3 micro/run_micro.py ... --suite config/micro_runtime.yaml
```
But `config/micro_runtime.yaml` **does not exist** (only `config/micro_pure_jit.yaml` exists). This means the "runtime suite" steps will fail silently (they have `continue-on-error: true`).

Additionally, the CI workflows:
- Do not use `make` targets (bypasses POLICY= and other parameter handling)
- Do not run `compare` to detect regressions
- Do not include `vm-micro-smoke` (no kernel-recompile coverage in CI)
- The `venv` path is hardcoded at `/home/yunwei37/workspace/.venv` — won't work in CI

**Fix:** Either remove the runtime suite steps, or create `config/micro_runtime.yaml`. Update CI to use `make smoke` and `make compare`.

### 3.3 [MEDIUM] `POLICY=` Has No Effect on `make smoke`

**File:** `Makefile`, `smoke` target (lines 167-177)

The `smoke` target runs `--runtime llvmbpf` only. Policy is only relevant for `kernel-recompile` runtime. So `POLICY=` is silently ignored for smoke. This is architecturally correct but confusing:

```bash
make smoke POLICY=baseline  # Has NO effect on output
```

The provenance still records `policy_dir: .../micro/policies` (the default fallback), not `config/policies/baseline`. This means smoke provenance doesn't accurately reflect which policy was "requested."

**Fix option A (minimal):** Add a comment in the Makefile smoke target noting that POLICY= is not applicable.

**Fix option B (complete):** Pass `$(POLICY_DIR_FLAG)` to the smoke target too, so provenance accurately records which policy dir was intended.

### 3.4 [MEDIUM] `vm-micro-smoke` Does Not Pass `POLICY_DIR_FLAG`

**File:** `Makefile`, `vm-micro-smoke` target (lines 192-200)

The `vm-micro-smoke` runs `kernel-recompile` but does NOT pass `$(POLICY_DIR_FLAG)`:
```makefile
vm-micro-smoke: micro | $(BZIMAGE_PATH)
    $(VNG) ... python3 run_micro.py \
        --runtime kernel \
        --runtime kernel-recompile \
        $(VM_SMOKE_ARGS) \
        --output "$(VM_MICRO_SMOKE_OUTPUT)"  # No $(POLICY_DIR_FLAG)!
```

This means `make vm-micro-smoke POLICY=baseline` silently uses the default policy. Only `vm-micro` correctly passes `$(POLICY_DIR_FLAG)`.

Also: the resulting `vm_micro_smoke.latest.json` is **missing the `provenance` key** entirely. This appears to be because the vm-micro-smoke run used an older build of the Python code inside the VM (generated at 22:19 UTC, before the current session's smoke at 22:26 UTC added provenance). This is likely a __pycache__ staleness issue inside the VM guest.

**Fix:** Add `$(POLICY_DIR_FLAG)` to the `vm-micro-smoke` target. Force pyc cache refresh in VM invocation or use `python3 -B`.

### 3.5 [MEDIUM] `make compare` Fails on llvmbpf-Only Result Files

**File:** `micro/compare_results.py`, `_infer_comparison_pair()`

Running `make compare OLD=smoke_authoritative_20260313.json NEW=smoke.latest.json` produces:
```
ERROR: cannot infer runtime pair from result files.
```
because the smoke results only contain `llvmbpf` runtime (one runtime → can't form a ratio). The compare tool requires exactly 2 runtimes.

This means the user can't compare two consecutive smoke runs to detect compile-time or exec-time changes in llvmbpf.

**Fix:** Support single-runtime comparison (show absolute exec_ns instead of ratio) when only one runtime is present.

### 3.6 [MEDIUM] Corpus and E2E Results Have No Provenance

Neither `corpus/_driver_impl_run_corpus_v5_vm_batch.py` nor `e2e/run.py` embed a `provenance` block in their JSON output. The micro benchmark runner added provenance in commit `622ccce`, but corpus and e2e were not updated.

This means corpus and e2e results can't be tracked to specific kernel/scanner commits.

**Fix:** Add the same `collect_provenance()` call (or a shared version) to corpus and e2e output JSON.

---

## 4. Naming Inconsistencies

### 4.1 Mixed Naming in `micro/results/`

The directory contains 57 JSON files with inconsistent naming:
- Modern canonical: `smoke_authoritative_20260313.json`, `vm_micro_smoke_authoritative_20260313.json`
- Legacy ad-hoc: `kernel_recompile_v2_tuned_20260312.json`, `dense6_round11_build40.json`, `post_fix_micro_62bench_smoke.json`
- No `.latest.json` symlinks for legacy files

**Impact:** Low (legacy files, historical data). No action needed unless we want to clean up.

### 4.2 `micro/policies/` vs `config/policies/default/`

`micro/policies/` is the default policy directory used at runtime. `config/policies/default/` is the named policy set exposed by the Makefile. They are **identical files** (diff shows no differences for the YAML files themselves).

However, `micro/policies/` has extra files not in `config/policies/default/`:
- `cond_select_dense.yaml.orig`, `cond_select_dense.yaml.full_original`
- `endian_swap_dense.yaml.orig`, `endian_swap_dense.yaml.full_original`
- `extract_dense.yaml.orig`, `extract_dense.yaml.full_original`
- `ablation/` subdirectory
- `per_family/` subdirectory

The `.orig` and `.full_original` backup files are stale artifacts from policy editing sessions and should be cleaned up.

**Fix:** Delete `micro/policies/*.orig` and `micro/policies/*.full_original`. Document that `micro/policies/` is the canonical runtime policy dir and `config/policies/` is for named overrides.

### 4.3 Provenance `policy_dir` Points to `micro/policies` Not `config/policies/default`

When running `make smoke` or `make vm-micro` without `--policy-dir`, `run_micro.py` uses `micro/policies` as the fallback. So provenance records `micro/policies` even for what conceptually is the "default" policy. This is technically correct but could confuse readers of the provenance data who expect `config/policies/default`.

---

## 5. Missing Features

### 5.1 No CI Regression Gate

There is no automated regression detection in the CI workflows or the Makefile. `compare_results.py` always exits 0. Regressions are flagged visually but not actionably.

**Suggested flow:**
```bash
make vm-micro-smoke  # run
make compare OLD=micro/results/vm_micro_smoke_authoritative_<prev>.json \
             NEW=micro/results/vm_micro_smoke.latest.json
```
and exit non-zero on regression.

### 5.2 No Authoritative One-Click Script

While `make vm-micro` is the canonical full run, there's no documented flow for:
1. Full authoritative run (vm-micro + corpus + e2e)
2. Comparing result to previous authoritative baseline

**Suggested addition to Makefile:**
```makefile
authoritative: vm-micro vm-corpus vm-e2e
    @echo "=== Authoritative run complete ==="
    @echo "Results: $(VM_MICRO_OUTPUT), $(VM_CORPUS_OUTPUT_JSON), $(VM_TRACEE_OUTPUT_JSON)"
```

### 5.3 `vm_micro_smoke.latest.json` Missing Provenance

See bug 3.4. The existing `vm_micro_smoke.latest.json` (generated 2026-03-13T22:19) has no `provenance` key. Future runs via `make vm-micro-smoke` should produce provenance once the `$(POLICY_DIR_FLAG)` fix is applied and the VM uses fresh Python bytecode.

---

## 6. Recommended Fixes (Prioritized)

| Priority | Fix | Effort |
|----------|-----|--------|
| P0 | `compare_results.py`: return exit code 1 on regressions (line 187) | 1 line |
| P0 | CI: remove `--suite config/micro_runtime.yaml` step (file doesn't exist) | 2 lines |
| P1 | `vm-micro-smoke`: add `$(POLICY_DIR_FLAG)` | 1 line |
| P1 | Corpus and e2e: add provenance to JSON output | ~20 lines each |
| P2 | `micro/policies/`: delete `.orig` and `.full_original` backup files | trivial |
| P2 | `compare_results.py`: support single-runtime absolute comparison | ~30 lines |
| P3 | Add `authoritative` make target for full combined run | ~5 lines |
| P3 | Document that `POLICY=` has no effect on `smoke` target (comment in Makefile) | 1 line |

---

## 7. Verification Commands Used

```bash
make help
make verify-build
make smoke          # + check smoke.latest.json provenance
make compare OLD=... NEW=...  # tested multiple file pairs
python3 micro/compare_results.py smoke.latest.json smoke.latest.json  # exit code check
ls config/policies/{default,all-apply,baseline}/
diff -r micro/policies/ config/policies/default/
ls micro/results/*.json | wc -l  # 57 files
ls docs/tmp/*.json docs/tmp/*.sh docs/tmp/*.py  # clean
python3 -c "... json.load provenance check ..."
```

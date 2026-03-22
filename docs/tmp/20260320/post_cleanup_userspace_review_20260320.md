# Post-cleanup Userspace Review (2026-03-20)

## Scope

- Review target: today's userspace changes since `751df131977062f1082b1d490b963d29c61c0b7e` plus current working tree state
- Reviewed areas: `micro/`, `corpus/`, `e2e/`, `runner/`, top-level `Makefile`, `.github/workflows/`
- Constraint followed: review only; no source fixes applied

## Verdict

Current userspace cleanup is **partially aligned** with `docs/kernel-jit-optimization-plan.md` §5.6.

- **Pass**: cross-layer imports between `micro/`, `corpus/`, `e2e/` are clean
- **Pass**: top-level `Makefile` paths were updated consistently after directory moves, and `make smoke` passes on the current worktree
- **Pass**: same-image paired measurement is implemented in runner and consumed by corpus
- **Pass with caveat**: profiler/policy shared logic is placed under `runner/libs/` and generic CLIs under `runner/scripts/`
- **Fail**: `runner/libs/` still has a reverse dependency on `micro/`
- **Fail**: one broken import was introduced in `corpus/auto_tune.py`
- **Fail**: ARM64 CI path update is incomplete; the workflow still calls a removed `micro/driver.py corpus ...` entrypoint
- **Drift**: "Makefile is the only entrypoint" is not consistently reflected in CI and READMEs

## Findings

### 1. ARM64 CI still calls a removed corpus entrypoint through `micro/driver.py`

Severity: High

`micro/driver.py` now explicitly rejects the old `corpus` subcommand and tells callers to use `corpus/driver.py` instead, but the ARM64 workflow still runs:

- `.github/workflows/arm64-benchmark.yml:176`
- `.github/workflows/arm64-benchmark.yml:195`
- `micro/driver.py:70`
- `micro/driver.py:83`

Observed repro:

```bash
python3 micro/driver.py corpus code-size
```

Observed result:

```text
micro/driver.py only supports suite runs; use corpus/driver.py for corpus workflows
```

Impact:

- ARM64 baseline workflow is not fully updated after the driver split
- CI no longer matches the actual supported entrypoints
- This violates the "Makefile / canonical entrypoint" cleanup objective and leaves CI broken for corpus steps

### 2. `corpus/auto_tune.py` has a real broken import after consolidation

Severity: High

`corpus/auto_tune.py` imports `relpath` from `corpus.modes`, but `corpus.modes` does not define it.

- `corpus/auto_tune.py:39`
- `corpus/auto_tune.py:50`
- `corpus/modes.py`

Observed repro:

```bash
python3 corpus/auto_tune.py --help
```

Observed result:

```text
ImportError: cannot import name 'relpath' from 'corpus.modes'
```

Impact:

- `py_compile` stays green, so this would slip through syntax-only validation
- the auto-tuning tool is currently unusable
- this is the only real broken import found in `micro/` + `corpus/` + `e2e/` + `runner/`

### 3. `runner/libs/` still has a reverse dependency on `micro/`

Severity: Medium

`runner/libs/benchmarks.py` imports `micro.benchmark_catalog` and `micro.input_generators` as fallback paths:

- `runner/libs/benchmarks.py:6`
- `runner/libs/benchmarks.py:10`

This violates the intended dependency direction:

- `runner/` should be shared foundation
- `micro/` may depend on `runner/`
- `runner/libs/` should not depend back on `micro/`

Impact:

- shared runner library is no longer layer-neutral
- reuse of `runner/libs` is coupled to micro-specific catalog/input machinery
- design principle 3 is violated at the library boundary even though top-level cross-import grep is otherwise clean

### 4. "Makefile is the only entrypoint" is still not true in CI/docs

Severity: Medium

The top-level `Makefile` is in good shape, but CI and READMEs still present direct Python/script entrypoints as canonical:

- `.github/workflows/x86-benchmark.yml:40`
- `.github/workflows/arm64-benchmark.yml:121`
- `micro/README.md:13`
- `micro/README.md:40`
- `corpus/README.md:21`
- `e2e/README.md:3`
- `docs/kernel-jit-optimization-plan.md:423`

Specific drift:

- x86 CI still runs `python3 micro/driver.py suite ...` directly instead of `make` targets
- ARM64 CI directly runs Python drivers and also hits the removed corpus path
- `micro/README.md` still points users to `./docs/paper/scripts/run_micro.sh`, even though that wrapper is already documented as deprecated
- `corpus/README.md` and `e2e/README.md` still describe direct Python entrypoints as canonical

Impact:

- principle 2 is only partially enforced in code
- operator-facing docs and CI behavior are inconsistent with §5.6

## Detailed Review Against Requested Checks

### 1. Cross-layer dependencies

Static grep results:

```bash
rg -n "from micro|import micro" corpus e2e
rg -n "from corpus|import corpus" micro e2e
rg -n "from e2e|import e2e" micro corpus
```

Result:

- No matches in any of the three forbidden directions

Conclusion:

- `micro/`, `corpus/`, and `e2e/` do not directly depend on each other
- requested layer split is preserved at the direct import level

### 2. `runner/libs/` dependency direction

Static grep:

```bash
rg -n "from (micro|corpus|e2e)|import (micro|corpus|e2e)" runner
```

Matches:

- `runner/libs/benchmarks.py:10`
- `runner/libs/benchmarks.py:11`
- `runner/scripts/collect_e2e_profile.py:21`
- `runner/scripts/collect_e2e_profile.py:38`
- `runner/scripts/collect_e2e_profile.py:59`
- `runner/scripts/arm64_t4g_remote_benchmark.py:22`

Conclusion:

- **`runner/libs/` is not clean** because `runner/libs/benchmarks.py` depends on `micro`
- `runner/scripts/collect_e2e_profile.py` importing `e2e.cases.*` is acceptable as an E2E-specific script, but this is exactly why it belongs in `runner/scripts`, not `runner/libs`
- `runner/scripts/arm64_t4g_remote_benchmark.py` is micro-specific operational tooling; it does not pollute `runner/libs`, but it does make `runner/scripts/` a mixed utility bucket

### 3. Makefile consistency after path moves

Inspected:

- `Makefile:20`
- `Makefile:23`
- `Makefile:30`
- `Makefile:351`
- `Makefile:383`
- `Makefile:398`
- `Makefile:513`

What is correct:

- ARM64 smoke script path updated to `runner/scripts/arm64_qemu_smoke.py`
- ARM64 Dockerfile path updated to `runner/docker/arm64-crossbuild.Dockerfile`
- AWS ARM64 script path updated to `runner/scripts/aws_arm64.sh`
- `make runner` builds from `runner/`
- `vm-micro` calls `micro/driver.py`
- `vm-corpus` calls `corpus/driver.py`
- `vm-e2e` calls `e2e/run.py`

Observed validation:

```bash
make smoke
```

Result:

- PASS on current working tree

Conclusion:

- top-level `Makefile` itself is consistent with the new directory layout
- I did not find stale moved-path references in source Makefiles/workflows other than the broken `micro/driver.py corpus ...` CI call described above

### 4. Profiler / policy tool placement

Inspected:

- `runner/libs/profiler.py`
- `runner/scripts/bpf_profiler.py`
- `runner/scripts/profile_guided_policy.py`
- `runner/scripts/collect_e2e_profile.py`
- `runner/libs/recompile.py`
- `runner/libs/policy.py`

Conclusion:

- `runner/libs/profiler.py` is correctly placed as shared profiling logic
- `runner/scripts/bpf_profiler.py` is correctly placed as a generic CLI on top of shared runner libs
- `runner/scripts/profile_guided_policy.py` is correctly placed as a generic CLI policy generator
- `runner/libs/recompile.py` and `runner/libs/policy.py` are the right place for shared live-enumerate / policy-remap logic
- `runner/scripts/collect_e2e_profile.py` is E2E-specific orchestration, but it is still acceptable under `runner/scripts`; the important thing is that its case-specific logic did **not** move into `runner/libs`

Net:

- placement is mostly correct
- the real layering problem is `runner/libs/benchmarks.py`, not the new profiler/policy tools

### 5. Python imports / broken import audit

Commands run:

```bash
python3 -m py_compile <all .py files>
python3 corpus/auto_tune.py --help
python3 -c 'import ...'  # import smoke across micro/corpus/e2e/runner modules
```

Results:

- `py_compile`: PASS for 1132 Python files
- vendor-only SyntaxWarnings seen in three vendored comedi helper scripts; no compile failures
- import smoke: only one real failure, `corpus.auto_tune`
- `corpus/auto_tune.py --help`: FAIL due to missing `relpath`

Conclusion:

- there is **one confirmed broken import** in active userspace code
- otherwise import paths are working for the reviewed layers

### 6. Dead code after `driver_impl` merge

Source-only search:

```bash
rg -n "_driver_impl_|run_rigorous|run_micro.py|run_rigorous.py|run_rigorous_framework_vm.py|run_e2e_tracee" \
  micro corpus e2e runner Makefile .github/workflows README.md REVIEW.md docs \
  --glob '!**/results/**' --glob '!docs/tmp/**'
```

Conclusion:

- no active source files still import or execute `_driver_impl_*`
- remaining references are in docs/history only
- I do **not** see active dead-code residue from the micro driver merge in the current source tree

### 7. CI workflow path updates

Path updates that are correct:

- `.github/workflows/arm64-benchmark.yml:14` now uses `runner/build/vendor/bpftool/bpftool`
- `.github/workflows/arm64-benchmark.yml:127` uses `micro/config/micro_pure_jit.yaml`
- `.github/workflows/x86-benchmark.yml:46` uses `micro/config/micro_pure_jit.yaml`
- ARM64 build step switched from `make -C micro ...` to `make micro` / `make scanner` / `make -C runner vendor_bpftool`

What is still broken:

- `.github/workflows/arm64-benchmark.yml:176`
- `.github/workflows/arm64-benchmark.yml:195`

These still call `python3 micro/driver.py corpus ...`, which no longer exists as a supported path.

Conclusion:

- workflow path migration is **incomplete**
- some paths were updated correctly, but the ARM64 corpus steps are still functionally stale

## Design Principle Check

### 1. Runner only measures

Status: PASS

Evidence:

- `runner/src/kernel_runner.cpp` still owns the measurement loop
- measurement JSON carries `phase` records and timing data
- orchestration, workload setup, target discovery, and reporting remain in Python layers

### 2. Makefile is the only entrypoint

Status: FAIL / DRIFT

Evidence:

- top-level `Makefile` is the right entrypoint
- but workflows and READMEs still use direct Python entrypoints and one deprecated wrapper script

### 3. Dependency direction

Status: PARTIAL FAIL

Evidence:

- `micro/` / `corpus/` / `e2e/` do not directly depend on one another
- but `runner/libs/benchmarks.py` depends on `micro`

### 4. Same-image paired measurement

Status: PASS

Evidence:

- `runner/src/kernel_runner.cpp:1559` starts a stock pass before recompile
- `runner/src/kernel_runner.cpp:1586` applies recompile after the stock measurement
- `corpus/modes.py:345` extracts `phase == "stock"` samples from a single runner invocation

### 5. Three-layer evaluation model

Status: MOSTLY PASS

Evidence:

- `vm-micro` uses `micro/driver.py`
- `vm-corpus` uses `corpus/driver.py`
- `vm-e2e` uses `e2e/run.py`
- layer boundaries are mostly preserved
- caveat: docs/CI still describe or invoke old cross-entrypoint paths

## Validation Log

Commands run:

```bash
rg -n "from micro|import micro" corpus e2e
rg -n "from corpus|import corpus" micro e2e
rg -n "from e2e|import e2e" micro corpus
rg -n "from (micro|corpus|e2e)|import (micro|corpus|e2e)" runner

source /home/yunwei37/workspace/.venv/bin/activate
python3 -m py_compile <all .py files>
python3 corpus/auto_tune.py --help
python3 micro/driver.py corpus code-size
make smoke
```

Observed results:

- forbidden cross-layer imports: PASS
- `runner/libs` reverse dependency check: FAIL (`runner/libs/benchmarks.py`)
- `py_compile`: PASS
- `corpus/auto_tune.py --help`: FAIL
- `python3 micro/driver.py corpus code-size`: FAIL as expected; confirms ARM64 workflow stale call
- `make smoke`: PASS on current working tree

## Bottom Line

Today's cleanup succeeded on the big structural moves:

- legacy removal is clean
- micro/corpus/e2e direct layering is intact
- Makefile paths are mostly correct
- same-image paired measurement is correctly wired
- new profiler/policy shared code is placed in the right general area

But there are still three blocking review items before I would call the userspace cleanup fully aligned with the design principles:

1. fix the broken `corpus.auto_tune` import
2. remove the `runner/libs -> micro` reverse dependency in `runner/libs/benchmarks.py`
3. update ARM64 CI away from `python3 micro/driver.py corpus ...`, and ideally align CI/docs with the documented `make vm-*` entrypoint rule

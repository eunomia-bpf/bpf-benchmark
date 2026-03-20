# Benchmark Framework Refactor

Date: 2026-03-20

## Status

The benchmark framework refactor is now live in the working tree.

At the start of this turn, the repo was already in a partially migrated state:

- `runner/` already existed and contained the moved C++ runner plus shared Python libs.
- `micro/runner/` and `micro/orchestrator/` were already absent from the filesystem.
- the worktree already showed the corpus driver consolidation in progress (`corpus/driver.py`, `corpus/modes.py`, deleted `_driver_impl_*.py` files).

This turn completed the remaining path/build fixes, verified that the moved layout works, and updated repo-facing docs/scripts to the new top-level `runner/` location.

## Filesystem Layout Verified

- `runner/` contains:
  - `runner/src/*.cpp`
  - `runner/include/micro_exec.hpp`
  - `runner/CMakeLists.txt`
  - `runner/Makefile`
  - `runner/libs/*.py`
- old locations removed:
  - `micro/runner/`
  - `micro/orchestrator/`

Verification command:

```bash
test ! -d micro/runner && test ! -d micro/orchestrator && echo OLD_LOCATIONS_REMOVED
```

Result:

```text
OLD_LOCATIONS_REMOVED
```

## Changes Completed In This Turn

### 1. Python entrypoints now resolve the moved runner binary

Updated defaults from `micro/build/runner/micro_exec` to `runner/build/micro_exec` in:

- `corpus/generate_default_policies.py`
- `corpus/run_code_size_comparison.py`
- `e2e/run.py`
- `e2e/run_e2e_tracee.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/katran/case.py`

### 2. E2E build hooks now use the top-level runner target

Replaced stale `make -C micro micro_exec ...` calls with the refactored top-level build target:

- `make runner`

This was applied in:

- `e2e/cases/bpftrace/case.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/katran/case.py`

### 3. Maintained docs/scripts updated to match the new structure

Updated:

- `micro/README.md`
- `e2e/README.md`
- `CLAUDE.md`
- `scripts/aws_arm64.sh`

The AWS ARM64 helper now stages and invokes the runner from `runner/build/micro_exec` inside the remote bundle instead of the retired `micro/build/runner/micro_exec` path.

## Recompile Output Check

The moved runner already contained the phase-split recompile output path in `runner/src/kernel_runner.cpp`. I verified the runtime behavior directly.

Command run:

```bash
sudo -n ./runner/build/micro_exec run-kernel \
  --program micro/programs/load_byte_recompose.bpf.o \
  --memory micro/generated-inputs/load_byte_recompose.mem \
  --policy-file micro/policies/load_byte_recompose.yaml \
  --io-mode staged \
  --input-size 1032 \
  --repeat 1 | tail -2
```

Observed result:

- line 1 included `"phase":"stock"`
- line 2 included `"phase":"recompile"`
- no `stock_exec_ns` field was present

This confirms the moved runner emits the required two-line JSON phase stream for recompile-mode kernel runs.

## Verification

Environment activated:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
```

Requested checks:

```bash
python3 -m py_compile runner/libs/commands.py
python3 -m py_compile micro/driver.py
make smoke 2>&1 | tail -5
```

Results:

- `python3 -m py_compile runner/libs/commands.py`: passed
- `python3 -m py_compile micro/driver.py`: passed
- extra sanity compile on changed entrypoints also passed:
  - `corpus/generate_default_policies.py`
  - `corpus/run_code_size_comparison.py`
  - `e2e/run.py`
  - `e2e/run_e2e_tracee.py`
  - `e2e/cases/bpftrace/case.py`
  - `e2e/cases/tracee/case.py`
  - `e2e/cases/tetragon/case.py`
  - `e2e/cases/katran/case.py`

`make smoke` tail output:

```text
[WARN] No CPU affinity set. Consider using --cpu for isolated measurements.
[bench] simple
  llvmbpf    compile median 4.283 ms | exec median 44 ns | result 12345678
[done] wrote /home/yunwei37/workspace/bpf-benchmark/micro/results/dev/smoke.json
SMOKE OK: simple llvmbpf exec 44 ns, compile 4.283 ms, result 12345678
```

## Notes

- The worktree remains dirty with broader refactor changes outside this turn; this report covers the execution and verification work completed in this turn.
- The moved `runner/` tree is present and buildable, old runner/orchestrator locations are absent, and the top-level smoke path now runs successfully through `runner/build/micro_exec`.

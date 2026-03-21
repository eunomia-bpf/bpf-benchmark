# Directory Reorganization Report (2026-03-20)

## Scope

Plan #303 reorganized top-level directories into the current layered layout:

- `docker/` -> `runner/docker/`
- `scripts/` -> `runner/scripts/`
- `reference/` -> `docs/reference/`
- `config/` inspection and cleanup

Constraint followed: no changes were made under `vendor/linux-framework/`.

## Moves Performed

### 1. `docker/` -> `runner/docker/`

- Moved the ARM64 cross-build Dockerfile to `runner/docker/arm64-crossbuild.Dockerfile`.
- Updated Makefile references to use `runner/docker/...`.
- Preserved an existing local Dockerfile change (`kernel6.18-libbpf-devel`) when cleaning up the old directory.

### 2. `scripts/` -> `runner/scripts/`

- Moved the root runner/helper scripts to `runner/scripts/`:
  - `arm64_qemu_smoke.py`
  - `aws_arm64.sh`
  - `bpf_profiler.py`
  - `collect_e2e_profile.py`
  - `collect_e2e_profile.sh`
  - `profile_guided_policy.py`
- Updated Makefile references to `runner/scripts/...`.
- Updated script-internal repo-root detection for moved shell/Python scripts.
- Updated documentation and tests that referenced the old `scripts/` paths.
- Preserved existing local `aws_arm64.sh` behavior before deleting the old top-level copy:
  - tagged-instance listing / cleanup checks
  - `ARM64_CROSSBUILD_OUTPUT_DIR` defaulting to `.cache/aws-arm64/binaries`

### 3. `reference/` -> `docs/reference/`

- Moved the paper archive to `docs/reference/papers/`.
- Updated `.gitignore` and manifest file paths to the new location.

### 4. `config/` inspection

- Before removal, `config/` contained only `micro_pure_jit.yaml`.
- The only active code consumers were micro-layer loaders / workflows.
- Decision: move it to `micro/config/micro_pure_jit.yaml`.
- Result: the top-level `config/` directory was removed.

## Reference Updates

Updated references in:

- `Makefile`
- `.github/workflows/arm64-benchmark.yml`
- `.github/workflows/x86-benchmark.yml`
- `CLAUDE.md`
- `README.md`
- `REVIEW.md`
- `corpus/README.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/micro-bench-status.md`
- `micro/README.md`
- `micro/benchmark_catalog.py`
- `runner/libs/catalog.py`
- `runner/scripts/aws_arm64.sh`
- `runner/scripts/bpf_profiler.py`
- `runner/scripts/collect_e2e_profile.py`
- `runner/scripts/collect_e2e_profile.sh`
- `runner/scripts/profile_guided_policy.py`
- `tests/test_profile_guided_policy.py`
- `docs/reference/papers/manifest.json`
- `docs/reference/papers/manifest.csv`

## Verification

Environment:

- `source /home/yunwei37/workspace/.venv/bin/activate`

Checks run:

```bash
make smoke
make scanner-tests
python3 -m py_compile \
  micro/benchmark_catalog.py \
  runner/libs/catalog.py \
  runner/scripts/arm64_qemu_smoke.py \
  runner/scripts/bpf_profiler.py \
  runner/scripts/collect_e2e_profile.py \
  runner/scripts/profile_guided_policy.py \
  tests/test_profile_guided_policy.py
```

Results:

- `make smoke`: passed
- `make scanner-tests`: passed
- `py_compile`: passed for all modified/moved Python files above

Residual old-path check:

- Searched for old root-level paths with `rg`, excluding `vendor/**`, `docs/tmp/**`, `micro/results/**`, `e2e/results/**`, `corpus/results/**`, and `**/__pycache__/**`.
- After updating the plan doc entry, no active repository references remained for:
  - root `docker/arm64-crossbuild.Dockerfile`
  - root `scripts/aws_arm64.sh`
  - root `scripts/arm64_qemu_smoke.py`
  - root `scripts/{bpf_profiler.py,collect_e2e_profile.py,collect_e2e_profile.sh,profile_guided_policy.py}`
  - root `config/micro_pure_jit.yaml`
  - root `config/{macro_corpus.yaml,corpus_manifest.yaml}`
  - root `reference/`

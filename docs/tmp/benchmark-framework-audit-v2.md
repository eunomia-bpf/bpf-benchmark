# Benchmark Framework Audit v2

Date: 2026-03-11

Scope: benchmark framework only. No benchmark program logic or kernel code was modified.

## Executive Summary

- `make -C micro` succeeded on this host and built the micro-layer artifacts in one step.
- Micro smoke tests passed for both `llvmbpf` and `kernel`.
- `sudo -n` is available on this host, so kernel-runtime smoke testing was possible.
- `micro/driver.py`, `e2e/run.py`, and `corpus/build_expanded_corpus.py` all start correctly.
- One framework bug was found and fixed: `e2e/cases/tracee/case.py` had a brittle post-restructure import path.
- Documentation was partially stale. I updated `README.md`, `CLAUDE.md`, `micro/README.md`, `corpus/README.md`, and `e2e/README.md`.
- `make -C micro` is enough for the micro layer, but it does not produce `scanner/build/bpf-jit-scanner`. The standalone scanner CLI is still a separate CMake build artifact used by `corpus/` recompile paths and `e2e/`.

## 1. Current Framework State

### micro/

- `micro/run_micro.py` is still the main isolated-suite runner.
- `micro/driver.py` is the unified Python entrypoint for `suite`, `rigorous`, `ablation`, `census`, and `corpus`.
- `micro/Makefile` builds three things via `make -C micro`: BPF program objects, `micro_exec`, and `micro/build/tools/directive_hint`.
- The default suite is no longer the old 22-case staged-only set. Current repo state is:
  - `config/micro_pure_jit.yaml`: 56 benchmarks total
  - `config/micro_runtime.yaml`: 11 benchmarks total
- `run_micro.py` always re-invokes incremental `make -C micro micro_exec` and `make -C micro programs` before running.

### corpus/

- `corpus/` owns fetch/build/measure tooling for the real-world program layer.
- `corpus/build_expanded_corpus.py` is the main object-builder for `corpus/build/<repo>/`.
- Those built objects are also the artifacts consumed by `e2e` for `tracee`, `tetragon`, and `scx`.

### e2e/

- `e2e/run.py` is the current unified entrypoint for `tracee`, `tetragon`, `bpftrace`, and `scx`.
- Per-case logic now lives under `e2e/cases/`.
- Each case expects `scanner/build/bpf-jit-scanner`, not the scanner static library that is embedded inside the `micro_exec` build tree.
- VM mode is wired in `e2e/run.py` for `tracee` and `scx`; it is intentionally rejected for `tetragon` and `bpftrace`.

## 2. Build Results

| Command | Result | Output Summary |
| --- | --- | --- |
| `source /home/yunwei37/workspace/.venv/bin/activate && make -C micro` | Success | `micro/programs` was already up to date; CMake configured and built `micro/build/runner/micro_exec`; `micro/build/tools/directive_hint` linked successfully. |
| `make -C micro` one-click build check | Success | Current `micro/Makefile` is sufficient for the micro layer. |
| Scanner CLI expectation check | Separate step required | `e2e` and corpus recompile flows use `scanner/build/bpf-jit-scanner`; this path is not produced by `make -C micro`. Existing case code auto-builds it when missing via `cmake -S scanner -B scanner/build ...`. |

Notes:

- `make -C micro` did build the scanner static library used by the runner build graph, but not the standalone CLI under `scanner/build/`.
- The workspace already contained `scanner/build/bpf-jit-scanner`; code inspection confirmed that this is still a separate CMake build product.

## 3. Smoke Test Results

| Command | Result | Key Output |
| --- | --- | --- |
| `python3 micro/run_micro.py --list` | Success | Listed 56 default-suite benchmarks and 2 runtimes (`llvmbpf`, `kernel`). |
| `python3 micro/run_micro.py --bench simple --runtime llvmbpf --iterations 1 --warmups 0 --repeat 10` | Success | `compile median 6.772 ms`, `exec median 167 ns`, `result 12345678`. |
| `sudo -n true` | Success | Passwordless sudo is available. |
| `python3 micro/run_micro.py --bench simple --runtime kernel --iterations 1 --warmups 0 --repeat 10` | Success | `compile median 552.330 us`, `exec median 107 ns`, `result 12345678`. |
| `python3 micro/driver.py --help` | Success | Unified driver exposes `suite`, `rigorous`, `ablation`, `census`, `corpus`. |
| `python3 micro/driver.py suite -- --list` | Success | Correctly routed through the unified driver into the default micro suite listing. |
| `python3 e2e/run.py --help` | Success | Unified e2e entrypoint starts correctly and shows the expected case/VM options. |
| `python3 corpus/build_expanded_corpus.py --help` | Success | Corpus build entrypoint starts correctly. |

Warnings observed during micro smoke tests:

- `perf_event_paranoid=2`: some perf counters may be unavailable.
- No CPU affinity was set, so the runner warns that measurements are not publication-grade.

## 4. Documentation Audit

### CLAUDE.md

Status before fix: partially accurate, but stale.

Accurate:

- `make -C micro` build instructions matched current code.
- `make -C micro micro_exec`, `make -C micro programs`, and `make -C micro vendor_bpftool` matched current targets.
- The run examples for `micro/run_micro.py` still matched current CLI behavior.

Outdated or missing:

- It still described `micro_pure_jit.yaml` as a 22-case staged-only suite.
- It described `micro_runtime.yaml` too narrowly as map-only.
- It did not mention that `corpus/` and `e2e/` recompile flows expect the standalone scanner CLI under `scanner/build/`.

Action taken:

- Updated suite counts and suite composition.
- Added the standalone scanner CLI build step to the build section.

### micro/README.md

Status before fix: usable, but incomplete.

Accurate:

- Correctly stated that `micro/` now owns only the isolated benchmark layer.
- Build commands and main entrypoints were correct.

Missing:

- No current benchmark counts.
- No explicit explanation of the current pure-jit vs runtime suite boundary.
- No note that `run_micro.py` auto-runs incremental build steps before execution.

Action taken:

- Added current suite counts.
- Added a dedicated pure-jit vs runtime semantics section.
- Added the incremental-build note.

### corpus/README.md

Status before fix: mostly accurate.

Accurate:

- Script inventory and common commands matched current code.
- The 23-project corpus description matched the current README state.

Missing:

- It did not explicitly say that `corpus/build/<repo>/` is the object root consumed by `e2e`.

Action taken:

- Added a short note linking `corpus/build/` to `e2e` consumers.

### e2e/README.md

Status before fix: stale and incomplete.

Problems:

- It still described the layer as a transitional move with planned layout.
- It mentioned only legacy `run_e2e_*.py` scripts and did not document `e2e/run.py`.
- It did not explain shared prerequisites, scanner CLI expectations, per-agent setup, object paths, or VM support.

Action taken:

- Rewrote the README around the current `e2e/run.py` entrypoint.
- Added shared prerequisites.
- Documented Tracee, Tetragon, bpftrace, and scx setup/asset expectations.

### Root README.md

Status before fix: helpful but not sufficient as a full quickstart.

Missing:

- No end-to-end sequence from fresh setup through micro/corpus/e2e.
- No mention of the separate scanner CLI build.
- No concrete path to prepare corpus objects consumed by e2e.

Action taken:

- Expanded the quickstart with micro build/smoke, scanner CLI build, corpus object build, and e2e smoke commands.

## 5. Issues Found and Fix Status

1. Tracee case import path was brittle after the repo restructure.
   - Symptom: `import e2e.cases.tracee.case` failed from repo-root Python with `ModuleNotFoundError: No module named 'run_e2e_tracee'`.
   - Cause: the fallback import relied on `e2e/` being on `sys.path` as a script directory, which is true for `python3 e2e/run.py` but not for normal module import.
   - Fix: changed the import path to prefer `e2e.run_e2e_tracee` and fall back to `ROOT_DIR / "e2e"` only when needed.
   - Status: fixed and verified.

2. Suite counts and composition were stale in `CLAUDE.md`.
   - Status: fixed.

3. `micro/README.md` did not explain the current pure-jit vs runtime split clearly enough.
   - Status: fixed.

4. `e2e/README.md` did not describe current case setup or `e2e/run.py`.
   - Status: fixed.

5. Scanner CLI build expectations were undocumented at the repo quickstart level.
   - Status: fixed in docs.

6. `corpus/README.md` did not mention that its build outputs feed `e2e`.
   - Status: fixed.

## 6. From-Zero Command Sequence

This is the shortest complete path I would hand to someone who wants to bring the framework up and verify all three layers.

```bash
cd /home/yunwei37/workspace/bpf-benchmark

git submodule update --init --recursive
source /home/yunwei37/workspace/.venv/bin/activate

# 1. Build the micro layer
make -C micro

# 2. Verify the isolated suite
python3 micro/run_micro.py --list
python3 micro/run_micro.py --bench simple --runtime llvmbpf --iterations 1 --warmups 0 --repeat 10
python3 micro/run_micro.py --bench simple --runtime kernel --iterations 1 --warmups 0 --repeat 10

# 3. Verify the unified entrypoints
python3 micro/driver.py --help
python3 micro/driver.py suite -- --list
python3 corpus/build_expanded_corpus.py --help
python3 e2e/run.py --help

# 4. Build the standalone scanner CLI used by corpus/e2e recompile paths
cmake -S scanner -B scanner/build -DCMAKE_BUILD_TYPE=Release
cmake --build scanner/build --target bpf-jit-scanner -j

# 5. Build the corpus objects consumed by e2e
python3 corpus/build_expanded_corpus.py --repo tracee --repo tetragon --repo scx

# 6. Run the main micro suites
python3 micro/driver.py suite -- --runtime llvmbpf --runtime kernel
python3 micro/driver.py suite -- --suite config/micro_runtime.yaml --runtime llvmbpf --runtime kernel

# 7. Corpus-layer entrypoints
python3 corpus/directive_census.py
python3 corpus/run_macro_corpus.py --list

# 8. End-to-end smoke runs
python3 e2e/run.py tracee --smoke
python3 e2e/run.py tetragon --smoke
python3 e2e/run.py bpftrace --smoke
python3 e2e/run.py scx --smoke
```

Operational notes:

- The kernel micro runtime and most `e2e` cases require root or passwordless `sudo -n`.
- `tracee` and `tetragon` case setup is done by their case-specific setup scripts.
- `bpftrace` expects `bpftrace >= 0.16` and `bpftool` in `PATH`.
- `scx` expects one of `hackbench`, `stress-ng`, or `sysbench`, and will build `scx_rusty` if needed.

## 7. Improvements Recommended

1. Add a top-level smoke target.
   - Example: `make smoke-framework` or `scripts/smoke_framework.sh`
   - That would codify the exact audit path I ran here.

2. Add a top-level scanner build target.
   - Example: `make scanner_cli`
   - Right now the split between `make -C micro` and `cmake -S scanner -B scanner/build ...` is easy to miss.

3. Add CI checks for entrypoint imports and `--help`.
   - Minimal checks:
     - `python3 -c "import e2e.cases.tracee.case"`
     - `python3 micro/driver.py --help`
     - `python3 e2e/run.py --help`
     - `python3 corpus/build_expanded_corpus.py --help`

4. Auto-generate benchmark inventory snippets in docs from YAML.
   - The stale 22-case text in `CLAUDE.md` is exactly the kind of drift that scripted doc generation would prevent.

5. Consider a single “framework prerequisites” doc or script.
   - Today the required setup is spread across root README, `micro/README.md`, `e2e/README.md`, and case setup scripts.

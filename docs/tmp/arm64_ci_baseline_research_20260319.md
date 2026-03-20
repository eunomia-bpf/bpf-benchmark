# ARM64 CI Baseline Research

Date: 2026-03-19

## Scope

Task: assess whether GitHub Actions `ubuntu-24.04-arm` can run the ARM64 pure-JIT baseline (`llvmbpf` vs stock kernel), then implement the workflow path that is realistic today without touching kernel code.

Constraints followed:

- No kernel source under `vendor/linux-framework` was modified.
- No local benchmark campaign was run; local checks were limited to build and `--compile-only` feasibility.

## Executive Summary

### What works

- `micro_exec` is natively buildable on Linux ARM64.
- The stock `kernel` runtime path does not depend on the custom recompile syscall; it uses `libbpf` + `bpf_prog_test_run_opts()`.
- GitHub-hosted Linux runners provide passwordless `sudo`, so the stock kernel runtime is viable on Actions if the host kernel exposes standard eBPF load/test-run support.
- `llvmbpf` explicitly links AArch64 LLVM components, and the scanner CLI has `__aarch64__` syscall definitions.
- A clean-checkout corpus path exists for paired `llvmbpf`/`kernel`: `corpus/run_real_world_code_size.py` plus `corpus/run_real_world_exec_time.py`, using `libbpf-bootstrap` fetched on demand.

### What does not work cleanly today

- ARM64 recompile is still blocked. The project hub already records that ARM64 `test_recompile` returns `-EOPNOTSUPP`, because ARM64 has no `bpf_jit_supports_recompile()` implementation.
- The full macro corpus is not CI-ready from a clean checkout:
  - `corpus/build/`, `corpus/repos/`, `corpus/inventory.json`, and `corpus/bcf/` are ignored local assets, not tracked in git.
  - `corpus/_driver_impl_run_macro_corpus.py` is kernel-only today; it does not run `llvmbpf`.
- GitHub ARM64 runners should not be treated as a KVM platform. This matters for VM/selftest work, but not for the stock-host-kernel baseline.

### Implemented workflow direction

- Updated `.github/workflows/arm64-benchmark.yml` to:
  - build `micro_exec` and micro BPF programs natively on `ubuntu-24.04-arm`
  - run the full micro pure-JIT suite with `--runtime llvmbpf --runtime kernel`
  - preserve `llvmbpf-only` and `kernel-only` fallback outputs if the combined run fails
  - run a minimal real-world corpus baseline via `libbpf-bootstrap` using:
    - `corpus/run_real_world_code_size.py`
    - `corpus/run_real_world_exec_time.py`
  - upload artifacts instead of committing results back to `main`

## Step 1: Existing ARM64 CI

Current `arm64-benchmark.yml` before this change:

- manual `workflow_dispatch`
- `runs-on: ubuntu-24.04-arm`
- installed `clang llvm cmake pkg-config libbpf-dev libelf-dev zlib1g-dev libzstd-dev python3-yaml`
- built `make -C micro`
- ran only the micro pure-JIT suite
- tried combined `llvmbpf + kernel`, then fell back to `kernel`-only if the combined run produced no output
- uploaded `micro/results/arm64_*.json`
- committed results back to `main`

Gaps in that workflow:

1. No corpus path at all.
2. Missing dev packages needed by the current build graph:
   - `llvm-dev` for `find_package(LLVM REQUIRED CONFIG)`
   - `libyaml-cpp-dev` for `find_package(yaml-cpp CONFIG REQUIRED)`
3. `contents: write` + auto-push is the wrong shape for benchmark artifacts.
4. Fallback only kept `kernel` results, not `llvmbpf` results.

## Step 2: micro_exec on ARM64

### Build graph findings

`micro/runner/CMakeLists.txt` shows:

- `micro_exec` links:
  - vendored `llvmbpf`
  - vendored static `libbpf`
  - scanner library
  - `libelf`, `zlib`, `libzstd`

`scanner/CMakeLists.txt` adds one more requirement:

- `yaml-cpp` via CMake package config

`vendor/llvmbpf/CMakeLists.txt` uses:

- `find_package(LLVM REQUIRED CONFIG)`
- static LLVM component mapping including:
  - `AArch64CodeGen`
  - `AArch64Desc`
  - `AArch64Info`
  - `AArch64AsmParser`

That means the practical dependency list for Actions is:

- `build-essential`
- `clang`
- `cmake`
- `llvm`
- `llvm-dev`
- `pkg-config`
- `libbpf-dev`
- `libelf-dev`
- `zlib1g-dev`
- `libzstd-dev`
- `libyaml-cpp-dev`
- `python3-yaml`
- `bpftool` for the corpus code-size path

### Local validation

I verified the build locally on the current x86_64 host:

```bash
make -C micro micro_exec
make -C micro programs
```

Both succeeded.

I also verified non-benchmark compile-only smoke:

```bash
micro/build/runner/micro_exec list-programs --program micro/programs/simple.bpf.o
micro/build/runner/micro_exec run-llvmbpf --program micro/programs/simple.bpf.o --program-name simple_xdp --io-mode staged --input-size 64 --repeat 1 --compile-only
sudo -n micro/build/runner/micro_exec run-kernel --program micro/programs/simple.bpf.o --program-name simple_xdp --io-mode packet --raw-packet --input-size 64 --repeat 1 --compile-only
```

Observed:

- `list-programs` succeeded.
- `run-llvmbpf --compile-only` succeeded and emitted native code size `73` bytes.
- `run-kernel --compile-only` succeeded and emitted `jited_prog_len=108`, `xlated_prog_len=192`.

This does not prove ARM64 execution directly, but it proves the workflow commands themselves are valid and the stock kernel path is independent of recompile.

### ARM64-specific source evidence

- `scanner/src/cli.cpp` has explicit `__aarch64__` syscall numbers for `__NR_bpf` and `__NR_memfd_create`.
- `vendor/llvmbpf/test/src/test_vm.c` and related tests explicitly mention x86_64 and arm64 JIT support.

## Step 3: Stock kernel runtime on GitHub ARM64 runners

### What the runtime actually needs

`micro/runner/src/kernel_runner.cpp` uses:

- `libbpf`
- `bpf_prog_test_run_opts()`
- ordinary `BPF_PROG_LOAD` / `BPF_OBJ_GET_INFO_BY_FD` flow

It does **not** require:

- `/dev/kvm`
- a custom booted kernel
- the ARM64 recompile syscall path

So the question for the baseline is only whether the GitHub-hosted Ubuntu ARM64 kernel supports ordinary eBPF load + test-run operations under `sudo`.

### GitHub-hosted runner facts

Official GitHub docs currently say:

- `ubuntu-24.04-arm` is a standard GitHub-hosted runner label.
- Linux GitHub-hosted runners provide passwordless `sudo`.
- nested virtualization is not officially supported.

Sources:

- GitHub-hosted runners reference:
  - https://docs.github.com/en/actions/reference/runners/github-hosted-runners
- GitHub-hosted runners overview:
  - https://docs.github.com/en/actions/concepts/runners/github-hosted-runners

Relevant implications:

- Stock-host-kernel baseline is viable in principle.
- VM/KVM-based ARM64 selftests remain out of scope for GitHub-hosted runners.

### ARM64 partner image facts

GitHub documents `ubuntu-24.04-arm` as an Arm partner image, and the published inventory lists:

- Clang 16/17/18
- CMake
- Docker
- make
- Python

Source:

- https://github.com/actions/partner-runner-images
- https://github.com/actions/partner-runner-images/blob/main/images/arm-ubuntu-24-image.md

This is compatible with our decision to install only the missing dev packages explicitly via `apt`.

### Kernel-runtime conclusion

Best assessment:

- `kernel` baseline on `ubuntu-24.04-arm` is likely to work for the stock path and is worth running directly.
- If the runner kernel rejects some loads or test-run modes, the workflow should preserve `llvmbpf-only` results rather than failing empty.

## Step 4: Corpus compatibility on ARM64

### Full macro corpus

Not CI-ready from a clean checkout.

Why:

1. `corpus/config/macro_corpus.yaml` points at `corpus/build/...` objects.
2. `corpus/build/`, `corpus/repos/`, `corpus/inventory.json`, and `corpus/bcf/` are ignored local assets in this repo.
3. `corpus/_driver_impl_run_macro_corpus.py` always executes `run-kernel`; it does not support `llvmbpf`.

So even if the assets existed on the runner, the macro suite would still not satisfy the user's requested `llvmbpf` vs `kernel` baseline without additional code changes beyond the workflow.

### Existing paired llvmbpf/kernel corpus path

The codebase already has a better fit for this task:

- `corpus/run_real_world_code_size.py`
  - compiles or loads corpus objects
  - runs `run-llvmbpf` and `run-kernel` in `--compile-only` mode
- `corpus/run_real_world_exec_time.py`
  - takes the paired code-size output
  - runs execution-time comparisons for the subset that succeeds on both runtimes

This is exactly the pure-baseline pairing we need.

### Clean-checkout feasible subset

The only subset that is immediately fetchable and runnable from a clean checkout is `libbpf-bootstrap`.

Why:

- `fetch_real_world_corpus.py` can sparse-clone `libbpf-bootstrap`.
- `run_real_world_code_size.py` already knows how to compile `libbpf-bootstrap` sources from that checkout.
- The broader BCF-backed corpus depends on `corpus/bcf/`, which is also an ignored local asset unless `fetch_bcf_dataset.py` is run.

### Local validation

I verified the minimal clean-checkout corpus path locally:

```bash
python3 corpus/fetch_real_world_corpus.py --repo libbpf-bootstrap
python3 corpus/run_real_world_code_size.py \
  --repo libbpf-bootstrap \
  --max-sources 1 \
  --output /tmp/arm64_code_size_smoke.json \
  --report /tmp/arm64_code_size_smoke.md
```

Observed:

- fetch step succeeded
- code-size step succeeded
- first source `bootstrap.bpf.c` produced 2 programs
- both `llvmbpf` and `kernel` compile-only inspection succeeded on both programs

Per the task constraint, I did **not** run `run_real_world_exec_time.py` locally.

## Step 5: Workflow design

### Implemented default path

The updated ARM64 workflow now does:

1. install the missing build dependencies
2. build `micro_exec` and the micro BPF programs natively
3. run compile-only preflight checks on both backends
4. run the full micro pure-JIT suite with:
   - `--runtime llvmbpf`
   - `--runtime kernel`
5. preserve fallback single-runtime JSON if the combined micro run fails
6. fetch `libbpf-bootstrap`
7. run:
   - `corpus/run_real_world_code_size.py --repo libbpf-bootstrap`
   - `corpus/run_real_world_exec_time.py` against that output
8. upload artifacts instead of mutating the repo

### Why `libbpf-bootstrap` only by default

Because it is the only existing paired corpus path that is:

- clean-checkout reproducible
- small enough for routine GitHub-hosted ARM64 use
- already implemented without adding new corpus-driver code

### What remains blocked or optional

- Full macro corpus on clean GitHub Actions runners
- ARM64 recompile / `kernel-recompile`
- VM-based ARM64 selftests on GitHub-hosted runners
- Broad BCF-backed corpus unless the workflow is extended to fetch the BCF dataset explicitly

## Files changed

- `.github/workflows/arm64-benchmark.yml`

## Bottom Line

Recommended judgment for the task:

- **Micro ARM64 baseline:** feasible now on GitHub Actions `ubuntu-24.04-arm`
- **Stock kernel runtime on host ARM64 runner:** feasible enough to run directly with fallback
- **Full existing corpus suite:** not clean-checkout ready
- **Minimal paired real-world corpus baseline:** feasible now via `libbpf-bootstrap`

That is the path implemented in the updated workflow.

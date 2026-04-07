# BPF Benchmark

eBPF benchmarking suite for the BpfReJIT paper — comparing llvmbpf (userspace LLVM JIT) against kernel eBPF with and without ReJIT.

Three-layer benchmarking pipeline:

- `micro/`: isolated micro-benchmarks driven by `bpf_prog_test_run_opts`
- `corpus/`: real-world program collection, measurement, and analysis
- `e2e/`: end-to-end deployment benchmarks (Tracee, Tetragon, bpftrace, scx, katran)

The historical multi-runtime userspace benchmark layer has been removed; the active tree is `micro/`, `corpus/`, and `e2e/`.

## Repository Layout

```text
bpf-benchmark/
├── runner/                # Target/suite contracts, executors, shared libs, and micro_exec
├── micro/                 # Isolated micro-benchmark suites, drivers, and inputs
├── corpus/                # 23-project real-world corpus, fetch/build, and measurement
├── e2e/                   # End-to-end workloads (tracee, tetragon, bpftrace, scx, katran)
├── daemon/                # Userspace BPF daemon (bpfrejit-daemon CLI)
├── config/                # YAML benchmark suite manifests (micro_pure_jit.yaml etc.)
├── tests/                 # Userspace/kernel self-tests
├── docs/                  # Research plans, reports, and temporary experiment notes
└── vendor/                # Vendored kernel (linux-framework) + tooling dependencies
```

## Prerequisites

- clang/llvm (BPF programs compiled with `clang -target bpf`)
- cmake, pkg-config, libelf-dev, zlib1g-dev, libzstd-dev
- Python 3 with PyYAML: `pip install pyyaml` (or use the workspace venv)
- `sudo -n` (passwordless) required for kernel eBPF runtime
- `vng` (virtme-ng) required for VM benchmark targets

## Quick Start

```bash
git submodule update --init --recursive
source /home/yunwei37/workspace/.venv/bin/activate   # workspace venv (optional)

# Build micro runner + BPF programs + daemon
make all

# Quick smoke test (no VM required)
make smoke

# Full micro benchmark suite in VM
make vm-micro

# Show all targets and parameters
make help
```

## Running Benchmarks

**The root `Makefile` is the single canonical entry point for all benchmarks.**

```bash
make vm-micro                        # full micro suite in VM
make vm-micro BENCH="simple bitcount"  # subset of benchmarks
make vm-micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
make vm-corpus                       # corpus benchmark in VM
make vm-corpus FILTERS=scx VM_CORPUS_WORKLOAD_SECONDS=10
make vm-e2e                          # E2E benchmarks in VM
make vm-e2e E2E_CASE=scx E2E_SMOKE=1
make aws-arm64-test                  # AWS ARM64 correctness path
make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=micro
make aws-x86-test                    # AWS x86 correctness path
make aws-x86-benchmark AWS_X86_BENCH_MODE=e2e
```

AWS targets require explicit local configuration for:
- `AWS_ARM64_KEY_NAME` / `AWS_X86_KEY_NAME`
- `AWS_ARM64_KEY_PATH` / `AWS_X86_KEY_PATH`
- `AWS_ARM64_SECURITY_GROUP_ID` / `AWS_X86_SECURITY_GROUP_ID`
- `AWS_ARM64_SUBNET_ID` / `AWS_X86_SUBNET_ID`
- `AWS_ARM64_PROFILE` / `AWS_X86_PROFILE`

Results are written to:
- `micro/results/` — direct local smoke outputs such as `make smoke`
- `.cache/kvm-staged/<run_token>/workspace/.cache/suite-results/<target>_<suite>_<timestamp>/` — staged local-KVM suite artifacts copied out by the suite entrypoint
- `.cache/aws-arm64/results/<suite>_<token>_<timestamp>/` — fetched AWS ARM64 suite outputs
- `.cache/aws-x86/results/<suite>_<token>_<timestamp>/` — fetched AWS x86 suite outputs
- `docs/tmp/` — analysis reports (.md only, never JSON results)

`make clean` preserves fetched AWS result directories under `.cache/aws-*/results/`.

## Building Components Individually

```bash
make micro            # micro_exec runner + BPF programs
make daemon           # bpfrejit-daemon CLI
make kernel           # bzImage from vendor/linux-framework
make upstream-selftests-build
```

## Layer Notes

`runner/` owns target/suite contracts under `runner/targets/` and `runner/suites/`, the shared `micro_exec` C++ runner, executors under `runner/scripts/`, and shared Python libraries in `runner/libs/`.

`micro/` owns the isolated benchmark manifests (`micro/config/micro_pure_jit.yaml`), input generators, and the Python suite driver (`micro/driver.py`).

`corpus/` owns the 23-project real-world corpus, fetch/build tooling, declarative app suites in `corpus/config/`, and the measurement entrypoint in `corpus/driver.py`.

`e2e/` owns full deployment-style evaluation via `e2e/driver.py` plus per-case assets under `e2e/cases/`.

`daemon/` is the userspace front end for BpfReJIT: it scans live BPF programs via `BPF_PROG_GET_NEXT_ID`, identifies optimization sites, and triggers `BPF_PROG_REJIT`. See `daemon/README.md`.

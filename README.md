# BPF Benchmark

eBPF benchmarking suite for the BpfReJIT paper — comparing llvmbpf (userspace LLVM JIT) against kernel eBPF with and without JIT specialization directives.

Three-layer benchmarking pipeline:

- `micro/`: isolated micro-benchmarks driven by `bpf_prog_test_run_opts`
- `corpus/`: real-world program collection, measurement, and analysis
- `e2e/`: end-to-end deployment benchmarks (Tracee, Tetragon, bpftrace, scx)

Legacy multi-runtime benchmarks live under `legacy/` and are not part of the active pipeline.

## Repository Layout

```text
bpf-benchmark/
├── micro/                 # Isolated micro-benchmark suites + runner (micro_exec)
├── corpus/                # 23-project real-world corpus, fetch/build, and measurement
├── e2e/                   # End-to-end workloads (tracee, tetragon, bpftrace, scx)
├── scanner/               # Userspace BPF directive scanner (bpf-jit-scanner CLI)
├── config/                # YAML benchmark suite manifests (micro_pure_jit.yaml etc.)
├── docs/                  # Research plans, reports, and temporary experiment notes
├── legacy/                # Inactive historical benchmark code
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

# Build micro runner + BPF programs + scanner
make all

# Quick smoke test (no VM required)
make smoke

# Full micro benchmark suite in VM → micro/results/dev/vm_micro.json
make vm-micro

# Show all targets and parameters
make help
```

## Running Benchmarks

**The root `Makefile` is the single canonical entry point for all benchmarks.**

```bash
make vm-micro                        # full micro suite in VM
make vm-micro BENCH="simple bitcount"  # subset of benchmarks
make vm-micro ITERATIONS=10 WARMUPS=2 REPEAT=500
make vm-corpus                       # corpus benchmark in VM
make vm-e2e                          # E2E benchmarks in VM
make vm-all                          # all VM benchmarks
make verify-build                    # check artifacts are up to date
make compare OLD=a.json NEW=b.json   # diff two result JSON files
```

Results are written to:
- `micro/results/dev/` — default Makefile micro outputs
- `corpus/results/dev/` — default Makefile corpus outputs
- `e2e/results/dev/` — default Makefile E2E outputs
- `*/results/` top-level — checked-in authoritative JSON only
- `docs/tmp/` — analysis reports (.md only, never JSON results)

## Building Components Individually

```bash
make micro            # micro_exec runner + BPF programs
make scanner          # bpf-jit-scanner CLI
make kernel           # bzImage from vendor/linux-framework
make kernel-tests     # kernel recompile self-tests
```

## Layer Notes

`micro/` owns the isolated benchmark manifests (`config/micro_pure_jit.yaml`), the `micro_exec` C++ runner, input generators, and the Python driver (`micro/driver.py`, with `_driver_impl_run_micro.py` as the suite backend).

`corpus/` owns the 23-project real-world corpus, fetch/build tooling, declarative corpus config in `corpus/config/`, and the measurement backends surfaced through `python3 micro/driver.py corpus ...` plus `corpus/run_corpus_runnability.py`.

`e2e/` owns full deployment-style evaluation via `e2e/run.py` plus per-case assets under `e2e/cases/`.

`scanner/` is the userspace front end for BpfReJIT: it scans live BPF programs via `BPF_PROG_GET_NEXT_ID`, identifies optimization sites, and triggers `BPF_PROG_JIT_RECOMPILE`. See `scanner/README.md`.

`legacy/` contains the old multi-runtime userspace benchmark. Preserved for history, not part of the active workflow.

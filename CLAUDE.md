# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

eBPF benchmarking suite comparing **llvmbpf** (userspace LLVM JIT) against **kernel eBPF** across micro-benchmarks. The main active development area is `micro/`, which runs declarative YAML-driven benchmark suites. A legacy `user_bpf_benchmark/` directory compares multiple userspace runtimes (ubpf, rbpf, wasmtime, native) but is largely static.

## Build & Run

### Prerequisites
- clang/llvm (BPF programs compiled with `clang -target bpf`)
- cmake, pkg-config, libelf-dev, zlib1g-dev, libzstd-dev
- Python 3 with PyYAML (`pip install pyyaml`)
- `sudo -n` access required for kernel eBPF runtime

### Initial setup
```bash
git submodule update --init --recursive
make -C micro          # builds both micro_exec runner and BPF programs
```

### Build individual targets
```bash
make -C micro micro_exec       # C++ runner binary → micro/build/runner/micro_exec
make -C micro programs         # BPF .bpf.c → .bpf.o via clang
make -C micro vendor_bpftool   # optional vendored bpftool
```

### Run benchmarks
```bash
# List available benchmarks
python3 micro/run_micro.py --list

# Run default pure-jit suite (both runtimes)
python3 micro/run_micro.py --runtime llvmbpf --runtime kernel --iterations 10 --warmups 2 --repeat 200

# Run runtime suite (map/helper benchmarks)
python3 micro/run_micro.py --suite config/micro_runtime.yaml --runtime llvmbpf --runtime kernel

# Run specific benchmarks only
python3 micro/run_micro.py --bench simple --bench bitcount --runtime llvmbpf --runtime kernel

# With perf counters
python3 micro/run_micro.py --runtime llvmbpf --runtime kernel --perf-counters

# Generate RQ-oriented markdown summary from results
python3 micro/summarize_rq.py --results micro/results/pure_jit.latest.json --output docs/summary.md
```

### Clean
```bash
make -C micro clean
```

## Architecture

### Three-layer benchmark model

Configured via YAML files in `config/`:
- **`micro_pure_jit.yaml`** — Pure JIT codegen/execution micro-benchmarks (22 cases). Uses `staged` IO mode: input staged via `input_map`, result returned in XDP test packet's first 8 bytes.
- **`micro_runtime.yaml`** — Map/helper runtime mechanism benchmarks. Uses `map` IO mode: result written to `result_map`.
- **`macro_corpus.yaml`** — Macro/corpus layer entry point.

### Key components

**`micro/run_micro.py`** — Main orchestrator. Loads suite YAML via `benchmark_catalog.py`, generates inputs via `input_generators.py`, invokes `micro_exec` for each benchmark×runtime pair, collects JSON samples, computes statistics (median/mean/p95/stdev), and attaches baseline adjustments.

**`micro/benchmark_catalog.py`** — Parses suite YAML into typed dataclasses (`SuiteSpec`, `BenchmarkSpec`, `RuntimeSpec`). `CONFIG_PATH` defaults to `config/micro_pure_jit.yaml`. All paths in YAML are resolved relative to repo root.

**`micro/input_generators.py`** — Deterministic binary input generators (one per benchmark). Outputs `.mem` files to `micro/generated-inputs/`. Each generator produces a fixed binary layout matching the corresponding BPF program's `input_map` value type.

**`micro/runner/`** — C++20 CMake project producing `micro_exec` binary. Two subcommands:
- `run-llvmbpf` — Loads ELF, extracts BPF bytecode, JIT-compiles via `llvmbpf_vm`, executes in userspace with emulated maps
- `run-kernel` — Loads ELF via libbpf, runs via `bpf_prog_test_run_opts` in kernel

Both paths output a single JSON line per sample with `compile_ns`, `exec_ns`, `result`, `phases_ns`, and optional `perf_counters`.

**`micro/programs/*.bpf.c`** — BPF benchmark programs. Each includes `common.h` and uses one of three macros:
- `DEFINE_STAGED_INPUT_XDP_BENCH` — staged IO (pure-jit suite)
- `DEFINE_MAP_BACKED_XDP_BENCH` — map IO (runtime suite)
- `DEFINE_PACKET_BACKED_XDP_BENCH` — packet IO

Programs define a `bench_*()` function taking `(const u8 *data, u32 len, u64 *out)` and an `input_map` with a program-specific value struct.

### Vendor submodules (`vendor/`)
- `llvmbpf` — LLVM-based BPF JIT compiler (from eunomia-bpf)
- `libbpf` — Kernel BPF library (built as static lib into `micro/build/vendor/libbpf/`)
- `bpftool` — Optional BPF tooling

### Adding a new benchmark

1. Create `micro/programs/<name>.bpf.c` with input struct, `input_map`, `bench_*` function, and the appropriate `DEFINE_*_XDP_BENCH` macro
2. Add a generator function in `micro/input_generators.py` and register it in `GENERATORS`
3. Add the benchmark entry to the relevant `config/*.yaml` with `name`, `base_name`, `kernel_input_size`, `input_generator`, `expected_result`, category/family/tags

### Constraints
- Kernel runtime requires `sudo -n` without password prompt
- llvmbpf allocates packet buffers in low 32-bit address space (MAP_32BIT) for XDP context compatibility
- llvmbpf does not support BPF-to-BPF internal subprogram calls (ELF loader limitation)
- `--perf-counters` uses `perf_event_open`; kernel counters include kernel-mode, llvmbpf counters are user-mode only

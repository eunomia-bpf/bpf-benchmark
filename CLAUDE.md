# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

eBPF benchmarking suite comparing **llvmbpf** (userspace LLVM JIT) against **kernel eBPF** across micro-benchmarks. The main active development areas are `micro/`, `corpus/`, and `e2e/`; the old multi-runtime userspace benchmark layer has been removed.

## Build & Run

### Prerequisites
- clang/llvm (BPF programs compiled with `clang -target bpf`)
- cmake, pkg-config, libelf-dev, zlib1g-dev, libzstd-dev
- Python 3 with PyYAML (`pip install pyyaml`)
- `sudo -n` access required for kernel eBPF runtime

### Initial setup
```bash
git submodule update --init --recursive
make micro             # builds runner/build/micro_exec and micro BPF programs

# e2e/corpus recompile paths expect the standalone daemon CLI
cargo build --release --manifest-path daemon/Cargo.toml
```

### Build individual targets
```bash
make runner                   # C++ runner binary → runner/build/micro_exec
make -C micro programs        # BPF .bpf.c → .bpf.o via clang
make -C runner vendor_bpftool # optional vendored bpftool
```

### Run benchmarks

**The Makefile is the single canonical entry point for running benchmarks.**

```bash
# Full micro benchmark suite in VM (results → micro/results/dev/vm_micro.json)
make vm-micro

# Run only specific benchmarks
make vm-micro BENCH="simple bitcount"

# Tune parameters
make vm-micro ITERATIONS=10 WARMUPS=2 REPEAT=500

# Quick smoke test (no VM needed)
make smoke

# Corpus benchmark in VM (results → corpus/results/dev/vm_corpus.json)
make vm-corpus

# E2E benchmarks in VM (results → e2e/results/)
make vm-e2e

# All VM benchmarks
make vm-all

# Show all available targets and parameters
make help
```

Results are written to:
- `micro/results/dev/` — default Makefile micro outputs
- `corpus/results/dev/` — default Makefile corpus outputs
- `e2e/results/dev/` — default Makefile E2E outputs
- `*/results/` top-level — checked-in authoritative JSON only
- `docs/tmp/` — analysis reports (.md) only, never JSON results

For direct invocation (advanced use only):
```bash
# List available benchmarks
python3 micro/driver.py suite -- --list

# Run with perf counters (direct invocation)
python3 micro/driver.py suite -- --runtime llvmbpf --runtime kernel --perf-counters

# Generate RQ-oriented markdown summary from results
python3 micro/summarize_rq.py --results micro/results/dev/vm_micro.json --output docs/summary.md
```

### Clean
```bash
make -C micro clean
make -C runner clean
```

## Architecture

### Three-layer benchmark model

Configured via YAML files in `micro/config/` and `corpus/config/`:
- **`micro/config/micro_pure_jit.yaml`** — Current default isolated JIT suite (62 benchmarks as of March 13, 2026): 48 staged XDP compute cases + 6 per-form dense variants, 5 packet-backed XDP controls, and 3 kernel-only non-XDP controls (2 TC + 1 cgroup_skb). The active suite is aligned with the 8 canonical forms tracked in `docs/kernel-jit-optimization-plan.md`.
- **`corpus/config/macro_corpus.yaml`** — Macro/corpus layer entry point.

### Key components

**`micro/driver.py`** — Main pure-JIT suite orchestrator. Loads suite YAML via `benchmark_catalog.py`, generates inputs via `input_generators.py`, invokes `micro_exec` for each benchmark×runtime pair, collects JSON samples, computes summaries, and attaches baseline adjustments.

**`micro/benchmark_catalog.py`** — Parses suite YAML into typed dataclasses (`SuiteSpec`, `BenchmarkSpec`, `RuntimeSpec`). `CONFIG_PATH` defaults to `micro/config/micro_pure_jit.yaml`. All paths in YAML are resolved relative to repo root.

**`micro/input_generators.py`** — Deterministic binary input generators (one per benchmark). Outputs `.mem` files to `micro/generated-inputs/`. Each generator produces a fixed binary layout matching the corresponding BPF program's `input_map` value type.

**`runner/`** — C++20 CMake project producing `micro_exec` plus shared Python helpers in `runner/libs/`. Two subcommands:
- `run-llvmbpf` — Loads ELF, extracts BPF bytecode, JIT-compiles via `llvmbpf_vm`, executes in userspace with emulated maps
- `run-kernel` — Loads ELF via libbpf, runs via `bpf_prog_test_run_opts` in kernel

Both paths output a single JSON line per sample with `compile_ns`, `exec_ns`, `result`, `phases_ns`, and optional `perf_counters`.

**`micro/programs/*.bpf.c`** — Active BPF benchmark programs. Each includes `common.h` and uses one of the active harness macros:
- `DEFINE_STAGED_INPUT_XDP_BENCH` — staged XDP pure-jit path
- `DEFINE_PACKET_BACKED_XDP_BENCH` / `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` — packet-backed XDP controls
- `DEFINE_MAP_BACKED_TC_BENCH` / `DEFINE_MAP_BACKED_CGROUP_SKB_BENCH` — kernel-only non-XDP controls

Programs define a `bench_*()` function taking `(const u8 *data, u32 len, u64 *out)` and an `input_map` with a program-specific value struct.

### Vendor submodules (`vendor/`)
- `llvmbpf` — LLVM-based BPF JIT compiler (from eunomia-bpf)
- `libbpf` — Kernel BPF library (built as static lib into `micro/build/vendor/libbpf/`)
- `bpftool` — Optional BPF tooling

### Adding a new benchmark

1. Create `micro/programs/<name>.bpf.c` with input struct, `input_map`, `bench_*` function, and the appropriate `DEFINE_*_XDP_BENCH` macro
2. Add a generator function in `micro/input_generators.py` and register it in `GENERATORS`
3. Add the benchmark entry to `micro/config/micro_pure_jit.yaml` with `name`, `base_name`, `kernel_input_size`, `input_generator`, `expected_result`, category/family/tags

### Constraints
- Kernel runtime requires `sudo -n` without password prompt
- llvmbpf allocates packet buffers in low 32-bit address space (MAP_32BIT) for XDP context compatibility
- llvmbpf does not support BPF-to-BPF internal subprogram calls (ELF loader limitation)
- `--perf-counters` uses `perf_event_open`; kernel counters include kernel-mode, llvmbpf counters are user-mode only

### Code Quality Rules
- **No dead code**: When replacing a subsystem (e.g., v1→v2), delete the old code entirely. Do not keep `if v1 then ... else v2` branches or commented-out legacy paths. Dead code rots and confuses future readers.
- **No unnecessary defensive checks**: Only validate at system boundaries (user input, external APIs). Trust internal invariants and kernel guarantees. If a check is "just in case" with no concrete failure scenario, remove it.
- **Direct replacement over addition**: When an interface changes, modify the existing code path instead of adding a parallel one. One path that works beats two paths where one is dead.
- **Minimize kernel LOC**: Every line of kernel code is a maintenance and review burden. Prefer the simplest implementation that passes all tests. Remove guards that exist only because the POC was too lazy to handle the general case.

## Subagent Workflow

### Division of Labor
- **Subagent handles**: code implementation, benchmark runs, data analysis, research, code review, CI fixes
- **Claude Code handles**: scheduling/dispatching, document writing (non-tmp), TODO/memory updates, architectural decisions
- **Claude Code must NEVER**: write implementation code directly, run benchmarks directly — always delegate

### Workflow Rules
- **Subagent output goes to `docs/tmp/`** — reports (.md) into `docs/tmp/`; JSON results go to `*/results/`
- **Never ask for confirmation** — just keep going, iterate autonomously
- **ALWAYS include `docs/kernel-jit-optimization-plan.md` as context** — every prompt MUST reference this doc
- **NEVER delete old entries in tracking docs** — mark superseded, keep row
- **Claude 只给高层次要求** — 让 subagent 自己读代码、设计方案、实现
- **Subagent 必须测试验证** — 写完代码后实际跑通，不能只写不测
- **构建+修改+运行不拆分** — 一个 subagent 负责完整流程
- **⚠️ 同一时间只能一个 agent 改内核代码，也只能一个 agent 跑测试**
- **⚠️ 默认不 commit/push** — 改完代码就停，由 Claude 统一 commit
- **⚠️ 如需 commit，在 main 直接做，不开分支**

### Benchmark Program Design Rules
- **Pure-JIT benchmarks** (`micro_pure_jit.yaml`): Must test ONLY JIT code generation quality. No map lookups or helper calls in the benchmark hot path. Allowed harness shapes are staged XDP, packet-backed XDP controls, and the small TC/cgroup_skb kernel-only control subset already in the suite.
- **Runtime-mechanism cases**: Keep runtime-overhead experiments out of the active pure-JIT manifest unless the suite definition and methodology are updated together.
- If a pure-JIT benchmark uses maps or helpers in its hot path, it is measuring runtime overhead, not JIT quality — this is a bug that must be fixed.

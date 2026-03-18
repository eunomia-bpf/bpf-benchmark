# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

eBPF benchmarking suite comparing **llvmbpf** (userspace LLVM JIT) against **kernel eBPF** across micro-benchmarks. The main active development area is `micro/`, which runs declarative YAML-driven benchmark suites. A legacy `legacy/user_bpf_benchmark/` directory compares multiple userspace runtimes (ubpf, rbpf, wasmtime, native) but is not part of the active pipeline.

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

# e2e/corpus recompile paths expect the standalone scanner CLI
cmake -S scanner -B scanner/build -DCMAKE_BUILD_TYPE=Release
cmake --build scanner/build --target bpf-jit-scanner -j
```

### Build individual targets
```bash
make -C micro micro_exec       # C++ runner binary → micro/build/runner/micro_exec
make -C micro programs         # BPF .bpf.c → .bpf.o via clang
make -C micro vendor_bpftool   # optional vendored bpftool
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
python3 micro/run_micro.py --list

# Run with perf counters (direct invocation)
python3 micro/run_micro.py --runtime llvmbpf --runtime kernel --perf-counters

# Generate RQ-oriented markdown summary from results
python3 micro/summarize_rq.py --results micro/results/dev/vm_micro.json --output docs/summary.md
```

### Clean
```bash
make -C micro clean
```

## Architecture

### Three-layer benchmark model

Configured via YAML files in `config/`:
- **`config/micro_pure_jit.yaml`** — Current default isolated JIT suite (62 benchmarks as of March 13, 2026): 48 staged XDP compute cases + 6 per-form dense variants, 5 packet-backed XDP controls, and 3 kernel-only non-XDP controls (2 TC + 1 cgroup_skb). The active suite is aligned with the 8 canonical forms tracked in `docs/kernel-jit-optimization-plan.md`.
- **`corpus/config/macro_corpus.yaml`** — Macro/corpus layer entry point.
- **`config/ablation/`** — Per-family ablation suite YAML files used for ablation experiments.

### Key components

**`micro/run_micro.py`** — Main orchestrator. Loads suite YAML via `benchmark_catalog.py`, generates inputs via `input_generators.py`, invokes `micro_exec` for each benchmark×runtime pair, collects JSON samples, computes statistics (median/mean/p95/stdev), and attaches baseline adjustments.

**`micro/benchmark_catalog.py`** — Parses suite YAML into typed dataclasses (`SuiteSpec`, `BenchmarkSpec`, `RuntimeSpec`). `CONFIG_PATH` defaults to `config/micro_pure_jit.yaml`. All paths in YAML are resolved relative to repo root.

**`micro/input_generators.py`** — Deterministic binary input generators (one per benchmark). Outputs `.mem` files to `micro/generated-inputs/`. Each generator produces a fixed binary layout matching the corresponding BPF program's `input_map` value type.

**`micro/runner/`** — C++20 CMake project producing `micro_exec` binary. Two subcommands:
- `run-llvmbpf` — Loads ELF, extracts BPF bytecode, JIT-compiles via `llvmbpf_vm`, executes in userspace with emulated maps
- `run-kernel` — Loads ELF via libbpf, runs via `bpf_prog_test_run_opts` in kernel

Both paths output a single JSON line per sample with `compile_ns`, `exec_ns`, `result`, `phases_ns`, and optional `perf_counters`.

**`micro/programs/*.bpf.c`** — Active BPF benchmark programs. Each includes `common.h` and uses one of the active harness macros:
- `DEFINE_STAGED_INPUT_XDP_BENCH` — staged XDP pure-jit path
- `DEFINE_PACKET_BACKED_XDP_BENCH` / `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` — packet-backed XDP controls
- `DEFINE_MAP_BACKED_TC_BENCH` / `DEFINE_MAP_BACKED_CGROUP_SKB_BENCH` — kernel-only non-XDP controls

Archived runtime-only programs live under `micro/programs/archive/runtime/` and are not part of the active suite.

Programs define a `bench_*()` function taking `(const u8 *data, u32 len, u64 *out)` and an `input_map` with a program-specific value struct.

### Vendor submodules (`vendor/`)
- `llvmbpf` — LLVM-based BPF JIT compiler (from eunomia-bpf)
- `libbpf` — Kernel BPF library (built as static lib into `micro/build/vendor/libbpf/`)
- `bpftool` — Optional BPF tooling

### Adding a new benchmark

1. Create `micro/programs/<name>.bpf.c` with input struct, `input_map`, `bench_*` function, and the appropriate `DEFINE_*_XDP_BENCH` macro
2. Add a generator function in `micro/input_generators.py` and register it in `GENERATORS`
3. Add the benchmark entry to `config/micro_pure_jit.yaml` with `name`, `base_name`, `kernel_input_size`, `input_generator`, `expected_result`, category/family/tags

### Constraints
- Kernel runtime requires `sudo -n` without password prompt
- llvmbpf allocates packet buffers in low 32-bit address space (MAP_32BIT) for XDP context compatibility
- llvmbpf does not support BPF-to-BPF internal subprogram calls (ELF loader limitation)
- `--perf-counters` uses `perf_event_open`; kernel counters include kernel-mode, llvmbpf counters are user-mode only

## Using Sonnet Subagent

> **Note (2026-03-14)**: Codex quota exhausted (renews 2026-03-18). All subagent tasks are now delegated to Claude Sonnet via the Agent tool (`run_in_background: true`).

Sonnet subagent is available for code writing and analysis tasks.

### Division of Labor (IMPORTANT)
- **Codex handles**: ALL code implementation, benchmark runs, data analysis, analysis scripts, experiments, research, code review, CI fixes
- **Claude Code handles**: scheduling/dispatching codex tasks, document writing (non-tmp), TODO/memory updates, architectural decisions, reviewing codex output
- **Claude Code must NEVER**: write analysis code directly, run benchmarks directly, or manually analyze data — always delegate to codex

### Workflow Rules
- **Codex output goes to `docs/tmp/`** — codex writes analysis/review/design reports (.md) into `docs/tmp/`; JSON results go to `micro/results/`, `corpus/results/`, or `e2e/results/`
- **Claude maintains non-tmp docs** — Claude directly edits `CLAUDE.md`, `docs/kernel-jit-optimization-plan.md`, and other non-tmp documents
- **Codex runs in background** — use `run_in_background: true` for all codex tasks; Claude dispatches and moves on
- **Review cycle** — when codex produces a new document, dispatch another codex to review it; iterate until quality is sufficient
- **CI monitoring** — dispatch codex to fix CI issues, push fixes, and monitor until CI passes (long-running background task)
- **Never ask for confirmation** — just keep going, do all work, iterate multiple rounds autonomously
- **ALWAYS include `docs/kernel-jit-optimization-plan.md` as context** — every codex prompt MUST reference this doc as the single source of truth for JIT optimization design
- **NEVER delete old entries in tracking docs** — when tasks/experiments/docs are superseded, keep at least one line with status (e.g. "归入 #32", "已被 v3 取代"). This applies to TODO tables, VM experiment matrix, reference doc lists in `docs/kernel-jit-optimization-plan.md`
- **Claude 只给高层次要求** — 不自己调研代码再给详细变更指令，让 codex 自己读代码、设计方案、实现
- **Codex 必须测试验证** — 每个 codex prompt 必须要求写完代码后实际跑通（sudo / VM vng 等方式），不能只写不测
- **构建+修改+运行不拆分** — 一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent，这样发现问题能立刻修

### Usage (Sonnet Agent)

When delegating coding/analysis tasks, use the Agent tool with `run_in_background: true`. Include `docs/kernel-jit-optimization-plan.md` as context in every prompt.

### Legacy Codex CLI (quota exhausted, renews 2026-03-18)
```bash
# Non-interactive execution — no sandbox, no prompts
codex exec --dangerously-bypass-approvals-and-sandbox "your prompt here"

# With a specific working directory
codex exec --dangerously-bypass-approvals-and-sandbox -C /path/to/dir "your prompt here"

# Pipe prompt from stdin
echo "implement feature X" | codex exec --dangerously-bypass-approvals-and-sandbox -
```

### Benchmark Program Design Rules
- **Pure-JIT benchmarks** (`micro_pure_jit.yaml`): Must test ONLY JIT code generation quality. No map lookups or helper calls in the benchmark hot path. Allowed harness shapes are staged XDP, packet-backed XDP controls, and the small TC/cgroup_skb kernel-only control subset already in the suite.
- **Archived runtime benchmarks**: Runtime-mechanism cases removed from the active comparison live under `micro/programs/archive/runtime/`. Keep them out of the active manifest unless the suite definition changes again.
- If a pure-JIT benchmark uses maps or helpers in its hot path, it is measuring runtime overhead, not JIT quality — this is a bug that must be fixed.

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

## Using Codex CLI as Subagent

OpenAI Codex CLI is available on this machine (default model: `gpt-5.4`). Use it as a subagent for code writing tasks.

### Division of Labor (IMPORTANT)
- **Codex handles**: ALL code implementation, benchmark runs, data analysis, analysis scripts, experiments, research, code review, CI fixes
- **Claude Code handles**: scheduling/dispatching codex tasks, document writing (non-tmp), TODO/memory updates, architectural decisions, reviewing codex output
- **Claude Code must NEVER**: write analysis code directly, run benchmarks directly, or manually analyze data — always delegate to codex

### Workflow Rules
- **Codex output goes to `docs/tmp/`** — codex writes analysis/review/design docs into `docs/tmp/`
- **Claude maintains non-tmp docs** — Claude directly edits `CLAUDE.md`, `docs/kernel-jit-optimization-plan.md`, and other non-tmp documents
- **Codex runs in background** — use `run_in_background: true` for all codex tasks; Claude dispatches and moves on
- **Review cycle** — when codex produces a new document, dispatch another codex to review it; iterate until quality is sufficient
- **CI monitoring** — dispatch codex to fix CI issues, push fixes, and monitor until CI passes (long-running background task)
- **Never ask for confirmation** — just keep going, do all work, iterate multiple rounds autonomously
- **ALWAYS include `docs/kernel-jit-optimization-plan.md` as context** — every codex prompt MUST reference this doc as the single source of truth for JIT optimization design
- **NEVER delete old entries in tracking docs** — when tasks/experiments/docs are superseded, keep at least one line with status (e.g. "归入 #32", "已被 v3 取代"). This applies to TODO tables, VM experiment matrix, reference doc lists in `docs/kernel-jit-optimization-plan.md`

### Usage
```bash
# Non-interactive execution — no sandbox, no prompts
codex exec --dangerously-bypass-approvals-and-sandbox "your prompt here"

# With a specific working directory
codex exec --dangerously-bypass-approvals-and-sandbox -C /path/to/dir "your prompt here"

# Pipe prompt from stdin
echo "implement feature X" | codex exec --dangerously-bypass-approvals-and-sandbox -
```

When delegating coding tasks, use `codex exec --dangerously-bypass-approvals-and-sandbox` so it can read/write files and run commands without interruption.

### Benchmark Program Design Rules
- **Pure-JIT benchmarks** (`micro_pure_jit.yaml`): Must test ONLY JIT code generation quality. No map lookups, no helper calls — pure computation only. Use `DEFINE_STAGED_INPUT_XDP_BENCH` with `input_map` for input staging only.
- **Runtime benchmarks** (`micro_runtime.yaml`): Test map/helper runtime mechanisms. Map lookups and helper calls are expected here.
- If a pure-JIT benchmark uses maps or helpers in its hot path, it is measuring runtime overhead, not JIT quality — this is a bug that must be fixed.

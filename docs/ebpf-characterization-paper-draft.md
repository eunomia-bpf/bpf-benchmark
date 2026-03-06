# Closing the Gap? A Characterization of eBPF Execution Across Kernel JIT and Userspace LLVM JIT

## Abstract

eBPF is now used across networking, tracing, security, scheduling, and storage. Yet the community still lacks a unified characterization of how the same eBPF program behaves across the Linux kernel JIT and emerging userspace LLVM-based runtimes. This paper presents a measurement framework and empirical study that compare `kernel eBPF` and `llvmbpf` along execution latency, compilation cost, phase breakdown, and microarchitectural behavior. We further study how helper usage, map access, branch structure, and verifier-friendly programming patterns shape the gap between the two execution environments. Our framework combines controlled micro-benchmarks with a growing corpus of real-world eBPF programs and emits machine-readable artifacts for reproducible analysis.

## 1. Introduction

The core question is no longer whether eBPF is useful, but how its execution quality varies across runtimes and why. The Linux kernel JIT is the de facto production engine, while userspace runtimes such as `llvmbpf` promise stronger optimization opportunities, easier experimentation, and lower integration cost. However, there is still no standard characterization pipeline that can answer five practical questions: how large the performance gap is, what causes it, which programs benefit most, how code generation and verifier-facing patterns interact, and how the picture changes in multi-program deployments.

This repository is evolving into that pipeline.

## 2. Research Questions

- RQ1: How large is the performance gap between `kernel eBPF` and `llvmbpf`?
- RQ2: Which factors explain the gap?
- RQ3: Which classes of eBPF programs benefit most?
- RQ4: How do code generation quality and verifier-facing patterns interact?
- RQ5: How does the picture change in multi-program scenarios?

## 3. Methodology

### 3.1 Measurement stack

- Declarative suite specification
- Three-layer organization: `micro_pure_jit`, `micro_runtime`, `macro_corpus`
- Single `programs/*.bpf.o` artifact shared by both runtimes
- `llvmbpf` execution helper with userspace map emulation
- `libbpf + BPF_PROG_TEST_RUN` kernel execution helper
- staged-input pure-jit path and map-backed runtime path under one runner
- Phase timing and optional `perf_event_open` counters in one JSON schema
- randomized benchmark order via `shuffle-seed`
- benchmark metadata (`category / family / level / hypothesis`) carried into result JSON
- baseline-adjusted pure-jit view plus bootstrap confidence intervals over cross-benchmark ratios

### 3.2 Current measurement dimensions

- compile/load/JIT time
- steady-state execution time
- phase breakdown
- optional perf counters over the execution window
- correctness validation through packet-header result extraction (`micro_pure_jit`) or `result_map` (`micro_runtime`)

### 3.3 Planned extensions

- JIT dump and code-size collection
- verifier/load/JIT segmented statistics
- real-world corpus ingestion

## 4. Workload Design

### 4.1 Current micro corpus

- `micro_pure_jit`: 22 cases spanning `baseline`, `alu-mix`, `control-flow`, `memory-local`, `dependency-ilp`, `loop-shape`, and `call-size`
- `micro_runtime`: map-backed `map_lookup_churn` and `map_roundtrip`
- representative pure-jit families currently include `popcount`, `log2-fold`, `dep-chain`, `multi-acc`, `fixed-loop`, `stride-load`, `bounds-density`, `branch-skew`, `switch-dispatch`, `search`, and `code-clone`
- each benchmark carries declarative `family`, `level`, and `hypothesis` metadata for table/figure generation

### 4.2 Planned synthetic factors

- helper-heavy variants
- map-heavy variants
- verifier-constrained variants
- tail-call and multi-program variants
- local `bpf-to-bpf` call-chain variants once the `llvmbpf` ELF loader supports subprogram-call objects in the default path

### 4.3 Planned real-world corpus

- BCC `libbpf-tools`
- Katran
- Tetragon
- Cilium datapath subsets
- XDP examples
- libbpf-bootstrap examples
- sched_ext samples

## 5. Preliminary Findings

### 5.1 Measurement support already available

- unified runtime comparison
- phase timing
- optional `perf_event_open` counters
- machine-readable JSON output
- RQ-oriented markdown summary generation

### 5.2 Current limitations

- hardware counters are best-effort and can be zero on short windows or restricted PMU setups
- code-size, JIT dump, and verifier breakdown are not yet collected
- real-world corpus ingestion is only at the first-wave stage

### 5.3 Preliminary pilot observations

- On the current 22-case `micro_pure_jit` suite, the raw geometric mean still slightly favors kernel parity (`1.06x` `llvmbpf/kernel`), but the baseline-adjusted geometric mean favors `llvmbpf` (`0.68x`, 95% bootstrap CI `[0.54x, 0.84x]`).
- `llvmbpf` is strongest on `control-flow` and much of `memory-local`; `dependency-ilp`, `loop-shape`, and the new `code-clone` family are near parity or slightly kernel-leading.
- `llvmbpf` compile time is still typically slower than kernel load/JIT time on this host, which means execution-only wins do not automatically translate to load-path wins.
- The first-wave real-world corpus currently inventories 124 candidate program sources across `xdp-examples`, `bcc`, `katran`, `tetragon`, `cilium`, and `libbpf-bootstrap`.

## 6. Artifact Status

This draft tracks the implementation status of the framework and will be filled in iteratively as data arrives.

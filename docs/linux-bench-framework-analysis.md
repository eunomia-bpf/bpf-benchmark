# Linux Kernel BPF Benchmark Framework & Infrastructure Analysis

## Overview

The Linux kernel ships a comprehensive BPF benchmark framework located at
`tools/testing/selftests/bpf/`. It provides a generic, plugin-based runner
for measuring BPF subsystem performance with fine-grained control over
threading, CPU placement, and measurement collection.

This document covers both the **benchmark framework** and the **underlying kernel BPF infrastructure** that supports it.

## Architecture

### Entry Point

`tools/testing/selftests/bpf/bench.c` — the main benchmark runner.

```
bench.c (main)
  ├─ Parse CLI arguments (-d duration, -p producers, -c consumers, -a affinity)
  ├─ Lookup benchmark by name from benchs[] registry
  ├─ Call bench->validate() and bench->setup()
  ├─ Spawn producer/consumer pthreads
  ├─ SIGALRM-based 1-second interval timer for measurement collection
  ├─ Warmup period (default 1s), then measurement period (default 5s)
  └─ Call bench->report_final() with all samples (excluding warmup)
```

### Core Data Structures (bench.h)

```c
struct bench {
    const char *name;
    const struct argp *argp;              // benchmark-specific CLI options
    void (*validate)(void);
    void (*setup)(void);
    void *(*producer_thread)(void *ctx);
    void *(*consumer_thread)(void *ctx);
    void (*measure)(struct bench_res *res);
    void (*report_progress)(int iter, struct bench_res *res, long delta_ns);
    void (*report_final)(struct bench_res res[], int res_cnt);
};

struct bench_res {
    long hits;
    long drops;
    long false_hits;
    long important_hits;
    unsigned long gp_ns;       // grace period nanoseconds
    unsigned long gp_ct;       // grace period count
    unsigned int stime;        // system time ticks
    unsigned long duration_ns;
};

struct env {
    char *bench_name;
    int duration_sec;          // default: 5
    int warmup_sec;            // default: 1
    int consumer_cnt;          // default: 0
    int producer_cnt;          // default: 1
    bool affinity, verbose, quiet, list;
    struct cpu_set prod_cpus, cons_cpus;
};
```

### Key Design Patterns

- **Lock-free measurements**: 128-byte aligned atomic counters per producer (cache-line isolation)
- **Producer/Consumer model**: flexible thread topology per benchmark
- **Modular BPF programs**: each benchmark has a BPF skeleton in `progs/`
- **Standardized reporting**: mean + stddev, multiple output formats (hits/drops, ops/sec, false positive rate, latency)

### Adding a New Benchmark

1. Create `benchs/bench_xxx.c` defining `const struct bench bench_xxx`
2. Add `extern` declaration in `bench.c`
3. Append `&bench_xxx` to `benchs[]` array
4. Write corresponding BPF program in `progs/xxx_bench.c`
5. Update Makefile

## Existing Benchmarks (17 files, 70+ tests)

### Baseline / Counting
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_count.c` | count-global, count-local | Atomic counter increments (shared vs per-producer) |

### Trigger / Attach Overhead
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_trigger.c` | ~40 variants | kprobe, kretprobe, kprobe-multi, fentry, fexit, fmodret, rawtp, tp, uprobe, uretprobe, uprobe-multi — measures program trigger latency |
| `bench_rename.c` | rename-base/kprobe/kretprobe/rawtp/fentry/fexit | Overhead of different attach types on sys_renameat2 |

### Data Structures
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_bloom_filter_map.c` | bloom-lookup, bloom-update, bloom-false-positive, hashmap-without-bloom, hashmap-with-bloom | Bloom filter map operations and false-positive rate |
| `bench_bpf_hashmap_lookup.c` | bpf-hashmap-lookup | Hash map lookup with configurable key size, flags, entries |
| `bench_bpf_hashmap_full_update.c` | bpf-hashmap-full-update | Full hash map update performance |
| `bench_lpm_trie_map.c` | lpm-trie-{noop,baseline,lookup,insert,update,delete,free} | LPM trie operations with configurable entries and prefix length |

### Local Storage
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_local_storage.c` | local-storage-cache-{seq,interleaved,hashmap}-get | Sequential/interleaved access patterns, hashmap control |
| `bench_local_storage_create.c` | local-storage-create | Socket/task local storage creation |
| `bench_local_storage_rcu_tasks_trace.c` | local-storage-tasks-trace | RCU tasks trace slowdown measurement |

### Event Delivery
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_ringbufs.c` | rb-libbpf, rb-custom, pb-libbpf, pb-custom | Ring buffer and perf buffer throughput |

### Helpers
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_bpf_loop.c` | bpf-loop | `bpf_loop()` helper performance |
| `bench_strncmp.c` | strncmp-no-helper, strncmp-helper | `bpf_strncmp()` vs hand-written comparison |

### Memory
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_htab_mem.c` | htab-mem (overwrite, batch_add_batch_del, add_del_on_diff_cpu) | Hash table memory usage patterns |

### Crypto
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_bpf_crypto.c` | crypto-encrypt, crypto-decrypt | AES encryption/decryption |

### Network / Socket
| File | Benchmarks | Description |
|------|-----------|-------------|
| `bench_sockmap.c` | fw-{rx,tx}-{normal,pass,verdict-egress,verdict-ingress} | Socket map redirection |

## CLI Usage

```bash
# List all benchmarks
sudo ./bench -l

# Run with 8 producers, CPU affinity, 10 seconds
sudo ./bench -p8 -a -d10 count-local

# Ring buffer: 1 producer, 1 consumer
sudo ./bench -p1 -c1 rb-libbpf

# Bloom filter with custom parameters
sudo ./bench --nr_entries=10000 bloom-lookup
```

## Helper Scripts

Located in `benchs/run_*.sh`:
- `run_bench_trigger.sh` — all trigger benchmarks with varying producer counts
- `run_bench_ringbufs.sh` — ring buffer configurations
- `run_bench_bloom_filter_map.sh` — bloom filter suite
- `run_common.sh` — shared shell helpers

## Linux Kernel BPF Infrastructure (kernel-side)

The kernel BPF subsystem is massive (~69 source files in `kernel/bpf/`). Here are the key components relevant to benchmarking:

### Core Kernel Files (`kernel/bpf/`)

| File | Lines | Purpose |
|------|-------|---------|
| `verifier.c` | 26,169 | BPF program verifier (largest file in BPF subsystem) |
| `syscall.c` | 6,595 | BPF syscall interface (prog load, map create, etc.) |
| `helpers.c` | 4,754 | BPF helper function implementations |
| `core.c` | 3,367 | BPF interpreter and core runtime |
| `hashtab.c` | 2,737 | Hash table map implementation |
| `trampoline.c` | 1,387 | BPF trampoline for fentry/fexit/fmod_ret |
| `ringbuf.c` | - | Ring buffer map implementation |
| `bloom_filter.c` | - | Bloom filter map |
| `lpm_trie.c` | - | Longest-prefix-match trie map |
| `arraymap.c` | - | Array map implementation |
| `stackmap.c` | - | Stack trace map |
| `cpumap.c` / `devmap.c` | - | XDP redirect maps |
| `dispatcher.c` | - | BPF dispatcher (direct call optimization) |
| `memalloc.c` | - | BPF memory allocator |
| `arena.c` | - | BPF arena (shared memory) |
| `crypto.c` | - | BPF crypto subsystem |

### BPF_PROG_TEST_RUN (`net/bpf/test_run.c`, 1,844 lines)

The kernel mechanism that allows running BPF programs from userspace for testing/benchmarking:

```c
struct bpf_test_timer {
    u32 i;
    u64 time_start, time_spent;
};
```

Supported test run functions:
- `bpf_prog_test_run_skb()` — Run with skb (network packet) context
- `bpf_prog_test_run_xdp()` — Run with XDP context
- `bpf_prog_test_run_tracing()` — Run tracing programs
- `bpf_prog_test_run_raw_tp()` — Run raw tracepoint programs
- `bpf_prog_test_run_flow_dissector()` — Run flow dissector
- `bpf_prog_test_run_sk_lookup()` — Run socket lookup
- `bpf_prog_test_run_syscall()` — Run syscall-type programs
- `bpf_prog_test_run_nf()` — Run netfilter programs

This is used by microsoft/bpf_performance and other benchmark tools via `bpf_prog_test_run_opts()`.

### JIT Compilers (`arch/*/net/`)

| Architecture | File | Lines |
|-------------|------|-------|
| x86-64 | `arch/x86/net/bpf_jit_comp.c` | 4,110 |
| x86-32 | `arch/x86/net/bpf_jit_comp32.c` | - |
| ARM64 | `arch/arm64/net/bpf_jit_comp.c` | 3,202 |

### Userspace Libraries (`tools/lib/bpf/`)

**libbpf** — the standard userspace BPF library (~40 source files, libbpf.c alone is 399KB):

Key files:
- `libbpf.c` / `libbpf.h` — Main library (program/map loading, attach)
- `bpf.c` / `bpf.h` — Low-level BPF syscall wrappers
- `bpf_helpers.h` — BPF program-side helper declarations
- `bpf_tracing.h` — Tracing attach macros (SEC, BPF_PROG, etc.)
- `bpf_core_read.h` — CO-RE (Compile Once, Run Everywhere) read macros
- `btf.c` / `btf.h` — BTF (BPF Type Format) handling
- `ringbuf.c` — Ring buffer handling
- `usdt.c` — USDT tracing support
- `features.c` — Kernel feature detection

**Benchmarking API** (`bpf_prog_test_run_opts`):
```c
struct bpf_test_run_opts {
    const void *data_in;       // Input data
    void *data_out;            // Output data
    __u32 data_size_in/out;
    const void *ctx_in;        // Input context
    void *ctx_out;             // Output context
    __u32 retval;              // Program return code
    int repeat;                // Iteration count
    __u32 duration;            // Out: nanoseconds per repetition
    __u32 cpu;                 // CPU to run on
    __u32 batch_size;          // Batch processing size
};
```

Other benchmarking-related APIs:
- `bpf_enable_stats(enum bpf_stats_type)` — Enable BPF performance stats collection
- `bpf_prog_get_info_by_fd()` — Get program info (JIT size, verified insns, etc.)
- `bpf_map_get_info_by_fd()` — Get map info

### BPF Tools (`tools/bpf/`)

- `bpftool/` — Swiss-army knife for BPF (inspect progs/maps, dump JIT, profile)
- `bpf_asm.c` — Classic BPF assembler
- `bpf_dbg.c` — Classic BPF debugger
- `bpf_jit_disasm.c` — JIT disassembler
- `resolve_btfids/` — BTF ID resolution tool

### Selftests Infrastructure (`tools/testing/selftests/bpf/`)

| Component | Count/Size | Description |
|-----------|-----------|-------------|
| `progs/` | **948 files** | BPF program source files (15 are bench-specific) |
| `prog_tests/` | **420 files** | Individual test cases for test_progs |
| `test_progs.c` | 2,124 lines | Main test runner framework |
| `bench.c` | 788 lines | Benchmark runner framework |
| `benchs/` | 17 bench_*.c + 12 run_*.sh | Benchmark implementations |
| `veristat.c` | ~84 KB | Verifier statistics analyzer (A/B comparison) |
| `Makefile` | 923 lines | Build system |

**test_progs framework** (`test_progs.c`):
- Generic test runner with 45+ assertion macros (`ASSERT_EQ`, `ASSERT_OK`, `ASSERT_STREQ`, etc.)
- Multi-process worker execution support
- Watchdog timer for stalled tests
- JSON output support
- Test whitelist/blacklist filtering
- `RUN_TESTS()` macro for skeleton-based tests

**veristat** — Verifier statistics tool:
- Compares verification stats between kernel versions (A/B testing)
- Filters/orders by instruction count, states, peak states
- CSV output for programmatic analysis

### Benchmark Run Scripts

| Script | Description |
|--------|-------------|
| `run_bench_trigger.sh` | All trigger types with varying producer counts |
| `run_bench_ringbufs.sh` | Ring buffer configurations |
| `run_bench_bloom_filter_map.sh` | Bloom filter suite |
| `run_bench_strncmp.sh` | String comparison |
| `run_bench_rename.sh` | Rename attach overhead |
| `run_bench_bpf_loop.sh` | bpf_loop helper |
| `run_bench_bpf_hashmap_full_update.sh` | Hashmap full update |
| `run_bench_htab_mem.sh` | Hash table memory |
| `run_bench_local_storage.sh` | Local storage access |
| `run_bench_local_storage_rcu_tasks_trace.sh` | RCU tasks trace |
| `run_bench_uprobes.sh` | Uprobe benchmarks |
| `run_common.sh` | Shared shell helpers |

---

## This Repo: eunomia-bpf/bpf-benchmark

### Focus
Compares **userspace eBPF runtime** performance across 7 implementations:
- `llvm-jit` (bpftime LLVM JIT) — consistently fastest
- `ubpf-jit` / `ubpf-vm` (iovisor/ubpf)
- `rbpf-jit` / `rbpf-vm` (Rust rbpf)
- `<NATIVE>` (compiled C baseline)
- `<WASM>` (Wasmtime WebAssembly)

### Test Programs (8 tests)

| Program | Category | Description |
|---------|----------|-------------|
| `simple.bpf.c` | Baseline | Return constant (absolute minimum) |
| `memory_a_plus_b.bpf.c` | Trivial memory | Read 2 values, return sum |
| `log2_int.bpf.c` | Integer compute | Binary log over 8192 integers |
| `prime.bpf.c` | Complex math | Brute-force prime sieve 1-10000 |
| `memcpy.bpf.c` | Memory bandwidth | Copy 1MB buffer |
| `strcmp_fail.bpf.c` | String (early exit) | Mismatch mid-comparison |
| `strcmp_full.bpf.c` | String (full match) | Full string traversal |
| `switch.bpf.c` | Branching | 64-case switch statement |

### Framework
- **Runner**: `run_benchmark.py` — runs each test 10x per runtime, collects stats
- **Build**: `bpf_progs/Makefile` — compiles `.bpf.c` → `.bpf.bin` (eBPF), `.native`, `.wasm`
- **Output**: JSON (`data.json`) + matplotlib PNG charts (compilation time, execution time)
- **Metrics**: avg, median, min, max, distribution per test per runtime

## Third-Party Projects

See `third-party/` directory and `third-party/README.md` for detailed analysis:

| Project | Focus |
|---------|-------|
| [microsoft/bpf_performance](https://github.com/microsoft/bpf_performance) | Cross-platform BPF helper function perf measurement (60+ tests, YAML-driven) |
| [pchaigno/tail-call-bench](https://github.com/pchaigno/tail-call-bench) | BPF tail call chain cost (0-33 depth, multi-kernel) |
| [aspsk/bpf-bench](https://github.com/aspsk/bpf-bench) | Hash function cycles + hashmap lookup perf (kernel module, cycle-precise) |

## Cross-Project Comparison

| Feature | Linux kernel bench | bpf_performance | tail-call-bench | bpf-bench | This repo |
|---------|-------------------|-----------------|-----------------|-----------|-----------|
| Platform | Linux | Linux+Windows | Linux | Linux | Linux |
| Config | C code | YAML | Ansible | Shell | Python |
| Focus | All BPF subsystems | BPF helpers & maps | Tail call cost | Hash/hashmap | Userspace runtimes |
| Output | Stdout (ops/sec) | CSV+Grafana | JSON | Text+PNG | JSON+PNG |
| Threading | Multi-thread | Per-CPU | Single | Single | Single |
| Test count | 70+ | 60+ | 34 depths | ~10 | 8x7 runtimes |
| Unique | Most comprehensive | Cross-platform | Multi-kernel | Cycle-precise | Runtime comparison |

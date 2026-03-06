# Third-Party BPF Benchmark Projects

## 1. microsoft/bpf_performance

**Focus**: Cross-platform (Linux + Windows) BPF helper function performance measurement.

### Architecture
- **Runner**: `bpf_performance_runner` (C++20), reads YAML test definitions
- **Tests defined in**: `bpf/tests.yml` (60+ tests, declarative YAML)
- **BPF programs**: `bpf/*.c` compiled with clang to `.o` (Linux) or `.sys` (Windows)
- **Output**: CSV with per-CPU nanosecond timings + Grafana dashboards

### Test Categories (60+ tests)

| Category | Tests |
|----------|-------|
| Baseline | Harness overhead measurement |
| Helpers | bpf_get_prandom_u32, bpf_ktime_get_ns, bpf_ktime_get_boot_ns, bpf_get_smp_processor_id |
| Array Maps | BPF_MAP_TYPE_ARRAY, PERCPU_ARRAY (read/update/replace) |
| Hash Maps | HASH, PERCPU_HASH, LRU_HASH, LRU_PERCPU_HASH (read/update/replace + concurrent) |
| LPM Trie | 1K/16K/256K/1M entries x read/update/replace |
| Nested Maps | array_of_maps, hash_of_maps (read/update) |
| Ring Buffer | Variable record sizes (128KB, 400B x 300K, 1420B x 100K) |
| Tail Calls | 5-level and 35-level chains |
| LRU Rolling | 10% working set simulation |

### Unique Features
- **YAML-driven**: Add tests without code changes
- **Per-program CPU assignment**: Enables concurrent read/write within single test
- **Map state preparation phase**: Separate init from measurement
- **Grafana integration**: Built-in dashboards for trend tracking
- **Cross-platform**: Linux + Windows via eBPF-for-Windows

### Build
```bash
cmake -B build && cmake --build build
# Run: build/bin/bpf_performance_runner build/bin/tests.yml
```

---

## 2. pchaigno/tail-call-bench

**Focus**: Measuring the cost of BPF tail call chains at varying depths.

### Architecture
- **BPF program** (`image/kern.c`): 34 programs chained via `bpf_tail_call()`
- **Runner** (`image/run.sh`): Compiles BPF, loads programs, runs `bpftool prog run`
- **Orchestration**: Ansible playbook + Docker for remote multi-kernel testing
- **Output**: JSON array of nanosecond values per chain length (0-33)

### How It Works
1. Ansible installs target kernel + Docker on remote servers
2. Docker container compiles and loads BPF tail-call chain programs
3. `BPF_PROG_TEST_RUN` measures execution time per chain depth
4. Results collected for multiple kernel versions and retpoline configs

### Key Results
- Published at: https://pchaigno.github.io/ebpf/2021/03/22/cost-bpf-tail-calls.html
- Measures per-tail-call overhead across kernel versions

### Run
```bash
ansible-playbook -v -i hosts.ini -e nb_runs=100 -e nb_measures=10 playbook.yaml
```

---

## 3. aspsk/bpf-bench

**Focus**: Hash function benchmarking and BPF hashmap performance analysis.

### Components

#### BBBench (Hash Functions)
- **Kernel module** (`bbbench/bbbench.c`): Measures CPU cycles per hash operation
- **Hash functions tested**: jhash, jhash2, xxh3, xxh32, xxh64, bpf
- **Precision**: RDTSCP+LFENCE, interrupt-disabled, 333x50x50 samples
- **Output**: Text data + matplotlib PNG plots

#### Hashmap Bench
- **Wraps Linux kernel's `bench bpf-hashmap-lookup`** selftest
- **Two axes**: Map fullness (10-100%) and key size (4-64 bytes)
- **Compares**: Original vs patched hash functions via map_flags
- **Output**: M ops/sec plots

#### Stack-Trace Map (WIP)
- Kernel module creating 31-level deep call stacks for trace benchmarking

### Key Design
- Uses kernel sysfs interface for measurement control
- Statistical rigor: variance, stddev, spurious value detection
- Requires: fixed CPU frequency, SMT off, turbo boost off

---

## Comparison Matrix

| Feature | bpf_performance | tail-call-bench | bpf-bench | Linux bench | eunomia bpf-benchmark |
|---------|----------------|-----------------|-----------|-------------|----------------------|
| Platform | Linux+Windows | Linux | Linux | Linux | Linux |
| Config | YAML | Ansible | Shell | C code | Python |
| Focus | BPF helpers & maps | Tail call cost | Hash/hashmap | All BPF subsystems | Userspace runtimes |
| Output | CSV+Grafana | JSON | Text+PNG | Stdout (ops/sec) | JSON+PNG |
| Threading | Per-CPU | Single | Single | Multi-thread | Single |
| Tests | 60+ | 34 depths | ~10 | 70+ | 8 programs x 7 runtimes |
| Kernel module | No | No | Yes (bbbench) | No | No |
| Unique | Cross-platform | Multi-kernel | Cycle-precise | Comprehensive | Runtime comparison |

# BPF Benchmark

eBPF benchmarking suite for the BpfReJIT paper — comparing llvmbpf (userspace LLVM JIT) against kernel eBPF with and without ReJIT.

Active benchmarking pipeline:

- `micro/`: isolated micro-benchmarks driven by `bpf_prog_test_run_opts`
- `corpus/`: real-world program collection, measurement, and analysis

The historical multi-runtime userspace benchmark layer has been removed; the active tree is `micro/`, `corpus/`, `runner/`, and `daemon/`.

Execution architecture for the runner image, runtime containers, and
host-kernel boundaries lives in
[`docs/benchmark-runtime-architecture.md`](docs/benchmark-runtime-architecture.md).

## Repository Layout

```text
bpf-benchmark/
├── runner/                # Target/suite contracts, executors, shared libs, and micro_exec
├── micro/                 # Isolated micro-benchmark suites, drivers, and inputs
├── corpus/                # Real-world corpus, fetch/build, and measurement
├── daemon/                # Userspace BPF daemon (bpfrejit-daemon CLI)
├── config/                # YAML benchmark suite manifests (micro_pure_jit.yaml etc.)
├── tests/                 # Userspace/kernel self-tests
├── docs/                  # Research plans, reports, and temporary experiment notes
└── vendor/                # Vendored kernel (linux-framework) + tooling dependencies
```

## Prerequisites

- Python 3 with PyYAML: `pip install pyyaml` (or use the workspace venv)
- `docker` for runner image builds and runtime containers
- runnable `linux/amd64` and `linux/arm64` container userspace support when
  building both target architectures
- `sudo -n` (passwordless) required for kernel eBPF runtime
- `vng` (virtme-ng) required for VM benchmark targets

## Quick Start

```bash
git submodule update --init --recursive
source /home/yunwei37/workspace/.venv/bin/activate   # workspace venv (optional)

# Local static validation
make check

# Full micro benchmark suite in VM
make vm-micro

# Show all targets and parameters
make help
```

## Running Benchmarks

**The root `Makefile` is the only supported entrypoint. Do not invoke
`cargo run`, `docker run`, or any component binary directly. Every benchmark
must go through `make <target>`.**

```bash
make vm-micro                        # full micro suite in VM
make vm-micro BENCH="simple bitcount"
make vm-micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
make vm-corpus                       # corpus benchmark, all 7 supported apps
make vm-corpus SAMPLES=5
make vm-selftest                     # kernel selftests
make vm-negative-test                # negative tests
make vm-test                         # full test suite (selftest + negative + repo units)
make vm-all                          # vm-test + vm-micro + vm-corpus
make aws-arm64-selftest              # AWS ARM64 selftest only
make aws-arm64-test                  # AWS ARM64 full test
make aws-arm64-micro                 # AWS ARM64 micro benchmark
make aws-arm64-corpus                # AWS ARM64 corpus benchmark
make aws-x86-selftest                # AWS x86 variants
make aws-x86-test
make aws-x86-micro
make aws-x86-corpus
make aws-corpus                      # auto-pick arm64/x86 by RUN_TARGET_ARCH
```

### Per-app filtering (corpus)

Restrict to a subset of the 7 supported apps (bcc/set, otelcol-ebpf-profiler,
cilium/agent, tetragon/observer, katran, tracee/monitor, bpftrace/set):

```bash
# Single app
BPFREJIT_CORPUS_APPS="tetragon/observer" make vm-corpus

# Multiple apps (comma- or space-separated)
BPFREJIT_CORPUS_APPS="cilium/agent,tracee/monitor" make vm-corpus
```

### Per-pass override (corpus / micro)

Override which bpfopt passes run, comma-separated. Default is the policy in
`corpus/config/benchmark_config.yaml`. Set to `"default"` to use the yaml
explicitly.

```bash
# Only noop + map_inline
BPFREJIT_BENCH_PASSES="noop,map_inline" make vm-corpus

# Only kinsn-class passes
BPFREJIT_BENCH_PASSES="wide_mem,rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch" \
    make vm-corpus

# Combine with per-app + sample count
BPFREJIT_CORPUS_APPS="tetragon/observer" \
BPFREJIT_BENCH_PASSES="noop,map_inline" \
SAMPLES=3 \
    make vm-corpus
```

Pass list reference (current `corpus/config/benchmark_config.yaml`):
- **kinsn-class**: `wide_mem`, `rotate`, `cond_select`, `extract`,
  `endian_fusion`, `bulk_memory`, `prefetch`
- **bytecode rewriting**: `noop` (state producer), `map_inline`, `const_prop`,
  `dce`, `bounds_check_merge`, `skb_load_bytes_spec`
- **profile-guided** (not in default policy): `branch_flip`

### Workdir retention

Workdir tarballs are discarded by default to keep `result.json` small. Enable
retention to inspect raw verifier logs and per-pass bytecode:

```bash
# Retain tarballs for programs that hit a real ReJIT failure
KEEP_WORKDIRS=1 make vm-corpus

# Force-capture every prog's workdir (useful for debugging successful progs;
# uses BPFREJIT_KEEP_ALL_WORKDIRS=1 internally to deliberately fail steps so
# the daemon emits tars for all)
KEEP_WORKDIRS=all make vm-corpus

# Tarballs land in: corpus/results/<run_dir>/details/failure-artifacts/<prog_id>.tar.gz
```

AWS targets require explicit local configuration for:
- `AWS_ARM64_KEY_NAME` / `AWS_X86_KEY_NAME`
- `AWS_ARM64_KEY_PATH` / `AWS_X86_KEY_PATH`
- `AWS_ARM64_SECURITY_GROUP_ID` / `AWS_X86_SECURITY_GROUP_ID`
- `AWS_ARM64_SUBNET_ID` / `AWS_X86_SUBNET_ID`
- `AWS_ARM64_PROFILE` / `AWS_X86_PROFILE`

The canonical lookup source is:
- process environment only

Micro suite runner builds use the LLVM CMake package in the runner image by
default. Override it for targeted debugging with:
- `LLVM_DIR`, or
- `RUN_LLVM_DIR`

Results are written to:
- `micro/results/` — authoritative micro benchmark results
- `corpus/results/` — authoritative corpus benchmark results
- `docs/tmp/` — analysis reports (.md only, never JSON results)

Executor logs and transient staging state still live under `.cache/`, but those
directories are not benchmark result roots.

The root `Makefile` surface is reserved for canonical run/validation entrypoints,
plus a small developer helper surface for direct kernel/module lifecycle work.
Active local prep/build flows through real Make targets resolved by the Python
runner libraries. User-space artifacts are built inside `runner-runtime` during
Dockerfile build. Host-coupled kernel/module artifacts are exported through
`docker build --target runner-host-artifacts --output`. Benchmark execution
loads and runs the same `runner-runtime` image with privileged suite containers.

## Layer Notes

`runner/` owns target/suite contracts under `runner/targets/` and `runner/suites/`, the shared `micro_exec` C++ runner, and Python executors/orchestrators under `runner/libs/`.

`micro/` owns the isolated benchmark manifests (`micro/config/micro_pure_jit.yaml`), input generators, and the Python suite driver (`micro/driver.py`).

`corpus/` owns the real-world corpus, fetch/build tooling, declarative app suites in `corpus/config/`, and the measurement entrypoint in `corpus/driver.py`.

`daemon/` is the userspace front end for BpfReJIT: it scans live BPF programs via `BPF_PROG_GET_NEXT_ID`, identifies optimization sites, and triggers `BPF_PROG_REJIT`. See `daemon/README.md`.

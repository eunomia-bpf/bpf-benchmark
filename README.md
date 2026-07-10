# bpf-bench

Auto-research framework and benchmark for agentic OS kernel extension
optimization.

`bpf-bench` frames eBPF optimization as a closed-loop search problem for LLM
agents. Agents choose optimization actions, the framework executes those actions
against real applications and workloads in isolated Docker/KVM/AWS environments,
and each iteration returns verifier, JIT, workload, and performance feedback for
the next decision.

This repository is the execution substrate and artifact workspace for the
`bpf-bench` paper draft in
[`docs/ebpf27-bpfoptbench/`](docs/ebpf27-bpfoptbench/). It also provides the
artifact and evaluation harness for the Kops paper,
[`Kops: Safely Extending the eBPF Compilation Pipeline with Native Operations`](docs/paper/main.tex).
The current `bpf-bench` instantiation covers six production eBPF applications,
146 comparable BPF program measurements, and 42 microbenchmark tasks, with
correctness and integrity checks designed to prevent reward hacking.

## Branch Discipline

This experimental repository develops directly on `master`. Do not create or
switch to task branches; completed work should land on `origin/master`.

## What It Benchmarks

eBPF optimization is difficult because the useful action depends on verifier
constraints, kernel version, architecture, runtime state, workload behavior, and
application semantics. A pass that improves one program can regress another, and
static rewrite counts do not reliably predict speedup.

`bpf-bench` evaluates whether agents can make better optimization decisions
under the real oracle:

- verifier acceptance and rejection logs
- JIT output size and emitted-code changes
- application lifecycle success or failure
- workload correctness and raw workload metrics
- per-program BPF run counters before and after optimization
- cross-iteration history for adaptive exploration

The benchmark action space spans multiple layers:

- source-level application/eBPF changes
- LLVM and BPF bytecode transformations
- post-load bytecode policy selection through `bpfopt`
- kernel JIT and Kops-backed native-operation choices
- suite-wide, per-app, and per-program policy selection

`bpfopt` and Kops-backed native operations are action backends in this
repository, but the `bpf-bench` contribution is broader: a benchmark and
auto-research framework for agentic eBPF optimization under real verifier, JIT,
application, and workload feedback.

## Benchmark Corpus

The production corpus uses real application loaders. The framework does not
replace upstream binaries with simplified loaders and does not load `.bpf.o`
files directly for corpus apps.

Supported corpus applications:

- `bcc/set`
- `otelcol-ebpf-profiler/profiling`
- `cilium/agent`
- `tetragon/observer`
- `katran`
- `tracee/monitor`

Microbenchmarks isolate pure-bytecode execution, helpers, maps, packet parsing,
branch behavior, and architecture-sensitive lowering under
`BPF_PROG_TEST_RUN`.

## Repository Layout

```text
bpf-benchmark/
├── docs/ebpf27-bpfoptbench/  # bpf-bench paper draft, figures, and analyses
├── runner/                   # Make-backed suites, executors, images, libs
├── corpus/                   # Production app corpus, workloads, results
├── micro/                    # Microbenchmark programs, configs, results
├── bpfopt/                   # Bytecode optimizer, loader, target probing tools
├── module/                   # Kops native-operation modules for x86 and arm64
├── analysis/                 # Post-hoc analysis utilities
├── tests/                    # Selftests and negative tests
├── docs/                     # Design notes, reports, and paper material
└── vendor/                   # Vendored kernel, libbpf, llvmbpf, app deps
```

The low-level optimizer design notes are documented under [`docs/tmp/`](docs/tmp/).
Runtime image layering and host/runtime boundaries are documented in
[`runner/containers/README.md`](runner/containers/README.md).

## Prerequisites

- Python 3 with PyYAML: `pip install pyyaml`
- `docker` for runner image builds and runtime containers
- `sudo -n` for privileged kernel eBPF runtime setup
- `vng` (virtme-ng) for the default local x86 KVM target
- AWS credentials only when using `PLATFORM=aws`

## Quick Start

```bash
git submodule update --init --recursive

# Static validation and tests through the supported Makefile entrypoint.
make check

# Local x86 KVM micro benchmark suite.
make micro
```

## Running Benchmarks

The root `Makefile` is the only supported benchmark entrypoint. Run suites with
`make <target>` so build dependencies, runtime images, KVM/AWS dispatch, and
artifact paths stay consistent.

```bash
make micro                           # local x86 KVM micro suite
make micro BENCH="simple bitcount"
make micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10

make corpus                          # local x86 KVM corpus, all supported apps
make corpus SAMPLES=3

make selftest                        # kernel selftests
make negative-test                   # negative tests
make test                            # full test suite
make all                             # test + micro + corpus
make terminate                       # terminate managed remote instances

PLATFORM=aws ARCH=x86 make test
PLATFORM=aws ARCH=arm64 make test
PLATFORM=aws ARCH=arm64 make micro
PLATFORM=aws ARCH=arm64 make corpus
```

Supported suite targets are `selftest`, `negative-test`, `test`, `micro`,
`corpus`, `all`, and `terminate`. `PLATFORM=kvm` with `ARCH=x86` is the local
default. AWS runs use `PLATFORM=aws` with `ARCH=x86` or `ARCH=arm64`.

### Corpus App Selection

Targeted corpus runs use the app names in
[`corpus/config/macro_apps.yaml`](corpus/config/macro_apps.yaml). Keep targeted
experiments routed through the root `Makefile` so app startup, workload setup,
runtime image selection, and artifact paths stay consistent.

```bash
# Full production corpus.
make corpus
```

### Pass Selection

The default pass policy lives in
[`corpus/config/benchmark_config.yaml`](corpus/config/benchmark_config.yaml).
Targeted pass experiments should still go through the root `Makefile`; use the
suite environment knobs defined there rather than invoking optimizer binaries
directly.

```bash
make corpus SAMPLES=3
```

Pass families currently include:

- Kops-backed native-operation passes: `kinsn`, `rotate`, `cond_select`,
  `ccmp`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch`
- bytecode rewriting passes: `noop`, `wide_mem`, `map_inline`, `const_prop`,
  `dce`, `bounds_check_merge`, `skb_load_bytes_spec`
- profile-guided opt-in pass: `branch_flip`

`branch_flip` requires real per-site PMU profile input and is not part of the
default runner policy.

### Workdir Retention

Workdir tarballs are discarded by default. Enable retention to inspect raw
verifier logs and per-pass bytecode for programs that hit real optimization
failures:

```bash
KEEP_WORKDIRS=1 make corpus
```

Tarballs are written under
`corpus/results/<run_dir>/details/failure-artifacts/<prog_id>.tar.gz`.

## Result Contract

The benchmark framework writes raw measurements only. `result.json` preserves
per-program baseline and post-optimization kernel counters such as
`run_cnt_delta`, `run_time_ns_delta`, `id`, `name`, `type`, `bytes_jited`, and
`bytes_xlated`, plus workload stdout/stderr, lifecycle events, app status, and
error strings.

Raw app-side workload fields may also be preserved under each phase's workload
payload. Aggregation, ratios, averages, geomeans, confidence intervals, success
scores, and markdown performance rollups belong in external analysis scripts,
not in the benchmark runner.

Results are written to:

- `micro/results/`
- `corpus/results/`
- `docs/tmp/` for analysis reports only, not raw JSON results

Executor logs and transient staging state live under `.cache/`; those
directories are not benchmark result roots.

## Agent Integrity Model

Paper experiments treat agents as untrusted optimizers. Agents should interact
with the benchmark through `make` targets, not by editing workloads, shortening
durations, filtering failed programs, bypassing application loaders, or
fabricating result files. The framework records raw artifacts so external
analysis can decide whether an action is accepted, correct, faster, noisy, or
invalid.

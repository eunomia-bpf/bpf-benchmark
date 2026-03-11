# BPF Benchmark

This repository now follows a three-layer layout for the active benchmarking pipeline:

- `micro/`: isolated micro-benchmarks driven by `bpf_prog_test_run_opts`
- `corpus/`: real-world program collection, measurement, and analysis
- `e2e/`: end-to-end deployment benchmarks and case-specific assets

Legacy material that is no longer part of the active pipeline lives under `legacy/`.

## Repository Layout

```text
bpf-benchmark/
├── micro/                 # Isolated micro-benchmark suites + shared orchestrator
├── corpus/                # Real-world corpus configs, fetch/build, measurement, analysis
├── e2e/                   # End-to-end workloads, case assets, and result placeholders
├── legacy/                # Inactive historical benchmark code and third-party snapshots
├── docs/                  # Research plans, reports, and temporary experiment notes
├── scanner/               # Offline directive scanner
└── vendor/                # Vendored kernel / tooling dependencies
```

## Quick Start

Initialize submodules, activate the shared virtualenv used in this workspace, and build the micro layer:

```bash
git submodule update --init --recursive
source /home/yunwei37/workspace/.venv/bin/activate
make -C micro
```

List the current micro suite and run the minimal smoke benchmark:

```bash
python3 micro/run_micro.py --list
python3 micro/run_micro.py --bench simple --runtime llvmbpf --iterations 1 --warmups 0 --repeat 10
python3 micro/run_micro.py --bench simple --runtime kernel --iterations 1 --warmups 0 --repeat 10
```

The kernel runtime command requires passwordless `sudo -n`.

Build the standalone scanner CLI required by `corpus/` recompile paths and `e2e/`:

```bash
cmake -S scanner -B scanner/build -DCMAKE_BUILD_TYPE=Release
cmake --build scanner/build --target bpf-jit-scanner -j
```

Check the higher-level entrypoints:

```bash
python3 micro/driver.py suite -- --list
python3 corpus/build_expanded_corpus.py --help
python3 e2e/run.py --help
```

Prepare the corpus-derived objects used by the end-to-end cases:

```bash
python3 corpus/build_expanded_corpus.py --repo tracee --repo tetragon --repo scx
```

Then run layer-specific workflows:

```bash
python3 micro/driver.py suite -- --runtime llvmbpf --runtime kernel
python3 corpus/directive_census.py --help
python3 corpus/run_macro_corpus.py --list
python3 e2e/run.py tracee --smoke
python3 e2e/run.py tetragon --smoke
python3 e2e/run.py bpftrace --smoke
python3 e2e/run.py scx --smoke
```

## Layer Notes

`micro/` owns the isolated benchmark manifests, runner build, and the shared `micro/orchestrator/` Python utilities that `corpus/` and `e2e/` import.

`corpus/` owns the 23-project real-world corpus, fetch/build tooling, declarative corpus config in `corpus/config/`, and the measurement / analysis scripts for corpus-wide experiments.

`e2e/` owns full deployment-style evaluation via the unified `e2e/run.py` entrypoint plus per-case assets under `e2e/cases/`.

`legacy/` contains the old multi-runtime userspace benchmark and external reference repositories. They are preserved for history but are not part of the active refactored workflow.

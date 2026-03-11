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

Build the shared runner and benchmark objects:

```bash
make -C micro micro_exec programs
```

List the current micro suite:

```bash
python3 micro/run_micro.py --list
```

Run a corpus census or corpus perf harness:

```bash
python3 corpus/directive_census.py --help
python3 corpus/run_corpus_perf.py --help
```

## Layer Notes

`micro/` owns the isolated benchmark manifests, runner build, and the shared `micro/orchestrator/` Python utilities that `corpus/` and `e2e/` import.

`corpus/` owns the 23-project real-world corpus, fetch/build tooling, declarative corpus config in `corpus/config/`, and the measurement / analysis scripts for corpus-wide experiments.

`e2e/` is reserved for full deployment-style evaluation. The current Tracee, Tetragon, and bpftrace probe harnesses now live there as the first slice of that layer.

`legacy/` contains the old multi-runtime userspace benchmark and external reference repositories. They are preserved for history but are not part of the active refactored workflow.

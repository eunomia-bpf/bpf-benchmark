# Micro Benchmark

`micro/` is the active isolated pure-JIT benchmark layer.

## Current Suite

- `micro/config/micro_pure_jit.yaml` is the active micro suite manifest.
- The suite covers the active workload-pattern benchmark set across staged XDP cases, packet-backed XDP controls, and a small kernel-only non-XDP control subset.
- The default benchmark set is intentionally workload-shaped rather than pass-pattern-shaped; pass-specific reduced cases belong in unit or regression tests.

## Directory Layout

- `driver.py`: consolidated micro suite driver; `make micro` is the canonical benchmark entrypoint
- `catalog.py`: micro-only suite YAML parser
- `../runner/libs/input_generators.py`: deterministic input generation for active benchmarks
- `summarize_rq.py`, `generate_figures.py`: active reporting utilities
- `../runner/`: shared C++ runner plus reusable Python libs for `micro/` and `corpus/`
- `programs/*.bpf.c`: active pure-JIT benchmark sources

## Build

Canonical preparation goes through the root `Makefile` (`make micro`) and the
Python local-prep pipeline.

## Usage

Run inside the framework-kernel VM:

```bash
make micro
```

Run a targeted VM benchmark with current knobs:

```bash
make micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

## Outputs

Results live under `micro/results/`.

- Each run lives under `micro/results/<run_type>_<timestamp>/`
- `metadata.json` is the canonical summary for that run
- `details/` contains `result.json` plus any retained per-sample payloads

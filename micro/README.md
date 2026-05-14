# Micro Benchmark

`micro/` is the active isolated pure-JIT benchmark layer.

## Current Suite

- `micro/config/micro_pure_jit.yaml` is the active micro suite manifest.
- The suite covers the active workload-pattern benchmark set across staged XDP cases, packet-backed XDP controls, and a small kernel-only non-XDP control subset.
- The default benchmark set is intentionally workload-shaped rather than pass-pattern-shaped; pass-specific reduced cases belong in unit or regression tests.

## Directory Layout

- `driver.py`: consolidated micro suite driver; `make vm-micro` is the canonical benchmark entrypoint and `python3 micro/driver.py ...` is the direct driver entrypoint
- `catalog.py`: micro-only suite YAML parser
- `input_generators.py`: deterministic input generation for active benchmarks
- `summarize_rq.py`, `generate_figures.py`: active reporting utilities
- `../runner/`: shared C++ runner plus reusable Python libs for `micro/` and `corpus/`
- `programs/*.bpf.c`: active pure-JIT benchmark sources

## Build

Canonical preparation goes through the root `Makefile` (`make micro`) and
the Python local-prep pipeline. Direct `python3 micro/driver.py ...` execution
assumes `runner/build/micro_exec` plus the staged `.bpf.o` inputs under
`.cache/micro-programs/<arch>/` already exist. For direct driver debugging, set
`BPFREJIT_MICRO_PROGRAM_DIR` to the prepared program directory and
`BPFREJIT_MICRO_RUNNER_BINARY` when using a non-default runner build such as
`runner/build-arm64/micro_exec`.

## Usage

List the active suite:

```bash
python3 micro/driver.py --list
```

Run the suite on the host:

```bash
python3 micro/driver.py --runtime llvmbpf --runtime kernel
```

Run llvmbpf only:

```bash
python3 micro/driver.py --runtime llvmbpf
```

Run inside the framework-kernel VM:

```bash
make micro
```

Run a targeted VM benchmark with current knobs:

```bash
make micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

Run a targeted smoke test directly:

```bash
python3 micro/driver.py \
  --bench simple \
  --runtime llvmbpf \
  --samples 1 \
  --warmups 0 \
  --inner-repeat 10
```

## Outputs

Results live under `micro/results/`.

- Each run lives under `micro/results/<run_type>_<timestamp>/`
- `metadata.json` is the canonical summary for that run
- `details/` contains `result.json` plus any retained per-sample payloads

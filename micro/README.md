# Micro Benchmark

`micro/` is the active isolated pure-JIT benchmark layer.

## Current Suite

- `micro/config/micro_pure_jit.yaml` is the active micro suite manifest.
- The suite covers the active pure-JIT benchmark set across staged XDP cases, packet-backed XDP controls, and a small kernel-only non-XDP control subset.
- The suite is designed to exercise the active canonical forms tracked in `docs/kernel-jit-optimization-plan.md`: `COND_SELECT`, `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `ENDIAN_FUSION`, and `BRANCH_FLIP`.

## Directory Layout

- `driver.py`: consolidated micro suite driver; `python3 micro/driver.py suite ...` is the canonical entrypoint
- `benchmark_catalog.py`: suite YAML parser for micro manifests
- `input_generators.py`: deterministic input generation for active benchmarks
- `summarize_rq.py`, `generate_figures.py`: active reporting utilities
- `../runner/`: shared C++ runner plus reusable Python libs for `micro/`, `corpus/`, and `e2e/`
- `programs/*.bpf.c`: active pure-JIT benchmark sources

## Build

```bash
git submodule update --init --recursive
make micro
```

`make micro` builds `runner/build/micro_exec` plus the active benchmark `.bpf.o` objects.

## Usage

List the active suite:

```bash
python3 micro/driver.py suite -- --list
```

Run the suite on the host:

```bash
./docs/paper/scripts/run_micro.sh
```

Run llvmbpf only:

```bash
./docs/paper/scripts/run_micro.sh --llvmbpf-only
```

Run inside the framework-kernel VM:

```bash
./docs/paper/scripts/run_micro.sh --vm
```

Run a targeted smoke test directly:

```bash
python3 micro/driver.py suite -- \
  --bench simple \
  --runtime llvmbpf \
  --iterations 1 \
  --warmups 0 \
  --repeat 10
```

## Outputs

Results live under `micro/results/`.

- `micro/results/dev/`: default working outputs for direct runs and Makefile targets
- `micro/results/`: checked-in authoritative JSON plus `README.md`
- `micro/results/archive/`: historical and intermediate artifacts

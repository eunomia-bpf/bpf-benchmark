# Micro Benchmark

`micro/` is the active isolated pure-JIT benchmark layer.

## Current Suite

- `micro/config/micro_pure_jit.yaml` is the active micro suite manifest.
- The suite covers the active pure-JIT benchmark set across staged XDP cases, packet-backed XDP controls, and a small kernel-only non-XDP control subset.
- The suite is designed to exercise the active canonical forms tracked in `docs/kernel-jit-optimization-plan.md`: `COND_SELECT`, `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `ENDIAN_FUSION`, and `BRANCH_FLIP`.

## Directory Layout

- `driver.py`: consolidated micro suite driver; `make vm-micro` is the canonical benchmark entrypoint and `python3 micro/driver.py ...` is the direct driver entrypoint
- `catalog.py`: micro-only suite YAML parser
- `input_generators.py`: deterministic input generation for active benchmarks
- `summarize_rq.py`, `generate_figures.py`: active reporting utilities
- `../runner/`: shared C++ runner plus reusable Python libs for `micro/`, `corpus/`, and `e2e/`
- `programs/*.bpf.c`: active pure-JIT benchmark sources

## Build

Canonical preparation goes through the root `Makefile` (`make vm-micro`) and
the Python local-prep pipeline. Direct `python3 micro/driver.py ...` execution
assumes `runner/build/micro_exec` plus the staged `.bpf.o` inputs under
`micro/programs/` already exist.

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
make vm-micro
```

Run a specific pass profile through the daemon-backed VM path:

```bash
make vm-micro PROFILE=ablation_wide_mem
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
- Older runs of the same type keep metadata and may drop `details/`

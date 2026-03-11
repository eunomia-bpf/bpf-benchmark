# Micro Benchmark

`micro/` now contains only the isolated benchmark layer.

- `config/micro_pure_jit.yaml`: pure JIT codegen/exec micro-benchmarks
- `config/micro_runtime.yaml`: map/helper/runtime mechanism micro-benchmarks
- `run_micro.py`: main isolated benchmark runner
- `run_rigorous.py` / `run_pass_ablation.py`: deeper micro-only evaluation modes
- `orchestrator/`: shared Python orchestration utilities reused by `corpus/` and `e2e/`

The corpus and end-to-end harnesses have moved out of this directory.

## Build

```bash
git submodule update --init --recursive
make -C micro
```

If you only need the runner and benchmark objects:

```bash
make -C micro micro_exec programs
```

## Usage

List the current pure-JIT suite:

```bash
python3 micro/driver.py suite -- --list
```

Run the default pure-JIT suite:

```bash
python3 micro/driver.py suite -- \
  --runtime llvmbpf \
  --runtime kernel \
  --iterations 10 \
  --warmups 2 \
  --repeat 200 \
  --shuffle-seed 20260306
```

Run the runtime-focused micro suite:

```bash
python3 micro/driver.py suite -- \
  --suite config/micro_runtime.yaml \
  --runtime llvmbpf \
  --runtime kernel
```

Run a single benchmark smoke test:

```bash
python3 micro/run_micro.py \
  --bench simple \
  --runtime llvmbpf \
  --iterations 1 \
  --warmups 0 \
  --repeat 1 \
  --output /tmp/micro-smoke.json
```

## Outputs

Default result files for the isolated suites live in `micro/results/`.

- `pure_jit.latest.json`
- `runtime.latest.json`

Micro-specific analysis scripts also continue to read and write `micro/results/`.

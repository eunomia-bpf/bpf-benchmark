# Micro Benchmark

`micro/` now contains only the isolated benchmark layer.

- `config/micro_pure_jit.yaml`: default isolated JIT suite. As of March 11, 2026 it contains 56 benchmarks: 48 staged compute-oriented cases, 5 packet-backed parser/hash/bounds controls, and 3 map-backed kernel-only non-XDP controls.
- `config/micro_runtime.yaml`: runtime mechanism suite. As of March 11, 2026 it contains 11 benchmarks: 8 map-backed map/atomic/probe-read/time cases plus 3 staged helper-call stress cases.
- `run_micro.py`: main isolated benchmark runner
- `run_rigorous.py` / `run_pass_ablation.py`: deeper micro-only evaluation modes
- `orchestrator/`: shared Python orchestration utilities reused by `corpus/` and `e2e/`

The corpus and end-to-end harnesses have moved out of this directory.

## Suite Semantics

- `micro_pure_jit.yaml` is for code-generation quality. The hot path should avoid map/helper work except for the explicit packet-backed controls and the small kernel-only non-XDP control subset.
- `micro_runtime.yaml` intentionally measures map/helper/runtime mechanisms. Differences there mix code generation with runtime service overhead.

## Build

```bash
git submodule update --init --recursive
make -C micro
```

`make -C micro` builds `micro_exec`, benchmark `.bpf.o` objects, and `micro/build/tools/directive_hint`. `run_micro.py` also re-invokes the incremental `make -C micro micro_exec` and `make -C micro programs` steps before running a suite.

If you only need the runner and benchmark objects:

```bash
make -C micro micro_exec programs
```

## Usage

List the current pure-JIT suite:

```bash
python3 micro/run_micro.py --list
```

Or via the unified driver:

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

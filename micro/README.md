# Micro Benchmark

`micro/` is the active isolated pure-JIT benchmark layer.

## Current Suite

- `config/micro_pure_jit.yaml` is the only active micro suite manifest.
- The suite currently contains 56 benchmarks: 48 staged XDP cases, 5 packet-backed XDP controls, and 3 kernel-only non-XDP controls.
- Program-type coverage is 53 XDP, 2 TC, and 1 cgroup_skb benchmarks.
- The suite is designed to exercise the 8 canonical forms tracked in `docs/kernel-jit-optimization-plan.md`: `COND_SELECT`, `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, and `BRANCH_FLIP`.

## Directory Layout

- `run_micro.py`: main pure-JIT runner
- `driver.py`: unified micro/corpus/e2e entrypoint
- `orchestrator/`: shared Python helpers reused by `corpus/` and `e2e/`
- `programs/*.bpf.c`: active pure-JIT benchmark sources
- `programs/archive/runtime/*.bpf.c`: archived runtime-only benchmarks, preserved for history and excluded from the active build

## Build

```bash
git submodule update --init --recursive
make -C micro
```

`make -C micro` builds `micro_exec`, the active benchmark `.bpf.o` objects, and `micro/build/tools/directive_hint`.

## Usage

List the active suite:

```bash
python3 micro/run_micro.py --list
python3 micro/driver.py suite -- --list
```

Run the suite on the host:

```bash
./scripts/run_micro.sh
```

Run llvmbpf only:

```bash
./scripts/run_micro.sh --llvmbpf-only
```

Run inside the framework-kernel VM:

```bash
./scripts/run_micro.sh --vm
```

Run a targeted smoke test directly:

```bash
python3 micro/run_micro.py \
  --bench simple \
  --runtime llvmbpf \
  --iterations 1 \
  --warmups 0 \
  --repeat 10
```

## Outputs

Results live under `micro/results/`.

- `pure_jit.latest.json`: default host run (`llvmbpf + kernel`)
- `pure_jit.llvmbpf_only.latest.json`: default `--llvmbpf-only` script output
- `pure_jit.vm.latest.json`: default `--vm` script output

Micro analysis scripts continue to read and write `micro/results/`.

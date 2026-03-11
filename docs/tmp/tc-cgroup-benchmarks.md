# TC and cgroup_skb Benchmark Expansion

Generated: 2026-03-11

## Scope

Added three non-XDP micro benchmarks to broaden program-type coverage without changing `kernel_runner.cpp`:

- `tc_checksum` (`SEC("tc")`, `io_mode: map`)
- `tc_bitcount` (`SEC("tc")`, `io_mode: map`)
- `cgroup_hash_chain` (`SEC("cgroup_skb/egress")`, `io_mode: map`)

Implementation details:

- `micro/programs/common.h` now includes TC and `cgroup_skb` staged/map-backed wrappers using `struct __sk_buff *`.
- The new skb wrappers read staged input from `input_map` and publish results through `result_map`.
- `tc` returns `TC_ACT_OK` on success.
- `cgroup_skb` returns `CGROUP_SKB_OK` (`1`) on success.

## Inputs and Manifest

- Reused existing generators for `tc_checksum` (`checksum`) and `tc_bitcount` (`bitcount`).
- Added a new `hash_chain` generator for `cgroup_hash_chain`.
- Added all three benchmarks to `config/micro_pure_jit.yaml` with explicit `io_mode: map`.

Expected results:

- `tc_checksum`: `0`
- `tc_bitcount`: `3035568289764064166`
- `cgroup_hash_chain`: `12027228624407116210`

## Validation

Build commands run:

```bash
make -C micro programs
make -C micro micro_exec
python3 -m py_compile micro/input_generators.py
python3 micro/run_micro.py --list
```

Input materialization run:

```bash
python3 - <<'PY'
from micro.input_generators import materialize_input
for name in ('checksum', 'bitcount', 'hash_chain'):
    print(materialize_input(name, force=True))
PY
```

Kernel smoke tests run:

```bash
sudo -n micro/build/runner/micro_exec run-kernel \
  --program micro/programs/tc_checksum.bpf.o \
  --memory micro/generated-inputs/checksum.mem \
  --input-size 1032 --io-mode map --repeat 100

sudo -n micro/build/runner/micro_exec run-kernel \
  --program micro/programs/tc_bitcount.bpf.o \
  --memory micro/generated-inputs/bitcount.mem \
  --input-size 2056 --io-mode map --repeat 100

sudo -n micro/build/runner/micro_exec run-kernel \
  --program micro/programs/cgroup_hash_chain.bpf.o \
  --memory micro/generated-inputs/hash_chain.mem \
  --input-size 72 --io-mode map --repeat 100
```

Observed results:

- `tc_checksum`: `result=0`, `retval=0`
- `tc_bitcount`: `result=3035568289764064166`, `retval=0`
- `cgroup_hash_chain`: `result=12027228624407116210`, `retval=1`

Optional llvmbpf spot-checks also succeeded for all three objects with matching results, despite these benchmarks being intended primarily as kernel-side program-type breadth checks.

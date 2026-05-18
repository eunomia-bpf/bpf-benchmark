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

## LLVM Kinsn Backend Path

The experimental LLVM backend path compiles the same `programs/*.bpf.c` sources
through clang IR plus a kinsn-enabled BPF `llc`, then runs the resulting objects
through the normal kernel micro runner.

Build or refresh the kinsn-enabled `llc`:

```bash
ninja -C llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

Generate kinsn-enabled micro objects:

```bash
out="micro/results/llvm_kinsn_programs_$(date +%Y%m%d_%H%M%S)"
make -C micro/programs \
  OUTPUT_DIR="$PWD/$out" \
  KERNEL_OFFSETS_INPUT="$PWD/.cache/repo-build/host/kernel-offsets/x86_64/kernel_offsets.h" \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$PWD/llvm-backend/build-bpf-kinsn/bin/llc" \
  all
```

Run those objects in the framework-kernel VM:

```bash
make micro TIMEOUT=7200 \
  MICRO_ARGS="--samples 3 --warmups 0 --inner-repeat 1000 --runtime kernel --program-dir $out"
```

Current smoke result from this path:

- kinsn object dir: `micro/results/llvm_kinsn_programs_20260518_014403`
- kinsn run: `micro/results/x86_kvm_micro_20260518_085229_761243`
- clang baseline: `micro/results/x86_kvm_micro_20260518_085516_282495`
- same-LLC no-selector control: `micro/results/x86_kvm_micro_20260518_085903_992103`
- correctness: 29/29 micro cases loaded and returned matching results
- selected kinsns: `siphash_rotate64_mixer` 116, `payload_prefix_memcmp_scan` 2,
  `bpftrace_string_search_prefix_scan` 1
- selected-only effect vs same-LLC no-selector: `siphash_rotate64_mixer`
  78.7 ns -> 55.3 ns, `payload_prefix_memcmp_scan` 116.3 ns -> 108.0 ns,
  `bpftrace_string_search_prefix_scan` 180.0 ns -> 175.7 ns

Current limitation: the selector does not select kinsns inside local `.text`
subprograms. With the current module proof stack ABI, selecting rotate kinsns in
local-call callees can make verifier combined stack accounting exceed 512 bytes.

## Outputs

Results live under `micro/results/`.

- Each run lives under `micro/results/<run_type>_<timestamp>/`
- `metadata.json` is the canonical summary for that run
- `details/` contains `result.json` plus any retained per-sample payloads

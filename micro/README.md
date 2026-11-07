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

## Verified native runtime

For x86 KVM, select `native_proof` to execute native code after the registered
trusted service generates, verifies and binds its proof. The application
submits only its native ELF, entry and typed metadata. The VM Make entrypoint
starts the service outside the application container, using a private `/run`
directory, and archives its requests and logs under
`micro/results/trusted-service-<RUN_TOKEN>.tar.gz` when the suite closes.
The `host-runner-x86` build also builds the trusted service loader; reuse the
existing incremental kernel and image build paths when refreshing artifacts.

```bash
make micro PLATFORM=kvm ARCH=x86 BENCH=simple RUNTIMES="kernel native_proof" SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
```

`native_kernel` also requires this same bound native-only path. These two
labels currently execute the same mechanism; they are not separate unbound
and verified baselines. Historical `native_proof` results executed a prebuilt
simulator BPF object and cannot be reused as trusted-path native timings.
New samples retain actual native-load phases; they do not add a historical
proof-compilation time from a packaged JSON file. Requested native runs fail
if service registration or proof binding fails. No micro runner is exempt
from the application proof-upload rejection. The standalone ARM QEMU and
other deployment bootstraps must likewise register the service before running
these native labels; the x86 KVM integration is not evidence for those paths.

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
  KERNEL_OFFSETS_INPUT="$PWD/micro/programs/build-x86/kernel_offsets.h" \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$PWD/llvm-backend/build-bpf-kinsn/bin/llc" \
  all
```

Run those objects in the framework-kernel VM:

```bash
make micro TIMEOUT=7200 \
  MICRO_ARGS="--samples 3 --warmups 0 --inner-repeat 100000 --runtime kernel --program-dir $out"
```

Current smoke result from this path:

- kinsn object dir: `micro/results/llvm_kinsn_programs_20260518_014403`
- kinsn run: `micro/results/x86_kvm_micro_20260518_085229_761243`
- clang baseline: `micro/results/x86_kvm_micro_20260518_085516_282495`
- same-LLC no-selector control: `micro/results/x86_kvm_micro_20260518_085903_992103`
- correctness: 29/29 micro cases loaded and returned matching results
- selected kinsn: `siphash_rotate64_mixer` 116, `payload_prefix_memcmp_scan` 2,
  `bpftrace_string_search_prefix_scan` 1
- selected-only effect vs same-LLC no-selector: `siphash_rotate64_mixer`
  78.7 ns -> 55.3 ns, `payload_prefix_memcmp_scan` 116.3 ns -> 108.0 ns,
  `bpftrace_string_search_prefix_scan` 180.0 ns -> 175.7 ns

Current limitation: the selector does not select kinsn inside local `.text`
subprograms. With the current module proof stack ABI, selecting rotate kinsn in
local-call callees can make verifier combined stack accounting exceed 512 bytes.

## Outputs

Results live under `micro/results/`.

- Each run lives under `micro/results/<run_type>_<timestamp>/`
- `metadata.json` is the canonical summary for that run
- `details/` contains `result.json` plus any retained per-sample payloads

# Micro Benchmark Status

Last updated: 2026-05-27

This is the current paper-facing status page for microbenchmark data. The
previous long evaluation note is archived at
`docs/tmp/micro-bench-status-20260520-archive.md`.

All ratios, speedups, and win/loss counts below are post-hoc analysis from raw
`result.json` files. The benchmark framework still records raw measurements
only.

## Paper Framing

This section should read like a characterization study, not like an
implementation status log. The microbenchmark claim is intentionally narrow:
native kernel execution changes the cost of BPF instruction execution and
helper/map access patterns under controlled `BPF_PROG_TEST_RUN` workloads.
Corpus/app results are required separately for end-to-end application claims.

The current research questions are:

- **RQ1 Correctness:** do all tested execution configurations preserve the
  expected result and retval on the microbenchmark suites?
- **RQ2 Four-way execution cost:** on x86 KVM, how do userspace eBPF,
  userspace native, kernel eBPF, and kernel native compare on pure
  instruction-path workloads?
- **RQ3 Helper/map boundary cost:** on x86 KVM, does kernel native still improve
  helper/map-heavy programs when evaluated against the real kernel helper/map
  ABI?
- **RQ4 Kernel-native portability:** does the kernel-native result also hold on
  arm64 when compared against arm64 kernel eBPF?

The full four-way comparison is available in the latest x86 KVM artifacts:
`llvmbpf` is userspace eBPF, `native` is userspace native, `kernel` is kernel
eBPF, and `native_kernel` is kernel native. Stage2 excludes userspace native
from the main comparison because its helper/map path is runner-local emulation,
not the kernel helper/map ABI. The arm64 AWS artifacts are a two-way
portability check for kernel eBPF versus kernel native.

## Experimental Setup

The authoritative micro runs use:

```sh
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 make micro

PLATFORM=aws ARCH=arm64 SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 make micro
```

The measured suites are:

- **Stage1 pure 29:** compute, branch, local-call, parser, checksum, string, and
  packet microbenchmarks with no external map/helper bottleneck as the dominant
  cost.
- **Stage2 helpers/maps 13:** deterministic helper and map-access benchmarks
  covering arrays, hash maps, percpu maps, LRU maps, mixed helper/map paths, and
  packet classification.

The measured runtimes are:

- **kernel:** baseline kernel eBPF JIT.
- **native_kernel:** native object linked and loaded into the kernel native
  execution path.
- **native:** userspace native runtime, available in the latest x86 KVM
  four-way run.
- **llvmbpf:** userspace eBPF through the LLVM-BPF runtime, available in the
  latest x86 KVM four-way run.

The platform details recorded in the artifacts are:

| Platform | Executor | CPU recorded by artifact | Kernel | AWS bench instance default |
|---|---|---|---|---|
| x86 KVM | virtme-ng VM | Intel Core Ultra 9 285K | 7.0.0-rc2+ | N/A |
| arm64 AWS | EC2 instance | aarch64 | 7.0.0-rc2+ | `t4g.small` |

## Methodology

Each benchmark/runtime pair records three samples after zero warmups. Each
sample runs the benchmark body `INNER_REPEAT=100000` times. Correctness is
gated by exact expected result and retval checks for every recorded sample.

For each benchmark and runtime, the analysis uses the median `exec_ns` across
the three samples. For each suite, the reported aggregate is the geomean of
per-benchmark ratios:

```text
ratio = median_runtime_exec_ns / median_kernel_exec_ns
speedup = 1 / ratio
```

A ratio below 1.0 means the runtime is faster than the kernel eBPF JIT.
Wins/losses/ties use a +/-2% band around the kernel baseline. No benchmark is
filtered out of these micro aggregates.

## Main Results

Latest representative full runs:

| Platform | Suite | Result source | Runtimes | Samples | Expected-result mismatches |
|---|---|---|---|---:|---:|
| x86 KVM | stage1 pure 29 | `micro/results/x86_kvm_micro_20260526_210952_650695` | kernel, llvmbpf, native, native_kernel | 348 | 0 |
| x86 KVM | stage2 helpers/maps | `micro/results/x86_kvm_micro_20260526_210434_440390` | kernel, llvmbpf, native, native_kernel | 156 | 0 |
| arm64 AWS | stage1 pure 29 | `micro/results/aws_arm64_micro_20260523_091516_610343` | kernel, native_kernel | 174 | 0 |
| arm64 AWS | stage2 helpers/maps | `micro/results/aws_arm64_micro_20260523_092823_183684` | kernel, native_kernel | 78 | 0 |

Aggregate runtime ratios:

| Platform | Suite | Runtime vs kernel eBPF | Runtime/kernel geomean | Speedup vs kernel eBPF | Wins / losses / ties |
|---|---|---|---:|---:|---:|
| x86 KVM | stage1 pure 29 | native userspace | 0.583 | 1.716x | 27 / 1 / 1 |
| x86 KVM | stage1 pure 29 | LLVM-BPF userspace | 0.650 | 1.538x | 27 / 1 / 1 |
| x86 KVM | stage1 pure 29 | native kernel | 0.678 | 1.474x | 24 / 2 / 3 |
| x86 KVM | stage2 helpers/maps | native kernel | 0.710 | 1.409x | 9 / 0 / 4 |
| arm64 AWS | stage1 pure 29 | native kernel | 0.556 | 1.800x | 28 / 0 / 1 |
| arm64 AWS | stage2 helpers/maps | native kernel | 0.855 | 1.170x | 9 / 0 / 4 |

![Aggregate runtime speedup over kernel eBPF](figures/micro-characterization-runtime-aggregate-20260527.png)

*Figure 1: Aggregate microbenchmark speedup over kernel eBPF JIT for the
authoritative stage1 and stage2 artifacts. x86 KVM includes kernel native,
userspace eBPF, and userspace native. arm64 AWS reports kernel native only
because the current authoritative arm64 artifacts contain kernel eBPF and
kernel native. Higher is better; the dashed line is parity.*

![x86 KVM per-case runtime comparison](figures/micro-characterization-x86-four-way-percase-vertical-20260527.png)

*Figure 2: x86 KVM per-case runtime comparison normalized to kernel eBPF JIT.
Stage1 includes userspace eBPF, userspace native, and kernel native. Stage2
only reports kernel native because helper/map-heavy programs must be evaluated
against the real kernel helper/map ABI; userspace helper/map models are not
comparable for this RQ.*

![arm64 AWS per-case kernel-native comparison](figures/micro-characterization-arm64-kernel-native-percase-vertical-20260527.png)

*Figure 3: arm64 AWS per-case kernel-native portability result. Bars report
kernel native speedup over arm64 kernel eBPF JIT, using the same stage1/stage2
case structure as Figure 2. Higher is better; the dashed line is parity.*

## RQ Answers

**RQ1 Correctness.** All current full micro artifacts have zero expected-result
or retval mismatches. On x86 KVM this covers all four execution configurations
over 29/29 stage1 benchmarks and 13/13 stage2 benchmarks. On arm64 AWS this
covers kernel eBPF and kernel native over the same suites.

**RQ2 Four-way execution cost.** On x86 KVM stage1, all non-kernel-eBPF
execution configurations are faster than kernel eBPF: userspace native is
1.716x, userspace eBPF is 1.538x, and kernel native is 1.474x. This shows that
the pure instruction path benefits from native code even after paying the
kernel-native execution path.

**RQ3 Helper/map boundary cost.** On x86 KVM stage2, kernel native remains
faster than kernel eBPF at 1.409x. Stage2 only reports kernel native because
helper/map-heavy programs must be evaluated against the real kernel helper/map
ABI. Userspace runtimes use runner-local helper/map models, so they are not
comparable for this RQ.

**RQ4 Kernel-native portability.** On arm64 AWS, kernel native is also faster
than arm64 kernel eBPF: 1.800x on stage1 and 1.170x on stage2. The stage2 gain
is smaller than the pure stage1 gain, consistent with helper/map boundary costs.

The concise paper claim supported by these data is:

- x86 KVM stage1 remains strong at 1.474x and stage2 is positive at 1.409x.
- arm64 AWS is positive on both stage1 and stage2, with a larger stage1 gain.

## Threats To Validity

- The microbenchmark suite isolates native execution costs; it does not replace
  corpus/app-level workload measurements.
- AWS CPU governor and turbo state are recorded as unknown in the artifacts.
  Cross-platform comparisons should therefore focus on ratios within the same
  platform, not absolute nanoseconds across platforms.
- AWS full authoritative artifacts currently cover `kernel` and
  `native_kernel`; userspace native and LLVM-BPF baselines are only available in
  the latest x86 KVM full run.
- Userspace runtime stage2 data exists in the raw artifact but is not a
  kernel-helper/map-path comparison, so it is intentionally excluded from the
  main stage2 claim.

## Appendix A: Artifact Manifest

| Platform | Suite | Generated at | Result source |
|---|---|---|---|
| x86 KVM | stage1 pure 29 | 2026-05-26T21:09:52Z | `micro/results/x86_kvm_micro_20260526_210952_650695/details/result.json` |
| x86 KVM | stage2 helpers/maps | 2026-05-26T21:04:34Z | `micro/results/x86_kvm_micro_20260526_210434_440390/details/result.json` |
| arm64 AWS | stage1 pure 29 | 2026-05-23T09:15:16Z | `micro/results/aws_arm64_micro_20260523_091516_610343/details/result.json` |
| arm64 AWS | stage2 helpers/maps | 2026-05-23T09:28:23Z | `micro/results/aws_arm64_micro_20260523_092823_183684/details/result.json` |

## Appendix B: Native Kernel Stage2 Detail

Stage2 is the helper/map suite and is the most sensitive current native-kernel
micro workload. Values are median `exec_ns`; speedup is
`kernel_ns / native_kernel_ns`.

| Platform | Benchmark | Native kernel ns | Kernel eBPF ns | Speedup |
|---|---|---:|---:|---:|
| x86 KVM | `helper_only_uid_gid` | 7 | 7 | 1.000x |
| x86 KVM | `helper_chain_simple` | 72 | 74 | 1.028x |
| x86 KVM | `map_array_lookup` | 6 | 18 | 3.000x |
| x86 KVM | `map_array_index_packet` | 6 | 17 | 2.833x |
| x86 KVM | `map_hash_lookup` | 32 | 32 | 1.000x |
| x86 KVM | `map_hash_str_key` | 33 | 33 | 1.000x |
| x86 KVM | `map_percpu_array` | 6 | 17 | 2.833x |
| x86 KVM | `map_lru_hash_counter` | 84 | 86 | 1.024x |
| x86 KVM | `map_percpu_hash_counter` | 27 | 28 | 1.037x |
| x86 KVM | `combined_helper_map` | 8 | 19 | 2.375x |
| x86 KVM | `multi_map_policy` | 32 | 44 | 1.375x |
| x86 KVM | `packet_5tuple_classify` | 40 | 41 | 1.025x |
| x86 KVM | `stats_mixed_helpers` | 60 | 59 | 0.983x |
| arm64 AWS | `helper_only_uid_gid` | 30 | 32 | 1.067x |
| arm64 AWS | `helper_chain_simple` | 242 | 247 | 1.021x |
| arm64 AWS | `map_array_lookup` | 17 | 28 | 1.647x |
| arm64 AWS | `map_array_index_packet` | 18 | 29 | 1.611x |
| arm64 AWS | `map_hash_lookup` | 96 | 100 | 1.042x |
| arm64 AWS | `map_hash_str_key` | 107 | 109 | 1.019x |
| arm64 AWS | `map_percpu_array` | 19 | 31 | 1.632x |
| arm64 AWS | `map_lru_hash_counter` | 215 | 220 | 1.023x |
| arm64 AWS | `map_percpu_hash_counter` | 90 | 91 | 1.011x |
| arm64 AWS | `combined_helper_map` | 37 | 46 | 1.243x |
| arm64 AWS | `multi_map_policy` | 108 | 125 | 1.157x |
| arm64 AWS | `packet_5tuple_classify` | 107 | 109 | 1.019x |
| arm64 AWS | `stats_mixed_helpers` | 188 | 190 | 1.011x |

## Appendix C: Code Size

The code-size comparison uses median `code_size.native_code_bytes` from the
same authoritative artifacts. This is machine-code size, not BPF bytecode size.
The ratio is `native_kernel_code_bytes / kernel_jit_code_bytes`, so lower means
the native-kernel image is smaller than the kernel eBPF JIT image.

![Native kernel machine-code size ratio](figures/micro-characterization-code-size-20260527.png)

*Figure 4: Native-kernel machine-code size relative to kernel eBPF JIT code size
for the same stage1/stage2 artifacts used in the runtime figures.*

| Platform | Suite | native_kernel/kernel code-size geomean |
|---|---|---:|
| x86 KVM | stage1 pure 29 | 0.541 |
| x86 KVM | stage2 helpers/maps | 0.610 |
| arm64 AWS | stage1 pure 29 | 0.495 |
| arm64 AWS | stage2 helpers/maps | 0.724 |

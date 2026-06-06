# Micro characterization 2026-06-06 summary

Post-hoc analysis from raw result.json files. Ratios use per-benchmark median exec_ns.

| Platform | Suite | Runtime | Runtime/kernel geomean | Speedup | Wins / losses / ties | Code-size ratio |
|---|---|---|---:|---:|---:|---:|
| x86 KVM | pure bytecode 29 | Kernel native | 0.678 | 1.474x | 24 / 2 / 3 | 0.541 |
| x86 KVM | pure bytecode 29 | Userspace eBPF | 0.650 | 1.538x | 27 / 1 / 1 | 0.565 |
| x86 KVM | pure bytecode 29 | Userspace native | 0.583 | 1.716x | 27 / 1 / 1 | 0.539 |
| x86 KVM | with helpers/maps 13 | Kernel native | 0.710 | 1.409x | 9 / 0 / 4 | 0.610 |
| arm64 AWS | pure bytecode 29 | Kernel native | 0.563 | 1.777x | 27 / 0 / 2 | 0.495 |
| arm64 AWS | pure bytecode 29 | Userspace eBPF | 0.512 | 1.952x | 29 / 0 / 0 | 0.460 |
| arm64 AWS | pure bytecode 29 | Userspace native | 0.467 | 2.141x | 29 / 0 / 0 | 0.471 |
| arm64 AWS | with helpers/maps 13 | Kernel native | 0.869 | 1.151x | 6 / 0 / 7 | 0.724 |

## Variability

| Platform | Suite | Benchmark/runtime pairs | Median CV | p95 CV | Max CV | Pairs within 2% of median |
|---|---|---:|---:|---:|---:|---:|
| x86 KVM | pure bytecode 29 | 116 | 0.57% | 17.69% | 28.37% | 75 / 116 |
| x86 KVM | with helpers/maps 13 | 26 | 0.40% | 60.39% | 61.02% | 16 / 26 |
| arm64 AWS | pure bytecode 29 | 116 | 0.50% | 9.96% | 17.15% | 73 / 116 |
| arm64 AWS | with helpers/maps 13 | 26 | 0.40% | 4.64% | 12.38% | 17 / 26 |

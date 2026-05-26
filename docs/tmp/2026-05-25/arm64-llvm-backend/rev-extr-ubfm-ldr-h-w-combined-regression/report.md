# ARM64 LLVM backend: REV/EXTR/UBFM/LDR combined regression

## Conclusion

The combined regression for the currently completed ARM64 selected-safe families passed.

Enabled families:

- `REV`
- `EXTR`
- `UBFM`
- `LDR_X`
- `LDRH`
- `LDR_W`

Object isolation:

| case | objects | kfunc symbol-objects | ARM64 symbol-objects | x86 symbol-objects | status |
|---|---:|---:|---:|---:|---|
| `arm64-all-disable` | 29 | 0 | 0 | 0 | completed |
| `arm64-combined` | 29 | 47 | 47 | 0 | completed |
| `x86-scoped` | 29 | 37 | 0 | 37 | completed |

AWS ARM64 full micro correctness:

| benchmarks | runtimes | samples | failed samples | status |
|---:|---|---:|---:|---|
| 29 | `kernel,native` | 58 | 0 | completed |

This report only proves object isolation and runtime correctness for the combined selector set. It is
not a performance experiment.

## What Was Tested

The test used the custom BPF LLVM backend:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc
```

ARM64 combined flags:

```text
-bpf-kinsn-target=arm64
-bpf-kinsn-mode=all=disable
-bpf-kinsn-mode=unary=force
-bpf-kinsn-mode=rotate=force
-bpf-kinsn-mode=bextr=force
-bpf-kinsn-mode=wide-load=force
```

These flags enable:

| selector policy | ARM64 family |
|---|---|
| `unary` | `REV` |
| `rotate` | `EXTR` |
| `bextr` | `UBFM` |
| `wide-load` | `LDR_X`, `LDRH`, `LDR_W` |

## ARM64 Relocation Coverage

| kfunc | object count | relocations |
|---|---:|---:|
| `bpf_arm64_rev16_w` | 1 | 2 |
| `bpf_arm64_rev_w` | 1 | 2 |
| `bpf_arm64_extr_w` | 4 | 40 |
| `bpf_arm64_extr_x` | 3 | 119 |
| `bpf_arm64_ubfm_x` | 12 | 38 |
| `bpf_arm64_ldrh` | 4 | 11 |
| `bpf_arm64_ldr_w` | 21 | 43 |
| `bpf_arm64_ldr_x` | 1 | 8 |

## AWS Run

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force -bpf-kinsn-mode=wide-load=force" \
  RUNTIMES="native kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

Environment:

- AWS region: `us-east-1`
- instance type: `t4g.small`
- kernel: `7.0.0-rc2+`
- runtime image: `bpf-benchmark/runner-runtime:arm64`
- final instance state: `terminated`

Estimated AWS cost:

| instance | wall seconds | total estimated cost |
|---|---:|---:|
| `i-0c549ab1126f6f443` | 370 | `$0.00208709` |

The estimate uses public on-demand EC2 and gp3 list prices, and excludes data transfer, tax, free
tier, credits, Savings Plans, Reserved Instances, and account-level discounts.

## Raw Data

The local development record is:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
```

Key copied data in this public tmp directory:

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-h-w-combined-regression/data
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-h-w-combined-regression/analysis
```

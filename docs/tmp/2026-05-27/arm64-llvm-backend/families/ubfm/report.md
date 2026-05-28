# ARM64 UBFM family report

## 结论

`UBFM` family 已达到 development-complete on micro。它覆盖 64-bit bitfield extract，
对应 kfunc：

```text
bpf_arm64_ubfm_x
```

当前 AWS same-LLC attribution 显示 selected kernel 有轻微改善，full suite median 基本不变。

## 实现内容

LLVM BPF backend 中实现了：

| 部分 | 状态 |
|---|---|
| pseudo | 已实现 `UBFM_X` pseudo |
| AsmPrinter payload | 已打包 dst/src 和 `immr` / `imms` |
| selector | safe bitfield extract pattern -> `bpf_arm64_ubfm_x` |
| FileCheck | 已覆盖 object emit |

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/ubfm.md
```

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ubfm-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-rev-extr-ubfm-combined-regression
```

Object smoke：

| case | objects | kfunc extern objects | relocations | ARM64 UBFM symbols | x86 symbols |
|---|---:|---:|---:|---:|---:|
| control-disabled | 29 | 0 | 0 | 0 | 0 |
| ubfm-only | 29 | 12 | 38 | 12 | 0 |

AWS correctness：

| attempt | benchmarks | runtime samples | failed samples |
|---|---:|---:|---:|
| selected-single | 1 | 2 | 0 |
| full-micro | 29 | 58 | 0 |

Performance attribution：

| scope | runtime | benchmarks | median treatment/control |
|---|---|---:|---:|
| all | native | 29 | 1.000000 |
| all | kernel | 29 | 0.999758 |
| selected | native | 12 | 1.000000 |
| selected | kernel | 12 | 0.996766 |

## 状态判断

`UBFM` correctness、target isolation、combined regression 已通过。性能信号是轻微 selected
kernel 改善，不足以单独作为主要结果。

## 后续

保留在 combined treatment 中。若做 paper-grade，应继续以 same-LLC control 比较，并单独汇报
selected subset。

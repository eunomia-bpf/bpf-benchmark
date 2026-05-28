# ARM64 EXTR family report

## 结论

`EXTR` family 已达到 development-complete on micro。它覆盖 rotate32 / rotate64 pattern，
对应 kfunc：

```text
bpf_arm64_extr_w
bpf_arm64_extr_x
```

当前 micro suite 里，`REV+EXTR` 的 selected kernel 改善主要来自 `EXTR`。

## 实现内容

LLVM BPF backend 中实现了：

| 部分 | 状态 |
|---|---|
| pseudo | 已实现 ARM64 `EXTR` pseudo |
| AsmPrinter payload | 已按 module decoder 打包 rotate immediate 和寄存器字段 |
| selector | rotate32 / rotate64 -> `EXTR` |
| FileCheck | 已覆盖 ARM64 `EXTR` emit |

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase5-correctness-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase6-performance
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase7-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
```

`EXTR-only` correctness：

| metric | value |
|---|---:|
| micro benchmarks | 29 |
| runtime samples | 58 |
| failed samples | 0 |
| object count | 29 |
| ARM64 `EXTR` symbols | 7 |
| x86 symbols | 0 |

`EXTR-only` performance attribution：

| scope | runtime | benchmarks | median treatment/control | wins `<0.98` | losses `>1.02` |
|---|---|---:|---:|---:|---:|
| selected | native | 7 | 1.000000 | 0 | 2 |
| selected | kernel | 7 | 0.959916 | 4 | 1 |

## 状态判断

`EXTR` 是当前最清楚的 ARM64 kinsn performance signal：selected kernel 小样本显示改善。
但它仍是 development-grade 结论，不是 paper-grade，因为样本数和 benchmark scope 还不够。

## 后续

后续 paper-grade run 应保留 `EXTR` 为重点 family，并单独保留 same-LLC
`EXTR-only treatment / all=disable control` 口径。

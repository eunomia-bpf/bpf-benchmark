# ARM64 REV family report

## 结论

`REV` family 已达到 development-complete on micro。它覆盖 ARM64 byteswap / endian
conversion，对应 kfunc：

```text
bpf_arm64_rev16_w
bpf_arm64_rev_w
bpf_arm64_rev_x
```

当前证据说明：LLVM 能在 `-bpf-kinsn-target=arm64` 下 emit `bpf_arm64_rev_*`，AWS ARM64
full micro correctness 通过，target isolation 通过。性能上，`REV-only` selected benchmark
在当前 micro suite 中基本 neutral，不是主要收益来源。

## 实现内容

LLVM BPF backend 中实现了：

| 部分 | 状态 |
|---|---|
| target flag | 已支持 `-bpf-kinsn-target=arm64` |
| pseudo | 已实现 ARM64 `REV` pseudo |
| AsmPrinter payload | 已按 `/home/ruoji/github/bpf-opt/code/module/arm64` decoder 打包 |
| selector | byteswap / endian conversion -> `REV` |
| FileCheck | 已覆盖 ARM64 target 和 `REV` emit |

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase5-correctness-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase6-performance
/home/ruoji/github/bpf-opt/experiments/2026-05-22-arm64-phase7-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
```

`REV-only` correctness：

| metric | value |
|---|---:|
| micro benchmarks | 29 |
| runtime samples | 58 |
| failed samples | 0 |
| object count | 29 |
| ARM64 `REV` symbols | 2 |
| x86 symbols | 0 |

`REV-only` performance attribution：

| scope | runtime | benchmarks | median treatment/control |
|---|---|---:|---:|
| selected | native | 1 | 1.000000 |
| selected | kernel | 1 | 1.000000 |

## 状态判断

`REV` 的 correctness 和 isolation 已经够支撑 development branch。它还不能支撑
paper-grade 性能结论，因为没有 corpus benchmark，也没有足够样本的 confidence interval。

## 后续

不建议继续扩展 `REV` 本身。后续如果做 paper-grade，应把 `REV` 作为 combined treatment
的一部分，而不是单独声称性能收益。

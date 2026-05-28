# ARM64 CCMP/CMP/CSET family report

## 结论

`CCMP/CMP/CSET` family 的 selected-safe boolean conjunction subset 已达到
development-complete on micro，但当前不是 performance win。

对应 kfunc：

```text
bpf_arm64_cmp_x
bpf_arm64_cmp_w
bpf_arm64_ccmp_x
bpf_arm64_ccmp_w
bpf_arm64_cset_x_cond
```

第一版实现覆盖 `ccmp_all_nonzero` 风格 pattern，核心是把 boolean `AND_rr_32` chain
lower 成 `CMP` / `CCMP` / `CSET`。

## 实现内容

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/ccmp-cmp-cset.md
```

LLVM BPF backend 中实现了：

| 部分 | 状态 |
|---|---|
| policy key | `ccmp` complete |
| combined pseudo | X2/X3/X4 and W2/W3/W4 complete |
| AsmPrinter payload | complete |
| selector | selected-safe `AND_rr_32` boolean conjunction |
| FileCheck | complete |

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-local-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-full-micro-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression
```

关键结果：

| metric | value |
|---|---|
| selected benchmark | `ccmp_all_nonzero` |
| selected kfuncs | `bpf_arm64_cmp_w`, `bpf_arm64_ccmp_w`, `bpf_arm64_cset_x_cond` |
| AWS selected correctness | native/kernel result both expected `1` |
| AWS full micro correctness | 31 benchmarks, 62 runtime samples, 0 failed sample |
| performance attribution | 31 benchmarks, 186 runtime samples/group, 0 failed sample |
| affected kernel geomean | treatment/control `1.0` |
| combined regression | 31 benchmarks, 62 runtime samples, 0 failed sample |

## 状态判断

selected-safe subset 的 correctness 和 target isolation 已通过，但当前数据不是 performance win。
它的价值主要是覆盖 condition-code based ARM64 kinsn lowering。

## 后续

在找到能从 condition-code sequence 受益的 benchmark 或 corpus workload 前，不要扩大 CCMP
matching 范围。

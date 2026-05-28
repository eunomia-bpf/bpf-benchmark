# ARM64 CSEL family report

## 结论

`CSEL` family 的 selected target 已完成 correctness、performance attribution 和 combined
regression，但当前不是 performance win。

对应 kfunc：

```text
bpf_arm64_tst
bpf_arm64_csel_ne
```

原始 29 个 micro object 没有命中第一版 CSEL selector；因此新增 selected benchmark
`csel_select64` 来覆盖该 family。

## 实现内容

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/csel.md
```

LLVM BPF backend 中实现了:

| 部分 | 状态 |
|---|---|
| combined pseudo | complete |
| AsmPrinter payload | complete |
| custom inserter | `Select_Ri cond,0` -> `TST + CSEL_NE` |
| FileCheck | complete |

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-coverage-correctness-gate
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-csel-combined-regression
```

关键结果：

| metric | value |
|---|---|
| original 29 micro object hit | 0 |
| selected benchmark | `csel_select64` |
| selected correctness | AWS native/kernel result correct |
| selected kfuncs | `bpf_arm64_tst`, `bpf_arm64_csel_ne` |
| performance | `csel_select64/kernel` treatment/control `1.06897` |

## 状态判断

`CSEL` 是 correctness-complete for selected target，但当前不是 performance win。它仍可保留
在 development branch 中，因为它验证了 combined pseudo 和 condition-code kfunc path。

## 后续

不要扩大 CSEL selector，除非找到能在 real workload 或 broader micro suite 中命中的 pattern。

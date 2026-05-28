# ARM64 LDR family report

## 结论

`LDR` family 当前是 correctness-complete on micro。已完成 `LDR_X`、`LDRH`、`LDR_W`
selected-safe subset；`LDRB` forced direct-load ABI coverage 也已由 2026-05-27 final AWS full
micro 覆盖。

对应 kfunc：

```text
bpf_arm64_ldrb
bpf_arm64_ldrh
bpf_arm64_ldr_w
bpf_arm64_ldr_x
```

`LDRB` 不进入默认策略的原因是普通 BPF `LDB` 已经能表达单字节 direct load；把它改成 kinsn
call 不会减少语义复杂度，反而增加 object / verifier / relocation 成本。

## 实现内容

已实现部分：

| target | selector scope | 状态 |
|---|---|---|
| `bpf_arm64_ldr_x` | selected-safe little-endian byte-ladder collapse | complete on micro |
| `bpf_arm64_ldrh` | selected-safe 2-byte load collapse | complete on micro |
| `bpf_arm64_ldr_w` | selected-safe 4-byte load collapse | complete on micro |
| `bpf_arm64_ldrb` | forced single-byte direct load | correctness-complete on micro; default disabled |

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/load-store.md
```

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ldr-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-ldr-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-llvm-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
```

关键结果：

| target | correctness | performance |
|---|---|---|
| `LDR_X` | AWS full micro correctness passed | selected benchmark code size down；runtime median neutral |
| `LDRH/LDR_W` | AWS correctness passed | selected kernel geomean treatment/control `0.968229` |
| `LDRB` | local object smoke passed | final AWS full micro correctness passed |

## 状态判断

`LDR` 在 correctness 层可以标为 development-complete on micro。`LDR_X` / `LDRH` / `LDR_W`
是 selected-safe optimizer；`LDRB` 是 forced ABI coverage，不应被写成默认 performance policy。

## 后续

后续 paper-grade run 应把 `LDRH/LDR_W` selected subset 和 `LDRB` forced ABI coverage 分开列出。

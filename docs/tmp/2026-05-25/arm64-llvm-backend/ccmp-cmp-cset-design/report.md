# ARM64 CCMP/CMP/CSET design

## 结论

本次只完成 `CCMP/CMP/CSET` family design，不修改 LLVM 代码、不运行 benchmark。

2026-05-26 状态更新：后续已经完成 LLVM implementation、local object smoke、AWS selected
correctness、AWS full micro correctness 和 same-LLC performance attribution。当前下一步不再是
implementation prep 或 performance attribution，而是 combined regression。记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-local-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-full-micro-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ccmp-performance-attribution
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/ccmp-performance-attribution/report.md
```

`CCMP/CMP/CSET` 的 module ABI 不是 arbitrary compare。它只表达：

```text
2 到 4 个 register 和 0 比较
  -> all-nonzero 或 all-zero
  -> materialize dst = 0 / 1
```

第一版实现范围应限制为 64-bit selected-safe subset：

```text
dst = (a != 0 && b != 0 [...]) ? 1 : 0
```

建议新增独立 policy key：

```text
-bpf-kinsn-mode=ccmp=force
```

原因是现有 `cmov=force` 已经控制 ARM64 `CSEL`。如果 `CCMP/CMP/CSET` 继续复用
`cmov`，same-LLC family attribution 不能把 CSEL 和 CCMP 的效果分开。

## 总体进度

总体目标：实现 ARM64 LLVM kinsn backend。LLVM BPF backend 在合适 pattern 上 emit
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，由 verifier 和 ARM64 module lower 成 native
AArch64 指令。

Family 总清单：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro |
| `EXTR` | 2 | development-complete on micro |
| `UBFM` | 1 | development-complete on micro |
| `LDR` | 4 | partial；`LDR_X`、`LDRH`、`LDR_W` selected-safe subset complete；`LDRB` deferred |
| `STR` | 4 | design-complete；selector deferred |
| `LDP/STP` | 2 | not started |
| `CSEL` | 2 | selected correctness、performance attribution、combined regression complete；不是 performance win |
| `CCMP/CMP/CSET` | 5 | development-complete on micro；不是 performance win |
| `PRFM` | 1 | not started |
| `MOV` | 1 | not started |

单个 family gate：

1. ABI / pattern design。
2. LLVM pseudo / AsmPrinter / selector / FileCheck。
3. local object smoke 和 target isolation。
4. AWS runtime correctness。
5. same-LLC performance attribution。
6. combined regression 和收尾复查。

本 design report 原始完成的是 `CCMP/CMP/CSET` 第 1 步；截至 2026-05-26，该 family 已完成到
第 5 步 same-LLC performance attribution。

## Module ABI

来源：

```text
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_ccmp.c
```

kfunc：

```text
bpf_arm64_cmp_x
bpf_arm64_cmp_w
bpf_arm64_ccmp_x
bpf_arm64_ccmp_w
bpf_arm64_cset_x_cond
```

`cmp_x/w` payload：

| bits | 字段 | 约束 |
|---|---|---|
| `0..3` | `reg` | `reg <= BPF_REG_10` |
| `4..63` | reserved | 必须为 0 |

`ccmp_x/w` payload：

| bits | 字段 | 约束 |
|---|---|---|
| `0..3` | `reg` | `reg <= BPF_REG_10` |
| `4..7` | `mode` | `0` 或 `1` |
| `8..63` | reserved | 必须为 0 |

`cset_x_cond` payload：

| bits | 字段 | 约束 |
|---|---|---|
| `0..3` | `dst_reg` | `<= BPF_REG_9` |
| `4..5` | `count_bits` | `count = count_bits + 2`，范围 `2..4` |
| `6` | `mode` | `0` 或 `1` |
| `7` | `width32` | 第一版使用 `0` |
| `8..23` | up to 4 regs | used reg `<= BPF_REG_10`，且不能等于 `dst_reg`；unused reg 必须为 0 |
| `24..63` | reserved | 必须为 0 |

mode 语义：

| mode | result |
|---:|---|
| `0` / `FAIL_EQ` | `dst = 1` iff 所有 regs 都非 0 |
| `1` / `FAIL_NE` | `dst = 1` iff 所有 regs 都等于 0 |

`cmp` 和 `ccmp` 的 proof expansion 都是 no-op；它们只在 native lowering 设置 flags。因此 LLVM
必须用 combined pseudo 保证 `cmp`、`ccmp`、`cset` 连续 emit。

## 第一版实现范围

建议第一版只做：

```text
64-bit all-nonzero chain
count = 2, 3, 4
dst materializes 0/1
```

暂缓：

- arbitrary `lhs/rhs` compare。
- mixed EQ/NE。
- OR。
- single-term。
- 32-bit compare。
- 独立 `CMP` / `CCMP` pseudo。

## LLVM 实现建议

新增 combined pseudo：

```text
BPF_KINSN_ARM64_CCMP_CSET_X2 dst, mode, r0, r1
BPF_KINSN_ARM64_CCMP_CSET_X3 dst, mode, r0, r1, r2
BPF_KINSN_ARM64_CCMP_CSET_X4 dst, mode, r0, r1, r2, r3
```

约束：

- `@earlyclobber $dst`，避免 `dst` 和 input regs 分到同一个 physical register。
- AsmPrinter 仍必须检查 `dst != input`。
- 第一版 `dst` 和 input 都限制为 `r0..r9`。

AsmPrinter emit 顺序：

```text
bpf_arm64_cmp_x(reg0)
bpf_arm64_ccmp_x(reg1, mode)
...
bpf_arm64_cset_x_cond(dst, count, mode, width32=0, regs)
```

selector 先从 selected-safe pattern 开始，不要一开始识别任意 branch tree：

```c
u64 ok2 = a && b;
u64 ok3 = a && b && c;
u64 ok4 = a && b && c && d;
```

## 验证计划

先新增 selected benchmark：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/ccmp_all_nonzero.bpf.c
```

然后按 gate 推进：

1. build + FileCheck：target guard、positive selector、negative cases、AsmPrinter 连续 emit。
2. local object smoke：`all=disable` 0 kfunc；`ccmp=force` 只出现 `bpf_arm64_cmp_x`、
   `bpf_arm64_ccmp_x`、`bpf_arm64_cset_x_cond`，且没有 `bpf_x86_*`。
3. AWS selected correctness：`BENCH=ccmp_all_nonzero`，`RUNTIMES="native kernel"`。
4. AWS full micro correctness。
5. same-LLC performance attribution：baseline、control-disabled、ccmp-only treatment。
6. combined regression：`REV+EXTR+UBFM+LDR+CSEL+CCMP`。

## 本次文件

详细设计记录：

```text
/home/ruoji/github/bpf-opt/docs/arm64-ccmp-cmp-cset-family-design.md
```

本 repo-facing 摘要：

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ccmp-cmp-cset-design/report.md
```

## 下一步

2026-05-26 状态更新：`CCMP/CMP/CSET` combined regression 已完成，记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-rev-extr-ubfm-ldr-csel-ccmp-combined-regression
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-26/arm64-llvm-backend/rev-extr-ubfm-ldr-csel-ccmp-combined-regression/report.md
```

Combined regression 验证了：

1. ARM64 combined treatment 打开 `unary`、`rotate`、`bextr`、`wide-load`、`cmov`、`ccmp`。
2. 检查 ARM64 combined object 没有 `bpf_x86_*`。
3. 检查 scoped x86 treatment 没有 `bpf_arm64_*`。
4. AWS full micro `native` / `kernel` 要求 0 failed sample。
5. selected targets `csel_select64` 和 `ccmp_all_nonzero` 必须仍命中各自 kfunc。

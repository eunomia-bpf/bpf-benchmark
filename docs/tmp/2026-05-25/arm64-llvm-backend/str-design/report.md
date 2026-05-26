# ARM64 LLVM backend STR design

日期：2026-05-25。

## 结论

本次只完成 `STR` family design，不修改 LLVM 代码。

结论是：暂不实现普通 direct `STR` selector。

原因是普通 BPF store 已经能紧凑表达同一条 verifier proof expansion，ARM64 JIT 也已经能
lower 成对应 native store。把普通 `BPF_STX_MEM` / `BPF_ST_MEM` 改成
`bpf_arm64_str*` kfunc 不会减少 proof expansion，也没有明确性能收益。

store widening 也暂缓。把多个 byte store 合并成一个更宽 store 会改变内存写粒度和可能的
可观察中间状态，风险高于 load-side byte-ladder collapse；当前没有 selected-safe pattern。

## 当前总体进度

ARM LLVM backend 的目标是在 LLVM BPF backend 中 emit ARM64 kinsn request：

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier proof expansion
  -> ARM64 module native lowering
```

当前 family 状态：

| Family | 状态 |
|---|---|
| `REV` | development-complete on micro |
| `EXTR` | development-complete on micro |
| `UBFM` | development-complete on micro |
| `LDR` | partial；`LDR_X`、`LDRH`、`LDR_W` selected-safe subset development-complete on micro；`LDRB` normal selector deferred |
| `STR` | design-complete；direct-store selector deferred，store-widening selector deferred |
| `LDP/STP` | not started |
| `CSEL` | design-complete；next gate is LLVM implementation |
| `CCMP/CMP/CSET` | not started |
| `PRFM` | not started |
| `MOV` | not started |

## ABI

来源：

```text
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_str.c
```

`STR` module 提供 4 个 kfunc：

| kfunc | register-store proof expansion | native lowering |
|---|---|---|
| `bpf_arm64_strb` | `BPF_STX_MEM(BPF_B, base, src, off)` | `STRB Wsrc, [Xbase, #off]` |
| `bpf_arm64_strh` | `BPF_STX_MEM(BPF_H, base, src, off)` | `STRH Wsrc, [Xbase, #off]` |
| `bpf_arm64_str_w` | `BPF_STX_MEM(BPF_W, base, src, off)` | `STR Wsrc, [Xbase, #off]` |
| `bpf_arm64_str_x` | `BPF_STX_MEM(BPF_DW, base, src, off)` | `STR Xsrc, [Xbase, #off]` |

Register-store tagged payload：

| bits | field | constraint |
|---|---|---|
| `0..3` | form | `ARM64_STR_FORM_REG = 1` |
| `4..7` | `src_reg` | `< BPF_REG_10` |
| `8..11` | `base_reg` | `<= BPF_REG_10` |
| `12..27` | `offset` | signed 16-bit |
| `28..63` | reserved | must be zero |

Legacy register-store payload：

| bits | field | constraint |
|---|---|---|
| `0..3` | `src_reg` | `< BPF_REG_10` |
| `4..7` | `base_reg` | `<= BPF_REG_10` |
| `8..23` | `offset` | signed 16-bit |
| `24..63` | reserved | must be zero |

`bpf_arm64_strb` 还支持 byte zero-store payload：

| bits | field | constraint |
|---|---|---|
| `0..3` | form | `ARM64_STR_FORM_ZERO = 2` |
| `4..7` | `base_reg` | `<= BPF_REG_10` |
| `8..23` | `offset` | signed 16-bit |
| `24..31` | `imm` | must be zero |
| `32..63` | reserved | must be zero |

zero-store proof expansion：

```text
BPF_ST_MEM(BPF_B, base_reg, offset, 0)
```

`STRH` / `STR_W` / `STR_X` 没有 immediate zero-store form。

## Offset Constraints

LLVM 如果以后 emit `STR` pseudo，必须先验证 ARM64 addressing mode 能编码 offset：

| kfunc | size | scaled unsigned offset | unscaled signed offset |
|---|---:|---|---|
| `bpf_arm64_strb` | 1 | `0 <= off <= 0xfff` | `-256 <= off <= 255` |
| `bpf_arm64_strh` | 2 | `0 <= off <= 0xfff << 1`, aligned 2 | `-256 <= off <= 255` |
| `bpf_arm64_str_w` | 4 | `0 <= off <= 0xfff << 2`, aligned 4 | `-256 <= off <= 255` |
| `bpf_arm64_str_x` | 8 | `0 <= off <= 0xfff << 3`, aligned 8 | `-256 <= off <= 255` |

## Selector Decision

| 候选 selector | 结论 | 原因 |
|---|---|---|
| 普通 register store -> `bpf_arm64_str*` | deferred | 普通 BPF `BPF_STX_MEM` 已经是相同 proof expansion；没有 code-size 或语义表达收益。 |
| byte zero store -> `bpf_arm64_strb` zero form | deferred | 普通 BPF `BPF_ST_MEM(BPF_B, base, off, 0)` 已经紧凑表达。 |
| 多个 byte store -> wider `STRH/STR_W/STR_X` | deferred | 会改变写粒度和可能的 alias / ordering 语义；没有安全 proof。 |
| store-release / atomic store -> normal `STR` | forbidden | memory ordering 语义不同。 |

## Verification Impact

因为本次不改 LLVM 代码，也不新增 selector，不需要运行 LLVM build、FileCheck、object smoke 或
AWS benchmark。需要验证的是文档一致性：

```text
/home/ruoji/github/bpf-opt/docs/arm64-load-store-family-design.md
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-implementation-plan.md
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend-guide.md
/home/ruoji/github/bpf-opt/docs/arm64-kinsn-experiment-matrix.md
```

## 下一步

`CSEL` design 和 targeted LLVM implementation 已完成，但当前 29 个 micro object 0 hit。
下一步进入 CSEL coverage/correctness gate。继续实现前仍需要重读：

```text
/home/ruoji/github/bpf-opt/actions/01-code-change-flow.md
/home/ruoji/github/bpf-opt/actions/04-submodule-flow.md
/home/ruoji/github/bpf-opt/actions/07-arm-llvm-backend-flow.md
```

核心设计记录：

```text
/home/ruoji/github/bpf-opt/docs/arm64-csel-family-design.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/csel-design/report.md
```

# ARM64 LLVM backend CSEL design

日期：2026-05-25。

## 结论

`CSEL` design 已完成，后续 targeted LLVM implementation 也已完成。第一版只做 selected-safe subset：

```text
dst = (cond_reg != 0) ? true_reg : false_reg
```

不做 arbitrary compare，不做 32-bit selected value，不做 branch diamond peephole，不做
compound conditions。

实现方式应使用一个 combined LLVM pseudo，一次连续 emit：

```text
bpf_arm64_tst
bpf_arm64_csel_ne
```

不要生成两个独立 MachineInstr 后依赖它们保持相邻。native `CSEL` 依赖前一条 `TST`
设置的 flags。

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

| Family | kfunc count | 状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro |
| `EXTR` | 2 | development-complete on micro |
| `UBFM` | 1 | development-complete on micro |
| `LDR` | 4 | partial；`LDR_X/LDRH/LDR_W` selected-safe subset complete；`LDRB` deferred |
| `STR` | 4 | design-complete；selector deferred |
| `CSEL` | 2 | design-complete；next gate is LLVM implementation |
| `CCMP/CMP/CSET` | 5 | not started |
| `LDP/STP` | 2 | not started |
| `PRFM` | 1 | not started |
| `MOV` | 1 | not started |

## ABI

来源：

```text
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_csel.c
```

目标 kfunc：

```text
bpf_arm64_tst
bpf_arm64_csel_ne
```

`bpf_arm64_tst` payload：

| bits | field | constraint |
|---|---|---|
| `0..3` | `reg` | `<= BPF_REG_10` |
| `4..63` | reserved | must be zero |

proof expansion is no-op:

```text
BPF_JMP_A(0)
```

native lowering:

```text
TST Xreg, Xreg
```

`bpf_arm64_csel_ne` payload：

| bits | field | constraint |
|---|---|---|
| `0..3` | `dst_reg` | `<= BPF_REG_10` |
| `4..7` | `true_reg` | `<= BPF_REG_10` |
| `8..11` | `false_reg` | `<= BPF_REG_10` |
| `12..15` | `cond_reg` | `<= BPF_REG_10` |
| `16..63` | reserved | must be zero |

proof expansion:

```text
if cond_reg == 0:
  dst_reg = false_reg
else:
  dst_reg = true_reg
```

native lowering:

```text
CSEL Xdst, Xtrue, Xfalse, NE
```

## Selector Scope

First implementation should match only:

```text
target == arm64
policy cmov enabled / forced
opcode == Select_Ri
rhs immediate == 0
CC == SETNE or SETEQ
selected value is 64-bit GPR
all regs are r0..r9
```

Mapping:

```text
SETNE lhs, 0:
  TST+CSEL_NE dst, lhs, truev, falsev

SETEQ lhs, 0:
  TST+CSEL_NE dst, lhs, falsev, truev
```

Use existing policy key:

```text
-bpf-kinsn-mode=cmov=force
```

## Coverage Evidence

Source:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression/data/object-programs-arm64-all-disable/*.bpf.ll
```

IR-level count:

```text
total select i1: 79
i64 selected value: 11
i32 selected value: 10
i1 selected value: 56
```

i64 candidates:

| benchmark | i64 select count |
|---|---:|
| `katran_lb_consistent_hash_select` | 8 |
| `cgroup_skb_hash_chain` | 1 |
| `sorted_rule_binary_search` | 1 |
| `tetragon_process_event_arg_filter` | 1 |

This is only an over-approximation. Object smoke must report real
`bpf_arm64_tst` / `bpf_arm64_csel_ne` relocation counts.

## Verification Plan

After implementation:

1. Build LLVM `LLVMBPFCodeGen llc`.
2. Add FileCheck for SETNE, SETEQ operand swap, all-disable, x86 target isolation, nonzero RHS
   negative case, register-register compare negative case, and i32 negative case.
3. Run local object smoke through `make -C micro/programs`.
4. Run AWS selected correctness using the first benchmark that actually emits CSEL.
5. Run AWS full micro correctness with `RUNTIMES="native kernel"`.
6. Run same-LLC performance attribution: baseline, all-disable control, CSEL-only treatment.
7. Run combined regression:

```text
REV+EXTR+UBFM+LDR_X+LDRH+LDR_W+CSEL
```

## 下一步

下一步是 LLVM implementation。Core files:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFInstrInfo.td
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFAsmPrinter.cpp
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm/llvm/lib/Target/BPF/BPFISelLowering.cpp
```

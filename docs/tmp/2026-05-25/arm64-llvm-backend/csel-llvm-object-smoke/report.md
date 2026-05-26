# 2026-05-25 arm64 CSEL LLVM object smoke

## 结论

CSEL 第一版 LLVM targeted implementation 已完成并通过 build / FileCheck / Makefile object
smoke，但当前 29 个 micro object 没有实际命中 `bpf_arm64_tst` 或 `bpf_arm64_csel_ne`。

这份 public tmp report 对应本地完整记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-llvm-object-smoke
```

## 实现内容

LLVM 子模块：

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm
```

本次 CSEL 相关实现点：

- `llvm/lib/Target/BPF/BPFInstrInfo.td`：新增 `BPF_KINSN_ARM64_TST_CSEL_NE` combined pseudo。
- `llvm/lib/Target/BPF/BPFAsmPrinter.cpp`：新增 TST / CSEL payload packer，并连续 emit
  `bpf_arm64_tst` 与 `bpf_arm64_csel_ne`。
- `llvm/lib/Target/BPF/BPFISelLowering.cpp`：ARM64 target 下匹配 `Select_Ri cond,0` 的
  64-bit `SETNE` / `SETEQ` select。
- `llvm/test/CodeGen/BPF/kinsn-arm64-csel-select.ll`：覆盖正反例。
- `llvm/test/CodeGen/BPF/kinsn-arm64-pseudos.mir`：覆盖 payload 数字。

## 验证命令

```bash
cd /home/ruoji/github/bpf-opt
ninja -C code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4

cd /home/ruoji/github/bpf-opt/code
llvm-backend/build-bpf-kinsn/bin/llc \
  -mtriple=bpfel -mcpu=v4 -verify-machineinstrs \
  -bpf-enable-kinsn-select \
  -bpf-kinsn-target=arm64 \
  -bpf-kinsn-mode=all=disable \
  -bpf-kinsn-mode=cmov=force \
  < llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-csel-select.ll \
  | llvm-backend/build-bpf-kinsn/bin/FileCheck \
      llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-csel-select.ll
```

Object smoke 使用 Makefile 入口：

```bash
cd /home/ruoji/github/bpf-opt
make -C /home/ruoji/github/bpf-opt/code/micro/programs \
  OUTPUT_DIR=/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-llvm-object-smoke/data/object-programs-arm64-csel \
  KERNEL_OFFSETS_INPUT=/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=cmov=force" \
  all
```

## 结果

| check | result |
|---|---|
| LLVM build | pass |
| CSEL FileCheck | pass |
| ARM64 pseudo payload FileCheck | pass |
| `all=disable` object smoke | 29/29 objects |
| `cmov=force` object smoke | 29/29 objects |

Object symbol summary：

| case | objects | ARM64 symbol objects | x86 symbol objects | `bpf_arm64_tst` objects | `bpf_arm64_csel_ne` objects |
|---|---:|---:|---:|---:|---:|
| `arm64-all-disable` | 29 | 0 | 0 | 0 | 0 |
| `arm64-csel` | 29 | 0 | 0 | 0 | 0 |

## 限制

当前没有 CSEL runtime correctness 结论，也没有 performance 结论。原因是 current 29 micro object
没有实际 CSEL hit；targeted FileCheck 证明 compiler path 正确，但不能替代 runtime gate。

## 下一步

进入 CSEL coverage/correctness gate：确认真实 micro lowering shape，或补一个能稳定命中
`Select_Ri cond,0` 的 selected correctness target。有真实 CSEL object hit 后，再跑 AWS
selected correctness、full micro correctness、same-LLC attribution 和 combined regression。

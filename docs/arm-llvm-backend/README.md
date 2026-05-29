# ARM64 LLVM Backend

本文档目录是 ARM64 LLVM kinsn backend 的稳定入口。这里的 backend 不是新增普通
AArch64 backend，而是在 LLVM 的 BPF backend 中实现 ARM64 kinsn-aware lowering：

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL
  -> bpf_arm64_* kfunc
  -> kernel verifier / module / JIT
  -> native AArch64 instruction
```

## 当前总报告

当前对外技术报告：

```text
docs/arm-llvm-backend/technical-report-2026-05-29.md
```

该报告自包含说明：

- 项目目标和基本概念。
- `KINSN_SIDECAR + KINSN_CALL` 的 BPF object 形态。
- ARM64 kinsn family 的实现范围。
- micro benchmark 的运行流程、AWS 设置、指标定义和结果。
- family-only、true all-on、candidate default policy 和 targeted JIT dump attribution 的结论。

## 当前实现范围

Family 总清单：

```text
REV(3), EXTR(2), UBFM(1), LDR(4), STR(4), LDP/STP(2),
CSEL(2), CCMP/CMP/CSET(5), PRFM(1), MOV(1)
```

截至 2026-05-29，已有 ARM64 module ABI 的 25 个 `bpf_arm64_*` target 已进入 LLVM，并完成
development-grade correctness。当前默认候选策略是：

```text
EXTR + selected LDR
```

其他 family 已有 coverage / correctness，但当前 micro 数据不足以支持默认启用。

## 实验结果位置

稳定总报告放在本目录；一次性实验公开快照仍放在：

```text
docs/tmp/YYYY-MM-DD/arm64-llvm-backend/
```

主要公开实验快照：

```text
docs/tmp/2026-05-27/arm64-llvm-backend/same-llc-attribution/
docs/tmp/2026-05-28/arm64-llvm-backend/true-all-on-attribution/
docs/tmp/2026-05-28/arm64-llvm-backend/candidate-default-policy-attribution/
```

原始实验记录保存在顶层工作区：

```text
/home/ruoji/github/bpf-opt/experiments/
```

注意：顶层工作区不是本 git 仓库；随代码发布的文档必须放在
`/home/ruoji/github/bpf-opt/code/docs/` 下。

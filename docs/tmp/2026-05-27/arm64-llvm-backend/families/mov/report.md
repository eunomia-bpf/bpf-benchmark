# ARM64 MOV family report

## 结论

`MOV` family 已完成 forced object path，但不进入默认策略。

对应 kfunc：

```text
bpf_arm64_mov_x
```

原因：`bpf_arm64_mov_x` 的 proof expansion 是普通 `BPF_MOV64_REG(dst, src)`，而 ARM64
BPF JIT 已经把普通 `MOV64_REG` lower 成同一条 native `MOV Xdst, Xsrc`。因此 selector 不会
减少 native instruction，反而会增加 object / xlated / verifier 成本。forced selector 只用于
已有 ABI 完整性和 FileCheck 覆盖。

## 设计说明

设计文档：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/mov.md
```

原始公开设计记录已经合并进本 report，旧的 `mov-design` 临时目录不再作为权威入口。

## 实验状态

已运行 FileCheck / pseudo emit；combined micro object 没有自然命中 `bpf_arm64_mov_x`，因为普通
BPF copy 会被 pipeline 合并或消除。记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
```

## 后续

不要把 MOV 放进默认策略，除非 ARM64 module 或 JIT 行为变化导致普通 `MOV64_REG` 不再生成
同等 native MOV。

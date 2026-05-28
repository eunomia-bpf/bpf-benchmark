# ARM64 STR family report

## 结论

`STR` family 已完成 forced direct-store ABI coverage，并已由 2026-05-27 final AWS full micro
correctness 覆盖。

对应 kfunc：

```text
bpf_arm64_strb
bpf_arm64_strh
bpf_arm64_str_w
bpf_arm64_str_x
```

direct-store 不进入默认策略不是遗漏。原因是普通 direct store 已经能由 BPF `STX_MEM` /
`ST_MEM` 表达；store-widening 会改变内存写粒度，可能引入 alias / ordering 风险，不能仅凭
native instruction count 判断安全。

## 设计结论

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/load-store.md
```

| option | decision | reason |
|---|---|---|
| forced direct-store selector | completed locally | 用于 ABI 完整性和显式实验，不进默认策略。 |
| zero-store selector | deferred | 收益不清楚，且需要额外 proof。 |
| store-widening selector | deferred | 可能改变写粒度和 alias / ordering 语义。 |

## 实验状态

local object smoke 和 final AWS full micro correctness 已运行并通过，记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
```

combined treatment 命中：

| symbol | relocations |
|---|---:|
| `bpf_arm64_strb` | 1 |
| `bpf_arm64_strh` | 1 |
| `bpf_arm64_str_w` | 1 |
| `bpf_arm64_str_x` | 1 |

final AWS full micro correctness：34 个 benchmark、68 个 runtime sample、0 个 bad sample。

## 后续

除非先找到明确的 selected pattern 和安全 proof，否则不要把 `STR` 放进默认策略，也不要做
store-widening。

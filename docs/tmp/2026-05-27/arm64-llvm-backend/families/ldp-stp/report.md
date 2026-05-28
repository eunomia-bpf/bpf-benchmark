# ARM64 LDP/STP family report

## 结论

`LDP/STP` family 的 stack-only subset 已达到 development-complete on micro。

对应 kfunc：

```text
bpf_arm64_ldp_x
bpf_arm64_stp_x
```

第一版明确不做通用 pair-memory optimizer，只做 selected-safe stack pair pattern。

## 实现内容

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/ldp-stp.md
```

已完成：

| target | selector scope | 状态 |
|---|---|---|
| `bpf_arm64_stp_x` | stack-only pair store | complete on micro |
| `bpf_arm64_ldp_x` | stack-only pair load | complete on micro |

同时加固了 `/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_ldp.c` reserved-bit 检查。

## 实验结果

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-stp-full-micro-combined-regression
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-object-smoke
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-aws-correctness
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-performance-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-ldp-full-micro-combined-regression
```

`STP_X`：

| metric | value |
|---|---|
| object smoke | 32 objects generated; only `stp_stack_pair` hits `bpf_arm64_stp_x` |
| AWS correctness | native/kernel result both `274886295554` |
| native evidence | `stp x0, x1, [x25, #-16]` |
| performance | `stp_stack_pair/kernel` treatment/control `0.909091` |
| combined regression | 32 benchmarks, 64 runtime samples, 0 failed sample |

`LDP_X`：

| metric | value |
|---|---|
| object smoke | 33 objects generated; only `ldp_stack_pair` hits `bpf_arm64_ldp_x` |
| AWS correctness | native/kernel result both `274886295554` |
| native evidence | `ldp x1, x0, [x25, #-16]` |
| performance | `ldp_stack_pair/kernel` treatment/control `1.000`; native bytes 352 -> 344 |
| combined regression | 33 benchmarks, 66 runtime samples, 0 failed sample |

## 状态判断

`STP_X` 有明确 selected micro win。`LDP_X` runtime neutral，但减少 native code size。
该 family 只在 selected-safe stack-only scope 下完成，不代表 arbitrary memory pair 已完成。

## 后续

不要扩展到 generic memory pair selector，除非先完成 alias / verifier / proof safety design。

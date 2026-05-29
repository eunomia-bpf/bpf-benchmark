# 2026-05-28 arm64-candidate-default-policy-attribution

## 结论

本实验完成，状态是 `completed`。

实验问题：在 ARM64 LLVM backend 已有 selector 中，默认 policy 应该优先启用
`EXTR + selected LDR`，还是扩大到 `EXTR + selected LDR + CSEL`？

结论：

- `control-disabled` object 生成 34 个 BPF object，0 个 `bpf_arm64_*` relocation。
- `candidate-conservative` object 生成 34 个 BPF object，234 个 ARM64 relocation：
  `EXTR=162`、`LDR=72`。
- `candidate-expanded` object 生成 34 个 BPF object，238 个 ARM64 relocation：
  `EXTR=162`、`LDR=72`、`CSEL=4`。
- 三组都没有 `bpf_x86_*` relocation。
- AWS ARM64 full micro 12 个 run 全部 rc=0；每个 run 34 个 benchmark，
  `native` / `kernel` 各 102 个 sample；总计 2448 个 runtime sample，0 个 bad sample。
- `candidate-conservative / control-disabled` 的 kernel all geomean 三轮都 faster，
  中位数 `0.940471563`，约 `5.95%` faster。
- `candidate-expanded / control-disabled` 的 kernel all geomean 三轮都 faster，
  中位数 `0.932466234`，约 `6.75%` faster。
- 但是 `candidate-expanded / candidate-conservative` 的 kernel all geomean 中位数是
  `1.000359815`，不是稳定额外收益。
- `CSEL` 只在 `csel_select64` 触发 4 个 relocation；该 benchmark 在 conservative
  已经是 `0.607142857`，expanded 没有稳定进一步改善。

因此，development-grade 默认策略建议是：

```text
default candidate = EXTR + selected LDR
do not add CSEL to default policy yet
keep PRFM and MOV default-disabled
```

这不是 paper-grade 结论；它是当前 micro suite 上的默认 policy 选择依据。

## 总体进度

总体目标：实现 ARM64 LLVM backend。这里的 backend 不是新增普通 AArch64 backend，而是在
LLVM BPF backend 中识别 BPF MachineInstr pattern，emit
`KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，再由 verifier / ARM64 kinsn module lower 成
native AArch64 instruction。

Family 总清单：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro |
| `EXTR` | 2 | development-complete on micro |
| `UBFM` | 1 | development-complete on micro |
| `LDR` | 4 | correctness-complete on micro；selected-safe subset 有默认候选价值 |
| `STR` | 4 | correctness-complete on micro；forced ABI coverage，不进默认策略 |
| `LDP/STP` | 2 | stack-only subset complete |
| `CSEL` | 2 | selected target complete；当前不进默认策略 |
| `CCMP/CMP/CSET` | 5 | selected-safe subset complete；当前不进默认策略 |
| `PRFM` | 1 | forced path complete；default disabled |
| `MOV` | 1 | forced path complete；default disabled |

当前 gate：

```text
已实现 family -> same-LLC attribution -> true all-on stability -> candidate default policy attribution
```

本实验就是最后这一层：决定哪些已实现 selector 应该进入默认候选 policy。

下一步：把 default policy 决策写回 ARM LLVM backend 总文档；后续如果要继续提高覆盖，应先做
corpus / e2e 方案，而不是继续把非 win family 加进默认 policy。

## 实验问题

micro benchmark 中每个 case 只会触发一部分 kinsn。全开并不意味着每个 case 都用到所有
kinsn；一个 case 的加速必须和它实际触发的 relocation 对齐。

本实验比较四组：

| group | 作用 |
|---|---|
| `baseline` | 普通 clang baseline，用于观察自然漂移。 |
| `control-disabled` | 同一个 custom `llc`，但 `-bpf-kinsn-mode=all=disable`，作为 same-LLC control。 |
| `candidate-conservative` | `all=disable` 后只 force `rotate,wide-load,direct-load`，即 `EXTR + selected LDR`。 |
| `candidate-expanded` | conservative 再加 `cmov=force`，即额外打开 `CSEL`。 |

正确比较口径：

```text
candidate-conservative / control-disabled
candidate-expanded / control-disabled
candidate-expanded / candidate-conservative
```

如果 expanded 只相对 control 更快，但相对 conservative 不快，说明额外 `CSEL` 不应进入默认
policy。

## 命令

工作目录：

```text
/home/ruoji/github/bpf-opt
```

配置检查：

```bash
./aws-config/check.sh arm64
```

LLVM build：

```bash
ninja -C code/llvm-backend/build-bpf-kinsn LLVMBPFCodeGen llc -j4
```

本地 object smoke 通过 Makefile `.bpf.o` target 生成，避免本地 native `.so` cross compile
环境差异影响 object-level selector 结论。关键 flags：

```text
control-disabled:
  -disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable

candidate-conservative:
  -disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
  -bpf-kinsn-mode=rotate=force,wide-load=force,direct-load=force

candidate-expanded:
  -disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
  -bpf-kinsn-mode=rotate=force,wide-load=force,direct-load=force,cmov=force
```

AWS full micro 每个 group 跑 3 轮。共同参数：

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
./aws-config/run.sh arm64 micro \
  RUNTIMES=native kernel \
  SAMPLES=3 \
  WARMUPS=0 \
  INNER_REPEAT=100000
```

treatment 额外参数：

```bash
BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm
BPF_KINSN_LLC=/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc
BPF_KINSN_LLC_FLAGS="<group-specific flags>"
```

清理：

```bash
./aws-config/run.sh arm64 terminate
```

## 环境

| item | value |
|---|---|
| workspace | `/home/ruoji/github/bpf-opt` |
| code repo | `/home/ruoji/github/bpf-opt/code` |
| LLVM submodule | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm` |
| custom `llc` | `/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc` |
| platform | AWS |
| arch | ARM64 |
| region | `us-east-1` |
| instance type | `t4g.small` |
| remote user | `ec2-user` |
| kernel release | `7.0.0-rc2+` |
| container image | `bpf-benchmark/runner-runtime:arm64` |
| runtimes | `native kernel` |

## 文件改动

本实验没有改 LLVM、runner、module 或 benchmark framework code。

新增实验记录和外部 analysis 文件：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-candidate-default-policy-attribution
```

同步更新文档：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/implementation-plan.md
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/experiment-matrix.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/report.md
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-28/arm64-llvm-backend/candidate-default-policy-attribution/report.md
```

## 数据文件

关键数据：

| file | 内容 |
|---|---|
| `analysis/result-map.tsv` | 12 个 AWS run 的 result directory 和 rc。 |
| `analysis/object-group-summary.tsv` | 每组 object 数、ARM64/x86 relocation 数。 |
| `analysis/object-family-summary.tsv` | 每组按 family 汇总的 relocation。 |
| `analysis/object-symbols.tsv` | 每个 object 的 kfunc symbol 和引用次数。 |
| `analysis/triggered-kinsn-by-benchmark.tsv` | 每个 benchmark 实际触发哪些 family。 |
| `analysis/raw-samples.tsv` | 2448 个 runtime sample。 |
| `analysis/correctness-summary.tsv` | 每组每个 runtime 的 bad sample 数。 |
| `analysis/median-summary.tsv` | 每个 rep/group/benchmark/runtime 的 median exec ns。 |
| `analysis/ratio-summary.tsv` | 每个 benchmark 的三轮 ratio 和方向。 |
| `analysis/geomean-by-rep-scope.tsv` | 每轮 geomean ratio。 |
| `analysis/geomean-stability.tsv` | 三轮稳定性汇总。 |
| `analysis/summary.json` | 机器可读总结。 |
| `analysis/aws-cost-summary.tsv` | AWS wall time 和费用估算。 |
| `analysis/aws-cleanup-summary.tsv` | 清理状态。 |

原始 runner result 已复制到：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-candidate-default-policy-attribution/attempts/*/data/aws_arm64_micro_*/details/result.json
```

## 问题和处理

- 初始本地 object smoke 使用完整 `make ... all` 时，默认尝试读取本地 x86
  `vendor/build/x86/linux/vmlinux`，该文件不存在。这个失败是本地 object-smoke 环境问题，
  不是 ARM64 selector 问题；记录在 `data/objects-initial-failed/`。
- 改成显式 ARM64 `KERNEL_VMLINUX` 后，本地 native `.so` cross compile 命中
  `gnu/stubs-32.h` include-path 问题。这个失败是本地 native artifact 问题，不影响 BPF
  object selector；记录在 `data/objects-native-cross-failed/`。
- 最终 object smoke 通过 Makefile `.bpf.o` target 完成，仍然通过 Makefile 入口，没有绕过
  benchmark framework。
- 第 3 轮 conservative / expanded 的 AWS setup 时间偏长，但最终 rc=0；报告保留原始日志。

## Object 结果

| case | objects | objects with ARM64 kfunc | ARM64 refs | x86 refs |
|---|---:|---:|---:|---:|
| `control-disabled` | 34 | 0 | 0 | 0 |
| `candidate-conservative` | 34 | 27 | 234 | 0 |
| `candidate-expanded` | 34 | 27 | 238 | 0 |

按 family：

| case | family | refs |
|---|---|---:|
| `candidate-conservative` | `EXTR` | 162 |
| `candidate-conservative` | `LDR` | 72 |
| `candidate-expanded` | `EXTR` | 162 |
| `candidate-expanded` | `LDR` | 72 |
| `candidate-expanded` | `CSEL` | 4 |

## Runtime 正确性

| group | runtime | samples | bad samples |
|---|---|---:|---:|
| `baseline` | `kernel` | 306 | 0 |
| `baseline` | `native` | 306 | 0 |
| `control-disabled` | `kernel` | 306 | 0 |
| `control-disabled` | `native` | 306 | 0 |
| `candidate-conservative` | `kernel` | 306 | 0 |
| `candidate-conservative` | `native` | 306 | 0 |
| `candidate-expanded` | `kernel` | 306 | 0 |
| `candidate-expanded` | `native` | 306 | 0 |

## Performance 结果

三轮 geomean stability：

| group | compare_to | runtime | scope | median geomean ratio | median faster |
|---|---|---|---|---:|---:|
| `baseline` | `control-disabled` | `kernel` | `ALL` | 1.002415411 | -0.24% |
| `candidate-conservative` | `control-disabled` | `kernel` | `ALL` | 0.940471563 | 5.95% |
| `candidate-conservative` | `control-disabled` | `kernel` | `TOUCHED` | 0.920124037 | 7.99% |
| `candidate-expanded` | `control-disabled` | `kernel` | `ALL` | 0.932466234 | 6.75% |
| `candidate-expanded` | `control-disabled` | `kernel` | `TOUCHED` | 0.920515841 | 7.95% |
| `candidate-expanded` | `control-disabled` | `kernel` | `CSEL` | 0.607142857 | 39.29% |
| `candidate-expanded` | `candidate-conservative` | `kernel` | `ALL` | 1.000359815 | -0.04% |
| `candidate-expanded` | `candidate-conservative` | `kernel` | `TOUCHED` | 0.999617859 | 0.04% |
| `candidate-expanded` | `candidate-conservative` | `kernel` | `CSEL` | 1.000000000 | 0.00% |
| `candidate-conservative` | `control-disabled` | `native` | `ALL` | 0.999972404 | 0.00% |
| `candidate-expanded` | `control-disabled` | `native` | `ALL` | 1.015307844 | -1.53% |

关键解释：

- Conservative 和 expanded 相对 control 都快。
- Expanded 相对 conservative 基本持平；ALL scope 中位数略慢，`CSEL` scope 中位数正好
  `1.0`。
- 因此 expanded 的绝对快，主要继承自 `EXTR + LDR`；额外 `CSEL` 没有稳定贡献。

Benchmark direction summary：

| comparison | runtime | all faster | all slower | all equal | mixed |
|---|---|---:|---:|---:|---:|
| conservative / control | kernel | 10 | 2 | 2 | 20 |
| expanded / control | kernel | 14 | 3 | 1 | 16 |
| expanded / conservative | kernel | 5 | 0 | 1 | 28 |

## AWS 时间和费用

每个 AWS run 使用 `t4g.small`、32 GB gp3 root volume。

价格来源：

| item | source | price |
|---|---|---:|
| compute | AWS Price List API, `t4g.small`, Linux, us-east-1 | `$0.0168 / hour` |
| EBS | AWS Price List API, gp3, us-east-1 | `$0.08 / GB-month` |

费用估算：

```text
total upper-bound estimate: $0.038999165
```

该估算使用本地 wrapper start/end wall time 作为上界，因此包含少量本地 wrapper / setup
等待，不是精确账单值。估算不包含 data transfer、税、free tier、credits、Savings Plans、
Reserved Instances 或账户级折扣。

清理结果：

| check | value |
|---|---|
| terminate exitcode | 0 |
| active instances after terminate | 0 |

## 后续

建议把默认 policy 暂定为：

```text
rotate=force,wide-load=force,direct-load=force
```

不要把 `cmov=force` 加入默认 policy。下一步如果继续做性能，应优先设计 corpus / e2e
experiment，而不是继续扩大 micro default policy。

## 收尾一致性复查

已回看：

- 当前实验所有失败/重试尝试：
  - `data/objects-initial-failed`
  - `data/objects-native-cross-failed`
  - 12 个 AWS attempt log
- 前序相关实验：
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution`
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-28-arm64-true-all-on-same-llc-attribution`
- 相关文档：
  - `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/implementation-plan.md`
  - `/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/experiment-matrix.md`
  - `/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-27/arm64-llvm-backend/report.md`

发现和处理：

- 当前实验没有代码改动，因此没有新增冗余代码或 workaround。
- 旧 true-all-on 结论仍成立：all-on kernel full micro 稳定 faster，但不能解释默认 policy。
- 本实验补上了默认 policy 决策层：expanded 相对 conservative 没有稳定额外收益。
- 已同步更新 ARM LLVM backend implementation plan、experiment matrix 和公开大报告。

是否重跑：

- 本实验已经完成 3 轮独立 AWS run；所有 run rc=0，0 bad sample。
- 收尾只会更新文档和 public report，不需要重跑 benchmark。

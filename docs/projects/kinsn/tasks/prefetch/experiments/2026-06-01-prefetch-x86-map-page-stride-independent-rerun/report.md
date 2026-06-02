# 2026-06-01 prefetch-x86-map-page-stride-independent-rerun

## 结论

本实验完成，状态是 `completed_no_default_enable_evidence`。

实验问题是：上一轮 x86 paired attribution 中，`prefetch_map_page_stride` 对
`bpf_x86_prefetcht0` 有弱 positive signal；这次用 3 轮独立 AWS control/treatment pair
确认这个信号是否稳定。

结论：x86 `PREFETCHT0` codegen 符合预期，但性能结果不够稳定，不能支持默认启用 prefetch。

- treatment 每个 sample 都命中 1 个 prefetch site，并在 JIT native dump 中出现 1 条
  `prefetcht0`。
- native code size 从 494 bytes 增加到 498 bytes，objdump 统计从 133 条 native instruction
  增加到 134 条。
- `exec_ns` 的 3 轮 treatment/control ratio 是 `1.0793`、`1.0117`、`0.9913`，geomean
  `1.0268`，即 ktime 口径下约 2.68% slower。
- `wall_exec_ns` / `exec_cycles` 的 3 轮 ratio 分别是 `0.8543`、`1.0001`、`0.9230`，
  geomean 约 `0.9239`，即 wall/cycles 口径下约 7.61% faster。
- 两个 timing source 方向相反，因此这个结果只能说明 x86 map-page-stride 是值得继续研究的
  candidate，不能作为 default policy 证据。

## 实验问题

当前 Kinsn prefetch task 要判断 `PREFETCHT0` / `PRFM` 能否成为默认启用的 kinsn family。
本实验只回答其中一个小问题：

```text
在 x86 AWS kernel micro runtime 上，map-backed page-stride access 插入 1 条
PREFETCHT0 后，是否能跨独立 run 稳定变快？
```

这里的 control 是 `BPFREJIT_BENCH_PASSES=noop`；treatment 是
`BPFREJIT_BENCH_PASSES=prefetch`。两组都通过同一个 AWS x86 Makefile/wrapper 路径运行。

## 命令

工作区：

```bash
cd /home/ruoji/github/bpf-opt
```

配置检查：

```bash
/home/ruoji/github/bpf-opt/aws-config/check.sh x86
```

每轮 control：

```bash
BPFREJIT_BENCH_PASSES=noop \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

每轮 treatment：

```bash
BPFREJIT_BENCH_PASSES=prefetch \
  /home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

实际执行顺序是 3 轮独立 pair：

```text
rep1: control -> treatment
rep2: control -> treatment
rep3: control -> treatment
```

全部 benchmark 通过 `/home/ruoji/github/bpf-opt/aws-config/run.sh` wrapper，底层走
`code/` 仓库 Makefile 入口，没有直接调用 runner Python。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS
- arch：x86
- instance type：`t3.small`
- region：`us-east-1`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- runtime container image：`bpf-benchmark/runner-runtime:x86_64`
- benchmark：`prefetch_map_page_stride`
- runtime：`kernel`
- samples：5
- warmups：1
- inner repeat：10000

## 文件改动

本实验没有修改代码。

新增 / 更新：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/data/aws-results/`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/data/aws-logs/`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/analysis/`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`

## 数据文件

原始数据副本：

- `data/run-contract.json`
- `data/local-logs/r1-control.log`
- `data/local-logs/r1-treatment.log`
- `data/local-logs/r2-control.log`
- `data/local-logs/r2-treatment.log`
- `data/local-logs/r3-control.log`
- `data/local-logs/r3-treatment.log`
- `data/aws-results/aws_x86_micro_20260601_231529_057545`
- `data/aws-results/aws_x86_micro_20260601_232136_911736`
- `data/aws-results/aws_x86_micro_20260601_232921_956048`
- `data/aws-results/aws_x86_micro_20260601_233617_042359`
- `data/aws-results/aws_x86_micro_20260601_234227_898339`
- `data/aws-results/aws_x86_micro_20260601_235047_421249`
- `data/aws-logs/*.remote.log`
- `data/aws-instance-state.json`
- `data/aws-active-before.json`
- `data/aws-active-after.json`

分析文件：

- `analysis/raw-samples.tsv`
- `analysis/summary.tsv`
- `analysis/pair-ratio.tsv`
- `analysis/codegen-evidence.tsv`
- `analysis/aws-cost-summary.tsv`

## 结果

`analysis/pair-ratio.tsv` 的核心结果如下。ratio 小于 1 表示 treatment 更快。

| rep | `exec_ns` ratio | `wall_exec_ns` ratio | `exec_cycles` ratio | native bytes ratio | BPF bytes ratio |
|---:|---:|---:|---:|---:|---:|
| 1 | `1.079341` | `0.854285` | `0.854259` | `1.008097` | `1.017391` |
| 2 | `1.011735` | `1.000077` | `1.000062` | `1.008097` | `1.017391` |
| 3 | `0.991316` | `0.922988` | `0.923004` | `1.008097` | `1.017391` |
| geomean | `1.026784` | `0.923870` | `0.923861` | `1.008097` | `1.017391` |
| median-ratio | `1.011735` | `0.922988` | `0.923004` | `1.008097` | `1.017391` |

Codegen evidence：

| condition | sites applied | native prefetch count | native instruction count | native bytes | BPF bytes |
|---|---:|---:|---:|---:|---:|
| control | 0 | 0 | 133 | 494 | 920 |
| treatment | 1 | 1 | 134 | 498 | 936 |

因此：

- treatment 确实改变了 BPF bytecode，并生成了 native `prefetcht0`。
- 该 prefetch 不是 native instruction count reduction；它是额外 hint。
- 对这个 case，wall/cycles 指标倾向正向，但 `exec_ns` 不支持稳定收益。

## AWS 费用

价格假设：

- `t3.small` Linux on-demand：`$0.0208/hour`
- gp3 EBS：`$0.08/GB-month`
- root volume：32 GiB
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

本实验共 6 台 `t3.small` instance，合计 AWS wall time 2129 秒。

| cost item | estimated USD |
|---|---:|
| compute | `0.0123008889` |
| EBS root volume | `0.0020739117` |
| total | `0.0143748006` |

所有 instance 均已进入 `terminated`，`data/aws-active-after.json` 为空数组。

## 问题和处理

- AWS tag `Name` 带 run token，例如 `bpf-benchmark-x86-y5`，所以 exact-name filter
  `Name=bpf-benchmark-x86` 查不到运行中 instance。本实验改用 `Project=bpf-benchmark`
  过滤并记录 instance id。
- 某些 instance 在 run-state 里短时间没有 public IP，但 AWS describe-instances 已显示 IP。
  这是启动等待阶段，不是实验失败；runner 随后正常 SSH 并完成。
- 第 3 轮 treatment instance status 一度显示 `initializing`，等待后正常进入 setup、run、sync。

## 后续

当前不应默认启用 prefetch。

下一步建议：

1. 把 `prefetch_map_page_stride` 继续标记为 x86 weak candidate，但不要作为 default gate。
2. 对比 ARM64 同名 map-backed case：ARM64 `exec_ns` 只有约 0.30% faster，且 map-backed geomean
   为负；x86 本轮 timing source 又不一致，因此不能说该策略是跨架构收益。
3. selector v2 应继续优先做 skip reason、site budget、cacheline dedup 和 profile/PMU gate，
   而不是扩大 coverage。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`

发现和处理：

- 上一轮 x86 paired attribution 只说明 `prefetch_map_page_stride` 有一轮 weak positive signal。
  本轮已补 3 轮 independent pair，并把结论更新为：codegen 正确，但 timing source 不一致，不支持
  default enable。
- 没有修改代码，因此不需要额外 rerun。
- 本实验已经覆盖当前问题：x86 map-page-stride weak signal 是否稳定。

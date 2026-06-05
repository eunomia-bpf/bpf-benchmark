# 2026-06-05 prefetch-reworked-performance-cases

## 结论

本轮补了两个此前缺口：

1. `future-first-dereference-window`：case 能命中 profile-fed prefetch，runtime correctness 通过，
   但 PMU 结果显示 cache miss 没有下降。因此它不是 cache-miss positive evidence。
2. `stream-of-strides degree=1`：用已有有效 high-miss stream case 只打开一个 prefetch site。
   PMU 结果显示 treatment 更快，并且 cache miss / cycles 同时下降。这是当前
   `stream-of-strides` 方向的有效正向版本。

关键结果：

| policy / case | sites applied | T/C exec | cycles T/C | instructions T/C | miss count ratio | miss rate delta | 结论 |
|---|---:|---:|---:|---:|---:|---:|---|
| future-first-deref-window | 1 | 0.997711 | 0.994716 | 0.999671 | 1.003498 | 0.000031 | 有轻微 timing signal，但 cache miss 未降；不能算 miss-pressure 正向例。 |
| stream-of-strides degree1 | 1 | 0.990870 | 0.981531 | 0.993567 | 0.882631 | -0.004916 | 有效正向例；degree=1 比之前 degree=2 placement 更合理。 |

另外，新增的 `prefetch_stream_of_strides_degree1_high_miss` smoke correctness 通过，
但 candidate diagnostics 为 0，说明它没有触发当前 scanner；本轮不把它作为 performance case。
后续如果继续研究新的 stream layout，需要先重构 case 或 selector。

## 实验问题

本轮要回答：

1. 对每个仍待补的 prefetch policy，是否有能被当前 scanner/profile 触发的有效 performance case？
2. 有效 case 的 control 是否有足够 cache miss pressure？
3. treatment 是否实际插入 prefetch，并且是否降低 cache miss / cycles / exec time？
4. 如果没有收益，原因是 case 无效、placement 太晚、miss pressure 不够，还是 prefetch overhead 抵消收益？

## 命令

所有命令从 `/home/ruoji/github/bpf-opt` 执行，均通过 AWS wrapper / Makefile 入口。

Smoke：确认新增 / 重构 case correctness。

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-newcase-future-first-smoke \
  BENCH=prefetch_future_first_deref_window \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1

./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-newcase-stream-degree1-smoke \
  BENCH=prefetch_stream_of_strides_degree1_high_miss \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1
```

Candidate diagnostics：

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-newcase-candidate-diagnostics \
  BENCH='prefetch_future_first_deref_window prefetch_stream_of_strides_degree1_high_miss' \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--emit-candidates'
```

Profile-fed smoke：

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-future-first-window-profile-smoke \
  BENCH=prefetch_future_first_deref_window \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile micro/config/prefetch-future-first-deref-window-profile-pc62-r8.json --max-sites=1 --emit-candidates'

./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-stream-high-degree1-profile-smoke \
  BENCH=prefetch_stream_of_strides_high_miss \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile micro/config/prefetch-stream-of-strides-high-miss-degree1-profile-pc24-r9.json --max-sites=1 --emit-candidates'
```

PMU paired attribution：

```bash
./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.medium \
  RUN_TOKEN=prefetch-reworked-control-pmu \
  BENCH='prefetch_future_first_deref_window prefetch_stream_of_strides_high_miss' \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0

./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.medium \
  RUN_TOKEN=prefetch-future-first-window-profile-pmu \
  BENCH=prefetch_future_first_deref_window \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile micro/config/prefetch-future-first-deref-window-profile-pc62-r8.json --max-sites=1'

./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.medium \
  RUN_TOKEN=prefetch-stream-high-degree1-profile-pmu \
  BENCH=prefetch_stream_of_strides_high_miss \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile micro/config/prefetch-stream-of-strides-high-miss-degree1-profile-pc24-r9.json --max-sites=1'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64 kernel micro
- region：`us-east-1`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- smoke instance type：`t4g.small`
- PMU attribution instance type：`c7g.medium`
- PMU counters：`cycles`、`instructions`、`cache_references`、`cache_misses`
- perf scope：`full_repeat_raw`

`c7g.medium` 用于 PMU attribution，因为默认 `t4g.small` 不暴露本实验需要的 generic
`cache_misses` / `cache_references` counters。

AWS instances：

| run token | instance id | type | launch time | final state |
|---|---|---|---|---|
| `prefetch-newcase-future-first-smoke` | `i-0e849808905d2a596` | `t4g.small` | 2026-06-05T11:46:51Z | terminated |
| `prefetch-newcase-stream-degree1-smoke` | `i-0a85dac26316e8b09` | `t4g.small` | 2026-06-05T11:54:02Z | terminated |
| `prefetch-newcase-candidate-diagnostics` | `i-0913fa5996226669d` | `t4g.small` | 2026-06-05T12:01:30Z | terminated |
| `prefetch-future-first-window-profile-smoke` | `i-00bbf41a78889e256` | `t4g.small` | 2026-06-05T12:09:23Z | terminated |
| `prefetch-stream-high-degree1-profile-smoke` | `i-0a9470708b6d08db8` | `t4g.small` | 2026-06-05T12:17:46Z | terminated |
| `prefetch-reworked-control-pmu` | `i-0143aa5aa9003608e` | `c7g.medium` | 2026-06-05T12:24:59Z | terminated |
| `prefetch-future-first-window-profile-pmu` | `i-0346a4f699d3a1ff6` | `c7g.medium` | 2026-06-05T12:32:23Z | terminated |
| `prefetch-stream-high-degree1-profile-pmu` | `i-06934db7c38c1f6a7` | `c7g.medium` | 2026-06-05T12:39:28Z | terminated |

费用估算：

- 价格来源：沿用本项目 2026-06-02 通过 AWS Pricing API 查询的 `us-east-1` Linux On-Demand
  和 gp3 storage 价格口径。
- `t4g.small`：`$0.0168/hour`。
- `c7g.medium`：按 `c7g.large $0.068/hour` 的一半估算为 `$0.034/hour`。
- gp3 root volume：`$0.08/GB-month`，root volume 32 GiB。
- 费用不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

本轮以 8 个短生命周期 instance 运行，计算费用量级低于 `$0.05`。

## 文件改动

代码 / config：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-future-first-deref-window-profile-pc62-r8.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-high-miss-degree1-profile-pc24-r9.json`

实验记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases/analysis/pmu-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-05-prefetch-reworked-performance-cases/analysis/site-summary.tsv`

同步更新文档：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-inventory.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/completion-audit.md`

## 数据文件

Raw result copies：

- `data/results/aws_arm64_micro_20260605_115215_581483/`
- `data/results/aws_arm64_micro_20260605_115931_763257/`
- `data/results/aws_arm64_micro_20260605_120612_158694/`
- `data/results/aws_arm64_micro_20260605_121517_855247/`
- `data/results/aws_arm64_micro_20260605_122312_451789/`
- `data/results/aws_arm64_micro_20260605_123027_377505/`
- `data/results/aws_arm64_micro_20260605_123752_878251/`
- `data/results/aws_arm64_micro_20260605_124343_337473/`

Analysis：

- `analysis/pmu-summary.tsv`
- `analysis/site-summary.tsv`

## 问题和处理

### `prefetch_stream_of_strides_degree1_high_miss` 无效

该新 case smoke correctness 通过，但 candidate diagnostics 显示：

```text
sites_matched = 0
sites_applied = 0
```

这说明当前 scanner 没有在该 layout 里识别出 prefetch candidate。因此它不是有效 performance case。
本轮没有继续用它跑 PMU。

处理：用已有已验证 high-miss stream case `prefetch_stream_of_strides_high_miss`，
新增单站点 profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-high-miss-degree1-profile-pc24-r9.json
```

这样能在同一个有效 high-miss stream workload 上比较 degree=1 placement。

### `future-first-deref-window` 不是 miss-pressure 正向例

Profile smoke 显示它能插入 1 个 prefetch，且 result 正确。但 PMU 显示：

```text
miss_count_ratio = 1.003498
miss_rate_delta  = 0.000031
```

因此它的轻微 timing signal 不能解释为 cache miss 降低。它只能作为 placement / profile
diagnostic，不能作为 prefetch policy 正向证据。

## 结果

Profile smoke：

| case | sites matched | sites applied | sites skipped | insn before | insn after | insn delta |
|---|---:|---:|---:|---:|---:|---:|
| future candidate diagnostics | 8 | 0 | 8 | 447 | 447 | 0 |
| stream degree1 invalid diagnostics | 0 | 0 | 0 | 348 | 348 | 0 |
| future profile smoke | 9 | 1 | 8 | 447 | 449 | 2 |
| stream degree1 profile smoke | 17 | 1 | 16 | 358 | 360 | 2 |

PMU paired attribution：

| bench | control dir | treatment dir | ctrl exec ns | trt exec ns | T/C exec | cycles T/C | instructions T/C | ctrl misses | trt misses | miss ratio | ctrl miss rate | trt miss rate | miss rate delta |
|---|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| `prefetch_future_first_deref_window` | `aws_arm64_micro_20260605_123027_377505` | `aws_arm64_micro_20260605_123752_878251` | 23498.8 | 23445.0 | 0.997711 | 0.994716 | 0.999671 | 1688497.6 | 1694404.6 | 1.003498 | 0.018965 | 0.018996 | 0.000031 |
| `prefetch_stream_of_strides_high_miss` degree1 | `aws_arm64_micro_20260605_123027_377505` | `aws_arm64_micro_20260605_124343_337473` | 17041.8 | 16886.2 | 0.990870 | 0.981531 | 0.993567 | 3210484.2 | 2833672.4 | 0.882631 | 0.039478 | 0.034562 | -0.004916 |

## 后续

1. 将 `stream-of-strides` 的结论改成：degree=2 current placement reject；degree=1 在 high-miss
   case 上有正向 PMU evidence。
2. 将 `future-first-deref-window` 标为有效诊断 / weak timing，不作为 cache-miss positive policy。
3. 后续如果继续 stream direction，应围绕 degree=1 / scheduling / placement 继续，而不是复用
   degree=2 placement。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-missing-performance-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-schema-and-pmu-evidence/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`

发现和处理：

- 旧文档把 `stream-of-strides` 整体写成 reject。新 PMU 结果说明 degree=1 版本有正向证据；
  已更新为 “degree=2 reject，degree=1 positive”。
- `prefetch_stream_of_strides_degree1_high_miss` 虽然 correctness 通过，但 scanner 不命中；
  已明确为无效 performance case，不再作为结果表中的正向用例。
- `future-first-deref-window` 可以插入 prefetch，但 cache miss 未下降；已避免把它写成正向 miss-pressure evidence。

是否重跑：

- 已重跑 AWS smoke、candidate diagnostics、profile smoke、PMU control/treatment。
- 本轮只修改文档和新增 profile config，不再需要额外 correctness run。

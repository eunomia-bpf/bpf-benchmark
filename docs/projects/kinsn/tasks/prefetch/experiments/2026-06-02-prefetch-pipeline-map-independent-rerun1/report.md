# 2026-06-02 prefetch-pipeline-map-independent-rerun1

## 结论

本次完成了 `prefetch_pipeline_page_stride` 的 independent AWS rerun。

结论：

- ARM64 treatment 仍然比 control 快，但没有复现上一轮约 `14.12%` 的幅度。
- 本轮 ARM64 paired geomean treatment/control 是 `0.962181`，约 `3.78%` nominal speedup。
- x86 treatment 也 applied 1 个 site，并生成 `prefetcht0 BYTE PTR [rdi]`；但 x86 control
  `exec_ns` 样本波动异常，本轮 x86 ratio 不能作为性能结论。
- ARM64 native code 继续出现 `prfm pldl1keep, [x0]`。
- 两个架构 treatment 的 `bpfopt` report 都是 `sites_applied=1`、`sites_matched=1`、
  `sites_skipped=0`、`insn_delta=2`。

本轮状态是 `completed_with_unstable_effect_size`。它支持 “next-iteration prefetch placement
比 same-iteration placement 更有希望”，但也说明上一轮 `14%` 不是稳定效应幅度。

## 实验问题

上一轮实验：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/report.md
```

显示 ARM64 paired geomean treatment/control 为 `0.858777`，约 `14.12%` nominal speedup。
本实验要回答：同一代码、同一 profile、同一 benchmark、同一 AWS instance type 下，独立 rerun
是否复现该 positive signal。

## 命令

AWS check：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/check.sh x86
/home/ruoji/github/bpf-opt/aws-config/check.sh arm64
```

ARM64 control：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-control-stability-rerun2 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000
```

ARM64 treatment：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-treatment-stability-rerun2 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'
```

x86 control：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-control-stability-rerun2 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000
```

x86 treatment：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-treatment-stability-rerun2 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- benchmark：`prefetch_pipeline_page_stride`
- runtime：`kernel`
- ARM64 instance type：`t4g.small`
- x86 instance type：`t3.small`
- AWS region：`us-east-1`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- ARM64 runtime image：`bpf-benchmark/runner-runtime:arm64`
- x86 runtime image：`bpf-benchmark/runner-runtime:x86_64`

AWS instances：

| arch | role | run token | instance id | state |
|---|---|---|---|---|
| ARM64 | control | `pipeline-arm64-control-stability-rerun2` | `i-0289f86439cf02668` | terminated |
| ARM64 | treatment | `pipeline-arm64-treatment-stability-rerun2` | `i-066f0c02292c250ac` | terminated |
| x86 | control | `pipeline-x86-control-stability-rerun2` | `i-006a3d03d671be584` | terminated |
| x86 | treatment | `pipeline-x86-treatment-stability-rerun2` | `i-027643778de562722` | terminated |

费用估算：

- 价格来源：2026-06-02 使用 AWS Pricing API 查询 `us-east-1` Linux On-Demand 和 gp3 storage。
- `t3.small`：`$0.0208/hour`。
- `t4g.small`：`$0.0168/hour`。
- gp3 storage：`$0.08/GB-month`。
- root volume：`32 GiB` gp3。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| arch | total wall seconds | compute USD | EBS USD | total USD |
|---|---:|---:|---:|---:|
| ARM64 | 646 | 0.003014 | 0.000638 | 0.003652 |
| x86 | 715 | 0.004132 | 0.000707 | 0.004839 |
| total | 1361 | 0.007146 | 0.001345 | 0.008491 |

逐 instance wall time 和费用见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/analysis/aws-instance-summary.tsv
```

## 文件改动

本实验没有修改代码行为。新增 / 更新实验记录和 prefetch task 文档：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/analysis/stability-samples.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/analysis/stability-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/analysis/aws-instance-summary.tsv`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

## 数据文件

- `data/run-contract.json`
- `data/aws-check-x86.log`
- `data/aws-check-x86.stderr.log`
- `data/aws-check-arm64.log`
- `data/aws-check-arm64.stderr.log`
- `data/aws-arm64-control-stability-rerun2.log`
- `data/aws-arm64-control-stability-rerun2.stderr.log`
- `data/aws-arm64-treatment-stability-rerun2.log`
- `data/aws-arm64-treatment-stability-rerun2.stderr.log`
- `data/aws-x86-control-stability-rerun2.log`
- `data/aws-x86-control-stability-rerun2.stderr.log`
- `data/aws-x86-treatment-stability-rerun2.log`
- `data/aws-x86-treatment-stability-rerun2.stderr.log`
- `data/aws-instance-describe.json`
- `data/arm64-control-stability-rerun2-result/`
- `data/arm64-treatment-stability-rerun2-result/`
- `data/x86-control-stability-rerun2-result/`
- `data/x86-treatment-stability-rerun2-result/`
- `analysis/stability-samples.tsv`
- `analysis/stability-summary.tsv`
- `analysis/aws-instance-summary.tsv`

## 问题和处理

- 本轮所有 AWS runs 都完成并进入 terminated 状态。
- x86 control `exec_ns` 波动异常：5 个样本是 `14809, 27884, 26063, 37372, 16064`。
  因此 x86 paired ratio `0.401950` 不是可信 speedup 结论，而是 timing instability signal。
- ARM64 没有 `wall_exec_ns` / `exec_cycles`，只能使用 `exec_ns`。

## 结果

Treatment codegen / pass report：

| arch | sites applied | native hint |
|---|---:|---|
| x86 | 1 | `prefetcht0 BYTE PTR [rdi]` |
| ARM64 | 1 | `prfm pldl1keep, [x0]` |

Stability raw sample summary：

| arch | role | n | mean exec ns | min exec ns | max exec ns |
|---|---|---:|---:|---:|---:|
| x86 | control | 5 | 24438.400 | 14809 | 37372 |
| x86 | treatment | 5 | 9252.000 | 9213 | 9287 |
| ARM64 | control | 5 | 17248.200 | 17024 | 17564 |
| ARM64 | treatment | 5 | 16602.000 | 16184 | 17523 |

Paired ratio：

| arch | paired n | paired geomean T/C | paired mean T/C | interpretation |
|---|---:|---:|---:|---|
| x86 | 5 | 0.401950 | 0.426756 | invalid as performance conclusion; control timing is unstable. |
| ARM64 | 5 | 0.962181 | 0.962448 | positive signal, about 3.78% nominal speedup. |

对上一轮的复核：

| arch | previous paired geomean T/C | independent rerun paired geomean T/C | conclusion |
|---|---:|---:|---|
| ARM64 | 0.858777 | 0.962181 | positive direction reproduced, magnitude did not reproduce. |
| x86 | 0.985484 | 0.401950 | x86 timing instability; do not interpret as speedup. |

## 后续

下一步不应直接 default-enable P19。需要：

1. 先把 ARM64 result 结论降级为 “positive but unstable effect size”。
2. 继续做至少一轮 ARM64-only rerun，或者改用更长 `INNER_REPEAT` / 更稳定 timing setting。
3. 如果要证明机制原因，仍需要 PMU-capable 环境；当前默认 AWS ARM64 micro 没有 wall/cycle/PMU 证据。
4. 只有稳定复现后，才值得设计自动 selector 来发现 next pointer / insertion point。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-upper-bound-map-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

发现和处理：

- 上一轮 report 写 ARM64 约 14% positive signal，并已明确需要 independent rerun。本轮完成该 rerun，
  发现 positive direction 复现，但 effect size 不稳定。
- 需要同步更新 prefetch plan / policy matrix，把 P19 状态从 “当前最强 positive signal” 调整为
  “positive direction reproduced, magnitude unstable”。
- 没有发现需要删除的临时代码或 workaround。

是否重跑：

- 本轮已经完成 x86 / ARM64 control + treatment AWS rerun。
- 后续只会更新文档，不修改代码行为，因此不需要额外重跑。

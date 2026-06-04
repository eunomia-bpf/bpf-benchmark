# 2026-06-02 prefetch-profile-fed-map-value-pmu-attribution

## 结论

本轮只完成 PMU capability smoke，没有继续扩大到 paired PMU attribution。

原因：默认 AWS instance 和当前 custom kernel/runtime 路径不能提供本实验最需要的硬件 PMU
counters：

- x86 `t3.small`：`cycles`、`instructions`、`cache_references`、`cache_misses` 等硬件 counters
  全部 `perf_event_open(...): No such file or directory`。
- ARM64 `t4g.small`：只采到 `cycles`；`instructions`、`cache_references`、`cache_misses` 等不可用。

因此，继续跑 5-sample paired PMU 不会回答“profile-fed map-value prefetch 是否降低 cache miss”。
本轮结论是：PMU-enabled cache attribution 在当前默认 AWS micro 环境下不可用；下一步应改用
非 PMU 的 repeated same-LLC rerun / codegen evidence，或者单独设计能获得 cache counters 的环境。

两次 smoke 中 prefetch pass 本身都生效：

| arch | sites matched | sites applied | insn delta | PMU 状态 |
|---|---:|---:|---:|---|
| x86 | 1 | 1 | 2 | 只有 software counters；硬件 counters 不可用 |
| ARM64 | 1 | 1 | 2 | 有 `cycles`；cache/instruction counters 不可用 |

## 实验问题

2026-06-02 profile-fed map-value attribution 显示 admission 机制可用，但缺少 PMU 归因。
本实验要回答：

1. AWS micro kernel runtime 能否采到 `cache_misses` / `cache_references` / `instructions` 等 PMU counters？
2. 如果 PMU 可用，是否可以扩大到 x86 / ARM64 paired treatment-control attribution？
3. 如果 PMU 不可用，应该停止还是继续做 wall-time-only 重复实验？

## 命令

所有命令从 `/home/ruoji/github/bpf-opt` 执行，均通过 AWS wrapper / Makefile 入口。

x86 PMU smoke：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pmu-x86-smoke \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json'
```

ARM64 PMU smoke：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pmu-arm64-smoke \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- AWS region：`us-east-1`
- x86 instance：`t3.small`
- ARM64 instance：`t4g.small`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：
  - x86：`bpf-benchmark/runner-runtime:x86_64`
  - ARM64：`bpf-benchmark/runner-runtime:arm64`
- benchmark：`prefetch_map_page_stride`
- runtime：`kernel`
- samples：1
- warmups：0
- inner repeat：10000
- perf scope：`full_repeat_raw`
- profile：`/home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json`

Remote metadata:

| arch | kernel | perf_event_paranoid | CPU model |
|---|---|---:|---|
| x86 | `7.0.0-rc2+` | 2 | Intel Xeon Platinum 8259CL |
| ARM64 | `7.0.0-rc2+` | 2 | `aarch64` |

Kernel config check:

```text
x86:   CONFIG_HAVE_PERF_EVENTS=y, CONFIG_PERF_EVENTS=y
ARM64: CONFIG_HAVE_PERF_EVENTS=y, CONFIG_PERF_EVENTS=y, CONFIG_HW_PERF_EVENTS=y
```

这说明 runner 代码确实请求了 perf events，kernel 也启用了 perf framework；不可用的是当前
instance / kernel / virtualized PMU 暴露出来的具体硬件 events。

## 文件改动

本实验没有改代码。新增实验记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/analysis/pmu-smoke.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/analysis/aws-instances.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/analysis/bpfopt-sites.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/attempts/run-token-empty-local-fail/report.md`

同步更新文档：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

## 数据文件

Raw results copied from `/home/ruoji/github/bpf-opt/code/micro/results`:

- `data/aws_x86_micro_20260602_064029_890900/`
- `data/aws_arm64_micro_20260602_064813_166189/`

Remote logs:

- `data/micro_pmu-x86-smoke_20260602_064028.remote.log`
- `data/micro_pmu-arm64-smoke_20260602_064811.remote.log`

Analysis:

- `analysis/pmu-smoke.tsv`
- `analysis/aws-instances.tsv`
- `analysis/bpfopt-sites.tsv`

## 问题和处理

### 本地 RUN_TOKEN preflight

第一次 PMU smoke 未显式传入 `RUN_TOKEN`，本地 run-contract preflight 失败，没有启动 AWS。
记录见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/attempts/run-token-empty-local-fail/report.md
```

后续正式 smoke 都显式传入 `RUN_TOKEN`。

### PMU counters 不完整

x86 sample:

```text
perf_event_open(cycles): No such file or directory
perf_event_open(instructions): No such file or directory
perf_event_open(cache_references): No such file or directory
perf_event_open(cache_misses): No such file or directory
```

ARM64 sample:

```text
cycles: collected
perf_event_open(instructions): No such file or directory
perf_event_open(cache_references): No such file or directory
perf_event_open(cache_misses): No such file or directory
```

处理：不扩大到 paired PMU run。只保存 smoke 结果，并把 PMU attribution 标记为 blocked by
environment capability。

## 结果

| arch | exec ns | wall exec ns | cycles | task clock ns | perf error |
|---|---:|---:|---:|---:|---|
| x86 | 8116 | 12910 | N/A | 75050108 | hardware counters unavailable |
| ARM64 | 14501 | N/A | 351612550 | 145164801 | cache/instruction counters unavailable |

Profile-fed admission 生效：

| arch | sites matched | sites applied | insn delta |
|---|---:|---:|---:|
| x86 | 1 | 1 | 2 |
| ARM64 | 1 | 1 | 2 |

本轮没有产生 treatment/control performance conclusion。它只回答 PMU capability：

```text
当前默认 AWS micro 环境不能支持 cache-miss PMU attribution。
```

## AWS 时间和费用

价格来源：AWS Pricing API，`AmazonEC2`，location `US East (N. Virginia)`。

使用价格：

- `t3.small` Linux on-demand：`$0.0208/hour`
- `t4g.small` Linux on-demand：`$0.0168/hour`
- EBS root volume：按 General Purpose SSD gp2 `32 GiB * $0.10/GB-month` 保守估算。

| arch | instance | type | launch | terminate | wall seconds | compute USD | EBS USD |
|---|---|---|---|---|---:|---:|---:|
| x86 | `i-08184e086166517da` | `t3.small` | 2026-06-02T06:34:59Z | 2026-06-02 06:40:35 GMT | 336 | 0.001941 | 0.000415 |
| ARM64 | `i-0891ad85a1f8315dd` | `t4g.small` | 2026-06-02T06:42:25Z | 2026-06-02 06:48:18 GMT | 353 | 0.001647 | 0.000436 |

估算合计：`$0.004439`。

费用不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。
两个 instance 均已 terminated。

## 后续

1. 不继续在默认 AWS micro instance 上做 cache-miss PMU attribution。
2. 对 profile-fed map-value policy 做 independent rerun / stability check，仍使用 same-LLC wall/ktime
   和 codegen evidence。
3. 如果必须证明 cache miss reduction，需要单独设计 PMU-capable 环境，或切换到工具链/实例组合能暴露
   `cache_misses` / `cache_references` 的平台。

## 收尾一致性复查

已回看：

- 本实验的本地 preflight failure attempt。
- 2026-06-02 profile-fed map-value attribution report。
- prefetch task plan 和 policy matrix。

发现和处理：

- profile-fed map-value report 曾把 PMU 作为下一步，本实验确认当前默认 AWS 环境无法做 cache-miss
  PMU attribution。已在 task 文档中更新为 blocked。
- 本实验没有改 benchmark framework code，因此不需要重跑 correctness 或 paired attribution。
- 未发现残留 AWS instance；两个 smoke instance 都已 terminated。

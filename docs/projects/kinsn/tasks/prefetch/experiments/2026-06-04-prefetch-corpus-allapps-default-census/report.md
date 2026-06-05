# 2026-06-04 prefetch-corpus-allapps-default-census

## 结论

本实验未产生 corpus raw result，状态是 `interrupted_no_result_sync`。

目标是对 ARM64 corpus 中更多真实 app 做 default structural prefetch census。实际运行先在
`otelcol-ebpf-profiler/profiling` 上等待 200 秒后失败，原因是 native app 没有加载
shim-tracked BPF program；随后进入 `cilium/agent`，该 runner 的 load timeout 是 1200 秒。为避免
把一个运行条件问题变成长时间空转，本次 run 被中止，并清理 AWS instance。

这不是 prefetch pass failure，也不是性能实验。

## 实验问题

真实 corpus app 是否能直接用 default structural prefetch pass 跑完整 census。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-allapps-default-census \
  BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling,cilium/agent,tetragon/observer,katran,katran/wrk,tracee/monitor,bpftrace/set \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

中止后清理：

```bash
./aws-config/run.sh arm64 terminate
```

## 环境

| item | value |
|---|---|
| platform | AWS |
| arch | arm64 |
| instance type | `t4g.small` |
| region | `us-east-1` |
| remote user | `ec2-user` |
| kernel | `7.0.0-rc2+` |
| instance id | `i-0bfb72f8e65c186e4` |
| public IP | `3.234.254.180` |
| launch time | `2026-06-04T15:29:35Z` |
| terminate time | `2026-06-04T15:47:59Z` |
| final state | `terminated` |

## 文件改动

本实验未修改代码。

## 数据文件

| file | 内容 |
|---|---|
| `data/run-contract.json` | 运行契约。 |
| `data/run-state-instance.json` | wrapper 本地 run-state。 |
| `data/aws-instance-describe.json` | AWS EC2 instance describe 原始输出。 |
| `analysis/aws-price-source.tsv` | AWS 费用估算价格来源。 |
| `analysis/aws-cost-summary.tsv` | AWS 费用估算。 |

本次没有 raw corpus result directory，因为 run 被手动中止且未同步 result。

## 问题和处理

- `otelcol-ebpf-profiler/profiling`：native app 没有在 200 秒内加载 shim-tracked BPF program。
- `cilium/agent`：runner 默认 `load_timeout_s=1200`，继续等待会消耗较长 AWS 时间。
- 处理：中止本次 all-app run，改跑 selected-app census，排除 `otelcol` 和 `cilium`。

## 结果

本实验只证明 all-app corpus census 当前不能直接作为 prefetch task 的批量入口。需要先按 app
逐个处理运行条件问题。

AWS 费用估算：

```text
instance_id            aws_wall_seconds  total_usd_estimate
i-0bfb72f8e65c186e4    1104              0.006242
```

估算使用 `t4g.small` us-east-1 Linux On-Demand `0.0168 USD/hour` 和 gp3 root volume
`0.08 USD/GB-month`，root volume `32 GB`。估算不包含 data transfer、税、free tier、credits、
Savings Plans、Reserved Instances 或账户级折扣。

## 后续

改用 selected app set 跑 census：

```text
tetragon/observer,katran,katran/wrk,tracee/monitor,bpftrace/set
```

该 follow-up 记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-selectedapps-default-census
```

## 收尾一致性复查

已回看同日 prefetch corpus 实验：

- `2026-06-04-prefetch-corpus-default-structural-smoke`
- `2026-06-04-prefetch-corpus-profile-fed-smoke`
- `2026-06-04-prefetch-corpus-multisite-profile-fed`
- `2026-06-04-prefetch-corpus-generated-profile-table`

发现：all-app run 是 corpus app runnability 问题，不改变此前 Katran profile-fed corpus 结论。
本实验没有代码改动，因此不需要重跑测试。


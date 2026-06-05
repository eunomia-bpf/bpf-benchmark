# 2026-06-04 prefetch-corpus-selectedapps-default-census

## 结论

本实验完成，状态是 `completed_with_app_errors`。

目的不是测性能，而是扩大真实 corpus 的 default structural prefetch census 覆盖。结果：

- `katran` 完整通过：1 个 program，prefetch pass 匹配 224 个候选，应用 0 个，跳过 224 个。
- `tracee/monitor` baseline 加载 167 个 BPF program，prefetch pass 对 167 个 program 做了 census：
  匹配 15542 个候选，应用 0 个，跳过 15542 个；之后 post-ReJIT 阶段 shim socket reset。
- `tetragon/observer`、`katran/wrk`、`bpftrace/set` 失败原因分别是 artifact 缺失、workload 连接
  timeout、`libclang-17.so.17` 缺失。这些不是 prefetch pass failure。

关键结论：真实 corpus 中 structural candidates 很多，但 default selector 仍然按 evidence gate 保守
跳过，不会在没有 profile / PMU evidence 时插入 prefetch。Tracee 暴露出 pass 在大型 corpus 上的
compile-time/scalability 风险：167 个 program 总 `bpfopt_ms=308187`，单 program 最大
`26817 ms`。

## 实验问题

1. 除 Katran 外，更多真实 app 是否能跑 prefetch default structural census。
2. default selector 在真实 app 上是否仍然只做 census / evidence-gated skip。
3. 是否出现新的 pass scalability 或 app runnability 问题。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-selectedapps-default-census \
  BPFREJIT_CORPUS_APPS=tetragon/observer,katran,katran/wrk,tracee/monitor,bpftrace/set \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

实验结束后额外确认清理：

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
| runtime container | `bpf-benchmark/runner-runtime:arm64` |
| instance id | `i-084e90e974c13b896` |
| public IP | `44.212.17.7` |
| launch time | `2026-06-04T15:49:38Z` |
| terminate time | `2026-06-04T16:06:01Z` |
| final state | `terminated` |
| synced result | `/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_155504_082524` |

## 文件改动

本实验未修改代码。实验记录新增：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-selectedapps-default-census
```

## 数据文件

| file | 内容 |
|---|---|
| `data/run-contract.json` | 运行契约。 |
| `data/aws-instance-describe.json` | AWS EC2 instance describe 原始输出。 |
| `data/raw-result/` | 同步回来的完整 corpus raw result 副本。 |
| `analysis/app-status.tsv` | 每个 app 的状态和错误摘要。 |
| `analysis/prefetch-pass-summary.tsv` | 每个 app 的 prefetch pass aggregate。 |
| `analysis/prefetch-program-summary.tsv` | 每个 program 的 prefetch pass stats。 |
| `analysis/skip-reason-summary.tsv` | 归一化 skip reason。 |
| `analysis/tracee-slowest-prefetch-programs.tsv` | Tracee 中 bpfopt 耗时最高的 program。 |
| `analysis/aws-price-source.tsv` | AWS 费用估算价格来源。 |
| `analysis/aws-cost-summary.tsv` | AWS 费用估算。 |

## 问题和处理

| app | status | 问题 |
|---|---|---|
| `tetragon/observer` | error | `bpf_alignchecker.o` 不存在，Tetragon 在 BPF tracking 前退出。 |
| `katran` | ok | 完整通过。 |
| `katran/wrk` | error | workload 无法连接 `10.100.1.1:8080`。 |
| `tracee/monitor` | error | baseline 成功加载 167 个 BPF program；ReJIT census 完成后 shim socket reset，post-ReJIT measurement 没有完成。 |
| `bpftrace/set` | error | `/usr/local/bin/bpftrace` 缺 `libclang-17.so.17`。 |

## 结果

App summary：

```text
app                 status  baseline_programs  post_rejit_programs
bpftrace/set        error   0                  0
katran              ok      1                  1
katran/wrk          error   0                  0
tetragon/observer   error   0                  0
tracee/monitor      error   167                0
```

Prefetch pass summary：

```text
app              program_passes  sites_matched  sites_applied  sites_skipped  total_bpfopt_ms  max_bpfopt_ms
katran           1               224            0              224            11322            11322
tracee/monitor   167             15542          0              15542          308187           26817
```

Skip reason summary：

```text
reason                                                     count
map value prefetch requires profile or PMU evidence        15665
packet prefetch requires a data-dependent dereference      101
```

Tracee 中最慢的 prefetch pass program：

```text
program_id  prog_name          bpfopt_ms  sites_matched
135         lkm_seeker_kset    26817      259
131         lkm_seeker_modt    25066      290
137         lkm_seeker_proc    24542      271
266         tracepoint__exe    21565      592
150         uprobe_syscall_    20757      153
```

AWS 费用估算：

```text
instance_id            aws_wall_seconds  total_usd_estimate
i-084e90e974c13b896    983               0.005558
```

估算使用 `t4g.small` us-east-1 Linux On-Demand `0.0168 USD/hour` 和 gp3 root volume
`0.08 USD/GB-month`，root volume `32 GB`。估算不包含 data transfer、税、free tier、credits、
Savings Plans、Reserved Instances 或账户级折扣。

## 后续

1. 不把 all-app corpus 直接作为 prefetch gate；需要逐 app 修复 runnability。
2. 对 Tracee 做单 app diagnosis：区分 shim reset 是 app/runtime 断连，还是 prefetch census 编译时间过长触发。
3. 在真实 corpus profile generator 中加入 ranking input，例如 profile count、PMU evidence 或 workload hit count。
4. 对 Katran profile-fed path 继续做 evidence-ranked profile，而不是 PC-order top-N。

## 收尾一致性复查

已回看同日 prefetch corpus 实验：

- `2026-06-04-prefetch-corpus-default-structural-smoke`
- `2026-06-04-prefetch-corpus-profile-fed-smoke`
- `2026-06-04-prefetch-corpus-multisite-profile-fed`
- `2026-06-04-prefetch-corpus-generated-profile-table`
- `2026-06-04-prefetch-corpus-allapps-default-census`

发现和处理：

- 本实验没有推翻此前结论：default selector 仍然是 census / evidence-gated skip，不会无证据插入。
- 新增发现是 Tracee 的大型 corpus census 有 compile-time/scalability 风险，需要单独 diagnosis。
- 本实验没有代码改动，因此不需要重跑测试。


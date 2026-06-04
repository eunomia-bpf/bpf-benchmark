# 2026-06-03 prefetch-c7g-pmu-policy-diagnosis

## 结论

本实验完成，状态是 `completed`。

实验目的：在 AWS ARM64 `c7g.large` 上，用可采集 `cycles`、`instructions`、
`cache_references`、`cache_misses` 的 PMU 环境，对当前 Kinsn prefetch task 里已经实现且有
profile 的 policy/case 做 treatment/control 归因。

主要结论：

- 真正有稳定 PMU 证据的 candidate 是 profile-fed future-address 类 policy：
  pipeline horizon、spatial-within-page、MLOP/index-field、normalized degree。
- 这些 positive case 的共同特征是：treatment 显著降低 `cache_misses`，并且 `exec_ns` 有
  `2.60%` 到 `5.47%` 的改善。
- 普通 fixed stride、same-iteration map/upper-bound、default structural policy 基本不是好
  candidate。它们要么 baseline cache miss 很低，要么 cache miss 没有明显下降，要么只有
  noise-level timing change。
- `struct-field` 和 `mixed-policy-table` 没有作为 treatment 跑：前者缺 stable future-pointer
  profile point，后者需要 per-PC policy table/profile schema。它们仍是 pending policy，不是
  已测 policy。

## 实验问题

本实验回答四个问题：

1. 当前已实现的 prefetch policy 在对应 micro case 上是否能加速。
2. 不加速时，PMU 证据是否能说明原因。
3. 哪些 case 是 policy/case mismatch，不能继续作为 positive evidence。
4. AWS 上是否能通过 `c7g.large` 补齐 `t4g.small` 缺失的 cache-miss PMU attribution。

这里的 policy 指“对哪个地址、什么时候、提前多远、一次几个地址、用哪个 hint、哪些 load 不
prefetch”的决策。PMU capability、hint ABI、loader fix、runner path、profile gate 是支持机制，
不是 policy。

## 命令

所有 benchmark 都从顶层 workspace 通过 AWS wrapper 执行：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro ...
```

共同参数：

```text
AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large
RUNTIMES=kernel
SAMPLES=3
WARMUPS=1
INNER_REPEAT=10000
PERF_COUNTERS=1
PERF_SCOPE=full_repeat_raw
CPU=0
```

Control：

```bash
RUN_TOKEN=pmu-policy-control-all \
AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
BENCH=<35-case-list> \
RUNTIMES=kernel SAMPLES=3 WARMUPS=1 INNER_REPEAT=10000 \
PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw CPU=0 \
./aws-config/run.sh arm64 micro
```

Default structural treatment：

```bash
RUN_TOKEN=pmu-policy-default-structural \
BPFREJIT_BENCH_PASSES=prefetch \
BPFREJIT_BENCH_PASS_ARGS='--hint l1keep' \
AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
BENCH=<17-structural-case-list> \
RUNTIMES=kernel SAMPLES=3 WARMUPS=1 INNER_REPEAT=10000 \
PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw CPU=0 \
./aws-config/run.sh arm64 micro
```

Profile-fed treatments 逐个跑，例如：

```bash
RUN_TOKEN=pmu-policy-spatial \
BPFREJIT_BENCH_PASSES=prefetch \
BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-spatial-page-footprint-profile-pc333-r0-r7-r5.json --max-sites 3 --hint l1keep' \
AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
BENCH=prefetch_spatial_page_footprint \
RUNTIMES=kernel SAMPLES=3 WARMUPS=1 INNER_REPEAT=10000 \
PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw CPU=0 \
./aws-config/run.sh arm64 micro
```

完整 run matrix 在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/analysis/planned-policy-runs.tsv
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- region：`us-east-1`
- instance type：`c7g.large`
- kernel：`7.0.0-rc2+`
- runtime：`kernel`
- suite：`micro`
- PMU scope：`full_repeat_raw`
- samples：`3`
- warmups：`1`
- inner repeat：`10000`
- CPU affinity：`0`

`c7g.large` 的使用理由：上一轮 PMU capability matrix 已证明默认 ARM64 micro instance
`t4g.small` 不能采集 `instructions/cache_references/cache_misses`，而 `c7g.large` 能采集本实验
需要的 generic perf counters。本实验使用 `c7g.large` 是 PMU capability requirement，不是为了
variance、并发或方便。

## 文件改动

实验运行前后没有修改 benchmark framework 行为。

本实验新增 / 更新：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/data/results/*`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/data/logs/*`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-03-prefetch-c7g-pmu-policy-diagnosis/analysis/*.tsv`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

## 数据文件

Raw result 副本：

```text
data/results/control-all
data/results/default-structural
data/results/map-page-stride
data/results/upper-page-stride
data/results/pipeline-page-stride
data/results/horizon1
data/results/horizon2
data/results/horizon4
data/results/pipeline-degree
data/results/stride64
data/results/stride256
data/results/stride4096
data/results/variable-stride
data/results/spatial
data/results/mlop
data/results/degree1
data/results/degree2
data/results/degree3
```

AWS remote logs：

```text
data/logs/micro_pmu-policy-*_20260603_*.remote.log
```

Analysis-side tables：

```text
analysis/result-dir-map.tsv
analysis/planned-policy-runs.tsv
analysis/pmu-samples.tsv
analysis/pmu-policy-attribution.tsv
analysis/policy-rollup.tsv
analysis/aws-cost-estimate.tsv
```

`pmu-samples.tsv` 是逐样本 raw table。`pmu-policy-attribution.tsv` 是 treatment/control
对比表，ratio 均在 analysis-side 计算，不写入 benchmark framework。

## 问题和处理

- 初次执行时 AWS session 过期，`aws sts get-caller-identity` 报
  `Your session has expired`。用户重新登录后，本实验在同一目录继续执行。
- 第一次写 TSV loop 时，空字段导致 shell `read` 列错位。该尝试只跑了 `control-all`，没有影响
  control 结果；之后改为显式 per-run 参数调用。
- AWS `describe-instances` 对前半段 terminated instance 已不再返回精确 launch/terminate
  metadata。report 保留已观察到的 instance id，并对这些 instance 用同批次后半段的平均 wall time
  做费用估算；不把估算写成精确账单。

## 结果

### Policy rollup

| run label | rows | time wins | time losses | neutral | cache-miss drop rows | geomean T/C | geomean speedup |
|---|---:|---:|---:|---:|---:|---:|---:|
| `default-structural` | 17 | 3 | 0 | 14 | 0 | `0.988528` | `1.15%` |
| `horizon1` | 1 | 1 | 0 | 0 | 1 | `0.973987` | `2.60%` |
| `horizon2` | 1 | 1 | 0 | 0 | 1 | `0.961195` | `3.88%` |
| `horizon4` | 1 | 1 | 0 | 0 | 1 | `0.972508` | `2.75%` |
| `pipeline-page-stride` | 1 | 1 | 0 | 0 | 1 | `0.968297` | `3.17%` |
| `pipeline-degree` | 1 | 1 | 0 | 0 | 1 | `0.969781` | `3.02%` |
| `spatial` | 1 | 1 | 0 | 0 | 1 | `0.971461` | `2.85%` |
| `mlop` | 1 | 1 | 0 | 0 | 1 | `0.945284` | `5.47%` |
| `degree1` | 1 | 1 | 0 | 0 | 1 | `0.958149` | `4.19%` |
| `degree2` | 1 | 1 | 0 | 0 | 1 | `0.967489` | `3.25%` |
| `degree3` | 1 | 1 | 0 | 0 | 1 | `0.967537` | `3.25%` |
| `map-page-stride` | 1 | 0 | 0 | 1 | 0 | `0.994264` | `0.57%` |
| `upper-page-stride` | 1 | 0 | 0 | 1 | 0 | `0.996947` | `0.31%` |
| `stride64` | 1 | 0 | 0 | 1 | 1 | `0.998684` | `0.13%` |
| `stride256` | 1 | 0 | 0 | 1 | 0 | `0.999031` | `0.10%` |
| `stride4096` | 1 | 0 | 0 | 1 | 0 | `1.000233` | `-0.02%` |
| `variable-stride` | 1 | 0 | 0 | 1 | 1 | `0.991186` | `0.88%` |

### Evidence by policy

| policy / case | treatment/control | cache miss ratio | instruction ratio | conclusion |
|---|---:|---:|---:|---|
| `prefetch_mlop_index_field` | `0.945284` | `0.019193` | `0.957288` | 有效：miss 大幅下降，时间改善最大。 |
| `prefetch_degree123_page_stride` degree1 | `0.958149` | `0.006768` | `0.969921` | 有效：degree1 最好。 |
| `prefetch_pipeline_horizon2_page_stride` | `0.961195` | `0.009627` | `0.970903` | 有效：horizon2 继续是 strong candidate。 |
| `prefetch_pipeline_page_stride` | `0.968297` | `0.006868` | `0.970491` | 有效：next-iteration placement 有 PMU 证据。 |
| `prefetch_pipeline_degree_page_stride` | `0.969781` | `0.010138` | `1.041210` | 有效但有 instruction overhead；degree 不是越大越好。 |
| `prefetch_spatial_page_footprint` | `0.971461` | `0.000460` | `1.037390` | 有效但有 instruction overhead；miss drop 足够大。 |
| `prefetch_stride64_page_stride` | `0.998684` | `0.759427` | `1.002690` | 中性：miss 有小幅下降但时间不动。 |
| `prefetch_stride256_page_stride` | `0.999031` | `0.820329` | `1.002940` | 中性：miss drop 不够。 |
| `prefetch_stride4096_page_stride` | `1.000233` | `0.984768` | `1.004340` | 中性：几乎没有 miss 改善。 |
| `prefetch_map_page_stride` | `0.994264` | `0.964509` | `1.008210` | 中性：map same-iteration placement 不够。 |
| `prefetch_upper_page_stride` | `0.996947` | `0.994163` | `1.000640` | 中性：upper-bound same-iteration 仍不支持。 |
| `prefetch_variable_stride_page_stride` | `0.991186` | `0.024155` | `0.996811` | miss 下降但时间只有弱信号，需更强 case 或更多 repeats。 |

Default structural 只在 `prefetch_distance_0/2/4` 三个非常小的 synthetic distance case 上显示
time win，但这些 case control `cache_misses` 均为 `0`，所以它们不能证明 cache prefetch 机理。

## AWS 资源和费用

实例状态：本实验结束后再次查询，没有 `pending/running/stopping/stopped` 残留实例。

使用 instance：

```text
analysis/aws-cost-estimate.tsv
```

记录：

- 18 个 `c7g.large` instance。
- 后半段 9 个 instance 有 AWS `describe-instances` 返回的精确 launch/terminate time。
- 前半段 9 个 instance 只保留 executor stdout 中观察到的 instance id；费用按后半段平均 wall time
  `0.087562` hour 估算。
- 估算单价：`c7g.large` Linux on-demand us-east-1 约 `$0.0725/hour`。
- root volume：`32 GiB`，EBS gp3 按 `$0.08/GB-month` 估算。
- 合计估算：约 `$0.119872`。

费用估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 后续

1. 继续追 profile-fed future-address policies：horizon2、pipeline、spatial、MLOP、degree1。
2. 不继续投入 default structural / same-iteration / plain stride 作为默认 policy。
3. 补两项未完成 policy：
   - `struct-field` stable future-pointer profile point。
   - `mixed-policy-table` per-PC policy/profile schema。
4. 做 corpus site census，确认真实 BPF 是否有足够多 future-address / spatial / MLOP shape。
5. 再设计自动 selector；不要把 hand-profiled positive case 直接 default-enable。

## 收尾一致性复查

已回看：

- `actions/02-experiment-flow.md`
- `actions/05-documentation-flow.md`
- `actions/06-aws-flow.md`
- `actions/08-experiment-record-flow.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- 相关前序实验：PMU capability matrix、variant/degree evidence、PF-LLM-inspired attribution。

发现和处理：

- 旧 report 写成 `blocked_before_run`，已更新为完整结果。
- 文档里仍说 PF-LLM-inspired paired attribution 缺 PMU 归因。已更新为 c7g PMU-backed evidence。
- 文档里容易把 hint ABI、degree support、PMU capability 和 policy 混在一起。已在 policy matrix 中明确区分。
- 没有发现需要删除的临时代码或 workaround；本实验没有代码行为改动。

是否重跑：

- 本实验已经覆盖当前问题：所有已实现且有 profile 的 prefetch policy/case 都完成 c7g PMU-backed
  treatment/control attribution。
- 收尾只修改文档和实验记录，没有修改代码行为，因此不需要重新跑 benchmark。

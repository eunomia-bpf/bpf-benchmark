# 2026-06-02 prefetch-arm64-horizon-l1-pmu-stability

## 结论

本实验完成了 ARM64 `horizon2` / `horizon4` L1 prefetch candidate 的 long-repeat
AWS kernel micro 验证，并打开 `PERF_COUNTERS=1`。

结果：

- `prefetch_pipeline_horizon2_page_stride + l1keep`：mean treatment/control
  `0.945361`，约 `5.78%` nominal speedup。
- `prefetch_pipeline_horizon4_page_stride + l1keep`：mean treatment/control
  `0.971207`，约 `2.96%` nominal speedup。
- 两个 treatment 每个 sample 都实际应用了 1 个 prefetch site：
  `sites_matched=1`、`sites_applied=1`、`sites_skipped=0`、`insn_delta=2`。
- 所有 sample 的 expected result 都正确。
- AWS 仍不能提供本任务最需要的 `cache_misses` / `cache_references` /
  `instructions` counters；只采到了 `cycles` 和 `task_clock_ns`。

因此，本实验把当前结论更新为：

```text
ARM64 future-address horizon2/horizon4 + L1 hint 在 synthetic-control micro 上有重复出现的
正向 timing/cycles signal；但默认 AWS micro 环境仍不能提供 cache-miss 机理归因，因此它还不是
default-enable 证据。
```

## 实验问题

前序 `2026-06-02-prefetch-variant-degree-evidence` 显示：

| case | ARM64 `l1keep` mean T/C | 结论 |
|---|---:|---|
| `prefetch_pipeline_horizon2_page_stride` | `0.954973` | L1 hint 有 positive signal。 |
| `prefetch_pipeline_horizon4_page_stride` | `0.964590` | L1 hint 有 positive signal。 |

但是前序实验仍缺两件事：

1. 样本数和 repeat 不够大，需要 long-repeat stability check。
2. 缺少 PMU 归因，需要再次确认当前 AWS 环境能否采到 cache counters。

本实验回答：

```text
在 SAMPLES=10、WARMUPS=2、INNER_REPEAT=10000 且 PERF_COUNTERS=1 时，
horizon2/horizon4 + l1keep 是否仍保持 treatment 更快？
```

## Micro benchmark 说明

本实验使用两个本 task 新增的 `synthetic-control` micro case。

它们不是从真实 BPF 程序自动提取的，而是为 prefetch policy-space 搜索构造的 upper-bound
case。目的不是证明真实 workload 效果，而是回答：

```text
如果 BPF 程序里已经有 future map-value pointer，Kinsn prefetch 是否能提前发 hint 并降低 runtime？
```

公共设置：

- BPF C file：`/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- manifest：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- IO mode：`map`
- input：`/home/ruoji/github/bpf-opt/code/micro/generated-inputs/prefetch_upper_bound.mem`
- working set：`1 MiB` map value
- runtime：`kernel`

| case | 新增 | 策略 | 为什么能测 prefetch |
|---|---|---|---|
| `prefetch_pipeline_horizon2_page_stride` | yes | 第 `i` 轮预取第 `i+2` 轮会使用的 map-value pointer。 | 比 same-iteration prefetch 多 2 个 logical steps 的 lead time。 |
| `prefetch_pipeline_horizon4_page_stride` | yes | 第 `i` 轮预取第 `i+4` 轮会使用的 map-value pointer。 | 提供更长 lead time，测试 future-address prefetch 是否仍及时且不太早。 |

## Policy 和实现

Prefetch 是插入型 kinsn，不是替换型 kinsn。

Control 仍执行原始 demand load：

```text
load *(ptr)
```

Treatment 在 demand load 前额外插入：

```text
KINSN_SIDECAR(ptr_reg)
KINSN_CALL(bpf_arm64_prfm_pldl1keep)
load *(ptr)
```

ARM64 JIT 目标 native hint 是：

```text
prfm pldl1keep, [xN]
```

本实验仍使用 profile point，而不是自动 selector：

| treatment | profile | 含义 |
|---|---|---|
| horizon2 | `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon2-page-stride-profile-pc23-r6.json` | 在 BPF PC 23，`r6` 是 `i+2` future pointer。 |
| horizon4 | `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon4-page-stride-profile-pc23-r9.json` | 在 BPF PC 23，`r9` 是 `i+4` future pointer。 |

## 命令

所有命令从 `/home/ruoji/github/bpf-opt` 执行，均通过 AWS wrapper / Makefile 入口。

ARM64 control：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pf-horizon-arm64-control-pmu1 \
  BENCH='prefetch_pipeline_horizon2_page_stride prefetch_pipeline_horizon4_page_stride' \
  RUNTIMES=kernel \
  SAMPLES=10 \
  WARMUPS=2 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1
```

ARM64 horizon2 treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pf-horizon2-arm64-l1keep-pmu1 \
  BENCH='prefetch_pipeline_horizon2_page_stride' \
  RUNTIMES=kernel \
  SAMPLES=10 \
  WARMUPS=2 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon2-page-stride-profile-pc23-r6.json --hint l1keep'
```

ARM64 horizon4 treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pf-horizon4-arm64-l1keep-pmu1 \
  BENCH='prefetch_pipeline_horizon4_page_stride' \
  RUNTIMES=kernel \
  SAMPLES=10 \
  WARMUPS=2 \
  INNER_REPEAT=10000 \
  PERF_COUNTERS=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon4-page-stride-profile-pc23-r9.json --hint l1keep'
```

Final cleanup：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 terminate
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- AWS region：`us-east-1`
- AWS profile：`default`
- instance type：`t4g.small`
- remote user：`ec2-user`
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- kernel：`7.0.0-rc2+`
- platform：`Linux-7.0.0-rc2+-aarch64-with-glibc2.39`
- `perf_event_paranoid`：`2`
- samples：10
- warmups：2
- inner repeat：10000
- timing source：`ktime`

AWS instances：

| role | instance id | state | result dir |
|---|---|---|---|
| control | `i-0833b4986dc759cff` | terminated | `aws_arm64_micro_20260603_024138_256667` |
| horizon2 treatment | `i-046988f0fe0837b81` | terminated | `aws_arm64_micro_20260603_025020_311804` |
| horizon4 treatment | `i-03e2a47a7e9ca8274` | terminated | `aws_arm64_micro_20260603_025753_420811` |

## AWS 时间和费用

价格来源：AWS Pricing API，`AmazonEC2`，Linux On-Demand `t4g.small` in `us-east-1`：
`$0.0168/hour`。

因为 EC2 `describe-instances` 没有直接返回 termination timestamp，本报告使用
`launch_time -> benchmark generated_at` 作为 compute lower-bound。真实费用会略高；仍应低于
`$0.01` 量级。

| role | minutes lower-bound | compute USD lower-bound |
|---|---:|---:|
| control | 5.89 | 0.001649 |
| horizon2 treatment | 6.64 | 0.001859 |
| horizon4 treatment | 5.96 | 0.001668 |
| total | 18.49 | 0.005176 |

费用不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 文件改动

本实验没有修改代码行为。

新增实验记录和分析：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/data/aws-instance-describe.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/data/aws-pricing-t4g-small.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/data/aws-results/`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/per-sample-runtime.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/runtime-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/treatment-control-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/pmu-availability.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/bpfopt-prefetch-aggregate.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/aws-instances.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-arm64-horizon-l1-pmu-stability/analysis/aws-cost-estimate.tsv`

同步更新的 task 文档：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/README.md`

## 数据文件

Raw AWS result copy：

- `data/aws-results/aws_arm64_micro_20260603_024138_256667/`
- `data/aws-results/aws_arm64_micro_20260603_025020_311804/`
- `data/aws-results/aws_arm64_micro_20260603_025753_420811/`

Analysis：

- `analysis/per-sample-runtime.tsv`
- `analysis/runtime-summary.tsv`
- `analysis/treatment-control-summary.tsv`
- `analysis/pmu-availability.tsv`
- `analysis/bpfopt-prefetch-summary.tsv`
- `analysis/bpfopt-prefetch-aggregate.tsv`
- `analysis/aws-instances.tsv`
- `analysis/aws-cost-estimate.tsv`

## 问题和处理

### PMU counters 仍不完整

每个 sample 都请求了 PMU counters，但 AWS 环境仍返回：

```text
perf_event_open(instructions): No such file or directory
perf_event_open(branches): No such file or directory
perf_event_open(branch_misses): No such file or directory
perf_event_open(cache_references): No such file or directory
perf_event_open(cache_misses): No such file or directory
```

实际可用 counters：

- `cycles`
- `task_clock_ns`
- software counters：`context_switches`、`cpu_migrations`、`page_faults`

处理：

- 本报告只把结果解释为 timing/cycles signal。
- 不声称已经证明 cache miss/refill 下降。
- 后续若要证明机制，需要 PMU-capable 环境或单独设计替代证据。

### Control 和 treatment 仍是独立 AWS instance

当前 AWS wrapper 每次 micro run 独立创建 instance。Control 和 treatment 没有在同一 instance
上交替运行，因此 instance-level variance 仍可能影响幅度。

处理：

- 使用 `SAMPLES=10`、`INNER_REPEAT=10000` 降低样本内波动。
- 把结论限制为 “方向复现 + 幅度仍需机制归因”，不作为 default-enable 证据。

## 结果

Pass application：

| treatment | samples | sites matched | sites applied | sites skipped | insn delta |
|---|---:|---:|---:|---:|---:|
| horizon2 `l1keep` | 10 | 1 | 1 | 0 | 2 |
| horizon4 `l1keep` | 10 | 1 | 1 | 0 | 2 |

Runtime summary：

| variant | case | samples | correct | mean exec ns | median exec ns | stddev | CV % | mean cycles |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| control | horizon2 | 10 | 10 | 20194.300 | 19868.000 | 1002.783 | 4.966 | 494755983.500 |
| horizon2 `l1keep` | horizon2 | 10 | 10 | 19090.900 | 19046.500 | 226.923 | 1.189 | 476787109.900 |
| control | horizon4 | 10 | 10 | 18310.300 | 18285.500 | 212.878 | 1.163 | 457054755.200 |
| horizon4 `l1keep` | horizon4 | 10 | 10 | 17783.100 | 17758.500 | 85.134 | 0.479 | 443366784.900 |

Treatment/control：

| case | treatment | mean T/C | nominal speedup | median T/C | cycles T/C | code size delta |
|---|---|---:|---:|---:|---:|---|
| `prefetch_pipeline_horizon2_page_stride` | `l1keep` | 0.945361 | 5.779717% | 0.958652 | 0.963681 | BPF `+16 B`, native `+8 B` |
| `prefetch_pipeline_horizon4_page_stride` | `l1keep` | 0.971207 | 2.964612% | 0.971179 | 0.970052 | BPF `+16 B`, native `+0 B` |

PMU availability：

| counter | availability |
|---|---|
| `cycles` | present in all 30 samples |
| `task_clock_ns` | present in all 30 samples |
| `instructions` | missing in all 30 samples |
| `cache_references` | missing in all 30 samples |
| `cache_misses` | missing in all 30 samples |
| `branches` / `branch_misses` | missing in all 30 samples |

## 解释

本实验支持的判断：

- `horizon2` / `horizon4` future-address placement 比 same-iteration placement 更合理。
- ARM64 L1 hint 仍是当前 prefetch task 中最强的 candidate。
- `horizon2` 的 nominal gain 比 `horizon4` 更大，但 control 的 CV 也更高，因此不能只按这一次幅度排序。

本实验不能支持的判断：

- 不能证明 cache miss 下降。
- 不能证明真实 workload 会有同样收益。
- 不能证明可以 default-enable。

## 后续

下一步应该进入 `prefetch-next-iteration-selector-design`：

1. 不再扩大 same-iteration structural policy。
2. 设计自动识别 `cur` / `future` map-value pointer 的 selector，减少 hand-profile dependence。
3. 为 horizon2/horizon4 设计 real-inspired 或 corpus-census evidence，确认真实 BPF 中是否存在这种
   pipeline/future-address shape。
4. 若要证明机制，迁移到 PMU-capable 环境；当前 AWS micro 环境不能回答 cache-miss reduction。

## 收尾一致性复查

已回看：

- `2026-06-02-prefetch-variant-degree-evidence`
- `2026-06-02-prefetch-pipeline-arm64-long-stability`
- `2026-06-02-prefetch-profile-fed-map-value-pmu-attribution`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

发现和处理：

- 新结果与前序 variant/degree 结论一致：ARM64 horizon2/horizon4 + L1 hint 仍是当前最强候选。
- 新结果与前序 PMU 结论一致：默认 AWS micro 环境不能提供 cache-miss PMU attribution。
- 本实验没有修改代码行为，因此不需要重新跑 correctness tests。
- 已同步更新 prefetch task 文档和 artifact index，避免旧文档只停留在 `variant-degree-evidence`
  结论。

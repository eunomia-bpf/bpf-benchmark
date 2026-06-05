# 2026-06-04 prefetch-schema-and-pmu-evidence

## 结论

本实验完成，状态是 `completed_with_mixed_policy_results`。

本次做了两件事：

1. 把 prefetch profile schema 从简单 allow-list 扩展为带 policy metadata 的
   `map_value_policy_points`，并保持旧 `map_value_prefetch_points` 兼容。
2. 在 AWS ARM64 `c7g.large` 上对 PF-LLM-inspired 的三个剩余 policy probe 做
   PMU-capable paired attribution：
   `struct-field`、`mixed-policy-table`、`stream-of-strides`。

结果：

| case | PRFM sites | T/C exec | T/C cycles | cache miss rate delta | 结论 |
|---|---:|---:|---:|---:|---|
| `struct-field` | 3 | `0.986178` | `0.970069` | `-0.004231218` | 有小幅正向 timing，并伴随 cache-miss-rate 下降。 |
| `mixed-policy-table` | 1 | `0.977369` | `0.983388` | `-0.026663413` | 正向，但主要价值是证明 per-PC policy/skip gate 可控。 |
| `stream-of-strides` | 2 | `1.557562` | `1.706492` | `-0.000377457` | 明显变慢；虽然 miss rate 下降，但 cycles 大幅上升，应排除为默认 candidate。 |

这说明 `struct-field` 和 `mixed-policy-table` 可以保留为 profile-gated research candidate；
`stream-of-strides` 当前实现不应继续作为 positive candidate。

## 实验问题

要回答的问题：

1. `map_value_policy_points` 是否能表达 per-site prefetch policy metadata，并且仍然能
   让 `bpfopt` 正确插入 Kinsn prefetch。
2. `struct-field`、`mixed-policy-table`、`stream-of-strides` 在 ARM64 `c7g.large`
   上是否有 cache-miss PMU evidence。
3. 对于 slowdown case，是否能用 PMU 和 JIT 证据说明慢在哪里，而不是猜。

## 命令

所有 benchmark 通过 AWS wrapper / Makefile 路径运行，没有直接调用底层 runner。

本地测试：

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo fmt -p bpfopt
cargo test -p bpfopt prefetch
```

AWS 配置检查和清理：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/check.sh arm64
./aws-config/run.sh arm64 terminate
```

AWS micro control / treatment 形态：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large \
  RUN_TOKEN=prefetch-struct-c7g2-control \
  PERF_COUNTERS=1 \
  PERF_SCOPE=full_repeat_raw \
  CPU=0 \
  BENCH=prefetch_struct_field_fixed_offsets \
  RUNTIMES=kernel \
  SAMPLES=3 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

treatment 增加：

```bash
BPFREJIT_BENCH_PASSES=prefetch
BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/PATH.json --max-sites=N --hint=pldl1keep'
```

实际 RUN_TOKEN / profile：

| token | bench | pass args |
|---|---|---|
| `prefetch-struct-c7g2-control` | `prefetch_struct_field_fixed_offsets` | none |
| `prefetch-struct-c7g2-treatment` | `prefetch_struct_field_fixed_offsets` | `--profile .../prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json --max-sites=3 --hint=pldl1keep` |
| `prefetch-mixed-c7g2-control` | `prefetch_mixed_policy_table` | none |
| `prefetch-mixed-c7g2-treatment` | `prefetch_mixed_policy_table` | `--profile .../prefetch-mixed-policy-table-profile-pc23-r2.json --max-sites=1 --hint=pldl1keep` |
| `prefetch-stream-c7g2-control` | `prefetch_stream_of_strides` | none |
| `prefetch-stream-c7g2-treatment` | `prefetch_stream_of_strides` | `--profile .../prefetch-stream-of-strides-profile-pc316-r2-r9.json --max-sites=2 --hint=pldl1keep` |

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS
- arch：ARM64
- region：`us-east-1`
- instance type：`c7g.large`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- root volume：32 GiB
- CPU pin：`CPU=0`
- PMU：`PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw`

`c7g.large` 是 PMU-capability exception：默认 ARM64 micro instance `t4g.small`
在前序实验中缺少 `instructions/cache_references/cache_misses` counters。本次不是为了
variance 或并发使用 large instance，而是为了能回答 cache-miss attribution。

## 文件改动

代码：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`

profile：

- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json`

文档：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/safety-rules.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/2026-06-04-prefetch-schema-and-pmu-evidence`

## 数据文件

Raw AWS logs：

- `data/run-contract.json`
- `data/aws-arm64-prefetch-*-c7g2*.log`
- `data/aws-arm64-prefetch-*-c7g2*.stderr.log`
- `data/aws-arm64-terminate-*.log`
- `data/aws-arm64-active-instance-check.json`

Raw runner results：

- `data/aws-results/aws_arm64_micro_20260604_121254_662142`
- `data/aws-results/aws_arm64_micro_20260604_121851_379231`
- `data/aws-results/aws_arm64_micro_20260604_122548_663006`
- `data/aws-results/aws_arm64_micro_20260604_123246_004133`
- `data/aws-results/aws_arm64_micro_20260604_123959_864948`
- `data/aws-results/aws_arm64_micro_20260604_124601_021206`

Analysis：

- `analysis/result-dir-map.tsv`
- `analysis/raw-samples.tsv`
- `analysis/measurement-summary.tsv`
- `analysis/paired-ratio.tsv`
- `analysis/bpfopt-prefetch-summary.tsv`
- `analysis/jit-prfm-summary.tsv`
- `analysis/*-prfm-snippet.disasm`

## 问题和处理

### Instance type override

第一次尝试用 shell env 设置 `AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large`，但
`aws.env.local` 在 wrapper 内覆盖了它，实际变成 `t4g.small`。该错误 run 已中止并清理。

正确方式是把 instance type 作为 wrapper 后面的 Makefile 变量传入：

```bash
./aws-config/run.sh arm64 micro AWS_ARM64_BENCH_INSTANCE_TYPE=c7g.large ...
```

### Stale contract

一次 rerun 复用了旧 token，AWS executor 命中了 stale run-state，导致 contract mismatch。
处理方式：terminate 后改用新 token 后缀 `c7g2`。

### Stream-of-strides slowdown

`stream-of-strides` treatment 确实插入了两个 `prfm`，不是 selector miss：

```text
618: f98002c0  prfm pldl1keep, [x22]
61c: f9800020  prfm pldl1keep, [x1]
```

PMU 证据显示：

- `exec_ns`：`15337.0 -> 23888.3`，T/C `1.557562`
- `cycles`：`180391310.3 -> 307836260.7`，T/C `1.706492`
- `instructions`：`908105559.7 -> 875098942.7`，下降
- `cache_misses/cache_references`：下降

因此 slowdown 不是“没有降低 cache miss”，而是 PRFM / 两 stream 访问形态导致 cycles
显著增加，IPC 从约 `5.03` 降到约 `2.84`。当前证据支持把该 policy 从 positive candidate
中排除；如果以后继续研究，需要重新设计 stream scheduling，而不是直接加更多 PRFM。

## 结果

### Selector / schema

| case | sites matched | sites applied | sites skipped | insn delta | native PRFM |
|---|---:|---:|---:|---:|---:|
| `struct-field` | 3 | 3 | 0 | +6 | 3 |
| `mixed-policy-table` | 17 | 1 | 16 | +2 | 1 |
| `stream-of-strides` | 18 | 2 | 16 | +4 | 2 |

### PMU paired result

| case | control mean exec ns | treatment mean exec ns | T/C exec | speedup | T/C cycles | cache miss rate delta |
|---|---:|---:|---:|---:|---:|---:|
| `struct-field` | `16495.000000` | `16267.000000` | `0.986178` | `+1.382%` | `0.970069` | `-0.004231218` |
| `mixed-policy-table` | `16084.333333` | `15720.333333` | `0.977369` | `+2.263%` | `0.983388` | `-0.026663413` |
| `stream-of-strides` | `15337.000000` | `23888.333333` | `1.557562` | `-55.756%` | `1.706492` | `-0.000377457` |

## AWS 费用估算

价格来源：

- EC2 `c7g.large` Linux on-demand us-east-1：`$0.0725/hour`
  (`https://aws.amazon.com/ec2/pricing/on-demand/`，cross-check:
  `https://www.economize.cloud/resources/aws/pricing/ec2/c7g.large/`)
- EBS gp3 us-east-1：`$0.08/GB-month`
  (`https://aws.amazon.com/ebs/pricing/`)

本次 c7g2 batch 共 6 个 independent micro instances。按每个 instance 约 6-8 分钟估算，
compute wall time 约 `0.7` instance-hour：

- compute：`0.7 * 0.0725 ~= $0.051`
- EBS：`32 GiB * 0.08 / 730h * 0.7h ~= $0.0025`
- 加上失败 / precheck / terminate attempt，保守估算总额 `< $0.08`

不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

Instance cleanup：

- 每个 run log 里的 instance 都进入 `shutting-down`。
- `aws ec2 describe-instances` 按 tag 检查 pending/running/stopping/stopped/shutting-down：
  `[]`，没有活动 ARM64 benchmark instance。

## 后续

1. 把 `struct-field` 和 `mixed-policy-table` 保留为 profile-gated candidate。
2. 把 `stream-of-strides` 当前实现从 candidate set 排除。
3. 下一步应做 corpus site census：真实 BPF 中是否存在 MLOP、spatial、struct-field、
   horizon2/future-pointer pattern。
4. 如果 corpus 里没有足够真实 candidate，prefetch task 应保持 `research-only`。

## 收尾一致性复查

已回看：

- 当前实验所有 failed / rerun attempts：wrong-instance override、stale contract。
- 前序 prefetch docs：`README.md`、`plan.md`、`policy-matrix.md`、`results.md`。
- 前序 prefetch experiment summaries：2026-06-02 到 2026-06-04 的 PF-LLM-inspired、
  PMU、variant/degree 实验。

发现和处理：

- `struct-field` 仍被写成“待 PMU attribution”。已更新为 PMU done。
- `mixed-policy-table` 仍被写成“只支持 prefetch/skip，缺完整 metadata”。已更新为
  schema 已支持并验证 metadata 字段。
- `stream-of-strides` 仍被写成只完成 smoke。已更新为 c7g PMU done，且当前排除为
  positive candidate。
- 未发现需要删除的 prefetch 临时代码。当前 `map_value_policy_points` 的 metadata 字段已经有
  unit test 覆盖。

是否重跑：

- 本次代码改动已跑 `cargo test -p bpfopt prefetch`。
- 本次 profile schema 已通过 3 个 ARM64 c7g treatment smoke 和 PMU attribution 间接验证。

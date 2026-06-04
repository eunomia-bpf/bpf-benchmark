# 2026-06-04 prefetch-pf-llm-missing-policy-arm64-attribution

## 结论

本实验完成，状态是 `completed_with_mixed_result`。

这轮补齐了三个 PF-LLM-inspired Kinsn prefetch policy probe 的 ARM64 smoke 和 paired
attribution：

| case | policy | correctness / emit | paired treatment/control | 结论 |
|---|---|---|---:|---|
| `prefetch_struct_field_fixed_offsets` | fixed-offset struct-field | 3 个 `prfm`，结果正确 | `0.959350` | 有正向 timing signal，值得后续 PMU 归因。 |
| `prefetch_mixed_policy_table` | per-PC mixed policy table | 1 个 `prfm`，16 个 site 被 skip，结果正确 | `0.990555` | 接近 noise-level；主要证明 per-PC `prefetch` / `skip` schema 能工作。 |
| `prefetch_stream_of_strides` | two-stream stride | 2 个 `prfm`，结果正确 | `1.553949` | 明显变慢；当前 two-stream policy 不应作为 candidate。 |

所有 control / treatment 的 deterministic result 都等于 expected result。Control object 中没有
`prfm`；treatment object 中 `prfm` 数量和 profile 预期一致。

本实验没有采集 `cache_misses` / `cache_references` PMU counters。因此这里的性能判断只能算
same-instance paired timing signal，不能解释 cache miss 是否下降。需要做原因归因时，下一步应在
PMU-capable ARM64 instance 上重跑重点 case。

## 实验问题

要回答的问题：

```text
PF-LLM-inspired 的 struct-field、mixed-policy-table、stream-of-strides 三类 access pattern
是否能通过 Kinsn prefetch 在 ARM64 kernel JIT 中正确发出 prfm，并且在 paired control/treatment
micro benchmark 中是否出现可复查的 runtime signal？
```

这三个 policy 都是 `synthetic-control` micro，不是从真实 BPF 程序直接提取的 workload。
它们的目的分别是：

- `struct-field`：模拟 map-value record / struct 中多个固定 offset field 的 future-address prefetch。
- `mixed-policy-table`：同一个 BPF program 中同时存在应该 prefetch 的 site 和应该 skip 的 site，
  测试 per-PC policy table 是否能做 negative filtering。
- `stream-of-strides`：同一个 loop 中存在两个交错 stride stream，测试多个 future stream 同时
  prefetch 是否有收益。

## 命令

所有 AWS benchmark 都通过配置 wrapper 运行，等价于从 code repo 使用 Makefile 入口：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro ...
```

预清理：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 terminate
```

Smoke control 形态：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  BENCH=<case> \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1
```

Smoke treatment 形态：

```bash
cd /home/ruoji/github/bpf-opt
BPFREJIT_BENCH_PASSES=prefetch \
BPFREJIT_BENCH_PASS_ARGS='<profile args>' \
./aws-config/run.sh arm64 micro \
  BENCH=<case> \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1
```

Paired attribution control 形态：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  BENCH=<case> \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

Paired attribution treatment 形态：

```bash
cd /home/ruoji/github/bpf-opt
BPFREJIT_BENCH_PASSES=prefetch \
BPFREJIT_BENCH_PASS_ARGS='<profile args>' \
./aws-config/run.sh arm64 micro \
  BENCH=<case> \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

实际 profile args：

| case | treatment profile args |
|---|---|
| `prefetch_struct_field_fixed_offsets` | `--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json --max-sites=3 --hint=pldl1keep` |
| `prefetch_mixed_policy_table` | `--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json --max-sites=1 --hint=pldl1keep` |
| `prefetch_stream_of_strides` | `--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json --max-sites=2 --hint=pldl1keep` |

最终清理：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 terminate
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS
- arch：ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote runtime container：`bpf-benchmark/runner-runtime:arm64`
- runtime：kernel micro / `BPF_PROG_TEST_RUN`
- prefetch hint：ARM64 `pldl1keep`，native form 是 `prfm pldl1keep, [xN]`

## 文件改动

本实验没有改代码。它使用已有 prefetch implementation、profile JSON 和 micro cases。

新增 / 更新实验记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/arm64-smoke-status.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/arm64-paired-status.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/arm64-result-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/arm64-paired-ratio.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/result-dir-map.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/analysis/aws-instance-ids.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/data/aws-instance-final-state.json`

## 数据文件

Raw result 副本保存在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution/data/aws-results
```

原始 runner result 目录：

| label | result dir |
|---|---|
| `prefetch-struct-field-arm64-control-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_095753_609329` |
| `prefetch-struct-field-arm64-treatment-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_100352_577197` |
| `prefetch-mixed-policy-arm64-control-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_101118_733301` |
| `prefetch-mixed-policy-arm64-treatment-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_101808_682174` |
| `prefetch-stream-arm64-control-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_102507_986621` |
| `prefetch-stream-arm64-treatment-smoke` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_103141_694954` |
| `prefetch-struct-field-arm64-control-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_104007_334790` |
| `prefetch-struct-field-arm64-treatment-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_104711_236149` |
| `prefetch-mixed-policy-arm64-control-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_105356_090170` |
| `prefetch-mixed-policy-arm64-treatment-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_110106_683480` |
| `prefetch-stream-arm64-control-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_110801_206792` |
| `prefetch-stream-arm64-treatment-paired` | `/home/ruoji/github/bpf-opt/code/micro/results/aws_arm64_micro_20260604_111404_577318` |

## 问题和处理

初始状态下 AWS session 已过期，第一次预清理失败：

```text
Your session has expired. Please reauthenticate using 'aws login'.
```

用户重新登录后，本实验继续使用同一个实验目录。重新执行 `./aws-config/run.sh arm64 terminate`
成功，然后运行 smoke 和 paired attribution。

没有残留 instance。最终清理命令成功。`aws ec2 describe-instances` 当前能查到 8 个实例记录，
全部是 `terminated`；另外 4 个早期 smoke instance ID 单独查询返回空数组，记录仍保存在 wrapper log
和 `analysis/aws-instance-ids.tsv` 中。

## 结果

### Smoke

| case | control result | treatment result | treatment `prfm` | sites matched | sites applied | sites skipped | status |
|---|---:|---:|---:|---:|---:|---:|---|
| `prefetch_struct_field_fixed_offsets` | `12246088582525788897` | `12246088582525788897` | 3 | 3 | 3 | 0 | passed |
| `prefetch_mixed_policy_table` | `16217383686291505505` | `16217383686291505505` | 1 | 17 | 1 | 16 | passed |
| `prefetch_stream_of_strides` | `2202534365130024933` | `2202534365130024933` | 2 | 18 | 2 | 16 | passed |

解释：

- `struct-field` 命中 3 个 fixed-offset future field，插入 3 个 `prfm`。
- `mixed-policy-table` 证明 per-PC policy 能只插 1 个 selected site，并跳过其他 16 个候选。
- `stream-of-strides` 命中两个 stream，各插一个 future-address `prfm`。

### Paired attribution

| case | control mean `exec_ns` | treatment mean `exec_ns` | treatment/control | 结论 |
|---|---:|---:|---:|---|
| `prefetch_struct_field_fixed_offsets` | `24457.8` | `23463.6` | `0.959350` | timing positive，约快 `4.065%`。 |
| `prefetch_mixed_policy_table` | `23016.6` | `22799.2` | `0.990555` | 弱正向，接近 noise-level。 |
| `prefetch_stream_of_strides` | `22923.4` | `35621.8` | `1.553949` | 明显变慢。 |

`exec_ns` 是 kernel test-run 口径下的 execution time。Ratio 小于 1 表示 treatment 更快。

### AWS instance 和费用估算

价格来源：

- AWS EC2 On-Demand Pricing：`https://aws.amazon.com/ec2/pricing/on-demand/`
- AWS EBS Pricing：`https://aws.amazon.com/ebs/pricing/`

估算使用：

- `t4g.small` Linux On-Demand：`$0.0168/hour`
- gp3 EBS：`$0.08/GB-month`
- root volume：`32 GiB`
- EBS 换算：`hours * 32 * 0.08 / (30 * 24)`

逐 run 估算：

| run | wall time hours | compute | root EBS | estimated total |
|---|---:|---:|---:|---:|
| `prefetch-struct-field-arm64-control-smoke` | `0.1061` | `$0.0018` | `$0.0004` | `$0.0022` |
| `prefetch-struct-field-arm64-treatment-smoke` | `0.0997` | `$0.0017` | `$0.0004` | `$0.0020` |
| `prefetch-mixed-policy-arm64-control-smoke` | `0.1239` | `$0.0021` | `$0.0004` | `$0.0025` |
| `prefetch-mixed-policy-arm64-treatment-smoke` | `0.1142` | `$0.0019` | `$0.0004` | `$0.0023` |
| `prefetch-stream-arm64-control-smoke` | `0.1161` | `$0.0020` | `$0.0004` | `$0.0024` |
| `prefetch-stream-arm64-treatment-smoke` | `0.1094` | `$0.0018` | `$0.0004` | `$0.0022` |
| `prefetch-struct-field-arm64-control-paired` | `0.1244` | `$0.0021` | `$0.0004` | `$0.0025` |
| `prefetch-struct-field-arm64-treatment-paired` | `0.1183` | `$0.0020` | `$0.0004` | `$0.0024` |
| `prefetch-mixed-policy-arm64-control-paired` | `0.1117` | `$0.0019` | `$0.0004` | `$0.0023` |
| `prefetch-mixed-policy-arm64-treatment-paired` | `0.1197` | `$0.0020` | `$0.0004` | `$0.0024` |
| `prefetch-stream-arm64-control-paired` | `0.1153` | `$0.0019` | `$0.0004` | `$0.0023` |
| `prefetch-stream-arm64-treatment-paired` | `0.1028` | `$0.0017` | `$0.0004` | `$0.0021` |

合计 wrapper wall time 约 `1.3617` instance-hours；compute 约 `$0.0229`，root EBS 约
`$0.0048`，合计约 `$0.0277`。

该估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 后续

本实验把 `struct-field`、`mixed-policy-table`、`stream-of-strides` 从 x86 emit smoke 推进到
ARM64 paired attribution。下一步应该：

1. 对 `struct-field` 做 PMU-capable rerun，确认 timing positive 是否来自 cache miss 下降。
2. 对 `stream-of-strides` 做 JIT/native attribution，确认 slowdown 是 instruction overhead、
   wrong timeliness、cache pollution，还是 case 与 policy 不匹配。
3. 扩展 integrated profile table schema，让每个 site 记录 `policy`、`horizon`、`degree`、
   `hint` 和 `reason`，而不只是 `prefetch` / `skip`。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-smoke/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md`

发现和处理：

- 本 report 原先停留在 `blocked_before_launch`，已更新为完整 ARM64 smoke / paired attribution 结果。
- canonical docs 原先把这三个 policy 写成 ARM64 attribution pending；已同步更新
  `README.md`、`plan.md`、`policy-matrix.md`、`results.md`、`microbench-design.md`
  和 experiment artifact index。
- 本实验没有改代码，因此不需要因为收尾复查重跑 benchmark。

是否重跑：

- 登录恢复后已经在同一个实验目录完成 smoke 和 paired attribution。
- 收尾只修改文档和实验记录，不改变代码行为，因此不需要额外 rerun。

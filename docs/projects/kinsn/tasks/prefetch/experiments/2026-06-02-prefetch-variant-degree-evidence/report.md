# 2026-06-02 prefetch-variant-degree-evidence

## 结论

本实验把 prefetch task 的 P18/P20/P21 补齐到可复查状态：

- P18 hint variant：x86 `prefetchnta/prefetcht0/prefetcht1/prefetcht2` 和 ARM64
  `prfm pldl1keep/pldl1strm/pldl2keep/pldl2strm` ABI/native emit 已打通。
- P20 degree parameter：新增 `prefetch_pipeline_degree_page_stride`，在同一 logical site 对
  `i+1/i+2/i+4` 三个 future map-value pointer 发 prefetch。
- P21 horizon sweep：新增 `prefetch_pipeline_horizon1/2/4_page_stride`，分别提前 1/2/4
  个 logical step 预取 future pointer。
- ARM64 上，L1 hint 的 horizon2/horizon4 是本轮最清楚的 positive signal：
  - horizon2 `l1keep` mean T/C `0.954973`，`l1strm` `0.957488`。
  - horizon4 `l1keep` mean T/C `0.964590`，`l1strm` `0.966710`。
- ARM64 degree 的 `l1keep` 只有弱信号：mean T/C `0.982073`，按本报告标准归为 noise。
- x86 上没有稳定大收益；`t1` 在 horizon2 有弱信号 mean T/C `0.981512`，但仍按 noise 处理。
- x86 `nta` 在全部四个 case 都明显变慢，不能作为当前 kinsn prefetch 默认候选。
- 默认 AWS micro 环境仍缺少 cache-miss PMU counters，因此本轮不能证明收益来自 cache-miss
  下降，只能给 timing/code-size/native-hint evidence。

本实验的结论不是 “prefetch 已经可以 default-enable”。当前更准确的结论是：

```text
future-address horizon + ARM64 L1 hint 是值得继续做 selector 的候选；
x86 NTA 和 ARM64 L2 hints 在这些 synthetic-control case 上不适合作为默认策略；
下一步需要 PMU-capable 环境或更强 codegen/dynamic evidence 来解释机制。
```

## 实验问题

本实验回答三个问题：

1. 当前 prefetch kinsn 是否能表达不同架构的 hint variant？
2. 对同一个 future-address micro case，hint variant、horizon、degree 哪些组合有收益？
3. 对不加速的 policy，能不能用数据区分 “case 不敏感”、 “hint 选择错误”、 “lead time 不足”
   或 “prefetch 本身增加成本”？

## Micro benchmark 说明

本实验使用的四个 case 都是本 task 新增的 `synthetic-control` micro。它们不是从真实 BPF
程序提取的，而是为 prefetch policy-space 搜索构造的 upper-bound probes。

这些 case 都使用：

- BPF C file：`/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- manifest：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- IO mode：`map`
- input size：`1048576` bytes
- input generator：`prefetch_upper_bound`
- runtime：`kernel`

| case | 新增 | 测试什么 | 为什么能测 prefetch |
|---|---|---|---|
| `prefetch_pipeline_horizon1_page_stride` | yes | 第 `i` 轮提前预取 `i+1` future pointer。 | 比 same-iteration 多一些 lead time，但可能仍不够。 |
| `prefetch_pipeline_horizon2_page_stride` | yes | 第 `i` 轮提前预取 `i+2` future pointer。 | 提供更长 lead time，仍保持较近复用距离。 |
| `prefetch_pipeline_horizon4_page_stride` | yes | 第 `i` 轮提前预取 `i+4` future pointer。 | 测试更长 lead time 是否更适合 page-stride map working set。 |
| `prefetch_pipeline_degree_page_stride` | yes | 同一轮同时预取 `i+1/i+2/i+4` 三个 future pointers。 | 测试 PF-style degree 是否能覆盖多个未来 miss，但也可能增加 cache/bandwidth pressure。 |

这些 case 的目的不是证明真实 workload 覆盖率，而是回答：

```text
如果我们给 prefetch 最有利的 future-address placement，它是否至少在 controlled case 上有效？
```

## Policy 和实现

本实验使用 `bpfopt --pass prefetch`。Pass 在 BPF bytecode 上插入：

```text
KINSN_SIDECAR(ptr_reg)
KINSN_CALL(bpf_x86_prefetch* 或 bpf_arm64_prfm_*)
```

原始 demand load 保留，因此 treatment 总是多出 prefetch hint。性能收益必须来自 prefetch
隐藏 memory latency，且收益要大于额外 hint 的 frontend/bandwidth/cache 成本。

本轮使用 profile point，而不是自动 selector 合成 future address。Profile point 的含义是：

```text
在 BPF PC X，寄存器 rY 已经持有一个 verifier-safe map-value future pointer。
在这里插入 prefetch kinsn。
```

本轮 profile 文件：

| profile | 含义 |
|---|---|
| `prefetch-pipeline-horizon1-page-stride-profile-pc24-r9.json` | horizon1：PC 24，`r9` 是 future pointer。 |
| `prefetch-pipeline-horizon2-page-stride-profile-pc23-r6.json` | horizon2：PC 23，`r6` 是 future pointer。 |
| `prefetch-pipeline-horizon4-page-stride-profile-pc23-r9.json` | horizon4：PC 23，`r9` 是 future pointer。 |
| `prefetch-pipeline-degree-page-stride-profile-pc259-r5-pc273-r3-pc287-r0.json` | degree：PC 259/273/287，`r5/r3/r0` 是三个 future pointers。 |
| `prefetch-pipeline-horizon-degree-page-stride-profile.json` | 本轮 AWS run 使用的 combined profile。 |

Hint mapping：

| arch | variant | kfunc target | native hint |
|---|---|---|---|
| ARM64 | `l1keep` | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [xN]` |
| ARM64 | `l1strm` | `bpf_arm64_prfm_pldl1strm` | `prfm pldl1strm, [xN]` |
| ARM64 | `l2keep` | `bpf_arm64_prfm_pldl2keep` | `prfm pldl2keep, [xN]` |
| ARM64 | `l2strm` | `bpf_arm64_prfm_pldl2strm` | `prfm pldl2strm, [xN]` |
| x86 | `t0` | `bpf_x86_prefetcht0` | `prefetcht0 [rN]` |
| x86 | `t1` | `bpf_x86_prefetcht1` | `prefetcht1 [rN]` |
| x86 | `t2` | `bpf_x86_prefetcht2` | `prefetcht2 [rN]` |
| x86 | `nta` | `bpf_x86_prefetchnta` | `prefetchnta [rN]` |

## 命令

所有命令从 `/home/ruoji/github/bpf-opt` 执行。Benchmark 都通过 AWS wrapper 运行。

ARM64 control：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pfarmctl195831 \
  BENCH="prefetch_pipeline_horizon1_page_stride prefetch_pipeline_horizon2_page_stride prefetch_pipeline_horizon4_page_stride prefetch_pipeline_degree_page_stride" \
  RUNTIMES=kernel \
  SAMPLES=7 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  PERF_COUNTERS=1
```

ARM64 treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BENCH="prefetch_pipeline_horizon1_page_stride prefetch_pipeline_horizon2_page_stride prefetch_pipeline_horizon4_page_stride prefetch_pipeline_degree_page_stride" \
  RUNTIMES=kernel \
  SAMPLES=7 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  PERF_COUNTERS=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon-degree-page-stride-profile.json --max-sites 3 --hint HINT"
```

ARM64 `HINT` values：默认 `l1keep`、`l1strm`、`l2keep`、`l2strm`。

x86 control：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pfx86ctl203416 \
  BENCH="prefetch_pipeline_horizon1_page_stride prefetch_pipeline_horizon2_page_stride prefetch_pipeline_horizon4_page_stride prefetch_pipeline_degree_page_stride" \
  RUNTIMES=kernel \
  SAMPLES=7 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  PERF_COUNTERS=1
```

x86 treatment：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH="prefetch_pipeline_horizon1_page_stride prefetch_pipeline_horizon2_page_stride prefetch_pipeline_horizon4_page_stride prefetch_pipeline_degree_page_stride" \
  RUNTIMES=kernel \
  SAMPLES=7 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  PERF_COUNTERS=1 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon-degree-page-stride-profile.json --max-sites 3 --hint HINT"
```

x86 `HINT` values：`t0`、`t1`、`t2`、`nta`。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS kernel micro
- AWS region：`us-east-1`
- remote user：`ec2-user`
- ARM64 instance：`t4g.small`
- x86 instance：`t3.small`
- kernel：`7.0.0-rc2+`
- ARM64 runtime image：`bpf-benchmark/runner-runtime:arm64`
- x86 runtime image：`bpf-benchmark/runner-runtime:x86_64`
- root volume：`32 GiB`

AWS instance summary for the degree/horizon run is in:

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-variant-degree-evidence/analysis/aws-instances-degree-horizon.tsv
```

All degree/horizon instances reached `shutting-down` through the wrapper. A final x86 terminate wrapper was also
run after the last x86 variant.

费用估算：

- 价格来源：沿用 `us-east-1` Linux On-Demand public price used by earlier reports.
- `t4g.small`：`$0.0168/hour`。
- `t3.small`：`$0.0208/hour`。
- gp3 EBS：`$0.08/GB-month`。
- 估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

本报告的 `aws-instances-degree-horizon.tsv` 用 runner metadata 的 `started_at/completed_at`
计算 runner window cost。真实 EC2 launch-to-shutdown wall time 略长；本轮 wrapper 输出中的
instance ids 已记录在表里。

## 文件改动

本实验涉及的代码和配置改动：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon1-page-stride-profile-pc24-r9.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon2-page-stride-profile-pc23-r6.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon4-page-stride-profile-pc23-r9.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-degree-page-stride-profile-pc259-r5-pc273-r3-pc287-r0.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon-page-stride-profile-pc23-r6-r9.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-horizon-degree-page-stride-profile.json`

前序同一实验已经记录的 hint ABI / pass 改动：

- `/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c`
- `/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/kinsnprober/src/main.rs`
- `/home/ruoji/github/bpf-opt/code/runner/config/passes/prefetch/default.yaml`

## 数据文件

新增分析文件：

- `analysis/degree-horizon-runtime.tsv`
- `analysis/degree-horizon-summary.tsv`
- `analysis/aws-instances-degree-horizon.tsv`
- `analysis/pmu-availability-degree-horizon.tsv`

新增 raw result copies：

- `data/aws-results/aws_arm64_micro_20260603_000024_733232`
- `data/aws-results/aws_arm64_micro_20260603_000849_265322`
- `data/aws-results/aws_arm64_micro_20260603_001622_048610`
- `data/aws-results/aws_arm64_micro_20260603_002356_463384`
- `data/aws-results/aws_arm64_micro_20260603_003146_747479`
- `data/aws-results/aws_x86_micro_20260603_004208_489943`
- `data/aws-results/aws_x86_micro_20260603_005048_125780`
- `data/aws-results/aws_x86_micro_20260603_005810_555037`
- `data/aws-results/aws_x86_micro_20260603_010552_992793`
- `data/aws-results/aws_x86_micro_20260603_011322_532995`

前序同一实验已有数据仍保留：

- `data/run-contract.json`
- `analysis/check-summary.tsv`
- `analysis/variant-runtime.tsv`
- `analysis/native-hint-evidence.tsv`
- `analysis/aws-instances.tsv`
- `analysis/aws-cost.tsv`
- `data/aws-results/aws_x86_micro_20260602_221811_212815`
- `data/aws-results/aws_x86_micro_20260602_222526_406675`
- `data/aws-results/aws_arm64_micro_20260602_223212_019101`
- `data/aws-results/aws_arm64_micro_20260602_223911_428229`

## 结果

### ARM64

| case | best hint | best mean T/C | 结论 |
|---|---|---:|---|
| horizon1 | `l1keep` | `1.004758` | 没有 win；horizon 太近或 noise。 |
| horizon2 | `l1keep` | `0.954973` | stable positive signal。 |
| horizon4 | `l1keep` | `0.964590` | stable positive signal。 |
| degree | `l1keep` | `0.982073` | weak/noise；degree 没有优于 horizon2/horizon4。 |

完整 ARM64 treatment/control：

| case | l1keep | l1strm | l2keep | l2strm |
|---|---:|---:|---:|---:|
| horizon1 | `1.004758` | `1.046112` | `1.052638` | `1.045345` |
| horizon2 | `0.954973` | `0.957488` | `1.003412` | `0.999053` |
| horizon4 | `0.964590` | `0.966710` | `0.986399` | `0.980974` |
| degree | `0.982073` | `1.001012` | `1.052795` | `1.017365` |

Interpretation：

- L1 hints 对 horizon2/horizon4 有一致收益。
- L2 hints 明显弱于 L1 hints；`l2keep` 在 degree 上慢且 CV 高。
- degree 同时发 3 个 future prefetch，没有比单个 horizon2/horizon4 更好，可能增加额外 hint 成本或污染。

### x86

| case | best hint | best mean T/C | 结论 |
|---|---|---:|---|
| horizon1 | `t2` | `0.998209` | noise。 |
| horizon2 | `t1` | `0.981512` | weak/noise，未达到本报告 win threshold。 |
| horizon4 | `t0` | `0.991978` | noise。 |
| degree | `t1` | `0.996759` | noise。 |

完整 x86 treatment/control：

| case | t0 | t1 | t2 | nta |
|---|---:|---:|---:|---:|
| horizon1 | `1.001926` | `1.008699` | `0.998209` | `2.944734` |
| horizon2 | `1.000225` | `0.981512` | `1.040229` | `2.393923` |
| horizon4 | `0.991978` | `1.003474` | `2.345639` | `1.681460` |
| degree | `1.445870` | `0.996759` | `1.045975` | `1.610153` |

Interpretation：

- x86 没有稳定大收益。
- `nta` 在所有 case 上都明显变慢，不适合当前 Kinsn prefetch policy。
- `t2` 的 horizon4 和 `t0` 的 degree CV 很高，不能作为结论。
- x86 的 preferred hint 在这些 case 上不清楚；继续投入前需要更强 PMU 或更接近真实 workload 的 case。

### PMU availability

本轮设置了 `PERF_COUNTERS=1`，但 AWS micro 环境仍缺少关键 PMU counters：

- ARM64：能采 `cycles` / `task_clock_ns`，缺 `instructions`、`branches`、`cache_references`、
  `cache_misses`。
- x86：连 `cycles` 也不可用，只能采 `task_clock_ns` / scheduler counters。

因此本轮不能写 “cache miss 下降导致加速”。能写的是：

```text
timing positive/negative + native hint emitted + code size changed + PMU cache counters unavailable
```

## 问题和处理

1. 初始 degree 设计中，profile point 对应的寄存器在选定 PC 处不能被 `bpfopt` 证明为 map-value
   pointer。处理方式：重写 degree case，使 `i+1/i+2/i+4` future map-value pointer 在各自
   profile point 处显式保存在 live register 中。修复后本地 validation 显示 degree
   `sites_applied=3`。
2. x86 / ARM64 AWS 的 cache PMU counters 不可用。这不是本轮代码引入的问题，前序 PMU capability
   smoke 已经确认同一环境缺少这些 counters。本轮报告不写 cache-miss 机理结论。
3. 本轮结果仍是 synthetic-control，不是 corpus/e2e 覆盖率证据。报告中不把它解释为真实 workload
   收益。

## 后续

1. 对 ARM64 horizon2/horizon4 L1 hint 做更稳定的 repeated independent runs。
2. 在 PMU-capable 环境上复测 ARM64 horizon2/horizon4，至少需要 cache-miss/refill 或 LLC miss 证据。
3. 设计自动 selector：从 hand-profiled PC/reg 过渡到能识别 `cur/next` software pipeline 形态。
4. x86 先不要继续扩展 `nta`；如果继续测 x86，应优先 `t1` horizon2 和 `t0` horizon4，并换 PMU-capable
   环境。
5. 将 `results.md` 和 `policy-matrix.md` 更新为：P18/P20/P21 已完成第一轮系统实验，而不是待完成。

## 收尾一致性复查

已回看：

- `2026-06-02-prefetch-profile-fed-map-value-pmu-attribution`
- `2026-06-02-prefetch-upper-bound-map-attribution`
- `2026-06-02-prefetch-pipeline-map-attribution`
- `2026-06-02-prefetch-pipeline-map-independent-rerun1`
- `2026-06-02-prefetch-pipeline-arm64-long-stability`
- `2026-06-02-prefetch-variant-degree-evidence` 旧版 report
- prefetch task README、results、policy matrix

发现和处理：

- 旧 report 只覆盖 hint smoke，仍把 degree/horizon 参数写成未完成。已更新为 degree/horizon 第一轮
  attribution 已完成。
- 旧文档容易把 `--max-sites` 误读为 degree 参数。已明确：本轮 degree 参数是多个 future addresses，
  不是 site budget。
- 旧文档没有把新 micro case 标清楚。已在本 report 的 Micro benchmark 说明里全部标注为新增
  `synthetic-control`。
- 顶层 prefetch plan 仍保留 “hint variant 未测 / ARM64 只支持 PLDL1KEEP” 的旧状态。已更新
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`，并用 grep 确认没有这类
  旧结论残留。
- 本轮 code behavior 改动已由 Makefile build、本地 profile validation 和 AWS kernel micro 覆盖。
- 本轮只更新文档/分析时没有再改 benchmark framework 行为，因此没有额外 rerun。

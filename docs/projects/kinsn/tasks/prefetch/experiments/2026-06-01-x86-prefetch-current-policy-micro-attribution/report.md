# 2026-06-01 x86-prefetch-current-policy-micro-attribution

## 结论

本实验完成，状态是 `completed_blocked_by_micro_pass_wiring`。

原始目标是：在 AWS x86 上用现有 Kinsn `bpfopt --pass prefetch` 策略跑完整 prefetch
micro benchmark，比较 `noop` control 和 `prefetch` treatment。

关键结论不是性能数字，而是方法学问题：

- AWS x86 micro 路径能运行，smoke / control / treatment 都完成。
- 19 个 prefetch micro case 在 `noop` 和 `prefetch` 下都 correctness 通过。
- 但 control 和 treatment 的 BPF xlated size、native JIT size 对所有 19 个 case 完全相同。
- result 目录中没有 `bpf_x86_prefetcht0` / `prefetcht0` evidence。
- 因此，本次 `BPFREJIT_BENCH_PASSES=prefetch` 没有实际作用到 micro kernel runner。

所以本实验不能作为 x86 prefetch 策略性能结论。`exec_ns` 的 geomean treatment/control 是
`0.994572`，但由于 treatment 没有插入 prefetch kinsn，这个数字只能视为 AWS / runner 噪声。

下一步不能继续直接用当前 micro command 做 x86/ARM64 policy 对比；必须先补一个能在 micro
kernel runtime 中实际应用 `bpfopt` pass 的路径，或者改用 Dynamic ReJIT/corpus 路径评估
`bpfopt --pass prefetch`。

## 实验问题

本实验要回答：

```text
现有 Kinsn prefetch policy 能否在 x86 AWS micro benchmark 上形成 control/treatment attribution？
```

答案是：当前 micro runner 路径不能回答这个问题，因为 `BPFREJIT_BENCH_PASSES` 没有改变 micro
program 的 xlated/native code。

## 背景

Kinsn prefetch 和 ARM LLVM backend forced PRFM 是两条不同路径：

| 路径 | 含义 | 本实验是否覆盖 |
|---|---|---|
| Kinsn `bpfopt --pass prefetch` | runtime / pass-level policy，把 BPF program 改写为含 `bpf_x86_prefetcht0` 或 `bpf_arm64_prfm_pldl1keep` kfunc call 的 program。 | 目标上想覆盖；实际 micro runner 未应用。 |
| ARM LLVM backend forced PRFM | LLVM BPF backend 编译时直接 emit `bpf_arm64_prfm_pldl1keep` kfunc extern。 | 不覆盖。 |
| 普通 LLVM `llvm.prefetch` | compiler intrinsic lowering。 | 不覆盖。 |

本实验使用 x86 target：

```text
/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c
bpf_x86_prefetcht0
```

预期 treatment 如果生效，BPF xlated 或 native JIT code size 应该发生变化，并且 native dump 应能看到
`prefetcht0 [rN]` 或至少 result/workdir 中保留 kfunc evidence。实际没有看到这些变化。

## Benchmark

本次覆盖全部 prefetch research micro：

| set | benchmarks |
|---|---|
| distance sweep | `prefetch_distance_0`、`prefetch_distance_2`、`prefetch_distance_4`、`prefetch_distance_8`、`prefetch_distance_16`、`prefetch_distance_32` |
| indirect / timeliness | `prefetch_indirect_lookup`、`prefetch_indirect_two_stage`、`prefetch_cacheline_dedup_scan`、`prefetch_packet_offset_guarded`、`prefetch_full_packet_ring_scan` |
| map-backed working set | `prefetch_map_page_stride`、`prefetch_map_indirect_page`、`prefetch_map_line_dedup` |
| candidate filtering | `prefetch_hot_l1_load`、`prefetch_sequential_scan`、`prefetch_large_stride_scan`、`prefetch_permuted_index_scan`、`prefetch_packet_first_deref` |

这些 benchmark 位于：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

## 命令

所有实验都从 `/home/ruoji/github/bpf-opt` 执行，通过 AWS wrapper / Makefile 路径运行。

AWS 配置检查：

```bash
./aws-config/check.sh x86
```

smoke：

```bash
BENCHES='prefetch_distance_0,prefetch_distance_2,prefetch_indirect_lookup,prefetch_map_page_stride,prefetch_hot_l1_load'

./aws-config/run.sh x86 micro \
  RUN_TOKEN=x86-prefetch-policy-smoke \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_BENCH_PASSES=prefetch
```

正式 control：

```bash
BENCHES='prefetch_distance_0,prefetch_distance_2,prefetch_distance_4,prefetch_distance_8,prefetch_distance_16,prefetch_distance_32,prefetch_indirect_lookup,prefetch_indirect_two_stage,prefetch_cacheline_dedup_scan,prefetch_packet_offset_guarded,prefetch_full_packet_ring_scan,prefetch_map_page_stride,prefetch_map_indirect_page,prefetch_map_line_dedup,prefetch_hot_l1_load,prefetch_sequential_scan,prefetch_large_stride_scan,prefetch_permuted_index_scan,prefetch_packet_first_deref'

./aws-config/run.sh x86 micro \
  RUN_TOKEN=x86-prefetch-policy-control-noop \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=7 WARMUPS=1 INNER_REPEAT=10000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_BENCH_PASSES=noop
```

正式 treatment：

```bash
./aws-config/run.sh x86 micro \
  RUN_TOKEN=x86-prefetch-policy-treatment-prefetch \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=7 WARMUPS=1 INNER_REPEAT=10000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_BENCH_PASSES=prefetch
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS x86
- instance type：`t3.small`
- region：`us-east-1`
- remote user：`ec2-user`
- runtime image：`bpf-benchmark/runner-runtime:x86_64`
- kernel：`7.0.0-rc2+`
- instance ids：
  - smoke：`i-09f4abf4ebf04be36`
  - control：`i-013f1b9fc5e253fc5`
  - treatment：`i-0527e8fc68bbcb708`

## 文件改动

本实验本身没有修改 benchmark framework code。

新增 / 更新：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-x86-prefetch-current-policy-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-x86-prefetch-current-policy-micro-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-x86-prefetch-current-policy-micro-attribution/analysis/*`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`

注意：工作树里已有其他 prefetch task 的代码和结果改动，它们不是本实验新引入的改动。

## 数据文件

Raw result copies：

- `data/smoke-result/`
- `data/control-noop-result/`
- `data/treatment-prefetch-result/`

Logs：

- `data/aws-check.log`
- `data/aws-smoke.log`
- `data/aws-control-noop.log`
- `data/aws-treatment-prefetch.log`
- `data/aws-describe-instances.json`
- `data/aws-active-after.json`
- `data/aws-pricing-t3-small.json`
- `data/aws-pricing-ebs-gp3.json`

Analysis：

- `analysis/x86-prefetch-current-policy.tsv`
- `analysis/code-size-equality.tsv`
- `analysis/summary.json`
- `analysis/topline.md`
- `analysis/aws-cost-estimate.tsv`

## 结果

### Correctness

| run | benchmarks | samples per benchmark | mismatches |
|---|---:|---:|---:|
| smoke | 5 | 1 | 0 |
| control `noop` | 19 | 7 | 0 |
| treatment `prefetch` | 19 | 7 | 0 |

### Codegen evidence

`analysis/code-size-equality.tsv` 显示 19 个 benchmark 的 control/treatment BPF xlated size 和
native JIT size 完全一致：

```text
diff_rows 0
```

例如：

| benchmark | control xlated | control native | treatment xlated | treatment native |
|---|---:|---:|---:|---:|
| `prefetch_distance_0` | 760 | 451 | 760 | 451 |
| `prefetch_indirect_two_stage` | 1192 | 644 | 1192 | 644 |
| `prefetch_map_line_dedup` | 1584 | 805 | 1584 | 805 |
| `prefetch_packet_first_deref` | 1080 | 592 | 1080 | 592 |

此外，在 `data/treatment-prefetch-result/` 中搜索 `bpf_x86_prefetcht0` / `prefetcht0` 没有命中。

因此，本次 treatment 没有实际插入 x86 prefetch kinsn。

### Performance numbers

这些数字只记录 raw run 的现象，不能解释为 prefetch 策略收益。

| metric | value |
|---|---:|
| benchmarks | 19 |
| geomean treatment/control `exec_ns` | `0.994572` |
| apparent geomean speedup | `0.54%` |
| wins / ties / losses by 2% threshold | `6 / 5 / 8` |
| best apparent case | `prefetch_map_line_dedup`, ratio `0.728955` |
| worst apparent case | `prefetch_indirect_two_stage`, ratio `1.326851` |

因为 code size 没有变化，上表只能说明该实验设置下 AWS/micro measurement 有明显噪声或 run-to-run
差异；不能说明 `PREFETCHT0` 有收益或回归。

## AWS 费用

价格来源：

- `data/aws-pricing-t3-small.json`：AWS Pricing API，`t3.small` Linux shared on-demand，
  `us-east-1`，`$0.0208/hour`。
- `data/aws-pricing-ebs-gp3.json`：AWS Pricing API，gp3 storage，`us-east-1`，
  `$0.08/GB-month`。

估算使用 32 GiB root volume、730 小时/月。费用不包含 data transfer、税、free tier、credits、
Savings Plans、Reserved Instances 或账户级折扣。

| run | instance | wall time | compute | EBS | total |
|---|---|---:|---:|---:|---:|
| smoke | `i-09f4abf4ebf04be36` | 325.5s | `$0.001881` | `$0.000317` | `$0.002198` |
| control | `i-013f1b9fc5e253fc5` | 462.7s | `$0.002673` | `$0.000451` | `$0.003124` |
| treatment | `i-0527e8fc68bbcb708` | 448.2s | `$0.002590` | `$0.000437` | `$0.003026` |
| total | - | - | - | - | `$0.008348` |

实例状态：`data/aws-active-after.json` 显示 active x86 benchmark instances 数量为 0。

## 问题和处理

问题：原计划把 `BPFREJIT_BENCH_PASSES=prefetch` 当作 micro kernel runtime treatment。但结果显示
micro runner 没有实际应用这个 pass。

证据：

- 19 个 case 的 xlated/native code size 完全一致。
- treatment result 中没有 `bpf_x86_prefetcht0` / `prefetcht0` evidence。
- 本地代码搜索显示 `BPFREJIT_BENCH_PASSES` 主要由 Dynamic ReJIT/app runner 路径使用；micro suite
  当前只加载 kinsn modules，没有把 `bpfopt` pass 应用到 micro BPF object。

处理：

- 保留本次 raw data，因为它说明当前 x86 micro attribution command 无效。
- 不把 `exec_ns` ratio 写成 prefetch performance result。
- 下一步先补 micro pass application 或改用 app/corpus ReJIT path。

## 后续

优先级：

1. 给 micro kernel runtime 增加明确的 Kinsn pass treatment 路径：control object 和 treatment object
   必须在 load 前可对比，并保存 pass report、xlated dump、native JIT dump。
2. 用这个路径重新跑 x86 current-policy prefetch micro attribution，并确认 treatment 出现
   `bpf_x86_prefetcht0` / native `prefetcht0`。
3. 再做 x86/ARM64 同构对比。没有 codegen evidence 的 micro result 不进入策略判断。

## 收尾一致性复查

已回看：

- 当前实验 smoke/control/treatment raw result。
- 当前 prefetch task 文档：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`。
- 相关前序 prefetch experiments：
  - `2026-05-31-prefetch-research-micro-attribution`
  - `2026-05-31-prefetch-candidate-filtering-micro-attribution`
  - `2026-06-01-prefetch-indirect-timeliness-micro-attribution`
  - `2026-06-01-prefetch-map-large-working-set-attribution`
  - `2026-06-01-prefetch-map-raw-loader-fix`

发现：

- 文档里把 x86 current-policy micro attribution 写成可直接使用 `BPFREJIT_BENCH_PASSES=prefetch`
  执行。这个前提被本实验推翻。
- 本实验没有改代码，因此没有代码冗余需要删除。

处理：

- 更新 prefetch task plan，把本实验记录为 micro pass wiring blocker。
- 没有重跑实验，因为重跑同一 command 只会得到相同的无效 attribution；下一次有效实验需要先改
  micro pass application path。

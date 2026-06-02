# 2026-05-31 prefetch-candidate-filtering-micro-attribution

## 结论

本实验完成，状态是 `completed_with_weak_positive_case`。

实验目标是判断：在 distance sweep 没有稳定收益之后，按 memory access pattern 拆分的
candidate-filtering micro 是否能找出 `PRFM` 值得插入的场景。

结论：

- correctness：通过。正式 5 个 candidate-filtering micro 在 AWS ARM64 kernel runtime 下
  control/treatment 全部通过 expected result。
- codegen：通过。control JIT dump 中 `prfm` 数量为 0；treatment 中每个 case 都出现
  2 或 3 条 `prfm`。
- performance：有弱 positive signal，但不足以默认启用。3 轮 independent AWS pair 的总体
  `exec_ns` geomean treatment/control 是 `0.969487107`，即 treatment 约快 `3.05%`；
  但 `prog_run_wall_ns` geomean 是 `1.01776946`，即整轮 wall time 约慢 `1.78%`。
- stability：只有 `prefetch_packet_first_deref` 在 3 轮里稳定变快，median ratio 是
  `0.998017839`，幅度只有约 `0.20%`。其余 case 都是 mixed。
- PMU：`cycles` geomean treatment/control 是 `1.00064527`，基本持平；本 AWS 环境仍缺少
  instructions/cache-miss/cache-reference perf events，因此不能解释 cache miss 变化。

因此，当前结论不是“prefetch 可以默认启用”，而是：

```text
PRFM path 正确。
naive prefetch=force 能在 packet-first-deref 上出现很弱且稳定的 kernel timing win。
这个 win 太小，且 wall-time/PMU 不支持强结论。
下一步应该做 selector v2，而不是默认启用当前 PRFM policy。
```

## 实验问题

本实验回答 Kinsn prefetch task 的 RQ3：

> 哪些 memory access pattern 可能从 ARM64 `PRFM PLDL1KEEP` 受益？

本实验只比较 same-LLC control/treatment：

- control：同一个 custom `llc`，`-bpf-kinsn-mode=all=disable`，不产生 `PRFM`。
- treatment：同一个 custom `llc`，先 `all=disable`，再 `prefetch=force`，只强制启用 prefetch
  family。

它不回答真实程序迁移性，也不证明默认 policy 可用。

## Benchmark

新增 / 正式采用的 candidate-filtering micro 在：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

输入由：

```text
/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py
generate_prefetch_research
```

生成，大小为 1400 bytes，低于常见 MTU，避免 XDP staged packet 过大。

正式 benchmark：

| benchmark | 目的 | 预期性质 |
|---|---|---|
| `prefetch_hot_l1_load` | 反复读取同一个 packet payload offset。 | 负例；数据应很快变 hot。 |
| `prefetch_sequential_scan` | 顺序扫描连续 8-byte words。 | 负例或弱例；硬件 prefetcher 可能已经覆盖。 |
| `prefetch_large_stride_scan` | 64-byte stride 跨 cacheline 扫描，并保留独立 work。 | 候选正例；软件 prefetch 可能补足硬件识别不足。 |
| `prefetch_permuted_index_scan` | 按固定 permutation 访问 64 个 slot。 | irregular 但 verifier-safe 的非顺序访问。 |
| `prefetch_packet_first_deref` | 先从 packet 中读 index，再 deref packet 另一块区域，并在 deref 前放独立 work。 | 对齐当前 pass 的 packet first deref 候选。 |

尝试但没有进入正式结果的 benchmark：

| attempt | 结果 | 原因 |
|---|---|---|
| `prefetch_pointer_chase` | verifier reject | 下一轮 packet offset 依赖上一轮 packet load，verifier 不能证明 8-byte packet range。 |
| `prefetch_dependent_index_chain` | verifier reject | loop-carried scalar cursor 仍导致 verifier 不接受 variable packet offset range。 |
| `prefetch_hashed_index_scan` | verifier reject | `data[key] + index * 17` 形成过宽 var_off，verifier 不能接受后续 packet pointer range。 |

这些失败说明：如果要做真正 pointer chasing micro，不能直接用 staged XDP packet variable offset；
需要改成 map-backed memory、bounded array map，或专门设计 verifier-friendly access pattern。

## 命令

所有 benchmark 都通过 AWS wrapper / Makefile 路径运行，没有直接调用底层 runner。

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
BENCHES='prefetch_hot_l1_load,prefetch_sequential_scan,prefetch_large_stride_scan,prefetch_permuted_index_scan,prefetch_packet_first_deref'
LLC='/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc'

./aws-config/run.sh arm64 micro \
  RUN_TOKEN=<token> \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='<flags>'
```

control flags：

```text
-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
```

treatment flags：

```text
-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force
```

正式 successful pairs：

| pair | control token | treatment token |
|---|---|---|
| r1 | `prefetch-candidate-control-fix4` | `prefetch-candidate-treatment-r1` |
| r2 | `prefetch-candidate-control-r2` | `prefetch-candidate-treatment-r2` |
| r3 | `prefetch-candidate-control-r3` | `prefetch-candidate-treatment-r3` |

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- kernel：`7.0.0-rc2+`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`

## 文件改动

Benchmark / input / manifest：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`

文档 / 实验记录：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/analysis/*`

## 问题和处理

本实验有 4 次失败尝试，均保留 raw result：

| attempt | status | 处理 |
|---|---|---|
| `control-r1` | `prefetch_pointer_chase` verifier reject | 保留失败；说明 packet-based true pointer chase 不适合这个 micro 形态。 |
| `control-fix1` | loop-carried packet-derived cursor verifier reject | 保留失败；不能用上一轮 packet load 更新下一轮 packet offset。 |
| `control-fix2` | loop-carried scalar cursor verifier reject | 保留失败；verifier 仍不能证明后续 packet range。 |
| `control-fix3` | hashed packet index verifier reject | 保留失败；`var_off` 太宽。 |

最终采用 `prefetch_permuted_index_scan` 作为 verifier-safe irregular access case。它不是 pointer chasing，
报告和配置不把它称为 pointer chasing。

## 结果

### Overall Geomean

| metric | treatment/control | 解释 |
|---|---:|---|
| `exec_ns` all case-runs | `0.969487107` | kernel timing 上 treatment 约快 `3.05%`。 |
| `prog_run_wall_ns` all case-runs | `1.01776946` | 整轮 wall time treatment 约慢 `1.78%`。 |
| `cycles` all case-runs | `1.00064527` | cycles 基本持平。 |

### Per-Run Geomean

| run | `exec_ns` treatment/control | `prog_run_wall_ns` treatment/control |
|---|---:|---:|
| r1 | `0.938848822` | `0.958124149` |
| r2 | `0.939360549` | `1.02170687` |
| r3 | `1.03323267` | `1.07696141` |

### Case Stability

| benchmark | ratios by run | median ratio | classification |
|---|---|---:|---|
| `prefetch_hot_l1_load` | `0.789473684,0.862559242,1.07692308` | `0.862559242` | mixed |
| `prefetch_sequential_scan` | `0.922705314,0.85077951,1.09186352` | `0.922705314` | mixed |
| `prefetch_large_stride_scan` | `0.999227501,1.00347759,0.999613601` | `0.999613601` | mixed |
| `prefetch_permuted_index_scan` | `1.00384615,0.996183206,1.00384615` | `1.00384615` | mixed |
| `prefetch_packet_first_deref` | `0.99826561,0.997031173,0.998017839` | `0.998017839` | stable_win |

Takeaway：唯一稳定 win 是 `packet_first_deref`，但幅度只有约 `0.2%`。这个结果更适合指导
selector v2 的候选优先级，不足以证明当前 `prefetch=force` 可以默认启用。

### Codegen

| benchmark | control `prfm` | treatment `prfm` | native code size delta |
|---|---:|---:|---:|
| `prefetch_hot_l1_load` | 0 | 2 | +8 bytes |
| `prefetch_sequential_scan` | 0 | 3 | +8 bytes |
| `prefetch_large_stride_scan` | 0 | 2 | +8 bytes |
| `prefetch_permuted_index_scan` | 0 | 3 | +16 bytes |
| `prefetch_packet_first_deref` | 0 | 2 | +8 bytes |

Treatment 确实触发了 ARM64 `PRFM` kinsn path；负例/混合结果不是因为 codegen 没生效。

## 数据文件

Raw result copies：

- `data/control-r1-failed-pointer-chase-result`
- `data/control-fix1-failed-dependent-chain-result`
- `data/control-fix2-failed-dependent-chain-result`
- `data/control-fix3-failed-hashed-index-result`
- `data/control-r1-result`
- `data/treatment-r1-result`
- `data/control-r2-result`
- `data/treatment-r2-result`
- `data/control-r3-result`
- `data/treatment-r3-result`

Analysis：

- `analysis/control-vs-treatment-all-runs.tsv`
- `analysis/case-stability.tsv`
- `analysis/summary-all-runs.tsv`
- `analysis/aws-cost-estimate.tsv`

Run contract：

- `data/run-contract.json`

Local smoke logs：

- `data/local-pycompile.*`
- `data/local-make-bpf.*`
- `data/local-make-native.*`

## AWS 时间和费用

全部 AWS instance 均已 terminated；当前没有 pending/running/stopping/stopped/shutting-down
ARM64 benchmark instance。

价格假设：

- EC2：`t4g.small` Linux on-demand in US East (N. Virginia)，`$0.0168/hour`。
- EBS：`gp3`，`$0.08/GB-month`。
- root volume：32 GB。
- EBS 按 wall time 线性折算，1 month = 730 hours。

合计估算：

```text
wall time: 4004 seconds
compute:   $0.018685333
EBS:       $0.003900396
total:     $0.022585729
```

前两个 failed attempts 的 EC2 describe 记录已不可见，费用表中用本地 log wall time 做 upper-bound
估算；其余 run 来自 EC2 describe。

逐实例明细见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/analysis/aws-cost-estimate.tsv
```

## 后续

下一步不应该继续强制全部 load prefetch，也不应该默认启用当前 `prefetch=force`。

建议做 selector v2：

1. 只保留类似 `packet_first_deref` 的 candidate 作为第一优先级。
2. 对 hot L1 / sequential / permuted / no-distance case 加 skip reason。
3. 在 pass summary 中输出 `candidate/applied/skipped/reason`。
4. 重新跑同一组 candidate-filtering micro，要求：
   - `packet_first_deref` 保持或扩大收益；
   - hot/sequential/permuted 不再插 PRFM；
   - treatment native code size 不再在负例上增加。

## 收尾一致性复查

已检查：

- 当前实验目录下所有失败尝试和正式 successful pairs。
- 前一轮 distance sweep report：
  `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`。
- prefetch task plan：
  `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`。

发现和处理：

- true pointer-chasing / dependent access 不能直接作为 staged XDP packet micro。已在本 report 记录失败原因，
  并把正式 benchmark 改名为 `prefetch_permuted_index_scan`，避免误导。
- 没有修改 default prefetch policy；当前结论仍是 forced-only / research-only。
- 本实验新增/修改的是 benchmark 和文档，不涉及 kernel kfunc ABI 或 LLVM backend selector。

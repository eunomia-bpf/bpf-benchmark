# 2026-06-01 prefetch-indirect-timeliness-micro-attribution

## 结论

本实验完成，状态是 `completed_no_stable_positive_strategy`。

实验目标是根据 prefetch literature review 继续尝试更有希望的 micro pattern：

- two-stage indirect access；
- same-cacheline 多 load，用来观察 cacheline dedup 需求；
- bounds-check 后的 packet variable offset；
- 覆盖更多 packet cacheline 的 ring scan。

结论：

- correctness：通过。修复后的 4 个正式 benchmark 在 AWS ARM64 kernel runtime 下
  control/treatment 全部通过 expected result。
- codegen：通过。control JIT dump 中 `prfm` 数量为 0；treatment 每个 benchmark 出现
  2 或 3 条 `prfm pldl1keep`，native code size 均增加 8 bytes。
- performance：没有稳定正收益。3 轮 independent AWS pair 的总体 `exec_ns`
  geomean treatment/control 是 `1.00367168`，即 treatment 约慢 `0.37%`。
- stability：`prefetch_indirect_two_stage` 在 3 轮中稳定变慢，median ratio `1.00228462`。
  其余 3 个 case 都是 mixed。
- PMU：`cycles` geomean treatment/control 是 `0.999782772`，基本持平。当前 AWS 环境仍缺少
  instructions/cache-miss/cache-reference perf events，因此不能证明 cache miss 有改善。

因此，本轮没有找到新的有效 prefetch 策略。当前判断仍然是：

```text
PRFM kfunc/JIT path 正确。
当前 prefetch=force policy 不是稳定 performance win。
XDP staged packet micro 可以暴露 verifier/correctness/codegen 和小 working-set overhead，
但不足以证明真实 cold-miss prefetch 策略有效。
```

## 实验问题

本实验回答 Kinsn prefetch task 的两个问题：

1. literature review 里更值得尝试的 indirect / timeliness / cacheline pattern，在当前 Kinsn
   `prefetch=force` selector 下是否能带来稳定收益？
2. 现有 XDP staged packet micro 是否足够测出 prefetch 策略收益？

对第一个问题，答案是否定的：4 个新增 pattern 中没有稳定 positive case。

对第二个问题，答案是“只能测一部分”：它能测 verifier-safe pattern、PRFM codegen 和额外指令成本；
但由于输入只有 1400 bytes，且 `INNER_REPEAT=100000` 会反复访问同一 packet buffer，它不能充分制造
真实 cold working set，也不能替代 map-backed large working-set 或真实 corpus attribution。

## Benchmark

新增 benchmark 在：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

输入由：

```text
/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py
generate_prefetch_research
```

生成。输入大小仍为 1400 bytes。

| benchmark | 目的 | 结果定位 |
|---|---|---|
| `prefetch_indirect_two_stage` | packet 中先读 index，再读第二级 index，最后访问 target payload。 | 模拟 two-stage indirect；最终稳定变慢。 |
| `prefetch_cacheline_dedup_scan` | 每轮读取同一 cacheline 的 4 个 8-byte word。 | 检查同 cacheline 多 load 下 PRFM 是否有用；结果 mixed。 |
| `prefetch_packet_offset_guarded` | 从 packet 读出 index，显式 bounds check 后访问 variable offset。 | 检查 verifier-safe variable offset；结果 mixed。 |
| `prefetch_full_packet_ring_scan` | 在 1400-byte packet 内按 ring pattern 访问更多 slot。 | 扩大 packet 内访问面，但仍不是 cold working set；结果 mixed。 |

失败尝试：

| attempt | 结果 | 原因 |
|---|---|---|
| `prefetch-indirect-control-r1` | verifier reject | `prefetch_indirect_two_stage` 初版在 range check 后重新构造 `data + mid_offset`，verifier 丢失 range proof。 |

修复：

- 将中间 load 改为直接 dereference 已经 range-checked 的 `mid_ptr`。
- 这个问题来自本实验新增 micro 的 verifier 写法，不是已有 Kinsn PRFM ABI 或 JIT 实现引入的 bug。

## 命令

所有 benchmark 都通过 AWS wrapper / Makefile 路径运行，没有直接调用底层 runner。

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
BENCHES='prefetch_indirect_two_stage,prefetch_cacheline_dedup_scan,prefetch_packet_offset_guarded,prefetch_full_packet_ring_scan'
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

成功 pairs：

| pair | control token | treatment token |
|---|---|---|
| r1 | `prefetch-indirect-control-fix1` | `prefetch-indirect-treatment-r1` |
| r2 | `prefetch-indirect-control-r2` | `prefetch-indirect-treatment-r2` |
| r3 | `prefetch-indirect-control-r3` | `prefetch-indirect-treatment-r3` |

本地 smoke：

```bash
python3 -m py_compile code/runner/libs/input_generators.py
make -C code/micro/programs OUTPUT_DIR=/tmp/bpf-opt-prefetch-indirect-smoke \
  /tmp/bpf-opt-prefetch-indirect-smoke/prefetch_research.bpf.o
make -C code/micro/programs OUTPUT_DIR=/tmp/bpf-opt-prefetch-indirect-smoke \
  /tmp/bpf-opt-prefetch-indirect-smoke/prefetch_research.native.so
```

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
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`

文档 / 实验记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/analysis/*`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`

## 数据文件

Raw result copies：

- `data/failed-control-r1-result`
- `data/control-r1-result`
- `data/treatment-r1-result`
- `data/control-r2-result`
- `data/treatment-r2-result`
- `data/control-r3-result`
- `data/treatment-r3-result`

Logs：

- `data/local-pycompile*.log`
- `data/local-make-bpf*.log`
- `data/local-make-native*.log`
- `data/aws-check*.log`
- `data/aws-control-r1*.log`
- `data/aws-control-fix1*.log`
- `data/aws-prefetch-indirect-*.log`
- `data/aws-describe-instances.json`
- `data/aws-active-after.json`

Analysis：

- `analysis/control-vs-treatment-all-runs.tsv`
- `analysis/case-stability.tsv`
- `analysis/summary-all-runs.tsv`
- `analysis/jit-prfm-summary.tsv`
- `analysis/aws-cost-estimate.tsv`

## 结果

### Overall Geomean

| metric | treatment/control | 解释 |
|---|---:|---|
| `exec_ns` all case-runs | `1.00367168` | treatment 约慢 `0.37%`。 |
| `prog_run_wall_ns` all case-runs | `0.993156588` | wall time treatment 约快 `0.68%`，但和 `exec_ns` / cycles 不一致。 |
| `cycles` all case-runs | `0.999782772` | cycles 基本持平。 |

### Case Stability

| benchmark | ratios by run | median ratio | classification |
|---|---|---:|---|
| `prefetch_cacheline_dedup_scan` | `0.999138921,0.988136975,1.00897799` | `0.999138921` | mixed |
| `prefetch_full_packet_ring_scan` | `0.999069552,0.99944097,1.01386921` | `0.99944097` | mixed |
| `prefetch_indirect_two_stage` | `1.00228462,1.00205621,1.00411727` | `1.00228462` | stable_loss |
| `prefetch_packet_offset_guarded` | `1.03075324,0.995760847,1.00106709` | `1.00106709` | mixed |

### Codegen

| benchmark | control `prfm` | treatment `prfm` | native code size delta |
|---|---:|---:|---:|
| `prefetch_cacheline_dedup_scan` | 0 | 2 | +8 bytes |
| `prefetch_full_packet_ring_scan` | 0 | 2 | +8 bytes |
| `prefetch_indirect_two_stage` | 0 | 3 | +8 bytes |
| `prefetch_packet_offset_guarded` | 0 | 2 | +8 bytes |

Treatment 确实触发了 ARM64 `PRFM` kinsn path；没有正收益不是因为 codegen 没生效。

## AWS 时间和费用

实例均已进入 `terminated`，`data/aws-active-after.json` 显示没有 pending/running/stopping/stopped
的 `bpf-benchmark-arm64` instance。

费用估算见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/analysis/aws-cost-estimate.tsv
```

估算依据：

- compute：`t4g.small` Linux on-demand `us-east-1`，按 `$0.0168/hour` 估算。
- EBS：root volume 32 GB，按 gp3 `$0.08/GB-month`、730 hour/month 估算。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

合计：

| wall seconds | compute USD | EBS USD | total USD |
|---:|---:|---:|---:|
| 2635 | 0.012296667 | 0.002566819 | 0.014863486 |

## 后续

不要继续扩大当前 `prefetch=force` 的默认范围。下一步更合理的是：

1. 如果目标是让当前 selector 更安全：实现 selector v2，只保留有 evidence 的 packet-first-deref
   弱 positive，并对 hot/sequential/no-distance/no-dominating-check case 记录 skip reason。
2. 如果目标是继续找真正有效的 prefetch 策略：新增 map-backed large working-set 或 corpus-level
   prefetch experiment。当前 1400-byte XDP staged packet micro 不能充分测 cold miss。

## 收尾一致性复查

已回看：

- 当前实验失败尝试：`failed-control-r1-result`。
- 前序 prefetch 实验：
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
- 相关文档：
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md`

发现和处理：

- `prefetch_indirect_two_stage` 初版 verifier reject。已修复为直接 dereference checked pointer，
  并通过 AWS control/treatment。
- `docs/projects/kinsn/tasks/prefetch/plan.md` 需要记录本实验的新结论：新增 indirect/timeliness
  micro 没有稳定正收益，且 XDP staged packet micro 不能充分测 cold working set。已更新。
- 未发现需要删除的 prefetch selector 临时代码；本实验没有改 selector。

是否重跑：

- 因为修复了 `prefetch_indirect_two_stage` 的 C micro 写法，已重新运行本地 smoke 和 AWS control/treatment。
- 文档更新只同步实验结论，不改变代码行为，因此文档更新后不需要额外 rerun。

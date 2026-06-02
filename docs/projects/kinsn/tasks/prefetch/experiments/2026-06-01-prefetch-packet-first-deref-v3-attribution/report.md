# 2026-06-01 prefetch-packet-first-deref-v3-attribution

## 结论

本实验完成，状态是 `completed_with_mixed_result`。

实验回答的问题是：Kinsn prefetch selector v3 保留的 `packet first-deref` 策略，在同一套
LLC、同一 runner、同一 kernel micro 条件下，是否能在 x86 和 ARM64 上给出稳定收益。

结论：

- correctness 通过：120 个 raw samples 全部得到 expected result。
- policy/codegen 通过：treatment 每个 sample 都 `sites_applied=1`，control 没有 prefetch；
  x86 codegen 出现 `prefetcht0 [rN]`，ARM64 codegen 出现 `prfm pldl1keep, [xN]`。
- performance 不稳定：两个 benchmark、两个架构都不是 stable win。ARM64 基本接近 no-op；
  x86 有局部加速，但三轮方向 mixed，不能作为 default-enable 依据。

因此，selector v3 的安全过滤和 codegen path 可以继续保留，但 `packet first-deref` prefetch
仍只能算 forced / research policy，不能作为默认启用策略。

## 实验问题

Prefetch 和替换型 kinsn 不同。替换型 kinsn 会把语义等价的 BPF sequence 替换成更短的
native 指令；prefetch 是插入型优化：

```text
control:
  load *(ptr)

treatment:
  prefetch ptr
  load *(ptr)
```

原始 load 不删除。prefetch 只有在 cache miss latency 能被提前隐藏、且额外 hint 不造成
frontend/cache/bandwidth 负担时才可能快。

本实验只测试 selector v3 当前保留的两个 packet first-deref micro case：

| case | 目的 |
|---|---|
| `prefetch_single_first_deref` | synthetic control；验证最小 first-deref admission 和 site budget。 |
| `prefetch_packet_first_deref` | packet-shaped case；验证 packet load 产生 index，再 deref packet 另一处位置的形态。 |

control / treatment 使用同一份 code tree 和同一个 `llc` / kernel / container。唯一差异是：

| condition | pass |
|---|---|
| control | `BPFREJIT_BENCH_PASSES=noop` |
| treatment | `BPFREJIT_BENCH_PASSES=prefetch` |

## 命令

执行目录：

```text
/home/ruoji/github/bpf-opt
```

主实验命令：

```bash
EXP=/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution
BENCHES='prefetch_single_first_deref prefetch_packet_first_deref'
COMMON=("BENCH=${BENCHES}" RUNTIMES=kernel SAMPLES=5 WARMUPS=1 INNER_REPEAT=10000 PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw)

for arch in x86 arm64; do
  for r in 1 2 3; do
    for condition in control treatment; do
      if [[ "$condition" == control ]]; then pass=noop; else pass=prefetch; fi
      token="pfd-v3-${arch}-r${r}-${condition}"
      log="${EXP}/data/local-logs/${token}.log"
      BPFREJIT_BENCH_PASSES="$pass" RUN_TOKEN="$token" \
        /home/ruoji/github/bpf-opt/aws-config/run.sh "$arch" micro "${COMMON[@]}" \
        2>&1 | tee -a "$log"
    done
  done
done
```

清理命令：

```bash
RUN_TOKEN=cleanup-x86 /home/ruoji/github/bpf-opt/aws-config/run.sh x86 terminate
RUN_TOKEN=cleanup-arm64 /home/ruoji/github/bpf-opt/aws-config/run.sh arm64 terminate
```

说明：benchmark 通过 `aws-config/run.sh` wrapper 进入 `make micro` 路径执行，没有直接调用
底层 Python runner。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- code repo HEAD：`d9f007575bda699f0ddb154abd37cf80bcd1b120`
- code repo 状态：dirty；包含本 task 之前已经引入的 prefetch selector / runner / micro 改动。
- AWS region：`us-east-1`
- remote user：`ec2-user`
- kernel release：`7.0.0-rc2+`
- x86 instance：`t3.small`
- ARM64 instance：`t4g.small`
- x86 container：`bpf-benchmark/runner-runtime:x86_64`
- ARM64 container：`bpf-benchmark/runner-runtime:arm64`
- root volume：32 GiB gp3

## 文件改动

本实验运行本身没有修改 code repo 的实现文件。实验完成后新增 / 更新：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/data/result-map.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/analysis/*.tsv`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

## 数据文件

Raw result 副本：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/data/aws-results/
```

本地运行日志：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/data/local-logs/
```

分析文件：

| file | 内容 |
|---|---|
| `data/result-map.tsv` | token 到原始 result dir / copied dir 的映射。 |
| `data/run-contract.json` | 实验参数、arch、container、price source。 |
| `analysis/raw-samples.tsv` | 120 个 raw samples 的 measurement。 |
| `analysis/per-run-summary.tsv` | 每轮 control/treatment median 和 ratio。 |
| `analysis/overall-summary.tsv` | 跨 3 轮 geomean ratio / speedup / win-loss。 |
| `analysis/pass-and-codegen.tsv` | `sites_applied`、`insn_delta`、native prefetch mnemonic 证据。 |
| `analysis/aws-instance-time.tsv` | instance id、start/done、本地 wall seconds。 |
| `analysis/aws-cost-estimate.tsv` | AWS compute / EBS 费用估算。 |
| `data/aws-active-x86-after-cleanup.json` | cleanup 后 x86 active instance 查询结果。 |
| `data/aws-active-arm64-after-cleanup.json` | cleanup 后 ARM64 active instance 查询结果。 |

## 问题和处理

- 预运行 cleanup 曾有一次未带 `RUN_TOKEN` 的命令失败，原因是 run-contract 要求 token。
  随后用 `RUN_TOKEN=cleanup-x86` / `RUN_TOKEN=cleanup-arm64` 重新清理成功。该问题发生在
  实验数据生成前，不影响 measurement。
- `rg` 本地不可用；后续检索使用 `find` / `grep` / `jq`。
- ARM64 result 没有 `wall_exec_ns` / `exec_cycles`，`timing_source_wall=unavailable`。
  因此 ARM64 performance 只使用 `exec_ns`。
- x86 的 `exec_ns`、`wall_exec_ns`、`exec_cycles` 都可用，但三者方向不完全一致；
  x86 结论按 mixed 处理。

## 结果

Correctness：

| total samples | failed samples |
|---:|---:|
| 120 | 0 |

Codegen / pass evidence：

| condition | report count | `sites_applied` | native prefetch mnemonic |
|---|---:|---|---|
| control | 0 per case | none | 0 |
| treatment | 5 per case per run | `1,1,1,1,1` | 1 in each code_compare |

x86 treatment example：

```text
prefetcht0 BYTE PTR [rdx]
movzx     rdi,BYTE PTR [rdx+0x300]
```

ARM64 treatment example：

```text
prfm pldl1keep, [x2]
ldrb w0, [x2, #768]
```

Performance summary。`treatment/control < 1` 表示 treatment 更快；`speedup > 1` 表示加速。

| arch | case | metric | rounds | geomean treatment/control | geomean speedup | direction |
|---|---|---|---:|---:|---:|---|
| ARM64 | `prefetch_packet_first_deref` | `exec_ns` | 3 | 0.998441 | 1.00156 | mixed |
| ARM64 | `prefetch_single_first_deref` | `exec_ns` | 3 | 1.00502 | 0.995005 | mixed |
| x86 | `prefetch_packet_first_deref` | `exec_ns` | 3 | 0.925581 | 1.0804 | mixed |
| x86 | `prefetch_packet_first_deref` | `wall_exec_ns` | 3 | 0.975545 | 1.02507 | mixed |
| x86 | `prefetch_packet_first_deref` | `exec_cycles` | 3 | 0.975625 | 1.02498 | mixed |
| x86 | `prefetch_single_first_deref` | `exec_ns` | 3 | 1.03979 | 0.961737 | mixed |
| x86 | `prefetch_single_first_deref` | `wall_exec_ns` | 3 | 0.979013 | 1.02144 | mixed |
| x86 | `prefetch_single_first_deref` | `exec_cycles` | 3 | 0.979105 | 1.02134 | mixed |

Interpretation：

- ARM64 packet first-deref 的 geomean speedup 约 1.00156，基本等于 no-op；三轮有 2 win / 1 loss。
- x86 packet first-deref 有局部收益，但三轮 mixed，且 `exec_ns` 与 wall/cycles 差异较大。
- single first-deref 是更小的 synthetic control，结果也 mixed，不支持“只要 first-deref 就快”。
- 当前策略能够稳定插入正确 native hint，但没有证明稳定 performance win。

## AWS 时间和费用

价格来源：AWS Pricing API `get-products`，查询时间为 2026-06-01 local / 2026-06-02 UTC。

价格：

- `t3.small` Linux On-Demand, US East (N. Virginia)：`$0.0208/hour`
- `t4g.small` Linux On-Demand, US East (N. Virginia)：`$0.0168/hour`
- gp3 EBS, US East (N. Virginia)：`$0.08/GB-month`

费用估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| token | instance | seconds | estimated USD |
|---|---|---:|---:|
| `pfd-v3-x86-r1-control` | `i-07e05c78f5265ec6b` | 422 | 0.002855 |
| `pfd-v3-x86-r1-treatment` | `i-02a3337b10bd4dc26` | 406 | 0.002747 |
| `pfd-v3-x86-r2-control` | `i-05d4b84bcda1d3b0b` | 385 | 0.002605 |
| `pfd-v3-x86-r2-treatment` | `i-04bdc19bd79e8620e` | 421 | 0.002848 |
| `pfd-v3-x86-r3-control` | `i-00f6f62ead0e189a4` | 408 | 0.002760 |
| `pfd-v3-x86-r3-treatment` | `i-00f099a3904007769` | 413 | 0.002794 |
| `pfd-v3-arm64-r1-control` | `i-054ef73c190616bda` | 421 | 0.002380 |
| `pfd-v3-arm64-r1-treatment` | `i-068e867f1ed364e80` | 416 | 0.002352 |
| `pfd-v3-arm64-r2-control` | `i-0ac02ebd6279f3058` | 541 | 0.003059 |
| `pfd-v3-arm64-r2-treatment` | `i-0fce42c882e1439d3` | 553 | 0.003127 |
| `pfd-v3-arm64-r3-control` | `i-0ae985ff7c6bafdf7` | 488 | 0.002759 |
| `pfd-v3-arm64-r3-treatment` | `i-0c9e49cadc4e6c36e` | 488 | 0.002759 |

合计估算：

| compute USD | EBS USD | total USD |
|---:|---:|---:|
| 0.027750 | 0.005296 | 0.033046 |

实例状态：每个 run 结束时 wrapper 都返回 `shutting-down`。实验后已执行 x86 / ARM64 terminate cleanup；
cleanup 后查询 `bpf-benchmark-x86` 和 `bpf-benchmark-arm64` 均返回空列表。

## 后续

下一步不应该直接 default-enable prefetch。建议顺序：

1. 暂停 structural-only packet first-deref 作为默认策略。
2. 实现 profile / PMU gate，优先验证 map value / large working set / cold miss site。
3. 对 packet first-deref 如果继续研究，需要新增更接近真实 workload 的 real-inspired case，
   并提供 codegen + PMU evidence，不能只看 synthetic-control median。
4. 若 x86 仍显示局部收益，应单独做 x86 timing-source cleanup，避免 `exec_ns` 和 wall/cycles
   指标给出不同结论。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-map-page-stride-independent-rerun/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

发现和处理：

- selector v3 smoke 只证明 applied / skipped behavior，不证明 performance。已在本 report 中补齐
  same-LLC attribution。
- policy matrix 原先把 P11 写成 “performance attribution 待重跑”。实验完成后更新为 mixed / not default-ready。
- plan 中当前结论同步更新为：selector v3 correctness/codegen 通过，但 packet first-deref performance 不稳定。
- 本实验没有新增实现代码，因此不需要重新跑 correctness smoke。

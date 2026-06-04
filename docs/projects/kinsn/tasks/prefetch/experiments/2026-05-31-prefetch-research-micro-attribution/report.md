# 2026-05-31 prefetch-research-micro-attribution

## 结论

本实验完成，状态是 `completed_with_negative_result`。

实验目标是判断：如果专门构造 prefetch distance sweep micro，当前 ARM64 `PRFM`
kinsn path 是否能在 kernel runtime micro 上稳定跑赢 no-prefetch control。

结论：

- correctness：通过。修复 benchmark 后，7 个 prefetch research micro 在 ARM64 AWS
  kernel runtime 下 control/treatment 全部通过 expected result。
- codegen：通过。treatment JIT dump 中每个 case 都出现 2 条 `prfm`，control 为 0。
- performance：没有稳定收益。3 轮 independent AWS control/treatment pair 的总体
  `exec_ns` geomean treatment/control 是 `1.00492806`，即 treatment 约慢 `0.49%`。
- stability：没有任何 case 在 3 轮中稳定变快；`prefetch_distance_4` 在 3 轮中稳定变慢。
- PMU：`cycles` geomean treatment/control 是 `0.999885166`，基本持平；但本环境缺少
  instructions/cache-miss/cache-reference perf events，因此不能解释 cache miss 变化。

因此，当前结果不支持默认启用 prefetch。`PRFM` 仍应保持 forced-only / research-only。

## 实验问题

本实验回答 Kinsn 项目 prefetch task 的 RQ2/RQ3：

- RQ2：简单 immediate-before-load prefetch 是否有效。
- RQ3：增加独立 work 的 distance sweep 是否能找到稳定 positive distance。

本实验不回答真实程序迁移性；它只在 synthetic micro 上验证 prefetch potential。

## 背景和术语

`PRFM` 是 ARM64 的 prefetch memory hint。当前 Kinsn ARM64 kfunc 是：

```text
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c
bpf_arm64_prfm_pldl1keep
```

LLVM/BPF object 中的 treatment 会插入 `bpf_arm64_prfm_pldl1keep` kfunc call。kernel JIT
最终把它翻译成：

```asm
prfm pldl1keep, [xN]
```

control 和 treatment 的区别：

- control：同一个 custom `llc`，`-bpf-kinsn-mode=all=disable`，不产生 `PRFM`。
- treatment：同一个 custom `llc`，先 `all=disable`，再 `prefetch=force`，只强制启用 prefetch family。

指标解释：

- `exec_ns`：runner 从 kernel timing source 记录的单次程序执行时间，单位 ns。
- `prog_run_wall_ns`：一次 `inner_repeat=100000` kernel test run 的 wall time，单位 ns。
- `cycles`：perf raw counter，覆盖 full repeat scope。
- `treatment/control < 1` 表示 treatment 更快；`> 1` 表示 treatment 更慢。

## Benchmark

新增 benchmark 都在 `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
中标记 `new-2026-05-31`：

| benchmark | 目的 |
|---|---|
| `prefetch_distance_0` | immediate-before-load 负例。 |
| `prefetch_distance_2` | 极短 lookahead。 |
| `prefetch_distance_4` | 短 lookahead。 |
| `prefetch_distance_8` | 对齐当前 `bpfopt` 默认 target distance 的近似 case。 |
| `prefetch_distance_16` | 对齐当前 `bpfopt` max distance 的近似 case。 |
| `prefetch_distance_32` | 更长 lookahead。 |
| `prefetch_indirect_lookup` | 先读 packet payload index，再访问另一区域，模拟 indirect lookup。 |

输入大小是 1400 bytes。这个大小刻意低于常见 MTU，避免 XDP test packet 过大影响实验，并让
verifier 能证明 packet-bound access。

## 命令

所有 benchmark 都通过 AWS wrapper / Makefile 路径运行，没有直接调用底层 runner。

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
BENCHES='prefetch_distance_0,prefetch_distance_2,prefetch_distance_4,prefetch_distance_8,prefetch_distance_16,prefetch_distance_32,prefetch_indirect_lookup'
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

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- kernel：`7.0.0-rc2+`
- host platform：`Linux-7.0.0-rc2+-aarch64-with-glibc2.39`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`

## 文件改动

Benchmark / input / manifest：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`

文档 / 实验记录：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/analysis/*`

## 问题和处理

第一次 AWS control run 失败，不计入性能结论。失败原因有两个：

1. `prefetch_distance_*` 返回 0，而 expected result 非 0。直接原因是原始 4096-byte payload
   对 XDP staged packet 太激进，runtime path 没有得到有效 result。
2. `prefetch_indirect_lookup` verifier 拒绝 variable packet offset：

```text
invalid access to packet, off=2568 size=1
R2 offset is outside of the packet
```

修复：

- 把 input payload 从 4096 bytes 降到 1400 bytes。
- 把 data window 调整到 packet 内：`DATA_BASE=256`、`DATA_STRIDE=4`、
  `INDIRECT_BASE=768`、`INDIRECT_STRIDE=8`。
- 在 benchmark 内部增加 `data_end` dominated bounds check，让 verifier 能证明目标 load 安全。

修复后重新跑了 control/treatment，并保留初始失败数据。

## 结果

### Run Geomean

| run | geomean treatment/control `exec_ns` | 结论 |
|---|---:|---|
| r1 | `1.00117016` | treatment 约慢 `0.12%` |
| r2 | `1.0357519` | treatment 约慢 `3.58%` |
| r3 | `0.978681268` | treatment 约快 `2.13%` |
| all case-runs | `1.00492806` | treatment 约慢 `0.49%` |

### Case Stability

| benchmark | median treatment/control `exec_ns` | min | max | classification |
|---|---:|---:|---:|---|
| `prefetch_distance_0` | `1.01895735` | `0.917061611` | `1.18087855` | mixed |
| `prefetch_distance_2` | `0.992762364` | `0.879907621` | `1.07894737` | mixed |
| `prefetch_distance_4` | `1.00250836` | `1.00083612` | `1.0083612` | stable_loss |
| `prefetch_distance_8` | `1.0` | `0.99895288` | `1.05141658` | mixed |
| `prefetch_distance_16` | `1.00180018` | `0.997011357` | `1.0024024` | mixed |
| `prefetch_distance_32` | `1.00325945` | `0.998207593` | `1.00506122` | mixed |
| `prefetch_indirect_lookup` | `0.997763864` | `0.997762864` | `1.0` | mixed |

### Codegen

| case | control `prfm` count | treatment `prfm` count | native code size delta |
|---|---:|---:|---:|
| all 7 cases | 0 | 2 | +8 bytes |

Treatment BPF bytecode size 比 control 多 32 bytes，native JIT code size 多 8 bytes。说明每个
program 的 PRFM path 确实生效，但额外 hint 没有形成稳定 runtime win。

## 数据文件

Raw result copies：

- `data/control-r1-initial-result`：初始失败 run。
- `data/control-fix1-result`：修复后 r1 control。
- `data/treatment-r1-result`：r1 treatment。
- `data/control-r2-result`：r2 control。
- `data/treatment-r2-result`：r2 treatment。
- `data/control-r3-result`：r3 control。
- `data/treatment-r3-result`：r3 treatment。

Analysis：

- `analysis/control-vs-treatment-all-runs.tsv`
- `analysis/case-stability.tsv`
- `analysis/summary-all-runs.tsv`
- `analysis/aws-cost-estimate.tsv`

AWS logs：

- `data/aws-control-r1.log` / `.stderr.log` / `.exit`
- `data/aws-control-fix1.log` / `.stderr.log` / `.exit`
- `data/aws-treatment-r1.log` / `.stderr.log` / `.exit`
- `data/aws-control-r2.log` / `.stderr.log` / `.exit`
- `data/aws-treatment-r2.log` / `.stderr.log` / `.exit`
- `data/aws-control-r3.log` / `.stderr.log` / `.exit`
- `data/aws-treatment-r3.log` / `.stderr.log` / `.exit`

## AWS 时间和费用

全部实例均已 terminated；当前没有 pending/running/stopping/stopped/shutting-down AWS instance。

价格来源：

- EC2 pricing API：`t4g.small` Linux on-demand in US East (N. Virginia)，`$0.0168/hour`。
- EC2 pricing API：EBS `gp3` in US East (N. Virginia)，`$0.08/GB-month`。

估算假设：

- root volume：32 GB。
- EBS 按 wall time 线性折算，1 month = 730 hours。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

合计估算：

```text
compute: $0.011685333
EBS:     $0.002439209
total:   $0.014124542
```

逐实例明细见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/analysis/aws-cost-estimate.tsv
```

## 后续

下一步不应该默认启用 PRFM，也不应该继续只调 distance 常数。

建议进入 candidate filtering micro：

1. 增加 hot L1 load / sequential scan / large-stride scan / pointer-chasing / map-value-first-deref
   五类 case。
2. 对每个 case 保存 native JIT dump 和 PRFM site。
3. 如果仍没有稳定 positive case，把 prefetch 作为 negative result 写入 Kinsn 论文故事：
   kfunc/native path 可行，但 naive prefetch policy 不成立。

## 收尾一致性复查

已回看：

- 当前失败 run：`data/control-r1-initial-result`。
- 修复后所有 control/treatment run：r1/r2/r3。
- 相关文档：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`。
- 前序 smoke：`/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-smoke/report.md`。

发现和处理：

- 初始 report 中写着 4096-byte input。当前代码已因 verifier/runtime 修复改为 1400-byte input；
  已在本实验 report 中记录修复原因，并更新 prefetch task plan。
- 未修改 LLVM backend、kernel module 或 prefetch selector policy。
- 未删除旧失败数据；初始失败被保留为 `control-r1-initial-result`，避免掩盖修复过程。

是否重跑：

- 代码修复后已重跑本地 object/native build。
- 已重跑 ARM64 AWS kernel runtime：1 个修复 control run、3 轮 independent control/treatment pair。

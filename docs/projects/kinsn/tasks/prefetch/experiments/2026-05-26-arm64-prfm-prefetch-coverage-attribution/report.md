# 2026-05-26 arm64-prfm-prefetch-coverage-attribution

## 结论

本实验完成，状态是 `completed`。

结论：

- 这不是 micro benchmark，而是 AWS ARM64 corpus targeted run。
- 选择 `katran` 是因为当前 micro runner 没有 ReJIT pass path；`PRFM` 目前由
  `bpfopt --pass prefetch` 插入，而不是 LLVM BPF backend selector 插入。
- `prefetch` pass 在 `katran` 的 `balancer_ingres` XDP program 上命中：
  `sites_matched=44`、`sites_applied=44`、`sites_skipped=0`。
- ReJIT 成功，`bpf_arm64_prfm` module 成功加载，`katran` baseline 和 post-ReJIT workload
  都成功运行，workload error 为 0。
- 单样本 raw performance 不是 win：baseline `1093533pps`，post-ReJIT `1075776pps`；
  baseline BPF runtime `446332751 ns`，post-ReJIT `451012780 ns`。
- 因此，本实验只能证明现有 bpfopt prefetch path 能覆盖 ARM64 PRFM kfunc runtime path；
  不能证明 PRFM 有性能收益，也不能证明 LLVM PRFM selector 应立即实现。

当前 PRFM 状态应更新为：

```text
PRFM: coverage exploration completed via bpfopt prefetch pass; LLVM selector still deferred.
```

## 实验问题

要回答的问题：

1. 现有 `bpfopt --pass prefetch` 是否能在 ARM64 corpus app 上实际插入 PRFM kfunc？
2. runner / module / verifier / ReJIT path 是否能接受 `bpf_arm64_prfm_pldl1keep`？
3. 单样本 targeted workload 是否显示立即性能收益？

这不是完整 PRFM performance evaluation。完整 evaluation 还需要更多 app、更多 samples、
native code evidence 和 same-pass disabled control。

## 总体进度

总体目标：实现 ARM64 LLVM backend。LLVM 仍输出 BPF object，在合适的 BPF
MachineInstr pattern 上 emit `KINSN_SIDECAR + KINSN_CALL bpf_arm64_*`，再由 verifier 和
ARM64 module lower 成 native AArch64 指令。

Family 总清单：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro。 |
| `EXTR` | 2 | development-complete on micro。 |
| `UBFM` | 1 | development-complete on micro。 |
| `LDR` | 4 | partial；`LDR_X`、`LDRH`、`LDR_W` selected-safe subset development-complete on micro；`LDRB` normal selector deferred。 |
| `STR` | 4 | design-complete；direct-store selector deferred，store-widening selector deferred。 |
| `LDP/STP` | 2 | stack-only `STP_X` 和 `LDP_X` development-complete on micro。 |
| `CSEL` | 2 | targeted implementation / selected correctness / attribution / regression 完成；当前不是 performance win。 |
| `CCMP/CMP/CSET` | 5 | development-complete on micro；当前不是 performance win。 |
| `PRFM` | 1 | coverage exploration completed via bpfopt prefetch pass；LLVM selector still deferred。 |
| `MOV` | 1 | not started。 |

单个 family 的完整 gate：

1. 读清楚 ARM64 module ABI 和 kfunc payload。
2. 在 LLVM BPF backend 里实现 target / pseudo / AsmPrinter / selector。
3. 做 object smoke 和 target isolation。
4. 做 AWS runtime correctness。
5. 做 same-LLC performance attribution。
6. 做 combined regression 和文档 / 实验收尾。

当前处于 `PRFM` family 的特殊 pre-implementation gate：因为 `PRFM` 是 hint insertion，
不是已有 BPF op 的等价 replacement，所以先验证 existing pass-level path 的 coverage 和
attribution 方法。这个 gate 已证明 coverage 存在，但没有证明 performance win。

## 命令

配置检查：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/check.sh arm64
```

实际运行命令：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=2
```

底层仍通过 Makefile / AWS wrapper 进入 corpus suite，没有绕过实验框架直接调用 runner。

价格查询命令：

```bash
aws pricing get-products --region us-east-1 --service-code AmazonEC2 \
  --filters Type=TERM_MATCH,Field=instanceType,Value=t4g.small \
            Type=TERM_MATCH,Field=location,Value='US East (N. Virginia)' \
            Type=TERM_MATCH,Field=operatingSystem,Value=Linux \
            Type=TERM_MATCH,Field=tenancy,Value=Shared \
            Type=TERM_MATCH,Field=preInstalledSw,Value=NA \
            Type=TERM_MATCH,Field=capacitystatus,Value=Used

aws pricing get-products --region us-east-1 --service-code AmazonEC2 \
  --filters Type=TERM_MATCH,Field=location,Value='US East (N. Virginia)' \
            Type=TERM_MATCH,Field=volumeType,Value='General Purpose' \
            Type=TERM_MATCH,Field=storageMedia,Value=SSD-backed \
            Type=TERM_MATCH,Field=usagetype,Value=EBS:VolumeUsage.gp3
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- suite：`corpus`
- app：`katran`
- pass：`prefetch`
- platform：AWS ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- root volume：32 GiB
- kernel release：`7.0.0-rc2+`
- result dir：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260526_233600_605194`
- container image：`bpf-benchmark/runner-runtime:arm64`

AWS instance：

| field | value |
|---|---|
| instance id | `i-0f47a6524937689ff` |
| launch time | `2026-05-26T23:29:57Z` |
| terminate observed | `2026-05-26T23:36:39.061587Z` |
| AWS wall time | `402.061587 s` |
| final state | `terminated` |

## 文件改动

本实验没有修改 LLVM、runner、module 或 benchmark framework code。

新增 / 更新实验记录和文档：

- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution/analysis/prefetch-pass-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution/analysis/katran-raw-measurements.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution/analysis/aws-cost-estimate.tsv`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/archive/tmp/arm-llvm-backend/2026-05-27/arm64-llvm-backend/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/families/prfm.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/implementation-plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/guide.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/experiment-matrix.md`

## 数据文件

实验记录目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution
```

保存的数据：

- `data/run-contract.json`
- `data/aws-katran-prefetch.stdout.log`
- `data/aws-katran-prefetch.stderr.log`
- `data/corpus_wcxwchw7_20260526_233559.remote.log`
- `data/setup_verify.log`
- `data/setup_verify.stderr.log`
- `data/aws-active-instances-after-run.json`
- `data/aws-pricing-ec2-t4g-small.json`
- `data/aws-pricing-ebs-gp3.json`
- `data/corpus-result/metadata.json`
- `data/corpus-result/details/result.json`
- `data/corpus-result/details/progress.json`
- `data/corpus-result/details/apps/katran.json`
- `analysis/prefetch-pass-summary.tsv`
- `analysis/katran-raw-measurements.tsv`
- `analysis/aws-cost-estimate.tsv`

原始 result 目录仍保留在：

```text
/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260526_233600_605194
```

## 问题和处理

- 当前 micro runner 没有 ReJIT pass path，不能直接用 micro 覆盖 `bpfopt --pass prefetch`。
  处理：改用 corpus suite 的 `katran` app targeted run。
- `PRFM` proof expansion 是 no-op，因此 runtime correctness 很容易“假通过”。处理：本实验只把
  correctness 作为 sanity，把主要结论限制为 coverage evidence。
- 单样本 performance 有噪声，不能作为 paper-grade 结论。处理：只汇报 raw measurements，不写
  geomean / confidence interval。

## 结果

Run status：

| field | value |
|---|---|
| corpus status | `completed` |
| result status | `ok` |
| app | `katran` |
| runner | `katran` |
| workload | `xdp_pktgen` |
| selected BPF program | `balancer_ingres` |
| baseline status | `ok` |
| ReJIT status | `ok` |
| post-ReJIT status | `ok` |

Prefetch pass：

| app | program | pass | status | sites matched | sites applied | sites skipped | insn before | insn after | insn delta | bpfopt ms | rejit syscall ms |
|---|---|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| `katran` | `balancer_ingres` | `prefetch` | `ok` | 44 | 44 | 0 | 2542 | 2630 | 88 | 21160 | 294 |

Raw workload / BPF measurements：

| phase | program | bpf id | run cnt delta | run time ns delta | bytes xlated | bytes jited | workload pps | workload bps | errors |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| baseline | `balancer_ingres` | 85 | 2155081 | 446332751 | 23808 | 14456 | 1093533 | 559888896 | 0 |
| post-ReJIT | `balancer_ingres` | 86 | 2152117 | 451012780 | 24512 | 14632 | 1075776 | 550797312 | 0 |

Kinsn module state：

| field | value |
|---|---|
| expected modules | 10 |
| loaded modules | 10 |
| failed modules | 0 |
| includes PRFM module | yes, `bpf_arm64_prfm` |

Interpretation：

- `sites_applied=44` 是 PRFM coverage evidence。
- `post-ReJIT` instruction count 增加 88，符合 44 个 prefetch sites 每处增加 kfunc-side
  instruction footprint 的方向。
- 单样本 `post-ReJIT` 比 baseline 更慢，不能称为 performance win。
- 因为本实验没有 pass-disabled same-corpus control，也没有 native disassembly evidence，
  PRFM LLVM selector 仍应 deferred。

## AWS 时间和费用

价格来源：AWS Pricing API，查询时间为 2026-05-26。交叉参考 AWS 官方 EC2 On-Demand
Pricing 和 EBS Pricing 页面。

| item | value |
|---|---:|
| instance | `t4g.small` |
| compute unit price | `$0.0168 / hour` |
| root volume | 32 GiB gp3 |
| EBS unit price | `$0.08 / GB-month` |
| wall time | 402.061587 s |
| compute cost | `$0.001876287406` |
| EBS cost | `$0.000397097864` |
| total estimated cost | `$0.002273385270` |

该估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 后续

下一步不要直接写 LLVM PRFM selector。建议按顺序做：

1. PRFM pass-disabled same-corpus control：同一个 `katran` corpus run，关闭 `prefetch`，
   用同样 `SAMPLES` / workload duration 做 same-pass attribution。
2. PRFM native code evidence：保存 ReJIT 后 program dump，确认 native code 里确实出现
   `prfm pldl1keep, [xN]`。
3. PRFM wider corpus smoke：至少覆盖 packet-heavy / map-heavy app，确认 coverage 不是
   `katran` 单点偶然。
4. 只有 selected corpus workload 有稳定、可解释收益时，才重新讨论 LLVM selector。

## 收尾一致性复查

已回看：

- 当前实验目录：`/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution`
- PRFM design 文档：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/families/prfm.md`
- 总体计划：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/implementation-plan.md`
- 实现指南：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/guide.md`
- 实验矩阵：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/arm-llvm-backend/experiment-matrix.md`
- AWS run logs 和 result JSON。

发现和处理：

- 旧 PRFM 文档只写到 `pending coverage/performance exploration`。本实验完成后已更新为
  `coverage exploration completed via bpfopt prefetch pass; LLVM selector still deferred`。
- 没有发现需要删除的 PRFM LLVM 临时代码，因为本实验没有写 LLVM PRFM selector。
- 没有修改 framework code，因此不需要重新运行 micro 或 corpus。

是否重跑：

- 不重跑。理由：本实验只更新文档和实验记录；raw run 已成功完成并保存。

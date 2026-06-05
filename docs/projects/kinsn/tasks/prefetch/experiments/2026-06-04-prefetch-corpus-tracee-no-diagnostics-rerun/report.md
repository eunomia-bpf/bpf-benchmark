# 2026-06-04 prefetch-corpus-tracee-no-diagnostics-rerun

## 结论

本实验完成，状态是 `completed_with_one_existing_rejit_failure`。

默认 corpus prefetch path 的 `bpfopt_ms` 明显下降：

- rerun 前：Tracee 167 个 program，总 `bpfopt_ms=308187`，最大单 program `26817ms`。
- rerun 后：Tracee 167 个 program，总 `bpfopt_ms=51357`，最大单 program `2781ms`。
- matched candidate 数不变：`15542`。
- applied 数仍为 0：没有 profile / PMU evidence 时，map-value prefetch 被安全 gate 拦截。
- 默认不再导出 per-candidate diagnostics：`diagnostics_len_total` 从 `15542` 降到 `0`。

仍有 1 个 program `uprobe_syscall_` rejit 失败，原因是 verifier/post-verifier
`BPF_PROG_LOAD errno=28`。这不是 prefetch pass crash；pass 已完成扫描并输出 summary。

## 实验问题

这个实验回答两个问题：

1. 关闭默认 candidate diagnostics 后，prefetch corpus census 是否仍能扫描真实程序中的候选点。
2. Tracee 这种大 BPF program 上的 pass overhead 是否下降到可继续做 corpus census 的范围。

## 命令

从顶层 workspace `/home/ruoji/github/bpf-opt` 执行：

```bash
RUN_TOKEN=prefetch-tracee-no-diag-rerun \
BPFREJIT_CORPUS_APPS=tracee/monitor \
BPFREJIT_BENCH_PASSES=prefetch \
SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1 \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 corpus
```

未传 `BPFREJIT_BENCH_PASS_ARGS='-- --emit-candidates'`，因此这是默认生产路径，
不是 profile candidate 导出路径。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- region：`us-east-1`
- instance type：`t4g.small`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- corpus app：`tracee/monitor`
- pass：`prefetch`
- samples：`1`
- warmups：`0`
- workload duration：`1s`
- raw result：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_163419_920271`
- instance id：`i-0529eb979d44f4833`
- instance 状态：wrapper 已请求 terminate，进入 `shutting-down`

费用估算：

- EC2 compute：`t4g.small` us-east-1 Linux On-Demand 约 `$0.0168/hour`。
- EBS root volume：`32GB`，按 gp3 约 `$0.08/GB-month` 粗略估算。
- suite metadata 时间：`2026-06-04T16:34:19Z` 到 `2026-06-04T16:37:59Z`，约 `220s`。
- compute 估算：`220 / 3600 * 0.0168 ~= $0.0010`。
- EBS 估算：`32 * 0.08 * 220 / (30*24*3600) ~= $0.0002`。
- 合计估算：约 `$0.0012`。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

价格来源：AWS EC2 On-Demand pricing 页面和 us-east-1 `t4g.small` public price mirror；
EBS gp3 参考 AWS EBS pricing / public price mirror。

## 文件改动

实验前已有代码改动：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/pass.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`

改动目的：

- 默认关闭 per-candidate diagnostics，只有显式 `--emit-candidates` /
  `--candidate-diagnostics` 时导出。
- 为 prefetch pass 缓存 program layout / site PC map，避免每个 candidate 反复重建
  全程序 PC map。

本实验新增记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/data/raw-result`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/data/remote.log`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/analysis/tracee-before-after-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/analysis/tracee-rerun-program-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun/analysis/tracee-rerun-top-bpfopt.tsv`

## 数据文件

- `data/raw-result/metadata.json`
- `data/raw-result/details/result.json`
- `data/raw-result/details/apps/tracee__monitor.json`
- `data/raw-result/details/progress.json`
- `data/remote.log`
- `analysis/tracee-before-after-summary.tsv`
- `analysis/tracee-rerun-program-summary.tsv`
- `analysis/tracee-rerun-top-bpfopt.tsv`

## 问题和处理

旧结果中 Tracee selected census 的 pass overhead 过高：

- total `bpfopt_ms=308187`
- max program `bpfopt_ms=26817`
- `diagnostics_len_total=15542`
- `bpfopt_ms` 与原始 BPF 指令数相关性约 `0.91`

定位后发现两个问题：

1. 每个 prefetch candidate 会通过 `report_site_pc` / `site_layout_offset` 间接重建全程序
   site PC map。
2. 默认 report 导出每个 candidate 的 diagnostics，适合 profile 生成，但不适合生产默认
   census。

处理：

- 新增 per-pass `PrefetchLayout` 缓存 site PC / layout offset。
- 默认 suppress candidate diagnostics。
- 保留显式 `--emit-candidates` / `--candidate-diagnostics` 作为 profile 生成路径。

本地验证：

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo fmt
cargo test -p bpfopt prefetch
```

结果：24 个 prefetch 相关测试通过。

## 结果

| run | programs | ok | error | total bpfopt ms | max bpfopt ms | sites matched | applied | skipped | diagnostics |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| before default candidate diagnostics | 167 | 166 | 1 | 308187 | 26817 | 15542 | 0 | 15542 | 15542 |
| after default no candidate diagnostics | 167 | 166 | 1 | 51357 | 2781 | 15542 | 0 | 15542 | 0 |

Top rerun programs by `bpfopt_ms`:

| prog | status | bpfopt ms | orig insns | sites matched |
|---|---|---:|---:|---:|
| `tracepoint__exe` | ok | 2781 | 11827 | 592 |
| `lkm_seeker_proc` | ok | 1847 | 13343 | 271 |
| `lkm_seeker_modt` | ok | 1495 | 13815 | 290 |
| `lkm_seeker_kset` | ok | 1409 | 14602 | 259 |
| `trace_security_` | ok | 1381 | 6699 | 303 |
| `uprobe_syscall_` | failed_rejit | 1275 | 12994 | 153 |

## 后续

继续执行全 corpus default census。该实验用于确认默认 no-diagnostics path 在更多 app 上的
失败面和集成成本；如果 app 本身不能加载 shim-tracked BPF，必须作为 corpus runnability 问题
单独记录，不能归因到 prefetch policy。

## 收尾一致性复查

已回看：

- 前序 selected census：
  `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-selectedapps-default-census`
- 当前 raw result：
  `/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_163419_920271`
- prefetch 文档目录：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch`
- 本地测试结果：`cargo test -p bpfopt prefetch`

发现和处理：

- 旧结论“Tracee candidate census overhead 过高”被本次修复部分推翻：默认 path overhead 已明显下降。
- 旧结论“没有 profile / PMU evidence 时不应用 map-value prefetch”仍成立。
- 未发现需要删除的 prefetch policy code；candidate diagnostics 仍作为显式 profile 生成路径保留。

是否重跑：

- 已重跑 Tracee selected corpus。
- 还需要全 corpus no-diagnostics rerun 作为 broader corpus gate。

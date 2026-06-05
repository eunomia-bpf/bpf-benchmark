# 2026-06-04 prefetch-corpus-allapps-no-diagnostics-rerun

## 结论

本实验完成，状态是 `failed_due_to_corpus_app_runnability`。

全 corpus default prefetch census 在当前 AWS ARM64 环境下不能作为完整 prefetch 集成结论：

- 8 个 app entry 中只有 `katran` 成功完成 baseline、rejit、post-rejit。
- 其余 7 个 app 在 BPF 加载前、shim tracking 前、workload 连接或依赖库阶段失败。
- 成功的 `katran` 只覆盖 1 个 BPF program，`sites_matched=224`，`sites_applied=0`，
  `diagnostics_len=0`，`bpfopt_ms=148`。

因此，这次实验的有效结论是 corpus runnability 当前不足；不能用这个 run 判断 prefetch
在 all-app corpus 上的收益或覆盖率。

## 实验问题

这个实验回答：

1. 默认 no-diagnostics prefetch path 是否可以跑完整 macro app corpus。
2. 如果不能，失败是 prefetch pass 问题，还是 corpus app / runtime 环境问题。

## 命令

从顶层 workspace `/home/ruoji/github/bpf-opt` 执行：

```bash
RUN_TOKEN=prefetch-allapps-no-diag-rerun \
BPFREJIT_BENCH_PASSES=prefetch \
SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1 \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 corpus
```

未设置 `BPFREJIT_CORPUS_APPS`，因此尝试运行 `corpus/config/macro_apps.yaml`
中的全部 app entry。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- region：`us-east-1`
- instance type：`t4g.small`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- corpus manifest：`/home/ruoji/github/bpf-opt/code/corpus/config/macro_apps.yaml`
- pass：`prefetch`
- samples：`1`
- warmups：`0`
- workload duration：`1s`
- raw result：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_164708_343140`
- instance id：`i-08656a0a3245d126a`
- instance 状态：wrapper 已请求 terminate，进入 `shutting-down`

费用估算：

- EC2 compute：`t4g.small` us-east-1 Linux On-Demand 约 `$0.0168/hour`。
- EBS root volume：`32GB`，按 gp3 约 `$0.08/GB-month` 粗略估算。
- suite metadata 时间：`2026-06-04T16:47:08Z` 到 `2026-06-04T17:14:17Z`，约 `1629s`。
- compute 估算：`1629 / 3600 * 0.0168 ~= $0.0076`。
- EBS 估算：`32 * 0.08 * 1629 / (30*24*3600) ~= $0.0016`。
- 合计估算：约 `$0.0092`。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

价格来源：AWS EC2 On-Demand pricing 页面和 us-east-1 `t4g.small` public price mirror；
EBS gp3 参考 AWS EBS pricing / public price mirror。

## 文件改动

实验前已有代码改动同 Tracee rerun：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/pass.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`

本实验新增记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun/data/raw-result`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun/data/remote.log`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun/analysis/app-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun/analysis/program-summary.tsv`

## 数据文件

- `data/raw-result/metadata.json`
- `data/raw-result/details/result.json`
- `data/raw-result/details/apps/*.json`
- `data/raw-result/details/progress.json`
- `data/remote.log`
- `analysis/app-summary.tsv`
- `analysis/program-summary.tsv`

## 问题和处理

失败 app 与原因：

| app | status | reason |
|---|---|---|
| `bcc/set` | error | `biosnoop` attach 失败，`blk_account_io_start` attach 返回 unknown error 524；`syscount` 缺少 `ausyscall` mapping |
| `bpftrace/set` | error | `/usr/local/bin/bpftrace` 缺少 `libclang-17.so.17` |
| `cilium/agent` | error | 1200s 内没有加载 shim-tracked BPF program |
| `katran` | ok | 成功 |
| `katran/wrk` | error | workload 连接 `10.100.1.1:8080` timeout |
| `otelcol-ebpf-profiler/profiling` | error | 200s 内没有加载 shim-tracked BPF program |
| `tetragon/observer` | error | 缺少 `bpf_alignchecker.o`，Tetragon 提前退出 |
| `tracee/monitor` | error | shim socket 返回 empty response |

这些失败发生在 app/runtime/shim tracking 层，不足以证明 prefetch policy 有问题。

## 结果

| app | status | programs | bpfopt ms | sites matched | applied | skipped | diagnostics |
|---|---|---:|---:|---:|---:|---:|---:|
| `bcc/set` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `bpftrace/set` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `cilium/agent` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `katran` | ok | 1 | 148 | 224 | 0 | 224 | 0 |
| `katran/wrk` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `otelcol-ebpf-profiler/profiling` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `tetragon/observer` | error | 0 | 0 | 0 | 0 | 0 | 0 |
| `tracee/monitor` | error | 0 | 0 | 0 | 0 | 0 | 0 |

Only successful program:

| app | program | bpfopt ms | orig insns | sites matched | applied |
|---|---|---:|---:|---:|---:|
| `katran` | `balancer_ingres` | 148 | 2542 | 224 | 0 |

## 后续

全 corpus gate 不能继续依赖当前 all-app runner 状态。下一步应拆成两条：

1. Prefetch task 继续使用可运行 selected apps 做 corpus census，例如 `tracee/monitor`、
   `katran`，并明确它们覆盖的 pattern。
2. Corpus infrastructure task 单独修复 all-app runnability，包括 bpftrace shared library、
   Tetragon artifact、Cilium / otelcol shim tracking、Katran wrk connectivity。

## 收尾一致性复查

已回看：

- Tracee no-diagnostics rerun：
  `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun`
- 前序 all-app default census attempt：
  `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-allapps-default-census`
- 当前 raw result：
  `/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_164708_343140`
- prefetch 文档目录：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch`

发现和处理：

- 当前 all-app run 失败面与 prefetch policy 无直接关系；不能把它作为 prefetch slowdown 或
  correctness failure。
- `katran` 的成功结果显示默认 diagnostics 已关闭，`diagnostics_len=0`。
- 没有因此修改 corpus app runner；这是后续 infrastructure work，不属于本次 prefetch pass
  修复。

是否重跑：

- 已完成 all-app no-diagnostics rerun。
- 由于 app runnability 不足，下一轮不应继续盲跑 all-app；应先修 runner/app artifacts，或改用
  selected-app corpus gate。

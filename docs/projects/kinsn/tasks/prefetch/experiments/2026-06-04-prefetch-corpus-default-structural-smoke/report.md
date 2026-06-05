# 2026-06-04 prefetch-corpus-default-structural-smoke

## 结论

本实验完成了 ARM64 AWS corpus smoke，但只得到 selector coverage 结论，不得到性能收益结论。

- `bcc/set` 没有进入 ReJIT：`biosnoop` attach `blk_account_io_start` 失败。这是 corpus app / kernel attach 问题，不是 prefetch pass 问题。
- `katran` 完整通过 baseline、ReJIT 和 post-ReJIT workload。当前默认 structural prefetch selector 在 `balancer_ingres` 上匹配到 224 个候选，但应用 0 个 prefetch，全部跳过。
- 跳过原因符合安全策略：123 个 map-value 候选缺少 profile 或 PMU 证据，101 个 packet 候选缺少 data-dependent dereference pattern。
- 为支持后续 profile-fed corpus，已把 `BPFREJIT_BENCH_PASS_ARGS` 接入 corpus pass config。随后对 `katran` 做了 config rerun，空参数路径仍通过：matched 224、applied 0、skipped 224。
- 为支持后续真实 corpus profile table，又补做了 `katran` diagnostics rerun。该 rerun 仍然应用 0 个 site，但报告了 224 个候选的
  `pc/source/ptr_reg/ptr_root_pc/ptr_def_pc/mem_off/dependent_load_depth/hint`，并生成
  `analysis/katran-diagnostics-candidates.tsv`。

因此，当前结论是：默认 prefetch selector 可以在真实 corpus app 上运行并做 site census，但不会在没有 profile / PMU 证据时自动插入 prefetch。最新 diagnostics 数据已经足够生成第一版 per-program profile policy table。

## 实验问题

本实验回答四个问题：

1. 当前 Kinsn prefetch pass 是否能通过 AWS ARM64 corpus runner。
2. 在真实 app 上，默认 selector 会匹配多少候选，是否会自动应用 prefetch。
3. 如果没有应用，跳过原因是否符合 safety/admission 规则。
4. pass report 能否导出足够的 per-site candidate 字段，用于后续生成 profile-fed policy table。

本实验不是性能实验，因为：

- `SAMPLES=1`、`WORKLOAD_DURATION=1` 只用于 smoke。
- `katran` 的 treatment 实际没有插入 prefetch，`insn_delta=0`。
- `bcc/set` 失败在 app attach 阶段，没有 baseline / ReJIT 数据。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
./aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=bcc/set \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

```bash
./aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

清理命令：

```bash
./aws-config/run.sh arm64 terminate
```

配置改动后的验证命令：

```bash
./aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

candidate diagnostics 改动后的验证命令：

```bash
./aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64 corpus
- AWS region：`us-east-1`
- instance type：`t4g.small`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- pass：`prefetch`
- corpus apps：
  - `bcc/set`
  - `katran`

## AWS 时间和费用

价格来源：

- EC2 Pricing API，`t4g.small` Linux On-Demand，US East (N. Virginia)：`$0.0168/hour`。
- EC2 Pricing API，EBS `gp3` provisioned storage，US East (N. Virginia)：`$0.08/GB-month`。

估算假设：

- root volume：32 GB gp3。
- 按 instance launch 到 user-initiated terminate 的 wall time 估算。
- EBS 按 730 小时/月折算。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| app | instance | launch UTC | terminate UTC | wall seconds | compute cost | EBS cost | estimated total |
|---|---|---:|---:|---:|---:|---:|---:|
| `bcc/set` | `i-0a4b2f2720d1fd41a` | 2026-06-04 13:09:27 | 2026-06-04 13:15:40 | 373 | `$0.001741` | `$0.000363` | `$0.002104` |
| `katran` | `i-088092f93c692ba19` | 2026-06-04 13:17:37 | 2026-06-04 13:23:47 | 370 | `$0.001727` | `$0.000360` | `$0.002087` |
| `katran-config-rerun` | `i-06cf7ae2cc75d225b` | 2026-06-04 13:34:42 | 2026-06-04 13:40:42 | 360 | `$0.001680` | `$0.000351` | `$0.002031` |
| `katran-diagnostics-rerun` | `i-028e87d0d18747875` | 2026-06-04 13:50:33 | 2026-06-04 13:56:00 | 327 | `$0.001526` | `$0.000319` | `$0.001845` |
| total |  |  |  | 1430 | `$0.006673` | `$0.001393` | `$0.008066` |

四台 instance 最终状态均为 `terminated`。

## 文件改动

本实验运行前后的代码改动来自同一 prefetch task 工作树。

为支持后续 profile-fed corpus，本实验期间新增一个 runner config plumbing 改动：

- `/home/ruoji/github/bpf-opt/code/runner/config/passes/prefetch/default.yaml`

改动内容：在 corpus app-level ReJIT 的 `bpfopt --pass prefetch ...` 命令末尾追加
`${BPFREJIT_BENCH_PASS_ARGS}`。shim 的 `substitute_vars` 会保留未知 `${...}`，随后由
`/bin/sh -c` 从环境中展开；变量为空时默认行为不变。

为支持后续 profile policy table，本实验期间还新增一个 `bpfopt` report diagnostics 改动：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`

改动内容：对每个 structural candidate 记录 `prefetch_candidate` diagnostics，即使该 candidate
最终因为缺少 profile / PMU evidence 被跳过。这样 corpus run 可以导出候选 PC、pointer register、
pointer source 和 dependent depth，用于后续生成 profile-fed policy table。

实验记录新增：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/bcc-set/metadata.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/bcc-set/bcc__set.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran/metadata.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran/katran.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran-config-rerun/metadata.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran-config-rerun/katran.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran-diagnostics-rerun/metadata.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/data/raw/katran-diagnostics-rerun/katran.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/analysis/katran-diagnostics-candidates.tsv`

## 数据文件

原始 runner 结果目录：

- `bcc/set`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_131517_886998`
- `katran`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_132321_206430`
- `katran-config-rerun`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_134016_122651`
- `katran-diagnostics-rerun`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_135534_131778`

本实验复制的 raw data：

- `data/run-contract.json`
- `data/aws-arm64-corpus-smoke.log`
- `data/aws-arm64-corpus-katran-smoke.log`
- `data/aws-arm64-corpus-katran-config-rerun.log`
- `data/aws-arm64-corpus-katran-diagnostics-rerun.log`
- `data/aws-instance-describe.json`
- `data/aws-instance-describe-config-rerun.json`
- `data/aws-instance-describe-diagnostics-rerun.json`
- `data/t4g-small-pricing.json`
- `data/gp3-pricing.json`
- `data/raw/bcc-set/metadata.json`
- `data/raw/bcc-set/bcc__set.json`
- `data/raw/katran/metadata.json`
- `data/raw/katran/katran.json`
- `data/raw/katran-config-rerun/metadata.json`
- `data/raw/katran-config-rerun/katran.json`
- `data/raw/katran-diagnostics-rerun/metadata.json`
- `data/raw/katran-diagnostics-rerun/result.json`
- `data/raw/katran-diagnostics-rerun/katran.json`
- `data/raw/katran-diagnostics-rerun/progress.json`
- `analysis/katran-diagnostics-candidates.tsv`

## 问题和处理

`bcc/set` 失败：

```text
BCC tool biosnoop exited with rc=1:
libbpf: prog 'blk_account_io_start': failed to attach
```

处理：保留失败 raw data，不把它当作 prefetch pass failure。随后改跑 `katran` 作为 corpus smoke。

`katran` 结果：

- app：`katran`
- program：`balancer_ingres`
- type：`xdp`
- status：completed
- `sites_matched`：224
- `sites_applied`：0
- `sites_skipped`：224
- `insn_delta`：0
- map-value skip：123
- packet skip：101

这说明当前 default structural selector 做到了“发现候选但按 evidence gate 保守跳过”。

`katran-config-rerun` 结果：

- result dir：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_134016_122651`
- status：completed
- `sites_matched`：224
- `sites_applied`：0
- `sites_skipped`：224
- `insn_delta`：0
- step command 保留了 `${BPFREJIT_BENCH_PASS_ARGS}`：

```text
timeout 6000 bpfopt --pass prefetch --input ${INPUT} --output ${OUTPUT}
--report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET}
${BPFREJIT_BENCH_PASS_ARGS}
```

这验证了配置改动在空参数时不改变默认行为，并为后续 `BPFREJIT_BENCH_PASS_ARGS='-- --profile ...'`
的 profile-fed corpus run 打开路径。

`katran-diagnostics-rerun` 结果：

- result dir：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_135534_131778`
- status：completed
- `sites_matched`：224
- `sites_applied`：0
- `sites_skipped`：224
- diagnostics：224 条 `prefetch_candidate`
- candidate source：123 个 `map-value`，101 个 `packet`
- 生成 TSV：`analysis/katran-diagnostics-candidates.tsv`

这一步没有改变 default policy 的保守行为；它只把真实 corpus 候选导出成后续 profile generation
可以消费的结构化数据。

## 结果

| app | corpus status | baseline/post available | sites matched | sites applied | sites skipped | interpretation |
|---|---|---:|---:|---:|---:|---|
| `bcc/set` | error | no | n/a | n/a | n/a | app attach failure before ReJIT |
| `katran` | completed | yes | 224 | 0 | 224 | default selector only performs census without profile/PMU evidence |
| `katran-config-rerun` | completed | yes | 224 | 0 | 224 | config plumbing verified; empty pass args preserve default behavior |
| `katran-diagnostics-rerun` | completed | yes | 224 | 0 | 224 | candidate diagnostics exported for profile policy table generation |

`katran` 的 BPF runtime counters 只作为 smoke 信息：

| program | baseline run cnt | baseline runtime ns | post run cnt | post runtime ns |
|---|---:|---:|---:|---:|
| `balancer_ingres` | 1,048,840 | 213,436,735 | 1,122,811 | 227,421,549 |

由于 treatment 没有插入 prefetch，不能用这组 runtime counters 分析 prefetch 加速或减速。

diagnostics rerun 的候选构成：

| source | candidates | meaning |
|---|---:|---|
| `map-value` | 123 | map lookup result 或其 alias 派生出的 map-value load；默认需要 profile / PMU evidence。 |
| `packet` | 101 | packet pointer 派生 load；默认要求 data-dependent dereference pattern。 |

候选 TSV 的字段：

| field | meaning |
|---|---|
| `program_id` / `pass_index` | corpus runner 中的 program id 和 pass index。 |
| `pc` | candidate load 的 BPF PC。 |
| `source` | `map-value` 或 `packet`。 |
| `ptr_reg` | candidate load 使用的 pointer register。 |
| `ptr_root_pc` | pointer root 被识别出的 BPF PC。 |
| `ptr_def_pc` | 当前 pointer value 的最近定义 PC。 |
| `mem_off` | load memory offset。 |
| `dependent_load_depth` | data-dependent dereference depth；当前 `0` 表示普通 structural candidate。 |
| `hint` | 当前 default hint；diagnostics rerun 没有 profile override，所以都是 `default`。 |

## 后续

1. 基于 `analysis/katran-diagnostics-candidates.tsv` 生成第一版 `katran` per-program profile policy table。
2. 用 `BPFREJIT_BENCH_PASS_ARGS='-- --profile ...'` 跑 profile-fed corpus，验证真实 site 能按 profile 插入，且 non-target site 继续 skip。
3. 扩展 corpus site census 到更多可运行 app，统计真实 program 中 future-address / spatial / MLOP / struct-field pattern 的覆盖率。
4. 做 integrated selector：把 synthetic micro 上保留的策略转换成自动或 profile-assisted selector，而不是手工 profile JSON。
5. 再跑原本通用 micro / corpus regression：确认默认不误插、profile-fed 能只插入 evidence-backed sites。

## 收尾一致性复查

已回看：

- 本实验两个子运行：`bcc/set` 和 `katran`。
- 配置改动后的验证运行：`katran-config-rerun`。
- candidate diagnostics 改动后的验证运行：`katran-diagnostics-rerun`。
- 当前 prefetch task 文档：
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md`

发现和处理：

- 文档中对 `struct-field`、`mixed-policy-table`、`stream-of-strides` 的状态仍有过时表述。已更新为 2026-06-04 PMU 结果。
- corpus smoke 证明默认 selector 没有自动插入真实 app prefetch，因此不能把 synthetic micro positive 直接写成真实 workload 收益。文档后续计划已按这个边界更新。
- 初始 diagnostics TSV 只有表头，不能作为数据使用。已从 `katran-diagnostics-rerun` 的
  `bpfopt_summary.diagnostics` 重新生成 224 行候选 TSV，并复制到 code/docs artifact 镜像。

是否重跑：

- 本次改了 prefetch report diagnostics 代码，已重跑：
  `cd /home/ruoji/github/bpf-opt/code/bpfopt && cargo fmt -p bpfopt && cargo test -p bpfopt prefetch`，
  23 个 prefetch tests 通过。
- 本次改了 corpus pass config，因此已重新跑 `katran-config-rerun`，验证默认空参数路径仍然通过。
- 本次新增了 candidate diagnostics，因此已重新跑 `katran-diagnostics-rerun`，验证真实 corpus 上
  default 行为仍是 matched 224、applied 0、skipped 224，同时导出 224 条 candidate diagnostics。

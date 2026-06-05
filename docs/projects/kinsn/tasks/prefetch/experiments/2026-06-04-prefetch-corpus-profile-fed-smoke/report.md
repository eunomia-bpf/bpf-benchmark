# 2026-06-04 prefetch-corpus-profile-fed-smoke

## 结论

本实验完成了 ARM64 AWS corpus profile-fed smoke。

- `rerun3` 在真实 `katran` corpus app 上成功：`sites_matched=225`，
  `sites_applied=1`，`sites_skipped=224`，`insn_delta=2`。
- 成功应用的 site 来自 profile table：
  `source=map-value-profile-point pc=16 ptr_reg=r0 hint=l1keep`。
- `rerun1` 和 `rerun2` 是实验配置失败，不是 prefetch pass 代码失败：
  - `rerun1` 少了 `--`，导致 `--profile` 被 `bpfopt` 顶层 CLI 解析。
  - `rerun2` profile 放在 `code/docs/...`，runner image 不复制该路径，远端容器读不到文件。
- 修正后把 profile 放到 `/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-pc16-r0.json`。
  `corpus/config` 会被 runner image 复制，因此 `rerun3` 成功。

本实验只证明 profile-fed corpus insertion path 可用，不证明性能收益。

## 实验问题

本实验回答：

1. 前一个 `katran` candidate census 导出的真实候选，能否被写回 profile table。
2. `BPFREJIT_BENCH_PASS_ARGS='-- --profile ...'` 是否能通过 corpus runner 传给 `bpfopt --pass prefetch`。
3. profile 指定的真实 `katran` BPF PC 是否能触发一次 Kinsn prefetch 插入。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行。

第一次本地尝试，失败在缺少 `RUN_TOKEN`：

```bash
./aws-config/run.sh arm64 corpus \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="--profile /home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/data/katran-profile-pc16-r0.json --max-sites=1 --hint=pldl1keep" \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

`rerun1`，失败在 pass argument forwarding：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-profile-fed \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="--profile /home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/data/katran-profile-pc16-r0.json --max-sites=1 --hint=pldl1keep" \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

`rerun2`，修正 `--`，但失败在远端 profile path 不存在：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-profile-fed-rerun2 \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="-- --profile /home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/data/katran-profile-pc16-r0.json --max-sites=1 --hint=pldl1keep" \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1
```

`rerun3`，修正 profile path 后成功：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-profile-fed-rerun3 \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="-- --profile /home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-pc16-r0.json --max-sites=1 --hint=pldl1keep" \
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
- corpus app：`katran`
- profile file：`/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-pc16-r0.json`

## AWS 时间和费用

价格来源：

- EC2 Pricing API，`t4g.small` Linux On-Demand，US East (N. Virginia)：`$0.0168/hour`。
- EC2 Pricing API，EBS `gp3` provisioned storage，US East (N. Virginia)：`$0.08/GB-month`。

估算假设：

- root volume：32 GB gp3。
- 按 instance launch 到 user-initiated terminate 的 wall time 估算。
- EBS 按 730 小时/月折算。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| run | instance | launch UTC | terminate UTC | wall seconds | compute cost | EBS cost | estimated total |
|---|---|---:|---:|---:|---:|---:|---:|
| `rerun1` | `i-0abc701af793d4ccc` | 2026-06-04 14:09:52 | 2026-06-04 14:15:34 | 342 | `$0.001596` | `$0.000333` | `$0.001929` |
| `rerun2` | `i-0a4436c93ff0897a5` | 2026-06-04 14:17:35 | 2026-06-04 14:23:34 | 359 | `$0.001675` | `$0.000350` | `$0.002025` |
| `rerun3` | `i-04ffa91e53036012a` | 2026-06-04 14:26:08 | 2026-06-04 14:31:47 | 339 | `$0.001582` | `$0.000330` | `$0.001912` |
| total |  |  |  | 1040 | `$0.004853` | `$0.001013` | `$0.005866` |

三台 AWS instance 最终状态均为 `terminated`。

## 文件改动

为保证远端 runner image 能读到 profile table，本实验新增：

- `/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-pc16-r0.json`

该文件只用于 corpus profile-fed smoke：指定真实 `katran` PC 16、register r0、hint
`pldl1keep`，用于验证 profile-fed insertion path。

实验记录新增：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/analysis/profile-fed-summary.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/analysis/profile-fed-diagnostics.tsv`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke/analysis/aws-cost-summary.tsv`

## 数据文件

原始 runner 结果目录：

- `rerun1`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_141520_133795`
- `rerun2`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_142320_617549`
- `rerun3`：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_143121_259823`

本实验复制的 raw data：

- `data/run-contract.json`
- `data/aws-arm64-corpus-katran-profile-fed-smoke.log`
- `data/aws-arm64-corpus-katran-profile-fed-smoke-rerun1.log`
- `data/aws-arm64-corpus-katran-profile-fed-smoke-rerun2.log`
- `data/aws-arm64-corpus-katran-profile-fed-smoke-rerun3.log`
- `data/aws-instance-describe-profile-fed-rerun1.json`
- `data/aws-instance-describe-profile-fed-rerun2.json`
- `data/aws-instance-describe-profile-fed-rerun3.json`
- `data/katran-profile-pc16-r0.json`
- `data/katran-profile-pc16-r0-container-visible.json`
- `data/raw/katran-profile-fed-rerun1/`
- `data/raw/katran-profile-fed-rerun2/`
- `data/raw/katran-profile-fed-rerun3/`
- `analysis/profile-fed-summary.tsv`
- `analysis/profile-fed-diagnostics.tsv`
- `analysis/aws-cost-summary.tsv`

## 问题和处理

`RUN_TOKEN` failure：

- 原因：corpus AWS target 必须通过 Makefile run contract 提供 `RUN_TOKEN`。
- 处理：后续 rerun 显式设置 `RUN_TOKEN=...`。

`rerun1` pass argument failure：

```text
error: unexpected argument '--profile' found
tip: to pass '--profile' as a value, use '-- --profile'
```

- 原因：`bpfopt` 顶层 CLI 使用 `-- [PASS_ARGS]...` 分隔 pass 参数。
- 处理：`BPFREJIT_BENCH_PASS_ARGS` 改成以 `-- --profile ...` 开头。

`rerun2` profile path failure：

```text
error: failed to read /home/ruoji/github/bpf-opt/code/docs/.../katran-profile-pc16-r0.json:
No such file or directory
```

- 原因：runner image 不复制 `code/docs/...`；它复制 `corpus/config`。
- 处理：新增 `/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-pc16-r0.json`，
  并在 `rerun3` 使用该路径。

## 结果

| run | app status | pass status | sites matched | sites applied | sites skipped | insn delta | interpretation |
|---|---|---|---:|---:|---:|---:|---|
| `rerun1` | ok | failed_bpfopt | n/a | n/a | n/a | n/a | missing `--` before pass args |
| `rerun2` | ok | failed_bpfopt | n/a | n/a | n/a | n/a | profile file path not copied into runner image |
| `rerun3` | ok | ok | 225 | 1 | 224 | 2 | profile-fed site insertion works |

`rerun3` 首条 diagnostic：

```text
site at PC=16: prefetch_candidate source=map-value-profile-point ptr_reg=r0
ptr_root_pc=13 ptr_def_pc=13 mem_off=0 dependent_load_depth=0 hint=l1keep
```

这说明 profile table 中的真实 corpus candidate 被转换成一个 prefetch insertion site。
`insn_delta=2` 表示 BPF object 增加了 Kinsn sidecar/call encoding。剩余 224 个 structural
candidate 仍被 safety/admission gate 跳过：

- 123 个 map-value candidate：缺少 profile 或 PMU evidence。
- 101 个 packet candidate：缺少 data-dependent dereference pattern。

## 后续

下一步不是继续扩大默认插入，而是做 profile policy generation：

1. 从 `katran-diagnostics-candidates.tsv` 生成多 site profile table。
2. 对候选按 source、dependent depth、offset cluster、hotness/PMU evidence 分组。
3. 只对有证据的真实 corpus site 做 profile-fed treatment。
4. 对 treatment 做 runtime + codegen + PMU-capable attribution。

## 收尾一致性复查

已回看：

- 当前实验的 `rerun1`、`rerun2`、`rerun3`。
- 前序实验 `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke`。
- 相关文档：
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`

发现和处理：

- `rerun2` 证明 `code/docs/...` 不能作为远端容器 profile path。已把 profile 移到
  `code/corpus/config/prefetch/` 并用 `rerun3` 验证。
- 没有发现需要删除的 prefetch selector 临时代码。
- 本实验只新增 profile config 和实验记录；profile config 是后续 corpus profile-fed
  experiments 的可复用输入，不是默认 policy。

是否重跑：

- 已重跑 `rerun3` 覆盖路径修正，且成功。

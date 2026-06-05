# 2026-06-04 prefetch-corpus-generated-profile-table

## 结论

本实验完成，状态是 `completed`。

本实验验证了 prefetch task 的 profile-fed path 可以从 corpus diagnostics 自动生成
profile JSON，并在 AWS ARM64 Katran corpus smoke 中实际应用多个 map-value prefetch
sites：

- generator：`/home/ruoji/github/bpf-opt/code/scripts/prefetch_profile_from_candidates.py`
- generated profile：`/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-generated-map-value-top12.json`
- AWS result：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_151014_311732`
- Katran status：`ok`
- bpfopt pass status：`ok`
- `sites_matched=236`
- `sites_applied=12`
- `sites_skipped=224`
- BPF insn count：`2542 -> 2566`，delta `+24`
- BPF xlated bytes：`23808 -> 24000`，delta `+192`
- ARM64 native JIT bytes：`14456 -> 14504`，delta `+48`

这不是性能结论。该 run 使用 `SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=1`，目的是验证
profile generator 和 corpus pass application path。

## 实验问题

Prefetch task 已经有两类 corpus smoke：

1. default structural smoke：扫描 Katran 中可见的 prefetch candidates，但没有 profile 或
   PMU evidence 时不应用 map-value prefetch。
2. hand-written multi-site profile smoke：手工列出 12 个 map-value profile points，验证
   pass 能应用多个 profile-fed prefetch。

本实验回答第三个问题：能不能从 diagnostics candidate TSV 自动生成 profile table，并让
同一个 corpus pipeline 消费该 profile，而不是继续手写 JSON。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行。

生成 profile：

```bash
python3 code/scripts/prefetch_profile_from_candidates.py \
  --input experiments/2026-06-04-prefetch-corpus-default-structural-smoke/analysis/katran-diagnostics-candidates.tsv \
  --output code/corpus/config/prefetch/katran-profile-generated-map-value-top12.json \
  --max-sites 12 \
  --hint pldl1keep \
  --policy corpus-generated-map-value-top12
```

本地验证：

```bash
python3 -m py_compile code/scripts/prefetch_profile_from_candidates.py
jq '.map_value_policy_points | length' \
  code/corpus/config/prefetch/katran-profile-generated-map-value-top12.json
```

AWS corpus smoke：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-generated-profile \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="-- --profile /home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-generated-map-value-top12.json --max-sites=12 --hint=pldl1keep" \
  SAMPLES=1 \
  WARMUPS=0 \
  WORKLOAD_DURATION=1
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS
- arch：ARM64
- suite：corpus
- app：Katran
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- kernel release：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- instance id：`i-0494ea51138acd8ca`
- launch time：`2026-06-04T15:04:26Z`
- terminate time：`2026-06-04T15:10:40Z`
- final state：`terminated`

费用估算：

- t4g.small Linux on-demand 按 `$0.0168/hour` 估算。
- gp3 root EBS 按 `$0.08/GB-month`、32 GB、374 秒估算。
- compute：`$0.001745`
- EBS：`$0.000369`
- total：`$0.002114`

该估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或
账户级折扣。

## 文件改动

本实验新增：

- `/home/ruoji/github/bpf-opt/code/scripts/prefetch_profile_from_candidates.py`
- `/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-generated-map-value-top12.json`

本实验没有修改 benchmark framework 的统计逻辑。framework 仍只保存 raw measurements；
summary、skip 聚合和说明只写在本实验记录和 task 文档中。

## 数据文件

- `data/run-contract.json`
- `data/aws-instance-describe.json`
- `data/katran-diagnostics-candidates.tsv`
- `data/katran-profile-generated-map-value-top12.json`
- `data/raw/aws_arm64_corpus_20260604_151014_311732/metadata.json`
- `data/raw/aws_arm64_corpus_20260604_151014_311732/details/apps/katran.json`
- `data/raw/aws_arm64_corpus_20260604_151014_311732/details/result.json`
- `data/raw/aws_arm64_corpus_20260604_151014_311732/details/progress.json`
- `analysis/summary.tsv`
- `analysis/applied-profile-points.tsv`
- `analysis/skip-reasons-raw.tsv`
- `analysis/skip-reason-summary.tsv`
- `analysis/aws-cost-summary.tsv`

## 结果

Profile generator 输出 12 个 points，和 hand-written multi-site smoke 的点位一致：

| pc | reg | ptr_root_pc | ptr_def_pc | mem_off | hint |
|---:|---:|---:|---:|---:|---|
| 16 | 0 | 13 | 13 | 0 | l1keep |
| 367 | 0 | 365 | 365 | 0 | l1keep |
| 466 | 0 | 464 | 464 | 0 | l1keep |
| 524 | 0 | 520 | 520 | 0 | l1keep |
| 543 | 0 | 541 | 541 | 0 | l1keep |
| 548 | 8 | 547 | 547 | 0 | l1keep |
| 572 | 0 | 570 | 570 | 0 | l1keep |
| 594 | 0 | 592 | 592 | 0 | l1keep |
| 618 | 0 | 616 | 616 | 0 | l1keep |
| 656 | 0 | 654 | 654 | 0 | l1keep |
| 775 | 0 | 770 | 770 | 0 | l1keep |
| 795 | 0 | 793 | 793 | 0 | l1keep |

Katran corpus smoke summary：

| case | app | rejit | pass | matched | applied | skipped | insn delta |
|---|---|---|---|---:|---:|---:|---:|
| generated-profile | ok | ok | ok | 236 | 12 | 224 | +24 |

Skip reason summary：

| reason class | count |
|---|---:|
| map value prefetch requires profile or PMU evidence | 123 |
| packet prefetch requires a data-dependent dereference | 101 |

`skip_reasons` 中仍会出现与 profile PC 相同的 ordinary structural candidates。例如 PC 16 同时有：

- `source=map-value-profile-point`：profile table 明确要求 prefetch，实际应用。
- `source=map-value`：普通 structural candidate，没有 profile 或 PMU evidence，因此被 skip。

因此 gate 以 `sites_applied=12` 和 `source=map-value-profile-point` diagnostics 为准。

## 问题和处理

- 运行前执行 `/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 terminate`，未发现需要清理的
  active instance。
- AWS run 完成后 instance `i-0494ea51138acd8ca` 已进入 `terminated`。
- 该次 terminal stdout 没有 tee 到独立 log；原始 corpus result、AWS instance describe 和
  run contract 已完整保存到本实验目录。后续如需完整 stdout，应在执行命令时显式 `tee`。

## 后续

Prefetch task 下一步不是继续手工挑点，而是把这个 generated profile path 推进成更完整的
selector/evaluation workflow：

1. 扩展 profile generator 的 selection rule：支持按 profile/PMU score 排序，而不只是按 PC 顺序取
   distinct pointer-def sites。
2. 对 packet data-dependent dereference candidates 做同类 profile generation。
3. 将 generated profile smoke 纳入 prefetch task 文档和 commit plan。
4. 如果要做性能结论，必须单独跑多样本、paired control/treatment，并补充可用 PMU 或替代证据。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`

发现和处理：

- hand-written multi-site profile 能工作，但不能说明 profile table 可自动生成。已用本实验补齐。
- 已同步更新 prefetch task 文档：profile-fed path 当前已从“手工 JSON”推进到
  “diagnostics TSV 生成 JSON”。
- 本次没有修改 benchmark framework 行为，因此不需要重跑 micro benchmark。

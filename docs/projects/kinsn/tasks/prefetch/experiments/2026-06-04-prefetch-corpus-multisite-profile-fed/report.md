# 2026-06-04 prefetch-corpus-multisite-profile-fed

## 结论

本实验完成，状态是 `completed_smoke_only`。

结论：

- AWS ARM64 `katran` corpus profile-fed 多点 smoke 成功。
- profile 来自真实 `katran` candidate diagnostics TSV，选择 12 个不同 map-value
  pointer-definition site。
- `bpfopt --pass prefetch` 在 `balancer_ingres` 上：
  - `sites_matched = 236`
  - `sites_applied = 12`
  - `sites_skipped = 224`
  - `insn_delta = 24`
- treatment BPF xlated bytes 从 `23808` 增加到 `24000`，native JIT bytes 从 `14456`
  增加到 `14504`，符合 12 个 `KINSN_SIDECAR + KINSN_CALL` profile points 被插入。

这不是性能结论。`SAMPLES=1`、`WORKLOAD_DURATION=1` 只用于验证真实 corpus 的
profile-table insertion path。

## 实验问题

要回答的问题是：真实 `katran` corpus candidate census 能不能驱动多点 profile-fed Kinsn
prefetch insertion，而不是只能做单点 smoke。

这是 prefetch task 的 real-coverage gate 的一部分：

```text
candidate census TSV
  -> per-site profile table
  -> bpfopt --pass prefetch -- --profile FILE
  -> raw kinsn BPF
  -> kernel kinsn JIT emit ARM64 prfm
```

## 命令

从 `/home/ruoji/github/bpf-opt` 执行：

```bash
./aws-config/run.sh arm64 corpus \
  RUN_TOKEN=prefetch-corpus-profile-fed-multisite \
  BPFREJIT_CORPUS_APPS=katran \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS="-- --profile /home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-multisite-map-value.json --max-sites=12 --hint=pldl1keep" \
  SAMPLES=1 \
  WARMUPS=0 \
  WORKLOAD_DURATION=1
```

Profile 文件：

```text
/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-multisite-map-value.json
```

该路径在 `code/corpus/config` 下，runner runtime image 会复制 `corpus/config`，远端容器能读取。

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS
- arch：ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- profile：`default`
- instance id：`i-0b6c82c26ff20d367`
- remote user：`ec2-user`
- kernel release：`7.0.0-rc2+`
- container image：`bpf-benchmark/runner-runtime:arm64`
- result dir：`/home/ruoji/github/bpf-opt/code/corpus/results/aws_arm64_corpus_20260604_145019_931644`

AWS time / cost：

| instance | launch | terminate | wall seconds | estimated cost |
|---|---|---|---:|---:|
| `i-0b6c82c26ff20d367` | `2026-06-04T14:44:41+00:00` | `2026-06-04T14:50:46+00:00` | 365 | `$0.002064` |

Cost estimate uses project convention for us-east-1 on-demand Linux `t4g.small` compute
`$0.0168/hour` and EBS gp3 `$0.08/GB-month`, root volume `32 GiB`. It excludes data
transfer, tax, free tier, credits, Savings Plans, Reserved Instances, and account-level discounts.

Instance cleanup status: terminated.

## 文件改动

新增 corpus-visible profile config：

```text
/home/ruoji/github/bpf-opt/code/corpus/config/prefetch/katran-profile-multisite-map-value.json
```

本实验没有新增 Rust / runner / kernel module code。运行前验证：

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo test -p bpfopt prefetch
```

结果：23 个 prefetch tests 全部通过。

## 数据文件

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/data/run-contract.json
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/data/aws-arm64-corpus-katran-multisite-profile-fed.log
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/data/aws-instance-describe.json
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/data/katran-profile-multisite-map-value.json
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/data/raw/aws_arm64_corpus_20260604_145019_931644
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/analysis/multisite-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/analysis/applied-profile-points.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/analysis/skip-reason-summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-multisite-profile-fed/analysis/aws-cost-summary.tsv
```

## 问题和处理

本实验没有 AWS runtime failure。

需要注意的限制：

- 这次 profile 是从 candidate TSV 手工选出的 12 个真实 `katran` map-value site。
- 它证明 profile-fed 多点 insertion path 可用。
- 它不证明这些 site 有性能收益，也不证明自动 selector 已完成。

## 结果

`multisite-summary.tsv`：

| case | status | sites matched | sites applied | sites skipped | insn delta |
|---|---|---:|---:|---:|---:|
| `katran-multisite-profile-fed` | `ok` | 236 | 12 | 224 | 24 |

Profile-fed points：

| pc | reg | ptr root pc | ptr def pc | hint |
|---:|---:|---:|---:|---|
| 16 | 0 | 13 | 13 | `l1keep` |
| 367 | 0 | 365 | 365 | `l1keep` |
| 466 | 0 | 464 | 464 | `l1keep` |
| 524 | 0 | 520 | 520 | `l1keep` |
| 543 | 0 | 541 | 541 | `l1keep` |
| 548 | 8 | 547 | 547 | `l1keep` |
| 572 | 0 | 570 | 570 | `l1keep` |
| 594 | 0 | 592 | 592 | `l1keep` |
| 618 | 0 | 616 | 616 | `l1keep` |
| 656 | 0 | 654 | 654 | `l1keep` |
| 775 | 0 | 770 | 770 | `l1keep` |
| 795 | 0 | 793 | 793 | `l1keep` |

Skip summary：

| group | count |
|---|---:|
| `map-value-unprofiled` | 123 |
| `packet-no-dependent-deref` | 101 |

Bytecode / JIT size:

| metric | baseline | treatment | delta |
|---|---:|---:|---:|
| BPF xlated bytes | 23808 | 24000 | +192 |
| native JIT bytes | 14456 | 14504 | +48 |

Interpretation:

- 12 profile-fed sites each add 2 BPF insns, so xlated byte delta is `12 * 2 * 8 = 192`.
- ARM64 native JIT image increases by 48 bytes, consistent with 12 native `prfm` hints.
- Remaining 224 structural candidates are still skipped by evidence gates.

## 后续

下一步应从 `katran-diagnostics-candidates.tsv` 自动生成 profile policy tables，而不是手工选点：

1. 对真实 candidate 做 classification：map-value field, repeated root, packet no-dependent-deref, etc.
2. 输出 per-program profile table：`prefetch` / `skip` / `reason`。
3. 跑 profile-fed corpus treatment with multiple apps or expanded Katran sites。
4. 再决定是否需要自动 selector，或保持 profile-gated research mode。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-default-structural-smoke`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-corpus-profile-fed-smoke`
- 当前 prefetch canonical docs：
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
  - `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`

发现和处理：

- 单点 profile-fed smoke 后，文档仍保留旧状态。已更新为：
  多点 hand-profile table smoke 已完成，但自动 profile generation / integrated selector 仍未完成。
- 本实验没有修改 Rust / runner / kernel behavior，因此不需要新增 code-level rerun。
- 已运行 `cargo test -p bpfopt prefetch` 覆盖当前 profile schema / prefetch pass 单元测试。

实例清理：

- `i-0b6c82c26ff20d367` 已进入 `terminated`。

# 2026-06-04 prefetch-pf-llm-missing-policy-smoke

## 结论

本实验补齐了 Kinsn prefetch policy screening 中缺的三个 PF-LLM-inspired probe：

- `struct-field`：固定 record / struct field offsets。
- `mixed-policy-table`：同一个 program 里 per-PC 选择 `prefetch` 或 `skip`。
- `stream-of-strides`：同一个 loop 里两个交错 stride stream。

本轮完成的是 **实现 / correctness / emit smoke**，不是性能归因。x86 AWS `t3.small` 上：

| case | policy role | status | `sites_applied` | native hint evidence |
|---|---|---:|---:|---|
| `prefetch_struct_field_fixed_offsets` | fixed-offset struct-field | completed | 3 | 3 个 `prefetcht0` |
| `prefetch_mixed_policy_table` | per-PC mixed prefetch / skip table | completed | 1 | 1 个 `prefetcht0` |
| `prefetch_stream_of_strides` | two-stream stride | completed | 2 | 2 个 `prefetcht0` |

因此这三个 policy 现在可以进入后续 ARM64 treatment / paired attribution / PMU diagnosis。
不能从本轮 `SAMPLES=1 WARMUPS=0 INNER_REPEAT=1` 得出性能结论。

## 实验问题

要回答的问题：

```text
PF-LLM-inspired taxonomy 中还缺的 struct-field、mixed-policy-table、stream-of-strides，
能否被 Kinsn prefetch 用 BPF bytecode profile point 表达，并在 kernel JIT 中生成 native prefetch hint？
```

本轮不回答：

```text
这些 policy 是否稳定加速。
这些 policy 是否应该 default-enable。
真实 BPF corpus 中是否存在这些 pattern。
```

## 命令

所有 benchmark / smoke 都通过 Makefile 或 AWS wrapper 入口运行。

本地 build：

```bash
cd /home/ruoji/github/bpf-opt/code
make -C micro/programs OUTPUT_DIR=build-x86 all
```

Rust tests：

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo fmt --all
cargo test prefetch -- --nocapture
```

本地 Docker smoke 尝试：

```bash
cd /home/ruoji/github/bpf-opt/code
PLATFORM=docker ARCH=x86 BENCH=prefetch_stream_of_strides RUNTIMES=kernel \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 make micro
```

该本地 smoke 因 host/container kernel mismatch 失败，见“问题和处理”。

AWS 配置检查和预清理：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/check.sh x86
./aws-config/run.sh x86 terminate
```

AWS x86 control / treatment smoke：

```bash
cd /home/ruoji/github/bpf-opt

./aws-config/run.sh x86 micro \
  BENCH=prefetch_stream_of_strides \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  RUN_TOKEN=prefetch-stream-x86-control-rerun1

./aws-config/run.sh x86 micro \
  BENCH=prefetch_stream_of_strides \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  RUN_TOKEN=prefetch-stream-x86-treatment-smoke \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json --max-sites=2 --hint=t0'

./aws-config/run.sh x86 micro \
  BENCH=prefetch_struct_field_fixed_offsets \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  RUN_TOKEN=prefetch-struct-field-x86-treatment-smoke \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json --max-sites=3 --hint=t0'

./aws-config/run.sh x86 micro \
  BENCH=prefetch_mixed_policy_table \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=1 \
  RUN_TOKEN=prefetch-mixed-policy-x86-treatment-smoke \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json --max-sites=1 --hint=t0'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- prefetch pass：`/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- micro manifest：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- AWS arch：x86
- AWS instance type：`t3.small`
- AWS region：`us-east-1`
- remote user：`ec2-user`
- remote runtime container：`bpf-benchmark/runner-runtime:x86_64`
- kernel release：`7.0.0-rc2+`
- root volume：32 GiB

## 文件改动

代码和 benchmark：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json`

文档和实验记录：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-smoke/report.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`

## 实现内容

### `struct-field`

Test case：

```text
prefetch_struct_field_fixed_offsets
```

构造方式：

- 1 MiB map value。
- 每轮选择一个 synthetic record。
- 同一 record 内读固定 offsets，例如 `0 / 64 / 128`。
- profile point 指定三个已经物化的 future field pointer registers。

Profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-struct-field-fixed-offsets-profile-pc29-r2-r6-r4.json
```

含义：

```text
pc 29: prefetch r2, r6, r4
```

### `mixed-policy-table`

Test case：

```text
prefetch_mixed_policy_table
```

构造方式：

- 同一个 BPF program 内混合：
  - hot fixed load，应该 skip；
  - future page-stride pointer，允许 prefetch。
- 新 profile schema 用 `map_value_policy_points` 表达每个 PC/register 的 action。

Profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-mixed-policy-table-profile-pc23-r2.json
```

含义：

```text
pc 23 reg 0: skip
pc 23 reg 2: prefetch
```

### `stream-of-strides`

Test case：

```text
prefetch_stream_of_strides
```

构造方式：

- 1 MiB map value。
- 同一个 loop 内有两个 interleaved streams。
- stream A 和 stream B 使用不同 stride/salt，分别物化 `i+2` future pointer。
- profile point 对两个 future pointer registers 各插一个 prefetch。

Profile：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-stream-of-strides-profile-pc316-r2-r9.json
```

含义：

```text
pc 316: prefetch r2, r9
```

## 数据文件

本实验目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-04-prefetch-pf-llm-missing-policy-smoke
```

关键数据：

- `data/run-contract.json`
- `analysis/aws-smoke-summary.tsv`
- `data/micro-programs-build.log`
- `data/micro-programs-build.stderr.log`
- `data/cargo-test-prefetch-all.log`
- `data/cargo-test-prefetch-all.stderr.log`
- `data/prefetch_upper_bound.bpf.objdump`
- `data/prefetch_upper_bound.bpf.source-objdump`
- `data/aws-results/aws_x86_micro_20260604_090025_116106`
- `data/aws-results/aws_x86_micro_20260604_090715_792636`
- `data/aws-results/aws_x86_micro_20260604_091609_304735`
- `data/aws-results/aws_x86_micro_20260604_092305_849754`
- `data/aws-instance-final-state.json`

## 问题和处理

1. 本地 Docker smoke 失败。

原因：

```text
image kernel release 7.0.0-rc2+ != host kernel 6.12.74+deb13+1-amd64
```

处理：

- 不把这个结果作为 benchmark failure。
- 后续改用 AWS x86 wrapper 跑 kernel runtime smoke。

2. `prefetch_stream_of_strides` 第一次 AWS control run 失败。

原因：

```text
manifest expected_result 仍是 0，实际 deterministic result 是 2202534365130024933。
```

处理：

- 更新 `micro_pure_jit.yaml` 的 expected result。
- 重新跑 control，后续 control / treatment 都通过。

## 结果

### Local verification

| check | status |
|---|---|
| `make -C micro/programs OUTPUT_DIR=build-x86 all` | passed |
| `cargo fmt --all` | passed |
| `cargo test prefetch -- --nocapture` | passed, 20 tests |

### AWS x86 smoke

| case | run dir | status | result | BPF bytes | native bytes | `sites_applied` | native hint |
|---|---|---:|---:|---:|---:|---:|---|
| `prefetch_stream_of_strides` control initial | `aws_x86_micro_20260604_085136_579819` | failed | n/a | n/a | n/a | n/a | n/a |
| `prefetch_stream_of_strides` control rerun | `aws_x86_micro_20260604_090025_116106` | completed | `2202534365130024933` | 2648 | 1360 | 0 | none |
| `prefetch_stream_of_strides` treatment | `aws_x86_micro_20260604_090715_792636` | completed | `2202534365130024933` | 2680 | 1367 | 2 | 2 x `prefetcht0` |
| `prefetch_struct_field_fixed_offsets` treatment | `aws_x86_micro_20260604_091609_304735` | completed | `12246088582525788897` | 2840 | 1425 | 3 | 3 x `prefetcht0` |
| `prefetch_mixed_policy_table` treatment | `aws_x86_micro_20260604_092305_849754` | completed | `16217383686291505505` | 2664 | 1314 | 1 | 1 x `prefetcht0` |

`prefetch_stream_of_strides` treatment BPF bytecode 比 control 多 32 bytes，和 2 个 prefetch kinsn
sequence 一致。

### AWS instance cleanup

| instance | run | launch time UTC | terminate proxy time UTC | wall time h | final state |
|---|---|---:|---:|---:|---|
| `i-0b5b199d1cb8ce5e1` | stream control initial | 2026-06-04 08:46:31 | 2026-06-04 08:51:36 | 0.0847 | terminated |
| `i-0ac875a238ac791f5` | stream control rerun | 2026-06-04 08:54:07 | 2026-06-04 09:00:25 | 0.1050 | terminated |
| `i-0168c3ad0fd352c3d` | stream treatment | 2026-06-04 09:01:55 | 2026-06-04 09:07:15 | 0.0889 | terminated |
| `i-0f6214f6bea4dfcbb` | struct-field treatment | 2026-06-04 09:10:11 | 2026-06-04 09:16:09 | 0.0994 | terminated |
| `i-0ec3f2776b7ae80a6` | mixed-policy treatment | 2026-06-04 09:17:54 | 2026-06-04 09:23:05 | 0.0864 | terminated |

Terminate proxy time 使用 runner result `generated_at`，wrapper 在同步结果后立即发出 terminate request。
AWS `describe-instances` 已确认最终状态为 `terminated`。

### AWS cost estimate

估算参数：

- AWS public On-Demand Linux `t3.small` in `us-east-1`：`$0.0208 / hour`。
- AWS public EBS gp3 in `us-east-1`：`$0.08 / GB-month`。
- root volume：32 GiB。
- 合计 AWS wall time：约 `0.4644` instance-hour。

估算：

| item | cost |
|---|---:|
| compute | `$0.0097` |
| EBS root volume | `$0.0017` |
| total | `$0.0114` |

不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 后续

这三个 policy 的下一步不是继续 x86 smoke，而是：

1. ARM64 treatment smoke，确认 `prfm pldl1keep` emit。
2. ARM64 paired attribution，`SAMPLES >= 5`、`WARMUPS >= 1`、`INNER_REPEAT=10000`。
3. 如果 timing 有 positive signal，再上 `c7g.large` PMU attribution。
4. 做 corpus site census，确认真实 BPF 里是否出现这些 access shape。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md`
- 当前 experiment 目录下失败的 local Docker smoke 和 initial stream control run。

发现和处理：

- 文档中 `struct-field` / `mixed-policy-table` 仍写成 treatment pending。已更新为 x86
  treatment smoke completed，但 ARM64 / performance pending。
- `stream-of-strides` 仍写成 missing policy。已更新为 case/profile/x86 smoke completed。
- initial stream control failure 的旧 expected-result mismatch 已在同一实验里记录，并通过 rerun 验证。

是否重跑：

- 代码和 micro manifest 已重跑 `make -C micro/programs OUTPUT_DIR=build-x86 all`、Rust prefetch tests
  和 AWS x86 smoke。
- 文档收尾改动不改变代码行为，因此不需要额外 benchmark rerun。

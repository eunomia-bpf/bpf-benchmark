# 2026-06-02 prefetch-pipeline-map-attribution

## 结论

本次完成了 next-iteration / software-pipeline map-value prefetch 的本地实现验证和
x86 / ARM64 AWS kernel micro paired attribution。

结论：

- `bpfopt` prefetch pass 已支持 profile 指定的 `map_value_prefetch_points`。
- 新增 micro `prefetch_pipeline_page_stride` 已能通过 Makefile 生成 BPF object。
- profile point `pc=45, reg=1` 的 object evidence 符合预期：`r1` 已经是下一轮
  `next` pointer，当前轮 demand load 尚未开始。
- x86 / ARM64 treatment 都稳定 applied 1 个 prefetch site。
- x86 treatment native code 出现 `prefetcht0 BYTE PTR [rdi]`。
- ARM64 treatment native code 出现 `prfm pldl1keep, [x0]`。
- x86 paired geomean treatment/control 是 `0.985484`，按 `exec_ns` 约快 `1.45%`。
  但 x86 `wall_exec_ns` / `exec_cycles` 在 treatment 前两个样本上出现明显计时源不一致，
  因此 x86 只能算 weak positive signal。
- ARM64 paired geomean treatment/control 是 `0.858777`，按 `exec_ns` 约快 `14.12%`。
  ARM64 本轮没有 `wall_exec_ns` / `exec_cycles`，因此结论仍需要 independent rerun 或 PMU-capable
  环境复核。

本次状态是 `completed_with_positive_signal`。它说明 next-iteration placement 比前面的
same-iteration placement 更有希望，但还不是 default-enable 证据。

## 实验问题

前一轮 `prefetch_upper_page_stride` 说明 same-iteration map-value prefetch 仍不能稳定隐藏 latency。
本实验要验证一个更接近软件流水线的形态：

```text
第 i 轮：
  读取 cur_i
  提前计算 next_{i+1}
  在当前轮 demand load 前 prefetch next_{i+1}

第 i+1 轮：
  使用上轮已经 prefetch 过的 next_{i+1} 作为 cur
```

这个实验不让 pass 合成未来地址。BPF micro 显式维护 `cur` 和 `next`，profile 只告诉 pass：
在某个 BPF PC 前，对 live register 里的 `next` pointer 发 prefetch。

要回答的问题：

1. profile-specified prefetch point 能否在本地正确定位到下一轮 pointer。
2. x86 和 ARM64 kernel runtime 是否都能加载 treatment object 并保持 result 正确。
3. kernel JIT native code 是否真的生成架构对应的 prefetch hint。
4. 在 same-LLC paired setting 下，next-iteration placement 是否出现比 control 更快的信号。

## 命令

本地 Rust targeted test：

```bash
cd /home/ruoji/github/bpf-opt
cargo test --manifest-path code/bpfopt/Cargo.toml --release -p bpfopt prefetch
```

本地 release build：

```bash
cd /home/ruoji/github/bpf-opt
cargo build --manifest-path code/bpfopt/Cargo.toml --release -p bpfopt -p kinsnprober
```

BPF object build，必须通过 Makefile 入口：

```bash
cd /home/ruoji/github/bpf-opt
make -C code/micro/programs OUTPUT_DIR=/tmp/bpf-opt-prefetch-pipeline-build \
  /tmp/bpf-opt-prefetch-pipeline-build/prefetch_upper_bound.bpf.o
```

Object evidence：

```bash
cd /home/ruoji/github/bpf-opt
llvm-objdump-20 -d --no-show-raw-insn \
  /tmp/bpf-opt-prefetch-pipeline-build/prefetch_upper_bound.bpf.o
```

AWS check：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/check.sh x86
/home/ruoji/github/bpf-opt/aws-config/check.sh arm64
```

AWS smoke：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-control-smoke-rerun1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=100

/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-treatment-smoke-rerun1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=100 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'

/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-control-smoke-rerun1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=100

/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-treatment-smoke-rerun1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=1 \
  WARMUPS=0 \
  INNER_REPEAT=100 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'
```

AWS stability run：

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-control-stability-r1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000

/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  RUN_TOKEN=pipeline-x86-treatment-stability-r1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'

/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-control-stability-r1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000

/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUN_TOKEN=pipeline-arm64-treatment-stability-r1 \
  BENCH=prefetch_pipeline_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=1000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：local build / AWS kernel micro
- x86 AWS instance type：`t3.small`
- ARM64 AWS instance type：`t4g.small`
- AWS region：`us-east-1`
- AWS remote user：`ec2-user`
- x86 CPU：`Intel(R) Xeon(R) Platinum 8259CL CPU @ 2.50GHz`
- kernel：`7.0.0-rc2+`
- x86 runtime image：`bpf-benchmark/runner-runtime:x86_64`
- ARM64 runtime image：`bpf-benchmark/runner-runtime:arm64`

AWS instances：

| arch | role | run token | instance id | state |
|---|---|---|---|---|
| x86 | control smoke | `pipeline-x86-control-smoke-rerun1` | `i-0b59fb48b6e65a99a` | terminated |
| x86 | treatment smoke | `pipeline-x86-treatment-smoke-rerun1` | `i-0a2436041dd1c24fc` | terminated |
| x86 | control stability | `pipeline-x86-control-stability-r1` | `i-0ae292f9d48da4b87` | terminated |
| x86 | treatment stability | `pipeline-x86-treatment-stability-r1` | `i-0c9ccafcc7759601d` | terminated |
| ARM64 | control smoke | `pipeline-arm64-control-smoke-rerun1` | `i-0be9e1c4e9e5a9c13` | terminated |
| ARM64 | treatment smoke | `pipeline-arm64-treatment-smoke-rerun1` | `i-0836bb3607c88c4d5` | terminated |
| ARM64 | control stability | `pipeline-arm64-control-stability-r1` | `i-0ec49b38f74ef5b68` | terminated |
| ARM64 | treatment stability | `pipeline-arm64-treatment-stability-r1` | `i-08fc9cd0578267046` | terminated |

费用估算：

- 价格来源：2026-06-02 使用 AWS Pricing API 查询 `us-east-1` Linux On-Demand 和 gp3 storage。
- `t3.small`：`$0.0208/hour`。
- `t4g.small`：`$0.0168/hour`。
- gp3 storage：`$0.08/GB-month`。
- root volume：按 runner 配置 `32 GiB` gp3 估算。
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| arch | total wall seconds | compute USD | EBS USD | total USD |
|---|---:|---:|---:|---:|
| x86 | 1439 | 0.008313 | 0.001421 | 0.009734 |
| ARM64 | 1356 | 0.006329 | 0.001339 | 0.007668 |
| total | 2795 | 0.014642 | 0.002760 | 0.017402 |

逐 instance wall time 和费用见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/analysis/aws-instance-summary.tsv
```

## 文件改动

本次涉及的相关文件：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.md`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/report.md`

## 数据文件

- `data/run-contract.json`
- `data/cargo-test-prefetch.log`
- `data/cargo-test-prefetch.stderr.log`
- `data/cargo-build-bpfopt-kinsnprober.log`
- `data/cargo-build-bpfopt-kinsnprober.stderr.log`
- `data/make-prefetch-upper-bound-object.log`
- `data/make-prefetch-upper-bound-object.stderr.log`
- `data/prefetch_upper_bound.objdump.log`
- `data/prefetch_upper_bound.objdump.stderr.log`
- `data/prefetch-pipeline-page-stride-profile-pc45-r1.json`
- `data/aws-check-x86-rerun.log`
- `data/aws-check-x86-rerun.stderr.log`
- `data/aws-check-arm64-rerun.log`
- `data/aws-check-arm64-rerun.stderr.log`
- `data/aws-x86-control-smoke-login-expired.log`
- `data/aws-x86-control-smoke-login-expired.stderr.log`
- `data/aws-x86-control-smoke-rerun1.log`
- `data/aws-x86-control-smoke-rerun1.stderr.log`
- `data/aws-x86-treatment-smoke-rerun1.log`
- `data/aws-x86-treatment-smoke-rerun1.stderr.log`
- `data/aws-x86-control-stability-r1.log`
- `data/aws-x86-control-stability-r1.stderr.log`
- `data/aws-x86-treatment-stability-r1.log`
- `data/aws-x86-treatment-stability-r1.stderr.log`
- `data/aws-arm64-control-smoke-rerun1.log`
- `data/aws-arm64-control-smoke-rerun1.stderr.log`
- `data/aws-arm64-treatment-smoke-rerun1.log`
- `data/aws-arm64-treatment-smoke-rerun1.stderr.log`
- `data/aws-arm64-control-stability-r1.log`
- `data/aws-arm64-control-stability-r1.stderr.log`
- `data/aws-arm64-treatment-stability-r1.log`
- `data/aws-arm64-treatment-stability-r1.stderr.log`
- `data/aws-instance-describe.json`
- `data/x86-control-smoke-rerun1-result/metadata.json`
- `data/x86-treatment-smoke-rerun1-result/metadata.json`
- `data/x86-control-stability-r1-result/metadata.json`
- `data/x86-treatment-stability-r1-result/metadata.json`
- `data/arm64-control-smoke-rerun1-result/metadata.json`
- `data/arm64-treatment-smoke-rerun1-result/metadata.json`
- `data/arm64-control-stability-r1-result/metadata.json`
- `data/arm64-treatment-stability-r1-result/metadata.json`
- `analysis/pipeline-profile-point-evidence.tsv`
- `analysis/stability-samples.tsv`
- `analysis/stability-summary.tsv`
- `analysis/aws-instance-summary.tsv`

## 问题和处理

初始 AWS attempt 失败：

```text
resolve AMI param /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-x86_64 failed:
aws: [ERROR]: Your session has expired. Please reauthenticate using 'aws login'.
```

处理：

- 保存失败 stdout / stderr 到 `data/`。
- 因失败发生在 AMI SSM 参数解析阶段，未创建 EC2 instance，不需要 terminate。
- 用户重新 AWS login 后，在同一实验目录内完成 x86 / ARM64 smoke 和 stability rerun。
- 所有后续 instance 都已 terminated。

计时注意事项：

- x86 treatment stability 的前两个样本 `wall_exec_ns` / `exec_cycles` 明显低于其余样本，
  与 `exec_ns` 的变化幅度不一致。因此 x86 的 `exec_ns` positive signal 不能单独作为强结论。
- ARM64 metadata 未提供 `wall_exec_ns` / `exec_cycles`，本轮 ARM64 只能用 `exec_ns`。

## 结果

本地验证结果：

| check | result |
|---|---|
| Rust prefetch tests | passed，14 个 prefetch tests 通过。 |
| `bpfopt` / `kinsnprober` release build | passed。 |
| `prefetch_upper_bound.bpf.o` Makefile object build | passed。 |
| object evidence | passed，profile point `pc=45, reg=1` 对应下一轮 pointer。 |

Object evidence 摘要：

| item | value |
|---|---|
| symbol start object PC | 250 |
| profile local PC | 45 |
| profile object PC | 295 |
| `next` pointer materialized | object PC 292-294 |
| current demand load starts | object PC 318 |
| lead time before current load | 23 BPF slots |

对应片段：

```text
292: r1 = *(u64 *)(r10 - 0x50)
293: r1 += r7
294: *(u64 *)(r10 - 0x48) = r1
295: r9 = r2
...
318: w4 = *(u8 *)(r0 + 0x0)
```

profile:

```json
{
  "map_value_prefetch_points": [
    { "pc": 45, "reg": 1 }
  ]
}
```

Smoke correctness / codegen：

| arch | role | result | sites applied | native hint | status |
|---|---|---:|---:|---|---|
| x86 | control | `2999102902642040864` | 0 | none | passed |
| x86 | treatment | `2999102902642040864` | 1 | `prefetcht0 BYTE PTR [rdi]` | passed |
| ARM64 | control | `2999102902642040864` | 0 | none | passed |
| ARM64 | treatment | `2999102902642040864` | 1 | `prfm pldl1keep, [x0]` | passed |

Stability raw sample summary：

| arch | role | n | mean exec ns | min exec ns | max exec ns |
|---|---|---:|---:|---:|---:|
| x86 | control | 5 | 9362.800 | 9301 | 9457 |
| x86 | treatment | 5 | 9226.800 | 9160 | 9257 |
| ARM64 | control | 5 | 17839.000 | 16957 | 18488 |
| ARM64 | treatment | 5 | 15316.200 | 14942 | 16362 |

Paired ratio：

| arch | paired n | paired geomean T/C | paired mean T/C | interpretation |
|---|---:|---:|---:|---|
| x86 | 5 | 0.985484 | 0.985528 | weak positive signal，约快 1.45%，但计时源需复核。 |
| ARM64 | 5 | 0.858777 | 0.860951 | positive signal，约快 14.12%，需要 independent rerun / PMU-capable 复核。 |

ratio 小于 1 表示 treatment 更快。完整 raw samples 见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-attribution/analysis/stability-samples.tsv
```

## 后续

下一步不要直接把 profile-point next-iteration prefetch 变成 default policy。

2026-06-02 已完成一轮 independent rerun：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-pipeline-map-independent-rerun1/report.md
```

rerun 结论是：ARM64 treatment 方向仍然更快，但 effect size 不稳定。上一轮 ARM64 paired
geomean treatment/control 是 `0.858777`，independent rerun 是 `0.962181`。因此 P19 只能
记录为 positive direction reproduced，不能记录为稳定 `14%` speedup。

后续需要先做：

1. 对 `prefetch_pipeline_page_stride` 做更稳定的 ARM64-only rerun，例如更长 `INNER_REPEAT` 或更稳定的
   timing setting，确认 positive direction 是否可稳定复现。
2. 如果可能，换 PMU-capable 环境或 perf event 可用配置，验证 speedup 是否对应 cache miss / refill
   下降。
3. 把 profile-point 策略和自动 selector 策略区分清楚：本次是 hand-profiled best-case placement，
   还没有实现自动发现 next pointer 和插入点。
4. 设计 real-inspired case：让程序自然产生 `cur` / `next` pipeline，而不是只靠 synthetic-control。

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-upper-bound-map-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-pmu-attribution/report.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_upper_bound.md`

发现和处理：

- 本 report 原先停在 `blocked_by_aws_login`。用户重新 AWS login 后，已在同一实验目录下完成
  x86 / ARM64 smoke 和 stability rerun，并更新顶层结论。
- `docs/projects/kinsn/tasks/prefetch/plan.md` 和
  `docs/projects/kinsn/tasks/prefetch/policy-matrix.md` 中关于 P19 / next-iteration probe 的状态需要
  从 “AWS blocked” 更新为 “first-run positive signal；independent rerun positive direction but
  unstable effect size”。
- 后续 independent rerun 已完成，结论是 ARM64 positive direction reproduced，但 effect size
  unstable。已把本文 “后续” 从 “需要 independent rerun” 更新为 “需要更稳定 ARM64-only rerun /
  PMU-capable 归因”。
- 未删除旧实验或旧结论；same-iteration 结果仍有效。
- 本次未发现需要删除的临时 workaround。

是否重跑：

- 代码和 micro object 已做本地最小验证。
- AWS x86 / ARM64 smoke 和 5-sample stability run 已完成。
- 收尾只会修改 report / docs，不再改代码行为，因此不需要再次重跑。

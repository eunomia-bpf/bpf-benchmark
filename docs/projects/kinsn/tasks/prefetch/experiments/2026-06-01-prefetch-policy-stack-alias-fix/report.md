# 2026-06-01 prefetch-policy-stack-alias-fix

## 结论

状态：`completed`.

本实验修复了 Kinsn prefetch policy 对真实 micro bytecode 的两个 coverage blocker：

- packet data / map value pointer 经 stack spill / reload 后，旧 policy 会丢失 pointer alias。
- packet/map target address 使用 register offset 后，旧 policy 无法继续追踪 pointer fact。

最终保守版修复后，local release `bpfopt` 和 x86 AWS `kernel` micro runtime 都能对两个代表 case
应用 prefetch：

| case | runtime | sites matched | sites applied | status |
|---|---|---:|---:|---|
| `prefetch_packet_first_deref` | AWS x86 `kernel` | 1 | 1 | completed |
| `prefetch_map_page_stride` | AWS x86 `kernel` | 1 | 1 | completed |

中间 permissive 版本曾通过 x86 AWS `kernel` smoke，但最终版为了降低跨 block register-state 误报风险，
恢复了 packet register fact boundary reset，只保留跨 block stack alias。第一次最终版 AWS rerun 在
EC2 reboot 阶段失败，原因是本地 AWS token 过期 / `RequestExpired`，不是 benchmark 或 verifier 失败。
重新登录后已确认并 terminate 残留 instance，然后补跑最终版 AWS smoke。

这一步证明 policy coverage 和 x86 kernel runtime application path 已经打通。它不是 prefetch
performance win 结论。

## 实验问题

上一轮 `prefetch-micro-kernel-pass-path-fix` 证明 `BPFREJIT_BENCH_PASSES=prefetch` 已经会调用
`bpfopt --pass prefetch`，但两个代表 case 都是 `sites_applied=0`。本轮要回答：

1. policy miss 是 runner / kfunc / kernel loader 问题，还是 prefetch policy 识别能力问题？
2. 修复后，最终保守版 policy 是否能在本地对代表 raw bytecode 生成 transformed bytecode？
3. x86 AWS kernel runtime 是否能接受最终 transformed bytecode 并返回正确结果？

结论：问题来自 prefetch policy 的既有限制，不是本轮 runner path fix 引入的，也不是 kfunc ABI
问题。三个问题均已解决。

## 改动

代码改动集中在：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs
```

主要修复：

- map value pointer 支持 stack spill / reload alias。
- packet data pointer 支持 stack spill / reload alias。
- map 和 packet pointer 在 `ADD/SUB X` register offset 后继续保留 pointer fact。
- packet policy 跨 block 保留 stack alias，但在不安全 boundary 重置 register facts，避免跨 block
  register-state 误报。
- map scan 不再因为 loop `ja` 提前停止。
- candidate 只针对 load，不针对 store。
- 同一 pointer definition、同一 64-byte cache line 的重复 load 只保留一个 prefetch candidate。

新增单元测试覆盖：

- `prefetch_tracks_map_value_stack_spill_and_register_offset`
- `prefetch_tracks_packet_stack_spill_and_register_offset`
- `prefetch_deduplicates_same_cacheline_packet_loads`
- `prefetch_ignores_packet_stores`

文档更新：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md
```

完整 diff 见：

```text
data/code-diff.patch
```

## 验证

本地验证：

| check | result | log |
|---|---|---|
| `cargo test --manifest-path code/bpfopt/crates/bpfopt/Cargo.toml prefetch -- --nocapture` | passed，8 个 prefetch tests 通过 | `data/cargo-test-prefetch.log` |
| `cargo build --manifest-path code/bpfopt/crates/bpfopt/Cargo.toml --release --bin bpfopt` | passed | `data/cargo-build-bpfopt-release.log` |

本地 release `bpfopt` 对 debug raw input 的结果：

| case | sites matched | sites applied | insn before | insn after | delta |
|---|---:|---:|---:|---:|---:|
| packet | 1 | 1 | 135 | 137 | 2 |
| map | 1 | 1 | 109 | 111 | 2 |

AWS x86 kernel smoke 最终结果：

| case | result dir | exec_ns | jited bytes | xlated bytes | sites applied |
|---|---|---:|---:|---:|---:|
| `prefetch_packet_first_deref` | `data/aws-results/aws_x86_micro_20260601_220320_641310` | 2410 | 595 | 1096 | 1 |
| `prefetch_map_page_stride` | `data/aws-results/aws_x86_micro_20260601_221126_145484` | 7997 | 498 | 936 | 1 |

AWS x86 kernel smoke 中间 permissive 版本也保留在 raw data 中，只用于解释为什么最终版从
packet 2 个 site 收紧到 1 个 site：

```text
data/aws-results/aws_x86_micro_20260601_114201_001026
data/aws-results/aws_x86_micro_20260601_114839_347362
```

第一次最终版 AWS rerun 的失败状态也保留在：

```text
data/aws-failed-rerun/packet-rerun-instance.json
data/aws-failed-rerun/README.txt
```

原始 summary：

```text
analysis/local-bpfopt-summary.tsv
analysis/aws-smoke-summary.tsv
```

## AWS

使用 AWS x86 micro 默认配置：

- instance type：`t3.small`
- region：`us-east-1`
- profile：`default`
- root volume：32 GiB

Instance 状态：

| instance | case | final state |
|---|---|---|
| `i-0f7fc0f3f4c735119` | `prefetch_packet_first_deref` | terminated |
| `i-0c742b49f93531e72` | `prefetch_map_page_stride` | terminated |
| `i-0371a7ae35a6b706b` | failed final packet rerun | terminated |
| `i-0fe34d545ff82c5d3` | final `prefetch_packet_first_deref` | terminated |
| `i-083bba4b087515321` | final `prefetch_map_page_stride` | terminated |

费用估算：

- 最终两个 AWS smoke EC2 runtime 约 0.202 小时，按 `t3.small` Linux us-east-1 `$0.0208/hour`，
  约 `$0.0042`。
- 失败 rerun 在 token 过期后曾停在 `stopped`，重新登录后已 terminate；EBS 保留时间约 10 小时量级，
  粗估约 `$0.036`。
- 本轮包含中间 smoke、失败 rerun 和最终 smoke，合计粗估约 `$0.045` 到 `$0.05`。
- 费用估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## 结果解释

这次修复说明：当前 representative prefetch micro 的 policy miss，是因为真实 BPF bytecode 不保持
“pointer 一直在同一个寄存器中直接被 load 使用”的简单形态。编译后的 micro 会：

- 把 `ctx->data` / map lookup returned value spill 到 stack。
- reload 到 callee-saved 或临时寄存器。
- 用 register offset 计算目标地址。
- 在 loop / branch shaped code 后才执行实际 deref。

旧 policy 只做 register-local alias，所以看到 transformed bytecode 时无法定位 candidate。
这不是 prefetch 策略有效性的正面证据，只是让后续 attribution 可以真的测到 transformed program。

实现上还有一个安全性约束：不能为了命中 packet case 而无条件跨 block 传播 register facts。最终实现只跨
block 保留 stack alias，并在不安全 block boundary 重置 register facts。这样会把 packet case 从 2 个
candidate 收紧到 1 个 candidate，但降低了误报风险。

## 后续

下一步应做 x86 `PREFETCHT0` paired treatment/control attribution：

1. 同一 AWS x86 配置下跑 control：`BPFREJIT_BENCH_PASSES=noop` 或明确禁用 prefetch。
2. 跑 treatment：`BPFREJIT_BENCH_PASSES=prefetch`。
3. 至少覆盖 `prefetch_packet_first_deref` 和 `prefetch_map_page_stride`。
4. 每个 case 至少做多轮 independent run，报告 raw sample、ratio、codegen evidence 和 variance。

只有 attribution 表明 treatment 相对 control 稳定更快，才能继续讨论 prefetch policy 默认启用或
selector v2 扩展。

## 收尾一致性复查

已回看：

- `experiments/2026-06-01-prefetch-micro-kernel-pass-path-fix/report.md`
- `docs/projects/kinsn/tasks/prefetch/plan.md`
- 本轮 AWS result 和 bpfopt pass report

发现和处理：

- prefetch plan 中“policy 仍然 0 hit”的状态已过时，已更新为本轮 stack-alias fix 后的状态。
- 本轮没有修改 benchmark framework 的 measurement aggregation 逻辑；只改 bpfopt policy 和 tests。
- 最终版第一次 AWS rerun 因 AWS token 过期未完成；已把失败状态记录到 `data/aws-failed-rerun/`。
- 重新登录后已确认并 terminate 残留 instance，并补跑最终版 packet/map AWS smoke。
- 未提交、未 push。

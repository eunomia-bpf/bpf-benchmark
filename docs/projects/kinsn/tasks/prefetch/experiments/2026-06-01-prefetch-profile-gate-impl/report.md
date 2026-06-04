# 2026-06-01 prefetch-profile-gate-impl

## 结论

本实验完成 Kinsn prefetch 的 map-value profile gate 第一版实现。

结论：

- `bpfopt --pass prefetch` 现在支持 pass-local profile side input：
  `-- --profile /path/to/prefetch-profile.json`。
- 没有 profile 时，map-value first deref 仍然跳过，skip reason 保持为
  `map value prefetch requires profile or PMU evidence ...`。
- profile 明确允许某个 map-value load PC 后，该 site 可以通过 admission 并插入 prefetch kinsn。
- targeted Rust tests 通过：`13 passed`。

这一步只证明 admission gate 和 parser 正确，不证明 map-value prefetch 有性能收益。

## 实验问题

要回答的问题：

```text
Kinsn prefetch policy 能否把 map-value prefetch 从 structural-only admission 改成 profile/PMU-gated admission？
```

具体成功标准：

- 默认无 profile 时，map-value candidate 不能被应用。
- profile allow-list 或 PMU-style metrics 指定该 PC 时，map-value candidate 可以被应用。
- 现有 packet first-deref selector v3 行为不回退。

## 命令

从 `/home/ruoji/github/bpf-opt/code/bpfopt` 执行：

```bash
cargo test -p bpfopt prefetch
cargo fmt -p bpfopt --check
```

原始 log：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl/data/cargo-test-prefetch.log
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl/data/cargo-test-prefetch.stderr.log
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- code HEAD：`d9f007575bda699f0ddb154abd37cf80bcd1b120`
- platform：local Rust unit test
- AWS：未使用；无 EC2 instance、无 AWS wall time、无 AWS 费用。

## 文件改动

代码改动：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/mod.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`

文档和实验记录：

- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl/data/run-contract.json`

## 实现内容

`PrefetchPass` 从 unit struct 改成带 profile gate 的 pass：

```text
PrefetchPass { profile: PrefetchProfileGate }
```

registry 里 `prefetch` 不再拒绝 pass-local args，而是调用：

```text
PrefetchPass::from_cli_args
```

profile JSON 支持两种输入：

```json
{
  "map_value_pcs": [2]
}
```

或：

```json
{
  "min_load_misses": 10,
  "min_miss_rate": 0.10,
  "map_value_sites": [
    { "pc": 2, "load_misses": 12, "miss_rate": 0.25 }
  ]
}
```

admission 规则：

- `Packet` source 继续走 selector v3 structural gate。
- `MapValue` source 先用 `report_site_pc()` 得到原始 BPF PC。
- 只有 profile gate 允许该 PC 时才应用 prefetch。
- profile 不包含该 PC 时跳过。

## 数据文件

- `data/run-contract.json`
- `data/cargo-test-prefetch.log`
- `data/cargo-test-prefetch.stderr.log`

## 问题和处理

- 现有 `PassContext.annotations` 只支持 branch profile，并且只挂到 terminator site。不能拿它表示
  load miss / PMU 数据。
- 处理方式：给 prefetch pass 增加独立 pass-local profile side input，避免混用 branch profile。
- 第一次保存 test log 时相对路径写到了 `/home/ruoji/github/bpf-opt/code/bpfopt/experiments`；
  该空错误目录由本次操作创建，已删除，随后用绝对路径重新保存 log。

## 结果

`cargo test -p bpfopt prefetch`：

```text
13 passed; 0 failed; 0 ignored
```

`cargo fmt -p bpfopt --check`：通过。

新增关键测试：

- `prefetch_allows_map_value_with_profile_gate`
- `prefetch_allows_map_value_with_pmu_profile_metrics`

保留关键回归：

- `prefetch_skips_map_value_without_profile_gate`
- packet first-deref、ALU32 index math、cacheline dedup、two-stage skip 等 selector v3 测试仍通过。

## 后续

下一步应做 profile-fed AWS attribution：

1. 为 `prefetch_map_page_stride` 生成 profile JSON，明确 allow map-value load PC。
2. 通过 Makefile 入口跑 x86 和 ARM64 same-LLC treatment/control。
3. 在 report 中同时记录 applied sites、native `prefetcht0` / `prfm` evidence、runtime 和 PMU/cycles
   口径。
4. 如果 profile-fed map-value 仍然 slow 或 mixed，map-value prefetch 保持 research-only。

## 收尾一致性复查

已回看：

- 当前 prefetch task 文档：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md`
  和 `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`。
- 相关前序实验：
  `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-packet-first-deref-v3-attribution/report.md`。
- 当前代码测试：
  `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`。

发现和处理：

- 文档仍写着 profile/PMU gate 未实现。已更新为 gate 已实现，但 profile-fed AWS attribution 未跑。
- 未发现需要删除的临时代码或 workaround。
- 本次只跑本地 targeted Rust tests，没有使用 AWS。

# 2026-06-01 prefetch-selector-v3-policy-smoke

## 结论

本实验完成，状态是 `completed`。

结论：

- selector v2 失败原因已确认：它能识别 packet load，但没有把 packet-derived scalar
  dependency 通过 32-bit `MOV/AND/LSH` index math 传播到 final dereference，所以
  `prefetch_single_first_deref` 和 `prefetch_packet_first_deref` 都没有插入 prefetch。
- selector v3 修复后，x86 和 ARM64 AWS kernel smoke 都通过：
  `prefetch_single_first_deref` 与 `prefetch_packet_first_deref` 各应用 1 个 prefetch site。
- `prefetch_map_page_stride` 在 x86 和 ARM64 上都保持 0 个 applied site，skip reason 是
  `map value prefetch requires profile or PMU evidence`。这符合当前 policy：map value
  structural candidate 不能默认启用，必须等 profile/PMU evidence。
- 本实验是 policy/correctness smoke，不是 performance attribution。它证明 v3 selector 的
  admission 行为正确，不证明 prefetch 已经是性能收益。

## 实验问题

本实验要回答：

1. v2 为什么没有命中 packet first-deref final load？
2. v3 是否能在真实 AWS kernel runtime 上对 packet first-deref 应用 prefetch？
3. v3 是否仍然拒绝没有 profile/PMU evidence 的 map value prefetch？
4. x86 `PREFETCHT0` 和 ARM64 `PRFM PLDL1KEEP` 是否在同一 BPF-level policy 下表现一致？

## 子实验

| 子目录 | 结论 |
|---|---|
| `attempts/v2-x86-smoke` | runtime 正确，但 packet cases applied 0；定位为 v2 tracking coverage gap。 |
| `attempts/v3-x86-smoke` | runtime 正确；packet cases applied 1；map case skipped。 |
| `attempts/v3-arm64-smoke` | runtime 正确；packet cases applied 1；map case skipped。 |

## 命令

工作目录：

```text
/home/ruoji/github/bpf-opt
```

本地验证：

```bash
cd /home/ruoji/github/bpf-opt/code
cargo fmt --package bpfopt
cargo test -p bpfopt prefetch -- --nocapture
cargo check -p bpfopt
make host-rust-x86
```

x86 v2 smoke：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh x86 micro \
  BENCH='prefetch_single_first_deref prefetch_packet_first_deref prefetch_map_page_stride' \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

x86 v3 smoke：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh x86 micro \
  BENCH='prefetch_single_first_deref prefetch_packet_first_deref prefetch_map_page_stride' \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

ARM64 v3 smoke：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh arm64 micro \
  BENCH='prefetch_single_first_deref prefetch_packet_first_deref prefetch_map_page_stride' \
  BPFREJIT_BENCH_PASSES=prefetch \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

清理检查：

```bash
cd /home/ruoji/github/bpf-opt
./aws-config/run.sh x86 terminate
./aws-config/run.sh arm64 terminate
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- selector：`/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- micro manifest：`/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- x86 instance type：`t3.small`
- ARM64 instance type：`t4g.small`
- AWS region：`us-east-1`
- remote user：`ec2-user`
- kernel release：`7.0.0-rc2+`
- x86 container image：`bpf-benchmark/runner-runtime:x86_64`
- ARM64 container image：`bpf-benchmark/runner-runtime:arm64`

AWS instance metadata note：

- ARM64 wrapper stdout recorded instance `i-0e0c054c748dd56d8` entering `shutting-down`.
- x86 instance ids were not preserved in runner result metadata and could not be recovered from tag lookup after cleanup.
- Result metadata records benchmark `started_at` / `completed_at`, but not full EC2 launch / terminate wall time.

## AWS 时间和费用

Benchmark metadata time：

| attempt | result dir | started_at UTC | completed_at UTC |
|---|---|---|---|
| v2 x86 | `aws_x86_micro_20260602_002724_881164` | `2026-06-02T00:27:24.881164+00:00` | `2026-06-02T00:27:27.737838+00:00` |
| v3 x86 | `aws_x86_micro_20260602_003936_999378` | `2026-06-02T00:39:36.999378+00:00` | `2026-06-02T00:39:40.150527+00:00` |
| v3 arm64 | `aws_arm64_micro_20260602_004655_302145` | `2026-06-02T00:46:55.302145+00:00` | `2026-06-02T00:46:58.144751+00:00` |

费用估算：

- 这里只能给 lower-bound estimate，因为 EC2 launch / terminate timestamp 没有写入 result metadata。
- 按公开 us-east-1 Linux On-Demand 价格近似计算：`t3.small ~= $0.0208/hour`，
  `t4g.small ~= $0.0168/hour`。
- 若只按 EC2 Linux per-second billing 的 60 秒最低计费估算：
  x86 两次合计约 `$0.00069`，ARM64 一次约 `$0.00028`，compute lower-bound 合计约 `$0.00097`。
- 这个估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances、
  账户级折扣，也不准确反映本地构建、镜像传输和实例 provision 的真实 wall time。
- Root volume 是 32 GB；本实验生命周期短，EBS lower-bound 远低于 1 美分，但由于没有精确
  EC2 wall time，这里不单独声称精确 EBS cost。

后续应修 runner metadata：把 instance id、launch time、terminate time、instance type 和 root volume
写入 result metadata，避免 AWS 费用记录依赖 terminal stdout。

## 文件改动

代码：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.md`

文档和实验记录：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/attempts/*/report.md`

## 数据文件

完整 AWS result 副本：

- `attempts/v2-x86-smoke/data/aws_x86_micro_20260602_002724_881164`
- `attempts/v3-x86-smoke/data/aws_x86_micro_20260602_003936_999378`
- `attempts/v3-arm64-smoke/data/aws_arm64_micro_20260602_004655_302145`

分析表：

- `data/run-contract.json`
- `analysis/pass-summary.tsv`
- `analysis/runtime-summary.tsv`

## 问题和处理

问题：v2 packet selector 没有命中 final deref。

具体原因：

- Clang 为 `prefetch_single_first_deref` 生成的 BPF 先从 packet 读取 index，再经过
  32-bit `MOV/AND/MOV/LSH` 计算 offset，最后做 `data + offset` 并 load final target。
- v2 只追踪 packet pointer 和直接 packet load，没有把 packet-derived scalar 通过 32-bit ALU
  instruction 继续传播。
- 因此 v2 把 address-source load 当成 depth 0，不承认后面的 final dereference 是
  data-dependent packet first deref。

修复：

- 在 prefetch pass 中加入 `PacketScalar` tracking。
- 让 32-bit `MOV/AND/LSH` 保留 packet-derived scalar dependency。
- 让 packet pointer + packet-derived scalar 形成 `dependent_load_depth=1` 的 candidate。
- 加入 program-level site budget：当前每个 program 最多保留 1 个 prefetch site。
- 对 map value structural candidate 加 profile/PMU gate，默认 skip。

## 结果

Pass behavior：

| attempt | arch | case | applied | skipped | 结论 |
|---|---|---:|---:|---:|---|
| v2 | x86 | `prefetch_single_first_deref` | 0 | 9 | 失败：没有命中 final deref。 |
| v2 | x86 | `prefetch_packet_first_deref` | 0 | 9 | 失败：没有命中 final deref。 |
| v2 | x86 | `prefetch_map_page_stride` | 0 | 1 | 符合当前 map profile/PMU gate。 |
| v3 | x86 | `prefetch_single_first_deref` | 1 | 1 | 通过。 |
| v3 | x86 | `prefetch_packet_first_deref` | 1 | 1 | 通过。 |
| v3 | x86 | `prefetch_map_page_stride` | 0 | 1 | 符合当前 map profile/PMU gate。 |
| v3 | ARM64 | `prefetch_single_first_deref` | 1 | 1 | 通过。 |
| v3 | ARM64 | `prefetch_packet_first_deref` | 1 | 1 | 通过。 |
| v3 | ARM64 | `prefetch_map_page_stride` | 0 | 1 | 符合当前 map profile/PMU gate。 |

Runtime correctness：

- 三个 attempts 的所有 benchmark `result == expected_result`。
- x86 v3 packet treatment bytecode 增加 16 bytes，符合插入一个 kinsn call sequence 的预期。
- ARM64 v3 packet treatment bytecode 同样增加 16 bytes。

## 策略选择解释

当前 prefetch strategy 不是从单次 benchmark 结果拍脑袋选出来的，而是按下面链条收敛：

1. Literature review 给出基本约束：prefetch 是 hint，不改变语义；默认插入容易因为 hot data、
   hardware prefetcher overlap、cache pollution 和 bandwidth pressure 变慢。
2. Micro policy matrix 把候选拆成 packet first deref、map first deref、sequential、hot L1、
   indirect、guarded offset、large stride、cacheline dedup、site budget 等。
3. 多轮 ARM64/x86 micro attribution 显示 structural-only policy 不稳定，不能默认启用。
4. v3 只保留最保守的可解释 candidate：packet first deref，并把 map value candidate 放到
   profile/PMU gate 后面。

最终当前可解释策略：

- **允许**：packet first deref，且 final load 依赖 packet 中读出的 index，depth 必须是 1，
  插入点必须在 verifier-safe window 内，每个 program 只保留一个 site。
- **拒绝**：address-source load 自身、dependent chain depth 0、dependent chain depth > 1、
  map value structural candidate、重复 cacheline、超过 site budget 的 candidate。

这个策略适合 Kinsn 场景的原因：

- 它在 BPF bytecode 层工作，不依赖 LLVM IR 或 C source。
- 它只插 verifier-safe hint，不删除原始 load，所以语义安全。
- 它只承认有潜在 latency hiding 价值的 final deref，而不是在每个 load 前插 prefetch。
- 它跨 x86 和 ARM64 共享 policy，架构差异只在 target native hint：x86 是 `PREFETCHT0`，
  ARM64 是 `PRFM PLDL1KEEP`。

例子：

```c
u32 index = data[key_off] & 63;
const u8 *ptr = data + base + index * 8;
if (ptr + 8 > data_end)
    return XDP_ABORTED;

acc = independent_mix(acc, index);
u64 value = *(u64 *)ptr;
```

v3 只对 `value = *(u64 *)ptr` 的 final deref 插 prefetch，不对 `data[key_off]` 插。
这样做的理由是：`data[key_off]` 是计算地址所需的 source load，prefetch 它已经太晚；
final deref 是 index-dependent target，有机会在 independent work 期间提前把 cacheline 拉近。

## 后续

下一步不应继续扩大 structural candidate。应该做：

1. 对 v3 packet first-deref 做 independent multi-run same-LLC attribution，确认收益是否稳定。
2. 增加 PMU/profile evidence path，再重新评估 map value prefetch。
3. 如果 packet first-deref 没有稳定收益，保持 prefetch forced-only / research-only。
4. 修 runner AWS metadata，保存 instance id、launch time、terminate time 和 root volume 信息。

## 收尾一致性复查

已回看：

- v2 x86 smoke 失败尝试。
- v3 x86 smoke。
- v3 ARM64 smoke。
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`
- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.md`
- 前序 prefetch 实验目录列表。

发现和处理：

- `plan.md` 仍写着 map page stride 可应用 1 个 site。已更新为 v3 默认 skip，并说明需要
  profile/PMU evidence。
- `policy-matrix.md` 仍把 v2 当作建议状态。已更新为当前 v3 状态，并补充策略选择依据、
  safety 条件、test case 例子和未完成 gate。
- `prefetch_research.md` 仍写 v2 raw-bytecode 检查发现旧 policy 不足。已更新为 v3 smoke 结果。
- 未发现需要删除的 prefetch v3 代码；v2 失败对应的是 tracking coverage gap，已由
  `PacketScalar` 和 ALU32 transfer test 覆盖。

是否重跑：

- 本次代码改动后已重跑 `cargo test -p bpfopt prefetch -- --nocapture`、`cargo check -p bpfopt`、
  `make host-rust-x86`。
- 已重跑 AWS x86 smoke 和 AWS ARM64 smoke，均通过。

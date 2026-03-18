# Micro Round 3 Optimization (2026-03-18)

基于：

- `docs/tmp/micro_further_optimization_20260318.md`
- `docs/kernel-jit-optimization-plan.md`
- VM 流程：`make vm-micro`

## 1. 最终 policy 状态

本轮最终收敛到：

- `cmov_select`：清空 `sites: []`
- `mixed_alu_mem`：清空 `sites: []`
- `branch_fanout_32`：清空 `sites: []`
- `imm64_storm`：不挂 `policy_file`，不进入默认 applied set

保留的 applied benchmark 数从 `9` 降到 `7`。

本轮**没有**把 `mega_basic_block_2048` 加入默认 policy。原因不是“已证伪”，而是当前 VM session 已经出现明显测量漂移，继续引入新的 dense candidate 没有可靠解释价值。

## 2. 迭代过程

### 2.1 第一轮 subset

命令：

```bash
make vm-micro BENCH='cmov_select mixed_alu_mem imm64_storm branch_fanout_32 rotate_dense rotate64_hash cmov_dense' ITERATIONS=5 WARMUPS=3 REPEAT=500
```

结果摘要：

| Benchmark | Ratio (recompile/kernel) | 说明 |
| --- | ---: | --- |
| `cmov_select` | `1.076` | 清空后仍是 non-applied 噪声 |
| `mixed_alu_mem` | `0.900` | `wide-only` 首轮看起来正向 |
| `imm64_storm` | `1.123` | 当时其实**没生效**（缺 `policy_file`） |
| `branch_fanout_32` | `0.786` | 当时也**没真正 applied**（live path 选中 0 site） |

发现两个问题：

1. `imm64_storm` 在 `config/micro_pure_jit.yaml` 里没有 `policy_file`，第一轮不是有效验证。
2. `branch_fanout_32` 虽然 policy 文件存在，但 live path 仍然 `0 site selected`。历史档案也显示它在 `8/9 rotate` 时会 `BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)`，因此不能作为稳定新增项。

### 2.2 第二轮 subset

调整：

- 给 `imm64_storm` 临时挂上 `policy_file`
- 把 `branch_fanout_32` 恢复为空 policy

命令：

```bash
make vm-micro BENCH='cmov_select mixed_alu_mem imm64_storm branch_fanout_32' ITERATIONS=5 WARMUPS=3 REPEAT=500
```

结果：

| Benchmark | Ratio | Applied | Sites |
| --- | ---: | ---: | ---: |
| `cmov_select` | `1.058` | `no` | `0` |
| `mixed_alu_mem` | `0.993` | `yes` | `1` |
| `imm64_storm` | `1.252` | `yes` | `64` |
| `branch_fanout_32` | `0.966` | `no` | `0` |

结论：

- `imm64_storm rotate-only` 是明确负向，清掉。
- `mixed_alu_mem wide-only` 不稳定，按保守规则清掉。
- `branch_fanout_32` 继续保持 empty；这不是稳定 winner。

### 2.3 最终态确认 subset

命令：

```bash
make vm-micro BENCH='cmov_select mixed_alu_mem imm64_storm branch_fanout_32' ITERATIONS=3 WARMUPS=3 REPEAT=500
```

确认：

| Benchmark | Applied | Sites |
| --- | ---: | ---: |
| `cmov_select` | `no` | `0` |
| `mixed_alu_mem` | `no` | `0` |
| `imm64_storm` | `no` | `0` |
| `branch_fanout_32` | `no` | `0` |

对应 artifact：

- `micro/results/dev/vm_micro_subset_round3_finalstate_20260318.json`

## 3. 全量结果

命令：

```bash
make vm-micro ITERATIONS=5 WARMUPS=3 REPEAT=1000
```

结果文件：

- `micro/results/dev/vm_micro_round3_optimization_20260318.json`

### 3.1 直接基于本次 JSON 重算

我用 benchmark-level `median(exec_ns_kernel-recompile) / median(exec_ns_kernel)` 重新计算 geomean：

| Metric | Ratio Geomean | Speedup Geomean |
| --- | ---: | ---: |
| Overall | `0.962` | `1.039x` |
| Applied-only (`7` benches) | `0.933` | `1.072x` |
| Non-applied | `0.966` | `1.035x` |

当前 applied set：

| Benchmark | Ratio | Sites |
| --- | ---: | ---: |
| `rotate_dense` | `0.788` | `256` |
| `rotate64_hash` | `0.917` | `116` |
| `cmov_dense` | `0.868` | `26` |
| `large_mixed_500` | `0.973` | `7` |
| `large_mixed_1000` | `0.911` | `7` |
| `bpf_call_chain` | `0.988` | `2` |
| `bounds_ladder` | `1.122` | `4` |

### 3.2 与旧 headline 的对比

用户给的旧权威 headline 是：

- overall `1.024x`
- applied-only `1.118x`

按这个口径比较，本轮 dev run：

- overall：`1.024x -> 1.039x`，表面上升 `+0.015x`
- applied-only：`1.118x -> 1.072x`，下降 `-0.046x`

也就是说：

- **按 overall headline 看是更好了**
- **按 applied-only headline 看是更差了**

## 4. 为什么 applied-only 没提升

根因不再是新加的 policy，而是**当前 VM session 的测量漂移已经大到会把旧 winner 测坏**。

为验证这一点，我又对当前 7 个 applied benchmark 做了一个专门 rerun：

```bash
make vm-micro BENCH='rotate_dense rotate64_hash cmov_dense large_mixed_500 bounds_ladder bpf_call_chain large_mixed_1000' ITERATIONS=5 WARMUPS=3 REPEAT=1000
```

结果文件：

- `micro/results/dev/vm_micro_applied_subset_rerun_20260318.json`

专门 rerun 的 ratio：

| Benchmark | Full 62-bench | Applied-subset rerun | Delta |
| --- | ---: | ---: | ---: |
| `rotate_dense` | `0.788` | `1.000` | `+0.212` |
| `rotate64_hash` | `0.917` | `1.026` | `+0.109` |
| `cmov_dense` | `0.868` | `1.579` | `+0.711` |
| `large_mixed_500` | `0.973` | `0.876` | `-0.097` |
| `bounds_ladder` | `1.122` | `0.914` | `-0.207` |
| `bpf_call_chain` | `0.988` | `1.100` | `+0.112` |
| `large_mixed_1000` | `0.911` | `0.927` | `+0.016` |

这个 applied-subset rerun 的 geomean 甚至是：

- ratio geomean `1.041`
- speedup geomean `0.961x`

这说明：

1. 当前 session 下，连 `cmov_dense` / `rotate64_hash` / `rotate_dense` 这类旧 winner 都不稳定。
2. 因此本轮 full run 的 applied-only 下降，**不能解释为 round-3 新 policy 失败**，因为新 policy 已经基本都被清掉了。
3. 真正的可归因结论只有：
   - `cmov_select` 应该清掉
   - `mixed_alu_mem` 应该清掉
   - `imm64_storm` rotate-only 不该加入
   - `branch_fanout_32` 仍然不稳定，不能加入

## 5. 结论

本轮 round-3 的**policy 决策**是清晰的：

- 成功清掉了两个已知 loss：`cmov_select`、`mixed_alu_mem`
- 证伪了一个新 rotate 候选：`imm64_storm`
- 再次确认 `branch_fanout_32` 目前不能稳定落地

但本轮 round-3 的**全量性能 headline**不适合升级为新的 authoritative：

- full 62-bench 看起来 overall `1.039x`
- 但 applied-only 只剩 `1.072x`
- 且 7-winner 专门 rerun 出现大幅漂移，说明当前 VM session 不稳定

因此建议：

1. 保留本轮 policy 清理结果。
2. 不要把 `micro/results/dev/vm_micro_round3_optimization_20260318.json` 提升成新的 authoritative。
3. 如果要继续 round-3/round-4，应先在更稳定的 VM session 上重新做一次 `7 applied` 子集确认，再决定是否尝试 `mega_basic_block_2048` budget sweep。

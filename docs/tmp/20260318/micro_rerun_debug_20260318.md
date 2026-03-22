# Micro rerun debug 2026-03-18

## 结论

- 这次没有复现 `rotate64_hash` 的负向反转。
- subset 先确认了方向为正：`64ns -> 54ns`，约 `+18.5%`。
- 干净全量 rerun 里，`rotate64_hash` 为 `84.5ns -> 63.0ns`，约 `+34.1%`。
- 全量结果质量达标：`applied-only = 1.1098x`，`non-applied = 1.0019x`，因此已将新结果复制到 `micro/results/vm_micro_authoritative_20260318.json`。

我能确认的最具体异常点不是“当前 build/obj 有问题”，而是“目录里原有的 `vm_micro_authoritative_20260318.json` 不是当前 policy 状态产物”：

- 旧文件（覆盖前）`policy_files_hash = 62744dba2c30a7d5`
- 这次新 rerun `policy_files_hash = 667ed0873980368f`
- 旧文件 applied bench 有 `9` 个，这次只有 `7` 个
- 旧文件里还有 `cmov_select` / `mixed_alu_mem` 两个 applied 项；当前 policy 已经清空，不再 apply

因此，“`rotate64_hash` 从 `+33%` 反转到 `-19%`”在本次排查里**没有被复现**。从现有证据看，更像是之前拿了不同 policy 状态或非权威噪声 run 在比较，而不是当前 `rotate64_hash` policy / bzImage / runner / BPF object 的真实回归。

## 1. 排查记录

### 1.1 没有其他 VM 在跑

命令：

```bash
ps aux | grep -E 'qemu|vng' | grep -v grep
```

结果：

- 初始检查为空，无其他 `qemu` / `vng` 进程
- 全量 rerun 期间仅看到当前这次 `vng + qemu-system-x86_64`

### 1.2 `rotate64_hash` policy 正确且非空

命令：

```bash
cat micro/policies/rotate64_hash.yaml
rg '^  - insn:' micro/policies/rotate64_hash.yaml | wc -l
```

结果：

- `program: 'rotate64_hash_xdp'`
- site 数量精确计数为 `116`
- 不是空 policy

### 1.3 关键产物时间戳

命令：

```bash
ls -la vendor/linux-framework/arch/x86/boot/bzImage
ls -la micro/build/runner/micro_exec
ls -la micro/programs/rotate64_hash.bpf.o
```

结果：

| Artifact | Timestamp |
| --- | --- |
| `vendor/linux-framework/arch/x86/boot/bzImage` | `Mar 13 20:02` |
| `micro/build/runner/micro_exec` | `Mar 13 20:01` |
| `micro/programs/rotate64_hash.bpf.o` | `Mar 11 20:13` |

说明：

- `rotate64_hash.bpf.o` 时间戳确实比 `bzImage` / `micro_exec` 更早
- 但这次 subset 和 full rerun 都确认它在运行时确实命中 `116` 个 live rotate sites，且收益是正向的
- 所以“对象文件时间戳偏早”这件事本身**不是这次反转的直接证据**

## 2. Subset 复核

命令：

```bash
make vm-micro BENCH='rotate64_hash rotate_dense cmov_dense' ITERATIONS=3 WARMUPS=2 REPEAT=500
```

结果摘要：

| Benchmark | kernel | kernel-recompile | K/KR |
| --- | --- | --- | --- |
| `rotate64_hash` | `64ns` | `54ns` | `1.185x` |
| `rotate_dense` | `229ns` | `188ns` | `1.218x` |
| `cmov_dense` | `75ns` | `60ns` | `1.250x` |

判断：

- `rotate64_hash` 当场就是正向，不满足“subset 仍然反转”的深挖分支
- 因此按计划直接进入全量 rerun

## 3. 干净全量 rerun

命令：

```bash
make vm-micro ITERATIONS=10 WARMUPS=5 REPEAT=1000
```

运行提示：

- 宿主提示 `CPU governor is 'unknown'`
- Turbo boost 开启
- 未显式绑核

这些提示意味着环境不算 strict-lab，但这次关键质量指标仍然足够干净。

### 3.1 新结果摘要

文件：

- `micro/results/dev/vm_micro.json`
- 已复制到 `micro/results/vm_micro_authoritative_20260318.json`

provenance：

- `generated_at = 2026-03-18T23:10:25.262807+00:00`
- `policy_files_hash = 667ed0873980368f`

suite 指标：

| Metric | Value |
| --- | --- |
| benchmark count | `62` |
| applied count | `7` |
| non-applied count | `55` |
| overall `K/KR` geomean | `1.0136x` |
| applied-only `K/KR` geomean | `1.1098x` |
| non-applied `K/KR` geomean | `1.0019x` |

质量判断：

- `applied-only > 1.10x`：满足
- `non-applied` 接近 `1.0`：满足
- 因此这次 run 可作为当前 policy 状态下的 authoritative 结果

### 3.2 `rotate64_hash` 结果

| Field | Value |
| --- | --- |
| policy file | `micro/policies/rotate64_hash.yaml` |
| live selected sites | `116` |
| kernel median | `84.5ns` |
| kernel-recompile median | `63.0ns` |
| `K/KR` | `1.3413x` |
| speedup | `+34.1%` |

这与“反转为 `-19%`”完全相反，而且非常接近你原先怀疑应该看到的 `+33%` 量级。

### 3.3 Applied wins / losses

Applied bench 共 `7` 个：

| Benchmark | K/KR | 备注 |
| --- | --- | --- |
| `rotate_dense` | `1.3912x` | 大幅正向 |
| `rotate64_hash` | `1.3413x` | 大幅正向 |
| `cmov_dense` | `1.1500x` | 正向 |
| `large_mixed_500` | `1.0154x` | 轻微正向 |
| `large_mixed_1000` | `1.0141x` | 轻微正向 |
| `bounds_ladder` | `0.9718x` | 轻微负向 |
| `bpf_call_chain` | `0.9656x` | 轻微负向 |

整体 applied-only 仍然达到 `1.1098x`，说明 headline 质量是好的。

### 3.4 Non-applied 噪声

尽管 suite-level `non-applied` geomean 已经很干净（`1.0019x`），单个短 benchmark 仍有 outlier：

| Benchmark | K/KR |
| --- | --- |
| `load_native_u64` | `0.7062x` |
| `fixed_loop_small` | `1.2365x` |
| `packet_redundant_bounds` | `1.1926x` |
| `cond_select_dense` | `1.1746x` |
| `packet_parse` | `1.1722x` |

因此这次结果适合当当前 policy 的 authoritative suite 结果，但仍不该把个别极短 benchmark 的单点偏移过度解读为“优化效果”。

## 4. 为什么我认为旧 `20260318` authoritative 文件是 stale policy 状态

在覆盖前，我先读取了目录里已有的 `micro/results/vm_micro_authoritative_20260318.json`。它和这次新 rerun 有明确不一致：

| Item | 旧文件 | 新 rerun |
| --- | --- | --- |
| `generated_at` | `2026-03-18T18:57:25.500347+00:00` | `2026-03-18T23:10:25.262807+00:00` |
| `policy_files_hash` | `62744dba2c30a7d5` | `667ed0873980368f` |
| applied count | `9` | `7` |
| `rotate64_hash` K/KR | `1.1707x` | `1.3413x` |
| applied set | 含 `cmov_select` / `mixed_alu_mem` | 两者都不再 apply |

当前 on-disk policy 也支持这个判断：

- `micro/policies/cmov_select.yaml` 现在是 `sites: []`
- `micro/policies/mixed_alu_mem.yaml` 现在也是 `sites: []`

也就是说，旧文件不是“当前 policy 目录下重新测出来的结果”，而是更早的另一版 policy 状态产物。拿它和当前树、当前文档、当前 rerun 直接对比，本身就会制造混淆。

## 5. 输出产物

- 调试文档：`docs/tmp/micro_rerun_debug_20260318.md`
- 新 full rerun：`micro/results/dev/vm_micro.json`
- 已更新 authoritative：`micro/results/vm_micro_authoritative_20260318.json`


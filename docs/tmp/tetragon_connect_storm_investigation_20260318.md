# Tetragon E2E `connect_storm` 回归调查与修复记录（2026-03-18）

## 1. 根因分析

### 1.1 authoritative run 实际重编译了哪些 program

输入结果：`e2e/results/dev/tetragon_authoritative_20260318.json`

本次 daemon-mode live program 一共 5 个，policy 命中 3 个，真正 apply 成功 2 个：

| Prog ID | Live program | Type | Policy | Live sites | 实际 remap/apply |
| --- | --- | --- | --- | --- | --- |
| `22` | `event_exit_acct` | `kprobe` | 无 | `branch-flip=6` | stock |
| `24` | `event_wake_up_n` | `kprobe` | `corpus/policies/tetragon/bpf_fork/event_wake_up_new_task.policy.yaml` | `branch-flip=13` | remap `5` 个 `branch-flip` |
| `27` | `event_execve` | `tracepoint` | `corpus/policies/tetragon/bpf_execve_event/event_execve.policy.yaml` | `branch-flip=14`, `cmov=15` | remap `4` 个 `branch-flip`，`cmov` 全 skip |
| `31` | `tg_kp_bprm_comm` | `kprobe` | 无 | `branch-flip=3` | stock |
| `32` | `execve_map_upda` | `socket_filter` | `corpus/policies/tetragon/bpf_execve_map_update/execve_map_update.policy.yaml` | `branch-flip=1` | policy 空 allowlist，未 apply |

结论：

- 这次 authoritative run 里，真正 live apply 的 non-CMOV family 只有 `branch-flip`。
- `wide/rotate/extract/endian` 在本次 live apply 中都是 `0`。
- `cmov` 在 `event_execve` 的 live manifest 里存在 `15` 个，但 policy 已全部跳过，没有 apply。

### 1.2 这些 policy 文件本身是什么

读取 `corpus/policies/tetragon/` 后，和本次 run 直接相关的 policy 如下：

| Policy file | Program | 静态注释里的 family totals | allowlist 内容 |
| --- | --- | --- | --- |
| `corpus/policies/tetragon/bpf_fork/event_wake_up_new_task.policy.yaml` | `event_wake_up_new_task` | `branch-flip=5` | 只保留 `branch-flip` |
| `corpus/policies/tetragon/bpf_execve_event/event_execve.policy.yaml` | `event_execve` | `cmov=65`, `branch-flip=4` | `cmov` 全排除，只保留 `branch-flip` |
| `corpus/policies/tetragon/bpf_execve_map_update/execve_map_update.policy.yaml` | `execve_map_update` | `cmov=1` | 空 allowlist |

所以，authoritative run 的 live recompile 事实和 policy 文件是对齐的：

- `event_wake_up_new_task`：纯 `branch-flip`
- `event_execve`：policy 只允许 `branch-flip`，虽然 live program 里还有 `cmov`
- `execve_map_update`：有 policy，但不 apply site

### 1.3 `connect_storm` 的特殊性：payload 里几乎没有网络路径信号

authoritative run 的 workload 级 BPF 统计显示：

| Workload | App ops/s | Events/s | 30s 内 tracked events 总数 | 主要 tracked programs |
| --- | ---: | ---: | ---: | --- |
| `stress_exec` baseline | `238.76` | `955.70` | `28672` | `event_exit_acct` / `event_wake_up_n` / `event_execve` / `tg_kp_bprm_comm` |
| `connect_storm` baseline | `1472.96` | `0.2288` | `7` | `event_exit_acct=1`, `event_wake_up_n=4`, `event_execve=1`, `tg_kp_bprm_comm=1` |
| `connect_storm` post | `648.67` | `0.2282` | `7` | 同上 |

关键点：

- `connect_storm` 在 payload 里 30 秒只触发了 `7` 个 tracked BPF events。
- 这些 event 不是 `security_socket_connect` 风格的网络热路径，而是零星的 `exec/fork/bprm` 路径。
- `stress_exec` 同样 30 秒却有 `28672` 个 tracked events，量级差了 4 个数量级。

这说明：

- 当前 JSON payload 里，`connect_storm` 根本没有把真正的 connect 热路径统计进来。
- 因此，不能把 `connect_storm -55.96%` 直接归因到 `event_execve/event_wake_up_new_task` 上的 `branch-flip`。

### 1.4 为什么会漏掉 connect 热路径

agent log 明确显示 Tetragon 已成功加载：

- `Added kprobe ... security_bprm_check`
- `Added kprobe ... security_file_open`
- `Added kprobe ... security_socket_connect`
- `Loaded generic kprobe sensor: /usr/local/lib/tetragon/bpf/bpf_multi_kprobe_v612.o -> kprobe_multi (3 functions)`

但 authoritative JSON 的 `tetragon_programs` 只有 5 个，全部是 exec/fork 相关程序，没有 `generic_kprobe` / `kprobe_multi` 程序。

根因是当前 daemon harness 的枚举方式有盲点：

- `TetragonAgentSession` 原来只把 `find_bpf_programs(pid)` 返回、且 owner FD 仍由 Tetragon 进程持有的 program 记入 `session.programs`
- `kprobe_multi` 这类 live program 很可能在 attach 后不再保留用户态 owner FD
- 结果：真实在跑的 connect/file-open generic kprobe 被 daemon-mode payload 漏掉

因此，本次 `connect_storm` 的“回归归因失败”有两个层次：

1. **归因对象错了**：payload 里看到的是 exec/fork 程序，不是 connect 热路径程序。
2. **policy 结论不稳**：即使 `branch-flip` 在已记录 program 上存在，也不能解释网络 workload 的真实退化。

### 1.5 `stress_exec` vs `connect_storm` 的关键区别

不是“同一个 program 走了不同代码路径”，而是更基础的区别：

- `stress_exec`：payload 确实覆盖了被 recompile 的 exec/fork 程序，所以看到稳定正收益
- `connect_storm`：payload 没覆盖真正的 `security_socket_connect` generic kprobe/kprobe_multi 程序，所以只剩 workload 自身漂移和少量背景 exec/fork 噪声

因此，`connect_storm -55.96%` 不能被视为“当前被 recompile 的 branch-flip 明确导致了网络路径回归”的直接证据。

## 2. 修复尝试与验证结果

### 2.1 试验 A：完全 skip 当前 live apply 的 branch-flip

修改：

- `corpus/policies/tetragon/bpf_fork/event_wake_up_new_task.policy.yaml`
- `corpus/policies/tetragon/bpf_execve_event/event_execve.policy.yaml`

做法：把 allowlist 清空，完全去掉这两个 program 的 `branch-flip`。

结果文件：`e2e/results/dev/tetragon_fixed_20260318.json`

结果：

- `applied_programs: 0 / 5`
- `comparison.comparable: false`
- `reason: recompile did not apply successfully`

意义：

- 证明 authoritative run 里真正 live apply 的确实就是这批 `branch-flip`
- 但因为 recompile 直接变成 0，benchmark 框架跳过了 post phase，所以这轮只能作为诊断，不能作为 paired performance 结论

### 2.2 试验 B：最小化 branch-flip，只保留 1+1 个 site

修改后保留：

- `event_wake_up_new_task`：`1` 个 `branch-flip`
- `event_execve`：`1` 个 `branch-flip`

结果文件：`e2e/results/dev/tetragon_min_branchflip_20260318.json`

recompile 结果：

| Program | authoritative remap | 最小化 remap |
| --- | ---: | ---: |
| `event_wake_up_n` | `5` | `1` |
| `event_execve` | `4` | `1` |

最小化 rerun 的 per-workload 数据：

| Workload | Baseline ops/s | Post ops/s | Delta |
| --- | ---: | ---: | ---: |
| `stress_exec` | `244.24` | `297.70` | `+21.89%` |
| `file_io` | `1,492,896.14` | `1,509,261.60` | `+1.10%` |
| `open_storm` | `309,209.00` | `316,246.43` | `+2.28%` |
| `connect_storm` | `783.78` | `595.28` | `-24.05%` |

对比 authoritative run：

| Workload | authoritative delta | 最小化 branch-flip delta | 变化 |
| --- | ---: | ---: | ---: |
| `stress_exec` | `+7.94%` | `+21.89%` | 更好 |
| `file_io` | `+6.42%` | `+1.10%` | 变弱 |
| `open_storm` | `-6.36%` | `+2.28%` | 明显改善 |
| `connect_storm` | `-55.96%` | `-24.05%` | 回归减轻，但仍远未达标 |

这一轮的解释：

- `open_storm` 方向性改善，说明减少 `branch-flip` 可能对 open 路径有帮助
- 但 `connect_storm` 仍然 `-24.05%`，距离目标 `>= -5%` 很远
- 更关键的是，`connect_storm` 的 tracked events/s 仍只有 `0.229 -> 0.228`，本质上还是没有看到真实 connect 热路径

所以，这一轮不能证明“branch-flip 就是 connect_storm 回归根因”；它只能说明：

- 减少 branch-flip 数量可能降低一部分总体扰动
- 但 `connect_storm` 的核心问题没有被 policy-only 修复

### 2.3 harness 修复：把 daemon live census 改为“所有新增 live programs”

代码修改：

- `e2e/cases/tetragon/case.py`

修改内容：

- 新增 `current_programs()`
- `TetragonAgentSession.__enter__()` 在 agent healthy 之后，不再用 `find_bpf_programs(pid)` 作为最终 `session.programs`
- 改为直接从 `bpftool prog show` 取“启动后新增的全部 live BPF programs”

目的：

- 把 `kprobe_multi` / `generic_kprobe` 这类 attach 后不再持有 owner FD 的 live program 也纳入 `tetragon_programs`
- 让 `connect_storm` 和 `open_storm` 真正看到 connect/file-open 热路径

本地校验：

- `python3 -m py_compile e2e/cases/tetragon/case.py` 通过

验证状态：

- 尝试基于 harness fix 再跑一次 full Tetragon E2E
- 该 rerun 长时间未落盘 JSON/Markdown，最终中止
- 因此，这个 harness fix **已实现但尚未有完整 authoritative 性能结果**

## 3. 最终 per-workload 数据

### 3.1 authoritative run（原始问题）

来源：`e2e/results/dev/tetragon_authoritative_20260318.json`

| Workload | Delta |
| --- | ---: |
| `stress_exec` | `+7.94%` |
| `file_io` | `+6.42%` |
| `open_storm` | `-6.36%` |
| `connect_storm` | `-55.96%` |

### 3.2 诊断性 full-skip branch-flip

来源：`e2e/results/dev/tetragon_fixed_20260318.json`

| Workload | 结果 |
| --- | --- |
| 全部 workload | 无 paired post 数据，因 `applied_programs=0` 被框架跳过 |

### 3.3 最小化 branch-flip rerun

来源：`e2e/results/dev/tetragon_min_branchflip_20260318.json`

| Workload | Delta |
| --- | ---: |
| `stress_exec` | `+21.89%` |
| `file_io` | `+1.10%` |
| `open_storm` | `+2.28%` |
| `connect_storm` | `-24.05%` |

## 4. 结论和建议

### 4.1 结论

当前最可靠的结论是：

1. `connect_storm -55.96%` **不能**被直接归因到 authoritative run 中已记录的 `branch-flip` sites。
2. 这次 run 里真正被 recompile 的 program 只有 exec/fork 路径；payload 没有把真实的 `security_socket_connect` generic kprobe/kprobe_multi 程序纳入统计。
3. 因此，当前 `connect_storm` 回归更像是：
   - daemon harness 漏记了真实 connect 热路径 program
   - 再叠加 workload 自身较大的 phase-to-phase 波动
4. policy-only 修复没有达到目标：
   - 全 skip branch-flip：直接无 recompile，无法 paired 比较
   - 最小化 branch-flip：`connect_storm` 仍有 `-24.05%` 回归

### 4.2 建议

下一步应该按这个顺序做：

1. **先用已实现的 harness fix 重跑一次完整 Tetragon E2E**，确认 `tetragon_programs` 中是否终于出现 `generic_kprobe` / `kprobe_multi` live programs。
2. 一旦 connect 热路径 program 被正确枚举，再看它实际命中的 policy family。
3. 如果 live connect program 里主要是 `branch-flip` / `wide` / `endian` 这类 same-size 或 near-same-size site，再单独在 `corpus/policies/tetragon/bpf_generic_kprobe/` 上做 family skip。
4. 在 harness 修好前，不建议把当前 `connect_storm` 结果当成 Tetragon policy 回归的最终定论。

### 4.3 当前工作树状态

本次调查实际落地了两类修改：

- policy 试验：把 Tetragon exec/fork policy 调整为“最小 branch-flip allowlist”
- harness 修复：`e2e/cases/tetragon/case.py` 改为记录所有新增 live BPF programs，而不只看 owner FD

但截至本报告结束，**connect_storm 仍未被修复到 `>= -5%`**，所以最终结论是：

- 已完成根因收敛
- 已完成一轮 policy 试验和一轮 harness 修复
- 但 authoritative 级别的最终性能修复还没有闭环，需要基于 harness fix 再跑一次完整验证

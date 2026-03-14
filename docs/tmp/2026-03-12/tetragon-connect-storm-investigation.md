# Tetragon `connect_storm` 回归调查

Generated: 2026-03-12

## 范围与输入

已读取：

- `e2e/results/tetragon-e2e-v2-fixed.json`
- `e2e/results/tetragon-real-e2e.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/e2e-v2-fixed-rerun.md`
- `e2e/cases/tetragon/case.py`
- `e2e/common/workload.py`
- `corpus/policies/tetragon/` 全部 policy yaml

补充说明：

- 任务中指定的 `e2e/results/tetragon-real-e2e.json` 在当前 worktree 中已不存在；它曾被 tracked，但在 commit `7371a42` 中删除。
- 为了完成对比，我使用了历史 blob `git show 90f8072:e2e/results/tetragon-real-e2e.json`，并与现存的 `e2e/results/tetragon-real-e2e.md` 交叉核对。

## 1. `connect_storm` workload 实际在测什么

`connect_storm` 不是外部网络压测，而是 `e2e/common/workload.py` 里的一个本地 Python workload：

- 启一个 loopback listener 线程
- 主线程不断执行 `socket.create_connection(("127.0.0.1", port))`
- 每次 TCP connect/accept/close 算一个 op

这意味着它是一个非常轻的、调度敏感的、用户态主导的 workload。它没有稳定的大量系统调用链，也没有重计算；在 VM 中对线程调度、频率、偶发停顿都比较敏感。

## 2. 当前 daemon mode 到底用了哪些 BPF 程序

`e2e/cases/tetragon/case.py` 的 daemon mode 会写入两份 TracingPolicy：

- tracepoint: `syscalls/sys_enter_execve`
- kprobes: `security_bprm_check`, `security_file_open`, `security_socket_connect`

agent log 也确认 Tetragon 成功加载了：

- `generic_kprobe` sensor from `/usr/local/lib/tetragon/bpf/bpf_multi_kprobe_v612.o`
- `generic_tracepoint` sensor from `/usr/local/lib/tetragon/bpf/bpf_generic_tracepoint_v612.o`

但是，benchmark harness 最终发现并纳入测量/重编译的 live program 只有这 5 个：

| Prog ID | Live program name | Type | v2-fixed policy |
| --- | --- | --- | --- |
| `22` | `event_exit_acct_process` | `kprobe` | stock |
| `24` | `event_wake_up_new_task` | `kprobe` | `bpf_fork/event_wake_up_new_task.policy.yaml` |
| `25` | `event_execve` | `tracepoint` | `bpf_execve_event/event_execve.policy.yaml` |
| `28` | `tg_kp_bprm_committing_creds` | `kprobe` | stock |
| `29` | `execve_map_update` | `socket_filter` | `bpf_execve_map_update/execve_map_update.policy.yaml` |

关键点：

- 当前 daemon mode 的 live census 里，没有出现 `generic_kprobe_event` 这个 corpus program name。
- 也就是说，当前真实 daemon run 并不是在直接重编译 `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` 里的 `generic_kprobe_event`。
- 早期 manual fallback 的 `security_socket_connect` 路径，和当前 daemon mode 不是同一条 benchmark path。

## 3. `bpf_generic_kprobe` policy 与 connect 相关 family

`corpus/policies/tetragon/bpf_generic_kprobe/` 下 policy 都已读取。和 connect 最相关的是：

| Policy file | Program | Family totals in comment |
| --- | --- | --- |
| `generic_kprobe_event.policy.yaml` | `generic_kprobe_event` | `cmov=1, wide=1, branch-flip=4` |
| `generic_kprobe_process_event.policy.yaml` | `generic_kprobe_process_event` | `cmov=47, wide=3, extract=1, endian=4` |
| `generic_kprobe_process_event_2.policy.yaml` | `generic_kprobe_process_event_2` | `cmov=49, wide=4, endian=1` |
| `generic_kprobe_process_filter.policy.yaml` | `generic_kprobe_process_filter` | `cmov=60, wide=20, extract=21, branch-flip=31` |

但这批 `generic_kprobe_*` program 在当前 daemon-mode live program/policy match 里都没有出现。

另一个关键事实：

- 当前 worktree 中 `corpus/policies/tetragon/**/*.policy.yaml` 没有任何文件包含 `families:`
- 也没有任何 Tetragon policy 含 `cmov: skip`
- 这批文件全部是 `default: apply` + `sites: []`

所以，至少在当前仓库状态里，Tetragon 并不是“`default: apply` + `families: { cmov: skip }`”。

## 4. blind all-apply vs v2-fixed：`connect_storm` 数据对比

### 4.1 直接对比两次目标 run

| Run | Source | Duration | Baseline ops/s | Post ops/s | App delta | Baseline events | Post events | Baseline BPF total ns | Post BPF total ns | Agent CPU delta |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| blind all-apply daemon | historical `tetragon-real-e2e.json` | `8s` | `337.21` | `302.95` | `-10.16%` | `10` | `7` | `40101` | `20720` | `+7.69%` |
| v2-fixed daemon | `tetragon-e2e-v2-fixed.json` | `30s` | `1509.07` | `746.84` | `-50.51%` | `7` | `7` | `30999` | `30423` | `-29.34%` |

v2-fixed 的异常点很明显：

- 吞吐掉了 `-50.5%`
- 但 tracked BPF event 数量完全没变：`7 -> 7`
- tracked BPF 总运行时间几乎没变：`30999ns -> 30423ns`
- agent CPU 不是升高，而是下降：`5.57% -> 3.93%`

如果把这 4 个信号放在一起看，这不像“BPF 变慢了，所以 app 慢了”；更像 workload 自身节奏变了，但 BPF 侧基本没动。

### 4.2 同 workload 在最近 3 次 daemon run 的漂移

为了判断是不是单次噪声，我把最近 3 次 daemon-mode 结果并排看了一下：

| Run | Baseline ops/s | Post ops/s | Delta | Baseline events | Post events |
| --- | ---: | ---: | ---: | ---: | ---: |
| blind daemon (`2026-03-11`) | `337.21` | `302.95` | `-10.16%` | `10` | `7` |
| broken v2-policy (`2026-03-12`) | `2488.28` | `2585.88` | `+3.92%` | `7` | `7` |
| fixed v2 (`2026-03-12`) | `1509.07` | `746.84` | `-50.51%` | `7` | `7` |

结论：

- `connect_storm` 的绝对吞吐在这些 run 之间本身就飘得非常大：`337 -> 2488 -> 1509`
- 但 tracked BPF events 一直只有 `7-10` 个量级
- 这说明这个 workload 在当前 Tetragon daemon harness 下，主要反映的是 workload/harness/VM 噪声，而不是稳定的 BPF 热路径差异

## 5. v2-fixed 实际 apply 了什么 family

`tetragon-e2e-v2-fixed.json` 里真正 apply 成功的是这 3 个 program：

| Prog ID | Program | Policy file | Applied live families |
| --- | --- | --- | --- |
| `24` | `event_wake_up_new_task` | `bpf_fork/event_wake_up_new_task.policy.yaml` | `branch-flip=13` |
| `25` | `event_execve` | `bpf_execve_event/event_execve.policy.yaml` | `cmov=15`, `branch-flip=14` |
| `29` | `execve_map_update` | `bpf_execve_map_update/execve_map_update.policy.yaml` | `branch-flip=1` |

stock fallback 的 program：

| Prog ID | Program | Live sites but not applied |
| --- | --- | --- |
| `22` | `event_exit_acct` | `branch-flip=6` |
| `28` | `tg_kp_bprm_comm` | `branch-flip=3` |

因此，对“是不是 non-CMOV family 导致回归”这个问题，可以明确回答：

- `wide`: 当前 live applied sites 是 `0`
- `rotate`: 当前 live applied sites 是 `0`
- `extract`: 当前 live applied sites 是 `0`
- `endian`: 当前 live applied sites 是 `0`
- `branch-flip` (`bflip`): 当前 live applied sites 是 `28`

所以如果一定要在“当前真的 apply 了的 non-CMOV families”里找嫌疑项，只有 `branch-flip` 还站得住。

但即便如此，现有数据仍然不支持它是根因，因为：

- `connect_storm` phase 里 tracked BPF 总时间几乎没变化
- event 数也没变化
- 下降的是 app throughput，不是 BPF runtime

## 6. 为什么 `bpf_generic_kprobe` 不是这次回归的主线

任务里特别点名了 `bpf_generic_kprobe`，这条线我单独确认过：

- 在 manual fallback harness 里，`connect_storm` 确实直接用 `generic_kprobe_event` attach 到 `security_socket_connect`
- 那条路径在历史 `manual_fallback` 结果中会产生约 `93k` BPF events / `8s`
- 但在当前 daemon-mode run 中，`connect_storm` 只有 `7-10` tracked events / phase

这两个量级差异太大，说明两者不是同一条被测路径。

换句话说：

- `bpf_generic_kprobe` policy 文件本身值得读
- 但它不是当前这次 `tetragon_daemon` `connect_storm` 回归的主要因果对象

## 7. 根因判断

当前最稳妥的判断是：

1. 这次 `-50.5%` 更像 workload 噪声 / harness 不稳定 / VM 调度波动，而不是已被数据证明的 policy 回归。
2. 当前 worktree 里的 Tetragon v2 policy 并没有 `cmov: skip`，所以“CMOV 被 skip、non-CMOV 被 apply 导致回归”这个前提，在本仓库状态下并不成立。
3. 当前 live applied non-CMOV family 只有 `branch-flip`；`wide/rotate/extract/endian` 都没有 live apply，因此它们不能解释这次回归。
4. 即使怀疑 `branch-flip`，现有 `connect_storm` phase 的 BPF runtime 信号也太弱，无法把 `23k` 次连接吞吐损失归因到 `28` 个 branch-flip sites 上。

## 8. 修复建议

### 8.1 结论性建议

不建议基于这一个 `-50.5%` 数据点，直接修改 Tetragon policy。

理由：

- 当前证据更偏向噪声，而不是 family 级别的稳定回归
- 当前 daemon path 与 `bpf_generic_kprobe` corpus path 不同
- 当前 tracked BPF runtime 几乎没变化

### 8.2 如果必须做一个最小诊断性 policy 试验

可以只做一个 very low-risk 的 falsification：

- 在以下 3 个 policy 上临时加 `families: { branch-flip: skip }`
  - `corpus/policies/tetragon/bpf_fork/event_wake_up_new_task.policy.yaml`
  - `corpus/policies/tetragon/bpf_execve_event/event_execve.policy.yaml`
  - `corpus/policies/tetragon/bpf_execve_map_update/execve_map_update.policy.yaml`

原因不是“我认为 branch-flip 已经是根因”，而是：

- 它是当前唯一 live apply 的 non-CMOV family
- 这能最快把“family regresssion”与“workload noise”区分开

### 8.3 更合理的下一步

更推荐的动作是 benchmark 侧，而不是 policy 侧：

1. 只跑 `connect_storm`，做至少 `5-10` 组 stock / v2-fixed 配对复跑。
2. 固定 VM vCPU、尽量固定 host 负载，记录中位数而不是单次值。
3. 单独导出 Tetragon live connect-related program 的 program ID 和 `run_cnt`，确认真正处理 `security_socket_connect` 的程序是否被 harness 统计到了。
4. 如果想研究 `bpf_generic_kprobe` 这条 connect 路径，就用 manual fallback 的 `generic_kprobe_event@security_socket_connect` 单独做对照；不要把它和当前 daemon-mode 结果混在一起。

## 9. 最终结论

这次 `Tetragon connect_storm -50.5%` 目前不能被归因为当前 v2 policy 的 `wide/rotate/extract/endian/branch-flip` 某个 family 回归。

现有证据更支持：

- 当前 daemon-mode `connect_storm` 不是在测 `bpf_generic_kprobe` corpus path
- 当前 v2-fixed 真正 live apply 的 non-CMOV family 只有 `branch-flip`
- 但 phase 内 BPF event/runtime 基本不变，无法解释吞吐腰斩
- 因此，这更像 workload/harness 噪声，而不是已证实的 policy 问题

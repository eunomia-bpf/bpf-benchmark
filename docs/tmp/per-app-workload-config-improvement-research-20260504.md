# Per-App Workload & Config Improvement Research (2026-05-04)

## 背景与目标

本报告分析如何让 corpus 中每个 app 触发更多 BPF program、每个 program 触发更多次。
数据来源：x86 KVM kop-only corpus runs (2026-05-04)。

**measurable 判定规则**（corpus/driver.py:174-177）：
```python
if baseline_run_cnt_delta <= 0 or post_rejit_run_cnt_delta <= 0:
    return None  # 不算 measurable
```
完全由 kernel `prog_info.run_cnt` delta 决定。

**关键底层约束**：
1. **BPF tail call 不增加 callee 的 run_cnt**。kernel 只在直接 attachment 点的入口增加 run_cnt（`__bpf_prog_enter`）。所以所有通过 `BPF_TAIL_CALL` 调用的子程序，run_cnt 永远为 0，无法变成 measurable。这是内核行为，不是过滤逻辑。
2. 改动范围：只改 `runner/libs/benchmark_catalog.py` 中的 `MacroAppDefinition`、`workload.py` 中的参数（wrk threads/concurrency）、以及 `benchmark_catalog.py` 中的 `duration_s`。
3. **禁止** 修改 corpus/driver.py 或任何 runner/libs/ 核心文件（v3 §8 policy B）。

---

## 全 App 当前状态总览

| App | 总 progs (baseline) | measurable | measurable% | 当前 workload | 问题根因 |
|---|---|---|---|---|---|
| bcc/capable | 1 | 1 | 100% | stress_ng_os | 极好 (92984次) |
| bcc/execsnoop | 2 | 2 | 100% | stress_ng_process | 可 (9次, 太少) |
| bcc/bindsnoop | 2 | 2 | 100% | stress_ng_network | 可 (2次, 噪声) |
| bcc/biosnoop | 3 | 3 | 100% | fio_randrw | 极好 (1.6M次) |
| bcc/vfsstat | 5 | 5 | 100% | stress_ng_filesystem | 好 |
| bcc/opensnoop | 3 | 3 | 100% | stress_ng_filesystem | 好 |
| bcc/syscount | 2 | 2 | 100% | stress_ng_os | 极好 (559K次) |
| bcc/tcpconnect | 2 | 2 | 100% | stress_ng_network | 差 (1次, 噪声) |
| bcc/tcplife | 1 | 1 | 100% | stress_ng_network | 可 (556次) |
| bcc/runqlat | 3 | 3 | 100% | stress_ng_scheduler | 好 |
| bpftrace/capable | 1 | 1 | 100% | stress_ng_os | 好 (92983次) |
| bpftrace/biosnoop | 2 | 2 | 100% | fio_randrw | 极好 (1.4M次) |
| bpftrace/vfsstat | 1 | 1 | 100% | stress_ng_filesystem | 好 |
| bpftrace/runqlat | 2 | 2 | 100% | stress_ng_scheduler | 好 |
| bpftrace/tcplife | 1 | 1 | 100% | stress_ng_network | 可 (9次) |
| bpftrace/tcpretrans | 1 | 0 | 0% | stress_ng_network | 需要 TCP 重传 |
| tracee/monitor | 158 | 57 | 36% | stress_ng_os | workload 太窄 |
| tetragon/observer | 287 | 32 | 11% | stress_ng_os_io_network | tail-call 约束 |
| otelcol-ebpf-profiler | 13 | 2 | 15% | stress_ng_cpu | tail-call 约束 |
| cilium/agent | 25 | 1 | 4% | network (wrk) | tail-call + 流量少 |
| calico/felix | 6 | 0 | 0% | network (wrk) | tail-call 架构 |
| katran | 3 | 1 | 33% | network (并发4) | tail-call + 缺 HC |

---

## 一、BCC Apps (10 个工具, 26 progs, 24 measurable)

### 1.1 各工具 BPF prog 清单（来自 result.json）

| 工具 | prog | type | attach | 当前 run_cnt | workload |
|---|---|---|---|---|---|
| capable | cap_capable | kprobe | kernel:cap_capable | 92,984 | stress_ng_os |
| execsnoop | syscall__execve | kprobe | syscall:execve | 9 | stress_ng_process |
| execsnoop | do_ret_sys_execve | kprobe | syscall:execve ret | 9 | stress_ng_process |
| bindsnoop | bindsnoop_entry | kprobe | kernel:security_socket_bind | 2 | stress_ng_network |
| bindsnoop | bindsnoop_v4_return | kprobe | kretprobe | 2 | stress_ng_network |
| biosnoop | trace_pid_start_tp | tracepoint | block:block_io_start | 1,653,783 | fio_randrw |
| biosnoop | trace_req_start | kprobe | kernel:blk_account_io_start | 1,653,793 | fio_randrw |
| biosnoop | trace_req_completion_tp | tracepoint | block:block_io_done | 1,653,798 | fio_randrw |
| vfsstat | vfs_create | tracing | kfunc:vfs_create | 4,853 | stress_ng_filesystem |
| vfsstat | kfunc__vmlinux__vfs_fsync_range | tracing | kfunc:vfs_fsync_range | 317 | stress_ng_filesystem |
| vfsstat | vfs_open | tracing | kfunc:vfs_open | 77,127 | stress_ng_filesystem |
| vfsstat | vfs_read | tracing | kfunc:vfs_read | 29,934 | stress_ng_filesystem |
| vfsstat | vfs_write | tracing | kfunc:vfs_write | 4,766 | stress_ng_filesystem |
| opensnoop | __x64_sys_open | tracing | kfunc:__x64_sys_open | 97 | stress_ng_filesystem |
| opensnoop | kretfunc:__x64_sys_openat | tracing | kretfunc:openat | 56,830 | stress_ng_filesystem |
| opensnoop | kretfunc:__x64_sys_openat2 | tracing | kretfunc:openat2 | 22 | stress_ng_filesystem |
| syscount | tracepoint__raw_syscalls__sys_enter | tracepoint | raw_tp:sys_enter | 559,314 | stress_ng_os |
| syscount | tracepoint__raw_syscalls__sys_exit | tracepoint | raw_tp:sys_exit | 559,315 | stress_ng_os |
| tcpconnect | trace_connect_entry | kprobe | kernel:tcp_v4_connect | 1 | stress_ng_network |
| tcpconnect | trace_connect_v4_return | kprobe | kretprobe | 1 | stress_ng_network |
| tcplife | tracepoint__sock__inet_sock_set_state | tracepoint | tracepoint:sock | 556 | stress_ng_network |
| runqlat | sched_switch | raw_tracepoint | raw_tp:sched_switch | 8,555 | stress_ng_scheduler |
| runqlat | sched_wakeup | raw_tracepoint | raw_tp:sched_wakeup | 4,698 | stress_ng_scheduler |
| runqlat | raw_tracepoint__sched_wakeup_new | raw_tracepoint | raw_tp:sched_wakeup_new | 558 | stress_ng_scheduler |

### 1.2 问题 prog 分析

**bcc/bindsnoop (2次)**：
- `stress_ng_network` 包含 epoll/netdev/sctp/sock/sockdiag/sockfd/sockpair/udp-flood
- `bind()` 系统调用在 stress-ng 的 `sock` stressor 里只触发少量次
- `bind_storm` workload（`run_bind_storm`）专门做 bind/unbind 循环，会触发数十万次

**bcc/tcpconnect (1次)**：
- `trace_connect_entry` 挂在 `tcp_v4_connect`，只有 TCP 连接才触发
- `stress_ng_network` 的 stressors 中只有 `sock` stressor 建立极少 TCP 连接
- `tcp_connect` workload 使用 `curl` 反复连接本地 HTTP server，可以触发数百次

### 1.3 BCC 改动建议

| 工具 | 改动 | 预期效果 | 风险 |
|---|---|---|---|
| bcc/bindsnoop | `workload="bind_storm"` | 2 -> 10,000+ triggers | 低，bind_storm 是稳定 workload |
| bcc/tcpconnect | `workload="tcp_connect"` | 1 -> 500+ triggers | 低，tcp_connect 用 curl 循环 |
| bcc/execsnoop | `workload="exec_storm"` | 9 -> 5,000+ triggers | 低，exec_storm 稳定 |

**改动文件**：`runner/libs/benchmark_catalog.py`，改 3 行（MacroAppDefinition workload 字段）

---

## 二、bpftrace Apps (6 个脚本, 10 progs, 9 measurable)

### 2.1 prog 清单

| 脚本 | prog | type | run_cnt | workload |
|---|---|---|---|---|
| capable | cap_capable | kprobe | 92,983 | stress_ng_os |
| biosnoop | block_io_start | tracepoint | 1,464,538 | fio_randrw |
| biosnoop | block_io_done | tracepoint | 1,464,553 | fio_randrw |
| vfsstat | vfs_create | kprobe | 113,923 | stress_ng_filesystem |
| runqlat | sched_switch | tracepoint | 7,867 | stress_ng_scheduler |
| runqlat | sched_wakeup | tracepoint | 4,376 | stress_ng_scheduler |
| runqlat | sched_wakeup_new | tracepoint | 562 | stress_ng_scheduler |
| tcplife | tcp_set_state | kprobe | 9 | stress_ng_network |
| tcpretrans | (perf_event) | perf_event | **0 — 不可测** | stress_ng_network |
| (bpftrace internal) | 1 | perf_event | 3 | stress_ng_network |

### 2.2 问题分析

**bpftrace/tcpretrans (0 measurable)**：
- `tcpretrans.bt` 挂在 `tcp_retransmit_skb` kprobe（或 `tcp_retransmit_skb` tracepoint）
- stress_ng_network 在 loopback 上做网络操作，几乎不产生 TCP 重传
- `tcp_retransmit` workload（`run_tcp_retransmit_load`）通过 `tc` 注入丢包率产生重传
- 这个 workload 需要 `tc` netem 支持（需要 sch_netem 内核模块）

**bpftrace/tcplife (9次)**：
- `tcp_set_state` 只在 TCP 连接状态变化时触发
- `stress_ng_network` 的 sock/sockfd/sockpair stressors 不完整走 TCP 状态机
- 换成 `tcp_connect` 或 `stress_ng_network` + 增加 duration_s 可提升

### 2.3 bpftrace 改动建议

| 脚本 | 改动 | 预期效果 | 风险 |
|---|---|---|---|
| bpftrace/tcpretrans | `workload="tcp_retransmit"` | 0 -> 可能 100+（需 sch_netem） | 中等，需要内核模块 |
| bpftrace/tcplife | `workload="tcp_connect"` | 9 -> 500+ | 低 |

**改动文件**：`benchmark_catalog.py` 2 行

---

## 三、tracee/monitor (158 progs, 57 measurable = 36%)

### 3.1 当前状态

**当前 workload**：`stress_ng_os`（stressors: cap, eventfd, get, prctl, set）
**当前 duration_s**：5.0 秒

**measurable 的 57 个 progs（全部直接 attach 点）**：
```
raw_tp:raw_syscalls/sys_enter/exit  → 1,196,765 次  (syscall hook)
raw_tp:sched_switch                 → 638,295 次    (调度器)
kprobe:arch_prctl                   → 263,006 次    (prctl stressor)
kprobe:cap_capable                  → 97,887 次     (cap stressor)
kprobe:security_task_prctl          → 92,042 次     (prctl)
kprobe:security_task_setrlimit      → 19,695 次     (set stressor)
kprobe:fd_install                   → 15,983 次     (eventfd stressor)
kprobe:security_file_permission     → 14,674 次
kprobe:security_file_open           → 13,440 次
lsm:file_open                       → 13,440 次     (LSM hook)
...（共57个）
```

### 3.2 不可测 progs 分析（101 个）

**按类别分组**：

| 类别 | prog 数 | 需要什么触发 | 相应 workload |
|---|---|---|---|
| ptrace/process_vm_writev | 2 | ptrace() 系统调用 | tracee_system_edge_mix 中的 `_exercise_ptrace_and_process_vm_writev_once` |
| dup/dup2/dup3 | 6 | dup 系列系统调用 | tracee_system_edge_mix 中的 `_exercise_dup_family` |
| execveat | 4 | execveat() 系统调用 | tracee_system_edge_mix 中的 `_run_execveat_once` |
| accept4 | 1 | accept4() 系统调用 | tracee_system_edge_mix 中的 `_accept4_roundtrip` |
| socketpair | - | socketpair() | tracee_system_edge_mix 中的 `_exercise_socketpair_once` |
| lkm_seeker_* (内核模块) | 7 | 模块加载/卸载 | tracee_module_load_loop_workload |
| cgroup_skb_ingress/egress | 2 | cgroup SKB hook | 需要 cgroup 网络流量 |
| vfs_readv/writev | 6 | readv/writev/preadv/pwritev | tracee_io_vector_mix workload |
| security_socket_listen/bind | 2 | socket bind/listen | connect_storm |
| security_sb_mount/umount | 2 | mount/umount | tracee_host_event_mix 中的 `_exercise_mount_roundtrip_once` |
| kallsyms_lookup_name | 2 | kallsyms 查找（rootkit检测） | 需要 BPF 自我观察 |
| inotify_find_inode | 2 | inotify 事件 | tracee_system_edge_mix 中的 `_exercise_fs_metadata_once(use_inotify=True)` |
| cgroup_attach_task | 1 | cgroup 进程附加 | tracee_system_edge_mix 中的 `_exercise_cgroup_attach_task_once` |
| vfs_utimes/truncate | 4 | 文件时间戳/截断 | tracee_system_edge_mix fs_metadata |
| security_kernel_read_file | 2 | 内核模块加载 | module_load_loop |

**关键发现**：所有这些 progs 都在 `tracee_system_edge_mix` workload 的覆盖范围内！

`tracee_system_edge_mix` 调用：
- `run_tracee_syscall_edge_mix_workload`（execveat, dup, socketpair, accept4, ptrace, fs_metadata, cgroup_attach, inotify）
- `run_tracee_io_vector_mix_workload`（readv, writev, preadv, pwritev）
- `run_tracee_module_load_loop_workload`（modprobe load/unload）

### 3.3 tracee 改动建议

**必做**：将 `tracee/monitor` workload 从 `stress_ng_os` 改为 `tracee_system_edge_mix`

```python
# runner/libs/benchmark_catalog.py 第 83 行
# 改前：
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os", duration_s=5.0),
# 改后：
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="tracee_system_edge_mix", duration_s=5.0),
```

**预期效果**：
- measurable progs：57 -> 估计 90-120（57 + 30-60 新增）
- 新增触发：ptrace, dup, execveat, accept4, socketpair, readv/writev, inotify, cgroup_attach, module_load
- 仍无法测的：cgroup_skb_ingress/egress（需要 cgroup 网络流量，不在任何 workload 中）、kallsyms_lookup_name（需要 BPF 自检观察）、uprobe progs（需要特定二进制 uprobe）

**改动**：1 行，风险极低（`tracee_system_edge_mix` 是成熟的工作负载）

---

## 四、tetragon/observer (287 progs, 32 measurable = 11%)

### 4.1 当前状态

**当前 workload**：`stress_ng_os_io_network`（os+io+network stressors）
**当前 duration_s**：默认 1.0 秒

**287 progs 类型分布**：
- kprobe: 270 个
- tracepoint: 9 个
- socket_filter: 1 个
- raw_tracepoint: 7 个

**run_cnt_delta > 0 的 32 个 progs（直接 attach 点）**：

| prog | type | run_cnt | 挂载位置 |
|---|---|---|---|
| generic_tracepoint_event | tracepoint | 6,454,808 | 各个 tracepoint 的主入口 |
| generic_kprobe_event (多个) | kprobe | 48,655-102,200 | 各个 kprobe 的主入口 |
| generic_retkprobe_event (多个) | kprobe | 4,264-57,553 | kretprobe 主入口 |
| event_wake_up_new_task | kprobe | 1,080 | wake_up_new_task |
| event_exit_acct_process | kprobe | 1,070 | acct_process (进程退出) |
| event_execve | tracepoint | 21 | sched:process_exec |
| tg_kp_bprm_committing_creds | kprobe | 21 | bprm_committing_creds |
| generic_rawtp_event | raw_tracepoint | 21 | rawtp 主入口 |
| generic_kprobe_event (少触发) | kprobe | 1-9 | 特定 kprobe |

**253 个 run_cnt=0 的 progs**（永远无法 measurable）：

| 类别 | 数量 | 原因 |
|---|---|---|
| generic_kprobe_filter_arg | 33 | tail-called from generic_kprobe_event |
| generic_kprobe_actions | 33 | tail-called |
| generic_kprobe_output | 33 | tail-called |
| generic_kprobe_setup_event | 33 | tail-called |
| generic_kprobe_process_event | 33 | tail-called |
| generic_kprobe_process_filter | 33 | tail-called |
| generic_kprobe_event (附加实例) | 12 | 对应无触发的 kprobe hook |
| generic_retkprobe_actions/filter/output | 27 | tail-called |
| generic_retkprobe_event | 2 | 对应无触发的 kretprobe hook |
| execve_send/rate/map_update | 3 | 对应 execve tracepoint 子程序 |
| generic_tracepoint_process_event 等 | 5 | tail-called from generic_tracepoint_event |
| generic_rawtp_* | 6 | tail-called from generic_rawtp_event |

### 4.2 根本原因

**Tetragon 架构**：每个 kprobe 附加点加载 6 个程序（entry prog + 5 个 tail-called helpers）。只有 `generic_kprobe_event`（主入口）的 run_cnt 会增加；`generic_kprobe_filter_arg`、`generic_kprobe_actions` 等都通过 BPF_TAIL_CALL 从主入口调用，run_cnt 不增加。

因此 **253/287 = 88% 的 progs 从设计上永远是 0 run_cnt**，这是 Tetragon BPF 架构的必然结果，不是 workload 问题。

**可改进的部分**：
1. 32 个 measurable progs 中有些 run_cnt 极低（1-3次）
2. 部分 `generic_kprobe_event` 仍有 run_cnt=0（attach 了但 workload 没触发该 kprobe）

### 4.3 Tetragon 改动建议

**改动一**：将 workload 改为 `tetragon_exec_connect_mix`，增加更多事件类型覆盖

```python
# benchmark_catalog.py 第 81 行
# 改前：
MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="stress_ng_os_io_network"),
# 改后：
MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="tetragon_exec_connect_mix"),
```

`tetragon_exec_connect_mix` 覆盖：
- exec storm（execve 事件，触发 event_execve tracepoint）
- rapid exec（/bin/true 的快速 execveat）
- socket events（TCP/UDP connect, accept）→ 触发更多 generic_kprobe_event
- fs events（文件操作）→ 触发文件相关 kprobe
- host events（mount, module, signal）→ 触发 host 相关 kprobe

**改动二**：增加 `duration_s=3.0`（目前 1.0 秒太短）

```python
MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="tetragon_exec_connect_mix", duration_s=3.0),
```

**预期效果**：
- 无法增加 measurable 数量（tail-call 约束固定了 253 个不可测）
- 32 个 measurable progs 的 run_cnt 分布会改善
- 原来 run_cnt=1-9 的低触发 progs 可能增加到 100+ 次，ratio 更可信

**改动文件**：`benchmark_catalog.py` 1 行（+`duration_s=3.0`）

---

## 五、otelcol-ebpf-profiler/profiling (13 progs, 2 measurable = 15%)

### 5.1 当前状态

**当前 workload**：`stress_ng_cpu`（otel profiler 的 runner 实际调用 `run_otel_profiler_cpu_mix_workload`）
**当前 duration_s**：5.0 秒

**所有 progs**：

| prog | type | run_cnt | 说明 |
|---|---|---|---|
| native_tracer_entry | perf_event | 238 | CPU 采样主入口（47 Hz 采样率） |
| tracepoint__sched_process_free | tracepoint | 3 | 进程退出 tracepoint（直接附加） |
| perf_unwind_stop | perf_event | 0 | tail-called from native_tracer_entry |
| perf_unwind_native | perf_event | 0 | tail-called from native_tracer_entry |
| perf_unwind_hotspot | perf_event | 0 | JVM 栈展开（tail call） |
| perf_unwind_perl | perf_event | 0 | Perl 栈展开（tail call） |
| perf_unwind_php | perf_event | 0 | PHP 栈展开（tail call） |
| perf_unwind_python | perf_event | 0 | Python 栈展开（tail call） |
| perf_unwind_ruby | perf_event | 0 | Ruby 栈展开（tail call） |
| perf_unwind_v8 | perf_event | 0 | Node.js 栈展开（tail call） |
| perf_unwind_dotnet | perf_event | 0 | .NET 栈展开（tail call） |
| perf_go_labels | perf_event | 0 | Go goroutine 标签（tail call） |
| perf_unwind_beam | perf_event | 0 | Erlang/Elixir 栈展开（tail call） |

### 5.2 根本原因

`native_tracer_entry` 是直接附加的 perf_event 主采样程序，它通过 BPF_TAIL_CALL 调用对应语言运行时的 unwinder。**所有 `perf_unwind_*` 都是 tail-called 程序，run_cnt 永远为 0**。

otel profiler 的架构：
1. CPU 采样触发 `native_tracer_entry`（238次/5s ≈ 47 Hz）
2. `native_tracer_entry` 检查当前 PC 属于哪个语言运行时
3. 通过 BPF_TAIL_CALL 调用对应 `perf_unwind_*`
4. 因为是 tail call，callee 的 run_cnt 不增加

`otel_profiler_cpu_mix_workload` 运行了：shell (bash), native (C), Go, Python, Node.js, Java, Ruby 等 CPU 消耗程序，理论上所有 unwinder 都应该被调用——但因为 tail call 约束，仍然是 0。

### 5.3 otel 改动建议

**结论**：从 measurable 数量角度无法改善（tail-call 约束）。

`native_tracer_entry` 的 238 次触发是 47 Hz 采样率，是正常工作的标志。
`tracepoint__sched_process_free` 触发 3 次（workload 中有 3 个子进程退出）。

**可选改进**：增加 `duration_s`（如 10.0 秒）让 `native_tracer_entry` 的 run_cnt 从 238 增加到 ~476，减少统计噪声。但这不增加 measurable 数量。

**打 X 不做**：无法让 `perf_unwind_*` 变成 measurable，除非修改 otel profiler 使其不用 tail call。

---

## 六、cilium/agent (25 progs, 1 measurable = 4%)

### 6.1 当前状态

**当前 workload**：`network`（wrk -t2 -c10, 1.0 秒，HTTP via bpfbench0 veth pair）

**所有 progs**（来自 post-A2 result.json）：

| prog | type | run_cnt | 说明 |
|---|---|---|---|
| cil_from_netdev | sched_cls | 312 | TC ingress on bpfbench0 — **唯一 measurable** |
| cil_from_host | sched_cls | 1 | TC egress from host to bpfbench0 |
| cil_to_host | sched_cls | 1 | TC ingress on host-side veth |
| dump_bpf_map | tracing | 0 | BPF introspection（内部工具） |
| dump_bpf_prog | tracing | 0 | BPF introspection |
| cil_to_host (多实例) | sched_cls | 0 | tail-called 或 diff interface |
| cil_to_netdev | sched_cls | 0 | TC egress on bpfbench0 |
| cil_from_netdev (其他实例) | sched_cls | 0 | 不同接口实例 |
| tail_handle_ipv4_from_netdev | sched_cls | 0 | tail-called from cil_from_netdev |
| tail_handle_ipv4_from_host | sched_cls | 0 | tail-called from cil_from_host |
| cil_host_policy | sched_cls | 0 | tail-called（policy enforcement） |
| tail_drop_notify | sched_cls | 0 | tail-called（drop notification） |

### 6.2 根本原因

**Cilium TC 架构**：
- `cil_from_netdev` 是 TC ingress 主入口（直接附加），接收来自外部的流量
- `tail_handle_ipv4_from_netdev`、`cil_host_policy`、`tail_drop_notify` 均为 tail calls
- `cil_to_netdev` 是 TC egress，处理发往外部的流量

**当前流量路径**（wrk 在 root ns，HTTP server 在 bpfbenchns）：
```
wrk (root ns) → bpfbench0 TC egress (cil_to_netdev) → bpfbench1 → HTTP server
HTTP server → bpfbench1 → bpfbench0 TC ingress (cil_from_netdev, 312次) → wrk
```

`cil_to_netdev` 处理从 root ns 发出的包，但 run_cnt=0——原因是 Cilium 在此方向没有检测到需要处理的端点（没有 WorkloadEndpoint，仅有 HostEndpoint）。

`cil_from_netdev` 的 312 次对应 wrk 在 1 秒内处理的 ~140 请求 × 2 方向 ≈ 312 个包到达 TC ingress。

### 6.3 cilium 改动建议

**改动一**：增加 wrk 吞吐量

当前：`wrk -t2 -c10 -d1s`（140 req/s, run_cnt=312）

`run_network_load()` 在 `workload.py` 第 2437 行固定使用 `-t2 -c10`。

```python
# workload.py 第 2437 行
# 改前：
[wrk_binary, "-t2", "-c10", f"-d{max(1, int(duration_s))}s", server.url],
# 改后：
[wrk_binary, "-t4", "-c50", f"-d{max(1, int(duration_s))}s", server.url],
```

预期：140 -> 700+ req/s，run_cnt 从 312 -> 1500+（更可信的统计）

**改动二**：增加 duration_s

```python
# benchmark_catalog.py 第 80 行
# 改前：
MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network"),
# 改后：
MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network", duration_s=5.0),
```

`cil_from_netdev` 的 run_cnt 从 312 -> 1500+，ratio 更稳定。

**关于 measurable 数量**：
- tail-called progs（tail_handle_ipv4_from_netdev, cil_host_policy, tail_drop_notify）：**无法变成 measurable**
- `cil_to_netdev`（处理 egress）：理论上 wrk 发出的请求会经过它，但 run_cnt=0 说明 Cilium 在这条路径没有处理流量
- `cil_from_host/cil_to_host`（1次）：才刚触发，是 Cilium 健康检查或初始化流量

最多只能增加 `cil_from_host`、`cil_to_host` 为 measurable（当前 run_cnt=1，需要 ≥ 2 次在两个窗口都触发）。

**风险**：修改 `run_network_load()` 会影响所有使用 `network` workload 的 app（cilium 和 calico）。要评估 calico 是否也受益。

---

## 七、calico/felix (6 progs, 0 measurable = 0%)

### 7.1 当前状态

**当前 workload**：`network`（wrk -t2 -c10, 1.0 秒）

**所有 progs**：

| prog | type | run_cnt | 说明 |
|---|---|---|---|
| conntrack_cleanup | sched_cls | 0 | conntrack GC（timer-based，不被流量触发） |
| cali_tcx_test | sched_cls | 0 | XDP/TCX 兼容性测试 prog（startup 时执行一次但不计 run_cnt） |
| calico_tc_allow | sched_cls | 0 (×2) | policy 允许 verdict（tail-called） |
| calico_tc_deny | sched_cls | 0 (×2) | policy 拒绝 verdict（tail-called） |

### 7.2 根本原因

**Calico Felix BPF 架构**：
1. **conntrack_cleanup**：timer-driven，不被数据包触发，run_cnt 不增加
2. **cali_tcx_test**：这是 Felix 加载时执行的 XDP/TCX 兼容性探测程序，仅作 capability 检测用途，不在流量路径上
3. **calico_tc_allow/deny**：这些是 policy verdict 子程序，通过 BPF JUMP MAP 从主 TC entry prog 调用——也是 tail-call，run_cnt 不增加

**主 TC entry progs（from_hep/to_hep）不在列表中**的原因：
Felix 动态加载 TC 程序（每次 endpoint 配置变化都重新加载）。这些主 entry progs（`cali_from_host`、`cali_to_host` 等）在 Felix 初始化时加载，可能在 daemon 开始采集前就已经存在，或者在采集窗口外被重新加载。我们的 result.json 只显示在 runner 启动期间发现的 prog（排除 preexisting IDs），所以动态重载的 TC entry progs 可能被漏掉。

**证据**：Calico 有 6 progs，其中：
- 无一个是 ingress/egress TC entry prog（from_hep/to_hep）
- 这与 Calico 动态加载架构一致：entry progs 可能在我们开始追踪后短暂出现又消失

### 7.3 calico 改动建议

**问题复杂度**：
1. tail-call progs（calico_tc_allow/deny）永远不可测
2. conntrack_cleanup 是 timer-based，不被流量触发
3. 主 TC entry progs 未被 daemon 追踪到

**可行方案**：

**方案 A（低效果，低风险）**：仅增加 wrk 流量强度
- 改 wrk 参数（-t4 -c50）和 duration_s=5.0
- 无法改变 0 measurable 的状态（因为 calico_tc_allow/deny 是 tail-call）
- 风险：低

**方案 B（高效果，中等风险）**：调查并修复 Calico TC entry prog 未被追踪的问题
- 在 `CalicoRunner.start()` 中添加更长的等待时间，让 Felix 完成 TC 附加
- 目前 `NativeProcessRunner.start()` 调用 `wait_until_program_set_stable()` 等待 prog 稳定
- 如果 Felix 在 HEP 注册后再次重新加载 TC progs，我们的 daemon 会错过它们
- **修复方向**：在 `_register_host_endpoint()` 之后再次调用 `refresh_programs()` 等待新 progs 出现
- 这涉及修改 `calico.py` 中的 `start()` 方法（约 10-15 行）
- 风险：中等，需要理解 Felix 的 TC reload 时序

**方案 C（不做，需 K8s）**：注册 WorkloadEndpoint
- 让 Felix 附加 workload endpoint policy progs
- 需要完整的 Kubernetes 集群或 calico-node 配置
- 基础设施成本过高，标记为 X

**推荐**：方案 A（快速改进 calico 的 trigger intensity）+ 独立 task 调查方案 B

---

## 八、katran (3 progs, 1 measurable = 33%)

### 8.1 当前状态

**当前 workload**：`network`（并发 4 客户端，HTTP over DSR topology）
**当前 duration_s**：默认 1.0 秒

**所有 progs**：

| prog | type | run_cnt | 说明 |
|---|---|---|---|
| xdp_root | xdp | 36,474 | XDP 主入口（直接附加到 katran0 接口） |
| balancer_ingress | xdp | 0 | tail-called from xdp_root via prog_array |
| healthcheck_encap | sched_cls | 0 | TC egress on ipip0（health check tunnel traffic） |

### 8.2 根本原因

**balancer_ingress (0)**：
- 由 `xdp_root` 通过 BPF prog_array tail call 调用
- tail call 不增加 callee run_cnt——这是无法改变的内核行为
- 36,474 次 xdp_root 触发意味着 balancer_ingress 实际上被执行了 36,474 次，但 run_cnt 保持 0

**healthcheck_encap (0)**：
- 这是 `sched_cls`（TC）程序，附加在 `ipip0` 隧道接口
- 触发条件：Katran 对后端 real server 做 health check，发送健康检查 TCP 连接
- 当前 benchmark 只做 client→VIP→real 的正向流量，没有触发 HC 流量
- HC 流量路径：katran_server → ipip0 → IPIP 隧道 → real server

### 8.3 katran 改动建议

**改动一**：触发 health check 流量以让 healthcheck_encap 变成 measurable

Katran server 有 `-healthchecker_prog` 参数，且 real server 在独立 netns `katran-real` 中。
若 real server 返回合法 HTTP 200，katran 应该定期发送健康检查。

检查 `KatranRunner.run_workload()` 使用 `run_parallel_http_load`，这只是发送 client→VIP 流量。

**方法**：
- 在 workload 期间让 katran 对 real server 做健康检查（可能通过启动时配置或发送 SIGHUP）
- 或在 workload 之前建立 VIP→real 的健康检查映射

这需要修改 `katran.py` 中 `configure_katran_maps()` 或 `_run_network_workload()`。约需 20-30 行代码理解和修改。

**改动二**：增加 concurrency 提高 xdp_root 触发率

```python
# katran.py 第 849 行
DEFAULT_CONCURRENCY = 4

# benchmark_catalog.py 第 82 行
MacroAppDefinition(name="katran", runner="katran", workload="network"),
# 改后：
MacroAppDefinition(name="katran", runner="katran", workload="network", runner_args={"concurrency": 16}),
```

当前 36,474 次 xdp_root → 4 concurrency × 9,118 requests → 36K packets
增加到 16 concurrency → 150K+ packets/second

**预期效果**：
- healthcheck_encap：需要调查和可能的代码修改才能触发
- xdp_root：从 36,474 -> ~145,000（concurrency × 4）
- balancer_ingress：永远不可测（tail call 约束）

---

## 九、改动优先级排序

### 必做（改一行 catalog，收益大）

| 优先级 | 改动 | 文件 | 行数 | 预期收益 |
|---|---|---|---|---|
| P0 | tracee/monitor: `stress_ng_os` → `tracee_system_edge_mix` | benchmark_catalog.py | 1 行 | 57 -> 90-120 measurable，覆盖 ptrace/dup/socket/iov/module 等 |
| P0 | bcc/bindsnoop: `stress_ng_network` → `bind_storm` | benchmark_catalog.py | 1 行 | 2 -> 10000+ triggers |
| P0 | bcc/tcpconnect: `stress_ng_network` → `tcp_connect` | benchmark_catalog.py | 1 行 | 1 -> 500+ triggers |
| P1 | bcc/execsnoop: `stress_ng_process` → `exec_storm` | benchmark_catalog.py | 1 行 | 9 -> 5000+ triggers |
| P1 | tetragon/observer: `stress_ng_os_io_network` → `tetragon_exec_connect_mix` + `duration_s=3.0` | benchmark_catalog.py | 1 行 | low-count progs 从 1-9 增加到 100+ |

### 建议（需改 workload.py 参数）

| 优先级 | 改动 | 文件 | 行数 | 预期收益 |
|---|---|---|---|---|
| P1 | wrk 参数: `-t2 -c10` → `-t4 -c50` | workload.py | 1 行 | cilium/calico network workload 触发次数 3-5x |
| P1 | cilium/agent: `duration_s=5.0` | benchmark_catalog.py | 1 行 | cil_from_netdev 从 312 -> 1500+ |
| P2 | bpftrace/tcplife: `stress_ng_network` → `tcp_connect` | benchmark_catalog.py | 1 行 | 9 -> 500+ triggers |
| P2 | katran: concurrency=16 | benchmark_catalog.py | 1 行 | xdp_root 36K -> 150K triggers |

### 可选（需复杂调查或代码修改）

| 优先级 | 改动 | 预期收益 | 风险 |
|---|---|---|---|
| P2 | calico: 调查 TC entry prog 未追踪问题 | 0 -> 可能 2 measurable（entry progs） | 中等，涉及 calico.py |
| P3 | katran: 触发 healthcheck_encap | 1 -> 2 measurable | 中等，需要 katran HC 流量配置 |
| P3 | bpftrace/tcpretrans: `tcp_retransmit` workload | 0 -> 可能 measurable | 中等，依赖 sch_netem 内核模块 |

### 打 X 不做

- **otel perf_unwind_***: 永远是 tail-call，run_cnt 不增加，无解
- **tetragon kprobe helper progs**: 永远是 tail-call（198 个），无解
- **Cilium tail-called progs**: tail_handle_ipv4_from_netdev 等永远不可测
- **calico WorkloadEndpoint**: 需要 K8s 基础设施，成本过高
- **任何 BPF_PROG_TEST_RUN**: 严格禁止

---

## 十、关于 BPF tail call 约束的根本说明

以下 app 的 measurable 上限被 BPF 内核架构限制：

| App | tail-call 不可测 progs | 真实可测上限 |
|---|---|---|
| tetragon | 253/287 (88%) | ~34 个（直接 attach 点） |
| otel | 11/13 (85%) | ~2 个（native_tracer_entry + sched_process_free） |
| cilium | ~20/25 (80%) | ~5 个（各 TC 接口的主 entry prog） |
| calico | 2/6 (33%)（policy tail-calls） | ~4 个（若 TC entry progs 被追踪到） |
| katran | 1/3 (33%) | ~2 个（xdp_root + healthcheck_encap） |

这是 BPF 架构的基本约束，不是本框架的问题。对于这些 app，报告的 measurable 数量客观上是 kernel `prog_info.run_cnt` 的上限，任何改进只能提高直接附加 prog 的 trigger 频率和可信度。

---

## 改动总结（按文件）

### `runner/libs/benchmark_catalog.py`（必做改动，约 7-8 行）

```python
# P0: tracee - 覆盖更多事件类型
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="tracee_system_edge_mix", duration_s=5.0),

# P0: bcc/bindsnoop - 需要 bind 操作
MacroAppDefinition(name="bcc/bindsnoop", runner="bcc", workload="bind_storm", runner_args={"tool": "bindsnoop"}),

# P0: bcc/tcpconnect - 需要 TCP 连接
MacroAppDefinition(name="bcc/tcpconnect", runner="bcc", workload="tcp_connect", runner_args={"tool": "tcpconnect"}),

# P1: bcc/execsnoop - 需要 exec 事件
MacroAppDefinition(name="bcc/execsnoop", runner="bcc", workload="exec_storm", runner_args={"tool": "execsnoop"}),

# P1: tetragon - 更丰富的事件混合
MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="tetragon_exec_connect_mix", duration_s=3.0),

# P1: cilium - 更长测量窗口
MacroAppDefinition(name="cilium/agent", runner="cilium", workload="network", duration_s=5.0),
```

### `runner/libs/workload.py`（建议改动，1 行）

```python
# P1: 增加 wrk 吞吐量（影响 cilium/calico network workload）
# 第 2437 行，改前：
[wrk_binary, "-t2", "-c10", f"-d{max(1, int(duration_s))}s", server.url],
# 改后：
[wrk_binary, "-t4", "-c50", f"-d{max(1, int(duration_s))}s", server.url],
```

---

*数据来源：corpus/results/x86_kvm_corpus_20260504_* 各 result.json，代码分析：runner/libs/benchmark_catalog.py, workload.py, app_runners/*.py*

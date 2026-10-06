# Per-App 并发/多工具 Workload 调研报告 (2026-05-04)

> 本报告是 `per-app-workload-config-improvement-research-20260504.md` 的深度补充，专注于：
> 1. 框架是否支持并发 workload（当前架构分析）
> 2. 最关键的隐藏 bug：`run_stress_ng_class_load` 顺序执行 stressor（非并行）
> 3. 使用 industry-standard tools 的每 app 并发组合建议
> 4. 工具可用性核查
> 5. 优先级与改动量汇总表

---

## 一、框架并发 Workload 支持现状

### 1.1 当前架构

`runner/libs/workload.py` 中的 workload 执行是**完全顺序的**：

```python
def run_named_workload(kind, duration_s, ...) -> WorkloadResult:
    # 单个同步调用，只支持一种 workload
    if kind in _STRESS_NG_WORKLOAD_STRESSORS:
        return run_stress_ng_class_load(...)
    if kind == "tcp_connect":
        return run_tcp_connect_load(...)
    ...
```

`run_stress_ng_class_load` 内部对多个 stressor 是**顺序循环**，不是并发：

```python
def run_stress_ng_class_load(duration_s, stressors, ...):
    for stressor in normalized_stressors:          # 顺序！
        command = _build_stress_ng_stressor_command(stressor, ...)
        completed = run_command(command, ...)       # 阻塞等待
        ops_total += parse_stress_ng_bogo_ops(...)
```

**影响**：`stress_ng_os`（5 个 stressor）实际运行时间 = 5 × 单 stressor 时间 ≈ 5s（不是 1s）。每个时间窗口内只有一种 syscall 在发生，不同 hook 类型的 BPF 程序分时触发。

### 1.2 存在但未使用的并发基础设施

`_merge_workload_results` 函数（workload.py 第 251 行）**已实现但从未被调用**（dead code）：

```python
def _merge_workload_results(results: Sequence[WorkloadResult]) -> WorkloadResult:
    # 合并多个 WorkloadResult，计算 total ops + total duration
    # 这个函数存在，但没有任何调用者
```

`run_otel_profiler_cpu_mix_workload` 已经使用 `subprocess.Popen` 并行启动多个语言进程（shell, C, Go, Python, Node.js, Java, Ruby），说明框架**技术上能做并发**，只是没有通用化。

### 1.3 stress-ng 本身支持原生并发多 stressor

stress-ng 支持在单次调用中并发运行多个 stressor：

```bash
# 所有 stressor 同时运行 1 秒
stress-ng --cap 1 --eventfd 1 --get 1 --prctl 1 --set 1 --timeout 1s --metrics-brief
```

实测输出（本机验证）：
```
stress-ng: metrc: [PID] cap     1086495      1.00s   -- 全部并发 1 秒
stress-ng: metrc: [PID] eventfd  200281      1.00s
stress-ng: metrc: [PID] get          248      1.00s
stress-ng: metrc: [PID] prctl       3408      1.00s
stress-ng: metrc: [PID] set         7355      1.00s
stress-ng: info:  [PID] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)
```

现有 `_stress_ng_metric_rows` 解析器完全能处理多 stressor 并发输出（正则对每行独立匹配）。

---

## 二、最高优先级 Bug：stress-ng 顺序执行问题

### 2.1 问题描述

**当前行为（顺序）**：

```
stress_ng_os_io_network (20 个 stressor):
时序：[cap 1s] [eventfd 1s] [get 1s] [prctl 1s] [set 1s] [aio 1s] [aiol 1s] ...
实际总时长：~20 秒
BPF hook 命中：每种类型分时触发，不同类型 hook 同时不活跃
```

**期望行为（并行）**：

```
时序：[所有 20 stressor 同时运行 1s]
实际总时长：~1 秒  
BPF hook 命中：所有类型同时触发，覆盖更广
```

对于 `tetragon/observer` 使用的 `stress_ng_os_io_network`（20 个 stressor）：
- 当前：20 秒顺序执行，measurement window 仅 1 秒
- 修复后：1 秒并发执行，20 种 syscall 类型同时发生

### 2.2 最小改动方案（约 25-30 行）

将 `run_stress_ng_class_load` 改为构建单一多 stressor 命令：

```python
# workload.py 修改位置：run_stress_ng_class_load 函数（第 467-512 行）
def run_stress_ng_class_load(duration_s, stressors, *, workload_name):
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError(f"stress-ng is required for the {workload_name} workload")
    normalized_stressors = tuple(s.strip() for s in stressors if s.strip())
    if not normalized_stressors:
        raise RuntimeError(f"{workload_name} requires at least one stressor")
    
    seconds = max(1, int(round(float(duration_s))))
    temp_root = _disk_backed_tmp_root()
    
    # 构建单一并行命令（原来是逐个循环调用）
    command = [stress_ng]
    for stressor in normalized_stressors:
        command += [f"--{stressor}", "1"]
        command += list(_STRESS_NG_STRESSOR_ARGS.get(stressor, ()))
        command += _stress_ng_dynamic_stressor_args((stressor,))
        if ops := _STRESS_NG_STRESSOR_OPS.get(stressor):
            command += [f"--{stressor}-ops", str(int(ops))]
    command += ["--timeout", f"{seconds}s", "--metrics-brief",
                "--temp-path", str(temp_root)]
    
    start = time.monotonic()
    try:
        completed = run_command(
            command, check=False, cwd=temp_root,
            timeout=max(float(seconds) + 30, float(seconds) * 4),
        )
    except subprocess.TimeoutExpired as exc:
        raise RuntimeError(f"{workload_name} workload timed out") from exc
    elapsed = time.monotonic() - start
    
    if completed.returncode != 0:
        raise RuntimeError(
            f"{workload_name} workload failed: {tail_text(completed.stderr or completed.stdout)}"
        )
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total = sum(ops for _, ops in _stress_ng_metric_rows(combined))
    if ops_total <= 0:
        raise RuntimeError(
            f"{workload_name} workload did not report bogo-ops metrics: {tail_text(combined)}"
        )
    return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")
```

**改动量**：约 25-30 行（将循环展开改为单命令构建）
**影响范围**：ALL stress_ng_* workload 类型（10 个 corpus app + 部分 E2E）
**风险**：低。stress-ng 并发模式已验证，输出解析不变。唯一潜在风险：某些 stressor 的 port 参数冲突（已有 `_stress_ng_dynamic_stressor_args` 处理端口分配）。

---

## 三、并发工具组合——按 App 分析

### 3.1 tracee/monitor（158 progs，57 measurable = 36%）

**当前**: `stress_ng_os` (5 stressors) 顺序执行，duration_s=5.0
**实际采集时长**：5.0 × duration_s + 测量开销 ≈ 5s per-stressor × 5 = ~3-5s 并行 BPF measurement

**问题根源**：tracee 监控 158 个 hook（syscall/file/network/lsm），但 stress_ng_os 只覆盖 cap/eventfd/get/prctl/set 这 5 类系统调用。

**不可测的 101 个 prog 类别**：

| 类别 | prog 数 | 需要的 syscall/event |
|------|---------|---------------------|
| file/inode ops | 17 | chmod, rename, writev/readv, inotify, file_modified |
| security/lsm socket | 16 | socket bind, listen, setsockopt, sendmsg, recvmsg, sk_clone |
| dup/process_vm | 10 | dup2, dup3, process_vm_writev, kernel_write |
| exec/execveat | 8 | execve, execveat, bprm_committing_creds |
| lkm/debug | 20 | module_load, kprobe register, debugfs |
| cgroup | 5 | cgroup_attach_task, mkdir, rmdir（需 cgroup namespace） |
| uprobe | 5 | 特定二进制 uprobe（最难触发） |

**workload 覆盖分析**（使用现有 catalog kinds）：

| workload kind | 触发哪些 tracee hooks |
|---|---|
| `stress_ng_os` | prctl, cap, eventfd, get, set syscalls |
| `stress_ng_filesystem` | chmod, rename, inotify, hdd (vfs_write/read), open |
| `stress_ng_network` | epoll, sock, sockfd （socket bind/listen/setsockopt） |
| `fio_randrw` | vfs_write, vfs_read, file_modified, block I/O |
| `exec_storm` | execve, bprm_committing_creds |
| `stress_ng_process` | fork/clone/exec → bprm_committing_creds |

**推荐方案**：将 tracee 改为 `stress_ng_os_io_network`（已有，包含 os + io + network stressors）

修复 sequential bug 后，`stress_ng_os_io_network` 会并发触发：
- `cap/eventfd/get/prctl/set` → tracee syscall hooks
- `aio/aiol/io/iomix/io-uring/sync-file` → vfs_write/read hooks (可能)
- `epoll/sock/sockfd/udp-flood` → socket bind/listen hooks

**进一步的推荐**：添加新 catalog 入口使 tracee 使用 `stress_ng_os_io_network` + 额外 filesystem stressors

```python
# benchmark_catalog.py 修改 (1 行):
# 现状:
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os", duration_s=5.0),
# 改为（先用已有的更广 workload）:
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os_io_network", duration_s=5.0),
```

加上 sequential bug fix，tracee measurable 估计：57 → 65-75。

**更高 ROI（需新增 workload 种类）**：
将 `tracee_system_edge_mix` 定义为并发运行 `stress_ng_os` + `stress_ng_filesystem` + `fio_randrw` + `exec_storm`。需要在 workload.py 添加 ~40 行 `run_concurrent_workloads()` 函数。估计 measurable 57 → 75-90。

高信度触发覆盖：
- `stress_ng_filesystem` stressor `chmod` → `trace_chmod_common` (tracee hook) ✓ 直接对应
- `stress_ng_filesystem` stressor `rename` → `trace_security_inode_rename` ✓ 直接对应
- `stress_ng_filesystem` stressor `inotify` → `trace_inotify_find_inode` ✓ 直接对应
- `fio_randrw` → `trace_vfs_writev`, `trace_file_modified` ✓ fio 做 writev 系统调用
- `exec_storm` → `syscall__execve_enter/exit` ✓ exec storm 做 execve

### 3.2 tetragon/observer（287 progs，32 measurable = 11%）

**根本约束**：253/287（88%）是 tail-called，永远 run_cnt=0。可测上限约 34 个。

**当前**: `stress_ng_os_io_network`（20 stressor），顺序执行，BPF 测量窗口内只触发 1-2 种事件

**修复 sequential bug 后**：20 个 stressor 并发运行，估计 low-count progs（run_cnt=1-9）提升到 50+。

实际提升幅度：32 measurable 不变（上限 ~34），但现有 measurable 的 run_cnt 更均匀。

**进一步 workload 改进**：添加 `exec_storm` 并发，触发更多 `event_execve` 相关 progs

```python
# 改动（benchmark_catalog.py 1 行）：
MacroAppDefinition(name="tetragon/observer", runner="tetragon", workload="exec_storm", duration_s=3.0),
```

注意：tetragon 的 run_workload_spec 支持 `exec_storm` 种类，可以直接使用。

### 3.3 cilium/agent（25-49 progs，1-3 measurable = 4%）

**根本约束**：所有主要 sched_cls 都是 tail-called。可测上限约 3-5 个（TC entry progs）。

**当前**：`network` (wrk -t2 -c10 -d1s)，产生 ~140 req/s，run_cnt=312

**推荐改动**：提高 wrk 并发度（1 行 workload.py 改动）

```python
# workload.py 第 993 行，将 run_network_load 的 wrk 参数改为：
[wrk_binary, "-t4", "-c50", f"-d{max(1, int(duration_s))}s", server.url],
```

效果：140 → 700+ req/s，cil_from_netdev run_cnt: 312 → 1500+

**进一步**：同时跑 iperf3 UDP（需添加 iperf3 支持 ~30 行），触发 UDP 路径 prog。但 cilium UDP datapath 也是 tail-called，实际 measurable 不增加。

优先级：**中**。wrk 参数提升很简单但 measurable 数量不增加，只提高统计可信度。

### 3.4 calico/felix（6 progs，0 measurable）

**根本问题**：calico_tc_allow/deny 是 BPF JUMP MAP tail-call，conntrack_cleanup 是 timer-driven，cali_tcx_test 是一次性 capability probe。

**workload 改动不帮助**：即使 wrk 流量加大 100x，calico_tc_allow/deny 的 run_cnt 仍是 0（tail-call 约束）。

**真正需要的**：TC entry prog（`cali_from_host`/`cali_to_host`）需要在 daemon 采集窗口内被发现。这是 calico.py 中 HEP 注册时序问题，不是 workload 问题。

估计 measurable：0 → 可能 2（若 TC entry prog 被正确追踪到），不依赖 workload 改动。

### 3.5 otelcol-ebpf-profiler（13 progs，2 measurable）

**根本约束**：11 个 `perf_unwind_*` 都是 tail-called from `native_tracer_entry`。硬上限 = 2 measurable。

**otel 的 runner 已用 run_otel_profiler_cpu_mix_workload（多语言并发 CPU burn）**：
- shell, C, Go, Python, Node.js, Java, Ruby 并发 CPU burn
- 这已经是正确的多工具并发 workload

**问题**：catalog 写 `workload="stress_ng_cpu"`，但 OtelProfilerRunner._run_workload 只对 `"exec_storm"` 触发 cpu_mix，对 `"stress_ng_cpu"` 走 super() → 普通 stress-ng。

**catalog 修正**（1 行）：
```python
# 改前:
MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="stress_ng_cpu", duration_s=5.0),
# 改后（触发 cpu_mix 多语言路径）:
MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="exec_storm", duration_s=5.0),
```

效果：`native_tracer_entry` run_cnt 从 238 → 估计 800+（多个并发 CPU 进程）。measurable 数量不变（仍是 2），但统计可信度提高。

### 3.6 katran（3 progs，1 measurable）

**程序列表**：
- `xdp_root`: 36,474 次（直接 attach 在 katran0 XDP hook）
- `balancer_ingress`: 0（tail-called from xdp_root，永远不可测）
- `healthcheck_encap`: 0（sched_cls on ipip0，需要 katran → real server HC 流量）

**workload 改动效果**：
- 增加 wrk 并发度 → xdp_root run_cnt 提升（更可信）
- 同时跑 iperf3 UDP → 触发 UDP 路径（但 balancer_ingress 仍 tail-called）
- `healthcheck_encap`：需要 katran 对 real server 做 health check，workload 层面无法控制

估计：measurable 保持 1（xdp_root），run_cnt 可以从 36K 提升到 150K+。

### 3.7 BCC Apps (10 个工具)

| 工具 | 问题 | 推荐（使用现有 workload 种类） | 预期效果 |
|---|---|---|---|
| bcc/tcpconnect | 2 次触发（stress_ng_network 很少 TCP connect） | `workload="tcp_connect"` | 2 → 500+ triggers |
| bcc/execsnoop | 18 次触发（stress_ng_process 做 clone/fork，不做 exec） | `workload="exec_storm"` | 18 → 5000+ triggers |
| bcc/bindsnoop | 4 次触发（stress_ng_network 做极少 bind） | 需新增 workload，或改用 exec_storm+tcp_connect 混合 | 4 → 难预估 |
| bcc/biosnoop | 4.9M 触发（fio_randrw）| **保持** | 极好 |
| bcc/vfsstat | 127K 触发 | **保持** | 好 |
| bcc/capable | 93K 触发 | **保持** | 极好 |

**bcc/bindsnoop 具体分析**：
- `bindsnoop` hook 在 `security_socket_bind`（内核函数 kprobe）
- `stress_ng_network` 的 `sock` stressor 做 TCP socket → bind，但 OPS 限制（200次）下只做很少
- `run_tcp_connect_load`（即 `tcp_connect` workload）使用 curl 连接本地 HTTP server
  - curl 在每次请求中会做 bind（通常隐式）→ 可能触发 bindsnoop
  - 但这不是主要目的

**真正增加 bind 的方法**：stress-ng `sock` stressor 配置更多 ops（移除/放大 ops 限制），或使用 wrk（每个 connection 做 bind）。wrk -t4 -c100 产生 100 个并发连接，每个连接做 bind → ~100 次 bind/s。

```python
# bcc/bindsnoop 建议改为 network workload（使用 wrk 接口绑定）
MacroAppDefinition(name="bcc/bindsnoop", runner="bcc", workload="network", runner_args={"tool": "bindsnoop"}),
```

但注意：`bcc` runner 的 workload dispatch 不支持 `"network"` kind（只支持 stress_ng_* + fio_randrw + tcp_connect）。需要检查 bcc.py 的 run_workload_spec：

```python
# bcc.py:
def run_workload(self, seconds):
    return run_named_workload(self._spec.workload_spec["kind"], seconds, network_as_tcp_connect=True)
```

`network_as_tcp_connect=True` 意味着 `"network"` kind 实际走 `tcp_connect` → curl 循环。curl 做 bind 但数量少。

**最可行**：bcc/bindsnoop 改为 `tcp_connect`（每次 curl 连接做隐式 bind）+ 增加 duration_s 以做更多次。

### 3.8 bpftrace Apps

| 脚本 | 问题 | 推荐 | 预期效果 |
|---|---|---|---|
| bpftrace/tcplife | 9 次（stress_ng_network 很少完整 TCP 状态机） | `workload="tcp_connect"` | 9 → 500+ |
| bpftrace/tcpretrans | 0 次（loopback 几乎不丢包） | 需 tc netem → 高风险，暂不改 | 0（保持） |

**bpftrace/tcpretrans 分析（高信度评估）**：
- `tcp_retransmit_skb` kprobe 只在真正的 TCP 重传时触发
- loopback + stress_ng_network：接近 0 丢包，永远不会触发
- 可行方案：`tc netem delay 50ms loss 10%` 注入丢包 → 但需要 sch_netem 内核模块 + tc 权限
- iperf3 支持 `--loss` 但只对 UDP；TCP 重传需要真实网络丢包
- **结论**：tcpretrans 的 0 measurable 是 workload 问题（非 tail-call），但修复成本较高。暂不优先。

---

## 四、Container 工具可用性核查

### 4.1 已安装工具（来自 runner-runtime.Dockerfile apt-get 列表）

| 工具 | apt 包 | 状态 |
|---|---|---|
| stress-ng | `stress-ng` | ✅ 已安装 |
| fio | `fio` | ✅ 已安装 |
| wrk | `wrk` | ✅ 已安装 |
| curl | `curl` | ✅ 已安装 |
| hackbench | `rt-tests` | ✅ 已安装 |

### 4.2 额外工具（运行时核查）

| 工具 | 状态 | 用途 |
|---|---|---|
| iperf3 | ✅ 已安装（/usr/bin/iperf3） | TCP/UDP bandwidth + latency 测试 |
| sysbench | ✅ 已安装（/usr/bin/sysbench） | CPU/memory/fileio benchmark |

注：iperf3 和 sysbench 已在系统中，但 workload.py 中没有任何对应的调用代码。如需使用需添加。

### 4.3 工具能力对比

| 工具 | 适合场景 | tracee hooks 覆盖 |
|---|---|---|
| stress-ng (network stressors) | socket bind/listen/UDP | security_socket_bind, security_socket_listen |
| iperf3 -s/-c | TCP/UDP bandwidth | security_socket_bind, security_socket_setsockopt, security_socket_sendmsg, security_socket_recvmsg |
| wrk -t4 -c50 | HTTP load (multi-connection) | security_socket_bind（每个 conn），security_sk_clone（每个 conn） |
| fio randrw | 块 I/O + VFS | trace_vfs_writev, trace_file_modified |
| exec_storm (stress-ng --exec) | execve | syscall__execve_enter/exit, bprm_committing_creds |
| hackbench | scheduler events | sched_switch, sched_wakeup（已有 stress_ng_scheduler） |

---

## 五、并发 Workload 基础设施——最小改动方案

### 5.1 方案 A：仅修复 stress-ng sequential bug（~30 行）

**改动文件**：`runner/libs/workload.py`
**改动位置**：`run_stress_ng_class_load`（第 467-512 行）
**改动描述**：将 `for stressor in normalized_stressors: run_command(...)` 改为构建单一并行 stress-ng 命令

**影响**：ALL stress_ng_* workload 种类并发执行 stressor，性能大幅提升
**风险**：低（stress-ng 并发模式已验证，输出解析不变）

### 5.2 方案 B：添加 run_concurrent_workloads() 辅助函数（~40 行）

用于跨工具并发（stress-ng + fio + iperf3 同时运行）：

```python
def run_concurrent_workloads(
    kinds: Sequence[str],
    duration_s: int | float,
    *,
    network_device: str | None = None,
) -> WorkloadResult:
    """
    并发运行多个 workload，等待所有完成后合并结果。
    对 run_named_workload 的每个 kind 使用 threading.Thread 并发执行。
    """
    import threading
    results: list[WorkloadResult | BaseException] = [RuntimeError("not started")] * len(kinds)
    
    def _run(idx: int, kind: str) -> None:
        try:
            results[idx] = run_named_workload(kind, duration_s, network_device=network_device)
        except BaseException as exc:
            results[idx] = exc
    
    threads = [threading.Thread(target=_run, args=(i, kind), daemon=True) for i, kind in enumerate(kinds)]
    for t in threads:
        t.start()
    for t in threads:
        t.join(timeout=float(duration_s) + 60)
    
    # 检查失败
    errors = [r for r in results if isinstance(r, BaseException)]
    if errors:
        raise RuntimeError(f"concurrent workload failed: {errors[0]}") from errors[0]
    
    return _merge_workload_results([r for r in results if isinstance(r, WorkloadResult)])
```

注意：`_merge_workload_results` 已在 workload.py 第 251 行实现，但从未被调用。可直接复用。

然后在 `run_named_workload` 中添加对新复合 kind 的支持：

```python
# run_named_workload 中添加：
if kind == "stress_ng_os_io_network_filesystem":
    return run_concurrent_workloads(
        ["stress_ng_os", "stress_ng_filesystem", "stress_ng_network"],
        duration_s,
    )
if kind == "stress_ng_os_filesystem_fio":
    return run_concurrent_workloads(
        ["stress_ng_os", "stress_ng_filesystem", "fio_randrw"],
        duration_s,
    )
```

**改动量**：~40 行新函数 + 在 `run_named_workload` 中 ~10 行新 kind 支持 + catalog.py 2-3 行

### 5.3 方案 C：benchmark_catalog.py 中使用已有 workload 种类（0 新代码）

仅靠改 catalog 能做的改动（无需改 workload.py）：

```python
# bcc/tcpconnect: stress_ng_network -> tcp_connect (工具已有)
MacroAppDefinition(name="bcc/tcpconnect", runner="bcc", workload="tcp_connect", runner_args={"tool": "tcpconnect"}),

# bcc/execsnoop: stress_ng_process -> exec_storm (工具已有)
MacroAppDefinition(name="bcc/execsnoop", runner="bcc", workload="exec_storm", runner_args={"tool": "execsnoop"}),

# bpftrace/tcplife: stress_ng_network -> tcp_connect (工具已有)
MacroAppDefinition(name="bpftrace/tcplife", runner="bpftrace", workload="tcp_connect", runner_args={"script": "tcplife"}),

# tracee: stress_ng_os -> stress_ng_os_io_network (已有，覆盖更广)
MacroAppDefinition(name="tracee/monitor", runner="tracee", workload="stress_ng_os_io_network", duration_s=5.0),

# otelcol: stress_ng_cpu -> exec_storm (触发 cpu_mix 多语言路径)
MacroAppDefinition(name="otelcol-ebpf-profiler/profiling", runner="otelcol-ebpf-profiler", workload="exec_storm", duration_s=5.0),
```

**需要注意**：
- `bcc` runner 的 workload dispatch（bcc.py:430-446）支持 `tcp_connect` 和 `exec_storm`（通过 `run_named_workload`），可以直接使用
- `tracee` runner 的 run_tracee_workload（tracee.py:230-239）支持 `stress_ng_os_io_network`
- `otelcol-ebpf-profiler` runner 的 _run_workload 对 `exec_storm` 触发 cpu_mix

---

## 六、触发覆盖理论验证

### 6.1 高信度推荐（hook → syscall 关系明确）

| 推荐 workload | 目标 hook | syscall/event | 信度 |
|---|---|---|---|
| `exec_storm` → bcc/execsnoop | `sys_execve` kprobe | execve 系统调用 | 极高 |
| `tcp_connect` → bcc/tcpconnect | `tcp_v4_connect` kprobe | TCP connect 系统调用 | 极高 |
| `tcp_connect` → bpftrace/tcplife | `tcp_set_state` kprobe | TCP 状态变化 | 高 |
| `stress_ng_filesystem` + parallel → tracee | `trace_chmod_common` | chmod 系统调用 | 高 |
| `stress_ng_filesystem` + parallel → tracee | `trace_security_inode_rename` | rename 系统调用 | 高 |
| `fio_randrw` → tracee | `trace_vfs_writev`, `trace_file_modified` | pwrite/writev | 高 |
| `stress_ng_network` (epoll/sock) → tracee | `trace_security_socket_bind` | socket bind | 中等 |

### 6.2 实验性推荐（信度较低）

| 推荐 workload | 目标 hook | 不确定因素 |
|---|---|---|
| iperf3 → cilium UDP path | UDP TC programs | Cilium UDP datapath 也是 tail-called |
| stress_ng_network sock → calico TC allow | calico_tc_allow | tail-call 约束 + TC attach 时序 |
| bpftrace/tcpretrans with packet loss | tcp_retransmit_skb | 需要 sch_netem 内核模块 |

---

## 七、优先级与改动量汇总表

| Priority | App | 现 workload | 推荐 | 估算 measurable | 改动行数 | 文件 |
|---|---|---|---|---|---|---|
| **P0** | 所有 stress_ng_* | 顺序执行 | 修复为并行执行 | 全局提升 trigger 密度 | ~30 行 | workload.py |
| **P0** | tracee/monitor | stress_ng_os | stress_ng_os_io_network | 57 → 65-70 | 1 行 | benchmark_catalog.py |
| **P0** | bcc/tcpconnect | stress_ng_network | tcp_connect | triggers: 2 → 500+ | 1 行 | benchmark_catalog.py |
| **P0** | bcc/execsnoop | stress_ng_process | exec_storm | triggers: 18 → 5000+ | 1 行 | benchmark_catalog.py |
| **P1** | otelcol-ebpf-profiler | stress_ng_cpu | exec_storm | native_tracer_entry: 238 → 800+ | 1 行 | benchmark_catalog.py |
| **P1** | bpftrace/tcplife | stress_ng_network | tcp_connect | triggers: 9 → 500+ | 1 行 | benchmark_catalog.py |
| **P1** | cilium/agent | wrk -t2 -c10 | wrk -t4 -c50 | cil_from_netdev: 312 → 1500+ | 1 行 | workload.py |
| **P1** | tracee/monitor | stress_ng_os_io_network | 添加 concurrent fio_randrw | 65-70 → 75-85 | ~50 行 | workload.py + catalog |
| **P2** | tetragon/observer | stress_ng_os_io_network | + exec_storm 并发 | 32 不变，low-count 提升 | ~50 行 | workload.py + catalog |
| **P2** | katran | network (4 conn) | network (16 conn) | xdp_root: 36K → 150K | 1 行 | benchmark_catalog.py |
| **P3** | bcc/bindsnoop | stress_ng_network | 需新 workload kind | 可能 4 → 50+ triggers | ~30 行 | workload.py |
| **P3** | bpftrace/tcpretrans | stress_ng_network | tc netem + packet loss | 0 → 可能 100+ | 高风险 | 多文件 |
| **X** | otelcol perf_unwind_* | 任何 | 无解（tail-call）| 硬上限 2 measurable | - | - |
| **X** | tetragon 253 tail-call progs | 任何 | 无解（tail-call）| 硬上限 ~34 measurable | - | - |
| **X** | calico tail-call progs | 任何 | 无解（tail-call）| 硬上限 ~4 measurable | - | - |

---

## 八、关键结论

### 8.1 是否需要新增 run_concurrent_workloads()？

**True**。需要添加并发辅助函数，但步骤分两阶段：

1. **先修 sequential bug**（P0，约 30 行）：让 stress-ng 并发执行所有 stressor。这是单一最高 ROI 改动，影响所有 stress_ng_* workload。

2. **再添加跨工具并发**（P1，约 50 行）：添加 `run_concurrent_workloads()` + 新复合 kind（例如 `stress_ng_os_filesystem_fio`），让 tracee 同时跑 stress-ng + fio。

### 8.2 Top-3 高 ROI 推荐

1. **修复 stress-ng sequential bug**（P0，~30 行 workload.py）：将 run_stress_ng_class_load 的顺序 for 循环改为单一并发 stress-ng 调用。影响全部 stress_ng_* workload app，所有 stressor 在同一秒内并发触发，显著提升 BPF hook 命中密度。

2. **tracee workload 从 stress_ng_os 改为 stress_ng_os_io_network**（P0，1 行 benchmark_catalog.py）：结合 sequential bug fix，tracee measurable 从 57 → 65-70，覆盖 network socket hooks（epoll/sock stressors）和 IO hooks（aio/io stressors）。

3. **bcc/tcpconnect + bpftrace/tcplife 改用 tcp_connect workload**（P0，各 1 行 catalog）：tcpconnect 的 `tcp_v4_connect` kprobe 从 2 次触发 → 500+，tcplife 的 `tcp_set_state` 从 9 次 → 500+。`tcp_connect` workload（curl 循环）已在 workload.py 中实现，无需新代码。

---

*数据来源：x86 KVM corpus runs 2026-05-04（SAMPLES=1，kop-only）*
*代码分析：runner/libs/workload.py, runner/libs/benchmark_catalog.py, runner/libs/app_runners/*.py*

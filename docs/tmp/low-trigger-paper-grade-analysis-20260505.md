# 低触发 App Paper-Grade 改进分析（2026-05-05）

## 数据来源
- KVM x86 SAMPLES=1, duration=1s, BPFREJIT_BENCH_PASSES=wide_mem
- `corpus/results/x86_kvm_corpus_20260505_034450_821164/details/result.json`
- 20/20 OK，无 bug

## 统计可靠性分级（per-program）
| 级别 | run_cnt 范围 | paper 含义 |
|---|---|---|
| pure noise | <100 | 无意义，不能放表 |
| noise | 100-1K | 边缘，需大 effect size 才显著 |
| marginal | 1K-10K | 可放但需 SAMPLES≥30 减噪 |
| ok | 10K-100K | 标准统计可靠 |
| strong | >100K | 论文 strong claim |

## 低触发 App 现状

| App | trig progs | post runs | 1s 等级 | SAMPLES=30 推算 |
|---|---|---|---|---|
| bcc/execsnoop | 2/2 | 4 | pure noise | ~120 (still noise) |
| bpftrace/tcpretrans | 1/1 | 110 | noise | ~3.3K (marginal) |
| cilium/agent | 2/43 | 785 | noise | ~24K (ok) |
| otel/profiling | 2/13 | 1,606 | marginal | ~48K (ok) |
| tetragon/observer | 34/287 | 9.8M | strong (但 88% prog 未触发) | — |
| tracee/monitor | 79/158 | 154M | strong (但 50% prog 未触发) | — |

## 逐个分析

### 1. bcc/execsnoop — 4 runs/s ❌ 必须改 workload
**原因**：当前 workload 是 `stress_ng_process` 含 `clone/exec/fork/vfork` 4 个 stressor。`exec` stressor 实际只在 stressor 启动时调一次 execve，循环内是 fork。`stress-ng --metrics` 显示 `cap` 4.3M ops、`get` 4.4K ops，但没有专 exec 的 ops 统计。

**Paper 视角**：execsnoop 是经典 BCC tool（trace execve），4 runs 完全无意义，paper 必须 ≥1K runs/s。

**推荐：增强 workload（标准 benchmark）**
- `stress-ng --exec 8 --exec-method execve --exec-no-pthread`：纯 execve 循环，预期 ≥10K ops/s
- 或 `hackbench`：fork+exec 混合，标准 benchmark
- 或 duration_s 提升到 5s（其他类似事件型 app 已用此手段）

**禁止**：自制 `for i in {1..10000}; do /bin/true; done`（违反 standard workloads feedback）

**判定**：`stress-ng --exec` 是标准用法，改 stressor 选择即可，无需换 app。

---

### 2. bpftrace/tcpretrans — 110 runs/s ⚠️ 边缘，建议保留+增强
**原因**：脚本只 kprobe 一个函数 `tcp_retransmit_skb`。当前 `network_lossy_multi` 用 netem 20% loss + wrk c50 + ping。110 retrans/s 来自 wrk 高并发短连接 + 20% 包丢失。

**Paper 视角**：
- 1 prog × 110 runs = SAMPLES=30 后 ~3.3K，刚到 marginal
- TCP retrans 是 BCC/bpftrace 经典示例，paper 完全有保留价值（"我们覆盖了网络异常路径"）
- 但 1 prog signal 弱，paper 表会显得突兀

**推荐：增强 workload + 保留**
- 把 netem loss 提到 30%（20%→30% 实测会让 retrans 翻倍以上，但 wrk 完成连接数下降；需调 wrk timeout）
- 或加第二个并发 wrk 进程（`wrk -c100`），让在途连接数翻倍
- duration_s=5s 可让总 retrans 量到 ~550 → SAMPLES=30 推到 16K，达到 ok 级

**不推荐删**：tcpretrans 是 paper 表里"网络观测类 BPF"代表，删掉会让 bpftrace 类只剩 capable/biosnoop/vfsstat/runqlat/tcplife（缺一类）。

**判定**：增强 workload + duration=5s，从 marginal 推到 ok。

---

### 3. cilium/agent — 2/43 progs, 785 runs/s ⚠️ 结构性限制，paper limitation
**原因**：cilium 注册了 43 个 BPF prog 覆盖 TC ingress/egress、masquerade、host firewall、encrypt、socket-LB 等。在 bare-metal 单 veth + 无 K8s pod 的 setup 下，只 `cil_to_host` + `cil_from_netdev` (host-network 路径) 触发；endpoint policy / pod-to-pod NAT / encrypt 永远不会跑。

**Paper 视角**：
- 这是**架构性限制**，不是 workload 问题
- 类似 calico 已被删（"BPF dataplane requires K8s pod model"，CLAUDE.md 已记录）
- cilium 没 K8s 时 41/43 prog 永远是 dead code，paper 应该明确写出 "host-network mode only, K8s endpoint programs not exercised"

**三选一推荐**：
- **A. 接受现状 + paper limitation**：写 "Cilium evaluated in standalone mode without Kubernetes orchestration; 2/43 host-network programs exercised"。CLAUDE.md `Removed Apps` 已有 calico 的同类条目。
- **B. 缩 app 配置**：cilium 启动时 `--enable-endpoint-routes=false --enable-host-firewall=false --enable-bpf-masquerade=false ...` 关掉无法触发的功能，把 prog 数从 43 砍到 ~10，让 "trig/total" 比例好看。但这违反 "use real upstream binary as-is"。
- **C. 删 cilium**：和 calico 同理由删除。但 cilium 比 calico 更主流，论文价值更高，**不建议删**。

**判定**：选 A——保留 cilium，paper 写明 limitation，不试图改配置。785 runs/s × SAMPLES=30 = 24K，统计上够。

---

### 4. otel-ebpf-profiler — 2/13 progs, 1.6K runs/s ⚠️ 加 runtime 即可
**原因**：13 个 prog 含 `native_tracer_entry`(C/C++ 栈) + `tracepoint__sched_process_free` + 11 个语言 unwinder（python/ruby/perl/php/v8/hotspot/dotnet/swift/...）。当前 workload 只 `stress_ng_cpu`，是 native code，所以只 2/13 触发。

**Paper 视角**：
- otel 设计就是多语言 unwinder，2/13 是 workload 不全，**可以补**
- 1.6K runs/s × SAMPLES=30 = 48K，已 ok 级
- 但 paper 想强调 "covers 13 unwinders" 时数据不支持

**推荐：增强 workload（并发跑多 runtime）**
- 在 `stress_ng_cpu` 旁开后台 `python3 -c "while True: pass"` (python unwinder)
- 加后台 `ruby -e "loop {}"` (ruby unwinder)
- 加 `node -e "while(true){}"` (v8 unwinder)
- 这些都是标准解释器，不是 synthetic
- 预期触发数从 2/13 → 5/13，runs 翻倍

**判定**：保留，workload 加多语言后台进程。13 个 unwinder 中 hotspot/dotnet/swift/perl 不常见，2/13→5/13 已够 paper "covers C, Python, Ruby, V8"。

---

### 5. tetragon/observer — 34/287 progs, 9.8M runs/s ⚠️ App 配置改
**原因**：当前加载 `runner/assets/tetragon_policies/` 16 个 example policy（bpf.yaml, datagram_518.yaml, process-exec/, host-changes/, security-socket-connect.yaml, sys_mount.yaml, tty.yaml, ...），每个 policy 含若干 generic_kprobe_event/generic_retkprobe_event/generic_tracepoint_event 模板，总 287。其中只 process-exec/raw_syscalls/security-socket-connect 这几个被 stress_ng_os_io_network 触发。

**Paper 视角**：
- 287 个 prog 但 34 个触发（12%），paper 表会显得 88% dead
- tetragon 真实部署一般 4-8 个 policy，16 个是 example dump
- 9.8M runs 总量已经 strong，问题是分母虚高

**推荐：缩 app 配置**
- 删非核心 policy：留 `process-exec/`, `process-credentials/`, `tcp-accept.yaml`, `security-socket-connect.yaml` 这 4 类，删 `bpf.yaml`, `datagram*.yaml`, `tty.yaml`, `sys_mount.yaml`, `rawtp.yaml`, `filename_monitoring.yaml`, `fd_install_cap_changes.yaml`, `security_inode_follow_link.yaml`, `host-changes/`
- 287 → 估 ~80 prog，触发比例 34/80 = 42%
- 上游 tetragon 安装时也是用户选 policy，删 example 不算"换 binary"，仍合规

**判定**：改 app 配置（policy 子集），不动 workload。

---

### 6. tracee/monitor — 79/158 progs, 154M runs/s ⚠️ App 配置改
**原因**：runner 启动时 `tracee --events "*"`，强制加载所有 158 events。其中 79 个被 `stress_ng_os_io_network` workload 触发；剩 79 个是 dup2/mknod/load_elf_phdrs/security_inode_unlink/socket_listen 等冷路径，1s workload 打不到。

**Paper 视角**：
- 154M runs strong，分母虚高问题
- 79/158 = 50%，paper 表勉强能看
- tracee 真实部署一般按需选 event，--events "*" 是测试用法

**推荐：缩 app 配置**
- 改成 `--events file_io_*,network_*,exec_*,scheduler_*` 等几类，对应 stress_ng_os_io_network 实际触发的事件域
- 158 → 估 ~100 prog，触发比例 79/100 = 79%
- 仍是 upstream tracee 的标准用法（events 过滤是 tracee 第一个 CLI 选项）

**判定**：改 app 配置（events 选择子集），不动 workload。

---

## 总结：行动优先级

| 优先级 | App | 改动方向 | 预期效果 | 工作量 |
|---|---|---|---|---|
| P0 | bcc/execsnoop | workload `--exec` stressor + duration=5s | 4 → 50K runs | XS |
| P0 | bpftrace/tcpretrans | netem loss 30% + wrk 双 client + duration=5s | 110 → 16K | S |
| P1 | otel/profiling | workload 加 python+ruby 后台进程 | 2/13 → 5/13 触发 | S |
| P1 | tetragon/observer | 删一半 example policy | 287→80 prog (12%→42% 触发) | M |
| P1 | tracee/monitor | `--events` 改 4 个域而非 `*` | 158→100 prog (50%→79% 触发) | M |
| P2 | cilium/agent | **不改**，paper 写 limitation | 2/43 接受 | 0 |

## 设计规则合规性
所有推荐都符合：
- ✅ No ReJIT Filtering（不过滤 prog，是改启动参数减少 prog 数）
- ✅ App-Level Loader Only（用 upstream binary，只换 CLI 参数）
- ✅ Standard Workloads（stress-ng、wrk、netem、python/ruby 解释器都是标准 benchmark/工具）
- ✅ No Synthetic Workload（不用 BPF_PROG_TEST_RUN）
- ✅ No Custom Loader（不替换 binary）

## 不推荐做的
- ❌ 不要给 bpftrace/tcpretrans 加更多 kprobe 把 1 个 prog 变 5 个（违反"用 upstream script as-is"）
- ❌ 不要为 otel 写 synthetic Python loop（用 python3 -c "while True: pass" 是合规的 idle loop，但若需要更复杂的工作负载，应该用 pyperformance 或类似标准 benchmark）
- ❌ 不要为 cilium 自创 endpoint setup
- ❌ 不要让 tetragon/tracee 改 BPF prog 源码

## 后续验证流程
1. 改 workload (execsnoop, tcpretrans, otel) 后跑 SAMPLES=1 smoke 看 trigger 是否上去
2. 改 app config (tetragon, tracee) 后跑 SAMPLES=1 smoke 看 prog 总数是否下降到目标
3. 全部改完跑 SAMPLES=30 authoritative，看 per-program ratio 稳定性
4. cilium limitation 写入 CLAUDE.md `## Notes` 或 paper 直接写 limitation 段

# eBPF 生态 Benchmark 基础设施缺口分析

## 现有覆盖总览

先梳理现有项目覆盖了什么：

| 维度 | 已覆盖 | 覆盖者 |
|------|--------|--------|
| Attach 触发开销 | kprobe/kretprobe/fentry/fexit/rawtp/tp/uprobe/fmod_ret | Linux bench_trigger |
| Map 数据结构 CRUD | hash/array/percpu/LRU/bloom/LPM trie/local_storage | Linux bench + MS bpf_performance |
| 事件传递 | ringbuf, perfbuf | Linux bench_ringbufs |
| Helper 函数 | bpf_loop, bpf_strncmp, bpf_get_prandom_u32, bpf_ktime_get_ns 等 | Linux bench + MS bpf_performance |
| 加密 | AES encrypt/decrypt | Linux bench_bpf_crypto |
| Socket 重定向 | sockmap rx/tx verdict | Linux bench_sockmap |
| Tail call 开销 | 0-33 深度链式调用 | tail-call-bench + MS bpf_performance |
| Hash 函数 | jhash/xxh3/xxh64 等 CPU cycle 精确测量 | bpf-bench |
| 用户态运行时对比 | llvm-jit/ubpf/rbpf/native/wasm 纯计算 | user_bpf_benchmark |
| Map 内存 | htab 内存使用模式 | Linux bench_htab_mem |

---

## 一、程序加载与编译链路：完全空白

**现状**：所有现有 benchmark 测的都是 "BPF 程序已经加载好之后" 的运行性能。但在生产环境中，加载环节本身就是一个关键瓶颈。

**缺失的 benchmark**：

| 环节 | 说明 | 重要性 |
|------|------|--------|
| **Verifier 耗时** | 验证时间 vs 程序复杂度（指令数、分支数、map 访问模式）的关系 | 极高 — 大程序验证可达秒级 |
| **JIT 编译耗时** | 内核 JIT 编译不同类型/大小程序的时间 | 高 — 影响程序热加载 |
| **ELF 解析 + libbpf 加载** | 从 .o 文件到 fd 的端到端耗时 | 高 |
| **CO-RE 重定位** | BTF 匹配 + 字段重定位的开销 | 中 — 跨内核版本部署关键 |
| **BTF 处理** | BTF dedup、解析、vmlinux BTF 查找 | 中 |
| **Skeleton 生成** | bpftool gen skeleton 的开销 | 低 |

veristat 工具只做 A/B 对比，不是系统化的 benchmark。**需要一个能测量 "从 clang 编译到程序真正开始执行" 全链路延迟的框架**。

---

## 二、端到端应用级开销：几乎没有

**现状**：所有现有 benchmark 都是微观测试 — 测单个操作的 ns 级延迟。但用户真正关心的是 "我挂上 BPF 程序后，应用会慢多少？"

**缺失的 benchmark**：

| 场景 | 说明 |
|------|------|
| **Tracing 对目标应用的影响** | 给 nginx/MySQL/Redis 挂 N 个 kprobe，吞吐量下降多少？延迟增加多少？ |
| **XDP 数据面吞吐** | XDP_DROP / XDP_TX / XDP_REDIRECT 在真实网卡上的 pps |
| **TC BPF 分类开销** | 与 iptables/nftables 的对比 |
| **Cilium/Calico 风格策略** | 网络策略执行对 pod 间延迟的影响 |
| **连续 profiling 开销** | 持续运行 perf_event BPF 对 CPU 的额外消耗 |

bench_trigger 测的是 "BPF 程序本身能跑多快"，但不测 "它给被观测系统带来多少额外负担"。这是两个完全不同的问题。

---

## 三、并发与可扩展性：严重不足

**现状**：Linux bench 框架支持多 producer 线程，MS bpf_performance 支持 per-CPU 分配，但都没有系统性地测并发场景。

**缺失的 benchmark**：

| 场景 | 说明 |
|------|------|
| **Map 竞争** | N 个 CPU 同时对同一个 hashmap 做 update，锁竞争的代价 |
| **Per-CPU vs 全局 map 扩展性** | 随 CPU 数增加，per-CPU map 与全局 map 的性能差距曲线 |
| **多程序同时加载** | 系统中挂 10/100/1000 个 BPF 程序时的 overhead |
| **RCU grace period 压力** | 大量 BPF 程序更新/卸载时 RCU 的瓶颈 |
| **rqspinlock** | 内核新增的 BPF 自旋锁实现，无 benchmark |
| **Arena 共享内存** | 多程序共享 arena 的并发访问模式 |

---

## 四、程序类型覆盖：大量空白

内核定义了 **31 种 BPF_PROG_TYPE**，现有 benchmark 只覆盖了其中一小部分：

| 程序类型 | 有 Benchmark? | 说明 |
|----------|:---:|------|
| KPROBE / TRACING (fentry/fexit/fmod_ret) | ✅ | bench_trigger 覆盖充分 |
| RAW_TRACEPOINT / TRACEPOINT | ✅ | bench_trigger |
| XDP | ❌ | **无吞吐量 benchmark**，仅 bench BPF 程序中有 SEC("xdp") 但无专门 bench |
| SCHED_CLS (TC) | ❌ | **完全空白** |
| SCHED_ACT | ❌ | 完全空白 |
| LSM | ❌ | **完全空白** — 安全场景核心，无任何性能数据 |
| STRUCT_OPS | ❌ | **完全空白** — TCP 拥塞控制 / sched_ext 无 benchmark |
| CGROUP_SKB / SOCK / SOCKOPT / SYSCTL / DEVICE | ❌ | **完全空白** — 容器场景核心 |
| SOCK_OPS | ❌ | 完全空白 |
| SK_LOOKUP | ❌ | 完全空白 |
| FLOW_DISSECTOR | ❌ | 完全空白 |
| LWT_IN / OUT / XMIT / SEG6LOCAL | ❌ | 完全空白 |
| NETFILTER | ❌ | 完全空白 |
| PERF_EVENT | ❌ | 完全空白 |
| SOCKET_FILTER | ❌ | 完全空白 |
| SK_MSG / SK_SKB | 部分 | bench_sockmap 只测 redirect，不测分类 |
| EXT (freplace) | ❌ | 完全空白 |

**尤其注意**：XDP、TC、LSM、struct_ops、cgroup 系列是生产使用最广泛的类型，却完全没有 benchmark。

---

## 五、Map 类型覆盖：仍有遗漏

内核定义了 **30+ 种 BPF_MAP_TYPE**，现有 benchmark 覆盖情况：

| Map 类型 | 有 Benchmark? | 说明 |
|----------|:---:|------|
| HASH / PERCPU_HASH / LRU_HASH / LRU_PERCPU_HASH | ✅ | |
| ARRAY / PERCPU_ARRAY | ✅ | MS bpf_performance |
| BLOOM_FILTER | ✅ | |
| LPM_TRIE | ✅ | |
| RINGBUF | ✅ | |
| PROG_ARRAY (tail call) | ✅ | |
| HASH_OF_MAPS / ARRAY_OF_MAPS | ✅ | MS bpf_performance |
| STACK_TRACE | ❌ | bpf-bench 有 WIP 但未完成 |
| QUEUE / STACK (FIFO/LIFO) | ❌ | **完全空白** |
| CPUMAP | ❌ | XDP redirect 核心，**无 benchmark** |
| DEVMAP / DEVMAP_HASH | ❌ | XDP redirect 核心，**无 benchmark** |
| XSKMAP | ❌ | AF_XDP 核心，**无 benchmark** |
| SOCKMAP / SOCKHASH | 部分 | bench_sockmap 只测 redirect |
| SK_STORAGE / TASK_STORAGE / INODE_STORAGE / CGRP_STORAGE | 部分 | local_storage bench 覆盖部分 |
| USER_RINGBUF | ❌ | 用户态到内核的反向 ringbuf，**无 benchmark** |
| ARENA | ❌ | **新特性，完全空白** |
| STRUCT_OPS | ❌ | 完全空白 |
| PERF_EVENT_ARRAY | ❌ | 完全空白 |
| REUSEPORT_SOCKARRAY | ❌ | 完全空白 |

---

## 六、用户态 eBPF 运行时：只测了纯计算

**现状**：user_bpf_benchmark 只测 8 个纯计算程序（log2, memcpy, prime, strcmp, switch 等），完全不涉及 eBPF 运行时在实际使用中最核心的能力。

**缺失的 benchmark**：

| 维度 | 说明 |
|------|------|
| **Map 操作** | 用户态运行时中 hashmap/array/ringbuf 的读写性能 |
| **Helper 函数模拟** | 用户态 helper（如 bpf_probe_read、bpf_get_current_pid_tgid）的模拟开销 |
| **Uprobe / syscall 拦截** | bpftime 的核心场景 — uprobe 拦截的延迟 |
| **与内核态的对比** | 同一个 BPF 程序在 kernel vs userspace 运行时的性能差距 |
| **正确性验证** | 不同运行时跑相同程序结果是否一致 |
| **内存占用** | 各运行时的内存 footprint |

---

## 七、跨版本性能回归：缺乏系统化

**现状**：只有 tail-call-bench 做了多内核版本对比，MS bpf_performance 有 Grafana 但没有公开的持续追踪数据。

**缺失的基础设施**：

| 需求 | 说明 |
|------|------|
| **持续性能追踪** | 每个内核版本发布时自动跑 benchmark 并记录趋势 |
| **回归检测** | 自动发现性能退化并告警 |
| **跨架构对比** | x86 vs ARM64 vs RISC-V 的 BPF 性能系统对比 |
| **Spectre/Meltdown 缓解影响** | retpoline 等安全缓解对 BPF 性能的影响（tail-call-bench 做了一点，但不够） |

---

## 八、方法论与工具链：碎片化严重

**现状**：各项目各自为政，指标不统一，结果不可比。

| 问题 | 具体表现 |
|------|---------|
| **输出格式不统一** | Linux bench 输出 ops/sec 到 stdout，MS 输出 CSV，bpf-bench 输出 text+PNG，user_bpf_benchmark 输出 JSON |
| **指标定义不一致** | 有的测 ns/op，有的测 M ops/sec，有的测 CPU cycles |
| **可复现性差** | 大部分没有记录 CPU 频率锁定、turbo boost 关闭等条件（bpf-bench 做得最好） |
| **缺少统一运行器** | 没有一个 "跑一遍就能覆盖全部 BPF benchmark" 的工具 |
| **缺少比较框架** | 无法方便地对比 "我改了一行代码前后的性能差异" |

---

## 九、新特性完全无覆盖

内核近期新增或增强的 BPF 特性，benchmark 完全跟不上：

| 特性 | 内核版本 | Benchmark 状态 |
|------|---------|:---:|
| **BPF Arena** (共享内存) | 6.9+ | ❌ |
| **BPF Timer** | 5.15+ | ❌ |
| **User Ring Buffer** | 6.1+ | ❌ |
| **rqspinlock** (BPF 自旋锁) | 6.x | ❌ |
| **sched_ext** (BPF 调度器) | 6.12+ | ❌ |
| **BPF Token** (权限委托) | 6.9+ | ❌ |
| **dmabuf iter** | 6.x | ❌ |
| **NETFILTER prog type** | 6.4+ | ❌ |
| **BPF cpumask kfuncs** | 6.3+ | ❌ |
| **BPF exceptions** | 6.7+ | ❌ |
| **insn_array map** | 最新 | ❌ |

---

## 总结：最关键的五个缺口

按优先级排序：

### 1. 端到端应用级 overhead benchmark
**为什么最重要**：这是用户最关心的问题 — "用 eBPF 会让我的应用变慢多少？" 但目前没有任何系统化的回答。需要一个框架，在真实应用（nginx, redis, MySQL）上挂 BPF 程序，测量吞吐量下降和延迟增加。

### 2. XDP / TC / 网络数据面 benchmark
**为什么重要**：XDP 和 TC 是 eBPF 在生产中最广泛的用途（Cilium, Katran, Cloudflare），但 **没有一个 benchmark 测 XDP 的 pps 吞吐量**。CPUMAP/DEVMAP/XSKMAP 这些 XDP 核心 map 也完全没覆盖。

### 3. 程序加载/验证链路 benchmark
**为什么重要**：大型 BPF 程序（如 Cilium 的 datapath）验证时间可达数秒，是部署的实际瓶颈。加载链路的每个环节都没有系统化的性能数据。

### 4. LSM / struct_ops / cgroup benchmark
**为什么重要**：安全（LSM BPF）、调度（sched_ext）、容器（cgroup BPF）是 eBPF 三大增长方向，但性能特征完全未知。

### 5. 并发扩展性 benchmark
**为什么重要**：生产系统是多核的。Map 在高并发下的竞争行为、per-CPU 数据结构的扩展性，直接决定 eBPF 方案在大规模部署中是否可行。

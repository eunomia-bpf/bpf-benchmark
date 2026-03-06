# eBPF 性能研究全景与 Benchmark 基础设施缺口分析

> 基于对现有 benchmark 基础设施、90+ 篇学术论文、以及 Linux 内核代码的系统分析。

---

## 一、现有 Benchmark 基础设施覆盖了什么

| 维度 | 已覆盖 | 工具/项目 |
|------|--------|-----------|
| Attach 触发开销 | kprobe/fentry/fexit/rawtp/uprobe/fmod_ret (~40 变体) | Linux bench_trigger |
| Map CRUD | hash/array/percpu/LRU/bloom/LPM/local_storage | Linux bench + MS bpf_performance |
| 事件传递 | ringbuf, perfbuf | Linux bench_ringbufs |
| Helper 函数 | bpf_loop, bpf_strncmp, bpf_get_prandom_u32, bpf_ktime_get_ns 等 | Linux bench + MS bpf_performance |
| 加密 | AES encrypt/decrypt | Linux bench_bpf_crypto |
| Socket 重定向 | sockmap rx/tx verdict | Linux bench_sockmap |
| Tail call 开销 | 0-33/35 深度链式调用 | tail-call-bench + MS bpf_performance |
| Hash 函数 cycle | jhash/xxh3/xxh64 | bpf-bench (内核模块级精度) |
| 用户态运行时对比 | llvm-jit/ubpf/rbpf/native/wasm 纯计算 | user_bpf_benchmark |
| Map 内存 | htab 内存模式 | Linux bench_htab_mem |

**核心特征**：全部是**微观级单操作测量**，缺乏端到端、系统级、跨版本的评估。

---

## 二、学术界已经做了什么（按主题分类）

### A. JIT 编译与代码生成

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **Jitterbug** | OSDI'20 | 形式化验证 Linux BPF JIT，发现并修复 bug，引入优化并 upstream |
| **Synthesizing JIT Compilers for In-Kernel DSLs** | CAV'20 | 综合形式化正确的 eBPF/cBPF JIT |
| **End-to-End Mechanized Proof of eBPF VM for IoT** | CAV'24 | RIOT 内核 eBPF JIT 的机械化正确性证明 |
| **hXDP: Efficient Software Packet Processing on FPGA NICs** | OSDI'20 | FPGA 上运行 XDP 程序 |
| **eBPF Program Warping on FPGA** | ATC'22 | hXDP peephole 优化 |
| **eHDL: Turning eBPF/XDP Programs into Hardware Designs** | ASPLOS'23 | 从 XDP 程序自动生成 FPGA 流水线 |

### B. Bytecode / 编译优化（JIT 前）

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **K2** | SIGCOMM'21 | 基于程序综合的 BPF bytecode 超优化器，代码尺寸降 6-26%，延迟降 1.36-55.03% |
| **Merlin** | ASPLOS'24 | 多层优化框架（定制 LLVM pass + bytecode rewriting），比 K2 更快更可扩展 |
| **EPSO** | ASE'25 | 基于缓存的高效超优化器，发现 795 条规则，尺寸最多降 68.87%，运行时均降 6.60% |
| **DSRO: Domain-Specific Run Time Optimization** | ASPLOS'22 | 基于流量模式优化数据面二进制 |

### C. 后验证优化（多程序融合/去链化）

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **KFuse** | EuroSys'22 | 后验证内核态程序融合，把 indirect jump 变 direct jump，真实应用最高 2.3× |

### D. 安全与验证

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **BeeBox** | Sec'24 | 直接修改 JIT 编译器硬化 BPF 抵御瞬态执行攻击 |
| **MOAT** | Sec'24 | 用 Intel MPK + 运行时检查硬化 eBPF |
| **Hive** | Sec'24 | AArch64 上硬件辅助 eBPF 隔离执行环境，替代静态验证 |
| **SoK: Memory Safety for eBPF** | S&P'25 | 系统调研 eBPF 内存安全挑战 |
| **BVF** | EuroSys'24 | 结构化 fuzzing 发现 verifier 正确性 bug，1 个月找到 15 个新 bug |
| **Validating eBPF Verifier via State Embedding** | OSDI'24 | 在 BPF 程序中嵌入正确性检查做 verifier fuzzing |
| **eBPF Misbehavior Detection** | SOSP'25 | 用 specification-based oracle fuzz verifier |
| **BCF (Prove It to the Kernel)** | SOSP'25 (Best Paper) | 将 verifier 精度提升外包给用户态 SMT solver，内核只做线性时间 proof checking（49μs, 541B proof），接受 78.7% 此前被拒程序 |
| **PREVAIL** | PLDI'19 | 基于抽象解释的 eBPF 验证器，现用于 eBPF-for-Windows |
| **Agni** | CAV'23 + SAS'25 | 形式化验证 Linux verifier 范围分析的正确性 |
| **VEP** | NSDI'25 | 两阶段验证工具链，用源码注解实现 proof-carrying code |
| **Rex** | ATC'25 | 用 Rust 编译器 + 运行时检查替代 verifier，减少误报 |
| **Fast, Flexible, and Practical Kernel Extensions** | SOSP'24 | 扩展 verifier 支持有限运行时检查，向后兼容 |
| **Toss a Fault to BpfChecker** | CCS'24 | 差分 fuzzing 用户态 eBPF 运行时 |
| **VeriFence** | RAID'24 | 扩展 BPF verifier 插入 speculation barrier 替代拒绝程序，将 844 个真实程序的拒绝率从 54% 降至 0% |
| **SafeBPF** | CCSW'24 | SFI + ARM MTE 硬件辅助 eBPF 隔离，宏观 benchmark 最多 4% 开销 |
| **Flow Hijacking in eBPF** | IJIS'25 (Springer) | eBPF 解释器和 JIT 的流劫持攻击与缓解 |
| **BPFGuard** | IEEE TCC'25 | BPF-LSM 容器强制访问控制，tail call 链式策略执行，平均仅 2.16% 性能开销 |
| **Enabling eBPF on Embedded Systems Through Decoupled Verification** | eBPF Workshop'23 | 解耦验证，嵌入式场景 |

### E. 网络与数据面

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **Demystifying Performance of eBPF Network Applications** | CoNEXT'25 | 系统评估 eBPF 网络应用性能，分析 tail call/链式机制开销，指出 JIT 在可确定下一跳时优化 tail call |
| **eNetSTL** | EuroSys'25 | 首个 eBPF 内核态网络函数库（类 STL），解决 35 个代表性网络函数中最高 49.2% 的性能退化 |
| **BMC: Accelerating Memcached** | NSDI'21 | XDP 实现内核态 Memcached 缓存 |
| **Electrode** | NSDI'23 | 用 tc/XDP 卸载 Paxos |
| **DINT** | NSDI'24 | 用 tc/XDP 卸载分布式事务 |
| **eTran** | NSDI'25 | AF_XDP 框架实现自定义传输协议 |
| **State-Compute Replication** | NSDI'25 | 用 XDP 跨核并行单流处理 |
| **SPRIGHT** | SIGCOMM'22 | eBPF 加速 serverless |
| **Hermes** | SIGCOMM'25 | sk_reuseport 优化 L7 负载均衡 |
| **NetEdit** | SIGCOMM'24 | 大规模 eBPF 网络函数编排平台 |
| **Tigger** | VLDB'23 | 用 sockmap 卸载 PostgreSQL 连接池 |
| **uXDP** | eBPF Workshop'25 | 用户态运行未修改 XDP 程序，比内核执行吞吐量高 3.3×，Katran 提升 40% |
| **X2DP** | SIGCOMM'25 Poster | 扩展 XDP 支持 prefetch/SIMD/批处理，吞吐量最高提升 2.3× |
| **InXpect** | eBPF Workshop'25 | 轻量级 XDP profiling 工具 |
| **AF_XDP + Programmable NICs** | eBPF Workshop'25 | AF_XDP 与可编程网卡的性能交叉分析 |

### F. 系统扩展与新应用

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **bpftime (EIM)** | OSDI'25 | 用户态 eBPF 扩展框架，Extension Interface Model + MPK 隔离 |
| **cache_ext** | SOSP'25 | 用 BPF hook/kfunc/struct_ops 定制 page cache |
| **PageFlex** | ATC'25 | 用 writable tracepoint 定制页面策略 |
| **FetchBPF** | ATC'24 | 新 hook/helper 实现内存预取定制 |
| **XRP** | OSDI'22 | 用 BPF 卸载存储处理到 NVMe 驱动 |
| **BPF-DB** | SIGMOD'25 | 内核嵌入式事务数据库，比 VoltDB 吞吐高 43% |
| **Syrup** | SOSP'21 | eBPF 实现应用定制调度 |
| **DepSurf** | EuroSys'25 | 揭示 eBPF 程序对不稳定内核接口的依赖问题，83% 程序受影响 |
| **FlexGuard** | SOSP'25 | 用 eBPF 与调度器通信，在锁持有线程被抢占时自动切换 busy-wait→blocking，LevelDB 吞吐提升 1-6× |
| **gpu_ext** | arXiv'25 | 用 eBPF hook 扩展 GPU 驱动 + 设备端 eBPF 运行时，推理/训练吞吐最高提升 4.8× |

### G. 编译优化与程序融合（新进展）

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **Pairwise BPF Programs Should Be Optimized Together** | eBPF Workshop'25 | 首次提出成对 BPF 程序联合优化，直接验证 Program-Set 编译方向的可行性 |
| **Kernel Extension DSLs Should Be Verifier-Safe** | eBPF Workshop'25 | 从 DSL 层面确保 verifier 安全性 |
| **Automatic Synthesis of Abstract Operators for eBPF** | eBPF Workshop'25 | 自动综合 eBPF 抽象算子 |

### H. 运行时与资源管理（新进展）

| 论文 | 会议 | 核心贡献 |
|------|------|---------|
| **No Two Snowflakes Are Alike** | eBPF Workshop'25 | 系统研究不同 eBPF 库的性能/保真度/资源使用差异 |
| **SchedBPF: Scheduling BPF programs** | eBPF Workshop'25 | BPF 程序本身的调度策略，关联多程序并发问题 |
| **A Memory Pool Allocator for eBPF Applications** | eBPF Workshop'25 | eBPF 应用的内存池分配器 |
| **eBPFML** | eBPF Workshop'25 | 用 eBPF 支持 ML 辅助内核决策 |
| **ChainIO** | eBPF Workshop'25 | 用 eBPF 桥接磁盘和网络域 |

### I. 性能评估方法论（直接相关的实证工作）

| 论文/工作 | 来源 | 核心贡献 |
|----------|------|---------|
| **Evaluation of tail call costs** | LPC'20 (Cloudflare) | Spectre 缓解后 tail call 成本的系统实证 |
| **Understanding Performance of eBPF Maps** | SIGCOMM eBPF Workshop'24 | eBPF map 性能系统化 benchmark |
| **An Empirical Study on the Challenges of eBPF Application Development** | SIGCOMM eBPF Workshop'24 | eBPF 应用开发挑战的实证研究 |
| **Understanding performance of eBPF-based applications** | ETH Zurich 学期论文'24 | 多核环境下 eBPF 程序的扩展性/资源利用/干扰分析 |
| **Towards eBPF Overhead Quantification** | ICPE'25 | eBPF vs SystemTap 开销量化方法论 |
| **Eliminating eBPF Tracing Overhead on Untraced Processes** | SIGCOMM eBPF Workshop'24 | 发现 untraced 进程也有开销，提出 zero-overhead 方案 |
| **FOSDEM 2025: Performance evaluation of eBPF verifier** | FOSDEM'25 | 6 个内核版本（5.0-6.8）的 verifier 验证时间与内存消耗对比 |
| **No Two Snowflakes Are Alike** | eBPF Workshop'25 | 不同 eBPF 库的性能/保真度/资源使用系统对比 |
| **Benchmarking DTrace vs eBPF** | AsiaBSDCon'24 | DTrace (FreeBSD) vs eBPF/bpftrace (Linux) 跨平台开销对比 |
| **eBPF-Based Instrumentation for Degradation Diagnosis** | arXiv'25 | 16 个 eBPF 指标覆盖 6 个内核子系统，量化 Cassandra/Kafka/Redis/MySQL 上的 overhead |
| **The eBPF Runtime in the Linux Kernel** | arXiv'24 | 首个完整描述 Linux eBPF 运行时（截至 v6.7）设计与实现的综合论文 |

---

## 三、从 Benchmark 基础设施角度看，还缺什么？

### 缺口 1：程序加载/编译全链路 Benchmark（完全空白）

**现状**：所有 benchmark 测的都是"程序已加载好"之后的运行性能。

**为什么重要**：
- Cilium datapath 程序验证时间可达数秒，是部署瓶颈
- SOSP'24 (Fast, Flexible Kernel Extensions) 和 NSDI'25 (VEP) 都在改验证机制，但**没有标准化的验证性能 benchmark**
- Agni (CAV'23) 发现 verifier 范围分析有不正确的优化，**验证器的性能-精度-正确性权衡缺乏量化工具**

**需要测量的环节**：
```
clang 编译 → ELF 解析 → CO-RE 重定位 → BTF 处理 → Verifier → JIT → Attach
    ↓            ↓           ↓            ↓          ↓       ↓       ↓
   耗时         耗时         耗时          耗时       耗时    耗时    耗时
                                                     ↕
                                          精度/正确性/拒绝率
```

**对标论文**：ETH Zurich 学期论文做了初步尝试，FOSDEM'25 有 verifier 性能评估，但都不够系统化。

### 缺口 2：端到端应用级 Overhead Benchmark（几乎空白）

**现状**：bench_trigger 测 "BPF 程序能跑多快"，不测 "给被观测系统带来多少负担"。

**为什么重要**：
- ICPE'25 论文证明了可以量化 eBPF vs SystemTap 的 overhead，但只覆盖了 open/mmap 两个 syscall
- SIGCOMM eBPF Workshop'24 发现 untraced 进程也受 overhead 影响 — **这意味着现有 benchmark 根本没测对场景**
- CoNEXT'25 问了 "是不是所有网络应用都适合 eBPF" — 需要 benchmark 数据回答

**需要的 benchmark**：
| 场景 | 指标 |
|------|------|
| nginx/Redis/MySQL + N 个 kprobe | 吞吐量下降 %，P99 延迟增加 |
| 目标进程 vs 非目标进程的开销 | 跟进 SIGCOMM'24 Workshop 的发现 |
| 持续 profiling (perf_event BPF) | CPU 额外消耗 |
| LSM BPF 安全策略 | 系统调用延迟增加 |
| sched_ext 自定义调度 | 调度延迟、上下文切换开销 |

### 缺口 3：XDP/TC/网络数据面吞吐 Benchmark（实证很强但 Benchmark 基础设施薄弱）

**现状**：学术论文里 XDP 数据非常多（BMC、Electrode、DINT、eTran、SPRIGHT），但**没有标准化的、可复现的 benchmark 套件**。

**为什么重要**：
- CoNEXT'25 用自己的基准评估不同 chaining 机制 — 但不可复用
- AF_XDP + 可编程 NIC 的性能交叉（eBPF Workshop'25）— 揭示了新的性能维度
- eHDL (ASPLOS'23) 把 XDP 编译到 FPGA — 需要统一基准对比软硬件

**需要的 benchmark**：
- XDP_DROP/TX/REDIRECT pps（单核、多核扩展曲线）
- TC BPF vs iptables vs nftables 对比
- AF_XDP 吞吐
- CPUMAP/DEVMAP/XSKMAP redirect 性能
- 链式 vs 融合（对标 KFuse）的网络功能链

### 缺口 4：多程序并发与可扩展性 Benchmark（几乎空白）

**现状**：ETH Zurich 学期论文做了初步的多程序/多核扩展性分析，但不够系统。

**为什么重要**：
- NetEdit (SIGCOMM'24) 做大规模 eBPF 网络函数编排 — 需要知道 N 个程序的 overhead
- cache_ext (SOSP'25) / PageFlex (ATC'25) 都是 per-cgroup struct_ops — 多租户场景的性能特征未知
- DepSurf (EuroSys'25) 发现 83% 的 eBPF 程序有依赖不匹配 — 但性能影响未量化

**需要的 benchmark**：
- 同一 hook 上挂 1/10/100/1000 个程序的 overhead 曲线
- Map 在 N 个 CPU 并发操作下的竞争开销
- Per-CPU map vs 全局 map 的扩展性曲线
- rqspinlock（BPF 新自旋锁，2025.3 进入 bpf-next）性能
- BPF 程序调度策略（SchedBPF, eBPF Workshop'25 已提出问题但未给出完整方案）

### 缺口 5：新特性 Benchmark（全部空白）

| 特性 | 相关论文 | Benchmark 状态 |
|------|---------|:---:|
| **BPF Arena** (共享内存) | — | ❌ |
| **User Ring Buffer** | — | ❌ |
| **BPF Timer** | — | ❌ |
| **sched_ext** (BPF 调度器) | Syrup (SOSP'21), cache_ext (SOSP'25) | ❌ |
| **struct_ops** 通用 | cache_ext, TCP CC (bpf_cubic) | ❌ |
| **NETFILTER prog type** | — | ❌ |
| **BPF Token** | — | ❌ |
| **BPF exceptions** | — | ❌ |

### 缺口 6：程序类型覆盖

内核有 **31 种 BPF_PROG_TYPE**，benchmark 覆盖不到 1/3：

| 程序类型 | 有 Benchmark? | 说明 |
|----------|:---:|------|
| KPROBE / TRACING (fentry/fexit/fmod_ret) | ✅ | bench_trigger 覆盖充分 |
| RAW_TRACEPOINT / TRACEPOINT | ✅ | bench_trigger |
| XDP | ❌ | **无吞吐量 benchmark** |
| SCHED_CLS (TC) | ❌ | **完全空白** |
| SCHED_ACT | ❌ | 完全空白 |
| LSM | ❌ | **完全空白** — BPFGuard 报告仅 2.16% 开销，但无标准化 benchmark |
| STRUCT_OPS | ❌ | **完全空白** — sched_ext/TCP CC 核心 |
| CGROUP_SKB / SOCK / SOCKOPT / SYSCTL / DEVICE | ❌ | **完全空白** — 容器场景核心 |
| SOCK_OPS | ❌ | 完全空白 |
| SK_LOOKUP | ❌ | 完全空白 |
| FLOW_DISSECTOR | ❌ | 完全空白 |
| LWT_IN / OUT / XMIT / SEG6LOCAL | ❌ | 完全空白 |
| NETFILTER | ❌ | 完全空白（新 prog type） |
| PERF_EVENT | ❌ | 完全空白 |
| SOCKET_FILTER | ❌ | 完全空白 |
| SK_MSG / SK_SKB | 部分 | bench_sockmap 只测 redirect |
| EXT (freplace) | ❌ | 完全空白 |

### 缺口 6b：Map 类型覆盖

内核有 **30+ 种 BPF_MAP_TYPE**，仍有大量遗漏：

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
| USER_RINGBUF | ❌ | 用户态到内核的反向 ringbuf |
| ARENA | ❌ | **新特性，完全空白** |
| STRUCT_OPS | ❌ | 完全空白 |
| PERF_EVENT_ARRAY | ❌ | 完全空白 |

### 缺口 6c：跨版本性能回归

只有 tail-call-bench 做了多内核版本对比，MS bpf_performance 有 Grafana 但无公开持续追踪数据。缺乏：持续性能追踪（每个内核版本自动跑 benchmark）、回归检测与告警、跨架构对比（x86 vs ARM64 vs RISC-V）、Spectre/Meltdown 缓解影响的系统化评估。

### 缺口 6d：方法论碎片化

各项目各自为政，指标不统一，结果不可比：输出格式不统一（ops/sec / CSV / JSON / text+PNG）、指标定义不一致（ns/op vs M ops/sec vs CPU cycles）、可复现性差（大部分未记录 CPU 频率锁定等条件）、缺少统一运行器和对比框架。

### 缺口 7：用户态 eBPF 运行时（只测了纯计算）

**现状**：user_bpf_benchmark 只测 8 个纯计算程序。

**为什么重要**：
- bpftime (OSDI'25) 提出了 Extension Interface Model — 需要更全面的性能评估
- **uXDP (eBPF Workshop'25) 在用户态运行 XDP 程序达到 3.3× 内核执行性能** — 用户态运行时已不再是"慢的替代品"
- CCS'24 (BpfChecker) 做了用户态运行时的差分 fuzzing — 发现正确性问题，但没做性能对比
- **"No Two Snowflakes Are Alike" (eBPF Workshop'25)** 首次系统对比不同 eBPF 库的性能差异
- 用户态运行时的核心价值是 uprobe/syscall 拦截和 map 操作，不是纯计算

**需要补充的**：
- Map 操作性能（hashmap/array/ringbuf 在用户态的开销）
- Helper 函数模拟开销
- Uprobe/syscall 拦截延迟
- 与内核态相同程序的性能对比

---

## 四、统一研究方向：用户态 eBPF 优化服务（UEOS）

> 本节将之前独立讨论的方向 A-E 合并为一个统一的研究框架。核心洞察：这些方向不是平行的选择题，而是同一个系统的不同层面 — A 是实证基础，B/C/D 是可插拔的优化策略，E 是架构模式和安全保障。合并后的论文比任何单独方向都更强。

### 4.0 为什么要合并？— 从 5 个方向到 1 个框架

**合并前的问题**：

| 方向 | 定位 | 独立做的风险 |
|------|------|-------------|
| A（全栈实证） | 实证测量 | Reviewer 觉得"只是 benchmark"，缺系统贡献 |
| B（Multi-tier JIT） | 编译机制 | 内核态实现过于复杂，只做用户态又太轻 |
| C（Program-Set 融合） | 一种优化策略 | 与 KFuse 区分度不够，单独做 novelty 不足 |
| D（安全+性能统一） | 另一种优化策略 | 需要先做 A 的实证才能立论，单独做时间线太长 |
| E（BCF 启发 PGO） | 架构+一种优化策略 | 如果只做 PGO 一个优化点，系统贡献偏窄 |

**合并后的结构**：

```
                    ┌─────────────────────────┐
                    │   UEOS 统一框架         │
                    │ (Userspace eBPF         │
                    │  Optimization Service)  │
                    └────────────┬────────────┘
                                 │
          ┌──────────────────────┼──────────────────────┐
          │                      │                      │
    ┌─────┴──────┐    ┌─────────┴─────────┐    ┌──────┴──────┐
    │ 实证基础    │    │ 优化策略引擎       │    │ 安全保障层   │
    │ (原方向 A)  │    │ (原方向 B+C+D)    │    │ (原方向 E)  │
    │             │    │                   │    │             │
    │ · JIT 差距  │    │ · LLVM -O3 基线   │    │ · 等价性验证 │
    │   量化     │    │ · Profile-Guided   │    │ · BCF proof │
    │ · 反直觉   │    │ · Helper 内联      │    │ · Atomic    │
    │   发现     │    │ · 安全补偿优化     │    │   replace   │
    │ · 优化空间 │    │ · 多程序融合       │    │             │
    │   分析     │    │ · Verifier 约束    │    │             │
    │            │    │   解放            │    │             │
    └────────────┘    └───────────────────┘    └─────────────┘
```

**合并后为什么更强**：
1. **实证 motivate 系统**：A 的测量结果直接回答 "哪些优化值得做、对哪些程序有效"，不再是无目的的 benchmark
2. **多策略可组合**：B+C+D 变成框架内的可插拔模块，"策略间的交互效应"本身就是重要发现
3. **安全框架共享**：无论用哪种优化策略，等价性验证机制都是同一套，设计一次复用多次
4. **评估矩阵更丰富**：(程序类型 × 优化策略 × 策略组合) 的评估空间远比单一方向大
5. **故事线更完整**：从 "发现问题"(实证) → "解决问题"(多策略优化) → "保证安全"(等价性验证) → "端到端验证"(真实应用)

### 4.1 核心 Thesis

Linux 内核 eBPF JIT 是单遍 1:1 翻译，不执行任何优化。这是一个有意的设计选择（简单、快速、安全），但代价是运行时性能次优。BCF (SOSP'25 Best Paper) 建立了 "内核保持简单、复杂工作外包给用户态" 的范式来解决 verifier 精度问题。我们将同一范式迁移到编译优化领域：构建一个**用户态 eBPF 优化服务（UEOS）**，它接收内核中运行的 BPF 程序的字节码和运行时 profile，通过多种可组合的优化策略生成高质量 native code，经等价性验证后原子替换回内核。

| BCF (SOSP'25) | UEOS (本工作) |
|----------------|---------------|
| 内核 verifier 为简单而不精确 | 内核 JIT 为快速/安全而不优化 |
| 不精确 → 误拒合法程序 | 不优化 → 运行时性能次优 |
| 用户态 SMT solver 提升精度 | 用户态 LLVM -O3 + 多策略提升代码质量 |
| 生成形式化 proof | 生成等价性 certificate |
| 内核 proof checking (49μs, 541B) | 内核 certificate checking + atomic swap |

### 4.2 实证基础：系统性量化内核 JIT 差距

这是论文的 **Section 3 (Motivation)**，回答："差距有多大？差距从哪来？哪些优化值得做？"

#### 4.2.1 测量框架

对 512+ 个真实 BPF 程序（复用 BCF 数据集 + 补充 Cilium/Tetragon/sched_ext 程序），在三个编译层级下测量：

| 层级 | 编译方式 | 用途 |
|------|---------|------|
| Tier-0 | Kernel JIT（`bpf_jit_comp.c` 单遍翻译） | Baseline |
| Tier-1 | llvmbpf LLVM -O3（无 profile） | 静态优化上界 |
| Tier-2 | llvmbpf LLVM -O3 + PGO + helper 内联 | 完全优化上界 |

测量维度：
- 每条 eBPF 指令 → native 指令数（code inflation ratio）
- 端到端执行时间（BPF_PROG_TEST_RUN, rdtsc 纳秒级）
- 微架构指标：分支预测命中率、IPC、L1i/LLC cache miss
- Spectre 缓解指令占比

在 3+ 内核版本（6.1 LTS, 6.6 LTS, 6.12+）上测量跨版本变化。

#### 4.2.2 七个反直觉假设

实证部分的 novelty 不在于 "A 比 B 快"，而在于揭示**违背直觉的发现**：

**H1：网络策略程序的 JIT 差距 > 计算密集程序**
- 直觉：计算密集型有更多循环/向量化空间
- 预测：网络程序的 helper call + map lookup 序列给 LLVM 更多优化机会（内联、特化、冗余消除）
- 验证：按程序类别（网络/tracing/安全/调度）分组，对比 Tier-0 vs Tier-1 差距

**H2：Spectre 缓解与 JIT 质量的非线性交互**
- 直觉：Spectre 是固定加法开销
- 预测：LLVM 内联 helper 后消除了间接跳转 → retpoline/LFENCE 也随之消失 → 优化收益 > 纯代码质量提升
- 验证：2×2 实验设计 {kernel JIT, llvmbpf} × {mitigations=on, off}
- 代码依据：`bpf_jit_comp.c:670-692` retpoline 仅在间接跳转时触发

**H3：Verifier 强制的"性能税"**
- 直觉：verifier 只影响加载时间
- 预测：verifier 约束（禁止后向跳转、512B 栈、强制寄存器保存）导致 JIT 输入代码质量下降
- 验证：从等价 C 代码编译的 LLVM IR vs 从 eBPF bytecode 翻译的 IR，量化质量差异

**H4：Helper 调用的 Pareto 分布**
- 直觉：helper 性能影响均匀分布
- 预测：80%+ 的调用集中在 top-5 helper（bpf_map_lookup_elem 等）
- 验证：静态分析全部 512+ 程序的 helper 调用频率
- 意义：证明 "只内联 top-5" 就够了，大幅简化系统

**H5：多程序联合优化的超线性收益**
- 直觉：N 程序收益 = N × 单程序收益
- 预测：联合优化消除跨程序 cache 压力 + 冗余安全检查 → 收益超线性
- 验证：同一 hook 挂 2/4/8/16 个 Cilium 程序，独立优化 vs 联合优化

**H6：开销分布不均 — Map 访问主导运行时**
- 直觉：hook 触发开销是主要开销
- 预测：对 tracing 类程序，70%+ 的运行时开销在 map 查找而非 hook entry/exit
- 验证：细粒度 profiling，拆分 entry/exit、helper call、map ops 各自的 cycle 占比

**H7：同一 hook 多程序的超线性退化**
- 直觉：N 个程序 = N× 开销
- 预测：N > 8 后因 BPF dispatcher indirect jump + icache pollution 出现超线性增长
- 验证：同一 hook 挂 1/2/4/8/16/32/64 个程序，测量总开销曲线

H6、H7 直接来自原方向 A 的假设，与 H1-H5 共同构成完整的实证矩阵。

### 4.3 优化策略引擎：6 种可组合的优化模块

这是系统的核心 — 一个统一的用户态优化框架，内含 6 种可独立开启/组合的优化策略：

```
                    eBPF Bytecode + Profile + Security Context + Program Set
                                        │
                                        ▼
┌─────────────────────────────────────────────────────────────────────────┐
│                    UEOS 优化引擎 (基于 llvmbpf)                         │
│                                                                         │
│  ┌─────────────┐ ┌─────────────┐ ┌──────────────┐ ┌────────────────┐  │
│  │ S1: LLVM    │ │ S2: Profile │ │ S3: Helper   │ │ S4: Security   │  │
│  │ -O3 Baseline│ │ -Guided     │ │ Inlining     │ │ Compensatory   │  │
│  │             │ │ Optimization│ │              │ │ Optimization   │  │
│  │ 常量传播    │ │ 分支布局     │ │ map_lookup   │ │ indirect→direct│  │
│  │ 死代码消除  │ │ 热路径特化   │ │ probe_read   │ │ LFENCE重排     │  │
│  │ 寄存器分配  │ │ 冷代码外移   │ │ ktime_get_ns │ │ retpoline消除  │  │
│  └─────────────┘ └─────────────┘ └──────────────┘ └────────────────┘  │
│                                                                         │
│  ┌─────────────────────────────┐ ┌───────────────────────────────────┐ │
│  │ S5: Multi-Program Fusion    │ │ S6: Verifier Constraint Release  │ │
│  │                             │ │                                   │ │
│  │ 跨程序 CSE (公共子表达式)    │ │ 循环恢复 (bpf_loop → native loop)│ │
│  │ 冗余 map lookup 消除        │ │ 栈扩展 (>512B if safe)           │ │
│  │ 共享代码去重                │ │ 寄存器约束解除                   │ │
│  │ tail call chain 内联        │ │ 结构体访问模式优化               │ │
│  └─────────────────────────────┘ └───────────────────────────────────┘ │
│                                                                         │
│                           ┌─────────────┐                              │
│                           │ Optimization │                              │
│                           │ Composer     │                              │
│                           │ (策略选择器) │                              │
│                           └──────┬──────┘                              │
│                                  │                                      │
└──────────────────────────────────│──────────────────────────────────────┘
                                   │
                                   ▼
                          Optimized Native Code
                          + Equivalence Certificate
```

#### 策略 S1：LLVM -O3 基线优化（来自原方向 B/E）

最基本的优化层 — 把 eBPF bytecode 翻译为 LLVM IR 后跑完整 -O3 pipeline。

**优化内容**：常量传播、死代码消除、LICM、全局值编号（GVN）、指令合并、高级寄存器分配（RegAllocGreedy vs kernel 的固定映射）
**实现**：已有，llvmbpf `optimizeModule()` 直接使用 `PB.buildPerModuleDefaultPipeline(OptimizationLevel::O3)`
**预期收益**：代码尺寸降 15-40%，执行时间降 10-30%（基于 K2/Merlin 在 bytecode 级的数据推断，JIT 后端级应该更大）

#### 策略 S2：Profile-Guided Optimization（来自原方向 B/E）

在 S1 基础上注入运行时 profile 信息：

**输入**：通过 perf_event BPF / BPF PMU kfunc 收集的分支频率、热路径、cache miss 分布
**优化内容**：
- 分支布局：将高频路径设为 fall-through，低频路径跳转
- 热函数内联：对频繁调用的 helper 优先内联
- 冷代码外移：将 error handling / rare path 移到函数末尾，减少 icache 压力
- 基于实际 map 访问模式的特化（如 hash map 的 key 大小固定则用特化版本）

**实现**：扩展 llvmbpf 的 `optimizeModule()` 注入 `!prof` metadata + 使用 `PGOOptions`
**预期收益**：在 S1 基础上额外 5-15%

#### 策略 S3：Helper 函数内联（来自原方向 B/D/E）

将 eBPF helper call（外部函数调用）替换为内联实现：

**优化内容**：
- `bpf_map_lookup_elem` → 内联 hash 查找逻辑（已知 map 类型和 key 大小时可深度特化）
- `bpf_probe_read` → 内联内存拷贝 + 边界检查
- `bpf_ktime_get_ns` → 内联 rdtsc 或 clock_gettime
- `bpf_get_current_pid_tgid` → 内联 current->pid 访问

**实现**：llvmbpf 已支持 `register_external_function()`，需要为每个 kernel helper 提供 LLVM IR 级别的实现模板
**预期收益**：对 helper-heavy 程序 20-50%（消除调用开销 + 启用跨边界优化）
**关键发现联动**：如果 H4（Pareto）成立，只需实现 top-5 helper 的内联模板

#### 策略 S4：安全补偿优化（来自原方向 D）

在用户态优化中，自动识别和消除不必要的 Spectre 缓解开销：

**优化内容**：
- **间接→直接转换**：当 helper 被内联后，原本的间接跳转消失 → retpoline 不再需要
- **LFENCE 消除**：LLVM 的 alias analysis 能证明某些内存访问不依赖 speculative load → 安全地删除 LFENCE
- **屏障间指令重排**：在必须保留的 LFENCE 之间，重排独立指令以隐藏序列化延迟
- **选择性加固**：根据程序安全上下文（是否处理不可信输入）决定加固等级

**实现**：在 LLVM IR 层面做分析和变换，利用 LLVM 的 SpeculativeExecution pass 和自定义 pass
**预期收益**：对 Spectre mitigations=on 的环境 5-20%
**关键发现联动**：H2（非线性交互）的验证直接量化此策略的价值

#### 策略 S5：多程序联合优化（来自原方向 C）

将同一 hook 上的多个 BPF 程序作为一个编译单元联合优化：

**优化内容**：
- **跨程序公共子表达式消除**：多个程序查找同一个 map → 合并为一次查找
- **冗余 ctx 访问消除**：多个程序读取 ctx 的同一字段 → 只读一次，结果传递
- **tail call chain 内联**：将线性 tail call 链（A → B → C）融合为一个函数
- **共享代码去重**：相似的 packet parsing / header extraction 代码合并
- **增量编译**：程序热插拔时只重编译受影响的部分，缓存未变化的部分

**实现**：在 LLVM IR 层面做 link-time optimization（LTO），利用 llvmbpf 的 module 合并能力
**前置分析**：自动分析程序间的 map/ctx 读写集合 + helper 副作用集合，确保融合安全
**预期收益**：对 N ≥ 4 的程序集 15-40%
**关键发现联动**：H5（超线性收益）和 H7（超线性退化）直接验证此策略的价值
**对标**：KFuse (EuroSys'22) 只做线性链融合；Pairwise (eBPF Workshop'25) 只做 pair-wise；我们做 N-wise + 增量

#### 策略 S6：Verifier 约束解放（新策略，来自假设 H3）

eBPF verifier 对程序结构施加了严格约束（无后向跳转、512B 栈、固定寄存器用途）。在用户态重编译时，可以在安全的前提下解除这些约束：

**优化内容**：
- **循环恢复**：将 `bpf_loop(N, callback, ...)` 恢复为 native for 循环（消除每次迭代的函数调用开销）
- **栈扩展**：对于需要 > 512B 栈的程序，在用户态编译时使用更大的栈帧
- **寄存器约束解除**：kernel JIT 用固定的 eBPF→x86 寄存器映射，LLVM 可以做全局最优分配
- **结构体访问模式优化**：verifier 要求的逐字段边界检查 → 合并为一次范围检查

**实现**：在 eBPF → LLVM IR 翻译阶段识别 verifier 约束模式，生成解约束的 IR
**预期收益**：对 bpf_loop-heavy 程序 10-30%（循环恢复），其余 5-10%
**Novelty**：这是全新的优化维度 — 之前所有工作（K2/Merlin/EPSO/KFuse）都在 verifier 约束内优化

#### 策略组合器（Optimization Composer）

不是所有策略对所有程序都有效。组合器根据实证数据选择策略：

```
输入：程序特征向量 (helper 调用数, map 类型, 分支数, 程序类型, hook 上其他程序)
      + 运行时 profile (调用频率, 热度, cache miss 率)

决策逻辑：
  if program.is_hot() and program.helper_call_count > threshold:
      enable S3 (helper inlining)
  if spectre_mitigations_on and program.indirect_jumps > threshold:
      enable S4 (security compensatory)
  if hook.program_count > 1:
      enable S5 (multi-program fusion)
  if program.has_bpf_loop:
      enable S6 (verifier constraint release)
  always enable S1 (LLVM -O3 baseline)
  if profile_available:
      enable S2 (PGO)

输出：优化策略集合 + 编译参数
```

**评估设计的关键**：论文需要一个 **策略消融研究（ablation study）**，展示每种策略的独立贡献和组合效应：

| 配置 | S1 | S2 | S3 | S4 | S5 | S6 | 预期加速比 |
|------|----|----|----|----|----|----|-----------|
| Baseline (kernel JIT) | | | | | | | 1.0× |
| S1 only | ✓ | | | | | | 1.2-1.4× |
| S1+S2 | ✓ | ✓ | | | | | 1.3-1.5× |
| S1+S3 | ✓ | | ✓ | | | | 1.4-1.8× |
| S1+S4 | ✓ | | | ✓ | | | 1.1-1.3× (mitigations=on) |
| S1+S5 (N=8) | ✓ | | | | ✓ | | 1.3-1.6× |
| S1+S6 | ✓ | | | | | ✓ | 1.1-1.4× |
| All (S1-S6) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ | **1.8-3.0×** |

**核心评估问题**：组合是否超线性？即 All > S1 + (S2-S1) + (S3-S1) + ... ？如果是，说明策略间有正交互效应 — 这本身就是重要的系统发现。

### 4.4 安全保障层：共享的等价性验证框架

无论使用哪种优化策略，优化后的代码必须通过等价性验证才能替换。这层是所有策略共享的：

```
原始 BPF 程序 ──┐
                 ├──→ 等价性验证 ──→ 通过 → Atomic Replace
优化后 native ──┘       │
                        └──→ 失败 → 回退到 kernel JIT 版本
```

**三级递进方案**（所有策略共享）：

| 方案 | 强度 | 实现复杂度 | 适用场景 |
|------|------|-----------|---------|
| **V1：差分测试** | 黑盒 | 低（2 周） | 第一版，快速上线 |
| **V2：BCF proof 扩展** | 形式化局部 | 中（2-3 月） | 论文主要方案 |
| **V3：Translation validation** | 形式化完全 | 高（远期） | Discussion 部分 |

**V1 差分测试**（基于 BPF_PROG_TEST_RUN）：
- 对原始/优化程序输入相同的测试向量，比较输出
- 测试向量来源：真实流量采样 + 覆盖引导模糊测试 + 边界值
- 零内核修改，可立即在现有 Linux 上使用

**V2 BCF proof 扩展**：
- 复用 BCF 的 proof checker（2337 行, 45 rules）
- 为每种优化策略生成局部等价性证明
- 例如：S3 helper 内联 → 证明内联代码与 call+return 语义等价
- 需要扩展：增加代码变换等价性规则（~20 条新 rules）

**V3 Translation Validation**：
- 对 eBPF bytecode 和 native code 分别构建符号表达式，用 SMT solver 验证等价
- 对标 Alive2 (LLVM IR) / CompCert
- eBPF 程序短（< 4096 指令），SMT 可行

### 4.5 系统架构总览

```
                          ┌─────────────────────────────────────────┐
                          │         用户态 UEOS 服务守护进程          │
                          │                                         │
   Profile ──────────────→│  ┌──────────┐    ┌───────────────────┐  │
   (perf_event /          │  │ Strategy │───→│ llvmbpf 编译引擎   │  │
    BPF PMU kfunc)        │  │ Composer │    │                   │  │
                          │  │          │    │ S1: LLVM -O3      │  │
   Bytecode ─────────────→│  │ 策略选择  │    │ S2: PGO           │  │
   (BPF_OBJ_GET /         │  │ + 参数   │    │ S3: Helper inline │  │
    bpf_prog_get_fd)      │  └──────────┘    │ S4: Security opt  │  │
                          │                  │ S5: Multi-prog    │  │
   Security Context ─────→│                  │ S6: Verifier free │  │
   (安全等级 / mitigations)│                  └────────┬──────────┘  │
                          │                           │             │
   Program Set ──────────→│                  ┌────────┴──────────┐  │
   (同 hook 程序列表)      │                  │  等价性验证         │  │
                          │                  │  V1/V2/V3         │  │
                          │                  └────────┬──────────┘  │
                          └───────────────────────────│─────────────┘
                                                      │
                                          optimized code + certificate
                                                      │
                          ════════════════════════════│════════════════
                                                      ↓         内核态
                                              ┌──────────────┐
                                              │ BPF Trampoline│
                                              │ Atomic Replace│
                                              └──────────────┘
```

**工作流**：
1. UEOS 守护进程监控内核中运行的 BPF 程序
2. 对热点程序收集 profile 数据（通过已有的 perf_event / PMU 接口）
3. Strategy Composer 根据程序特征 + profile + 安全上下文选择优化策略组合
4. llvmbpf 编译引擎执行所选策略，输出优化后的 native code
5. 等价性验证确保功能不变
6. 通过 BPF trampoline 原子替换内核中的程序
7. 持续监控替换后的性能，异常时自动回退

### 4.6 对标与差异化分析

| 已有工作 | 做了什么 | UEOS 的差异 |
|---------|---------|------------|
| K2 (SIGCOMM'21) | eBPF bytecode 超优化 | 在 verifier 约束内优化 bytecode；UEOS 在 native code 级优化，且可解放 verifier 约束 |
| Merlin (ASPLOS'24) | 多层 bytecode 优化 | LLVM pass + bytecode rewriting；UEOS 在 JIT 后端做，正交可叠加 |
| EPSO (ASE'25) | 缓存高效超优化 | bytecode 级规则；UEOS 涵盖 JIT 后端 + PGO + 多程序 |
| KFuse (EuroSys'22) | 线性链程序融合 | 只做 tail call chain 融合；UEOS 的 S5 做 N 程序 DAG 融合 + 增量编译 |
| Jitterbug (OSDI'20) | 形式化验证 JIT | 验证正确性，不做优化；UEOS 做优化 + 验证等价性 |
| BeeBox (Sec'24) | JIT 安全加固 | 只加安全不优化；UEOS 的 S4 在加固的同时做补偿优化 |
| BCF (SOSP'25) | 用户态提升 verifier 精度 | 范式相同（外包给用户态），应用不同（编译 vs 验证） |
| Pairwise (Workshop'25) | 成对 BPF 程序优化 | 只做 pair-wise；UEOS 的 S5 做 N-wise + 自动策略选择 |

**关键区分**：
1. **K2/Merlin/EPSO 与 UEOS 正交**：前者优化 bytecode（verifier 前），UEOS 优化 native code（JIT 后）。可以先用 Merlin 优化 bytecode，再用 UEOS 优化 JIT — 收益叠加。论文应展示这种组合。
2. **UEOS 是第一个做多策略组合优化的**：之前每个工作只做一种优化（超优化 / 融合 / 安全加固），UEOS 的核心贡献是在统一框架内组合多种策略，并展示其交互效应。
3. **UEOS 是第一个做用户态→内核注入闭环的优化系统**：所有已有工作要么在加载前优化（K2/Merlin），要么在内核内优化（KFuse/BeeBox），没有人做过 "运行时外包给用户态优化再注入" 的闭环。

### 4.7 可直接复用的基础设施

| 组件 | 来源 | 复用方式 |
|------|------|---------|
| eBPF → LLVM IR | llvmbpf `compiler.cpp` (1376 行) | 直接使用，已支持全指令集 |
| LLVM -O3 | llvmbpf `optimizeModule()` | S1 直接用；S2 扩展 PGO |
| Helper 内联 | llvmbpf `register_external_function()` | S3 对接内核 helper 签名 |
| AOT 编译 | llvmbpf `do_aot_compile()` | 生成可加载 native ELF |
| Module 合并 | LLVM LTO | S5 多程序融合 |
| 512 程序数据集 | BCF 论文 | 实证分析 |
| Proof checker | BCF 内核代码 (2337 行, 45 rules) | V2 等价性验证 |
| Atomic replace | BPF trampoline / bpf_prog_replace() | 内核已有 |
| Profile 收集 | perf_event BPF, PMU kfunc | 内核已有 |

### 4.8 论文结构设计

```
Title: "UEOS: Offloading eBPF Compilation to User Space
        with Composable Optimization Strategies"

1. Introduction (1.5p)
   - 问题：kernel JIT 为简单/安全牺牲性能
   - 洞察：BCF 范式 → 编译也可以外包
   - 贡献：(1) 实证量化 JIT 差距 (2) 6 种可组合优化策略
           (3) 等价性验证框架 (4) 端到端系统实现与评估

2. Motivation: The Kernel JIT Quality Gap (3p)
   - 2.1 Kernel JIT 架构分析 (单遍翻译, 无优化, Spectre 缓解)
   - 2.2 实证量化：512+ 程序的 Tier-0/1/2 性能矩阵
   - 2.3 七个假设的验证结果 (H1-H7)
   - 2.4 优化机会分解：差距来自哪里？→ 直接 motivate 6 个策略

3. Design (4p)
   - 3.1 架构总览：UEOS 守护进程 + 优化引擎 + 验证层
   - 3.2 策略 S1-S6 的设计
   - 3.3 策略组合器：何时用什么策略
   - 3.4 等价性验证 (V1/V2)
   - 3.5 内核集成：Atomic Replace 机制

4. Implementation (1.5p)
   - 基于 llvmbpf 的优化引擎
   - Profile 收集框架
   - 等价性验证实现
   - 内核端加载/替换机制

5. Evaluation (4p)
   - 5.1 微观：每种策略的独立收益 (512+ 程序)
   - 5.2 消融：策略组合的交互效应 (表 4.3 的完整实验)
   - 5.3 宏观：4 个真实应用 (Cilium, Katran, Tetragon, bpftrace)
   - 5.4 开销：编译时间, 内存, 验证时间
   - 5.5 安全性：等价性验证的覆盖率与可靠性
   - 5.6 与 K2/Merlin/EPSO 的正交性（bytecode 优化 + UEOS 叠加）

6. Discussion (1p)
   - Translation Validation (V3) 的远期路径
   - 内核上游化可行性
   - GPU/FPGA 扩展 (llvmbpf 已支持 PTX/SPIR-V)

7. Related Work (1p)
8. Conclusion (0.5p)
```

**贡献列表**（reviewer 视角）：
1. **首个系统性的 kernel JIT vs LLVM JIT 性能差距量化**（512+ 程序, 3+ 内核版本, 7 个假设验证）
2. **首个用户态→内核 eBPF 优化闭环系统**（BCF 范式迁移，profile 收集 → 优化 → 验证 → 注入）
3. **6 种可组合优化策略 + 策略交互效应分析**（S1-S6, ablation study）
4. **共享等价性验证框架**（V1 差分测试 + V2 BCF proof 扩展）
5. **4 个真实应用的端到端评估**（Cilium/Katran/Tetragon/bpftrace）

---

## 五、UEOS 统一实施路线图

### 分阶段实施计划

#### 阶段 1：实证基础与策略 S1 验证（第 1-3 个月）

**目标**：系统量化 JIT 差距，验证 7 个假设，确定各策略的优先级。

**Step 1.1：数据集构建（2 周）**
- 获取 BCF 的 512 程序数据集（106 源程序 × 多编译器配置）
- 补充 30 个代表不同类别的程序：
  - 网络策略：Cilium bpf_lxc, Calico policy, Katran L4LB
  - 可观测性：bpftrace 编译产物, bcc tools
  - 安全：BPF-LSM 策略, Tetragon 传感器
  - 调度：scx_rusty, scx_lavd
  - 存储：XRP-style NVMe offload
- 标注每个程序：类型、helper 数/类型、map 数/类型、指令数、分支数

**Step 1.2：三层 baseline 测量（3 周）**
- Tier-0（kernel JIT）：`bpf_jit_disasm` + perf stat + BPF_PROG_TEST_RUN
- Tier-1（llvmbpf -O3）：直接使用 `optimizeModule()` 的 -O3 pipeline
- 测量维度：code inflation ratio、执行时间(ns)、IPC、cache miss、Spectre 指令占比
- 在 3 个内核版本测量：6.1 LTS, 6.6 LTS, 6.12+

**Step 1.3：假设验证实验矩阵（5 周）**
- H1（网络 > 计算）：按类别分组对比 Tier-0 vs Tier-1
- H2（Spectre 交互）：2×2 设计 {kernel, llvmbpf} × {mitigations on/off}
- H3（verifier 性能税）：C→IR vs eBPF→IR 的代码质量对比
- H4（Pareto）：全数据集 helper 调用频率静态分析
- H5（超线性联合）：llvmbpf N 程序联合编译 vs 独立编译
- H6（Map 主导）：细粒度 profiling 拆分 entry/helper/map 的 cycle 占比
- H7（多程序退化）：同 hook 1-64 个程序的总开销曲线

**阶段 1 deliverable**：
- 完整的性能差距矩阵 + 7 个假设的验证/证伪（附统计分析）
- 基于数据的策略优先级排序（哪些策略对哪类程序价值最大）
- **可独立提交为 eBPF Workshop'26 论文**

#### 阶段 2：核心优化策略实现 S1-S4（第 4-7 个月）

**目标**：实现 4 个单程序级优化策略，构建 PGO 编译闭环。

**Step 2.1：S2 Profile 收集与 PGO 编译（4 周）**
- Profile 收集：通过 perf_event_open 采样 BPF 程序 IP 分布 + 分支频率
  ```c
  struct bpf_prog_profile {
      u64 total_calls;
      u64 branch_taken[MAX_BRANCHES];
      u64 helper_calls[MAX_HELPERS];
      u64 map_lookups[MAX_MAPS];
      u64 cache_misses;
  };
  ```
- PGO 集成：扩展 `optimizeModule()` 注入 `!prof` metadata + `PGOOptions`
- 验证 Tier-0 vs Tier-1 vs Tier-2 三级差异

**Step 2.2：S3 Helper 内联（3 周）**
- 为 top-5 kernel helper（基于 H4 验证结果）编写 LLVM IR 实现模板
- 通过 llvmbpf 的 `register_external_function()` 对接
- 测量：内联前 vs 内联后的性能差异，是否触发 S4 的安全收益

**Step 2.3：S4 安全补偿优化（3 周）**
- 实现 LLVM pass：检测 helper 内联后消失的间接跳转 → 标记为不需要 retpoline
- 实现 LFENCE 消除：利用 LLVM alias analysis 证明无 speculative load 依赖
- 实现屏障间指令重排：在保留的 LFENCE 之间调度独立指令

**Step 2.4：S6 Verifier 约束解放（2 周）**
- 实现 bpf_loop → native loop 恢复（在 IR 翻译阶段识别模式）
- 实现寄存器约束解除（不使用固定 eBPF→x86 映射，交给 LLVM RegAlloc）

**Step 2.5：等价性验证 V1 实现（2 周）**
- 基于 BPF_PROG_TEST_RUN 的差分测试框架
- 测试向量：真实流量采样 + 边界值 + 覆盖引导模糊测试
- 在全数据集上验证 S1-S4 所有优化的等价性

**阶段 2 deliverable**：
- S1-S4+S6 的独立实现
- 每种策略的独立收益数据
- V1 等价性验证的覆盖率/可靠性报告

#### 阶段 3：多程序优化 S5 + 策略组合 + 消融研究（第 8-9 个月）

**目标**：实现 S5 多程序融合，构建策略组合器，完成消融实验。

**Step 3.1：S5 多程序融合（4 周）**
- 实现程序间依赖分析（map/ctx 读写集 + helper 副作用集）
- 利用 LLVM LTO 做跨程序 module 合并
- 实现：跨程序 CSE、冗余 map lookup 消除、tail call chain 内联
- 实现增量编译：程序热插拔时只重编译受影响部分

**Step 3.2：策略组合器实现（2 周）**
- 基于阶段 1/2 的数据构建策略选择规则
- 对每个程序自动选择最优策略组合

**Step 3.3：消融研究（2 周）**
- 完整的消融矩阵：S1, S1+S2, S1+S3, ..., S1-S6 全开
- 验证核心问题：策略组合是否超线性？

**阶段 3 deliverable**：
- 完整的 6 策略消融矩阵
- 策略交互效应分析（正/负交互）
- 自动策略组合器

#### 阶段 4：端到端系统 + 真实应用评估（第 10-11 个月）

**目标**：完成 UEOS 守护进程 + 内核注入闭环 + 真实应用评估。

**Step 4.1：UEOS 守护进程（3 周）**
- 实现完整的用户态服务：监控 → profile → 策略选择 → 编译 → 验证 → 注入
- 内核注入方案 1：`bpf_prog_replace()` + `BPF_F_REPLACE`
- 自动回退机制：监控替换后性能，异常时恢复

**Step 4.2：真实应用评估（3 周）**
- **Cilium 网络策略**：K8s pod-to-pod 延迟/吞吐量
- **Katran L4LB**：XDP pps 变化
- **Tetragon 安全策略**：系统调用延迟
- **bpftrace 持续 profiling**：overhead 降低
- 与 K2/Merlin/EPSO 正交性验证（bytecode 优化 + UEOS 叠加效果）

**Step 4.3：V2 等价性验证原型（2 周，可选）**
- 扩展 BCF proof checker，增加代码变换等价性规则
- 为 S3 helper 内联生成局部 proof

**阶段 4 deliverable**：
- 完整的端到端 UEOS 系统
- 4 个真实应用的性能提升数据
- 编译时间/内存/安全性开销分析

#### 阶段 5：论文写作与投稿（第 12 个月）

论文结构见 4.8 节。

### 投稿目标与时间线

| 目标会议 | 截稿日（预估） | 内容 | 说明 |
|---------|--------------|------|------|
| **eBPF Workshop'26** | ~2026.08 | 阶段 1 实证结果 | 先发，建立 presence |
| **OSDI'27** | ~2026.12 | UEOS 完整系统 | **推荐主投** |
| **SOSP'27** | ~2027.04 | UEOS 完整系统 | 备选主投 |
| **EuroSys'27** | ~2026.10 | 如系统偏中等 | 备选 |

**推荐时间线**：
```
2026.03 ──── 阶段1: 实证 ────── 2026.05
                                    │
2026.06 ──── 阶段2: S1-S4 ───── 2026.09
                          │
                    eBPF Workshop'26 提交 (阶段1结果)
                                    │
2026.09 ──── 阶段3: S5+消融 ──── 2026.10
                                    │
2026.10 ──── 阶段4: 端到端 ───── 2026.11
                                    │
2026.12 ──── 阶段5: 写作 ─────── 2027.02 → OSDI'27 / SOSP'27
```

### 对比基线与可复现性

- **必须对比的基线**：
  - Kernel JIT baseline（各内核版本）
  - K2/Merlin/EPSO 的 bytecode 优化（证明正交性）
  - KFuse 的程序融合（与 S5 对比）
  - BeeBox 的安全加固（与 S4 对比）
- **可复现性**：
  - CPU 频率锁定、turbo boost 关闭、NUMA 绑定
  - 多次运行取中位数 + 95% 置信区间
  - 公开全部代码、数据集、测量脚本
- **论文必须回答的核心问题**：
  - "为什么现在？" → BCF (SOSP'25) 刚建立"外包给用户态"的范式 + llvmbpf 刚成熟
  - "对谁有用？" → 云厂商（Cilium/Calico 部署）、安全团队（Tetragon）、可观测性（bpftrace）
  - "lasting impact？" → "keep kernel simple" 范式从验证推广到编译，统一优化框架

---

## 六、参考文献与资源

### 综合列表
- [pchaigno 的 eBPF 研究论文列表](https://pchaigno.github.io/bpf/2025/01/07/research-papers-bpf.html) — 最全面的 eBPF 论文索引
- [eunomia-bpf 的 eBPF 论文综述](https://eunomia.dev/en/blogs/ebpf-papers/)
- [ACM SIGCOMM eBPF Workshop](https://conferences.sigcomm.org/sigcomm/2025/workshop/ebpf/) — 每年的 eBPF 专题研讨
- [eBPF Workshop 2025 论文列表 (DBLP)](https://dblp.org/db/conf/ebpf/ebpf2025.html) — 15 篇论文
- [eBPF Workshop 2024 论文列表 (DBLP)](https://dblp.org/db/conf/ebpf/ebpf2024.html)
- [eBPF 生态 2024-2025 技术深度分析](https://eunomia.dev/blog/2025/02/12/ebpf-ecosystem-progress-in-20242025-a-technical-deep-dive/)

### 开源 Artifact
```
Jitterbug:  https://github.com/uw-unsat/jitterbug
Merlin:     https://github.com/4ar0nma0/Merlin
KFuse:      https://github.com/synercys/eurosys-kfuse-artifact
BeeBox:     https://gitlab.com/brown-ssl/beebox-ae
PREVAIL:    https://github.com/vbpf/prevail
Agni:       https://github.com/bpfverif/agni
DepSurf:    https://github.com/ShawnZhong/DepSurf
bpftime:    https://github.com/eunomia-bpf/bpftime
llvmbpf:    https://github.com/eunomia-bpf/llvmbpf
BCF:        https://github.com/haosun2017/BCF  (proof checker + dataset)
cache_ext:  https://github.com/cache-ext/cache_ext
veristat:   https://github.com/libbpf/veristat
```

### Benchmark 基础设施
```
Linux kernel bench: tools/testing/selftests/bpf/benchs/
MS bpf_performance: https://github.com/microsoft/bpf_performance
tail-call-bench:    https://github.com/pchaigno/tail-call-bench
bpf-bench:          https://github.com/aspsk/bpf-bench
user_bpf_benchmark: (本仓库 user_bpf_benchmark/)
```

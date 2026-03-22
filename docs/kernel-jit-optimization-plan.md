# BpfReJIT: Dynamic, Extensible Compilation Framework for Kernel eBPF

> 本文档是 BpfReJIT 论文的单一 hub。
> **论文核心方向：构建一个最小化、动态、可扩展的内核编译框架，让 deployed eBPF 从一次性静态编译，变成可在线、透明、runtime-guided specialization 的执行环境。Paper 必须展示真实程序上的可测量加速和安全加固能力。**
> **编辑规则**：
> - **⚠️ 未经用户明确同意，禁止修改内核代码（vendor/linux-framework）。** 所有内核改动必须先调研→用户确认→再实施。codex/agent prompt 必须包含此约束。
> - 未经用户明确要求，禁止 git commit / git push。
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 agent background 跑任务，不阻塞主对话。
> - **构建+修改+运行不拆分**：一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent。
> - **⚠️ 同一时间只能有一个 agent 修改内核代码（vendor/linux-framework），也只能有一个 agent 跑测试（VM benchmark / selftest）。** 多个 agent 同时改内核代码会产生 git 冲突；多个 agent 同时跑 VM 测试会竞争资源、结果不可靠。调度时必须串行化内核改动和测试任务。
> - **⚠️ codex 默认不要 commit/push，除非 prompt 明确要求。** 改完代码就停，由 Claude 统一 commit。
> - **⚠️ 如果需要 commit，必须在 main 分支直接做，不要开新分支。** 开分支导致合并冲突。
> - **⚠️ 暂时性性能数据和实验计划只能出现在两个地方：(1) 开头摘要区域的权威数据行；(2) §7 任务追踪表格的条目。** §1-§6 的正文不得包含会过期的具体数字或待办计划。如果 §1-§6 需要引用性能数据，只引用任务编号（如"见 #256"），不内联数据本身。
> - **⚠️ 禁止死代码和防御性编程**：替换子系统时（如 v1→v2）必须删除旧代码，不保留 `if v1 / else v2` 分支。内核代码中不保留"以防万一"的检查——只在有具体失败场景时才加 guard。每行内核代码都是审核负担，越少越好。
> **v1 权威数据**（#256 rerun，native-level rewrite 架构）：micro **1.057x** / applied-only **1.193x**；corpus **0.983x**；Tracee **+8.1%**；Tetragon **+20.3%/+32.2%**；Katran BPF **1.108-1.168x**；gap **0.581x**。vm-selftest **35/35**。v1 代码保存在 `v1-native-rewrite` 分支。

---

## 0. Abstract

eBPF is widely adopted in production for observability, networking, and customizable kernel extensions in modern production systems, yet its current just-in-time (JIT) compilers remain rigid, platform-agnostic, and severely under-optimized compared to mature runtimes such as JVM, WASM, or LLVM. Many optimizations and security hardenings are restricted due to stringent kernel safety constraints and prohibitive implementation complexity. This paper presents BpfReJIT, a dynamic, minimally invasive, and extensible kernel compilation framework that transparently optimizes kernel-resident eBPF programs. Our key insight is a novel, microkernel-inspired separation of concerns that delegates kernel safety guarantees to minimal kernel extensions, allowing lightweight verification and in-place recompilation while offloading correctness and complex optimizations to an extensible userspace daemon informed by runtime profiling data. We implement BpfReJIT within the Linux kernel with fewer than 600 lines of code modifications, transparently supporting existing eBPF tools, loaders, and subsystems. Evaluation across diverse hardware platforms and representative workloads (network monitoring, security enforcement, and observability tracing) demonstrates that BpfReJIT achieves up to 40% performance improvement, 50% reduction in binary size, and negligible overhead. BpfReJIT provides a practical, upstream-compatible path toward dynamic, extensible compilation frameworks in operating system kernels.

---

## 1. 论文定位与策略

### 1.1 背景与问题

**背景。** Linux 内核 eBPF 已在生产环境广泛使用：网络（Cilium、Katran）、可观测（Tracee、Tetragon）、安全执行（KRSI/BPF LSM）、调度（sched_ext）。

**问题。** 与成熟的用户态运行时（JVM、WASM、LLVM 后端）相比，eBPF 存在两大不足：

1. **缺乏优化**：没有平台特定指令扩展（RORX、CMOV、BEXTR、LEA），没有运行时信息引导的 PGO 或动态 JIT 重编译（如 JVM 分层编译），没有对 frozen map 的常量传播，没有基于 workload profile 的分支重排，没有数据布局优化。
2. **缺乏安全/安全加固**：没有运行时 Spectre 缓解注入，没有对有漏洞 BPF 程序的 live patching，没有对运行中程序的透明安全策略执行。

**证据。** 实验表明，对于相同的 BPF 源代码，llvmbpf（bpftime 用户态 LLVM JIT）相比内核 JIT 可实现 **30-40% 的性能提升**和 **50% 的二进制大小缩减**。

### 1.2 根因

在内核中实现类似 LLVM 的完整编译 pass 需要**数万到数十万行代码**，大量内核代码改动，容易出错（不安全），且非常困难。即使实现了简单的 peephole 优化，upstream 接受也需要很长时间（数月到数年）。而且，静态/固定的优化在某些 workload 上可能有害（例如，CMOV 在分支可预测的 workload 上比 branch 更慢）。

### 1.3 替代方案（已排除）

| 替代方案 | 问题 |
|----------|------|
| **在硬件或 SFI 沙箱中隔离 eBPF 指令** | 引入运行时开销；改变执行模型 |
| **在内核中实现所有优化** | 静态优化可能在某些 workload 上损害性能；复杂优化难以保证安全性且难以上游。已有人验证了 JIT 编译器（Jitk、Jitterbug）——不要破坏它们 |

### 1.4 核心 Insights

BpfReJIT 的设计基于三个层次的 insight：

#### Insight 1: 需要一个类似 LLVM pass 的、OS 内核级别的可扩展编译框架

> 成熟的用户态运行时（JVM、WASM、LLVM）通过**可扩展编译框架**获得高性能：LLVM 有 pass 基础设施，新优化 pass 可以作为插件注册；JVM HotSpot 基于运行时 profiling 做动态 JIT 重编译（PGO、分层编译、去优化）。
>
> eBPF 的内核 JIT **完全没有这些能力**。它是刚性的、单体的、平台无关的。我们需要一个**最小化的、动态的、可扩展的内核编译框架——类似 LLVM 的 pass 基础设施但面向 OS 内核**——为内核驻留的 eBPF 程序提供同样的可扩展、运行时引导的优化能力。

#### Insight 2: 微内核启发的关注点分离 —— "什么能优化" vs "如何优化"

> 类似微内核将机制与策略分离，BpfReJIT 将 JIT 编译分为两个关注点：
>
> - **内核组件**（最小化，~600 行）：通过轻量级内核模块为每个平台定义**"什么能被优化"**——平台特定的指令定义，包含验证语义和 native 发射回调（**kinsn**）。这是**机制**。
> - **用户态 daemon**（完整功能）：通过编译 pass 定义**"如何优化"**——基于静态分析、平台能力和运行时 profiling 数据（类似 JVM 的动态 JIT 重编译 + PGO）。这是**策略**。
>
> 新优化 = 新 module + daemon 更新，零内核改动。这是让 LLVM pass 基础设施成功的可扩展性模型，现在应用到 OS 内核。

#### Insight 3: Safety ≠ Correctness —— 与内核 eBPF 安全模型对齐

> 不同于 JVM 或 LLVM 的编译框架必须同时保证**安全性和正确性**，BpfReJIT **将正确性与安全性分离**，与已有的内核 eBPF 安全模型对齐：
>
> - **内核组件保证安全性**：不会破坏内核。已有的 BPF verifier 对通过 REJIT 提交的任何新 bytecode 提供与 BPF_PROG_LOAD 完全相同的安全保证。不需要编写新的 validator 或证明 pass 的正确性。
> - **用户态 daemon 负责正确性**：编译变换保持程序语义。如果 daemon 有 bug，程序行为可能改变，但内核安全不受影响（fail-safe）。
>
> 这种分离之所以可能，是因为 BPF 有强制性的 verifier——这是原生内核代码等系统所没有的属性（livepatch 必须完全信任 patch 作者）。这正是 eBPF 特别适合 post-load 可扩展编译框架的原因。

### 1.6 设计目标

1. **可扩展（Extensible）**：最小内核改动（~600 行），支持大量 pass。新优化 = 新 module + daemon 更新，零内核改动。
2. **透明（Transparent）**：对所有 eBPF 应用、loader 和其他 eBPF 工具/涉及的子系统完全透明。不需要 .bpf.o，不需要改应用。
3. **安全（Safe）**：框架不影响内核安全模型。Verifier 验证所有变换。
4. **零开销和更好性能（Zero overhead & better performance）**：特化后的程序运行在与原始加载完全相同的执行路径上，零稳态运行时开销。

### 1.7 三组件设计

设计和实现由 **3 个组件**组成：

**组件 1：内核 syscall 扩展**（内核源码改动，Patch 1）
- 增加和修改内核 BPF syscall 功能，允许**获取 BPF bytecode**（`BPF_PROG_GET_ORIGINAL`）和**重新验证编译一个 BPF 程序并原地替换**（`BPF_PROG_REJIT`）。
- REJIT 接受**完整的新 BPF bytecode**（不是 patch）→ 内核运行完整的 `bpf_check()` + JIT → 在同一个 `struct bpf_prog` 上原子替换 image。

**组件 2：kinsn —— 平台特定指令扩展机制**（内核源码改动，Patch 2 + 内核模块）
- 允许注册 **kinsn**：一种为平台特定指令或扩展定义验证语义并让 JIT 发射它们的方式。
- **实现**：kinsn 通过已有的 kfunc 基础设施实现——新的 `KF_INLINE_EMIT` flag 使 JIT 调用 module 提供的 emit 回调而非生成函数调用（inline kfunc）。复用了 kfunc 已有的 verifier 验证、BTF 类型系统和 module 生命周期管理。
- 最小内核模块为每个平台定义 kfunc 风格的 kinsn，包含验证函数和 JIT emit 函数（x86、arm64 等）。

**组件 3：用户态 daemon**
- 监控/profiling 内核中的 eBPF 程序
- 基于静态分析 pass、平台能力和运行时 profiling 信息，透明地动态优化它们
- 安全加固：检测和中和恶意 BPF 程序

### 1.8 类比定位

| 系统 | 类比 | 关键差异 |
|------|------|----------|
| **LLVM Pass** | 编译时 IR 变换，可扩展 | 我们是 **运行时 post-load**，safety 由 verifier 保证而非 pass 正确性 |
| **JVM HotSpot** | 运行时分层编译 + PGO | 我们在 **OS 内核级别**，安全模型更强（kernel verifier vs bytecode verifier） |
| **Linux livepatch** | 运行时内核代码替换 | 我们有 **verifier 安全保证**，livepatch 没有 |
| **K2/Merlin/EPSO** | BPF bytecode 优化 | 他们是 **compile-time pre-load**，需要原始 .bpf.o，不 transparent，不支持 PGO |
| **BCF (SOSP'25)** | Certificate-backed verification | 他们 offload verification，我们 offload optimization |

#### 与 existing work 的关键差异

| 系统 | 时机 | 执行位置 | 目的 | 需要 .bpf.o? | Transparent? | Runtime PGO? | 安全保证 |
|------|------|----------|------|:---:|:---:|:---:|----------|
| K2 (SIGCOMM'21) | pre-load | 用户态 | 性能优化 | 是 | 否 | 否 | SMT solver |
| Merlin (ASPLOS'24) | pre-load | 用户态 | 性能优化 | 是 | 否 | 否 | 编译器正确性 |
| EPSO (ASE'25) | pre-load | 用户态 | 性能优化 | 是 | 否 | 否 | 编译器正确性 |
| ePass (LPC'25 原型) | load/verify | 内核态 | 优化 + 运行时执行加强 | 是 | 否 | 否 | in-kernel pass |
| BCF (SOSP'25) | load-time | 用户态+内核 | verifier 加强 | 是 | 否 | 否 | certificate |
| **BpfReJIT** | **post-load** | **用户态+内核** | **性能优化+安全加固** | **否** | **是** | **是** | **kernel verifier** |

### 1.9 四种用途

同一框架支持四种用途：

| 用途 | 说明 |
|------|------|
| **性能优化** | wide load 合并、rotate、cmov、硬件特化 lowering、PGO、const propagation |
| **安全加固** | 插入 bounds check、speculation barrier、收紧权限、Spectre 缓解注入 |
| **恶意程序阻断** | 检测恶意 BPF prog → 替换为 no-op/安全版本 → 在线热修复，危险 helper 防火墙 |
| **运行时可观测** | 给 hot path 插入 tracing，不改应用代码 |

### 1.10 Why Userspace and kernel module (详细理由)

| 理由 | 说明 |
|------|------|
| **可更新性** | userspace daemon 可随时更新优化策略，无需等 kernel release cycle |
| **上游接受成本** | kernel patch 审核周期长（月~年级），优化逐个上游不现实；BpfReJIT 让优化以 userspace daemon 形式即时部署 |
| **算法迭代** | 优化 pattern 需要反复实验和迭代；kernel 代码一旦合入很难改，userspace 可以快速迭代而不影响 kernel 稳定性 |
| **程序级组合** | 局部有利的变换可能全局有害（I-cache cliff），userspace 做全局预算 |
| **Workload 适应** | 分支可预测性、hot path 等取决于运行时数据分布，不是静态信息 |
| **Fleet 管理** | A/B testing、gradual rollout、per-deployment customization |
| **所有权** | service owner 控制优化策略（Cilium/Katran），不是 kernel maintainer |
| **覆盖面** | kernel JIT 中有数十个可优化点，不可能全部逐一 patch 上游；统一框架一次性覆盖 |
| **安全管理** | 同一框架可做安全加固、恶意程序阻断，不需要单独系统 |

### 1.11 核心设计约束

1. **Safety/correctness 分离**：kernel verifier 保证 safety（内核不崩溃），correctness 由用户态 daemon 负责
2. **Kernel 改动最小化**：核心内核接口只加一次（~600 LOC），新优化/新 arch 全部以 module + daemon 方式部署
3. **完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach
4. **零运行时开销**：变换后的程序和原始加载路径完全一样快
5. **Fail-safe**：verify 失败 → 什么都不改，返回错误；daemon 可随时回滚
6. **BPF_PROG_REJIT 接受完整的新 BPF bytecode**，不是 patch format — daemon 提交整段新程序，kernel 走标准 verify 路径
7. **Mandatory Falsification**：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，不是发布 userspace-guided interface
8. **Daemon 零 libbpf 依赖**：daemon 只通过 raw BPF syscall（`GET_NEXT_ID`、`GET_INFO_BY_FD` + `orig_prog_insns`、`REJIT`）与内核交互，不需要 libbpf。Rust 实现。
9. **Daemon 统一命名**：用户态组件统一叫 daemon（目录 `daemon/`），不叫 scanner/optimizer/rewriter。C++ scanner 已废弃删除。
10. **Daemon 两种运行模式**：(1) **一次性模式**（`apply-all`）— 扫描所有 live 程序，优化一次，退出。用于 benchmark（确定性 paired measurement）。(2) **常驻模式**（`watch`，待实现）— 后台持续运行，watch 新加载的程序，自动优化。用于 production 部署。当前 benchmark 和 e2e 评估用模式 1；论文需说明模式 2 是 production 目标。


---

## 2. Characterization 证据摘要

| 证据 | 数值 |
|------|------|
| Exec time geomean (L/K) — **characterization gap** | **0.609x** (56 pure-JIT, strict 30×1000); 0.849x (31 pure-JIT, old 3×100)。注意：这是 llvmbpf vs stock kernel 的 gap 上界，不是 BpfReJIT 改进 |
| BpfReJIT micro improvement (recompile/stock) | blind **1.028x** (50 valid, 31W/17L); fixed-policy applied-only **1.049x** (56/56 valid, 8 applied, 5W/3L); per-family best: rotate **1.021x**, wide **1.010x**; gap recovery **4.3%** of 1.641x characterization gap |
| Code size geomean (L/K) | 0.496x |
| Byte-recompose 占 kernel surplus | 50.7%，2.24x 时间惩罚 |
| cmov 差距 | llvmbpf 31 vs kernel 0 |
| Prologue/epilogue 占 surplus | 18.5% |
| branch_layout 输入敏感性 | predictable 0.225x vs random 0.326x，差 44.6% |
| Real-program code-size | 0.618x geomean (36 unique) |
| Real-program exec-time | 0.514x geomean (14 unique) |
| Corpus directive coverage (5 fam) | 143/560 objects with sites, **14593** total sites（5 families, per-section）|
| Corpus v6 full recompile (blind) | 166 targets, **163 measured pairs**, 92 applied, exec geomean **0.868x**, code-size 0.999x, wins 40 / regressions 107 |
| Corpus v2 fixed policy recompile | 156 measured pairs, 91 applied, exec geomean **0.875x**, wins 45 / losses 101。vs blind +0.8%, vs v1 tuned -2.6% |
| Corpus 8-family census | 157/560 corpus objects with sites, **16535** total sites（8 families, per-section）。新: endian=1386, bflip=2264, zeroext=0（x86-64 预期） |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 |
| cmov 消融 | switch_dispatch +26%，binary_search +12%；bounds_ladder -18%，large_mixed -24% |

---

## 3. 变换分类

### 3.1 性能优化变换

| 变换 | 需要 kinsn? | 说明 |
|------|:---:|------|
| **WIDE_MEM** | 否 | byte load+shift+or → 已有 BPF wide load 指令。占 kernel surplus 50.7% |
| **ROTATE** | 是 | shift+or → `bpf_rotate64()` kinsn → JIT emit RORX |
| **COND_SELECT** | 是 | branch+mov → `bpf_select64()` kinsn → JIT emit CMOV。policy-sensitive：依赖分支可预测性 |
| **BITFIELD_EXTRACT** | 是 | shift+and → `bpf_extract64()` kinsn → JIT emit BEXTR |
| **BRANCH_FLIP** | 否 | if/else body 重排，用已有 BPF branch 指令。policy-sensitive：依赖 workload 热度 |
| **ENDIAN_FUSION** | 可选 | load+bswap → combined kinsn → JIT emit MOVBE |
| **ADDR_CALC** | 可选 | mov+shift+add → `bpf_lea()` kinsn → JIT emit LEA |
| **Const propagation** | 否 | 利用 frozen map / runtime invariants 做常量折叠 |
| **Subprog inline** | 否 | bytecode 层展开 subprogram call |

### 3.2 安全加固变换

| 变换 | 说明 |
|------|------|
| **危险 helper 防火墙** | 中和恶意 BPF 程序的 bpf_probe_read_kernel / bpf_send_signal 等 |
| **Spectre 缓解注入** | 在缺少 speculation barrier 的位置插入 lfence |
| **BPF 程序漏洞热修复** | verifier bug 发现后对 live 程序加额外检查 |
| **权限收紧** | 收窄过度权限的 BPF 程序的访问范围 |

### 3.3 不在范围内

完整寄存器分配、指令调度、任意 native code 注入。

---

## 4. 系统架构

### 4.1 两套正交接口，三组件架构

```
┌──────────────────────────────────────────────────────────────┐
│  Component 3: Userspace Daemon                               │
│  Defines "HOW to optimize" — compilation passes, strategy    │
│  ┌──────────┐ ┌──────────┐ ┌──────────┐ ┌────────────────┐  │
│  │ Discovery│ │ Analyzer │ │ Rewriter │ │    Profiler     │  │
│  │ (枚举    │ │ (pattern │ │ (bytecode│ │ (run_cnt/perf/ │  │
│  │  live    │ │  match)  │ │  rewrite)│ │  branch miss)  │  │
│  │  progs)  │ │          │ │          │ │                │  │
│  └────┬─────┘ └────┬─────┘ └────┬─────┘ └───────┬────────┘  │
│       │            │            │                │           │
└───────┼────────────┼────────────┼────────────────┼───────────┘
        │            │            │                │
   GET_NEXT_ID  GET_ORIGINAL   REJIT         ENABLE_STATS
        │            │            │                │
┌───────▼────────────▼────────────▼────────────────▼───────────┐
│  Component 1: Kernel Syscall Extensions                      │
│                                                              │
│  BPF_PROG_GET_ORIGINAL  → 返回 load 时保存的原始 bytecode     │
│                                                              │
│  BPF_PROG_REJIT          → 接受完整新 BPF bytecode            │
│    │  bpf_check()        → 完整 re-verify（标准路径）          │
│    │  bpf_int_jit_compile() → re-JIT（含 kinsn 展开）         │
│    │  image swap         → 原子替换 JIT image（同一 struct     │
│    │                       bpf_prog，零 attach 变化）          │
│    └  fail → 什么都不改，返回 verifier log                     │
│                                                              │
│  Component 2: kinsn — Platform-Specific Instruction Modules  │
│  Defines "WHAT CAN be optimized" — per-platform capabilities │
│    Implementation: inline kfunc (KF_INLINE_EMIT)             │
│    → verifier: check_kfunc_call()（零改动）                   │
│    → JIT: emit 自定义 native 序列（而非 CALL）                 │
│    → fallback: emit 普通 CALL（module 未加载时）               │
│                                                              │
└──────────────────────────────────────────────────────────────┘
```

### 4.2 Daemon 完整工作流

```
1. BPF_PROG_GET_NEXT_ID      → 枚举所有 live BPF 程序
2. BPF_PROG_GET_ORIGINAL      → 拿原始 bytecode + map_ids + prog_type
3. 分析 + 重写                 → 生成完整的新 BPF bytecode
                                 （可含 kinsn 调用，如 bpf_rotate64）
4. BPF_PROG_REJIT(prog_fd,   → kernel: re-verify → re-JIT → image swap
     new_insns, new_insn_cnt)    失败 → 返回错误 + verifier log，原程序不受影响
```

### 4.3 安全模型

```
Safety（kernel 保证）：
  verifier 验证新 bytecode → 内核不会崩溃/信息泄露/提权
  和 BPF_PROG_LOAD 完全相同的安全保证

Correctness（daemon 负责）：
  daemon 确保变换保持程序语义
  手段：differential testing、gradual rollout、auto-rollback
  daemon 有 bug → 程序行为可能变 → 但内核安全不受影响（fail-safe）
```

### 4.4 kinsn 机制（实现：inline kfunc）

**kinsn** 是 BpfReJIT 引入的平台特定指令扩展机制。Kernel module 注册一个 kinsn，定义验证语义和 native 发射回调。

**实现**：kinsn 通过已有的 kfunc 基础设施实现（inline kfunc），复用 kfunc 的 verifier 验证、BTF 类型系统、module 生命周期管理。

```
Kernel module（如 bpf_rotate.ko）注册 kinsn：
  1. kfunc 真实函数：bpf_rotate64(u64 val, u32 shift) → 真实内核函数（fallback）
  2. KF_INLINE_EMIT flag：标记为可内联展开
  3. JIT emit 回调：emit_rotate_x86() → 产生 RORX native 指令

BPF 程序使用 kinsn：
  extern u64 bpf_rotate64(u64 val, u32 shift) __ksym;   // 标准 kfunc 声明
  hash = bpf_rotate64(hash, 13);

Verifier 看到：普通 kfunc call → check_kfunc_call()（零 verifier 改动）
JIT 看到：KF_INLINE_EMIT → 调 module emit 回调 → emit RORX（不是 CALL）
Module 未加载：emit 普通 CALL bpf_rotate64()（优雅降级，程序仍然正确）
```

### 4.5 Kernel 文件布局（`vendor/linux-framework/` rejit-v2 分支）

| 文件 | 职责 | 组件 |
|------|------|------|
| `include/linux/bpf.h` | `bpf_kfunc_inline_ops` 结构体、注册 API | kinsn |
| `include/linux/btf.h` | `KF_INLINE_EMIT` flag | kinsn |
| `include/uapi/linux/bpf.h` | `BPF_PROG_REJIT` cmd、`orig_prog_insns` 字段 | syscall |
| `kernel/bpf/syscall.c` | GET_ORIGINAL 导出、REJIT syscall 入口 | syscall |
| `kernel/bpf/verifier.c` | kinsn 注册、load 时保存原始 bytecode | kinsn + syscall |
| `arch/x86/net/bpf_jit_comp.c` | JIT CALL case kinsn inline dispatch | kinsn |

---

## 5. 评估计划

### 5.1 Required Baselines

1. Stock kernel JIT
2. `kernel-fixed-cmov/wide/rotate/lea` peephole（固定策略）
3. `advisor-static`（CPU DB only）
4. `advisor-profiled`（CPU DB + workload profile）
5. llvmbpf 作为上界参考

### 5.2 Required Questions

1. Userspace policy 是否在不同硬件/workload/程序间产生差异？✅
2. 这些差异是否 outperform fixed kernel heuristics？✅
3. Legality substrate 在真实程序上的 directive 接受率？🔄
4. 系统是否泛化到多个 directive 家族？✅
5. Operators 能否在类似 production 部署中安全管理 policy？🔄

### 5.5 测量方法约定

- **exec_ns** 是跨 runtime 对比的正确主指标（双方都测纯 BPF 执行）
- **wall_exec_ns** 不可用于跨 runtime 对比（kernel 包含 syscall dispatch 开销）
- timing_source 追踪来源（kernel=ktime, llvmbpf=rdtsc）
- 显著性标签使用 BH-adjusted Wilcoxon，ratio CI 使用 unadjusted bootstrap
- ktime 分辨率 <100ns 的 benchmark 标记为 sub-resolution

### 5.3 Required Workloads

- **Mechanism isolation**：load_byte_recompose, binary_search, switch_dispatch, branch_layout
- **Policy-sensitivity**：cmov_select vs log2_fold（见 #20, #38）
- **Real programs**：.bpf.o corpus（Cilium/Katran/loxilb/Calico/xdp-tools/selftests，见 #32-#36）
- **End-to-end deployment**：至少一个（Cilium/Katran 级别）🔄 未完成

### 5.4 Required Hardware

1. Modern wide OoO x86 core ✅
2. Smaller-core / Atom-like x86 ❌
3. arm64 系统 🔄（CI 有，性能数据有限）

### 5.6 Benchmark Framework 架构

#### 设计原则

- **Runner 只测量**：micro_exec 是唯一的 BPF 执行/计时工具，输出标准化 JSON，每个 measurement 一行
- **Orchestrator 统一调度**：一个 Python 调度层，通过 mode 区分 micro/corpus/e2e
- **Makefile 是唯一入口**：所有 benchmark 从 `make vm-*` 触发，不用一次性脚本
- **Same-image paired measurement**：recompile 模式下 load→measure stock→recompile→measure recompile，消除 layout 噪声

#### 三层评估模型

```
┌──────────────────────────────────────────────┐
│  Configuration                                │
│  micro/config/micro_pure_jit.yaml — 62 micro 定义 │
│  corpus/config/ — corpus target 发现           │
│  e2e/cases/*/config.yaml — E2E case 定义       │
│  micro/policies/ + corpus/policies/ — 优化策略  │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Runner: micro_exec (C++)                     │
│  子命令：run-llvmbpf | run-kernel             │
│  输入：.bpf.o + .mem + repeat/warmup params   │
│  输出：JSON lines, 每行一个 measurement        │
│    {"phase":"stock","exec_ns":N,...}           │
│    {"phase":"recompile","exec_ns":N,...}       │
│  不做：target 发现、policy 选择、结果聚合       │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Orchestrator: micro/driver.py (Python)       │
│                                               │
│  ┌────────┐ ┌──────────┐ ┌─────────┐         │
│  │ micro  │ │  corpus   │ │   e2e   │         │
│  │ mode   │ │  mode     │ │  mode   │         │
│  ├────────┤ ├──────────┤ ├─────────┤         │
│  │YAML    │ │target    │ │daemon   │         │
│  │manifest│ │discovery │ │setup    │         │
│  │input   │ │io-mode   │ │workload │         │
│  │gen     │ │selection │ │trigger  │         │
│  └────────┘ └──────────┘ └─────────┘         │
│                                               │
│  共享：VM boot、micro_exec 调用、JSON 收集、    │
│       统计聚合（median/geomean/CI）、报告输出    │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Daemon: daemon/ (Rust)                        │
│  子命令：enumerate | rewrite | apply           │
│  职责：pattern matching、bytecode rewrite、    │
│         调用 BPF_PROG_REJIT syscall            │
│  依赖：零 libbpf，仅 raw BPF syscall           │
│  不做：测量、调度、结果分析                      │
└──────────────────────────────────────────────┘
```

#### 目录布局（理想）

依赖方向：`runner/` 是共享基础，`micro/`、`corpus/`、`e2e/` 各自只依赖 `runner/`，互不依赖。

```
runner/                     # 共享基础设施（不依赖 micro/corpus/e2e）
  docker/                   #   Docker build assets
  scripts/                  #   辅助脚本 (aws_arm64.sh 等)
  src/                      # C++ micro_exec 源码
  include/                  # C++ headers
  CMakeLists.txt
  libs/                     # Python 共享库
    commands.py             #   micro_exec CLI 调用构建
    results.py              #   JSON result 解析/聚合
    statistics.py           #   median/geomean/CI/Wilcoxon
    environment.py          #   CPU/governor/turbo/VM 检测
    vm.py                   #   vng boot/rwdir/exec helpers
    rejit.py                #   REJIT 相关 Python helpers

micro/                      # Micro 评估层（只依赖 runner/）
  programs/                 #   BPF .bpf.c 源码 (62 个)
  policies/                 #   Per-benchmark policy YAML
  generated-inputs/         #   输入数据 (gitignored)
  input_generators.py       #   二进制输入生成器
  catalog.py                #   micro YAML manifest 加载
  driver.py                 #   micro 调度 (import runner.libs)

corpus/                     # Corpus 评估层（只依赖 runner/）
  build/                    #   .bpf.o 收集 (gitignored)
  policies/                 #   Per-program policy YAML (580 个)
  config/                   #   Corpus manifest
  driver.py                 #   corpus 调度 (import runner.libs)
  discovery.py              #   Target 发现 + io-mode 选择

e2e/                        # E2E 评估层（只依赖 runner/）
  cases/                    #   Per-case: tracee/, tetragon/, katran/, ...
  driver.py                 #   E2E 调度 (import runner.libs)

daemon/                     # BpfReJIT daemon（Rust，独立，零 libbpf 依赖）
  Cargo.toml
  src/
    main.rs                 #   CLI: enumerate / rewrite / apply
    bpf.rs                  #   BPF syscall wrappers
    matcher.rs              #   pattern matching
    rewriter.rs             #   bytecode rewrite + branch fixup
    emit.rs                 #   per-transform emit logic

module/                     # kinsn 内核模块（out-of-tree）
  x86/                      #   x86 平台 kinsn (bpf_rotate, bpf_select, bpf_extract)
micro/config/               # Active micro suite manifest YAML
```

详细设计文档见 `docs/tmp/benchmark-framework-design.md`。

---

## 6. Kernel 分支与开发环境

### 6.1 分支清单（`vendor/linux`）

| 分支 | 用途 | 状态 |
|------|------|:---:|
| `master` | upstream 7.0-rc2 stock baseline | 基准 |
| `jit-directive-v4` | v4 框架：BPF_PROG_JIT_RECOMPILE + 4 directives（稳定基线） | ✅ |
| `jit-directive-v5` | **主力**：v5 声明式 pattern + canonical lowering（基于 v4） | ✅ |
| `jit-fixed-baselines` | 对照：CONFIG_BPF_JIT_FIXED_{ROTATE,WIDE_MEM,LEA,CMOV} | ✅ |
| `jit-directive-poc-v2` | 历史：POC v2 cmov_select 单 directive | 已被 v4 取代 |
| `jit-directive-poc` | 历史：POC v1 wide_load（方向错误）| 已弃用 |

### 6.2 Worktree 布局

- `vendor/linux` — 当前工作目录（可切换分支）
- `vendor/linux-framework` — `jit-directive-v5` worktree（永驻，基于 v4）
- `vendor/linux-baseline` — `master` worktree（stock 7.0-rc2，永驻）

### 6.3 开发环境

```
VM:        QEMU/KVM + virtme-ng
Kernel:    vendor/linux (v7.0-rc2) as submodule
JIT file:  arch/x86/net/bpf_jit_comp.c
Benchmark: micro/run_micro.py + micro_exec via BPF_PROG_TEST_RUN
Baseline:  host 6.15.11 + VM 7.0-rc2
CI:        GitHub Actions ARM64 + x86 (manual trigger)
VM 使用:   make -j$(nproc) bzImage && vng --run <worktree>/arch/x86/boot/bzImage --exec "..."
```

> v4 policy 优先级：在 `jit-fixed-baselines` 上，如果 v4 policy 附加到 prog，v4 规则优先于 fixed heuristic。

### 6.4 Root Makefile 一键命令速查

根目录 `Makefile` 提供一键构建+测试。所有 VM 目标自动依赖 bzImage。

#### 构建目标

| 命令 | 作用 |
|------|------|
| `make all` | 构建 micro_exec + BPF programs + daemon + kernel-tests |
| `make micro` | 只构建 micro_exec 和 BPF programs |
| `make daemon` | 只构建 bpfrejit-daemon CLI |
| `make kernel` | 编译 bzImage（vendor/linux-framework） |
| `make kernel-tests` | 编译 kernel self-tests (test_recompile) |

#### 快速验证（无需 VM）

| 命令 | 作用 |
|------|------|
| `make smoke` | 构建 + 本地 llvmbpf smoke test (simple, 1 iter, 10 repeat) |
| `make daemon-tests` | 构建 + 运行 daemon unit tests (ctest) |
| `make check` | = `all` + `daemon-tests` + `smoke`（完整本地验证） |

#### VM 目标（需要 bzImage + vng）

| 命令 | 作用 |
|------|------|
| `make vm-selftest` | VM 中跑 kernel self-tests (test_recompile) |
| `make vm-micro-smoke` | VM 中跑 micro smoke (simple + load_byte_recompose, kernel + recompile) |
| `make vm-micro` | VM 中跑全量 micro suite (llvmbpf + kernel + recompile, 默认 10iter/2warm/200rep) |
| `make vm-corpus` | 跑 corpus batch (per-target VM boot, 用 policy, 默认 200 repeat) |
| `make vm-e2e` | 跑全部 E2E (tracee + tetragon + bpftrace + scx；`xdp_forwarding` 已退役) |
| `make vm-all` | = `vm-selftest` + `vm-micro` + `vm-corpus` + `vm-e2e`（完整 VM 验证） |
| `make validate` | = `check` + `vm-selftest` + `vm-micro-smoke`（最小 VM 验证） |

#### 可调参数

```bash
make vm-micro ITERATIONS=2 WARMUPS=2 REPEAT=500          # strict run
make vm-micro BZIMAGE=/path/to/other/bzImage              # 自定义 kernel
make vm-corpus REPEAT=100                                  # 快速 corpus
```

#### 典型工作流

```bash
# 改完代码后最小验证
make check                    # 本地：编译 + daemon tests + smoke

# 改完 kernel 后
make kernel && make validate  # 重编 bzImage + 本地验证 + VM smoke

# 全量评估
make vm-all                   # 跑全部 micro + corpus + e2e

# 清理
make clean
```

---

## 7. 任务追踪

> **规则**：
> - 所有重要数据和文档路径只在本列表维护，不在别处重复。
> - 每次执行 subagent 都必须输出文档到 `docs/tmp/` 或 `micro/results/`，并在对应条目记录路径和关键数据。
> - 条目被取代时保留一行标注状态，不得删除。

> **v1 历史记录（#1 - #303）已移至 `docs/kernel-jit-optimization-plan-record-old.md`。** v1 架构（native-level JIT rewrite, ~6400 LOC kernel）的所有任务记录在旧档中。以下从 #304（v2 架构转向）开始。

| # | 任务 | 状态 | 关键数据 / 文档 |
|---|------|:---:|------|
| ~~1-303~~ | v1 历史任务 | 见旧档 | `docs/kernel-jit-optimization-plan-record-old.md` |
| 304 | **⚠️ 重大架构探索：BpfReJIT v2 — Verifier-guarded post-load transformation framework（2026-03-21）** | 🔄 | **架构方向讨论**，考虑从当前 native-level rewrite (~6400 LOC kernel) 转向通用 post-load program transformation 框架。核心思路：不在 native code 层做优化，改为在 BPF bytecode 层做重写 + 让 kernel verifier 验证；新优化通过 kernel module 部署；privileged daemon 自动发现/分析/重写 live BPF 程序，对应用完全透明。**最终收敛方案**见 #304a-#304d。**10 份 codex 调研报告**：(A) `kinsn_feasibility_research_20260320.md`、(B) `bpf_program_replacement_research_20260320.md`、(C) `verifier_acceptance_research_20260320.md`、(D) `architecture_comparison_osdi_20260320.md`、(E) `kinsn_minimal_implementation_20260321.md`、(F) `userspace_framework_design_research_20260321.md`、(G) `bpf_prog_rewrite_kernel_research_20260321.md`、(H) `transparent_replacement_feasibility_20260321.md`、(I) `inline_kfunc_feasibility_20260321.md`。 |
| 304a | **收敛方案：两套正交接口（2026-03-21）** | 📝 | **(接口 A) 程序变换 — GET + REJIT**：`BPF_PROG_GET_ORIGINAL` 拿原始 bytecode + `BPF_PROG_REJIT` 对同一 `struct bpf_prog` 做 bytecode patch → re-verify → re-JIT → image swap（复用现有 `jit_directives.c` staged commit/rollback/trampoline regen）。零 attach 变化、零运行时开销。**(接口 B) ISA 扩展 — Inline Kfunc**：新"指令"注册为 kfunc（复用 `register_btf_kfunc_id_set()` + 新 `KF_INLINE_EMIT` flag）；verifier 零改动（走已有 `check_kfunc_call()`）；interpreter 零改动（调真实内核函数）；JIT CALL case 检测 `KF_INLINE_EMIT` → 调 module 的 emit 回调内联展开为自定义 native 序列。优雅降级：module 未加载时 emit 普通 CALL。已有先例：`fixup_kfunc_call()` 中 `bpf_cast_to_kern_ctx`/`bpf_rdonly_cast` 等已被完全替换为 plain BPF 指令。**kernel 总改动估计 ~500-800 LOC**（GET_ORIGINAL ~70 + REJIT ~580 + Inline Kfunc ~150-200）。 |
| 304b | **关键发现汇总（2026-03-21）** | 📝 | **(1)** `struct bpf_prog` 不保留原始 bytecode — `insnsi` 被 verifier/fixup 原地改写，需在 load 时新增保存 pre-fixup baseline 到 `bpf_prog_aux`。**(2)** BPF opcode `BPF_ALU64` 的 `0xe0`/`0xf0` 是仅有干净空位，但 Inline Kfunc 不需要新 opcode。**(3)** xlated bytecode 不可逆（`convert_ctx_accesses()` + `do_misc_fixups()`），不能直接重新 PROG_LOAD。**(4)** 现有 `jit_directives.c` image swap 机制可复用。**(5)** re-verify 开销 ~ms 级（vs re-JIT ~30μs），但只发生一次。**(6)** Inline Kfunc 优于 kinsn — 零 verifier/interpreter 改动，复用 kfunc 注册/生命周期/BTF。**(7)** "interpreter 优雅降级"不成立 — kfunc 强制 JIT，降级是 "inline emit 失败 → fallback 普通 kfunc CALL"。**(8)** 常量参数编码（`RORX imm8`）需 v2 增强，v1 先做纯寄存器版。 |
| 304c | **论文定位（2026-03-21）** | 📝 | 与 K2/Merlin/EPSO **不同赛道**（runtime post-load vs compile-time pre-load）。类比：K2 = GCC -O3，我们 = JVM HotSpot。两者正交可叠加。**新定位**："Verifier-guarded, modular, post-load program transformation infrastructure for eBPF — 给 eBPF 加上类似 JVM 分层编译的能力，在 OS 内核级别，且安全模型更强（kernel verifier vs JVM bytecode verifier）"。同一框架支持四种用途：**(1)** 性能优化；**(2)** 安全加固；**(3)** 恶意程序在线热修复；**(4)** 运行时可观测。 |
| 304d | **Daemon 完整工作流（2026-03-21）** | 📝 | `BPF_PROG_GET_NEXT_ID` → `BPF_PROG_GET_ORIGINAL` → 用户态分析+重写（kinsn/kfunc 替换 or 安全加固 or PGO 决策）→ `BPF_PROG_REJIT`（kernel: patch orig bytecode → re-verify → re-JIT → image swap via RCU）。**完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach，零运行时开销。`freplace` 和 `bpf_link_update` 也可作为备选替换路径（freplace 有 ~3-5ns trampoline 开销，link_update 零开销但覆盖面有限）。 |
| 304e | **POC 实现（2026-03-21）** | ✅ | **三个 Phase 全部完成。** Phase 1 Inline Kfunc ✅（kernel `a3173b119`）：KF_INLINE_EMIT + x86 JIT dispatch + test module。Phase 2 GET_ORIGINAL ✅（kernel `36e41e7a0`）：保存+导出原始 insns。Phase 3 REJIT ✅：VM 验证 "same prog_fd re-jitted from XDP_PASS to XDP_DROP"。**+200 行 kernel 核心改动**（+297 行 selftest）。Git：`rejit-v2` 分支，v1 保存在 `v1-native-rewrite` 分支。主仓库 commits: `e50365a`（v1 snapshot）、`ba3c76e`（switch to rejit-v2）、`f5eb9f1`（plan doc rewrite）。 |
| 304f | **⚠️ REJIT 接口设计决策（2026-03-21）** | 📝 | **BPF_PROG_REJIT 接受完整的新 BPF bytecode，不是 patch。** daemon 提交整段新程序 `(prog_fd, new_insns, new_insn_cnt)` → kernel 对新 bytecode 做完整 `bpf_check()` + JIT → 原子替换同一 `struct bpf_prog` 的 image。理由：(1) daemon 有完全灵活性做任意变换；(2) kernel 走标准 verify 路径，零特殊 patch 逻辑；(3) map 引用在新 bytecode 中用 fd/BTF ID，kernel 正常 resolve。**不是 patch format** — 避免 kernel 内部 patch 应用+offset 调整的复杂度。 |
| 304g | **调研全部完成（2026-03-21）** | ✅ | **(1)** Verifier-fixup 耦合度 → **结论 4C**：xlated 不能直接喂 verifier，需保存原始 bytecode。`vendor/linux-framework/docs/tmp/verifier_fixup_coupling_analysis_20260321.md`。**(2)** 安全 use case → 推荐"危险 helper 防火墙 + exfil sinkholing"。`docs/tmp/security_usecase_research_20260321.md`。**(3)** 用户态适配 → scanner matcher 可复用，输出改为 full-program rewrite；新增 `run-rejit` 子命令。`docs/tmp/userspace_v2_adaptation_research_20260321.md`。**(4)** 综合 related work → `docs/tmp/comprehensive_related_work_20260321.md`。**(5)** 设计 gap → identity-preserving swap 是核心难点。`docs/tmp/bpfrejit_v2_design_gaps_20260321.md`。 |
| **305** | **内核 POC 修复（2026-03-21）** | ✅ | **内核代码 444 行**（vs stock 7.0-rc2），含 selftest 共 974 行。修复内容：(1) 去掉 14 项不必要防御检查；(2) UAPI 增加 `fd_array`/`fd_array_cnt` 支持 maps 和 module kfunc；(3) 去掉等长约束（只 swap JIT image，不拷贝 xlated insns）；(4) per-prog `rejit_mutex` 并发保护；(5) `attach_btf` 透传到 tmp；(6) swap 增加 `used_maps`/`kfunc_tab` 等字段；(7) sleepable 程序支持（`synchronize_rcu_tasks_trace`）。VM 测试通过：same-length PASS + different-length PASS（2→4 insns）+ inline_kfunc PASS。 |
| **306** | **Runner v1→v2 替换（2026-03-21）** | ✅ | **净删除 1,121 行**（-1320/+199）。8 文件改动，0 errors 0 warnings。删除全部 v1 scanner/policy/directive 代码。新增 `--rejit`/`--rejit-program`，runtime `kernel-rejit`。`recompile.py` 601→20 行。⚠️ 已知问题：same-bytecode 模式读 xlated insns 而非 orig_prog_insns，需后续修正（4C 结论）。 |
| **307** | **module/x86/ 真实 kinsn 模块（2026-03-21）** | ✅ | 创建 `module/x86/`：3 个模块编译通过零警告。`bpf_rotate.c`→ROL(9B)、`bpf_select.c`→CMOV(10B)、`bpf_extract.c`→BEXTR(12B)。每个含 kfunc fallback + KF_INLINE_EMIT + x86 emit 回调。 |
| **308** | **Bytecode rewriter 架构设计（2026-03-21）** | ✅ | 6 阶段 pipeline（Parse→Match→Decide→Emit→BranchFixup→Validate）。C++ 实现在 daemon/ 中，复用 70-80% 现有 matcher。变换：WIDE_MEM(N→1)、ROTATE(4→4 kfunc)、SELECT(3→7 kfunc)、EXTRACT(2→5 kfunc)。总估计 2.1-3.2k LoC。报告：`docs/tmp/rewriter_architecture_design_20260321.md`。 |
| **309** | **scanner→daemon 重命名 + 死代码清单（2026-03-21）** | ✅ | `git mv scanner daemon`，全部引用更新，编译通过。产出死代码清单：daemon/ C++ 中 v1 policy blob/JIT_RECOMPILE 路径、runner/ 中 directive_blob 路径、corpus/ 中 v1 enumerate 路径。daemon/ C++ 将被 Rust 重写取代。 |
| **310** | **Runner v1 死代码清理（2026-03-21）** | ✅ | 删除 32 行 v1 残留：`BPF_F_JIT_DIRECTIVES_FD`、`--directive-blob`、`build_sealed_directive_memfd()`、`jit_directives_fd/flags` 结构体字段。5 文件，0 errors 0 warnings。 |
| **311** | **Daemon Rust POC 实现（2026-03-21）** | ✅ | **1,834 行 Rust，21 tests all pass。** 删除全部 C++ 代码，Rust 重写。6 个模块：bpf.rs（raw syscall wrapper，零 libbpf）、insn.rs（BpfInsn repr(C)）、matcher.rs（WIDE_MEM 2-8 byte LE 检测）、emit.rs（byte-ladder→wide load）、rewriter.rs（site 应用 + addr_map + branch fixup）、main.rs（CLI: enumerate/rewrite/apply/apply-all）。依赖：libc + clap + anyhow。 |
| **312** | **VM 冒烟测试 + bug 修复（2026-03-21）** | ✅ | **20/20 PASS。** 修复 3 个 bug：(1) BPF_PROG_REJIT cmd 号统一为 39；(2) ksym list_del_rcu 后加 INIT_LIST_HEAD_RCU；(3) daemon orig_prog_len bytes÷8=insns。kinsn 模块加载/卸载成功。 |
| **313** | **Matcher Variant B 修复（2026-03-21）** | ✅ | 旧 C++ scanner 有 low-first + high-first 两种 variant，Rust daemon 只有 low-first。添加 `match_wide_mem_high_first()`，**27 tests all pass**。 |
| **314** | **daemon-apply 集成 + --daemon-path（2026-03-21）** | ✅ | micro_exec 新增 `--daemon-path`，fork/exec daemon apply <prog_id>。~50 行改动。driver.py + Makefile 适配。 |
| **315** | **⚠️ v2 WIDE_MEM 性能结果（2026-03-21）** | ✅ | **14 个 micro benchmark，10 个有 WIDE_MEM site（71%）。** 显著加速：bounds_ladder **2.78x**、load_byte **2.59x**、stride_load_16 **2.46x**、bitfield_extract **1.33x**、load_byte_recompose **1.17x**。Katran e2e：daemon 找到 4 site 但 REJIT 返回 EOPNOTSUPP（func_cnt>0 限制）。Commit `27cbc1b`。 |
| **316** | **Paper tex v2 更新（2026-03-21）** | ✅ | Abstract 一字不差替换，Title 更新，Introduction/Background 全部重写（v2 三 insights + 三组件），Design/Eval 用 v2 占位符。+463/-866 行。删除全部 v1 内容。新增 7 bib 条目。 |
| **317** | **corpus/ 死代码清理（2026-03-21）** | ✅ | 净删 ~329 行。删除 `apply_recompile_v5()`、`_apply_one_v5_enumerate()`、`build_kernel_command()` 等 v1 路径。所有 import 验证通过。 |
| **318** | **driver.py --daemon-path 适配（2026-03-21）** | ✅ | micro/driver.py 新增 `--daemon-path` 参数，Makefile `vm-micro` 自动传 DAEMON_PATH。+10 行。 |
| **319** | **Makefile cmake→cargo（2026-03-21）** | ✅ | daemon target 从 cmake 改为 cargo build。CLAUDE.md 同步更新。 |
| **320** | **Commit push（2026-03-21）** | ✅ | 3 commits：`698334f`（主 #305-#311）、`56d6d19`（清理）、`c48cb43`（补全）。kernel submodule `4bcbc8e21`。 |
| **321** | **Daemon pass 框架设计（2026-03-21）** | ✅ | BpfPass/Analysis/AnalysisCache/PassManager 框架。线性 insn+annotation IR。6 分析 + 6 pass。渐进迁移路径。报告：`docs/tmp/daemon_pass_framework_design_20260321.md`。 |
| **322** | **Kernel code review by codex（2026-03-21）** | ✅ | 发现 3 Critical（旧 image UAF、attachment 缓存不同步、KERNEL_BPFPTR 伪装）+ 4 Major。报告：`docs/tmp/kernel_v2_review_20260321.md`。 |
| **323** | **ARM64 inline kfunc + kinsn 模块（2026-03-21）** | ✅ | 内核 `bpf.h` +emit_arm64（+12）、`arm64/bpf_jit_comp.c` +dispatch（+44）。`module/arm64/` 3 模块（ROR 4B、CSEL 8B、LSR+AND 20B）。交叉编译通过。+613 行。 |
| **324** | **e2e v2 daemon 集成（2026-03-21）** | ✅ | 5 case 全部接入 baseline→daemon apply-all→post_rejit 流程。净减 314 行。 |
| **325** | **Attachment sync 调研（2026-03-21）** | 🔄 | 调研 REJIT 后各 backend（XDP/TC/cgroup/LSM/trampoline 等）的 bpf_func 缓存更新方案。4 候选方案对比。codex 进行中。 |
| **326** | **Verifier log parser POC（2026-03-21）** | 🔄 | 解析 verifier log level 2 提取 per-insn 寄存器状态，用于 daemon Analysis。codex 进行中。 |
| **327** | **Daemon profiling 调研 + POC（2026-03-21）** | 🔄 | 调研 bpf_stats/perf/kprobe 等数据源获取运行时 profile。codex 进行中。 |
| 328 | Daemon pass 框架实现 | 待定 | 依赖 #321 设计。重构 ad-hoc matcher 为 pass 框架。 |
| 329 | kinsn pass（ROTATE/SELECT/EXTRACT） | 待定 | 依赖 #307 #328。 |
| 330 | 内核 Critical issue 修复 | 待定 | 依赖 #322 #325。修复 attachment sync + KERNEL_BPFPTR + image lifecycle。 |
| 331 | VM 全量 micro suite rejit | 待定 | `make vm-micro` 跑全部 57 个 benchmark。 |
| 332 | 全量评估：stock vs rejit vs llvmbpf | 待定 | 三方对比。 |

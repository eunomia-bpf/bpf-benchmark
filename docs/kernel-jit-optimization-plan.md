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
│  Scanner: scanner/ (C++)                      │
│  子命令：enumerate | scan | apply | policy     │
│  职责：pattern matching、policy 编译、blob 生成  │
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
    recompile.py            #   scanner enumerate → apply 共享
    policy.py               #   policy YAML v3 解析

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

scanner/                    # Scanner + policy compiler（独立）
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
| `make all` | 构建 micro_exec + BPF programs + scanner + kernel-tests |
| `make micro` | 只构建 micro_exec 和 BPF programs |
| `make scanner` | 只构建 scanner CLI |
| `make kernel` | 编译 bzImage（vendor/linux-framework） |
| `make kernel-tests` | 编译 kernel self-tests (test_recompile) |

#### 快速验证（无需 VM）

| 命令 | 作用 |
|------|------|
| `make smoke` | 构建 + 本地 llvmbpf smoke test (simple, 1 iter, 10 repeat) |
| `make scanner-tests` | 构建 + 运行 scanner unit tests (ctest) |
| `make check` | = `all` + `scanner-tests` + `smoke`（完整本地验证） |

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
make check                    # 本地：编译 + scanner tests + smoke

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

| # | 任务 | 状态 | 关键数据 / 文档 |
|---|------|:---:|------|
| 1 | v3 JIT pass 框架设计 | ✅ | 8/10。`docs/tmp/2026-03-09/jit-pass-framework-v3-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v3-final-verdict.md` |
| 2 | v4 Post-load re-JIT 设计 | ✅ | `docs/tmp/2026-03-09/jit-pass-framework-v4-design.md` |
| 3 | v5 声明式 Pattern 设计 | ✅ | 7.5/10。`docs/tmp/2026-03-09/jit-pass-framework-v5-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v5-review.md` |
| 4 | v7 Hybrid 设计 | ✅ | `docs/tmp/2026-03-08/bpf-jit-advisor-v7.md`，`docs/tmp/2026-03-08/bpf-jit-advisor-v7-review.md` |
| 5 | Interface 设计 | ✅ | 6/10。`docs/tmp/2026-03-08/interface-design-detail.md`，`docs/tmp/2026-03-08/interface-design-review.md` |
| 6 | Verifier-rewrite 分析 | ✅ | JIT lowering 为主。`docs/tmp/2026-03-08/verifier-rewrite-approach.md` |
| 7 | Policy decision layer | ✅ | 3 级策略。`docs/tmp/2026-03-10/policy-decision-layer-design.md` |
| 8 | Directive 发现 | ✅ | 11 候选。`docs/tmp/2026-03-08/directive-discovery-analysis.md` |
| 9 | OSDI readiness | ✅ | 4/10。`docs/tmp/2026-03-08/osdi-readiness-review.md` |
| 10 | 跨文档交叉验证 | ✅ | `docs/tmp/2026-03-08/cross-document-review.md` |
| 11 | POC v1: wide_load verifier rewrite | ⚠️ 方向错误 | `docs/tmp/2026-03-09/poc-design-review.md` |
| 12 | POC v2: cmov_select JIT lowering | ✅ | jited 4168→4167。`docs/tmp/2026-03-09/poc-v2-design-conformance-review.md` |
| 13 | v4 POC（4 directives） | ✅ | ~850 LOC kernel。branch `jit-directive-v4` |
| 14 | v4 bug 修复 | ✅ | `docs/tmp/2026-03-09/v4-bug-diagnosis.md` |
| 15 | v4 review | ✅ | 6/10。`docs/tmp/2026-03-09/v4-implementation-review.md` |
| 16 | v4 Round 1 | ✅ | ADDR_CALC -12%，COND_SELECT log2_fold **+28%**（policy-sensitivity）。`docs/tmp/2026-03-09/v4-round1-test-results.md` |
| 17 | v4 Round 2: WIDE_MEM | ✅ | load_byte_recompose **-13%**。`docs/tmp/2026-03-09/v4-round2-test-results.md`，`docs/tmp/2026-03-09/v4-round2-implementation.md` |
| 18 | v4 Round 3: ROTATE | ✅ | rotate64_hash **-28.4%**。composability 验证。`docs/tmp/2026-03-09/v4-round3-test-results.md` |
| 19 | Fixed baselines 设计 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-design.md` |
| 20 | Fixed baselines 测试 | ✅ | CMOV 必须 policy-controlled。`docs/tmp/2026-03-10/kernel-fixed-baselines-test-results.md` |
| 21 | Per-directive 隔离测试 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-per-directive.md` |
| 22 | v5 POC | ✅ | v5=v4 功能等价。`docs/tmp/2026-03-10/v5-minimal-poc-results.md` |
| 23 | v5 迭代 | ✅ | `docs/tmp/2026-03-10/v5-iteration-results.md` |
| 24 | v5 canonical binding | ✅ | v4 1018 LOC vs v5 32 LOC (32x)。`docs/tmp/2026-03-10/v5-canonical-binding-results.md`，`docs/tmp/2026-03-10/extensibility-quantification.md` |
| 25 | Scanner 独立化 | ✅ | `docs/tmp/2026-03-10/scanner-cleanup-results.md` |
| 26 | v5 gap analysis | ✅ | 6.5/10。`docs/tmp/2026-03-10/v5-design-gap-analysis.md` |
| 27 | Framework review | ✅ | 4/10。`docs/tmp/2026-03-10/framework-architecture-review.md` |
| 28 | cmov subprog fix | ⚠️ | emitter bug 见 #47。`docs/tmp/2026-03-10/cmov-subprog-fix-results.md` |
| 29 | Pure-JIT audit | ✅ | `docs/tmp/2026-03-08/pure-jit-benchmark-audit.md` |
| 30 | Host 重跑 | ✅ | pure-jit L/K=**0.797x**。`micro/results/pure_jit_with_cmov.json` |
| 31 | VM 重跑 | ✅ | VM/host parity。`docs/tmp/2026-03-08/vm-rerun-analysis.md` |
| 32 | Directive census | ✅ | 67/98 有 sites，1029 总 sites。`docs/tmp/2026-03-11/real-program-directive-census.md` |
| 33 | Corpus v5 recompile | ✅ | 37/40 apply。`docs/tmp/2026-03-10/corpus-v5-recompile-results.md` |
| 34 | Production corpus | ✅ | Cilium/Katran/xdp-tools。`docs/tmp/2026-03-10/production-program-compilation.md` |
| 35 | Production recompile | ✅ | 15/15 成功。`docs/tmp/2026-03-10/production-corpus-v5-rerun-results.md` |
| 36 | Corpus 扩充 R2 | ✅ | 529 总 .bpf.o（22 项目）。`docs/tmp/2026-03-10/corpus-expansion-round2.md` |
| 37 | Scanner rotate fix | ✅ | `docs/tmp/2026-03-10/scanner-gap-fix.md` |
| 38 | 严格 benchmark | ✅ | CMOV **0.655x**, ROTATE **1.193x**。`docs/tmp/2026-03-10/rigorous-benchmark-results.md` |
| 39 | 微架构实验 | ✅ | PMU/频率/输入分布。`docs/tmp/2026-03-08/microarch_experiments.md` |
| 40 | ARM64 CI | ✅ | 3 轮修复。 |
| 41 | ARM64 分析 | ✅ | L/K=**0.656x**。`docs/tmp/2026-03-08/arm64-cross-arch-analysis.md`，`docs/tmp/2026-03-11/arm64-analysis-review.md` |
| 42 | EINVAL debug | ✅ | production EINVAL 修复。 |
| 43 | Benchmark 审计 | ✅ | `docs/tmp/2026-03-11/benchmark-infrastructure-audit.md` |
| 44 | Benchmark 分析 | ✅ | `docs/tmp/2026-03-10/benchmark-framework-analysis.md` |
| 45 | 论文 LaTeX | 🔄 | R3 6.5/10。`docs/paper/paper.tex`，`docs/tmp/2026-03-10/paper-review-r3-post-rewrite.md` |
| 46 | COND_SELECT v5 | ✅ | `docs/tmp/2026-03-10/cmov-v5-migration-report.md` |
| 47 | cmov emitter fix | ✅ | site index 修复。`docs/tmp/2026-03-10/cmov-emitter-fix-report.md` |
| 48 | Benchmark 重构 | 🔄 | P0 5/5 完成。`docs/tmp/2026-03-10/p0-bugfix-report.md` |
| 49 | 端到端部署 | 已取消 | |
| 50 | 论文更新 | 已取消 | |
| 51 | log_level/log_buf | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 52 | Shape whitelist | ✅ | site_len≤64。`docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 53 | Overlap 语义 | ❌ | 未实现。 |
| 54 | Subprog 一致性 | ❌ | 未同步。 |
| 55 | K2/Merlin/EPSO 对比 | ✅ | **正交非替代**，backend gap 89.1%。`docs/tmp/2026-03-11/k2-merlin-epso-comparison.md` |
| 56 | RCU 安全分析 | ✅ | `docs/tmp/2026-03-11/rejit-rcu-safety-analysis.md` |
| 57 | 消融补全 | ❌ | |
| 58 | ZERO_EXTEND | ❌ | |
| 59 | ARM64 backend | ❌ | |
| 60 | 严格重跑 30×1000 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_strict_20260312.json` |
| 61 | Benchmark 多样性 | 🟡 | 67 micro + 79 corpus paired。`docs/tmp/2026-03-11/benchmark-diversity-audit.md` |
| 62 | CMOV 信号增强 | ❌ | 仅 2.8% 改善。 |
| 63 | E2E throughput | 已取消 | 随 #49。 |
| 64 | Corpus 可运行性 | ✅ | 381 runnable / 3069 sites。`docs/tmp/2026-03-11/corpus-runnability-report.md` |
| 65 | Corpus 批量 recompile | ✅ | geomean **0.847x**。`docs/tmp/2026-03-11/corpus-batch-recompile-results.md`，`docs/tmp/2026-03-11/corpus-recompile-regression-analysis.md` |
| 66 | 非网络 E2E 研究 | ✅ | Tracee+Tetragon+bpftrace+scx。`docs/tmp/2026-03-11/non-networking-evaluation-plan.md` |
| 67 | Framework 重构 Step 1-3 | ✅ | 共享 Python 层。`docs/tmp/2026-03-11/framework-improvement-step1.md` |
| 68 | Corpus 扩展 R3 | ✅ | 560 objects（23 项目）。`docs/tmp/2026-03-11/corpus-expansion-round3.md` |
| 69 | Selective CMOV policy | ✅ | global skip-cmov 不足。`docs/tmp/2026-03-11/selective-policy-results.md` |
| 70 | bpftrace E2E driver | ✅ | 9 CMOV sites。`docs/tmp/2026-03-11/bpftrace-e2e-results.md` |
| 70a | Tetragon harness | ✅ | `docs/tmp/2026-03-11/tetragon-e2e-results.md` |
| 70b | BPF-side VM 测试 | ✅ | Tracee **2.71x**。`docs/tmp/2026-03-11/tracee-e2e-vm-summary.md`，`docs/tmp/2026-03-11/bpftrace-e2e-vm-summary.md`，`docs/tmp/2026-03-11/tetragon-e2e-vm-summary.md` |
| 70c | Framework 重构 Steps 2-7 | ✅ | `micro/driver.py` 统一入口。`docs/tmp/2026-03-11/framework-improvement-steps2-7.md` |
| 71 | 仓库三层重组 | ✅ | micro/corpus/e2e 分离。`docs/tmp/2026-03-11/repo-restructure-report.md` |
| 72 | Tracee E2E | ✅ | exec_storm **+21.65%**。`docs/tmp/2026-03-11/tracee-real-e2e-report.md`，`e2e/results/tracee-e2e-real.json` |
| 73 | Kernel 重编 | ✅ | FTRACE_SYSCALLS+SCHED_CLASS_EXT。`docs/tmp/2026-03-11/kernel-rebuild-report.md` |
| 74 | Tetragon E2E | ✅ | stress_exec **+6.7%**，BPF **-14.5%**。`e2e/results/tetragon-real-e2e.json` |
| 75 | bpftrace E2E | ✅ | geomean **0.992x**（policy-sensitivity）。`docs/tmp/2026-03-12/bpftrace-real-e2e-report.md`，`e2e/results/bpftrace-real-e2e.json` |
| 77 | Directive gap 分析 | ✅ | CMOV 应为 policy-sensitivity 证据。`docs/tmp/2026-03-11/directive-gap-analysis.md` |
| 78 | cmov 识别加宽 | ✅ | `docs/tmp/2026-03-11/cmov-broadening-report.md` |
| 79 | bitfield_extract | ✅ | **544 sites / 41 objects**。`docs/tmp/2026-03-11/bitfield-extract-implementation.md` |
| 80 | wide_load 扩展 | ✅ | **2835 sites**。`docs/tmp/2026-03-11/wide-load-extension-report.md` |
| 81 | branch_reorder | 归入 #89 | BRANCH_FLIP 简单版。 |
| 82 | bounds_window | ❌ | 未实现。 |
| 83 | Kernel JIT 清理 | ✅ | 零偏移+imm64 优化。`docs/tmp/2026-03-11/kernel-jit-cleanup-patches.md` |
| 84 | Interface v6 提案 | ✅ | `docs/tmp/2026-03-11/interface-design-audit.md`，`docs/tmp/2026-03-11/interface-improvement-proposals.md` |
| 85 | v4 删除 | ✅ | -778 LOC。 |
| 86 | v6 tier-1 | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 87 | v6 接口研究 | ✅ | verifier log 足够 discovery。`docs/tmp/2026-03-11/v6-interface-design.md` |
| 88 | Framework audit v2 | ✅ | `docs/tmp/2026-03-11/benchmark-framework-audit-v2.md` |
| 89 | 新 forms (ZEXT/ENDIAN/BFLIP) | ✅ | 3 form 落地。`docs/tmp/2026-03-11/new-canonical-forms-implementation.md` |
| 90 | Corpus 全量 v6 | ✅ | geomean **0.868x**，92 applied。`docs/tmp/2026-03-11/corpus-full-recompile-v6.md` |
| 91 | 优化方向研究 | ✅ | Top 3 方向。`docs/tmp/2026-03-11/optimization-beyond-isel.md` |
| 92 | 8-family census | ✅ | 17637 total sites，zeroext=0。`docs/tmp/2026-03-11/corpus-8families-census-persection.md` |
| 93 | Micro 精简 | ✅ | 56-case pure-jit only。 |
| 94 | Micro input 去 map | ✅ | packet buffer 传入。 |
| 95 | Tracing corpus driver | ✅ | attach+trigger 测量。 |
| 96 | Corpus 整理 | ✅ | |
| 97 | Policy 配置设计 | ✅ | 统一 YAML schema + 5 阶段 auto-tuning。`docs/tmp/2026-03-11/policy-configuration-design.md` |
| 99 | Micro Python 整理 | ✅ | 归档+共享 helper。 |
| 99a | Micro cleanup follow-up | ✅ | |
| 98 | Policy v2 设计 | ✅ | 程序无关 auto-tuning。`docs/tmp/2026-03-12/policy-configuration-design-v2.md` |
| 98a | Policy P0+P1 | ✅ | 8-family surface + scanner compile-policy。 |
| 98b | P2 Micro policy | ✅ | manifest-driven policy plumbing。 |
| 98e | P3 Corpus policy | ✅ | per-program policy files。 |
| 98c | Tracing corpus VM | ✅ | 473 ready / 315 attached。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 98d | Code-size systematic | ✅ | `docs/tmp/2026-03-11/code-size-by-progtype.md` |
| 98f | P4 Auto-tuner | ✅ | prototype landed。`corpus/auto_tune.py` |
| 100 | Micro 回归修复 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_20260312.json` |
| 101 | Corpus driver dedup | ✅ | -385 行。 |
| 102 | Inventory audit | ✅ | `docs/tmp/2026-03-11/benchmark-inventory-audit.md` |
| 103 | Policy pipeline | ✅ | `docs/tmp/2026-03-11/policy-pipeline-analysis.md` |
| 104 | Corpus tuned policy | ✅ | geomean 0.868x→**0.898x**。`docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md` |
| 105 | E2E policy 接线 | ✅ | per-program policy lookup。 |
| 106 | 结果目录规范 | ✅ | authoritative naming + symlinks。 |
| 107 | Code-size VM | ✅ | geomean **1.003x**。`docs/tmp/2026-03-11/code-size-full-vm-results.md` |
| 108 | Tracing corpus VM | ✅ | applied-only **1.019x**。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 109 | scx EINVAL | ✅ | extable guard 修复。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 110 | llvmbpf map inline POC | ✅ | **1.30x** speedup。`docs/tmp/2026-03-11/llvmbpf-array-map-inline-poc.md` |
| 111 | XDP forwarding PPS | ✅（已退役） | +0.27%，见 #203。 |
| 112 | Strict micro 30×1000 | ✅ | geomean **0.609x**，53/56 wins。`docs/tmp/2026-03-11/sub-ktime-and-strict-analysis.md` |
| 113 | Policy <1.0x 分析 | ✅ | non-CMOV families 回归。`docs/tmp/2026-03-11/policy-improvement-analysis.md` |
| 114 | Policy v2 格式 | ✅ | site > family > default 优先级。 |
| 115 | Strict 分析 | ✅ | 归入 #112。 |
| 116 | bflip/endian sweep | ✅ | bflip+endian:skip **0.857x**。`docs/tmp/2026-03-11/bflip-endian-skip-sweep.md` |
| 117 | scx EINVAL 调查 | ✅ | 归入 #109。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 118 | Recompile micro strict | ✅ | overall **1.028x**，applied **1.024x**。`docs/tmp/2026-03-11/kernel-recompile-micro-strict.md` |
| 119 | XDP forwarding VM | ✅（已退役） | +0.27%，见 #203。`docs/tmp/2026-03-11/xdp-forwarding-live-vm-report.md` |
| 120 | Corpus v2 policy rerun | ✅ | **0.848x**（pre-fix baseline）。`docs/tmp/2026-03-11/corpus-v2-policy-rerun.md` |
| 121 | E2E v2 policy rerun | ✅ | wiring 验证，site 漂移导致 0 apply。`docs/tmp/2026-03-11/e2e-v2-policy-rerun.md` |
| 122 | v2 pipeline 迁移 | ✅ | scanner v2-only。`docs/tmp/2026-03-11/v2-pipeline-migration-report.md` |
| 123 | Per-family 消融 | ✅ | wide **1.010x**, rotate **1.021x**, cmov **0.974x**。`docs/tmp/2026-03-11/kernel-recompile-per-family-ablation.md` |
| 124 | 论文审计 | 已取消 | |
| 125 | Gap 分解 | ✅ | recovery **4.3%** of gap。`docs/tmp/2026-03-11/characterization-gap-decomposition.md` |
| 126 | Micro v2 tuned rerun | ✅ | applied-only **1.040x**。`docs/tmp/2026-03-11/kernel-recompile-micro-v2-tuned.md` |
| 128 | Corpus v2 policy fix | ✅ | site 漂移修复，0.758x→**1.055x**（13-target smoke）。`docs/tmp/2026-03-12/corpus-v2-policy-diagnosis.md` |
| 129 | Micro mismatch fix | ✅ | cmov site 触发 wrong-code。源级修复见 #138。`docs/tmp/2026-03-12/micro-mismatch-crash-diagnosis.md` |
| 127 | 阶段性 review | ✅ | 4 critical 不一致。`docs/tmp/2026-03-12/stage-review-report.md` |
| 130 | 默认语义修正 | ✅ | no-policy → stock。 |
| 131 | Inline policy v1→v2 | ✅ | policy_file 引用替换 inline。 |
| 132 | v2 spec 文档 | ✅ | `docs/tmp/2026-03-12/policy-v2-authoritative-spec.md` |
| 133 | Corpus v2 fixed rerun | ✅ | **0.875x**（91 applied）。`docs/tmp/2026-03-12/corpus-v2-fixed-rerun.md` |
| 134 | E2E v2 fixed rerun | ✅ | cmov skip 过滤生效。`docs/tmp/2026-03-12/e2e-v2-fixed-rerun.md` |
| 135 | Parser 一致性测试 | ✅ | golden tests。`docs/tmp/2026-03-12/parser-consistency-fix.md` |
| 136 | Plan doc 修正 | ✅ | 过时条目描述回写。 |
| 137 | bpftrace policy artifacts | ✅ | 12 cmov sites。`docs/tmp/2026-03-12/bpftrace-policy-artifacts.md` |
| 138 | CMOV/EXTRACT fix | ✅ | emitter fail-close + BEXTR ModRM 修正。`docs/tmp/2026-03-12/cmov-emitter-fix.md` |
| 139 | Micro authoritative | ✅ | 56/56 valid，applied-only **1.049x**。`docs/tmp/2026-03-12/kernel-recompile-micro-v2-fixed-authoritative.md` |
| 140 | Tetragon 回归调查 | ✅ | workload 噪声。`docs/tmp/2026-03-12/tetragon-connect-storm-investigation.md` |
| 141 | Per-family v1→v2 | ✅ | 8 policy 升级。 |
| 142 | v1 清理 | ✅ 被 #145 取代 | v2 纯化，后续切 v3。 |
| 143 | Post-fix micro rerun | ✅ | 11/56 applied，**1.007x**。`docs/tmp/2026-03-12/post-cmov-fix-micro-rerun.md` |
| 144 | CMOV 消融 | ✅ | CMOV 仍负面，保留 cmov:skip。`docs/tmp/2026-03-12/post-cmov-fix-corpus-ablation.md` |
| 145 | v3 policy | ✅ | per-site directive list，614 YAML 通过。 |
| 146 | Recompile 开销 | ✅ | scanner **4.32ms**，syscall **29.89μs**。`docs/tmp/2026-03-12/recompile-overhead-measurement.md` |
| 147 | bpftrace v3 validation | ✅ | `docs/tmp/2026-03-12/bpftrace-e2e-v3-validation.md` |
| 148 | 架构 Review + 图 | ✅ | `docs/tmp/2026-03-12/architecture-review-and-diagrams.md` |
| 149 | Canonical-site hardening | ✅ | 8 form 双重校验。 |
| 150 | Kernel cleanup | ✅ | RORX bug 等修复。`docs/tmp/2026-03-12/kernel-engineering-cleanup.md` |
| 151 | Kernel self-tests | ✅ | 18/18 PASS。`docs/tmp/2026-03-12/kernel-selftest-run.md` |
| 152 | Kernel safety fixes | ✅ | smp_store_release + RCU 等。`docs/tmp/2026-03-12/kernel-safety-fixes.md` |
| 153 | JIT image diff | ✅ | **re-JIT 改 non-site 字节**（code layout shift）。zero-site 短路已修。`docs/tmp/2026-03-12/jit-image-diff-analysis.md` |
| 154 | Per-form benchmark | ✅ | +6 纯隔离 benchmark。`docs/tmp/2026-03-12/per-form-benchmarks-implementation.md` |
| 155 | Corpus regressor root cause | ✅ | 3/10 真实回归（branch-flip）。`docs/tmp/2026-03-12/corpus-regressor-root-cause.md` |
| 156 | Measurement fix | ✅ | dual TSC + warmup。`docs/tmp/2026-03-12/kernel-runner-measurement-fixes.md` |
| 157 | Framework audit v3 | ✅ | corpus construct validity 问题。`docs/tmp/2026-03-12/benchmark-framework-audit-v3.md` |
| 158 | Post-cleanup 验证 | 🔄 | 62/62 micro valid。`docs/tmp/2026-03-12/post-cleanup-validation.md` |
| 159 | Root Makefile | ✅ | 一键 build+test。`docs/tmp/2026-03-12/root-makefile-report.md` |
| 160 | Post-fix micro 62 bench | ✅ | applied-only **0.877x**。`docs/tmp/2026-03-12/post-fix-micro-62bench-rerun.md` |
| 161 | Scanner pattern_kind fix | ✅ | `docs/tmp/2026-03-12/scanner-pattern-kind-investigation.md` |
| 162 | Corpus validity 分析 | ✅ | corpus exec **无效**（噪声主导），code size 有效。`docs/tmp/2026-03-12/corpus-construct-validity-analysis.md` |
| 163 | Scanner enumerate | ✅ | live program 分析，197 progs / 1920 sites。`docs/tmp/2026-03-12/scanner-enumerate-implementation.md` |
| 164 | E2E 切 enumerate | ✅ | `docs/tmp/2026-03-13/e2e-enumerate-pipeline-switch.md` |
| 165 | 消融补全 | ✅ | byte-recompose **50.7%**，callee-saved ~0%，BMI ~0%。`docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md` |
| 166 | Per-form 矛盾调查 | ✅ | emitter bug 导致零变化。`docs/tmp/2026-03-13/per-form-discrepancy-investigation.md` |
| 167 | Emitter 修复 | ✅ | BEXTR VEX 修正，extract_dense -6.8%。`docs/tmp/2026-03-13/emitter-fix-extract-endian-bflip.md` |
| 168 | endian/bflip 回归 | ✅ | same-size I-cache flush 开销 > 微架构收益。`docs/tmp/2026-03-13/endian-bflip-perf-investigation.md` |
| 170 | Enumerate manifest | ✅ | --json per-site 输出。 |
| 171 | Daemon 模式 | ❌ 暂不做 | 论文不需要。 |
| 172 | Native code 分析 | ❌ | jited_prog_insns 未用。 |
| 173 | Corpus 切 enumerate | ✅ | |
| 76 | scx E2E | 🔄 | 28 sites，struct_ops -EOPNOTSUPP。`docs/tmp/2026-03-11/scx-e2e-report.md`，`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 169 | Post-BEXTR rerun | ✅ | overall **1.003x**，applied **0.932x**。extract_dense **0.556x** 回归。`docs/tmp/active/micro-62bench-post-bextr-fix.md`，`micro/results/micro_62bench_post_bextr_fix_20260313.json` |
| 174 | Patch-site 架构 | ❌ | 消除 I-cache flush 开销。 |
| 175 | WIDE_MEM 扩展 | ❌ | byte-recompose 50.7%。 |
| 176 | Prologue 优化 | ❌ | 占 gap 18.5%。 |
| 177 | Cost model | ❌ | 跳过 same-size/dense 超阈值。 |
| 178 | 更多 E2E 数据 | ❌ | 目标 ≥3 workload 正向。 |
| 179 | Per-form ablation | ✅ | ROTATE **0.923x** win，CMOV **1.068x** loss。`docs/tmp/micro-per-form-ablation.md` |
| 180 | 框架重构 Makefile | ✅ | file-based deps + provenance + POLICY=。 |
| 181 | CI 修复 | ✅ | driver.py + requirements.txt。 |
| 182 | Opus review | ✅ | 架构✅，方法学有 gap。`docs/tmp/deep-review-*.md` |
| 183 | P0.1 更多 E2E | 🔄 已被 #304 搁置 | Tracee +6.28%/+7.00%。 |
| 184 | P0.2 Corpus >1.05x | 🔄 已被 #304 搁置 | 当前 1.046x。 |
| 185-188 | P1 优化方向 | ❌ 已被 #304 搁置 | prologue / patch-site / wide 扩展 / native 分析。 |
| 189 | Micro policy 优化 | ✅ | applied-only **1.110x**（7 applied）。`micro/results/vm_micro_authoritative_20260318.json` |
| 190 | 结果目录 + schema | ✅ | authoritative naming，policy 内嵌。 |
| 191 | Corpus+E2E 分析 | ✅ | stale policy 是主因。`docs/tmp/corpus_e2e_performance_analysis_20260318.md` |
| 192 | Katran E2E 可行性 | ✅ | 94 live sites。`docs/tmp/katran_e2e_feasibility_20260318.md` |
| 193 | Corpus policy refresh | ✅ | 582 个 v3 policy，skip cmov+extract。 |
| 194 | 项目卫生审计 | ✅ | `docs/tmp/project_hygiene_audit_20260318.md` |
| 195 | 内核修改文档 | ✅ | 1017 行。`docs/tmp/kernel_modifications_analysis.md` |
| 196 | Framework 设计文档 | ✅ | 800+ 行。`docs/tmp/benchmark_framework_analysis.md` |
| 197 | Micro 第三轮 | ✅ 归入 #189 | |
| 198 | prog_fd 残留清理 | ✅ | enumerate-only。 |
| 199 | Corpus refreshed rerun | ⚠️ | applied-only **1.077x**，overall 0.881x。 |
| 200 | **Tetragon rerun（2026-03-18）** | ⚠️ | connect_storm **-55.96%** 回归，见 #204 修复。 |
| 201 | **Kernel WARN_ON 排查（2026-03-18）** | ✅ | tailcall poke descriptor 冲突，暂不修。报告：`docs/tmp/kernel_warn_on_investigation_20260318.md`。 |
| 202 | **Katran E2E 完整设计（2026-03-18）** | ✅ | DSR 拓扑设计。报告：`docs/tmp/e2e_design_katran_20260318.md`。 |
| 203 | **XDP forwarding E2E 删除（2026-03-18）** | ✅ | 已删除 `e2e/cases/xdp_forwarding/` + 结果 + 文档引用。commit `431fdc5`。 |
| 204 | **Tetragon connect_storm 修复（2026-03-18）** | ✅ | stress_exec **+8.70%**，connect_storm **+22.29%**。3 applied / 49 bflip sites。报告：`docs/tmp/tetragon_connect_storm_investigation_20260318.md`。 |
| 205 | **Katran E2E MVP 实现（2026-03-18）** | 🔄 | 创建 e2e/cases/katran/，注册到 e2e/run.py，第一版用 standalone bpftool load 做 smoke。 |
| 206 | **Sequential rerun round 2（2026-03-18）** | ✅ | Tracee/Corpus rerun。trampoline guard 是 corpus 回归根因，已 revert。报告：`docs/tmp/sequential_rerun_round2_20260318.md`。 |
| 207 | **Tracee revert rerun（2026-03-19）** | ✅ | exec_storm +4.40%，file_io +4.69%。旧权威保持。报告：`docs/tmp/tracee_revert_rerun_20260319.md`。 |
| 208 | **Corpus revert rerun（2026-03-19）** | ✅ | applied-only **1.023x**。瓶颈是 non-applied ultra-short 噪声。报告：`docs/tmp/corpus_improvement_analysis_20260319.md`。 |
| 209 | **Trampoline regeneration 调研（2026-03-19）** | ✅ | ~100 LOC 方案。已在 #248 实施。报告：`docs/tmp/trampoline_regeneration_research_20260319.md`。 |
| 210 | **Kernel deep review（2026-03-19）** | ✅ | 9 个问题，3 轮修复见 #212-#214。报告：`docs/tmp/kernel_deep_review_20260319.md`。 |
| 211 | **GitHub ARM64 KVM 调研（2026-03-19）** | ✅ | 无 KVM，ARM64 recompile 需租机。报告：`docs/tmp/github_arm64_kvm_research_20260319.md`。 |
| 212-214 | **Kernel fix Phase A/B/C（2026-03-19）** | ✅ | 3 轮 kernel 修复。报告：`docs/tmp/kernel_fix_phase_{a,b,c1,c2}_20260319.md`。 |
| 215-216 | **Kernel cleanup + review（2026-03-19）** | ✅ | tracepoints 删除、stock choice 消除。9.2/10。selftest 20/20。 |
| 217-220 | **Kernel DSL 删除 + 简化（2026-03-19）** | ✅ | DSL ~900 行删除，blob 简化，do_jit 短路恢复。报告：`docs/tmp/kernel_dsl_removal_20260319.md`。 |
| 221 | **用户态 dead code 清理（2026-03-19）** | ✅ | -47 文件 / -21000 行。报告：`docs/tmp/userspace_cleanup_20260319.md`。 |
| 222-223 | **Kernel review + 接口精简（2026-03-19）** | ✅ | 8.4/10。selftest 19/19。报告：`docs/tmp/kernel_final_review_20260319.md`。 |
| 224-225 | **Build 依赖修复（2026-03-19）** | ✅ | Makefile blob 依赖修复。报告：`docs/tmp/micro_exec_blob_fix_20260319.md`。 |
| 226 | **UAPI 同步 + 验证（2026-03-19）** | ✅ | vm-micro 62/62，applied-only **1.078x**。报告：`docs/tmp/full_validation_final_20260319.md`。 |
| 227 | **ARM64 交叉编译 + QEMU（2026-03-19）** | ✅ | make kernel-arm64 + vm-arm64-smoke 通过。报告：`docs/tmp/arm64_cross_compile_qemu_20260319.md`。 |
| 228 | **Param match dead code 确认（2026-03-19）** | ✅ | 无需改动。 |
| 229-230 | **Kernel 5k review + P0/P1/P2 fix（2026-03-19）** | ✅ | trampoline gate、param-only emitter、overlap 检测。selftest 19/19。报告：`docs/tmp/kernel_review_fixes_20260319.md`。 |
| 231 | **Docker ARM64 交叉编译（2026-03-19）** | ✅ | Dockerfile + Makefile targets。ARM64 kernel 缺 recompile override。 |
| 232 | **用户态 cleanup round 3（2026-03-19）** | ✅ | dead imports/locals 清理。 |
| 233-235 | **Kernel LOC 分析 + 架构 review + 简化（2026-03-19）** | ✅ | 净减 **-447 LOC**。报告：`docs/tmp/kernel_simplification_20260319.md`。 |
| 236 | **Micro rerun post-P0/P1/P2（2026-03-19）** | ✅ | rotate_dense 回归为旧 bzImage 问题，非代码 bug。报告：`docs/tmp/rotate_dense_regression_debug_20260319.md`。 |
| 237 | **Scaleway RISC-V 调研（2026-03-19）** | ✅ | custom kernel 需特殊处理。报告：`docs/tmp/riscv_cloudv_scaleway_research_20260319.md`。 |
| 238 | **LLVM vs kernel JIT 指令级对比（2026-03-19）** | ✅ | WIDE_MEM+ROTATE 是主因。8-form 未覆盖：load-width narrowing、store coalescing、regalloc。报告：`docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md`。 |
| 239 | **ARM64 JIT gap 分析（2026-03-19）** | ✅ | 4 form 值得移植（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）。报告：`docs/tmp/arm64_jit_gap_analysis_20260319.md`。 |
| 240 | **rotate_dense 回归 debug（2026-03-19）** | ✅ | 归入 #236。 |
| 241 | **Kernel 简化重启（2026-03-19）** | ✅ | 归入 #235。 |
| 242 | **Post-simplification review（2026-03-19）** | ✅ | 8/10。P1 masked ROTATE 见 #247。 |
| 243 | **ARM64 CI baseline（2026-03-19）** | ✅ | llvmbpf **0.590x**（54/62 wins）。报告：`docs/tmp/arm64_ci_first_run_20260319.md`。 |
| 244 | **权威 micro rerun（2026-03-19）** | ✅ | applied-only **1.152x**。报告：`docs/tmp/micro_authoritative_post_simplification_20260319.md`。 |
| 245 | **Corpus rerun（2026-03-19）** | ✅ | applied-only **1.062x**。报告：`docs/tmp/corpus_post_simplification_20260319.md`。 |
| 246 | **E2E rerun（待做）** | ⏳ 已被 #304 架构转向搁置 | |
| 247 | **ROTATE fix + cleanup（2026-03-19）** | ✅ | kernel-side 完成，scanner 待对齐（见 #268）。 |
| 248 | **Trampoline regeneration（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 249-251 | **ARM64 emitter 设计+实现（2026-03-19）** | ✅ | 4 form（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）+ arch callback 拆分。selftest 24/24（x86+ARM64）。报告：`docs/tmp/arm64_emitter_implementation_20260319.md`。 |
| 252 | **Selftest 扩展（2026-03-19）** | ✅ | +5 form，8/8 覆盖。selftest 24/24。 |
| 253 | **ARM64 CI corpus fix（2026-03-19）** | ✅ | io-mode 修复，覆盖率 52%。 |
| 254 | **Timing fix（2026-03-19）** | ✅ | llvmbpf 批量计时，ultra-short 修复。报告：`docs/tmp/timing_fix_20260319.md`。 |
| 255 | **Corpus llvmbpf 删除（2026-03-19）** | ✅ | 报告：`docs/tmp/corpus_llvmbpf_removal_20260319.md`。 |
| 256 | **权威 rerun（2026-03-20）** | ✅ | Micro **1.057x** / applied **1.193x**。Corpus applied **0.947x**。Tracee **+8.1%**。Tetragon **+20.3%/+32.2%**。Gap **0.581x**。报告：`docs/tmp/full_rerun_authoritative_20260320.md`。 |
| 257 | **Branch 合并（2026-03-19）** | ✅ | ARM64 CI 分支合并到 main。 |
| 258 | **Paired measurement（2026-03-19）** | ✅ | 归入 #262。 |
| 259 | **Framework review（2026-03-19）** | ✅ | micro applied-only 可靠；corpus overall 不可靠。报告：`docs/tmp/benchmark_framework_review_20260319.md`。 |
| 260 | **ARM64 micro eval（2026-03-19）** | ✅ | smoke 通过，性能负向（QEMU 噪声）。报告：`docs/tmp/arm64_micro_eval_20260319.md`。 |
| 261-262 | **Benchmark cleanup + same-image 改造（2026-03-19）** | ✅ | same-image paired measurement 落地。报告：`docs/tmp/same_image_measurement_20260319.md`。 |
| 263 | **Trampoline regen + ROTATE fix 合并（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 264-265 | **ARM64 emitter review + P0/P1 fix（2026-03-19）** | ✅ | subprog staging + EXTRACT width 校验。selftest 27/27。报告：`docs/tmp/arm64_p0p1_fix_20260319.md`。 |
| 266 | **AWS ARM64 benchmark（2026-03-19）** | ⚠️ 已被 #304 搁置 | t4g.micro smoke 通过。glibc ABI 残留。报告：`docs/tmp/aws_arm64_benchmark_run_20260320.md`。 |
| 267 | **Makefile 审计（2026-03-19）** | ✅ | defaults 统一 10/2/200。报告：`docs/tmp/makefile_benchmark_audit_20260319.md`。 |
| 268 | **Scanner ROTATE 对齐（2026-03-19）** | ✅ | scanner-tests 0 FAIL。报告：`docs/tmp/scanner_rotate_align_20260319.md`。 |
| 269 | **Validator/emitter boundary audit（2026-03-20）** | ✅ | “Validator=安全门，Emitter=信任”。selftest 27/27。报告：`docs/tmp/validator_emitter_boundary_audit_20260320.md`。 |
| 270 | **Katran harness fix（2026-03-20）** | ✅ | same-image paired，1.042x。报告：`docs/tmp/katran_harness_fix_20260320.md`。 |
| 271 | **Corpus 根因分析（2026-03-20）** | ✅ | applied-only 0.947x。报告：`docs/tmp/corpus_rootcause_20260320.md`。 |
| 272 | **Selftest 扩展（2026-03-20）** | ✅ | +9 tests，selftest **36/36**。报告：`docs/tmp/selftest_negative_boundary_20260320.md`。 |
| 273 | **Kernel quality audit（2026-03-20）** | ✅ | P0 buffer overflow + P1 alias bugs。见 #275 修复。报告：`docs/tmp/kernel_code_quality_audit_20260320.md`。 |
| 274 | **Benchmark framework refactor（2026-03-20）** | ✅ | runner/ 顶层提取，corpus 8→1 driver。报告：`docs/tmp/benchmark_framework_refactor_20260320.md`。 |
| 275 | **Kernel P0+P1 fix（2026-03-20）** | ✅ | BRANCH_FLIP/COND_SELECT/ADDR_CALC bugs。selftest 36/36。报告：`docs/tmp/kernel_p0p1_fix_20260320.md`。 |
| 276-278 | **ZERO_EXT_ELIDE 分析+删除（2026-03-20）** | ✅ | 内核 **-118 LOC**。selftest 35/35。报告：`docs/tmp/zero_ext_elide_deletion_20260320.md`。 |
| 277 | **Post-refactor cleanup（2026-03-20）** | ✅ | py_compile 无错误。 |
| 279 | **Cross-layer fix（2026-03-20）** | ✅ | 零跨层 import。报告：`docs/tmp/cross_layer_cleanup_20260320.md`。 |
| 280 | **Trampoline leak fix（2026-03-20）** | ✅ | Double synchronize_rcu。selftest 35/35。 |
| 281 | **ARM64 E2E smoke（2026-03-20）** | ✅ | Katran recompile 通过。Tetragon ❌。EC2 terminated。报告：`docs/tmp/arm64_e2e_smoke_20260320.md`。 |
| 282 | **Katran harness 升级（2026-03-20）** | ✅ | BPF **1.108-1.168x**。报告：`docs/tmp/katran_e2e_quality_analysis_20260320.md`。 |
| 283 | **ARM64 bpftool fix（2026-03-20）** | ✅ | kernel_btf fallback。Katran recompile 全通。报告：`docs/tmp/arm64_bpftool_fix_20260320.md`。 |
| 284 | **Kernel 精简（2026-03-20）** | ✅ | **-137 LOC**。selftest 35/35。报告：`docs/tmp/kernel_low_risk_simplification_20260320.md`。 |
| 285 | **用户态精简（2026-03-20）** | ✅ | **-32,329 行**。报告：`docs/tmp/userspace_consolidation_20260320.md`。 |
| 286 | **Framework 清理（2026-03-20）** | ✅ | 删除散乱目录/脚本。报告：`docs/tmp/framework_cleanup_audit_20260320.md`。 |
| 287-288 | **Kernel bloat review + emitter 成本（2026-03-20）** | ✅ | BRANCH_FLIP 反转不可行。per-form ~180-500 LOC。报告：`docs/tmp/kernel_bloat_review_20260320.md`。 |
| 289 | **表驱动 validator（2026-03-20）** | ✅ | 边际成本 ~500→~80-150 LOC。selftest 35/35。报告：`docs/tmp/form_cost_reduction_design_20260320.md`。 |
| 290 | **vm-micro 验证（2026-03-20）** | ✅ | 62/62 valid，applied-only **1.269x**。报告：`docs/tmp/vm_micro_validation_20260320.md`。 |
| 291 | **ROTATE/WIDE_MEM 表驱动（2026-03-20）** | ✅ | **-66 行**。selftest 35/35。报告：`docs/tmp/rotate_wide_table_driven_20260320.md`。 |
| 292 | **Katran endian bug（2026-03-20）** | ✅ | movbe store 副作用 bug。报告：`docs/tmp/katran_endian_store_bug_investigation_20260320.md`。 |
| 293 | **PGO policy 设计（2026-03-20）** | ✅ | live enumerate 是关键。报告：`docs/tmp/pgo_policy_design_20260320.md`。 |
| 294 | **Verifier 扩展调研（2026-03-20）** | ✅ | 方案 C 最划算（~50 行 liveness）。报告：`docs/tmp/verifier_extension_research_20260320.md`。 |
| 295-296 | **Katran site coverage（2026-03-20）** | ✅ | 74 sites（bflip=56, cmov=8, wide=4, endian=4, extract=2）。safe6 policy，BPF 1.042x。报告：`docs/tmp/katran_site_coverage_analysis_20260320.md`。 |
| 297/301 | **Tetragon 未 apply 调查（2026-03-20）** | ✅ | offline scan 看不到 live bflip sites。最多 5/7 可 apply。报告：`docs/tmp/tetragon_unapplied_investigation_20260320.md`。 |
| 298/300 | **ARM64 benchmark pipeline（2026-03-20）** | ⚠️ 已被 #304 搁置 | 改为 t4g.micro 交叉编译方案。 |
| 299 | **x86 新优化调研（2026-03-20）** | ✅ | Top-5 新机会。报告：`docs/tmp/x86_new_optimization_opportunities_20260320.md`。 |
| 302 | **E2E profiler（2026-03-20）** | 🔄 已被 #304 搁置 | PGO policy 设计。 |
| 303 | **目录整理（2026-03-20）** | ✅ | runner/docker, runner/scripts, docs/reference。报告：`docs/tmp/directory_reorganization_20260320.md`。 |
| 304 | **⚠️ 重大架构探索：BpfReJIT v2 — Verifier-guarded post-load transformation framework（2026-03-21）** | 🔄 | **架构方向讨论**，考虑从当前 native-level rewrite (~6400 LOC kernel) 转向通用 post-load program transformation 框架。核心思路：不在 native code 层做优化，改为在 BPF bytecode 层做重写 + 让 kernel verifier 验证；新优化通过 kernel module 部署；privileged daemon 自动发现/分析/重写 live BPF 程序，对应用完全透明。**最终收敛方案**见 #304a-#304d。**10 份 codex 调研报告**：(A) `kinsn_feasibility_research_20260320.md`、(B) `bpf_program_replacement_research_20260320.md`、(C) `verifier_acceptance_research_20260320.md`、(D) `architecture_comparison_osdi_20260320.md`、(E) `kinsn_minimal_implementation_20260321.md`、(F) `userspace_framework_design_research_20260321.md`、(G) `bpf_prog_rewrite_kernel_research_20260321.md`、(H) `transparent_replacement_feasibility_20260321.md`、(I) `inline_kfunc_feasibility_20260321.md`。 |
| 304a | **收敛方案：两套正交接口（2026-03-21）** | 📝 | **(接口 A) 程序变换 — GET + REJIT**：`BPF_PROG_GET_ORIGINAL` 拿原始 bytecode + `BPF_PROG_REJIT` 对同一 `struct bpf_prog` 做 bytecode patch → re-verify → re-JIT → image swap（复用现有 `jit_directives.c` staged commit/rollback/trampoline regen）。零 attach 变化、零运行时开销。**(接口 B) ISA 扩展 — Inline Kfunc**：新"指令"注册为 kfunc（复用 `register_btf_kfunc_id_set()` + 新 `KF_INLINE_EMIT` flag）；verifier 零改动（走已有 `check_kfunc_call()`）；interpreter 零改动（调真实内核函数）；JIT CALL case 检测 `KF_INLINE_EMIT` → 调 module 的 emit 回调内联展开为自定义 native 序列。优雅降级：module 未加载时 emit 普通 CALL。已有先例：`fixup_kfunc_call()` 中 `bpf_cast_to_kern_ctx`/`bpf_rdonly_cast` 等已被完全替换为 plain BPF 指令。**kernel 总改动估计 ~500-800 LOC**（GET_ORIGINAL ~70 + REJIT ~580 + Inline Kfunc ~150-200）。 |
| 304b | **关键发现汇总（2026-03-21）** | 📝 | **(1)** `struct bpf_prog` 不保留原始 bytecode — `insnsi` 被 verifier/fixup 原地改写，需在 load 时新增保存 pre-fixup baseline 到 `bpf_prog_aux`。**(2)** BPF opcode `BPF_ALU64` 的 `0xe0`/`0xf0` 是仅有干净空位，但 Inline Kfunc 不需要新 opcode。**(3)** xlated bytecode 不可逆（`convert_ctx_accesses()` + `do_misc_fixups()`），不能直接重新 PROG_LOAD。**(4)** 现有 `jit_directives.c` image swap 机制可复用。**(5)** re-verify 开销 ~ms 级（vs re-JIT ~30μs），但只发生一次。**(6)** Inline Kfunc 优于 kinsn — 零 verifier/interpreter 改动，复用 kfunc 注册/生命周期/BTF。**(7)** "interpreter 优雅降级"不成立 — kfunc 强制 JIT，降级是 "inline emit 失败 → fallback 普通 kfunc CALL"。**(8)** 常量参数编码（`RORX imm8`）需 v2 增强，v1 先做纯寄存器版。 |
| 304c | **论文定位（2026-03-21）** | 📝 | 与 K2/Merlin/EPSO **不同赛道**（runtime post-load vs compile-time pre-load）。类比：K2 = GCC -O3，我们 = JVM HotSpot。两者正交可叠加。**新定位**："Verifier-guarded, modular, post-load program transformation infrastructure for eBPF — 给 eBPF 加上类似 JVM 分层编译的能力，在 OS 内核级别，且安全模型更强（kernel verifier vs JVM bytecode verifier）"。同一框架支持四种用途：**(1)** 性能优化；**(2)** 安全加固；**(3)** 恶意程序在线热修复；**(4)** 运行时可观测。 |
| 304d | **Daemon 完整工作流（2026-03-21）** | 📝 | `BPF_PROG_GET_NEXT_ID` → `BPF_PROG_GET_ORIGINAL` → 用户态分析+重写（kinsn/kfunc 替换 or 安全加固 or PGO 决策）→ `BPF_PROG_REJIT`（kernel: patch orig bytecode → re-verify → re-JIT → image swap via RCU）。**完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach，零运行时开销。`freplace` 和 `bpf_link_update` 也可作为备选替换路径（freplace 有 ~3-5ns trampoline 开销，link_update 零开销但覆盖面有限）。 |
| 304e | **POC 实现（2026-03-21）** | 🔄 | **Phase 1 Inline Kfunc ✅**（kernel `a3173b119`）：KF_INLINE_EMIT flag + x86 JIT inline dispatch + test module `bpf_test_add42`。**Phase 2 GET_ORIGINAL ✅**（kernel `36e41e7a0`）：load 时保存原始 insns + `bpf_prog_info.orig_prog_insns` 导出。两个 phase 合计 **+200 行 kernel 核心改动**（+297 行 selftest）。**Phase 3 REJIT 🔄**：codex 实现中。Git：`rejit-v2` 分支（stock 7.0-rc2 baseline），v1 代码保存在 `v1-native-rewrite` 分支。 |
| 304f | **⚠️ REJIT 接口设计决策（2026-03-21）** | 📝 | **BPF_PROG_REJIT 接受完整的新 BPF bytecode，不是 patch。** daemon 提交整段新程序 `(prog_fd, new_insns, new_insn_cnt)` → kernel 对新 bytecode 做完整 `bpf_check()` + JIT → 原子替换同一 `struct bpf_prog` 的 image。理由：(1) daemon 有完全灵活性做任意变换；(2) kernel 走标准 verify 路径，零特殊 patch 逻辑；(3) map 引用在新 bytecode 中用 fd/BTF ID，kernel 正常 resolve。**不是 patch format** — 避免 kernel 内部 patch 应用+offset 调整的复杂度。 |
| 304g | **调研进行中（2026-03-21）** | 🔄 | (1) Verifier-fixup 耦合度分析（能否让 verifier 直接接受 xlated bytecode）→ `docs/tmp/verifier_fixup_coupling_analysis_20260321.md`。(2) 安全 use case 深度调研 → `docs/tmp/security_usecase_research_20260321.md`。(3) 用户态 v2 适配调研（scanner 改造/daemon 架构/benchmark 适配）→ `docs/tmp/userspace_v2_adaptation_research_20260321.md`。(4) 综合 related work → `docs/tmp/comprehensive_related_work_20260321.md` ✅。(5) 设计 gap 分析 → `docs/tmp/bpfrejit_v2_design_gaps_20260321.md` ✅。 |

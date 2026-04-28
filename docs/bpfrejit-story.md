# BpfReJIT Paper Story

> 本文档从 `kernel-jit-optimization-plan.md` 提取论文叙事相关内容，聚焦 principle、story 结构和证据链。
> 不含任务追踪、编辑规则等工程信息。

---

## 0. Abstract (from plan doc)

eBPF is widely adopted in production for observability, networking, and customizable kernel extensions in modern production systems, yet its current just-in-time (JIT) compilers remain rigid, platform-agnostic, and severely under-optimized compared to mature runtimes such as JVM, WASM, or LLVM. Many optimizations and security hardenings are restricted due to stringent kernel safety constraints and prohibitive implementation complexity. This paper presents BpfReJIT, a dynamic, minimally invasive, and extensible kernel compilation framework that transparently optimizes kernel-resident eBPF programs. Our key insight is a novel, microkernel-inspired separation of concerns that delegates kernel safety guarantees to minimal kernel extensions, allowing lightweight verification and in-place recompilation while offloading correctness and complex optimizations to an extensible userspace daemon informed by runtime profiling data. We implement BpfReJIT within the Linux kernel with fewer than 600 lines of code modifications, transparently supporting existing eBPF tools, loaders, and subsystems. Evaluation across diverse hardware platforms and representative workloads (network monitoring, security enforcement, and observability tracing) demonstrates that BpfReJIT achieves up to 40% performance improvement, 50% reduction in binary size, and negligible overhead. BpfReJIT provides a practical, upstream-compatible path toward dynamic, extensible compilation frameworks in operating system kernels.

---

## 1. 论文定位与策略 (from plan §1)

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
> - **内核组件**（最小化，~550 行代码（不含注释））：通过轻量级内核模块为每个平台定义**"什么能被优化"**——平台特定的指令定义，包含验证语义和 native 发射回调（**kinsn**）。这是**机制**。
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

1. **可扩展（Extensible）**：最小内核改动（~550 行代码（不含注释）），支持大量 pass。新优化 = 新 module + daemon 更新，零内核改动。
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
- **实现**：kinsn 复用已有的 kfunc 基础设施：新的 `KF_INLINE_EMIT` flag 使 JIT 调用 module 提供的 emit 回调，而不是生成普通函数调用。复用了 kfunc 已有的 verifier 验证、BTF 类型系统和 module 生命周期管理。
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
2. **Kernel 改动最小化**：核心内核接口只加一次（~550 LOC（不含注释）），新优化/新 arch 全部以 module + daemon 方式部署
3. **完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach
4. **零运行时开销**：变换后的程序和原始加载路径完全一样快
5. **Fail-safe**：verify 失败 → 什么都不改，返回错误；daemon 可随时回滚
6. **BPF_PROG_REJIT 接受完整的新 BPF bytecode**，不是 patch format — daemon 提交整段新程序，kernel 走标准 verify 路径
7. **Mandatory Falsification**：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，不是发布 userspace-guided interface
8. **Daemon 零 libbpf 依赖**：daemon 只通过 raw BPF syscall 与内核交互，不需要 libbpf。Rust 实现。
9. **Daemon 统一入口**：当前只保留 `serve` 常驻模式；优化、dry-run、批量操作都通过 Unix socket JSON 请求触发。

---

## 2. Characterization 证据摘要 (from plan §2)

| 证据 | 数值 |
|------|------|
| Exec time geomean (L/K) — **characterization gap** | **0.609x** (56 pure-JIT, strict 30×1000) |
| Code size geomean (L/K) | 0.496x |
| Byte-recompose 占 kernel surplus | 50.7%，2.24x 时间惩罚 |
| cmov 差距 | llvmbpf 31 vs kernel 0 |
| Prologue/epilogue 占 surplus | 18.5% |
| branch_layout 输入敏感性 | predictable 0.225x vs random 0.326x，差 44.6% |
| Real-program code-size | 0.618x geomean (36 unique) |
| Real-program exec-time | 0.514x geomean (14 unique) |
| Corpus directive coverage (5 fam) | 143/560 objects with sites, **14593** total sites |
| Corpus 8-family census | 157/560 corpus objects with sites, **16535** total sites |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 |
| cmov 消融 | switch_dispatch +26%，binary_search +12%；bounds_ladder -18%，large_mixed -24% |

---

## 3. 变换分类 (from plan §3)

### 3.1 性能优化变换

| 变换 | kinsn? | 状态 | 说明 |
|------|:---:|:---:|------|
| **WIDE_MEM** | 否 | ✅ | byte load+shift+or → 已有 BPF wide load 指令。占 kernel surplus 50.7% |
| **ROTATE** | 是 | ✅ | shift+or → `bpf_rotate64()` kinsn → JIT emit RORX |
| **COND_SELECT** | 是 | ✅ | branch+mov → `bpf_select64()` kinsn → JIT emit CMOV。policy-sensitive |
| **BITFIELD_EXTRACT** | 是 | ✅ | shift+and → `bpf_extract64()` kinsn → JIT emit BEXTR |
| **BRANCH_FLIP** | 否 | ✅ | if/else body 重排。policy-sensitive：依赖 PGO |
| **ENDIAN_FUSION** | 可选 | ✅ | load+bswap → combined kinsn → JIT emit MOVBE |
| **Dynamic map inlining** | 否 | 🔄 | JVM deopt 模型：map 稳定 → inline → invalidation → re-REJIT。**论文核心 story** |
| **Verifier const prop** | 否 | 🔄 设计完成 | `log_level=2` → tnum/range 常量 → `MOV imm` → branch folding |
| **DCE** | 否 | 🔄 设计完成 | const prop / map inline 后的 unreachable block / dead store 消除 |
| **Bounds check merge** | 否 | ✅ | guard window merge / hoisting |
| **128-bit LDP/STP** | 是 | ✅ 设计完成 | **ARM64**：相邻 load/store pair → LDP/STP kinsn |
| **Bulk memory kinsn** | 是 | ✅ | `rep movsb/stosb` (x86) / `LDP/STP` (ARM64) |
| **Helper call specialization** | 否/可选 | ✅ | `skb_load_bytes → direct packet access` |
| **Subprog inline** | 否 | ✅ 调研完成 | REJIT 元数据 blocker |
| **Tail-call specialization** | 否 | ✅ 调研完成 | dynamic-key PIC，kernel poke_tab blocker |

### 3.2 安全加固变换

| 变换 | 状态 | 说明 |
|------|:---:|------|
| **Spectre 缓解注入** | ✅ | SpeculationBarrierPass + bpf_barrier kinsn |
| **危险 helper 防火墙** | ✅ | 分级策略：P0 fail-closed，P1 coarseify，audit-only |
| **BPF 程序漏洞热修复** | ✅ | null-guard / helper 参数净化 / packet pointer refresh / tail-call isolation |
| **权限收紧** | ✅ 调研完成 | D⊇S⊇N⊇O 模型 |

---

## 4. 系统架构 (from plan §4)

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
│    Implementation: kinsn via KF_INLINE_EMIT                  │
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

### 4.4 kinsn 机制

**kinsn** 是 BpfReJIT 引入的平台特定指令扩展机制。kinsn IS-A kfunc，额外绑定 `bpf_kinsn_ops`，定义**执行语义**（JIT emit）和**验证语义**（verifier modeling）。

**核心设计**：module 同时定义 "emit 什么 native 指令" 和 "verifier 如何建模这条指令"。verifier 不需要 per-kinsn 特例代码。新增 kinsn = 新 module，零 verifier 改动。

---

## 5. 评估计划 (from plan §5)

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

### 5.3 Required Workloads

- **Mechanism isolation**：load_byte_recompose, binary_search, switch_dispatch, branch_layout
- **Policy-sensitivity**：cmov_select vs log2_fold
- **Real programs**：.bpf.o corpus（Cilium/Katran/loxilb/Calico/xdp-tools/selftests）
- **End-to-end deployment**：至少一个（Cilium/Katran 级别）

### 5.5 测量方法约定

- **exec_ns** 是跨 runtime 对比的正确主指标（双方都测纯 BPF 执行）
- **wall_exec_ns** 不可用于跨 runtime 对比（kernel 包含 syscall dispatch 开销）
- timing_source 追踪来源（kernel=ktime, llvmbpf=rdtsc）
- 显著性标签使用 BH-adjusted Wilcoxon，ratio CI 使用 unadjusted bootstrap
- ktime 分辨率 <100ns 的 benchmark 标记为 sub-resolution

---

## 6. 权威性能数据 (from plan doc header + task tracker)

### v1 数据（native-level rewrite 架构，~6000 LOC kernel，保存在 v1-native-rewrite 分支）

- micro **1.057x** / applied-only **1.193x**
- corpus **0.983x**
- Tracee **+8.1%**；Tetragon **+20.3%/+32.2%**；Katran BPF **1.108-1.168x**
- gap **0.581x**
- vm-selftest **35/35**

### v2 数据（BpfReJIT 架构，~550 LOC kernel + daemon）

- **Characterization gap**: llvmbpf vs kernel **0.609x**（56 pure-JIT, strict 30×1000）
- **Micro**: 62/62 valid, **53 applied**, 0 correctness mismatch, 1591 sites
- **Corpus**: 764 targets, 471 compile, 292 measured, **113 applied**; exec geomean **0.854x**（rejit 快 ~17%）
- **E2E Katran**: BPF **+8.8%**（speedup 0.919, app +1.4%, P99 -1.2%）
- **Recompile overhead**: daemon pipeline ~2-5ms + kernel REJIT syscall ~3-7ms
- **Map inlining coverage**: 11556 个 map_lookup site；Katran 22→2 条（-91%）；Tetragon 447→2（-99.6%）
- **Verifier acceptance**: static_verify 340/342 accepted (99.4%)
- **Safety tests**: 20/20 negative + 10000 fuzz + 23 adversarial
- **Kernel LOC**: 1437 代码行 + 162 注释行（vs stock 7.0-rc2）
- **Daemon tests**: 430 passed, 0 failed, 12 ignored

### 关键对比

| 维度 | v1 (kernel-internal) | v2 (BpfReJIT) |
|------|---------------------|---------------|
| 内核代码量 | ~6000 LOC | ~550 LOC（核心接口） |
| Upstream 可行性 | 无法 merge | 待验证（550 LOC 数量级合理） |
| Pass 数量 | ~5（固定） | 15+（可扩展，零内核改动） |
| 支持 runtime 数据 | 否 | 是（map inlining, PGO） |
| 安全用途 | 否 | 是（live patch, firewall） |
| Micro | 1.057x | 53/62 applied, 0 mismatch |
| Corpus | 0.983x | 0.854x (17% improvement) |
| E2E Katran | 1.108-1.168x | +8.8% |

---

## 7. 叙事分析与讨论笔记

> 以下是对论文 story 方向的讨论笔记，用于迭代 paper 写作。

### 7.1 当前 principle 讨论

**方向 C（信任成本）**：内核编译和用户态编译有本质的结构性差异。

用户态（JVM/V8/LLVM）的编译假设：
- 编译器有完整的源码/IR
- 编译器是可信的
- 编译后的代码直接执行
- Runtime 可以随时 deopt

内核（eBPF JIT）的编译面对完全不同的约束：
- 每一行优化代码都是审查负担
- JIT 运行在特权上下文，bug = kernel panic
- 没有 deoptimization 机制
- 加新优化 = 新的 kernel patch → 年级别的审查周期

这些约束导致一个结构性结果：**内核 JIT 永远是 under-optimized**。不是因为没人知道怎么优化，而是因为**在内核里做优化的成本结构是错的**——每增加一个优化 pass，审查/验证/维护成本远超收益。

**Principle 候选**：在安全关键系统（OS 内核）中，编译优化的瓶颈不是算法能力而是信任成本。唯一可持续的路径是把信任边界对齐到已有的安全机制（verifier），使优化代码不需要被信任。

**连接的更广泛问题**：在高信任成本环境中如何做 extensibility？

### 7.2 Insight 层次分析

当前三个 insight 是并列的，但深度不同：

- **Insight 1**（需要可扩展编译框架）：需求描述
- **Insight 2**（微内核启发的分离）：设计选择
- **Insight 3**（Safety ≠ Correctness）：最深层原理——verifier 将 safety 和 correctness 解耦

Insight 3 是 principle，Insight 1 和 2 是它的推论。

递进结构应为：
```
观察：内核 JIT 的优化瓶颈是信任成本，不是算法能力
     ↓
为什么 eBPF 可以打破这个局面：mandatory verifier 将 safety 和 correctness 解耦
     ↓
设计推论：优化 pass 不需要被内核信任 → 外置到用户态
     ↓
结果：可扩展的 post-load 编译框架，550 LOC 内核支撑 15+ pass
```

### 7.3 Abstract "key insight" 精确化方向

当前：
> Our key insight is a novel, microkernel-inspired separation of concerns...

精确化方向：
> Our key insight is that eBPF's mandatory verifier **decouples safety from correctness** for bytecode transformations: any submitted bytecode is machine-checked for safety independent of its provenance. This decoupling enables optimization passes that are **untrusted by the kernel**, **deployed without kernel code changes**, and **informed by runtime data** inaccessible to the static JIT — while the verifier provides the same safety guarantees as the original program load path.

### 7.4 §1.10 "Why Userspace" 归纳

9 条理由可归纳为两类：

**因为 safety/correctness 解耦（fundamental）：**
- 优化代码不需要被内核信任 → 不需要内核审查
- 可以快速迭代、A/B test、gradual rollout
- 新优化 = 新 daemon 代码，零内核改动

**因为 runtime 信息在用户态（practical）：**
- Map 值、branch profile、workload 特征只有 daemon 能观测
- 全局预算（I-cache cliff）需要跨程序视角
- Fleet 管理、per-deployment customization

### 7.5 信任边界对比

| 机制 | 信任模型 | 可外置优化？ |
|------|----------|:---:|
| Kernel module | 完全信任（GPL + code review） | 否 |
| Livepatch | 完全信任（patch 作者负责） | 否 |
| Seccomp BPF | 有 verifier，但表达力受限 | 有限 |
| **eBPF** | **Mandatory verify，任意 bytecode** | **是** |

### 7.6 Evaluation 围绕 principle 组织

| 问题 | 实验 | 数据状态 |
|------|------|:---:|
| 优化有效吗？ | corpus/micro/e2e | ✅ |
| 信任边界成立吗？ | safety negative + fuzz + correctness | ✅ |
| 信任成本翻转了吗？ | 550 LOC 支撑 15+ pass vs v1 6000 LOC | ✅ |
| Runtime 信息有增量价值吗？ | ablation: static-only vs +map_inline vs full | ⚠️ 需要跑 |
| Overhead 多大？ | re-verify 时间分解 | ⚠️ 需要整理 |
| 框架可泛化吗？ | 安全用途 + 多架构 | ✅ |
| Mandatory Falsification | fixed kernel peephole baseline 对比 (#494) | ⚠️ 待定 |

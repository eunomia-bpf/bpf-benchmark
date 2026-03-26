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
> - **⚠️ Makefile 是唯一构建/测试入口**：Agent 只能用 `make <target>` 构建和测试。禁止手动 `cargo build`、`make -C vendor/linux-framework`、`insmod`、`cp .config` 等。如果 make target 不够用，修 Makefile pipeline，不要绕过它。
> - **⚠️ 禁止 sudo**：VM 内已是 root（vng），主机不跑 BPF。不需要 sudo。
> - **⚠️ E2E 禁止 manual fallback**：E2E 测试必须用真实应用 binary 加载 BPF 程序，禁止手动加载 .bpf.o。如果应用不兼容当前 kernel，标记 SKIP 而不是 fallback。论文的 transparency 声明依赖此约束。
> - **⚠️ VM 测试每个 target 一个 agent**：vm-test、vm-micro、vm-corpus、vm-e2e 分别用不同 agent 串行跑。不要一个 agent 跑所有。
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
2. **Kernel 改动最小化**：核心内核接口只加一次（~550 LOC（不含注释）），新优化/新 arch 全部以 module + daemon 方式部署
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
| BpfReJIT micro improvement (recompile/stock) | **v2 (2026-03-23, post BTF+mapfd+pattern fixes)**: 62/62 valid, **49 applied**（wide_mem only，kinsn pass 待 verifier 改动后激活），0 correctness mismatch。Daemon **303 tests**。**关键发现**：rotate/cond_select pattern matcher 已修复（真实 bytecode 匹配），extract/endian caller-saved save/restore 已实现，但根本方案是 kinsn operand-encoded ALU 语义（见 #417）。v1 参考: blind 1.028x, fixed-policy 1.049x |
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

| 变换 | kinsn? | 状态 | 说明 | Corpus 证据（2026-03-24） |
|------|:---:|:---:|------|------|
| **WIDE_MEM** | 否 | ✅ 已实现 | byte load+shift+or → 已有 BPF wide load 指令。占 kernel surplus 50.7% | 49/62 micro applied |
| **ROTATE** | 是 | ✅ 已实现 | shift+or → `bpf_rotate64()` kinsn → JIT emit RORX | 701 sites, 15 applied |
| **COND_SELECT** | 是 | ✅ 已实现 | branch+mov → `bpf_select64()` kinsn → JIT emit CMOV。policy-sensitive | 12 corpus applied |
| **BITFIELD_EXTRACT** | 是 | ✅ 已实现 | shift+and → `bpf_extract64()` kinsn → JIT emit BEXTR | 524 sites, 4 applied |
| **BRANCH_FLIP** | 否 | ✅ 已实现 | if/else body 重排。policy-sensitive：依赖 PGO | PGO-only |
| **ENDIAN_FUSION** | 可选 | ✅ 已实现 | load+bswap → combined kinsn → JIT emit MOVBE | 256 sites, 17 corpus applied |
| **Dynamic map inlining** | 否 | ✅ serve/watch 接线完成 | JVM deopt 模型：map 稳定 → inline → invalidation → re-REJIT。**论文核心 story** | **11556 个 map_lookup site；Katran 22→2 条（-91%）；Tetragon 447→2（-99.6%）**。`MapInvalidationTracker` 已接入 `daemon/src/commands.rs` / `daemon/src/server.rs`；`MapInlinePass` 不再要求 frozen map，只要支持 direct value access 就允许 speculative inline。`serve` / `watch` 每秒轮询 invalidation，命中后自动重新 REJIT，必要时恢复原始 bytecode 并清理 tracking。设计：`dynamic_map_inlining_design_20260324.md` |
| **Verifier const prop** | 否 | 🔄 设计完成 | `log_level=2` → tnum/range 常量 → `MOV imm` → branch folding | **23% verifier state 含精确常量；62.5% 分支和立即数比较**。设计：`verifier_constprop_dce_design_20260324.md` |
| **DCE** | 否 | 🔄 设计完成 | const prop / map inline 后的 unreachable block / dead store 消除。specialization 乘数 | **kernel 已有 `opt_remove_dead_code()`，daemon DCE 让更多条件变常量**。和 #424 同一份设计 |
| **Bounds check merge** | 否 | ✅ 已实现 | ~~冗余 check 删除~~ → **guard window merge / hoisting**。合并小窗口为大窗口 | **42 guard sites，严格冗余=0%，但 83.3% 可合并（ladder 结构）**。实现：`BoundsCheckMergePass`。**测试**：`cargo test bounds_check` 14/14、`cargo test` 365 pass/12 ignored、`make daemon`、`make daemon-tests`。**commit**：`639926cb28e9`。调研：`bounds_check_elimination_research_20260324.md` |
| **128-bit LDP/STP** | 是 | ✅ module 已实现 | **ARM64**：相邻 load/store pair → `bpf_ldp128`/`bpf_stp128` kinsn → JIT emit LDP/STP，不碰 FPU。**x86**：pair load/store 用 `two mov` 即可（SSE/AVX 不值得——FPU context 开销远大于收益），bulk memcpy 走 `rep movsb`。**论文 story**：同一优化在不同架构有完全不同的 cost model（ARM64 免费 vs x86 需 FPU），体现 platform-aware kinsn 设计价值 | **ARM64 corpus store 对密度高，当前 JIT 完全没 LDP/STP**。设计：`arm64_ldp_stp_kinsn_design_20260326.md`、`x86_128bit_wide_loadstore_design_20260326.md`。调研：`128bit_wide_loadstore_research_20260324.md`。**module report**：`arm64_bpf_ldp_module_report_20260326.md`。**commit**：`d29d9b6427ab` |
| **Bulk memory kinsn** | 是 | ✅ x86 + ARM64 kinsn modules 已实现 | ~~SIMD~~ → v1 用 `rep movsb/stosb` (x86) / `LDP/STP` (ARM64)，不碰 FPU | **corpus 有 40B/74B/360B/464B 连续 copy/zero run**。设计：`simd_kinsn_design_20260324.md`、`x86_128bit_wide_loadstore_design_20260326.md`。**测试**：`cargo test ... bulk_memory` **16/16**、`cargo test ...` **395 pass / 12 ignored**、`make daemon-tests`。**daemon pass commit**：`958bab4528b2`。**module reports**：`x86_bpf_bulk_memory_module_report_20260326.md`、`arm64_bpf_bulk_memory_module_report_20260326.md`。**module commit**：`d29d9b6427ab`。 |
| **ADDR_CALC (LEA)** | 可选 | ❌ 低优先级 | mov+shift+add → `bpf_lea()` kinsn → JIT emit LEA | **corpus 仅 14 个严格命中 site（全部 tetragon），ROI 很低**。调研：`addr_calc_lea_research_20260324.md` |
| **Helper call specialization** | 否/可选 | 🔄 调研完成 | `skb_load_bytes → direct packet access` 优先（纯 bytecode）；`probe_read_kernel` 需 safe-load kinsn | **590 skb_load_bytes + 25296 probe_read_kernel site。结论：skb_load_bytes 最可行，probe_read 风险高**。调研：`helper_call_inlining_research_20260324.md` |
| **Frozen map inlining** | 否 | ❌ 不做 | BPF_MAP_FREEZE 后只读 map → 常量 MOV | **调研结论：真实 workload 无显式 freeze，hot-path lookup ≈ 0** |
| **Subprog inline** | 否 | ✅ 调研完成 | bytecode 层展开 subprogram call。**REJIT 元数据 blocker**：UAPI 不接受新 func_info/line_info | **834 调用点 / 67 对象(11.8%)；scx 占 63.7%（531 sites）；中位数 callee 40.5 insns；Phase 1 = leaf+单callsite+≤64insns；路径 C（kernel-side inline）工程风险最低**。调研：`subprog_inline_research_20260326.md` |
| **Const propagation** | 否 | ↗ 归入 #424 | 利用 frozen map / runtime invariants 做常量折叠 | 归入 verifier const prop |
| **SIMD (FPU)** | 是 | ❌ 不进 OSDI 主线 | **x86 SIMD 不做**：`kernel_fpu_begin/end` XSAVE/XRSTOR 开销 ~200-800 cycles，pair load/store 场景下远超收益；**ARM64 NEON 条件性 Phase 2**：仅 ≥1KiB + `may_use_simd()` 成立时考虑，no-FPU `LDP/STP` 优先。Linux crypto 模式（per-operation fpu_begin/end）不适用于 BPF 的细粒度调用 | **深度调研结论：x86 break-even ≥数百字节且需整次 BPF 调用摊销一次 FPU context；corpus 中绝大多数 copy/store ≤128B，不满足条件**。调研：`simd_fpu_kinsn_deep_research_20260326.md` |
| **Tail-call specialization** | 否 | ✅ 调研完成 | **Phase 1**：dynamic-key monomorphic PIC（guarded constant-key fast path），复用 kernel `map_poke_run()`。**Kernel blocker**：`poke_tab` shape check 需放宽 | **537 sites / 31 对象(5.46%)；Cilium 216、Tetragon 118、Tracee 49；upstream 已有 constant-key direct jump → 论文新意在 dynamic-key PIC；break-even 命中率 ~8%**。调研：`tail_call_specialization_research_20260326.md` |
| **Spill/fill 消除** | 否 | ❌ 不做 | 冗余 spill/fill 消除 | **内核已有 KF_FASTCALL，增量收益低** |

### 3.2 安全加固变换

| 变换 | 状态 | 说明 | Corpus 证据（2026-03-24） |
|------|:---:|------|------|
| **Spectre 缓解注入** | ✅ 已实现 | 在缺少 speculation barrier 的位置插入 lfence kinsn | SpeculationBarrierPass + bpf_barrier kinsn |
| **LFENCE/BPF_NOSPEC 消除** | ⏸ 降优先级 | daemon 重构 bytecode 使 speculative path 安全 → verifier 不再插 barrier | **corpus 861 程序实测 BPF_ST_NOSPEC = 0**。设计保留：`lfence_nospec_elimination_design_20260324.md` |
| **危险 helper 防火墙** | ✅ 已实现 | 分级策略：P0 `send_signal`/`send_signal_thread`/`override_return` fail-closed（`r0=-EPERM`）；P1 `ktime_get_ns` coarseify；`probe_read_kernel` audit-only | **91034 helper 调用 / 568 对象；严格危险集 26925 调用(29.6%) / 155 对象(27.3%)；权限提升类仅 10 次调用(send_signal 7 + override_return 3)；Tracee+KubeArmor 占 91.6%**。实现：`dangerous_helper_firewall_design_20260326.md` / `dangerous_helper_firewall_impl_report_20260326.md` |
| **BPF 程序漏洞热修复** | ✅ 已实现 | 不修 verifier，对已加载字节码做 null-guard / helper 参数净化 / packet pointer refresh / tail-call isolation，并要求补丁后重新过 verifier | **45+ verifier CVE 中 31 个(G1)适合热补丁，13 个高可行性（nullability/helper contract/packet pointer 刷新）；信任模型：补丁绕开缺陷 verifier 规则 + re-verify**。设计/实现/评审：`live_patch_pass_design_20260326.md` / `live_patch_impl_report_20260326.md` / `live_patch_review_report_20260326.md` |
| **权限收紧** | ✅ 调研完成 | D(部署声明)⊇S(静态包络)⊇N(可安全收紧)⊇O(观测 live)。BpfReJIT 补上 BPF token 只收紧"未来加载"的缺口 | **157 源文件中 0 个使用高风险 helper，但 systemd/Tracee/bcc 容器以 privileged/CAP_SYS_ADMIN 部署；过权在部署层面非字节码层面；不能仅凭 live 观测删除 helper**。调研：`privilege_narrowing_research_20260326.md` |

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

### 4.4 kinsn 机制

**kinsn** 是 BpfReJIT 引入的平台特定指令扩展机制。kinsn IS-A kfunc，额外绑定 `bpf_kinsn_ops`，定义**执行语义**（JIT emit）和**验证语义**（verifier modeling）。

**核心设计**：module 同时定义 "emit 什么 native 指令" 和 "verifier 如何建模这条指令"。verifier 不需要 per-kinsn 特例代码。新增 kinsn = 新 module，零 verifier 改动。

**`bpf_kinsn_ops`** 包含三类回调：`model_call`（返回声明式 `bpf_kinsn_effect`，含 clobber_mask/result range/tnum/mem_accesses）、`decode_call`/`validate_call`（编码解析和校验）、`emit_x86`/`emit_arm64`（JIT 发射）。

Packed（sidecar pseudo-insn + CALL pair，零 argument setup，N→1 指令替换）。

**安全模型**：module 提供声明式 effect，verifier core 负责应用（clobber/range/tnum/subreg_def/mem_access）。不暴露 `bpf_reg_state` 给 module。`KF_KINSN` flag 标记 kfunc 为 kinsn，与 KF_ACQUIRE/KF_RELEASE/KF_SLEEPABLE 互斥。

详细设计文档：`docs/tmp/20260323/kinsn_ops_design_20260323.md`。实现审计：`docs/tmp/20260323/kinsn_implementation_review_20260323.md`。

### 4.5 Kernel 文件布局（`vendor/linux-framework/` rejit-v2 分支）

| 文件 | 职责 | 组件 |
|------|------|------|
| `include/linux/bpf.h` | `bpf_kinsn_ops`/`bpf_kinsn_effect`/`bpf_kinsn_call` 结构体、注册 API、`bpf_tramp_user` | kinsn + syscall |
| `include/linux/bpf_verifier.h` | kinsn verifier 辅助结构体 | kinsn |
| `include/linux/btf.h` | `KF_KINSN` flag（替代 KF_INLINE_EMIT） | kinsn |
| `include/uapi/linux/bpf.h` | `BPF_PROG_REJIT` cmd、`orig_prog_insns`、`fd_array` | syscall |
| `kernel/bpf/syscall.c` | GET_ORIGINAL、REJIT 入口、swap、multi-subprog layout match | syscall |
| `kernel/bpf/verifier.c` | kinsn 注册/查找、model_call verifier 通用流程、sidecar decode、load 时保存原始 bytecode | kinsn + syscall |
| `kernel/bpf/trampoline.c` | REJIT 后 trampoline refresh（fentry/fexit/freplace） | syscall |
| `kernel/bpf/dispatcher.c` | REJIT 后 XDP dispatcher refresh | syscall |
| `kernel/bpf/core.c` | `bpf_tramp_user` 初始化 | syscall |
| `arch/x86/net/bpf_jit_comp.c` | JIT CALL case kinsn inline dispatch | kinsn |
| `arch/arm64/net/bpf_jit_comp.c` | ARM64 JIT kinsn inline dispatch | kinsn |
| `net/core/filter.c` | `bpf_prog_refresh_xdp()` wrapper | syscall |

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

详细设计文档见 `docs/tmp/20260320/benchmark-framework-design_20260320.md`。

---

## 6. Kernel 分支与开发环境

### 6.1 分支清单（`vendor/linux-framework`）

| 分支 | 用途 | 状态 |
|------|------|:---:|
| `master` | upstream 7.0-rc2 stock baseline | 基准 |
| `rejit-v2` | **主力**：v2 架构 — syscall (GET_ORIGINAL + REJIT) + Inline Kfunc (KF_INLINE_EMIT) + multi-subprog + trampoline/XDP refresh（~650 LOC kernel，VM 26/26 + safety 20/20 PASS） | ✅ |
| `jit-directive-v4` | 已被 v2 取代：v4 框架（BPF_PROG_JIT_RECOMPILE + 4 directives，稳定基线） | 已被 v2 取代 |
| `jit-directive-v5` | 已被 v2 取代：v5 声明式 pattern + canonical lowering（基于 v4） | 已被 v2 取代 |
| `jit-fixed-baselines` | 对照：CONFIG_BPF_JIT_FIXED_{ROTATE,WIDE_MEM,LEA,CMOV} | ✅ |
| `jit-directive-poc-v2` | 历史：POC v2 cmov_select 单 directive | 已被 v4 取代 |
| `jit-directive-poc` | 历史：POC v1 wide_load（方向错误）| 已弃用 |

### 6.2 Worktree 布局

- `vendor/linux` — 当前工作目录（可切换分支）
- `vendor/linux-framework` — `rejit-v2` 分支（v2 架构主力开发，永驻）
- `vendor/linux-baseline` — `master` worktree（stock 7.0-rc2，永驻）

> 注：`vendor/linux-framework` 原先跟踪 `jit-directive-v5`（已被 v2 取代），现切换为 `rejit-v2`。

### 6.3 开发环境

```
VM:        QEMU/KVM + virtme-ng
Kernel:    vendor/linux (v7.0-rc2) as submodule
JIT file:  arch/x86/net/bpf_jit_comp.c
Benchmark: micro/driver.py + micro_exec via BPF_PROG_TEST_RUN
Baseline:  host 6.15.11 + VM 7.0-rc2
CI:        GitHub Actions ARM64 + x86 (manual trigger)
VM 使用:   make -j$(nproc) bzImage && vng --run <worktree>/arch/x86/boot/bzImage --exec "..."
```

> v1 注：`jit-fixed-baselines` 分支仅用于 v1 对照实验，v2 不使用。

### 6.4 Root Makefile 一键命令速查

根目录 `Makefile` 提供一键构建+测试。所有 VM 目标自动依赖 bzImage。

#### 构建目标

| 命令 | 作用 |
|------|------|
| `make all` | 构建 micro_exec + BPF programs + daemon + kernel-tests |
| `make micro` | 只构建 micro_exec 和 BPF programs |
| `make daemon` | 只构建 bpfrejit-daemon CLI |
| `make kernel` | 编译 bzImage（vendor/linux-framework） |
| `make kernel-tests` | 编译 kernel self-tests (rejit_poc + rejit_safety_tests) |

#### 快速验证（无需 VM）

| 命令 | 作用 |
|------|------|
| `make smoke` | 构建 + 本地 llvmbpf smoke test (simple, 1 iter, 10 repeat) |
| `make daemon-tests` | 构建 + 运行 daemon unit tests (ctest) |
| `make check` | = `all` + `daemon-tests` + `smoke`（完整本地验证） |

#### VM 目标（需要 bzImage + vng）

| 命令 | 作用 |
|------|------|
| `make vm-selftest` | VM 中跑 kernel self-tests (rejit_poc + rejit_safety_tests) |
| `make vm-micro-smoke` | VM 中跑 micro smoke (simple + load_byte_recompose + cmov_dense, kernel + kernel-rejit) |
| `make vm-micro` | VM 中跑全量 micro suite (kernel + kernel-rejit, 默认 3iter/1warm/100rep) |
| `make vm-corpus` | 跑 corpus batch（单 VM batch，daemon serve 常驻，用 policy，默认 200 repeat） |
| `make vm-e2e` | 跑全部 E2E (tracee + tetragon + bpftrace + scx；`xdp_forwarding` 已退役) |
| `make vm-all` | = `vm-selftest` + `vm-micro` + `vm-corpus` + `vm-e2e`（完整 VM 验证） |
| `make validate` | = `check` + `vm-selftest` + `vm-micro-smoke`（最小 VM 验证） |

#### 可调参数

```bash
make vm-micro ITERATIONS=10 WARMUPS=2 REPEAT=500         # strict run
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
| 304g | **调研全部完成（2026-03-21）** | ✅ | **(1)** Verifier-fixup 耦合度 → **结论 4C**：xlated 不能直接喂 verifier，需保存原始 bytecode。`vendor/linux-framework/docs/tmp/20260321/verifier_fixup_coupling_analysis_20260321.md`。**(2)** 安全 use case → 推荐"危险 helper 防火墙 + exfil sinkholing"。`docs/tmp/20260321/security_usecase_research_20260321.md`。**(3)** 用户态适配 → scanner matcher 可复用，输出改为 full-program rewrite；新增 `run-rejit` 子命令。`docs/tmp/20260321/userspace_v2_adaptation_research_20260321.md`。**(4)** 综合 related work → `docs/tmp/20260321/comprehensive_related_work_20260321.md`。**(5)** 设计 gap → identity-preserving swap 是核心难点。`docs/tmp/20260321/bpfrejit_v2_design_gaps_20260321.md`。 |
| **305** | **内核 POC 修复（2026-03-21）** | ✅ | **内核代码 444 行**（vs stock 7.0-rc2），含 selftest 共 974 行。修复内容：(1) 去掉 14 项不必要防御检查；(2) UAPI 增加 `fd_array`/`fd_array_cnt` 支持 maps 和 module kfunc；(3) 去掉等长约束（只 swap JIT image，不拷贝 xlated insns）；(4) per-prog `rejit_mutex` 并发保护；(5) `attach_btf` 透传到 tmp；(6) swap 增加 `used_maps`/`kfunc_tab` 等字段；(7) sleepable 程序支持（`synchronize_rcu_tasks_trace`）。VM 测试通过：same-length PASS + different-length PASS（2→4 insns）+ inline_kfunc PASS。 |
| **306** | **Runner v1→v2 替换（2026-03-21）** | ✅ | **净删除 1,121 行**（-1320/+199）。8 文件改动，0 errors 0 warnings。删除全部 v1 scanner/policy/directive 代码。新增 `--rejit`/`--rejit-program`，runtime `kernel-rejit`。`recompile.py` 601→20 行。⚠️ 已知问题：same-bytecode 模式读 xlated insns 而非 orig_prog_insns，需后续修正（4C 结论）。 |
| **307** | **module/x86/ 真实 kinsn 模块（2026-03-21）** | ✅ | 创建 `module/x86/`：3 个模块编译通过零警告。`bpf_rotate.c`→ROL(9B)、`bpf_select.c`→CMOV(10B)、`bpf_extract.c`→BEXTR(12B)。每个含 kfunc fallback + KF_INLINE_EMIT + x86 emit 回调。 |
| **308** | **Bytecode rewriter 架构设计（2026-03-21）** | ✅ | 6 阶段 pipeline（Parse→Match→Decide→Emit→BranchFixup→Validate）。C++ 实现在 daemon/ 中，复用 70-80% 现有 matcher。变换：WIDE_MEM(N→1)、ROTATE(4→4 kfunc)、SELECT(3→7 kfunc)、EXTRACT(2→5 kfunc)。总估计 2.1-3.2k LoC。报告：`docs/tmp/20260321/rewriter_architecture_design_20260321.md`。 |
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
| **321** | **Daemon pass 框架设计（2026-03-21）** | ✅ | BpfPass/Analysis/AnalysisCache/PassManager 框架。线性 insn+annotation IR。6 分析 + 6 pass。渐进迁移路径。报告：`docs/tmp/20260321/daemon_pass_framework_design_20260321.md`。 |
| **322** | **Kernel code review by codex（2026-03-21）** | ✅ | 发现 3 Critical（旧 image UAF、attachment 缓存不同步、KERNEL_BPFPTR 伪装）+ 4 Major。报告：`docs/tmp/20260321/kernel_v2_review_20260321.md`。 |
| **323** | **ARM64 inline kfunc + kinsn 模块（2026-03-21）** | ✅ | 内核 `bpf.h` +emit_arm64（+12）、`arm64/bpf_jit_comp.c` +dispatch（+44）。`module/arm64/` 3 模块（ROR 4B、CSEL 8B、LSR+AND 20B）。交叉编译通过。+613 行。 |
| **324** | **e2e v2 daemon 集成（2026-03-21）** | ✅ | 5 case 全部接入 baseline→daemon apply-all→post_rejit 流程。净减 314 行。 |
| **325** | **Attachment sync 调研（2026-03-21）** | ✅ | TC/cgroup/kprobe 只缓存 `prog*`，WRITE_ONCE 够用。XDP dispatcher 不会 UAF（indirect fallback）。**Trampoline/freplace 是真 UAF**（硬编码地址）。报告：`docs/tmp/20260321/rejit_attachment_sync_research_20260321.md`。 |
| **325a** | **REJIT 安全性 VM 验证（2026-03-22）** | ✅ | **12/12 PASS，dmesg 干净。** XDP/TC/cgroup_skb REJIT + 正确性 + 运行中 REJIT + 并发 REJIT 全部通过。 |
| **325b** | **XDP/trampoline 修复设计（2026-03-22）** | ✅ | Phase 0: KERNEL_BPFPTR fix + 拒绝 live trampoline（~10 行）。Phase 1: XDP dispatcher refresh（~31 行）。Phase 2: trampoline refresh（~75 行）。报告：`docs/tmp/20260321/rejit_xdp_trampoline_fix_design_20260321.md`。 |
| **325c** | **内核 Phase 0-2 修复实现（2026-03-22）** | ✅ | +260 行 kernel（+459 行 selftest）。fd_array fix + XDP refresh + trampoline refresh + ARM64。**VM 6/6 PASS**（same-len + diff-len + fd_array + correctness + info + concurrent）。 |
| **326** | **Verifier log parser（2026-03-21）** | ✅ | `verifier_log.rs` 433 行，33 tests。 |
| **327** | **Daemon profiling（2026-03-21）** | ✅ | `profiler.rs` 249 行。bpf_stats polling。 |
| **328** | **Daemon pass 框架实现（2026-03-22）** | ✅ | pass.rs + analysis.rs + passes.rs。WideMemPass + RotatePass + SpectreMitigationPass。**104 tests all pass。** |
| **329** | kinsn pass（ROTATE/SELECT/EXTRACT） | 🔄 | RotatePass 在 #328 已实现。SELECT/EXTRACT 待做。 |
| **330** | 内核 Critical issue 修复 | ✅ 归入 #325c | Phase 0-2 全部完成。 |
| **331** | VM 全量 micro suite rejit | ✅ 归入 #338 | 见 #338。 |
| **332** | 全量评估：stock vs rejit vs llvmbpf | 待定 | 依赖 #331。 |
| **333** | **安全测试套件设计（2026-03-22）** | ✅ | 553 行设计文档。5 类测试：negative(20 case)/fuzz(100K+)/concurrent/privilege/differential。参考 Jitterbug/K2/BCF 方法论。报告：`docs/tmp/20260321/safety_eval_design_20260321.md`。 |
| **334** | func_cnt 限制 + e2e 兼容性 | ✅ 调研完成 | **结论**：swap 路径不完整（缺 `aux->func[]`/`func_cnt`/`real_func_cnt`/kallsyms）。**E2E 兼容**：Tracee 12/13、Tetragon 7/7、Katran **0/1**（blocker）、bpftrace 7/7。**最小修复方案 A'**：layout match + swap multi-subprog JIT package，~50-90 行。报告：`docs/tmp/20260322/func_cnt_and_e2e_compat_20260322.md`。 |
| **335** | perf/LBR 调研（2026-03-22） | ✅ | VM 无硬件 PMU（Arrow Lake 太新）。LBR 不可用。perf 软件采样可关联 BPF JIT 代码。bpf_stats 够用。 |
| **336** | func_cnt 修复实现（方案 A'） | ✅ VM 验证 | **+55/-3 行 syscall.c**。(1) 移除 func_cnt/real_func_cnt gate；(2) 新增 `bpf_prog_rejit_subprog_layout_match()` 校验 real_func_cnt + per-subprog len；(3) swap func/func_cnt/real_func_cnt/bpf_exception_cb/exception_boundary；(4) `bpf_prog_kallsyms_del_all()` + subprog re-publish。**VM rejit_poc 6/6 PASS + dmesg 干净。** Kernel `21c1b1f89`，主仓库 `31c1433`。 |
| **337** | 安全 negative test suite 实现 | ✅ VM 验证 | **919 行 `tests/rejit_safety_tests.c`，20 个测试**（15 negative + 5 correctness）。**VM 20/20 PASS + dmesg 干净。** 覆盖：非法 bytecode/OOB/infinite loop/illegal helper/oversized/invalid fd/non-privileged/失败后原程序不变/identity transform/NOP insertion/多次 REJIT/roundtrip。主仓库 `31c1433`。 |
| **338** | VM micro 冒烟（2026-03-22） | ✅ | 62 bench × 3 runtime。**正确性 62/62 全部通过**。性能数据非权威（低迭代+VM 噪声）。WIDE_MEM 改进可见（load_byte_recompose 0.68x, stride_load_4 0.60x）。 |
| **339** | **Kernel cleanup + gate 放宽 + st_ops（2026-03-22）** | ✅ bzImage #104 | **(1)** Code review 净减 101 行（死代码/过度注释/防御性编程）。**(2)** 删除 layout match check，允许 REJIT 改变 subprog 长度。**(3)** 放宽 dst_trampoline/dst_prog gate（零额外代码）。**(4)** 实现 st_ops text_poke refresh（+85 行，3 文件）。**当前 ~608 LOC 纯代码，tail_call 已在 #343 解决。** 报告：`docs/tmp/20260322/kernel_cleanup_arch_review_20260322.md`、`docs/tmp/20260322/st_ops_rejit_research_20260322.md`。 |
| **340** | **Daemon 升级（2026-03-22）** | ✅ 已被 #344 取代 | CondSelectPass + BranchFlipPass + rewriter fixes + watch mode。后续在 #344 做了完整重构。 |
| **341** | **Benchmark 框架升级（2026-03-22）** | ✅ | **(1)** driver.py 自动正确性验证（kernel vs kernel-rejit result 比较）。**(2)** corpus v2 对齐（`--daemon-path` + `kernel-rejit` + YAML）。**(3)** Makefile 修复（dispatcher.c 加入 KERNEL_JIT_SOURCES）。 |
| **342** | **prog_type 覆盖测试（2026-03-22）** | ✅ VM 21/21 | `tests/unittest/rejit_prog_types.c`。.bpf.c + libbpf，覆盖 XDP/TC/socket/cgroup/kprobe/tracepoint/raw_tp/perf/fentry/fexit/freplace/LSM/struct_ops。含 kernel EXT REJIT fix。 |
| **343** | **tail_call REJIT（2026-03-22）** | ✅ VM 2/2 | `tests/unittest/rejit_tail_call.c`。caller poke 更新 + target 两阶段 NOP/JMP。deadlock fix `f4be5f31b`。**BpfReJIT 零 prog_type 限制。** |
| **344** | **Daemon 完整重构（2026-03-22）** | ✅ 111 tests | 删 matcher/emit/rewriter（-1622 行）→ passes/wide_mem。main.rs 走 PassManager。passes/ + analysis/ 拆模块。verifier_log 恢复。6,425 行 / 17 文件。 |
| **345** | **kfunc 发现 + VM module loading（2026-03-22）** | ✅ 119 tests | `kfunc_discovery.rs`（~130 行）：BTF parser + 扫描 `/sys/kernel/btf/` + KfuncRegistry 填充。Makefile 自动 insmod kinsn modules。Commits: `1c281ea` + `7f5d70a`。 |
| **346** | **全量测试 + kernel bug fixes（2026-03-22）** | ✅ | **micro 62/62 完成，0 correctness mismatch，47 applied，geomean 0.887x（11.3% 加速）。** 发现并修复 4 个 kernel bug：**(1)** text_mutex 竞争（删 bpf_arch_text_invalidate）**(2)** kallsyms latch_tree 双重注册 **(3)** synchronize_rcu→expedited **(4)** XDP test_run 慢 sync。Kernel `b4bd737`，主仓库 `92d717c`。 |
| **347** | **upstream BPF selftest（2026-03-22）** | ✅ | test_verifier **526 PASS / 1 FAIL**（CONFIG_IPV6 相关，非 REJIT 回归）。test_progs verifier+jit: 109 PASS。新增 `make vm-upstream-test-verifier` target。 |
| **348** | **kernel bug fix 审查 + 回归测试（2026-03-22）** | ✅ | 4 个 fix 全部正确。5 个回归测试 PASS（并发 REJIT 40/40 + latency 27μs + rapid kallsyms 20/20 + XDP test_run + 压力测试 78779 REJITs）。`tests/unittest/rejit_regression.c`。 |
| **349** | **kernel 全面审计 + 修复（2026-03-22）** | ✅ | 发现 3 HIGH + 6 MED。修复：**(H1)** kfd_array 内存泄漏 **(H2)** EXT func_info 泄漏 **(H3)** struct_ops multi-slot **(M1)** expedited 范围限制 **(M4)** insns/len swap **(M6)** UAPI flags 字段。Kernel `8a6923893`。报告：`docs/tmp/20260322/kernel_full_audit_20260322.md`。 |
| **350** | **kinsn module 重编（2026-03-22）** | ✅ | vermagic 不匹配修复。3/3 modules 加载成功。`/sys/kernel/btf/bpf_rotate` 等 BTF 确认。 |
| **351** | **micro v2 with kinsn（2026-03-22）** | ✅ | 62/62 完成。**RotatePass 生效**（412 sites / 5 benchmarks）。但只 7/62 applied — **PassManager 路径和旧 matcher 覆盖率差异调查中**。Bias-adjusted applied geomean 0.967x。rotate64_hash **20.4% 真实加速**。报告：`docs/tmp/20260322/micro_analysis_v2_20260322.md`。 |
| **352** | **corpus compile_only→attach_trigger（2026-03-22）** | ✅ 代码完成 | 4 个目标改为 attach_trigger + bpf_stats timing。新增 `runner/libs/attach.py`。**VM 验证中。** |
| **353** | **applied 数下降调查（2026-03-22）** | ✅ | **Root cause**: WideMemPass emitter 只支持 width 2/4/8，width=3/5/6/7 导致 cmd_apply crash。修复：skip 不支持的 width。49/62 有 wide_mem sites，预期恢复 ~47 applied。121 tests。 |
| **354** | **e2e 准备（2026-03-22）** | ✅ | 5/5 case 可跑。Katran 不用 tail_call（是 func_cnt 问题，已修）。dev 数据：Katran 1.108x、Tracee +8.1%、Tetragon BPF -10.5%。**v2 e2e 尚未跑**（等全部 pass 修复后统一跑）。 |
| **355** | **全部 5 pass 真正 apply（2026-03-22）** | ✅ | CondSelectPass emit 实现（commit `25c73f4`）、BranchFlipPass heuristic（`ed36a35`）、SpectreMitigation 测试（`1eb150d`）。后续在 #362 做了算法正确性修复。 |
| **356** | **SpectreMitigation 专门测试（2026-03-22）** | ✅ | 18 daemon unit tests + 7 VM integration tests（`tests/unittest/rejit_spectre.c`）+ `--passes` CLI flag。Commit `1eb150d`。⚠️ JA+0 是 placeholder 不是真 barrier，真 barrier 需要 kinsn（future）。 |
| **357** | **bpftrace 复杂 tools（2026-03-22）** | ✅ | 6 个 upstream tools（tcplife/biosnoop/runqlat/tcpretrans/capable/vfsstat）替换 5 个简单脚本。Commit `6933ee3`。 |
| **358** | **v2 全量评估（2026-03-22）** | 🔄 | micro ✅（62/62, 49 applied, geomean **1.153x**, applied-only **1.096x**, 0 mismatch）。corpus 🔄（94/148 measured, applied=0 — 旧 binary 问题，rebuild 后待重跑）。e2e 🔄 正在跑。 |
| **359** | Recompile overhead 测量 | 待做 | REJIT verify+JIT+swap 各多久？reviewer 必问。 |
| **360** | Policy sensitivity 输入变体 | 待做 | 启用 predictable/random 变体到 YAML，支撑 Insight 2。 |
| **361** | VM bias 调查 | 待做 | control 有 7.8% phantom speedup，需要理解和消除。 |
| **362** | **Daemon P0 算法修复（2026-03-22）** | ✅ | **(1)** branch_flip: 修正 CFG diamond 识别（then_len=off-1），删 heuristic 改为 PGO-only，修正 flip offset。**(2)** cond_select: 删 Pattern B（两路径都得到 true_val 的误编译），实现 swap-safe emit_safe_params()，删 predictability_threshold。**(3)** rotate: 加 find_provenance_mov()（回扫 8 条找 MOV tmp,dst），加 live-out 检查。**(4)** liveness: call defs 改为 {r0-r5}。**147 tests pass。** Commit `ae76f1b`。 |
| **363** | **Daemon P1 集成修复（2026-03-22）** | ✅ | **(1)** BTF kind: 19 个常量对齐 kernel header + sync test + mixed-kind test。**(2)** fd_array: BpfProgram.required_module_fds + rotate/cond_select 记录 module FD + cmd_apply 传给 bpf_prog_rejit。**(3)** PGO: 删 analysis/pgo.rs 死代码。**(4)** Dead code: build_full_pipeline 删除，cargo check zero warnings。Commit `0c650f0`。 |
| **364** | **Daemon serve 子命令（2026-03-22）** | ✅ | Unix socket server mode。JSON newline-delimited 协议（optimize/optimize-all/status）。SIGTERM/SIGINT graceful shutdown。serde + serde_json 依赖。Commit `4df4922`。 |
| **365** | **Tests 目录重组（2026-03-22）** | ✅ | 删 40+ debug scripts。4 层结构：kernel/ + unittest/ + integration/ + python/ + helpers/。unittest/Makefile 统一构建 6 个 rejit_*.c。根 Makefile 加 unittest-tests + python-tests targets。Commit `a68a79a`。 |
| **366** | **Kernel bug 回归测试（2026-03-22）** | ✅ VM 9/9 | `tests/unittest/rejit_audit_tests.c`：T1-T6 kfd_array leak stress、T2-T3-T8 insns/len swap（含 2→4→6→4→2 cycle）、T4-T5 UAPI flags、T7 func_info stress、**T9 struct_ops multi-slot**（tcp_congestion_ops 4-slot trampoline patch）。Commit `ca5aa66`。 |
| **367** | **docs/tmp 按日期归档（2026-03-22）** | ✅ | 创建 6 个日期子目录（20260313-20260322），~250 个文件归档。plan doc + old record 82 个路径引用更新。Commits `94c3ce2` + `3373251`。 |
| **368** | **Corpus measured_pairs 修复（2026-03-22）** | ✅ | vng --cwd→--rwdir、kinsn auto-load、v1→v2 runner command 迁移。measured_pairs 0→94。Commit `7a5009e`。 |
| **369** | **Daemon code review by codex（2026-03-22）** | ✅ | 发现 3 CRITICAL + 8 HIGH。branch_flip CFG 错误、cond_select Pattern B 误编译、spectre JA+0 假 barrier、寄存器别名、rotate provenance、BTF kind 错误、fd_array 未打通、PGO 两套死代码。全部在 #362-#363 修复。报告：`docs/tmp/20260322/daemon_code_review_20260322.md`。 |
| **370** | **vm-micro-smoke 全覆盖（2026-03-22）** | ✅ | smoke 从 3 个 benchmark 改为全部 62 个（ITER=1, WARM=0, REP=50）。加 daemon-path 依赖。 |
| **371** | Corpus 54 unmeasured 程序 | 🔄 | 152 targets 中 54 个无 exec 数据（stock phase missing）。opus 正在诊断+配 attach_trigger。 |
| **372** | Makefile vm-selftest 接入 unittest | 🔄 | unittest/ 6 个测试文件需接入 vm-selftest。opus 正在做。 |
| **373** | kinsn module 重编（2026-03-22） | ✅ | 3/3 x86 modules against kernel 7.0-rc2+rejit-v2。Commit `9e6eb3d`。 |
| **374** | **Daemon post-fix review（2026-03-22）** | ✅ | Codex review 发现 5/11 修复完整、3/11 部分修复、3/11 未修复 + 1 新问题。报告：`docs/tmp/20260322/daemon_postfix_review_20260322.md`。 |
| **375** | **Daemon 7 issues 全修复（2026-03-22）** | ✅ | **(1)** cond_select parallel-copy 算法（27 组合穷举测试）。**(2)** rotate dst 改写检查。**(3)** fd_array per-kfunc module_fd（HashMap）。**(4)** spectre→barrier_placeholder + Placeholder category。**(5)** InsnAnnotation remap（addr_map 重映射）。**(6)** PGO 闭环（ProfilingData→annotations→branch_flip）。**(7)** ExtractPass 已存在确认。**187 tests pass**（+17 new）。 |
| **376** | 缺失 pass 站点覆盖分析（2026-03-22） | ✅ | ENDIAN_FUSION 1386 sites（最高）、BITFIELD_EXTRACT 542 sites、ADDR_CALC 较少。ENDIAN 需新 kinsn module + daemon pass。 |
| **377** | **ExtractPass 验证+增强（2026-03-22）** | ✅ | pattern 正确（RSH+AND→bpf_extract64 kfunc）。+9 new edge case tests（width=1/32, shift=0, consecutive, non-matching masks）。**196 tests pass**，zero warnings。 |
| **378** | E2E katran veth 修复 + 全量跑 | ✅ 归入 #404 | VM 缺 veth 模块导致 katran 失败。opus 修复中（modprobe veth）。 |
| **379** | **全项目架构审查 + 论文差距分析（2026-03-22）** | ✅ | Codex 全面 review：死代码、设计缺陷、组织问题、论文差距。报告→`docs/tmp/20260322/full_project_review_20260322.md`。 |
| **380** | **ENDIAN_FUSION 实现（2026-03-22）** | ✅ | x86 bpf_endian.c（MOVBE 3 variants）+ arm64 bpf_endian.c（LDR+REV）+ daemon EndianFusionPass（LDX_MEM+ENDIAN_TO_BE→kfunc）。+22 tests。**218 tests pass**。 |
| **381** | **Module UB + cross-arch 修复（2026-03-22）** | ✅ | **(1)** extract len=64 UB fix。**(2)** rotate shift=0 UB fix。**(3)** ARM64 ROL/ROR 统一（NEG+AND+RORV 实现左旋）。**(4)** 全部 module 改 BPF_PROG_TYPE_UNSPEC（不限 XDP）。**(5)** build artifact gitignore。 |
| **382** | **真实 Spectre barrier（2026-03-22）** | ✅ | x86 bpf_barrier.c（LFENCE 3B）+ arm64 bpf_barrier.c（DSB SY+ISB 8B）。daemon SpeculationBarrierPass 替换 JA+0 placeholder。kfunc 不可用时 pass 不做任何事。**224 tests pass**。 |
| **383** | **kinsn common header + module 简化（2026-03-22）** | ✅ | `module/include/kinsn_common.h`：DEFINE_KINSN_MODULE/DEFINE_KINSN_MODULE_MULTI 宏。10 个 module 文件全部简化（~300 行减少）。BPF_PROG_TYPE_UNSPEC 默认全 prog type。module/.gitignore 清理 artifact。 |
| **406** | Transform trace 可观测性设计 | 🔄 | daemon optimize 返回 per-site transform log（PC、原始指令、替换指令、insn delta）。runner 写入 JSON。codex 调研中。 |
| **405** | Micro 回归分析（bounds_check_heavy/rotate64_hash） | 待做 | 两个 applied benchmark 0.87-0.88x 回归。需要 per-pass ablation 定位。依赖 #406 可观测性。 |
| **404** | E2E 3 bug 修复 + 重跑 | ✅ | persist_results 签名 + scx bpftool + katran CONFIG_NET_IPIP。vm-e2e 重跑中。 |
| **403** | Corpus applied=2 调查+修复 | 🔄 | 152 measured 但只 2 applied。opus 调查中。 |
| **402** | CPU freq scaling bias 修复（2026-03-22） | ✅ | daemon socket idle gap 导致 CPU 降频。修复：daemon 调用移到测量前。geomean 0.654→1.059x。 |
| **401** | Split BTF name_off 修复（2026-03-22） | ✅ | module BTF 用 split BTF，name_off 需减 vmlinux str_len。修复后 7/7 kfuncs 发现成功。241 tests。 |
| **400** | Verifier log buffer ENOSPC 修复（2026-03-22） | ✅ | log_level=2 + 64KB buffer 对大程序溢出→ENOSPC→误判 verifier 拒绝。改为快速路径 log_level=0，失败时 16MB。 |
| **399** | v1 policy 文件系统清理（2026-03-22） | ✅ | 删 runner/libs/policy.py (553行) + corpus/policies/ (582文件) + micro/policies/ (~40文件) + CLI 参数 + generate_default_policies.py + auto_tune.py。corpus rejit 改为 daemon_socket 触发。 |
| **398** | **Verifier differential correctness verification 调研（2026-03-22）** | 📝 | 结论：**可行，但只能做 heuristic differential checking，不是 sound correctness proof。** 三方案里 **B（每 pass 前后 temp `BPF_PROG_LOAD` + `log_level=2` 对比）最佳**；A 太晚，C 工程量过大。对 `wide_mem` 信号最强；`rotate/cond_select` 很弱；`branch_flip` false positive 最高。**最可信路线 = verifier-diff guardrail + 本地 peephole translation validation（SMT/bitvector）**。完整报告：`docs/tmp/20260322/verifier_differential_verification_research_20260322.md`。 |
| **397** | **Verifier-guided transform rollback（2026-03-22）** | ✅ | TransformAttribution + extract_failure_pc + rollback loop + --no-rollback flag。**240 tests pass**。 |
| **396** | **Fuzz + adversarial negative tests（2026-03-22）** | ✅ | tests/negative/: fuzz_rejit.c (10000轮) + adversarial_rejit.c (23 tests + 3 differential)。vm-negative-test target。 |
| **395** | **Corpus 54 unmeasured 完整实现（2026-03-22）** | ✅ | 8 新 attach 类型 + 22 新程序。measured_pairs 91→152。 | 需要：新 attach 类型实现（kprobe/tracepoint/cgroup_sock_addr 等）+ 触发机制 + bpf_stats 测量 + YAML 配置。不只是改 config。 |
| **394** | deprecated CLI 清理（2026-03-22） | ✅ | 删 --daemon-path（3处）、recompile_v5→blind_apply、recompile_v4 死分支、重复 --bpftool 合并。 |
| **393** | **sudo 全量清理（2026-03-22）** | ✅ | 29 文件，删除所有 sudo（除 AWS 脚本）。VM 内已是 root。 |
| **392** | **kernel 修改总结（2026-03-22）** | ✅ | 22 文件，净增 ~1300 行。5 组件：GET_ORIGINAL + REJIT + kinsn + 传播 + bug fix。 |
| **391** | **5 dead code 接线（2026-03-22）** | ✅ | **(1)** verifier_log→bpf_prog_rejit（64KB log buffer + 结构化解析）。**(2)** HotnessRanking→watch（热度排序优先优化）。**(3)** PlatformCapabilities→PassContext（/proc/cpuinfo 检测 BMI1/CMOV/MOVBE/RORX，pass 开头检查）。**(4)** all_module_fds→cmd_apply（required⊆all 验证）。**(5)** AnalysisCache invalidate→PassManager（pass 修改后精确失效）。**229 tests pass**。 |
| **390** | **Makefile 大重构（2026-03-22）** | ✅ | 759→335 行（56% 减少）。vm-test 合并 4 个 target。vm-e2e 收敛为 `e2e/run.py all`。inline shell 抽到 4 个脚本。删 verify-build/compare/kernel-perf 死 target。 |
| **389** | **Makefile 全自动 pipeline（2026-03-22）** | ✅ | kernel 自动 defconfig + modules_prepare。kinsn-modules 加入所有 vm-* 依赖链。corpus load_all.sh（5/5 modules）。删 e2e/run.py --vm 死代码（~160 行）。删 KINSN_MODULES 死变量。 |
| **388** | **Daemon serve 接入 benchmark pipeline（2026-03-22）** | ✅ | kernel_runner.cpp: Unix socket client（daemon_socket_optimize）。micro/driver.py + corpus/driver.py: --daemon-socket 参数。Makefile vm-micro: 自动启动 daemon serve → socket 通信 → trap kill。fork/exec fallback 保留。 |
| **387** | **5 infra 架构修复（2026-03-22）** | ✅ | **(1)** module/load_all.sh 统一 kinsn 加载。**(2)** kernel target 改 file-based 避免重编。**(3)** VM_INIT 宏统一 venv+module 加载，所有 vm-* target 使用。**(4)** daemon path 统一到 daemon/target/release/。**(5)** PYTHON 变量统一 venv python3。make smoke 验证通过。 |
| **386** | **scanner→daemon 全量清理 + 死代码删除（2026-03-22）** | ✅ | 25 文件 scanner→daemon 命名统一。删除 build_scanner_command/parse_scanner_v5_output/REMOVED_SUBCOMMAND_HINTS/input_generators.py shim。全部 import 验证通过。 |
| **385** | **e2e case_common 提取 + gitignore（2026-03-22）** | ✅ | 新建 `e2e/case_common.py`：git_sha/host_metadata/summarize_numbers/percent_delta/percentile/speedup_ratio/ensure_*/persist_results。5 个 case 文件去重。4 个新 .gitignore（module/x86, module/arm64, tests/kernel, tests/unittest）。 |
| **384** | **PGO 闭环实现（2026-03-22）** | ✅ | **(1)** profiler.rs: PgoAnalysis.is_hot()/hotness_score() + HotnessRanking + collect_program_profiling()。**(2)** pass.rs: ProfilingData.program_hotness + 删 #[allow(dead_code)]。**(3)** main.rs: --pgo/--pgo-interval-ms CLI + PgoConfig + collect_pgo_data() 接线到 apply/apply-all/watch/serve。**(4)** 完整数据流：profiler→ProfilingData→inject_profiling→BranchFlipPass。**224 tests pass**。 |
| **407** | **Transform trace observability P0+P1（2026-03-23）** | ✅ | daemon `try_apply_one()` → 结构化 `OptimizeOneResult`（per-pass detail + rollback attempts + timings）。runner 结构化 JSON 解析 + `daemon_response` 嵌入。Python `rejit` 为 canonical，`recompile` 兼容。**246 tests + smoke pass**。 |
| **408** | **kinsn BTF 常量修复（2026-03-23）** | ✅ | **Root cause**: `BPF_BTF_GET_NEXT_ID` 常量 22→23（应为 23，22 是 BPF_MAP_FREEZE）。修复后 7/7 kfuncs 发现成功。同时显式添加 `CONFIG_DEBUG_INFO_BTF_MODULES=y` 到 defconfig。 |
| **409** | **Map fd bit extraction 修复（2026-03-23）** | ✅ | **Root cause**: `relocate_map_fds()` 中 `regs & 0x0f`（提取 dst_reg）应为 `(regs >> 4) & 0x0f`（提取 src_reg）。导致 corpus 60/152 程序 REJIT 失败（EINVAL/EBADF）。**256 tests + smoke pass**。 |
| **410** | **PMU counters 接入 profiler（2026-03-23）** | ✅ | profiler.rs 用 `perf_event_open` 采集 `BRANCH_MISSES`/`BRANCH_INSTRUCTIONS`。ProfilingData + BpfProgram 增加 `branch_miss_rate: Option<f64>`。Graceful fallback（PMU 不可用时 None）。**251 tests**。 |
| **411** | **BranchFlip fallback + PGO warmup（2026-03-23）** | ✅ | **(1)** BranchFlipPass: `branch_miss_rate=None` → skip（"no PMU data"）。**(2)** micro/driver.py: `--pgo-warmup-repeat`（默认 10），optimize 前先跑 warmup。**(3)** corpus/modes.py: daemon serve 加 `--pgo`。**(4)** Makefile vm-micro: daemon serve 加 `--pgo`。**265 tests + smoke pass**。 |
| **412** | **死代码/过时测试/脚本清理（2026-03-23）** | ✅ | 删 test_policy_utils.py + test_profile_guided_policy.py + profile_guided_policy.py。修 ARM64/AWS 脚本（daemon/build→target/release，删 policy 引用）。更新 corpus/e2e 旧路径。**256 tests**。 |
| **413** | **Daemon 测试缺口补充（2026-03-23）** | ✅ | +19 tests（含 `test_bpf_cmd_constants_match_kernel_header` — 解析 kernel header 验证 BPF cmd 常量，能直接抓住 22→23 bug）。`AttrRejit._pad` 修复（128-44→128-48）。struct layout + BTF 真实环境集成测试（`#[ignore]`）。**265 tests, 10 ignored**。 |
| **414** | **Mock test 审计报告（2026-03-23）** | ✅ | 6 HIGH + 8 MEDIUM。核心发现：BpfProgInfo/BtfInfo layout 未验证、BTF_KIND 常量硬编码、cmd_apply 零测试、所有 pass 从未用真实 bytecode。报告：`docs/tmp/20260323/daemon_mock_test_audit_20260323.md`。 |
| **415** | **修复全部 14 个测试问题（2026-03-23）** | ✅ | 6 HIGH + 8 MEDIUM 全修。BpfProgInfo/BtfInfo field-by-field layout 验证、BTF_KIND 从 header 解析、真实 .bpf.o bytecode 测试 5 个 pass。**关键发现**：rotate scanner 不匹配 clang 反向 OR、cond_select 不匹配 Jcc+1 短 pattern、extract 全部 caller-saved conflict。 |
| **416** | **Pass pattern matcher 修复 + caller-saved save/restore（2026-03-23）** | ✅ | **(1)** RotatePass: 支持反向 OR 操作数（256/256 匹配，17 applied）。**(2)** CondSelectPass: 支持 Jcc+1 短 pattern（104 detected）。**(3)** caller-saved save/restore in passes/utils.rs（endian 256 applied, extract 1 applied）。**(4)** BranchFlipPass 真实 bytecode 测试（256 flips verified）。**303 tests**。 |
| **417** | **⚠️ kinsn operand-encoded ALU 设计（2026-03-23）** | ✅ 设计完成 | **核心 novelty**：kinsn 不是函数调用，是自定义 ALU 指令。dst_reg 编码操作数，off 编码常量，verifier 只 mark dst_reg modified + narrow_result 回调恢复精度。每个 kinsn 替换都是 N→1 指令，零开销。**关键**: 这是论文 kinsn 机制的核心贡献 — 如何让 verifier 正确建模平台特定内联指令。设计报告：`docs/tmp/20260323/kinsn_register_design_20260323.md`。 |
| **418** | kfunc verifier 机制调研（2026-03-23） | ✅ | verifier 无现成机制让 kfunc 控制 clobber。KF_FASTCALL 只做 spill/fill NOP 消除。do_refine_retval_range() 和 bpf_res_spin_lock 是 range narrowing 先例。报告：`docs/tmp/20260323/kfunc_verifier_mechanisms_20260323.md`。 |
| **419** | **⚠️ bpf_kinsn_ops 完整设计（2026-03-23）** | ✅ | codex 调研。独立 sidecar `struct bpf_kinsn_ops`（不扩展 btf_kfunc_id_set）。`model_call()` 返回声明式 `bpf_kinsn_effect`（input_mask + clobber_mask + result range/tnum + mem_accesses），不暴露 bpf_reg_state。packed ABI 用 sidecar pseudo-insn（不复用 off 字段）。endian_load 改 const void*。KF_KINSN 替代 KF_INLINE_EMIT。设计报告：`docs/tmp/20260323/kinsn_ops_design_20260323.md`。 |
| **420** | **⚠️ kinsn_ops 完整实现（2026-03-23）** | ✅ | codex 实现两步。**第一步**：bpf_kinsn_ops + model_call + verifier 通用逻辑 + 5 module 迁移。**第二步**：packed ABI + sidecar pseudo-insn + daemon 适配。**结果**：53/62 applied, 1612 sites（rotate 701, extract 524, endian 256）。vm-selftest **70/70 PASS**（含 rejit_kinsn 9/9 + rejit_kinsn_packed 6/6）。Commit `8c1dd22`。Review：`docs/tmp/20260323/kinsn_implementation_review_20260323.md`。 |
| **421** | SIMD kinsn module | 🔄 调研中 | 新 kinsn module：bpf_memcpy_simd → AVX2/NEON，bpf_crc32 → SSE4.2。不需改框架，只需新 module + daemon pass。机会分析：`simd_constprop_opportunity_analysis_20260323.md`。**设计报告见 #472g**。 |
| **422** | Frozen map constant inlining | ❌ 不做 | **调研结论（`map_inlining_opportunity_analysis_20260323.md`）：真实 workload 几乎无显式 BPF_MAP_FREEZE，hot-path frozen map lookup 接近零。价值在于引出 #423。** |
| **423** | **Dynamic map inlining + invalidation** | ✅ v1 + invalidation loop 已落地 | `daemon/src/passes/map_inline.rs` 已实现 **ARRAY 全 lookup 消除**，并扩展到 **struct value 多字段 fixed-offset load**；同时支持 **HASH/LRU_HASH speculative inline**（保留 runtime lookup + null check，只替换 non-null path 字段 load）。最新实现移除 frozen requirement：只要 map type 支持 direct value access，就允许 mutable map speculative inline，并把 invalidation tracker 接到 `commands.rs` + `server.rs`，在 `serve` / `watch` 模式下轮询失效并自动 re-REJIT / restore-original。**设计报告见 #472a**。 |
| **424** | Verifier-assisted constant propagation | 🔄 v1 已落地，verifier log 版待做 | `daemon/src/passes/const_prop.rs` 已实现 pass 级常量传播：消费 `map_inline` 产出的 `MOV/LD_IMM64`，把常量 ALU 折叠成 `MOV/LD_IMM64`，把常量分支折叠成 `JA/NOP`。基于 `log_level=2` verifier state 的 exact-scalar + DCE 扩展仍待做。**设计报告见 #472b**。 |
| **425** | **vm-micro 正确性验证（2026-03-23）** | ✅ | 53/62 applied, 0 mismatch。rotate 15, extract 4, endian 1, wide_mem 49。kinsn pass 生效。 |
| **426** | **vm-corpus 正确性验证（2026-03-23）** | ✅ | 152 measured, **56 applied**（从 4 提升 14x）。0 error, 0 mismatch。wide_mem 35, endian 17, cond_select 12, extract 4。 |
| **427** | vm-e2e 正确性验证（2026-03-23） | ✅ | 4/5 PASS（katran timeout 未修复）。tracee/tetragon/bpftrace/scx OK。 |
| **428** | **Kernel code review（2026-03-23）** | ✅ | 2 CRITICAL（tools/uapi 头不同步、无 fd_array_cnt 上限）+ 3 HIGH（find_call_site x86 硬编码、text_invalidate 被删、无 try_module_get）。正确性全 PASS。报告：`docs/tmp/20260323/kernel_code_review_20260323.md`。 |
| **429** | **Packed ABI 验证（2026-03-23）** | ✅ | rotate ✅ packed（-2/site），extract ✅ packed（0/site）。**endian ❌ offset!=0 走 legacy（+4.99/site 膨胀）**。unit tests 不覆盖 packed。 |
| **430** | **修复 endian packed offset + 删 legacy ABI（2026-03-23）** | ✅ | endian packed 支持 offset ✅、unit tests 走 packed ✅、删除 daemon 全部 legacy emit 路径 ✅。`emit_kfunc_call_legacy()`/`save_caller_saved_regs()`/`restore_caller_saved_regs()` 全部删除。296 cargo tests pass。vm-micro/corpus/e2e 正确性验证 0 mismatch。Commit `5e10be2`。 |
| **431** | Kernel CRITICAL/HIGH 修复（2026-03-23） | ✅ | tools/uapi 头同步（`BPF_PSEUDO_KINSN_SIDECAR`、REJIT `flags`、`orig_prog_*`）、`fd_array_cnt` 上限=64、`find_call_site()` 改为 x86/ARM64 架构相关扫描、恢复 `bpf_arch_text_invalidate()`、`kinsn_ops` 在 verifier/JIT 期间显式持有 module 引用。验证：`make kernel`、`make vm-selftest`、`make vm-micro-smoke` 全通过。 |
| **432** | E2E 真实应用模式 + katran 修复 | ✅ 归入 #435 | katran HTTP server 修复（自定义 HTTP/1.0 handler）。5/5 PASS。Commit `a57e41f`。 |
| **433** | LFENCE/BPF_NOSPEC 消除 | 🔄 设计中 | 安全屏障消除。内核代码分析：`comprehensive_optimization_survey_20260323.md` §A。**设计报告见 #472c**。 |
| **434** | 全面优化调研（2026-03-23） | ✅ | codex 调研。报告：`docs/tmp/20260323/comprehensive_optimization_survey_20260323.md`、`map_inlining_opportunity_analysis_20260323.md`、`simd_constprop_opportunity_analysis_20260323.md`。 |
| **435** | E2E 真实应用模式 + katran 修复（2026-03-23） | ✅ | tracee/tetragon 已有真实 binary 流程。katran 改 xdpgeneric + 降并发 + retry。**5/5 PASS**。但 tracee 走 manual fallback（需修为 SKIP）、katran post-REJIT 破坏程序（correctness bug）。 |
| **436** | **删除 E2E manual fallback 路径（2026-03-23）** | ✅ | 删除 `e2e/cases/tracee/manual.py`（-244 行）。tracee/tetragon 二进制不可用时标 SKIP（"manual .bpf.o fallback is forbidden"）。e2e ALL PASSED。Commit `174bfe5`。 |
| **437** | **Katran post-REJIT correctness bug（2026-03-23）** | ✅ | Root cause 不是 REJIT bug，是 HTTP server 行为问题（`python3 -m http.server` 的 Connection handling 不可靠）。修复为自定义 HTTP/1.0 handler。Commit `a57e41f`。 |
| **438** | Endian packed ABI offset 支持 | ✅ 归入 #430 | 在 #430 中一起修复。 |
| **439** | 删除 daemon legacy ABI 代码 | ✅ 归入 #430 | 在 #430 中一起完成。`emit_kfunc_call_legacy()` 全部删除。 |
| **440** | Unit tests 覆盖 packed ABI | ✅ 归入 #430 | 在 #430 中一起完成。296 tests pass，全走 packed。 |
| **441** | Kernel CRITICAL/HIGH 修复（2026-03-23） | ✅ | 同 #431：修复 tools/uapi 头不同步、REJIT `fd_array_cnt` 无上限、`find_call_site()` x86 硬编码、`text_invalidate` 删除、`kinsn_ops` owner 引用问题。验证：`make kernel`、`make vm-selftest`、`make vm-micro-smoke` 全通过。见 #428。 |
| **442** | 冗余 bounds check 消除 | 🔄 调研中 | BPF packet access 中冗余的 bounds check 消除。从零调研。**调研报告见 #472d**。 |
| **443** | **Dead code elimination pass（2026-03-24）** | ✅ v1 已实现 | 新增 `daemon/src/passes/dce.rs`：做 **unreachable block elimination**（从每个 subprog entry 做 reachability）+ **`JA +0` NOP cleanup fixed-point**，并复用通用 branch-fixup/address-map helper。默认 pass 顺序改为 `map_inline -> const_prop -> dce -> wide_mem -> ...`。验证：`make daemon-tests` **333 pass**，`make daemon` 通过。设计报告：`docs/tmp/20260324/verifier_constprop_dce_design_20260324.md`。 |
| **444** | Helper call 内联/优化 | ✅ v1 已实现 | `skb_load_bytes -> direct packet access` 已落地为 `SkbLoadBytesSpecPass`，限定 TC (`SCHED_CLS`/`SCHED_ACT`) + `len<=8` + bytewise fast path；验证：`cargo test ... skb_load` **14/14**，`cargo test ...` **379 pass / 12 ignored**；实现 commit：`bf0742d9540f`。调研报告：`docs/tmp/20260324/helper_call_inlining_research_20260324.md`。 |
| **445** | Spill/fill 消除 | ❌ 低优先级 | BPF 程序冗余 spill/fill 消除。**调研结论（`comprehensive_optimization_survey_20260323.md`）：内核已有 KF_FASTCALL，增量收益低**。 |
| **446** | **kinsn 设计文档（2026-03-23）** | ✅ | `docs/kinsn-design.md`（1097 行）。覆盖 packed ABI 编码、daemon→verifier→JIT 数据流、bpf_kinsn_ops API、安全模型、5 个 kinsn 规格、添加新 kinsn 指南。Commit `5e10be2`。 |
| **447** | **Daemon debug logging（2026-03-23）** | ✅ | `--debug` CLI flag。per-pass 完整 bytecode dump、verifier log（via REJIT log_level=2）、JIT machine code dump。299 tests pass。 |
| **448** | **Corpus 测量 bug 修复（2026-03-23）** | ✅ | **Root cause**：daemon-socket 模式下 C++ runner 不输出 stock sample，Python fallback 把 recompile sample 当 baseline → ratio=1.0。修复：driver 在 v5_run 前单独跑 stock baseline + 防护 fallback。 |
| **449** | **bpftrace 脚本修复（2026-03-23）** | ✅ | 5 个脚本语法适配 bpftrace v0.20.2：`->` 替代 `.`、`delete(@map[key])`、`if ($cond)`、`interval:s:1`。6/6 scripts 成功。 |
| **450** | **Tetragon e2e 修复（2026-03-23）** | ✅ | kprobe `security_socket_connect` → `tcp_connect`（内核缺 `CONFIG_SECURITY_NETWORK`）。增加 agent 退出检测。 |
| **451** | **Tracee e2e 修复（2026-03-23）** | ✅ | setup.sh 重写适配当前 kernel。tracee/tetragon 都 status: ok。 |
| **452** | **Kernel 完整审计 v2（2026-03-23）** | ✅ | #428 五个问题全修 ✅。新发现 2 HIGH（refresh 吞错误 err=0、bpf_func publish 缺 barrier）+ 5 MEDIUM + 5 dead code。精确 LOC：1437 代码行 + 162 注释行。报告：`docs/tmp/20260323/kernel_full_review_20260323.md`。 |
| **453** | Kernel HIGH 修复（refresh err=0 + dead code） | 待做 | H2: trampoline/struct_ops/XDP refresh 失败时静默吞错误，可能 UAF。5 个 dead code 清理。 |
| **454** | 干净环境性能重跑 | 待做 | 串行跑 vm-micro/vm-corpus/vm-e2e strict params。不并行任何任务。 |
| **455** | Recompile overhead 测量 | ✅ 数据已有 | daemon pipeline ~2-5ms + kernel REJIT syscall ~3-7ms，从 static_verify.json 和 micro results 可提取。不需额外基础设施，只需汇总分析。 |
| **456** | ARM64 QEMU 测试 | 待做 | vm-arm64-selftest + vm-arm64-micro-smoke。基础设施已有。 |
| **457** | **WideMemPass packet pointer verifier 拒绝 bug（2026-03-25）** | ✅ | **Root cause**：XDP/TC 程序中非 R10 寄存器可能是 packet pointer，wide load 被 verifier 拒绝（range tracking 不够/对齐问题）。**修复**：`PassContext` 新增 `prog_type`，WideMemPass 在 XDP/TC/LWT/SK_SKB 程序中 skip 非 R10 base 的 site。`pass.rs` + `wide_mem.rs` + `main.rs`/`commands.rs`。+7 tests，350 daemon tests pass。 |
| **458** | **Corpus single-VM batch mode（2026-03-23）** | ✅ | `corpus/modes.py` 默认改为单 VM batch：一次 `vng --exec` 跑全部 target，guest 内 `daemon serve` 全程常驻，删除旧的 per-target VM 路径；`vm-corpus` 外部入口不变，JSON + markdown 输出格式保持兼容。 |
| **459** | **micro_exec keep-alive 模式（2026-03-23）** | ✅ 代码完成 | `runner/src/main.cpp` 无参启动进入 stdin JSON-line keep-alive 模式，BTF 只加载一次。`micro/driver.py` 新增 `MicroExecSession` 复用单个长驻进程。预期 micro 时间 13.5min→3-4min。`make smoke` + llvmbpf 验证通过。 |
| **460** | **Daemon 静态验证 pipeline（2026-03-23）** | ✅ VM 跑通 | `daemon/tests/static_verify.py` + `make vm-static-test`。130 个 .bpf.o → 342 个程序 → 48 applied → 340 verifier accepted → 2 error（xdp_synproxy）。micro 62/62 全部通过。结果：`daemon/tests/results/static_verify.json`。 |
| **461** | **BCC libbpf-tools corpus 扩展（2026-03-23）** | ✅ | macro_corpus.yaml +34 条目（16→50），覆盖全部可行 BCC libbpf-tools .bpf.o。7 个合理跳过（uprobe/USDT/dummy section）。 |
| **462** | **BCC e2e case（2026-03-23）** | ✅ 代码完成 | `e2e/cases/bcc/`：8 个代表性 tool（tcplife/biosnoop/runqlat/execsnoop/opensnoop/capable/vfsstat/tcpconnect），真实 binary 加载，已注册到 `e2e/run.py`。 |
| **463** | **kinsn v2 instantiate 设计（2026-03-23）** | ✅ 设计完成 | `instantiate_insn()` 方案：kinsn 展开为等价 BPF 指令序列 → verifier 直接 walk → 极简。建议论文前做 compat-v2（保留 sidecar/fd_slot，只切 verifier 从 effect DSL 到 instruction instantiation）。报告：`docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`。 |
| **464** | **Paper submodule + 死代码清理（2026-03-23）** | ✅ pushed | `docs/paper` 替换为 `yunwei37/bpfrejit-paper` submodule。删除 `daemon/tests/policy_v3_golden/`（10 个孤立 v1 YAML）+ 9 个垃圾文件（temp corpus JSON + 空 debug artifacts）。Commits: `91a2be3` + `329ef17`。 |
| **465** | **VM 管理设计文档（2026-03-23）** | ✅ | 分析现有 VM/ARM64/CI 管理现状 + 统一方案设计（config/machines.yaml、TARGET= 选择、vm_global lock）。报告：`docs/tmp/20260323/vm_management_design_20260323.md`。 |
| **466** | **Benchmark 框架 review（2026-03-23）** | ✅ | 五大瓶颈识别：corpus per-VM 72%、micro subprocess 83%、PGO sleep 15%、corpus socket wait、correctness/perf 不分离。#458/#459 解决前两个。 |
| **467** | **Runner 统一第三方 repo 控制面** | 🔄 | **父任务**：`runner/` 成为唯一第三方 BPF 项目注册中心和 fetch/build 入口。**第一批实现已落地**：`runner/repos.yaml`、`runner/scripts/fetch_corpus_repos.py`、`runner/scripts/build_corpus_objects.py`、`runner/libs/repo_registry.py`、`runner/Makefile` repo targets、根 `Makefile` 薄透传。验证：`make corpus-fetch REPOS='bcc'` ✅，`python3 runner/scripts/build_corpus_objects.py --repo bcc --max-sources 2` ✅。剩余消费层和旧路径清理见 #467d/#467f。 |
| **467a** | `runner/repos.yaml` schema 收口 | ✅ | `corpus/repos.yaml` 已迁到 `runner/repos.yaml`。`corpus/config/macro_corpus.yaml` 已改为读取 `runner/repos.yaml` / `runner/repos` / `runner/inventory.json`。schema 已扩到支持 `cargo_packages` / `promoted_objects` / `forced_includes` 等 repo-specific 字段，并可同时容纳 source-backed 与 prebuilt registry-only 项目；本轮新增 runner 注册项：`scx`、`netbird`、`systemd`，以及 `tracee` / `suricata` / `calico` / `KubeArmor` / `datadog-agent` / `coroot-node-agent` / `loxilb` / `opentelemetry-ebpf-profiler` / `tubular` 等 prebuilt upstream。 |
| **467b** | `runner/repos/` fetch 后端统一 | ✅ | fetch 入口已迁到 `runner/scripts/fetch_corpus_repos.py`，工作区目标改为 `runner/repos/`。`make corpus-fetch REPOS='bcc'` 实测通过，输出 `runner/inventory.json`。 |
| **467c** | repo build/harvest 编排收口到 `runner/` | ✅ | build 入口已迁到 `runner/scripts/build_corpus_objects.py`，`runner/Makefile` 新增 `corpus-fetch` / `corpus-build-objects` / `corpus-build`。对象产物仍写入 `corpus/build/`，但 orchestration 已收口到 `runner/`。builder 本轮新增 manifest-driven `forced_includes` 能力，已用于 `netbird` legacy map-def 源和 `systemd` 源的兼容编译；同时支持 prebuilt/registry-only repo 在 `corpus-build` 中走 zero-work no-op，而不是误报失败。 |
| **467d** | `corpus/` 和 `e2e/` 消费层迁移 | 🔄 | active 路径已继续迁移：`bcc` / `scx` e2e 默认 repo 路径改到 `runner/repos/`，`e2e/run.py` 的 `scx` 默认参数已切到 `runner/repos/scx`，`runner/Makefile` 新增 `e2e-prep` / `scx-artifacts`，`make vm-e2e` 会在进 VM 前自动准备 `runner/repos/scx` 和 `scx_rusty` binary。`corpus` README / `e2e` README 已同步更新；其余 case/配置和遗留硬编码路径继续清理。 |
| **467e** | Make 入口统一 | ✅ | 根 `Makefile` 新增薄封装 `corpus-fetch` / `corpus-build-objects` / `corpus-build`，全部透传到 `runner/Makefile`。 |
| **467f** | repo 控制面验证与旧路径清理 | 🔄 | 当前验证：repo manifest 解析 ✅、`make corpus-fetch REPOS='bcc'` ✅、`python3 runner/scripts/build_corpus_objects.py --repo bcc --max-sources 2` ✅、相关 Python 文件 `py_compile` ✅、`make -C runner e2e-prep` ✅、`make corpus-fetch REPOS='netbird systemd'` ✅、`python3 runner/scripts/build_corpus_objects.py --repo netbird --repo systemd --max-sources 3` ✅、`make corpus-fetch REPOS='tracee'` ✅、`python3 runner/scripts/build_corpus_objects.py --repo tracee --max-sources 1` ✅（prebuilt repo 正确走 zero-work no-op）。fetch 路径已支持把 legacy `corpus/repos/<name>` checkout 自动迁移到 `runner/repos/<name>`（已实测迁移 `scx`、`netbird`、`systemd`）。遗留旧路径清理仍未完成。 |
| **468** | Corpus 补全缺失项目（macro_corpus.yaml） | ✅ | +61 条目：cilium/KubeArmor/loxilb/scx/bpftrace/xdp-tools/xdp-tutorial/netbird/opentelemetry-ebpf-profiler/tubular。加上 #461 BCC +34 条目，macro_corpus.yaml 从原始 ~60 扩展到 ~155 条目。YAML 验证通过。 |
| **469** | **Runner infra 收口后的构建修复、全量验证与跑速分析** | 🔄 | **支撑任务**：在 #467 / #470 改动落地后统一修复构建与接线问题，并做完整验证，不接受只跑 smoke 收尾。最终验证至少覆盖 `make all`、`make check`、`make vm-static-test`、全量 `vm-micro`、全量 `vm-corpus`、全量 `vm-e2e`；同时分析 benchmark framework 自身运行这些任务时的性能瓶颈，必要时继续优化以缩短总评测时间。**当前状态**：`make all` ✅、`make check` ✅；VM 全量验证与跑速分析继续见 #469b/#469c。 |
| **469a** | Runner infra 收口后的本地构建验证 | ✅ | `make all` 与 `make check` 已通过，包含 runner `micro_exec`、daemon release build、kernel-tests、daemon-tests、Python tests、local smoke。当前未发现新的构建/链接阻塞；daemon 仍有若干非阻塞 warning。 |
| **469b** | Runner infra 收口后的全量 VM 验证 | ✅ | 串行全量验证已完成：`make vm-static-test STATIC_VERIFY_ARGS='--mode micro' TARGET=x86` ✅（62 objects / 62 programs / 39 applied / 62 verifier accepted）、`make vm-static-test TARGET=x86` ✅（191 objects / 420 programs / 63 applied / 418 verifier accepted；191 objects 中 58 个因 loader/libbpf 限制 `skip_load`，1 个 object partial，剩余 runtime errors 仍集中在 `xdp_synproxy`）、`make vm-micro TARGET=x86` ✅（`468.87s`）、`make vm-corpus TARGET=x86` ✅（`908.68s`，152 compile/measured pairs，44 applied）、`make vm-e2e TARGET=x86` ✅（`1186.39s`；tracee/tetragon/bpftrace/scx/katran/bcc 全部 OK）。 |
| **469c** | Benchmark 执行性能瓶颈分析与提速 | 🔄 数据已采集 | 本轮数据表明：1) `vm-micro` 的主成本仍是 guest 内 `kernel-rejit compile`，但 batch 重构最初引入了一次明显回归，根因不是 benchmark 本体，而是 correctness-only 路径错误默认写出了超重 debug artifacts：`vm_micro_20260324_123603` 结果目录达到 `421M`，其中 `details/daemon_debug/` 共 `63` 个 JSON、总计 `417.56 MB`。修复为“默认不写 live_samples/daemon_debug 细节，只在显式 `--write-details` 时开启”后，同参数 `make vm-micro TARGET=x86 ITERATIONS=1 WARMUPS=0 REPEAT=1` 从 `154.23s`（`vm_micro_20260324_122147`）降到 `119.39s`（`vm_micro_20260324_124131`），也快过之前旧路径的 `132.85s`（`vm_micro_20260324_020125`）。2) `vm-corpus` 在 single-VM batch + C++ runner 后已消掉 per-target VM 启动，`REPEAT=1` 的可比成功运行从 `703.35s`（`vm_corpus_20260324_022707`）降到 `514.45s`（`vm_corpus_20260324_121217`）；剩余大头仍是 guest 内 compile/verify，而不是 Python/VM 外壳。3) `vm-static-test` 已迁到 C++ batch path，旧的 Python `bpftool/loadall/process_*` 调度栈已删除；`static_verify_object` 改为 object-level batch jobs，直接用 `libbpf` 打开/加载 object、遍历已加载 prog 并抓 xlated/JIT dump。`cilium/bpf_lxc.bpf.o` 这类在 `bpf_object__open_file()` 阶段即 `Operation not supported` 的对象现在会被稳定归类为 `skip_load`，不再中断整轮验证。4) `vm-e2e` 的长尾主要来自 case/workload 本身，不是 VM 包装层；`scx` 的 host-side repo/binary 前置已收口到 `runner`，重复运行时可直接 skip。5) 已修基础设施固定成本/噪音：`runner.libs.workload` 和 `katran` 的轻量 HTTP helper 对客户端提早断开不再打印 `BrokenPipeError` traceback；`runner/Makefile` 新增按需 `e2e-tracee-setup` / `e2e-tetragon-setup`，warm cache 实测直接 skip（`elapsed_s=0.00`）。下一步提速重点：#457、进一步压缩 guest 内 compile/verify 总量、剩余 e2e setup/download 缓存细化。 |
| **470** | **Runner 统一 VM/机器调度控制面** | 🔄 | **父任务**：所有 VM/远端机器的注册、选择、排队、串行执行、guest 初始化和 VM 相关构建编排全部收口到 `runner/`。**前两批实现已落地**：`runner/machines.yaml`、`runner/libs/machines.py`、`runner/scripts/with_vm_lock.py`、`runner/libs/vm.py` 的机器解析 + 串行锁/队列状态；新增 `runner/scripts/run_vm_shell.py` 和 `runner/Makefile` 内的 `vm-*` 目标，根 `Makefile` 的 VM 入口已降为薄透传。验证：`py_compile` ✅、`resolve_machine()` / `build_vng_command()` ✅、两个并发 `with_vm_lock.py` 任务自动排队串行完成（总耗时 `2.59s`，第二个任务 `wait_seconds=1.82s`）✅、`make -n vm-test TARGET=x86` 显示根入口已透传到 `runner/Makefile` ✅。剩余 backend/consumer 收口见 #470c/#470e/#470f。 |
| **470a** | `runner/machines.yaml` 机器注册中心 | ✅ MVP | `runner/machines.yaml` 已落地，注册本地 x86 vng、本地 ARM64 QEMU、AWS ARM64，并提供 alias、`default_targets`、`backend`、`arch`、`executable`、`cpus`、`memory`、`lock_scope`。后续可继续扩展 kernel/rootfs/build profile 字段，但中心注册入口已建立。 |
| **470b** | 自动排队 + 串行执行层 | ✅ MVP | `runner/scripts/with_vm_lock.py` + `runner/libs/machines.py` 已提供 file-backed queue state 和 `vm_global` lock；VM 相关命令现在可自动排队并串行执行，而不是只靠人工约束。并发验证：两个任务总耗时 `2.59s`，第二个任务记录 `wait_seconds=1.82s`。 |
| **470c** | VM backend adapter 收口 | 🔄 | `runner/libs/vm.py` 已接管 `vng` backend 的命令拼装、锁包装和机器解析；`runner/scripts/run_vm_shell.py` 进一步把“guest 内运行 shell 命令”的 x86 VM 路径收口到 runner。`qemu-system-aarch64`、AWS SSH、CI runner adapter 仍待继续收口。 |
| **470d** | 根 `Makefile` 薄封装化 | ✅ | 根 `Makefile` 的 `vm-test` / `vm-selftest` / `vm-static-test` / `vm-negative-test` / `vm-micro-smoke` / `vm-micro` / `vm-corpus` / `vm-e2e` 已改成薄透传到 `runner/Makefile`，不再内联 `vng` 命令、guest init、queue/lock 或 e2e 预下载逻辑。 |
| **470e** | `micro/` / `corpus/` / `e2e/` VM 路径迁移 | 🔄 | `micro/driver.py`、`corpus/modes.py`、`daemon/tests/static_verify.py` 的执行热路径都已继续收口：Python 仍负责 YAML/control-plane 选择，但实际 job 执行改为一次调用 `runner/build/micro_exec run-batch` 的 C++ batch runner；`static_verify` 的旧 `bpftool/loadall/process_*` Python 调度代码已删除。`corpus/modes.py` 仍通过 `runner.libs.vm.build_vng_command()` 生成 VM 命令；`e2e/cases/scx/case.py` 已通过 `run_in_vm(..., action=\"vm-e2e\")` 接入 runner 调度语义。剩余待迁移的是 `e2e/run.py` 和其他 case 的具体执行循环。 |
| **470f** | 调度控制面验证 | ✅ 主线已通 | 已完成基础验证：`py_compile` ✅、机器解析 ✅、命令生成 ✅、并发队列/锁串行化 ✅。端到端验证也已在 #469b 跑完：`make vm-static-test` / `make vm-micro` / `make vm-corpus` / `make vm-e2e` 全部通过；剩余工作已转为性能优化与个别 backend/case 的继续收口。 |
| **471** | **用户态 benchmark 框架死代码清理（2026-03-24）** | ✅ | corpus/modes.py 删 3 函数 + 1 import（invocation_summary/paired_stock_invocation_summary/text_invocation_summary/parse_runner_samples import）、MODE_NAMES 常量。micro/benchmark_catalog.py 删 3 无用全局变量（DEFAULT_SUITE/AVAILABLE_BENCHMARKS/AVAILABLE_RUNTIMES）。micro/driver.py 删 read_git_sha()（和 _git_rev_parse 重复）。Commits `d3879ba`+`3b98b53`+`eeef9f4`。 |
| **472** | **⚠️ 未实现优化深度调研（2026-03-24）** | 🔄 | **父任务**：8 份独立调研/设计报告，覆盖 plan §3 中所有已列出但未设计的优化。全部 codex 并行执行中。 |
| **472a** | #423 Dynamic map inlining + invalidation 设计报告 | 🔄 codex 执行中 | 已有机会分析（`map_inlining_opportunity_analysis_20260323.md`），本轮做具体设计：稳定性检测、invalidation 机制、bytecode rewrite 算法、verifier 交互、daemon pass 设计、case study、break-even 模型。→ `docs/tmp/20260324/dynamic_map_inlining_design_20260324.md` |
| **472b** | #424 Verifier const prop + #443 DCE 深度调研+设计 | 🔄 codex 执行中 | 已有统计（`simd_constprop_opportunity_analysis_20260323.md` Part 2），本轮做：log_level=2 格式精确解析、可利用常量状态分类、verifier 接受性验证、DCE 算法、pass 交互顺序、case study。→ `docs/tmp/20260324/verifier_constprop_dce_design_20260324.md` |
| **472c** | #433 LFENCE/BPF_NOSPEC 消除设计报告 | ✅ | 已有内核代码分析（`comprehensive_optimization_survey_20260323.md` §A），本轮做：corpus NOSPEC 统计、安全判断算法、verifier 交互（pre-fixup bytecode → verifier 重新决定插不插）、safe-load 替代方案、case study。→ `docs/tmp/20260324/lfence_nospec_elimination_design_20260324.md` |
| **472d** | #442 冗余 bounds check 消除从零调研 | ✅ | 从零开始：bounds check bytecode pattern、冗余定义（dominator 关系）、corpus XDP/TC 统计、消除算法（interval analysis）、verifier 接受性（合并 vs 删除）、case study。→ `docs/tmp/20260324/bounds_check_elimination_research_20260324.md` |
| **472e** | 128-bit wide load-store 全新调研 | ✅ | 新课题：ARM64 LDP/STP、x86 MOVDQU/REP MOVSB、corpus 连续相邻 load/store 频率、和 wide_mem 关系、kinsn 设计、verifier 挑战。→ `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md` |
| **472f** | ADDR_CALC (LEA) 从零调研 | ✅ | 报告：`docs/tmp/20260324/addr_calc_lea_research_20260324.md`。**主结论**：strict `mov+shift+add` LEA pattern 在当前 `corpus/build` 里仅 **14 sites / 7 objects**，**100% 来自 tetragon**，且全是 `scale=4, disp=0`；x86 strict LEA **ROI 低，不建议第一波实现**。补充观察：ARM64 broader shifted-add（特别是 `shift=4`）覆盖远大于 x86 LEA，应视为 separate family。 |
| **472g** | #421 SIMD kinsn 设计报告 | ✅ | 已有机会分析（`simd_constprop_opportunity_analysis_20260323.md` Part 1），本轮做：技术路线决策（rep movsb vs SSE2 vs AVX2）、kinsn module 设计、daemon pass、ARM64 设计、corpus case。→ `docs/tmp/20260324/simd_kinsn_design_20260324.md` |
| **472h** | #444 Helper call 内联/特化调研 | ✅ | 报告：`docs/tmp/20260324/helper_call_inlining_research_20260324.md`。主结论：`skb_load_bytes` 是最适合先做的纯 bytecode helper specialization；`skb_store_bytes` 只适合 `flags=0` 窄子集；`probe_read_kernel` 必须保留 nofault/fault-handling 语义；`ktime_get_ns` 只能走新 intrinsic/helper-inline contract。 |
| **473** | **Related Work 系统性文献整理 + 对比分析（2026-03-24）** | ✅ | codex 完成基于 primary sources 的全面 related-work survey，覆盖 K2/Merlin/EPSO/ePass/BCF、Jitterbug/Jitk/PREVAIL/Agni/VEP/BeeBox/VeriFence、bpftime/llvmbpf/uXDP/hXDP/eHDL/femto-containers，以及 HotSpot/V8/LLVM ORC/livepatch 等类比系统；输出逐篇分析、大对比表、按维度差异化分析与 BpfReJIT novelty 总结。报告：`docs/tmp/20260324/related_work_comprehensive_analysis_20260324.md`。 |
| **474** | **⚠️ Map Inlining + Const Prop + DCE 实现（论文核心 story）** | 🔄 | **父任务**：分阶段实现 dynamic map inlining 及其级联优化链。当前进度：**474a/474b/474c/474d/474e/474f 已完成**，默认 pipeline 已接入 `map_inline -> const_prop -> dce -> wide_mem -> ...`，`serve` / `watch` invalidation loop 也已落地；后续主线剩 **474g verifier-assisted classification**。Corpus 数据支撑：11556 个 map_lookup_elem site；Katran 22→2 条（-91%）；Tetragon 447→2（-99.6%）。设计文档：`dynamic_map_inlining_design_20260324.md` + `verifier_constprop_dce_design_20260324.md`。 |
| **474a** | MapInlinePass v0：ARRAY + const key + scalar loads | ✅ | v0 已完成：`MapInfoAnalysis` + `find_map_lookup_sites` + `extract_constant_key` + rewrite + ARRAY null check 消除 + branch fixup。daemon tests 已通过。 |
| **474b** | MapInlinePass v1：struct value 多字段 + HASH map 稳定 entry | ✅ | 已完成：支持 **多个 fixed-offset `LDX_MEM` 字段读取**（struct value 多字段分别替换为 `MOV/LD_IMM64`）；支持 **HASH/LRU_HASH speculative inline**，daemon 成功读值时只 inline **non-null path**，保留 runtime lookup + null check，并在 pass diagnostics 里标记 speculative site。 |
| **474c** | ConstPropPass：利用 map inline 产出的常量做传播 | ✅ | 已完成：新增 `daemon/src/passes/const_prop.rs`，跟踪 `MOV_IMM/LD_IMM64` 常量状态，折叠常量 ALU，并把常量条件分支改写为 `JA/NOP`。默认 pass 顺序已改为 `map_inline -> const_prop -> wide_mem -> rotate -> ...`。 |
| **474d** | **DCEPass：dead branch + unreachable block elimination（2026-03-24）** | ✅ v1 | 已完成 v1：`daemon/src/passes/dce.rs` 在 `const_prop` 后执行，消费折叠后的 `JA/NOP`，删除不可达 basic block，并循环删除 `JA +0` NOP 直到 fixed point；dead register def elimination 暂缓。已补单测覆盖 dead branch、NOP cleanup 和 subprog 保留，`make daemon-tests` 通过。 |
| **474e** | 全量测试 + 性能验证（2026-03-25） | ✅ | **vm-static-test**: 62/62 verifier accepted, 53 applied, avg -36 insns, avg -161 bytes。**vm-micro**: 62/62 correct, 4800 sites applied, geomean 1.00x（micro 无 map lookup，中性）。**vm-corpus**: 152 measured, 72 applied, **exec geomean 0.854x（rejit 快 ~17%，从 9% 提升到 17%）**。**vm-e2e**: Katran BPF **+8.8%**（speedup 0.919, app +1.4%, P99 -1.2%）；Tracee/Tetragon REJIT 失败（"no direct value access support for this map type" + "unreachable insn" — map_inline 对不支持直接值访问的 map 类型触发 verifier 拒绝）；BCC/bpftrace/scx completed 但无有效对比。结果：`vm_micro_20260325_053433` + `vm_corpus_20260325_053936` + `e2e/results/*_20260325_06*`。 |
| **474f** | Dynamic invalidation（watch/serve 模式） | ✅ | `MapInvalidationTracker` 已接入 daemon pipeline：`MapInlinePass` 输出 `(map_id, key, expected_value)` 记录，`commands::try_apply_one()` 成功应用后刷新 tracker；`serve` / `watch` 每秒轮询 invalidation，命中后自动重新 REJIT，若新值导致 map_inline 不再可改写则回退到原始 bytecode 并清理 tracking。测试：`cargo test --manifest-path daemon/Cargo.toml invalidation` **12/12**，以及 `cargo test --manifest-path daemon/Cargo.toml` **436 pass / 12 ignored**。tracker primitive 实现 commit：`eb9b5fe`。 |
| **474g** | Verifier-assisted map classification | 待做 | 利用 REJIT log_level=2 的 verifier state 自动识别：哪些 map_lookup 的 key 是常量、哪些 map 是 ARRAY/HASH、value 的字段 layout。避免手动数据流分析，让 verifier 做大部分工作。 |
| **474h** | Frozen map 特殊路径 | ⏸ 降优先级 | 移除 frozen requirement + 接通 invalidation loop 后，frozen map 不再是 correctness gate。后续如果需要，可把 frozen map 作为“无需 tracking 的 permanent inline”小优化；不影响主线。 |
| **475** | **⚠️ kinsn 统一到 kfunc 路径（消除平行子系统）（2026-03-25）** | 📝 设计完成 | **目标**：消除 kinsn 在 kfunc 旁边建的平行基础设施（独立 UAPI pseudo、独立注册表、独立 desc/BTF 查找、独立 JIT dispatch），统一到标准 kfunc 路径。**核心方案**：module 导出真实 kfunc（`struct bpf_kinsn *bpf_rotate64(void) { return &rotate; }`），用标准 `register_btf_kfunc_id_set()` + `KF_KINSN` flag 注册；daemon emit 的 CALL 改为 `BPF_PSEUDO_KFUNC_CALL` 编码（imm=func btf_id）；verifier 早期 normalize shim 把旧 `PSEUDO_KINSN_CALL` 归一化为 `PSEUDO_KFUNC_CALL`；`check_kfunc_call()` 看到 `KF_KINSN` → proof lowering 旁路（instantiate_insn → verifier walk）；`fixup_kfunc_call()` 对 `KF_KINSN` 跳过 imm rewrite；JIT 在 kfunc CALL 路径内按 `KF_KINSN` 分派到 `emit_x86/emit_arm64`。**保留不变**：sidecar packed ABI、verifier proof lowering/restore 语义、native emit 回调。**可删除**：`kinsn_tab`（prog_aux + btf）、`register_bpf_kinsn_set()`/`unregister`/`btf_try_get_kinsn_desc()`、`add_kinsn_call()`、`fetch_kinsn_desc_meta()`、`bpf_jit_find_kinsn_desc()`/`bpf_jit_get_kinsn_payload()` 独立入口、`BPF_PSEUDO_KINSN_CALL` UAPI（降为 compat shim）、独立 JIT dispatch 分支、BTF_KIND_VAR descriptor 构建链。**预估**：内核 diff 净减 ~150-260 行，消除"平行子系统"审查阻力。调研报告：`docs/tmp/20260325/kinsn_kfunc_unification_research_20260325.md`（opus）+ `docs/tmp/20260325/kinsn_kfunc_unification_codex_research_20260325.md`（codex）。 |
| **475a** | Module 补真实 kfunc stub + daemon 切 FUNC discovery | 待做 | 10 个 module 文件（x86×5 + arm64×5）各补一个 `noinline struct bpf_kinsn *bpf_xxx(void) { return &desc; }` + `BTF_ID_FLAGS(func, ..., KF_KINSN)` + `register_btf_kfunc_id_set()`。daemon `kfunc_discovery.rs` 从 `find_var_btf_id()` 切到 `find_func_btf_id()`。 |
| **475b** | Verifier/JIT 旁路 + 早期 normalize shim | 待做 | 引入 `KF_KINSN` internal flag。`add_subprog_and_kfunc()` 早期把 `PSEUDO_KINSN_CALL` normalize 为 `PSEUDO_KFUNC_CALL`。`check_kfunc_call()` 对 `KF_KINSN` 转 proof lowering。`fixup_kfunc_call()` 对 `KF_KINSN` 跳过。JIT kfunc CALL 路径内加 `KF_KINSN` 分支。 |
| **475c** | 删除旧平行基础设施 | 待做 | 删除 `kinsn_tab`、`register_bpf_kinsn_set()`、`btf_try_get_kinsn_desc()`、`add_kinsn_call()`、独立 JIT dispatch、`BPF_PSEUDO_KINSN_CALL`（或降为 normalize shim）。更新全部 daemon tests 和 vm-selftest。 |
| **476** | **⚠️ 测试基础设施完善 + bug 修复（2026-03-25/26）** | ✅ | **测试基础设施**：(1) `rejit_swap_tests.c` 5 tests（metadata/concurrent/tail_call/orig_insns）。(2) `rejit_verifier_negative_tests.c` 4 tests（daemon bug verifier 回归：scalar→map_value/unreachable insn/invalid call/unsupported map type）。(3) `rejit_pass_correctness.c` 16 tests（每个 BPF prog identity REJIT 正确性验证）。(4) C++ runner retval correctness check（paired measurement stock vs recompile retval 对比）。(5) `tests/negative/` adversarial(23)+fuzz(1000) 接入 vm-selftest。(6) vm-selftest.sh 自动发现 `rejit_*` binary + host 预编译。(7) ARM64 QEMU 验证 53 pass。(8) `tests/kernel/` v1 遗留删除，16 个 BPF progs 迁移到 `tests/unittest/progs/`。**Bug 修复**：(1) daemon const_prop 丢弃 map_value 指针类型（`const_prop.rs:202`）。(2) daemon map_inline 对不支持直接值访问的 map 类型没有过滤（`map_info.rs:supports_direct_value_access()`）。(3) daemon DCE orphaned subprog（`utils.rs:eliminate_unreachable_blocks_with_cfg()`）。(4) 内核 `bpf_prog_get_info_by_fd()` metadata 竞态（`syscall.c:5772 guard(mutex)`）。(5) 内核 `bpf_prog_get_stats()` null deref（`syscall.c:2466`）。(6) 内核 swap 遗漏 `tail_call_reachable`/`arena`/`ctx_arg_info`。(7) 内核 `smp_wmb()` → `smp_store_release()`。(8) host `panic_on_oops=1` 移除。**验证结果**：vm-selftest x86 13 suites ALL PASSED；ARM64 53 pass；vm-micro 62/62 **0 correctness mismatch** 1591 sites；vm-corpus 131 targets 76 compile 55 measured 20 applied。**注意**：corpus `packet` mode 不做 retval 对比（无 TEST_RUN），retval check 只对 micro 和 corpus `compile` mode 有效。**残留 P1**：(1) `bpf_prog_rejit_swap()` one-way copy 导致 rollback 不可逆（需 kernel fault injection）。(2) `find_call_site()` 只返回第一个匹配（libbpf 限制无法测试）。**调查报告**：`docs/tmp/20260325/kernel_remaining_bugs_20260325.md`、`crash_path_trace_opus/codex_20260325.md`、`kernel_bug_root_cause_opus/codex_20260325.md`、`kernel_patch_strict_final_review_20260325.md`、`arm64_test_results_20260325.md`。 |
| **477** | **框架死代码清理（2026-03-26）** | ✅ | 删除 ~1314 行死代码：(1) corpus 删除所有 mode 概念（tracing/perf/code-size/packet），`driver.py` 直接调用 `packet_main()`，不再需要 mode 参数。(2) 删除 `runner/libs/attach.py`（860 行，全仓库无引用）。(3) 删除 `micro/driver.py --rejit` 无效 flag。(4) 清理 unused imports。**验证**：vm-micro 62/62 0 mismatch ✅；corpus 764 targets 471 compile 292 measured 113 applied ✅。**审查报告**：`docs/tmp/20260326/corpus_modes_audit_20260326.md`、`docs/tmp/20260326/benchmark_framework_dead_code_audit_20260326.md`。**注意**：`make vm-corpus` 通过 Makefile/runner 包装层有 output 截断问题，但 `python3 corpus/driver.py` 直接跑正常。 |
| **477** | **⚠️ CRITICAL: REJIT subprog kallsyms 双重删除 kernel panic（2026-03-25）** | ✅ | **Root cause**：`bpf_prog_rejit_swap()` 先 `kallsyms_del_all(prog)` poison 旧 subprogs lnode，再 swap func[] 到 tmp，cleanup 时 `__bpf_prog_put_noref(tmp)` 对 poisoned lnode 再次 `list_del_rcu` → GPF。**修复**：swap 后对 tmp 旧 subprogs 的 ksym.lnode 做 `INIT_LIST_HEAD_RCU()`（+10 行 syscall.c）。**验证**：新增 Test 6 `parallel_subprog_rejit`（8 prog × 20 REJIT = 160 次，含 bpf2bpf call），修复前 panic 修复后 6/6 PASS。`make vm-static-test`：191 objects / 616 programs / **217 applied** / 576 verifier accepted / 0 crash。报告：`docs/tmp/20260325/rejit_kallsyms_crash_report_20260325.md`。 |
| **480** | **Corpus 全 prog type 覆盖（2026-03-25）** | ✅ | **(1)** C++ runner `run-kernel-attach`（libbpf attach + bpf_enable_stats）。**(2)** batch plan `kernel-attach` 分支。**(3)** 删除 65K 行 inventory.json，改为 `macro_corpus.yaml` 驱动。**(4)** YAML 131→764 条目（322 test_run + 390 attach + 52 compile_only），覆盖 2019/2019 程序 100%。**(5)** **结果**：`make vm-corpus` 从 152 targets/69 applied → **764 targets / 471 compile / 292 measured / 113 applied**（2026-03-26 最新）。 |
| **479** | **测试基础设施统一（2026-03-25）** | ✅ | **(1)** `tests/unittest/Makefile`：wildcard 自动发现 `rejit_*.c`，统一 libbpf link flags，删除 SIMPLE_TESTS/LIBBPF_TESTS 手工列表。**(2)** `vm-selftest.sh` + `run_all_tests.sh`：`find rejit_* -executable` 自动发现，删除 hardcode 列表。**(3)** `vm-all` 加入 `vm-static-test`。加新测试只需放 `rejit_*.c` 文件，其他全自动。 |
| **478** | **WideMemPass provenance filter 优化（2026-03-25）** | ✅ | 从 `base_reg != R10` 改为 `is_likely_packet_ptr()` 回扫 32 条指令判断 base_reg 是否来自 ctx field load。只跳过真正的 packet pointer，map value / stack 衍生指针照常 apply。+1 test（map-value base in XDP）。351 daemon tests pass。 |
| **476** | **Daemon P1: map type 过滤 + WideMemPass packet pointer（2026-03-25）** | ✅ | **(1)** MapInlinePass PERCPU 过滤：从 `supports_direct_value_access()` / `can_remove_lookup_pattern_v1()` / `is_speculative_v1()` 中移除 PERCPU_HASH/PERCPU_ARRAY/LRU_PERCPU_HASH（用户态读值≠BPF运行时值）。+3 tests。**(2)** WideMemPass packet pointer：PassContext 新增 `prog_type`，XDP/TC/LWT/SK_SKB 程序中 skip 非 R10 base site。+7 tests。**350 daemon tests pass**。修复 #474e Tracee/Tetragon REJIT 失败 + #457 wide_mem verifier 拒绝。 |
| **481** | **⚠️ QEMU 8.2.2 TCG crash 根因确认 + QEMU 9.2.2 升级（2026-03-25）** | ✅ | **Bug**: 反复 `pid_iter_bpf__load()` + struct_ops probe 后 QEMU 8.2.2 TCG `tlb_set_dirty` segfault（固定 offset `0x8d8f21`）。**调查**：narrowing 到只需 `pid_iter_bpf__load()`（不需 attach/run）；KASAN 内核 KVM 模式全量测试（rejit_regression 6/6 + vm-static-test 191 obj + vm-negative-test + scx 500 轮 + unit tests）零内存安全报错；KASAN 内核 TCG 连 boot 都 crash（QEMU 同一 offset）。**根因**：QEMU 8.2.2 TCG softmmu `tlb_set_dirty` 实现 bug，处理 guest `text_poke_copy()` 快速 fixmap PTE 修改时出错。与内核 BPF/REJIT 代码无关。**修复**：源码编译 QEMU 9.2.2 安装到 `/usr/local`（`--prefix=/usr/local --datadir=/usr/share --target-list=x86_64-softmmu,aarch64-softmmu`），apt 8.2.2 保留不冲突。**验证**：QEMU 9.2.2 + TCG + 非 KASAN 内核 200 轮全过，零 segfault。报告：`docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md`。 |
| **482** | **Daemon const_prop typed LD_IMM64 修复（2026-03-25）** | ✅ | **Bug**: `const_prop` 把 typed `LD_IMM64`（`src_reg != 0`，如 `BPF_PSEUDO_MAP_VALUE`）当纯标量折叠，破坏 verifier 可见指针类型信息 → 多个 scx/tracee 程序 REJIT 失败。**修复**：`daemon/src/passes/const_prop.rs` 不再折叠 `src_reg != 0` 的 LD_IMM64 + 回归测试。**验证**：340 daemon tests pass。 |
| **484** | **内核代码 4 轮审阅（2026-03-25/26）** | ✅ | **审阅方法**：Opus + Codex 分别审阅 `kernel_vs_upstream_diff.patch`（2935 行，13 文件，+1967/-121 vs 上游 `c23719abc`），Opus 最终裁决交叉验证。**确认 7 个必修 HIGH**：(1) `do_misc_fixups` kinsn `insn_buf` 溢出（`max_insn_cnt` 无上界）。(2) `has_callchain_buf` 未 swap。(3) rollback `poke_tab` 裸 `memcpy` 无 `poke_mutex`。(4) unlink 失败时误删 `trampoline_users` 反向索引。(5) ARM64 emit 回调无 scratch buffer。(6) `rejit_scx_debug_prog` 调试残留。(7) rollback trampoline refresh 失败不一致。**确认 4 个误报**：`memcpy(prog->insnsi)` 越界（vmalloc 页对齐正确）、`bpf_arch_text_poke` 参数错（5 参数签名正确）、TRACING 类型缺处理（`trampoline_users` 已覆盖）、`validate_kinsn_proof_seq` `BPF_LD_IMM64`（class 检查避免误判）。**新发现（遗漏）**：`bpf_prog_get_info_by_fd` 持 `rejit_mutex` 执行 `copy_to_user` → page fault 时长时间持锁。**报告**：`docs/tmp/20260325/kernel_review_opus_final_20260325.md`、`kernel_review_codex_final_20260325.md`、`kernel_final_verdict_opus_20260326.md`、`kernel_verify_codex{1,2,3}_20260326.md`。 |
| **490** | **⚠️ 未调研 pass 补全（2026-03-26）** | ✅ | 6 个 codex 并行调研全部完成。**(1)** Subprog inline：834 调用点/67 对象，scx 占 63.7%，Phase 1 = leaf+单callsite+≤64insns，REJIT 元数据 blocker → `subprog_inline_research_20260326.md`。**(2)** Tail-call specialization：537 sites/31 对象，推荐 dynamic-key PIC（guarded constant-key），kernel poke_tab blocker → `tail_call_specialization_research_20260326.md`。**(3)** 危险 helper 防火墙：91034 helper 调用，权限提升类仅 10 次，Tracee+KubeArmor 占 91.6% 风险 → `dangerous_helper_firewall_research_20260326.md`。**(4)** Corpus 统计：568 对象/2019 程序/3427 bpf2bpf/537 tail_call/59939 dangerous → `corpus_call_statistics_20260326.md` + `.json`。**(5)** BPF 漏洞热修复：45+ CVE 中 31 个适合热补丁，四类模板 → `bpf_live_patching_research_20260326.md`。**(6)** 权限收紧：过权在部署层面非字节码层面，D⊇S⊇N⊇O 模型 → `privilege_narrowing_research_20260326.md`。 |
| **498a** | Bounds check merge (#442) — 设计文档 | ✅ | codex 补充实现级设计文档 → `bounds_check_merge_design_20260326.md` |
| **498b** | Bounds check merge (#442) — TDD 写测试 | ✅ | daemon unit tests 已写；最终 `cargo test bounds_check` 14/14 通过 |
| **498c** | Bounds check merge (#442) — 实现 | ✅ | `BoundsCheckMergePass` 已实现并接入 PassManager；review 中补修 mixed strict/inclusive guard merge bug |
| **498d** | Bounds check merge (#442) — Review + 测试 + commit | ✅ | code review 完成；`make daemon-tests` 通过；`make vm-static-test STATIC_VERIFY_ARGS='--mode micro' TARGET=x86` 已尝试，guest-side static verify 启动后超过 60s 无输出，按 review 窗口中止；commit/push：`639926cb28e9` |
| **498e** | Helper call spec / skb_load_bytes (#444) — 设计文档 | ✅ | 设计文档：`docs/tmp/20260326/skb_load_bytes_spec_design_20260326.md` |
| **498f** | Helper call spec / skb_load_bytes (#444) — TDD 写测试 | ✅ | TDD 报告：`docs/tmp/20260326/skb_load_bytes_tdd_report_20260326.md`；当前 `cargo test ... skb_load` **14/14** 通过 |
| **498g** | Helper call spec / skb_load_bytes (#444) — 实现 | ✅ | `SkbLoadBytesSpecPass` 已实现并接入默认 PassManager；review 中补修 `len>8`、packet pointer 宽访问和 `r1` ctx 跟踪问题 |
| **498h** | Helper call spec / skb_load_bytes (#444) — Review + 测试 + commit | ✅ | review 完成；`cargo test ... skb_load` **14/14**，`cargo test ...` **379 pass / 12 ignored**；实现 commit：`bf0742d9540f` |
| **498i** | Bulk memory kinsn — 设计文档 | ✅ | 设计文档：`docs/tmp/20260326/bulk_memory_pass_design_20260326.md` |
| **498j** | Bulk memory kinsn — TDD 写测试 | ✅ | TDD 报告：`docs/tmp/20260326/bulk_memory_tdd_report_20260326.md`；stub red state 已记录 |
| **498k** | Bulk memory kinsn — 实现 | ✅ | `BulkMemoryPass` + `pass.rs`/`mod.rs`/`kfunc_discovery.rs` bulk-memory 接线已完成；review 中补修 zero-only memset、chunked same-base overlap 和 different-base alias gate |
| **498l** | Bulk memory kinsn — Review + 测试 + commit | ✅ | review 完成；`cargo test ... bulk_memory` **16/16**，`cargo test ...` **395 pass / 12 ignored**，`make daemon-tests` **395 pass / 12 ignored**；实现 commit：`958bab4528b2` |
| **498m** | Dynamic map invalidation (#474f) — 设计文档 | ✅ | 设计文档已补充：`docs/tmp/20260326/dynamic_map_invalidation_design_20260326.md` |
| **498n** | Dynamic map invalidation (#474f) — TDD 写测试 | ✅ | TDD 报告：`docs/tmp/20260326/dynamic_map_invalidation_tdd_report_20260326.md`；tracker 覆盖 9 个新单测 |
| **498o** | Dynamic map invalidation (#474f) — 实现 | ✅ | `daemon/src/invalidation.rs` 已实现 `MapInvalidationTracker`；当前范围为 tracker primitive（记录 / 批量检查 / remove / dedup），未含 watch/serve loop 接线 |
| **498p** | Dynamic map invalidation (#474f) — Review + 测试 + commit | ✅ | review 报告：`docs/tmp/20260326/dynamic_map_invalidation_review_report_20260326.md`；`cargo test --manifest-path daemon/Cargo.toml invalidation` **12/12** 通过；实现 commit：`eb9b5fe`；plan 已同步更新 |
| **498q** | 危险 helper 防火墙 — 设计文档 | ✅ | 设计文档：`docs/tmp/20260326/dangerous_helper_firewall_design_20260326.md` |
| **498r** | 危险 helper 防火墙 — TDD 写测试 | ✅ | TDD 报告：`docs/tmp/20260326/dangerous_helper_firewall_tdd_report_20260326.md`；daemon unit tests 先红后绿 |
| **498s** | 危险 helper 防火墙 — 实现 | ✅ | `daemon/src/passes/dangerous_helper_firewall.rs` 已实现 deny/coarseify/audit + conservative cleanup；实现报告：`docs/tmp/20260326/dangerous_helper_firewall_impl_report_20260326.md` |
| **498t** | 危险 helper 防火墙 — Review + 测试 + commit | ✅ | review 报告：`docs/tmp/20260326/dangerous_helper_firewall_review_report_20260326.md`；`cargo test --manifest-path daemon/Cargo.toml dangerous_helper` **13/13** 通过；完整 `cargo test` 当前被未提交 `live_patch` 测试阻塞；实现 commit：`ca020c4`；plan 已同步更新 |
| **498u** | BPF 漏洞热修复 — 设计文档 | ✅ | 设计文档：`docs/tmp/20260326/live_patch_pass_design_20260326.md` |
| **498v** | BPF 漏洞热修复 — TDD 写测试 | ✅ | TDD 报告：`docs/tmp/20260326/live_patch_tdd_report_20260326.md`；daemon unit tests 先红后绿 |
| **498w** | BPF 漏洞热修复 — 实现 | ✅ | `daemon/src/passes/live_patch.rs` 已实现 null guard + helper arg sanitization + pointer refresh + tail-call isolation；实现报告：`docs/tmp/20260326/live_patch_impl_report_20260326.md` |
| **498x** | BPF 漏洞热修复 — Review + 测试 + commit | ✅ | review 报告：`docs/tmp/20260326/live_patch_review_report_20260326.md`；`cargo test --manifest-path daemon/Cargo.toml live_patch` **14/14** 通过；完整 `cargo test --manifest-path daemon/Cargo.toml` **430 passed, 0 failed, 12 ignored**；实现 commit：`750adfa`；plan 已同步更新 |
| **498y** | 3 个 kinsn modules（ARM64 LDP/STP pair + x86/ARM64 bulk memory）— 实现 + review + commit | ✅ | `module/arm64/bpf_ldp.c`、`module/x86/bpf_bulk_memory.c`、`module/arm64/bpf_bulk_memory.c` 与 `module/x86/Makefile`/`module/arm64/Makefile` 已提交；模块报告：`docs/tmp/20260326/arm64_bpf_ldp_module_report_20260326.md`、`docs/tmp/20260326/x86_bpf_bulk_memory_module_report_20260326.md`、`docs/tmp/20260326/arm64_bpf_bulk_memory_module_report_20260326.md`；review/fix：`docs/tmp/20260326/kinsn_modules_review_20260326.md`、`docs/tmp/20260326/kinsn_modules_fix_report_20260326.md`；实现 commit：`d29d9b6427ab`；plan 已同步更新 |
| **491** | **Recompile overhead 分解** | 待做 | verify 时间 + JIT 时间 + swap 时间 + daemon pipeline 时间。reviewer 必问。从 static_verify.json 和 micro results 可提取部分数据。 |
| **492** | **Scalability 测量** | 待做 | 100/500/1000 个 live 程序时 daemon 吞吐量和延迟。apply-all 和 watch mode。 |
| **493** | **Memory overhead 测量** | 待做 | REJIT 保留 orig bytecode + tmp prog 的额外内存。per-prog 和总量。 |
| **494** | **Fixed kernel peephole baseline 对比** | 待做 | `jit-fixed-baselines` 分支 vs BpfReJIT v2 在同样 benchmark 上的 A/B 对比。支撑 "userspace policy > fixed heuristic" 论点。 |
| **495** | **BPF 程序生命周期分析** | 待做 | 生产环境程序加载频率、存活时间分布。证明 post-load 优化有价值。可从 Tracee/Tetragon/Cilium 文档和 bpf_stats 数据推断。 |
| **496** | **K2/Merlin/EPSO 量化对比** | 待做 | 在同样的 benchmark 上 head-to-head 跑数据。至少 K2（有开源）。 |
| **497** | **ARM64 性能数据** | 待做 | vm-arm64-selftest + vm-arm64-micro。论文声称 multi-platform 需要至少一组数据。 |
| **483** | **宿主频繁重启分析（2026-03-25）** | 📝 | 调查期间宿主多次无 panic/oops 重启。每次 boot 有 `mce: [Hardware Error]: Machine check events logged`，有 CPU 过热降频（event count 65+）。原因：Intel Core Ultra 9 285K 在 `-j24` 全核编译 + QEMU TCG 高负载下过热。建议：降低编译并行度、检查散热。 |
| **491** | **⚠️ REJIT hotswap 压力测试全 prog_type 覆盖（2026-03-26）** | 🔄 | **审计**：`rejit_prog_type_test_coverage_audit.md` 发现 33 个 prog_type 中仅 1 个（RAW_TRACEPOINT）有强覆盖（真实 attach + REJIT + 用户态可观测行为）。**Batch 1（6 个 prog_type）实现**：kprobe/tracepoint/perf_event/fentry/LSM/XDP 各一个独立文件 `rejit_hotswap_TYPE.c` + `.bpf.c`。模式：持续触发工作线程 + 并发 REJIT hot swap + 用户态观测行为变化。**VM 验证结果**：tracepoint ✅ PASS，kprobe ❌（patch pattern 不匹配 clang 输出）、perf_event ❌（`perf_event_open` 失败）、fentry ❌（target-side trampoline refresh 未实现 — 真实内核 bug）、LSM ❌（attach 后 counter=0，程序未触发）、XDP ❌（counter 增量未切换）。**已知内核限制**：fentry/fexit/fmod_ret REJIT target prog 时 trampoline 不刷新（`trampoline_users` 只挂在 attached prog 侧，不挂在 target 侧）。**Batch 2（6 个）**：socket_filter/sched_cls/cgroup_skb/struct_ops/ext/sk_lookup — codex 写完待测。**报告**：`docs/tmp/20260326/rejit_prog_type_test_coverage_audit.md`。 |

# BpfReJIT: Dynamic, Extensible Compilation Framework for Kernel eBPF

> 本文档是 BpfReJIT 论文的单一 hub。
> **论文核心方向：构建一个最小化、动态、可扩展的内核编译框架，让 deployed eBPF 从一次性静态编译，变成可在线、透明、runtime-guided specialization 的执行环境。Paper 必须展示真实程序上的可测量加速和安全加固能力。**
> **编辑规则**：
> - **⚠️ 未经用户明确同意，禁止修改内核代码（vendor/linux-framework）。** 所有内核改动必须先调研→用户确认→再实施。codex/agent prompt 必须包含此约束。
> - 未经用户明确要求，禁止 git commit / git push。
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 Bash tool 的 `run_in_background: true` 跑 codex，不阻塞主对话。**禁止用 shell `&` 或 `2>&1 &` 后台启动 codex**（外层 shell 退出导致假完成通知，codex 子进程仍在跑）。
> - **构建+修改+运行不拆分**：一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent。
> - **⚠️ 同一时间只能有一个 agent 修改内核代码（vendor/linux-framework），也只能有一个 agent 跑测试（VM benchmark / selftest）。** 多个 agent 同时改内核代码会产生 git 冲突；多个 agent 同时跑 VM 测试会竞争资源、结果不可靠。调度时必须串行化内核改动和测试任务。
> - **⚠️ codex 默认不要 commit/push，除非 prompt 明确要求。** 改完代码就停，由 Claude 统一 commit。
> - **⚠️ 如果需要 commit，必须在 main 分支直接做，不要开新分支。** 开分支导致合并冲突。
> - **⚠️ 暂时性性能数据和实验计划只能出现在两个地方：(1) 开头摘要区域的权威数据行；(2) §7 任务追踪表格的条目。** §1-§6 的正文不得包含会过期的具体数字或待办计划。如果 §1-§6 需要引用性能数据，只引用任务编号（如"见 #256"），不内联数据本身。
> - **⚠️ 禁止死代码和防御性编程**：替换子系统时（如 v1→v2）必须删除旧代码，不保留 `if v1 / else v2` 分支。内核代码中不保留"以防万一"的检查——只在有具体失败场景时才加 guard。每行内核代码都是审核负担，越少越好。
> - **⚠️ 零静默失败（Zero Silent Failure）**：所有错误必须传播和报告。禁止 `unwrap_or_default()`、`.ok()`、`except: pass`、`let _ = result` 等静默吞错模式。禁止 `compile_only` 等标注来掩盖运行时失败——每个 corpus 程序要么跑出测量结果，要么明确报错说明原因。E2E case 失败不能伪装成 `skipped`。
> - **⚠️ Makefile 是唯一构建/测试入口**：禁止手动 `cargo build`、`insmod` 等。
> - **⚠️ 禁止 sudo**：VM 内已是 root（vng），主机不跑 BPF。
> - **⚠️ VM 测试每个 target 一个 agent**：vm-test/vm-micro/vm-corpus/vm-e2e 串行跑。
> - **Daemon 设计约束见 §4.6，Benchmark 设计约束见 §5.35。**
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

| 用途 | 说明 | OSDI 评估 |
|------|------|:---:|
| **性能优化** | wide load 合并、rotate、cmov、硬件特化 lowering、PGO、const propagation、map inlining | ✅ 主线 |
| **安全加固** | 插入 bounds check、speculation barrier、收紧权限、Spectre 缓解注入 | ⏸ future work |
| **恶意程序阻断** | 检测恶意 BPF prog → 替换为 no-op/安全版本 → 在线热修复，危险 helper 防火墙 | ⏸ future work |
| **运行时可观测** | 给 hot path 插入 tracing，不改应用代码 | ⏸ future work |

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
| **Subprog inline** | 否 | ⏸ 不在 OSDI 主线 | bytecode 层展开 subprogram call。**不做原因**：不依赖 runtime info，和论文 "deployment-time runtime-guided specialization" story 不符。**REJIT 元数据 blocker**：UAPI 不接受新 func_info/line_info。834 调用点 / 67 对象(11.8%)。调研：`subprog_inline_research_20260326.md` |
| **Const propagation** | 否 | ↗ 归入 #424 | 利用 frozen map / runtime invariants 做常量折叠 | 归入 verifier const prop |
| **SIMD (FPU)** | 是 | ❌ 不进 OSDI 主线 | **x86 SIMD 不做**：`kernel_fpu_begin/end` XSAVE/XRSTOR 开销 ~200-800 cycles，pair load/store 场景下远超收益；**ARM64 NEON 条件性 Phase 2**：仅 ≥1KiB + `may_use_simd()` 成立时考虑，no-FPU `LDP/STP` 优先。Linux crypto 模式（per-operation fpu_begin/end）不适用于 BPF 的细粒度调用 | **深度调研结论：x86 break-even ≥数百字节且需整次 BPF 调用摊销一次 FPU context；corpus 中绝大多数 copy/store ≤128B，不满足条件**。调研：`simd_fpu_kinsn_deep_research_20260326.md` |
| **Tail-call specialization** | 否 | ✅ 调研完成 | **Phase 1**：dynamic-key monomorphic PIC（guarded constant-key fast path），复用 kernel `map_poke_run()`。**Kernel blocker**：`poke_tab` shape check 需放宽 | **537 sites / 31 对象(5.46%)；Cilium 216、Tetragon 118、Tracee 49；upstream 已有 constant-key direct jump → 论文新意在 dynamic-key PIC；break-even 命中率 ~8%**。调研：`tail_call_specialization_research_20260326.md` |
| **Spill/fill 消除** | 否 | ❌ 不做 | 冗余 spill/fill 消除 | **内核已有 KF_FASTCALL，增量收益低** |

### 3.2 安全加固变换（暂不在 OSDI 评估范围）

> **2026-03-28 决定**：安全相关 pass（speculation_barrier、dangerous_helper_firewall、live_patch、权限收紧）暂不纳入当前评估和 benchmark pipeline。代码保留在 daemon 中供 future work 引用，但不在默认 pipeline 中启用，也不在 benchmark_config.yaml 中配置。

| 变换 | 状态 | 说明 |
|------|:---:|------|
| **Spectre 缓解注入** | ⏸ 暂不评估 | SpeculationBarrierPass + bpf_barrier kinsn。代码保留 |
| **LFENCE/BPF_NOSPEC 消除** | ⏸ 暂不评估 | corpus 861 程序实测 BPF_ST_NOSPEC = 0 |
| **危险 helper 防火墙** | ⏸ 暂不评估 | DangerousHelperFirewallPass。代码保留 |
| **BPF 程序漏洞热修复** | ⏸ 暂不评估 | LivePatchPass。代码保留 |
| **权限收紧** | ⏸ 暂不评估 | 调研完成，过权在部署层面非字节码层面 |

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

### 4.6 Daemon 设计约束

- **Session 级启动一次**：corpus/micro/e2e 的 daemon（serve 模式）在 benchmark session 开始时启动一次，整个 run 结束后关闭。禁止 per-object 或 per-program 重启 daemon。如果 daemon crash，报错退出，不自动重启掩盖问题。
- **Per-pass verify 用 BPF_PROG_LOAD dry-run**：每个 pass 后用 `BPF_PROG_LOAD`（非 REJIT）做 verify，成功后 close fd。最终只做一次 REJIT 原子 swap。**禁止为此修改内核代码**。
- **Verifier-in-the-loop**（目标架构）：每次 `BPF_PROG_LOAD(log_level=2)` verify 时，解析 verifier log 提取精确常量/range 信息，喂给下一个 pass（尤其是 const_prop）。把内核 verifier 当成免费的抽象解释 oracle。
- **零 libbpf 依赖**：daemon 只通过 raw BPF syscall 与内核交互。
- **安全 pass 不在 OSDI 范围**：`speculation_barrier`、`dangerous_helper_firewall`、`live_patch` 不在默认 pipeline。
- **结构化 per-pass 记录**：每个 program 的每个 pass 必须记录 `pass`/`changed`/`sites_applied`/`insn_delta`/`verify_result`/`verify_error`/`action`。

---

## 5. ���估计划

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

### 5.35 Benchmark 设计约束

- **每个 corpus 程序必须有 exec_ns**。没有 "code size only" fallback。不能测 exec_ns 的程序不进 corpus。
- **BPF 程序用它在生产中被使用的方式来测量**。有原生应用的程序（Tracee/Tetragon/Katran/BCC/bpftrace/scx/KubeArmor）必须用 app-native loader，不用 generic libbpf。
- **两种测量路径，没有第三种**：(1) App-native：真实应用加载+触发 BPF，`bpf_enable_stats` 读 per-program exec_ns；(2) TEST_RUN：`BPF_PROG_TEST_RUN` 直接测，仅限 XDP/TC/socket_filter 等支持的 prog_type。
- **kinsn module 证据**：E2E artifact 必须包含 kinsn module 加载状态（loaded_modules/failed_modules/daemon discovery log）。
- **ARM64 默认走 AWS 远端**（t4g.micro），不在本地 QEMU 跑 Python。
- **统计要求**：报告必须同时给 applied-only geomean 和 all-comparable geomean + sample count + comparison exclusion reasons。repeat ≥ 50，论文级 ≥ 500。

### 5.4 Required Hardware

1. Modern wide OoO x86 core ✅
2. Smaller-core / Atom-like x86 ❌
3. arm64 系统 🔄（CI 有，性能数据有限）

### 5.6 Benchmark Framework 架构

#### 设计原则

- **BPF 程序用生产方式加载和触发**：有原生应用的程序由应用加载（app-native），不用 generic libbpf + 手写 trigger
- **Corpus 和 E2E 共享 App Runner**：同一个 AppRunner 类（start/workload/stop），corpus 测 per-program exec_ns，E2E 测 app throughput/latency
- **C++ 只做 TEST_RUN 测量**：`micro_exec test-run` 极简——load→TEST_RUN→output JSON→exit。没有 batch orchestration、没有 prepared state、没有 daemon 通信
- **Python Orchestrator 是唯一编排者**：协调 app runner + daemon + C++ tool 的顺序。~200 行
- **每个测量单元自包含**：没有跨 object/跨 app 的共享 state（no prepared_key/ref/group）
- **并行在 orchestrator 层**：不同 app 之间可并行（prepare 阶段），测量阶段串行避免 CPU 竞争噪声
- **Makefile 是唯一入口**：所有 benchmark 从 `make vm-*` 触发
- **Same-image paired measurement**：load→baseline exec_ns→daemon REJIT→rejit exec_ns，同一加载实例上对比

#### 组件职责

```
┌─────────────────────────────────────────────────────────┐
│  macro_corpus.yaml                                       │
│  定义 WHAT：每个程序的测量方式                            │
│    measurement: app_native(repo=tracee) | test_run       │
│  不含 trigger 命令、io_mode 细节                         │
└───────────────────────┬─────────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────────┐
│  Orchestrator（Python，~200 行）                         │
│  负责 WHEN + 协调顺序                                    │
│                                                          │
│  for each entry:                                         │
│    baseline = loader.measure_baseline()                   │
│    daemon.optimize(prog_ids)                              │
│    rejit = loader.measure_rejit()                         │
│    report(baseline, rejit)                                │
│                                                          │
│  不做：BPF 加载、触发、测量实现、daemon 通信细节          │
└────────┬─────────────────┬──────────────┬───────────────┘
         │                 │              │
┌────────▼────────┐  ┌─────▼─────┐  ┌─────▼──────────────┐
│  App Runner     │  │  Daemon   │  │  micro_exec        │
│  (per-repo)     │  │  (Rust)   │  │  test-run (C++)    │
│                 │  │           │  │                    │
│  负责：         │  │  负责：   │  │  负责：            │
│  start app      │  │  REJIT    │  │  libbpf load       │
│  run workload   │  │  优化     │  │  BPF_PROG_TEST_RUN │
│  stop app       │  │           │  │  返回 exec_ns      │
│                 │  │  不做：   │  │                    │
│  不做：         │  │  测量     │  │  不做：            │
│  BPF 加载       │  │  加载     │  │  daemon 通信       │
│  直接测量       │  │  触发     │  │  编排              │
│  优化           │  │           │  │  app 生命周期      │
└─────────────────┘  └───────────┘  └────────────────────┘
```

#### App-native 测量流程

```
Orchestrator                App Runner              Daemon           bpf_stats
    │                          │                      │                 │
    ├── start(repo) ──────────►│ start app            │                 │
    │                          │ (app loads BPF)      │                 │
    │◄── prog_ids ─────────────┤                      │                 │
    │                          │                      │                 │
    ├── enable_bpf_stats ─────────────────────────────────────────────►│
    ├── run_workload(10s) ────►│ exec storm / packets │                 │
    ├── read_stats ───────────────────────────────────────────────────►│ baseline exec_ns
    │                          │                      │                 │
    ├── optimize(prog_ids) ───────────────────────────►│ REJIT          │
    │                          │                      │                 │
    ├── run_workload(10s) ────►│ exec storm / packets │                 │
    ├── read_stats ───────────────────────────────────────────────────►│ rejit exec_ns
    │                          │                      │                 │
    ├── stop() ───────────────►│ cleanup              │                 │
    │                          │                      │                 │
    ├── report(baseline, rejit)│                      │                 │
```

#### Corpus 和 E2E 共享

```
runner/libs/app_runners/        ← Corpus 和 E2E 共享层
  tracee.py                       class TraceeRunner:
    def start() -> [prog_ids]       启动 tracee，返回加载的 BPF program IDs
    def run_workload(seconds)       exec storm / file IO / network traffic
    def stop()                      cleanup
  tetragon.py                     class TetragonRunner: ...
  katran.py                       class KatranRunner: ...
  bcc.py                          class BCCRunner: ...
  bpftrace.py                     class BpftraceRunner: ...
  scx.py                          class ScxRunner: ...

corpus/orchestrator.py          使用 app_runners + bpf_stats → per-program exec_ns
e2e/cases/*/case.py             使用 app_runners + app benchmark → app throughput/latency
```

#### 目录布局（理想）

```
runner/                     # 共享基础设施
  libs/                     #   Python 共享库
    app_runners/            #     Per-repo app lifecycle（Corpus/E2E 共享）
      tracee.py
      tetragon.py
      katran.py
      bcc.py
      ...
    results.py              #     JSON result 解析/聚合
    statistics.py           #     median/geomean/CI/Wilcoxon
    vm.py                   #     vng boot/exec helpers
    rejit.py                #     daemon socket 通信
    bpf_stats.py            #     bpf_enable_stats + read per-program stats
  src/                      #   C++ micro_exec（仅 TEST_RUN + llvmbpf）
  scripts/                  #   AWS/ARM64 远端脚本

corpus/                     # Corpus 评估层
  config/macro_corpus.yaml  #   程序列表 + 测量方式（app_native | test_run）
  orchestrator.py           #   调度：app_runner 或 micro_exec → 聚合结果

e2e/                        # E2E 评估层
  cases/*/case.py           #   使用 app_runners，测 app-level metrics

micro/                      # Micro 评估层
  programs/                 #   62 个 BPF .bpf.c
  driver.py                 #   调度 micro_exec

daemon/                     # BpfReJIT daemon（Rust，serve-only）
module/                     # kinsn 内核模块
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
| 304 | **v2 架构探索+收敛（2026-03-21）** | ✅ | v1 native-level rewrite → v2 bytecode-layer transformation + kernel verifier 验证。**收敛方案**：(A) GET_ORIGINAL+REJIT 程序变换；(B) Inline Kfunc ISA 扩展（KF_INLINE_EMIT）。REJIT 接受完整新 bytecode（非 patch）。**+200 行 kernel**。10 份调研报告在 `docs/tmp/20260320-21/`。POC 三 Phase 完成（`rejit-v2` 分支）。主仓库 commits: `e50365a`/`ba3c76e`/`f5eb9f1`。关键发现：xlated 不可逆需保存原始 bytecode；Inline Kfunc 优于独立 kinsn；re-verify ~ms 级。 |
| 305 | 内核 POC 修复（2026-03-21） | ✅ | **444 行 kernel**（含 selftest 974 行）。fd_array/等长约束/rejit_mutex/sleepable 等 7 项修复。VM 通过。 |
| 306 | Runner v1→v2 替换 | ✅ | 净删 1121 行，删全部 v1 scanner/policy/directive 代码。 |
| 307 | module/x86/ 真实 kinsn 模块 | ✅ | `bpf_rotate.c`(ROL)、`bpf_select.c`(CMOV)、`bpf_extract.c`(BEXTR)。 |
| 308 | Bytecode rewriter 架构设计 | ✅ | 6 阶段 pipeline。报告：`docs/tmp/20260321/rewriter_architecture_design_20260321.md`。 |
| 309 | scanner→daemon 重命名 | ✅ | `git mv scanner daemon`，编译通过。 |
| 310 | Runner v1 死代码清理 | ✅ | 删 32 行 v1 残留。 |
| 311 | Daemon Rust POC 实现 | ✅ | **1834 行 Rust，21 tests**。C++→Rust 重写。6 模块，零 libbpf 依赖。 |
| 312 | VM 冒烟 + 3 bug fix | ✅ | **20/20 PASS**。REJIT cmd=39、ksym INIT_LIST_HEAD_RCU、len bytes÷8。 |
| 313 | Matcher Variant B 修复 | ✅ | 添加 high-first variant。27 tests。 |
| 314 | daemon-apply 集成 | ✅ | micro_exec `--daemon-path`。 |
| 315 | v2 WIDE_MEM 性能结果 | ✅ | 10/14 有 site。bounds_ladder **2.78x**、load_byte **2.59x**。Commit `27cbc1b`。 |
| 316 | Paper tex v2 更新 | ✅ | Abstract/Intro/Background 全部重写。+463/-866 行。 |
| 317 | corpus/ 死代码清理 | ✅ | 净删 ~329 行 v1 路径。 |
| 318 | driver.py --daemon-path 适配 | ✅ | Makefile `vm-micro` 自动传 DAEMON_PATH。 |
| 319 | Makefile cmake→cargo | ✅ | daemon target 改 cargo build。 |
| 320 | Commit push（2026-03-21） | ✅ | `698334f`/`56d6d19`/`c48cb43`。kernel submodule `4bcbc8e21`。 |
| 321 | Daemon pass 框架设计 | ✅ | PassManager 框架。报告：`docs/tmp/20260321/daemon_pass_framework_design_20260321.md`。 |
| 322 | Kernel code review | ✅ | 3 Critical + 4 Major。报告：`docs/tmp/20260321/kernel_v2_review_20260321.md`。 |
| 323 | ARM64 inline kfunc + kinsn 模块 | ✅ | `module/arm64/` 3 模块。+613 行。交叉编译通过。 |
| 324 | e2e v2 daemon 集成 | ✅ | 5 case 接入 baseline→apply-all→post_rejit。 |
| 325 | Attachment sync 调研+修复（2026-03-22） | ✅ | Trampoline/freplace UAF 是真问题。Phase 0-2 修复实现：+260 行 kernel。**VM 12/12 PASS**。报告：`docs/tmp/20260321/rejit_attachment_sync_research_20260321.md`。 |
| 326 | Verifier log parser | ✅ | `verifier_log.rs` 433 行，33 tests。 |
| 327 | Daemon profiling | ✅ | `profiler.rs` 249 行。bpf_stats polling。 |
| 328 | Daemon pass 框架实现 | ✅ | WideMemPass + RotatePass + SpectreMitigation。**104 tests**。 |
| 333 | 安全测试套件设计 | ✅ | 5 类测试。报告：`docs/tmp/20260321/safety_eval_design_20260321.md`。 |
| 334 | func_cnt 限制调研 | ✅ | swap 路径不完整。报告：`docs/tmp/20260322/func_cnt_and_e2e_compat_20260322.md`。 |
| 335 | perf/LBR 调研 | ✅ | VM 无硬件 PMU（Arrow Lake）。bpf_stats 够用。 |
| 336 | func_cnt 修复实现 | ✅ | **+55 行 syscall.c**。multi-subprog layout match + swap。**VM 6/6 PASS**。Kernel `21c1b1f89`。 |
| 337 | 安全 negative test suite | ✅ | **919 行，20 tests，VM 20/20 PASS**。主仓库 `31c1433`。 |
| 338 | VM micro 冒烟（2026-03-22） | ✅ | **62/62, 47 applied, 0 mismatch**。geomean 0.887x。 |
| 339 | Kernel cleanup + gate 放宽 + st_ops | ✅ | 净减 101 行，st_ops text_poke +85 行。**~608 LOC kernel**。报告：`docs/tmp/20260322/kernel_cleanup_arch_review_20260322.md`。 |
| 340 | Daemon 升级 | ✅ | 被 #344 取代。 |
| 341 | Benchmark 框架升级 | ✅ | driver.py 正确性验证，corpus v2 对齐。 |
| 342 | prog_type 覆盖测试 | ✅ | **VM 21/21**。覆盖 13 种 prog_type。 |
| 343 | tail_call REJIT | ✅ | **VM 2/2**。deadlock fix `f4be5f31b`。**BpfReJIT 零 prog_type 限制。** |
| 344 | Daemon 完整重构 | ✅ | 删旧代码 -1622 行，PassManager 架构。**6425 行 / 111 tests**。 |
| 345 | kfunc 发现 + VM module loading | ✅ | `kfunc_discovery.rs`。Commits: `1c281ea`/`7f5d70a`。 |
| 346 | 全量测试 + 4 kernel bug fixes | ✅ | **62/62, 47 applied, 0 mismatch**。修 4 个 kernel bug。Kernel `b4bd737`。 |
| 347 | upstream BPF selftest | ✅ | test_verifier **526/527**（1 FAIL 非 REJIT）。test_progs 109 PASS。 |
| 348 | kernel bug fix 回归测试 | ✅ | 5 回归 PASS。并发 40/40，latency 27μs，78779 REJITs 压力。 |
| 349 | kernel 全面审计+修复 | ✅ | 3 HIGH + 6 MED 全修。Kernel `8a6923893`。报告：`docs/tmp/20260322/kernel_full_audit_20260322.md`。 |
| 350 | kinsn module 重编 | ✅ | 3/3 modules 加载成功。 |
| 351 | micro v2 with kinsn | ✅ | RotatePass **412 sites**。rotate64_hash **20.4% 加速**。报告：`docs/tmp/20260322/micro_analysis_v2_20260322.md`。 |
| 352 | corpus attach_trigger | ✅ | 新增 `runner/libs/attach.py`。 |
| 353 | applied 数下降修复 | ✅ | WideMemPass width=3/5/6/7 skip。121 tests。 |
| 354 | e2e 准备 | ✅ | 5/5 case 可跑。dev: Katran 1.108x, Tracee +8.1%。 |
| 355 | 全部 5 pass apply | ✅ | CondSelectPass/BranchFlipPass/SpectreMitigation。后续 #362 修正算法。 |
| 356 | SpectreMitigation 测试 | ✅ | 18+7 tests。JA+0 是 placeholder（真 barrier 在 #382）。 |
| 357 | bpftrace 复杂 tools | ✅ | 6 个 upstream tools 替换简单脚本。Commit `6933ee3`。 |
| 358 | v2 全量评估 | 🔄 | micro **1.153x**（62/62, 49 applied）。corpus/e2e 待重跑。 |
| 359 | Recompile overhead | ✅ 见 #491 | daemon ~2ms + REJIT ~13ms。 |
| 360 | Policy sensitivity 输入变体 | 待做 | predictable/random 变体，支撑 Insight 2。 |
| 361 | VM bias 调查 | 待做 | control 有 7.8% phantom speedup。 |
| 362 | Daemon P0 算法修复 | ✅ | branch_flip/cond_select/rotate/liveness 4 项修复。**147 tests**。Commit `ae76f1b`。 |
| 363 | Daemon P1 集成修复 | ✅ | BTF kind/fd_array/PGO/dead code。Commit `0c650f0`。 |
| 364 | Daemon serve 子命令 | ✅ | Unix socket server，JSON 协议。Commit `4df4922`。 |
| 365 | Tests 目录重组 | ✅ | 删 40+ debug scripts。4 层结构。Commit `a68a79a`。 |
| 366 | Kernel bug 回归测试 | ✅ | **VM 9/9**。含 struct_ops multi-slot。Commit `ca5aa66`。 |
| 367 | docs/tmp 按日期归档 | ✅ | ~250 文件归到 6 个日期目录。Commits `94c3ce2`/`3373251`。 |
| 368 | Corpus measured_pairs 修复 | ✅ | vng --rwdir + kinsn auto-load。0→94 measured。Commit `7a5009e`。 |
| 369 | Daemon code review | ✅ | 3 CRITICAL + 8 HIGH，全在 #362-363 修复。报告：`docs/tmp/20260322/daemon_code_review_20260322.md`。 |
| 370 | vm-micro-smoke 全覆盖 | ✅ | 62 bench smoke（ITER=1, WARM=0, REP=50）。 |
| 371 | Corpus 54 unmeasured | ✅ | 8 新 attach 类型。measured 91→152。 |
| 372 | Makefile vm-selftest 接入 unittest | ✅ | unittest/ 6 个测试文件接入。 |
| 373 | kinsn module 重编 | ✅ | 3/3 x86 modules。Commit `9e6eb3d`。 |
| 374 | Daemon post-fix review | ✅ | 5/11 完整、3/11 部分、3/11 未修。报告：`docs/tmp/20260322/daemon_postfix_review_20260322.md`。 |
| 375 | Daemon 7 issues 全修复 | ✅ | cond_select/rotate/fd_array/PGO/annotation remap 等。**187 tests**。 |
| 376 | 缺失 pass 覆盖分析 | ✅ | ENDIAN_FUSION **1386 sites**（最高）、EXTRACT 542。 |
| 377 | ExtractPass 增强 | ✅ | +9 edge case tests。**196 tests**。 |
| 379 | 全项目架构审查 | ✅ | 报告：`docs/tmp/20260322/full_project_review_20260322.md`。 |
| 380 | ENDIAN_FUSION 实现 | ✅ | x86 MOVBE + arm64 LDR+REV + daemon EndianFusionPass。+22 tests。 |
| 381 | Module UB + cross-arch 修复 | ✅ | extract/rotate UB fix。ARM64 ROL 统一。全部 UNSPEC。 |
| 382 | 真实 Spectre barrier | ✅ | x86 LFENCE + arm64 DSB+ISB kinsn。**224 tests**。 |
| 383 | kinsn common header | ✅ | `DEFINE_KINSN_MODULE` 宏，10 modules 简化 ~300 行。 |
| 384 | PGO 闭环实现 | ✅ | profiler→ProfilingData→BranchFlipPass 完整数据流。**224 tests**。 |
| 385 | e2e case_common 提取 | ✅ | `e2e/case_common.py`，5 case 去重。 |
| 386 | scanner→daemon 全量清理 | ✅ | 25 文件命名统一。 |
| 387 | 5 infra 架构修复 | ✅ | module/load_all.sh、VM_INIT 宏、daemon path 统一。 |
| 388 | Daemon serve 接入 pipeline | ✅ | kernel_runner.cpp Unix socket client。 |
| 389 | Makefile 全自动 pipeline | ✅ | kernel defconfig + kinsn-modules 依赖链。 |
| 390 | Makefile 大重构 | ✅ | 759→335 行（-56%）。 |
| 391 | 5 dead code 接线 | ✅ | verifier_log/HotnessRanking/PlatformCapabilities/module_fds/AnalysisCache。**229 tests**。 |
| 392 | kernel 改动总结 | ✅ | 22 文件，净增 ~1300 行。5 组件。 |
| 393 | sudo 全量清理 | ✅ | 29 文件删 sudo。VM 内已是 root。 |
| 394 | deprecated CLI 清理 | ✅ | 删 --daemon-path、recompile_v5→blind_apply 等。 |
| 395 | Corpus 54 unmeasured 实现 | ✅ | 8 新 attach 类型。measured 91→152。 |
| 396 | Fuzz + adversarial tests | ✅ | fuzz 10000 轮 + adversarial 23 tests。 |
| 397 | Verifier-guided rollback | ✅ | TransformAttribution + failure PC 提取。**240 tests**。 |
| 398 | Verifier differential verification 调研 | 📝 | **方案 B（per-pass LOAD+log_level=2 对比）最佳**。报告：`docs/tmp/20260322/verifier_differential_verification_research_20260322.md`。 |
| 399 | v1 policy 文件系统清理 | ✅ | 删 policy.py(553行) + corpus/policies/(582文件)。 |
| 400 | Verifier log ENOSPC 修复 | ✅ | 快速路径 log_level=0，失败时 16MB。 |
| 401 | Split BTF name_off 修复 | ✅ | 7/7 kfuncs 发现成功。 |
| 402 | CPU freq scaling bias 修复 | ✅ | daemon idle 降频。修复后 geomean 0.654→1.059x。 |
| 403 | Corpus applied=2 调查 | 🔄 | 152 measured 只 2 applied。 |
| 404 | E2E 3 bug 修复 | ✅ | persist_results + scx bpftool + katran CONFIG_NET_IPIP。 |
| 407 | Transform trace observability | ✅ | 结构化 `OptimizeOneResult`。runner JSON 嵌入。**246 tests**。 |
| 408 | kinsn BTF 常量修复 | ✅ | `BPF_BTF_GET_NEXT_ID` 22→23。`CONFIG_DEBUG_INFO_BTF_MODULES=y`。 |
| 409 | Map fd bit extraction 修复 | ✅ | `regs & 0x0f` → `(regs >> 4) & 0x0f`。修复 60/152 REJIT 失败。**256 tests**。 |
| 410 | PMU counters 接入 profiler | ✅ | `perf_event_open` 采集 branch_misses。**251 tests**。 |
| 411 | BranchFlip fallback + PGO warmup | ✅ | no PMU data → skip。`--pgo-warmup-repeat`。**265 tests**。 |
| 412 | 死代码/过时脚本清理 | ✅ | 删 v1 policy tests。**256 tests**。 |
| 413 | Daemon 测试缺口补充 | ✅ | +19 tests。含 kernel header BPF cmd 常量验证。**265 tests**。 |
| 414 | Mock test 审计 | ✅ | 6 HIGH + 8 MEDIUM。报告：`docs/tmp/20260323/daemon_mock_test_audit_20260323.md`。 |
| 415 | 修复全部 14 个测试问题 | ✅ | 发现 rotate/cond_select/extract 真实 bytecode 不匹配。 |
| 416 | Pass pattern matcher 修复 | ✅ | RotatePass 反向 OR、CondSelectPass Jcc+1、caller-saved save/restore。**303 tests**。 |
| **417** | **⚠️ kinsn operand-encoded ALU 设计（2026-03-23）** | ✅ 设计完成 | **核心 novelty**：kinsn 不是函数调用，是自定义 ALU 指令。dst_reg 编码操作数，off 编码常量，verifier 只 mark dst_reg modified + narrow_result 回调恢复精度。每个 kinsn 替换都是 N→1 指令，零开销。**关键**: 这是论文 kinsn 机制的核心贡献 — 如何让 verifier 正确建模平台特定内联指令。设计报告：`docs/tmp/20260323/kinsn_register_design_20260323.md`。 |
| 418 | kfunc verifier 机制调研 | ✅ | 无现成 clobber 控制。报告：`docs/tmp/20260323/kfunc_verifier_mechanisms_20260323.md`。 |
| **419** | **⚠️ bpf_kinsn_ops 完整设计（2026-03-23）** | ✅ | codex 调研。独立 sidecar `struct bpf_kinsn_ops`（不扩展 btf_kfunc_id_set）。`model_call()` 返回声明式 `bpf_kinsn_effect`（input_mask + clobber_mask + result range/tnum + mem_accesses），不暴露 bpf_reg_state。packed ABI 用 sidecar pseudo-insn（不复用 off 字段）。endian_load 改 const void*。KF_KINSN 替代 KF_INLINE_EMIT。设计报告：`docs/tmp/20260323/kinsn_ops_design_20260323.md`。 |
| **420** | **kinsn_ops 完整实现** | ✅ | **53/62 applied, 1612 sites**（rotate 701, extract 524, endian 256）。vm-selftest **70/70 PASS**。Commit `8c1dd22`。Review：`docs/tmp/20260323/kinsn_implementation_review_20260323.md`。 |
| 421 | SIMD kinsn module | 🔄 | **设计报告见 #472g**。x86 SIMD 不做（FPU 开销），ARM64 NEON 条件性 Phase 2。 |
| 422 | Frozen map inlining | ❌ 不做 | 真实 workload 无显式 freeze。报告：`map_inlining_opportunity_analysis_20260323.md`。 |
| 423 | **Dynamic map inlining + invalidation** | ✅ | ARRAY 全消除 + HASH speculative inline + invalidation tracker。**设计报告见 #472a**。 |
| 424 | Verifier-assisted const prop | 🔄 | v1 已落地（`const_prop.rs`），verifier log 版待做。**设计报告见 #472b**。 |
| 425 | vm-micro 正确性验证 | ✅ | **53/62 applied, 0 mismatch**。kinsn pass 生效。 |
| 426 | vm-corpus 正确性验证 | ✅ | 152 measured, **56 applied**（14x 提升）。0 mismatch。 |
| 427 | vm-e2e 正确性验证 | ✅ | 4/5 PASS（katran timeout）。 |
| 428 | Kernel code review | ✅ | 2 CRITICAL + 3 HIGH。报告：`docs/tmp/20260323/kernel_code_review_20260323.md`。 |
| 429 | Packed ABI 验证 | ✅ | rotate/extract ✅。endian offset 需修（#430）。 |
| 430 | endian packed + 删 legacy ABI | ✅ | 全部走 packed。删 legacy emit。**296 tests**。Commit `5e10be2`。 |
| 431 | Kernel CRITICAL/HIGH 修复 | ✅ | uapi 头同步、fd_array_cnt 上限、module 引用。 |
| 432 | katran HTTP server 修复 | ✅ | 归入 #435。Commit `a57e41f`。 |
| 433 | LFENCE/BPF_NOSPEC 消除 | 🔄 | **设计报告见 #472c**。 |
| 434 | 全面优化调研 | ✅ | 3 份报告：`docs/tmp/20260323/comprehensive_optimization_survey_20260323.md` 等。 |
| 435 | E2E 真实应用模式 | ✅ | katran xdpgeneric + retry。**5/5 PASS**。 |
| 436 | 删除 E2E manual fallback | ✅ | 删 `manual.py`（-244 行）。Commit `174bfe5`。 |
| 437 | Katran post-REJIT correctness bug | ✅ | HTTP server 行为问题（非 REJIT bug）。Commit `a57e41f`。 |
| 438-440 | endian packed / legacy ABI / packed tests | ✅ | 归入 #430。 |
| 441 | Kernel CRITICAL/HIGH 修复 | ✅ | 同 #431（重复条目）。 |
| 442 | 冗余 bounds check 消除 | 🔄 | **调研报告见 #472d**。 |
| 443 | DCE pass | ✅ | `dce.rs`：unreachable block + NOP cleanup。设计：`docs/tmp/20260324/verifier_constprop_dce_design_20260324.md`。 |
| 444 | skb_load_bytes 特化 | ✅ | `SkbLoadBytesSpecPass`。TC only, len≤8。Commit `bf0742d9540f`。报告：`docs/tmp/20260324/helper_call_inlining_research_20260324.md`。 |
| 445 | Spill/fill 消除 | ❌ | 内核已有 KF_FASTCALL。 |
| 446 | kinsn 设计文档 | ✅ | `docs/kinsn-design.md`（1097 行）。Commit `5e10be2`。 |
| 447 | Daemon debug logging | ✅ | `--debug` per-pass dump。299 tests。 |
| 448 | Corpus 测量 bug 修复 | ✅ | daemon-socket 模式下 stock sample 缺失。 |
| 449 | bpftrace 脚本修复 | ✅ | 语法适配 v0.20.2。 |
| 450 | Tetragon e2e 修复 | ✅ | kprobe→tcp_connect。 |
| 451 | Tracee e2e 修复 | ✅ | setup.sh 重写。 |
| 452 | Kernel 完整审计 v2 | ✅ | **1437 LOC**。2 HIGH + 5 MED 新发现。报告：`docs/tmp/20260323/kernel_full_review_20260323.md`。 |
| 453 | Kernel HIGH 修复 | 待做 | refresh 吞错误 + dead code。 |
| 454 | 干净环境性能重跑 | 待做 | 串行 strict params。 |
| 455 | Recompile overhead | ✅ | daemon ~2-5ms + REJIT ~3-7ms。见 #491 详细。 |
| 456 | ARM64 QEMU 测试 | 待做 | vm-arm64-selftest + smoke。 |
| 457 | WideMemPass packet pointer fix | ✅ | XDP/TC skip 非 R10 base。+7 tests，**350 tests**。 |
| 458 | Corpus single-VM batch | ✅ | 单 VM + daemon serve 全程常驻。删 per-target VM 路径。 |
| 459 | micro_exec keep-alive | ✅ | stdin JSON-line 模式。BTF 只加载一次。micro 13.5min→3-4min。 |
| 460 | Daemon 静态验证 pipeline | ✅ | 342 程序→48 applied→340 accepted。`make vm-static-test`。 |
| 461 | BCC corpus 扩展 | ✅ | +34 条目（16→50）。 |
| 462 | BCC e2e case | ✅ | 8 个 tool，真实 binary。 |
| 463 | kinsn v2 instantiate 设计 | ✅ | 报告：`docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`。 |
| 464 | Paper submodule + 清理 | ✅ | Commits `91a2be3`/`329ef17`。 |
| 465 | VM 管理设计 | ✅ | 报告：`docs/tmp/20260323/vm_management_design_20260323.md`。 |
| 466 | Benchmark 框架 review | ✅ | 五大瓶颈。#458/#459 解决前两个。 |
| 467 | **Runner 统一第三方 repo 控制面** | 🔄 | `runner/repos.yaml` + fetch(`fetch_corpus_repos.py`) + build(`build_corpus_objects.py`) + Make 薄封装均已落地。bcc/scx 消费层已迁。**剩余**：其余消费层硬编码路径 + 遗留旧路径清理。 |
| 468 | Corpus 补全 | ✅ | +61 条目。~60→~155。 |
| 469 | Runner infra 全量验证+提速 | 🔄 | `make all`/`check` ✅。VM 全量通过（static-test/micro/corpus/e2e）。debug artifact 默认关闭后 micro 154→119s，corpus 703→514s。 |
| 470 | Runner VM/机器调度控制面 | 🔄 | `machines.yaml` + `with_vm_lock.py` 自动排队串行 + Makefile 薄封装。端到端验证通过。**剩余**：QEMU/AWS SSH backend adapter + e2e/run.py VM 路径迁移。 |
| 471 | benchmark 死代码清理 | ✅ | 删 v1 helpers。Commits `d3879ba`/`3b98b53`/`eeef9f4`。 |
| 472 | **未实现优化深度调研** | ✅ | 8 份设计/调研报告全部完成，均在 `docs/tmp/20260324/`：(a) `dynamic_map_inlining_design`、(b) `verifier_constprop_dce_design`、(c) `lfence_nospec_elimination_design`、(d) `bounds_check_elimination_research`、(e) `128bit_wide_loadstore_research`、(f) `addr_calc_lea_research`（**14 sites，ROI 低**）、(g) `simd_kinsn_design`、(h) `helper_call_inlining_research`（`skb_load_bytes` 最可行）。 |
| 473 | Related Work survey | ✅ | → `docs/tmp/20260324/related_work_comprehensive_analysis_20260324.md` |
| 474 | **Map Inlining + Const Prop + DCE（论文核心）** | 🔄 | MapInlinePass v0(ARRAY)+v1(struct/HASH speculative) + ConstPropPass(ALU/分支折叠) + DCEPass(unreachable+NOP) + `MapInvalidationTracker`(serve/watch 1s 轮询，commit `eb9b5fe`) 全部落地。Pipeline: `map_inline → const_prop → dce`。**11556 lookup sites；Katran -91%；Tetragon -99.6%**。corpus 72 applied, **exec geomean 0.854x**（+17%）。Katran BPF **+8.8%**。设计：`docs/tmp/20260324/dynamic_map_inlining_design_20260324.md` + `docs/tmp/20260324/verifier_constprop_dce_design_20260324.md`。**剩余**：474g verifier-assisted map classification（log_level=2 自动识别常量 key/map type/value layout）。474h frozen map ⏸。 |
| **475** | **kinsn 统一到 kfunc 路径** | 📝 设计完成 | 消除平行子系统，统一到 `KF_KINSN` + `PSEUDO_KFUNC_CALL`。净减 ~150-260 行 kernel。报告：`docs/tmp/20260325/kinsn_kfunc_unification_research_20260325.md`、`docs/tmp/20260325/kinsn_kfunc_unification_codex_research_20260325.md`。**待做**：(1) 10 module 补 kfunc stub + daemon 切 FUNC discovery；(2) verifier/JIT `KF_KINSN` 旁路 + normalize shim；(3) 删旧 `kinsn_tab`/`register_bpf_kinsn_set()`/独立 JIT dispatch。 |
| **476** | **测试基础设施 + bug 修复（2026-03-25/26）** | ✅ | **测试**：rejit_swap(5) + rejit_verifier_negative(4) + rejit_pass_correctness(16) + retval check + fuzz(1000) + ARM64 53 pass。**Bug 修复**：daemon const_prop/map_inline/DCE 3 个 + 内核 metadata 竞态/null deref/swap 遗漏/smp_wmb 4 个。**验证**：vm-selftest x86 **13 suites ALL PASSED**；vm-micro **62/62 0 mismatch 1591 sites**。**残留 P1**：swap one-way copy + find_call_site 单匹配。报告：`docs/tmp/20260325/kernel_remaining_bugs_20260325.md`、`kernel_patch_strict_final_review_20260325.md`、`arm64_test_results_20260325.md`。 |
| **477** | **框架死代码清理（2026-03-26）** | ✅ | 删除 ~1314 行死代码：(1) corpus 删除所有 mode 概念（tracing/perf/code-size/packet），`driver.py` 直接调用 `packet_main()`，不再需要 mode 参数。(2) 删除 `runner/libs/attach.py`（860 行，全仓库无引用）。(3) 删除 `micro/driver.py --rejit` 无效 flag。(4) 清理 unused imports。**验证**：vm-micro 62/62 0 mismatch ✅；corpus 764 targets 471 compile 292 measured 113 applied ✅。**审查报告**：`docs/tmp/20260326/corpus_modes_audit_20260326.md`、`docs/tmp/20260326/benchmark_framework_dead_code_audit_20260326.md`。**注意**：`make vm-corpus` 通过 Makefile/runner 包装层有 output 截断问题，但 `python3 corpus/driver.py` 直接跑正常。 |
| **477** | **REJIT subprog kallsyms kernel panic** | ✅ | swap 后 `INIT_LIST_HEAD_RCU()`（+10 行）。**217 applied / 576 accepted / 0 crash**。报告：`docs/tmp/20260325/rejit_kallsyms_crash_report_20260325.md`。 |
| 478 | WideMemPass provenance filter | ✅ | `is_likely_packet_ptr()` 回扫。只跳真正 packet pointer。351 tests。 |
| 479 | 测试基础设施统一 | ✅ | wildcard 自动发现 `rejit_*.c`。vm-all 加 vm-static-test。 |
| 480 | Corpus 全 prog type 覆盖 | ✅ | YAML **131→764 条目**，覆盖 **2019/2019 程序 100%**。**764 targets / 471 compile / 292 measured / 113 applied**。 |
| 481 | QEMU 8.2.2 TCG crash + 9.2.2 升级 | ✅ | QEMU bug（非内核）。源码编译 9.2.2。200 轮零 segfault。报告：`docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md`。 |
| 482 | const_prop typed LD_IMM64 修复 | ✅ | 不再折叠 `src_reg != 0` 的 LD_IMM64。340 tests。 |
| 484 | 内核代码 4 轮审阅 | ✅ | **2935 行 patch**，7 必修 HIGH + 4 误报 + 1 新发现。报告：`docs/tmp/20260325/kernel_review_opus_final_20260325.md`、`docs/tmp/20260326/kernel_final_verdict_opus_20260326.md`。 |
| 490 | 未调研 pass 补全 | ✅ | 6 份报告（`docs/tmp/20260326/`）：subprog inline(**834** 调用点)、tail-call(**537** sites)、helper firewall(**91034** 调用)、corpus 统计(**568** obj/**2019** prog)、live patching(**31**/45 CVE)、权限收紧。 |
| **498a** | Bounds check merge (#442) — 设计文档 | ✅ | codex 补充实现级设计文档 → `bounds_check_merge_design_20260326.md` |
| 498 | **Bounds check merge (#442)** | ✅ | `BoundsCheckMergePass` 设计→TDD→实现→review。**14/14** tests。Commit `639926cb28e9`。设计：`docs/tmp/20260326/bounds_check_merge_design_20260326.md`。 |
| 498 | **skb_load_bytes spec (#444)** | ✅ | `SkbLoadBytesSpecPass` 设计→TDD→实现→review。**14/14** tests。Commit `bf0742d9540f`。设计：`docs/tmp/20260326/skb_load_bytes_spec_design_20260326.md`。 |
| 498 | **Bulk memory kinsn** | ✅ | `BulkMemoryPass` 设计→TDD→实现→review。**16/16** tests。Commit `958bab4528b2`。设计：`docs/tmp/20260326/bulk_memory_pass_design_20260326.md`。 |
| 498 | **Dynamic map invalidation (#474f)** | ✅ | `MapInvalidationTracker` 设计→TDD→实现→review。**12/12** tests。Commit `eb9b5fe`。设计：`docs/tmp/20260326/dynamic_map_invalidation_design_20260326.md`。 |
| 498 | **危险 helper 防火墙** | ✅ | `DangerousHelperFirewallPass` 设计→TDD→实现→review。**13/13** tests。Commit `ca020c4`。设计：`docs/tmp/20260326/dangerous_helper_firewall_design_20260326.md`。 |
| 498 | **BPF 漏洞热修复** | ✅ | `LivePatchPass` 设计→TDD→实现→review。**14/14** tests。Commit `750adfa`。设计：`docs/tmp/20260326/live_patch_pass_design_20260326.md`。 |
| 498 | **3 个 kinsn modules** | ✅ | `bpf_ldp.c`(ARM64) + `bpf_bulk_memory.c`(x86+ARM64)。Commit `d29d9b6427ab`。报告：`docs/tmp/20260326/arm64_bpf_ldp_module_report_20260326.md`、`x86_bpf_bulk_memory_module_report_20260326.md`、`arm64_bpf_bulk_memory_module_report_20260326.md`、`kinsn_modules_review_20260326.md`。 |
| 499 | Serve per-request pass selection + profiles | ✅ | 请求级 `passes` 覆盖 + `benchmark_config.yaml` + 5 个 cascade 集成测试。**448 tests**。Commit `2872554`。报告：`docs/tmp/20260326/serve_per_request_passes_report_20260326.md`、`benchmark_config_report_20260326.md`、`cascade_integration_test_report_20260326.md`。 |
| 491 | Recompile overhead 分解 | ✅ | **daemon ~2ms + REJIT ~13ms + PGO ~500ms**。摊销门槛 646x-226140x 次执行。报告：`recompile_overhead_analysis_20260326.md`。 |
| 492 | Scalability 测量 | ✅ | O(N) **~15ms/prog**。62 progs 579ms。报告：`scalability_memory_overhead_analysis_20260326.md`。 |
| 493 | Memory overhead | ✅ | kernel orig_prog_insns **10.21 MiB**/2019 progs。daemon RSS **9.97 MiB**。报告同 #492。 |
| 500 | map_inline 真实 VM 零命中修复 | ✅ | 真实 clang bytecode pattern 更复杂。Katran `xdp_pktcntr` 命中。**454 tests**。Commit `e658335`。报告：`map_inline_final_fix_report_20260326.md`。E2E capture Tracee+Tetragon **20 fixtures**。 |
| 501 | Corpus 结果分析 | ✅ | `764/442/315/130`。security pass 混入导致 1.239x 回归→已配 `active: performance`。报告：`corpus_results_analysis_20260326.md`。 |
| 502 | Corpus 覆盖 + map 初始化调研 | ✅ | **568 obj / 2073 prog，覆盖 97.7%**。推荐 E2E capture fixture 方案。报告：`corpus_coverage_and_map_init_investigation_20260326.md`。 |
| 503 | Daemon runtime 数据架构分析 | ✅ | 3 个缺陷（invalidation 未接入/PGO 缺 per-PC/非 JVM deopt）。报告：`daemon_runtime_data_architecture_20260326.md`。 |
| 504 | map_inline→const_prop→DCE 级联测试 | ✅ | 5 个集成测试。Commit `2872554`。 |
| 505 | SIMD/FPU kinsn 深度调研 | ✅ | x86 SIMD 不做（FPU ~200-800 cycles）。ARM64 NEON 条件性 Phase 2。报告：`simd_fpu_kinsn_deep_research_20260326.md`。 |
| 506 | Corpus YAML v2 重构 | ✅ | object-centric schema **477 obj / 2019 prog**。Commit `d9a5e94`。设计：`corpus_yaml_restructure_design_20260326.md`。 |
| 507 | E2E map state capture | ✅ | v2：从 daemon response 提取 `inlined_map_entries`。Tracee 13 + Tetragon 7 = **20 fixtures**。Commit `bdc11ca`。 |
| 508 | map_inline 性能验证 | 🔄 | **3 真实命中**。Katran insns **-45%**, JIT **-47%**; Tracee insns **-11%**。exec_ns 在 timing floor。报告：`map_inline_performance_validation_20260326.md`。 |
| 509 | Daemon testcase review | ✅ | 276/283 手写 BpfInsn。报告：`daemon_testcase_review_real_bpfo_20260326.md`。 |
| 510 | Corpus naming 统一 | ✅ | 764 条目加 `name`。Commit `ed9588f`。 |
| 511 | Daemon testcase 迁移真实 .bpf.o | ✅ | 全 15 pass，44 个真实 .bpf.o 测试。**513 tests**。Commit `79586a2`。 |
| 512 | Map fixture replay | ✅ | C++ runner `--fixture-path`。支持 PROG_ARRAY/map-in-map FD 翻译。Commit `9876557`。 |
| 513 | map_inline emit + const_prop fixed point | ✅ | MOV_IMM 替代 LD_IMM64。fixed point 最多 5 轮。Commit `c8b18f3`。 |
| 514 | map_inline inline 统计 | ⏸ | katran fixture 2 sites 命中。 |
| 515 | Daemon 简化 + E2E pass plumbing | ✅ | 删 --pgo/-passes（**-335 行**）。E2E 统一 `benchmark_performance_passes()`。报告：`map_inline_debug_status_20260327.md`。 |
| **494** | **Fixed kernel peephole baseline 对比** | 待做 | `jit-fixed-baselines` 分支 vs BpfReJIT v2 在同样 benchmark 上的 A/B 对比。支撑 "userspace policy > fixed heuristic" 论点。 |
| 483 | 宿主频繁重启 | 📝 | Intel 285K 过热（`-j24` + QEMU TCG）。降并行度。 |
| 491 | REJIT hotswap 压力测试 | ✅ | **11/12 PASS**（ext FAIL=kernel bug #506）。12 prog_type 各一个压测。Commit `24f480d`。报告：`hotswap_test_review_20260326.md`。 |
| 494 | Fixed kernel peephole baseline 对比 | 待做 | `jit-fixed-baselines` 分支 A/B 对比。 |
| 495 | BPF 程序生命周期分析 | 待做 | 证明 post-load 优化有价值。 |
| 496 | K2/Merlin/EPSO 量化对比 | 待做 | head-to-head 跑数据。K2 有开源。 |
| 497 | ARM64 性能数据 | 待做 | 论文需至少一组 ARM64 数据。 |
| 506 | 内核 Known Limitation：EXT REJIT | 📝 | `bpf_tracing_link_release()` 清 `dst_prog`。eval 无影响。修复方案 `ext_rejit_fix_proposal_20260326.md`（~70-100 行）。 |
| 516 | map_inline PERCPU_ARRAY 等值槽 | 🔄 | PERCPU_ARRAY per-CPU slots 全一致时 inline。Tetragon **1→2** site。Tracee 仍 0（dynamic key）。**517 tests**。 |
| 517 | Katran 热路径静态分析 | ✅ | `balancer_ingress`（**23872 xlated / 13654 jited / ~218.7ns**）。**66 map 引用**。先攻 `ctl_array/ch_rings/reals`。 |
| 520 | Katran live e2e 真值 | 🔄 | BPF **229→225ns (1.016x)**。wide_mem+endian 6 sites。map_inline 0 hit。 |
| 519 | map_inline corpus 0-hits 根因 | 🔄 | BCC 全 HASH+动态 key。报告：`map_inline_root_cause_analysis_20260327.md`。 |
| 518 | Tracee fixture replay 修复 | 🔄 | stale map_id→live fd 重映射。inner-map fixture 仍缺。**523 tests**。 |
| 521 | Katran `inlined_map_entries` null fix | 🔄 | rejit.py null→空数组。map_inline 仍 0 hit（key>8B/non-load uses）。 |
| 522 | Katran corpus EINVAL 修复 | ✅ | prepared-run 复用 compile-only 输入→改重新 materialize_memory()。 |
| 523 | E2E/Corpus request-level pass 收口 | 🔄 | daemon serve request-level `enabled_passes`。6 E2E case 统一。**540 tests**。 |
| 526 | map_inline 全面增强 + .rodata | ✅ | PERCPU fallback + PSEUDO_MAP_VALUE + verifier-guided key + .rodata（BCC **169** sites）。**540 tests**。 |
| 527 | Katran REPEAT=50 可信度审查 | ✅ | **<100ns ktime 不可信**。REPEAT=500+。报告：`katran_perf_credibility_analysis_20260327.md`。 |
| 528 | Corpus 构建方式调研 | ✅ | **429/1213 成功 (35%)**。531 include path 失败。报告：`corpus_build_analysis_20260327.md`。 |
| 524 | Katran 定向 corpus 真值 | ✅ | map_inline only: **exec_ns 14→7 (2.000x)**。sites_found=64, applied=7。报告：`katran_map_inline_perf_results_20260327.md`。 |
| 529 | map_inline fixpoint + Katran 40-site | 🔄 | fixed-point 迭代。Katran `sites_applied 40`，`const_prop 29`。wall_exec **-17%**。 |
| 530 | Katran 20-byte key + stack-slot tracking | 🔄 | 任意长度 key + stack-slot 常量追踪。Katran **41/105** sites，wall_exec **-23.6%**。 |
| 531 | 任意长度 constant-key | 🔄 | wall_exec_ns **-23.6%**，exec_cycles **-23.6%**。JIT `13645→13573`。 |
| 532 | lookup-result spill/fill 跟踪 | 🔄 | **1.714x**→correctness 回归→回退。`total_sites_applied 180`。JIT **-5.7%**。 |
| 533 | Katran spill/fill correctness 复核 | 🔄 | **1.714x 是假阳性**（mutable writeback + spill alias 过长）。安全版本 2 sites，无 runtime 收益。 |
| 534 | Corpus warmups 配置接线修复 | ✅ | `warmup_repeat` 透传修复。之前默认 5 warmups 扭曲数据。 |
| 535 | Tracee inner-map fixture + Katran warmup-fixed | 🔄 | Tracee inner-map capture+replay 落代码。Katran `total_sites_applied=2`，runtime 0.671x（无收益）。 |
| **536** | **Tetragon `func_info` blocker 已清除，single-pass rerun 与 static-verify pass 透传补齐（2026-03-27）** | 🔄 | **内核修正**：`vendor/linux-framework/kernel/bpf/syscall.c` 现在对带 `btf + func_info` 的程序统一预填充 REJIT metadata，并在 `free_tmp` 失败路径补上 `tmp->aux->btf` 的 `btf_put()`，避免扩大后的 metadata preload 引入 BTF 引用泄漏。**最小 correctness**：`make vm-shell ... rejit_pass_correctness ... T17_tracepoint_subprog` ✅，`missing btf func_info` 不再出现，也没有新 guest panic/oops。**Tetragon 单-pass rerun 真值**：`map_inline` artifact `e2e/results/tetragon_20260328_033535/metadata.json`、`const_prop` artifact `e2e/results/tetragon_20260328_033915/metadata.json`、`dce` artifact `e2e/results/tetragon_20260328_034137/details/result.json`。当前结论已从“泛化 post-verify EINVAL”收紧为三条独立 blocker：`map_inline` 旧 metadata blocker 已消失但仍未成功 apply；`const_prop` 在 active `event_execve` 上报 `unreachable insn 230`；`dce` 在 active path 上报 `call unknown#195896080` / `R4 !read_ok`。三轮 preflight 里 `execve_rate` 都还是冷的（`run_cnt_delta = 0`），真正活跃的是 `event_execve`。**harness 基建**：`daemon/tests/static_verify.py` + `runner/src/batch_runner.cpp` 现支持 `static_verify_object` 透传 `enabled_passes`，因此 `make vm-static-test STATIC_VERIFY_ARGS='--filter bpf_execve_event --max-objects 1 --enabled-passes map_inline'` 已可作为 single-pass correctness smoke；首轮结果 `verifier_accepted=3/3, applied=0`，说明这条 harness 能验证 pass-isolated correctness plumbing，但不能替代带 live map state 的 e2e 单-pass 数据。下一步集中在 `map_inline` 对 callback/static-subprog 边界的保守化和 Tetragon `event_execve` 的 pass-specific verifier 调试。 |
| **537** | **Tetragon `map_inline` tail-call guard 收口 + corpus attach blocker 显性化（2026-03-27）** | 🔄 | **实现**：`daemon/src/passes/map_inline.rs` 新增 tail-call helper guard，当前对包含 `bpf_tail_call` 的程序直接保守 `no_change`，避免继续触发 kernel `poke_tab update failed: -22`；并补回归测试到真实 Tetragon fixture。**验证**：`make daemon-tests` ✅、`make daemon` ✅。**e2e 新真值**：artifact `e2e/results/tetragon_20260328_041603/details/result.json`，`event_execve` 与 `execve_rate` 都从“旧的 apply/rollback 失败”收敛成干净 `no_change`，共同 skip reason 是 `program contains bpf_tail_call helper; map_inline is disabled until poke_tab-preserving rewrites land`；preflight 仍显示 `event_execve run_cnt_delta=7501`、`execve_rate=0`。**corpus 新真值**：artifact `runner/corpus/results/vm_corpus_20260328_041923/details/result.json`，用 `PROFILE=ablation_map_inline_only FILTERS='bpf_execve_event'` 只选中 `tetragon:bpf_execve_event.bpf.o` 的 3 个 program，但 `compile_pairs=3, measured_pairs=0`，baseline/rejit 全部失败在 `bpf_program__attach failed: Invalid argument`。**结论**：当前 Tetragon `map_inline` 的 e2e blocker 已不再是 REJIT 失败，而是保守禁用；corpus 侧的主 blocker 则收敛成 generic attach 对 `event_execve` family 的 `EINVAL`，后续 `const_prop` / `dce` 的单-pass rerun 主要是在补齐独立 artifact，runtime 数据要等 attach 面修通。 |
| **538** | **Tetragon corpus 单-pass matrix 补齐：`map_inline` / `const_prop` / `dce` 全部收敛到同一 attach blocker（2026-03-27）** | 🔄 | **配置补齐**：`corpus/config/benchmark_config.yaml` 新增 `ablation_const_prop_only` 与 `ablation_dce_only`，从而可以像 `ablation_map_inline_only` 一样用 `make vm-corpus` 做真正单-pass rerun。**新 artifact**：`const_prop` → `runner/corpus/results/vm_corpus_20260328_042542/details/result.json`，`dce` → `runner/corpus/results/vm_corpus_20260328_042647/details/result.json`。两轮都沿用 `FILTERS='bpf_execve_event'`，结果与前面的 `map_inline` corpus 真值完全一致：`selected_objects=1`、`selected_programs=3`、`compile_pairs=3`、`measured_pairs=0`、`applied_programs=0`，三个 program（`execve_rate` / `execve_send` / `event_execve`）的 baseline/rejit 全都失败在 `bpf_program__attach failed: Invalid argument`。**结论**：当前 Tetragon `bpf_execve_event` 的 corpus 线已经没有”哪条 pass 还没独立跑”的空白了；三条单-pass artifact 一致证明，主阻塞不是 pass-specific rewrite，而是 generic attach 无法挂起 `event_execve` family，所以下一阶段该修 attach 路径，而不是继续盲跑更多 corpus ablation。 |
| **539** | **安全 pass 从评估范围移除（2026-03-28）** | ✅ | `benchmark_config.yaml` 删除 `security` 组（`dangerous_helper_firewall`/`live_patch`/`speculation_barrier`）。plan doc §3.2 标记为「⏸ 暂不评估」。§1.9 四种用途只有性能优化是 OSDI 主线。代码保留在 daemon 中供 future work。 |
| **540** | **Tetragon `const_prop` folded JA offset bug 修复（2026-03-28）** | ✅ | **根因**：`const_prop` 把恒真条件分支折叠成 `JA` 后，没有按 `addr_map` 重新计算 offset；如果同一轮折叠把中间指令扩成 `LD_IMM64`，`JA` 的 `off` 就 stale → verifier `jump out of range` → `Permission denied`。**修复**：新增 `fixup_folded_jumps()`，专门修 const_prop 新生成的 taken-branch `JA`。回归测试 `const_prop_fixups_folded_jump_after_ldimm64_growth`。`make daemon-tests` 499 pass。报告：`tetragon_permission_denied_fix_20260328.md`。 |
| **541** | **E2E pass 控制面统一（2026-03-28）** | ✅ | **根因**：`runner/libs/rejit.py` 的 `benchmark_rejit_enabled_passes()` 只看环境变量或硬编码默认值，没有读 `benchmark_config.yaml`。Katran 等 case 走 `daemon apply` 时用了全量 pipeline（混入 `wide_mem`/`endian_fusion`）。**修复**：`rejit.py` 新增 `_benchmark_config_enabled_passes()` 从 YAML 读 active passes，所有 E2E case 统一走同一 pass 集。 |
| **542** | **Daemon 质量修复：静默吞错/归因/CLI/pass 别名（2026-03-28）** | ✅ | **(1)** 错误传播：`bpf_prog_get_map_ids` / `relocate_map_fds` / `iter_prog_ids` / `MapInfoAnalysis` 全部改为向上传播，禁止 `unwrap_or_default()` / `.ok()`。**(2)** rollback 归因：从整段程序覆盖改为 per-pass diff 真实变更 PC 范围。**(3)** CLI：删除全局 `--list-passes`/`--no-rollback`，`--no-rollback` 下沉到 REJIT 子命令。删除 `pipeline_profile`。**(4)** pass 别名：serve/policy 传未知 pass 名报错，不再静默 no-op。`make daemon-tests` 503 pass。报告：`daemon_quality_fixes_20260328.md`。 |
| **543** | **E2E 首次全量结果（2026-03-28）** | ✅ | 6 case 全部 PASS。Katran BPF **-4.5%**/throughput **+1.8%**/p99 **-2.2%**（最佳）。BCC geomean **0.983x**，map_inline=183/const_prop=300/dce=2674。Tracee app throughput +11.5%/+6.8%。Tetragon `event_execve` **Permission denied**（#540 已修）。bpftrace 无 ReJIT 数据。scx 2/13 apply（889 sites）。报告：`e2e_full_run_results_20260328.md`。 |
| **544** | **Corpus 分析（2026-03-28）** | ✅ | **最后全量 run (3/26)**：764/442/315/130，exec geomean 0.807x（不可信——security pass 污染 + 138 个无 pass 程序也有 1.249x 回归）。**map_inline = 0**（3/26 在 #526 增强前跑的）。**当前无 post-#523 权威全量数字**。报告：`corpus_results_analysis_20260328.md`。 |
| **545** | **map_inline 零命中调查（2026-03-28）** | ✅ | 全量 run 的 0 hit 是 stale artifact。离线扫描：764 程序中 148 个有 map_lookup，2432 sites，保守 preflight 212 个候选。**安全 coverage 从 41 掉到 2 的元凶**：mutable writeback guard 是程序级 map veto——同一 map 上某 site 有写回，所有 site 一起禁。verifier-guided key extraction 代码有了但实际 `no verifier states available`。报告：`map_inline_corpus_zero_hit_investigation_20260328.md`。 |
| **546** | **仓库一致性审查（2026-03-28）** | ✅ | 3 HIGH：benchmark_config.yaml 引用不存在的 security pass（已修 #539）、`enabled_passes=[]` 语义不一致、macro_corpus.yaml 引用 8 个不存在的 .bpf.o。5 MEDIUM：E2E JSON 无统一 schema、术语漂移、pass 解析重复、根 Makefile 不 thin、profiler 旧路径。报告：`repo_consistency_review_20260328.md`。 |
| **547** | **Daemon 代码质量审查（2026-03-28）** | ✅ | 3 HIGH：rollback 归因退化（已修 #542）、branch_flip 默认启用但永远 skip、`--list-passes` 不可用（已修 #542）。5 MEDIUM：pass 别名不生效（已修 #542）、REJIT 错误字符串协议、静默吞错（已修 #542）、enumerate 缺 prog_type、serve 测试极少。God files：map_inline.rs 5134 行。报告：`daemon_code_quality_review_20260328.md`。 |
| **548** | E2E post-fix 重跑 | ✅ | **全部 6 case ok**（tracee/tetragon/katran/bcc/bpftrace/scx）。Tetragon 不再 Permission denied。E2E 结果目录：`e2e/results/*_20260328_18*/`。 |
| **549** | Corpus 覆盖率瓶颈分析 | ✅ | **关键发现**：(1) build 失败 76% 是 asm/types.h 缺失。(2) 当前 v2 partial run 已有 334 applied（不是旧的 130）。(3) prepared-state 失败 308 个是 object-level load 先失败。(4) compile_only 226 个天生不可测。(5) attach 失败 91 个需要专用 handler。报告：`corpus_coverage_bottleneck_analysis_20260328.md`。 |
| **550** | Daemon 架构文档 | ✅ | 1476 行中文完整架构文档 `docs/daemon-architecture.md`。 |
| **551** | Daemon post-fix review | ✅ | HIGH: rollback attribution 跨 pass 坐标不稳定。MEDIUM: 空白字符串绕过校验、invalidation polling 错误丢弃。const_prop jump fix 缺 backward/JMP32 测试。报告：`daemon_post_fix_review_20260328.md`。 |
| **552** | E2E + corpus 代码 review | ✅ | CRITICAL: E2E 把失败伪装成 skipped。HIGH: enabled_passes=[] 语义不一致、corpus daemon 启动脆弱、blind_apply 未接线。报告：`e2e_corpus_code_review_20260328.md`。 |
| **553** | 测试重组 + unwrap_or_default 修复 | ✅ | 4 个空测试文件已填充（bulk_memory/cond_select/wide_mem/real_bpfo）。unwrap_or_default 收紧（bpf.rs/commands.rs/elf_parser.rs）。daemon-tests **510 pass / 0 fail / 13 ignored**。 |
| **554** | compile_only 清理 + prepared-state 调查 | ✅ | compile_only 从 66 降到 17（剩余有原因注释）。prepared-state 根因是 object-level load 先失败，不是 ref 映射错。batch_runner 已改进错误透传。报告：`compile_only_and_prepared_state_fix_20260328.md`。 |
| **555** | asm/types.h build 修复 + attach 调查 | ✅ | 构建脚本注入 vendor/linux-framework arch-specific UAPI include。验证通过。attach 根因是 generic `bpf_program__attach()` 缺专用 handler。报告：`build_and_attach_fix_20260328.md`。 |
| **556** | K2 + fixed-baseline 对比方案 | ✅ | K2 开源可用，需 pre-load .bpf.o 输入。fixed-baseline 分支 `jit-fixed-baselines` 可用。报告：`k2_and_baseline_comparison_plan_20260328.md`。 |
| **557** | Ablation 设计 + bpftrace 调查 | ✅ | ablation matrix 设计完成（7 个 profile）。bpftrace 0 ReJIT 根因已识别。报告：`ablation_and_bpftrace_investigation_20260328.md`。 |
| **558** | Static verify post-build | ✅ | **531 objects / 1241 programs / 345 applied / 345 verifier accepted**。报告：`post_build_fix_static_verify_20260328.md`。 |
| **559** | Corpus dev run（performance-only pipeline） | ✅ partial | **288/469 objects**（在 test_map_init.bpf.o segfault exit 139）。**648 compile / 483 measured / 364 applied**。exec geomean **0.980x**。map_inline=465, const_prop=635, dce=458。linux-selftests **0.874x**（快 14%），Katran **0.919x**（快 8%），calico **1.125x**（慢 12.5% 回归）。报告：`corpus_dev_full_results_20260328.md`。 |
| **560** | 死代码 + 垃圾测试清理 | ✅ | cargo build 0 warnings, 507 tests pass / 0 ignored。Python pyflakes 干净。corpus/modes.py 旧 v1 helper 删除。 |
| **561** | 全仓库静默失败 + 安全 pass 清理 | ✅ | 安全 pass .rs 文件已删。enabled_passes=[] 语义统一（C++ `enabled_passes_specified` flag）。E2E skip→error。json_parser fail-close + socket 30s 超时。 |
| **562** | Daemon CLI serve-only + PGO 接线 | ✅ | 删除 watch/apply/apply-all/enumerate/rewrite 五个子命令。保留 serve 作为唯一入口。PGO 接到 serve --pgo，branch_flip 不再 always-skip。Python 统一走 serve socket。**净删 -1418 行**。 |
| **563** | corpus/modes.py 重构 | ✅ | **3085 → 689 行**（-78%）。逻辑下沉到 runner/libs/（rejit.py + corpus.py + results.py + vm.py）。pytest 34 pass。 |
| **564** | Runner C++ 去重 | ✅ | 新建 json_parser.cpp + daemon_client.cpp + bpf_helpers.cpp 三个共享模块。kernel_runner -491 行，batch_runner -547 行，**合计 -1038 行**。make runner + smoke 通过。 |
| **565** | json_parser fail-close + socket timeout | ✅ | 缺 key → fail()。转义引号处理。socket 30s SO_RCVTIMEO/SO_SNDTIMEO。error_message 透传到 response.error。_batch 残留命名清除。 |
| **566** | 5 个 SOSP red flags 修复 | ✅ | (1) micro enabled_passes 传递。(2) daemon docs/tests 更新到 serve-only。(3) module/load_all.sh 失败即退出 + bpf_barrier 移除默认路径。(4) README 删除不存在 target。(5) profiler 路径统一。 |
| **567** | SOSP 架构 readiness review | ✅ | 302 files / 120644 LOC。5 大 red flags（已修 #566）。God files 列表。重复实现分析。artifact 闭环缺失。报告：`architecture_sosp_readiness_20260328.md`。 |
| **568** | Mutable writeback guard site-local | ✅ | 删除程序级 `collect_mutable_maps_with_lookup_value_writes()` veto。改为 per-site r0 use classification 直接判断。同一 mutable map 上只读 site 仍可 inline。507 tests pass。 |
| **569** | bpftrace 0 applied 修复 | ✅ | 根因：bpftrace sites 全是 wide_mem，但 active passes 只有 map_inline/const_prop/dce。修复：benchmark_config.yaml performance 列表加回所有 11 个 performance passes（wide_mem/rotate/cond_select/extract/endian_fusion/map_inline/const_prop/dce/bounds_check_merge/skb_load_bytes_spec/bulk_memory）。 |
| **570** | Corpus 深入分析 + crash 调查 | ✅ | **Top 10 speedup**: security_bpf_map 4.19x（map_inline+const_prop+dce）。**88/255 加速 >1.05x**（但 36 个是 no-change 噪声）。**103/255 回归 <0.95x**（~50 噪声 + ~37 pass-induced）。**Calico 不是代码膨胀**：xlated 不变，native 只 +2-4B，但慢 3-4x（layout perturbation）。**BCC emit bug**: 32-bit 0xffffffff 用 2-slot LD_IMM64。**Crash 根因**：REJIT retry 中 guest segfault（已修 #per-pass verify）。报告：`corpus_deep_analysis_and_crash_20260328.md`。 |
| **571** | E2E + Katran VM 验证（第一轮） | ✅ | **用旧 binary**（mtime 比 E2E 晚）。Tetragon 仍 Permission denied（R4 !read_ok，可能第二个 bug）。Katran map_inline=**6**（site-local veto 生效，但其他原因 skip 了 60+ sites）。BCC geomean **1.023x**。报告：`e2e_and_katran_post_all_fixes_20260328.md`。 |
| **572** | Per-pass verify 重构 | ✅ | 删除 retry loop / attribution / --no-rollback。每个 changed pass 后调 verify callback，失败回退+标记 rejected+继续后续 pass。最终 REJIT 只做一次。**506 tests pass / 0 failed / 0 ignored**。 |
| **573** | PGO socket protocol | ✅ | 删除 --pgo CLI flag。新增 socket 命令：profile-start/stop/save/load。optimize 自动用已有 profile。branch_flip 启用时 Python 自动 start→sleep→stop→optimize。**513 daemon tests pass**。 |
| **574** | E2E case scaffold 去重 | ✅ | run_case_lifecycle() 在 case_common.py。6 个 case 统一生命周期。 |
| **575** | 术语统一 recompile→rejit | ✅ | C++ phase 输出、Python 解析兼容层全改。`make runner` + `make smoke` 通过。 |
| **576** | daemon-architecture.md 更新 | ✅ | 反映 serve-only + PGO socket + per-pass verify + 删安全 pass。1371 行。 |
| **577** | Calico 回归分析 | ✅ | **不是真实回归**：51 applied 中 25 慢 26 快，中位数 1.005。3 次同配置 run geomean 从 0.84→0.80→1.13，连正负号都翻。repeat=50 对 138-150ns 程序不够。 |
| **578** | verifier_retries JSON 兼容修复 | ✅ | daemon_client.cpp optional 解析，缺失时置 0。`make runner` 通过。 |
| **579** | Python test 修复 | ✅ | test_benchmark_rejit_enabled_passes 断言更新到 11 pass 列表。38 python tests pass。 |
| **580** | KVM PMU 调查 | ✅ | **根因**：Arrow Lake 是 Hybrid CPU（P+E core），KVM 硬编码禁用 vPMU（`X86_FEATURE_HYBRID_CPU` → `enable_pmu=false`），modprobe 无法覆盖。替代：`perf kvm stat --guest` 或重编译宿主机内核。 |
| **581** | SOSP paper review (Opus + Codex) | ✅ | **两个 reviewer 一致 Strong Reject / Reject**。致命：eval placeholder、formally verified 无支撑、Section 5 空。核心故事在 framework/kinsn/map-inline 间不收敛。报告：`sosp_paper_review_20260328.md`。 |
| **582** | 回归根因分析 | ✅ | Calico：非代码膨胀，是 layout/branch perturbation。BCC：emit_constant_load 把 32-bit 0xffffffff 用 LD_IMM64。报告：`regression_root_cause_analysis_20260328.md`。 |
| **583** | E2E 最终重跑（最新 binary） | ✅ | **5/6 PASS**：tracee ✅、tetragon ✅（顶层 OK，event_execve 内部 const_prop `unreachable insn 230` + dce `Permission denied` 仍在）、bpftrace ✅、scx ✅、bcc ✅。**Katran ❌**：veth module 加载失败（`modprobe: unknown symbol`），kernel 7.0-rc2 模块符号不兼容，未到 scan/apply。11 passes 均确认。daemon binary mtime 14:37 > E2E start 14:38。 |
| **584** | emit_constant_load fix + Tetragon R4 调查 | ✅ | **Bug 1 已修**：map_inline 替换 LDX_MEM_W/H/B 时用 `MOV32_IMM` 而非 `MOV64_IMM`，避免 0xffffffff zero-extension 语义错误（u32 max → LD_IMM64 2-slot 变成 MOV32_IMM 1-slot）。const_prop ALU32 折叠同理。回归测试覆盖。`make daemon-tests` 通过。**Bug 2 调查**：R4 !read_ok 是 BPF-to-BPF 子程序参数初始化问题（非 map_inline），最新重跑 Tetragon 已 OK。 |
| **585** | perf kvm stat --guest 调研 | ✅ | **结论**：`perf kvm stat` 只看 KVM exits（tracepoint），拿不到 branch_misses/instructions/cycles。**可用方案**：`perf stat -e cycles:Gk,instructions:Gk,branches:Gk,branch-misses:Gk -p <qemu-pid>` 从 host 侧采 guest-kernel PMU 汇总，已实测可用。进一步细到 BPF 程序需 `perf record -e ...:Gk` + guest kallsyms/BPF JIT symbols。报告：`perf_kvm_guest_profiling_20260328.md`。 |
| **586** | 7 个重构 post-review | ✅ | 7 个重构全部正确，无功能缺失。**12 cargo warnings** 全在 profiler.rs（dead code：`ProgStatsPoller`/`HotnessRanking`/`collect_program_profiling` 等未使用）+ bpf.rs `get_orig_insns_by_id` + pass.rs `pc`/`run` + passes/mod.rs `description`/`available_passes_help`。`make daemon-tests` 510 pass。`pytest tests/python/` 38 pass。报告：`post_refactor_review_20260328.md`。 |
| **587** | **Corpus 数据统计审计（2026-03-28）** | ✅ | **关键发现**：(1) `0.980x` 是 crash-truncated partial run（288/469 objects，exit 139），不是完整结果。(2) headline geomean 包含 85 个 `applied=false` 程序（geomean 0.951x），严重稀释 applied-only 的 0.995x。(3) 483 measured 但只有 255 个有 `speedup_ratio!=null`（228 个 exec_ns=0）。(4) applied=364 但只有 170 进入 geomean（74 无 measured pair + 120 exec_ns=0）。**修复建议**：主指标改为 `applied-only comparable geomean`（本次 0.995x / 170 samples）；必须同时报 sample count；crash run 不能当 authoritative。**真实漏斗**：2009 programs → crash 截断 1149 → prepared ok 648 compile → 483 measured → 255 comparable → 170 applied comparable。报告：`corpus_data_statistics_review_20260328.md`。 |
| **588** | Profiler 接线 + cargo warnings 消除 | ✅ | optimize-all 接入 hotness ranking（有 snapshot 按 hotness 排序，没有先做 stats observation window）。branch_flip 数据链路通了（profile snapshot → ProfilingData → branch_miss_rate）。**12 cargo warnings 全部通过实际使用消除**（不是删除）。`make daemon` 0 warnings，`make daemon-tests` 509 pass。**未做 VM live profiling 验证**。 |
| **589** | Corpus 覆盖率修复 + 完整重跑 | ✅ partial | codex 被杀（太慢）。代码修复已 commit（results.py applied-only geomean）。完整 run 由 #608 接力。 |
| **603** | E2E 6/6 全部修复 + 正面数据 | ✅ | **6/6 PASS + 正面数据**：Tracee exec_storm +3.09%/file_io +1.71%，Katran 吞吐 +1.78%/p99 -1.57%/BPF 1.022x，BCC geomean 1.015x（从 0.883x 修复），bpftrace 1.140x，scx hackbench +54.6%，Tetragon pass 但 post-ReJIT 不可比。 |
| **604** | BCC 0.883x 回归修复 | ✅ | **根因**：map_inline+const_prop 后留大量死定义残渣（mov32→ldimm64→mov64 循环），native code 不缩 → layout 扰坏。**修复**：DCE 加 fixed-point 死寄存器定义删除，保留 pseudo_func。daemon-tests 520 pass。 |
| **605** | Build toolchain 并发安全 | ✅ | kernel-build + kinsn-modules 加 flock(.cache/kernel-build.lock)，原子完成 config+bzImage+modules+hostfs。daemon/runner 不受锁影响。 |
| **606** | Tracee 回归修复 + Tetragon 超时 | ✅ | Tracee：放宽后 branch-target 冲突 skip 整个 site → 改 fallback to load-only。Tetragon：stop_agent() timeout 覆盖主错误 → 修错误传播。daemon-tests 517 pass。 |
| **607** | OSDI benchmark 框架 review | ✅ | **Reject / Not evaluation-ready**。P0：repeated paired trials、CPU pin+governor、K2 对比、fixed peephole baseline、469 objects 完整 run。P1：Tracee/Tetragon 提升到 Katran 方法学。报告：`benchmark_framework_osdi_review_20260328.md`。 |
| **608** | Corpus 完整 469 objects 迭代跑 | 🔄 | Round 1：431/469 完成，剩 38 长尾 objects。前 26 objects applied-only geomean **1.0156**。 |
| **609** | AWS ARM64 benchmark（t4g.micro） | ✅ | **真实硬件数据**：llvmbpf gap **0.616x**（55/62 赢），BpfReJIT 49/62 applied，123/123 sites。Katran smoke rejit_applied=True 16/16 sites。实例已 terminate。 |
| **610** | AWS x86 benchmark（t3.micro） | ✅ | **修复 3 次后成功**：ENA/VIRTIO builtin + SELinux + dracut。62/62 benchmark 完成。kernel 7.0-rc2+ confirmed。实例已 terminate。commit `5eed9d6` + `dc6c436`。 |
| **611** | Fixed kernel peephole baseline 分析 | ✅ | Fixed peephole scanner ceiling 14049 sites。BpfReJIT userspace-only 14833 sites（8.5x applied）。Fixed peephole 不能替代：无 map_inline/const_prop/PGO/adaptive policy。CMOV 有明确负例。报告：`fixed_peephole_baseline_analysis_20260328.md`。 |
| **612** | K2 对比框架 | ✅ | K2 geomean 0.736x vs BpfReJIT 0.629x。K2 只 7/15 objects 有效 patched ELF，只支持 XDP/TC。BpfReJIT 覆盖所有 prog_type。报告：`k2_comparison_setup_20260328.md`。 |
| **613** | Tracee E2E 方法学增强 | ✅ | Control→baseline→post_rejit same-image paired，warmup+5 轮采样，event throughput/detection latency/app overhead，Bootstrap CI + paired significance test。 |
| **614** | Daemon 生命周期优化 | ✅ | Corpus/Micro 已是 session 级。E2E 修复：scan+apply 复用单 daemon session。pytest 28 pass。 |
| **615** | Per-program policy + pass-regression 分析 | ✅ | 选择偏差问题确认：不同程序比较不是因果。const_prop only 1.031 vs triple 0.977 是不同程序群体。 |
| **593** | ARM64 交叉编译 + QEMU test | ✅ | `vm-arm64-smoke` ✅、ARM64 kinsn modules **6/6** 加载、`rejit_poc` **6/6** 全过。rotate/select/endian/bulk_memcpy/ldp/stp/extract 可工作。cross-build 修了 ncurses 依赖 + daemon CMake→Cargo。报告：`arm64_test_20260328.md`。 |
| **600** | attach-trigger 修复 + auto-trigger | ✅ | **增强**：主 trigger 后 run_cnt 没涨时按 section 做 auto-trigger 补扫（exec/process/sched/file/mm/network）。放宽静态判定：kprobe/raw_tp/fentry/lsm/tp_btf 不再提前排除。**效果**：attach-trigger 静态可测集合 **111 → 1060/1536**。pytest/make runner/make smoke 通过。报告：`attach_trigger_fix_20260328.md`。 |
| **602** | Pass 覆盖率调查 | ✅ | **27.8% 是假低**：旧 run daemon 中途 crash，后续程序全 connect refused。修复 daemon stderr headline + Makefile KERNEL_BUILD_STAMP 后，真实覆盖率 **595/1241 = 47.9%**。Per-pass：const_prop 489、dce 404、map_inline 294。skb_load_bytes_spec 只 1 site（len>8 skip）。报告：`pass_coverage_investigation_20260328.md`。 |
| **601** | map_inline 不必要限制 review | ✅ | 3 个放宽（宽 key split-store + contiguous proxy + use-classifier helper/CFG）。daemon-tests 517 pass。**但 E2E 效果有限**：Katran 6→6 不变，Tracee 1→0 反降。真实程序的 HASH key 大多是动态的（从 packet/context 计算），放宽 pattern matcher 不能解决根本问题。报告：`map_inline_relaxation_20260328.md`。 |
| **599** | HASH map aggressive inline 实现 | ✅ | 对 HASH/LRU_HASH 纯标量 use site 允许全消除（lookup + null check + null path 一起删）。`make daemon-tests` **514 passed**。**但真实程序效果有限**：katran_balancer 2318→2318、tracee_sys_enter 3731→3731 — 大多数 HASH site 不满足严格条件（宽 key/非连续 setup/需要 pointer）。E2E 未跑（VM lock 被 corpus 占）。 |
| **598** | map_inline → const_prop → dce 级联分析 | ✅ | **核心结论**：级联发生但效果太小。大多数命中只做 "value load 常量化 + 局部折叠 + 删 1-2 NOP"，没有"消除整个代码路径"。**根因**：HASH/LRU_HASH（占真实程序大多数）保留 lookup call + null check，只替换 value load → 改动太少被噪声淹没。**ARRAY map** 可以 full inline（删 lookup + null check），但 corpus 中 ARRAY 占比低。**改进方案**：(1) HASH guard+fallback 全消除模式（用常量 key guard 跳过 lookup）(2) 更强 const_prop（跨基本块）(3) branch threading。报告：`cascade_analysis_20260328.md`。 |
| **616** | lkm_seeker EINVAL fix | ✅ | **根因**：`BPF_PROG_LOAD` verify 缺 `prog_btf_fd`/`func_info`/`line_info`/`attach_btf_id`/`attach_fd`/`prog_name`。修复 `bpf_prog_load_meta_from_prog_info()` 完整提取 metadata。daemon-tests **527 pass**。 |
| **617** | kinsn module 证据加入 E2E artifact | ✅ | `run_case_lifecycle()` 记录 kinsn module 快照（loaded/failed/discovery log），写入 `metadata.kinsn_modules`。pytest 55 pass。 |
| **618** | Corpus exit 1 根因 | ✅ | guest `RLIMIT_NOFILE` 未提到 65536。bulk prepare codex 已修（`ulimit -HSn 65536` + `--nofile`）。 |
| **619** | Smart trigger 设计 | ✅ | 8 类 category，P1（syscall_specific+cgroup+socket+block）覆盖 96/214=45%，P2 65%，P3 100%。工程量 7-11 天。报告：`smart_trigger_design_20260329.md`。 |
| **620** | Map inline 覆盖差距 | ✅ | 17321 lookup → 1629 命中（9.4%）。三大 blocker：动态 key 5264（35.9%）、不支持 map type 3959（27.0%）、非标量 load 2883（19.6%）。报告：`map_inline_coverage_gap_20260329.md`。 |
| **621** | Corpus measured=0 gap | ✅ | 不是 kernel 不支持，是 loader 模型错。tracee/scx/KubeArmor/tetragon 应用 app-native loader。报告：`corpus_measured_gap_analysis_20260329.md`。 |
| **622** | E2E 性能瓶颈分析 | ✅ | lkm_seeker EINVAL 是最大阻塞（已修 #616）。Katran 19 insns 是上限不是 bug。kinsn modules 缺观测证据（已修 #617）。报告：`e2e_performance_blockers_20260329.md`。 |
| **623** | Per-repo app-native loader | 🔄 | codex 在跑。tracee/scx/tetragon/KubeArmor 用原始 loader。 |
| **624** | Verifier-in-the-loop 实现 + review | ✅ | **实现完成**（+713/-147 行，7 文件）：bpf.rs accept 时 log_level=2 抓 success log + 自适应扩容；verifier_log.rs 升级解析 exact scalar/tnum/32-64 bit/spill/speculative；const_prop.rs 优先用 verifier exact constants，fallback 本地传播；pass.rs accept 后刷新 verifier_states。**Review 修 2 个问题**：seed capture 扩到所有程序（不只 map_lookup）；超大 log 退化改 visible warning。**534 tests pass**。报告：`docs/tmp/20260329/verifier_in_the_loop_review_20260329.md`。 |
| **625** | **LLVM IR map_inline 可行性调研** | ✅ | **结论：可行，推荐 hybrid 方案**。保留 kinsn pass 在 BPF 层，map_inline+const_prop+DCE 走 LLVM IR 子路径。`llvmbpf` lifter 覆盖大部分 BPF 指令，已有 array-map inline 实现可证明路线正确。**最大风险**：verifier 兼容性（lifted IR 缺 PTR_TO_CTX/loop-bound/pointer provenance）。不需要改 LLVM BPF backend（第一阶段）。**时间线**：1 周窄 POC，2 周接入 daemon，1 个月工程化。827 行报告：`docs/tmp/20260329/llvm_ir_map_inline_feasibility_20260329.md`。 |
| **626** | Corpus pipeline 3 bug fix | 🔄 | (1) 单 object libbpf 错误不应 kill 整个 batch；(2) guest batch 部分失败时已收集数据应聚合；(3) verifier log 289MB bloat（daemon response 不应输出 log 原文）。codex 在修+重跑。 |
| **627** | ARM64 native cross-build + AWS rerun | ✅ | cross-arm64-build.sh 改 native cross-compile（不再 QEMU 模拟）。t4g.micro **62 micro, 50 applied, 126 sites**。Katran smoke **23 sites applied**。corpus 仍 exit=1（batch runner 问题）。结果：`.cache/aws-arm64/results/benchmark_20260329_200533/`。 |
| **628** | E2E/corpus 质量 review + 清理 | 🔄 | 检查死代码、旧配置、零静默失败、功能正确性。codex 在跑。 |
| **597** | Per-program pass selection YAML policy | ✅ | **YAML policy 格式**：`default.passes` + `rules`（按序匹配 `prog_type`/`repo`/`has_sites`，`passes`/`enable`/`disable` 语义）。`has_sites` 条件基于 daemon 预扫描 site counts。**改动**：rejit.py（policy 解析+matching）+ corpus.py（per-program REJIT job）+ modes.py + benchmark_config.yaml（默认 policy scaffold）。Daemon 不改。向后兼容。pytest **45 passed**。报告：`per_program_policy_design_20260328.md`。 |
| **596** | ARM64 bulk_memset bug fix | ✅ | **3 个修复**：(1) `module/arm64/bpf_bulk_memory.c` BPF_W 校验错误。(2) `kernel/bpf/verifier.c` `restore_kinsn_proof_regions()` stale `insn_aux_data` 指针（`bpf_patch_insn_data` 后未更新→内存破坏/Oops）。(3) `INSN_BUF_SIZE` 32→256（bulk-memory proof sequence 截断）。ARM64 QEMU 回归 **3/3 PASS**。报告：`arm64_bulk_memset_fix_20260328.md`。 |
| **595** | Pass-regression 关联分析 | ✅ | **核心发现**：`const_prop` only geomean **1.031**（热程序 1.154），是最佳默认启用候选。`const_prop+map_inline+dce` 三连 geomean **0.977**（热程序 0.952），是风险组合。回归集中在 bcc kprobe/tracing 程序。回归不是 code bloat（很多 native 变小仍更慢），是 layout/I-cache perturbation。**Policy 建议**：const_prop 默认开，map_inline+dce profiling-gated，kprobe/tracing 更保守。报告：`pass_regression_analysis_20260328.md`。 |
| **594** | map_inline correctness 形式化 | ✅ | 完整 contract 文档。支持 ARRAY/PERCPU_ARRAY/HASH/LRU_HASH。HASH-family 保留 null guard（speculative）；ARRAY-family key 静态 in-range 可删 lookup。Mutable site site-local writeback guard。Invalidation: 1s polling → re-REJIT from original。**关键边界**：并发 map update 有 bounded stale window（eventual rollback，非 synchronous deopt）。与 JVM 差异：polling vs trap-on-access。报告：`map_inline_correctness_contract_20260328.md`。 |
| **592** | Tetragon event_execve verifier bugs 修复 | ✅ | **Bug 1 (const_prop)**：branch fold 后 unreachable block 未清 → 修复：fold 后立即清 dead block。**Bug 2 (dce)**：`LD_IMM64 src=BPF_PSEUDO_FUNC` callback subprog 引用未被 CFG/reachability 识别 → callback-only subprog 被删除（116 insns）→ function entry 偏移全错 → R4 !read_ok。修复：insn.rs 加 `BPF_PSEUDO_FUNC` 识别 + cfg.rs/utils.rs pseudo-func 追踪和 fixup。4 个新回归测试。`make daemon-tests` 513 pass。报告：`tetragon_verifier_bugs_20260328.md`。 |
| **590** | kinsn vs kfunc novelty 文档 | ✅ | **核心结论**：(1) "kinsn=kfunc+emit" 不成立：kinsn 有专用 bytecode transport（sidecar+PSEUDO_KINSN_CALL）、proof-lowering verifier path、descriptor-driven native emit、双层降级。(2) **但** "novelty 来自 declarative effect DSL" 在当前代码树也不成立——`bpf_kinsn_effect/model_call()` 未实现。(3) 当前真实 novelty：proof-visible instruction form + packed sidecar + native emit + graceful degradation。(4) **5/11 pass 依赖 kinsn**（rotate/cond_select/extract/endian_fusion/bulk_memory），其余 6 个是纯 bytecode。报告：`kinsn_vs_kfunc_novelty_20260328.md`。 |
| **591** | Katran veth module 修复 | ✅ | **根因**：Makefile `kernel-build` 在 bzImage 存在时跳过重编，导致 guest bzImage 和 hostfs modules 版本不匹配 → veth.ko symbol 不对。**修复**：kernel-build 始终让 kbuild 增量判断 + virtme-hostfs-modules 加 .ko 存在校验。`make vm-e2e TARGET=x86 E2E_CASE=katran` 通过，baseline/post-ReJIT 完整产出。 |

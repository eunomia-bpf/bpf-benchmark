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
> - **⚠️ Unit test 质量标准见 `CLAUDE.md` 的 "Unit Test Quality"**：非必要不加 unit test。新增测试必须能说明失败时定位哪一类 bug。合理测试覆盖逻辑分支、状态变化、计算/转换、边界、错误路径、外部 ABI/layout/序列化约定或 bug 回归。ABI/layout 测试不能只验 `size_of`，必须验字段 offset 或编码格式。禁止 trivial getter/setter、std/upstream lib 行为、自身重言、mock 测 mock、可读性测试、纯 const alias 和重复覆盖率测试。慢测试或真实系统依赖测试应放到集成/端到端层级，不要伪装成 unit test。
> - **bpfopt-suite v3 设计约束见 §4.6，Benchmark 设计约束见 §5.35。**
> **v1 权威数据**（#256 rerun，native-level rewrite 架构）：micro **1.057x** / applied-only **1.193x**；corpus **0.983x**；Tracee **+8.1%**；Tetragon **+20.3%/+32.2%**；Katran BPF **1.108-1.168x**；gap **0.581x**。vm-selftest **35/35**。v1 代码保存在 `v1-native-rewrite` 分支。
> **v2 当前权威数据**（#644，2026-04-02 本地重跑，artifact 时间戳为 2026-04-03 UTC）：benchmark 默认尝试当前全部 in-scope performance passes，报告只统计**实际 applied sites**。`make vm-corpus` **20/20 app ok**，applied-only / all-comparable geomean **1.033x**，applied sample **61**；`make vm-e2e` **6/6 ok**；apply-side site totals：bpftrace **33**、BCC **961**、SCX **359**。`make vm-selftest`、`make vm-test`、`make vm-negative-test`、`make vm-micro-smoke`、`make vm-micro` 全通过。**2026-04-03 再验证**：private-stack 覆盖迁移到 repo-owned tests 后，`make all`、`make check`、`make vm-test` 仍全部通过。
> **2026-04-21/22 Wave 1 后三目标 corpus 权威重跑**（见 #663）：`x86_kvm_corpus_20260421_232916_947372`（30 samples）all-comparable geomean **1.010x**，applied sample **12**，20/20 app ok；`aws_x86_corpus_20260422_012001_472335`（1 sample）**0.983x**，applied sample **10**，20/20 app ok；`aws_arm64_corpus_20260422_044304_037607`（1 sample）**0.986x**，applied sample **10**，20/20 app ok。三目标 `no_programs_changed_in_loader` 统一 **36**。**注意**：该 reason 并非 bytes_jited/xlated same-size gap（`corpus/driver.py:471-540` 根本没比 bytes）。它是命名不准的 observability bucket，混了 "0 site 命中"、"pass 命中但 verifier 全 rollback"、"apply 成功但最终 program_changed=false" 三类情况，属 corpus 侧 taxonomy 过粗，非 apply correctness bug。详情见 #664。

---

## 0. Abstract

eBPF is widely adopted in production for observability, networking, and customizable kernel extensions in modern production systems, yet its current just-in-time (JIT) compilers remain rigid, platform-agnostic, and severely under-optimized compared to mature runtimes such as JVM, WASM, or LLVM. Many optimizations and security hardenings are restricted due to stringent kernel safety constraints and prohibitive implementation complexity. This paper presents BpfReJIT, a dynamic, minimally invasive, and extensible kernel compilation framework that transparently optimizes kernel-resident eBPF programs. Our key insight is a novel, microkernel-inspired separation of concerns that delegates kernel safety guarantees to minimal kernel extensions, allowing lightweight verification and in-place recompilation while offloading correctness and complex optimizations to an extensible userspace CLI toolchain informed by runtime profiling data. We implement BpfReJIT within the Linux kernel with fewer than 600 lines of code modifications, transparently supporting existing eBPF tools, loaders, and subsystems. Evaluation across diverse hardware platforms and representative workloads (network monitoring, security enforcement, and observability tracing) demonstrates that BpfReJIT achieves up to 40% performance improvement, 50% reduction in binary size, and negligible overhead. BpfReJIT provides a practical, upstream-compatible path toward dynamic, extensible compilation frameworks in operating system kernels.

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
> - **用户态 bpfopt-suite**（Unix CLI 工具链）：通过编译 pass 和 shell/file pipeline 定义**"如何优化"**——基于静态分析、平台能力和运行时 profiling 数据（类似 JVM 的动态 JIT 重编译 + PGO）。这是**策略**。
>
> 新优化 = 新 module + bpfopt-suite 更新，零内核改动。这是让 LLVM pass 基础设施成功的可扩展性模型，现在应用到 OS 内核。

#### Insight 3: Safety ≠ Correctness —— 与内核 eBPF 安全模型对齐

> 不同于 JVM 或 LLVM 的编译框架必须同时保证**安全性和正确性**，BpfReJIT **将正确性与安全性分离**，与已有的内核 eBPF 安全模型对齐：
>
> - **内核组件保证安全性**：不会破坏内核。已有的 BPF verifier 对通过 REJIT 提交的任何新 bytecode 提供与 BPF_PROG_LOAD 完全相同的安全保证。不需要编写新的 validator 或证明 pass 的正确性。
> - **用户态工具链负责正确性**：编译变换保持程序语义。如果 pass 或 orchestration 脚本有 bug，程序行为可能改变，但内核安全不受影响（fail-safe）。
>
> 这种分离之所以可能，是因为 BPF 有强制性的 verifier——这是原生内核代码等系统所没有的属性（livepatch 必须完全信任 patch 作者）。这正是 eBPF 特别适合 post-load 可扩展编译框架的原因。

### 1.6 设计目标

1. **可扩展（Extensible）**：最小内核改动（~550 行代码（不含注释）），支持大量 pass。新优化 = 新 module + bpfopt-suite 更新，零内核改动。
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

**组件 3：用户态 bpfopt-suite**
- `bpfopt` 作为零内核依赖的纯 bytecode optimizer，所有 pass 都暴露为 CLI 子命令。
- `bpfget`、`bpfverify`、`bpfprof`、`bpfrejit` 分别承担内核交互：读取 bytecode/metadata、dry-run verify、profile 采集、最终 REJIT。
- `bpfrejit-daemon` 是可选 watch 进程，只触发外部脚本，不嵌入优化 pipeline。

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
| **可更新性** | userspace bpfopt-suite 可随时更新优化策略，无需等 kernel release cycle |
| **上游接受成本** | kernel patch 审核周期长（月~年级），优化逐个上游不现实；BpfReJIT 让优化以 userspace CLI 工具链形式即时部署 |
| **算法迭代** | 优化 pattern 需要反复实验和迭代；kernel 代码一旦合入很难改，userspace 可以快速迭代而不影响 kernel 稳定性 |
| **程序级组合** | 局部有利的变换可能全局有害（I-cache cliff），userspace 做全局预算 |
| **Workload 适应** | 分支可预测性、hot path 等取决于运行时数据分布，不是静态信息 |
| **Fleet 管理** | A/B testing、gradual rollout、per-deployment customization |
| **所有权** | service owner 控制优化策略（Cilium/Katran），不是 kernel maintainer |
| **覆盖面** | kernel JIT 中有数十个可优化点，不可能全部逐一 patch 上游；统一框架一次性覆盖 |
| **安全管理** | 同一框架可做安全加固、恶意程序阻断，不需要单独系统 |

### 1.11 核心设计约束

1. **Safety/correctness 分离**：kernel verifier 保证 safety（内核不崩溃），correctness 由用户态 bpfopt-suite 和 orchestration 脚本负责
2. **Kernel 改动最小化**：核心内核接口只加一次（~550 LOC（不含注释）），新优化/新 arch 全部以 module + CLI 工具方式部署
3. **完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach
4. **零运行时开销**：变换后的程序和原始加载路径完全一样快
5. **Fail-safe**：verify 失败 → 什么都不改，返回错误；per-pass verify 脚本可回滚到上一段已验证 bytecode
6. **BPF_PROG_REJIT 接受完整的新 BPF bytecode**，不是 patch format — `bpfrejit` 提交整段新程序，kernel 走标准 verify 路径
7. **Mandatory Falsification**：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，不是发布 userspace-guided interface
8. **`bpfopt` 零内核依赖**：`bpfopt` 只读写 raw `struct bpf_insn[]` bytecode；所有 raw BPF syscall 都在 `bpfget` / `bpfverify` / `bpfprof` / `bpfrejit` / `bpfrejit-daemon`。
9. **Pipeline 是 shell/file 协议**：stdin/stdout 只传 raw binary bytecode，profile/verifier states/map values/report 等 side-input/output 走文件。
10. **Daemon 可选且薄**：`bpfrejit-daemon` 只 watch 新程序、检测 map invalidation、触发外部脚本；benchmark runner 优先直接调用 CLI 工具，不走 daemon socket。


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
| **BRANCH_FLIP** | 否 | ✅ 已实现 | if/else body 重排。policy-sensitive；默认 benchmark profile 不启用。当前显式启用时仍是 PMU gate + heuristic fallback，而非严格 per-site PGO-only | 非默认 benchmark pass |
| **ENDIAN_FUSION** | 可选 | ✅ 已实现 | load+bswap → combined kinsn → JIT emit MOVBE | 256 sites, 17 corpus applied |
| **Dynamic map inlining** | 否 | ✅ pass 已实现；v3 runtime wiring 待迁移 | JVM deopt 模型：map 稳定 → inline → invalidation → re-REJIT。**论文核心 story** | **11556 个 map_lookup site；Katran 22→2 条（-91%）；Tetragon 447→2（-99.6%）**。v3 目标：`bpfget` 生成 map value side-input，`bpfopt map-inline --map-values ... --report ...` 产出 invalidation hints，薄 `bpfrejit-daemon` 只读取 hints 并触发外部 re-optimize 脚本。设计：`dynamic_map_inlining_design_20260324.md` |
| **Verifier const prop** | 否 | ✅ 已实现 | `log_level=2` → tnum/range 常量 → `MOV imm` → branch folding。verifier-in-the-loop 已接入（#624） | **23% verifier state 含精确常量；62.5% 分支和立即数比较** |
| **DCE** | 否 | ✅ 已实现 | const prop / map inline 后的 unreachable block / dead store 消除 | bpfopt DCE 让更多条件变常量 |
| **Bounds check merge** | 否 | ✅ 已实现 | ~~冗余 check 删除~~ → **guard window merge / hoisting**。合并小窗口为大窗口 | **42 guard sites，严格冗余=0%，但 83.3% 可合并（ladder 结构）**。实现：`BoundsCheckMergePass`。**测试**：`cargo test bounds_check` 14/14、`cargo test` 365 pass/12 ignored、`make daemon`、`make daemon-tests`。**commit**：`639926cb28e9`。调研：`bounds_check_elimination_research_20260324.md` |
| **128-bit LDP/STP** | 是 | ✅ module 已实现 | **ARM64**：相邻 load/store pair → `bpf_ldp128`/`bpf_stp128` kinsn → JIT emit LDP/STP，不碰 FPU。**x86**：pair load/store 用 `two mov` 即可（SSE/AVX 不值得——FPU context 开销远大于收益），bulk memcpy 走 `rep movsb`。**论文 story**：同一优化在不同架构有完全不同的 cost model（ARM64 免费 vs x86 需 FPU），体现 platform-aware kinsn 设计价值 | **ARM64 corpus store 对密度高，当前 JIT 完全没 LDP/STP**。设计：`arm64_ldp_stp_kinsn_design_20260326.md`、`x86_128bit_wide_loadstore_design_20260326.md`。调研：`128bit_wide_loadstore_research_20260324.md`。**module report**：`arm64_bpf_ldp_module_report_20260326.md`。**commit**：`d29d9b6427ab` |
| **Bulk memory kinsn** | 是 | ✅ x86 + ARM64 kinsn modules 已实现 | ~~SIMD~~ → v1 用 `rep movsb/stosb` (x86) / `LDP/STP` (ARM64)，不碰 FPU | **corpus 有 40B/74B/360B/464B 连续 copy/zero run**。设计：`simd_kinsn_design_20260324.md`、`x86_128bit_wide_loadstore_design_20260326.md`。**测试**：`cargo test ... bulk_memory` **16/16**、`cargo test ...` **395 pass / 12 ignored**、`make daemon-tests`。**pass commit**：`958bab4528b2`。**module reports**：`x86_bpf_bulk_memory_module_report_20260326.md`、`arm64_bpf_bulk_memory_module_report_20260326.md`。**module commit**：`d29d9b6427ab`。 |
| **ADDR_CALC (LEA)** | 可选 | ❌ 低优先级 | mov+shift+add → `bpf_lea()` kinsn → JIT emit LEA | **corpus 仅 14 个严格命中 site（全部 tetragon），ROI 很低**。调研：`addr_calc_lea_research_20260324.md` |
| **Helper call specialization** | 否/可选 | 🔄 调研完成 | `skb_load_bytes → direct packet access` 优先（纯 bytecode）；`probe_read_kernel` 需 safe-load kinsn | **590 skb_load_bytes + 25296 probe_read_kernel site。结论：skb_load_bytes 最可行，probe_read 风险高**。调研：`helper_call_inlining_research_20260324.md` |
| **Frozen map inlining** | 否 | ❌ 不做 | BPF_MAP_FREEZE 后只读 map → 常量 MOV | **调研结论：真实 workload 无显式 freeze，hot-path lookup ≈ 0** |
| **Subprog inline** | 否 | ⏸ 不在 OSDI 主线 | bytecode 层展开 subprogram call。**不做原因**：不依赖 runtime info，和论文 "deployment-time runtime-guided specialization" story 不符。**REJIT 元数据 blocker**：UAPI 不接受新 func_info/line_info。834 调用点 / 67 对象(11.8%)。调研：`subprog_inline_research_20260326.md` |
| **Const propagation** | 否 | ↗ 归入 #424 | 利用 frozen map / runtime invariants 做常量折叠 | 归入 verifier const prop |
| **SIMD (FPU)** | 是 | ❌ 不进 OSDI 主线 | **x86 SIMD 不做**：`kernel_fpu_begin/end` XSAVE/XRSTOR 开销 ~200-800 cycles，pair load/store 场景下远超收益；**ARM64 NEON 条件性 Phase 2**：仅 ≥1KiB + `may_use_simd()` 成立时考虑，no-FPU `LDP/STP` 优先。Linux crypto 模式（per-operation fpu_begin/end）不适用于 BPF 的细粒度调用 | **深度调研结论：x86 break-even ≥数百字节且需整次 BPF 调用摊销一次 FPU context；corpus 中绝大多数 copy/store ≤128B，不满足条件**。调研：`simd_fpu_kinsn_deep_research_20260326.md` |
| **Tail-call specialization** | 否 | ✅ 调研完成 | **Phase 1**：dynamic-key monomorphic PIC（guarded constant-key fast path），复用 kernel `map_poke_run()`。**Kernel blocker**：`poke_tab` shape check 需放宽 | **537 sites / 31 对象(5.46%)；Cilium 216、Tetragon 118、Tracee 49；upstream 已有 constant-key direct jump → 论文新意在 dynamic-key PIC；break-even 命中率 ~8%**。调研：`tail_call_specialization_research_20260326.md` |
| **Spill/fill 消除** | 否 | ❌ 不做 | 冗余 spill/fill 消除 | **内核已有 KF_FASTCALL，增量收益低** |
| **POPCNT/CLZ/CTZ** | 是 | ❌ 不做 | corpus 无可支撑的 pattern site。clang 已将 `__builtin_popcount` 展开为高效位操作序列，无循环可替换。调研：`bit_ops_kinsn_research_20260329.md` | 0 site |
| **CRC32** | 是 | ⏸ 不做默认 pass | 仅 loxilb 有真实 CRC32 site（2 个 byte-update），broad corpus 覆盖低。`bpf_csum_diff` 等 helper 更广泛但走 helper 路径。调研：`crc32_kinsn_research_20260329.md` | loxilb 2 site |
| **CCMP** | 是 | 📝 值得做 | **ARM64 独有**。conditional compare chain。**74 个 with-copy site**，restricted first wave。调研：`arm64_kinsn_research_20260329.md` | 74 site |
| **Prefetch** | 是 | 📝 设计完成 | x86 `PREFETCHT0` + ARM64 `PRFM`。纯 hint kinsn，强 runtime-gate（只打开 hot+cache-miss site）。Phase 1：helper-before-lookup。Phase 2：map-inline direct-load。**完美体现 runtime-guided**（fixed JIT 不知道哪个 site 值得 prefetch）。调研：`memory_hints_kinsn_research_20260329.md`。设计：`prefetch_kinsn_design_20260329.md`（841 行）。 | 17391 潜在 site |
| **NT store** | 是 | ❌ 不做 | 当前 corpus 无明确 streaming write 场景。调研：`memory_hints_kinsn_research_20260329.md` | 不值得 |
| **PDEP/PEXT** | 是 | ❌ 不做 | corpus 无 site。调研：`bit_ops_kinsn_research_20260329.md` | 0 site |
| **SHRX/SHLX** | 是 | ❌ 不做 | OoO CPU 上无增量收益。调研：`bit_ops_kinsn_research_20260329.md` | 不值得 |
| **MADD/MSUB** | 是 | ⏸ 低优先级 | ARM64 独有。优先级低于 CCMP。调研：`arm64_kinsn_research_20260329.md` | |
| **UBFX/BFI** | 是 | ⏸ 低优先级 | ARM64 独有。优先级低于 CCMP。调研：`arm64_kinsn_research_20260329.md` | |
| **RDTSC** | 是 | 📝 待做 | x86 `RDTSC`/`RDTSCP` 内联时间戳。比 `bpf_ktime_get_ns()` helper call 快一个数量���。tracing/profiling 场景 | 待调研 |
| **ADC/SBB** | 是 | 📝 待做 | x86 `ADC`/`SBB` 128-bit 算术。IPv6 地址操作、crypto | 待调研 |
| **SETcc/CSET** | 是 | 📝 待做 | x86 `SETcc` + ARM64 `CSET`。比较结果直接存 0/1，不需要 branch+mov。和 CMOV 不同：CMOV 条件赋值任意值，SETcc 专门设置 boolean。BPF 里极常见（`if (x > 0) flag = 1`） | 待调研 |
| **ANDN** | 是 | 📝 待做 | x86 BMI1 `ANDN`（`a & ~b` 一条指令）。mask 操作常见 | 待调研 |
| **BLSI/BLSR/BLSMSK** | 是 | 📝 待做 | x86 BMI1 isolate/reset/mask lowest set bit。bitmap 操作 | 待调研 |
| **除法强度削减** | 否 | 📝 待做 | 常量除数 → shift+multiply trick。DIV 40 cycles → 3 cycles。纯 bytecode 变换，需要 verifier const prop 提供常量。**完美体现 runtime-guided** | 待调研 |
| **PAUSE/YIELD** | 是 | ❌ 不做 | x86 `PAUSE` + ARM64 `YIELD`。内核 BPF spin lock helper 内部已有 PAUSE/WFE，kinsn 无增量价值。调研：`pause_yield_kinsn_research_20260329.md` | corpus 中几乎无 BPF-level busy-wait |
| **寄存器重分配** | 否 | 📝 待做 | BPF 10 个寄存器的 liveness 分析→callee-saved 重分配（R6-R9）减少 spill/fill。纯 bytecode 变换。bpfopt 已有 liveness 分析能力 | 待调研 |
| **REJIT spill-to-register** | kernel 机制 | 📝 设计完成 | REJIT 接受可选 reg_map，`bpfrejit` 提交 spill slot → native register 映射。**x86 只剩 R12**（1 个），**ARM64 有 x23/x24**（2 个）。Verifier 不需要改。分阶段：ARM64 先做 → x86 → 可配置 reg_map。调研：`rejit_register_mapping_research_20260329.md`（790 行） | |
| **Region kinsn（寄存器扩展）** | 是 | 📝 待做 | 高寄存器压力的代码段包装为 region kinsn，emit callback 内部用 native 寄存器。需要 `model_call()` 支持 | 待调研 |

### 3.2 安全加固变换（暂不在 OSDI 评估范围）

> **2026-03-28 决定**：安全相关 pass（speculation_barrier、dangerous_helper_firewall、live_patch、权限收紧）暂不纳入当前评估和 benchmark pipeline。代码保留供 future work 引用，但不在默认 pipeline 中启用，也不在 benchmark_config.yaml 中配置。

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
│  Component 3: bpfopt-suite v3                                │
│  Defines "HOW to optimize" — Unix tools + shell/file pipeline│
│                                                              │
│  bpfget → bpfopt pass(es) → bpfverify → bpfrejit             │
│              ↑               ↑             ↑                │
│          target/profile   verifier     final REJIT           │
│          JSON side files   states       syscall              │
│                                                              │
│  Optional: bpfrejit-daemon watches events and triggers       │
│            external scripts. It does not run passes.         │
└───────┬────────────┬────────────┬───────────────┬────────────┘
        │            │            │               │
   GET_NEXT_ID  GET_ORIGINAL  PROG_LOAD     PROG_REJIT
        │            │            │               │
┌───────▼────────────▼────────────▼───────────────▼────────────┐
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

### 4.2 bpfopt-suite v3 工作流

v3 是 CLI-first / Unix-pipeline-first。Pipeline 属于 shell，不属于 daemon 或内部 framework。

```
1. bpfget PROG_ID              → 输出原始 raw bytecode；--full 可输出 metadata/side-input files
2. bpfopt PASS                 → 从 stdin 读 raw struct bpf_insn[]，向 stdout 写 raw bytecode
3. bpfverify --prog-type TYPE  → BPF_PROG_LOAD dry-run；通过则透传，失败则报错
4. bpfrejit PROG_ID            → BPF_PROG_REJIT；kernel re-verify → re-JIT → image swap
```

典型 pipeline：

```bash
bpfget 123 | bpfopt wide-mem | bpfopt rotate --target target.json | bpfverify --prog-type xdp | bpfrejit 123
```

### 4.3 安全模型

```
Safety（kernel 保证）：
  verifier 验证新 bytecode → 内核不会崩溃/信息泄露/提权
  和 BPF_PROG_LOAD 完全相同的安全保证

Correctness（用户态工具链负责）：
  bpfopt pass 和 orchestration 脚本确保变换保持程序语义
  手段：differential testing、per-pass verify、gradual rollout、auto-rollback
  用户态变换有 bug → 程序行为可能变 → 但内核安全不受影响（fail-safe）
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

### 4.6 bpfopt-suite v3 设计约束

权威设计文档是 `docs/tmp/bpfopt_design_v3.md`。本文档中任何 bpfopt/daemon 设计都必须服从 v3。

实现层把 v3 §6 中原本分开的共享库与 CLI 收敛为单一 `bpfopt` crate（同时提供 lib + bin）；其余工具和 crate 边界仍按 v3 设计推进。

- **CLI-first，6 个工具**（#646 后续方向）：`bpfopt`、`bpfverify`、`bpfprof`、`bpfget`、`bpfrejit`、`bpfrejit-daemon`。`bpfopt` 同时提供 workspace-internal library API 和 CLI 入口。
- **`bpfopt` 是纯 bytecode CLI**：零内核依赖；stdin/stdout 传 raw `struct bpf_insn[]` binary；`--target`、`--profile`、`--verifier-states`、`--map-values`、`--report` 等 side-input/output 全部走文件。
- **kernel-facing 功能拆到独立 CLI**：`bpfget` 读取 live program bytecode/metadata/side-input；`bpfverify` 做 `BPF_PROG_LOAD` dry-run 和 verifier states；`bpfprof` 采集 profile；`bpfrejit` 做最终 `BPF_PROG_REJIT`。
- **daemon 是 socket-to-CLI 适配进程**：保留 socket + JSON 协议，watch 新程序、检测 map invalidation、维护 session 生命周期，并在收到 optimize/rejit/profile/discover 请求时 fork+exec CLI（`bpfopt`、`bpfget`、`bpfrejit`、`bpfverify`、`bpfprof`）。daemon 不跑 pass pipeline、不维护 `PassManager`、不做 profiling、不解析 `verifier_log`、不做字节码变换。
- **Per-pass verify loop 由 bash/runner 脚本实现**：每个 pass 产生 candidate bytecode 后调用 `bpfverify`，通过则接受，失败则保留上一段 bytecode。最终只调用一次 `bpfrejit`。**禁止为此修改内核代码**。
- **Verifier-in-the-loop 仍保留**：`bpfverify --verifier-states-out` 解析 verifier log，生成 `verifier-states.json`，再作为 `bpfopt const-prop --verifier-states` 的 side-input。
- **安全 pass 不在 OSDI 范围**：`speculation_barrier`、`dangerous_helper_firewall`、`live_patch` 不在默认 pipeline。
- **结构化 per-pass 记录**：每个 program 的每个 pass 必须记录 `pass`/`changed`/`sites_applied`/`insn_delta`/`verify_result`/`verify_error`/`action`。v3 中这些记录由 CLI `--report` 文件和 runner 汇总产生。
- **Benchmark runner Python 保持不动**：v3 迁移采用 §8 方案 B，`runner/libs/`、`corpus/`、`e2e/`、`micro/` 继续走 daemon socket + JSON 稳定边界；daemon 内部适配到 CLI。v3 迁移期只允许 runner bug fix 和 stale test data 更新。

#### Fail-fast 原则：禁止 dead code / fallback / silence

`CLAUDE.md` 的 **Fail-Fast: No Dead Code, Fallback, or Silenced Errors** 是当前实现约束：能力缺失、syscall/IO/parse 失败、无法生成完整结果时都必须 exit 1 并向 stderr 给出友好错误，不能用降级路径、空结果或 warning 继续掩盖问题。所有 fn、struct、字段、常量都必须有真实调用方；`#[allow(dead_code)]` 标注对象要删除，test-only helper 改用 `#[cfg(test)]`。当前已知违反点包括 `bpfget --target` fallback empty kinsns，必须改成缺能力时失败。`bpfprof` PMU 当前 nullable + `pmu_available` 形态会把能力缺失编码成 partial result，也必须改成 fail-fast。`kernel-sys` 旧 `prog_load_dryrun` / `map_get_next_id` wrapper 没有真实调用方，应删除而不是保留兼容层。`BpfInsn` 的 `#[allow(dead_code)]` helper 要改成 `#[cfg(test)]` 或删除，`PassManager::pass_count` / `pass_names` 这类无调用方 API 也要清理。

#### CLI 之间不交叉依赖

`CLAUDE.md` 的 **No CLI Cross-Dependencies** 是实现约束。bpfopt-suite 的 6 个 CLI binary crate（`bpfopt`、`bpfverify`、`bpfprof`、`bpfget`、`bpfrejit`、`bpfrejit-daemon`）之间不能有 runtime dependency，也不能有 compile-time path-dependency。运行时协作通过 stdin/stdout pipeline 和 bash orchestration 组合。共享代码必须放到独立 lib crate，不能把某个 CLI crate 的 lib 部分当成公共库给其它 CLI 引用。

当前实现状态：`bpfrejit-daemon` 不再依赖 `bpfopt` 的 lib 部分；daemon 只通过共享库 `kernel-sys` 访问必要的 BPF 枚举/watch/invalidation 能力，优化、验证、profile、ReJIT 均通过 CLI 子进程完成。

#### 依赖 libbpf-rs，不自己 wrap

`CLAUDE.md` 的 **Use libbpf-rs/libbpf-sys, Don't Re-Wrap** 覆盖实现层依赖选择。只要 `libbpf-rs`/`libbpf-sys` 已经提供 BPF syscall wrapper、`struct bpf_insn`、BPF opcode 常量或 prog type enum，就必须直接使用它们，避免手写 wrapper 引入 `bpf_attr` 和 kABI 漂移错误。唯一必须自写的是项目 fork 的自定义 syscall：`BPF_PROG_REJIT` 和 `BPF_PROG_GET_ORIGINAL`，因为上游 libbpf 不支持。v3 §11 中“libbpf 直接链接（未来走 fork+exec）”是早期保守限制，本文档记录的新规则已经覆盖它；`docs/tmp/bpfopt_design_v3.md` 保持历史原文不改。

#### kernel-sys 是唯一 syscall 入口

`kernel-sys` 是 bpfopt-suite 内唯一直接调用 BPF syscall 的 crate。`bpfopt` 可以依赖 `kernel-sys` 获取 `bpf_insn` 类型、opcode 常量、prog type 枚举等纯数据 API，不再要求 `bpfopt` 完全不依赖 `kernel-sys`。v3 §6 中“`bpfopt` 不依赖 `kernel-sys`”的严格描述是早期保守约束，当前实现约束以本文档为准。`bpfopt` 仍然不能直接调用 `libc::syscall(SYS_bpf, ...)`，也不能用其它方式绕过 `kernel-sys` 调 BPF syscall。其它 CLI（`bpfverify`、`bpfprof`、`bpfget`、`bpfrejit`、`bpfrejit-daemon`）同样只能通过 `kernel-sys` 调 BPF syscall。`kernel-sys` 内部对标准 BPF 命令使用 `libbpf-rs`/`libbpf-sys`，只对 fork 自定义命令 `BPF_PROG_REJIT` 和 `BPF_PROG_GET_ORIGINAL` 用 `libc::syscall` 自行 wrap。`docs/tmp/bpfopt_design_v3.md` 作为历史设计文档不修改，本文档记录新的 syscall 边界约束。

实现阶段：

1. **Phase 1：核心工具最小可用**。迁移/保留 `bpfopt`，实现 `bpfopt optimize`、至少 `wide-mem` 子命令、`bpfget PROG_ID`/`--list`、`bpfrejit PROG_ID FILE`。
2. **Phase 2：完整工具链**。实现所有 pass 子命令、`bpfverify`、`bpfprof`、`bpfget --full` 和 side-input/report 文件协议。
3. **Phase 3：集成**。runner Python 保持 daemon socket + JSON 边界，daemon 内部 fork+exec CLI，并瘦身为 socket server + watch + invalidation + CLI 转发器；必要时把 bpfopt-suite 独立 repo/submodule 化。
4. **Phase 4：增强**。补 per-pass verify loop 脚本、`bpfget --target`/target.json 自动生成、map-inline invalidation hints。

---

## v3 实施进度（截至 2026-04-29）

该节只记录当前实施状态；权威设计仍是 `docs/tmp/bpfopt_design_v3.md`，不在此重复 v3 细节。

### Phase 1（核心工具最小可用）— 完成

- **1.1 `bpfopt-core` 合并进 `bpfopt`**：`bpfopt` 现在同时提供 lib + bin，消除 `-core` 命名（`7d34960`、`d973a4f`、`de64cde`；见 `docs/tmp/bpfopt-merge-review-20260428.md`、`docs/tmp/unit-test-audit-20260428.md`）。
- **1.2 `kernel-sys` crate**：标准 BPF 命令走 `libbpf-rs`/`libbpf-sys`，项目 fork 的 `BPF_PROG_REJIT`/`BPF_PROG_GET_ORIGINAL` 留在 syscall 边界内（`9f59ee4`、`588da36`；见 `docs/tmp/kernel-sys-review-20260428.md`、`docs/tmp/kernel-sys-fix-review-20260428.md`、`docs/tmp/libbpf-rs-eval-20260428.md`）。其中 `GET_ORIGINAL` 通过 `BPF_OBJ_GET_INFO_BY_FD` 加 fork 扩展 `orig_prog_*` 实现，不是独立 syscall cmd。
- **1.2.5 `bpfopt` 切到 `kernel-sys` 类型**：`BpfInsn = #[repr(transparent)] kernel_sys::bpf_insn`（`a441e22`；见 `docs/tmp/bpfopt-kernel-sys-migration-plan-20260428.md`、`docs/tmp/bpfopt-kernel-sys-fix-review-20260428.md`）。
- **1.3 `bpfopt` CLI 完整版**：已提供 12 个 pass 子命令、`optimize`、`analyze`、`list-passes`，缺少 required side-input 或 kinsn 不可用时退出 1（`b0da364`、`aaaaa76`；见 `docs/tmp/bpfopt-cli-review-20260428.md`）。
- **1.4 `bpfget` CLI**：已实现 live bytecode/metadata 获取，后续 `--target` 仍需补 kinsn BTF 自动探测（`dc3abe3`、`8ca15b6`；见 `docs/tmp/bpfget-design-20260428.md`、`docs/tmp/bpfget-bpfrejit-review-20260428.md`）。
- **1.5 `bpfrejit` CLI**：已实现最终 REJIT 提交，`--dry-run` 支持 `fd_array` 并遵守 `kernel-sys` 边界（`dc3abe3`、`8ca15b6`；见 `docs/tmp/bpfrejit-design-20260428.md`、`docs/tmp/bpfget-bpfrejit-review-20260428.md`）。
- **1.6 minimal pipeline 验证**：`bpfget | bpfopt | bpfrejit` 仍待跑 #41。
- **3.3 per-pass verify bash 脚本**：已提前完成脚本化 verify loop（`2e13d9b`）。

测试现状：`bpfopt` 414 + `bpfget`/`bpfrejit` 测试 + `kernel-sys` 4 + daemon 69，当前约 435+ 全 pass；unit test cleanup 删除 37 个 trivial test，保留 468 个高质量 test。

### Phase 2（完整工具链）— 进行中

- **2.1 `bpfverify` CLI + `verifier_log` 迁移**：task #42 + #48 进行中（见 `docs/tmp/bpfverify-design-20260428.md`）。
- **2.2 `bpfprof` CLI**：task #43 进行中（见 `docs/tmp/bpfprof-design-20260428.md`）。
- **`bpfget --target` 增强**：kinsn BTF 自动探测仍是 TODO。

### Phase 3（集成）— 完成（#44 + #45）

#### Phase 3 实施方针：方案 B

- v3 §8 列了方案 A（runner 直调 CLI）和方案 B（daemon 转发 CLI）。
- 本项目选方案 B：runner Python 不动，daemon 内部 fork+exec CLI。
- Task #44 范围调整已落地：runner Python 不改，daemon socket + JSON 协议保持不变，内部 fork+exec CLI subprocess。
- Task #45 daemon 瘦身已落地：删除 `PassManager` / pass code / profiler / kfunc discovery / verifier_log 依赖，daemon 主体只剩 socket server + watch + invalidation + CLI fork+exec。
- v3 §8 文档不动（保留两方案历史描述），plan doc 记录我们的实施选择。

- **3.1 daemon socket-to-CLI 适配**：`optimize` 走 `bpfget --full` → `bpfopt optimize` → `bpfverify` → `bpfrejit`；`profile-start/stop` 走 `bpfprof`；`status`/`optimize-all` 保持原 socket 响应形状。
- **3.2 daemon 瘦身**：`daemon/Cargo.toml` 去掉 `bpfopt`/`goblin`，改为依赖 `kernel-sys`；删除旧 `pipeline.rs`、`profiler.rs`、`kfunc_discovery.rs`、`platform_detect.rs` 及对应旧测试文件。
- **3.3 runner 边界确认**：`runner/libs/`、`corpus/`、`e2e/`、`micro/` 在本阶段不改；Docker/build 依赖也收窄为 daemon 只跟踪 `kernel-sys` 而不是整个 `bpfopt` 源码。

### Phase 4（增强）— 未开始

- **4.1 全平台验证**：KVM x86 + AWS x86 + AWS ARM64 corpus + e2e + micro 尚未完成。
- **4.2 micro `BpfReJIT` 入口恢复**：重构期间被移除，task #53；当前限制见 `docs/tmp/micro-rejit-smoke-20260428.md`（known limitation）。

参考报告：

- `docs/tmp/bpfopt-merge-review-20260428.md`
- `docs/tmp/kernel-sys-review-20260428.md`
- `docs/tmp/kernel-sys-fix-review-20260428.md`
- `docs/tmp/bpfopt-kernel-sys-migration-plan-20260428.md`
- `docs/tmp/bpfopt-kernel-sys-fix-review-20260428.md`
- `docs/tmp/bpfopt-cli-review-20260428.md`
- `docs/tmp/bpfget-design-20260428.md`
- `docs/tmp/bpfget-bpfrejit-review-20260428.md`
- `docs/tmp/bpfprof-design-20260428.md`
- `docs/tmp/bpfverify-design-20260428.md`
- `docs/tmp/bpfrejit-design-20260428.md`
- `docs/tmp/runner-cli-migration-20260428.md`
- `docs/tmp/daemon-slim-design-20260428.md`
- `docs/tmp/libbpf-rs-eval-20260428.md`
- `docs/tmp/unit-test-audit-20260428.md`
- `docs/tmp/micro-rejit-smoke-20260428.md`（known limitation）

---

## 5. 计划

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
- **ARM64 默认走 AWS 远端**（t4g.small bench / t4g.micro test），不在本地 QEMU 跑 Python。
- **AWS 成本约束**：smoke (SAMPLES=1) 用最小够用规格（当前 `t3.small` x86 / `t4g.small` arm64，2 vCPU/2GB）；authoritative (SAMPLES=30) 仅在 burstable CPU credit 限流影响 variance 时升级到 c5/c6g 非 burstable。**禁止无证据升级 instance size**（commit message 必须给出 OOM 或 credit-throttling 数据）。spot instance 优先用于非时间敏感 run。
- **统计要求**：报告必须同时给 applied-only geomean 和 all-comparable geomean + sample count + comparison exclusion reasons。repeat ≥ 50，论文级 ≥ 500。

### 5.4 Required Hardware

1. Modern wide OoO x86 core ✅
2. Efficiency-oriented / Atom-like x86 ❌
3. arm64 系统 🔄（CI 有，性能数据有限）

### 5.6 Benchmark Framework 架构

#### 设计原则

- **BPF 程序用生产方式加载和触发**：有原生应用的程序由应用加载（app-native），不用 generic libbpf + 手写 trigger
- **Corpus 和 E2E 共享 App Runner**：同一个 AppRunner 类（start/workload/stop），corpus 测 per-program exec_ns，E2E 测 app throughput/latency。唯一区别是采集指标，不是生命周期。
- **所有 corpus 程序必须用原生 app 加载**：禁止 bpftool loadall 替代原生 loader。每个 repo 都有原生 app/tool，没有 runner 的要去实现 runner。
- **三个正交维度：Loader × Workload × Measurement**：
  - **Loader**（谁加载 BPF）：原生 app（tracee, bcc/execsnoop, katran_server, libbpf-bootstrap/minimal, systemd, ...）。每个 repo 的程序必须由该 repo 自己的可执行文件加载。
  - **Workload driver**（什么触发 BPF 执行）：app 自身事件、exec_storm、fio、network_traffic 等。Workload 是独立维度，可叠加。
  - **Measurement**（读什么指标）：bpf_stats per-program exec_ns（corpus）、app throughput/latency（E2E）
- **生命周期单元是 loader instance**：一个 loader instance = 一个可执行进程加载的所有 BPF 程序。Tracee 是一个 loader（启动一次加载 30+ BPF 程序）；BCC 的每个 tool（execsnoop, opensnoop, ...）是独立 loader（各加载 1-2 个 BPF 程序）；Katran 是一个 loader。Orchestrator 按 loader instance 分组，每个 instance 一次 start→measure→REJIT→measure→stop 生命周期。
- **缺 runner 的 repo 必须补 runner**：不能标"不可测"然后跳过。没有 runner 是实现缺口，不是分类问题。
- **禁止在 object (.bpf.o) 层级做规划/分流/调度**：object 是编译产物的打包格式，对测量无意义。Orchestrator 的调度单元是 loader instance（app），不是 object。YAML 里不出现 .bpf.o 路径。program 通过 bpf_stats/get_next_id 在运行时自动发现，不需要预先枚举。
- **YAML 只列 app，不列 object/program**：YAML 定义 app（loader instance），每个 app 指定 runner + workload。启动 app 后通过 bpf_stats/get_next_id 自动发现所属 BPF 程序并测量，不需要在 YAML 里枚举 .bpf.o 或 program name。这和“单 daemon session + 运行时发现 live program”的当前架构一致；Object 只是编译产物的打包格式，和调度/测量无关。
- **同一 YAML 服务 corpus 和 e2e**：每个 app 按用途标不同 workload。Corpus 读 bpf_stats exec_ns，E2E 读 app metrics。Orchestrator 根据 mode（corpus/e2e）选 workload。
- **YAML schema**：
  ```yaml
  apps:
    - name: tracee
      runner: tracee
      workload:
        corpus: exec_storm     # corpus: bpf_stats + exec_storm
        e2e: exec_storm        # e2e: tracee 检测延迟 + exec_storm
    - name: bcc/execsnoop
      runner: bcc
      tool: execsnoop
      workload:
        corpus: exec_storm
        e2e: exec_storm
    - name: katran
      runner: katran
      workload:
        corpus: test_run       # corpus: BPF_PROG_TEST_RUN 精确测
        e2e: network           # e2e: 真实流量测 throughput
  ```
- **Corpus TEST_RUN 走 Python + bpftool + ctypes**：`bpftool prog loadall/run/show` + `bpf_enable_stats` 直接测 live kernel program，同一加载实例上对比 baseline/rejit
- **micro 仍保留极简 C++ tool**：`micro_exec test-run` 只服务 isolated micro benchmark，没有 batch orchestration、没有 prepared state、没有 daemon 通信
- **Python Orchestrator 是 corpus benchmark 的唯一编排者**：协调 app runner + daemon + bpftool/bpf_stats 的顺序
- **每个测量单元是一个 loader instance**：没有跨 loader 的共享 state
- **并行在 orchestrator 层**：不同 loader instance 之间可并行（prepare 阶段），测量阶段串行避免 CPU 竞争噪声
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
│  for each loader_instance:                               │
│    # Native app loader: app runner start                 │
│    # bpftool loader: bpftool loadall + attach            │
│    prog_ids = loader.start()                             │
│                                                          │
│    # Workload: test_run / exec_storm / fio / network     │
│    workload.run(seconds=10)                              │
│    baseline = read_bpf_stats(prog_ids)                   │
│                                                          │
│    daemon.optimize(prog_ids)                              │
│    workload.run(seconds=10)                              │
│    rejit = read_bpf_stats(prog_ids)                      │
│                                                          │
│    loader.stop()                                         │
│    report(prog_ids, baseline, rejit)                     │
│                                                          │
│  不做：BPF 加载、触发、测量实现、daemon 通信细节          │
└────────┬─────────────────┬──────────────┬───────────────┘
         │                 │              │
┌────────▼────────┐  ┌─────▼─────┐  ┌─────▼──────────────┐
│  Loader +       │  │  Daemon   │  │  bpftool +         │
│  Workload       │  │  (Rust)   │  │  bpf_stats         │
│                 │  │           │  │                    │
│  负责：         │  │  负责：   │  │  负责：            │
│  start app      │  │  REJIT    │  │  prog loadall/run  │
│  run workload   │  │  优化     │  │  prog show + stats │
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

corpus/driver.py                使用 app_runners + bpftool + bpf_stats → per-program exec_ns
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
  driver.py                 #   调度：app_runner 或 micro_exec → 聚合结果

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
| `rejit-v2` | **主力**：v2 架构 — syscall (GET_ORIGINAL + REJIT) + kinsn (KF_INLINE_EMIT) + multi-subprog + trampoline/XDP refresh（~650 LOC kernel，VM 26/26 + safety 20/20 PASS） | ✅ |
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
| `make vm-test` | canonical 本地 x86 KVM 测试入口；按 contract 自动准备 runner/daemon/test artifacts |
| `make vm-micro` | canonical 本地 x86 KVM micro benchmark 入口 |
| `make aws-arm64-test` | canonical AWS ARM64 测试入口 |
| `make aws-x86-test` | canonical AWS x86 测试入口 |
| `make __kernel` | 内部 x86 kernel 构建 helper；不属于公开控制面 |

#### 快速验证（无需 VM）

| 命令 | 作用 |
|------|------|
| `python3 micro/driver.py --bench simple --runtime llvmbpf --samples 1 --warmups 0 --inner-repeat 10` | 本地 llvmbpf smoke test (simple, 1 iter, 10 repeat) |
| `make check` | 运行根入口定义的静态回归门禁（当前仅 Python contract tests） |

#### VM 目标（需要 bzImage + vng）

| 命令 | 作用 |
|------|------|
| `make vm-selftest` | VM 中跑 repo 自己的 unittest `rejit_*` 集合，并追加 negative tests (`adversarial_rejit` + `fuzz_rejit`) |
| `make vm-micro-smoke` | VM 中跑 micro smoke (simple + load_byte_recompose + cmov_dense, llvmbpf + kernel) |
| `make vm-micro` | VM 中跑全量 micro suite (llvmbpf + kernel, 默认 3iter/1warm/100rep) |
| `make vm-corpus` | 跑 corpus batch（单 VM batch，daemon serve 常驻，用 policy，默认 30 samples） |
| `make vm-e2e` | 跑全部 E2E (tracee + tetragon + bpftrace + scx + bcc + katran；`xdp_forwarding` 已退役) |
| `make vm-all` | = `vm-test` + `vm-micro` + `vm-corpus` + `vm-e2e`（完整 VM 验证） |
| `make validate` | = `check` + `vm-test` + `vm-micro-smoke`（最小 VM 验证） |

#### 可调参数

```bash
make vm-micro SAMPLES=10 WARMUPS=2 INNER_REPEAT=500      # strict run
make vm-micro BZIMAGE=/path/to/other/bzImage              # 自定义 kernel
make vm-corpus SAMPLES=10                                 # 快速 corpus
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

任务追踪已迁移到 git history。每个任务的详细记录在 commit messages 和 `docs/tmp/` 报告中。

- **v1 历史记录（#1 - #303）**：`docs/kernel-jit-optimization-plan-record-old.md`
- **v2 任务记录（#304 - #673）**：`docs/kernel-jit-optimization-plan-task-archive.md`
- **当前任务**：用 `git log --oneline` 查看
- **调研报告**：`docs/tmp/` 按日期组织

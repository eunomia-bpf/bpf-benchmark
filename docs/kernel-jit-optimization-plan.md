# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化论文的单一 hub，记录设计方向、论文策略、实验进度与 TODO。
> **编辑规则：任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态（如"归入 #32"），不得直接删除。**
> Characterization 论文见 `docs/paper-comparison.md`（独立论文，最终将与本文合并）。
>
> 最新设计文档：**`docs/tmp/jit-pass-framework-v5-design.md`**（v5 声明式 Pattern + Canonical Lowering）
> v4 设计文档：`docs/tmp/jit-pass-framework-v4-design.md`（v5 的前身，保留作参考）
> v3 设计文档：`docs/tmp/jit-pass-framework-v3-design.md`（已被 v4 取代为主方向，保留作参考）
>
> 上次更新：2026-03-10（v4 Round 3 完成，ALL 4 directive families active，ROTATE -28%，combined -37%）

---

## 1. 论文定位与策略

### 1.1 核心论题

> eBPF JIT 的 backend 优化应该分为稳定的 **kernel legality plane** 和可更新的 **userspace backend policy plane**。Kernel 验证并安全采纳有界的 backend directives；特权 userspace 根据 CPU profile、workload profile、程序特征和 fleet policy 决定请求哪些 directives。

贡献不是任何一个 peephole 优化，而是 **可扩展的 JIT pass 框架**：用户态定义 transformation rules，内核安全地解释执行。本质上是给 kernel BPF JIT 加一个可外部控制的 instruction selection / peephole optimization 框架。

> **v3 核心洞察**：论文的贡献层次应该是**框架**，不是个别 directive。
> POC v2 证明了单个 JIT-level directive 的可行性（cmov_select）；
> v3 要证明这个机制可以**泛化为通用的可扩展框架**——用户态无需改内核代码就能定义新的优化 rule。

### 1.1b 论文故事（OSDI/SOSP 版，2026-03-11）

#### 1. eBPF 已是关键基础设施，但 kernel JIT 耦合了安全和优化

eBPF 程序运行在 fleet-scale 网络、追踪、安全、调度的 hot path 上。每个部署的 BPF 程序都由内核 JIT 编译为 native code，**直接在内核态执行**——任何代码生成错误都可能导致内核崩溃或安全漏洞，因此 JIT 必须提供严格的安全保证。JIT code quality 直接决定 CPU 成本。

但当前 JIT 将安全保证和另一个不同的关注点耦合在一起：**决定如何优化生成的代码**。优化决策取决于部署上下文——workload 行为、目标微架构、fleet 约束——内核没有这些信息，operator 也无法介入。

#### 2. 为什么不能在 kernel 里修

- **不是 bytecode 层的问题**：BPF ISA 没有 cmov/wide-load/rotate，bytecode 优化器（K2/Merlin/EPSO）触及不到 native instruction selection。
- **固定启发式必然错**：
  - Policy-sensitivity：同一优化对不同 workload 方向相反（CMOV: predictable +34.5%, unpredictable -2.8%）
  - Combination interference：各自有益的启发式组合产生新回退（fixed-all → stride_load_16 +141%）
- **新模式受限于 kernel release 周期**（月级），kernel JIT 成为优化演化的瓶颈。

#### 3. 安全约束：使问题 non-trivial

Operator 需要控制优化决策，但 eBPF 安全模型要求内核是唯一生成 native code 的实体。不能上传机器码，不能绕 verifier，不能扩大 TCB。

→ 表面矛盾：需要外部控制优化，但不能开放 native code emission。

#### 4. Thesis：安全与优化可以分离

> **内核 JIT 的 backend 决策可以安全地分解为 safety（哪些 native code 变体可以安全生成）和 optimization（哪些变体应当应用）。**
>
> - **Safety（内核负责）**：内核定义有界的 safe variant menu，验证每个请求，不合法则 fail-closed。
> - **Optimization（用户态负责）**：特权用户态根据 workload、硬件、fleet policy 选择变体。
>
> 内核从不执行用户态提供的代码——只在自己预定义的安全变体间切换。

#### 5. 可扩展性

- **Safety 接口稳定且小**：每新增一个优化族 ~100 LOC kernel
- **Optimization policy 独立于 kernel 演化**：新 pattern、新 CPU、新 workload → userspace 更新，无需 kernel release
- 这不是四个 peephole 的论文——是一个可扩展的 OS 接口，让 JIT optimization policy 像 scheduling policy (sched_ext) 一样从内核分离

#### 论文主线（Abstract → Conclusion）

1. **问题**：Kernel JIT 耦合安全和优化，operator 无法控制 native code quality
2. **不可修复**：policy-sensitive + combination interference + bytecode optimizer 够不到 + kernel release 瓶颈
3. **安全约束**：不能让 userspace 控制 native code emission
4. **Thesis**：安全与优化可以分离
5. **系统**：BpfReJIT——kernel-defined safe variant menu + userspace selection + fail-closed
6. **可扩展性**：safety 接口稳定，optimization policy 独立演化
7. **证据**：policy-sensitivity 证明分离必要；60 生产程序证明 practical；selective re-compilation 避免所有 regression

#### 类比定位

| 系统 | 耦合了什么 | 分离出什么 |
|------|-----------|-----------|
| Exokernel | 保护 + 资源管理 | 应用控制资源管理 |
| sched_ext | 调度机制 + 调度策略 | BPF 程序定义调度策略 |
| **BpfReJIT** | **JIT 安全 + JIT 优化策略** | **用户态定义优化策略** |

### 1.2 两篇论文策略（已合并，保留记录）

> 两篇论文已合并为 `docs/paper/paper.tex`，以下为历史记录。

| 论文 | 状态 | 说明 |
|------|:---:|------|
| **Paper 1: Characterization** | 已合并 | `paper-comparison.md`，量化 kernel JIT vs LLVM -O3 差距 |
| **Paper 2: Optimization** | 已合并 | 本文档，userspace-guided backend optimization |
| **最终合并** | ✅ 完成 | `docs/paper/paper.tex` |

**合并后的故事线**（旧版，被 1.1b 取代）：
1. ~~Characterization 揭示差距来自 backend lowering（不是 bytecode）~~
2. ~~Bytecode 优化器（K2/Merlin/EPSO）无法触及这些 backend 决策~~
3. ~~部分 backend 决策的 legality 稳定但 profitability 依赖部署环境~~
4. ~~设计 mechanism/policy 分离的框架~~
5. ~~实现 + 评估~~

### 1.3 OSDI/SOSP Novelty 分析

**真正 novel 的部分**：
1. **Mechanism/policy 分离** — kernel 管 legality，userspace 管 profitability
2. **Fail-closed backend policy substrate** — digest binding、verifier remap、retained facts、exact validators、CPU gating
3. **部署控制权** — 优化 owner 是 Cilium/Katran 等特权 loader，不是 kernel maintainer
4. **Policy-sensitive 的证据** — 同一个合法站点在不同 CPU/workload 下需要不同 lowering

**增量的部分**（有用但不足以单独撑论文）：
- 各个 peephole 优化本身
- Validator template 作为代码组织手段
- Arch-specific emitter

**OSDI/SOSP Go 条件**（全部满足才提交）：
1. 与 characterization 深度整合或合并
2. 原型实现多个 directive，展示框架的泛化能力
3. 评估包含真实多函数程序和至少一个端到端部署
4. Fixed kernel baseline 不能在所有场景下达到同等收益

### 1.4 "Why Userspace" — 5 个独立理由

不只是微架构差异：

| 理由 | 说明 |
|------|------|
| **可更新性** | userspace policy DB 可以每周更新，kernel heuristic 只能等升级 |
| **程序级组合** | 局部有利的变换可能全局有害（I-cache cliff），userspace 做全局预算 |
| **Workload 适应** | 分支可预测性取决于运行时数据分布，不是 ISA 特性 |
| **Fleet A/B testing** | 5% 机器先上新 policy，看效果再推广，无需改 kernel |
| **所有权** | service owner 已经拥有 BPF 性能调优（Cilium/Katran），kernel maintainer 不应维护每个 service 的 heuristic |

### 1.5 设计方向决策记录

| 决策 | 结论 | 原因 |
|------|------|------|
| **不做简单 peephole patches** | ❌ 不考虑 | 目标是论文（系统贡献），不是发 kernel patch |
| **不做 kernel-only first** | ❌ 不采纳 R4 建议 | 一开始就要考虑 userspace |
| **不用 lift→compare→emit** | ❌ 放弃 v4 设计 | 太重，且不是正确的抽象层次 |
| **userspace policy 不只是微架构** | ✅ v6 扩展 | 可更新性、组合、workload 适应、fleet 管理、所有权 |
| **kernel 改动最小化** | ✅ | 参数化 validator 模板，每个 directive ~50-100 LOC |
| **最终合并两篇论文** | ✅ 计划中 | 但现在先拆开确保各自质量 |

**与 existing work 的关键差异**：

| 系统 | 优化层 | 能解决 backend 差距? | 部署可控? |
|------|--------|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode | ❌ | ❌ |
| **Ours** | **Backend lowering** | **✅** | **✅** |

### 1.6 核心设计思路

1. **Kernel 开放最小接口**，允许特权用户态进程对已验证的 BPF 程序附加**微架构相关的 JIT directives**
2. 这些 directives 本质上是**与目标硬件绑定的后端优化决策**（wide load、cmov、branch layout 等）
3. **Userspace 做分析决策**（手动工具、llvmbpf 自动化、或 profiler）
4. **Kernel JIT 只做验证 + 采纳/拒绝**，fail-safe（拒绝时 fallback 到正常 emission）

### 1.7 为什么是微架构相关的 directives（v4 vs v5）

v4 试图用 target-independent IR 做抽象，但这是错误的层次：

| 维度 | Target-independent IR (v4) | 微架构相关 directives (v5+) |
|------|---------------------------|--------------------------|
| 抽象层次 | 语义等价变换 | 后端决策指令 |
| kernel 复杂度 | 需要 lifter + canonicalizer + comparator | 只需验证前置条件 + 采纳/拒绝 |
| 安全模型 | 语义等价证明（难） | 前置条件检查（简单） |
| 可扩展性 | 每种优化需新 IR op | 每种优化需新 directive type（~50-100 LOC） |
| 微架构适配 | 不能 — target-independent | 天然支持 — 由 userspace 决定 |

关键洞察：**优化决策本身就是微架构相关的**。cmov 在某些微架构上比 branch 快，在其他上不一定。Wide load 的收益取决于 cache line 行为。Branch layout 依赖分支预测器设计。

### 1.8 分阶段计划

| 阶段 | 内容 | Kernel 改动 | Userspace | 状态 |
|------|------|-----------|-----------|:---:|
| **Phase 1 (POC v2)** | 单个硬编码 JIT directive (cmov_select) | 新增 directive 接口 + 验证逻辑 + x86 emitter | 手动工具 | ✅ |
| **Phase 2 (v3→v4)** | **Post-load re-JIT + 机器码级 policy** | `BPF_PROG_JIT_RECOMPILE` + 通用 dispatch | auto-scan xlated + policy blob builder | 🔄 |
| **Phase 3** | 跨架构 + 自动化 + 端到端部署 | arm64 target backend | llvmbpf 自动 rule 生成 + PGO | ❌ |

#### v3→v4 设计演化

v3 设计了复杂的 5 层基础设施（family/plan/alt table/dispatcher/arbitration），但 POC 阶段过度工程化。v4 回到第一性原理：

| 创新 | v3 | v4 |
|------|----|----|
| 控制粒度 | userspace 选 kernel 预注册的 alt | **userspace 直接指定 native instruction** |
| 传输时机 | 绑定在 BPF_PROG_LOAD | **独立 BPF_PROG_JIT_RECOMPILE** |
| 可迭代性 | 需重新加载程序 | **运行中程序可反复 re-JIT** |
| Runtime PGO | 不支持 | **load → profile → apply → re-JIT → measure → iterate** |

### 1.9 v3 可扩展 JIT Pass 框架（核心方向）

> **这是论文的真正贡献**。POC v2 的单个 cmov_select 只是 proof of concept。

#### 1.9.1 问题：当前 POC v2 不可扩展

| 能力 | POC v2 | v3 可扩展框架 |
|------|--------|-------------|
| directive 种类 | 1 个（cmov） | N 个，用户态可定义 |
| 添加新 directive | 改内核代码（~300行/directive） | 用户态提交 rule |
| pattern 语言 | 硬编码 C 函数 | 声明式 DSL / peephole pattern |
| native emission | 硬编码 EMIT 宏 | instruction selection 抽象 |
| 跨架构 | 只有 x86 | target-independent rules + target lowering |
| safety 机制 | 手工 audit | 自动 rule 验证 |

#### 1.9.2 v3 需要的四个核心组件

1. **Pattern/Rewrite 中间表示**
   - 用户态描述"看到 X 形状的 BPF 指令序列，native lowering 换成 Y"
   - 类似 LLVM TableGen 的 peephole DSL，但更受限（安全性）
   - 内核能解释执行这个 rule

2. **Safety Verifier for Rules**
   - 内核必须证明用户态给的 rewrite rule 不会破坏语义正确性
   - 可能的方法：从预定义模板实例化、声明式 constraint checking、equivalence proof

3. **JIT Backend 抽象层**
   - 当前 `do_jit()` 是一个大 switch-case，没有 instruction selection 抽象
   - 需要在关键位置插入 "instruction selection point"，让 rule 决定走哪个 lowering 分支
   - 或者：两阶段 JIT（先选策略，再发射）

4. **跨架构 Target Description**
   - Target-independent pattern（BPF 指令序列匹配）
   - Target-specific lowering（x86: cmovcc, arm64: csel）
   - 统一的 rule 格式，per-target emission backends

#### 1.9.3 核心难点

这本质上是在**给 kernel BPF JIT 加一个 compiler backend 的 instruction selection 框架**。Linux 内核 BPF JIT 当前的设计哲学是：一个大的 `do_jit()` switch-case，每条 BPF 指令对应一段硬编码的 native emission。它没有 IR、没有 instruction selection pass、没有 peephole optimizer。

关键问题：**在保持内核安全性的前提下，用户态可以控制 JIT emission 的最大边界在哪里？**

#### 1.9.4 与 existing work 的关键差异（更新）

| 系统 | 优化层 | 可扩展? | 能解决 backend 差距? | 部署可控? |
|------|--------|:---:|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | ❌ | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF | ❌ | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode | ❌ | ❌ | ❌ |
| GCC/LLVM JIT | native backend | ✅ (passes) | ✅ | ❌ (kernel-internal) |
| **Ours (v3)** | **BPF JIT backend** | **✅ (user-defined rules)** | **✅** | **✅** |

详细设计见 `docs/tmp/jit-pass-framework-v3-design.md`。

---

## 2. Characterization 证据摘要

来自 `paper-comparison.md` 的关键数据，作为设计输入：

| 证据 | 数值 | 来源 |
|------|------|------|
| Exec time geomean (L/K) | 0.849x (31 pure-JIT) | authoritative 30×1000 |
| Code size geomean (L/K) | 0.496x (31/31 llvmbpf 更小) | authoritative |
| Byte-recompose 指令占比 | **50.7%** of kernel surplus | JIT dump 分析 |
| Byte-recompose 时间惩罚 | **2.24x** (load_byte_recompose 0.447x) | 因果隔离实验 |
| cmov 差距 | 31 vs 0 | JIT dump |
| Prologue/epilogue 占比 | 18.5% of surplus | JIT dump |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 | pass ablation |
| branch_layout 输入敏感性 | predictable 0.225x vs random 0.326x，差 44.6% | 微架构实验 |
| Real-program code-size | 0.618x geomean (36 unique) | corpus 分析 |
| Real-program exec-time | 0.514x geomean (14 unique) | raw-packet 实验 |

---

## 3. 优化目标与 Kernel 状态

### 3.1 Tier 1：论文已识别的 3 个主要优化

| # | 优化 | 影响 | v7.0-rc2 状态 | 行动 |
|---|------|------|:---:|------|
| 1 | **Byte-load recomposition** | 50.7% surplus, 2.24x penalty | ❌ 未实现 | **最高优先级，wide_load directive** |
| 2 | **cmov support** | 19.9% branch surplus, 31 vs 0 cmov | ❌ 未实现 | cmov_select directive |
| 3 | **Callee-saved register opt** | 18.5% surplus | ✅ 已实现 | 验证了我们的分析 |

### 3.2 Tier 2：新发现的优化机会

详见 `docs/tmp/directive-discovery-analysis.md`（含真实 workload 证据）和 `docs/tmp/additional_jit_optimizations.md`。

**v1 候选（按 real-workload 收益/风险排序）**：

| # | Directive | 触发模式 | 证据 | 框架适配度 |
|---|-----------|----------|------|:---:|
| 1 | `bitfield_extract` | `(src >> c) & mask`，packet header field extraction | packet_parse_vlans_tcpopts, packet_rss_hash, Cilium tc | 直线段 ✅ |
| 2 | `rotate_fusion` | hash/checksum rotate idioms | packet_rss_hash, checksum, bitcount | 直线段 ✅ |
| 3 | `lea_fusion` | small-const multiply + add | smallmul_strength_reduce, local_call_fanout, parser indexing | 直线段 ✅ |
| 4 | `bounds_window` | 冗余 bounds check 消除 | bounds_ladder, packet_redundant_bounds, Cilium tc parsers | 单钻石 + retained facts |
| 5 | `packet_ctx_wide_load` | packet/ctx 连续字段提取 | packet_parse, nat64_kern, bpf_overlay | 需 mem-class 扩展 |
| 6 | `wide_store` | 相邻 byte stores 合并 | ksnoop stack zeroing, bpf_overlay | 直线段 ✅ |

**Future（需框架扩展）**：

| Directive | 原因 | 备注 |
|-----------|------|------|
| `map_lookup_cache` | 重复同 key 查找，需 helper-effect 建模 | corpus 99.8% objects 含 map_lookup |
| `subprog_inline` | 需跨过程 validator + 代码预算 | corpus 97.2% objects 多函数 |

**明确排除 v1**：const_fold_region, post_verifier_dce, tail_call_specialize（需 mini-compiler 或跨程序语义）

**新 benchmark smoke 结果**（directive-discovery 创建）：

| Benchmark | llvmbpf | kernel | code size L/B vs K/B |
|-----------|--------:|-------:|:----:|
| packet_redundant_bounds | 71 ns | 115 ns | 273 / 717 |
| const_fold_chain | 211 ns | 891 ns | 408 / 602 |
| map_lookup_repeat | 1.744 µs | 678 ns | 591 / 872 |
| struct_field_cluster | 98 ns | 76 ns | 339 / 439 |
| smallmul_strength_reduce | 393 ns | 349 ns | 413 / 586 |

### 3.3 Tier 3：不推荐

- 完整常量传播/DCE — 等于重写为编译器后端
- 指令调度 — 现代 OoO CPU 已处理
- 完整寄存器分配 — 固定 BPF→x86 映射是设计选择
- 循环优化 — LLVM ablation 显示对 BPF 无效果

---

## 4. Directive 分类体系（v6）

### 4.1 Policy-sensitive 家族（需要 userspace policy，撑论文 novelty）

| Directive | Why userspace policy | 已有证据 | 状态 |
|-----------|---------------------|----------|:---:|
| **`cmov_select`** | 依赖分支可预测性、依赖链深度、CPU 家族；同一合法站点需要不同 lowering | no-cmov ablation: switch_dispatch +26%, binary_search +12%; 31 vs 0 cmov | **v1 prototype** |
| **`branch_reorder`** | 依赖 workload 热度、输入分布、code-size budget、前端行为 | branch_layout: predictable vs random 差 44.6% | **应加入 v1** |
| **`subprog_inline`** | 依赖热度、code-size budget、I-cache 压力、多函数结构 | corpus 97.2% multi-function，local_call_fanout ~0.72x | future，但极有说服力 |

### 4.2 Substrate 家族（主要是 kernel peephole，但复用框架基础设施）

| Directive | 诚实评估 | 状态 |
|-----------|----------|:---:|
| `wide_load` | 高价值 baseline recovery + substrate exercise；profitability 弱依赖 policy | **v1 prototype** |
| `wide_store` | code size 改善，workload 敏感性低 | v1 候选 |
| `rotate_fusion` | 局部 idiom 识别，BMI2 feature 依赖 | **v1 候选**（packet_rss_hash 等证据） |
| `lea_fusion` | 经典 backend combine，有 smallmul 和 parser indexing 证据 | **v1 候选** |
| `bitfield_extract` | packet header field extraction，Cilium tc 高频 | **v1 候选** |
| `bounds_window` | 冗余 bounds check，需 retained entry facts | v1 stretch goal |
| `packet_ctx_wide_load` | wide_load 的 packet/ctx 扩展 | post-v1 扩展 |

### 4.3 不应做的方向

| 方向 | 原因 |
|------|------|
| 寄存器分配 hints | 太底层，跨 JIT 版本不稳定 |
| 指令调度 hints | 难验证，收益证据不足 |
| 任意 native code 注入 | 破坏安全故事 |
| Target-independent replacement IR | 回到 v4 问题 |

---

## 5. 系统架构

### 5.1 Control Plane vs Data Plane

```
┌───────────────────────────────────────────┐
│  Userspace Backend Policy Plane           │
│  ┌─────────────────────────────────────┐  │
│  │ Candidate discovery (pattern match) │  │
│  │ Site feature extraction             │  │
│  │ CPU + workload policy DB            │  │
│  │ Fleet policy / A/B rollout          │  │
│  │ Code-size budget management         │  │
│  │ Directive blob generation           │  │
│  └─────────────────────────────────────┘  │
└──────────────────┬────────────────────────┘
                   │ BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd)
                   │ (v4: 独立于 BPF_PROG_LOAD，支持 post-load re-JIT)
┌──────────────────▼────────────────────────┐
│  Kernel Legality Plane                    │
│  ┌─────────────────────────────────────┐  │
│  │ Digest binding + CPU contract       │  │
│  │ Verifier (preserves orig_idx)       │  │
│  │ Retained mem facts                  │  │
│  │ Post-verifier remap                 │  │
│  │ Shared precondition checks          │  │
│  │ Kind-specific validators            │  │
│  │ Arch-specific emitters              │  │
│  │ Fail-closed fallback + logging      │  │
│  └─────────────────────────────────────┘  │
└───────────────────────────────────────────┘
```

### 5.2 Arch-neutral / Arch-specific 分离

```
┌─────────────────────────────┐
│  Arch-neutral (共享)         │
│  - Directive blob 格式       │
│  - BPF_PROG_LOAD transport  │
│  - orig_idx remap           │
│  - CPU gating               │
│  - Retained verifier facts  │
│  - Fail-closed + logging    │
│  - Kind-specific validators │
└──────────┬──────────────────┘
           │
    ┌──────┴──────┐
    │             │
┌───┴───┐   ┌────┴────┐
│ x86   │   │ arm64   │
│ emit  │   │ emit    │
│ wide: │   │ wide:   │
│  mov  │   │  ldr    │
│ cmov: │   │ cmov:   │
│ cmovcc│   │  csel   │
│ hfall:│   │ hfall:  │
│ jcc   │   │ b.cond  │
└───────┘   └─────────┘
```

### 5.3 参数化 Validator 模板

```c
struct bpf_jit_dir_template {
    enum bpf_jit_dir_kind kind;
    bool requires_aligned_access;
    bool requires_no_side_effects;
    bool requires_single_entry_exit;
    u8 min_insn_count, max_insn_count;
    bool (*validate)(const struct bpf_prog *prog,
                     const struct bpf_jit_dir_rec *rec,
                     const struct bpf_jit_site *site,
                     struct bpf_jit_plan *plan);
};
```

| 层次 | 加新 directive 是否需要改 | 说明 |
|------|:-:|------|
| Transport / blob 格式 | ❌ | 通用 |
| Remap / orig_idx | ❌ | 通用 |
| CPU gating | ❌ | 通用 |
| Fail-closed + logging | ❌ | 通用 |
| **Validator** | **✅ 小改** | ~50-100 LOC |
| **Emitter** | **✅ 小改** | ~50-100 LOC per arch |

### 5.4 Mandatory Falsification Condition

> 如果 fixed kernel policies 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，而不是"发布 userspace-guided interface"。

---

## 6. 评估计划

### 6.1 Required Baselines

1. Stock kernel JIT
2. `kernel-wide-load` peephole
3. `kernel-fixed-cmov` peephole（固定策略）
4. `kernel-fixed-layout`（固定 branch layout 策略）
5. `advisor-static`（CPU DB only）
6. `advisor-profiled`（CPU DB + workload profile）
7. llvmbpf 作为上界参考

### 6.2 Required Questions

1. Userspace policy 是否真的在不同硬件/workload/程序间产生差异？
2. 这些差异是否 outperform fixed kernel heuristics？
3. Legality substrate 在真实程序上的 directive 接受率？
4. 系统是否泛化到多个 directive 家族？
5. Operators 能否在类似 production 的部署中安全管理 policy？

### 6.3 Required Workloads

**Mechanism isolation microbenchmarks**：load_byte_recompose, binary_search, switch_dispatch, branch_layout

**Policy-sensitivity benchmarks**：packet_rss_hash (~0.47x), local_call_fanout (~0.72x), branch_fanout_32, mega_basic_block_2048

**Real programs**：162 paired instances (36 unique)，per-program candidate counts + acceptance rates

**End-to-end deployment**：至少一个（Cilium datapath / Katran XDP / 其他 production-like）

### 6.4 Required Hardware Diversity

1. 一个 modern wide OoO x86 core
2. 一个 smaller-core / Atom-like x86
3. 理想情况一个 arm64 系统

---

## 7. 消融实验证据

### 7.1 已完成

| 消融实验 | 方法 | 结果 |
|----------|------|------|
| 禁用 cmov | LLVM subtarget `-cmov` | switch_dispatch +26%，binary_search +12%；部分反而变快 |

**cmov 消融详细数据**：

| Benchmark | Normal | No-cmov | Delta |
|-----------|-------:|--------:|------:|
| switch_dispatch | 213 ns | 269 ns | **+26.3%** |
| binary_search | 205 ns | 229 ns | **+11.7%** |
| bounds_ladder | 83 ns | 68 ns | -18.1% |
| large_mixed_500 | 415 ns | 316 ns | -23.9% |

结论：cmov 收益**依赖于微架构和 workload**。

### 7.2 待做

| 消融实验 | 方法 | 状态 |
|----------|------|:---:|
| 模拟 byte-recompose | llvmbpf 中 wide load → byte-load 序列 | ❌ |
| 强制 fixed callee-saved | 总是保存 rbp+rbx+r13 | ❌ |
| 禁用 rotate/blsr | 禁用 BMI/BMI2 features | ❌ |

---

## 7.5 Kernel 分支清单（`vendor/linux`）

| 分支名 | 基于 | 用途 | 状态 |
|--------|------|------|:---:|
| `master` | upstream 7.0-rc2 | 原始 upstream kernel，stock JIT baseline | 基准 |
| `jit-directive-poc` | master | POC v1：wide_load verifier-level rewrite（**方向错误**，已弃用） | ⚠️ 弃用 |
| `jit-directive-poc-v2` | master | POC v2：cmov_select JIT-level directive，证明 xlated 不变量 | ✅ 验证完成 |
| `jit-directive-v4` | master | **v4 框架主分支**：BPF_PROG_JIT_RECOMPILE + 4 directives (CMOV/WIDE/ROTATE/LEA) + policy blob | ✅ 主力开发 |
| `jit-fixed-baselines` | jit-directive-v4 | **Kernel-fixed baselines**：无条件 heuristic 对照实验。CONFIG_BPF_JIT_FIXED_{ROTATE,WIDE_MEM,LEA,CMOV} 四个开关 | 🔄 测试中 |

> **Worktree 布局**（2026-03-10 起）：
> - `vendor/linux` — 当前工作目录（可切换分支）
> - `vendor/linux-framework` — `jit-directive-v4` worktree（框架主分支，永驻）
> - `vendor/linux-baseline` — `master` worktree（stock upstream 7.0-rc2，永驻）
>
> **使用方式**：在对应 worktree 目录下 `make -j$(nproc) bzImage`，然后 `vng --run <worktree>/arch/x86/boot/bzImage --exec "..."`。
> 不再需要频繁 `git checkout` 切换，framework 和 baseline 可并行编译测试。
> **v4 policy 优先级**：在 `jit-fixed-baselines` 上，如果 v4 policy 附加到 prog，v4 规则优先于 fixed heuristic。

---

## 8. 已完成实验

| 实验 | 日期 | 结果 |
|------|------|------|
| VM 环境搭建 | 03-07 | QEMU/KVM + virtme-ng，kernel 7.0-rc2 |
| VM baseline（kernel only） | 03-07 | geomean **0.881x**（7.0-rc2 更快） |
| Kernel 7.0-rc2 JIT 源码分析 | 03-08 | callee-saved ✅；byte-recompose ❌；cmov ❌ |
| no-cmov 消融 | 03-08 | 混合结果，见上 |
| 10 个新 benchmark | 03-08 | geomean 0.835x（8/10 llvmbpf wins） |
| 微架构实验 | 03-08 | 频率扫描、输入分布、PMU |
| GitHub Actions CI | 03-08 | ARM64 + x86 workflow 设置完成 |
| v6 设计完善 | 03-08 | OSDI/SOSP novelty 分析，directive 分类体系 |
| v3 框架设计 + 3 轮 review | 03-09 | 8/10，JIT-only invariant 确立。见 `docs/tmp/jit-pass-framework-v3-design.md` |
| v4 框架设计 | 03-09 | Post-load re-JIT + 机器码级 policy。见 `docs/tmp/jit-pass-framework-v4-design.md` |
| **v4 POC 实现（2 rule）** | 03-09 | 1788 LOC kernel + 3 commits userspace。`jit-directive-v4` branch。2 directives (COND_SELECT + WIDE_MEM) |
| **v4 VM 验证（2 rule）** | 03-09 | 43 benchmarks tested。xlated 不变量全部满足。log2_fold: 6 sites, +28% 变慢 → **policy-sensitivity 直接验证** |
| **v4 gap analysis** | 03-09 | 13 gaps, 7 需立刻修。最关键：correctness bug + 只有 2 directives + 无 cpu feature gating |
| **v4 correctness fix** | 03-09 | 3 个 bug 修复：interior edge check + flag-clobber + subprog boundary。见 `docs/tmp/v4-bug-diagnosis.md` |
| **v4 扩展（4 rule）** | 03-09 | 新增 ROTATE (rorx/ror) + ADDR_CALC (LEA fusion) + cpu_features_required + per-rule logging。~850 LOC kernel 总计 |
| **v4 实现 review** | 03-09 | 🔄 sonnet 对比 plan+v4 设计文档审查中。输出 `docs/tmp/v4-implementation-review.md` |
| **v4 新 directive VM 测试** | 03-09 | 🔄 sonnet 测试 4 个 directive 在 VM 端到端验证中。输出 `micro/results/v4_new_directives_test.json` |
| **论文 LaTeX 初稿** | 03-09 | 🔄 sonnet 创建 ACM sigconf 模板 + characterization + system design 初稿。输出 `docs/paper/paper.tex` |
| **Round 1 修复 + 重测** | 03-09 | R1/R3/R5/R6/R7 五项修复。LEA/CMOV 无回归。**ROTATE 和 WIDE_MEM 仍 0 覆盖**（clang pattern mismatch）。见 `docs/tmp/v4-round1-test-results.md` |
| **Round 2 scanner 修复 + VM 测试** | 03-10 | WIDE_MEM 突破（0→11 sites，-13%/-14% exec）。ROTATE 仍 0（micro_rotl64 shift mask 问题）。见 `docs/tmp/v4-round2-test-results.md` |
| **v5 声明式 Pattern 框架设计** | 03-10 | ~950 行设计文档。pattern 描述移到 userspace blob，kernel 通用 matcher + canonical lowering。见 `docs/tmp/jit-pass-framework-v5-design.md` |
| **Round 2 scanner 修复** | 03-09 | ROTATE 6-insn masked pattern + WIDE_MEM high-byte-first + rotate64_hash benchmark。见 `docs/tmp/v4-round2-implementation.md`。VM 测试 🔄 |
| **Round 3: ROTATE 突破** | 03-10 | **ALL 4 families active**。ROTATE 0→126 sites（115+11），-28.4% exec，-32.3% code。combined -36.6%。见 `docs/tmp/v4-round3-test-results.md` |

### 8.1 VM vs Host 关键发现

7.0-rc2 kernel JIT 比 6.15 快约 12%（geomean 0.881x），部分归因于 callee-saved 优化。
完整数据见 `micro/results/vm_vs_host_comparison.md`。

### 8.2 v4 新 Directive VM 测试（2026-03-09）

> 完整数据见 `micro/results/v4_new_directives_test.json`

| Directive | 覆盖率 | 结果 | 说明 |
|-----------|--------|------|------|
| **ADDR_CALC (LEA)** | 4 程序，5 sites | ✅ **stride_load_16 -12%，multi_acc_4 -7%** | jited -6B/-5B，真实加速 |
| **COND_SELECT (cmov)** | 1 程序，6 sites | ⚠️ log2_fold +34% 变慢 | 可预测分支 → cmov 反而更慢，验证 policy-sensitivity |
| **ROTATE** | **0 覆盖** | ❌ 无 sites | clang 编译 rotate 为 AND+RSH+SHL+OR（带 mask），scanner 不识别 |
| **WIDE_MEM** | **0 覆盖** | ❌ 无 sites | clang 把 byte-load 循环优化掉，不产生 sequential ladder |

**关键结论**：
- ADDR_CALC 是唯一展示真实加速的 directive（-12%），且正确性 100%
- ROTATE 和 WIDE_MEM 的 scanner pattern 需要适配真实 clang 编译输出
- 核心不变量全部满足：xlated_prog_len 在所有 case 下不变

### 8.2b v4 Round 2 VM 测试（2026-03-10）

> 完整数据见 `docs/tmp/v4-round2-test-results.md`

| Directive | 覆盖率 | 性能 | 代码大小 | 说明 |
|-----------|--------|------|---------|------|
| **WIDE_MEM** | **3 程序，11 sites** | ✅ **load_byte_recompose -13%，stride_load_4 -14%** | -12B/-24B/-96B | **Round 1→Round 2 突破：0→11 sites** |
| **ADDR_CALC (LEA)** | 3 程序，3 sites | ✅ stride_load_16 -64%，multi_acc_4 -3% | -6B/-5B | 无回归，stride_load_16 大幅加速 |
| **COND_SELECT (cmov)** | 1 程序，6 sites | ⚠️ log2_fold +9.3% 变慢 | +34B | 预期行为（policy-sensitivity） |
| **ROTATE** | **仍 0 覆盖** | ❌ 无 sites | — | micro_rotl64 的 `shift&=63` 产生额外 BPF insn，需进一步调试 |

**Round 2 关键进展**：
- WIDE_MEM scanner 修复成功：high-byte-first 2-byte pattern 匹配 load_byte_recompose 和 stride_load_4
- 现有 3/4 directives 有真实覆盖（CMOV + LEA + WIDE_MEM），仅 ROTATE 待修
- xlated_prog_len 不变量全部满足

### 8.2c v4 Round 3 VM 测试（2026-03-10）

> 完整数据见 `docs/tmp/v4-round3-test-results.md`

**ROTATE 突破**：内核 validator+emitter 扩展支持 commuted 4-insn、5-insn two-copy、5-insn masked 三种 clang 实际输出模式。

| Directive | 覆盖率 | 性能 | 代码大小 | 说明 |
|-----------|--------|------|---------|------|
| **ROTATE** | **2 程序，126 sites** | ✅ **rotate64_hash -28.4%，packet_rss_hash -10.5%** | -1150B/-156B | **Round 2→Round 3 突破：0→126 sites** |
| **ROTATE+WIDE_MEM** | rotate64_hash 115+8 | ✅ **-36.6% combined** | -1246B (-35%) | 多 directive 组合验证 |
| **WIDE_MEM** | 3 程序，11 sites | ✅ 无回归 | 无回归 | Round 2 结果保持 |
| **ADDR_CALC (LEA)** | stride_load_16 | ✅ 无回归 | 无回归 | 保持 |

**Round 3 关键里程碑**：
- **ALL 4 directive families 现在都有非零覆盖**（CMOV 受 subprog boundary 限制，但机制已验证）
- rotate64_hash combined optimization -36.6% 展示了框架的 **composability**
- xlated_prog_len 不变量全部满足
- 所有 correctness 检查通过

### 8.2d Kernel-Fixed Baselines 测试（2026-03-10）

> 完整数据见 `docs/tmp/kernel-fixed-baselines-test-results.md`
> Kernel commit: `1572a4ddb` on `jit-fixed-baselines` branch

**CONFIG**: `CONFIG_BPF_JIT_FIXED_{ROTATE,WIDE_MEM,LEA,CMOV}` 全部启用（fixed-all）vs 全部禁用（stock）

| Program | Stock exec_ns | Fixed-all exec_ns | Delta | jited Delta | 说明 |
|---------|------:|------:|------:|------:|------|
| rotate64_hash | 143 | 119 | **-16.8%** | -1178B | ROTATE 匹配 v4 |
| packet_rss_hash | 67 | 57 | **-14.9%** | -151B | ROTATE 匹配 v4 |
| load_byte_recompose | 409 | 356 | **-13.0%** | -12B | WIDE_MEM 匹配 v4 |
| stride_load_4 | 444 | 413 | **-7.0%** | -30B | WIDE_MEM 匹配 |
| stride_load_16 | 437 | 499 | **+14.2%** | -30B | ⚠️ LEA 回归 |
| **log2_fold** | **258** | **331** | **+28.3%** | -2B | **🔴 固定 CMOV 伤害可预测分支** |

**Go/no-go 结论**：
- **PASSED** — 无条件 fixed CMOV 明确伤害 log2_fold（+28.3%），证明 fixed kernel heuristic 不能替代 policy-controlled framework
- ROTATE/WIDE_MEM 基本匹配 v4 框架结果（固定 heuristic 和 framework 效果相当 → 这些是 substrate 优化）
- LEA fixed-all 回归表明组合干扰（fixed-all ≠ 各 directive 独立结果之和）
- xlated_prog_len 不变量 6/6 满足，正确性 12/12 通过

### 8.3 微架构实验摘要

- **CPU 频率敏感性**：binary_search（31.7%）、load_byte_recompose（33.2%）、switch_dispatch（17.3%）
- **输入分布**：branch_layout predictable 0.225x vs random 0.326x
- **PMU**：llvmbpf IPC 普遍高于 kernel（binary_search 6.86 vs 2.41）

---

## 9. TODO（按优先级排序）

### ✅ 已完成

| # | 任务 | 说明 |
|---|------|------|
| 1 | v4 → v5 → v5r2 → v6 设计迭代 | 4 轮设计 + 3 轮 review |
| 2 | Directive 分类体系 | 3 个 policy-sensitive + 4 个 substrate |
| 3 | OSDI/SOSP novelty 分析 | 5 个 why-userspace 理由，go/no-go 条件 |
| 4 | CI 工作流 | GitHub Actions ARM64 + x86（手动触发，修复中） |
| 5 | `bpf_jit_comp.c` 详细分析 | 1474 行分析文档，见 `docs/tmp/bpf-jit-comp-analysis.md` |
| 6 | JIT pass 实现细节 | x86 编码级别分析，见 `docs/tmp/jit-pass-implementation-detail.md` |
| 7 | v6 design review | 机制 gap 分析，见 `docs/tmp/bpf-jit-advisor-v6-review.md` |

### ⚠️ 关键设计决策（待定）

**JIT-level vs Verifier-level 实现方案**

分析发现当前 JIT 线性发射模型（`do_jit()` + `addrs[]`）只能做局部 peephole collapse。这有一个根本矛盾：局部 peephole 不需要 userspace 框架（kernel 直接加就行）。

**分析结论：Hybrid 方向（Path B 主导 + JIT-level 辅助）**

`docs/tmp/verifier-rewrite-approach.md` 分析完成（54KB，1468 行），结论明确：

| 路径 | 思路 | 优势 | 劣势 | **评估结论** |
|------|------|------|------|:---:|
| **A: JIT-level** | directive 指导 JIT emission | 实现清晰，wide_load/cmov_select 可行 | 只能做局部 peephole | **单独不够** |
| **B: Verifier-level** | directive 指导 verifier 做 BPF 指令重写 | 跨架构，支持非局部变换，verifier 已有 CFG/类型 | 安全关键路径，需新基础设施 | **方向正确** |
| **✅ Hybrid** | 结构性变换在 verifier，encoding 在 JIT | 两层各做擅长的事 | 实现分两层 | **推荐方案** |

**Hybrid 分层**：

| 层 | 负责 | 具体 directives |
|----|------|----------------|
| **Verifier rewrite** | 结构性 BPF 程序变换（跨架构） | `byte_load_recompose`、`branch_reorder`、future `subprog_inline` |
| **JIT lowering** | target-specific 编码选择 | `cmovcc/csel` lowering、`lea` fusion、`rotate/BMI2`、encoding choices |
| **Hybrid** | verifier 识别 + JIT lowering | `cmov_select`（verifier 识别 diamond → 内部 select 抽象 → JIT 选择 cmovcc/csel/branch） |

**关键发现**（verifier-rewrite 分析）：
1. verifier 已有 **31 个 `bpf_patch_insn_data()` 调用点**，已经是 BPF late-lowering pass
2. `optimize_bpf_loop()` 已经是非局部结构性变换的先例
3. `branch_reorder` 是 Path B 最强 case——BPF 层面的 CFG permutation，JIT 无法做
4. Pipeline placement：**after `do_check()`, before `convert_ctx_accesses()`**
5. 需要新基础设施：block-permutation helper、optional `BPF_SELECT` 内部 opcode、better provenance

**OSDI/SOSP readiness**（`docs/tmp/osdi-readiness-review.md`）：
- 当前评分：**4/10**
- 最大问题：framing 强于实际 prototype；kernel-fixed baselines 未测试；缺端到端部署
- 到 8/10 需要：settle path、实现多 directive、run kernel-fixed baselines、一个真实部署评估
- `wide_load` 单独看来像 kernel peephole；`branch_reorder` 在 verifier 层才有 novelty

### 🔴 P0 — 当前 sprint：设计定型 + 开始实现

| # | 任务 | 状态 | 说明 |
|---|------|:---:|------|
| 8 | **Verifier-rewrite 方案分析** | ✅ 完成 | Hybrid 推荐：verifier 做结构变换，JIT 做 encoding。见 `docs/tmp/verifier-rewrite-approach.md` |
| 9 | **新 directive 发现 + test cases** | ✅ 完成 | 5 个新 benchmark + 11 候选排名，见 `docs/tmp/directive-discovery-analysis.md` |
| 10 | **Interface 层详细设计** | ✅ 完成 | syscall/blob/CPU contract/安全/部署全覆盖，见 `docs/tmp/interface-design-detail.md` |
| 11 | **确定 JIT-level vs Verifier-level** | ✅ **Hybrid** | 分析结论：verifier 做结构变换 + JIT 做 encoding |
| 12 | **v7 设计文档** | ✅ 完成 | 3245 行，见 `docs/tmp/bpf-jit-advisor-v7.md` |
| 12-r | **v7 review** | ✅ 完成 | **7.5/10**（v6 was 5.5）。4 must-fix：cmov blinding remap、branch_reorder metadata、bounds_window fact、struct size。见 `docs/tmp/bpf-jit-advisor-v7-review.md` |
| 13 | **CI 修复** | ✅ 完成 | x86: `2e008ac` libbpf-dev；ARM64: `1c17332` timing fallback + `d2bd851` packet mapping + `d8edc80` shallow submodule + kernel fallback |
| 23 | **Pure-JIT benchmark 审计** | ✅ 完成 | 49/50 OK，仅 `map_lookup_repeat` 需修。见 `docs/tmp/pure-jit-benchmark-audit.md` |
| 24 | **修复 benchmark + 新增 cmov_select** | ✅ 完成 | `map_lookup_repeat` 移到 runtime；新增 `cmov_select.bpf.c`（L/K=0.181x） |
| 25 | **Host 重跑** | ✅ 完成 | 50 pure-jit + 11 runtime，见 `micro/results/pure_jit_with_cmov.json`。geomean L/K=0.797x |
| 25-v | **VM 重跑 (7.0-rc2)** | ✅ 完成 | kernel VM/host=1.003x (parity)。见 `docs/tmp/vm-rerun-analysis.md` |
| 25-a | **综合结果分析** | ✅ 完成 | 见 `docs/tmp/combined-results-analysis.md`。**未 review** |
| 25-r | **重跑结果 review** | ✅ 完成 | 数据正确；因果语言需弱化（VM≠kernel版本结论），map_lookup_repeat 3ns 差异是噪声，需严格重跑。见 `docs/tmp/rerun-results-review.md` |
| 26 | **ARM64 CI 全流程** | ✅ 完成 | 3 轮修复，最终 llvmbpf+kernel 都在 ARM64 成功。run `22835784942` |
| 26-a | **ARM64 跨架构分析** | ✅ 完成 | ARM64 pure-jit L/K=0.656x（vs x86 0.797x）。见 `docs/tmp/arm64-cross-arch-analysis.md`。**未 review** |
| 26-r | **ARM64 分析 review** | ✅ 完成 | 数据正确；因果语言需弱化（runtime≠backend quality），需同 SHA 重跑+disassembly 证据。见 `docs/tmp/arm64-analysis-review.md` |
| 27 | **Kernel POC v1 分支** | ⚠️ **方向错误** | wide_load 是 BPF bytecode rewrite，不是 JIT backend 优化。userspace 也能做同样的事。见 `docs/tmp/poc-design-review.md` |
| 27-v | **POC v1 端到端验证** | ⚠️ **方向错误** | 2.21x 加速数字可信，但证明的不是 JIT directive，而是 BPF 指令级变换。xlated_prog_len 变了说明是 BPF rewrite |
| 27-fix | **POC v1 根本问题分析** | ✅ 完成 | v1 的 wide_load 本质是 verifier-side BPF 指令重写，K2/Merlin 等 bytecode 优化器也能做。与论文 "backend JIT 优化" thesis 矛盾。见 `docs/tmp/poc-design-review.md` |
| 28 | **POC v2：真正的 JIT-level directive** | 🔄 进行中 | `cmov_select` JIT lowering：BPF 不变，只改 native code emission（cmovcc vs jcc+mov）。分支 `jit-directive-poc-v2`。关键不变量：xlated_prog_len 不变，jited_prog_len 变小 |
| 12-f | **v7 must-fix** | ✅ 完成 | cmov blinding→fail-closed, branch_reorder metadata 补全, bounds_window 缩窄, struct 56B |
| 14-r | **Interface review** | ✅ 完成 | 6/10，主要问题：假设简化的 kernel pipeline、scope 与 v6 不一致、缺 multi-subprog。见 `docs/tmp/interface-design-review.md` |
| 15-r | **Cross-doc review** | ✅ 完成 | 每个 directive 的 blob/JIT/证据交叉验证 + Hybrid 分层建议。见 `docs/tmp/cross-document-review.md` |
| 16-r | **OSDI readiness review** | ✅ 完成 | 4/10，见 `docs/tmp/osdi-readiness-review.md` |

### 🟡 P1 — v4 Post-load Re-JIT 框架实现

> **2026-03-09 方向演化**：v3 设计（8/10 review）确认了可扩展框架方向。
> v4 进一步简化：(1) 机器码级 instruction selection 是 userspace policy (2) 从 BPF_PROG_LOAD 分离出 BPF_PROG_JIT_RECOMPILE。
>
> **v4 POC 已实现**：4 个 directive (COND_SELECT + WIDE_MEM + ROTATE + ADDR_CALC)，BPF_PROG_JIT_RECOMPILE syscall 工作，VM 验证通过。
> **关键发现**：log2_fold cmov recompile **+28% 变慢**，直接验证 policy-sensitivity thesis。
>
> **已修复**：correctness bug（interior edge check + flag-clobber fix + subprog boundary）。
> **已补齐**：ROTATE (rorx/ror, BMI2 gating) + ADDR_CALC (LEA fusion) + cpu_features_required + per-rule logging。
> **待验证**：VM 测试新 directive 正确性和性能（sonnet agent 进行中）。

| # | 任务 | 说明 | 状态 |
|---|------|------|:---:|
| 15 | **Transport + blob parser + fail-closed** | 复用 v1 skeleton，POC v2 中实现了基础版本 | ✅ |
| 28 | **POC v2: cmov_select JIT lowering** | ✅ 设计不变量证明成功（xlated 不变，jited 变）。已提交 `dd81852` | ✅ |
| 28-r | **POC v2 设计一致性审查** | ✅ 实现忠实于狭义目标。已知 bug：diamond+BPF_X 未 lower。见 `docs/tmp/poc-v2-design-conformance-review.md` | ✅ |
| 17-fix | **wide_load 重新定位** | v3 框架下作为 rule 之一；不再是独立 verifier rewrite | 归入 #35 |
| 29 | **第二个 JIT directive** | 原计划 `lea_fusion`/`rotate_fusion`，现归入 v4 rule 体系 | 归入 #35 |
| 20 | **branch_reorder** | verifier-level CFG permutation，v4 scope 外（xlated 不变限制） | scope 外 |
| 30 | **v3 框架设计** | 可扩展 JIT pass 框架详细设计。见 `docs/tmp/jit-pass-framework-v3-design.md`。已被 v4 取代 | 已被 v4 取代 |
| 30-v4 | **v4 框架设计** | Post-load re-JIT + 机器码级 policy。见 `docs/tmp/jit-pass-framework-v4-design.md` | ✅ |
| 35 | **v4 POC 实现** | BPF_PROG_JIT_RECOMPILE + 通用 dispatcher + 4 directives。branch `jit-directive-v4`，~850 LOC kernel | ✅ 框架 + 4 rule |
| 35-bug | **v4 correctness bug** | ✅ 已修复：interior edge check + flag-clobber (emit_mov_imm32_noflags) + subprog boundary。见 `docs/tmp/v4-bug-diagnosis.md` | ✅ 已修复 |
| 35-gap | **v4 实现差距分析** | 13 个 gap 中已修 10 个。见下方详细列表 | ✅ 大部分修复 |
| 35-r | **v4 实现 review** | sonnet 对比 plan+设计文档全面审查。见 `docs/tmp/v4-implementation-review.md`。评分 6/10，10 个 gap (R1-R10) | ✅ |
| 35-vm | **v4 新 directive VM 测试** | 4 个 directive 在 VM 中端到端测试。见 `micro/results/v4_new_directives_test.json`。LEA 唯一有覆盖 | ✅ |
| 35-r1 | **Round 1 修复 + 重测** | R1/R3/R5/R6/R7 修复。无回归。ROTATE/WIDE_MEM 仍 0 覆盖（scanner pattern mismatch）。见 `docs/tmp/v4-round1-test-results.md` | ✅ |
| 35-r2 | **Round 2: Scanner pattern 适配** | WIDE_MEM 突破（0→11 sites，-13%/-14%）。ROTATE 仍 0（shift mask 问题）。见 `docs/tmp/v4-round2-test-results.md` | ⚠️ WIDE ✅ ROT ❌ |
| 35-r3 | **Round 3: ROTATE 修复** | ✅ ROTATE 突破：0→126 sites（rotate64_hash 115, packet_rss_hash 11）。-28.4% exec，-32.3% code。ALL 4 directive families now active。见 `docs/tmp/v4-round3-test-results.md` | ✅ |
| 36 | **v4 补充 directive: ROTATE** | rorx vs ror，BMI2 gating。validator + emitter + userspace scanner 已实现 | ✅ 已实现 |
| 37 | **v4 补充 directive: ADDR_CALC** | lea vs mov+shl+add。validator + emitter + userspace scanner 已实现 | ✅ 已实现 |
| 38 | **v4 补充 directive: ZERO_EXTEND** | movzx vs xor+mov，非常普遍 | ❌ 未开始 |
| 39 | **v4 policy A/B 对比** | ✅ log2_fold 6 sites：baseline 764ns vs cmov 824ns (+7.9%)。可预测分支 cmov 变慢，验证 policy-sensitivity | ✅ |
| 40 | **v4 cpu_features_required** | UAPI `bpf_jit_rewrite_rule.cpu_features_required` + kernel `boot_cpu_has()` 检查 | ✅ 已实现 |
| 41 | **v4 per-rule logging** | `pr_debug` 报告每条 rule 的 accept/reject | ✅ 已实现 |
| 31 | **v3 rule 解释器** | 已被 v4 简化设计取代 | 已被 v4 取代 |
| 32 | **v3 5+ rules** | 归入 v4 #36-38 | 归入 v4 |
| 33 | **v3 x86 target backend** | v4 已实现通用 dispatcher | 归入 #35 |
| 34 | **v3 arm64 target backend** | 跨架构验证 | ❌ |
| 43 | **Scanner framework 独立化** | 从 kernel_runner.cpp 提取为顶级 `scanner/` 目录，独立 C++ 库/CLI | ✅ 完成 |
| 46 | **cmov_select subprog scan 修复** | ✅ scanner 扫全程（0→1 site）。kernel 改为 subprog-local 验证。⚠️ 正确性 bug：cmov_select recompile 改变 result。见 `docs/tmp/cmov-subprog-fix-results.md` | ⚠️ scanner ✅ emitter bug |
| 47 | **Per-directive 隔离测试** | ✅ 4 个隔离 CONFIG 各自测试。CMOV-only 只改 log2_fold（+19.7%），code size 可加但 exec time 不可加。见 `docs/tmp/kernel-fixed-baselines-per-directive.md` | ✅ |
| 44 | **Kernel-fixed baselines 设计** | ✅ 设计完成。ROTATE/WIDE/LEA 固定 heuristic 能匹配框架；CMOV 是 go/no-go（policy-sensitive）。~80 LOC 实现。见 `docs/tmp/kernel-fixed-baselines-design.md` | ✅ 设计完成 |
| 45 | **Policy decision layer 设计** | workload-aware 策略选择（不是硬编码 scanner），论文 story 核心。见 `docs/tmp/policy-decision-layer-design.md` | ✅ 设计完成 |
| 21 | **kernel-fixed baselines** | ✅ fixed-all 测试完成。log2_fold +28.3% 回归 → go/no-go PASSED。fixed-all ≠ framework-smart。见 `docs/tmp/kernel-fixed-baselines-test-results.md` | ✅ 初测完成 |
| 48 | **v5 minimal declarative pattern POC** | ✅ 通用 pattern matcher + canonical lowering。rotate64_hash v5=v4（115 sites, jited 2409）。load_byte_recompose v5=v4（1 site, jited 410）。新 pattern 只需改 userspace data。见 `docs/tmp/v5-minimal-poc-results.md` | ✅ |
| 55 | **v5 迭代改进** | ✅ CMOV 上 v5（6 sites，+76% policy-sensitive）。v5 代码移入 scanner/。overflow-safe bounds。kernel-owned CPU legality。--recompile-v5 --recompile-all。5 程序全部正确。见 `docs/tmp/v5-iteration-results.md` | ✅ |
| 49 | **Scanner cleanup + 框架统一** | ✅ scanner/ 是唯一实现。micro/runner 通过 CMake link libscanner.a。kernel_runner.cpp 删除全部重复 scanner/blob 代码。见 `docs/tmp/scanner-cleanup-results.md` | ✅ |
| 50 | **Real program directive census** | ✅ 98 个 EM_BPF 扫描：67/98 有 sites，1029 总 sites。Corpus CMOV 最普遍（18/10prog）。见 `docs/tmp/real-program-directive-census.md` + `micro/directive_census.py` | ✅ |
| 52 | **Corpus 真实执行性能测试** | ✅ 36 objects, 57 programs, 31 loadable, 10 runnable。**0 个可跑程序有 directive sites**。有 sites 的程序是 tracing 类型无法用 bpf_prog_test_run。需要扩充 XDP/TC corpus（Cilium/Katran）。见 `docs/tmp/corpus-perf-results.md` + `micro/run_corpus_perf.py` | ⚠️ corpus 不足 |
| 53 | **Benchmark 基础设施审计** | ✅ 6+ 个散落的测试入口，v5 blob builder 仍在 kernel_runner.cpp 内，缺统一编排。建议统一到 bench/ driver + 单一 YAML 配置。见 `docs/tmp/benchmark-infrastructure-audit.md` | ✅ 设计完成 |
| 54 | **Corpus 扩充 + kprobe/tp 测试方法** | ✅ 468 .bpf.o（含 selftests+bcc+xdp-tools repos），429 census，40 个真实程序同时有 sites+性能数据（29 test_run + 11 tracing）。`run_corpus_tracing.py` 实现 attach+trigger 测量。cilium/katran/xdp-tools 编译产物仍为 0。见 `docs/tmp/expanded-corpus-results.md` | ✅ |
| 56 | **Corpus v5 framework recompile** | ✅ 40 程序中 37 apply v5 成功，28 有 runtime 数据。xdp_synproxy +15%/+31% faster。CMOV-only 程序多数变慢（policy-sensitivity 证据）。2 个 rotate-heavy TC 程序 v5 scanner 0 sites（gap）。见 `docs/tmp/corpus-v5-recompile-results.md` | ✅ |
| 51 | **Framework architecture review** | ✅ 4/10，主要问题：bounds overflow、CPU gating、v4 vs v5 gap、userspace 分裂。见 `docs/tmp/framework-architecture-review.md` | ✅ |
| 55 | **v5 实现 review** | ✅ **4.5/10**→**6.5/10**。核心问题：canonical binding 层缺失、CMOV 未上 v5、v5 代码未合入 scanner。已修复：CMOV 上 v5、scanner 统一、overflow-safe、CPU legality。仍缺：binding table + parameterized emitter。见 `docs/tmp/v5-implementation-review.md` + `docs/tmp/v5-design-gap-analysis.md` | ✅ |
| 68 | **v5 design gap analysis** | ✅ **6.5/10**。10 项特性矩阵：constraint ✅、coexistence ✅、scanner integration ✅。缺：binding table (#58)、opcode mask (#67)、shape whitelist (#63)。见 `docs/tmp/v5-design-gap-analysis.md` | ✅ |
| 69 | **Production corpus 编译** | ✅ Cilium 3 程序（658 CMOV sites）、Katran 5 程序（29 sites）、xdp-tools 13、xdp-tutorial 25。总 493 .bpf.o。见 `docs/tmp/production-program-compilation.md` | ✅ |
| 70 | **Production corpus v5 recompile 测试** | ✅ 15/15 recompile 成功。katran balancer 5C+4W code -0.2%，xdp_vlan_swap 1C+1W code -5.7%。Cilium 仍无法加载。见 `docs/tmp/production-corpus-v5-rerun-results.md` | ✅ |
| 71 | **Corpus 扩充 Round 2** | ✅ +21 .bpf.o（493→514）。loxilb 912 sites/prog（863 WIDE），Calico 314 sites（10 ROTATE），Suricata/systemd/tubular/netbird。见 `docs/tmp/corpus-expansion-round2.md` | ✅ |
| 72 | **Scanner rotate gap 修复** | ✅ rotate6_masked(AND64_X) var binding bug。core_kern 0→818，test_verif_scale2 0→992，calico/from_hep_debug 0→10。scanner 47/47。见 `docs/tmp/scanner-gap-fix.md` | ✅ |
| 73 | **loxilb/Calico v5 recompile 测试** | loxilb 863 WIDE + Calico 10 ROTATE 测试 | 🔄 codex |
| 74 | **严格 benchmarking** | ✅ 10×1000, CPU pin host#23, perf governor, turbo off, Wilcoxon BH-adjusted。CMOV 0.655x (p=0.002)，ROTATE 1.193x/1.235x (p=0.002)，LEA 1.052x (p=0.012)，WIDE 不显著 (p=0.164)。见 `docs/tmp/rigorous-benchmark-results.md` | ✅ |
| 75 | **论文更新** | 集成所有新数据到 paper.tex | 🔄 codex |
| 56 | **cmov_select emitter bug 修复** | subprog CMOV 产出错误结果（baseline→recompile result 不一致）。需在 linux-framework 上修复 emitter | 🔄 codex |
| 57 | **严格 benchmarking 脚本** | CPU pinning + performance governor + 30×1000 + 统计检验 + 多模式对比 | 🔄 codex |
| 22 | **消融补全** | cmov ablation 已有，补 byte-recompose / callee-saved / BMI | ❌ |

### 🔴 P0.6 — v5 实现改进（基于 review，4.5/10 → 8/10）

> **v5 review 评分 4.5/10**（`docs/tmp/v5-implementation-review.md`）。核心差距是"新 pattern 只需改 userspace"的论文声明只部分成立。

#### v5 Blocker（论文 hard block）

| # | 任务 | 说明 | 优先级 |
|---|------|------|:---:|
| 58 | **Canonical binding table + parameterized emitter** | ✅ v2 rule 携带 binding_count + struct bpf_jit_binding。kernel 提取 canonical params 后传给 emitter。COND_SELECT + ROTATE 验证通过。见 `docs/tmp/v5-canonical-binding-results.md` | ✅ |
| 59 | **COND_SELECT 上 v5 path** | 论文最重要的 policy-sensitive case 必须走 v5 声明式框架，否则 reviewer 直接问"为什么最关键的 directive 不用你的框架" | **Critical** |
| 60 | **v5 代码移入 scanner/** | v5 descriptor 定义、matcher、blob builder 从 kernel_runner.cpp 移到 scanner 库，消除"权威实现"分裂 | **High** |
| 61 | **Overflow-safe bounds check** | kernel matcher/validator 中 `site_start + site_len` 缺溢出检查。所有相关路径改用 `check_add_overflow()` | **High** |
| 62 | **Kernel-owned CPU legality** | 从 `(canonical_form, native_choice)` 推导 required CPU features，不信任 blob 的 `cpu_features_required`。例如 RORX 必须 kernel 检查 BMI2 | **High** |

#### v5 改进（论文加分）

| # | 任务 | 说明 | 优先级 |
|---|------|------|:---:|
| 63 | **Shape whitelist 扩展或泛化** | `bpf_jit_pattern_rule_shape_valid()` 硬编码 site_len 白名单（rotate: 4/5/6, wide: 4/10/22）。新 pattern 即使 userspace-only 也可能被 kernel 拒绝。改为 per-canonical-form 的 max_site_len | **Medium** |
| 64 | **Overlap/priority 语义** | 当前 kernel 不拒绝也不仲裁重叠 rule。要么明确 reject overlap，要么实现 priority-aware lookup | **Medium** |
| 65 | **Subprog 一致性** | kernel 仍 deactivate 非 main-subprog rule（jit-directive-v4）vs 已有 subprog-local 修复（jit-fixed-baselines）。两个分支需同步 | **Medium** |
| 66 | **Extensibility 量化** | 统计 v4 vs v5 添加新 pattern 的代码量对比（v4: ~200 LOC kernel; v5: ~20 LOC userspace-only + 0 kernel for same-form）。论文 Table 需要这个数据 | **Medium** |
| 67 | **Opcode mask/class 支持** | v5 design 说支持 opcode mask（如"any conditional jump"），但实现只有 exact opcode 匹配。添加 `BPF_JIT_CONSTRAINT_OPCODE_MASK` 或类似机制 | **Low** |

#### v4 实现差距摘要（初始 Gap Review 2026-03-09，已大部分修复）

| 优先级 | 差距 | 说明 | 状态 |
|--------|------|------|:---:|
| **Critical** | 只有 2/4+ rule kind | 需至少 ROTATE + ADDR_CALC 证明 general | ✅ 已有 4 个 |
| **Critical** | Correctness bug | cmov emitter 产生错误结果 | ✅ 已修复 |
| **Critical** | 无 CPU feature gating | UAPI 缺 cpu_features_required 字段 | ✅ 已实现 |
| **Major** | BPF_JIT_SEL_BRANCH 未测 | ✅ log2_fold A/B: baseline(branch) 764ns vs cmov 824ns (+7.9%)，验证 policy-sensitivity | ✅ |
| **Major** | 无 payload 字段 | kernel 靠 re-parse insn，不可扩展 | ❌ |
| **Major** | 无 logging | 用户态不知道 rule 接受/拒绝 | ⚠️ 仅 pr_debug |
| **Major** | 无 iterative policy 对比 | 只能一次性 apply，不能 A → B → iterate | ❌ |

#### v4 implementation review 差距（2026-03-09，评分 6/10）

> 完整审查见 `docs/tmp/v4-implementation-review.md`

| # | 优先级 | 差距 | 说明 | 状态 |
|---|--------|------|------|:---:|
| R1 | **Critical** | Layer-2 side-effect check 缺失 | rule site 内可能包含 BPF_CALL/store/atomic，应在所有 validator 前统一检查 | ✅ R1 修复 |
| R2 | **Critical** | Re-JIT 非原子 | `bpf_int_jit_compile()` 直接调用，无 RCU 保护。POC+test_run 下可接受，production 不安全 | ⚠️ POC OK |
| R3 | **Critical** | ROTATE scanner 不生成 RORX | 总是 BPF_JIT_ROT_ROR，BMI2 gating 从未被测试。论文 CPU feature demo 无效 | ✅ R1+R2 修复 |
| R4 | **Critical** | jit_recompile attr 缺 log_level/log_buf/log_size | 用户态无法观察 rule accept/reject。Policy 迭代故事缺关键 feedback | ❌ |
| R5 | **Major** | Policy leak on OOM | re-JIT 失败后 policy 留在 prog->aux->jit_policy 上未释放 | ✅ R1 修复 |
| R6 | **Major** | WIDE_MEM/ADDR_CALC scanner 未限制 main subprog | cmov scanner 有限制，其他没有。fail-closed 安全但不一致 | ✅ R1 修复 |
| R7 | **Major** | WIDE_MEM validator 允许 width 3/5/6/7 | emitter 拒绝但 validator 通过，浪费验证。应 validator 直接拒绝 | ✅ R1 修复 |
| R8 | **Minor** | LEA emitter dead add_3mod call | 计算后被覆盖，无害但混乱 | ❌ |
| R9 | **Minor** | ARM64 native_choice 枚举未预留 | 设计文档有 CSEL/EXTR 等，UAPI 中缺 | ❌ |
| R10 | **Minor** | rule_kind 编号与设计文档不一致 | WIDE_MEM=2 vs 设计 ADDR_CALC=2。内部一致但与文档矛盾 | ⚠️ 需同步 |

### 🔴 P0.5 — v5 声明式 Pattern + Canonical Lowering 设计

> **核心洞察**：当前 v4 的 rule_kind 是 closed enum，每种新优化需改 kernel。但大多数"新优化"只是同一 canonical form 的新 BPF pattern（如 4-insn vs 6-insn rotate，low-first vs high-first byte ladder）。
>
> **v5 方向**：把 BPF pattern 描述移到 userspace policy blob，kernel 只保留通用 pattern matcher + canonical form lowering。
> - 新 BPF pattern → 只改 userspace（不需要 kernel release cycle）
> - 新 canonical form → 改 kernel emitter（~50 LOC/arch，rare）
> - 安全模型：pattern matching = read-only（安全），native emission = kernel 控制
> - 类比：IDS signature update 不需要改 engine；LLVM SelectionDAG pattern → canonical → target lowering
>
> **v4 POC 继续迭代**：v5 设计与 v4 POC 并行。v4 必须先做到有真实性能优化证据，v5 是设计层面的升级。

| # | 任务 | 状态 |
|---|------|:---:|
| 42 | **v5 声明式 pattern 框架设计文档** | ✅ ~950 行。见 `docs/tmp/jit-pass-framework-v5-design.md` |
| 42-r | **v5 设计 review** | ✅ **7.5/10**。5 must-fix：DIFF_CONST 缺失、8B wide 超限、类型混淆、ja dst_reg、MAX_BINDINGS。见 `docs/tmp/jit-pass-framework-v5-review.md` |
| 42-fix | **v5 must-fix 修复** | ✅ 5 项全部修复：DIFF_CONST、MAX_PATTERN_LEN 24、类型检查、expected_dst/src_reg、MAX_BINDINGS 12 |

### 🟠 P1.5 — v4 迭代改进路线（基于 review）

> **原则**：每轮改进由 opus 实现 → sonnet 测试/review → 迭代直到收敛。

#### Round 1：安全 + 正确性（opus）
| 任务 | 说明 |
|------|------|
| R1 fix | 在所有 validator 前加 layer-2 统一检查：扫描 site 内 BPF_CALL/BPF_ST/BPF_ATOMIC → reject |
| R3 fix | ROTATE scanner 生成 RORX 规则（cpu_features_required=BPF_JIT_X86_BMI2），加 `--rotate-rorx` flag 或自动检测 |
| R5 fix | re-JIT OOM 时清理 policy |
| R7 fix | WIDE_MEM validator 只接受 width ∈ {2,4,8} |
| R6 fix | 所有 scanner 统一限制 main subprog |

#### Round 2：Policy 迭代能力（opus）
| 任务 | 说明 |
|------|------|
| R4 fix | jit_recompile attr 加 log_level/log_buf/log_size，kernel 写 rule accept/reject 到 log_buf |
| A/B test | 加 `--policy-branch` flag：对 cmov sites 生成 BPF_JIT_SEL_BRANCH 规则，对比 cmov vs branch |
| Iterative | 实现 re-JIT → 测量 → 修改 policy → 再 re-JIT 的完整 PGO 流程演示 |

#### Round 3：论文数据收集（sonnet）
| 任务 | 说明 |
|------|------|
| A/B benchmark | 对每个 cmov site 分别测 cmov 和 branch policy，证明 policy-sensitivity |
| RORX benchmark | 在有 BMI2 的 CPU 上测 rorx vs ror，证明 CPU feature sensitivity |
| Wide load benchmark | 测有 byte-load ladder 的程序（load_byte_recompose 等） |
| Extensibility metric | 统计添加每个新 rule kind 的代码量，证明框架可扩展 |

#### Round 4：kernel-fixed baseline 对照（OSDI go/no-go）
| 任务 | 说明 |
|------|------|
| fixed-cmov kernel | 在 kernel 中硬编码 cmov peephole（不需要框架），测性能 |
| fixed-wide kernel | 在 kernel 中硬编码 wide_load peephole，测性能 |
| 对比分析 | fixed kernel heuristic vs framework policy，找到 framework 独有价值的 case |

**正确 directive 的判断标准**（POC v1 教训）：用户态能不能做同样的事？如果能 → 错误的层。
- ❌ `wide_load` verifier rewrite：改写 BPF 指令 → 用户态也能做
- ✅ `cmov_select` JIT lowering：选择 cmovcc vs jcc+mov → 只有 JIT 能做
- ✅ `lea_fusion`：选择 lea vs mov+shl+add → 只有 x86 JIT 能做
- ✅ `rotate_fusion`：选择 rorx/BMI2 → 只有 JIT 知道 CPU features
- ✅ v3 framework：用户态定义 rule，但 rule 控制的是 **native emission 选择**，不是 BPF rewrite

**POC v1 → v2 → v3 演化路径**：
- v1 `wide_load` verifier rewrite：❌ 错误方向（BPF bytecode 变换，用户态也能做）
- v2 `cmov_select` JIT lowering：✅ 正确方向（native code 变，BPF 不变），但硬编码、不可扩展
- **v3 extensible framework**：✅ 论文目标（用户态定义 rule，内核安全执行，可扩展）

**试金石**：如果 `xlated_prog_len` 变了，说明优化在错误的层。v3 的所有 rule 都必须满足此不变量。

### 🟢 P2 — 自动化 + 评估 + 合并

| # | 任务 | 说明 |
|---|------|------|
| 22 | 自动 directive 生成器 | llvmbpf 分析 → 自动产出 directives |
| 23 | Policy 实验 | 同一程序在不同 CPU/workload 下的 policy 差异 |
| 24 | 真实程序评估 | 36 unique real-program directive census |
| 25 | 端到端部署评估 | Cilium/Katran 级别的 deployment evidence |
| 26 | arm64 分析 | CI 数据 + JIT dump + acceptance census |
| 27 | 两篇论文合并 | characterization + optimization 完整故事 |

---

## 10. 设计迭代历史

| 版本 | 核心思路 | 结果 | 文档 |
|------|----------|------|------|
| v4 | Target-independent IR + lift→compare→emit | ❌ 太重，IR freeze 是 blocker | `docs/tmp/bpf-jit-advisor-design-v4.md` |
| v5 | Microarch-aware directives | review 5-7/10，µarch 故事太弱 | `docs/tmp/bpf-jit-advisor-v5.md` |
| v5r2 | 聚焦 wide_load + cmov_select，legality/profitability 分离 | review 7-9/10，JIT-level mechanism ready | `docs/tmp/bpf-jit-advisor-v5r2.md` |
| v6 | Backend policy plane framing，expanded directive taxonomy | review 发现 JIT 线性模型限制 | `docs/tmp/bpf-jit-advisor-v6.md` |
| **v7** | **Hybrid：verifier structural rewrite + JIT target-specific lowering** | **设计定型，被 v3/v4 取代为实现路径** | **待写，综合 verifier-rewrite + interface-design + reviews** |
| **v3** | **可扩展 JIT pass 框架**（5 层基础设施：family/plan/alt table/dispatcher/arbitration） | review **8/10**，设计完善但 POC 阶段过重 | `docs/tmp/jit-pass-framework-v3-design.md` |
| **v4** | **Post-load re-JIT + 机器码级 policy**（BPF_PROG_JIT_RECOMPILE + 直接指定 native instruction） | **POC 已实现**，4 directives，Round 2 scanner 修复中 | `docs/tmp/jit-pass-framework-v4-design.md` |
| **v5** | **声明式 Pattern + Canonical Lowering**（pattern 描述在 userspace blob，kernel 通用 matcher + 固定 canonical lowering） | ✅ 设计完成 | `docs/tmp/jit-pass-framework-v5-design.md` |

### 10.1 关键发现（v6 review + JIT 分析后）

1. **`orig_idx` 已存在**于 `insn_aux_data` 中，只需修复 rewrite expansion 传播
2. **x86 JIT 不是两 pass**——是 convergence loop + final image pass，directive 必须跨 pass 确定性一致
3. **线性 `do_jit()` + `addrs[]` 只能做局部 peephole**——wide_load/cmov_select 可行，branch_reorder/subprog_inline 不行
4. **Constant blinding 是独立的第二次重写**——v1 必须显式处理（当前设计直接 drop directive set）
5. **Path B（verifier-level rewrite）可能更有前景**——verifier 已有 CFG 和 `bpf_patch_insn_data()`，重写后 JIT 照常线性发射，自动跨架构

---

## 11. VM 实验矩阵

| 配置 | Kernel | 状态 | 结果 |
|------|--------|:---:|------|
| baseline-host | 6.15.11 | ✅ | authoritative 31-case 数据 |
| baseline-vm (kernel only) | 7.0-rc2 | ✅ | geomean 0.881x vs host |
| baseline-vm (L/K) | 7.0-rc2 llvmbpf + kernel | ✅ | L/K ~0.850x |
| ~~opt1-vm~~ | ~~7.0-rc2 + byte-recompose verifier rewrite~~ | ⚠️ **方向错误** | v1 POC 证明了 2.21x，但这是 BPF 层优化，不是 JIT directive |
| **opt-cmov-vm** | **7.0-rc2 + cmov_select JIT lowering** | ✅ | xlated 7480→7480，jited 4168→4167，exec +13.2%（可预测分支下 cmov 更慢，验证 policy-sensitivity） |
| opt-lea-vm | 7.0-rc2 + lea_fusion JIT lowering | 归入 v3 | 作为 v3 rule 之一实现 |
| opt3-vm | 7.0-rc2 + branch_reorder | 归入 v3 | 作为 v3 rule 之一实现 |
| opt-all-vm | 7.0-rc2 + all directives | 归入 v3 | 由 opt-v3-vm 统一覆盖 |
| **opt-v4-vm** | **7.0-rc2 + v4 re-JIT 框架 (COND_SELECT)** | ✅ | log2_fold: 6 sites, 648→664B, **+28% 变慢**（验证 policy-sensitivity）；cmov_select: 1 site, 4168B 不变。correctness bug ✅已修 |
| **opt-v4-vm-wide** | **7.0-rc2 + v4 re-JIT (WIDE_MEM)** | ⚠️ | **0 覆盖**：clang 不产生 sequential byte ladder。Scanner pattern 需适配 |
| **opt-v4-vm-rotate** | **7.0-rc2 + v4 re-JIT (ROTATE)** | ⚠️ | **0 覆盖**：clang 编译 rotate 为带 mask 变体。Scanner pattern 需适配 |
| **opt-v4-vm-lea** | **7.0-rc2 + v4 re-JIT (ADDR_CALC)** | ✅ | **4 程序 5 sites。stride_load_16 -12%，multi_acc_4 -7%** |
| **opt-v4-vm-all** | **7.0-rc2 + v4 re-JIT (4 rules)** | ✅ | 正确性 100%。只有 LEA + cmov 有实际覆盖。见 `micro/results/v4_new_directives_test.json` |
| opt-v3-vm | 7.0-rc2 + v3 可扩展框架 | 已被 v4 取代 | v4 POC 已实现框架核心功能 |
| **fixed-all-vm** | **7.0-rc2 + all 4 fixed heuristics** | ✅ | **ROTATE/WIDE 匹配 v4，CMOV 伤害 log2_fold +28.3%，LEA 组合回归。见 `docs/tmp/kernel-fixed-baselines-test-results.md`** |
| **fixed-ROTATE-vm** | **7.0-rc2 + ROTATE-only** | ✅ | rotate64_hash -12.1%，packet_rss_hash +2.7%（code -151B）。见 `docs/tmp/kernel-fixed-baselines-per-directive.md` |
| **fixed-WIDE-vm** | **7.0-rc2 + WIDE-only** | ✅ | load_byte_recompose -14.2%，覆盖广于预期 |
| **fixed-LEA-vm** | **7.0-rc2 + LEA-only** | ✅ | stride_load_4 -11.9%，stride_load_16 +141.4% 回归 |
| **fixed-CMOV-vm** | **7.0-rc2 + CMOV-only** | ✅ | **只改 log2_fold codegen（+34B），+19.7% 变慢**。其他 5 程序 jited_len 不变 |
| opt-arm64-vm | v4 framework on arm64 | ❌ | 跨架构验证 |

---

## 12. 开发环境

```
VM:        QEMU/KVM + virtme-ng
Kernel:    vendor/linux (v7.0-rc2) as submodule
JIT file:  arch/x86/net/bpf_jit_comp.c
Benchmark: micro/run_micro.py + micro_exec via BPF_PROG_TEST_RUN
Baseline:  host 6.15.11 authoritative + VM 7.0-rc2 unmodified
CI:        GitHub Actions ARM64 + x86 (manual trigger)
```

---

## 13. 参考文档

| 文档 | 内容 |
|------|------|
| **`docs/tmp/jit-pass-framework-v5-design.md`** | **v5 声明式 Pattern + Canonical Lowering 设计（v4 的架构升级，pattern 在 userspace，canonical lowering 在 kernel）** |
| **`docs/tmp/jit-pass-framework-v4-design.md`** | **v4 Post-load re-JIT + 机器码级 policy 框架设计（v5 的前身，保留作参考）** |
| **`docs/tmp/jit-pass-framework-v3-design.md`** | **v3 可扩展 JIT pass 框架设计（已被 v4 取代，保留作参考）** |
| **`docs/tmp/jit-pass-framework-v3-review-r2.md`** | **v3 review（7.5/10 → 修订后 8/10）** |
| **`docs/tmp/jit-pass-framework-v3-final-verdict.md`** | **v3 最终评审（8/10，3 个 API 合约细节）** |
| **`docs/tmp/poc-v2-design-conformance-review.md`** | **POC v2 设计一致性审查（codex review）** |
| **`docs/tmp/poc-design-review.md`** | **POC v1 全面评审：为什么 wide_load verifier rewrite 是错误方向** |
| **`docs/tmp/poc-v2-implementation-summary.md`** | **POC v2 实现说明：cmov_select 真正的 JIT-level directive** |
| **`docs/tmp/bpf-jit-advisor-v7.md`** | **v7 Hybrid 设计（被 v3 框架取代为主方向）** |
| `docs/tmp/bpf-jit-advisor-v6.md` | v6 设计（已被 v7 取代） |
| **`docs/tmp/interface-design-detail.md`** | **接口详细设计：syscall、blob 格式、CPU contract、安全分析、部署场景** |
| **`docs/tmp/directive-discovery-analysis.md`** | **Directive 发现分析：11 候选排名、5 新 benchmark、真实 workload 证据** |
| **`docs/tmp/verifier-rewrite-approach.md`** | **Path B 分析：verifier rewrite 方案、31 处 patch 清单、Hybrid 推荐** |
| **`docs/tmp/osdi-readiness-review.md`** | **OSDI/SOSP 准备度评估：4/10，关键 gaps 和 "why not just" 回答** |
| **`docs/tmp/interface-design-review.md`** | **Interface review：6/10，pipeline 简化、scope 不一致、缺 multi-subprog** |
| **`docs/tmp/cross-document-review.md`** | **跨文档交叉验证：每个 directive 的 blob/JIT/证据兼容性 + Hybrid 实现建议** |
| `docs/tmp/bpf-jit-comp-analysis.md` | JIT 源码详细分析（1474 行） |
| `docs/tmp/jit-pass-implementation-detail.md` | JIT pass x86 编码级别实现细节 |
| `docs/tmp/bpf-jit-advisor-v6-review.md` | v6 review（发现 JIT 线性模型限制） |
| `docs/tmp/bpf-jit-advisor-v5r2.md` | v5r2 设计（implementation-ready 机制细节） |
| `docs/tmp/bpf-jit-advisor-v5r2-review-r2.md` | v5r2 最终 review（7-9/10） |
| `docs/tmp/bpf-jit-advisor-design-v4.md` | v4 设计（已废弃） |
| `docs/tmp/vm_vs_host_detailed_analysis.md` | VM 7.0-rc2 vs Host 6.15 |
| `docs/tmp/additional_jit_optimizations.md` | Tier 2 优化机会（初期分析） |
| `docs/tmp/microarch_experiments.md` | 微架构实验结果 |
| `micro/results/vm_vs_host_comparison.md` | VM vs Host 简要对比 |
| `.github/workflows/arm64-benchmark.yml` | ARM64 CI（手动触发） |
| `.github/workflows/x86-benchmark.yml` | x86 CI（手动触发） |
| **`docs/tmp/v4-bug-diagnosis.md`** | **v4 correctness bug 诊断：flag-clobber + subprog boundary，修复过程记录** |
| **`docs/tmp/v4-implementation-review.md`** | **v4 实现 vs 设计文档全面审查（sonnet review，🔄进行中）** |
| **`micro/results/v4_recompile_comprehensive.json`** | **v4 VM 测试结果（2 rule：COND_SELECT + WIDE_MEM）** |
| **`micro/results/v4_new_directives_test.json`** | **v4 VM 测试结果（4 rule：+ ROTATE + ADDR_CALC）** |
| **`docs/tmp/v4-round1-test-results.md`** | **Round 1 修复后重测：LEA 无回归，ROTATE/WIDE_MEM 0 覆盖根因分析** |
| **`docs/tmp/v4-round2-implementation.md`** | **Round 2 实现：ROTATE 6-insn scanner + WIDE_MEM high-first scanner + rotate64_hash benchmark** |
| **`docs/tmp/v4-round2-test-results.md`** | **Round 2 VM 测试：WIDE_MEM 突破（11 sites，-13%），ROTATE 仍 0 覆盖** |
| **`docs/tmp/v4-round3-test-results.md`** | **Round 3 VM 测试：ROTATE 突破（126 sites），ALL 4 families active，combined -36.6%** |
| **`docs/tmp/rotate-scanner-debug.md`** | **ROTATE scanner 调试：clang 实际输出分析（commuted/two-copy/interleaved patterns）** |
| **`docs/tmp/rotate-recompile-debug.md`** | **ROTATE recompile 调试：kernel -EINVAL 根因分析** |
| **`docs/tmp/jit-pass-framework-v5-design.md`** | **v5 声明式 Pattern + Canonical Lowering 框架设计（~950 行）** |
| **`docs/tmp/jit-pass-framework-v5-review.md`** | **v5 设计 review（7.5/10）：5 must-fix 项** |
| **`docs/tmp/kernel-fixed-baselines-test-results.md`** | **Kernel-fixed baselines 测试结果：fixed-all vs stock 6 程序对比。Go/no-go PASSED（log2_fold +28.3%）** |
| **`docs/tmp/kernel-fixed-baselines-per-directive.md`** | **Per-directive 隔离测试：ROTATE/WIDE/LEA/CMOV 各自独立结果。Code size 可加，exec time 不可加。CMOV-only 隔离验证** |
| **`docs/tmp/cmov-subprog-fix-results.md`** | **cmov_select subprog scan 修复：0→1 site，kernel subprog-local 验证。emitter correctness bug 待修** |
| **`docs/paper/paper.tex`** | **ACM sigconf 论文初稿：characterization + system design（🔄进行中）** |
| **`docs/tmp/policy-decision-layer-design.md`** | **Policy decision layer 设计（TODO #45）：3 级策略（static/profile/AB），per-site branch-miss 归因，log2_fold vs cmov_select 对比，论文 narrative** |

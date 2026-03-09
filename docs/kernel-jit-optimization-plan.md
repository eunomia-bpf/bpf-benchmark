# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化论文的单一 hub，记录设计方向、论文策略、实验进度与 TODO。
> Characterization 论文见 `docs/paper-comparison.md`（独立论文，最终将与本文合并）。
>
> 最新设计文档：**`docs/tmp/bpf-jit-advisor-v7.md`**（Hybrid 架构，3245 行）
>
> 上次更新：2026-03-08

---

## 1. 论文定位与策略

### 1.1 核心论题

> eBPF JIT 的 backend 优化应该分为稳定的 **kernel legality plane** 和可更新的 **userspace backend policy plane**。Kernel 验证并安全采纳有界的 backend directives；特权 userspace 根据 CPU profile、workload profile、程序特征和 fleet policy 决定请求哪些 directives。

贡献不是任何一个 peephole 优化，而是 **mechanism/policy 分离、fail-closed legality 基础设施、以及 profitable backend 决策随程序/workload/硬件变化的证据**。

### 1.2 两篇论文策略

| 论文 | 状态 | 说明 |
|------|:---:|------|
| **Paper 1: Characterization** | 数据就绪 | `paper-comparison.md`，量化 kernel JIT vs LLVM -O3 差距 |
| **Paper 2: Optimization** | 设计就绪，待实现 | 本文档，userspace-guided backend optimization |
| **最终合并** | 计划中 | 两篇最终合并为一个完整故事，但**现在先拆开**，确保每个方面独立达到顶会水准 |

**合并后的故事线**：
1. Characterization 揭示差距来自 backend lowering（不是 bytecode）
2. Bytecode 优化器（K2/Merlin/EPSO）无法触及这些 backend 决策
3. 部分 backend 决策的 legality 稳定但 profitability 依赖部署环境
4. 设计 mechanism/policy 分离的框架
5. 实现 + 评估

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

| 阶段 | 内容 | Kernel 改动 | Userspace |
|------|------|-----------|-----------|
| **Phase 1** | 允许特权进程对已验证 BPF 程序附加 directives | 最小：新增 directive 接口 + 验证逻辑 | 手动工具 / 脚本 |
| **Phase 2** | 基于 llvmbpf 分析自动生成 directives | 不变 | llvmbpf 分析 + directive 生成 |
| **Phase 3** | 跨架构（x86 + arm64） | 每个 arch 实现 directive consumer | 同一分析，不同 directives |

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
                   │ BPF_PROG_LOAD(jit_directives_fd)
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

### 8.1 VM vs Host 关键发现

7.0-rc2 kernel JIT 比 6.15 快约 12%（geomean 0.881x），部分归因于 callee-saved 优化。
完整数据见 `micro/results/vm_vs_host_comparison.md`。

### 8.2 微架构实验摘要

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
| 27 | **Kernel POC 分支** | ✅ 完成 | 216 行新增，wide_load directive，verifier rewrite，fail-closed。见 `docs/tmp/poc-implementation-summary.md` |
| 27-v | **POC 端到端验证** | ✅ 完成 | load_byte_recompose: 288→130.5ns (**0.453x, 2.21x 加速**)，JIT 422→296B。userspace hint→directive blob→verifier rewrite 闭环。见 `docs/tmp/poc-validation-report.md` |
| 12-f | **v7 must-fix** | ✅ 完成 | cmov blinding→fail-closed, branch_reorder metadata 补全, bounds_window 缩窄, struct 56B |
| 14-r | **Interface review** | ✅ 完成 | 6/10，主要问题：假设简化的 kernel pipeline、scope 与 v6 不一致、缺 multi-subprog。见 `docs/tmp/interface-design-review.md` |
| 15-r | **Cross-doc review** | ✅ 完成 | 每个 directive 的 blob/JIT/证据交叉验证 + Hybrid 分层建议。见 `docs/tmp/cross-document-review.md` |
| 16-r | **OSDI readiness review** | ✅ 完成 | 4/10，见 `docs/tmp/osdi-readiness-review.md` |

### 🟡 P1 — 原型实现（Critical Path from cross-doc review）

| # | 任务 | 说明 | 层 |
|---|------|------|:---:|
| 14 | **orig_idx 传播修复** | 字段已存在，需修复 `adjust_insn_aux_data()` 传播。**所有 remap 的前置条件** | kernel |
| 15 | **Transport + blob parser + fail-closed** | interface-design-detail.md 设计可复用（transport skeleton 在 Hybrid 下存活） | kernel |
| 16 | **Remap / validation 准备阶段** | post-rewrite remap + stage-aware matcher | kernel |
| 17 | **wide_load (= byte_load_recompose)** | 第一个 directive。**JIT-level v1 或 verifier-level 均可** | JIT 或 verifier |
| 18 | **narrow cmov_select** | 冻结 pure-assignment contract（不含 v6 expression-arm） | hybrid |
| 19 | **广度 directive × 1-2** | `wide_store` 最安全；`lea_fusion` / `rotate_fusion` 也可 | JIT |
| 20 | **第一个 verifier-rewrite directive** | `branch_reorder`（一钻石 BPF block permutation）或 `bounds_window` | verifier |
| 21 | **kernel-fixed baselines** | fixed-cmov + fixed-layout 作为对比。**OSDI 必须** | eval |
| 22 | **消融补全** | byte-recompose / callee-saved / BMI | eval |

**Cross-doc review 关键发现**：
- constant blinding 在 Path B 下冲突大幅减小（verifier 先 rewrite BPF，blinding 跑在已 rewrite 的程序上）
- interface 需要增加 **stage 维度**（`VERIFIER_REWRITE` vs `JIT_LOWERING`）和 stage-aware telemetry
- v6 的 cmov_select 表达式 arm 不等于 v5r2 的 pure-assignment arm——必须冻结 narrow contract
- `struct_field_cluster` 和 `smallmul_strength_reduce` smoke 数据中 kernel 更快——只是 pattern 证据，不是 backend gap 证据

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
| **v7** | **Hybrid：verifier structural rewrite + JIT target-specific lowering** | **设计定型，待写文档** | **待写，综合 verifier-rewrite + interface-design + reviews** |

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
| **opt1-vm** | **7.0-rc2 + byte-recompose** | ❌ | 待实现 |
| opt2-vm | 7.0-rc2 + cmov | ❌ | 待实现 |
| opt3-vm | 7.0-rc2 + branch_reorder | ❌ | 待实现 |
| opt1+2+3-vm | 7.0-rc2 + all directives | ❌ | 待实现 |

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
| **`docs/tmp/bpf-jit-advisor-v7.md`** | **当前最新设计（v7 Hybrid，verifier rewrite + JIT lowering）** |
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

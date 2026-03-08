# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化工作的单一 hub，记录设计方向、实验进度与 TODO。
> Characterization 论文见 `docs/paper-comparison.md`（独立论文）。本文档支撑第二篇论文的系统贡献。
>
> 上次更新：2026-03-08

---

## 1. 论文定位

**第二篇论文核心问题**：characterization 已量化了 kernel JIT 与 LLVM -O3 的差距，下一步是**如何安全、可扩展地缩小这个差距**。

**论文故事线**：
1. Characterization 揭示差距主要来自 backend lowering，不是 bytecode 层面
2. Bytecode 优化器（K2/Merlin/EPSO）无法触及 byte-recompose、cmov、branch layout 等 backend 决策
3. 我们提出**微架构感知的 userspace-guided JIT 优化框架**：允许特权用户态进程基于目标微架构特征来指导 kernel JIT 的 backend 决策
4. 实现框架 + 典型优化并展示 before/after 数据

### 1.1 设计方向决策记录（2026-03-08）

| 决策 | 结论 | 原因 |
|------|------|------|
| **不做简单 peephole patches** | ❌ 不考虑 | 目标是论文（系统贡献），不是发 kernel patch |
| **不做 kernel-only first** | ❌ 不采纳 R4 建议 | 一开始就要考虑 userspace，不能只在 kernel 内部做 |
| **不用 lift→compare→emit** | ❌ 放弃 v4 的 re-lift 设计 | 太重，且不是正确的抽象层次 |
| **userspace 调整必须微架构相关** | ✅ 核心设计约束 | 优化决策本质上依赖目标硬件特征（cmov 可用性、cache 行为、分支预测等） |
| **先手动、后自动** | ✅ 分阶段 | 先允许特权进程手动调整 bytecode/JIT hints，后考虑 llvmbpf 自动闭环 |
| **kernel 改动最小化** | ✅ | 只开放接口让 userspace 影响 JIT，不在 kernel 里做复杂分析 |

**与 existing work 的关键差异**：

| 系统 | 优化层 | 能解决 byte-recompose? | 能解决 cmov? |
|------|--------|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode | ❌ | ❌ |
| **Ours** | **Backend lowering** | **✅** | **✅** |

---

## 2. Characterization 证据摘要

来自 `paper-comparison.md` 的关键数据，作为本文档的输入：

| 证据 | 数值 | 来源 |
|------|------|------|
| Exec time geomean (L/K) | 0.849x (31 pure-JIT) | authoritative 30×1000 |
| Code size geomean (L/K) | 0.496x (31/31 llvmbpf 更小) | authoritative |
| Byte-recompose 指令占比 | **50.7%** of kernel surplus | JIT dump 分析 |
| Byte-recompose 时间惩罚 | **2.24x** (load_byte_recompose 0.447x) | 因果隔离实验 |
| cmov 差距 | 31 vs 0 | JIT dump |
| Prologue/epilogue 占比 | 18.5% of surplus | JIT dump |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 | pass ablation |

---

## 3. 优化目标（按优先级）

### Tier 1：论文已识别的 3 个优化

| # | 优化 | 影响 | v7.0-rc2 状态 | 行动 |
|---|------|------|:---:|------|
| 1 | **Byte-load recomposition** | 50.7% surplus, 2.24x penalty | ❌ 未实现 | **最高优先级，需实现** |
| 2 | **cmov support** | 19.9% branch surplus, 31 vs 0 cmov | ❌ 未实现 | 中优先级 |
| 3 | **Callee-saved register opt** | 18.5% surplus | ✅ 已实现 | ~~验证了我们的分析~~ |

### Tier 2：新发现的优化机会

详见 `docs/tmp/additional_jit_optimizations.md`。

| 优化 | 当前 kernel | LLVM 做法 | 复杂度 |
|------|------------|----------|--------|
| Byte-store composition | 每个 store 独立发射 | 合并多个 byte stores 为 1 个 mov | 80-140 LOC |
| Rotate/bit-twiddle | 无 rotate 识别 | `rorx`/`rol`/`blsr` | 120-220 LOC |
| `lea` arithmetic fusion | 严格 two-address ALU | `lea` 做 add/scale/offset | 100-180 LOC |
| Branch layout | 严格 BPF block 顺序 | fall-through 重排 | 200-350 LOC |
| Zero-displacement elision | off=0 也发射 disp8 | 更短编码 | 20-40 LOC |

### Tier 3：不推荐

- 完整常量传播/DCE — 等于重写为编译器后端
- 指令调度 — 现代 OoO CPU 已处理
- 完整寄存器分配 — 固定 BPF→x86 映射是设计选择
- 循环优化 — LLVM ablation 显示对 BPF 无效果

---

## 4. 系统设计方向：微架构感知的 Userspace-Guided JIT 优化

> ⚠️ 以下为新设计方向（v5），取代 v4 的 target-independent region IR 方案。
> v4 设计及 review 历史保留在 `docs/bpf-jit-advisor-design.md` 和 `docs/tmp/bpf-jit-advisor-review-r{1,2,3,4}.md`。

### 4.1 核心思路

**不做 kernel-only peephole（那只是 patch），也不做 target-independent IR lift（太重且抽象层次错误）。**

正确的设计是：

1. **Kernel 开放最小接口**，允许特权用户态进程对已验证的 BPF 程序附加**微架构相关的 JIT 指令**（directives）
2. 这些 directives 本质上是**与目标硬件绑定的后端优化决策**，例如：
   - "这组连续 byte load + shift + or 可以合并为 wide load"（依赖：对齐、little-endian）
   - "这个 branch diamond 可以用 cmov"（依赖：目标 CPU 的 cmov 性能特征）
   - "这段基本块应该按此顺序排列"（依赖：分支预测器行为）
3. **Userspace 做分析决策**（可以是手动工具、llvmbpf 自动化、或其他 profiler）
4. **Kernel JIT 只做验证 + 采纳/拒绝**，fail-safe（拒绝时 fallback 到正常 emission）

### 4.2 为什么必须是微架构相关的

v4 试图用 target-independent IR 做抽象，但这是错误的层次：

| 维度 | Target-independent IR (v4) | 微架构相关 directives (v5) |
|------|---------------------------|--------------------------|
| 抽象层次 | 语义等价变换 | 后端决策指令 |
| kernel 复杂度 | 需要 lifter + canonicalizer + comparator | 只需验证前置条件 + 采纳/拒绝 |
| 安全模型 | 语义等价证明（难） | 前置条件检查（简单） |
| 可扩展性 | 每种优化需新 IR op | 每种优化需新 directive type |
| 微架构适配 | 不能 — target-independent | 天然支持 — 由 userspace 决定 |

关键洞察：**优化决策本身就是微架构相关的**。cmov 在某些微架构上比 branch 快，在其他上不一定。Wide load 的收益取决于 cache line 行为。Branch layout 依赖分支预测器设计。把这些决策抽象为 target-independent IR 是在丢掉最关键的信息。

### 4.3 分阶段计划

| 阶段 | 内容 | Kernel 改动 | Userspace |
|------|------|-----------|-----------|
| **Phase 1** | 允许特权进程对已验证 BPF 程序附加 directives | 最小：新增 directive 接口 + 验证逻辑 | 手动工具 / 脚本 |
| **Phase 2** | 基于 llvmbpf 分析自动生成 directives | 不变 | llvmbpf 分析 + directive 生成 |
| **Phase 3** | 跨架构（x86 + arm64） | 每个 arch 实现 directive consumer | 同一分析，不同 directives |

### 4.4 与 v4 的关键区别

- **v4**：userspace 提供 target-independent replacement IR → kernel re-lift + compare + lower
- **v5**：userspace 提供 microarch-specific directives → kernel 验证前置条件 + 采纳/拒绝
- **v5 更简单**：不需要 kernel 里的 IR lifter/canonicalizer
- **v5 更精确**：优化决策直接绑定到硬件特征
- **v5 从一开始就有 userspace**：不是 kernel-only first

### 4.5 当前状态

**需要重新设计**。v5 方向已确定，但具体的 directive 格式、kernel 接口、安全模型需要从头设计。

---

## 5. 消融实验证据

> 这些实验为设计提供定量输入，不直接产出系统贡献。

### 5.1 已完成

| 消融实验 | 方法 | 结果 |
|----------|------|------|
| 禁用 cmov | LLVM subtarget `-cmov` | switch_dispatch +26%，binary_search +12%；部分 benchmark 反而变快 |

### 5.2 待做

| 消融实验 | 方法 | 状态 |
|----------|------|:---:|
| 模拟 byte-recompose | 在 llvmbpf 中 wide load → byte-load 序列 | ❌ |
| 强制 fixed callee-saved | 总是保存 rbp+rbx+r13 | ❌ |
| 禁用 rotate/blsr | 禁用 BMI/BMI2 features | ❌ |

### 5.3 cmov 消融详细数据

| Benchmark | Normal | No-cmov | Delta |
|-----------|-------:|--------:|------:|
| switch_dispatch | 213 ns | 269 ns | **+26.3%** |
| binary_search | 205 ns | 229 ns | **+11.7%** |
| bounds_ladder | 83 ns | 68 ns | -18.1% |
| large_mixed_500 | 415 ns | 316 ns | -23.9% |

结论：cmov 的收益**依赖于微架构和 workload**——这正是为什么优化决策必须是微架构相关的。

---

## 6. 已完成实验

| 实验 | 日期 | 结果 |
|------|------|------|
| VM 环境搭建 | 03-07 | QEMU/KVM + virtme-ng，kernel 7.0-rc2 可启动 |
| VM baseline（kernel only） | 03-07 | 31 benchmark，7.0-rc2 vs host 6.15: geomean **0.881x**（7.0-rc2 更快） |
| Kernel 7.0-rc2 JIT 源码分析 | 03-08 | callee-saved opt ✅ 已实现 (`detect_reg_usage`)；byte-recompose ❌；cmov ❌（仅 1 处 BPF_ZEXT edge case） |
| no-cmov 消融（路径 B） | 03-08 | switch_dispatch +26%，binary_search +12%；混合结果 |
| 10 个新 benchmark | 03-08 | authoritative 数据，geomean 0.835x（8/10 llvmbpf wins） |
| 微架构实验 | 03-08 | 频率扫描（3 benchmarks material）、输入分布、PMU 双 runtime |

### 6.1 VM vs Host 关键发现

7.0-rc2 kernel JIT 比 6.15 快约 12%（geomean 0.881x），部分归因于 callee-saved 优化。

| Benchmark | Host 6.15 | VM 7.0-rc2 | 7.0-rc2 / 6.15 |
|-----------|----------:|----------:|:---:|
| simple | 14 ns | 7 ns | 0.50x |
| binary_search | 442 ns | 380 ns | 0.86x |
| large_mixed_500 | 512 ns | 409 ns | 0.80x |

Note: `simple` 低于 ktime 分辨率，数据仅作参考。完整数据见 `micro/results/vm_vs_host_comparison.md`。

### 6.2 微架构实验摘要

完整数据：`tmp/microarch_experiments.md`

**CPU 频率敏感性**：`binary_search`（31.7%）、`load_byte_recompose`（33.2%）、`switch_dispatch`（17.3%）的 L/K ratio 随频率有 material 变化。llvmbpf 在高频率下相对优势增大。

**输入分布**：`branch_layout` 对输入分布敏感（predictable 0.225x vs random 0.326x）。

**PMU**：llvmbpf IPC 普遍高于 kernel（binary_search 6.86 vs 2.41），与更紧凑的指令流一致。

---

## 7. TODO（按优先级排序）

### 🔴 P0 — 当前 sprint：v5 设计

| # | 任务 | 负责 | 说明 |
|---|------|------|------|
| 1 | **v5 架构设计文档** | codex 设计 + codex review | 微架构感知 directive 框架：接口、安全模型、directive 格式 |
| 2 | **Directive 类型清单** | codex | 基于 characterization 数据定义初始 directive set |
| 3 | **消融补全** | codex | byte-recompose / callee-saved / BMI 消融数据 |

### 🟡 P1 — 原型实现

| # | 任务 | 说明 |
|---|------|------|
| 4 | Kernel directive 接口 prototype | 最小 kernel 改动，允许 userspace 附加 directives |
| 5 | 手动 directive 工具 | 命令行工具，人工为 BPF 程序生成 directives |
| 6 | VM 验证 | 31+ benchmark before/after，定量展示 directive 效果 |

### 🟢 P2 — 自动化 + 跨架构

| # | 任务 | 说明 |
|---|------|------|
| 7 | llvmbpf 自动 directive 生成 | 基于 LLVM 优化结果自动产出 directives |
| 8 | arm64 directive 消费 | 跨架构验证 |
| 9 | 端到端评估 | 真实程序 directive 效果 |

---

## 8. VM 实验矩阵

| 配置 | Kernel | 状态 | 结果 |
|------|--------|:---:|------|
| baseline-host | 6.15.11 | ✅ | authoritative 31-case 数据 |
| baseline-vm (kernel only) | 7.0-rc2 | ✅ | geomean 0.881x vs host |
| baseline-vm (L/K) | 7.0-rc2 llvmbpf + kernel | ✅ | L/K ~0.850x |
| **opt1-vm** | **7.0-rc2 + byte-recompose** | ❌ | 待实现 |
| opt2-vm | 7.0-rc2 + cmov | ❌ | 待实现 |
| opt1+2-vm | 7.0-rc2 + byte-recompose + cmov | ❌ | 待实现 |

---

## 9. 开发环境

```
VM:        QEMU/KVM + virtme-ng
Kernel:    vendor/linux (v7.0-rc2) as submodule
JIT file:  arch/x86/net/bpf_jit_comp.c
Benchmark: micro/run_micro.py + micro_exec via BPF_PROG_TEST_RUN
Baseline:  host 6.15.11 authoritative + VM 7.0-rc2 unmodified
```

---

## 10. 参考文档

| 文档 | 内容 |
|------|------|
| `docs/bpf-jit-advisor-design.md` | BPF-JIT Advisor v4 详细设计 |
| `docs/tmp/bpf-jit-advisor-review-r4.md` | 最新 review（IR freeze 是 blocker） |
| `docs/tmp/vm_vs_host_detailed_analysis.md` | VM 7.0-rc2 vs Host 6.15 详细对比 |
| `docs/tmp/additional_jit_optimizations.md` | Tier 2 JIT 优化机会分析 |
| `docs/tmp/benchmark_coverage_analysis.md` | Benchmark 覆盖度缺口分析 |
| `docs/tmp/bpf_roundtrip_feasibility.md` | BPF→IR→BPF round-trip 可行性研究 |
| `docs/tmp/microarch_experiments.md` | 微架构实验结果 |
| `micro/results/vm_vs_host_comparison.md` | VM vs Host 简要对比 |
| `micro/results/new_benchmarks_authoritative_summary.md` | 10 个新 benchmark 结果 |

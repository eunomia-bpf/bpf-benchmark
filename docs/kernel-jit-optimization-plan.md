# Kernel eBPF JIT Optimization Plan

> 基于 benchmark characterization 的数据驱动 kernel JIT 改进计划。
> 目标：实现至少 1-2 个优化并在 VM 中测量效果，将论文从 characterization 升级为 systems contribution。
>
> 上次更新：2026-03-08

## 1. 背景与动机

### 1.1 Review 反馈的核心问题

Codex review（4/10）指出最大的 reject 原因是"没有实现任何系统结果"。论文提出了 3 个 kernel JIT 改进建议，但都停留在分析层面。实现至少一个优化并展示 before/after 数据是从 characterization→systems paper 的关键路径。

### 1.2 两条实现路径

| 路径 | 方法 | 优势 | 劣势 |
|------|------|------|------|
| **路径 A：修改 kernel JIT** | 直接改 `arch/x86/net/bpf_jit_comp.c` | 最直接，upstream 可接受 | 需要内核开发经验，crash 风险 |
| **路径 B：通过 llvmbpf 验证** | 在 llvmbpf 中禁用特定优化，模拟 kernel 行为 | 安全、快速迭代 | 不是真正的 kernel patch |

**推荐策略**：两条路径并行。路径 B 先跑（快速验证假设），路径 A 跟进（产出真正的 kernel patch）。

### 1.3 开发环境

- **VM 隔离**：QEMU/KVM + virtme-ng，自定义 kernel 在 VM 里运行，crash 不影响 host
- **Kernel source**：`vendor/linux`（v7.0-rc2）作为 submodule
- **Benchmark**：同一套 `micro/run_micro.py` + `micro_exec`，在 VM 内通过 `BPF_PROG_TEST_RUN` 执行
- **对比基线**：host kernel 6.15.11 authoritative 数据 + VM unmodified 7.0-rc2 数据

### 1.4 已完成的实验

| 实验 | 状态 | 结果 |
|------|------|------|
| VM 环境搭建 | ✅ | QEMU/KVM + virtme-ng，kernel 7.0-rc2 可启动 |
| VM baseline（kernel only） | ✅ | 31 benchmark，geomean 0.881x vs host 6.15（7.0-rc2 更快） |
| no-cmov 消融 | ✅ | switch_dispatch +26%，binary_search +12%；bounds_ladder/large_mixed 反而变快 |
| Kernel 7.0-rc2 JIT 分析 | ✅ | callee-saved opt 已实现，byte-recompose/cmov 未实现 |
| VM llvmbpf 对比 | 🔄 进行中 | 需要在 VM 里跑 llvmbpf 得到真实 L/K ratio |

## 2. 优化目标全景（按优先级排序）

### Tier 1：论文已识别的 3 个优化

| 优化 | 影响 | 上游状态 (v7.0-rc2) | 行动 |
|------|------|---------------------|------|
| **Byte-load recomposition** | 50.7% 指令开销，2.24x 隔离惩罚 | ❌ 未实现 | **最高优先级** |
| **cmov support** | 31 vs 0 cmov，19.9% branch surplus | ❌ 未实现（仅 1 处 edge case） | 中优先级 |
| **Callee-saved register opt** | 18.5% 指令开销 | ✅ 已实现 | 无需行动，验证了我们的分析 |

### Tier 2：新发现的优化机会

基于 codex 对 `bpf_jit_comp.c` 的系统性分析（详见 `docs/tmp/additional_jit_optimizations.md`）：

| 优化 | 当前 kernel 行为 | LLVM 对比 | 影响范围 | 复杂度 |
|------|-----------------|-----------|----------|--------|
| **Byte-store composition** | 每个 BPF store 独立发射 | LLVM 合并 8 byte stores 为 1 个 mov | ~31/31 benchmarks（固定开销） | 80-140 LOC |
| **Rotate/bit-twiddle peepholes** | 无 rotate 识别器 | LLVM 发射 `rorx`/`rol`/`ror`/`blsr` | ~10/31 benchmarks | 120-220 LOC |
| **`lea` arithmetic fusion** | 严格 two-address ALU | LLVM 用 `lea` 做 add/scale/offset | ~6-10/31 benchmarks | 100-180 LOC |
| **Branch layout optimization** | 严格 BPF block 顺序 | LLVM 重排 fall-through | ~4-5/31 benchmarks | 200-350 LOC |
| **Zero-displacement elision** | 即使 off=0 也发射 disp8 | LLVM 用更短编码 | 广泛但极小 | 20-40 LOC |

### Tier 3：不推荐在此 JIT 中实现

以下在理论上有差距但 ROI 不足：
- 完整常量传播/DCE — kernel JIT 是线性发射器，加这些等于重写为编译器后端
- 指令调度 — 现代 OoO CPU 已处理大部分调度
- 完整寄存器分配 — 固定 BPF→x86 映射是 kernel JIT 的设计选择
- 循环优化 — LLVM ablation 显示这些 pass 对 BPF 无效果

## 3. Byte-Load Recomposition（详细设计）

**为什么是最高优先级**：
- 最大的单一优化机会：50.7% 的额外指令，2.24x 隔离惩罚
- 需要安全论证：kernel 做 byte-by-byte load 是 verifier 安全要求还是 JIT lowering 选择？

**安全论证关键点**：
- BPF verifier 已在 load 之前验证了内存区域的安全性和类型
- byte-load-recompose 是 JIT lowering 的选择，不是 verifier 的要求
- 如果 verifier 允许 `BPF_LDX_MEM_W`/`BPF_LDX_MEM_DW`，JIT 直接生成 `mov` 就是合法的
- 需要确认：是否有特定 endianness 或 alignment 约束导致 byte-load

**路径 B 验证（llvmbpf）**：
- 在 llvmbpf 中添加一个 pass，将 wide load 降级为 byte-load-recompose 序列
- 测量降级后的性能损失，验证 2.24x 的因果关系

**路径 A 实现方案**：
1. 在 `do_jit()` 的 `BPF_LDX` case 中识别连续 byte load + shift + or pattern
2. 当所有条件满足时（aligned、type-safe、little-endian scalar），合并为单个 wide load
3. 需要修改的函数：`do_jit()` 中处理 `BPF_LDX_MEM_B` 的 case

## 4. cmov Support（详细设计）

**no-cmov 消融结果**（路径 B，已完成）：

| Benchmark | Normal exec | No-cmov exec | Delta | Notes |
|-----------|------------|-------------|-------|-------|
| switch_dispatch | 213 ns | 269 ns | **+26.3%** | 主要受益者，28 cmov |
| binary_search | 205 ns | 229 ns | **+11.7%** | 有 cmov 用于 min/max |
| bounds_ladder | 83 ns | 68 ns | -18.1% | cmov 反而更慢 |
| large_mixed_500 | 415 ns | 316 ns | -23.9% | cmov 反而更慢 |
| branch_layout | 161 ns | 156 ns | -3.1% | 基本无影响 |
| simple | 17 ns | 17 ns | 0% | 无 cmov |

**结论**：cmov 对 switch/search 类 benchmark 有显著收益（+12-26%），但在某些 pattern 下 branch 优于 cmov。影响不均匀，优先级低于 byte-recompose。

## 5. 路径 B 消融实验矩阵

| 消融实验 | 实现方式 | 状态 | 结果 |
|----------|---------|------|------|
| 禁用 cmov | `--no-cmov` via LLVM subtarget `-cmov` | ✅ 完成 | switch_dispatch +26%，混合结果 |
| 强制 fixed callee-saved | 总是保存 rbp+rbx+r13 | ❌ 未做 | — |
| 模拟 byte-recompose | 将 wide load 替换为 byte-load 序列 | ❌ 未做 | — |
| 禁用 rotate/blsr | 禁用 BMI/BMI2 subtarget features | ❌ 未做 | — |

## 6. Benchmark 覆盖度改进

基于 codex 分析（详见 `docs/tmp/benchmark_coverage_analysis.md`），当前 suite 的主要缺陷：

### 6.1 覆盖缺口

- 变长包解析几乎缺失（只有简化的 `packet_parse`）
- 无字符串/字节比较 workload
- 调用图覆盖太薄（仅 `bpf_call_chain` 一个）
- 无原子操作、ringbuf/perf output、BTF/CO-RE、kfunc 覆盖
- 过度集中在 staged batch 输入模式

### 6.2 不真实的 Pattern

- `binary_search` 实际上不是二分搜索
- `code_clone_*` 和 `large_mixed_*` 是显式 stress 测试，不是真实 workload
- 输入分布过于"干净"

### 6.3 推荐优先添加的 5 个 Benchmark

| 名称 | 覆盖的缺口 | 模式 | 复杂度 |
|------|-----------|------|--------|
| `packet_parse_vlans_tcpopts` | 变长包解析 | Pure-JIT, packet | Medium |
| `memcmp_prefix_64` | 字符串/字节比较 | Pure-JIT | Low |
| `local_call_fanout` | 多函数调用图 | Pure-JIT | Medium |
| `packet_rss_hash` | 包数据算术 | Pure-JIT, packet | Medium |
| `atomic_counter_xadd` | 原子操作 | Runtime | Medium |

### 6.4 推荐的 JIT 压力测试

| 名称 | 测试目标 | 复杂度 |
|------|---------|--------|
| `imm64_storm` | 常量物化压力 | Low |
| `alu32_64_pingpong` | 混合 32/64 位 zero-extension | Low-Medium |
| `branch_fanout_32` | 大量分支目标 | Medium |
| `deep_guard_tree_8` | 深层嵌套条件 | Medium |
| `mega_basic_block_2048` | 超大基本块 | Low-Medium |

## 7. VM 实验矩阵

| 配置 | Kernel | 状态 |
|------|--------|------|
| baseline-host | 6.15.11 (host) | ✅ authoritative 数据 |
| baseline-vm | 7.0-rc2 unmodified (kernel only) | ✅ 完成，geomean 0.881x |
| baseline-vm-llvmbpf | 7.0-rc2 (llvmbpf runtime) | 🔄 进行中 |
| opt2-vm | 7.0-rc2 + byte-recompose opt | ❌ 待实现 |
| opt3-vm | 7.0-rc2 + cmov opt | ❌ 待实现 |

## 8. 论文方向：Characterization + 基于 llvmbpf 的跨架构优化框架

### 8.1 核心论点

论文的 contribution 不仅是 characterization，而是：

> **用 userspace llvmbpf 作为优化 oracle，安全地改进 kernel JIT 的 backend 决策，且跨架构通用。**

这与 K2/Merlin/EPSO 的本质区别：它们在 bytecode 层优化（verifier 约束内），我们解决的是 **backend lowering 层** 的差距（byte-recompose 50.7%、cmov 19.9%），这是 bytecode 优化器无法触及的。

### 8.2 两条实现路径（按优先级）

#### 路径 A（主推）：Userspace Hint Advisor

llvmbpf 分析 BPF 程序，生成 **JIT hints**，kernel JIT 选择性采纳：

| Hint 类型 | 解决的问题 | x86 映射 | arm64 映射 | 影响 |
|-----------|-----------|----------|-----------|------|
| **wide-load-ok** | byte-recompose（50.7%） | `mov` 替代 8×`movzbq`+shift+or | `ldr` 替代 byte 序列 | 最大单一优化 |
| **select-region** | 缺少 cmov（19.9%） | `cmp`+`cmov` | `cmp`+`csel` | switch/search 类 |
| **block-order** | 分支布局 | fall-through 优化 | fall-through 优化 | 中等 |

**安全模型**：
- Verified bytecode **不变**，kernel 只是选择性采纳 hint
- Hint 错误时 kernel 忽略（fail-safe），不影响正确性
- Verifier 语义完全保留

**Hint 传输机制**（原型→长期）：
- 原型：BTF decl-tag payload（最小侵入）
- 中期：fd_array 中的 side-band object
- 长期：新的 hint blob UAPI

**跨架构**：hint 语义通用，每个 arch 的 JIT 自己解释。只需实现 x86 + arm64 即可论证。

#### 路径 B（Fallback）：BPF Bytecode Pre-optimizer

BPF ELF → lift to LLVM IR → LLVM -O3 → lower back to BPF bytecode → kernel verifier + JIT

- 不需要改 kernel
- 但只能优化 bytecode 层能表达的东西（InstCombine、SimplifyCFG 等）
- **无法解决** byte-recompose 和 cmov，因为这些是 backend lowering 问题
- 与 K2/Merlin/EPSO 有重叠，但我们用 LLVM full pipeline 而非手写规则/随机搜索
- 预期回收 characterization gap 的一小部分

### 8.3 与 existing work 的差异化

| 系统 | 优化层 | 约束 | 能解决 byte-recompose? | 能解决 cmov? |
|------|--------|------|----------------------|-------------|
| K2 (SIGCOMM'21) | BPF bytecode synthesis | verifier-constrained | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF bytecode | verifier-constrained | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode rewriting | verifier-constrained | ❌ | ❌ |
| KFuse (EuroSys'22) | In-kernel program fusion | kernel-internal | ❌ | ❌ |
| **Ours (Hint Advisor)** | **Backend lowering hints** | **hint-advised, fail-safe** | **✅** | **✅** |

核心区别：所有现有工作都被 BPF bytecode 语义限制，无法影响 JIT backend 如何将 bytecode 翻译为 native code。我们的 hint 直接作用于这一层。

### 8.4 预期 reviewer 问题

- **"为什么不直接把 LLVM 放进 kernel？"** — 正因为不需要。Userspace 做昂贵分析，kernel 只消费窄的 advisory 接口。
- **"如何保证安全？"** — Verified bytecode 不变，hint 是 advisory（kernel 可以忽略），每个 hint 在 kernel 侧有独立的前置条件检查。
- **"为什么跨架构？"** — Hint 语义是 arch-neutral 的（"这些 byte load 可以合并"），每个 arch JIT 用自己的指令实现。

## 9. 下一步行动计划

### Phase 1：强化 Characterization（当前）

| 任务 | 状态 | 产出 |
|------|------|------|
| 10 个新 benchmark 实现 | ✅ 完成，7/10 需修复 | 更强的 external validity |
| 新 benchmark 修复 | 🔄 codex 进行中 | — |
| VM 7.0-rc2 llvmbpf 对比 | ✅ 完成，L/K 0.811→0.850 | 7.0-rc2 缩小 ~5% 差距 |
| no-cmov 消融 | ✅ 完成 | switch_dispatch +26% |
| 更新 paper.md | ❌ 待做 | 整合 7.0-rc2 + 新 benchmark 数据 |

### Phase 2：路径 B 反向消融 + Round-trip 可行性

| 任务 | 说明 |
|------|------|
| byte-recompose 反向消融 | 在 llvmbpf 中模拟 byte-load 序列，量化因果关系 |
| BPF→LLVM IR→BPF round-trip 原型 | 验证是否可以 lift + optimize + lower back（codex 研究中） |
| rotate/blsr 消融 | 禁用 BMI/BMI2，测量影响 |

### Phase 3：Hint Advisor 原型

| 任务 | 说明 | 预计复杂度 |
|------|------|-----------|
| llvmbpf hint 导出 | 从优化后的 LLVM IR 提取 wide-load-ok / select-region hint | Medium |
| Hint 格式设计 | BTF decl-tag 或独立 blob | Low |
| x86 kernel JIT hint 消费 | `bpf_jit_comp.c` 读取 hint，条件性 wide load / cmov | Medium-High |
| arm64 kernel JIT hint 消费 | `arch/arm64/net/bpf_jit_comp.c` 对应实现 | Medium |
| VM 验证 | 31+ benchmark before/after | — |

### Phase 4：论文定稿

- 整合所有数据：authoritative + 7.0-rc2 + 新 benchmark + 消融 + hint advisor 结果
- 收紧 claims（per review feedback）
- 目标：characterization + systems contribution = OSDI/SOSP 级别

## 10. 参考文档

| 文档 | 内容 |
|------|------|
| `docs/tmp/vm_vs_host_detailed_analysis.md` | VM 7.0-rc2 vs Host 6.15 详细对比 |
| `docs/tmp/additional_jit_optimizations.md` | Tier 2 JIT 优化机会分析 |
| `docs/tmp/benchmark_coverage_analysis.md` | Benchmark 覆盖度缺口分析 |
| `docs/tmp/ebpf_profiling_tools_analysis.md` | eBPF profiling 工具 gap 分析（待完成） |
| `micro/results/vm_vs_host_comparison.md` | VM vs Host 简要对比 |

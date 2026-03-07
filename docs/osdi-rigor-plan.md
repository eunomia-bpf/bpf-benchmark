# Pure JIT Micro-Benchmark: OSDI 级别严谨性差距分析与行动计划

> 本文分析当前 22-case 纯 JIT 微基准的实验设计，识别与 OSDI/SOSP 要求的差距，并给出优先级排序的行动方案。

## 1. 当前状态评估

### 1.1 已有的好基础

| 维度 | 现状 | OSDI 要求 | 差距 |
|------|------|-----------|------|
| 样本量 | 30 iterations × 1000 repeats | 充分 | 无 |
| 统计检验 | Bootstrap CI + Cohen's d + Mann-Whitney U | 标准方法 | 无 |
| 效应量 | 16/22 显著 (p < 0.05)，|d| > 0.8 为大效应 | 已覆盖 | 无 |
| 确定性输入 | LCG 固定种子生成器 | 可复现 | 无 |
| 代码大小 | 22/22 有 native code bytes | 完备 | 无 |
| 开源脚本 | analyze_statistics.py 全自动 | 可复现 | 无 |

### 1.2 严重差距（必须修复）

#### G1. 测量方法不对等

**问题**：kernel 用 `ktime_get_ns`（内核时钟，~ns 分辨率但含调度噪声），llvmbpf 用 `rdtsc`（用户态 TSC，无调度噪声）。

**证据**：kernel CV 中位数 0.152 vs llvmbpf 0.031（5x 方差差异）。6 个不显著 benchmark 中 4 个因 kernel 方差过高。

**OSDI 审稿人会问**："你的两个 runtime 用不同的时钟源，如何保证测量公平性？"

**修复方案（优先级 P0）**：
1. **方案 A — kernel 侧也用 rdtsc**：修改 `kernel_runner.cpp`，在 `bpf_prog_test_run_opts` 前后插入 `rdtsc/rdtscp`，记为 `wall_exec_ns`，作为主要对比指标
2. **方案 B — 增大 repeat 取中位数**：`repeat=10000`，然后报 median 而非 mean，减小离群值影响
3. **方案 C — 隔离 CPU**：`isolcpus=` + `taskset` 绑核，减少调度噪声

**推荐**：A+C 组合。B 作为补充。

#### G2. 硬件计数器数据缺失

**问题**：22 个 benchmark 中只有 4 个（bitcount, binary_search, switch_dispatch, checksum）有非零 perf 计数器数据。llvmbpf 全部为 0。

**原因**：执行窗口太短（< 1μs），`perf_event_open` 的 PMU 调度周期（~1ms）内来不及采样。

**OSDI 审稿人会问**："你声称 llvmbpf 代码质量更好，但没有 IPC、分支预测、cache 命中率数据支撑？"

**修复方案（P0）**：
1. **方案 A — 累积计数器**：不要每个 iteration 重置计数器，而是在 N=1000 次 repeat 结束后读取一次，得到累积值 / N = 平均值。这需要修改 `micro_exec` 的计数器采集逻辑
2. **方案 B — 长程序聚焦**：对 exec_ns > 1000ns 的 benchmark（bitcount, checksum, fixed_loop_large, code_clone_8, fibonacci_iter, dep_chain_long）做 PMU 深度分析，这些已经有数据
3. **方案 C — 构建专门的 PMU 微基准**：循环 10K 次调用同一个 BPF 程序，在循环外采集 PMU

**推荐**：A 为最优方案（最小改动，最完整数据）。

#### G3. 编译时间未报告

**问题**：数据中有 `compile_ns` 但从未分析。OSDI 论文必须报告 JIT 编译开销。

**现有数据显示**：
- llvmbpf 编译时间 4-14 ms（LLVM -O3 代价）
- kernel 编译时间 0.3-72 ms（简单程序快、复杂程序如 bitcount 72ms）
- 比率范围：0.1x（bitcount: llvmbpf 更快）到 16x（simple: llvmbpf 更慢）

**修复方案（P1）**：在 analyze_statistics.py 中添加 compile_ns 分析，输出到统计报告。

### 1.3 中等差距（显著提升论文质量）

#### G4. 因果归因不足

**问题**：知道"代码更小但更慢"，但不能量化每种指令模式对执行时间的贡献。

**OSDI 审稿人会问**："byte-recompose 占了 50.7% 的额外指令，但占了多少额外时间？"

**修复方案（P1）**：
1. **微基准隔离法**：构建一对 benchmark，一个有大量 byte-recompose pattern，一个没有，差值即为该模式的时间贡献
2. **PMU 相关分析**：用 G2 修复后的 IPC 数据，结合指令数差异，估算时间分解：
   - `extra_time = extra_insns / IPC_observed`
   - 按指令类型分解：prologue, byte-recompose, branches, other

#### G5. 缺乏时间序列稳定性分析

**问题**：30 个 iteration 是否稳定？是否有 warm-up 效应、drift、周期性？

**OSDI 审稿人会问**："你怎么知道系统在测量期间是稳定的？"

**修复方案（P2）**：
1. 绘制 exec_ns vs iteration_index 的时间序列图（22 个 benchmark × 2 runtime）
2. 对前 10 和后 10 iterations 做 Wilcoxon 检验，验证无 drift
3. 计算自相关系数 ACF(1)，验证独立性

#### G6. 单一平台

**问题**：只在 Intel Arrow Lake-S 上测试。

**OSDI 审稿人会问**："结果是否特定于你的 CPU 微架构？ARM 上表现如何？"

**修复方案（P2）**：
- 如果有 ARM 机器，至少在 1 个非 x86 平台上重跑 suite
- 如果没有，在 Threats to Validity 中明确声明并解释为什么结论可推广（JIT codegen 差异是结构性的，不依赖特定微架构）

#### G7. 代表性论证不足

**问题**：22 个 benchmark 是手写的，审稿人会质疑代表性。

**OSDI 审稿人会问**："你的 22 个微基准覆盖了真实 BPF 程序的哪些特征空间？"

**修复方案（P1）**：
1. 用 BCF 静态特征数据（1588 个程序）画真实程序的指令/helper/分支分布
2. 把 22 个 benchmark 标注在分布上，证明覆盖了关键区域
3. 用 60 个可编译的真实程序做 code-size 对比，验证微基准结论的外部效度

### 1.4 小差距（锦上添花）

#### G8. LLVM Pass 消融粒度不够

当前只有 O0/O1/O2/O3，没有逐 pass 消融。

**修复方案（P3）**：用 `opt -passes=...` 逐步启用 pass，识别对 BPF 最关键的 2-3 个 pass。

#### G9. Spectre 2×2 实验

需要重启 `mitigations=off`，风险/收益比不高。

**修复方案（P3）**：如果时间允许，做一次 reboot 实验。

## 2. 优先级行动计划

### Phase 1 — 测量基础设施修复（P0，阻塞论文）

| ID | Action | 预计工作量 | 依赖 |
|----|--------|-----------|------|
| A1 | kernel_runner.cpp: 添加 rdtsc 围栏测量 | 2h | 无 |
| A2 | micro_exec: PMU 累积模式（整个 repeat 循环读一次） | 4h | 无 |
| A3 | isolcpus + taskset 绑核脚本 | 1h | 无 |
| A4 | 重跑 30-iter suite with A1+A2+A3 | 1h (自动) | A1-A3 |

### Phase 2 — 分析补全（P1，显著提升）

| ID | Action | 预计工作量 | 依赖 |
|----|--------|-----------|------|
| B1 | analyze_statistics.py: 添加 compile_ns 分析 | 1h | 无 |
| B2 | 时间序列稳定性图 + Wilcoxon drift 检验 | 2h | A4 数据 |
| B3 | PMU 相关矩阵（IPC vs ratio, branch_miss vs ratio） | 2h | A4 数据 |
| B4 | 代表性论证：BCF 特征空间 + benchmark 覆盖可视化 | 3h | 已有数据 |
| B5 | 因果时间分解：byte-recompose 等模式的时间贡献 | 4h | A4 数据 |
| B6 | 60 个真实程序 code-size 批量对比 | 2h | 已有数据 |

### Phase 3 — 锦上添花（P2-P3）

| ID | Action | 预计工作量 | 依赖 |
|----|--------|-----------|------|
| C1 | ARM 交叉验证 | 4h+ | 硬件 |
| C2 | LLVM pass-level 消融 | 4h | 无 |
| C3 | Spectre 2×2 | 2h | reboot |
| C4 | Kernel JIT 改进建议 + patch 原型 | 8h | B5 |

## 3. 核心论证链（修复后应能回答）

```
1. 测量可信吗？
   → 两侧统一 rdtsc，绑核隔离噪声，30 iterations 无 drift，CV < 0.1（已验证）

2. 差距有多大？
   → Exec geomean 0.82x [0.80, 0.85]，16/22 显著，Cohen's d 多为大效应

3. 为什么有差距？
   → 代码大小 0.47x（LLVM 指令消除 + 寄存器分配 + 分支优化）
   → 但 8/22 更小更慢（关键路径不缩短，byte-recompose 占 50% extra insns）
   → PMU 证据：IPC 差异、branch miss 率差异（可量化）

4. 对谁有用？
   → BCF 1588 个程序特征分布证明微基准覆盖了主要特征区域
   → 60 个真实程序 code-size 批量验证（外部效度）
   → 具体 patch 建议（cmov 支持、按需 callee-saved、byte-recompose 优化）

5. 编译代价多大？
   → llvmbpf 4-14ms vs kernel 0.3-72ms，简单程序 llvmbpf 慢 10-16x，
   → 但对 networking fast-path 来说编译是一次性的
```

## 4. 最高优先级的代码修改清单

### 4.1 kernel_runner.cpp — 添加 rdtsc 测量

在 `BPF_PROG_TEST_RUN` 前后添加 `__rdtsc()` / `__rdtscp()` 围栏，输出 `exec_cycles` 和 `tsc_freq_hz`，与 llvmbpf 侧对齐。

### 4.2 micro_exec PMU 累积模式

修改 perf counter 采集逻辑：
- 当前：每个 repeat 迭代前 reset → 读取 → 只取最后一次
- 改为：repeat 循环开始前 reset → 循环结束后读取 → 除以 repeat 数得平均值
- 添加 `--perf-mode cumulative|per-iter` 参数

### 4.3 绑核脚本

```bash
#!/bin/bash
# run_isolated.sh — 隔离 CPU 4 运行 benchmark
sudo taskset -c 4 python3 micro/run_micro.py "$@"
```

## 5. 风险与 Threats to Validity

论文中需明确声明的限制：

1. **测量域不等价**：即使统一用 rdtsc，kernel 侧包含 syscall 进出开销（~100ns），llvmbpf 是纯 function call。应声明这是 "end-to-end execution including dispatch" vs "pure function call"。

2. **PMU 范围不等价**：kernel perf counters 包含 kernel-mode 事件（context switch, page fault），llvmbpf 只看 user-mode。应用 `exclude_kernel=1` 限制 kernel 侧只看 user-mode，或声明局限。

3. **单一平台**：只在 x86-64 Intel Arrow Lake-S 上测试。BPF JIT 对 ARM64 有不同的后端代码，结论可能不同。

4. **微基准 vs 真实负载**：微基准不包含完整的 networking stack 交互（中断、NAPI、socket buffer 分配）。

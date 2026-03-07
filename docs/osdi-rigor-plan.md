# Pure JIT Micro-Benchmark: OSDI 级别严谨性差距分析与行动计划

> 本文分析当前 31-case 纯 JIT 微基准的实验设计，识别与 OSDI/SOSP 要求的差距，并给出优先级排序的行动方案。
> 更新说明（2026-03-07）：suite 覆盖现已扩展到 `31` 个 staged-codegen / pure-JIT case 与 `9` 个 runtime case，并新增多源真实程序 code-size 外部验证：`corpus/results/real_world_code_size.md` 当前已扫描 `4` 个 repo、纳入 `77` 个 artifacts、枚举 `949` 个真实 program；其中当前双 runtime 成功配对的是来自 `cilium` 与 `libbpf-bootstrap` 的 `105` 个 paired instances（按 unique program name 去重后为 `27` 个 unique programs），code-size geomean 为 `0.573x`。本文的问题分级和优先级仍然有效，但覆盖相关段落需要结合 `micro/results/representativeness_report.md` 与 `corpus/results/real_world_code_size.md` 一起阅读。

## 0. 相关论文是怎么做的

强评测论文几乎都不会只依赖手写 micro benchmark。它们通常把“机制归因”和“外部有效性”拆成不同证据层。

- `BCF / Prove It to the Kernel`：用大规模真实对象集做主评测，覆盖多编译器、多优化级别、多程序来源，并报告 load/acceptance 的成功率与失败分解。核心特点是“真实语料 + 明确 baseline + 大样本统计”。
- `Demystifying Performance of eBPF Network Applications`：同时做受控 micro 和真实网络应用评测，硬件环境控制得很严，明确关掉 SMT / turbo 等噪声源，再把 hook overhead 和端到端吞吐/延迟放在一起解释。
- `Understanding Performance of eBPF-based Applications`：把 CPU isolation、资源隔离、扩展性实验放到主设计里，不只看单程序单核，而是看程序数、map 数、核心数增长时会怎样退化。
- `Evaluation of Tail Call Costs`：同时使用 `BPF_PROG_TEST_RUN` 型受控 micro 和更接近生产流量的 benchmark，并做大量重复实验，明确讨论两种环境的稳定性和方差差异。

从这些论文提炼出来的共同点是：

1. `Micro` 用来隔离因果，不拿来单独证明“真实世界通常怎样”。
2. `Corpus` 用来证明外部有效性，至少要有几十到上百个真实程序或对象。
3. `End-to-end` workload 用来证明结论在真实系统交互里仍成立。
4. `Failure breakdown / inclusion criteria / platform control` 要写清楚，否则审稿人会默认结果挑样本了。

## 1. 当前状态评估

### 1.1 已有的好基础

| 维度 | 现状 | OSDI 要求 | 差距 |
|------|------|-----------|------|
| 样本量 | 30 iterations × 1000 repeats | 充分 | 无 |
| 统计检验 | Bootstrap CI + Cohen's d + paired Wilcoxon（BH 校正；Mann-Whitney U 仅补充） | 标准方法 | 无 |
| 效应量 | 25/31 显著（BH-corrected paired Wilcoxon p < 0.05），|d| > 0.8 为大效应 | 已覆盖 | 无 |
| 确定性输入 | LCG 固定种子生成器 | 可复现 | 无 |
| 代码大小 | 31/31 有 native code bytes | 完备 | 无 |
| 编译时间 | `analyze_statistics.py` 已输出 compile-time section | 应报告 | 无 |
| 稳定性分析 | drift / ACF / 时间序列图已完成 | 需要稳定性证据 | 无 |
| 计时元数据 | `timing_source` + `wall_exec_ns` + `--metric` 已接入 | 可追溯 | 无 |
| 顺序偏置控制 | benchmark shuffle + per-iteration runtime randomization | 需要顺序控制 | 无 |
| 开源脚本 | analyze_statistics.py 全自动 | 可复现 | 无 |

- `run_micro.py` 现已在每个 iteration 内随机打乱 `llvmbpf/kernel` 顺序，并把 `runtime_order_seed` / `iteration_runtime_orders` 写入结果 JSON。
- `baseline_adjustment` 现按 `io_mode` 匹配应用，mixed-`io_mode` case 不再误用 staged `simple` baseline。

#### 本 session 已完成项（2026-03-07）

- Interleaved counterbalanced sampling 已接入 authoritative pipeline。
- Paired Wilcoxon 已作为 primary test；当前 `25/31` 在 BH 校正后仍显著。
- `--strict-env` enforcement 已接入运行入口。
- sub-resolution flagging 已加入结果与文档同步流程。
- `31+9` authoritative results 已落盘并用于当前结论。
- environment metadata 已随 run 一起记录。
- BH FDR correction 已纳入主分析流程。

### 1.2 关键差距（含部分已修复项）

#### G1. 测量方法不对等（主比较口径已澄清）

**问题**：kernel `exec_ns` 用 `ktime_get_ns`，llvmbpf `exec_ns` 用 `rdtsc`；而 `wall_exec_ns` 不适合跨 runtime 比较，因为 kernel 侧包含 `BPF_PROG_TEST_RUN` syscall dispatch 开销。

**证据**：authoritative `31`-case run 已显式记录 `timing_source`，并把 kernel 外层 rdtsc 保留为 `wall_exec_ns` / `exec_cycles` 元数据；但主结论统一基于 `exec_ns`。

**Status**: RESOLVED FOR PRIMARY ANALYSIS. `wall_exec_ns` 不适合 cross-runtime comparison；当前主分析使用 `exec_ns` 作为纯 BPF 执行时间指标，虽然 timing source 不同（kernel=`ktime`, llvmbpf=`rdtsc`），但比较对象是一致的。kernel 侧新增的 rdtsc 结果保留为 wall-clock / dispatch cost 参考与可追溯元数据。

#### G2. 硬件计数器数据缺失（已部分修复）

**问题**：当前 `micro/results/pmu_analysis_rigorous.md` 报告了 18 个 benchmark 行；其中 llvmbpf 只有 3 个 benchmark（`switch_dispatch`、`multi_acc_4`、`multi_acc_8`）有非 `n/a` 的 IPC，相关性分析样本量仅 `n=3`，不足以支持强结论。

**原因**：执行窗口太短（< 1μs），`perf_event_open` 的 PMU 调度周期（~1ms）内来不及采样。

**Status**: PARTIALLY RESOLVED — demoted to supplementary. cumulative PMU 基础设施已具备，`run_micro.py` 与 `micro_exec` 已支持 `--perf-scope full_repeat_raw|full_repeat_avg`；但当前 `micro/results/pmu_analysis_rigorous.md` 只有 `18` 个 kernel-side benchmark，且仅 `3` 个 benchmark 具备 dual-runtime IPC。短执行窗口与 PMU 调度粒度不匹配是结构性限制，因此 PMU 更适合作为定性 supplementary evidence，而非主因果证据。

**Remaining**: 保留 PMU 数据与分析脚本作为 supplementary material；正文中的因果归因以 code-size ratio、指令模式分析和“代码更小但执行更慢”悖论分析为主。若后续补做 IPC / branch-miss / cache-miss 关联分析，也只应作为补充诊断，不进入主论证链。

#### G3. 编译时间未报告（已修复）

**Status**: RESOLVED. authoritative analysis 已报告 compile time geomean `L/K = 3.394x`。

### 1.3 中等差距（显著提升论文质量）

#### G4. 因果归因不足

**Status**: OPEN. 目前还没有 time-domain decomposition。

**问题**：知道"代码更小但更慢"，但不能量化每种指令模式对执行时间的贡献。

**OSDI 审稿人会问**："byte-recompose 占了 50.7% 的额外指令，但占了多少额外时间？"

**修复方案（P1）**：
1. **微基准隔离法**：构建一对 benchmark，一个有大量 byte-recompose pattern，一个没有，差值即为该模式的时间贡献
2. **补充 PMU 相关分析（supplementary only）**：若后续能拿到更多可用 IPC 数据，可结合指令数差异做定性时间分解，但不作为主因果证据：
   - `extra_time = extra_insns / IPC_observed`
   - 按指令类型分解：prologue, byte-recompose, branches, other

#### G5. 缺乏时间序列稳定性分析（已修复）

**Status**: RESOLVED. `analyze_stability.py` 已存在；当前结论为 `3/44` drift 显著，但幅度均 `< 2%`。

#### G6. 单一平台

**Status**: OPEN. 当前仍只覆盖 x86-64。

**问题**：只在 Intel Arrow Lake-S 上测试。

**OSDI 审稿人会问**："结果是否特定于你的 CPU 微架构？ARM 上表现如何？"

**修复方案（P2）**：
- 如果有 ARM 机器，至少在 1 个非 x86 平台上重跑 suite
- 如果没有，在 Threats to Validity 中明确声明并解释为什么结论可推广（JIT codegen 差异是结构性的，不依赖特定微架构）

#### G7. 代表性论证不足

**Status**: PARTIALLY RESOLVED. suite 已扩展到 `31+9` benchmarks，`micro/results/representativeness_report.md` 已存在；多源外部验证已扫描 `4` 个 repo（`libbpf-bootstrap` + `3` 个 BCF repo）、纳入 `77` 个 artifacts 并枚举 `949` 个真实 program，其中当前双 runtime 成功配对的是来自 `cilium` 与 `libbpf-bootstrap` 的 `105` 个 paired instances（`27` 个 unique programs），code-size geomean 为 `0.573x`；但 feature-box 覆盖仍只有 `0.8%`。

**问题**：31 个 benchmark 是手写的，审稿人会质疑代表性。

**OSDI 审稿人会问**："你的 31 个微基准覆盖了真实 BPF 程序的哪些特征空间？"

**修复方案（P1）**：
1. 用 BCF 静态特征数据（1588 个程序）画真实程序的指令/helper/分支分布
2. 把 31 个 benchmark 标注在分布上，证明覆盖了关键区域
3. 已完成跨 `4` 个 repo 的扫描；当前来自 `cilium` 与 `libbpf-bootstrap` 的 `105` 个 paired real-program code-size 实例已验证微基准结论的外部效度

**Remaining**: 仍需把 feature-space 覆盖从 `0.8%` 往上推；真实程序 execution-time 子集不再视为 engineering TODO，因为 `BPF_PROG_TEST_RUN` 对 real programs 存在结构性限制（tracepoint/kprobe/perf_event 不支持 test_run，TC 缺少 classifier/act context，fentry/fexit 在 dummy input 下 `exec_ns=0`）。论文中的验证策略应明确为：`105` 个 paired real programs 做 code-size 外部验证，execution-time 则由 `40` 个 handcrafted microbenchmarks（`31` staged-codegen + `9` runtime）承担。

### 1.4 小差距（锦上添花）

#### G8. LLVM Pass 消融粒度不够

当前只有 O0/O1/O2/O3，没有逐 pass 消融。

**修复方案（P3）**：用 `opt -passes=...` 逐步启用 pass，识别对 BPF 最关键的 2-3 个 pass。

#### G9. Spectre 2×2 实验

需要重启 `mitigations=off`，风险/收益比不高。

**修复方案（P3）**：如果时间允许，做一次 reboot 实验。

## 2. 优先级行动计划

### Phase 1 — 测量基础设施修复（P0，阻塞论文）

| ID | Action | 状态 | 预计工作量 | 依赖 |
|----|--------|------|-----------|------|
| A1 | kernel_runner.cpp: 添加 rdtsc 围栏测量 | 已完成 | 2h | 无 |
| A2 | micro_exec: PMU 累积模式（整个 repeat 循环读一次） | 已完成 | 4h | 无 |
| A3 | isolcpus + taskset 绑核脚本 | 已完成 | 1h | 无 |
| A4 | 重跑 30-iter suite with A1+A2+A3 | 已完成 | 1h (自动) | A1-A3 |

### Phase 2 — 分析补全（P1，显著提升）

| ID | Action | 状态 | 预计工作量 | 依赖 |
|----|--------|------|-----------|------|
| B1 | analyze_statistics.py: 添加 compile_ns 分析 | 已完成 | 1h | 无 |
| B2 | 时间序列稳定性图 + Wilcoxon drift 检验 | 已完成 | 2h | A4 数据 |
| B3 | PMU 相关矩阵（IPC vs ratio, branch_miss vs ratio） | 未完成 | 2h | A4 数据 |
| B4 | 代表性论证：BCF 特征空间 + benchmark 覆盖可视化 | 部分完成 | 3h | 已有数据 |
| B5 | 因果时间分解：byte-recompose 等模式的时间贡献 | 未完成 | 4h | A4 数据 |
| B6 | 60+ 个真实程序 code-size 批量对比 | 部分完成 | 2h | 多源 slice 已完成：扫描 `4` 个 repo / `77` artifacts / `949` discovered，当前 paired 为 `105` instances / `27` unique programs（来自 `cilium` + `libbpf-bootstrap`） |

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
   → `exec_ns` 是主比较指标（两侧都测纯 BPF 执行时间），`timing_source` 已显式记录；`wall_exec_ns` 仅作 syscall / dispatch 参考，30 iterations 无明显 drift

2. 差距有多大？
   → Exec geomean `0.849x [0.834, 0.865]`，`25/31` 在 BH-corrected paired Wilcoxon 下显著，Cohen's d 多为大效应

3. 为什么有差距？
   → 代码大小 `0.496x`（LLVM 指令消除 + 寄存器分配 + 分支优化）
   → 但 `10/31` 更小更慢（关键路径不缩短，byte-recompose 占 `50.7%` extra insns）
   → 补充 PMU 证据：当前仅 `3` 个 dual-runtime IPC benchmark，可作定性参考，不作为主因果证据

4. 对谁有用？
   → BCF 1588 个程序特征分布证明微基准覆盖了主要特征区域
   → 多源真实程序 code-size 验证已扫描 `4` 个 repo；当前在 `cilium` + `libbpf-bootstrap` 上得到 `105` 个 paired instances（`27` 个 unique programs），geomean `0.573x`
   → 下一步扩到跨 repo 的 60+ program execution/code-size 验证（外部效度）
   → 具体 patch 建议（cmov 支持、按需 callee-saved、byte-recompose 优化）

5. 编译代价多大？
   → llvmbpf 4-14ms vs kernel 0.3-72ms，简单程序 llvmbpf 慢 10-16x，
   → 但对 networking fast-path 来说编译是一次性的
```

## 4. 最高优先级的代码修改清单

### 4.1 kernel_runner.cpp — rdtsc 测量已完成

已在 `BPF_PROG_TEST_RUN` 前后添加 `__rdtsc()` / `__rdtscp()` 围栏，输出 `wall_exec_ns`、`exec_cycles` 和 `tsc_freq_hz`。

### 4.2 micro_exec PMU 累积模式已完成

当前已支持：
- `--perf-scope full_repeat_raw`：输出整段 repeat 的原始计数
- `--perf-scope full_repeat_avg`：输出 full-repeat 计数除以 repeat 后的平均值

### 4.3 绑核脚本（已完成）

```bash
#!/bin/bash
# run_isolated.sh — 隔离 CPU 4 运行 benchmark
sudo taskset -c 4 python3 micro/run_micro.py "$@"
```

## 5. 风险与 Threats to Validity

论文中需明确声明的限制：

1. **主指标与 wall-time 视角需区分**：`exec_ns` 是跨 runtime 的主比较指标，因为两侧都在测纯 BPF 执行时间；`wall_exec_ns` 不适合跨 runtime 比较，因为 kernel 侧会把 `BPF_PROG_TEST_RUN` syscall dispatch 开销带进来。论文中应明确区分主指标与 wall-clock 参考。

2. **PMU 范围不等价**：kernel perf counters 包含 kernel-mode 事件（context switch, page fault），llvmbpf 只看 user-mode。应用 `exclude_kernel=1` 限制 kernel 侧只看 user-mode，或声明局限。

3. **单一平台**：只在 x86-64 Intel Arrow Lake-S 上测试。BPF JIT 对 ARM64 有不同的后端代码，结论可能不同。

4. **微基准 vs 真实负载**：微基准不包含完整的 networking stack 交互（中断、NAPI、socket buffer 分配）。

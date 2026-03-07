# eBPF Micro Benchmark：实验计划、进度与分析

> 本文档是 micro benchmark 层的统一参考，合并了原来分散在多个文件中的实验计划、进度追踪、RQ 定义和结果分析。

---

## 1. 目标

在同一份 BPF ELF 产物上对比 **kernel eBPF**（Linux 内核 JIT）和 **llvmbpf**（用户态 LLVM JIT），产出可直接进入论文的可复现数据。

核心假设：llvmbpf 拥有完整 LLVM -O3 优化能力，在分支布局、指令调度、寄存器分配等代码质量维度上应优于 kernel 的单遍 JIT，但会在 map/helper 等 runtime 机制上暴露不同的 overhead 特征。

## 2. Research Questions

### RQ1: 性能差距有多大？

- **RQ1.1 代码尺寸**：kernel JIT vs llvmbpf -O3 生成的 native 指令数、代码膨胀比
- **RQ1.2 执行时间**：纯计算微基准和真实程序上的执行时间差距，是否随复杂度变化
- **RQ1.3 微架构质量**：IPC、分支预测命中率、I-cache 命中率的差异

### RQ2: 差距的根因是什么？

- **RQ2.1 基础代码质量**：寄存器分配、指令选择、指令调度的合计贡献
- **RQ2.2 Helper 调用开销**：indirect call + ABI 保存恢复的 overhead
- **RQ2.3 Map 访问模式**：hash lookup 等 map 操作的间接调用开销
- **RQ2.4 Spectre 缓解**：retpoline / LFENCE / IBRS 对 kernel JIT 增加的开销
- **RQ2.5 Verifier 约束**：bpf_loop callback、512B 栈限制、冗余边界检查的运行时开销

### RQ3: 哪类程序受益最大？

- 程序类别敏感性（networking / tracing / security / scheduling）
- Helper 调用频率分布（top-N 占比）
- 静态特征（指令数、helper 数、map 数、分支数）与优化收益的预测关系

### RQ4: 代码生成质量与 Spectre 缓解是否存在交互效应？

- 2×2 factorial: {kernel, llvmbpf} × {mitigations on/off}，交互效应量化

### RQ5: 多程序场景下的变化

- 同一 hook 挂 N 个程序的退化曲线
- 联合编译 (LTO) vs 独立编译的收益

**RQ 覆盖链条**：RQ1（测量） → RQ2（归因） → RQ3（分类预测） → RQ4（交互效应） → RQ5（多程序）

## 3. 三层架构

```
config/micro_pure_jit.yaml   ──→  纯 JIT codegen/exec 微基准  (22 case)
config/micro_runtime.yaml    ──→  map/helper runtime 机制基准  (2 case)
config/macro_corpus.yaml     ──→  真实程序语料库批跑入口       (WIP)
```

### 设计要点

- 每个 benchmark 维护一份 `programs/*.bpf.c`，两条 runtime 加载同一个 `.bpf.o`
- `programs/common.h` 提供三种 XDP wrapper 宏：
  - `DEFINE_STAGED_INPUT_XDP_BENCH` — pure-jit suite：`input_map` staging 输入，packet header 回收结果
  - `DEFINE_MAP_BACKED_XDP_BENCH` — runtime suite：`input_map` + `result_map` 全程 map 路径
  - `DEFINE_PACKET_BACKED_XDP_BENCH` — packet IO（保留）
- `run_micro.py` 读取 YAML → 生成输入 → 调度 `micro_exec` → 聚合 JSON → baseline-adjusted ratio + bootstrap CI
- `micro_exec` C++ runner：`run-llvmbpf`（ELF→bytecode→LLVM JIT→userspace exec，map 在用户态模拟）和 `run-kernel`（libbpf→BPF_PROG_TEST_RUN）
- 结果 JSON 包含 `compile_ns`、`exec_ns`、`phases_ns`、`perf_counters`、`derived_metrics`

### 当前纳入

- llvmbpf runtime（vendor/llvmbpf）
- kernel runtime（vendor/libbpf + BPF_PROG_TEST_RUN）
- vendored bpftool（可选）
- 声明式 config/*.yaml
- 共享输入生成器（确定性 LCG，23 个生成器）
- Family 元数据：category / family / level / hypothesis
- Phase timing + perf_event_open 执行窗口计数器
- Baseline-adjusted ratio + bootstrap CI + geometric mean
- Shuffle-seed 随机化执行顺序

### 暂不纳入

- `bpftool prog profile` / JIT dump 采集
- LLVM pass ablation
- Spectre on/off 双启动实验
- Macro benchmark 批跑
- 默认 suite 中的 `bpf-to-bpf local call` family（llvmbpf ELF loader 限制）

## 4. 当前覆盖

### micro_pure_jit (22 case)

| Category | Family | Benchmarks |
|----------|--------|------------|
| baseline | baseline | `simple`（harness floor），`memory_pair_sum` |
| alu-mix | popcount, log2-fold | `bitcount`, `log2_fold` |
| control-flow | search, branch-skew, switch-dispatch | `binary_search`, `branch_layout`, `switch_dispatch` |
| memory-local | reduction, parser, bounds-density, stride-load | `checksum`, `packet_parse`, `bounds_ladder`, `stride_load_4`, `stride_load_16` |
| dependency-ilp | dep-chain, spill-pressure, multi-acc | `dep_chain_short`, `dep_chain_long`, `spill_pressure`, `multi_acc_4`, `multi_acc_8` |
| loop-shape | recurrence, fixed-loop | `fibonacci_iter`, `fixed_loop_small`, `fixed_loop_large` |
| call-size | code-clone | `code_clone_2`, `code_clone_8` |

### micro_runtime (2 case)

| Category | Benchmarks |
|----------|------------|
| map-runtime | `map_lookup_churn`, `map_roundtrip` |

### 真实语料库（corpus）

6 个上游仓库，124 个候选程序源文件：

| Repo | 数量 |
|------|---:|
| bcc (libbpf-tools) | 57 |
| tetragon | 28 |
| cilium | 9 |
| libbpf-bootstrap | 15 |
| xdp-examples | 13 |
| katran | 2 |

## 5. 测量环境

```
Machine:  Intel Core Ultra 9 285K (Arrow Lake-S)
Cores:    24 (P-core × 8 + E-core × 16), no HT
Cache:    L1d 768K, L1i 1.3M, L2 40M, L3 36M
RAM:      128GB DDR5
Kernel:   6.15.11-061511-generic (PREEMPT_DYNAMIC)
OS:       Ubuntu 24.04.3 LTS
Spectre:  Enhanced IBRS + IBPB conditional
BPF:      CONFIG_BPF_JIT=y, CONFIG_BPF_SYSCALL=y, BTF enabled
```

测量策略：
- 不做人为稳定化（不锁频、不禁 turbo），通过足够重复 + 统计分析处理噪声
- 默认参数：iterations=10, warmups=2, repeat=200
- 可选 `--perf-counters` 采集执行窗口硬件计数器
- 可选 `--shuffle-seed` 随机化执行顺序
- 摘要层输出 geometric mean + bootstrap 95% CI（5000 iterations）

### 约束

- `kernel` runtime 需要 `sudo -n` 无密码可用
- llvmbpf 通过 `MAP_32BIT` 分配低地址 packet buffer，供 XDP context 的 u32 指针使用
- llvmbpf ELF loader 不支持 BPF-to-BPF local subprogram call
- `--perf-counters` kernel 计数包含 kernel 态，llvmbpf 只看 user 态
- 短执行窗口或受限 PMU 下硬件计数器可能为 0

## 6. 结果

> 以下数据基于 rdtsc 精确测量修正后的结果（2026-03-06）。
> 旧版 baseline-adjusted 数据已废弃，llvmbpf 改用 per-iteration rdtsc 测量纯 vm.exec() 时间。

### 6.1 micro_pure_jit 执行时间 (22 case)

**Suite-Level**

| 指标 | 值 |
|------|---:|
| Exec time llvmbpf/kernel geomean | 0.794x |
| Wins (llvmbpf/kernel/tie) | 13/8/1 |

**Benchmark-Level（按 exec ratio 排序）**

| Benchmark | Category | llvmbpf ns | kernel ns | Exec ratio | Code ratio |
|-----------|----------|---:|---:|---:|---:|
| `stride_load_4` | memory-local | 119 | 486 | 0.24x | 0.33x |
| `branch_layout` | control-flow | 157 | 532 | 0.30x | 0.35x |
| `binary_search` | control-flow | 210 | 653 | 0.32x | 0.45x |
| `switch_dispatch` | control-flow | 284 | 640 | 0.44x | 0.80x |
| `stride_load_16` | memory-local | 100 | 206 | 0.49x | 0.33x |
| `log2_fold` | alu-mix | 335 | 581 | 0.58x | 0.66x |
| `bounds_ladder` | memory-local | 86 | 143 | 0.60x | 0.39x |
| `checksum` | memory-local | 10823 | 12385 | 0.87x | 0.42x |
| `fibonacci_iter` | loop-shape | 607 | 954 | 0.64x | 0.40x |
| `code_clone_2` | call-size | 378 | 594 | 0.64x | 0.49x |
| `dep_chain_long` | dependency-ilp | 411 | 595 | 0.69x | 0.41x |
| `simple` | baseline | 19 | 25 | 0.76x | 0.62x |
| `spill_pressure` | dependency-ilp | 253 | 317 | 0.80x | 0.76x |
| `multi_acc_8` | dependency-ilp | 423 | 410 | 1.03x | 0.76x |
| `multi_acc_4` | dependency-ilp | 276 | 256 | 1.08x | 0.65x |
| `fixed_loop_small` | loop-shape | 97 | 85 | 1.14x | 0.36x |
| `fixed_loop_large` | loop-shape | 1572 | 1215 | 1.29x | 0.43x |
| `bitcount` | alu-mix | 4673 | 3465 | 1.35x | 0.45x |
| `packet_parse` | memory-local | 95 | 69 | 1.38x | 0.50x |
| `dep_chain_short` | dependency-ilp | 188 | 108 | 1.74x | 0.41x |
| `code_clone_8` | call-size | 2325 | 1124 | 2.07x | 0.54x |
| `memory_pair_sum` | baseline | 20 | 9 | 2.22x | 0.24x |

注：`memory_pair_sum` 和 `simple` 的 kernel exec < 50ns，低于 `ktime_get_ns` 分辨率，数值不可靠。

### 6.1b 统计严谨性分析（30 iterations × 1000 repeats）

> 数据来源：`micro/results/pure_jit_rigorous.json`，分析脚本：`micro/analyze_statistics.py`
> Bootstrap iterations: 10,000; 种子 0; 完整报告见 `micro/results/pure_jit_rigorous_analysis.md`

**Suite-Level（Bootstrap CI）**

| 指标 | 值 |
|------|---:|
| Exec ratio geomean (L/K) | 0.823 |
| 95% CI | [0.801, 0.847] |
| 统计显著 benchmarks (p < 0.05) | 16 / 22 |

**显著性与效应量**

| Benchmark | Exec Ratio | 95% CI | Cohen's d | Mann-Whitney p | Significant |
|-----------|---:|---|---:|---:|---|
| branch_layout | 0.269 | [0.263, 0.275] | -15.952 | 7.70e-12 | Yes |
| checksum | 0.894 | [0.892, 0.898] | -15.849 | 2.88e-11 | Yes |
| stride_load_16 | 0.434 | [0.412, 0.458] | -5.245 | 1.06e-11 | Yes |
| fibonacci_iter | 0.848 | [0.832, 0.864] | -4.298 | 3.20e-11 | Yes |
| binary_search | 0.502 | [0.463, 0.562] | -4.179 | 2.39e-10 | Yes |
| code_clone_8 | 1.919 | [1.810, 2.049] | 4.588 | 2.89e-11 | Yes |
| bitcount | 1.536 | [1.483, 1.594] | 7.073 | 3.02e-11 | Yes |
| fixed_loop_large | 1.193 | [1.164, 1.220] | 4.079 | 4.40e-10 | Yes |

**6 个不显著 benchmarks 的诊断**

| Benchmark | p-value | CV (llvmbpf / kernel) | 诊断 |
|-----------|---:|---|---|
| simple | 0.651 | 0.026 / 0.677 | kernel 极高方差 (ktime 分辨率) |
| memory_pair_sum | 0.069 | 0.041 / 0.799 | kernel 极高方差 (ktime 分辨率) |
| log2_fold | 0.615 | 0.019 / 0.130 | 真正接近 (ratio=0.997) |
| dep_chain_short | 1.000 | 0.016 / 0.258 | kernel 高方差 |
| packet_parse | 0.161 | 0.006 / 0.341 | kernel 高方差掩盖差异 |
| multi_acc_8 | 0.329 | 0.187 / 0.132 | 真正接近 (ratio=0.993) |

**关键发现**：kernel 侧测量方差系统性偏高（CV 中位数 0.152 vs llvmbpf 0.031）。原因：BPF_PROG_TEST_RUN 通过 ktime_get_ns 测量，包含内核调度噪声；llvmbpf 用 rdtsc 在用户态稳定得多。6 个不显著中有 4 个是 kernel 方差过高导致统计检验力不足，2 个是真正的性能相当。

### 6.1c BCF 静态字节码分析与 Helper Pareto (H4)

> 数据来源：`corpus/results/bytecode_features.json`、`corpus/results/helper_pareto.json`
> 分析脚本：`corpus/analyze_bytecode.py`，覆盖 1588 个 BCF 程序

**Helper 调用频率 Pareto (H4: top-5 = 80%+)**

| Rank | Helper ID | 名称 | 调用次数 | 占比 | 累计 |
|---:|---:|---|---:|---:|---:|
| 1 | 6 | trace_printk | 391,689 | 49.15% | 49.15% |
| 2 | 1 | map_lookup_elem | 107,497 | 13.49% | 62.64% |
| 3 | 39 | (probe_read_kernel) | 76,589 | 9.61% | 72.26% |
| 4 | 2 | map_update_elem | 47,511 | 5.96% | 78.22% |
| 5 | 11 | (tail_call) | 26,625 | 3.34% | 81.56% |

**H4 结论**：Top-5 helper 占总调用的 81.56%，假设验证通过。对 runtime 优化的启示：优先实现 trace_printk 的高效内联路径（49% 调用量），其次是 map_lookup/update（19.5%）。

**程序特征分布（1588 个程序）：**
- BPF-to-BPF 子程序调用：92.9% 的程序包含（Calico 主导）
- 平均 BPF insn 数：~3,200（中位数 ~1,800）
- Helper 种类：共 45 种不同 helper ID

### 6.2 代码质量对比（code-size + 指令分析）

**Code Size**

| 指标 | 值 |
|------|---:|
| llvmbpf/kernel native code size geomean | 0.47x |
| llvmbpf 全面更小 | 22/22 benchmarks |

**指令级分析**（完整报告见 `micro/jit-dumps/report.md`）

| 维度 | llvmbpf/kernel ratio | 说明 |
|------|---:|------|
| 总指令数 | 0.44x | LLVM 生成不到一半的指令 |
| Prologue 指令 | 0.40x | kernel 固定保存 rbp+rbx+r13-r15，LLVM 按需保存 |
| Spill 指令 | 0.85x | 寄存器溢出差距不如预期大 |
| 分支指令 | 0.76x | kernel 1:1 翻译 BPF 分支，LLVM 做布局优化 |
| cmov 指令 | 31 vs 0 | LLVM 用条件移动替代分支（`switch_dispatch` 28 个 cmov） |

**Kernel 额外指令来源分解**

| 来源 | 占总增量比例 | 说明 |
|------|---:|------|
| Byte-load-recompose | 50.7% | kernel 用 `movzbq + shl + or` 逐字节重组 32/64 位值（verifier 安全要求） |
| 分支指令 | 19.9% | 1:1 翻译 BPF 分支，不做布局优化 |
| Prologue/epilogue | 18.5% | 固定 callee-saved 寄存器保存 |

### 6.3 LLVM 优化级别消融

| 优化级别 | Code size (avg) | 说明 |
|---------|---:|------|
| -O0 | 1057 B | 无优化 baseline |
| -O1 | 307 B | **所有主要优化在此完成**（0.29x of O0） |
| -O2 | 307 B | 与 O1 完全相同 |
| -O3 | 307 B | 与 O1 完全相同 |

**关键发现**：对 BPF 程序这种短小代码，O1→O3 零增量。基础优化（DCE、常量传播、寄存器分配）就够了，高级优化（loop unroll、vectorization）无用。

### 6.4 核心矛盾："代码更小但执行更慢"

8/22 个 benchmark 中 llvmbpf 代码更小但执行更慢。根因分析（详见 `micro/jit-dumps/report.md` Root Cause Analysis）：

| Benchmark | Exec ratio | Code ratio | 根因 |
|-----------|---:|---:|------|
| `bitcount` | 1.35x | 0.45x | kernel 热循环更短的依赖链（14 vs 6），LLVM 的 BMI 指令减少了指令数但没缩短关键路径 |
| `code_clone_8` | 2.07x | 0.54x | kernel 依赖链 59 vs LLVM 45，但 kernel 用 `rorx` 合成旋转更高效 |
| `fixed_loop_large` | 1.29x | 0.43x | kernel 逐字节加载在此场景下不影响关键路径，LLVM 省掉的指令不在热路径上 |
| `dep_chain_short` | 1.74x | 0.41x | verifier-safe 的 byte-load ladder 延长关键路径 |

**论文洞察**：代码大小 ≠ 性能。LLVM 的指令消除优化主要减少非关键路径指令，但 kernel JIT 的 1:1 翻译在某些数据流模式下偶然产生了更短的依赖链。

### 6.5 测量方法论修正

| 问题 | 旧方法 | 修正后 |
|------|--------|--------|
| llvmbpf exec_ns | `steady_clock` 包裹 `vm.exec()`，含 ~2μs harness 开销 | per-iteration `rdtsc/rdtscp` 仅测 vm.exec() 调用 |
| 旧的 baseline-adjusted ratio | 减去 `simple` baseline，统计上脆弱 | 废弃，改用 rdtsc 直接测量 |
| IPC 对比 | kernel 0.37 vs llvmbpf 3.89，perf counter 窗口不等价 | 已知限制，perf counter 对比需谨慎解读 |

### 6.6 micro_runtime (2 case)

| Benchmark | llvmbpf exec | kernel exec | Ratio |
|-----------|---:|---:|---:|
| `map_lookup_churn` | 324 ns | 260 ns | 1.24x |
| `map_roundtrip` | 323 ns | 553 ns | 0.58x |

## 7. 迭代计划与进度

### Iteration 1 — 基础设施 ✅

- [x] perf_event_open 支持
- [x] 语料库 manifest + fetch 脚本
- [x] 论文骨架
- [x] RQ 摘要脚本

### Iteration 2 — 扩展 suite ✅（大部分完成）

- [x] 拆分 config 为 micro_pure_jit / micro_runtime / macro_corpus
- [x] 扩展 micro_pure_jit 到 22-case family 结构
- [x] 拆分 pure-jit 和 runtime ABI 为 staged/map 模式
- [x] 增加 map/helper-like 和 verifier-style micro case
- [x] Bootstrap/gmean-oriented 摘要生成
- [x] 第一波真实语料库拉取

### Iteration 3 — 代码质量与归因（进行中）

**已完成：**
- [x] JIT dump / code-size 采集 — `--dump-jit` flag + `code_size` JSON 字段（RQ1.1 已关闭）
- [x] rdtsc 精确测量修正 — 消除 harness 开销，llvmbpf exec_ns 现在公平
- [x] LLVM 优化级别消融 — `--opt-level 0/1/2/3`，发现 O1=O2=O3
- [x] 指令级 JIT 分析 — `dump_all_jit.sh` + `analyze_jit.py`，byte-recompose / BMI / cmov / prologue / 依赖链
- [x] BCF 数据集获取 — 1588 个程序已下载到 `corpus/bcf/`
- [x] llvmbpf dummy helper 注册 — 注册 helper 3-220 为 no-op stub，解锁 Cilium/collected/inspektor-gadget 编译
- [x] ELF loader relocation 修复 — 跳过越界 relocation 而非 crash，支持带子程序的 ELF

**BCF 批量结果（2026-03-06）：**
- llvmbpf 编译成功率：60/1588（3.8%）
  - Cilium: 42/42 ✅（无 BPF-to-BPF call）
  - inspektor-gadget: 11/11 ✅
  - collected: 7/9 ✅
  - Calico: 0/1476 ❌（全部有 BPF-to-BPF 子程序调用）
  - bcc: 0/8 ❌（有子程序调用）
  - bpf-examples: 0/42 ❌（有子程序调用）
- **瓶颈**：llvmbpf 不支持 BPF-to-BPF internal function calls（compiler.cpp 未实现）
- kernel 侧全部 1588 个程序都加载失败（verifier 拒绝 / 缺少 map/BTF context）

**TODO — 广度扩展（scale up to 500+ programs）：**
- [ ] **T3.1 BCF 真实程序 code-size 批量对比** — kernel 侧 load + bpf_prog_info 取 jited_prog_len；llvmbpf 侧 load_code + compile 取 native size。不需要执行。目标：500+ 程序的 code inflation ratio 分布图
- [x] **T3.2 BCF 静态特征提取** — `corpus/analyze_bytecode.py` 提取 1588 个程序的 insn count、helper call、BPF-to-BPF call、map 数。输出 `corpus/results/bytecode_features.json`
- [x] **T3.3 Helper 调用频率 Pareto 分析 (H4)** — Top-5 = 81.56%，H4 验证通过。详见 §6.1c

**TODO — 深度加强（rigorous root cause）：**
- [ ] **T3.4 编译时间分析** — compile_ns 已在 JSON 中，需要系统分析 kernel vs llvmbpf 编译时间，按 benchmark 分类
- [x] **T3.5 统计严谨性补充** — 30 iterations × 1000 repeats，bootstrap CI + Cohen's d + Mann-Whitney U。16/22 显著。详见 §6.1b
- [ ] **T3.6 时间域因素分解** — 指令层分析只回答"多了多少指令"，不回答"慢了多少时间"。需要：(a) 用 PMU 的 IPC 数据估算各类指令的时间贡献；(b) 构建针对性 micro-benchmark 隔离 byte-recompose 的时间开销
- [ ] **T3.7 LLVM Pass-level 消融** — 不只是 O0/O1/O2/O3，而是逐个 pass 启用（instcombine、GVN、RegAlloc、SimplifyCFG 等），识别对 BPF 最有价值的 pass
- [ ] **T3.8 Perf counter 相关性分析** — IPC/branch-miss/cache-miss vs exec ratio 的 Pearson/Spearman 相关系数矩阵
- [ ] **T3.9 静态特征→优化收益预测模型 (RQ3.3)** — 用 T3.2 的特征 + code-size ratio 做线性回归/随机森林，识别最强预测因子

**TODO — 补充实验：**
- [ ] **T3.10 Spectre 2×2 实验** — 需重启 mitigations=off（低优先级）
- [ ] **T3.11 verifier/load/JIT 分段统计** — 接入 veristat 或 BPF_OBJ_GET_INFO_BY_FD 取 verified_insns
- [ ] **T3.12 增加 helper-call / tail-call micro case** — 当前 runtime suite 只有 2 个 case，需扩展
- [ ] **T3.13 扩展 llvmbpf ELF loader 支持 local subprogram call** — 解锁 code_clone 等更多程序

**TODO — Actionable Insights（OSDI/SOSP 要求的"so what"）：**
- [ ] **T3.14 内核 JIT 改进建议** — 基于分析结果，提出具体 patch 级建议（如：添加 cmov 支持、优化 byte-recompose pattern、按需 callee-saved 保存）
- [ ] **T3.15 与 K2/Merlin/EPSO 的正交性分析** — 比较 bytecode 级优化（verifier 前）vs JIT 后端优化（native 级）的空间重叠度，证明互补性
- [ ] **T3.16 跨工具对比定位** — 将我们的 characterization 与 CoNEXT'25（网络应用性能）、"No Two Snowflakes"（运行时差异）、ETH Zurich（多核扩展）等已有实证工作对比，明确差异化

### Iteration 4 — 系统贡献与提交

- [ ] Helper inlining (S3) 实现 — UEOS 核心差异化
- [ ] 等价性验证 V1（BPF_PROG_TEST_RUN 差分测试）
- [ ] 端到端 Cilium/Katran 评估
- [ ] 多程序实验（RQ5）
- [ ] 图表生成脚本
- [ ] 论文写作

## 8. 数据采集方法总结

| 维度 | kernel 侧工具 | llvmbpf 侧工具 |
|------|-------------|---------------|
| 执行时间 | BPF_PROG_TEST_RUN duration (内核内部 ktime) | per-iteration rdtsc/rdtscp (纯 vm.exec) |
| Wall exec 时间 | prog_run_wall_ns (steady_clock) | wall_exec_ns (steady_clock, 含 harness) |
| 编译/加载时间 | bpf_object__open + bpf_object__load | llvmbpf load_code + compile |
| 硬件计数器 | perf_event_open (include_kernel=true) | perf_event_open (user only) |
| 代码尺寸 | bpf_prog_info.jited_prog_len / xlated_prog_len | get_compiled_code().size / insn_count × 8 |
| JIT 代码 dump | `--dump-jit` → .kernel.bin | `--dump-jit` → .llvmbpf.bin |
| 指令分析 | `objdump -D -b binary -m i386:x86-64` | 同左 |
| Verifier 统计 | veristat（待接入） | N/A |
| Phase 分段 | object_open / object_load / prog_run_wall / result_read | program_image / memory_prepare / input_stage / vm_load_code / jit_compile |
| 优化级别 | N/A (kernel JIT 无选项) | `--opt-level 0/1/2/3` |

## 9. 添加新 benchmark 的流程

1. 创建 `micro/programs/<name>.bpf.c`：定义 input struct + `input_map` + `bench_*()` 函数 + 对应 `DEFINE_*_XDP_BENCH` 宏
2. 在 `micro/input_generators.py` 中添加生成器函数并注册到 `GENERATORS`
3. 在对应 `config/*.yaml` 中添加 benchmark 条目：`name`、`base_name`、`kernel_input_size`、`input_generator`、`expected_result`、category/family/level/hypothesis/tags

## 10. 参考文档

以下文档保留在 `docs/` 中作为背景参考，不再单独维护进度：

| 文件 | 角色 |
|------|------|
| `benchmark-framework-design.md` | 早期设计文档，定义了 RQ 子问题、7 个假设、两级架构、数据采集方法清单和测量环境详细信息 |
| `ebpf-bench-research-plan.md` | 文献综述，90+ 论文梳理，现有 benchmark 工具分析 |
| `references/linux-bench-framework-analysis.md` | Linux 内核 bench 框架架构分析 |
| `references/third-party-analysis.md` | 三个第三方 benchmark 项目详细分析 |
| `ebpf-characterization-paper-draft.md` | 论文草稿（随数据更新） |

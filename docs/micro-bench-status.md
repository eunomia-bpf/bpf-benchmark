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

## 6. 初步结果

### 6.1 micro_pure_jit (22 case)

**Suite-Level**

| 指标 | 值 | 95% CI |
|------|---:|---:|
| Raw exec llvmbpf/kernel geomean | 1.06x | [0.80x, 1.46x] |
| Baseline-adjusted geomean | 0.68x | [0.54x, 0.84x] |
| Adjusted wins (llvmbpf/kernel/tie) | 14/4/3 | — |

**Category-Level（baseline-adjusted）**

| Category | Benchmarks | Adjusted gmean | 95% CI | Wins (l/k/t) |
|----------|---:|---:|---:|---|
| alu-mix | 2 | 0.52x | [0.50x, 0.54x] | 2/0/0 |
| baseline | 1 | 0.33x | [0.33x, 0.33x] | 1/0/0 |
| call-size | 2 | 1.06x | [0.99x, 1.15x] | 0/1/1 |
| control-flow | 3 | 0.32x | [0.20x, 0.50x] | 3/0/0 |
| dependency-ilp | 5 | 1.00x | [0.94x, 1.07x] | 2/1/2 |
| loop-shape | 3 | 1.01x | [0.92x, 1.17x] | 2/1/0 |
| memory-local | 5 | 0.62x | [0.46x, 0.91x] | 4/1/0 |

**Benchmark-Level（按 adjusted ratio 排序）**

| Benchmark | Category | llvmbpf exec | kernel exec | Adjusted ratio | 95% CI |
|-----------|----------|---:|---:|---:|---:|
| `branch_layout` | control-flow | 167 ns | 608 ns | 0.20x | [0.17x, 0.26x] |
| `binary_search` | control-flow | 224 ns | 546 ns | 0.33x | [0.28x, 0.41x] |
| `memory_pair_sum` | baseline | 48 ns | 8 ns | 0.33x | [0.17x, 5.00x] |
| `stride_load_16` | memory-local | 119 ns | 172 ns | 0.43x | [0.28x, 0.54x] |
| `bounds_ladder` | memory-local | 109 ns | 138 ns | 0.47x | [0.23x, 0.65x] |
| `stride_load_4` | memory-local | 120 ns | 158 ns | 0.48x | [0.46x, 0.61x] |
| `log2_fold` | alu-mix | 254 ns | 423 ns | 0.50x | [0.39x, 0.77x] |
| `switch_dispatch` | control-flow | 244 ns | 401 ns | 0.50x | [0.45x, 0.74x] |
| `bitcount` | alu-mix | 1.886 us | 3.382 us | 0.54x | [0.51x, 0.58x] |
| `checksum` | memory-local | 9.130 us | 12.140 us | 0.75x | [0.74x, 0.75x] |
| `dep_chain_short` | dependency-ilp | 133 ns | 99 ns | 0.92x | [0.56x, 1.46x] |
| `fibonacci_iter` | loop-shape | 619 ns | 629 ns | 0.92x | [0.86x, 1.01x] |
| `multi_acc_8` | dependency-ilp | 323 ns | 304 ns | 0.92x | [0.82x, 1.04x] |
| `fixed_loop_large` | loop-shape | 1.036 us | 1.040 us | 0.96x | [0.87x, 1.04x] |
| `code_clone_2` | call-size | 310 ns | 272 ns | 0.99x | [0.48x, 1.14x] |
| `dep_chain_long` | dependency-ilp | 390 ns | 352 ns | 0.99x | [0.74x, 1.12x] |
| `spill_pressure` | dependency-ilp | 272 ns | 228 ns | 1.01x | [0.87x, 1.22x] |
| `multi_acc_4` | dependency-ilp | 253 ns | 186 ns | 1.15x | [0.59x, 1.41x] |
| `code_clone_8` | call-size | 1.232 us | 1.038 us | 1.15x | [1.06x, 1.21x] |
| `fixed_loop_small` | loop-shape | 118 ns | 67 ns | 1.17x | [1.04x, 2.69x] |
| `packet_parse` | memory-local | 123 ns | 68 ns | 1.22x | [0.57x, 2.71x] |

**Perf-Counter Signal**

| Runtime | Median IPC | Branch miss rate | Cache miss rate |
|---------|---:|---:|---:|
| kernel | 0.37 | 0.60% | 7.68% |
| llvmbpf | 3.89 | 0.47% | 15.00% |

### 6.2 micro_runtime (2 case)

| 指标 | 值 | 95% CI |
|------|---:|---:|
| Raw exec llvmbpf/kernel geomean | 0.85x | [0.58x, 1.24x] |

| Benchmark | llvmbpf exec | kernel exec | Ratio |
|-----------|---:|---:|---:|
| `map_lookup_churn` | 324 ns | 260 ns | 1.24x |
| `map_roundtrip` | 323 ns | 553 ns | 0.58x |

### 6.3 初步观察

1. **llvmbpf 在 control-flow 和 alu-mix 类别优势显著**（0.32x-0.52x），LLVM 的分支布局优化和位操作优化起了关键作用
2. **dependency-ilp 和 loop-shape 接近平手**（~1.0x），说明纯标量依赖链和简单循环两侧 JIT 差距不大
3. **kernel 在部分场景仍有优势**：`packet_parse`（1.22x）可能受益于 kernel 的 packet-oriented JIT 路径，`fixed_loop_small`（1.17x）可能体现 llvmbpf 的 harness 固定开销在短任务上更明显
4. **IPC 差距巨大**（3.89 vs 0.37）：kernel 的 `BPF_PROG_TEST_RUN` 测量路径包含更多内核态开销，不完全等价于纯 BPF 执行
5. **llvmbpf compile 时间通常慢于 kernel load/JIT**：执行层面的赢面不自动转化为加载路径的赢面
6. **runtime suite 仅 2 case**，结论还不够稳固

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

### Iteration 3 — 代码质量与归因（当前）

- [ ] JIT dump / code-size 采集（关闭 RQ1.1）
- [ ] verifier/load/JIT 分段统计（将 compile_ns 拆分为 verifier、JIT、ELF parse 三段）
- [ ] 扩展 llvmbpf ELF loader 支持 local subprogram call → 解锁 `call-chain` family
- [ ] 增加 real helper-call micro case（超越 map lookup/update）
- [ ] 增加 tail-call 和 multi-program micro case
- [ ] 评估完全无 helper 的 pure-jit ABI 是否可行

### Iteration 4 — 完善与提交

- [ ] 多程序实验（RQ5）
- [ ] 端到端应用场景
- [ ] 图表生成脚本
- [ ] 收紧论文为 OSDI/SOSP 格式

## 8. 数据采集方法总结

| 维度 | kernel 侧工具 | llvmbpf 侧工具 |
|------|-------------|---------------|
| 执行时间 | BPF_PROG_TEST_RUN duration | steady_clock + repeat 均摊 |
| 编译/加载时间 | bpf_object__open + bpf_object__load | llvmbpf load_code + compile |
| 硬件计数器 | perf_event_open (include_kernel=true) | perf_event_open (user only) |
| 代码尺寸 | bpftool prog dump jited（待接入） | llvm-objdump（待接入） |
| Verifier 统计 | veristat（待接入） | N/A |
| Phase 分段 | object_open / object_load / prog_run_wall / result_read | program_image / memory_prepare / input_stage / vm_load_code / jit_compile |

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

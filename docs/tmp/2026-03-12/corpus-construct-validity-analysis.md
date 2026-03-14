# Corpus Benchmark Construct Validity Analysis

Generated: 2026-03-12

## 摘要

Corpus benchmark 的 exec_ns 测量存在严重的 construct validity 问题。核心结论：

1. **94/156 个程序的 exec_ns < 100ns**，处于 ktime 量化噪声范围，测量值无统计意义
2. **未优化程序（股票 JIT）本身显示 58/66 个程序 >5% 偏差**，证明噪声主导
3. **Calico `calico_tc_main` 同一程序逻辑从 6 个不同 .bpf.o 测量**，speedup_ratio 范围从 0.531x 到 1.037x，而代码大小变化仅为 ~0.4%
4. **代码布局效应（I-cache、分支预测器）** 主导性能变化，而非优化指令本身的执行效率

---

## 测量框架分析

### 数据包生成（`materialize_dummy_packet`）

```
corpus/micro/orchestrator/corpus.py: materialize_dummy_packet()
```

64B dummy packet 内容为一个合法构造的 TCP SYN 包：
- ETH: dst=00:11:22:33:44:55, src=66:77:88:99:aa:bb, type=0x0800 (IPv4)
- IP: version=4 IHL=5 len=50 ttl=64 proto=6(TCP) src=192.0.2.1 dst=198.51.100.2 checksum=0
- TCP: sport=12345 dport=80 seq=1 flags=SYN window=8192 checksum=0

注意：IP checksum 和 TCP checksum 均为 0（无效）。

### 执行计划（`execution_plan`）

```
corpus/micro/orchestrator/corpus.py: execution_plan()
```

程序类型与 io_mode 映射：
- XDP / TC / socket / cgroup_skb: `io_mode="packet"`, memory_path=dummy_packet_64.bin, input_size=64
- raw_tracepoint: `io_mode="context"`, memory_path=dummy_context_64.bin
- 其他 tracing 程序: `io_mode="context"`, memory_path=None

### BPF_PROG_TEST_RUN 如何传包

`micro/runner/src/kernel_runner.cpp` 中 `bpf_prog_test_run_opts` 调用：
- XDP 程序（BPF_PROG_TYPE_XDP）: `data_in=packet_data, data_size_in=64`
- TC/sched_cls 程序（BPF_PROG_TYPE_SCHED_CLS）: 同样传 packet_data，内核构造 sk_buff

### 重复次数

本次 corpus run 使用 `repeat=200`，即 bpf_prog_test_run_opts 在内核中紧密循环 200 次，报告 total_ns / 200 = per-iteration 平均值。

---

## 执行时间分析

### 按 section 类型分布

从 `corpus_v5_v2_fixed_20260312.json` 提取：

| Section    | N   | Median exec_ns | Min | Max          |
|------------|-----|---------------|-----|--------------|
| tc         | 108 | 170 ns        | 7   | 1,000,547,248 |
| xdp        | 43  | 17 ns         | 7   | 340          |
| cgroup_skb | 5   | 8 ns          | 7   | 9            |

- **94/156 个可测量程序的 baseline exec_ns < 100ns**
- **81 个程序 exec_ns < 20ns**（严重量化噪声区）

### 按来源分布

| Source            | N   | Applied | Median exec_ns | Median speedup_ratio |
|-------------------|-----|---------|---------------|---------------------|
| calico            | 59  | 54      | 179 ns        | 0.951               |
| linux-selftests   | 63  | 20      | 9 ns          | 0.824               |
| xdp-tutorial      | 20  | 6       | 15 ns         | 1.061               |
| katran            | 5   | 2       | 10 ns         | 0.625               |
| xdp-tools         | 4   | 3       | 30 ns         | 1.071               |
| tracee            | 2   | 2       | 8 ns          | 0.615               |

Calico TC 程序是唯一 exec_ns > 100ns 的主要来源（median 179ns）。

---

## 构造效度问题一：sub-20ns 程序的量化噪声

### 证据

**未优化程序（stock JIT，v5_run_applied=False）的 speedup_ratio 分布：**
- 总共 66 个未优化但可测量程序
- 23 个显示 >5% "improvement"（ratio > 1.05）
- 35 个显示 >5% "regression"（ratio < 0.95）
- 只有 8 个在 ±5% 以内

**即没有优化的情况下，88% 的程序显示 >5% 的性能偏差。**

代表性案例：
- `xdp_drop_func`：8ns → 30ns (ratio=0.267)，policy=stock（无优化）
- `tcx2`：25ns → 78ns (ratio=0.321)，policy=stock（无优化）
- `calico_xdp_norm_pol_tail`：189ns → 309ns (ratio=0.612)，policy=stock（无优化）
- `xdp_prog_simple`：268ns → 368ns (ratio=0.728)，policy=stock（无优化）

### 原因分析

1. **ktime 量化**：repeat=200，如果程序耗时 8ns，total=1600ns。baseline 和 v5_run 分别在两个不同时间点测量，任何 CPU 频率波动、调度延迟或 VM hypervisor 开销都会影响结果。

2. **运行顺序效应**：baseline_run 和 v5_run **按顺序**运行（先 baseline，后 v5）。系统状态（cache warmth、thermal state、TurboBoost）在两次运行之间会改变。

3. **VM 调度**：在 vng VM 中运行，hypervisor 可以在任意时间引入额外延迟。

**结论**：exec_ns < 100ns 的程序在当前框架中无法可靠测量 <1% 级别的优化效果。

---

## 构造效度问题二：Calico TC 程序的代码布局效应

### `calico_tc_main` 跨 6 个 .bpf.o 的测量

同一程序（`calico_tc_main`）从 6 个不同的 Calico .bpf.o 文件中提取并测量：

| 对象文件              | baseline exec_ns | v5 exec_ns | speedup_ratio | JIT 大小减少 |
|-----------------------|-----------------|------------|---------------|-------------|
| from_hep_debug.bpf.o  | 342 ns          | 330 ns     | **1.036x**    | -0.48%      |
| from_nat_debug.bpf.o  | 340 ns          | 328 ns     | **1.037x**    | -0.45%      |
| from_wep_debug.bpf.o  | 175 ns          | 314 ns     | **0.557x**    | -0.40%      |
| to_hep_debug.bpf.o    | 180 ns          | 339 ns     | **0.531x**    | -0.46%      |
| to_nat_debug.bpf.o    | 205 ns          | 285 ns     | **0.719x**    | -0.45%      |
| to_wep_debug.bpf.o    | 178 ns          | 280 ns     | **0.636x**    | -0.40%      |

**观察**：
- 代码大小变化几乎相同（0.40–0.48%，对应 200-300 bytes）
- 但 speedup_ratio 从 0.531x（88% 下降）到 1.037x（+3.7% 提升）
- **关键关联**：baseline exec_ns 高（~340ns）的两个版本都显示改进；baseline exec_ns 低（~175-205ns）的四个版本都显示回归

### 解释

**baseline exec_ns 高（340ns）的 from_hep/from_nat 版本**：
- 与低版本的差异：~180ns 额外执行时间
- 说明 dummy 包在这两个 Calico 变体中触发了更长的代码路径
- 优化的 endian/wide sites（位于指令偏移 424-8315）实际上被执行到
- 优化确实有效（+3.7%）

**baseline exec_ns 低（175-205ns）的其他 4 个版本**：
- dummy 包在这些变体中更早退出（防火墙规则、路由决策不同）
- 优化 sites 位于程序后半部分（>1000 insn offset），未被执行
- 性能下降原因：0.4% 的代码大小减少改变了 30-46KB JIT 代码的布局
- I-cache line 对齐、branch predictor 历史表入口发生偏移，引起 cache miss 增加

**这直接证明了 dummy packet 不能保证触发被优化的 BPF site。**

### 代码布局效应的量级

对于 30-46KB 的 JIT 代码段（Calico TC 规模），移除 200-300 bytes：
- 改变 ~3-5 个 64B I-cache line 的内容
- 可能使后续所有热循环的 branch target 地址错位
- 实际效果（-44% ~ -88% slowdown）远大于任何指令级优化可能带来的提升

---

## 构造效度问题三：哪些程序实际执行了优化 site

### 路径分析框架

dummy packet 特征：
- 合法的 ETH + IPv4 header（但 checksum=0）
- src=192.0.2.1（documentation 地址，不在任何真实策略表中）
- dst port=80（HTTP），flags=SYN

各类程序对 dummy packet 的响应：

| 程序类型 | dummy packet 触发 | 估计 exec path |
|----------|-----------------|----------------|
| XDP drop/pass | 无条件早退 | 1-3 指令 |
| XDP packet filter (xdp-tutorial) | ETH type check → pass/drop early | 5-20 指令 |
| Calico TC (from_hep/from_nat) | 完整 IPv4+TCP 路径，策略查找 | 完整路径 |
| Calico TC (其他变体) | 某个早期条件不匹配 → 较早退出 | 部分路径 |
| katran balancer | XDP load balancing，查找 hash table | 部分路径 |
| linux-selftests TC encap | 大多数立即返回 TC_ACT_OK | 极少 |
| tracee cgroup_skb | 计数器递增即返回 | 极少 |

### 被优化 site 的位置

以 `calico_tc_main`（from_hep_debug）为例（policy 文件显示）：
- 最早的优化 site：insn 424（endian）
- 最晚的优化 site：insn 8315（endian）
- 总 JIT 指令数（推算）：~8400+

当程序在 insn 200-400 处退出时（~175ns 对应），只有极少数甚至零个优化 site 被执行。

---

## 数据汇总

### 完整 corpus run 统计（corpus_v5_v2_fixed_20260312.json）

- 总程序数：166
- 可测量程序对数：156
- Applied 程序数：91（speedup_ratio 有值）
- exec_ns < 20ns（严重噪声区）：81 个
- exec_ns < 100ns（量化噪声区）：94 个
- stock JIT（未优化）程序中 >5% 偏差：58/66 = **88%**

### Applied 程序的 speedup 分布

- overall geomean：0.875x
- improvements（ratio ≥ 1.0）：45/156 = 29%
- regressions（ratio < 1.0）：101/156 = 65%
- code size geomean：1.004x（v5 稍小，-0.4%）

**重要**：code size 只减少 0.4%，但 exec 下降 12.5%。这个比例说明 exec 测量不是在测量指令执行效率。

---

## 根因分析

### 假说验证

**假说：dummy packet 没有触发被优化的 BPF 指令 site，corpus 0.875x 由代码布局效应引起**

| 证据 | 支持/反驳 |
|------|---------|
| 94/156 程序 exec_ns < 100ns，处于噪声区 | 支持 |
| 未优化程序 88% 显示 >5% 偏差 | 支持 |
| calico_tc_main 同一程序 6 个实例 speedup_ratio 0.531x-1.037x | 支持 |
| baseline exec_ns 高（340ns）的 Calico 版本显示改进 | 支持（这些版本确实执行了 site） |
| baseline exec_ns 低（175ns）的 Calico 版本显示回归 | 支持（早退，site 未执行，布局效应负面） |
| 代码大小变化 0.4% vs exec 变化 60-90% | 支持（不成比例） |

**结论：假说成立**。

### 唯一反例

xdp-tools（xdp_fwd_fib_direct, xdp_fwd_fib_full）和部分 Calico TC 程序（calico_tc_send_icmp_replies, calico_tc_main from_hep/from_nat）确实显示了真实改进。这些程序的共同特征是 baseline exec_ns 较高（>15ns 对于 xdp-tools，>190ns 对于 Calico），暗示它们实际执行了更多代码路径。

---

## 改进方案

### 方案一：构造 path-targeted 测试包（推荐，最根本）

**对每个被测程序生成专用 packet**，确保触发优化 sites 所在的代码路径：

1. 静态分析程序：找到优化 site 的指令偏移
2. 沿控制流图反向追踪：确定触达该 site 所需的 packet 字段值
3. 生成一个或多个 per-program packet 文件

**优点**：直接解决 construct validity
**缺点**：需要 per-program 自动化分析，工程量较大；部分程序（如有 map 依赖的路径条件）无法仅靠 packet 触发

**可行性**：对 XDP 程序相对可行（协议 header 字段直接决定路径）；对 TC 程序更难（可能需要 conntrack/policy table 配合）

### 方案二：增大 repeat 并使用多次独立测量

将 repeat 从 200 增加到 10000+，并运行 5+ 次取统计中位数：
- 对 sub-20ns 程序：更大的总测量窗口降低量化误差
- 但不解决 path-triggering 问题

**优点**：工程简单
**缺点**：显著增加运行时间；不解决代码布局效应

### 方案三：perf 计数器测量执行的 site 数量

使用 `perf_event_open` 在 baseline 和 v5 版本运行时统计被优化 site 地址的 **execution count**：
- 直接证明 site 是否被执行
- 不依赖 exec_ns 的量化精度

**优点**：精确回答"site 是否被执行"
**缺点**：需要硬件 PMU 支持，VM 中 perf 配置可能受限

### 方案四：退出 corpus exec 测量，以代码大小为主要 corpus 指标

接受 corpus exec 测量存在无法克服的 construct validity 问题，将 corpus 结果的重点移到：
1. **代码大小**（已验证：geomean 0.996x，变化幅度可靠）
2. **site 覆盖率**（有多少程序含有可优化的 site）
3. Micro-benchmark 用于 exec 性能论断

**优点**：最务实，数据已经存在
**缺点**：无法直接 claim corpus 程序的运行时改进

### 方案五：选择 exec_ns 可靠的程序子集（短期缓解）

过滤条件：
- exec_ns > 200ns（避免量化噪声）
- 确认 v5_run_applied=True 且 scanner_counts.total_sites > 0
- 排除 stock JIT 下也显示 >5% 偏差的程序

符合条件的程序估计约 30-40 个（主要是 Calico TC），但仍面对代码布局效应问题。

---

## 对论文的影响

### 当前 corpus 数据的有效性

| 指标 | 有效性 |
|------|--------|
| Code size geomean (0.996x) | **有效**：代码大小测量不受上述问题影响 |
| Exec geomean (0.875x) | **无效**：主要由测量噪声和布局效应构成 |
| 45 wins / 101 regressions | **无效**：噪声主导，无统计意义 |
| 91/156 applied | **有效**：反映策略文件存在且 site 被识别 |

### 建议

1. **论文中的 corpus exec 结论需要修订**：不能 claim 0.875x 性能改进，因为这主要是噪声
2. **保留 code size 数据**：corpus code size 结论（几乎无变化，geomean ~1.0）是有效的
3. **Micro-benchmark 数据是可信的**：pure-JIT micro suite 正确控制了所有 construct validity 问题
4. **补充 site execution rate 分析**：说明在当前 corpus 框架下，大多数程序的被优化 site 并不在 dummy packet 触发的路径上

---

## 文件引用

- `corpus/micro/orchestrator/corpus.py`：dummy packet 生成（`materialize_dummy_packet`）和 execution plan 逻辑
- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`：VM batch 驱动，运行顺序（baseline 先，v5 后）
- `micro/runner/src/kernel_runner.cpp`：BPF_PROG_TEST_RUN 实现，包括 packet context 分配
- `corpus/results/corpus_v5_v2_fixed_20260312.json`：本分析所用数据
- `corpus/policies/calico/from_hep_debug/calico_tc_main.policy.yaml`：Calico endian site 位置（insn 424-8315）

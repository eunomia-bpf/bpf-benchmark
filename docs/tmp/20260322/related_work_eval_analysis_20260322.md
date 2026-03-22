# 相关工作 Evaluation 方法论分析

**日期**: 2026-03-22
**分析对象**: 5 篇论文的 Evaluation section
**重要说明**: `08-merlin.pdf` 和 `09-epso.pdf` 均为下载错误（文件名与内容不符）。08 实际是 Nature Genetics 2002 遗传图谱论文，09 实际是计算智能领域粒子群算法章节。以下分析对这两篇论文如实记录，并在"对我们的启示"部分以其他 3 篇高质量 eBPF/BPF 论文为主要参考。

---

## 论文 1: K2 (SIGCOMM'21)

**全称**: "Synthesizing Safe and Efficient Kernel Extensions for Packet Processing"
**文件**: `07-k2.pdf`

### 评估结构

**1. RQ / Evaluation Goals (§8)**

K2 的评估明确列出 6 个问题：
1. K2 合成程序有多紧凑？（program compactness）
2. K2 对 latency 和 throughput 有多大提升？
3. K2 能否产生安全、通过 kernel checker 的程序？
4. 等价性检查优化效果？（§5）
5. K2 的搜索参数影响？
6. domain-specific rewrite rules 有多重要？

**2. Baselines**

- clang 编译结果（-O1/-O2/-O3/-Os 四个变体），取"最优"变体作为基准
- K2 与 clang 最优变体对比，不与其他优化工具对比

**3. Workloads**

- **19 个真实 BPF 程序**，来源多样：
  - Linux kernel BPF samples（1-13）
  - Facebook（14, 19）
  - Cilium（17, 18）
  - hXDP（15, 16）
- attach 点：XDP、TC（transport-level sockets）、system calls
- 程序规模：4 个基本块（xdp_exception）到 247 个基本块（xdp_balancer）
- 指令数：18-1811 条

**4. 主要 Metric**

- **Program compactness**: 指令数（K2 vs clang 各变体）+ compression ratio（%）+ 搜索时间（秒）+ 迭代次数
- **Throughput**: MLFFR（Maximum Loss-Free Forwarding Rate），单位 Mpps，单核
- **Latency**: 平均延迟（微秒），在 4 种不同 offered load 下测量
- **Safety**: 38 个输出程序通过 kernel checker 的比例（100%）
- **等价性检查加速**: 时间 vs slowdown（orders of magnitude）

**5. 硬件平台**

- CloudLab [66]，两台 server-class 机器（T-Rex 流量生成器 + DUT）
- 均为 10-core Intel Broadwell (E5-2640v4) 2.4 GHz，PCIe 3.0，64 GB RAM，Mellanox ConnectX-4 25G NIC
- **单一硬件平台**，只有 x86

**6. 统计方法**

- Throughput 取 3 次 trial 平均，每次在吞吐量稳定后取值（等 60 秒或数字稳定）
- Latency 在 4 个不同 offered load 下测量（low/medium/high/saturating）
- **无 confidence interval**，**无 significance test**
- 重复次数很少（3 trials），依赖 CloudLab 的网络实验稳定性

**7. 数据呈现方式**

- **Table 1**: 每 benchmark 的基本块数、指令数（-O1/-O2/-O3/-Os/K2）、compression ratio、搜索时间（秒）、迭代数 — per-program breakdown
- **Table 2**: throughput（MLFFR，Mpps）per benchmark，含 -O1/-O2/-O3/K2 列
- **Table 3**: 4 个 offered load 下的 average latency（微秒），per benchmark
- **Table 4**: 等价性检查优化的加速比（orders of magnitude），per benchmark
- **Figure 2**: 实验 setup 示意图
- Appendix H: latency 详细数据

---

## 论文 2: Merlin (ASPLOS'24)

**重要说明**: `08-merlin.pdf` 实际内容是 Nature Genetics 2002 论文"Merlin—rapid analysis of dense genetic maps using sparse gene flow trees"（遗传学，Abecasis 等），并非 ASPLOS'24 的 eBPF Merlin 论文。这是下载脚本匹配错误。以下分析该实际文件的内容，并注明无法用于 BpfReJIT 参考。

**实际内容分析（仅供记录）**:
- 评估目标：比较 Merlin（稀疏基因流树算法）vs Genehunter v2.1 vs Allegro v1.1b 的计算速度
- Baseline: Genehunter, Allegro 两个竞品
- Workload: 4 种模拟 pedigree（A/B/C/D），不同缺失基因型比例（5%/10%/20%/50%）
- Metric: 计算时间（分钟/秒）
- 硬件: 700 MHz Pentium III, 2 GB RAM
- 呈现: Table 2（各程序在不同 pedigree 上的时间）、Table 3（错误检测率）

**结论**: 该文件与 BpfReJIT 评估无关，无法提供 eBPF 领域的方法论参考。

---

## 论文 3: EPSO (ASE'25)

**重要说明**: `09-epso.pdf` 实际内容是 Springer 2007 书章节"EPSO: Evolutionary Particle Swarms"（V. Miranda 等），是电力系统优化领域的粒子群算法，并非 ASE'25 的 eBPF 论文。下载脚本在搜索"EPSO"时匹配了错误来源。

**实际内容分析（仅供记录）**:
- 评估目标：EPSO vs 标准 PSO 在标准优化函数上的收敛速度和解质量
- Baseline: 标准 PSO (PSO 2006 by M. Clerc)
- Workload: 4 个合成优化函数（Schaffer, Alpine, Sphere, Rosenbrock）+ 电力系统单元调度问题（unit commitment, 5 generators）
- Metric: 达到停止阈值所需的平均 fitness evaluation 次数；固定 evaluation 数下的平均结果质量
- 统计: 500 次随机初始化 run 的平均；20 次 run 的平均
- 呈现: Table 6.2（平均 evaluations 数）、Table 6.3（结果质量）、Figure 6.4-6.10（收敛曲线）

**结论**: 该文件与 BpfReJIT 评估无关，无法提供 eBPF 领域的方法论参考。

---

## 论文 4: BCF (SOSP'25)

**全称**: "Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement"
**文件**: `19-bcf-prove-it-to-the-kernel.pdf`

### 评估结构

**1. RQ / Evaluation Goals (§6)**

两个核心目标：
1. **Precision（精度）**: BCF 能让 verifier 接受多少之前被错误拒绝的程序？（§6.2）
2. **Overhead（开销）**: 引入 BCF 的时间开销和 proof 开销是多少？（§6.3）

**2. Baselines**

- Linux in-tree verifier（kernel v5.15，最新主线版本），这是主 baseline
- PREVAIL [7, 48]（使用 Zone abstract domain 的 state-of-the-art 验证器）用于对比精度
- 注意：PREVAIL 因 Windows-specific 设计只能加载不到 1% 的程序，实际比较意义有限

**3. Workloads**

- **512 个真实 eBPF 程序**，均是安全但被 verifier 错误拒绝的程序（dataset 精心构建）
- 来源：从 46 个流行 eBPF 用户空间项目（eBPF 官方 application landscape [42]）编译
- 编译方式：106 个 source program × 多个编译器版本（Clang-13 到 Clang-21）× 多个优化级别（-O1 到 -O3）= 共 512 个 unique objects（去重后）
- 覆盖的项目包括 Cilium、Calico 等生产级系统（Table 2 展示了 subset）
- 程序大小：0.5 到 376.2 KiB，去 strip 后平均 118.1 KiB

**4. 主要 Metric**

- **Precision**: 512 个程序中接受数量（and acceptance rate %）
- **Component-wise metrics**（Table 3）:
  - Refinement Frequency（每程序平均触发次数，范围 1-16,048）
  - Symbolic Track Length（指令数，平均 102）
  - Condition Size（字节，平均 836 bytes）
  - Proof Check Time（微秒，平均 49 μs）
  - Proof Size（字节，平均 541 bytes）
- **Total analysis time**: 每程序 0.7-182.0 秒，平均 9.0 秒
- Proof checking 占总时间 < 1%，user space 占 21%
- **Figure 8**: proof size 分布（99.4% < 4096 bytes）

**5. 硬件平台**

- 单一平台：AMD EPYC 9654 96-core server，两线程/核，756 GiB RAM
- Linux v5.15，KVM 虚拟机（QEMU 6.2.0）
- **单一硬件平台**

**6. 统计方法**

- **无重复 run 统计**（分析是确定性的，verifier 是固定的抽象解释算法）
- 展示 min/avg/max（Table 3）
- 程序数量 512 已足够做统计描述
- Figure 8 展示 proof size 的分布（histogram）

**7. 数据呈现方式**

- **Precision 结果**: 文本 + 核心数字（403/512 = 78.7%），按类别分析 109 个仍被拒绝的原因（4 cases 未触发 refinement、82 因 condition 不满足、23 因 million-instruction limit）
- **Table 2**: dataset 中几个典型程序的详情（project、size、LoC、description）
- **Table 3**: component-wise key metrics（min/avg/max）
- **Figure 8**: proof size 分布 histogram
- **Listings 7-9**: 3 个具体的 false rejection 案例（qualitative case study）
- 无 per-program breakdown table（程序太多）

---

## 论文 5: Jitterbug (OSDI'20)

**全称**: "Specification and Verification in the Field: Applying Formal Methods to BPF Just-in-Time Compilers in the Linux Kernel"
**文件**: `01-jitterbug.pdf`

### 评估结构

**1. RQ / Evaluation Goals (§7 Experience)**

Jitterbug 的 "Evaluation" 主要是 **experience report** 而非传统 benchmark：
1. JIT correctness 验证的可行性（per-opcode verification time）
2. 在 real Linux kernel 中发现并修复 bug 的效果
3. 新 JIT 实现（RV32）的开发效率
4. 优化的正确性保证

**2. Baselines**

- **没有传统 performance baseline**
- 比较对象是：bug 是否被现有 BPF selftest suite 发现（多数未被发现）
- 历史上 41 commits 修复的 82 个 correctness bugs 作为"ground truth"

**3. Workloads**

- **6 种 BPF JIT 架构**: RV32、RV64、Arm32、Arm64、x86-32、x86-64
- **Per-opcode 验证**: 每个 BPF 指令 opcode 的翻译正确性
- Bug 发现: 检查 Linux kernel 从 2014 年 5 月到 2020 年 4 月的所有相关 commit
- 新发现 16 个 previously unknown bugs（在 5 个已部署 JIT 中）
- 开发 12 个优化 patch

**4. 主要 Metric**

- **Verification overhead**: per-opcode 验证时间（秒），不是 execution performance
- **Bug detection rate**: 发现的 bugs 数量（16 个）及验证规范能覆盖的比例（82 个中的 80 个）
- **Code size**: JIT 实现代码行数（C 和 DSL 版本，Figure 10-11）
- **Specification effort**: 每架构 specification 的代码行数（Figure 10）

**5. 硬件平台**

- Verification 用机器: Intel Core i7-7700K @4.5 GHz，Boolector 3.2.1 作为 SMT solver（§7）
- **单一硬件平台**（且重点不在 runtime performance）

**6. 统计方法**

- Per-opcode 验证时间：展示 min/max/mean/median（Figure 11 表格）
- **没有 repetitions**（验证是确定性的）
- **没有 confidence interval**
- 用 mean/median 来描述验证时间的分布

**7. 数据呈现方式**

- **Figure 10**: 各组件代码行数（component breakdown table）
- **Figure 11**: 每架构 JIT 的指令数（C/DSL）、specification 大小、per-opcode 验证时间（min/max/mean/median）
- **§A.1.1-A.1.3**: 上游到 Linux kernel 的 patch 列表（Table: commit hash + arch + description）
- **§3.2**: 具体 bug 案例分析（代码片段 + 错误解释）— qualitative
- **无 throughput/latency benchmark**

---

## 对 BpfReJIT 的启示

### 8. 我们的 eval 目前缺什么

对比 K2 和 BCF 这两篇最相关的 BPF 优化/扩展论文，我们的 eval 目前存在以下缺口：

**缺口 1: 没有明确的 RQ 结构**
K2 列出 6 个编号 RQ，BCF 列出 2 个核心目标，每个实验数据都能对应到具体的 claim。我们目前的 eval 是"跑 benchmark 看数字"，缺乏 claim→evidence 的映射。

**缺口 2: Baseline 选取不完整**
K2 的 baseline 是 clang -O1/-O2/-O3/-Os（取最优），涵盖了读者会自然想到的对比对象。我们目前只对比 kernel JIT vs llvmbpf，但缺少：
- 手工优化 BPF 程序作为 upper bound（K2 做了）
- 其他 userspace recompiler（如 ubpf with LLVM optimization）
- "只用 clang -O3 编译"的基准

**缺口 3: Workload 覆盖度不足**
K2 使用 19 个来自 Cilium/Facebook/Linux kernel 的真实 production 程序。BCF 使用 512 个从 46 个项目编译的真实程序。我们的 micro benchmark（62 个合成 case）在多样性上远弱于这些 paper。缺少：
- 真实生产程序中的"自然出现的 JIT 优化机会"分析
- 程序规模分布（小/中/大程序的分类统计）

**缺口 4: 缺乏量化的统计严谨性**
K2 的吞吐量 3 次 trial 取平均，我们用 3 iterations × 100 repeat，但：
- 没有报告 confidence interval（K2 也没有，但 OSDI/SIGCOMM reviewer 现在要求更高）
- 没有 significance test（两组 exec_ns 是否有统计显著差异）
- VM noise 已知存在（见 memory 中的 warning），但没有量化/控制

**缺口 5: Overhead 量化不够细致**
BCF 的 overhead 分析极为详细：refinement frequency、symbolic track length、condition size、proof check time、proof size、total time breakdown（kernel vs userspace %）。我们对 daemon rewrite overhead 的分析（4.32ms scanner、29.89μs syscall）是正确方向，但：
- 没有 per-pass breakdown
- 没有展示 overhead 随程序大小的变化
- 没有展示 overhead 在整个程序生命周期中的摊销分析

**缺口 6: 缺乏定性案例分析**
BCF 有 Listings 7-9（3 个具体 false rejection 案例），K2 有 §9（2 类 discovered optimization examples）。我们目前没有：
- 展示 daemon 发现了哪些"有趣"的优化 case
- 展示具体 BPF 程序优化前后的 assembly 对比

**缺口 7: 多架构缺失**
K2 只有 x86，Jitterbug 支持 6 种架构。我们目前：
- 只在 x86_64 测试
- ARM64 的 kinsn module 实现了（module/arm64/），但没有 eval
- 这是 reviewer 会直接要求的项

### 9. Reviewer 会基于这些标准要求我们什么

基于 K2 (SIGCOMM'21) 和 BCF (SOSP'25) 的标准，针对 OSDI'26 的 reviewer 会问：

**必答问题（不回答直接 reject）**:
1. **"Baseline 不公平"**: 为什么不对比 clang -O3 编译的 BPF？为什么不对比 K2？你的 daemon 比 K2 强在哪？（BpfReJIT 的角度不同，但需要解释）
2. **"Workload 太合成"**: 你的 62 个 micro benchmark 都是手写的合成 case，不代表真实程序。Cilium/Calico/Suricata 这些 corpus 结果在哪？
3. **"VM noise"**: 你用 VM 跑，且承认有 >10% 波动。如何保证结论的统计有效性？
4. **"Overhead 的代价"**: BpfReJIT 引入了 daemon 和新 syscall，这个 overhead 在哪些场景下可接受/不可接受？

**重要加分问题（有则更强）**:
5. **"Multi-architecture"**: x86 结果能代表 ARM64 吗？（你们有 ARM64 kinsn 但没有 eval）
6. **"Applied vs not-applied"**: 你的 overall geomean 1.054x 是 62 个程序的混合，但 applied-only 1.074x 更有说服力。为什么有些程序 daemon 不 apply？
7. **"E2E latency"**: exec time 提升转化为多少 end-to-end application latency？（你有 E2E tracee 结果）
8. **"Code quality metric 多样性"**: 除了 exec time，BPF 程序质量还有 instruction count、I-cache footprint——你们有么？

**可能的 reject 理由（根据这些 paper 的标准）**:
- K2 类 reviewer: "你的 workload 不够真实，62 个合成 case 无法说明 production BPF 的优化收益"
- BCF 类 reviewer: "你的 overhead breakdown 不够细致，不知道瓶颈在哪，是否 scalable"
- Jitterbug 类 reviewer（偏 correctness）: "你的 kinsn 正确性如何保证？rejit syscall 的 safety 模型是什么？"

### 10. 我们应该学哪些做法

**立即可借鉴（高优先级）**:

**A. 从 K2 学 RQ 结构**
在 §Evaluation 开头用编号 RQ 列表，然后每个小节回答一个 RQ。格式：
```
In this section, we answer the following questions:
(1) What is the performance improvement of BpfReJIT over stock kernel JIT?
(2) How does BpfReJIT compare to llvmbpf?
(3) What is the compilation overhead?
(4) Which passes contribute most to the improvement? (ablation)
(5) Does BpfReJIT preserve correctness?
```

**B. 从 K2 学 per-program breakdown table**
K2 的 Table 1 是 19×9 的矩阵，每行一个 benchmark，每列一个 metric。我们的 62 个 benchmark 可以做一个 per-program 的 exec speedup 和 "pass applied" 列（类似 K2 的 compression ratio 列）。这比 geomean 更有说服力。

**C. 从 BCF 学 dataset 构建方法**
BCF 的 512 个程序 = 106 source × 多编译器变体，并且每个程序是"safe but rejected"。我们的 corpus 应该：
- 从 Cilium/Calico/Suricata 的多个版本编译
- 记录每个程序被哪些 pass 优化、优化了多少指令
- 构建 "natural optimization opportunity" 统计（多少 % 的真实程序能被 BpfReJIT 改善）

**D. 从 BCF 学 overhead 分解**
BCF 的 Table 3 有 7 个 metric，每个都有 min/avg/max。我们应该对 daemon 的各阶段计时：
- ELF 解析时间
- 每个 pass 分析时间
- BPF_PROG_GET_ORIGINAL syscall 时间
- BPF_PROG_REJIT syscall 时间
- 总 rewrite 时间
- 重复调用的摊销时间（如果 caching）

**E. 从 K2 学 ablation 设计**
K2 的 Table 4 对等价性检查优化做了消融（逐步关闭 I/II/III/IV，记录 slowdown）。我们应该：
- 每个 pass 单独关闭，测量 speedup 下降
- 报告 "without BpfReJIT" vs "with specific pass" vs "with all passes"

**F. 从 Jitterbug 学 case study 写法**
Jitterbug §3.2 和 §9（K2）的 concrete example：展示具体的 BPF 代码片段优化前后对比，解释为什么 stock JIT 做不到而 BpfReJIT 能做到。这对 OSDI 读者理解贡献非常重要。

**中优先级（加强论文但非 critical）**:

**G. 增加 ARM64 数据**
即使只有 partial 结果（5-10 个 benchmark），也能展示跨架构的 generality。

**H. 统计严谨性**
- 报告每个 benchmark 的标准差或 95% CI
- 对 "BpfReJIT vs stock JIT" 的整体比较做 Wilcoxon signed-rank test，报告 p-value
- 明确 baseline 的测量方法（bare metal vs VM，warm cache vs cold）

**I. 指令数 metric**
除了 exec_ns，报告优化后 BPF bytecode 的指令数变化（类似 K2 的 compression ratio）。这是独立于 CPU 执行速度的 JIT quality metric，更稳健。

---

## 总结表

| 维度 | K2 (SIGCOMM'21) | BCF (SOSP'25) | Jitterbug (OSDI'20) | BpfReJIT 当前状态 |
|------|----------------|---------------|---------------------|-------------------|
| RQ 数量 | 6 个明确 RQ | 2 个核心目标 | Experience report | 无显式 RQ |
| Baseline | clang -O1/2/3/s | Linux in-tree verifier | BPF selftests | kernel JIT + llvmbpf |
| Workload 类型 | 19 真实程序（生产级） | 512 真实程序（46 项目） | 6 架构 JIT per-opcode | 62 合成 micro + corpus |
| 主 Metric | throughput + latency + code size | acceptance rate + overhead breakdown | bug count + verification time | exec_ns speedup |
| 硬件平台数 | 1（x86 CloudLab） | 1（x86 AMD EPYC） | 1（Intel i7，验证用） | 1（x86 VM） |
| 统计严谨性 | 3 trials，无 CI | 确定性，min/avg/max | 确定性，min/max/mean/median | 3 iterations，无 CI |
| 数据呈现 | per-program tables + 分 metric | component breakdown + distribution | patch list + per-opcode table | geomean + per-benchmark |
| Ablation | 4-factor ablation（Table 4）| 3 failure categories | bug category analysis | WideMemPass 等单独分析 |
| Case study | §9 两类优化示例 | Listings 7-9 三个案例 | §3.2 具体 bug 分析 | 无 |
| Multi-arch | 否 | 否 | 是（6 架构） | 否（ARM64 module 未 eval）|

---

*分析者: Claude (subagent)*
*注: 08-merlin.pdf 和 09-epso.pdf 均为下载错误文件，分析基于实际文件内容。建议修复 manifest 并重新下载正确的 ASPLOS'24 Merlin 和 ASE'25 EPSO 论文。*

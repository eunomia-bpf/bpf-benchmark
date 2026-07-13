# 2026 eBPF Grant（eBPF Runtime Optimization）故事组织分析

日期：2026-07-13
输入材料：
- `docs/research/eBPF-Grant---eBPF-runtime-optimization/`（现版 main.tex = 2025 "Extending eBPF for LLM Serving Observability" 提案，$50K/12 个月，PI Andi Quinn + Yusheng Zheng；`old/` 为 PI 更早的 bug-reproduction NSF 素材）
- 仓库四条论文线：
  1. **KOperation**（`docs/paper/`）："Safely Extending the eBPF Compilation Pipeline with Native Operations" — dual-form operation（proof sequence + native emit），Lean 4 证明，7 个硬件习语操作，micro +24% / production +12%，x86-64 + ARM64
  2. **BpfReJIT / Speculative Optimization**（`docs/speculative-optimization/`）："Transparent Speculative Optimization for Deployed eBPF Programs" — shim 拦截 + bpfopt 纯字节码 CLI + stock verifier/JIT，load-time 与 live-swap 两条路径
  3. **NativeBPF**（`docs/kprog-simulator-in-ebpf/`）："Verifying Native Kernel Extensions with an eBPF Simulator" — 用可信 ISA 模拟器把 native 程序特化成 verifier 可分析的 eBPF artifact，安全性条件转移
  4. **bpfoptbench**（`docs/ebpf27-bpfoptbench/`）：Agentic auto-research framework + benchmark，6 个生产应用 / 146 programs / 42 micro，agent 探索最高 +34%
- 基础设施资产：6-app 真实工作负载 corpus、双架构（x86/arm64）、KVM+AWS 全自动 Makefile 入口、噪声底数据（≥100 run_cnt 过滤方法学）

## 〇、论文线深读盘点（2026-07-13 细读补充）

### 1. kop / KOperation（`docs/paper/`）— 成熟度最高，完整论文
- 全部章节齐备：characterization → mechanism（bpfext）→ 7 个习语操作 → Lean 4 证明 → 实现 → 4 个 RQ 的完整评估，双架构真实数字。
- 关键数字：特征化 gap 1.57×（最高 2×）；micro geomean **1.242× (x86) / 1.222× (arm64)**，
  恢复 42% gap；native code size −22.8%/−12.1%；**Cilium 1.074×、Katran 1.073×**（端到端）；
  load-time 内核侧开销 0.99×（无感）。
- RQ3 是政策敏感性反例：coverage-max 反而变差（Cilium 关掉 bulk_memory 1.074→1.114×；
  Katran 21→62 sites 反跌到 0.995×）→ "profitability, not coverage" 结论。
- RQ4 是设计空间上界：whole-program native replacement **Cilium 2.358×**（TCB 换性能），
  kop 在真实 datapath 只恢复该上界的 **5.4%**（micro 上是 42%），原因是真实 datapath
  时间大头在 helpers/maps/tail calls。**这个 5.4% vs 42% 对比是 grant 动机金句。**

### 2. Speculative Optimization / BpfReJIT（`docs/speculative-optimization/`）— 架构完整，主张诚实受限
- 评估章标题就是 "Evaluation Status and Plan"，带 claim ledger：
  - C1（load-time 透明施加）：已支持，六 app 重跑存在
  - C2（运行中替换覆盖率）：机制已实现，无 paper-grade 结果
  - C3（runtime side inputs 价值超过静态策略）：未证明
  - C4（保守策略不回归）：**当前不成立**——branch_flip 7 月 1 日完整跑 0.949（1.054× 加速），
    后续重跑 stitched 1.113（0.899×，44 胜 60 负），Tracee 大幅回归
- 明确的 result gates 和 4 个待回答 RQ（端到端 load-time、side-input 价值、live 覆盖率、
  profitability gating held-out 验证）——**这些就是现成的 grant "open questions"**。

### 3. kprog / NativeBPF（`docs/kprog-simulator-in-ebpf/`）— design/position paper
- 定位精确：非 PCC、非 SFI、非 native→eBPF lowering；verify 的是"模拟器 I 执行 P"的特化
  artifact \checked，运行的是原生 P；安全性是条件转移（模拟器保真 + hash binding 进 TCB）。
- 评估章还是 plan + "native-execution preview artifacts"——而这个 preview 实际就是
  kop RQ4 的 2.358× native replacement 路径。**kprog 正是给 2.358× 上界补上验证故事的
  那篇论文**：kop RQ4 说"native 上界要信任应用代码"，kprog 说"这份信任可以用 stock
  verifier 检查掉"。三篇论文在设计空间上首尾相接。
- 注意：sections/ 里混有 kop 论文章节的陈旧拷贝（3-characterization、4-bpfext 等），
  main.tex 未引用，属于克隆骨架残留。

### 4. bpfoptbench（`docs/ebpf27-bpfoptbench/`）— workshop 体量，已编译出 PDF
- Agentic auto-research framework + benchmark：6 app / 146 programs / 42 micro，
  隐藏正确性检查防作弊，agent 探索最高 +34%，还能定位 crash。
- 双重身份：社区 benchmark deliverable + "AI 帮助探索优化空间"的 2026 方法学钩子。

### 四篇的内在结构（grant 叙事的骨架已经被 kop RQ4 写出来了）
kop 评估原文："places stock eBPF, \tool, and native-in-kernel execution at
**three points in the same design space**"。加上 ReJIT 的时间维度，就是一个二维故事：

```
TCB/机制轴：  stock eBPF ──▶ ReJIT(纯字节码,零内核改动) ──▶ kop(module+Lean证明) ──▶ native+kprog(验证转移)
性能：            1×              递增                       micro+24%,app+7~12%        2.358× 上界
时间轴：      load 前(LLVM) ──▶ load 时(kop/ReJIT load-time) ──▶ deploy 后(ReJIT live, 未完成)
```

## 一、判断：完全可以写，而且比 2025 版更有底气

2025 版（LLM serving observability）本质是"方向提案"：preliminary work 只有 bpftime/eGPU 引用。
2026 版（eBPF runtime optimization）不同——**四条线都已有可引用的系统、数字和 artifact**，
grant 只需要把它们编成一个连贯的研究议程 + 12 个月可交付计划。这是 grant 最舒服的写法：
"we have shown X in preliminary work; funding lets us complete Y and deliver Z to the community"。

对 eBPF Foundation 类 grant（$50K gift、无 overhead、看重生态回馈）尤其匹配：
- 全部工作 stock kernel 可用（shim 无内核改动；kop 只是 kernel module）→ 社区可直接采用
- benchmark suite 本身就是社区级 deliverable（eBPF 至今没有标准优化 benchmark）
- Lean 4 证明贴合 Foundation 近年对 verifier 正确性/形式化方向的兴趣

## 二、核心故事线（推荐）："Closing the Native-Performance Gap of eBPF, Safely"

一句话主张：**eBPF 用户为可验证安全付出最高 2× 的性能税；我们证明这笔税不是必然的，
并按程序生命周期的三个时点系统性地消除它，同时保持最小 TCB。**

统一叙事骨架（安全不变量恒定，性能逐级逼近 native）：

```
                 性能 ────────────────────────────────▶ native
测量基线          load 时             deploy 后            终局
┌────────────┐  ┌──────────────┐  ┌────────────────┐  ┌──────────────┐
│ Thrust 1   │  │ Thrust 2     │  │ Thrust 3       │  │ (展望/stretch)│
│ Benchmark &│  │ KOperation:  │  │ BpfReJIT:      │  │ NativeBPF:   │
│ Gap 特征化  │  │ 安全扩展 ISA  │  │ 负载引导再优化   │  │ native 执行 + │
│ (bpfopt-   │  │ dual-form +  │  │ shim + stock   │  │ 独立验证转移   │
│  bench)    │  │ Lean 4 证明  │  │ verifier/JIT   │  │              │
└────────────┘  └──────────────┘  └────────────────┘  └──────────────┘
   "gap 有多大"     "编译管线缺的指令"   "编译时看不见的事实"    "gap 归零"
```

三个 thrust 各自回答一个 reviewer 会问的问题：
1. **T1（测量/基准）**：gap 到底多大、来自哪里？→ 已有答案：单遍 JIT、硬件习语被拆碎、
   LLVM 缺运行时知识；纯 JIT 对比 0.609×，特征化最高 2×。deliverable = 开源 benchmark suite
   + 持续测量方法学（run_cnt≥100 噪声底、per-program geomean）。
2. **T2（load 时）**：不改内核核心、不膨胀 TCB，怎么把硬件习语还给 eBPF？→ KOperation：
   proof sequence 走现有 verifier，native emit 是唯一 TCB 增量，Lean 4 证明二者等价。
   deliverable = kernel module + 上游 RFC 讨论。
3. **T3（deploy 后）**：map 内容稳定、分支偏置这类"部署后才可见的事实"怎么利用？→
   BpfReJIT：进程内 shim 捕获原始 BPF_PROG_LOAD 上下文，bpfopt 纯字节码变换，候选照走
   stock verifier/JIT；load-time specialization 已验证，live re-specialization 是资助期目标。
4. **展望段（不占 thrust）**：NativeBPF 作为"gap 归零"的终局愿景一段带过——放正文会稀释
   可信度（它还是 design paper），放展望恰好证明议程有纵深。

### 为什么这个组织方式合适
- **三条论文线共用同一个不变量**（"stock verifier 检查一切，TCB 最小"），grant 里这就是
  "coherent research program" 的证据，而不是三个不相干项目的拼盘。
- **时间轴式推进**（load 前 → load 时 → deploy 后 → 终局）天然给出 quarter 划分。
- 与 2025 版观测性 grant 不冲突且有延续性：同一套 "eBPF methodology" 专长
  （bpftime、eGPU 可继续作为 PI/学生 credibility 引用），但问题域从 observability 换到
  performance，避免"重复资助"观感。

## 三、2026 味道：agentic 角度怎么放

bpfoptbench 的 LLM-agent 故事是 2026 年最有辨识度的钩子，但**不建议当主线**：
grant 主张必须落在"eBPF 生态收益"上，AI-for-systems 当主线会把提案变成 ML 提案。
推荐两种放法（二选一）：
- **方法学角色**（保守，推荐）：T1 里说明 benchmark 配套 agentic exploration harness，
  用于系统性搜索优化机会和回归归因（已发现 +34% 案例），是"研究工具"而非研究对象。
- **独立 mini-thrust**（激进）：若 2026 年 Foundation RFP 明确出现 AI/tooling 题目，
  可升级为 Thrust 4 "Automated discovery of optimization passes"，deliverable 是
  agent 发现→人工审核→固化为 bpfopt pass 的流水线。

## 四、Quarter/Deliverable 草案（12 个月，$50K，1 名 RA）

- **Q1**：发布 eBPF 优化 benchmark suite v1（6 app corpus + 42 micro + 方法学文档）；
  完成 gap 特征化报告（对应 T1；材料基本现成，故意放最前保证首季度就有交付）。
- **Q2**：KOperation kernel module + 7 操作 + Lean 4 证明开源发布；提交上游 RFC/邮件列表
  讨论（T2）。
- **Q3**：BpfReJIT shim + bpfopt 开源发布；load-time 路径在 6 个生产应用上的完整评估（T3 前半）。
- **Q4**：live re-specialization（execute_plan + reload/reattach 路径）评估 + phase-change
  实验；年度报告 + NativeBPF 可行性备忘（T3 后半 + 展望）。

## 五、写作时的注意点 / 风险

1. **别把三篇论文的 hedging 带进 grant**。speculative 那篇 abstract 里 branch_flip 回归、
   "open empirical gates" 的诚实措辞是论文美德，grant 里应转写为 "open research questions
   that this funding will resolve"——同一事实，姿态从防守变进攻。
2. **数字口径统一**：不同文档里有 0.609×、2×、24%、12%、34%、1.046×，grant 里每个数字
   出现一次、注明测量对象（micro vs production、pure-JIT vs 端到端），避免 reviewer 交叉
   对不上。ARM64 tail-call poke gap、OTEL panic 这类已知限制不进 grant。
3. **强调 "no kernel modification required"**：这是对 Foundation/社区最有说服力的采纳论据
   （shim 纯 userspace；kop 是 module；NativeBPF 用 stock verifier）。
4. **范围克制**：$50K/12mo 撑不起四个 thrust 全量。NativeBPF 一定降级为展望；若篇幅只有
   2 页（沿用 overview.tex 格式），T1 压缩成 preliminary-work 段落，正文只留 T2/T3 两个 thrust。
5. **格式复用**：直接复用现 repo 的 main.tex/preamble/budget.tex 骨架，overview.tex 换内容；
   budget 文案只需改项目名（结构与金额逻辑不变，按 2026-27 学年费用更新数字）。

## 六、eBPF Foundation Research Fund 实际要求（2026-07-13 核实）

- **2026 周期：6/15 开放，7/15 截止；9/1 公布**；进度汇报 2026-12-01 和 2027-05-01；要求 2 篇 blog post。
- 材料：Project Summary ≤2 页（focus/techniques/prior work/timeline+milestones）+ Budget ≤1 页 + 全员 CV + 机构信息；Google Form 提交；$50K/项，unrestricted gift 付给学校。
- Topics 直接命中我们：Program optimization techniques、In-kernel JIT compiler improvements、
  formal verification of the verifier and JITs、verifier limitations、application efficiency。
- 评审 = eBPF Steering Committee（内核 maintainer）。2024 年 25 份提案资助 5 份；2025 年
  27 份资助 2 份（EPASS/Michigan、eBPF Governors/UCR）。
- **官方页面挂出两份 2025 获奖 proposal 原文**（已存 scratchpad sample1/2.pdf）：结构 =
  编号 section + 动机图/架构图 + Proof-of-concept 数字 + GitHub 链接 + Tasks 1..N +
  按基金会日期排的 Milestones + refs 全部塞进 2 页（约 10-11pt）。
- **EPASS（2025 获奖）与 BpfReJIT 同在 load-time 变换空间**：它做 programmability/safety
  （ISA 内 + 运行时检查），我们做 performance（ISA 之下 native emit + 部署后 workload 事实）。
  Related work 必须主动区分——已写进两版草稿。

## 七、当前文件布局（grant 目录）

- `main.tex / overview.tex / budget.tex / biblio.bib` — 2026 现行版，**格式与 2025 版完全一致**
  （main.tex 除标题外与 2025 逐字节相同；overview 为段落式：PI 头/Introduction/Related Work/
  Research Plan+3 Thrust/Timeline Q1-Q4）。标题 "eBPF Runtime Optimization: Safely Closing
  the Performance Gap to Native Code"。24+1 条真实 bib（含 Kops arXiv:2606.24213、EPASS）。
- `2025/` — 2025 LLM serving observability 版原件四份（未改动）。
- `old/2026-draft-winning-sample-style-overview.tex` — 获奖样例式备选稿（编号 section、
  双图 figs/sec-3-perf-gap-fig.pdf + figs/sec-4-pipeline-fig.pdf、Tasks 1-5、带日期
  Milestones）；启用需 main.tex 配 10pt + margin 0.8in + multicol scriptsize refs。
- 待办：正文 ~3 页 > 2 页上限，需删减；budget 学年数字待 Andi 更新；CV 另备。

## 八、候选标题

- Closing the Native-Performance Gap of eBPF, Safely
- An Optimizing Runtime for eBPF: Verified Native Operations and Workload-Guided Re-Optimization
- Making Verified Kernel Extensions as Fast as Native Code
（第一个最贴 grant 语气：问题即标题，"safely" 点出约束。）

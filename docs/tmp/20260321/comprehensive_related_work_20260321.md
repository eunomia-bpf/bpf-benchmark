# Comprehensive Related Work for BpfReJIT

日期: 2026-03-21

## 0. Executive Summary

这份调研的核心结论只有一句话:

**你们最有力的 thesis 不是“又一个 eBPF compiler framework”，而是“对已部署、正在运行的 live eBPF 程序做 verifier-guarded、post-load、transparent、runtime-guided specialization”。**

沿着这个 thesis，现有相关工作大致分成六类:

1. **加载前/验证前优化**: K2、Merlin、EPSO。
2. **in-kernel compiler framework / pass substrate**: ePass。
3. **userspace 做复杂 reasoning，kernel 保留小 checker**: BCF。
4. **JIT/verifier 正确性与安全性研究**: Jitk、Jitterbug、Prevail、Agni、State Embedding。
5. **动态替换/attach 基础设施与生产系统实践**: `bpf_link_update`、`freplace`、TCX/mprog、Cilium、Tetragon、Tracee、libbpf。
6. **userspace eBPF 运行时**: bpftime、rbpf、uBPF。

把这些工作放在一起看，你们真正的差异不是“做优化”，而是同时满足下面几个条件:

- **post-load**: 面向已经 load+attach 的 live 程序，而不是将要加载的对象。
- **transparent**: 对原应用和原 loader 尽量透明，不要求应用重新编译、重新 attach、或改代码路径。
- **verifier-guarded**: 安全性仍由内核 verifier/JIT 的现有 trust boundary 兜底。
- **userspace correctness / profitability**: 复杂正确性、收益判断、profile 分析放在 userspace/daemon。
- **hot-swap specialization**: 不是只接受更多程序，也不是只做静态优化，而是根据运行时信息替换更优版本。

从 related work 和 upstream 信号看，最需要避免的错误定位有两个:

- **不要主打“minimal extensible compiler framework”**。这会直接撞上 K2/Merlin/ePass/BCF。
- **不要主打“module-defined BPF ISA / kinsn”**。这会直接踩中 upstream 对 ISA 扩展和 verifier 复杂度的敏感点。

更稳健的定位是:

- 论文主线: **transparent online specialization for deployed eBPF**。
- 机制主线: **minimal kernel substrate + privileged daemon + verifier-checked safety + optional certificate/invariant checking for transformation correctness**。
- upstream 友好表述: **优先复用 kfunc / verifier rewrite / JIT lowering / same-prog image swap，而不是扩 public ISA**。

## 0.1 调研方法与来源边界

- 已发表论文优先使用论文 PDF、USENIX/ACM/OpenAccess、作者主页或项目主页。
- 上游 patch/RFC 优先使用 `spinics.net`、LWN、git mirror、docs.kernel.org、docs.ebpf.io。
- 2026-03-21 直接访问 `lore.kernel.org` / patchwork 的若干页面时，部分请求被 anti-bot 机制拦截；因此这里对上游历史的重建主要依赖:
  - 可直接访问的 `spinics.net` 邮件归档；
  - LWN 的 patch report / thread summary；
  - 可搜索到的 commit mirror；
  - 当前内核树与 libbpf 树的源码证据。
- 另外交叉参考了本仓库内已有 reviewer note:
  - `docs/tmp/chatgpt-pro-review-20260321.md`
  - `docs/tmp/bpf_program_replacement_research_20260320.md`
  - `docs/tmp/transparent_replacement_feasibility_20260321.md`
  - `docs/tmp/verifier_extension_research_20260320.md`

## 0.2 先纠正几个题目中的引用

截至 **2026-03-21**，下面几项需要纠正，否则 related work 会一开始就被 reviewer 抓住:

1. **BCF** 的准确题目不是 “Certificate-Backed BPF Verification”。
   准确题目是 **“Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement”**，SOSP 2025。[BCF]

2. **Agni (SIGCOMM'22)** 这条我没有找到对应的 SIGCOMM 2022 论文。
   与 “Agni/specification-based verifier work” 对应的公开论文线更准确地说是:
   - CGO 2022: tnum soundness/optimality。[Agni-CGO22]
   - CAV 2023: verifying the verifier / range analysis verification。[Agni-CAV23]
   - SAS 2025: fixing latent unsound abstract operators。[Agni-SAS25]

3. **Electrode (NSDI'23): Fast BPF compilation** 这一项截至 2026-03-21 未能核实。
   我检索了 USENIX、ACM、OpenAlex 和通用 web index，没有找到一篇与 eBPF 编译/优化直接对应、标题为 “Electrode” 的 NSDI 2023 论文。除非你有 DOI/PDF/作者名，否则它更像是误记或占位符。

4. **Oko (CoNEXT'20)** 也不准确。
   可核实的公开工作是 **“Oko: Extending Open vSwitch with Stateful Filters”**, **SOSR 2018**。[Oko]

5. **ePass 和 EPSO 不是同一个东西**。
   - **EPSO** 是已发表论文: caching-based BPF superoptimizer，ASE 2025。[EPSO]
   - **ePass** 是公开原型/框架线: in-kernel LLVM-like eBPF compiler framework，带 SSA IR、pass runner、IV/PV passes、runtime enforcement；目前我没有找到正式发表的系统论文，主要来源是 GitHub README 与 LPC 2025 slides。[ePass-README] [ePass-LPC]

## 1. 高层 taxonomy

| 类别 | 代表工作 | 主要目标 | 发生时机 | 与 BpfReJIT 的核心差异 |
|---|---|---|---|---|
| pre-load optimizer | K2, Merlin, EPSO | 让待加载程序更小/更快/更易过 verifier | load 前或 verify 前 | 不是 live，不解决已部署程序在线 specialization |
| in-kernel compiler framework | ePass | 在 kernel 内提供 SSA IR + pass substrate + runtime checks | load/verify 附近 | 更像“通用 compiler/pass 平台”，不是“透明在线 specialization” |
| proof-backed acceptance | BCF | 把复杂 reasoning 放到 userspace，kernel 做轻量 proof check | load/verify 时 | 目标是接受 safe-yet-rejected program，不是替换已运行程序 |
| verified JIT / verifier correctness | Jitk, Jitterbug, Prevail, Agni, State Embedding | 保证/检验 JIT 与 verifier 的正确性和 soundness | compile/verify 阶段 | 主要关心 safety/correctness，而不是 runtime optimization |
| dynamic replacement substrate | `bpf_link_update`, `freplace`, TCX/mprog | 在 attach 点替换 program 或函数 | 运行时 | 提供 building blocks，但还不是透明 live optimization framework |
| production program managers | Cilium, Tetragon, Tracee | 由系统所有者管理自己加载的程序 | 运行时 | 是 owner-managed lifecycle，不是对任意第三方 live program 的透明优化 |
| userspace eBPF runtime | bpftime, rbpf, uBPF | 在 userspace 运行 eBPF 或 JIT/AOT | 运行时 | 逃离内核 verifier/JIT/attach 模型，不直接对应你们的问题 |

你们的系统位于一个很窄但很清晰的槽位:

- **对象**: 已 load、已 attach、正在运行的 kernel eBPF 程序。
- **目标**: 在线优化/加固/专用化。
- **边界**: kernel 只继续保证 safety；userspace 负责 correctness/profitability。
- **理想替换语义**: 尽可能保留 program identity / attach / map state / steady-state zero overhead。

## 2. 已发表论文与公开原型

## 2.1 BPF 优化相关

| 工作 | 会议/年份 | 核心方法 | 与我们的关系 | 关键差异 |
|---|---|---|---|---|
| **K2** | SIGCOMM 2021 | 在原生 BPF ISA 内做 synthesis-based superoptimization，并做 equivalence + safety checking | 是最重要的“BPF bytecode 自动优化”基线 | offline/pre-load；关注语义等价搜索；不处理 live program；不透明热替换 |
| **Merlin** | ASPLOS 2024 | customized LLVM passes + bytecode rewriting；IR 优化与 bytecode refinement 结合 | 是最强的 compile-time eBPF optimizer 基线 | 优化发生在 verify 前；仍是 loader/compiler 控制路径，不是 post-load specialization |
| **EPSO** | ASE 2025 | caching-based superoptimizer；离线发现 rewrite rule，再高效复用 | 是 K2 之后最直接的 bytecode 优化对手 | 规则学习 + pre-load 应用；不面向 live program identity、attach transparency、runtime profile |
| **ePass** | 公开原型 / LPC 2025 / GitHub | in-kernel LLVM-like compiler framework；SSA IR；IV/PV passes；可做优化和 runtime enforcement | 与你们最接近的“framework”式原型 | thesis 是 pass substrate / IR framework；不是主打 transparent online specialization |
| **BCF** | SOSP 2025 | proof-guided abstraction refinement；userspace 生成 proof，kernel 做 proof checking | 与“correctness/safety 分离”最接近的概念盟友 | 目标是接受 safe-yet-rejected 程序，不是对 live program 做变换；属于 acceptance 而非 optimization |
| **Electrode** | 未核实 | 未找到可信 BPF 论文条目 | 目前不应作为正式 related work 讨论 | 截至 2026-03-21 无法确认其与 eBPF 编译/优化的对应关系 |

### 2.1.1 K2: 你们必须认真比较的第一篇

K2 的准确题目是 **“Synthesizing Safe and Efficient Kernel Extensions for Packet Processing”**。[K2]

K2 的关键点:

- 目标是 **BPF bytecode superoptimization**，而不是 native backend re-lowering。
- 变换发生在 **加载前**，输出仍是 BPF bytecode。
- 其卖点不是单纯“更快”，而是 **formal correctness + safety**。
- 论文报告:
  - **6% 到 26%** 的代码尺寸减少；
  - **1.36% 到 55.03%** 的平均 packet-processing latency 下降；
  - 等价性检查加速 **6 个数量级**。[K2]

K2 和你们的关系:

- 它是 reviewer 最容易拿来问的 baseline，因为它已经证明 **BPF 本身可以被自动优化**。
- 但它的核心对象是 **待加载 bytecode**，不是 **已部署 live program**。
- 它的核心可信性来自 **semantic equivalence reasoning**；你们如果只说“verifier 保证安全”，那并不能替代 K2 的正确性故事。

精确差异:

- **层次不同**: K2 改 bytecode；你们更像改 live program 的 deployed form。
- **时机不同**: K2 是 pre-load；你们是 post-load。
- **oracle 不同**: K2 依赖等价性检查；你们若不引入 certificate/invariant，只能 claim safety，不够 claim semantic equivalence。
- **目标不同**: K2 不关心 transparent hot-swap、program identity、attach continuity。

K2 的限制，也是你们能赢的地方:

- synthesis/search 成本高，不天然适配在线、频繁、低延迟的 live specialization；
- 工作负载主要是 packet processing/XDP 路径；
- 不利用 live runtime profile 或 deployment-specific invariants。

### 2.1.2 Merlin: 与你们最强的“编译器工程”对手

Merlin 的准确题目是 **“Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness”**，ASPLOS 2024。[Merlin]

Merlin 的关键点:

- 做 **LLVM IR 级优化 + bytecode 级 refinement**；
- 在 **19 个 XDP 程序** 和 **Sysdig/Tetragon/Tracee** 上评估；
- 报告对 K2 的编译速度优势达到 **6 个数量级**；
- 通过 compile-time pass 把 verifier-aware 的 domain knowledge 融入 LLVM/BPF 流水线。[Merlin]

Merlin 和你们的关系:

- 如果你们把自己写成 “another flexible optimizer framework”，Merlin 会直接压上来。
- 如果你们坚持“online transparent specialization of deployed programs”，Merlin 则更像 **前端/加载前 baseline**。

精确差异:

- Merlin 的目标是 **编译器产物**，不是 **运行中实例**。
- Merlin 假设优化发生在 **验证前**；你们要处理的是已经过 verifier、已经 attach 的对象。
- Merlin 不解决 **atomic replacement、program identity continuity、runtime-driven policy**。

Merlin 最值得借鉴的不是机制，而是实验面:

- reviewer 会期待你们至少也覆盖 **XDP/tc** 和 **tracing/security** 两类 workload；
- 如果没有 Cilium/Katran/Tetragon/Tracee/Sysdig 这一层，比较面会显著变弱。

### 2.1.3 EPSO 与 ePass: 必须明确拆开

#### EPSO

EPSO 的准确题目是 **“EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode”**，ASE 2025。[EPSO]

论文的关键量化结果:

- 发现 **795** 条 rewrite rule；
- 代码尺寸减少最高 **68.87%**，平均 **24.37%**；
- 运行时间平均下降 **6.60%**，最高 **19.05%**；
- 评估覆盖 Linux kernel、Cilium、Katran、hXDP、Sysdig、Tetragon、Tracee。[EPSO]

EPSO 和你们的关系:

- 它已经把 “高质量 BPF bytecode rewrite + 比 K2 更实用” 这条线占掉了一大块。
- 如果你们转向“live bytecode rewrite framework”，reviewer 很容易把你们理解成 **online EPSO**。

你们相对 EPSO 的精确差异只能建立在:

- **post-load/live**；
- **透明热替换**；
- **runtime-guided**；
- **kernel verifier 继续做安全边界**；
- **deployment 侧 daemon + kernel module 的 split deployment model**。

#### ePass

ePass 的公开定位是 **“an in-kernel LLVM-like compiler framework for eBPF programs”**。[ePass-README]

从 GitHub README 与 LPC 2025 slides 看，ePass 已经有:

- SSA-based IR；
- lifter / pass runner / code generator；
- IV/PV 两类 pass；
- optimization pass、MSan、loop counter、helper validation、runtime checks；
- LPC slides 声称实现约 **12K lines of C code** 与 **12 个主要 pass**。[ePass-LPC]

ePass 和你们的关系:

- 它是与“framework”叙事最接近的公开原型。
- 如果你们主打 “minimal extensible compiler framework”，ePass 会是 reviewer 的第一反应。
- 如果你们主打 “transparent online specialization of deployed programs”，ePass 则变成一个 **近邻但不同 thesis** 的系统。

精确差异:

- ePass 是 **kernel 内 IR + pass substrate**；
- 你们更应该是 **runtime specialization substrate + hot-swap control plane**；
- ePass 关注 pass flexibility 与 runtime enforcement；
- 你们应关注 **live program discovery、profile-guided admission、transparent replacement、steady-state overhead、rollback**。

一句话总结:

- **EPSO** 更像算法论文。
- **ePass** 更像框架/原型。
- 你们如果定位正确，应该更像 **运行时 specialization 系统**。

### 2.1.4 BCF: 与你们“correctness/safety 分离”最相近的工作

BCF 的准确题目是 **“Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement”**，SOSP 2025。[BCF]

BCF 的核心思想非常重要:

- verifier 不直接做越来越复杂的精确推理；
- 当内核中的抽象不够精确时，把复杂 reasoning 下放到 userspace；
- userspace 返回 **proof**；
- kernel 只保留一个 **cheap proof checker**。

论文报告:

- 对 **512** 个真实 safe-yet-rejected 程序，接受了 **403** 个，即 **78.7%**；
- 平均 proof size **541 bytes**；
- 平均 proof-check 时间 **48.5 microseconds**。[BCF]

BCF 与你们的关系:

- 这是你们“safety 由 kernel 保证，correctness 由 userspace 负责”叙事的最强外部支撑。
- 它证明了 **“offload complex reasoning, keep kernel checking cheap”** 这条 framing 本身是很强的。

但 BCF 和你们仍然不同:

- BCF 解决的是 **acceptance** 问题: 原程序本来安全，但 verifier 不够精确。
- 你们解决的是 **transformation** 问题: 原程序已经 accepted，要生成并切换到新的 specialization。
- BCF 的 proof 证明 “这个程序可以接受”；
- 你们更需要证明 “这个变换在给定 invariant/profile 条件下是正确的，且替换后的程序仍安全”。

这也意味着一个很直接的 reviewer attack:

- 如果你们只写 “userspace 负责 correctness”，会显得太弱；
- 更好的写法是 **pass-specific certificate / cheaply-checkable invariant / refinement proof**。

## 2.2 BPF 验证 / 安全 / 正确性相关

| 工作 | 会议/年份 | 核心方法 | 与我们的关系 | 关键差异 |
|---|---|---|---|---|
| **Jitk** | OSDI 2014 | 基于 Coq + CompCert 的可信 in-kernel interpreter/JIT infrastructure | 是“verified compiler for in-kernel policy execution”的祖先工作 | 关注 verified translation，不是 live specialization |
| **Jitterbug** | OSDI 2020 | 用符号执行/验证技术测试 BPF JIT，并合成验证过的优化 | 与任何会改 JIT backend 的系统都强相关 | 目标是 JIT correctness，不是 runtime transparent optimization |
| **Prevail** | PLDI 2019 | 基于 abstract interpretation 的 eBPF verifier；支持 loops；减少 false positives | 是 verifier 替代设计的重要参照 | 它验证程序，不负责变换 live program |
| **State Embedding** | OSDI 2024 | 用 state embedding 找 verifier logic bugs | 直接提醒你们不能过分扩 verifier TCB | 不是优化系统，而是 verifier bug-finding |
| **Agni: tnum soundness** | CGO 2022 | 形式化验证 tnum 抽象运算的 soundness/optimality | 说明 verifier 组件的形式化基础可以被单独验证 | 聚焦抽象运算 soundness，不涉及在线 specialization |
| **Verifying the Verifier** | CAV 2023 | 检查 Linux eBPF verifier 的 range analysis soundness | 强烈支持“kernel checker 要小且可验证” | 目标是 verifier 自身正确性，不是变换框架 |
| **Fixing Latent Unsound Abstract Operators** | SAS 2025 | 发现并修复 verifier 中依赖共享 refinement 才成立的 latent unsound operators | 再次说明 verifier 复杂度上升有风险 | 仍是 verifier validation，而非 deployment-time specialization |

### 2.2.1 Jitk: “可信 in-kernel policy execution”的早期代表

Jitk 的准确题目是 **“Jitk: A Trustworthy In-Kernel Interpreter Infrastructure”**，OSDI 2014。[Jitk]

Jitk 的贡献:

- 为 in-kernel interpreter/JIT 提供可信编译基础设施；
- 基于 **Coq + CompCert**；
- 论文里演示了 BPF 与 INET-DIAG 两个内核解释器/策略系统。[Jitk]

Jitk 和你们的关系:

- 它告诉 reviewer: “把用户态策略/程序安全地编到内核执行” 不是新话题。
- 但它的焦点是 **translation correctness**，而不是 **live program specialization**。

精确差异:

- Jitk 证明“从高层规则到 native code 的可信翻译”；
- 你们要解决“对已经存在的 deployed eBPF 实例做在线变换和切换”。

### 2.2.2 Jitterbug: 任何触碰 JIT backend 的系统都不能绕开

Jitterbug 的准确题目是 **“Rigorous Engineering for BPF JIT Compilers”**，OSDI 2020。[Jitterbug]

关键结果:

- 实现并验证了 **RV32** BPF JIT；
- 在 5 个已部署 JIT 中发现并修复 **16 个此前未知 bug**；
- 还开发了新的 JIT 优化，并全部 upstreamed。[Jitterbug]

Jitterbug 对你们的意义非常直接:

- 如果你们的系统会触碰 JIT lowering、JIT image swap、backend-specific optimized emission，reviewer 会天然担心 **JIT correctness regression**。
- Jitterbug 的存在意味着 reviewer 可以合理要求:
  - 需要 JIT-level differential testing；
  - 需要对替换前后 machine code 做 validation；
  - 需要 arch-specific correctness evidence。

你们不需要和它“竞争”；但必须承认:

- **你们的系统 novel 点不在 verified JIT**；
- 若论文中修改 JIT backend，只能把 Jitterbug 作为 safety/correctness 风险基线来讨论。

### 2.2.3 Prevail, Agni, State Embedding: 为什么你们应该主动缩小 kernel TCB

#### Prevail

Prevail 的准确题目是 **“Simple and Precise Static Analysis of Untrusted Linux Kernel Extensions”**，PLDI 2019。[Prevail]

关键点:

- alternative eBPF verifier；
- 基于 abstract interpretation；
- 支持 **loops**；
- 减少 Linux verifier 的 false positives；
- polynomial-time oriented design。[Prevail]

与 BpfReJIT 的关系:

- 它证明 verifier 仍有巨大的 precision/engineering 空间；
- 但它的对象始终是“验证输入程序”，不是“替换 live 程序”。

#### State Embedding

State Embedding 的准确题目是 **“Finding Bugs in Linux eBPF Verifier with State Embedding”**，OSDI 2024。[StateEmbedding]

关键结果:

- 在一个月内发现 **15 个此前未知 verifier logic bug**；
- 其中一些可导致 **local privilege escalation**。[StateEmbedding]

这对你们的启示非常明确:

- 不要把论文主贡献建立在“显著扩大 verifier 复杂度”上；
- 不要假设 verifier 是可以随意加大逻辑的稳定平台；
- 更好的方向是 **kernel checker 保持小、userspace reasoning 外移、再加 cheap certificate checking**。

#### Agni / specification-based verifier line

截至 2026-03-21，更准确的 “Agni/specification-based verifier work” 线是:

- **CGO 2022**: **“Sound, Precise, and Fast Abstract Interpretation with Tristate Numbers”**。证明 tnum 加减的 soundness/optimality，并给出更好的 multiplication algorithm；部分结果已进内核。[Agni-CGO22]
- **CAV 2023**: **“Verifying the Verifier: eBPF Range Analysis Verification”**。检查 **16 个内核版本** 的 range analysis soundness，发现旧版本中多处 unsoundness，并证明较新版本 sound。[Agni-CAV23]
- **SAS 2025**: **“Fixing Latent Unsound Abstract Operators in the eBPF Verifier of the Linux Kernel”**。指出若干 abstract operators 仅在依赖共享 refinement 时才“看起来正确”，并推动修复使其在 isolation 下也正确。[Agni-SAS25]

这条线与你们的关系:

- 它系统性地说明了: **verifier 本身并不适合无节制地继续膨胀**；
- 也说明了: **把 kernel 里的 checker 缩到小而稳定** 是有理论与工程支撑的。

这恰好支持你们的最佳定位:

- kernel 负责 safety；
- userspace 负责 transformation-specific reasoning；
- kernel 最好只做小而可验证的 checking。

## 2.3 相关系统: 非 BPF，但思路相近

| 工作 | 会议/年份 | 核心方法 | 与我们的关系 | 关键差异 |
|---|---|---|---|---|
| **BOLT** | CGO 2019 | post-link binary optimization；基于 profile 的 layout / code placement 优化 | 是“部署后再优化”的最像类比 | BOLT 作用于普通 native binary；没有 verifier/safety boundary；不处理 attach/hook identity |
| **AutoFDO / Propeller** | 工业系统 / 2014+ | 采样驱动的 PGO / layout optimization | 提供“runtime profile 驱动优化决策”的直接灵感 | 只优化 binary，非 live kernel extension；无 safety verifier |
| **Dynamo** | ASPLOS 2000 | transparent dynamic optimization system | 是“运行时透明优化”的经典祖先 | 用户态 DBT/optimization，可自由 speculative；与 kernel eBPF 的 trust boundary 完全不同 |
| **Pin** | PLDI 2005 | dynamic binary instrumentation | 类比“运行时插桩/重写” | 目标是 analysis/instrumentation；允许更高开销；不受 verifier 约束 |
| **DynamoRIO** | CGO 2007 | runtime code manipulation for dynamic tools | 类比“通用动态重写 substrate” | 在用户态工作；与 kernel live BPF 的安全模型不同 |
| **HotSpot / C2 / tiered compilation** | 工业系统 / 2012+ | profiling + tiered compilation + deoptimization | 给你们“runtime-guided optimization”叙事提供直觉类比 | JVM 有 deopt、speculation、managed runtime；eBPF 没有同等自由度 |
| **V8 Ignition + TurboFan + Maglev** | 工业系统 / 2017+ / 2023 | JS tiered compilation，baseline 到 optimizing tier | 提供 tiered JIT 和 quick-to-optimize 的类比 | V8 可 aggressive speculation/deopt；eBPF 不行 |
| **GraalVM Truffle** | Onward! 2012 / 工业系统 | self-optimizing AST interpreters | 是“把动态语义外显化后再专用化”的经典例子 | AST interpreter 模型与 BPF bytecode/JIT 模型差异很大 |
| **Wasmtime / Winch + Cranelift** | RFC 2022+ / 工业系统 | baseline compiler + optimizing compiler，走 Wasm tiering | 提供“启动快 vs 运行快”的双 tier 思路 | Wasm runtime 有自己的 sandbox/runtime；不是 kernel verifier 模型 |
| **Wasmer (Singlepass/Cranelift/LLVM)** | 工业系统 | 多编译后端选择 | 提供 multi-backend/runtime adaptability 类比 | 用户态 runtime，不涉及 live kernel hook replacement |
| **livepatch / kpatch / ftrace** | Linux subsystem / 2014+ | 在线打补丁、函数入口重定向、原子切换 | 提供 “kernel live replacement” 的工程先例 | patch 的对象是 kernel text，不是 verifier-checked BPF object； correctness model 完全不同 |

### 2.3.1 这些类比能帮你们什么，不能帮什么

这些非 BPF 系统最有价值的作用，不是证明 novelty，而是帮助你们构建 reviewer 能听懂的坐标系。

它们能帮助的地方:

- **BOLT / AutoFDO / Propeller**: 帮你们解释 “profile-guided deployment-time optimization”。
- **Dynamo / Pin / DynamoRIO**: 帮你们解释 “transparent runtime rewriting/instrumentation”。
- **HotSpot / V8 / Wasm tiering**: 帮你们解释 “baseline first, optimize later, guided by profile”。
- **livepatch / kpatch / ftrace**: 帮你们解释 “原子替换、不中断服务、rollback”。

它们不能替代的地方:

- 它们通常不需要经过 **Linux eBPF verifier/JIT** 这条安全链。
- 它们通常允许 **speculation + deoptimization**；而 eBPF 的 trust boundary 更刚性。
- 它们不需要保留 BPF program identity、map lifetime、attach semantics。

所以正确用法不是说 “我们就是 eBPF 的 BOLT / HotSpot / DynamoRIO”，而是说:

- **我们借鉴了这些系统的 optimization timing 与 deployment philosophy；**
- **但 novelty 在于把这套想法嵌入 verifier-guarded kernel eBPF 世界里。**

## 2.4 其他 eBPF 运行时与系统

| 工作 | 会议/年份 | 核心方法 | 与我们的关系 | 关键差异 |
|---|---|---|---|---|
| **bpftime** | 项目 + OSDI 2025 论文 | userspace eBPF runtime；支持 LLVM JIT/AOT、binary rewriting、运行中注入 | 是最强的 userspace eBPF runtime 参考 | 它绕开内核 attach/verifier/JIT 主路径；不是 kernel live program transformation |
| **rbpf** | 开源项目 | Rust userspace eBPF VM；解释器 + x86_64 JIT + 简单 verifier | 提供 userspace VM/JIT 参照 | 与 kernel live program replacement 无关 |
| **uBPF** | 开源项目 | userspace eBPF VM；assembler/disassembler/interpreter/JIT | 经典 userspace eBPF VM | 不处理 kernel verifier、hook、attach continuity |
| **Oko** | SOSR 2018 | 在 OVS 中支持 stateful filters | 是“BPF-like datapath programmability”的早期系统 | 不是今天 Linux eBPF live specialization 的直接对手 |

### 2.4.1 bpftime: 重要，但不是你们的直接基线

bpftime 的 README 直接把自己定位成 **userspace eBPF runtime**，支持:

- userspace binary rewriting / DBI；
- LLVM JIT / AOT；
- runtime 注入到正在运行的进程；
- 与 kernel eBPF 协同运行。[bpftime]

bpftime 和你们最容易被混淆的地方是:

- 都有“运行时”“不重启”“动态替换/注入”的味道。

但精确差异非常大:

- bpftime 工作在 **userspace runtime**；
- 你们要处理的是 **kernel live eBPF object**；
- bpftime 可以绕开 kernel verifier/JIT/attach 约束；
- 你们不能。

因此 bpftime 更适合作为:

- runtime adaptability 的相邻方向；
- 不是你们的 primary baseline。

## 3. 上游 kernel patches / RFC / 现有内核机制

## 3.1 先说结论

截至 **2026-03-21**，我没有找到以下任何一个已存在的通用机制:

1. **通用 `BPF_PROG_REPLACE` syscall**。
2. **通用 `BPF_PROG_REVERIFY` / post-load bytecode re-verify API**。
3. **通用、透明、保持同一 `struct bpf_prog` identity 的 bytecode-level hot-swap UAPI**。
4. **成熟的 module-defined public BPF ISA extension 机制**。

我找到的，是一系列 **building blocks**:

- `BPF_LINK_UPDATE` 和 link-based replacement；
- `freplace` / `BPF_PROG_TYPE_EXT`；
- TCX/mprog/cgroup mprog；
- kfunc 与针对 kfunc 的 fastcall / inline / verifier rewrite 方向；
- verifier 内部 DCE、scalar tracking、live register metadata 等渐进增强；
- `BPF_MAP_FREEZE`、`BPF_F_RDONLY_PROG`、`BPF_PROG_BIND_MAP` 这类 correctness-enabling primitives。

这套 building blocks 共同说明两件事:

- upstream 接受 **小步、通用 building block**；
- upstream 对 **大跨度 ISA 扩展 / 模块化 verifier / 导出 verifier internals** 非常敏感。

## 3.2 与你们最直接相关的 patch / RFC / 社区信号

| patch / RFC / 机制 | 时间 | 核心内容 | 与我们的关系 | 关键信号 |
|---|---|---|---|---|
| **`bpf_prog` replacement for active `bpf_cgroup_link`** | 2020-03-23 | 为 active cgroup link 提供原子 program replacement | 是 `BPF_LINK_UPDATE` 路线的早期基础 | 社区接受“link 层原子替换”，但对象是新 prog，不是原地改同一 prog 对象 |
| **`BPF_LINK_UPDATE` + link-based replacement** | 2020+ | 原子替换 link 上挂的 program | 是当前最现实的 hot-swap 原语之一 | 覆盖面有限，且改变 program object identity |
| **BPF link support for tc / TCX / mprog** | 2023-07 起 | 为 tc 引入 link-based attach/update/query，并逐步抽象为 mprog infra | 对多程序 attach、replace、ordering 非常关键 | 社区愿意为特定 hook 建多程序/替换基础设施，但不是 generic live optimizer 接口 |
| **Implement mprog API on top of existing cgroup progs (`bpfchainer`)** | 2025-06-06 | 把 cgroup 也纳入 mprog/链式 attach 模型 | 说明 runtime replacement infra 仍在扩展 | 方向是 attach infrastructure 统一化，而不是 generic program re-verify |
| **freplace multiple attach points** | 5.10 / commit `4a1e7c0c63e0` | 让 freplace program 可挂多个 attach point | 说明 freplace 正在增强 | freplace 仍是 BPF-to-BPF function replacement，不是 generic live prog rewrite |
| **tracing program multi-attach / tracing_multi** | 2024-02 / 2025-07 | 扩展 tracing 程序 attach 形态 | 提升 tracing 类的动态组合能力 | 仍不是透明 hot-swap 任意 live program 的通用方案 |
| **Support for kernel module function calls from eBPF (kfunc)** | 2021 | 给 eBPF 开放受 verifier 约束的内核函数接口 | 是“内核暴露 extension points”的主路线 | upstream 更接受 kfunc 这类 surface extension，而不是新 ISA |
| **support `bpf_fastcall` patterns for calls to kfuncs** | 2024-08-22 | 优化 kfunc 调用 lowering/ABI pattern | 证明 verifier/JIT 可以为特定扩展面做后端友好化 | 社区偏好“保留用户态 API，内核内部 rewrite/fastcall”，而不是新 public ISA |
| **Search and add kfuncs in struct_ops prologue/epilogue** | 2024-12-20 | 在 verifier 生成的 prologue/epilogue 中搜索并记录 kfunc | 说明 verifier 已在维护更多 JIT/fixup metadata | verifier 内部元数据可增加，但方向是渐进增强，不是开放式插件化 |
| **Inlining kfuncs into BPF programs** | 2024-11 讨论 / 2025-04 summit 报告 | 探索让特定 kfunc 以内联形式落地 | 与你们“通过新机制引入优化”高度相关 | 社区首先考虑的是 kfunc + internal lowering，而不是公开 ISA 扩展 |
| **64-bit bitops kfunc RFC (`KF_MUST_INLINE`)** | 2026-02-09 | 用户接口仍是 kfunc；verifier 把调用 rewrite 成 internal ALU64 encoding；JIT 直接发 native insn | 这是你们最重要的 upstream precedent 之一 | 清楚表明社区更偏好“kfunc surface + verifier/JIT internal rewrite”，而不是新 public ISA |
| **Improvements for tracking scalars in verifier** | 2024-01-27 | 改进 spilled scalar / narrowing fill / state pruning | 是 verifier const/range reasoning 逐步增强的例子 | 社区接受 verifier precision 增强，但这是 verifier 本身的静态分析，不是 post-load optimizer |
| **use `compute_live_registers()` info in `clean_func_state`** | 2025-09-15 | 重用 `insn_aux_data->live_regs_before` | 说明 verifier 正在积累可复用的 liveness metadata | 这是“轻量元数据” precedent，对你们想要的 aux facts 很有帮助 |
| **Indirect calls in BPF / instruction-set maps** | 2025-04-21 | 引入 instruction-set map 以安全支持间接调用 | 说明 ISA/调用模型仍在演进 | 但这类扩展很谨慎，伴随专门 verifier machinery，不代表开放式 ISA extension 已可接受 |
| **Modular verifier RFC pushback** | 2025-04-21 | 对导出 verifier symbols / modular verifier 的 RFC 明确回绝 | 是你们必须正视的负面信号 | “this patch goes too far” 表明 verifier 不是随意外插的扩展点 |

### 3.2.1 当前最重要的正面 precedent: `kfunc surface + verifier rewrite + JIT lowering`

最值得你们认真吸收的不是 “新 ISA 指令”，而是更像下面这种路线:

- 用户看到的是现有扩展面，比如 **kfunc**；
- verifier/JIT 内部把它 rewrite 成更合适的 internal encoding；
- 后端直接发高效 machine code；
- 如果当前 arch/JIT 不支持，就 reject，而不是静默退化。

2026-02-09 的 **64-bit bitops kfunc RFC** 就是这个模式的教科书例子。[bitops-kfunc-rfc]

它的关键设计:

- 用户 API 仍是 `bpf_clz64()`/`bpf_ctz64()`/`bpf_popcnt64()` 等 **kfunc**；
- verifier 把调用 rewrite 成单条 internal `ALU64` bitops encoding；
- JIT 直接发 native instruction；
- `KF_MUST_INLINE` 保证“不支持就 reject”，避免不可预期 slow fallback。[bitops-kfunc-rfc]

对你们的启示非常强:

- 如果要向 upstream 讲故事，**这条线比 “module-defined public ISA” 合法得多**。
- 也就是说，最现实的路线不是 `kinsn`，而是:
  - 用户或 daemon 触发某种变换；
  - kernel 内部以 verifier-owned metadata 和 JIT-owned lowering 落地；
  - 对外仍尽量保持现有 UAPI 与安全边界。

### 3.2.2 当前最重要的负面 precedent: modular verifier pushback

2025-04-21 的 modular verifier RFC 讨论中，Alexei Starovoitov 的公开回复是:

> “but this patch goes too far.” [modular-verifier-pushback]

这句话的意义非常直接:

- verifier 不是 upstream 愿意开放给外部模块“随便挂逻辑”的通用平台；
- 导出 verifier symbols、在 verifier 边界外插大块逻辑，社区会非常警惕；
- 这也说明你们如果想争取 upstream 相关性，应该把设计压缩成:
  - 小量通用 primitive；
  - verifier-owned metadata；
  - kfunc/attach/JIT rewrite 级别的局部增强；
  - 而不是 “插件化 verifier + 模块化 ISA”。

## 3.3 当前树里“程序替换”到底支持到哪

根据当前本地内核树与已有调研结果，几点结论非常重要:

1. **`BPF_LINK_UPDATE` 不是通用程序替换。**
   当前 in-tree 支持 `update_prog` 的 link type 主要是:
   - `CGROUP`
   - `ITER`
   - `NETNS`
   - `XDP`
   - `TCX`
   - `NETKIT`
   - `SOCKMAP`

2. 当前不支持 `update_prog` 的重要类型包括:
   - `RAW_TRACEPOINT`
   - `TRACING`（`fentry`/`fexit`/`fmod_ret`/`freplace`）
   - `PERF_EVENT`
   - `KPROBE_MULTI`
   - `UPROBE_MULTI`
   - `NETFILTER` 虽有回调，但直接返回 `-EOPNOTSUPP`

3. **`bpf_link_update` 的语义是“link 指向新 prog”**，不是“原地修改同一 `struct bpf_prog`”。
   这意味着:
   - 旧 `prog_fd` / `prog_id` 仍代表旧对象；
   - loader 若观察原程序对象，会发现它不再是 live 的那个；
   - 它对 hook 是透明的，但对 program identity **不是完全透明**。

4. **`freplace` 是 BPF-to-BPF function replacement，不是 generic whole-program replacement。**
   它更像:
   - 通过 trampoline/text poke 把目标 BPF 函数入口跳到另一个 BPF 程序；
   - 支持越来越多 attach 形态；
   - 但它不是“重验证原程序并原地替换 image”的通用通道。

5. **如果你们要求同时满足“完全透明 + 零 steady-state overhead + 不变 program identity + 不改 attach”**，
   那么真正缺失的 primitive 仍然是:

- **same-`struct bpf_prog` re-verify/re-JIT + atomic image swap**。

这也是为什么你们的论文故事里，最像 novel substrate 的，不是 `bpf_link_update` 本身，而是:

- 利用 live introspection 找到 program；
- 生成 specialization；
- 让 kernel 在不破坏 object identity 的前提下重新验证/重 JIT/原子切换 image。

## 3.4 现有 correctness-enabling primitives

这部分非常重要，因为 reviewer 会质疑你们的 const propagation、invariant-based specialization 是否站得住。

### `BPF_MAP_FREEZE`

- 内核 UAPI 明确支持 **`BPF_MAP_FREEZE`**，用于冻结 map 的 syscall-side 修改权限。[syscall-doc]
- 在本地树的 selftest `tools/testing/selftests/bpf/prog_tests/bpf_insn_array.c:347-353` 中，注释直接写着:
  - “**correctness: now freeze the map, the program should load fine**”
- libbpf 也会对 `.rodata` / `.kconfig` internal map 调用 `bpf_map_freeze()`，见 `vendor/linux-framework/tools/lib/bpf/libbpf.c:5260-5262`。

这说明:

- 某些“把 map 看成常量”的 reasoning 在内核里是有 precedent 的；
- 但前提是 **freeze 或等价只读约束**，不是任意 map。

### `BPF_F_RDONLY_PROG`

- UAPI 明确定义了 **`BPF_F_RDONLY_PROG`**，位于 `vendor/linux-framework/include/uapi/linux/bpf.h:1423-1425`。
- 这表示“从 BPF program 侧只能读不能写”，是 program-side immutability 的原语。

这对你们意味着:

- const propagation / partial evaluation 只能建立在足够强的 immutability 条件上；
- **`BPF_MAP_FREEZE` 只冻结 syscall-side 更新，不等于 BPF 程序不能写**；
- 若没有 `BPF_F_RDONLY_PROG` 或等价条件，仅凭 freeze 不足以把 map 当纯常量。

### `BPF_PROG_BIND_MAP`

- `BPF_PROG_BIND_MAP` 的 UAPI 描述是 “**Bind a map to the lifetime of an eBPF program**”，见 `vendor/linux-framework/include/uapi/linux/bpf.h:873-886`。
- 这提供了一种把 metadata map 生命周期绑定到 prog 的方式。

它对你们的意义:

- 可以作为 program-specific metadata / certificate / specialization state 的绑定原语；
- 但它不是 hot-swap 本身。

## 4. 开源项目与现有工程实践

## 4.1 生产系统到底怎么管理 BPF 程序

| 项目 | 年份/形态 | 核心做法 | 与我们的关系 | 关键差异 |
|---|---|---|---|---|
| **Cilium** | 活跃开源项目 | 用 pinned links、`link.Update()`、旧 `PROG_ATTACH` 兼容升级，管理自家 cgroup/XDP/tc 程序 | 是最接近“生产环境热替换 BPF program”的工程实践 | 它只管理自己加载的程序，不是对任意第三方 live program 的透明优化 |
| **Tetragon** | 活跃开源项目 | 以 sensor/policy 为单位动态加载、启停、串行化管理 BPF 程序与 maps | 证明 security observability 系统会动态管理大量 BPF 程序 | 仍是 owner-managed lifecycle，不是 transparent specialization |
| **Tracee** | 活跃开源项目 | 统一 object load、map init、probe attach、tailcall 管理 | 证明 tracing/security 系统确实有复杂的 BPF control plane | Tracee 自己的文档明确假设“已加载字节码不可被修改”，只承认管理性 detachment/unload |
| **bpftool** | 官方工具 | introspection、dump xlated/JITed insns、profile、对象查询 | 是 live enumerate / introspection 的重要来源 | 只观测不变换 |
| **libbpf** | 官方库 | skeleton、link update、freplace、rodata freeze、BPF feature probing | 是 BPF 程序生命周期操作的主 API | 提供 building blocks，不提供 transparent optimizer |
| **libxdp / xdp-tools** | 开源项目 | 用 dispatcher + freplace 做 XDP multiprog 组合 | 是 freplace 在实际工程中的强先例 | 目标是 XDP multiprog management，不是 arbitrary live optimization |
| **ePass GitHub** | 公开原型 | in-kernel LLVM-like pass framework | 是“optimizer/tooling on GitHub”的重要例子 | 更像 pass substrate，不是 live transparent specialization |
| **llvmbpf** | 开源工具 | userspace LLVM JIT/AOT for eBPF | 是“BPF optimization tools on GitHub”的另一个例子 | 工作在 userspace VM/runtime，非 kernel live program |

### 4.1.1 Cilium: 最强的“热替换”工程先例之一，但不等于你们

在本地抓取的 Cilium 源码 `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go` 中，开头注释写得非常直白:

- `bpf_link` 可用于 fresh install；
- 在升级时，`link.Update()` 可以 **atomically replace the currently running bpf program**；
- 但为了兼容和避免连接中断，某些升级路径仍会继续使用旧 `PROG_ATTACH` API。

对应位置:

- `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go:4-19`
- `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go:69-79`
- `/tmp/cilium-src-191417/pkg/socketlb/cgroup.go:148-159`

这说明两件事:

1. production 系统已经在用 **BPF 程序热替换**。
2. 但热替换是 **系统作者管理自己加载的程序**，不是“透明优化任意 live program”。

另外，Cilium 还显式处理了 pinned maps 与 `BPF_F_RDONLY_PROG` 升级兼容，见:

- `/tmp/cilium-src-191417/pkg/bpf/collection.go:176-181`
- `/tmp/cilium-src-191417/pkg/bpf/collection.go:218-223`

这与 reviewer note 提到的 map immutability / upgrade compatibility 高度一致。

### 4.1.2 Tetragon: 说明 tracing/security 栈会做动态 program lifecycle 管理

Tetragon 的源码显示:

- `StartSensorManager` 的注释明确说，目的是 **serialize loading and unloading of sensors**；
  - `/tmp/tetragon-src/pkg/sensors/manager.go:26-31`
- `Program` 结构里直接有:
  - `Link`
  - `Prog`
  - `RewriteProg`
  - `LoadedMapsInfo`
  - `/tmp/tetragon-src/pkg/sensors/program/program.go:170-183`

这说明:

- Tetragon 并不是“静态 load 一次就不动”；
- 它本质上有一个 owner-managed、policy-driven 的 BPF lifecycle manager。

但它仍然不是你们:

- 它管理的是 **自己拥有的 sensor/policy**；
- 不做 transparent specialization of arbitrary live programs；
- 不追求 generic post-load optimization substrate。

### 4.1.3 Tracee: 有复杂 control plane，但自身文档反而支持你们的“透明优化难点”

Tracee 的 security model 文档明确写道:

- “**The eBPF bytecode itself cannot be modified once loaded and verified**”
- 但 root 用户可以通过 detaching program、killing process、accessing maps 等管理性方式禁用监控。
  - `/tmp/tracee-src/docs/docs/security-model.md:40-45`

同时，Tracee 的加载流程也显示出完整 control plane:

- `initBPFProbes()` 打开 object；
  - `/tmp/tracee-src/pkg/ebpf/tracee.go:1673-1697`
- `initBPF()` 调用 `BPFLoadObject()`、初始化 maps/perf buffers、再 `attachProbes()`；
  - `/tmp/tracee-src/pkg/ebpf/tracee.go:1700-1815`
- `ProbeGroup` 用 mutex 串行 attach/detach；
  - `/tmp/tracee-src/pkg/ebpf/probes/probe_group.go:61-72`
  - `/tmp/tracee-src/pkg/ebpf/probes/probe_group.go:127-178`

这说明:

- tracing/security 栈确实有复杂的 BPF control plane；
- 但它们通常把“已加载字节码不可修改”当成系统假设；
- 因此你们若能提供 **透明 live specialization**，差异就很清楚。

## 4.2 现有工具能给你们什么

### `bpftool`

`bpftool` 的官方 README 直接说明:

- authoritative source 在 `bpf-next` 的 `tools/bpf/bpftool`；
- 支持 profiling；
- 若带 `libbfd`，可 dump JITed instructions。[bpftool]

对你们最重要的是:

- `prog show` / `prog dump xlated` / `prog dump jited` / `prog profile`；
- 它可以作为 live enumerate、JIT image 观察、profile 输入的现成工具。

### `libbpf`

`libbpf` 已经提供了若干与你们系统直接相关的 building blocks:

- skeleton + internal map freeze；
- `bpf_link__update_program()` / `BPF_LINK_UPDATE`；
- `BPF_PROG_TYPE_EXT` / freplace；
- feature probing。

但 `libbpf` 只是控制面 API，不是 transparent optimizer。

### “GitHub 上的 BPF optimization tools”

截至 2026-03-21，我认为可以严肃提到的主要是:

- **OrderLab/ePass**: in-kernel LLVM-like pass framework。[ePass-README]
- **eunomia-bpf/llvmbpf**: userspace LLVM JIT/AOT compiler for eBPF。
- **eunomia-bpf/bpftime**: userspace eBPF runtime，含 LLVM JIT/AOT。[bpftime]

反过来，**我没有发现一个成熟的开源项目已经把“对 arbitrary live kernel eBPF program 做 transparent online specialization”做成通用框架**。这恰恰是你们最有价值的空白点。

## 5. 与所有主要工作相比，你们的 precise 差异是什么

## 5.1 按类归纳的精确差异

| 现有工作线 | 他们做什么 | 你们的 precise delta |
|---|---|---|
| K2 / Merlin / EPSO | 优化 **待加载** 的 BPF/IR/bytecode | 你们优化 **已加载、已 attach、正在运行** 的实例 |
| ePass | 提供 **in-kernel IR + pass framework** | 你们应提供 **minimal runtime specialization substrate**，不是通用 compiler 平台 |
| BCF | 让 safe-yet-rejected program 通过 verifier | 你们让 already-safe program 在运行后期切换到更优 specialization |
| Jitk / Jitterbug | 保证/验证 JIT 或翻译 correctness | 你们的 novelty 不在 verified compilation，而在 online specialization |
| Prevail / Agni / State Embedding | 改进或验证 verifier precision/soundness | 你们不该主打扩 verifier；相反应利用这些工作证明应把 kernel checker 保持小 |
| `bpf_link_update` / `freplace` / mprog | 提供 runtime replacement building blocks | 你们把这些 building blocks 组织成 **transparent, runtime-guided specialization system** |
| Cilium / Tetragon / Tracee | 管理 **自己拥有** 的 BPF 程序生命周期 | 你们目标是对 **任意 live BPF program** 做透明优化 |
| bpftime / rbpf / uBPF | 在 userspace 跑 eBPF | 你们工作在 kernel eBPF 原生语义、verifier、attach 约束之内 |
| BOLT / AutoFDO / HotSpot / V8 / Wasm tiering | profile 驱动、部署后或运行时优化 | 你们把这类思路带进 **verifier-guarded kernel extension world** |

## 5.2 更细一点: 逐项比较时该怎么说

### 相对 K2

- 我们不是再做一个更快的 superoptimizer。
- K2 的核心贡献是 **semantic equivalence-guided bytecode search**。
- 我们的核心贡献应是 **对 deployed live eBPF 的 transparent specialization substrate**。
- 若没有 certificate/invariant，我们不能 claim 像 K2 一样的 semantic equivalence，只能 claim safety + transformation-specific correctness protocol。

### 相对 Merlin

- Merlin 改的是 compiler pipeline；我们改的是 deployment/runtime phase。
- Merlin 不解决 live program discovery、atomic swap、identity transparency、rollback。
- 我们的优势维度应是 **时机** 与 **透明性**，不是“pass 数量更多”。

### 相对 EPSO

- EPSO 是 rule-learning superoptimizer；我们不是新规则库，而是新 **runtime deployment model**。
- 如果论文实现层面也做 bytecode rewrite，必须强调:
  - 我们的核心不是 rewrite algorithm；
  - 而是 **post-load + transparent + verifier-guarded**。

### 相对 ePass

- ePass 是 general in-kernel pass framework；
- 我们应避免变成 “another in-kernel pass framework”；
- 我们最强的版本应是:
  - kernel side 很小；
  - userspace daemon 做发现、分析、收益判断、certificate/invariant 生成；
  - kernel 只负责 safety 与小检查器。

### 相对 BCF

- BCF 接近你们的 trust split，但对象不同。
- BCF 处理 “should this program be accepted?”；
- 我们处理 “should this live program be specialized and replaced now?”。
- 最好的姿势不是把自己和 BCF 对立，而是说:
  - **BCF 是 acceptance 侧的同构思想；**
  - **我们是 optimization/replacement 侧的延伸。**

### 相对 Jitk / Jitterbug / Agni / State Embedding

- 这些工作告诉 reviewer: correctness/soundness 很难，不能轻易扩 kernel TCB。
- 所以我们不应 claim “更复杂的 verifier/plugin framework”。
- 正确 claim 应是:
  - **我们把 correctness 和 safety 刻意分离；**
  - **把大部分复杂 reasoning 保持在 userspace；**
  - **kernel checker 尽量小、尽量稳定、尽量容易验证。**

### 相对 Cilium / Tetragon / Tracee

- 这些系统已经在做 owner-managed reload/update/attach orchestration；
- 我们要解决的是 **第三方 live program 的透明优化**；
- 这是系统边界与 generality 的差异，不只是工程细节。

## 6. 哪些 reviewer 攻击最可能出现，怎么回应

| 最可能的 reviewer 攻击 | 最好的回应 |
|---|---|
| **“这不就是 online K2 / Merlin / EPSO 吗？”** | 不是。那些工作优化的是待加载程序；我们优化的是已部署 live program，关键难点在 transparent discovery、runtime policy、atomic replacement、identity/attach continuity。 |
| **“这不就是 ePass + daemon 吗？”** | 不是。ePass 的主轴是 in-kernel IR/pass framework；我们的主轴应是 minimal kernel substrate + userspace optimizer + transparent specialization。我们不追求 general compiler framework。 |
| **“BCF 已经把复杂 reasoning 下放到 userspace 了。”** | 对，这正是我们应该主动借力的思想。但 BCF 解决 acceptance；我们解决 transformation and replacement。最好把自己的 correctness story 升级为 pass-specific certificate / cheaply-checkable invariant。 |
| **“verifier 只能保证 safety，不能保证语义等价。”** | 完全同意，而且要主动写出来。kernel 保证 memory/control-flow/resource safety；userspace/certificate 负责 transformation correctness。不要混淆 safety 与 semantic equivalence。 |
| **“ISA extension / kinsn 不会上游。”** | 大概率不会。应该主动收缩 claim: 论文可以探索这个 design point，但更现实的 upstream-aligned 路线是 kfunc surface + verifier/JIT internal rewrite 或 same-prog re-JIT primitive。 |
| **“透明热替换并不存在，`bpf_link_update` 已经够了。”** | `bpf_link_update` 只能替换 link 所指向的新 prog，对 program identity 不是完全透明，且覆盖 attach type 有限。真正的透明 replacement 仍缺 same-`struct bpf_prog` re-JIT/image swap primitive。 |
| **“const propagation / invariant specialization 对 map 可变性不成立。”** | 只有在 `BPF_MAP_FREEZE`、`BPF_F_RDONLY_PROG`、rodata/kconfig map 或其他足够强的 immutability 条件下才成立。没有这些条件就不要 claim。 |
| **“生产系统已经会热更新 BPF 程序，Cilium/Tetragon/Tracee 已经做了。”** | 它们是 owner-managed lifecycle systems，只替换自己控制的程序，不透明，也不对 arbitrary live program 做在线 specialization。 |
| **“没有 deoptimization，runtime-guided optimization 说服力不够。”** | kernel eBPF 的 trust boundary本来就不允许像 JVM/V8 那样 aggressive speculation + deopt。我们的合理模型是 bounded variants + canary + rollback，而不是 fully speculative tiering。 |
| **“你们做的是机制，不是系统。”** | 需要在论文里证明完整 control loop: live enumerate -> profile -> select invariant/certificate -> reverify/re-JIT/hot-swap -> observe -> rollback/refine。没有这条闭环，确实会被打成机制论文。 |

## 7. 我建议你们怎么定位

## 7.1 论文一句话定位

最建议的一句话:

**BpfReJIT is a verifier-guarded framework for transparent, post-load, runtime-guided specialization of deployed eBPF programs.**

如果要再强调你们最独特的 split:

**Safety stays in-kernel; correctness and profitability reasoning live in userspace.**

## 7.2 不要怎么定位

下面这些说法都不利:

- “a minimal extensible compiler framework for BPF”
- “an LLVM-like in-kernel optimization framework”
- “a new modular verifier/compiler substrate”
- “a new BPF ISA extension mechanism”

这些说法都会把你们推到 K2 / Merlin / ePass / verifier complexity / upstream rejection 的火力线上。

## 7.3 应该和谁比

### 必做实验比较对象

1. **kernel baseline**
   - 原始 live program，不做 specialization。

2. **Merlin**
   - 最现实的 compile-time optimizer baseline。

3. **K2 或 EPSO**
   - 至少选其一证明 “offline/pre-load optimizer != online specialization”。
   - 如果能同时做，最好。

4. **Cilium/Tetragon/Tracee 风格 owner-managed update**
   - 不是性能基线，而是 deployability / transparency 基线。

### 主要用于概念比较，而不是性能 baseline

1. **ePass**
   - 解释 thesis 差异。

2. **BCF**
   - 解释 trust split / certificate story。

3. **Jitterbug / Agni / State Embedding**
   - 解释为什么 kernel side checker 要小。

## 7.4 你们应该在哪些维度上赢

最值得主打的 winning dimensions:

1. **时机**
   - 我们能优化已经部署、已经 attach、已经在跑的程序。

2. **透明性**
   - 应用不需要重新编译；
   - 最好不需要重新 attach；
   - 最好不改变 program identity。

3. **runtime-guided**
   - 基于真实 workload/profile/invariants，而不是静态对象文件。

4. **安全边界清晰**
   - kernel 继续负责 safety；
   - correctness/profitability 在 userspace；
   - 可选 certificate/invariant checking。

5. **steady-state cost**
   - 替换后没有常驻 trampoline/DBI 级 overhead；
   - 至少要显著优于 userspace DBI 类方法。

6. **rollback / operationality**
   - hot-swap latency；
   - rollback latency；
   - failure isolation。

## 7.5 最稳的论文故事

如果让我替你们收束成一个最稳的 OSDI/SOSP 风格故事，会是这样:

1. eBPF 今天已经是生产系统里的可编程内核扩展层。
2. 但它基本仍然是“一次加载、静态执行”的模型。
3. K2/Merlin/EPSO 证明了 BPF 可以被优化，但它们都在加载前。
4. Cilium/Tetragon/Tracee 证明生产系统需要 runtime lifecycle 管理，但它们只管理自己拥有的程序。
5. BCF 证明了复杂 reasoning 可以放到 userspace，kernel 保留小 checker。
6. 我们把这些点接起来，提出:
   - live enumerate；
   - runtime-guided specialization selection；
   - verifier-guarded replacement；
   - transparent deployment；
   - correctness/safety split。

换句话说，你们的贡献不应被写成:

- “another optimizer”
- “another pass framework”
- “another verifier extension”

而应写成:

- **“turning deployed eBPF from one-shot static compilation into a transparent online specialization environment without abandoning the existing verifier/JIT trust boundary.”**

## 8. 最后给一个简短判断

从 currently available related work 看:

- **最像你们的“算法对手”**: K2、Merlin、EPSO。
- **最像你们的“框架对手”**: ePass。
- **最像你们的“理念盟友”**: BCF。
- **最像你们的“工程先例”**: `bpf_link_update`、TCX/mprog、freplace、Cilium。
- **最像你们的“风险提醒”**: Jitterbug、Agni、State Embedding、modular verifier pushback。

真正决定你们能否站稳的，不是再多加几个优化 pass，而是三件事:

1. **把 thesis 锁死在 online + transparent + post-load + verifier-guarded specialization。**
2. **把 correctness/safety split 讲成 certificate/invariant story，而不是“userspace 尽量保证正确”。**
3. **把 upstream 故事从 `kinsn` 收缩到更现实的 building blocks。**

## 9. Sources

### 论文与公开材料

[K2]: https://arxiv.org/pdf/2103.00022.pdf
[Merlin]: https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf
[EPSO]: https://arxiv.org/pdf/2511.15589.pdf
[BCF]: https://haosun.info/assets/pdf/BCF.pdf
[Jitk]: https://www.usenix.org/conference/osdi14/technical-sessions/presentation/wang_xi
[Jitterbug]: https://www.usenix.org/system/files/osdi20-nelson.pdf
[StateEmbedding]: https://www.usenix.org/system/files/osdi24-sun-hao.pdf
[Prevail]: https://vbpf.github.io/assets/prevail-paper.pdf
[Agni-CGO22]: https://arxiv.org/pdf/2112.14579.pdf
[Agni-CAV23]: https://link.springer.com/content/pdf/10.1007/978-3-031-37709-9_20.pdf
[Agni-SAS25]: https://people.cs.rutgers.edu/~santosh.nagarakatte/papers/agni-sas-2025.pdf
[ePass-README]: https://github.com/OrderLab/ePass
[ePass-LPC]: https://lpc.events/event/19/contributions/2179/attachments/1829/3927/main.pdf
[Oko]: https://dl.acm.org/doi/10.1145/3185467.3185496

### 上游机制 / 文档 / 邮件线程

[kernel-QA]: https://docs.kernel.org/bpf/bpf_design_QA.html
[syscall-doc]: https://docs.kernel.org/userspace-api/ebpf/syscall.html
[kfunc-doc]: https://docs.kernel.org/bpf/kfuncs.html
[tc-bpf-link]: https://lwn.net/Articles/937650/
[mprog-cgroup]: https://lwn.net/ml/netdev/20250606152748.79214-1-hffilwlqm@gmail.com/
[fastcall-kfunc]: https://www.spinics.net/lists/bpf/msg124099.html
[structops-kfunc]: https://www.spinics.net/lists/netdev/msg1055058.html
[kfunc-inline]: https://lwn.net/Articles/974709/
[bitops-kfunc-rfc]: https://lwn.net/Articles/1058015/
[scalar-tracking]: https://lwn.net/Articles/959903/
[live-regs-before]: https://www.spinics.net/lists/bpf/msg152224.html
[indirect-calls]: https://lwn.net/Articles/1017439/
[modular-verifier-pushback]: https://www.spinics.net/lists/bpf/msg142433.html

### 开源项目

[bpftime]: https://github.com/eunomia-bpf/bpftime
[rbpf]: https://github.com/qmonnet/rbpf
[uBPF]: https://github.com/iovisor/ubpf
[bpftool]: https://github.com/libbpf/bpftool
[llvmbpf]: https://github.com/eunomia-bpf/llvmbpf

### 非 BPF 相关系统参考

[BOLT-paper]: https://arxiv.org/abs/1807.06735
[Dynamo]: https://dl.acm.org/doi/10.1145/378993.379232
[Pin]: https://dl.acm.org/doi/10.1145/1065010.1065034
[DynamoRIO]: https://dl.acm.org/doi/10.1145/1250734.1250746
[HotSpot]: https://docs.oracle.com/en/java/javase/22/vm/java-hotspot-virtual-machine-performance-enhancements.html
[V8-Ignition-TurboFan]: https://v8.dev/docs/ignition
[V8-Maglev]: https://v8.dev/blog/maglev
[Truffle]: https://dl.acm.org/doi/10.1145/2384577.2384587
[Wasmtime-Winch]: https://raw.githubusercontent.com/bytecodealliance/rfcs/main/accepted/wasmtime-baseline-compilation.md
[Wasmer]: https://docs.wasmer.io/runtime/
[livepatch-doc]: https://docs.kernel.org/livepatch/livepatch.html
[kpatch]: https://github.com/dynup/kpatch

## 10. 关于未能完全核实的条目

按照 2026-03-21 的检索结果，唯一无法作为“已核实 published work”写入正表的，是你题目里给出的 **Electrode (NSDI'23): Fast BPF compilation**。

我做了什么:

- 查了 USENIX、ACM、作者/论文索引、通用 web index。
- 查了与 eBPF compilation / fast BPF / Electrode 相关的组合关键词。

我找到什么:

- 没有找到与 eBPF 编译/优化直接对应、标题为 “Electrode” 的 NSDI 2023 论文。

为什么还不够:

- 没有 DOI、PDF、作者名或公开系统主页能把 “Electrode” 与 eBPF fast compilation 这条线可靠对应起来。

如果你手头有这项工作的 DOI、PDF、作者列表或另一个标题别名，我建议在下一轮把它补进来；否则在正式 paper 里最好不要把它当作已核实 related work。

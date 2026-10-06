# Related Work 系统性文献整理 + 对比分析（2026-03-24）

本报告在阅读 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md) §1.8 与 §1.9 后撰写，目标是为论文 related work section 提供一份可以直接引用、裁剪、重组的底稿。核心 framing 采用 plan 中已经明确的四个维度：

- `pre-load` vs `post-load`
- 静态编译期优化 vs 动态运行期优化
- 需要原始 `.bpf.o`/源码 vs 对已加载 live program 完全透明
- pass 正确性/额外 proof vs 直接复用 kernel verifier 安全模型

## 1. Executive Summary

结论先行：

- 现有 **直接 BPF 优化工作**，主线仍然是 `pre-load + userspace + 需要 .bpf.o`。K2、Merlin、EPSO 都属于这一类。它们优化的是“待加载对象文件”，不是“已经加载、正在运行的 live BPF 程序”。
- **ePass** 是目前最接近 “kernel 内 pass 基础设施” 的工作，但它仍然是 `load/verify time` 路径，且把较多优化逻辑放进 kernel；这与 BpfReJIT “kernel 只提供最小机制，复杂策略留在 userspace daemon” 的路线明显不同。
- **BCF / VEP / PREVAIL / Agni / Jitterbug / Jitk** 等工作主要回答“怎样更强、更 sound、更精确、更可验证地接受或执行 BPF”，而不是“怎样透明地对 live BPF 进行 post-load 优化”。
- **bpftime / llvmbpf / uXDP / hXDP / eHDL / hBPF / femto-containers** 这条线的共同点是“换执行环境”：把 BPF 搬到 userspace、FPGA、IoT VM、或新硬件上。它们带来不同的性能/隔离/可移植性 tradeoff，但并不保持 stock Linux kernel eBPF 的透明部署模型。
- 通用 **HotSpot / V8 / Graal / LLVM ORC / Wasm runtime** 提供了非常强的类比：`runtime profile-guided specialization`、`tiered compilation`、`deoptimization`、`lazy/eager JIT`。BpfReJIT 的 novel 点不在于“发明 JIT”本身，而在于把这类 runtime compilation 思想带入 **内核 eBPF live program**，同时复用 verifier 作为安全根。

一句话归纳 BpfReJIT 的定位：

> BpfReJIT 不是又一个 pre-load eBPF optimizer，也不是替代 verifier 的新验证器，更不是把 BPF 搬到 userspace/FPGA 的新 runtime；它是一个 **post-load, transparent, verifier-guarded, kernel-resident live re-JIT framework**。

## 2. 调研方法与来源策略

- **本地上下文**：先读 [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md) §1.8/§1.9，锁定论文需要强调的比较轴。
- **检索范围**：OSDI/SOSP/SIGCOMM/ASPLOS/NSDI/ATC/PLDI/RAID/CAV/USENIX Security，外加 LPC、eBPF workshop、FOSDEM eBPF devroom、官方项目文档。
- **关键词**：`eBPF optimization`、`BPF JIT optimization`、`eBPF compiler`、`BPF program transformation`、`eBPF verifier`、`eBPF runtime`、`eBPF hardware`、`eBPF workshop` 等。
- **来源优先级**：优先 peer-reviewed 正式论文，其次官方 workshop/LPC 材料，其次项目官方 repo / 官方文档 / 作者主页。
- **版本说明**：
  - **EPSO** 存在数字差异。`2025-11-19` 的 arXiv preprint 报告 `795` 条 rewrite rules、平均 `24.37%` 代码尺寸下降；ASE 页面/二级摘要常见 `624` 条 rules、平均 `20.01%`。本报告以 `2025-11-19` arXiv preprint 为主，并在需要时注明差异。
  - **ePass** 的性能数字主要来自 eBPF Foundation grant 新闻页与 LPC 材料的组合。LPC PDF 偏设计性，eBPF Foundation 页给出 `<2%` overhead、`91%` previously rejected safe programs resolved 等更具体数字。
- **证据强弱**：
  - `强`：正式论文、会议开放 PDF、USENIX/ACM 官方页面。
  - `中`：LPC/eBPF workshop/full paper、作者主页、项目官方 repo。
  - `弱但有用`：基金会项目页、官方文档、官方 talk 页面。此类主要用于补齐“代码是否开源”“最新项目状态”“非归档系统”的事实。

## 3. A 类：BPF 程序优化与直接竞品

### 3.1 K2

- **基本信息**：Qiongwen Xu, Michael D. Wong, Tanvi Wagle, Srinivas Narayana, Anirudh Sivaraman, “Synthesizing Safe and Efficient Kernel Extensions for Packet Processing,” SIGCOMM 2021.
- **核心方法**：K2 从现有 BPF object 出发，对 hot basic block / instruction slice 做 stochastic superoptimization，并用 SMT 检查等价性与安全性，目标是在不破坏 verifier 可接受性的前提下缩小程序、降低延迟。
- **关键技术**：stochastic search、cost-guided superoptimization、SMT-based equivalence and safety checking、针对 BPF verifier 约束的 transformation validity 过滤。
- **性能数据**：论文报告 `6%–26%` code-size reduction、`1.36%–55.03%` 平均 packet latency 降低、`0%–4.75%` throughput 提升。
- **限制**：
  - 明确是 **pre-load** 工具链，输入是 `.bpf.o`。
  - 不透明；部署侧必须替换编译/加载 pipeline。
  - 优化成本高，适合 offline/prepare-time，不适合 live program runtime adaptation。
  - 主要针对 packet-processing/XDP 语境，通用性和 hook 覆盖面有限。
- **代码/数据**：论文写明 released source/artifacts；文中实现约 `24,500 LOC`。本轮调研未定位到稳定维护中的官方 repo 首页，但论文本身明确主张 artifact 可用。
- **与 BpfReJIT 的关系**：
  - **关系类型**：直接竞争，但不在同一时机层面竞争。
  - **应如何在论文中引用**：把 K2 引为“第一个有代表性的 synthesis-based pre-load BPF optimizer”最合适。
  - **BpfReJIT 差异化**：BpfReJIT 不需要 `.bpf.o`，作用于 **已加载 live program**；可透明部署；可基于线上 profile 决定是否 REJIT。
  - **互补性**：BpfReJIT 的 userspace daemon 理论上可以吸收 K2 风格的 search/synthesis 作为某个 pass 的算法后端，但这不改变 BpfReJIT 的核心 novelty 仍在 `post-load transparency + verifier-guarded re-JIT`。
- **来源**：
  - SIGCOMM 2021 paper PDF: https://conferences.sigcomm.org/sigcomm/2021/files/papers/3452296.3472929.pdf

### 3.2 Merlin

- **基本信息**：Jinsong Mao, Hailun Ding, Juan Zhai, Shiqing Ma, “Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness,” ASPLOS 2024.
- **核心方法**：Merlin 不是 synthesis/superoptimization，而是把 eBPF 优化拆成两个层次：前端 LLVM IR passes 做 IR refinement，后端对生成的 eBPF bytecode 再做结构化 peephole / bytecode rewriting。
- **关键技术**：constant propagation、dead code elimination、instruction merging、strength reduction、alignment/macro-op fusion、IR-level + bytecode-level 联合优化。
- **性能数据**：论文摘要给出 `73%` instruction reduction、`60%` runtime overhead reduction；对比 K2，throughput 额外提升 `0.59%`、latency 再降 `5.31%`；论文强调平均编译成本显著低于 K2，并报告对 K2 约 `106x` 的 speed advantage。
- **限制**：
  - 仍是 **pre-load** toolchain。
  - 需要 `.bpf.o`，无法对已加载程序透明介入。
  - 不依赖 runtime observation，不做 online specialization / PGO。
  - 更像“更工程化、更 scalable 的编译器优化器”，不是 live reoptimization framework。
- **代码/数据**：作者主页与 GitHub 提供开源 MIT 仓库，仓库包含 LLVM pass 与 Python bytecode optimizer；README 明确输入是 clang/llc 生成的 object file。
- **与 BpfReJIT 的关系**：
  - **关系类型**：最强工程竞品之一，但仍属 pre-load。
  - **论文引用建议**：引用它作为“compiler-style eBPF optimization”的代表，比 K2 更工程化、更 scalable。
  - **BpfReJIT 差异化**：Merlin 优化发生在 load 前，BpfReJIT 优化发生在 load 后；Merlin 依赖构建链集成，BpfReJIT 可对第三方已运行程序透明生效。
  - **互补性**：Merlin 的 pass 家族可作为 daemon pass 的设计灵感，但只要系统必须拿到 `.bpf.o`，它就仍旧不能覆盖 BpfReJIT 试图打开的 deployment space。
- **来源**：
  - Paper PDF: https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf
  - Code repo: https://github.com/4ar0nma0/Merlin
  - 作者主页: https://4ar0nma0.github.io/

### 3.3 EPSO

- **基本信息**：Qian Zhu, Yuxuan Liu, Ziyuan Zhu, Shangqing Liu, Lei Bu, “EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode,” ASE 2025 / arXiv preprint dated `2025-11-19`.
- **核心方法**：EPSO 试图解决 K2 类 superoptimization 的扩展性问题。它离线进行 superoptimization 以挖掘 rewrite rules，把规则缓存起来，在线阶段只做 slice extraction + cache lookup + rule application。
- **关键技术**：offline superoptimization、rule cache、program slicing、CEGIS-style rule discovery、abstraction to improve rule reuse。
- **性能数据**：
  - `2025-11-19` arXiv 版本：发现 `795` 条 rewrite rules；相对 clang 输出，代码尺寸最高下降 `68.87%`、平均下降 `24.37%`；运行时平均提升 `6.60%`、最高 `19.05%`；synthesis-only overhead 相比 K2 下降 `88.71%`。
  - 文中还报告在全部比较基准上优于 K2，在大多数基准上优于 Merlin。
- **限制**：
  - 时机仍然是 **pre-load**。
  - 需要 `.bpf.o` 或至少需要待优化字节码作为离线输入，不透明。
  - 虽然通过 cache 把 online 成本压下来了，但仍不是针对 live kernel program 的在线 PGO/re-JIT。
  - 规则库的质量与覆盖面决定收益上限。
- **代码/数据**：截至 `2026-03-24` 公开页面中未稳定定位到官方开源仓库；可确认的是 paper/preprint 公开，artifact 可得性不如 Merlin 明确。
- **与 BpfReJIT 的关系**：
  - **关系类型**：算法上最接近 BpfReJIT daemon 可吸收的工作之一，但系统边界不同。
  - **论文引用建议**：把 EPSO 与 K2/Merlin 一起归为 “pre-load BPF optimization pipeline”。
  - **BpfReJIT 差异化**：即使 EPSO 大幅降低 superoptimization 成本，它仍然需要 object-level optimization pipeline；BpfReJIT 解决的是 “没有 `.bpf.o`、只有 live program fd/ID 时怎么办”。
  - **互补性**：EPSO 的 rule cache 非常适合迁移到 daemon，作为 post-load rewrite engine 的候选实现。
- **来源**：
  - arXiv PDF: https://arxiv.org/pdf/2511.15589.pdf

### 3.4 ePass

- **基本信息**：OrderLab 团队，LPC `2025-12-11` contribution，“ePass: A Framework for Enhancing Flexibility and Runtime Safety of eBPF Programs.”
- **核心方法**：ePass 在 kernel 内部建立 SSA-based IR、lifter、pass runner、codegen，把原本 verifier/JIT 之前的 BPF 流程扩展为“可插入 pass 的中间层”。重点不只是性能优化，也包含 verifier-cooperative runtime checking，用以允许更多安全但当前 verifier 难以接受的程序。
- **关键技术**：in-kernel IR、SSA transformation、pass composition、verifier-cooperative runtime enforcement、低代码量 pass API。
- **性能数据**：
  - LPC 材料主要强调设计和 demo。
  - eBPF Foundation grant 新闻页给出：prototype 解决了 `91%` 先前“被 verifier 拒绝但其实安全”的程序、缓解 `14` 个已知漏洞、runtime overhead `<2%`。
  - 另有说法指出 demo 中 `12` 个 pass 均可在 `<100 LOC` 实现。
- **限制**：
  - 时机更接近 `load/verify time`，不是 post-load live replacement。
  - pass 基础设施直接进 kernel，意味着 kernel-side complexity 增长更快。
  - 当前公开材料更偏 prototype / LPC 阶段，性能与广泛 workload 覆盖尚不如 K2/Merlin 那样系统化。
  - 不是透明地针对任意已加载程序做 runtime-guided reoptimization。
- **代码/数据**：公开 GitHub repo 存在；是目前少见的 kernel-side BPF pass 基础设施原型。
- **与 BpfReJIT 的关系**：
  - **关系类型**：最值得正面比较的“理念近邻”。
  - **论文引用建议**：可将 ePass 写成“把 pass 框架直接塞进 kernel 的路线”，再对比 BpfReJIT 的“minimal kernel mechanism + userspace policy”路线。
  - **BpfReJIT 差异化**：
    - BpfReJIT 优化触发点是 **post-load**。
    - BpfReJIT 不要求将高复杂度优化逻辑内嵌 kernel。
    - BpfReJIT 通过 `GET_ORIGINAL` / `REJIT` + daemon 实现机制/策略分离，更像 livepatch + verifier 的结合体。
  - **互补性**：二者都说明 “BPF pass infrastructure” 是真实需求，但系统分工完全不同。
- **来源**：
  - LPC contribution PDF: https://lpc.events/event/19/contributions/2179/contribution.pdf
  - Repo: https://github.com/OrderLab/ePass
  - eBPF Foundation grant page: https://ebpf.foundation/ebpf-foundation-awards-100000-in-research-grants-to-advance-ebpf-safety-and-efficiency/

### 3.5 BCF / “Prove It to the Kernel”

- **基本信息**：Hao Sun, Zhendong Su, “Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement,” SOSP 2025.
- **核心方法**：BCF 不做性能优化，而是把 verifier 的复杂 reasoning 外包到 userspace 精确分析器，在 kernel 内只保留一个轻量 proof checker。其目标是接受更多原本被过于保守的 verifier 拒绝的安全程序。
- **关键技术**：proof-guided abstraction refinement、userspace precise analysis、small certificate checker、证书式验证。
- **性能数据**：论文报告对 `512` 个 previously rejected program variants 中，`403` 个被接受，即 `78.7%` acceptance；平均 proof size `541 bytes`；平均 proof check time `~48.5–49 µs`；proof checking `<1%` of total analysis time；平均总分析时间约 `9.0 s`。
- **限制**：
  - 不是 optimizer。
  - 仍在 load-time path 上工作，且需要外部分析器/证书格式。
  - 不是 transparent live re-JIT。
  - 额外引入 proof format、checker、toolchain 兼容问题。
- **代码/数据**：公开 artifact-evaluation branch 可用。
- **与 BpfReJIT 的关系**：
  - **关系类型**：安全模型上的邻近工作，不是直接性能竞品。
  - **论文引用建议**：用它来说明 “最近工作也在把复杂工作从 kernel 挪到 userspace”，但 BCF offload 的是 **verification**，BpfReJIT offload 的是 **optimization policy**。
  - **BpfReJIT 差异化**：
    - BCF 增强 verifier expressiveness。
    - BpfReJIT 不替代 verifier，而是 **完全复用内核 verifier 作为 transformation gatekeeper**。
    - 如果未来想避免完整 reverify，BCF 风格证书也许可以成为 BpfReJIT 的 future work；但当前设计刻意不引入新 proof trust base。
- **来源**：
  - Paper PDF: https://haosun.info/assets/pdf/BCF.pdf
  - Artifact repo: https://github.com/SunHao-0/BCF/tree/artifact-evaluation

## 4. B 类：BPF 验证、安全与 JIT 正确性

### 4.1 Jitterbug

- **基本信息**：Luke Nelson, Jacob Van Geffen, Emina Torlak, Xi Wang, “Specification and verification in the field: Applying formal methods to BPF just-in-time compilers in the Linux kernel,” OSDI 2020.
- **核心方法**：Jitterbug 针对的是 **BPF JIT backend correctness**。它构建精确 JIT 规范与自动 proof strategy，对 Linux 内多个 BPF JIT 后端做形式化验证，并直接发现真实 bug。
- **关键技术**：formal specification of JIT correctness、automated theorem proving / symbolic reasoning、architecture-specific backend verification。
- **性能数据**：论文报告发现并修复 `16` 个先前未知的 JIT bug；验证/移植覆盖 Arm32、Arm64、RISC-V、x86-32、x86-64，并验证了新的 RV32 BPF JIT。
- **限制**：
  - 它验证的是 JIT backend，不优化 bytecode。
  - 不回答 deployment transparency 或 runtime specialization。
  - 证明成本高，难以直接作为 everyday optimization pipeline。
- **代码/数据**：官方 repo 公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：互补。
  - **论文引用建议**：放在“why JIT correctness matters”小节，说明只依赖 verifier 并不能自动消除 backend miscompilation 风险。
  - **BpfReJIT 差异化**：BpfReJIT 变换的是 BPF bytecode，并依赖现有 JIT；Jitterbug 关注的是“JIT 实现本身是否 faithful”。二者安全关注点在不同层。
- **来源**：
  - USENIX OSDI page: https://www.usenix.org/conference/osdi20/presentation/nelson
  - PDF: https://www.usenix.org/system/files/osdi20-nelson.pdf
  - Repo: https://github.com/uw-unsat/jitterbug

### 4.2 Jitk

- **基本信息**：Xi Wang, David Lazar, Nickolai Zeldovich, Adam Chlipala, Zachary Tatlock, “Jitk: A Trustworthy In-Kernel Interpreter Infrastructure,” OSDI 2014.
- **核心方法**：Jitk 比 eBPF 更早，面向 classic BPF / seccomp filter。它把 in-kernel JIT/解释设施做成可证明可信的 CompCert/Coq 体系，以减少手写 JIT backend bug。
- **关键技术**：CompCert、Coq proof、verified compilation path、trustworthy in-kernel JIT infrastructure。
- **性能数据**：论文报告 seccomp filter install time 从 stock Linux `~1 ms` 到 Jitk `~21 ms`；在 `1,000,000` 次 `gettimeofday` syscalls 的过滤场景中，stock interpreter `771 ms`、Jitk JIT `691 ms`、no filter `460 ms`。
- **限制**：
  - 面向 classic BPF 时代，不是现代 eBPF verifier + JIT 生态。
  - 关注 trustworthy execution，不是 live optimization。
  - 不支持 BpfReJIT 论文要强调的 runtime re-specialization/PGO 故事。
- **代码/数据**：论文提供项目链接。
- **与 BpfReJIT 的关系**：
  - **关系类型**：历史根基型相关工作。
  - **论文引用建议**：用作“verified BPF execution path is an old but orthogonal line of work”。
  - **BpfReJIT 差异化**：Jitk 追求可信 JIT 基础设施，BpfReJIT 追求透明 live optimization 框架；目标不同。
- **来源**：
  - OSDI 2014 PDF: https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-wang_xi.pdf

### 4.3 PREVAIL

- **基本信息**：Elazar Gershuni, Nadav Amit, et al., “Simple and Precise Static Analysis of Untrusted Linux Kernel Extensions,” PLDI 2019.
- **核心方法**：PREVAIL 是一个 polynomial-time user-space eBPF verifier，核心价值是比 Linux verifier 更 sound / scalable，并支持 loops 等更强程序结构。
- **关键技术**：abstract interpretation、join/fixpoint、polynomial-time verifier design、bounded loops 支持。
- **性能数据**：论文报告在 `192` 个 benchmark programs 中，最强 abstract domain 下除 `1` 个外全部证明安全；较 Linux verifier 多支持 `81` 个程序；每个 benchmark 验证时间不超过 `5.2 s`。
- **限制**：
  - 它是 verifier，不是 optimizer。
  - 不直接改变运行后机器码质量。
  - 如果用于 Linux 主线，还要面对 kernel integration / trust model 的问题。
- **代码/数据**：官方 repo 公开；Windows eBPF 生态也用过 PREVAIL 线。
- **与 BpfReJIT 的关系**：
  - **关系类型**：安全模型对照组。
  - **论文引用建议**：把 PREVAIL 写成“alternative verifier”代表，和 BCF/VEP 一起表明大量工作试图替代或增强 verifier，而 BpfReJIT 选择的是复用 verifier。
  - **BpfReJIT 差异化**：BpfReJIT 不建立新 verifier trust base，不引入与主线 verifier 竞争的 analysis engine。
- **来源**：
  - Paper PDF: https://seahorn.github.io/papers/ebpf-pldi19.pdf
  - Repo: https://github.com/vbpf/ebpf-verifier

### 4.4 Agni

- **基本信息**：Harishankar Vishwanathan, Matan Shachnai, Srinivas Narayana, Santosh Nagarakatte, “Verifying the Verifier: eBPF Range Analysis Verification,” CAV 2023.
- **核心方法**：Agni 不是验证 BPF program，而是验证 **Linux eBPF verifier 的 range-analysis implementation** 是否 sound。
- **关键技术**：symbolic verification of analyzer implementation、bug finding、proof-carrying analysis of verifier operators/spec。
- **性能数据**：检查 `16` 个 kernel versions（`4.14` 到 `5.19`），发现 `27` 个 previously unknown bugs；为约 `97%` 的 soundness violations 生成 POC；在 refined setting 下对约 `90%` operators 的验证耗时约 `30 min`。
- **限制**：
  - 不做 performance optimization。
  - 更偏 meta-verification 与 kernel QA。
  - 产出对 BpfReJIT 是“可信 verifier 基础的重要性”，不是替代关系。
- **代码/数据**：repo 公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：非常重要的支撑性相关工作。
  - **论文引用建议**：直接说明 verifier 本身并非完美 sound，这恰恰证明 BpfReJIT 选择“少改 kernel、尽量复用现有 verifier 机制”是务实路线。
  - **BpfReJIT 差异化**：Agni 改善/验证 safety gate；BpfReJIT 是在该 gate 存在的前提下做 live optimization。
- **来源**：
  - Paper PDF: https://people.cs.rutgers.edu/~sn349/papers/agni-cav2023.pdf
  - Repo: https://github.com/bpfverif/ebpf-range-analysis-verification-cav23

### 4.5 State Embedding / SEV

- **基本信息**：Hao Sun, Zhendong Su, “Validating the eBPF Verifier via State Embedding,” OSDI 2024.
- **核心方法**：通过 state embedding 对 verifier 内部状态与执行行为做 profiling/validation，系统性找 verifier 逻辑 bug。
- **关键技术**：state embedding、validator instrumentation、differential bug finding。
- **性能数据**：论文报告在一个月内发现 `15` 个 previously unknown logic bugs，其中 `10` 个已修复，`2` 个可利用；平均 profiling impact `5.3%`。
- **限制**：
  - 不是优化器。
  - 引入 profiling/instrumentation overhead。
- **代码/数据**：论文与项目材料公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：补强“verifier 是关键 TCB”的论据。
  - **论文引用建议**：放在 verifier correctness 段落，与 Agni 并列。
  - **BpfReJIT 差异化**：BpfReJIT 不试图重建 verifier，而是在其上做 transformation submission。
- **来源**：
  - OSDI 2024 paper PDF: https://www.usenix.org/system/files/osdi24-sun-hao.pdf

### 4.6 VEP

- **基本信息**：Xiwei Wu et al., “VEP: A Two-stage Verification Toolchain for Full eBPF Programmability,” NSDI 2025.
- **核心方法**：VEP 把验证分成 C-level annotated verifier、annotation-aware compiler 与 bytecode proof checker 三段，希望用注解和 proof 把“full programmability”带给 eBPF。
- **关键技术**：annotation-guided verification、source-level proof obligations、lightweight bytecode checker。
- **性能数据**：论文报告在其 benchmark suites 上，在正确注解给定时可达到 `100%` acceptance；产生 `64,840` proof obligations；Envoy case 中 proof 规模约 `5,800` 行。
- **限制**：
  - 需要 source/annotations，不透明。
  - 不是 post-load 优化。
  - 对生产部署的 adoption barrier 很高。
- **代码/数据**：论文页面与作者主页可见项目材料；开源程度不如 PREVAIL 明确。
- **与 BpfReJIT 的关系**：
  - **关系类型**：verification expressiveness 方向的代表。
  - **论文引用建议**：和 BCF 一起说明“近年工作在提升 verifier acceptance，而不是在 runtime 透明优化 loaded programs”。
  - **BpfReJIT 差异化**：VEP 要求更强开发者参与；BpfReJIT 追求对现有 BPF 部署完全透明。
- **来源**：
  - USENIX page: https://www.usenix.org/conference/nsdi25/presentation/wu-xiwei
  - PDF: https://www.usenix.org/system/files/nsdi25-wu-xiwei.pdf

### 4.7 BeeBox

- **基本信息**：Di Jin et al., “BeeBox: Hardening BPF against Transient Execution Attacks,” USENIX Security 2024.
- **核心方法**：BeeBox 关注 Spectre 类 transient execution attack surface，修改 verifier/JIT 逻辑，以更低开销实现 BPF transient execution defenses。
- **关键技术**：speculation hardening、compiler/JIT instrumentation、verifier-aware mitigation。
- **性能数据**：平均 overhead 约 `20%`（Katran macro benchmark），相比 Linux 现有 mitigations 的 `112%` overhead 大幅改善；端到端 throughput degradation `<1%`。
- **限制**：
  - 核心目标是安全 hardening，不是性能优化。
  - 仍需 kernel-side changes。
- **代码/数据**：论文指出仅约 `700 LOC` 改动，说明工程侵入性不大。
- **与 BpfReJIT 的关系**：
  - **关系类型**：安全加固方向的直接相关工作。
  - **论文引用建议**：支持 plan §1.9 中 “同一 REJIT 机制也可用于安全加固” 这一 story。
  - **BpfReJIT 差异化**：BeeBox 是一个特定 mitigation；BpfReJIT 是可承载安全 pass 的通用 live replacement 框架。
- **来源**：
  - USENIX Security page: https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di

### 4.8 VeriFence

- **基本信息**：Luis Gerhorst et al., “VeriFence: Lightweight and Precise Spectre Defenses for Untrusted Linux Kernel Extensions,” RAID 2024.
- **核心方法**：VeriFence 针对 Linux 当前 Spectre-PHT/STL defenses 过于保守、误拒大量 BPF 应用的问题，增强 verifier 的 architectural analysis 精度，降低误拒。
- **关键技术**：precise speculative execution defense、verifier precision improvement、lightweight protection。
- **性能数据**：基于 `844` 个 real-world programs，Linux `v6.5` defenses 拒绝 `31%` 总体 / `54%` application objects；VeriFence 把总体 rejection 降到 `4%`，application-group rejection 降为 `0`；某些实际 workload overhead 在 `0.1%` 到 `2.1%` 范围。
- **限制**：
  - 关注 Spectre defense precision，不是通用 optimizer。
  - 依赖 kernel verifier modifications。
- **代码/数据**：论文公开，预印本与 RAID 页面可访问。
- **与 BpfReJIT 的关系**：
  - **关系类型**：安全模型相关。
  - **论文引用建议**：可与 BeeBox 一起放在“BPF security hardening”小节，强调 BpfReJIT future work 可承载类似 pass。
  - **BpfReJIT 差异化**：VeriFence 是 verifier hardening；BpfReJIT 是 transformation framework。
- **来源**：
  - RAID 2024 metadata / open access info: https://cris.fau.de/publications/329168051/
  - arXiv preprint: https://arxiv.org/pdf/2405.00078

### 4.9 BpfChecker

- **基本信息**：Chaoyuan Peng et al., “Toss a Fault to BpfChecker: Revealing Implementation Flaws for eBPF Runtimes with Differential Fuzzing,” CCS 2024.
- **核心方法**：BpfChecker 通过 differential fuzzing 比较不同 eBPF runtime implementations，发现语义偏差和实现漏洞。
- **关键技术**：differential fuzzing、fault injection、runtime semantic checking。
- **性能数据**：报告发现 `28` 个新 bug、`2` 个 CVE、对应约 `$800,000` bug bounty；`25/28` bugs 为 baseline fuzzers 漏掉；BpfChecker `12 h` 内发现这些问题，而 baseline 在 `7` 天内只找到 `3` 个。
- **限制**：
  - 目标是 runtime correctness，不是 optimization。
  - 主要影响 userspace runtimes / alternative runtimes 的可信度比较。
- **代码/数据**：论文与 artifact 可获得。
- **与 BpfReJIT 的关系**：
  - **关系类型**：支撑“为什么 BpfReJIT 不想把执行搬出 kernel”的重要材料。
  - **论文引用建议**：在 runtime 相关部分点出 userspace runtimes 的 correctness attack surface。
  - **BpfReJIT 差异化**：BpfReJIT 保留 stock kernel execution path，减少引入新 runtime semantic gap。
- **来源**：
  - Local paper path: [25-toss-a-fault-to-bpfchecker.pdf](/home/yunwei37/workspace/bpf-benchmark/docs/reference/papers/25-toss-a-fault-to-bpfchecker.pdf)

### 4.10 Rex

- **基本信息**：Jinghao Jia et al., “Rex: Closing the language-verifier gap with safe and usable kernel extensions,” USENIX ATC 2025.
- **核心方法**：Rex 不是 eBPF optimizer，而是 safe Rust + runtime checks 的新 kernel extension model，试图用语言安全替代 verifier-centric usability pain。
- **关键技术**：safe Rust、kernel crate、安全接口、lightweight runtime for exception/stack/termination checks。
- **性能数据**：论文报告 Memcached 场景吞吐可达 `1.92M/1.98M`，相对 userspace baseline 带来 `5.26x/5.43x` 改善，并可与 eBPF extension 性能相当或略优。
- **限制**：
  - 改的是 extension model 本身，不兼容现有 stock eBPF deployment 模型。
  - 不是透明作用于既有 BPF 程序。
- **代码/数据**：官方 repo 存在。
- **与 BpfReJIT 的关系**：
  - **关系类型**：替代范式，不是直接竞品。
  - **论文引用建议**：把它放到“safe kernel extension alternatives”小节，说明另一条路线是放弃 verifier-centric eBPF 模型。
  - **BpfReJIT 差异化**：Rex 要开发者重写 extension；BpfReJIT 作用于现有 eBPF ecosystem，部署 friction 更低。
- **来源**：
  - USENIX page: https://www.usenix.org/conference/atc25/presentation/jia
  - PDF: https://www.usenix.org/system/files/atc25-jia.pdf

### 4.11 KFlex

- **基本信息**：Kumar Kartikeya Dwivedi, Rishabh Iyer, Sanidhya Kashyap, “Fast, Flexible, and Practical Kernel Extensions,” SOSP 2024.
- **核心方法**：KFlex 试图在“full static verification 太 restrictive”与“完全无保护的 kernel module 太危险”之间找中间点：更多依赖 lightweight runtime checks + restricted interfaces。
- **关键技术**：mixed static validation + runtime checks、fast communication path、practical kernel extension interface。
- **性能数据**：论文报告在 data-structure offload workload 上，平均 throughput overhead `9%`、latency overhead `31.7%` 相对理想零开销 baseline；performance mode 可再减少若干百分点。
- **限制**：
  - 改的是 kernel extension execution/safety model，而不是优化现有 BPF bytecode。
  - 不透明，不兼容“对任何现有 loaded BPF 程序直接生效”的目标。
- **代码/数据**：论文公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：相邻问题域。
  - **论文引用建议**：和 Rex 一起说明“学界同时也在探索 verifier 之外的新 extension contract”，从反面强调 BpfReJIT 的保守性与可部署性。
  - **BpfReJIT 差异化**：BpfReJIT 不改 extension 编程模型，而是在现有模型上增加 live optimization layer。
- **来源**：
  - Paper PDF: https://rs3lab.github.io/assets/papers/2024/dwivedi%3Akflex.pdf

## 5. C 类：BPF 运行时与替代执行环境

### 5.1 bpftime

- **基本信息**：Yusheng Zheng et al., “Extending Applications Safely and Efficiently,” OSDI 2025. 系统名为 **bpftime**，核心模型为 EIM。
- **核心方法**：bpftime 把 eBPF runtime 带到 userspace，使应用在无需内核态 attach 的情况下使用 eBPF 风格扩展，同时通过资源模型、MPK、verification/dynamic rewriting 等手段实现隔离与效率。
- **关键技术**：Extension Interface Model (EIM)、userspace eBPF runtime、MPK、shared-memory maps、userspace JIT、dynamic rewriting。
- **性能数据**：论文报告在 Nginx 类场景 overhead 约 `2%`；在某些用例上比替代方案低至 `5x` overhead；SSL monitoring overhead `3.79x` lower than native eBPF；部分场景 throughput 提升超过 `40%`。
- **限制**：
  - 执行环境变成 userspace，不再是 stock kernel eBPF path。
  - 需要 runtime adoption / integration；对现有已加载 kernel BPF program 不透明。
  - 不回答“如何优化 live in-kernel BPF”。
- **代码/数据**：官方开源项目成熟，社区活跃。
- **与 BpfReJIT 的关系**：
  - **关系类型**：最强 runtime-level 对照组之一。
  - **论文引用建议**：把 bpftime 写成“通过改变执行位置获得性能与灵活性”的代表。
  - **BpfReJIT 差异化**：bpftime 是 userspace runtime；BpfReJIT 保留 kernel execution semantics，并针对已加载 kernel program 透明工作。
- **来源**：
  - OSDI page: https://www.usenix.org/conference/osdi25/presentation/zheng-yusheng
  - PDF: https://www.usenix.org/system/files/osdi25-zheng-yusheng.pdf
  - Repo: https://github.com/eunomia-bpf/bpftime

### 5.2 llvmbpf

- **基本信息**：eunomia 项目，userspace/GPU eBPF VM with LLVM JIT/AOT compiler；无稳定 peer-reviewed 系统论文作为主引用来源。
- **核心方法**：在 userspace 解释/编译 eBPF，利用 LLVM JIT/AOT 获得较快执行；支持 helper/map inlining 等，强调把 eBPF 带离内核。
- **关键技术**：LLVM JIT、AOT、userspace VM、部分 map/helper inlining。
- **性能数据**：项目 README 强调优化能力，但没有像正式论文那样统一的 peer-reviewed benchmark 套件与结论；本项目内它更适合作为 baseline runtime，而不是文献中的“paper claim”。
- **限制**：
  - userspace runtime，不是 kernel live reoptimization。
  - 语义/compatibility coverage 受 loader/helper/context 限制。
  - correctness 风险可参考 BpfChecker 一类工作。
- **代码/数据**：官方 GitHub repo 开源。
- **与 BpfReJIT 的关系**：
  - **关系类型**：实验 baseline 和 userspace 对照组。
  - **论文引用建议**：作为 project/system 引，不宜写成论文级主要 related-work anchor。
  - **BpfReJIT 差异化**：llvmbpf 通过“换 runtime”获得优化空间；BpfReJIT 在 stock kernel eBPF model 内做透明 post-load 优化。
- **来源**：
  - Repo: https://github.com/eunomia-bpf/llvmbpf

### 5.3 uXDP / !XDP

- **基本信息**：Yusheng Zheng, Panayiotis Gavriil, Marios Kogias, “uXDP: Frictionless XDP Deployments in Userspace,” eBPF Workshop at SIGCOMM 2025.
- **核心方法**：uXDP 试图在不修改原 XDP 程序的情况下，把验证过的 XDP program 搬到 userspace 执行，从而兼得 eBPF 工作流和 userspace optimization 空间。
- **关键技术**：run unmodified XDP in userspace、preserve verified XDP semantics、kernel-bypass friendly runtime。
- **性能数据**：官方摘要报告 throughput 提升最高 `3.3x`，Meta Katran performance 提升 `40%`。
- **限制**：
  - 仅限 XDP 子域。
  - 仍是换执行位置，不是保留 in-kernel execution。
  - 对一般 tracing/security/scheduler 类 eBPF 不适用。
- **代码/数据**：公开 paper/talk PDF；系统仍偏 workshop 阶段。
- **与 BpfReJIT 的关系**：
  - **关系类型**：运行位置对照组。
  - **论文引用建议**：用于说明“如果愿意把执行迁出 kernel，可以拿到很大性能空间；BpfReJIT 则选择不改变部署位置”。
  - **BpfReJIT 差异化**：uXDP `userspace + XDP-only`，BpfReJIT `in-kernel + generic eBPF hook coverage`。
- **来源**：
  - SIGCOMM 2025 workshop page: https://conferences.sigcomm.org/sigcomm/2025/workshop/papers-workshop-info/
  - PDF: https://marioskogias.github.io/docs/uxdp.pdf

### 5.4 hXDP

- **基本信息**：Marco Spaziani Brunella et al., “hXDP: Efficient Software Packet Processing on FPGA NICs,” OSDI 2020.
- **核心方法**：把 XDP/eBPF program 翻译到 FPGA 上的 purpose-built soft processor / extended ISA 上执行，实现 packet processing offload。
- **关键技术**：optimizing compiler for FPGA target、extended eBPF ISA、soft processor、map/helper hardware support。
- **性能数据**：OSDI 页面和论文报告在 `<15%` FPGA resources 下达到高端 CPU core 的 packet forwarding throughput，并提供约 `10x` lower packet forwarding latency；部分 drop path 达到 `52 Mpps`。
- **限制**：
  - 硬件 offload，依赖 FPGA NIC。
  - 主要针对 XDP/networking。
  - 不是透明的通用 stock kernel deployment。
- **代码/数据**：研究原型公开材料较完整。
- **与 BpfReJIT 的关系**：
  - **关系类型**：硬件 placement 对照组。
  - **论文引用建议**：放在“changing execution substrate”分支，与 eHDL 同类。
  - **BpfReJIT 差异化**：BpfReJIT 不要求专用硬件，目标是提升 commodity CPU 上现有内核 BPF 执行质量。
- **来源**：
  - OSDI page: https://www.usenix.org/conference/osdi20/presentation/brunella

### 5.5 eHDL

- **基本信息**：Alessandro Rivitti et al., “eHDL: Turning eBPF/XDP Programs into Hardware Designs for the NIC,” ASPLOS 2023.
- **核心方法**：自动把 eBPF/XDP 程序变成 NIC hardware design，几乎是把“执行 BPF”推进到 synthesized hardware datapath。
- **关键技术**：automatic hardware generation from eBPF/XDP、pipeline synthesis、NIC offload generation。
- **性能数据**：论文报告在 U50 FPGA 上 line-rate `148 Mpps`、约 `1 µs` forwarding latency、`6.5%–13.3%` FPGA resources、比 processor-based offload 高 `10x–100x` throughput。
- **限制**：
  - 极强硬件依赖。
  - 主要是 XDP/data plane。
  - 与透明地优化 stock kernel live BPF 是完全不同的问题。
- **代码/数据**：论文和项目页可访问。
- **与 BpfReJIT 的关系**：
  - **关系类型**：硬件加速极端点。
  - **论文引用建议**：作为 “we are not competing with hardware generation systems” 的代表。
  - **BpfReJIT 差异化**：BpfReJIT 的价值在 deployment transparency 与 software-only incremental adoption。
- **来源**：
  - ASPLOS project page: https://pontarelli.di.uniroma1.it/publication/asplos23/

### 5.6 hBPF

- **基本信息**：hBPF 项目，eBPF in hardware。公开可确认的是 eBPF Foundation infrastructure page 与 GitHub project；未定位到高质量 peer-reviewed archival systems paper。
- **核心方法**：实现一个 FPGA 上的 eBPF CPU / hardware interpreter-executor。
- **关键技术**：FPGA-based eBPF CPU、custom call extensions、hardware test suite。
- **性能数据**：截至 `2026-03-24` 未找到正式论文级、可稳定引用的 benchmark 数据。
- **限制**：
  - 项目级 prior art，不宜在论文中作为主力 scientific baseline。
  - 硬件路线、生态兼容性、部署条件与 BpfReJIT 差异很大。
- **代码/数据**：GitHub 项目公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：说明“eBPF in hardware”这条路线存在，但不是同一问题空间。
  - **论文引用建议**：一两句即可，避免给过高篇幅。
  - **BpfReJIT 差异化**：BpfReJIT 仍然是 commodity-kernel software-only path。
- **来源**：
  - eBPF Foundation infra page: https://ebpf.io/infrastructure/
  - GitHub: https://github.com/rprinz08/hBPF

### 5.7 femto-containers

- **基本信息**：Koen Zandberg, Emmanuel Baccelli, “Femto-Containers: DevOps on Microcontrollers with Lightweight Virtualization & Isolation for IoT Software Modules,” arXiv 2021；后续还有 “lightweight virtualization and fault isolation” 论文线。
- **核心方法**：把 eBPF/rBPF VM 带到 microcontroller/RIOT OS，用极低内存开销提供模块隔离和 lightweight deployment。
- **关键技术**：eBPF virtualization on MCUs、lightweight isolation、RIOT integration、microcontroller-friendly runtime。
- **性能数据**：论文摘要报告 memory footprint overhead `<10%`，startup time 为 “tens of microseconds”，可满足 hot-path debug logic 与 higher-level logic。
- **限制**：
  - 场景是 IoT/microcontroller，不是 Linux kernel live BPF optimization。
  - 侧重点是 isolation/deployment on constrained devices。
- **代码/数据**：基于 RIOT/open-source ecosystem，学术与开源联系较紧。
- **与 BpfReJIT 的关系**：
  - **关系类型**：说明 eBPF 运行时已经被迁移到完全不同的计算环境。
  - **论文引用建议**：放在 runtime breadth / alternative deployment 段落即可，不应占直接竞品篇幅。
  - **BpfReJIT 差异化**：BpfReJIT 不重建 runtime，而是增强 Linux kernel 内现有 runtime。
- **来源**：
  - arXiv: https://arxiv.org/abs/2106.12553

### 5.8 Enabling eBPF on Embedded Systems Through Decoupled Verification

- **基本信息**：Milo Craun, Adam Oswald, Dan Williams, “Enabling eBPF on Embedded Systems Through Decoupled Verification,” 1st Workshop on eBPF and Kernel Extensions, 2023.
- **核心方法**：把 embedded 设备上的 verifier/JIT 从 load-time 拆出去：由 designated verifier kernel 验证、编译、签名 native executable，embedded device 只负责加载签名后的产物。
- **关键技术**：decoupled verification、precompiled signed native executable、verification-as-a-service 思路。
- **性能数据**：论文指出 embedded verification 可比 server 慢高达 `70x`，因此 decoupling 的价值主要体现在 feasibility。
- **限制**：
  - 依赖外部 trusted verifier kernel 和签名产物。
  - 是 embedded deployment 系统，不是 live optimization framework。
- **代码/数据**：workshop paper，作者主页提供 PDF。
- **与 BpfReJIT 的关系**：
  - **关系类型**：与 BCF 相似，体现“把复杂工作挪出受限环境”这一 broader trend。
  - **论文引用建议**：点出它和 BCF/ePass 一起说明 eBPF 社区已经在重构 verifier/JIT placement，但 BpfReJIT offload 的目标是 optimization，不是 merely verification/JIT feasibility。
  - **BpfReJIT 差异化**：embedded decoupling 依赖 signed native artifact；BpfReJIT 仍让内核完成最终 verifier + JIT。
- **来源**：
  - Author page / PDF index: https://milocraun.com/publications/
  - PDF: https://people.cs.vt.edu/djwillia/papers/ebpf23-decoupled.pdf

## 6. D 类：通用 JIT / 动态编译系统类比

这一类不是直接竞品，重点是给 BpfReJIT 的 story 找成熟类比。论文里建议少讲 benchmark，多讲 design analogy。

### 6.1 JVM HotSpot

- **基本信息**：Oracle HotSpot VM，长期工业级 JIT/runtime optimization 系统。
- **核心方法**：通过 tiered compilation，在解释/轻量编译和高优化编译之间切换，收集 profile，再对 hot code 做更 aggressive optimization。
- **关键技术**：tiered compilation、code cache segmentation、runtime profiling、deoptimization。
- **性能数据**：官方文档强调 tiered compilation 同时改善 startup 与 peak performance，并说明因此默认 code cache 大小提升到原来的约 `5x`；官方文档没有给一个统一、单一的 speedup 数字，因此更适合作为架构类比而非定量 baseline。
- **限制**：
  - 管理语言 VM，安全边界和 kernel eBPF 完全不同。
  - deoptimization 依赖 VM 对状态和栈的强控制。
- **与 BpfReJIT 的关系**：
  - **关系类型**：最好的 runtime PGO 类比。
  - **论文引用建议**：用 HotSpot 来解释 “为什么 post-load optimization 是自然方向”。
  - **BpfReJIT 差异化**：BpfReJIT 处于 kernel 内核级、untrusted extension 的更强安全语境；其优化最终受 kernel verifier 约束。
- **来源**：
  - Oracle doc: https://docs.oracle.com/en/java/javase/17/vm/java-hotspot-virtual-machine-performance-enhancements.html

### 6.2 V8 TurboFan

- **基本信息**：Google V8 的 optimizing compiler。
- **核心方法**：对 JavaScript 热路径做 speculative optimization，结合 feedback、deoptimization、隐藏类等机制获取高性能。
- **关键技术**：optimizing compiler、speculation、deoptimization、feedback-directed optimization。
- **性能数据**：V8 官方 TurboFan 文档偏机制说明，没有一个统一 speedup headline，因此同样更适合作为 design analogy。
- **限制**：
  - 动态语言 VM；trust model、ABI、program mutability 都与 eBPF 不同。
- **与 BpfReJIT 的关系**：
  - **关系类型**：说明“先运行、再观察、再重编译”在现代语言 runtime 中是标准范式。
  - **BpfReJIT 差异化**：BpfReJIT 不拥有完整语言 runtime，也没有 cheap deopt fallback，因此需要更保守的 transformation policy。
- **来源**：
  - V8 docs: https://v8.dev/docs/turbofan

### 6.3 WebAssembly runtimes / Wasmtime + Cranelift/Winch

- **基本信息**：Wasmtime 是 Bytecode Alliance 的 Wasm runtime；Cranelift 是 optimizing backend；Winch 是更快编译的 baseline compiler。
- **核心方法**：用不同 compiler tier 在 compile latency 与 generated code quality 间做权衡。Wasmtime 官方文档明确指出 Cranelift 是 optimizing compiler，Winch 是 baseline compiler，且目前不做自动 runtime tiering 切换。
- **关键技术**：baseline vs optimizing compiler split、JIT/AOT、portable IR/backend。
- **性能数据**：官方文档强调 Winch 的 low-latency startup 与 Cranelift 的 fast code；仍然缺少单一统一 speedup 数字，适合作机制引用。
- **限制**：
  - Wasm runtime 和 kernel BPF 有完全不同的 calling/context model。
  - 当前 Wasmtime 官方明确写到“does not support tiering at this time”，这一点恰好说明 BpfReJIT 的 runtime re-JIT story并不是 trivial。
- **与 BpfReJIT 的关系**：
  - **关系类型**：runtime compilation design analogy。
  - **论文引用建议**：可用来对照 “fast initial load vs later optimized recompilation” 的系统设计张力。
  - **BpfReJIT 差异化**：BpfReJIT 的 tier 切换目标是 live kernel eBPF program，而不是通用 Wasm module。
- **来源**：
  - Wasmtime docs: https://docs.wasmtime.dev/stability-platform-support.html
  - Bytecode Alliance project page: https://bytecodealliance.org/projects

### 6.4 LLVM ORC / LLJIT

- **基本信息**：LLVM ORCv2 官方 JIT framework。
- **核心方法**：为构建 JIT 编译器提供模块化组件，包括 eager/lazy compilation、symbol/materialization 管理、removable code 等。
- **关键技术**：ORCv2 layers、LLJIT、LLLazyJIT、lazy compilation、speculative compilation support。
- **性能数据**：官方文档是 framework docs，不提供单一 benchmark headline。
- **限制**：
  - 是 building block，不是具体 BPF/runtime system。
- **与 BpfReJIT 的关系**：
  - **关系类型**：工程架构类比。
  - **论文引用建议**：可用于说明 “BpfReJIT daemon 像一个 domain-specific JIT framework”。
  - **BpfReJIT 差异化**：BpfReJIT 需要和 kernel verifier/JIT syscall ABI 配合，不是纯 user-space JIT framework。
- **来源**：
  - LLVM docs: https://llvm.org/docs/ORCv2.html

### 6.5 Graal

- **基本信息**：GraalVM / Graal JIT compiler。
- **核心方法**：通过 aggressive inlining、partial escape analysis、polymorphic optimization 等提升 managed/runtime languages 性能。
- **关键技术**：high-tier optimizations、partial escape analysis、polyglot compiler infrastructure。
- **性能数据**：官方 compiler 文档偏特性说明，不给单一 speedup 数字。
- **限制**：
  - managed runtime world，与 kernel eBPF 的安全模型不同。
- **与 BpfReJIT 的关系**：
  - **关系类型**：说明“丰富 pass pipeline + runtime profiling + recompilation”是成熟传统。
  - **BpfReJIT 差异化**：把这套思路带到 kernel live eBPF 且仍受 verifier 门控，是更受限、更系统化的问题。
- **来源**：
  - GraalVM docs: https://www.graalvm.org/latest/reference-manual/java/compiler/

## 7. E 类：内核代码替换、热修复与其他内核优化类比

### 7.1 Linux livepatch

- **基本信息**：Linux kernel 官方 livepatch 机制。
- **核心方法**：在运行中的 kernel 上安全地替换函数实现，避免重启。
- **关键技术**：consistency model、hybrid kGraft/kpatch approach、atomic replace、cumulative patches。
- **性能数据**：官方文档重点是机制与一致性，不提供统一性能 headline。
- **限制**：
  - 没有 eBPF verifier 这类面向 untrusted extension 的安全 gate。
  - 目标是修 bug/打补丁，不是优化 BPF bytecode。
- **与 BpfReJIT 的关系**：
  - **关系类型**：非常强的机制类比。
  - **论文引用建议**：可写 “BpfReJIT is closer to livepatch than to a compiler pass, but with verifier-backed safety specific to BPF.”
  - **BpfReJIT 差异化**：livepatch 改的是 kernel text；BpfReJIT 改的是 verifier-gated BPF program image。
- **来源**：
  - Kernel docs: https://docs.kernel.org/livepatch/livepatch.html

### 7.2 kpatch / ksplice

- **基本信息**：两者是 Linux kernel 热补丁生态的重要工程实现。
- **核心方法**：在线应用 kernel security/bug patches，减少 reboot。
- **关键技术**：runtime patching、function redirection、consistency management。
- **性能数据**：公开主文档多强调 operational value，非 benchmark-first 论文叙事。
- **限制**：
  - 本质是维护/修复系统，不是面向 BPF 优化。
  - 无 verifier-guarded untrusted extension safety story。
- **与 BpfReJIT 的关系**：
  - **关系类型**：概念类比。
  - **论文引用建议**：可以一句带过，证明“runtime code replacement”不是新概念，但 BpfReJIT 把它带进 eBPF 并加上 verifier safety gate。
- **来源**：
  - livepatch 官方文档即可承接该段对比。

### 7.3 XDP/eBPF offload

- **基本信息**：XDP/offload 是 Linux/eBPF 生态长期存在的优化方向，包括 NIC offload、AF_XDP、driver-specific acceleration、FPGA/NIC offload 等。
- **核心方法**：通过改变执行位置（NIC、userspace、specialized path）来改善 packet processing latency/throughput。
- **关键技术**：offload contracts、driver-specific hooks、AF_XDP zero-copy、hardware datapath mapping。
- **性能数据**：具体数字依系统而异；hXDP、eHDL、uXDP 已在上文给出代表性数字。
- **限制**：
  - 强场景性，多数限于 packet processing/XDP。
  - 与通用 eBPF live optimization 不等价。
- **与 BpfReJIT 的关系**：
  - **关系类型**：问题空间相邻但不同。
  - **论文引用建议**：offload works 改的是 placement；BpfReJIT 改的是在原 placement 下的 code quality。
- **来源**：
  - XDP kernel docs: https://docs.kernel.org/networking/xdp-rx-metadata.html

### 7.4 io_uring

- **基本信息**：Linux 高性能异步 I/O 框架。
- **核心方法**：通过 API/interface redesign 消除 syscall/上下文切换开销。
- **关键技术**：submission/completion queue、shared rings、asynchronous fast path。
- **性能数据**：不同 workload 不同，非本文主轴。
- **限制**：
  - 不是 BPF，也不是 runtime code replacement。
- **与 BpfReJIT 的关系**：
  - **关系类型**：非常弱的类比，仅能说明“kernel fast path optimization 也可以通过 interface redesign 获益”。
  - **论文引用建议**：通常不需要写进 core related work，除非论文想强调 broader kernel optimization context。

## 8. F 类：2024-2026 新近/补充工作

### 8.1 Pairwise BPF Programs Should Be Optimized Together

- **基本信息**：Milo Craun, Dan Williams, “Pairwise BPF Programs Should Be Optimized Together,” 3rd Workshop on eBPF and Kernel Extensions, 2025.
- **核心方法**：观察到 tracing/observability 中大量 entry/exit probe 成对部署，造成跨程序状态共享与额外开销，因此提出 pairwise optimization，如 inlining、context-aware optimization、intermediate-state internalization。
- **关键技术**：cross-program optimization、pairwise analysis、state internalization。
- **性能数据**：论文报告示例中 random read overhead 从 `28.13%` 降到 `8.98%`，random write overhead 从 `26.97%` 降到 `8.60%`；并指出 `22/57` tools 出现该 pairwise pattern。
- **限制**：
  - 当前是 workshop-level design/early evidence。
  - 更偏 tracing use-case。
  - 尚不是透明部署到现有 Linux 主线的系统。
- **代码/数据**：作者主页和 PDF 公开。
- **与 BpfReJIT 的关系**：
  - **关系类型**：非常值得关注的 future-work 邻近方向。
  - **论文引用建议**：可放在最后“emerging optimization directions”里，说明近期社区已开始讨论 **multi-program** rather than single-program optimization。
  - **BpfReJIT 差异化**：BpfReJIT 当前主要是 single-program re-JIT framework，但完全可以承载 pairwise/cross-program pass。
- **来源**：
  - Workshop page: https://conferences.sigcomm.org/sigcomm/2025/workshop/papers-workshop-info/
  - PDF mirror: https://people.cs.vt.edu/djwillia/papers/ebpf25-pairwise.pdf

### 8.2 Automatic Synthesis of Abstract Operators for eBPF

- **基本信息**：Harishankar Vishwanathan et al., “Automatic Synthesis of Abstract Operators for eBPF,” eBPF Workshop 2025.
- **核心方法**：自动合成 verifier abstract operators，以提升 verifier soundness/precision，减少手工 operator 设计错误。
- **关键技术**：program synthesis、abstract interpretation operator synthesis、differential precision checking。
- **性能数据**：公开页面强调已推动至少一个 abstract operator precision patch upstream；工作重点是 verifier quality 而非运行性能。
- **限制**：
  - 不是 optimizer。
  - workshop 阶段。
- **代码/数据**：公开项目线为 `Vayu`。
- **与 BpfReJIT 的关系**：
  - **关系类型**：进一步强化“verifier 仍在快速演化”这一背景。
  - **论文引用建议**：放在 verifier evolution 段落即可。
  - **BpfReJIT 差异化**：BpfReJIT 构建于 verifier 之上，而不是参与 verifier operator synthesis。
- **来源**：
  - J-Global metadata: https://jglobal.jst.go.jp/en/public/202602256160047492
  - NJ publication page: https://www.researchwithnj.com/en/publications/automatic-synthesis-of-abstract-operators-for-ebpf/

### 8.3 FOSDEM 2025: Performance evaluation of the Linux kernel eBPF verifier

- **基本信息**：Julia Lawall, Maxime Derri, FOSDEM eBPF devroom, 2025.
- **核心方法**：对 Linux verifier 版本演化与 PREVAIL 做 performance comparison，分析编译器版本对 verifier 接受率和验证时间的影响。
- **关键技术**：multi-version benchmarking、verifier memory/time comparison。
- **性能数据**：对 Linux `5.0` 到 `6.8` 六个 verifier 版本做时间与内存评估；报告指出 conditional jumps 相关验证时间自 bounded loops 引入后下降明显；PREVAIL 在 path-heavy 场景有结构性优势，但总体仍比 kernel verifier 慢。
- **限制**：
  - talk，不是 archival paper。
  - 结论主要作为 ecosystem background。
- **与 BpfReJIT 的关系**：
  - **关系类型**：背景材料。
  - **论文引用建议**：如果需要强调 “verifier cost/behavior is compiler-sensitive and evolving”，可简短引用。
- **来源**：
  - FOSDEM page: https://fosdem.org/2025/schedule/event/fosdem-2025-6453-performance-evaluation-of-the-linux-kernel-ebpf-verifier/

## 9. 大对比表

说明：

- `时机`：`pre-load` 指在 `bpf()` load 前优化对象文件；`load/verify` 指 load path 内部；`post-load` 指针对已加载 live program。
- `位置`：系统主要复杂性与执行位置。
- `需要 .bpf.o?`：是否必须掌握原 object/source pipeline。
- `Transparent?`：是否可对第三方现有部署“无感”介入。
- `Runtime PGO?`：是否显式依赖运行时 profile/热度信息做后续优化。

| Paper / System | 时机 | 位置 | 需要 `.bpf.o`? | Transparent? | Runtime PGO? | 安全保证 | 性能数据 |
|---|---|---|:---:|:---:|:---:|---|---|
| K2 | pre-load | userspace | 是 | 否 | 否 | SMT equivalence + safety | 6%–26% size down; 1.36%–55.03% latency down |
| Merlin | pre-load | userspace | 是 | 否 | 否 | compiler transformations + verifier acceptability | 73% inst down; 60% overhead down |
| EPSO | pre-load | userspace | 是 | 否 | 否 | offline synthesized rewrite rules | avg 24.37% size down; avg 6.60% runtime up |
| ePass | load/verify | kernel | 是 | 否 | 否 | in-kernel IR + verifier-cooperative runtime checks | 91% rejected-safe resolved; <2% overhead |
| BCF | load-time | userspace + kernel | 是 | 否 | 否 | certificate-backed proof checking | 78.7% rejected variants accepted; ~49 µs proof check |
| Jitterbug | build/verification | proof tooling + kernel JIT | 否 | 否 | 否 | formal JIT verification | 16 new JIT bugs found |
| Jitk | load/exec | kernel + proof toolchain | 否 | 否 | 否 | Coq/CompCert verified JIT | 691 ms vs 771 ms classic seccomp case |
| PREVAIL | load-time | userspace verifier | 是 | 否 | 否 | abstract interpretation | +81 programs vs Linux verifier |
| Agni | offline analysis | proof tooling | 否 | 否 | 否 | verifier implementation verification | 27 new verifier bugs |
| VEP | pre-load / load-time | source compiler + checker | 是 | 否 | 否 | annotations + proof checker | 100% acceptance with correct annotations |
| bpftime | runtime | userspace runtime | 否 | 否 | 可部分动态重写 | MPK + userspace checks | ~2% Nginx overhead; up to 5x lower overhead |
| llvmbpf | runtime | userspace runtime | 否 | 否 | 否 | runtime-specific | project baseline, no archival headline |
| uXDP | runtime | userspace | 否 | 部分 | 否 | preserves verified XDP model | up to 3.3x throughput; +40% Katran |
| hXDP | runtime | FPGA NIC | 否 | 否 | 否 | hardware isolation + target compiler | CPU-core throughput; 10x lower latency |
| eHDL | compile/offload | hardware generation | 是 | 否 | 否 | hardware synthesis flow | 148 Mpps; ~1 µs latency |
| hBPF | runtime | FPGA | 否 | 否 | 否 | project-specific | no stable paper metric found |
| femto-containers | runtime | MCU VM | 否 | 否 | 否 | VM isolation | <10% memory overhead; tens of µs startup |
| livepatch / kpatch / ksplice | post-load | kernel | 否 | 部分 | 否 | kernel consistency model | operational, not optimization-centric |
| HotSpot | runtime | VM runtime | N/A | N/A | 是 | language VM safety | qualitative startup/peak improvement |
| V8 TurboFan | runtime | VM runtime | N/A | N/A | 是 | language VM + deopt | qualitative speculative optimization |
| Wasmtime / Cranelift / Winch | runtime | VM runtime | N/A | N/A | 部分 | Wasm sandbox + runtime | baseline vs optimizing tiers |
| LLVM ORC / LLJIT | runtime | userspace JIT framework | N/A | N/A | 可支持 | framework-level | framework, not fixed metric |
| Graal | runtime | VM runtime | N/A | N/A | 是 | managed runtime | qualitative high-tier optimization |
| **BpfReJIT** | **post-load** | **userspace daemon + kernel** | **否** | **是** | **是** | **kernel verifier re-verification** | **目标是提升已加载 live BPF 的 code quality，且不改部署模型** |

## 10. 按维度的差异化分析

### 10.1 Pre-load vs Post-load

- **Pre-load 主流**：K2、Merlin、EPSO、VEP 都假设“编译/加载链仍在你控制下”，因此可以拿到 `.bpf.o`、LLVM IR、source annotations，做充分但不透明的优化或验证。
- **Load/verify time**：ePass、BCF、PREVAIL 这类工作把改变插到 load path 内部，但依然默认“程序还没进 live steady-state”。
- **Post-load 缺口**：现有 literature 中几乎没有成熟系统同时满足“程序已经加载”“第三方部署”“仍能透明优化”“最终仍由 kernel verifier gatekeep”。这正是 BpfReJIT 的核心空位。

### 10.2 Static vs Dynamic

- **Static**：K2/Merlin/EPSO 的优化决策基本在离线或 load 前完成，不依赖线上 profile。
- **Dynamic**：HotSpot/V8/Graal 明确体现 runtime-guided recompilation；bpftime/uXDP 通过改变 runtime placement 也打开了动态优化空间。
- **BpfReJIT 的位置**：把动态编译思想从 managed/runtime world 引到 kernel eBPF world，但不要求新 VM、新语言、新 sandbox。

### 10.3 需要源码/ELF vs 完全透明

- **需要 `.bpf.o` / source**：K2、Merlin、EPSO、VEP、ePass、BCF 本质都需要 program artifact 级别输入或 load-time interception。
- **半透明**：uXDP 可以运行未修改的 XDP program，但执行位置已经变成 userspace，且仅限 XDP。
- **真正透明的目标**：对一个“已经在生产上运行、没有源码和原 `.bpf.o` 的 program”仍可优化，这正是 BpfReJIT 的差异点。

### 10.4 安全模型对比

- **proof / synthesis correctness**：K2、BCF、VEP、Jitk、Jitterbug。
- **enhanced verifier**：PREVAIL、Agni、State Embedding、VeriFence、BeeBox。
- **runtime checks / language safety**：ePass、bpftime、Rex、KFlex。
- **复用 kernel verifier**：BpfReJIT。

这里最关键的论文叙事是：

- 很多工作为了增强 expressiveness/performance，需要引入新 proof format、新 verifier、新 runtime，或者更多 kernel complexity。
- BpfReJIT 采取更保守的工程选择：**变换可以很激进，但 acceptance 机制不变，最终仍由 kernel verifier 决定是否允许替换。**

### 10.5 复杂性放在哪里

- **userspace-heavy**：K2、Merlin、EPSO、BCF、bpftime。
- **kernel-heavy**：ePass、VeriFence、BeeBox。
- **hardware-heavy**：hXDP、eHDL、hBPF。
- **mechanism/policy split**：BpfReJIT。

这也是 BpfReJIT 论文里值得强调的设计哲学：

- kernel 只放必须在 TCB 内的机制：抓原始 bytecode、重提交 verifier/JIT、支持 kinsn；
- 真正高 churn、高复杂度、架构特定、算法迭代快的 pass policy 放在 userspace daemon。

### 10.6 单程序 vs 多程序优化

- 当前直接优化工作几乎都默认 **single program**。
- `Pairwise BPF Programs Should Be Optimized Together` 表明 tracing/observability 场景里，cross-program optimization 已经浮现。
- BpfReJIT 当前 novelty 不需要依赖多程序 story，但其框架天然更适合承载这类未来扩展，因为 post-load daemon 可以观察部署形态与 program graph。

## 11. BpfReJIT 相对已有工作的独特贡献总结

下面这几条最值得在论文中作为 novelty sentence 使用。

### 11.1 第一类贡献：时机上的 novelty

- 现有直接 BPF optimizer 基本都在 `pre-load`。
- BpfReJIT 的 novelty 首先是 **post-load optimization for live kernel eBPF programs**。
- 这不是把编译器 pass 简单搬到另一个时间点，而是打开了“第三方程序、只拿到 fd/ID、线上 workload 驱动优化”的新 deployment space。

### 11.2 第二类贡献：部署透明性

- K2/Merlin/EPSO 需要 `.bpf.o`，VEP 甚至需要 source annotations。
- BpfReJIT 不需要源码、不需要原 ELF、不需要开发者重新 build/reload。
- 这让它从 “compiler/toolchain contribution” 变成 “system/runtime infrastructure contribution”。

### 11.3 第三类贡献：安全根选择

- BCF/VEP/PREVAIL/ePass 等工作都或多或少引入新的 verifier/proof/runtime checking machinery。
- BpfReJIT 的一个非常强的 engineering point 是：**不引入新的 acceptance authority**。
- 它可以把优化策略做得复杂、迭代很快，但最终安全 gate 仍是现有 kernel verifier。

### 11.4 第四类贡献：机制/策略分离

- ePass 倾向把 pass infra 深嵌 kernel。
- BpfReJIT 则把 kernel 收缩为最小机制层：syscall 扩展 + re-verification path + kinsn 支撑。
- 这一点使它比 kernel-heavy 方案更容易演进、更容易做 architecture-specific experimentation，也更符合“论文原型可持续工程化”的方向。

### 11.5 第五类贡献：把 runtime optimization 传统带入 kernel eBPF

- HotSpot / V8 / Graal 早就证明 runtime-guided recompilation 有价值。
- 但内核 eBPF world 缺少可部署、可验证、可透明插入的对应物。
- BpfReJIT 的真正新意，是把 **runtime-guided, post-load, policy-pluggable recompilation** 带进 kernel eBPF，并用 verifier 约束住风险边界。

### 11.6 第六类贡献：统一承载性能优化与安全加固

- BeeBox、VeriFence 说明 eBPF 生态对安全 hardening pass 有真实需求。
- K2/Merlin/EPSO 说明性能优化 pass 也有真实需求。
- BpfReJIT 的框架价值在于：**同一 live replacement pipeline 可以同时承载 performance passes 与 security-hardening passes**。这与 plan §1.9 的“四种用途”完全一致。

## 12. 论文写作建议：如何组织 related work

建议 related work section 按下面四段写，最清晰。

### 12.1 Direct BPF optimizers

- K2、Merlin、EPSO：统一归为 `pre-load userspace optimizers`。
- ePass：单独一句，说明也探索 pass infrastructure，但在 `kernel load-time`，且更 kernel-heavy。
- 结论句：这些工作都没有解决对 **already-loaded live BPF programs** 的透明优化。

### 12.2 Verification and safety of BPF

- Jitterbug、Jitk：执行/JIT correctness。
- PREVAIL、Agni、State Embedding、VEP、BCF：verifier precision/soundness/expressiveness。
- BeeBox、VeriFence：BPF security hardening。
- 结论句：这些工作提升了 trust base 或 acceptance power，但不提供 transparent post-load optimization。

### 12.3 Alternative runtimes and placements

- bpftime、llvmbpf、uXDP、hXDP、eHDL、femto-containers。
- 结论句：这些工作通过改变 execution substrate 获得收益，而 BpfReJIT 保持 stock kernel eBPF execution model。

### 12.4 Dynamic compilation analogies

- HotSpot、V8、Graal、LLVM ORC、Wasm runtimes、livepatch。
- 结论句：BpfReJIT 继承的是这些系统中的 runtime recompilation / live replacement 思想，但适配到 verifier-guarded kernel eBPF 环境。

## 13. 可直接复用的定位句

下面几句可以直接作为论文草稿中的候选句子。

1. Existing eBPF optimizers such as K2, Merlin, and EPSO operate before program load and require access to the original object file, whereas BpfReJIT targets already-loaded live programs and does not require `.bpf.o` artifacts.
2. Recent efforts such as ePass move pass infrastructure into the kernel load path, while BpfReJIT keeps the kernel mechanism minimal and places optimization policy in a userspace daemon.
3. Verification-oriented systems such as PREVAIL, VEP, and BCF strengthen the acceptance path of eBPF programs; in contrast, BpfReJIT reuses the stock kernel verifier and focuses on transparent post-load optimization.
4. Alternative runtimes such as bpftime, llvmbpf, uXDP, hXDP, and eHDL obtain flexibility or speed by changing the execution substrate, whereas BpfReJIT preserves the stock in-kernel deployment model.
5. Conceptually, BpfReJIT is closer to HotSpot-style runtime recompilation and livepatch-style code replacement, but adapted to verifier-guarded kernel extensions.

## 14. 总结

如果只保留一句最核心结论：

> 在现有 related work 中，没有一项工作同时满足 `post-load`、`transparent`、`no .bpf.o required`、`runtime-guided`、`verifier-guarded` 这五个条件；BpfReJIT 的 novelty 正是这个交集。

如果要保留两句：

- **直接竞品** 主要是 K2/Merlin/EPSO，但它们都停留在 pre-load 优化。
- **真正独特之处** 是 BpfReJIT 把 runtime recompilation 思想带入 live kernel eBPF，同时不替换 verifier、也不改变部署模型。

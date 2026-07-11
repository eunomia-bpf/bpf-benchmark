# eBPF 优化相关学术论文综述

调研日期：2026-05-10

> **架构注记（2026-07-10）**：论文综述与 prior-work 摘要仍可使用,但文中
> 把 BpfReJIT 定位成 daemon + `BPF_PROG_REJIT` 的段落已被 stock-kernel
> shim 路线取代。当前系统边界见
> `docs/rejit-speculative-optimization-ebpf_idea.md`;旧定位只作历史记录。

## 1. 摘要：现有 eBPF 优化研究的层次分布

近五年的 eBPF 优化研究大致集中在四类位置：

1. **pre-load 编译优化最多**：K2、Merlin、EPSO 都在程序加载前处理 `.bpf.o`、LLVM IR 或 BPF bytecode。它们能做超优化、IR pass、bytecode rewrite，但通常需要原始对象文件或重新走 load path，缺少 live program 的运行时状态。
2. **post-verification 优化有先例，但粒度不同**：KFuse 在多个已经 verify 的 BPF 程序之间做链融合，降低 tail call/indirect jump/retpoline 开销。它证明了“verify 后仍可优化”这个系统方向，但目标是 program-chain merging，不是对同一 live program 做 whole-program bytecode re-optimization。
3. **verifier 研究很活跃**：PREVAIL、Agni、State Embedding、BCF、VEP、KFlex、Rex 等都围绕 verifier 精度、正确性、可用性或替代安全机制展开。它们给 BpfReJIT 的启发是：复杂推理尽量外置，kernel 保持小而可检查；但它们多数不以性能优化为主。
4. **runtime/sandbox 和应用论文在暴露瓶颈**：HIVE/MOAT/Rex/bpftime 从隔离或用户态 runtime 角度绕开 verifier/JIT 限制；BMC/DINT/SPRIGHT/eNetSTL/Demystifying Performance 等应用论文反复显示 eBPF 的 verifier 限制、tail-call 切分、map/helper 开销、JIT 代码质量和缺少硬件特化是实际性能瓶颈。

BpfReJIT 当前的独特位置是：**application-local, stock-kernel
deployment-aware optimization**。In-app shim 在 upstream loader 的
`BPF_PROG_LOAD` 边界捕获 bytecode、map 和 attach state,运行 userspace
bytecode optimizer,再通过普通 verifier/JIT 接受 candidate。当前 corpus
评估 load-time specialization;running-process reload/reattach 已实现但需要
独立 coverage 结果。这个位置和 K2/Merlin/EPSO 的 pre-load optimizer、
KFuse 的链融合、BCF 的 proof-guided verifier 都相邻,但不重合。

## 2. 关键论文列表

### 2.1 eBPF JIT / 性能优化 / benchmark

| 论文 | 作者 | 会议/年份 | 主要层次 | 相关性 |
|---|---|---:|---|---|
| [Synthesizing Safe and Efficient Kernel Extensions for Packet Processing (K2)](https://arxiv.org/abs/2103.00022) | Qiongwen Xu, Michael D. Wong, Tanvi Wagle, Srinivas Narayana, Anirudh Sivaraman | SIGCOMM 2021 | BPF bytecode, pre-load | BPF 超优化标杆 |
| [Verified Programs Can Party: Optimizing Kernel Extensions via Post-Verification Merging (KFuse)](https://doi.org/10.1145/3492321.3519562) | Hsuan Chi Kuo, Kai Hsun Chen, Yicheng Lu, Dan Williams, Sibin Mohan, Tianyin Xu | EuroSys 2022 | post-verification runtime merging | 最接近 BpfReJIT 的 post-verification 系统 |
| [Faster Software Packet Processing on FPGA NICs with eBPF Program Warping](https://www.usenix.org/conference/atc22/presentation/bonola) | Marco Bonola et al. | USENIX ATC 2022 | BPF bytecode to FPGA pipeline | 硬件/异构 lowering |
| [Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness](https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf) | Jinsong Mao, Hailun Ding, Juan Zhai, Shiqing Ma | ASPLOS 2024 | LLVM IR + BPF bytecode, pre-load | 多层 eBPF 优化 |
| [Understanding Performance of eBPF Maps](https://doi.org/10.1145/3672197.3673430) | Chang Liu, Byungchul Tak, Long Wang | eBPF@SIGCOMM 2024 | runtime data structure benchmark | map 开销实证 |
| [eNetSTL: Towards an In-kernel Library for High-Performance eBPF-based Network Functions](https://doi.org/10.1145/3689031.3696094) | Bin Yang, Dian Shen, Junxue Zhang, Hanlin Yang, Lunqi Zhao, Beilun Wang, Guyue Liu, Kai Chen | EuroSys 2025 | in-kernel library/runtime API | 用 kernel library 弥补 eBPF 表达和性能缺口 |
| [Demystifying Performance of eBPF Network Applications](https://cs.nyu.edu/~apanda/assets/papers/conext25.pdf) | Farbod Shahinfar, Sebastiano Miano, Aurojit Panda, Gianni Antichi | PACMNET/CoNEXT 2025 | application/runtime benchmark | 明确指出 JIT、hook、runtime 限制 |
| [EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode](https://arxiv.org/abs/2511.15589) | Qian Zhu, Yuxuan Liu, Ziyuan Zhu, Shangqing Liu, Lei Bu | arXiv 2025 | BPF bytecode, pre-load | 缓存式 BPF 超优化 |
| [Extending Applications Safely and Efficiently (bpftime/EIM)](https://www.usenix.org/conference/osdi25/presentation/zheng-yusheng) | Yusheng Zheng, Tong Yu, Yiwei Yang, Yanpeng Hu, Xiaozheng Lai, Dan Williams, Andi Quinn | OSDI 2025 | userspace eBPF runtime + JIT | 用户态替代 runtime，对比 kernel-resident ReJIT |

### 2.2 Verifier / verification / safety

| 论文 | 作者 | 会议/年份 | 主要层次 | 相关性 |
|---|---|---:|---|---|
| [Simple and Precise Static Analysis of Untrusted Linux Kernel Extensions (PREVAIL)](https://pldi19.sigplan.org/details/pldi-2019-papers/44/Simple-and-Precise-Static-Analysis-of-Untrusted-Linux-Kernel-Extensions) | Elazar Gershuni, Nadav Amit, Arie Gurfinkel, Nina Narodytska, Jorge A. Navas, Noam Rinetzky, Leonid Ryzhyk, Mooly Sagiv | PLDI 2019 | verifier replacement | 抽象解释 verifier 基线 |
| [Verifying the Verifier: eBPF Range Analysis Verification (Agni)](https://people.cs.rutgers.edu/~sn349/papers/agni-cav2023.pdf) | Harishankar Vishwanathan, Matan Shachnai, Srinivas Narayana, Santosh Nagarakatte | CAV 2023 | verifier correctness | Linux verifier 抽象域正确性 |
| [Finding Correctness Bugs in eBPF Verifier with Structured and Sanitized Program](https://2024.eurosys.org/accepted-papers.html) | Hao Sun, Yiru Xu, Jianzhong Liu, Yuheng Shen, Nan Guan, Yu Jiang | EuroSys 2024 | verifier fuzzing | 结构化输入找 verifier bug |
| [Validating the eBPF Verifier via State Embedding](https://www.usenix.org/conference/osdi24/presentation/sun-hao) | Hao Sun, Zhendong Su | OSDI 2024 | verifier validation | 把 state correctness check 嵌入 BPF |
| [BRF: Fuzzing the eBPF Runtime](https://2024.esec-fse.org/details/fse-2024-research-papers/113/BRF-Fuzzing-the-eBPF-runtime) | Hsin-Wei Hung, Ardalan Amiri Sani | FSE 2024 | verifier-aware runtime fuzzing | 覆盖 verifier/load/attach/execute 全链路 |
| [Fast, Flexible, and Practical Kernel Extensions (KFlex)](https://infoscience.epfl.ch/entities/publication/88003da8-9ecc-4230-b36c-518e2311c181) | Kumar Kartikeya Dwivedi, Rishabh R. Iyer, Sanidhya Kashyap | SOSP 2024 | verifier + runtime checks | safety 分解为 kernel-interface compliance 和 extension correctness |
| [VEP: A Two-stage Verification Toolchain for Full eBPF Programmability](https://www.usenix.org/conference/nsdi25/presentation/wu-xiwei) | Xiwei Wu, Yueyang Feng, Tianyi Huang, Xiaoyang Lu, Shengkai Lin, Lihan Xie, Shizhen Zhao, Qinxiang Cao | NSDI 2025 | source annotation + bytecode proof checker | proof-carrying / annotation-guided verifier |
| [Rex: Closing the language-verifier gap with safe and usable kernel extensions](https://research.ibm.com/publications/rex-closing-the-language-verifier-gap-with-safe-and-usable-kernel-extensions) | Jinghao Jia et al. | USENIX ATC 2025 | safe Rust kernel extensions | verifier-replacing 路线 |
| [Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement (BCF)](https://www.research-collection.ethz.ch/entities/publication/099dc4f6-d4e3-4536-af98-9dcf6f7412af) | Hao Sun, Zhendong Su | SOSP 2025 | verifier cooperative proof checking | 用户态复杂推理 + kernel 线性 proof check |

检索备注：按用户给出的关键词检索时，没有找到明确以 “Gehad verifier” 命名的主流 eBPF verifier 论文；相关方向更稳定的关键词是 PREVAIL、Agni、BCF、state embedding、abstract interpretation。

### 2.3 In-kernel runtime / sandboxing / hardening

| 论文 | 作者 | 会议/年份 | 主要层次 | 相关性 |
|---|---|---:|---|---|
| [MOAT: Towards Safe BPF Kernel Extension](https://arxiv.org/abs/2301.13421) | Hongyi Lu, Shuai Wang, Yechang Wu, Wanning He, Fengwei Zhang | arXiv 2023 | MPK isolation | verifier-bypassing/defense-in-depth |
| [BeeBox: Hardening BPF against Transient Execution Attacks](https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di) | Di Jin, Alexander J. Gaidis, Vasileios P. Kemerlis | USENIX Security 2024 | JIT/sandbox hardening | transient execution 防御 |
| [HIVE: A Hardware-assisted Isolated Execution Environment for eBPF on AArch64](https://www.usenix.org/conference/usenixsecurity24/presentation/zhang-peihua) | Peihua Zhang et al. | USENIX Security 2024 | AArch64 hardware isolation | 用隔离替代纯 verifier |
| [VeriFence: Lightweight and Precise Spectre Defenses for Untrusted Linux Kernel Extensions](https://raid2024.github.io/papers/raid2024-17.pdf) | Luis Gerhorst, Henriette Herzog, Peter Wägemann, Maximilian Ott, Rüdiger Kapitza, Timo Hönig | RAID 2024 | verifier-inserted barriers + JIT lowering | verifier-cooperative hardening |
| [Linux Livepatch documentation](https://kernel.org/doc/html/next/livepatch/livepatch.html) | Linux kernel documentation | ongoing | function-level hot patching | runtime replacement 对照组，不是 BPF-specific |

### 2.4 eBPF 应用论文和瓶颈来源

| 论文 | 作者 | 会议/年份 | 应用领域 | 对优化的启发 |
|---|---|---:|---|---|
| [BMC: Accelerating Memcached using Safe In-kernel Caching and Pre-stack Processing](https://www.usenix.org/conference/nsdi21/presentation/ghigoff) | Yoann Ghigoff, Julien Sopena, Kahina Lazri, Antoine Blin, Gilles Muller | NSDI 2021 | key-value cache | 复杂逻辑被 verifier budget/tail-call 切分限制 |
| [SPRIGHT: High-performance eBPF-based Event-driven, Shared-memory Processing](https://doi.org/10.1145/3544216.3544259) | Shixiong Qi et al. | SIGCOMM 2022 | serverless dataplane | eBPF 可替代重型组件，但依赖 hook/map/socket 机制性能 |
| [Electrode: Accelerating Distributed Protocols with eBPF](https://www.usenix.org/conference/nsdi23/presentation/zhou) | Yang Zhou et al. | NSDI 2023 | distributed protocols | 通过 eBPF 减少 user/kernel crossing |
| [DINT: Fast In-Kernel Distributed Transactions with eBPF](https://www.usenix.org/conference/nsdi24/presentation/zhou-yang) | Yang Zhou, Xingyu Xiang, Matthew Kiley, Sowmya Dharanipragada, Minlan Yu | NSDI 2024 | distributed transactions | 证明 kernel-stack + eBPF 可接近 bypass 性能，但 hot path 极度依赖 eBPF codegen |
| [No Two Snowflakes Are Alike: Studying eBPF Libraries' Performance, Fidelity and Resource Usage](https://miguelmatos.me/files/papers/2025/ebpf_ebpf.pdf) | Carlos Machado, Bruno Gião, Sebastião Amaro, Miguel Matos, João Paulo, Tânia Esteves | eBPF Workshop 2025 | observability libraries | 用户态库、ringbuf/polling 路径差异导致吞吐和丢事件差异 |

## 3. 每篇关键论文摘要与 BpfReJIT 差异化

### K2, SIGCOMM 2021

- **核心 contribution**：用程序综合做 BPF bytecode superoptimization，目标是同时保持 semantic correctness 和 verifier safety。论文报告在 Cilium、Katran/hXDP/Linux benchmark 上减少 bytecode size、降低 packet latency。
- **优化层次**：BPF bytecode，pre-load。输入是 Clang 生成的 BPF object，输出仍需加载进入 kernel。
- **和 BpfReJIT 的关系**：K2 证明 BPF bytecode 层还有明显优化空间；BpfReJIT 做它没有做的 post-load/live/deployment-aware 优化，不依赖应用重新部署。K2 做了更强的形式化等价约束，BpfReJIT 当前更偏系统框架和 kernel verifier 兜底。

### KFuse, EuroSys 2022

- **核心 contribution**：把已经单独 verify/load 的 BPF program chain 动态合并，减少 indirect jump、loop 和 memory access 开销，尤其针对 tail-call 或 seccomp-BPF 链式执行。
- **优化层次**：post-verification runtime program-chain merging。
- **和 BpfReJIT 的关系**：这是最接近的系统论文，因为它也在 verification 之后利用“已安全”的事实优化执行。差异是 KFuse 优化多个程序之间的链结构；BpfReJIT 优化单个 live program 的 bytecode/native image，并重新走 verifier/JIT。

### eBPF Program Warping, ATC 2022

- **核心 contribution**：对 packet-processing BPF 程序做静态分析，把适合流水线化的子集替换为 FPGA warp engine 执行，其余部分回到常规 eBPF executor。
- **优化层次**：BPF bytecode 到 FPGA pipeline，pre-deployment/offload。
- **和 BpfReJIT 的关系**：都说明 BPF bytecode 可以作为硬件特化输入；BpfReJIT 更关注 CPU kernel JIT 和 live replacement，不要求 FPGA 或拆分执行路径。

### Merlin, ASPLOS 2024

- **核心 contribution**：多层 eBPF 优化框架，在 LLVM IR 和 BPF bytecode 两层做定制优化，提升 compactness 和 runtime performance，并与 K2 比较。
- **优化层次**：source/LLVM IR/BPF bytecode，pre-load。
- **和 BpfReJIT 的关系**：Merlin 的“multi-tier”直接支持我们论点：单靠 LLVM 默认 BPF backend 不够。BpfReJIT 的差异是 late optimization，可以利用 map values、verifier states、profile 和 target kop capability。

### Understanding Performance of eBPF Maps, eBPF@SIGCOMM 2024

- **核心 contribution**：系统 benchmark 不同 eBPF map 类型和访问模式，给出使用 map 的性能启发。
- **优化层次**：runtime data structure/performance characterization。
- **和 BpfReJIT 的关系**：map access 是 BpfReJIT `map_inline`、const propagation、specialization 的主要动机之一。该工作测 map 成本，但不改写 live program。

### eNetSTL, EuroSys 2025

- **核心 contribution**：将网络函数中共享的高成本行为抽象为稳定 in-kernel library，用 Rust 和 metadata-assisted verifier 降低 eBPF 实现复杂度和交互开销。
- **优化层次**：in-kernel library/API，应用侧重写。
- **和 BpfReJIT 的关系**：eNetSTL 是“扩展 kernel primitive”路线，BpfReJIT 是“优化已加载程序”路线。kop 与 eNetSTL 类似，都把平台/内核侧能力做成小接口，但 kop 是 codegen target 而不是通用 NF library。

### Demystifying Performance of eBPF Network Applications, PACMNET/CoNEXT 2025

- **核心 contribution**：系统解释一般网络应用 offload 到 eBPF 时为何不总是更快，量化 hook invocation、map、tail-call/feature 和 JIT 代码质量等瓶颈。
- **优化层次**：application/runtime benchmark。
- **和 BpfReJIT 的关系**：它明确指出 eBPF JIT emitted code 对性能很关键，且 runtime/hook 选择影响大。BpfReJIT 可作为回应：不改变应用 offload 架构的前提下，对 hot BPF code 做 late specialization。

### EPSO, arXiv 2025

- **核心 contribution**：用离线 superoptimization 发现 rewrite rules，并通过缓存复用规则，降低传统 superoptimizer 的在线搜索成本。
- **优化层次**：BPF bytecode，pre-load。
- **和 BpfReJIT 的关系**：EPSO 的规则库可成为 bpfopt 的候选 rewrite 来源；BpfReJIT 提供的是运行时应用这些 rewrite 并经过真实 verifier 接受的系统接口。

### bpftime/EIM, OSDI 2025

- **核心 contribution**：把 eBPF 风格 verifier、MPK 和 binary rewriting 用于 userspace extension framework，兼容部分 eBPF 生态并绕过 kernel hook 开销。
- **优化层次**：userspace runtime/JIT/sandbox。
- **和 BpfReJIT 的关系**：bpftime 选择把 eBPF 带到用户态以获取更灵活 JIT；BpfReJIT 选择保持 kernel-resident execution 和现有 app/loader 透明性。

### PREVAIL, PLDI 2019

- **核心 contribution**：基于 abstract interpretation 的 eBPF verifier，使用 Zone domain 等抽象提高可扩展性和精度。
- **优化层次**：verifier replacement。
- **和 BpfReJIT 的关系**：PREVAIL 是 verifier 研究基线。BpfReJIT 不替换 verifier，而是复用 Linux verifier，把 verifier states 当作优化 side-input。

### Agni, CAV 2023

- **核心 contribution**：形式化并验证 Linux eBPF verifier range analysis 的关键抽象算子，发现并修正 latent unsoundness。
- **优化层次**：verifier correctness。
- **和 BpfReJIT 的关系**：BpfReJIT 依赖 verifier states 做 const propagation/map_inline，必须尊重 verifier 抽象语义。Agni 说明 verifier 信息可用，但也提醒不能把 verifier log 当成无条件真值。

### Finding Correctness Bugs in eBPF Verifier, EuroSys 2024

- **核心 contribution**：用 structured/sanitized BPF program 生成方法找 verifier correctness bugs。
- **优化层次**：verifier fuzzing。
- **和 BpfReJIT 的关系**：BpfReJIT 增加了大量“合法但非普通编译器生成”的 bytecode 形态，类似 fuzzing 工具可作为 ReJIT regression oracle。

### State Embedding, OSDI 2024

- **核心 contribution**：把 concrete state 和 approximation-correctness check 嵌入 BPF 程序，让 verifier 自己验证其近似是否包含真实状态，从而暴露 verifier logic bug。
- **优化层次**：verifier validation。
- **和 BpfReJIT 的关系**：它提供了一个很适合 BpfReJIT 的测试思想：优化 pass 生成的新 bytecode 可以携带自校验状态，验证 verifier-state-driven optimization 是否稳健。

### BRF, FSE 2024

- **核心 contribution**：构造能满足 verifier 语义和依赖的 eBPF runtime fuzzing 输入，覆盖 load/attach/execute 路径。
- **优化层次**：verifier-aware runtime fuzzing。
- **和 BpfReJIT 的关系**：当前风险面包括 shim syscall interposition、
  load-attribute replay、map/profile side input、candidate `BPF_PROG_LOAD`
  和 attachment replacement;BRF 的方法可扩展为 shim/load/reattach-aware
  fuzzing。

### KFlex, SOSP 2024

- **核心 contribution**：把 kernel extension safety 分成 kernel-owned resource compliance 和 extension-owned resource correctness，前者用 verification，后者用轻量 runtime checks，提升 expressiveness/performance。
- **优化层次**：verifier + runtime checks。
- **和 BpfReJIT 的关系**：KFlex 和 BpfReJIT 都是 safety/correctness 分离。区别是 KFlex 改 extension model；BpfReJIT 保持 eBPF model，把 correctness 留给 userspace optimizer，safety 留给原 verifier。

### VEP, NSDI 2025

- **核心 contribution**：两阶段 verification toolchain，source annotation 到 annotated bytecode，再由轻量 bytecode proof checker 检查。
- **优化层次**：source annotation + bytecode proof checker。
- **和 BpfReJIT 的关系**：VEP 是 proof-carrying verifier 路线。BpfReJIT 可借鉴 proof metadata，但当前更强调无需用户源码/注解的透明优化。

### Rex, ATC 2025

- **核心 contribution**：用 safe Rust 和轻量 runtime 支撑 kernel extensions，消除 eBPF “语言安全性”和 verifier 接受条件之间的 gap。
- **优化层次**：safe language/runtime，verifier replacement。
- **和 BpfReJIT 的关系**：Rex 解决“新扩展怎么写”；BpfReJIT 解决“已经部署的 eBPF 怎么优化”。Rex 需要迁移语言/框架，BpfReJIT 保留现有 eBPF 生态。

### BCF, SOSP 2025

- **核心 contribution**：kernel verifier 在遇到不确定性时把复杂抽象细化任务交给用户态，用户态产出 formal proof，kernel 做线性 proof checking 后接受 refined abstraction。
- **优化层次**：verifier-cooperative proof-guided abstraction refinement。
- **和 BpfReJIT 的关系**：这是 BpfReJIT 的强类比：复杂策略在用户态，kernel 保留小而可信的接受路径。BCF 面向 verifier precision；BpfReJIT 面向 optimizer/JIT performance。

### MOAT, arXiv 2023

- **核心 contribution**：用 Intel MPK 隔离潜在恶意 BPF program，作为 verifier 不完美时的 defense-in-depth。
- **优化层次**：runtime isolation。
- **和 BpfReJIT 的关系**：MOAT 是 verifier-bypassing/mitigation；BpfReJIT 不绕过 verifier。MOAT 可能降低对 verifier 的精度压力，但会改变 execution overhead model。

### BeeBox, USENIX Security 2024

- **核心 contribution**：针对 BPF transient execution attacks 做 hardening，重点在 speculative leakage 防护。
- **优化层次**：JIT/sandbox hardening。
- **和 BpfReJIT 的关系**：BpfReJIT 可把安全加固也视为 rewrite pass，例如插入 barrier 或替换 unsafe idioms，但需要避免和性能优化互相抵消。

### HIVE, USENIX Security 2024

- **核心 contribution**：在 AArch64 上用硬件特性隔离 BPF 程序，试图以 isolation-based approach 支撑复杂 BPF。
- **优化层次**：hardware-assisted runtime isolation。
- **和 BpfReJIT 的关系**：HIVE 是替代安全模型；BpfReJIT 是保留 Linux verifier。HIVE 给 kop 的启发是硬件特性应当有明确、可验证的共享语义。

### VeriFence, RAID 2024

- **核心 contribution**：扩展 BPF verifier，在检测到 Spectre-PHT/STL 风险时插入 speculation barriers，并让 JIT 后端按架构 lower 或删除。
- **优化层次**：verifier-cooperative bytecode instrumentation + JIT lowering。
- **和 BpfReJIT 的关系**：这是 “verifier-aware rewrite + arch-aware lowering” 的安全版。BpfReJIT 的 kop/pass 可以看作性能版：userspace 选择 rewrite，kernel verifier/JIT 决定是否可执行。

### BMC, NSDI 2021

- **核心 contribution**：用 eBPF/XDP 实现 pre-stack Memcached cache，在不改 kernel 和应用的情况下大幅提升目标 workload。
- **优化层次**：application-level eBPF offload。
- **和 BpfReJIT 的关系**：BMC 因 verifier complexity 和 byte-copy 成本拆成多个 BPF programs，是 BpfReJIT tail-call accounting、wide_mem、bulk_memory、map_inline 的典型动机场景。

### SPRIGHT, SIGCOMM 2022

- **核心 contribution**：用 eBPF socket message 和 shared memory processing 优化 serverless function chain，降低 serialization 和 protocol overhead。
- **优化层次**：application/runtime architecture。
- **和 BpfReJIT 的关系**：它展示 eBPF 可减少系统边界开销，但仍依赖 kernel runtime 机制。BpfReJIT 可优化其 hot BPF pieces，但不能解决整体 serverless orchestration。

### DINT, NSDI 2024

- **核心 contribution**：把分布式事务 frequent path offload 到 eBPF/XDP，使 kernel networking stack 达到接近 kernel-bypass 的吞吐/延迟。
- **优化层次**：application-level eBPF offload。
- **和 BpfReJIT 的关系**：DINT 代表“性能关键、复杂逻辑、内核常驻”的 BPF 应用。BpfReJIT 的目标正是这类 hot path 的 post-load specialization。

### egg, POPL 2021

- **核心 contribution**：提供快速、可扩展的 equality saturation e-graph library，支持 e-class analysis，把重写搜索从顺序启发式变成同时探索等价表达式。
- **优化层次**：通用 compiler/PL 技术。
- **和 BpfReJIT 的关系**：适合做 BPF peephole/pattern rewrite search，但必须加入 verifier constraints、bounded program size、helper/map/kfunc side effects、arch target costs。

### Equality Saturation for Tensor Graph Superoptimization / Tensat, MLSys 2021

- **核心 contribution**：把 equality saturation 用于 tensor graph superoptimization，避免规则顺序敏感问题。
- **优化层次**：domain-specific compiler superoptimization。
- **和 BpfReJIT 的关系**：给 BPF e-graph 优化一个方法论模板：用 domain-specific cost model 和 legality checker。差异是 BPF 的 legality 由 verifier/kernel ABI 决定，不是纯 tensor semantics。

### CompCert / CakeML

- **核心 contribution**：证明现实编译器或编译器后端语义保持，建立 verified compiler 的工程路径。
- **优化层次**：verified compiler。
- **和 BpfReJIT 的关系**：如果 BpfReJIT 走 PLDI/OOPSLA 方向，verified BPF rewriting 可以参考这些系统；系统论文路线则可把 verifier safety 和 optimizer correctness 分开，降低必须完整证明 pass 的压力。

## 4. 系统化分类

### 4.1 按优化所在层次

| 层次 | 例子论文/系统 | 优化能力 | 限制 |
|---|---|---|---|
| Source (C/Rust) | VEP, Rex, KFlex 部分设计 | 可表达高级意图、类型、资源边界 | 需要新语言、annotation 或迁移；对已有 `.bpf.o`/live program 不透明 |
| LLVM IR | Merlin | 能利用 SSA、高级 CFG、LLVM pass 生态 | load 前一次性优化；缺少 runtime map/profile/verifier feedback |
| BPF bytecode, post-LLVM pre-load | K2, Merlin bytecode stage, EPSO | 精确面向 verifier 和 BPF ISA；可做超优化和 peephole | 需要对象文件或重部署；没有 live deployment facts |
| Post-verification program set | KFuse | 利用已 verify 程序链结构，优化 tail-call/chain overhead | 目标是多程序合并，不是优化单个 program 的内部 codegen |
| BPF bytecode, post-load in-kernel | BpfReJIT | 可用 runtime profile、map values、verifier states、target kop；透明优化 live program | 必须新增 kernel syscall/metadata path；每个候选仍需 verifier 接受 |
| Verifier-inserted rewrite/hardening | VeriFence | verifier 知道安全风险，可插入 barrier 并交给 JIT lower | 主要用于安全；优化策略放 kernel 会增加 upstream/复杂度成本 |
| Kernel JIT/native code | Jitterbug, BeeBox, arch JIT patches | 最低层、可用具体 ISA | 难移植、难 upstream、正确性风险高；不适合快速迭代策略 |
| Alternative runtime/sandbox | bpftime, HIVE, MOAT, Rex | 可绕开 kernel JIT 限制或换安全模型 | 改执行模型或 deployment model，不完全透明于 kernel eBPF fast path |

### 4.2 按优化目标

| 目标 | 代表工作 | BpfReJIT 机会 |
|---|---|---|
| 减指令数 / code size | K2, Merlin, EPSO | bytecode peephole、DCE、const_prop 后清理 |
| 减跳转 / chain overhead | KFuse, K2/Merlin CFG 优化 | branch_flip、tail-call specialization、bounds_check_merge |
| inline 常量 / stable values | Merlin 部分 IR 优化，BpfReJIT map_inline 设计 | frozen/stable map value inline、verifier-state const propagation |
| hardware-specific instructions | Program Warping, hXDP, BeeBox/VeriFence JIT lowering | kop: rotate/cmov/extract/endian/bulk memory/prefetch |
| profile-guided optimization | 通用 PGO 文献，Demystifying 指出 workload sensitivity | branch_flip 必须用真实 per-site PMU profile；hot/cold path selection |
| specialization | BMC/DINT/SPRIGHT 暴露应用 hot path | 按 app/prog/map/profile 做 post-load specialization |
| sandbox/hardening | HIVE, MOAT, BeeBox, VeriFence | 用 ReJIT pass 做 runtime hardening 或 emergency neutralization |

### 4.3 按 verifier interaction

| 类型 | 例子 | 机制 | 对 BpfReJIT 的启发 |
|---|---|---|---|
| Verifier-bypassing / verifier-replacing | HIVE, MOAT, Rex | 用隔离、safe language 或 runtime checks 替代部分 verifier 假设 | 有助于表达力，但改变 trust/perf model；BpfReJIT 当前应避免走这条主线 |
| Verifier-cooperative | BCF, VEP, VeriFence, KFlex | kernel verifier 与外部 proof/runtime/barrier/check 合作 | 最适合 BpfReJIT 叙事：userspace 复杂策略 + kernel 小接受路径 |
| Verifier-validating | Agni, State Embedding, BRF, EuroSys 2024 verifier fuzzing | 验证/测试 verifier 自身正确性 | BpfReJIT 需要把这些作为 test oracle，尤其是 verifier-state-driven pass |
| Verifier-as-acceptance | K2, Merlin, EPSO, BpfReJIT | rewrite 后仍交给 verifier 接受 | BpfReJIT 的差异是 application-local loader state 与 runtime side input |

## 5. BpfReJIT 的独特定位

BpfReJIT 当前可以定位为：

> **面向真实 upstream loader 的 stock-kernel, deployment-aware eBPF
> bytecode specialization framework。**

关键边界：

- **输入**：shim 在 application `BPF_PROG_LOAD` 边界捕获的 original
  bytecode、load attributes、map snapshot、attachment state 和外部 PMU/profile
  side input。
- **优化执行位置**：userspace `bpfopt` 纯 bytecode CLI;in-app shim 执行
  runner-provided plan 并拥有 kernel-facing fd state。
- **接受路径**：candidate 通过 stock `BPF_PROG_LOAD` 重新 verify/JIT;
  load-time 路径直接完成原 load,running-process 路径再执行 attachment-specific
  reload/reattach。
- **安全模型**：不绕过 verifier；userspace optimizer 负责 semantic correctness，kernel verifier 负责 kernel safety。
- **kernel-side extension**：speculative paper 不需要 kernel extension;
  KOperation 属于独立论文线。

最接近的论文：

1. **KFuse**：相同点是 deployment-time optimization 和动态系统叙事；差异是 KFuse 合并程序链，BpfReJIT 重写 application-loaded program。
2. **K2/Merlin/EPSO**：相同点是 BPF bytecode 优化；差异是它们从 pre-load artifact 出发，BpfReJIT 在真实 loader 进程中获得 runtime/load state。
3. **BCF**：相同点是把复杂推理放用户态，kernel 只做小而可信的接受/检查；差异是 BCF 提升 verifier precision，BpfReJIT 提升 execution performance。
4. **VeriFence**：相同点是 verifier/JIT cooperation 和 architecture-aware lowering；差异是 VeriFence 主要 hardening，BpfReJIT 主要 optimization。
5. **bpftime/Rex/HIVE**：相同点是承认现有 eBPF verifier/JIT 模型有限；差异是它们换 runtime 或安全模型，BpfReJIT 保留 kernel eBPF fast path。

一句话 differentiation：

> 现有 optimizer 大多在独立的 **load 前 artifact** 上工作;BpfReJIT 在
> upstream application 的真实 load boundary 上捕获 deployment state,并让
> 每个 candidate 重新通过 stock verifier/JIT。运行中 replacement 是需要
> 单独 attachment-coverage 证据的第二条路径。

## 6. 学术创新点 brainstorm

### 6.1 System-level 创新，OSDI/SOSP 优先级最高

| 创新点 | Differentiation | 额外工作量 | 目标会议 |
|---|---|---:|---|
| BpfReJIT：application-local deployment-aware optimizer | 区别于 K2/Merlin/EPSO 的 detached pre-load artifact；区别于 KFuse 的 chain merge；保持 app loader | 中 | OSDI/SOSP/EuroSys |
| Stock `BPF_PROG_LOAD` + attachment-specific reload | 无私有 syscall；live coverage 由真实 attach population 决定 | 中 | OSDI/SOSP |
| kop 架构：可插拔 kernel-side inline emit contract | 区别于直接扩 kernel JIT peephole；新 ISA 能力以 module/contract 暴露 | 中/大 | OSDI/SOSP/ASPLOS |
| Verifier-gated optimization loop | 每个 candidate 走真实 stock verifier/JIT；失败保留为证据 | 中 | OSDI/SOSP/PLDI |
| Deployment-aware BPF optimization policy | 用 map values、hardware、profile、app hotness 选择 pass，回应 Demystifying 的 workload sensitivity | 中 | OSDI/SOSP/NSDI |

最强系统叙事：**BpfReJIT 把 runtime-guided optimization 放进真实 eBPF
loader 的 deployment boundary,但不把复杂 optimizer 放进 kernel。**

### 6.2 Compiler / PL 创新

| 创新点 | Differentiation | 额外工作量 | 目标会议 |
|---|---|---:|---|
| Safety-constrained BPF rewrite DSL | 相比 K2/EPSO 的 superoptimizer，更明确表达 verifier legality、map/kfunc side effects、BPF ABI constraints | 中 | PLDI/OOPSLA/ASPLOS |
| e-graph for verifier-constrained BPF | egg/Tensat 没有 kernel verifier 约束；BPF e-graph 需要 verifier-aware extraction cost | 大 | PLDI/OOPSLA |
| Verified BPF rewriting library | 借鉴 CompCert/CakeML，证明 bytecode pass 语义保持；kernel safety 仍由 verifier 接受 | 大 | PLDI/OOPSLA/CPP |
| MLIR dialect for kernel-loaded BPF | 把 raw bytecode lift 到可组合 IR，再 lower 回 BPF；区别于 Merlin 的 compiler-time pipeline | 大 | CGO/LLVM/PLDI workshop, 后续 PLDI |
| Translation validation for each ReJIT candidate | 不证明 optimizer，只证明 input/output pair 等价，适合 live pass | 中/大 | PLDI/OOPSLA/SOSP artifact angle |

PL 风险：如果没有强 correctness story，PLDI/OOPSLA 会质疑 optimizer bug；系统路线可以先把 safety/correctness separation 讲清楚。

### 6.3 Performance characterization 创新

| 创新点 | Differentiation | 额外工作量 | 目标会议 |
|---|---|---:|---|
| “post-load 还能优化多少”的 18-app/多架构 characterization | 现有 benchmark 多测 hook/map/helper；缺少 real app live BPF optimization headroom | 小/中 | IMC/SIGMETRICS/EuroSys |
| AOT vs post-load ReJIT performance ceiling | 对比 LLVM/Merlin/K2/EPSO 与 BpfReJIT 可达空间，回答 late info 的价值 | 中 | ASPLOS/EuroSys |
| tail-call accounting 和 caller-side benefit characterization | 解释 run_cnt=0 tail target 的统计陷阱，给出 caller/descendant affected population 方法 | 小 | eBPF Workshop/IMC |
| Verifier-state quality as optimization signal | 量化 verifier log/state 对 const_prop/map_inline 命中率和错误率的影响 | 中 | PLDI/EuroSys workshop |

这条线投稿风险较低，但如果只是测量，顶会需要非常强的数据集、复现性和新 insight。

### 6.4 Networking / Security 创新

| 创新点 | Differentiation | 额外工作量 | 目标会议 |
|---|---|---:|---|
| Production networking ReJIT：Cilium/Katran/DINT/BMC 类 hot path | 与应用论文不同，我们不要求作者手写更复杂 BPF；自动 late optimization | 中/大 | NSDI/SIGCOMM |
| Security monitoring ReJIT：Tracee/Tetragon/OTEL profiler | 观测类 BPF 长期驻留、频繁触发，优化可直接降低 monitored workload overhead | 中 | USENIX Security/EuroSys |
| ReJIT for hardening and live neutralization | 与 BeeBox/VeriFence/HIVE 不同，BpfReJIT 可对已部署 program 在线插入/替换安全逻辑 | 大 | Security/OSDI |
| PGO branch/layout for BPF policy programs | profile-guided branch_flip 对 Cilium policy/tetragon filters 更自然 | 中 | NSDI/ASPLOS |

NSDI/SIGCOMM 需要更强网络场景和 production traces；Security 方向需要严谨 threat model，不能只说“可插 barrier”。

## 7. 社区贡献机会清单

### LLVM BPF backend

- 把 BpfReJIT 中稳定、architecture-independent、compile-time 可判定的 peephole 回流到 LLVM BPF backend：wide memory idioms、rotate idioms、extract idioms、bounds-check canonicalization。
- 给 LLVM BPF backend 增加更好的 cost model：避免为了 verifier 友好牺牲明显 codegen 质量。
- 改进 BPF IR 到 bytecode 的 metadata 保留，使后续 post-load optimizer 更容易定位 source/IR pattern。

### Linux kernel

- 不为 speculative 路线新增 ReJIT/original-bytecode syscall;由 in-app shim
  捕获 original load context。
- 改进 verifier log/state 的结构化输出,减少 fragile log parsing。
- KOperation/JIT backend hooks 属于独立 KOperation 论文线,不得与 stock-kernel
  speculative contribution 合并。

### libbpf

- 提供 verifier-state/log parse helper,避免各项目重复解析 text log。
- 调研 attachment replacement 与 loader-state introspection 的统一接口;
  当前实现仍必须按 attach type 处理。

### bpfopt 开源工具

- 发布 standalone pure-bytecode optimizer：stdin/stdout `struct bpf_insn[]`，side-input 走 JSON/files。
- 提供 offline mode：开发者可以在 CI 中对 `.bpf.o` 做 pass preview,但它
  不替代真实 application loader path。
- 提供 pass report schema：记录 rewrite site、applied count、failure reason、verifier dependency。
- 接入 K2/EPSO 类规则库或 e-graph backend，但以 verifier acceptance 为最终边界。

## 8. 参考链接

- K2, SIGCOMM 2021: <https://arxiv.org/abs/2103.00022>
- KFuse, EuroSys 2022: <https://doi.org/10.1145/3492321.3519562>
- eBPF Program Warping, ATC 2022: <https://www.usenix.org/conference/atc22/presentation/bonola>
- Merlin, ASPLOS 2024: <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>
- Understanding Performance of eBPF Maps, eBPF@SIGCOMM 2024: <https://doi.org/10.1145/3672197.3673430>
- eNetSTL, EuroSys 2025: <https://doi.org/10.1145/3689031.3696094>
- Demystifying Performance of eBPF Network Applications, PACMNET/CoNEXT 2025: <https://cs.nyu.edu/~apanda/assets/papers/conext25.pdf>
- EPSO, arXiv 2025: <https://arxiv.org/abs/2511.15589>
- bpftime/EIM, OSDI 2025: <https://www.usenix.org/conference/osdi25/presentation/zheng-yusheng>
- PREVAIL, PLDI 2019: <https://pldi19.sigplan.org/details/pldi-2019-papers/44/Simple-and-Precise-Static-Analysis-of-Untrusted-Linux-Kernel-Extensions>
- Agni, CAV 2023: <https://people.cs.rutgers.edu/~sn349/papers/agni-cav2023.pdf>
- State Embedding, OSDI 2024: <https://www.usenix.org/conference/osdi24/presentation/sun-hao>
- BRF, FSE 2024: <https://2024.esec-fse.org/details/fse-2024-research-papers/113/BRF-Fuzzing-the-eBPF-runtime>
- KFlex, SOSP 2024: <https://infoscience.epfl.ch/entities/publication/88003da8-9ecc-4230-b36c-518e2311c181>
- VEP, NSDI 2025: <https://www.usenix.org/conference/nsdi25/presentation/wu-xiwei>
- Rex, ATC 2025: <https://research.ibm.com/publications/rex-closing-the-language-verifier-gap-with-safe-and-usable-kernel-extensions>
- BCF, SOSP 2025: <https://www.research-collection.ethz.ch/entities/publication/099dc4f6-d4e3-4536-af98-9dcf6f7412af>
- MOAT, arXiv 2023: <https://arxiv.org/abs/2301.13421>
- BeeBox, USENIX Security 2024: <https://www.usenix.org/conference/usenixsecurity24/presentation/jin-di>
- HIVE, USENIX Security 2024: <https://www.usenix.org/conference/usenixsecurity24/presentation/zhang-peihua>
- VeriFence, RAID 2024: <https://raid2024.github.io/papers/raid2024-17.pdf>
- BMC, NSDI 2021: <https://www.usenix.org/conference/nsdi21/presentation/ghigoff>
- SPRIGHT, SIGCOMM 2022: <https://doi.org/10.1145/3544216.3544259>
- Electrode, NSDI 2023: <https://www.usenix.org/conference/nsdi23/presentation/zhou>
- DINT, NSDI 2024: <https://www.usenix.org/conference/nsdi24/presentation/zhou-yang>
- egg, POPL 2021: <https://popl21.sigplan.org/details/POPL-2021-research-papers/23/egg-Fast-and-Extensible-Equality-Saturation>
- Equality Saturation for Tensor Graph Superoptimization, MLSys 2021: <https://proceedings.mlsys.org/paper_files/paper/2021/hash/cc427d934a7f6c0663e5923f49eba531-Abstract.html>
- Linux livepatch documentation: <https://kernel.org/doc/html/next/livepatch/livepatch.html>

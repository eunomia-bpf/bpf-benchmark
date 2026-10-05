# eBPF Grant 提案事实核查报告（overview.tex / main.tex / biblio.bib）

- 核查对象：`docs/research/eBPF-Grant---eBPF-runtime-optimization/{overview.tex,main.tex,biblio.bib}`
- 核查时间：2026-07-13
- 方法：逐条对照三篇 source-of-truth 论文（Kops `docs/paper/`、BpfReJIT `docs/speculative-optimization/`、NativeBPF `docs/kprog-simulator-in-ebpf/`）、bpf-bench 论文（`docs/ebpf27-bpfoptbench/main.tex`）、仓库现状（`corpus/config/macro_apps.yaml`、`bpfopt/`、`micro/`、CLAUDE.md）、以及 GitHub/WebSearch 外部核实。

---

## 一、逐条核查结果表

| # | claim（overview.tex 位置） | 结论 | 证据 |
|---|---|---|---|
| 1 | "characterization over **54** microbenchmarks ... up to twice as slow ... 1.57× geomean on x86-64"（line 5） | **MISMATCH**（数字错误） | `docs/paper/sections/3-characterization.tex:141` 明确写 "The corpus is **27** pure-bytecode microbenchmarks."，表 `sec-3-micro-summary.tex` 也是 27 个基准（x86: 24/27、25/27；ARM64: 27/27）。"54" 这个数字只出现在**已废弃的旧稿**里：`docs/paper/documents/3-motivation.tex:94` 和 `docs/paper/documents/2-old-bandm.tex:137`（目录名本身就是 "old"/早期 outline，非本次任务指定的 sources-of-truth）。"1.57×" 和 "twice as slow" 部分是对的（x86 1.57×、ARM64 1.98×，均来自 3-characterization.tex:111）。 |
| 2 | Rotate 例子："eight bytecode instructions and leaves as 15 machine instructions"，原生单条 ROL（line 5） | **CONFIRMED** | 与 `1-introduction.tex:132-133` 逐字一致："A 64-bit rotate with a variable shift, a single ROL instruction on x86-64, arrives at the kernel JIT as eight bytecode instructions and is emitted as 15 machine instructions."；`3-characterization.tex:242-244` 和 `tables/sec-2-isa-gap.tex`（Rotate 行：Native 1 / eBPF 8 / Kernel JIT 15）也一致。 |
| 3a | "seven hardware-idiom operations" | **CONFIRMED** | Kops abstract/intro 多处 "seven operations/seven such operations"。 |
| 3b | "up to 24% on x86-64 and 22% on ARM64" | **CONFIRMED** | `1-introduction.tex:141`、`0-abstract.tex:47`、`9-conclusion.tex:29` 完全一致的表述。 |
| 3c | "recovering 42% of the gap" | **CONFIRMED** | `7-evaluation.tex:66`："the 1.242× speedup recovers 42% of the characterization's 1.57× eBPF-native gap on x86-64"。 |
| 3d | "improves Cilium and Katran datapath throughput by up to 12%" | **CONFIRMED，但有细节需注意** | Kops abstract/intro/conclusion 都写 "up to 12%"，但 RQ2（`7-evaluation.tex:84,87`）默认策略下 Cilium 是 **1.074×**（7.4%）、Katran 是 **1.073×**（7.3%），都够不到 12%。真正接近 12% 的是 RQ3 敏感性分析里 Cilium 关掉 `bulk_memory` 之后的 **1.114×**（11.4%，`7-evaluation.tex:103`），是一个消融变体而非 RQ2 的默认头条结果。overview.tex 的措辞完全照搬了 Kops 论文自己 abstract/intro/conclusion 里的 "up to 12%"（这本身是 Kops 论文自己的表述方式，不是 grant 撰写者编造的），但建议提案作者知悉：这是"上限值来自消融实验变体"而非默认策略的头条数字。 |
| 3e | "shrinks generated native code by 12–23%" | **CONFIRMED** | RQ1（`7-evaluation.tex:63`）：x86-64 0.772×（22.8% 减少）、ARM64 0.879×（12.1% 减少），即 12.1%–22.8%，四舍五入为 "12–23%"。 |
| 3f | "no measurable load-time overhead" | **CONFIRMED** | `7-evaluation.tex:74`："the kernel-side load time ... shows a 0.99× geomean ratio ... i.e., no measurable overhead."（注意：这只是 load time；同一句话里 end-to-end compile time 增加 1.4–2.4×，但 overview 没有把这个和 load-time overhead 混为一谈，用词精确。） |
| 3g | Lean 4 证明 claim | **CONFIRMED** | Kops abstract："Lean 4 proofs show that each native emit computes the same result as its proof sequence."（intro §同）。 |
| 4 | "Kops is an extension interface, added as a small one-time kernel patch, through which kernel modules add new operations without further core changes" | **CONFIRMED（略有简化）** | 与 Kops abstract "an extension interface that lets userspace compilers and kernel modules introduce new operations without modifying the kernel core" 和 intro "the kernel change ... must therefore stay small and one-time" 一致。overview 省略了"userspace compilers 也能新增 operation"这一半，只提 kernel modules，是无害的简化，不构成事实错误。 |
| 5a | "in-process shim intercepts unmodified application's BPF_PROG_LOAD and attachment calls" | **CONFIRMED** | BpfReJIT abstract："An in-process shim captures each upstream application's normal BPF_PROG_LOAD context and attachment state." |
| 5b | "resubmits every candidate through the stock verifier and JIT" | **CONFIRMED** | abstract："the shim submits every candidate through the stock verifier and JIT." |
| 5c | "load-time specialization and in-place replacement of running programs via stock kernel APIs" | **CONFIRMED** | abstract："The same boundary supports two modes: load-time specialization ... and an implemented running-process path that reloads accepted candidates and updates captured attachments with existing kernel APIs." |
| 5d | "BpfReJIT transparently applies load-time plans to all six unmodified applications" | **CONFIRMED（作为机制声明，非性能声明）** | 对应 `5-evaluation-plan.tex` claim ledger C1："The shim transparently applies BPF-to-BPF plans during real application loads. → Mechanism implemented; six-app reruns exist."。overview 把它放在 "Preliminary Results" 段落里且**没有**声称性能提升，与论文诚实披露 branch_flip 结果好坏参半（见 #9）保持一致，措辞谨慎、没有过度声明。 |
| 6 | "A NativeBPF native-execution preview, which runs whole-program native replacements, reaches 2.358× on Cilium" | **MISMATCH / 归因张力，需要修正** | 见下方专门分析（§二.1）。2.358× 这个数字实际来自 **Kops 论文** `7-evaluation.tex` RQ4"native-in-kernel upper bound"实验（同样用 Kops 的 dual-form 接口做整程序原生替换），论文原文明确说"The 2.358× upper bound is not comparable to the characterization's 1.57× microbenchmark gap"，且这段是作为 Kops 设计空间里的第三个点来讨论的，通篇没有出现"NativeBPF"字样。而 **NativeBPF 论文自己**的 Existing Evidence 段落（`5-evaluation-plan.tex:23-32`）给出的是完全不同的数字：x86 KVM workload geomean **1.349×**、ARM64 AWS workload geomean **1.056×**，微基准 **1.478×**（29 个 x86 纯字节码）/ **1.429×**（13 个 x86 helper/map），且明确警告"这些数字必须谨慎使用……最终论文必须把 'native execution potential' 和 'NativeBPF verified execution' 分开"。overview.tex 把 Kops 论文的实验结果贴上"NativeBPF native-execution preview"标签，是张冠李戴。 |
| 7 | "six production applications (Cilium, Katran, Tracee, Tetragon, BCC, an eBPF continuous profiler), 146 programs, 42 microbenchmarks, built-in correctness oracles, automated x86-64/ARM64 runs" | **CONFIRMED** | `docs/ebpf27-bpfoptbench/main.tex` abstract："146 programs and 42 micro benchmarks"；§Benchmark Design "6 production applications with 146 BPF programs"、"42 microbenchmarks ... under BPF_PROG_TEST_RUN"、"hidden correctness tests to prevent reward hacking"（对应"built-in correctness oracles"）、x86 KVM + ARM64 AWS（对应"automated x86-64/ARM64 runs"）。六个 app 名字与 `corpus/config/macro_apps.yaml`（bcc/set, otelcol-ebpf-profiler/profiling, cilium/agent, tetragon/observer, katran, tracee/monitor）一一对应，也与 CLAUDE.md "Supported Apps (6): tracee, tetragon, bcc, katran, cilium, otelcol-ebpf-profiler" 完全一致。 |
| 8 | "LLM-agent exploration harness has discovered speedups of up to 34% on suite programs" | **CONFIRMED** | bpf-bench abstract 原句："up to 34% speedup"。 |
| 9a | "0.995× on Katran under a coverage-maximizing policy" | **CONFIRMED（精确匹配）** | `7-evaluation.tex:105`（RQ3）："we then force a coverage-max policy that enables every implemented ARM64 family and applies 62 sites. ... workload throughput falls to 0.995×"。 |
| 9b | "a profile-guided branch-layout pass improved one complete six-application run but regressed a rerun" | **CONFIRMED** | BpfReJIT `5-evaluation-plan.tex:31-39`："The July 1 complete six-app run ... produced a 0.949 optimized-to-baseline geomean (1.054× speedup). A later rerun did not reproduce it ... Stitching those app-level artifacts yields a 1.113 ratio (0.899× speedup) ... 44 wins and 60 losses."。 |
| 10 | "idioms alone recover only 5.4% of the achievable gap on Cilium" | **CONFIRMED（精确匹配）** | `7-evaluation.tex:121`："its 1.074× Cilium throughput gain recovers 5.4% of the 2.358× native upper bound's gap ((1.074−1)/(2.358−1))"。注意：这里的 2.358× 用法是正确的——Task 2 这句话**没有**把它归因为 NativeBPF，只是复用了 Kops 论文里同一个数字做分母，这是合理的；真正有问题的归因是 #6（Preliminary Results 段落里把它叫做"NativeBPF preview"）。 |
| 11a | K2/Merlin/EPSO：在 ISA 内改写、load 前完成、看不到 deployment workload | **CONFIRMED** | 与 Kops `1-introduction.tex:110`（"rewrite programs within the eBPF instruction set, but cannot emit native instructions the instruction set lacks"）及 bib 摘要一致。 |
| 11b | EPASS：2025 eBPF Foundation project，load-time transformation for programmability/safety within ISA | **CONFIRMED（已外部核实）** | WebSearch 确认：Ryan Huang（University of Michigan）2025 年获 eBPF Foundation $50K 资助，项目名 "Verifier-Cooperative Instrumentation"，产出框架 EPASS，"resolved about 91% of programs incorrectly rejected"——与 bib 摘要逐项吻合。 |
| 11c | Jitterbug/Agni：verify existing JIT/verifier，不扩展 pipeline | **CONFIRMED** | 与 Kops `1-introduction.tex` 用词一致，bib 摘要准确。 |
| 11d | Rex：trades independent checking for toolchain trust | **CONFIRMED** | 与 NativeBPF intro（"its safety argument relies on a trusted language toolchain"）呼应；WebSearch 确认 Rex 是真实的 ATC'25 论文（pp. 325–342）。 |
| 11e | "BOLT-style profile-guided optimization has no eBPF counterpart. To our knowledge, BpfReJIT provides the first." | **需要在提交前验证 / 目前证据不足** | 见下方专门分析（§二.2）。BpfReJIT 论文自己的 related-work（`6-related-work.tex`）**没有**做出这个"first"论断；相反，"Runtime eBPF Specialization" 小节里留了一条明确的 TODO："% TODO: add and verify the closest runtime eBPF specialization citations before submission"。也就是说，BpfReJIT 论文草稿自己都还没有完成"是否是第一个"这个查新工作，overview.tex 却已经替它下了断言。 |
| 12 | "Every component already exists as a working prototype ... all open sourced at github.com/eunomia-bpf/**bpf-bench**" | **MISMATCH（严重，需在提交前修复）** | 见下方专门分析（§二.3）。该 URL 返回 **HTTP 404**（WebFetch 和 `gh api` 均确认）。真实的公开仓库是 **`github.com/eunomia-bpf/bpf-benchmark`**（本地仓库 `git remote -v` 的 origin 正是这个地址；GitHub 搜索 API 确认它公开、22 stars、topics 含 `koperation`，描述为 "AI Agent eBPF optimization benchmark and framework"）。同样的错误 URL 也出现在 `docs/ebpf27-bpfoptbench/main.tex:62`（"\sys is available at https://github.com/eunomia-bpf/bpf-bench"），说明这是一个从 bpf-bench 论文继承过来的、贯穿多个文档的拼写错误（少了 "mark"）。 |
| 13 | Milestones: Dec 1, 2026 / May 1, 2027 | **内部一致，但外部 RFP 要求无法核实** | overview.tex §3 内部写法一致（Milestone 1 = Dec 1 2026 对应"1st update blog post"，Milestone 2 = May 1 2027 对应"2nd progress update"）。任务给定的 source-of-truth 列表中不含 eBPF Foundation 的 RFP/资助条款原文，因此**无法独立核实**这两个日期是否恰好对应 Foundation 要求的汇报节点；只能确认提案文档自身没有前后矛盾。 |
| 14 | overview.tex 内部一致性 | 发现 1 处（见 #1），其余未见矛盾 | "54 microbenchmarks"（line 5）与论文当前正文的 27（characterization）、62（Kops RQ1 全部微基准）、42（bpf-bench 套件总数）都对不上，是本文档中最明显的内部/外部不一致数字。其余如 42%（微基准恢复比例）与 5.4%（Cilium 应用级恢复比例）是两个不同层级的合理并存数字，未见矛盾；2.358× 在 Preliminary Results 段和 Task 2 句子中数值本身一致，只是前一处的"来源标签"贴错了（见 #6）。 |
| 15 | biblio.bib 抽查 | **全部 CONFIRMED（已逐条外部核实，未发现错误）** | 见下方 §三 详细清单。 |

---

## 二、需要重点关注的三个问题（深入分析）

### 1. "NativeBPF ... reaches 2.358× on Cilium" 的归因张力（对应 claim #6）

Overview.tex 原文（line 21）：

> "A NativeBPF native-execution preview, which runs whole-program native replacements, reaches 2.358$\times$ on Cilium, quantifying the remaining gap to native performance..."

**2.358× 的真实出处**是 Kops 论文 `7-evaluation.tex` §RQ4 "Native-in-Kernel Upper Bound"（line 110-121）：这是用 **Kops 自己的 dual-form 接口**（proof sequence = eBPF bytecode，native emit = LLVM -O2 直接编译的原生代码，但这次是"信任"而非"证明"两者等价）对 Cilium 做整程序原生替换的实验，论文原话是把它定位为"stock eBPF、Kops idiom operations、native-in-kernel execution 这三个点构成的同一个设计空间"里的第三个点，而不是一个叫"NativeBPF"的独立系统产出的结果。整段文字里没有出现 "NativeBPF" 这个词。

而 **NativeBPF 论文自己**（`docs/kprog-simulator-in-ebpf/sections/5-evaluation-plan.tex` "Existing Evidence" 小节）明确给出的是另一组数字：
- x86 KVM workload geomean **1.349×** native/eBPF（六个 corpus apps）
- ARM64 AWS workload geomean **1.056×**
- 微基准 **1.478×**（29 个 x86 纯字节码基准）、**1.429×**（13 个 x86 helper/map 基准）

并且这段话紧接着自我警示："These numbers should be used carefully. They show that the execution target is worth pursuing, but they do not establish that the simulator artifact ✓ is generated, accepted, and faithfully bound for those programs. **The final paper must therefore separate 'native execution potential' from 'NativeBPF verified execution.'**"

**结论**：overview.tex 把 Kops 论文里"信任原生替换"的设计空间实验（2.358×），贴上了"NativeBPF native-execution preview"的标签，而 NativeBPF 项目自己已有的 preview 数字其实是完全不同的一组（1.349×/1.056×/1.478×/1.429×），且论文自己反复强调这些 preview 数字不能等同于"verified execution"的结果。这是一个真实的张冠李戴，容易被评审识破（评审如果去读 Kops 或 NativeBPF 论文原文，会发现 "2.358×" 根本不是 NativeBPF 产出的）。

**建议修复**（二选一）：
- (a) 把这句话的归因改回 Kops：将 2.358× 描述为"Kops 接口在信任模式下做整程序原生替换所揭示的性能天花板"，而不是"NativeBPF preview"；
- (b) 如果确实想突出 NativeBPF 项目的现有数据，应该换用 NativeBPF 自己的数字（1.349×/1.056× workload，或 1.478×/1.429× 微基准），并同样标注"这只是 native-execution potential，不是 verified NativeBPF execution"的限定语，与 NativeBPF 论文的措辞保持一致。

### 2. "BpfReJIT provides the first" 的新颖性声明尚未被源论文自己验证（对应 claim #11e）

Overview.tex 原文：

> "BOLT-style profile-guided optimization~\cite{panchenko2019bolt} has no eBPF counterpart. To our knowledge, BpfReJIT provides the first."

BpfReJIT 论文自己的 `sections/6-related-work.tex` 中，与此最相关的两个小节是：
- "Speculative Runtime Optimization"：只提到 HotSpot 类生产 JIT 用运行时 profile 选择优化版本（`paleczny2001java`），说明 BpfReJIT 借用了"观察-特化"分离思路，但没有做"BOLT 类是否有 eBPF 对应物"的查新论断。
- "Runtime eBPF Specialization"：这一节明确留了一条尚未完成的 TODO 注释：
  ```
  % TODO: add and verify the closest runtime eBPF specialization citations before submission.
  ```

也就是说，BpfReJIT 论文草稿自己都还没有完成"最接近的 runtime eBPF 特化系统"这项查新工作，**overview.tex 却已经先一步下了"我们是第一个"的断言**。这不是说这个断言一定是错的（我个人所知范围内确实没见过专门针对 eBPF 的、post-link/BOLT 风格 profile-guided 分支布局优化器），但这是一个**尚未被源材料证实、且源材料自己标注为未完成**的新颖性声明，在正式提交前应当：
- 要求作者/学生把 BpfReJIT 论文里那条 TODO 完成（做一次系统的 related-work 检索），确认没有遗漏的现有工作（例如是否有人在 XDP/tc-bpf 场景做过静态分支概率标注、liveness-based 重排等）；
- 或者在 grant 文本里把"first"这种强断言弱化为"to our knowledge, no published eBPF-specific counterpart"并附带这是初步文献调研结论的限定。

### 3. GitHub 仓库链接失效（对应 claim #12）——必须在提交前修复

Overview.tex 原文（line 21）：

> "...all open sourced at \url{https://github.com/eunomia-bpf/bpf-bench}."

**核实过程**：
```
$ curl -s -o /dev/null -w "%{http_code}\n" https://github.com/eunomia-bpf/bpf-bench
404
$ curl -s -o /dev/null -w "%{http_code}\n" https://github.com/eunomia-bpf
200
$ gh api repos/eunomia-bpf/bpf-bench
{"message":"Not Found", ...}
```
`eunomia-bpf` 这个组织本身存在且公开，但 `bpf-bench` 这个仓库名不存在（404）。通过 GitHub 搜索 API 定位到真正的公开仓库：

```
$ gh api "search/repositories?q=bpf-bench+org:eunomia-bpf"
{"full_name":"eunomia-bpf/bpf-benchmark", "private": false,
 "description":"AI Agent eBPF optimization benchmark and framework",
 "topics":["agents","benchmark","bpf","ebpf","ebpf-jit","jit","kernel",
           "koperation","llm","llvm","optimization","performance"],
 "stargazers_count": 22, "pushed_at": "2026-07-11T06:52:32Z", ...}
```

并且**本地仓库自己的 git remote** 就印证了这一点：
```
$ git config --get remote.origin.url
https://github.com/eunomia-bpf/bpf-benchmark.git
```

即：真实仓库名是 `bpf-benchmark`（正是当前工作的这个仓库），而不是 `bpf-bench`——少了 "mark" 四个字母。这个错误不只出现在 overview.tex 里，`docs/ebpf27-bpfoptbench/main.tex:62`（bpf-bench 论文自己的 abstract 结尾："\sys is available at \url{https://github.com/eunomia-bpf/bpf-bench}"）也是同样的错误，说明这是一个从 bpf-bench 论文继承下来、贯穿多篇文档的拼写错误。

**作为 proxy 验证仓库内容是否支持 "Every component already exists" 的说法**：本地仓库确实包含
- `bpfopt/shim/libbpfrejit_shim.c`（BpfReJIT 的 shim）
- `bpfopt/`（bpfopt CLI 本体）、`corpus/`、`runner/`、`micro/`（benchmark 套件）
- `bpfopt/kopprober`、`llvm-backend/build-bpf-kop*`（Kops/KOperation 相关的识别器与内核模块构建产物）

这部分内容支持"组件已作为工作原型存在"的说法；**唯一的问题是链接本身写错了，导致任何评审点击都会得到 404**，这是一个非常容易被抓到、也非常容易修复的错误，必须在提交前改正为 `https://github.com/eunomia-bpf/bpf-benchmark`。

---

## 三、biblio.bib 外部核实清单（对应 claim #15）

| bib key | 声称的 venue/年份/作者 | 核实结果 |
|---|---|---|
| `zheng2026kops` | arXiv 2606.24213, "Kops: Safely Extending the eBPF Compilation Pipeline with Native Operations" | 与 `docs/paper/` 本地论文标题、作者列表（Zheng, Ji, Tao, Sun, Zhang, Williams, Quinn）完全一致；arXiv ID 格式（26=年，06=月）与当前日期 2026-07 吻合。**CONFIRMED**（内部一致性核实，非公开 arXiv 页面直接抓取核实，因为该 ID 目前应仍是占位/待发布状态）。 |
| `xu2021synthesizing`（K2） | SIGCOMM '21 | 真实存在的论文（Xu et al., "Synthesizing safe and efficient kernel extensions for packet processing"），DOI 10.1145/3452296.3472929 正确。**CONFIRMED** |
| `mao2024merlin`（Merlin） | ASPLOS '24 | 真实存在，DOI 10.1145/3620666.3651387 正确。**CONFIRMED** |
| `zhu2025epso`（EPSO） | ASE '25 | 真实存在，DOI 10.1109/ASE63991.2025.00242 正确。**CONFIRMED** |
| `nelson2020specification`（Jitterbug） | OSDI '20 | 真实存在的著名论文。**CONFIRMED** |
| `vishwanathan2023verifying`（Agni） | CAV '23 | 真实存在。**CONFIRMED** |
| `gershuni2019simple`（PREVAIL/Gershuni） | PLDI '19 | 真实存在的经典论文。**CONFIRMED** |
| `jia2025rex`（Rex） | USENIX ATC '25 | 经 WebSearch 外部核实：真实论文 "Rex: Closing the Language-Verifier Gap with Safe and Usable Kernel Extensions"，作者 Jinghao Jia, Ruowen Qin 等，ATC'25 pp. 325–342。**CONFIRMED** |
| `panchenko2019bolt`（BOLT） | CGO '19 | 真实存在的经典论文（Panchenko et al.）。**CONFIRMED** |
| `zheng2025extending`（bpftime） | OSDI '25 | 经 WebSearch 外部核实：真实论文 "Extending Applications Safely and Efficiently"，作者 Yusheng Zheng, Tong Yu, Yiwei Yang, Yanpeng Hu, Xiaozheng Lai, Dan Williams, Andi Quinn，OSDI'25 pp. 557–574。作者列表与 bib 条目逐一对应。**CONFIRMED** |
| `yang2025egpu`（eGPU） | HCDS '25 | 经 WebSearch 外部核实：真实论文，发表于 "4th Workshop on Heterogeneous Composable and Disaggregated Systems"（HCDS '25，2025-03-30，鹿特丹），作者 Yiwei Yang, Tong Yu, Yusheng Zheng, Andrew Quinn，DOI 10.1145/3723851.3726984 正确。**CONFIRMED**（注：bib 里作者名是 "Quinn, Andrew"，main.tex 里 PI 署名是 "Andi Quinn"——Andi 是 Andrew 的昵称，同一人，不是错误。） |
| `huang2025epass`（EPASS） | eBPF Foundation Research Grant project, 2025 | 经 WebSearch 外部核实：Ryan Huang（University of Michigan）2025 年获 eBPF Foundation $50K 资助，项目 "Verifier-Cooperative Instrumentation" 产出 EPASS 框架，"resolved about 91% of programs incorrectly rejected"——与 bib 摘要（"Resolved 91% of previously rejected-but-safe programs"）逐项吻合。**CONFIRMED** |

**结论**：抽查的 12 条非"unused"bib 条目里，venue、年份、作者、DOI 均未发现错误。

---

## 四、提交前必须修复的清单（按优先级）

1. **【严重，务必修】** GitHub 链接 `https://github.com/eunomia-bpf/bpf-bench` → 改成 `https://github.com/eunomia-bpf/bpf-benchmark`（overview.tex line 21）。同一错误也存在于 `docs/ebpf27-bpfoptbench/main.tex:62`，建议一并修正（虽然该文件不在本次核查授权修改范围内，仅供参考）。
2. **【应修】** "characterization over 54 microbenchmarks"（overview.tex line 5）→ 应为 **27**（与 Kops 论文当前 `3-characterization.tex` 一致）；"54" 只存在于已废弃的旧稿。
3. **【应修正归因，或换数据】** "A NativeBPF native-execution preview ... reaches 2.358× on Cilium" —— 2.358× 实际来自 Kops 论文的 native-in-kernel upper-bound 实验，不是 NativeBPF 项目的产出；NativeBPF 自己的 preview 数字是 1.349×/1.056×（workload）与 1.478×/1.429×（微基准）。建议改用正确归因或正确数字。
4. **【提交前应验证】** "BpfReJIT provides the first" 的新颖性断言——BpfReJIT 论文自己的 related-work 里这部分还有未完成的 TODO（"add and verify the closest runtime eBPF specialization citations before submission"），建议先完成这项查新，或在措辞上更保守。
5. **【建议知悉，不强制修改】** "Cilium and Katran datapath throughput by up to 12%" 的"12%"来自 RQ3 消融实验变体（1.114×），而非 RQ2 默认策略头条结果（1.074×/1.073×）；这是 Kops 论文自己 abstract 里的写法，overview 只是忠实转述，非提案作者编造，但作者应知悉这个数字的真实出处以应对评审追问。

---

## 五、正面结论

除上述 5 项之外，overview.tex 中对 Kops、BpfReJIT、bpf-bench 论文的绝大多数数字引用（seven operations、24%/22%、42%、12–23% 代码收缩、no measurable load-time overhead、0.995× Katran、5.4% Cilium gap、0.949/1.113 branch_flip 数据、146 programs/42 microbenchmarks/34% speedup、六个 app 与仓库现状的对应关系）都能在对应源论文章节中找到逐字或高度一致的原文支撑，biblio.bib 的 venue/年份/作者信息经外部核实全部准确。整体提案的事实基础是扎实的，主要问题集中在一个失效链接、一个过时数字、一个归因错配、一个尚待验证的新颖性断言。

---

## 后续裁定（2026-07-13，与作者确认后）

- **发现 3（2.358× 归属）— 撤销**：作者确认 2.358× 属于 kprog/NativeBPF preview 数据集，
  是 **Cilium 单应用值**；kprog 论文的 1.349×/1.056×（workload）与 1.478×/1.429×（micro）
  是跨应用几何平均，二者同源不矛盾。proposal 保留 "A NativeBPF native-execution preview ...
  reaches 2.358× on Cilium"，"on Cilium" 已限定口径。
- **发现 4（BpfReJIT "first" 声明）— 已按删除处理**：作者直接删除了该句（连同 Rust/BOLT
  对比句），jia2025rex 与 panchenko2019bolt 不再被引用。
- **发现 1（URL）与发现 2（54→27）**：已修复并核实（bpf-benchmark 返回 200；27 来自
  3-characterization.tex:141）。注意 bpfoptbench 论文（ebpf27-bpfoptbench/main.tex:62）
  的同款错误 URL 尚未修复。

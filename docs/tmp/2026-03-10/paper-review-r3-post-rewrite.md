# BpfReJIT 第三轮审稿意见（改写后版本）

**审稿人**：模拟资深 PC 成员（第三轮，参照 Opus R1 4/10、Codex R2 6/10）
**论文版本**：改写后版本（`docs/paper/paper.tex`，当前主分支）
**参考材料**：
- Opus 评审（`paper-sosp-review-opus.md`）
- Codex 评审（`paper-sosp-review-codex.md`）
- 跨领域 census 结果（`cross-domain-directive-census.md`）

---

## 1. 综合评分：6.5/10（弱接受/弱拒绝边界）

相比 Opus 的 4/10 有明显提升，与 Codex 的 6/10 持平略高。这一版本的主要进步在于：（1）将 Halide 类比从主轴降格为从属说明；（2）引入 policy-sensitive 与 substrate family 的明确二分法；（3）新增 fixed-kernel-baseline 实验作为关键对照；（4）增加了跨领域 census；（5）增加了 worked example 和设计备选方案的正当化论证。但仍然无法达到 OSDI/SOSP 接受门槛，核心瓶颈（缺少端到端部署、政策敏感性证据仍薄弱、LEA 回归的叙事自相矛盾）尚未解决。

---

## 2. 故事连贯性评估

### 整体叙事结构

改写后的论文有了清晰的主线：

> "BPF JIT 质量有缺口 → 固定 kernel heuristic 失败（因为 CMOV policy-sensitive，以及组合干扰）→ BpfReJIT 分离 mechanism/policy → 评估验证"

这个骨架比之前强得多。Abstract（第 53–79 行）已经把两个核心论点（policy-sensitivity 和 combination interference）都点出来，Introduction（第 134–145 行）用 "We built exactly that baseline" 开头直接引出 fixed-baseline 实验，这是第一次在引言里有实质性反驳而不只是宣称。

### 二分法分类（§1, §3.4）

Policy-sensitive families / Substrate families 的区分（第 166–180 行）是这次改写的最大进步之一，直接回应了 Codex W1（"另外三个 family 更像常规 kernel peepholes"）。但分类本身引出了一个新的叙事问题：**如果 substrate family 本质上是"fixed kernel 也能做"的事，那么 framework 针对这三个 family 的价值论证能否支撑"mechanism/policy separation 是一个 general design principle"的主张？** 当前文本（第 527–542 行）给出了三个理由（更新频率、组合效应、共享基础设施），但这些理由力度不均，见"新问题"节。

### 从 Motivation 到 Design 的过渡

第 365–368 行（"The mechanism we need is not a better heuristic but a better interface"）作为桥梁句已经明确，比之前版本更好。Worked example（§3.2，第 441–475 行）具体展示了 policy blob → 内核验证 → 发射的流程，有效地把 slogan 变成了可检验的语义描述。

---

## 3. 旧评审意见逐条核查

### Opus W1：政策敏感性只基于一个 benchmark → 已部分解决（但仍不足）

**做了什么：**
- 引言（第 134–145 行）新增了 LEA 在 `stride_load_16` 上的 +141% 回归作为第二个 policy-sensitivity 证据。
- Table 3（第 310–324 行）展示了 switch\_dispatch、binary\_search、bounds\_ladder、large\_mixed\_500 四个 benchmark 的 cmov ablation 结果，证明了不同 benchmark 方向相反。
- §3.1 正式区分了 policy-sensitive 和 substrate family，并承认"only CMOV currently demonstrates clear bidirectional policy sensitivity"（第 959–960 行）。

**仍然不足：**
问题从"1个benchmark"变成了更深层的问题："policy-sensitivity 的核心论点（CMOV）依赖 llvmbpf ablation（Table 3），而不是 kernel JIT 本身的实验。" Opus W5 指出这个 disconnect，见下。

LEA 的例子（`stride_load_16` +141%）被论文作为"组合干扰"而非"policy-sensitivity"使用（§2.4 标题是 "Combination interference"），但 Table 6（第 747–751 行）实际上表明 LEA-only 单独就造成了 +141% 的回归，这不是"组合"而是 LEA 单独的副作用。这里的叙事框架和数据有分歧，将引发审稿人质疑。

### Opus W2：没有端到端部署 → 未解决（诚实承认）

论文在 §5.3 末尾（第 848–861 行）和 §6 Limitations（第 980–989 行）明确承认 "end-to-end deployment evaluation with throughput measurement is future work"。

这是诚实的立场，但不能改变这一弱点的性质。值得肯定的是，论文不再用 "60/60 recompile success" 硬撑成部署结果——这比之前版本克制。但对于 OSDI/SOSP 审稿人而言，缺少端到端结果仍是关键缺陷，任何数量的 future work 声明都不能替代一个真实 PPS 数字。

### Opus W3：四个 rule family 不是"generality" → 有进步但仍薄弱

**做了什么：**
- 引入 policy-sensitive / substrate 分类，明确降低了对"generality"的主张（第 958–960 行：只有 CMOV 有清晰的双向 policy-sensitivity）。
- §3.5（第 590–632 行）用 v5 declarative pattern 解释为什么 kernel 可以保持 stable at ~4 canonical forms。
- 跨领域 census（§5.5，第 908–944 行）用 514 objects、444,610 条指令的扫描证明 directive site 在多个领域都存在。

**仍然不足：**
substrate family 的"framework 价值"论证主要来自"更新频率"（ROTATE 需要 3 轮 pattern 扩展），这是工程便利性而非 generality。一个持怀疑态度的审稿人会说："这是 pattern-matching hygiene，不是 mechanism/policy separation 的 general principle。"

### Opus W4：Halide 类比误导 → 已解决

**做了什么：**
§5 Related Work（第 1021–1027 行）把 Halide 降格为"borrows the principle"，明确说明"operates at a much narrower scope" 和 "much stronger safety constraints"。这直接回应了 Codex 和 Opus 的一致批评。

引言中不再把 Halide 作为主要定位框架；第 147–153 行的 "Key insight" 段用了"kernel/userspace interface boundary"的表述而非 Halide 类比。

**评价：** 这是改写中最彻底的改进之一。

### Opus W5：Table 4 在错误的系统中测量 → 已部分解决（但仍有问题）

**做了什么：**
Table 3（第 310–324 行）的 caption 增加了一句话（第 312–313 行）："Validated in the kernel JIT via BpfReJIT re-JIT (§5.2)"。Table 5（第 765–788 行）在 kernel JIT 中直接测量了 COND\_SELECT 强制应用的 regression（383.5→590.0ns）。

**仍然有问题：**
Table 3 使用 llvmbpf 数据作为主要的 policy-sensitivity 展示，然后在 §2.4（第 307–308 行）用一句话说"我们在 kernel JIT 中验证了这一点"，但这个"验证"是通过 BpfReJIT **强制** 应用 CMOV 产生的（一个有害的应用），而不是展示 CMOV **有益**时在 kernel JIT 中的数据。审稿人会问：`switch_dispatch` 在 kernel JIT 中加 CMOV 是否也有 +26% 的提升？这个数据在整篇论文中仍然缺失。这是 Opus W5 的核心，仍然没有完全解决。

### Opus W6（RQ1 属于 Motivation）→ 已解决

改写后的 Evaluation section（§5，第 684–692 行）把结构改为四个轴：fixed-kernel-baseline、selective re-JIT effectiveness、safety/compatibility、extensibility。不再有一个独立的 "RQ1: How large is the gap?" 在 Evaluation 里重复 Motivation 的内容。

### Codex W1：novelty 太接近"compiler flags" → 有进步但未完全解决

**做了什么：**
第 147–153 行将 insight 表述为"新的 kernel/userspace interface boundary"而不是"四个 peephole"。二分法分类和 worked example 让 mechanism/policy separation 的含义更具体了。

**仍然不足：**
一个资深审稿人读完 §3.3 的 syscall interface（第 477–495 行）和 §3.4 的 rule families（第 497–542 行）后，仍然会想："这基本上是一组 per-site 的 compiler flag，通过 syscall 传入。" 论文还需要一个更有力的论证：为什么这个 interface 优于 (a) load-time flags (b) 一个简单的 JSON 配置文件驱动的 kernel module？第 430–439 行（Design alternatives）提到了 load-time hints，但论证不够深入。

### Codex W2：缺少 decisive fixed-kernel baseline → 已解决（这是改写最大亮点）

这是本次改写最显著的进步。§5.1（第 700–763 行）和 Table 4（第 711–733 行）提供了完整的 per-directive isolation 实验：6 个 benchmark × 6 个 kernel build（stock, CMOV-only, ROTATE-only, WIDE-only, LEA-only, fixed-all）。

结果清晰支持论文 thesis：
- CMOV-only 唯一修改了 log2\_fold 的 codegen，并造成 19.7% 的 regression。
- LEA-only 帮助 stride\_load\_4（-11.9%）但严重损害 stride\_load\_16（+141.4%）。
- 最关键的：selective BpfReJIT 在 stride\_load\_16 上取得了 +5.2% 的改善（§5.2，第 797–803 行），证明了选择性应用优于全量应用。

这是"固定 heuristic 不够，需要 userspace policy"的直接证据，比之前的任何版本都有力。

### Codex W3：RQ1 和 Motivation 重叠 → 已解决（见 Opus W6）

---

## 4. 改写引入的新问题

### 新问题 N1：LEA 叙事框架与数据不一致（重大问题）

论文在两处以不同方式描述 LEA 的表现：

1. §2.4（第 335–344 行）将 LEA `stride_load_16` 的 +14.2% 回归标记为"Combination interference"，暗示是多个 family 联合的结果。
2. Table 4（第 728 行）显示 **LEA-only 单独**就造成 `stride_load_16` +141.4% 的回归（$\dagger$ 标记缺失，说明这是真实的代码生成改变，不是噪声）。

但在 §2.4 的 "fixed\_preview" 表格（Table 2，第 359 行）中，fixed-all 下 stride\_load\_16 是 +14.2%，而 Table 4 中 LEA-only 是 +141.4%。这两个数字来自不同实验（Table 2 来自一个较早的 fixed-all baseline，Table 4 来自 pinned VM 实验），但论文没有解释为什么两个实验的同一 benchmark 数字差别如此之大（14.2% vs 141.4%）。

审稿人会立即注意到这个矛盾并质疑实验方法。

### 新问题 N2：stride_load_16 的 BpfReJIT 结果与 fixed-kernel 结果直接矛盾（需要解释）

Table 4（第 728 行）：LEA-only kernel 使 stride\_load\_16 +141.4%。
Table 5（第 784 行）：BpfReJIT ADDR\_CALC 在 stride\_load\_16 上取得 1.052× 改善（p=0.012）。

论文在第 797–803 行解释了这个差异：BpfReJIT "applies LEA selectively only where the userspace scanner identifies profitable sites, whereas the kernel-fixed baseline applies it unconditionally at every eligible site."

这是论文 thesis 的核心证据，**但当前对解释的重视程度不够**。这个对比应该是论文的高光时刻，但它被埋在两段之间，没有一个专门的图或框框凸显。如果这个对比没有被审稿人注意到，论文的关键证据就失效了。

### 新问题 N3：cross-domain census 缺少对 LEA 覆盖率为零的解释

Table 5（第 919–930 行，census 结果表）显示 LEA 在所有领域的覆盖率为 0。但 ADDR\_CALC 是四个 rule family 之一，在 evaluation 中也有结果。Census 方法论说明（第 1237–1240 行）解释了扫描方法，但没有解释为什么 LEA 扫描结果为零而 BpfReJIT 实验中有 LEA sites。这个不一致会让审稿人困惑：scanner 是否实现了 LEA pattern 的扫描？或者 census 使用了不同的 pattern？

### 新问题 N4："binary search 不是 O(1)"的实现说明

§4（第 672 行）："Rule lookup is O(1) via sorted-array binary search on site offset."

Binary search 是 O(log n)，不是 O(1)。这可能是笔误（原意可能是"每次查询的成本是 O(log n) 即近似常数"），但会被审稿人抓住。如果 rule 数量很少（比如 10 条），那么常数因子确实可以忽略，但这需要说明。

### 新问题 N5：Cilium 加载失败的定性处理过于轻描淡写

§5.3（第 847–851 行）把 Cilium 加载失败归因于 "BTF compatibility" 和 "libbpf loading issues, not BpfReJIT limitations"。

审稿人（尤其是熟悉 BPF 社区的）会知道 Cilium 是最重要的生产 BPF 部署之一（bpf_xdp.bpf.o 有 26,129 条指令，408 个 CMOV sites，见 census 数据）。在评审方面，无法加载最高价值的生产程序是重大弱点，用一句 "libbpf loading issues" 带过不会让审稿人满意。至少需要说明已经尝试了哪些解决方法，以及为什么这是 tractable 的未来工作而不是根本性限制。

---

## 5. Census 整合评估

### 数据完整性

Census 表格（Table 5，§5.5）数据来源于 `cross-domain-directive-census.md`，覆盖 514 objects、444,610 条指令，跨 5 个领域，分类清晰。

### 叙事整合质量：中等

**做得好的地方：**
- 第 935–939 行识别了 CMOV 在 tracing 领域（BCC tools）的分布模式（20/57 objects，histogram-binning 是重要应用场景），这是一个有意义的观察，超出了"机械计数"。
- Takeaway（第 941–944 行）明确将 census 连接到 policy-sensitivity 论点："the policy-sensitive family that motivates mechanism/policy separation is present across BPF program domains." 这是正确的叙事挂钩。

**做得不够的地方：**

1. **LEA 覆盖率为零未被解释**（见新问题 N3）。

2. **Cilium 有 408 个 CMOV sites（bpf_xdp.bpf.o），却在 §5.3 中无法加载**——这个矛盾没有在 census 段落中处理。审稿人看到 census 中 Cilium 有大量 site，再看到 §5.3 说 Cilium 加载失败，会对论文的可信度产生疑问。

3. **Census 只说了"sites 存在"，没有说明 site 的 policy-sensitivity 如何**。例如 BCC tracing tools 的 CMOV sites——这些程序的分支是否 data-dependent？如果 tracing 程序通常在内核态运行，branch predictability 是否不同于网络数据面？一句话的分析会大大增加 census 的说服力。

4. **loxilb 有 863 个 WIDE sites（最多单一来源），但 loxilb 在 §5.3 中因"non-standard ELF section names"而无法加载**。这再次形成了"census 覆盖 loxilb 但实验无法测试 loxilb"的矛盾，需要说明。

5. **Table 5 的 "Testing" 行**：ROTATE 有 1,810 sites（几乎全来自 linux-selftests），这实际上是内核自测代码，对外部部署的意义有限。论文没有区分 "testing code" 和 "production code" 的 site 分布含义。

### 对"generality"论证的贡献

Census 解决了 Opus W3 的一部分：证明了 directive site 不局限于论文使用的 6 个 benchmark 程序，而是广泛存在于真实代码中。CMOV 跨越 networking、tracing、security 三个领域出现（1,237 total），这是 generality 的有效支撑。

但 Census 无法解决 Opus W3 的核心：**4 个 rule family 在结构上仍然不是一个"general principle"**，而更像是"4 个手工发现的 peephole + 一个通用框架"。Census 证明了 site 的存在性，但没有证明 policy-sensitivity 的广泛性。

---

## 6. 达到 8/10 还需要完成的三件事

### Gap 1：需要一个 kernel JIT 层面的 CMOV benefit 数据点（最高优先级）

当前论文证明了 CMOV 在 kernel JIT 中**有害**（log2\_fold 在强制 CMOV 后 +34.5%）。但完整的 policy-sensitivity 需要同时证明 CMOV 在 kernel JIT 中**有益**。Table 3 使用的是 llvmbpf 数据（switch\_dispatch +26.3%），而不是 kernel JIT 数据。

需要：在 kernel JIT 中对一个 unpredictable-branch benchmark（如 switch\_dispatch 或 binary\_search）应用 BpfReJIT COND\_SELECT，测量 speedup。如果该实验的结果与 llvmbpf 的 Table 3 数据一致（即 switch\_dispatch 在 kernel JIT 中也因为 CMOV 而变快），则"CMOV policy-sensitive 且 kernel JIT 中有效"的论点才完整。**这是一个可在几天内完成的实验。**

### Gap 2：需要一个 end-to-end 数字（即使小也行）

论文诚实地承认 end-to-end deployment 是 future work。但哪怕一个最小的 end-to-end 数字都会从根本上改变 OSDI/SOSP 评审的接受意愿。

具体建议：选择 Katran 的 `balancer.bpf.o`（census 中有 29 个 sites：5 CMOV + 4 WIDE + 20 ROTATE，见 census 详细表格），在一个简单的 XDP testbed 上测量 PPS。即使 Katran 整体效果不显著（因为 site 数量相对于程序规模不大），"我们尝试了 Katran"本身就说明了实验的认真程度。Calico 的 from_hep_debug.bpf.o 有 62 个 sites，也是候选。

### Gap 3：解决 stride_load_16 的数字矛盾（修改稿必做）

如前所述（新问题 N1），Table 2 中 stride\_load\_16 在 fixed-all 下是 +14.2%，Table 4 中 LEA-only 是 +141.4%。这个看似矛盾的数字（一个 specific family 造成的损害大于 all-combined 的损害）没有解释，将导致审稿人对实验可重复性产生严重质疑。

需要：在 Footnote 或正文中明确说明这两个实验的不同之处（不同的 kernel build 方法？不同的测量环境？），或者统一实验条件使两组数字来自同一环境。这不需要新实验，只需要清晰的文字说明。

---

## 7. 分节细节说明

### Abstract（第 53–79 行）

相比之前版本明显更强：提到了 policy-sensitive 和 combination interference 两个论点，也提到了 fixed-all 的 LEA regression。但第 63–65 行（"LEA fusion causes a 141% slowdown on one benchmark"）中的数字和 Table 4 中的 +141.4% 一致，但论文正文 §2.4 中 Table 2（fixed\_preview）给的是 +14.2%（stride\_load\_16 在 fixed-all 下）——abstract 用的是 LEA-only 的数字而 Table 2 用的是 fixed-all 的数字，这个不一致在 abstract 里就已经出现，需要统一。

### Section 2（第 204–368 行）

第 287–290 行对 root cause 的 89% 分解（byte-load 50.7%、absent cmov 19.9%、callee-saved 18.5%）是强有力的 characterization。§2.4 的两个证据（policy-sensitivity + combination interference）结构清晰，但如上所述存在叙事和数据的一致性问题。

第 327–333 行（"Why static analysis is insufficient"）是一个很好的进步：明确了"branch predictability depends on runtime input distributions, not just program structure"，并给出了"packet classification against a hash table"作为具体例子。但这个论点仍然停留在理论层面——没有展示一个具体的 BPF 程序，其 branch predictability 在两个不同的部署环境中实测不同。这个论点对有 BPF 背景的审稿人来说仍然可以被反驳（"对于大多数 BPF 程序，通过 BTF/map 配置可以推断出足够的信息"）。

### Section 3（第 370–633 行）

§3.2 Worked Example（第 441–475 行）是改写中的明显进步，把 mechanism/policy separation 从 slogan 变成了可操作的语义流程。§3.5 Declarative Pattern Extension（第 590–632 行）比之前版本充实了很多，"32-LOC descriptor" 的具体例子有说服力。

§3.3 的 syscall interface（第 477–495 行）中 `log_level`/`log_buf`/`log_size` 字段的出现说明 logging interface 已经设计好，但 Opus W6 提到"no logging implemented"——如果 logging 在 evaluation 中没有使用，需要说明这些字段的实现状态。

### Section 4（第 635–681 行）

第 672 行的 "O(1) via sorted-array binary search" 是一个术语错误（binary search 是 O(log n)）。其余内容紧凑合理。

### Section 5（第 683–944 行）

§5.1 的 per-directive isolation table（Table 4，第 724–733 行）是论文的最强证据，但有 $\dagger$ 标记使用不一致的问题：rotate64\_hash 在 LEA-only 下有 +60.6% 的 $\dagger$（标记为"codegen unchanged; delta is measurement noise"），但同一程序在 ROTATE-only 下有 -12.1%（没有 $\dagger$）——这是正确的（LEA 没有改变 rotate 程序，ROTATE 改变了）。但 stride\_load\_16 在 ROTATE-only 下有 +131.4% 的 $\dagger$（标记为噪声），这个数字高达 131% 作为"噪声"令人难以置信，需要更多解释（也许是确实代码没有变化但 timing 因为其他因素波动了这么大？）。

### Section 6（第 946–989 行）

Discussion 部分（特别是第 959–960 行："We are transparent that only CMOV currently demonstrates clear bidirectional policy sensitivity"）比之前版本更诚实，这会增加审稿人对论文可信度的评价。"Falsification condition" 的精神保留在了诚实的 scope-of-claims 声明中（第 963–967 行）。

### Section 7（第 991–1040 行）

§7 中 feedback-directed JIT compilation（第 1012–1019 行）和 kernel live patching（第 1035–1040 行）的新增比较解决了 Opus §5.Related Work 的两个缺失点。Halide/TVM/XLA 的定位已经纠正（第 1021–1027 行）。

---

## 8. 总结：达到当前 6.5/10 的主要功劳和限制

**本次改写的功劳（相比 Opus 4/10 的进步）：**
1. Fixed-kernel-baseline 实验（§5.1）：最重要的新增，直接回应了 Codex 的关键缺陷。
2. Policy-sensitive / Substrate 二分法：让 generality 主张更诚实。
3. Worked example（§3.2）：机制描述具体化。
4. Halide 类比降格：叙事更可信。
5. "Why static analysis is insufficient"（§2.4）：给出了理论论证。
6. 跨领域 census（§5.5）：拓展了 directive site 的覆盖范围证明。
7. 诚实的 scope-of-claims（§6）：增加了可信度。

**仍然是 reject 的主要手柄：**
1. CMOV 在 kernel JIT 中只有"有害"方向的实验，缺少"有益"方向的 kernel JIT 数据。
2. 零端到端吞吐量数字。
3. stride\_load\_16 在两个表格中的数字矛盾（14.2% vs 141.4%）未解释。
4. LEA census 覆盖率为零与 ADDR\_CALC family 的存在之间的不一致。
5. Cilium 和 loxilb 无法加载，而 census 中它们是 site 最多的来源之一。

# BpfReJIT: Optimization Directions Beyond Instruction Selection

Date: 2026-03-11

## 1. Bottom Line

结论先行：

1. **有。比 instruction selection 更有 novelty 的方向至少有三类：**
   - **profile-guided control-flow region specialization**
   - **verifier-fact-guided late specialization**
   - **typed semantic region composition**
2. **最不该做的“泛化”**不是再加一个 userspace rewrite DSL，而是让 kernel 去解释用户提供的通用 rewrite program。那会把当前 fail-closed 边界变成“kernel 内置语义证明器/解释器”，安全模型会急剧恶化。
3. **最合理的接口升级**不是 “one pattern -> one emitter” 的无限扩展，也不是 generic rewrite interpreter，而是：
   - `kernel-owned site kinds`
   - `kernel-owned region families`
   - `optional fact predicates / fact refs`
   - `finite native plan IDs`

一句话总结：

> **v5 的上限是 local instruction selection；下一步真正有论文 novelty 的，是 region、facts、composition。**

---

## 2. Why v5 Hits A Ceiling

当前 v5 的核心边界已经非常清楚：

- `jit_directives.c` 只接受**有限 canonical forms**，并按 `canonical_form + native_choice` 进入 kernel-owned emitter，见 `bpf_jit_canonical_form_valid()`、`bpf_jit_native_choice_valid()`、`bpf_jit_try_emit_rule()`。
- pattern 仍然是 **contiguous local region**，而且 `pattern_count == site_len`，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:1843-1879`、`2063-2205`。
- rule lookup 本质上是 **按 `site_start` 精确命中**；即使 rule 覆盖一个 interval，也只有 `insn_idx == rule->site_start` 时才会触发，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:2373-2409`。
- kernel 通过 `bpf_jit_has_interior_edge()`、`site_has_side_effects()`、`within_single_subprog()` 把变换限制在 **无 side effect、无外部 interior edge、单 subprog 的本地区域**，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:414-478`、`1919-1935`、`1938-1974`。
- x86 JIT 的 prologue/epilogue 根本不在 per-insn dispatch 路径里，当前 UAPI 也无法命名这些 site，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:514-565`、`3351-3377`、`4406-4432`。

因此，v5 适合：

- many-BPF-shapes -> one native emitter
- local pattern validation
- per-site native choice

但它**天然不适合**：

- basic block layout / fallthrough placement
- entry/exit/prologue specialization
- verifier-fact-guarded variant selection
- inter-region composition
- general CFG relayout

---

## 3. Direction-by-Direction Assessment

下面按你给的 A-E 来看。

### A. Peephole 之外，BPF->native 还有什么优化？

#### A1. Single-entry/single-exit control-flow layout

这是我认为**最强**的 beyond-isel 方向。

原因：

- x86 JIT 的分支发射仍然是 source-order、`addrs[]`-driven 的线性 emitter，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4221-4404`。
- 当前 characterization 里 **branch/control-flow 占 19.9% backend surplus**，而 `branch_layout` benchmark 对输入分布有 **44.6% sensitivity**，见 `docs/kernel-jit-optimization-plan.md:127-136`。
- 这类优化不是 “把 3 条 BPF 变成 1 条 x86”，而是**改变哪个 block fallthrough、哪个 block taken、是否 tail-duplicate cleanup**。

收益估算：

- `exec time`: **中到高**。对 branch-heavy 程序可达双位数局部收益；对整个 suite，更保守的推断是 **2-6%** 级别。
- `code size`: **中性到小幅波动**。只做 fallthrough flip 时接近中性；做 cleanup tail-dup 可能略增。

实现复杂度：

- **中高**。需要 region validator + region emitter，而不是再加一个普通 peephole emitter。

与 K2/Merlin/EPSO 的关系：

- **完全正交**。它们可以改 CFG，但**不能替同一份 BPF 选择 native fallthrough / jcc polarity / exit block placement**。

安全模型：

- **可以 fit**，但必须限于 **contiguous, SESE, local CFG region**。
- 不宜上来就做 arbitrary CFG reorder；先做 closed diamond / short ladder 最安全。

结论：

- **非常值得做，且是 Top 1 候选。**

#### A2. Function-boundary specialization (prologue/epilogue/entry/exit)

这类优化 practical value 很高，但 novelty 略低于 control-flow region。

原因：

- characterization 里 **prologue/epilogue 占 18.5% backend surplus**，见 `docs/kernel-jit-optimization-plan.md:129-132`。
- 现有 x86 prologue 明确留了固定 patch window 和 layout contract，甚至源码里直接写了 “waste 5 bytes for now and optimize later”，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:525-537`。

收益估算：

- `code size`: **中高**，尤其对短程序和 tracing 程序。
- `exec time`: **低到中**，总体大概率不如 control-flow。

实现复杂度：

- **中等**。核心难点不是 emitter，而是先把 entry/exit 变成 first-class site。

与 K2/Merlin/EPSO 的关系：

- **完全正交**，因为 BPF ISA 根本没有 prologue/epilogue。

安全模型：

- **可以 fit**，用 `FUNC_ENTRY` / `FUNC_EXIT` site kind 即可。

结论：

- **强 practical direction，但论文 novelty 稍弱，不进我的 Top 3。**

#### A3. Liveness-sensitive save/restore and scratch management

这是介于 peephole 和 global optimization 之间的方向。

原因：

- x86 `div/mod` 明确有 `push rax/push rdx` 和 restore 路径，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3618-3683`。
- variable shift 非 BMI2 路径也有 `push rcx` / restore，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3729-3784`。
- 这已经不是简单 isel，而是**由 successor liveness 决定 scratch-saving discipline**。

收益估算：

- `exec time`: **低到中**，局部热点上可能明显。
- `code size`: **低到中**。

实现复杂度：

- **中等**。如果只做 `DIV_LIVENESS`，工作量可控；若扩展成通用 scratch-pressure model，则会明显变大。

与 K2/Merlin/EPSO 的关系：

- **正交**。它们碰不到 x86 `rax/rdx/rcx` 约束。

安全模型：

- **可以 fit**，前提是 kernel 自己重验 liveness facts。

结论：

- **值得做，但最好作为 verifier-fact-guided specialization 的第一站，而不是单独讲成论文主贡献。**

#### A4. Arbitrary CFG reordering / full scheduler / instruction scheduling

这类方向 novelty 很高，但**不适合当前安全边界**。

原因：

- 当前 JIT 是 convergence loop + `addrs[]` 体系，branch displacement、tail-call patchability、shared cleanup 都绑在一起，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3448-3455`、`4289-4404`、`4406-4465`。
- 这已经不是 site-local rewrite，而是 whole-function layout problem。

结论：

- **有研究价值，但不是 v6/v7 的正确第一步。**

---

### B. 有没有更通用的 safe optimization interface？

有，但**不应该**是 generic rewrite interpreter。

#### B1. 为什么 generic rewrite interpreter 不合适

如果让 userspace 发 “rewrite rules” 或“小型 lowering DSL”，kernel 再通用解释：

- kernel 就要证明这个 rule preserves semantics / safety；
- 证明对象不再是“有限 menu 的 native variants”，而是“用户自定义 rewrite program”；
- 这会把当前 fail-closed 模型，从 `finite validator + finite emitter`，变成 `kernel-side proof checker / semantics interpreter`。

这与现有文档主线冲突：

- v6 明确强调 kernel 仍然要拥有 **safety / validation / native emission**，见 `docs/tmp/v6-interface-design.md:9-27`。
- 当前内核代码也体现了这一点：只有有限 canonical form、有限 native choice、有限 validator/emitter，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:360-410`、`1843-1935`。

我的判断：

- **类似 LLVM TableGen / ISLE 的 userspace-authored lowering rules，不适合作为 kernel UAPI。**
- 这些可以是 **userspace discovery / search language**，但 kernel 接口仍应收敛到有限的 kernel-owned plans。

#### B2. 推荐的泛化方式：region family + plan ID + fact predicates

更安全的方向是：

1. kernel 扩展 **site kinds**
2. kernel 定义有限的 **region families**
3. userspace 只选择 **plan ID / variant ID**
4. 可选地附带 **fact predicates / fact refs**

也就是把接口从：

`pattern -> canonical_form -> emitter`

升级成：

`site_kind + region_family + bindings + optional facts -> kernel-owned plan`

这比 v5 更通用，但仍保留：

- kernel validates
- kernel emits
- userspace 不提供 machine code
- userspace 不提供通用 rewrite semantics

结论：

- **有更通用的 safe interface，但它应该是“typed plan interface”，不是“generic rewrite interpreter”。**

---

### C. 能不能利用 verifier 已有分析？

**可以，而且这是 Top 2 候选。**

关键点不是“先导出更多 verifier internals”，而是：

- userspace **今天已经能从 verifier log 拿到足够多的 discovery facts**
- kernel **自己仍然用真实 verifier state / aux data 重验 legality**

这正是 `docs/tmp/v6-interface-design.md` 的核心结论，见 `31-140`、`565-588`。

#### C1. 最靠谱的事实驱动优化

1. **DIV_LIVENESS**
   - 当 `rdx` 不 live-out 时，避免保守 save/restore
   - 直接对应 `bpf_jit_comp.c:3618-3683`
2. **ZERO_EXT_ELIDE / upper-32-known-zero**
   - 某些显式 zext 只是 verifier patching artifact
3. **Width narrowing / compare narrowing**
   - 当 verifier 知道 `umax <= 255`、`upper32 == 0`、或类型更窄时，选择更短/更低依赖的 native form
4. **Type/provenance-sensitive lowering**
   - packet/map/btf pointer 的 provenance 可以决定 load/guard variant

#### C2. 为什么它比 instruction selection 更有 novelty

- isel 只看 **local syntax**
- verifier-fact-guided specialization 看的是 **abstract state**
- 这把 BpfReJIT 从 “pattern database” 往 “late specialization substrate” 推了一步

#### C3. 收益估算

这是推断，不是已有测量：

- `exec time`: **1-4% suite-level plausible**，对 arithmetic/guard-heavy 热点更高
- `code size`: **1-4%**

如果未来能把 safety model 扩展到 `bounds_window` 一类 retained-fact rewrite，收益可能更高；但那已经不再是当前 v6 的低风险范围。

#### C4. 实现复杂度

- 若只是 `DIV_LIVENESS` 这类单点变体：**低到中**
- 若做成通用 fact-predicate substrate：**中等**

#### C5. 与 K2/Merlin/EPSO 的关系

- **正交**。这些系统不消费 verifier 的 post-check abstract state 来选 native lowering。

#### C6. 安全模型

- **非常契合**，前提是：
  - userspace 用 verifier log 做 discovery/ranking
  - kernel 用真实 verifier facts 重验
  - `fact_ref` 只作为 binding / stale-policy protection，而不是让 kernel 信用户

结论：

- **这是最值得做的 fact-driven beyond-isel 方向。**

---

### D. Semantic region composition

**有潜力，而且它不是“再加一个 canonical form”，而是“减少 canonical-form explosion 的另一条路”。**

#### D1. 为什么这个方向有意思

你给的两个例子都很对：

- `ROTATE(13) + ROTATE(19) -> ROTATE(32) -> nop`
- `WIDE_LOAD(4) + BITFIELD_EXTRACT(shift=8, mask=0xFF) -> 直接 load 第 2 byte`

这类优化的关键不是某一个 pattern，而是：

- **多个已知 semantic atoms 的组合**
- **组合后可能出现抵消、折叠、降级、或重新选择更优 native plan**

这比 instruction selection 更 novel，因为：

- isel 是 many-to-one
- composition 是 **many-known-atoms -> fewer-better-plans**

#### D2. 当前接口为什么做不了

当前 v5 lookup/dispatch 模型有两个天然限制：

1. rule 是按 `site_start` 精确触发的，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:2373-2409`
2. active set 逻辑上希望 non-overlap；v6 甚至建议把 overlap arbitration 放在 parse time，见 `docs/tmp/v6-interface-design.md:378-395`

这意味着：

- 当前框架适合 “一个 region 触发一个 form”
- 不适合 “多个相邻 form 在 kernel 里再组合”

#### D3. 正确做法不是 arbitrary overlap，而是 typed semantic atoms

我的建议不是让 userspace 直接发 rewrite rules，而是：

- userspace 发一个 **typed atom sequence / region plan**
- atom 只能来自 kernel 预定义语义集
- kernel 自己 re-match / normalize / compose / emit

例如：

- atoms: `LOAD_BYTES`, `BFX`, `ROT`, `SELECT`, `ADDR`
- plans: `LOAD_EXTRACT`, `ROT_CHAIN`, `SELECT_CHAIN`, `NOOP_CANCEL`

#### D4. 收益估算

这也是推断：

- 对 packet / parsing-heavy workload，**code size 2-8%** 并不夸张
- `exec time` 大概是 **2-5% suite-level plausible**

依据是：

- `byte-recompose` bucket 本身占 **50.7%**
- `bitfield_extract` 已经是高频族
- 组合优化最可能在 `wide_load + extract`、`extract + endian`、`rotate chain` 上命中

#### D5. 复杂度与风险

- **复杂度高于前两项**
- 但安全上仍可控，只要 kernel 拒绝 arbitrary atoms / arbitrary CFG / disjoint spans

结论：

- **这是 Top 3 候选，但应该做成 typed region plans，而不是 generic rewrite engine。**

---

### E. Hardware-specific optimization and microarchitecture

这里要分成两类看。

#### E1. 值得做但不该单独当主线的

1. **alignment / hot fallthrough placement**
   - 这本质上应该并入 control-flow region specialization
2. **macro-fusion preserving compare+jcc shape**
   - 依赖 block order / branch polarity，仍属于 region layout
3. **MOVBE / BEXTR / RORX**
   - 有价值，但本质仍偏 isel

#### E2. 不建议重压的

1. **branch prediction hints**
   - x86 上没有稳定、强语义的通用软件 hint 可以依赖
2. **过度 microarchitecture-specific scheduling**
   - 跨 CPU family brittle，且 kernel JIT 很难维护

收益估算：

- `exec time`: **0-3% 常见，热点上可能更高**
- `code size`: **通常很小**

结论：

- **可以作为 control-flow/layout family 的附属策略，不建议单独作为论文主轴。**

---

## 4. Recommended Top 3

下面是我认为最值得投入的三条线。

### Top 1. SESE Control-Flow Region Specialization

**一句话描述**

把优化对象从 “几条直线 BPF 指令” 升级为 “single-entry/single-exit 的本地 CFG region”，让 userspace 选择 hot fallthrough / branch polarity / cleanup placement，kernel 验证 region 并重发 native layout。

**为什么比 instruction selection 更有 novelty**

- 它优化的是 **block order 和 control-flow shape**，不是单条 native instruction choice。
- 同一份 BPF，可以合法地有多个 native layout；优选哪一个依赖 workload branch bias，这正是 userspace policy 的天然舞台。

**UAPI / kernel 设计草案**

- 新增 canonical family：`BPF_JIT_CF_CFG_REGION`
- 新增 `site_kind`：沿用 v6 的 `INSN_REGION`，但 region validator 额外要求：
  - contiguous
  - single entry
  - single join
  - no outside interior edge
- `native_choice` 示例：
  - `BPF_JIT_CFG_THEN_FALLTHROUGH`
  - `BPF_JIT_CFG_ELSE_FALLTHROUGH`
  - `BPF_JIT_CFG_DUP_EXIT`（future）
- userspace 提供：
  - region 起止
  - body bindings
  - hot-arm choice
  - optional code-size budget class
- kernel 验证：
  - diamond/ladder shape
  - join 一致
  - interior-edge exclusion
  - subprog containment
- x86 emitter：
  - 重新线性化 blocks
  - 统一更新 region 内 `addrs[]`
  - 可选保留 shared cleanup 或局部 duplication

**潜在收益**

- `exec time`: **2-6% suite-level plausible**；branch-heavy workload 上可更高
- `code size`: **大致中性，少数计划略增**

**实现复杂度**

- **约 350-700 LOC**
  - common validator/UAPI: 150-250
  - x86 region emitter/layout logic: 200-450

**与 K2/Merlin 的关系**

- **完全正交**

**安全模型**

- **兼容当前 fail-closed 边界**

---

### Top 2. Verifier-Fact-Guided Late Specialization

**一句话描述**

让 userspace 用 verifier log 做 discovery/ranking，kernel 用真实 verifier facts 做 legality re-check，在同一 site 上选择依赖 range/type/liveness 的 native variant。

**为什么比 instruction selection 更有 novelty**

- 它把决策依据从 **syntax** 提升到 **abstract state**。
- 这不是 “match 到一个 idiom 就发某条 CISC”，而是 “同一语义 site，在不同 verifier facts 下选择不同 lowering contract”。

**UAPI / kernel 设计草案**

- baseline 继续用 v6 pattern rule
- 扩展一个 optional `fact_predicates[]` 或 future `fact_ref`
- predicate kind 示例：
  - `LIVE_OUT_DEAD(reg, succ)`
  - `UMIN_UMAX_WITHIN(var, lo, hi)`
  - `UPPER32_ZERO(reg)`
  - `REG_TYPE_IS(reg, scalar/pkt_ptr/map_ptr)`
- userspace：
  - 从 verifier log 提取 facts
  - 决定是否值得发 rule
- kernel：
  - 从 `insn_aux_data` / verifier summary 重验 facts
  - 只在 facts 成立时启用 fast variant
- 第一批 native choices：
  - `DIV_FAST_RDX_DEAD`
  - `ZEXT_ELIDE`
  - `NARROW_CMP`
  - `TYPE_SPECIALIZED_LOAD`

**潜在收益**

- `exec time`: **1-4% suite-level plausible**
- `code size`: **1-4%**

**实现复杂度**

- **约 300-550 LOC**
  - generic fact-predicate plumbing: 150-250
  - first 2-3 x86 variants: 150-300

**与 K2/Merlin 的关系**

- **正交**

**安全模型**

- **非常契合**
  - kernel 不信 userspace facts
  - kernel 自己 re-check

---

### Top 3. Typed Semantic Region Plans

**一句话描述**

把接口从 “每个 pattern 一个 canonical form” 升级为 “多个 kernel-known semantic atoms 组成一个 region plan”，由 kernel 在 region 内做组合、抵消和 plan selection。

**为什么比 instruction selection 更有 novelty**

- 它不再是单层 many-to-one isel，而是 **inter-region algebra + composition**。
- 它还能直接缓解当前最根本的扩展痛点：**每加一个 form 就要加一个 emitter**。

**UAPI / kernel 设计草案**

- 新 rule kind：`BPF_JIT_RK_REGION_PLAN`
- userspace 发送：
  - `site_desc`
  - `atom[]`
  - `binding[]`
  - `plan_goal`
- `atom` 必须来自 kernel 预定义小集合，例如：
  - `LOAD_BYTES`
  - `EXTRACT`
  - `ROTATE`
  - `SELECT`
  - `ADDR_GEN`
- kernel 处理流程：
  1. 重新匹配 atom sequence 到真实 BPF region
  2. 做内建 normalize
  3. 应用有限 composition rules
  4. 选择 kernel-owned native plan
- 首批 composition rules：
  - `ROT + ROT -> ROT/NOP`
  - `WIDE_LOAD + EXTRACT -> FIELD_LOAD`
  - `ENDIAN + EXTRACT -> BE_FIELD_LOAD`
  - `SELECT + ZEXT -> SELECT32`

**潜在收益**

- `exec time`: **2-5% suite-level plausible**
- `code size`: **2-8%**，packet/parser-heavy workload 上更有机会

**实现复杂度**

- **约 550-900 LOC**
  - common atom parser/validator: 250-400
  - composition engine: 150-250
  - x86 first plan library: 150-250

**与 K2/Merlin 的关系**

- **正交**

**安全模型**

- **可以兼容**
  - 前提是 atom set、composition rules、native plans 全都 kernel-owned
  - 不接受 arbitrary rewrite scripts

---

## 5. What I Would Not Sell As The Main Novelty

### 5.1 “再加更多 instruction selection forms”

有用，但不 novel。

### 5.2 “generic rewrite interpreter in kernel”

novel 但不安全；不符合当前论文主线。

### 5.3 “纯 microarchitectural knob exposure”

收益偏小、过于 x86-family-specific，适合做附属项，不适合做主轴。

### 5.4 `bounds_window` / `BOUNDS_ELIDE`

这是**高价值 future direction**，但它已经触及新的 safety proof：kernel 需要证明“删掉 guard 后仍保持 verifier-level safety invariant”。我会把它视为 **vNext 级别的 retained-fact rewrite**，而不是当前最稳妥的前三名。

---

## 6. Final Recommendation

如果目标是 **“比 instruction selection 更有 novelty，同时还能维持 kernel-validated / userspace-driven 安全模型”**，我的排序是：

1. **SESE control-flow region specialization**
2. **verifier-fact-guided late specialization**
3. **typed semantic region plans**

如果目标是 **“下一个版本先做最稳、最容易发 paper 的组合”**，建议实施顺序是：

1. 先把 v6 的 `site_kind + overlap arbitration + log parity` 收好
2. 先做 `SESE` 局部 diamond 版本的 control-flow family
3. 同时做一个小而硬的 fact-driven family（优先 `DIV_LIVENESS`）
4. 最后再上 typed region plans，作为 v7 的接口升级

这条路线的优点是：

- 第一项给你**真正 policy-sensitive** 的 structural story
- 第二项给你**verifier-info** story
- 第三项给你**interface generalization** story

三者合起来，明显比 “再加一个 instruction selector” 更像一个 systems paper 的新贡献。

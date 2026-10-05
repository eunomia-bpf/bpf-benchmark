# Review of BpfReJIT

## 1. Overall score

**6/10**

Borderline / weak reject in the current form.

## 2. Summary

这篇论文的核心主张是：eBPF JIT backend 的优化决策不应该全部固化在 kernel 内，而应该做 mechanism/policy separation。Kernel 负责 legality 和安全边界，privileged userspace 负责 profitability 和 deployment policy，并通过 `BPF_PROG_JIT_RECOMPILE` 对已验证程序做 post-load re-JIT。论文最强的部分是这个高层 thesis 本身，以及 post-load re-JIT 这个接口方向；最弱的部分是，当前写法还没有完全说服我这比“把少数 JIT 选择暴露给 userspace”更深一层。对 SOSP/OSDI 来说，这篇论文最像一篇 measurement-driven 的新系统/interface 论文，而不是 measurement study；但目前 positioning 和 evaluation 还留着比较明显的 reject handle。

## 3. Strengths

- 核心 idea 是清楚且好记的：kernel 管 legality，userspace 管 profitability。这是一个对 systems reviewer 友好的 framing。
- 论文很好地区分了 BPF bytecode optimization 和 native lowering optimization，说明了现有 K2 / Merlin / EPSO 不能覆盖这个 backend gap。
- Introduction 到 Design 的高层叙事总体可读，RQ + Takeaway 结构也提升了可导航性。
- `BPF_PROG_JIT_RECOMPILE` 作为 post-load、无需 re-verification 的接口，有实际系统意义，不只是单个 peephole patch。
- v5 declarative pattern extension 是让这篇论文看起来像“可扩展 abstraction”而不是“四个手写规则”的关键组成部分。

## 4. Weaknesses

1. **核心 novelty 仍然太接近“把 optimization flag 暴露给 privileged userspace”。** 论文说的是 mechanism/policy separation，但目前还没有把这个抽象写到 reviewer 无法轻易降格成“几个 JIT knobs”的程度。
2. **`Why not just fix the kernel?` 目前只对 COND\_SELECT / cmov 足够有说服力。** 另外三个 family 更像常规 kernel peepholes，这会削弱“userspace policy plane 是一般答案”的论点。
3. **Evaluation 缺少最关键的 baseline。** reviewer 会直接问：`best reasonable fixed-kernel heuristic` vs `userspace policy`，跨 workload / CPU / real program 谁更好？现在 RQ2 只否掉了一个固定选择，不足以否掉整体 alternative。
4. **论文结构在 characterization paper 和 system paper 之间摇摆。** Motivation 已经给了很多 characterization，RQ1 又重复一遍，导致 narrative 发散。
5. **Security / correctness 论证还不够“kernel paper”级别。** `no native code upload + digest binding + CPU gating` 是必要条件，但还不是足够有力的 paper-level assurance story。
6. **Positioning 有点危险。** 你们用了 Halide 类比，但 breadth、自动化程度、generalization 范围都还远不到让 reviewer 自然接受这类 comparison 的程度。

## 5. 每个 section 的具体建议

### Abstract

- 当前 abstract 的 thesis 是清楚的，但太像结果数字堆叠。建议补 1 句更强的“为什么重要”：eBPF JIT quality 直接影响 production datapath / tracing / scheduling hot path 的 CPU 成本。
- 建议少放一个结果数字，换成一句更明确的 design claim：`backend lowering decisions are deployment policy, not a fixed kernel implementation detail`。
- `60 production programs succeed` 和 `32 LOC extension cost` 都是好结果，但同时放会分散主贡献。若只能留一个，我更建议保留 deployment/safety 结果，把 extensibility 放到引言贡献点。

### Introduction

- 问题 statement 还可以更有力。现在说明了 eBPF 很重要，但没有完全讲透“为什么 kernel JIT backend quality 是 SOSP/OSDI 级别的问题”。建议更明确把 fleet-scale CPU cost、hot-path frequency、operator pain point 说出来。
- `Why not just fix the kernel?` 是全篇最关键的一段，但目前过度依赖 cmov 这个例子。reviewer 很容易反问：`那就把 3 个 peepholes upstream，只对 cmov 特判就行了`。
- 建议在引言里提前做 taxonomy：
  - `policy-sensitive families`：必须 externalize policy
  - `substrate / baseline-recovery families`：即使 fixed heuristic 也可能有用，但复用同一个 substrate
- 五个 `why userspace` 理由本身是对的，但现在像附加说明。建议把它们直接并入反 straw man 论证，而不是在 `Our system` 后面单列。
- Halide 类比可以保留，但不要让它成为主要 positioning，否则 reviewer 会自然拿 TVM/XLA/Halide 这类系统来衡量 breadth。

### Background and Motivation

- `Existing BPF Optimizers Cannot Close This Gap` 这一节有效，且是必要的。它让论文和 K2/Merlin/EPSO 的边界很清楚。
- 这一节目前数据密度偏高：optimizer comparison、gap summary、selected benchmarks、surplus breakdown、cmov ablation 都堆在 Design 前面，读者在 fully buy in 之前就被表格淹没。
- 我建议：
  - Motivation 只保留 1 个 suite-level gap 表 + 1 个 policy-sensitivity 表。
  - `selected per-benchmark results` 移到 appendix 或 Evaluation。
  - 方法学细节压缩到 appendix 或 Evaluation setup。
- 现在“bytecode optimizer 不够”已经证明得不错，但“policy-sensitive”还没有证明到足够 general。更准确的写法应是：`COND_SELECT clearly policy-sensitive; other families motivate reuse of the same substrate`。
- `The mechanism we need is not a better heuristic but a better interface` 这句是一个很好的 section landing sentence，建议更突出，作为从 Motivation 转入 Design 的明确桥梁。

### Design

- 高层 framing 清楚，但 design decision justification 还不够强。读完后我知道你们做了什么，但不完全知道为什么这个 interface 比 alternatives 更合理。
- 建议显式加入三个 alternatives，并解释为什么不用：
  - load-time hints，而不是 post-load re-JIT
  - kernel heuristics / kernel plugin，而不是 userspace policy blob
  - native code upload，而不是 named variant + canonical form
- Security model 需要更明确地写 trusted boundary 和 invariants：
  - trusted：verified xlated bytecode、kernel emitters、CPU feature detection
  - untrusted：policy blob content
  - invariants：bytecode unchanged、no new side effects、bounded control-flow forms、unsupported request fail-closed
- 建议加一个 worked example。比如一个小的 select pattern，展示 stock lowering、requested variant、kernel checks、final emission。这样 mechanism/policy separation 会从 slogan 变成具体语义。
- v5 declarative pattern 不应只是“最后补一个 extensibility 小节”。它实际上决定了这套 abstraction 是否能保持 small and stable。建议在 Architecture Overview 就提前埋进去。
- 但也不要把 v5 写成第二篇论文。正确的定位是：`v5 is the extensibility mechanism that keeps the legality plane stable while policy evolves`。

### Implementation

- 这是目前最值得压缩的 section。`1,800 LOC across 7 files` 有参考价值，但不值得占太多 narrative bandwidth。
- 建议保留三件事：
  - `do_jit()` 中的 dispatch hook
  - 4 层 validation pipeline
  - userspace scanner 如何支撑 iterative optimization loop
- 如果需要腾篇幅，我会优先砍 LOC inventory，把空间还给 Design justification 或 decisive Evaluation baseline。

### Evaluation

- RQ 的顺序基本合理：RQ1 建 gap，RQ2 否 fixed policy，RQ3 验机制安全，RQ4 看 family effectiveness，RQ5 看 extensibility。
- 最大问题不是 RQ 命名，而是少了一个真正 decisive 的问题：
  - `Does userspace policy outperform the best reasonable fixed-kernel alternative across workloads / CPUs / real programs?`
- 现在 RQ2 只能说明 `always-cmov is bad for one workload class`。这还不够推出 `therefore a userspace policy plane is the right systems abstraction`。
- 至少应补下面三类中的两类：
  - fixed-kernel baseline for ROTATE / WIDE / ADDR\_CALC / CMOV
  - cross-workload or cross-input policy A/B on the same program
  - cross-microarchitecture sensitivity，哪怕只是两台 x86
- RQ1 和 Motivation 重复较多。建议二选一：
  - 要么把 characterization 全放进 Evaluation，Motivation 只留摘要；
  - 要么删除 RQ1，让 Evaluation 从 RQ2 开始。
- `Takeaway` 的使用总体有效，但个别句子写得太满。尤其 `Fixed kernel heuristics are falsified` 这句证据强度不够，建议收窄成 `fixed policies are insufficient for policy-sensitive families`。
- RQ3 的 `100% recompile success` 是好的 compatibility/safety signal，但还缺更像 systems paper 的 deployment story，例如 policy A/B、iterative re-JIT loop、或一个 production-like service case study。
- RQ5 的 extensibility 不应该只是工程优雅性结果，而应被明确连接到主 thesis：它证明了 kernel legality plane 可以保持 small、stable、kernel-maintainable。

### Discussion

- `Falsification condition` 是正确方向，但它也暴露了当前论文最大的短板：你们自己承认还缺 cross-microarchitecture validation。reviewer 会直接拿这点做 reject handle。
- 建议主动收窄 claim：当前证据已经支持 `some backend decisions are policy-sensitive enough that a purely fixed kernel interface is insufficient`，但还不足以支持更 general 的全称命题。
- `RCU-protected hot-swap` 不只是一般 limitation，而是 kernel interface paper 的可信度问题。若这部分仍是 prototype，建议在更前面就降 claim，而不是留到 limitations 才说。

### Related Work

- 和 BPF optimizer 的区分写得清楚，这点很好。
- 但只引用 Halide，不提 TVM/XLA/auto-tuning 类系统，会让类比显得过于选择性。你们有两个选择：
  - 要么补 cite，并明确只是借用 `policy externalization / schedule separation` 的思想；
  - 要么弱化 Halide 类比，避免 reviewer 自动按 compiler-framework 标准来衡量。
- 我更建议把核心定位写成：`safe OS/compiler interface for post-load specialization`，而不是 `another optimization framework`。

### Conclusion

- 结论总结清楚，但还是偏结果回顾，不够像一个落地的 design claim。
- 最后两句最好更明确：这篇论文的 lasting message 不是四个 peepholes，而是 `when profitability depends on deployment context, backend optimization policy should be externalized from the kernel`。

## 6. 如果我是作者，我会这样改

1. 把论文主轴重写成：`a new kernel/userspace boundary for safe post-load JIT specialization`，而不是“四个 backend optimizations + 一个框架”。
2. 在 Introduction 和 Design 中显式区分两类 rule family：`truly policy-sensitive` 和 `substrate / baseline-recovery`。
3. 重写 `Why not just fix the kernel?`，把五个 `why userspace` 理由直接纳入反 straw man 论证。
4. 精简 Motivation 的表格密度，只保留最能支撑 thesis 的两张表，其余移到 appendix 或 Evaluation。
5. 删除或吸收 RQ1，避免 Motivation 和 Evaluation 重复讲 characterization。
6. 在 Design 里加入一个 worked example，具体展示 policy blob、pattern match、validation、emission 之间的语义边界。
7. 扩展安全模型，清楚列出 trusted computing base、equivalence boundary、fail-closed conditions，以及当前 prototype 不支持什么。
8. 提升 v5 declarative pattern 的地位，把它从“扩展性小节”升级为“为何 legality plane 能保持 small and stable”的关键证据。
9. 补一个 decisive baseline：`best fixed-kernel heuristic` vs `userspace policy`，至少在两个 workload class 上对比。
10. 如果短期拿不到多硬件结果，就主动收窄 claim，不要再把论证写成已经彻底否定 kernel-fixed policy。
11. 增加一个 production-like case study，展示 operator 如何 profile、生成 policy、A/B、回滚。哪怕收益不大，story 价值也很高。
12. 调整 Abstract 和 Conclusion，让核心 takeaway 更像系统设计原则，而不是 benchmark scoreboard。

## 7. 最致命的 3 个 reject 理由

1. **Novelty risk**：中心思想仍可能被 reviewer 解读为“把少数 JIT lowering choices 暴露给 privileged userspace”，抽象层次还不够高。
2. **Evidence mismatch**：论文声称 kernel-fixed policy 不够，但强证据主要集中在 CMOV 一个 family、一个硬件环境，支撑不了更 general 的 systems claim。
3. **Positioning gap**：论文想作为 SOSP/OSDI 级别的新系统/abstraction paper 发表，但 evaluation 目前更像 characterization + prototype validation，缺 decisive deployment 或 multi-environment evidence。

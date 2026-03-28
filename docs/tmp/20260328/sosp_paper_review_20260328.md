# Summary

本文提出 BpfReJIT：在 eBPF 程序加载后保存原始 bytecode，由用户态 daemon 对 live program 做整程序重写，再通过内核重新 verifier + JIT，并原地替换同一 `struct bpf_prog` 的执行映像；同时引入 `kinsn`，希望把架构相关指令选择从固定 eBPF ISA 中分离出来。作者试图论证的核心价值是：相比 K2/Merlin/EPSO 这类 pre-load 优化器，BpfReJIT 提供了一个透明、可扩展、runtime-guided 的 post-load 编译框架。

我认为这个问题方向本身值得做，尤其是“对已经部署的 live eBPF 程序做透明重编译”这一点，确实和已有 compile-time 工作不在同一设计点上；把 verifier 重新用作 admission gate 也有一定系统味道。但当前稿件距离 SOSP 可接受状态很远，主要原因不是“实验还不够漂亮”，而是论文目前同时存在三类根本性问题：第一，稿件本身尚不可审，Implementation 和 Evaluation 仍是 TODO/placeholder；第二，核心故事在 framework、`kinsn` 和具体优化之间反复摇摆；第三，若按当前文本最强 claim 来审，安全性、novelty、upstreamability、多平台与实验支撑都明显不足，且部分地方与 plan doc 反映的系统现状直接冲突。

# Strengths

- 选题重要。eBPF JIT 代码质量、透明部署与内核可维护性之间的张力是真问题，不是人为制造出来的 benchmark game。
- “post-load + transparent + verifier-guarded” 这个设计点和 K2/Merlin/EPSO 确实不同，至少在问题设定上有新意。
- 将优化 policy 放在 userspace、将 legality/safety admission 留在 kernel，这个分工直觉上是合理的，且比“把复杂优化全塞进 kernel JIT”更现实。
- 若系统真正跑通，dynamic map inlining / invalidation 这类 deployment-time specialization 会是比 rotate/cmov peephole 更强的论文故事，因为它确实依赖 runtime state，而不只是“把现有 peephole 搬到 daemon”。

# Weaknesses

1. **稿件目前不可审，单凭这一点就应拒稿。** `Implementation` 节仍然带有 `\note{TO-DO}`，`Evaluation` 节明确写着 `\note{TO-DO, data not real}`，大量正文反复出现 “current placeholder dataset / synthetic placeholder”；图表和附文也保留了 raw draft 标记，如 `wrong, need update`、`\note{rq-...}`、未消化的 related-work 备注。这不是“写作还需 polish”，而是论文主体结果尚未成形。具体证据见 `docs/paper/sections/5-implementation.tex:35-38`、`docs/paper/sections/6-evaluation.tex:47-168`，以及 `docs/paper/figures-next/*` 中多处 “Synthetic placeholder”。

2. **核心 contribution 叙事极不稳定，导致我无法判断这篇论文到底应该按什么标准来审。** 摘要和引言把论文包装为一个 “dynamic, extensible compilation framework”；第 3 节却把篇幅大幅放在 `kinsn`；而 plan doc 又明确写着 “over half of our optimizations do not depend on Kinsn”，并把 “Dynamic map inlining” 标为“论文核心 story”。换言之，framework、`kinsn`、以及具体 runtime specialization 三者之间的主次关系并没有收束。若主贡献是 framework，那么必须把 `REJIT` 接口、透明替换、admission model 和 policy separation 说透；若主贡献是 `kinsn`，那当前 novelty 明显不够；若主贡献其实是 dynamic map specialization，那论文当前重心完全放错了。

3. **“microkernel-inspired separation” 这个 analogy 是 stretch，而且不是论文真正的 novelty 来源。** 机制/策略分离本身是极其通用的工程原则，不足以支撑一篇 SOSP 论文。更关键的是，这个 analogy 还会掩盖真正需要回答的问题：为什么 userspace interface 比 fixed in-kernel peephole 更必要？为什么 runtime feedback 必须越过 kernel trust boundary？为什么 `REJIT` 的 admission contract 比简单 kernel peephole 更 general 且更值这个复杂度？当前文中频繁使用 microkernel/LLVM/HotSpot/livepatch 类比，但并没有把这些类比转化为可验证的 technical delta。

4. **“re-verify = safety guarantee” 被写得过满，而且 `kinsn` 路径的 safety story 有明显漏洞。** 对 ordinary eBPF bytecode 而言，重新走 verifier 的确能重新建立 bytecode-level safety；但这并不自动推出两个更强命题：一是语义正确性，二是 `kinsn` native lowering 的安全性。论文在摘要和引言中声称 `kinsn` 的 eBPF expansion 与 native lowering 之间有 “formally verified equivalence”，从而把 verifier 在 proof form 上建立的性质转移到 native code；但第 3 节正文并没有给出任何 theorem、proof artifact、proof assistant、proof scope，甚至该处自己还留着 `TODO: Kinsn Safety`。更糟的是，plan 中还明确提醒“如果不是 machine-checked，就不要写 formally verified”。因此当前稿件最核心的 safety transfer claim 并没有被证明，读者只能被要求信任 module/JIT emitter 的正确性。

5. **`kinsn` 的 novelty 看起来更像 “kfunc + inline emit callback”，而不是一个真正新颖的 IR/ISA 机制。** plan doc 对实现写得很清楚：`kinsn` 通过已有 kfunc 基础设施实现，新加 `KF_INLINE_EMIT` flag，让 JIT 在 call path 上分派到 module emitter；后续甚至还有专门任务要把 `kinsn` “统一到 kfunc 路径，消除平行子系统”。如果真实实现本质上就是 “已有 kfunc registration/lifetime/BTF + proof-sequence expansion + direct emit callback”，那第 3 节把它包装成一个独立 bytecode abstraction/extended ISA 就显得过度陈述。作者必须正面回答：`kinsn` 相对已有 kfunc，到底多了什么不可替代的新能力，而不是仅仅多了一个更方便的论文名字。

6. **为什么不直接在 kernel JIT 里加 peephole，这篇论文没有做出足够有力的反证。** 论文反复诉诸“静态应用会回归 68% real programs”来证明 userspace-guided runtime optimization 必要，但这个论证并不封闭。首先，没有 fixed kernel peephole baseline；其次，没有展示少量 carefully chosen in-kernel rules 是否已经能吃掉大部分收益；第三，缺少与 K2/Merlin/EPSO 的 head-to-head，因此读者无法知道 BpfReJIT 的新增价值到底来自 “post-load + runtime info”，还是仅仅来自“作者终于实现了一堆 kernel 里还没有的 peephole”。plan 里甚至明确写了 `Mandatory Falsification`：如果 fixed kernel heuristics 在各 workload/硬件上恢复了同样收益，正确结论就是“去做 kernel peepholes”，不是发布这个接口。当前论文没有完成这一步，因此 userspace 方案的必要性尚未被证明。

7. **论文声称的“<600 LOC kernel modifications / upstream-compatible path”与 plan 中系统现状明显不符。** 摘要和引言都反复强调 fewer than 600 lines of kernel changes、upstream-compatible；但 plan 在 2026-03-23 的审计条目里记录的是 **1437 行代码 + 162 行注释**，随后 2026-03-25/26 的 review 条目又显示对上游的 patch 规模是 **13 files, +1967/-121**。这还不包括 reviewer 发现的多项 HIGH 问题。一个引入新 syscall/UAPI、保存原始 bytecode、re-JIT swap、attachment refresh、JIT/verifier/module lifetime 处理的补丁集，本来就很难被认真称为 “minimal” 或 “upstream-compatible path”。至少以当前材料看，这个 claim 不可信。

8. **Evaluation 缺的不是“小补充”，而是决定论文结论方向的关键基线与关键维度。** 没有 K2/Merlin/EPSO 的 head-to-head；没有 fixed kernel peephole baseline；没有可信的 ARM64 实验；没有真正完成的 overhead 与 safety section；没有对 `map_inline`/`branch_flip` 这类 policy-sensitive pass 的失误代价做完整量化。尤其 ARM64 问题很严重：论文正文和表格明示 x86/ARM64 lowering、多平台；但 plan 在 2026-03-23 的条目仍把 `ARM64 QEMU 测试` 标为待做，而评测 setup 却已经写“we use an additional ARM64 development board for cross-architecture validation”。这会让审稿人直接怀疑作者是否在把实现存在与实验完成混为一谈。

9. **dynamic map inlining 的 correctness contract 没有被论文讲清楚，而它恰恰很可能是全文最有价值的技术点。** 从 plan 看，这个 pass 有一长串关键前提：只适用于 direct value access map；要排除 PERCPU maps；对 HASH/LRU_HASH 只能做 speculative inline，且只替换 non-null path；需要 invalidation tracker 定期检查并触发 re-REJIT/rollback；还踩过 typed `LD_IMM64` 与 verifier-visible pointer type 的坑。论文目前几乎没有把这些条件正式化，也没有给出清晰的 deoptimization/invalidation correctness 论证。如果作者真正想把 runtime specialization 立为核心贡献，那么这里应该是 design/evaluation 的中心，而不是一笔带过。

10. **Related work 不够公平，且回避了最危险的对比。** 第 7 节几乎只从 lifecycle point 上区分“pre-load vs post-load”，然后得出“互补”结论，但这不足以说服 SOSP 审稿人。作者应该正面回答：在作者自己的 workload 上，K2/Merlin/EPSO 能做多少？ePass 这种 in-kernel extensible pass 和你们相比，复杂度/性能/透明性差多少？哪些优化 family 只有 post-load 才有意义，哪些其实完全可以 pre-load 或 kernel peephole？如果不做这些 head-to-head，本节更像 positioning，而不是公平比较。

# Questions for authors

1. 这篇论文的第一贡献到底是什么：`REJIT` framework、`kinsn` 机制，还是 dynamic map inlining / runtime specialization？请给一个单句版本，并解释为什么其它部分是 supporting material 而不是并列主贡献。

2. 你们反复写 “formally verified equivalence between each eBPF expansion and its native lowering”。这个 proof 目前到底是什么状态？是 machine-checked proof、paper proof，还是根本还没完成？覆盖哪些 instruction family，覆盖哪些架构？

3. 若把 `kinsn` 的包装全部去掉，按实现本质来描述，它和 “kfunc + custom verifier-side expansion/proof sequence + JIT inline emit callback” 的差异到底是什么？为什么这足以构成论文中的独立 novelty？

4. 能否提供与你们同一 workload、同一 benchmark harness 下的 K2/Merlin/EPSO 对比，以及一个 fixed kernel peephole baseline？没有这个对比，我很难相信 userspace post-load interface 是必要的，而不是工程上更重的替代方案。

5. map inlining 的 correctness 条件请完整写出：支持哪些 map type，不支持哪些 map type，speculative inline 的 guard 是什么，失效检测频率是什么，rollback 如何保证不留下 stale assumption？特别是 mutable map、per-CPU map、并发更新下，语义如何定义？

6. 截至 plan 中 2026-03-23 至 2026-03-26 的条目，ARM64 测试仍未完整跑完，而 Tracee/Tetragon 也曾因为 map type / verifier 问题出现 REJIT failure。作者准备在最终论文中如何收敛这些 claim？哪些结果已经稳定，哪些其实仍在开发中？

7. 你们准备 upstream 的到底是什么？新 syscall/UAPI、保存 original bytecode 的 aux state、JIT swap、`KF_INLINE_EMIT`/`KF_KINSN`、以及架构 module 都要一起 upstream 吗？如果不是，所谓 “upstream-compatible path” 的含义是什么？

# Minor comments

- `docs/paper/sections/1-introduction.tex` 仍有 `\cite{xxx,yyy}` 这种占位 citation。
- `docs/paper/sections/4-bpfrejit-design.tex` 的图注直接保留了 `\note{wrong, need update}`。
- `docs/paper/sections/5-implementation.tex` 中出现了看起来不存在的交叉引用，如 `\ref{sec:design-recompile}`、`\ref{sec:design-kinsn}`，建议检查。
- `docs/paper/sections/7-related-work.tex` 末尾还留着 `\note{incorporate original LLVM / JVM / Wasm section in background}`。
- `docs/paper/figures-next/text-eval-setup.tex` 的 setup 描述过于粗糙，像 “Recent x86-64 workstation-class CPU” 这种写法不符合系统论文复现标准。
- 如果最终保留 sub-100ns 的 microbenchmark 数字，必须给出 cycle-level methodology、CPU pinning、frequency policy、loop peeling/measurement overhead 处理方式，否则可信度会被严重质疑。
- speedup/ratio 的方向必须统一。plan 中很多结果用 `rejit/stock < 1` 表示更快，而正文又用 `1.13x speedup`。如果图表同时出现两套方向，读者很容易误读 geomean。
- abstract 里 “transparently supporting existing eBPF ecosystem” 和 “upstream-compatible path” 现在都说得过满，建议在结果没完全稳定之前降调。

# Overall recommendation

**Reject.**

理由不是“想法不有趣”，而是当前稿件在可审性、主故事收敛、关键 technical claim、以及评测完整性四个维度都没有达到 SOSP 标准。即便把 placeholder 全部替换成真实数据，我也仍然建议作者先做一次较大幅度重构：

- 明确把论文主线收束到 **framework 本身** 还是 **dynamic specialization**；
- 删除或降调所有没有证据支撑的强 claim，尤其是 `formally verified`, `<600 LOC`, `upstream-compatible`, `multi-platform`；
- 补齐 fixed kernel baseline、K2/Merlin/EPSO 对比、ARM64 数据、map inlining correctness/invalidation 论证；
- 把 `kinsn` 从“宏大新 ISA 叙事”收缩为一个被严谨界定的 mechanism，或者反过来真正证明它是全文核心 novelty。

如果作者能够把这些问题解决，这个方向未来是有潜力的；但以当前版本，我会给出比较坚决的拒稿意见。

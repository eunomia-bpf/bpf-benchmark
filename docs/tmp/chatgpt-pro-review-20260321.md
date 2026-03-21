我先给结论：这个 proposal 的方向是对的，而且确实有很强的 systems taste；但按你现在的表述，我会给出“有潜力，但主线还不够尖”的评价。eBPF 本身已经是广泛部署的生产技术，覆盖 networking、runtime security、observability，近年的社区材料还把它扩展到 FinOps 和 AI/LLM telemetry 等基础设施场景；官方内核文档也显示 eBPF JIT 已覆盖 x86_64、arm64、riscv64、loongarch64 等多种架构，所以围绕 kernel eBPF 的性能与安全继续做研究，绝对不是伪问题。([eBPF][1])

但它现在最大的风险不是“题目不重要”，而是“和已有工作重叠得太近”。K2 已经证明 eBPF bytecode 可以被自动优化并给出形式化正确性与安全保证；Merlin 已经做了 customized LLVM passes + bytecode rewriting，并在 19 个 XDP 程序和 Sysdig/Tetragon/Tracee 上报告了明显的指令数与运行时收益；ePass 的公开材料又明确把自己定位成一个 in-kernel、LLVM-like 的 eBPF compiler framework，带 SSA IR、pass runner、re-verify、optimization/runtime-enforcement passes。再往 verifier/user-space reasoning 这条线看，BCF 则把复杂 reasoning 下放到用户态、内核只做轻量 proof checking，并因此在 SOSP’25 拿到了很强的学术位置。按这个版图，你现在如果仍然主打“minimal extensible compiler framework + userspace does the hard part + kernel keeps safety”，评审很容易问：这和 K2/Merlin/ePass/BCF 的增量到底是什么。([Rutgers University][2])

我觉得它仍然有 OSDI/SOSP 级别 novelty 的机会，但必须换一个 thesis。真正有机会打动顶会的，不该是“再做一个 LLVM-pass framework”，而应该是：**在不放大 kernel TCB、也不破坏现有 verifier/JIT safety model 的前提下，让 deployed eBPF 从一次性静态编译，变成可在线、透明、runtime-guided specialization 的执行环境。** 从我查到的公开材料看，K2 和 Merlin 更像加载前/验证前优化；ePass 更像 verifier pipeline 内的 IR 重写与 runtime enforcement。它们都很近，但都没有把“用户态 daemon 监控真实运行 profile 和 runtime invariants，再对已部署程序做透明 hot-swap specialization”作为主 thesis 讲清楚。这个点如果做实，是你最像样的差异化。([Rutgers University][2])

你 proposal 里我最喜欢的 insight，其实是你说的那句：**把 correctness 和 safety 拆开**。这和 BCF 的核心思想非常契合：复杂 reasoning 在用户态做，内核只保留小而可信的检查器。BCF 已经说明，这种“offload complex reasoning, keep kernel checking cheap”的 framing 是很强的；它报告了 403/512 个原本被误拒的真实 eBPF 程序可被接受，平均 proof size 541 bytes，平均 proof-check 48.5 微秒。你完全可以借这条思路，把自己的系统升格成“certificate-backed dynamic optimization”，而不是只说“userspace tries to ensure correctness”。后者对顶会和 upstream 都太弱。([Haosun][3])

和 JVM / Wasm / userspace runtime 相比，你这个方向之所以有意思，恰恰是因为 kernel eBPF 的约束更硬。Linux 官方 BPF 设计文档明确说 BPF 不是 generic VM，JITed BPF 程序被设计成和 native kernel C code 无缝互操作；这也解释了为什么 eBPF 很难像 JVM 那样接受大量 speculative optimization、deopt、custom ISA extension，但反过来也意味着：谁要是能在不破坏这套 trust boundary 的前提下，把一部分 runtime adaptability 加回来，谁就有真正的 insight。([Kernel Documentation][4])

广泛应用性我觉得是高的。因为 eBPF 今天本来就横跨 networking、observability、security 多个子系统，而且生产案例已经不仅限于单一 hook 或单一公司；你如果真的做到对现有 loader、bpftool/libbpf 和子系统 attachment 足够透明，它理论上就不是只服务 XDP/tc 的优化器，而是一个更通用的 deployed eBPF specialization layer。([eBPF][1])

但 full vision 的 upstream 概率，我觉得不高，尤其是你提的 **kinsn**。Linux 官方 BPF 设计文档写得很直接：core BPF functionality（program types、maps、helpers）不能通过 module 扩展；module 更适合暴露的是 kfunc/kptr。文档还明确说，未来可接受的新 BPF 指令，前提是它和原生 CPU 指令有良好的一对一映射；缺乏这种映射的新指令不会被接受。所以“允许模块注册新 ISA 指令并让 JIT 发射它”这件事，几乎正好踩在 upstream 最敏感的红线上。更现实的替代是尽量复用 kfunc 这类既有扩展面，而不是扩张 BPF ISA 本身。([Kernel Documentation][4])

而且 upstream 社区对 verifier/JIT 复杂度天然高度敏感，这不是空想。Jitterbug 在 OSDI’20 里验证 BPF JIT，找出了 5 个已部署 JIT 中的 16 个未知 bug，并把修复 upstream 了；State Embedding 在 OSDI’24 又在一个月内挖出 15 个 verifier logic bug，其中一些可导致本地提权。换句话说，任何会增加 JIT、verifier、或者 transformation surface 的机制，maintainers 都会先想到“这会不会破坏我们已经很脆弱的信任基础”。所以如果没有非常强的最小 TCB 论证、pass 隔离、proof/certificate，upstream 阻力会非常大。([USENIX][5])

更现实、也更像 upstream 的路径，是把内核改动压成几个**通用 building blocks**，而不是整套 framework 一次性进内核。因为现有接口其实已经给了你不少基础：`BPF_OBJ_GET_INFO_BY_FD` 能拿到 `jited_prog_insns`、`xlated_prog_insns`、`run_time_ns`、`run_cnt`、`verified_insns` 等；`BPF_ENABLE_STATS` 可以按需启用统计；`BPF_LINK_UPDATE` 已经支持更新 link 上挂着的程序；`BPF_PROG_BIND_MAP` 可以把 map 绑定到 program 生命周期；`BPF_PROG_TYPE_EXT`/freplace 也已经支持对已加载 BPF 程序里的 global function 做一层替换。问题在于，这些机制还不等于“透明在线重优化”：`xlated_prog_insns` 是 verifier 改写过的字节码，里面可能已经有 helper inlining、IMM64 fd 变实际指针、ctx access rewrite、helper specialization，不能直接当成原始可重编译输入；而且不是所有 attach model 都已经 link 化，docs.ebpf 仍写着有些 program type 到 v6.19 还没有 link support。也就是说，你真正该做的是精确定义“还缺哪一个最小原语”。([Kernel Documentation][6])

我会建议你这样改：

1. **把题目从“extensible compiler framework”收敛成“transparent online specialization for deployed eBPF”。**
   这样你的主贡献就从“又一个 framework”变成“online + transparent + runtime-guided + safe hot swap”，更容易和 K2/Merlin/ePass 拉开。([Rutgers University][2])

2. **把 kinsn 从主线挪掉，最多做成 optional prototype。**
   你现在最不 upstream 的就是它；如果真要扩展能力，优先走 kfunc / freplace / existing link model，而不是扩 BPF ISA。([Kernel Documentation][4])

3. **把 safety story 从“userspace 尽量保证 correctness”升级成“certificate-backed transform”。**
   最理想是 pass-specific certificate 或 refinement proof；至少也要让 kernel 只接受能被便宜检查的 invariants，而不是盲信 userspace compiler。BCF 已经证明这条路线有说服力。([Haosun][3])

4. **把“runtime invariant”讲得更硬，不要泛泛地说 map 可能是 const。**
   现有机制里，`BPF_MAP_FREEZE` 会禁止未来 syscall 修改 map，但仍允许 eBPF 程序写；`BPF_F_RDONLY_PROG` 则禁止程序通过 helper 写 map；libbpf 文档还专门提到 freeze 常用于 constant global data。也就是说，只有这类强条件满足时，你的 const propagation 才有扎实依据。([Kernel Documentation][6])

5. **把 kernel API 设计成“最小缺口补全”，不是“完整 in-kernel compiler”。**
   你可能真正需要的是：更完整的 program metadata export、可恢复的原始重编译上下文、跨更多 attach point 的 atomic swap、失败回滚语义，而不是在内核里再造一套 pass framework。现有 `BPF_LINK_UPDATE`、`freplace`、`BPF_OBJ_GET_INFO_BY_FD` 已经能覆盖一部分，但显然还不够通用。([Kernel Documentation][6])

6. **把“zero overhead”改成“zero steady-state overhead after specialization”。**
   这会更可信。连官方 `BPF_ENABLE_STATS` 文档都明确说统计默认关闭是为了最小化性能开销；profiling 和决策面几乎不可能真的零开销，但 steady-state 可以接近零。([Kernel Documentation][6])

7. **评测一定要从 microbenchmark 扩到真实系统，并对准正确 baseline。**
   至少要和 kernel baseline、K2、Merlin 比；如果可能，也要说明和 ePass public prototype 的关系。工作负载别只跑 toy XDP，最好上 Cilium/Katran 类 XDP/tc 程序，以及 Tetragon/Tracee/Sysdig 这类 tracing/security 程序，外加 hot-swap latency、rollback、verification time、steady-state overhead。([Rutgers University][2])

所以我的判断是：**这题不是没新意，而是你得把“大而全 framework”改成“透明在线 specialization + 极小 kernel trust core + 可证明/可回滚的 hot-swap protocol”。**
按现在的写法，我觉得它更像“把几个正确方向捆在一起”的 ambitious system；改完以后，我会认为它有真实的 OSDI/SOSP 机会。upstream 方面，**full system 我给低概率；去掉 kinsn、收敛成通用 introspection/swap hooks 的最小 patchset，我给中等概率。** ([Kernel Documentation][4])

我下一条可以直接把它改写成一版更像 OSDI/SOSP 投稿摘要的 framing。

[1]: https://ebpf.foundation/new-state-of-ebpf-report-explores-how-modern-infrastructure-teams-are-building-on-kernel-level-programmability/ "https://ebpf.foundation/new-state-of-ebpf-report-explores-how-modern-infrastructure-teams-are-building-on-kernel-level-programmability/"
[2]: https://www.researchwithrutgers.com/en/publications/synthesizing-safe-and-efficient-kernel-extensions-for-packet-proc/ "https://www.researchwithrutgers.com/en/publications/synthesizing-safe-and-efficient-kernel-extensions-for-packet-proc/"
[3]: https://haosun.info/assets/pdf/BCF.pdf "https://haosun.info/assets/pdf/BCF.pdf"
[4]: https://docs.kernel.org/bpf/bpf_design_QA.html "https://docs.kernel.org/bpf/bpf_design_QA.html"
[5]: https://www.usenix.org/conference/osdi20/presentation/nelson "https://www.usenix.org/conference/osdi20/presentation/nelson"
[6]: https://docs.kernel.org/userspace-api/ebpf/syscall.html "https://docs.kernel.org/userspace-api/ebpf/syscall.html"

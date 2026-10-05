# Kernel JIT Directive POC 设计与实现评审

## 结论摘要

- 这个 POC 证明的不是 `v7` 文档承诺的完整 Hybrid 框架，而是一个更窄的事实：`userspace -> sealed memfd blob -> kernel parser -> verifier-side wide_load rewrite -> 更小的 BPF/JIT 代码 -> 在定制 benchmark 上更快` 这条链路可以跑通。
- 当前实现**不是 fail-closed、不是 digest-bound、不是 stage-aware、不是 policy-driven**。它也**没有证明 JIT-lowering substrate**，因为真正生效的逻辑几乎都在 verifier rewrite，x86 侧改动基本是摆设。
- `2.21x` 这个数字方向上是可信的，但它只能支撑“这个特定 transform 在这个特定 benchmark 上有效”，不能支撑“v7 设计已被验证”或“机制/策略分离已经成立”。
- 以 OSDI/SOSP 标准看，当前最大问题不是“代码还没补完”，而是**论文口径、设计文档、POC 实现、验证方法四者没有对齐**。

## A. 实现质量评审

**Kernel 侧**

- `vendor/linux/kernel/bpf/jit_directives.c:54-119` 的核心行为是 silent ignore。坏 FD、坏 flags、不是 sealed memfd、blob 长度错误、header 不匹配、record 不支持、甚至分配失败，最后都只是 `goto out; return NULL;`。这不是 fail-closed；这是 fail-open。
- `vendor/linux/kernel/bpf/syscall.c:3045-3048` 直接把 `bpf_jit_directives_load()` 的返回值挂到 `prog->aux->jit_directives`，没有错误传播、没有日志、没有 capability 强化检查。设计文档里强调的 `CAP_BPF + CAP_PERFMON`、fatal protocol error、structured telemetry，这里都没有。
- `vendor/linux/kernel/bpf/verifier.c:22264-22533` 的 `wide_load` matcher 本身写得比我预期保守，优点是真正做了几件重要的安全收缩：限制 pointer class、拒绝 interior jump、检查 temp live-out、限制 stack/map-value、限制 4/8 byte。就 POC 而言，这一段是最像“可 defend 的 kernel code”的部分。
- 但这段 matcher 仍然是**exact template matcher**，不是通用 directive framework。它只接受 byte-load/shift/or 这一个家族，而且默认 little-endian，默认无 `PROBE_MEM`/extable，默认无 packet/ctx，默认无多 directive interaction。
- `vendor/linux/kernel/bpf/verifier.c:22391-22405` 对 map-value alignment 的处理明显是临时避险：注释直接承认没有保留 `reg->off/var_off facts`，所以只能在 relaxed alignment target 上放行。这不是“已解决 legality reconstruction”，而是“先绕开难点”。
- `vendor/linux/kernel/bpf/verifier.c:22511-22533` 顺序应用 records，但没有 duplicate site、overlap、冲突顺序、互斥 directive 的策略。今天只有一个 kind，所以问题被掩盖了；一旦多 directive，上层 contract 还没建立，内核行为会变成 order-dependent。
- `vendor/linux/arch/x86/net/bpf_jit_comp.c:2249-2256` 的 x86 hook 基本是 no-op。因为同一个 switch 在 `2310-2312` 本来就会对普通 `BPF_LDX | BPF_MEM | BPF_W` 调 `emit_ldx(..., BPF_W, ...)`。也就是说，POC 根本没有展示新的 x86 directive lowering，只是 verifier 先把 BPF 改写好了。
- `vendor/linux/include/uapi/linux/bpf.h:1464-1493` 只提供了最小 header/record/payload，连 per-kind version、stage、interval、digest、CPU contract 都没有。作为 POC 可以接受，但它不是可 upstream 的 ABI 草案。
- `vendor/linux/include/linux/bpf.h:1710-1712` + `vendor/linux/kernel/bpf/core.c:288-296` 的内存生命周期是对的，`jit_directives` 最终会释放。这一块比 userspace 代码更整洁。

**Userspace 侧**

- `micro/runner/src/kernel_runner.cpp:515-573` 的 manual `BPF_PROG_LOAD` path 只带了 `prog_type / expected_attach_type / insns / license / prog_name / jit_directives_fd`。它**丢掉了**原始 loader 语义里的 `prog_flags`、`prog_btf_fd`、`func_info`、`line_info`、`fd_array`、`signature`、`token` 等字段。对 micro benchmark 足够；对真实 BPF 程序完全不够。
- `micro/runner/include/micro_exec.hpp:12-28` + `micro/runner/src/kernel_runner.cpp:450-488` 的 map metadata 只保留 `{type,key_size,value_size,max_entries,name}`。`map_flags`、BTF、inner map、map_extra、NUMA、pinning 语义全丢。这意味着当前 runner 只适用于非常简单的 array/hash map 微基准。
- `micro/runner/src/elf_program_loader.cpp:449-550` 手写了一个“够 POC 用”的 ELF relocation / local call / subprog address 处理器，但它只覆盖 maps、local calls、executable-section address relocation。对 CO-RE、global data、kfunc、复杂 extern、BTF 相关语义都不完整。更糟的是，这个 ad-hoc loader 可能和 libbpf 的最终 load image 不一致。
- `micro/runner/src/elf_program_loader.cpp:588-712` 的 `load_program_image()` 依赖“自己重建将要 load 的 BPF image”，而不是拿到 loader 最终提交给 kernel 的 exact pre-verifier image。v7 最核心的 digest-binding 叙事，在这里其实还没有被 userspace 端验证过。
- `micro/runner/src/elf_program_loader.cpp` 对 `Elf *` 没有 RAII；一旦 `elf_begin()` 后抛异常，`elf_end()` 会泄漏。CLI 工具问题不大，但这不是 production-quality C++。
- `micro/tools/directive_hint.c:63-189` 的 hint tool 不是 advisor，只是 pattern enumerator。它不做 CPU/workload policy，不做 profitability 选择，不做 conflict resolution，不做 exact-image digest，只是“看到 pattern 就全发”。这和 v7 的 policy plane 不是一回事。
- `micro/Makefile:20-22,48-54` 只有 `deps` 会构建 `directive_hint`，默认 `all` 不会。验证脚本依赖这个工具，所以可复现实验的默认 build path 其实不完整。这是小问题，但说明这个 POC 还停留在开发者内循环。

**安全、错误处理、内存管理总体判断**

- Kernel parser 的主要问题不是 parser bug，而是**错误语义设计错误**：该失败时不失败，该记录时不记录。
- Userspace runner 的主要问题不是崩，而是**伪装成通用 loader**。它其实是“为了把 directive fd 塞进去而重写了一套最小 BPF loader”，这会误导后续对“端到端可集成性”的判断。
- 就“代码是否做了它宣称做的事”而言：它基本做到了 `docs/tmp/poc-implementation-summary.md` 所说的那个窄 POC；它没有做到 `docs/tmp/bpf-jit-advisor-v7.md` 所承诺的系统。

## B. 设计-实现差距分析

| v7 / 设计文档承诺 | 当前 POC 实现 | 评语 |
| --- | --- | --- |
| Hybrid: verifier rewrite + JIT lowering 双阶段 | 只有 verifier rewrite；x86 hook 几乎 no-op | 架构承诺和实现方向不一致 |
| `wide_load` 属于 `JIT_LOWERING` | `wide_load` 实际在 verifier 中改写 | 这是最大的设计-实现错位 |
| digest bind 到 exact pre-verifier image | 只有 `insn_cnt` 检查，无 digest | 核心 correctness / identity contract 未实现 |
| sealed memfd + strict parser + fatal protocol errors | sealed memfd 有，strict parser 没有，fatal error 没有 | transport 只有外壳，缺错误语义 |
| CPU contract / strict CPU / feature gating | 没有 | policy plane 几乎不存在 |
| stage-aware blob 和 per-site interval metadata | 只有 `site_idx + payload` | 无法表达大多数 v7 directives |
| structured telemetry + verifier log | 没有，`BPF_F_JIT_DIRECTIVES_LOG` 形同虚设 | 无法观测 adoption/reject reason |
| multi-subprog remap/slicing | 没有 | `jit_subprogs()` 路径完全未证明 |
| constant blinding 分 family 处理 | 没有专门机制 | 当前 POC 其实绕开了 stage-2 问题 |
| v1 directive set 包含 `cmov_select` / `branch_reorder` / `bounds_window` 等 | 只实现 `wide_load` | 论文 novelty 载体还没落地 |
| userspace policy owner 根据 CPU/workload/program 选 directive | hint tool 看到 pattern 就发 | 这不是 policy，只是 discovery |

**更严重的文档自相矛盾**

- `docs/kernel-jit-optimization-plan.md:477` 把当前 POC 标成了 `fail-closed`，但 `docs/tmp/poc-implementation-summary.md` 和 `docs/tmp/poc-validation-report.md` 都明确承认“坏 blob 被忽略，程序照常加载”。这两个说法只能有一个是真的，当前代码证明后者才是真的。
- `docs/tmp/bpf-jit-advisor-v7.md` 把 `wide_load` 放在 JIT-lowering v1 集合里，但当前 kernel patch 把它实现成 verifier rewrite。这不只是实现 shortcut，而是 architecture decision 没定型。
- `docs/tmp/poc-validation-report.md` 说“mechanism/policy split works end to end”。这句话目前站不住，因为根本没有 policy selection，只有 pattern emission。

## C. POC 验证可信度

**我认为可信的部分**

- `load_byte_recompose` 的 benchmark 本身就是为 byte-recompose penalty 设计的，`micro/programs/load_byte_recompose.bpf.c:22-48` 在 loop 中反复调用 `micro_read_u64_le()`，理论上非常适合 `wide_load`。所以出现大幅收益是符合预期的。
- `docs/tmp/poc-validation-results.json` 里的 code-size 变化很有说服力。`xlated_prog_len: 744 -> 504`，正好减少 `240` 字节，也就是 `30` 条 BPF 指令。这个数和“一处 4-byte ladder 去掉 9 条 + 一处 8-byte ladder 去掉 21 条”完全吻合。说明 rewrite 大概率真的发生了，不像是测量噪声。
- `jited_prog_len: 422 -> 296` 也和“前端 BPF 更短，后端 native code 更短”这个机制一致。
- 因此，`2.21x` 作为**这个 synthetic case 的方向性结果**，我是相信的。

**我不认为足够可信的部分**

- 验证脚本 `docs/tmp/run_poc_validation_in_vm.py:66-96` 只测一个 benchmark、一个 guest kernel、`2` 次 warmup、`10` 次测量，没有置信区间、没有交错顺序、没有随机化。作为 POC 可以，作为论文系统证据远远不够。
- baseline 和 directive run 不是同一条 load path。baseline 用 `bpf_object__load()`，directive run 用 `manual_bpf_prog_load()` + 手写 ELF/image 重建。也就是说，A/B 不只是“有没有 directive”，还是“换了整个 loader”。这会污染因果归因。
- 更糟的是，现在**没有一个 same-loader no-op control**。最基本的对照应该是“同样走 manual load path，但 blob 空/无效/被内核忽略”。当前脚本没做这个实验。
- 当前 kernel 没有 structured telemetry，validation 也没有读取 kernel 侧 adoption state。也就是说，实验框架本身没有办法证明“directive 被接受了多少个、为什么被拒绝、是否只接受了其中一部分”。现在只能从 code size 和性能侧推。
- benchmark 顺序固定为 baseline 全跑完，再跑 directives。对纳秒级 microbench，这不是严谨设计。分支预测器、cache、guest 噪声、频率状态都可能偏向第二组。
- `compile_ns` 没有比较价值，因为两个 load path 完全不同。报告里虽然承认 directive path compile 更慢，但这本质上是“manual loader 更重”，不是 directive framework 的一般结论。

**这套验证可能怎样误导人**

- 它很容易把“对一个精心定制 benchmark 的成功 POC”说成“v7 系统已被验证”。
- 它也很容易把“reduced xlated/jited size”说成“mechanism/policy split 成功”，但当前根本没有 policy。
- 如果未来某个 case silent ignore 了 blob，没有 telemetry 的情况下，实验者甚至可能不知道自己测的是 stock path。

## D. 架构评估

**Hybrid 思路是否 sound**

- 抽象上是 sound 的。我同意把 structural transform 放 verifier，把 target-specific lowering 放 JIT。这个划分比纯 JIT peephole 或纯 verifier rewrite 都更诚实。
- `docs/tmp/verifier-rewrite-approach.md` 和 `docs/tmp/cross-document-review.md` 对这一点的判断是对的：真正能撑 novelty 的东西，尤其是 `branch_reorder`、`bounds_window`、`packet_ctx_wide_load`，本来就不适合塞进现在的 `do_jit()` 线性 emitter。

**POC 是否证明了 verifier rewrite path**

- 是的，但只证明了**最容易的一类 verifier rewrite**：局部、可删减、无 duplication、无 subprog slicing、无 new internal opcode 的 rewrite。
- 它没有证明更难的 verifier path：`branch_reorder` 的 block permutation、`bounds_window` 的 retained fact dependency、`cmov_select` 的 normalized select plan。

**POC 是否证明了 JIT lowering path**

- 没有。
- 当前 patch 没有 stable plan、没有 `addrs[]` collapse rule 的真实 exercise、没有 pass-stable acceptance 问题、没有 blinding rebase、没有 `jit_subprogs()` slicing。v7 在 JIT stage 花大量笔墨定义的 hardest parts，这个 POC 一个都没碰。

**向其他 directives 的泛化能力**

- 向 `wide_store` 泛化相对可信，因为它和 `wide_load` 同属“局部 contiguous byte ladder -> wider memory op”。
- 向 `packet_ctx_wide_load` 泛化只说明“方向上可能”，不说明“实现上接近”。真正难点在 readable-window facts、speculation hardening、`PROBE_MEM` / extable 排除、ctx access rewrite 的时序。
- 向 `cmov_select` 泛化几乎没有直接证据。那条路径需要 CFG recognition、纯赋值 contract、internal select 表示、arch-specific lowering、flags discipline、blinding policy。
- 向 `branch_reorder` 泛化更没有。那是 metadata move / branch retarget / subprog boundary / line info / poke descriptor 一整套新基础设施，不是把 `wide_load` matcher 改长一点。

## E. 走向生产级质量还缺什么

**必须补的机制缺口**

- 真正的 fail-closed parser 和 error model。
- digest binding 到 exact finalized pre-verifier image。
- userspace 与真实 loader 的集成，而不是继续维护一套 partial manual loader。
- `bpf_prog_info` / verifier log 级别的 structured telemetry。
- multi-subprog remap/slicing。
- constant blinding 语义。
- multi-directive overlap / conflict / ordering contract。
- selftests，尤其是 malformed blob、duplicate site、subprog、blinding、rejected-site telemetry。

**`orig_idx` propagation 到底难不难**

- 如果目标只是当前这种 `wide_load` 风格的“局部删除 + N->1 collapse”，那它确实接近一个中等规模 infra patch，难度没有神化到不可做。
- 但 v7 文档把它写成“Step 0: 20-40 LOC prerequisite”，这个估计对真正重要的 directives 明显过于乐观。
- 原因很简单：`orig_idx` 只足够描述简单 splice。对 `branch_reorder` 这种 permutation、对 `cmov_select` 这种 normalization + stage-2 plan、对 repeated rewrites、对 cross-subprog slicing，单个 `orig_idx` 不再足够。你需要的是 origin span、stable site identity、old->new map、aux/line/poke metadata 联动更新。
- 所以真实结论应该是：`orig_idx propagation` 不是很难；**把 provenance 做到足以支撑 Hybrid novelty cases 很难**。

**transport mechanism 的真实缺口**

- 当前 kernel UAPI 只是最小 tail fields + 最小 blob。它没有 exact-image identity、没有 CPU contract、没有 stage、没有 results。
- 当前 userspace 集成方式也不对。v7 的正确路径应该是“真实 loader 在 finalize exact image 后直接打包 blob”，而不是“另起一套 hand-written loader 重建 image”。
- 如果 production 目标是真的，应该优先做 libbpf/bpftool/Cilium style integration，而不是继续扩展 micro runner 的自定义 loader。

**multi-directive interaction 的缺口**

- 当前完全没有 overlap 规则、依赖关系、顺序语义、cross-stage invalidation reporting。
- v7 文档已经承认“verifier-stage rewrite 可能 invalidates later JIT-stage record”，但 POC 里连最基本的 per-site result 都没有，更别说 interaction semantics。
- 没有这层 contract，就不能认真讨论 `cmov_select + branch_reorder`、`packet_ctx_wide_load + bounds_window` 这类真实组合。

## F. Critical Issues / Red Flags

1. **Silent ignore/fail-open 直接击穿安全和实验叙事。** 当前代码无法区分“directive 生效”和“directive 被静默忽略”，这对产品和论文都不可接受。
2. **POC 的唯一已实现 directive 正是最容易被 reviewer 说成 kernel peephole 的那个。** 如果没有第二个真正 policy-sensitive 或 structural case，故事会塌。
3. **实现路径和 v7 架构不一致。** 文档说 `wide_load` 是 JIT-level；代码把它做成 verifier rewrite；x86 patch 还是 no-op。这个不统一会让所有后续评审失去信心。
4. **实验没有 same-loader control。** 当前 2.21x 数字虽然方向可信，但归因方式不够干净。
5. **userspace manual loader 不是 production path。** 它是一个 benchmark hack；如果继续把它当“端到端集成”，后面会在真实程序上踩坑。
6. **`orig_idx` / provenance 的核心难题还没碰。** 当前 POC 只证明了最简单的 delete-only case。
7. **没有 fixed kernel baselines。** 在 OSDI 语境里，这等于还没开始验证“为什么不是 kernel-only heuristic”。
8. **没有真实 workload / deployment 证据。** 当前最多证明一个 microbenchmark case，不足以支撑系统贡献。

## G. 建议

**优先级排序**

1. 先把口径改诚实。所有文档里把当前 POC 称为 `fail-closed`、`Hybrid validated`、`mechanism/policy split end-to-end` 的地方都应撤回或降级。
2. 立刻补 telemetry。最少也要有 per-site accept/reject/drop reason，哪怕只是 verifier log + `bpf_prog_info` 的最小版。
3. 立刻补 same-loader no-op control。不要再拿 `bpf_object__load()` 对 `manual_bpf_prog_load()` 做唯一对照。
4. 尽快补 digest binding。没有 exact-image identity，v7 的核心 claim 是空的。
5. 在架构上做决定。要么承认 `wide_load` 现在更适合 verifier rewrite，并改文档；要么真的去实现一个 stage-2 JIT-lowering directive，别让实现和设计长期分叉。
6. 下一个实现目标不要再选“另一个明显 peephole”。优先在 `narrow cmov_select` 和 `bounds_window` 之间二选一，至少做出一个能撑 novelty 的 case。
7. 不要继续投资 micro 自定义 loader 作为长期路径。把精力转到真实 loader integration 和 kernel selftests。

**该砍什么**

- 砍掉“v1 范围很大”的叙事。现在最危险的不是 scope 太小，而是 scope 文字太大。
- 砍掉“POC 已证明 policy plane”的说法。当前没有 policy。
- 砍掉把 `branch_reorder`、`packet_ctx_wide_load`、`subprog_inline` 说得像“只是后续实现”的轻松语气。这些是机制级难点，不是 backlog 小项。

**该保留什么**

- 保留 verifier-side `wide_load` 这条 POC 线。它至少给出了一个真实、保守、可测的 kernel-side rewrite 成功样例。
- 保留 sealed memfd 作为 transport 方向。这个选择本身没问题。
- 保留现有 micro benchmark 基础设施，但把它降级为 mechanism-isolation harness，不要拿它冒充系统级验证。

**时间线判断**

- `1-2` 周内可以做完的事：口径校正、same-loader control、最小 telemetry、文档对齐、`all` target/build 可复现性修正。
- `1-2` 个月内可以做完的事：digest-bound transport、strict error model、kernel selftests、真实 loader integration、单 directive 的 production-grade path。
- `2-4` 个月内可能做出的东西：一个真正能撑论文的第二 directive（`narrow cmov_select` 或 `bounds_window`），外加固定 kernel baseline。
- `3-6+` 个月才有机会接近 OSDI-ready：multi-directive semantics、subprog slicing、branch_reorder 或等价 structural case、跨硬件 baseline、真实 deployment evaluation。

## 最后的判断

如果目标是“证明这个想法不是空想”，当前 POC 是成功的。

如果目标是“证明 v7 设计已经站住”或“现在就够 OSDI submission”，答案是否定的，而且是否定得很明确。当前最该做的不是继续往上堆更多 directive 名字，而是把 **实现、验证、文档、claim** 四件事先对齐。

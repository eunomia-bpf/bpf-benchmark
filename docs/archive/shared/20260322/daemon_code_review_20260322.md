# daemon/ Code Review - 2026-03-22

审查范围：已逐个阅读 `daemon/src/` 下全部 18 个 Rust 源文件，并额外运行：

- `cargo test --manifest-path daemon/Cargo.toml`
- `cargo check --manifest-path daemon/Cargo.toml --all-targets`
- 本机 UAPI 头文件核对：`/usr/include/linux/bpf.h`、`/usr/include/linux/btf.h`

结论先行：`daemon/` 的 pass framework 和 `wide_mem` 分支修正框架有一定工程基础，但当前还不能把它视为“语义保持”的优化器。`branch_flip`、`cond_select`、`rotate`、`spectre`、kfunc 发现与 REJIT 集成这几条路径上都存在会导致误优化、误安全结论或运行时失败的问题。更严重的是，现有测试大多只验证“形状变了”，没有验证“语义还对”。

## 1. 算法正确性

- **CRITICAL** `daemon/src/passes/branch_flip.rs:258`, `daemon/src/passes/branch_flip.rs:260`, `daemon/src/passes/branch_flip.rs:189`, `daemon/src/passes/branch_flip.rs:228`
  `branch_flip` 的候选模式本身就不是 if/else。扫描逻辑把 `jcc.off` 直接当成 `then_len`，于是 `Jcc` 的目标落在 `JA` 上，而不是 else block。这样匹配到的是 “条件跳到 JA，再一起跳过 else”的形状，所谓 else body 实际不可达。随后 `fixup_branches_inline()` 又会把新 JCC 继续修正到原目标，进一步固化这个错误。
  修复建议：把模式改成真正的 diamond/if-else 形状。对于 `pc: Jcc -> else_start`，应有 `then_len = off - 1`、`ja_pc = pc + off`，并为翻转后的新布局单独计算新 JCC/JA 偏移，不要复用“保持原目标”的 generic fixup。

- **CRITICAL** `daemon/src/passes/cond_select.rs:351`
  `cond_select` 的 Pattern B (`Jcc +1 ; MOV false ; MOV true`) 不是合法的条件赋值。分支不跳时会先执行 `MOV false`，然后继续落到 `MOV true`，最终总是得到 `true_val`。把这个形状替换成 `bpf_select64()` 会直接改变程序语义。
  修复建议：删掉 Pattern B，或者要求第二个赋值前必须有显式 `JA`/`EXIT`/block split，使两条路径互斥。

- **HIGH** `daemon/src/passes/cond_select.rs:245`, `daemon/src/passes/cond_select.rs:248`, `daemon/src/passes/cond_select.rs:250`
  `cond_select` 发射参数时没有处理寄存器别名，可能在复制后续参数前就把源寄存器覆盖掉。例如 `cond_reg == r2` 时，先写 `r2 = b_val`，再 `mov r3, r2`，此时传入的 cond 已经不是原值了。`true_val` / `false_val` 如果来自 `r1`/`r2`/`r3` 也有同类问题。
  修复建议：实现 parallel-copy/swap-safe 参数搬运，或者先把所有真实源寄存器冻结到 scratch/callee-saved 寄存器，再组装 `r1`/`r2`/`r3`。

- **HIGH** `daemon/src/passes/rotate.rs:69`, `daemon/src/passes/rotate.rs:165`, `daemon/src/passes/rotate.rs:195`
  `rotate` matcher 没有证明两个移位操作来自同一个原值。任何满足 `rsh + lsh == 64` 且最终 `OR` 在一起的三条指令都会命中，即使 `tmp` 寄存器里根本不是 `dst` 的副本。这会产生 false positive。
  修复建议：把 matcher 扩展到真实的 copy+shift+shift+or 形状，或者至少通过局部 dataflow 追踪确认 `tmp` 在进入 pattern 时确实等于 `dst`。

- **HIGH** `daemon/src/passes/rotate.rs:69`, `daemon/src/passes/rotate.rs:75`, `daemon/src/passes/rotate.rs:169`
  `rotate` 也没有检查被移位的 `tmp` 是否在 site 之后仍然 live。原始序列会破坏 `tmp`，而 rewrite 后根本不再写 `tmp`。如果 `tmp` 是 `r6-r10` 并且后续继续使用，当前 pass 会静默改语义。
  修复建议：把 `tmp_reg` 记录进 `RotateSite`，并像 `wide_mem` 一样要求 `tmp_reg` 在 site 后 dead；如果要保留 `tmp` 破坏语义，则 rewrite 也必须显式重建该副作用。

- **HIGH** `daemon/src/analysis/liveness.rs:94`, `daemon/src/analysis/liveness.rs:98`, `daemon/src/analysis/liveness.rs:120`
  liveness 对 call 的 use/def 模型不正确：它把 `r1-r5` 都当作 use，却没有把 `r1-r5` 标记为 def/clobber；同时 successor 也不建 callee edge。对 helper/kfunc/BPF-to-BPF call，这会让 caller-saved 寄存器在 call 后看起来“活着但未被破坏”，导致分析结果错误或过度保守。
  修复建议：至少把 call 的 defs 扩展到 `r0-r5`；如果要支持 BPF-to-BPF subprog，再为 pseudo-call 增加 call edge 或单独做 interprocedural summary。

- **MEDIUM** `daemon/src/analysis/cfg.rs:152`, `daemon/src/analysis/cfg.rs:173`
  CFG 分析对 subprog 的建模不完整。`subprogs` 最终被构造成 `[0..n]` 加多个 `[entry..n]` 的重叠区间，而不是互不重叠的真实子程序范围；call 也只连 fall-through，不连 callee entry。
  修复建议：按排序后的 subprog entry 生成不重叠范围，并显式表示 pseudo-call 到 callee entry 的边，或者在 API 上明确该 CFG 仅为 intraprocedural 近似。

- **HIGH** `daemon/src/kfunc_discovery.rs:124`
  `find_func_btf_id()` 里的 BTF kind skip table 用错了 kind 编号。当前代码把 `2|3` 当成 `STRUCT/UNION`、把 `4` 当成 `ENUM`、把 `8` 当成 `FUNC_PROTO` 等，但本机 `linux/btf.h` 中 `2=PTR`、`3=ARRAY`、`4=STRUCT`、`13=FUNC_PROTO`。这会让遍历在真实 BTF blob 上很快失步，返回错误的 type ID 或找不到目标 kfunc。
  修复建议：直接按 `linux/btf.h` 的 `BTF_KIND_*` 常量实现完整 skip 逻辑，不要手写错位的 magic number。

- **CRITICAL** `daemon/src/passes/spectre.rs:9`, `daemon/src/passes/spectre.rs:56`
  `spectre_mitigation` 声称自己是安全 pass，但实际插入的是 `JA +0`，这只是 NOP，不是 speculation barrier。它既不能阻止错误路径上的 speculative load，也没有任何与内核/JIT 协议化的“barrier lowering” 逻辑。现在这个 pass 会给出“已加固”的错误结论。
  修复建议：如果当前只能插 placeholder，就不要把它归类为 `Security` mitigation；要么接入真正的内核/JIT 认可 barrier，要么明确改名为 instrumentation/debug pass。

## 2. 架构清晰度

- **HIGH** `daemon/src/pass.rs:29`, `daemon/src/pass.rs:109`, `daemon/src/pass.rs:434`, `daemon/src/passes/branch_flip.rs:121`
  `InsnAnnotation` 的设计和实际实现是脱节的。注释写的是“analysis 填 annotation，pass 读取 annotation”，但现有 analyses 全都只返回独立 result，不回填 `program.annotations`。更糟的是，程序改写后 `sync_annotations()` 只 resize，不重映射，旧 PC 上的 `branch_profile`/`verifier_state` 会粘在新 PC 上。`branch_flip` 又直接依赖 annotation 中的 `branch_profile`，因此一旦前面 pass 改过指令数，这些 profile 就会错位。
  修复建议：统一元数据来源。要么彻底改成 typed analysis result，不让 pass 直接读 annotation；要么把 annotation 当成真正 IR 属性并在每次 rewrite 后显式 remap/rebuild。

- **MEDIUM** `daemon/src/pass.rs:163`
  `AnalysisCache` 以 `TypeId::of::<A::Result>()` 为 key，而不是以 analysis 身份为 key。两个 analysis 只要返回同一种结果类型，就会共享同一 cache entry，出现静默冲突。
  修复建议：key 改成 `TypeId::of::<A>()` 或 `(analysis_name, result_type)`。

- **HIGH** `daemon/src/passes/mod.rs:72`, `daemon/src/passes/mod.rs:101`, `daemon/src/analysis/pgo.rs:33`, `daemon/src/passes/branch_flip.rs:121`, `daemon/src/passes/cond_select.rs:37`
  PGO 设计没有真正接通。pipeline 注册了 `PGOAnalysis`，但没有任何 pass 在 `required_analyses()` 里声明 `"pgo"`；`branch_flip` 直接去读 annotation；`cond_select.predictability_threshold` 完全没用。当前所谓 PGO-guided 优化只存在于手工给 annotation 填值的单元测试里。
  修复建议：把 profiling 数据统一接入 `AnalysisCache`，让 pass 显式请求 `PGOAnalysis`，并删除/实现掉所有未接线的参数。

- **HIGH** `daemon/src/pass.rs:278`, `daemon/src/kfunc_discovery.rs:251`, `daemon/src/main.rs:305`, `daemon/src/main.rs:419`
  kfunc 发现、rewrite 发射、REJIT 提交之间的契约不完整。`KfuncRegistry` 里保存了 `module_fd`，`bpf_prog_rejit()` 也支持 `fd_array`，但 apply 路径始终传空数组，kfunc 相关 pass 与实际 syscall 提交路径之间缺了最后一跳。
  修复建议：在 PassResult 或 program metadata 中显式记录本次 rewrite 用到了哪些 kfunc/module，然后在 `cmd_apply()` / `try_apply_one()` 中构造对应的 `fd_array`。

- **MEDIUM** `daemon/src/pass.rs:236`, `daemon/src/pass.rs:424`
  分析依赖是 stringly-typed 的，而且并不强制使用 registry 中预计算的实例。`required_analyses()` 返回字符串，PassManager 只是“尝试预跑”，真正执行时各 pass 又重新 new 一个 analysis 去 `cache.get()`。这让 ordering/identity 契约很松散。
  修复建议：把分析依赖改成 typed handle 或 trait object 引用；至少在 registry miss 时显式报错，而不是静默跳过。

## 3. 模块耦合

- **HIGH** `daemon/src/analysis/pgo.rs:33`, `daemon/src/profiler.rs:74`, `daemon/src/main.rs:361`, `daemon/src/passes/branch_flip.rs:121`
  现在有两套 PGO abstraction：`analysis::PGOAnalysis` 和 `profiler::PgoAnalysis`。前者被注册但没人消费，后者在 `profile` 命令里打印完就结束，`branch_flip` 又绕过两者直接读 annotation。模块之间没有一个闭环的数据通路。
  修复建议：合并成一套 PGO 数据模型，并定义从 profiler 采样到 pass 消费的唯一入口。

- **HIGH** `daemon/src/kfunc_discovery.rs:17`, `daemon/src/pass.rs:272`, `daemon/src/main.rs:305`
  kfunc 模块 FD 的生命周期和使用方耦合是隐式的。discovery 打开 module BTF FD，`main()` 只靠 `_module_fds` 局部变量把它们留活，但真正的 apply path 不消费这些 FD。`rotate`/`cond_select` 看起来可用，实际上 REJIT 阶段并没有拿到依赖。
  修复建议：把 “需要哪些 module FD” 做成显式 API，不要靠注释和约定维持。

- **MEDIUM** `daemon/src/pass.rs:41`, `daemon/src/verifier_log.rs:41`
  verifier log parser 和 pass framework 之间也只有“字段上看起来能接”的弱耦合：`InsnAnnotation` 有 `verifier_state`，但没有任何地方调用 `parse_verifier_log()` 并把结果挂进去。这个模块边界目前是断的。
  修复建议：要么把 verifier log 解析真正接到 rewrite pipeline，要么删掉这层半成品接口，避免误导后续开发。

## 4. 死代码

- **LOW** `daemon/src/analysis/mod.rs:9`
  `analysis/mod.rs` 导出了大量当前完全未使用的 symbol。`cargo check --all-targets` 已经对这些 re-export 给出 unused-import warning。
  修复建议：删掉未使用 re-export，或者在外部真正消费这些类型后再导出。

- **LOW** `daemon/src/passes/cond_select.rs:37`, `daemon/src/passes/cond_select.rs:55`
  `predictability_threshold` 和 `jcc_src_reg` 当前都没有任何生产代码读取。它们让 API 看起来比实际能力更强。
  修复建议：要么实现掉相关功能，要么删掉字段，避免接口漂移。

- **LOW** `daemon/src/passes/mod.rs:88`
  `build_full_pipeline()` 目前没有调用点。
  修复建议：如果 CLI 不会走这条路径，就删除；如果希望暴露 full pipeline，就在 CLI 中提供明确入口并补集成测试。

- **MEDIUM** `daemon/src/verifier_log.rs:41`
  `verifier_log.rs` 整个模块在生产路径中都是死代码；`cargo check` 对其几乎所有函数都报告了 dead_code。
  修复建议：短期要么删除，要么先在 CLI/调试命令里挂上使用点；否则后续维护成本只会增加。

- **MEDIUM** `daemon/src/analysis/pgo.rs:33`, `daemon/src/profiler.rs:74`
  PGO 相关存在重复但未真正消费的结构体和字段。`analysis::PGOResult` / `ProfilingData`、`profiler::PgoAnalysis` 都没有进入 pass 决策闭环。
  修复建议：统一为单一数据模型，删掉另一套。

- **LOW** `daemon/src/pass.rs:19`, `daemon/src/pass.rs:31`, `daemon/src/pass.rs:284`, `daemon/src/pass.rs:302`
  `ProgMeta`、`InsnAnnotation`、`PlatformCapabilities`、`PolicyConfig` 中有大块字段当前无人使用，`cargo check` 已经把它们标成 dead code。这里反映的是“设计超前于实现”。
  修复建议：对保留字段给出明确近期接线计划；否则先裁掉无用接口面。

## 5. 测试充分性

- **HIGH** `daemon/src/passes/cond_select.rs:463`, `daemon/src/passes/cond_select.rs:600`
  `cond_select` 的测试验证的是“命中了 pattern 并发出 kfunc call”，而不是“改写前后选择语义一致”。因此 Pattern B 这种本身就不成立的 CFG 也能全部通过。
  修复建议：增加语义级测试。最简单的做法是写一个小型 BPF IR interpreter 或 CFG oracle，对改写前后的所有输入分支路径做等价性比较。

- **HIGH** `daemon/src/passes/branch_flip.rs:361`, `daemon/src/passes/branch_flip.rs:489`, `daemon/src/passes/branch_flip.rs:533`
  `branch_flip` 的测试把 `jcc -> JA` 当成了“else 路径”，从测试数据开始就把 off-by-one 模式写错了，所以单测其实是在帮错误实现背书。
  修复建议：用真正的 if/else CFG 重新写测试，并额外检查翻转后的 branch target 是否落到新 then/else body，而不是落到 JA。

- **HIGH** `daemon/src/passes/rotate.rs:273`
  `rotate` 没有任何负例去证明 `tmp` 必须来自同一个原值，也没有覆盖 “tmp live-out” 的情况。当前 matcher 的最大风险正是这两个点，但单测完全没碰。
  修复建议：增加至少两类测试：`tmp` 来自无关值的 false-positive 用例，以及 `tmp=r6` 且 site 后继续读取的语义回归用例。

- **HIGH** `daemon/src/kfunc_discovery.rs:275`
  kfunc 发现测试只构造了“纯 FUNC 类型”的极简 BTF blob，没有任何混合 `PTR/ARRAY/STRUCT/FUNC_PROTO` 的真实布局，因此 skip-table bug 完全没被打到。
  修复建议：加入更接近真实内核 BTF 的混合-kind 测试样本，至少覆盖 `ARRAY`、`STRUCT`、`FUNC_PROTO` 三类。

- **MEDIUM** `daemon/src/analysis/liveness.rs:215`, `daemon/src/analysis/cfg.rs:213`
  analysis 测试缺少 call/subprog 相关边界。当前没有 helper/kfunc/pseudo-call 的 liveness 测试，也没有验证 CFG 的 subprog range 和 call edge。
  修复建议：加入 helper call、kfunc call、BPF-to-BPF pseudo-call 三组 case，并检查 live_in/live_out 以及 CFG 边集。

- **MEDIUM** `daemon/src/main.rs:256`, `daemon/src/main.rs:383`
  没有任何集成测试覆盖 `cmd_apply()` / `try_apply_one()` 与 `bpf_prog_rejit(fd_array=...)` 的连接，因此 “kfunc pass 可运行但 apply 必失败” 这种问题只能到运行时暴露。
  修复建议：把 `bpf_prog_rejit()` 抽成可 mock 的接口，测试当 program 中包含 kfunc call 时是否传入了正确的 `fd_array`。

- **LOW** `daemon/src/passes/wide_mem.rs:674`, `daemon/src/passes/wide_mem.rs:1126`
  `wide_mem` 的测试整体是 5 个 pass 里最好的，但仍然缺少 high-first 8-byte ladder、width 5/6/7 skip 行为等边界样例。现在只特判了 width 3。
  修复建议：补齐 5/6/7/8 相关边界，尤其是高位优先 8-byte 模式和混合支持/不支持宽度并存的程序。

## 总体评价

优点：

- `pass.rs` 的骨架清楚，`PassManager` / `AnalysisCache` / `TransformEntry` 的分层方向是对的。
- `wide_mem` 的 pattern matching、safety filter 和 branch fixup 单测相对扎实。
- `cargo test` 当前 145 个单测全部通过，说明代码在“作者预期的形状”上有一定自洽性。

主要问题：

- 多个 pass 的“形状识别”并没有被语义测试约束，已经出现了明显的 CFG 误判和寄存器别名问题。
- PGO、verifier-state、kfunc fd_array 这些横切特性都只完成了一半，模块之间没有真正闭环。
- `cargo check --all-targets` 报出了大量 dead code / unused-field warning，说明接口面明显大于实际实现面。

综合判断：目前这套 daemon 更像“研究原型中的 pass playground”，还不是可以安全连接到 live kernel programs 的 production-grade rewrite engine。

## 优先修复清单

1. 立即禁用 `branch_flip`，并删除 `cond_select` 的 3-insn Pattern B，直到 CFG 语义和测试全部修正。
2. 修复 `cond_select` 的参数搬运别名问题，以及 `rotate` 的 provenance/live-out 检查。
3. 停止把 `spectre_mitigation` 当作安全 pass 对外宣称，除非接入真实 speculation barrier。
4. 修复 `kfunc_discovery` 的 BTF 遍历逻辑，并把 module `fd_array` 从 discovery 一直打通到 `BPF_PROG_REJIT`。
5. 统一 annotation / analysis / profiler 三条元数据路径，特别是把 PGO 和 verifier-state 接成一条真实可用的数据流。

## 验证记录

- `cargo test --manifest-path daemon/Cargo.toml`：145 tests passed，0 failed。
- `cargo check --manifest-path daemon/Cargo.toml --all-targets`：通过，但存在大量 unused-import / dead-code warning；这些 warning 与上文“死代码/未接线接口”的结论一致。

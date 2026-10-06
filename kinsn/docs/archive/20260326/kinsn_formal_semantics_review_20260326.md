# kinsn Formal Semantics Review (2026-03-26)

## 1. 总体评价

这两份文档说明了实现边界，也能看出作者在努力把 `instantiate_insn()`、proof lowering、native emit、daemon side condition 放进一个统一叙述里。但以 OSDI/SOSP formal section 的标准看，当前版本还**远未达到可投稿状态**。

核心问题不在“写得不够多”，而在“关键 theorem/proof sketch 目前不正确或至少不完整”。最严重的是：

- `Whole-Program Refinement` 的对象和程序阶段定义混乱，`P` 到底是原始程序还是 lowered 程序没有讲清。
- proof sketch 依赖 “structural induction on topological order”，但这对包含 loop 的 BPF 程序根本不成立。
- failure-mode 叙述与真实 verifier/JIT pipeline 不一致，尤其是 “native emit JIT 失败后回退到 lowered BPF/interpreter” 这一点，代码并不支持文档中描述的语义。
- per-instance 语义里至少有一处和实现直接不符：`extract64` 的 x86 native path 不是 `BEXTR`，而是 `SHR + AND imm32`。

如果把它当成“设计/appendix note”，现在的质量还可以；如果把它当成论文中的正式 formal section，它现在会被严格 reviewer 直接打回。

## 2. 形式化严谨性问题

### P0: Whole-Program theorem 的程序对象定义自相矛盾，proof sketch 也不成立

`docs/kinsn-formal-semantics.md:121-123` 写的是：

> Let `P` be a BPF program accepted by the verifier after proof lowering, containing kinsn sites `s_1, …, s_n`.

这句话本身就不成立。`docs/kinsn-design.md:205-217` 已经明确说了 verifier 在 `lower_kinsn_proof_regions()` 后分析的是 **instantiated proof sequence**，而不是原始 `sidecar + kinsn_call`；也就是说，“after proof lowering”的程序不再“contain kinsn sites”。

这会导致整个 theorem 的对象混乱：

- `P` 是原始程序 `P_src`？
- 还是 verifier 真正分析的 lowered 程序 `P_low`？
- 还是 restore 之后、供 `do_misc_fixups()` / JIT 使用的程序 `P_restored`？

现在 theorem 直接比较 `P_jit` 和 `P_low`（`docs/kinsn-formal-semantics.md:129-136`），但没有定义从哪个程序经过哪一步得到它们。按照真实实现，至少应该区分：

- `P_src`: 含 `sidecar + kinsn_call`
- `P_low`: `lower_kinsn_proof_regions()` 之后的 proof-sequence 程序（`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`）
- `P_restored`: `restore_kinsn_proof_regions()` 之后恢复原 site 的程序（`vendor/linux-framework/kernel/bpf/verifier.c:3837-3880`）
- `P_fix`: `do_misc_fixups()` 之后，部分 site 可能被 fallback lower 的程序（`vendor/linux-framework/kernel/bpf/verifier.c:23720-23798`）
- `P_jit`: 对 `P_fix` 做 arch JIT 后的结果

proof sketch 里更严重的问题是 `docs/kinsn-formal-semantics.md:138-143` 的 “structural induction on the program's topological order”。`validate_kinsn_proof_seq()` 只保证 **site 内部** 没有 back-edge（`vendor/linux-framework/kernel/bpf/verifier.c:3688-3710`），它完全不保证**整个程序**无环。BPF 程序本身当然可以有 loops；kinsn site 也可以位于 loop 内。这种情况下不存在你文中所说的“program's topological order”。

所以现在的 proof sketch 不能支持 theorem。你需要的不是 topological order，而是：

- 一个明确的 small-step / trace-based simulation argument，或者
- 至少一个“单次执行到某个 site 时，native replacement preserves continuation semantics”的 lemma，再对**site 执行次数**做归纳，而不是对 CFG 的拓扑序做归纳。

这也直接影响用户问到的“相邻 kinsn sites 共享寄存器时 structural induction 是否成立”。当前写法下，答案是**不成立**；只有在你把 `LiveOut` 精确定义为 lowered CFG 上的全局 liveness，并改写为 continuation/simulation proof 后，寄存器共享才有机会被正确吸收进去。

### P0: 状态模型不足以支撑 `endian_load*` 的 refinement 结论

`docs/kinsn-formal-semantics.md:28-49` 把状态定义成 `State = (R, M)`，只保留寄存器和内存字节；`docs/kinsn-formal-semantics.md:103-111` 的 local refinement 只要求 `Valid_K(p)` 和 `Admissible_K^a(s,p)`。

这对纯寄存器 kinsn（`rotate64`/`select64`/`extract64`）还勉强够用，但对 `endian_load*` 不够。因为 `docs/kinsn-formal-semantics.md:366-377` 里的

```text
load_n(M, R[base] + offset)
```

在真实 BPF 里不是一个对任意 `(R,M)` 都 total 的函数。它依赖 verifier 建立的前置条件：

- `R[base]` 是什么 kind 的 pointer
- 这个 offset 是否在已验证的 bounds 内
- 是否满足 alignment / access-size 约束
- 是否允许该地址空间的 load

这些信息都不在 `(R, M)` 里。换句话说，当前模型**丢掉了 verifier 真正在证明安全性时依赖的抽象状态**。所以：

- “for every initial state `(R,M)` satisfying `Valid` and `Admissible`” 这句话对 `endian_load*` 不成立；
- `docs/kinsn-formal-semantics.md:136` 里的 “verifier-accepted domain” 也没有形式化定义，无法知道到底量化的是哪些初始状态。

如果你不想把 verifier abstract state 全部形式化，至少要显式引入一个额外前置条件，例如 `SafeLoad_n(base, offset, σ)` 或者 “the current verifier state proves this access is legal”，否则 theorem 里关于 memory-reading kinsn 的量词范围是不闭合的。

### P0: failure-mode 分析和真实代码路径不一致，且遗漏 late JIT failure / two-pass 语义

`docs/kinsn-formal-semantics.md:150-157` 和 `docs/kinsn-design.md:56-59` 都在暗示：

- native emit 缺失时会 fallback 到 instantiated BPF
- native emit 在 JIT 时报错时也会“kernel falls back to the interpreter on the lowered program”

前半句只对“无 native emit callback”成立；后半句和代码不符。

真实 pipeline 是：

1. verifier 先 lower，再验证，再 restore（`vendor/linux-framework/kernel/bpf/verifier.c:3723-3880`）
2. `do_misc_fixups()` 只在“未请求 JIT”或“无 native emit”时把 site lower 成普通 BPF（`vendor/linux-framework/kernel/bpf/verifier.c:23782-23795`）
3. 若保留 native kinsn site，后续 arch JIT 直接调用 module emit callback

x86 路径：

- `emit_kinsn_desc_call()` 在 JIT 时调用 `kinsn->emit_x86()`（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`）
- 如果 callback 返回负值，JIT pass 失败（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:597-600`）
- 整个 JIT compile 在 `proglen <= 0` 时走 abort/fallback（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3853-3869`）

arm64 路径同理：

- `emit_kinsn_desc_call_arm64()` 调用 `kinsn->emit_arm64()`（`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1201-1235`）
- callback 返回负值会直接让 `build_body()` 失败（`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1643-1647`, `2209-2233`）

问题在于：这时程序里保留的仍然是 `sidecar + BPF_PSEUDO_KINSN_CALL`，不是 lowered proof sequence。文档里的 “falls back to the interpreter on the lowered program” 并没有发生。

更糟的是，interpreter 对 `BPF_JMP | BPF_CALL` 的处理是直接跳到 `(__bpf_call_base + imm)`（`vendor/linux-framework/kernel/bpf/core.c:2037-2044`），并不理解 `BPF_PSEUDO_KINSN_CALL`。verifier 也明确禁止 non-JITed kinsn program（`vendor/linux-framework/kernel/bpf/verifier.c:23450-23452`）。所以这里不是一个小措辞问题，而是**你文档声称存在的安全 fallback 路径，在代码里并不存在**。

此外，failure-mode section 还漏掉了 user 明确点名的 two-pass 问题：

- x86 native emit 会在不同 JIT pass 中被重复调用（`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:597-600`, `3850-3900`）
- arm64 也会在 sizing / write pass 中重复跑 build（`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2183-2233`）

所以理论上存在 “sizing pass 成功、emit pass 失败” 的情形。当前 in-tree module callback 看起来是纯函数，应该不太会发生，但 formal section 不能靠“应该不会”支撑；你至少要把它写成显式假设：`emit_*` 对同一 `(payload, prog)` 是 deterministic 且 pass-independent。

顺带一提，`bpf_prog_select_runtime()` 只把 `kfunc` 视为 `jit_needed`（`vendor/linux-framework/kernel/bpf/core.c:2531-2554`），没有把 kinsn 单独纳入这个条件。至少从这段代码看，late JIT failure for kinsn 的最终行为是**不清楚且未文档化的**。我不会直接在 review 里把它定性成实现 bug，但你现在文档里的 fallback 叙述显然没有被代码支持。

### P1: “daemon enforced admissibility” 是 theorem 条件，不是 kernel-enforced invariant；文中把两者说混了

`docs/kinsn-formal-semantics.md:457-479` 把正确性 obligation 分成 kernel verifier 和 daemon 两部分，这本身是诚实的；但 `:477-479` 紧接着说：

> This split does not weaken the correctness guarantee...

这个说法过头了。作为**条件 theorem**，当然可以写成“只要 predicate hold，结论就 hold”；但作为**系统保证**，这确实弱了，因为：

- kernel 只检查 proof-sequence structure 和 verifier safety（`vendor/linux-framework/kernel/bpf/verifier.c:3669-3721`）
- `rotate64` 的关键 `tmp ∉ LiveOut(site)` 是 daemon 检的（`daemon/src/passes/rotate.rs:101-118`）
- arm64 `endian_load*` 的 offset compensation 也是 daemon 做的（`daemon/src/passes/endian.rs:164-210`）

换言之，当前系统的可信基并不只是 kernel verifier + module descriptor；它还包括 daemon rewrite pass。如果论文要卖“verifier-safe native optimization”这一点，必须把 TCB 讲清楚。否则系统 reviewer 会理解成“kernel 自己保证了 admissibility”，而这并不是事实。

### P1: theorem/notation 还隐含了 callback purity，但文中没有说

`docs/kinsn-formal-semantics.md:97-104` 把 native semantics 写成 `Emit_K^a(p)`，但真实 callback API 是：

- `emit_x86(..., u64 payload, const struct bpf_prog *prog)`
- `emit_arm64(..., u64 payload, const struct bpf_prog *prog)`

见 `docs/kinsn-design.md:94-99` 和 `vendor/linux-framework/include/linux/bpf.h:973-978`。

当前 in-tree module 确实都没有使用 `prog`，例如：

- `module/x86/bpf_rotate.c:103`
- `module/x86/bpf_select.c:110`
- `module/x86/bpf_extract.c:105`
- `module/x86/bpf_endian.c:165`
- `module/x86/bpf_barrier.c:32`
- `module/arm64/bpf_rotate.c:75`
- `module/arm64/bpf_select.c:78`
- `module/arm64/bpf_extract.c:71`
- `module/arm64/bpf_endian.c:166`, `207`, `247`
- `module/arm64/bpf_barrier.c:47`

但 theorem 需要把这个写成前提，否则你 formalize 的不是当前 API，而是一个更窄的理想 API。

### P1: `extract64` 的 x86 语义描述和真实实现不符

`docs/kinsn-formal-semantics.md:323-324` 和 `:342-343` 把 x86 native path 描述成 `BEXTR`。但 `module/x86/bpf_extract.c` 的真实实现是：

- `emit_shr_imm()`（`module/x86/bpf_extract.c:80-86`）
- `emit_and_imm32()`（`module/x86/bpf_extract.c:88-94`）
- `emit_extract_x86()` 里实际发的是 `SHR + AND imm32`（`module/x86/bpf_extract.c:118-121`）

也就是说，当前 formal section 至少有一处 instance definition 直接和代码不一致。这个问题不只是措辞；它会让 reviewer 怀疑你到底是 formalizing artifact 还是 formalizing an intended future implementation。

### P2: `rotate64` 的 admissibility 条件写得过强，不够精确

`docs/kinsn-formal-semantics.md:229-233` 把 `rotate64` 的 admissibility 写成无条件的 `tmp ∉ LiveOut(site)`。但真实实现允许 `shift = 0`：

- decoder 会把 shift 取 `& 63`，并不拒绝 0（`module/x86/bpf_rotate.c:22-30`, `module/arm64/bpf_rotate.c:22-30`）
- proof object 在 `shift = 0` 时只发 `MOV dst, src`（`module/x86/bpf_rotate.c:45-47`, `module/arm64/bpf_rotate.c:45-47`）
- native emit 在 `shift = 0` 时也不会写 `tmp`（`module/x86/bpf_rotate.c:116-123`, `module/arm64/bpf_rotate.c:91-95`）

因此更精确的 admissibility 应该是：

```text
shift = 0  or  tmp ∉ LiveOut(site)
```

这不影响当前 daemon rotate pass，因为它匹配的是 shift/or idiom，不会生成 `shift = 0` site；但 formal section 既然在讲 descriptor semantics，就不应把必要条件和“当前 rewrite pass 恰好只会产出的子域”混在一起。

### P2: “标准 BPF 语义 taken as given” 不足以支撑 theorem

`docs/kinsn-formal-semantics.md:71-74` 说 `Exec_BPF` taken as given from the kernel BPF specification。对系统 note 可以接受；对正式 theorem 不够。

原因很简单：你整个 refinement theorem 的 right-hand side 就是 `Exec_BPF(Inst_K(p))`。如果 base semantics 没有明确引用的 formal source，reviewer 没法判断：

- `BPF_LDX_MEM` 的精确定义
- `BPF_BSWAP` 的 16/32/64-bit zero-extension 规则
- `ALU32` vs `ALU64` 的 high-bit semantics
- `JMP_A(0)` 是否被当成 architectural no-op

Jitk/CertiKOS/seL4 之所以能让 reviewer 买账，不是因为 theorem 名字大，而是因为基底语义是明确且可追溯的。这里现在还没有做到。

## 3. 表达和呈现问题

### 3.1 记号和叙述不够稳定

我建议统一并收紧记号。当前至少有这些不稳定点：

- `P` 的阶段不清楚，见上面的 theorem 对象问题。
- `s` 同时被用作 site 下标（`π_s`）和 rotate shift 参数（`rol64(x, s)` / `Proof_rotate(..., s)`），对非 PL reviewer 很不友好。
- `docs/kinsn-formal-semantics.md:112-117` 说 “three formal pieces”，但同一文档 `:441-442` 又把对象写成 6-tuple。这里明显不一致。
- `π_s` 用的是 site-level projection，而 theorem 结论又用 `P_jit(s_0)|_{r0,M}` 这种新的投影写法（`docs/kinsn-formal-semantics.md:133`），没有先定义。

### 3.2 当前写法对系统 reviewer 来说“形式化太多，但证明太少”

这份 section 现在处于一个比较危险的中间状态：

- 形式符号已经足够多，会触发 PL/security reviewer 的严格审查；
- 但 proof obligation、program phase、simulation relation、trusted boundary 又都没有定义完整。

结果是两边都不讨好：

- 非 PL 系统 reviewer 会觉得抽象层次太高，不知道哪一条和代码真正对应；
- PL reviewer 会觉得 theorem/proof sketch 明显不够。

我建议主文里只保留：

- 一个清晰的 system model figure
- 一个 worked example（推荐 `rotate64`）
- 一个缩小后的 theorem statement

把全实例语义和细节 case-by-case definitions 放 appendix。

### 3.3 需要显式拆开三件不同的事

当前文本把三种 correctness 叙述揉在一起了：

1. 原始 BPF idiom 被 rewrite 成 kinsn site 是否语义保持
2. kinsn site 被 lower 成 proof sequence 是否 verifier-safe
3. native emit 是否 refinement of proof sequence

现在 formal section 主要在讲 (2)+(3)，但又在 `Admissible` 那里不断借用 daemon pass 的 rewrite logic（`docs/kinsn-formal-semantics.md:116-117`, `457-479`）。这会让 reader 以为你证明了 (1)，但其实没有。

如果论文主张是 “modular, verifier-safe JIT optimization”，那至少应该清楚说：

- 本节只证明 (3)，
- (1) 目前只是 trusted pass invariant / engineering argument，
- 或者给出一个单独的 rewrite-soundness theorem。

### 3.4 `speculation_barrier` 的 formal scope 需要更尖锐地界定

你现在已经承认模型不编码 microarchitectural speculation state（`docs/kinsn-formal-semantics.md:47-49`, `421-432`, `481-498`），这是好的。但论文里如果想把 barrier 当成 security contribution，必须把边界说得更直白：

- 现有 theorem 只证明 architectural state preservation；
- 对 Spectre-style ordering / speculation property，没有 formal proof，只是实现-level contract。

否则 reviewer 会把 `Proof_barrier = identity` 与 “security barrier” 并置理解为 overclaim。

## 4. 论文就绪度评估

### 4.1 结论：目前不具备 OSDI 投稿水准

如果这是 OSDI/SOSP 主文中的正式 formal section，我的结论是：**现在还不能投**。主要不是“还需要补几个定义”，而是：

- theorem statement 需要重写；
- proof strategy 需要换；
- failure semantics 需要和代码重新对齐；
- 可信基和 daemon obligation 需要诚实重述；
- 还有至少一处 instance 语义要改正。

### 4.2 细节层次也不太适合系统论文主文

现在这份 section 同时做了两件事：

- 讲当前实现的 artifact-accurate 细节
- 试图给出 theorem-level correctness story

但两者没有很好分层。对系统论文更合理的结构是：

- 主文：系统模型、trusted boundary、1 个代表性例子、1 个缩小版 theorem
- appendix：每个 kinsn 实例的 algebraic semantics，外加 artifact cross-reference

### 4.3 有些 claim 需要实验支撑，有些 claim 不能靠实验替代

需要实验/数据支撑的，是这些系统层面的说法：

- daemon side condition 在真实 corpus 上覆盖率如何，跳过率如何
- arm64 `endian` offset compensation 常见不常见
- rotate `tmp ∉ LiveOut` 在真实 workload 中有多少命中/miss

但 formal claims 不能靠实验替代。比如：

- “Whole-Program Refinement”
- “proof-carrying semantics”
- “fallback always returns to verified proof path”

这些必须靠精确定义和 proof / validated checker 支撑，而不是 test suite。

### 4.4 和 Jitk / CertiKOS / seL4 相比，当前 rigor 差距很大

如果你主动把这段和 Jitk、CertiKOS、seL4 放在一起比，reviewer 会很快看出差距：

- 没有 mechanization
- 没有明确的 machine model / verifier-state model
- 没有 simulation relation
- 没有 lemma chain
- 没有 proof artifact 或 validator

就目前文本而言，它更像是：

- 一个高质量的 design appendix，或者
- 一个 artifact note

而不是能够和上述工作同类比较的 formal section。

## 5. 具体建议

### 优先级 1

重写 theorem 的 program pipeline。建议显式引入 `P_src -> P_low -> P_restored -> P_fix -> P_jit`，并说明每个 theorem/lemma 是在哪两个阶段之间比较。

### 优先级 2

删除 “topological order” 这套 proof sketch，改成 trace-based / small-step simulation，或者至少改成“对 site 执行次数的归纳”。否则 theorem 会被一眼看穿。

### 优先级 3

把 verifier 依赖的 memory-safety / pointer-provenance 前置条件显式加入模型。最小可接受版本也要为 `endian_load*` 引入一个 `SafeLoad` 类谓词；更好的版本是引用 verifier abstract state。

### 优先级 4

修正文档中的 failure semantics：

- “no native emit” fallback 到 proof sequence：对
- “late native emit failure” fallback 到 lowered interpreter：当前代码不支持，不能这么写
- 明确讨论 repeated `instantiate_insn` / multi-pass `emit_*` 的 determinism 假设

### 优先级 5

修正 `extract64` 的 x86 描述。当前实现不是 `BEXTR`，而是 `SHR + AND imm32`；如果未来想换成 `BEXTR`，那就等代码真换了再写。

### 优先级 6

把 TCB 说清楚。现在系统保证至少依赖：

- kernel verifier
- module descriptor/decoder
- daemon rewrite passes

如果论文想弱化 TCB，就需要把关键 admissibility checks 往 kernel 里推，或者让 payload/validator 自描述这些条件。

### 优先级 7

谨慎使用 “proof-carrying semantics” 这个词。当前更准确的说法是：`instantiate_insn()` 生成一个 **verifier-checked proof witness / witness sequence**。如果没有更强的 formal account，不建议直接借用 proof-carrying code 的话语。

### 优先级 8

主文只保留一个 worked example（建议 `rotate64`），把 `select/extract/endian/barrier` 的完整 algebraic definitions 放 appendix。否则主文过于 dense，但 rigor 又还不够。

### 优先级 9

在 appendix 或 artifact note 里单独列一个 “Implementation Assumptions” 小节，明确写出：

- all current emit callbacks ignore `prog`
- all current callbacks are deterministic and pass-independent
- current proof sequences do not use stack/memory writes/calls

这些在 reviewer 看来都是隐藏假设；你主动写出来，会比让 reviewer 自己挖出来更好。

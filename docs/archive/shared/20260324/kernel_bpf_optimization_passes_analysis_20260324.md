# Linux 内核现有 eBPF 优化 Pass 完整分析 + 与 BpfReJIT 对比

日期：2026-03-24

## TL;DR

1. Linux 内核现有 eBPF “优化”并不是一个 LLVM/GCC 式 middle-end；主体是 verifier/fixup 阶段的少量硬编码 rewrite，再加上架构 JIT 的浅层 peephole。
2. 这些代码里相当一部分其实是安全硬化或功能性 legalization，不是纯性能优化。
3. 以“上游等价、pass-like 的优化/硬化/特化代码”为口径，在 `kernel/bpf/verifier.c` + `arch/x86/net/bpf_jit_comp.c` + `arch/arm64/net/bpf_jit_comp.c` 中一共能数出约 **1,749 LOC**。
4. BpfReJIT 已实现的 7 个 daemon pass 本身就有 **5,555 LOC Rust**；整个 daemon 为 **12,191 LOC Rust**。内核现有 pass-like 逻辑与 BpfReJIT 的差别，不是“内核什么都没做”，而是“内核只做了少量固定 rewrite；BpfReJIT 提供了一个可扩展、可重编译、可加 profile/runtime 信息的优化框架”。
5. 内核与 BpfReJIT 的重叠主要在 helper/map inline、endianness lowering、Spectre 硬化；BpfReJIT 的真正差异化在 `wide_mem`、`rotate`、`cond_select`、`extract`、`endian_fusion`、`branch_flip`、runtime specialization/DCE 这类内核现在不做或只做了很小子集的变换。

## 0. 范围、口径、方法

### 0.1 主要阅读对象

- `docs/kernel-jit-optimization-plan.md`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/include/linux/bpf.h`
- `daemon/src/passes/*.rs`

### 0.2 重要 caveat：`vendor/linux-framework` 不是纯上游基线

当前 `vendor/linux-framework` 工作树是 dirty 的，已经混入了 BpfReJIT vendor-only 改动。和本报告最相关的两处是：

- `kernel/bpf/verifier.c:23917-23944`
  - kinsn sidecar lowering，**22 LOC**
- `arch/arm64/net/bpf_jit_comp.c:1627-1635`
  - ARM64 kinsn call inline，**8 LOC**

这两段都存在于当前 vendor tree，但不应算进“Linux 内核现有 eBPF 优化 baseline”。下文会明确标注，并在总 LOC 里扣除。

### 0.3 LOC 统计口径

- 统计单位：非空、非注释的 C/Rust 代码行。
- 对于单一职责函数，直接统计整个函数。
- 对于 `do_misc_fixups()`、`convert_ctx_accesses()` 这类大函数，先统计函数总量，再做子块拆分说明。
- **主口径总数 1,749 LOC**：
  - 包含：上游等价的 verifier/fixup/JIT/post-JIT pass-like 优化、硬化、特化逻辑
  - 不包含：上面两段 vendor-only kinsn 代码
  - 也不包含：一些通用 backend 机制性代码，例如 x86 `emit_indirect_jump()` / `emit_spectre_bhb_barrier()` 这类更偏“通用分支硬化 helper”的逻辑；这些会分析，但不并入主表总数

### 0.4 真实 pipeline

在 `kernel/bpf/verifier.c:26615-26668`，程序在主验证结束后，按如下顺序进入 rewrite/fixup/JIT 前优化管线：

1. `mark_fastcall_patterns()`
2. `remove_fastcall_spills_fills()`
3. `optimize_bpf_loop()`
4. `opt_hard_wire_dead_code_branches()`
5. `opt_remove_dead_code()`
6. `opt_remove_nops()`
7. `convert_ctx_accesses()`
8. `do_misc_fixups()`
9. `opt_subreg_zext_lo32_rnd_hi32()`

这已经说明一个关键事实：内核 eBPF “优化”主要发生在 **verification 之后、JIT 之前的 fixup/rewrite 层**，不是一个独立的 SSA optimizer。

## 1. 按类别分组的逐 pass 枚举

## 1.1 Verification-Time：验证期决定的优化/硬化

这一类逻辑发生在 verifier 的抽象解释阶段，本身不一定直接改字节码，但会设置 `insn_aux_data` 或寄存器状态，供后面的 fixup/JIT 使用。

| 项目 | 位置 | LOC | 触发条件 | 做了什么 | 性质 | 效果/备注 |
| --- | --- | ---: | --- | --- | --- | --- |
| `sanitize_val_alu()` / `sanitize_ptr_alu()` / `update_alu_sanitation_state()` / `can_skip_alu_sanitation()` | `kernel/bpf/verifier.c:15052-15212` | 111 | 指针/标量 `ADD/SUB`，且不能 bypass Spectre v1、不是立即数特例、也未被更早 `nospec` 覆盖 | 计算并记录 `aux->alu_state`、`aux->alu_limit`，为后续 masking patch 准备窗口 | 安全 | Spectre v1 指针算术硬化；真正 patch 发生在 `do_misc_fixups()` |
| `nospec_result` 标记（栈写结果） | `kernel/bpf/verifier.c:5748-5760` | 10 | 写栈结果可能来自 spillable reg 或非纯 `STACK_MISC/STACK_ZERO` 槽位 | 置位 `insn_aux_data[].nospec_result`，后续在写之后插 `BPF_ST_NOSPEC` | 安全 | 主要为 Spectre v4 |
| 主验证循环中的 `nospec` 恢复逻辑 | `kernel/bpf/verifier.c:21822-21872`；辅助判定 `2116-2125` | 26 | speculative path 遇到可恢复错误：`-EPERM/-EACCES/-EINVAL` | 在危险指令前记录 `insn_aux->nospec = true`，并停止该 speculative path | 安全 | 让程序可能通过“插 barrier”而不是直接 reject |

### 1.1.1 其他 verifier 期“小优化”，不是独立 pass，但值得写进 related work

这些不计入 1,749 LOC 主总数，因为它们散落在 verifier 语义逻辑里，不是单独的 rewrite pass。

- `update_loop_inline_state()`：`kernel/bpf/verifier.c:12057-12073`
  - 作用：在验证 `BPF_FUNC_loop` 时记录这个 site 是否“适合 inline”。
  - 触发：`flags == 0`，并且不同路径上看到的是同一个 callback subprog。
  - 作用性质：优化准备，不是直接 rewrite。

- const-key map lookup nullness elision
  - key 收集：`kernel/bpf/verifier.c:10482-10490`
  - nullness 消除：`kernel/bpf/verifier.c:12452-12456`
  - map 类型判定：`kernel/bpf/verifier.c:12079-12087`
  - 作用：对于 `ARRAY/PERCPU_ARRAY` 且 key 为编译期常量、并且 `< max_entries` 的 `bpf_map_lookup_elem()`，直接清掉返回值的 `PTR_MAYBE_NULL`。
  - 触发条件：常量 key + 支持该性质的 map 类型。
  - 性质：纯优化/特化。
  - 备注：这是 verifier 利用静态信息做的“小 specialization”，但规模很有限。

## 1.2 Fixup Stage：verify 后、JIT 前的 rewrite/peephole

这是内核现有 eBPF 优化最密集的区域。

| Pass / 子系统 | 位置 | LOC | 触发条件 | 一句话说明 | 性质 | 效果/备注 |
| --- | --- | ---: | --- | --- | --- | --- |
| `mark_fastcall_pattern_for_call()` + `mark_fastcall_patterns()` | `kernel/bpf/verifier.c:18928-19040` | 66 | helper/kfunc 周围出现 clang 生成的 spill/call/fill fastcall pattern | 识别可消去 spill/fill 的 fastcall pattern，并检查 stack contract | 优化准备 | 为后续删 spill/fill 做标记；无公开 benchmark |
| `remove_fastcall_spills_fills()` | `kernel/bpf/verifier.c:25013-25042` | 27 | `aux[i].fastcall_spills_num > 0` 且 contract 成立 | 把 call 前后的 spill/fill 改成 NOP，并在可行时下调子程序 stack depth | 纯优化 | 每个 site 删除 `2 * spills_num` 条 BPF 指令；还能减少栈深 |
| `inline_bpf_loop()` + `optimize_bpf_loop()` | `kernel/bpf/verifier.c:24873-25008` | 84 | `BPF_FUNC_loop` 且 `loop_inline_state.fit_for_inline` 为真 | 把 `bpf_loop()` helper 调用展开成显式循环模板 | 纯优化 | 已知公开数据：提交 `1ade23711971` 给出 `14 ns/op -> 2 ns/op` |
| `opt_hard_wire_dead_code_branches()` | `kernel/bpf/verifier.c:22817-22841` | 21 | 条件跳转一边是 `aux_data[].seen == false` | 把“必走某一边”的条件跳转硬连线成 `JA` | 纯优化 | 为后续 DCE 创造条件 |
| `opt_remove_dead_code()` | `kernel/bpf/verifier.c:22843-22865` | 19 | 指令从未被 verifier 看到 | 删除不可达指令块 | 纯优化 | 减少 BPF insn 数与 JIT 工作量 |
| `opt_remove_nops()` | `kernel/bpf/verifier.c:22870-22893` | 19 | `JA +0` 或 `MAY_GOTO_0` | 删除 rewrite 之后遗留的 NOP | 纯优化 | 缩短程序 |
| `verifier_inlines_helper_call()` | `kernel/bpf/verifier.c:18788-18802` | 15 | x86/ARM64 支持 percpu insn，且 helper 属于白名单 | 作为 capability gate，决定部分 helper 是否走 verifier-side inline | 优化 gate | 自己不改程序，但控制后续 `do_misc_fixups()` |
| `convert_ctx_accesses()` | `kernel/bpf/verifier.c:23001-23299` | 243 | ctx/sock/BTF/ARENA 访问、epilogue/prologue、`nospec` 标记 | 重写 ctx 访问、插入 `BPF_ST_NOSPEC`、做窄 load widening、生成 prologue/epilogue | 混合：功能 + 安全 + 小优化 | 内核现有“结构化 specialization”核心之一 |
| `do_misc_fixups()`（扣除 vendor-only kinsn 后） | `kernel/bpf/verifier.c:23882-24870` | 721 | helper call、tail call、LD_ABS/IND、ptr ALU、map op、tracing helper 等 | 大一统 legalization/inline/specialization 阶段 | 混合：功能 + 优化 + 安全 | 这是内核 eBPF rewrite 的主战场 |
| `opt_subreg_zext_lo32_rnd_hi32()` | `kernel/bpf/verifier.c:22895-22994` | 71 | `zext_dst`、`CMPXCHG`、arch 需要 zext，或测试模式 `BPF_F_TEST_RND_HI32` | 自动补 `ZEXT`，或在测试模式下随机化高 32 位 | 主要是功能/正确性 | 更偏 backend/legalization，不是性能 pass |

关于 `opt_subreg_zext_lo32_rnd_hi32()` 还要注意两点：

- generic 默认的 `bpf_jit_needs_zext()` 在 `kernel/bpf/core.c:3094-3097` 返回 `false`
- 因此这个 pass 的常见用途不是“所有架构都额外优化一次”，而是 **按架构 JIT 需求补齐 zero-extension 语义**，或在测试模式下故意随机化高 32 位来抓 bug

### 1.2.1 `convert_ctx_accesses()` 内部到底做了哪些优化/特化

`convert_ctx_accesses()` 是一个典型的“内核不是在做 generic optimization，而是在做 program-type-specific rewrite”的例子：

- `23016-23066`
  - materialize epilogue/prologue
  - 为 epilogue 保存 `ARG_PTR_TO_CTX`
- `23077-23097`
  - 若 `insn_aux_data[].nospec` 为真，在指令前插入 `BPF_ST_NOSPEC()`
- `23147-23165`
  - 若 `nospec_result` 为真，在写/调用之后插 barrier
- `23167-23217`
  - 将 `PTR_TO_BTF_ID` / `PTR_TO_MEM|PTR_UNTRUSTED` / `PTR_TO_ARENA` 访问转换为 `BPF_PROBE_MEM` / `BPF_PROBE_MEMSX` / `BPF_PROBE_ATOMIC`
- `23223-23284`
  - 对“窄于 ctx field 宽度”的 load，先扩成 4/8-byte load，再在 patch 后补 `RSH/AND` 或 sign-extend

这里真正接近“优化”的点主要有两个：

1. **窄 ctx load widening**
   - 条件：`size < ctx_field_size`
   - 作用：减少 program-type-specific convert hook 复杂度，并让后续 JIT 看到更规范的 4/8-byte load
   - 局限：只针对 ctx field，不是 generic wide-load combine

2. **epilogue 共享**
   - 多个 `EXIT` 可以跳转到共享 epilogue
   - 这更像功能性代码复用与 CFG 规整，而不是 aggressive optimization

### 1.2.2 `do_misc_fixups()` 子块拆分

`do_misc_fixups()` 体量很大，必须拆开看。下面 LOC 是子块级代码量；和 721 LOC 总量并不严格相加，因为函数内部还有循环/控制流骨架。

| 子块 | 位置 | LOC | 触发条件 | 说明 | 性质 |
| --- | --- | ---: | --- | --- | --- |
| `kinsn_sidecar_lowering` | `23917-23944` | 22 | 当前 vendor tree 的 kinsn sidecar | BpfReJIT vendor-only；**不计入 baseline** | vendor-only |
| `addr_space_cast_mov32` | `23946-23955` | 8 | arena addr-space cast 或 `BPF_F_NO_USER_CONV` | 把特定 `MOV64` 改成清高 32 的 `MOV32` | 功能/特化 |
| `needs_zext_alu32_rewrite` | `23958-23960` | 2 | `aux.needs_zext` | 把 `ALU64` 改写成 `ALU32` | 功能 |
| `div_mod_exception_rewrite` | `23962-24080` | 97 | `DIV/MOD` 存在 0/-1 异常路径 | 插保护序列，避免架构异常 | 功能/安全 |
| `probe_mem_user_addr_guard` | `24082-24110` | 24 | `BPF_PROBE_MEM*` 且 arch 提供 `uaddress_limit` | 在真正 load 前加 userspace 地址上界过滤 | 安全 |
| `ld_abs_ld_ind_lowering` | `24112-24130` | 16 | `LD_ABS` / `LD_IND` | 调 `gen_ld_abs()` 做 rewrite | 功能 |
| `ptr_alu_mask_patch` | `24132-24183` | 46 | earlier verifier 标记了 `aux->alu_state` | 把 Spectre v1 指针 masking patch 真正插进程序 | 安全 |
| `may_goto_lowering` | `24185-24249` | 40 | `may_goto` 指令 | 展开计数/超时辅助逻辑 | 功能 |
| `kfunc_call_fixup` | `24257-24271` | 13 | pseudo kfunc call | 修正 kfunc 调用点 | 功能 |
| `tail_call_rewrite_and_spec_mask` | `24284-24357` | 49 | `BPF_FUNC_tail_call` | 改 opcode、构造 poke descriptor，或为 unpriv tail-call 插 index mask 防 speculation OOB | 优化 + 安全 |
| `timer_set_callback_aux_inject` | `24359-24390` | 16 | `BPF_FUNC_timer_set_callback` | 在 helper 前注入 `prog->aux` 地址 | 功能 |
| `storage_get_gfp_specialize` | `24392-24408` | 15 | storage_get helper | 根据 sleepable 性质自动注入 `GFP_ATOMIC/GFP_KERNEL` | 特化 |
| `percpu_alloc_ptr_helper_fixup` | `24410-24427` | 12 | `call_with_percpu_alloc_ptr` | 先解一层 percpu data ptr 再调用 helper | 功能/特化 |
| `map_ops_inline_and_direct_call` | `24429-24526` | 88 | JIT 请求、64-bit、map ptr 未 poison、helper 属于 map op 集合 | `map_lookup_elem` 可完整 inline；其余 map op 直接改成具体 map ops 函数，避免 generic helper/retpoline | 纯优化 |
| `jiffies64_inline` | `24528-24551` | 20 | `BPF_FUNC_jiffies64`、64-bit、JIT 请求 | 直接内联为读 `jiffies` | 优化 |
| `x86_percpu_helper_inline` | `24553-24597` | 34 | x86_64 且 helper 为 `get_smp_processor_id` / `get_current_task[_btf]` | 直接内联 percpu/current_task 读取 | 纯优化 |
| `tracing_helper_inlines` | `24599-24758` | 106 | tracing prog 上的 `get_func_arg/ret/arg_cnt/ip/branch_snapshot` | 将多个 tracing helper rewrite 成直接 ctx/stack 操作 | 纯优化/特化 |
| `kptr_xchg_inline` | `24760-24776` | 14 | `BPF_FUNC_kptr_xchg` 且 JIT 支持 ptr xchg | 内联为原子交换 | 纯优化 |

### 1.2.3 `do_misc_fixups()` 的核心观察

1. `do_misc_fixups()` 里既有真正的 speed optimization，也有大量“为了正确运行必须做”的 legalization。
2. 最接近“纯优化”的块只有少数几类：
   - fastcall spill/fill 删除
   - `bpf_loop` inline
   - map op direct-call / map lookup inline
   - `jiffies64` inline
   - x86 percpu helper inline
   - tracing helper inline
   - `kptr_xchg` inline
3. Spectre 相关的 `ptr_alu_mask_patch`、tail-call index mask、`BPF_ST_NOSPEC` 插入，都是 **安全硬化**，不是性能优化。

## 1.3 JIT Stage：x86 / ARM64 codegen peephole

## 1.3.1 x86

| Peephole / 机制 | 位置 | LOC | 触发条件 | 做了什么 | 性质 | 效果/备注 |
| --- | --- | ---: | --- | --- | --- | --- |
| `emit_mov_imm32()` 短编码 | `arch/x86/net/bpf_jit_comp.c:934-972` | 26 | `MOV imm32`，尤其 `imm32 >= 0` 或 `imm32 == 0` | 用更短的 x86 编码：正数用 `mov eax, imm32`，零用 `xor eax, eax` | 纯优化 | 省 2-3 字节 |
| BMI2 variable shift lowering (`emit_shiftx()` + 调用点) | `1593-1603`, `2023-2043` | 25 | CPU 支持 BMI2 且 shift count 不在 `rcx` | 用 `shrx/sarx/shlx` 代替传统 `mov rcx; d3` 路径 | 纯优化 | 少一次寄存器搬运；无公开 perf |
| `cast_user` 的 `cmove` lowering | `1780-1811` | 19 | `insn_is_cast_user(insn)` | 用 `cmove` 生成 cast-user fast path | 功能 + 安全特化 | 不是 generic if-conversion |
| `BPF_END` / zero-extend / `BPF_ST_NOSPEC` lowering | `2076-2137` | 48 | `BPF_END` 或 `BPF_ST|BPF_NOSPEC` | 16-bit 用 `ror`+`movzwl`，32/64-bit 用 `bswap`；`BPF_ST_NOSPEC` -> `LFENCE` | 优化 + 安全 | 对 endianness 做得不错，但不是 load+swap fusion |
| jump shrink + NOP `JA` 消除 | `2639-2745` | 57 | 分支目标可用 imm8，或 `JA` 实际 offset 为 0 | 将长跳缩成短跳，并删掉无意义 `JA +0` | 纯优化 | 降代码尺寸；减少指令字节 |
| 多轮 fixed-point shrink | `3828-3848` | 10 | x86 JIT 整体生成 | 重复生成直到 image 不再 shrink | 纯优化 | 为 jump shrink 提供收敛机制 |

### 1.3.1.1 x86 JIT 中相关但不并入主 LOC 的硬化机制

- `emit_indirect_jump()`：`arch/x86/net/bpf_jit_comp.c:693-710`，17 LOC
  - 根据 CPU 特性选 ITS thunk / LFENCE / retpoline thunk
- `emit_spectre_bhb_barrier()`：`arch/x86/net/bpf_jit_comp.c:1635-1668`，19 LOC
  - 插 `IBHF` / clear BHB 序列

这些非常重要，但它们更像 **x86 backend 通用分支硬化 helper**，而不是 BPF bytecode 级别的 rewrite pass，所以本文只分析、不计入 1,749 LOC 主总数。

## 1.3.2 ARM64

| Peephole / 机制 | 位置 | LOC | 触发条件 | 做了什么 | 性质 | 效果/备注 |
| --- | --- | ---: | --- | --- | --- | --- |
| helper inline + EXIT fallthrough（扣除 vendor-only kinsn） | `arch/arm64/net/bpf_jit_comp.c:1599-1665` | 42 | helper 为 `get_smp_processor_id` / `get_current_task[_btf]`，或最后一条是 `EXIT` | 直接内联 helper；若最后一条是 `EXIT` 则直接 fallthrough 到 epilogue | 纯优化 | ARM64 JIT 的优化深度明显低于 x86 |
| `BPF_END` lowering | `arch/arm64/net/bpf_jit_comp.c:1352-1391` | 35 | `BPF_END` | 用 `REV16/REV32/REV64` + `UXTH/UXTW` 实现 byteswap/zero-extend | 优化 | 有 standalone END lowering，但没有 `LDX + END` fusion |
| `BPF_ST_NOSPEC` lowering | `arch/arm64/net/bpf_jit_comp.c:1778-1786` | 8 | `BPF_ST|BPF_NOSPEC` | `SB` 或 `DSB NSH + ISB` | 安全 | 与 x86 的 `LFENCE` 对应 |
| subprog call shrink 额外 pass | `arch/arm64/net/bpf_jit_comp.c:2228-2233` | 2 | `extra_pass` 且子程序调用从间接变直接导致 image shrink | 再跑一轮以收敛地址 | 纯优化 | 类似 x86 的 shrink pass，但更小 |
| `bpf_jit_bypass_spec_v4()` | `arch/arm64/net/bpf_jit_comp.c:3183-3192` | 4 | ARM64 | 直接返回 true，表示依赖 firmware/SSBD 处理 Spectre v4，因此跳过 verifier 期 v4 `nospec` 插桩 | 安全策略 | 这是策略差异，不是 speed opt |
| `bpf_jit_inlines_helper_call()` | `arch/arm64/net/bpf_jit_comp.c:3199-3208` | 10 | helper 为 `get_smp_processor_id` / `get_current_task[_btf]` | 通知 verifier/JIT 允许 inline 这些 helper | 优化 gate | 自己不是 rewrite |

## 1.4 Post-JIT

从“真正的 post-JIT 优化器”角度看，内核几乎没有一个独立层。最接近的是 x86 的 tail-call direct fixup：

| 机制 | 位置 | LOC | 触发条件 | 做了什么 | 性质 | 效果/备注 |
| --- | --- | ---: | --- | --- | --- | --- |
| `bpf_tail_call_direct_fixup()` | `arch/x86/net/bpf_jit_comp.c:896-929`，调用点 `3917` | 30 | `poke_tab` 中已有 tail-call 直接目标，且目标稳定 | 对已生成机器码做 text poke，把 tail-call 补成 direct jump，并关闭 bypass path | 纯优化 | 更像 post-JIT patching，不是通用 post-pass optimizer |

结论：**Linux eBPF 几乎不存在一个通用 post-JIT optimization layer。**

## 2. LOC 总量统计

## 2.1 主口径总量

### 按阶段统计

| 类别 | LOC |
| --- | ---: |
| Verification-time 标记/硬化 | 147 |
| Post-verify fixup/rewrite | 1,286 |
| x86 JIT peephole | 185 |
| ARM64 JIT peephole | 101 |
| Post-JIT patching | 30 |
| **合计** | **1,749** |

### 按关键 pass/函数统计

| Pass / 机制 | LOC |
| --- | ---: |
| `sanitize_*` + ALU sanitation state | 111 |
| `nospec_result` stack mark | 10 |
| speculative `nospec` mark in main loop | 26 |
| `mark_fastcall_pattern_for_call()` + `mark_fastcall_patterns()` | 66 |
| `remove_fastcall_spills_fills()` | 27 |
| `inline_bpf_loop()` + `optimize_bpf_loop()` | 84 |
| `opt_hard_wire_dead_code_branches()` | 21 |
| `opt_remove_dead_code()` | 19 |
| `opt_remove_nops()` | 19 |
| `convert_ctx_accesses()` | 243 |
| `do_misc_fixups()` baseline（去掉 vendor-only kinsn） | 721 |
| `opt_subreg_zext_lo32_rnd_hi32()` | 71 |
| x86 peephole 小计 | 185 |
| ARM64 peephole 小计 | 101 |
| x86 post-JIT tail-call direct fixup | 30 |

## 2.2 和整体文件规模的关系

`cloc` 结果：

- `kernel/bpf/verifier.c`：19,184 LOC C
- `arch/x86/net/bpf_jit_comp.c`：2,793 LOC C
- `arch/arm64/net/bpf_jit_comp.c`：2,313 LOC C
- 三者合计：**24,290 LOC C**

因此：

- 本文主口径 counted optimization/hardening/specialization code：**1,749 LOC**
- 占这三大文件总 code 的 **7.2%**

这很能说明问题：内核里确实有 eBPF 优化，但规模并不大，而且被大量功能性 verifier/JIT 基础设施包围。

## 2.3 和 BpfReJIT daemon 的 LOC 对比

`daemon/src` Rust code 总量：**12,191 LOC**

7 个已实现 pass 文件：

| BpfReJIT pass | 文件 | LOC |
| --- | --- | ---: |
| `wide_mem` | `daemon/src/passes/wide_mem.rs` | 1,086 |
| `rotate` | `daemon/src/passes/rotate.rs` | 672 |
| `cond_select` | `daemon/src/passes/cond_select.rs` | 894 |
| `extract` | `daemon/src/passes/extract.rs` | 691 |
| `endian_fusion` | `daemon/src/passes/endian.rs` | 778 |
| `branch_flip` | `daemon/src/passes/branch_flip.rs` | 866 |
| `speculation_barrier` | `daemon/src/passes/spectre.rs` | 568 |
| **7 pass 合计** |  | **5,555** |

对比：

- 内核主口径 pass-like baseline：**1,749 LOC**
- BpfReJIT 7 个 pass 本身：**5,555 LOC**
- 比值：**3.18x**

如果按整个 daemon 算，则是 **12,191 / 1,749 = 6.97x**。

这不是在说 BpfReJIT “更轻量”；恰恰相反，它说明 BpfReJIT 把大量原本不适合进 kernel 的优化复杂度，移到了用户态可扩展框架里。

## 3. 效果分析：哪些有性能数据，哪些是安全/功能性

## 3.1 已知有公开性能数据的内核优化

1. `bpf_loop` inline
   - commit：`1ade23711971b0eececf0d7fedc29d3c1d2fce01`
   - 标题：`bpf: Inline calls to bpf_loop when callback is known`
   - 日期：2022-06-20
   - commit message 给出的数据：**14 ns/op -> 2 ns/op**
   - 这是目前最明确、最强的一条“内核 eBPF optimizer 确实能带来大幅提速”的公开证据。

2. map op direct-call / retpoline avoidance
   - 代表 commit：`09772d92cd5ad998b0d5f6f46cd1658f8cb698cf`
   - 标题：`bpf: avoid retpoline for lookup/update/delete calls on maps`
   - 日期：2018-06-03
   - commit 只明确说 retpoline 会造成 slowdown，没有给统一 benchmark 数字。

除此之外，大部分内核 pass 都没有公开的统一性能数字，只能给结构性效果估计。

## 3.2 主要是安全相关的逻辑

这些逻辑不该被吹成“性能优化”：

- `sanitize_ptr_alu()` + `ptr_alu_mask_patch`
  - 目标：Spectre v1
- `nospec_result` / `BPF_ST_NOSPEC`
  - 目标：Spectre v4
- unprivileged tail-call index masking
  - 目标：speculation OOB
- x86 `LFENCE` / ARM64 `SB`/`DSB+ISB`
  - 目标：真正的硬件 barrier lowering
- x86 indirect thunk / BHB barrier
  - 目标：间接分支历史相关投机攻击

### 3.2.1 `BPF_NOSPEC` 的完整链路

这条链路在 related work 里值得单独点明，因为它横跨 verifier、fixup、JIT 三层：

1. **策略入口**
   - `kernel/bpf/core.c:3094-3112`
   - generic 默认：`bpf_jit_bypass_spec_v1()` / `bpf_jit_bypass_spec_v4()` 都返回 `false`
   - `include/linux/bpf.h:2794-2805`
   - 若 `cpu_mitigations_off()` 或 token 具备 `CAP_PERFMON`，也可 bypass

2. **verifier 期标记**
   - `insn_aux->nospec`
   - `insn_aux->nospec_result`
   - `insn_aux->alu_state` / `alu_limit`

3. **fixup 期 materialize**
   - `convert_ctx_accesses()` 在指令前后插 `BPF_ST_NOSPEC`
   - `do_misc_fixups()` 插 pointer masking patch

4. **arch JIT lowering**
   - x86：`BPF_ST|BPF_NOSPEC -> LFENCE`
   - ARM64：`BPF_ST|BPF_NOSPEC -> SB` 或 `DSB+ISB`

5. **ARM64 特例**
   - `arch/arm64/net/bpf_jit_comp.c:3183-3192`
   - `bpf_jit_bypass_spec_v4()` 直接返回 `true`
   - 含义：ARM64 依赖 firmware/SSBD 处理 Spectre v4，因此 verifier 期 v4 插桩会被跳过

## 3.3 主要是功能性的逻辑

这些逻辑不做就会出错、trap，或者 JIT 不知道怎么生成：

- div/mod exception rewrite
- `LD_ABS` / `LD_IND` lowering
- `kfunc` call fixup
- `may_goto` lowering
- `needs_zext` / `opt_subreg_zext_lo32_rnd_hi32()`
- `PROBE_MEM` / `PROBE_ATOMIC` 转换
- 某些 helper 注参修正（`timer_set_callback`、percpu alloc ptr 等）

## 3.4 可以算纯优化的内核逻辑

纯优化子集其实不大：

- fastcall spill/fill removal
- `bpf_loop` inline
- `opt_hard_wire_dead_code_branches()` / `opt_remove_dead_code()` / `opt_remove_nops()`
- map op direct-call / `map_lookup_elem` inline
- `jiffies64` inline
- x86 percpu helper inline
- tracing helper inline
- `kptr_xchg` inline
- x86 short encoding / BMI2 shift / jump shrink
- ARM64 helper inline / EXIT fallthrough

## 4. 与 BpfReJIT 7 个 pass 的逐项对比

## 4.1 `wide_mem` vs 内核现有逻辑

- BpfReJIT：`wide_mem`
  - byte ladder：`LDX_B + LSH + OR` -> 宽 load
  - `docs/kernel-jit-optimization-plan.md` 给的数据：**占 kernel surplus 50.7%**
- 内核已有最接近的逻辑：
  - `convert_ctx_accesses()` 的“窄 ctx load widening”
  - 某些架构 JIT 对 `BPF_END` 的 lowering
- 关键差异：
  - 内核只会在 **ctx field rewrite** 这类极窄上下文里做 widening
  - 不会对通用 BPF bytecode 的 byte-recompose pattern 做识别和融合
- 结论：**基本互补，几乎无重叠**

## 4.2 `rotate` vs 内核现有逻辑

- BpfReJIT：识别 shift/or rotate pattern，改成 `bpf_rotate64()` kfunc，JIT inline 为原生 rotate
- 内核已有最接近的逻辑：
  - x86 只在 `BPF_END 16` lowering 里用 `ror`
  - 没有 generic rotate pattern matcher
- 结论：**互补**

## 4.3 `cond_select` vs 内核现有逻辑

- BpfReJIT：把 Jcc + move diamond 变成 `CMOV/CSEL`
- 内核已有最接近的逻辑：
  - x86 `insn_is_cast_user()` 特例里会生成一个 `cmove`
- 关键差异：
  - 内核没有 generic if-conversion pass
  - 只有非常局部、语义专用的 `cmove`
- 结论：**极小局部重叠，本质仍是互补**

## 4.4 `extract` vs 内核现有逻辑

- BpfReJIT：`RSH64_IMM + AND64_IMM(连续 mask)` -> `bpf_extract64()`
- 内核：
  - 没有 generic `BEXTR/UBFX` 识别
- 结论：**完全互补**

## 4.5 `endian_fusion` vs 内核现有逻辑

- BpfReJIT：`LDX_MEM + ENDIAN_TO_BE` -> `bpf_endian_loadXX()`；x86 下可到 `MOVBE`，ARM64 下可到 `LDR+REV`
- 内核：
  - x86/ARM64 都能把 standalone `BPF_END` 降好
  - 但不会把“load + byteswap”二者融合成一个新的语义节点
- 结论：**部分重叠，但 BpfReJIT 更强**
  - 重叠：都能优化 endianness
  - 差异：内核只会降单条 `BPF_END`，BpfReJIT 能跨指令融合

## 4.6 `branch_flip` vs 内核现有逻辑

- BpfReJIT：PGO 驱动的 if/else body 重排
- 内核已有：
  - x86 / ARM64 JIT 会 shrink jump
  - 没有 profile-guided branch layout
- 结论：**完全互补**

## 4.7 `speculation_barrier` vs 内核现有逻辑

- 内核已有：
  - verifier 标记 `nospec` / `nospec_result`
  - `sanitize_ptr_alu()` + `ptr_alu_mask_patch`
  - x86 `LFENCE`、ARM64 `SB/DSB+ISB`
- BpfReJIT：
  - `speculation_barrier` pass 在条件跳转后插 `bpf_speculation_barrier()` kfunc
  - 由 JIT inline 成真实 barrier
- 关系：
  - **有重叠**：两者都在处理 speculation barrier placement
  - **位置不同**：
    - 内核：verifier 驱动，围绕危险访问点打补丁
    - BpfReJIT：recompile 期 pass 驱动，围绕 branch site 增量插 barrier
- 结论：**部分重叠，但抽象层次不同**

## 4.8 BpfReJIT 的差异化到底在哪里

不是“内核完全没有优化”，而是：

1. **内核优化是固定白名单**
   - 都是硬编码在 verifier/JIT 里的小 rewrite
2. **内核缺少独立可扩展 pass framework**
   - 没有“新增一个 pass 而不动 verifier/JIT 核心”的自然位置
3. **内核不做 runtime/profile-informed specialization**
   - 没有 `branch_flip` 这种 PGO 逻辑
   - 没有 dynamic map inlining + deopt/re-REJIT
4. **内核不做 generic multi-insn peephole family**
   - 没有 `wide_mem` / `rotate` / `cond_select` / `extract`
5. **BpfReJIT 把 ISA-specific complexity 下沉到 kinsn module**
   - daemon 定义“找什么 pattern”
   - kinsn module 定义“如何发射平台特定指令”

## 5. 内核没做、但理论上可以做的优化

## 5.1 对比 LLVM/GCC 的典型 pass 列表

官方文档：

- LLVM Passes: <https://llvm.org/docs/Passes.html>
- GCC Tree-SSA passes: <https://gcc.gnu.org/onlinedocs/gccint/Tree-SSA-passes.html>
- GCC optimize options: <https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html>

可以直接拿来对照的 pass 家族：

| LLVM/GCC pass 家族 | 内核现在是否做 | 说明 | BpfReJIT 对应 |
| --- | --- | --- | --- |
| SCCP / CCP / IPSCCP | 否 | verifier 有 range/tnum，但内核不会把这些重新写回字节码做 constprop | `Verifier const prop` 已设计完成 |
| DCE | 只做 very-late unreachable removal | 内核只有 `opt_remove_dead_code()`，但不会在 specialization 后再做大范围 DCE | `DCE` 已设计完成 |
| GVN / CSE | 否 | 内核没有 SSA IR，也没有统一值编号层 | 两者都还没有 |
| LICM | 否 | eBPF loop 受限、验证复杂度高、收益难稳定 | 两者都还没有 |
| jump threading | 否 | 内核只 shrink jump，不改变逻辑结构 | 两者都还没有 |
| if-conversion | 只有极小特例 | x86 `cast_user` 里用 `cmove`，但没有 generic if-conversion | `cond_select` 已实现 |
| load combine / mem idiom recognition | 否 | 不会识别 byte ladder / bulk memory idiom | `wide_mem` 已实现；bulk memory 已设计 |
| endian load fusion | 否 | 只会降 standalone `BPF_END` | `endian_fusion` 已实现 |
| branch layout / block reordering | 否 | 没有 PGO 层 | `branch_flip` 已实现 |
| helper specialization / devirtualization | 极小静态白名单 | map ops、jiffies64、少数 helper inline | dynamic map inlining / helper specialization 已设计或调研完成 |
| pair load/store / vectorization | 否 | 内核 JIT 还没做 `LDP/STP` / SIMD 风格合并 | `128-bit LDP/STP`、bulk memory 已调研/设计 |

## 5.2 为什么内核不做

### 5.2.1 代码复杂度和安全审计成本

内核每多一个 eBPF optimizer，都要同时回答：

- verifier 是否还能证明安全
- rewrite 后是否还满足所有 prog type 约束
- JIT / interpreter / offload backends 是否都一致
- 边角 case 能否经得住 selftests 和长期维护

这和在用户态加一个 compiler pass 的代价完全不是一个数量级。

### 5.2.2 内核没有自然的中间表示和 deopt 机制

很多强优化都依赖：

- SSA/CFG 层统一分析
- profile 信息
- runtime invariant
- 失效后可 deopt / recompile

内核现有 verifier/JIT pipeline 里，几乎没有这些基础设施。静态 map op direct-call 已经很保守；dynamic map inlining 这种事情在内核里做，upstream 成本会非常高。

### 5.2.3 上游成本往往按“月”甚至“年”算

几个可验证的案例：

- `bpf_loop helper` 加入：2021-11-30
- `bpf_loop inline` 优化加入：2022-06-20
- 间隔：**202 天**

- fastcall 家族
  - `no_caller_saved_registers` helper 支持：2024-07-29
  - rename/support for kfuncs：2024-08-22
  - 进入 `bpf-next-6.12` merge tag：2024-09-21
  - 从首个 helper 支持到 merge：**54 天**

- map inline / retpoline avoidance 家族
  - inline map lookup 修正：2017-03-22
  - retpoline avoidance direct-call：2018-06-03
  - 间隔：**438 天**

这些不是精确“评审周期”统计，但已经足以说明：**给内核新增一个 BPF 优化，不是几天一个 patch 的节奏。**

## 5.3 BpfReJIT 如何填空

### 已实现

- `wide_mem`
- `rotate`
- `cond_select`
- `extract`
- `endian_fusion`
- `branch_flip`
- `speculation_barrier`

### 已设计完成 / 已调研完成

来自 `docs/kernel-jit-optimization-plan.md`：

- dynamic map inlining
- verifier const propagation
- DCE
- 128-bit ARM64 `LDP/STP`
- bulk memory kinsn
- helper specialization

### 关键方法论差异

1. 新优化优先写在 daemon 里，不碰内核 verifier/JIT 核心
2. 若需要新指令语义，只加一个 kinsn module
3. 利用 `BPF_PROG_GET_ORIGINAL` / `BPF_PROG_REJIT` 在 live program 上重写并 re-verify
4. profile/runtime 信息可以在 userspace 收集并驱动 pass

## 6. 关键数字

## 6.1 内核 BPF 优化总 LOC vs BpfReJIT

- Linux 内核现有 pass-like 优化/硬化/特化代码：**1,749 LOC**
- 当前 vendor tree 中额外混入的 BpfReJIT vendor-only kinsn 代码：**30 LOC**
- BpfReJIT 7 个已实现 daemon pass：**5,555 LOC Rust**
- BpfReJIT daemon 整体：**12,191 LOC Rust**

## 6.2 BpfReJIT 的内部定量证据

来自 `docs/kernel-jit-optimization-plan.md`：

- `wide_mem`：占 kernel surplus **50.7%**
- `cmov` 差距：**llvmbpf 31 vs kernel 0**
- pass ablation：**仅 `InstCombinePass + SimplifyCFGPass` 有效**
  - 这反过来证明“通用 LLVM middle-end 并不能自动覆盖内核/JIT 的缺口”
- `rotate64_hash`：真实加速 **20.4%**
- 2026-03-23 VM 验证：
  - `vm-micro`: 53/62 applied, 0 mismatch
  - `vm-corpus`: 56 applied, 0 error, 0 mismatch

## 6.3 新增一个优化的工程成本

### 内核

一般需要同时改：

- verifier 分析或 `insn_aux_data`
- verifier fixup/rewrite
- 至少一个架构 JIT
- selftests / prog type 回归
- upstream 评审

### BpfReJIT

通常只需要：

- 一个新的 daemon pass
- 若需要平台新语义，再加一个可选 kinsn module

`docs/kernel-jit-optimization-plan.md` 里的 `SIMD kinsn module` 调研结论已经明确指出：**新 module + daemon pass 即可，不必再改框架主干。**

## 7. 最终大表

| 优化类别 | 内核已有 | BpfReJIT 已有 | BpfReJIT 设计完成 | 两者都没有 |
| --- | --- | --- | --- | --- |
| 不可达分支硬连线 / DCE / NOP 清理 | `opt_hard_wire_dead_code_branches()` / `opt_remove_dead_code()` / `opt_remove_nops()` | 否 | `verifier constprop + DCE` 已设计 | 否 |
| fastcall spill/fill 删除 | 是 | 否 | 否 | 否 |
| `bpf_loop` helper inline | 是 | 否 | 否 | 否 |
| ctx access specialization / 窄 ctx load widening | `convert_ctx_accesses()` | 否 | 否 | 否 |
| helper/map 静态内联与 direct-call | `do_misc_fixups()` 中已有白名单 | 部分有：特定 kfunc/kinsn lowering | dynamic map inlining、helper specialization 已设计/调研 | 否 |
| subreg zext / backend legalization | 是 | 依赖内核完成 | 否 | 否 |
| Spectre v1/v4 硬化、ptr masking、`BPF_NOSPEC` | 是 | `speculation_barrier` 已实现 | 更激进的 barrier placement / elimination 可继续扩展 | 否 |
| byte ladder -> wide load | 否 | `wide_mem` | 否 | 否 |
| rotate pattern -> 原生 rotate | 否 | `rotate` | 否 | 否 |
| Jcc + move diamond -> `CMOV/CSEL` | 只有 `cast_user` 特例 | `cond_select` | 否 | 否 |
| `RSH + AND` -> `BEXTR/UBFX` | 否 | `extract` | 否 | 否 |
| `LDX + END` 融合成 endian load | 只有 standalone `BPF_END` lowering | `endian_fusion` | 否 | 否 |
| PGO branch layout / if-else block reorder | 否 | `branch_flip` | 否 | 否 |
| runtime constprop / specialization-driven DCE | 否 | 否 | 已设计完成 | 否 |
| dynamic map inlining + deopt/re-REJIT | 否 | 否 | 已设计完成 | 否 |
| 128-bit pair load/store (`LDP/STP`) | 否 | 否 | ARM64 方向调研完成 | x86 通用方案仍缺 |
| bulk memory idiom (`memcpy/memset`) 专门优化 | 否 | 否 | bulk memory kinsn 已设计 | 否 |
| generic GVN / CSE / LICM / jump-threading / loop unswitch | 否 | 否 | 还没有完整设计 | **是** |

## 8. 结论

### 8.1 对 related work 的准确表述

最准确的写法不是“Linux 内核没有 eBPF 优化”，而是：

- Linux 内核已经有一小套 verifier/fixup/JIT 层面的硬编码优化与安全硬化；
- 其中最强的公开性能证据是 `bpf_loop` inline；
- 但它们多数是 program-type-specific rewrite、helper inline、Spectre 防护和浅层 JIT peephole；
- Linux 目前没有一个可扩展的、可插拔的、可结合 runtime/profile 信息的 eBPF pass framework；
- BpfReJIT 的贡献正是在这个空白上：把优化复杂度移出内核主线，用 daemon + 可选 kinsn module 迭代出更丰富的 pass family。

### 8.2 对 motivation 的准确表述

从这份盘点可以直接支持论文 motivation：

1. 内核现有优化代码量不大，且高度分散在 verifier/fixup/JIT 中。
2. 新增优化要碰 verifier/JIT/upstream 评审，工程阻力很高。
3. 内核的 pass 范围主要停留在 dead-code cleanup、helper inline、endianness lowering、Spectre hardening 这类固定逻辑。
4. BpfReJIT 已经证明：`wide_mem`、`rotate`、`cond_select`、`extract`、`endian_fusion`、`branch_flip` 这些 pass 可以在用户态独立演化，并通过 re-REJIT 应用于 live program。

## 9. 参考链接

### 内核提交

- `bpf_loop helper`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=e6f2dd0f80674e9d5960337b3e9c2a242441b326>
- `bpf_loop inline`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=1ade23711971b0eececf0d7fedc29d3c1d2fce01>
- `no_caller_saved_registers attribute for helper calls`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=5b5f51bff1b66cedb62b5ba74a1878341204e057>
- `bpf_fastcall` rename：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=ae010757a55b57c8b82628e8ea9b7da2269131d9>
- `support bpf_fastcall patterns for kfuncs`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=b2ee6d27e9c6be0409e96591dcee62032a8e0156>
- `inline map lookup` 修正：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=fad73a1a35ea61f13607a391aca669caad8c04ca>
- `avoid retpoline for lookup/update/delete calls on maps`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=09772d92cd5ad998b0d5f6f46cd1658f8cb698cf>
- `avoid retpoline for map push/pop/peek operation`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=84430d4232c36cb858564374f839d233fd6f623a>
- `Avoid retpoline for bpf_for_each_map_elem`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=0640c77c46cb84328d5e08aa85a781a60be8b02b>
- `Add BPF_FUNC_jiffies64`：<https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=5576b991e9c1a11d2cc21c4b94fc75ec27603896>

### 编译器 pass 文档

- LLVM Passes：<https://llvm.org/docs/Passes.html>
- GCC Tree-SSA passes：<https://gcc.gnu.org/onlinedocs/gccint/Tree-SSA-passes.html>
- GCC Optimize Options：<https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html>

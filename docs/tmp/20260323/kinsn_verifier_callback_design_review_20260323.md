# kinsn verifier callback 设计审查

日期：2026-03-23

结论先行：你们提出的方向有价值，但按当前描述还不完整，也还不足以上游可接受。核心问题不是 `clobber_mask` 和 `narrow_result` 两个字段本身，而是它们把 `KF_INLINE_EMIT` 从“JIT 内联提示”升级成了“模块参与 verifier 语义定义”。一旦这么做，现有 verifier/JIT/kfunc 解析路径里很多默认前提都会失效。

最重要的结论有 8 条：

1. `clobber_mask` 声明错误会直接破坏 verifier soundness。最坏后果不是“结果算错”，而是 verifier 继续相信某个活跃寄存器仍然保持原来的 pointer/ref/range 状态，实际 native code 却已经改掉它。
2. 从系统安全边界看，这不比“module emit callback 可发射任意 native code”更高权限；但从 verifier 维护和上游审查角度看，风险是更高的，因为 verifier 的可信语义开始依赖模块元数据是否正确。
3. 现有树里已经有一个反例说明“只 clobber r0”不成立：x86 `bpf_rotate64` 会写 `RCX`，而 `RCX` 在 x86 JIT 中对应 `BPF_REG_4`，不是自由 scratch。
4. `narrow_result(dst, insn)` 只看 `insn->off` 不够。对 `select` 这类结果依赖输入寄存器状态的 kinsn，还需要读源寄存器状态；对 memory kinsn，还需要 base reg/offset/access size 语义。
5. 如果采用 operand encoding，当前 verifier 会在进入 `check_kfunc_call()` 之前就拒绝，因为它要求 `BPF_CALL` 的 `dst_reg == 0`，而且现有 kfunc 基础设施把 `off` 当成 `btf_fd_idx` 使用。
6. memory kinsn 不能只靠 `narrow_result`。像 `endian_load` 这种必须复用 core verifier 的 `check_mem_access()` 族逻辑，否则就是把“真实内存访问”藏进了 opaque kfunc。
7. 把 `struct bpf_reg_state *` 暴露给模块做可写回调，上游大概率不会接受。社区能接受的是 declarative metadata，或至多是受限的、只读的 verifier hook，不是把 verifier 内部状态机开放给模块改写。
8. 如果 verifier 语义不再等同于普通 kfunc CALL，那么 JIT 就不能再“emit 失败就 fallback 到真实 CALL”。否则 verifier 认为寄存器被保留，真实 CALL 却按 ABI clobber 它们，语义立即失配。

---

## 1. 现状基线

先固定当前代码中的事实，这些事实决定了 proposed design 的边界。

| 事实 | 代码位置 | 影响 |
|------|---------|------|
| verifier 在主解释循环里要求 `BPF_CALL` 的 `dst_reg == BPF_REG_0`，且 kfunc call 的 `src_reg == BPF_PSEUDO_KFUNC_CALL`，`off` 仍按现有语义检查 | `vendor/linux-framework/kernel/bpf/verifier.c` L21210-L21220 | 直接把 `dst_reg` 拿来编码 operand，会在进入 `check_kfunc_call()` 前被拒绝 |
| `check_kfunc_call()` 当前无条件 `mark_reg_not_init()` 掉 `r0-r5` | `vendor/linux-framework/kernel/bpf/verifier.c` L14432-L14437 | 这是你们想修改的核心点 |
| helper 的返回值 refine 不是简单设 min/max，而是同时维护 64/32-bit bounds，再 `reg_bounds_sync()` | `vendor/linux-framework/kernel/bpf/verifier.c` L11418-L11454 | `narrow_result` 若要可靠，至少要遵守同样的不变量 |
| `bpf_kfunc_inline_ops` 现在只有 `emit_x86`/`emit_arm64`/`max_emit_bytes` | `vendor/linux-framework/include/linux/bpf.h` L968-L977 | 目前 inline ops 完全不参与 verifier |
| x86 JIT 的 inline 路径是“找到 `inline_ops` 就调用 emit；否则返回错误并回退到普通 CALL” | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` L579-L599, L2464-L2470 | 一旦 verifier 对 inline kfunc 采用非 CALL 语义，这个 fallback 就不再安全 |
| kfunc 解析和 JIT lookup 都把 `insn->off` 当成 kfunc descriptor key 的一部分 | `vendor/linux-framework/kernel/bpf/verifier.c` L3313-L3336, L3522-L3616, L3693-L3710, L23311-L23323 | `off` 不是“空闲字段”，直接复用会破坏 kfunc 查找 |
| `find_kfunc_desc_btf(offset)` 中 `offset == 0` 明确表示 `btf_vmlinux`，非零才从 `fd_array` 取 module BTF fd | `vendor/linux-framework/kernel/bpf/verifier.c` L3415-L3429, L3349-L3400 | “注册到 `BPF_PROG_TYPE_UNSPEC` 所以 `btf_fd_idx=0`” 这个前提不成立 |
| 当前 x86 JIT 中 `BPF_REG_4 -> RCX`，`BPF_REG_5 -> R8` | `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` L181-L196 | 判断 native reg clobber 是否对应 BPF reg 时，必须按这张表来 |
| 当前 x86 `bpf_rotate64` emit 会执行 `mov rcx, rsi` | `module/x86/bpf_rotate.c` L47-L54 | 这会 clobber `BPF_REG_4`，因此“现有 emit 只写 r0”是错误结论 |

补充两点：

- `module/x86/bpf_extract.c`、`module/x86/bpf_select.c`、`module/x86/bpf_endian.c`、`module/x86/bpf_barrier.c` 当前 x86 实现里，除 `rotate` 外，肉眼检查都只写 `RAX` 或不写任何 BPF 映射寄存器。
- `module/arm64/bpf_rotate.c` 用的是 `X10` scratch，不对应任何 BPF visible reg；因此 x86 和 arm64 的真实 clobber 集已经不同。

---

## 2. 安全性分析

### 2.1 如果 module 的 `clobber_mask` 声明错误，后果是什么？

结论：如果 `clobber_mask` 少报，后果是 verifier soundness 直接被破坏；如果多报，只是保守，性能/覆盖率变差。

理由：

- verifier 当前在 call 后把 `r0-r5` 全部打成未初始化，是为了保证后续任何对这些寄存器的读取都必须重新建立状态。
- 如果你们改成“只 clobber `clobber_mask` 指定的寄存器”，那么 verifier 会继续保留未被 mask 命中的寄存器状态。
- 一旦 emit 实际改写了一个未申报寄存器，例如“mask 说不碰 `r3`，但 native code 改了 `RDX`”，后续 verifier 仍会把 `r3` 当作旧的 `PTR_TO_CTX`、`PTR_TO_MAP_VALUE`、`ref_obj_id`、或带有某个 `tnum/range` 的 scalar 来使用。
- 这类错误会把“JIT 编译时 bug”提升成“verifier 模型和真实执行状态分叉”。后续任意内存访问、ref tracking、NULL check、range check 都可能建立在错误前提上。

一个具体例子：

- 假设 `r4` 在 verifier 看来是一个已验证过边界的 packet/map/value 指针。
- x86 `bpf_rotate64` 当前 emit 实际会改 `RCX`，而 `RCX` 正好是 `BPF_REG_4`。
- 如果 `clobber_mask` 错把它声明成“只写 r0”，后续程序再用 `r4` 访问内存时，verifier 仍按旧 pointer state 放行，但 CPU 上 `r4` 对应的物理寄存器已经不再是原来的指针。

这不是普通功能 bug，而是 verifier 失真。

修复建议：

- `clobber_mask` 只能由 kernel core 最终消费，但不能盲目信任模块给出的 under-approximation。
- 如果保留这个接口，最少也要要求“宁可 over-approximate，绝不能 under-approximate”，并为每个 kinsn 加寄存器保留自测。
- 更好的做法是让 core verifier/JIT 从更 declarative 的 operand/scratch 描述推导 clobber，而不是直接相信模块给的最终 mask。

### 2.2 这比现有 module 信任模型风险更高，还是相同？

结论：从权限边界看是“相同级别”；从 verifier 可信性和上游审查角度看是“更高风险”。

理由：

- 相同点：今天的 `emit_x86()` 已经是内核态代码，能发射任意 native code。一个恶意或严重 buggy 的 module 已经可以做比“偷偷改寄存器”更糟的事，例如直接发错误内存访问、破坏调用约定、写任意地址。
- 更高风险点：现有模型下，module 的错误主要表现为“生成了坏代码”。proposed model 下，module 还能影响 verifier 的抽象语义。这会让 verifier soundness 依赖模块声明是否正确，属于新的“静默失真通道”。
- 社区通常对“trusted kernel code 可能写错 native code”比较能接受，因为那仍是 JIT bug；但对“verifier 的抽象解释依赖外部模块元数据/回调”会更敏感，因为 verifier 被视为 BPF 安全边界的一部分。

所以，严格说：

- 安全边界没有提升到一个新权限层级。
- 但 verifier TCB 被扩展到了每个注册 `KF_INLINE_EMIT` 的模块，上游会更警惕。

### 2.3 能不能在 JIT 侧验证 `clobber_mask` 的正确性？

结论：对当前这种“module 直接发 arbitrary native bytes”的 API，无法做通用、可靠、低成本的验证。最多做 debug/selftest 级别的近似检查。

理由：

- `emit_x86()`/`emit_arm64()` 是任意 C 代码，不是 declarative template。
- emitted sequence 可能依赖 `insn`、依赖 `prog`、依赖寄存器分配，还可能因目标寄存器不同而选择不同 scratch。
- 真正要验证“clobber 了哪些 BPF visible regs”，需要：
  - 完整指令解码；
  - 架构寄存器写集合分析；
  - BPF reg 到 native reg 的映射；
  - 对条件分支、异常路径、隐式写寄存器、call/fixup 的处理。
- 这本质上接近一个精简版 objtool/arch analyzer。对当前 out-of-tree callback API 来说，投入过高，而且仍很难覆盖所有路径。

可行但不完美的替代：

- debug-only 自测：为每个 kinsn 构造“所有 caller-saved BPF regs 都 live”的测试程序，JIT 后执行并核对未声明 clobber 的寄存器是否保持。
- build-time/disasm test：对固定 byte sequence 的 in-tree kinsn 做反汇编白名单比对。
- 真正可验证的方案：把 emit callback 改成 declarative template 或受限 IR，让 kernel 从模板里推导 scratch/read/write，而不是从 bytes 事后猜。

---

## 3. 完整性检查

### 3.1 `narrow_result` 只拿到 `insn->off` 够不够？

结论：不够。

理由：

- 对 `extract` 这类“结果只依赖编码在 `off` 里的常量宽度”的场景，`off` 足够做基本 range narrowing。
- 对 `select` 这类“结果是若干输入寄存器状态的并集”的场景，`off` 只能告诉你 operand 编号，不能告诉你这些 source reg 当前的 `tnum/min/max`。
- 对 memory kinsn，`off` 只能告诉你一部分位置信息，不能表达 base reg 当前是什么类型、可访问范围多大、是否是 packet/stack/map value/ctx pointer。
- 对 staged rollout 来说，如果还要兼容旧 ABI 的 r1-rN 传参模式，`insn->off` 在旧编码里根本是 `btf_fd_idx`，不含操作数。

至少还需要的信息：

- 已解码的 operand 描述。
- 源寄存器编号。
- 源寄存器当前 `bpf_reg_state`。
- 结果宽度/是否 zero-extend/sign-extend。
- 对 memory op，base reg、access size、signedness、faulting model。

建议：

- 不要让 `narrow_result` 直接解析 `insn` 原始比特并顺便推导所有语义。
- 更合理的是 kernel core 先 decode 成一个小的、稳定的“inline operand descriptor”，再把 descriptor 和当前 `regs` 的只读视图传给 refine 逻辑。

### 3.2 是否还需要 `verify_operands` 回调？

结论：需要，或者至少需要等价的 kernel-owned operand validation 层。

理由：

- `narrow_result` 只负责输出状态，不负责输入合法性。
- 一旦不再走现有 `check_kfunc_args()` 的 `r1-rN` 检查，就必须有替代路径来验证：
  - 编码出来的寄存器号是否合法；
  - 是否错误使用了 `r10`/无效 reg 编号；
  - dst/src 是否必须是 scalar；
  - 某些 immediate 是否必须落在合法范围；
  - 某些 operand 是否允许 alias；
  - memory operand 的 offset/size 是否在 verifier 允许范围内。

我的判断是：

- 只靠 `clobber_mask + narrow_result` 不完整。
- 最少需要 `verify_operands`。
- 更好的形式不是模块随意写 verifier 逻辑，而是 core 提供受限验证框架，模块只给 declarative operand schema 或 very small policy callback。

### 3.3 是否需要 `input_regs` 回调？

结论：需要一个“哪些寄存器被读取”的声明；是否叫 `input_regs` 不重要，但这个信息本身是必须的。

理由：

- verifier 必须知道哪些寄存器是输入，才能检查它们已经初始化、类型正确、必要时参与 precision tracking。
- 对 `select`，你至少要知道 cond/true/false 三个输入。
- 对 memory kinsn，要知道 base reg 是输入。
- 仅靠 `clobber_mask` 无法推导 read set。

推荐形式：

- 最简单：返回一个 `read_mask`。
- 更完整：返回按 operand role 标注的解码结果，例如 `dst`、`src[0..N]`、`base`、`imm`。

如果没有这个层，后面所有 source-dependent refine 都会变成“模块自己碰 verifier internals”，这条路上游基本不会买单。

### 3.4 多操作数 kinsn（如 `select`）里，`off` 16 位够不够？

结论：对“3 个寄存器 + 小枚举条件码”这种特例，勉强够；对通用方案，不够。

理由：

- 4-bit 一个寄存器编号，3 个寄存器是 12 bit，剩 4 bit 可塞条件码。这对 `select` 可以工作。
- 但一旦出现以下任一需求，就不够：
  - 需要同时编码 dst 之外的更多寄存器；
  - 需要 full `s16` memory offset 之外再带 base reg；
  - 需要 immediate operand；
  - 需要 signedness、宽度、模式位；
  - 需要兼容 module BTF fd index。

更严重的是，当前 kernel 里 `off` 本身不是空闲字段：

- verifier fetch kfunc meta 用它定位 BTF；
- fixup/JIT lookup 也把它作为 kfunc descriptor key。

所以问题不是“16 位够不够”，而是“你们现在没有自由使用这 16 位”。

### 3.5 对内存型 kinsn（如 `endian_load`），verifier 需不需要额外验证内存访问？

结论：需要，而且这是 current proposal 里最大的缺项之一。

理由：

- `endian_load` 的真实语义不是“opaque scalar function”，而是“读取 `[base + off]` 上的内存，再做 endian transform”。
- 这必须复用 core verifier 现有的 memory access 规则，否则你就把一个真正的内存读藏进了 module emit/native code 里。
- 当前仓库里的 `bpf_endian_loadXX` fallback 签名写成 `u64 addr`，而不是 `const void *addr`。这说明按现有 `check_kfunc_args()`，它只会被当成 scalar 参数检查，而不会触发 pointer-based memory validation。
- daemon 当前 `endian` pass 也是“把 src_reg 搬到 `r1`，必要时加 offset，再 call kfunc”；如果 `src_reg` 是 pointer reg，这和 BTF scalar 参数模型本身就不一致。

需要额外验证的内容至少包括：

- base reg 的 pointer type。
- access size。
- access offset。
- alignment。
- packet/map/stack/ctx 的各自访问规则。
- 是否会 fault，若会 fault，fault model 是否类似 `BPF_PROBE_MEM`。

修复建议：

- memory kinsn 不能只走“kfunc scalar return refine”路径。
- 应该新增“memory operand descriptor”，由 core verifier 调用现有 `check_mem_access()`/`check_packet_access()` 逻辑。
- 如果不想做这层，建议第一版明确禁止 memory kinsn，只支持 pure scalar kinsn 和 barrier。

---

## 4. 上游可接受性

### 4.1 社区会担心什么？

结论：会担心，而且担心点很明确。

主要顾虑：

- verifier 不再是 core kernel 的单点语义来源，模块也能参与定义寄存器状态转移。
- `struct bpf_reg_state` 是 verifier 私有内部结构；一旦暴露给模块，接口稳定性和内部不变量都变差。
- JIT 语义和 verifier 语义可能因 module 版本、架构差异、fallback 路径而失配。
- kfunc 原本依赖 BTF prototype + flags 这种 declarative 模型；module verifier callback 会把它推向 ad-hoc imperative 模型。

如果想提高可接受性，我建议把目标收窄到：

- 只允许 pure scalar/no-ref/no-sleep/no-callback/no-exception/no-memory-write 的 inline kinsn。
- module 只提供 declarative metadata。
- verifier 的真正状态更新逻辑仍在 core 内核。

### 4.2 有没有类似先例？

结论：有“部分先例”，但没有“等价先例”。

可以引用的先例：

- module/subsystem 通过 BTF kfunc id set 和 `KF_*` flags 影响 verifier 行为，这是现有机制。
- `struct bpf_verifier_ops` 里的 `btf_struct_access()` 已经让特定子系统的 verifier callback 能看到 `const struct bpf_reg_state *`。
- `bpf_prog_offload_ops` 允许 device/offload 驱动通过 `insn_hook`/`replace_insn`/`remove_insns` 参与 verifier/offload 流程。

但这些先例与 proposed design 的关键差别是：

- 它们多数是 core/subsystem-owned callback，不是对任意 `KF_INLINE_EMIT` module 开放。
- `btf_struct_access()` 是只读观察，不是让模块写 `bpf_reg_state`。
- 现有 kfunc flags 是 declarative metadata，不是 per-kfunc imperative verifier callback。

所以可以说“方向上不是完全没有先例”，但不能说“社区已经接受过等价机制”。

### 4.3 把 `bpf_reg_state` 暴露给 module，安全吗？

结论：不安全，也不利于上游。

理由：

- `bpf_reg_state` 定义在 `bpf_verifier.h`，里面有大量 verifier 内部字段和不变量：`var_off`、64/32-bit bounds、`id`、`ref_obj_id`、`subreg_def`、`precise` 等。
- 只要允许模块直接写它们，core verifier 就必须假设外部代码能维持所有不变量。这很难审查，也很难稳定。
- 现有 helper refine 逻辑是 core verifier 自己更新这些字段，然后立刻 `reg_bounds_sync()` 和 `reg_bounds_sanity_check()`；模块不应该直接介入这一层。

更可接受的替代：

- 向模块暴露一个更小的、专门给 inline kinsn 用的 result descriptor。
- 例如只允许表达：
  - scalar 或 void；
  - 可选 `tnum`；
  - 可选 64/32-bit bounds；
  - 结果宽度和 zext/sext 属性。
- 真正的 `bpf_reg_state` 更新由 core verifier 完成。

### 4.4 与 `bpf_fastcall` 的关系怎么处理？

结论：`KF_FASTCALL` 不是这个问题的解法；最好把两者视为正交机制，且不要组合。

理由：

- 当前 `KF_FASTCALL` 主要用于 clang spill/fill pattern 的识别和删除，verifier 的主 call 语义仍是 CALL 语义。
- 你们要做的是“inline kfunc 不再遵循普通 CALL 的寄存器语义”，这比 fastcall 更激进。
- 如果 verifier 已按 inline ALU-like 语义处理，那么 JIT emit 失败时不能依赖 fastcall fallback，因为 fastcall 仍然是假设“本质上是 call，只是 clobber 少一些”。

建议：

- `KF_INLINE_EMIT` 和 `KF_FASTCALL` 不要组合。
- 若 `KF_INLINE_EMIT` 被 verifier 识别为非 CALL 语义，则必须保证：
  - inline emit 成功；或
  - native fallback 显式保存/恢复 verifier 认为 preserved 的寄存器。

---

## 5. operand encoding 对 verifier 的影响

### 5.1 如果用 `dst_reg` 编码操作数寄存器，`check_kfunc_args()` 怎么适配？

结论：现有 `check_kfunc_args()` 不能直接适配，必须重构。

原因有两层：

- 更早的前置检查已经要求 `BPF_CALL.dst_reg == 0`，所以光改 `check_kfunc_args()` 不够，首先要改主 verifier 的保留字段检查。
- `check_kfunc_args()` 当前硬编码读取 `r1-rN`。它不是从“抽象 operand 列表”取参数，而是直接拿 `cur_regs(env)[i + 1]`。

要想复用现有 kfunc 验证能力，合理的方向不是“模块自己重新验证一遍”，而是：

- 把 `check_kfunc_args()` 重构成“接受一个已解码 operand vector”。
- 每个 operand 可以是：
  - `reg N`；
  - `const imm`；
  - `memory(base, off, size)`；
  - `implicit`。

这样 BTF prototype 仍可作为 source of truth，core verifier 仍能复用现有 scalar/pointer/ref/dynptr/RCU 规则。

### 5.2 当前 `check_kfunc_args()` 只验证 `r1-rN` 类型。需要替代的参数验证吗？

结论：需要，而且必须是完整替代，不是简单补丁。

至少要覆盖：

- 输入寄存器已初始化。
- 输入寄存器类型匹配。
- 常量 operand 合法。
- BTF arg 约束仍成立。
- 对 memory operand 进行真正的访问验证。
- 对不支持的 kfunc flag 组合直接拒绝。

建议：

- 对 `KF_INLINE_EMIT` 单独走一个 `check_inline_kfunc_operands()`。
- 但这个函数应尽量复用 core verifier 现有的 arg/type/memory 子逻辑，而不是让 module callback 自己碰 `env` 和 `regs`。

### 5.3 直接复用 `dst_reg/off` 还有哪些 verifier 级别冲突？

结论：冲突很多，不止 `check_kfunc_args()`。

受影响的现有路径至少包括：

- 主 verifier 的保留字段检查，要求 `dst_reg == 0`。
- `add_kfunc_call()` / `find_kfunc_desc()` / `fixup_kfunc_call()` 以 `(imm, off)` 查找 kfunc descriptor。
- `fetch_kfunc_arg_meta(env, imm, off, ...)` 里 `off` 仍被解释成 module BTF fd index。
- `visit_insn()` 和一些 callback/special-kfunc 辅助逻辑也会拿 `off` 去做 kfunc meta fetch。

这意味着：

- operand encoding 不是 `check_kfunc_call()` 里加一个分支就能完成。
- 它会触到 verifier 预处理、descriptor 缓存、fixup、JIT lookup 的共同基础设施。

---

## 6. 还缺什么

### 6.1 `tnum` 追踪需要吗？`narrow_result` 只设 min/max 够不够？

结论：如果只追求保守 soundness，min/max 可以“勉强够”；如果要设计完整、尽量不回归 verifier 通过率，必须支持 `tnum`。

理由：

- verifier 的 scalar state 不只看 `umin/umax`，还看 `var_off` (`tnum`) 和 32-bit 子范围。
- `reg_bounds_sync()` 会尝试在 bounds 和 `tnum` 之间互相收紧，但如果你把 `var_off` 留成 `tnum_unknown`，很多位级信息永远回不来。
- 对 `extract`/`endian_load` 这种结果是 `[0, 2^n-1]` 的连续区间，min/max 再 `sync` 后通常能恢复相当一部分 `tnum`，所以问题较小。
- 对 `select` 这种“结果是两个值/两个范围的并集”的场景，只设 min/max 会明显丢精度。比如真实结果是 `{0, 8}`，min/max 只能表达 `[0, 8]`。

因此建议：

- result descriptor 至少允许表达可选 `tnum`。
- core verifier 在应用 descriptor 后统一做 `reg_bounds_sync()` 和 sanity check。

### 6.2 还缺 32-bit subregister 追踪吗？

结论：缺，而且不能忽略。

理由：

- 当前 helper/kfunc 返回值路径会用 `mark_btf_func_reg_size()` 设置 `subreg_def`，这是 32-bit zero-extension 跟踪的一部分。
- 你们如果改成“inline kinsn 写 `dst_reg` 而不是 `r0`”，就不能再只处理 `BPF_REG_0` 的 `subreg_def`。
- 例如某个 inline kinsn 语义上只定义 32-bit 结果并零扩展到 64-bit，那么 verifier 应该给 `dst_reg` 正确的 subreg/zext 元数据；否则后续精度和 JIT zext 优化都会失真。

修复建议：

- 把当前“基于 BTF return size 设置 `r0.subreg_def`”的逻辑，推广成“基于 inline result width 设置 `dst.subreg_def`”。
- 这部分最好由 core verifier 做，不要让 module 直接写 `subreg_def`。

### 6.3 subprog 场景怎么处理？

结论：原则上可以支持，但如果引入新编码或 2-slot 指令，需要同步修改 subprog/CFG/指令遍历逻辑。

理由：

- 现有 kfunc call 在 subprog 里本来就允许，`check_kfunc_call()` 不区分主程序还是 callee frame。
- 但如果你们引入新的 instruction form，像文档里提到的 2-slot encoding，现有 verifier 并不会自动把它当成“像 `LDIMM64` 那样的双宽指令”。
- `visit_insn()` 目前只对 `LDIMM64` 特判 2-slot，其余非 branch 指令都按 1-slot 前进。

结论化一点说：

- 纯 1-slot inline kinsn：subprog 不会是主问题。
- 任何 2-slot 方案：必须把 CFG walker、branch target、insn iteration、JIT iteration 一起改掉。

### 6.4 还缺哪些边界条件？

我认为还缺 8 个关键边界条件：

1. `emit` fallback 语义。
   现在 x86 JIT 的 inline path 会在 `ops == NULL` 或 emit 返回负值时回退到真实 CALL。新 verifier 语义下这会立刻失配。

2. 旧/新编码区分不充分。
   文档里用“`dst_reg != 0` 表示新编码”区分 old/new call，但 `bpf_speculation_barrier()` 这种无操作数 kinsn 在旧编码和新编码下完全同形。

3. `off` 的 module-BTF 语义没有替代方案。
   只要 kfunc 定义在 module BTF 中，你们就还需要某种 `btf_fd_idx` 或等价机制。

4. 版本兼容问题。
   一旦 verifier 行为依赖 `inline_ops` 新字段，`bpf_kfunc_inline_ops` 需要 `struct_size` 或 version/flags；否则新内核对旧模块、旧 daemon 对新模块都会有歧义。

5. source-dependent refine 的 precision backtracking。
   如果某个 result refinement 依赖 source reg 的精确 `tnum`，还需要一条“结果精度依赖哪些输入”的通道，否则后续 `mark_precise` 类逻辑无法回溯。

6. memory faulting model。
   若某 memory kinsn 可能 fault，它不是普通 `LDX` 语义，也不是普通 kfunc 语义，需要明确是 raw access 还是 probe-style access。

7. 架构差异。
   x86 和 arm64 同名 kinsn 的真实 scratch set 已经不同；如果未来一个 registration 同时提供 `emit_x86` 和 `emit_arm64`，单一 `clobber_mask`/result contract 不一定够。

8. operand-dependent clobber。
   一旦进入 operand encoding，某些 emit 序列是否需要额外 scratch，可能取决于 `dst_reg` 映射到哪个 native reg。此时“每个 kfunc 一个静态 `clobber_mask`”未必足以表达真实 clobber 集。

---

## 7. 对你们当前方案的逐项结论

### 7.1 仅扩展 `bpf_kfunc_inline_ops`，增加 `clobber_mask + narrow_result`，是否完整？

结论：不完整。

缺的最少组件是：

- 输入 operand 验证。
- 输入 read set 声明。
- memory operand 验证。
- `tnum`/32-bit result 表达。
- operand-dependent clobber 表达。
- fallback 语义收敛。
- `off`/`dst_reg` 重载对应的 verifier 预处理和 kfunc descriptor 机制修改。

### 7.2 这个方案是否可行？

结论：有条件可行，但必须收窄范围。

我认为“可行”的收敛版本是：

- 第一阶段只支持 pure scalar inline kinsn 和 barrier。
- 不把 `bpf_reg_state *` 直接交给模块写。
- 由 core verifier 维护 read/write/clobber/result-width/tnum 应用。
- module 只提供 declarative metadata，或最多提供 very small operand decoder/constant validator。
- memory kinsn 单独设计，不和第一阶段混在一起。

### 7.3 这个方案是否安全？

结论：在“模块已是 trusted kernel code”的意义上安全边界可接受；在“verifier soundness 不应依赖模块 imperative callback”的意义上不够安全。

### 7.4 这个方案是否容易上游接受？

结论：按当前形式，上游接受概率低；按“declarative + 限定范围 + 不暴露 `bpf_reg_state`”重做后，才有讨论空间。

---

## 8. 我建议的修订方向

如果目标是既解决你们的实际问题，又尽量不把内核 verifier 变成“模块驱动的第二解释器”，我建议这样收敛：

### 8.1 第一阶段：只解决“现有 ABI call-site 覆盖率”

目标：

- 不做 operand encoding。
- 不改 `off` 语义。
- 先让 `KF_INLINE_EMIT` 支持受限的、保守的寄存器保留模型。

做法：

- 为当前固定 ABI kinsn 增加 kernel-owned per-kfunc clobber policy。
- x86 `rotate` 必须显式 clobber `r4`；不能宣称“只写 r0”。
- `narrow_result` 先只支持不依赖 source reg 的 scalar range，例如 extract/endian 的 fixed-width result。

这样做的优点：

- 不碰 `dst_reg/off` 保留字段。
- 不碰 kfunc descriptor key。
- 不碰 memory kinsn 编码。
- 能先验证“减少 caller-save 跳过点”是否值得。

### 8.2 第二阶段：若一定要 operand encoding，先做 kernel-owned decode 层

核心原则：

- module 不直接改 verifier state。
- kernel 先把 insn decode 成稳定的 operand descriptor。
- verifier 核心根据 descriptor 做：
  - read/write/clobber；
  - `check_kfunc_args` 泛化版；
  - `check_mem_access`；
  - result width/subreg/tnum 应用。

module 能提供的内容应尽量限定在：

- operand 格式类型。
- immediate 合法性检查。
- 纯 scalar result 的 declarative refine 信息。

### 8.3 memory kinsn 单独处理

建议：

- 不把 `endian_load` 作为“普通 inline scalar kfunc”的一个特例硬塞进去。
- 给它独立的 memory operand 描述，让 core verifier 重用 `LDX` 访问验证。
- 如果做不到，第一版直接排除 memory kinsn。

### 8.4 明确禁止的组合

第一版建议直接拒绝以下组合：

- `KF_INLINE_EMIT` + `KF_FASTCALL`
- `KF_INLINE_EMIT` + `KF_ACQUIRE`
- `KF_INLINE_EMIT` + `KF_RELEASE`
- `KF_INLINE_EMIT` + callback kfunc
- `KF_INLINE_EMIT` + sleepable/destructive/special-exception kfunc

---

## 9. 最终结论

我对这个方案的总评是：

- 方向对：你们确实抓住了真正的瓶颈，现有 `KF_INLINE_EMIT` 只有 JIT 语义，没有 verifier 语义，导致 caller-saved 冲突和 range 丢失。
- 但当前方案还不够完整：它缺 operand validation、memory semantics、tnum/subreg、fallback 语义、`off/dst_reg` 与现有 kfunc 基础设施的兼容层。
- 安全上可以成立，但前提不是“模块 verifier callback 没问题”，而是“模块本来就是 trusted kernel code”；这并不足以自动说服上游接受可写 `bpf_reg_state` callback。
- 真正更稳的路线是：把 module 参与 verifier 的方式限制为 declarative metadata，让 core verifier 仍然拥有全部状态转移逻辑。

一句话版本：

这个设计“可以被修成可行方案”，但“按当前形式还不能直接实现，更不适合原样拿去上游讨论”。

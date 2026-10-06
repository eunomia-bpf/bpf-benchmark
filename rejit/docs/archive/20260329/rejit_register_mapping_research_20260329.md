# REJIT 自定义寄存器映射可行性调研

日期：2026-03-29  
范围：只读调研，不修改内核/JIT 代码，不跑 VM。重点阅读 `vendor/linux-framework/arch/*/net/bpf_jit_comp.c` 和 `vendor/linux-framework/kernel/bpf/syscall.c`。

## TL;DR

结论先行：

1. `reg_map` 作为 REJIT 的可选输入，在机制上是可行的。
2. 但“任意 BPF 寄存器 -> 任意 native 寄存器”的自由映射并不可行，至少不能作为一个小改动完成。
3. x86 的空间非常紧。当前 16 个 GP 寄存器里，除 `rsp` 外几乎全部已经被 BPF 映射或 JIT 内部占用；真正现实的额外长期寄存器候选基本只剩 `r12`。
4. arm64 的空间明显更大。当前文件里未使用的整数寄存器较多，其中 `x23/x24` 是最适合的新增长期寄存器候选，因为它们是 callee-saved。
5. verifier 大概率不需要理解 `reg_map`。只要 BPF 语义不变，`reg_map` 可以作为 JIT 后端的实现细节，放在 `bpf_prog_select_runtime()` 之前写入 `prog->aux`。
6. “spill-to-register” 比“全局自定义 reg_map”更现实，但也只能做受限版本：只替换少量 64-bit、非 address-taken、成对 load/store 的 stack slot，并且只用额外的 callee-saved native 寄存器。
7. 最大的隐藏障碍不是 verifier，而是 JIT 内部保留寄存器、helper ABI、exception boundary save/restore，以及 kinsn native emit 接口目前拿不到 `reg_map`/slot 映射。

我的建议是分阶段做：

1. 先做 arm64 限制版：只允许把若干 spill slot 映射到 `x23/x24`，不先做完全自由的 `reg_map`。
2. 再做 x86 限制版：只尝试把少量 spill slot 映射到 `r12`。
3. 最后再考虑可配置的 BPF->native `reg_map`，而且要强约束可选寄存器集合，不要开放任意映射。

## 1. x86 BPF JIT 寄存器映射

主要代码位置：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:166-197`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:506-556`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1115-1256`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1534-1549`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1710-1764`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2761-2787`

### 1.1 当前映射表

`reg2hex[]` 是核心表，定义在 `arch/x86/net/bpf_jit_comp.c:181-197`：

| BPF 寄存器 | native 寄存器 |
| --- | --- |
| `BPF_REG_0` | `rax` |
| `BPF_REG_1` | `rdi` |
| `BPF_REG_2` | `rsi` |
| `BPF_REG_3` | `rdx` |
| `BPF_REG_4` | `rcx` |
| `BPF_REG_5` | `r8` |
| `BPF_REG_6` | `rbx` |
| `BPF_REG_7` | `r13` |
| `BPF_REG_8` | `r14` |
| `BPF_REG_9` | `r15` |
| `BPF_REG_FP` | `rbp` |
| `BPF_REG_AX` | `r10` |
| `AUX_REG` | `r11` |
| `X86_REG_R9` | `r9` |
| `X86_REG_R12` | `r12` |

文件里的注释已经直接说明了几个关键限制：

- `r12` 没被 BPF 寄存器直接使用，因为作为 base 寄存器做内存访问时会多一个编码字节，而且它还是 callee-saved。见 `:174-176`。
- `r9` 不给 BPF 程序使用，保留给 trampoline/private frame 等内部用途。见 `:178-179` 和 `:195`。
- `r10` 是 `BPF_REG_AX`，用于 blinding/临时用途。见 `:193`。
- `r11` 是 `AUX_REG`，也是 JIT 内部 scratch。见 `:194`。

### 1.2 x86 一共用了哪些寄存器，哪些还“空闲”

x86-64 有 16 个 GP 寄存器：

- `rax rbx rcx rdx rsi rdi rbp rsp r8 r9 r10 r11 r12 r13 r14 r15`

当前状态可以分三层看：

1. BPF 可见映射已经占用 11 个寄存器：
   - `rax rdi rsi rdx rcx r8 rbx r13 r14 r15 rbp`
2. JIT 内部又保留了 4 个：
   - `r9 r10 r11 r12`
3. `rsp` 是硬栈指针。

所以从“当前 JIT 整体是否还有真正空闲的 GP 寄存器”这个角度看，答案基本是：**没有**。

如果只问“BPF R0-R9 + FP 直接映射了多少个 native 寄存器”，答案是 **11 个**。  
如果问“当前 x86 JIT 全流程把多少个 GP 寄存器占住了”，答案接近 **15/16**。

### 1.3 prologue / epilogue 怎么保存寄存器

prologue 分两段：

1. `emit_prologue()` 在 `:506-556`
2. `do_jit()` 里在 prologue 之后继续 push callee-saved，在 `:1710-1738`

流程是：

- 普通程序先 `push rbp; mov rbp, rsp`。见 `:544-545`。
- 然后根据 `stack_depth` 做 `sub rsp, ...`。见 `:551-553`。
- 再由 `do_jit()` 决定是否 `push r12`，以及是否 push `rbx/r13/r14/r15`。见 `:1721-1732`。
- 如果启用了 arena，`r12` 还会被装成 arena base。见 `:1729-1735`。
- 如果启用了 private frame，`BPF_REG_FP` 后续会被重写成 `r9`。见 `:1737-1738` 和 `:1759-1764`。

callee-saved 的使用检测目前很硬编码：`detect_reg_usage()` 只扫描 `BPF_REG_6..9`，见 `:1534-1549`。这意味着：

- 当前 save/restore 逻辑默认只关心 `rbx/r13/r14/r15`
- 如果以后让别的 BPF 寄存器映射到其他 callee-saved native 寄存器，或者给 spill slot 分配额外 callee-saved 寄存器，就必须把这套逻辑泛化

epilogue 在 `BPF_EXIT` 分支里做：

- `pop_callee_regs(...)`
- 必要时 `pop_r12()`
- `leave`
- `ret`

见 `:2761-2787`。

### 1.4 x86 的 spill/fill 路径

核心在两个 helper：

- `emit_ldx()`，`:1115-1141`
- `emit_stx()`，`:1226-1256`

对 `BPF_DW`：

- load 会发出 `mov r64, [base+off]`，见 `emit_ldx()` 的 `:1135-1138`
- store 会发出 `mov [base+off], r64`，见 `emit_stx()` 的 `:1251-1253`

所以 BPF 层的典型 spill/fill：

```c
*(u64 *)(r10 - X) = rY
rZ = *(u64 *)(r10 - X)
```

在 x86 JIT 里会变成类似：

```asm
mov [rbp - X], <native_of_rY>
mov <native_of_rZ>, [rbp - X]
```

如果启用了 private frame，那么 `BPF_REG_FP` 在主循环里会先被改写成 `r9`，所以最后的 base 可能是 `r9` 而不是 `rbp`。见 `:1759-1764`。

### 1.5 如果改成可配置 `reg_map`，x86 需要改哪里

不是只改 `reg2hex[]` 一个表就完了，原因有两个：

1. x86 编码 helper 把静态映射嵌得很深。
2. save/restore、private frame、arena、exception boundary 都假设了当前寄存器角色。

需要动的地方至少包括：

- `reg2hex[]` 本身，以及所有依赖它的编码 helper
- `is_ereg()` / `is_ereg_8l()` / `add_1mod()` / `add_2mod()` / `add_3mod()` 这一串编码路径
- `emit_ldx()` / `emit_stx()` / `emit_mov_*()` / ALU/JMP/helper call 相关路径
- `detect_reg_usage()`
- `push_callee_regs()` / `pop_callee_regs()` / `push_r12()` / `pop_r12()`
- arena/private frame/exception boundary 逻辑

我对改动量的估计：

- 仅做“受限的 per-prog reg_map”，x86 大约 **250-400 LoC**
- 如果再加“spill-to-register”，额外再加 **150-250 LoC**

### 1.6 x86 的主要技术障碍

1. **没有真正空闲的 GP 寄存器。**
   - `r12` 是最现实的新增长期寄存器，但它已经被 arena base 使用，而且会增大指令编码。
2. **helper ABI 友好的现有布局不能随便破坏。**
   - `R1-R5 -> rdi/rsi/rdx/rcx/r8` 这套映射明显是为了尽量贴合 x86-64 C ABI。
   - 这点是从当前映射推断出来的，但和 helper call 语义是一致的。
3. **`r9/r10/r11` 不是安全的长期寄存器。**
   - `r9` 给 private frame/trampoline
   - `r10` 给 blinding/temp
   - `r11` 给 AUX/temp
4. **exception boundary 路径单独处理了保存集。**
   - 如果增加新的长期寄存器或 spill-slot 寄存器，这条路径也必须同步更新。

## 2. ARM64 BPF JIT 寄存器映射

主要代码位置：

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:48-77`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:374-455`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:513-620`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1033-1059`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1724-1915`

### 2.1 当前映射表

`bpf2a64[]` 定义在 `arch/arm64/net/bpf_jit_comp.c:49-77`：

| BPF 寄存器 | native 寄存器 |
| --- | --- |
| `BPF_REG_0` | `x7` |
| `BPF_REG_1` | `x0` |
| `BPF_REG_2` | `x1` |
| `BPF_REG_3` | `x2` |
| `BPF_REG_4` | `x3` |
| `BPF_REG_5` | `x4` |
| `BPF_REG_6` | `x19` |
| `BPF_REG_7` | `x20` |
| `BPF_REG_8` | `x21` |
| `BPF_REG_9` | `x22` |
| `BPF_REG_FP` | `x25` |
| `TMP_REG_1` | `x10` |
| `TMP_REG_2` | `x11` |
| `TMP_REG_3` | `x12` |
| `TCCNT_PTR` | `x26` |
| `BPF_REG_AX` | `x9` |
| `PRIVATE_SP` | `x27` |
| `ARENA_VM_START` | `x28` |

这里的注释更直白：

- `R1-R5` 被放到 `x0-x4`，用于 helper 参数。见 `:52-57`
- `R6-R9` 放在 callee-saved `x19-x22`。见 `:58-62`
- `FP` 放在 `x25`。见 `:63-64`

### 2.2 ARM64 一共用了哪些寄存器，哪些还“空闲”

arm64 有 31 个整数寄存器 `x0-x30`，`sp` 单独算。

当前 BPF 可见映射占用 11 个：

- `x0 x1 x2 x3 x4 x7 x19 x20 x21 x22 x25`

JIT 内部额外占用 7 个：

- `x9 x10 x11 x12 x26 x27 x28`

另外 prologue/epilogue 还显式使用：

- `x29` (`fp`)
- `x30` (`lr`)

当前文件里基本未被引用的整数寄存器包括：

- `x5 x6 x8 x13 x14 x15 x16 x17 x18 x23 x24`

这里要分“未使用”与“适合作为新增长期寄存器”：

- **`x23/x24` 最合适**，因为它们是 callee-saved，而且 exception-boundary 路径已经完整保存它们。见 `push_callee_regs()` 的 `:435-440`
- `x5/x6/x8/x13-x17` 虽然当前文件没用，但它们是 caller-saved，做长期寄存器会和 helper call/tail call/间接调用保护冲突
- `x18` 也不是好的第一候选，平台约定和特性配置下它可能带来额外约束

所以如果只考虑“新增稳定长期寄存器”，arm64 的首选是：**`x23/x24`**。

### 2.3 prologue / epilogue 怎么保存寄存器

`find_used_callee_regs()` 在 `:374-423`，作用和 x86 的 `detect_reg_usage()` 类似：

- 只扫描 `BPF_REG_6..9` 和 `BPF_REG_FP`
- 如果需要 private stack/arena，再把 `x27/x28` 加入保存集

普通路径的保存逻辑在 `push_callee_regs()`，`:425-455`：

- 正常情况下只 push “实际用到的 callee-saved 集”
- exception boundary 情况下直接 push 全部 `x19-x28`，见 `:435-440`

prologue 在 `build_prologue()`，`:513-620`：

- `stp x29, lr, [sp, #-16]!`
- `mov x29, sp`
- push callee-saved
- 设置 BPF FP
- 如果不是 private stack，再 `sub sp, sp, stack_size`
- 如果有 arena，再把 `kern_vm_start` 装到 `x28`

epilogue 在 `build_epilogue()`，`:1033-1059`：

- 回收 BPF stack
- `pop_callee_regs()`
- 恢复 `FP/LR`
- 把 BPF `r0` 对应的 `x7` 再搬回 ABI 返回寄存器 `x0`，见 `:1052-1053`
- `ret`

### 2.4 ARM64 的 spill/fill 路径

ARM64 没有像 x86 那样把 stack load/store 完全拆成独立 helper，而是直接在 `build_insn()` 的内存访问分支里做。

load 路径在 `:1724-1783`：

- 如果 `src == fp`，先把 base 改成真实的 `SP` 或 `PRIVATE_SP`，见 `:1724-1729`
- 然后发 `LDR*`
- `BPF_DW` 情况下用的是 `A64_LDR64I(...)` 或 `A64_LDR64(...)`，见 `:1777-1783`

store 路径在：

- `BPF_ST`：`:1815-1855`
- `BPF_STX`：`:1877-1915`

如果 `dst == fp`，同样先改写成 `SP` 或 `PRIVATE_SP`，再发 `STR*`。

所以 BPF 层的 stack spill/fill，最后会变成 arm64 的：

```asm
str <src>, [sp/private_sp, #off]
ldr <dst>, [sp/private_sp, #off]
```

而不是简单地对 `x25` 直接寻址。

### 2.5 如果改成可配置 `reg_map`，ARM64 需要改哪里

ARM64 也不是只改一个 `bpf2a64[]` 就够，但比 x86 好做一些，因为：

- A64 编码 helper 本来就更直接地传真实寄存器号
- 很多地方只是把 `bpf2a64[...]` 读到局部变量再发指令

需要改的主要点：

- `bpf2a64[]` 的读取入口，最好改成 per-prog `ctx->regmap[]`
- `find_used_callee_regs()`
- `push_callee_regs()` / `pop_callee_regs()`
- `build_prologue()` / `build_epilogue()`
- `build_insn()` 中所有直接读取 `bpf2a64[...]` 的路径
- helper call / tail call / atomics / exception boundary 相关路径

我对改动量的估计：

- 仅做“受限的 per-prog reg_map”，arm64 大约 **150-250 LoC**
- 如果再加“spill-to-register”，额外再加 **120-200 LoC**

### 2.6 ARM64 的主要技术障碍

1. **helper ABI 友好布局不能乱。**
   - 当前 `R1-R5 -> x0-x4` 是明显贴合 AAPCS/helper ABI 的设计。
2. **caller-saved 不能直接拿来做长期状态。**
   - 如果 daemon 想把长期活跃值映射到 `x5/x6/x8/x13...`，就必须在所有 helper call、tail call、trampoline、可能的 kinsn/native emit 点前后做保存恢复。
3. **当前 callee-save 发现逻辑只认识 `R6-R9/FP`。**
   - 如果把别的 BPF 寄存器映射到 `x23/x24`，或者让 spill slot 占用 `x23/x24`，这套逻辑必须同步泛化。

## 3. spill/fill 路径对“spill-to-register”的含义

### 3.1 JIT 现在怎么发 spill/fill

无论 x86 还是 arm64，JIT 当前都把 BPF stack 访问当成真实的内存访问来发：

- x86：`mov [rbp/r9 + off], reg` / `mov reg, [rbp/r9 + off]`
- arm64：`str/ldr [sp/private_sp + off]`

也就是说，今天没有“把某个 verifier stack slot 物化成 native 寄存器”的层。

### 3.2 如果要把 stack slot 改成 register-to-register，需要改哪里

最自然的切入点是“识别 `FP` 基址的 stack 访问并旁路成寄存器读写”：

- x86：在 `do_jit()` 的指令 lowering 主循环附近处理，或者在 `emit_ldx()/emit_stx()` 前加专门分支
- arm64：在 `build_insn()` 里 `src == fp` / `dst == fp` 的 load/store 分支里处理

需要新增的数据结构：

- `slot_map[stack_slot] -> native_reg`
- 可选的 liveness/use-count 元数据，供 daemon 挑少量最值得替换的 slot

新的 lowering 形态大致会变成：

```c
*(u64 *)(r10 - 0x20) = r6   ->   mov spill_reg0, native(r6)
r1 = *(u64 *)(r10 - 0x20)   ->   mov native(r1), spill_reg0
```

或者在 arm64 上是：

```asm
mov spill_reg0, x19
mov x0, spill_reg0
```

### 3.3 prologue 需要额外保存吗

需要。

只要 spill slot 用的是长期保活的 native 寄存器，它们就必须进入 save/restore 集：

- x86：现实候选基本是 `r12`
- arm64：现实候选首先是 `x23/x24`

如果 spill slot 用 caller-saved 寄存器，就不只是 prologue/epilogue 的问题了，还要在每个 helper call/tail call/native call 边界做保存恢复，复杂度会明显上升，我不建议作为第一版。

### 3.4 verifier 需不需要知道 slot->reg

我的判断是：**大概率不需要**。

原因：

- verifier 看到的还是原始 BPF 指令
- BPF stack 的语义没有变
- `slot->native_reg` 只是 JIT lowering 细节

只有在你想让 verifier 参与“哪些 slot 允许寄存器化”的合法性判定时，才需要额外接口；但从机制上讲，这不是必需条件。

## 4. kinsn emit 的冲突点

这是这次调研里我认为最容易被忽略的问题。

### 4.1 x86 kinsn emit 接口

`emit_kinsn_desc_call()` 在 `arch/x86/net/bpf_jit_comp.c:579-606`。

真正的 callback 形状是：

```c
kinsn->emit_x86(scratch, &off, emit, payload, bpf_prog)
```

它拿到：

- scratch buffer
- 输出偏移
- emit 标志
- payload
- `bpf_prog`

它拿不到：

- 当前 JIT 上下文
- 当前 native `reg_map`
- 当前 spill-slot 映射

### 4.2 arm64 kinsn emit 接口

`emit_kinsn_desc_call_arm64()` 在 `arch/arm64/net/bpf_jit_comp.c:1201-1235`。

callback 形状是：

```c
kinsn->emit_arm64(scratch, &scratch_idx, ctx->write, payload, bpf_prog)
```

同样拿不到 `reg_map` 或 slot 映射。

### 4.3 这意味着什么

如果某个 kinsn native emitter 默认假设“BPF R6 一定在 `rbx`/`x19`”之类的固定约定，那么：

- 自定义 `reg_map` 会悄悄把它搞错
- spill slot remap 也可能和它抢寄存器

所以二选一：

1. 扩展 kinsn emit ABI，把 `reg_map`/额外 scratch 寄存器约束显式传进去
2. 第一版直接限制：有 kinsn/native emit 的程序不允许启用自定义 reg_map / spill-to-register

我倾向于先做第 2 种限制版。

## 5. REJIT syscall 扩展怎么做

主要代码位置：

- `vendor/linux-framework/include/uapi/linux/bpf.h:1935-1945`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h:1935-1945`
- `vendor/linux-framework/kernel/bpf/syscall.c:3595-3615`
- `vendor/linux-framework/kernel/bpf/syscall.c:3636-3645`
- `vendor/linux-framework/kernel/bpf/syscall.c:3756-3766`

### 5.1 当前 REJIT attr 长什么样

`union bpf_attr.rejit` 当前只有这些字段：

- `prog_fd`
- `insn_cnt`
- `insns`
- `log_level`
- `log_size`
- `log_buf`
- `fd_array`
- `fd_array_cnt`
- `flags`

见两个 UAPI 头文件的 `:1935-1945`。

syscall 侧目前把：

- `BPF_PROG_REJIT_LAST_FIELD` 定义成 `rejit.flags`，见 `syscall.c:3595`
- 所有非零 `attr->rejit.flags` 直接拒掉，见 `:3614-3615`

### 5.2 适合的扩展方式

我建议把 `reg_map` 作为 `rejit` 子结构的新可选字段追加进去，而不是塞进 verifier 的 `load_attr`。

一种实际可行的形状是：

```c
struct {
	__u32 prog_fd;
	__u32 insn_cnt;
	__aligned_u64 insns;
	__u32 log_level;
	__u32 log_size;
	__aligned_u64 log_buf;
	__aligned_u64 fd_array;
	__u32 fd_array_cnt;
	__u32 flags;
	__aligned_u64 reg_map;
	__u32 reg_map_cnt;
	__u32 reg_map_flags;
} rejit;
```

其中 `reg_map` 指向一个用户态数组，内容可以是：

- 固定长度的 native reg 编号数组，按 `BPF_REG_0..BPF_REG_9/BPF_REG_FP` 编码
- 或者更显式的 `{bpf_reg, native_reg}` 小结构数组

我更倾向于第二种，因为更方便做稀疏映射和版本兼容。

### 5.3 syscall 里要改哪些点

最少需要改：

1. `include/uapi/linux/bpf.h`
2. `tools/include/uapi/linux/bpf.h`
3. `BPF_PROG_REJIT_LAST_FIELD`
4. `bpf_prog_rejit()` 里对新字段的 copy/validate
5. `tmp->aux` 上保存 `reg_map`
6. arch JIT 从 `prog->aux` 或 `jit_ctx` 读取这份映射

注意一件事：

- `BPF_PROG_REJIT_LAST_FIELD` 需要更新
- **`BPF_PROG_REJIT_LOAD_ATTR_SIZE` 大概率不需要改**

原因是：

- `BPF_PROG_REJIT_LOAD_ATTR_SIZE` 只影响传给 `bpf_check()` 的 `load_attr` 视图，见 `syscall.c:3165` 和 `:3760-3761`
- 如果 `reg_map` 不给 verifier 用，它不必进入 `load_attr`

### 5.4 verifier 要不要知道 `reg_map`

我的结论：**不需要**。

理由：

- verifier 只需要验证 BPF 程序语义
- `reg_map` 是 JIT backend 的 lowering 选择
- `bpf_prog_select_runtime(tmp, &err)` 在 verifier 之后才跑，见 `syscall.c:3765-3766`

比较自然的实现方式是：

1. `bpf_prog_rejit()` 从用户态拷贝 `reg_map`
2. 做基本合法性检查
3. 把它挂到 `tmp->aux`
4. `bpf_check()` 继续按原样工作
5. `bpf_prog_select_runtime()` 进入 arch JIT 时再消费这份 `reg_map`

### 5.5 syscall 侧至少要做哪些校验

至少需要：

- native 寄存器不能重复分配到两个长期 live 的 BPF 寄存器
- 不能碰 JIT 内部保留寄存器
- 不能破坏 helper ABI 所需的约束
- 不能选和 arena/private stack/exception path 冲突的寄存器
- 需要按架构分别校验

所以 `reg_map` 的校验不能是通用一套表，必须是 arch-aware 的。

## 6. spill-to-register 的现实可行性

### 6.1 可行，但必须做成“受限版”

我认为可行的第一版约束应该是：

1. 只处理 `u64` stack slot
2. 只处理“同一个 slot 同时出现 store-from-reg 和 load”的候选
3. 不处理 address-taken slot
4. 不处理混合宽度访问的 slot
5. 只允许使用额外 callee-saved native 寄存器

这样能把问题限制在“把少量热点 spill/fill 从内存换成寄存器 move”，而不是发明一个新的 native register allocator。

### 6.2 x86 上最现实的版本

x86 第一版最现实的形式是：

- 保持现有 BPF R0-R9 映射不动
- 只新增 1 个 spill 寄存器：`r12`

优点：

- 改动最局部
- 不碰 helper ABI
- save/restore 机制已有 `push_r12()/pop_r12()` 可复用

缺点：

- 只有 1 个真正现实的额外寄存器，收益上限有限
- `r12` 作 base/index 时编码更贵；虽然纯 reg-reg move 不受这个问题影响，但一旦混入寻址，代码尺寸会变差
- 如果 arena 已经占了 `r12`，就没有这个名额了

### 6.3 arm64 上最现实的版本

arm64 第一版最现实的形式是：

- 保持现有 BPF R0-R9 映射不动
- 只新增 2 个 spill 寄存器：`x23/x24`

优点：

- 两个都是 callee-saved
- exception-boundary 路径本来就保存 `x23/x24`
- 不碰 `x0-x4` helper ABI

缺点：

- save/restore 检测逻辑要泛化
- 仍然只能覆盖少量最热点 slot

### 6.4 和 kinsn emit 的冲突

如果启用 spill-to-register，必须额外回答：

- kinsn native emitter 是否会用这些额外寄存器
- kinsn 是否默认假设当前固定映射

所以第一版最好直接加限制：

- “含 native kinsn emit 的程序禁用 spill-to-register”

## 7. Corpus 静态数据

方法：

- 只做静态扫描，不跑 VM
- 用 `llvm-objdump -dr --no-show-raw-insn` 扫 `corpus/build/**/*.bpf.o`
- 识别 `r10` 相对的 stack 访问
- 同时区分“粗粒度 stack op 总量”和“更像 spill/fill 的成对 slot”

### 7.1 总量

共扫描 **917** 个 `.bpf.o`。

全 corpus 的静态计数：

- 总 BPF 指令数：**2,768,188**
- `call` 指令：**170,343**
- stack load：**293,062**
- stack store（来自寄存器）：**166,003**
- stack store（立即数）：**22**
- stack op 总数：**459,087**
- 其中 `u64` stack load：**255,922**
- `u64` stack store（来自寄存器）：**112,106**
- `u64` stack store（立即数）：**8**
- `u64` stack op 总数：**368,036**
- 含任意 stack op 的对象数：**459 / 917**
- 含任意 `u64` stack op 的对象数：**351 / 917**

这些数字是“所有 stack 访问”的上界，不等于“真实 spill/fill”。

### 7.2 更像 spill/fill 的候选

我用了更严格的近似口径：

- 同一个 `u64` stack slot
- 同时出现 `store-from-reg` 和 `load`

按这个口径，得到：

- paired `u64` slot ops：**141,499**
- paired `u64` slots：**4,407**

这个数字仍然不是“真实寄存器压力导致的 spill/fill”精确值，但比 368k 的粗总量更接近“值得被寄存器化的候选上界”。

两个有用的换算：

- paired 候选约占全部 `u64` stack op 的 **38.4%**
- 平均每个 `call` 对应大约 **0.83** 次 paired `u64` slot op

### 7.3 spill/fill 最重的对象

按更严格的 paired 指标，热点对象大致是：

| 对象 | paired `u64` slot ops |
| --- | ---: |
| `tracee/tracee.bpf.o` | 30,119 |
| `KubeArmor/system_monitor.bpf.o` | 26,919 |
| `KubeArmor/enforcer.bpf.o` | 5,092 |
| `coroot-node-agent/ebpf.bpf.o` | 4,887 |
| `tetragon/bpf_execve_event_v53.bpf.o` | 3,306 |
| `tetragon/bpf_execve_event_v511.bpf.o` | 2,863 |
| `tetragon/bpf_generic_tracepoint_v53.bpf.o` | 2,403 |
| 若干 tetragon retuprobe/retkprobe 变体 | 约 2.3k |
| `loxilb/llb_ebpf_emain.bpf.o` | 1,879 |
| `loxilb/llb_ebpf_main.bpf.o` | 1,821 |

### 7.4 代表性观察

1. `tracee/tracee.bpf.o`
   - 有大量围绕 helper 调用前后的 `r10-0x8 / -0x18 / -0x80 ...` 成对保存恢复
   - 这类模式比较像真正的“寄存器不够，只能借 stack 保活”

2. `KubeArmor/system_monitor.bpf.o`
   - 原始 `u64` stack op 很高
   - 但里面有相当一部分是大块 stack zeroing / scratch buffer 构造
   - 所以“raw stack op 高”不等于“spill-to-register 收益一定高”

3. `tetragon` 的若干 uprobe/tracepoint 程序
   - 有不少重复的 `r10-0x8`、`-0xb0/-0xc0/...` 之类成对槽位
   - 这类程序更像是值得优先做试验的对象

### 7.5 潜在收益怎么估

保守看：

- 不可能把全部 141k paired op 都消掉，因为额外寄存器数量很少
- 很多 stack slot 其实是结构体暂存、零初始化、helper 参数区，不是真 spill

现实一点的收益模型应该是：

1. daemon 做 liveness + hotness 排序
2. 每个程序只挑前 1-2 个最值钱的 `u64` slot
3. x86 用 `r12` 覆盖 1 个 slot
4. arm64 用 `x23/x24` 覆盖 1-2 个 slot

这更像是“消掉最热的少数 stack round-trip”，而不是大规模消除 stack 使用。

## 8. 改动量估算

只算实现，不算测试/调参：

| 子项 | 估算 |
| --- | ---: |
| REJIT UAPI + syscall 拷贝/校验 | 40-80 LoC |
| x86 受限版 `reg_map` | 250-400 LoC |
| arm64 受限版 `reg_map` | 150-250 LoC |
| x86 spill-to-register | 150-250 LoC |
| arm64 spill-to-register | 120-200 LoC |
| 共享 metadata/daemon 协议/验证胶水 | 80-150 LoC |

合起来，一个“跨 x86 + arm64、能稳定工作的第一版”大约是 **600-1,000 LoC** 量级，不含测试。

## 9. 最终判断

### 9.1 “自定义 BPF->native reg_map”是否可行

可行，但前提是：

- 不是开放任意 native 寄存器
- 不是忽略 helper ABI/JIT 保留寄存器/exception boundary/kinsn
- 最好按架构分别定义“允许的目标寄存器集合”

### 9.2 “spill-to-register”是否可行

可行，而且比“全局自由 remap”更值得先做。

原因：

- 它不需要重写 BPF helper ABI
- 不需要 verifier 感知
- 可以限制在极少数额外 callee-saved 寄存器上
- 收益更直接，目标更明确

### 9.3 两个架构哪个更适合先做

**arm64 更适合先做。**

原因：

1. 真正可用的额外 callee-saved 寄存器更多
2. `x23/x24` 是天然候选
3. 当前 JIT 对静态映射的耦合没有 x86 那么深

### 9.4 x86 的现实边界

x86 不是不能做，但第一版应该很克制：

- 不要一开始就做完全自由的 `reg_map`
- 不要碰 `r9/r10/r11`
- 优先只把极少数热点 spill slot 映射到 `r12`

## 10. 建议的实现顺序

1. **Phase 1: arm64 spill-to-register 限制版**
   - 只支持 `x23/x24`
   - 只支持 1-2 个 `u64` slot
   - 禁止与 kinsn/native emit 共存

2. **Phase 2: x86 spill-to-register 限制版**
   - 只支持 `r12`
   - arena 占用 `r12` 时直接禁用

3. **Phase 3: 受限版自定义 `reg_map`**
   - arm64 先行
   - 只允许映射到约定好的安全寄存器集合
   - verifier 仍保持无感知

4. **Phase 4: 解决 kinsn/native emit ABI**
   - 如果后续确实需要更自由的 remap，再扩展 kinsn emit 接口

## 附：本次调研的核心结论一句话版

REJIT 接受可选 `reg_map` 在机制上没问题，但真正值得做的不是“任意自定义寄存器映射”，而是“面向少量热点 stack slot 的、严格受限的 spill-to-register”；arm64 先做，x86 后做，verifier 不需要先动，kinsn 接口是主要隐患。

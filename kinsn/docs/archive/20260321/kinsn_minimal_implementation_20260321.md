# kinsn 最小实现可行性分析（基于 `vendor/linux-framework/` 内核源码）

## 0. 结论

- 以当前源码形态看，“完全通用、任意语义的新 BPF 指令由 module 注入且以后再也不用改 verifier/JIT/interpreter 主代码”不可行。原因是 verifier、x86 JIT、arm64 JIT、interpreter 都按 opcode/class 硬编码分发；未知 opcode 在 verifier/JIT 里直接报错，在 interpreter 里直接 `BUG_ON(1)`。`do_check_insn()` 的主分发在 `vendor/linux-framework/kernel/bpf/verifier.c:21032-21194`，x86 JIT 默认分支在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4255-4263`，arm64 JIT 默认分支在 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2470-2472`，interpreter 默认分支在 `vendor/linux-framework/kernel/bpf/core.c:2363-2373`。
- 但是，“一次性打一层通用 hook，后续 module 只注册 ALU64 标量变换类新指令”是可行的，而且改动可以做到比较小。最干净的落点是保留 `BPF_ALU64` 的一个空 op nibble，推荐 `0xe0`，把 `insn->off` 作为 extension id，后续 module 仅实现 verify/JIT/interpreter 回调。
- 这套最小方案足够实现 `ROTATE` 这类纯寄存器、无内存副作用、无控制流副作用的新指令。若把目标扩到 memory/jump/call 类指令，耦合面会立刻上升到 `check_mem_access()`、`check_cond_jmp_op()`、`push_stack()`、多 pass JIT relocation 这些内部机制，已不再是“小改动”。

我下面给出的方案因此明确限定为：

- `kinsn-v1` 只扩展 `BPF_ALU64`
- 语义限定为“标量寄存器变换”
- 不允许扩展指令自己访问内存、创建分支、修改 verifier CFG
- 三操作数形态 `dst = f(src, imm)` 通过已有 `MOV` + `kinsn` 两条指令表达；`kinsn` 本身仍保持 eBPF 既有的两操作数风格

这也是为什么我认为这个方案“可行”，但“可行范围必须收窄”。

---

## 1. BPF opcode 空间分析

### 1.1 8 个 instruction class

经典 BPF 在 `vendor/linux-framework/include/uapi/linux/bpf_common.h:5-14` 定义了：

- `BPF_LD = 0x00`
- `BPF_LDX = 0x01`
- `BPF_ST = 0x02`
- `BPF_STX = 0x03`
- `BPF_ALU = 0x04`
- `BPF_JMP = 0x05`
- `BPF_RET = 0x06`
- `BPF_MISC = 0x07`

eBPF 在 `vendor/linux-framework/include/uapi/linux/bpf.h:16-18` 把后两个数值重新解释为：

- `BPF_JMP32 = 0x06`
- `BPF_ALU64 = 0x07`

内核 disassembler 的 class 表也只剩 8 个 eBPF class：`vendor/linux-framework/kernel/bpf/disasm.c:62-70`。

结论：

- 当前 eBPF 实际可见的 8 个 class 是 `LD/LDX/ST/STX/ALU/JMP/JMP32/ALU64`
- `BPF_RET` / `BPF_MISC` 不是额外可复用 class；它们已经被 `JMP32/ALU64` 占用了
- 不存在单独预留的 “extension class”

### 1.2 每个 class 的 used / unused op 值

下面的 used/unused 是按 `code & 0xf0` 的 op nibble 统计；枚举基于：

- UAPI 宏定义：`vendor/linux-framework/include/uapi/linux/bpf_common.h:16-51`、`vendor/linux-framework/include/uapi/linux/bpf.h:20-55`
- 公开 opcode 白名单：`vendor/linux-framework/kernel/bpf/core.c:1651-1793`、`vendor/linux-framework/kernel/bpf/core.c:1795-1812`

| class | 已用 op 值 | 未用 op 值 | 备注 |
| --- | --- | --- | --- |
| `BPF_LD` | `0x10, 0x20, 0x30, 0x40, 0x50` | `0x00, 0x60, 0x70, 0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0` | 实际公开字节为 `LD|IMM|DW`、`LD|ABS|B/H/W`、`LD|IND|B/H/W`；见 `core.c:1793-1810` |
| `BPF_LDX` | `0x60, 0x70, 0x80, 0x90` | `0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0` | 公开字节为 `LDX|MEM|B/H/W/DW` 和 `LDX|MEMSX|B/H/W`；见 `core.c:1785-1791` |
| `BPF_ST` | `0x60, 0x70` | `0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x80, 0x90, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xf0` | 公开字节为 `ST|MEM|B/H/W/DW`；见 `core.c:1779-1782` |
| `BPF_STX` | `0x60, 0x70, 0xc0, 0xd0` | `0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x80, 0x90, 0xa0, 0xb0, 0xe0, 0xf0` | `STX|MEM|*` 和 `STX|ATOMIC|*`；见 `core.c:1767-1777` |
| `BPF_ALU` | `0x00` 到 `0xd0` 全部已用 | `0xe0, 0xf0` | `ADD..END` 全部占满；见 `bpf_common.h:30-51`、`bpf.h:27-35`、`disasm.c:73-88` |
| `BPF_JMP` | `0x00` 到 `0xe0`，只有 `0xf0` 未公开使用 | `0xf0` | `JA/JEQ/.../JCOND` 占用到 `0xe0`；见 `bpf_common.h:44-48`、`bpf.h:37-47`、`disasm.c:121-136` |
| `BPF_JMP32` | `0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0xa0, 0xb0, 0xc0, 0xd0` | `0x80, 0x90, 0xe0, 0xf0` | 只实现 32-bit 条件跳转和 `JA`；见 `core.c:1715-1739` |
| `BPF_ALU64` | `0x00` 到 `0xd0` 全部已用 | `0xe0, 0xf0` | 与 `BPF_ALU` 一样，干净地空出两个 op nibble；见 `core.c:1682-1710` |

### 1.3 `BPF_ALU64` class 的空闲空间

`BPF_ALU64` 的 op nibble 里，真正空着的是：

- `0xe0`
- `0xf0`

源码证据：

- `BPF_ALU64` 的现有 op 定义到 `BPF_END = 0xd0` 为止：`vendor/linux-framework/include/uapi/linux/bpf_common.h:32-42`、`vendor/linux-framework/include/uapi/linux/bpf.h:27-35`
- disasm 表也只填到了 `BPF_END >> 4`：`vendor/linux-framework/kernel/bpf/disasm.c:73-88`
- `BPF_INSN_MAP` 的 `ALU64` 分发只列到了 `END`：`vendor/linux-framework/kernel/bpf/core.c:1682-1710`

如果按“实际 byte 编码”而不是“op nibble”来数，`BPF_ALU64` 里有 6 个当前未用 byte：

- `0x8f`: `BPF_NEG | BPF_X | BPF_ALU64`，当前被 `check_alu_op()` 明确当作保留字段拒绝，`NEG` 只能是 `BPF_K` 形式，见 `vendor/linux-framework/kernel/bpf/verifier.c:16338-16345`
- `0xdf`: `BPF_END | BPF_TO_BE | BPF_ALU64`，当前也被拒绝；`ALU64` 下的 `BPF_END` 只能 `BPF_TO_LE`，见 `vendor/linux-framework/kernel/bpf/verifier.c:16346-16353`
- `0xe7`, `0xef`, `0xf7`, `0xff`: 两个空 op nibble × `K/X`

但真正“干净、对称、适合拿来做扩展 dispatcher”的只有后 4 个 byte：

- `BPF_ALU64 | 0xe0 | BPF_K`
- `BPF_ALU64 | 0xe0 | BPF_X`
- `BPF_ALU64 | 0xf0 | BPF_K`
- `BPF_ALU64 | 0xf0 | BPF_X`

### 1.4 `BPF_MISC` / `BPF_RET` 是否可用

不可用。

原因不是“没人用”，而是“数值已经被 eBPF 改义”：

- `BPF_RET = 0x06` / `BPF_MISC = 0x07`：`vendor/linux-framework/include/uapi/linux/bpf_common.h:13-14`
- `BPF_JMP32 = 0x06` / `BPF_ALU64 = 0x07`：`vendor/linux-framework/include/uapi/linux/bpf.h:17-18`

因此这两个 class 不能再单独拿出来当 extension class。

### 1.5 有没有预留的 extension class

没有。

8 个 class 数值已经全部用满，而且内核 disassembler class 表也刚好 8 个槽：`vendor/linux-framework/kernel/bpf/disasm.c:62-70`。

### 1.6 `BPF_ATOMIC` 的编码先例

`BPF_ATOMIC` 是一个非常重要的先例，因为它已经证明了“主 opcode + 次级 opcode”在 BPF ISA 里是现实存在的：

- `BPF_ATOMIC = 0xc0` 是 `STX` 类下的 mode：`vendor/linux-framework/include/uapi/linux/bpf.h:21-24`
- 真正的 atomic 子操作不在 `code`，而在 `insn->imm`，包括 `BPF_ADD`、`BPF_FETCH`、`BPF_XCHG`、`BPF_CMPXCHG`、`BPF_LOAD_ACQ`、`BPF_STORE_REL`：`vendor/linux-framework/include/uapi/linux/bpf.h:50-55`
- verifier 的 `check_atomic()` 直接按 `insn->imm` 二级分发：`vendor/linux-framework/kernel/bpf/verifier.c:8139-8171`

这正是我推荐 `kinsn` 用“保留一个主 opcode，再把 `off` 当 ext-id”的直接先例。

### 1.7 现有内部 hidden opcode 对“空闲空间”的影响

光看公开 UAPI 表，会高估可用空间。内核内部已经在多个 class 里偷偷用了很多 rewrite-only opcode：

- `BPF_TAIL_CALL = 0xf0`
- `BPF_PROBE_MEM = 0x20`
- `BPF_PROBE_MEMSX = 0x40`
- `BPF_PROBE_MEM32 = 0xa0`
- `BPF_PROBE_MEM32SX = 0xc0`
- `BPF_PROBE_ATOMIC = 0xe0`
- `BPF_CALL_ARGS = 0xe0`
- `BPF_NOSPEC = 0xc0`

这些定义在 `vendor/linux-framework/include/linux/filter.h:67-90`。interpreter jump table 也明确给它们开了专门 label：`vendor/linux-framework/kernel/bpf/core.c:1837-1846`。

所以：

- `JMP` class 表面看只空出 `0xf0`，但它已经被 `BPF_TAIL_CALL` 吃掉了
- `ST` / `STX` / `LDX` 表面有很多空洞，但很多已经被 `NOSPEC` / `PROBE_*` 家族内部占用
- 真正最干净、最少历史包袱的扩展位，仍然是 `ALU64` 的 `0xe0` / `0xf0`

### 1.8 最终结论：到底有多少空闲 opcode 可给 kinsn

我给三个口径：

1. 纯“公开 UAPI 未占用 byte”口径：当前 256 个 opcode byte 里，`bpf_opcode_in_insntable()` 白名单大约只放行了 129 个，剩余约 127 个 byte 还未公开使用；这个口径过于乐观，因为没扣掉 hidden rewrite opcode，且很多落在 load/store 历史编码空洞里，工程上不干净。依据：`vendor/linux-framework/kernel/bpf/core.c:1651-1812`。
2. “干净可复用的 ALU64 byte”口径：4 个，即 `0xe7/0xef/0xf7/0xff`。
3. “我建议 kinsn-v1 实际保留的 dispatcher byte”口径：2 个，即 `BPF_ALU64|0xe0|BPF_K` 和 `BPF_ALU64|0xe0|BPF_X`。`0xf0` 整个 nibble 留作将来二期扩展。

我建议采用第 3 种。

---

## 2. Verifier dispatch 耦合度分析

### 2.1 主 dispatch 在哪里

`do_check()` 主循环在 `vendor/linux-framework/kernel/bpf/verifier.c:21200-21373`，真正的“按指令分类分发”在 `do_check_insn()`，且 `do_check()` 在 `21308` 行调用它：

- `do_check()` 调用点：`vendor/linux-framework/kernel/bpf/verifier.c:21296-21314`
- `do_check_insn()` 本体：`vendor/linux-framework/kernel/bpf/verifier.c:21032-21194`

另外，在进入 `do_check()` 主循环之前，verifier 先用 `bpf_opcode_in_insntable()` 做基本白名单检查；未知 opcode 甚至进不到 `do_check_insn()`：

- 白名单检查：`vendor/linux-framework/kernel/bpf/verifier.c:21880-21882`
- 白名单表定义：`vendor/linux-framework/kernel/bpf/core.c:1795-1812`

因此，`kinsn` 至少必须改两个位置：

- `bpf_opcode_in_insntable()`
- `do_check_insn()`

### 2.2 `do_check_insn()` 当前覆盖的 dispatch 组合

`do_check_insn()` 当前只认这些大类：

- `BPF_ALU` / `BPF_ALU64` → `check_alu_op()`：`vendor/linux-framework/kernel/bpf/verifier.c:21038-21041`
- `BPF_LDX` → `check_load_mem()`：`vendor/linux-framework/kernel/bpf/verifier.c:21043-21051`
- `BPF_STX` 且 `mode == BPF_ATOMIC` → `check_atomic()`：`vendor/linux-framework/kernel/bpf/verifier.c:21052-21059`
- `BPF_STX` 且 `mode == BPF_MEM` → `check_store_reg()`：`vendor/linux-framework/kernel/bpf/verifier.c:21061-21068`
- `BPF_ST` → 先 `check_reg_arg()`，再 `check_mem_access()`：`vendor/linux-framework/kernel/bpf/verifier.c:21069-21093`
- `BPF_JMP` / `BPF_JMP32`
  - `CALL` → `check_func_call()` / `check_kfunc_call()` / `check_helper_call()`：`vendor/linux-framework/kernel/bpf/verifier.c:21098-21132`
  - `JA` → 直接更新 `env->insn_idx` 或走 `check_indirect_jump()`：`vendor/linux-framework/kernel/bpf/verifier.c:21133-21156`
  - `EXIT` → `process_bpf_exit_full()`：`vendor/linux-framework/kernel/bpf/verifier.c:21157-21166`
  - 其余条件跳转 → `check_cond_jmp_op()`：`vendor/linux-framework/kernel/bpf/verifier.c:21167-21170`
- `BPF_LD`
  - `ABS/IND` → `check_ld_abs()`：`vendor/linux-framework/kernel/bpf/verifier.c:21175-21178`
  - `IMM` → `check_ld_imm()`：`vendor/linux-framework/kernel/bpf/verifier.c:21180-21186`

按 op 家族展开，可以更具体地写成：

- `check_alu_op()` 覆盖 `ADD/SUB/MUL/DIV/OR/AND/LSH/RSH/NEG/MOD/XOR/MOV/ARSH/END`，见 `vendor/linux-framework/kernel/bpf/verifier.c:16338-16524`
- `check_cond_jmp_op()` 覆盖 `JEQ/JNE/JGT/JLT/JGE/JLE/JSGT/JSLT/JSGE/JSLE/JSET/JCOND`，见 `vendor/linux-framework/kernel/bpf/verifier.c:17458-17470`
- `JMP/JMP32` 中只有 `CALL`、`JA`、`EXIT` 不走 `check_cond_jmp_op()`，而是在 `do_check_insn()` 里单独分支，见 `vendor/linux-framework/kernel/bpf/verifier.c:21098-21168`
- `JMP32` 明确没有 `CALL/EXIT/JCOND`，从公开 opcode 表就能看出来：`vendor/linux-framework/kernel/bpf/core.c:1715-1739`

### 2.3 default case 当前做什么

`do_check_insn()` 的未知 class 默认分支是：

- `verbose(env, "unknown insn class %d\n", class);`
- `return -EINVAL;`

源码：`vendor/linux-framework/kernel/bpf/verifier.c:21191-21193`

更细一点：

- `ALU/ALU64` 内部未知 opcode 不是在 `do_check_insn()` default，而是在 `check_alu_op()` 里被 `opcode > BPF_END` 拒绝：`vendor/linux-framework/kernel/bpf/verifier.c:16520-16522`
- `LD` 类未知 mode 也会在类内拒绝：`vendor/linux-framework/kernel/bpf/verifier.c:21187-21189`
- 条件跳转类里若 `opcode == BPF_JA` 或 `opcode > BPF_JCOND` 也直接 `-EINVAL`：`vendor/linux-framework/kernel/bpf/verifier.c:17464-17468`

所以，如果把 `kinsn` 放进 `ALU64` 的保留 op nibble，就必须在 `check_alu_op()` 之前截获；否则它会被现有 `opcode > BPF_END` 路径直接拒绝。

### 2.4 各类指令依赖 verifier 内部哪些状态

#### ALU 路径

`check_alu_op()` 在 `vendor/linux-framework/kernel/bpf/verifier.c:16332-16572`。它依赖：

- 当前寄存器文件 `cur_regs(env)`：`vendor/linux-framework/include/linux/bpf_verifier.h:901-903`
- 操作数合法性检查 `check_reg_arg()`：`vendor/linux-framework/kernel/bpf/verifier.c:3966-3973`
- 指针值判定 `is_pointer_value()`：`vendor/linux-framework/kernel/bpf/verifier.c:6454-6457`
- 标量范围传播 `adjust_scalar_min_max_vals()`：`vendor/linux-framework/kernel/bpf/verifier.c:16014-16167`
- 指针/标量混合传播 `adjust_reg_min_max_vals()`：`vendor/linux-framework/kernel/bpf/verifier.c:16172-16328`
- 范围一致性检查 `reg_bounds_sanity_check()`：`vendor/linux-framework/kernel/bpf/verifier.c:2780-2787`
- 目的寄存器未知化 `mark_reg_unknown()`：`vendor/linux-framework/kernel/bpf/verifier.c:2881-2892`
- 边界同步 `reg_bounds_sync()`：`vendor/linux-framework/kernel/bpf/verifier.c:2763-2778`

#### Memory 路径

核心是 `check_mem_access()`，入口在 `vendor/linux-framework/kernel/bpf/verifier.c:7681-7702`。它直接碰 verifier 的内存模型：

- `cur_regs(env)` / 当前 frame 寄存器
- 指针对齐 `check_ptr_alignment()`
- 区域合法性 `check_mem_region_access()`
- map 访问权限/边界
- stack 读写状态
- ctx 访问
- packet pointer 访问
- BTF typed pointer 访问

`check_load_mem()` 和 `check_store_reg()` 只是薄封装：

- `check_load_mem()`：`vendor/linux-framework/kernel/bpf/verifier.c:7951-7981`
- `check_store_reg()`：`vendor/linux-framework/kernel/bpf/verifier.c:7984-8010`

结论：memory 类扩展如果想 module 化，必须把 verifier 的内存类型系统一起开放，远超“最小改动”。

#### Jump 路径

条件跳转在 `check_cond_jmp_op()`，入口 `vendor/linux-framework/kernel/bpf/verifier.c:17449-17704`。它依赖：

- `check_reg_arg()` 检查操作数：`17494-17509`
- 指针比较规则：`17511-17517`、`17549-17552`、`17656-17696`
- 分支状态栈 `push_stack()`：`vendor/linux-framework/kernel/bpf/verifier.c:2122-2140`
- jmp history `push_jmp_history()`：`vendor/linux-framework/kernel/bpf/verifier.c:4079-4100`
- linked regs / nullability / min-max 分支传播

结论：jump 类扩展也不适合纳入 `kinsn-v1`。

#### Call 路径

`CALL` 在 `do_check_insn()` 里根据 `src_reg` 再二次分发：

- `BPF_PSEUDO_CALL` → `check_func_call()`：`vendor/linux-framework/kernel/bpf/verifier.c:21120-21121`
- `BPF_PSEUDO_KFUNC_CALL` → `check_kfunc_call()`：`vendor/linux-framework/kernel/bpf/verifier.c:21122-21125`
- 普通 helper → `check_helper_call()`：`vendor/linux-framework/kernel/bpf/verifier.c:21126-21127`

它们都会清 scratch 状态，至少 `R0` 会被 mark scratched：`vendor/linux-framework/kernel/bpf/verifier.c:21129-21132`，而 `mark_reg_scratched()` 只是一个 header inline：`vendor/linux-framework/include/linux/bpf_verifier.h:1017-1020`。

`check_helper_call()` 很大，入口 `vendor/linux-framework/kernel/bpf/verifier.c:11618-12120`；`check_kfunc_call()` 同样很大，入口 `vendor/linux-framework/kernel/bpf/verifier.c:14088-14480`。这两条路都已经不是 opcode-level 扩展，而是“把 verifier 的调用 ABI 再做一次外部开放”。

### 2.5 kfunc 在 verifier 里的 dispatch 路径

kfunc 不是独立 opcode；它仍然走 `BPF_JMP | BPF_CALL`，只是 `src_reg == BPF_PSEUDO_KFUNC_CALL`：

- `BPF_PSEUDO_KFUNC_CALL` 定义：`vendor/linux-framework/include/uapi/linux/bpf.h:1382-1385`
- `do_check_insn()` 的 kfunc 分发：`vendor/linux-framework/kernel/bpf/verifier.c:21098-21127`

后续链路是：

1. `check_kfunc_call()` 做语义检查：`vendor/linux-framework/kernel/bpf/verifier.c:14088-14480`
2. `add_kfunc_call()` 把用到的 kfunc 描述符塞进 `prog->aux->kfunc_tab` / `kfunc_btf_tab`：`vendor/linux-framework/kernel/bpf/verifier.c:3432-3524`
3. `fixup_kfunc_call()` 在 verifier fixup 阶段把 `insn->imm` 改成相对 `__bpf_call_base` 的 call offset，或者保留 far-call 形式：`vendor/linux-framework/kernel/bpf/verifier.c:23184-23213`

这条路径证明了两件事：

- 新能力不一定要新 opcode；也可以在已有 opcode 上复用额外字段
- 程序级别保存 owner/module ref 是可行的，kfunc 已经这样做了

### 2.6 如果 module 直接操作 verifier internals，最少需要哪些 API

如果不做新的 wrapper ops-table，而是让 module 直接调用 verifier 现有 internals，那么对一个最简单、最保守的 ALU-type 新指令（例如“把 `dst` 视为输入输出寄存器，最后把结果类型降成 unknown scalar”），最少需要：

- `static int check_reg_arg(struct bpf_verifier_env *env, u32 regno, enum reg_arg_type t)`：`vendor/linux-framework/kernel/bpf/verifier.c:3966-3973`
- `static bool is_pointer_value(struct bpf_verifier_env *env, int regno)`：`vendor/linux-framework/kernel/bpf/verifier.c:6454-6457`
- `static void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, u32 regno)`：`vendor/linux-framework/kernel/bpf/verifier.c:2881-2892`
- `cur_regs(env)`：已是 header inline，`vendor/linux-framework/include/linux/bpf_verifier.h:901-903`

若想保留更高精度，还会进一步需要：

- `static void __mark_reg_known(struct bpf_reg_state *reg, u64 imm)`：`vendor/linux-framework/kernel/bpf/verifier.c:2187-2195`
- `static void reg_bounds_sync(struct bpf_reg_state *reg)`：`vendor/linux-framework/kernel/bpf/verifier.c:2763-2778`
- `static int reg_bounds_sanity_check(struct bpf_verifier_env *env, struct bpf_reg_state *reg, const char *ctx)`：`vendor/linux-framework/kernel/bpf/verifier.c:2780-2787`

但是我不推荐这么做；推荐做法是由 core 把这些能力包装成 `struct bpf_insn_ext_verifier_ops`，module 通过回调上下文拿函数指针，不直接链接这些静态符号。

### 2.7 ROTATE verify 回调的最小 API 需求

若把 `ROTATE` 的编码限制为与现有 ALU 一样的二操作数风格：

- `dst = rotate(dst, imm)`，或
- `dst = rotate(dst, src_reg)`，

那么 verify 回调最小只要做下面几件事：

1. `check_reg_arg(env, dst, SRC_OP)`，确保读 `dst` 合法
2. 如果是 `X` 形式，再 `check_reg_arg(env, src, SRC_OP)`
3. `is_pointer_value(env, dst)` / `is_pointer_value(env, src)`，拒绝任何指针参与 rotate
4. `check_reg_arg(env, dst, DST_OP_NO_MARK)`，确认写 `dst` 合法
5. 最保守地 `mark_reg_unknown(env, regs, dst)`，把结果建模成 unknown scalar

这就已经足够安全。对 `ROTATE` 来说，不需要 `adjust_reg_min_max_vals()`、`check_mem_access()`、`push_stack()` 这些重型内部 API。

---

## 3. JIT dispatch 耦合度分析

## 3.1 x86 JIT

### 3.1.1 主 dispatch、default case、上下文

x86 主入口是 `do_jit()`：

- 入口：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3187-3190`
- 主 switch 从 `3290` 行开始：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3290-4264`
- default case：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4255-4263`

`default` 行为非常直接：

- 打 `pr_err("bpf_jit: unknown opcode %02x\n", insn->code);`
- 返回 `-EINVAL`

JIT 上下文 `struct jit_context` 非常小，只记录：

- `cleanup_addr`
- `tail_call_direct_label`
- `tail_call_indirect_label`
- `fp_start`
- `fp_end`

定义位置：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:318-330`

### 3.1.2 x86 emit 回调最少需要哪些内部状态

对一个“只发直线代码、不发本地分支”的 ALU-like 扩展，最少需要：

- 输出缓冲区游标 `u8 **pprog`
- BPF 寄存器到 x86 物理寄存器的映射
- 原始字节 emit 能力
- 少量寄存器编码 helper

当前源码里的对应内部对象是：

- `emit_code()` / `EMIT1..EMIT5`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:27-57`
- `reg2hex[]`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:183-199`
- `is_ereg()`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:219-229`
- `add_1mod()` / `add_2mod()` / `add_1reg()` / `add_2reg()`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:250-287`
- `emit_mov_reg()`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1008-1023`

若扩展指令想自己发 branch/call，就还会依赖：

- `addrs[]`
- `image`
- pass 收敛逻辑

这些都来自 `do_jit()` 的多 pass 框架：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5318-5392`。这也是我建议 `kinsn-v1` 禁止扩展指令自己发控制流的原因。

### 3.1.3 ROTATE 的 x86 emit 最小 API

x86 现成就有一个 rotate helper：

- `emit_canonical_rotate()`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2169-2224`

它说明了 rotate immediate 真正需要的最小东西：

- 取得映射后寄存器：`x86_jit_param_reg(...)`，`2179-2184`
- 计算 `ror_imm = width - rot_amount`：`2185-2186`
- `RORX` fast path 用到：
  - `is_ereg()`：`2193-2197`
  - `reg2hex[]`：`2203`
  - `EMIT4()` / `EMIT2()`：`2205-2206`
- fallback path 用到：
  - `emit_mov_reg()`：`2214-2215`
  - `add_1mod()` / `add_1reg()` / `EMIT3()`：`2217-2221`

所以，如果 `kinsn` 要给 module 开一个“足够写 ROTATE”的 x86 emit API，最少要有：

- `map_reg()`
- `reg_bits()`
- `is_ereg()`
- `emit1/emit2/emit3/emit4()`
- `emit_mov_reg()`
- `add_1mod()` / `add_1reg()`

### 3.1.4 x86 多 pass / convergence

x86 不是单 pass。收敛循环在：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5329-5392`

逻辑是：

- 先用粗估值初始化 `addrs[]`
- 反复 `do_jit()`，直到 `proglen` 不再缩小
- 再分配最终 image

因此：

- 若扩展指令自己发分支，module emit 回调必须读 `addrs[]`
- 若只发定长直线 ALU 指令，完全可以不暴露这些复杂状态

这再次支持 `kinsn-v1` 只做 ALU64 标量变换。

## 3.2 arm64 JIT

### 3.2.1 主 dispatch、default case、上下文

arm64 的实际单指令发码函数是 `build_insn()`：

- 入口：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1763`
- default case：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2470-2472`

上层 `build_body()` 在 `2494-2508` 循环遍历 BPF insn，并调用 `build_insn()`：

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2478-2520`

arm64 的 JIT 上下文 `struct jit_ctx` 比 x86 大，包含：

- `idx`
- `offset[]`
- `image`
- `ro_image`
- `write`
- `extable`
- `num_exentries`
- `stack_size`
- `priv_stack_ptr`

定义在：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:80-99`

### 3.2.2 emit 回调最少需要哪些内部状态

对不发控制流的 ALU-like 指令，arm64 的最小需求比 x86 更干净：

- BPF → A64 reg 映射 `bpf2a64[]`：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:49-78`
- 单条 32-bit 指令 emit：`emit()`，`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:120-126`

如果扩展指令自己要发 branch / call / literal pool / PLT，就必须碰：

- `offset[]`
- `idx`
- `ro_image`
- `write`
- pass 2 / pass 3 的重放逻辑

arm64 的三 pass 在：

- pass 1：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2699-2716`
- pass 2：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2735-2771`
- pass 3：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2772-2780`

因此，和 x86 一样，`kinsn-v1` 最好限制成不发控制流的直线代码。

### 3.2.3 ROTATE 的 arm64 emit 最小 API

arm64 现成 helper 是：

- `emit_canonical_rotate_arm64()`：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:638-651`

它直接说明 rotate immediate 的最低需求：

- 取 `width`、`rot_amount`
- `ror_imm = width - rot_amount`：`641-647`
- `emit(A64_ROR_I(...), ctx)`：`648-650`

`A64_ROR_I` 宏在 `vendor/linux-framework/arch/arm64/net/bpf_jit.h:210-213`，本质上就是 `EXTR(Rn, Rn, imm)`。

所以一个“足够实现 ROTATE”的 arm64 module API，最少只要：

- `map_reg()`
- `emit()`
- `a64_ror_i()`

## 3.3 kfunc 在 JIT 里的路径

x86 和 arm64 对 kfunc 的处理并不一样：

- x86 `BPF_CALL` case 直接拿 `imm32` 当相对 `__bpf_call_base` 的偏移去发 call：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4001-4021`
- verifier 在 fixup 阶段已经把 kfunc 的 `imm` 改成 `BPF_CALL_IMM(desc->addr)`：`vendor/linux-framework/kernel/bpf/verifier.c:23197-23213`

所以在 x86 上：

- kfunc 到 JIT 时，已经和普通 helper call 没有 opcode 级别区别

arm64 更通用：

- `BPF_CALL` case 里调用 `bpf_jit_get_func_addr()`：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2172-2175`
- `bpf_jit_get_func_addr()` 若 `src_reg == BPF_PSEUDO_KFUNC_CALL && bpf_jit_supports_far_kfunc_call()`，会走 `bpf_get_kfunc_addr()`：`vendor/linux-framework/kernel/bpf/core.c:1349-1353`

但本树里：

- x86 `bpf_jit_supports_kfunc_call() == true`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5548-5551`
- arm64 `bpf_jit_supports_kfunc_call() == true`：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2959-2962`
- `bpf_jit_supports_far_kfunc_call()` 默认 weak false：`vendor/linux-framework/kernel/bpf/core.c:3207-3215`

因此本树中 x86/arm64 实际都依赖 verifier 先把 kfunc 改成普通 relative call。

这给 `kinsn` 的启发是：

- 若扩展要运行期仍保留“专用 opcode”，则 JIT 必须显式增加 case
- 若扩展能在 verifier/fixup 阶段完全改写成现有指令，则 JIT 无需改动

本题要求“真新指令 + native emit”，所以仍然需要 JIT 主 dispatch 一次性打洞。

---

## 4. Interpreter dispatch 分析

### 4.1 主 dispatch 在哪里

interpreter 的主执行循环是 `___bpf_prog_run()`：

- `vendor/linux-framework/kernel/bpf/core.c:1828-2374`

它是 computed goto 风格：

- jump table：`vendor/linux-framework/kernel/bpf/core.c:1830-1847`
- 取下一条：`vendor/linux-framework/kernel/bpf/core.c:1855-1856`

`BPF_INSN_MAP()` 生成了绝大多数公开 opcode 的 label 映射：`vendor/linux-framework/kernel/bpf/core.c:1651-1793`

### 4.2 default case 当前做什么

默认 label：

- 打 `pr_warn("BPF interpreter: unknown opcode %02x (imm: 0x%x)\n", ...)`
- `BUG_ON(1)`

源码：`vendor/linux-framework/kernel/bpf/core.c:2363-2373`

也就是说 interpreter 不是“未知指令返回错误”，而是直接当内核 bug 处理。

### 4.3 interpreter 的寄存器 / 栈状态怎么传

wrapper 宏非常清楚：

- `DEFINE_BPF_PROG_RUN()`：`vendor/linux-framework/kernel/bpf/core.c:2377-2387`
- `DEFINE_BPF_PROG_RUN_ARGS()`：`vendor/linux-framework/kernel/bpf/core.c:2390-2405`

执行状态是：

- `u64 regs[MAX_BPF_EXT_REG]`
- `u64 stack[stack_size / sizeof(u64)]`
- `FP` 指向栈顶：`2384` / `2398`
- `ARG1..ARG5` 或 `BPF_R1..R5` 先填好
- 然后把 `regs` 和 `insn` 传给 `___bpf_prog_run()`

所以 interpreter callback 如果只做“寄存器内算术”，完全不需要更多上下文，只要：

- `u64 *regs`
- `const struct bpf_insn *insn`

### 4.4 computed goto 是编译期固定的，怎么加 extension dispatch

动态给 jump table 塞新 label 不现实；正确做法只能是：

- 一次性保留一个静态 opcode
- jump table 给这个 opcode 绑到一个固定 label
- label 里再做“二级动态分发”

这和前面 opcode 分析完全一致：`kinsn-v1` 最适合做成

- 固定主 opcode：`BPF_ALU64 | BPF_KINSN | {K/X}`
- 二级 id：`insn->off`

然后 interpreter 只新增一个静态 label，例如 `ALU64_KINSN`。

---

## 5. kfunc 注册机制对标分析

## 5.1 注册宏和注册入口

kfunc ID 集合宏：

- `BTF_KFUNCS_START(name)`：`vendor/linux-framework/include/linux/btf_ids.h:212-213`
- `BTF_KFUNCS_END(name)`：`vendor/linux-framework/include/linux/btf_ids.h:215-216`

kfunc set 结构：

- `struct btf_kfunc_id_set { owner, set, filter }`：`vendor/linux-framework/include/linux/btf.h:121-125`

注册 API：

- 声明：`vendor/linux-framework/include/linux/btf.h:579-585`
- 实现：`vendor/linux-framework/kernel/bpf/btf.c:8929-8946`
- 导出：`EXPORT_SYMBOL_GPL(register_btf_kfunc_id_set)`，`vendor/linux-framework/kernel/bpf/btf.c:8946`

一个实际模块例子在 `vendor/linux-framework/kernel/bpf/crypto.c:354-396`：

- 先 `BTF_KFUNCS_START/END`
- 再写 `static const struct btf_kfunc_id_set ... = { .owner = THIS_MODULE, .set = ... }`
- 最后模块 init 里调用 `register_btf_kfunc_id_set()`

## 5.2 verifier 里怎么处理 kfunc

`CALL` + `src_reg == BPF_PSEUDO_KFUNC_CALL` 时：

- `do_check_insn()` 走 `check_kfunc_call()`：`vendor/linux-framework/kernel/bpf/verifier.c:21098-21127`
- `check_kfunc_call()` 入口：`vendor/linux-framework/kernel/bpf/verifier.c:14088-14480`

它做的事远比 helper 多，包括：

- BTF 元数据抓取
- 参数类型检查
- sleepable / RCU / preempt / irq 上下文检查
- ref / resource / release 规则
- 返回值寄存器建模

所以 kfunc 并不是一个“通用 verifier 外插接口”；它只是一个被 core 硬编码支持的新调用形态。

## 5.3 kfunc 的 program 生命周期 pinning

这条链路对 `kinsn` 最有参考价值。

### 5.3.1 verifier 获取并持有 module ref

当 kfunc 来自 module BTF 时，verifier 会：

- 通过 `btf_get_by_fd()` 拿 module BTF：`vendor/linux-framework/kernel/bpf/verifier.c:3278-3282`
- 检查它确实是 module BTF：`3284-3287`
- `btf_try_get_module(btf)` 拿 module ref：`3290-3294`
- 把 `{btf, module, offset}` 记录到 `prog->aux->kfunc_btf_tab`：`3296-3305`

源码：`vendor/linux-framework/kernel/bpf/verifier.c:3249-3310`

内核自己也在 `btf_kfunc_flags()` 前面的注释里强调了“verifier context 下调用时必须持有对应 module ref”，因为 `prog->aux->kfunc_btf_tab` 正是这层保护：`vendor/linux-framework/kernel/bpf/btf.c:8873-8879`

### 5.3.2 prog free 时释放 ref

- `bpf_free_kfunc_btf_tab()` 里逐个 `module_put()` / `btf_put()`：`vendor/linux-framework/kernel/bpf/verifier.c:3313-3323`
- `bpf_prog_free_deferred()` 调用它：`vendor/linux-framework/kernel/bpf/core.c:2984-2993`

### 5.3.3 module BTF 生命周期侧

`btf_try_get_module()` 只会对 live module 成功，并调用 `try_module_get()`：

- `vendor/linux-framework/kernel/bpf/btf.c:8414-8438`

内核对 module BTF 的 notifier 生命周期管理在：

- `vendor/linux-framework/kernel/bpf/btf.c:8379-8394`

### 5.3.4 kfunc 对 `kinsn` 的直接启发

`kinsn` 应该模仿的不是 BTF 本身，而是这套“程序级 owner pinning”：

- verifier 第一次看见某个扩展指令时，给所属 module `try_module_get()`
- 记录到 `prog->aux->insn_ext_tab`
- 程序释放时 `module_put()`

这样 module unload 就天然安全，和 kfunc 一致。

## 5.4 kfunc 的一个限制：没有 unregister

kfunc 只提供 `register_btf_kfunc_id_set()`，没有对应 unregister。它甚至明确要求只能在 initcall/module init 调：`vendor/linux-framework/kernel/bpf/btf.c:8929-8946`。

`kinsn` 这里我建议比 kfunc 多做一步：

- 提供 `bpf_unregister_insn_extension()`

因为 `kinsn` 用的是纯 runtime registry，不依赖 BTF set 拼接，做 unregister 很容易。

---

## 6. 最小改动方案

## 6.0 设计约束

为了把改动压到最小，我建议 `kinsn-v1` 的 ABI 明确写死这几个约束：

1. 只扩展 `BPF_ALU64`
2. 固定 opcode：`BPF_ALU64 | BPF_KINSN | {BPF_K, BPF_X}`
3. `insn->off` 作为 `u16 ext_id`
4. 只允许“纯寄存器、无控制流、无内存副作用”的标量变换
5. `kinsn` 自身采用与现有 ALU 相同的两操作数语义：`dst = op(dst, imm/src)`  
   如果用户想要三操作数 `dst = op(src, imm)`，先发一条 `MOV dst, src`
6. `K` 形式若程序启用了 constant blinding，则默认拒绝；二期再考虑 K→X blind rewrite

这样做的理由，都能直接从现有源码看到：

- memory 指令要碰 `check_mem_access()` 一整套地址/对象类型系统：`vendor/linux-framework/kernel/bpf/verifier.c:7681-7946`
- jump 指令要碰 `push_stack()` / 状态分叉：`vendor/linux-framework/kernel/bpf/verifier.c:17449-17704`、`2122-2140`
- x86 / arm64 若要让 module 自己发 branch，就得开放多 pass relocation 状态：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5318-5392`、`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2699-2780`

### 6a. 新增文件：`include/linux/bpf_insn_ext.h`

下面是我建议的完整 API 轮廓。它刻意只暴露“实现 ALU64 标量扩展所需的最小 surface”，不把 verifier/JIT 巨大内部状态直接导给 module。

同时，还需要一个很小的 UAPI 保留位：

```c
/* include/uapi/linux/bpf.h */
#define BPF_KINSN 0xe0 /* ALU64 extension dispatch; insn->off stores ext_id */
```

建议的新头文件：

```c
/* include/linux/bpf_insn_ext.h */
#ifndef _LINUX_BPF_INSN_EXT_H
#define _LINUX_BPF_INSN_EXT_H

#include <linux/bpf.h>
#include <linux/bpf_verifier.h>
#include <linux/module.h>

#define BPF_KINSN_CODE_K (BPF_ALU64 | BPF_KINSN | BPF_K)
#define BPF_KINSN_CODE_X (BPF_ALU64 | BPF_KINSN | BPF_X)

#define BPF_KINSN_IMM(dst, ext_id, imm) \
	BPF_RAW_INSN(BPF_KINSN_CODE_K, dst, BPF_REG_0, (ext_id), (imm))

#define BPF_KINSN_REG(dst, src, ext_id) \
	BPF_RAW_INSN(BPF_KINSN_CODE_X, dst, src, (ext_id), 0)

enum bpf_insn_ext_flags {
	BPF_INSN_EXT_F_IMM            = BIT(0), /* supports BPF_KINSN_CODE_K */
	BPF_INSN_EXT_F_REG            = BIT(1), /* supports BPF_KINSN_CODE_X */
	BPF_INSN_EXT_F_BLINDABLE_IMM  = BIT(2), /* optional future K->X rewrite */
};

struct bpf_insn_ext_verifier_ops {
	int  (*check_reg_arg)(struct bpf_verifier_env *env, u32 regno, int t);
	bool (*is_pointer_value)(struct bpf_verifier_env *env, int regno);
	void (*mark_reg_unknown)(struct bpf_verifier_env *env,
				 struct bpf_reg_state *regs, u32 regno);
	void (*mark_reg_known)(struct bpf_reg_state *regs, u32 regno, u64 imm);
	void (*reg_bounds_sync)(struct bpf_reg_state *reg);
	void (*log)(struct bpf_verifier_env *env, const char *fmt, ...);
};

struct bpf_insn_ext_verifier_ctx {
	struct bpf_verifier_env *env;
	struct bpf_insn *insn;
	struct bpf_reg_state *regs; /* current frame regs */
	const struct bpf_insn_ext_verifier_ops *ops;
	const struct bpf_insn_extension *ext;
};

struct bpf_insn_ext_jit_x86_ctx;
struct bpf_insn_ext_jit_arm64_ctx;

struct bpf_insn_ext_x86_ops {
	u32 (*map_reg)(struct bpf_insn_ext_jit_x86_ctx *ctx, u8 bpf_reg);
	u8  (*reg_bits)(u32 native_reg);
	bool (*is_ereg)(u32 native_reg);
	u8  (*add_1mod)(u8 byte, u32 reg);
	u8  (*add_1reg)(u8 byte, u32 reg);
	void (*emit1)(struct bpf_insn_ext_jit_x86_ctx *ctx, u8 b1);
	void (*emit2)(struct bpf_insn_ext_jit_x86_ctx *ctx, u8 b1, u8 b2);
	void (*emit3)(struct bpf_insn_ext_jit_x86_ctx *ctx, u8 b1, u8 b2, u8 b3);
	void (*emit4)(struct bpf_insn_ext_jit_x86_ctx *ctx,
		      u8 b1, u8 b2, u8 b3, u8 b4);
	void (*emit_mov_reg)(struct bpf_insn_ext_jit_x86_ctx *ctx,
			     bool is64, u32 dst, u32 src);
};

struct bpf_insn_ext_jit_x86_ctx {
	const struct bpf_prog *prog;
	const struct bpf_insn *insn;
	int insn_idx;
	bool use_priv_fp;
	void *priv;   /* struct jit_context *; opaque to modules */
	u8 **pprog;   /* temp buffer cursor inside do_jit() */
	const struct bpf_insn_ext_x86_ops *ops;
};

struct bpf_insn_ext_arm64_ops {
	u8  (*map_reg)(struct bpf_insn_ext_jit_arm64_ctx *ctx, u8 bpf_reg);
	u32 (*a64_ror_i)(bool is64, u8 rd, u8 rn, u32 imm);
	void (*emit)(struct bpf_insn_ext_jit_arm64_ctx *ctx, u32 insn);
};

struct bpf_insn_ext_jit_arm64_ctx {
	const struct bpf_prog *prog;
	const struct bpf_insn *insn;
	int insn_idx;
	void *priv; /* struct jit_ctx *; opaque to modules */
	const struct bpf_insn_ext_arm64_ops *ops;
};

struct bpf_insn_ext_interp_ctx {
	const struct bpf_prog *prog;
	const struct bpf_insn *insn;
	u64 *regs;
	const struct bpf_insn_extension *ext;
};

struct bpf_insn_extension {
	struct module *owner;
	u16 id;
	const char *name;
	u32 flags;

	int  (*verify)(struct bpf_insn_ext_verifier_ctx *ctx);
	int  (*emit_x86)(struct bpf_insn_ext_jit_x86_ctx *ctx);
	int  (*emit_arm64)(struct bpf_insn_ext_jit_arm64_ctx *ctx);
	void (*interpret)(struct bpf_insn_ext_interp_ctx *ctx);
};

int bpf_register_insn_extension(struct bpf_insn_extension *ext);
void bpf_unregister_insn_extension(struct bpf_insn_extension *ext);

/* core-only helpers, not for modules */
const struct bpf_insn_extension *
bpf_prog_find_insn_extension(const struct bpf_prog *prog, u16 ext_id);
int bpf_record_prog_insn_extension(struct bpf_verifier_env *env,
				   const struct bpf_insn *insn,
				   const struct bpf_insn_extension **out_ext);
void bpf_free_prog_insn_extensions(struct bpf_prog_aux *aux);

#endif
```

我建议再新增一个内部实现文件，例如 `kernel/bpf/insn_ext.c`，做三件事：

- 全局 registry：`ext_id -> struct bpf_insn_extension *`
- verifier 时的 program-level pinning：`prog->aux->insn_ext_tab`
- JIT / interpreter 的 `prog->aux` 查表

内部表结构可以直接模仿 kfunc：

```c
struct bpf_prog_insn_ext_desc {
	u16 id;
	struct module *module;
	const struct bpf_insn_extension *ext;
};

struct bpf_prog_insn_ext_tab {
	struct bpf_prog_insn_ext_desc *descs;
	u32 nr_descs;
};
```

### 6b. `verifier.c` 改动

必须动三个点：

1. opcode 白名单
2. `do_check_insn()` 主 dispatch
3. `prog->aux` free path的记录结构

#### 6b.1 opcode 白名单

`bpf_opcode_in_insntable()` 当前白名单在 `vendor/linux-framework/kernel/bpf/core.c:1799-1812`。需要加：

```c
[BPF_KINSN_CODE_K] = true,
[BPF_KINSN_CODE_X] = true,
```

否则 verifier 在 `vendor/linux-framework/kernel/bpf/verifier.c:21880-21882` 就先把它当 unknown opcode 拒掉了。

#### 6b.2 `do_check_insn()` 中新增 kinsn 分支

插入点：`vendor/linux-framework/kernel/bpf/verifier.c:21038-21041` 之前，原因是现有 `check_alu_op()` 会在 `16520-16522` 把 `opcode > BPF_END` 的东西全部拒掉。

建议伪代码：

```c
/* verifier.c */
static int check_kinsn_alu64(struct bpf_verifier_env *env, struct bpf_insn *insn)
{
	const struct bpf_insn_extension *ext;
	struct bpf_insn_ext_verifier_ctx ctx;
	u16 ext_id = (u16)insn->off;
	bool is_reg = BPF_SRC(insn->code) == BPF_X;

	if (BPF_CLASS(insn->code) != BPF_ALU64 || BPF_OP(insn->code) != BPF_KINSN) {
		verbose(env, "invalid kinsn opcode %02x\n", insn->code);
		return -EINVAL;
	}

	if (!ext_id) {
		verbose(env, "kinsn ext_id 0 is reserved\n");
		return -EINVAL;
	}

	ext = NULL;
	if (bpf_record_prog_insn_extension(env, insn, &ext))
		return -EINVAL;

	if (is_reg) {
		if (!(ext->flags & BPF_INSN_EXT_F_REG)) {
			verbose(env, "kinsn %s does not support reg form\n", ext->name);
			return -EINVAL;
		}
	} else {
		if (!(ext->flags & BPF_INSN_EXT_F_IMM)) {
			verbose(env, "kinsn %s does not support imm form\n", ext->name);
			return -EINVAL;
		}
		if (env->prog->blinding_requested &&
		    !(ext->flags & BPF_INSN_EXT_F_BLINDABLE_IMM)) {
			verbose(env, "kinsn %s imm form is not supported under constant blinding\n",
				ext->name);
			return -EOPNOTSUPP;
		}
	}

	if (!ext->verify) {
		verbose(env, "kinsn %s has no verifier callback\n", ext->name);
		return -EINVAL;
	}

	ctx.env  = env;
	ctx.insn = insn;
	ctx.regs = cur_regs(env);
	ctx.ops  = &bpf_insn_ext_verifier_ops;
	ctx.ext  = ext;

	return ext->verify(&ctx);
}

static int do_check_insn(struct bpf_verifier_env *env, bool *do_print_state)
{
	...
	if (class == BPF_ALU64 && BPF_OP(insn->code) == BPF_KINSN) {
		err = check_kinsn_alu64(env, insn);
		if (err)
			return err;
		return 0;
	}
	if (class == BPF_ALU || class == BPF_ALU64) {
		err = check_alu_op(env, insn);
		...
	}
	...
}
```

#### 6b.3 verifier wrapper ops 的具体绑定

`bpf_insn_ext_verifier_ops` 可以绑定成：

```c
static void bpf_insn_ext_mark_reg_known(struct bpf_reg_state *regs, u32 regno, u64 imm)
{
	__mark_reg_known(&regs[regno], imm);
}

static const struct bpf_insn_ext_verifier_ops bpf_insn_ext_verifier_ops = {
	.check_reg_arg   = check_reg_arg,
	.is_pointer_value = is_pointer_value,
	.mark_reg_unknown = mark_reg_unknown,
	.mark_reg_known   = bpf_insn_ext_mark_reg_known,
	.reg_bounds_sync  = reg_bounds_sync,
	.log              = bpf_verifier_log_write,
};
```

这样 module 不需要直接链接 verifier 的静态符号。

### 6c. `do_jit()` / `build_insn()` 改动

### 6c.1 x86

插入点：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3290-4264` 的 switch 中，新增两个 case 即可。

建议伪代码：

```c
/* x86 JIT */
static int emit_kinsn_x86(struct bpf_prog *prog, const struct bpf_insn *insn,
			  int insn_idx, u8 **pprog, bool use_priv_fp,
			  struct jit_context *ctx)
{
	const struct bpf_insn_extension *ext;
	struct bpf_insn_ext_jit_x86_ctx xctx;

	ext = bpf_prog_find_insn_extension(prog, (u16)insn->off);
	if (!ext || !ext->emit_x86)
		return -EINVAL;

	xctx.prog = prog;
	xctx.insn = insn;
	xctx.insn_idx = insn_idx;
	xctx.use_priv_fp = use_priv_fp;
	xctx.priv = ctx;
	xctx.pprog = pprog;
	xctx.ops = &bpf_insn_ext_x86_ops;

	return ext->emit_x86(&xctx);
}

switch (insn->code) {
case BPF_KINSN_CODE_K:
case BPF_KINSN_CODE_X:
	err = emit_kinsn_x86(bpf_prog, insn, i - 1, &prog,
			     priv_frame_ptr != NULL, ctx);
	if (err)
		return err;
	break;
...
default:
	...
}
```

这里的 `bpf_insn_ext_x86_ops` 只需要薄包装现有静态 helper：

- `map_reg()`：复用 `do_jit()` 里现成的 `priv_frame_ptr` remap 逻辑，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3268-3274`
- `reg_bits()`：包装 `reg2hex[]`，定义在 `183-199`
- `is_ereg()`：`219-229`
- `add_1mod()` / `add_1reg()`：`250-287`
- `emit1..emit4()`：包装 `EMIT1..EMIT4`，这些宏本身不能导出
- `emit_mov_reg()`：`1008-1023`

### 6c.2 arm64

插入点：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1763-2472` 的 `build_insn()` switch。

建议伪代码：

```c
static int emit_kinsn_arm64(struct jit_ctx *ctx, const struct bpf_insn *insn,
			    int insn_idx)
{
	const struct bpf_insn_extension *ext;
	struct bpf_insn_ext_jit_arm64_ctx actx;

	ext = bpf_prog_find_insn_extension(ctx->prog, (u16)insn->off);
	if (!ext || !ext->emit_arm64)
		return -EINVAL;

	actx.prog = ctx->prog;
	actx.insn = insn;
	actx.insn_idx = insn_idx;
	actx.priv = ctx;
	actx.ops = &bpf_insn_ext_arm64_ops;

	return ext->emit_arm64(&actx);
}

switch (code) {
case BPF_KINSN_CODE_K:
case BPF_KINSN_CODE_X:
	ret = emit_kinsn_arm64(ctx, insn, i);
	if (ret)
		return ret;
	break;
...
default:
	...
}
```

`bpf_insn_ext_arm64_ops` 只要包装：

- `map_reg()` → `bpf2a64[]` / `arm64_jit_param_reg()` 同类逻辑，见 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:49-78`、`632-636`
- `emit()` → `120-126`
- `a64_ror_i()` → 包装 `A64_ROR_I`，定义在 `vendor/linux-framework/arch/arm64/net/bpf_jit.h:210-213`

### 6d. interpreter 改动

需要动三处：

1. jump table
2. `___bpf_prog_run()` 入口保存 `prog`
3. free path

#### 6d.1 jump table 加固定 label

在 `vendor/linux-framework/kernel/bpf/core.c:1832-1847` 增加：

```c
[BPF_KINSN_CODE_K] = &&ALU64_KINSN_K,
[BPF_KINSN_CODE_X] = &&ALU64_KINSN_X,
```

#### 6d.2 `___bpf_prog_run()` 中增加静态 extension dispatch

建议伪代码：

```c
static u64 ___bpf_prog_run(u64 *regs, const struct bpf_insn *insn)
{
	const struct bpf_insn *prog_start = insn;
	const struct bpf_prog *prog =
		container_of(prog_start, struct bpf_prog, insnsi);
	...

ALU64_KINSN_K:
ALU64_KINSN_X: {
		const struct bpf_insn_extension *ext;
		struct bpf_insn_ext_interp_ctx ictx;

		ext = bpf_prog_find_insn_extension(prog, (u16)insn->off);
		if (unlikely(!ext || !ext->interpret))
			goto default_label;

		ictx.prog = prog;
		ictx.insn = insn;
		ictx.regs = regs;
		ictx.ext = ext;
		ext->interpret(&ictx);
		CONT;
	}
	...
}
```

这就是解决 “computed goto table 是编译期固定的，怎么加动态 dispatch” 的最小方法：不动态加 label，只加一个静态 opcode → label，再在 label 里二级查表。

#### 6d.3 程序释放时 drop extension refs

`struct bpf_prog_aux` 目前已有：

- `kfunc_tab`
- `kfunc_btf_tab`

见 `vendor/linux-framework/include/linux/bpf.h:1741-1743`。`kinsn` 直接照着加一个：

```c
struct bpf_prog_insn_ext_tab *insn_ext_tab;
```

然后在 `bpf_prog_free_deferred()`，靠近现有 `bpf_free_kfunc_btf_tab()` 的位置，新增：

```c
bpf_free_prog_insn_extensions(aux);
```

插入点：`vendor/linux-framework/kernel/bpf/core.c:2984-2993`

### 6e. 需要 EXPORT 的函数列表

#### 6e.1 推荐方案下，必须新增导出的符号

推荐方案里，不需要把现有 verifier/JIT internals 直接 `EXPORT_SYMBOL_GPL` 给 module；因为 module 是通过 core 回调拿到 `ops` 表的。真正必须新增导出的只有：

- `int bpf_register_insn_extension(struct bpf_insn_extension *ext);`
- `void bpf_unregister_insn_extension(struct bpf_insn_extension *ext);`

另外，verifier 日志本身已经有现成导出：

- `bpf_verifier_log_write()` 已导出：`vendor/linux-framework/kernel/bpf/log.c:316`

#### 6e.2 如果坚持直接调用现有 static internals，还需要哪些 export/wrapper

不推荐，但如果硬要让 module 直接碰 verifier/JIT internals，那么最少还需要：

Verifier 侧：

- `check_reg_arg(struct bpf_verifier_env *env, u32 regno, enum reg_arg_type t)`  
  源码：`vendor/linux-framework/kernel/bpf/verifier.c:3966-3973`  
  用途：检查读/写寄存器是否合法
- `is_pointer_value(struct bpf_verifier_env *env, int regno)`  
  源码：`vendor/linux-framework/kernel/bpf/verifier.c:6454-6457`  
  用途：禁止 pointer 进入自定义 ALU 指令
- `mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, u32 regno)`  
  源码：`vendor/linux-framework/kernel/bpf/verifier.c:2881-2892`  
  用途：安全地把结果降成 unknown scalar
- `__mark_reg_known(struct bpf_reg_state *reg, u64 imm)`  
  源码：`vendor/linux-framework/kernel/bpf/verifier.c:2187-2195`  
  用途：若扩展想在 constant case 维持精度
- `reg_bounds_sync(struct bpf_reg_state *reg)`  
  源码：`vendor/linux-framework/kernel/bpf/verifier.c:2763-2778`  
  用途：手动更新边界

x86 侧：

- `emit_code()` / `EMIT1..EMIT4` 不能直接 export，因为后者是宏：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:27-57`  
  结论：必须新增 wrapper
- `is_ereg(u32 reg)`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:219-229`
- `add_1mod(u8 byte, u32 reg)`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:250-255`
- `add_1reg(u8 byte, u32 reg)`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:278-281`
- `emit_mov_reg(u8 **pprog, bool is64, u32 dst_reg, u32 src_reg)`：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1008-1023`
- `reg2hex[]` 也是 `static const`，不能直接 export，最好改成 wrapper `reg_bits()`

arm64 侧：

- `emit(const u32 insn, struct jit_ctx *ctx)`：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:120-126`
- `A64_ROR_I` 是 arch-private header 宏：`vendor/linux-framework/arch/arm64/net/bpf_jit.h:210-213`  
  结论：要么给 module 公开 wrapper，要么让 module 直接依赖 arch-private header
- `bpf2a64[]` 是 `static const`，最好包装成 `map_reg()`

所以从工程上看，推荐方案必须是“新增 `ops` wrapper surface”，不要直接导出旧 static internals。

---

## 7. 验证：以 ROTATE 指令为例

我用一个最保守、能证明接口足够的例子：

- 指令名：`rotate64`
- extension id：`1`
- 语义：`dst = rol64(dst, imm)`  
  如果用户想表达 `dst = rol64(src, imm)`，先发 `MOV dst, src`
- 只支持 imm 形式  
  这样和 x86 `RORX` / arm64 `ROR` immediate 路径完全吻合

之所以选 rotate-left 语义，是因为现有 x86 / arm64 helper 都把它实现成 rotate-right `width - amount`：

- x86：`ror_imm = width - rot_amount`，`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2180-2186`
- arm64：`ror_imm = width - rot_amount`，`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:644-650`

### 7.1 模块伪代码

```c
/* bpf_rotate.c */
#include <linux/module.h>
#include <linux/bpf_insn_ext.h>
#include <linux/bitops.h>
#include <asm/cpufeature.h> /* x86 BMI2 path if built on x86 */

#define BPF_KINSN_ROTATE64 1

static int rotate64_verify(struct bpf_insn_ext_verifier_ctx *ctx)
{
	struct bpf_verifier_env *env = ctx->env;
	struct bpf_insn *insn = ctx->insn;
	struct bpf_reg_state *regs = ctx->regs;
	int err;

	/* This module only supports imm form. */
	if (BPF_SRC(insn->code) != BPF_K) {
		ctx->ops->log(env, "rotate64: reg form is not implemented\n");
		return -EINVAL;
	}

	/* We do not support K-form under constant blinding in v1. */
	if (env->prog->blinding_requested) {
		ctx->ops->log(env, "rotate64: imm form is not supported under constant blinding\n");
		return -EOPNOTSUPP;
	}

	/* Reserved fields. */
	if (insn->src_reg != BPF_REG_0) {
		ctx->ops->log(env, "rotate64: src_reg must be 0 in imm form\n");
		return -EINVAL;
	}

	if ((u32)insn->imm >= 64) {
		ctx->ops->log(env, "rotate64: immediate %d is out of range [0, 63]\n",
			      insn->imm);
		return -EINVAL;
	}

	/* Read dst as source. */
	err = ctx->ops->check_reg_arg(env, insn->dst_reg, SRC_OP);
	if (err)
		return err;

	if (ctx->ops->is_pointer_value(env, insn->dst_reg)) {
		ctx->ops->log(env, "rotate64: R%d pointer operand is prohibited\n",
			      insn->dst_reg);
		return -EACCES;
	}

	/* Write dst. */
	err = ctx->ops->check_reg_arg(env, insn->dst_reg, DST_OP_NO_MARK);
	if (err)
		return err;

	/*
	 * Conservative model: result is an unknown scalar.
	 * This is safe and requires no custom min/max algebra.
	 */
	ctx->ops->mark_reg_unknown(env, regs, insn->dst_reg);
	return 0;
}

#ifdef CONFIG_X86_64
static int rotate64_emit_x86(struct bpf_insn_ext_jit_x86_ctx *ctx)
{
	const struct bpf_insn *insn = ctx->insn;
	u32 dst = ctx->ops->map_reg(ctx, insn->dst_reg);
	u8 ror_imm = 64 - (u8)insn->imm;

	/*
	 * BMI2 RORX encoding, same idea as emit_canonical_rotate():
	 * C4 / VEX ... F0 /r imm8
	 */
	if (static_cpu_has(X86_FEATURE_BMI2)) {
		u8 byte2 = 0x03;
		u8 byte3 = 0xFB; /* 64-bit */
		u8 modrm;

		if (!ctx->ops->is_ereg(dst))
			byte2 |= 0x80;
		byte2 |= 0x40;
		if (!ctx->ops->is_ereg(dst))
			byte2 |= 0x20;

		modrm = 0xC0 | (ctx->ops->reg_bits(dst) << 3) |
			ctx->ops->reg_bits(dst);

		ctx->ops->emit4(ctx, 0xC4, byte2, byte3, 0xF0);
		ctx->ops->emit2(ctx, modrm, ror_imm);
		return 0;
	}

	/* Fallback: ROR r64, imm8 */
	ctx->ops->emit1(ctx, ctx->ops->add_1mod(0x48, dst));
	ctx->ops->emit3(ctx, 0xC1, ctx->ops->add_1reg(0xC8, dst), ror_imm);
	return 0;
}
#endif

#ifdef CONFIG_ARM64
static int rotate64_emit_arm64(struct bpf_insn_ext_jit_arm64_ctx *ctx)
{
	const struct bpf_insn *insn = ctx->insn;
	u8 dst = ctx->ops->map_reg(ctx, insn->dst_reg);
	u32 ror_imm = 64 - (u32)insn->imm;

	ctx->ops->emit(ctx, ctx->ops->a64_ror_i(true, dst, dst, ror_imm));
	return 0;
}
#endif

static void rotate64_interpret(struct bpf_insn_ext_interp_ctx *ctx)
{
	const struct bpf_insn *insn = ctx->insn;
	u64 v = ctx->regs[insn->dst_reg];
	u32 amt = (u32)insn->imm & 63;

	ctx->regs[insn->dst_reg] = rol64(v, amt);
}

static struct bpf_insn_extension rotate64_ext = {
	.owner = THIS_MODULE,
	.id = BPF_KINSN_ROTATE64,
	.name = "rotate64",
	.flags = BPF_INSN_EXT_F_IMM,
	.verify = rotate64_verify,
#ifdef CONFIG_X86_64
	.emit_x86 = rotate64_emit_x86,
#endif
#ifdef CONFIG_ARM64
	.emit_arm64 = rotate64_emit_arm64,
#endif
	.interpret = rotate64_interpret,
};

static int __init bpf_rotate_init(void)
{
	return bpf_register_insn_extension(&rotate64_ext);
}

static void __exit bpf_rotate_exit(void)
{
	bpf_unregister_insn_extension(&rotate64_ext);
}

module_init(bpf_rotate_init);
module_exit(bpf_rotate_exit);
MODULE_LICENSE("GPL");
```

### 7.2 这个例子证明了什么

这个 `rotate64.ko` 例子证明：

- verifier callback 用最小 wrapper API 足够实现一个新的 ALU64 opcode 语义检查
- x86 callback 用“寄存器映射 + 字节 emit + 少量编码 helper”足够 native 发码
- arm64 callback 用“寄存器映射 + `emit()` + `A64_ROR_I` wrapper”足够 native 发码
- interpreter callback 只要 `regs + insn` 就能执行
- module 生命周期可由 `prog->aux->insn_ext_tab` pin 住

也就是说，题目要求的四个 callback 维度都能被这一组接口覆盖。

---

## 8. 风险和障碍

### 8.1 opcode 冲突风险

如果采用我推荐的“单一 dispatcher opcode + ext_id”方案，opcode 冲突风险非常低：

- 主 opcode 只保留一次：`BPF_ALU64 | BPF_KINSN | {K/X}`
- 后续不同 module 的区分不靠新 opcode，而靠 `ext_id`

真正的冲突从“opcode 冲突”变成了“ext_id 冲突”。

缓解方式：

- `bpf_register_insn_extension()` 用全局 registry，重复 id 直接 `-EEXIST`
- 文档约定 `ext_id` 由模块统一分配

### 8.2 多 module 注册同一 opcode / ext_id

若采用单一 dispatcher：

- 所有 module 都共享同一主 opcode，不冲突
- 只有同一 `ext_id` 冲突

这比“每个 module 吃一个独立 opcode byte”明显更稳，因为后者很快会把 `ALU64` 的 4 个干净空 byte 用光。

### 8.3 verify 回调 bug 的安全问题

和 kfunc 相比，`kinsn` 更危险。

kfunc 的 verifier 逻辑全部还在 core 里：

- `check_kfunc_call()` 是内核自带代码：`vendor/linux-framework/kernel/bpf/verifier.c:14088-14480`

而 `kinsn` 的 verify callback 若放到 module，就变成：

- module 代码直接参与寄存器类型建模

这意味着：

- 一个 bug 就可能把 pointer 当 scalar 放行
- 或错误地保留了边界精度

所以我建议的安全边界是：

1. `kinsn-v1` 只允许 ALU64 scalar transform
2. core 只给 module 最小 mutator API，不开放 memory/jump verifier internals
3. module 的 verify callback 默认采取最保守建模：`mark_reg_unknown()`

这会比 kfunc 更保守，但明显更安全。

### 8.4 interpreter computed goto table 固定

这是硬约束，不是风险猜测。源码已经写死：

- jump table 是静态数组：`vendor/linux-framework/kernel/bpf/core.c:1832-1847`

所以动态注册新 label 根本不是选项。可行解只能是：

- 静态保留一个主 opcode
- label 里二级动态分发

### 8.5 Constant blinding

这是 `kinsn-v1` 的最大现实障碍之一。

原因很直接：`bpf_jit_blind_insn()` 当前只认识现有一小组 opcode：

- `vendor/linux-framework/kernel/bpf/core.c:1374-1504`

它对未知 opcode 的行为是“不重写，直接跳过”，调用点在：

- `vendor/linux-framework/kernel/bpf/core.c:1606-1609`

所以如果 `K` 形式 `kinsn` 直接放行到 JIT blinding：

- immediate 会以明文保留在指令里

这是安全问题。`kinsn-v1` 的最小解决方案应当是：

- verifier 若看到 `env->prog->blinding_requested` 且扩展没有声明 `BPF_INSN_EXT_F_BLINDABLE_IMM`，直接拒绝 `K` 形式

对应 `struct bpf_prog` 里的 blinding 标志在：

- `vendor/linux-framework/include/linux/bpf.h:1814-1815`

二期增强方案才是：

- 在 `bpf_jit_blind_insn()` 里新增 `BPF_KINSN_CODE_K` → `BPF_KINSN_CODE_X` 的 blind rewrite

但这已经超出“最小补丁”。

### 8.6 BPF_PROG_DUMP / bpftool prog dump 的可读性

内核内的 disasm 目前是固定表：

- class 表：`vendor/linux-framework/kernel/bpf/disasm.c:62-70`
- ALU 字符串表：`vendor/linux-framework/kernel/bpf/disasm.c:73-88`
- 打印逻辑：`vendor/linux-framework/kernel/bpf/disasm.c:208-226`

如果只加功能不加 disasm 支持，那么 `BPF_KINSN` 在 verifier log / 内核 disasm 里要么显示成一个泛化字符串，要么显示不友好。

kfunc 之所以能显示名字，是 verifier 单独加了：

- `disasm_kfunc_name()`：`vendor/linux-framework/kernel/bpf/verifier.c:4163-4177`
- `verbose_insn()` 把 callback 传给 `print_bpf_insn()`：`vendor/linux-framework/kernel/bpf/verifier.c:4179-4188`

`kinsn` 要想有可读名字，也需要一条类似的中心化 disasm hook。

另外，`bpftool` 是 userspace 工具；即便 kernel 内 disasm 修好了，`bpftool` / `libbpf` 的 userspace disassembler 也还需要同步补丁。这一点超出本次“只读 kernel 源码”的分析范围，但在工程上必须考虑。

### 8.7 这个方案的边界

这个方案解决的是：

- ALU64 纯寄存器扩展

它不解决：

- 新内存访问模式
- 新 branch / CFG 原语
- 新 helper ABI / call ABI
- 新多指令复合模板

如果目标是后者，必须重新模块化 `check_mem_access()` / `check_cond_jmp_op()` / JIT branch relocation，这不是“小改动”。

---

## 9. 行数估计

下面给出我认为最合理、最保守的最小实现行数估计。这里不包含可读性增强的 `disasm.c` / userspace `bpftool` 补丁，只算功能最小闭环。

| 文件 | 估计新增/修改行数 | 说明 |
| --- | ---: | --- |
| `vendor/linux-framework/include/uapi/linux/bpf.h` | 4 | 新增 `#define BPF_KINSN 0xe0` 注释和宏 |
| `vendor/linux-framework/include/linux/bpf.h` | 7 | `struct bpf_prog_aux` 新增 `insn_ext_tab` 指针和少量声明 |
| `vendor/linux-framework/include/linux/bpf_insn_ext.h` | 132 | 新增头文件：struct/API/ctx/ops 定义 |
| `vendor/linux-framework/kernel/bpf/insn_ext.c` | 286 | registry、program pinning、lookup、free helper、ops wrapper |
| `vendor/linux-framework/kernel/bpf/verifier.c` | 68 | `check_kinsn_alu64()`、`do_check_insn()` hook、少量日志/包装 |
| `vendor/linux-framework/kernel/bpf/core.c` | 64 | opcode whitelist、interpreter jump table/label、free path |
| `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` | 54 | `emit_kinsn_x86()`、两个 switch case、x86 ops wrapper |
| `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c` | 46 | `emit_kinsn_arm64()`、两个 switch case、arm64 ops wrapper |
| **合计** | **661** | 功能最小闭环 |

若再加两个增强项，额外大约是：

| 额外文件 | 额外行数 | 说明 |
| --- | ---: | --- |
| `vendor/linux-framework/kernel/bpf/disasm.c` | 18 | verifier log / 内核 disasm 显示 `kinsn` 名称 |
| `vendor/linux-framework/kernel/bpf/core.c` | 22 | 二期可选：`K` 形式 constant blinding rewrite |

所以：

- **最小可运行闭环**：约 **661 行**
- **加内核内可读性和 blind rewrite**：约 **701 行**

---

## 最后判断

基于这棵源码树，我的判断是：

- **可行**：如果把目标限定为“`BPF_ALU64` 标量寄存器变换类扩展”，并接受一次性在 verifier/JIT/interpreter/core 里打一个统一的 `kinsn` hook。
- **不可行**：如果目标是“任意 class、任意语义、完全不受 verifier/JIT 内部状态限制的新 opcode 全部 module 化”，那在当前内核代码结构下不是小改动，而是重新拆分 verifier/JIT 架构。

换句话说，本题要的 “module 注册新 BPF 指令机制” 在工程上最合理的版本，不是 “module 获得一整块新 opcode 空间”，而是：

- 内核一次性保留一个 `ALU64` 扩展 dispatcher
- verifier/JIT/interpreter 都只新增这一层固定入口
- 后续新指令只通过 module 注册 `ext_id + callbacks`

这条路和现有 `BPF_ATOMIC` 的二级子 opcode、以及 kfunc 的 program-level module pinning，都是同一种设计风格，因此我认为这是这棵源码上最可落地、最不违和的方案。

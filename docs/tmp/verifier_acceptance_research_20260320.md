# Linux BPF verifier 对重写后 bytecode 的接受度分析（Linux 7.0-rc2）

## 结论先行

如果目标是“在 userspace 重写 eBPF bytecode，再重新提交给 verifier”，8 种 native 优化里可以分成三类：

1. **可以直接用现有 eBPF ISA 表达，并且有现实通过 verifier 的空间**
   - `WIDE_MEM`
   - `BRANCH_FLIP`
   - 一部分“普通 DCE 级别”的 `ZERO_EXT_ELIDE`（不是 JIT 那个内部 `BPF_ZEXT_REG` 版本）

2. **可以用现有 ISA 把 bytecode 重写成更利于 JIT 识别的 canonical pattern，但不能压成更少的 BPF 指令**
   - `ROTATE`
   - `COND_SELECT`
   - `ADDR_CALC`
   - `BITFIELD_EXTRACT`
   - `ENDIAN_FUSION`

3. **如果要真的在 bytecode 层“压缩成新单指令”，需要新增 ISA / verifier 支持**
   - `ROTATE`
   - `ADDR_CALC`
   - `BITFIELD_EXTRACT`
   - `ENDIAN_FUSION`
   - `COND_SELECT` 需要的不是“小补丁”，而是更侵入式的新编码/新状态模型

最重要的 verifier 结论是：

- **verifier 只关心“重写后的程序”本身是否满足内存安全、寄存器类型、CFG、复杂度限制；它不关心你是从哪个原程序重写来的。**
- 因此，某个 native 优化在 bytecode 层是否可行，本质上取决于：
  - 重写后是否仍能用 **现有 verifier 可理解的指令语义** 表达；
  - 重写后是否会改变 verifier 依赖的 **bounds proof / pointer id / alignment / CFG 形状 / state pruning 行为**。

下面的分析基于 `vendor/linux-framework/` 下的 7.0-rc2 源码。

---

## 1. verifier 的核心工作方式

### 1.1 主循环和复杂度计数

`do_check()` 是主验证循环；每执行一条“正在探索的指令”，`env->insn_processed++`，超过 `BPF_COMPLEXITY_LIMIT_INSNS = 1,000,000` 就拒绝（`vendor/linux-framework/kernel/bpf/verifier.c:21200-21273`，`vendor/linux-framework/include/linux/bpf.h:2319`）。

真正的按指令分发不在 `do_check()` 的 switch 里，而在 `do_check_insn()` 的 class 分发链里：

- `ALU/ALU64 -> check_alu_op()`
- `LDX -> check_load_mem()`
- `STX/ST -> check_store_reg()/check_mem_access()`
- `JMP/JMP32 -> check_cond_jmp_op()/check_func_call()/...`
- `LD -> check_ld_abs()/check_ld_imm()`

见 `vendor/linux-framework/kernel/bpf/verifier.c:21032-21198`。

### 1.2 寄存器状态

verifier 的核心状态是 `struct bpf_reg_state`，关键字段包括：

- `type`: 标量 / 各类指针
- `off`: 固定偏移
- `var_off`: tnum 形式的变量偏移/值
- `smin/smax/umin/umax`
- `id`: 用于关联同一来源的包指针 / nullable pointer / linked scalar
- `range`: 对 `PTR_TO_PACKET` 已证明安全的可访问区间

见 `vendor/linux-framework/include/linux/bpf_verifier.h:37-170`。

这决定了：**重写如果改变了寄存器 identity、固定偏移、或值域，verifier 接受度会变。**

### 1.3 内存访问检查

内存访问最终走 `check_mem_access()`，它先做：

1. 访问宽度解析
2. 对齐检查 `check_ptr_alignment()`
3. 根据 pointer type 分发到不同检查
4. packet 指针走 `check_packet_access()`

见：

- `vendor/linux-framework/kernel/bpf/verifier.c:7681-7895`
- `vendor/linux-framework/kernel/bpf/verifier.c:6617-6671`
- `vendor/linux-framework/kernel/bpf/verifier.c:6324-6362`

最关键的一点：**load 宽度变了，bounds 和 alignment 的要求也随之变。**

### 1.4 分支和 packet bounds 传播

对 packet pointer，`if (ptr +/- k <= pkt_end)` 这样的分支会被 `try_match_pkt_pointers()` / `find_good_pkt_pointers()` 识别，并把“安全访问范围”写回同 `id` 的 packet pointer：

- `try_match_pkt_pointers()`: `vendor/linux-framework/kernel/bpf/verifier.c:17235-17335`
- `find_good_pkt_pointers()`: `vendor/linux-framework/kernel/bpf/verifier.c:16575-16651`
- 条件跳转整体处理：`vendor/linux-framework/kernel/bpf/verifier.c:17449-17640`

这意味着：**同样的语义，如果重写后使用了不同 `id` 的 packet 指针，原来的 bounds proof 可能失效。**

### 1.5 CFG 和 pruning

CFG 先由 `check_cfg()` 做静态遍历，要求：

- 所有指令可达
- 不能跳进 `ldimm64` 的中间
- 跳转目标必须合法

见 `vendor/linux-framework/kernel/bpf/verifier.c:18918-19004`。

子程序还要求：

- jump 不能跨 subprog
- 每个 subprog 末尾必须是 `exit` 或 `ja`

见 `vendor/linux-framework/kernel/bpf/verifier.c:3679-3730`。

运行时状态剪枝由 `is_state_visited()` 完成；它按 `insn_idx` 存 explored states，并用 `states_equal()` / `regsafe()` 判断可否剪枝。这里有明显的顺序敏感 heuristics：

- 每个 prune point 上最多保留有限状态
- 非特权程序每个指令位置超过 `BPF_COMPLEXITY_LIMIT_STATES = 64` 个状态后，不再继续保存新状态
- 还受 jump history / checkpoint 启发式影响

见：

- `vendor/linux-framework/kernel/bpf/verifier.c:195-196`
- `vendor/linux-framework/kernel/bpf/verifier.c:20433-20760`
- `vendor/linux-framework/kernel/bpf/verifier.c:20194-20230`
- `vendor/linux-framework/kernel/bpf/verifier.c:19780-19928`

**因此，纯 CFG 重排虽然语义等价，但 verifier 时间和是否触发复杂度上限，确实会受指令顺序影响。**

---

## 2. 八种优化逐项分析

## 2.1 WIDE_MEM

### 现有 ISA 是否能表达

能。eBPF 现有就有 `LDX | MEM | H/W/DW`，所以 byte load 聚合成 `ldxh/ldxw/ldxdw` 本身是合法 raw bytecode。

### verifier 是否接受

**条件接受。** 关键不是“语义上等价”，而是“重写后的访问宽度是否仍满足 verifier 的安全证明”。

实际检查路径：

1. `check_mem_access()` 先按新的访问宽度做对齐检查  
   `vendor/linux-framework/kernel/bpf/verifier.c:7681-7895`
2. 对 packet pointer，`check_packet_access()` 调 `__check_mem_access(off, size, reg->range)`  
   `vendor/linux-framework/kernel/bpf/verifier.c:6324-6362`
3. `__check_mem_access()` 要求 `off >= 0 && off + size <= mem_size`  
   `vendor/linux-framework/kernel/bpf/verifier.c:5833-5865`

### 你给的 packet 例子

如果原程序先证明了 `pkt + 2` 在 `pkt_end` 之内，例如：

```c
r3 = r2;
r3 += 2;
if (r3 > r4) goto err;   // r2 = pkt, r4 = pkt_end
```

那么 fall-through 安全路径上，`find_good_pkt_pointers()` 会把同 `id` 的 base packet pointer 的 `range` 设成 `2`；此时 `ldxh r1,[r2+0]` 会通过，因为 `off=0,size=2,range=2` 满足 `off + size <= range`。

证据链：

- `try_match_pkt_pointers()` 对 `JGT/JLT/JGE/JLE` 的 packet-vs-pkt_end 特判  
  `vendor/linux-framework/kernel/bpf/verifier.c:17235-17335`
- `find_good_pkt_pointers()` 把 `new_range = dst_reg->off` 或 `off+1` 写回同 `id` packet regs  
  `vendor/linux-framework/kernel/bpf/verifier.c:16575-16651`
- `check_packet_access()` 只看当前寄存器的 `range` 和访问宽度  
  `vendor/linux-framework/kernel/bpf/verifier.c:6324-6362`

所以，对你问的这个具体问题，答案是：

- **如果原程序的 bounds check 真的给当前 base packet pointer 证明了至少 2-byte 的连续安全区间，`ldxh [pkt+0]` 会被接受。**
- 但前提是 **重写后仍然用到那个已经被证明过的 packet pointer 或同 `id` 别名**。

### 什么时候 byte load 能过而 wide load 反而不过

两类常见情况：

1. **alignment 更严格**
   - byte access 永远允许
   - `H/W/DW` 会走 `check_pkt_ptr_alignment()` / `check_generic_ptr_alignment()`
   - packet 在 strict path 下按 `NET_IP_ALIGN==2` 规则检查  
     `vendor/linux-framework/kernel/bpf/verifier.c:6558-6615`

2. **原来只证明了逐字节可访问，但没证明足够宽的连续区间**
   - verifier 不会做“语义级推理：两个 byte load 等价于一个 half-word load”
   - 它只看重写后这条 `ldxh` 本身是否满足 `range >= 2`

### 结论

- `WIDE_MEM` 是 **最现实的 bytecode 层优化**。
- 但它不是“凡是语义等价都能过 verifier”；它依赖：
  - 连续范围证明
  - 对齐
  - 使用同一 packet pointer `id`

---

## 2.2 ROTATE

### 现有 ISA 是否能表达

**不能用单条 eBPF 指令表达 rotate。** 现有 ALU opcode 只有 `ADD/SUB/MUL/DIV/OR/AND/LSH/RSH/NEG/MOD/XOR/MOV/ARSH/END`，没有 rotate；`check_alu_op()` 还直接拒绝 `opcode > BPF_END`。

见：

- `vendor/linux-framework/include/uapi/linux/bpf_common.h:29-43`
- `vendor/linux-framework/include/uapi/linux/bpf.h:24-33`
- `vendor/linux-framework/kernel/bpf/verifier.c:16332-16572`
- `vendor/linux-framework/kernel/bpf/disasm.c:73-88`

### 现有 ISA 下能做什么

只能把现有 `lsh/rsh/or` 序列重排成 JIT 更容易识别的 rotate shape，但 **不能压成 1 条 bytecode**。

JIT validator 已经明确接受多种 rotate shape：

- `site_len==4`: in-place rotate
- `site_len==5/6`: 两-copy 或 masked 32-bit rotate

见 `vendor/linux-framework/kernel/bpf/jit_validators.c:1098-1112`。

### 如果新增 `BPF_ROTATE`

如果真的加一个新 bytecode op，verifier 改动是 **小到中等**，但比“加一个 case”多一些。

最少要改：

1. UAPI opcode 定义
2. `check_alu_op()` 允许该 opcode，做 reserved-field / shift-range 检查  
   `vendor/linux-framework/kernel/bpf/verifier.c:16332-16572`
3. `adjust_scalar_min_max_vals()` 定义寄存器效果  
   `vendor/linux-framework/kernel/bpf/verifier.c:16014-16167`
4. `bpf_alu_string[]` / disasm 输出  
   `vendor/linux-framework/kernel/bpf/disasm.c:73-88`

### 寄存器效果怎么定义

最保守且安全的版本：

- pointer operand: 拒绝
- constant input + constant rotate amount: 精确求值
- 其它 scalar 情况：`dst` 仍是 `SCALAR_VALUE`，但内容 `mark_reg_unknown()`

这比“全都 unknown”更好一点，但 precision 较差。

更好的版本是：

- 如果 rotate amount 是常量，按 bit permutation 变换 `var_off`
- `umin/umax` 用 `reg_bounds_sync()` 从新的 `var_off` 近似恢复

我不建议把它仅仅建模成“`mark_reg_unknown(dst)` 完事”，因为 rotate 是纯位重排，不会引入 pointer，也不会突破已知 bitmask；完全抹掉信息会明显损 precision，影响后续 pruning 和条件推理。

### 结论

- **现有 ISA 下：不能压成单条 bytecode。**
- **如果愿意加新 opcode：verifier 集成难度低于 `LEA`/`CMOV`，属于比较容易加的那类。**

---

## 2.3 COND_SELECT

### 现有 ISA 是否能表达

**不能用单条通用 eBPF 指令表达 generic cmov/select。**

原因不是 verifier，而是 **编码不够**：

- 现有 eBPF 单指令只有 `dst/src/imm/off`
- 通用 `select(cond, true_val, false_val)` 至少需要“条件 + 两个候选值”
- eBPF 也没有像 x86 flags 那样的“前一条 compare 产生的隐藏条件码状态”

### 现有 ISA 下能做什么

能做的是把 branch+mov 重排成 JIT 认可的 select shape，但 verifier 仍然只看到普通 CFG。x86 JIT validator 当前接受三种 shape：

- `site_len=2`: guarded update
- `site_len=3`: compact select
- `site_len=4`: diamond select

见 `vendor/linux-framework/kernel/bpf/jit_validators.c:726-750`。

也就是说：

- **如果目标只是“把 bytecode 整形为 JIT 更容易选 cmov 的 shape”**，现有 ISA 足够；
- **如果目标是“把整个 diamond 压成 1 条新 bytecode”**，现有 ISA 不够。

### verifier 接受度

只要仍是合法 CFG，verifier 没有特殊阻碍：

- `check_cfg()` 负责可达性/跳转合法性  
  `vendor/linux-framework/kernel/bpf/verifier.c:18918-19004`
- `check_subprogs()` 禁止跨 subprog jump  
  `vendor/linux-framework/kernel/bpf/verifier.c:3679-3730`
- `check_cond_jmp_op()` 负责分支两边状态分裂  
  `vendor/linux-framework/kernel/bpf/verifier.c:17449-17640`

### 如果强行设计新 `CMOV`

这不是一个“小 verifier patch”：

1. 现有单指令编码装不下完整语义
2. 如果引入“依赖前一条 compare 的 flags”，verifier 就必须跟踪一种新的隐式机器状态
3. 如果引入多源选择指令，则 UAPI/解释器/JIT/disasm/verifier 全都要扩

### 结论

- **作为 CFG 重写或 canonicalization：可行。**
- **作为真正的 bytecode 单指令优化：在当前 eBPF 编码下基本不可行；需要更侵入式 ISA 扩展。**

---

## 2.4 ADDR_CALC

### 现有 ISA 是否能表达

能表达成 canonical 3-insn pattern：

```c
mov dst, index
lsh dst, scale
add dst, base
```

x86 JIT validator 识别的正是这个模式，见 `vendor/linux-framework/kernel/bpf/jit_validators.c:1318-1359`。

### 能否压成更少 BPF 指令

**一般不能。**

原因是现有 `ADD` 只能做 `dst += src/imm`，没有“带 scale 的双输入地址生成”。如果要仿 x86 `lea dst, [base + idx*scale]`，当前 ISA 缺少直接表示。

### 如果新增 `LEA`

最现实的不是“通用三输入 LEA”，而是一个受限形式，例如：

```c
dst = src + (dst << imm)
```

这样正好能把上面的 3-insn pattern 压成 1 条：

- 旧 `dst` 充当 `index`
- `src` 充当 `base`
- `imm` 充当 `scale shift`

### verifier 集成难点

难点不在 scalar 语义，而在 **pointer arithmetic**。

当前 verifier 对 pointer arithmetic 的核心约束是：

- 32-bit pointer arithmetic 禁止
- pointer 只允许 `ADD/SUB`
- bitwise op 禁止
- 其它运算统一拒绝

见 `vendor/linux-framework/kernel/bpf/verifier.c:14841-15081`。

也就是说，今天 verifier 只知道：

- `ptr + scalar`
- `ptr - scalar`

它 **不知道**：

- `ptr + (scalar << imm)`

所以如果想让 `LEA` 作用于 pointer base，就必须给 `adjust_ptr_min_max_vals()` 新增一套“scaled offset”传播规则。这比 `ROTATE/BEXTR` 的 verifier 接入明显更复杂。

### 结论

- **现有 ISA 下：可以整形成 JIT 需要的 3-insn pattern。**
- **如果要压成 1 条 bytecode：需要新指令，而且 verifier 工作量中等偏高。**

---

## 2.5 BITFIELD_EXTRACT

### 现有 ISA 是否能表达

能，用现有 `rsh/and` 或 `and/rsh` 组合表达。

JIT validator 已经接受：

- 64-bit / 32-bit
- in-place 2-insn
- `mov + rsh + and` 的 3-insn

见 `vendor/linux-framework/kernel/bpf/jit_validators.c:1279-1315`。

### 能否压成单条 bytecode

**不能。** 当前 ISA 没有 `bextr`。

### 如果新增 `BEXTR`

这是比较自然的扩展。可以设计成：

```c
dst = extract(src, start, len)
```

编码上完全放得下：

- `dst_reg`: 结果寄存器
- `src_reg`: 源寄存器
- `off` / `imm`: `start` 和 `len`

### verifier 集成难度

中等，且比 `LEA` 简单：

- pointer source: 直接拒绝
- scalar source: 结果仍是 scalar
- 如果 `start/len` 是常量，最起码可以保证：
  - `umin = 0`
  - `umax = (1 << len) - 1`
  - 高位为 0

比完全 `mark_reg_unknown()` 更合理，也不会太难实现。

### 结论

- **现有 ISA 下：能 canonicalize，但不能单指令压缩。**
- **新增 `BEXTR` 是可行的 verifier 扩展，难度中等。**

---

## 2.6 ENDIAN_FUSION

### 现有 ISA 是否能表达

现有 raw bytecode 已经有 endian conversion：`BPF_END`。

- `check_alu_op()` 对 `BPF_END` 做专门校验  
  `vendor/linux-framework/kernel/bpf/verifier.c:16332-16378`
- `adjust_scalar_min_max_vals()` 用 `scalar_byte_swap()` 传播结果  
  `vendor/linux-framework/kernel/bpf/verifier.c:16014-16167`

x86 JIT validator 识别的 fusion 也是：

- `load + BPF_END`
- `BPF_END + store`

见 `vendor/linux-framework/kernel/bpf/jit_validators.c:1362-1491`。

### 能否压成单条 bytecode

**不能。** 当前 ISA 没有“big-endian load/store”单指令。

### 如果新增 fused mem op

比如：

- `LDX | MEMBE | H/W/DW`
- `STX | MEMBE | H/W/DW`

或等价的新 mode/opcode。

verifier 集成相对直接：

- mem safety 仍走 `check_mem_access()`
- load 结果再施加一次 byte swap 语义
- store 时验证写入源寄存器合法即可

这类扩展的难点主要在 ISA 设计和 JIT，不在 verifier 推理。

### 结论

- **现有 ISA 下：可以保留为 `load/store + BPF_END` 的 2-insn pattern。**
- **要压成 1 条 bytecode，需要新 mem opcode/mode；verifier 难度中等偏低。**

---

## 2.7 BRANCH_FLIP

### 现有 ISA 是否能表达

能。这只是：

- 反转 jump 条件
- 交换 taken / fall-through body
- 重新计算 `off`

JIT validator 里 `BRANCH_FLIP` 本来就是基于普通 branch body 的结构分析，见 `vendor/linux-framework/kernel/bpf/jit_validators.c:1498-1765`。

### verifier 是否接受

**通常接受**，前提是重写后 CFG 仍合法：

- jump 目标在范围内  
  `vendor/linux-framework/kernel/bpf/verifier.c:18918-19004`
- 不跨 subprog  
  `vendor/linux-framework/kernel/bpf/verifier.c:3679-3730`
- 不制造 unreachable insn  
  `vendor/linux-framework/kernel/bpf/verifier.c:18918-19004`

### verifier 的探索顺序是否受影响

**会受影响。**

原因很具体：

1. `visit_insn()` 对条件跳转先 push fall-through，再 push branch target  
   `vendor/linux-framework/kernel/bpf/verifier.c:18794-18912`
2. 状态工作栈 `push_stack()` 是 LIFO；因此当前路径会先沿着 fall-through 继续，另一路压栈等待  
   `vendor/linux-framework/kernel/bpf/verifier.c:2081-2148`
3. `is_state_visited()` 的剪枝启发式与 `insn_idx`、jump history、checkpoint 布局强相关  
   `vendor/linux-framework/kernel/bpf/verifier.c:20433-20760`

所以：

- **语义上等价，不代表 verifier 时间完全一样**
- 某些程序里 `BRANCH_FLIP` 可能让 pruning 更早发生，也可能更晚

### 结论

- `BRANCH_FLIP` 是 **完全可做的 bytecode 层重写**。
- 但它的收益主要是 JIT / 后端布局，不是 verifier-friendly 的单向单调优化；它可能改善，也可能恶化 verifier complexity。

---

## 2.8 ZERO_EXT_ELIDE

### 现有 ISA 语义

raw eBPF 里，**大多数 ALU32 操作天然会把结果 zero-extend 到 64 位**：

- `adjust_scalar_min_max_vals()` 末尾对 ALU32 执行 `zext_32_to_64()`（`BPF_END` 例外）  
  `vendor/linux-framework/kernel/bpf/verifier.c:16014-16167`
- `check_alu_op()` 对 `BPF_MOV` 的 32-bit 形式也显式做 `zext_32_to_64()`  
  `vendor/linux-framework/kernel/bpf/verifier.c:16332-16572`

因此，“零扩展”在 raw BPF 里本来就是语义的一部分，**不需要额外 bytecode**。

### 为什么它在内核里又出现了

因为 verifier/JIT 后处理会插入内部专用形式 `BPF_ZEXT_REG(dst)`：

- 宏定义：`vendor/linux-framework/include/linux/filter.h:242-253`
- 插入 pass：`opt_subreg_zext_lo32_rnd_hi32()`  
  `vendor/linux-framework/kernel/bpf/verifier.c:22374-22470`

但这是 **internal special form**，不是用户可提交的通用 raw opcode。

直接证据：

- `BPF_ZEXT_REG` 实际编码是 `BPF_ALU | BPF_MOV | BPF_X` 且 `imm=1`
- 而 `check_alu_op()` 对普通 `mov32 reg, reg` 要求 `imm==0`

所以 raw verifier 会把它当成 “reserved fields” 拒绝：

- 宏定义：`vendor/linux-framework/include/linux/filter.h:242-253`
- 校验逻辑：`vendor/linux-framework/kernel/bpf/verifier.c:16380-16403`

### 结论

- **作为“删除冗余 raw mov32/self-mov”的普通 DCE：可以做，但这是一般优化，不是你们 native `ZERO_EXT_ELIDE` 的那件事。**
- **作为“复用 verifier/JIT 插入的 zext 形式”：不行，不能把 `BPF_ZEXT_REG` 当 raw bytecode 重新提交。**
- 另外，`BPF_JIT_CF_ZERO_EXT_ELIDE` 在工具头里已经是 **deprecated reserved ABI slot**，见 `vendor/linux-framework/tools/include/uapi/linux/bpf.h:1487-1537`。

---

## 3. 新 BPF 指令的 verifier 集成难度

### 3.1 `BPF_ROTATE`

难度：**低到中等**

原因：

- 只作用于 scalar
- 不碰内存
- 不碰 pointer provenance
- 主要改 `check_alu_op()` + `adjust_scalar_min_max_vals()`

这是最适合加新 opcode 的一类。

### 3.2 `BPF_BEXTR`

难度：**中等**

原因：

- 也主要是 scalar-only
- 但为了不损太多 precision，最好保留 `0..(1<<len)-1` 的 bound

### 3.3 fused endian load/store

难度：**中等偏低**

原因：

- mem safety 仍是现有 `check_mem_access()` 路线
- 主要是把“load/store + byte-swap”的寄存器效果合并到单指令语义里

### 3.4 `BPF_LEA`

难度：**中等偏高**

原因：

- scalar case 简单
- 但一旦允许 `pointer base + scaled scalar`，就要扩 `adjust_ptr_min_max_vals()`
- 这会直接碰 pointer bounds、`id`、packet pointer range 这些 verifier 最敏感的逻辑

### 3.5 `BPF_CMOV` / `BPF_SELECT`

难度：**高**

原因：

- 不是 verifier 本身难，而是 **当前 eBPF 单指令编码不自然支持它**
- 需要新增隐藏 flags 语义，或更宽指令格式，或受限特殊形式

### 3.6 “`do_check()` 的 switch 有多少个 case？”

严格说，**`do_check()` 本身没有那个 switch**；指令分发在 `do_check_insn()` 的 if/else 链里，见 `vendor/linux-framework/kernel/bpf/verifier.c:21032-21198`。

所以加新 ALU opcode 的典型工作量不是“在大 switch 里塞个 case”，而是：

1. 让 `check_alu_op()` 接受新 opcode
2. 定义寄存器效果
3. 补 disasm/JIT/interpreter/UAPI

对 `ROTATE/BEXTR` 来说，这仍然是相对局部的改动。

---

## 4. 重要 verifier 限制，以及“更短程序是否更容易过”

### 4.1 原始指令数限制

`bpf(BPF_PROG_LOAD)` 时：

- 特权：最多 `BPF_COMPLEXITY_LIMIT_INSNS = 1,000,000`
- 非特权：最多 `BPF_MAXINSNS = 4096`

见：

- `vendor/linux-framework/kernel/bpf/syscall.c:2929-2935`
- `vendor/linux-framework/include/linux/bpf.h:2319`
- `vendor/linux-framework/include/uapi/linux/bpf_common.h:54`

### 4.2 验证过程复杂度

- `env->insn_processed` 上限：1,000,000  
  `vendor/linux-framework/kernel/bpf/verifier.c:21223-21229`
- 非特权每个 insn 位置最多保留 `64` 个 explored states  
  `vendor/linux-framework/kernel/bpf/verifier.c:195-196, 20734-20741`
- jump 序列栈深限制 `BPF_COMPLEXITY_LIMIT_JMP_SEQ = 8192`  
  `vendor/linux-framework/kernel/bpf/verifier.c:195, 2122-2148`

### 4.3 栈深限制

- `MAX_BPF_STACK = 512` bytes  
  `vendor/linux-framework/include/linux/filter.h:98-99`
- verifier 会检查 combined stack depth / subprog stack depth  
  `vendor/linux-framework/kernel/bpf/verifier.c:6719-6784`

### 4.4 更短/更简单是否更容易通过

**通常是，但不是无条件。**

更短程序一般会降低：

- `attr->insn_cnt`
- `env->insn_processed`
- CFG 规模
- explored state 数量

这对 verifier 是正向的。

但也有两类反例：

1. **访问变宽**
   - 例如 `WIDE_MEM` 把两个 `ldxb` 变成一个 `ldxh`
   - 字节码更短，但 bounds/alignment 更严格，可能反而被拒绝

2. **CFG 顺序变化**
   - 例如 `BRANCH_FLIP`
   - 语义相同，但 pruning 次序变化，可能更好也可能更差

所以更准确的说法是：

- **“控制流和算术更短”通常更 verifier-friendly**
- **“内存访问更宽”不一定**

---

## 5. xlated bytecode 与原始 bytecode 的差异

这是你们方案里非常关键的一点。

## 5.1 verifier 之后还会继续改程序

`bpf_check()` 的顺序是：

1. `do_check_main()` / `do_check_subprogs()`
2. `check_max_stack_depth()`
3. 然后才开始 instruction rewrites
4. `convert_ctx_accesses()`
5. `do_misc_fixups()`
6. `opt_subreg_zext_lo32_rnd_hi32()`
7. `fixup_call_args()`

源码明确写了：

> instruction rewrites happen after this point

见 `vendor/linux-framework/kernel/bpf/verifier.c:26052-26112`。

### 5.2 `convert_ctx_accesses()` 会改什么

它会：

- 插入 prologue/epilogue
- 插入 `BPF_ST_NOSPEC`
- 把窄的 ctx load 扩成更宽的 load，再补 `rsh/and`
- 把某些访问改成 `BPF_PROBE_MEM*`
- 对 `BPF_MEMSX` 追加 sign-extend `mov`

见 `vendor/linux-framework/kernel/bpf/verifier.c:22480-22778`。

这意味着：

- **你读到的 xlated 不一定还是原始 ctx access 的字节码**
- 直接重新提交，verifier 看到的是“已经被内核 lower 过的版本”，接受性未必相同

### 5.3 `do_misc_fixups()` 还会继续改

它会做很多后处理，例如：

- 替换部分 div/mod corner case
- `LD_ABS/LD_IND` lower
- pointer speculation mitigation
- arena / probe / tail call / call args 相关 fixup

见 `vendor/linux-framework/kernel/bpf/verifier.c:23355-24313`。

### 5.4 `xlated` dump 不是“原始用户 bytecode”

`bpf_prog_get_info_by_fd()` 导出的 `xlated_prog_insns` 来自当前 `prog->insnsi`，也就是 **已经过 verifier 后续 rewrite 的程序**：

- `vendor/linux-framework/kernel/bpf/syscall.c:5066-5079`

另外，如果程序已经被 blinding，且调用方没有 raw dump 权限，内核会直接把 `info.xlated_prog_insns` 置 0，不返回指令数组：

- `vendor/linux-framework/kernel/bpf/syscall.c:5066-5084`

`bpf_insn_prepare_dump()` 只会把一部分 internal opcode “清洗”回更像 raw 的形式，例如：

- `BPF_TAIL_CALL -> BPF_CALL`
- `BPF_CALL_ARGS -> BPF_CALL`
- `BPF_PROBE_MEM* -> BPF_MEM`

见 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4958`。

但它 **不会把所有 internal form 都还原**，尤其是 `BPF_ZEXT_REG` 这类形式。

### 5.5 能否直接拿 xlated 重新提交

**结论：不能假设可以。**

原因至少有三层：

1. `xlated` 已经不是原始 verifier 输入
2. dump 只还原了部分 internal opcode
3. 某些 internal form 重新提交会被 raw verifier 拒绝

最明确的例子就是 `BPF_ZEXT_REG`：

- 宏：`vendor/linux-framework/include/linux/filter.h:242-253`
- raw verifier 对同编码要求 `imm==0`，否则 `reserved fields`  
  `vendor/linux-framework/kernel/bpf/verifier.c:16380-16403`

因此：

- **如果你们读取的是 xlated bytecode，不能直接当成新的 raw 输入重新提交。**
- **必须做“反向还原”或自己维护一份 raw-bytecode 级 IR。**

### 5.6 constant blinding 在哪发生

constant blinding 不在 verifier 里，而在 runtime/JIT 选择阶段：

- `bpf_check()` 之后才到 `bpf_prog_select_runtime()`  
  `vendor/linux-framework/kernel/bpf/syscall.c:3090-3094`
- `bpf_prog_select_runtime()` 注释明确说 JIT 可能因 constant blinding 重写程序  
  `vendor/linux-framework/kernel/bpf/core.c:2588-2635`

所以：

- **constant blinding 不是 verifier 接受性问题**
- 它不会解释 raw verifier 的接受/拒绝

---

## 6. 对 8 个优化的最终判断

| 优化 | 现有 ISA 可否表达 | 能否压成更少 BPF 指令 | verifier 风险点 | 总结 |
| --- | --- | --- | --- | --- |
| `WIDE_MEM` | 可以 | 可以 | bounds、alignment、packet pointer `id/range` | 最可做 |
| `ROTATE` | 只能保留 shift/or pattern | 不能 | 无单指令 rotate | 需新 opcode 才能真正压缩 |
| `COND_SELECT` | 可以保留 branch+mov shape | 不能 | CFG/pruning 顺序 | 只能 canonicalize，单指令化不现实 |
| `ADDR_CALC` | 可以保留 `mov+lsh+add` | 通常不能 | scaled pointer arithmetic | 新 `LEA` 可做，但 verifier 成本不低 |
| `BITFIELD_EXTRACT` | 可以保留 `rsh+and` | 不能 | precision 传播 | 新 `BEXTR` 值得考虑 |
| `ENDIAN_FUSION` | 可以保留 `load/store + BPF_END` | 不能 | 无 fused mem op | 新 endian mem op 可做 |
| `BRANCH_FLIP` | 可以 | N/A | pruning 次序 | 纯 CFG 重排，可做 |
| `ZERO_EXT_ELIDE` | raw 语义已内建 zext | 一般不是这个层面的问题 | `BPF_ZEXT_REG` 不能重提 | 不应把 internal zext 当 raw 优化目标 |

---

## 7. 建议

如果你们要做“userspace 重写 raw BPF bytecode，再交给原生 verifier”，优先级建议是：

1. **优先做 `WIDE_MEM`**
   - 这是唯一既能减少 BPF 指令数、又已有现成 ISA 的核心优化
   - 但实现时必须保守处理 packet bounds / alignment / pointer `id`

2. **把 `BRANCH_FLIP` 视为可选 CFG 优化**
   - 它 verifier-safe，但收益不稳定
   - 需要实测 verifier 时间和 `states_per_insn`

3. **其余几项先做“canonicalization to JIT-recognized pattern”，不要急着追求新单指令**
   - `ROTATE`
   - `COND_SELECT`
   - `ADDR_CALC`
   - `BITFIELD_EXTRACT`
   - `ENDIAN_FUSION`

4. **如果真要扩 ISA，优先考虑 `ROTATE` 和 `BEXTR`**
   - verifier 接入最局部
   - 不碰 pointer semantics

5. **不要把 xlated dump 当成稳定可重提交 IR**
   - 最好维护自己的 raw-bytecode IR
   - 或者只对自己生成/保存的 raw insns 做重写

---

## 8. 一句话回答你最关心的问题

**在当前 Linux 7.0-rc2 verifier 下，真正适合“userspace 直接改 raw BPF bytecode 再重提”的核心优化只有 `WIDE_MEM` 和 `BRANCH_FLIP`；其余大多最多只能做 pattern canonicalization，想压成新单指令则需要新增 ISA，其中 `ROTATE/BEXTR` 好加，`LEA` 次之，`CMOV/SELECT` 最难。**

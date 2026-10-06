# Verifier-Assisted Constant Propagation + DCE 设计报告

日期：2026-03-24  
关联任务：#424、#443、#423、#398、#457  
上游上下文：`docs/kernel-jit-optimization-plan.md`、`docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md` Part 2

## 0. 结论先行

结论很明确：

1. **#424 值得做，而且应该先做 exact-scalar 版本。**
   - `docs/kernel-jit-optimization-plan.md` 已把 verifier-assisted const propagation 定义为“`log_level=2` → 识别常量 → `MOV reg, const` → DCE”的核心 runtime specialization 路线。
   - 前一份报告已经证明 consumer side 很大：归档 log 的保守下界里，约 `23%` 的 state line 含精确常量；静态 corpus 里 `62.54%` 的条件分支和立即数比较，`8.05%` 的全部指令是 ALU-immediate。

2. **#443 应该作为 #424/#423 的乘数来做，而不是单独发明一个“全能 DCE”。**
   - kernel verifier 自己已经在 re-verify 之后做 `opt_hard_wire_dead_code_branches()`、`opt_remove_dead_code()`、`opt_remove_nops()`。
   - 所以 userspace DCE 的重点不是复制 kernel 全部逻辑，而是：
     - 让更多条件变成常量；
     - 在 daemon 侧先把 CFG 和死 def 清掉，给后续 pass 留更干净的 IR；
     - 依赖 kernel 作为最后一道 dead-code cleanup backstop。

3. **v1 范围应当收敛到：**
   - exact scalar constant propagation：`tnum mask = 0` 为主；
   - singleton range constant propagation：作为保守补充，但必须和 `var_off`/位宽一致性一起判断；
   - branch folding + unreachable block elimination；
   - dead scalar register def elimination；
   - `fp + const` 栈槽 dead store 只做严格受限版本，放到 v1.5 或 phase 2 更稳。

4. **当前 `daemon/src/verifier_log.rs` 不能直接支撑 #424。**
   - 它现在只适合 failure attribution。
   - 它缺的不只是字段，还缺**语义层**：
     - 没区分 full snapshot vs delta snapshot；
     - 没保留 `var_off`；
     - 没保留 `P` precise 标记；
     - 没保留 `id=` / `ref_obj_id=` / `r=` / `imm=` / stack slots；
     - 最关键的是：**把 `pc: (...) ; R...` 这种附着在指令行尾的状态，误当成该 `pc` 的普通状态**。

5. **真实程序里的 DCE 乘数非常大。**
   - Katran `pktcntr`：`22 -> 2`，可删 `20` 条（`90.9%`）。
   - Tetragon `tg_tp_cgrp_mkdir`：`447 -> 2`，可删 `445` 条（`99.6%`）。
   - Tetragon `tg_tp_cgrp_release`：`352 -> 98`，可删 `254` 条（`72.2%`）。
   - 这些 case 说明 #443 的价值不是“省一两条 MOV”，而是 specialization 之后把整片后继块直接打成 dead。

我的建议是：**先做 parser/fact model 重构 + exact-scalar constprop + CFG DCE v1；不要一上来做 general memory DSE。**

---

## 1. 代码库现状与起点

### 1.1 项目计划里的既定定位

`docs/kernel-jit-optimization-plan.md` 已明确把这条路线写成：

- `Verifier-assisted const propagation`：`log_level=2` 获取 per-insn verifier state（tnum/range）→ 识别运行时常量 → 替换为 `MOV reg, const` → 死代码消除
- `Dead code elimination (DCE)`：const prop / map inlining 后的 unreachable block / dead store 消除，是 specialization 的乘数

对应任务状态：

- `#423 Dynamic map inlining + invalidation`：负责把 runtime-stable map 值物化成常量；
- `#424 Verifier-assisted constant propagation`：负责消费 verifier state；
- `#443 Dead code elimination pass`：负责把常量传播后的 dead CFG 和 dead defs 真正清掉。

因此 #424 和 #443 不应该孤立设计，而应该被视为一条连续链：

`runtime facts (#423/#424) -> branch folding -> DCE (#443) -> later kinsn passes`

### 1.2 仓库里已经有的基础设施

现有基础并不差：

- `daemon/src/bpf.rs` 已支持 `BPF_PROG_REJIT(log_level=2)` 成功路径拿 verifier log。
  - `bpf_prog_rejit()` 现在固定用 `log_level=2` + `16MB` buffer。
  - 这意味着**#424 不需要新增 kernel syscall**，采集路径已经在 daemon 里。
- `daemon/src/verifier_log.rs` 已有一个 parser，但 README 也明确写了它“not yet wired into pipeline”。
- `daemon/src/analysis/cfg.rs`、`daemon/src/analysis/liveness.rs` 已经提供了 DCE v1 所需的两个核心砖块：CFG 和寄存器级 liveness。
- `daemon/src/passes/mod.rs` 有明确的 canonical pass order，可为 #424/#443 加入前置/清理位置。

### 1.3 现有 parser 为什么不够

当前 `daemon/src/verifier_log.rs` 的 `RegState` 只有：

- `reg_type`
- `min_value`
- `max_value`
- `known_value`
- `offset`

对 failure attribution 足够，对 constprop 不够。关键缺口有五类：

1. **缺 program-point 语义**
   - 没区分：
     - full pre-state snapshot
     - delta snapshot
     - instruction line 尾部追加的 state

2. **缺 tnum 结构**
   - 没解析 `var_off=(value; mask)`，因此无法区分：
     - whole-register exact constant
     - partial-known tnum
     - pure range fact
   - 还会把 `min==max` 直接提升成 `known_value`，但没有和 `var_off` 做一致性交叉检查

3. **缺 verifier metadata**
   - `P` precise
   - `id=`
   - `ref_obj_id=`
   - `refs=`
   - `cb` / `async_cb`

4. **缺 pointer-specific 属性**
   - `r=` packet range
   - `imm=`
   - dynptr / iter / map attrs

5. **缺 stack 状态**
   - `fp-8=0000????`
   - spilled pointer state
   - dynptr / iter stack slots

#443 如果要覆盖 dead store，这些 stack facts 迟早要进模型。

---

## 2. Verifier `log_level=2` 输出格式精确解析

这一节只基于 kernel 源码：

- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/log.c`

### 2.1 谁在打印什么

核心调用关系是：

1. `do_check()` 负责 verifier 主循环。
2. `print_verifier_state()` 负责把当前 frame 的寄存器/stack/ref/callback 状态打印成一行。
3. `print_insn_state()` 负责把“上一步 scratch 出来的 state delta”附加到日志里。

关键位置：

- `verifier.c:21791-21797`
  - `do_check()` 在 `BPF_LOG_LEVEL2 && do_print_state` 时打印：
    - `"\nfrom %d to %d%s:"`
    - 然后调用 `print_verifier_state(..., true)`
- `verifier.c:21800-21810`
  - 如果有 scratched state，则先 `print_insn_state(...)`
  - 然后才打印当前指令的：
    - `"%d: "` + disassembly
- `log.c:749-846`
  - `print_verifier_state()` 真正序列化寄存器/stack/ref/callback
- `log.c:854-865`
  - `print_insn_state()` 决定 delta state 是“单独一行”还是“`; ...` 追加到上一条指令行尾”

### 2.2 三种日志形态

从源码看，实际要处理的不是“一个状态格式”，而是三种：

#### A. 完整入口状态

```text
from <prev_pc> to <pc>[: optional speculative suffix]: R0=... R1=... ...
```

例：

```text
from 7 to 10: R0=0 R1=ctx() R10=fp0
from 7 to 10 (speculative execution): R0=...
```

语义：

- 这是 **entry state of `<pc>`**
- 由 `print_verifier_state(..., true)` 打印
- 是 **full snapshot**

#### B. 独立 delta 行

```text
<pc>: R0=... R1=... ...
```

语义：

- 这是由 `print_insn_state()` 打印的 **current state delta**
- `print_verifier_state(..., false)`，所以它只包含 scratched regs / stack slots
- 语义上它是**当前 iteration 的状态**，即当前即将验证的 PC 的入口状态
- 它不是 full snapshot

#### C. 指令行尾部追加 delta

```text
<displayed_pc>: (opcode ...) ... ; R0=... R1=...
```

注意：这个形式最容易被误解。

`print_insn_state()` 的实现是：

- 如果日志光标还停在上一条 disasm 的结尾，就回退一个字符；
- 然后直接追加 `";"`；
- 再打印 `print_verifier_state(..., false)`。

这意味着：

- **`; R...` 不是 `displayed_pc` 的 full pre-state**
- 它是“下一轮 verifier 当前状态”的 delta，只是为了可读性被物理追加到上一条指令行后面
- 对直线控制流来说，它更接近“执行完 `displayed_pc` 之后的状态”
- 对 branch path 来说，它本质上是“下一条被探索路径的入口 delta”

这就是为什么当前 parser 把：

```text
6: (71) r3 = *(u8 *)(r2 +0) ; R3=scalar(...)
```

简单记成“`pc=6` 的状态”在语义上是不严谨的。

### 2.3 `print_verifier_state()` 的 token 组成

它输出的是一个单行 token 流，大致可写成：

```text
[frameN:] {Rk=reg_state}* {fp-offset=stack_state}* [refs=id[,id...]] [cb] [async_cb]
```

更具体一点：

```text
state_line ::=
  [" frame" <frameno> ":"]
  {" R" <regno> "=" <reg_state>}*
  {" fp" <stack_off> "=" <stack_repr>}*
  [" refs=" <id_list>]
  [" cb"]
  [" async_cb"]
```

其中：

- `frameN:` 只有当前 frame 不是 `0` 时才出现；
- `Rk=` token 只打印非 `NOT_INIT` 的寄存器；
- `fp-8=` token 只打印 allocated 且 valid 的 stack slot；
- `refs=` 打印 acquired reference id 列表；
- `cb` / `async_cb` 表示当前在 callback context。

### 2.4 `reg_state` 的精确打印规则

`print_reg_state()` 的规则非常重要：

#### 1. exact scalar constant

如果：

- `reg->type == SCALAR_VALUE`
- 且 `tnum_is_const(reg->var_off)`

那么直接打印：

- `R2=1`
- `R3=0x123456`
- 如果 `precise` 还会有前缀：`R4=P42`

这里**不会打印 `scalar(...)`**。

#### 2. stack pointer / frame pointer

`PTR_TO_STACK` 会打印成：

- `fp0`
- `fp-8`
- `fp[1]-16`

如果 `var_off` 不是常量，则会退回 `fp(...)` 形式。

#### 3. 一般 typed state

否则打印：

```text
<reg_type>(<comma-separated attrs>)
```

可能出现的属性包括：

- `id=<n>`
- `+<off>`（`BPF_ADD_CONST`）
- `ref_obj_id=<n>`
- `non_own_ref`
- `map=<name>,ks=<n>,vs=<n>`
- `off=<fixed_off>`
- `r=<packet_range>`
- `sz=<mem_size>`
- `type=<dynptr_type>`
- `imm=<const_var_off>`（pointer register with fixed var_off）
- scalar range fields：
  - `smin`
  - `smax`
  - `umin`
  - `umax`
  - `smin32`
  - `smax32`
  - `umin32`
  - `umax32`
- `var_off=(value; mask)`

### 2.5 数字格式规则

这部分对 parser 很关键：

1. `tnum_strn()`：
   - `mask == 0` 时直接打印常量值
   - 否则打印 `(value; mask)`

2. 无符号数：
   - `<= U16_MAX` 用十进制
   - 否则用十六进制

3. 有符号数：
   - 在 `[-32768, 32767]` 范围内用十进制
   - 否则用十六进制

4. range 会做“相等值压缩”：
   - 例如：
     - `smin=umin=smin32=umin32=0`
     - `smax=umax=smax32=umax32=255`

5. `print_verifier_state(..., false)` 省略所有没被 scratch 的寄存器/stack slot。

因此 parser 必须接受：

- decimal / hex / negative hex 混用
- `a=b=c=0` 这种 chained equality
- full snapshot / sparse delta 混用

同时还必须记住一件事：

- delta line 不是完整状态；
- 如果后续分析想知道“PC 处全体寄存器事实”，就必须把 delta merge 回最近的 full snapshot。

### 2.6 `reg_type` 字符串不是固定小集合

`reg_type_str()` 不只是输出 base type，还会拼前后缀：

- prefix:
  - `rdonly_`
  - `ringbuf_`
  - `user_`
  - `percpu_`
  - `rcu_`
  - `untrusted_`
  - `trusted_`
- base:
  - `scalar`
  - `ctx`
  - `map_ptr`
  - `map_value`
  - `fp`
  - `pkt`
  - `pkt_meta`
  - `pkt_end`
  - `sock`
  - `ptr_<btf_type>`
  - `mem`
  - `func`
  - `map_key`
  - `dynptr_ptr`
  - 等
- postfix:
  - `_or_null`
  - `or_null_`

所以 parser 绝不能把 reg type 假定为少量硬编码字符串。

### 2.7 对 #424 parser 的直接设计要求

建议把 parser 输出升级为：

```text
Snapshot {
  stream_index,
  snapshot_kind: FullEntry | DeltaEntry | AppendedDelta,
  displayed_pc,
  semantic_pc: Option<usize>,
  prev_pc: Option<usize>,
  speculative: bool,
  frame_no,
  regs: HashMap<regno, RichRegState>,
  stack: Vec<StackSlotState>,
  refs: Vec<u32>,
  in_callback: bool,
  in_async_callback: bool,
}
```

其中 `RichRegState` 至少要有：

- `reg_type`
- `precise`
- `var_off_value`
- `var_off_mask`
- `smin/smax/umin/umax`
- `smin32/smax32/umin32/umax32`
- `id`
- `ref_obj_id`
- `fixed_off`
- `packet_range`
- `imm`

v1 constprop 至少要消费：

- `reg_type`
- `precise`
- `var_off`
- 64/32-bit ranges
- `id/ref_obj_id`
- 以及“这是不是 full snapshot”的标记

v1.5 stack dead-store DSE 还要消费：

- `fp` slot types
- spilled pointer states

---

## 3. 哪些常量状态可利用

这一节的核心不是“哪些东西看起来像常量”，而是“哪些事实可以安全降成 bytecode rewrite”。

### 3.1 一级：whole-register exact scalar constant

判定标准：

- kernel 真实语义是：
  - `type == SCALAR_VALUE`
  - `tnum_is_const(var_off)`
- 日志表现通常是：
  - `R2=1`
  - `R3=P42`
  - `R4=-1`

这类事实是 **#424 v1 的主战场**。

可直接支持的 rewrite：

- `MOV reg, imm`
- compare folding：
  - `if rX == imm`
  - `if rX != imm`
  - `if rX < imm`
  - `if rX > imm`
- immediate ALU simplification：
  - `rX &= imm`
  - `rX |= imm`
  - `rX ^= imm`
  - `rX += imm`
  - `rX <<= imm`
- constant branch folding 后触发 DCE

### 3.2 二级：singleton range

日志里可能表现成：

```text
R3=scalar(smin=umin=smin32=umin32=5,smax=umax=smax32=umax32=5)
```

或者 32-bit 范围被锁死。

这类事实**可以利用，但不能比 tnum 更高优先级**。建议规则：

1. 如果 `var_off` 明确存在：
   - 要求它和 singleton range 一致；
   - 不一致则不做 whole-register replacement。

2. 如果只有 range，没有 `var_off`：
   - 可以作为保守 fallback；
   - 但要区分：
     - full 64-bit exact
     - only low-32 exact

3. 如果只知道 32-bit subreg 精确：
   - 优先生成 `BPF_ALU | BPF_MOV | BPF_K`（`wX = imm`）
   - 不要默认升格成 64-bit exact `MOV64`

这类信息适合做：

- `MOV32 imm`
- branch folding
- narrow ALU simplification

### 3.3 三级：partial-known tnum

日志里表现成：

```text
var_off=(0x0; 0xff)
var_off=(0x40; 0xbf)
```

解释：

- `value` 表示已知位模式
- `mask` 表示未知位

这类状态**不能直接改成 `MOV imm`**，因为 whole register 仍然不是常量。

但它非常适合做：

1. bit-test simplification
   - `(rX & mask) == c`
   - `(rX & mask) != c`

2. compare pruning
   - 某些比较已经必真或必假

3. range tightening after local rewrite
   - 如 `rX &= 0xf`、`rX >> 4` 等

建议把 partial-known tnum 放进 #424 phase 2：

- v1：只消费 whole-register exact / singleton
- phase 2：增加 predicate-level simplification

### 3.4 哪些“常量样子”的东西不能直接拿来做 `MOV imm`

以下状态虽然“带固定值/偏移”，但**不是 scalar constant**：

1. typed pointer
   - `pkt(off=14,r=34)`
   - `map_value(off=8,...)`
   - `ctx()`
   - `fp-8`

2. pointer identity / reference state
   - `id=<n>`
   - `ref_obj_id=<n>`

3. packet range facts
   - `r=<n>`

4. dynptr / iter / callback state

这些状态的 value/offset 可用于后续更强的 pointer-aware simplification，但**不能被 whole-register immediate move 替代**。

### 3.5 v1 推荐的常量分类表

| 类别 | 日志症状 | v1 是否消费 | 可做的事 |
| --- | --- | --- | --- |
| Exact scalar | `R2=1` / `R3=P42` | 是 | `MOV imm`、branch fold、ALU fold |
| Singleton 64-bit range | `smin=smax=...` 且与 `var_off` 一致 | 是 | `MOV64 imm`、branch fold |
| Singleton 32-bit range | `smin32=smax32` / `umin32=umax32` | 是，保守 | `MOV32 imm`、branch fold |
| Partial-known tnum | `var_off=(v;mask)`、`mask!=0` | 否，phase 2 | predicate simplification |
| Pointer fixed offset | `pkt(off=14,...)`、`fp-8` | 否 | 仅 pointer-aware future work |
| Ref/callback/stack metadata | `ref_obj_id=...`、`cb` | 否 | 仅合法性 guard |

---

## 4. 替换后 verifier 是否接受

### 4.1 kernel 对 `MOV imm` 的真实语义

`check_alu_op()` 对 `BPF_MOV K` 的处理非常直接：

1. 检查 reserved fields：
   - `src_reg == BPF_REG_0`
   - `off == 0`

2. `mark_reg_unknown(env, regs, dst)`
3. `regs[dst].type = SCALAR_VALUE`
4. 调用：
   - 64-bit：`__mark_reg_known(dst, imm)`
   - 32-bit：`__mark_reg_known(dst, (u32)imm)`

而 `__mark_reg_known()` 会：

- 清掉旧的 pointer/range/map/ref 相关残留状态；
- `id = 0`
- `ref_obj_id = 0`
- `var_off = tnum_const(imm)`
- 同步设置：
  - `smin/smax`
  - `umin/umax`
  - `smin32/smax32`
  - `umin32/umax32`

随后 verifier 判断“这个寄存器是不是常量”的逻辑也是：

- `type == SCALAR_VALUE`
- 且 `tnum_is_const(...)`

所以：

> **只要你把一个“本来就已经是 exact scalar”的值改写成 `MOV imm`，verifier 的抽象状态会被重建成完全一致的 scalar-constant 形状。**

### 4.2 一个安全的 before/after bytecode 形态

可接受的模式是这种：

#### Before

```text
19: r1 = *(u32 *)(r0 + 0)
20: r1 &= 0x2
21: if r1 == 0x0 goto +0x33
```

如果 verifier 在 branch entry state 已经告诉我们：

```text
R1=0
```

那么可以改写成：

#### After (#424)

```text
19: r1 = 0
20: goto +0x33
```

然后再由 #443 做：

#### After (#443)

- `19` 如果不再 live，删掉；
- `21` 的另一侧后继块整片不可达，删掉；
- branch offset 全量重写。

这个 rewrite 对 verifier 是安全的，因为：

- `r1` 在原程序中已被证明是 exact scalar `0`；
- rewrite 后 `r1` 仍然是 exact scalar `0`；
- 所有后续 use 都只依赖 scalar value，而不依赖 pointer identity / packet range / ref state。

### 4.3 一个会被 verifier 拒绝的反例

这种就不安全：

#### Before

```text
10: r2 = r1
11: r2 += 14
12: r3 = *(u8 *)(r2 + 0)
```

verifier 可能看到的是：

```text
R2=pkt(off=14,r=34)
```

如果错误地改成：

#### Bad After

```text
10: r2 = 14
12: r3 = *(u8 *)(r2 + 0)
```

那么 rewrite 后：

- `R2` 变成了 `SCALAR_VALUE`
- 不再是 `PTR_TO_PACKET`
- 后续 packet load 会被 verifier 直接拒绝

所以 #424 的 legality rule 必须写死：

> **只替换 scalar-producing slice，不替换 pointer-producing slice。**

### 4.4 v1 的合法性边界

建议 v1 rewrite legality 规则如下：

1. 目标寄存器在消费点必须被 verifier 证明为 exact scalar 或 singleton scalar。
2. 回溯的定义链只能包含：
   - scalar ALU
   - scalar MOV
   - scalar load
   - 不产生 side effect 的纯计算
3. 不能跨越：
   - helper call
   - kfunc call
   - map update/delete
   - packet pointer derivation
   - pointer copy / pointer arithmetic
   - ref acquisition / release
4. 如果 only-32-bit exact，则生成 `MOV32`，不要强行发 `MOV64`。
5. rewrite 后必须再走正常 REJIT + verifier；失败就按 #397 的 rollback 机制回退。

---

## 5. DCE pass 算法设计

### 5.1 目标与非目标

**v1 目标：**

1. unreachable block elimination
2. dead conditional branch folding
3. dead scalar register def elimination
4. 非常保守的 stack dead store elimination（可选）

**v1 非目标：**

1. general memory DSE
2. helper side-effect reordering
3. pointer SSA / alias analysis
4. 跨 subprog 的 aggressive slicing

### 5.2 为什么不做“大而全”的 DCE

两个现实约束：

1. daemon 当前分析能力有限
   - `cfg.rs` 有 basic block / preds / succs
   - 没 dominator / post-dominator / SSA
   - 没 memory graph
   - `liveness.rs` 只有 register-level dataflow

2. kernel 自己已经会做 dead-code cleanup
   - `opt_hard_wire_dead_code_branches()`
   - `opt_remove_dead_code()`
   - `opt_remove_nops()`

因此最划算的工程切法是：

- daemon 先做“高确定性、低风险”的 CFG simplification；
- kernel 负责最后的 canonical cleanup。

### 5.3 DCE v1 总流程

建议的 pass 结构是：

```text
VerifierConstPropPass
  -> DceSimplifyCfgPass
```

其中 `DceSimplifyCfgPass` 的算法分七步：

#### Step 1. 建立可消费的 verifier facts

输入：

- `Snapshot` 流
- 当前 bytecode

输出：

- `FactAtPc`：
  - per-PC entry exact scalar facts
  - singleton range facts
  - optional partial tnum facts

建议 v1 只信：

- full entry snapshots
- 语义明确的 delta entry snapshots

对附着在指令行尾的 appended delta，v1 可以先不用，或者只作为 debug/reference，不直接驱动 rewrite。

#### Step 2. 做 local constprop / compare simplification

对每个基本块内指令：

- 用 fact 替换 pure scalar-def slice 为 `MOV imm`
- 计算 branch predicate 是否恒真/恒假
- 计算 ALU immediate 是否可折叠

rewrite 结果可分三类：

1. `JEQ/JNE/JLT/... -> JA`
2. `JEQ/JNE/JLT/... -> NOP/fallthrough`
3. `ALU chain -> MOV imm`

#### Step 3. 重建 CFG

因为 branch 目标可能变化，所以必须重新跑 CFG：

- basic block boundaries
- preds / succs
- subprog boundaries

`daemon/src/analysis/cfg.rs` 目前能做基础版，但建议补两点：

1. 更明确地区分 subprog entry / fallthrough edges
2. 处理 rewrite 后 branch-target remap

#### Step 4. Reachability 分析

从每个 subprog entry 出发 DFS/BFS：

- 标记 reachable blocks
- 未命中的 block 直接进入 dead set

这是 `unreachable block elimination` 的主体。

#### Step 5. 物理删除 unreachable blocks

对 dead blocks：

- 删除整块指令
- 统一重写剩余 branch offsets
- 保证 `ldimm64` 二联指令不会被拆裂

这一步在 daemon 做的价值有三个：

1. 后续 passes 看到更干净的 CFG
2. transform trace 更可解释
3. verifier 工作量和日志体积更小

但即便这里有漏网之鱼，kernel 的 dead-code cleanup 仍是 backstop。

#### Step 6. Dead scalar register def elimination

这里直接建立在 `liveness.rs` 上：

如果一条指令满足：

- 只定义 scalar register
- 没 side effect
- 定义结果不在 `live_out`

则可删。

典型可删对象：

- `MOV imm`
- dead ALU op
- dead `LDX` scalar load
- dead `LDIMM64` constant materialization

典型不可删对象：

- helper/kfunc call
- `ST` / `STX`（除非进入 stack dead-store 子算法）
- branch / exit
- map update/delete

#### Step 7. 可选：严格受限的 stack dead store elimination

建议 v1.5 再做，算法只覆盖：

1. 目的地址必须是 `r10 + const`
2. 不允许 alias：
   - 任何 `rX = r10` 再逃逸都当 barrier
3. 只处理 fixed-offset、fixed-width、同 frame 的 stack slot
4. 只删“后写完全覆盖前写，且中间无读”的 store
5. helper/call/pseudo-call 直接当 barrier

如果满足以下模式：

```text
stx [fp-8] = r1
...
stx [fp-8] = r2
```

并且中间对 `[fp-8]` 没有任何 read，也没有 alias/barrier，那么前一个 store 可删。

### 5.4 建议的 side-effect / barrier 分类

为了让 DCE legality 简单，建议先做一个每条指令的 `EffectKind`：

- `PureScalar`
- `ReadsMemory`
- `WritesStack`
- `WritesMemory`
- `Call`
- `Branch`
- `Exit`

v1 只对 `PureScalar` 做 dead-def 删除。  
stack DSE 再单独处理 `WritesStack`。

### 5.5 和 kernel 内建 dead-code cleanup 的关系

这件事必须说清楚，否则 #443 会被做成重复劳动。

kernel 在 privileged verifier 成功后，已经会依次执行：

1. `opt_hard_wire_dead_code_branches()`
2. `opt_remove_dead_code()`
3. `opt_remove_nops()`

这意味着：

- **branch folding 本身的“最终死代码删除”不是 userspace 必须独占完成的事**
- daemon 侧 DCE 的价值更偏向：
  - 为后续 pass 暴露更大 pattern surface
  - 减少 rewrite 后 bytecode 噪声
  - 提高 transform observability

因此 #443 的成功标准不应定义为“彻底复制 kernel DCE”，而应定义为：

> **在 daemon 中尽可能早地把 specialization 暴露出来，并把明显 dead 的块和 def 清掉。**

---

## 6. 和其他 pass 的交互顺序

当前默认 pipeline 是：

```text
wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip
```

`speculation_barrier` 是 opt-in。

### 6.1 推荐的新顺序

建议改成：

```text
map specialization / other runtime fact materialization
-> verifier_constprop
-> dce_simplifycfg
-> wide_mem
-> rotate
-> cond_select
-> extract
-> endian_fusion
-> dce_simplifycfg_cleanup
-> branch_flip
-> speculation_barrier
```

### 6.2 为什么 constprop + DCE 要放最前

原因有四个：

1. **verifier facts只对“当前 bytecode 版本”成立**
   - 先做 `wide_mem/rotate/...` 会改变 CFG 和 def-use
   - 旧 verifier log 不再对新 bytecode 对位

2. **constprop/DCE 会把大量 branch 直接删掉**
   - 后面的 pattern pass 会更简单
   - matching surface 更干净

3. **`cond_select` 不该先吃掉本来就能折叠成常量的 branch**
   - 常量 branch 先删，比改成 select 更好

4. **`branch_flip` 必须在 dead edge 清理之后**
   - 否则 hot/cold bias 会被已经确定 dead 的边污染

### 6.3 为什么建议再跑一次 cleanup DCE

后面的 pattern passes 也可能制造：

- dead temp register
- dead immediate load
- 简化后的单块空转

因此建议在 `endian_fusion` 后再跑一个轻量 cleanup：

- 不重新读 verifier log
- 只做 local dead scalar def + trivial CFG cleanup

### 6.4 `speculation_barrier` 为什么最后

因为它本质上是安全注入 pass：

- 会引入新的控制相关指令
- 不应再被 aggressive CFG rewrite 干扰

所以它应该最后，或接近最后。

---

## 7. Case Study：corpus 中的真实程序

### 7.1 方法说明

这里的计数方法是：

1. 用 `llvm-nm -S` 取目标程序 symbol size
2. 以 `8B / insn` 换算总指令数
3. 用 `llvm-objdump -dr --no-show-raw-insn` 定位常量 gate 后的 dead region
4. 计数表示的是：
   - **一旦 runtime facts 已被 #423/#424 物化，#443 能吃掉的指令规模**

这几个 case 的重点不是“有没有省掉一条 map lookup”，而是：

> **runtime constant 一旦成立，会不会把大片后继块整体打死。**

### 7.2 主表：v1 可直接受益的三个 case

| 程序 | 触发常量 | 总指令数 | 可删指令 | 可删比例 | 说明 |
| --- | --- | ---: | ---: | ---: | --- |
| `corpus/build/katran/xdp_pktcntr.bpf.o:pktcntr` | `ctl_array[0] == 0` | `22` | `20` | `90.9%` | 计数器开关关闭后，整个计数路径都变成 dead，只剩 `XDP_PASS` |
| `corpus/build/tetragon/bpf_cgroup_mkdir.bpf.o:tg_tp_cgrp_mkdir` | `tg_conf_map[0].tg_cgrp_level == 0` | `447` | `445` | `99.6%` | 入口 config gate 为 0 时，整程序坍缩成 `return 0` |
| `corpus/build/tetragon/bpf_cgroup_release.bpf.o:tg_tp_cgrp_release` | `tg_conf_map[0].loglevel != LOG_TRACE_LEVEL` | `352` | `254` | `72.2%` | map delete side effect 还要保留，但后续 event emission 全部 dead |

### 7.3 Case 1：Katran `pktcntr`

源程序：

```c
flag = bpf_map_lookup_elem(&ctl_array, &ctl_flag_pos);
if (!flag || (*flag == 0))
  return XDP_PASS;

cntr_val = bpf_map_lookup_elem(&cntrs_array, &cntr_pos);
if (cntr_val)
  *cntr_val += 1;
return XDP_PASS;
```

对象级 disassembly 只有 `22` 条指令。  
如果 `ctl_array[0]` 被 specialization 为 `0`：

- null / zero gate 直接恒真；
- `cntrs_array` 更新路径整体不可达；
- 最终只剩：
  - `r0 = 0x2`
  - `exit`

这是最标准的：

`runtime config constant -> branch fold -> whole dead suffix removal`

### 7.4 Case 2：Tetragon `tg_tp_cgrp_mkdir`

源程序一开头就是：

```c
config = map_lookup_elem(&tg_conf_map, &zero);
if (!config || config->tg_cgrp_level == 0)
  return 0;
```

而 `tg_conf_map` 自己在源码里明确注明：

> Set from userspace during startup and environment discovery only, bpf part is read-only.

这是非常典型的 runtime-stable config map。

对象级统计：

- symbol size：`0xdf8`
- 总指令数：`3576 / 8 = 447`

当 `tg_cgrp_level == 0` 时：

- 整个后继 cgroup tracking / heap init / event path 都不可达；
- 程序实质上退化成 `return 0`。

这是 DCE 乘数最强的样例之一。

### 7.5 Case 3：Tetragon `tg_tp_cgrp_release`

源代码关键 gate：

```c
map_delete_elem(&tg_cgrps_tracking_map, &cgrpid);

conf = map_lookup_elem(&tg_conf_map, &zero);
if (!conf)
  return 0;

if (unlikely(conf->loglevel == LOG_TRACE_LEVEL))
  send_cgrp_event(...);

return 0;
```

这里和 `mkdir` 不同：

- `map_delete_elem()` 是 side effect，不能被删；
- 所以程序不会坍缩到 2 条指令；
- 但 event emission 大尾巴可以整片砍掉。

对象级统计：

- symbol size：`0xb00`
- 总指令数：`2816 / 8 = 352`
- 从 `pc=98` 到函数结尾（`pc=351`）共 `254` 条指令

若 `loglevel != LOG_TRACE_LEVEL` 被特化为真：

- `pc=98..351` 整片不可达；
- 可删 `254 / 352 = 72.2%`

这说明 #443 不只是“极端情况下才有效”，即使前面有必须保留的 side effect，它仍然能拿到非常大的删除规模。

### 7.6 扩展 case：NetBird `nb_xdp_prog`（phase 2 上界）

NetBird 主程序有两个 feature gate：

```c
if (*features & flag_feature_dns_fwd) { ... }
if (*features & flag_feature_wg_proxy) { ... }
return XDP_PASS;
```

对象级总长 `118` 条指令。  
若 `nb_features[0] == 0`，理论上最终行为应退化为 `XDP_PASS`。

但这个 case 对 v1 有一个重要提醒：

- 这里很多 packet parse / bounds checks 在 feature test 之前就做了；
- 只靠“branch folding + unreachable block elimination”还不够把整个前缀都删光；
- 想把它压到接近 `2` 条，需要更强的：
  - control-equivalence cleanup
  - 或 backward slicing / early-return normalization

所以 NetBird 更适合作为 **phase 2 upper-bound case**，不应拿来当 v1 交付标准。

### 7.7 与宏观统计的一致性

前一份综合调研已经给出全 corpus 的保守下界：

- `2167` 个 foldable branch
- `2165` 个 dead successor block

其中光 Cilium 的几个热点 section 就有：

- `cilium/bpf_lxc.bpf.o:tc/tail`：`388` 个 dead successor block
- `cilium/bpf_overlay.bpf.o:tc/tail`：`244`
- `cilium/bpf_xdp.bpf.o:xdp/tail`：`205`

所以这三个 case 不是偶然样本，而是和整个 corpus 的 dead-edge density 一致。

---

## 8. 实现复杂度评估

### 8.1 推荐切分

#### Phase A：parser / fact model 重构

工作内容：

- 重写 `verifier_log.rs` 数据结构
- 保留 `var_off` / precise / ids / stack / refs
- 区分 full snapshot / delta snapshot / appended delta
- 为 constprop 提供 `FactAtPc`

复杂度：**medium**

估算：

- `250-400` LOC 主逻辑
- `150-250` LOC 测试

#### Phase B：exact-scalar constprop

工作内容：

- legal slice 识别
- `MOV32/MOV64 imm` rewrite
- compare folding
- branch-to-`JA` / branch-to-fallthrough rewrite

复杂度：**medium**

估算：

- `300-500` LOC 主逻辑
- `150-250` LOC 测试

#### Phase C：DCE v1

工作内容：

- CFG rebuild
- reachability
- block removal
- branch fixup
- dead scalar def elimination

复杂度：**medium-high**

估算：

- `400-700` LOC 主逻辑
- `150-250` LOC 测试

#### Phase D：strict stack dead-store DSE（可后置）

工作内容：

- frame-slot 读写建模
- alias/barrier 规则
- overwrite-before-read 删除

复杂度：**high relative to its incremental value**

估算：

- `200-350` LOC 主逻辑
- `100-200` LOC 测试

### 8.2 总体排期判断

如果只做推荐的 v1：

- parser/facts
- exact scalar constprop
- branch folding
- unreachable block elimination
- dead scalar defs

那么单人实现大约是：

- **1 到 1.5 周的中等强度工程量**

如果把 strict stack DSE 和 partial-known tnum predicate simplification 一起带上：

- **再加约 1 周**

### 8.3 风险点

最大的风险不是 rewrite 本身，而是**fact 对位与 legality**：

1. parser 误解 log program-point 语义
2. 把 partial-known tnum 误当 exact constant
3. 把 pointer state 误降成 scalar `MOV imm`
4. 32-bit exact / 64-bit exact 混淆
5. appended delta state 的 semantic PC 对位错误

这些风险都比“怎么删 unreachable block”更危险。

---

## 9. 建议的落地顺序

### 9.1 v1 交付范围

建议 #424/#443 的第一版明确限定为：

1. parser 重构，保留完整 verifier state
2. 只消费：
   - exact scalar
   - singleton scalar range
3. 只做：
   - `MOV imm`
   - compare/branch folding
   - unreachable block elimination
   - dead scalar reg def elimination
4. 依赖 kernel verifier 继续做最终 dead-code cleanup

### 9.2 先不做的内容

第一版不要做：

1. general memory dead store elimination
2. pointer-aware constprop
3. partial-known tnum whole-reg replacement
4. NetBird 这类需要更强控制等价归约的 phase-2 case

### 9.3 推荐实现顺序

1. 重写 `verifier_log.rs`
2. 增加 `FactAtPc`
3. 实现 `VerifierConstPropPass`
4. 实现 `DceSimplifyCfgPass`
5. 接到 pipeline 最前 + cleanup 位
6. 先在 corpus 做静态对象 case 回归
7. 再用 #398 的 verifier-diff 方案做 pass guardrail

---

## 10. 最终判断

我对 #424/#443 的判断是：

- **优先级：high**
- **可行性：high**
- **工程风险：medium**
- **最值得先做的版本：exact scalar + CFG DCE v1**

真正应该避免的是两种错误方向：

1. 把 #424 做成“任何看起来像常量都强行 `MOV imm`”  
   这会踩 verifier type system。

2. 把 #443 做成“从第一天起就做 general memory DSE”  
   这会让实现复杂度和 bug surface 膨胀得很快。

正确的落点是：

> **先把 verifier 已经证明的 scalar 常量稳定吃干净，再用一个保守的 CFG DCE 把 specialization 的乘数兑现出来。**

这条路和项目整体 story 也最一致：

- #423 提供 runtime-stable value
- #424 把 verifier facts 显式化
- #443 把 dead path 真正移除

这三者组合起来，才是 BpfReJIT 最像 HotSpot-style runtime specialization 的地方。

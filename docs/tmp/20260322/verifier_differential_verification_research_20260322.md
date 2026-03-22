# BpfReJIT 利用 BPF verifier 做 differential correctness verification 的可行性调研

日期: 2026-03-22

调研输入:

- 项目文档: `docs/kernel-jit-optimization-plan.md`
- daemon 代码: `daemon/src/verifier_log.rs`, `daemon/src/pass.rs`, `daemon/src/passes/*.rs`, `daemon/src/bpf.rs`, `daemon/src/main.rs`
- 本地内核树: `vendor/linux-framework/`
- 外部一手资料:
  - Linux kernel verifier 文档: <https://docs.kernel.org/6.15/bpf/verifier.html>
  - `bpf(2)` man page: <https://man7.org/linux/man-pages/man2/bpf.2.html>
  - K2 (SIGCOMM'21): <https://people.cs.rutgers.edu/~sn624/papers/k2-sigcomm21.pdf>
  - Merlin (ASPLOS'24): <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>
  - EPSO (ASE'25 / arXiv): <https://arxiv.org/abs/2511.15589>
  - Jitterbug / OSDI'20: <https://www.usenix.org/conference/osdi20/presentation/nelson>

## TL;DR

结论先给清楚:

1. **可行，但只能做 heuristic differential checking，不能做 sound correctness proof。**
   - BPF verifier 的抽象域是为 **safety** 设计的单程序抽象解释，不是为 **relational equivalence** 设计的双程序证明器。
   - “REJIT 前后 verifier 状态一致”只能说明两边在 verifier 关心的安全相关抽象事实下看起来一样，**不能推出语义等价**。

2. **三种方案里，方案 B 最值得做。**
   - 方案 A: 能做，但发现问题时程序已经 swap，语义错误窗口已经存在。
   - 方案 B: 工程上最合理，能逐 pass 定位问题，且不需要内核改动。
   - 方案 C: 如果只是复刻 kernel verifier 抽象域，收益不大；如果想做 sound equivalence，又必须做 relational/product abstract interpretation，工程量过大且难跟 kernel 同步。

3. **不同 pass 上，这个 oracle 的有效性差异很大。**
   - `wide_mem`: 信号最强，但仍然不 sound。
   - `extract` / `endian_fusion`: 有一定价值，但对 kfunc lowering 后的语义盲点依然明显。
   - `rotate` / `cond_select`: verifier state diff 很弱，容易漏掉 semantic bug。
   - `branch_flip`: 语义可能等价，但 verifier 路径/剪枝/状态打印很容易不同，false positive 风险最高。

4. **最可信的落地方式不是“verifier-only correctness verification”，而是“两层机制”。**
   - 第一层: **方案 B** 做 per-pass verifier-diff，作为在线、低门槛、post-load 特有的异常检测。
   - 第二层: 对高风险 pass（特别是 `rotate` / `cond_select` / `extract` / `endian_fusion`）增加 **本地 translation validation**，例如 peephole 级 bitvector/SMT 证明。

5. **对论文表述要收敛。**
   - 可以说: “BpfReJIT leverages the kernel verifier as a lightweight differential abstract interpreter to detect suspicious semantic drift.”
   - 不应说: “BpfReJIT proves pass correctness via the verifier.”

## 1. 背景和问题重述

`docs/kernel-jit-optimization-plan.md` 已经把 BpfReJIT 的设计边界说得很清楚:

- kernel verifier 保证 **safety**
- daemon 负责 **correctness**

问题在于:

- 一个变换可以 **通过 verifier**
- 但仍然 **改变程序语义**

典型例子:

- `rotate` 把操作数顺序写反
- `cond_select` 的 true/false 值交换错
- `wide_mem` 把 load 的 offset 或 byte order 搞错

这些错误未必改变:

- register type
- scalar signed/unsigned range
- pointer kind
- stack initializedness

因此 verifier 通过 != 语义正确。

用户现在提出的核心想法是:

- 对原始 bytecode 和变换后 bytecode 各跑一次 verifier
- 对比 verifier 抽象状态
- 把“抽象状态无差异”作为一种 differential correctness signal

这个想法 **值得做**，但必须先把它的理论上限说清楚。

## 2. 理论边界: verifier diff 为什么天然不是 correctness proof

### 2.1 verifier 是 unary abstract interpretation，不是 relational verification

kernel verifier 计算的是单程序抽象状态:

- 给定程序 `P`
- 沿 CFG 做抽象解释
- 在每个 explored PC 上维护 `struct bpf_reg_state`、stack state、ref state 等

它回答的问题是:

- “`P` 是否安全?”

而 differential correctness 需要回答的问题是:

- “`P` 和 `P'` 是否对所有输入都产生相同语义?”

这是一个 **relational** 问题。

把两个单程序抽象解释结果并排比较:

- `Abs(P)`
- `Abs(P')`

并不能替代 product program / relational abstract interpretation / translation validation。

### 2.2 为什么“状态相同”不推出语义相同

因为 verifier 抽象域故意很粗。

例如一个寄存器都被抽象成:

- `SCALAR_VALUE`
- `umin=0`
- `umax=2^64-1`

则大量不同 concrete 函数都落在同一个抽象元素里。

具体到 BpfReJIT:

- `rotate(x, 8)` 和 `rotate(x, 16)` 都可能只是 “某个 scalar”
- `select(a, b, cond)` 和 `select(b, a, cond)` 也都可能只是 “某个 scalar”
- `*(u32 *)(pkt + 0)` 和 `*(u32 *)(pkt + 1)` 也都可能只是 “0..2^32-1 的 scalar”

因此:

- **false negative** 必然存在
- 所以它对 correctness **不 sound**

### 2.3 为什么“状态不同”也不推出语义不同

verifier 状态里含有大量 **proof artifact**，不是最终语义本身:

- packet pointer `id`
- proved range `r`
- path-sensitive branch constraints
- liveness-sensitive state pruning
- kfunc call 对 `R1-R5` 的 clobber 语义
- log 中同一 PC 的多个路径状态

两个语义等价程序只要:

- CFG 形状不同
- state pruning 次序不同
- dead tmp reg 的值不同
- call/no-call 结构不同

就可能产生不同 verifier state。

因此:

- **false positive** 也必然存在
- 所以它对 equivalence **不 complete**

### 2.4 正确的定位

最准确的定位是:

> verifier differential checking 是一个 **cheap, kernel-native, online abstract-drift detector**，
> 不是 formal equivalence proof。

这个定位在系统上是成立的，而且很有价值。

## 3. verifier 到底追踪什么

### 3.1 kernel verifier 的抽象状态

本地内核树里，核心抽象状态在 `vendor/linux-framework/include/linux/bpf_verifier.h` 的 `struct bpf_reg_state`、`struct bpf_func_state`、`struct bpf_verifier_state`。

verifier 追踪的关键信息包括:

- **寄存器类型**
  - `SCALAR_VALUE`
  - `PTR_TO_CTX`
  - `CONST_PTR_TO_MAP`
  - `PTR_TO_MAP_VALUE`
  - `PTR_TO_STACK`
  - `PTR_TO_PACKET`
  - `PTR_TO_PACKET_END`
  - socket / dynptr / iter / BTF pointer 等
- **固定偏移**
  - `off`
- **变量偏移和值域**
  - `var_off` (`tnum`)
  - `smin/smax/umin/umax`
  - `s32_min/s32_max/u32_min/u32_max`
- **alias / provenance**
  - `id`
  - `ref_obj_id`
  - `frameno`
- **packet pointer 已证明的安全访问范围**
  - `range`
- **stack slot 状态**
  - `STACK_INVALID`
  - `STACK_SPILL`
  - `STACK_MISC`
  - `STACK_ZERO`
  - dynptr / iter / irq 等
- **引用/锁状态**
  - verifier reference tracking
- **路径相关信息**
  - branch split
  - prune checkpoints
  - liveness-cleaned cached states

外部 kernel 文档也明确写了这些高层语义:

- verifier 先做 CFG/DAG 检查，再做路径敏感的抽象执行
- 跟踪 register type、fixed offset、variable offset、signed/unsigned bounds、tnum、packet pointer `id`/range
- pruning 基于 `regsafe()` / `states_equal()`，不是 concrete semantics 本身

参考:

- <https://docs.kernel.org/6.15/bpf/verifier.html>
- 本地源码 `vendor/linux-framework/include/linux/bpf_verifier.h`
- 本地源码 `vendor/linux-framework/kernel/bpf/verifier.c`
- 本地源码 `vendor/linux-framework/kernel/bpf/log.c`

### 3.2 `log_level=2` 暴露的内容

当前 kernel 会在 verifier log 里输出:

- `from <prev> to <pc>: ...`
- `<pc>: R0=... R1=...`
- `<pc>: (insn) ... ; R0=...`
- 可选的 source line / stats

而且 `BPF_LOG_STATS` 会追加:

- `verification time <N> usec`

也就是说:

- **方案 B 完全可以用标准 `BPF_PROG_LOAD` + `log_level=2|BPF_LOG_STATS`**
- 拿到每次 temp load 的 path-sensitive state snapshots 和 verifier 时间

### 3.3 当前 daemon parser 能看到什么，漏掉什么

`daemon/src/verifier_log.rs` 现在的 parser 只保留:

- `pc`
- `regs: HashMap<u8, RegState>`
- `RegState { reg_type, min_value, max_value, known_value, offset }`

它**没有**保留很多对 differential checking 很关键的字段:

- `var_off`
- packet range `r`
- pointer `id`
- `ref_obj_id`
- stack slot state
- spilled reg / frame state
- `refs=...`
- `speculative execution`
- 同一 PC 的多条路径状态之间的 predecessor 区分

这意味着当前 parser 只够做:

- REJIT failure attribution
- 粗粒度 diagnostic

**不够做高置信度 differential comparison。**

### 3.4 “所有 PC 点比较”在工程上其实不成立

即使不考虑抽象域粗糙度，“所有 PC 点比较”本身也不是一个定义良好的对象，因为:

1. 同一 PC 可能有多个路径状态。
2. 变换前后 PC 不一一对应。
3. verifier log 是 exploration trace，不是 canonical fixpoint dump。
4. branch reordering 会改变探索顺序和被打印出的状态集合。

所以工程上真正能比较的是:

- **cutpoint states**
  - 站点入口
  - 站点出口
  - branch merge 点
  - function exit
- 或者
- **mapped state sets**
  - 按 old PC -> new PC 的 address map 比较经过归一化的状态集合

这比“所有 PC 点逐条相等”要现实得多。

## 4. 对各类变换的精度分析

先给总表:

| 变换 | verifier 最可能捕获的差异 | verifier 最容易漏掉的 bug | 实际信号强度 |
| --- | --- | --- | --- |
| `wide_mem` | 访问宽度、对齐、packet range 不足、pointer type 变化 | 相同宽度下的 offset 错误、byte order 错误、读取错字节但范围相同 | 中等偏强 |
| `rotate` | kfunc 不可用、call clobber 导致安全事实变化 | rotate amount 错、参数顺序错、返回值语义错 | 很弱 |
| `cond_select` | CFG 被压平后某些 live reg / type 约束变化 | true/false 值交换错、条件方向错但仍是 scalar | 很弱 |
| `extract` | 一些 scalar range 变化、call clobber | start 错但 bit-length 相同、结果位位置错 | 弱到中等 |
| `endian_fusion` | load width/offset 不合法、pointer proof 不足 | 同宽度下 endianness 错、等范围错误读取 | 弱到中等 |
| `branch_flip` | 非法 CFG、不可反转分支、内部跳转修复错误 | 语义等价但状态打印不同；或 branch body swap bug 但 join state 类似 | 噪声最大 |

下面逐项展开。

### 4.1 `wide_mem`

`wide_mem` 把多次 byte load + shift/or 合并成一次 `LDX H/W/DW`。

verifier 对它最敏感的部分是:

- 访问宽度变大
- 对齐要求更严格
- 对 packet pointer 要求更大的 proved range
- base pointer type 必须仍然合法

所以它确实能抓到一些真实错误:

- 原 byte ladder 每步都能过，但改成 `ldxw` 后对齐不够
- packet bounds 只证明了 2 bytes，却做了 4-byte load
- base pointer 改错导致类型不是可加载内存

但它也会漏掉很多 semantic bug:

- offset 从 `off` 误写成 `off+1`
- 拼装顺序错
- width 相同、range 也足够，但读的是错误字节

因此:

- **比其他 pass 更有用**
- **但仍然不 sound**

另一个关键点是 completeness:

- 原程序有多个 tmp reg 中间态
- 新程序没有
- naive full-state compare 很容易报差异

所以 `wide_mem` 只有在“比较站点出口的 live-out regs + 相关 pointer facts”时才比较合理。

### 4.2 `rotate`

当前 `RotatePass` 是把 shift/or pattern lower 成 `bpf_rotate64()` kfunc call。

从 verifier 视角看:

- 原程序: 一串 scalar ALU
- 新程序: 一个 kfunc call，返回 scalar

只要 kfunc verifier model 比较粗，很多 semantic bug 完全不可见:

- rotate immediate 写错
- 参数顺序交换
- 左旋/右旋搞反

它们都可能在抽象域里仍然只是:

- `Rdst = scalar`

因此:

- **如果 states 相同，完全不能推出 rotate 语义相同**
- soundness 很差

同时 completeness 也很差:

- call 会 clobber `R1-R5`
- intermediate scalar facts消失
- 即使语义等价，抽象状态也很可能不同

### 4.3 `cond_select`

`CondSelectPass` 把 branch+mov diamond 变成 `bpf_select64()` kfunc call。

这是 verifier-diff 最不友好的变换之一，因为它同时改变:

- CFG 形状
- path splitting
- branch constraints
- call/no-call 结构

原程序里 verifier 能看到:

- branch true path 上 `cond == 0` 或 `cond != 0` 的约束
- 两条路径各自的寄存器值

新程序里 verifier 只看到:

- 一个 kfunc 返回 scalar

这会导致两个问题同时存在:

- **false negative**: true/false 参数顺序错也可能看起来都是 scalar
- **false positive**: 语义等价，但 CFG/path-sensitive state 必然变化

所以 `cond_select` 上的 verifier diff 适合做:

- “这个变换是否把明显的 type/range/pointer proof 搞坏了”

不适合做:

- “这个变换是否语义正确”

### 4.4 `extract`

`ExtractPass` 把 `RSH + AND(mask)` 降成 `bpf_extract64()` kfunc。

这个 pass 比 `rotate` 稍微好一点，因为原模式本身会暴露比较明显的范围信息:

- `AND((1 << len) - 1)` 后理论上 `umax = (1 << len) - 1`

如果 kfunc verifier model 也显式给出类似 bound，则差分信号可以比较强。

但在当前框架里，daemon 侧并没有自定义 verifier 抽象语义；最终看到的仍是 kernel 对 kfunc return 的建模。于是:

- `start` 写错但 `len` 没错时，range 可能完全一样
- 结果位位置错，抽象范围仍然一样

因此:

- soundness 仍然不成立
- 但如果后续增强 parser/比较器，把 `umax`、`var_off`、zero-high-bit 这类事实纳入比较，它会比 `rotate` 更有信号

### 4.5 `endian_fusion`

`EndianFusionPass` 把 `LDX + BPF_END` 变成 `bpf_endian_loadXX()` kfunc。

verifier 可能看见的差异:

- load width
- effective address
- pointer legality
- 某些 scalar range/known bit

但最关键的 semantic bug 很容易被漏掉:

- big-endian / little-endian 方向错
- 同宽度、同范围，但字节顺序错

因此:

- 它的 differential signal 主要在 **memory-access legality**
- 不在 **byte permutation correctness**

### 4.6 `branch_flip`

`BranchFlipPass` 是纯 CFG 重排，不引入 kfunc。

这类变换的问题不是抽象域过粗，而是:

- **verifier 本身对路径探索顺序敏感**
- pruning 是基于 checkpoint/state cache 的
- 同一语义程序，仅仅改变 fall-through / taken 布局，就可能改写 exploration trace

所以 `branch_flip` 有两个特性:

1. 它对 semantic bug 依然不 sound。
   - 错误翻转条件、错误交换 body，仍可能在 join 点得到相似抽象状态。
2. 它对 semantic equivalence 也最不 complete。
   - 只是重排布局，就可能让日志状态集合不同。

因此 `branch_flip` 不适合做 strict all-PC diff。
如果要做，只能比较:

- site entry
- merge point
- live-out regs

而不能比较 branch-local 内部状态。

## 5. Soundness / Completeness 结论

### 5.1 总结表

这里的定义是:

- **Sound?**
  - 若 differential checker 判定“无差异/等价”，能否推出语义等价
- **Complete?**
  - 若两个程序语义等价，checker 能否稳定判定“无差异/等价”

| 变换 | Sound? | Complete? | 结论 |
| --- | --- | --- | --- |
| `wide_mem` | 否 | 否 | 最接近可用，但只能做强启发式 |
| `rotate` | 否 | 否 | 对 correctness 几乎不够 |
| `cond_select` | 否 | 否 | 最弱，主要只能抓 safety-related drift |
| `extract` | 否 | 否 | 若增强 range/tnum 比较，实用性可提升 |
| `endian_fusion` | 否 | 否 | 更像 memory-proof checker，不是 endian-proof checker |
| `branch_flip` | 否 | 否 | 语义等价也容易报 diff，噪声最大 |

### 5.2 更细一点的判断

- `wide_mem`
  - soundness: **弱**
  - completeness: **中等偏低**
- `rotate`
  - soundness: **很弱**
  - completeness: **很低**
- `cond_select`
  - soundness: **很弱**
  - completeness: **很低**
- `extract`
  - soundness: **弱**
  - completeness: **低到中等**
- `endian_fusion`
  - soundness: **弱**
  - completeness: **低**
- `branch_flip`
  - soundness: **弱**
  - completeness: **最低**

### 5.3 对论文/系统 claim 的影响

如果论文要写这部分，最稳妥的 claim 是:

- verifier differential checking 提供 **best-effort semantic drift detection**
- 它可以显著降低 bug surfacing latency
- 它能给出 pass-local suspiciousness signal
- 它是 post-load 透明框架特有的一个优势

但不要把它包装成:

- formal correctness verification
- sound translation validation

## 6. 三种方案对比

| 方案 | 描述 | 优点 | 缺点 | 结论 |
| --- | --- | --- | --- | --- |
| A | REJIT 前后各跑一次 verifier，对比原始和最终程序 | 不影响 pass pipeline；实现简单 | 发现问题时程序已 swap；定位粗；回滚晚 | 可做审计层，不宜做主方案 |
| B | 每个 pass 前后都 temp `BPF_PROG_LOAD`，不 attach，不 swap | 最容易定位问题；无错误语义窗口；无需内核改动 | 需要 replay load context；开销最高；不是 proof | **最佳主方案** |
| C | daemon 内实现 verifier 风格抽象解释 | 无 kernel 交互；可定制 cutpoint/比较逻辑 | 若仅复刻 unary 域，理论上仍不够；若做 relational 域，工程量爆炸 | 不建议作为主线 |

### 6.1 为什么 B 优于 A

方案 A 的最大问题不是“能不能 rollback”，而是:

- **rollback 太晚**

如果 checker 在 REJIT 之后才发现 semantic drift:

- 程序已经被原子替换
- 即使之后再回滚，也已经有一段错误行为窗口

而方案 B 在每个 pass 后先 temp verify:

- 没有 attach
- 没有 swap
- 失败只是不接受该 pass 的结果

这是更符合 correctness guardrail 的位置。

### 6.2 为什么 C 不值得先做

如果 C 只是在 daemon 里复刻 kernel verifier 的 unary abstract domain:

- 它与 B 的理论上限一样
- 还要承担 kernel drift 成本

如果 C 想真正弥补 soundness:

- 就必须做 relational abstract interpretation
- 或 product program/translation validation

这已经不是“简化版 verifier”了，而是新的 formal engine。

因此 C 的合理用途不是替代 B，而是:

- 后续做 state normalization
- 做 dead-reg / cutpoint-aware comparison

## 7. 方案 B 的具体可行性

## 7.1 `BPF_PROG_LOAD` 需要什么参数

标准 `BPF_PROG_LOAD` UAPI 至少涉及:

- `prog_type`
- `insn_cnt`
- `insns`
- `license`
- `log_level`
- `log_size`
- `log_buf`

以及按 program type 可能还需要:

- `expected_attach_type`
- `prog_flags`
- `prog_btf_fd`
- `attach_btf_id`
- `attach_prog_fd` 或 `attach_btf_obj_fd`
- `fd_array` / `fd_array_cnt`

本地内核源码 `vendor/linux-framework/kernel/bpf/syscall.c` 也明确说明了:

- 某些 prog type 在 load time 必须给 `expected_attach_type`
- tracing / LSM / EXT / struct_ops 某些场景必须给 attach BTF 或 target prog

因此方案 B 的结论不是“只要拿到 bytecode 就能 temp load”，而是:

> **需要 faithfully replay 足够多的 load-time context。**

## 7.2 map fd 怎么传

这里有一个很关键的工程点。

`orig_prog_insns` 是在 `BPF_PROG_LOAD` 时从 userspace 原样拷进 kernel 后保存的原始指令副本。对 map reference 来说，这意味着它里面保存的是:

- **原 loader 进程的 pseudo-map-fd 数字**

而不是:

- map id
- 可跨进程复用的 fd

所以 daemon 拿到 `orig_prog_insns` 后，**不能直接拿去 temp `BPF_PROG_LOAD`**。必须先做一层 replay:

1. 用 `bpf_prog_info.map_ids` 拿到 map id 列表
2. 通过 `BPF_MAP_GET_FD_BY_ID` 在 daemon 自己的 fd table 里重新打开这些 map
3. 把 bytecode 里的 `BPF_PSEUDO_MAP_FD` 立即数改成 daemon 持有的 map fd
4. 或者改写成 `BPF_PSEUDO_MAP_IDX` 并通过 `fd_array` 传入

当前 daemon 里还没有:

- `BPF_MAP_GET_FD_BY_ID` wrapper
- pseudo-map-fd remap 逻辑

因此方案 B 的第一步工程工作就是把 **map replay context** 补齐。

## 7.3 可以不 attach 只 verify 吗

可以。

`bpf(2)` man page 明确说明:

- `BPF_PROG_LOAD` 返回一个新的 prog fd
- 之后程序才会被 attach 到事件
- 如果只是 load 成功但不 attach，关闭 fd 即可卸载这个临时程序

也就是说，方案 B 的 temp verify 路径可以是:

1. `BPF_PROG_LOAD(temp_prog)`
2. 读取 verifier log
3. 立即 `close(temp_fd)`

无需 attach。

## 7.4 `log_level=2` 能拿到每条指令的状态吗

可以拿到 **verifier 探索过程中的状态快照**，但要避免过度解读。

准确说法是:

- 能拿到 path-sensitive state snapshots
- 包括 `from <prev> to <pc>: ...` 和 `<pc>: ...`
- 并可加 `BPF_LOG_STATS` 拿到 verifier time

但这不是:

- 一个 canonical 的 “每个 PC 唯一抽象状态表”

因为:

- 同一 PC 可重复出现
- 不同路径下状态不同
- exploration/pruning 顺序会影响输出

所以这些 log **足够做 cutpoint-level differential checking**，但不适合做“逐 PC 唯一状态字典”。

## 7.5 性能开销大约多少

现有仓库里没有直接测过“每次 temp `BPF_PROG_LOAD(log_level=2|stats)` 的 verifier-only 时间”，所以这里必须分三层说:

1. **可精确测量**
   - kernel 已经支持 `BPF_LOG_STATS`
   - verifier log 会输出 `verification time <N> usec`
   - 所以方案 B 上线后可以直接对每个 temp load 记录精确 verifier 时间

2. **现有 repo 的粗上界**
   - 现有文档里已有两类相关数字:
     - REJIT regression 测到的 kernel-side latency 约 `27 us`
     - 较早 recompile syscall 文档测到 median `29.89 us`
   - 这些数字说明:
     - 对小到中等程序，kernel-side “verify/JIT/replay” 本身在几十微秒量级并不离谱

3. **真正会放大开销的是 `log_level=2`**
   - 生成 path-sensitive verifier log 会引入字符串格式化和 user copy 成本
   - 对大程序/复杂 CFG，这个开销可能显著高于“裸 verify + JIT”

因此保守结论是:

- **方案 B 在 changed-pass 数量不大时是可接受的**
- 但不能假设 “6 个 pass x 1 次 temp load” 对任意大程序都几乎免费
- 实际上线应采样并记录:
  - verifier time
  - total syscall wall time
  - log size
  - 每 pass changed/un-changed

## 7.6 是否需要修改 kernel

如果问题是:

- “能否用标准 `BPF_PROG_LOAD` 做 temp verify？”

答案是:

- **不需要内核修改**

如果问题是:

- “能否对所有 live program 仅靠现有 `bpf_prog_info` 就 faithful replay 原始 load 语境？”

答案是:

- **不完全能**

原因是 current userspace 可见信息仍然不完整。当前 daemon 的 `ProgMeta` 只有:

- `prog_id`
- `prog_type`
- `prog_name`
- `map_ids`
- `btf_id`
- run stats

但 temp `BPF_PROG_LOAD` 想做到与原始 load 等价，至少还需要考虑:

- `expected_attach_type`
- `gpl_compatible`
- `prog_flags`
- `attach_btf_obj_id`
- `attach_btf_id`
- 某些 tracing/ext 的 target prog 或 target BTF
- map fd remap

其中:

- `gpl_compatible`、`attach_btf_obj_id`、`attach_btf_id` 可从 `bpf_prog_info` 取到
- 但 `expected_attach_type`、完整 `prog_flags`、部分 attach target 上下文并不总能仅靠当前 daemon 现有元数据恢复

所以更精确的结论是:

> **方案 B 不需要 kernel 改动即可起步，但若想覆盖所有 live program family，需要 daemon 额外恢复/缓存 load-time metadata；否则只能先支持一个“易 replay 的 prog type 子集”。**

## 8. 实现设计

## 8.1 总体设计原则

不要把方案 B 设计成:

- “全程序全 PC 强等价检查器”

而要设计成:

- “per-pass cutpoint-based suspicious-drift filter”

目标是:

- 尽早发现明显 semantic drift
- 把问题定位到具体 pass
- 在真正 REJIT 之前就丢弃可疑变换

## 8.2 daemon 端数据流

建议的数据流如下:

1. 枚举 live prog，读取:
   - `orig_prog_insns`
   - `bpf_prog_info`
2. 构造 `LoadReplayContext`
   - `prog_type`
   - `gpl_compatible`
   - `expected_attach_type`
   - `prog_flags`
   - `attach_btf` / target context
   - reopened map fds
   - kfunc/module fds
3. 从 `orig_prog_insns` 初始化 `BpfProgram`
4. 按 pipeline 顺序逐 pass 运行
5. 每个 changed pass 后:
   - temp verify `program_before_pass`
   - temp verify `program_after_pass`
   - 解析 log
   - 比较 cutpoint states
6. 若比较结果为 suspicious:
   - 丢弃该 pass 结果
   - 记录告警
   - 程序退回 `program_before_pass`
7. 所有 pass 跑完后，只对最终版本做一次真实 `BPF_PROG_REJIT`
8. 如果真实 REJIT 因 verifier rejection 失败:
   - 继续走现有 rollback/disable-pass 机制

这和当前框架很契合，因为:

- pass 已经是顺序执行的
- `PassManager` 已有 analysis invalidation
- `BpfProgram.required_module_fds` 已经在积累 kfunc 依赖

## 8.3 需要补的 daemon 元数据

当前 `ProgMeta` 不够。

建议新增一个专门的 `LoadReplayContext`，至少包含:

- `prog_type`
- `gpl_compatible`
- `expected_attach_type`
- `prog_flags`
- `attach_btf_obj_id`
- `attach_btf_id`
- `attach_prog_id` 或 tracing target
- `map_fds_by_id`
- `canonical_license`
- `bound_fd_array`

其中 `canonical_license` 可以简单取:

- GPL-compatible -> `"GPL"`
- otherwise -> `"MIT"`

因为对 privileged daemon 来说，真正影响 verifier helper/kfunc 权限的是 GPL compatibility bit，而不是原始 license 文本本身。

## 8.4 `bpf.rs` 需要补的 syscall wrapper

当前 daemon 只有:

- `BPF_PROG_GET_NEXT_ID`
- `BPF_PROG_GET_FD_BY_ID`
- `BPF_OBJ_GET_INFO_BY_FD`
- `BPF_PROG_REJIT`

方案 B 至少还需要:

- `BPF_MAP_GET_FD_BY_ID`
- `BPF_BTF_GET_FD_BY_ID`
- 可能还需要 `BPF_LINK_GET_FD_BY_ID` / `BPF_OBJ_GET_INFO_BY_FD(link_fd)`
  - 用于 tracing/ext 场景恢复 attach target
- 一个标准 `bpf_prog_load_temp()` wrapper
  - 支持 `log_level=2|BPF_LOG_STATS`
  - 支持 `fd_array`
  - 返回 verifier log 与 temp fd

## 8.5 `PassManager` 的接入点

当前 `PassManager::run()` 是“一次跑完整 pipeline”。

方案 B 更适合把它改成:

- `run_one_pass(...)`
- 或者给 `run()` 加一个 callback:
  - `before_pass(pass_name, program_before)`
  - `after_pass(pass_name, program_before, program_after, pass_result)`

这样可以:

- 直接在 pass 边界做 temp verify
- 不再依赖最终程序上的 conservative attribution

这比现在的 rollback attribution 更精确，也更符合 per-pass differential checking 的目的。

## 8.6 verifier log parser 需要升级什么

当前 `daemon/src/verifier_log.rs` 必须升级，否则 differential checker 的信息量不够。

建议新增结构:

```rust
struct VerifierSnapshot {
    pc: usize,
    prev_pc: Option<usize>,
    speculative: bool,
    frame_states: Vec<FrameState>,
}

struct FrameState {
    regs: HashMap<u8, RichRegState>,
    stack: HashMap<i32, StackSlotState>,
    refs: Vec<u32>,
}

struct RichRegState {
    reg_type: String,
    off: Option<i32>,
    packet_range: Option<u32>,
    id: Option<u32>,
    ref_obj_id: Option<u32>,
    smin: Option<i64>,
    smax: Option<i64>,
    umin: Option<u64>,
    umax: Option<u64>,
    smin32: Option<i32>,
    smax32: Option<i32>,
    umin32: Option<u32>,
    umax32: Option<u32>,
    var_off: Option<(u64, u64)>,
    known_value: Option<i64>,
}
```

最关键的是补上:

- `id`
- packet range `r`
- `var_off`
- stack initialized/spill state
- `prev_pc`

否则很多真正该比较的 proof fact 根本丢了。

## 8.7 状态对比算法

### 8.7.1 比较单位不是“所有 PC”

建议比较单位为 **cutpoints**:

- pass site entry
- pass site exit
- merge point
- function exit

理由:

- old/new 指令数量不同
- 同一 site 内部 PC 无法自然对齐
- branch_flip / cond_select 内部 path state 噪声太大

### 8.7.2 比较对象不是“所有寄存器”

建议只比较:

- live-in / live-out regs
- `R0` at exits
- pointer regs
- stack slots that are live or later-read

不要比较:

- 明确 dead 的 tmp regs
- 被 call clobber 且不 live-out 的 `R1-R5`

否则 false positive 会很多。

### 8.7.3 比较关系不是简单字符串相等

建议分两级:

- **hard mismatch**
  - reg type 不同
  - pointer fixed offset 不同
  - packet range `r` 不同
  - stack initializedness/spill kind 不同
  - return type 不同
- **soft mismatch**
  - scalar range 变宽/变窄
  - `var_off` 精度变化
  - non-live caller-saved reg state 变化

策略:

- hard mismatch: 默认拒绝该 pass
- soft mismatch: 记录 warn，可配置为拒绝或继续

### 8.7.4 对同一 PC 的多个状态

建议不要强行只保留一个状态。

而是:

- 按 cutpoint 收集 state set
- 对每个 pre-state 在 post-state 集合里找一个 matching state
- 或者先把 state set 归一化成 live-reg projection 再比较 multiset

第一版可以简化为:

- 只比较 cutpoint 上的 state hull
- 但要明确这会进一步降低 soundness

## 8.8 pass-specific 策略

建议不要对所有 pass 用同一个严格度。

### `wide_mem`

- 最适合 strict diff
- 比较:
  - entry pointer facts
  - exit dst range
  - live-out regs

### `extract` / `endian_fusion`

- 适合 medium-strength diff
- 重点比较:
  - dst scalar bounds
  - pointer legality
  - live-out regs

### `rotate` / `cond_select`

- verifier diff 只做 advisory
- 更应依赖本地 peephole translation validator

### `branch_flip`

- 只比较 site entry / merge / exit
- 不比较 branch-local states

## 8.9 告警和回退策略

推荐策略:

1. pass 后 temp diff 无异常:
   - 接受该 pass 结果
2. pass 后出现 hard mismatch:
   - 拒绝该 pass
   - 回退到 pass 前程序
   - 记录 `prog_id + pass_name + site + diff summary`
3. pass 后只有 soft mismatch:
   - 默认 warn
   - 可以策略化:
     - hot path: 更保守，拒绝
     - cold path: 继续
4. 最终仍执行真实 REJIT
5. 若真实 REJIT 被 verifier 拒绝:
   - 用现有 rollback 机制继续 disable-pass and retry

也就是说:

- 方案 B 不是替代当前 rollback
- 而是 **前置的 correctness guardrail**

## 9. 与现有 rollback 机制的关系

当前 daemon 已经有:

- verifier rejection log parser
- `extract_failure_pc()`
- attribution + disable-pass retry

这是一个 **safety / acceptance-oriented** rollback。

方案 B 则提供一个 **correctness-oriented** pre-REJIT filter。

两者关系应是:

- 方案 B: pre-swap，抓 suspicious semantic drift
- 现有 rollback: post-temp-verify、pre-swap 的最后防线，抓 verifier rejection

这样系统就形成三层保护:

1. pass 自己的 syntactic/liveness guards
2. verifier differential checking
3. final REJIT verifier rejection rollback

## 10. 与 related work 的对比

| 系统 | 时机 | 目标 | 方法 | 是否 transparent to live programs | correctness guarantee |
| --- | --- | --- | --- | --- | --- |
| K2 | pre-load | 优化 bytecode | synthesis + solver-based equivalence checking | 否 | 强，接近 translation validation |
| Merlin | pre-load | LLVM IR + bytecode 优化 | compiler-integrated passes + bytecode rewriting | 否 | 依赖编译器/规则正确性，不是 post-load |
| EPSO | pre-load | eBPF superoptimization | offline superoptimization + cached rewrite rules | 否 | 强于手写 peephole，但仍是 compile-time optimizer |
| Jitterbug | JIT compiler verification | 证明 JIT 正确 | 形式化 JIT correctness + automated proof | 不适用 | 强，验证的是编译器后端 |
| 我们 | post-load | 在线检测 semantic drift | kernel verifier abstract-state differential checking | **是** | **弱，只是 heuristic** |

### 10.1 K2

K2 的核心是:

- synthesis 出候选 BPF program
- 用 solver 做 equivalence checking
- 另外再看 kernel checker 是否接受

它的 correctness 思路是:

- **语义关系证明**

而不是:

- 比较两个 unary verifier abstract states

K2 的优点是 correctness 强，缺点是:

- compile-time
- 依赖原始编译流程/对象
- 优化成本高
- 不适合 BpfReJIT 这种 transparent post-load 模式

### 10.2 Merlin

Merlin 明确是:

- customized LLVM passes
- bytecode rewriting
- 在 **eBPF verification 之前** 做优化

也就是说它仍然是 compile-time compiler pipeline 的一部分。

Merlin 的优势是:

- 可以在 IR 和 bytecode 两层做优化
- 比 K2 更工程化

但它没有 BpfReJIT 的 post-load 透明性，也没有 live-program dynamic specialization 的定位。

### 10.3 EPSO

EPSO 的关键思想是:

- 用 offline superoptimization 发现 rewrite rules
- 在线阶段做轻量规则复用

它比 K2 更像“把昂贵 proof/search 前移离线”。

与我们相比:

- 它仍然是 pre-load optimizer
- correctness 逻辑仍围绕 rewrite rule discovery / superoptimization
- 不是 kernel-native、不是 post-load differential audit

### 10.4 Jitterbug

Jitterbug 解决的是另一个层次的问题:

- **JIT compiler correctness**

它证明的是:

- machine code emission 相对 bytecode semantics 的正确性

而 BpfReJIT differential verifier 想解决的是:

- userspace pass 对 **bytecode -> bytecode** 变换的 runtime guardrail

因此两者不是竞争关系，而是正交关系:

- Jitterbug 证明 JIT 后端
- 我们的方案检测 post-load rewrite 策略

### 10.5 我们的独特位置

如果把定位说准，我们的独特点其实很清楚:

- **post-load**
- **transparent**
- **复用 kernel 内部现成 verifier**
- **在线、便宜、无需独立证明基础设施**

代价则是:

- correctness 保证弱

所以最合理的论文故事不是“替代 K2/Jitterbug”，而是:

> 在 transparent post-load setting 下，完整 solver-based translation validation 太重；
> kernel verifier differential checking 提供了一个低成本、在线、内生于内核安全模型的异常检测机制。

## 11. 最终结论和建议

### 11.1 可行性结论

**可行。**

但这里的“可行”要严格限定为:

- 作为 **heuristic differential correctness detector**
- 不是作为 **sound verifier-backed proof of equivalence**

### 11.2 工程结论

建议路线是:

1. **做方案 B，不做 A-first，不做 C-first。**
2. **先支持易 replay 的 prog type 子集。**
   - 优先: `XDP`, `TC`, `cgroup_skb`
   - tracing / ext / struct_ops 放第二阶段
3. **先把 parser 升级到 rich state。**
4. **比较 cutpoints，不比较所有 PC。**
5. **使用 live-out filtering。**
6. **把 `wide_mem` 作为 first-class strict differential pass。**
7. **把 `rotate` / `cond_select` 当作 verifier-diff 弱信号 pass。**
8. **对高风险 peephole 增加本地 translation validation。**

### 11.3 对 pass 的推荐策略

| pass | verifier diff 推荐级别 | 额外建议 |
| --- | --- | --- |
| `wide_mem` | 高 | 直接上 strict cutpoint diff |
| `extract` | 中 | 结合 range/tnum 比较 |
| `endian_fusion` | 中 | 更关注 pointer/load legality，另补本地 byte-order validator |
| `rotate` | 低 | 必须补本地 bitvector validator |
| `cond_select` | 低 | 必须补本地 SMT/bitvector validator |
| `branch_flip` | 低 | 只做 entry/merge/exit diff，不做 strict interior diff |

### 11.4 最值得写进论文的一句话

> BpfReJIT can reuse the kernel verifier as a lightweight differential abstract interpreter to detect suspicious semantic drift across post-load rewrites, but this mechanism is intentionally best-effort and complements rather than replaces formal equivalence validation.

## 12. 参考

项目内代码/文档:

- `docs/kernel-jit-optimization-plan.md`
- `daemon/src/verifier_log.rs`
- `daemon/src/pass.rs`
- `daemon/src/passes/mod.rs`
- `daemon/src/passes/wide_mem.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`
- `daemon/src/passes/branch_flip.rs`
- `daemon/src/bpf.rs`
- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/log.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`

外部一手资料:

- Linux kernel verifier docs: <https://docs.kernel.org/6.15/bpf/verifier.html>
- Linux `bpf(2)` man page: <https://man7.org/linux/man-pages/man2/bpf.2.html>
- K2: <https://people.cs.rutgers.edu/~sn624/papers/k2-sigcomm21.pdf>
- Merlin: <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>
- EPSO: <https://arxiv.org/abs/2511.15589>
- Jitterbug / OSDI'20: <https://www.usenix.org/conference/osdi20/presentation/nelson>

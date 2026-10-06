# Emitter Cost And BRANCH_FLIP Analysis

Date: 2026-03-20

Scope:
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/kernel_bloat_review_20260320.md`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `scanner/src/pattern_v5.cpp`

Constraint:
- 只做调研分析，不改内核/扫描器代码，不 commit，不 push。

## Executive Summary

结论先行：

1. 当前 7 个 form 的新增成本，按“validator + x86 emitter + arm64 emitter + scanner”四层合计，简单 form 大致在 **180-500 LOC**，复杂 form `BRANCH_FLIP` 在当前架构下约 **1132 LOC**。
2. `ROTATE` 这一类“简单但不是最小”的 cross-arch form，当前真实成本约 **495 LOC**：
   - validator 235
   - x86 emitter 64
   - arm64 emitter 23
   - scanner 173
3. `BRANCH_FLIP` 这一类 control-flow form，当前真实成本约 **1132 LOC**：
   - validator 344
   - x86 emitter 663
   - arm64 emitter 0
   - scanner 125
4. `BRANCH_FLIP` 的 x86 成本主要不是顶层 `emit_canonical_branch_flip()` 本身，而是它背后的 **x86 linear replay substrate**：
   - `emit_bpf_alu32_insn` + `emit_bpf_end_insn` + `emit_bpf_alu64_insn` + `emit_linear_bpf_insn` 约 **524 LOC**
   - 真正 branch-flip 控制逻辑只有约 **139 LOC**
5. “只改 jcc 条件码 1 字节就把 hot path 变成 fallthrough”这个核心假设 **不成立**。原因不是 offset 细节，而是 **物理布局**：
   - 原生代码里 fallthrough 路径就是 `body_a`
   - 只反转条件码不会改变哪一段字节紧跟在 `jcc` 后面
   - 要让 `body_b` 变成 fallthrough，必须 **重排 body 字节顺序**，或者构造等价的新控制流；只改 1 字节不可能
6. 因此，`BRANCH_FLIP` 不能靠“只 patch cond byte”砍到 `<50 LOC`。
7. 但可以把“per-form 边际成本”显著降下来，最有效的两个方向是：
   - **表驱动 validator**：把 scanner/validator 的 pattern duplication 收敛到一份 declarative spec
   - **共享 linear emitter helper**：把 `BRANCH_FLIP` 现在重复的 524 LOC stock-emission 逻辑抽成共享 helper，未来 replay 型 form 的边际成本可降到几十到百来行

## Method

计数口径：

1. 只统计 **form-dedicated code**。
2. 只要一个 helper 基本只服务某个 form，就算进该 form。
3. 多 form 共享的基础设施不重复记账，单列为 `shared infra`。
4. 不计入：
   - 通用 dispatch / lookup / staged commit/abort
   - 通用 policy/plumbing
   - scanner 主扫描循环
   - `include/linux/bpf_jit_directives.h` 里的共享 inline helper

两个小 caveat：

1. validator 里的 `bpf_jit_cond_op_valid()` 被 `COND_SELECT` 和 `BRANCH_FLIP` 共用，但它和 cond-select helper 放在一起，我把它记到 `COND_SELECT`，`BRANCH_FLIP` 只记它自己的 4 行 wrapper。
2. x86 里的 `bpf_jmp_invert()` / `bpf_jmp_to_x86_cond()` / `bpf_jmp_to_x86_cmov()` / `emit_bpf_jmp_cmp()` 被 `COND_SELECT`、`BRANCH_FLIP` 和 stock `do_jit()` 共享，所以我单列成 shared infra，不双重算到 form 里。

## Part 1: Per-Form LOC

### 1.1 Per-form dedicated LOC

| Form | Validator | x86 emitter | arm64 emitter | Scanner | Total |
|---|---:|---:|---:|---:|---:|
| `COND_SELECT` | 325 | 116 | 229 | 445 | 1115 |
| `WIDE_MEM` | 165 | 58 | 131 | 146 | 500 |
| `ROTATE` | 235 | 64 | 23 | 173 | 495 |
| `ADDR_CALC` | 90 | 52 | 0 | 37 | 179 |
| `BITFIELD_EXTRACT` | 181 | 55 | 31 | 112 | 379 |
| `ENDIAN_FUSION` | 118 | 58 | 0 | 90 | 266 |
| `BRANCH_FLIP` | 344 | 663 | 0 | 125 | 1132 |

观察：

- 最便宜的 form 是 `ADDR_CALC`，总计 **179 LOC**。
- “简单 cross-arch form” 的真实成本落在 **379-500 LOC**。
- `COND_SELECT` 和 `BRANCH_FLIP` 是两个明显 outlier：
  - `COND_SELECT` 被 scanner descriptor 爆炸拖高
  - `BRANCH_FLIP` 被 x86 replay substrate 拖高

### 1.2 Shared infra not charged to a single form

| File | Shared infra | LOC |
|---|---|---:|
| `kernel/bpf/jit_validators.c` | `site_range` / `interior_edge` / `param_set_*` / `form_meta` 等 | 172 |
| `arch/x86/net/bpf_jit_comp.c` | `bpf_jmp_invert` / `bpf_jmp_to_x86_cond` / `bpf_jmp_to_x86_cmov` / `emit_bpf_jmp_cmp` | 149 |

结论：

- 当前“每新增一个 form”的真实成本，不能只看 emitter。
- 真正的边际成本主要来自三份逻辑重复：
  - scanner pattern
  - kernel validator
  - arch emitter

### 1.3 BRANCH_FLIP x86 emitter 内部拆分

`BRANCH_FLIP` 的 663 LOC 里，真正 branch-flip-specific 的控制逻辑并不大，主要成本来自 replay substrate：

| x86 BRANCH_FLIP sub-block | LOC |
|---|---:|
| `emit_bpf_alu32_insn` | 191 |
| `emit_bpf_end_insn` | 67 |
| `emit_bpf_alu64_insn` + `emit_linear_bpf_insn` | 266 |
| `measure_branch_flip_body` + `emit_branch_flip_body` + local jump helpers + `emit_canonical_branch_flip` | 139 |
| Total | 663 |

关键点：

- 其中前 3 项合起来约 **524 LOC**，本质上是在复制 `do_jit()` 的 stock emission 逻辑。
- 这也是之前文档里“~420 行 ALU replay”判断的当前精确版本：现在按文件行计，整个 replay substrate 实际更接近 **523-524 LOC**。

## 2. 新增一个 form 需要多少行

### 2.1 简单 peephole form（类似 `ROTATE`）

用 `ROTATE` 作为真实样本：

- validator: 235
- x86 emitter: 64
- arm64 emitter: 23
- scanner: 173
- total: **495 LOC**

如果只做 x86，不做 arm64，则是：

- 235 + 64 + 173 = **472 LOC**

如果比 `ROTATE` 再简单一点，接近 `ADDR_CALC` / `ENDIAN_FUSION` 这种单一形状 form，则当前架构下更现实的区间是：

- x86-only: **180-300 LOC**
- x86 + arm64: **220-350 LOC**

但如果你说的“简单”真的是“类似 ROTATE 这种有多个 source shape、scanner descriptor 也不少的 form”，那当前真实成本就是 **约 450-500 LOC**，不是 50-100 LOC。

### 2.2 复杂 form（类似 `BRANCH_FLIP`）

用 `BRANCH_FLIP` 作为真实样本：

- validator: 344
- x86 emitter: 663
- arm64 emitter: 0
- scanner: 125
- total: **1132 LOC**

如果未来还要补 arm64 branch-flip，现实成本还会继续上去。

因此：

- 在当前架构里，复杂 control-flow form 的真实成本是 **约 1k LOC/form**
- 其中最大头是 x86 replay substrate，不是 scanner，不是 staged commit/abort

## 3. 这个成本是否合理

### 3.1 先看“kernel backend 本身”的成本

如果只看 emitter lowering，不看 scanner/validator：

- `ROTATE` x86 只有 **64 LOC**
- `WIDE_MEM` x86 只有 **58 LOC**
- `ADDR_CALC` x86 只有 **52 LOC**
- `ENDIAN_FUSION` x86 只有 **58 LOC**
- `ROTATE` arm64 只有 **23 LOC**

这和普通 kernel/backend peephole 的量级是接近的：**几十行到一百来行**。  
所以“lowering 本身”并不臃肿。

真正昂贵的是：

1. scanner 还要再写一遍 pattern
2. kernel validator 还要再写一遍 fail-closed 安全检查
3. 某些 form 还要补第二个架构

所以结论不是“emitter 太胖”，而是 **BpfReJIT 的 layered architecture 把单 backend peephole 变成了多层重复实现**。

### 3.2 对比 GCC / LLVM backend

对比对象的成本明显更低，但原因也很直接：它们通常只需要维护一层 backend rule，不需要 scanner + kernel validator + per-arch emitter 三重重复。

#### GCC

GCC 官方文档里的 `define_peephole2` 示例本身大约就是 **十几行**；真实 i386 `define_peephole2` 例子在官方 gcc-cvs diff 里也基本是 **十几到二十几行一个 pattern**。  

原因：

- pattern 是 declarative machine description
- matcher 和调度基础设施是共享的
- 没有额外的 userspace scanner
- 没有一个独立的 kernel-side fail-closed validator

#### LLVM

LLVM 官方 `Pat` 例子甚至只有 **2-3 行一个选择规则**，例如文档里把任意 `i32` immediate 匹配到 `LIS/ORI` 的 `Pat`。  
复杂一点的情况会退回自定义 C++ matcher/combine，但那仍然只生活在 backend 一层，不需要再同步维护 scanner 和安全 validator。

#### 对比结论

按“单 backend pattern”的标准看，BpfReJIT 的 **180-500 LOC/simple form** 和 **~1.1k LOC/complex form** 显然偏贵。  
但按“scanner + fail-closed validator + x86/arm64 lowering”这个四层系统的标准看，这个成本是 **可以解释的**，不是莫名其妙的膨胀。

更准确的判断是：

- `ROTATE` / `WIDE_MEM` / `BITFIELD_EXTRACT` 这类 form：**合理但贵**
- `BRANCH_FLIP`：**功能上合理，边际成本偏高，说明缺少共享 substrate**

### 3.3 对比“kernel peephole pass”

如果和“单 kernel backend 的硬编码 peephole”比：

- 现有 x86/arm64 emitter 本身已经是同一量级
- 成本差几乎全部来自 scanner + validator 双重实现

所以这里的 trade-off 很清楚：

- kernel peephole：每个 pattern 便宜，但没有 userspace policy control，也没有 scanner/kernel decoupling
- BpfReJIT：每个 form 昂贵，但换来 safety/optimization 分离、userspace policy、跨程序/跨架构控制

## 4. 怎么降低“每新增一个 form”的边际成本

### 4.1 表驱动 validator

这是最值得做的一个方向。

现状：

- scanner 已经有 declarative descriptor DSL
- kernel validator 仍然是手写 imperative matcher
- 于是 scanner 和 validator 维护了两份 pattern 知识

最适合表驱动化的 form：

- `ADDR_CALC`
- `ENDIAN_FUSION`
- `WIDE_MEM`
- `ROTATE`
- `BITFIELD_EXTRACT`

`COND_SELECT` 和 `BRANCH_FLIP` 也可以部分吃到收益，但会保留 custom post-check：

- `COND_SELECT` 还要做 alias 检查
- `BRANCH_FLIP` 还要做 diamond CFG、body linearizability、native-byte budget 检查

收益判断：

- 对简单 form，validator 侧有机会从 **90-235 LOC/form** 降到 **20-80 LOC/form**
- 更重要的是减少 scanner/validator 语义漂移风险

代价：

- 需要在 kernel 里引入一个小型 declarative matcher，或者从一份 spec 生成 C 代码
- 一次性 substrate 成本会上升

判断：

- 如果还准备继续加很多 form，**值得**
- 如果 form 数量停在 7-10 个，收益中等

### 4.2 通用 emit helper

这是对 `BRANCH_FLIP` 最有效的方向。

现状：

- `BRANCH_FLIP` 为了重放 body，复制了一整份 x86 stock emission 逻辑
- 当前重复成本约 **524 LOC**

更好的结构：

1. 从 `do_jit()` 抽一个共享的 `emit_stock_linear_insn()` / `emit_stock_linear_range()`
2. `do_jit()` 和 `BRANCH_FLIP` 都调用它
3. `BRANCH_FLIP` 自己只保留：
   - compare/jcc inversion
   - body range size measurement
   - `body_b + jmp + body_a` 的控制逻辑

效果：

- `BRANCH_FLIP` per-form x86 成本可从 **663 LOC** 降到大约 **120-180 LOC**
- 未来任何 replay 型 form 的边际成本也会大幅下降

注意：

- 这是 **共享化**，不是“删掉复杂性”
- 复杂性依然存在，只是从 per-form duplicated code 变成 shared backend substrate

### 4.3 更轻量的 hook / staged commit 机制

这个方向收益最小。

原因：

- staged commit/abort 现在已经是 shared plumbing
- per-form emitter 并没有各自复制 staged state machine
- 真正的 LOC 热点不在这里，而在 matcher duplication 和 replay substrate

所以：

- 可以继续保持当前 staged 设计
- 不值得把它当作主要减肥方向

### 4.4 Native-byte splice substrate（只对复杂 control-flow form 值得考虑）

这是专门给 `BRANCH_FLIP` 这种 form 的方向。

思路：

- 不是重新 emit body 的 BPF 指令
- 而是直接拷贝旧 image 中对应 body 的 native byte slice，再重排拼接

如果要做，需要额外能力：

1. 持久保存 BPF insn 到 native byte range 的映射，而不是只在 JIT pass 内有 `addrs[]`
2. 让 emitter 能访问“旧 image + 旧 native ranges”
3. 保证 site 内没有 overlap / relocation / arch-specific side effect

它有潜力把 `BRANCH_FLIP` 的 x86 成本再往下压，但这已经是 **更大架构改造**，不是小修小补。

## Part 2: BRANCH_FLIP 条件码反转可行性验证

## 5. x86 `do_jit()` 里的 if/else native layout

`do_jit()` 对 `BPF_JMP/BPF_JMP32` 的 emit 顺序是 **严格按 BPF 指令顺序线性发射**。

对一个 canonical `BRANCH_FLIP` site，BPF 形状是：

```text
idx:        jcc   -> body_b
idx+1..N:   body_a
ja_idx:     ja    -> join
...:        body_b
join:
```

`do_jit()` 里关键逻辑在条件跳转分支：

```text
emit compare/test
emit cond-jump to addrs[i + insn->off]
```

以及无条件跳转分支：

```text
emit jmp to addrs[target]
```

所以 stock native layout 是：

```text
cmp/test
jcc body_b
body_a
jmp join
body_b
join
```

关键事实：

- `body_a` 是 **物理 fallthrough**
- `body_b` 是 **taken target**
- x86 JIT 没有先 emit CFG 再做 block layout；它就是按原始 BPF 顺序线性写字节

## 6. 当前 BRANCH_FLIP emitter 到底在做什么

当前 x86 `emit_canonical_branch_flip()` 不是 patch 原有 native code，而是 **重新生成一个新的 site**：

```text
emit compare/test
invert cond op
emit jcc_inv -> skip(body_b + jmp)
emit body_b
emit jmp -> skip(body_a)
emit body_a
```

也就是它把 layout 变成：

```text
cmp/test
jcc_inv body_a
body_b
jmp join
body_a
join
```

这样：

- 原来 taken 的 `body_b` 现在变成 fallthrough
- 原来 fallthrough 的 `body_a` 现在变成 taken

这正是想要的 hot-path relayout。

## 7. 只改条件码是否语义等价

结论：**不等价。**

### 7.1 只改条件码，不改 body 布局

原 layout：

```text
cmp
jcc body_b
body_a
jmp join
body_b
join
```

如果只把 `jcc` 改成 `jcc_inv`，得到：

```text
cmp
jcc_inv body_b
body_a
jmp join
body_b
join
```

这会发生什么：

- 原来 `cond == true` 时，应该执行 `body_b`
- 现在 `cond == true` 时，`jcc_inv` 不跳，直接 fallthrough 到 `body_a`

也就是语义直接反了。

所以：

- **条件码反转只会交换真假语义**
- **不会交换 physical fallthrough/taken layout**

### 7.2 为什么 body 大小相同也没用

就算 `body_a_size == body_b_size`，也仍然不够。

相同大小只意味着：

- 交换 block 后，jump encoding 可能保持同一 opcode size

但它不改变一个更根本的事实：

- 在原始字节序列里，紧跟在 `jcc` 后面的仍然是 `body_a`
- fallthrough 是物理布局属性，不是条件码属性

所以 same-size 只会让“重排之后的 offset 计算”更简单，不会让“只改 cond byte”突然成立。

### 7.3 只改条件码 + 改 `jmp` offset 行不行

也不行。

原因：

- site 里唯一能在进入 body 之前做条件分流的边，就是最前面的 `jcc`
- 后面的 `jmp` 在 `body_a` 之后才执行
- 一旦已经 fallthrough 进入 `body_a`，你就已经执行了错误的 block，后面再改 `jmp` target 也救不回来

所以：

- `jcc` 决定“先执行哪一段 body”
- `jmp` 只负责“执行完第一段之后跳过第二段”
- 光改 `jcc` 和 `jmp` 的 immediates，不能把 `body_b` 变成物理 fallthrough

### 7.4 body 大小不同时怎么办

如果真的做了 body swap，那么 body 大小不同会影响：

1. `jcc_inv` 的跳转距离：要跳过 `body_b + jmp_join`
2. `jmp_join` 的跳转距离：要跳过 `body_a`
3. `jcc` / `jmp` 是否还能保持 short jump，还是要升级成 near jump

当前实现就是因此先 `measure_branch_flip_body()`，再决定：

```text
jmp_join_size = 2 or 5
cond_jump_offset = body_b_size + jmp_join_size
jump_offset = body_a_size
```

这进一步说明：

- 这不是一个“1-byte cond patch”问题
- 这是一个“重新布局后的局部 codegen”问题

## 8. 能不能靠 text_poke 直接 patch 条件码字节

只能得到一个非常窄的 fast path，而且 **不构成通用 BRANCH_FLIP**。

### 8.1 只 patch cond byte

不行，原因上面已经证明：语义不等价。

### 8.2 patch 整个 site

理论上可以想象一种完全不同的设计：

1. 保留旧 image
2. 找到 site 对应 native byte range
3. 生成一个新的局部 byte sequence
4. 用 `text_poke` 或 staged copy 直接替换整段

但这已经不是“只改 1 字节”了，而且仍然需要：

- body byte boundaries
- 新 jump offsets
- short/near jump size decision
- RCU/text safety

也就是说：

- `text_poke` 不是核心难点
- **如何构造正确的新 site bytes** 才是核心难点

## 9. 有没有更轻量的替代方案

有，但都不是“只改条件码”。

### 9.1 最现实的方案：共享 stock linear emitter

这是我认为最务实的方案。

做法：

1. 把 `do_jit()` 的线性 ALU/END/LDX emission 抽成共享 helper
2. `BRANCH_FLIP` 继续 replay body，但不再复制 524 LOC stock emission

预期效果：

- 语义完全正确
- 设计与当前 validator/emitter 边界兼容
- 可以把 `BRANCH_FLIP` x86 per-form 代码从 663 LOC 明显压低

### 9.2 更激进方案：native-byte splice

做法：

1. 保留旧 image 的 per-insn native byte ranges
2. `BRANCH_FLIP` 直接 copy `body_b bytes + jmp + body_a bytes`

优点：

- 不需要 replay BPF 指令

缺点：

- 需要新的 metadata substrate
- 需要改变 recompile API / emitter context
- 需要解决 old-image/native-range 生命周期

这是可以研究的方向，但不是 50 LOC 修复。

### 9.3 “只改 jcc 条件码 + 修改 jmp offset”

明确判断：**不成立，不建议继续沿这个方向实现。**

原因不是实现细节，而是控制流结构本身不允许。

## 10. 明确结论

### 10.1 关于 Part 1

- 当前架构下，一个简单 form 的真实新增成本不是几十行，而是：
  - x86-only：大约 **180-500 LOC**
  - x86 + arm64：大约 **220-500 LOC**
- 如果拿 `ROTATE` 当样本，真实成本是 **495 LOC**
- 如果拿 `BRANCH_FLIP` 当样本，真实成本是 **1132 LOC**

这个成本：

- 对“分层 scanner + validator + 多架构 emitter”的系统来说，**可解释**
- 对“继续快速扩 form”这个目标来说，**偏高**

最值得优化的方向：

1. scanner/validator 统一 spec
2. x86 shared linear emitter helper

### 10.2 关于 Part 2

**不能**把当前 `BRANCH_FLIP` 简化成“只改 jcc 条件码 1 字节”。

理由：

1. 只改条件码只会交换真假语义，不会交换 fallthrough/taken 的物理布局
2. `body_b` 想变成 fallthrough，必须变成紧跟在 `jcc` 后面的那段字节
3. 因而必须：
   - 重放 body 指令，或
   - 拷贝并重排 body native bytes，或
   - 引入更复杂的新控制流/metadata substrate

所以对“能不能把 ~420 行砍到 <50 行”的明确回答是：

- **不能，前提是保持当前语义和当前架构约束**
- 能做的是把重复的 replay substrate 共享化，把 per-form x86 代码降到一百来行级别
- 但那是 **共享重构**，不是“1-byte patch trick”

## References

Local sources:

- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `scanner/src/pattern_v5.cpp`
- `docs/tmp/kernel_bloat_review_20260320.md`
- `docs/tmp/validator_emitter_boundary_audit_20260320.md`
- `docs/tmp/2026-03-13/endian-bflip-perf-investigation.md`

External comparison references:

- GCC internals, `define_peephole2`:
  - https://gcc.gnu.org/onlinedocs/gccint/define_005fpeephole2.html
- GCC real-world `define_peephole2` examples in official gcc-cvs diff:
  - https://gcc.gnu.org/pipermail/gcc-cvs/2021-July/350862.html
- LLVM Code Generator / TableGen `Pat` examples:
  - https://llvm.org/docs/CodeGenerator.html

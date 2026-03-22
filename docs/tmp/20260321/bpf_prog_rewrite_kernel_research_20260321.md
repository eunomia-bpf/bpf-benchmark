# `BPF_PROG_REWRITE` 内核实现可行性调研

日期: 2026-03-21

范围:
- 内核源码: `vendor/linux-framework/`（7.0-rc2 vendor tree）
- 重点文件:
  - `vendor/linux-framework/include/linux/bpf.h`
  - `vendor/linux-framework/include/linux/filter.h`
  - `vendor/linux-framework/include/uapi/linux/bpf.h`
  - `vendor/linux-framework/kernel/bpf/syscall.c`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
  - `vendor/linux-framework/kernel/bpf/core.c`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c`
  - `vendor/linux-framework/kernel/bpf/trampoline.c`
  - `vendor/linux-framework/kernel/bpf/arraymap.c`
  - `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
  - `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

---

## TL;DR

结论先说清楚:

1. **当前内核不会保留 eBPF 程序的原始 raw bytecode。**
   - `struct bpf_prog` 的 `insnsi` 只是“当前程序指令流”，load 时最初装的是用户 raw insns，但 verifier/fixup/JIT prep 会持续原地改写或扩容重分配它，最终留下的是 **post-verify / post-fixup 的 xlated 指令流**，不是原始输入。
   - 这棵树里也**没有** `orig_insns` 一类字段。`orig_prog` 只服务 classic BPF `struct sock_fprog_kern`，不是 eBPF 原始字节码，见 `vendor/linux-framework/include/linux/bpf.h:1837-1843` 和 `vendor/linux-framework/net/core/filter.c:1158-1178`.

2. **`bpf_insn_prepare_dump()` 不是原始 bytecode 的逆变换。**
   - 它只对当前 `prog->insnsi` 做部分导出清洗，主要是 map pointer -> map id、`TAIL_CALL`/`CALL_ARGS` opcode 规范化、部分 `PROBE_MEM*` 还原，见 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4959`.
   - 它**不会**把 helper/kernel-call imm 还原成原始 helper id，也**不会**逆转 `convert_ctx_accesses()` / `do_misc_fixups()` / hidden subprog / verifier 插入指令。
   - 因此 “读出 xlated dump -> 修改 -> 重新提交 -> full verifier” **不能**作为通用方案。

3. **可行的最小闭环方案不是纯 A，也不是纯 C，而是 `A' = 保存 kernel-owned pre-fixup rewrite baseline + 复用 C 的 live JIT image swap`。**
   - 单纯保存一份“用户原始 insns”还不够，因为原始 map FD / module-BTF fd-array 语义在 live rewrite 时已经丢了。
   - 最小可实现的闭环应当保存:
     - pre-fixup baseline insns
     - 原始 `prog_flags`
     - 原始 `func_info` / `line_info`
     - 最好再保存 `xlated -> orig` 映射，供 daemon 从 live xlated site 回溯到 baseline patch offset
   - live commit/swap 则应复用 `BPF_PROG_JIT_RECOMPILE` 已有的 snapshot / staged image / trampoline regeneration / `synchronize_rcu()` 逻辑，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:14-35`, `311-582`.

4. **最小内核改动版本必须有明确限制。**
   - 只支持 `prog->jited && bpf_jit_supports_recompile()` 的程序，和当前 `BPF_PROG_JIT_RECOMPILE` 一致，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:602-603`, `637-658`, `vendor/linux-framework/kernel/bpf/core.c:3232-3235`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5761-5764`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3867-3870`.
   - v1 最好要求 “rewrite 后 verified topology 不变”: 相同 `func_cnt/real_func_cnt`、相同 `used_maps` 集合、相同 poke/kfunc/BTF metadata 形状。否则就会落入“替换整个 `struct bpf_prog`”的问题域，复杂度会大很多。

5. **性能上，`BPF_PROG_REWRITE` 必然比当前 `BPF_PROG_JIT_RECOMPILE` 贵 2-3 个数量级。**
   - 当前 tree 里没有增量 verifier API；`BPF_PROG_LOAD` 总是 full verifier + runtime/JIT，见 `vendor/linux-framework/kernel/bpf/syscall.c:3089-3099`, `vendor/linux-framework/kernel/bpf/core.c:2599-2652`.
   - verifier 的复杂度上限是 `BPF_COMPLEXITY_LIMIT_INSNS = 1,000,000` processed insns，且 `env->insn_processed` 按状态遍历累计，不是 raw insn 数量，见 `vendor/linux-framework/include/linux/bpf.h:2319`, `vendor/linux-framework/kernel/bpf/verifier.c:21224-21231`, `24742-24763`.
   - 因此 full re-verify 的量级应按 **毫秒** 看，而不是现有 re-JIT syscall 的 **几十微秒**。

---

## 1. `struct bpf_prog` 是否保留原始 bytecode

### 1.1 这棵树里 `struct bpf_prog` 不在 `include/linux/filter.h`

用户要求先读 `include/linux/filter.h`。这个检查本身很重要，因为在这棵 7.0-rc2 vendor tree 里:

- `include/linux/filter.h` 只前置声明 `struct bpf_prog_aux`，并在运行时 helper 中使用 `prog->insnsi`，见 `vendor/linux-framework/include/linux/filter.h:35`, `695-724`.
- 真正的 `struct bpf_prog_aux` / `struct bpf_prog` 定义已经移动到 `include/linux/bpf.h`，见 `vendor/linux-framework/include/linux/bpf.h:1674-1803`, `1807-1844`.

这直接影响新增字段应该放在哪里。

### 1.2 `insnsi` 是什么

`struct bpf_prog` 的关键部分如下:

- `struct bpf_prog` 定义: `vendor/linux-framework/include/linux/bpf.h:1807-1844`
- `insnsi` 定义: `vendor/linux-framework/include/linux/bpf.h:1839-1843`
- `orig_prog` 定义: `vendor/linux-framework/include/linux/bpf.h:1838`

关键信息:

1. `insnsi` 不是“专门保存 raw insns 的字段”，它只是当前程序指令数组。
2. `orig_prog` 的类型是 `struct sock_fprog_kern *`，只给 classic BPF 用，不适合 eBPF 原始字节码。
3. 结构体里**没有** `orig_insns` / `orig_len` / `orig_func_info` / `orig_linfo` 一类字段。

`filter.h` 中 `bpf_prog_run()` 直接把 `prog->insnsi` 和 `prog->bpf_func` 一起传给 dispatcher，说明 `insnsi` 是运行时“当前指令流”接口的一部分，见 `vendor/linux-framework/include/linux/filter.h:700-730`.

### 1.3 用户 raw insns 是怎么进入 `struct bpf_prog` 的

`bpf_prog_load()` 的主流程在 `vendor/linux-framework/kernel/bpf/syscall.c:2872-3115`.

关键步骤:

1. 先分配裸 `struct bpf_prog`:
   - `prog = bpf_prog_alloc(bpf_prog_size(attr->insn_cnt), GFP_USER);`
   - 见 `vendor/linux-framework/kernel/bpf/syscall.c:2993-3002`

2. 设定长度:
   - `prog->len = attr->insn_cnt;`
   - 见 `vendor/linux-framework/kernel/bpf/syscall.c:3017`

3. 从用户态把 raw insns 直接复制到 union storage:
   - `copy_from_bpfptr(prog->insns, ...)`
   - 见 `vendor/linux-framework/kernel/bpf/syscall.c:3019-3023`

也就是说，**load 初始时** `prog->insnsi` / `prog->insns` 里确实是用户传进来的原始 eBPF 指令。

但这只是初始状态，不是最终保留状态。

### 1.4 `bpf_check()` 如何改变 `env->prog` / `prog->insnsi`

`bpf_check()` 在 `vendor/linux-framework/kernel/bpf/verifier.c:25912-26200`.

关键数据流:

1. verifier env 直接指向 load 时分配的 `prog`:
   - `env->prog = *prog;`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:25935-25947`

2. `insn_aux_data` 最初把每条当前指令映射回自身:
   - `env->insn_aux_data[i].orig_idx = i;`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:25936-25942`

3. verifier 后半段明确写着:
   - `/* instruction rewrites happen after this point */`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:26076-26077`

4. 之后顺序执行:
   - `optimize_bpf_loop()` `26077-26079`
   - `opt_remove_dead_code()` / `opt_remove_nops()` `26080-26090`
   - `convert_ctx_accesses()` `26092-26095`
   - `do_misc_fixups()` `26096-26097`
   - `opt_subreg_zext_lo32_rnd_hi32()` `26102-26105`
   - `fixup_call_args()` `26108-26109`

5. verifier 结束时返回的不是原始 `prog` 指针，而是当前可能已经被 reallocated 的 `env->prog`:
   - `*prog = env->prog;`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:26185`

所以 `bpf_check()` 不是“只读校验器”，而是“校验 + IR rewrite + 可能替换 `prog` 对象”的一体化流程。

### 1.5 `bpf_patch_insn_data()` 会不会增删指令

会。

核心 helper:

- `bpf_patch_insn_data()` 在 `vendor/linux-framework/kernel/bpf/verifier.c:22012-22041`
- 它底层调用 `bpf_patch_insn_single()`，见 `vendor/linux-framework/kernel/bpf/core.c:460-519`
- `bpf_patch_insn_single()` 会:
  - 允许 `1 -> n` patch
  - 必要时调用 `bpf_prog_realloc()`
  - 调整分支 offset 和 line info
  - 见 `vendor/linux-framework/kernel/bpf/core.c:474-518`

`bpf_prog_realloc()` 还会在 size 超过原页数时分配**新的** `struct bpf_prog`，复制旧内容后释放旧 prog，并把 `aux->prog` 指向新对象，见 `vendor/linux-framework/kernel/bpf/core.c:260-287`.

这说明 verifier rewrite 不只是“in-place 改几个 opcode”，而是可能:

1. 修改单条指令
2. 插入多条新指令
3. 删除指令
4. 扩大主程序长度
5. 改变 `struct bpf_prog *` 地址

### 1.6 `convert_ctx_accesses()` 是 in-place 吗

**部分 in-place，部分通过 `bpf_patch_insn_data()` 扩容重写。**

证据:

- 入口: `vendor/linux-framework/kernel/bpf/verifier.c:22480-22778`
- 直接改 opcode 的例子:
  - arena / probe mem form 直接改 `insn->code`，见 `22600-22602`, `22673-22680`, `22682-22693`
- 插入 prologue/epilogue / `ST_NOSPEC` / expanded ctx access sequence 的例子:
  - `22504-22512`, `22525-22536`, `22560-22569`, `22631-22643`, `22728-22775`
- 每次扩容后都更新:
  - `env->prog = new_prog;`
  - `insn = new_prog->insnsi + ...`
  - 见 `22511-22512`, `22535-22536`, `22567-22569`, `22640-22642`, `22772-22774`

所以它不是简单的 in-place lower pass。

### 1.7 `fixup_bpf_calls()` 在这棵树里不存在；helper call fixup 已并入其他 pass

我在 `vendor/linux-framework/kernel/bpf/` 下没有找到 `fixup_bpf_calls()` 符号。

当前 tree 的对应工作主要分散在:

1. `do_misc_fixups()`:
   - helper / kfunc / tailcall / map op / inline helper lowering
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:23355-24313`

2. `fixup_call_args()`:
   - JIT subprog split / pseudo call adjustment / callback/tailcall interpreter fallback rules
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:23066-23105`

因此对这个 tree，问题应读作:

- `do_misc_fixups()` 如何改写 `prog->insnsi`
- `fixup_call_args()` 如何在 JIT subprog 阶段继续改写/拆分程序

### 1.8 `do_misc_fixups()` 是 in-place 吗

也是 **部分 in-place，部分插入新指令**。

证据:

- 入口: `vendor/linux-framework/kernel/bpf/verifier.c:23355-24313`
- 直接改现有指令字段的例子:
  - 32-bit zext rewrite / cast normalize: `23390-23405`
  - tail call helper -> `BPF_TAIL_CALL`: `23727-23745`
  - helper call imm -> kernel function offset: `24220-24231`
  - map op helper id -> `BPF_CALL_IMM(ops->...)`: `23937-23965`
- 插入新指令序列的例子:
  - div/mod safety patch: `23407-23525`
  - userspace deref guard: `23527-23555`
  - `LD_ABS/IND` lower: `23557-23575`
  - speculation mitigation: `23577-23628`
  - `may_goto` expansion: `23630-23694`, `24251-24289`
  - kfunc/helper inlining: `23700-24219`

所以 verify 之后剩下的 `prog->insnsi` 已经远离原始用户输入。

### 1.9 `insn_aux_data` 和原始指令的对应关系只在 verifier 生命周期内存在

这是实现 `BPF_PROG_REWRITE` 时经常被忽略的一点。

1. 初始时 `orig_idx = i`:
   - `vendor/linux-framework/kernel/bpf/verifier.c:25941-25942`

2. 发生插入时，`adjust_insn_aux_data()` 会把原指令的 `orig_idx` 扩散到新插入区间:
   - `vendor/linux-framework/kernel/bpf/verifier.c:21922-21955`

3. verifier 结束后，这个映射会被清理并释放:
   - `clear_insn_aux_data(env, 0, env->prog->len);`
   - `vfree(env->insn_aux_data);`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:26191-26192`

因此:

- **内核在 load 完成后不再保留 `xlated insn -> raw/orig insn` 的映射。**
- 如果 daemon 想从 live xlated site 回补到“原始 patch offset”，当前内核里没有现成元数据可用。

### 1.10 结论

结论非常明确:

1. `prog->insnsi` **初始**是 raw insns，**完成 load 后**是 current xlated/fixed-up insns。
2. verify + fixup 后，原始 eBPF bytecode **已经丢失**。
3. 当前 tree 中没有 `orig_insns` / `orig_len` / `orig_idx map` 持久保存点。
4. 想做 `BPF_PROG_REWRITE`，**必须额外保存一份可重放的 pre-fixup baseline**。

而且这里的“额外保存一份”不能只理解成 `struct bpf_insn *orig_insnsi`；如果要真的在没有 `.bpf.o` 的前提下重放 verifier，还至少要保存:

- 原始 `prog_flags`，因为 verifier 会重新读取它们，见 `vendor/linux-framework/kernel/bpf/verifier.c:25983-25991`
- 原始 `func_info`，它稍后会被改写成 xlated offset，见 `vendor/linux-framework/kernel/bpf/verifier.c:19171-19172`, `19256-19266`
- 原始 `line_info`，它同样在后续 rewrite 中被调整，见 `vendor/linux-framework/kernel/bpf/verifier.c:19387-19388`, `vendor/linux-framework/kernel/bpf/core.c:440-458`
- 如果要从 xlated site patch 回 baseline，还要保存 `xlated -> orig` 映射

---

## 2. `bpf_insn_prepare_dump()` 的反向可用性

### 2.1 它到底做了什么

`bpf_insn_prepare_dump()` 在 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4959`.

流程很直接:

1. `kmemdup(prog->insnsi, bpf_prog_insn_size(prog), GFP_USER);`
   - 见 `4913-4916`
2. 遍历当前 xlated insns，做若干导出清洗

具体清洗包括:

1. `BPF_TAIL_CALL` -> 普通 `BPF_CALL` + `BPF_FUNC_tail_call`
   - `4921-4924`

2. `BPF_CALL_ARGS` -> 普通 `BPF_CALL`
   - `4926-4929`

3. 对无 raw dump 权限的调用者，把 call imm 清零
   - `4930-4932`

4. `BPF_PROBE_MEM` -> `BPF_MEM`
   - `4934-4937`

5. `BPF_PROBE_MEM32` -> `BPF_MEM`
   - `4939-4943`

6. `LD_IMM64` 的 kernel map pointer / direct-value pointer -> map id + off
   - `4945-4954`
   - map 反查 helper 在 `bpf_map_from_imm()`，`4875-4900`

### 2.2 它**没有**做什么

它没有做的事情，恰好决定了 dump 的不可逆性。

#### 2.2.1 它不会把 helper/kernel-call imm 还原成原始 helper id

`do_misc_fixups()` 最终把普通 helper call 的 `imm` 改成 `fn->func - __bpf_call_base`:

- `vendor/linux-framework/kernel/bpf/verifier.c:24220-24231`

对 map op helper，它甚至会改成具体 map ops 函数地址偏移:

- `vendor/linux-framework/kernel/bpf/verifier.c:23937-23965`

`bpf_insn_prepare_dump()` 对这些 call 做的仅仅是:

- 如果是 `CALL_ARGS`，把 opcode 改回 `CALL`
- 如果调用者无 raw 权限，把 `imm = 0`
- 否则原样保留 `imm`

也就是说，它**不会**把:

```text
imm = fn->func - __bpf_call_base
```

变回:

```text
imm = BPF_FUNC_xxx
```

因此 dump 出来的 helper call `imm` 与原始用户 bytecode 的差距非常大。

#### 2.2.2 它不会逆转 `convert_ctx_accesses()`

`convert_ctx_accesses()` 可能:

- 插入 prologue/epilogue
- 把 ctx load/store lower 成多条底层访问
- 把部分 load/store 转成 `PROBE_MEM*`
- 插入 `ST_NOSPEC`

见 `vendor/linux-framework/kernel/bpf/verifier.c:22480-22778`.

`bpf_insn_prepare_dump()` 最多只把 `PROBE_MEM`/`PROBE_MEM32` 还原成 `MEM`，并不会:

1. 删除插入的 prologue/epilogue
2. 把 lowered 序列重建成原始 `ctx + off`
3. 删除 `ST_NOSPEC`

#### 2.2.3 它不会逆转 `do_misc_fixups()`

`do_misc_fixups()` 可能:

- 插入 div/mod safety 序列
- 插入 helper inline 序列
- 生成 hidden subprog
- 把 helper 改成 `TAIL_CALL`
- 改写 pointer arithmetic / `may_goto`

见 `vendor/linux-framework/kernel/bpf/verifier.c:23355-24313`.

`bpf_insn_prepare_dump()` 不会把这些变化逆回去。

#### 2.2.4 它不会覆盖所有 internal opcode

`public_insntable` 只接受 UAPI opcode，再加少量公开但会被 rewrite 的 carry-over 指令，见:

- `vendor/linux-framework/kernel/bpf/core.c:1795-1815`

而解释器 jump table 明确还支持非 UAPI internal opcode，例如:

- `BPF_CALL_ARGS`
- `BPF_TAIL_CALL`
- `BPF_ST_NOSPEC`
- `BPF_PROBE_MEMSX`

见 `vendor/linux-framework/kernel/bpf/core.c:1837-1846`.

`bpf_insn_prepare_dump()` 只清洗了:

- `TAIL_CALL`
- `CALL_ARGS`
- `PROBE_MEM`
- `PROBE_MEM32`

它**没有**处理:

- `BPF_PROBE_MEMSX`
- `BPF_PROBE_MEM32SX`
- `BPF_PROBE_ATOMIC`
- `BPF_ST_NOSPEC`

这些 internal form 若原样重提，`resolve_pseudo_ldimm64()` 早期合法性检查会直接查 `bpf_opcode_in_insntable()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:21879-21883`, `vendor/linux-framework/kernel/bpf/core.c:1795-1815`.

### 2.3 dump 出来的 insns 和原始 insns 的差距有多大

不是“小差一点”，而是结构性地不等价。

差距来源至少有六层:

1. map FD 已变成 kernel map pointer，再被 dump 清洗成 map id
2. helper id 已变成 kernel call offset，dump 不会还原
3. ctx access 已 lower 成底层序列
4. verifier 可能插入 hidden subprog / prologue / epilogue / speculation fixup
5. internal opcode 只做了部分导出清洗
6. JIT subprog path 为了 later dump 还专门改过主程序解释器视图
   - `jit_subprogs()` 最后一步写着:
     - “make now unused interpreter insns from main prog consistent for later dump requests”
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:23002-23018`

因此 `xlated_prog_insns` 本质上是:

```text
current post-verifier interpreter-facing view
+ export sanitizer
```

而不是“可逆的原始输入”。

### 2.4 如果读 dump 出来的 insns，再修改后重新提交 verifier，会遇到什么问题

#### 2.4.1 helper call `imm` 语义错了

原始 verifier 对普通 helper call 期望 `imm` 是 helper id，而 dump 中往往已经是 kernel function offset，见 `vendor/linux-framework/kernel/bpf/verifier.c:24220-24231`, `vendor/linux-framework/kernel/bpf/syscall.c:4926-4932`.

#### 2.4.2 internal opcode 可能直接被 raw verifier 拒绝

如上所述，`PROBE_MEMSX` / `PROBE_MEM32SX` / `PROBE_ATOMIC` / `ST_NOSPEC` 不在 `public_insntable`，见 `vendor/linux-framework/kernel/bpf/core.c:1795-1815`, `1837-1846`.

#### 2.4.3 ctx access 已经失去原始形态

`convert_ctx_accesses()` 把原始 “`*(u32 *)(ctx + off)`” 改成更底层序列，见 `vendor/linux-framework/kernel/bpf/verifier.c:22475-22778`.

直接重提 dump，不会回到原始 ctx model。

#### 2.4.4 subprog boundary 可能已经变了

`bpf_patch_insn_data()` 会调整 `subprog_info[].start`，见 `vendor/linux-framework/kernel/bpf/verifier.c:21957-21968`, `22037-22039`.

而 `adjust_btf_func()` 最后又把 `func_info[i].insn_off` 设成**rewrite 后**的 subprog 起点，见 `vendor/linux-framework/kernel/bpf/verifier.c:19256-19266`.

所以 dump 的 subprog 布局和原始 BTF func_info 已经不是一回事。

#### 2.4.5 constant blinding 会进一步拉开差距

constant blinding 不在 verifier，而在 runtime/JIT 选择阶段:

- `bpf_prog_select_runtime()` 调 `bpf_int_jit_compile()`，见 `vendor/linux-framework/kernel/bpf/core.c:2622-2628`
- `bpf_jit_blind_constants()` 会 clone 并 patch program，见 `vendor/linux-framework/kernel/bpf/core.c:1569-1634`
- x86/arm64 JIT 都可能把 `prog` 切换到 blinded clone，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5225-5263`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2601-2638`

这也是为什么当前 `BPF_PROG_JIT_RECOMPILE` 明确拒绝 `prog->blinded`:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:652-658`

### 2.5 结论

`bpf_insn_prepare_dump()` 只能作为:

- live xlated analysis input
- 调试/可视化导出

不能作为:

- `BPF_PROG_REWRITE` 的 verifier replay baseline
- “没有 `.bpf.o` 时的原始程序替身”

---

## 3. 方案 A / B / C 对比

## 3.1 方案 A: kernel 额外保存原始 bytecode

### 3.1.1 纯 `orig_insnsi` 版不闭环

用户提出的最直观版本是:

```c
struct bpf_prog {
    struct bpf_insn *insnsi;
    struct bpf_insn *orig_insnsi;
    u32 orig_len;
};
```

这个方向的**基础判断是对的**: 现在原始 raw bytecode 确实没有保留，必须额外保存一份。

但按当前内核实际数据流，**只保存这三项还不够**。

原因:

1. verifier 重放还依赖 `prog_flags`，见 `vendor/linux-framework/kernel/bpf/verifier.c:25983-25991`
2. raw `func_info` / `line_info` 会被后续 rewrite 改成 xlated offset，见 `vendor/linux-framework/kernel/bpf/verifier.c:19171-19172`, `19256-19266`, `19387-19388`
3. 原始 map 引用依赖 FD / fd_array；live rewrite 时这些 FD 已经不在了
   - pseudo map idx 通过 `fd_array` 取 FD，见 `vendor/linux-framework/kernel/bpf/verifier.c:21823-21837`
4. module kfunc 也可能依赖 `fd_array` 中的 module BTF FD
   - `kfunc offset > 0 without fd_array is invalid`
   - 见 `vendor/linux-framework/kernel/bpf/verifier.c:3268-3278`

所以“纯 raw user buffer”并不是最小**可重放**状态。

### 3.1.2 推荐的 A'：保存 kernel-owned rewrite baseline，而不是仅保存用户原始 buffer

最小闭环版本应保存的是:

```c
struct bpf_prog_aux {
    struct bpf_insn *rewrite_insns;      /* pre-fixup verifier baseline */
    u32 rewrite_len;
    u32 rewrite_prog_flags;
    struct bpf_func_info *rewrite_func_info;
    u32 rewrite_func_info_cnt;
    struct bpf_line_info *rewrite_linfo;
    u32 rewrite_nr_linfo;
    u32 *xlated_to_rewrite;              /* optional but strongly recommended */
    u32 xlated_to_rewrite_cnt;
};
```

为什么建议放 `aux` 而不是 `struct bpf_prog` 本体:

1. `bpf_prog_realloc()` 会搬动 `struct bpf_prog`，但复用 `aux`，见 `vendor/linux-framework/kernel/bpf/core.c:272-284`
2. `bpf_prog_main_aux()` 已经是 main/subprog 共享状态中心，见 `vendor/linux-framework/include/linux/bpf.h:1846-1853`
3. `jit_recompile_mutex` 本来就在 `aux`，live rewrite 也天然应挂在这里，见 `vendor/linux-framework/include/linux/bpf.h:1737`

### 3.1.3 A' 的可行性判断

**可行，而且这是唯一合理起点。**

但要强调两点:

1. A' 解决的是“re-verify baseline”问题，不是“live commit”问题。
2. live commit 最好不要替换整个 `struct bpf_prog`，而应复用现有 JIT image swap 机制，见第 4 节。

### 3.1.4 内存开销

只算 insns:

- `struct bpf_insn` 是 8 字节，见 `vendor/linux-framework/include/uapi/linux/bpf.h:80-86`
- `bpf_prog_insn_size(prog) = prog->len * sizeof(struct bpf_insn)`，见 `vendor/linux-framework/include/linux/filter.h:1020-1023`

所以额外保存一份 baseline insns 的开销就是:

```text
8 * rewrite_len bytes
```

换算:

- 100 insns: 800 B
- 1,000 insns: 8 KB
- 3,000 insns: 24 KB
- 7,000 insns: 56 KB
- 10,000 insns: 80 KB

如果同时保存:

- `func_info`: `8 * func_info_cnt` bytes，见 `vendor/linux-framework/include/uapi/linux/bpf.h:7545-7548`
- `line_info`: `16 * nr_linfo` bytes，见 `vendor/linux-framework/include/uapi/linux/bpf.h:7553-7558`
- `xlated_to_rewrite`: `4 * xlated_len` bytes

则 debug-rich 程序的 metadata 开销可能比单纯 insns 还大，尤其当 `nr_linfo` 接近 insn 数量时。

### 3.1.5 A' 的主要障碍

1. 要决定 baseline capture 时机:
   - 太早: 还是 FD/fd_array 语义，不可重放
   - 太晚: 已经进了 `convert_ctx_accesses()` / `do_misc_fixups()`
2. 必须保留 raw/BTF metadata 和最好保留 `xlated_to_rewrite` 映射
3. live commit 需要保证 current program identity 不变

**结论**: A' 是必要方案，但需要和 C 的 commit 机制结合，不能只加 `orig_insnsi` 三个字段就结束。

## 3.2 方案 B: 直接对 xlated insns 做 patch + re-verify

### 3.2.1 不可行的核心原因

**在当前内核结构下，这不是最小改动方案。**

原因:

1. xlated 中包含 internal-form opcode，而 verifier 入口只认 `public_insntable`
   - `vendor/linux-framework/kernel/bpf/core.c:1795-1815`, `1837-1846`
2. `bpf_insn_prepare_dump()` 只部分清洗，见 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4959`
3. `env->insn_aux_data.orig_idx` 映射在 load 完成后已释放，见 `vendor/linux-framework/kernel/bpf/verifier.c:26191-26192`
4. 当前 verifier 没有任何“从 post-fixup internal IR 重新验证”的 API
5. `func_info` / `line_info` / `subprog_info` / `poke_tab` 都是围绕当前 xlated layout 构建的

### 3.2.2 增量验证有 API 吗

没有。

当前 tree 中:

- `bpf_prog_load()` 总是 `bpf_check()` + `bpf_prog_select_runtime()`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3089-3099`
- verifier 复杂度按 `env->insn_processed` 计，并受 `BPF_COMPLEXITY_LIMIT_INSNS` 约束，见 `vendor/linux-framework/kernel/bpf/verifier.c:21224-21231`, `vendor/linux-framework/include/linux/bpf.h:2319`

我没有在这棵树里找到:

- partial verifier reuse
- path-local revalidation
- old `insn_aux_data` cache replay API

### 3.2.3 结论

方案 B 只有在你愿意新增一个“internal xlated IR verifier mode”时才有可能成立。

这意味着至少要新增:

1. internal opcode whitelist
2. xlated metadata replay API
3. subprog / BTF / linfo / poke descriptor 重新建模

这已经远远超过“最小改动”。

## 3.3 方案 C: 基于现有 `BPF_PROG_JIT_RECOMPILE` 扩展

### 3.3.1 现有 `BPF_PROG_JIT_RECOMPILE` 做了什么

UAPI:

- `BPF_PROG_JIT_RECOMPILE` enum: `vendor/linux-framework/include/uapi/linux/bpf.h:996`
- attr union: `vendor/linux-framework/include/uapi/linux/bpf.h:2010-2017`

syscall dispatch:

- `vendor/linux-framework/kernel/bpf/syscall.c:6332-6334`

实现入口:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:584-747`

它的语义是:

1. 拿 live prog
2. 锁 `main_aux->jit_recompile_mutex`
3. snapshot 当前 JIT / `insnsi`
4. 重新 JIT 当前 xlated images
5. staged commit 新 image
6. regenerate trampolines
7. `synchronize_rcu()` 后释放旧 image

### 3.3.2 它能否直接扩成 bytecode rewrite + re-verify

**不能直接扩，但它是最好的 commit substrate。**

原因:

1. 现有 rollback state 只保存:
   - `bpf_func`
   - `priv_stack_ptr`
   - `extable`
   - `jit_data`
   - `insnsi_copy`
   - `insn_cnt`
   - `jited_len`
   - `num_exentries`
   - `fp_start/fp_end`
   - `jited/exception_boundary`
   - 见 `vendor/linux-framework/kernel/bpf/jit_directives.c:14-28`

2. 它**没有** snapshot:
   - `used_maps`
   - `kfunc_tab`
   - `kfunc_btf_tab`
   - `func_info`
   - `linfo`
   - `func[]` topology
   - `verified_insns`
   - `stack_depth`

3. 所以它天然假设:
   - xlated layout 不变
   - aux topology 不变
   - 只是同一组 insns 的 native lowering 变化

这正是当前 POC 里它好用的原因，也是它不能单独承载 bytecode rewrite 的原因。

### 3.3.3 结论

方案 C 的正确用法是:

- **拿来复用 live image swap / rollback / trampoline regen / RCU 释放**
- **不要拿它替代 raw baseline 保存和 verifier replay**

## 3.4 最终裁决

| 方案 | 可行性 | 是否最小改动 | 结论 |
| --- | --- | --- | --- |
| A: 仅保存 `orig_insnsi` | 基础方向对，但不闭环 | 否 | 不够，需要扩成 A' |
| A': 保存 kernel-owned rewrite baseline + 原始 metadata | 可行 | 是 | **推荐** |
| B: 直接 patch xlated 再 re-verify | 结构性不可行 | 否 | 排除 |
| C: 单独扩 `BPF_PROG_JIT_RECOMPILE` | 不足以闭环 | 否 | 只适合作为 commit substrate |

**推荐方案**:

> `A' + C`: 保存可重放 baseline，full re-verify 在临时 candidate 上完成，live commit 复用 `jit_directives.c` 的 image swap 机制。

---

## 4. 原子替换 live program 的内核机制

## 4.1 当前已有机制: 只替换 JIT image，不替换 `struct bpf_prog`

这是现有 tree 里最重要的工程先例。

### 4.1.1 `BPF_PROG_JIT_RECOMPILE` 的 commit

`bpf_jit_recompile_prog_images()` 的 commit path 在 `vendor/linux-framework/kernel/bpf/jit_directives.c:311-582`.

关键步骤:

1. staged re-JIT 每个 image
2. `bpf_jit_recompile_commit(image_prog);`
   - `vendor/linux-framework/kernel/bpf/jit_directives.c:480-486`
3. 对主 prog 更新 `bpf_func`
   - `498-501`
4. regenerate trampolines
   - `503-514`
5. `synchronize_rcu()`
   - `516-522`
6. 释放旧 header / priv stack / 更新 kallsyms
   - `524-547`

### 4.1.2 arch commit 真正更新了什么

x86:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5495-5522`

arm64:

- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2908-2933`

两者都做了类似事情:

1. 更新 jited linfo pointer
2. 更新 `priv_stack_ptr` / `extable` / `num_exentries`
3. 更新 `jited_len`
4. 最终 `smp_store_release(&prog->bpf_func, staged_func);`

注意这里不是 `xchg(&prog->bpf_func, ...)`，而是 `smp_store_release()`。

### 4.1.3 trampoline 处理

`bpf_prog_regenerate_trampolines()` 在 `vendor/linux-framework/kernel/bpf/trampoline.c:905-965`.

它会遍历所有关联 trampoline，并根据场景:

- retarget extension
- retarget target
- or update linked prog image

对应 text poke / trampoline retarget helper 在:

- `bpf_trampoline_activate_extension()`: `826-833`
- `bpf_trampoline_retarget_extension()`: `835-848`

### 4.1.4 旧 image 生命周期

旧 program/text 的 सामान्य释放路径:

- `bpf_prog_put()` -> `__bpf_prog_put()` -> `__bpf_prog_put_noref()`
  - `vendor/linux-framework/kernel/bpf/syscall.c:2412-2429`, `2377-2396`
- 最终 `call_rcu()` / `call_rcu_tasks_trace()` 后才到 `__bpf_prog_put_rcu()`
  - `vendor/linux-framework/kernel/bpf/syscall.c:2366-2396`

而 trampoline image 自己也使用:

- `call_rcu_tasks_trace()`
- `call_rcu_tasks()`
- `percpu_ref_kill()`

来保证旧 trampoline 退出后再 free，见 `vendor/linux-framework/kernel/bpf/trampoline.c:573-643`.

### 4.1.5 结论

当前 tree 的 live-safe pattern 已经非常明确:

1. 保持同一个 `struct bpf_prog`
2. 更新其 JIT entry / metadata
3. 必要时 text poke / trampoline retarget
4. `synchronize_rcu()` 后回收旧 image

## 4.2 为什么不建议替换整个 `struct bpf_prog`

### 4.2.1 `bpf_link_update()` 不是通用答案

`link_update()` 只是把**某一个 link** 指向的 program 换成另一个已有 `struct bpf_prog`:

- `vendor/linux-framework/kernel/bpf/syscall.c:5817-5868`

它没有解决:

- prog_array tail callee
- freplace target / extension
- non-link attach family
- open fd / idr identity

### 4.2.2 prog array 没有“反向 holder 列表”

`struct bpf_prog_aux` 只有:

- `prog_array_member_cnt`
- `ext_mutex`
- 见 `vendor/linux-framework/include/linux/bpf.h:1716-1717`

`prog_array_member_cnt` 的维护在:

- 加入时 `++`: `vendor/linux-framework/kernel/bpf/arraymap.c:978-982`
- 删除时 `--`: `vendor/linux-framework/kernel/bpf/arraymap.c:1000-1002`

这只是计数，不是 holder list。

而 `struct bpf_prog_array` 的 RCU 使用注释明确说明:

- `struct bpf_prog_array *` 应用 `xchg()` 替换
- CPU 正并行遍历数组
- 见 `vendor/linux-framework/include/linux/bpf.h:2410-2418`

因此“把旧 `struct bpf_prog *` 全局替换成新 `struct bpf_prog *`”在当前树里没有统一基础设施。

### 4.2.3 freplace / trampoline / dst_prog 也会变复杂

相关状态都挂在 `aux` 上:

- `dst_prog`, `dst_trampoline`: `vendor/linux-framework/include/linux/bpf.h:1695-1699`
- `is_extended`: `1710`

trampoline side 也直接持有 `extension_prog`，见:

- `vendor/linux-framework/include/linux/bpf.h:1357`
- `vendor/linux-framework/kernel/bpf/trampoline.c:929-950`

这再次说明:

- **whole-prog replacement 需要重新连很多 cross-reference**
- **same-object image swap 则可以复用当前所有引用**

## 4.3 对 `BPF_PROG_REWRITE` 的直接建议

v1 直接复用现有模式:

1. 保持 `prog` / `prog->aux` / `prog->aux->id` / open fd 不变
2. 只更新:
   - `prog->insnsi`（以及 subprog `func[i]->insnsi`）
   - `prog->tag/digest`
   - 若干 aux 标量
   - JIT image / `bpf_func` / extable / kallsyms
3. 继续走:
   - `bpf_jit_recompile_snapshot()`
   - `bpf_jit_recompile_prog_images()`
   - `bpf_prog_regenerate_trampolines()`
   - `synchronize_rcu()`

如果 rewrite 后 verified topology 变了，则 v1 直接拒绝，而不是尝试 whole-prog replace。

---

## 5. Re-verify 的性能开销

## 5.1 源码层面的确定结论

### 5.1.1 full re-verify 是不可避免的

当前 tree 中:

- `bpf_prog_load()` 无条件 `bpf_check()`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3089-3091`
- verifier 之后无条件 `bpf_prog_select_runtime()`，见 `3094-3096`

所以只要是 bytecode-level rewrite，就天然进入:

```text
patch
-> full verifier
-> runtime/JIT
```

### 5.1.2 verifier 复杂度不是简单按 raw insn 数线性计

verifier 的核心复杂度指标是:

- `env->insn_processed`
- 每处理一个状态下的 insn 就递增
- 超过 `BPF_COMPLEXITY_LIMIT_INSNS` 就失败

见:

- `vendor/linux-framework/kernel/bpf/verifier.c:21224-21231`
- `vendor/linux-framework/include/linux/bpf.h:2319`

这意味着:

- 1000 raw insns 的 straight-line 程序，可能很快
- 1000 raw insns 的 state-heavy CFG 程序，可能很慢

### 5.1.3 verifier-only 时间内核里有统计，但不是持久字段

`bpf_check()` 记录:

- `env->verification_time = ktime_get_ns() - start_time;`
- 见 `vendor/linux-framework/kernel/bpf/verifier.c:26111`

并在 `BPF_LOG_STATS` 时打印:

- `verification time %lld usec`
- `processed %d insns ...`
- 见 `vendor/linux-framework/kernel/bpf/verifier.c:24742-24763`

`prog->aux->verified_insns = env->insn_processed;`

- `vendor/linux-framework/kernel/bpf/verifier.c:26113`

但 `verification_time` 本身不会常驻导出到 `prog_info`。

## 5.2 对典型程序和大程序的量级判断

这里要区分“源码保证”和“经验推断”。

### 5.2.1 100-1000 insns

源码层面只能确定:

- 上限由 `insn_processed` 决定，不是由 raw 长度决定
- 没有增量验证 API

经验上，若程序结构简单、没有大规模 state explosion:

- 100-1000 insn 的 full re-verify 往往是 **几百微秒到几毫秒**

这是**推断**，不是源码保证。

### 5.2.2 7000+ insns（Cilium/Calico 级）

源码层面仍只能确定:

- full verifier 一定重跑
- worst-case 可能远超线性

经验上，大型 datapath 程序的 full reload 应按 **数毫秒到数十毫秒** 预期，而不是几十微秒。

这同样是**推断**。

仓库里现有本地测量也支持这个数量级判断:

- `docs/tmp/2026-03-12/recompile-overhead-measurement.md:185-203`
  - 当前 `BPF_PROG_JIT_RECOMPILE` syscall 中位数大约 `20-64 us`
- `docs/tmp/bpf_program_replacement_research_20260320.md:698-767`
  - 一个 3638-insn Cilium `cil_to_netdev` 的 steady-state `compile_ns` 约 `26.4 ms`（end-to-end compile-only path）

所以如果从现在的 JIT-only recompile 转成 full re-verify:

```text
tens of microseconds
-> milliseconds
```

是合理预期。

## 5.3 当前 verifier 有增量验证可能吗

**当前 tree 没有现成 API。**

从 `bpf_check()` 的组织方式看，它每次都重新做:

- CFG
- SCC
- live reg
- main/subprog checking
- rewrite passes
- BTF adjustment

见 `vendor/linux-framework/kernel/bpf/verifier.c:26004-26109`.

没有任何接口允许:

- “给旧 verifier state + patch diff”
- “只重新验证某个局部 region”
- “保留旧 explored_states / aux_data / subprog_info”

因此 v1 `BPF_PROG_REWRITE` 不应承诺增量验证。

---

## 6. 推荐的最小内核改动方案

## 6.1 设计目标重述

目标不是“通用 whole-prog replacement 平台”，而是:

1. privileged daemon
2. 在没有 `.bpf.o` 的前提下
3. patch live BPF 的 bytecode-level baseline
4. full re-verify
5. 复用现有 live JIT image swap
6. 对应用透明，fd/id/link/prog_array 引用尽量不变

## 6.2 新增命令与 attr

UAPI 可以沿用户草案走，但我建议明确 offset 语义。

### 6.2.1 建议 UAPI

```c
enum bpf_cmd {
    ...
    BPF_PROG_REWRITE,
};

struct bpf_prog_patch {
    __u32 insn_off;          /* baseline offset, not live xlated offset */
    __u32 old_len;
    __u32 new_len;
    __aligned_u64 new_insns; /* pointer to struct bpf_insn[new_len] */
};

struct bpf_prog_rewrite_attr {
    __u32 prog_fd;
    __u32 patch_count;
    __aligned_u64 patches;
    __u32 flags;
    __u32 log_level;
    __u32 log_size;
    __aligned_u64 log_buf;
};
```

### 6.2.2 建议再加一个 offset-mode flag

如果 daemon 分析的是 live `xlated_prog_insns`，那它天然得到的是 **xlated offset**，不是 baseline/raw offset。

而当前内核在 load 完成后已经把 `orig_idx` map 释放了，见 `vendor/linux-framework/kernel/bpf/verifier.c:26191-26192`.

因此二选一:

1. 保持用户草案，要求 daemon patch offset 基于 kernel-exported baseline dump
2. 再加一个 `BPF_F_REWRITE_OFF_XLATED`，内核用保存的 `xlated_to_rewrite[]` 翻译

为了真正“无 `.bpf.o`、靠 live 分析”，**推荐加第 2 个 flag**。

## 6.3 需要额外保存什么

### 6.3.1 最小建议字段

建议新增到 `struct bpf_prog_aux`:

```c
struct bpf_prog_aux {
    ...
    struct bpf_insn *rewrite_insns;
    u32 rewrite_len;
    u32 rewrite_prog_flags;

    struct bpf_func_info *rewrite_func_info;
    u32 rewrite_func_info_cnt;
    struct bpf_line_info *rewrite_linfo;
    u32 rewrite_nr_linfo;

    u32 *xlated_to_rewrite;   /* optional but highly recommended */
    u32 xlated_to_rewrite_cnt;
};
```

如果想保留用户草案名字，也可以叫 `orig_insnsi` / `orig_len`，但从实现语义上，**更准确的名字是 `rewrite_*`**:

- 它未必是字节级的“原始用户缓冲区”
- 它应该是“内核可重放的 pre-fixup baseline”

### 6.3.2 capture 时机

建议在 `bpf_check()` 内部做两次持久化:

1. `check_btf_info()` 完成后，先复制 raw `func_info` / `line_info`
   - 它们此时还是 user/raw offset 版本
2. 在 `resolve_pseudo_ldimm64()` 之后、`instruction rewrites happen after this point` 之前，复制 baseline insns
   - 即在 `vendor/linux-framework/kernel/bpf/verifier.c:26020-26023` 之后、`26076-26077` 之前

这样得到的 baseline 已经摆脱用户 FD 依赖里最麻烦的 map-FD 阶段，但还没进入 ctx/fixup rewrites。

### 6.3.3 为什么不直接在 `bpf_prog_load()` 里保存 raw copy

直接在 `bpf_prog_load()` `copy_from_bpfptr()` 之后保存 raw copy:

- 简单
- 但会把原始 map FD / fd_array 偏移也一并保存

这在 live rewrite 时并不好重放，因为原始 FDs 并不稳定。

所以最小闭环不是“保存最早的 raw user buffer”，而是“保存 verifier 仍可重放、但已 kernel-own 关键引用的 baseline”。

## 6.4 `BPF_PROG_REWRITE()` 的建议流程

### 6.4.1 高层流程

```c
static int bpf_prog_rewrite(union bpf_attr *attr)
{
    struct bpf_prog *live;
    struct bpf_prog_aux *main_aux;
    struct bpf_prog *cand = NULL;
    struct rewrite_baseline base;
    struct bpf_jit_recompile_rollback_state rollback = {};
    int err;

    live = bpf_prog_get(attr->rewrite.prog_fd);
    main_aux = bpf_prog_main_aux(live);

    mutex_lock(&main_aux->jit_recompile_mutex);

    err = bpf_prog_rewrite_precheck(live, attr);
    if (err)
        goto out_unlock;

    err = bpf_jit_recompile_snapshot(live, &rollback);
    if (err)
        goto out_unlock;

    err = bpf_prog_build_rewrite_candidate(live, attr, &cand);
    if (err)
        goto out_restore;

    err = bpf_prog_rewrite_check_compat(live, cand);
    if (err)
        goto out_free_cand;

    err = bpf_prog_copy_candidate_into_live(live, cand);
    if (err)
        goto out_restore;

    err = bpf_jit_recompile_prog_images(live);
    if (err)
        goto out_restore;

    err = 0;
out_free_cand:
    bpf_prog_free_internal(cand);
out_restore:
    if (err)
        bpf_jit_recompile_restore(&rollback);
out_unlock:
    mutex_unlock(&main_aux->jit_recompile_mutex);
    bpf_prog_put(live);
    return err;
}
```

### 6.4.2 step 1: precheck

建议直接继承 `BPF_PROG_JIT_RECOMPILE` 的限制:

1. privileged only
   - 参考 `vendor/linux-framework/kernel/bpf/jit_directives.c:607-608`
2. `bpf_jit_supports_recompile()`
   - `602-603`
3. `prog->jited`
   - `637-641`
4. reject blinded progs
   - `652-658`
5. reject live struct_ops
   - `644-649`

此外 v1 再加:

1. baseline metadata 已保存，否则 `-EOPNOTSUPP`
2. 如果 program 使用 module kfunc (`offset > 0`) 且未保存模块 BTF reloc metadata，则 `-EOPNOTSUPP`
3. patch list 必须:
   - sorted
   - non-overlapping
   - `old_len > 0`
   - `new_len > 0`

### 6.4.3 step 2: build temporary candidate

candidate 不应直接复用 live prog，而应新建临时 prog，再 full verifier。

建议复用/调用的现有函数:

1. `bpf_prog_alloc()`
   - `vendor/linux-framework/include/linux/filter.h:1121-1124`
2. `find_prog_type()`
   - `vendor/linux-framework/kernel/bpf/syscall.c:2280-2307`
3. `security_bpf_prog_load()`
   - 当前 load 路径在 `3085-3087`
4. `bpf_check()`
   - `3089-3091`

candidate 初始化时应复制 live program 的 stable context:

- `type`
- `expected_attach_type`
- `sleepable`
- `aux->attach_btf`
- `aux->attach_btf_id`
- `aux->dst_prog`
- `aux->token`
- `aux->dev_bound`
- `aux->xdp_has_frags`

并且 `attr.prog_flags` 不能用“当前 daemon 权限”推断，而应使用保存的 `rewrite_prog_flags`，因为 verifier 的 privilege/alignment 路径依赖这些 flags，见 `vendor/linux-framework/kernel/bpf/verifier.c:25949-25953`, `25983-25991`.

### 6.4.4 step 3: apply patches to baseline

不建议直接在 live `prog->insnsi` 上 patch。

建议做法:

1. 从 `rewrite_insns` clone 出一份 baseline
2. 在 clone 上应用 patch list
3. 同步调整 `rewrite_func_info` / `rewrite_linfo`
4. 再把这个结果喂给 temporary `bpf_check()`

这里最好新增一个通用 helper，例如:

```c
struct bpf_prog *bpf_prog_replace_insns(struct bpf_prog *prog,
                                        u32 off, u32 old_len,
                                        const struct bpf_insn *new_insns,
                                        u32 new_len);
```

现有内核只直接提供:

- `bpf_patch_insn_single()` (`1 -> n`) `vendor/linux-framework/kernel/bpf/core.c:460-519`
- `bpf_remove_insns()` (`n -> 0`) `vendor/linux-framework/kernel/bpf/core.c:521-535`

v1 若想缩短改动，也可以限制 patch 语义为:

- `old_len == 1`

这样直接复用 `bpf_patch_insn_single()` 即可。

### 6.4.5 step 4: compatibility check

这是 v1 成败关键。

为了避免 whole-prog replacement，candidate 通过 verifier 后必须满足:

1. `cand->len == live->len`
2. `cand->aux->func_cnt == live->aux->func_cnt`
3. `cand->aux->real_func_cnt == live->aux->real_func_cnt`
4. 每个 `cand->aux->func[i]->len == live->aux->func[i]->len`
5. `used_maps` 集合相同
6. `kfunc_tab` 形状相同
7. `size_poke_tab` 相同
8. `func_info_cnt` / `nr_linfo` 相同

换句话说，v1 要求:

```text
verified topology invariant
```

这样 live object graph 不用换，只需要更新同一批对象的 insn bytes / scalar metadata / JIT image。

如果 candidate 打破了这些不变量，就返回 `-EXDEV` 或 `-EOPNOTSUPP`。

### 6.4.6 step 5: copy candidate into live

在 `jit_recompile_mutex` 下，把 candidate 的以下内容复制到 live:

1. main prog `insnsi`
2. 每个 `func[i]->insnsi`
3. `tag/digest`
4. `aux->stack_depth`
5. `aux->verified_insns`
6. 其他受 verifier 影响但 v1 允许变化的标量:
   - `tail_call_reachable`
   - `changes_pkt_data`
   - `might_sleep`
   - `func_proto_unreliable`
   - `exception_boundary`

之所以必须做 snapshot/rollback，是因为现有 `bpf_jit_recompile_snapshot()` 只保存了 JIT state 和 `insnsi_copy`，并不自动覆盖这些额外标量，见 `vendor/linux-framework/kernel/bpf/jit_directives.c:14-28`, `88-149`.

所以 v1 需要:

1. 扩展 rollback state 保存必要 aux 标量
2. 或者更保守: 在 JIT commit 成功之前不要覆盖 live 的这些标量

### 6.4.7 step 6: live re-JIT + swap

这一步直接复用现有 `jit_directives.c`:

1. `bpf_jit_recompile_prog_images(live)`
2. `bpf_prog_regenerate_trampolines(live, old_prog_func)`
3. `synchronize_rcu()`

现有实现已经包含:

- rollback
- shadow ksym
- old header / old priv stack 生命周期管理

见 `vendor/linux-framework/kernel/bpf/jit_directives.c:429-547`.

### 6.4.8 step 7: baseline update

成功后应把保存的 baseline 也更新到“patched baseline”版本。

否则下一次 rewrite 还是从旧 baseline 出发，会丢失已提交 patch。

即:

```text
rewrite_insns := patched baseline
rewrite_func_info := patched baseline func_info
rewrite_linfo := patched baseline line_info
```

## 6.5 为什么这个方案比“whole-prog replacement”小

因为它只新增两类能力:

1. baseline 持久化
2. candidate verifier replay

而 live commit 完全复用已有 JIT recompile substrate。

如果去做 whole-prog replacement，还要额外解决:

- fd/id identity
- link/prog_array/freplace/trampoline 全局引用替换
- old prog delayed free

那会明显超过 v1 的“最小内核改动”目标。

---

## 7. 与 `kinsn` 的配合

## 7.1 当前 tree 没有 `kinsn` 机制

我在 `vendor/linux-framework/kernel/bpf` / `include/linux` 里没有找到任何 `kinsn` 注册接口。

当前 verifier 的 opcode 接受面仍然是硬编码闭集:

- `bpf_opcode_in_insntable()` `vendor/linux-framework/kernel/bpf/core.c:1795-1815`
- `resolve_pseudo_ldimm64()` 早期用它拒绝未知 opcode，`vendor/linux-framework/kernel/bpf/verifier.c:21879-21883`

所以在当前 tree 中，`kinsn` 还是 **future work / separate subsystem**，不是现成能力。

## 7.2 如果未来有 `kinsn`，`BPF_PROG_REWRITE` 如何配合

只有在以下前提都成立时，`BPF_PROG_REWRITE` 才能接 `kinsn`:

1. verifier opcode whitelist 接受 `kinsn`
2. verifier 能为 `kinsn` 建模
3. JIT backend 能 emit `kinsn`
4. dump/disasm/tooling 能认识 `kinsn`

在这个前提下，`BPF_PROG_REWRITE` 的配合方式很直接:

1. daemon 读 live xlated
2. 定位优化 site
3. 构造 baseline patch，把普通序列替换成 `kinsn`
4. `BPF_PROG_REWRITE`
5. 内核 full re-verify + re-JIT + live swap

但要强调:

- **`BPF_PROG_REWRITE` 不会降低 `kinsn` 本身的 verifier/JIT 集成复杂度**
- 它只是提供“把含 `kinsn` 的新 baseline 原子切到 live program”的机制

因此 `kinsn` 是 `BPF_PROG_REWRITE` 的可选上层，而不是后者的前提。

---

## 8. 行数估计

下面给的是 **restricted v1** 估计:

- 仅支持 JITed + recompile-capable arch
- 仅支持保存 baseline 后的 full re-verify
- 仅在 verified topology invariant 时提交
- 不做 whole-prog replacement

| 修改点 | 文件 | 估计行数 |
| --- | --- | ---: |
| 新 UAPI command + attr + patch struct | `include/uapi/linux/bpf.h` | 30 |
| `struct bpf_prog_aux` baseline fields | `include/linux/bpf.h` | 18 |
| load/verifier baseline capture | `kernel/bpf/verifier.c` | 90 |
| baseline free path | `kernel/bpf/core.c` / `kernel/bpf/syscall.c` | 35 |
| 新 syscall dispatch + `*_LAST_FIELD` | `kernel/bpf/syscall.c` | 18 |
| patch-list copy/validate/apply helpers | `kernel/bpf/syscall.c` or new helper file | 95 |
| temp candidate build + synthetic attr + `bpf_check()` replay | `kernel/bpf/syscall.c` | 120 |
| compatibility check + live-copy helpers | `kernel/bpf/syscall.c` / `kernel/bpf/jit_directives.c` | 80 |
| rollback state 扩展（tag/aux scalar 等） | `kernel/bpf/jit_directives.c` | 55 |
| 复用/导出 internal re-JIT helper | `kernel/bpf/jit_directives.c` | 40 |
| **总计** |  | **581** |

如果再加上:

- `BPF_F_REWRITE_OFF_XLATED`
- `xlated_to_rewrite[]` 保存/导出
- module-kfunc reloc metadata

再加大约 **120-180 行**。

如果要做 unrestricted v2:

- 允许 verified topology 变化
- 允许 whole-prog replacement

那很容易超过 **1000 行**，而且会跨更多 attach family。

---

## 9. 风险和障碍

## 9.1 原始 bytecode 之外，还要保存更多 load context

这是本题最关键的隐藏障碍。

只保存 `orig_insnsi` 不够，因为还需要:

1. `prog_flags`
2. raw `func_info`
3. raw `line_info`
4. 最好还有 `xlated -> baseline` map

否则 daemon 无法在没有 `.bpf.o` 的条件下准确 patch。

## 9.2 map / kfunc / fd_array 语义

原始用户输入里:

- map pseudo load 可能是 FD 或 fd_array idx，见 `vendor/linux-framework/kernel/bpf/verifier.c:21823-21837`
- module kfunc 也可能依赖 fd_array 中的 BTF FD，见 `3268-3278`

所以 baseline 如果保存得太早，就不是真正可重放的 live rewrite IR。

## 9.3 full re-verify 延迟

这不是 `BPF_PROG_JIT_RECOMPILE` 现在的几十微秒路径，而是:

- full verifier
- full JIT
- trampoline regen

因此 daemon 应按控制面操作设计，而不是按热路径每 packet/flow 触发设计。

## 9.4 并发 rewrite

当前 tree 已有 `jit_recompile_mutex`:

- `vendor/linux-framework/include/linux/bpf.h:1737`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:615-619`

`BPF_PROG_REWRITE` 最小实现应直接复用这把锁，防止:

1. 两个 rewrite 并发
2. rewrite 与 `BPF_PROG_JIT_RECOMPILE` 并发

## 9.5 subprogram / tailcall / trampoline 一致性

这是 v1 必须坚持 topology invariant 的原因。

一旦 verified topology 变化，就会牵连:

- `func[]`
- `real_func_cnt`
- `poke_tab`
- `subprog_start`
- `exception_callback_subprog`
- trampoline target layout

现有 `BPF_PROG_JIT_RECOMPILE` 只处理 image 变化，不处理这些 graph-level 变化。

## 9.6 constant blinding

当前 recompile path 已明确拒绝 `prog->blinded`:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:652-658`

`BPF_PROG_REWRITE` v1 应完全继承这一限制。

## 9.7 BTF / func_info / line_info

如果不保存 raw copies，就无法重放 verifier。

如果保存了，但 rewrite 导致 topology 变化，则还要重新生产/替换:

- `func_info`
- `line_info`
- `jited_linfo`

这会把 v1 迅速推向 whole-prog replacement 复杂度。

## 9.8 `bpftool prog dump` 的可读性

rewrite 成功后，`bpftool prog dump xlated` 仍然只会看到:

- current post-verifier xlated view
- 再经过 `bpf_insn_prepare_dump()` 的 partial sanitize

不会自动显示:

- baseline patch 前后的 raw diff
- daemon 提交的 patch list

所以如果工具可读性重要，后续应考虑再暴露:

1. saved baseline dump
2. optional rewrite history / generation counter

---

## 最终结论

围绕用户最关心的前提，结论可以压缩成一句话:

> **verify + fixup 后，原始 eBPF bytecode 在当前 `struct bpf_prog` 里已经丢失；`prog->insnsi` 只剩下 current xlated/fixed-up 指令流，因此 `BPF_PROG_REWRITE` 必须额外保存一份 kernel-owned pre-fixup baseline，且 live commit 应复用现有 `BPF_PROG_JIT_RECOMPILE` 的 image swap/RCU/trampoline 机制。**

如果追求最小改动，推荐的 v1 是:

1. 保存 `rewrite_insns + rewrite_prog_flags + raw func/line info`
2. 最好保存 `xlated_to_rewrite[]`
3. `BPF_PROG_REWRITE` 在 temporary candidate 上 full `bpf_check()`
4. 只在 verified topology invariant 时提交
5. live commit 复用 `jit_directives.c`
6. 直接拒绝:
   - non-JITed
   - recompile-unsupported arch
   - blinded
   - live struct_ops
   - topology-changing rewrite

这条路径能做到:

- 无需 `.bpf.o`
- privileged daemon control-plane 可用
- 对应用透明
- 内核改动控制在约 600 行量级

但它的边界也很明确:

- **不是通用 whole-prog replacement**
- **不是 xlated dump 直接回灌**
- **不是增量 verifier**
- **不是零延迟操作**


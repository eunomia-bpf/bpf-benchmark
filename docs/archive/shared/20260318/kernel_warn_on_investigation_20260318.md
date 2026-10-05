# Tetragon E2E recompile 触发 `tailcall_target_stable` WARNING 调查

日期：2026-03-18

## 1. WARNING 的根因分析

### 1.1 `WARN_ON_ONCE(READ_ONCE(poke->tailcall_target_stable))` 在检查什么

`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:881-916` 的 `bpf_tail_call_direct_fixup()` 会在 JIT final image 已生成后，把 direct tailcall 的占位 NOP/JMP patch 成真实 target，并在最后：

- `WRITE_ONCE(poke->tailcall_target_stable, true);`

这里的 `tailcall_target_stable` 不是普通调试位，而是 tailcall prog-array 热补丁路径的发布标志。`vendor/linux-framework/kernel/bpf/arraymap.c:1124-1144` 的注释写得很明确：

- 程序刚开始 tracking 时，JIT image 还不稳定，`poke->tailcall_target_stable` 必须是 false；
- 只有 JIT 完成 final fixup 后，map update 路径才能通过这个 descriptor 去 patch JIT text；
- `prog_array_map_poke_run()` 会跳过 `stable=false` 的 entry。

因此，这个 `WARN_ON_ONCE` 的含义是：

- x86 JIT 进入 `bpf_tail_call_direct_fixup()` 时，按设计这应该是“首次把一个尚未发布的 poke entry 变成 stable”的时刻；
- 如果此时 `stable` 已经是 true，说明这个 descriptor 之前已经被发布过，当前 fixup 正在复用一份本应只对应 live image 的 tailcall poke 元数据。

### 1.2 `poke->tailcall_target_stable` 是什么

`vendor/linux-framework/include/linux/bpf.h:1603-1618`：

- `tailcall_target` / `tailcall_bypass` / `bypass_addr` 记录 direct tailcall site 在 JIT image 里的 patch 点地址；
- `tailcall_target_stable` 表示这些地址已经对应到一个“可被 map update 路径安全 text-poke”的稳定 JIT image。

换句话说：

- `false` = 这个 descriptor 里的地址还在构建中，不能让 `map_poke_run()` 用；
- `true` = 这个 descriptor 已经绑定到一个可在线更新的 live/stable image。

### 1.3 正常首次 JIT 为什么不会触发

首次 load 路径中，这个假设成立：

- verifier 在 load 时创建 `poke_tab`，初始值全是 0，`bpf_jit_add_poke_descriptor()` 还显式要求 `tailcall_target_stable` 必须为 0；
- `emit_bpf_tail_call_direct()` 在 JIT pass 中填写 `tailcall_target` / `tailcall_bypass`；
- 直到 `bpf_tail_call_direct_fixup()` 最后一步，才把 `stable` 置为 true。

因此首次 JIT 时 warning 不会触发。

普通 load 路径里，subprog 虽然会两次调用 `bpf_int_jit_compile()`，但第一次只是 staging pass，不会走 final `bpf_tail_call_direct_fixup()`；真正置位 `stable` 只发生在最后一次 finalized pass。所以 load 路径本身不违反这个假设。

### 1.4 recompile 为什么会触发

根因是：**BpfReJIT 复用了已经发布过的 live `poke_tab`。**

关键链条如下：

1. `bpf_prog_jit_recompile()` 进入 `bpf_jit_recompile_prog_images()`，对已有 JIT 程序再次调用 `bpf_int_jit_compile()`。
2. recompile 的 reset 逻辑只清 staged-image 字段：`jit_recompile_*`、`jit_data` 等；`vendor/linux-framework/kernel/bpf/jit_directives.c:239-251,357-366` 没有 reset `poke_tab`，也没有 reset `tailcall_target_stable`。
3. `poke_tab` 本身是 verifier load 阶段长期挂在 `prog->aux` 上的共享元数据，不是“每次 JIT 新建一份”。
4. 因此 recompile 进入 x86 `bpf_tail_call_direct_fixup()` 时，`poke->tailcall_target_stable` 仍然保留着第一次 live JIT 后写下的 `true`。
5. 于是 `WARN_ON_ONCE()` 触发。

所以，这个 WARNING 的直接根因不是 Tetragon workload 本身，而是：

- x86 JIT 的 tailcall final-fixup 假设“当前 descriptor 还没被发布过”；
- BpfReJIT recompile 复用了“已经发布过的 descriptor”。

### 1.5 recompile 路径下还有什么特殊之处

更重要的是，recompile 不只是“读到了旧的 stable=true”。

`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4548-4555` 显示，`emit_bpf_tail_call_direct()` 在 `do_jit()` 过程中会直接改写共享 `poke_tab` 里的地址字段：

- `poke->tailcall_target`
- `poke->tailcall_bypass`
- `poke->bypass_addr`

而 `arraymap.c:1143-1151` 的 map update 路径会在 `stable=true` 时直接使用这些字段做 text poke。

这意味着 recompile 期间当前实现存在三个问题：

1. **warning 一定会打**
   因为 old live image 留下的 `stable=true` 没有清掉。

2. **shared poke metadata 会被 recompile 原地改写**
   staged image 构建时，JIT 会把 live descriptor 改写成新的地址。

3. **rollback/no-op 路径没有保存/恢复 poke descriptor**
   `kernel/bpf/jit_directives.c` 的 rollback state 只保存了 `bpf_func` / `extable` / `jit_data` / `insnsi` 等，不保存 `poke_tab` 的 tailcall address/stable 状态。

这跟 #109 的模式非常像：当时的问题是 re-JIT 首 pass 复用了 stale `aux->extable`，把 metadata 写回旧 RO image；这里的问题是 re-JIT 复用了 stale/live `poke_tab`，把 tailcall direct-poke 元数据和 live/staged image 混在了一起。

### 1.6 这个 WARNING 是否只在 recompile 路径上触发

在当前 tree 里，**基本可以认为它是 recompile 专属的 warning**。

更精确地说：

- 它会在“对同一个已经做过 final tailcall fixup 的 prog，再次进入 `bpf_int_jit_compile()`”时触发；
- 当前代码里，满足这个条件的实际路径就是 `BPF_PROG_JIT_RECOMPILE`；
- 普通 load 路径虽然也有多次 JIT（尤其 subprog），但在第一次 JIT 时还没把 `stable` 置 true，因此不会触发。

所以对你这次 Tetragon E2E 现象，可以直接归因为 recompile 路径。

## 2. 与文档 #109 / #152 的关系

### 2.1 #109（struct_ops EINVAL）

`docs/kernel-jit-optimization-plan.md` 里的 #109 / #117 已明确记录过一类 recompile bug：

- re-JIT 首 pass 复用了旧 `aux->extable`；
- `do_jit()` 因此把 exception-table metadata 写进旧 RO image；
- 最终触发 crash / EINVAL 误判；
- 修法是把 extable 写入收紧到 final image pass。

这次 tailcall warning 属于**同一大类问题**：

- 都是 recompile 期间复用了“只对当前 live image 有效”的旧元数据；
- 都发生在 JIT/re-JIT pass 之间的状态隔离不完整；
- 都不是 verifier/policy 的语义错误，而是 recompile 内部 staging/live 状态隔离问题。

### 2.2 #152（kernel safety fixes）

#152 修过的是：

- `smp_store_release()` 发布 `bpf_func`
- old image 退役前 `synchronize_rcu()`
- rollback 扩展
- `exception_cb` / `recompile_count` 等安全边角

但**没有覆盖 tailcall poke descriptor 的 staging/live 隔离**。

也就是说：

- #152 方向是对的，属于 recompile safety hardening；
- 但当前这个 warning 说明 tailcall poke 这一块当时没被纳入安全修复范围。

## 3. 严重性评估

### 3.1 对当前 Tetragon smoke 现象本身

如果 Tetragon smoke 只是对已加载程序做 recompile，而 recompile 期间没有并发的 prog-array 更新，那么这次看到的 WARNING **大概率只是防御性检查命中**：

- staged image 最终仍会在 `bpf_tail_call_direct_fixup()` 里按当前 `array->ptrs[key]` 做一次完整 fixup；
- 所以单次 smoke 本身未必会出现 wrong code、数据损坏或 crash；
- 这也解释了为什么你看到的是 WARNING，而不是直接功能失效。

因此，对“本次 Tetragon smoke 的已观察结果”来说，严重性偏低。

### 3.2 对内核实现本身

但从实现正确性看，这**不是单纯误报**，而是一个真实 bug 的 warning 症状，风险不应低估。

原因：

1. recompile 期间共享 `poke_tab` 被原地改写；
2. `tailcall_target_stable=true` 会让 map update 路径继续信任这份 descriptor；
3. rollback / no-op 路径又没有恢复旧 descriptor。

这带来几类潜在后果：

- **wrong code**：future tailcall map update 可能 patch 到错误 image；
- **stale target**：no-op/rollback 后 live image 保留，但 descriptor 已经不是 live image 对应地址；
- **kernel WARNING/BUG/oops 风险**：如果 map update 撞在 recompile 窗口，`__bpf_arch_text_poke()` 可能收到无效或已释放地址，调用者里还有 `BUG_ON(ret < 0)`。

结论：

- **不是数据损坏类 bug**；
- **可能演化成 wrong-code 或 crash 类 bug**；
- 当前看到的 WARNING 是低症状、但底层问题是中高严重性的 recompile safety bug。

### 3.3 `tailcall_target_stable=true` 在 recompile 场景下是否“预期”

需要区分两个层面：

- 对“旧 live image 的共享 descriptor”来说，`stable=true` 是**自然且预期**的；
- 对“`bpf_tail_call_direct_fixup()` 正在处理的 staged image”来说，`stable=true` 是**不应出现**的。

所以准确说法是：

- `stable=true` 出现在 recompile 入口，是当前实现的必然结果；
- 但它揭示的是 staged/live poke state 没有隔离好，因此**不是一个可接受的稳态**。

## 4. 修复方案

## 4.1 正确修法

正确方向不是“清 warning”，而是**把 live poke metadata 和 staged poke metadata 分离**。

建议方案：

1. recompile 开始时保留 live `poke_tab` 作为当前运行 image 的 authoritative descriptor；
2. 为 recompile/staged image 建立一份 shadow poke table；
3. JIT recompile 期间只改写 shadow table，`bpf_tail_call_direct_fixup()` 也只在 shadow table 上工作；
4. map update 路径在 commit 前继续使用 live table；
5. commit 成功后再原子切换到 shadow table；
6. abort / rollback / no-op 路径丢弃 shadow table，不影响 live table。

此外 rollback state 也应覆盖 poke metadata，否则 no-op/失败路径仍会留下脏状态。

### 4.2 不建议的“假修复”

下面两种都不对：

- **仅屏蔽/放宽 `WARN_ON_ONCE`**
  这只能消掉日志，不能解决 shared `poke_tab` 被 recompile 改写的问题。

- **在 recompile 开头直接把 shared `tailcall_target_stable` 清零**
  这会让 live image 在 recompile 期间失去 tailcall map update 的正常 direct-poke 跟踪能力，同样不安全。

### 4.3 这次是否直接改

**没有直接改内核代码。**

原因：

- 我确认这是 bug；
- 但安全修复不是 `<10` 行级别的小补丁；
- 单纯做 warning suppression 或 in-place reset 都会掩盖/引入更深问题，不适合在这次调查里顺手提交。

## 5. 是否需要重编 bzImage

**这次不需要。**

原因：

- 本次只做源码调查和文档结论；
- 没有改内核代码；
- 因此不需要 `make -C vendor/linux-framework -j$(nproc) bzImage`。

如果后续要落地修复，则建议：

- 先实现 shadow poke-table / rollback 扩展；
- 再重编 `bzImage`；
- 最后至少验证：
  - 普通 tailcall 程序 load + prog-array update
  - 有 tailcall 的 `BPF_PROG_JIT_RECOMPILE`
  - no-op recompile
  - rollback recompile
  - recompile 与并发 prog-array update

# REJIT Kernel Defensive Checks Review (2026-03-29)

## TL;DR

- 当前 `vendor/linux-framework/kernel/bpf/syscall.c` 的未提交改动只做了一件事：在 `bpf_prog_rejit_update_poke_tab()` 里去掉 `old_poke->insn_idx != new_poke->insn_idx` 校验。
- 这项放宽是**正确的**。对当前 in-place `poke_tab` 更新模型来说，`insn_idx` 不是运行时消费的不变量；真正影响后续 `map_poke_run()` 正确性的，是 `poke` 条目数、`reason`、`map`、`key`，以及新 JIT image 里已经生成好的 patch 地址。
- `insn_idx` 检查不是原始 tail-call REJIT 设计的一部分。`bpf_prog_rejit_update_poke_tab()` 在最初引入的提交里只有 `reason + map + key` 校验；`insn_idx` 是 2026-03-25 的 cleanup commit 后加的一行 tighten，没有 commit message 论证，也没有设计文档把它定义成安全边界。
- `map + key + 当前 slot 顺序` 对**当前实现**足够，但不是最小条件。它仍然会拒绝某些安全的 reorder；而“新增/删除 poke entry”的 structural delta 仍然不支持。这是未来 tail-call specialization 的独立 blocker，不是这次 `insn_idx` 放宽的问题。
- 这次审查没有在 `trampoline.c` refresh、`dispatcher.c` refresh、x86 JIT kinsn dispatch 里发现同等级的“明显过严且应立即删除”的当前校验。当前更像 implementation gate 的，主要是 attached `EXT/freplace` 的 REJIT reject。

## 1. `poke_tab` `insn_idx` 改动审查

### 1.1 当前代码和工作树 diff

当前 helper 在 [vendor/linux-framework/kernel/bpf/syscall.c:3218](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/syscall.c#L3218)。

当前校验只保留：

- `size_poke_tab` 相同
- 每个 slot 的 `reason` 相同
- 每个 slot 的 `tail_call.map` 相同
- 每个 slot 的 `tail_call.key` 相同

工作树 diff 显示，未提交改动仅删除了这一行：

```c
old_poke->insn_idx != new_poke->insn_idx
```

并补上注释，说明 llvmbpf round-trip 后 helper site 可以移动，但仍生成同一组 poke descriptor。

### 1.2 为什么去掉 `insn_idx` 是安全的

当前 runtime patch 路径并**不消费** `insn_idx`：

- `prog_array_map_poke_run()` 只看 `tailcall_target_stable`、`reason`、`tail_call.map`、`tail_call.key`，然后调用 `bpf_arch_poke_desc_update()`。
  见 [vendor/linux-framework/kernel/bpf/arraymap.c:1107](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/arraymap.c#L1107) 到 [vendor/linux-framework/kernel/bpf/arraymap.c:1150](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/arraymap.c#L1150)。
- x86 direct-tail-call final fixup 也只使用 `map`、`key`、地址字段和 `adj_off`，不看 `insn_idx`。
  见 [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:901](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L901) 到 [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:935](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L935)。

而 `bpf_prog_rejit_update_poke_tab()` 实际做的事情，也只是把新 image 的地址字段复制回旧 `poke_tab`：

- `tailcall_target`
- `tailcall_bypass`
- `bypass_addr`
- `adj_off`

见 [vendor/linux-framework/kernel/bpf/syscall.c:3279](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/syscall.c#L3279) 到 [vendor/linux-framework/kernel/bpf/syscall.c:3282](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/syscall.c#L3282)。

换句话说：

1. 新程序自己的 poke descriptors 是 verifier/JIT 重新生成的，地址不是 userspace 伪造的。
2. 后续 runtime 只需要“哪个 `(map,key)` 对应哪块 patchable native 地址”。
3. `insn_idx` 既不参与 runtime lookup，也没有被 copy 回 live `poke_tab`。

所以，如果新 lifted 程序把同一个 constant-key tail-call site 移到了新的 eBPF PC，但 verifier/JIT 仍然为它生成同一个 `(map,key)` 的新 patch slot，那么拒绝它只是过严，不是在保护真正被消费的安全属性。

### 1.3 `insn_idx` 在系统里的真实作用

`insn_idx` 不是完全没用；它仍然用于**build/JIT 阶段**：

- verifier 创建 poke descriptor 时记录 `insn_idx`。
  见 [vendor/linux-framework/kernel/bpf/verifier.c:24165](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c#L24165) 到 [vendor/linux-framework/kernel/bpf/verifier.c:24169](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c#L24169)。
- `jit_subprogs()` 里用它把 poke descriptor 归属到对应 subprog 的 `aux`。
  见 [vendor/linux-framework/kernel/bpf/verifier.c:23221](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c#L23221) 到 [vendor/linux-framework/kernel/bpf/verifier.c:23227](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c#L23227)。

但这两个用途都发生在 **tmp 新程序的 verify/JIT 过程中**。REJIT live-swap 阶段并不依赖旧 `poke_tab` 的 `insn_idx` 再做任何决策。

这也反过来说明：如果 `insn_idx` 真是 live-swap 的安全不变量，那么当前代码不应该只“比较但不复制/更新”；它应该同步 remap `insn_idx`，甚至同步 `poke->aux`。现在没有这么做，说明这个 compare 本身就是纯 defensive tighten，不是 downstream 必需条件。

### 1.4 `map + key + 顺序` 是否足够

对**当前 in-place 更新模型**，结论是：

- `size_poke_tab` 必须保留。
- `reason + map + key` 必须保留。
- 当前的“按 slot 对齐”是**足够但偏保守**。

原因分别是：

#### `size_poke_tab` 不能删

如果 old/new 条目数不同，而我们还复用旧 `poke_tab`：

- old 多出来的 descriptor 会继续留在 `poke_progs` 跟踪里；
- 它们的地址可能仍指向旧 image；
- 后续 `map_poke_run()` 可能 patch 已释放 JIT memory。

所以 `size_poke_tab` 对当前实现是内存安全边界，不是多余防御。

#### `reason + map + key` 不能删

runtime `map_poke_run()` 就是按 `(map,key)` 找 descriptor 的。

如果把 key/map 对不上：

- 后续 map update 会 patch 错的 direct-jump site；
- 或者该 patch site 不再随它真正依赖的 map slot 更新；
- 这是明确的语义错误。

#### “按 slot 顺序匹配”足够，但不是最小条件

当前代码仍要求 old/new 两边在 slot 序列上逐项匹配。它的效果是：

- 对当前 llvmbpf round-trip 这类“site 移位但 `(map,key)` 发现顺序不变”的场景，已经足够。
- 对未来“不同 `(map,key)` site 发生安全 reorder”的场景，它仍可能误拒。

所以：

- `map + key + 发现顺序` 对**当前实现**足够。
- 但它不是理论上的最小必要条件；只是一个保守、易实现的 pairing 方案。

### 1.5 edge case：同一个 `(map,key)` 出现多次

这是这次改动最需要单独看的 edge case。

结论：**删除 `insn_idx` 后仍然安全**。

原因：

1. 如果同一个 `(map,key)` 出现多次，runtime `map_poke_run()` 本来就会遍历 `poke_tab`，把所有匹配该 `(map,key)` 的条目全部 patch 一遍。
2. 这几个 descriptor 对 runtime 来说，区别只在于“各自 patch 哪个 native site”；它们不依赖 eBPF PC 身份。
3. REJIT update 复制的是新 image 中 verifier/JIT 生成的合法 patch 地址，不是 userspace 传进来的任意地址。
4. 只要 `size_poke_tab` 不变，这些 duplicate descriptor 会得到一组新的、同样合法的 patch slot。

更细一点说：

- 若 duplicate 之间只是相对顺序变化，但每个 slot 上的 `(map,key)` 仍相同，那么当前代码也会接受。
- 即便 old/new duplicate 的一一配对不是“原 site 对原 site”，也不影响 runtime，因为这几条 descriptor 最终都会在同一个 `(map,key)` 事件上被统一 repatch。

### 1.6 这次放宽没有引入的风险

我没有看到删除 `insn_idx` 后新增的内核安全风险。具体没有新增以下问题：

- 没有新增任意地址 text poke：地址仍来自新程序 JIT 自己生成的 patch slot。
- 没有让 map update patch 到非 tail-call site：descriptor 仍只能来自 verifier/JIT 创建的 direct-tail-call descriptor。
- 没有放宽到“不同 `(map,key)` 也能混配”：`map` 和 `key` 仍逐 slot 比较。
- 没有放宽到“entry 数量不同也能混配”：`size_poke_tab` 仍严格相等。

### 1.7 结论

对当前树，这次 `insn_idx` 删除的 verdict 是：

- **删除是正确的。**
- **它移除的是过严 defensive check，不是安全边界。**
- **真正该保留的是 `size + reason + map + key`。**
- **未来若要支持 dynamic tail-call specialization 的 structural delta，则要从“就地更新旧 poke_tab”升级到“untrack old / install new”的新模型；那是下一阶段问题。**

## 2. `insn_idx` 检查最初是怎么加上的

### 2.1 git history

`bpf_prog_rejit_update_poke_tab()` 的历史是：

1. `e7d27ef37317` (`2026-03-21`, `bpf: tail_call (poke_tab) REJIT support + EXT/freplace fix + gitignore`)
   - **首次引入**这个 helper。
   - 当时只检查 `size_poke_tab`、`reason`、`map`、`key`。
   - **没有** `insn_idx` compare。

2. `71e468dde82e` (`2026-03-25`, `bpf: Clean up unnecessary changes from BpfReJIT patch set`)
   - 在这个 cleanup commit 里，给现有 compare 条件多加了一行：
     `old_poke->insn_idx != new_poke->insn_idx`
   - commit message 没有解释这行为什么需要。

3. 当前未提交工作树
   - 又把这行删掉了，并补了说明注释。

### 2.2 commit message / 文档里有没有解释

没有找到把 `insn_idx` 定义成安全边界的依据：

- `71e468dde82e` 的 commit message 只说 “Clean up unnecessary changes ... / Fix struct_ops and verifier minor cleanups”，没有提 `poke_tab` `insn_idx` 的设计理由。
- 原始功能提交 `e7d27ef37317` 也没有要求 `insn_idx` 必须一致。
- 我搜索了 `docs/tmp/` 和主设计文档，只看到后续调研文档记录“当时实现要求 `insn_idx` 一致”，没有找到“为什么这是安全所必需”的论证。

唯一明确提到这次放宽的是：

- `docs/tmp/20260329/llvmbpf_kernel_stack_fix_report_20260329.md:161-173`

这份报告把它描述为为 llvmbpf round-trip 放宽的 REJIT 限制，并记录该修改修复了若干 `EINVAL` REJIT 失败。

### 2.3 判断

我的判断是：

- 这行 `insn_idx` compare **不是**原始设计要求；
- 它也**没有**被 commit message / 设计文档当成安全属性来论证；
- 它更像一次 ad hoc defensive tighten，想把“site identity”也一并锁死；
- 但 downstream 代码并不消费这个“site identity”，所以它没有形成真正闭环。

因此，它应被归类为：

- **defensive but over-strict**
- 不是必须保留的安全校验

## 3. 其他当前 defensive checks 审查

### 3.1 结果概览

我重点审查了用户指定的当前文件：

- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `vendor/linux-framework/kernel/bpf/dispatcher.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

结论：

- 当前树里**没有**再发现一个与 `poke_tab.insn_idx` 同级别、明显“删掉更对”的 over-strict 校验。
- 目前最像 implementation gate 的，是 **attached `EXT/freplace` REJIT 直接 reject**。
- 另外一个“严格但应该保留”的点，是 **`func_info` 与 subprog layout 严格一致**。
- 历史上曾存在的 `func_cnt` / multi-subprog layout gate 已经不在当前 `syscall.c` 里，不是当前 blocker。

### 3.2 逐项 verdict

| 位置 | 当前检查 | 保护的属性 | 哪些 daemon 变换会撞上 | Verdict |
| --- | --- | --- | --- | --- |
| `syscall.c:3171-3175` | `!prog->jited || prog->is_func || offloaded || dev_bound` 直接不支持 REJIT | 避免对 runtime model 不同或不是顶层 live prog 的对象走 REJIT swap | 任何对 offloaded/dev-bound prog 的 REJIT | **保留**。这是能力边界，不是过严防御。 |
| `syscall.c:3182` | attached `EXT` 且 `!aux->dst_prog` 时拒绝 | verifier 需要 live replacement target；当前 attach 后 `dst_prog` 被清空，refresh 路径也不完整 | freplace / attached EXT REJIT | **保留（当前）**。这是 implementation gate，不是长期设计目标；只有在 live target 重建和 REPLACE refresh 做完后才能放宽。 |
| `syscall.c:3224-3248` | `size_poke_tab` 相等，逐 slot `reason/map/key` 相等 | 当前 in-place `poke_tab` 重用模型的内存安全和后续 `map_poke_run()` 正确性 | llvmbpf round-trip、未来 tail-call specialization | **部分放宽**。`insn_idx` 已应删除；`size/reason/map/key` 该保留。slot-order 约束是保守实现，不是最小必要条件。 |
| `syscall.c:3774-3778` | `!bpf_prog_rejit_supported(tmp) || !tmp->jited`，以及 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE` | 保证 replacement image 真正可 JIT，并且 fit 进现有 prog allocation/page budget | llvmbpf 增大指令数、任何 code-size 增长 pass | **保留**。这是实际内存/发布约束，不是 defensive overkill。 |
| `verifier.c:19525-19549` | `func_info_cnt == subprog_cnt` 且每个 `func_info[i].insn_off == subprog start` | BTF/func_info 元数据与真实 subprog layout 一致 | 任何改变 subprog 边界却还复用旧 `func_info` 的变换；尤其是 full subprog relift / subprog inline | **保留**。这是 metadata correctness 边界。若要放宽，必须先扩 UAPI 或重建新 metadata。 |
| `verifier.c:23448-23460` | JIT 失败后，带 kfunc / kinsn / `tail_call + bpf2bpf` 的程序不允许退回 interpreter | interpreter 本身不支持这些语义组合 | 间接地，任何让 JIT 失败的程序 | **保留**。这是 runtime support gap，不是多余防御。 |
| `verifier.c:24708-24718` | `map_poke_track/untrack/run` 三个 hook 必须同时存在 | 确保 poke 生命周期完整，不会 track 了却无法 untrack / repatch | 任意支持 direct-tail-call poke 的 map type 扩展 | **保留**。这是生命周期完整性检查。 |
| `trampoline.c:936-950` | refresh 遍历 `trampoline_users`，遇错即停 | 这里没有明显 over-strict reject；问题在 failure atomicity 和覆盖范围 | attached prog REJIT、部分 refresh 失败 | **不属于“过严校验”**。当前问题是 refresh 语义不够完整，不是 guard 太严。 |
| `dispatcher.c:145-149` | 只有 dispatcher image 存在且确实包含该 prog 时才 refresh | 避免无意义 rebuild | XDP prog REJIT | **保留**。不是过严。 |
| `x86/net/bpf_jit_comp.c:592-600` | `emit_x86` 必须存在，返回长度必须和 `off/max_emit_bytes` 一致 | 防止 kinsn native emitter 越界或内部协议错位 | 任何 kinsn emit path | **保留**。这是内存安全/内部一致性检查。 |

## 4. 重点结论

### 4.1 应该删除/已正确放宽的

只有一项我认为应当明确归为“过严 defensive check”：

- `bpf_prog_rejit_update_poke_tab()` 中的 `insn_idx` 一致性要求

安全论证已经在上面给出：

- runtime 不消费它；
- live-swap 也不更新它；
- descriptor 地址仍由 verifier/JIT 生成；
- 保留 `size + reason + map + key` 后，不会新增 kernel safety 风险。

### 4.2 应该保留的

以下严格校验不应删：

- `size_poke_tab` 相等
- `poke reason/map/key` 一致
- `func_info` 与 subprog layout 严格一致
- attached `EXT/freplace` 在无法重建 live target 时继续拒绝
- JIT fallback 到 interpreter 时对 unsupported 语义组合的 reject
- kinsn emit bounds / consistency 校验

这些要么是：

- 真实内存安全边界，
- 真实 metadata correctness 边界，
- 要么是当前 runtime support 的明确 capability boundary。

### 4.3 可继续关注但不建议现在删的

当前 `poke_tab` 仍然保留“按 slot 顺序对齐”的假设。它不是最小必要条件，但在当前实现下我不建议再继续放宽，原因是：

- llvmbpf round-trip 现在只需要“site 移位但 descriptor 序列不变”；
- 再往下做 order-insensitive matching，会引入 duplicate/multiset pairing 逻辑；
- 真正想支持 future tail-call specialization，正确方向不是继续在旧表上做更复杂匹配，而是切到 `untrack old / install new` 的 structural-delta 模型。

所以这项的 verdict 不是“删除”，而是：

- **当前保留**
- **未来在 structural-delta 方案里整体替换**

## 5. 最终 verdict

### `poke_tab insn_idx`

- **Verdict: 删除**
- 原因：过严 defensive check；不是安全边界；删除后对当前 runtime patch 模型仍安全。

### 其他当前检查

- **保留**：`size_poke_tab`、`reason/map/key`、page budget、`func_info`/subprog layout、non-JIT fallback reject、poke hook completeness、x86 kinsn emit bounds。
- **保留但属于 implementation gate**：attached `EXT/freplace` 的 `dst_prog` 检查。
- **未发现当前应立即删除的第二个同级别过严校验**。

## 6. 额外说明

历史上确实存在过更重的 REJIT defensive gate，例如 `func_cnt` / multi-subprog layout match 之类；但这些已经不在当前 `syscall.c` 中，不能算“当前树仍需删除的 over-strict check”。

所以，如果只回答当前问题：

- **这次 `poke_tab insn_idx` 放宽是对的。**
- **它应被视为删除过严 defensive programming，而不是削弱安全性。**

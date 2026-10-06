# BpfReJIT v2 内核补丁集严格最终审查

**审查日期**: 2026-03-25
**审查标准**: BPF subsystem maintainer (Alexei/Daniel 级别)
**分支**: `vendor/linux-framework` master..HEAD
**Diff 规模**: 17 files changed, +1739/-99 lines
**已排除项**: kinsn 双轨制验证 (instantiate_insn vs emit_x86/emit_arm64) 为有意设计，类似 kfunc trampoline，不对此提 NAK

---

## 前置说明

本次审查聚焦以下四个维度：
1. REJIT verifier 安全边界
2. 内存安全
3. 不必要的改动
4. 代码质量

已完整阅读 5 份前期报告。本报告不重复前期报告的结论，而是在其基础上进行更深入、更精确的逐行审查。

---

## 1. P0 安全问题

### P0-1: `do_misc_fixups()` 中 `bpf_kinsn_has_native_emit()` 未定义 — 编译错误或死代码路径

**文件**: `kernel/bpf/verifier.c:23776`

```c
if (prog->jit_requested && bpf_kinsn_has_native_emit(kinsn))
    goto next_insn;
```

**问题**: `bpf_kinsn_has_native_emit()` 在整个内核源码树中没有定义。grep 确认只有这一处引用，没有函数定义、内联函数、或宏。

此外，该代码块存在**严重的缩进错误**：第 23776-23781 行的缩进比周围代码多了一层（三个 tab），但没有任何 `if/else/for` 包裹它们。这意味着：
- 如果编译器将其视为有效代码（找到了某个头文件中的声明），这个 `goto next_insn` 会在 `validate_kinsn_proof_seq` 成功后无条件跳过后续的 `verifier_remove_insns` + `bpf_patch_insn_data`
- 实际上缩进表明这里原本应该有一个 `if` 块，但代码被损坏了

这不仅是编译错误，还暴露了 `do_misc_fixups` 中 kinsn fallback 路径的逻辑是不完整的。

**触发条件**: 任何使用 kinsn 的程序在 non-JIT fallback 路径上
**修复方案**: 定义 `bpf_kinsn_has_native_emit()` 或修复整个逻辑块的控制流

---

### P0-2: `bpf_prog_rejit_swap()` 使用 `smp_wmb()` + `WRITE_ONCE()` — 在弱序架构上不安全

**文件**: `kernel/bpf/syscall.c:3448-3450`

```c
/* Publish the replacement image after metadata is in place. */
smp_wmb();
WRITE_ONCE(prog->bpf_func, tmp->bpf_func);
```

**问题**: `smp_wmb()` 只保证**写-写**顺序。读端（`BPF_PROG_RUN` 宏、trampoline dispatch）使用普通 load 读取 `prog->bpf_func`。在 ARM64 等弱序架构上：

- 写端: `smp_wmb()` 保证 metadata 写 happens-before `bpf_func` 写（在写端 CPU 的存储缓冲区中）
- **但读端没有对应的 acquire barrier**。读端可能看到新的 `bpf_func` 值，但对 metadata（`prog->len`、`prog->insnsi`、`prog->aux->func[]` 等）的读取被重排到 `bpf_func` 读取之前执行，拿到旧值

在 x86 上 TSO 模型保证了这不是问题。但代码同时支持 ARM64（有 `emit_arm64` callback），所以必须正确。

**具体竞争窗口**:
1. CPU0 执行 swap: 写 metadata → smp_wmb → 写 bpf_func
2. CPU1 执行 BPF prog: 读 bpf_func (得到新值) → **读 prog->len (可能得到旧值)**
3. 如果新 prog 的 len > 旧 prog 的 len，`bpf_prog_get_info_by_fd` 可能 over-read；如果 `prog->aux->func[]` 指向旧的子函数数组，运行时可能跳转到已释放的地址

**修复方案**: 改为 `smp_store_release(&prog->bpf_func, tmp->bpf_func)`。但更根本的问题是：BPF 运行时读 `prog->bpf_func` 的地方是否有配对的 `smp_load_acquire`。如果没有（目前没有），那么应该：
- 依赖 `synchronize_rcu` 后才释放旧镜像（当前已有）
- 在窗口期内，CPU 可能执行旧或新的 bpf_func，两者都必须有效 — 这一点由 RCU grace period 保证，因为旧镜像在 `synchronize_rcu` 之后才释放
- 但 metadata 不一致仍然存在 — 读端可能看到新 bpf_func 但旧 metadata

实际安全影响：BPF 运行时主要通过 `bpf_func` 指针直接调用，不依赖 `prog->len` 等 metadata。但 `prog->aux->func[]`（子函数数组）和 `prog->aux->extable`（异常表）如果不一致，可能导致运行时错误。

---

### P0-3: `bpf_prog_rejit_swap()` 遗漏 `tail_call_reachable` 字段

**文���**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_swap()` (第 3370-3463 行)

**问题**: `prog->aux->tail_call_reachable` 由 verifier 在 `check_cfg()` 阶段设置（`verifier.c:7187`），并在 `jit_subprogs()` 中传播到子函数（`verifier.c:23262`）。`bpf_prog_rejit_swap()` 没有 swap 这个字段。

如果原程序 `tail_call_reachable = false` 但 REJIT 后的程序引入了新的 tail_call 可达路径，或者反过来：
- `tail_call_reachable` 影响 JIT 是否在函数 prologue 中保存 tail_call 计数器（`verifier.c:23454`）
- 不一致会导致 tail_call 递归保护失效（计数器不被保存/恢复），可能触发内核栈溢出

**触发条件**: REJIT 的新 bytecode 改变了 tail_call 可达性
**修复方案**: 在 swap 中添加 `swap(prog->aux->tail_call_reachable, tmp->aux->tail_call_reachable)`。或者更好地，将所有 verifier/JIT 输出字段打包为子结构一次性 swap。

---

### P0-4: `bpf_struct_ops_refresh_prog()` 部分成功后的不一致状���

**文件**: `kernel/bpf/bpf_struct_ops.c:1548-1569`

```c
for (i = 0; i < st_map->funcs_cnt; i++) {
    ...
    err = bpf_arch_text_poke(call_sites[i], BPF_MOD_CALL,
                             BPF_MOD_CALL,
                             (void *)old_bpf_func,
                             (void *)prog->bpf_func);
    if (err) {
        pr_warn("struct_ops rejit: text_poke failed: %d\n", err);
        goto out;
    }
}
```

**问题**: `bpf_arch_text_poke` 对多个 call site 逐个 patch。如果第 N 个 site 的 patch 失败（`err != 0`），前 N-1 个 site 已经被 patch 为新地址，但剩余 site 仍指向旧地址。

此时函数返回错误，`bpf_prog_rejit()` 进入 rollback 路径（`syscall.c:3625-3637`）。rollback 调用 `bpf_prog_rejit_swap()` 恢复旧 `bpf_func`，然后再次调用 `bpf_struct_ops_refresh_prog()` 尝试将所有 site 改回旧地址。

但在 rollback 的 `bpf_struct_ops_refresh_prog()` 中，`find_call_site()` 搜索的是 `old_bpf_func`（传入的参数，此时 rollback 传入的 `new_bpf_func`）。对于已经被 patch 到新地址的 site，`find_call_site` 能找到；对于未被 patch 的 site，它们仍指向旧地址 — 但 `find_call_site` 搜索的是 `new_bpf_func`，所以找不到。

**结果**: rollback 后，部分 call site 被恢复，部分 call site 保持旧地址不变（本来就是旧地址所以恰好正确），整体上 rollback 是正确的。

**但**: 如果 rollback 的 `find_call_site` 失败（因为某个 trampoline 被并发修改），它返回 `-ENOENT`，此时 `bpf_prog_rejit_rollback()` 记录 `rollback_err` 但仍然继续。调用方设置 `retain_old_image = true` 防止释放。

**真正的 UAF 风险在这里** (`syscall.c:3613-3618`):
```c
err = bpf_prog_rejit_rollback(prog, tmp, new_bpf_func, ...);
if (err) {
    retain_old_image = true;
}
goto post_swap_sync;
```

`retain_old_image` 只阻止 `__bpf_prog_put_noref(tmp, ...)`。rollback swap 之后，`tmp` 持有的是新镜像（swap-back 把新镜像放回 tmp）。如果 `retain_old_image = true`，新镜像不被释放 — 这是正确的（防止 struct_ops trampoline 中可能残留的新地址引用成为悬垂指针）。但这是**内存泄漏**，不是 UAF。

**修订结论**: 前期报告声称的 UAF 在仔细分析后降级为**内存泄漏 + 部分更新的不一致状态**（P1 而非 P0）。但仍需修复：部分成功的 text_poke 应该在返回错误前回滚已 patch 的 site。

---

### P0-5: `bpf_prog_rejit_poke_target_phase()` 的 lockless read + idr 遍历竞态

**文���**: `kernel/bpf/syscall.c:3288-3340`

```c
while ((map = bpf_map_get_curr_or_next(&id))) {
    ...
    for (key = 0; key < array->map.max_entries; key++) {
        if (array->ptrs[key] != prog)    // lockless read
            continue;
        mutex_lock(&array->aux->poke_mutex);
        if (array->ptrs[key] != prog) {  // re-check under lock
            mutex_unlock(&array->aux->poke_mutex);
            continue;
        }
        ...
    }
}
```

**问题 1**: Phase 1 (delete) 在 swap 之前将 `prog` 的 poke site patch 为 NOP。Phase 2 (insert) 在 swap 之后将 NOP patch 为新 `bpf_func` 地址。两个 phase 之间，如果 `bpf_prog_array_update()` 将 `prog` 插入一个新的 PROG_ARRAY slot：
- Phase 1 不知道这个新 slot（已经扫描过了）
- 新 slot 的 poke site 被 `map_poke_run` 设置为指向当前 `prog->bpf_func`（此时已是新地址，因为 swap 已完成）
- Phase 2 也可能错过它（如果 Phase 2 扫描时该 slot 尚未可见）

由于 `bpf_prog_array_update` 中的 `map_poke_run` 使用的是 swap 后的 `prog->bpf_func`（新地址），这个新 slot 最终会指向正确的地址。所以这不是 UAF。

**问题 2**: `bpf_map_get_curr_or_next` 遍历 `map_idr`，在遍历过程中新增或删除的 map 可能被错过或重复访问。这在功能上是 benign 的（错过一个 map 意味着该 map 中的 prog 在下一次 map_update 时会被 repoke），但效率不高且语义不精确。

**修订结论**: 前期报告描述的 Phase 1/2 竞态在仔细分析后**不是 UAF** — `synchronize_rcu` 保证旧镜像不被使用中的 CPU 引用，新 slot 的 poke 由 `map_poke_run` 正确处理。降级为 P2（效率和代码清晰度改进）。

---

## 2. P1 正确性问题

### P1-1: `bpf_prog_rejit_swap()` 遗漏多个 verifier/JIT 输出字段

**文件**: `kernel/bpf/syscall.c:3370-3463`

以下字段由 verifier 或 JIT 设置，但未在 swap 中处理：

| 字段 | 设置位置 | 影响 | 严重程度 |
|------|---------|------|---------|
| `tail_call_reachable` | verifier.c:7187 | tail_call 递归保护 | P0（已在上面单列） |
| `arena` | verifier.c:22249 | BPF arena 内存映射 | P1：REJIT 后 arena 指针不一致 |
| `ctx_arg_info` / `ctx_arg_info_size` | verifier.c:25122 | 上下文参数类型信息 | P1：运行时类型检查可能用旧值 |
| `attach_func_proto` | verifier.c:25769 | tracing/EXT 目标函数原型 | P2：信息查询不一致 |
| `attach_func_name` | verifier.c:25770 | tracing/EXT 目标函数名 | P2：信息查询不一致 |

**修复方案**: 将 `bpf_prog_aux` 中所有 verifier/JIT 产出字段分组为 `struct bpf_prog_compile_output` 子结构，swap 整个子结构。这从根本上消除遗漏风险。

---

### P1-2: `free_tmp` 错误路径中 `btf` 引用可能泄漏

**文件**: `kernel/bpf/syscall.c:3656-3673`

```c
free_tmp:
    if (tmp->aux->dst_prog)
        bpf_prog_put(tmp->aux->dst_prog);
    tmp->aux->dst_prog = NULL;
    if (tmp->aux->attach_btf)
        btf_put(tmp->aux->attach_btf);
    tmp->aux->attach_btf = NULL;
    kvfree(tmp->aux->func_info);
    ...
    bpf_prog_free(tmp);
```

**问题**: 对于 EXT (freplace) 程序，REJIT 在第 3577-3605 行中：
```c
if (prog->type == BPF_PROG_TYPE_EXT && prog->aux->btf && ...) {
    btf_get(prog->aux->btf);
    tmp->aux->btf = prog->aux->btf;
    ...
}
```

如果后续在 `security_bpf_prog_load()` 之前失败并跳到 `free_tmp`，`tmp->aux->btf` 持有一个引用。`free_tmp` 路径没有 `btf_put(tmp->aux->btf)`。

**但**: `bpf_prog_free(tmp)` 最终通过 `call_rcu -> bpf_prog_free_deferred` 调用 `btf_put(prog->aux->btf)`。问题是 `bpf_prog_free_deferred` 中的 `btf_put` 是否覆盖了 `tmp` 的情况 — `tmp` 没有 prog_id、没有经过 `bpf_prog_alloc_id`，`bpf_prog_free_id` 会是 no-op。

经确认，`bpf_prog_free_deferred` 路径确实会 `btf_put(aux->btf)`，所以不会泄漏。但代码可读性很差，`free_tmp` 和 `free_tmp_noref` 两条错误路径的清理逻辑应该统一。

**修订结论**: 不是实际泄漏，但 `free_tmp` 中的清理与 `__bpf_prog_put_noref` 不一致。`free_tmp` 手动清理了部分字段然后调用 `bpf_prog_free`（延迟清理），而 `free_tmp_noref` 直接调用 `__bpf_prog_put_noref`（立即清理）。应该统一为一条路径。降级为 P2。

---

### P1-3: `bpf_struct_ops_refresh_prog()` 中 `find_call_site()` 线性扫描 trampoline — 脆弱且可能找错

**文件**: `kernel/bpf/bpf_struct_ops.c:1481-1515`

`find_call_site()` 在 trampoline 二进制镜像中搜索 `CALL rel32` 指令，检查目标是否等于 `old_bpf_func`。

**问题 1**: 如果 trampoline 镜像中有其他 CALL 指令恰好调用相同地址（例如两个不同的 struct_ops 方法使用同一个 BPF 程序），`find_call_site` 只返回第一个匹配。后续 `text_poke` 只 patch 第一个，遗漏第二个。

**问题 2**: x86 的 `insn_init`/`insn_get_length` 解码器是可靠的，但 ARM64 的分支偏移计算 `aarch64_get_branch_offset` 的正确性依赖于 `aarch64_insn_is_bl` 能完全覆盖所有 branch-and-link 变体。

**问题 3**: 扫描范围是 `ksym->start` 到 `ksym->end`，但 `ksym` 是 `st_map->ksyms[i]`。如果 ksym 的范围信息不精确（例如 size 为 0 或过大），扫描可能越界或漏掉。

**修复方案**: 在 struct_ops trampoline 构建时（`bpf_struct_ops_prepare_trampoline`），记录每个 prog 的 call site 偏移到 `st_map` 中。REJIT 时直接使用保存的偏移。

---

### P1-4: `bpf_prog_rejit_poke_target_phase` 中 `bpf_map_get_curr_or_next` 遍历所有 map — 效率问题且可能持锁过久

**文件**: `kernel/bpf/syscall.c:3288-3340`

遍历整个 `map_idr` 查找类型为 `BPF_MAP_TYPE_PROG_ARRAY` 的 map，再线性扫描每个 map 的所有 entries。对于有大量 map 的系统（如 Cilium 可能有数百个 map），这个操作的时间复杂度为 O(total_maps * max_entries)。

在 REJIT 的 hot path 上执行两次（Phase 1 和 Phase 2），每次都需要遍历并持有 `poke_mutex`。

**修复方案**: 维护反向索引：prog -> 包含它的所有 PROG_ARRAY slot 列表。

---

### P1-5: `__bpf_ksym_del` 中新增的 `INIT_LIST_HEAD_RCU` 可能隐藏 double-del bug

**文��**: `kernel/bpf/core.c:657`

```c
latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
list_del_rcu(&ksym->lnode);
INIT_LIST_HEAD_RCU(&ksym->lnode);
```

**问题**: `__bpf_ksym_del()` 开头有 `if (list_empty(&ksym->lnode)) return;` 检查。添加 `INIT_LIST_HEAD_RCU` 使 `lnode` 在删除后变为"空"状态，使得后续的 `__bpf_ksym_del` 调用变为 no-op。

这个改动的目的是支持 REJIT 中 `bpf_prog_kallsyms_del_all(prog)` 后 `bpf_prog_kallsyms_add(prog)` 的序列（swap 函数中第 3397-3455 行）。没有这个改动，`list_empty` 检查在 `list_del_rcu` 后返回 false（因为 `list_del_rcu` 设置 poison 值），导致 `bpf_prog_kallsyms_add` 时 `__bpf_ksym_add` 无法正确插入。

**但**: `INIT_LIST_HEAD_RCU` 意味着在 RCU 读侧临界区中，其他 CPU 可能正在遍历这个 list node 的 `next` 指针。如果 `INIT_LIST_HEAD_RCU` 在 `list_del_rcu` 之后立即执行，正在遍历的 CPU 可能通过 `next` 指针走到一个已经被重新初始化为 self-loop 的 node。

`list_del_rcu` + `INIT_LIST_HEAD_RCU` 的组合在上游内核中有使用先例（见 `hlist_bl_del_init_rcu`），但前提是在 RCU grace period 过后才重新使用该 node。这里 `bpf_prog_kallsyms_add` 在 `synchronize_rcu` 之前就被调用了（swap 函数中没有 `synchronize_rcu`），所以**不安全**。

**修复方案**: 将 `bpf_prog_kallsyms_add` 移到 `synchronize_rcu` 之后。或者在 swap 后不重新注册 kallsyms（只在 `post_swap_sync` 之后注册）。

---

### P1-6: `orig_insns` 对所有 BPF 程序无条件分配 — 内存浪费

**文件**: `kernel/bpf/syscall.c:3025-3031`

```c
prog->aux->orig_insns = kvmemdup(prog->insns, bpf_prog_insn_size(prog), GFP_USER);
```

在 `bpf_prog_load()` 中为每个 BPF 程序无条件分配 `orig_insns` 副本。对于大型部署（Cilium/Falco 可能有数千个程序），这是显著的内存浪费。一个 1000 条指令的程序 = 8KB，10000 个程序 = 80MB。

**修复方案**: 延迟分配 — 只在第一次 `BPF_PROG_REJIT` 调用时保存 `orig_insns`。或通过 `bpf_prog_load` 时的 flag 控制。

---

### P1-7: `lower_kinsn_proof_regions()` 的 region start 调整逻辑

**文件**: `kernel/bpf/verifier.c:3836-3851`

```c
for (j = 0; j < env->kinsn_region_cnt - 1; j++) {
    struct bpf_kinsn_region *prior = &env->kinsn_regions[j];
    ...
    if (prior->start <= region->start)
        continue;
    new_start = (s32)prior->start + (cnt - 2);
    ...
}
```

**问题**: `kinsn_regions` 的填充顺序是倒序（从 `env->prog->len - 1` 向 0 遍历）。所以 `kinsn_regions[0]` 是最高地址的 kinsn，`kinsn_regions[cnt-1]` 是最低地址的。

当处理 `kinsn_regions[k]`（当前 region）时，`j` 从 0 遍历到 `k-1`。由于 prior 索引 < k，且数组按倒序填充，prior 的原始地址 >= 当前地址。但 prior 的 start 已经被之前的 lowering 调整过了。

如果两个相邻的 kinsn region 的 proof 长度都不同于 2（即 `cnt != 2`），第二次调整时使用的是 prior 的已调整 start 值。调整公式 `prior->start + (cnt - 2)` 是基于当前 lowering 的偏移量。但 prior 的 start 已经被之前的偏移量调整过了，所以这个调整是**叠加的**。

这实际上是正确的：每次 lowering 都增加/减少 `cnt - 2` 条指令，所有地址 > 当前 lowering 位置的 region 都需要偏移。由于是倒序处理（先处理高地址），低地址的 region 在被处理之前已经正确累积了所有来自高地址 lowering 的偏移量。

**修订结论**: 逻辑上是正确的，但极难理解。需要添加 invariant 注释和 assert 检查。降级为 P2。

---

## 3. P2 改进建议

### P2-1: `btf_kfunc_is_allowed()` 和 `btf_kfunc_flags()` 的 `goto again` 重构 — 不必要的改动

**文件**: `kernel/bpf/btf.c:8940-8967`

原代码清晰地分两步查找（先 `BTF_KFUNC_HOOK_COMMON`，再 prog-type hook）。新代码改为 `goto again` 循环，逻辑等价但可读性下降。

**与 BpfReJIT 的关系**: 无关。纯重构。应恢复原代码或作为独立 prep patch。

---

### P2-2: `btf_populate_kfunc_set()` 中 memcpy 换行

**文件**: `kernel/bpf/btf.c:8771`

```c
-	memcpy(set->pairs + set->cnt, add_set->pairs, add_set->cnt * sizeof(set->pairs[0]));
+	memcpy(set->pairs + set->cnt, add_set->pairs,
+	       add_set->cnt * sizeof(set->pairs[0]));
```

纯 cosmetic 改动，与功能无关。

---

### P2-3: `-ENOTSUPP` -> `-EOPNOTSUPP` 修正

**文件**: `kernel/bpf/verifier.c`, `add_kfunc_desc()` 中

这是一个正确的 bug fix（`-ENOTSUPP` 是非标准错误码），但应该作为独立 prep patch 提交。

---

### P2-4: 每个 BPF 程序无条件初始化 `rejit_mutex` 和 `trampoline_users`

**文件**: `kernel/bpf/core.c:141-142`

```c
mutex_init(&fp->aux->rejit_mutex);
INIT_LIST_HEAD(&fp->aux->trampoline_users);
```

绝大多数程序永远不会使用 REJIT。mutex + list_head 在 `bpf_prog_aux` 中占用 ~96 bytes（x86_64），对大量程序的系统是不必要的开销。应按需分配。

---

### P2-5: `bpf_prog_rejit_swap()` 的 25+ 个手动字段 swap 是维护隐患

每次上游在 `bpf_prog` 或 `bpf_prog_aux` 中新增字段，都需要评估是否需要加入 swap 列表。当前 swap 列表没有任何自动化检查（没有 static_assert 验证字段覆盖率）。

**修复方案**: 将 verifier/JIT 输出字段打包为 `struct bpf_prog_compile_output` 子结构，swap 整个子结构。

---

### P2-6: `do_misc_fixups()` 中 kinsn fallback 路径使用 `env->insn_buf` 而非 `insn_buf`

**文件**: `kernel/bpf/verifier.c:23767, 23783`

```c
cnt = kinsn->instantiate_insn(bpf_kinsn_sidecar_payload(insn),
                              env->insn_buf);     // <-- env->insn_buf
...
new_prog = bpf_patch_insn_data(env, i + delta, insn_buf, cnt);  // <-- insn_buf (not env->insn_buf)
```

第一个调用写入 `env->insn_buf`，但 `bpf_patch_insn_data` 的参数是 `insn_buf`（局部变量 `struct bpf_insn *insn_buf = env->insn_buf`——需要确认是否是同一个）。如果 `insn_buf` 是 `env->insn_buf` 的别名，则正确。如果不是，则是 bug。

<确认>: `do_misc_fixups` 中有 `struct bpf_insn *insn_buf = env->insn_buf;`，所以 `insn_buf == env->insn_buf`。是同一个缓冲区。没有 bug，但应该统一使用 `insn_buf` 或 `env->insn_buf`，不要混用。

---

## 4. 逐文件判定

| # | 文件 | +/- | 判定 | 关键问题 |
|---|------|-----|------|---------|
| 1 | `include/uapi/linux/bpf.h` | +24 | **要求修改** | `BPF_PSEUDO_KINSN_SIDECAR` ISA 编码（不在本次 scope 但存在），`rejit` attr 结构可接受 |
| 2 | `include/linux/bpf.h` | +54 | **要求修改** | `orig_insns` 应按需分配，`rejit_mutex` 应按需初始化 |
| 3 | `include/linux/bpf_verifier.h` | +13 | **ACK** | |
| 4 | `include/linux/btf.h` | +2 | **ACK** | |
| 5 | `include/linux/filter.h` | +1 | **ACK** | |
| 6 | `arch/x86/net/bpf_jit_comp.c` | +39 | **有条件 ACK** | kinsn emit 为有意设计（排除项） |
| 7 | `arch/arm64/net/bpf_jit_comp.c` | +38 | **有条件 ACK** | 同上 |
| 8 | `kernel/bpf/verifier.c` | +574/-99 | **要求修改** | P0-1 (`bpf_kinsn_has_native_emit` 未定义)；kinsn 整合进 kfunc_desc 的重构是好的 |
| 9 | `kernel/bpf/syscall.c` | +699 | **要求修改** | P0-2 (smp_wmb), P0-3 (tail_call_reachable 遗漏), P1-1 (swap 遗漏字段), P1-6 (orig_insns) |
| 10 | `kernel/bpf/trampoline.c` | +58 | **有条件 ACK** | 锁序文档化 |
| 11 | `kernel/bpf/bpf_struct_ops.c` | +123 | **要求修改** | P1-3 (find_call_site 脆弱), P0-4 (部分成功不一致) |
| 12 | `kernel/bpf/btf.c` | +156/-8 | **要求修改** | P2-1 (goto again 不必要改动)，kinsn_set 并行结构可接受但应��一 |
| 13 | `kernel/bpf/core.c` | +3 | **要求修改** | P1-5 (INIT_LIST_HEAD_RCU 在 synchronize_rcu 之前重用) |
| 14 | `kernel/bpf/disasm.c` | +2 | **ACK** | |
| 15 | `kernel/bpf/dispatcher.c` | +23/-1 | **ACK** | |
| 16 | `net/core/filter.c` | +5 | **ACK** | |
| 17 | `tools/include/uapi/linux/bpf.h` | +24 | **ACK** (随主 UAPI) | |

---

## 5. REJIT `load_attr` vs `BPF_PROG_LOAD` 逐字段对比表

| `union bpf_attr` 字段 | `BPF_PROG_LOAD` 路径 | REJIT `load_attr` 构造 | 是否一致 | 影响 |
|----------------------|---------------------|----------------------|---------|------|
| `prog_type` | `attr->prog_type` | `prog->type` | 一致 | |
| `insn_cnt` | `attr->insn_cnt` | `attr->rejit.insn_cnt` | 一致 | |
| `insns` | `attr->insns` (用户空间) | `attr->rejit.insns` (用户空间, copy_from_bpfptr) | 一致 | |
| `license` | `attr->license` (用户空间) | **未设置** (load_attr.license = 0) | **不一致** | verifier 中 `bpf_check()` 调用 `process_fd_array()` 不依赖 license。GPL 兼容性由 `tmp->gpl_compatible = prog->gpl_compatible` 直接复制。**实际安全**: license 不影响 verifier 行为，GPL 兼容性通过 `gpl_compatible` 传播。**无实际影响** |
| `log_level` | `attr->log_level` | `attr->rejit.log_level` | 一致 | log_level 不影响 verifier 严格度 |
| `log_size` | `attr->log_size` | `attr->rejit.log_size` | 一致 | |
| `log_buf` | `attr->log_buf` | `attr->rejit.log_buf` | 一致 | |
| `kern_version` | `attr->kern_version` | **未设置** (0) | **不一致** | `kern_version` 只用于旧式 socket_filter，verifier 不使用。**无实际影响** |
| `prog_flags` | `attr->prog_flags` | `prog->aux->prog_flags` (= orig flags & ~TOKEN_FD) | **一致** | 在 HEAD 中已修复（`bpf_prog_load` 保存 `prog_flags` 到 `aux->prog_flags`，REJIT 使用它）。包含 `BPF_F_ANY_ALIGNMENT`、`BPF_F_TEST_RND_HI32` 等所有影响 verifier 的 flag |
| `expected_attach_type` | `attr->expected_attach_type` | `prog->expected_attach_type` | ��致 | |
| `prog_ifindex` | `attr->prog_ifindex` | **未设置** (0) | **不一致** | REJIT 已排除 dev_bound/offloaded 程序 (`bpf_prog_rejit_supported()`)。**无实际影响** |
| `attach_btf_id` | `attr->attach_btf_id` | **未设置** (0) | **不一致** | `attach_btf_id` 在 `bpf_prog_load` 中用于查找 `attach_btf` 和构造 `dst_prog`。REJIT 直接设置 `tmp->aux->attach_btf` 和 `tmp->aux->attach_btf_id`，绕过了 `bpf_check` 开头的查找逻辑。**这是正确的**: `bpf_check` 内部的 `check_attach_btf_id()` 通过 `prog->aux->attach_btf_id` 而非 `attr->attach_btf_id` 工作 |
| `attach_prog_fd` / `attach_btf_obj_fd` | `attr->attach_prog_fd` | **未设置** (0) | **不一致** | 同上，REJIT 直接设置 `tmp->aux->dst_prog`。`bpf_check` 通过 `prog->aux->dst_prog` 工作。**无实际影响** |
| `fd_array` | `attr->fd_array` (用户空间) | REJIT 复制到 kernel buffer 后设置 `load_attr.fd_array` | **一致** | KERNEL_BPFPTR 语义正确处理 |
| `fd_array_cnt` | `attr->fd_array_cnt` | `attr->rejit.fd_array_cnt` | 一致 | |
| `prog_token_fd` | `attr->prog_token_fd` | **未设置** (0) | **不一致** | REJIT 要求 `CAP_BPF + CAP_SYS_ADMIN`，不使用 token 机制。**无实际影响** |
| `prog_name` | `attr->prog_name` | **未设置** (空字符串) | **不一致** | REJIT 通过 `memcpy(tmp->aux->name, prog->aux->name, ...)` 直接复制。**无实际影响** |
| `func_info` / `func_info_cnt` | `attr->func_info` | **未设置** (0) | **不一致** | REJIT 对 EXT 程序预填充 `tmp->aux->func_info` 从原 prog 复制。对非 EXT 程序，`check_btf_info_early()` 在 `func_info_cnt=0` 时返回 0（正确跳过）。**无实际影响** |
| `line_info` / `line_info_cnt` | `attr->line_info` | **未设置** (0) | **不一致** | REJIT 不传递 line_info。verifier 在 `check_btf_info_early()` 中跳过。REJIT 后程序的 bpftool 调试信息会丢失。**功能性降级但不是安全问题** |
| `signature` | `attr->signature` | **未设置** (0) | **不一致** | REJIT 跳过程序签名验证。**安全考量**: REJIT 已要求 `CAP_BPF + CAP_SYS_ADMIN`，且签名验证是 policy 层面的（防止未授权用户加载），REJIT 已有更强的权限要求 |

### 对比结论

**无安全影响的不一致**: `license`、`kern_version`、`prog_ifindex`、`attach_btf_id`、`attach_prog_fd`、`prog_token_fd`��`prog_name`、`func_info`、`line_info`、`signature` — 这些字段要么在 verifier 中不使用，要么 REJIT 通过直接设置 `prog->aux` 字段绕过了 attr 解析。

**已正确处理的关键字段**: `prog_flags`（通过 `aux->prog_flags` 传播所有影响 verifier 的 flag）、`expected_attach_type`、`fd_array`。

**关键发现**: 前期报告 P0-2 声称 `prog_flags` 只复制了 `BPF_F_SLEEPABLE | BPF_F_XDP_HAS_FRAGS` 两个 flag。**这在当前代码中已修复**。当前代码在 `bpf_prog_load` 中保存 `prog->aux->prog_flags = attr->prog_flags & ~BPF_F_TOKEN_FD`，在 REJIT 中使用 `load_attr.prog_flags = prog->aux->prog_flags`。所有影响 verifier 的 flag 都被正确传递。

**`check_struct_ops_btf_id()` 是否被调用**: 是的。`bpf_check()` -> `check_attach_btf_id()` -> 对 `BPF_PROG_TYPE_STRUCT_OPS` 调用 `check_struct_ops_btf_id()`。REJIT 设置了正确的 `prog->type`、`prog->aux->attach_btf`、`prog->aux->attach_btf_id`，所以 struct_ops 验证路径完整。

---

## 6. 总结

### 真正的 P0 安全问题（排除 kinsn 双轨制后）

| # | 问题 | 位置 | 状态 |
|---|------|------|------|
| P0-1 | `bpf_kinsn_has_native_emit()` 未定义，`do_misc_fixups` kinsn fallback 路径控制流损坏 | `verifier.c:23776` | **必须修复** |
| P0-2 | `smp_wmb()` + `WRITE_ONCE` 在 ARM64 上不保证读端 metadata 可见性 | `syscall.c:3449` | **应修复** (x86 上安全但不规范) |
| P0-3 | `tail_call_reachable` 未 swap | `syscall.c:bpf_prog_rejit_swap` | **必须修复** |

### P1 正确性问题

| # | 问题 | 位置 |
|---|------|------|
| P1-1 | swap 遗漏 `arena`、`ctx_arg_info` 等字段 | `syscall.c:bpf_prog_rejit_swap` |
| P1-3 | `find_call_site()` 线性扫描脆弱 | `bpf_struct_ops.c:1481` |
| P1-4 | `bpf_prog_rejit_poke_target_phase` 遍历所有 map | `syscall.c:3288` |
| P1-5 | `INIT_LIST_HEAD_RCU` 在 `synchronize_rcu` 之前重用 | `core.c:657` |
| P1-6 | `orig_insns` 无条件分配 | `syscall.c:3025` |
| P1-7 | `lower_kinsn_proof_regions` 调整逻辑需要注释 | `verifier.c:3836` |

### 前期报告中被降级的问题

| 前期问题 | 原级别 | 修订级别 | 理由 |
|---------|--------|---------|------|
| `prog_flags` 遗漏 (P0-2) | P0 | **已修复** | 当前代码通过 `aux->prog_flags` 正确传播所有 flag |
| `check_struct_ops_btf_id` 未调用 (P0-1) | P0 | **不成立** | `bpf_check` ���部完整调用 struct_ops 验证路径 |
| poke_target_phase UAF (P0-5) | P0 | **P2** | `synchronize_rcu` + `map_poke_run` 保证了安全 |
| struct_ops refresh UAF (P0-4) | P0 | **P1** | 是内存泄漏 + 部分不一致，不是 UAF |
| `free_tmp` btf 泄漏 (P1-5) | P1 | **P2** | `bpf_prog_free` 延迟路径会释放 |

### 整体评价

1. REJIT 的 `load_attr` 构造比前期报告评估的**更安全** — `prog_flags` 的传递问题已在当前代码中修复，struct_ops 验证路径完整
2. **最严重的问题**是 `do_misc_fixups` 中未定义的 `bpf_kinsn_has_native_emit()` — 这要么是编译错误，要么是控制流 bug
3. swap 遗漏 `tail_call_reachable` 是实际的安全问题
4. 内存序问题（`smp_wmb`）在 ARM64 上有理论风险，在 x86 上安全
5. kinsn 整合进 kfunc_desc 的重构方向是正确的（比前期报告描述的"完全平行基础设施"好很多）

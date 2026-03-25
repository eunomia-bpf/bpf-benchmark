# BpfReJIT v2 内核补丁集最终审查报告

**审查日期**: 2026-03-25
**审查者**: 模拟 BPF subsystem maintainer（Alexei Starovoitov 级别）
**分支**: `vendor/linux-framework` master..HEAD
**Diff 规模**: 17 files changed, +1725 / -97 lines

---

## 一、P0 安全问题清单

### P0-1: REJIT verifier 路径缺少 `check_struct_ops_btf_id()` 验证

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit()` 函数，约 L3520-3560

**问题**: `bpf_prog_rejit()` 构造 `load_attr` 调用 `bpf_check()` 时，缺少对 struct_ops 程序的完整验证路径。正常的 `BPF_PROG_LOAD` 路径中，`BPF_PROG_TYPE_STRUCT_OPS` 程序会调用 `check_struct_ops_btf_id()` 验证 struct_ops 方法签名和 BTF 一致性。REJIT 路径通过手动构造 `load_attr` 绕过了这个检查。

具体来说，`bpf_check()` 内部的 `check_struct_ops_btf_id()` 依赖 `attr->attach_btf_obj_fd` 和 prog 类型来决定是否执行。REJIT 构造的 `load_attr` 没有设置 `attach_btf_obj_fd`（因为 struct_ops 使用 `expected_attach_type` 而非 `attach_btf_obj_fd`），但 `expected_attach_type` 是从原 prog 复制的。需要验证 `check_struct_ops_btf_id()` 是否在 REJIT 路径中被完整调用。

**触发条件**: 对 struct_ops 程序执行 REJIT，提交的新 bytecode 如果改变了 struct_ops 方法的语义（例如修改参数使用方式），verifier 可能无法检测到不匹配。

**已确认影响**: 根据 QEMU crash 调查报告，daemon 生成的 malformed bytecode 曾通过 REJIT verifier 进入 JIT 执行。虽然后续 replay 测试表明当前 tree 的 verifier 拒绝了重构的 malformed input，但这不能排除某些 struct_ops 特有路径的绕过。

**修复方案**: 在 `bpf_prog_rejit()` 中 `bpf_check()` 调用前后，对 struct_ops 类型的程序显式调用 `check_struct_ops_btf_id()` 相关验证逻辑。或者重构 `bpf_check()` 使其在 REJIT 模式下也能完整运行 struct_ops 验证路径。

---

### P0-2: `load_attr` 构造遗漏 prog_flags，导致 verifier 行为与 PROG_LOAD 不一致

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit()`, 约 L3498-3502

```c
load_attr.prog_flags = (prog->sleepable ? BPF_F_SLEEPABLE : 0) |
                       (prog->aux->xdp_has_frags ? BPF_F_XDP_HAS_FRAGS : 0);
```

**问题**: 只复制了 2 个 flag。原程序可能带有以下 flag，REJIT 路径会丢失：
- `BPF_F_ANY_ALIGNMENT`: 影响 verifier 对齐检查
- `BPF_F_TEST_RND_HI32`: 影响 verifier 的寄存器高 32 位清零语义
- `BPF_F_XDP_DEV_BOUND_ONLY`: XDP 设备绑定限制

**触发条件**: 原程序带 `BPF_F_ANY_ALIGNMENT` 加载（Cilium 常用），REJIT 时 verifier 使用默认严格对齐检查，可能拒绝合法的 bytecode 变换；或者反过来，原程序不带某个宽松 flag，但 REJIT 路径默认为 0 可能导致某些检查被跳过。

**安全影响**: `BPF_F_TEST_RND_HI32` 的遗漏可能导致 verifier 对 32 位操作的高位清零假设不一致，最终 JIT 生成不安全代码。

**修复方案**: 从原 prog 的完整 `prog_flags`（存储在 `prog->aux` 中）恢复所有 flag，而非手动枚举。或者在 `bpf_prog_aux` 中保存原始 `prog_flags` 并在 REJIT 时直接使用。

---

### P0-3: `bpf_prog_rejit_swap()` 中 `smp_store_release` 与读端缺少配对的 `smp_load_acquire`

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_swap()`, 约 L3400-3405

```c
smp_store_release(&prog->bpf_func, tmp->bpf_func);
```

**问题**: 使用 `smp_store_release` 发布新的 `bpf_func` 指针。但 BPF 运行时的读端（`BPF_PROG_RUN` 宏、trampoline 入口）使用的是 `prog->bpf_func` 的普通读取（不是 `smp_load_acquire`，也不是 `rcu_dereference`）。

在 x86 上，TSO 保证了 store 的顺序性，所以 `smp_store_release` 等价于普通 store + compiler barrier，实际是安全的。但在 **ARM64** 上（代码也有 ARM64 支持），`smp_store_release` 需要配对的 `smp_load_acquire` 才能保证所有先前的 metadata write 对读端可见。如果读端用普通 load 读取 `bpf_func`，可能在看到新 `bpf_func` 的同时看到旧的 metadata（如 `prog->len`、`prog->insnsi` 等）。

**触发条件**: ARM64 SMP 系统上，一个 CPU 正在执行 REJIT swap，另一个 CPU 正在通过 trampoline 调用该 prog。读端可能看到新 `bpf_func` 但旧 metadata。

**修复方案**:
1. 将 `bpf_func` 的发布改为 `rcu_assign_pointer(prog->bpf_func, tmp->bpf_func)`，读端使用 `rcu_dereference(prog->bpf_func)`。
2. 或者在 swap 和 RCU grace period 之间添加 `smp_wmb()` 并确认所有读端在 RCU 读侧临界区内。
3. 当前代码在 swap 后紧跟 `synchronize_rcu`/`synchronize_rcu_tasks_trace`，这意味着在 grace period 之前释放旧镜像是安全的——但问题不在释放，而在 metadata 可见性窗口。

---

### P0-4: `bpf_struct_ops_refresh_prog()` 失败后 `err` 被吞没，导致 UAF

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit()` 主函数，约 L3600-3615

```c
if (rcu_access_pointer(prog->aux->st_ops_assoc)) {
    err = bpf_struct_ops_refresh_prog(prog, old_bpf_func);
    if (err) {
        pr_warn("bpf_rejit: struct_ops refresh failed: %d\n", err);
        ret = err;
        err = bpf_prog_rejit_rollback(prog, tmp, new_bpf_func, ...);
        if (err) {
            pr_warn("bpf_rejit: rollback after struct_ops refresh failure failed: %d\n", err);
            retain_old_image = true;
        }
        goto post_swap_sync;
    }
}
```

**分析**: 当 `bpf_struct_ops_refresh_prog()` 返回 `-ENOENT`（call site not found）时，代码进入 rollback。但如果 rollback 成功（`err == 0`），`ret` 仍保留了错误码，函数最终返回 `ret`（非零错误）。这本身是正确的——返回错误告诉用户 REJIT 失败。

但**真正的问题**在 `bpf_struct_ops_refresh_prog()` 的实现中（`kernel/bpf/bpf_struct_ops.c`）：

```c
if (!call_site) {
    pr_warn("struct_ops rejit: CALL site not found in trampoline %s\n", ksym->name);
    return -ENOENT;
}
```

如果 `find_call_site` 找不到旧的 `bpf_func` call site（因为 trampoline 可能已被其他路径更新），函数提前返回错误。但此时 swap 已经完成——`prog->bpf_func` 已经指向新镜像。回到 syscall.c 的 rollback 路径，rollback 会再次执行 swap（恢复旧 `bpf_func`），然后调用 `bpf_trampoline_refresh_prog()` 和 `bpf_struct_ops_refresh_prog()` 刷新到旧地址。

**关键风险**: 如果 rollback 中的 `bpf_struct_ops_refresh_prog()` 也失败（旧 call site 同样找不到），`retain_old_image = true` 阻止释放旧镜像——这正确防止了 UAF。但如果 rollback 中的 `bpf_trampoline_refresh_prog()` 成功但 `bpf_struct_ops_refresh_prog()` 失败，trampoline 指向旧 `bpf_func`（正确），但 struct_ops trampoline 仍指向新 `bpf_func`（错误地址，因为 swap 恢复了旧 `bpf_func`），这是 **UAF**——struct_ops trampoline 会跳转到新镜像，而新镜像在 `retain_old_image = false` 路径会被释放。

实际上 `retain_old_image` 只保护旧镜像不释放（`__bpf_prog_put_noref(tmp, ...)` 被跳过），但此时 tmp 持有的是新镜像（swap 后 tmp 有旧镜像，再次 rollback swap 后 tmp 又有新镜像）。逻辑极其复杂，容易出错。

**修复方案**:
1. 将 struct_ops 的 text_poke 从"查找 call site"改为通过 struct_ops_map 保存的已知偏移直接 patch。
2. 如果任何 refresh 失败且 rollback 也失败，应该让 prog 进入"不可执行"状态（清除 `bpf_func`），而非保留半更新状态。

---

### P0-5: `bpf_prog_rejit_poke_target_phase()` delete/insert 窗口存在 UAF 风险

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_poke_target_phase()`, 约 L3280-3340

```c
/*
 * This is an intentionally lockless pre-check. A slot can
 * change between this read and map_poke_run(), but both
 * directions are benign...
 */
if (array->ptrs[key] != prog)
    continue;
```

**问题**: Phase 1（delete）在 swap 前执行，将所有指向 `prog` 的 tail_call 直接跳转 patch 为 NOP。Phase 2（insert）在 swap 后执行，将 NOP patch 为跳转到新 `bpf_func`。

在 Phase 1 和 Phase 2 之间：
1. `bpf_prog_rejit_swap()` 执行，`prog->bpf_func` 变为新地址。
2. 如果在 Phase 1 执行过程中，另一个 CPU 通过 `bpf_prog_array_update` 将 `prog` 加入了一个新的 PROG_ARRAY slot（Phase 1 已经扫描过该 slot），那个 slot 的 poke site 仍然编码着旧 `bpf_func` 地址。
3. Phase 2 可能也会遗漏这个 slot（如果扫描时该 slot 又被修改）。
4. 旧 JIT 镜像在 `synchronize_rcu` + `__bpf_prog_put_noref` 后被释放。
5. 那个漏网的 slot 的 poke site 仍然跳转到已释放的旧镜像——**UAF**。

**注释声称安全的论据**: "miss a newly added slot until that update path repokes it"。但 `bpf_prog_array_update` 调用 `poke_run` 时使用的是当前 `prog->bpf_func`（已是新地址），所以新 slot 的 poke 确实会指向新地址。关键问题是：在 `poke_run` 执行之前，那个 slot 的 poke site 编码的旧地址是否还有 CPU 在执行？

由于 swap 后有 `synchronize_rcu`，所有在 swap 前进入 RCU 读侧临界区的 CPU 都已退出。tail_call 的执行也在 RCU 保护下（`rcu_read_lock` in `bpf_prog_run`），所以 `synchronize_rcu` 保证了没有 CPU 还在使用旧镜像。但那个漏网 slot 的 poke site 编码的仍是旧地址——如果在 `synchronize_rcu` 之后有新的执行到达那个 poke site，它会跳转到已释放的地址。

**然而**: `bpf_prog_array_update` 中的 `poke_run` 调用在更新 slot 后 **同步** patch poke site。所以到那个 slot 可被新执行到达时，poke site 已经被 patch 为新地址了。但这依赖于 `map_update` 路径的 `poke_run` 在 slot 可见之前完成——这取决于 `poke_mutex` 和 memory ordering 是否正确。

**结论**: 这是一个**理论上的竞态窗口**，实际触发概率极低（需要 REJIT + 并发 map_update + 特定时序），但对于内核安全代码，理论上的 UAF 就是 P0。

**修复方案**: 在 REJIT 期间持有所有涉及的 PROG_ARRAY map 的 `poke_mutex`，防止并发 `map_update`。或者在 Phase 1 和 Phase 2 之间不释放 map ref，确保扫描的原子性。

---

### P0-6: kinsn `emit_x86`/`emit_arm64` 回调可生成任意 native code，绕过 verifier

**代码位置**:
- `arch/x86/net/bpf_jit_comp.c`, `emit_kinsn_desc_call()`, 约 L580-610
- `arch/arm64/net/bpf_jit_comp.c`, `emit_kinsn_desc_call_arm64()`, 约 L1195-1220
- `include/linux/bpf.h`, `struct bpf_kinsn` 定义

**问题**: `kinsn->emit_x86(scratch, &off, emit, payload, bpf_prog)` 是一个模块提供的回调，可以向 JIT 镜像中写入**任意 x86 机器代码**。唯一的限制是 `max_emit_bytes` 检查了输出长度，但完全不检查内容。

与此同时，`kinsn->instantiate_insn()` 生成的"proof sequence"是 verifier 实际验证的代码。但 JIT 执行的是 `emit_x86` 的输出。这意味着 **verifier 看到的代码（proof）和 JIT 执行的代码（native emit）不同** —— "双轨制"验证。

一个 buggy 或恶意的内核模块可以：
1. 让 `instantiate_insn` 返回无害的 `MOV R0, 0; EXIT` proof sequence
2. 让 `emit_x86` 生成 `int3; mov rdi, rsp; call arbitrary_func` 等任意代码

**触发条件**: 加载一个提供 kinsn descriptor 的内核模块。由于 kinsn 通过 `btf_kfunc_id_set.kinsn_descs[]` 注册（btf.c 中新增的路径），任何注册了 kfunc ID set 的模块都可以附带 kinsn descriptor。

**缓解因素**: 加载内核模块本身需要 `CAP_SYS_MODULE`。但 BPF 的安全模型假设即使 root 也不能通过 BPF 执行任意代码（verifier 保证）。kinsn 打破了这个假设——root + 可加载模块 = 可在 BPF JIT 镜像中注入任意代码。

**修复方案**:
1. 短期：增加 `CONFIG_BPF_KINSN` Kconfig 选项，默认关闭。
2. 中期：移除 per-arch emit callback，所有 kinsn 的 native code 必须通过标准 BPF 指令 + JIT 路径生成。
3. 长期：将 kinsn 统一到 kfunc 框架，通过 BTF 类型系统约束行为。

---

## 二、P1 正确性问题清单

### P1-1: `bpf_prog_rejit_swap()` 遗漏 `arena` 相关字段

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_swap()`

**问题**: 当前 swap 了 25+ 个字段，但遗漏了以下可能需要 swap 的字段：
- `prog->aux->arena`: 如果新 bytecode 使用了 arena（BPF arena），`arena` 指针需要更新。
- `prog->aux->sleepable_used_maps`: sleepable 程序的特殊 map 追踪。
- `prog->aux->tail_call_reachable`: 如果新 bytecode 改变了 tail_call 可达性，这个 flag 不一致会导致 tail_call 计数器处理错误。
- `prog->aux->exception_cb`: 用户态异常回调（`bpf_throw` 相关）。

遗漏任何字段都可能导致 bpf_func 指向新 JIT 镜像，但 metadata 仍然是旧的，造成运行时不一致。

**修复方案**: 将 `bpf_prog_aux` 中的"verification/JIT 输出"字段分组为 `struct bpf_prog_compile_result` 子结构，swap 整个子结构。这样新增字段时不会遗漏。

---

### P1-2: `memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp))` 溢出风险

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_swap()`, 约 L3390

```c
memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));
prog->len = tmp->len;
```

**问题**: `prog->insnsi` 是 `struct bpf_prog` 末尾的 flexible array member，其实际分配大小由 `bpf_prog_alloc(bpf_prog_size(orig_len), ...)` 决定。如果 `tmp->len > prog` 的原始分配长度，`memcpy` 会越界写入。

前置检查：
```c
if (bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE) {
    err = -E2BIG;
    goto free_tmp_noref;
}
```

`prog->pages` 是 `bpf_prog_alloc` 时的分配页数。但 `bpf_prog_alloc` 实际分配的是 `round_up(size, PAGE_SIZE)` 大小（通过 `__vmalloc`），而 `prog->pages = size / PAGE_SIZE`。所以检查 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE` 是正确的——确保新 insn 大小 fit 在原分配中。

**但**: `bpf_prog_size` 包含了 `struct bpf_prog` 的固定部分 + flexible array。所以实际 insn 区域的可用空间是 `prog->pages * PAGE_SIZE - offsetof(struct bpf_prog, insnsi)`。而 `bpf_prog_insn_size(tmp) = tmp->len * sizeof(struct bpf_insn)`。只要 `bpf_prog_size(tmp->len) <= prog->pages * PAGE_SIZE`，insn 区域就足够。

**结论**: 前置检查**在当前实现中是正确的**，但非常脆弱——如果 `bpf_prog_size` 的计算方式变化，或 `prog->pages` 的含义变化，这个检查就会失效。建议添加一个更直接的检查：`bpf_prog_insn_size(tmp) <= bpf_prog_insn_size_alloc(prog)`。

---

### P1-3: `bpf_trampoline_refresh_prog()` 的 `old_bpf_func` 参数未使用

**代码位置**: `kernel/bpf/trampoline.c`, `bpf_trampoline_refresh_prog()`

```c
int bpf_trampoline_refresh_prog(struct bpf_prog *prog, bpf_func_t old_bpf_func)
{
    struct bpf_tramp_user *tu;
    int err = 0;

    list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
        struct bpf_trampoline *tr = tu->tr;
        mutex_lock(&tr->mutex);
        err = bpf_trampoline_update(tr, true);
        mutex_unlock(&tr->mutex);
        if (err)
            break;
    }
    return err;
}
```

**问题**: `old_bpf_func` 参数在函数体中完全未使用。`bpf_trampoline_update()` 会重建整个 trampoline 镜像，自动获取当前 `prog->bpf_func`（已是新地址），所以不需要旧地址。

但在 `bpf_struct_ops_refresh_prog()` 中，`old_bpf_func` **是**被使用的（用于 `find_call_site`）。两个函数的接口不一致。

**影响**: 不是 bug，但是 dead code 和 API 不一致。

**修复方案**: 如果 `bpf_trampoline_refresh_prog` 确实不需要 `old_bpf_func`，删除该参数。如果未来需要，添加注释说明为何保留。

---

### P1-4: 每个 BPF 程序都分配 `orig_insns` 和 `rejit_mutex`，即使从不用 REJIT

**代码位置**:
- `kernel/bpf/syscall.c`, `bpf_prog_load()`: 无条件分配 `orig_insns`
- `kernel/bpf/core.c`, `bpf_prog_alloc_no_stats()`: 无条件初始化 `rejit_mutex`

**问题**: 对于有 10000+ BPF 程序的系统（如 Cilium、Falco），每个程序额外分配 `sizeof(struct mutex)` + `sizeof(struct list_head)` + `insn_cnt * 8 bytes` 的 `orig_insns`。对于一个 1000 insn 的程序，`orig_insns` 就是 8KB。10000 个程序 = 80MB 额外内存。

**修复方案**:
1. `orig_insns` 只在第一次 REJIT 调用时保存（lazy allocation），或通过 `BPF_F_KEEP_ORIG_INSNS` flag 控制。
2. `rejit_mutex` 和 `trampoline_users` 按需分配（包装在一个 `struct bpf_rejit_state` 中，指针为 NULL 直到首次 REJIT）。

---

### P1-5: `bpf_prog_rejit()` 的 `free_tmp` 错误路径清理不完整

**代码位置**: `kernel/bpf/syscall.c`, `bpf_prog_rejit()` 末尾的错误处理

```c
free_tmp_sec:
    security_bpf_prog_free(tmp);
free_tmp:
    if (tmp->aux->dst_prog)
        bpf_prog_put(tmp->aux->dst_prog);
    tmp->aux->dst_prog = NULL;
    if (tmp->aux->attach_btf)
        btf_put(tmp->aux->attach_btf);
    tmp->aux->attach_btf = NULL;
    kvfree(tmp->aux->func_info);
    tmp->aux->func_info = NULL;
    kfree(tmp->aux->func_info_aux);
    tmp->aux->func_info_aux = NULL;
    free_uid(tmp->aux->user);
    kvfree(tmp->aux->orig_insns);
    bpf_prog_free(tmp);
```

**问题**:
1. `free_tmp_sec` 标签调用 `security_bpf_prog_free()` 然后 fall-through 到 `free_tmp`，但 `free_tmp` 中又可能 double-free 某些资源（如果 `security_bpf_prog_load` 部分成功时已分配了某些 security context）。
2. `free_tmp` 清理了 `dst_prog`、`attach_btf`、`func_info`、`func_info_aux`、`user`、`orig_insns`，但没有清理 `tmp->aux->btf`（在 EXT 程序路径中 `btf_get(prog->aux->btf)` 增加了引用计数）。如果 `bpf_check` 未被调用就跳到 `free_tmp`，`tmp->aux->btf` 的引用会泄漏。

实际上在 EXT 程序路径中：
```c
btf_get(prog->aux->btf);
tmp->aux->btf = prog->aux->btf;
```
如果后续 `security_bpf_prog_load` 或 `bpf_check` 前的操作失败，跳到 `free_tmp`，`tmp->aux->btf` 的引用泄漏——因为 `free_tmp` 没有 `btf_put(tmp->aux->btf)`。

但 `bpf_prog_free()` -> `__bpf_prog_put_noref()` -> ... 是否会释放 `btf`？看 `__bpf_prog_put_noref` 的代码：它调用 `btf_put(prog->aux->btf)` 通过 `bpf_prog_free_deferred`。所以 `bpf_prog_free(tmp)` **会**释放 `btf` 引用。

**等等**，但 `free_tmp` 中调用的是 `bpf_prog_free(tmp)` 而非 `__bpf_prog_put_noref`。`bpf_prog_free` 走的是 `call_rcu(&prog->aux->rcu, bpf_prog_free_deferred)`。`bpf_prog_free_deferred` 最终调用 `bpf_prog_free_id(prog)` 等，但 tmp 没有 ID（未通过 `bpf_prog_new_fd`）。

这条路径需要更仔细的审计。

**修复方案**: 统一错误清理路径，使用与 `__bpf_prog_put_noref` 一致的清理逻辑。或者在 `free_tmp` 中显式清理所有可能被设置的字段。

---

### P1-6: `lower_kinsn_proof_regions()` 的 region start 调整逻辑有 off-by-one 风险

**代码位置**: `kernel/bpf/verifier.c`, `lower_kinsn_proof_regions()`

```c
for (j = 0; j < env->kinsn_region_cnt - 1; j++) {
    struct bpf_kinsn_region *prior = &env->kinsn_regions[j];
    s32 new_start;

    if (prior->start <= region->start)
        continue;

    new_start = (s32)prior->start + (cnt - 2);
    if (WARN_ON_ONCE(new_start < 0))
        new_start = 0;
    prior->start = new_start;
}
```

**问题**: 倒序遍历 insn 数组修改指令，同时正序遍历 `kinsn_regions[]` 调整 `start`。由于倒序修改，先处理高地址的 kinsn，此时低地址的 region start 不需要调整。但 `kinsn_regions[]` 的填充顺序是**倒序**（从 `env->prog->len - 1` 向 0 遍历，先遇到的高地址先加入数组）。所以 `kinsn_regions[0]` 是最高地址的 kinsn，`kinsn_regions[cnt-1]` 是最低地址的。

当处理 `kinsn_regions[k]` 时，`j` 从 0 遍历到 `k-1`。`prior->start > region->start` 意味着 prior 的地址 > 当前地址——但 prior 是更早加入的（即原始地址更高），已经被处理过了。它们的 start 已经是 lowered 后的值。

**风险**: 如果两个 kinsn region 相邻（连续的 sidecar+call 对），`verifier_remove_insns` + `bpf_patch_insn_data` 修改了 insn 数组长度后，prior 的 adjusted start 可能不正确——因为 prior 的 start 是基于之前的 lowering 结果，而当前 lowering 又改变了 insn 数组。

**修复方案**: 添加详细的 assert/invariant 检查。或者改为两遍：第一遍收集所有 kinsn 位置，第二遍从高到低一次性 patch。

---

### P1-7: `bpf_trampoline_link_prog` 中锁序 `rejit_mutex -> tr->mutex` 与潜在死锁

**代码位置**: `kernel/bpf/trampoline.c`, `bpf_trampoline_link_prog()`

```c
mutex_lock(&link->link.prog->aux->rejit_mutex);
mutex_lock(&tr->mutex);
err = __bpf_trampoline_link_prog(link, tr, tgt_prog);
...
mutex_unlock(&tr->mutex);
mutex_unlock(&link->link.prog->aux->rejit_mutex);
```

**问题**: 锁序是 `rejit_mutex -> tr->mutex`。在 `bpf_trampoline_refresh_prog()` 中，调用者已持有 `rejit_mutex`，然后获取 `tr->mutex`——顺序一致。在 `bpf_trampoline_unlink_prog()` 中也是一致的。

但如果有第三个路径需要先获取 `tr->mutex` 再获取 `rejit_mutex`（例如 trampoline GC 或某些回调），就会死锁。目前代码中未发现这种路径，但缺少文档化的锁序不变量。

**修复方案**: 在 `include/linux/bpf.h` 的 `rejit_mutex` 声明处添加注释文档化锁序：`/* Lock ordering: rejit_mutex -> tr->mutex -> poke_mutex */`。

---

## 三、P2 架构问题清单

### P2-1: kinsn 完整平行基础设施应合并到 kfunc 框架

**涉及文件**:
- `kernel/bpf/verifier.c`: `bpf_kinsn_desc`, `bpf_kinsn_desc_tab` 等被完全删除，改为在 `bpf_kfunc_desc` 中增加 `kinsn` 指针（实际上代码已经走向了这个方向——`bpf_kfunc_desc` 已有 `kinsn` 字段）
- `kernel/bpf/btf.c`: `btf_kfunc_kinsn_set` 并行数据结构
- `include/linux/bpf.h`: `struct bpf_kinsn` 的 per-arch callback
- `include/uapi/linux/bpf.h`: `BPF_PSEUDO_KINSN_SIDECAR`, `BPF_PSEUDO_KINSN_CALL`

**分析**: 审查代码后发现，**实际的 verifier.c 实现已经将 kinsn 整合进了 kfunc_desc**：`add_kfunc_desc()` 统一处理 kfunc 和 kinsn call，`bpf_kfunc_desc` 已有 `kinsn` 字段。这比之前报告描述的"完全平行基础设施"要好得多。

然而 btf.c 中仍然有独立的 `btf_kfunc_kinsn_set` / `btf_kfunc_kinsn_desc` 数据结构。UAPI 中仍有两个独立的 pseudo 常量。JIT 中仍有独立的 `BPF_PSEUDO_KINSN_CALL` dispatch 分支。

**建议**:
1. UAPI: 保留 `BPF_PSEUDO_KINSN_CALL` 但在内核内部 normalize 为 `BPF_PSEUDO_KFUNC_CALL` + `KF_KINSN` flag
2. btf.c: 将 `kinsn_descs[]` 直接关联到 `btf_id_set8.flags` 中的 flag 位，而非独立的并行数组
3. JIT: 在 kfunc call 路径中检查 `desc->kinsn` 而非在 dispatch 级别分支

---

### P2-2: sidecar 伪指令（`BPF_PSEUDO_KINSN_SIDECAR`）是对 BPF ISA 的滥用

**问题**: 重载 `BPF_ALU64 | BPF_MOV | BPF_K` 的 `src_reg` 字段（正常应为 0）来传递 kinsn payload metadata。这种编码方式：
1. 违反 BPF ISA 规范（`src_reg` 在 K-mode 应为 0）
2. 混淆所有解析 BPF 指令的工具（bpftool, libbpf, objdump）
3. 需要在 verifier、JIT、backtrack、disasm 等多处添加特殊处理

**替代方案**: 使用 `BPF_LD | BPF_IMM | BPF_DW`（ldimm64）作为 sidecar 载体——这是 BPF ISA 中现有的 128-bit 指令，有 64-bit 的 payload 空间，且已有工具支持。或者将 payload 编码在 kfunc call 指令本身的 `imm`/`off` 字段中。

---

### P2-3: `bpf_prog_rejit()` 构造 `load_attr` 调用 `bpf_check()` 的 hack

**问题**: 手动映射 `rejit.xxx` 到 `prog_load.xxx` 字段，使用 `KERNEL_BPFPTR` 假装是内核态调用。`BPF_PROG_REJIT_LOAD_ATTR_SIZE = offsetofend(union bpf_attr, keyring_id)` 硬编码了 `union bpf_attr` 的内存布局。

这种做法：
1. 随着 UAPI 演进极易崩溃
2. 缺少字段的问题（P0-2）就是这种设计的直接后果
3. 使得 REJIT 和 PROG_LOAD 的验证路径微妙不同

**修复方案**: 从 `bpf_check()` 中抽取核心验证逻辑为 `bpf_verify_prog(struct bpf_prog *prog, struct bpf_verify_opts *opts)`，不依赖 `union bpf_attr`。

---

### P2-4: btf.c 中 `btf_kfunc_is_allowed` / `btf_kfunc_flags` 的 `goto again` 循环重构

**代码位置**: `kernel/bpf/btf.c`, `btf_kfunc_is_allowed()` 和 `btf_kfunc_flags()`

**问题**: 原代码是清晰的两步查找（先 COMMON hook，再 prog-type hook）。新代码改为 `goto again` 循环，逻辑等价但可读性下降。这个改动与 REJIT/kinsn 功能无关。

**建议**: 恢复原代码结构，或如果确实需要重构，作为独立 prep patch 提交。

---

### P2-5: `find_call_site()` 在 `bpf_struct_ops.c` 中内联了 x86/ARM64 反汇编器

**代码位置**: `kernel/bpf/bpf_struct_ops.c`, `find_call_site()`

**问题**: 手写了 x86 insn 解码器（使用 `insn_init`/`insn_get_length`）和 ARM64 branch offset 解析。这些应该使用现有的 `bpf_arch_text_poke` 框架或保存 call site 偏移到 struct_ops_map 中，而非运行时线性扫描整个 trampoline 镜像。

**修复方案**: 在 struct_ops trampoline 构建时记录每个 prog 的 call site 偏移到 `st_map` 中。REJIT 时直接使用保存的偏移，无需线性扫描。

---

## 四、逐文件 Review

### 4.1 `include/uapi/linux/bpf.h` (+24)

| 项目 | 判定 |
|------|------|
| `BPF_PROG_REJIT` 新 bpf_cmd | ACK (命名可商议) |
| `BPF_PSEUDO_KINSN_SIDECAR` | 要求修改 (P2-2) |
| `BPF_PSEUDO_KINSN_CALL` | 有条件 ACK (统一后可保留为 compat) |
| `rejit` attr struct | 要求修改 (缺 license 等字段, P0-2) |
| `bpf_prog_info` 的 `orig_prog_len`/`orig_prog_insns` | ACK |

**总判定**: 要求修改

### 4.2 `include/linux/bpf.h` (+60)

| 项目 | 判定 |
|------|------|
| `struct bpf_kinsn` | 要求修改 (per-arch callback -> 统一到 kfunc, P0-6) |
| `bpf_kinsn_is_sidecar_insn` / `bpf_kinsn_sidecar_payload` | 要求修改 (P2-2) |
| `struct bpf_tramp_user` | ACK |
| `bpf_dispatcher_refresh_prog` 声明 | ACK |
| `bpf_trampoline_refresh_prog` 声明 | ACK |
| `rejit_mutex` / `trampoline_users` 在 `bpf_prog_aux` | 要求修改 (按需分配, P1-4) |
| `orig_insns` / `orig_prog_len` 在 `bpf_prog_aux` | 要求修改 (按需分配, P1-4) |
| `bpf_struct_ops_refresh_prog` 声明 | ACK |
| `bpf_jit_get_kinsn_payload` 声明 | ACK |

**总判定**: 要求修改

### 4.3 `include/linux/bpf_verifier.h` (+13)

| 项目 | 判定 |
|------|------|
| `struct bpf_kinsn_region` | ACK (proof lowering 需要) |
| `kinsn_regions` 等 4 个字段在 `bpf_verifier_env` | ACK |
| `btf_kfunc_kinsn_desc` 声明 | ACK |

**总判定**: ACK

### 4.4 `include/linux/btf.h` (+2)

| 项目 | 判定 |
|------|------|
| `struct bpf_kinsn` forward decl | ACK |
| `kinsn_descs` 在 `btf_kfunc_id_set` | ACK (注册路径) |

**总判定**: ACK

### 4.5 `include/linux/filter.h` (+1)

| 项目 | 判定 |
|------|------|
| `bpf_prog_refresh_xdp` 声明 | ACK |

**总判定**: ACK

### 4.6 `arch/x86/net/bpf_jit_comp.c` (+39)

| 项目 | 判定 |
|------|------|
| `emit_kinsn_desc_call` | 要求修改 (P0-6: 任意 native code) |
| sidecar skip in `BPF_ALU64 | BPF_MOV | BPF_K` | ACK with nit |
| `BPF_PSEUDO_KINSN_CALL` dispatch | ACK |

**总判定**: 要求修改

### 4.7 `arch/arm64/net/bpf_jit_comp.c` (+38)

| 项目 | 判定 |
|------|------|
| `emit_kinsn_desc_call_arm64` | 要求修改 (同 P0-6) |
| sidecar skip | ACK |
| `BPF_PSEUDO_KINSN_CALL` dispatch | ACK |

**总判定**: 要求修改

### 4.8 `kernel/bpf/verifier.c` (+582, -97)

| 项目 | 判定 |
|------|------|
| `bpf_pseudo_kinsn_call()` | ACK |
| `kinsn` 字段加入 `bpf_kfunc_meta` 和 `bpf_kfunc_desc` | ACK (已统一) |
| `__find_kfunc_desc_btf` 按需分配 `kfunc_btf_tab` | ACK (修复资源泄漏) |
| `fetch_kfunc_meta` 中添加 `btf_kfunc_kinsn_desc` 查找 | ACK |
| `add_kfunc_desc` 统一替代 `add_kfunc_call` | ACK (好的重构) |
| `sort_kfunc_descs_by_imm_off` 中 kinsn 跳过 `set_kfunc_desc_imm` | ACK |
| `bpf_prog_has_desc_kind` / `bpf_prog_has_kfunc_call` / `bpf_prog_has_kinsn_call` | ACK |
| `bpf_jit_find_kfunc_model` 中跳过 kinsn desc | ACK |
| `validate_kinsn_proof_seq` | ACK (严格的 proof 验证) |
| `lower_kinsn_proof_regions` | 要求修改 (P1-6: off-by-one 风险) |
| `restore_kinsn_proof_regions` | ACK with nit (jt 清理逻辑需要注释) |
| `bpf_kinsn_has_native_emit` | ACK |
| `bpf_jit_get_kinsn_payload` | ACK |
| `add_subprog_and_kfunc` 中 kinsn 计数 | ACK |
| `disasm_kfunc_name` 扩展 | ACK |
| `backtrack_insn` 中 sidecar skip | ACK |
| `check_kinsn_sidecar_insn` | ACK |
| `do_check_insn` 中 sidecar 检查 | ACK |
| `do_check_insn` 中 kinsn call 到达 verifier 的 EFAULT | ACK (防御性检查) |
| `fixup_call_args` 中 kinsn 检查 | ACK |
| `do_misc_fixups` 中 kinsn sidecar 展开 fallback | ACK |
| `bpf_check()` 中初始化顺序变更 | ACK (kinsn lowering 必须在 explored_states 前) |
| `bpf_check()` cleanup 中 `restore_kinsn_proof_regions` | ACK |

**总判定**: 要求修改 (P1-6)，其余 ACK

### 4.9 `kernel/bpf/syscall.c` (+696)

| 项目 | 判定 |
|------|------|
| `orig_insns` 保存和释放 | 要求修改 (P1-4: 按需分配) |
| `bpf_prog_rejit_supported` | ACK with nit (缺少若干检查) |
| `bpf_prog_rejit_update_poke_tab` | ACK |
| `bpf_prog_rejit_untrack_tmp_pokes` | ACK |
| `bpf_prog_rejit_poke_target_phase` | 要求修改 (P0-5: UAF 风险) |
| `bpf_prog_rejit_swap` | 要求修改 (P0-3, P1-1, P1-2) |
| `bpf_prog_rejit_rollback` | 要求修改 (P0-4 相关) |
| `bpf_prog_rejit` 主函数 | 要求修改 (P0-1, P0-2, P2-3) |
| `bpf_prog_get_info_by_fd` orig_insns 暴露 | ACK |

**总判定**: 要求修改

### 4.10 `kernel/bpf/trampoline.c` (+53)

| 项目 | 判定 |
|------|------|
| `bpf_trampoline_link_prog` 中 tramp_user 追踪 | ACK |
| `bpf_trampoline_unlink_prog` 中 tramp_user 移除 | ACK |
| `bpf_trampoline_refresh_prog` | 要求修改 (P1-3: dead parameter, P1-7: 锁序文档) |

**总判定**: 要求修改 (小修)

### 4.11 `kernel/bpf/bpf_struct_ops.c` (+108)

| 项目 | 判定 |
|------|------|
| `find_call_site` (x86 + ARM64) | 要求修改 (P2-5: 应保存偏移而非运行时扫描) |
| `bpf_struct_ops_refresh_prog` | 要求修改 (P0-4 相关) |

**总判定**: 要求修改

### 4.12 `kernel/bpf/btf.c` (+149, -8)

| 项目 | 判定 |
|------|------|
| `btf_kfunc_kinsn_desc` / `btf_kfunc_kinsn_set` | 要求修改 (P2-1: 应与 kfunc set 合并) |
| `btf_free_kfunc_set_tab` 中 kinsn_sets 释放 | ACK |
| `btf_kfunc_kinsn_desc_cmp` | ACK |
| `btf_populate_kfunc_set` 中 kinsn_descs 处理 | 要求修改 (与 kfunc set 的并行结构) |
| `btf_kfunc_kinsn_set_contains` | ACK |
| `btf_kfunc_is_allowed` / `btf_kfunc_flags` 的 goto again 重构 | 要求修改 (P2-4: 不必要的改动) |
| `btf_kfunc_kinsn_desc` 公开 API | ACK |
| `__register_btf_kfunc_id_set` 中 kinsn owner 验证 | ACK (安全检查) |

**总判定**: 要求修改

### 4.13 `kernel/bpf/core.c` (+3)

| 项目 | 判定 |
|------|------|
| `mutex_init(&fp->aux->rejit_mutex)` | 要求修改 (P1-4: 按需分配) |
| `INIT_LIST_HEAD(&fp->aux->trampoline_users)` | 同上 |
| `INIT_LIST_HEAD_RCU(&ksym->lnode)` | ACK (修复 double-add) |

**总判定**: 要求修改 (小修)

### 4.14 `kernel/bpf/disasm.c` (+2)

| 项目 | 判定 |
|------|------|
| `BPF_PSEUDO_KINSN_CALL` 分支 | ACK |

**总判定**: ACK

### 4.15 `kernel/bpf/dispatcher.c` (+23, -1)

| 项目 | 判定 |
|------|------|
| `bpf_dispatcher_update` 增加 `expedited` 参数 | ACK |
| `bpf_dispatcher_refresh_prog` | ACK |
| `bpf_dispatcher_change_prog` 传 `false` | ACK |

**总判定**: ACK

### 4.16 `net/core/filter.c` (+5)

| 项目 | 判定 |
|------|------|
| `bpf_prog_refresh_xdp` | ACK |

**总判定**: ACK

### 4.17 `tools/include/uapi/linux/bpf.h` (+24)

| 项目 | 判定 |
|------|------|
| UAPI tools/ 副本同步 | ACK (随主 UAPI) |

**总判定**: ACK (随 4.1 修改)

---

## 五、不必要改动清单

| # | 文件 | 改动描述 | 行数 | 与 BpfReJIT 的关系 |
|---|------|---------|------|------------------|
| 1 | `btf.c` | `btf_kfunc_is_allowed` 和 `btf_kfunc_flags` 从两步查找改为 goto-again 循环 | ~20 | 无关。纯重构，可读性反而下降 |
| 2 | `btf.c` | `btf_populate_kfunc_set` 中 memcpy 换行 | 2 | 无关。cosmetic |
| 3 | `verifier.c` | `-ENOTSUPP` -> `-EOPNOTSUPP` 修正 | 3 | 独立 bug fix，应单独提交 |

**说明**: 相比之前报告描述的"大量不必要改动"，实际审查发现当前代码已经做了较好的整合（kinsn desc 已合入 kfunc_desc）。不必要改动集中在 btf.c 的查找函数重构和少量 cosmetic 修改。

---

## 六、最终判定

### 当前状态能否合入？

**不能。** 存在 6 个 P0 安全问题和 7 个 P1 正确性问题。

### 需要几轮修改？

**预计 3 轮**：

**第 1 轮（安全关键）**:
1. 修复 P0-1: REJIT verifier 路径的 struct_ops 验证完整性
2. 修复 P0-2: `load_attr` 的完整 prog_flags 传递
3. 修复 P0-3: `smp_store_release` 与读端配对（或改为 `rcu_assign_pointer`）
4. 修复 P0-4: struct_ops refresh 失败路径的 UAF
5. 修复 P0-5: poke target phase 的并发安全
6. 评估 P0-6: kinsn native emit 的安全模型（可能需要设计层面的讨论）

**第 2 轮（正确性 + 架构）**:
1. 修复 P1-1: swap 遗漏字段 → sub-struct 重构
2. 修复 P1-4: 按需分配 orig_insns/rejit_mutex
3. 修复 P1-5: 错误路径清理完整性
4. 实施 P2-1: btf.c 中 kinsn_set 合并到 kfunc set
5. 实施 P2-3: `bpf_check()` 接口重构
6. 实施 P2-5: struct_ops call site 偏移保存

**第 3 轮（清理 + 最终审查）**:
1. 实施 P2-2: sidecar 编码方式改进
2. 解决 P2-4: btf.c 不必要重构
3. 文档化锁序不变量
4. 添加 selftest 覆盖 REJIT 的各种边界情况
5. Patch 拆分为独立可审查的系列

### 整体评价

REJIT 功能本身是有价值的——运行时替换 BPF 程序的 JIT 镜像是 BPF 生态中的一个重要能力。verifier.c 中的 kinsn 整合（合入 `bpf_kfunc_desc`）比预期要好，说明作者已经意识到了复用 kfunc 基础设施的必要性。

但 syscall.c 中的 swap 逻辑是整个 patch set 的最大风险：25+ 个手动 swap + rollback + 多阶段 poke 更新，组成了一个复杂的状态机。任何新增的 `bpf_prog_aux` 字段都必须更新 swap 列表，这是一个维护定时炸弹。

kinsn 的"双轨制"验证（proof sequence vs native emit）是核心安全隐忧。即使当前实现是正确的，这种设计增加了信任面，使得 formal verification 更加困难。长期来看，应该朝着"verifier 看到什么 = JIT 生成什么"的方向发展。

最后，已确认的 QEMU crash（daemon 生成 malformed bytecode → REJIT verifier 通过 → guest crash）表明当前 verifier 路径存在实际的安全缺陷。虽然后续修复似乎堵住了已知的具体路径，但系统性的审计（struct_ops 验证、flag 传递、fd_array fixup 等）是合入前的必要条件。

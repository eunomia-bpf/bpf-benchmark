# REJIT 后 XDP Dispatcher / Trampoline / freplace / LSM 同步修复设计

日期: 2026-03-21
基于: `vendor/linux-framework` rejit-v2 分支源码审阅

---

## 0. 概述

REJIT 通过 `WRITE_ONCE(prog->bpf_func, new_func)` 发布新 JIT image。对于仅缓存 `struct bpf_prog *` 的 backend（TC、cgroup、sockmap、perf_event、kprobe、tracepoint 等），此操作天然足够。但以下两类 backend 在生成的可执行代码中嵌入了 raw 地址，需要额外同步：

1. **XDP dispatcher** -- 在 dispatcher image 中嵌入 `bpf_func` 地址作为 direct-call 目标
2. **trampoline / freplace / LSM** -- 在 trampoline image 中嵌入 `bpf_func` 地址作为 call 目标，或通过 `bpf_arch_text_poke` 将 jump target 设为 `bpf_func`

此外还有两个前置修复：
3. **Attachment 类型检测** -- 当前检测逻辑有漏洞
4. **KERNEL_BPFPTR** -- REJIT 构造 load_attr 时的指针语义错误

---

## 1. XDP Dispatcher 同步

### 1.1 问题分析

XDP dispatcher 在 `bpf_dispatcher_prepare()` 中提取每个注册 prog 的 `bpf_func` 地址：

```c
// kernel/bpf/dispatcher.c:99-103
for (i = 0; i < BPF_DISPATCHER_MAX; i++) {
    if (d->progs[i].prog)
        *ipsp++ = (s64)(uintptr_t)d->progs[i].prog->bpf_func;
}
```

这些地址被 `arch_prepare_bpf_dispatcher()` 编码为 x86 比较+直跳指令：

```asm
; arch/x86/net/bpf_jit_comp.c:3622-3633
cmp rdx, <baked_bpf_func>   ; 比较传入的 bpf_func 与缓存地址
je  <baked_bpf_func>         ; 匹配则 direct jump
jmp rdx                      ; 不匹配则 indirect jump（fallback）
```

热路径调用链：`bpf_prog_run_xdp()` -> `__bpf_prog_run(prog, xdp, BPF_DISPATCHER_FUNC(xdp))`，其中 dispatcher 函数接收 `prog->bpf_func` 作为第三个参数（rdx）。

**关键发现：REJIT 后不会导致 UAF，但会导致性能退化。**

理由：
- 调用方每次从 `prog->bpf_func` 读取新地址并传给 dispatcher
- Dispatcher 比较时发现新地址与 baked-in 旧地址不匹配
- 走 fallback 的 indirect jump (`jmp rdx`)，用的是新地址，正确性无问题
- 但 direct-call 优化失效，每个 XDP 包都走 indirect call

**次要风险：旧地址残留。** 旧 JIT image 释放后，dispatcher image 中仍残留旧地址。极端情况下如果新分配的 JIT image 恰好复用了旧地址，会发生 false positive direct jump。概率极低但不可忽视。

### 1.2 修复方案

新增 `bpf_dispatcher_refresh_prog()` 函数，允许 same-prog refresh。

```c
// kernel/bpf/dispatcher.c -- 新增函数

/**
 * bpf_dispatcher_refresh_prog - rebuild dispatcher image after
 *                                a prog's bpf_func changed (e.g. REJIT).
 * @d:    dispatcher
 * @prog: the prog whose bpf_func was updated in-place
 *
 * Unlike bpf_dispatcher_change_prog(), this does NOT add/remove a prog.
 * It only rebuilds the dispatcher image so that baked-in addresses
 * reflect the current prog->bpf_func values.
 */
void bpf_dispatcher_refresh_prog(struct bpf_dispatcher *d,
                                 struct bpf_prog *prog)
{
    if (!d || !prog)
        return;

    mutex_lock(&d->mutex);
    if (!d->image || !bpf_dispatcher_find_prog(d, prog))
        goto out;

    /* Force rebuild: bpf_dispatcher_prepare() re-reads prog->bpf_func */
    bpf_dispatcher_update(d, d->num_progs);
out:
    mutex_unlock(&d->mutex);
}
```

在 REJIT 成功路径中调用：

```c
// kernel/bpf/syscall.c -- bpf_prog_rejit() 成功路径，在 swap 之后

bpf_prog_rejit_swap(prog, tmp);

/* Refresh XDP dispatcher if this prog is registered. */
if (prog->type == BPF_PROG_TYPE_XDP)
    bpf_prog_refresh_xdp(prog);

if (prog->sleepable)
    synchronize_rcu_tasks_trace();
else
    synchronize_rcu();
```

`bpf_prog_refresh_xdp()` 是 `net/core/filter.c` 中的 wrapper：

```c
// net/core/filter.c -- 新增

void bpf_prog_refresh_xdp(struct bpf_prog *prog)
{
    bpf_dispatcher_refresh_prog(BPF_DISPATCHER_PTR(xdp), prog);
}
```

### 1.3 需要修改的文件和预估行数

| 文件 | 改动 | 行数 |
|------|------|------|
| `kernel/bpf/dispatcher.c` | 新增 `bpf_dispatcher_refresh_prog()` | ~20 |
| `include/linux/bpf.h` | 声明新函数 | ~3 |
| `net/core/filter.c` | 新增 `bpf_prog_refresh_xdp()` wrapper | ~5 |
| `kernel/bpf/syscall.c` | REJIT 成功路径调用 refresh | ~3 |
| **合计** | | **~31** |

### 1.4 风险评估

- **低风险**: `bpf_dispatcher_update()` 已经是成熟路径，内部有 `synchronize_rcu()` 保护
- `bpf_dispatcher_refresh_prog()` 不改变 prog 引用计数，不增减 dispatcher slot
- 额外开销：一次 dispatcher image rebuild + `synchronize_rcu()`，只在 REJIT 时发生
- 不需要 netdev down/up，不需要 driver 配合

---

## 2. Trampoline 同步（fentry / fexit / fmod_ret / LSM）

### 2.1 问题分析

trampoline image 由 `arch_prepare_bpf_trampoline()` 生成。对于 fentry/fexit/fmod_ret/LSM 类型的 attached prog，trampoline 中通过 `invoke_bpf_prog()` 调用每个 prog：

```c
// arch/x86/net/bpf_jit_comp.c:3051
if (emit_rsb_call(&prog, p->bpf_func, image + (prog - (u8 *)rw_image)))
    return -EINVAL;
```

`emit_rsb_call` 生成一条 relative call 指令，目标地址在 trampoline 生成时从 `p->bpf_func` 计算为相对偏移并写死到 image 中。**REJIT 后旧 trampoline image 仍然 call 旧地址，而旧 JIT image 在 `synchronize_rcu()` 后会被释放，构成 UAF。**

这是一个 **Critical** 级别的安全问题。

### 2.2 修复方案

REJIT 后需要对 prog 关联的所有 trampoline 调用 `bpf_trampoline_update()` 来重新生成 trampoline image。

**核心挑战：如何从 prog 找到所有关联的 trampoline？**

当前内核中，trampoline 到 prog 的关联通过 `tr->progs_hlist[]` 维护（正向），但 prog 到 trampoline 没有反向索引。`bpf_tracing_link` 持有 `trampoline` 指针，但从 prog 出发需要遍历 link_idr。

**方案 2A（推荐）：在 `bpf_prog_aux` 中新增轻量反向索引**

```c
// include/linux/bpf.h -- bpf_prog_aux 新增字段

struct bpf_prog_aux {
    ...
    /* Reverse index: trampolines using this prog's bpf_func.
     * Protected by trampoline_mutex.
     * Only non-empty for progs attached via fentry/fexit/fmod_ret/LSM/freplace.
     */
    struct list_head trampoline_users;  /* list of bpf_tramp_user */
    ...
};
```

```c
// kernel/bpf/trampoline.c -- 新增 trampoline_user 结构

struct bpf_tramp_user {
    struct list_head list;          /* linked into prog->aux->trampoline_users */
    struct bpf_trampoline *tr;
};
```

在 `__bpf_trampoline_link_prog()` 中注册反向索引：

```c
// kernel/bpf/trampoline.c -- 在 __bpf_trampoline_link_prog() 成功路径中

/* 在 hlist_add_head(&link->tramp_hlist, prog_list) 之后，
 * bpf_trampoline_update() 之前 */

struct bpf_tramp_user *tu = kzalloc(sizeof(*tu), GFP_KERNEL);
if (!tu)
    return -ENOMEM;
tu->tr = tr;
list_add(&tu->list, &link->link.prog->aux->trampoline_users);
```

在 `__bpf_trampoline_unlink_prog()` 中移除：

```c
// kernel/bpf/trampoline.c -- 在 __bpf_trampoline_unlink_prog() 中

struct bpf_tramp_user *tu, *tmp;
list_for_each_entry_safe(tu, tmp,
                         &link->link.prog->aux->trampoline_users, list) {
    if (tu->tr == tr) {
        list_del(&tu->list);
        kfree(tu);
        break;
    }
}
```

REJIT 后刷新所有关联 trampoline：

```c
// kernel/bpf/trampoline.c -- 新增

/**
 * bpf_trampoline_refresh_prog - regenerate all trampolines using
 *                                this prog after its bpf_func changed.
 * @prog: the prog whose bpf_func was updated
 *
 * Must be called AFTER bpf_func is updated but BEFORE the old JIT
 * image is freed. Caller must NOT hold any trampoline mutex.
 *
 * Returns 0 on success, negative errno on first failure (best-effort
 * for remaining trampolines).
 */
int bpf_trampoline_refresh_prog(struct bpf_prog *prog)
{
    struct bpf_tramp_user *tu;
    int err = 0;

    /* trampoline_mutex protects trampoline_users list and
     * serializes with link/unlink. */
    mutex_lock(&trampoline_mutex);
    list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
        struct bpf_trampoline *tr = tu->tr;

        mutex_lock(&tr->mutex);
        /* bpf_trampoline_update() rebuilds the image, picking up
         * the new prog->bpf_func from tr->progs_hlist[]. */
        err = bpf_trampoline_update(tr, true);
        mutex_unlock(&tr->mutex);

        if (err)
            break;
    }
    mutex_unlock(&trampoline_mutex);
    return err;
}
```

### 2.3 替代方案 2B（无反向索引，遍历 link_idr）

如果不想新增 `trampoline_users` 字段，可以遍历全局 `link_idr` 来发现关联的 trampoline：

```c
int bpf_trampoline_refresh_prog(struct bpf_prog *prog)
{
    struct bpf_link *link;
    u32 id = 0;
    int err = 0;

    while ((link = bpf_link_get_next_id(&id)) != NULL) {
        if (link->prog != prog || link->type != BPF_LINK_TYPE_TRACING) {
            bpf_link_put(link);
            continue;
        }
        struct bpf_tracing_link *tr_link =
            container_of(link, struct bpf_tracing_link, link.link);

        mutex_lock(&tr_link->trampoline->mutex);
        err = bpf_trampoline_update(tr_link->trampoline, true);
        mutex_unlock(&tr_link->trampoline->mutex);

        bpf_link_put(link);
        if (err)
            break;
    }
    return err;
}
```

**方案 2B 的缺点：**
- 遍历全局 IDR 在 link 数量大时较慢
- 需要在 IDR 遍历期间拿 link 引用再 put，与 trampoline mutex 的锁序需要仔细验证
- 遗漏 shim_tramp_link（BPF_LSM_CGROUP）等非标准 link 类型

**推荐方案 2A**：新增轻量反向索引，O(1) 查找，锁序清晰。

### 2.4 需要修改的文件和预估行数

| 文件 | 改动 | 行数 |
|------|------|------|
| `include/linux/bpf.h` | `bpf_prog_aux` 新增 `trampoline_users` 字段 + `bpf_tramp_user` 声明 | ~8 |
| `kernel/bpf/core.c` | `bpf_prog_alloc()` 中初始化 `INIT_LIST_HEAD` | ~2 |
| `kernel/bpf/trampoline.c` | `bpf_tramp_user` 定义、link/unlink 中维护、新增 `bpf_trampoline_refresh_prog()` | ~60 |
| `kernel/bpf/syscall.c` | REJIT 成功路径调用 `bpf_trampoline_refresh_prog()` | ~5 |
| **合计** | | **~75** |

### 2.5 风险评估

- **中等风险**: `bpf_trampoline_update()` 本身是成熟路径，但从 REJIT 上下文调用它是新路径
- **锁序**: REJIT 持有 `prog->aux->rejit_mutex`，然后需要拿 `trampoline_mutex` -> `tr->mutex`。需要确认这个锁序与现有 attach/detach 路径不冲突。当前 attach 路径是 `tr->mutex` 内部操作，不持有 `rejit_mutex`，所以不应有死锁
- **重要约束**: trampoline refresh 必须在 `WRITE_ONCE(prog->bpf_func)` 之后、旧 image 释放之前完成。当前代码中，swap 和 `synchronize_rcu()` 之间是合适的插入点
- 如果 `bpf_trampoline_update()` 失败（例如内存不足），需要决定是否回滚 REJIT。建议：失败时不回滚，但标记 prog 为 "partially rejited"，在下次 detach 时清理

---

## 3. Freplace 同步

### 3.1 问题分析

freplace (BPF_PROG_TYPE_EXT) 的 attach 路径与 fentry/fexit 不同。它不走 trampoline image 内部的 call，而是直接 `bpf_arch_text_poke` 把目标函数的入口改成 jump 到 `link->link.prog->bpf_func`：

```c
// kernel/bpf/trampoline.c:796-798 (__bpf_trampoline_link_prog, kind==BPF_TRAMP_REPLACE)
tr->extension_prog = link->link.prog;
return bpf_arch_text_poke(tr->func.addr, BPF_MOD_NOP,
                          BPF_MOD_JUMP, NULL,
                          link->link.prog->bpf_func);
```

REJIT 后，poke site 仍然指向旧 `bpf_func`。旧 image 释放后是 UAF。

**这也是 Critical 级别问题。**

### 3.2 修复方案

freplace 也会创建 `bpf_tracing_link`，其 `trampoline` 字段指向被 extend 的函数对应的 trampoline。通过方案 2A 的反向索引可以发现它。

但 freplace 的 refresh 逻辑不同于 fentry/fexit：不需要重建 trampoline image，而是需要重新 text-poke。

```c
// kernel/bpf/trampoline.c -- 在 bpf_trampoline_refresh_prog() 中

int bpf_trampoline_refresh_prog(struct bpf_prog *prog)
{
    struct bpf_tramp_user *tu;
    int err = 0;

    mutex_lock(&trampoline_mutex);
    list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
        struct bpf_trampoline *tr = tu->tr;

        mutex_lock(&tr->mutex);

        if (tr->extension_prog == prog) {
            /* freplace: re-poke the jump target */
            err = bpf_arch_text_poke(tr->func.addr,
                                     BPF_MOD_JUMP, BPF_MOD_JUMP,
                                     tu->old_bpf_func,  /* previous bpf_func */
                                     prog->bpf_func);   /* new bpf_func */
        } else {
            /* fentry/fexit/fmod_ret/LSM: rebuild trampoline image */
            err = bpf_trampoline_update(tr, true);
        }

        mutex_unlock(&tr->mutex);
        if (err)
            break;
    }
    mutex_unlock(&trampoline_mutex);
    return err;
}
```

注意 `bpf_arch_text_poke` 需要旧地址来验证 text poke 合法性。有两种方式获取旧地址：

**方式 A**: 在 `bpf_tramp_user` 中保存 `old_bpf_func`，REJIT swap 前记录。
**方式 B**: 不存旧地址，使用 `BPF_MOD_JUMP` -> `BPF_MOD_JUMP` 的语义。

检查 `bpf_arch_text_poke` 的接口：

```c
// arch/x86/net/bpf_jit_comp.c
int bpf_arch_text_poke(void *ip, enum bpf_text_poke_type old_poke_type,
                       enum bpf_text_poke_type new_poke_type,
                       void *old_addr, void *new_addr);
```

它需要 `old_addr` 来构造旧指令以验证 poke site。所以需要方式 A -- 在发起 refresh 前保存旧 `bpf_func`。

更好的做法是在 `bpf_prog_rejit_swap()` 之前就保存旧地址，然后传给 refresh 函数：

```c
// kernel/bpf/syscall.c -- REJIT 成功路径

bpf_func_t old_bpf_func = prog->bpf_func;
bpf_prog_rejit_swap(prog, tmp);

/* Refresh all backends that cache bpf_func addresses */
err = bpf_trampoline_refresh_prog(prog, old_bpf_func);
if (err) {
    /* Best-effort: log warning but don't roll back */
    pr_warn("bpf_rejit: trampoline refresh failed: %d\n", err);
}

if (prog->type == BPF_PROG_TYPE_XDP)
    bpf_prog_refresh_xdp(prog);
```

调整 refresh 函数签名：

```c
int bpf_trampoline_refresh_prog(struct bpf_prog *prog, bpf_func_t old_bpf_func)
{
    ...
    if (tr->extension_prog == prog) {
        err = bpf_arch_text_poke(tr->func.addr,
                                 BPF_MOD_JUMP, BPF_MOD_JUMP,
                                 (void *)old_bpf_func,
                                 (void *)prog->bpf_func);
    } else {
        err = bpf_trampoline_update(tr, true);
    }
    ...
}
```

### 3.3 额外行数

freplace 的处理已包含在 `bpf_trampoline_refresh_prog()` 中，不需要额外文件，只增加 ~10 行分支逻辑。

### 3.4 风险评估

- **中等风险**: `bpf_arch_text_poke` 需要精确的旧地址；如果传错会 BUG/WARN
- 需要确保 REJIT swap 和 text_poke 之间没有其他路径修改 poke site
- `rejit_mutex` 可以保证不会有并发 REJIT，但需要与 freplace detach 路径的 `tr->mutex` 配合

---

## 4. Attachment 类型检测修复

### 4.1 问题分析

当前 `bpf_prog_rejit_supported()` 用以下条件检查 trampoline 关联：

```c
// kernel/bpf/syscall.c:3169-3171
if (aux->dst_prog || aux->dst_trampoline || aux->func_cnt ||
    aux->real_func_cnt || aux->poke_tab || aux->size_poke_tab ||
    rcu_access_pointer(aux->st_ops_assoc))
    return false;
```

但 `bpf_tracing_prog_attach()` 成功后会清空这些字段：

```c
// kernel/bpf/syscall.c:3999-4000
prog->aux->dst_prog = NULL;
prog->aux->dst_trampoline = NULL;
```

这意味着**已经 attach 到 trampoline 的 prog 不会被 `bpf_prog_rejit_supported()` 拒绝**。这是一个严重的漏洞。

### 4.2 修复方案

利用方案 2A 引入的 `trampoline_users` 反向索引来检测：

```c
static bool bpf_prog_rejit_supported(const struct bpf_prog *prog)
{
    const struct bpf_prog_aux *aux = prog->aux;

    if (!prog->jited || prog->is_func)
        return false;

    if (bpf_prog_is_offloaded(aux) || bpf_prog_is_dev_bound(aux))
        return false;

    if (aux->dst_prog || aux->dst_trampoline || aux->func_cnt ||
        aux->real_func_cnt || aux->poke_tab || aux->size_poke_tab ||
        rcu_access_pointer(aux->st_ops_assoc))
        return false;

    /* 新增：不再禁止 trampoline 用户，而是允许并做 refresh。
     * 但仍需检查是否有支持不了的 attachment 类型。
     *
     * 已实现 refresh 的类型：
     *   - trampoline (fentry/fexit/fmod_ret/LSM)
     *   - freplace (BPF_TRAMP_REPLACE)
     *   - XDP dispatcher (prog->type == BPF_PROG_TYPE_XDP)
     *
     * 仍需禁止的类型：
     *   - struct_ops (已被 st_ops_assoc 检查拦截)
     *   - sched_ext (已被 st_ops_assoc 检查拦截)
     */

    return true;
}
```

**如果不引入反向索引（短期方案）**，则需要显式拒绝已 attach 的 tracing/LSM prog。可以通过检查 `prog->aux->trampoline_users` 是否为空来判断：

```c
/* 短期方案：拒绝任何有 live trampoline 的 prog */
if (!list_empty(&aux->trampoline_users))
    return false;
```

**或者（如果不新增字段）**，利用 link 计数。`bpf_link_settle()` 在 attach 成功后会分配 link ID 并将 `link->prog` 设为 prog。但当前没有 prog -> link 的反向计数。一个轻量的办法：

```c
// include/linux/bpf.h -- bpf_prog_aux 新增
atomic_t tramp_attach_cnt;  /* count of live trampoline/freplace attachments */
```

在 `bpf_tracing_prog_attach()` 成功时 `atomic_inc`，在 `bpf_tracing_link_release()` 中 `atomic_dec`。

```c
// bpf_prog_rejit_supported() 中
if (atomic_read(&aux->tramp_attach_cnt) > 0) {
    /* 短期：拒绝。中期：允许但需要 refresh */
    return false;  /* 或 return true; 如果 refresh 已实现 */
}
```

### 4.3 推荐路线

- **短期**: 新增 `tramp_attach_cnt`，REJIT 先拒绝有 live trampoline 的 prog。改动 ~15 行。
- **中期**: 实现 `trampoline_users` 反向索引 + refresh，改为允许。改动 ~75 行（即方案 2A）。
- **两步合并**: 如果 2A 和检测一起实现，直接用 `list_empty(&aux->trampoline_users)` 既做检测又做 refresh 入口，不需要单独的 `tramp_attach_cnt`。

### 4.4 需要修改的文件和预估行数

**短期方案（仅检测，拒绝）：**

| 文件 | 改动 | 行数 |
|------|------|------|
| `include/linux/bpf.h` | `bpf_prog_aux` 新增 `tramp_attach_cnt` | ~2 |
| `kernel/bpf/syscall.c` | `bpf_tracing_prog_attach()` inc，`bpf_tracing_link_release()` dec | ~4 |
| `kernel/bpf/syscall.c` | `bpf_prog_rejit_supported()` 检查 | ~3 |
| **合计** | | **~9** |

**中期方案（检测 + refresh）：** 已包含在方案 2A 中。

---

## 5. KERNEL_BPFPTR 修复

### 5.1 问题分析

当前 REJIT 构造 load_attr 时：

```c
// kernel/bpf/syscall.c:3252-3253
union bpf_attr load_attr = {};
bpfptr_t load_uattr = KERNEL_BPFPTR(&load_attr);
```

然后将其传给 `bpf_check()`。问题在于 `load_attr.fd_array` 的值直接从用户 attr 拷贝：

```c
// kernel/bpf/syscall.c:3286
load_attr.fd_array = attr->rejit.fd_array;  // 用户态地址
```

但 `process_fd_array()` 中：

```c
// kernel/bpf/verifier.c:25571
env->fd_array = make_bpfptr(attr->fd_array, uattr.is_kernel);
```

由于 `uattr.is_kernel == true`，用户态的 `fd_array` 地址被当作内核指针处理。后续 `copy_from_bpfptr_offset()` 会调用 `copy_from_kernel_nofault()` 而非 `copy_from_user()`。

这有两个后果：
1. 正常使用时 `fd_array` 是用户态指针，`copy_from_kernel_nofault()` 大概率失败或读到错误数据
2. 恶意调用者可以把任意内核地址伪装成 fd_array，探测内核内存布局

### 5.2 修复方案

**方案 5A（推荐）：不用 `KERNEL_BPFPTR`，用 `USER_BPFPTR`**

REJIT 的 `load_attr` 是栈上构造的 kernel 副本，但其中的 `fd_array`、`log_buf` 等字段指向用户空间。正确做法是让 `bpf_check` 知道 attr 本身在内核空间，但 `fd_array` 按用户指针处理。

实际上 `bpf_check()` 只在以下地方使用 `uattr`：
1. `process_fd_array()` -- 读 `fd_array`
2. `bpf_vlog_init()` -- 读 `log_buf`（但这个在 attr 里已经是用户指针值）

最简单的修复是**不要传 `KERNEL_BPFPTR`**：

```c
// kernel/bpf/syscall.c -- 修改

/* 替换：
 * bpfptr_t load_uattr = KERNEL_BPFPTR(&load_attr);
 * 为：
 */
bpfptr_t load_uattr = make_bpfptr((u64)(unsigned long)&load_attr, false);
```

但这也有问题：`attr` 结构体本身在内核栈上，但里面的指针字段（`insns`、`fd_array`、`log_buf`）指向用户空间。verifier 需要用 `copy_from_bpfptr` 来读这些字段，它根据 `uattr.is_kernel` 选择 `copy_from_kernel` 还是 `copy_from_user`。

等等，让我重新审视 -- `bpf_check` 实际上直接用 `attr` 结构体（不是 `uattr`）来读大部分字段。`uattr` 只用于 `process_fd_array()` 中构造 `env->fd_array` 的 `bpfptr_t`。

**正确的修复方案**：

`bpfptr_t` 的 `is_kernel` 标志只影响 `env->fd_array` 的 copy 语义。所以应该：

```c
// 方案 5A: 使 fd_array 的 bpfptr 正确标记为用户指针
// kernel/bpf/syscall.c

/* 不用 KERNEL_BPFPTR。构造一个 "user" bpfptr 但指向栈上 attr。
 * 这样 process_fd_array() 中 make_bpfptr(attr->fd_array, false)
 * 会正确地用 copy_from_user 读 fd_array。
 *
 * 但 copy_from_bpfptr 在读 attr 本身时... 实际上 bpf_check 不会
 * 通过 uattr 来读 attr。uattr 只用于 fd_array。
 * 所以把 uattr 标记为 !is_kernel 是安全的。
 */
bpfptr_t load_uattr = make_bpfptr(0, false);
/* 单独设置 fd_array 字段 -- 但这行不通因为 make_bpfptr 是对 uattr 整体的 */
```

实际上看代码：`process_fd_array()` 的第二个参数是 `attr`（普通指针），第三个是 `uattr`（bpfptr）。代码在 25571 行：

```c
env->fd_array = make_bpfptr(attr->fd_array, uattr.is_kernel);
```

所以 `uattr.is_kernel` 决定了 `attr->fd_array` 被解读为内核还是用户指针。

**最终方案 5A**: 简单地把 `load_uattr` 改为 `USER_BPFPTR`：

```c
// kernel/bpf/syscall.c -- 修改行 3253

/* 旧代码：bpfptr_t load_uattr = KERNEL_BPFPTR(&load_attr); */
/* 新代码：*/
bpfptr_t load_uattr = USER_BPFPTR((void __user *)&load_attr);
```

这样 `process_fd_array()` 中 `make_bpfptr(attr->fd_array, false)` 会把 `fd_array` 当作用户指针，用 `copy_from_user()` 读取 -- 这是正确的语义。

`bpf_check()` 内部不通过 `uattr` 访问 `load_attr` 结构体本身（它直接用 `attr` 参数），所以这个改动不会影响其他路径。

需要验证 `bpf_check` 内部是否还有其他地方用 `uattr` 访问 attr 本身：

```c
// bpf_check() 中 uattr 的使用处：
// 1. process_fd_array(env, attr, uattr) -- 只用 uattr.is_kernel
// 2. 没有其他地方
```

**但有一个微妙问题**：`USER_BPFPTR` 期望接收一个真正的用户空间地址。`&load_attr` 是内核栈地址，传给 `USER_BPFPTR` 在语义上不对，虽然 `load_uattr` 不会被用来 dereference `load_attr`。更干净的做法：

```c
// 方案 5B（最干净）: 给 bpf_check 传一个 fd_array 专用参数
//
// 但这需要修改 bpf_check 签名，影响面过大
```

```c
// 方案 5C（务实）: 构造一个假 uattr，只传递 is_kernel=false 信号
bpfptr_t load_uattr = make_bpfptr(0, false);
```

`make_bpfptr(0, false)` 创建一个 null user bpfptr。`bpf_check()` 不通过它来读 attr，所以 null 是安全的。但如果未来 `bpf_check` 内部添加了通过 `uattr` 读 attr 的路径，就会 crash。

**推荐方案 5A 变体**：将 `load_uattr` 去掉，直接在 REJIT 调用路径中给 `bpf_check` 传一个明确的 `is_kernel=false` 标志。

考虑到改动面和清晰度，**最终推荐方案**：

```c
// kernel/bpf/syscall.c -- REJIT 路径

/* fd_array 和 log_buf 都是用户态指针，所以标记为非内核 */
bpfptr_t load_uattr = make_bpfptr((u64)(unsigned long)attr, false);
```

这里 `attr` 是 REJIT 的原始用户 `union bpf_attr *`（通过 `copy_from_user` 到栈上的），而 `load_attr` 是栈上构造的。但我们需要的只是 `uattr.is_kernel = false` 信号。

实际上最简单正确的改法是：

```c
// 1 行修改
bpfptr_t load_uattr = KERNEL_BPFPTR(&load_attr);
// 改为
bpfptr_t load_uattr = make_bpfptr((u64)(uintptr_t)&load_attr, false);
```

这样 `process_fd_array()` 用 `uattr.is_kernel == false` 来处理 `attr->fd_array`，正确地使用 `copy_from_user()` 语义。`bpf_check()` 内部不会通过 `uattr` 来 dereference `load_attr`，所以把 `is_kernel` 设为 false 不会有副作用。

### 5.3 需要修改的文件和预估行数

| 文件 | 改动 | 行数 |
|------|------|------|
| `kernel/bpf/syscall.c` | 修改 `load_uattr` 构造 | 1 |

### 5.4 风险评估

- **低风险**: 一行改动，语义明确
- 需要确认 `bpf_check()` 内部不会通过 `uattr` 来 `copy_from_bpfptr()` 读 `load_attr` 本身 -- 通过代码审阅确认仅在 `process_fd_array()` 中使用 `uattr.is_kernel`

---

## 6. 整体修复顺序和路线图

### Phase 0: 紧急安全修复（阻塞合入的前置条件）

1. **KERNEL_BPFPTR 修复** (1 行) -- 修正 verifier fd_array 读取语义
2. **Attachment 检测修复** (~9 行) -- 新增 `tramp_attach_cnt`，禁止对已 attach trampoline/freplace 的 prog 做 REJIT

Phase 0 后的状态：REJIT 只对"安全类 backend + 完全 detached 的 tracing/extension prog"生效。XDP prog 因为不经过 trampoline 也可安全 REJIT（但 dispatcher 优化会失效，详见下文）。

### Phase 1: XDP dispatcher refresh（~31 行）

新增 `bpf_dispatcher_refresh_prog()` 并在 REJIT 成功路径调用。XDP prog REJIT 后恢复 direct-call 优化。

### Phase 2: Trampoline / freplace refresh（~75 行）

实现 `trampoline_users` 反向索引 + `bpf_trampoline_refresh_prog()`。允许对 live fentry/fexit/LSM/freplace attached prog 做 REJIT。

Phase 2 后可以移除 Phase 0 中 `tramp_attach_cnt` 的 "reject" 逻辑，改为 "allow + refresh"。

### 改动量汇总

| Phase | 改动量 | 新增 kernel API |
|-------|--------|-----------------|
| 0 | ~10 行 | 无 |
| 1 | ~31 行 | `bpf_dispatcher_refresh_prog()`, `bpf_prog_refresh_xdp()` |
| 2 | ~75 行 | `bpf_trampoline_refresh_prog()` |
| **总计** | **~116 行** | 3 个内部函数 |

---

## 7. 测试要点

每个 Phase 需要对应的 selftest：

### Phase 0 测试
- REJIT 对 live fentry/fexit attached prog 返回 `-EOPNOTSUPP`
- REJIT 对 live freplace attached prog 返回 `-EOPNOTSUPP`
- REJIT 对 live LSM attached prog 返回 `-EOPNOTSUPP`
- REJIT 对 detached tracing prog 成功
- REJIT fd_array 中包含 map fd 时正常工作（验证 KERNEL_BPFPTR 修复）

### Phase 1 测试
- XDP prog REJIT 后 dispatcher image 更新，XDP 仍正确执行
- XDP prog REJIT 后性能不退化（direct-call 恢复）

### Phase 2 测试
- fentry attached prog REJIT 后 trampoline image 更新，fentry 仍正确触发
- fexit attached prog REJIT 后返回值 hook 仍正确
- freplace attached prog REJIT 后 extension 仍正确工作
- LSM attached prog REJIT 后 LSM hook 仍正确

---

## 8. 关于 struct_ops / sched_ext

继续禁止 REJIT。

struct_ops 的 trampoline 模型与 fentry/fexit 不同：每个 member function 有独立的 trampoline，且 trampoline 地址被写入 live callback table（`kvalue.data`）。refresh 几乎等价于整个 struct_ops map 的 update，复杂度远超 Phase 2。

sched_ext 更是明确拒绝 live update (`bpf_scx_update()` 返回 `-EOPNOTSUPP`)。

如果将来要支持，需要另外设计 struct_ops 级别的 "partial member refresh" 机制。

---

## 9. 关于 `READ_ONCE(prog->bpf_func)` 读侧补全

当前通用热路径（`__bpf_prog_run` 等）读 `prog->bpf_func` 时没有 `READ_ONCE`。虽然对已安全的 backend 来说 compiler 不太可能生成有问题的代码（因为 `bpf_func` 通常只读一次），但作为 REJIT 的基础语义契约，建议补上：

```c
// include/linux/filter.h -- __bpf_prog_run()
// 旧: ret = dfunc(ctx, prog->insnsi, prog->bpf_func);
// 新:
ret = dfunc(ctx, prog->insnsi, READ_ONCE(prog->bpf_func));
```

这是一行改动，没有性能影响（编译器已经只读一次），但让内存模型语义更正确。可以在任何 Phase 中顺便做掉。

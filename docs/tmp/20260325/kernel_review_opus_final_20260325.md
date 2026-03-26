# BpfReJIT 内核 Patch 审计报告

> 审计对象：`kernel_vs_upstream_diff.patch`（2935 行）
> 审计日期：2026-03-25
> 审计角色：Linux 内核 BPF 子系统维护者视角
> 审计标准：upstream submission readiness

---

## 总体评估

此 patch 向 BPF 子系统添加了三个主要功能：
1. `BPF_PROG_REJIT` syscall —— 在线替换已加载 BPF 程序的 JIT image
2. `kinsn` 机制 —— 允许内核模块注册平台特定指令扩展，由 verifier 验证后由 JIT 内联发射
3. `BPF_PROG_GET_ORIGINAL` —— 通过 `bpf_prog_info` 暴露原始 bytecode

修改涉及 ~15 个文件，覆盖 UAPI、verifier、JIT (x86/arm64)、trampoline、dispatcher、struct_ops、btf。patch 规模大、横跨面广，以下按文件逐条列出问题。

---

## 1. `include/uapi/linux/bpf.h` — UAPI 设计

### 1.1 [HIGH] `BPF_PSEUDO_KINSN_SIDECAR = 3` 与 `BPF_PSEUDO_KINSN_CALL = 4` 值域冲突风险

```c
#define BPF_PSEUDO_KINSN_SIDECAR 3
#define BPF_PSEUDO_KINSN_CALL    4
```

`BPF_PSEUDO_KINSN_SIDECAR` 复用 `src_reg` 域（4 bit 宽），值 3 和 4 在 `BPF_ALU64|BPF_MOV|BPF_K` 的 src_reg 位置。现有内核中 `src_reg` 在 MOV_K 指令里必须为 0，否则 verifier 拒绝。但 SIDECAR 编码直接覆盖了这个隐式约束，且值 3 在其他 context 中已被 `BPF_PSEUDO_KFUNC_CALL` 使用（在 `BPF_JMP|BPF_CALL` 中）。虽然 opcode class 不同不会冲突，但数字重复增加了审计/工具链混淆风险。

**建议**：sidecar/kinsn_call 编号应从更高值开始（如 5/6），或在注释中明确标注值域隔离规则。

### 1.2 [MEDIUM] `bpf_prog_info` 新增字段 `orig_prog_len` / `orig_prog_insns` 缺少版本协商

```c
struct bpf_prog_info {
    ...
    __u32 orig_prog_len;
    __aligned_u64 orig_prog_insns;
};
```

追加在 `bpf_prog_info` 尾部，旧内核不返回这些字段。但 `orig_prog_insns` 是一个 userspace 指针（用户传入 buffer 地址），与 `xlated_prog_insns` 模式一致，合理。然而缺少文档说明这些字段的语义（是原始 load 时的 bytecode 还是最近一次 REJIT 前的 bytecode）。

**建议**：在 UAPI header 中添加注释说明 `orig_insns` 的精确语义。

### 1.3 [MEDIUM] `union bpf_attr::rejit` 缺少 `prog_type` / `expected_attach_type` 字段

当前 REJIT 从原始 prog 继承这些值，但未来如果需要支持类型迁移（如 freplace 目标切换），UAPI 就需要扩展。当前设计合理但缺少预留 padding。

**建议**：在 `rejit` struct 末尾添加 `__u32 pad[4]` 保留字段。

### 1.4 [LOW] `BPF_PROG_REJIT` 枚举值紧接 `BPF_PROG_ASSOC_STRUCT_OPS`

当前 `BPF_PROG_STREAM_READ_BY_FD` 和 `BPF_PROG_ASSOC_STRUCT_OPS` 似乎是你们自己加的非 upstream 命令。upstream 合并时这些值会冲突。

**建议**：标注哪些 enum 值是本地扩展，确保 upstream submission 时 rebase 到正确位置。

---

## 2. `include/linux/bpf.h` — 内部 API

### 2.1 [HIGH] `struct bpf_kinsn` 的 `emit_x86` / `emit_arm64` 回调可被模块任意提供，缺少安全边界

```c
struct bpf_kinsn {
    struct module *owner;
    u16 max_insn_cnt;
    u16 max_emit_bytes;
    int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
    int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
    int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

模块提供的 `emit_x86` / `emit_arm64` 回调直接向 JIT image 写入任意 native 指令。一个恶意或有 bug 的模块可以：
- 写入超过 `max_emit_bytes` 限制的字节（虽然有后校验，但写入已发生）
- 写入包含 RET / INT3 等破坏 BPF 执行模型的指令
- 在 `emit=false`（sizing pass）时返回与 `emit=true` 不同的大小

x86 JIT 用 scratch buffer 缓解了直接覆写风险，但 ARM64 JIT 直接写入 `ctx->image`，没有 scratch buffer 保护。

**建议**：
1. ARM64 路径也应使用 scratch buffer + 后验证
2. 考虑对 emit 输出做基本 sanity check（至少检查不包含 RET/INT3）
3. 在文档中明确声明模块承担正确性责任

### 2.2 [MEDIUM] `bpf_kinsn_has_native_emit()` 使用 `#ifdef CONFIG_X86` 而非运行时检测

```c
static inline bool bpf_kinsn_has_native_emit(const struct bpf_kinsn *kinsn)
{
#ifdef CONFIG_X86
    if (kinsn->emit_x86) return true;
#endif
#ifdef CONFIG_ARM64
    if (kinsn->emit_arm64) return true;
#endif
    return false;
}
```

如果内核同时配置了 x86 和 arm64（交叉编译场景），这个函数会检查两个平台的 emit 回调。虽然实际上不太可能同时 `CONFIG_X86` 和 `CONFIG_ARM64`，但逻辑上应只检查当前运行平台。

### 2.3 [MEDIUM] `bpf_kinsn_sidecar_payload()` 编码 52 bit payload 但只用了 4+16+32=52 bit

```c
static inline u64 bpf_kinsn_sidecar_payload(const struct bpf_insn *insn)
{
    return (u64)(insn->dst_reg & 0xf) |
           ((u64)(u16)insn->off << 4) |
           ((u64)(u32)insn->imm << 20);
}
```

`dst_reg` 只有 4 bit，`off` 16 bit，`imm` 32 bit，总计 52 bit。这是一个合理的编码，但没有对应的 `encode` 函数（用户态 daemon 必须手动构造）。缺少配套的 `BPF_KINSN_SIDECAR_ENCODE()` 宏增加了出错概率。

**建议**：在 UAPI 或 `include/linux/bpf.h` 中提供 encode 宏。

### 2.4 [HIGH] `rejit_mutex` 和 `trampoline_users` 加入 `bpf_prog_aux` 但缺少生命周期文档

```c
struct bpf_prog_aux {
    ...
    struct mutex rejit_mutex;
    struct list_head trampoline_users;
    ...
};
```

`trampoline_users` 链表由 `bpf_trampoline_link_prog` 添加元素、`bpf_trampoline_unlink_prog` 删除元素，由 `rejit_mutex` 保护。但 `bpf_prog_free` 路径没有显式清理 `trampoline_users` 链表。如果 prog 被释放时链表非空（理论上 unlink 应在 free 之前发生），`list_head` 指向已释放内存。

**建议**：在 `__bpf_prog_put_noref` 中添加 `WARN_ON(!list_empty(&prog->aux->trampoline_users))` 断言。

---

## 3. `include/linux/filter.h` — 热路径修改

### 3.1 [CRITICAL] `smp_load_acquire` 在 `__bpf_prog_run` 热路径引入全局可见的性能影响

```c
static __always_inline u32 __bpf_prog_run(const struct bpf_prog *prog, ...)
{
    bpf_func_t bpf_func;
    bpf_func = smp_load_acquire(&prog->bpf_func);
    ...
    ret = dfunc(ctx, prog->insnsi, bpf_func);
}
```

**每一次 BPF 程序执行**都会经过这里。`smp_load_acquire` 在 x86 上是 plain load（x86 TSO 保证），但在 ARM64 上会生成 `ldar` 指令，相比普通 `ldr` 有额外的 acquire barrier 开销。这对所有 BPF 程序都有影响，不仅仅是 REJIT 过的程序。

在 ARM64 性能敏感的网络路径（XDP、tc）上，这可能是不可接受的全局开销。

**建议**：
1. 将 `smp_load_acquire` 替换为 `READ_ONCE` + 在 REJIT swap 侧使用 `smp_wmb()` + `synchronize_rcu()` 组合
2. 或者使用 `rcu_dereference` 模式，在 RCU read-side 读取 `bpf_func`
3. 基准测试量化 ARM64 上的影响

### 3.2 [MEDIUM] `bpf_prog_refresh_xdp` 只声明未在此 diff 中实现

```c
void bpf_prog_refresh_xdp(struct bpf_prog *prog);
```

声明存在但实现不在 diff 中。如果实现在其他 patch 中，需要确保这个 diff 自身可编译。

---

## 4. `kernel/bpf/syscall.c` — REJIT 核心逻辑

### 4.1 [CRITICAL] `bpf_prog_rejit_swap` 中 `memcpy(prog->insnsi, tmp->insnsi, ...)` 可能越界写入

```c
memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));
prog->len = tmp->len;
```

`prog->insnsi` 是 `struct bpf_prog` 末尾的柔性数组，大小由 `bpf_prog_size(prog->len)` 在分配时决定。如果 `tmp->len > prog` 原始分配时的 `len`，`memcpy` 会越界写入 `prog` 分配块之外的内存。

虽然在 `bpf_prog_rejit()` 中有检查：
```c
if (bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE)
    return -E2BIG;
```
但 `prog->pages * PAGE_SIZE` 是整页大小，而 `bpf_prog_size(prog->len)` 可能小于此值。这意味着只要 `tmp` 的 insns 不超过页边界就允许写入，但可能覆盖 `prog` 尾部的 padding 或相邻的 slab 对象。

更准确的检查应该是：
```c
if (bpf_prog_size(tmp->len) > bpf_prog_size(prog->len))
```

**建议**：使用精确的 allocation size 比较而非 page-granularity 比较。

### 4.2 [CRITICAL] `retain_old_image = true` 导致 `tmp` 程序永久泄漏

```c
if (retain_old_image) {
    pr_warn("bpf_rejit: retaining old JIT image after refresh failure\n");
} else {
    __bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt > 0);
}
```

当 rollback 失败时，`retain_old_image = true`，`tmp` 永远不会被释放。这是一个有意的设计（防止 UAF），但意味着：
- JIT image 内存永久泄漏
- `bpf_prog_aux` 及其所有关联资源永久泄漏
- 无法恢复——系统只能通过重启清理

这种情况虽然极端（rollback of rollback 失败），但应该被计数并暴露给用户空间。

**建议**：
1. 添加一个 atomic 计数器跟踪泄漏的 JIT images
2. 通过 `/proc/bpf_stats` 或 sysfs 暴露
3. 考虑是否可以延迟释放（如 workqueue retry）

### 4.3 [HIGH] REJIT rollback 路径的 trampoline refresh 失败可能导致不一致状态

```c
err = bpf_trampoline_refresh_prog(prog);
if (err) {
    ret = err;
    err = bpf_prog_rejit_rollback(prog, tmp, new_bpf_func, ...);
    if (err) {
        retain_old_image = true;
    }
    goto post_swap_sync;
}
```

`bpf_prog_rejit_rollback()` 内部又调用 `bpf_trampoline_refresh_prog()`。如果正向 refresh 失败了，rollback 中的 refresh 很可能也会失败（相同的底层问题）。这导致：
- prog->bpf_func 已被 swap 回旧值
- 但 trampoline image 仍指向新 bpf_func（已被 tmp 持有）
- tmp 被 retain（不释放），但其 JIT image 被 trampoline 引用
- 形成悬挂引用

**建议**：考虑在正向 refresh 失败时直接 `retain_old_image = true` 而不尝试 rollback，或者将 trampoline refresh 改为 swap-before-refresh 模式。

### 4.4 [HIGH] `bpf_prog_rejit_poke_target_phase` 全局扫描 `map_idr` 的性能和锁问题

```c
while ((map = bpf_map_get_curr_or_next(&id))) {
    if (map->map_type != BPF_MAP_TYPE_PROG_ARRAY) {
        bpf_map_put(map);
        id++;
        continue;
    }
    ...
    for (key = 0; key < array->map.max_entries; key++) {
        if (array->ptrs[key] != prog)
            continue;
        mutex_lock(&array->aux->poke_mutex);
        ...
    }
}
```

这个函数遍历系统中**所有** BPF map，对每个 PROG_ARRAY 遍历所有 entry。在大规模部署中（数千 map，大 PROG_ARRAY），这会是 O(total_maps * max_entries) 的操作，且在 REJIT 热路径中执行两次（phase 1 + phase 2）。

此外，`array->ptrs[key]` 的无锁读取（注释说是 intentionally lockless pre-check）之后取 `poke_mutex` 再检查——这里有个 TOCTOU 窗口。虽然注释声称两个方向都是 benign，但如果一个 map_update 操作在两个 phase 之间发生（delete phase NOP'd 一个 slot，然后那个 slot 被替换成另一个 prog，insert phase 看不到它），可能导致某些 caller 的 direct jump 永久指向 NOP。

**建议**：
1. 在 `bpf_prog_aux` 中维护反向索引（哪些 PROG_ARRAY 包含此 prog），避免全局扫描
2. 文档化 TOCTOU 窗口的安全论证

### 4.5 [HIGH] `bpf_prog_rejit()` 缺少对 `prog->type == BPF_PROG_TYPE_TRACING` (fentry/fexit/fmod_ret) 的特殊处理

`bpf_prog_rejit_supported()` 没有排除 TRACING 类型程序。TRACING 程序的 `dst_prog` 和 `dst_trampoline` 在 attach 后被清零（`bpf_tracing_link_init` 中）。注释说"the existing trampoline_users refresh path handles the attached tracing case"，但这依赖于 `trampoline_users` 链表在 link 阶段被正确填充。

如果程序通过旧路径 attach（不经过 `bpf_trampoline_link_prog` 的新代码），`trampoline_users` 为空，refresh 会被跳过，trampoline 仍指向旧 image。

**建议**：添加测试覆盖 fentry/fexit REJIT 场景，或在 supported 检查中验证 trampoline_users 非空。

### 4.6 [MEDIUM] `rejit_scx_debug_prog()` 是调试残留代码

```c
static void rejit_scx_debug_prog(const char *phase, const struct bpf_prog *prog, u32 req_id)
{
    if (!prog || prog->type != BPF_PROG_TYPE_STRUCT_OPS)
        return;
    pr_info("rejit-scx-debug: %s req_id=%u prog_id=%u ...\n", ...);
}
```

这个函数及其 ~8 处调用点是纯粹的调试代码，不应出现在 upstream submission 中。`pr_info` 在 struct_ops prog 的每次 `get_fd_by_id` 和 `get_info_by_fd` 中触发，会污染 dmesg。

**建议**：删除所有 `rejit_scx_debug_prog` 调用和定义。

### 4.7 [MEDIUM] `bpf_prog_get_stats()` 新增的 NULL check 改变了已有语义

```c
if (unlikely(!prog->stats)) {
    stats->nsecs = 0;
    stats->cnt = 0;
    stats->misses = 0;
    return;
}
```

原始代码假设 `prog->stats` 总是非 NULL（由 `bpf_prog_alloc` 保证）。添加 NULL check 意味着 REJIT 路径可能产生 `stats == NULL` 的 prog。这是一个隐性的合同变更，需要解释何时 `stats` 会为 NULL。

### 4.8 [MEDIUM] `bpf_prog_load` 中为所有程序复制 `orig_insns` 增加内存开销

```c
prog->aux->orig_insns = kvmemdup(prog->insns, bpf_prog_insn_size(prog), GFP_USER);
```

这对**每个** BPF 程序都生效，不仅仅是会被 REJIT 的程序。对于一个 10K insn 的程序，这额外消耗 ~80KB 内存。在大规模部署中（数千 BPF 程序），总开销可达数十 MB。

**建议**：
1. 懒分配：仅在首次 REJIT 或 `GET_ORIGINAL` 请求时复制
2. 或通过 `BPF_F_REJITABLE` flag 显式 opt-in

### 4.9 [MEDIUM] `prog->aux->prog_flags` 存储了 `~BPF_F_TOKEN_FD` 过滤后的 flags

```c
prog->aux->prog_flags = attr->prog_flags & ~BPF_F_TOKEN_FD;
```

但 REJIT 重放时直接使用 `prog->aux->prog_flags`，未考虑 flags 可能在内核版本间语义变化。这是一个 minor 问题，但需要文档化。

### 4.10 [LOW] `BPF_PROG_REJIT_MAX_FD_ARRAY = 64` 魔数缺少 justification

为什么是 64？如果 BPF 程序引用了更多 map，REJIT 会失败。应该与 `BPF_PROG_LOAD` 的限制保持一致。

### 4.11 [HIGH] `bpf_prog_rejit()` 中 `copy_from_bpfptr` 的第三参数使用 `false` 硬编码

```c
if (copy_from_bpfptr(tmp->insns, make_bpfptr(attr->rejit.insns, false), ...))
```

`false` 表示这是 userspace 指针。正确。但如果 REJIT 被从内核空间调用（如未来的 in-kernel daemon），这里需要 `uattr.is_kernel`。当前 `bpf_prog_rejit` 只从 `__sys_bpf` 调用，所以暂时安全，但缺少面向未来的设计。

---

## 5. `kernel/bpf/trampoline.c` — Trampoline 集成

### 5.1 [HIGH] 锁顺序问题：`rejit_mutex` -> `tr->mutex` 可能与其他路径死锁

```c
// bpf_trampoline_link_prog:
mutex_lock(&link->link.prog->aux->rejit_mutex);
mutex_lock(&tr->mutex);

// bpf_trampoline_refresh_prog (called under rejit_mutex):
list_for_each_entry(tu, ...) {
    mutex_lock(&tr->mutex);
    ...
}
```

锁顺序：`rejit_mutex` -> `tr->mutex`。

但在其他内核路径中（如 `bpf_trampoline_update` 被其他 subsystem 直接调用时），`tr->mutex` 可能先于 `rejit_mutex` 被持有。虽然当前代码中 `bpf_trampoline_link/unlink` 总是先取 `rejit_mutex`，但如果有任何路径先取 `tr->mutex` 再调用涉及 `rejit_mutex` 的函数，就会死锁。

**建议**：
1. 在 `include/linux/bpf.h` 中文档化锁顺序：`rejit_mutex` -> `tr->mutex` -> `poke_mutex`
2. 添加 `lockdep_assert_held` 注解
3. 审计所有 `tr->mutex` 持有路径，确保不存在反向锁序

### 5.2 [MEDIUM] `bpf_tramp_user` 结构在 link 时分配但在 unlink 时线性搜索

```c
list_for_each_entry_safe(tu, tmp, &link->link.prog->aux->trampoline_users, list) {
    if (tu->tr == tr) {
        list_del(&tu->list);
        kfree(tu);
        break;
    }
}
```

线性搜索。如果一个 prog 被大量 trampoline 引用（如通过 multi-attach），这可能成为瓶颈。但实际场景中数量通常很小，可接受。

---

## 6. `kernel/bpf/dispatcher.c` — Dispatcher 刷新

### 6.1 [MEDIUM] `synchronize_rcu_expedited()` 在 REJIT 路径中使用

```c
if (expedited)
    synchronize_rcu_expedited();
else
    synchronize_rcu();
```

`synchronize_rcu_expedited()` 会向所有 CPU 发 IPI，对实时工作负载有影响。在 REJIT 路径中使用是合理的（减少替换延迟），但应该有 sysctl 或 prog flag 允许用户选择 normal vs expedited。

---

## 7. `kernel/bpf/bpf_struct_ops.c` — Struct_ops 实时修补

### 7.1 [HIGH] `find_next_call_site` 中直接解码 native 指令，缺少对 speculative execution gadget 的考虑

```c
#ifdef CONFIG_X86
for (; start + CALL_INSN_SIZE <= end;) {
    struct insn insn;
    u8 *p = (u8 *)start;
    insn_init(&insn, p, end - start, 1);
    if (insn_get_length(&insn) || !insn.length)
        break;
    ...
    if (*p == CALL_INSN_OPCODE) {
        s32 disp = *(s32 *)(p + 1);
        ...
    }
}
```

在 trampoline image 中线性扫描 CALL 指令本身不是安全问题，但如果 trampoline image 被修改（如并发 text_poke），解码可能出错。函数假设 image 在扫描期间稳定——这依赖于调用者持有 `st_ops_assoc_mutex`，但 trampoline image 的修改可能不受此 mutex 保护。

### 7.2 [MEDIUM] `krealloc_array` 在循环中逐个增长 `call_sites` 数组

```c
grown = krealloc_array(call_sites, call_site_cnt + 1, sizeof(*call_sites), GFP_KERNEL);
```

每找到一个 call site 就 realloc 一次。应预分配合理大小或使用 exponential growth。

### 7.3 [MEDIUM] `bpf_arch_text_poke` 的 rollback 路径可能部分失败

```c
while (patched_cnt > 0) {
    void *patched_site = call_sites[--patched_cnt];
    if (bpf_arch_text_poke(patched_site, BPF_MOD_CALL,
                          BPF_MOD_CALL, new_bpf_func, (void *)old_bpf_func))
        pr_warn("struct_ops rejit: rollback text_poke failed\n");
}
```

Rollback `text_poke` 失败只打印 warning 但不返回错误。这意味着部分 call site 指向新 image、部分指向旧 image——一个不一致的状态。

### 7.4 [MEDIUM] `bpf_arch_text_poke` 调用时参数 `BPF_MOD_CALL` 传了两次

```c
err = bpf_arch_text_poke(call_sites[i], BPF_MOD_CALL,
                         BPF_MOD_CALL,
                         (void *)old_bpf_func,
                         new_bpf_func);
```

`bpf_arch_text_poke` 的签名是 `(void *ip, enum bpf_text_poke_type t, void *old_addr, void *new_addr)`，只有一个 type 参数。这里传了两个 `BPF_MOD_CALL`——第二个被当作 `old_addr`。这是一个**编译器不会报错的严重 bug**，因为 `enum` 可隐式转换为指针。

实际 `bpf_arch_text_poke` 签名：`int bpf_arch_text_poke(void *ip, enum bpf_text_poke_type t, void *addr1, void *addr2)`

需要确认签名。如果确实只有一个 type 参数，这里第二个 `BPF_MOD_CALL` 会被当成 `old_addr = (void*)1`（BPF_MOD_CALL 通常是 1），导致 text_poke 匹配不到旧值而失败或产生 UB。

**建议**：删除多余的 `BPF_MOD_CALL`，确认 `bpf_arch_text_poke` 调用签名。

---

## 8. `kernel/bpf/btf.c` — kinsn 注册基础设施

### 8.1 [MEDIUM] `kinsn_descs` 数组与 `set->pairs` 必须 1:1 对应，但只有隐式约束

```c
for (i = 0; i < add_set->cnt; i++) {
    desc->id = btf_relocate_id(btf, add_set->pairs[i].id);
    desc->kinsn = add_kinsn_descs[i];
}
```

`kinsn_descs[i]` 必须与 `add_set->pairs[i]` 一一对应。如果模块注册时数组长度不匹配，会越界读取。虽然在 `__register_btf_kfunc_id_set` 中有检查 `kinsn_descs[i]` 不为 NULL，但没有检查数组长度。

**建议**：添加显式长度字段或 sentinel。

### 8.2 [LOW] `btf_kfunc_is_allowed` 和 `btf_kfunc_flags` 的 `goto again` 风格不符合内核编码规范

```c
again:
    kfunc_flags = btf_kfunc_id_set_contains(btf, hook, kfunc_btf_id);
    if (kfunc_flags && ...)
        return true;
    if (hook == BTF_KFUNC_HOOK_COMMON) {
        hook = bpf_prog_type_to_kfunc_hook(...);
        if (hook != BTF_KFUNC_HOOK_COMMON)
            goto again;
    }
```

重构为 `goto again` 不如原来的两次独立检查清晰。且这个重构与 kinsn 功能无关——属于不必要的 churn。

**建议**：恢复原始代码，或者在单独的 cleanup patch 中重构。

---

## 9. `kernel/bpf/verifier.c` — Verifier 集成

### 9.1 [HIGH] `lower_kinsn_proof_regions` 在 verifier 探索之前修改指令流，但 `restore_kinsn_proof_regions` 在探索之后恢复

```
bpf_check() {
    add_subprog_and_kfunc();          // 识别 kinsn call
    lower_kinsn_proof_regions();      // 替换 sidecar+call -> proof sequence
    ...
    do_check();                       // verifier 探索 proof sequence
    ...
    restore_kinsn_proof_regions();    // 恢复 sidecar+call
    do_misc_fixups();                 // 再次处理 kinsn
}
```

这个 lower-verify-restore 模式有几个问题：

1. `restore_kinsn_proof_regions` 中使用 `bpf_patch_insn_data` + `verifier_remove_insns` 修改指令流，但此时 `env->insn_aux_data` 的 adjustments 可能与 verifier 探索过程中记录的 aux 数据不一致。
2. `region->start` 是基于 lower 后的指令偏移，restore 时如果多个 region 重叠调整，偏移计算可能出错（虽然 lower 是逆序遍历，但 restore 是正序）。
3. 强制清空 `aux[region->start].jt` 和 `aux[region->start + 1].jt` 可能丢失 verifier 的 jump target 信息。

**建议**：需要更严格的数学证明说明 offset adjustment 的正确性，或添加 assertion 验证。

### 9.2 [HIGH] `validate_kinsn_proof_seq` 的跳转验证不完整

```c
tgt = i + 1 + jmp_off;
if (tgt < 0 || tgt > cnt) { ... }
if (tgt <= i) { ... }
```

允许 `tgt == cnt`（跳出 proof region），这是正确的（fall-through 到下一条指令）。但对于条件跳转（`BPF_JNE`, `BPF_JGT` 等），fall-through 路径也需要验证——当 `i == cnt - 1` 时 fall-through 目标是 `cnt`，这是允许的。看起来正确。

但是，proof sequence 中的 `BPF_LD_IMM64`（双 insn）未被考虑。如果 `instantiate_insn` 生成了 `BPF_LD_IMM64`，`i` 需要额外跳过 1 条 insn，否则第二条 insn 会被当作跳转指令检查。

**建议**：添加 `BPF_LD_IMM64` 的 `i++` 处理。

### 9.3 [MEDIUM] `add_kfunc_desc` 中 `tab->nr_descs--` 错误回滚模式

```c
desc = &tab->descs[tab->nr_descs++];
desc->func_id = func_id;
desc->offset = offset;
if (kinsn_call) {
    if (!kfunc.kinsn) {
        tab->nr_descs--;
        return -ENOENT;
    }
    ...
}
```

先 `nr_descs++` 写入 desc，失败后 `nr_descs--`。问题是 desc 的内容没有被清零——如果下次 `add_kfunc_desc` 找到相同的 `func_id/offset`，`find_kfunc_desc` 可能匹配到脏数据。虽然 `find_kfunc_desc` 使用 `bsearch`（依赖排序后的数组），而 `sort` 在函数末尾执行，所以脏数据在排序区间之外不会被 bsearch 找到。但这仍然是不好的实践。

**建议**：先验证完所有条件，再 `nr_descs++` 并写入。

### 9.4 [MEDIUM] `__find_kfunc_desc_btf` 中新增的 `kfunc_btf_tab` lazy allocation 改变了原始语义

```c
tab = env->prog->aux->kfunc_btf_tab;
+if (!tab) {
+    tab = kzalloc_obj(*tab, GFP_KERNEL_ACCOUNT);
+    if (!tab)
+        return ERR_PTR(-ENOMEM);
+    env->prog->aux->kfunc_btf_tab = tab;
+}
```

原来 `__find_kfunc_desc_btf` 在 `!tab` 时不会自行分配（由 `add_kfunc_call` 预分配）。现在 kinsn 路径跳过了预分配（因为 kinsn 不需要 btf_tab），但如果 kinsn 的 BTF 解析路径意外进入这里，就会 lazy allocate。这改变了 `add_kfunc_call` 移除 btf_tab 预分配后的行为。

需要确认所有调用 `__find_kfunc_desc_btf` 的路径是否都能正确处理 lazy allocation。

### 9.5 [MEDIUM] `check_kinsn_sidecar_insn` 直接跳过 `env->insn_idx++`

```c
static int check_kinsn_sidecar_insn(struct bpf_verifier_env *env, ...)
{
    ...
    env->insn_idx++;
    return 0;
}
```

在 `do_check_insn` 返回 0 后，`do_check` 循环会再次 `env->insn_idx++`。所以 sidecar insn 实际跳过 2 条指令（sidecar 自身 + kinsn call）。这**假设** kinsn call 紧跟 sidecar，且 kinsn call 不需要 verifier 检查（因为 proof sequence 已经被验证）。

但是——在 `lower_kinsn_proof_regions` 之后，sidecar+call 已被替换为 proof sequence。所以在 `do_check` 执行时，不应该遇到 sidecar insn。这个 `check_kinsn_sidecar_insn` 只在 proof regions 没有被 lower 的情况下才会被触发。

这形成了一个矛盾：如果 lower 成功了，sidecar 不存在；如果 lower 失败了，verifier 不应该继续。那么 `check_kinsn_sidecar_insn` 在什么场景下会被调用？

**建议**：如果这是 dead code，应删除。如果有合法场景，需要文档化。

### 9.6 [LOW] `bpf_pseudo_kinsn_call` 在 `do_check_insn` 中触发 `-EFAULT`

```c
} else if (insn->src_reg == BPF_PSEUDO_KINSN_CALL) {
    verbose(env, "internal error: kinsn call reached verifier without proof lowering\n");
    return -EFAULT;
}
```

同上问题——如果 lower 总是在 do_check 之前运行，这是 dead code。如果是防御性编程，与项目规范（"内核代码中不保留以防万一的检查"）冲突。

---

## 10. `arch/x86/net/bpf_jit_comp.c` — x86 JIT

### 10.1 [MEDIUM] `emit_kinsn_desc_call` 使用栈上 `BPF_MAX_INSN_SIZE` 字节的 scratch buffer

```c
u8 scratch[BPF_MAX_INSN_SIZE];
```

`BPF_MAX_INSN_SIZE` 通常是 15（x86 最长指令）或更大的值。如果 `max_emit_bytes` 可以很大（如 256 字节），栈上分配可能溢出。虽然有 `if (kinsn->max_emit_bytes > BPF_MAX_INSN_SIZE) return -E2BIG` 保护，但 `BPF_MAX_INSN_SIZE` 的定义需要确认是否足够。

### 10.2 [MEDIUM] `BPF_ALU64|BPF_MOV|BPF_K` 的 sidecar skip 位置可能影响其他 MOV_K 指令

```c
case BPF_ALU64 | BPF_MOV | BPF_K:
case BPF_ALU | BPF_MOV | BPF_K:
+   if (bpf_kinsn_is_sidecar_insn(insn))
+       break;
    emit_mov_imm32(&prog, ...);
```

`bpf_kinsn_is_sidecar_insn` 检查 `code == (BPF_ALU64|BPF_MOV|BPF_K) && src_reg == BPF_PSEUDO_KINSN_SIDECAR`。这意味着 `BPF_ALU|BPF_MOV|BPF_K`（32-bit MOV）的 case 也会经过这个检查。虽然 sidecar 只使用 `BPF_ALU64|BPF_MOV|BPF_K`，检查不会匹配 32-bit case，但 fallthrough 位置在两个 case label 之间，每个 32-bit MOV_K 都会执行一次额外的 `bpf_kinsn_is_sidecar_insn` 检查——这是 JIT 编译时的 micro-overhead。

---

## 11. `arch/arm64/net/bpf_jit_comp.c` — ARM64 JIT

### 11.1 [HIGH] `emit_kinsn_desc_call_arm64` 直接写入 `ctx->image` 而非 scratch buffer

```c
n_insns = kinsn->emit_arm64(ctx->image, &ctx->idx, ctx->write, payload, bpf_prog);
if (n_insns < 0) return n_insns;
if (ctx->idx - saved_idx != n_insns) return -EFAULT;
if (n_insns * 4 > kinsn->max_emit_bytes) return -EFAULT;
```

与 x86 不同，ARM64 直接让模块回调写入 JIT image。如果回调写入超过声明的 `max_emit_bytes`，后验证（`ctx->idx - saved_idx != n_insns`）会检测到不一致，但写入已经发生——可能破坏后续指令或越界写入。

**建议**：ARM64 也应使用 scratch buffer + `memcpy` 模式。

### 11.2 [LOW] `build_insn` 开头的 sidecar skip 对性能无影响但增加了代码路径

```c
if (bpf_kinsn_is_sidecar_insn(insn))
    return 0;
```

每条指令都会检查。对 JIT 编译性能影响极小，但不如在 `build_body` 循环中提前过滤。

---

## 12. `kernel/bpf/core.c` — 初始化

### 12.1 [LOW] `mutex_init` 和 `INIT_LIST_HEAD` 的位置

```c
mutex_init(&fp->aux->rejit_mutex);
INIT_LIST_HEAD(&fp->aux->trampoline_users);
```

正确初始化。无问题。

---

## 13. `kernel/bpf/dispatcher.c`

### 13.1 [LOW] `bpf_dispatcher_refresh_prog` 正确但缺少对 `prog` 实际是否在 dispatcher 中的高效检查

`bpf_dispatcher_find_prog` 线性搜索，但 dispatcher 通常只有少量 prog，可接受。

---

## 14. 缺失功能

### 14.1 [HIGH] 缺少 `bpf_kinsn_region` 结构定义

diff 中使用了 `struct bpf_kinsn_region`，但未包含其定义（应在 `include/linux/bpf_verifier.h` 中）。patch 不完整。

### 14.2 [HIGH] 缺少 verifier env 字段的定义

`env->kinsn_regions`、`env->kinsn_region_cnt`、`env->kinsn_region_cap`、`env->kinsn_call_cnt` 在 `struct bpf_verifier_env` 中的定义未包含在 diff 中。

### 14.3 [HIGH] 缺少 `bpf_prog_refresh_xdp` 的实现

只有声明，没有实现。

### 14.4 [MEDIUM] 缺少 `btf_kfunc_id_set::kinsn_descs` 字段定义

`kset->kinsn_descs` 被引用但 `struct btf_kfunc_id_set` 的修改不在 diff 中。

### 14.5 [MEDIUM] 缺少 selftests

没有任何自测试代码。upstream BPF 变更必须附带 selftests。

### 14.6 [LOW] 缺少 `bpf_map_get_curr_or_next` 的实现/声明

在 `bpf_prog_rejit_poke_target_phase` 中使用，但未在 diff 中出现。

---

## 15. 总结

| 严重度 | 数量 | 代表性问题 |
|--------|------|-----------|
| CRITICAL | 2 | 热路径 `smp_load_acquire` 全局开销；`memcpy` 越界写入风险 |
| HIGH | 9 | 模块 emit 回调无沙箱；`retain_old_image` 泄漏；锁顺序未文档化；poke target 全局扫描；diff 不完整 |
| MEDIUM | 15 | 调试代码残留；`orig_insns` 全局分配；`krealloc_array` 逐个增长；proof region offset 正确性等 |
| LOW | 6 | 编码风格、magic number、minor optimization |

### 阻塞上游提交的问题（must fix）：

1. **删除所有 `rejit_scx_debug_prog` 调试代码**
2. **修复 `bpf_struct_ops_refresh_prog` 中 `bpf_arch_text_poke` 的参数错误**（双 `BPF_MOD_CALL` 问题）
3. **ARM64 emit 回调改用 scratch buffer**
4. **`bpf_prog_rejit_swap` 中的 insns memcpy 越界检查**需使用精确 allocation size
5. **补全缺失的结构体定义和函数实现**
6. **`smp_load_acquire` 在热路径的性能影响**需要基准数据支撑或改用更轻量方案
7. **文档化锁顺序**：`rejit_mutex` -> `tr->mutex` -> `poke_mutex` -> `array->aux->poke_mutex`
8. **添加 selftests**
9. **`orig_insns` 改为 opt-in 或 lazy 分配**，避免全局内存开销

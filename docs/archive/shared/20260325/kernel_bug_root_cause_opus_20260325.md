# BpfReJIT 内核 Bug Root Cause 分析报告

**日期**: 2026-03-25
**分析方法**: 从 bug 复现报告出发，对照内核源码逐行分析
**内核分支**: `vendor/linux-framework` HEAD (`2d3c5adb3`)
**参考好基线**: `e7d27ef37`

---

## 总览

从复现报告 (`tcg_min_repro_and_e2e_investigation_20260325.md`) 中确认了以下独立的失败类别：

1. **QEMU TCG 崩溃** — `scx_rusty` struct_ops 程序在 `bpftool prog show` 枚举时触发 QEMU segfault at `tlb_set_dirty`
2. **REJIT verifier 未拦截 malformed bytecode** — daemon 生成的 `rusty_exit` (prog 20) 包含 malformed `LD_IMM64` scalar loads，live 场景曾通过 verifier 但 replay 被拒绝
3. **多个 REJIT correctness 失败** — `sysctl_monitor`, `event_execve`, `lkm_seeker_modt`, `rusty_init_task` 等程序的 verifier 拒绝

以下逐一分析每个 bug 的内核代码 root cause。

---

## Bug #1: QEMU TCG 崩溃 — `bpf_prog_get_stats()` 空指针解引用 (已部分修复)

### Root Cause

**文件**: `kernel/bpf/syscall.c:5751`（调用 `bpf_prog_get_stats`）
**函数**: `bpf_prog_get_info_by_fd()` -> `bpf_prog_get_stats()`

**核心问题**: struct_ops 程序通过 `jit_subprogs()` 编译时，子程序通过 `bpf_prog_alloc_no_stats()` 分配（`verifier.c:23198`），**不分配** `prog->stats`。主程序的 `bpf_func` 指向 `func[0]->bpf_func`（`verifier.c:23370`）。

当 `bpftool prog show` 查询 struct_ops 程序时，`bpf_prog_get_info_by_fd()` 在第 5751 行调用 `bpf_prog_get_stats(prog, &stats)`。主程序（通过 `bpf_prog_alloc()` 分配）有 `stats`，但如果内核错误地传入了一个子程序的指针，或者在某些竞态条件下 `prog->stats` 为 NULL，就会触发空指针解引用。

**确认**: dirty-tree 中的修复补丁（`syscall.c:2466-2471`）添加了 `if (unlikely(!prog->stats))` guard，证实了这个 bug 是真实的。

### 但修复不充分 — 剩余崩溃

复现报告明确记录: 添加 null-stats guard 后，崩溃**频率降低但未消除**（报告第 1029-1053 行）。剩余崩溃仍在 `bpf_prog_get_info_by_fd()` 路径内，但在 `bpf_prog_get_stats()` 之后的其他位置。

### 剩余崩溃的可能 Root Cause

分析 `bpf_prog_get_info_by_fd()` 中所有访问 `prog->aux->func[i]` 的位置：

1. **`syscall.c:5823-5824`**: `prog->aux->func[i]->jited_len` — 如果 `func_cnt > 0` 但 `func` 数组已被释放或指向无效内存
2. **`syscall.c:5842-5846`**: `prog->aux->func[i]->bpf_func` — 同样依赖 `func` 数组有效性
3. **`syscall.c:5877-5878`**: `prog->aux->func[i]->bpf_func` — 用于 `jited_ksyms`
4. **`syscall.c:5905-5906`**: `prog->aux->func[i]->jited_len` — 用于 `jited_func_lens`
5. **`syscall.c:5980-5983`**: `prog->aux->func[i]->tag` — 用于 `prog_tags`

**竞态场景**: `probe_bpftool_register()` 创建的第一组 struct_ops 程序被注册/注销。注销时 `bpf_struct_ops_map_free()` 调用 `synchronize_rcu_mult()` 后 `__bpf_struct_ops_map_free()` 释放 trampoline image。如果第二组 `scx_rusty` 程序的 ID 复用了第一组的 ID（idr 分配），而 `bpftool prog show` 在两者之间的窗口查询，可能访问到正在释放过程中的程序。

**但更关键的是**: 复现报告的 bisect 表明这是一个**回归 bug**。好基线 `e7d27ef37` 不崩溃，但 HEAD 崩溃。在 `e7d27ef37..HEAD` 的变更中：

- `2d3c5adb3` 引入了 `bpf_struct_ops_refresh_prog()` 的两阶段改写（先找所有 call sites，再逐个 patch）
- `cefee2648` 修复了 struct_ops multi-slot 问题
- `8a6923893` 修复了内存泄漏和 struct_ops 相关问题

具体回归原因需要 git bisect 确认，但从代码分析看，最可能的触发路径是 **probe 注册创建的 struct_ops map 在 unregister 时释放了 trampoline image，但 ksym 注册信息或程序引用在 RCU grace period 内未完全清理**，导致后续的 `bpftool prog show` 通过 `bpf_prog_by_id()` 获取到一个虽然 refcount > 0 但其 struct_ops 关联已被部分拆除的程序，访问已释放的 trampoline 内存时触发 guest 级别的非法内存访问，进而导致 QEMU TCG segfault。

### 触发路径

```
probe_bpftool_register()                    # 创建 struct_ops map + programs
  -> bpf_struct_ops_map_update_elem()       # 注册 struct_ops
  -> bpf_struct_ops_map_delete_elem()       # 注销 struct_ops
  -> bpf_struct_ops_map_free()              # 释放 map
    -> bpf_struct_ops_map_dissoc_progs()    # 解除 prog -> map 关联
    -> bpf_struct_ops_map_del_ksyms()       # 删除 trampoline ksyms
    -> synchronize_rcu_mult()               # 等待 RCU
    -> __bpf_struct_ops_map_free()          # 释放 trampoline image

scx_rusty --stats 1                         # 创建第二组 struct_ops

bpftool prog show id <id>                   # 查询程序信息
  -> bpf_prog_get_fd_by_id()
  -> bpf_prog_get_info_by_fd()
    -> bpf_prog_get_stats(prog)             # prog->stats == NULL (已修复)
    -> prog->aux->func[i]->bpf_func        # 可能访问无效指针 (未修复)
```

### 修复方案

1. **`syscall.c:2466`** — null stats guard 已添加（保留）
2. 需要进一步排查 `prog->aux->func[]` 在 struct_ops 程序中是否始终有效。考虑在 `bpf_prog_get_info_by_fd()` 中对所有 `func[i]` 访问添加防御性检查
3. 需要 git bisect 在 `e7d27ef37..2d3c5adb3` 范围内找到精确的回归 commit

### 优先级: **P0** — 导致 QEMU 进程崩溃，可触发 host 重启

---

## Bug #2: `smp_wmb()` + `WRITE_ONCE()` 替代 `smp_store_release()` — 内存序降级

### Root Cause

**文件**: `kernel/bpf/syscall.c:3455-3457`
**函数**: `bpf_prog_rejit_swap()`

```c
/* Publish the replacement image after metadata is in place. */
smp_wmb();
WRITE_ONCE(prog->bpf_func, tmp->bpf_func);
```

**问题**: commit `2d3c5adb3` 将原来的 `smp_store_release(&prog->bpf_func, tmp->bpf_func)` 降级为 `smp_wmb()` + `WRITE_ONCE()`。

- `smp_store_release` = compiler barrier + store barrier（在 ARM64 上生成 `STLR` 指令）
- `smp_wmb()` = 仅 write-write barrier（在 ARM64 上生成 `DMB ISHST`）
- 读端（`BPF_PROG_RUN` 宏）使用普通 load 读取 `prog->bpf_func`，没有 `smp_load_acquire`

**在 ARM64 弱序架构上**: 读端 CPU 可能看到新的 `bpf_func` 值，但对之前写入的 metadata（`prog->len`, `prog->insnsi`, `prog->aux->func[]` 等）的读取被重排到 `bpf_func` 读取之前执行，拿到旧值。这导致 metadata 不一致：

- 新 `bpf_func` + 旧 `prog->len` → `bpf_prog_get_info_by_fd` 可能报告错误的 insn 数量
- 新 `bpf_func` + 旧 `prog->aux->func[]` → 运行时可能跳转到已释放的子函数地址
- 新 `bpf_func` + 旧 `prog->aux->extable` → 异常处理可能使用错误的异常表

**在 x86 TSO 架构上**: 由于 x86 的 Total Store Order 保证，`smp_wmb()` 等价于 compiler barrier，实际安全。但代码声明支持 ARM64（有 `emit_arm64` callback），因此必须正确处理。

### 具体代码位置

- **写端**: `syscall.c:3455-3457` — `smp_wmb()` + `WRITE_ONCE(prog->bpf_func, ...)`
- **读端**: `include/linux/filter.h` 中 `BPF_PROG_RUN` 宏 — 使用普通 load 读 `prog->bpf_func`

### 修复方案

恢复为 `smp_store_release`：
```c
smp_store_release(&prog->bpf_func, tmp->bpf_func);
```

或者更完善地，使用 `rcu_assign_pointer()` + 读端 `rcu_dereference()`。

### 优先级: **P0** (ARM64)，**P2** (x86-only)

---

## Bug #3: `bpf_prog_rejit_swap()` 遗漏 `tail_call_reachable` 字段

### Root Cause

**文件**: `kernel/bpf/syscall.c:3372-3470`
**函数**: `bpf_prog_rejit_swap()`

`tail_call_reachable` 在 verifier 的 `check_cfg()` 阶段设置（`verifier.c:7187`）：
```c
if (subprog[0].tail_call_reachable)
    env->prog->aux->tail_call_reachable = true;
```

并在 `jit_subprogs()` 中传播到子函数（`verifier.c:23262`）：
```c
func[i]->aux->tail_call_reachable = env->subprog_info[i].tail_call_reachable;
```

在 `bpf_prog_rejit_swap()` 的 swap 列表中（第 3379-3444 行），**没有** `swap(prog->aux->tail_call_reachable, tmp->aux->tail_call_reachable)`。

**影响**: `tail_call_reachable` 控制 JIT 是否在函数 prologue 中保存/恢复 tail_call 计数器。如果原程序 `tail_call_reachable = false` 但 REJIT 后新程序需要 tail_call 保护，计数器不会被保存，tail_call 递归保护失效，可能导致**内核栈溢出**。

### 验证

搜索 `syscall.c` 中所有对 `tail_call_reachable` 的引用：**零条**。确认完全遗漏。

### 修复方案

在 `bpf_prog_rejit_swap()` 中添加：
```c
swap(prog->aux->tail_call_reachable, tmp->aux->tail_call_reachable);
```

更好的方案是将所有 verifier/JIT 输出字段打包为子结构，一次性 swap。

### 优先级: **P0** — 可导致内核栈溢出

---

## Bug #4: `bpf_kinsn_has_native_emit()` 原未定义 + 缩进错误（已修复）

### Root Cause

**文件**: `kernel/bpf/verifier.c:23776`
**函数**: `do_misc_fixups()`

原始代码中 `bpf_kinsn_has_native_emit()` 函数**未定义**（grep 确认只有 verifier.c 中一处引用，没有定义）。同时该代码块存在严重缩进错误（多了一层 tab），导致控制流含义不明。

### 当前状态

dirty-tree 中已修复两个问题：

1. **`include/linux/bpf.h:981-993`** — 添加了 `bpf_kinsn_has_native_emit()` 内联函数
2. **`verifier.c:23773-23781`** — 修复了缩进，使控制流清晰

修复后的逻辑：如果 `prog->jit_requested` 且 kinsn 有 native emit callback，则跳过 proof sequence 的 insn 替换（因为 JIT 会直接使用 native emit）。否则执行标准的 `verifier_remove_insns` + `bpf_patch_insn_data` 路径。

### 优先级: **P0**（已在 dirty-tree 中修复，需 commit）

---

## Bug #5: `bpf_struct_ops_refresh_prog()` 部分成功后状态不一致

### Root Cause

**文件**: `kernel/bpf/bpf_struct_ops.c:1518-1582`
**函数**: `bpf_struct_ops_refresh_prog()`

commit `2d3c5adb3` 将 `bpf_struct_ops_refresh_prog()` 改为两阶段：

**阶段 1** (第 1538-1559 行): 找到所有 call sites
```c
for (i = 0; i < st_map->funcs_cnt; i++) {
    ...
    call_sites[i] = find_call_site(..., (void *)old_bpf_func);
    if (!call_sites[i]) {
        err = -ENOENT;
        goto out;     // 提前返回错误
    }
}
```

**阶段 2** (第 1561-1577 行): 逐个 patch
```c
for (i = 0; i < st_map->funcs_cnt; i++) {
    ...
    err = bpf_arch_text_poke(call_sites[i], BPF_MOD_CALL,
                             BPF_MOD_CALL,
                             (void *)old_bpf_func,
                             (void *)prog->bpf_func);
    if (err) {
        goto out;     // 部分 patch 后返回错误
    }
}
```

**问题**: 如果阶段 2 在 patch 第 N 个 site 时失败，前 N-1 个 site 已经被 patch 为新地址，剩余 site 仍指向旧地址。此时返回错误码，`bpf_prog_rejit()` 进入 rollback 路径。

rollback 调用 `bpf_prog_rejit_swap()` 恢复旧 `bpf_func`，然后再次调用 `bpf_struct_ops_refresh_prog()` 尝试恢复。但此时：
- 已 patch 的 sites 指向新地址 → `find_call_site(... new_bpf_func)` 能找到
- 未 patch 的 sites 仍指向旧地址 → `find_call_site(... new_bpf_func)` 找不到

如果 rollback 的 `find_call_site` 失败，`bpf_prog_rejit_rollback()` 返回错误，`retain_old_image = true` 防止释放。**结果是内存泄漏 + 部分更新的不一致状态**。

### 修复方案

在阶段 2 的 patch 循环中，如果某个 site patch 失败，应立即回滚已 patch 的 sites（按逆序 patch 回旧地址），而非依赖外层 rollback。

### 优先级: **P1** — 内存泄漏 + 不一致状态，但不是 UAF

---

## Bug #6: `bpf_prog_rejit_swap()` 遗漏其他 verifier/JIT 输出字段

### Root Cause

**文件**: `kernel/bpf/syscall.c:3372-3470`

除了 `tail_call_reachable`（Bug #3, P0），以下字段也未被 swap：

| 字段 | 设置位置 | 影响 |
|------|---------|------|
| `arena` | `verifier.c:22249` | BPF arena 内存映射不一致 |
| `ctx_arg_info` / `ctx_arg_info_size` | `verifier.c:25122` | 运行时上下文参数类型检查错误 |
| `attach_func_proto` | `verifier.c:25769` | 信息查询不一致 |
| `attach_func_name` | `verifier.c:25770` | 信息查询不一致 |
| `sleepable_used_maps` | verifier sleepable path | sleepable 程序 map 追踪不一致 |
| `exception_cb` | verifier exception path | 异常回调指向旧程序 |

### 修复方案

将 `bpf_prog_aux` 中所有 verifier/JIT 产出字段分组为 `struct bpf_prog_compile_output` 子结构，swap 整个子结构。

### 优先级: **P1**

---

## Bug #7: `INIT_LIST_HEAD_RCU` 在 `synchronize_rcu` 之前重用

### Root Cause

**文件**: `kernel/bpf/core.c:655-657`
**函数**: `__bpf_ksym_del()`

```c
latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
list_del_rcu(&ksym->lnode);
INIT_LIST_HEAD_RCU(&ksym->lnode);
```

然后在 `bpf_prog_rejit_swap()` 中（`syscall.c:3404, 3462`）：
```c
bpf_prog_kallsyms_del_all(prog);   // 调用 __bpf_ksym_del -> INIT_LIST_HEAD_RCU
...
bpf_prog_kallsyms_add(prog);       // 重新注册，使用 lnode
```

**问题**: `list_del_rcu()` 后的 `INIT_LIST_HEAD_RCU()` 允许 `lnode` 立即被重用。但在 RCU 读侧临界区中，其他 CPU 可能正在遍历这个 list node 的 `next` 指针。`INIT_LIST_HEAD_RCU` 将 `next` 设为 self-loop，导致正在遍历的 CPU 陷入无限循环。

`bpf_prog_kallsyms_add(prog)` 在 swap 函数内被调用，此时**没有**经过 `synchronize_rcu`（swap 后才有 `synchronize_rcu`）。因此在 RCU grace period 之前就重用了 list node。

### 修复方案

将 `bpf_prog_kallsyms_add(prog)` 移到 `synchronize_rcu` 之后。或在 swap 后不重新注册 kallsyms，而是在 `post_swap_sync` 之后注册。

### 优先级: **P1** — 可能导致 CPU 自旋，但触发需要精确时序

---

## Bug #8: REJIT verifier 放过 malformed `rusty_exit` bytecode

### Root Cause

复现报告确认 `rusty_exit` (prog 20) 的 REJIT 失败原因是**用户态 daemon 的 `const_prop` pass 错误**：

- `const_prop` 将 `r1 = map_value; r1 += 16` 变换为 `r1 = 0x...21`（纯 scalar ldimm64）
- 这破坏了 verifier 可见的指针类型信息，`r1` 变为 plain scalar
- verifier 在 helper call 处拒绝：`R1 type=scalar expected=... map_value ...`

**关键发现**: 报告第 300-346 行记录，在重建 daemon 后 malformed 输出消失了（30→29 insns），verifier 正确拒绝。第 317-346 行记录 replay 测试也被正确拒绝 (`errno=13`)。

**但**: 历史上（2026-03-25 早期），相同的 malformed bytecode **曾经通过** REJIT verifier 进入 JIT 执行，导致 QEMU 崩溃。这说明：

1. **daemon 侧**: `const_prop` 有一个非确定性 bug，有时生成 malformed output，有时不生成
2. **内核侧**: 当前 verifier 路径（HEAD + dirty-tree fixes）能拦截这种 malformed bytecode
3. **历史版本的内核可能有 verifier bypass**: 在没有 `prog_flags` 修复（commit `2d3c5adb3` 之前版本只传 2 个 flag）的情况下，verifier 可能因为缺少 `BPF_F_ANY_ALIGNMENT` 等 flag 而行为不同

### `load_attr` 构造分析

**文件**: `kernel/bpf/syscall.c:3551-3559`

当前代码（含 `2d3c5adb3` 修复）：
```c
load_attr.prog_type = prog->type;
load_attr.expected_attach_type = prog->expected_attach_type;
load_attr.insn_cnt = attr->rejit.insn_cnt;
load_attr.insns = attr->rejit.insns;
load_attr.log_level = attr->rejit.log_level;
load_attr.log_size = attr->rejit.log_size;
load_attr.log_buf = attr->rejit.log_buf;
load_attr.prog_flags = prog->aux->prog_flags;    // 修复后：完整传递所有 flag
load_attr.fd_array_cnt = attr->rejit.fd_array_cnt;
```

**在修复前** (commit `2d3c5adb3` 之前):
```c
load_attr.prog_flags = (prog->sleepable ? BPF_F_SLEEPABLE : 0) |
                       (prog->aux->xdp_has_frags ? BPF_F_XDP_HAS_FRAGS : 0);
```

这意味着 `BPF_F_ANY_ALIGNMENT`, `BPF_F_TEST_RND_HI32` 等 flag 在旧版本中丢失。对于 struct_ops 程序（scx），如果加载时带了这些 flag，REJIT verifier 使用默认严格检查，可能**以不同方式**处理 bytecode，某些情况下放过 malformed code。

### struct_ops 的 `attach_btf_id` 和 `fd_array`

**文件**: `kernel/bpf/syscall.c:3591-3595, 3562-3577`

```c
// attach_btf 正确传播
if (prog->aux->attach_btf) {
    btf_get(prog->aux->attach_btf);
    tmp->aux->attach_btf = prog->aux->attach_btf;
}
tmp->aux->attach_btf_id = prog->aux->attach_btf_id;
```

**fd_array 处理**: 从用户态 `attr->rejit.fd_array` copy 到内核 buffer `kfd_array`，设置 `load_attr.fd_array`。使用 `KERNEL_BPFPTR` 语义。

严格审查表（见 `kernel_patch_strict_final_review_20260325.md` 第 412-436 行）确认：在当前 HEAD 中，`load_attr` 构造的关键字段（`prog_flags`, `expected_attach_type`, `fd_array`, `attach_btf_id`）都已正确处理。`check_struct_ops_btf_id()` 通过 `bpf_check()` -> `check_attach_btf_id()` 被正确调用。

### 结论

REJIT verifier bypass 的 root cause 是 **`prog_flags` 不完整传递**（已在 `2d3c5adb3` 中修复）。加上 daemon 侧的非确定性 `const_prop` bug，两者共同导致了历史上的 malformed bytecode 通过 verifier。

当前 HEAD + dirty-tree 修复后，replay 测试确认 verifier 能正确拒绝。但应在内核侧添加 regression test 确保不再发生。

### 优先级: **P1**（`prog_flags` 已修复，但需要 regression test 确认不再发生）

---

## Bug #9: `bpf_prog_rejit_swap()` 中 `bpf_prog_kallsyms_add` 后未注册子函数

### Root Cause

**文件**: `kernel/bpf/syscall.c:3462-3469`

```c
bpf_prog_kallsyms_add(prog);
/* NOTE: subfuncs (prog->aux->func[i]) were already registered in
 * bpf_prog_kallsyms by jit_subprogs() during REJIT compilation.
 * Do NOT call bpf_prog_kallsyms_add() for them again here...
 */
```

对比修改前（`e7d27ef37` 基线）:
```c
bpf_prog_kallsyms_add(prog);
{
    u32 i;
    for (i = 0; i < prog->aux->real_func_cnt; i++)
        bpf_prog_kallsyms_add(prog->aux->func[i]);
}
```

在 `2d3c5adb3` 之后的 HEAD 中，不再对子函数调用 `bpf_prog_kallsyms_add()`。注释声称子函数在 `jit_subprogs()` 期间已注册。

**问题**: `jit_subprogs()` 在 tmp 的上下文中运行时，子函数确实会被注册到 kallsyms。但 swap 后，`bpf_prog_kallsyms_del_all(prog)` 删除了旧的 prog 主函数 ksym（第 3404 行），然后 `bpf_prog_kallsyms_add(prog)` 重新注册主函数。子函数的 ksym 在 tmp 的 `jit_subprogs` 期间已注册（使用 tmp 的地址），swap 后这些 ksym 仍然有效（因为新子函数的地址就是 JIT 时的地址）。

但 `tmp` 被释放时（`__bpf_prog_put_noref(tmp, ...)`），会调用 `bpf_prog_kallsyms_del_all(tmp)`，这可能删除 tmp 之前注册的子函数 ksym。如果 tmp 的子函数（现在已被 swap 到 prog->aux->func[]）的 ksym 被 tmp 的 free path 删除了，那些子函数的符号信息就丢失了。

### 触发条件

任何 REJIT swap 后的 `perf`/`bpftool prog dump jited` 可能看不到子函数的符号信息。

### 修复方案

需要仔细审计 `__bpf_prog_put_noref` 中的 `bpf_prog_kallsyms_del_all` 是否删除了 swap 后已属于 prog 的子函数 ksym。

### 优先级: **P2** — 功能性问题，不是安全问题

---

## 优先级排序总结

| # | Bug | 文件:函数:行号 | 触发条件 | 优先级 |
|---|-----|--------------|---------|--------|
| 1 | QEMU TCG 崩溃 — `bpf_prog_get_stats` null deref + 后续崩溃 | `syscall.c:bpf_prog_get_info_by_fd:5751` | probe_register + scx_rusty + bpftool prog show | **P0** |
| 3 | `tail_call_reachable` 未 swap | `syscall.c:bpf_prog_rejit_swap:3372-3470` | REJIT 改变 tail_call 可达性 | **P0** |
| 4 | `bpf_kinsn_has_native_emit` 未定义 + 缩进 | `verifier.c:23776` + `bpf.h:981` | kinsn non-JIT fallback | **P0** (已修复) |
| 2 | `smp_wmb` 替代 `smp_store_release` | `syscall.c:bpf_prog_rejit_swap:3455-3457` | ARM64 REJIT + 并发 BPF 执行 | **P0** (ARM64) |
| 5 | struct_ops refresh 部分成功不一致 | `bpf_struct_ops.c:bpf_struct_ops_refresh_prog:1561-1577` | REJIT struct_ops + text_poke 失败 | **P1** |
| 6 | swap 遗漏 `arena`, `ctx_arg_info` 等 | `syscall.c:bpf_prog_rejit_swap:3372-3470` | REJIT 使用 arena/ctx_arg_info 的程序 | **P1** |
| 7 | `INIT_LIST_HEAD_RCU` 在 synchronize_rcu 前重用 | `core.c:__bpf_ksym_del:657` | REJIT swap + 并发 kallsyms 遍历 | **P1** |
| 8 | REJIT verifier 历史 bypass (`prog_flags`) | `syscall.c:bpf_prog_rejit:3558` | 已修复，需 regression test | **P1** |
| 9 | swap 后子函数 kallsyms 可能被 tmp free 删除 | `syscall.c:bpf_prog_rejit_swap:3462-3469` | 任何多子函数 REJIT | **P2** |

---

## 与各 crash/failure 的对应关系

### QEMU TCG segfault at `tlb_set_dirty` (probe + scx_rusty + bpftool prog show)

**对应 Bug**: #1 (P0)
**触发路径**: `probe_bpftool_register()` → `scx_rusty` → 重复 `bpftool prog show` → `bpf_prog_get_info_by_fd()` 中访问无效指针 → guest 非法内存访问 → QEMU TCG segfault
**为何 replay 不触发**: replay 是单次精确查询，不涉及 struct_ops 注册/注销竞态
**为何旧基线不触发**: 回归 bug，需 git bisect 定位精确 commit

### `rusty_exit` (prog 20) malformed rewrite 通过 verifier

**对应 Bug**: #8 (P1, 已修复)
**触发路径**: daemon `const_prop` 生成 malformed `LD_IMM64` → REJIT 提交 → 旧版本 verifier 因 `prog_flags` 不完整传递而行为不同 → 放过 malformed code → JIT 执行 → guest crash
**为何当前 replay 拒绝**: `prog_flags` 修复 + daemon 重建后不再生成 malformed output

### `rusty_init_task` / `rusty_exit_task` / `rusty_init` 的 `R2 invalid mem access 'scalar'`

**对应 Bug**: 用户态 daemon rewrite bug（不是内核 bug）
**原因**: daemon 的 `const_prop` pass 将 map-value 指针算术转换为纯 scalar ldimm64，破坏 verifier 的指针类型追踪
**内核行为正确**: verifier 正确拒绝了这些 malformed programs

### `sysctl_monitor` 的 `call to invalid destination`

**对应 Bug**: 用户态 daemon rewrite bug
**原因**: daemon 的变换产生了指向不存在函数的 call 指令
**内核行为正确**: verifier 正确拒绝

### Host kernel stack corruption in `kfree` (pstore evidence)

**可能对应 Bug**: #7 (P1) — `INIT_LIST_HEAD_RCU` 在 `synchronize_rcu` 前重用可能导致 RCU list 遍历腐化；或 #1 的内存访问越界在 KVM 模式下影响 host slab
**替代解释**: 硬件 MCE (5/18 boots 有 MCE 记录)
**需进一步排查**: 启用 KASAN 确认

---

## 建议的修复顺序

1. **立即**: 将 dirty-tree 中的 `bpf_kinsn_has_native_emit()` 和 `null stats guard` commit（Bug #4, #1 部分修复）
2. **本轮修复**: `tail_call_reachable` swap（Bug #3）, `smp_wmb` → `smp_store_release`（Bug #2）
3. **下一轮**: git bisect 定位 QEMU TCG 崩溃的精确回归 commit（Bug #1 完整修复）, struct_ops refresh 部分成功处理（Bug #5）, swap 遗漏字段（Bug #6）
4. **后续**: `INIT_LIST_HEAD_RCU` 时序（Bug #7）, kallsyms 子函数管理（Bug #9）

# REJIT 并行 kallsyms 双重删除 Kernel Panic 根因分析

**日期**: 2026-03-25
**分析基于**: `vendor/linux-framework` commit `9be94921f`（rejit-v2 分支）

---

## 1. 结论

**根因是 `bpf_prog_rejit_swap()` 中的 subprog kallsyms 双重删除，与并发无关。**

在 REJIT 路径中，对于含有 subprogs 的 BPF 程序（`real_func_cnt > 0`），旧 subprogs 的 kallsyms 注册在 swap 阶段被删除一次，然后在 tmp_prog 的 cleanup 阶段被再次删除。第一次 `list_del_rcu()` 将 `lnode.prev` 设为 `LIST_POISON2 = 0xdead000000000122`，第二次删除解引用该毒化指针，触发 GPF。

**这是一个确定性 bug，不是竞争条件。** 每次对含 subprogs 的程序执行 REJIT 都必然触发。之前的测试通过是因为测试程序不含 subprogs（`real_func_cnt == 0`）。并发场景只是增加了"至少一个程序含 subprogs"的概率。

---

## 2. 详细分析

### 2.1 kallsyms 生命周期回顾

BPF 程序的 kallsyms 注册由三个数据结构管理：

| 结构 | 位置 | 说明 |
|------|------|------|
| `prog->aux->ksym.lnode` | 全局链表 `bpf_kallsyms` | 主程序符号 |
| `prog->aux->ksym.tnode` | latch tree `bpf_tree` | 用于地址查找 |
| `prog->aux->func[i]->aux->ksym` | 同上 | subprog 符号 |

关键函数：
- `bpf_ksym_add()`: 在 `bpf_lock` 下插入 lnode + tnode
- `bpf_ksym_del()` → `__bpf_ksym_del()`: 在 `bpf_lock` 下执行 `latch_tree_erase()` + `list_del_rcu()`
- `list_del_rcu()` 将 `lnode.next = LIST_POISON1`, `lnode.prev = LIST_POISON2`

**`__bpf_ksym_del()` 的防护不足**：

```c
// vendor/linux-framework/kernel/bpf/core.c:650
static void __bpf_ksym_del(struct bpf_ksym *ksym)
{
    if (list_empty(&ksym->lnode))   // 检查 lnode.next == &lnode
        return;
    latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
    list_del_rcu(&ksym->lnode);     // 设置 POISON
}
```

`list_empty()` 检查 `head->next == head`。但 `list_del_rcu()` 后 `next = LIST_POISON1 ≠ head`，所以 `list_empty()` 返回 **false**。第二次调用会通过防护，尝试解引用 `lnode.prev = LIST_POISON2 = 0xdead000000000122`。

### 2.2 触发路径逐行追踪

以含 subprogs 的程序为例（`real_func_cnt = N > 0`），追踪 `bpf_prog_rejit()` 的完整路径：

#### 阶段 1: 创建 tmp_prog

```
syscall.c:3636  tmp = bpf_prog_alloc(...)
                → INIT_LIST_HEAD_RCU(&tmp->aux->ksym.lnode)  // 初始化为空
syscall.c:3732  bpf_check(&tmp, ...)
                → verifier.c:23349  bpf_prog_kallsyms_add(func[i])  // i=1..N-1
                   // tmp 的 subprog func[1..N-1] 注册到全局 kallsyms
syscall.c:3737  bpf_prog_select_runtime(tmp, ...)
                → bpf_int_jit_compile(tmp)
                   // 注意：tmp 的主程序 ksym 从未被 add 到 kallsyms
                   // （bpf_prog_load 才会 add 主程序，rejit 不经过该路径）
```

此时状态：
- `prog->aux->func[]` = 旧 subprogs，已注册 kallsyms ✓
- `prog->aux->ksym` = 已注册 kallsyms ✓
- `tmp->aux->func[]` = 新 subprogs，已注册 kallsyms ✓
- `tmp->aux->ksym` = **未注册**（list_head 是空的初始状态）

#### 阶段 2: swap

```
syscall.c:3795  bpf_prog_rejit_swap(prog, tmp)
  ├─ syscall.c:3426  bpf_prog_kallsyms_del_all(prog)    ← 关键！
  │   ├─ bpf_prog_kallsyms_del_subprogs(prog)
  │   │   // 遍历 prog->aux->func[0..N-1]（旧 subprogs）
  │   │   // 对每个调用 bpf_ksym_del() → list_del_rcu()
  │   │   // 旧 subprogs 的 lnode 现在是 LIST_POISON 状态
  │   └─ bpf_prog_kallsyms_del(prog)
  │       // 删除 prog 主程序的 ksym
  │
  ├─ syscall.c:3429  swap(prog->aux->func, tmp->aux->func)
  │   // 现在：prog->aux->func = 新 subprogs
  │   //       tmp->aux->func  = 旧 subprogs（ksym 已是 POISON 状态！）
  │
  └─ syscall.c:3431  swap(prog->aux->real_func_cnt, tmp->aux->real_func_cnt)
      // 现在：tmp->aux->real_func_cnt = prog 原来的 real_func_cnt = N
```

#### 阶段 3: post-swap sync + cleanup

```
syscall.c:3864-3867  synchronize_rcu_expedited()
syscall.c:3876       INIT_LIST_HEAD_RCU(&prog->aux->ksym.lnode)  // 重置主 ksym
syscall.c:3880       bpf_prog_kallsyms_add(prog)  // 重新注册主程序（不含 subprogs）

syscall.c:3890  __bpf_prog_put_noref(tmp, tmp->aux->real_func_cnt > 0)
  └─ syscall.c:2380  bpf_prog_kallsyms_del_all(tmp)
      ├─ bpf_prog_kallsyms_del_subprogs(tmp)
      │   // 遍历 tmp->aux->func[0..N-1]（旧 subprogs！）
      │   // 这些 subprogs 的 ksym 已在阶段 2 被删除（LIST_POISON 状态）
      │   //
      │   // 调用 bpf_ksym_del(&func[i]->aux->ksym)
      │   //   → spin_lock_bh(&bpf_lock)
      │   //   → __bpf_ksym_del(ksym)
      │   //     → list_empty(&ksym->lnode) 返回 false（因为 next = LIST_POISON1 ≠ self）
      │   //     → latch_tree_erase(...)  // 已被 erase，行为未定义
      │   //     → list_del_rcu(&ksym->lnode)
      │   //       → lnode->prev->next = lnode->next
      │   //       → 解引用 lnode->prev = 0xdead000000000122  ← GPF！
      │   //
      └─ bpf_prog_kallsyms_del(tmp)
          // tmp 主 ksym 从未注册，list_empty() 返回 true，安全返回
```

### 2.3 为什么之前的测试没发现

| 测试场景 | 是否含 subprogs | 是否触发 |
|----------|:---:|:---:|
| unit test（单个简单程序 REJIT） | 否（`real_func_cnt=0`） | ✗ |
| rapid kallsyms 20/20（同一程序反复 REJIT） | 否 | ✗ |
| 并发 REJIT 40/40（同一程序 40 次） | 否 | ✗ |
| daemon serve 30 objects | 可能都无 subprogs | ✗ |
| daemon serve 40+ objects | 至少一个有 subprogs | **✓ 必现** |

关键：daemon serve 模式下 REJIT 的是真实 BPF 程序（Tracee、Calico 等），其中一些含有 subprog 调用或 exception handler（hidden subprog）。当 `real_func_cnt > 0` 时，双重删除必然触发。

**与并发无关**：即使串行执行，只要 REJIT 一个含 subprogs 的程序就会 crash。之前的测试巧合地只用了无 subprogs 的简单测试程序。

### 2.4 并发是否有独立的问题？

虽然根因不是并发，但分析代码时发现一个潜在问题：

`bpf_prog_rejit_swap` 中 `bpf_prog_kallsyms_del_all(prog)` 和 post-swap 的 `bpf_prog_kallsyms_add(prog)` 之间有一个窗口期（包含 `synchronize_rcu`），在此期间 `prog` 的 kallsyms 不在全局表中。这不是 bug（符号查找会在 RCU 宽限期后才看到新状态），但值得注意。

另外，`bpf_prog_rejit_swap` 中新 subprogs 的 kallsyms 在 post-swap 后没有被重新注册（只重新注册了主程序）。新 subprogs 保留着 verifier 阶段注册的 kallsyms，指向新 JIT image 的地址。这是正确的——swap 没有改变新 subprogs func[i] 的 ksym 内容，只是改变了 prog->aux->func 指针指向它们。

---

## 3. 修复方案

### 方案 A（根本修复）：swap 后清空旧 subprogs 的 ksym 状态

在 `bpf_prog_rejit_swap` 的 `bpf_prog_kallsyms_del_all(prog)` 之后、`swap(func)` 之前，对旧 subprogs 的 ksym lnode 做 `INIT_LIST_HEAD_RCU` 重置：

```c
// 在 bpf_prog_rejit_swap() 中，bpf_prog_kallsyms_del_all(prog) 之后添加：

/* After deleting old subprog ksyms, reinitialize their list heads
 * so that the subsequent __bpf_prog_put_noref(tmp) cleanup path
 * sees them as "never registered" and skips the delete.
 * Must happen after synchronize_rcu() to ensure no RCU reader
 * still references the old list nodes.
 */
```

但这里有个问题：`INIT_LIST_HEAD_RCU` 需要在 RCU 宽限期之后才能安全执行（`list_del_rcu` 的语义要求在 grace period 结束前保持节点可读）。而 `synchronize_rcu` 在 swap 之后才执行（line 3864-3867）。

**正确的修复位置**：在 `synchronize_rcu` 之后、`__bpf_prog_put_noref(tmp)` 之前，重置 tmp 的旧 subprogs 的 ksym lnode。

```c
// syscall.c, 在 bpf_prog_kallsyms_add(prog) 之后（约 line 3880 之后）添加：

/* The old subprogs (now in tmp->aux->func[]) had their ksyms
 * deleted by bpf_prog_kallsyms_del_all() inside the swap.
 * list_del_rcu() left their lnodes in LIST_POISON state.
 * After the RCU grace period, reinitialize them so that
 * __bpf_prog_put_noref(tmp) → bpf_prog_kallsyms_del_all(tmp)
 * sees empty list heads and skips the double-delete.
 */
for (i = 0; i < tmp->aux->real_func_cnt; i++) {
    INIT_LIST_HEAD_RCU(&tmp->aux->func[i]->aux->ksym.lnode);
#ifdef CONFIG_FINEIBT
    INIT_LIST_HEAD_RCU(&tmp->aux->func[i]->aux->ksym_prefix.lnode);
#endif
}
```

### 方案 B（防御性修复）：加强 `__bpf_ksym_del` 的毒化检查

在 `__bpf_ksym_del` 中除了 `list_empty` 还检查 LIST_POISON：

```c
static void __bpf_ksym_del(struct bpf_ksym *ksym)
{
    if (list_empty(&ksym->lnode))
        return;
    /* Catch double-delete: list_del_rcu sets prev to LIST_POISON2 */
    if (ksym->lnode.prev == LIST_POISON2)
        return;

    latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
    list_del_rcu(&ksym->lnode);
}
```

这是防御性的，能防止 crash 但掩盖了调用方的 bug。

### 方案 C（最简修复）：在 cleanup 前跳过已删除的 subprogs

在 `bpf_prog_rejit` 的 post-swap 清理路径中，不调用 `__bpf_prog_put_noref(tmp)` 而是手动释放 tmp，跳过 kallsyms 清理：

```c
// 替换 line 3890 的 __bpf_prog_put_noref(tmp, ...)
// 直接释放 tmp，跳过 bpf_prog_kallsyms_del_all
bpf_prog_free_deferred(&tmp->aux->rcu);
```

但这需要对 `__bpf_prog_put_noref` 的其他清理逻辑做拆分，较复杂。

### 推荐

**方案 A 是最优修复**。在正确的位置（RCU grace period 之后）重置旧 subprogs 的 ksym 状态，让 cleanup 路径自然安全。改动小（~10 行），语义清晰。

方案 B 可以作为额外的防御层，但不应是唯一修复。

### rollback 路径同样需要修复

`bpf_prog_rejit_rollback()` 也调用 `bpf_prog_rejit_swap(prog, tmp)`（line 3540），同样存在双重删除问题。需要在 rollback 路径的 `synchronize_rcu` 之后也加入相同的 INIT_LIST_HEAD_RCU 逻辑。

---

## 4. Call Trace 与分析的对应

```
GPF at 0xdead000000000122 (LIST_POISON2)
  bpf_ksym_del+0x72/0xa0
    → __bpf_ksym_del() 中 list_del_rcu() 解引用 lnode.prev = LIST_POISON2
  bpf_prog_kallsyms_del_all+0x46/0x80
    → bpf_prog_kallsyms_del_subprogs(tmp) 遍历旧 subprogs
  __bpf_prog_put_noref+0x14/0x120
    → 第一条语句就是 bpf_prog_kallsyms_del_all(prog)
  bpf_prog_rejit+0xce7/0xdb0
    → line 3890: __bpf_prog_put_noref(tmp, ...)
  __sys_bpf+0x58f/0x2660
    → BPF_PROG_REJIT syscall 入口
```

完全吻合。

---

## 5. 验证方法

修复后的验证：

1. **构造含 subprogs 的 BPF 程序做单次 REJIT** — 不修复前应 crash，修复后应 pass
2. **`make vm-static-test TARGET=x86`** — 全量 191 objects
3. **`make vm-corpus`** — 并行 daemon serve
4. **加入 `WARN_ON_ONCE` 检查** — 在 `__bpf_ksym_del` 中加 `WARN_ON_ONCE(ksym->lnode.prev == LIST_POISON2)` 确认修复后不再触发

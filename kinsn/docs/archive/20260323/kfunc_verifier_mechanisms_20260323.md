# BPF Verifier kfunc 机制完整调研

日期：2026-03-23
目标：为 KF_INLINE_EMIT kfunc 实现 "只修改 dst_reg，不 clobber r1-r5，output range 约束" 提供设计依据。

---

## 1. kfunc flag 完整清单

定义位置：`include/linux/btf.h` L18-82

| Flag | Bit | Verifier 行为 | 对寄存器的影响 |
|------|-----|--------------|---------------|
| `KF_ACQUIRE` | 0 | 返回指针带 `ref_obj_id`，必须对应 `release_reference()` | r0 获得 ref，需后续释放 |
| `KF_RELEASE` | 1 | 参数中有 `ref_obj_id` 的指针被释放 | 释放参数 reg 的 ref_obj_id |
| `KF_RET_NULL` | 2 | 返回指针可能为 NULL，加 `PTR_MAYBE_NULL` | r0.type |= PTR_MAYBE_NULL，r0.id = ++id_gen |
| `KF_SLEEPABLE` | 5 | 仅 sleepable prog 可调用，不能在 RCU/preempt-disabled/IRQ-disabled 区内调用 | 无直接寄存器影响 |
| `KF_DESTRUCTIVE` | 6 | 需要 `CAP_SYS_BOOT` | 无直接寄存器影响 |
| `KF_RCU` | 7 | 参数允许 RCU 指针（除 trusted 之外） | 放宽参数指针的验证 |
| `KF_ITER_NEW` | 8 | 迭代器构造函数 | 修改栈上 iter slot |
| `KF_ITER_NEXT` | 9 | 迭代器 next 方法，返回 NULL 时循环结束 | r0 = PTR_TO_BTF_ID, 触发 process_iter_next_call |
| `KF_ITER_DESTROY` | 10 | 迭代器析构函数 | 清理栈上 iter slot |
| `KF_RCU_PROTECTED` | 11 | 必须在 `bpf_rcu_read_lock()` 区内调用 | 返回指针 type |= MEM_RCU |
| `KF_FASTCALL` | 12 | 支持 bpf_fastcall 协议：只 clobber 参数对应的 r1-rN 和（非 void 时的）r0 | **间接影响**：允许 fastcall spill/fill 优化 |
| `KF_ARENA_RET` | 13 | 返回 arena 指针 | r0 标记为 arena 指针 |
| `KF_ARENA_ARG1/2` | 14-15 | 参数是 arena 指针 | 验证参数类型 |
| `KF_IMPLICIT_ARGS` | 16 | verifier 自动注入隐含参数 | 验证时跳过该参数 |
| `KF_INLINE_EMIT` | 17 | **我们的 flag**：JIT 可内联展开为架构指令 | 当前 verifier 无特殊处理（核心问题） |

---

## 2. kfunc 参数声明机制

### 2.1 BTF 签名消费

kfunc 参数类型完全由 BTF（BPF Type Format）签名决定。`check_kfunc_args()` (L13445) 遍历 `btf_param` 数组：

1. **标量参数** (`btf_type_is_scalar`): 验证 reg.type == SCALAR_VALUE
   - `__k` 后缀 → 必须是编译时常量（`tnum_is_const`），存入 `meta->arg_constant`
   - `rdonly_buf_size` / `rdwr_buf_size` → 控制返回指针的 buffer 大小
2. **指针参数** (`btf_type_is_ptr`): 通过 `get_kfunc_ptr_arg_type()` (L12769) 分类

### 2.2 参数后缀约定

位置：`verifier.c` L12346-12389

| 后缀 | 函数 | 语义 |
|------|------|------|
| `__k` | `is_kfunc_arg_constant` | 编译时常量 |
| `__ign` | `is_kfunc_arg_ignore` | verifier 跳过验证 |
| `__map` | `is_kfunc_arg_map` | bpf_map 指针 |
| `__alloc` | `is_kfunc_arg_alloc_obj` | 已分配 BTF 对象 |
| `__uninit` | `is_kfunc_arg_uninit` | 输出参数（未初始化） |
| `__refcounted_kptr` | `is_kfunc_arg_refcounted_kptr` | 引用计数 kptr |
| `__nullable` | `is_kfunc_arg_nullable` | 允许 NULL |
| `__str` | `is_kfunc_arg_const_str` | 常量字符串 |
| `__irq_flag` | `is_kfunc_arg_irq_flag` | IRQ flag |
| `__sz` | `is_kfunc_arg_mem_size` | 指定前一个参数的 mem size |
| `__szk` | `is_kfunc_arg_const_mem_size` | 同上但必须为常量 |

### 2.3 指针参数类型枚举

`get_kfunc_ptr_arg_type()` (L12769) 返回的类型：

```
KF_ARG_PTR_TO_NULL, KF_ARG_PTR_TO_MAP, KF_ARG_PTR_TO_ALLOC_BTF_ID,
KF_ARG_PTR_TO_BTF_ID, KF_ARG_PTR_TO_CTX, KF_ARG_PTR_TO_DYNPTR,
KF_ARG_PTR_TO_ITER, KF_ARG_PTR_TO_LIST_HEAD, KF_ARG_PTR_TO_LIST_NODE,
KF_ARG_PTR_TO_RB_ROOT, KF_ARG_PTR_TO_RB_NODE, KF_ARG_PTR_TO_MEM,
KF_ARG_PTR_TO_MEM_SIZE, KF_ARG_PTR_TO_CALLBACK,
KF_ARG_PTR_TO_REFCOUNTED_KPTR, KF_ARG_PTR_TO_CONST_STR,
KF_ARG_PTR_TO_WORKQUEUE, KF_ARG_PTR_TO_TIMER,
KF_ARG_PTR_TO_TASK_WORK, KF_ARG_PTR_TO_IRQ_FLAG,
KF_ARG_PTR_TO_RES_SPIN_LOCK
```

---

## 3. check_kfunc_call() 完整处理流程

位置：`verifier.c` L14200-14593

```
check_kfunc_call(env, insn, insn_idx_p)
│
├── 1. fetch_kfunc_arg_meta()            -- 查找 BTF 元信息 + kfunc flags
│   ├── fetch_kfunc_meta()               -- 从 btf_kfunc_id_set 查找
│   └── btf_kfunc_is_allowed()           -- 检查 prog_type 是否允许
│
├── 2. 特殊 kfunc 处理
│   ├── bpf_res_spin_lock               -- push_stack + 分叉状态
│   │   └── 分叉状态：clobber r0-r5, mark_reg_unknown(r0), __mark_reg_s32_range(r0, -MAX_ERRNO, -1)
│   └── __bpf_trap                      -- 直接报错
│
├── 3. 权限检查
│   ├── KF_DESTRUCTIVE → CAP_SYS_BOOT
│   ├── KF_SLEEPABLE → 必须 sleepable prog
│   └── non_sleepable 标记
│
├── 4. check_kfunc_args()                -- 参数验证
│   ├── 遍历 BTF param 数组
│   ├── 标量：常量检查、buffer size 检查
│   ├── 指针：get_kfunc_ptr_arg_type → 各类型逐一验证
│   └── release_regno 收集
│
├── 5. 特殊 kfunc 回调注册
│   ├── bpf_rbtree_add → push_callback_call
│   ├── bpf_wq_set_callback → push_callback_call
│   └── task_work_add → push_callback_call
│
├── 6. RCU / preempt / IRQ 锁状态管理
│   ├── rcu_lock → active_rcu_locks++
│   ├── rcu_unlock → active_rcu_locks--, 清除 MEM_RCU
│   ├── preempt_disable/enable → active_preempt_locks ±1
│   └── 嵌套合法性检查
│
├── 7. KF_RELEASE 引用释放
│   ├── dynptr → unmark_stack_slots_dynptr
│   └── 其他 → release_reference
│
├── 8. ★ 寄存器 clobber（核心问题所在）★
│   │
│   │   for (i = 0; i < CALLER_SAVED_REGS; i++) {    // r0-r5 全部
│   │       mark_reg_not_init(env, regs, caller_saved[i]);
│   │       regs[regno].subreg_def = DEF_NOT_SUBREG;
│   │   }
│   │
│   └── 这里无条件 clobber r0-r5，不管 kfunc 实际只用了哪些寄存器
│
├── 9. 返回值类型处理
│   ├── btf_type_is_scalar(t):
│   │   └── mark_reg_unknown(r0) + mark_btf_func_reg_size(r0, t->size)
│   │       对于 bpf_res_spin_lock：__mark_reg_const_zero(r0)
│   ├── btf_type_is_ptr(t):
│   │   ├── check_special_kfunc() — obj_new, refcount_acquire, cast, dynptr_slice 等
│   │   ├── void * → mark_reg_unknown(r0)
│   │   ├── non-struct → PTR_TO_MEM + r0_size
│   │   └── struct → PTR_TO_BTF_ID + PTR_TRUSTED/PTR_UNTRUSTED/MEM_RCU
│   │       + KF_RET_NULL → PTR_MAYBE_NULL
│   │       + KF_ACQUIRE → acquire_reference
│   ├── btf_type_is_void(t):
│   │   └── 仅处理 obj_drop
│   └── mark_btf_func_reg_size(r0, size)
│
├── 10. pkt_changing → clear_all_pkt_pointers
│
├── 11. 参数 reg_size 标记
│   └── 遍历参数，mark_btf_func_reg_size
│
└── 12. iter_next 处理 → process_iter_next_call
```

**关键观察**：第 8 步是核心瓶颈——无条件 clobber 全部 r0-r5。

---

## 4. 返回值 range 约束的先例

### 4.1 Helper: do_refine_retval_range()

位置：`verifier.c` L11418-11454

这是 **helper** 调用后细化返回值范围的唯一入口。当前仅处理几个特殊 helper：

```c
switch (func_id) {
case BPF_FUNC_get_stack:
case BPF_FUNC_get_task_stack:
case BPF_FUNC_probe_read_str:
case BPF_FUNC_probe_read_kernel_str:
case BPF_FUNC_probe_read_user_str:
    ret_reg->smax_value = meta->msize_max_value;
    ret_reg->smin_value = -MAX_ERRNO;
    reg_bounds_sync(ret_reg);
    break;
case BPF_FUNC_get_smp_processor_id:
    ret_reg->umax_value = nr_cpu_ids - 1;
    ret_reg->umin_value = 0;
    reg_bounds_sync(ret_reg);
    break;
}
```

**关键**：这证明 verifier 完全有能力对函数返回值做 range narrowing，只是目前 kfunc 路径没有这个机制。

### 4.2 kfunc: bpf_res_spin_lock 的 s32 range

位置：`check_kfunc_call()` L14248

```c
err = __mark_reg_s32_range(env, regs, BPF_REG_0, -MAX_ERRNO, -1);
```

这是 kfunc 路径中**唯一一个**对返回值做 range 约束的先例，但它是硬编码在 `check_kfunc_call()` 中的特殊处理。

### 4.3 kfunc 标量返回的通用路径

```c
if (btf_type_is_scalar(t)) {
    mark_reg_unknown(env, regs, BPF_REG_0);  // 64-bit unbounded
    mark_btf_func_reg_size(env, BPF_REG_0, t->size);
}
```

`mark_reg_unknown` 将 r0 设为完全未知的 `SCALAR_VALUE`（tnum_unknown, unbounded min/max）。没有任何 range narrowing。

---

## 5. 寄存器 clobber 的现有机制分析

### 5.1 当前 kfunc clobber 行为

`check_kfunc_call()` L14432-14437:

```c
for (i = 0; i < CALLER_SAVED_REGS; i++) {
    u32 regno = caller_saved[i];
    mark_reg_not_init(env, regs, regno);   // type = NOT_INIT
    regs[regno].subreg_def = DEF_NOT_SUBREG;
}
```

**无条件 clobber r0-r5**，然后根据返回类型重新设置 r0。

### 5.2 Helper clobber 行为

`check_helper_call()` L12036-12040:

```c
for (i = 0; i < CALLER_SAVED_REGS; i++) {
    mark_reg_not_init(env, regs, caller_saved[i]);
    check_reg_arg(env, caller_saved[i], DST_OP_NO_MARK);
}
```

同样无条件 clobber。

### 5.3 有没有已有机制让 kfunc 声明只修改某些寄存器？

**答案：没有。** verifier 内部没有任何机制让 kfunc（或 helper）声明"我只修改 r0，不碰 r1-r5"。所有函数调用都走 BPF ABI 的 caller-saved 约定。

但是，存在一个**间接**机制：`bpf_fastcall`（见下一节）。

---

## 6. bpf_fastcall 机制完整分析

### 6.1 概述

`bpf_fastcall` 是一个 **LLVM attribute + kernel verifier** 协作机制，定义在：
- `include/linux/btf.h` L77: `KF_FASTCALL (1 << 12)`
- `include/linux/bpf.h` L934: `bool allow_fastcall` (helper 的对应字段)
- `verifier.c` L18471-18630: 完整实现

### 6.2 工作原理

bpf_fastcall 的核心思想是：如果一个函数只 clobber 部分 caller-saved 寄存器（由参数数量决定），那么 clang 在编译时就可以不保存/恢复那些未被 clobber 的寄存器。

**但这不是在 verifier 层面做的**——verifier 仍然 clobber 全部 r0-r5。bpf_fastcall 的优化发生在**指令层面**：

1. **clang 侧**：
   - 编译时，将 call 前后的 spill/fill 指令对（保存/恢复不被 clobber 的寄存器）按特定格式排列
   - 使用函数最低栈偏移存放这些 spill

2. **verifier 侧** (`mark_fastcall_patterns()` L18632):
   - 扫描所有 CALL 指令
   - 对每个 call，调用 `get_call_summary()` 获取 `num_params` 和 `is_void`
   - 计算 `clobbered_regs_mask = GENMASK(num_params, is_void ? 1 : 0)`
   - `expected_regs_mask = ~clobbered_regs_mask & ALL_CALLER_SAVED_REGS`
   - 匹配 call 前后的 spill/fill 对
   - 标记 `fastcall_pattern` 和 `fastcall_spills_num`

3. **后处理** (`remove_fastcall_spills_fills()` L24566):
   - 如果 fastcall 条件满足（栈区域仅被 fastcall pattern 使用），将 spill/fill 替换为 NOP
   - NOP 后续被 `opt_remove_nops()` 清除

### 6.3 kfunc 的 KF_FASTCALL 支持

在 `get_call_summary()` L18455-18466:

```c
if (bpf_pseudo_kfunc_call(call)) {
    cs->num_params = btf_type_vlen(meta.func_proto);
    cs->fastcall = meta.kfunc_flags & KF_FASTCALL;
    cs->is_void = btf_type_is_void(...);
    return true;
}
```

**关键**：KF_FASTCALL 仅控制是否移除 spill/fill，**不影响 verifier 的寄存器状态追踪**。verifier 仍然认为 r0-r5 全部被 clobber。

### 6.4 bpf_fastcall 对 KF_INLINE_EMIT 的意义

**KF_FASTCALL 不能替代我们需要的机制**：
- KF_FASTCALL：运行时消除多余的 spill/fill NOP 指令
- 我们需要的：verifier 层面告知 "r1-r5 不被修改"，这样后续指令可以继续使用这些寄存器的值

但 KF_FASTCALL 的实现给了我们重要启示：**kernel 已经有"区分不同寄存器 clobber 集合"的概念**（`clobbered_regs_mask`），只是目前仅用于指令优化，不用于 verifier 状态追踪。

---

## 7. fixup_kfunc_call() 分析

位置：`verifier.c` L23294-23433

`fixup_kfunc_call()` 在 `do_misc_fixups()` 中被调用，发生在 verification **之后**、JIT **之前**。

### 处理流程：

1. **查找 kfunc descriptor**: `find_kfunc_desc()` → 获取 addr
2. **设置 imm**: 将 btf func_id 替换为 `BPF_CALL_IMM(desc->addr)`（相对偏移）
3. **特殊 kfunc fixup**:
   - `bpf_obj_new` / `bpf_percpu_obj_new`: 注入 r1=size, r2=struct_meta 参数
   - `bpf_obj_drop` / `bpf_refcount_acquire`: 注入 r2=struct_meta
   - `bpf_list_push_*` / `bpf_rbtree_add`: 注入 struct_meta + node_offset
   - `bpf_cast_to_kern_ctx` / `bpf_rdonly_cast`: 替换为 `mov r0, r1`
   - `bpf_session_is_return`: 内联为 3 条指令
   - `bpf_session_cookie`: 内联为 6 条指令
4. **arg_prog fixup**: 如果有 `__prog_aux` 参数，注入 `prog->aux` 地址

### KF_INLINE_EMIT 的 fixup 路径

KF_INLINE_EMIT 的内联 **不在** `fixup_kfunc_call()` 中发生。它在 kfunc descriptor 构建时记录 `inline_ops`：

```c
desc->inline_ops = kfunc.flags && (*kfunc.flags & KF_INLINE_EMIT) ?
    bpf_kfunc_inline_lookup(kfunc.name) : NULL;
```

实际内联发生在**JIT 阶段**，由架构 JIT 代码查询 `bpf_jit_find_kfunc_inline_ops()` 后调用 `emit_x86()/emit_arm64()` 回调。

---

## 8. kfunc 返回值精度追踪能力

### 8.1 当前 kfunc 标量返回值的追踪状态

当 kfunc 返回标量时：
```c
mark_reg_unknown(env, regs, BPF_REG_0);  // r0: SCALAR_VALUE, tnum_unknown
mark_btf_func_reg_size(env, BPF_REG_0, t->size);  // 如果 size < 8, 设置 subreg_def
```

`mark_reg_unknown` 设置：
- type = SCALAR_VALUE
- var_off = tnum_unknown  (所有 64 位都是未知)
- smin = S64_MIN, smax = S64_MAX
- umin = 0, umax = U64_MAX
- s32_min = S32_MIN, s32_max = S32_MAX
- u32_min = 0, u32_max = U32_MAX

### 8.2 现有的 range 约束 API

verifier 提供了完整的 range 约束工具：

| 函数 | 功能 |
|------|------|
| `__mark_reg_s32_range(env, regs, reg, min, max)` | 设置 s32 范围 + sync |
| `reg_bounds_sync(reg)` | 根据已知范围推导其他约束 |
| `___mark_reg_known(reg, imm)` | 设置为已知常量 |
| `__mark_reg_known(reg, imm)` | 同上 + precise 标记 |
| `mark_reg_known_zero(env, regs, reg)` | 设为 0 |
| `__mark_reg_const_zero(env, reg)` | 设为 const 0 |

可以直接使用这些 API 对 r0 做 range narrowing。

---

## 9. 对 KF_INLINE_EMIT 的建议：最小改动方案

### 9.1 需要解决的两个问题

1. **寄存器 clobber**: 当前无条件 clobber r0-r5，但 kinsn 只修改 r0（或 r0+某些临时寄存器）
2. **返回值 range**: 当前标量返回值为 unbounded，但 kinsn 的输出有明确范围（如 extract 的输出 ∈ [0, 2^len-1]）

### 9.2 方案分析

#### 问题 1：减少 clobber — 复用 bpf_fastcall

**推荐方案：KF_INLINE_EMIT 隐含 KF_FASTCALL 语义**

理由：
1. KF_FASTCALL 已经有 `get_call_summary()` 中基于参数数量计算 clobber mask 的逻辑
2. kinsn 实际上只写入 r0，不修改 r1-rN（因为它直接 emit 机器码操作 x86 寄存器）
3. 但仅靠 KF_FASTCALL 不够——它只影响 spill/fill 消除，**不改变 verifier 的寄存器状态**

**真正的最小改动**：在 `check_kfunc_call()` 的第 8 步中，对 KF_INLINE_EMIT 做条件处理：

```c
// verifier.c check_kfunc_call(), 替换 L14432-14437 的无条件 clobber
if (is_kfunc_inline_emit(&meta)) {
    // KF_INLINE_EMIT: only clobber r0, preserve r1-r5
    mark_reg_not_init(env, regs, BPF_REG_0);
    regs[BPF_REG_0].subreg_def = DEF_NOT_SUBREG;
} else {
    for (i = 0; i < CALLER_SAVED_REGS; i++) {
        mark_reg_not_init(env, regs, caller_saved[i]);
        regs[caller_saved[i]].subreg_def = DEF_NOT_SUBREG;
    }
}
```

**改动量**：~10 行 verifier.c + 1 个 `is_kfunc_inline_emit()` 辅助函数。

**安全性论证**：
- KF_INLINE_EMIT 的 emit 回调只在 `dst_reg`(r0) 中写入结果
- 参数寄存器 r1-rN 是输入，emit 回调不应该修改它们（这是 kinsn 的契约）
- 如果某个 kinsn 违反这个契约（修改了 r1-r5），那是 module 的 bug，不是 verifier 的问题

**替代方案**：给 `bpf_kfunc_inline_ops` 加一个 `clobber_mask` 字段，让 module 声明自己 clobber 哪些寄存器。更灵活但改动更大。

#### 问题 2：返回值 range 约束

**推荐方案：在 `check_kfunc_call()` 中对 KF_INLINE_EMIT 的标量返回值做特殊处理**

两个子方案：

**方案 A：基于 BTF 返回类型 size（零改动 kfunc 签名）**

如果 kfunc 返回类型是 u32（而非 u64），verifier 已经通过 `mark_btf_func_reg_size()` 设置 `subreg_def`。但这只影响零扩展，不影响 range。

增加一步：对于返回 u32 的 KF_INLINE_EMIT kfunc，自动设置 `umax = U32_MAX`:
```c
if (is_kfunc_inline_emit(&meta) && btf_type_is_scalar(t)) {
    mark_reg_unknown(env, regs, BPF_REG_0);
    if (t->size <= 4) {
        regs[BPF_REG_0].umax_value = U32_MAX;
        regs[BPF_REG_0].u32_max_value = U32_MAX;
        reg_bounds_sync(&regs[BPF_REG_0]);
    }
    mark_btf_func_reg_size(env, BPF_REG_0, t->size);
}
```

这已经比现在好（u32 返回自动限制到 32 位范围），但对 extract(start,len) 这样输出范围更窄的场景不够。

**方案 B：给 inline_ops 加 range 回调（最灵活）**

在 `bpf_kfunc_inline_ops` 中新增一个可选回调：

```c
struct bpf_kfunc_inline_ops {
    int (*emit_x86)(...);
    int (*emit_arm64)(...);
    int max_emit_bytes;
    /* NEW: optional range declaration for return value */
    /* Returns true if range was set, false to use default (unknown) */
    bool (*get_retval_range)(const struct bpf_insn *insn,
                             u64 *umin, u64 *umax);
};
```

然后在 `check_kfunc_call()` 中调用：
```c
if (is_kfunc_inline_emit(&meta) && btf_type_is_scalar(t)) {
    mark_reg_unknown(env, regs, BPF_REG_0);
    // ...获取 insn_aux 中的 inline_ops...
    if (ops && ops->get_retval_range) {
        u64 umin, umax;
        if (ops->get_retval_range(insn, &umin, &umax)) {
            regs[BPF_REG_0].umin_value = umin;
            regs[BPF_REG_0].umax_value = umax;
            reg_bounds_sync(&regs[BPF_REG_0]);
        }
    }
}
```

**问题**：verifier 在 `check_kfunc_call` 阶段没有直接访问 `inline_ops`，因为 `inline_ops` 存在 `bpf_kfunc_desc` 中，而 `check_kfunc_call` 使用的是 `bpf_kfunc_call_arg_meta`。需要把 `inline_ops` 或 range 信息传递过来。

**方案 C：基于参数常量推导（不需要新回调）**

对于 `bpf_extract64(val, start, len)` 这样的场景，`start` 和 `len` 如果是常量（`__k` 后缀），verifier 在参数检查阶段已经知道它们的值。可以利用这些信息直接推导 range：

```c
// extract: output ∈ [0, (1 << len) - 1]
if (meta->arg_constant.found) {
    u64 len = meta->arg_constant.value;
    if (len < 64) {
        regs[BPF_REG_0].umax_value = (1ULL << len) - 1;
        reg_bounds_sync(&regs[BPF_REG_0]);
    }
}
```

但这需要在 `check_kfunc_call` 中对每个具体 kinsn 做特殊处理，不够通用。

### 9.3 推荐的最小改动集

**Step 1**: 在 `btf.h` 中让 KF_INLINE_EMIT 隐含 "只 clobber r0" 语义：
- 修改 `check_kfunc_call()` L14432-14437，对 KF_INLINE_EMIT 只 clobber r0

**Step 2**: 给 `bpf_kfunc_inline_ops` 加一个可选的 `u64 output_umax` 字段（默认 0 表示 unbounded）：
- 模块侧：`extract_ops.output_umax = (1ULL << 64) - 1`（默认无约束）或具体值
- 但 extract 的 output_umax 依赖运行时参数，不适合静态声明

**Step 3（推荐）**: 基于 BTF 返回类型自动推导 range：
- `u32` 返回 → `umax = U32_MAX`
- `u16` 返回 → `umax = 65535`
- `u8`  返回 → `umax = 255`
- 这覆盖了大部分场景，且零额外 API

---

## 10. 可直接复用的现有机制

| 机制 | 代码位置 | 复用方式 |
|------|---------|---------|
| `mark_reg_unknown()` | L2881 | 对 r0 设置 SCALAR_VALUE |
| `reg_bounds_sync()` | L2763 | range 约束后同步所有 bounds |
| `__mark_reg_s32_range()` | L2894 | 直接设置 s32 range（bpf_res_spin_lock 先例） |
| `mark_btf_func_reg_size()` | L12284 | 基于 BTF 类型 size 设置 subreg_def |
| `is_kfunc_*()` 辅助函数模式 | L12290-12318 | 新增 `is_kfunc_inline_emit()` |
| KF_FASTCALL 的 `clobbered_regs_mask` 计算 | L18567 | 理念可复用 |
| `do_refine_retval_range()` 模式 | L11418 | helper 的 range narrowing 模式可照搬到 kfunc |
| `bpf_kfunc_call_arg_meta.kfunc_flags` | L313 | 已在 meta 中，直接检查 KF_INLINE_EMIT |

---

## 11. 需要新增的内容

| 内容 | 改动量 | 位置 |
|------|-------|------|
| `is_kfunc_inline_emit()` 函数 | 5 行 | verifier.c（跟其他 is_kfunc_* 函数放一起） |
| check_kfunc_call 中的条件 clobber | ~10 行 | verifier.c L14432 区域 |
| KF_INLINE_EMIT 返回值 range 处理 | ~15 行 | verifier.c, 在 L14453 btf_type_is_scalar 分支中 |
| （可选）bpf_kfunc_inline_ops 加 range 字段 | ~5 行 | bpf.h |
| （可选）module 侧声明 output range | ~3 行/模块 | module/x86/*.c |

**总内核改动量估计：25-35 行**

---

## 12. 安全性分析

### 12.1 只 clobber r0 的安全性

**前提条件**：KF_INLINE_EMIT kfunc 的 emit 回调必须保证只修改 dst_reg(rax)，不修改 r1-r5 对应的 x86 寄存器（rdi, rsi, rdx, rcx, r8）。

**验证**：
- `bpf_rotate64(val, shift)` → 使用 rdi, rsi, rcx 作为临时，但结果写入 rax。**问题**：它修改了 rcx（mov rcx, rsi），这对应 BPF_REG_4（不是参数寄存器，因为 BPF_REG_4 = r8 on x86）。等一下——BPF 到 x86 的映射：
  - BPF_REG_0 = RAX
  - BPF_REG_1 = RDI
  - BPF_REG_2 = RSI
  - BPF_REG_3 = RDX
  - BPF_REG_4 = R9（不是 RCX!）
  - BPF_REG_5 = R8
  - RCX 不对应任何 BPF 寄存器（它是 x86 JIT 内部使用的辅助寄存器，即 AUX_REG）

  **所以 rotate 的 `mov rcx, rsi` 修改的是 x86 的 AUX_REG，不影响任何 BPF 寄存器。** ✓

- `bpf_select64(a, b, cond)` → 使用 rsi, rdi, rdx 作为只读输入，写入 rax。不修改任何 BPF 输入寄存器。 ✓

- `bpf_extract64(val, start, len)` → 修改 eax（BPF_REG_0），使用 edx, esi, rdi 作为输入。中间步骤修改 eax 但最终结果也在 rax。 ✓

**结论**：现有的 3 个 kinsn 都满足 "只修改 r0" 的契约。

### 12.2 两步保守实现

如果担心第三方模块违反契约，可以：

1. 在注册 inline_ops 时加文档声明："emit 回调必须只修改 dst_reg(rax/x0)，不得修改 r1-r5 对应的架构寄存器"
2. 如果要更保守，可以只保留"未使用的参数寄存器"而非全部 r1-r5。对于 `f(a,b)` 类型的 kfunc，可以保留 r3-r5。这与 KF_FASTCALL 的 `clobbered_regs_mask` 逻辑完全一致。

---

## 13. 总结

### 可以直接复用的

1. **`is_kfunc_*()` 模式** → 新增 `is_kfunc_inline_emit()`
2. **`do_refine_retval_range()` 模式** → 照搬到 kfunc 返回值处理
3. **`__mark_reg_s32_range()` / `reg_bounds_sync()`** → 直接设置 range
4. **`mark_btf_func_reg_size()`** → 已有基于 BTF type size 的 subreg 处理
5. **KF_FASTCALL 的 clobber mask 概念** → 理念复用（但实现不同）

### 需要新增的

1. **verifier 条件 clobber**：在 `check_kfunc_call()` 中对 KF_INLINE_EMIT 只 clobber r0
2. **返回值 range**：至少基于 BTF 返回类型 size 做自动 narrowing；理想状态是让 module 可以声明 range

### 最小可行改动

**约 25-35 行内核代码**：
- `verifier.c`: is_kfunc_inline_emit() + 条件 clobber + 基于 type size 的 range
- 无需修改 BTF、bpf.h 或 inline_ops 结构体
- 无需修改 JIT 代码
- 无需修改 module 侧代码

### 风险

1. **契约违反**：如果 kinsn 的 emit 回调偷改了 r1-r5 对应的寄存器，verifier 不会检测到 → 可能导致 BPF 程序行为不正确。但这与 helper inline（`verifier_inlines_helper_call`）是同样的信任模型。
2. **向后兼容**：KF_INLINE_EMIT 是新 flag，没有向后兼容问题。
3. **与 bpf_fastcall 交互**：KF_INLINE_EMIT + KF_FASTCALL 同时存在是合理的——fastcall 消除多余 spill/fill，inline_emit 的条件 clobber 让 verifier 知道不需要 spill/fill。两者互补。

# struct_ops REJIT 支持方案调研

日期：2026-03-22

## 1. 问题本质

当前 `bpf_prog_rejit_supported()`（`syscall.c:3159`）拒绝 `st_ops_assoc` 不为 NULL 的程序：

```c
if (aux->poke_tab || aux->size_poke_tab ||
    rcu_access_pointer(aux->st_ops_assoc))
    return false;
```

原因注释已经写明：
> TODO: st_ops_assoc trampolines bake bpf_func into a direct call;
> need trampoline rebuild to support REJIT for struct_ops progs.

## 2. struct_ops trampoline 构建流程

### 2.1 入口：`bpf_struct_ops_map_update_elem()`

文件：`kernel/bpf/bpf_struct_ops.c:686`

流程：
1. 遍历 struct 的每个 func 成员（`for_each_member(i, t, member)`）
2. 通过 `prog_fd` 拿到 `bpf_prog`
3. 调用 `bpf_prog_assoc_struct_ops(prog, &st_map->map)` —— 设置 `prog->aux->st_ops_assoc`
4. 创建 `bpf_tramp_link`，初始化为 `BPF_LINK_TYPE_STRUCT_OPS`
5. **关键行** (line 835):
   ```c
   err = bpf_struct_ops_prepare_trampoline(tlinks, link,
       &st_ops->func_models[i],
       *(void **)(st_ops->cfi_stubs + moff),
       &image, &image_off, allow_alloc);
   ```
6. **关键行** (line 849):
   ```c
   *(void **)(kdata + moff) = image + trampoline_start + cfi_get_offset();
   ```
   将 trampoline 入口地址写入内核结构体的函数指针槽位

### 2.2 trampoline 生成：`bpf_struct_ops_prepare_trampoline()`

文件：`kernel/bpf/bpf_struct_ops.c:597`

关键参数：
- `tlinks` — 只放了一个 FENTRY link
- `link` — 包含 `link->link.prog` 即目标 BPF 程序
- `model` — BTF 函数模型
- `stub_func` — CFI stub 地址（indirect call 目标）
- `image/image_off` — 输出 trampoline 代码的位置

内部调用 `arch_prepare_bpf_trampoline(NULL, ...)` —— 注意第一个参数 `im` 为 NULL（不是 `bpf_tramp_image`，因为 struct_ops 不用标准 trampoline image 管理）。

### 2.3 x86 trampoline 代码生成

文件：`arch/x86/net/bpf_jit_comp.c:3236`（`__arch_prepare_bpf_trampoline`）

flags = `BPF_TRAMP_F_INDIRECT | BPF_TRAMP_F_RET_FENTRY_RET`

trampoline 代码结构：
1. CFI prefix（`emit_cfi`，因为 `BPF_TRAMP_F_INDIRECT`）
2. `push rbp; mov rbp, rsp; sub rsp, stack_size`
3. 保存参数到栈
4. 调用 `__bpf_prog_enter*`
5. **关键：`emit_rsb_call(&prog, p->bpf_func, ...)`** (line 3051)
   - 生成 `0xE8 <rel32>` CALL 指令
   - 目标是 `p->bpf_func`（绝对地址被编码为相对偏移）
6. 调用 `__bpf_prog_exit*`
7. return

**`bpf_func` 就是在 step 5 被硬编码进 trampoline image 的。**

### 2.4 image 保护

trampoline image 由 `bpf_struct_ops_image_alloc()` 分配（实际是 `arch_alloc_bpf_trampoline` → `bpf_prog_pack_alloc`），之后调用 `arch_protect_bpf_trampoline()`。在 x86 上 `arch_protect_bpf_trampoline()` 是空操作（return 0），因为 prog_pack 本身已经是 RX 的，写入通过 text_poke 机制。

### 2.5 ksym 注册

每个 trampoline 都注册了 ksym（`bpf_image_ksym_add`），所以 `is_bpf_text_address()` 对 trampoline 地址返回 true。这是 `bpf_arch_text_poke()` 能工作的前提。

## 3. 从 prog 反查 struct_ops map/member

### 3.1 `prog->aux->st_ops_assoc`

指向 `bpf_map`（实际是 `bpf_struct_ops_map`）。通过 `container_of` 或强制转换可以拿到完整的 `st_map`。

### 3.2 member index

`prog->expected_attach_type` 存储的就是 BTF member index `i`（见 line 808 和 824）。

### 3.3 反查路径

```
prog->aux->st_ops_assoc → st_map (bpf_struct_ops_map)
prog->expected_attach_type → member index i
st_map->links[func_idx] → bpf_link（但 func_idx 不等于 member index i，需要额外映射）
st_map->image_pages[] → trampoline image pages
```

**注意**：`links[]` 数组的索引是 funcs_cnt（紧凑排列的函数指针索引），不是 BTF member index。member index 包含非函数成员（如 module owner 等），而 links 只存函数成员。需要遍历或建立映射表。

## 4. 三种可行方案

### 方案 A：text_poke 替换 CALL target（最简）

**原理**：REJIT 后 `prog->bpf_func` 已更新。只需找到 trampoline 中 `CALL old_bpf_func` 指令的位置，用 `bpf_arch_text_poke()` 将其改为 `CALL new_bpf_func`。

**可行性分析**：

- `bpf_arch_text_poke(ip, BPF_MOD_CALL, BPF_MOD_CALL, old_addr, new_addr)` 是成熟的内核基础设施
- 已被 `bpf_trampoline_refresh_prog()` 用于 freplace 场景（line 940-943）
- struct_ops trampoline image 在 bpf prog_pack 中，`is_bpf_text_address()` 返回 true ✓
- x86 上 `arch_protect_bpf_trampoline()` 是空操作，不阻止 text_poke ✓

**难点**：定位 CALL 指令的 IP 地址。trampoline 内部的 call 偏移取决于：
- 参数数量、类型（struct arg 展开）
- CFI prefix 大小
- call depth accounting（IBT/retpoline）
- stack layout

没有现成的方法记录"call bpf_func 在 image 中的偏移"。

**解决思路**：在 `bpf_struct_ops_prepare_trampoline()` 或 `__arch_prepare_bpf_trampoline()` 中，记录 call 指令的偏移。可以：

1. 在 `bpf_tramp_link` 或 `bpf_struct_ops_map` 中新增 `call_site_off` 字段
2. 修改 `arch_prepare_bpf_trampoline` 在 emit CALL 时记录偏移（通过 `im` 结构或新参数）
3. 或者：直接扫描 trampoline image 找 `0xE8` + 匹配 old_addr 的 CALL（简单但 hacky）

**推荐方法 A1：扫描法**

trampoline 很短（通常 100-300 字节），且 struct_ops 每个 trampoline 只有一个 BPF 程序调用。可以安全地扫描 image 找到唯一的 `CALL old_bpf_func` 指令：

```c
// 伪代码
static void *find_call_site(void *image, u32 image_size, void *target) {
    u8 *p;
    for (p = image; p < (u8 *)image + image_size - 5; p++) {
        if (*p == 0xE8) {
            s32 disp = *(s32 *)(p + 1);
            void *call_target = (void *)(p + 5 + disp);
            if (call_target == target)
                return p;
        }
    }
    return NULL;
}
```

但这样太 hacky。**推荐方法 A2：记录 offset**。

### 方案 B：重建整个 trampoline image

**原理**：REJIT 后，重新调用 `bpf_struct_ops_prepare_trampoline()` 重新生成 trampoline，然后用 `text_poke_copy` 替换整个 image。

**可行性分析**：

这就是 `bpf_trampoline_update()` 对 fentry/fexit/fmod_ret 做的事情。但 struct_ops 有几个不同：

1. struct_ops 不使用 `bpf_tramp_image` 管理，没有 `im->image` / `im->iphdr` / `im->ip_after_call`
2. 多个 trampoline 可能共享一个 image page（紧凑排列）
3. 重建需要：unprotect image → overwrite → re-protect → update function pointer → synchronize_rcu

**复杂度**：中等。需要 ~60-80 行，但要处理 image page 共享和 CFI。

### 方案 C：使用 indirect call（不修改 trampoline）

**原理**：让 trampoline 不直接 call `bpf_func`，而是通过 `prog->bpf_func` 间接调用。

**可行性**：改变了整个 struct_ops trampoline 的调用约定，影响面太大，不考虑。而且会引入性能开销（多一次内存访问 + indirect branch），破坏了 struct_ops trampoline 的设计初衷。

**结论：不推荐。**

## 5. 推荐方案：A（text_poke）+ 记录 offset

### 5.1 需要改的文件

1. **`kernel/bpf/bpf_struct_ops.c`** (~30 行)
   - 新增 `bpf_struct_ops_refresh_prog()` 函数
   - 从 `prog->aux->st_ops_assoc` 拿到 `st_map`
   - 遍历 `st_map->links[]` 找到匹配的 link（`link->prog == prog`）
   - 调用 `bpf_arch_text_poke(call_site, BPF_MOD_CALL, BPF_MOD_CALL, old_bpf_func, new_bpf_func)`

2. **`kernel/bpf/syscall.c`** (~5 行)
   - 在 `bpf_prog_rejit_supported()` 中移除 `st_ops_assoc` 检查
   - 在 REJIT swap 之后调用 `bpf_struct_ops_refresh_prog()`

3. **`include/linux/bpf.h`** (~2 行)
   - 声明 `bpf_struct_ops_refresh_prog()`

4. **call site offset 记录**（两种子方案）：

   **A2a：在 link 中记录 offset**（~10 行）
   - 在 `bpf_struct_ops_map` 中新增 `u32 *call_offsets` 数组
   - 在 `bpf_struct_ops_prepare_trampoline()` 返回后计算并存储 call offset
   - 问题：需要知道 trampoline 内部 call 的精确位置

   **A2b：利用 `bpf_arch_text_poke` 的 old_addr 匹配**（0 行额外）
   - `bpf_arch_text_poke` 本身就会验证 old_insn 匹配
   - 只需找到 CALL 指令的 IP，但这回到了扫描问题

   **A2c：扫描法但受限范围**（~15 行）
   - 从 `st_map->ksyms[func_idx]` 拿到 trampoline 的起始地址和大小
   - 在 `ksym->start` 到 `ksym->start + ksym->end - ksym->start` 范围内扫描 `0xE8`
   - struct_ops trampoline 只有一个 CALL bpf_func，误匹配概率极低（`__bpf_prog_enter/__exit` 也是 CALL 但目标不同）
   - 用 old_bpf_func 验证可以完全消除误匹配

### 5.2 最简实现：A + A2c（扫描法）

总改动量：~50 行

```
kernel/bpf/bpf_struct_ops.c:  +35 行 (bpf_struct_ops_refresh_prog)
kernel/bpf/syscall.c:          +8 行 (移除限制 + 调用 refresh)
include/linux/bpf.h:           +2 行 (声明)
```

### 5.3 锁序分析

REJIT 流程持有 `prog->aux->rejit_mutex`。struct_ops refresh 需要：
- 读 `st_ops_assoc`：需要 `st_ops_assoc_mutex` 或 RCU read lock
- 调用 `bpf_arch_text_poke`：需要 `text_mutex`（内部获取）

锁序：`rejit_mutex` → `st_ops_assoc_mutex` → `text_mutex`。与现有锁序不冲突（`st_ops_assoc_mutex` 是 per-prog 的，没有与 `rejit_mutex` 的嵌套关系）。

### 5.4 安全风险

1. **竞态**：REJIT 和 struct_ops unregister 可能并发。`st_ops_assoc` 可能在 REJIT 期间变为 NULL 或 POISON。需要在 `rejit_mutex` 下检查。风险：低，已有 RCU 保护。

2. **text_poke 原子性**：`smp_text_poke_single` 保证 5 字节 CALL 的原子更新。其他 CPU 要么看到旧地址要么看到新地址，不会看到中间状态。风险：无。

3. **struct_ops 状态**：如果 struct_ops map 已经注册到内核子系统（如 tcp_congestion_ops），trampoline 正在被内核调用。text_poke 期间的安全性由 `text_poke_bp` 机制保证（int3-based）。风险：无。

4. **多 map 共用同一 prog**：`bpf_prog_assoc_struct_ops` 允许一个 prog 只关联到一个 map（第二次调用会 POISON）。所以最多只有一个 st_ops trampoline 需要 patch。风险：无。

5. **image page 已释放**：如果 struct_ops map 已经 free，image 也被释放。但此时 `st_ops_assoc` 已经被 disassoc（变为 NULL），不会进入 refresh 逻辑。风险：无。

## 6. 结论

### 值不值得做？

**值得做，但优先级中等偏低。**

理由：
- struct_ops 是 BPF 社区的重要方向（sched_ext、tcp_congestion_ops、HID-BPF 等）
- 工作量很小：~50 行内核代码
- 安全风险低：复用成熟的 text_poke 基础设施
- 但当前 benchmark 和论文不涉及 struct_ops 场景，不是 OSDI deadline 前的必做项

### 最简方案总结

1. 新增 `bpf_struct_ops_refresh_prog(prog, old_bpf_func)`:
   - 取 `st_ops_assoc` → `st_map`
   - 遍历 `st_map->links[]`，找 `link->prog == prog`
   - 从对应 `ksym` 拿到 trampoline 范围
   - 扫描找到 `CALL old_bpf_func` 的 IP
   - 调用 `bpf_arch_text_poke(ip, CALL, CALL, old, new)`

2. 在 `bpf_prog_rejit_supported()` 中移除 `st_ops_assoc` 限制

3. 在 REJIT swap 后调用 `bpf_struct_ops_refresh_prog()`

4. 约 50 行改动，3 个文件，无新的锁依赖

### 潜在后续工作

- ARM64 支持需要类似的 call site 定位逻辑（BL 指令扫描）
- 如果 struct_ops 支持多程序（future），需要扩展扫描逻辑
- 可考虑在 trampoline 生成时记录 call offset，避免运行时扫描

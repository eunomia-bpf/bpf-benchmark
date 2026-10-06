# Tail Call (poke_tab) REJIT 支持调研

**日期**: 2026-03-22
**状态**: 调研完成
**相关**: #339（poke_tab 是最后一个 REJIT limitation）

## 1. poke_tab 机制完整分析

### 1.1 数据结构

```c
// include/linux/bpf.h:1619
struct bpf_jit_poke_descriptor {
    void *tailcall_target;       // JIT image 中 direct jump 的目标地址
    void *tailcall_bypass;       // JIT image 中 bypass jump 的地址
    void *bypass_addr;           // bypass 跳转的目标（= tailcall_target + 5）
    void *aux;                   // 拥有此 poke entry 的 subprog 的 aux（NULL = main prog）
    union {
        struct {
            struct bpf_map *map; // PROG_ARRAY map 指针
            u32 key;             // map 中的 index
        } tail_call;
    };
    bool tailcall_target_stable; // JIT fixup 完成后设为 true
    u8 adj_off;                  // X86_TAIL_CALL_OFFSET（跳过 prologue）
    u16 reason;                  // BPF_POKE_REASON_TAIL_CALL
    u32 insn_idx;                // 对应的 BPF insn index
};
```

```c
// include/linux/bpf.h:1845
struct bpf_array_aux {
    struct list_head poke_progs;  // 所有引用此 PROG_ARRAY 的 prog aux 链表
    struct bpf_map *map;
    struct mutex poke_mutex;      // 保护 poke_progs 和 text_poke 操作
    struct work_struct work;
};
```

`bpf_prog_aux` 中:
- `poke_tab`: 指向 `bpf_jit_poke_descriptor` 数组（krealloc 动态增长）
- `size_poke_tab`: poke 条目数（上限 1024）

### 1.2 生命周期

**创建时**（verifier `convert_ctx_accesses` 阶段）:
1. 遇到 `BPF_TAIL_CALL` 指令，如果 map 和 key 已知（直接 tail call）
2. 调用 `bpf_jit_add_poke_descriptor(prog, &desc)` 将 poke entry 添加到 `poke_tab`
3. 修改 insn 的 `imm` 为 `slot + 1`（非零表示 direct tail call）

**JIT 阶段**（`do_jit` in `bpf_jit_comp.c`）:
1. `emit_bpf_tail_call_direct()`: 生成 bypass jump (jae out) + nop (5B placeholder) + out label
2. 将 `poke->tailcall_target`, `poke->tailcall_bypass`, `poke->bypass_addr`, `poke->adj_off` 填入实际 JIT image 地址

**JIT 完成后** (`bpf_tail_call_direct_fixup()`):
1. 遍历所有 poke entries
2. 如果 target prog 已存在于 map，用 `__bpf_arch_text_poke` 将 nop 改为 jmp
3. 设置 `poke->tailcall_target_stable = true`

**注册 tracking**（verifier finalize 阶段 `fixup_call_args`）:
1. 遍历所有 poke entries
2. 调用 `map->ops->map_poke_track(map, prog->aux)` 将 prog->aux 注册到 `bpf_array_aux->poke_progs` 链表

**map 更新时**（`bpf_fd_array_map_update_elem` / `fd_array_map_delete_elem`）:
1. 持有 `poke_mutex`
2. 调用 `prog_array_map_poke_run(map, key, old_prog, new_prog)`
3. 遍历 `poke_progs` 链表 → 遍历每个 aux 的 `poke_tab`
4. 对匹配的 entry 调用 `bpf_arch_poke_desc_update(poke, new, old)` 进行 text_poke

**prog 释放时**:
1. `bpf_free_used_maps()` → `map_poke_untrack(map, aux)` 从链表移除
2. subprog 的 `poke_tab = NULL`（因为共享主 prog 的 poke_tab）
3. `__bpf_prog_free()` → `kfree(aux->poke_tab)`

### 1.3 关键不变量

- **poke_tab 归主 prog 所有**。subprog 的 `aux->poke_tab` 指向主 prog 的同一份数组，只是 `poke->aux` 标记了具体属于哪个 subprog。
- **poke entries 包含 JIT image 内的绝对地址**（`tailcall_target`, `tailcall_bypass`, `bypass_addr`）。
- **map 侧通过 `poke_progs` 链表索引所有引用者**，链表元素是 `prog_poke_elem { list, aux }`。
- **所有 text_poke 操作持有 `bpf_array_aux->poke_mutex`**。

## 2. 两个子问题分析

### 2.A. Caller 侧: prog 自身调用 tail_call（有 poke_tab）被 REJIT

**场景**: prog P 有 N 个 direct tail_call 到不同 PROG_ARRAY entries。P 被 REJIT → 新 JIT image 有新的 poke entries（地址不同）。

**需要做什么**:

1. **tmp prog 正常经过 verifier**：verifier 会为 tmp 创建新的 `poke_tab`（N 条新 entries），并通过 `map_poke_track()` 把 tmp->aux 注册到各 PROG_ARRAY 的 `poke_progs`。
   - **问题**: 目前 `bpf_prog_rejit_supported()` 在第二次检查 tmp 时也会拒绝（因为 tmp 也有 poke_tab）。

2. **在 swap 之前**，需要让旧的 poke entries 失效：
   - 对每个旧 poke entry，锁住对应 `bpf_array_aux->poke_mutex`
   - 设置 `poke->tailcall_target_stable = false`（阻止后续 map 更新 patch 旧地址）
   - 从所有相关 PROG_ARRAY 的 `poke_progs` 链表中移除旧 aux

3. **在 swap 之后**：
   - 新的 poke_tab 已经 swap 到 prog->aux（`bpf_prog_rejit_swap` 需要新增 `swap(poke_tab, size_poke_tab)`）
   - 新的 poke entries 的 `tailcall_target` 等地址指向新 JIT image（正确的）
   - 但 `poke_progs` 链表中注册的是 **tmp->aux**，需要替换为 **prog->aux**
   - 调用 `bpf_tail_call_direct_fixup(prog)` 做最终 fixup（将 nop 改为实际 jmp）

4. **释放 tmp 时**：
   - tmp->aux 现在持有旧的 poke_tab（swap 后）
   - `__bpf_prog_free` → `kfree(tmp->aux->poke_tab)` 释放旧 poke_tab
   - `bpf_free_used_maps(tmp->aux)` 会对旧 used_maps 调用 `map_poke_untrack(map, tmp->aux)` —— 但 tmp->aux 已经不在链表中了（步骤 2 已移除），所以是 no-op

**方案 A 的详细步骤**:

```
bpf_prog_rejit():
    // 放宽 check: 允许 poke_tab
    // tmp 正常 verify + JIT (会建立自己的 poke_tab + track)

    // --- swap 前准备 ---
    // 对 prog->aux 的每个 poke map:
    //   lock poke_mutex
    //   设置旧 poke->tailcall_target_stable = false
    //   map_poke_untrack(map, prog->aux)
    //   unlock poke_mutex

    // --- swap poke_tab ---
    swap(prog->aux->poke_tab, tmp->aux->poke_tab)
    swap(prog->aux->size_poke_tab, tmp->aux->size_poke_tab)

    // --- 修复 poke_progs 链表中的 aux 指针 ---
    // 对 prog->aux 的每个新 poke map:
    //   lock poke_mutex
    //   在 poke_progs 链表中把 tmp->aux 替换为 prog->aux
    //   bpf_tail_call_direct_fixup 风格的 text_poke
    //   设置 poke->tailcall_target_stable = true
    //   unlock poke_mutex

    // --- 正常继续 ---
    bpf_prog_rejit_swap(prog, tmp)  // swap 其他字段
    synchronize_rcu()
    free tmp
```

**但有一个微妙问题**: `poke_progs` 链表中的元素是 `prog_poke_elem { list, aux }`，是 `prog_array_map_poke_track` 分配的 kmalloc 对象。要把 `elem->aux = tmp->aux` 改成 `elem->aux = prog->aux`，需要在持有 `poke_mutex` 的情况下遍历链表。

**实际上更简单的做法**: 不做 swap poke_tab，而是**重用旧的 poke_tab + 更新地址**：
- 新旧 prog 引用的 PROG_ARRAY map + key 是一样的（语义不变）
- 只需要更新 `tailcall_target`, `tailcall_bypass`, `bypass_addr` 到新 JIT image 的对应位置
- 这样 `poke_progs` 链表不需要改，prog->aux 一直在链表中

**但这要求新旧 poke_tab 条目数量和顺序完全一致**。如果 REJIT 后的新 bytecode 有不同数量的 tail_call，这个假设就不成立。

**最简方案**: **要求 REJIT 后 tail_call 数量和 map+key 完全一致**（与旧 prog 相同的 tail_call pattern）。这是合理的，因为 daemon 的 rewrite pass 不应改变控制流结构。

### 2.B. Target 侧: prog 是 tail_call 的 target（在某个 PROG_ARRAY map 中）

**场景**: prog T 被 REJIT → `bpf_func` 地址改变。其他 prog 的 poke entries 中 `tailcall_target` 指向 T 的旧 `bpf_func + adj_off`。

**分析**: 这个情况**自动被现有机制处理**！

理由:
1. `bpf_prog_rejit_swap()` 最后做 `WRITE_ONCE(prog->bpf_func, tmp->bpf_func)` —— 更新了 prog 的 `bpf_func` 到新 JIT image。
2. **indirect tail call** (`emit_bpf_tail_call_indirect`)：运行时从 `array->ptrs[index]->bpf_func` 读取，每次都是最新值。`bpf_func` 的更新通过 `smp_wmb()` + `WRITE_ONCE` 保证可见性。所以 **indirect tail call 自动看到新地址**。
3. **direct tail call** (`emit_bpf_tail_call_direct`)：JIT image 中是 hardcoded jump 地址。这些是通过 `bpf_arch_poke_desc_update(poke, new, old)` 更新的。当 PROG_ARRAY map 被更新时才调用。**但 REJIT 不更新 map，所以不会触发 poke_run**。

**关键问题**: direct tail call 的 callers 在 JIT image 中已经 baked in 了旧的 `target->bpf_func + adj_off`。REJIT 更新了 target 的 `bpf_func`，但 **没有人通知 callers 更新它们的 direct jump**。

**解决方案**: REJIT target 后，需要模拟一次 "map 更新" 来 patch 所有 callers:
1. 找到 target 在哪些 PROG_ARRAY map 的哪些 slot
2. 对每个 (map, key)，调用等价于 `prog_array_map_poke_run(map, key, old_prog, new_prog)` —— 但这里 old 和 new 是同一个 prog（只是 bpf_func 变了）

**问题**: 没有从 prog → "我在哪些 PROG_ARRAY 的哪些 slot" 的反向索引。

**`aux->used_maps` 能不能用？** 不能直接用。`used_maps` 记录的是 prog 使用的 map（即 prog 自己 tail_call 出去的 map），不是 "哪些 map 持有 prog 作为 target"。

**可选方案**:

**B1: 扫描所有 poke_progs 链表** (O(M*N), M=map数, N=poke总数)
- 遍历所有 PROG_ARRAY map → 遍历 poke_progs → 检查 poke entries 中 target 是否匹配
- 需要 `bpf_map_idr` 或类似全局索引
- 太重，不可接受

**B2: 不支持 direct tail call target REJIT**
- 只做方案 A（caller 侧）
- Target 侧只影响 direct tail call 的 callers
- **Indirect tail call 自动工作**（运行时读 bpf_func）

**B3: 利用 PROG_ARRAY map 做一次 xchg**
- 对 target 所在的每个 (map, key)，做一次 `xchg(array->ptrs[key], same_prog)`
- 这会触发 `map_poke_run(map, key, old_prog=T, new_prog=T)`
- 但 `bpf_arch_poke_desc_update` 看到 old==new，old_addr == new_addr，text_poke 会跳过
- **不行**: 因为 bpf_func 已经变了，所以 old_addr（基于旧 bpf_func）≠ new_addr（基于新 bpf_func）
- 等等... `bpf_arch_poke_desc_update` 计算 `old_addr = old->bpf_func + adj_off`，`new_addr = new->bpf_func + adj_off`。但 old 和 new 是同一个 prog 对象，且 bpf_func 已经更新，所以 old_addr == new_addr。**不行。**

**B4: 自定义 refresh 函数**
```c
void bpf_prog_rejit_refresh_tail_call_target(struct bpf_prog *prog,
                                              bpf_func_t old_bpf_func)
{
    // 遍历 prog->aux->used_maps 找到 PROG_ARRAY maps
    // 对每个 PROG_ARRAY map:
    //   lock poke_mutex
    //   遍历 poke_progs 链表中每个 elem
    //     遍历 elem->aux->poke_tab
    //       if poke->tail_call.map == map && array->ptrs[poke->tail_call.key] == prog:
    //         text_poke tailcall_target: old_bpf_func+adj -> prog->bpf_func+adj
    //   unlock poke_mutex
}
```

**但 `prog->aux->used_maps` 记录的是 prog 自己使用的 map，不是 "持有 prog 的 map"。**

**获取 "哪些 map 持有 prog"**:
- 没有现成的反向索引
- 可以扫描 `bpf_map_idr` 中所有 BPF_MAP_TYPE_PROG_ARRAY 的 map → 检查 `array->ptrs[i] == prog`
- 或者新增反向索引（prog → maps_holding_me），但这是侵入式改动

**实际上**: 在 Cilium 的使用模式中，tail_call target 通常是在加载时通过 `bpf_prog_array_set_prog()` 设置一次，之后很少更新。如果 target 被 REJIT，只需要扫描相关的 PROG_ARRAY maps。

**最简方案 B**: 不在内核做反向索引扫描。而是由 **daemon（用户态）** 负责：
1. Daemon 知道 PROG_ARRAY map fd 和 prog fd
2. REJIT target 后，daemon 对相关 PROG_ARRAY slot 做一次 `bpf_map_update_elem(map_fd, &key, &same_prog_fd, BPF_ANY)`
3. 这触发 `bpf_fd_array_map_update_elem` → `prog_array_map_poke_run` → 所有 callers 的 direct jump 被 patch
4. 内核零额外代码

## 3. 工作量估计

### 方案 A (Caller 侧: prog 有 poke_tab)

**最简实现: poke_tab 就地更新（要求 tail_call pattern 不变）**

修改点:
1. `bpf_prog_rejit_supported()`: 移除 `poke_tab || size_poke_tab` check (**-2 行**)
2. `bpf_prog_rejit_swap()`: 新增 poke_tab 地址更新逻辑 (**~40-60 行**)
   - 遍历旧 poke_tab，设 `tailcall_target_stable = false`
   - 校验新旧 poke_tab size 一致、map+key 一致
   - 将新 poke entries 的地址字段（tailcall_target/bypass/bypass_addr）复制到旧 poke entries
   - 对每个 poke entry: 持 poke_mutex → text_poke 更新 direct jump → 设 stable = true → 释 mutex
   - **不 swap poke_tab**（prog->aux 的 poke_tab 保持不变，poke_progs 链表不需改）
3. 释放 tmp 的 poke_tab: tmp 的 poke_tab 需要 untrack 后释放 (**~10 行**)
   - tmp 经 verifier 后已被 track，需要在 swap 前 untrack
4. 处理 tmp 的 poke_tab 被 verifier track 的问题 (**~15 行**)

**总计: ~65-85 行新代码**

**更通用实现: 允许 tail_call pattern 改变**

如果 REJIT 后的 bytecode 可以有不同的 tail_call 数量/目标（不太合理但更通用）:
- 需要 untrack 旧 poke_tab → swap → re-track 新 poke_tab
- 需要处理 `poke_progs` 链表中 aux 指针替换
- **~120-150 行**
- **不推荐**: 增加复杂度，daemon rewrite 不应改变 tail_call 结构

### 方案 B (Target 侧: prog 在 PROG_ARRAY 中)

**用户态方案 (推荐): 0 行内核代码**

Daemon 负责在 REJIT target 后对相关 PROG_ARRAY slot 做一次 update-in-place:
```python
# daemon pseudo-code
for map_fd, key in prog_array_entries[prog_fd]:
    bpf_map_update_elem(map_fd, key, prog_fd, BPF_EXIST)
```
- 这触发 `prog_array_map_poke_run` 自动 patch 所有 callers
- 需要 daemon 维护 (prog → PROG_ARRAY slots) 映射，从 bpffs 或 bpftool 获取

**内核方案: ~30-50 行**

新增 `bpf_prog_rejit_refresh_tail_call_targets(prog, old_bpf_func)`:
- 扫描 `bpf_map_idr` 中所有 PROG_ARRAY maps
- 对每个 map 检查 `ptrs[i] == prog`
- 触发 poke_run
- 需要 `bpf_map_idr` 读锁（`rcu_read_lock` + `idr_for_each`）
- **侵入式**: 需要导出 `bpf_map_idr` 或新增 helper

### 安全风险

**方案 A**:
- **text_poke 竞态**: 在 `tailcall_target_stable = false` 和新地址 patch 完成之间，如果 map 更新触发 poke_run，stable=false 的 entry 会被跳过 → 安全（运行时走 nop → bypass → 跳过 tail_call → 正常返回）
- **旧 JIT image 正在执行**: `synchronize_rcu()` 保证旧 image 不再被执行后才释放 → 安全
- **subprog poke_tab 共享**: 需要确保 subprog 的 `aux->poke_tab` 指针也更新 → 不 swap 而是就地更新，所以 subprog 的指针自动有效

**方案 B (用户态)**:
- 零内核风险
- 用户态竞态: 如果在 REJIT 和 map update 之间有 caller 执行 direct tail_call，会跳到旧地址。但旧 JIT image 在 `synchronize_rcu()` 前不会被释放 → 安全

**需要新的锁吗？**
- 不需要。所有操作都在已有的 `poke_mutex` 和 `rejit_mutex` 保护下。
- 方案 A 需要注意锁序: `rejit_mutex` → `poke_mutex`（与现有的 verifier finalize 锁序一致）。

## 4. Cilium tail_call 使用模式

### 实际数据（corpus 中的 BPF objects）

| 项目 | Object | tail_call 数量 |
|---|---|---|
| **Cilium** | bpf_lxc.bpf.o | **129** |
| **Cilium** | bpf_overlay.bpf.o | **58** |
| **Cilium** | bpf_xdp.bpf.o | **29** |
| **Tetragon** | bpf_generic_kprobe.bpf.o | 20 |
| **Tetragon** | bpf_generic_uprobe.bpf.o | 20 |
| **Tetragon** | bpf_generic_rawtp.bpf.o | 16 |
| **Tracee** | tracee.bpf.o | **49** |
| **Calico** | from_hep_debug.bpf.o | 13 |
| **Calico** | to_hep/to_nat/from_nat | 5-10 each |
| **Katran** | xdp_root.o | 3 |
| **Loxilb** | llb_ebpf_main.bpf.o | 17 |
| **SCX** | scx_lavd_main.bpf.o | 18 |
| **SCX** | scx_flash_main.bpf.o | 16 |
| **OpenTelemetry** | native_stack_trace.bpf.o | 4 |

### Cilium 架构

Cilium 使用 **tail_call chaining** 作为核心架构模式:
- **Entry prog** (tc/entry 或 xdp/entry): 初始化 ctx_state，然后 tail_call 到具体处理函数
- **Tail progs** (tc/tail 或 xdp/tail): 每个功能模块一个 tail prog（如 ARP、IPv4、IPv6、L7、NAT、CT 等）
- **PROG_ARRAY map**: `cilium_calls_*` map，加载时一次性填充所有 tail progs
- **模式**: entry → tail_call(main_handler) → tail_call(conntrack) → tail_call(nat) → tail_call(l3) → ...

**bpf_lxc.bpf.o 的结构**:
- sections: `.text` (共享函数), `tc/tail` (tail call targets), `tc/entry` (入口)
- entry prog 和 tail progs **都会调用 tail_call**（chain pattern）
- entry prog 和 tail progs **也都是 tail_call 的 target**

**影响评估**:
- Cilium 的所有 entry prog 和 tail prog 都有 `poke_tab`（因为都调用 `bpf_tail_call`）
- 同时它们也都是 PROG_ARRAY 的 target
- 不支持 poke_tab REJIT = **Cilium 100% 不可用**
- 支持方案 A = **entry prog 可以 REJIT**（它们自己调用 tail_call）
- 支持方案 A + B = **完整支持**

## 5. 推荐方案

### Phase 1: 方案 A（Caller 侧），~75 行内核代码

**实现**: 就地更新 poke_tab 地址（要求 tail_call pattern 不变）

步骤:
1. `bpf_prog_rejit_supported()`: 删除 poke_tab check
2. REJIT 路径在 swap 前: untrack tmp 的 poke entries（tmp 被 verifier track 了）
3. REJIT 路径在 swap 后: 就地更新 prog 的 poke entries 地址字段 + text_poke fixup
4. 新增校验: 新旧 poke_tab 的 size/map/key 必须完全匹配

**效果**: 解锁所有 **自身调用 tail_call** 的 prog 的 REJIT。覆盖 Cilium entry prog 和 tail prog 的 caller 侧。

### Phase 2: 方案 B（Target 侧），0 行内核代码

**实现**: daemon 在 REJIT 后对相关 PROG_ARRAY slot 做 update-in-place

步骤:
1. Daemon 从 bpftool/bpffs 获取 prog → PROG_ARRAY slots 映射
2. REJIT 成功后，对每个相关 slot 做 `bpf_map_update_elem`
3. 这自动触发 poke_run → patch 所有 callers 的 direct jump

**效果**: 完整解锁 tail_call 场景。Cilium, Tetragon, Tracee, Calico 等全部可用。

### 总工作量

| 阶段 | 内核代码 | 用户态代码 | 风险 |
|---|---|---|---|
| Phase 1 (方案 A) | ~75 行 | 0 | 低（已有 poke_mutex 保护） |
| Phase 2 (方案 B) | 0 | ~50 行 daemon | 极低（利用已有 map update 路径） |
| **合计** | **~75 行** | **~50 行** | **低** |

## 6. 结论

**值得做**: 是。tail_call 是 eBPF 生态中最关键的控制流机制。Cilium（129 tail_calls in bpf_lxc）、Tetragon、Tracee、Calico、Katran、SCX 全部依赖 tail_call。不解除这个限制，BpfReJIT 的 real-world 覆盖率会很低。

**最简方案**: Phase 1 (~75 行内核) + Phase 2 (~50 行 daemon)。

**建议优先级**: 高。这是 OSDI 论文 evaluation 中 "real-world workload coverage" 的关键指标。

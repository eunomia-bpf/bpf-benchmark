# BpfReJIT 内核 Patch 最终裁决

> 审计对象：`kernel_vs_upstream_diff.patch`（2935 行）
> 裁决日期：2026-03-26
> 审计角色：Linux 内核 BPF 子系统维护者最终裁决
> 对比输入：
>   - Opus 报告：`kernel_review_opus_final_20260325.md`
>   - Codex 报告：`kernel_review_codex_final_20260325.md`
> 方法：逐条对照实际代码（非仅 diff），给出最终结论

---

## 一、Codex 报告 CRITICAL/HIGH 问题裁决

### Codex-1 [HIGH] `do_misc_fixups()` 对 kinsn proof sequence 使用固定 32 指令缓冲区，缺少上界检查

**裁决：✅ 确认存在**

代码位置：`verifier.c:23767-23768`

```c
cnt = kinsn->instantiate_insn(bpf_kinsn_sidecar_payload(insn),
                              env->insn_buf);
```

`env->insn_buf` 定义在 `bpf_verifier.h:27` 为 `struct bpf_insn insn_buf[INSN_BUF_SIZE]`，`INSN_BUF_SIZE = 32`。如果 kinsn 描述符的 `max_insn_cnt > 32`，`instantiate_insn()` 回调会越界写入 `env->insn_buf`。虽然 `validate_kinsn_proof_seq()` 在写入后检查 `cnt <= kinsn->max_insn_cnt`，但写入已经发生。

**修复方案**：在 `do_misc_fixups` 中 kinsn 分支入口添加：
```c
if (kinsn->max_insn_cnt > INSN_BUF_SIZE)
    return -E2BIG;
```
或者改为使用 `lower_kinsn_proof_regions()` 中已有的 `kvcalloc(kinsn->max_insn_cnt, ...)` 模式进行动态分配。

---

### Codex-2 [HIGH] kinsn-only 程序不再强制 `jit_needed=true`，JIT 失败后可能错误回退到 interpreter

**裁决：⚠️ 部分正确**

代码位置：`core.c:2531-2533`, `verifier.c:23634-23644`, `verifier.c:23446-23453`

分析：
- `bpf_prog_has_kfunc_call()` 确实排除了 kinsn 描述符（只返回 `!tab->descs[i].kinsn` 的条目为 true）。
- 因此 `bpf_prog_select_runtime()` 中 `jit_needed` 不会因 kinsn 而被置位。
- 但是 `fixup_call_args()` 在 `#ifndef CONFIG_BPF_JIT_ALWAYS_ON` 路径中已经显式检查 `has_kinsn_call` 并拒绝。

风险限定：
- 对 `CONFIG_BPF_JIT_ALWAYS_ON=y` 的配置（现代发行版几乎全部如此），`jit_needed` 始终为 true，不受影响。
- 对 `CONFIG_BPF_JIT_ALWAYS_ON=n` 的配置，`fixup_call_args()` 先于 `bpf_prog_select_runtime()` 运行，会拒绝带 kinsn 的非 JIT 程序。但对**多子程序**情况，如果 `jit_subprogs()` 先成功，单独的主程序 JIT 在 `bpf_prog_select_runtime()` 中失败，kinsn pseudo-insn 在 `do_misc_fixups` 中被保留（因为 `jit_requested && native_emit`），此时确实会回退到 interpreter 看到无法识别的指令。

**结论**：在 `!CONFIG_BPF_JIT_ALWAYS_ON` 配置下确实存在理论风险。修复方案：让 `bpf_prog_has_kfunc_call()` 或新函数 `bpf_prog_has_kinsn_call()` 也参与 `jit_needed` 判断。

---

### Codex-3 [HIGH] REJIT swap 漏掉了 `has_callchain_buf`，会打破 `bpf_get_stack*()` 的资源生命周期

**裁决：✅ 确认存在**

代码位置：`syscall.c:3372-3487`（`bpf_prog_rejit_swap`）

验证：
- `SWAP_PROG_BITFIELD` 列表中包含 `call_get_stack` 但**不包含** `has_callchain_buf`。
- `has_callchain_buf` 在 verifier (`verifier.c:12441`) 中设置在 `env->prog`（即 `tmp`）上。
- `__bpf_prog_free_deferred` -> `bpf_prog_free_deferred`（`core.c:2926`）根据 `aux->prog->has_callchain_buf` 决定是否 `put_callchain_buffers()`。

场景：
1. 旧 prog 不调 `bpf_get_stack()`（`has_callchain_buf=0`），新 tmp 调了（`has_callchain_buf=1`）。
2. swap 后，prog 仍然 `has_callchain_buf=0`，tmp 带着 `has_callchain_buf=1` 被释放。
3. 释放 tmp 时执行 `put_callchain_buffers()`，但 prog 在后续释放时不会再 put。
4. 结果：引用计数正确（get 1 次 put 1 次），但资源所有权挂在了被释放的 tmp 而非存活的 prog 上。

反方向更严重：旧 prog 有 `has_callchain_buf=1`，新 tmp 没有。swap 后 prog 仍为 1，但 tmp 为 0，tmp 释放时不 put；prog 最终释放时会 double put（如果 prog 的 `has_callchain_buf` 仍为 1）。

**修复方案**：在 `SWAP_PROG_BITFIELD` 列表中添加 `has_callchain_buf`。

---

### Codex-4 [HIGH] REJIT 没有完整重放 load-time metadata，却把 live program 的 BTF/func_info/line_info 直接 swap 掉了

**裁决：⚠️ 部分正确**

代码位置：`syscall.c:3394-3401`（swap btf/func_info/linfo），`syscall.c:3694-3723`（EXT 程序预填充）

分析：
- 对 EXT (freplace) 程序，代码在 REJIT 前已显式复制 `btf`、`func_info`、`func_info_aux`（`syscall.c:3694-3723`）。
- 对非 EXT 程序，如果 REJIT 的新 bytecode 不需要 BTF（用户未传入 `prog_btf_fd`），`tmp->aux->btf` 为 NULL。swap 后 prog 的 btf 变为 NULL，旧 btf 随 tmp 释放。
- `line_info` 和 `jited_linfo` 同理会被清空。

**影响确认**：非 EXT 程序的 REJIT 确实会丢失 BTF、func_info、line_info。这会导致 `bpftool prog dump` 和 `BPF_OBJ_GET_INFO_BY_FD` 返回的信息退化。但由于 REJIT 替换了 bytecode，旧的 BTF/line_info 本身就不再对应新代码，所以丢失是**语义上合理的**。

**结论**：这不是 bug，而是 UAPI 设计选择。但 codex 报告指出的"静默降级"确实是一个 UX 问题。应在 UAPI 文档中明确说明 REJIT 后 BTF/line_info 状态，或者将相关字段从 swap 中排除（只 swap JIT 相关字段，保留原 prog 的 metadata）。

---

### Codex-5 [HIGH] rollback 用裸 `memcpy()` 恢复 `poke_tab`，会和并发的 `map_poke_run()` 发生数据竞争

**裁决：⚠️ 部分正确，但严重度低于 HIGH**

代码位置：`syscall.c:3541-3544`

```c
if (saved_poke_tab && prog->aux->poke_tab &&
    prog->aux->size_poke_tab == saved_poke_cnt)
    memcpy(prog->aux->poke_tab, saved_poke_tab,
           saved_poke_cnt * sizeof(*saved_poke_tab));
```

分析：
- rollback 在 `rejit_mutex` 保护下执行。
- 但 `map_poke_run()` 由 prog_array map 更新触发，持有的是 `array->aux->poke_mutex`，不是 `rejit_mutex`。
- 因此 rollback 的 `memcpy` 与并发的 `map_poke_run()` 确实可以同时访问 `poke_tab` 条目。

缓解因素：
- rollback 路径极少触发（只有当 trampoline/struct_ops refresh 失败时）。
- 正向路径 `bpf_prog_rejit_update_poke_tab()` 正确使用了 per-map `poke_mutex`。
- rollback 的 `memcpy` 在两个 `bpf_prog_rejit_poke_target_phase` 调用之间执行，此时 poke entries 的 `tailcall_target_stable` 状态不确定。

**修复方案**：rollback 应复用正向路径的锁模式，逐条恢复 poke entry 并持有对应 `poke_mutex`。

---

### Codex-6 [MEDIUM] 每个程序永久保存一份 `orig_insns`，把大程序的指令内存直接翻倍

**裁决：✅ 确认存在**

代码位置：`syscall.c:3029-3038`

所有 `BPF_PROG_LOAD` 无条件 `kvmemdup` 一份原始指令。这是一个设计问题而非正确性 bug。

**修复方案**：改为 lazy allocation 或 opt-in flag。

---

### Codex-7 [LOW] `rejit_scx_debug_prog()` 是调试残留

**裁决：✅ 确认存在**

代码位置：`syscall.c:5597-5605` 及 ~8 处调用点

`pr_info` + `%px` 打印内核地址，必须在提交前删除。

---

### Codex-8 [MEDIUM] unlink 失败时仍然删除 `trampoline_users` 反向索引

**裁决：✅ 确认存在**

代码位置：`trampoline.c:912-921`

```c
err = __bpf_trampoline_unlink_prog(link, tr, tgt_prog);
list_for_each_entry_safe(tu, tmp, ...) {
    if (tu->tr == tr) {
        list_del(&tu->list);
        kfree(tu);
        break;
    }
}
```

无论 `err` 是否为 0，都会删除反向索引。如果 `__bpf_trampoline_unlink_prog` 内部的 `bpf_trampoline_update()` 失败，trampoline 仍然挂着旧的 prog 代码，但反向索引已删除。后续 REJIT 的 `bpf_trampoline_refresh_prog()` 会跳过这个 trampoline。

但注意：`bpf_trampoline_unlink_prog` 的注释说 "should never fail"，且上层调用者 `bpf_shim_tramp_link_release` 也有 `WARN_ON_ONCE` 包裹。所以这更多是一个防御性问题。

**修复方案**：只在 `err == 0` 时删除反向索引。

---

## 二、Opus 报告 CRITICAL/HIGH 问题裁决

### Opus-3.1 [CRITICAL] `smp_load_acquire` 在 `__bpf_prog_run` 热路径引入全局可见的性能影响

**裁决：⚠️ 部分正确，但严重度应为 MEDIUM 而非 CRITICAL**

代码位置：`filter.h:707`

分析：
- 在 x86 上，`smp_load_acquire` 编译为普通 load（TSO 保证），零额外开销。
- 在 ARM64 上，`smp_load_acquire` 编译为 `ldar`，比 `ldr` 多一个 acquire barrier。
- ARM64 `ldar` 的额外延迟在现代 micro-architecture 上通常 <1ns（非 contested cache line）。

降级理由：
- x86（BPF 主要部署平台）无影响。
- ARM64 上的影响需要实际基准测试量化，不能仅凭理论断定为 CRITICAL。
- `smp_load_acquire` / `smp_store_release` 是 REJIT 原子发布新 `bpf_func` 的正确做法；替代方案（如 `rcu_dereference` + `synchronize_rcu`）会引入更大的 REJIT 延迟。

**建议**：保留当前方案，在 ARM64 上进行 XDP/tc 热路径基准测试。如果确认有显著影响，可以考虑 `READ_ONCE` + REJIT 侧 `synchronize_rcu()` 的方案。

---

### Opus-4.1 [CRITICAL] `bpf_prog_rejit_swap` 中 `memcpy(prog->insnsi, tmp->insnsi, ...)` 可能越界写入

**裁决：❌ 误报**

代码位置：`syscall.c:3476`, `syscall.c:3746`

分析：
- `bpf_prog` 使用 `__vmalloc` 分配，大小为 `bpf_prog_alloc_size(bpf_prog_size(len))`，向上对齐到页。
- `prog->pages = size / PAGE_SIZE`，所以 `prog->pages * PAGE_SIZE` 就是精确的 vmalloc 分配大小。
- 检查 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE` 确保 `tmp` 的 insns 不会写出 `prog` 的 vmalloc 分配边界。
- vmalloc 分配是页对齐的，不存在 slab 相邻对象问题。

Opus 建议的 `bpf_prog_size(tmp->len) > bpf_prog_size(prog->len)` 过于严格——原始分配包含的 padding 空间完全可用。

---

### Opus-4.2 [CRITICAL] `retain_old_image = true` 导致 `tmp` 程序永久泄漏

**裁决：⚠️ 部分正确，严重度为 MEDIUM**

代码位置：`syscall.c:3888-3892`

这是有意的设计决策：当 rollback 的 rollback 也失败时，为防止 UAF（trampoline 仍引用旧 image），选择泄漏而非崩溃。

问题在于：
1. 泄漏不可恢复，不可监控。
2. 没有计数器暴露给用户空间。

但这是极端边界情况（refresh 失败 + rollback 失败），实际触发概率极低。

**修复方案**：添加 atomic 计数器 + sysfs/debugfs 暴露。

---

### Opus-4.3 [HIGH] REJIT rollback 路径的 trampoline refresh 失败可能导致不一致状态

**裁决：✅ 确认存在**

代码位置：`syscall.c:3800-3815`

分析：如果正向 `bpf_trampoline_refresh_prog()` 因 JIT 内存不足失败，`bpf_prog_rejit_rollback()` 内部也调 `bpf_trampoline_refresh_prog()`，很可能同样失败。此时 prog 的 `bpf_func` 已被 swap 回旧值，但 trampoline image 仍指向新值（swap 前的值）。由于 `retain_old_image = true`，tmp 不会被释放，JIT image 仍有效——所以不会 UAF，但 trampoline 调用的是旧代码而 prog 认为自己是旧代码，形成功能上的不一致。

**修复方案**：考虑在正向 refresh 失败时直接 `retain_old_image = true` 而不尝试 rollback。

---

### Opus-4.4 [HIGH] `bpf_prog_rejit_poke_target_phase` 全局扫描 `map_idr` 的性能问题

**裁决：⚠️ 部分正确，严重度应为 MEDIUM**

这是一个性能问题而非正确性问题。全局扫描 `map_idr` 在大规模部署中可能很慢，但 REJIT 本身是低频操作，且在 `rejit_mutex` 保护下执行。

关于 TOCTOU 窗口：代码在 lockless pre-check 后持有 `poke_mutex` 再检查，两个方向都是 benign。delete phase 多 NOP 一个（下次 map update 会修正），insert phase 少一个（下次 map update 会补上）。

**建议**：未来优化可添加反向索引，但不阻塞提交。

---

### Opus-4.5 [HIGH] `bpf_prog_rejit()` 缺少对 TRACING 类型的特殊处理

**裁决：❌ 误报**

代码位置：`syscall.c:3162-3199`（`bpf_prog_rejit_supported`）, `trampoline.c:862-863`

分析：
- TRACING 程序（fentry/fexit/fmod_ret）在 `bpf_trampoline_link_prog()` 时已正确将 `bpf_tramp_user` 添加到 `trampoline_users` 链表。
- `bpf_trampoline_refresh_prog()` 遍历该链表刷新所有关联 trampoline。
- `bpf_prog_rejit_supported()` 不排除 TRACING 类型是正确的，因为 `trampoline_users` 机制已覆盖此场景。
- Opus 担心的"通过旧路径 attach"场景不存在——`bpf_trampoline_link_prog()` 是唯一的 link 入口。

---

### Opus-5.1 [HIGH] 锁顺序问题：`rejit_mutex` -> `tr->mutex` 可能与其他路径死锁

**裁决：⚠️ 部分正确，但实际风险低**

代码位置：`trampoline.c:859-864`（link），`trampoline.c:910-923`（unlink）

分析：
- 当前代码确立了锁序：`rejit_mutex` -> `tr->mutex`。
- 审查了所有 `tr->mutex` 的持有路径：`bpf_trampoline_link_prog`、`bpf_trampoline_unlink_prog`、`bpf_trampoline_refresh_prog`、`bpf_trampoline_update` 的直接调用者。
- `bpf_trampoline_update` 在 `__bpf_trampoline_link_prog` 和 `__bpf_trampoline_unlink_prog` 中被调用，此时 `tr->mutex` 已持有，不会再去拿 `rejit_mutex`。
- 目前没有发现反向锁序路径。

**建议**：添加 `lockdep_assert_held` 注解和锁顺序文档。不阻塞提交。

---

### Opus-7.1 [HIGH] `find_next_call_site` 中直接解码 native 指令

**裁决：❌ 误报**

代码位置：`bpf_struct_ops.c:1470-1519`

分析：
- 函数在 `st_ops_assoc_mutex` 保护下执行。
- struct_ops trampoline image 在注册后不会被并发修改（只能通过 unregister 销毁）。
- REJIT 路径持有 `rejit_mutex`，且通过 `st_ops_assoc_mutex` 确保 image 稳定。

---

### Opus-7.4 [MEDIUM] `bpf_arch_text_poke` 调用时参数 `BPF_MOD_CALL` 传了两次

**裁决：❌ 误报**

代码位置：`bpf_struct_ops.c:1597-1600`

```c
err = bpf_arch_text_poke(call_sites[i], BPF_MOD_CALL,
                         BPF_MOD_CALL,
                         (void *)old_bpf_func,
                         new_bpf_func);
```

`bpf_arch_text_poke` 的签名是：
```c
int bpf_arch_text_poke(void *ip, enum bpf_text_poke_type old_t,
                       enum bpf_text_poke_type new_t, void *old_addr,
                       void *new_addr);
```

**有 5 个参数**，两个 type 参数分别表示旧类型和新类型。`BPF_MOD_CALL, BPF_MOD_CALL` 表示"旧的是 CALL，新的也是 CALL"，这是正确的——只是替换 CALL 的目标地址。Opus 报告误以为只有 4 个参数。

---

### Opus-9.1 [HIGH] `lower_kinsn_proof_regions` 在 verifier 探索之前修改指令流

**裁决：⚠️ 部分正确，但设计是 intentional**

代码位置：`verifier.c:3722-3879`（lower），`verifier.c:3836-3879`（restore）

分析：
- lower-verify-restore 模式的核心意图是：让 verifier 验证 proof sequence（kinsn 的等价 BPF 指令序列），而非验证不可识别的 kinsn pseudo-insn。
- lower 从后往前遍历（`for (i = prog->len - 1; i >= 0; i--)`），避免前面的 patch 影响后面的索引。
- restore 从前往后遍历，并在每次 patch 后更新后续 region 的 start 偏移。

Opus 指出的 `aux[].jt` 清空问题：这是 intentional——proof region 内的 jump target 信息在 restore 后不再有意义（对应指令已被替换回 sidecar+call）。

关于 `BPF_LD_IMM64` 的问题：`validate_kinsn_proof_seq` 确实没有处理 `BPF_LD_IMM64` 的双指令跳过。但 proof sequence 已禁止 `src_reg != 0` 的 `BPF_LD_IMM64`（即伪 ldimm64），只允许 `src_reg == 0` 的纯字面量加载。对纯字面量 `BPF_LD_IMM64`，第二条指令的 `code` 仍然满足 `BPF_CLASS = BPF_LD`，不会被误判为 JMP。但循环 `for (i = 0; i < cnt; i++)` 会对第二条 insn 做类型检查，这条 insn 的 class 是 `BPF_LD`，不会进入 JMP 分支。所以实际上是安全的。

**结论**：设计是 intentional 的，但缺少清晰的注释和 assertion。建议添加。

---

### Opus-9.2 [HIGH] `validate_kinsn_proof_seq` 的跳转验证不完整（BPF_LD_IMM64）

**裁决：❌ 误报**（见上条分析）

proof sequence 禁止了带 `src_reg != 0` 的 `BPF_LD_IMM64`。对 `src_reg == 0` 的纯字面量 `BPF_LD_IMM64`，第二条 insn 的 class 是 `BPF_LD`，不会触发 JMP 分支的跳转检查。虽然没有显式 `i++` 跳过第二条，但不会产生错误结果。

不过，如果 proof sequence 包含纯字面量 `BPF_LD_IMM64`（合法），验证器会对第二条 insn 做无意义的检查。虽然不会报错（class 不匹配 JMP），但属于冗余检查。可优化但不阻塞。

---

### Opus-11.1 [HIGH] ARM64 `emit_kinsn_desc_call_arm64` 直接写入 `ctx->image`

**裁决：✅ 确认存在**

代码位置：`arm64/net/bpf_jit_comp.c:1210`

```c
n_insns = kinsn->emit_arm64(ctx->image, &ctx->idx, ctx->write,
                            payload, bpf_prog);
```

与 x86 使用 scratch buffer + `memcpy` 不同，ARM64 直接让回调写入 JIT image。如果回调有 bug（写入超过 `max_emit_bytes`），后验证 `ctx->idx - saved_idx != n_insns` 能检测到 `n_insns` 与实际索引的不一致，但物理写入已发生。

缓解因素：
- `emit=false`（sizing pass）时 `ctx->image` 为 NULL，回调不应写入任何内容。
- 回调由内核模块提供，享有内核同等信任级别。

**建议**：与 x86 保持一致，使用 scratch buffer。不阻塞 POC，但 upstream 提交前应修复。

---

### Opus-14.1/14.2/14.3 [HIGH] 缺少结构体定义和函数实现

**裁决：⚠️ 部分正确**

- `struct bpf_kinsn_region`：定义应在 `include/linux/bpf_verifier.h` 中，diff 不完整。
- `env->kinsn_regions` 等字段：定义不在 diff 中。
- `bpf_prog_refresh_xdp`：只有声明没有实现。

这些不是 bug，而是 patch 不完整。对于 POC 评估来说可以理解，但 upstream submission 必须补全。

---

## 三、两份报告都未发现的遗漏问题

### 遗漏-1 [HIGH] `bpf_prog_rejit_swap` 未 swap `is_func` bitfield

`bpf_prog_rejit_swap` swap 了大量 bitfield，但没有 swap `is_func`。`is_func` 标记程序是否为子函数。虽然 `bpf_prog_rejit_supported()` 拒绝 `is_func == 1` 的程序，但如果 tmp 的验证过程因某种原因设置了 `is_func`（不太可能但非不可能），swap 后的状态会不一致。风险低但值得在 swap 列表中确认完整性。

### 遗漏-2 [MEDIUM] `bpf_prog_rejit_swap` 未 swap `sleepable` 位

`tmp->sleepable` 在 REJIT 入口被设置为 `prog->sleepable`（`syscall.c:3639`），所以 swap 后值相同。但如果 verifier 在某些情况下修改 `sleepable`，值可能不同步。当前代码安全但脆弱。

### 遗漏-3 [MEDIUM] `bpf_prog_get_info_by_fd` 持有 `rejit_mutex` 期间执行 `copy_to_user`

代码位置：`syscall.c:6078`（`guard(mutex)(&prog->aux->rejit_mutex)`）

`bpf_prog_get_info_by_fd` 在 `rejit_mutex` 保护下执行多次 `copy_to_user`。如果用户空间传入的缓冲区触发 page fault，mutex 会被持有较长时间，可能阻塞并发的 REJIT 操作。虽然不是死锁，但可能导致 REJIT 延迟。

### 遗漏-4 [LOW] `bpf_prog_rejit` 使用 `GFP_USER` 分配 `kfd_array` 和 `tmp`

REJIT 要求 `CAP_BPF + CAP_SYS_ADMIN`，但使用 `GFP_USER` 而非 `GFP_KERNEL`。`GFP_USER` 允许用户空间 memcg 计费和回收，这对特权操作可能不合适。

---

## 四、总结

| 严重度 | 确认存在 | 误报 | 部分正确 |
|--------|---------|------|---------|
| CRITICAL | 0 | 1 (Opus-4.1) | 1 (Opus-3.1 降级为 MEDIUM) |
| HIGH | 4 | 3 | 4 |
| MEDIUM | 3 | 0 | 2 |
| LOW | 1 | 0 | 0 |

### 必须修复的问题（阻塞合并）：

1. **[HIGH] `do_misc_fixups` kinsn insn_buf 溢出**（Codex-1）：添加 `max_insn_cnt <= INSN_BUF_SIZE` 检查
2. **[HIGH] `has_callchain_buf` 未被 swap**（Codex-3）：添加到 SWAP_PROG_BITFIELD 列表
3. **[HIGH] rollback poke_tab memcpy 无锁**（Codex-5）：复用正向路径的锁粒度
4. **[HIGH] trampoline_users 反向索引在 unlink 失败时被删除**（Codex-8）：仅成功时删除
5. **[HIGH] rollback 的 trampoline refresh 失败导致不一致**（Opus-4.3）：改为直接 retain
6. **[HIGH] ARM64 emit 回调无 scratch buffer**（Opus-11.1）：改为 scratch + memcpy
7. **[HIGH] 删除所有 `rejit_scx_debug_prog` 调试代码**（Codex-7 / Opus-4.6）
8. **[HIGH] patch 不完整**（Opus-14.x）：补全缺失定义和实现
9. **[MEDIUM] `kinsn-only` 程序应设置 `jit_needed`**（Codex-2）：在 `bpf_prog_select_runtime` 中检查
10. **[MEDIUM] `orig_insns` 全局分配**（Codex-6）：改为 lazy 或 opt-in

### 确认为误报的问题：

1. Opus-4.1：`memcpy(prog->insnsi, ...)` 越界——vmalloc 分配是页对齐的，检查正确
2. Opus-7.4：`bpf_arch_text_poke` 参数错误——5 参数签名，两个 `BPF_MOD_CALL` 是正确的
3. Opus-4.5：TRACING 类型未特殊处理——`trampoline_users` 机制已覆盖
4. Opus-9.2：`validate_kinsn_proof_seq` 的 `BPF_LD_IMM64` 处理——class 检查避免了误判

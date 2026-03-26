# batch2 patch review

Patch reviewed: `/tmp/batch2.patch`

Method: static code review against the current tree. I did not run a build or runtime test.

## 1. `syscall.c`: rollback `poke_tab` 改为逐条加锁恢复

**PASS**

意见：

- `bpf_prog_rejit_update_poke_tab()` 本来就是按 entry 获取 `array->aux->poke_mutex`，并通过 `tailcall_target_stable` 阻止并发 `map_poke_run()` 看到半更新状态；见 `kernel/bpf/syscall.c:3218-3278` 和 `kernel/bpf/arraymap.c:1107-1144`。
- 旧的 rollback 直接 `memcpy(prog->aux->poke_tab, saved_poke_tab, ...)` 会绕过这套同步协议。若此时有并发的 PROG_ARRAY 更新，`map_poke_run()` 可能在 swap-back 之后看到混合的 old/new JIT 地址。
- 现在在 `kernel/bpf/syscall.c:3543-3564` 里逐条拿 `poke_mutex`，先把 `tailcall_target_stable` 置 false，再恢复 `tailcall_target` / `tailcall_bypass` / `bypass_addr` / `adj_off`，最后置 true；这和正向更新路径对称，修复方向正确。
- 只恢复上述地址字段也是合理的，因为正向 `bpf_prog_rejit_update_poke_tab()` 实际改动的就是这些字段，而不是整张 descriptor。

## 2. `trampoline.c`: unlink 失败时不删 `trampoline_users`

**PASS**

意见：

- `bpf_trampoline_refresh_prog()` 完全依赖 `prog->aux->trampoline_users` 来找到需要重建的 trampoline；见 `kernel/bpf/trampoline.c:931-948`。
- `__bpf_trampoline_unlink_prog()` 在非 REPLACE 路径里，先把 link 从 hlist 和计数里摘掉，再调用 `bpf_trampoline_update()`；见 `kernel/bpf/trampoline.c:872-899`。因此它返回错误时，旧 trampoline image 仍可能继续执行这个 prog。
- 如果 unlink 失败时仍删除 `trampoline_users` 里的反向索引，那么后续 REJIT refresh 就再也找不到这个 trampoline，存在把仍在调用 old image 的 trampoline “丢失”的风险。
- 现在 `kernel/bpf/trampoline.c:912-923` 改成仅在 `!err` 时删除 `trampoline_users`，这个修复是对的。
- 范围说明：这并没有让 unlink failure 变成完全原子；它修复的是 refresh reachability / 安全性，而不是所有失败中间态。

## 3. `syscall.c`: trampoline refresh 失败直接 retain

**PASS**

意见：

- `bpf_trampoline_refresh_prog()` 是遍历 `trampoline_users` 逐个重建的；一旦中途失败，就可能已经有一部分 trampoline 切到了 new image，另一部分还留在 old image。
- 这种情况下再调用 rollback，会再跑一轮 trampoline refresh，无法保证回滚仍然原子；如果第二轮也失败，状态只会更混乱。
- 现在 `kernel/bpf/syscall.c:3822-3832` 在 refresh 失败后直接 `retain_old_image = true`，不再尝试 rollback trampoline，这个选择更保守但更安全。
- 语义上也说得通：swap 之后 direct tail-call callers 已经指向 new image，而 retain `tmp` 可以保证尚未 refresh 完的 trampolines 继续调用 old image 时不会落到已释放代码上。
- 代价是失败 REJIT 会退化成保留 old image 的泄漏式兜底，而不是回到严格原子状态；但这和现有 `retain_old_image` 容错分支一致，优先保证执行安全。

## 总结

本补丁这 3 个修复我都给 `PASS`。其中第 2 项我认为是“修对了关键安全属性，但没有把 unlink 失败路径整体做成原子恢复”；如果后续要继续收敛这块，建议单独处理 `__bpf_trampoline_unlink_prog()` 失败后的中间态一致性。

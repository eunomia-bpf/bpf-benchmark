# Batch2 Codex Review

结论：

1. `syscall.c`: rollback `poke_tab` 改为按 entry 加 `poke_mutex` 恢复：`FAIL`
2. `trampoline.c`: unlink 失败时不删 `trampoline_users`：`PASS`
3. `syscall.c`: trampoline refresh 失败时直接 `retain_old_image` 不 rollback：`FAIL`

## 1. rollback `poke_tab` 按 entry 加 `poke_mutex` 恢复：FAIL

这版修改里，“单个 descriptor 的恢复方式”本身是对齐现有约束的：forward path 的 `bpf_prog_rejit_update_poke_tab()` 也是在持有对应 `PROG_ARRAY` 的 `poke_mutex` 时，把 `tailcall_target_stable` 置 `false`、更新地址字段、再置回 `true`，见 `kernel/bpf/syscall.c:3218-3278`。`prog_array_map_poke_run()` 也明确要求在持有 `poke_mutex` 时，只处理 `tailcall_target_stable == true` 的 entry，见 `kernel/bpf/arraymap.c:1107-1151`。从“局部写入序列化”看，这里加锁方向是对的，也没有看到新的锁顺序反转。

但整体 rollback 仍然不正确，关键在恢复顺序。现在是先 `bpf_prog_rejit_swap(prog, tmp)` 把 old image 重新发布出去，再逐项恢复 `prog->aux->poke_tab` 到 old image 的地址，见 `kernel/bpf/syscall.c:3538-3567`。这中间存在一个窗口：并发 `PROG_ARRAY` 更新路径在 `kernel/bpf/arraymap.c:918-945` 会拿 `poke_mutex` 后调用 `map_poke_run()`。如果它抢在 rollback 某个 entry 恢复之前执行，就会看到该 entry 仍然 `stable == true` 且地址仍指向 new image，于是去 patch new image；随后 rollback 再把 descriptor 指回 old image，但不会把刚才那次 map 更新 replay 到 old image。结果是已经重新生效的 old image 保留过时的 direct-tail-call patch。

而且即使没有这个 swap-back 窗口，只要 new image 生效期间发生过 `PROG_ARRAY` 更新，问题仍然存在。因为 REJIT forward path 在交换前已经把 `prog->aux->poke_tab` 重定向到 new image，并且把 `tmp` 的 poke tracking 解除掉了，见 `kernel/bpf/syscall.c:3290-3299`。这意味着那段时间内 map update 只会 patch new image；old image 不再被跟踪。rollback 这里只是把 descriptor 地址改回 old image，并没有把“new image 期间发生的 map 变更”补回 old image，所以 rollback 后 old image 可能天然就是 stale 的。

所以，这个修复解决了原来 `memcpy()` 无锁覆盖 descriptor 的问题，但还没有建立“回滚后 old image 与当前 map 状态一致”的保证。要把它做完整，至少还需要一个能覆盖“new image 期间 map 变更”的同步方案，而不只是按 entry 加锁恢复字段。

## 2. unlink 失败时不删 `trampoline_users`：PASS

这里的 `if (!err)` 包裹是对的。`trampoline_users` 是 `prog -> trampoline` 的 reverse index，`bpf_trampoline_refresh_prog()` 依赖它来找到所有仍可能引用该 program 的 trampoline，见 `kernel/bpf/trampoline.c:930-948`。如果 `__bpf_trampoline_unlink_prog()` 失败了，旧 trampoline image 仍有可能保持 active，或者至少还没完成切换；这时把 `trampoline_users` 提前删掉，会让后续 refresh 丢失这条反向引用。

因此，只有在 `__bpf_trampoline_unlink_prog()` 成功后才删除 `trampoline_users`，即 `kernel/bpf/trampoline.c:912-923` 这一层面的修复是正确的。

但这里有一个剩余问题需要明确：`__bpf_trampoline_unlink_prog()` 自己并不是 failure-atomic 的。非 `REPLACE` 路径会先把 link 从 hlist 上摘掉，再去做 `bpf_trampoline_update()`，见 `kernel/bpf/trampoline.c:893-899`；`REPLACE` 路径也会在 `bpf_arch_text_poke()` 返回后无条件清 `tr->extension_prog` 和 `is_extended`，见 `kernel/bpf/trampoline.c:880-888`。所以失败路径本身仍然可能留下状态偏斜。这个补丁修的是“unlink 失败时不该删 reverse index”，这一点我认为成立；但它不是对 unlink 失败一致性的完整修复。

## 3. trampoline refresh 失败时直接 `retain_old_image`：FAIL

这里不 rollback、只保留 old image 以避免 UAF，这个出发点我理解，但作为最终状态不安全。

首先，`bpf_trampoline_refresh_prog()` 是逐个 trampoline 刷新的，遇错即停，见 `kernel/bpf/trampoline.c:936-948`。所以一旦它失败，状态天然可能是“部分 trampoline 已切到 new image，剩余 trampoline 还在 old image”。新补丁在这种情况下直接保留 `tmp` 并返回错误，见 `kernel/bpf/syscall.c:3822-3832` 和 `kernel/bpf/syscall.c:3905-3908`。这会把 `bpf_prog_rejit()` 变成“系统调用返回失败，但程序的部分入口点已经切到新版本”的部分提交语义：普通调用路径、tail-call target path 已经指向 new image，而一部分 trampoline 可能还执行 old image。对于同一个 prog，这种 mixed-version 结果是外部可观察的，不应当作为失败返回后的稳定状态。

其次，这里只是“不 free tmp”，并没有建立后续接管和回收路径。函数返回后 `tmp` 没有被挂到任何显式管理结构上，等价于永久泄漏 old JIT image、subprog 以及它们持有的相关资源。这不是一个可接受的长期恢复策略。

最关键的是，这个 retained old image 还会在后续运行里继续偏离当前状态。因为 forward path 在 swap 前已经执行了 `bpf_prog_rejit_untrack_tmp_pokes(tmp)`，见 `kernel/bpf/syscall.c:3290-3299`。也就是说，被保留下来的 old image 不再参与 `PROG_ARRAY` 的 poke tracking；之后所有 map 更新都只会 patch new image 的 `poke_tab`。如果某些 trampoline 仍然调用 retained old image，那么它们执行到 direct tail-call 站点时会逐步与 map 当前内容脱节，继续跑 stale patch。

所以，这个修改最多只能说“避免立即 free old image 带来的 UAF”，但不能说“逻辑安全”。它引入了失败后部分提交、永久泄漏，以及 old image 后续 tail-call patch 失步这几个问题。我认为不能接受。

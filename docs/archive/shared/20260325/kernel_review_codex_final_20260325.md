# BPF Patch Set Review

整体看，这个 patch set 把 `BPF_PROG_REJIT`、`kinsn`、trampoline/dispatcher 刷新路径一次性都拉进来了，但当前实现里还有几处不能接受的问题，尤其是 JIT fallback、REJIT 回滚并发、资源转移和 UAPI 完整性。下面按文件列出具体问题。

## kernel/bpf/verifier.c

### 1. [HIGH] `do_misc_fixups()` 对 kinsn proof sequence 使用固定 32 指令缓冲区，缺少上界检查
位置: `kernel/bpf/verifier.c:3669-3720`, `kernel/bpf/verifier.c:23755-23785`, `include/linux/bpf_verifier.h:27`

问题: `validate_kinsn_proof_seq()` 只要求 `cnt <= kinsn->max_insn_cnt`，但 `do_misc_fixups()` 里再次调用 `kinsn->instantiate_insn()` 时，目标缓冲区是固定大小的 `env->insn_buf[INSN_BUF_SIZE]`，而 `INSN_BUF_SIZE` 只有 32。这里既没有约束 `kinsn->max_insn_cnt <= 32`，也没有在 `instantiate_insn()` 返回后检查 `cnt <= 32`。

影响: 只要某个 kinsn 描述符把 `max_insn_cnt` 设到 32 以上，或者 `instantiate_insn()` 本身写超，就会在 verifier 堆对象里越界写，属于直接的内核内存破坏路径。

建议: 要么在注册/验证 kinsn 描述符时强制 `max_insn_cnt <= INSN_BUF_SIZE`，要么这里改成按 `max_insn_cnt` 动态分配临时缓冲区，不能继续写死到 `env->insn_buf`。

## kernel/bpf/core.c

### 2. [HIGH] kinsn-only 程序不再强制 `jit_needed=true`，JIT 失败后可能错误回退到 interpreter
位置: `kernel/bpf/core.c:2521-2553`, `kernel/bpf/verifier.c:3634-3647`, `kernel/bpf/verifier.c:23776-23777`

问题: 现在 `bpf_prog_has_kfunc_call()` 只把传统 kfunc 视为 “必须 JIT”，显式排除了 `desc->kinsn`。但 `bpf_prog_select_runtime()` 仍然只依赖这个 helper 来决定 `jit_needed`。与此同时，`do_misc_fixups()` 在 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)` 时会保留原始 `BPF_PSEUDO_KINSN_CALL`，把 lowering 留给 JIT。

影响: 在 x86/arm64 这类支持 native emit 的架构上，只要主 JIT 在最后阶段因为内存或其它原因失败，程序就可能被错误地回退到 interpreter，而最终指令流里还留着 interpreter 根本不认识的 kinsn pseudo-insn。这不是单纯的 load failure，而是会把一个不可解释的程序放进运行路径。

建议: `kinsn` 也必须被视为 “JIT required”。最直接的修法是让 `bpf_prog_has_kfunc_call()` 把 `kinsn` 一起算进去，或者单独增加 `bpf_prog_has_kinsn_call()` 并在 `bpf_prog_select_runtime()` 里并联判断。

## kernel/bpf/syscall.c

### 3. [HIGH] REJIT swap 漏掉了 `has_callchain_buf`，会打破 `bpf_get_stack*()` 的资源生命周期
位置: `kernel/bpf/syscall.c:3445-3456`, `kernel/bpf/verifier.c:12424-12441`, `kernel/bpf/core.c:2926-2927`

问题: verifier 在看到 `bpf_get_stack()` / `bpf_get_task_stack()` 时会通过 `get_callchain_buffers()` 获取全局 callchain buffer，并把 `env->prog->has_callchain_buf` 置位。这个 bit 决定 unload 时是否执行 `put_callchain_buffers()`。但 `bpf_prog_rejit_swap()` 交换了一批 bitfield，却没有交换 `has_callchain_buf`。

影响: 如果旧程序不需要 callchain buffer、新程序需要，那么 ref 会记在 `tmp` 上，随后在释放 `tmp` 时被提前 `put` 掉，活着的 `prog` 反而没有对应持有关系。反过来，如果旧程序需要、新程序不需要，则会把旧 ref 永久泄漏给新程序。

建议: 至少把 `has_callchain_buf` 一并转移；更稳妥的是把这类“带外资源持有”从通用 bitfield swap 里拆出来，做显式的 acquire/release 迁移。

### 4. [HIGH] REJIT 没有完整重放 load-time metadata，却把 live program 的 BTF/func_info/line_info 直接 swap 掉了
位置: `kernel/bpf/syscall.c:3392-3400`, `kernel/bpf/syscall.c:3606-3724`

问题: `bpf_prog_rejit()` 只重放了很小一部分 load-time state，常规 `prog_btf_fd`、`func_info`、`line_info`、`prog_name` 等都没有从 UAPI 重建；但 `bpf_prog_rejit_swap()` 却无条件把 `prog->aux->btf`、`func_info*`、`linfo*`、`jited_linfo` 和计数器从 `tmp` 交换到 live `prog` 上。对普通 BTF-enabled 程序来说，`tmp` 这些字段大多是空的。

影响: 第一次 REJIT 之后，原程序的 prog BTF、func_info、line_info、jited line info 会被静默清空，并随着旧 `tmp` 的释放被真正 `btf_put()/kvfree()`。这会直接回归 `BPF_OBJ_GET_INFO_BY_FD`、bpftool dump、JIT line info 和 kallsyms 命名。

建议: 这个接口要么扩展 UAPI，把 prog BTF / func_info / line_info 全部显式带进来；要么在现有 UAPI 下，只要原程序带了这些 metadata 就直接 `-EOPNOTSUPP`，不能静默降级。

### 5. [HIGH] rollback 用裸 `memcpy()` 恢复 `poke_tab`，会和并发的 `map_poke_run()` 发生数据竞争
位置: `kernel/bpf/syscall.c:3524-3544`, `kernel/bpf/syscall.c:3218-3279`, `kernel/bpf/arraymap.c:1107-1148`

问题: 正向更新 `poke_tab` 时，代码明确按每个 `prog_array` 的 `poke_mutex` 逐项更新，避免 `map_poke_run()` 看到半更新的 descriptor。rollback 路径却直接对整张 `prog->aux->poke_tab` 做 `memcpy()`，完全不拿任何 `poke_mutex`。

影响: 一旦 rollback 和并发的 prog-array 更新重叠，`map_poke_run()` 就可能读到部分恢复的 `tailcall_target` / `bypass_addr` / `adj_off`，从而把 text poke 打到错误地址。这不是理论上的 KCSAN 噪音，而是直接的代码 patch 目标错乱。

建议: rollback 必须复用正向路径的锁粒度，至少按 map 维度拿 `poke_mutex` 后再恢复对应 descriptor，不能整表 memcpy。

### 6. [MEDIUM] 每个程序永久保存一份 `orig_insns`，把大程序的指令内存直接翻倍了
位置: `kernel/bpf/syscall.c:3027-3038`

问题: 现在所有 `BPF_PROG_LOAD` 都会额外 `kvmemdup()` 一份原始指令，并一直保留到 unload。这个成本不是按需，而是无条件付出。

影响: 对大 BPF 程序，这会把 instruction storage 近乎翻倍；而 REJIT 和 `orig_prog_insns` 查询都属于非常低频路径，大多数程序根本不会用到这份副本。

建议: 这类状态应该按需分配。可以在第一次 `BPF_PROG_REJIT` 或第一次请求 `orig_prog_insns` 时延迟创建，或者通过显式 load flag/UAPI opt-in 打开。

### 7. [LOW] `rejit_scx_debug_prog()` 是明显的调试残留，且把原始内核地址打进了日志
位置: `kernel/bpf/syscall.c:5597-5605`, `kernel/bpf/syscall.c:5622-5629`, `kernel/bpf/syscall.c:5851`, `kernel/bpf/syscall.c:5887`, `kernel/bpf/syscall.c:5897`, `kernel/bpf/syscall.c:6165`

问题: `BPF_PROG_GET_FD_BY_ID` 和 `BPF_OBJ_GET_INFO_BY_FD` 路径里加入了无条件 `pr_info()`，还打印了 `%px` 的 `bpf_func`/`aux` 地址。

影响: 这会在常见管理路径上制造日志噪音，也把调试专用的地址信息带进生产内核日志。即便调用者大多是特权进程，这种输出也不应该进主线。

建议: 这段代码应当在提交前完全删除；如果确实需要，至少也应改成动态调试或 tracepoint，而不是常驻 `pr_info()`。

## kernel/bpf/trampoline.c

### 8. [MEDIUM] unlink 失败时仍然删除 `trampoline_users` 反向索引，后续 REJIT 会漏刷新仍然存活的 trampoline
位置: `kernel/bpf/trampoline.c:903-925`

问题: `bpf_trampoline_unlink_prog()` 先调用 `__bpf_trampoline_unlink_prog()`，随后无论 `err` 是否为 0，都会把匹配的 `bpf_tramp_user` 从 `prog->aux->trampoline_users` 里删除并释放。

影响: 这和真实 link 状态可能发生偏离。只要 unlink/update 某次失败，trampoline 仍然挂着，但反向索引已经没了；之后 REJIT 走 `bpf_trampoline_refresh_prog()` 时就不会再刷新这个 trampoline，留下陈旧的 call target。

建议: 只有在 unlink 真正成功后才能删除反向索引；失败时至少应该保留条目并 `WARN`，不能静默把索引删掉。

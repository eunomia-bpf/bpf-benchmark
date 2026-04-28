# BpfReJIT v2 Kernel Cleanup Architectural Review

> 审查日期：2026-03-22
> 输入：`kernel_cleanup_review.diff` (+17/-118) 和 `kernel_all_committed.diff` (vs stock)
> 参考：`docs/kernel-jit-optimization-plan.md` SS1.4-1.7, SS4

---

## A. 清理改动正确性

### A.1 删除 `tramp_attach_cnt` — 安全

**改动**：删除 `atomic_t tramp_attach_cnt` 字段、`atomic_set` 初始化、`atomic_inc`/`atomic_dec` 调用（syscall.c `bpf_tracing_prog_attach`/`bpf_tracing_link_release`）。

**分析**：`tramp_attach_cnt` 在提交的代码中从未被读取或作为判断条件使用。`bpf_prog_rejit_supported()` 中原本有注释说"kept for future use"但没有实际检查。REJIT 对有 trampoline attachment 的 prog 的支持已通过 `trampoline_users` 链表 + refresh 机制实现。`tramp_attach_cnt` 纯属冗余。

**结论**：删除安全。减少每次 attach/detach 的 atomic 操作开销。

### A.2 删除 fd_array overflow check — 安全

**改动**：删除 `if (fda_size / sizeof(int) != attr->rejit.fd_array_cnt)` 检查。

**分析**：`fd_array_cnt` 类型是 `__u32`（最大 4G），`fda_size` 类型是 `size_t`（64 位系统上 8 字节）。`(size_t)u32_max * 4` = 16GB，远小于 `SIZE_MAX`，64 位系统上不可能溢出。BPF 子系统要求 `CONFIG_BPF_SYSCALL` 仅在 64 位内核上启用。

**结论**：删除安全。该检查在 64 位系统上永远为真（不触发），是死代码。

### A.3 trampoline refresh 失败回滚（re-swap）— **有 BUG**

**改动**：将 trampoline refresh 失败从 `pr_warn` 改为 re-swap 回滚。

```c
err = bpf_trampoline_refresh_prog(prog, old_bpf_func);
if (err) {
    bpf_prog_rejit_swap(prog, tmp);  // rollback
    goto free_tmp_noref;
}
```

**问题**：`bpf_trampoline_refresh_prog()` 遍历 `trampoline_users` 链表，逐个 refresh，遇到第一个错误即 `break`。如果有 N 个 trampoline 且第 K 个失败（K < N），则：

- trampoline 1..K-1：已 refresh，现在指向 **新** `bpf_func`（即 `tmp` 编译出的 image）
- trampoline K..N：未 refresh，仍指向 **旧** `bpf_func`

rollback re-swap 将 `prog->bpf_func` 恢复为旧值，`tmp->bpf_func` 恢复为新值。之后 `goto free_tmp_noref` 释放 `tmp`，其 JIT image 也被释放。此时 **trampoline 1..K-1 持有已释放的新 bpf_func 指针 — use-after-free**。

**修复方向**（不在本次审查范围内改代码）：

1. **选项 A**：rollback 时也 reverse-refresh 已成功的 trampoline（需要记录成功到第几个，传 `old_bpf_func` 作为"新目标"重做一遍）。复杂但完全正确。
2. **选项 B**：保持原来的 best-effort 语义——refresh 失败只 `pr_warn`，不回滚。REJIT 已经成功，trampoline refresh 失败不影响 prog 主体执行，只是个别 fentry/fexit 看到旧 image（最终会被下次 reattach 或 unlink 修复）。简单，符合"fail-safe"原则。
3. **选项 C**：先做一轮 dry-run/预检查（如检查所有 trampoline 是否 alive、image 是否可分配），全部通过后再做实际 refresh。但 `bpf_trampoline_update` 本身可能因内存分配失败而不可预检。

**建议**：**采用选项 B**（回退到 `pr_warn`，不回滚）。原因：
- refresh 失败场景极罕见（内存耗尽或 arch_prepare_bpf_trampoline 失败）
- 部分 refresh 成功 + rollback = 确定性 UAF，比"偶发 trampoline 未刷新"严重得多
- 与 livepatch 等内核机制的 best-effort 语义一致

### A.4 删除 `dev_bound` 复制 — 安全

**改动**：删除 `tmp->aux->dev_bound = prog->aux->dev_bound`。

**分析**：`bpf_prog_rejit_supported()` 已通过 `bpf_prog_is_dev_bound(aux)` 拒绝 dev_bound 程序。如果 prog 是 dev_bound，REJIT 流程在进入 swap 之前就已 return `-EOPNOTSUPP`。因此 swap 中对 `dev_bound` 的复制永远不会执行。

**结论**：删除安全，是死代码。

### A.5 删除 NULL 检查 (`bpf_dispatcher_refresh_prog`, `bpf_unregister_kfunc_inline_ops`) — 安全

**改动**：
- `bpf_dispatcher_refresh_prog` 中删除 `if (!d || !prog) return`
- `bpf_unregister_kfunc_inline_ops` 中删除 `if (!func_name) return`

**分析**：
- `bpf_dispatcher_refresh_prog` 的唯一调用点是 `bpf_prog_rejit` 中 `bpf_prog_refresh_xdp(prog)`，传入的 `prog` 不可能为 NULL（前面已 `bpf_prog_get` 成功），`d` 是静态 `BPF_DISPATCHER_PTR(xdp)` 宏展开，也不可能为 NULL。
- `bpf_unregister_kfunc_inline_ops` 由 module exit 调用，`func_name` 是编译时字符串常量。

**结论**：删除安全。符合 CLAUDE.md "No unnecessary defensive checks" 规则。

### A.6 删除的注释是否包含关键信息

**审查所有被删除的注释**：

| 位置 | 删除内容 | 是否包含关键信息 |
|------|----------|:---:|
| `bpf_jit_comp.c` ARM64 | emit_arm64 回调的参数文档 | 否，参数签名已自解释 |
| `bpf.h` `bpf_kfunc_inline_ops` | ARM64 emit 回调参数文档 | 否，同上 |
| `bpf.h` `bpf_tramp_user` | "Linked into prog->aux->trampoline_users" | 否，替换注释已包含核心信息 |
| `dispatcher.c` refresh_prog | kerneldoc 格式说明 | 否，替换的单行注释足够 |
| `syscall.c` rejit_supported | "tramp_attach_cnt kept for future use" | 否，字段已删除 |
| `syscall.c` subprog_layout_match | 函数功能说明 | 否，函数名已自解释 |
| `syscall.c` rejit_swap | kallsyms/func[] swap 时序说明 | **轻微**：`smp_wmb()` 前的 "Publish the replacement image" 注释删除后，读者可能不理解为什么需要 barrier。建议保留或缩短，不要完全删除 |
| `syscall.c` bpf_prog_rejit | fd_array 复制原因 | 否，替换注释已保留核心理由 |
| `syscall.c` bpf_prog_rejit | "Phase 1/Phase 2" 标签 | 否，phase 编号无语义意义 |
| `trampoline.c` refresh_prog | kerneldoc + "AFTER bpf_func updated BEFORE old freed" 时序约束 | **轻微**：调用时序约束是重要信息，单行替换注释 "Caller holds rejit_mutex" 丢失了 "BEFORE old image freed" 这个关键约束。建议恢复 |
| `trampoline.c` freplace/fentry | 具体机制说明 | 否，替换的单行注释足够 |

**建议恢复的注释**（2 处）：

1. `syscall.c` `smp_wmb()` 前：至少保留 `/* Publish replacement image */` 一行
2. `trampoline.c` `bpf_trampoline_refresh_prog` 函数头：恢复 "Must be called AFTER bpf_func is updated but BEFORE the old JIT image is freed" 约束说明

---

## B. 架构对齐

### B.1 三组件完整性

| 组件 | 状态 | 说明 |
|------|:---:|------|
| syscall (GET_ORIGINAL + REJIT) | 完整 | `BPF_PROG_REJIT` cmd、`orig_prog_insns`/`orig_prog_len` in `bpf_prog_info`、完整 verify+JIT+swap 流程 |
| kinsn (KF_INLINE_EMIT) | 完整 | `bpf_kfunc_inline_ops` 结构体、register/unregister API、x86+ARM64 JIT 分发、verifier `inline_ops` 缓存 |
| daemon | N/A | 纯用户态，不在 kernel diff 中 |

**结论**：内核侧三组件完整，与 SS1.7 设计一致。

### B.2 GET_ORIGINAL + REJIT 流程

**GET_ORIGINAL**：通过 `bpf_prog_get_info_by_fd` 中的 `orig_prog_insns`/`orig_prog_len` 字段实现。`bpf_prog_load` 时 `kvmemdup` 保存原始 insns，REJIT 后 swap 到新 insns 的 orig 副本。路径正确。

**REJIT 流程**：
1. 权限检查 (CAP_BPF + CAP_SYS_ADMIN)
2. `bpf_prog_rejit_supported()` 预检
3. `rejit_mutex` 序列化
4. 构造 `load_attr`，fd_array 复制到内核
5. `bpf_prog_alloc` + 复制 insns + `bpf_check` + `bpf_prog_select_runtime` (JIT)
6. 二次 `bpf_prog_rejit_supported` + `jited` 检查
7. subprog layout match 检查
8. swap + trampoline refresh + XDP dispatcher refresh
9. `synchronize_rcu` + 释放旧 image

**问题**：流程整体正确。唯一问题是 A.3 中的 refresh 失败回滚 bug。

### B.3 kinsn (KF_INLINE_EMIT) 路径

**注册**：`bpf_register_kfunc_inline_ops(func_name, ops)` → 加入 `bpf_kfunc_inline_list`

**verifier 集成**：`add_kfunc_call()` 中检查 `KF_INLINE_EMIT` flag → `bpf_kfunc_inline_lookup()` → 缓存到 `desc->inline_ops`

**JIT 分发**：
- x86：`emit_kinsn_desc_call()` → `ops->emit_x86()` → 检查 `ret == off && ret <= max_emit_bytes`
- ARM64：`emit_kinsn_desc_call_arm64()` → `ops->emit_arm64()` → 检查 `ctx->idx - saved_idx == n_insns` + `n_insns * 4 <= max_emit_bytes`

**fallback**：如果 `bpf_jit_find_kfunc_inline_ops` 返回 NULL（module 未加载），JIT 正常 emit CALL 指令。

**结论**：路径完整且正确。x86 和 ARM64 都有一致的 bounds check。

### B.4 multi-subprog layout match

**检查**：`bpf_prog_rejit_subprog_layout_match` 比较 `real_func_cnt` 和每个 subprog 的 `len`（insn count）。

**是否足够**：
- 匹配 insn count 确保新旧程序有相同的 subprog 边界
- **不检查** subprog 签名/参数类型，但这由 verifier 保证（bpf_check 会验证）
- **不检查** subprog 名称/BTF，但 swap 中已 swap `func_info`/`func_info_aux`

**已知限制**：如果 daemon 的变换改变了某个 subprog 的 insn count（如 inline 了一条 kinsn call），layout match 会拒绝。这是 by design——daemon 需要保持每个 subprog 的 insn count 不变（padding NOP），或者变换只适用于单函数程序。

**结论**：对当前需求足够。如果未来需要支持 subprog-level 变换（insn count 变化），需要放宽此检查并相应调整 func[] swap 逻辑。

---

## C. 进一步简化建议

### C.1 swap 字段列表

当前 `bpf_prog_rejit_swap` 交换/复制约 35 个字段。可分为三类：

**必须 swap（资源所有权转移）**：~18 个
- `orig_insns`, `orig_prog_len`, `func`, `func_cnt`, `real_func_cnt`
- `used_btfs`, `used_btf_cnt`, `btf`, `kfunc_tab`, `kfunc_btf_tab`
- `used_maps`, `used_map_cnt`
- `func_info`, `func_info_aux`, `func_info_cnt`
- `linfo`, `jited_linfo`, `nr_linfo`, `linfo_idx`
- `num_exentries`, `extable`, `priv_stack_ptr`, `jit_data`
- `security`

**必须复制（verifier 产出的 metadata）**：~15 个
- `max_ctx_offset`, `max_pkt_offset`, `max_tp_access`, `stack_depth`
- `max_rdonly_access`, `max_rdwr_access`, `verifier_zext`
- `changes_pkt_data`, `kprobe_write_ctx`, `verified_insns`
- `digest`, `jited`, `jited_len`, `gpl_compatible`, `cb_access`
- `dst_needed`, `blinding_requested`, `blinded`, `kprobe_override`
- `enforce_expected_attach_type`, `call_get_stack`, `call_get_func_ip`
- `call_session_cookie`, `tstamp_type_access`

**简化建议**：

1. **位字段 batch copy**：`gpl_compatible`, `cb_access`, `dst_needed` 等是 `struct bpf_prog` 中的单 bit 字段。如果它们在结构体中连续（事实上它们是 bitfield），可以用一个 `memcpy` 覆盖整个 bitfield word，而不是逐个赋值。但这依赖结构体 layout 稳定性，**不推荐**。

2. **verifier metadata struct 提取**：将 `max_ctx_offset`/`max_pkt_offset`/... 等 verifier 产出的字段提取到一个 `struct bpf_prog_verify_info` 中，swap 时只需一个 `memcpy`。但这需要修改 `struct bpf_prog_aux` 的定义，影响面大，**适合作为 upstream 改进建议而非 POC 改动**。

3. **当前可删除的 swap**：
   - `bpf_exception_cb` / `exception_boundary`：如果 REJIT 不支持 exception callback 程序（可以在 `bpf_prog_rejit_supported` 中加检查），则无需 swap

**结论**：swap 字段列表已经是最小必要集，暂无安全可删除项。

### C.2 其他多余代码

1. **`INIT_LIST_HEAD_RCU` in `core.c __bpf_ksym_del`**：这是清理 diff 之外的改动，但在 committed diff 中存在。`__bpf_ksym_del` 在 `latch_tree_erase` + `list_del_rcu` 后加了 `INIT_LIST_HEAD_RCU`。这是为了让 REJIT 的 `bpf_prog_kallsyms_del_all` 在重新 add 前能安全检查 list 状态。合理，非多余。

2. **`bpf_prog_rejit_supported` 二次调用**：在 `bpf_prog_rejit` 中，verify+JIT 后又调用一次 `bpf_prog_rejit_supported(tmp)`。这是因为 verifier 可能改变 prog 属性（如 `dst_prog`）。合理。

3. **单函数程序的 `real_func_cnt == 0` 提前返回**：`bpf_prog_rejit_subprog_layout_match` 中 `if (!prog->aux->real_func_cnt) return true`。这是正确的优化（单函数程序无需比较 func[]），非多余。

---

## D. 遗漏/风险

### D.1 [HIGH] trampoline refresh 失败回滚导致 UAF

详见 A.3。部分 refresh 成功后 rollback re-swap 会导致已刷新的 trampoline 指向被释放的 JIT image。

**严重程度**：HIGH — 可导致内核 crash（use-after-free on code execution）。

**发生条件**：REJIT 目标 prog 被 2+ 个 fentry/fexit/freplace attach，且其中一个 trampoline 的 rebuild/text_poke 失败（通常因内存耗尽）。

**修复**：回退到 `pr_warn` + 不回滚，或实现完整的 reverse-refresh。

### D.2 [LOW] `load_time` 在 rollback 后不恢复

`bpf_prog_rejit_swap` 设置 `prog->aux->load_time = ktime_get_boottime_ns()`。如果 rollback，load_time 被更新两次（不恢复原始值）。影响极小（仅影响 `bpf_prog_info.load_time` 展示），但严格来说是语义错误。

### D.3 [LOW] XDP dispatcher refresh 无错误处理

`bpf_dispatcher_refresh_prog` 返回 void。如果 dispatcher rebuild 失败，没有错误报告。当前实现中 `bpf_dispatcher_update` 不返回错误（内部 `bpf_jit_binary_alloc` 失败会 fallback 到 interpreter），所以实际无影响。但如果未来 dispatcher 实现变化，可能遗漏错误。

### D.4 [INFO] trampoline_users 注释从 "trampoline_mutex" 改为 "rejit_mutex"

cleanup diff 将 `bpf_tramp_user` 注释从 "Protected by trampoline_mutex" 改为 "Protected by rejit_mutex"。代码中实际使用的是 `rejit_mutex`。修改正确——注释与实现一致了。

### D.5 [INFO] 缺少 `BPF_PROG_REJIT` 的 audit log

`__sys_bpf` 中 `BPF_PROG_REJIT` case 没有 audit logging。现有的 `BPF_PROG_LOAD` 也没有 audit log（安全由 `security_bpf_prog_load` hook 处理），所以这是一致的。但从安全审计角度，REJIT（在线替换 live 程序）比 LOAD 更 security-sensitive。未来可考虑添加。

---

## 总结

| 类别 | 项目 | 状态 |
|------|------|------|
| tramp_attach_cnt 删除 | 安全 | PASS |
| fd_array overflow check 删除 | 安全（64-bit only） | PASS |
| trampoline refresh 失败回滚 | **有 UAF bug** | **FAIL** |
| dev_bound 复制删除 | 安全 | PASS |
| NULL 防御性检查删除 | 安全 | PASS |
| 注释删除 | 2 处建议恢复 | WARN |
| 三组件完整性 | 完整 | PASS |
| GET_ORIGINAL + REJIT 流程 | 正确（除 A.3） | PASS |
| KF_INLINE_EMIT 路径 | 正确 | PASS |
| multi-subprog layout match | 足够 | PASS |
| swap 字段列表 | 已最小 | PASS |

## 结论：**暂不可 commit**

需要先修复 D.1（trampoline refresh 失败回滚导致 UAF）。建议：

1. 将 refresh 失败处理回退到 `pr_warn` + 继续（不回滚），即恢复原始 committed 版本的行为
2. 恢复 `smp_wmb()` 前的 `/* Publish replacement image */` 注释
3. 恢复 `bpf_trampoline_refresh_prog` 函数头的时序约束注释

修复上述 3 点后即可 commit。其余清理改动（-118 行冗余代码/注释）全部正确且有价值。

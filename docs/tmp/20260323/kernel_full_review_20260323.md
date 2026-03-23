# BpfReJIT 内核改动完整 Code Review (2026-03-23)

范围：`git diff master..rejit-v2` on `vendor/linux-framework`
23 files, +2202/-13 lines (含 selftests)。核心改动 16 files, +1881/-11 lines（不含 selftests）。

---

## 一、逐文件改动摘要

### 1. `include/uapi/linux/bpf.h` (+20)
- 新增 `BPF_PROG_REJIT` 命令到 `enum bpf_cmd`
- 新增 `BPF_PSEUDO_KINSN_SIDECAR` (= 3) 伪源寄存器
- 新增 `union bpf_attr.rejit` 结构体：prog_fd, insn_cnt, insns, log_level/size/buf, fd_array, fd_array_cnt, flags
- 新增 `bpf_prog_info.orig_prog_len` + `orig_prog_insns` 字段

### 2. `tools/include/uapi/linux/bpf.h` (+20)
- 与 kernel UAPI 完全同步（同样的 20 行改动）

### 3. `include/linux/bpf.h` (+173)
- 新增 kinsn 类型系统：`bpf_kinsn_encoding`, `bpf_kinsn_result_type`, `bpf_kinsn_operand_kind`, `bpf_kinsn_mem_flags`, `bpf_kinsn_effect_flags` 枚举
- 新增 kinsn 数据结构：`bpf_kinsn_scalar_state`, `bpf_kinsn_operand`, `bpf_kinsn_call`, `bpf_kinsn_mem_access`, `bpf_kinsn_effect`, `bpf_kinsn_ops`
- 新增 sidecar 内联函数：`bpf_kinsn_is_sidecar_insn()`, `bpf_kinsn_sidecar_payload()`
- 新增 `bpf_tramp_user` 结构体（trampoline 反向索引）
- `bpf_prog_aux` 新增字段：`rejit_mutex`, `trampoline_users`, `orig_insns`, `orig_prog_len`
- 新增函数声明：`bpf_dispatcher_refresh_prog`, `bpf_trampoline_refresh_prog`, `bpf_struct_ops_refresh_prog`, `bpf_register_kinsn_ops`, `bpf_unregister_kinsn_ops`, `bpf_free_kfunc_desc_tab`, `bpf_jit_find_kinsn_ops`, `bpf_jit_get_kinsn_call`
- 完整的 `!CONFIG_BPF_SYSCALL` / `!CONFIG_BPF_JIT` 静态 stub

### 4. `include/linux/bpf_verifier.h` (+3)
- `bpf_insn_aux_data` 新增 `kinsn_clobber_mask` (u32) 和 `kinsn_call` (bool)

### 5. `include/linux/btf.h` (+2)
- 新增 `KF_KINSN = (1 << 17)` 和别名 `KF_INLINE_EMIT`

### 6. `include/linux/filter.h` (+1)
- 新增 `bpf_prog_refresh_xdp()` 声明

### 7. `kernel/bpf/syscall.c` (+591, -1)
核心组件：
- **orig_insns 保存**：`bpf_prog_load` 中用 `kvmemdup` 保存原始指令
- **`bpf_prog_rejit_supported()`**：检查 jited/is_func/offloaded/dev_bound
- **`bpf_prog_rejit_update_poke_tab()`**：两阶段（验证+更新）tail_call poke 表迁移
- **`bpf_prog_rejit_untrack_tmp_pokes()`**：从 PROG_ARRAY 中注销 tmp 的 poke entries
- **`bpf_prog_rejit_poke_target_phase()`**：扫描所有 map_idr，为 target prog 执行 poke 删除/重建
- **`bpf_prog_rejit_swap()`**：~30 字段 swap，含 smp_wmb + WRITE_ONCE 发布
- **`bpf_prog_rejit()`**：主函数，fd_array 内核缓冲，构造 load_attr，调用 bpf_check/JIT/swap
- **`bpf_prog_get_info_by_fd` 扩展**：导出 orig_insns
- **`__sys_bpf` dispatch**：新增 `BPF_PROG_REJIT` 分支

### 8. `kernel/bpf/verifier.c` (+795)
核心组件：
- **kinsn 注册系统**：`bpf_kinsn_ops_desc` 链表 + mutex，`bpf_register_kinsn_ops()` / `bpf_unregister_kinsn_ops()`
- **`bpf_kinsn_lookup()`**：查找 + `try_module_get`
- **`bpf_free_kfunc_desc_tab()`**：释放时 `module_put` kinsn_ops
- **`add_kfunc_call()` 扩展**：为 KF_KINSN kfunc 关联 kinsn_ops 指针
- **sidecar 支持**：`bpf_verifier_find_kinsn_sidecar()`, `bpf_prog_find_kinsn_sidecar()`, `check_kinsn_sidecar_insn()`
- **kinsn call 准备**：`bpf_build_legacy_kinsn_call()`, `bpf_prepare_kinsn_call()`, `bpf_jit_get_kinsn_call()`
- **backtracking 扩展**：`bt_clear_reg_mask()`, sidecar/kinsn_call 特殊处理
- **kinsn 验证主流程 `check_kinsn_call()`**：decode -> validate -> check args/operands -> collect scalar -> model_call -> validate effect -> check mem -> apply clobber -> apply result -> apply subreg_def
- **effect 验证 `bpf_validate_kinsn_effect()`**：~95 行，检查 mask/reg/mem 合法性
- **内存访问检查 `bpf_kinsn_check_mem_accesses()`**：调用 `check_mem_access` 复用现有验证
- **结果应用**：`bpf_kinsn_apply_clobber_mask()`, `bpf_kinsn_apply_result()`, `bpf_kinsn_apply_subreg_def()`
- **`check_kfunc_call()` 扩展**：KF_KINSN 分支进入 `check_kinsn_call`
- **`do_check_insn()` 扩展**：sidecar 指令拦截
- **`is_kinsn_unsized_mem_arg()`**：允许 kinsn kfunc 接受 `void *` 参数

### 9. `kernel/bpf/core.c` (+9, -1)
- `bpf_prog_alloc_no_stats` 初始化 `rejit_mutex` 和 `trampoline_users`
- `bpf_prog_jit_attempt_done` 改用 `bpf_free_kfunc_desc_tab`
- `__bpf_ksym_del` 新增 `INIT_LIST_HEAD_RCU`（防止 rejit kallsyms 重注册时 UAF）
- `bpf_prog_pack_free` 恢复 `bpf_arch_text_invalidate` + 新增注释

### 10. `kernel/bpf/trampoline.c` (+64, -1)
- `bpf_trampoline_link_prog`：新增 `bpf_tramp_user` 分配和 rejit_mutex 下 list_add
- `bpf_trampoline_unlink_prog`：新增 rejit_mutex 下 list_del + kfree
- **`bpf_trampoline_refresh_prog()`**：遍历 trampoline_users，freplace 用 text_poke，fentry/fexit/fmod_ret 用 trampoline_update

### 11. `kernel/bpf/dispatcher.c` (+23, -3)
- `bpf_dispatcher_update` 新增 `expedited` 参数
- **`bpf_dispatcher_refresh_prog()`**：REJIT 后重建 XDP dispatcher image

### 12. `kernel/bpf/bpf_struct_ops.c` (+98)
- 新增 arch includes (`text-patching.h`, `insn.h`)
- **`find_call_site()`**：扫描 trampoline 机器码，x86 CALL 0xE8 + ARM64 BL
- **`bpf_struct_ops_refresh_prog()`**：遍历 st_map 找到 prog 的 trampoline 槽位，text_poke 替换 CALL 目标

### 13. `arch/x86/net/bpf_jit_comp.c` (+36)
- **`emit_kinsn_call()`**：查找 kinsn_ops，调用 `ops->emit_x86`，验证输出大小
- `do_jit` BPF_MOV_K case 新增 sidecar 跳过
- `do_jit` BPF_JMP CALL case 新增 kinsn 内联分支

### 14. `arch/arm64/net/bpf_jit_comp.c` (+47)
- **`emit_kinsn_call_arm64()`**：调用 `ops->emit_arm64`，验证 insn 计数和字节大小
- `build_insn` 新增 sidecar 跳过
- `build_insn` CALL case 新增 kinsn 内联分支

### 15. `net/core/filter.c` (+5)
- **`bpf_prog_refresh_xdp()`**：调用 `bpf_dispatcher_refresh_prog`

### 16. `net/bpf/test_run.c` (-5)
- 移除 `bpf_prog_test_run_xdp` 中多余的 dispatcher 注册/注销（与 REJIT 冲突）

---

## 二、#428 五个问题修复状态

| # | 问题 | 严重度 | 状态 | 说明 |
|---|------|--------|------|------|
| 1 | tools/uapi header 不同步 | CRITICAL | **已修** | `tools/include/uapi/linux/bpf.h` 与 `include/uapi/linux/bpf.h` 完全同步，rejit 结构体含 flags 字段，bpf_prog_info 含 orig_prog_len/orig_prog_insns。已通过 diff 验证两文件一致。 |
| 2 | fd_array_cnt 无上限 | CRITICAL | **已修** | 新增 `#define BPF_PROG_REJIT_MAX_FD_ARRAY 64`，在 `bpf_prog_rejit()` 中 `if (attr->rejit.fd_array_cnt > BPF_PROG_REJIT_MAX_FD_ARRAY) return -E2BIG;` |
| 3 | find_call_site x86 硬编码 5 bytes | HIGH | **已修** | `find_call_site()` 现在有 `#ifdef CONFIG_X86` 用 `CALL_INSN_SIZE` + `CALL_INSN_OPCODE`，`#elif defined(CONFIG_ARM64)` 用 `aarch64_insn_is_bl()` + `aarch64_get_branch_offset()`。两个架构都支持。 |
| 4 | text_invalidate 被删 | HIGH | **已修** | `bpf_prog_pack_free()` 中 `bpf_arch_text_invalidate()` 调用已恢复，新增注释说明 "Poison freed JIT text so stale instructions do not remain executable"。 |
| 5 | 无 try_module_get for kinsn_ops | HIGH | **已修** | `bpf_kinsn_lookup()` 中 `if (desc && try_module_get(desc->ops->owner)) ops = desc->ops;`。`bpf_free_kfunc_desc_tab()` 中 `if (ops) module_put(ops->owner);`。完整的 get/put 配对。 |

**结论：#428 五个问题全部已修复。**

---

## 三、新发现的问题

### CRITICAL (0)

无新增 CRITICAL 问题。

### HIGH (2)

| # | 位置 | 描述 |
|---|------|------|
| H1 | `kernel/bpf/syscall.c:bpf_prog_rejit_swap()` | **bpf_func 发布缺乏读端屏障**。写端用 `smp_wmb()` + `WRITE_ONCE(prog->bpf_func, ...)`，但 `BPF_PROG_RUN` 系列宏直接读 `prog->bpf_func` 没有用 `READ_ONCE`。在弱序架构（ARM64）上，理论上 CPU 可能看到新 bpf_func 但旧 metadata。实际上 JIT image 是自包含的（不依赖 metadata 执行），且后续 `synchronize_rcu` 保证旧 reader 退出。**对执行正确性无影响，但 metadata 查询（bpftool dump）在短窗口内可能不一致。** |
| H2 | `kernel/bpf/syscall.c:bpf_prog_rejit()` | **trampoline/struct_ops/XDP refresh 失败被静默忽略**。三处 refresh 失败后 `err = 0` 继续，只有 `pr_warn`。REJIT 报告成功但 trampoline 可能使用旧地址（旧 image RCU 释放后变 UAF）。应至少回滚或返回错误。特别是 `bpf_trampoline_refresh_prog` 失败后，fentry/fexit 可能 jump 到已释放的旧 image。 |

### MEDIUM (5)

| # | 位置 | 描述 |
|---|------|------|
| M1 | `kernel/bpf/syscall.c:bpf_prog_rejit_poke_target_phase()` | **O(total_maps) 扫描**。遍历所有 map_idr 查找 PROG_ARRAY。系统 map 多时性能差。可接受但上游需要注释或 reverse index。 |
| M2 | `kernel/bpf/trampoline.c:bpf_trampoline_link_prog()` | **trampoline link 和 trampoline_users list add 之间有窄竞态**。在 `tr->mutex` 释放和 `rejit_mutex` 获取之间，REJIT 不会看到这个 trampoline。实际无害（旧 image 在 RCU grace period 内仍有效），但值得加注释。 |
| M3 | `kernel/bpf/syscall.c:bpf_prog_rejit_swap()` | **xlated insns 可能过时**。如果新程序 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE`，xlated view 保持旧 bytecode 但 bpf_func 指向新 image。bpftool 用户会看到不匹配的 xlated 和实际执行代码。 |
| M4 | `kernel/bpf/syscall.c:bpf_prog_rejit()` | **`synchronize_rcu_expedited()` 在大系统上触发 IPI 风暴**。对于频繁 REJIT 的 daemon 场景（watch 模式），可能影响系统性能。上游可能要求普通 `synchronize_rcu` 或 call_rcu 延迟释放。 |
| M5 | `kernel/bpf/bpf_struct_ops.c:find_call_site()` | **0xE8 扫描可能 false positive**。如果 trampoline 中某条指令的立即数恰好形成一个指向 old_target 的相对偏移，会误判。实际概率极低但非零。更健壮的方案是在 trampoline 生成时记录 call site 位置。 |

### LOW (6)

| # | 位置 | 描述 |
|---|------|------|
| L1 | `include/linux/bpf.h` | `BPF_KINSN_SIDECAR_PAYLOAD_BITS = 52` 定义但未使用。纯文档常量。 |
| L2 | `include/linux/btf.h` | `KF_INLINE_EMIT` 别名定义但未在任何内核代码中使用。仅 module 侧可能用。 |
| L3 | `include/linux/bpf.h:bpf_kinsn_call` | `reserved` 字节对内核内部结构无意义。 |
| L4 | `include/linux/bpf.h:bpf_kinsn_operand` | `imm16` (offset 4) 和 `imm32` (offset 8) 之间有 2 字节 padding hole（对齐导致）。 |
| L5 | `kernel/bpf/verifier.c:bpf_kinsn_forbidden_flags()` | 黑名单方式：新增 KF_ flag 时需手动更新。白名单更安全。 |
| L6 | `kernel/bpf/syscall.c` | `bpf_prog_rejit_supported()` 函数体只有 2 个 if 检查 + return true，但有 10+ 行注释。 |

---

## 四、Dead Code 清单

| # | 位置 | 类型 | 说明 |
|---|------|------|------|
| D1 | `include/linux/bpf.h` | 未使用常量 | `BPF_KINSN_SIDECAR_PAYLOAD_BITS = 52`，无任何代码引用 |
| D2 | `include/linux/btf.h` | 未使用别名 | `KF_INLINE_EMIT = KF_KINSN`，内核代码全部使用 `KF_KINSN` |
| D3 | `include/linux/bpf.h` | 未使用枚举值 | `BPF_KINSN_OPERAND_NONE = 0`，内核代码未引用（module 侧可能用） |
| D4 | `include/linux/bpf.h` | 未使用字段 | `bpf_kinsn_call.reserved`，无代码读写 |
| D5 | `kernel/bpf/verifier.c` | 可简化函数 | `bpf_build_legacy_kinsn_call()` 返回值永远是 0（`memset` + 赋值不会失败），调用处检查 `if (err)` 无意义 |

**说明**：D1-D4 是 API 定义，供外部 module 使用，不算严格的 dead code。D5 是真正可删除的防御性检查。

---

## 五、精确 LOC 统计

### 核心内核代码（不含 selftests、tools UAPI 镜像）

| 文件 | 新增总行 | 代码行 | 注释行 | 空行 | 删除行 |
|------|----------|--------|--------|------|--------|
| `include/linux/bpf.h` | 173 | 150 | 1 | 22 | 0 |
| `include/linux/bpf_verifier.h` | 3 | 2 | 1 | 0 | 0 |
| `include/linux/btf.h` | 2 | 2 | 0 | 0 | 0 |
| `include/linux/filter.h` | 1 | 1 | 0 | 0 | 0 |
| `include/uapi/linux/bpf.h` | 20 | 15 | 4 | 1 | 0 |
| `kernel/bpf/syscall.c` | 590 | 385 | 125 | 80 | 1 |
| `kernel/bpf/verifier.c` | 795 | 656 | 7 | 132 | 0 |
| `kernel/bpf/core.c` | 8 | 4 | 4 | 0 | 1 |
| `kernel/bpf/trampoline.c` | 63 | 47 | 4 | 12 | 1 |
| `kernel/bpf/dispatcher.c` | 20 | 17 | 1 | 2 | 3 |
| `kernel/bpf/bpf_struct_ops.c` | 98 | 74 | 7 | 17 | 0 |
| `arch/x86/net/bpf_jit_comp.c` | 36 | 30 | 1 | 5 | 0 |
| `arch/arm64/net/bpf_jit_comp.c` | 47 | 35 | 3 | 9 | 0 |
| `net/core/filter.c` | 5 | 4 | 0 | 1 | 0 |
| `net/bpf/test_run.c` | 0 | 0 | 0 | 0 | 5 |
| `tools/include/uapi/linux/bpf.h` | 20 | 15 | 4 | 1 | 0 |
| **合计** | **1881** | **1437** | **162** | **282** | **11** |

### 按组件分解（纯代码行）

| 组件 | 代码行 | 文件 |
|------|--------|------|
| **REJIT syscall** | ~385 | syscall.c |
| **kinsn 验证器建模** | ~656 | verifier.c |
| **kinsn 头文件/类型** | ~170 | bpf.h, btf.h, bpf_verifier.h, filter.h, uapi/bpf.h |
| **refresh/patching 基础设施** | ~162 | trampoline.c, dispatcher.c, bpf_struct_ops.c, filter.c |
| **JIT 后端** | ~65 | x86 bpf_jit_comp.c, arm64 bpf_jit_comp.c |
| **核心初始化** | ~4 | core.c |
| **tools UAPI 镜像** | ~15 | tools/include/uapi/linux/bpf.h |
| **合计** | **~1437** | |

### Selftests（不含在核心 LOC 中）

| 文件 | 新增行 |
|------|--------|
| `get_original_poc.c` | 103 |
| `prog_tests/inline_kfunc.c` | 97 |
| `progs/test_inline_kfunc.c` | 13 |
| `test_kmods/bpf_test_inline_kfunc.c` | 99 |
| `.gitignore` | 5 |
| `Makefile` | 2 |
| **合计** | ~319 |

---

## 六、Coding Style 审查

### 符合内核风格
- Tab 缩进全部正确
- 大括号风格一致（K&R）
- 行宽 <= 100 字符
- 注释用 `/* */` 风格
- `#include` 位置合理
- 函数命名一致：`bpf_kinsn_*`（内部）、`bpf_prog_rejit_*`（syscall）、`bpf_*_refresh_prog`（refresh）
- EXPORT_SYMBOL_GPL 用于 `bpf_register_kinsn_ops` / `bpf_unregister_kinsn_ops`

### 需注意
- `bpf_prog_rejit_swap()` 使用 `{ ... }` 块包裹局部变量 `old_bpf_func`（在 `bpf_prog_rejit()` 内部），这在内核代码中不常见但合法。可改为单独函数。
- `guard(mutex)` 用法（`bpf_struct_ops_refresh_prog`）是正确的内核 cleanup 模式。

---

## 七、修复建议

### 必须修复（上游提交前）

1. **H2: refresh 失败处理** — trampoline/struct_ops refresh 失败不应被忽略。如果 trampoline refresh 失败，旧 image 会在 RCU grace period 后被释放，导致 fentry 跳转到已释放内存。建议：
   - 方案 A：refresh 失败时回滚 swap（回到旧 image）
   - 方案 B：refresh 失败时不释放旧 image（泄漏但不崩溃）
   - 方案 C：refresh 失败时将 prog 标记为 "不可用"

2. **M3: xlated insns 溢出** — 如果新程序更大，应更新 `prog->pages` 并 realloc，或至少在 `bpf_prog_get_info_by_fd` 中检查一致性。

### 建议修复（代码质量）

3. **D1+D2: 删除未使用定义** — `BPF_KINSN_SIDECAR_PAYLOAD_BITS` 和 `KF_INLINE_EMIT`。如果外部 module 需要 `KF_INLINE_EMIT`，保留但加注释。

4. **D5: 简化 bpf_build_legacy_kinsn_call** — 返回 void 而非 int，删除调用处的错误检查。

5. **bpf_prog_rejit_swap() 维护性** — 30+ 个字段逐个 swap 极脆弱。上游增加新字段时容易遗漏。建议：
   - 方案 A：swap `prog->aux` 指针本身（需要 careful 处理 refcnt/mutex 等不能 swap 的字段）
   - 方案 B：引入 `SWAP_AUX(field)` 宏 + compile-time 覆盖率检查

6. **L5: forbidden_flags 改白名单** — 改为允许 `KF_KINSN | KF_TRUSTED_ARGS`，拒绝其他所有。

7. **M2: 加注释说明窄竞态** — `bpf_trampoline_link_prog` 中 `tr->mutex` 释放和 `rejit_mutex` 获取之间的窗口。

---

## 八、总体评价

### 亮点
1. kinsn_ops 模块接口设计干净：decode → validate → model → emit 四阶段，验证器完整建模 effect
2. try_module_get/module_put 配对完整（#428 修复后）
3. poke_tab (tail_call) 两阶段处理设计正确
4. ARM64 支持完整：find_call_site 双架构、emit_arm64 JIT 后端
5. 验证器集成彻底：backtracking、subreg_def、range narrowing 全部正确处理

### 风险
1. `bpf_prog_rejit_swap()` 是最大维护负担，上游 rebase 时容易漏字段
2. refresh 失败的静默忽略可能导致 UAF
3. `synchronize_rcu_expedited` 在大规模部署时可能引发性能问题

### 与前次 review (#428) 对比
- 5 个 CRITICAL/HIGH 问题全部修复
- 新增 kinsn_ops 验证器建模（~470 LOC）是最大新增功能
- 代码质量明显提升：module 引用管理、text_invalidate 恢复、双架构支持

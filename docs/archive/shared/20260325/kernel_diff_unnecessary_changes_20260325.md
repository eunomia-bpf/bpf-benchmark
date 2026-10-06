# vendor/linux-framework: rejit-v2 vs master 完整 diff 分析

日期: 2026-03-25

## 1. 总体统计

| 指标 | 数值 |
|------|------|
| 修改文件数 | 22 |
| 新增行数 | +2205 |
| 删除行数 | -47 |
| 净增行数 | +2158 |
| rejit-v2 独有 commit 数 | 19 |

### 按组件分布

| 组件 | 文件数 | 新增行 | 删除行 | 说明 |
|------|--------|--------|--------|------|
| UAPI 头文件 | 2 | 48 | 0 | include/uapi + tools/include/uapi |
| 内核头文件 | 4 | 142 | 0 | bpf.h, bpf_verifier.h, btf.h, filter.h |
| JIT 后端 | 2 | 92 | 3 | x86 + ARM64 JIT |
| BPF 核心 | 7 | 1778 | 38 | syscall, verifier, btf, core, trampoline, dispatcher, struct_ops |
| 辅助/杂项 | 3 | 7 | 1 | disasm.c, filter.c, Makefile.btf |
| 测试变更 | 3 | 138 | 5 | test_run.c, get_original_poc.c, jit_disasm_helpers.c, .gitignore |

---

## 2. 逐文件分析

### 2.1 `arch/arm64/net/bpf_jit_comp.c` (+38/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +1192 | `emit_kinsn_desc_call_arm64()` 函数 | **核心必要** | kinsn ARM64 原生 emit 路径 |
| @@ +1251 | `bpf_kinsn_is_sidecar_insn` 跳过 | **核心必要** | JIT 跳过 sidecar 伪指令 |
| @@ +1624 | `BPF_PSEUDO_KINSN_CALL` case | **核心必要** | kinsn CALL 指令的 ARM64 JIT 入口 |

**结论**: 全部必要，无多余代码。

---

### 2.2 `arch/x86/net/bpf_jit_comp.c` (+54/-3)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +576 | `emit_kinsn_desc_call()` 函数 | **核心必要** | kinsn x86 原生 emit 路径 |
| @@ +1002 | `emit_movabs_imm64()` helper | **核心必要** | 用于替代 `emit_mov_imm64` 的更清晰 API |
| @@ +1623 | `emit_priv_frame_ptr` 改用 `emit_movabs_imm64` | **可疑** | 这是纯重构：用新 helper 替代旧 API。功能等价但不属于 BpfReJIT 必要改动。可能是开发过程中顺手的 cleanup。 |
| @@ +1905 | `bpf_kinsn_is_sidecar_insn` 跳过 | **核心必要** | JIT 跳过 sidecar 伪指令 |
| @@ +2485 | `BPF_PSEUDO_KINSN_CALL` case | **核心必要** | kinsn CALL 指令的 x86 JIT 入口 |
| @@ +2804 | 增强 unknown opcode 错误打印 | **可疑/调试残留** | 在 `pr_err` 中增加 insn 详细字段输出。对 BpfReJIT 功能本身非必要，属于调试辅助。可以保留但不属于核心功能。 |

**结论**: 2 处可疑改动。
- `emit_movabs_imm64` + `emit_priv_frame_ptr` 重构：功能等价的 cleanup，非 BpfReJIT 必要
- `pr_err` 增强：调试辅助，非功能必需

---

### 2.3 `include/linux/bpf.h` (+110/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +965 | `struct bpf_kinsn` / `bpf_kinsn_id` / `bpf_kinsn_set` | **核心必要** | kinsn 描述符核心数据结构 |
| @@ +965 | `bpf_kinsn_is_sidecar_insn()` / `bpf_kinsn_sidecar_payload()` | **核心必要** | sidecar 指令判断和 payload 解码 |
| @@ +1396 | `struct bpf_tramp_user` | **核心必要** | REJIT trampoline 反向索引 |
| @@ +1574 | `bpf_dispatcher_refresh_prog()` 声明 | **核心必要** | REJIT 后 dispatcher 刷新 |
| @@ +1586 | `bpf_trampoline_refresh_prog()` 声明 | **核心必要** | REJIT 后 trampoline 刷新 |
| @@ +1613 | non-JIT stubs | **核心必要** | CONFIG_BPF_JIT=n 时的空实现 |
| @@ +1675 | `struct bpf_kinsn_desc_tab` forward decl | **核心必要** | |
| @@ +1729 | `rejit_mutex` / `trampoline_users` in `bpf_prog_aux` | **核心必要** | REJIT 序列化和 trampoline 追踪 |
| @@ +1766 | `kinsn_tab` in `bpf_prog_aux` | **核心必要** | |
| @@ +1781 | `orig_insns` / `orig_prog_len` in `bpf_prog_aux` | **核心必要** | GET_ORIGINAL 功能 |
| @@ +2156 | `bpf_struct_ops_refresh_prog()` 声明 | **核心必要** | |
| @@ +3092 | `bpf_free_kfunc_desc_tab` / `bpf_free_kinsn_desc_tab` / register/unregister | **核心必要** | kinsn 注册 API |
| @@ +3387 | non-BPF stubs 区域 | **核心必要** | |

**结论**: 全部必要。

---

### 2.4 `include/linux/bpf_verifier.h` (+10/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +742 | `struct bpf_kinsn_region` | **核心必要** | verifier kinsn proof region 结构 |
| @@ +857 | `kinsn_regions` / `kinsn_call_cnt` / `kinsn_region_cnt/cap` in env | **核心必要** | verifier 状态扩展 |

**结论**: 全部必要。

---

### 2.5 `include/linux/btf.h` (+11/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +115 | `struct bpf_kinsn` forward decl | **核心必要** | |
| @@ +584 | `btf_try_get_kinsn_desc()` 声明 | **核心必要** | |
| @@ +653 | non-BTF stub for `btf_try_get_kinsn_desc` | **可疑(微小)** | stub 内的 `(void)btf; (void)var_id; (void)desc;` 是不寻常的 cast-to-void 风格，大部分内核 stub 不这样写。不影响正确性但风格不一致。 |

**结论**: 功能全部必要。`(void)` casts 是轻微风格问题。

---

### 2.6 `include/linux/filter.h` (+11/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +484 | `BPF_CALL_KINSN` 宏 | **核心必要** | kinsn CALL 指令构造宏 |
| @@ +1026 | `bpf_prog_refresh_xdp()` 声明 | **核心必要** | REJIT XDP dispatcher 刷新 |

**结论**: 全部必要。

---

### 2.7 `include/uapi/linux/bpf.h` (+24/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +993 | `BPF_PROG_REJIT` cmd | **核心必要** | REJIT syscall 命令号 |
| @@ +1383 | `BPF_PSEUDO_KINSN_SIDECAR` / `BPF_PSEUDO_KINSN_CALL` | **核心必要** | kinsn 伪指令编码 |
| @@ +1932 | `union bpf_attr.rejit` struct | **核心必要** | REJIT syscall 参数 |
| @@ +6718 | `orig_prog_len` / `orig_prog_insns` in `bpf_prog_info` | **核心必要** | GET_ORIGINAL 接口 |

**结论**: 全部必要。

---

### 2.8 `tools/include/uapi/linux/bpf.h` (+24/-0)

与 `include/uapi/linux/bpf.h` 完全相同的改动（UAPI 头的 tools/ 副本同步）。

**结论**: 全部必要。UAPI 的 tools 副本必须与内核副本保持一致。

---

### 2.9 `kernel/bpf/bpf_struct_ops.c` (+108/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +13 | `#include <asm/insn.h>` / `<asm/text-patching.h>` (x86/arm64 guards) | **核心必要** | `find_call_site()` 需要这些 API |
| @@ +1465 | `find_call_site()` 函数 | **核心必要** | REJIT 后扫描 struct_ops trampoline 中的 CALL site |
| @@ +1465 | `bpf_struct_ops_refresh_prog()` 函数 | **核心必要** | REJIT 后 text_poke struct_ops trampoline |

**结论**: 全部必要。

---

### 2.10 `kernel/bpf/btf.c` (+239/-1)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +240 | `struct btf_kinsn_desc` / `struct btf_kinsn_tab` | **核心必要** | BTF 端的 kinsn 描述符表 |
| @@ +277 | `kinsn_tab` in `struct btf` | **核心必要** | |
| @@ +1815 | `btf_free_kinsn_tab()` | **核心必要** | |
| @@ +1869 | 在 `btf_free()` 中调用 `btf_free_kinsn_tab` | **核心必要** | |
| @@ +7837 | EXT prog 的 `dst_prog` NULL check 添加 | **核心必要** | 防止 EXT 程序在 `dst_prog` 被清除后崩溃（REJIT 场景中 EXT 的验证路径需要） |
| @@ +8975 | `btf_kinsn_desc_cmp` / `btf_type_is_kinsn_desc` / `btf_resolve_kinsn_desc_id` | **核心必要** | kinsn BTF 解析逻辑 |
| @@ +8975 | `register_bpf_kinsn_set()` / `unregister_bpf_kinsn_set()` | **核心必要** | kinsn 注册/注销 |
| @@ +8975 | `btf_try_get_kinsn_desc()` | **核心必要** | kinsn 描述符查找 |

**结论**: 全部必要。

---

### 2.11 `kernel/bpf/core.c` (+10/-1)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +138 | `mutex_init(&fp->aux->rejit_mutex)` / `INIT_LIST_HEAD(&fp->aux->trampoline_users)` | **核心必要** | prog 分配时初始化 REJIT 相关字段 |
| @@ +199 | `bpf_free_kfunc_desc_tab()` 替代 `kfree()` + `bpf_free_kinsn_desc_tab` | **核心必要** | kfunc_tab 动态分配后需要两步释放(内部 descs + 外部 tab) |
| @@ +656 | `INIT_LIST_HEAD_RCU(&ksym->lnode)` 在 `__bpf_ksym_del` | **可疑** | 在 latch_tree_erase + list_del_rcu 之后重新初始化 lnode。这是一个安全加固：防止 REJIT 路径中 kallsyms del+add 重入时看到悬挂指针。对正常路径不需要。 |
| @@ +1010 | `bpf_prog_pack_free` 中添加注释 | **可疑/不必要** | 纯注释添加（解释已有的 `bpf_arch_text_invalidate` 调用）。无功能变更。 |

**结论**: 大部分必要。
- `INIT_LIST_HEAD_RCU`：REJIT 相关安全加固，保留合理但可能属于防御性代码
- 新增注释：纯文档性质，不必要

---

### 2.12 `kernel/bpf/disasm.c` (+2/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +36 | `BPF_PSEUDO_KINSN_CALL` case in `__func_get_name` | **核心必要** | disasm 输出 "kinsn-descriptor" |

**结论**: 必要。

---

### 2.13 `kernel/bpf/dispatcher.c` (+20/-3)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +103 | `bpf_dispatcher_update()` 添加 `bool expedited` 参数 | **核心必要** | REJIT 路径用 `synchronize_rcu_expedited()` 减少延迟 |
| @@ +129 | `if (expedited) synchronize_rcu_expedited()` 分支 | **核心必要** | |
| @@ 新增 | `bpf_dispatcher_refresh_prog()` 函数 | **核心必要** | REJIT 后重建 dispatcher image |
| @@ +182 | `bpf_dispatcher_change_prog` 传 `false` | **核心必要** | 原有路径保持非 expedited |

**结论**: 全部必要。

---

### 2.14 `kernel/bpf/syscall.c` (+696/-1)

这是最大的改动文件，包含 REJIT syscall 的完整实现。

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +2380 | `__bpf_prog_put_noref` 中 `kvfree(orig_insns)` + kfunc/kinsn tab 释放 | **核心必要** | prog 释放时清理新增字段 |
| @@ +3022 | `bpf_prog_load` 中保存 `orig_insns` | **核心必要** | GET_ORIGINAL 功能 |
| @@ +3148 | `bpf_prog_load` error path 中 `kvfree(orig_insns)` | **核心必要** | |
| @@ +3148 | `bpf_prog_rejit_supported()` | **核心必要** | REJIT 前置条件检查 |
| @@ +3148 | `bpf_prog_rejit_update_poke_tab()` | **核心必要** | tail_call 直接跳转更新 |
| @@ +3148 | `bpf_prog_rejit_untrack_tmp_pokes()` | **核心必要** | 清理 tmp prog 的 poke 追踪 |
| @@ +3148 | `bpf_prog_rejit_poke_target_phase()` | **核心必要** | TARGET 侧 poke 两阶段更新 |
| @@ +3148 | `bpf_prog_rejit_swap()` | **核心必要** | 核心交换逻辑 |
| @@ +3148 | `bpf_prog_rejit_rollback()` | **核心必要** | 失败回滚 |
| @@ +3148 | `bpf_prog_rejit()` 主函数 | **核心必要** | REJIT syscall 入口 |
| @@ +5732 | `bpf_prog_get_info_by_fd` 中 `info.orig_prog_len = 0` (非 capable) | **核心必要** | GET_ORIGINAL 权限控制 |
| @@ +5762 | `orig_prog_insns` 复制到用户空间 | **核心必要** | GET_ORIGINAL 实现 |
| @@ +7020 | `__sys_bpf` switch 中 `BPF_PROG_REJIT` case | **核心必要** | syscall 路由 |

**建议审查的细节**:

1. `bpf_prog_rejit()` 中的多处 `pr_warn`:
   - `pr_warn("bpf_rejit: poke_tab update failed: %d\n", err)` — 保留合理（重要失败路径）
   - `pr_warn("bpf_rejit: trampoline refresh failed: %d\n", err)` — 保留合理
   - `pr_warn("bpf_rejit: struct_ops refresh failed: %d\n", err)` — 保留合理
   - `pr_warn("bpf_rejit: rollback after ... failure failed: %d\n", err)` — 保留合理（双重失败需要知道）
   - `pr_warn("bpf_rejit: retaining old JIT image after refresh failure\n")` — 保留合理

**结论**: 全部必要。syscall 实现是 BpfReJIT 的核心。

---

### 2.15 `kernel/bpf/trampoline.c` (+53/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +842 | `bpf_trampoline_link_prog` 增加 `bpf_tramp_user` 反向索引 | **核心必要** | REJIT 需要知道哪些 trampoline 用了这个 prog |
| @@ +899 | `bpf_trampoline_unlink_prog` 清理反向索引 | **核心必要** | |
| @@ 新增 | `bpf_trampoline_refresh_prog()` | **核心必要** | REJIT 后重建 trampoline |

**结论**: 全部必要。

---

### 2.16 `kernel/bpf/verifier.c` (+649/-32)

最复杂的改动文件。

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +272 | `bpf_pseudo_kinsn_call()` helper | **核心必要** | |
| @@ +3173 | 删除 `MAX_KFUNC_DESCS` / `MAX_KFUNC_BTFS` 宏 | **核心必要** | 改为动态分配后不再需要 |
| @@ +3193 | `bpf_kfunc_desc_tab` / `bpf_kfunc_btf_tab` 改为动态数组 | **核心必要** | 支持更大数量的 kfunc/kinsn 描述符 |
| @@ +3193 | `bpf_kinsn_desc` / `bpf_kinsn_desc_tab` 新结构 | **核心必要** | |
| @@ +3193 | `ensure_desc_capacity()` 通用动态数组增长函数 | **核心必要** | |
| @@ +3193 | 前向声明 `kinsn_desc_cmp_by_imm_off` / `find_kinsn_desc` / `bpf_patch_insn_data` / `verifier_remove_insns` | **核心必要** | 解决前向引用 |
| @@ +3309 | `__find_kfunc_desc_btf` 中 lazy alloc `kfunc_btf_tab` + 删除 `MAX_KFUNC_BTFS` 限制 + 动态增长 | **核心必要（但有附带影响）** | 这是把 kfunc_btf_tab 从固定大小数组改为动态分配。虽然对 kinsn 也需要相同的 BTF 查找路径，但这个改动同时影响了纯 kfunc 路径。从功能角度仍然是必要的。 |
| @@ +3380 | `bpf_free_kfunc_btf_tab` 增加 `kvfree(tab->descs)` | **核心必要** | 动态数组释放 |
| @@ 新增 | `bpf_free_kfunc_desc_tab()` / `bpf_free_kinsn_desc_tab()` | **核心必要** | |
| @@ +3569 | `add_kfunc_call` 删除 MAX check，改用 `ensure_desc_capacity` | **核心必要** | |
| @@ 新增 | `fetch_kinsn_desc_meta()` / `add_kinsn_call()` | **核心必要** | kinsn 描述符获取和注册 |
| @@ 新增 | `kinsn_desc_cmp_by_imm_off()` / `find_kinsn_desc()` | **核心必要** | |
| @@ +3762 | `bpf_prog_has_kinsn_call()` | **核心必要** | |
| @@ +3793 | `bpf_jit_find_kinsn_desc()` / 一系列 kinsn verifier 函数 | **核心必要** | |
| @@ +3793 | `validate_kinsn_proof_seq()` | **核心必要** | 验证 kinsn proof sequence 安全性 |
| @@ +3793 | `scrub_restored_kinsn_aux()` | **核心必要** | |
| @@ +3793 | `alloc_kinsn_proof_regions()` / `lower_kinsn_proof_regions()` / `restore_kinsn_proof_regions()` | **核心必要** | kinsn proof region 替换/恢复机制 |
| @@ +3793 | `bpf_kinsn_has_native_emit()` / `build_kinsn_inst_seq()` / `bpf_jit_get_kinsn_payload()` | **核心必要** | |
| @@ +4153 | `add_subprog_and_kfunc` 扩展支持 kinsn | **核心必要** | |
| @@ +4700 | `disasm_kfunc_name` → `disasm_call_name` 重命名 + 扩展支持 kinsn | **核心必要（但包含重命名）** | 重命名 `disasm_kfunc_name` 为 `disasm_call_name` 属于 cleanup 但与功能变更一起做是合理的 |
| @@ +4700 | 变量 `func` → `t` 重命名 | **可疑/不必要** | 在 `disasm_call_name` 中把 `const struct btf_type *func` 改名为 `*t`，纯风格变更 |
| @@ +4700 | 添加 NULL check `t ? btf_name_by_offset(...) : "<invalid>"` | **可疑** | 新增了一个 NULL 检查。可能是因为 kinsn 的 BTF type 可能返回 NULL？如果是的话应该是必要的安全检查，但也可能是防御性代码。 |
| @@ +4950 | `backtrack_insn` 中 sidecar 跳过 | **核心必要** | |
| @@ +21573 | `check_kinsn_sidecar_insn()` | **核心必要** | verifier 对 sidecar 指令的检查 |
| @@ +21573 | `do_check_insn` 中 sidecar 入口 | **核心必要** | |
| @@ +21665 | `do_check_insn` CALL 指令路径扩展支持 kinsn | **核心必要** | |
| @@ +23455 | `jit_subprogs` 传播 `kinsn_tab` | **核心必要** | |
| @@ +23640 | `fixup_call_args` 中 kinsn non-JIT 检查 | **核心必要** | |
| @@ +23964 | `do_misc_fixups` 中 sidecar+kinsn 展开逻辑 | **核心必要** | |
| @@ +24301 | `do_misc_fixups` CALL fixup 中跳过 kinsn | **核心必要** | |
| @@ +26596 | `bpf_check` 中提前调用 `check_btf_info_early` + `add_subprog_and_kfunc` + `lower_kinsn_proof_regions` | **核心必要** | kinsn proof lowering 必须在 verifier 主循环之前 |
| @@ +26596 | 删除原位置的 `check_btf_info_early` / `add_subprog_and_kfunc` 调用 | **核心必要** | 对应上面的提前调用 |
| @@ +26596 | `env->explored_states = NULL` | **可疑** | 在 `kvfree(env->explored_states)` 后置 NULL。可能是防御性代码，防止 `restore_kinsn_proof_regions` 路径出错时 double free。合理但属于安全加固。 |
| @@ +26596 | `restore_kinsn_proof_regions` 调用 | **核心必要** | |
| @@ +26810 | `kvfree(env->kinsn_regions)` | **核心必要** | 清理 |

**结论**: 绝大部分必要。2-3 处轻微的风格/防御性代码。

---

### 2.17 `net/bpf/test_run.c` (+0/-5)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ -1390 | 删除 `bpf_prog_change_xdp(NULL, prog)` / `bpf_prog_change_xdp(prog, NULL)` | **可疑/可能不必要** | 从 `bpf_prog_test_run_xdp` 中移除了 XDP dispatcher 注册/注销。这改变了 XDP test_run 的行为：repeat>1 时不再临时注册到 dispatcher。可能是为了避免 REJIT 与 test_run dispatcher 的冲突，但也可能引入 test_run 性能回退（不走 dispatcher 快速路径）。**需要确认是否真的必要。** |

**结论**: **可疑，需要进一步确认**。如果非 REJIT 必需，应回退此变更。

---

### 2.18 `net/core/filter.c` (+5/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +11903 | `bpf_prog_refresh_xdp()` 实现 | **核心必要** | REJIT 后的 XDP dispatcher 刷新 |

**结论**: 必要。

---

### 2.19 `scripts/Makefile.btf` (+3/-1)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +2 | `extmod-btf-global-var-y` / `extmod-btf-global-var-$(if $(KBUILD_EXTMOD),y)` | **核心必要** | 外部模块编译时需要 `global_var` BTF feature 才能让 pahole 生成 kinsn 描述符的 BTF_KIND_VAR |
| @@ +16 | `$(extmod-btf-global-var-y)` append 到 `--btf_features` | **核心必要** | |

**结论**: 必要。kinsn 通过 BTF_KIND_VAR 注册描述符，需要此 pahole flag。

---

### 2.20 `tools/testing/selftests/bpf/.gitignore` (+5/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +47 | `/rejit_poc` / `/rejit_safety_tests` / `/rejit_prog_types` / `/rejit_tail_call` / `/get_original_poc` | **核心必要** | selftest 二进制的 gitignore |

**结论**: 必要。

---

### 2.21 `tools/testing/selftests/bpf/get_original_poc.c` (+103/-0, 新文件)

| 内容 | 判定 | 说明 |
|------|------|------|
| GET_ORIGINAL POC 测试程序 | **核心必要** | 验证 `orig_prog_insns` / `orig_prog_len` 功能的 POC 测试 |

**结论**: 必要。

---

### 2.22 `tools/testing/selftests/bpf/jit_disasm_helpers.c` (+30/-0)

| Hunk | 内容 | 判定 | 说明 |
|------|------|------|------|
| @@ +10 | `#include <stdlib.h>` | **可疑** | 添加了 `<stdlib.h>` include。可能是为了 `strtoull` 函数。 |
| @@ +90 | `normalize_movabs_imm_hex()` 函数 | **可疑/可能不必要** | 这个函数规范化 movabsq 指令的负立即数格式（$-0xN → $0xFFFF...）。**与 BpfReJIT 功能本身无直接关系**，可能是 `emit_movabs_imm64` 引入后某个 selftest 的 disasm 比较出错才需要的修补。如果不引入 `emit_movabs_imm64` 的 `emit_priv_frame_ptr` 重构，这个也不需要。 |
| @@ +170 | `normalize_movabs_imm_hex(buf, sizeof(buf))` 调用 | **同上** | |

**结论**: **可能不必要**。这是因为 x86 JIT 中 `emit_priv_frame_ptr` 的重构导致 disasm 输出格式变化，需要此 normalizer 来修复 selftest。如果回退 `emit_priv_frame_ptr` 的重构，这个也可以回退。

---

## 3. 建议删除/回退的变更清单

### 3.1 明确不必要（可以安全删除）

| # | 文件 | 内容 | 理由 |
|---|------|------|------|
| 1 | `kernel/bpf/core.c` | `bpf_prog_pack_free` 中新增的注释（3行） | 纯文档性质，解释已有代码，无功能变更 |

### 3.2 可疑/建议删除（回退后不影响 BpfReJIT 功能）

| # | 文件 | 内容 | 理由 |
|---|------|------|------|
| 2 | `arch/x86/net/bpf_jit_comp.c` | `emit_movabs_imm64()` 函数及 `emit_priv_frame_ptr` 重构 | 纯代码 cleanup，与 BpfReJIT 无关。原 `emit_mov_imm64` 功能等价 |
| 3 | `arch/x86/net/bpf_jit_comp.c` | `pr_err` unknown opcode 增强打印 | 调试辅助，非功能必需 |
| 4 | `tools/testing/selftests/bpf/jit_disasm_helpers.c` | `normalize_movabs_imm_hex()` + `#include <stdlib.h>` | 因 #2 的 `emit_movabs_imm64` 引入而需要。如果回退 #2 则此处也应回退 |
| 5 | `net/bpf/test_run.c` | 删除 XDP test_run 中的 dispatcher 注册/注销 | 需要确认是否真的是 REJIT 所需。可能改变了 XDP test_run 的性能特性 |
| 6 | `kernel/bpf/verifier.c` | `disasm_kfunc_name` → `disasm_call_name` 中的变量 `func` → `t` 重命名 | 纯风格变更 |
| 7 | `include/linux/btf.h` | `btf_try_get_kinsn_desc` stub 中的 `(void)` casts | 非常规内核风格，大部分 stub 使用 `__always_unused` 或直接忽略参数 |

### 3.3 防御性代码（保留合理但非严格必要）

| # | 文件 | 内容 | 理由 |
|---|------|------|------|
| 8 | `kernel/bpf/core.c` | `INIT_LIST_HEAD_RCU(&ksym->lnode)` | REJIT 路径的安全加固，防止 kallsyms 重入 |
| 9 | `kernel/bpf/verifier.c` | `env->explored_states = NULL` after kvfree | 防止 restore 路径 double-free |
| 10 | `kernel/bpf/verifier.c` | `t ? btf_name_by_offset(...) : "<invalid>"` NULL check | 防御性 NULL 检查 |

---

## 4. 最小化 Patch Set 建议

如果要向上游提交，建议将 patch set 拆分为以下系列：

### Patch 1: GET_ORIGINAL — 暴露原始程序指令
- `include/uapi/linux/bpf.h`: `orig_prog_len` / `orig_prog_insns` in `bpf_prog_info`
- `tools/include/uapi/linux/bpf.h`: 同上
- `include/linux/bpf.h`: `orig_insns` / `orig_prog_len` in `bpf_prog_aux`
- `kernel/bpf/syscall.c`: `bpf_prog_load` 中保存 `orig_insns` + `bpf_prog_get_info_by_fd` 中返回
- `kernel/bpf/core.c`: `bpf_prog_alloc` 中不涉及（已有）
- `tools/testing/selftests/bpf/get_original_poc.c`: POC 测试

### Patch 2: kinsn 框架 — BTF 注册 + verifier 支持
- `include/uapi/linux/bpf.h`: `BPF_PSEUDO_KINSN_SIDECAR` / `BPF_PSEUDO_KINSN_CALL`
- `tools/include/uapi/linux/bpf.h`: 同上
- `include/linux/bpf.h`: `struct bpf_kinsn` / `bpf_kinsn_set` / 注册 API / kinsn_tab
- `include/linux/bpf_verifier.h`: `bpf_kinsn_region` / verifier env 扩展
- `include/linux/btf.h`: `btf_try_get_kinsn_desc`
- `include/linux/filter.h`: `BPF_CALL_KINSN`
- `kernel/bpf/btf.c`: kinsn BTF 注册/查找全部
- `kernel/bpf/verifier.c`: kinsn 相关全部（动态数组改造、proof lowering/restoring、fixup 等）
- `kernel/bpf/disasm.c`: kinsn disasm
- `kernel/bpf/core.c`: kfunc_tab/kinsn_tab 释放
- `scripts/Makefile.btf`: `global_var` for extmod

### Patch 3: kinsn JIT 后端 — x86 + ARM64
- `arch/x86/net/bpf_jit_comp.c`: `emit_kinsn_desc_call` / sidecar skip / kinsn call case
- `arch/arm64/net/bpf_jit_comp.c`: `emit_kinsn_desc_call_arm64` / sidecar skip / kinsn call case
- **不包含** `emit_movabs_imm64` 重构和 `pr_err` 增强

### Patch 4: REJIT syscall — 核心 recompile 路径
- `include/uapi/linux/bpf.h`: `BPF_PROG_REJIT` cmd + `union bpf_attr.rejit`
- `tools/include/uapi/linux/bpf.h`: 同上
- `include/linux/bpf.h`: `rejit_mutex` / `trampoline_users` / `bpf_tramp_user` / refresh 声明
- `kernel/bpf/syscall.c`: `bpf_prog_rejit()` 全部
- `kernel/bpf/core.c`: `rejit_mutex` init / `INIT_LIST_HEAD`

### Patch 5: REJIT trampoline + dispatcher refresh
- `include/linux/bpf.h`: `bpf_dispatcher_refresh_prog` / `bpf_trampoline_refresh_prog`
- `include/linux/filter.h`: `bpf_prog_refresh_xdp`
- `kernel/bpf/trampoline.c`: link/unlink 中的反向索引 + `bpf_trampoline_refresh_prog`
- `kernel/bpf/dispatcher.c`: `expedited` 参数 + `bpf_dispatcher_refresh_prog`
- `net/core/filter.c`: `bpf_prog_refresh_xdp`

### Patch 6: REJIT struct_ops refresh
- `kernel/bpf/bpf_struct_ops.c`: `find_call_site` + `bpf_struct_ops_refresh_prog`

### 应从 patch set 中排除的变更

| 文件 | 变更 | 排除理由 |
|------|------|----------|
| `arch/x86/net/bpf_jit_comp.c` | `emit_movabs_imm64` + `emit_priv_frame_ptr` 重构 | 无关 cleanup |
| `arch/x86/net/bpf_jit_comp.c` | `pr_err` unknown opcode 增强 | 无关调试辅助 |
| `tools/testing/selftests/bpf/jit_disasm_helpers.c` | `normalize_movabs_imm_hex` | 因排除 `emit_movabs_imm64` 后不再需要 |
| `net/bpf/test_run.c` | 删除 XDP dispatcher 注册 | 需要独立论证，不应混入 BpfReJIT patch set |
| `kernel/bpf/core.c` | `bpf_prog_pack_free` 注释 | 纯文档 |

---

## 5. 总结

**核心 BpfReJIT 必要改动**: ~2120 行（约 96% 的 diff）
**可疑/不必要改动**: ~90 行（约 4% 的 diff）

整体来看，rejit-v2 分支相当干净，绝大多数改动都直接服务于三个核心功能：
1. **GET_ORIGINAL** — 保存并暴露原始指令
2. **kinsn 机制** — 新的 kernel instruction 描述符框架（BTF 注册 + verifier proof lowering + JIT 原生 emit）
3. **REJIT syscall** — 运行时重编译（swap + trampoline/dispatcher/struct_ops/poke 刷新）

不必要的变更主要集中在：
- x86 JIT 的 `emit_movabs_imm64` 重构（无关 cleanup）
- x86 JIT 的 `pr_err` 增强（调试残留）
- selftest `jit_disasm_helpers.c` 的 `normalize_movabs_imm_hex`（因重构引入）
- `test_run.c` 的 XDP dispatcher 变更（可疑，需独立论证）
- 少量防御性代码和纯注释

如果要提交上游，建议先清理上述 4-5 处不相关变更，将 patch set 精简为纯功能性改动。

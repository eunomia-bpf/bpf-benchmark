# BpfReJIT Kernel Diff: Unnecessary Changes Audit

Date: 2026-03-24
Base: `master..HEAD` (committed) + `HEAD` (uncommitted)
Total committed: **21 files, +1900/-48 lines**
Total uncommitted: **6 files, +292/-85 lines**

---

## 1. Per-File Hunk-Level Audit

### 1.1 `include/linux/btf.h` (committed: -1 line)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -79: 删除 `KF_IMPLICIT_ARGS` 后的空行 | **A** | 纯空行删除 | **YES** | 删一个空行对功能毫无影响，属于无关 style churn |

**A 类行数**: 1 (删除)

### 1.2 `include/linux/btf.h` (uncommitted: +12)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -79: 恢复被删的空行 | **A** | 恢复上面 committed 中错删的空行 | YES (net: 不变) | 和 committed 的 -1 抵消 |
| @@ -114: forward declare `struct bpf_kinsn` | 核心 | btf.h 需要引用 bpf_kinsn 类型 | NO | `btf_try_get_kinsn_desc` 签名需要 |
| @@ -582: `btf_try_get_kinsn_desc()` 声明 | 核心 | 新 API 声明 | NO | kinsn 注册表查询入口 |
| @@ -649: CONFIG_BPF_SYSCALL=n stub | 核心 | 编译守卫 | NO | 必须 |
| @@ -653: stub 中 `(void)btf; (void)var_id; (void)desc;` | **C** | 过度防御：用 `__maybe_unused` 或 `(void)` 不符合内核 stub 惯例 | 应简化 | 内核 stub 通常直接 `return -ENOENT;`，不需要 cast-to-void |

**A 类行数**: 1 (恢复空行 — 和 committed 抵消，net 0)
**C 类行数**: 3 (void casts in stub)

### 1.3 `arch/arm64/net/bpf_jit_comp.c` (committed: +38)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -1192: `emit_kinsn_desc_call_arm64()` | 核心 | ARM64 kinsn native emit | NO | 功能核心 |
| @@ -1224: `bpf_kinsn_is_sidecar_insn` skip | 核心 | 跳过 sidecar 伪指令 | NO | JIT 必须 |
| @@ -1594: `BPF_PSEUDO_KINSN_CALL` 分支 | 核心 | kinsn call dispatch | NO | 功能核心 |

所有 hunk 均为核心功能。

### 1.4 `arch/x86/net/bpf_jit_comp.c` (committed: +57)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -576: `emit_kinsn_desc_call()` | 核心 | x86 kinsn native emit | NO | 功能核心 |
| @@ -972: `emit_movabs_imm64()` 新函数 | **B** | 提取 movabs helper，原 `emit_mov_imm64` 的轻量重构 | 应拆 | 不属于 kinsn 功能，是独立 refactor |
| @@ -1582: `emit_priv_frame_ptr` 改用 `emit_movabs_imm64` | **B** | 使用新 helper | 应拆 | 搭配上面的重构 |
| @@ -1865: sidecar `bpf_kinsn_is_sidecar_insn` skip | 核心 | 跳过 sidecar | NO | 功能核心 |
| @@ -2443: `BPF_PSEUDO_KINSN_CALL` dispatch | 核心 | kinsn call | NO | 功能核心 |
| @@ -2755: 增强 unknown opcode pr_err 消息 | **A** | 给 unknown opcode 的 pr_err 加了 dst/src/off/imm 打印 | **YES** | 纯 debug 增强，删掉不影响任何功能 |

**A 类行数**: ~3 (pr_err 增强)
**B 类行数**: ~13 (emit_movabs_imm64 + emit_priv_frame_ptr refactor)

### 1.5 `include/linux/bpf.h` (committed: +90)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -965: `struct bpf_kinsn` 定义 | 核心 | kinsn 描述符结构 | NO | |
| @@ -965: `BPF_KINSN_SIDECAR_PAYLOAD_BITS` 宏 | **D** | 定义了但从未被引用 | **YES** | grep 全树无使用者，死代码 |
| @@ -965: `bpf_kinsn_is_sidecar_insn()` | 核心 | sidecar 识别 | NO | |
| @@ -965: `bpf_kinsn_sidecar_payload()` | 核心 | payload 解码 | NO | |
| @@ -1359: `struct bpf_tramp_user` | 核心 | REJIT trampoline 反向索引 | NO | |
| @@ -1531: `bpf_dispatcher_refresh_prog` 声明 | 核心 | REJIT dispatcher 刷新 | NO | |
| @@ -1541: `bpf_trampoline_refresh_prog` 声明 | 核心 | REJIT trampoline 刷新 | NO | |
| @@ -1567: CONFIG_BPF_JIT=n stubs | 核心 | 编译守卫 | NO | |
| @@ -1622: forward `struct bpf_kinsn_desc_tab` | 核心 | 前向声明 | NO | |
| @@ -1675: `rejit_mutex` + `trampoline_users` | 核心 | REJIT 序列化 | NO | |
| @@ -1710: `kinsn_tab` in prog_aux | 核心 | 核心数据结构 | NO | |
| @@ -1724: `orig_insns` + `orig_prog_len` | 核心 | GET_ORIGINAL 功能 | NO | |
| @@ -2097: `bpf_struct_ops_refresh_prog` 声明 | 核心 | REJIT struct_ops | NO | |
| @@ -3032: `bpf_free_kfunc_desc_tab` 声明 | **B** | kfunc_desc_tab 从 `kfree` 改为专用 free 函数 | 应拆 | 动态分配重构的一部分 |
| @@ -3032: `bpf_free_kinsn_desc_tab` 声明 | 核心 | kinsn tab 释放 | NO | |
| @@ -3032: `bpf_prog_has_kinsn_call` 声明 | 核心 | | NO | |
| @@ -3032: `bpf_jit_find_kinsn_desc` 声明 | 核心 | | NO | |
| @@ -3032: `bpf_jit_get_kinsn_payload` 声明 | 核心 | | NO | |
| @@ -3315: CONFIG_BPF_SYSCALL=n stubs | 核心 + **B** | `bpf_free_kfunc_desc_tab` stub 属于 B 类 | 部分应拆 | |

**A 类行数**: 2 (`BPF_KINSN_SIDECAR_PAYLOAD_BITS` 宏)
**B 类行数**: ~6 (`bpf_free_kfunc_desc_tab` 相关声明和 stub)

### 1.6 `include/linux/bpf.h` (uncommitted: +24)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -966: 给 `owner` 字段加注释 `/* NULL for built-in/vmlinux */` | 核心 | 文档化语义 | NO | 有用的注释 |
| @@ -978: `struct bpf_kinsn_id` + `struct bpf_kinsn_set` | 核心 | kinsn 注册 API | NO | |
| @@ -978: 删除 `BPF_KINSN_SIDECAR_PAYLOAD_BITS` | 核心 | 清理上面标记的死代码 | NO | 好的清理 |
| @@ -3085: `register_bpf_kinsn_set` / `unregister_bpf_kinsn_set` 声明 | 核心 | | NO | |
| @@ -3384: CONFIG_BPF_SYSCALL=n stubs | 核心 | | NO | |

所有 hunk 均为核心功能。

### 1.7 `include/linux/bpf_verifier.h` (committed: +9)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -742: `struct bpf_kinsn_region` | 核心 | proof region 结构 | NO | |
| @@ -851: `kinsn_regions/cnt/cap` in verifier_env | 核心 | | NO | |

### 1.8 `include/linux/bpf_verifier.h` (uncommitted: +1)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -858: `kinsn_call_cnt` field | 核心 | 优化：避免重复遍历计数 | NO | |

### 1.9 `include/linux/filter.h` (committed: +11)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -484: `BPF_CALL_KINSN` macro | **D** | 定义了但 grep 全树无使用者 | **YES** | 目前是死代码；测试/用户空间都没用它 |
| @@ -1016: `bpf_prog_refresh_xdp` 声明 | 核心 | REJIT XDP 刷新 | NO | |

**A/D 类行数**: ~10 (`BPF_CALL_KINSN` macro)

### 1.10 `include/uapi/linux/bpf.h` (committed: +24)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -993: `BPF_PROG_REJIT` enum | 核心 | syscall 入口 | NO | |
| @@ -1382: `BPF_PSEUDO_KINSN_SIDECAR`, `BPF_PSEUDO_KINSN_CALL` | 核心 | 指令编码 | NO | |
| @@ -1922: `union bpf_attr { .rejit {} }` | 核心 | REJIT syscall attr | NO | |
| @@ -6696: `orig_prog_len`, `orig_prog_insns` in `bpf_prog_info` | 核心 | GET_ORIGINAL info | NO | |

全部核心。但需审视 UAPI:

| 子项 | Cat | 详情 |
|------|-----|------|
| `rejit.flags` 字段 | **C** | 当前 `if (attr->rejit.flags) return -EINVAL;`，定义了但未使用。保留给未来扩展可以接受，但 UAPI 审阅者可能要求删除直到真正需要时 |
| `rejit.fd_array_cnt` 字段 | 核心 | 用于 kinsn fd_array |

**C 类行数**: ~1 (`flags` field — 争议小)

### 1.11 `tools/include/uapi/linux/bpf.h` (committed: +24)

与 `include/uapi/linux/bpf.h` 完全镜像，相同分析。

### 1.12 `kernel/bpf/bpf_struct_ops.c` (committed: +108)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -13: 新增 `#include <asm/insn.h>`, `<asm/text-patching.h>` (x86), `<asm/insn.h>` (arm64) | 核心 | find_call_site 需要 | NO | |
| @@ -1458: `find_call_site()` | 核心 | struct_ops REJIT | NO | |
| @@ -1458: `bpf_struct_ops_refresh_prog()` | 核心 | struct_ops REJIT | NO | |

全部核心。

### 1.13 `kernel/bpf/core.c` (committed: +11/-2)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -138: `mutex_init(&fp->aux->rejit_mutex)` + `INIT_LIST_HEAD(&fp->aux->trampoline_users)` | 核心 | REJIT 初始化 | NO | |
| @@ -197: `kfree` → `bpf_free_kfunc_desc_tab` | **B** | 动态分配重构 | 应拆 | 和 kfunc_desc_tab 重构一起 |
| @@ -197: `bpf_free_kinsn_desc_tab` + NULL | 核心 | kinsn tab 释放 | NO | |
| @@ -652: `INIT_LIST_HEAD_RCU(&ksym->lnode)` after erase | **D** | 可疑：原代码 `list_del_rcu` 后不做 reinit；这个 reinit 使 `list_empty()` guard 在 double-del 时返回 true。这看起来是修复 REJIT 重新 add ksym 时的 double-del bug | 核心 (bug fix) | 实际上是 `bpf_prog_rejit_swap` 中 `bpf_prog_kallsyms_del_all` + `bpf_prog_kallsyms_add` 的前提条件 |
| @@ -1005: `bpf_prog_pack_free` 上方注释 | **A** | 3 行纯注释，描述已有行为 | **YES** | 不改变任何行为，只是注释 |

**A 类行数**: 4 (注释)
**B 类行数**: 2 (`kfree` → `bpf_free_kfunc_desc_tab`)

### 1.14 `kernel/bpf/disasm.c` (committed: +2)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -36: `BPF_PSEUDO_KINSN_CALL` → "kinsn-descriptor" | 核心 | disasm 支持 kinsn 调用 | NO | |

### 1.15 `kernel/bpf/dispatcher.c` (committed: +23/-4)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -103: `bpf_dispatcher_update` 加 `bool expedited` 参数 | 核心 | REJIT 使用 `synchronize_rcu_expedited` | NO | |
| @@ -128: `synchronize_rcu_expedited` 分支 | 核心 | | NO | |
| @@ -128: `bpf_dispatcher_refresh_prog()` | 核心 | | NO | |
| @@ -165: 原有 `bpf_dispatcher_update(d, prev_num_progs)` → 加 `false` 参数 | 核心 | 接口适配 | NO | |

全部核心。

### 1.16 `kernel/bpf/syscall.c` (committed: +602)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -2380: `kfree` → `bpf_free_kfunc_desc_tab` | **B** | 动态分配重构 | 应拆 | |
| @@ -2380: `bpf_free_kinsn_desc_tab(prog->aux->kinsn_tab)` | 核心 | | NO | |
| @@ -2380: `kvfree(prog->aux->orig_insns)` | 核心 | GET_ORIGINAL cleanup | NO | |
| @@ -3020: `orig_insns = kvmemdup(...)` in bpf_prog_load | 核心 | GET_ORIGINAL 保存原始指令 | NO | |
| @@ -3139: `kvfree(prog->aux->orig_insns)` in error path | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit_supported()` | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit_update_poke_tab()` | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit_untrack_tmp_pokes()` | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit_poke_target_phase()` | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit_swap()` | 核心 | | NO | |
| @@ -3148: `bpf_prog_rejit()` | 核心 | | NO | |
| @@ -5054: `info.orig_prog_len = 0` in unprivileged path | 核心 | | NO | |
| @@ -5083: orig_prog_insns in `bpf_prog_get_info_by_fd` | 核心 | | NO | |
| @@ -6328: `BPF_PROG_REJIT` case in `__sys_bpf` | 核心 | | NO | |
| (rejit.flags check) | **C** | `if (attr->rejit.flags) return -EINVAL` — 目前 flags 无用 | 轻微 | UAPI 常见做法预留 flags=0 |
| `BPF_PROG_REJIT_LOAD_ATTR_SIZE` | 核心 | 定义为 `offsetofend(union bpf_attr, keyring_id)` — 这是 `BPF_PROG_LOAD` 子结构的末尾偏移。REJIT 构建一个内核空间 `load_attr` 然后传给 `bpf_check()`，该函数需要的 `uattr_size` 必须覆盖所有 `BPF_PROG_LOAD` 字段 | NO | 正确：`bpf_check()` 是为 LOAD 路径设计的，REJIT 复用它，size 需要匹配 LOAD attr |
| `pr_warn("bpf_rejit: ...")` x3 | **A** | rejit 中 3 处 pr_warn 用于非致命路径 (trampoline/struct_ops/poke_tab 失败后 err=0 继续) | 可保留 | 争议不大，但严格说这些可以在 debug 模式下才输出 |

**A 类行数**: ~0 (pr_warn 争议小，不计入)
**B 类行数**: ~2 (`kfree` → `bpf_free_kfunc_desc_tab`)
**C 类行数**: ~1 (flags field)

### 1.17 `kernel/bpf/trampoline.c` (committed: +59/-3)

全部核心（`bpf_tramp_user` 管理 + `bpf_trampoline_refresh_prog`）。

### 1.18 `kernel/bpf/verifier.c` (committed: +737)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -272: `bpf_pseudo_kinsn_call()` | 核心 | | NO | |
| @@ -3167: 删除 `#define MAX_KFUNC_DESCS 256` + `MAX_KFUNC_BTFS 256` | **B** | 改为动态分配 | 应拆 | kfunc_desc_tab 动态分配重构 |
| @@ -3190: `struct bpf_kfunc_desc_tab` 从固定数组 → `*descs + cap` | **B** | 动态分配 | 应拆 | |
| @@ -3190: `struct bpf_kfunc_btf_tab` 从固定数组 → `*descs + cap` | **B** | 动态分配 | 应拆 | |
| @@ -3190: `struct bpf_kinsn_desc` + `bpf_kinsn_desc_tab` | 核心 | | NO | |
| @@ -3190: `ensure_desc_capacity()` | **B** | 通用动态扩容helper，被kfunc和kinsn共用 | 部分应拆 | kfunc 部分是独立重构 |
| @@ -3190: forward declares (`kinsn_desc_cmp`, `find_kinsn_desc`, `bpf_patch_insn_data`, `verifier_remove_insns`) | 核心 | | NO | 其中 `bpf_patch_insn_data` 和 `verifier_remove_insns` 的 forward declare 是因为函数顺序，虽丑但必要 |
| @@ -3257: `__find_kfunc_desc_btf` 中删除 `MAX_KFUNC_BTFS` 检查，加 `ensure_desc_capacity` | **B** | 动态分配 | 应拆 | |
| @@ -3257: `__find_kfunc_desc_btf` 中 `if (!tab)` 懒初始化 | **B** | 和动态分配一起 | 应拆 | |
| @@ -3319: `bpf_free_kfunc_btf_tab` 加 `kvfree(tab->descs)` | **B** | 动态分配 | 应拆 | |
| @@ -3319: `bpf_free_kfunc_desc_tab()` 新函数 | **B** | 动态分配 | 应拆 | |
| @@ -3319: `bpf_free_kinsn_desc_tab()` | 核心 | | NO | |
| @@ -3489: `add_kfunc_call` 删除 `MAX_KFUNC_DESCS` 检查，加 `ensure_desc_capacity` | **B** | 动态分配 | 应拆 | |
| @@ -3524: `btf_type_is_kinsn_desc()` | 核心 | | NO | |
| @@ -3524: `fetch_kinsn_desc_meta()` | 核心 | | NO | |
| @@ -3524: `add_kinsn_call()` | 核心 | | NO | |
| @@ -3536: `kinsn_desc_cmp_by_imm_off()` | 核心 | | NO | |
| @@ -3536: `find_kinsn_desc()` | 核心 | | NO | |
| @@ -3580: `bpf_prog_has_kinsn_call()` | 核心 | | NO | |
| @@ -3598: `bpf_jit_find_kinsn_desc()` | 核心 | | NO | |
| @@ -3598: kinsn proof region 一整套 (lower/restore/validate/scrub/alloc/adjust) | 核心 | ~200 行 | NO | |
| @@ -3598: `bpf_jit_get_kinsn_payload()` | 核心 | | NO | |
| @@ -4160: `disasm_kfunc_name` → `disasm_call_name` 重命名 + 支持 kinsn | 核心 + **B** | 重命名属于 refactor | 部分应拆 | 函数重命名可以拆出，但加 kinsn 分支是核心 |
| @@ -4160: 增加 null check `t ? ... : "<invalid>"` | **A** | 防御性检查，和 kinsn 无关 | **YES** | 如果只支持 kfunc，`btf_type_by_id` 不会返回 NULL（verified by add_kfunc_call） |
| @@ -4409: `backtrack_insn` 中 sidecar skip | 核心 | | NO | |
| @@ -21029: `check_kinsn_sidecar_insn()` | 核心 | | NO | |
| @@ -21029: `do_check_insn` 中 sidecar dispatch | 核心 | | NO | |
| @@ -21098: BPF_CALL reserved fields 检查扩展 | 核心 | | NO | |
| @@ -21123: kinsn_call verifier error | 核心 | | NO | |
| @@ -22883: `jit_subprogs` 中 `func[i]->aux->kinsn_tab = prog->aux->kinsn_tab` | 核心 | | NO | |
| @@ -23067: `fixup_call_args` 中 `has_kinsn_call` 检查 | 核心 | | NO | |
| @@ -23386: `do_misc_fixups` 中 kinsn sidecar lowering | 核心 | | NO | |
| @@ -23695: kinsn call skip in fixup_kfunc path | 核心 | | NO | |
| @@ -25988: `bpf_check` 中重排 `check_btf_info_early` + `add_subprog_and_kfunc` + `lower_kinsn_proof_regions` 到 `explored_states` 分配之前 | 核心 | | NO | kinsn lowering 需要在验证之前完成 |
| @@ -25988: `explored_states = NULL` after kvfree | 核心 | 防止 double-free | NO | |
| @@ -25988: `restore_kinsn_proof_regions` 调用 | 核心 | | NO | |
| @@ -26194: `kvfree(env->kinsn_regions)` cleanup | 核心 | | NO | |

**A 类行数**: ~2 (null check in disasm_call_name)
**B 类行数**: ~80 (kfunc_desc_tab/kfunc_btf_tab 动态分配重构)

### 1.19 `kernel/bpf/verifier.c` (uncommitted: +102/-85)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -3395: 简化 `bpf_free_kinsn_desc_tab` (删除 module_put 循环) | 核心 | 配合 btf_try_get_kinsn_desc 不再 try_module_get | NO | |
| @@ -3613: 删除 `btf_type_is_kinsn_desc()` 从 verifier（移到 btf.c） | 核心 | 重构到 btf.c | NO | |
| @@ -3613: 重写 `fetch_kinsn_desc_meta()` 使用 `btf_try_get_kinsn_desc()` | 核心 | | NO | |
| @@ -3810: 简化 `bpf_prog_has_kinsn_call()` 为 `!!prog->aux->kinsn_tab` | 核心 | 优化 | NO | |
| @@ -3963: 删除 `count_kinsn_calls()` 用 `kinsn_call_cnt` 替代 | 核心 | | NO | |
| @@ -4213: `add_subprog_and_kfunc` 中递增 `kinsn_call_cnt` | 核心 | | NO | |

全部核心（BTF 查询重构 + 优化）。

### 1.20 `kernel/bpf/btf.c` (uncommitted: +233)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -240: `struct btf_kinsn_desc` + `struct btf_kinsn_tab` | 核心 | BTF-side kinsn 注册表 | NO | |
| @@ -267: `btf->kinsn_tab` field | 核心 | | NO | |
| @@ -1804: `btf_free_kinsn_tab()` | 核心 | | NO | |
| @@ -1852: `btf_free_kinsn_tab(btf)` in `btf_free()` | 核心 | | NO | |
| @@ -8952: `btf_kinsn_desc_cmp` | 核心 | | NO | |
| @@ -8952: `btf_type_is_kinsn_desc` (moved from verifier.c) | 核心 | | NO | |
| @@ -8952: `btf_resolve_kinsn_desc_id()` | 核心 | | NO | |
| @@ -8952: `register_bpf_kinsn_set()` | 核心 | | NO | |
| @@ -8952: `unregister_bpf_kinsn_set()` | 核心 | | NO | |
| @@ -8952: `btf_try_get_kinsn_desc()` | 核心 | | NO | |

全部核心。

### 1.21 `net/bpf/test_run.c` (committed: -5)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -1390: 删除 `bpf_prog_change_xdp(NULL, prog)` | **A** | 删除 XDP 测试中的 dispatcher 注册/反注册 | **YES** | 这个修改破坏了 XDP test_run 的 dispatcher 路径。upstream 中 `repeat > 1` 时注册 dispatcher 是为了让 XDP direct-call 走 dispatcher 路径以获得更好测试覆盖。删掉它使 test_run XDP 总是走间接调用 |
| @@ -1414: 删除 `bpf_prog_change_xdp(prog, NULL)` | **A** | 同上 | **YES** | |

**A 类行数**: 5

### 1.22 `net/bpf/test_run.c` (uncommitted: +5 — 恢复被删的行)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| 恢复 `bpf_prog_change_xdp(NULL, prog)` 和 `bpf_prog_change_xdp(prog, NULL)` | 修复 A | 恢复 committed 中的误删 | 已恢复 | net: committed -5 + uncommitted +5 = 0 |

### 1.23 `net/core/filter.c` (committed: +5)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -11903: `bpf_prog_refresh_xdp()` | 核心 | REJIT XDP dispatcher 刷新 | NO | |

### 1.24 `scripts/Makefile.btf` (committed: +4/-2)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -2: `extmod-btf-global-var-y` 变量 | 核心 | 外部模块 BTF 需要 `global_var` 特性来暴露 kinsn 描述符 | NO | kinsn 模块的 BTF 需要 VAR 类型 |
| @@ -14: 追加 `$(extmod-btf-global-var-y)` 到 `--btf_features` | 核心 | | NO | |

### 1.25 `tools/testing/selftests/bpf/.gitignore` (committed: +5)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -47: 添加 rejit_poc/rejit_safety_tests/rejit_prog_types/rejit_tail_call/get_original_poc | **A** | 添加了 .gitignore 条目，但其中 rejit_poc/rejit_safety_tests/rejit_prog_types/rejit_tail_call 的源文件并不在树中（commit `21c1b1f89` "remove selftest from kernel tree" 已删除）。只有 get_original_poc.c 存在 | 部分 YES | 4/5 条目指向不存在的 binary，是残留 |

**A 类行数**: 4 (4 个孤立 .gitignore 条目)

### 1.26 `tools/testing/selftests/bpf/get_original_poc.c` (committed: +103, 新文件)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| 整个文件 | **D/A** | 这是一个 POC 测试，直接用 raw syscall 测试 GET_ORIGINAL 功能。按 CLAUDE.md 规则 "Upstream kernel selftests stay in vendor/linux-framework/tools/testing/selftests/**"，位置合法。但它是 POC 而非正式 selftest（没有 TAP/kselftest 框架集成），且测试的是 orig_prog_insns info 字段 | 可保留 | POC 测试有存在价值，但不属于 feature patch 本身 |

**D 类行数**: 103 (POC test，不是 feature 代码但也不完全无用)

### 1.27 `tools/testing/selftests/bpf/jit_disasm_helpers.c` (committed: +30)

| Hunk | Cat | 改动摘要 | 能否删？ | 理由 |
|------|-----|---------|---------|------|
| @@ -10: `#include <stdlib.h>` | **B** | 为 `strtoull` 加的 include，属于下面 normalize 函数的依赖 | 和下面一起 | |
| @@ -88: `normalize_movabs_imm_hex()` 函数 | **A** | 格式化 movabs 负立即数的显示，和 kinsn/REJIT 功能无关。这是修复 disasm 输出中 movabs 显示负数时的格式问题 | **YES** | 纯 selftest 工具修复，和 REJIT/kinsn 无关 |
| @@ -141: 在 disasm 循环中调用 `normalize_movabs_imm_hex` | **A** | 同上 | **YES** | |

**A 类行数**: 32 (整个 normalize_movabs_imm_hex + include + 调用点)

### 1.28 `tools/testing/selftests/bpf/jit_disasm_helpers.c` (uncommitted: -30, 恢复)

未检测到 uncommitted diff（上面 bash 输出为空）— 说明 committed 中的 +30 仍在。

---

## 2. 汇总

### A 类（完全不必要，应删除）

| 文件 | 行数 | 描述 |
|------|------|------|
| `include/linux/btf.h` (committed) | 1 | 空行删除 |
| `include/linux/bpf.h` | 2 | `BPF_KINSN_SIDECAR_PAYLOAD_BITS` 死宏（uncommitted 已清理） |
| `arch/x86/net/bpf_jit_comp.c` | 3 | unknown opcode pr_err 增强 |
| `include/linux/filter.h` | 10 | `BPF_CALL_KINSN` 死宏 |
| `kernel/bpf/core.c` | 4 | `bpf_prog_pack_free` 上方纯注释 |
| `net/bpf/test_run.c` (committed) | 5 | 误删 `bpf_prog_change_xdp`（uncommitted 已恢复，net=0） |
| `tools/testing/selftests/bpf/.gitignore` | 4 | 4 个指向不存在 binary 的 .gitignore 条目 |
| `tools/testing/selftests/bpf/jit_disasm_helpers.c` | 32 | `normalize_movabs_imm_hex` 函数及调用 |
| `kernel/bpf/verifier.c` | 2 | `disasm_call_name` 中多余的 null check |

**A 类总计: ~63 行** (committed 中的净值；考虑到 test_run.c 已被 uncommitted 修复，实际是 58 行)

### B 类（应拆到独立 prep patch）

| 文件 | 行数 | 描述 |
|------|------|------|
| `kernel/bpf/verifier.c` | ~80 | `kfunc_desc_tab` / `kfunc_btf_tab` 从固定数组改为动态分配（`ensure_desc_capacity`、删除 `MAX_KFUNC_DESCS`/`MAX_KFUNC_BTFS`、`bpf_free_kfunc_desc_tab`/`bpf_free_kfunc_btf_tab` 修改） |
| `kernel/bpf/syscall.c` | ~2 | `kfree` → `bpf_free_kfunc_desc_tab` |
| `kernel/bpf/core.c` | ~2 | 同上 |
| `include/linux/bpf.h` | ~6 | `bpf_free_kfunc_desc_tab` 声明 + stub |
| `arch/x86/net/bpf_jit_comp.c` | ~13 | `emit_movabs_imm64` 重构 |
| `kernel/bpf/verifier.c` | ~5 | `disasm_kfunc_name` → `disasm_call_name` 重命名 |

**B 类总计: ~108 行**

### C 类（过度设计）

| 文件 | 描述 |
|------|------|
| `include/uapi/linux/bpf.h` + `tools/` | `rejit.flags` 字段当前无用（但 UAPI 预留 flags=0 是常见做法，争议不大） |
| `include/linux/btf.h` (uncommitted) | stub 中不必要的 `(void)btf; (void)var_id; (void)desc;` |

**C 类总计: ~5 行**

### D 类（可疑 / debug 残留）

| 文件 | 描述 |
|------|------|
| `tools/testing/selftests/bpf/get_original_poc.c` | 103 行 POC 测试，非正式 selftest（不影响功能，但不属于 feature patch 本体） |

---

## 3. 删除 A 类 + 拆出 B 类后的 diff 规模

| 来源 | 原始行数 | 减去 A | 减去 B | 剩余 |
|------|---------|--------|--------|------|
| Committed | +1900/-48 = 1948 改动行 | -58 | -108 | ~1782 |
| Uncommitted | +292/-85 = 377 改动行 | 0 (已恢复 test_run) | 0 | ~377 |
| **合计** | **~2325 改动行** | **-58** | **-108** | **~2159 改动行** |

### 理想的 patch series 拆分：

1. **Prep patch 1**: kfunc_desc_tab/kfunc_btf_tab 动态分配重构 (~80 行)
2. **Prep patch 2**: emit_movabs_imm64 x86 helper 提取 (~13 行)
3. **Prep patch 3**: disasm_call_name rename (~5 行)
4. **Feature patch**: BpfReJIT + kinsn + GET_ORIGINAL (~2059 行)
5. **Test patch**: get_original_poc.c + .gitignore (~108 行)

清理后 feature patch 的 diff: **~2059 行 (+/-)** = 当前的 ~89%

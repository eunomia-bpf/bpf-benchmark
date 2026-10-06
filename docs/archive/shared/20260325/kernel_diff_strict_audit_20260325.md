# vendor/linux-framework rejit-v2 vs master 严格逐 hunk 审计报告

日期: 2026-03-25

## 审计标准

对 `git diff master..HEAD` 的每一处改动，严格判定是否直接服务于 BpfReJIT 三大功能：
1. **GET_ORIGINAL** — 暴露原始 BPF insns
2. **REJIT** — 运行时重新编译 BPF 程序
3. **kinsn** — 内核指令描述符（kinsn 实现）

判定类别：
- **必要** — 直接服务于上述功能
- **不必要** — 与功能无关的 cleanup、格式调整、调试残留
- **可疑** — 可能是开发过程中的临时改动，或功能相关但做法不当

---

## 一、不必要的变更（应还原）

### 1.1 `arch/x86/net/bpf_jit_comp.c` — `emit_movabs_imm64` 重构

**位置**: `@@ -972,6 +1002,17 @@` 和 `@@ -1582,8 +1623,7 @@`

**原始代码**:
```c
/* movabs r9, priv_frame_ptr */
emit_mov_imm64(&prog, X86_REG_R9, (__force long) priv_frame_ptr >> 32,
               (u32) (__force long) priv_frame_ptr);
```

**当前代码**:
新增 `emit_movabs_imm64()` helper 函数（+10行），并将 `emit_priv_frame_ptr()` 改为使用该 helper：
```c
emit_movabs_imm64(&prog, X86_REG_R9, (u64)(__force long)priv_frame_ptr);
```

**判定**: **不必要**

**理由**: 这是纯重构——用新 helper 替代已有的 `emit_mov_imm64`。生成的机器码完全等价。`emit_movabs_imm64` 本身确实被 kinsn 的 x86 emit 路径使用（在内核模块侧），但 `emit_priv_frame_ptr` 的改动与 BpfReJIT 无关。如果 kinsn 模块需要此 helper，可通过其他方式（内联或模块侧实现）提供，不需要改动上游 JIT 中无关函数。

**建议**: 保留 `emit_movabs_imm64` 函数定义（kinsn 需要），但还原 `emit_priv_frame_ptr` 中的调用方式为原始写法。

### 1.2 `arch/x86/net/bpf_jit_comp.c` — 增强 unknown opcode 错误打印

**位置**: `@@ -2755,7 +2804,9 @@`

**原始代码**:
```c
pr_err("bpf_jit: unknown opcode %02x\n", insn->code);
```

**当前代码**:
```c
pr_err("bpf_jit: unknown opcode %02x at insn %d (dst=%u src=%u off=%d imm=%d)\n",
       insn->code, i, insn->dst_reg, insn->src_reg,
       insn->off, insn->imm);
```

**判定**: **不必要（调试残留）**

**理由**: 这是开发过程中为调试 kinsn 指令分发问题而添加的增强日志。对 BpfReJIT 功能本身非必要，属于 debug-time convenience。虽然对上游可能有价值，但作为 BpfReJIT POC 补丁不应包含此类无关 cleanup。

**建议**: 还原为原始写法。

### 1.3 `kernel/bpf/core.c` — `bpf_prog_pack_free` 纯注释添加

**位置**: `@@ -1005,6 +1010,10 @@`

**原始代码**: `WARN_ONCE(bpf_arch_text_invalidate(...` 行前无注释

**当前代码**: 新增 4 行注释：
```c
/* Poison freed JIT text so stale instructions do not remain executable.
 * Live patching already handles I-cache coherency for rewritten text;
 * this hardens pack chunks that are about to be recycled.
 */
```

**判定**: **不必要（纯注释添加）**

**理由**: 这段注释解释的是已有代码的行为，不改变任何功能。虽然注释内容正确且有价值，但这是对上游代码的纯文档改动，不属于 BpfReJIT 功能实现。

**建议**: 删除。

### 1.4 `kernel/bpf/core.c` — `INIT_LIST_HEAD_RCU` in `__bpf_ksym_del`

**位置**: `@@ -652,6 +656,7 @@`

**原始代码**:
```c
latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
list_del_rcu(&ksym->lnode);
```

**当前代码**: 新增一行：
```c
latch_tree_erase(&ksym->tnode, &bpf_tree, &bpf_tree_ops);
list_del_rcu(&ksym->lnode);
INIT_LIST_HEAD_RCU(&ksym->lnode);
```

**判定**: **可疑（bug fix / 防御性编程）**

**理由**: `list_del_rcu` 后立即 `INIT_LIST_HEAD_RCU` 是一种防御模式，防止后续 `list_empty()` 检查返回 false（因为 `list_del_rcu` 将 prev 置为 `LIST_POISON2`）。这可能是修复 REJIT 流程中 `bpf_prog_kallsyms_del_all` + 再 `bpf_prog_kallsyms_add` 时的 double-del 保护。

**但问题是**: 如果这是 REJIT 需要的修复，应在 commit message 中明确说明。如果上游代码没有此 bug（因为不存在 del+re-add 场景），那这个改动只为 REJIT 服务，应该被标记为 REJIT 依赖。

**建议**: 保留，但需要在 commit message 或注释中明确标注这是 REJIT 依赖的改动。

### 1.5 `net/bpf/test_run.c` — 删除 XDP dispatcher 注册/注销

**位置**: `@@ -1390,9 +1390,6 @@` 和 `@@ -1414,8 +1411,6 @@`

**原始代码**:
```c
if (repeat > 1)
    bpf_prog_change_xdp(NULL, prog);
// ...
out:
if (repeat > 1)
    bpf_prog_change_xdp(prog, NULL);
```

**当前代码**: 这两处都被删除了。

**判定**: **可疑（可能是 bug）**

**理由**: `bpf_prog_test_run_xdp` 中的 `bpf_prog_change_xdp` 调用是为了在 repeat 模式下将 XDP 程序注册到 dispatcher 以获得更好的性能（direct call）。删除后，`BPF_PROG_TEST_RUN` 的 XDP 重复执行将走间接调用路径，可能影响性能测试结果。

这个删除可能是因为 REJIT 的 `bpf_dispatcher_refresh_prog` 流程与 `bpf_prog_change_xdp` 有交互问题，但如果是这样，应该修复交互而不是删除功能。

**建议**: 还原。如果确实存在交互问题，需要另外修复。

### 1.6 `include/linux/btf.h` — stub 中的 `(void)` cast

**位置**: `@@ -650,6 +653,14 @@`

**当前代码**:
```c
static inline int btf_try_get_kinsn_desc(const struct btf *btf, u32 var_id,
                                         const struct bpf_kinsn **desc)
{
    (void)btf;
    (void)var_id;
    (void)desc;
    return -ENOENT;
}
```

**判定**: **不必要（风格不一致）**

**理由**: 内核中的 static inline stub 函数一律不使用 `(void)` cast 来消除 unused parameter 警告。编译器对 static inline 函数的未使用参数不会报警。这是非内核风格的写法。

**建议**: 删除三行 `(void)` cast。

### 1.7 `tools/testing/selftests/bpf/jit_disasm_helpers.c` — `normalize_movabs_imm_hex` 和 `#include <stdlib.h>`

**位置**: `@@ -10,6 +10,8 @@` 和 `@@ -88,6 +90,33 @@` 和 `@@ -141,6 +170,7 @@`

**当前代码**: 新增 `#include <stdlib.h>`（for `strtoull`），新增 `normalize_movabs_imm_hex()` 函数，并在 `disasm_one_func` 中调用。

**判定**: **不必要**

**理由**: 这个函数将 LLVM disassembler 输出的 `movabsq $-0x...` 格式转换为 `movabsq $0x...` 格式。这与 BpfReJIT 三大功能无关，是上游 selftest 的 disassembler 输出格式修正。可能是开发过程中为了让 selftest 在新 LLVM 版本下通过而做的 workaround。

**建议**: 删除。这属于 selftest 层面的 fix，不应混入 BpfReJIT 补丁。

### 1.8 `tools/testing/selftests/bpf/.gitignore` — 多余的 selftest binary 名称

**位置**: `@@ -47,3 +47,8 @@`

**当前代码**: 新增 5 个 gitignore entry：
```
/rejit_poc
/rejit_safety_tests
/rejit_prog_types
/rejit_tail_call
/get_original_poc
```

**判定**: **可疑**

**理由**: `get_original_poc` 确实有对应的源文件 `get_original_poc.c`。但 `rejit_poc`、`rejit_safety_tests`、`rejit_prog_types`、`rejit_tail_call` 四个 entry 没有对应的源文件在此 diff 中（之前 commit "remove selftest from kernel tree" 删除了它们）。orphan gitignore entry 应该一并清理。

**建议**: 删除没有对应源文件的 4 个 gitignore entry（`rejit_poc`, `rejit_safety_tests`, `rejit_prog_types`, `rejit_tail_call`）。

---

## 二、可疑但可能必要的变更（需确认）

### 2.1 `kernel/bpf/btf.c` — `btf_prepare_func_args` 中 EXT 的 dst_prog NULL 检查

**位置**: `@@ -7819,8 +7837,13 @@`

**原始代码**:
```c
if (prog_type == BPF_PROG_TYPE_EXT)
    prog_type = prog->aux->dst_prog->type;
```

**当前代码**:
```c
if (prog_type == BPF_PROG_TYPE_EXT) {
    if (!prog->aux->dst_prog) {
        bpf_log(log, "extension program missing dst_prog\n");
        return -EINVAL;
    }
    prog_type = prog->aux->dst_prog->type;
}
```

**判定**: **可疑（防御性修复）**

**理由**: 上游代码假设 `BPF_PROG_TYPE_EXT` 总有 `dst_prog`。REJIT 流程中，attached EXT 程序的 `dst_prog` 已被清空（`bpf_tracing_link_init` 中），但 `bpf_prog_rejit_supported` 已拒绝这种情况。所以这个 NULL 检查在 REJIT 正常流程中不应被触发。

如果这是纯防御性编程，可以保留但属于"额外"改动。如果确实有 REJIT 路径能触发此 crash，则必要。

**建议**: 保留，但注释说明这是 REJIT 防御。

### 2.2 `kernel/bpf/verifier.c` — kfunc_desc_tab/kfunc_btf_tab 从固定数组改为动态数组

**位置**: 多个 hunk，包括：
- `@@ -3167,9 +3173,6 @@` 删除 `MAX_KFUNC_DESCS` / `MAX_KFUNC_BTFS`
- `@@ -3190,15 +3193,64 @@` 结构体改为动态分配
- `@@ -3257,14 +3309,16 @@` `__find_kfunc_desc_btf` 中 btf_tab 延迟初始化迁移
- `@@ -3489,11 +3569,6 @@` 删除 `MAX_KFUNC_DESCS` 上限检查
- `@@ -3514,6 +3589,11 @@` 新增 `ensure_desc_capacity` 调用
- `@@ -3319,6 +3399,25 @@` `bpf_free_kfunc_btf_tab` 改为 `kvfree(tab->descs)` + `kfree(tab)`
- 新增 `bpf_free_kfunc_desc_tab` 和 `bpf_free_kinsn_desc_tab`

**判定**: **可疑（超出必要范围的重构）**

**理由**: kinsn 功能需要新增 `bpf_kinsn_desc_tab` 结构和 `ensure_desc_capacity` 函数，这是必要的。但把已有的 `kfunc_desc_tab` 和 `kfunc_btf_tab` 也从固定数组改为动态数组，是超出 kinsn 功能所需的重构。

具体而言：
1. `bpf_kfunc_desc_tab.descs` 从 `struct bpf_kfunc_desc descs[MAX_KFUNC_DESCS]` 改为 `struct bpf_kfunc_desc *descs` + `u32 desc_cap` — **不必要的重构**，kinsn 不需要改动 kfunc 的数据结构
2. `bpf_kfunc_btf_tab.descs` 同理
3. 删除 `MAX_KFUNC_DESCS` / `MAX_KFUNC_BTFS` 常量 — 上游用了固定上限，改为动态需要额外的 `ensure_desc_capacity` 逻辑
4. `bpf_free_kfunc_desc_tab` 从 `kfree(tab)` 变为 `kvfree(tab->descs)` + `kfree(tab)` — 因为 `descs` 不再内嵌
5. `__find_kfunc_desc_btf` 中 btf_tab 的延迟初始化从 `add_kfunc_call` 挪到这里 — 这是为了让 kinsn 的 `fetch_kinsn_desc_meta` 也能通过 `find_kfunc_desc_btf` 查找模块 BTF，而不经过 `add_kfunc_call`

**建议**: 评估是否可以只添加 kinsn 的新结构，而不改动 kfunc 的既有数据结构。如果 kinsn 确实需要调用 `find_kfunc_desc_btf`（需要 btf_tab 已初始化），则 btf_tab 延迟初始化的迁移是必要的。但 kfunc_desc_tab 的动态化不是必要的——保持固定 256 上限完全可以。

### 2.3 `kernel/bpf/verifier.c` — `disasm_kfunc_name` 重命名为 `disasm_call_name`

**位置**: `@@ -4160,26 +4700,27 @@`

**原始代码**:
```c
static const char *disasm_kfunc_name(void *data, const struct bpf_insn *insn)
{
    const struct btf_type *func;
    ...
    if (insn->src_reg != BPF_PSEUDO_KFUNC_CALL)
        return NULL;
    ...
    func = btf_type_by_id(desc_btf, insn->imm);
    return btf_name_by_offset(desc_btf, func->name_off);
}
```

**当前代码**:
```c
static const char *disasm_call_name(void *data, const struct bpf_insn *insn)
{
    const struct btf_type *t;
    ...
    if (insn->src_reg != BPF_PSEUDO_KFUNC_CALL &&
        insn->src_reg != BPF_PSEUDO_KINSN_CALL)
        return NULL;
    ...
    t = btf_type_by_id(desc_btf, insn->imm);
    return t ? btf_name_by_offset(desc_btf, t->name_off) : "<invalid>";
}
```

**判定**: 功能扩展 **必要**，但包含两处额外改动：
1. 重命名 `disasm_kfunc_name` → `disasm_call_name` — **不必要的 rename**
2. 变量名 `func` → `t` — **不必要的 rename**
3. 添加 NULL 检查 `t ? ... : "<invalid>"` — **防御性编程，非必要**

**建议**: 保留 kinsn 的功能扩展（添加 `BPF_PSEUDO_KINSN_CALL` 分支），但不重命名函数和变量。NULL 检查可以保留作为防御。

### 2.4 `scripts/Makefile.btf` — 外部模块 BTF `global_var` 特性

**位置**: `@@ -2,6 +2,8 @@` 和 `@@ -14,7 +16,7 @@`

**原始代码**:
```makefile
pahole-flags-$(call test-ge, $(pahole-ver), 126)  = -j$(JOBS) --btf_features=encode_force,var,float,enum64,...
```

**当前代码**: 新增条件变量，对外部模块追加 `,global_var`：
```makefile
extmod-btf-global-var-y :=
extmod-btf-global-var-$(if $(KBUILD_EXTMOD),y) := ,global_var
...
pahole-flags-... = -j$(JOBS) --btf_features=...$(extmod-btf-global-var-y)
```

**判定**: **可能必要**

**理由**: kinsn 描述符通过 `BTF_KIND_VAR` 注册，需要外部模块的 BTF 包含 `global_var` 信息。如果没有这个改动，外部模块编译时 pahole 不会为全局变量生成 BTF entry，导致 `btf_find_by_name_kind(btf, name, BTF_KIND_VAR)` 找不到 kinsn descriptor。

**建议**: 保留，但需确认仅在 `KBUILD_EXTMOD` 时生效（不影响 vmlinux BTF）。

---

## 三、必要但有改进空间的变更

### 3.1 `kernel/bpf/core.c` — `kfree` → `bpf_free_kfunc_desc_tab`

**位置**: `@@ -197,8 +199,10 @@`

**原始代码**: `kfree(prog->aux->kfunc_tab);`
**当前代码**: `bpf_free_kfunc_desc_tab(prog->aux->kfunc_tab);`

**判定**: **必要**（因为 `kfunc_desc_tab` 被改为动态数组，`kfree` 不再能正确释放）

**注意**: 这个改动是 kfunc_desc_tab 动态化重构的连锁影响。如果 2.2 中的动态化重构被还原，此处也应还原。

### 3.2 `kernel/bpf/syscall.c` — 同理

**位置**: `@@ -2380,7 +2380,9 @@`

**原始代码**: `kfree(prog->aux->kfunc_tab);`
**当前代码**: `bpf_free_kfunc_desc_tab(prog->aux->kfunc_tab);`

与 3.1 同一问题。

---

## 四、完全必要的变更（确认无问题）

以下文件/hunk 经审查确认完全必要：

| 文件 | 改动行数 | 服务功能 |
|------|----------|----------|
| `arch/arm64/net/bpf_jit_comp.c` | +38/-0 | kinsn ARM64 emit |
| `arch/x86/net/bpf_jit_comp.c` — `emit_kinsn_desc_call` | +30 | kinsn x86 emit |
| `arch/x86/net/bpf_jit_comp.c` — sidecar skip + kinsn call case | +12 | kinsn JIT |
| `include/linux/bpf.h` | +110 | 全部 kinsn/REJIT 核心结构 |
| `include/linux/bpf_verifier.h` | +10 | kinsn region 结构 |
| `include/linux/btf.h` — forward decl + `btf_try_get_kinsn_desc` | +8 | kinsn BTF 查找 |
| `include/linux/filter.h` | +11 | kinsn 宏 + XDP refresh 声明 |
| `include/uapi/linux/bpf.h` | +24 | UAPI：REJIT 命令 + kinsn pseudo + orig_insns |
| `kernel/bpf/bpf_struct_ops.c` | +108 | REJIT struct_ops trampoline 刷新 |
| `kernel/bpf/btf.c` — kinsn 注册 | +220 | kinsn BTF 注册/查找 |
| `kernel/bpf/core.c` — mutex/list init + kinsn_tab free | +4 | REJIT 初始化 |
| `kernel/bpf/disasm.c` | +2 | kinsn disasm |
| `kernel/bpf/dispatcher.c` | +20/-3 | REJIT dispatcher 刷新 |
| `kernel/bpf/syscall.c` — REJIT 主实现 + orig_insns | +670 | REJIT 核心 |
| `kernel/bpf/trampoline.c` | +53 | REJIT trampoline 刷新 |
| `kernel/bpf/verifier.c` — kinsn 相关所有新增代码 | ~600 | kinsn 验证/lowering/restore |
| `net/core/filter.c` | +5 | REJIT XDP refresh |
| `tools/include/uapi/linux/bpf.h` | +24 | UAPI 镜像 |
| `tools/testing/selftests/bpf/get_original_poc.c` | +103 | GET_ORIGINAL 测试 |

---

## 五、总结

### 应删除/还原的改动

| # | 文件 | 位置 | 描述 | 行数影响 |
|---|------|------|------|----------|
| 1 | `arch/x86/net/bpf_jit_comp.c` | `emit_priv_frame_ptr` | 还原为使用 `emit_mov_imm64` 的原始写法 | -3 |
| 2 | `arch/x86/net/bpf_jit_comp.c` | `do_jit` default case | 还原 `pr_err` 为原始简洁写法 | -3 |
| 3 | `kernel/bpf/core.c` | `bpf_prog_pack_free` | 删除纯注释 | -4 |
| 4 | `include/linux/btf.h` | `btf_try_get_kinsn_desc` stub | 删除 3 行 `(void)` cast | -3 |
| 5 | `net/bpf/test_run.c` | `bpf_prog_test_run_xdp` | 还原删除的 `bpf_prog_change_xdp` 调用 | +5 |
| 6 | `tools/testing/selftests/bpf/jit_disasm_helpers.c` | 全部改动 | 删除 `normalize_movabs_imm_hex` 和 `#include <stdlib.h>` | -32 |
| 7 | `tools/testing/selftests/bpf/.gitignore` | orphan entries | 删除 `rejit_poc`, `rejit_safety_tests`, `rejit_prog_types`, `rejit_tail_call` | -4 |

### 应改进但可暂保留的改动

| # | 文件 | 描述 | 理由 |
|---|------|------|------|
| 1 | `kernel/bpf/core.c` | `INIT_LIST_HEAD_RCU` | REJIT 必要但需注释说明 |
| 2 | `kernel/bpf/btf.c` | `dst_prog` NULL 检查 | REJIT 防御但需注释说明 |
| 3 | `kernel/bpf/verifier.c` | kfunc_desc_tab 动态化 | 超出 kinsn 所需，但还原成本高；如果不值得还原则需在 commit message 说明 |
| 4 | `kernel/bpf/verifier.c` | `disasm_kfunc_name` rename | 不必要的 rename，但影响小 |

### 净减少行数估算

如果执行所有"应删除/还原"的改动，预计净减少约 **44 行**无关变更，使补丁更加聚焦于 BpfReJIT 核心功能。

### 补丁质量评估

- **核心功能代码**：约 2160 行，结构清晰，三大功能边界明确
- **不必要变更**：约 44 行（占比 ~2%），主要是调试残留和顺手 cleanup
- **可疑但可能必要**：约 60 行（kfunc 动态化重构），成本/收益需权衡
- **总评**：补丁整体质量较高，不必要变更占比小。主要问题是 test_run.c 的功能删除和 jit_disasm_helpers.c 的无关 fix。

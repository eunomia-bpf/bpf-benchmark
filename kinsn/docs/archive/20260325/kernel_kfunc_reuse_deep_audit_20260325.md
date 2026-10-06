# kfunc 复用深度审计：逐函数对比与不必要架构改动

**审查日期**: 2026-03-25
**审查者**: Claude (第二轮 review, 聚焦 kfunc 复用与架构冗余)
**基线**: `vendor/linux-framework` master..HEAD, +1827/-28 = 1799 net lines

---

## 1. 逐函数对比：kinsn vs kfunc 代码重复

### 1.1 `kinsn_desc_cmp_by_imm_off()` vs `kfunc_desc_cmp_by_imm_off()`

**文件**: `kernel/bpf/verifier.c`
**kfunc 原版**: master:3527-3537 (11 行)
**kinsn 复制**: HEAD 新增 (11 行)

```
// kfunc 版 (master:3527)                       // kinsn 版 (HEAD 新增)
static int kfunc_desc_cmp_by_imm_off(            static int kinsn_desc_cmp_by_imm_off(
    const void *a, const void *b)                     const void *a, const void *b)
{                                                {
    const struct bpf_kfunc_desc *d0 = a;             const struct bpf_kinsn_desc *d0 = a;
    const struct bpf_kfunc_desc *d1 = b;             const struct bpf_kinsn_desc *d1 = b;

    if (d0->imm != d1->imm)                          if (d0->imm != d1->imm)
        return d0->imm < d1->imm ? -1 : 1;              return d0->imm < d1->imm ? -1 : 1;
    if (d0->offset != d1->offset)                    if (d0->offset != d1->offset)
        return d0->offset < d1->offset ? -1 : 1;        return d0->offset < d1->offset ? -1 : 1;
    return 0;                                        return 0;
}                                                }
```

**结论**: 11/11 行结构相同，唯一差异是类型名 `bpf_kfunc_desc` → `bpf_kinsn_desc`。
- 必要差异: 0 行
- 不必要复制粘贴: 11 行
- **可通过统一 desc 结构完全消除**

---

### 1.2 `find_kinsn_desc()` vs `find_kfunc_desc()`

**文件**: `kernel/bpf/verifier.c`
**kfunc 原版**: master:3222-3234 (13 行)
**kinsn 复制**: HEAD 新增 (16 行)

```
// kfunc 版 (master:3222)                           // kinsn 版 (HEAD 新增)
static struct bpf_kfunc_desc *                      static struct bpf_kinsn_desc *
find_kfunc_desc(const struct bpf_prog *prog,        find_kinsn_desc(const struct bpf_prog *prog,
                u32 func_id, u16 offset)                            s32 imm, u16 offset)
{                                                   {
    struct bpf_kfunc_desc desc = {                      struct bpf_kinsn_desc key = {
        .func_id = func_id,                                 .imm = imm,
        .offset = offset,                                   .offset = offset,
    };                                                  };
    struct bpf_kfunc_desc_tab *tab;                     struct bpf_kinsn_desc_tab *tab;

    tab = prog->aux->kfunc_tab;                         tab = prog->aux->kinsn_tab;
    return bsearch(&desc, tab->descs, tab->nr_descs,    if (!tab)
                   sizeof(tab->descs[0]),                    return NULL;
                   kfunc_desc_cmp_by_id_off);            return bsearch(&key, tab->descs, tab->nr_descs,
}                                                                   sizeof(tab->descs[0]),
                                                                    kinsn_desc_cmp_by_imm_off);
                                                    }
```

**结论**: 13/16 行逻辑相同。
- 必要差异: 3 行 — kinsn 版增加了 `if (!tab) return NULL` 检查（kfunc 版其实也应该有），且 key 字段名不同（`func_id` vs `imm`）
- 不必要复制粘贴: 13 行
- **可通过统一 desc 结构消除，NULL 检查应提炼为通用逻辑**

---

### 1.3 `add_kinsn_call()` vs `add_kfunc_call()`

**文件**: `kernel/bpf/verifier.c`
**kfunc 原版**: master:3432-3535 (104 行)
**kinsn 复制**: HEAD 新增 (40 行)

逐段对比：

| 功能块 | kfunc 行数 | kinsn 行数 | 相同逻辑 | 差异 |
|--------|-----------|-----------|---------|------|
| tab 初始化 (alloc if NULL) | 18 | 7 | 同 | kfunc 有 BTF/JIT/GPL 前置检查(~16行), kinsn 无 |
| early return if already exists | 6 | 2 | 同 | 相同逻辑 |
| fetch meta | 3 | 3 | 同 | 调不同 fetch 函数 |
| capacity check / grow | 5 (MAX_KFUNC_DESCS) | 4 (ensure_desc_capacity) | 同 | kinsn 用动态增长 |
| 填充 desc 并 sort | 7 | 7 | 同 | 字段名不同 |
| 总计 | 104 | 40 | - | - |

**结论**: kinsn 版 40 行中约 30 行是 kfunc 对应逻辑的精简翻版。kfunc 多出的 64 行主要是前置验证（BTF/JIT/GPL 检查）和 `kfunc_btf_tab` 处理，kinsn 跳过了这些检查。
- 必要差异: ~10 行（不同的 meta fetch 和 desc 字段）
- 不必要复制粘贴: ~30 行
- **可通过在 kfunc_desc 中加 `kinsn` 指针完全消除**

---

### 1.4 `fetch_kinsn_desc_meta()` vs `fetch_kfunc_meta()`

**文件**: `kernel/bpf/verifier.c`
**kfunc 原版**: master:3369-3431 (63 行)
**kinsn 复制**: HEAD 新增 (66 行)

逐段对比：

| 功能块 | kfunc | kinsn | 相同 | 差异 |
|--------|-------|-------|------|------|
| func_id 验证 | 4行 | 4行 | 同 | 消息文本不同 |
| BTF 查找 | 5行 | 5行 | 同 | 完全相同 |
| btf_type_by_id 验证 | 5行 | 5行 | 同 | 完全相同 |
| func_name 获取 | 1行 | 5行 | 部分 | kinsn 多了 NULL 检查 |
| kfunc_flags / module 查找 | 4行 | 6行 | 不同 | kfunc 查 btf_kfunc_flags; kinsn 查 module |
| func_proto 获取 | 8行 | 0行 | 不同 | kinsn 不需要 func_proto |
| kallsyms lookup | 0行 | 16行 | 不同 | kinsn 特有的 `_desc` 后缀 kallsyms 查找 |
| 填充结果结构 | 8行 | 8行 | 不同 | kfunc 填 kfunc_meta; kinsn 填 bpf_kinsn* |
| 总计 | 63行 | 66行 | - | - |

**结论**: 约 20 行逻辑完全相同（验证 + BTF 查找 + btf_type_by_id），约 20 行是语义不同的必要差异（kfunc 获取 func_proto/kfunc_flags，kinsn 做 kallsyms 查找），约 26 行是结构性复制。
- 必要差异: ~30 行（kallsyms vs func_proto 是根本不同的路径）
- 不必要复制粘贴: ~36 行（开头验证 + BTF 查找部分）
- **如果统一到 kfunc，整个函数可删除，BTF 验证由 kfunc 路径处理**

---

### 1.5 `bpf_free_kinsn_desc_tab()` vs `bpf_free_kfunc_desc_tab()`

**文件**: `kernel/bpf/verifier.c`
**HEAD 新增两个函数**

```
// kfunc 版 (HEAD 新增)                          // kinsn 版 (HEAD 新增)
void bpf_free_kfunc_desc_tab(                    void bpf_free_kinsn_desc_tab(
    struct bpf_kfunc_desc_tab *tab)                  struct bpf_kinsn_desc_tab *tab)
{                                                {
    if (!tab)                                        if (!tab)
        return;                                          return;

    kfree(tab);                                      kvfree(tab->descs);
}                                                    kfree(tab);
                                                 }
```

**结论**: 6/8 行相同。
- 必要差异: 1 行（kinsn 多了 `kvfree(tab->descs)` 因为动态分配）
- 不必要复制粘贴: 7 行
- **统一后只需一个 free 函数**

---

### 1.6 `sort_kfunc_descs_by_imm_off()` — kinsn 无对应函数

kinsn 没有独立的 `sort_kinsn_descs_by_imm_off()`。kinsn 在 `add_kinsn_call()` 中每次添加后立即 sort（`sort(tab->descs, ...)`），而 kfunc 在 verification 结束时统一 sort。

**结论**: 无直接对应，但 kinsn 的 per-add sort 是 O(n^2 log n) 的低效实现，kfunc 的 post-verification sort 是 O(n log n)。这是架构差异而非复制。

---

### 1.7 `bpf_jit_find_kinsn_desc()` vs `bpf_get_kfunc_addr()` / `bpf_jit_find_kfunc_model()`

**文件**: `kernel/bpf/verifier.c`

```
// kfunc: bpf_get_kfunc_addr (master:3236)       // kinsn: bpf_jit_find_kinsn_desc (HEAD 新增)
int bpf_get_kfunc_addr(const struct bpf_prog     const struct bpf_kinsn *
    *prog, u32 func_id,                          bpf_jit_find_kinsn_desc(const struct bpf_prog
    u16 btf_fd_idx, u8 **func_addr)                  *prog, const struct bpf_insn *insn)
{                                                {
    const struct bpf_kfunc_desc *desc;               struct bpf_kinsn_desc *desc;
    desc = find_kfunc_desc(prog, func_id,
                           btf_fd_idx);              desc = find_kinsn_desc(prog, insn->imm,
    if (!desc)                                                            insn->off);
        return -EFAULT;                              return desc ? desc->kinsn : NULL;
    *func_addr = (u8 *)desc->addr;               }
    return 0;
}
```

**结论**: 10/7 行核心逻辑相同（lookup by key → extract result field）。
- 必要差异: 返回类型不同（addr vs kinsn pointer）
- 不必要复制粘贴: 5 行
- **统一后，在 kfunc_desc 中增加 kinsn 指针，通过同一个 lookup 路径**

---

### 1.8 btf.c: `register_bpf_kinsn_set()` vs `register_btf_kfunc_id_set()`

**实际代码中没有 `register_bpf_kinsn_set()`**。kinsn 走的是 kallsyms 动态查找路径（`fetch_kinsn_desc_meta` 中 `kallsyms_lookup_name(func_name + "_desc")`），完全绕过了 kfunc 的 `register_btf_kfunc_id_set()` 注册机制。

btf.c 的唯一改动（+7 行）是修复 EXT 程序 `dst_prog == NULL` 的 NULL deref — 这是一个独立 bug fix，与 kinsn 无关。

**结论**: kinsn 没有复用 kfunc 的注册机制，而是发明了一套完全不同的基于 kallsyms 的发现机制。这是最大的架构分歧之一。

---

### 1.9 复制粘贴汇总

| 函数对 | kinsn 行数 | 不必要重复行数 | 必要差异行数 |
|--------|-----------|--------------|------------|
| `kinsn_desc_cmp_by_imm_off` vs `kfunc_desc_cmp_by_imm_off` | 11 | 11 | 0 |
| `find_kinsn_desc` vs `find_kfunc_desc` | 16 | 13 | 3 |
| `add_kinsn_call` vs `add_kfunc_call` | 40 | 30 | 10 |
| `fetch_kinsn_desc_meta` vs `fetch_kfunc_meta` | 66 | 36 | 30 |
| `bpf_free_kinsn_desc_tab` vs `bpf_free_kfunc_desc_tab` | 8 | 7 | 1 |
| `bpf_jit_find_kinsn_desc` vs `bpf_get_kfunc_addr` | 7 | 5 | 2 |
| `bpf_kinsn_desc_tab` struct 定义 | 6 | 6 | 0 |
| `bpf_kinsn_desc` struct 定义 | 5 | 3 | 2 |
| **小计（纯 desc 基础设施）** | **159** | **111** | **48** |

此外还有大量 kinsn-only 代码（非复制粘贴但因独立基础设施而存在）：

| 函数 | 行数 | 如果统一可删除？ |
|------|------|----------------|
| `bpf_pseudo_kinsn_call()` | 5 | 是（normalize 到 kfunc_call） |
| `bpf_prog_has_kinsn_call()` | 12 | 是（合并到 has_kfunc_call） |
| `bpf_jit_get_kinsn_payload()` | 17 | 是（通过 kfunc_desc 查找） |
| `bpf_kinsn_is_subprog_start()` | 10 | 否（proof lowering 仍需） |
| `bpf_verifier_find_kinsn_sidecar()` | 7 | 否（proof lowering 仍需） |
| `bpf_prog_find_kinsn_sidecar()` | 8 | 否（JIT 仍需） |
| `check_kinsn_sidecar_insn()` | 15 | 否（verifier dispatch 仍需） |
| `build_kinsn_inst_seq()` | 20 | 否（fixup 仍需） |
| `validate_kinsn_proof_seq()` | 40 | 否（proof lowering 仍需） |
| `lower_kinsn_proof_regions()` | 55 | 否（核心功能） |
| `restore_kinsn_proof_regions()` | 20 | 否（核心功能） |
| `scrub_restored_kinsn_aux()` | 15 | 否（核心功能） |
| `alloc_kinsn_proof_regions()` | 12 | 否（核心功能） |
| `adjust_prior_kinsn_region_starts()` | 14 | 否（核心功能） |
| `bpf_kinsn_has_native_emit()` | 7 | 否（JIT dispatch 仍需） |
| `ensure_desc_capacity()` | 20 | 否（kfunc 也使用） |
| `find_kfunc_desc_module()` | 14 | 否（kinsn/kfunc 均需） |
| 其他 verifier/JIT 分支代码 | ~30 | 部分（normalize 后减少） |
| **小计（kinsn-only 可删除）** | **~34** | - |
| **小计（kinsn-only 需保留）** | **~250** | - |

---

## 2. 非 kinsn 的不必要架构改动

### 2.1 kfunc_desc_tab 从固定数组改为动态分配

**文件**: `kernel/bpf/verifier.c`
**改动**:
```c
-	struct bpf_kfunc_desc descs[MAX_KFUNC_DESCS];  // 固定 256
+	struct bpf_kfunc_desc *descs;
 	u32 nr_descs;
+	u32 desc_cap;
```
加 `ensure_desc_capacity()` 通用增长函数 (20 行)。

**分析**: REJIT 程序不太可能超过 `MAX_KFUNC_DESCS=256` 个不同 kfunc。即使 daemon 注入很多 kinsn call，每个不同的 kfunc/kinsn BTF ID + offset 组合才算一个 desc。实际场景中一个 BPF 程序很少超过 20 个不同 kfunc 调用。

**但**：固定数组改动态分配是上游本身就可以做的优化（减少每次 kzalloc 时的固定内存开销，`256 * sizeof(bpf_kfunc_desc)` 约 12KB），这是独立于 REJIT 的改进。

**判定**: 合理但不必须。可以作为独立 prep patch 提交。如果保留固定数组，REJIT 功能不受影响。
**行数**: ~25 行新增，~5 行删除 = 净 ~20 行

### 2.2 `explored_states` 分配顺序变更

**文件**: `kernel/bpf/verifier.c`, `bpf_check()` 函数

**改动**: 将 `check_btf_info_early()` 和 `add_subprog_and_kfunc()` 从 `explored_states` 分配之后移到之前，然后在两者之间插入 `lower_kinsn_proof_regions()`。

```c
// 之前:
    explored_states = kvzalloc_objs(...)
    check_btf_info_early(env, attr, uattr)
    add_subprog_and_kfunc(env)

// 之后:
    check_btf_info_early(env, attr, uattr)
    add_subprog_and_kfunc(env)
    lower_kinsn_proof_regions(env)        // 新增
    explored_states = kvzalloc_objs(...)
```

**分析**: 这是 kinsn proof lowering 强制需要的。`lower_kinsn_proof_regions()` 需要在 `explored_states` 分配之前执行（因为 lowering 改变了指令数量，影响 `state_htab_size(env)`）。前两个调用的移动也是必须的（lowering 需要 kinsn_tab 已填充）。

**判定**: 对 kinsn 是必须的。但如果 kinsn 统一到 kfunc，这个顺序变更仍然需要（proof lowering 在 explored_states 之前）。
**行数**: 净增 ~10 行（移动 + 新增 lower/restore 调用 + NULL 初始化）

### 2.3 `__find_kfunc_desc_btf` 的 `try_module_get` 变更

**文件**: `kernel/bpf/verifier.c`

**改动**: 将 `MAX_KFUNC_BTFS` 超限检查从 `bsearch` 之前移到 `module_put`/`btf_put` 之后。同时增加了 tab 的按需分配。

```c
// 之前:
    tab = env->prog->aux->kfunc_btf_tab;
    b = bsearch(...);
    if (!b) {
        if (tab->nr_descs == MAX_KFUNC_BTFS) { ... }
        ...
        btf = btf_get_by_fd(...)
        mod = btf_try_get_module(btf)
        ...

// 之后:
    tab = env->prog->aux->kfunc_btf_tab;
    if (!tab) {
        tab = kzalloc_obj(*tab, ...);
        env->prog->aux->kfunc_btf_tab = tab;
    }
    b = bsearch(...);
    if (!b) {
        ...
        btf = btf_get_by_fd(...)
        mod = btf_try_get_module(btf)
        ...
        if (tab->nr_descs == MAX_KFUNC_BTFS) {
            module_put(mod);      // 先释放
            btf_put(btf);
            return ERR_PTR(-E2BIG);
        }
```

**分析**: 这修复了一个真实的资源泄漏：原代码先检查超限，如果没超限才获取 btf/mod。但错误路径上如果 btf/mod 已获取但后续失败，需要释放。新代码把超限检查移到获取之后是正确的（先获取再检查，失败时释放）。tab 的按需分配是因为原来 `btf_tab` 在 `add_kfunc_call()` 中分配，但 `__find_kfunc_desc_btf()` 也需要它。

**判定**: `module_put` 变更是 bug fix（独立于 REJIT），tab 按需分配是 kinsn 通过 kfunc BTF 路径查找 module 所需。
**行数**: 净增 ~10 行

### 2.4 `disasm_kfunc_name` → `disasm_call_name` 重命名

**文件**: `kernel/bpf/verifier.c`

**改动**:
- 函数名 `disasm_kfunc_name` → `disasm_call_name`
- 添加 `BPF_PSEUDO_KINSN_CALL` 的处理
- 添加 `btf_type_by_id` 返回 NULL 的安全检查 (`? ... : "<invalid>"`)
- callback 名 `cb_call = disasm_kfunc_name` → `cb_call = disasm_call_name`

**分析**: 如果 kinsn 统一到 kfunc（使用 `BPF_PSEUDO_KFUNC_CALL`），则不需要在这里添加 `BPF_PSEUDO_KINSN_CALL` 分支。重命名本身是 cosmetic 的。NULL 安全检查是独立改进。

**判定**: 重命名和 kinsn 分支不必须（统一后消除）。NULL 安全检查是独立改进。
**行数**: 净增 ~5 行

### 2.5 ARM64 JIT 改动

**文件**: `arch/arm64/net/bpf_jit_comp.c` (+38 行)

**改动**:
- `emit_kinsn_desc_call_arm64()` (27 行)
- `build_insn()` 中 sidecar skip (2 行)
- `BPF_PSEUDO_KINSN_CALL` dispatch (7 行)

**分析**: 论文只在 x86 上评测。ARM64 改动证明了架构可移植性，但对论文评测结果无贡献。上游 review 时可以先提交 x86-only 版本，ARM64 作为后续 patch。

**判定**: 论文 scope 外，可推迟。但保留也无害（38 行不多）。
**行数**: 38 行

---

## 3. REJIT syscall 的不必要复杂度

### 3.1 `bpf_prog_rejit()` 构造 `load_attr` 调用 `bpf_check()` 的 hack

**文件**: `kernel/bpf/syscall.c`, `bpf_prog_rejit()` 函数

```c
union bpf_attr load_attr = {};
bpfptr_t load_uattr = KERNEL_BPFPTR(&load_attr);
...
load_attr.prog_type = prog->type;
load_attr.expected_attach_type = prog->expected_attach_type;
load_attr.insn_cnt = attr->rejit.insn_cnt;
load_attr.insns = attr->rejit.insns;
...
err = bpf_check(&tmp, &load_attr, load_uattr,
                BPF_PROG_REJIT_LOAD_ATTR_SIZE);
```

**脆弱性分析**:
1. `BPF_PROG_REJIT_LOAD_ATTR_SIZE = offsetofend(union bpf_attr, keyring_id)` — 这个常量硬编码了 `union bpf_attr` 的内存布局。如果上游在 `prog_load` 和 `keyring_id` 之间添加新字段，这个偏移量会失效。
2. `rejit` 和 `prog_load` 是 `union bpf_attr` 的不同成员。将 `rejit` 的字段手动映射到 `prog_load` 的字段，依赖两者在 union 中的布局兼容性。
3. 只复制了 2 个 flag (`BPF_F_SLEEPABLE`, `BPF_F_XDP_HAS_FRAGS`)。如果程序有其他 flag（`BPF_F_ANY_ALIGNMENT`, `BPF_F_TEST_RND_HI32`, `BPF_F_XDP_DEV_BOUND_ONLY` 等），会丢失。

**更干净的替代方案**:
- 从 `bpf_check()` 中抽取核心验证逻辑为 `bpf_verify_prog(struct bpf_prog *prog, struct bpf_verify_opts *opts)`，不依赖 `union bpf_attr`
- 或在 `bpf_check()` 中增加一个 `is_rejit` 参数，让它从 `prog` 本身获取 type/attach_type 等信息，而非从 attr

**行数影响**: 构造 load_attr 及相关逻辑约 30 行。重构后可减少到约 5 行。

### 3.2 `bpf_prog_rejit_swap()` 的 27 个 swap

逐个列出并判断必要性：

| # | swap 字段 | 必要性 | 可否通过 sub-struct 消除 |
|---|----------|--------|------------------------|
| 1 | `orig_insns` | 必须 | 可分组到 `rejit_state` sub-struct |
| 2 | `orig_prog_len` | 必须 | 同上 |
| 3 | `used_btfs` | 必须 | 可分组到 `verification_result` sub-struct |
| 4 | `used_btf_cnt` | 必须 | 同上 |
| 5 | `btf` | 必须 | 同上 |
| 6 | `func_info` | 必须 | 同上 |
| 7 | `func_info_aux` | 必须 | 同上 |
| 8 | `func_info_cnt` | 必须 | 同上 |
| 9 | `linfo` | 必须 | 同上 |
| 10 | `jited_linfo` | 必须 | 同上 |
| 11 | `nr_linfo` | 必须 | 同上 |
| 12 | `linfo_idx` | 必须 | 同上 |
| 13 | `num_exentries` | 必须 | 可分组到 `jit_result` sub-struct |
| 14 | `extable` | 必须 | 同上 |
| 15 | `priv_stack_ptr` | 必须 | 同上 |
| 16 | `jit_data` | 必须 | 同上 |
| 17 | `used_maps` | 必须 | 可分组到 `verification_result` |
| 18 | `used_map_cnt` | 必须 | 同上 |
| 19 | `kfunc_tab` | 必须 | 同上 |
| 20 | `kfunc_btf_tab` | 必须 | 同上 |
| 21 | `kinsn_tab` | 统一后不需要 | 合并到 kfunc_tab 后消除 |
| 22 | `security` | 必须 | 可分组 |
| 23 | `func` | 必须 | 可分组到 `jit_result` |
| 24 | `func_cnt` | 必须 | 同上 |
| 25 | `real_func_cnt` | 必须 | 同上 |
| 26 | `bpf_exception_cb` | 必须 | 同上 |
| 27 | `exception_boundary` | 必须 | 同上 |

另外还有 14 个直接赋值（非 swap）的 bool/int 字段：
`gpl_compatible`, `cb_access`, `dst_needed`, `blinding_requested`, `blinded`, `kprobe_override`, `enforce_expected_attach_type`, `call_get_stack`, `call_get_func_ip`, `call_session_cookie`, `tstamp_type_access`, `max_ctx_offset`, `max_pkt_offset`, `max_tp_access`, `stack_depth`, `max_rdonly_access`, `max_rdwr_access`, `verifier_zext`, `changes_pkt_data`, `kprobe_write_ctx`, `verified_insns`, `load_time`

**结论**:
- 27 个 swap 中 26 个是真正必要的，1 个（`kinsn_tab`）统一后可消除
- 14 个直接赋值都是必要的
- **根本问题不是 swap 数量，而是缺少 sub-struct 分组**

**建议**: 将 `bpf_prog_aux` 中的字段分为两组：
1. `struct bpf_prog_compile_result { func_info, linfo, kfunc_tab, extable, func, ... }` — 包含所有 verification/JIT 输出
2. 身份信息 (name, type, attach_btf...) — 不 swap

这样 27 个 swap 可以缩减为 1 个：`swap(prog->aux->compile_result, tmp->aux->compile_result)`
**净减**: ~50 行 swap → ~5 行

### 3.3 trampoline / struct_ops / XDP / dispatcher refresh

| 组件 | 文件 | 行数 | 论文 scope | 可推迟？ |
|------|------|------|-----------|---------|
| trampoline refresh | `kernel/bpf/trampoline.c` | 53 | 论文 scope 内 (freplace 是关键 use case) | 不可 |
| trampoline user tracking (link/unlink) | `kernel/bpf/trampoline.c` | ~30 | 同上 | 不可 |
| struct_ops refresh | `kernel/bpf/bpf_struct_ops.c` | 108 | 论文中有 struct_ops 评测 (sched_ext 等) | 不可 |
| XDP dispatcher refresh | `kernel/bpf/dispatcher.c` | 23 | 论文中有 XDP 评测 | 不可 |
| XDP wrapper | `net/core/filter.c` | 5 | 同上 | 不可 |
| **总计** | | **219** | | |

**判定**: 所有 refresh 逻辑在论文 scope 内都是必须的。REJIT 如果不能刷新 trampoline/struct_ops/dispatcher，则 attached 程序的 REJIT 会失败或产生 stale call target。这 219 行全部需要保留。

---

## 4. 与 #475 设计方案的关系

### 4.1 #475 统一后可直接删除的代码

根据 plan doc #475 的设计，统一后可删除的代码：

**verifier.c 可删除**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `struct bpf_kinsn_desc` | 5 | 合并到 `bpf_kfunc_desc` |
| `struct bpf_kinsn_desc_tab` | 5 | 使用 `bpf_kfunc_desc_tab` |
| `kinsn_desc_cmp_by_imm_off()` | 11 | 复用 `kfunc_desc_cmp_by_imm_off()` |
| `find_kinsn_desc()` | 16 | 复用 `find_kfunc_desc()` |
| `fetch_kinsn_desc_meta()` | 66 | 由 kfunc BTF 注册路径替代 |
| `add_kinsn_call()` | 40 | 合并到 `add_kfunc_call()` |
| `bpf_free_kinsn_desc_tab()` | 8 | 合并到 `bpf_free_kfunc_desc_tab()` |
| `bpf_jit_find_kinsn_desc()` | 8 | 由 kfunc_desc 中的 kinsn 指针替代 |
| `bpf_jit_get_kinsn_payload()` | 17 | 简化到 kfunc 查找路径 |
| `bpf_prog_has_kinsn_call()` | 12 | 合并到 `bpf_prog_has_kfunc_call()` |
| `bpf_pseudo_kinsn_call()` | 5 | normalize 后不需要独立判断 |
| `add_subprog_and_kfunc()` 中 kinsn 分支 | 5 | normalize 后走 kfunc 路径 |
| `fixup_call_args()` 中 kinsn 检查 | 4 | 不再需要独立检查 |
| `do_misc_fixups()` 中 kinsn skip | 2 | 合并到 kfunc skip |
| `do_check_insn()` 中 kinsn error | 3 | 不再触发 |
| `jit_subprogs()` 中 kinsn_tab 共享 | 1 | 通过 kfunc_tab |
| `backtrack_insn()` 中 sidecar skip | 2 | 保留（sidecar 仍存在） |
| 各种 kinsn 相关的 forward declaration | 4 | 删除 |
| **verifier.c 小计** | **~214** | |

**include/linux/bpf.h 可删除**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `struct bpf_kinsn_desc_tab` forward decl | 1 | 合并 |
| `bpf_kinsn_tab` in `bpf_prog_aux` | 1 | 合并到 kfunc_tab |
| `bpf_free_kinsn_desc_tab()` decl+stub | 8 | 合并 |
| `bpf_prog_has_kinsn_call()` decl+stub | 8 | 合并 |
| `bpf_jit_find_kinsn_desc()` decl+stub | 10 | 合并 |
| `bpf_jit_get_kinsn_payload()` decl+stub | 12 | 合并 |
| **bpf.h 小计** | **~40** | |

**include/uapi/linux/bpf.h 可删除/降级**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `BPF_PSEUDO_KINSN_SIDECAR` | 1 | 保留（sidecar 仍存在） |
| `BPF_PSEUDO_KINSN_CALL` | 1 | 降为 compat shim 或直接删除 |
| **uapi 小计** | **~1** | |

**kernel/bpf/syscall.c 可删除**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `bpf_free_kinsn_desc_tab()` 调用 | 1 | 合并到 kfunc free |
| `swap(kinsn_tab)` in rejit_swap | 1 | 合并到 kfunc_tab |
| **syscall.c 小计** | **~2** | |

**kernel/bpf/core.c 可删除**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `bpf_free_kinsn_desc_tab()` 调用 | 2 | 合并 |
| **core.c 小计** | **~2** | |

**kernel/bpf/disasm.c 可删除**:

| 代码 | 行数 | 原因 |
|------|------|------|
| `BPF_PSEUDO_KINSN_CALL` 分支 | 2 | normalize 后走 kfunc 路径 |
| **disasm.c 小计** | **~2** | |

**arch/ 可简化**:

| 代码 | 行数 | 原因 |
|------|------|------|
| x86: `BPF_PSEUDO_KINSN_CALL` dispatch 分支 | 7 | 改为在 kfunc CALL 路径中检查 KF_KINSN flag |
| arm64: `BPF_PSEUDO_KINSN_CALL` dispatch 分支 | 8 | 同上 |
| **arch/ 小计 (净减)** | **~5** | 删 15 行，新增 ~10 行在 kfunc 路径中 |

### 4.2 #475 统一后需新增的代码

| 代码 | 行数 | 说明 |
|------|------|------|
| `bpf_kfunc_desc` 增加 `kinsn` 指针字段 | 2 | `const struct bpf_kinsn *kinsn;` |
| `KF_KINSN` flag 定义 | 1 | `#define KF_KINSN (1 << ...)` |
| `add_kfunc_call()` 中 KF_KINSN 处理 | ~15 | 检测到 KF_KINSN 时获取 kinsn descriptor |
| `check_kfunc_call()` 中 KF_KINSN 旁路 | ~10 | 转 proof lowering |
| `fixup_kfunc_call()` 中 KF_KINSN 跳过 | ~3 | 跳过 imm rewrite |
| JIT kfunc 路径中 KF_KINSN 分支 (x86) | ~5 | 调用 emit callback |
| JIT kfunc 路径中 KF_KINSN 分支 (arm64) | ~5 | 同上 |
| normalize shim (PSEUDO_KINSN_CALL → KFUNC_CALL) | ~15 | 早期 pass |
| module 增加真实 kfunc stub | ~50 | 10 个 module 各 ~5 行 |
| **新增小计** | **~106** | |

### 4.3 行数汇总

| 项目 | 行数 |
|------|------|
| **当前总 diff** | **+1827 / -28 = 1799 净增** |
| **#475 统一可删除** | **~266 行** |
| **#475 统一需新增** | **~106 行** |
| **#475 统一后净减** | **~160 行** |
| **#475 统一后内核 diff** | **~1639 净增** |

---

## 5. 末尾总结

### 5.1 当前不必要的代码总行数

| 类别 | 行数 | 说明 |
|------|------|------|
| kinsn desc 基础设施（复制粘贴） | ~111 | 与 kfunc 功能重复的纯复制 |
| kinsn desc 基础设施（非复制但可消除） | ~34 | 独立查找/注册函数 |
| kinsn bpf.h 声明 + stub | ~40 | 头文件中的重复声明 |
| kinsn_tab 在各文件的引用 | ~8 | syscall/core 中的 free/swap |
| disasm/JIT 中的独立 dispatch | ~20 | 可合并到 kfunc 路径 |
| ARM64 JIT（非必须但无害） | 38 | 论文 scope 外 |
| load_attr hack 的冗余部分 | ~25 | 可重构简化 |
| **当前不必要代码总计** | **~276 行** |

### 5.2 #475 统一后可删除的总行数

**~266 行可直接删除**（见 4.1 详细分解）

### 5.3 理想状态下的最小内核 diff

| 组件 | 当前行数 | 理想行数 | 节约 |
|------|---------|---------|------|
| kinsn desc 基础设施 | ~270 | ~30 (kfunc 扩展) | 240 |
| REJIT syscall 核心 | ~500 | ~450 (sub-struct swap) | 50 |
| trampoline/struct_ops/dispatcher refresh | ~219 | ~219 | 0 |
| 头文件 (bpf.h + uapi) | ~112 | ~72 | 40 |
| arch/ JIT | ~77 | ~50 | 27 |
| btf.c bug fix | 7 | 7 | 0 |
| core.c | 7 | 5 | 2 |
| disasm.c | 2 | 0 | 2 |
| proof lowering/restore (保留) | ~250 | ~250 | 0 |
| 其他 verifier 分支 | ~50 | ~30 | 20 |
| **总计** | **~1799** | **~1418** | **~381** |

**结论**:
- 当前 1799 行 diff 中，约 276 行（15.3%）是可以消除的不必要代码
- #475 统一实施后，预计可删除 ~266 行、新增 ~106 行，净减 ~160 行
- 加上 swap sub-struct 重构（净减 ~50 行）和其他清理，理想状态下内核 diff 约 **1418 行**
- 这 1418 行中约 450 行是 REJIT syscall 核心（不可压缩），219 行是 refresh 逻辑（不可压缩），250 行是 proof lowering（不可压缩），其余是必要的头文件/JIT/verifier 扩展

**最紧迫的改进优先级**:
1. **P0**: #475 kinsn 统一到 kfunc（消除平行子系统，-160 行，解决审查阻力）
2. **P1**: `bpf_prog_rejit_swap()` sub-struct 重构（降低维护风险，-50 行）
3. **P2**: `bpf_check()` 调用接口重构（消除 load_attr hack，-25 行）
4. **P3**: ARM64 推迟提交（-38 行，但可保留不影响 review）
